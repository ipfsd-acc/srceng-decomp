// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_surbuild_halfspacesoup.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_compact_builder\ivp_surbuild_halfspacesoup.h"

//------------------------------------------------------------------------------
// Address: 0x10045A20
// Name: private: static class IVP_U_Point __near * IVP_SurfaceBuilder_Halfspacesoup::insert_point_into_list(class IVP_U_Point __near *,class IVP_U_Vector<class IVP_U_Point> __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Point *__cdecl IVP_SurfaceBuilder_Halfspacesoup::insert_point_into_list(
        IVP_U_Point *point,
        IVP_U_Vector<IVP_U_Point> *points,
        float quad_threshold)
{
  unsigned __int16 n_elems; // dx
  int v4; // eax
  void **elems; // ecx
  void *v6; // edi

  n_elems = points->n_elems;
  v4 = 0;
  if ( n_elems != 0 )
  {
    elems = points->elems;
    while ( 1 )
    {
      v6 = *elems;
      if ( quad_threshold > (float)((float)((float)((float)(point->k[1] - *((float *)*elems + 1))
                                                  * (float)(point->k[1] - *((float *)*elems + 1)))
                                          + (float)((float)(point->k[0] - *(float *)*elems)
                                                  * (float)(point->k[0] - *(float *)*elems)))
                                  + (float)((float)(point->k[2] - *((float *)*elems + 2))
                                          * (float)(point->k[2] - *((float *)*elems + 2)))) )
        break;
      ++v4;
      ++elems;
      if ( v4 >= points->n_elems )
        goto LABEL_5;
    }
    free(data: point);
    return (IVP_U_Point *)v6;
  }
  else
  {
LABEL_5:
    if ( n_elems >= points->memsize )
      IVP_U_Vector_Base::increment_mem(this: points);
    points->elems[points->n_elems++] = point;
    return point;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045AC0
// Name: public: static int IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_points(class IVP_Halfspacesoup __near *,float,class IVP_U_Vector<class IVP_U_Point> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __usercall IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_points@<eax>(
        int a1@<ebp>,
        IVP_Halfspacesoup *halfspaces,
        float pointmerge_threshold,
        IVP_U_Vector<IVP_U_Point> *points)
{
  int n_elems; // eax
  int v5; // edx
  float v6; // ecx
  int v7; // esi
  int v8; // eax
  void **elems; // edx
  IVP_U_Point *v10; // eax
  int v11; // edx
  int v12; // ecx
  float *v13; // eax
  int v14; // edi
  void **v15; // ecx
  float *v16; // edx
  int v17; // eax
  float **v18; // ecx
  unsigned __int16 v19; // cx
  int v20; // edx
  __int64 v22; // [esp+14h] [ebp-3Ch] BYREF
  _BYTE quad_threshold[20]; // [esp+1Ch] [ebp-34h] OVERLAPPED
  int v24; // [esp+30h] [ebp-20h]
  float v25; // [esp+34h] [ebp-1Ch]
  float threshold; // [esp+38h] [ebp-18h]
  int v27; // [esp+3Ch] [ebp-14h]
  IVP_U_Point *p1; // [esp+40h] [ebp-10h]
  int k; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  k = a1;
  i = retaddr;
  n_elems = halfspaces->n_elems;
  *(float *)&quad_threshold[16] = pointmerge_threshold * pointmerge_threshold;
  if ( n_elems != 0 )
  {
    v5 = 1;
    v27 = 0;
    v24 = 1;
    do
    {
      p1 = (IVP_U_Point *)v5;
      if ( v5 < n_elems )
      {
        LODWORD(v6) = v5 + 1;
        LODWORD(v25) = v5 + 1;
        do
        {
          v7 = LODWORD(v6);
          threshold = v6;
          if ( SLODWORD(v6) < n_elems )
          {
            do
            {
              if ( IVP_U_Point::set_crossing(
                     this: (IVP_U_Point *)&v22,
                     h0: *(IVP_U_Hesse **)((char *)halfspaces->elems + v27),
                     h1: (IVP_U_Hesse *)halfspaces->elems[(_DWORD)p1],
                     h2: (IVP_U_Hesse *)halfspaces->elems[v7]) != IVP_FAULT )
              {
                v8 = 0;
                if ( halfspaces->n_elems != 0 )
                {
                  elems = halfspaces->elems;
                  while ( (float)((float)((float)((float)(*((float *)*elems + 1) * *((float *)&v22 + 1))
                                                + (float)(*(float *)*elems * *(float *)&v22))
                                        + (float)(*((float *)*elems + 2) * *(float *)quad_threshold))
                                + *((float *)*elems + 3)) >= -0.000099999997 )
                  {
                    ++v8;
                    ++elems;
                    if ( v8 >= halfspaces->n_elems )
                      goto LABEL_11;
                  }
                }
                else
                {
LABEL_11:
                  v10 = (IVP_U_Point *)p_malloc(size: 0x10u);
                  if ( v10 != nullptr )
                  {
                    *(_QWORD *)v10->k = v22;
                    *(_QWORD *)&v10->k[2] = *(_QWORD *)quad_threshold;
                  }
                  else
                  {
                    v10 = nullptr;
                  }
                  IVP_SurfaceBuilder_Halfspacesoup::insert_point_into_list(
                    point: v10,
                    points,
                    quad_threshold: *(float *)&quad_threshold[16]);
                }
              }
              v11 = halfspaces->n_elems;
              v7 = LODWORD(threshold) + 1;
              LODWORD(threshold) = v7;
            }
            while ( v7 < v11 );
            v6 = v25;
            v5 = v24;
          }
          n_elems = halfspaces->n_elems;
          ++LODWORD(v6);
          p1 = (IVP_U_Point *)((char *)p1 + 1);
          v25 = v6;
        }
        while ( (int)p1 < n_elems );
      }
      n_elems = halfspaces->n_elems;
      v27 += 4;
      v24 = ++v5;
    }
    while ( v5 - 1 < n_elems );
  }
  v12 = 0;
  v27 = 0;
  if ( points->n_elems != 0 )
  {
    do
    {
      v13 = (float *)points->elems[v12];
      v14 = points->n_elems - 1;
      v25 = *(float *)&v13;
      v24 = v14;
      if ( v14 > v12 )
      {
        do
        {
          v15 = points->elems;
          v16 = (float *)v15[v14];
          if ( *(float *)&quad_threshold[16] > (float)((float)((float)((float)(v13[1] - v16[1])
                                                                     * (float)(v13[1] - v16[1]))
                                                             + (float)((float)(*v13 - *v16) * (float)(*v13 - *v16)))
                                                     + (float)((float)(v13[2] - v16[2]) * (float)(v13[2] - v16[2]))) )
          {
            v17 = points->n_elems - 1;
            if ( points->n_elems != 0 )
            {
              v18 = (float **)&v15[v17];
              do
              {
                if ( *v18 == v16 )
                  break;
                --v18;
                --v17;
              }
              while ( v17 >= 0 );
            }
            v19 = points->n_elems - 1;
            points->n_elems = v19;
            if ( v17 < v19 )
            {
              do
              {
                points->elems[v17] = points->elems[v17 + 1];
                ++v17;
              }
              while ( v17 < points->n_elems );
              v14 = v24;
            }
            free(data: v16);
            v13 = (float *)LODWORD(v25);
          }
          v24 = --v14;
        }
        while ( v14 > v27 );
        v12 = v27;
      }
      v20 = points->n_elems;
      v27 = ++v12;
    }
    while ( v12 < v20 );
  }
  return points->n_elems;
}

//------------------------------------------------------------------------------
// Address: 0x10045D30
// Name: public: static class IVP_Compact_Ledge __near * IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_compact_ledge(class IVP_Halfspacesoup __near *,float)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge *__cdecl IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_compact_ledge(
        IVP_Halfspacesoup *halfspaces,
        float pointmerge_threshold)
{
  IVP_Compact_Ledge *v2; // eax
  int v3; // esi
  IVP_Compact_Ledge *v4; // edi
  IVP_U_Vector<IVP_U_Point> points; // [esp+10h] [ebp-8h] BYREF
  char vars0; // [esp+18h] [ebp+0h] BYREF

  *(_DWORD *)&points.memsize = 0;
  points.elems = nullptr;
  IVP_SurfaceBuilder_Halfspacesoup::convert_halfspacesoup_to_points(
    a1: (int)&vars0,
    halfspaces,
    pointmerge_threshold,
    &points);
  v2 = IVP_SurfaceBuilder_Pointsoup::convert_pointsoup_to_compact_ledge(&points);
  v3 = points.n_elems - 1;
  v4 = v2;
  if ( points.n_elems != 0 )
  {
    do
      free(data: points.elems[v3--]);
    while ( v3 >= 0 );
  }
  if ( (char *)points.elems != &vars0 && points.elems != nullptr )
    free(data: points.elems);
  return v4;
}
