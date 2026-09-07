// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_compact_ledge.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_collision\ivp_compact_ledge.h"

//------------------------------------------------------------------------------
// Address: 0x1006E280
// Name: public: IVP_Compact_Triangle::IVP_Compact_Triangle(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Triangle *__thiscall IVP_Compact_Triangle::IVP_Compact_Triangle(IVP_Compact_Triangle *this)
{
  *(_WORD *)this->c_three_edges = 0;
  *(_DWORD *)this->c_three_edges &= 0x8000FFFF;
  *(_WORD *)&this->c_three_edges[1] = 0;
  *(_DWORD *)&this->c_three_edges[1] &= 0x8000FFFF;
  *(_WORD *)&this->c_three_edges[2] = 0;
  *(_DWORD *)&this->c_three_edges[2] &= 0x8000FFFF;
  *(_QWORD *)this = 0;
  *(_QWORD *)&this->c_three_edges[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006E2B0
// Name: public: void IVP_Compact_Triangle::byte_swap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Triangle::byte_swap(IVP_Compact_Triangle *this)
{
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int fourbytes; // [esp+4h] [ebp-8h] BYREF
  unsigned int bitfields; // [esp+8h] [ebp-4h] BYREF

  bitfields = (*(_DWORD *)this << 20)
            | ((*(_DWORD *)this & 0xFFF000 | (((*(_DWORD *)this >> 8) | *(_DWORD *)this & 0x7F000000u) >> 19)) >> 4);
  ivp_byte_swap4(fourbytes: &bitfields);
  *(_DWORD *)this = bitfields;
  fourbytes = (*(_DWORD *)this->c_three_edges << 16)
            | ((*(_DWORD *)this->c_three_edges & 0x7FFF0000u | HIWORD(*(_DWORD *)this->c_three_edges)) >> 15);
  ivp_byte_swap4(&fourbytes);
  v2 = fourbytes;
  v3 = (unsigned __int16)fourbytes | ((HIWORD(fourbytes) & 0x7FFF) << 16);
  *(_WORD *)this->c_three_edges = fourbytes;
  this->c_three_edges[0] = (IVP_Compact_Edge)(v2 & 0x80000000 | v3);
  fourbytes = (*(_DWORD *)&this->c_three_edges[1] << 16)
            | ((*(_DWORD *)&this->c_three_edges[1] & 0x7FFF0000u | HIWORD(*(_DWORD *)&this->c_three_edges[1])) >> 15);
  ivp_byte_swap4(&fourbytes);
  v4 = fourbytes;
  v5 = (unsigned __int16)fourbytes | ((HIWORD(fourbytes) & 0x7FFF) << 16);
  *(_WORD *)&this->c_three_edges[1] = fourbytes;
  this->c_three_edges[1] = (IVP_Compact_Edge)(v4 & 0x80000000 | v5);
  fourbytes = (*(_DWORD *)&this->c_three_edges[2] << 16)
            | ((*(_DWORD *)&this->c_three_edges[2] & 0x7FFF0000u | HIWORD(*(_DWORD *)&this->c_three_edges[2])) >> 15);
  ivp_byte_swap4(&fourbytes);
  v6 = fourbytes;
  v7 = HIWORD(fourbytes) & 0x7FFF;
  v8 = (unsigned __int16)fourbytes;
  *(_WORD *)&this->c_three_edges[2] = fourbytes;
  this->c_three_edges[2] = (IVP_Compact_Edge)(v6 & 0x80000000 | v8 | (v7 << 16));
}

//------------------------------------------------------------------------------
// Address: 0x1006E3E0
// Name: public: void IVP_Compact_Ledge::c_ledge_init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge::c_ledge_init(IVP_Compact_Ledge *this)
{
  *(_QWORD *)&this->c_point_offset = 0;
  *((_QWORD *)this + 1) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1006E3F0
// Name: public: void IVP_Compact_Ledge::byte_swap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge::byte_swap(IVP_Compact_Ledge *this)
{
  unsigned int bitfields; // [esp+8h] [ebp-4h] BYREF

  ivp_byte_swap4(fourbytes: (unsigned int *)this);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->___u1);
  bitfields = (((*((_DWORD *)this + 2) >> 4) | (*((_DWORD *)this + 2) << 24) & 0xF000000F) >> 4)
            | (4 * ((*((_DWORD *)this + 2) << 24) & 0xC000000 | (*((_DWORD *)this + 2) << 28)));
  ivp_byte_swap4(fourbytes: &bitfields);
  *((_DWORD *)this + 2) = bitfields & 0xFFFFFF00 | bitfields & 0xF3 | (4 * ((bitfields >> 2) & 3));
  ivp_byte_swap2(twobytes: (unsigned __int16 *)&this->n_triangles);
  ivp_byte_swap2(twobytes: (unsigned __int16 *)&this->for_future_use);
}

//------------------------------------------------------------------------------
// Address: 0x1006E490
// Name: ProcessPoint
// Source: json
//------------------------------------------------------------------------------
void __usercall ProcessPoint(
        IVP_Compact_Poly_Point *point@<ecx>,
        IVP_U_BigVector<IVP_Compact_Poly_Point> *pre_swapped_points@<eax>)
{
  int n_elems; // edx
  int v5; // eax
  void **elems; // ecx
  float *p_hesse_val; // esi

  if ( pre_swapped_points == nullptr )
  {
    p_hesse_val = &point->hesse_val;
    ivp_byte_swap4(fourbytes: (unsigned int *)&point->hesse_val);
    ivp_byte_swap4(fourbytes: (unsigned int *)point);
    ivp_byte_swap4(fourbytes: (unsigned int *)&point->k[1]);
LABEL_11:
    ivp_byte_swap4(fourbytes: (unsigned int *)&point->k[2]);
    ivp_byte_swap4(fourbytes: (unsigned int *)p_hesse_val);
    return;
  }
  n_elems = pre_swapped_points->n_elems;
  v5 = 0;
  if ( n_elems > 0 )
  {
    elems = pre_swapped_points->elems;
    do
    {
      if ( *elems == (void *)point )
        break;
      ++v5;
      ++elems;
    }
    while ( v5 < n_elems );
  }
  if ( v5 == n_elems )
  {
    if ( n_elems >= pre_swapped_points->memsize )
      IVP_U_BigVector_Base::increment_mem(this: pre_swapped_points);
    pre_swapped_points->elems[pre_swapped_points->n_elems++] = (void *)point;
    p_hesse_val = &point->hesse_val;
    ivp_byte_swap4(fourbytes: (unsigned int *)&point->hesse_val);
    ivp_byte_swap4(fourbytes: (unsigned int *)point);
    ivp_byte_swap4(fourbytes: (unsigned int *)&point->k[1]);
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E510
// Name: public: void IVP_Compact_Ledge::byte_swap_all(class IVP_U_BigVector<class IVP_Compact_Poly_Point> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge::byte_swap_all(
        IVP_Compact_Ledge *this,
        IVP_U_BigVector<IVP_Compact_Poly_Point> *pre_swapped_points)
{
  IVP_Compact_Poly_Point *v2; // eax
  _DWORD *v3; // esi
  int v4; // edi
  int v5; // ebx
  IVP_Compact_Ledge *v6; // [esp+0h] [ebp-Ch]
  int j; // [esp+4h] [ebp-8h]
  IVP_Compact_Poly_Point *points; // [esp+8h] [ebp-4h]

  v2 = (IVP_Compact_Poly_Point *)((char *)this + this->c_point_offset);
  v6 = this;
  points = v2;
  j = 0;
  if ( this->n_triangles > 0 )
  {
    v3 = (_DWORD *)this + 7;
    while ( 1 )
    {
      v4 = (unsigned __int16)*(v3 - 1);
      v5 = (unsigned __int16)*v3;
      ProcessPoint(point: &v2[(unsigned __int16)*(v3 - 2)], pre_swapped_points);
      ProcessPoint(point: &points[v4], pre_swapped_points);
      ProcessPoint(point: &points[v5], pre_swapped_points);
      IVP_Compact_Triangle::byte_swap(this: (IVP_Compact_Triangle *)(v3 - 3));
      this = v6;
      v3 += 4;
      if ( ++j >= v6->n_triangles )
        break;
      v2 = points;
    }
  }
  IVP_Compact_Ledge::byte_swap(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006E5B0
// Name: public: void IVP_Compact_Ledgetree_Node::byte_swap_all(class IVP_U_BigVector<class IVP_Compact_Poly_Point> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledgetree_Node::byte_swap_all(
        IVP_Compact_Ledgetree_Node *this,
        IVP_U_BigVector<IVP_Compact_Poly_Point> *pre_swapped_points)
{
  int offset_compact_ledge; // eax

  if ( this->offset_right_node != 0 )
  {
    IVP_Compact_Ledgetree_Node::byte_swap_all(this: this + 1, pre_swapped_points);
    IVP_Compact_Ledgetree_Node::byte_swap_all(
      this: (IVP_Compact_Ledgetree_Node *)((char *)this + this->offset_right_node),
      pre_swapped_points);
  }
  offset_compact_ledge = this->offset_compact_ledge;
  if ( offset_compact_ledge != 0 && (IVP_Compact_Ledgetree_Node *)((char *)this + offset_compact_ledge) != nullptr )
    IVP_Compact_Ledge::byte_swap_all(
      this: (IVP_Compact_Ledge *)((char *)this + offset_compact_ledge),
      pre_swapped_points);
  ivp_byte_swap4(fourbytes: (unsigned int *)this);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->offset_compact_ledge);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->center);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->center.k[1]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->center.k[2]);
  ivp_byte_swap4(fourbytes: (unsigned int *)&this->radius);
}
