// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_ray_solver.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_collision\ivp_ray_solver.h"

//------------------------------------------------------------------------------
// Address: 0x1007D1A0
// Name: public: IVP_Ray_Solver_Os::IVP_Ray_Solver_Os(class IVP_Ray_Solver __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Ray_Solver_Os *__thiscall IVP_Ray_Solver_Os::IVP_Ray_Solver_Os(
        IVP_Ray_Solver_Os *this,
        IVP_Ray_Solver *so,
        IVP_Real_Object *obj)
{
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v5; // ebx
  float ray_length; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  this->object = obj;
  this->hit_listener = so;
  if ( obj->cache_object == nullptr )
    obj->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                          this: obj->environment->cache_object_manager,
                          object: obj);
  if ( *(_BYTE *)&obj->flags < 8 )
  {
    cache_object = obj->cache_object;
    if ( obj->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v5 = obj->cache_object;
  IVP_Cache_Object::transform_position_to_object_coords(
    this: v5,
    P_world: &so->ray_start_point,
    P_object_out: &this->ray_start_point);
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: v5,
    P_world: &so->ray_direction,
    P_object_out: &this->ray_direction);
  ray_length = so->ray_length;
  this->ray_length = ray_length;
  v7 = (float)(this->ray_direction.k[2] * ray_length) + this->ray_start_point.k[2];
  v8 = (float)(this->ray_direction.k[1] * ray_length) + this->ray_start_point.k[1];
  this->ray_end_point.k[0] = (float)(this->ray_direction.k[0] * ray_length) + this->ray_start_point.k[0];
  this->ray_end_point.k[1] = v8;
  this->ray_end_point.k[2] = v7;
  v9 = this->ray_start_point.k[1];
  v10 = this->ray_start_point.k[2];
  this->ray_center_point.k[0] = this->ray_start_point.k[0];
  this->ray_center_point.k[1] = v9;
  this->ray_center_point.k[2] = v10;
  v11 = this->ray_length * 0.5;
  v12 = (float)(this->ray_direction.k[1] * v11) + this->ray_center_point.k[1];
  v13 = (float)(this->ray_direction.k[2] * v11) + this->ray_center_point.k[2];
  this->ray_center_point.k[0] = (float)(this->ray_direction.k[0] * v11) + this->ray_center_point.k[0];
  this->ray_center_point.k[1] = v12;
  this->ray_center_point.k[2] = v13;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007D2C0
// Name: public: void IVP_Ray_Solver::check_ray_against_ball(class IVP_Ball __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Ray_Solver::check_ray_against_ball(IVP_Ray_Solver *this@<ecx>, int a2@<ebp>, IVP_Ball *ball)
{
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v5; // eax
  float v6; // xmm4_4
  float v7; // xmm5_4
  float extra_radius; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18[3]; // [esp+18h] [ebp-5Ch] BYREF
  IVP_U_Point solution; // [esp+24h] [ebp-50h] BYREF
  IVP_U_Point equ; // [esp+34h] [ebp-40h]
  IVP_U_Float_Point center_ws; // [esp+44h] [ebp-30h] BYREF
  float v22; // [esp+64h] [ebp-10h]
  int v23; // [esp+68h] [ebp-Ch]
  void *v24; // [esp+6Ch] [ebp-8h]
  void *retaddr; // [esp+74h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  if ( ball->cache_object == nullptr )
    ball->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                           this: ball->environment->cache_object_manager,
                           object: ball);
  if ( *(_BYTE *)&ball->flags < 8 )
  {
    cache_object = ball->cache_object;
    if ( ball->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v5 = ball->cache_object;
  v6 = v5->m_world_f_object.vv.k[1];
  v7 = v5->m_world_f_object.vv.k[2];
  extra_radius = ball->extra_radius;
  v9 = this->ray_start_point.k[0] - v5->m_world_f_object.vv.k[0];
  v10 = this->ray_start_point.k[1] - v6;
  equ.k[1] = v5->m_world_f_object.vv.k[0];
  equ.k[2] = v6;
  v11 = this->ray_start_point.k[2];
  equ.hesse_val = v7;
  v12 = v11 - v7;
  v13 = extra_radius * extra_radius;
  v14 = (float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v12 * v12);
  if ( v13 <= v14 )
  {
    solution.k[1] = 1.0;
    solution.k[2] = (float)((float)((float)(this->ray_direction.k[1] * v10) + (float)(this->ray_direction.k[0] * v9))
                          + (float)(this->ray_direction.k[2] * v12))
                  * 2.0;
    solution.hesse_val = v14 - v13;
    IVP_U_Point::solve_quadratic_equation_accurate(this: (IVP_U_Point *)v18, p: (IVP_U_Point *)&solution.k[1]);
    if ( v18[0] >= 0.0 )
    {
      v15 = v18[1];
      v22 = v18[1];
      if ( v18[1] >= 0.0 || (v15 = v18[2], v22 = v18[2], v18[2] >= 0.0) )
      {
        v16 = (float)((float)(this->ray_direction.k[1] * v15) + this->ray_start_point.k[1]) - equ.k[2];
        v17 = (float)((float)(this->ray_direction.k[2] * v15) + this->ray_start_point.k[2]) - equ.hesse_val;
        center_ws.k[1] = (float)((float)(this->ray_direction.k[0] * v15) + this->ray_start_point.k[0]) - equ.k[1];
        center_ws.k[2] = v16;
        center_ws.hesse_val = v17;
        if ( IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&center_ws.k[1]) != 1 )
        {
          center_ws.k[1] = 1.0;
          center_ws.k[2] = 0.0;
          center_ws.hesse_val = 0.0;
        }
        ((void (__thiscall *)(IVP_Ray_Solver *, IVP_Ball *, _DWORD, _DWORD, _DWORD, float *))this->add_hit_object)(
          a1: this,
          a2: ball,
          a3: 0,
          a4: 0,
          a5: LODWORD(v22),
          a6: &center_ws.k[1]);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D4A0
// Name: public: void IVP_Ray_Solver_Group::check_ray_group_against_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Ray_Solver_Group::check_ray_group_against_object(
        IVP_Ray_Solver_Group *this,
        IVP_SurfaceManager *object)
{
  IVP_RAY_SOLVER_FLAGS ray_flags; // eax
  int i; // esi
  int v6; // esi
  IVP_SurfaceManager *v7; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF
  IVP_SurfaceManager *surman; // [esp+10h] [ebp+8h]

  if ( object == nullptr
    || (((ray_flags = (*this->ray_solvers)->ray_flags) & 1) == 0 || object[7].__vftable == nullptr)
    && ((ray_flags & 2) == 0 || ((int)object[17].__vftable & 0x10) != 0)
    && ((ray_flags & 4) == 0 || ((int)object[17].__vftable & 0x10) == 0) )
  {
    if ( object[1].__vftable == (IVP_SurfaceManager_vtbl *)2 )
    {
      v6 = this->n_ray_solvers - 1;
      v7 = (IVP_SurfaceManager *)object[33].__vftable;
      surman = v7;
      if ( v6 >= 0 )
      {
        while ( 1 )
        {
          v7->insert_all_ledges_hitting_ray(this: v7, a2: this->ray_solvers[v6--], a3: (IVP_Real_Object *)object);
          if ( v6 < 0 )
            break;
          v7 = surman;
        }
      }
    }
    else if ( object[1].__vftable == (IVP_SurfaceManager_vtbl *)3 )
    {
      for ( i = this->n_ray_solvers - 1; i >= 0; --i )
        IVP_Ray_Solver::check_ray_against_ball(
          this: this->ray_solvers[i],
          a2: (int)&savedregs,
          ball: (IVP_Ball *)object);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D530
// Name: public: IVP_Ray_Solver_Group::IVP_Ray_Solver_Group(int,class IVP_Ray_Solver __near * __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Ray_Solver_Group *__thiscall IVP_Ray_Solver_Group::IVP_Ray_Solver_Group(
        IVP_Ray_Solver_Group *this,
        int n_ray_solvers_,
        IVP_Ray_Solver **ray_solvers_)
{
  float v3; // xmm5_4
  IVP_Ray_Solver_Group *result; // eax
  int v5; // edx
  float v6; // xmm3_4
  float v7; // xmm2_4
  IVP_Ray_Solver *v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  int v14; // edx
  float v15; // xmm6_4
  IVP_Ray_Solver *v16; // ecx

  v3 = 0.0;
  result = this;
  v5 = 0;
  this->ray_solvers = ray_solvers_;
  this->n_ray_solvers = n_ray_solvers_;
  *(_QWORD *)&this->center_ws.k[1] = 0;
  this->center_ws.k[0] = 0.0;
  if ( n_ray_solvers_ > 0 )
  {
    v6 = 0.0;
    v7 = 0.0;
    do
    {
      v8 = ray_solvers_[v5];
      v9 = v8->ray_center_point.k[1] + v7;
      ++v5;
      v10 = v8->ray_center_point.k[2] + v6;
      result->center_ws.k[0] = result->center_ws.k[0] + v8->ray_center_point.k[0];
      v7 = v9;
      result->center_ws.k[1] = v9;
      v6 = v10;
      result->center_ws.k[2] = v10;
    }
    while ( v5 < n_ray_solvers_ );
  }
  v11 = 1.0 / (float)n_ray_solvers_;
  v12 = result->center_ws.k[0] * v11;
  v13 = result->center_ws.k[1] * v11;
  v14 = 0;
  v15 = v11 * result->center_ws.k[2];
  result->center_ws.k[0] = v12;
  result->center_ws.k[1] = v13;
  for ( result->center_ws.k[2] = v15; v14 < n_ray_solvers_; ++v14 )
  {
    v16 = ray_solvers_[v14];
    if ( (float)((float)((float)((float)(v16->ray_start_point.k[1] - v13) * (float)(v16->ray_start_point.k[1] - v13))
                       + (float)((float)(v16->ray_start_point.k[0] - v12) * (float)(v16->ray_start_point.k[0] - v12)))
               + (float)((float)(v16->ray_start_point.k[2] - v15) * (float)(v16->ray_start_point.k[2] - v15))) > v3 )
      v3 = (float)((float)((float)(v16->ray_start_point.k[1] - v13) * (float)(v16->ray_start_point.k[1] - v13))
                 + (float)((float)(v16->ray_start_point.k[0] - v12) * (float)(v16->ray_start_point.k[0] - v12)))
         + (float)((float)(v16->ray_start_point.k[2] - v15) * (float)(v16->ray_start_point.k[2] - v15));
    if ( (float)((float)((float)((float)(v16->ray_end_point.k[1] - v13) * (float)(v16->ray_end_point.k[1] - v13))
                       + (float)((float)(v16->ray_end_point.k[0] - v12) * (float)(v16->ray_end_point.k[0] - v12)))
               + (float)((float)(v16->ray_end_point.k[2] - v15) * (float)(v16->ray_end_point.k[2] - v15))) > v3 )
      v3 = (float)((float)((float)(v16->ray_end_point.k[1] - v13) * (float)(v16->ray_end_point.k[1] - v13))
                 + (float)((float)(v16->ray_end_point.k[0] - v12) * (float)(v16->ray_end_point.k[0] - v12)))
         + (float)((float)(v16->ray_end_point.k[2] - v15) * (float)(v16->ray_end_point.k[2] - v15));
  }
  result->radius = fsqrt(v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D670
// Name: public: virtual void IVP_Ray_Solver_Min::add_hit_object(class IVP_Real_Object __near *,class IVP_Compact_Ledge const __near *,class IVP_Compact_Triangle const __near *,float,class IVP_U_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Ray_Solver_Min::add_hit_object(
        IVP_Ray_Solver_Min *this,
        IVP_Real_Object *object,
        const IVP_Compact_Ledge *compact_ledge,
        const IVP_Compact_Triangle *compact_triangle,
        float hit_dist,
        IVP_U_Point *hit_sur_vec_os)
{
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( hit_dist < this->min_dist )
  {
    this->ray_hit.hit_real_object = object;
    this->ray_hit.hit_compact_triangle = compact_triangle;
    this->min_dist = hit_dist;
    this->ray_hit.hit_compact_ledge = compact_ledge;
    this->ray_hit.hit_distance = hit_dist;
    v6 = hit_sur_vec_os->k[1];
    v7 = hit_sur_vec_os->k[2];
    this->ray_hit.hit_surface_direction_os.k[0] = hit_sur_vec_os->k[0];
    this->ray_hit.hit_surface_direction_os.k[1] = v6;
    this->ray_hit.hit_surface_direction_os.k[2] = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D6D0
// Name: public: IVP_Ray_Solver::IVP_Ray_Solver(class IVP_Ray_Solver_Template const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Ray_Solver *__thiscall IVP_Ray_Solver::IVP_Ray_Solver(IVP_Ray_Solver *this, const IVP_Ray_Solver_Template *templ)
{
  IVP_Ray_Solver *result; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float ray_length; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4

  result = this;
  this->__vftable = (IVP_Ray_Solver_vtbl *)&IVP_Ray_Hit_Listener::`vftable';
  v3 = templ->ray_normized_direction.k[1];
  v4 = templ->ray_normized_direction.k[2];
  this->ray_direction.k[0] = templ->ray_normized_direction.k[0];
  this->ray_direction.k[1] = v3;
  this->ray_direction.k[2] = v4;
  v5 = templ->ray_start_point.k[1];
  v6 = templ->ray_start_point.k[2];
  this->ray_start_point.k[0] = templ->ray_start_point.k[0];
  this->ray_start_point.k[1] = v5;
  this->ray_start_point.k[2] = v6;
  this->ray_length = templ->ray_length;
  this->ray_flags = templ->ray_flags;
  v7 = this->ray_start_point.k[1];
  v8 = this->ray_start_point.k[2];
  this->ray_center_point.k[0] = this->ray_start_point.k[0];
  this->ray_center_point.k[1] = v7;
  this->ray_center_point.k[2] = v8;
  v9 = this->ray_direction.k[2];
  v10 = this->ray_direction.k[0];
  v11 = this->ray_length * 0.5;
  this->ray_center_point.k[1] = (float)(this->ray_direction.k[1] * v11) + this->ray_center_point.k[1];
  this->ray_center_point.k[0] = (float)(v10 * v11) + this->ray_center_point.k[0];
  this->ray_center_point.k[2] = (float)(v9 * v11) + this->ray_center_point.k[2];
  ray_length = this->ray_length;
  v13 = (float)(this->ray_direction.k[1] * ray_length) + this->ray_start_point.k[1];
  v14 = (float)(result->ray_direction.k[2] * ray_length) + result->ray_start_point.k[2];
  this->ray_end_point.k[0] = (float)(this->ray_direction.k[0] * ray_length) + this->ray_start_point.k[0];
  this->ray_end_point.k[1] = v13;
  this->ray_end_point.k[2] = v14;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007D7C0
// Name: public: enum IVP_BOOL IVP_Ray_Solver_Os::check_ray_against_compact_ledge_os(class IVP_Compact_Ledge const __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge IVP_Ray_Solver_Os::check_ray_against_compact_ledge_os@<eax>(
        IVP_Ray_Solver_Os *this@<ecx>,
        int a2@<ebp>,
        const IVP_Compact_Ledge *ledge_to_compare)
{
  int n_triangles; // eax
  int v5; // eax
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  int v10; // eax
  float v11; // xmm0_4
  int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16; // eax
  int i; // ecx
  int v18; // ecx
  bool v19; // sf
  int v20; // [esp+8h] [ebp-6Ch]
  int v21; // [esp+Ch] [ebp-68h]
  int v22; // [esp+10h] [ebp-64h]
  int v23; // [esp+14h] [ebp-60h]
  IVP_Unscaled_QR_Result v24; // [esp+18h] [ebp-5Ch] BYREF
  _DWORD v25[3]; // [esp+28h] [ebp-4Ch] BYREF
  IVP_U_Point intersect_point; // [esp+34h] [ebp-40h] BYREF
  IVP_Unscaled_QR_Result qr; // [esp+44h] [ebp-30h] BYREF
  IVP_U_Point hesse_vec_os; // [esp+54h] [ebp-20h]
  int s; // [esp+64h] [ebp-10h]
  int tri_cnt; // [esp+68h] [ebp-Ch]
  const IVP_Compact_Edge *edge; // [esp+6Ch] [ebp-8h]
  const IVP_Compact_Edge *retaddr; // [esp+74h] [ebp+0h]

  tri_cnt = a2;
  edge = retaddr;
  n_triangles = ledge_to_compare->n_triangles;
  LODWORD(hesse_vec_os.k[2]) = n_triangles;
  if ( n_triangles == 2 )
  {
    LODWORD(hesse_vec_os.hesse_val) = &ledge_to_compare[1].___u1;
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: (const IVP_Compact_Edge *)&ledge_to_compare[1].___u1,
      ledge: ledge_to_compare,
      out_vec: (IVP_U_Float_Point *)&qr.checks[1]);
    v5 = ledge_to_compare->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)LODWORD(hesse_vec_os.hesse_val);
    v6 = (float)((float)(*(float *)((char *)&ledge_to_compare->ledgetree_node_offset + v5) * qr.checks[2])
               + (float)(*(float *)((char *)&ledge_to_compare->c_point_offset + v5) * qr.checks[1]))
       + (float)(*(float *)((char *)ledge_to_compare + v5 + 8) * qr.scale);
    v7 = (float)((float)((float)(this->ray_start_point.k[1] * qr.checks[2])
                       + (float)(qr.checks[1] * this->ray_start_point.k[0]))
               + (float)(this->ray_start_point.k[2] * qr.scale))
       - v6;
    v8 = (float)((float)((float)(this->ray_end_point.k[1] * qr.checks[2])
                       + (float)(this->ray_end_point.k[0] * qr.checks[1]))
               + (float)(this->ray_end_point.k[2] * qr.scale))
       - v6;
    hesse_vec_os.k[2] = v7;
    if ( (float)(v8 * v7) < 0.0 )
    {
      *(float *)&s = v7 / (float)(v7 - v8);
      IVP_U_Float_Point::set_interpolate(
        this: (IVP_U_Float_Point *)v25,
        p0: &this->ray_start_point,
        p1: &this->ray_end_point,
        s: *(float *)&s);
      IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
        c_ledge: ledge_to_compare,
        tri: SLODWORD(hesse_vec_os.hesse_val),
        p_object: (const IVP_U_Point *)v25,
        result: (IVP_Unscaled_QR_Result *)&intersect_point.k[1]);
      if ( (LODWORD(intersect_point.k[1]) | LODWORD(intersect_point.k[2]) | LODWORD(intersect_point.hesse_val)) >= 0 )
      {
        if ( hesse_vec_os.k[2] < 0.0 )
        {
          qr.checks[1] = qr.checks[1] * -1.0;
          qr.checks[2] = qr.checks[2] * -1.0;
          qr.scale = qr.scale * -1.0;
        }
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&qr.checks[1]);
        ((void (__stdcall *)(IVP_Real_Object *, const IVP_Compact_Ledge *, const IVP_Compact_Ledge *, _DWORD, float *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->hit_listener->add_hit_object)(
          a1: this->object,
          a2: ledge_to_compare,
          a3: &ledge_to_compare[1],
          a4: this->ray_length * *(float *)&s,
          a5: &qr.checks[1],
          a6: v20,
          a7: v21,
          a8: v22,
          a9: v23,
          a10: LODWORD(v24.checks[0]),
          a11: LODWORD(v24.checks[1]),
          a12: LODWORD(v24.checks[2]),
          a13: LODWORD(v24.scale),
          a14: v25[0],
          a15: v25[1],
          a16: v25[2],
          a17: LODWORD(intersect_point.k[0]),
          a18: LODWORD(intersect_point.k[1]),
          a19: LODWORD(intersect_point.k[2]),
          a20: LODWORD(intersect_point.hesse_val),
          a21: LODWORD(qr.checks[0]));
        return 1;
      }
    }
    return 0;
  }
  qr.checks[1] = this->ray_direction.k[0];
  qr.checks[2] = this->ray_direction.k[1];
  qr.scale = this->ray_direction.k[2];
  hesse_vec_os.hesse_val = 0.0;
  if ( n_triangles <= 0 )
    return 0;
  s = (int)&ledge_to_compare[1].___u1;
  while ( 1 )
  {
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: (const IVP_Compact_Edge *)s,
      ledge: ledge_to_compare,
      out_vec: (IVP_U_Point *)&intersect_point.k[1]);
    if ( (float)((float)((float)(intersect_point.k[2] * qr.checks[2]) + (float)(intersect_point.k[1] * qr.checks[1]))
               + (float)(intersect_point.hesse_val * qr.scale)) <= -0.000001 )
    {
      v10 = ledge_to_compare->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)s;
      v11 = (float)((float)(*(float *)((char *)&ledge_to_compare->ledgetree_node_offset + v10) * intersect_point.k[2])
                  + (float)(*(float *)((char *)&ledge_to_compare->c_point_offset + v10) * intersect_point.k[1]))
          + (float)(*(float *)((char *)ledge_to_compare + v10 + 8) * intersect_point.hesse_val);
      if ( (float)((float)((float)((float)(this->ray_start_point.k[1] * intersect_point.k[2])
                                 + (float)(intersect_point.k[1] * this->ray_start_point.k[0]))
                         + (float)(this->ray_start_point.k[2] * intersect_point.hesse_val))
                 - v11) > 0.0 )
        break;
    }
    s += 16;
    ++LODWORD(hesse_vec_os.hesse_val);
    if ( SLODWORD(hesse_vec_os.hesse_val) >= SLODWORD(hesse_vec_os.k[2]) )
      return 0;
  }
  if ( (float)((float)((float)((float)(intersect_point.k[2] * this->ray_end_point.k[1])
                             + (float)(intersect_point.k[1] * this->ray_end_point.k[0]))
                     + (float)(intersect_point.hesse_val * this->ray_end_point.k[2]))
             - v11) > 0.0 )
    return 0;
  LODWORD(hesse_vec_os.k[2]) = ledge_to_compare->n_triangles - 1;
  if ( hesse_vec_os.k[2] < 0.0 )
    return 0;
  while ( 2 )
  {
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: (const IVP_Compact_Edge *)s,
      ledge: ledge_to_compare,
      out_vec: (IVP_U_Point *)&intersect_point.k[1]);
    if ( (float)((float)((float)(intersect_point.k[2] * qr.checks[2]) + (float)(intersect_point.k[1] * qr.checks[1]))
               + (float)(intersect_point.hesse_val * qr.scale)) > -0.000001 )
      return 0;
    v12 = ledge_to_compare->c_point_offset + 16 * (unsigned __int16)*(_DWORD *)s;
    v13 = (float)((float)(*(float *)((char *)&ledge_to_compare->ledgetree_node_offset + v12) * intersect_point.k[2])
                + (float)(*(float *)((char *)&ledge_to_compare->c_point_offset + v12) * intersect_point.k[1]))
        + (float)(*(float *)((char *)ledge_to_compare + v12 + 8) * intersect_point.hesse_val);
    v14 = (float)((float)((float)(intersect_point.k[2] * this->ray_start_point.k[1])
                        + (float)(intersect_point.k[1] * this->ray_start_point.k[0]))
                + (float)(intersect_point.hesse_val * this->ray_start_point.k[2]))
        - v13;
    v15 = (float)((float)((float)(intersect_point.k[2] * this->ray_end_point.k[1])
                        + (float)(intersect_point.k[1] * this->ray_end_point.k[0]))
                + (float)(intersect_point.hesse_val * this->ray_end_point.k[2]))
        - v13;
    if ( (float)(v15 * v14) >= 0.0 )
      return 0;
    hesse_vec_os.hesse_val = v14 / (float)(v14 - v15);
    IVP_U_Float_Point::set_interpolate(
      this: (IVP_U_Float_Point *)v25,
      p0: &this->ray_start_point,
      p1: &this->ray_end_point,
      s: hesse_vec_os.hesse_val);
    IVP_Compact_Ledge_Solver::calc_unscaled_qr_vals_F_space(
      c_ledge: ledge_to_compare,
      tri: s,
      p_object: (const IVP_U_Point *)v25,
      result: &v24);
    v16 = s;
    for ( i = 0; ; ++i )
    {
      if ( i >= 3 )
      {
        hesse_vec_os.hesse_val = this->ray_length * hesse_vec_os.hesse_val;
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Point *)&intersect_point.k[1]);
        ((void (__stdcall *)(IVP_Real_Object *, const IVP_Compact_Ledge *, unsigned int, _DWORD, float *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->hit_listener->add_hit_object)(
          a1: this->object,
          a2: ledge_to_compare,
          a3: s & 0xFFFFFFF0,
          a4: LODWORD(hesse_vec_os.hesse_val),
          a5: &intersect_point.k[1],
          a6: v20,
          a7: v21,
          a8: v22,
          a9: v23,
          a10: LODWORD(v24.checks[0]),
          a11: LODWORD(v24.checks[1]),
          a12: LODWORD(v24.checks[2]),
          a13: LODWORD(v24.scale),
          a14: v25[0],
          a15: v25[1],
          a16: v25[2],
          a17: LODWORD(intersect_point.k[0]));
        return 1;
      }
      if ( v24.checks[i] <= 0.0 )
        break;
      v16 += *(int *)((char *)IVP_Compact_Edge::next_table + (v16 & 0xC));
    }
    v18 = 2 * *(_DWORD *)v16;
    v19 = --LODWORD(hesse_vec_os.k[2]) < 0;
    s = v16 + 4 * (v18 >> 17);
    if ( !v19 )
      continue;
    break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007DC40
// Name: public: void IVP_Ray_Solver_Os::check_ray_against_ledge_tree_node_os(class IVP_Compact_Ledgetree_Node const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Ray_Solver_Os::check_ray_against_ledge_tree_node_os(
        IVP_Ray_Solver_Os *this,
        const IVP_Compact_Ledgetree_Node *node)
{
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm6_4
  float radius; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  while ( 1 )
  {
    v4 = node->center.k[0] - this->ray_center_point.k[0];
    v5 = node->center.k[1] - this->ray_center_point.k[1];
    v6 = node->center.k[2] - this->ray_center_point.k[2];
    radius = node->radius;
    v8 = (float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6);
    if ( v8 >= (float)((float)((float)(this->ray_length * 0.5) + radius)
                     * (float)((float)(this->ray_length * 0.5) + radius)) )
      break;
    if ( (float)(radius * radius) <= v8 )
    {
      v9 = (float)(this->ray_direction.k[1] * v6) - (float)(this->ray_direction.k[2] * v5);
      if ( (float)((float)(radius * radius)
                 - (float)((float)((float)((float)((float)(this->ray_direction.k[2] * v4)
                                                 - (float)(this->ray_direction.k[0] * v6))
                                         * (float)((float)(this->ray_direction.k[2] * v4)
                                                 - (float)(this->ray_direction.k[0] * v6)))
                                 + (float)(v9 * v9))
                         + (float)((float)((float)(this->ray_direction.k[0] * v5)
                                         - (float)(this->ray_direction.k[1] * v4))
                                 * (float)((float)(this->ray_direction.k[0] * v5)
                                         - (float)(this->ray_direction.k[1] * v4))))) < -0.0099999998 )
        break;
    }
    if ( node->offset_right_node == 0 )
    {
      IVP_Ray_Solver_Os::check_ray_against_compact_ledge_os(
        this,
        a2: (int)&savedregs,
        ledge_to_compare: (const IVP_Compact_Ledge *)((char *)node + node->offset_compact_ledge));
      return;
    }
    IVP_Ray_Solver_Os::check_ray_against_ledge_tree_node_os(this, node: node + 1);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + node->offset_right_node);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DD60
// Name: public: void IVP_Ray_Solver_Os::check_ray_against_compact_surface_os(class IVP_Compact_Surface const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Ray_Solver_Os::check_ray_against_compact_surface_os(
        IVP_Ray_Solver_Os *this,
        const IVP_Compact_Surface *compact_surface_to_compare)
{
  IVP_Ray_Solver_Os::check_ray_against_ledge_tree_node_os(
    this,
    node: (const IVP_Compact_Ledgetree_Node *)((char *)compact_surface_to_compare
                                       + compact_surface_to_compare->offset_ledgetree_root));
}

//------------------------------------------------------------------------------
// Address: 0x1007DD80
// Name: public: void IVP_Ray_Solver_Group::check_ray_group_against_node(class IVP_OV_Node __near *,class IVP_OV_Tree_Manager __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Ray_Solver_Group::check_ray_group_against_node(
        IVP_Ray_Solver_Group *this@<ecx>,
        float a2@<ebp>,
        IVP_OV_Node *node,
        IVP_OV_Tree_Manager *ov_tree_man)
{
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  int i; // edi
  float *v10; // eax
  int v11; // edi
  float v12[3]; // [esp-Ch] [ebp-2Ch] BYREF
  float v13[3]; // [esp+10h] [ebp-10h] BYREF
  float retaddr; // [esp+20h] [ebp+0h]

  v13[1] = a2;
  v13[2] = retaddr;
  IVP_OV_Tree_Manager::get_luf_coordinates_ws(this: ov_tree_man, node, p: (IVP_U_Float_Point *)v12, cubesize: v13);
  v5 = (float)(v13[0] * 0.5) + this->radius;
  v6 = fabs((float)(v12[0] + (float)(v13[0] * 0.5)) - this->center_ws.k[0]);
  v7 = fabs((float)(v12[1] + (float)(v13[0] * 0.5)) - this->center_ws.k[1]);
  v8 = fabs((float)(v12[2] + (float)(v13[0] * 0.5)) - this->center_ws.k[2]);
  if ( v6 <= v5
    && v7 <= v5
    && v8 <= v5
    && (float)((float)((float)(v6 * v6) + (float)(v7 * v7)) + (float)(v8 * v8)) < (float)((float)(v5 * v5) * 3.0) )
  {
    for ( i = node->elements.n_elems - 1; i >= 0; --i )
    {
      v10 = *(float **)(*((_DWORD *)node->elements.elems[i] + 9) + 148);
      if ( (float)((float)((float)((float)(v10[37] - this->center_ws.k[1]) * (float)(v10[37] - this->center_ws.k[1]))
                         + (float)((float)(v10[36] - this->center_ws.k[0]) * (float)(v10[36] - this->center_ws.k[0])))
                 + (float)((float)(v10[38] - this->center_ws.k[2]) * (float)(v10[38] - this->center_ws.k[2]))) < (float)((float)(v10[1] + this->radius) * (float)(v10[1] + this->radius)) )
        IVP_Ray_Solver_Group::check_ray_group_against_object(
          this,
          object: *((IVP_SurfaceManager **)node->elements.elems[i] + 9));
    }
    v11 = node->children.n_elems - 1;
    if ( node->children.n_elems != 0 )
    {
      do
        IVP_Ray_Solver_Group::check_ray_group_against_node(
          this,
          node: (IVP_OV_Node *)node->children.elems[v11--],
          ov_tree_man);
      while ( v11 >= 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DEF0
// Name: public: void IVP_Ray_Solver_Group::check_ray_group_against_all_objects_in_sim(class IVP_Environment const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Ray_Solver_Group::check_ray_group_against_all_objects_in_sim(
        IVP_Ray_Solver_Group *this,
        const IVP_Environment *environment)
{
  IVP_OV_Tree_Manager *ov_tree_manager; // eax
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  ov_tree_manager = environment->ov_tree_manager;
  if ( ov_tree_manager != nullptr )
    IVP_Ray_Solver_Group::check_ray_group_against_node(
      this,
      a2: COERCE_FLOAT(&savedregs),
      node: ov_tree_manager->root,
      ov_tree_man: environment->ov_tree_manager);
}
