// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_surface_manager/ivp_compact_surface.cxx
// Functions: 2
// ============================================================

#include "ivp\ivp_surface_manager\ivp_compact_surface.h"

//------------------------------------------------------------------------------
// Address: 0x1007B510
// Name: public: void IVP_Compact_Surface::byte_swap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Surface::byte_swap(IVP_Compact_Surface *this)
{
  unsigned int v2; // eax
  unsigned int bitfields; // [esp+8h] [ebp-4h] BYREF

  ivp_byte_swap4(fourbytes: (unsigned int *)this);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->mass_center.k[1]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->mass_center.k[2]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->rotation_inertia);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->rotation_inertia.k[1]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->rotation_inertia.k[2]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->upper_limit_radius);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->offset_ledgetree_root);
  ivp_byte_swap4(fourbytes: (unsigned int *)this->dummy);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->dummy[1]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->dummy[2]);
  bitfields = __ROR4__(*((_DWORD *)this + 7), 8);
  ivp_byte_swap4(fourbytes: &bitfields);
  v2 = bitfields;
  *((_BYTE *)this + 28) = bitfields;
  *((_DWORD *)this + 7) = (unsigned __int8)*((_DWORD *)this + 7) | v2 & 0xFFFFFF00;
}

//------------------------------------------------------------------------------
// Address: 0x1007B5B0
// Name: public: void IVP_Compact_Surface::byte_swap_all(enum IVP_BOOL,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Surface::byte_swap_all(IVP_Compact_Surface *this, IVP_BOOL swap_points, int point_estimate)
{
  IVP_Compact_Ledgetree_Node *v4; // esi
  IVP_U_BigVector<IVP_Compact_Poly_Point> swapped_points; // [esp+8h] [ebp-Ch] BYREF
  char vars0; // [esp+14h] [ebp+0h] BYREF

  v4 = (IVP_Compact_Ledgetree_Node *)((char *)this + this->offset_ledgetree_root);
  if ( v4 != nullptr )
  {
    if ( swap_points != IVP_FALSE )
    {
      swapped_points.memsize = point_estimate;
      swapped_points.n_elems = 0;
      if ( point_estimate != 0 )
        swapped_points.elems = (void **)p_malloc(size: 4 * point_estimate);
      else
        swapped_points.elems = nullptr;
      IVP_Compact_Ledgetree_Node::byte_swap_all(this: v4, pre_swapped_points: &swapped_points);
      if ( (char *)swapped_points.elems != &vars0 && swapped_points.elems != nullptr )
      {
        free(data: swapped_points.elems);
        IVP_Compact_Surface::byte_swap(this);
        return;
      }
    }
    else
    {
      IVP_Compact_Ledgetree_Node::byte_swap_all(this: v4, pre_swapped_points: nullptr);
    }
  }
  IVP_Compact_Surface::byte_swap(this);
}
