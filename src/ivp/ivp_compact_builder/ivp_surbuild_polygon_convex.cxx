// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_surbuild_polygon_convex.cxx
// Functions: 7
// ============================================================

#include "ivp\ivp_compact_builder\ivp_surbuild_polygon_convex.h"

//------------------------------------------------------------------------------
// Address: 0x100489F0
// Name: public: IVP_SurfaceBuilder_Polygon_Convex::~IVP_SurfaceBuilder_Polygon_Convex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Polygon_Convex::~IVP_SurfaceBuilder_Polygon_Convex(
        IVP_SurfaceBuilder_Polygon_Convex *this)
{
  int i; // edi
  IVP_VHash_Elem *elems; // edx
  IVP_point_hash *poly_point_hash; // ecx
  IVP_Object_Polygon_Tetra *tetras; // edi

  for ( i = this->poly_point_hash->size_mm; i >= 0; --i )
  {
    elems = this->poly_point_hash->elems;
    if ( elems[i].elem != nullptr )
      free(data: (void *)elems[i].elem);
  }
  poly_point_hash = this->poly_point_hash;
  if ( poly_point_hash != nullptr )
    ((void (__thiscall *)(IVP_point_hash *, int))poly_point_hash->dtr_IVP_VHash)(a1: poly_point_hash, a2: 1);
  tetras = this->tetras;
  this->poly_point_hash = nullptr;
  if ( tetras != nullptr )
  {
    IVP_Object_Polygon_Tetra::~IVP_Object_Polygon_Tetra(this: tetras);
    free(data: tetras);
  }
  this->tetras = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10048A50
// Name: protected: IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex(class IVP_Template_Ledge_Polygon_Soup __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceBuilder_Polygon_Convex *__userpurge IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex@<eax>(
        IVP_SurfaceBuilder_Polygon_Convex *this@<ecx>,
        int a2@<ebp>,
        IVP_Template_Ledge_Polygon_Soup *templ_ledge)
{
  IVP_SurfaceBuilder_Polygon_Convex *v3; // esi
  IVP_VHash *v4; // eax
  IVP_point_hash *v5; // edi
  IVP_Template_Triangle *templ_triangles_array; // edi
  int *v7; // edi
  IVP_I_Point_VHash *poly_point_hash; // esi
  float v9; // xmm0_4
  unsigned int v10; // eax
  void *elem; // eax
  IVP_U_Point *v12; // esi
  IVP_U_Point *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  IVP_I_Point_VHash *v17; // ecx
  int v18; // eax
  IVP_Triangle *double_triangle; // esi
  IVP_Triangle *other_side; // eax
  IVP_Poly_Surface *v21; // edi
  IVP_Triangle *v22; // edx
  IVP_Triangle *v23; // esi
  int v24; // esi
  unsigned __int8 *v25; // edi
  int v26; // esi
  IVP_U_Vector<IVP_Poly_Surface> *v27; // eax
  void (__thiscall ***v28)(_DWORD, int); // ecx
  int v29; // esi
  IVP_Poly_Point *v30; // ecx
  _BYTE v32[16]; // [esp-Ch] [ebp-6Ch] BYREF
  float v33; // [esp+4h] [ebp-5Ch] BYREF
  float v34; // [esp+8h] [ebp-58h]
  float v35; // [esp+Ch] [ebp-54h]
  IVP_Poly_Point new_point_static; // [esp+10h] [ebp-50h]
  IVP_Poly_Point *v37; // [esp+30h] [ebp-30h]
  IVP_Poly_Point *v38; // [esp+34h] [ebp-2Ch]
  IVP_Poly_Point *new_point[3]; // [esp+38h] [ebp-28h] BYREF
  IVP_U_Vector<IVP_Poly_Surface> sur_vec; // [esp+44h] [ebp-1Ch] BYREF
  IVP_U_Vector<IVP_Triangle> tri_vec; // [esp+4Ch] [ebp-14h]
  int v42; // [esp+54h] [ebp-Ch]
  void *v43; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v42 = a2;
  v43 = retaddr;
  v3 = this;
  *(_DWORD *)&tri_vec.memsize = this;
  this->tetras = nullptr;
  this->c_ledge = nullptr;
  v4 = (IVP_VHash *)p_malloc(size: 0x10u);
  v5 = (IVP_point_hash *)v4;
  if ( v4 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v4, size_i: 8);
    v5->__vftable = (IVP_point_hash_vtbl *)&IVP_I_FPoint_VHash::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  v3->poly_point_hash = v5;
  if ( templ_ledge != nullptr )
  {
    templ_triangles_array = templ_ledge->templ_triangles_array;
    *(_DWORD *)&sur_vec.memsize = 0;
    memset(new_point, 0, sizeof(new_point));
    tri_vec.elems = nullptr;
    v7 = (int *)&templ_triangles_array->tri_points[0].k[2];
    while ( 1 )
    {
      poly_point_hash = (IVP_I_Point_VHash *)v3->poly_point_hash;
      v33 = *((float *)v7 - 2);
      v34 = *((float *)v7 - 1);
      v9 = *(float *)v7;
      new_point_static.k[2] = 0.0;
      v35 = v9;
      v10 = IVP_I_Point_VHash::point_to_index(this: poly_point_hash, point: (IVP_U_Point *)&v33);
      elem = IVP_VHash::find_elem(this: poly_point_hash, elem: &v33, hash_index: v10);
      v12 = nullptr;
      *((_DWORD *)&new_point_static.tmp + (int)tri_vec.elems + 2) = elem;
      if ( elem == nullptr )
      {
        v13 = (IVP_U_Point *)p_malloc(size: 0x20u);
        if ( v13 != nullptr )
        {
          v13[1].k[1] = 0.0;
          v12 = v13;
        }
        v14 = v34;
        v15 = v35;
        v16 = v33;
        v17 = *(IVP_I_Point_VHash **)(*(_DWORD *)&tri_vec.memsize + 8);
        *((_DWORD *)&new_point_static.tmp + (int)tri_vec.elems + 2) = v12;
        v12->k[0] = v16;
        v12->k[1] = v14;
        v12->k[2] = v15;
        sur_vec.elems = (void **)&v17->__vftable;
        v18 = IVP_I_Point_VHash::point_to_index(this: v17, point: v12);
        IVP_VHash::add_elem(this: (IVP_VHash *)sur_vec.elems, elem: v12, hash_index: v18);
      }
      v7 += 4;
      if ( (int)++tri_vec.elems >= 3 )
        break;
      v3 = *(IVP_SurfaceBuilder_Polygon_Convex **)&tri_vec.memsize;
    }
    double_triangle = IVP_Object_Polygon_Tetra::generate_double_triangle(
                        p1: *((IVP_Poly_Point **)&new_point_static.tmp + 2),
                        p2: v37,
                        p3: v38);
    other_side = double_triangle->other_side;
    double_triangle->pierced_triangle = other_side;
    other_side->pierced_triangle = double_triangle;
    v21 = (IVP_Poly_Surface *)p_malloc(size: 0xCu);
    v21->tetras = nullptr;
    v22 = double_triangle->other_side;
    double_triangle->ivp_surface = v21;
    v22->ivp_surface = v21;
    if ( HIWORD(new_point[2]) >= LOWORD(new_point[2]) )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&new_point[2]);
    *(_DWORD *)(*(_DWORD *)&sur_vec.memsize + 4 * HIWORD(new_point[2])) = double_triangle;
    ++HIWORD(new_point[2]);
    v23 = double_triangle->other_side;
    if ( HIWORD(new_point[2]) >= LOWORD(new_point[2]) )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&new_point[2]);
    *(_DWORD *)(*(_DWORD *)&sur_vec.memsize + 4 * HIWORD(new_point[2])) = v23;
    ++HIWORD(new_point[2]);
    if ( HIWORD(new_point[0]) >= LOWORD(new_point[0]) )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)new_point);
    LODWORD(new_point[1]->k[HIWORD(new_point[0])]) = v21;
    ++HIWORD(new_point[0]);
    IVP_Compact_Ledge_Generator::IVP_Compact_Ledge_Generator(this: (IVP_Compact_Ledge_Generator *)v32);
    v24 = IVP_Compact_Ledge_Generator::prepare_compact_ledge(
            this: (IVP_Compact_Ledge_Generator *)v32,
            triangles: (IVP_U_Vector<IVP_Triangle> *)&new_point[2]);
    v25 = (unsigned __int8 *)ivp_malloc_aligned(size: v24, alignment: 16);
    memset(dst: v25, value: 0, count: v24);
    IVP_Compact_Ledge_Generator::generate_compact_ledge(this: (IVP_Compact_Ledge_Generator *)v32, mem: v25);
    IVP_Compact_Ledge_Generator::~IVP_Compact_Ledge_Generator(this: (IVP_Compact_Ledge_Generator *)v32);
    v26 = HIWORD(new_point[2]) - 1;
    v27 = *(IVP_U_Vector<IVP_Poly_Surface> **)&sur_vec.memsize;
    if ( HIWORD(new_point[2]) != 0 )
    {
      do
      {
        v28 = *((void (__thiscall ****)(_DWORD, int))&v27->memsize + v26);
        if ( v28 != nullptr )
        {
          (**v28)(a1: v28, a2: 1);
          v27 = *(IVP_U_Vector<IVP_Poly_Surface> **)&sur_vec.memsize;
        }
        --v26;
      }
      while ( v26 >= 0 );
    }
    v29 = HIWORD(new_point[0]) - 1;
    if ( HIWORD(new_point[0]) != 0 )
    {
      do
        free(data: (void *)LODWORD(new_point[1]->k[v29--]));
      while ( v29 >= 0 );
      v27 = *(IVP_U_Vector<IVP_Poly_Surface> **)&sur_vec.memsize;
    }
    v30 = new_point[1];
    if ( (IVP_Poly_Point **)new_point[1] != &new_point[2] )
    {
      if ( new_point[1] != nullptr )
      {
        free(data: new_point[1]);
        v27 = *(IVP_U_Vector<IVP_Poly_Surface> **)&sur_vec.memsize;
      }
      v30 = nullptr;
      new_point[1] = nullptr;
      LOWORD(new_point[0]) = 0;
    }
    HIWORD(new_point[0]) = 0;
    if ( v27 != (IVP_U_Vector<IVP_Poly_Surface> *)&sur_vec.elems )
    {
      if ( v27 != nullptr )
      {
        free(data: v27);
        v30 = new_point[1];
      }
      v27 = nullptr;
      *(_DWORD *)&sur_vec.memsize = 0;
      LOWORD(new_point[2]) = 0;
    }
    v3 = *(IVP_SurfaceBuilder_Polygon_Convex **)&tri_vec.memsize;
    HIWORD(new_point[2]) = 0;
    *(_DWORD *)(*(_DWORD *)&tri_vec.memsize + 4) = v25;
    if ( v30 != (IVP_Poly_Point *)&new_point[2] )
    {
      if ( v30 != nullptr )
      {
        free(data: v30);
        v27 = *(IVP_U_Vector<IVP_Poly_Surface> **)&sur_vec.memsize;
      }
      new_point[1] = nullptr;
      LOWORD(new_point[0]) = 0;
    }
    HIWORD(new_point[0]) = 0;
    if ( v27 != (IVP_U_Vector<IVP_Poly_Surface> *)&sur_vec.elems && v27 != nullptr )
      free(data: v27);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10048D40
// Name: protected: void IVP_SurfaceBuilder_Polygon_Convex::fill_list_with_all_triangles(class IVP_U_Vector<class IVP_Triangle> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Polygon_Convex::fill_list_with_all_triangles(
        IVP_SurfaceBuilder_Polygon_Convex *this,
        IVP_U_Vector<IVP_Triangle> *tri_vec)
{
  IVP_Triangle *i; // edi

  for ( i = this->tetras->triangles.first; i != nullptr; i = i->next )
  {
    if ( i->flags.is_hidden == 0 )
    {
      if ( tri_vec->n_elems >= tri_vec->memsize )
        IVP_U_Vector_Base::increment_mem(this: tri_vec);
      tri_vec->elems[tri_vec->n_elems++] = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048D90
// Name: protected: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Polygon_Convex::convert_templateledgepolygonsoup_to_ledge(class IVP_Template_Ledge_Polygon_Soup __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl IVP_SurfaceBuilder_Polygon_Convex::convert_templateledgepolygonsoup_to_ledge(
        IVP_Compact_Ledge *templat)
{
  IVP_Compact_Ledge *result; // eax
  IVP_Compact_Ledge *c_ledge; // esi
  IVP_SurfaceBuilder_Polygon_Convex surface_builder; // [esp+0h] [ebp-Ch] BYREF
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  result = templat;
  if ( templat != nullptr )
  {
    IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex(
      this: &surface_builder,
      a2: (int)&savedregs,
      templ_ledge: (IVP_Template_Ledge_Polygon_Soup *)templat);
    c_ledge = surface_builder.c_ledge;
    surface_builder.c_ledge = nullptr;
    IVP_SurfaceBuilder_Polygon_Convex::~IVP_SurfaceBuilder_Polygon_Convex(this: &surface_builder);
    return c_ledge;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048DD0
// Name: protected: void IVP_SurfaceBuilder_Polygon_Convex::init_surface_manager_polygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Polygon_Convex::init_surface_manager_polygon(
        IVP_SurfaceBuilder_Polygon_Convex *this)
{
  IVP_Hash *v2; // eax
  IVP_Hash *v3; // eax
  const char *triangles; // eax
  IVP_Hash *points_to_edge_hash; // edi
  const char *v6; // ebx
  IVP_Triangle *i; // edi
  int v8; // eax
  unsigned __int8 *v9; // edi
  IVP_Compact_Ledge_Generator ledge_gen; // [esp+8h] [ebp-38h] BYREF
  IVP_U_Vector<IVP_Triangle> tri_vec; // [esp+38h] [ebp-8h] BYREF
  char vars0; // [esp+40h] [ebp+0h] BYREF

  v2 = (IVP_Hash *)p_malloc(size: 0x10u);
  if ( v2 != nullptr )
    v3 = IVP_Hash::IVP_Hash(this: v2, sizei: 500, key_sizei: 8, not_found_valuei: nullptr);
  else
    v3 = nullptr;
  this->tetras->points_to_edge_hash = v3;
  triangles = IVP_Object_Polygon_Tetra::make_triangles(this: this->tetras);
  points_to_edge_hash = this->tetras->points_to_edge_hash;
  v6 = triangles;
  if ( points_to_edge_hash != nullptr )
  {
    IVP_Hash::~IVP_Hash(this: this->tetras->points_to_edge_hash);
    free(data: points_to_edge_hash);
  }
  this->tetras->points_to_edge_hash = nullptr;
  if ( v6 != nullptr )
  {
    this->tetras = nullptr;
    this->c_ledge = nullptr;
  }
  else
  {
    for ( i = this->tetras->triangles.first; i != nullptr; i = i->next )
      IVP_Triangle::calc_hesse(this: i);
    IVP_Object_Polygon_Tetra::insert_pierce_info(this: this->tetras);
    *(_DWORD *)&tri_vec.memsize = 0;
    tri_vec.elems = nullptr;
    IVP_SurfaceBuilder_Polygon_Convex::fill_list_with_all_triangles(this, &tri_vec);
    IVP_Compact_Ledge_Generator::IVP_Compact_Ledge_Generator(this: &ledge_gen);
    v8 = IVP_Compact_Ledge_Generator::prepare_compact_ledge(this: &ledge_gen, triangles: &tri_vec);
    v9 = (unsigned __int8 *)ivp_malloc_aligned(size: v8, alignment: 16);
    IVP_Compact_Ledge_Generator::generate_compact_ledge(this: &ledge_gen, mem: v9);
    IVP_Compact_Ledge_Generator::~IVP_Compact_Ledge_Generator(this: &ledge_gen);
    if ( (char *)tri_vec.elems != &vars0 && tri_vec.elems != nullptr )
      free(data: tri_vec.elems);
    this->c_ledge = (IVP_Compact_Ledge *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048EC0
// Name: protected: IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex(class IVP_Template_Polygon __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceBuilder_Polygon_Convex *__thiscall IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex(
        IVP_SurfaceBuilder_Polygon_Convex *this,
        IVP_Template_Polygon *templ)
{
  IVP_VHash *v3; // eax
  IVP_point_hash *v4; // edi
  IVP_Object_Polygon_Tetra *v5; // eax
  IVP_Object_Polygon_Tetra *v6; // eax

  v3 = (IVP_VHash *)p_malloc(size: 0x10u);
  v4 = (IVP_point_hash *)v3;
  if ( v3 != nullptr )
  {
    IVP_VHash::IVP_VHash(this: v3, size_i: 8);
    v4->__vftable = (IVP_point_hash_vtbl *)&IVP_I_FPoint_VHash::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  this->poly_point_hash = v4;
  v5 = (IVP_Object_Polygon_Tetra *)p_malloc(size: 0x50u);
  if ( v5 != nullptr )
    v6 = IVP_Object_Polygon_Tetra::IVP_Object_Polygon_Tetra(this: v5, i_temp_pop: templ);
  else
    v6 = nullptr;
  this->tetras = v6;
  v6->template_polygon = templ;
  this->c_ledge = nullptr;
  IVP_SurfaceBuilder_Polygon_Convex::init_surface_manager_polygon(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048F30
// Name: public: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Polygon_Convex::convert_template_to_ledge(class IVP_Template_Polygon __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl IVP_SurfaceBuilder_Polygon_Convex::convert_template_to_ledge(IVP_Compact_Ledge *templat)
{
  IVP_Compact_Ledge *result; // eax
  IVP_Compact_Ledge *c_ledge; // esi
  IVP_SurfaceBuilder_Polygon_Convex surman; // [esp+0h] [ebp-Ch] BYREF

  result = templat;
  if ( templat != nullptr )
  {
    IVP_SurfaceBuilder_Polygon_Convex::IVP_SurfaceBuilder_Polygon_Convex(
      this: &surman,
      templ: (IVP_Template_Polygon *)templat);
    c_ledge = surman.c_ledge;
    surman.c_ledge = nullptr;
    IVP_SurfaceBuilder_Polygon_Convex::~IVP_SurfaceBuilder_Polygon_Convex(this: &surman);
    return c_ledge;
  }
  return result;
}
