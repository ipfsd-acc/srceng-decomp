// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_compact_builder/ivp_rot_inertia_solver.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_compact_builder\ivp_rot_inertia_solver.h"

//------------------------------------------------------------------------------
// Address: 0x10056F90
// Name: public: IVP_Compact_Ledge_Mass_Center_Solver::IVP_Compact_Ledge_Mass_Center_Solver(class IVP_U_Matrix const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge_Mass_Center_Solver *__thiscall IVP_Compact_Ledge_Mass_Center_Solver::IVP_Compact_Ledge_Mass_Center_Solver(
        IVP_Compact_Ledge_Mass_Center_Solver *this,
        const IVP_U_Matrix *transform_in)
{
  this->transform = transform_in;
  this->msum = 0.0;
  this->mzsum = 0.0;
  this->mzzsum = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056FB0
// Name: public: IVP_Compact_Ledge_Find_Mass_Center::IVP_Compact_Ledge_Find_Mass_Center(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Compact_Ledge_Find_Mass_Center *__thiscall IVP_Compact_Ledge_Find_Mass_Center::IVP_Compact_Ledge_Find_Mass_Center(
        IVP_Compact_Ledge_Find_Mass_Center *this)
{
  *(_QWORD *)&this->qsum_surface = 0;
  *(_QWORD *)&this->sum_mass.k[1] = 0;
  this->sum_mass.k[0] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056FD0
// Name: public: void IVP_Compact_Ledge_Mass_Center_Solver::integrate_triangle(class IVP_Compact_Ledge const __near *,class IVP_Compact_Triangle const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Compact_Ledge_Mass_Center_Solver::integrate_triangle(
        IVP_Compact_Ledge_Mass_Center_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_Compact_Ledge *ledge,
        const IVP_Compact_Triangle *triangle,
        int x,
        int y,
        int z)
{
  IVP_Compact_Edge *c_three_edges; // edi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  const IVP_U_Float_Point *v11; // esi
  double v12; // st6
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm7_4
  IVP_BOOL v32; // eax
  _DWORD v33[3]; // [esp-Ch] [ebp-7Ch] BYREF
  IVP_U_Point hesse2; // [esp+0h] [ebp-70h] BYREF
  IVP_U_Float_Point p1; // [esp+10h] [ebp-60h] BYREF
  IVP_U_Float_Point p0; // [esp+20h] [ebp-50h] BYREF
  IVP_U_Point vec; // [esp+30h] [ebp-40h]
  int x0; // [esp+40h] [ebp-30h]
  float v39; // [esp+44h] [ebp-2Ch]
  int v40; // [esp+48h] [ebp-28h]
  float v41; // [esp+4Ch] [ebp-24h]
  float fydz; // [esp+50h] [ebp-20h]
  IVP_BOOL three_edge_area; // [esp+54h] [ebp-1Ch]
  float area_mzzsum; // [esp+58h] [ebp-18h]
  float area_mzsum; // [esp+5Ch] [ebp-14h]
  float v46; // [esp+60h] [ebp-10h]
  float area_msum; // [esp+64h] [ebp-Ch]
  float ka; // [esp+68h] [ebp-8h]
  float retaddr; // [esp+70h] [ebp+0h]

  area_msum = a2;
  ka = retaddr;
  three_edge_area = (IVP_BOOL)this;
  c_three_edges = triangle->c_three_edges;
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: triangle->c_three_edges,
    ledge,
    out_vec: (IVP_U_Float_Point *)v33);
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)v33);
  v8 = *(float *)&v33[z];
  v9 = *(float *)&v33[y];
  v10 = fabs(v8);
  if ( fabs(v9) <= v10 )
  {
    v40 = 1;
    if ( v10 <= 0.000001 )
      v46 = 0.0;
    else
      v46 = (float)(v9 * -0.5) / v8;
    v39 = 0.0;
  }
  else
  {
    v40 = 0;
    v39 = (float)(v8 * 0.5) / v9;
    v46 = 0.0;
  }
  area_mzzsum = 0.0;
  fydz = 0.0;
  v41 = 0.0;
  for ( x0 = 3; x0 != 0; --x0 )
  {
    v11 = (const IVP_U_Float_Point *)((char *)&ledge[(unsigned __int16)*(_DWORD *)((char *)c_three_edges
                                                                                 + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                                          + ((unsigned __int8)c_three_edges
                                                                                           & 0xC)))]
                                    + ledge->c_point_offset);
    IVP_U_Matrix::vimult4(
      this: *(IVP_U_Matrix **)three_edge_area,
      p_in: (const IVP_U_Float_Point *)((char *)&ledge[(unsigned __int16)*(_DWORD *)c_three_edges] + ledge->c_point_offset),
      p_out: (IVP_U_Float_Point *)&p1.k[1]);
    IVP_U_Matrix::vimult4(this: *(IVP_U_Matrix **)three_edge_area, p_in: v11, p_out: (IVP_U_Point *)&hesse2.k[1]);
    p0.k[1] = hesse2.k[1] - p1.k[1];
    p0.k[2] = hesse2.k[2] - p1.k[2];
    p0.hesse_val = hesse2.hesse_val - p1.hesse_val;
    vec.hesse_val = fabs(p0.k[x + 1]);
    v12 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p0.k[1]) * 0.000001;
    if ( v12 <= vec.hesse_val )
    {
      v13 = 1.0 / p0.k[x + 1];
      v14 = p1.k[x + 1];
      v15 = p0.k[y + 1] * v13;
      v16 = p1.k[y + 1] - (float)(v14 * v15);
      if ( v40 != 0 )
      {
        area_mzsum = (float)(v16 * v46) * v16;
        v17 = (float)((float)(v46 * 2.0) * v16) * v15;
        v18 = (float)(v15 * v46) * v15;
      }
      else
      {
        v19 = p0.k[z + 1] * v13;
        v20 = p1.k[z + 1] - (float)(v14 * v19);
        area_mzsum = (float)((float)(v20 * v39) + v16) * v20;
        v17 = (float)((float)(v19 * v16) + (float)(v20 * v15)) + (float)((float)((float)(v39 * 2.0) * v20) * v19);
        v18 = (float)((float)(v19 * v39) + v15) * v19;
      }
      v21 = hesse2.k[x + 1];
      v22 = (float)((float)(v21 * v21) - (float)(v14 * v14)) * 0.5;
      v23 = (float)(v14 * v14) * v14;
      v24 = (float)(v21 * v21) * v21;
      v25 = v24 * v21;
      v26 = (float)(v24 - v23) * 0.33333334;
      v27 = v23 * v14;
      vec.k[2] = v23 * v14;
      v28 = v25;
      v29 = v25 * hesse2.k[x + 1];
      v30 = (float)(v28 - v27) * 0.25;
      v31 = (float)(hesse2.k[x + 1] - v14) * area_mzsum;
      vec.k[1] = v14;
      area_mzzsum = (float)((float)(v31 + (float)(v22 * v17)) + (float)(v26 * v18)) + area_mzzsum;
      fydz = (float)((float)((float)(v26 * v17) + (float)(v22 * area_mzsum)) + (float)(v30 * v18)) + fydz;
      v41 = (float)((float)((float)((float)(v29 - (float)(vec.k[2] * v14)) * 0.2) * v18)
                  + (float)((float)(v30 * v17) + (float)(v26 * area_mzsum)))
          + v41;
    }
    ++c_three_edges;
  }
  v32 = three_edge_area;
  *(double *)(three_edge_area + 8) = area_mzzsum + *(double *)(three_edge_area + 8);
  *(double *)(v32 + 16) = fydz + *(double *)(v32 + 16);
  *(double *)(v32 + 24) = v41 + *(double *)(v32 + 24);
}

//------------------------------------------------------------------------------
// Address: 0x10057370
// Name: public: void IVP_Compact_Ledge_Find_Mass_Center::integrate_triangle(class IVP_Compact_Ledge const __near *,class IVP_Compact_Triangle const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge_Find_Mass_Center::integrate_triangle(
        IVP_Compact_Ledge_Find_Mass_Center *this,
        const IVP_Compact_Ledge *ledge,
        const IVP_Compact_Triangle *triangle)
{
  float *v4; // eax
  float v5; // xmm4_4
  float v6; // xmm2_4
  float *v8; // edx
  float v9; // xmm1_4
  int v10; // esi
  float v11; // xmm7_4
  float v12; // xmm6_4
  float v13; // xmm3_4
  float v14; // xmm7_4
  float *v15; // esi
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm7_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // [esp+Ch] [ebp-4h]
  float ledgea; // [esp+18h] [ebp+8h]
  const IVP_Compact_Triangle *trianglea; // [esp+1Ch] [ebp+Ch]
  float triangleb; // [esp+1Ch] [ebp+Ch]

  v4 = (float *)((char *)&ledge[(unsigned __int16)*(_DWORD *)triangle->c_three_edges].c_point_offset
               + ledge->c_point_offset);
  v5 = v4[2];
  v6 = v4[1];
  trianglea = (const IVP_Compact_Triangle *)(((_BYTE)triangle + 4) & 0xC);
  v8 = (float *)((char *)&ledge[(unsigned __int16)*(_DWORD *)((char *)triangle->c_three_edges
                                                            + *(int *)((char *)IVP_Compact_Edge::next_table
                                                                     + (_DWORD)trianglea))].c_point_offset
               + ledge->c_point_offset);
  v9 = v8[2] - v5;
  v10 = ledge->c_point_offset
      + 16
      * (unsigned __int16)*(_DWORD *)((char *)triangle->c_three_edges
                                    + *(int *)((char *)IVP_Compact_Edge::prev_table + (_DWORD)trianglea));
  v11 = *(float *)((char *)ledge + v10 + 8);
  v12 = *(float *)((char *)&ledge->ledgetree_node_offset + v10);
  v13 = v8[1] - v6;
  ledgea = *(float *)((char *)&ledge->c_point_offset + v10) - *v4;
  v14 = v11 - v5;
  v15 = (float *)((char *)&ledge->c_point_offset + v10);
  v16 = *v8 - *v4;
  v17 = v13 * v14;
  triangleb = v14;
  v35 = v12 - v6;
  v18 = v9 * (float)(v12 - v6);
  v19 = (float)(v9 * ledgea) - (float)(v16 * triangleb);
  v20 = v6 * v19;
  v21 = (float)(v16 * v35) - (float)(v13 * ledgea);
  v22 = v17 - v18;
  v23 = (float)((float)((float)(v19 * v19) + (float)(v22 * v22)) + (float)(v21 * v21)) + this->qsum_surface;
  v24 = (float)(v20 + (float)(*v4 * v22)) + (float)(v4[2] * v21);
  v25 = this->sum_det + v24;
  this->qsum_surface = v23;
  this->sum_det = v25;
  v26 = v24 * 0.25;
  v27 = (float)((float)(v24 * 0.25) * v4[1]) + this->sum_mass.k[1];
  v28 = v4[2] * (float)(v24 * 0.25);
  v29 = *v4;
  v30 = v28 + this->sum_mass.k[2];
  this->sum_mass.k[1] = v27;
  this->sum_mass.k[2] = v30;
  this->sum_mass.k[0] = (float)(v29 * v26) + this->sum_mass.k[0];
  v31 = (float)(v26 * v8[1]) + v27;
  v32 = (float)(v26 * v8[2]) + v30;
  this->sum_mass.k[0] = (float)(*v8 * v26) + this->sum_mass.k[0];
  this->sum_mass.k[1] = v31;
  this->sum_mass.k[2] = v32;
  v33 = (float)(v26 * v15[1]) + v31;
  v34 = (float)(v26 * v15[2]) + v32;
  this->sum_mass.k[0] = (float)(*v15 * v26) + this->sum_mass.k[0];
  this->sum_mass.k[1] = v33;
  this->sum_mass.k[2] = v34;
}

//------------------------------------------------------------------------------
// Address: 0x10057550
// Name: public: void IVP_Compact_Ledge_Find_Mass_Center::integrate_ledge(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge_Find_Mass_Center::integrate_ledge(
        IVP_Compact_Ledge_Find_Mass_Center *this,
        const IVP_Compact_Ledge *ledge)
{
  int v2; // edi
  const IVP_Compact_Triangle *i; // ebx

  v2 = 0;
  for ( i = (const IVP_Compact_Triangle *)&ledge[1]; v2 < ledge->n_triangles; ++i )
  {
    IVP_Compact_Ledge_Find_Mass_Center::integrate_triangle(this, ledge, triangle: i);
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057580
// Name: public: void IVP_Compact_Ledge_Find_Mass_Center::integrate_ledges(class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Compact_Ledge_Find_Mass_Center::integrate_ledges(
        IVP_Compact_Ledge_Find_Mass_Center *this,
        IVP_U_BigVector<IVP_Compact_Ledge> *v_ledges)
{
  int i; // esi

  for ( i = v_ledges->n_elems - 1; i >= 0; --i )
    IVP_Compact_Ledge_Find_Mass_Center::integrate_ledge(this, ledge: (const IVP_Compact_Ledge *)v_ledges->elems[i]);
}

//------------------------------------------------------------------------------
// Address: 0x100575B0
// Name: public: static void IVP_Rot_Inertia_Solver::find_center_given_xyz(class IVP_U_BigVector<class IVP_Compact_Ledge> __near *,int,int,int,class IVP_U_Matrix const __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Rot_Inertia_Solver::find_center_given_xyz(
        IVP_U_BigVector<IVP_Compact_Ledge> *v_ledges,
        int x,
        int y,
        int z,
        const IVP_U_Matrix *transform,
        float *center,
        float *mass,
        float *inertia)
{
  int v8; // eax
  const IVP_Compact_Ledge *v9; // esi
  int v10; // edi
  const IVP_Compact_Triangle *v11; // ebx
  double msum; // xmm1_8
  long double v13; // xmm0_8
  float v14; // xmm2_4
  IVP_Compact_Ledge_Mass_Center_Solver solver; // [esp+0h] [ebp-24h] BYREF
  int l; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  IVP_Compact_Ledge_Mass_Center_Solver::IVP_Compact_Ledge_Mass_Center_Solver(this: &solver, transform_in: transform);
  v8 = v_ledges->n_elems - 1;
  for ( l = v8; v8 >= 0; l = v8 )
  {
    v9 = (const IVP_Compact_Ledge *)v_ledges->elems[v8];
    v10 = 0;
    v11 = (const IVP_Compact_Triangle *)&v9[1];
    if ( v9->n_triangles > 0 )
    {
      do
      {
        IVP_Compact_Ledge_Mass_Center_Solver::integrate_triangle(
          this: &solver,
          a2: COERCE_FLOAT(&savedregs),
          ledge: v9,
          triangle: v11,
          x,
          y,
          z);
        ++v10;
        ++v11;
      }
      while ( v10 < v9->n_triangles );
      v8 = l;
    }
    --v8;
  }
  msum = solver.msum;
  if ( solver.msum >= 1.000000013351432e-10 )
  {
    v13 = 1.0 / solver.msum * solver.mzzsum;
    v14 = 1.0 / solver.msum * solver.mzsum;
    *center = v14;
    *mass = msum;
    *inertia = v13;
  }
  else
  {
    *mass = 0.0;
    *center = 0.0;
    *inertia = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057690
// Name: localCalcGeomCenterAndRotInertia
// Source: json
//------------------------------------------------------------------------------
int __usercall localCalcGeomCenterAndRotInertia@<eax>(
        IVP_U_BigVector<IVP_Compact_Ledge> *all_ledges@<edi>,
        float a2@<ebp>,
        IVP_U_Float_Point *a3,
        float *a4)
{
  int i; // esi
  float v5; // xmm0_4
  float v6; // xmm0_4
  _BYTE v8[12]; // [esp+14h] [ebp-4Ch] BYREF
  IVP_U_Point ma; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Point mi; // [esp+30h] [ebp-30h] BYREF
  IVP_U_Point max_extents; // [esp+40h] [ebp-20h] BYREF
  IVP_U_Point min_extents; // [esp+50h] [ebp-10h]
  float retaddr; // [esp+60h] [ebp+0h]

  min_extents.k[1] = a2;
  min_extents.k[2] = retaddr;
  IVP_Compact_Ledge_Solver::calc_bounding_box(
    c_ledge_in: *(const IVP_Compact_Ledge **)all_ledges->elems,
    min_extents_out: (IVP_U_Point *)&max_extents.k[1],
    max_extents_out: (IVP_U_Point *)&mi.k[1]);
  for ( i = all_ledges->n_elems - 1; i > 0; --i )
  {
    IVP_Compact_Ledge_Solver::calc_bounding_box(
      c_ledge_in: (const IVP_Compact_Ledge *)all_ledges->elems[i],
      min_extents_out: (IVP_U_Point *)&ma.k[1],
      max_extents_out: (IVP_U_Point *)v8);
    IVP_U_Point::line_min(this: (IVP_U_Point *)&max_extents.k[1], p: (IVP_U_Point *)&ma.k[1]);
    IVP_U_Point::line_max(this: (IVP_U_Point *)&mi.k[1], p: (const IVP_U_Point *)v8);
  }
  IVP_U_Float_Point::set_interpolate(
    this: a3,
    p0: (IVP_U_Point *)&max_extents.k[1],
    p1: (IVP_U_Point *)&mi.k[1],
    s: 0.5);
  v5 = fsqrt(
         (float)((float)((float)(max_extents.k[2] - mi.k[2]) * (float)(max_extents.k[2] - mi.k[2]))
               + (float)((float)(max_extents.k[1] - mi.k[1]) * (float)(max_extents.k[1] - mi.k[1])))
       + (float)((float)(max_extents.hesse_val - mi.hesse_val) * (float)(max_extents.hesse_val - mi.hesse_val)));
  v6 = (float)((float)(v5 * 0.5) * (float)(v5 * 0.5)) * 0.5;
  *a4 = v6;
  a4[1] = v6;
  a4[2] = v6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10057790
// Name: localCalcMassCenterAndRotInertia
// Source: json
//------------------------------------------------------------------------------
int __usercall localCalcMassCenterAndRotInertia@<eax>(
        IVP_U_BigVector<IVP_Compact_Ledge> *all_ledges@<eax>,
        IVP_U_Point *rotation_inertia_out@<esi>,
        int a3@<ebp>,
        IVP_U_Float_Point *a4)
{
  IVP_Compact_Ledge_Find_Mass_Center *v5; // ecx
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  _BYTE v13[12]; // [esp-Ch] [ebp-8Ch] BYREF
  IVP_U_Matrix transform; // [esp+0h] [ebp-80h] BYREF
  IVP_U_Point check_center; // [esp+40h] [ebp-40h] BYREF
  float v16; // [esp+54h] [ebp-2Ch] BYREF
  float v17; // [esp+58h] [ebp-28h] BYREF
  float v18; // [esp+5Ch] [ebp-24h] BYREF
  int v19; // [esp+70h] [ebp-10h] BYREF
  _DWORD v20[2]; // [esp+74h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  v20[0] = a3;
  v20[1] = retaddr;
  IVP_U_Matrix::init(this: (IVP_U_Matrix *)v13);
  IVP_Compact_Ledge_Find_Mass_Center::IVP_Compact_Ledge_Find_Mass_Center(this: (IVP_Compact_Ledge_Find_Mass_Center *)&transform.vv.k[1]);
  IVP_Compact_Ledge_Find_Mass_Center::integrate_ledges(this: v5, v_ledges: all_ledges);
  v6 = fsqrt(check_center.k[1]);
  if ( check_center.k[2] <= (float)((float)((float)(v6 * v6) * v6) * 9.9999997e-10) )
  {
    localCalcGeomCenterAndRotInertia(all_ledges, a2: COERCE_FLOAT(v20), a3: a4, a4: rotation_inertia_out->k);
    return 0;
  }
  else
  {
    IVP_U_Matrix::init(this: (IVP_U_Matrix *)v13);
    v7 = transform.vv.k[1] * (float)(1.0 / check_center.k[2]);
    v8 = (float)(1.0 / check_center.k[2]) * transform.vv.k[2];
    v9 = transform.vv.hesse_val * (float)(1.0 / check_center.k[2]);
    a4->k[0] = v7;
    a4->k[1] = v8;
    a4->k[2] = v9;
    v16 = v7;
    v17 = v8;
    v18 = v9;
    *(__m128i *)((char *)&transform.rows[2] + 4) = _mm_load_si128((const __m128i *)&v16);
    IVP_Rot_Inertia_Solver::find_center_given_xyz(
      v_ledges: all_ledges,
      x: 0,
      y: 1,
      z: 2,
      transform: (const IVP_U_Matrix *)v13,
      center: &check_center.k[1],
      mass: (float *)&v19,
      inertia: &v16);
    IVP_Rot_Inertia_Solver::find_center_given_xyz(
      v_ledges: all_ledges,
      x: 1,
      y: 2,
      z: 0,
      transform: (const IVP_U_Matrix *)v13,
      center: &check_center.k[2],
      mass: (float *)&v19,
      inertia: &v17);
    IVP_Rot_Inertia_Solver::find_center_given_xyz(
      v_ledges: all_ledges,
      x: 2,
      y: 0,
      z: 1,
      transform: (const IVP_U_Matrix *)v13,
      center: &check_center.hesse_val,
      mass: (float *)&v19,
      inertia: &v18);
    v10 = fsqrt((float)(v18 * v18) + (float)(v16 * v16));
    v11 = fsqrt((float)(v17 * v17) + (float)(v16 * v16));
    rotation_inertia_out->k[0] = fsqrt((float)(v18 * v18) + (float)(v17 * v17));
    rotation_inertia_out->k[1] = v10;
    rotation_inertia_out->k[2] = v11;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057910
// Name: public: static enum IVP_RETURN_TYPE IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia(class IVP_Compact_Surface const __near *,class IVP_U_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia(
        const IVP_Compact_Surface *c_surface_in,
        IVP_U_Point *mass_center_out,
        IVP_U_Point *rotation_inertia_out)
{
  int v3; // esi
  IVP_U_BigVector<IVP_Compact_Ledge> all_ledges; // [esp+4h] [ebp-Ch] BYREF
  char vars0; // [esp+10h] [ebp+0h] BYREF

  all_ledges.memsize = 128;
  all_ledges.n_elems = 0;
  all_ledges.elems = (void **)p_malloc(size: 0x200u);
  IVP_Compact_Ledge_Solver::get_all_ledges(surface: c_surface_in, all_ledges_out: &all_ledges);
  v3 = localCalcMassCenterAndRotInertia(&all_ledges, rotation_inertia_out, a3: (int)&vars0, a4: mass_center_out);
  if ( (char *)all_ledges.elems != &vars0 && all_ledges.elems != nullptr )
    free(data: all_ledges.elems);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10057980
// Name: public: static enum IVP_RETURN_TYPE IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia_fast(class IVP_Compact_Surface const __near *,class IVP_U_Point __near *,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IVP_Rot_Inertia_Solver::calc_mass_center_and_rotation_inertia_fast(
        const IVP_Compact_Surface *c_surface_in,
        IVP_U_Point *mass_center_out,
        IVP_U_Point *rotation_inertia_out)
{
  int v3; // esi
  IVP_U_BigVector<IVP_Compact_Ledge> all_ledges; // [esp+8h] [ebp-Ch] BYREF
  char vars0; // [esp+14h] [ebp+0h] BYREF

  all_ledges.memsize = 128;
  all_ledges.n_elems = 0;
  all_ledges.elems = (void **)p_malloc(size: 0x200u);
  IVP_Compact_Ledge_Solver::get_all_ledges(surface: c_surface_in, all_ledges_out: &all_ledges);
  v3 = localCalcGeomCenterAndRotInertia(
         &all_ledges,
         a2: COERCE_FLOAT(&vars0),
         a3: mass_center_out,
         a4: rotation_inertia_out->k);
  if ( (char *)all_ledges.elems != &vars0 && all_ledges.elems != nullptr )
    free(data: all_ledges.elems);
  return v3;
}
