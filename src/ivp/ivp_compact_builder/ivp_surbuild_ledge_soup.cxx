// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_surbuild_ledge_soup.cxx
// Functions: 17
// ============================================================

#include "ivp\ivp_compact_builder\ivp_surbuild_ledge_soup.h"

//------------------------------------------------------------------------------
// Address: 0x10046FF0
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::add_ledge_tree_to_convex_hull(class IVP_Compact_Recursive __near &,class IVV_Sphere __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::add_ledge_tree_to_convex_hull(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVP_Compact_Recursive *cr,
        IVV_Sphere *node)
{
  IVV_Sphere *v3; // esi

  v3 = node;
  if ( node != nullptr )
  {
    while ( v3->compact_ledge == nullptr )
    {
      if ( v3->child_1 != nullptr )
        IVP_SurfaceBuilder_Ledge_Soup::add_ledge_tree_to_convex_hull(this, cr, node: v3->child_1);
      v3 = v3->child_2;
      if ( v3 == nullptr )
        return;
    }
    IVP_Compact_Recursive::add_compact_ledge(
      this: (IVP_Friction_Core_Pair *)cr,
      dist: (IVP_Contact_Point *)v3->compact_ledge);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047040
// Name: protected: int IVP_SurfaceBuilder_Ledge_Soup::recompile_point_indizes_of_compact_ledge(class IVP_Compact_Ledge __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall IVP_SurfaceBuilder_Ledge_Soup::recompile_point_indizes_of_compact_ledge(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVP_Compact_Ledge *ledge_source,
        char *dest)
{
  unsigned int v5; // esi
  char *v6; // ecx
  IVP_Compact_Edge *v7; // edi
  IVP_Compact_Poly_Point *v8; // esi
  unsigned int v9; // eax
  void *elem; // eax
  IVP_Compact_Poly_Point *v11; // edi
  IVP_I_Point_VHash *v12; // esi
  int v13; // eax
  bool v14; // zf
  int size; // [esp+8h] [ebp-18h]
  IVP_I_Point_VHash *point_hash; // [esp+Ch] [ebp-14h]
  IVP_Compact_Poly_Point *source_ledge_points; // [esp+10h] [ebp-10h]
  int t; // [esp+14h] [ebp-Ch]
  int v19; // [esp+18h] [ebp-8h]
  IVP_Compact_Edge *edge; // [esp+1Ch] [ebp-4h]
  IVP_Compact_Ledge *ledge_sourcea; // [esp+28h] [ebp+8h]

  if ( this->point_hash != nullptr )
  {
    v5 = 16 * (ledge_source->n_triangles + 1);
    size = v5;
    memcpy(dst: (unsigned __int8 *)dest, src: (unsigned __int8 *)ledge_source, count: v5);
    v6 = dest;
    source_ledge_points = (IVP_Compact_Poly_Point *)((char *)ledge_source + ledge_source->c_point_offset);
    t = *((__int16 *)dest + 6) - 1;
    if ( t >= 0 )
    {
      ledge_sourcea = (IVP_Compact_Ledge *)(dest + 20);
      do
      {
        v7 = (IVP_Compact_Edge *)ledge_sourcea;
        edge = (IVP_Compact_Edge *)ledge_sourcea;
        v19 = 3;
        do
        {
          v8 = &source_ledge_points[(unsigned __int16)*(_DWORD *)v7];
          point_hash = (IVP_I_Point_VHash *)this->point_hash;
          v9 = IVP_I_Point_VHash::point_to_index(this: point_hash, point: (IVP_U_Point *)v8);
          elem = IVP_VHash::find_elem(this: point_hash, elem: v8, hash_index: v9);
          if ( elem != nullptr )
          {
            *(_WORD *)v7 = (signed int)((int)elem - (unsigned int)this->first_poly_point) >> 4;
          }
          else
          {
            *(_WORD *)v7 = this->n_poly_points_allocated;
            v11 = &this->first_poly_point[this->n_poly_points_allocated++];
            *(_QWORD *)v11->k = *(_QWORD *)v8->k;
            *(_QWORD *)&v11->k[2] = *(_QWORD *)&v8->k[2];
            v12 = (IVP_I_Point_VHash *)this->point_hash;
            v13 = IVP_I_Point_VHash::point_to_index(this: v12, point: (IVP_U_Point *)v11);
            IVP_VHash::add_elem(this: v12, elem: v11, hash_index: v13);
            v7 = edge;
          }
          ++v7;
          v14 = v19-- == 1;
          edge = v7;
        }
        while ( !v14 );
        ++ledge_sourcea;
        --t;
      }
      while ( t >= 0 );
      v5 = size;
      v6 = dest;
    }
    *(_DWORD *)v6 = (char *)this->first_poly_point - v6;
    return v5;
  }
  else
  {
    memcpy(
      dst: (unsigned __int8 *)dest,
      src: (unsigned __int8 *)ledge_source,
      count: 16 * (*((_DWORD *)ledge_source + 2) >> 8));
    return 16 * (*((_DWORD *)ledge_source + 2) >> 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047180
// Name: protected: class IVP_Compact_Ledgetree_Node __near * IVP_SurfaceBuilder_Ledge_Soup::build_ledgetree(class IVV_Sphere __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledgetree_Node *__thiscall IVP_SurfaceBuilder_Ledge_Soup::build_ledgetree(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVV_Sphere *node)
{
  IVP_Compact_Ledgetree_Node *ledgetree_work; // esi

  ledgetree_work = this->ledgetree_work;
  ledgetree_work->center.k[0] = node->center.k[0];
  this->ledgetree_work = ledgetree_work + 1;
  ledgetree_work->center.k[1] = node->center.k[1];
  ledgetree_work->center.k[2] = node->center.k[2];
  ledgetree_work->radius = node->radius;
  ledgetree_work->box_sizes[0] = node->box_sizes[0];
  ledgetree_work->box_sizes[1] = node->box_sizes[1];
  ledgetree_work->box_sizes[2] = node->box_sizes[2];
  ledgetree_work->nLedgeIndex = 0;
  if ( node->child_1 != nullptr )
  {
    if ( node->compact_ledge != nullptr )
    {
      ledgetree_work->offset_compact_ledge = (char *)node->compact_ledge - (char *)ledgetree_work;
      node->compact_ledge->ledgetree_node_offset = (char *)ledgetree_work - (char *)node->compact_ledge;
      *((_DWORD *)node->compact_ledge + 2) = *((_DWORD *)node->compact_ledge + 2) & 0xFFFFFFFC | 1;
    }
    else
    {
      ledgetree_work->offset_compact_ledge = 0;
    }
    IVP_SurfaceBuilder_Ledge_Soup::build_ledgetree(this, node: node->child_1);
    ledgetree_work->offset_right_node = (char *)IVP_SurfaceBuilder_Ledge_Soup::build_ledgetree(
                                                  this,
                                                  node: node->child_2)
                                      - (char *)ledgetree_work;
    return ledgetree_work;
  }
  else
  {
    *((_DWORD *)node->compact_ledge + 2) &= 0xFFFFFFFC;
    ledgetree_work->offset_compact_ledge = (char *)node->compact_ledge - (char *)ledgetree_work;
    ledgetree_work->offset_right_node = 0;
    return ledgetree_work;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047240
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::insert_radius_in_compact_surface(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_SurfaceBuilder_Ledge_Soup::insert_radius_in_compact_surface(
        IVP_SurfaceBuilder_Ledge_Soup *this@<ecx>,
        float a2@<ebp>,
        IVP_BOOL bUseFastInertiaTensor)
{
  IVP_Compact_Surface *v4; // eax
  IVP_Compact_Surface *compact_surface; // [esp-28h] [ebp-58h]
  _DWORD v6[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point rotation_inertia; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Point mass_center; // [esp+10h] [ebp-20h] BYREF
  float v9[2]; // [esp+20h] [ebp-10h] BYREF
  float mass_radius_dev; // [esp+28h] [ebp-8h]
  float retaddr; // [esp+30h] [ebp+0h]

  v9[1] = a2;
  mass_radius_dev = retaddr;
  compact_surface = this->compact_surface;
  if ( bUseFastInertiaTensor == IVP_TRUE )
    IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia_fast(
      c_surface_in: compact_surface,
      mass_center_out: (IVP_U_Point *)&rotation_inertia.k[1],
      rotation_inertia_out: (IVP_U_Point *)v6);
  else
    IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia(
      c_surface_in: compact_surface,
      mass_center_out: (IVP_U_Point *)&rotation_inertia.k[1],
      rotation_inertia_out: (IVP_U_Point *)v6);
  IVP_Compact_Ledge_Solver::calc_radius_to_given_center(
    c_surface_in: this->compact_surface,
    center_in: (IVP_U_Point *)&rotation_inertia.k[1],
    radius_out: v9,
    radius_dev_out: &mass_center.hesse_val);
  v4 = this->compact_surface;
  LODWORD(v4->rotation_inertia.k[0]) = v6[0];
  LODWORD(v4->rotation_inertia.k[1]) = v6[1];
  LODWORD(v4->rotation_inertia.k[2]) = v6[2];
  v4->mass_center.k[0] = rotation_inertia.k[1];
  v4->mass_center.k[1] = rotation_inertia.k[2];
  v4->mass_center.k[2] = rotation_inertia.hesse_val;
  v4->upper_limit_radius = v9[0];
  *((_BYTE *)this->compact_surface + 28) = (int)(float)((float)(mass_center.hesse_val / (float)(v9[0] * 0.0040000002))
                                                      + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10047310
// Name: protected: enum IVP_RETURN_TYPE IVP_SurfaceBuilder_Ledge_Soup::create_compact_ledgetree(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_SurfaceBuilder_Ledge_Soup::create_compact_ledgetree(IVP_SurfaceBuilder_Ledge_Soup *this)
{
  IVP_SurfaceBuilder_Ledge_Soup::build_ledgetree(this, node: this->spheres_cluster[this->spheres_cluster->next].sphere);
  this->spheres_cluster->next = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047380
// Name: public: IVP_SurfaceBuilder_Ledge_Soup::IVP_SurfaceBuilder_Ledge_Soup(void)
// Source: json
//------------------------------------------------------------------------------
IVP_SurfaceBuilder_Ledge_Soup *__thiscall IVP_SurfaceBuilder_Ledge_Soup::IVP_SurfaceBuilder_Ledge_Soup(
        IVP_SurfaceBuilder_Ledge_Soup *this)
{
  this->c_ledge_vec.elems = nullptr;
  *(_DWORD *)&this->c_ledge_vec.memsize = 0;
  this->rec_spheres.elems = nullptr;
  *(_DWORD *)&this->rec_spheres.memsize = 0;
  this->terminal_spheres.elems = nullptr;
  *(_DWORD *)&this->terminal_spheres.memsize = 0;
  *(_DWORD *)&this->overlapping_spheres.memsize = 0;
  this->overlapping_spheres.elems = nullptr;
  *(_DWORD *)&this->built_spheres.memsize = 0;
  this->built_spheres.elems = nullptr;
  *(_DWORD *)&this->all_spheres.memsize = 0;
  this->all_spheres.elems = nullptr;
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_SurfaceBuilder_Ledge_Soup));
  this->smallest_radius = 0.0;
  this->compact_surface = nullptr;
  this->extents_min.k[0] = 1000000.0;
  this->extents_min.k[1] = 1000000.0;
  this->extents_min.k[2] = 1000000.0;
  this->extents_max.k[0] = -1000000.0;
  this->extents_max.k[1] = -1000000.0;
  this->extents_max.k[2] = -1000000.0;
  this->interval_minhash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047410
// Name: public: IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::~IVP_SurfaceBuilder_Ledge_Soup(IVP_SurfaceBuilder_Ledge_Soup *this)
{
  IVP_SurfaceBuilder_Ledge_Soup *elems; // eax
  IVP_SurfaceBuilder_Ledge_Soup *v3; // eax
  IVP_SurfaceBuilder_Ledge_Soup *v4; // eax
  IVP_SurfaceBuilder_Ledge_Soup *v5; // eax
  IVP_SurfaceBuilder_Ledge_Soup *v6; // eax
  IVP_SurfaceBuilder_Ledge_Soup *v7; // eax

  elems = (IVP_SurfaceBuilder_Ledge_Soup *)this->all_spheres.elems;
  if ( elems != (IVP_SurfaceBuilder_Ledge_Soup *)(&this->all_spheres + 1) )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->all_spheres.elems = nullptr;
    this->all_spheres.memsize = 0;
  }
  this->all_spheres.n_elems = 0;
  v3 = (IVP_SurfaceBuilder_Ledge_Soup *)this->built_spheres.elems;
  if ( v3 != (IVP_SurfaceBuilder_Ledge_Soup *)&this->parameters )
  {
    if ( v3 != nullptr )
      free(data: this->built_spheres.elems);
    this->built_spheres.elems = nullptr;
    this->built_spheres.memsize = 0;
  }
  this->built_spheres.n_elems = 0;
  v4 = (IVP_SurfaceBuilder_Ledge_Soup *)this->overlapping_spheres.elems;
  if ( v4 != (IVP_SurfaceBuilder_Ledge_Soup *)&this->built_spheres )
  {
    if ( v4 != nullptr )
      free(data: this->overlapping_spheres.elems);
    this->overlapping_spheres.elems = nullptr;
    this->overlapping_spheres.memsize = 0;
  }
  this->overlapping_spheres.n_elems = 0;
  v5 = (IVP_SurfaceBuilder_Ledge_Soup *)this->terminal_spheres.elems;
  if ( v5 != (IVP_SurfaceBuilder_Ledge_Soup *)&this->extents_min )
  {
    if ( v5 != nullptr )
      free(data: this->terminal_spheres.elems);
    this->terminal_spheres.elems = nullptr;
    this->terminal_spheres.memsize = 0;
  }
  this->terminal_spheres.n_elems = 0;
  v6 = (IVP_SurfaceBuilder_Ledge_Soup *)this->rec_spheres.elems;
  if ( v6 != (IVP_SurfaceBuilder_Ledge_Soup *)&this->terminal_spheres )
  {
    if ( v6 != nullptr )
      free(data: this->rec_spheres.elems);
    this->rec_spheres.elems = nullptr;
    this->rec_spheres.memsize = 0;
  }
  this->rec_spheres.n_elems = 0;
  v7 = (IVP_SurfaceBuilder_Ledge_Soup *)this->c_ledge_vec.elems;
  if ( v7 == (IVP_SurfaceBuilder_Ledge_Soup *)&this->rec_spheres )
  {
    this->c_ledge_vec.n_elems = 0;
  }
  else
  {
    if ( v7 != nullptr )
      free(data: this->c_ledge_vec.elems);
    this->c_ledge_vec.elems = nullptr;
    *(_DWORD *)&this->c_ledge_vec.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047510
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::cleanup(IVP_SurfaceBuilder_Ledge_Soup *this)
{
  IVP_SurfaceBuilder_Ledge_Soup *elems; // eax
  int v3; // edi
  IVP_SurfaceBuilder_Ledge_Soup *v4; // eax

  elems = (IVP_SurfaceBuilder_Ledge_Soup *)this->terminal_spheres.elems;
  if ( elems != (IVP_SurfaceBuilder_Ledge_Soup *)&this->extents_min )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->terminal_spheres.elems = nullptr;
    this->terminal_spheres.memsize = 0;
  }
  this->terminal_spheres.n_elems = 0;
  v3 = 0;
  if ( this->all_spheres.n_elems != 0 )
  {
    do
      free(data: this->all_spheres.elems[v3++]);
    while ( v3 < this->all_spheres.n_elems );
  }
  v4 = (IVP_SurfaceBuilder_Ledge_Soup *)this->all_spheres.elems;
  if ( v4 != (IVP_SurfaceBuilder_Ledge_Soup *)(&this->all_spheres + 1) )
  {
    if ( v4 != nullptr )
      free(data: v4);
    this->all_spheres.elems = nullptr;
    this->all_spheres.memsize = 0;
  }
  this->all_spheres.n_elems = 0;
  if ( this->spheres_cluster != nullptr )
  {
    free(data: this->spheres_cluster);
    this->spheres_cluster = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100475D0
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::calculate_boundingbox(class IVP_U_Vector<class IVV_Sphere> __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::calculate_boundingbox(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVP_U_Vector<IVV_Sphere> *terminals,
        IVP_U_Float_Point *ext_min,
        IVP_U_Float_Point *ext_max)
{
  int v4; // edx
  float *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float min_4; // [esp+4h] [ebp-8h]

  ext_min->k[0] = 1000000.0;
  ext_min->k[1] = 1000000.0;
  ext_min->k[2] = 1000000.0;
  ext_max->k[0] = -1000000.0;
  ext_max->k[1] = -1000000.0;
  ext_max->k[2] = -1000000.0;
  v4 = 0;
  if ( terminals->n_elems != 0 )
  {
    do
    {
      v5 = (float *)terminals->elems[v4];
      v6 = v5[8] * dimension_steps;
      v7 = v5[4];
      v8 = (float)*((unsigned __int8 *)v5 + 37) * v6;
      v9 = (float)*((unsigned __int8 *)v5 + 36) * v6;
      min_4 = v5[5] - v8;
      v10 = v7 - v9;
      v11 = (float)*((unsigned __int8 *)v5 + 38) * v6;
      v12 = v7 + v9;
      v13 = v5[6] - v11;
      v14 = v5[5] + v8;
      v15 = v5[6] + v11;
      if ( ext_min->k[0] > v10 )
        ext_min->k[0] = v10;
      if ( v12 > ext_max->k[0] )
        ext_max->k[0] = v12;
      if ( ext_min->k[1] > min_4 )
        ext_min->k[1] = min_4;
      if ( v14 > ext_max->k[1] )
        ext_max->k[1] = v14;
      if ( ext_min->k[2] > v13 )
        ext_min->k[2] = v13;
      if ( v15 > ext_max->k[2] )
        ext_max->k[2] = v15;
      ++v4;
    }
    while ( v4 < terminals->n_elems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047700
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::insert_compact_ledges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::insert_compact_ledges(IVP_SurfaceBuilder_Ledge_Soup *this)
{
  char *first_compact_ledge; // edi
  void *v3; // eax
  IVP_Compact_Ledge *v4; // ebx
  void *v5; // eax
  IVP_Compact_Ledge *v6; // ebx
  IVP_SurfaceBuilder_Ledge_Soup *elems; // eax
  int j; // [esp+Ch] [ebp-4h]
  int ja; // [esp+Ch] [ebp-4h]

  first_compact_ledge = (char *)this->first_compact_ledge;
  if ( this->parameters->link_to_input_compact_ledges == IVP_FALSE )
  {
    j = 0;
    if ( this->terminal_spheres.n_elems != 0 )
    {
      do
      {
        v3 = this->terminal_spheres.elems[j];
        v4 = *((IVP_Compact_Ledge **)v3 + 10);
        *((_DWORD *)v3 + 10) = first_compact_ledge;
        first_compact_ledge += IVP_SurfaceBuilder_Ledge_Soup::recompile_point_indizes_of_compact_ledge(
                                 this,
                                 ledge_source: v4,
                                 dest: first_compact_ledge);
        if ( this->parameters->free_input_compact_ledges == IVP_TRUE && v4 != nullptr )
          ivp_free_aligned(data: (void *)v4);
        ++j;
      }
      while ( j < this->terminal_spheres.n_elems );
    }
  }
  ja = 0;
  if ( this->rec_spheres.n_elems != 0 )
  {
    do
    {
      v5 = this->rec_spheres.elems[ja];
      v6 = *((IVP_Compact_Ledge **)v5 + 10);
      *((_DWORD *)v5 + 10) = first_compact_ledge;
      first_compact_ledge += IVP_SurfaceBuilder_Ledge_Soup::recompile_point_indizes_of_compact_ledge(
                               this,
                               ledge_source: v6,
                               dest: first_compact_ledge);
      if ( v6 != nullptr )
        ivp_free_aligned(data: (void *)v6);
      ++ja;
    }
    while ( ja < this->rec_spheres.n_elems );
  }
  elems = (IVP_SurfaceBuilder_Ledge_Soup *)this->c_ledge_vec.elems;
  if ( elems == (IVP_SurfaceBuilder_Ledge_Soup *)&this->rec_spheres )
  {
    this->c_ledge_vec.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: elems);
    this->c_ledge_vec.elems = nullptr;
    *(_DWORD *)&this->c_ledge_vec.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100477E0
// Name: public: void IVP_SurfaceBuilder_Ledge_Soup::insert_ledge(class IVP_Compact_Ledge __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::insert_ledge(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVP_Compact_Ledge *c_ledge)
{
  IVP_U_Vector<IVP_Compact_Ledge> *p_c_ledge_vec; // esi

  if ( c_ledge != nullptr )
  {
    p_c_ledge_vec = &this->c_ledge_vec;
    if ( this->c_ledge_vec.n_elems >= this->c_ledge_vec.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->c_ledge_vec);
    p_c_ledge_vec->elems[p_c_ledge_vec->n_elems++] = (void *)c_ledge;
  }
  else if ( IVP_BetterDebugmanager::is_debug_enabled(this: &ivp_debugmanager, class_id: IVP_DM_SURBUILD_LEDGESOUP) != IVP_FALSE )
  {
    IVP_BetterDebugmanager::dprint(
      this: &ivp_debugmanager,
      class_id: IVP_DM_SURBUILD_LEDGESOUP,
      formatstring: "warning: tried to add NULL ledge in IVP_SurfaceBuilder_Ledge_Soup::insert_ledge()\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047840
// Name: protected: class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Ledge_Soup::build_root_convex_hull(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__thiscall IVP_SurfaceBuilder_Ledge_Soup::build_root_convex_hull(
        IVP_SurfaceBuilder_Ledge_Soup *this)
{
  IVV_Sphere *sphere; // esi
  IVP_Template_Surbuild_LedgeSoup *parameters; // eax
  IVP_Compact_Ledge *hull; // ebx
  IVP_Compact_Recursive cr; // [esp+Ch] [ebp-10h] BYREF

  sphere = this->spheres_cluster[this->spheres_cluster->next].sphere;
  IVP_Compact_Recursive::IVP_Compact_Recursive(this: &cr);
  IVP_SurfaceBuilder_Ledge_Soup::add_ledge_tree_to_convex_hull(this, &cr, node: sphere);
  parameters = this->parameters;
  if ( parameters->force_convex_hull != nullptr )
  {
    cr.hull = parameters->force_convex_hull;
    IVP_Compact_Recursive::set_rekursive_convex_hull(this: &cr);
    hull = cr.hull;
  }
  else
  {
    hull = IVP_Compact_Recursive::compile(this: &cr);
  }
  if ( hull != nullptr )
  {
    if ( this->c_ledge_vec.n_elems >= this->c_ledge_vec.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->c_ledge_vec);
    this->c_ledge_vec.elems[this->c_ledge_vec.n_elems++] = (void *)hull;
    sphere->compact_ledge = hull;
    if ( this->rec_spheres.n_elems >= this->rec_spheres.memsize )
      IVP_U_Vector_Base::increment_mem(this: &this->rec_spheres);
    this->rec_spheres.elems[this->rec_spheres.n_elems++] = sphere;
  }
  IVP_Friction_Core_Pair::~IVP_Friction_Core_Pair(this: (IVP_Friction_Core_Pair *)&cr);
  return hull;
}

//------------------------------------------------------------------------------
// Address: 0x100478F0
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::ledges_to_boxes_and_spheres(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_SurfaceBuilder_Ledge_Soup::ledges_to_boxes_and_spheres(
        IVP_SurfaceBuilder_Ledge_Soup *this@<ecx>,
        IVP_Compact_Ledge *a2@<ebp>)
{
  int n_elems; // esi
  IVV_Sphere_Cluster *v4; // eax
  unsigned __int8 *v5; // eax
  IVV_Sphere *v6; // esi
  const IVP_Compact_Ledge *v7; // edx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  IVP_Compact_Ledge *v18; // eax
  int v19; // edx
  float smallest_radius; // xmm0_4
  float radius; // xmm1_4
  int v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  _BYTE v26[12]; // [esp+14h] [ebp-5Ch] BYREF
  IVP_U_Point min; // [esp+20h] [ebp-50h] BYREF
  IVP_U_Point rad; // [esp+30h] [ebp-40h] BYREF
  int v29; // [esp+50h] [ebp-20h]
  float v30; // [esp+54h] [ebp-1Ch]
  const IVP_Compact_Ledge *v31; // [esp+58h] [ebp-18h]
  int n_ledges; // [esp+5Ch] [ebp-14h]
  int v33; // [esp+60h] [ebp-10h]
  IVP_Compact_Ledge *compact_ledge; // [esp+64h] [ebp-Ch]
  int ledge_cnt; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  compact_ledge = a2;
  ledge_cnt = retaddr;
  n_elems = this->c_ledge_vec.n_elems;
  this->size_of_tree_in_bytes = 0;
  v29 = n_elems;
  this->number_of_terminal_spheres = n_elems;
  v4 = (IVV_Sphere_Cluster *)_calloc_crt(nelem: n_elems + 1, size: 8);
  this->spheres_cluster = v4;
  v4->next = 1;
  v33 = 1;
  n_ledges = 0;
  if ( n_elems > 0 )
  {
    do
    {
      v31 = (const IVP_Compact_Ledge *)this->c_ledge_vec.elems[n_ledges];
      v5 = (unsigned __int8 *)p_malloc(size: 0x40u);
      v6 = (IVV_Sphere *)v5;
      if ( v5 != nullptr )
        memset(dst: v5, value: 0, count: 0x40u);
      else
        v6 = nullptr;
      if ( this->all_spheres.n_elems >= this->all_spheres.memsize )
        IVP_U_Vector_Base::increment_mem(this: &this->all_spheres);
      this->all_spheres.elems[this->all_spheres.n_elems] = v6;
      v7 = v31;
      ++this->all_spheres.n_elems;
      IVP_Compact_Ledge_Solver::calc_bounding_box(
        c_ledge_in: v7,
        min_extents_out: (IVP_U_Point *)v26,
        max_extents_out: (IVP_U_Point *)&rad.k[1]);
      IVP_U_Float_Point::set_interpolate(
        this: &v6->center,
        p0: (IVP_U_Point *)&rad.k[1],
        p1: (const IVP_U_Float_Point *)v26,
        s: 0.5);
      v8 = rad.k[2] - v6->center.k[1];
      v9 = rad.hesse_val - v6->center.k[2];
      min.k[1] = rad.k[1] - v6->center.k[0];
      min.k[2] = v8;
      min.hesse_val = v9;
      v30 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Point *)&min.k[1]);
      v10 = v6->center.k[0];
      v6->radius = v30;
      v11 = v10 - v30;
      if ( this->extents_min.k[0] > v11 )
        this->extents_min.k[0] = v11;
      v12 = v6->radius + v6->center.k[0];
      if ( v12 > this->extents_max.k[0] )
        this->extents_max.k[0] = v12;
      v13 = v6->center.k[1] - v6->radius;
      if ( this->extents_min.k[1] > v13 )
        this->extents_min.k[1] = v13;
      v14 = v6->radius + v6->center.k[1];
      if ( v14 > this->extents_max.k[1] )
        this->extents_max.k[1] = v14;
      v15 = v6->center.k[2] - v6->radius;
      if ( this->extents_min.k[2] > v15 )
        this->extents_min.k[2] = v15;
      v16 = v6->radius + v6->center.k[2];
      if ( v16 > this->extents_max.k[2] )
        this->extents_max.k[2] = v16;
      v17 = 1.0 / (float)(v6->radius * 0.0040000002);
      v6->box_sizes[0] = (int)(float)((float)(rad.k[1] - v6->center.k[0]) * v17) + 1;
      v18 = v31;
      v6->box_sizes[1] = (int)(float)((float)(rad.k[2] - v6->center.k[1]) * v17) + 1;
      v6->box_sizes[2] = (int)(float)((float)(rad.hesse_val - v6->center.k[2]) * v17) + 1;
      this->size_of_tree_in_bytes += 64;
      v19 = v33;
      v6->compact_ledge = v18;
      v6->child_1 = nullptr;
      v6->child_2 = nullptr;
      v6->number = v19;
      this->spheres_cluster[v19].previous = v19 - 1;
      this->spheres_cluster[v19].next = v19 + 1;
      this->spheres_cluster[v19].sphere = v6;
      smallest_radius = this->smallest_radius;
      if ( smallest_radius == 0.0 )
      {
        this->smallest_radius = v6->radius;
      }
      else
      {
        radius = v6->radius;
        if ( smallest_radius > radius )
          this->smallest_radius = radius;
      }
      if ( this->terminal_spheres.n_elems >= this->terminal_spheres.memsize )
      {
        IVP_U_Vector_Base::increment_mem(this: &this->terminal_spheres);
        v19 = v33;
      }
      this->terminal_spheres.elems[this->terminal_spheres.n_elems] = v6;
      v22 = n_ledges;
      ++this->terminal_spheres.n_elems;
      v33 = v19 + 1;
      n_ledges = v22 + 1;
    }
    while ( v22 + 1 < v29 );
  }
  this->spheres_cluster[v33 - 1].next = 0;
  if ( n_ledges > 1 )
  {
    v23 = this->extents_max.k[0] - this->extents_min.k[0];
    v24 = this->extents_max.k[1] - this->extents_min.k[1];
    v25 = this->extents_max.k[2] - this->extents_min.k[2];
    if ( v24 > v23 )
    {
      if ( v25 <= v24 )
      {
        this->longest_axis = 1;
        return;
      }
      goto LABEL_31;
    }
    if ( v25 > v23 )
    {
LABEL_31:
      this->longest_axis = 2;
      return;
    }
    this->longest_axis = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047C00
// Name: protected: class IVV_Sphere __near * IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(class IVP_U_Vector<class IVV_Sphere> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVV_Sphere *__userpurge IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively@<eax>(
        IVP_SurfaceBuilder_Ledge_Soup *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Vector<IVV_Sphere> *terminals)
{
  bool v4; // zf
  double v6; // st7
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  unsigned __int16 n_elems; // cx
  int v10; // xmm0_4
  float v11; // xmm0_4
  void **elems; // ecx
  void **v13; // ecx
  int *v14; // eax
  IVP_U_Vector<IVV_Sphere> *v15; // eax
  IVP_U_Vector<IVV_Sphere> *v16; // eax
  IVP_U_Vector<IVV_Sphere> *v17; // eax
  IVP_U_Vector<IVV_Sphere> *v18; // eax
  IVP_U_Vector<IVV_Sphere> *v19; // eax
  IVP_U_Vector<IVV_Sphere> *v20; // eax
  IVP_U_Vector<IVV_Sphere> *v21; // eax
  int v22; // edx
  float v23; // xmm0_4
  int v24; // edi
  void **v25; // eax
  unsigned int v26; // esi
  int v27; // ecx
  void **v28; // eax
  int v29; // esi
  float v30; // xmm0_4
  float v31; // xmm2_4
  void **v32; // eax
  IVP_U_Vector<IVV_Sphere> *v33; // edi
  void **v34; // eax
  float v35; // xmm1_4
  IVP_U_Vector_Base *v36; // esi
  float v37; // xmm0_4
  char *v38; // eax
  float v39; // xmm1_4
  IVP_U_Vector_Base *v40; // esi
  int v41; // edi
  int v42; // esi
  IVP_SurfaceBuilder_Ledge_Soup *v43; // edi
  float hesse_val; // xmm0_4
  IVV_Sphere *v45; // edi
  int v46; // esi
  IVV_Sphere *v47; // eax
  IVP_U_Vector<IVV_Sphere> *v48; // edx
  IVV_Sphere *v49; // eax
  int *v50; // eax
  IVP_U_Vector<IVV_Sphere> *v51; // edi
  void **v52; // eax
  _DWORD *v53; // edi
  void *v54; // eax
  IVP_U_Vector<IVV_Sphere> *v55; // edi
  IVP_U_Vector<IVV_Sphere> *v56; // eax
  IVP_U_Vector<IVV_Sphere> *v57; // edi
  IVP_U_Vector<IVV_Sphere> *v58; // eax
  IVP_U_Vector<IVV_Sphere> *v59; // edi
  IVP_U_Vector<IVV_Sphere> *v60; // eax
  float v61[3]; // [esp+14h] [ebp-CCh] BYREF
  IVP_U_Float_Point min[2]; // [esp+20h] [ebp-C0h] BYREF
  IVP_U_Float_Point max[2]; // [esp+40h] [ebp-A0h] BYREF
  IVP_U_Point rad; // [esp+60h] [ebp-80h]
  float v65; // [esp+70h] [ebp-70h]
  float v66; // [esp+74h] [ebp-6Ch]
  float difference_in_boundingbox_volumes[3]; // [esp+78h] [ebp-68h]
  __int64 median; // [esp+84h] [ebp-5Ch] OVERLAPPED BYREF
  _BYTE v69[20]; // [esp+8Ch] [ebp-54h] OVERLAPPED BYREF
  IVV_Sphere *new_sphere; // [esp+A0h] [ebp-40h]
  IVP_U_Vector<IVV_Sphere> *v71; // [esp+A4h] [ebp-3Ch]
  int x; // [esp+A8h] [ebp-38h]
  IVP_U_Vector<IVV_Sphere> *lefthand_terminals[3]; // [esp+ACh] [ebp-34h]
  IVP_U_Vector<IVV_Sphere> *righthand_terminals[3]; // [esp+B8h] [ebp-28h] BYREF
  IVV_Sphere *terminal_sphere; // [esp+C4h] [ebp-1Ch] BYREF
  float *p_hesse_val; // [esp+C8h] [ebp-18h]
  int v77; // [esp+CCh] [ebp-14h] BYREF
  int v78; // [esp+D0h] [ebp-10h]
  int v79; // [esp+D4h] [ebp-Ch]
  int median_average; // [esp+D8h] [ebp-8h]
  int retaddr; // [esp+E0h] [ebp+0h]

  v79 = a2;
  median_average = retaddr;
  v4 = terminals->n_elems == 1;
  *(_DWORD *)&v69[12] = this;
  if ( v4 )
    return (IVV_Sphere *)*terminals->elems;
  IVP_SurfaceBuilder_Ledge_Soup::calculate_boundingbox(
    this,
    terminals,
    ext_min: &this->extents_min,
    ext_max: &this->extents_max);
  IVP_U_Float_Point::set_interpolate(
    this: (IVP_U_Float_Point *)&median,
    p0: &this->extents_max,
    p1: &this->extents_min,
    s: 0.5);
  max[1].k[1] = this->extents_max.k[0] - *(float *)&median;
  max[1].k[2] = this->extents_max.k[1] - *((float *)&median + 1);
  max[1].hesse_val = this->extents_max.k[2] - *(float *)v69;
  v6 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&max[1].k[1]);
  *(float *)&v77 = v6;
  *(float *)righthand_terminals = v6 * dimension_steps_0;
  v7 = (unsigned __int8 *)p_malloc(size: 0x40u);
  v8 = v7;
  if ( v7 != nullptr )
    memset(dst: v7, value: 0, count: 0x40u);
  else
    v8 = nullptr;
  n_elems = this->all_spheres.n_elems;
  *(_DWORD *)&v69[8] = v8;
  if ( n_elems >= this->all_spheres.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->all_spheres);
  v10 = v77;
  this->all_spheres.elems[this->all_spheres.n_elems++] = v8;
  *((_DWORD *)v8 + 8) = v10;
  *(_DWORD *)v8 = 0;
  *((_QWORD *)v8 + 2) = median;
  *((_QWORD *)v8 + 3) = *(_QWORD *)v69;
  v11 = 1.0 / *(float *)righthand_terminals;
  *((_DWORD *)v8 + 10) = 0;
  v8[36] = (int)(float)((float)(this->extents_max.k[0] - *(float *)&median) * v11) + 1;
  v8[37] = (int)(float)((float)(this->extents_max.k[1] - *((float *)&median + 1)) * v11) + 1;
  v8[38] = (int)(float)((float)(this->extents_max.k[2] - *(float *)v69) * v11) + 1;
  if ( terminals->n_elems == 2 )
  {
    righthand_terminals[2] = nullptr;
    p_hesse_val = nullptr;
    terminal_sphere = nullptr;
    elems = terminals->elems;
    righthand_terminals[1] = nullptr;
    v77 = *(int *)elems;
    IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&righthand_terminals[1]);
    *((float *)&righthand_terminals[2]->memsize + HIWORD(righthand_terminals[1])) = *(float *)&v77;
    v13 = terminals->elems;
    ++HIWORD(righthand_terminals[1]);
    v77 = *((int *)v13 + 1);
    if ( HIWORD(terminal_sphere) >= (unsigned __int16)terminal_sphere )
      IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&terminal_sphere);
    p_hesse_val[HIWORD(terminal_sphere)] = *(float *)&v77;
    ++HIWORD(terminal_sphere);
    *((_DWORD *)v8 + 11) = IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(
                             this,
                             terminals: (IVP_U_Vector<IVV_Sphere> *)&righthand_terminals[1]);
    *((_DWORD *)v8 + 12) = IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(
                             this,
                             terminals: (IVP_U_Vector<IVV_Sphere> *)&terminal_sphere);
    v14 = (int *)p_hesse_val;
    ++this->number_of_nodes;
    if ( v14 != &v77 )
    {
      if ( v14 != nullptr )
        free(data: v14);
      p_hesse_val = nullptr;
      LOWORD(terminal_sphere) = 0;
    }
    HIWORD(terminal_sphere) = 0;
    if ( (IVV_Sphere **)righthand_terminals[2] != &terminal_sphere && righthand_terminals[2] != nullptr )
      free(data: righthand_terminals[2]);
    return (IVV_Sphere *)v8;
  }
  v15 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v15 != nullptr )
    new_sphere = (IVV_Sphere *)IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v15, size: terminals->n_elems);
  else
    new_sphere = nullptr;
  v16 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v16 != nullptr )
    v71 = IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v16, size: terminals->n_elems);
  else
    v71 = nullptr;
  v17 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v17 != nullptr )
    x = (int)IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v17, size: terminals->n_elems);
  else
    x = 0;
  v18 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v18 != nullptr )
    lefthand_terminals[0] = IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v18, size: terminals->n_elems);
  else
    lefthand_terminals[0] = nullptr;
  v19 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v19 != nullptr )
    lefthand_terminals[1] = IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v19, size: terminals->n_elems);
  else
    lefthand_terminals[1] = nullptr;
  v20 = (IVP_U_Vector<IVV_Sphere> *)p_malloc(size: 8u);
  if ( v20 != nullptr )
    lefthand_terminals[2] = IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(this: v20, size: terminals->n_elems);
  else
    lefthand_terminals[2] = nullptr;
  LODWORD(difference_in_boundingbox_volumes[2]) = &v69[4];
  righthand_terminals[2] = (IVP_U_Vector<IVV_Sphere> *)&v69[16];
  v78 = 16;
  p_hesse_val = &max[1].hesse_val;
  do
  {
    v21 = terminals;
    v22 = terminals->n_elems;
    v23 = 0.0;
    v24 = 0;
    if ( (unsigned int)v22 < 4 )
    {
      v27 = v78;
    }
    else
    {
      v25 = terminals->elems + 2;
      v26 = ((unsigned int)(v22 - 4) >> 2) + 1;
      v77 = 4 * v26;
      v27 = v78;
      do
      {
        v23 = (float)((float)((float)(v23 + *(float *)((char *)*(v25 - 2) + v78)) + *(float *)((char *)*(v25 - 1) + v78))
                    + *(float *)((char *)*v25 + v78))
            + *(float *)((char *)v25[1] + v78);
        v25 += 4;
        --v26;
      }
      while ( v26 != 0 );
      v21 = terminals;
      v24 = v77;
    }
    if ( v24 < v22 )
    {
      v28 = &v21->elems[v24];
      v29 = v22 - v24;
      do
      {
        v23 = v23 + *(float *)((char *)*v28++ + v27);
        --v29;
      }
      while ( v29 != 0 );
    }
    v30 = v23 / (float)v22;
    difference_in_boundingbox_volumes[0] = v30;
    v77 = 1;
    *(_DWORD *)&v69[16] = 0;
    if ( v22 > 0 )
    {
      v31 = v30 - 0.000001;
      for ( difference_in_boundingbox_volumes[1] = v30 - 0.000001; ; v31 = difference_in_boundingbox_volumes[1] )
      {
        v32 = terminals->elems;
        v33 = (IVP_U_Vector<IVV_Sphere> *)v32[*(_DWORD *)&v69[16]];
        v34 = &v32[*(_DWORD *)&v69[16]];
        v35 = *(float *)((char *)&v33->memsize + v78);
        righthand_terminals[0] = v33;
        if ( v31 > v35 )
        {
          v36 = *(IVP_U_Vector_Base **)&v69[v78 + 4];
          if ( v36->n_elems >= v36->memsize )
          {
            IVP_U_Vector_Base::increment_mem(this: v36);
            v36->elems[v36->n_elems++] = v33;
            goto LABEL_80;
          }
          goto LABEL_55;
        }
        v37 = v30 + 0.000001;
        if ( v35 > v37 )
        {
          v36 = *(IVP_U_Vector_Base **)&v69[v78 + 16];
          if ( v36->n_elems >= v36->memsize )
            IVP_U_Vector_Base::increment_mem(this: *(IVP_U_Vector_Base **)&v69[v78 + 16]);
LABEL_55:
          v36->elems[v36->n_elems++] = v33;
          goto LABEL_80;
        }
        if ( *(_DWORD *)&v69[16] == v22 - 1 )
          v38 = (char *)*(v34 - 1);
        else
          v38 = (char *)v34[1];
        v39 = *(float *)&v38[v78];
        if ( v31 > v39 )
        {
          v40 = *(IVP_U_Vector_Base **)&v69[v78 + 16];
          if ( v40->n_elems >= v40->memsize )
            IVP_U_Vector_Base::increment_mem(this: *(IVP_U_Vector_Base **)&v69[v78 + 16]);
LABEL_62:
          v40->elems[v40->n_elems++] = v33;
          goto LABEL_80;
        }
        v40 = *(IVP_U_Vector_Base **)&v69[v78 + 4];
        if ( v39 > v37 )
        {
          if ( v40->n_elems < v40->memsize )
            goto LABEL_62;
LABEL_65:
          IVP_U_Vector_Base::increment_mem(this: *(IVP_U_Vector_Base **)&v69[v78 + 4]);
          v40->elems[v40->n_elems++] = v33;
          goto LABEL_80;
        }
        if ( v40->n_elems == 0 )
        {
          if ( v40->n_elems < v40->memsize )
            goto LABEL_62;
          goto LABEL_65;
        }
        v41 = *(_DWORD *)&v69[v78 + 16];
        if ( *(_WORD *)(v41 + 2) == 0 )
          break;
        if ( *(float *)&v77 == 0.0 )
        {
          if ( *(_WORD *)(v41 + 2) >= *(_WORD *)v41 )
            IVP_U_Vector_Base::increment_mem(this: *(IVP_U_Vector_Base **)&v69[v78 + 16]);
          v77 = 1;
          goto LABEL_79;
        }
        if ( v40->n_elems >= v40->memsize )
          IVP_U_Vector_Base::increment_mem(this: v40);
        v40->elems[v40->n_elems++] = righthand_terminals[0];
        *(float *)&v77 = 0.0;
LABEL_80:
        v22 = terminals->n_elems;
        ++*(_DWORD *)&v69[16];
        if ( *(int *)&v69[16] >= v22 )
          goto LABEL_81;
        v30 = difference_in_boundingbox_volumes[0];
      }
      if ( *(_WORD *)(v41 + 2) >= *(_WORD *)v41 )
        IVP_U_Vector_Base::increment_mem(this: *(IVP_U_Vector_Base **)&v69[v78 + 16]);
LABEL_79:
      *(IVP_U_Vector<IVV_Sphere> **)(*(_DWORD *)(v41 + 4) + 4 * (unsigned __int16)(*(_WORD *)(v41 + 2))++) = righthand_terminals[0];
      goto LABEL_80;
    }
LABEL_81:
    v42 = v78;
    v43 = *(IVP_SurfaceBuilder_Ledge_Soup **)&v69[12];
    IVP_SurfaceBuilder_Ledge_Soup::calculate_boundingbox(
      this: *(IVP_SurfaceBuilder_Ledge_Soup **)&v69[12],
      terminals: *(IVP_U_Vector<IVV_Sphere> **)(LODWORD(difference_in_boundingbox_volumes[2]) + v78),
      ext_min: (IVP_U_Float_Point *)v61,
      ext_max: (IVP_U_Float_Point *)&min[1].k[1]);
    IVP_SurfaceBuilder_Ledge_Soup::calculate_boundingbox(
      this: v43,
      terminals: *(IVP_U_Vector<IVV_Sphere> **)((char *)&righthand_terminals[2]->memsize + v42),
      ext_min: (IVP_U_Float_Point *)&min[0].k[1],
      ext_max: (IVP_U_Float_Point *)&max[0].k[1]);
    *(float *)((char *)p_hesse_val + v42) = (float)((float)(fabs(max[0].k[2] - min[0].k[2])
                                                          * fabs(max[0].k[1] - min[0].k[1]))
                                                  * fabs(max[0].hesse_val - min[0].hesse_val))
                                          + (float)((float)(fabs(min[1].k[2] - v61[1]) * fabs(min[1].k[1] - v61[0]))
                                                  * fabs(min[1].hesse_val - v61[2]));
    v78 = v42 + 4;
  }
  while ( v42 + 4 < 28 );
  hesse_val = 1.0e20;
  v45 = new_sphere;
  v46 = 0;
  if ( rad.hesse_val < 1.0e20 )
    hesse_val = rad.hesse_val;
  if ( hesse_val > v65 )
  {
    if ( v71->n_elems != 0 && lefthand_terminals[1]->n_elems != 0 )
      v46 = 1;
    hesse_val = v65;
  }
  if ( hesse_val > v66 && *(_WORD *)(x + 2) != 0 && lefthand_terminals[2]->n_elems != 0 )
    v46 = 2;
  v47 = IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(
          this: *(IVP_SurfaceBuilder_Ledge_Soup **)&v69[12],
          terminals: (IVP_U_Vector<IVV_Sphere> *)*(&new_sphere + v46));
  v48 = lefthand_terminals[v46];
  *(_DWORD *)(*(_DWORD *)&v69[8] + 44) = v47;
  v49 = IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(
          this: *(IVP_SurfaceBuilder_Ledge_Soup **)&v69[12],
          terminals: v48);
  *(_DWORD *)(*(_DWORD *)&v69[8] + 48) = v49;
  if ( v45 != nullptr )
  {
    v50 = (int *)*(&v45->number + 1);
    if ( v50 != &v45->number + 2 )
    {
      if ( v50 != nullptr )
        free(data: v50);
      *(&v45->number + 1) = 0;
      LOWORD(v45->number) = 0;
    }
    HIWORD(v45->number) = 0;
    free(data: v45);
  }
  v51 = v71;
  if ( v71 != nullptr )
  {
    v52 = v71->elems;
    if ( v52 != (void **)&v71[1] )
    {
      if ( v52 != nullptr )
        free(data: v52);
      v51->elems = nullptr;
      v51->memsize = 0;
    }
    v51->n_elems = 0;
    free(data: v51);
  }
  v53 = (_DWORD *)x;
  if ( x != 0 )
  {
    v54 = *(void **)(x + 4);
    if ( v54 != (void *)(x + 8) )
    {
      if ( v54 != nullptr )
        free(data: v54);
      v53[1] = 0;
      *(_WORD *)v53 = 0;
    }
    *((_WORD *)v53 + 1) = 0;
    free(data: v53);
  }
  v55 = lefthand_terminals[0];
  if ( lefthand_terminals[0] != nullptr )
  {
    v56 = (IVP_U_Vector<IVV_Sphere> *)lefthand_terminals[0]->elems;
    if ( v56 != &lefthand_terminals[0][1] )
    {
      if ( v56 != nullptr )
        free(data: v56);
      v55->elems = nullptr;
      v55->memsize = 0;
    }
    v55->n_elems = 0;
    free(data: v55);
  }
  v57 = lefthand_terminals[1];
  if ( lefthand_terminals[1] != nullptr )
  {
    v58 = (IVP_U_Vector<IVV_Sphere> *)lefthand_terminals[1]->elems;
    if ( v58 != &lefthand_terminals[1][1] )
    {
      if ( v58 != nullptr )
        free(data: v58);
      v57->elems = nullptr;
      v57->memsize = 0;
    }
    v57->n_elems = 0;
    free(data: v57);
  }
  v59 = lefthand_terminals[2];
  if ( lefthand_terminals[2] != nullptr )
  {
    v60 = (IVP_U_Vector<IVV_Sphere> *)lefthand_terminals[2]->elems;
    if ( v60 != &lefthand_terminals[2][1] )
    {
      if ( v60 != nullptr )
        free(data: v60);
      v59->elems = nullptr;
      v59->memsize = 0;
    }
    v59->n_elems = 0;
    free(data: v59);
  }
  ++*(_DWORD *)(*(_DWORD *)&v69[12] + 8);
  return *(IVV_Sphere **)&v69[8];
}

//------------------------------------------------------------------------------
// Address: 0x100484B0
// Name: protected: class IVP_Compact_Surface __near * IVP_SurfaceBuilder_Ledge_Soup::allocate_compact_surface(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Surface *__thiscall IVP_SurfaceBuilder_Ledge_Soup::allocate_compact_surface(
        IVP_SurfaceBuilder_Ledge_Soup *this)
{
  int v2; // edx
  int v3; // edi
  void **elems; // ecx
  int v5; // eax
  void **v6; // ecx
  int v7; // eax
  int v8; // ebx
  IVP_Compact_Surface *v9; // eax
  IVP_Compact_Surface *result; // eax
  IVP_Template_Surbuild_LedgeSoup *parameters; // eax
  IVP_SURBUILD_LEDGE_SOUP_MERGE_POINT_TYPES merge_points; // eax
  int v13; // ecx
  int v14; // eax
  IVP_VHash *v15; // eax
  IVP_I_FPoint_VHash *v16; // eax
  IVP_I_FPoint_VHash *point_hash; // ecx
  int v18; // eax
  int v19; // eax
  IVP_I_FPoint_VHash *v20; // [esp+Ch] [ebp-10h]
  int b; // [esp+10h] [ebp-Ch]
  int cs_estimated_ledglelist_size; // [esp+14h] [ebp-8h]
  int cs_estimated_ledglelist_sizea; // [esp+14h] [ebp-8h]
  int cs_estimated_ledglelist_sizeb; // [esp+14h] [ebp-8h]
  int number_of_ledges_compiled; // [esp+18h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  cs_estimated_ledglelist_size = 0;
  number_of_ledges_compiled = 0;
  if ( this->parameters->link_to_input_compact_ledges == IVP_FALSE && this->terminal_spheres.n_elems != 0 )
  {
    elems = this->terminal_spheres.elems;
    cs_estimated_ledglelist_sizea = this->terminal_spheres.n_elems;
    number_of_ledges_compiled = cs_estimated_ledglelist_sizea;
    do
    {
      v5 = *((_DWORD *)*elems + 10);
      v2 += 16 * (*(_DWORD *)(v5 + 8) >> 8);
      v3 += *(__int16 *)(v5 + 12);
      ++elems;
      --cs_estimated_ledglelist_sizea;
    }
    while ( cs_estimated_ledglelist_sizea != 0 );
    cs_estimated_ledglelist_size = v2;
  }
  if ( this->rec_spheres.n_elems != 0 )
  {
    v6 = this->rec_spheres.elems;
    number_of_ledges_compiled += this->rec_spheres.n_elems;
    cs_estimated_ledglelist_sizeb = this->rec_spheres.n_elems;
    do
    {
      v7 = *((_DWORD *)*v6 + 10);
      v2 += 16 * (*(_DWORD *)(v7 + 8) >> 8);
      v3 += *(__int16 *)(v7 + 12);
      ++v6;
      --cs_estimated_ledglelist_sizeb;
    }
    while ( cs_estimated_ledglelist_sizeb != 0 );
    cs_estimated_ledglelist_size = v2;
  }
  v8 = 28 * this->number_of_nodes;
  v9 = (IVP_Compact_Surface *)ivp_malloc_aligned(size: (v8 + v2 + 63) & 0xFFFFFFF0, alignment: 16);
  this->compact_surface = v9;
  if ( v9 == nullptr )
    return nullptr;
  if ( number_of_ledges_compiled <= 1 || (parameters = this->parameters)->link_to_input_compact_ledges != IVP_FALSE )
  {
    this->first_poly_point = nullptr;
    this->point_hash = nullptr;
  }
  else
  {
    merge_points = parameters->merge_points;
    if ( merge_points == IVP_SLMP_MERGE_AND_REALLOCATE || merge_points == IVP_SLMP_MERGE_NO_REALLOCATE )
    {
      v13 = 2;
      v14 = v3;
      b = 2;
      if ( v3 != 0 )
      {
        do
        {
          v14 >>= 1;
          v13 *= 2;
        }
        while ( v14 != 0 );
        b = v13;
      }
      v15 = (IVP_VHash *)p_malloc(size: 0x10u);
      v20 = (IVP_I_FPoint_VHash *)v15;
      if ( v15 != nullptr )
      {
        IVP_VHash::IVP_VHash(this: v15, size_i: b);
        v16 = v20;
        v20->__vftable = (IVP_I_FPoint_VHash_vtbl *)&IVP_I_FPoint_VHash::`vftable';
      }
      else
      {
        v16 = nullptr;
      }
      this->point_hash = v16;
      this->first_poly_point = (IVP_Compact_Poly_Point *)((char *)&this->compact_surface[1]
                                                        + 16 * number_of_ledges_compiled
                                                        + 16 * v3);
    }
  }
  this->n_poly_points_allocated = 0;
  this->first_compact_ledge = (IVP_Compact_Ledge *)&this->compact_surface[1];
  IVP_SurfaceBuilder_Ledge_Soup::insert_compact_ledges(this);
  point_hash = this->point_hash;
  if ( point_hash != nullptr )
  {
    ((void (__thiscall *)(IVP_I_FPoint_VHash *, int))point_hash->dtr_IVP_VHash)(a1: point_hash, a2: 1);
    v18 = number_of_ledges_compiled + this->n_poly_points_allocated;
    this->point_hash = nullptr;
    v19 = 16 * (v3 + v18);
  }
  else
  {
    v19 = cs_estimated_ledglelist_size;
  }
  *((_DWORD *)this->compact_surface + 7) = (unsigned __int8)*((_DWORD *)this->compact_surface + 7)
                                         | ((v19 + v8 + 48) << 8);
  this->compact_surface->offset_ledgetree_root = v19 + 48;
  this->compact_surface->dummy[0] = 0;
  this->compact_surface->dummy[1] = 0;
  this->compact_surface->dummy[2] = 0;
  result = this->compact_surface;
  this->ledgetree_work = (IVP_Compact_Ledgetree_Node *)((char *)this->compact_surface
                                                      + this->compact_surface->offset_ledgetree_root);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048670
// Name: protected: void IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        float __formal)
{
  IVV_Sphere_Cluster *spheres_cluster; // eax
  int next; // esi
  IVV_Sphere *sphere; // ebx
  IVV_Sphere_Cluster *v6; // esi
  IVP_U_Vector<IVV_Sphere> terminals; // [esp+8h] [ebp-8h] BYREF
  char vars0; // [esp+10h] [ebp+0h] BYREF

  *(_DWORD *)&terminals.memsize = 0;
  terminals.elems = nullptr;
  spheres_cluster = this->spheres_cluster;
  next = spheres_cluster->next;
  if ( spheres_cluster->next != 0 )
  {
    do
    {
      sphere = spheres_cluster[next].sphere;
      if ( terminals.n_elems >= terminals.memsize )
        IVP_U_Vector_Base::increment_mem(this: &terminals);
      terminals.elems[terminals.n_elems++] = sphere;
      spheres_cluster = this->spheres_cluster;
      next = spheres_cluster[next].next;
    }
    while ( next != 0 );
  }
  v6 = this->spheres_cluster;
  this->number_of_nodes = this->number_of_terminal_spheres;
  v6[v6->next].sphere = IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut_recursively(
                          this,
                          a2: (int)&vars0,
                          &terminals);
  if ( (char *)terminals.elems != &vars0 && terminals.elems != nullptr )
    free(data: terminals.elems);
}

//------------------------------------------------------------------------------
// Address: 0x10048700
// Name: public: class IVP_Compact_Surface __near * IVP_SurfaceBuilder_Ledge_Soup::compile(class IVP_Template_Surbuild_LedgeSoup __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Surface *__thiscall IVP_SurfaceBuilder_Ledge_Soup::compile(
        IVP_SurfaceBuilder_Ledge_Soup *this,
        IVP_Template_Surbuild_LedgeSoup *templ)
{
  IVP_Template_Surbuild_LedgeSoup *p_t2; // edi
  IVP_Compact_Surface *compact_surface; // edi
  IVP_Template_Surbuild_LedgeSoup *parameters; // eax
  IVP_Template_Surbuild_LedgeSoup t2; // [esp+10h] [ebp-18h] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  p_t2 = templ;
  t2.force_convex_hull = nullptr;
  t2.build_root_convex_hull = IVP_FALSE;
  t2.link_to_input_compact_ledges = IVP_FALSE;
  t2.bUseFastApproximateInertiaTensor = IVP_FALSE;
  t2.free_input_compact_ledges = IVP_TRUE;
  t2.merge_points = IVP_SLMP_MERGE_AND_REALLOCATE;
  if ( templ == nullptr )
    p_t2 = &t2;
  this->parameters = p_t2;
  if ( this->c_ledge_vec.n_elems == 0 )
    return nullptr;
  IVP_SurfaceBuilder_Ledge_Soup::ledges_to_boxes_and_spheres(this, a2: (IVP_Compact_Ledge *)&savedregs);
  IVP_SurfaceBuilder_Ledge_Soup::cluster_spheres_topdown_mediancut(this, __formal: 1.0);
  if ( p_t2->build_root_convex_hull != IVP_FALSE
    && this->c_ledge_vec.n_elems > 1u
    && IVP_SurfaceBuilder_Ledge_Soup::build_root_convex_hull(this) == nullptr )
  {
    return nullptr;
  }
  IVP_SurfaceBuilder_Ledge_Soup::allocate_compact_surface(this);
  IVP_SurfaceBuilder_Ledge_Soup::create_compact_ledgetree(this);
  IVP_SurfaceBuilder_Ledge_Soup::insert_radius_in_compact_surface(
    this,
    a2: COERCE_FLOAT(&savedregs),
    bUseFastInertiaTensor: p_t2->bUseFastApproximateInertiaTensor);
  IVP_SurfaceBuilder_Ledge_Soup::cleanup(this);
  compact_surface = this->compact_surface;
  if ( this->number_of_terminal_spheres > 1 )
  {
    parameters = this->parameters;
    if ( parameters->link_to_input_compact_ledges == IVP_FALSE
      && parameters->merge_points == IVP_SLMP_MERGE_AND_REALLOCATE )
    {
      compact_surface = (IVP_Compact_Surface *)ivp_malloc_aligned(
                                                 size: *((int *)compact_surface + 7) >> 8,
                                                 alignment: 16);
      memcpy(
        dst: (unsigned __int8 *)compact_surface,
        src: (unsigned __int8 *)this->compact_surface,
        count: *((int *)this->compact_surface + 7) >> 8);
      ivp_free_aligned(data: this->compact_surface);
    }
  }
  this->compact_surface = nullptr;
  return compact_surface;
}
