// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_compact_recursive.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_compact_builder\ivp_compact_recursive.h"

//------------------------------------------------------------------------------
// Address: 0x10056AF0
// Name: _IVP_Compact_Recursive::set_rekursive_convex_hull_::_2_::Triangle_Key::set_tri
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Compact_Recursive::set_rekursive_convex_hull_::_2_::Triangle_Key::set_tri(
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *this@<ecx>,
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key **a2@<eax>,
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *a,
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *b,
        int c)
{
  *a2 = this;
  a2[1] = a;
  a2[2] = b;
}

//------------------------------------------------------------------------------
// Address: 0x10056B10
// Name: _IVP_Compact_Recursive::set_rekursive_convex_hull_::_3_::Edge_Key::set_edge
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Compact_Recursive::set_rekursive_convex_hull_::_3_::Edge_Key::set_edge(
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *this@<ecx>,
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key **a2@<eax>,
        IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *a,
        int b)
{
  *a2 = this;
  a2[1] = a;
}

//------------------------------------------------------------------------------
// Address: 0x10056B20
// Name: private: void IVP_Compact_Recursive::set_rekursive_convex_hull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Recursive::set_rekursive_convex_hull(IVP_Compact_Recursive *this)
{
  unsigned __int16 *p_memsize; // esi
  bool v2; // sf
  int v3; // eax
  int *v4; // ebx
  IVP_Compact_Triangle *v5; // ecx
  int v6; // edx
  int v7; // eax
  const IVP_U_Float_Point *v8; // edx
  const IVP_U_Float_Point *v9; // ecx
  int i; // esi
  const char *v11; // edi
  void *v12; // eax
  const char *v13; // eax
  int v14; // ecx
  int v15; // esi
  const char *v16; // eax
  IVP_Compact_Ledge *v17; // ecx
  IVP_Compact_Ledge *v18; // ebx
  int v19; // eax
  int c_point_offset; // eax
  $D94D6EC998D8AC7437E59ECF9B271F0E *v21; // edi
  int j; // esi
  const char *v23; // eax
  int v24; // ecx
  int v25; // esi
  const char *v26; // eax
  int v27; // [esp+0h] [ebp-7Ch]
  IVP_Hash point_hash; // [esp+Ch] [ebp-70h] BYREF
  IVP_Hash triangle_hash; // [esp+1Ch] [ebp-60h] BYREF
  IVP_Hash edge_hash; // [esp+2Ch] [ebp-50h] BYREF
  const IVP_U_Float_Point *p[3]; // [esp+3Ch] [ebp-40h]
  IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key triangle_key; // [esp+48h] [ebp-34h] BYREF
  int pi[3]; // [esp+54h] [ebp-28h]
  IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key edge_key; // [esp+60h] [ebp-1Ch] BYREF
  IVP_Compact_Ledge *ledge; // [esp+68h] [ebp-14h]
  int ledge_i; // [esp+6Ch] [ebp-10h]
  int t; // [esp+70h] [ebp-Ch]
  int n_points_in_hash; // [esp+74h] [ebp-8h]
  IVP_Compact_Triangle *tri; // [esp+78h] [ebp-4h]

  p_memsize = &this->ledges.memsize;
  ledge = (IVP_Compact_Ledge *)this;
  IVP_Hash::IVP_Hash(this: &point_hash, sizei: 1024, key_sizei: 16, not_found_valuei: (void *)0xFFFFFFFF);
  n_points_in_hash = 0;
  IVP_Hash::IVP_Hash(this: &triangle_hash, sizei: 1024, key_sizei: 12, not_found_valuei: nullptr);
  IVP_Hash::IVP_Hash(this: &edge_hash, sizei: 1024, key_sizei: 8, not_found_valuei: nullptr);
  v3 = p_memsize[1] - 1;
  v2 = p_memsize[1] == 0;
  ledge_i = v3;
  if ( !v2 )
  {
    do
    {
      v4 = *(int **)(*((_DWORD *)p_memsize + 1) + 4 * v3);
      v5 = (IVP_Compact_Triangle *)(v4 + 4);
      v6 = *((__int16 *)v4 + 6) - 1;
      tri = (IVP_Compact_Triangle *)(v4 + 4);
      t = v6;
      if ( v6 >= 0 )
      {
        while ( 1 )
        {
          v7 = *v4;
          p[0] = (const IVP_U_Float_Point *)((char *)&v4[4 * (unsigned __int16)*(_DWORD *)v5->c_three_edges] + *v4);
          v8 = (const IVP_U_Float_Point *)((char *)&v4[4 * (unsigned __int16)*(_DWORD *)&v5->c_three_edges[1]] + v7);
          v9 = (const IVP_U_Float_Point *)((char *)&v4[4 * (unsigned __int16)*(_DWORD *)&v5->c_three_edges[2]] + v7);
          p[1] = v8;
          p[2] = v9;
          for ( i = 0; i < 3; ++i )
          {
            v11 = (const char *)p[i];
            v12 = IVP_Hash::find(this: &point_hash, key: v11);
            if ( (int)v12 < 0 )
            {
              IVP_Hash::add(this: &point_hash, key: v11, val: (void *)n_points_in_hash);
              v12 = (void *)n_points_in_hash++;
            }
            pi[i] = (int)v12;
          }
          IVP_Compact_Recursive::set_rekursive_convex_hull_::_2_::Triangle_Key::set_tri(
            this: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[0],
            a2: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key **)&triangle_key,
            a: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[1],
            b: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[2],
            c: v27);
          if ( IVP_Hash::find(this: &triangle_hash, key: v13) == nullptr )
            IVP_Hash::add(this: &triangle_hash, key: (const char *)&triangle_key, val: (void *)tri);
          v14 = 0;
          do
          {
            v15 = v14 + 1;
            IVP_Compact_Recursive::set_rekursive_convex_hull_::_3_::Edge_Key::set_edge(
              this: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *)pi[v14],
              a2: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key **)&edge_key,
              a: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *)pi[(v14 + 1) % 3],
              b: v27);
            if ( IVP_Hash::find(this: &edge_hash, key: v16) == nullptr )
              IVP_Hash::add(this: &edge_hash, key: (const char *)&edge_key, val: (void *)tri);
            v14 = v15;
          }
          while ( v15 < 3 );
          ++tri;
          if ( --t < 0 )
            break;
          v5 = tri;
        }
        p_memsize = (unsigned __int16 *)ledge;
        v3 = ledge_i;
      }
      ledge_i = --v3;
    }
    while ( v3 >= 0 );
  }
  v17 = *((IVP_Compact_Ledge **)p_memsize + 2);
  v18 = v17 + 1;
  v19 = v17->n_triangles - 1;
  ledge = v17;
  ledge_i = (int)&v17[1];
  t = v19;
  if ( v19 >= 0 )
  {
    while ( 1 )
    {
      c_point_offset = v17->c_point_offset;
      v21 = &v18->___u1;
      p[0] = (const IVP_U_Float_Point *)((char *)&v17[(unsigned __int16)v18->ledgetree_node_offset] + v17->c_point_offset);
      p[1] = (const IVP_U_Float_Point *)((char *)&v17[(unsigned __int16)*((_DWORD *)v18 + 2)] + c_point_offset);
      p[2] = (const IVP_U_Float_Point *)((char *)&v17[(unsigned __int16)*(_DWORD *)&v18->n_triangles] + c_point_offset);
      for ( j = 0; j < 3; ++j )
        pi[j] = (int)IVP_Hash::find(this: &point_hash, key: (const char *)p[j]);
      IVP_Compact_Recursive::set_rekursive_convex_hull_::_2_::Triangle_Key::set_tri(
        this: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[0],
        a2: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key **)&triangle_key,
        a: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[1],
        b: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l2::Triangle_Key *)pi[2],
        c: v27);
      if ( IVP_Hash::find(this: &triangle_hash, key: v23) == nullptr )
        v18->c_point_offset |= 0x80000000;
      v24 = 0;
      do
      {
        v25 = v24 + 1;
        IVP_Compact_Recursive::set_rekursive_convex_hull_::_3_::Edge_Key::set_edge(
          this: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *)pi[v24],
          a2: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key **)&edge_key,
          a: (IVP_Compact_Recursive::set_rekursive_convex_hull::__l3::Edge_Key *)pi[(v24 + 1) % 3],
          b: v27);
        if ( IVP_Hash::find(this: &edge_hash, key: v26) == nullptr )
          v21->ledgetree_node_offset |= 0x80000000;
        v24 = v25;
        ++v21;
      }
      while ( v25 < 3 );
      v18 = (IVP_Compact_Ledge *)(ledge_i + 16);
      v2 = --t < 0;
      ledge_i += 16;
      if ( v2 )
        break;
      v17 = ledge;
    }
  }
  IVP_Hash::~IVP_Hash(this: &edge_hash);
  IVP_Hash::~IVP_Hash(this: &triangle_hash);
  IVP_Hash::~IVP_Hash(this: &point_hash);
}

//------------------------------------------------------------------------------
// Address: 0x10056DB0
// Name: public: IVP_Compact_Recursive::IVP_Compact_Recursive(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Recursive *__thiscall IVP_Compact_Recursive::IVP_Compact_Recursive(IVP_Compact_Recursive *this)
{
  *(_DWORD *)&this->ledges.memsize = 128;
  this->ledges.elems = (void **)p_malloc(size: 0x200u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056DD0
// Name: public: void IVP_Compact_Recursive::add_compact_ledge(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Recursive::add_compact_ledge(IVP_Friction_Core_Pair *this, IVP_Contact_Point *dist)
{
  if ( this->fr_dists.n_elems >= this->fr_dists.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->fr_dists);
  this->fr_dists.elems[this->fr_dists.n_elems++] = dist;
}

//------------------------------------------------------------------------------
// Address: 0x10056E00
// Name: private: void IVP_Compact_Recursive::build_convex_hull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Recursive::build_convex_hull(IVP_Compact_Recursive *this)
{
  IVP_Compact_Recursive *v1; // esi
  bool v2; // sf
  int v3; // edx
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  IVP_U_Float_Point *v6; // esi
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float *v10; // esi
  int v11; // esi
  IVP_Hash point_hash; // [esp+4h] [ebp-30h] BYREF
  IVP_U_Vector<IVP_U_Point> points; // [esp+14h] [ebp-20h] BYREF
  IVP_Compact_Recursive *v14; // [esp+1Ch] [ebp-18h] BYREF
  IVP_U_Float_Point *point_array; // [esp+20h] [ebp-14h]
  int k; // [esp+24h] [ebp-10h]
  int t; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  _DWORD *v19; // [esp+30h] [ebp-4h]

  v1 = this;
  v14 = this;
  IVP_Hash::IVP_Hash(this: &point_hash, sizei: 1024, key_sizei: 16, not_found_valuei: nullptr);
  v3 = v1->ledges.n_elems - 1;
  v2 = v1->ledges.n_elems == 0;
  *(_DWORD *)&points.memsize = 0;
  points.elems = nullptr;
  k = v3;
  if ( !v2 )
  {
    do
    {
      v4 = v1->ledges.elems[v3];
      point_array = (IVP_U_Float_Point *)((char *)v4 + *v4);
      t = *((__int16 *)v4 + 6) - 1;
      if ( t >= 0 )
      {
        v19 = v4 + 5;
        do
        {
          v5 = v19;
          for ( i = 3; i != 0; --i )
          {
            v6 = &point_array[(unsigned __int16)*v5];
            if ( IVP_Hash::find(this: &point_hash, key: (const char *)v6) == nullptr )
            {
              IVP_Hash::add(this: &point_hash, key: (const char *)v6, val: v6);
              v7 = (float *)p_malloc(size: 0x10u);
              if ( v7 != nullptr )
              {
                v8 = v6->k[1];
                v9 = v6->k[2];
                *v7 = v6->k[0];
                v7[1] = v8;
                v7[2] = v9;
                v10 = v7;
              }
              else
              {
                v10 = nullptr;
              }
              if ( points.n_elems >= points.memsize )
                IVP_U_Vector_Base::increment_mem(this: &points);
              points.elems[points.n_elems++] = v10;
            }
            ++v5;
          }
          v19 += 4;
          --t;
        }
        while ( t >= 0 );
        v1 = v14;
        v3 = k;
      }
      k = --v3;
    }
    while ( v3 >= 0 );
  }
  v1->hull = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(&points);
  v11 = points.n_elems - 1;
  if ( points.n_elems != 0 )
  {
    do
      free(data: points.elems[v11--]);
    while ( v11 >= 0 );
  }
  if ( (IVP_Compact_Recursive **)points.elems != &v14 )
  {
    if ( points.elems != nullptr )
      free(data: points.elems);
    points.elems = nullptr;
    points.memsize = 0;
  }
  points.n_elems = 0;
  IVP_Hash::~IVP_Hash(this: &point_hash);
}

//------------------------------------------------------------------------------
// Address: 0x10056F70
// Name: public: class IVP_Compact_Ledge __near * IVP_Compact_Recursive::compile(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__thiscall IVP_Compact_Recursive::compile(IVP_Compact_Recursive *this)
{
  IVP_Compact_Recursive::build_convex_hull(this);
  if ( this->hull != nullptr )
    IVP_Compact_Recursive::set_rekursive_convex_hull(this);
  return this->hull;
}
