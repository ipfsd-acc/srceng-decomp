// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_clustering_lrange_hash.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_collision\ivp_clustering_lrange_hash.h"

//------------------------------------------------------------------------------
// Address: 0x100A97F0
// Name: public: virtual IVP_ov_tree_hash::~IVP_ov_tree_hash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_ov_tree_hash::~IVP_ov_tree_hash(IVP_ov_tree_hash *this)
{
  this->__vftable = (IVP_ov_tree_hash_vtbl *)&IVP_ov_tree_hash::`vftable';
  IVP_VHash::~IVP_VHash(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A9800
// Name: protected: int IVP_ov_tree_hash::node_to_index(class IVP_OV_Node __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_ov_tree_hash::node_to_index(IVP_ov_tree_hash *this, IVP_OV_Node *node)
{
  unsigned int v2; // eax
  char *v3; // ecx
  int i; // edx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  v2 = -1;
  v3 = (char *)&node->data.x + 2;
  for ( i = 4; i != 0; --i )
  {
    v5 = IVP_Hash_crctab[(unsigned __int8)(v2 ^ *(v3 - 2))] ^ (v2 >> 8);
    v6 = IVP_Hash_crctab[(unsigned __int8)(v5 ^ *(v3 - 1))] ^ (v5 >> 8);
    v7 = IVP_Hash_crctab[(unsigned __int8)(v6 ^ *v3)] ^ (v6 >> 8);
    v8 = IVP_Hash_crctab[(unsigned __int8)(v7 ^ v3[1])] ^ (v7 >> 8);
    v2 = IVP_Hash_crctab[(unsigned __int8)(v8 ^ v3[2])] ^ (v8 >> 8);
    v3 += 5;
  }
  return v2 | 0x80000000;
}

//------------------------------------------------------------------------------
// Address: 0x100A9890
// Name: protected: virtual enum IVP_BOOL IVP_ov_tree_hash::compare(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_ov_tree_hash::compare(IVP_ov_tree_hash *this, _DWORD *elem0, _DWORD *elem1)
{
  return elem0[3] == elem1[3] && *elem0 == *elem1 && elem0[1] == elem1[1] && elem0[2] == elem1[2];
}
