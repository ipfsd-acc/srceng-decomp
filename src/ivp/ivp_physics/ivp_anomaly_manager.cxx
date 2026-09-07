// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_anomaly_manager.cxx
// Functions: 12
// ============================================================

#include "ivp\ivp_physics\ivp_anomaly_manager.h"

//------------------------------------------------------------------------------
// Address: 0x10085BD0
// Name: public: IVP_Anomaly_Limits::IVP_Anomaly_Limits(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Anomaly_Limits *__thiscall IVP_Anomaly_Limits::IVP_Anomaly_Limits(
        IVP_Anomaly_Limits *this,
        IVP_BOOL delete_this_if_env_is_deleted_in)
{
  this->max_velocity = 2000.0;
  this->max_angular_velocity_per_psi = 1.5707964;
  this->min_friction_mass = 10.0;
  this->__vftable = (IVP_Anomaly_Limits_vtbl *)&IVP_Anomaly_Limits::`vftable';
  this->delete_this_if_env_is_deleted = delete_this_if_env_is_deleted_in;
  this->max_collisions_per_psi = 70000;
  this->max_collision_checks_per_psi = 1000;
  this->max_friction_mass = 2500.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085C30
// Name: public: virtual void IVP_Anomaly_Limits::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anomaly_Limits::environment_will_be_deleted(IVP_Anomaly_Limits *this, IVP_Environment *__formal)
{
  if ( this->delete_this_if_env_is_deleted != IVP_FALSE )
    ((void (__thiscall *)(IVP_Anomaly_Limits *, int))this->dtr_IVP_Anomaly_Limits)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10085C50
// Name: public: IVP_Anomaly_Manager::IVP_Anomaly_Manager(enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Anomaly_Manager *__thiscall IVP_Anomaly_Manager::IVP_Anomaly_Manager(
        IVP_Anomaly_Manager *this,
        IVP_BOOL delete_this_if_env_is_deleted_in)
{
  this->__vftable = (IVP_Anomaly_Manager_vtbl *)&IVP_Anomaly_Manager::`vftable';
  this->delete_this_if_env_is_deleted = delete_this_if_env_is_deleted_in;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10085C70
// Name: public: virtual IVP_Anomaly_Manager::~IVP_Anomaly_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anomaly_Manager::~IVP_Anomaly_Manager(IVP_Anomaly_Manager *this)
{
  this->__vftable = (IVP_Anomaly_Manager_vtbl *)&IVP_Anomaly_Manager::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10085C80
// Name: public: virtual void IVP_Anomaly_Manager::environment_will_be_deleted(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anomaly_Manager::environment_will_be_deleted(IVP_Anomaly_Manager *this, IVP_Environment *__formal)
{
  if ( this->delete_this_if_env_is_deleted != IVP_FALSE )
    ((void (__thiscall *)(IVP_Anomaly_Manager *, int))this->dtr_IVP_Anomaly_Manager)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10085CA0
// Name: public: virtual void IVP_Anomaly_Manager::max_velocity_exceeded(class IVP_Anomaly_Limits __near *,class IVP_Core __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anomaly_Manager::max_velocity_exceeded(
        IVP_Anomaly_Manager *this,
        IVP_Anomaly_Limits *al,
        IVP_Core *__formal,
        IVP_U_Float_Point *velocity_in_out)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  v4 = velocity_in_out->k[1];
  v5 = velocity_in_out->k[2];
  v6 = (float)(al->max_velocity * 0.99000001)
     / fsqrt((float)((float)(velocity_in_out->k[0] * velocity_in_out->k[0]) + (float)(v4 * v4)) + (float)(v5 * v5));
  velocity_in_out->k[0] = velocity_in_out->k[0] * v6;
  velocity_in_out->k[1] = v4 * v6;
  velocity_in_out->k[2] = v5 * v6;
}

//------------------------------------------------------------------------------
// Address: 0x10085D10
// Name: public: virtual void IVP_Anomaly_Manager::max_angular_velocity_exceeded(class IVP_Anomaly_Limits __near *,class IVP_Core __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Anomaly_Manager::max_angular_velocity_exceeded(
        IVP_Anomaly_Manager *this,
        IVP_Anomaly_Limits *al,
        IVP_Core *core,
        IVP_U_Float_Point *angular_velocity_in_out)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  v4 = angular_velocity_in_out->k[1];
  v5 = angular_velocity_in_out->k[2];
  v6 = (float)((float)(core->environment->inv_delta_PSI_time * al->max_angular_velocity_per_psi) * 0.89999998)
     / fsqrt(
         (float)((float)(angular_velocity_in_out->k[0] * angular_velocity_in_out->k[0]) + (float)(v4 * v4))
       + (float)(v5 * v5));
  angular_velocity_in_out->k[0] = angular_velocity_in_out->k[0] * v6;
  angular_velocity_in_out->k[1] = v4 * v6;
  angular_velocity_in_out->k[2] = v5 * v6;
}

//------------------------------------------------------------------------------
// Address: 0x10085D90
// Name: public: void IVP_Anomaly_Manager::solve_inter_penetration_simple(class IVP_Real_Object __near *,class IVP_Real_Object __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Anomaly_Manager::solve_inter_penetration_simple(
        IVP_Anomaly_Manager *this@<ecx>,
        int a2@<ebp>,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1,
        float speedChange)
{
  IVP_Core *physical_core; // esi
  IVP_Core *v6; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float hesse_val; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Float_Point p1; // [esp+0h] [ebp-40h] BYREF
  IVP_U_Float_Point p0; // [esp+10h] [ebp-30h] BYREF
  IVP_U_Float_Point vec01; // [esp+20h] [ebp-20h]
  const IVP_U_Point *p_vv; // [esp+30h] [ebp-10h]
  int v20; // [esp+34h] [ebp-Ch] BYREF
  float d_time; // [esp+38h] [ebp-8h]
  float retaddr; // [esp+40h] [ebp+0h]

  v20 = a2;
  d_time = retaddr;
  physical_core = obj1->physical_core;
  v6 = obj0->physical_core;
  v7 = physical_core->m_world_f_core_last_psi.vv.k[2] - v6->m_world_f_core_last_psi.vv.k[2];
  v8 = physical_core->m_world_f_core_last_psi.vv.k[0] - v6->m_world_f_core_last_psi.vv.k[0];
  vec01.hesse_val = obj0->environment->delta_PSI_time;
  v9 = physical_core->m_world_f_core_last_psi.vv.k[1] - v6->m_world_f_core_last_psi.vv.k[1];
  p_vv = &v6->m_world_f_core_last_psi.vv;
  p0.k[1] = v8;
  p0.k[2] = v9;
  p0.hesse_val = v7;
  hesse_val = 0.0;
  if ( IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&p0.k[1]) > 0.01 )
  {
    hesse_val = p0.hesse_val;
  }
  else
  {
    p0.k[1] = 1.0;
    p0.k[2] = 0.0;
    p0.hesse_val = 0.0;
  }
  if ( *((_BYTE *)&v6->IVP_Core_Fast_Static + 1) < 8u && (*(_BYTE *)&v6->IVP_Core_Fast_Static & 0x10) == 0 )
  {
    v11 = v6->rot_inertia.hesse_val;
    if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 && v11 > physical_core->rot_inertia.hesse_val )
      v11 = physical_core->rot_inertia.hesse_val;
    LODWORD(v12) = COERCE_UNSIGNED_INT(v11 * speedChange) ^ _mask__NegFloat_;
    p1.k[1] = v12 * p0.k[1];
    p1.k[2] = p0.k[2] * v12;
    p1.hesse_val = hesse_val * v12;
    IVP_Real_Object::async_push_object_ws(
      this: obj0,
      a2: COERCE_FLOAT(&v20),
      position_ws_: p_vv,
      impulse_ws_: (IVP_U_Float_Point *)&p1.k[1]);
    LODWORD(v15[0]) = LODWORD(vec01.hesse_val) ^ _mask__NegFloat_;
    v15[1] = 0.0;
    v15[2] = 0.0;
    IVP_Real_Object::async_add_rot_speed_object_cs(this: obj0, rotation_vec: (const IVP_U_Float_Point *)v15);
    hesse_val = p0.hesse_val;
  }
  if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u
    && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 )
  {
    v13 = physical_core->rot_inertia.hesse_val;
    if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 0x10) == 0 && v13 > v6->rot_inertia.hesse_val )
      v13 = v6->rot_inertia.hesse_val;
    v14 = v13 * speedChange;
    v15[0] = v14 * p0.k[1];
    v15[1] = v14 * p0.k[2];
    v15[2] = hesse_val * v14;
    IVP_Real_Object::async_push_object_ws(
      this: obj1,
      a2: COERCE_FLOAT(&v20),
      position_ws_: p_vv,
      impulse_ws_: (const IVP_U_Float_Point *)v15);
    p1.k[1] = vec01.hesse_val;
    p1.k[2] = 0.0;
    p1.hesse_val = 0.0;
    IVP_Real_Object::async_add_rot_speed_object_cs(this: obj1, rotation_vec: (IVP_U_Float_Point *)&p1.k[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085F70
// Name: public: virtual float IVP_Anomaly_Manager::get_push_speed_penetration(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall IVP_Anomaly_Manager::get_push_speed_penetration(
        IVP_Anomaly_Manager *this,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1)
{
  IVP_Environment *environment; // eax
  float d_time; // [esp+8h] [ebp+8h]

  environment = obj0->environment;
  d_time = environment->delta_PSI_time;
  return IVP_U_Float_Point::fast_real_length(this: &environment->gravity) * 4.0 * d_time;
}

//------------------------------------------------------------------------------
// Address: 0x10085FA0
// Name: public: virtual enum IVP_BOOL IVP_Anomaly_Manager::max_contacts_exceeded_check_freezing(class IVP_Core __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Anomaly_Manager::max_contacts_exceeded_check_freezing(
        IVP_Anomaly_Manager *this,
        IVP_Core **pCoreList,
        IVP_Core **coreCount)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10085FB0
// Name: public: virtual int IVP_Anomaly_Manager::max_collision_checks_exceeded(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Anomaly_Manager::max_collision_checks_exceeded(IVP_Anomaly_Manager *this, int totalChecked)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10086020
// Name: public: virtual void IVP_Anomaly_Manager::inter_penetration(class IVP_Mindist __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Anomaly_Manager::inter_penetration(
        IVP_Anomaly_Manager *this@<ecx>,
        int a2@<ebp>,
        IVP_Mindist *mindist,
        IVP_Real_Object *obj0,
        IVP_Real_Object *obj1,
        float speedChange)
{
  IVP_Core *physical_core; // ecx
  bool v7; // zf
  BOOL v8; // eax
  int v9; // ecx
  char *v10; // esi
  IVP_Core *v11; // edi
  bool v12; // cf
  float v13; // xmm0_4
  float v14; // xmm1_4
  const IVP_Compact_Ledge *ledge; // eax
  const IVP_Compact_Ledge *v16; // esi
  _DWORD *v17; // edi
  int c_point_offset; // ecx
  int v19; // eax
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // xmm2_4
  int v23; // eax
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  int v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  int n_triangles; // ecx
  _DWORD v31[3]; // [esp+14h] [ebp-BCh] BYREF
  IVP_U_Point three_points[3]; // [esp+20h] [ebp-B0h] BYREF
  IVP_U_Point obj_pos_moving; // [esp+50h] [ebp-80h] BYREF
  IVP_U_Point world_push_dir; // [esp+60h] [ebp-70h] BYREF
  IVP_U_Point world_pos_moving; // [esp+70h] [ebp-60h] BYREF
  IVP_U_Hesse hesse_plane; // [esp+80h] [ebp-50h] BYREF
  IVP_U_Float_Point world_push_vec; // [esp+90h] [ebp-40h] BYREF
  IVP_U_Point push_direction; // [esp+A0h] [ebp-30h]
  IVP_Core *v39; // [esp+B0h] [ebp-20h]
  IVP_Real_Object *v40; // [esp+B4h] [ebp-1Ch]
  IVP_Real_Object *v41; // [esp+B8h] [ebp-18h]
  int v42; // [esp+BCh] [ebp-14h]
  IVP_Real_Object *moving_obj; // [esp+C0h] [ebp-10h]
  int v44; // [esp+C4h] [ebp-Ch] BYREF
  int i; // [esp+C8h] [ebp-8h]
  int retaddr; // [esp+D0h] [ebp+0h]

  v44 = a2;
  i = retaddr;
  moving_obj = (IVP_Real_Object *)this;
  physical_core = obj1->physical_core;
  v40 = obj0;
  v7 = (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0;
  v41 = obj1;
  v8 = !v7;
  v9 = (int)*(&v40 + v8);
  if ( (**(_BYTE **)(v9 + 148) & 2) != 0 && *((__int16 *)(v10 = (char *)mindist + 28 * v8) + 25) <= 2 )
  {
    v11 = (*(&v41 - v8))->physical_core;
    v12 = *((_BYTE *)&v11->IVP_Core_Fast_Static + 1) < 8u;
    v41 = *(&v41 - v8);
    v39 = v11;
    if ( v12 )
    {
      v13 = v11->m_world_f_core_last_psi.vv.k[1];
      v14 = v11->m_world_f_core_last_psi.vv.k[2];
      world_push_dir.k[1] = v11->m_world_f_core_last_psi.vv.k[0];
      world_push_dir.k[2] = v13;
      world_push_dir.hesse_val = v14;
      LODWORD(push_direction.hesse_val) = &IVP_Real_Object::get_cache_object_no_lock(this: (IVP_Real_Object *)v9)->m_world_f_object;
      IVP_U_Matrix::vimult4(
        this: (IVP_U_Matrix *)LODWORD(push_direction.hesse_val),
        p_in: (IVP_U_Point *)&world_push_dir.k[1],
        p_out: (IVP_U_Point *)&three_points[2].k[1]);
      ledge = IVP_Synapse::get_ledge(this: (IVP_Synapse *)(v10 + 24));
      world_push_vec.k[1] = 1.0;
      v16 = ledge;
      world_push_vec.k[2] = 0.0;
      world_push_vec.hesse_val = 0.0;
      *(float *)&moving_obj = -1.0e20;
      v42 = 0;
      if ( ledge->n_triangles > 0 )
      {
        v17 = (_DWORD *)&ledge[1] + 2;
        do
        {
          c_point_offset = v16->c_point_offset;
          v19 = v16->c_point_offset + 16 * (unsigned __int16)*(v17 - 1);
          v20 = *(int *)((char *)&v16->ledgetree_node_offset + v19);
          v21 = *(_DWORD *)((char *)v16 + v19 + 8);
          v22 = *(int *)((char *)&v16->c_point_offset + v19);
          v23 = v16->c_point_offset + 16 * (unsigned __int16)*v17;
          v31[0] = v22;
          v31[1] = v20;
          v31[2] = v21;
          v24 = *(float *)((char *)&v16->ledgetree_node_offset + v23);
          v25 = *(float *)((char *)v16 + v23 + 8);
          v26 = *(float *)((char *)&v16->c_point_offset + v23);
          v27 = c_point_offset + 16 * (unsigned __int16)v17[1];
          three_points[0].k[1] = v26;
          three_points[0].k[2] = v24;
          three_points[0].hesse_val = v25;
          v28 = *(float *)((char *)&v16->ledgetree_node_offset + v27);
          v29 = *(float *)((char *)v16 + v27 + 8);
          LODWORD(three_points[1].k[1]) = *(int *)((char *)&v16->c_point_offset + v27);
          three_points[1].k[2] = v28;
          three_points[1].hesse_val = v29;
          IVP_U_Hesse::calc_hesse(
            this: (IVP_U_Hesse *)&world_pos_moving.k[1],
            tp0: (const IVP_U_Float_Point *)v31,
            tp1: (IVP_U_Point *)&three_points[1].k[1],
            tp2: (IVP_U_Point *)&three_points[0].k[1]);
          IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)&world_pos_moving.k[1]);
          if ( (float)((float)((float)((float)(three_points[2].k[2] * world_pos_moving.k[2])
                                     + (float)(three_points[2].k[1] * world_pos_moving.k[1]))
                             + (float)(three_points[2].hesse_val * world_pos_moving.hesse_val))
                     + hesse_plane.k[0]) > *(float *)&moving_obj )
          {
            *(float *)&moving_obj = (float)((float)((float)(three_points[2].k[2] * world_pos_moving.k[2])
                                                  + (float)(three_points[2].k[1] * world_pos_moving.k[1]))
                                          + (float)(three_points[2].hesse_val * world_pos_moving.hesse_val))
                                  + hesse_plane.k[0];
            world_push_vec.k[1] = world_pos_moving.k[1];
            world_push_vec.k[2] = world_pos_moving.k[2];
            world_push_vec.hesse_val = world_pos_moving.hesse_val;
          }
          n_triangles = v16->n_triangles;
          v17 += 4;
          ++v42;
        }
        while ( v42 < n_triangles );
        v11 = v39;
      }
      IVP_U_Matrix3::vmult3(
        this: (IVP_U_Matrix3 *)LODWORD(push_direction.hesse_val),
        p_in: (IVP_U_Float_Point *)&world_push_vec.k[1],
        p_out: (IVP_U_Point *)&obj_pos_moving.k[1]);
      hesse_plane.k[1] = obj_pos_moving.k[1];
      hesse_plane.k[2] = obj_pos_moving.k[2];
      hesse_plane.hesse_val = obj_pos_moving.hesse_val;
      if ( (float)(speedChange * 0.1) > (float)((float)((float)((float)(v11->delta_world_f_core_psis.k[1]
                                                                      + v11->speed_change.k[1])
                                                              * obj_pos_moving.k[2])
                                                      + (float)((float)(v11->delta_world_f_core_psis.k[0]
                                                                      + v11->speed_change.k[0])
                                                              * obj_pos_moving.k[1]))
                                              + (float)((float)(v11->delta_world_f_core_psis.k[2]
                                                              + v11->speed_change.k[2])
                                                      * obj_pos_moving.hesse_val)) )
      {
        hesse_plane.k[1] = obj_pos_moving.k[1] * speedChange;
        hesse_plane.k[2] = obj_pos_moving.k[2] * speedChange;
        hesse_plane.hesse_val = obj_pos_moving.hesse_val * speedChange;
        IVP_Real_Object::async_add_speed_object_ws(this: v41, speed_vec: (IVP_U_Hesse *)&hesse_plane.k[1]);
      }
    }
  }
  else
  {
    IVP_Anomaly_Manager::solve_inter_penetration_simple(
      this: (IVP_Anomaly_Manager *)moving_obj,
      a2: (int)&v44,
      obj0,
      obj1,
      speedChange);
  }
}
