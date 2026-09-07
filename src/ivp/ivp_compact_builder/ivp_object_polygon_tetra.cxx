// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_object_polygon_tetra.cxx
// Functions: 30
// ============================================================

#include "ivp\ivp_compact_builder\ivp_object_polygon_tetra.h"

//------------------------------------------------------------------------------
// Address: 0x100579F0
// Name: public: void IVP_Triangle::calc_hesse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Triangle::calc_hesse(IVP_Triangle *this)
{
  IVP_U_Float_Hesse *p_tmp; // esi

  p_tmp = (IVP_U_Float_Hesse *)&this->tmp;
  IVP_U_Hesse::calc_hesse(
    this: &this->tmp.gen.hesse,
    tp0: this->three_edges[0].start_point,
    tp1: this->three_edges[0].prev->start_point,
    tp2: this->three_edges[0].next->start_point);
  IVP_U_Hesse::normize(this: p_tmp);
}

//------------------------------------------------------------------------------
// Address: 0x10057A20
// Name: public: class IVP_Tri_Edge __near * IVP_Tri_Edge::other_side(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Triangle *__thiscall IVP_Tri_Edge::other_side(IVP_Tri_Edge *this)
{
  IVP_Triangle *result; // eax
  IVP_Poly_Point *start_point; // ecx
  int v3; // edx

  result = this->triangle->other_side;
  if ( result != nullptr )
  {
    start_point = this->start_point;
    result = (IVP_Triangle *)((char *)result + 40);
    v3 = 2;
    while ( (char *)(&result->__vftable)[2]->dtr_IVP_Triangle != (char *)start_point )
    {
      result = (IVP_Triangle *)((char *)result + 36);
      if ( --v3 < 0 )
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057A50
// Name: public: P_Sur_2D_Triangle::P_Sur_2D_Triangle(int,int,int)
// Source: json
//------------------------------------------------------------------------------
P_Sur_2D_Triangle *__thiscall P_Sur_2D_Triangle::P_Sur_2D_Triangle(P_Sur_2D_Triangle *this, int pn0, int pn1, int pn2)
{
  *(_QWORD *)&this->next = 0;
  *(_QWORD *)this->point_nums = 0;
  this->point_nums[2] = 0;
  this->point_nums[0] = pn0;
  this->point_nums[1] = pn1;
  this->point_nums[2] = pn2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057A80
// Name: public: P_Sur_2D_Point::P_Sur_2D_Point(int)
// Source: json
//------------------------------------------------------------------------------
P_Sur_2D_Point *__thiscall P_Sur_2D_Point::P_Sur_2D_Point(P_Sur_2D_Point *this, int i_point_num)
{
  *(_QWORD *)this->k = 0;
  *(_QWORD *)&this->k[2] = 0;
  *(_QWORD *)&this->point_num = 0;
  *(_QWORD *)&this->line_ref = 0;
  this->point_num = i_point_num;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10057AB0
// Name: public: P_Sur_2D_Line::P_Sur_2D_Line(class P_Sur_2D_Point __near *,class P_Sur_2D_Point __near *)
// Source: json
//------------------------------------------------------------------------------
P_Sur_2D_Line *__thiscall P_Sur_2D_Line::P_Sur_2D_Line(P_Sur_2D_Line *this, P_Sur_2D_Point *sp, P_Sur_2D_Point *ep)
{
  P_Sur_2D_Line *result; // eax

  result = this;
  *(_QWORD *)&this->next = 0;
  *(_QWORD *)&this->start_point = 0;
  *(_QWORD *)&this->delta_x = 0;
  this->start_point = sp;
  this->end_point = ep;
  if ( sp != nullptr && ep != nullptr )
  {
    this->delta_x = ep->k[0] - sp->k[0];
    this->delta_y = ep->k[1] - sp->k[1];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057B00
// Name: public: int P_Sur_2D_Line::has_points(class P_Sur_2D_Point __near *,class P_Sur_2D_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall P_Sur_2D_Line::has_points(P_Sur_2D_Line *this, P_Sur_2D_Point *point_a, P_Sur_2D_Point *point_b)
{
  P_Sur_2D_Point *start_point; // eax

  if ( point_b != nullptr )
  {
    start_point = this->start_point;
    if ( start_point == point_a && this->end_point == point_b )
      return 1;
    if ( this->end_point == point_a && start_point == point_b )
      return 1;
  }
  else if ( this->start_point == point_a || this->end_point == point_a )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057B50
// Name: public: float P_Sur_2D_Line::dist_to_point(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall P_Sur_2D_Line::dist_to_point(P_Sur_2D_Line *this, IVP_U_Point *i_point)
{
  P_Sur_2D_Point *start_point; // ecx
  double v3; // st6
  double v4; // st5
  float norm; // [esp+0h] [ebp-4h]

  norm = (float)(this->delta_x * this->delta_x) + (float)(this->delta_y * this->delta_y);
  if ( norm >= 1.0e-10 )
    return ((i_point->k[1] - this->start_point->k[1]) * this->delta_x
          + (this->start_point->k[0] - i_point->k[0]) * this->delta_y)
         / sqrt(norm);
  start_point = this->start_point;
  v3 = start_point->k[1] - i_point->k[1];
  v4 = start_point->k[0] - i_point->k[0];
  return v4 * v4 + v3 * v3;
}

//------------------------------------------------------------------------------
// Address: 0x10057BC0
// Name: public: float P_Sur_2D_Line::hesse_dist_to_point(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall P_Sur_2D_Line::hesse_dist_to_point(P_Sur_2D_Line *this, IVP_U_Point *i_point)
{
  return (i_point->k[1] - this->start_point->k[1]) * this->delta_x
       + (this->start_point->k[0] - i_point->k[0]) * this->delta_y;
}

//------------------------------------------------------------------------------
// Address: 0x10057BE0
// Name: public: int P_Sur_2D_Line::point_lies_in_interval(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall P_Sur_2D_Line::point_lies_in_interval(P_Sur_2D_Line *this, IVP_U_Point *i_point)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  int v4; // eax
  float v5; // xmm1_4

  v2 = fabs(this->delta_x);
  if ( v2 <= 1.0e-10 )
  {
    v2 = fabs(this->delta_y);
    if ( v2 <= 1.0e-10 )
      return false;
    if ( this->delta_y <= 0.0 )
      v4 = -1;
    else
      v4 = 1;
    v3 = i_point->k[1] - this->start_point->k[1];
  }
  else
  {
    v3 = i_point->k[0] - this->start_point->k[0];
    if ( this->delta_x <= 0.0 )
      v4 = -1;
    else
      v4 = 1;
  }
  v5 = v3 * (float)v4;
  return v5 > 0.000099999997 && (float)(v2 - 0.000099999997) > v5;
}

//------------------------------------------------------------------------------
// Address: 0x10057CA0
// Name: public: int P_Sur_2D_Line::overlaps_with_line(class P_Sur_2D_Line __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall P_Sur_2D_Line::overlaps_with_line(P_Sur_2D_Line *this, P_Sur_2D_Line *line_v)
{
  P_Sur_2D_Point *start_point; // eax
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4

  start_point = this->start_point;
  if ( fabs(this->delta_x) <= 0.0000000099999999 )
  {
    if ( fabs(this->delta_y) <= 0.0000000099999999 )
      return P_Sur_2D_Line::point_lies_in_interval(this: line_v, i_point: start_point);
    if ( this->delta_y <= 0.0 )
    {
      v10 = this->end_point->k[1];
      v11 = start_point->k[1];
    }
    else
    {
      v10 = start_point->k[1];
      v11 = this->end_point->k[1];
    }
    v5 = line_v->end_point->k[1];
    v6 = v10 + 0.0000000099999999;
    v7 = v11 - 0.0000000099999999;
    v8 = line_v->start_point->k[1];
  }
  else
  {
    if ( this->delta_x <= 0.0 )
    {
      v3 = this->end_point->k[0];
      v4 = start_point->k[0];
    }
    else
    {
      v3 = start_point->k[0];
      v4 = this->end_point->k[0];
    }
    v5 = line_v->end_point->k[0];
    v6 = v3 + 0.0000000099999999;
    v7 = v4 - 0.0000000099999999;
    v8 = line_v->start_point->k[0];
  }
  return (v6 < v8 || v6 < v5) && (v8 < v7 || v5 < v7);
}

//------------------------------------------------------------------------------
// Address: 0x10057D90
// Name: public: int P_Sur_2D_Line::is_crossing_line(class P_Sur_2D_Line __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall P_Sur_2D_Line::is_crossing_line(P_Sur_2D_Line *this, P_Sur_2D_Line *line_v)
{
  float delta_y; // xmm7_4
  float delta_x; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  P_Sur_2D_Point *start_point; // eax
  P_Sur_2D_Point *end_point; // edx
  P_Sur_2D_Point *v11; // ecx
  P_Sur_2D_Point *v12; // eax
  P_Sur_2D_Point *v13; // esi
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm1_4
  float v18; // xmm2_4

  delta_y = this->delta_y;
  delta_x = this->delta_x;
  v5 = line_v->delta_x;
  v6 = line_v->delta_y;
  v7 = (float)(delta_y * v5) - (float)(delta_x * v6);
  if ( COERCE_FLOAT(LODWORD(v7) & _mask__AbsFloat_) >= 9.9999997e-10 )
  {
    start_point = this->start_point;
    end_point = line_v->end_point;
    if ( start_point != end_point )
    {
      v11 = line_v->start_point;
      if ( start_point != v11 )
      {
        v12 = this->end_point;
        if ( v12 != v11 && v12 != end_point )
        {
          v13 = this->start_point;
          v14 = 0.0;
          v15 = v11->k[0] - v13->k[0];
          v16 = v11->k[1] - v13->k[1];
          if ( v7 <= 0.0 )
          {
            v14 = (float)(delta_y * v5) - (float)(delta_x * v6);
            v7 = 0.0;
          }
          v17 = (float)(v5 * v16) - (float)(v6 * v15);
          if ( v14 <= v17 && v17 <= v7 )
          {
            v18 = (float)(delta_x * v16) - (float)(delta_y * v15);
            if ( v14 <= v18 && v18 <= v7 )
              return true;
          }
        }
      }
    }
  }
  else if ( fabs(P_Sur_2D_Line::dist_to_point(this, i_point: line_v->start_point)) < 0.0000000099999991 )
  {
    return P_Sur_2D_Line::overlaps_with_line(this, line_v);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10057E90
// Name: int p_count_reachable(class P_Sur_2D_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl p_count_reachable(P_Sur_2D_Point *i_point)
{
  P_Sur_2D_Point *end_point; // ecx
  int result; // eax

  end_point = i_point;
  for ( result = 0; end_point != nullptr; ++result )
  {
    if ( end_point->was_reached != 0 )
      break;
    end_point->was_reached = 1;
    end_point = end_point->line_ref->end_point;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057EC0
// Name: float p_ab_quad_length(class P_Sur_2D_Point __near *,class P_Sur_2D_Point __near *,class P_Sur_2D_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl p_ab_quad_length(P_Sur_2D_Point *pa, P_Sur_2D_Point *pb, P_Sur_2D_Point *pc)
{
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]
  float pca; // [esp+1Ch] [ebp+10h]

  v6 = pc->k[0] - pa->k[0];
  v7 = pc->k[1] - pa->k[1];
  v3 = pc->k[2];
  v4 = pc->k[0] - pb->k[0];
  pca = pc->k[1] - pb->k[1];
  return pca * pca
       + v4 * v4
       + (float)(v3 - pb->k[2]) * (float)(v3 - pb->k[2])
       + v7 * v7
       + v6 * v6
       + (float)(v3 - pa->k[2]) * (float)(v3 - pa->k[2]);
}

//------------------------------------------------------------------------------
// Address: 0x10057F50
// Name: void ivp_check_for_opposite(class IVP_Hash __near *,class IVP_Poly_Point __near *,class IVP_Poly_Point __near *,class IVP_Tri_Edge __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ivp_check_for_opposite(IVP_Hash *hash, IVP_Poly_Point *p0, IVP_Poly_Point *p1, IVP_Tri_Edge *edge)
{
  IVP_Tri_Edge *v4; // eax
  IVP_Poly_Point *hashval[2]; // [esp+0h] [ebp-8h] BYREF

  if ( p0 >= p1 )
  {
    hashval[0] = p1;
    hashval[1] = p0;
  }
  else
  {
    hashval[0] = p0;
    hashval[1] = p1;
  }
  v4 = (IVP_Tri_Edge *)IVP_Hash::find(this: hash, key: (const char *)hashval);
  if ( v4 != nullptr )
  {
    edge->opposite = v4;
    v4->opposite = edge;
  }
  else
  {
    IVP_Hash::add(this: hash, key: (const char *)hashval, val: edge);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057FA0
// Name: public: void IVP_Poly_Surface::set(class IVP_Template_Surface __near *,class IVP_Object_Polygon_Tetra __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Poly_Surface::set(
        IVP_Poly_Surface *this,
        IVP_Template_Surface *templ_sur,
        IVP_Object_Polygon_Tetra *i_tetras)
{
  this->tetras = i_tetras;
}

//------------------------------------------------------------------------------
// Address: 0x10057FB0
// Name: void p_link_triangle_self(class IVP_Triangle __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl p_link_triangle_self(IVP_Triangle *tri)
{
  IVP_Tri_Edge *three_edges; // esi
  int i; // edi

  three_edges = tri->three_edges;
  for ( i = 3; i != 0; --i )
  {
    three_edges->triangle = tri;
    three_edges->behind = three_edges;
    three_edges->opposite = (IVP_Tri_Edge *)IVP_Tri_Edge::other_side(this: three_edges);
    ++three_edges;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057FE0
// Name: private: void IVP_Object_Polygon_Tetra::add_edge_into_point_to_edge_hash(class IVP_Tri_Edge __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Polygon_Tetra::add_edge_into_point_to_edge_hash(
        IVP_Object_Polygon_Tetra *this,
        IVP_Tri_Edge *edge)
{
  IVP_Poly_Point *start_point; // eax
  IVP_Tri_Edge *next; // ecx
  IVP_Poly_Point *v5; // ecx
  IVP_Poly_Point *p[2]; // [esp+8h] [ebp-8h] BYREF

  start_point = edge->start_point;
  next = edge->next;
  p[0] = start_point;
  v5 = next->start_point;
  p[1] = v5;
  if ( start_point > v5 )
  {
    p[0] = v5;
    p[1] = start_point;
  }
  if ( IVP_Hash::find(this: this->points_to_edge_hash, key: (const char *)p) == nullptr )
    IVP_Hash::add(this: this->points_to_edge_hash, key: (const char *)p, val: edge);
}

//------------------------------------------------------------------------------
// Address: 0x10058030
// Name: public: virtual IVP_Triangle::~IVP_Triangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Triangle::~IVP_Triangle(IVP_Triangle *this)
{
  this->__vftable = (IVP_Triangle_vtbl *)&IVP_Triangle::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10058040
// Name: public: void IVP_Object_Polygon_Tetra::insert_pierce_info(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Polygon_Tetra::insert_pierce_info(IVP_Object_Polygon_Tetra *this)
{
  IVP_Triangle *i; // eax
  IVP_Triangle *j; // edx
  IVP_Triangle *first; // eax
  IVP_Triangle *v4; // esi
  float k; // xmm1_4

  for ( i = this->triangles.first; i != nullptr; i = i->next )
    i->pierced_triangle = nullptr;
  for ( j = this->triangles.first; j != nullptr; j = j->next )
  {
    if ( j->flags.is_hidden == 0 && j->pierced_triangle == nullptr )
    {
      first = this->triangles.first;
      v4 = nullptr;
      for ( k = -0.000001; first != nullptr; first = first->next )
      {
        if ( first->flags.is_hidden == 0
          && k > (float)((float)((float)(first->tmp.gen.hesse.k[1] * j->tmp.gen.hesse.k[1])
                               + (float)(first->tmp.gen.hesse.k[0] * j->tmp.gen.hesse.k[0]))
                       + (float)(first->tmp.gen.hesse.k[2] * j->tmp.gen.hesse.k[2])) )
        {
          k = (float)((float)(first->tmp.gen.hesse.k[1] * j->tmp.gen.hesse.k[1])
                    + (float)(first->tmp.gen.hesse.k[0] * j->tmp.gen.hesse.k[0]))
            + (float)(first->tmp.gen.hesse.k[2] * j->tmp.gen.hesse.k[2]);
          v4 = first;
        }
      }
      j->pierced_triangle = v4;
      v4->pierced_triangle = j;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100580F0
// Name: public: int P_Sur_2D_Line::point_lies_to_the_left(class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall P_Sur_2D_Line::point_lies_to_the_left(P_Sur_2D_Line *this, IVP_U_Point *i_point)
{
  double v2; // st7
  int result; // eax
  float hesse_dist; // [esp+8h] [ebp+8h]

  v2 = P_Sur_2D_Line::hesse_dist_to_point(this, i_point);
  if ( v2 <= 1.0e-10 )
    return 0;
  result = 2;
  hesse_dist = v2;
  if ( P_Pop_Too_Flat_Eps < hesse_dist )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058130
// Name: public: P_Sur_2D::P_Sur_2D(class IVP_Object_Polygon_Tetra __near *,class IVP_Template_Surface __near *)
// Source: json
//------------------------------------------------------------------------------
P_Sur_2D *__thiscall P_Sur_2D::P_Sur_2D(P_Sur_2D *this, IVP_Object_Polygon_Tetra *tetras_, IVP_Template_Surface *sur)
{
  *(_QWORD *)&this->orig_tetras = 0;
  this->lines = 0;
  this->triangles = 0;
  *(_QWORD *)&this->line_array = 0;
  this->orig_tetras = tetras_;
  this->orig_surface = sur;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058160
// Name: public: P_Sur_2D::~P_Sur_2D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall P_Sur_2D::~P_Sur_2D(P_Sur_2D *this)
{
  P_Sur_2D_Line *first; // esi
  P_Sur_2D_Point *end_point; // eax
  P_Sur_2D_Line *prev; // eax
  P_Sur_2D_Triangle *i; // eax
  P_Sur_2D_Triangle *v6; // ecx

  if ( this->line_array != nullptr )
  {
    free(data: this->line_array);
    this->line_array = nullptr;
  }
  if ( this->point_array != nullptr )
  {
    free(data: this->point_array);
    this->point_array = nullptr;
  }
  while ( this->lines.first != nullptr )
  {
    first = this->lines.first;
    if ( first->start_point != nullptr )
      free(data: first->start_point);
    end_point = first->end_point;
    first->start_point = nullptr;
    if ( end_point != nullptr )
      free(data: end_point);
    prev = first->prev;
    first->end_point = nullptr;
    if ( prev != nullptr )
      prev->next = first->next;
    else
      this->lines.first = first->next;
    if ( first->next != nullptr )
      first->next->prev = first->prev;
    first->next = (P_Sur_2D_Line *)-1;
    --this->lines.len;
    free(data: first);
  }
  for ( i = this->triangles.first; i != nullptr; i = this->triangles.first )
  {
    v6 = i->prev;
    if ( v6 != nullptr )
      v6->next = i->next;
    else
      this->triangles.first = i->next;
    if ( i->next != nullptr )
      i->next->prev = i->prev;
    i->next = (P_Sur_2D_Triangle *)-1;
    --this->triangles.len;
    free(data: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058240
// Name: public: char const __near * P_Sur_2D::calc_line_representation(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall P_Sur_2D::calc_line_representation(P_Sur_2D *this)
{
  IVP_Template_Surface *orig_surface; // esi
  int v4; // edi
  float v5; // xmm0_4
  float v6; // xmm1_4
  char *v7; // edi
  P_Sur_2D_Line **line_array; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // ecx
  int v13; // esi
  P_Sur_2D_Point *v14; // edi
  int v15; // ebx
  P_Sur_2D_Point *v16; // eax
  IVP_Poly_Point *points; // eax
  double v18; // st7
  P_Sur_2D_Point *v19; // esi
  P_Sur_2D_Point *v20; // eax
  IVP_Poly_Point *v21; // eax
  double v22; // st7
  P_Sur_2D_Line *v23; // eax
  P_Sur_2D_Line *v24; // eax
  P_Sur_2D_Line *first; // edx
  IVP_Template_Surface *sur; // [esp+8h] [ebp-24h]
  int i; // [esp+Ch] [ebp-20h]
  IVP_Object_Polygon_Tetra *pop; // [esp+14h] [ebp-18h]
  int v30; // [esp+18h] [ebp-14h]
  BOOL trafo_is_mirrored; // [esp+1Ch] [ebp-10h]
  P_Sur_2D_Point **point_hash_array; // [esp+20h] [ebp-Ch]
  int td_k0; // [esp+24h] [ebp-8h]
  int td_k1; // [esp+28h] [ebp-4h]

  orig_surface = this->orig_surface;
  sur = orig_surface;
  if ( orig_surface == nullptr )
    return "calc_line_representation: no orig_surface specified!\n";
  v4 = 0;
  v5 = fabs(orig_surface->normal.k[0]);
  v6 = fabs(orig_surface->normal.k[1]);
  pop = this->orig_tetras;
  if ( v6 > v5 )
  {
    v5 = v6;
    v4 = 1;
  }
  if ( fabs(orig_surface->normal.k[2]) > v5 )
    v4 = 2;
  if ( v4 == 0 )
  {
    td_k0 = 1;
    goto LABEL_11;
  }
  td_k0 = 0;
  if ( v4 == 1 )
  {
LABEL_11:
    td_k1 = 2;
    goto LABEL_12;
  }
  td_k1 = 1;
LABEL_12:
  trafo_is_mirrored = orig_surface->normal.k[v4] < 0.0;
  if ( v4 == 1 )
    trafo_is_mirrored = orig_surface->normal.k[1] >= 0.0;
  v7 = _calloc_crt(nelem: pop->n_points, size: 4);
  line_array = this->line_array;
  point_hash_array = (P_Sur_2D_Point **)v7;
  if ( line_array != nullptr )
  {
    free(data: line_array);
    this->line_array = nullptr;
  }
  this->line_array = (P_Sur_2D_Line **)_calloc_crt(nelem: orig_surface->n_lines, size: 4);
  if ( this->point_array != nullptr )
  {
    free(data: this->point_array);
    this->point_array = nullptr;
  }
  this->point_array = (P_Sur_2D_Point **)_calloc_crt(nelem: orig_surface->n_lines, size: 4);
  v9 = orig_surface->n_lines - 1;
  i = v9;
  if ( v9 >= 0 )
  {
    v30 = 0;
    while ( 1 )
    {
      v10 = (int)&pop->template_polygon->lines[orig_surface->lines[v9]];
      v11 = orig_surface->revert_line[v9];
      if ( trafo_is_mirrored )
        v11 = 1 - v11;
      v12 = 2 * v11;
      v13 = *(unsigned __int16 *)(v12 + v10);
      v14 = *(P_Sur_2D_Point **)&v7[4 * v13];
      v15 = *(unsigned __int16 *)(v10 - v12 + 2);
      if ( v14 == nullptr )
      {
        v16 = (P_Sur_2D_Point *)p_malloc(size: 0x20u);
        if ( v16 != nullptr )
          v14 = P_Sur_2D_Point::P_Sur_2D_Point(this: v16, i_point_num: v13);
        else
          v14 = nullptr;
        point_hash_array[v13] = v14;
        this->point_array[v30++] = v14;
      }
      points = pop->points;
      v18 = points[v13].k[td_k0];
      v14->k[1] = points[v13].k[td_k1];
      v14->k[0] = v18;
      v14->k[2] = 0.0;
      v19 = point_hash_array[v15];
      if ( v19 == nullptr )
      {
        v20 = (P_Sur_2D_Point *)p_malloc(size: 0x20u);
        if ( v20 != nullptr )
          v19 = P_Sur_2D_Point::P_Sur_2D_Point(this: v20, i_point_num: v15);
        else
          v19 = nullptr;
        point_hash_array[v15] = v19;
        this->point_array[v30++] = v19;
      }
      v21 = pop->points;
      v22 = v21[v15].k[td_k0];
      v19->k[1] = v21[v15].k[td_k1];
      v19->k[0] = v22;
      v19->k[2] = 0.0;
      v23 = (P_Sur_2D_Line *)p_malloc(size: 0x18u);
      if ( v23 != nullptr )
        v24 = P_Sur_2D_Line::P_Sur_2D_Line(this: v23, sp: v14, ep: v19);
      else
        v24 = nullptr;
      v14->line_ref = v24;
      v24->next = this->lines.first;
      first = this->lines.first;
      if ( first != nullptr )
        first->prev = v24;
      v7 = (char *)point_hash_array;
      v24->prev = nullptr;
      ++this->lines.len;
      this->lines.first = v24;
      this->line_array[i--] = v24;
      if ( i < 0 )
        break;
      orig_surface = sur;
      v9 = i;
    }
  }
  if ( v7 != nullptr )
    free(data: v7);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100584F0
// Name: public: char const __near * P_Sur_2D::calc_triangle_representation(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall P_Sur_2D::calc_triangle_representation(P_Sur_2D *this)
{
  P_Sur_2D_Line *first; // edi
  IVP_U_Min_Hash_Elem **stadel; // eax
  int v4; // edx
  P_Sur_2D_Line *v5; // esi
  P_Sur_2D_Point *end_point; // ecx
  int elem; // ecx
  P_Sur_2D_Point *v8; // esi
  P_Sur_2D_Line *v9; // eax
  P_Sur_2D_Line *v10; // eax
  P_Sur_2D_Line *v11; // esi
  P_Sur_2D_Point *v12; // edi
  P_Sur_2D_Line *v13; // ecx
  P_Sur_2D_Line *v14; // esi
  IVP_U_Point *start_point; // edi
  P_Sur_2D_Triangle *v16; // eax
  int v17; // edi
  P_Sur_2D_Triangle *v18; // eax
  P_Sur_2D_Triangle *v19; // ecx
  P_Sur_2D_Line *v20; // ecx
  P_Sur_2D_Line *prev; // eax
  P_Sur_2D_Line *v22; // ecx
  P_Sur_2D_Line *next; // esi
  P_Sur_2D_Line *v24; // ecx
  P_Sur_2D_Line *v25; // eax
  P_Sur_2D_Line *v26; // eax
  P_Sur_2D_Line *v27; // eax
  P_Sur_2D_Line *v28; // eax
  P_Sur_2D_Line *v29; // ecx
  P_Sur_2D_Line *v30; // eax
  P_Sur_2D_Line *v31; // eax
  P_Sur_2D_Line *v32; // ecx
  int j; // esi
  P_Sur_2D_Point **point_array; // ecx
  P_Sur_2D_Line *i; // esi
  float val; // [esp+14h] [ebp-44h]
  IVP_U_Min_Hash ab_min_hash; // [esp+24h] [ebp-34h] BYREF
  int bc_removed; // [esp+38h] [ebp-20h]
  int loop_counter; // [esp+3Ch] [ebp-1Ch]
  P_Sur_2D_Line *td_base_line; // [esp+40h] [ebp-18h]
  P_Sur_2D_Line *td_bc_line; // [esp+44h] [ebp-14h]
  P_Sur_2D_Line *td_ca_line; // [esp+48h] [ebp-10h]
  P_Sur_2D_Point *ep; // [esp+4Ch] [ebp-Ch]
  P_Sur_2D_Point *point_b; // [esp+50h] [ebp-8h]
  P_Sur_2D_Point *point_a; // [esp+54h] [ebp-4h]

  p_count_reachable(i_point: this->lines.first->start_point);
  IVP_U_Min_Hash::IVP_U_Min_Hash(this: &ab_min_hash, sizei: 16);
  first = this->lines.first;
  td_ca_line = nullptr;
  td_bc_line = nullptr;
  loop_counter = 0;
  td_base_line = first;
  if ( first == nullptr )
    goto LABEL_92;
  stadel = ab_min_hash.stadel;
  do
  {
    v4 = loop_counter++;
    if ( v4 > 100 )
    {
      for ( i = this->lines.first; i != nullptr; i = i->next )
        printf(format: "  %f %f %f\n", i->start_point->k[0], i->start_point->k[1], i->start_point->k[2]);
      IVP_U_Min_Hash::~IVP_U_Min_Hash(this: &ab_min_hash);
      return "Cannot convert";
    }
    while ( stadel[1] != nullptr && stadel[1]->elem != nullptr )
    {
      IVP_U_Min_Hash::remove_min(this: &ab_min_hash);
      stadel = ab_min_hash.stadel;
    }
    v5 = this->lines.first;
    end_point = first->end_point;
    point_a = first->start_point;
    point_b = end_point;
    if ( v5 != nullptr )
    {
      do
      {
        val = p_ab_quad_length(pa: point_a, pb: point_b, pc: v5->start_point);
        IVP_U_Min_Hash::add(this: &ab_min_hash, elem: v5, val);
        v5 = v5->next;
      }
      while ( v5 != nullptr );
      stadel = ab_min_hash.stadel;
    }
    if ( stadel[1] == nullptr )
      goto LABEL_87;
    elem = (int)stadel[1]->elem;
    bc_removed = elem;
    if ( elem == 0 )
      goto LABEL_87;
    while ( 1 )
    {
      if ( (P_Sur_2D_Line *)elem == first )
        goto LABEL_44;
      v8 = *(P_Sur_2D_Point **)(elem + 8);
      ep = v8;
      if ( v8 == first->end_point || P_Sur_2D_Line::point_lies_to_the_left(this: first, i_point: v8) == 0 )
        goto LABEL_44;
      if ( td_ca_line != nullptr )
        free(data: td_ca_line);
      v9 = (P_Sur_2D_Line *)p_malloc(size: 0x18u);
      if ( v9 != nullptr )
        td_ca_line = P_Sur_2D_Line::P_Sur_2D_Line(this: v9, sp: v8, ep: point_a);
      else
        td_ca_line = nullptr;
      if ( td_bc_line != nullptr )
        free(data: td_bc_line);
      v10 = (P_Sur_2D_Line *)p_malloc(size: 0x18u);
      td_bc_line = v10 != nullptr ? P_Sur_2D_Line::P_Sur_2D_Line(this: v10, sp: point_b, ep: v8) : nullptr;
      v11 = this->lines.first;
      if ( v11 == nullptr )
        break;
      v12 = ep;
      while ( (P_Sur_2D_Line::has_points(this: v11, point_a: v12, point_b: point_a) != 0
            || !P_Sur_2D_Line::is_crossing_line(this: v11, line_v: td_ca_line))
           && (P_Sur_2D_Line::has_points(this: v11, point_a: point_b, point_b: v12) != 0
            || !P_Sur_2D_Line::is_crossing_line(this: v13, line_v: td_bc_line)) )
      {
        v11 = v11->next;
        if ( v11 == nullptr )
          goto LABEL_32;
      }
      if ( *((_DWORD *)ab_min_hash.stadel + 1) == 0 || *(_DWORD *)(*((_DWORD *)ab_min_hash.stadel + 1) + 12) == 0 )
      {
        printf(format: "Couldn't find a matching point to baseline!\n");
        _Error(a1: "IVP Failed at %s %d\n", "ivp_object_polygon_tetra.cxx", 806);
      }
LABEL_44:
      IVP_U_Min_Hash::remove_min(this: &ab_min_hash);
      stadel = ab_min_hash.stadel;
      if ( *((_DWORD *)ab_min_hash.stadel + 1) == 0 )
        goto LABEL_87;
      elem = *(_DWORD *)(*((_DWORD *)ab_min_hash.stadel + 1) + 12);
      bc_removed = elem;
      if ( elem == 0 )
        goto LABEL_87;
      first = td_base_line;
    }
LABEL_32:
    v14 = this->lines.first;
    if ( v14 != nullptr )
    {
      while ( 1 )
      {
        start_point = v14->start_point;
        if ( P_Sur_2D_Line::point_lies_to_the_left(this: td_base_line, i_point: start_point) != 0
          && P_Sur_2D_Line::point_lies_to_the_left(this: td_bc_line, i_point: start_point) != 0
          && P_Sur_2D_Line::point_lies_to_the_left(this: td_ca_line, i_point: start_point) != 0 )
        {
          break;
        }
        v14 = v14->next;
        if ( v14 == nullptr )
          goto LABEL_37;
      }
      if ( *(_DWORD *)bc_removed == 0 )
      {
        printf(format: "Couldn't find a matching point to baseline!\n");
        _Error(a1: "IVP Failed at %s %d\n", "ivp_object_polygon_tetra.cxx", 833);
      }
      goto LABEL_44;
    }
LABEL_37:
    v16 = (P_Sur_2D_Triangle *)p_malloc(size: 0x14u);
    v17 = 0;
    if ( v16 != nullptr )
      v18 = P_Sur_2D_Triangle::P_Sur_2D_Triangle(
              this: v16,
              pn0: point_a->point_num,
              pn1: ep->point_num,
              pn2: point_b->point_num);
    else
      v18 = nullptr;
    v18->next = this->triangles.first;
    v19 = this->triangles.first;
    if ( v19 != nullptr )
      v19->prev = v18;
    v20 = td_base_line;
    v18->prev = nullptr;
    ++this->triangles.len;
    this->triangles.first = v18;
    prev = v20->prev;
    if ( prev != nullptr )
      prev->next = v20->next;
    else
      this->lines.first = v20->next;
    if ( v20->next != nullptr )
      v20->next->prev = v20->prev;
    v20->next = (P_Sur_2D_Line *)-1;
    --this->lines.len;
    bc_removed = 0;
    free(data: v20);
    v22 = this->lines.first;
    if ( v22 == nullptr )
    {
LABEL_73:
      v27 = (P_Sur_2D_Line *)p_malloc(size: 0x18u);
      if ( v27 != nullptr )
        v28 = P_Sur_2D_Line::P_Sur_2D_Line(this: v27, sp: point_a, ep);
      else
        v28 = nullptr;
      v28->next = this->lines.first;
      v29 = this->lines.first;
      if ( v29 != nullptr )
        v29->prev = v28;
      v28->prev = nullptr;
      ++this->lines.len;
      this->lines.first = v28;
      goto LABEL_79;
    }
    while ( 2 )
    {
      next = v22->next;
      if ( P_Sur_2D_Line::has_points(this: v22, point_a: ep, point_b: point_a) != 0 )
      {
        v25 = v24->prev;
        if ( v25 != nullptr )
          v25->next = next;
        else
          this->lines.first = next;
        if ( v24->next != nullptr )
          v24->next->prev = v24->prev;
        v17 = 1;
        goto LABEL_70;
      }
      if ( P_Sur_2D_Line::has_points(this: v24, point_a: ep, point_b) != 0 )
      {
        v26 = v24->prev;
        if ( v26 != nullptr )
          v26->next = next;
        else
          this->lines.first = next;
        if ( v24->next != nullptr )
          v24->next->prev = v24->prev;
        bc_removed = 1;
LABEL_70:
        v24->next = (P_Sur_2D_Line *)-1;
        --this->lines.len;
        free(data: v24);
      }
      v22 = next;
      if ( next != nullptr )
        continue;
      break;
    }
    if ( v17 == 0 )
      goto LABEL_73;
LABEL_79:
    if ( bc_removed == 0 )
    {
      v30 = (P_Sur_2D_Line *)p_malloc(size: 0x18u);
      if ( v30 != nullptr )
        v31 = P_Sur_2D_Line::P_Sur_2D_Line(this: v30, sp: ep, ep: point_b);
      else
        v31 = nullptr;
      v31->next = this->lines.first;
      v32 = this->lines.first;
      if ( v32 != nullptr )
        v32->prev = v31;
      v31->prev = nullptr;
      ++this->lines.len;
      this->lines.first = v31;
    }
    stadel = ab_min_hash.stadel;
LABEL_87:
    first = this->lines.first;
    td_base_line = first;
  }
  while ( first != nullptr );
  if ( td_ca_line != nullptr )
    free(data: td_ca_line);
  if ( td_bc_line != nullptr )
    free(data: td_bc_line);
LABEL_92:
  for ( j = this->orig_surface->n_lines - 1; j >= 0; --j )
  {
    point_array = this->point_array;
    if ( point_array[j] != nullptr )
      free(data: point_array[j]);
  }
  IVP_U_Min_Hash::~IVP_U_Min_Hash(this: &ab_min_hash);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100589B0
// Name: public: IVP_Object_Polygon_Tetra::IVP_Object_Polygon_Tetra(class IVP_Template_Polygon __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Object_Polygon_Tetra *__thiscall IVP_Object_Polygon_Tetra::IVP_Object_Polygon_Tetra(
        IVP_Object_Polygon_Tetra *this,
        IVP_Template_Polygon *i_temp_pop)
{
  int v2; // ebx
  IVP_Poly_Point *v5; // eax
  int v6; // edx
  IVP_Template_Point *v7; // eax
  IVP_Poly_Point *points; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // ebx
  int v12; // edx
  int n_points; // [esp-10h] [ebp-1Ch]
  int n_surfaces; // [esp-4h] [ebp-10h]
  IVP_Template_Polygon *i_temp_popa; // [esp+14h] [ebp+8h]
  IVP_Template_Polygon *i_temp_popb; // [esp+14h] [ebp+8h]

  v2 = 0;
  this->triangles.first = nullptr;
  this->triangles.len = 0;
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Object_Polygon_Tetra));
  this->template_polygon = i_temp_pop;
  n_points = i_temp_pop->n_points;
  this->n_points = i_temp_pop->n_points;
  v5 = (IVP_Poly_Point *)_calloc_crt(nelem: 32, size: n_points);
  v6 = 0;
  this->points = v5;
  if ( this->n_points > 0 )
  {
    i_temp_popa = nullptr;
    do
    {
      v7 = (IVP_Template_Point *)((char *)i_temp_popa + (unsigned int)i_temp_pop->points);
      points = this->points;
      v9 = v7->k[1];
      v10 = v7->k[2];
      points[v6].k[0] = v7->k[0];
      i_temp_popa = (IVP_Template_Polygon *)((char *)i_temp_popa + 16);
      points[v6].k[1] = v9;
      points[v6].k[2] = v10;
      this->points[v6].l_tetras = this;
      ++v2;
      ++v6;
    }
    while ( v2 < this->n_points );
  }
  n_surfaces = i_temp_pop->n_surfaces;
  this->n_surfaces = n_surfaces;
  v11 = 0;
  this->surfaces = (IVP_Poly_Surface *)_calloc_crt(nelem: 12, size: n_surfaces);
  if ( this->n_surfaces <= 0 )
  {
    this->template_polygon = nullptr;
    return this;
  }
  else
  {
    i_temp_popb = nullptr;
    do
    {
      IVP_Poly_Surface::set(
        this: (IVP_Poly_Surface *)((char *)i_temp_popb + (unsigned int)this->surfaces),
        templ_sur: &i_temp_pop->surfaces[v11],
        i_tetras: this);
      i_temp_popb = (IVP_Template_Polygon *)((char *)i_temp_popb + 12);
      ++v11;
    }
    while ( v12 + 1 < this->n_surfaces );
    this->template_polygon = nullptr;
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058A90
// Name: private: void IVP_Object_Polygon_Tetra::free_triangles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Polygon_Tetra::free_triangles(IVP_Object_Polygon_Tetra *this)
{
  IVP_Triangle *i; // ecx
  IVP_Triangle *prev; // eax
  IVP_Triangle *next; // eax
  IVP_Extra_Point *extra_points; // eax
  IVP_Extra_Point *v6; // edi

  for ( i = this->triangles.first; i != nullptr; i = this->triangles.first )
  {
    prev = i->prev;
    if ( prev != nullptr )
      prev->next = i->next;
    else
      this->triangles.first = i->next;
    next = i->next;
    if ( next != nullptr )
      next->prev = i->prev;
    i->next = (IVP_Triangle *)-1;
    --this->triangles.len;
    ((void (__thiscall *)(IVP_Triangle *, int))i->dtr_IVP_Triangle)(a1: i, a2: 1);
  }
  extra_points = this->extra_points;
  if ( extra_points != nullptr )
  {
    do
    {
      v6 = extra_points->next;
      free(data: extra_points);
      extra_points = v6;
    }
    while ( v6 != nullptr );
  }
  this->extra_points = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10058B00
// Name: public: IVP_Triangle::IVP_Triangle(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Triangle *__thiscall IVP_Triangle::IVP_Triangle(IVP_Triangle *this)
{
  this->other_side = nullptr;
  this->prev = nullptr;
  this->next = nullptr;
  this->pierced_triangle = nullptr;
  *(_WORD *)&this->flags.is_terminal = 0;
  this->ivp_surface = nullptr;
  this->__vftable = (IVP_Triangle_vtbl *)&IVP_Triangle::`vftable';
  memset(dst: (unsigned __int8 *)this->three_edges, value: 0, count: sizeof(this->three_edges));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058B70
// Name: public: static class IVP_Triangle __near * IVP_Object_Polygon_Tetra::generate_double_triangle(class IVP_Poly_Point __near *,class IVP_Poly_Point __near *,class IVP_Poly_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Triangle *__cdecl IVP_Object_Polygon_Tetra::generate_double_triangle(
        IVP_Poly_Point *p1,
        IVP_Poly_Point *p2,
        IVP_Poly_Point *p3)
{
  IVP_Triangle *v3; // eax
  IVP_Triangle *v4; // esi
  IVP_Triangle *v5; // eax
  IVP_Triangle *v6; // edi
  IVP_Tri_Edge *next; // ebx
  IVP_Tri_Edge *v8; // eax

  v3 = (IVP_Triangle *)p_malloc(size: 0xC0u);
  if ( v3 != nullptr )
    v4 = IVP_Triangle::IVP_Triangle(this: v3);
  else
    v4 = nullptr;
  v5 = (IVP_Triangle *)p_malloc(size: 0xC0u);
  if ( v5 != nullptr )
    v6 = IVP_Triangle::IVP_Triangle(this: v5);
  else
    v6 = nullptr;
  v4->three_edges[0].triangle = v4;
  v4->three_edges[0].next = &v4->three_edges[1];
  v4->three_edges[0].prev = &v4->three_edges[2];
  v4->three_edges[0].start_point = p1;
  v4->three_edges[1].prev = v4->three_edges;
  v4->three_edges[1].triangle = v4;
  v4->three_edges[1].next = &v4->three_edges[2];
  v4->three_edges[1].start_point = p2;
  v4->three_edges[2].prev = &v4->three_edges[1];
  v4->three_edges[2].start_point = p3;
  v4->three_edges[2].next = v4->three_edges;
  v4->three_edges[2].triangle = v4;
  v6->three_edges[0].start_point = p2;
  v6->three_edges[0].triangle = v6;
  v6->three_edges[0].next = &v6->three_edges[2];
  v6->three_edges[0].prev = &v6->three_edges[1];
  v6->three_edges[1].next = v6->three_edges;
  v6->three_edges[1].prev = &v6->three_edges[2];
  v6->three_edges[1].start_point = p3;
  v6->three_edges[1].triangle = v6;
  v6->three_edges[2].prev = v6->three_edges;
  v6->three_edges[2].next = &v6->three_edges[1];
  v6->three_edges[2].start_point = p1;
  v6->three_edges[2].triangle = v6;
  v4->other_side = v6;
  v6->other_side = v4;
  p_link_triangle_self(tri: v4);
  p_link_triangle_self(tri: v6);
  IVP_Triangle::calc_hesse(this: v4);
  IVP_Triangle::calc_hesse(this: v6);
  v4->three_edges[0].tmp.gen.tetra_point = v4->three_edges[0].start_point->tmp.tetra_point;
  next = v4->three_edges[0].next;
  next->tmp.gen.tetra_point = next->start_point->tmp.tetra_point;
  next->next->tmp.gen.tetra_point = next->next->start_point->tmp.tetra_point;
  v6->three_edges[0].tmp.gen.tetra_point = v6->three_edges[0].start_point->tmp.tetra_point;
  v8 = v6->three_edges[0].next;
  v8->tmp.gen.tetra_point = v8->start_point->tmp.tetra_point;
  v8->next->tmp.gen.tetra_point = v8->next->start_point->tmp.tetra_point;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10058C90
// Name: public: IVP_Object_Polygon_Tetra::~IVP_Object_Polygon_Tetra(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Object_Polygon_Tetra::~IVP_Object_Polygon_Tetra(IVP_Object_Polygon_Tetra *this)
{
  IVP_Object_Polygon_Tetra::free_triangles(this);
  if ( this->surfaces != nullptr )
  {
    free(data: this->surfaces);
    this->surfaces = nullptr;
  }
  if ( this->points != nullptr )
  {
    free(data: this->points);
    this->points = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058CD0
// Name: public: char const __near * IVP_Object_Polygon_Tetra::make_triangles(void)
// Source: json
//------------------------------------------------------------------------------
const char *__usercall IVP_Object_Polygon_Tetra::make_triangles@<eax>(
        IVP_Object_Polygon_Tetra *this@<ecx>,
        IVP_Template_Surface *a2@<ebp>)
{
  IVP_Object_Polygon_Tetra *v2; // esi
  int v3; // eax
  int v4; // edi
  IVP_Hash *v5; // eax
  IVP_Poly_Point *v6; // edi
  int v7; // ecx
  P_Sur_2D *v8; // eax
  P_Sur_2D *v9; // edi
  const char *v10; // eax
  const char *v11; // eax
  P_Sur_2D_Triangle *v12; // edi
  IVP_Poly_Point *points; // edx
  int v14; // eax
  int v15; // ecx
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float *k; // ecx
  int v20; // edi
  float v21; // xmm0_4
  IVP_Poly_Point *v22; // edi
  float v23; // xmm3_4
  float v24; // xmm0_4
  IVP_Triangle *v25; // eax
  IVP_Triangle *v26; // edi
  IVP_Triangle *v27; // eax
  IVP_Template_Surface *v28; // ecx
  int surface_index; // eax
  IVP_Poly_Point *v30; // ecx
  IVP_Poly_Point *v31; // edx
  IVP_Hash *v32; // ecx
  IVP_Poly_Point *v33; // eax
  void *v34; // edi
  IVP_Triangle *v35; // eax
  IVP_Triangle *v36; // edi
  IVP_Triangle *first; // eax
  int v39; // ecx
  IVP_Poly_Point *p_next; // eax
  IVP_Object_Polygon_Tetra *v41; // ecx
  IVP_Poly_Point *v42; // eax
  P_Sur_2D_Triangle *v43; // edx
  IVP_Triangle *v44; // eax
  IVP_Triangle *v45; // eax
  IVP_Poly_Point *v46; // ecx
  P_Sur_2D_Triangle *next; // edx
  bool v48; // zf
  IVP_Tri_Edge *v49; // edi
  IVP_Hash *v50; // [esp-4Ch] [ebp-ACh]
  IVP_Poly_Point *v51; // [esp-44h] [ebp-A4h]
  float v52[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Point cross; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Point v0; // [esp+10h] [ebp-50h] BYREF
  int template_polygon; // [esp+30h] [ebp-30h]
  IVP_Object_Polygon_Tetra *v56; // [esp+34h] [ebp-2Ch]
  IVP_Poly_Point *v57; // [esp+38h] [ebp-28h]
  int i; // [esp+3Ch] [ebp-24h]
  P_Sur_2D_Triangle *v59; // [esp+40h] [ebp-20h]
  IVP_Poly_Point *po; // [esp+44h] [ebp-1Ch]
  P_Sur_2D *td_sur; // [esp+48h] [ebp-18h]
  P_Sur_2D_Triangle *td_tri; // [esp+4Ch] [ebp-14h]
  IVP_Poly_Point *po3; // [esp+50h] [ebp-10h]
  IVP_Template_Surface *sur; // [esp+54h] [ebp-Ch]
  IVP_Poly_Point *po2; // [esp+58h] [ebp-8h]
  IVP_Poly_Point *retaddr; // [esp+60h] [ebp+0h]

  sur = a2;
  po2 = retaddr;
  v2 = this;
  template_polygon = (int)this->template_polygon;
  v3 = *(_DWORD *)template_polygon;
  v56 = this;
  v4 = 2 * (3 * v3 - 6);
  v5 = (IVP_Hash *)p_malloc(size: 0x10u);
  if ( v5 != nullptr )
  {
    v6 = (IVP_Poly_Point *)IVP_Hash::IVP_Hash(this: v5, sizei: v4, key_sizei: 8, not_found_valuei: nullptr);
    po3 = v6;
  }
  else
  {
    po3 = nullptr;
    v6 = nullptr;
  }
  v7 = template_polygon;
  template_polygon = *(_DWORD *)(template_polygon + 16) - 1;
  td_sur = *(P_Sur_2D **)(v7 + 20);
  if ( template_polygon < 0 )
  {
LABEL_23:
    if ( v6 != nullptr )
    {
      IVP_Hash::~IVP_Hash(this: (IVP_Hash *)v6);
      free(data: v6);
    }
    for ( i = (int)v2->triangles.first; i != 0; i = *(_DWORD *)(i + 16) )
    {
      v35 = (IVP_Triangle *)p_malloc(size: 0xC0u);
      if ( v35 != nullptr )
        v36 = IVP_Triangle::IVP_Triangle(this: v35);
      else
        v36 = nullptr;
      v36->next = v2->triangles.first;
      first = v2->triangles.first;
      if ( first != nullptr )
        first->prev = v36;
      v36->prev = nullptr;
      v2->triangles.first = v36;
      ++v2->triangles.len;
      v36->ivp_surface = nullptr;
      v39 = i;
      v36->other_side = (IVP_Triangle *)i;
      *(_WORD *)&v36->flags.is_terminal = 257;
      *(_DWORD *)(v39 + 24) = v36;
      td_tri = (P_Sur_2D_Triangle *)(v39 + 132);
      p_next = (IVP_Poly_Point *)&v36->three_edges[2].next;
      v41 = (IVP_Object_Polygon_Tetra *)(v39 - (_DWORD)v36);
      td_sur = (P_Sur_2D *)3;
      po3 = (IVP_Poly_Point *)&v36->three_edges[2].next;
      v56 = v41;
      template_polygon = 3;
      while ( 1 )
      {
        *((_DWORD *)&p_next[-1].tmp + 1) = **(_DWORD **)((char *)p_next->k + (_DWORD)v41);
        *((_DWORD *)&p_next[-1].tmp + 2) = v36;
        LODWORD(po3->k[0]) = &v36->three_edges[((int)&td_sur->orig_tetras + 1) % 3];
        v42 = po3;
        v43 = td_tri;
        LODWORD(po3->k[1]) = &v36->three_edges[(int)td_sur % 3];
        LODWORD(v42->k[2]) = v43->next;
        v44 = IVP_Tri_Edge::other_side(this: (IVP_Tri_Edge *)(&v42[-1].tmp + 1));
        v45 = IVP_Tri_Edge::other_side(this: (IVP_Tri_Edge *)v44->prev);
        v46 = po3;
        if ( v45 != nullptr )
        {
          LODWORD(po3->hesse_val) = v45;
          v45->prev = (IVP_Triangle *)(&v46[-1].tmp + 1);
        }
        next = td_tri->next;
        td_tri = (P_Sur_2D_Triangle *)((char *)td_tri - 36);
        next->point_nums[2] = (int)(&v46[-1].tmp + 1);
        td_sur = (P_Sur_2D *)((char *)td_sur - 1);
        v48 = template_polygon-- == 1;
        po3 = (IVP_Poly_Point *)((char *)v46 - 36);
        if ( v48 )
          break;
        v41 = v56;
        p_next = po3;
      }
      template_polygon = 2;
      v49 = &v36->three_edges[2];
      do
      {
        IVP_Object_Polygon_Tetra::add_edge_into_point_to_edge_hash(this: v2, edge: v49--);
        --template_polygon;
      }
      while ( template_polygon >= 0 );
    }
    return nullptr;
  }
  else
  {
    while ( 1 )
    {
      v8 = (P_Sur_2D *)p_malloc(size: 0x20u);
      if ( v8 != nullptr )
      {
        v9 = P_Sur_2D::P_Sur_2D(this: v8, tetras_: v2, sur: (IVP_Template_Surface *)td_sur);
        i = (int)v9;
      }
      else
      {
        i = 0;
        v9 = nullptr;
      }
      v10 = P_Sur_2D::calc_line_representation(this: v9);
      if ( v10 != nullptr )
      {
        printf(format: "make_triangles:calc_line_representation: %s\n", v10);
        return "No 2d representation";
      }
      v11 = P_Sur_2D::calc_triangle_representation(this: v9);
      if ( v11 != nullptr )
        break;
      v12 = v9->triangles.first;
      v59 = v12;
      if ( v12 != nullptr )
      {
        while ( 1 )
        {
          points = v2->points;
          v14 = v12->point_nums[1];
          v15 = v12->point_nums[2];
          v16 = points[v14].k[2] - points[v15].k[2];
          v17 = points[v14].k[0] - points[v15].k[0];
          v18 = points[v14].k[1] - points[v15].k[1];
          k = points[v15].k;
          v20 = v12->point_nums[0];
          v21 = points[v20].k[1] - k[1];
          v22 = &points[v20];
          cross.hesse_val = v16;
          v23 = v22->k[0] - *k;
          v0.k[2] = v21;
          v24 = v22->k[2] - k[2];
          td_tri = (P_Sur_2D_Triangle *)&points[v14];
          v57 = (IVP_Poly_Point *)k;
          po = v22;
          cross.k[1] = v17;
          cross.k[2] = v18;
          v0.k[1] = v23;
          v0.hesse_val = v24;
          IVP_U_Float_Point::calc_cross_product(
            this: (IVP_U_Float_Point *)v52,
            v1: (IVP_U_Point *)&cross.k[1],
            v2: (IVP_U_Point *)&v0.k[1]);
          if ( (float)((float)((float)(v52[0] * *(float *)&td_sur->orig_tetras)
                             + (float)(*(float *)&td_sur->orig_surface * v52[1]))
                     + (float)(*(float *)&td_sur->lines.first * v52[2])) < 0.0 )
          {
            po = (IVP_Poly_Point *)td_tri;
            td_tri = (P_Sur_2D_Triangle *)v22;
          }
          v25 = (IVP_Triangle *)p_malloc(size: 0xC0u);
          if ( v25 != nullptr )
            v26 = IVP_Triangle::IVP_Triangle(this: v25);
          else
            v26 = nullptr;
          v26->next = v2->triangles.first;
          v27 = v2->triangles.first;
          if ( v27 != nullptr )
            v27->prev = v26;
          v28 = (IVP_Template_Surface *)td_sur;
          v26->prev = nullptr;
          ++v2->triangles.len;
          v2->triangles.first = v26;
          v26->flags.is_terminal = 1;
          surface_index = IVP_Template_Surface::get_surface_index(this: v28);
          v30 = v57;
          v26->ivp_surface = &v2->surfaces[surface_index];
          v26->flags.is_hidden = 0;
          v26->three_edges[0].start_point = v30;
          v26->three_edges[0].triangle = v26;
          v26->three_edges[0].next = &v26->three_edges[1];
          v26->three_edges[0].prev = &v26->three_edges[2];
          v26->three_edges[0].behind = nullptr;
          ivp_check_for_opposite(hash: (IVP_Hash *)po3, p0: v30, p1: (IVP_Poly_Point *)td_tri, edge: v26->three_edges);
          v26->three_edges[1].start_point = (IVP_Poly_Point *)td_tri;
          v31 = po;
          v26->three_edges[1].prev = v26->three_edges;
          v32 = (IVP_Hash *)po3;
          v26->three_edges[1].triangle = v26;
          v26->three_edges[1].next = &v26->three_edges[2];
          v26->three_edges[1].behind = nullptr;
          ivp_check_for_opposite(hash: v32, p0: (IVP_Poly_Point *)td_tri, p1: v31, edge: &v26->three_edges[1]);
          v33 = po;
          v26->three_edges[2].next = v26->three_edges;
          v51 = v57;
          v26->three_edges[2].start_point = v33;
          v50 = (IVP_Hash *)po3;
          v26->three_edges[2].triangle = v26;
          v26->three_edges[2].prev = &v26->three_edges[1];
          v26->three_edges[2].behind = nullptr;
          ivp_check_for_opposite(hash: v50, p0: v33, p1: v51, edge: &v26->three_edges[2]);
          v2 = v56;
          v59 = v59->next;
          if ( v59 == nullptr )
            break;
          v12 = v59;
        }
      }
      v34 = (void *)i;
      P_Sur_2D::~P_Sur_2D(this: (P_Sur_2D *)i);
      free(data: v34);
      ++td_sur;
      if ( --template_polygon < 0 )
      {
        v6 = po3;
        goto LABEL_23;
      }
    }
    printf(format: "make_triangles:calc_triangle_representation: %s\n", v11);
    return "no 3d representation";
  }
}
