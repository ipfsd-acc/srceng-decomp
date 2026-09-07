// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_compact_ledge_gen.cxx
// Functions: 4
// ============================================================

#include "ivp\ivp_compact_builder\ivp_compact_ledge_gen.h"

//------------------------------------------------------------------------------
// Address: 0x10059130
// Name: public: IVP_Compact_Ledge_Generator::IVP_Compact_Ledge_Generator(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge_Generator *__thiscall IVP_Compact_Ledge_Generator::IVP_Compact_Ledge_Generator(
        IVP_Compact_Ledge_Generator *this)
{
  *(_DWORD *)&this->point_vec.memsize = 0;
  this->point_vec.elems = nullptr;
  *(_DWORD *)&this->triangle_vec.memsize = 0;
  this->triangle_vec.elems = nullptr;
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Compact_Ledge_Generator));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10059160
// Name: public: void IVP_Compact_Ledge_Generator::generate_compact_ledge(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge_Generator::generate_compact_ledge(
        IVP_Compact_Ledge_Generator *this,
        unsigned __int8 *mem)
{
  int v3; // eax
  unsigned __int8 *i; // esi
  _QWORD *v5; // ecx
  int v6; // ecx
  float *v7; // eax
  int v8; // xmm0_4
  int v9; // xmm1_4

  this->compact_ledge = (IVP_Compact_Ledge *)mem;
  IVP_Compact_Ledge::c_ledge_init(this: (IVP_Compact_Ledge *)mem);
  *((_WORD *)mem + 6) = this->n_triangles;
  v3 = 0;
  for ( i = mem + 16; v3 < this->n_triangles; i += 16 )
  {
    v5 = this->triangle_vec.elems[v3];
    *(_QWORD *)i = *v5;
    *((_QWORD *)i + 1) = v5[1];
    ++v3;
  }
  v6 = 0;
  for ( *(_DWORD *)mem = i - mem; v6 < this->point_cnt; i += 16 )
  {
    *((_DWORD *)i + 3) = 0;
    v7 = (float *)this->point_vec.elems[v6];
    v8 = *((_DWORD *)v7 + 1);
    v9 = *((_DWORD *)v7 + 2);
    *(float *)i = *v7;
    *((_DWORD *)i + 1) = v8;
    *((_DWORD *)i + 2) = v9;
    ++v6;
  }
  *((_DWORD *)mem + 2) = *((_DWORD *)mem + 2) & 0xF3 | ((i - mem) >> 4 << 8) | 4;
}

//------------------------------------------------------------------------------
// Address: 0x10059210
// Name: public: IVP_Compact_Ledge_Generator::~IVP_Compact_Ledge_Generator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge_Generator::~IVP_Compact_Ledge_Generator(IVP_Compact_Ledge_Generator *this)
{
  int i; // edi
  IVP_Compact_Ledge_Generator *elems; // eax
  IVP_Hash *edge_hash; // edi
  int v5; // edi
  IVP_Compact_Ledge_Generator *v6; // eax
  IVP_Compact_Ledge_Generator *v7; // eax
  IVP_Compact_Ledge_Generator *v8; // eax

  for ( i = 0; i < this->n_triangles; ++i )
    IVP_Triangle::calc_hesse(this: (IVP_Triangle *)this->orig_triangles->elems[i]);
  elems = (IVP_Compact_Ledge_Generator *)this->point_vec.elems;
  if ( elems != (IVP_Compact_Ledge_Generator *)&this->triangle_vec )
  {
    if ( elems != nullptr )
      free(data: this->point_vec.elems);
    this->point_vec.elems = nullptr;
    this->point_vec.memsize = 0;
  }
  this->point_vec.n_elems = 0;
  if ( this->point_hash != nullptr )
    ((void (__thiscall *)(IVP_point_hash *, int))this->point_hash->dtr_IVP_VHash)(a1: this->point_hash, a2: 1);
  edge_hash = this->edge_hash;
  this->point_hash = nullptr;
  if ( edge_hash != nullptr )
  {
    IVP_Hash::~IVP_Hash(this: edge_hash);
    free(data: edge_hash);
  }
  v5 = 0;
  for ( this->edge_hash = nullptr; v5 < this->n_triangles; ++v5 )
    free(data: this->triangle_vec.elems[v5]);
  v6 = (IVP_Compact_Ledge_Generator *)this->triangle_vec.elems;
  if ( v6 != (IVP_Compact_Ledge_Generator *)&this->point_cnt )
  {
    if ( v6 != nullptr )
      free(data: this->triangle_vec.elems);
    this->triangle_vec.elems = nullptr;
    this->triangle_vec.memsize = 0;
  }
  this->triangle_vec.n_elems = 0;
  v7 = (IVP_Compact_Ledge_Generator *)this->triangle_vec.elems;
  if ( v7 != (IVP_Compact_Ledge_Generator *)&this->point_cnt )
  {
    if ( v7 != nullptr )
      free(data: this->triangle_vec.elems);
    this->triangle_vec.elems = nullptr;
    this->triangle_vec.memsize = 0;
  }
  this->triangle_vec.n_elems = 0;
  v8 = (IVP_Compact_Ledge_Generator *)this->point_vec.elems;
  if ( v8 == (IVP_Compact_Ledge_Generator *)&this->triangle_vec )
  {
    this->point_vec.n_elems = 0;
  }
  else
  {
    if ( v8 != nullptr )
      free(data: this->point_vec.elems);
    this->point_vec.elems = nullptr;
    *(_DWORD *)&this->point_vec.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059320
// Name: public: int IVP_Compact_Ledge_Generator::prepare_compact_ledge(class IVP_U_Vector<class IVP_Triangle> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Compact_Ledge_Generator::prepare_compact_ledge(
        IVP_Compact_Ledge_Generator *this,
        IVP_U_Vector<IVP_Triangle> *triangles)
{
  int n_elems; // eax
  int v4; // ebx
  IVP_VHash *v5; // eax
  IVP_point_hash *v6; // edi
  int v7; // eax
  _DWORD *v8; // ebx
  char *v9; // ebx
  IVP_U_Point *v10; // edi
  unsigned int v11; // eax
  IVP_U_Point *v12; // edi
  unsigned int v13; // eax
  unsigned __int16 v14; // ax
  bool v15; // zf
  IVP_Hash *v16; // eax
  IVP_Hash *v17; // eax
  bool v18; // cc
  char *v19; // ebx
  IVP_Compact_Triangle *v20; // eax
  IVP_Compact_Triangle *v21; // edi
  int v22; // eax
  IVP_Tri_Edge *next; // eax
  int v24; // ebx
  int v25; // edx
  IVP_Tri_Edge *v26; // edx
  int v27; // eax
  int v28; // eax
  char *v29; // ebx
  char *v30; // edi
  _DWORD *v31; // ebx
  IVP_Hash *edge_hash; // ecx
  void *v33; // eax
  int v34; // ecx
  IVP_U_Point *v36; // [esp-4h] [ebp-24h]
  IVP_U_Point *v37; // [esp-4h] [ebp-24h]
  IVP_Tri_Edge *opp; // [esp+Ch] [ebp-14h] BYREF
  IVP_VHash *point_hash; // [esp+10h] [ebp-10h]
  int c_three_edges; // [esp+14h] [ebp-Ch]
  IVP_Tri_Edge *edge; // [esp+18h] [ebp-8h] BYREF
  int i; // [esp+1Ch] [ebp-4h]

  this->orig_triangles = triangles;
  n_elems = triangles->n_elems;
  this->n_triangles = n_elems;
  v4 = 16;
  edge = (IVP_Tri_Edge *)16;
  if ( 3 * n_elems / 2 > 16 )
  {
    do
      v4 *= 2;
    while ( v4 < 3 * this->n_triangles / 2 );
    edge = (IVP_Tri_Edge *)v4;
  }
  v5 = (IVP_VHash *)p_malloc(size: 0x10u);
  v6 = (IVP_point_hash *)v5;
  if ( v5 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v5, size_i: v4);
    v6->__vftable = (IVP_point_hash_vtbl *)&IVP_I_FPoint_VHash::`vftable';
  }
  else
  {
    v6 = nullptr;
  }
  v7 = 0;
  this->point_hash = v6;
  i = 0;
  if ( this->n_triangles > 0 )
  {
    while ( 1 )
    {
      v8 = triangles->elems[v7];
      v8[44] = v7;
      v9 = (char *)(v8 + 10);
      c_three_edges = 3;
      do
      {
        v10 = *(IVP_U_Point **)v9;
        v36 = *(IVP_U_Point **)v9;
        point_hash = this->point_hash;
        v11 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)point_hash, point: v36);
        if ( IVP_VHash::find_elem(this: point_hash, elem: v10, hash_index: v11) == nullptr )
        {
          *(_DWORD *)(*(_DWORD *)v9 + 20) = this->point_cnt++;
          v12 = *(IVP_U_Point **)v9;
          v37 = *(IVP_U_Point **)v9;
          point_hash = this->point_hash;
          v13 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)point_hash, point: v37);
          IVP_VHash::add_elem(this: point_hash, elem: v12, hash_index: v13);
          v14 = this->point_vec.n_elems;
          point_hash = *(IVP_VHash **)v9;
          if ( v14 >= this->point_vec.memsize )
            IVP_U_Vector_Base::increment_mem(this: &this->point_vec);
          this->point_vec.elems[this->point_vec.n_elems++] = point_hash;
        }
        v15 = c_three_edges-- == 1;
        v9 = *((char **)v9 + 2);
      }
      while ( !v15 );
      if ( ++i >= this->n_triangles )
        break;
      v7 = i;
    }
    v4 = (int)edge;
  }
  this->edge_cnt = 0;
  v16 = (IVP_Hash *)p_malloc(size: 0x10u);
  if ( v16 != nullptr )
    v17 = IVP_Hash::IVP_Hash(this: v16, sizei: 4 * v4, key_sizei: 4, not_found_valuei: (void *)0xFFFFFFFF);
  else
    v17 = nullptr;
  v18 = this->n_triangles <= 0;
  this->edge_hash = v17;
  i = 0;
  if ( !v18 )
  {
    do
    {
      v19 = (char *)triangles->elems[i];
      v20 = (IVP_Compact_Triangle *)p_malloc(size: 0x10u);
      if ( v20 != nullptr )
        v21 = IVP_Compact_Triangle::IVP_Compact_Triangle(this: v20);
      else
        v21 = nullptr;
      *(_DWORD *)v21 ^= (*(_DWORD *)v21 ^ *((_DWORD *)v19 + 44)) & 0xFFF;
      v22 = *((_DWORD *)v19 + 7);
      if ( v22 != 0 )
        *(_DWORD *)v21 ^= (*(_DWORD *)v21 ^ (*(_DWORD *)(v22 + 176) << 12)) & 0xFFF000;
      else
        printf(format: "no valid pierce index!? Probably a backside triangle...\n");
      *(_DWORD *)v21 &= 0x80FFFFFF;
      next = (IVP_Tri_Edge *)(v19 + 40);
      edge = (IVP_Tri_Edge *)(v19 + 40);
      v24 = 0;
      c_three_edges = (int)v21->c_three_edges;
      do
      {
        v25 = i;
        *(_WORD *)c_three_edges = next->start_point->tmp.tetra_point;
        IVP_Hash::add(this: this->edge_hash, key: (const char *)&edge, val: (void *)(v24 + 4 * v25 + 1));
        v26 = edge;
        ++this->edge_cnt;
        next = v26->next;
        c_three_edges += 4;
        ++v24;
        edge = next;
      }
      while ( v24 < 3 );
      if ( this->triangle_vec.n_elems >= this->triangle_vec.memsize )
        IVP_U_Vector_Base::increment_mem(this: &this->triangle_vec);
      v27 = i;
      this->triangle_vec.elems[this->triangle_vec.n_elems++] = (void *)v21;
      i = v27 + 1;
    }
    while ( v27 + 1 < this->n_triangles );
  }
  v28 = 0;
  c_three_edges = 0;
  if ( this->n_triangles > 0 )
  {
    edge = (IVP_Tri_Edge *)-1;
    while ( 1 )
    {
      v29 = (char *)this->triangle_vec.elems[v28];
      v30 = (char *)triangles->elems[v28] + 40;
      i = (int)edge;
      v31 = v29 + 4;
      point_hash = (IVP_VHash *)3;
      do
      {
        edge_hash = this->edge_hash;
        opp = *((IVP_Tri_Edge **)v30 + 5);
        v33 = IVP_Hash::find(this: edge_hash, key: (const char *)&opp);
        v34 = i - 1;
        *v31 ^= (*v31 ^ (((_DWORD)v33 + i) << 16)) & 0x7FFF0000;
        v30 = *((char **)v30 + 2);
        ++v31;
        v15 = point_hash == (IVP_VHash *)1;
        point_hash = (IVP_VHash *)((char *)point_hash - 1);
        i = v34;
      }
      while ( !v15 );
      edge = (IVP_Tri_Edge *)((char *)edge - 4);
      if ( ++c_three_edges >= this->n_triangles )
        break;
      v28 = c_three_edges;
    }
  }
  return 16 * (this->point_cnt + this->n_triangles + 1);
}
