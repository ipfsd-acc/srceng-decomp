// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_surbuild_pointsoup.cxx
// Functions: 9
// ============================================================

#include "ivp\ivp_compact_builder\ivp_surbuild_pointsoup.h"

//------------------------------------------------------------------------------
// Address: 0x10045DB0
// Name: protected: static int IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(class IVP_Template_Point __near *,int,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(
        IVP_Template_Point *points,
        int length,
        IVP_U_Point *point)
{
  int v3; // edx
  float *i; // ecx

  v3 = 0;
  if ( length <= 0 )
    return 0;
  for ( i = &points->k[2]; *(i - 2) != point->k[0] || *(i - 1) != point->k[1] || *i != point->k[2]; i += 4 )
  {
    if ( ++v3 >= length )
      return 0;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10045E10
// Name: protected: static int IVP_SurfaceBuilder_Pointsoup::get_offset_from_lineslist(class IVP_Template_Line __near *,int,int,int,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_SurfaceBuilder_Pointsoup::get_offset_from_lineslist(
        IVP_Template_Line *lines,
        int length,
        int pointnr1,
        int pointnr2,
        char *reverse)
{
  int result; // eax
  int v6; // edx

  result = 0;
  if ( length <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = lines[result].p[0];
    if ( pointnr1 == v6 && pointnr2 == lines[result].p[1] )
    {
      *reverse = 0;
      return (unsigned __int16)result;
    }
    if ( pointnr1 == lines[result].p[1] && pointnr2 == v6 )
      break;
    if ( ++result >= length )
      return 0;
  }
  *reverse = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045E70
// Name: public: float IVP_SurMan_PS_Plane::get_area_size(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_SurMan_PS_Plane::get_area_size@<st0>(IVP_SurMan_PS_Plane *this@<ecx>, int a2@<ebp>)
{
  void *v3; // ecx
  int n_elems; // edi
  float v5; // eax
  float *v6; // ecx
  float *v7; // edx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v13[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Point cross; // [esp+0h] [ebp-40h] BYREF
  IVP_U_Point diff0; // [esp+10h] [ebp-30h] BYREF
  IVP_U_Point diff1; // [esp+20h] [ebp-20h]
  float v17; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  IVP_U_Point *p0; // [esp+38h] [ebp-8h]
  IVP_U_Point *retaddr; // [esp+40h] [ebp+0h]

  v18 = a2;
  p0 = retaddr;
  v3 = *this->points.elems;
  n_elems = this->points.n_elems;
  v5 = 0.0;
  v17 = 0.0;
  LODWORD(diff1.hesse_val) = v3;
  if ( n_elems != 0 )
  {
    do
    {
      v6 = (float *)this->points.elems[LODWORD(v5)];
      LODWORD(diff1.k[2]) = LODWORD(v5) + 1;
      v7 = (float *)this->points.elems[(LODWORD(v5) + 1) % n_elems];
      v8 = v7[1] - v6[1];
      v9 = v7[2] - v6[2];
      cross.k[1] = *v7 - *v6;
      cross.k[2] = v8;
      cross.hesse_val = v9;
      v10 = v6[1] - *(float *)(LODWORD(diff1.hesse_val) + 4);
      v11 = v6[2] - *(float *)(LODWORD(diff1.hesse_val) + 8);
      diff0.k[1] = *v6 - *(float *)LODWORD(diff1.hesse_val);
      diff0.k[2] = v10;
      diff0.hesse_val = v11;
      IVP_U_Float_Point::calc_cross_product(
        this: (IVP_U_Float_Point *)v13,
        v1: (IVP_U_Point *)&cross.k[1],
        v2: (IVP_U_Point *)&diff0.k[1]);
      n_elems = this->points.n_elems;
      v5 = diff1.k[2];
      v17 = (float)((float)((float)(this->k[0] * v13[0]) + (float)(v13[1] * this->k[1])) + (float)(v13[2] * this->k[2]))
          + v17;
    }
    while ( SLODWORD(diff1.k[2]) < n_elems );
  }
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10045F80
// Name: public: float IVP_SurMan_PS_Plane::get_len_of_all_edges(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_SurMan_PS_Plane::get_len_of_all_edges(IVP_SurMan_PS_Plane *this)
{
  float v1; // xmm3_4
  int n_elems; // edi
  int v3; // eax
  void **elems; // ebx
  float *v5; // ecx
  int v6; // edx
  float *v7; // edx
  float sum; // [esp+0h] [ebp-4h]

  v1 = 0.0;
  n_elems = this->points.n_elems;
  v3 = 0;
  sum = 0.0;
  if ( this->points.n_elems != 0 )
  {
    elems = this->points.elems;
    do
    {
      v5 = (float *)elems[v3];
      v6 = ++v3 % n_elems;
      v7 = (float *)elems[v6];
      v1 = v1
         + fsqrt(
             (float)((float)((float)(v5[1] - v7[1]) * (float)(v5[1] - v7[1]))
                   + (float)((float)(*v5 - *v7) * (float)(*v5 - *v7)))
           + (float)((float)(v5[2] - v7[2]) * (float)(v5[2] - v7[2])));
      sum = v1;
    }
    while ( v3 < n_elems );
  }
  return sum;
}

//------------------------------------------------------------------------------
// Address: 0x10046000
// Name: public: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge(class IVP_U_Point __near *,class IVP_U_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__usercall IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge@<eax>(
        IVP_BOOL a1@<ebp>,
        IVP_U_Point *p0,
        IVP_U_Point *p1,
        IVP_U_Point *p2)
{
  IVP_Compact_Ledge *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  unsigned __int8 *v12; // esi
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *v18; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  _DWORD v21[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_Template_Triangle templ_tri; // [esp+0h] [ebp-40h] BYREF
  _DWORD *v23; // [esp+30h] [ebp-10h]
  IVP_Template_Ledge_Polygon_Soup ledge_templ; // [esp+34h] [ebp-Ch]
  int retaddr; // [esp+40h] [ebp+0h]

  ledge_templ.ledge_is_open = a1;
  ledge_templ.n_templ_triangles = retaddr;
  v4 = IVP_SurfaceBuilder_Pointsoup::single_tri_ledge;
  if ( IVP_SurfaceBuilder_Pointsoup::single_tri_ledge == nullptr )
  {
    templ_tri.tri_points[2].k[2] = 0.0;
    v21[0] = 0;
    v21[1] = 0;
    templ_tri.tri_points[0].k[1] = 0.0;
    templ_tri.tri_points[0].hesse_val = 0.0;
    templ_tri.tri_points[1].k[1] = 0.0;
    templ_tri.tri_points[1].k[2] = 0.0;
    v21[2] = 1065353216;
    templ_tri.tri_points[0].k[2] = 1.0;
    templ_tri.tri_points[1].hesse_val = -1.0;
    LODWORD(templ_tri.tri_points[2].hesse_val) = 2;
    v23 = v21;
    v4 = IVP_SurfaceBuilder_Polygon_Convex::convert_templateledgepolygonsoup_to_ledge(templat: (IVP_Template_Ledge_Polygon_Soup *)&templ_tri.tri_points[2].k[2]);
    IVP_SurfaceBuilder_Pointsoup::single_tri_ledge = v4;
  }
  v5 = p2->k[1] - p0->k[1];
  v6 = p2->k[2] - p0->k[2];
  v7 = p1->k[1] - p0->k[1];
  v8 = p1->k[2] - p0->k[2];
  v9 = p2->k[0] - p0->k[0];
  v10 = p1->k[0] - p0->k[0];
  if ( (float)((float)((float)((float)((float)(v6 * v10) - (float)(v9 * v8))
                             * (float)((float)(v6 * v10) - (float)(v9 * v8)))
                     + (float)((float)((float)(v5 * v8) - (float)(v6 * v7))
                             * (float)((float)(v5 * v8) - (float)(v6 * v7))))
             + (float)((float)((float)(v9 * v7) - (float)(v5 * v10)) * (float)((float)(v9 * v7) - (float)(v5 * v10)))) < 1.0e-12 )
    return nullptr;
  v12 = (unsigned __int8 *)ivp_malloc_aligned(size: 16 * (*((_DWORD *)v4 + 2) >> 8), alignment: 16);
  memcpy(
    dst: v12,
    src: (unsigned __int8 *)IVP_SurfaceBuilder_Pointsoup::single_tri_ledge,
    count: 16 * (*((_DWORD *)IVP_SurfaceBuilder_Pointsoup::single_tri_ledge + 2) >> 8));
  v13 = *(_DWORD *)v12;
  v14 = p0->k[1];
  v15 = p0->k[2];
  *(float *)&v12[v13] = p0->k[0];
  *(float *)&v12[v13 + 4] = v14;
  *(float *)&v12[v13 + 8] = v15;
  v16 = p1->k[1];
  v17 = p1->k[2];
  *(float *)&v12[v13 + 16] = p1->k[0];
  v18 = (float *)&v12[v13];
  v18[5] = v16;
  v18[6] = v17;
  v19 = p2->k[1];
  v20 = p2->k[2];
  v18[8] = p2->k[0];
  v18[9] = v19;
  v18[10] = v20;
  return (IVP_Compact_Ledge *)v12;
}

//------------------------------------------------------------------------------
// Address: 0x100461B0
// Name: protected: static class IVP_Template_Polygon __near * IVP_SurfaceBuilder_Pointsoup::planes_to_template(class IVP_U_Vector<class IVP_U_Point> __near *,class IVP_U_Vector<class IVP_SurMan_PS_Plane> __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Polygon *__cdecl IVP_SurfaceBuilder_Pointsoup::planes_to_template(
        IVP_U_Vector<IVP_U_Point> *points,
        IVP_U_Vector<IVP_SurMan_PS_Plane> *planes)
{
  IVP_Template_Polygon *v2; // eax
  IVP_Template_Polygon *v3; // esi
  int n_elems; // edi
  IVP_U_Point *v5; // ebx
  int n_points; // edi
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v9; // edi
  IVP_Hash *v10; // eax
  int v11; // ebx
  void *v12; // eax
  int v13; // eax
  IVP_Template_Surface *v14; // edi
  int v15; // edx
  IVP_SurMan_PS_Plane *v16; // eax
  int v17; // ecx
  int v18; // edi
  IVP_U_Point **elems; // ebx
  IVP_U_Point *v20; // edi
  unsigned __int16 offset_from_pointlist; // bx
  IVP_Hash *v22; // edi
  char *v23; // edi
  void *v24; // edi
  int v25; // edi
  unsigned __int16 *v26; // eax
  int v27; // edi
  float *v28; // ecx
  IVP_Template_Surface *surfaces; // eax
  float v30; // xmm0_4
  float v31; // xmm1_4
  unsigned __int16 *v32; // eax
  int v33; // ebx
  unsigned __int16 v34; // ax
  unsigned __int16 *v35; // edx
  int i; // ebx
  IVP_U_Vector<point_hash_key2> lines_vector; // [esp+Ch] [ebp-28h] BYREF
  int v39; // [esp+14h] [ebp-20h] BYREF
  IVP_SurMan_PS_Plane *plane; // [esp+18h] [ebp-1Ch]
  int face_vertex_count; // [esp+1Ch] [ebp-18h]
  int offset_point1; // [esp+20h] [ebp-14h]
  int face_count; // [esp+24h] [ebp-10h]
  unsigned __int16 *offset_points; // [esp+28h] [ebp-Ch]
  int punktezahl; // [esp+2Ch] [ebp-8h]
  int x; // [esp+30h] [ebp-4h]

  v2 = (IVP_Template_Polygon *)p_malloc(size: 0x18u);
  if ( v2 != nullptr )
    v3 = IVP_Template_Polygon::IVP_Template_Polygon(this: v2);
  else
    v3 = nullptr;
  n_elems = points->n_elems;
  face_vertex_count = n_elems;
  v3->n_points = 0;
  v3->points = (IVP_Template_Point *)p_malloc(size: 16 * n_elems);
  for ( x = 0; x < face_vertex_count; ++x )
  {
    v5 = (IVP_U_Point *)points->elems[x];
    n_points = v3->n_points;
    if ( IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(points: v3->points, length: v3->n_points, point: v5) == 0 )
    {
      v7 = v5->k[1];
      v8 = v5->k[2];
      v9 = (int)&v3->points[n_points];
      *(float *)v9 = v5->k[0];
      *(float *)(v9 + 4) = v7;
      *(float *)(v9 + 8) = v8;
      ++v3->n_points;
    }
  }
  v10 = (IVP_Hash *)p_malloc(size: 0x10u);
  if ( v10 != nullptr )
    punktezahl = (int)IVP_Hash::IVP_Hash(this: v10, sizei: 2 * points->n_elems, key_sizei: 4, not_found_valuei: nullptr);
  else
    punktezahl = 0;
  *(_DWORD *)&lines_vector.memsize = 0;
  lines_vector.elems = nullptr;
  v11 = planes->n_elems;
  face_count = v11;
  v3->n_surfaces = v11;
  v12 = p_malloc(size: __CFADD__(32 * v11, 16) ? -1 : 32 * v11 + 16);
  if ( v12 != nullptr )
  {
    v13 = (int)v12 + 16;
    *(_DWORD *)(v13 - 16) = v11;
    face_vertex_count = v13;
    v14 = (IVP_Template_Surface *)v13;
    points = (IVP_U_Vector<IVP_U_Point> *)(v11 - 1);
    if ( v11 - 1 >= 0 )
    {
      do
      {
        IVP_Template_Surface::IVP_Template_Surface(this: v14++);
        points = (IVP_U_Vector<IVP_U_Point> *)((char *)points - 1);
      }
      while ( (int)points >= 0 );
      v13 = face_vertex_count;
    }
  }
  else
  {
    v13 = 0;
  }
  v15 = 0;
  v3->surfaces = (IVP_Template_Surface *)v13;
  v3->n_lines = 0;
  x = 0;
  if ( v11 > 0 )
  {
    offset_points = nullptr;
    do
    {
      v16 = (IVP_SurMan_PS_Plane *)planes->elems[v15];
      v17 = v16->points.n_elems;
      *(int *)((char *)&v3->surfaces->n_lines + (unsigned int)offset_points) = v17;
      v18 = 0;
      plane = v16;
      face_vertex_count = v17;
      if ( v17 != 0 )
      {
        while ( 1 )
        {
          elems = (IVP_U_Point **)v16->points.elems;
          offset_point1 = (unsigned __int16)IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(
                                              points: v3->points,
                                              length: v3->n_points,
                                              point: elems[v18]);
          v39 = v18 + 1;
          if ( v18 + 1 == face_vertex_count )
            v20 = *elems;
          else
            v20 = elems[v18 + 1];
          offset_from_pointlist = IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(
                                    points: v3->points,
                                    length: v3->n_points,
                                    point: v20);
          if ( offset_from_pointlist >= (unsigned __int16)offset_point1 )
          {
            LOWORD(points) = offset_from_pointlist;
            HIWORD(points) = offset_point1;
          }
          else
          {
            LOWORD(points) = offset_point1;
            HIWORD(points) = offset_from_pointlist;
          }
          v22 = (IVP_Hash *)punktezahl;
          if ( IVP_Hash::find(this: (IVP_Hash *)punktezahl, key: (const char *)&points) == nullptr )
          {
            IVP_Hash::add(this: v22, key: (const char *)&points, val: (void *)1);
            v23 = _calloc_crt(nelem: 1, size: 4);
            *(_WORD *)v23 = offset_point1;
            *((_WORD *)v23 + 1) = offset_from_pointlist;
            if ( lines_vector.n_elems >= lines_vector.memsize )
              IVP_U_Vector_Base::increment_mem(this: &lines_vector);
            lines_vector.elems[lines_vector.n_elems++] = v23;
            ++v3->n_lines;
          }
          v18 = v39;
          if ( v39 >= face_vertex_count )
            break;
          v16 = plane;
        }
        v15 = x;
      }
      v11 = face_count;
      offset_points += 16;
      x = ++v15;
    }
    while ( v15 < face_count );
  }
  v24 = (void *)punktezahl;
  if ( punktezahl != 0 )
  {
    IVP_Hash::~IVP_Hash(this: (IVP_Hash *)punktezahl);
    free(data: v24);
  }
  v3->lines = (IVP_Template_Line *)p_malloc(size: (unsigned __int64)(unsigned int)v3->n_lines >> 30 != 0 ? -1 : 4 * v3->n_lines);
  v25 = 0;
  if ( lines_vector.n_elems != 0 )
  {
    do
    {
      v26 = (unsigned __int16 *)lines_vector.elems[v25];
      v3->lines[v25].p[0] = *v26;
      v3->lines[v25].p[1] = v26[1];
      free(data: v26);
      ++v25;
    }
    while ( v25 < lines_vector.n_elems );
  }
  v27 = 0;
  x = 0;
  if ( v11 > 0 )
  {
    do
    {
      v28 = (float *)planes->elems[x];
      v3->surfaces[v27].templ_poly = v3;
      surfaces = v3->surfaces;
      v30 = v28[1];
      v31 = v28[2];
      surfaces[v27].normal.k[0] = *v28;
      surfaces[v27].normal.k[1] = v30;
      surfaces[v27].normal.k[2] = v31;
      v39 = (int)v28;
      v3->surfaces[v27].lines = (unsigned __int16 *)_calloc_crt(nelem: v3->surfaces[v27].n_lines, size: 2);
      v3->surfaces[v27].revert_line = (char *)p_malloc(size: v3->surfaces[v27].n_lines);
      punktezahl = v3->surfaces[v27].n_lines;
      v32 = (unsigned __int16 *)_calloc_crt(nelem: punktezahl + 1, size: 2);
      v33 = 0;
      offset_points = v32;
      if ( punktezahl > 0 )
      {
        do
        {
          v34 = IVP_SurfaceBuilder_Pointsoup::get_offset_from_pointlist(
                  points: v3->points,
                  length: v3->n_points,
                  point: *(IVP_U_Point **)(*(_DWORD *)(v39 + 20) + 4 * v33));
          v35 = offset_points;
          offset_points[v33++] = v34;
        }
        while ( v33 < punktezahl );
        v32 = v35;
      }
      v32[v33] = *v32;
      for ( i = 0; i < punktezahl; v3->surfaces[v27].revert_line[i - 1] = 1 - HIBYTE(points) )
      {
        v3->surfaces[v27].lines[i] = IVP_SurfaceBuilder_Pointsoup::get_offset_from_lineslist(
                                       lines: v3->lines,
                                       length: v3->n_lines,
                                       pointnr1: v32[i],
                                       pointnr2: v32[i + 1],
                                       reverse: (char *)&points + 3);
        v32 = offset_points;
        ++i;
      }
      free(data: v32);
      ++v27;
      ++x;
    }
    while ( x < face_count );
  }
  if ( (int *)lines_vector.elems != &v39 && lines_vector.elems != nullptr )
    free(data: lines_vector.elems);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100465D0
// Name: protected: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Pointsoup::try_to_build_convex_ledge_from_qhull_result(class IVP_U_Vector<class IVP_U_Point> __near *,enum IVP_BOOL __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl IVP_SurfaceBuilder_Pointsoup::try_to_build_convex_ledge_from_qhull_result(
        IVP_U_Vector<IVP_U_Point> *points,
        IVP_BOOL *skip_point,
        char *skip_list,
        char *use_list)
{
  facetT *facet_list; // edi
  IVP_SurMan_PS_Plane *v5; // esi
  IVP_SurMan_PS_Plane *v6; // eax
  int i; // eax
  setT *v8; // eax
  setelemT v9; // eax
  long double *v10; // edx
  int v11; // edi
  void *v12; // ebx
  float v13; // edx
  double area_size; // st7
  float v15; // xmm3_4
  int v16; // xmm0_4
  int n_elems; // edi
  int v18; // eax
  int v19; // ebx
  float v20; // xmm4_4
  float **elems; // edx
  float *v22; // ecx
  float *v23; // edx
  float v24; // xmm0_4
  int v25; // edx
  void **v26; // ecx
  float *v27; // eax
  float *v28; // ecx
  float v29; // xmm0_4
  int v30; // eax
  IVP_Compact_Ledge *v31; // ebx
  IVP_Template_Polygon *v32; // esi
  int v33; // edi
  _DWORD *v34; // esi
  char *v35; // eax
  IVP_U_Vector<IVP_SurMan_PS_Plane> planes; // [esp+Ch] [ebp-20h] BYREF
  IVP_U_Vector<IVP_SB_PS_DUMMY> point_indizes; // [esp+14h] [ebp-18h] BYREF
  setT *vertices; // [esp+1Ch] [ebp-10h] BYREF
  int max_index2; // [esp+20h] [ebp-Ch]
  float edge_sum; // [esp+24h] [ebp-8h]
  facetT *facet; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  *skip_point = IVP_FALSE;
  facet_list = qh_qh.facet_list;
  *(_DWORD *)&planes.memsize = 0;
  planes.elems = nullptr;
  *(_DWORD *)&point_indizes.memsize = 0;
  point_indizes.elems = nullptr;
  facet = qh_qh.facet_list;
  if ( qh_qh.facet_list != nullptr )
  {
    while ( 1 )
    {
      *(float *)&v5 = 0.0;
      if ( facet_list->next == nullptr )
        break;
      v6 = (IVP_SurMan_PS_Plane *)p_malloc(size: 0x20u);
      if ( v6 != nullptr )
      {
        v6->points.elems = nullptr;
        *(_DWORD *)&v6->points.memsize = 0;
        v5 = v6;
      }
      max_index2 = (int)v5;
      if ( planes.n_elems >= planes.memsize )
        IVP_U_Vector_Base::increment_mem(this: &planes);
      planes.elems[planes.n_elems++] = v5;
      for ( i = 0; i < qh_qh.hull_dim; ++i )
        v5->k[i] = facet_list->normal[i];
      v8 = qh_facet3vertex(facet: facet_list);
      vertices = v8;
      point_indizes.n_elems = 0;
      if ( v8 != nullptr )
      {
        LODWORD(edge_sum) = v8->e;
        v9.p = (void *)v8->e[0];
        if ( v9.i != 0 )
        {
          do
          {
            v10 = *(long double **)(v9.i + 8);
            LODWORD(edge_sum) += 4;
            v11 = qh_pointid(point: v10);
            if ( point_indizes.n_elems >= point_indizes.memsize )
              IVP_U_Vector_Base::increment_mem(this: &point_indizes);
            point_indizes.elems[point_indizes.n_elems++] = (void *)v11;
            v12 = points->elems[v11];
            if ( v5->points.n_elems >= v5->points.memsize )
              IVP_U_Vector_Base::increment_mem(this: &v5->points);
            v13 = edge_sum;
            v5->points.elems[v5->points.n_elems++] = v12;
            ++use_list[v11];
            v9.p = ((setelemT *)LODWORD(v13))->p;
          }
          while ( *(_DWORD *)LODWORD(v13) != 0 );
          v5 = (IVP_SurMan_PS_Plane *)max_index2;
          facet_list = facet;
        }
      }
      area_size = IVP_SurMan_PS_Plane::get_area_size(this: v5, a2: (int)&savedregs);
      *(float *)&max_index2 = area_size;
      edge_sum = IVP_SurMan_PS_Plane::get_len_of_all_edges(this: v5);
      v15 = -1.0;
      if ( area_size >= 0.0 )
      {
        v16 = max_index2;
      }
      else
      {
        v5->k[0] = v5->k[0] * -1.0;
        v5->k[1] = v5->k[1] * -1.0;
        v5->k[2] = v5->k[2] * -1.0;
        *(float *)&v16 = *(float *)&max_index2 * -1.0;
      }
      if ( edge_sum * 0.004999999888241291 > *(float *)&v16 )
      {
        n_elems = point_indizes.n_elems;
        v18 = 0;
        v19 = 0;
        v20 = -1.0;
        *(float *)&max_index2 = 0.0;
        if ( point_indizes.n_elems != 0 )
        {
          while ( skip_list[(unsigned int)point_indizes.elems[v18]] == 0 )
          {
            elems = (float **)v5->points.elems;
            v22 = elems[v18];
            v23 = *elems;
            v24 = fsqrt(
                    (float)((float)((float)(v23[1] - v22[1]) * (float)(v23[1] - v22[1]))
                          + (float)((float)(*v23 - *v22) * (float)(*v23 - *v22)))
                  + (float)((float)(v23[2] - v22[2]) * (float)(v23[2] - v22[2])));
            if ( v24 > v20 )
            {
              v19 = v18;
              v20 = v24;
            }
            if ( ++v18 >= point_indizes.n_elems )
              goto LABEL_28;
          }
        }
        else
        {
LABEL_28:
          *(float *)&v25 = 0.0;
          if ( point_indizes.n_elems != 0 )
          {
            do
            {
              *skip_point = IVP_TRUE;
              v26 = v5->points.elems;
              v27 = (float *)v26[v25];
              v28 = (float *)v26[v19];
              v29 = fsqrt(
                      (float)((float)((float)(v28[1] - v27[1]) * (float)(v28[1] - v27[1]))
                            + (float)((float)(*v28 - *v27) * (float)(*v28 - *v27)))
                    + (float)((float)(v28[2] - v27[2]) * (float)(v28[2] - v27[2])));
              if ( v29 > v15 )
              {
                max_index2 = v25;
                v15 = v29;
              }
              ++v25;
            }
            while ( v25 < n_elems );
          }
          v30 = 0;
          if ( n_elems > 0 )
          {
            while ( v30 == max_index2 || v30 == v19 )
            {
              if ( ++v30 >= n_elems )
                goto LABEL_38;
            }
            ++*((_BYTE *)point_indizes.elems[v30] + (unsigned int)skip_list);
          }
        }
LABEL_38:
        facet_list = facet;
      }
      qh_settempfree(set: &vertices);
      facet = facet_list->next;
      if ( facet == nullptr )
        break;
      facet_list = facet;
    }
  }
  v31 = nullptr;
  if ( *skip_point == IVP_FALSE )
  {
    v32 = IVP_SurfaceBuilder_Pointsoup::planes_to_template(points, &planes);
    v31 = IVP_SurfaceBuilder_Polygon_Convex::convert_template_to_ledge(templat: v32);
    if ( v32 != nullptr )
    {
      IVP_Template_Polygon::~IVP_Template_Polygon(this: v32);
      free(data: v32);
    }
  }
  v33 = 0;
  if ( planes.n_elems != 0 )
  {
    do
    {
      v34 = planes.elems[v33];
      if ( v34 != nullptr )
      {
        v35 = (char *)v34[5];
        if ( v35 != (char *)(v34 + 6) )
        {
          if ( v35 != nullptr )
            free(data: v35);
          v34[5] = 0;
          *((_WORD *)v34 + 8) = 0;
        }
        *((_WORD *)v34 + 9) = 0;
        free(data: v34);
      }
      ++v33;
    }
    while ( v33 < planes.n_elems );
  }
  if ( (setT **)point_indizes.elems != &vertices )
  {
    if ( point_indizes.elems != nullptr )
      free(data: point_indizes.elems);
    point_indizes.elems = nullptr;
    point_indizes.memsize = 0;
  }
  point_indizes.n_elems = 0;
  if ( (IVP_U_Vector<IVP_SB_PS_DUMMY> *)planes.elems != &point_indizes && planes.elems != nullptr )
    free(data: planes.elems);
  return v31;
}

//------------------------------------------------------------------------------
// Address: 0x10046960
// Name: protected: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge_internal(class IVP_U_Vector<class IVP_U_Point> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_Compact_Ledge *__usercall IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge_internal@<eax>(
        int a1@<ebp>,
        IVP_U_Vector<IVP_U_Point> *points_in)
{
  IVP_U_Vector<IVP_U_Point> *v2; // edi
  int n_elems; // eax
  char *v4; // esi
  double *v5; // esi
  IVP_U_Point *v6; // edi
  unsigned int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // edi
  long double *v11; // esi
  int v12; // eax
  char *v13; // esi
  int v14; // esi
  int v15; // ecx
  double *v16; // eax
  char *v17; // edi
  char *v18; // edx
  char *v19; // esi
  double v20; // st7
  double *v21; // eax
  char *v22; // edi
  char *v23; // edx
  char *v24; // edx
  double v25; // st7
  int v26; // edi
  IVP_U_Point *v27; // esi
  int v28; // eax
  _DWORD *v29; // ecx
  int v30; // esi
  int v31; // edi
  int v32; // xmm0_4
  int v33; // xmm1_4
  unsigned int v34; // eax
  float *elem; // eax
  int v36; // esi
  char v38[12]; // [esp+18h] [ebp-16Ch] BYREF
  __int64 flags_244; // [esp+118h] [ebp-6Ch] OVERLAPPED BYREF
  int v40; // [esp+120h] [ebp-64h]
  int v41; // [esp+134h] [ebp-50h] BYREF
  _DWORD v42[2]; // [esp+138h] [ebp-4Ch] BYREF
  _BYTE curlong[20]; // [esp+140h] [ebp-44h] OVERLAPPED
  char *j; // [esp+154h] [ebp-30h] BYREF
  long double *points2; // [esp+158h] [ebp-2Ch] BYREF
  IVP_Compact_Ledge *res; // [esp+15Ch] [ebp-28h]
  IVP_BOOL skip_point; // [esp+160h] [ebp-24h]
  int totlong; // [esp+164h] [ebp-20h]
  char *use_list; // [esp+168h] [ebp-1Ch]
  char *skip_list; // [esp+16Ch] [ebp-18h]
  int i; // [esp+170h] [ebp-14h] BYREF
  int *v52; // [esp+174h] [ebp-10h]
  int dest; // [esp+178h] [ebp-Ch] BYREF
  IVP_U_Vector<IVP_U_Point> points; // [esp+17Ch] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+184h] [ebp+0h]

  dest = a1;
  *(_DWORD *)&points.memsize = retaddr;
  v2 = points_in;
  n_elems = points_in->n_elems;
  i = (unsigned __int16)n_elems;
  if ( n_elems != 0 )
    v52 = (int *)p_malloc(size: 4 * n_elems);
  else
    v52 = nullptr;
  v4 = _calloc_crt(nelem: 4 * points_in->n_elems, size: 8);
  *(_DWORD *)&curlong[12] = v4;
  IVP_VHash::IVP_VHash(this: (IVP_VHash *)v42, size_i: 1024);
  v42[0] = &IVP_I_FPoint_VHash::`vftable';
  totlong = 0;
  if ( points_in->n_elems != 0 )
  {
    v5 = (double *)(v4 + 16);
    while ( 1 )
    {
      v6 = (IVP_U_Point *)v2->elems[totlong];
      v7 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)v42, point: v6);
      if ( IVP_VHash::find_elem(this: (IVP_VHash *)v42, elem: v6, hash_index: v7) == nullptr )
      {
        v8 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)v42, point: v6);
        IVP_VHash::add_elem(this: (IVP_VHash *)v42, elem: v6, hash_index: v8);
        if ( HIWORD(i) >= (unsigned __int16)i )
          IVP_U_Vector_Base::increment_mem(this: (IVP_U_Vector_Base *)&i);
        v52[HIWORD(i)] = (int)v6;
        ++HIWORD(i);
        *(v5 - 2) = v6->k[0];
        *(v5 - 1) = v6->k[1];
        *v5 = v6->k[2];
        v5 += 3;
      }
      v9 = points_in->n_elems;
      if ( ++totlong >= v9 )
        break;
      v2 = points_in;
    }
  }
  IVP_point_hash::~IVP_point_hash(this: (IVP_I_Point_VHash *)v42);
  v10 = HIWORD(i);
  totlong = HIWORD(i);
  skip_point = (IVP_BOOL)_calloc_crt(nelem: HIWORD(i), size: 1);
  v11 = nullptr;
  res = (IVP_Compact_Ledge *)_calloc_crt(nelem: v10, size: 1);
  *(_DWORD *)&curlong[16] = 0;
  v41 = 1;
  *(_QWORD *)curlong = 0x3D71979980000000LL;
  while ( 1 )
  {
    sprintf(string: v38, format: "qhull Qs Pp C-0 W1e-14 E1.0e-6");
    if ( v41 != 0 )
    {
      if ( v11 != nullptr )
        qh_freeqhull(allmem: 0);
      v12 = qh_new_qhull(
              dim: 3,
              numpoints: v10,
              points: *(long double **)&curlong[12],
              ismalloc: 0,
              qhull_cmd: v38,
              outfile: nullptr,
              errfile: nullptr);
      points2 = (long double *)1;
      if ( v12 == 0 )
        goto LABEL_24;
      v11 = points2;
    }
    if ( IVP_BetterDebugmanager::is_debug_enabled(this: &ivp_debugmanager, class_id: IVP_DM_SURBUILD_POINTSOUP) != IVP_FALSE )
      IVP_BetterDebugmanager::dprint(
        this: &ivp_debugmanager,
        class_id: IVP_DM_SURBUILD_POINTSOUP,
        formatstring: "*** Qhull failed. Retrying with different parameters.\n");
    sprintf(string: v38, format: "qhull Qs QJ%G C-0 Pp W1e-14 E1.0e-18", *(double *)curlong);
    if ( v11 != nullptr )
      qh_freeqhull(allmem: 0);
    points2 = (long double *)1;
    if ( qh_new_qhull(
           dim: 3,
           numpoints: v10,
           points: *(long double **)&curlong[12],
           ismalloc: 0,
           qhull_cmd: v38,
           outfile: nullptr,
           errfile: nullptr) != 0 )
    {
      *(double *)curlong = (*(double *)curlong + 9.999999960041972e-13) * 1.200000047683716;
      v41 = 0;
      goto LABEL_54;
    }
LABEL_24:
    j = nullptr;
    memset(dst: (unsigned __int8 *)res, value: 0, count: v10);
    v13 = (char *)skip_point;
    memset(dst: (unsigned __int8 *)skip_point, value: 0, count: v10);
    *(_DWORD *)&curlong[16] = IVP_SurfaceBuilder_Pointsoup::try_to_build_convex_ledge_from_qhull_result(
                                points: (IVP_U_Vector<IVP_U_Point> *)&i,
                                skip_point: (IVP_BOOL *)&j,
                                skip_list: v13,
                                use_list: (char *)res);
    if ( *(_DWORD *)&curlong[16] != 0 )
      break;
    v14 = 0;
    v15 = 0;
    skip_list = nullptr;
    if ( v10 >= 4 )
    {
      v16 = *(double **)&curlong[12];
      v17 = (char *)res - skip_point;
      v18 = (char *)(*(_DWORD *)&curlong[12] + 16);
      use_list = (char *)(*(_DWORD *)&curlong[12] + 16);
      for ( j = (char *)res - skip_point; ; v17 = j )
      {
        if ( v17[v15 + skip_point] == 0 || *(_BYTE *)(v15 + skip_point) != 0 )
        {
          v14 = (int)skip_list;
        }
        else
        {
          v19 = skip_list;
          *v16 = *((double *)v18 - 2);
          v14 = (int)(v19 + 1);
          v20 = *((double *)v18 - 1);
          skip_list = (char *)v14;
          v16[1] = v20;
          v16 += 3;
          *(v16 - 1) = *(double *)v18;
          v52[v14 - 1] = v52[v15];
          v18 = use_list;
        }
        if ( *((_BYTE *)&res->c_point_offset + v15 + 1) != 0 && *(_BYTE *)(v15 + skip_point + 1) == 0 )
        {
          ++v14;
          *v16 = *((double *)v18 + 1);
          skip_list = (char *)v14;
          v16 += 3;
          *(v16 - 2) = *((double *)v18 + 2);
          *(v16 - 1) = *((double *)v18 + 3);
          v52[v14 - 1] = v52[v15 + 1];
          v18 = use_list;
        }
        if ( *((_BYTE *)&res->c_point_offset + v15 + 2) != 0 && *(_BYTE *)(v15 + skip_point + 2) == 0 )
        {
          ++v14;
          *v16 = *((double *)v18 + 4);
          skip_list = (char *)v14;
          v16 += 3;
          *(v16 - 2) = *((double *)v18 + 5);
          *(v16 - 1) = *((double *)v18 + 6);
          v52[v14 - 1] = v52[v15 + 2];
          v18 = use_list;
        }
        if ( *((_BYTE *)&res->c_point_offset + v15 + 3) != 0 && *(_BYTE *)(v15 + skip_point + 3) == 0 )
        {
          ++v14;
          *v16 = *((double *)v18 + 7);
          skip_list = (char *)v14;
          v16 += 3;
          *(v16 - 2) = *((double *)v18 + 8);
          *(v16 - 1) = *((double *)v18 + 9);
          v52[v14 - 1] = v52[v15 + 3];
          v18 = use_list;
        }
        v15 += 4;
        v18 += 96;
        use_list = v18;
        if ( v15 >= totlong - 3 )
          break;
      }
      v10 = totlong;
    }
    if ( v15 < v10 )
    {
      skip_list = (char *)(v15 + skip_point);
      use_list = (char *)(*(_DWORD *)&curlong[12] + 24 * v14 + 16);
      v21 = (double *)(*(_DWORD *)&curlong[12] + 24 * v15 + 16);
      v22 = (char *)res - skip_point;
      v23 = (char *)(v15 + skip_point);
      for ( j = (char *)res - skip_point; ; v22 = j )
      {
        if ( v22[(_DWORD)v23] != 0 && *v23 == 0 )
        {
          v24 = use_list;
          *((double *)use_list - 2) = *(v21 - 2);
          ++v14;
          v25 = *(v21 - 1);
          use_list += 24;
          *((double *)v24 - 1) = v25;
          *(double *)v24 = *v21;
          v52[v14 - 1] = v52[v15];
          v23 = skip_list;
        }
        v10 = totlong;
        ++v15;
        ++v23;
        v21 += 3;
        skip_list = v23;
        if ( v15 >= totlong )
          break;
      }
    }
    HIWORD(i) = v14;
    if ( v10 == v14 )
    {
      *(double *)curlong = (*(double *)curlong + 9.999999960041972e-13) * 1.200000047683716;
      v41 = 0;
    }
    v10 = v14;
    totlong = v14;
    if ( v14 == 3 )
    {
      *(_DWORD *)&curlong[16] = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(points: (IVP_U_Vector<IVP_U_Point> *)&i);
      goto LABEL_66;
    }
    if ( v14 <= 3 )
      goto LABEL_66;
LABEL_54:
    if ( *(double *)curlong >= 0.01999999955296516 )
      goto LABEL_66;
    v11 = points2;
  }
  IVP_VHash::IVP_VHash(this: (IVP_VHash *)v42, size_i: 1024);
  v26 = 0;
  v42[0] = &IVP_I_FPoint_VHash::`vftable';
  if ( HIWORD(i) != 0 )
  {
    do
    {
      v27 = (IVP_U_Point *)v52[v26];
      v28 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)v42, point: v27);
      IVP_VHash::add_elem(this: (IVP_VHash *)v42, elem: v27, hash_index: v28);
      ++v26;
    }
    while ( v26 < HIWORD(i) );
  }
  v29 = *(_DWORD **)&curlong[16];
  if ( 16 * (*(_DWORD *)(*(_DWORD *)&curlong[16] + 8) >> 8) / 16 - *(__int16 *)(*(_DWORD *)&curlong[16] + 12) - 1 > 0 )
  {
    v30 = 0;
    points2 = (long double *)(16 * (*(_DWORD *)(*(_DWORD *)&curlong[16] + 8) >> 8) / 16
                            - *(__int16 *)(*(_DWORD *)&curlong[16] + 12)
                            - 1);
    while ( 1 )
    {
      v31 = (int)&v29[v30] + *v29;
      v32 = *(_DWORD *)(v31 + 4);
      v33 = *(_DWORD *)(v31 + 8);
      LODWORD(flags_244) = *(_DWORD *)v31;
      HIDWORD(flags_244) = v32;
      v40 = v33;
      v34 = IVP_I_Point_VHash::point_to_index(this: (IVP_I_Point_VHash *)v42, point: (IVP_U_Point *)&flags_244);
      elem = (float *)IVP_VHash::find_elem(this: (IVP_VHash *)v42, elem: &flags_244, hash_index: v34);
      if ( elem != nullptr )
        *(float *)(v31 + 12) = elem[3];
      v30 += 4;
      points2 = (long double *)((char *)points2 - 1);
      if ( points2 == nullptr )
        break;
      v29 = *(_DWORD **)&curlong[16];
    }
  }
  IVP_point_hash::~IVP_point_hash(this: (IVP_I_Point_VHash *)v42);
LABEL_66:
  qh_freeqhull(allmem: 0);
  qh_memfreeshort(curlong: &v41, totlong: (int *)&points2);
  if ( *(_DWORD *)&curlong[12] != 0 )
    free(data: *(void **)&curlong[12]);
  if ( skip_point != IVP_FALSE )
    free(data: (void *)skip_point);
  if ( res != nullptr )
    free(data: (void *)res);
  v36 = *(_DWORD *)&curlong[16];
  if ( *(_DWORD *)&curlong[16] == 0
    && IVP_BetterDebugmanager::is_debug_enabled(this: &ivp_debugmanager, class_id: IVP_DM_SURBUILD_POINTSOUP) != IVP_FALSE )
  {
    IVP_BetterDebugmanager::dprint(
      this: &ivp_debugmanager,
      class_id: IVP_DM_SURBUILD_POINTSOUP,
      formatstring: "*** IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_template_polygon - couldn't build convex hull! Skipping object...\n");
  }
  if ( IVP_BetterDebugmanager::is_debug_enabled(this: &ivp_debugmanager, class_id: IVP_DM_SURBUILD_POINTSOUP) != IVP_FALSE )
    IVP_BetterDebugmanager::dprint(
      this: &ivp_debugmanager,
      class_id: IVP_DM_SURBUILD_POINTSOUP,
      formatstring: "*** Done with convex pointsoup.\n\n");
  if ( v52 != &dest && v52 != nullptr )
    free(data: v52);
  return (IVP_Compact_Ledge *)v36;
}

//------------------------------------------------------------------------------
// Address: 0x10046F80
// Name: public: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(class IVP_U_Vector<class IVP_U_Point> __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(
        IVP_U_Vector<IVP_U_Point> *points)
{
  unsigned int n_elems; // ecx
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  n_elems = points->n_elems;
  if ( n_elems < 3 )
    return nullptr;
  if ( n_elems == 3 )
    return IVP_SurfaceBuilder_Pointsoup::convert_triangle_to_compace_ledge(
             a1: (IVP_BOOL)&savedregs,
             p0: *(IVP_U_Point **)points->elems,
             p1: *((IVP_U_Point **)points->elems + 1),
             p2: *((IVP_U_Point **)points->elems + 2));
  return IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge_internal(
           a1: (int)&savedregs,
           points_in: points);
}
