// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_controller_raycast_vehicle.cpp
// Functions: 6
// ============================================================

#include "vphysics\physics_controller_raycast_vehicle.h"

//------------------------------------------------------------------------------
// Address: 0x10003C50
// Name: protected: virtual void IVP_Controller_Raycast_Car::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::core_is_going_to_be_deleted_event(CPhysics_Airboat *this, IVP_Core *core)
{
  char *v2; // ecx

  v2 = (char *)this - 4;
  if ( v2 != nullptr )
    (**(void (__thiscall ***)(char *, int))v2)(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000F1A0
// Name: public: virtual float IVP_Controller_Raycast_Car::get_booster_time_to_go(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Controller_Raycast_Car::get_booster_time_to_go(IVP_Controller_Raycast_Car *this)
{
  return this->booster_seconds_to_go;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1C0
// Name: public: class IPhysicsObject __near * CPhysics_Car_System_Raycast_Wheels::GetWheel(int)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CPhysics_Car_System_Raycast_Wheels::GetWheel(
        CPhysics_Car_System_Raycast_Wheels *this,
        int index)
{
  return (IPhysicsObject *)this->m_pWheels[index]->client_data;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1F0
// Name: public: CPhysics_Car_System_Raycast_Wheels::CPhysics_Car_System_Raycast_Wheels(class IVP_Environment __near *,class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysics_Car_System_Raycast_Wheels *__thiscall CPhysics_Car_System_Raycast_Wheels::CPhysics_Car_System_Raycast_Wheels(
        CPhysics_Car_System_Raycast_Wheels *this,
        IVP_Environment *pEnv,
        const IVP_Template_Car_System *pCarSystem)
{
  int v4; // ebx
  IVP_Real_Object **m_pWheels; // edi
  IVP_Real_Object **car_wheel; // esi
  IVP_Real_Object *v7; // ecx

  IVP_Controller_Raycast_Car::IVP_Controller_Raycast_Car(this, pEnvironment: pEnv, pCarSystemTemplate: pCarSystem);
  v4 = 0;
  this->IVP_Controller_Raycast_Car::IVP_Car_System::__vftable = (CPhysics_Car_System_Raycast_Wheels_vtbl *)&CPhysics_Car_System_Raycast_Wheels::`vftable'{for `IVP_Car_System'};
  this->IVP_Controller_Raycast_Car::IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&CPhysics_Car_System_Raycast_Wheels::`vftable'{for `IVP_Controller_Dependent'};
  if ( pCarSystem->n_wheels <= 0 )
    return this;
  m_pWheels = this->m_pWheels;
  car_wheel = pCarSystem->car_wheel;
  do
  {
    v7 = *car_wheel;
    *m_pWheels = *car_wheel;
    IVP_Real_Object::enable_collision_detection(this: v7, enable: IVP_FALSE);
    ++v4;
    ++car_wheel;
    ++m_pWheels;
  }
  while ( v4 < pCarSystem->n_wheels );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F290
// Name: public: virtual void CPhysics_Car_System_Raycast_Wheels::do_raycasts(class IVP_Event_Sim __near *,int,class IVP_Ray_Solver_Template __near *,class IVP_Ray_Hit __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Car_System_Raycast_Wheels::do_raycasts(
        CPhysics_Car_System_Raycast_Wheels *this@<ecx>,
        IVP_Ray_Solver_Min *a2@<ebp>,
        IVP_Event_Sim *es,
        int n_wheels,
        IVP_Ray_Solver_Template *t_in,
        IVP_Ray_Hit *hits_out,
        float *friction_of_object_out)
{
  BOOL v7; // esi
  int v8; // esi
  int v9; // esi
  float *v10; // edi
  IVP_Ray_Solver_Min *v12; // edx
  int v13; // ecx
  _DWORD v14[3]; // [esp-Ch] [ebp-28Ch] BYREF
  IVP_Ray_Solver_Min ray_solver3; // [esp+0h] [ebp-280h] BYREF
  IVP_Ray_Solver_Min ray_solver0; // [esp+90h] [ebp-1F0h] BYREF
  IVP_Ray_Solver_Min ray_solver2; // [esp+120h] [ebp-160h] BYREF
  IVP_Ray_Solver_Min ray_solver1; // [esp+1B0h] [ebp-D0h] BYREF
  IVP_Ray_Solver_Group rs_group; // [esp+240h] [ebp-40h] BYREF
  const IVP_Compact_Ledge **p_hit_compact_ledge; // [esp+260h] [ebp-20h]
  const IVP_Compact_Ledge **v21; // [esp+264h] [ebp-1Ch]
  IVP_Ray_Solver_Min *solvers[4]; // [esp+268h] [ebp-18h]
  void *v23; // [esp+278h] [ebp-8h]
  void *retaddr; // [esp+280h] [ebp+0h]

  solvers[3] = a2;
  v23 = retaddr;
  t_in->ray_flags = IVP_RAY_SOLVER_ALL;
  IVP_Ray_Solver::IVP_Ray_Solver(this: (IVP_Ray_Solver *)&ray_solver3.ray_hit.hit_compact_ledge, templ: t_in);
  ray_solver3.ray_hit.hit_compact_ledge = (const IVP_Compact_Ledge *)&IVP_Ray_Solver_Min::`vftable';
  ray_solver0.ray_flags = 1621981420;
  v7 = n_wheels > 1;
  IVP_Ray_Solver::IVP_Ray_Solver(this: (IVP_Ray_Solver *)&ray_solver2.ray_hit.hit_compact_ledge, templ: &t_in[v7]);
  v8 = v7 + 1;
  ray_solver2.ray_hit.hit_compact_ledge = (const IVP_Compact_Ledge *)&IVP_Ray_Solver_Min::`vftable';
  ray_solver1.ray_flags = 1621981420;
  if ( v8 >= n_wheels )
    --v8;
  IVP_Ray_Solver::IVP_Ray_Solver(this: (IVP_Ray_Solver *)&ray_solver0.ray_hit.hit_compact_ledge, templ: &t_in[v8]);
  v9 = v8 + 1;
  ray_solver0.ray_hit.hit_compact_ledge = (const IVP_Compact_Ledge *)&IVP_Ray_Solver_Min::`vftable';
  ray_solver2.ray_flags = 1621981420;
  if ( v9 >= n_wheels )
    --v9;
  IVP_Ray_Solver::IVP_Ray_Solver(this: (IVP_Ray_Solver *)v14, templ: &t_in[v9]);
  p_hit_compact_ledge = &ray_solver2.ray_hit.hit_compact_ledge;
  *((_DWORD *)&rs_group.ray_solvers + 1) = &ray_solver3.ray_hit.hit_compact_ledge;
  v14[0] = &IVP_Ray_Solver_Min::`vftable';
  ray_solver3.ray_flags = 1621981420;
  v21 = &ray_solver0.ray_hit.hit_compact_ledge;
  solvers[0] = (IVP_Ray_Solver_Min *)v14;
  IVP_Ray_Solver_Group::IVP_Ray_Solver_Group(
    this: (IVP_Ray_Solver_Group *)&ray_solver1.ray_hit.hit_compact_ledge,
    n_ray_solvers_: n_wheels,
    ray_solvers_: (IVP_Ray_Solver **)&rs_group.ray_solvers + 1);
  IVP_Ray_Solver_Group::check_ray_group_against_all_objects_in_sim(
    this: (IVP_Ray_Solver_Group *)&ray_solver1.ray_hit.hit_compact_ledge,
    environment: es->environment);
  if ( n_wheels > 0 )
  {
    v10 = friction_of_object_out;
    v12 = (IVP_Ray_Solver_Min *)((char *)(&rs_group.ray_solvers + 1) - (char *)friction_of_object_out);
    solvers[1] = (IVP_Ray_Solver_Min *)((char *)(&rs_group.ray_solvers + 1) - (char *)friction_of_object_out);
    solvers[2] = (IVP_Ray_Solver_Min *)n_wheels;
    do
    {
      v13 = *(_DWORD *)((char *)v10 + (_DWORD)v12);
      if ( *(float *)(v13 + 96) == 1.0e20 || v13 == -112 )
      {
        *(_QWORD *)hits_out->hit_surface_direction_os.k = 0;
        *(_QWORD *)&hits_out->hit_surface_direction_os.k[2] = 0;
        *(_QWORD *)&hits_out->hit_real_object = 0;
        *(_QWORD *)&hits_out->hit_compact_triangle = 0;
        *v10 = 0.0;
      }
      else
      {
        *(_QWORD *)hits_out->hit_surface_direction_os.k = *(_QWORD *)(v13 + 112);
        *(_QWORD *)&hits_out->hit_surface_direction_os.k[2] = *(_QWORD *)(v13 + 120);
        *(_QWORD *)&hits_out->hit_real_object = *(_QWORD *)(v13 + 128);
        *(_QWORD *)&hits_out->hit_compact_triangle = *(_QWORD *)(v13 + 136);
        *v10 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)(*(_DWORD *)(v13 + 128) + 136) + 4))(a1: *(_DWORD *)(*(_DWORD *)(v13 + 128) + 136));
        v12 = solvers[1];
      }
      ++hits_out;
      ++v10;
      --solvers[2];
    }
    while ( solvers[2] != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F480
// Name: public: virtual void CPhysics_Car_System_Raycast_Wheels::update_wheel_positions(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysics_Car_System_Raycast_Wheels::update_wheel_positions(
        CPhysics_Car_System_Raycast_Wheels *this@<ecx>,
        int a2@<ebp>)
{
  IVP_Real_Object *car_body; // esi
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v5; // esi
  IVP_Real_Object *v6; // ecx
  float *v7; // esi
  float v8; // xmm0_4
  IVP_COORDINATE_INDEX index_y; // edx
  IVP_COORDINATE_INDEX index_x; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int n_wheels; // ecx
  float angle; // [esp+0h] [ebp-130h]
  _BYTE v15[12]; // [esp+14h] [ebp-11Ch] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+20h] [ebp-110h] BYREF
  IVP_U_Matrix3 m_world_f_wheel; // [esp+60h] [ebp-D0h] BYREF
  IVP_U_Matrix3 m_core_f_wheel; // [esp+90h] [ebp-A0h] BYREF
  IVP_U_Float_Point hp_os; // [esp+C0h] [ebp-70h] BYREF
  IVP_U_Point hp_ws; // [esp+D0h] [ebp-60h] BYREF
  IVP_U_Quat rot_ws; // [esp+E0h] [ebp-50h] BYREF
  IVP_U_Float_Point hp_cs; // [esp+F0h] [ebp-40h] BYREF
  IVP_U_Point wheel_cs; // [esp+100h] [ebp-30h] BYREF
  IVP_U_Point wheel2_cs; // [esp+110h] [ebp-20h]
  IVP_Cache_Object *v25; // [esp+120h] [ebp-10h]
  int iWheel; // [esp+124h] [ebp-Ch]
  void *v27; // [esp+128h] [ebp-8h]
  void *retaddr; // [esp+130h] [ebp+0h]

  iWheel = a2;
  v27 = retaddr;
  car_body = this->car_body;
  if ( car_body->cache_object == nullptr )
    car_body->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                               this: car_body->environment->cache_object_manager,
                               object: car_body);
  ++car_body->cache_object->reference_count;
  if ( *(_BYTE *)&car_body->flags < 8 )
  {
    cache_object = car_body->cache_object;
    if ( car_body->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v5 = car_body->cache_object;
  v6 = this->car_body;
  v25 = v5;
  IVP_Real_Object::calc_m_core_f_object(this: v6, m_core_f_object: (IVP_U_Matrix *)v15);
  wheel2_cs.k[2] = 0.0;
  if ( this->n_wheels <= 0 )
  {
    --v5->reference_count;
  }
  else
  {
    LODWORD(wheel2_cs.hesse_val) = this->m_pWheels;
    v7 = &this->wheels_of_car[0].spring_direction_cs.k[2];
    do
    {
      v8 = v7[27] - v7[8];
      rot_ws.y = (float)(*(v7 - 2) * v8) + *(v7 - 6);
      rot_ws.z = (float)(*(v7 - 1) * v8) + *(v7 - 5);
      rot_ws.w = (float)(*v7 * v8) + *(v7 - 4);
      IVP_U_Matrix::vimult4(
        this: (IVP_U_Matrix *)v15,
        p_in: (const IVP_U_Float_Point *)&rot_ws.y,
        p_out: (IVP_U_Float_Point *)&m_core_f_wheel.rows[2].k[1]);
      IVP_Cache_Object::transform_position_to_world_coords(
        this: v25,
        P_object: (const IVP_U_Float_Point *)&m_core_f_wheel.rows[2].k[1],
        P_world_out: (IVP_U_Point *)&hp_os.k[1]);
      index_y = this->index_y;
      index_x = this->index_x;
      v11 = v7[15];
      v12 = v7[16];
      hp_cs.k[1] = v7[14];
      memset(&wheel_cs.k[1], 0, 12);
      wheel_cs.k[index_y + 1] = -1.0;
      angle = v7[18];
      hp_cs.k[2] = v11;
      hp_cs.hesse_val = v12;
      IVP_U_Float_Point::rotate(this: (IVP_U_Point *)&wheel_cs.k[1], axis: index_x, angle);
      IVP_U_Matrix3::init_normized3_col(
        this: (IVP_U_Matrix3 *)&m_world_f_wheel.rows[2].k[1],
        vb: (const IVP_U_Point *)&hp_cs.k[1],
        index_b: this->index_x,
        vc: (IVP_U_Point *)&wheel_cs.k[1]);
      IVP_U_Matrix3::mmult3(
        this: &v25->m_world_f_object,
        mb: (IVP_U_Matrix3 *)&m_world_f_wheel.rows[2].k[1],
        m_out: (IVP_U_Matrix *)&m_core_f_object.vv.k[1]);
      IVP_U_Quat::set_quaternion(this: (IVP_U_Quat *)&hp_ws.k[1], mat: (IVP_U_Matrix *)&m_core_f_object.vv.k[1]);
      IVP_Real_Object::beam_object_to_new_position(
        this: *(IVP_Real_Object **)LODWORD(wheel2_cs.hesse_val),
        rotation_world_f_object: (const IVP_U_Quat *)&hp_ws.k[1],
        position_w_f_o: (const IVP_U_Point *)&hp_os.k[1],
        optimize_for_repeated_calls: IVP_FALSE);
      n_wheels = this->n_wheels;
      LODWORD(wheel2_cs.hesse_val) += 4;
      v7 += 36;
      ++LODWORD(wheel2_cs.k[2]);
    }
    while ( SLODWORD(wheel2_cs.k[2]) < n_wheels );
    --v25->reference_count;
  }
}
