// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_surface_manager/ivp_surman_polygon.cxx
// Functions: 8
// ============================================================

#include "ivp\ivp_surface_manager\ivp_surman_polygon.h"

//------------------------------------------------------------------------------
// Address: 0x1007B1A0
// Name: public: virtual void IVP_SurfaceManager_Polygon::insert_all_ledges_hitting_ray(class IVP_Ray_Solver __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_SurfaceManager_Polygon::insert_all_ledges_hitting_ray(
        IVP_SurfaceManager_Polygon *this@<ecx>,
        IVP_Real_Object *a2@<ebp>,
        IVP_Ray_Solver *ray_solver,
        IVP_Real_Object *object)
{
  _BYTE v5[12]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_Ray_Solver_Os ray_solver_os; // [esp+0h] [ebp-50h]
  float retaddr; // [esp+50h] [ebp+0h]

  ray_solver_os.object = a2;
  ray_solver_os.ray_length = retaddr;
  IVP_Ray_Solver_Os::IVP_Ray_Solver_Os(this: (IVP_Ray_Solver_Os *)v5, so: ray_solver, obj: object);
  IVP_Ray_Solver_Os::check_ray_against_compact_surface_os(
    this: (IVP_Ray_Solver_Os *)v5,
    compact_surface_to_compare: this->compact_surface);
}

//------------------------------------------------------------------------------
// Address: 0x1007B1F0
// Name: public: virtual void IVP_SurfaceManager_Polygon::get_mass_center(class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon::get_mass_center(
        IVP_SurfaceManager_Polygon *this,
        IVP_U_Float_Point *mass_center_out)
{
  const IVP_Compact_Surface *compact_surface; // eax

  compact_surface = this->compact_surface;
  mass_center_out->k[0] = compact_surface->mass_center.k[0];
  mass_center_out->k[1] = compact_surface->mass_center.k[1];
  mass_center_out->k[2] = compact_surface->mass_center.k[2];
}

//------------------------------------------------------------------------------
// Address: 0x1007B210
// Name: public: virtual void IVP_SurfaceManager_Polygon::get_rotation_inertia(class IVP_U_Float_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon::get_rotation_inertia(
        IVP_SurfaceManager_Polygon *this,
        IVP_U_Float_Point *rotation_inertia_out)
{
  const IVP_Compact_Surface *compact_surface; // eax

  compact_surface = this->compact_surface;
  rotation_inertia_out->k[0] = compact_surface->rotation_inertia.k[0];
  rotation_inertia_out->k[1] = compact_surface->rotation_inertia.k[1];
  rotation_inertia_out->k[2] = compact_surface->rotation_inertia.k[2];
}

//------------------------------------------------------------------------------
// Address: 0x1007B230
// Name: public: virtual void IVP_SurfaceManager_Polygon::get_radius_and_radius_dev_to_given_center(class IVP_U_Float_Point const __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon::get_radius_and_radius_dev_to_given_center(
        IVP_SurfaceManager_Polygon *this,
        const IVP_U_Float_Point *center,
        float *radius,
        float *radius_deviation)
{
  const IVP_Compact_Surface *compact_surface; // eax
  float v5; // xmm0_4

  compact_surface = this->compact_surface;
  v5 = fsqrt(
         (float)((float)((float)(compact_surface->mass_center.k[1] - center->k[1])
                       * (float)(compact_surface->mass_center.k[1] - center->k[1]))
               + (float)((float)(compact_surface->mass_center.k[0] - center->k[0])
                       * (float)(compact_surface->mass_center.k[0] - center->k[0])))
       + (float)((float)(compact_surface->mass_center.k[2] - center->k[2])
               * (float)(compact_surface->mass_center.k[2] - center->k[2])));
  *radius = compact_surface->upper_limit_radius + v5;
  *radius_deviation = (double)*((unsigned __int8 *)compact_surface + 28)
                    * 0.0040000002
                    * compact_surface->upper_limit_radius
                    + v5;
}

//------------------------------------------------------------------------------
// Address: 0x1007B2B0
// Name: public: virtual class IVP_Compact_Ledge const __near * IVP_SurfaceManager_Polygon::get_single_convex(void)const
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Ledge *__thiscall IVP_SurfaceManager_Polygon::get_single_convex(IVP_SurfaceManager_Polygon *this)
{
  _DWORD *v1; // ecx
  const IVP_Compact_Ledge *result; // eax

  v1 = (_DWORD *)((char *)this->compact_surface->mass_center.k + this->compact_surface->offset_ledgetree_root);
  result = (const IVP_Compact_Ledge *)v1[1];
  if ( *v1 == 0 || result != nullptr )
    return (const IVP_Compact_Ledge *)((char *)result + (_DWORD)v1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B2E0
// Name: public: virtual IVP_SurfaceManager_Polygon::~IVP_SurfaceManager_Polygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon::~IVP_SurfaceManager_Polygon(IVP_SurfaceManager_Polygon *this)
{
  this->__vftable = (IVP_SurfaceManager_Polygon_vtbl *)&IVP_SurfaceManager_Polygon::`vftable';
  IVP_SurfaceManager::~IVP_SurfaceManager(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007B2F0
// Name: public: void IVP_SurfaceManager_Polygon_Solver::traverse_cluster(class IVP_Compact_Ledgetree_Node const __near *,class IVP_U_Point const __near *,float,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon_Solver::traverse_cluster(
        IVP_SurfaceManager_Polygon_Solver *this,
        const IVP_Compact_Ledgetree_Node *node,
        const IVP_U_Point *visitor_position_object_space,
        float radius,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  int offset_compact_ledge; // eax
  IVP_Compact_Ledge *v12; // eax
  char *v13; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  while ( 1 )
  {
    v7 = node->center.k[1] - visitor_position_object_space->k[1];
    v8 = node->center.k[0] - visitor_position_object_space->k[0];
    v9 = node->center.k[2] - visitor_position_object_space->k[2];
    if ( (float)((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v9 * v9)) > (float)((float)(node->radius + radius)
                                                                                          * (float)(node->radius + radius)) )
      break;
    v10 = node->radius * 0.0040000002;
    if ( fabs(v8) >= (float)((float)((float)node->box_sizes[0] * v10) + radius)
      || fabs(v7) >= (float)((float)((float)node->box_sizes[1] * v10) + radius)
      || fabs(v9) >= (float)((float)((float)node->box_sizes[2] * v10) + radius) )
    {
      break;
    }
    offset_compact_ledge = node->offset_compact_ledge;
    if ( offset_compact_ledge != 0 )
    {
      v12 = (IVP_Compact_Ledge *)((char *)node + offset_compact_ledge);
      if ( v12 != nullptr )
      {
        IVP_U_BigVector<IVP_Compact_Ledge>::add(this: resulting_ledges, elem: v12);
        return;
      }
    }
    if ( node->offset_right_node == 0 )
    {
      v13 = (char *)node + node->offset_compact_ledge;
      if ( *((_WORD *)v13 + 6) != 2
        || IVP_Compact_Ledge_Solver::calc_qlen_PF_F_space(
             a1: (int)&savedregs,
             ledge: (const IVP_Compact_Ledge *)v13,
             tri: (const IVP_Compact_Triangle *)v13 + 1,
             object_pos: visitor_position_object_space) <= radius * radius )
      {
        IVP_U_BigVector<IVP_Compact_Ledge>::add(this: resulting_ledges, elem: (IVP_Compact_Ledge *)v13);
      }
      return;
    }
    IVP_SurfaceManager_Polygon_Solver::traverse_cluster(
      this,
      node: node + 1,
      visitor_position_object_space,
      radius,
      resulting_ledges);
    node = (const IVP_Compact_Ledgetree_Node *)((char *)node + node->offset_right_node);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B440
// Name: public: virtual void IVP_SurfaceManager_Polygon::get_all_ledges_within_radius(class IVP_U_Point const __near *,float,class IVP_Compact_Ledge const __near *,class IVP_Real_Object __near *,class IVP_Compact_Ledge const __near *,class IVP_U_BigVector<class IVP_Compact_Ledge> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_SurfaceManager_Polygon::get_all_ledges_within_radius(
        IVP_SurfaceManager_Polygon *this,
        const IVP_U_Point *visitor_position_object_space,
        float radius,
        const IVP_Compact_Ledge *root_ledge,
        IVP_Real_Object *__formal,
        const IVP_Compact_Ledge *a6,
        IVP_U_BigVector<IVP_Compact_Ledge> *resulting_ledges)
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  const IVP_Compact_Ledgetree_Node *v10; // esi
  IVP_SurfaceManager_Polygon_Solver sps; // [esp+14h] [ebp-20h] BYREF

  v7 = visitor_position_object_space->k[0];
  sps.visitor_bb_max_x = visitor_position_object_space->k[0] + radius;
  v8 = visitor_position_object_space->k[1];
  sps.visitor_bb_max_y = v8 + radius;
  v9 = visitor_position_object_space->k[2] - radius;
  sps.visitor_bb_max_z = visitor_position_object_space->k[2] + radius;
  sps.visitor_bb_min_x = v7 - radius;
  sps.visitor_bb_min_y = v8 - radius;
  sps.visitor_bb_min_z = v9;
  sps.traversion_depth = 0;
  sps.max_traversion_depth = 0;
  if ( root_ledge != nullptr )
  {
    v10 = (const IVP_Compact_Ledgetree_Node *)((char *)root_ledge + root_ledge->ledgetree_node_offset);
    IVP_SurfaceManager_Polygon_Solver::traverse_cluster(
      this: &sps,
      node: v10 + 1,
      visitor_position_object_space,
      radius,
      resulting_ledges);
    IVP_SurfaceManager_Polygon_Solver::traverse_cluster(
      this: &sps,
      node: (const IVP_Compact_Ledgetree_Node *)((char *)v10 + v10->offset_right_node),
      visitor_position_object_space,
      radius,
      resulting_ledges);
  }
  else
  {
    IVP_SurfaceManager_Polygon_Solver::traverse_cluster(
      this: &sps,
      node: (const IVP_Compact_Ledgetree_Node *)((char *)this->compact_surface + this->compact_surface->offset_ledgetree_root),
      visitor_position_object_space,
      radius,
      resulting_ledges);
  }
}
