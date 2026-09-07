// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_controller_raycast_car.cxx
// Functions: 36
// ============================================================

#include "ivp\ivp_controller\ivp_controller_raycast_car.h"

//------------------------------------------------------------------------------
// Address: 0x10003A10
// Name: protected: virtual enum IVP_CONTROLLER_PRIORITY IVP_Controller_Raycast_Car::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Controller_Raycast_Car::get_controller_priority(IVP_Controller_Raycast_Car *this)
{
  return 410;
}

//------------------------------------------------------------------------------
// Address: 0x1007B690
// Name: protected: void IVP_Controller_Raycast_Car::SetupWheelRaycasts(class IVP_Ray_Solver_Template __near *,class IVP_U_Matrix const __near *,class IVP_Raycast_Car_Wheel_Temp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::SetupWheelRaycasts(
        IVP_Controller_Raycast_Car *this,
        IVP_Ray_Solver_Template *pRaySolverTemplates,
        IVP_U_Matrix *m_world_f_core,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels)
{
  IVP_U_Float_Point *p_spring_direction_ws; // ebx
  float *p_wheel_radius; // edi
  float *v6; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  IVP_Controller_Raycast_Car *v9; // [esp+0h] [ebp-8h]
  int iWheel; // [esp+4h] [ebp-4h]

  v9 = this;
  iWheel = 0;
  if ( this->n_wheels > 0 )
  {
    p_spring_direction_ws = &pTempWheels->spring_direction_ws;
    p_wheel_radius = &this->wheels_of_car[0].wheel_radius;
    v6 = &pRaySolverTemplates->ray_normized_direction.k[2];
    do
    {
      if ( p_wheel_radius != (float *)56 )
      {
        IVP_U_Matrix::vmult4(
          this: m_world_f_core,
          p_in: (const IVP_U_Float_Point *)(p_wheel_radius - 14),
          p_out: (IVP_U_Float_Point *)(v6 - 6));
        IVP_U_Matrix3::vmult3(
          this: m_world_f_core,
          p_in: (const IVP_U_Float_Point *)(p_wheel_radius - 10),
          p_out: p_spring_direction_ws);
        v7 = p_spring_direction_ws->k[1];
        v8 = p_spring_direction_ws->k[2];
        *(v6 - 2) = p_spring_direction_ws->k[0];
        this = v9;
        *(v6 - 1) = v7;
        *v6 = v8;
        v6[2] = *(p_wheel_radius - 5) + *p_wheel_radius;
        v6[3] = 0.0;
      }
      v6 += 12;
      p_wheel_radius += 36;
      p_spring_direction_ws += 9;
      ++iWheel;
    }
    while ( iWheel < this->n_wheels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B740
// Name: protected: bool IVP_Controller_Raycast_Car::DoSimulationWheels(class IVP_Ray_Solver_Template __near *,class IVP_U_Matrix const __near *,class IVP_Raycast_Car_Wheel_Temp __near *,class IVP_Ray_Hit __near *,float __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall IVP_Controller_Raycast_Car::DoSimulationWheels(
        IVP_Controller_Raycast_Car *this,
        IVP_Ray_Solver_Template *pRaySolverTemplates,
        const IVP_U_Matrix *m_world_f_core,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels,
        IVP_Ray_Hit *pRayHits,
        float *pFrictions,
        IVP_Core *pCarCore)
{
  float *v7; // ebx
  float *v8; // esi
  float *p_wheel_radius; // edi
  IVP_Real_Object *v10; // eax
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  IVP_Controller_Raycast_Car *v19; // [esp+Ch] [ebp-Ch]
  float *v20; // [esp+10h] [ebp-8h]
  int iWheel; // [esp+14h] [ebp-4h]
  IVP_Real_Object **pRaySolverTemplatesa; // [esp+20h] [ebp+8h]
  IVP_Ray_Hit *pRayHitsa; // [esp+2Ch] [ebp+14h]

  v19 = this;
  iWheel = 0;
  if ( this->n_wheels <= 0 )
    return 1;
  v7 = &pRaySolverTemplates->ray_start_point.k[2];
  v20 = &pRaySolverTemplates->ray_start_point.k[2];
  pRaySolverTemplatesa = &pRayHits->hit_real_object;
  v8 = &pTempWheels->ground_normal_ws.k[2];
  p_wheel_radius = &this->wheels_of_car[0].wheel_radius;
  while ( 1 )
  {
    if ( p_wheel_radius == (float *)56 || v8 == (float *)24 || pRaySolverTemplatesa == (IVP_Real_Object **)16 )
      goto LABEL_17;
    v10 = *pRaySolverTemplatesa;
    pRayHitsa = (IVP_Ray_Hit *)*pRaySolverTemplatesa;
    if ( *pRaySolverTemplatesa != nullptr )
    {
      if ( v10->cache_object == nullptr )
      {
        LODWORD(pRayHitsa[2].hit_surface_direction_os.k[0]) = IVP_Cache_Object_Manager::get_cache_object(
                                                                this: v10->environment->cache_object_manager,
                                                                object: v10);
        v10 = (IVP_Real_Object *)pRayHitsa;
      }
      if ( *(_BYTE *)&v10->flags < 8 )
      {
        cache_object = v10->cache_object;
        if ( v10->environment->current_time_code > cache_object->valid_until_time_code )
        {
          IVP_Cache_Object::update_cache_object(this: cache_object);
          v10 = (IVP_Real_Object *)pRayHitsa;
        }
      }
      v12 = v10->cache_object;
      if ( v12 != nullptr )
      {
        IVP_Cache_Object::transform_vector_to_world_coords(
          this: v12,
          P_object: (const IVP_U_Float_Point *)pRaySolverTemplatesa - 1,
          P_world_out: (IVP_U_Float_Point *)(v8 - 2));
        p_wheel_radius[19] = *((float *)pRaySolverTemplatesa + 3);
        v8[27] = 1.1
               / (float)(COERCE_FLOAT(
                           COERCE_UNSIGNED_INT((float)((float)(v8[7] * *(v8 - 1)) + (float)(v8[6] * *(v8 - 2))) + (float)(v8[8] * *v8))
                         & _mask__AbsFloat_)
                       + 0.1);
      }
    }
    else
    {
      p_wheel_radius[18] = 0.0;
      p_wheel_radius[19] = *(p_wheel_radius - 5) + *p_wheel_radius;
      v8[27] = 1.0;
      *(v8 - 4) = 0.0;
      v13 = v8[7] * -1.0;
      v14 = v8[8] * -1.0;
      *(v8 - 2) = v8[6] * -1.0;
      *(v8 - 1) = v13;
      *v8 = v14;
    }
    *(v8 - 6) = pFrictions[iWheel] * p_wheel_radius[2];
    v15 = p_wheel_radius[19];
    v16 = (float)(v8[7] * v15) + *(v7 - 1);
    v17 = (float)(v8[8] * v15) + *v7;
    v8[2] = (float)(v8[6] * v15) + *(v7 - 2);
    v8[3] = v16;
    v8[4] = v17;
    IVP_Core::get_surface_speed_ws(
      this: pCarCore,
      position_ws_in: (const IVP_U_Point *)(v8 + 2),
      speed_ws_out: (IVP_U_Float_Point *)(v8 + 10));
    IVP_U_Float_Point::set_orthogonal_part(
      this: (IVP_U_Float_Point *)(v8 + 14),
      vector: (const IVP_U_Float_Point *)(v8 + 10),
      normal_v: (const IVP_U_Float_Point *)(v8 - 2));
    IVP_U_Matrix3::vmult3(
      this: &m_world_f_core->IVP_U_Matrix3,
      p_in: (const IVP_U_Float_Point *)(p_wheel_radius + 6),
      p_out: (IVP_U_Float_Point *)(v8 + 18));
    IVP_U_Float_Point::set_orthogonal_part(
      this: (IVP_U_Float_Point *)(v8 + 22),
      vector: (const IVP_U_Float_Point *)(v8 + 18),
      normal_v: (const IVP_U_Float_Point *)(v8 - 2));
    if ( IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)(v8 + 22)) == IVP_FAULT )
      return 0;
    v7 = v20;
    this = v19;
LABEL_17:
    pRaySolverTemplatesa += 8;
    v7 += 12;
    p_wheel_radius += 36;
    v8 += 36;
    ++iWheel;
    v20 = v7;
    if ( iWheel >= this->n_wheels )
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B9A0
// Name: protected: void IVP_Controller_Raycast_Car::DoSimulationStabilizers(class IVP_Raycast_Car_Wheel_Temp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::DoSimulationStabilizers(
        IVP_Controller_Raycast_Car *this,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels)
{
  unsigned int v2; // esi
  float *p_stabilizer_force; // edx
  IVP_Raycast_Car_Axis *axis_of_car; // edi
  int v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // edx
  float *v8; // eax

  if ( this->wheels_per_axis == 2 )
  {
    v2 = 0;
    if ( this->n_axis != 0 )
    {
      p_stabilizer_force = &pTempWheels[1].stabilizer_force;
      axis_of_car = this->axis_of_car;
      do
      {
        v5 = v2 * this->wheels_per_axis;
        v6 = (float)((float)((float)(this->wheels_of_car[v5 + 1].raycast_dist - this->wheels_of_car[v5 + 1].spring_len)
                           - this->wheels_of_car[v5 + 1].wheel_radius)
                   - (float)((float)(this->wheels_of_car[v5].raycast_dist - this->wheels_of_car[v5].spring_len)
                           - this->wheels_of_car[v5].wheel_radius))
           * (float)(axis_of_car->stabilizer_constant * 0.5);
        *(p_stabilizer_force - 36) = v6;
        *p_stabilizer_force = -v6;
        ++v2;
        ++axis_of_car;
        p_stabilizer_force += 72;
      }
      while ( v2 < this->n_axis );
    }
  }
  else
  {
    v7 = 0;
    if ( this->n_wheels != 0 )
    {
      v8 = &pTempWheels->stabilizer_force;
      do
      {
        *v8 = 0.0;
        ++v7;
        v8 += 36;
      }
      while ( v7 < this->n_wheels );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BA80
// Name: protected: void IVP_Controller_Raycast_Car::DoSimulationShocks(class IVP_Raycast_Car_Wheel_Temp __near *,class IVP_Ray_Hit __near *,class IVP_Event_Sim __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Raycast_Car::DoSimulationShocks(
        IVP_Controller_Raycast_Car *this@<ecx>,
        int a2@<ebp>,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels,
        IVP_Ray_Hit *pRayHits,
        IVP_Event_Sim *pEventSim,
        IVP_Core *pCarCore)
{
  float *v6; // esi
  int v7; // eax
  float *p_spring_len; // edi
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  int n_wheels; // edx
  float v18[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point impulse_ws; // [esp+0h] [ebp-20h]
  IVP_Real_Object **p_hit_real_object; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int iWheel; // [esp+18h] [ebp-8h]
  int retaddr; // [esp+20h] [ebp+0h]

  v21 = a2;
  iWheel = retaddr;
  LODWORD(impulse_ws.k[2]) = this;
  impulse_ws.hesse_val = 0.0;
  if ( this->n_wheels > 0 )
  {
    v6 = &pTempWheels->projected_surface_speed_wheel_ws.k[2];
    v7 = (char *)pTempWheels - (char *)this;
    p_hit_real_object = &pRayHits->hit_real_object;
    p_spring_len = &this->wheels_of_car[0].spring_len;
    LODWORD(impulse_ws.k[1]) = (char *)pTempWheels - (char *)this;
    do
    {
      if ( p_spring_len != (float *)36 && *p_hit_real_object != nullptr )
      {
        v9 = (float)(p_spring_len[24] - *p_spring_len) - p_spring_len[5];
        if ( v9 < 0.0 )
        {
          v10 = p_spring_len[1] * v9;
          v11 = v6[11];
          if ( v11 >= 0.0 )
          {
            if ( v11 > 3.0 )
              v11 = 3.0;
          }
          else
          {
            v11 = 0.0;
          }
          v12 = (float)(*(v6 - 21) - v10) * v11;
          v13 = (float)((float)(*(v6 - 9) * (float)(*(v6 - 1) - *(float *)((char *)p_spring_len + v7)))
                      + (float)(*(v6 - 10) * (float)(*(v6 - 2) - *(v6 - 6))))
              + (float)(*(v6 - 8) * (float)(*v6 - *(v6 - 4)));
          if ( v13 <= 0.0 )
            v14 = v13 * p_spring_len[3];
          else
            v14 = v13 * p_spring_len[2];
          v15 = v12 - v14;
          if ( v15 < 0.0 )
            v15 = 0.0;
          p_spring_len[23] = v15;
          v16 = pEventSim->delta_time * v15;
          v18[0] = *(v6 - 18) * v16;
          v18[1] = *(v6 - 17) * v16;
          v18[2] = *(v6 - 16) * v16;
          IVP_Core::push_core_ws(
            this: pCarCore,
            world_point: (const IVP_U_Point *)(v6 - 14),
            impulse_in_world: (const IVP_U_Float_Point *)v18);
          this = (IVP_Controller_Raycast_Car *)LODWORD(impulse_ws.k[2]);
          v7 = LODWORD(impulse_ws.k[1]);
        }
      }
      n_wheels = this->n_wheels;
      ++LODWORD(impulse_ws.hesse_val);
      p_hit_real_object += 8;
      p_spring_len += 36;
      v6 += 36;
    }
    while ( SLODWORD(impulse_ws.hesse_val) < n_wheels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BC20
// Name: protected: void IVP_Controller_Raycast_Car::DoSimulationBooster(class IVP_Event_Sim __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::DoSimulationBooster(
        IVP_Controller_Raycast_Car *this,
        IVP_Event_Sim *pEventSim,
        IVP_Core *pCarCore)
{
  float booster_seconds_until_ready; // xmm0_4
  float booster_seconds_to_go; // xmm0_4
  float v5; // xmm0_4
  float booster_force; // xmm4_4
  IVP_COORDINATE_INDEX index_z; // ecx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  booster_seconds_until_ready = this->booster_seconds_until_ready;
  if ( booster_seconds_until_ready > 0.0 )
    this->booster_seconds_until_ready = booster_seconds_until_ready - pEventSim->delta_time;
  booster_seconds_to_go = this->booster_seconds_to_go;
  if ( booster_seconds_to_go > 0.0 )
  {
    v5 = booster_seconds_to_go - pEventSim->delta_time;
    this->booster_seconds_to_go = v5;
    if ( v5 <= 0.0 )
      this->booster_force = 0.0;
  }
  booster_force = this->booster_force;
  if ( booster_force != 0.0 )
  {
    index_z = this->index_z;
    v8 = pEventSim->delta_time * booster_force;
    v9 = (float)(v8 * pCarCore->m_world_f_core_last_psi.rows[1].k[index_z]) + pCarCore->speed.k[1];
    v10 = (float)(pCarCore->m_world_f_core_last_psi.rows[2].k[index_z] * v8) + pCarCore->speed.k[2];
    pCarCore->speed.k[0] = (float)(v8 * pCarCore->m_world_f_core_last_psi.rows[0].k[index_z]) + pCarCore->speed.k[0];
    pCarCore->speed.k[1] = v9;
    pCarCore->speed.k[2] = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007BCF0
// Name: protected: void IVP_Controller_Raycast_Car::ApplySteeringForces(class IVP_Raycast_Car_Wheel_Temp __near *,class IVP_Core __near *,class IVP_Event_Sim __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Raycast_Car::ApplySteeringForces(
        IVP_Controller_Raycast_Car *this@<ecx>,
        float a2@<ebp>,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels,
        IVP_Core *pCarCore,
        IVP_Event_Sim *pEventSim,
        float *pForcesNeededToDriveStraight)
{
  int n_wheels; // edx
  int v7; // edi
  float *p_torque; // ecx
  unsigned int v9; // esi
  float *v10; // ecx
  int v11; // edx
  int p_wheel_is_fixed; // edi
  float *v13; // esi
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  int v24; // eax
  float v25; // xmm4_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  int v31; // ecx
  float v32[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Float_Point impulse; // [esp+0h] [ebp-40h] BYREF
  float v34; // [esp+20h] [ebp-20h]
  int v35; // [esp+24h] [ebp-1Ch]
  float v36; // [esp+28h] [ebp-18h]
  IVP_Controller_Raycast_Car *flMaxForce; // [esp+2Ch] [ebp-14h]
  int iWheel; // [esp+30h] [ebp-10h]
  float flFrForce; // [esp+34h] [ebp-Ch]
  void *v40; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  flFrForce = a2;
  v40 = retaddr;
  n_wheels = this->n_wheels;
  v7 = 0;
  flMaxForce = this;
  HIWORD(iWheel) = 0;
  if ( n_wheels >= 4 )
  {
    p_torque = &this->wheels_of_car[1].torque;
    v9 = ((unsigned int)(n_wheels - 4) >> 2) + 1;
    v7 = 4 * v9;
    do
    {
      if ( *(p_torque - 36) != 0.0 )
        HIBYTE(iWheel) = 1;
      if ( *p_torque != 0.0 )
        HIBYTE(iWheel) = 1;
      if ( p_torque[36] != 0.0 )
        HIBYTE(iWheel) = 1;
      if ( p_torque[72] != 0.0 )
        HIBYTE(iWheel) = 1;
      p_torque += 144;
      --v9;
    }
    while ( v9 != 0 );
    this = flMaxForce;
  }
  if ( v7 < n_wheels )
  {
    v10 = &this->wheels_of_car[v7].torque;
    v11 = n_wheels - v7;
    do
    {
      if ( *v10 != 0.0 )
        HIBYTE(iWheel) = 1;
      v10 += 36;
      --v11;
    }
    while ( v11 != 0 );
  }
  if ( fabs(IVP_U_Float_Point::fast_real_length(this: &pCarCore->speed)) < 0.5 && HIBYTE(iWheel) == 0 )
    BYTE2(iWheel) = 1;
  v35 = 0;
  if ( flMaxForce->n_wheels > 0 )
  {
    p_wheel_is_fixed = (int)&flMaxForce->wheels_of_car[0].wheel_is_fixed;
    v13 = &pTempWheels->spring_direction_ws.k[1];
    do
    {
      v14 = v13[16];
      v15 = v13[1];
      v16 = v13[17] * *v13;
      v34 = *(float *)(p_wheel_is_fixed + 56) * *(v13 - 13);
      v17 = (float)(v14 * v15) - v16;
      v18 = *(v13 - 1);
      impulse.k[1] = v17;
      v19 = (float)(v13[15] * *v13) - (float)(v18 * v14);
      impulse.k[2] = (float)(v18 * v13[17]) - (float)(v13[15] * v15);
      impulse.hesse_val = v19;
      IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&impulse.k[1]);
      v20 = (float)((float)(pCarCore->speed.k[0] * impulse.k[1]) + (float)(impulse.k[2] * pCarCore->speed.k[1]))
          + (float)(impulse.hesse_val * pCarCore->speed.k[2]);
      if ( *(_DWORD *)p_wheel_is_fixed != 0 || BYTE2(iWheel) != 0 )
      {
        v23 = (float)((float)(v20 * -0.5) * pCarCore->rot_inertia.hesse_val) * pEventSim->i_delta_time;
        *(_DWORD *)(p_wheel_is_fixed + 28) = 0;
      }
      else
      {
        v21 = *(float *)(p_wheel_is_fixed - 12);
        *(float *)(p_wheel_is_fixed + 28) = v21 * v20;
        if ( v20 < 0.0 )
          v22 = -1.0;
        else
          v22 = 1.0;
        v23 = (float)((float)((float)((float)(pCarCore->rot_inertia.hesse_val * 0.25) * *(v13 - 13)) * v22) * -2.5)
            + (float)(*(float *)(p_wheel_is_fixed - 4) * v21);
      }
      v24 = v35 / flMaxForce->wheels_per_axis;
      v36 = v23;
      v25 = pForcesNeededToDriveStraight[v24];
      v26 = v25;
      v27 = (float)(v26 * v26) + (float)(v23 * v23);
      if ( v27 > (float)(v34 * v34) )
      {
        v28 = fsqrt((float)(v34 * v34) / v27);
        v36 = v28 * v23;
        v26 = v28 * v25;
      }
      pForcesNeededToDriveStraight[v24] = v25 - v26;
      *(float *)(p_wheel_is_fixed + 24) = *(float *)(p_wheel_is_fixed + 24)
                                        - (float)(*(float *)(p_wheel_is_fixed + 28) * pEventSim->delta_time);
      v29 = pEventSim->delta_time * v26;
      v32[0] = v13[15] * v29;
      v32[1] = v29 * v13[16];
      v32[2] = v13[17] * v29;
      IVP_Core::push_core_ws(
        this: pCarCore,
        world_point: (const IVP_U_Point *)(v13 - 5),
        impulse_in_world: (const IVP_U_Float_Point *)v32);
      v30 = pEventSim->delta_time * v36;
      v32[0] = v30 * impulse.k[1];
      v32[1] = impulse.k[2] * v30;
      v32[2] = v30 * impulse.hesse_val;
      IVP_Core::push_core_ws(
        this: pCarCore,
        world_point: (const IVP_U_Point *)(v13 - 5),
        impulse_in_world: (const IVP_U_Float_Point *)v32);
      v31 = flMaxForce->n_wheels;
      p_wheel_is_fixed += 144;
      v13 += 36;
      ++v35;
    }
    while ( v35 < v31 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C060
// Name: public: virtual void IVP_Controller_Raycast_Car::do_steering_wheel(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::do_steering_wheel(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL wheel_nr,
        float s_angle)
{
  IVP_Raycast_Car_Wheel *v3; // edx

  v3 = &this->wheels_of_car[wheel_nr];
  v3->axis_direction_cs.k[2] = 0.0;
  v3->axis_direction_cs.k[1] = 0.0;
  v3->axis_direction_cs.k[0] = 0.0;
  v3->axis_direction_cs.k[this->index_x] = 1.0;
  IVP_U_Float_Point::rotate(this: &this->wheels_of_car[wheel_nr].axis_direction_cs, axis: this->index_y, angle: s_angle);
}

//------------------------------------------------------------------------------
// Address: 0x1007C0C0
// Name: public: virtual void IVP_Controller_Raycast_Car::change_spring_constant(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_spring_constant(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float spring_constant)
{
  this->wheels_of_car[pos].spring_constant = spring_constant;
}

//------------------------------------------------------------------------------
// Address: 0x1007C0E0
// Name: public: virtual void IVP_Controller_Raycast_Car::change_spring_dampening(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_spring_dampening(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float spring_dampening)
{
  this->wheels_of_car[pos].spring_damp_relax = spring_dampening;
}

//------------------------------------------------------------------------------
// Address: 0x1007C100
// Name: public: virtual void IVP_Controller_Raycast_Car::change_spring_dampening_compression(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_spring_dampening_compression(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float spring_dampening)
{
  this->wheels_of_car[pos].spring_damp_compress = spring_dampening;
}

//------------------------------------------------------------------------------
// Address: 0x1007C120
// Name: public: virtual void IVP_Controller_Raycast_Car::change_spring_pre_tension(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_spring_pre_tension(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float pre_tension_length)
{
  this->wheels_of_car[pos].spring_len = (float)(this->wheels_of_car[pos].distance_orig_hp_to_hp - pre_tension_length)
                                      * this->gravity_y_direction;
}

//------------------------------------------------------------------------------
// Address: 0x1007C150
// Name: public: virtual void IVP_Controller_Raycast_Car::change_spring_length(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_spring_length(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float spring_length)
{
  this->wheels_of_car[pos].spring_len = spring_length;
}

//------------------------------------------------------------------------------
// Address: 0x1007C170
// Name: public: virtual void IVP_Controller_Raycast_Car::change_wheel_torque(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_wheel_torque(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        float torque)
{
  IVP_Controller_Dependent *v3; // eax

  this->wheels_of_car[pos].torque = torque;
  if ( this != nullptr )
    v3 = &this->IVP_Controller_Dependent;
  else
    v3 = nullptr;
  IVP_Controller_Manager::ensure_controller_in_simulation(
    this: this->car_body->environment->controller_manager,
    cntrl: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007C1B0
// Name: public: virtual float IVP_Controller_Raycast_Car::get_wheel_torque(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Controller_Raycast_Car::get_wheel_torque(IVP_Controller_Raycast_Car *this, IVP_POS_WHEEL pos)
{
  return this->wheels_of_car[pos].torque;
}

//------------------------------------------------------------------------------
// Address: 0x1007C1D0
// Name: public: virtual void IVP_Controller_Raycast_Car::fix_wheel(enum IVP_POS_WHEEL,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::fix_wheel(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos,
        IVP_BOOL stop_wheel)
{
  this->wheels_of_car[pos].wheel_is_fixed = stop_wheel;
}

//------------------------------------------------------------------------------
// Address: 0x1007C1F0
// Name: public: virtual void IVP_Controller_Raycast_Car::change_stabilizer_constant(enum IVP_POS_AXIS,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_stabilizer_constant(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_AXIS pos,
        float stabi_constant)
{
  this->axis_of_car[pos].stabilizer_constant = stabi_constant;
}

//------------------------------------------------------------------------------
// Address: 0x1007C210
// Name: public: virtual void IVP_Controller_Raycast_Car::change_body_downforce(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::change_body_downforce(IVP_Controller_Raycast_Car *this, float force)
{
  this->down_force = force;
}

//------------------------------------------------------------------------------
// Address: 0x1007C230
// Name: public: virtual void IVP_Controller_Raycast_Car::set_booster_acceleration(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::set_booster_acceleration(
        IVP_Controller_Raycast_Car *this,
        float acceleration)
{
  this->booster_force = acceleration;
}

//------------------------------------------------------------------------------
// Address: 0x1007C250
// Name: public: virtual void IVP_Controller_Raycast_Car::activate_booster(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::activate_booster(
        IVP_Controller_Raycast_Car *this,
        float thrust,
        float duration,
        float delay)
{
  if ( this->booster_force == 0.0 && this->booster_seconds_until_ready <= 0.0 )
  {
    this->booster_force = thrust;
    this->booster_seconds_to_go = duration;
    this->booster_seconds_until_ready = duration + delay;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C2A0
// Name: public: virtual float IVP_Controller_Raycast_Car::get_booster_delay(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Controller_Raycast_Car::get_booster_delay(IVP_Controller_Raycast_Car *this)
{
  return this->booster_seconds_until_ready;
}

//------------------------------------------------------------------------------
// Address: 0x1007C2B0
// Name: public: virtual void IVP_Controller_Raycast_Car::do_steering(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::do_steering(
        IVP_Controller_Raycast_Car *this,
        float steering_angle_in,
        bool bAnalog)
{
  IVP_Real_Object *car_body; // eax
  int i; // edi

  if ( this->steering_angle != steering_angle_in )
  {
    car_body = this->car_body;
    this->steering_angle = steering_angle_in;
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: car_body->environment->controller_manager,
      cntrl: &this->IVP_Controller_Dependent);
    for ( i = 0;
          i < this->wheels_per_axis;
          ((void (__thiscall *)(IVP_Controller_Raycast_Car *, int, _DWORD))this->do_steering_wheel)(
            a1: this,
            a2: i++,
            a3: LODWORD(steering_angle_in)) )
    {
      ;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C320
// Name: public: virtual float IVP_Controller_Raycast_Car::get_wheel_angular_velocity(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Controller_Raycast_Car::get_wheel_angular_velocity(
        IVP_Controller_Raycast_Car *this,
        IVP_POS_WHEEL pos)
{
  return this->wheels_of_car[pos].wheel_angular_velocity;
}

//------------------------------------------------------------------------------
// Address: 0x1007C340
// Name: public: virtual float IVP_Controller_Raycast_Car::get_body_speed(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Controller_Raycast_Car::get_body_speed(
        IVP_Controller_Raycast_Car *this,
        IVP_COORDINATE_INDEX index)
{
  IVP_Core *physical_core; // eax

  physical_core = this->car_body->physical_core;
  return physical_core->m_world_f_core_last_psi.rows[0].k[index] * physical_core->speed.k[0]
       + physical_core->m_world_f_core_last_psi.rows[1].k[index] * physical_core->speed.k[1]
       + physical_core->m_world_f_core_last_psi.rows[2].k[index] * physical_core->speed.k[2];
}

//------------------------------------------------------------------------------
// Address: 0x1007C390
// Name: public: virtual float IVP_Controller_Raycast_Car::get_orig_front_wheel_distance(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall IVP_Controller_Raycast_Car::get_orig_front_wheel_distance(IVP_Controller_Raycast_Car *this)
{
  return fabs(this->wheels_of_car[0].hp_cs.k[this->index_x] - this->wheels_of_car[1].hp_cs.k[this->index_x]);
}

//------------------------------------------------------------------------------
// Address: 0x1007C3B0
// Name: public: virtual float IVP_Controller_Raycast_Car::get_orig_axles_distance(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall IVP_Controller_Raycast_Car::get_orig_axles_distance(IVP_Controller_Raycast_Car *this)
{
  return fabs(this->wheels_of_car[0].hp_cs.k[this->index_z] - this->wheels_of_car[2].hp_cs.k[this->index_z]);
}

//------------------------------------------------------------------------------
// Address: 0x1007C3D0
// Name: public: virtual void IVP_Controller_Raycast_Car::get_skid_info(class IVP_Wheel_Skid_Info __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::get_skid_info(
        IVP_Controller_Raycast_Car *this,
        IVP_Wheel_Skid_Info *array_of_skid_info_out)
{
  int v2; // edx
  float *v3; // eax

  v2 = 0;
  if ( this->n_wheels > 0 )
  {
    v3 = &array_of_skid_info_out->last_contact_position_ws.k[1];
    do
    {
      v3[1] = 0.0;
      *v3 = 0.0;
      *(v3 - 1) = 0.0;
      v3[3] = 0.0;
      v3[5] = 0.0;
      v3[6] = 0.0;
      ++v2;
      v3 += 8;
    }
    while ( v2 < this->n_wheels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007C430
// Name: protected: void IVP_Controller_Raycast_Car::InitRaycastCarEnvironment(class IVP_Environment __near *,class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::InitRaycastCarEnvironment(
        IVP_Controller_Raycast_Car *this,
        IVP_Environment *pEnvironment,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  IVP_COORDINATE_INDEX index_y; // ecx
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  this->index_x = pCarSystemTemplate->index_x;
  this->index_y = pCarSystemTemplate->index_y;
  this->index_z = pCarSystemTemplate->index_z;
  this->is_left_handed = pCarSystemTemplate->is_left_handed;
  IVP_Controller_Manager::announce_controller_to_environment(
    this: pEnvironment->controller_manager,
    cntrl: &this->IVP_Controller_Dependent);
  index_y = this->index_y;
  this->extra_gravity = pCarSystemTemplate->extra_gravity_force_value;
  if ( pEnvironment->gravity.k[index_y] <= 0.0 )
    v5 = -1.0;
  else
    v5 = 1.0;
  this->gravity_y_direction = v5;
  v6 = pEnvironment->gravity.k[1];
  v7 = pEnvironment->gravity.k[2];
  this->normized_gravity_ws.k[0] = pEnvironment->gravity.k[0];
  this->normized_gravity_ws.k[1] = v6;
  this->normized_gravity_ws.k[2] = v7;
  IVP_U_Float_Point::fast_normize(this: &this->normized_gravity_ws);
}

//------------------------------------------------------------------------------
// Address: 0x1007C4F0
// Name: public: virtual void IVP_Controller_Raycast_Car::SetCarSystemDebugData(struct IVP_CarSystemDebugData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::SetCarSystemDebugData(
        IVP_Controller_Raycast_Car *this,
        const IVP_CarSystemDebugData_t *carSystemDebugData)
{
  this->m_CarSystemDebugData.wheelRaycasts[0][0] = carSystemDebugData->wheelRaycasts[0][0];
  this->m_CarSystemDebugData.wheelRaycasts[0][1] = carSystemDebugData->wheelRaycasts[0][1];
  this->m_CarSystemDebugData.wheelRaycastImpacts[0] = carSystemDebugData->wheelRaycastImpacts[0];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[1],
    carSystemDebugData->wheelRaycasts[1],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[1]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[1] = carSystemDebugData->wheelRaycastImpacts[1];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[2],
    carSystemDebugData->wheelRaycasts[2],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[2]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[2] = carSystemDebugData->wheelRaycastImpacts[2];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[3],
    carSystemDebugData->wheelRaycasts[3],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[3]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[3] = carSystemDebugData->wheelRaycastImpacts[3];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[4],
    carSystemDebugData->wheelRaycasts[4],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[4]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[4] = carSystemDebugData->wheelRaycastImpacts[4];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[5],
    carSystemDebugData->wheelRaycasts[5],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[5]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[5] = carSystemDebugData->wheelRaycastImpacts[5];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[6],
    carSystemDebugData->wheelRaycasts[6],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[6]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[6] = carSystemDebugData->wheelRaycastImpacts[6];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[7],
    carSystemDebugData->wheelRaycasts[7],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[7]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[7] = carSystemDebugData->wheelRaycastImpacts[7];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[8],
    carSystemDebugData->wheelRaycasts[8],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[8]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[8] = carSystemDebugData->wheelRaycastImpacts[8];
  qmemcpy(
    this->m_CarSystemDebugData.wheelRaycasts[9],
    carSystemDebugData->wheelRaycasts[9],
    sizeof(this->m_CarSystemDebugData.wheelRaycasts[9]));
  this->m_CarSystemDebugData.wheelRaycastImpacts[9] = carSystemDebugData->wheelRaycastImpacts[9];
}

//------------------------------------------------------------------------------
// Address: 0x1007C7D0
// Name: public: virtual void IVP_Controller_Raycast_Car::GetCarSystemDebugData(struct IVP_CarSystemDebugData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::GetCarSystemDebugData(
        IVP_Controller_Raycast_Car *this,
        IVP_CarSystemDebugData_t *carSystemDebugData)
{
  carSystemDebugData->wheelRaycasts[0][0] = this->m_CarSystemDebugData.wheelRaycasts[0][0];
  carSystemDebugData->wheelRaycasts[0][1] = this->m_CarSystemDebugData.wheelRaycasts[0][1];
  carSystemDebugData->wheelRaycastImpacts[0] = this->m_CarSystemDebugData.wheelRaycastImpacts[0];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[1],
    this->m_CarSystemDebugData.wheelRaycasts[1],
    sizeof(carSystemDebugData->wheelRaycasts[1]));
  carSystemDebugData->wheelRaycastImpacts[1] = this->m_CarSystemDebugData.wheelRaycastImpacts[1];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[2],
    this->m_CarSystemDebugData.wheelRaycasts[2],
    sizeof(carSystemDebugData->wheelRaycasts[2]));
  carSystemDebugData->wheelRaycastImpacts[2] = this->m_CarSystemDebugData.wheelRaycastImpacts[2];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[3],
    this->m_CarSystemDebugData.wheelRaycasts[3],
    sizeof(carSystemDebugData->wheelRaycasts[3]));
  carSystemDebugData->wheelRaycastImpacts[3] = this->m_CarSystemDebugData.wheelRaycastImpacts[3];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[4],
    this->m_CarSystemDebugData.wheelRaycasts[4],
    sizeof(carSystemDebugData->wheelRaycasts[4]));
  carSystemDebugData->wheelRaycastImpacts[4] = this->m_CarSystemDebugData.wheelRaycastImpacts[4];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[5],
    this->m_CarSystemDebugData.wheelRaycasts[5],
    sizeof(carSystemDebugData->wheelRaycasts[5]));
  carSystemDebugData->wheelRaycastImpacts[5] = this->m_CarSystemDebugData.wheelRaycastImpacts[5];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[6],
    this->m_CarSystemDebugData.wheelRaycasts[6],
    sizeof(carSystemDebugData->wheelRaycasts[6]));
  carSystemDebugData->wheelRaycastImpacts[6] = this->m_CarSystemDebugData.wheelRaycastImpacts[6];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[7],
    this->m_CarSystemDebugData.wheelRaycasts[7],
    sizeof(carSystemDebugData->wheelRaycasts[7]));
  carSystemDebugData->wheelRaycastImpacts[7] = this->m_CarSystemDebugData.wheelRaycastImpacts[7];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[8],
    this->m_CarSystemDebugData.wheelRaycasts[8],
    sizeof(carSystemDebugData->wheelRaycasts[8]));
  carSystemDebugData->wheelRaycastImpacts[8] = this->m_CarSystemDebugData.wheelRaycastImpacts[8];
  qmemcpy(
    carSystemDebugData->wheelRaycasts[9],
    this->m_CarSystemDebugData.wheelRaycasts[9],
    sizeof(carSystemDebugData->wheelRaycasts[9]));
  carSystemDebugData->wheelRaycastImpacts[9] = this->m_CarSystemDebugData.wheelRaycastImpacts[9];
}

//------------------------------------------------------------------------------
// Address: 0x1007CAB0
// Name: protected: void IVP_Controller_Raycast_Car::InitRaycastCarWheels(class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Raycast_Car::InitRaycastCarWheels(
        IVP_Controller_Raycast_Car *this@<ecx>,
        int a2@<ebp>,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  IVP_Real_Object *car_body; // ecx
  float *spring_constant; // edi
  float *v6; // esi
  float v7; // ecx
  int v8; // edx
  double v9; // st7
  int v10; // eax
  float v11; // ecx
  int v12; // edx
  _BYTE v13[12]; // [esp+14h] [ebp-5Ch] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+20h] [ebp-50h]
  int v15; // [esp+60h] [ebp-10h]
  int v16; // [esp+64h] [ebp-Ch]
  void *v17; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  car_body = this->car_body;
  LODWORD(m_core_f_object.vv.k[2]) = this;
  IVP_Real_Object::calc_m_core_f_object(this: car_body, m_core_f_object: (IVP_U_Matrix *)v13);
  v15 = 0;
  if ( this->n_wheels > 0 )
  {
    spring_constant = pCarSystemTemplate->spring_constant;
    LODWORD(m_core_f_object.vv.hesse_val) = pCarSystemTemplate->wheel_pos_Bos;
    v6 = &this->wheels_of_car[0].spring_direction_cs.k[1];
    do
    {
      memset(dst: (unsigned __int8 *)v6 - 20, value: 0, count: 0x90u);
      IVP_U_Matrix::vmult4(
        this: (IVP_U_Matrix *)v13,
        p_in: (const IVP_U_Float_Point *)LODWORD(m_core_f_object.vv.hesse_val),
        p_out: (IVP_U_Float_Point *)(v6 - 5));
      v7 = m_core_f_object.vv.k[2];
      *((_DWORD *)v6 + 4) = *((_DWORD *)spring_constant + 40) ^ _mask__NegFloat_;
      *(_QWORD *)v6 = 0;
      *(v6 - 1) = 0.0;
      v6[*(_DWORD *)(LODWORD(v7) + 1816) - 1] = *(float *)(LODWORD(v7) + 1788);
      v8 = v15;
      v6[5] = *spring_constant;
      v6[6] = spring_constant[10];
      v9 = spring_constant[20];
      v6[11] = 1.0;
      v6[7] = v9;
      v6[9] = *(spring_constant - 105);
      v6[10] = 1.0 / *(spring_constant - 105);
      (*(void (__thiscall **)(float, int, _DWORD))(*(_DWORD *)LODWORD(v7) + 4))(
        a1: COERCE_FLOAT(LODWORD(v7)),
        a2: v8,
        a3: 0);
      v10 = v15;
      LODWORD(m_core_f_object.vv.hesse_val) += 16;
      v6[13] = 0.0;
      v11 = m_core_f_object.vv.k[2];
      v6[8] = pCarSystemTemplate->wheel_max_rotation_speed[v10 >> 1];
      v12 = *(__int16 *)(LODWORD(v11) + 20);
      ++spring_constant;
      v6 += 36;
      v15 = v10 + 1;
    }
    while ( v10 + 1 < v12 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CBF0
// Name: protected: void IVP_Controller_Raycast_Car::CalcSteeringForces(class IVP_Raycast_Car_Wheel_Temp __near *,class IVP_Core __near *,class IVP_Event_Sim __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Controller_Raycast_Car::CalcSteeringForces(
        IVP_Controller_Raycast_Car *this@<ecx>,
        int a2@<ebp>,
        IVP_Raycast_Car_Wheel_Temp *pTempWheels,
        IVP_Core *pCarCore,
        IVP_Event_Sim *pEventSim,
        float *pForcesNeededToDriveStraight)
{
  IVP_U_Float_Point *p_axis_direction_ws; // esi
  float v7; // xmm4_4
  float v8; // xmm0_4
  float i_delta_time; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  int v14; // [esp+14h] [ebp-27Ch] BYREF
  IVP_Solver_Core_Reaction coreReactionSolver[2]; // [esp+20h] [ebp-270h] BYREF
  IVP_U_Point backPosWS; // [esp+260h] [ebp-30h] BYREF
  int v17; // [esp+280h] [ebp-10h]
  int v18; // [esp+284h] [ebp-Ch]
  void *v19; // [esp+288h] [ebp-8h]
  void *retaddr; // [esp+290h] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  if ( this->wheels_per_axis == 2 )
  {
    IVP_U_Float_Point::set_interpolate(
      this: (IVP_U_Point *)&backPosWS.k[1],
      p0: &pTempWheels->ground_hit_ws,
      p1: &pTempWheels[1].ground_hit_ws,
      s: 0.5);
    IVP_U_Float_Point::set_interpolate(
      this: (IVP_U_Float_Point *)&coreReactionSolver[1].delta_velocity_ds.k[1],
      p0: &pTempWheels[2].ground_hit_ws,
      p1: &pTempWheels[3].ground_hit_ws,
      s: 0.5);
    v17 = 2;
  }
  else
  {
    backPosWS.k[1] = pTempWheels->ground_hit_ws.k[0];
    backPosWS.k[2] = pTempWheels->ground_hit_ws.k[1];
    backPosWS.hesse_val = pTempWheels->ground_hit_ws.k[2];
    coreReactionSolver[1].delta_velocity_ds.k[1] = pTempWheels[1].ground_hit_ws.k[0];
    coreReactionSolver[1].delta_velocity_ds.k[2] = pTempWheels[1].ground_hit_ws.k[1];
    coreReactionSolver[1].delta_velocity_ds.hesse_val = pTempWheels[1].ground_hit_ws.k[2];
    v17 = 1;
  }
  IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
    this: (IVP_Solver_Core_Reaction *)&v14,
    core_0: pCarCore,
    core_1: nullptr,
    pos_ws: (IVP_U_Point *)&backPosWS.k[1],
    direction_0_ws: &pTempWheels->axis_direction_ws,
    direction_1_ws: nullptr,
    direction_2_ws: nullptr);
  p_axis_direction_ws = &pTempWheels[v17].axis_direction_ws;
  IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
    this: (IVP_Solver_Core_Reaction *)&coreReactionSolver[0].delta_velocity_ds.k[1],
    core_0: pCarCore,
    core_1: nullptr,
    pos_ws: (IVP_U_Point *)&coreReactionSolver[1].delta_velocity_ds.k[1],
    direction_0_ws: p_axis_direction_ws,
    direction_1_ws: nullptr,
    direction_2_ws: nullptr);
  v7 = coreReactionSolver[1].cr_mult_inv1[2].k[1];
  v8 = (float)((float)((float)((float)(p_axis_direction_ws->k[1] * pTempWheels->axis_direction_ws.k[1])
                             + (float)(pTempWheels->axis_direction_ws.k[0] * p_axis_direction_ws->k[0]))
                     + (float)(p_axis_direction_ws->k[2] * pTempWheels->axis_direction_ws.k[2]))
             * pCarCore->inv_rot_inertia.hesse_val)
     + (float)((float)((float)(*(float *)&coreReactionSolver[1].direction_ws[2]
                             * *(float *)&coreReactionSolver[0].m_world_f_core_last_psi[2])
                     + (float)(*(float *)&coreReactionSolver[1].direction_ws[1]
                             * *(float *)&coreReactionSolver[0].m_world_f_core_last_psi[1]))
             + (float)(*(float *)&coreReactionSolver[1].direction_ws[3]
                     * *(float *)&coreReactionSolver[0].m_world_f_core_last_psi[3]));
  i_delta_time = pEventSim->i_delta_time;
  v10 = (float)(i_delta_time * coreReactionSolver[1].m_velocity_ds_f_impulse_ds.rows[2].k[1]) * -1.2;
  v11 = (float)(i_delta_time * coreReactionSolver[0].m_velocity_ds_f_impulse_ds.rows[2].k[1]) * -1.2;
  v12 = (float)(coreReactionSolver[1].cr_mult_inv1[2].k[1] * coreReactionSolver[0].cr_mult_inv1[2].k[1])
      - (float)(v8 * v8);
  if ( (float)(v12 * v12) < 1.0e-20 )
  {
    *(_QWORD *)pForcesNeededToDriveStraight = 0;
  }
  else
  {
    LODWORD(v13) = COERCE_UNSIGNED_INT((float)(1.0 / v12) * v8) ^ _mask__NegFloat_;
    pForcesNeededToDriveStraight[1] = (float)((float)((float)(1.0 / v12) * coreReactionSolver[0].cr_mult_inv1[2].k[1])
                                            * v10)
                                    + (float)(v13 * v11);
    *pForcesNeededToDriveStraight = (float)(v13 * v10) + (float)((float)(v7 * (float)(1.0 / v12)) * v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007CE30
// Name: protected: void IVP_Controller_Raycast_Car::InitRaycastCarBody(class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::InitRaycastCarBody(
        IVP_Controller_Raycast_Car *this,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  __int16 n_axis; // ax
  IVP_Real_Object *car_body; // eax
  const IVP_Template_Car_System *pCarSystemTemplatea; // [esp+14h] [ebp+8h]

  this->n_wheels = pCarSystemTemplate->n_wheels;
  n_axis = pCarSystemTemplate->n_axis;
  this->n_axis = n_axis;
  this->wheels_per_axis = this->n_wheels / n_axis;
  car_body = pCarSystemTemplate->car_body;
  this->car_body = car_body;
  pCarSystemTemplatea = (const IVP_Template_Car_System *)car_body->physical_core;
  if ( this->vector_of_cores.n_elems >= this->vector_of_cores.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->vector_of_cores);
  this->vector_of_cores.elems[this->vector_of_cores.n_elems++] = (void *)pCarSystemTemplatea;
  this->booster_force = 0.0;
  *(_QWORD *)&this->booster_seconds_to_go = 0;
  this->down_force_vertical_offset = pCarSystemTemplate->body_down_force_vertical_offset;
  this->down_force = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1007CED0
// Name: public: virtual IVP_Controller_Raycast_Car::~IVP_Controller_Raycast_Car(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Controller_Raycast_Car::~IVP_Controller_Raycast_Car(IVP_Controller_Raycast_Car *this)
{
  IVP_Controller_Dependent *v2; // edi
  IVP_Controller_Raycast_Car *elems; // eax

  v2 = &this->IVP_Controller_Dependent;
  this->IVP_Car_System::__vftable = (IVP_Controller_Raycast_Car_vtbl *)&IVP_Controller_Raycast_Car::`vftable'{for `IVP_Car_System'};
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&IVP_Controller_Raycast_Car::`vftable'{for `IVP_Controller_Dependent'};
  IVP_Controller_Manager::remove_controller_from_environment(cntrl: &this->IVP_Controller_Dependent, silently: IVP_TRUE);
  elems = (IVP_Controller_Raycast_Car *)this->vector_of_cores.elems;
  if ( elems != (IVP_Controller_Raycast_Car *)this->vector_of_cores.elem_buffer )
  {
    if ( elems != nullptr )
      free(data: this->vector_of_cores.elems);
    this->vector_of_cores.elems = nullptr;
    this->vector_of_cores.memsize = 0;
  }
  this->vector_of_cores.n_elems = 0;
  v2->__vftable = (IVP_Controller_Dependent_vtbl *)&IVP_Controller_Dependent::`vftable';
  IVP_Car_System::~IVP_Car_System(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007CF70
// Name: public: IVP_Controller_Raycast_Car::IVP_Controller_Raycast_Car(class IVP_Environment __near *,class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Controller_Raycast_Car *__thiscall IVP_Controller_Raycast_Car::IVP_Controller_Raycast_Car(
        IVP_Controller_Raycast_Car *this,
        IVP_Environment *pEnvironment,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  void (__thiscall *do_steering)(struct IVP_Controller_Raycast_Car *, float, bool); // eax
  int v5; // edx
  IVP_Raycast_Car_Axis *axis_of_car; // ecx
  float *stabilizer_constant; // eax
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  IVP_Car_System::IVP_Car_System(this);
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&IVP_Controller_Dependent::`vftable';
  this->IVP_Car_System::__vftable = (IVP_Controller_Raycast_Car_vtbl *)&IVP_Controller_Raycast_Car::`vftable'{for `IVP_Car_System'};
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&IVP_Controller_Raycast_Car::`vftable'{for `IVP_Controller_Dependent'};
  this->vector_of_cores.elems = this->vector_of_cores.elem_buffer;
  *(_DWORD *)&this->vector_of_cores.memsize = 1;
  IVP_Controller_Raycast_Car::InitRaycastCarBody(this, pCarSystemTemplate);
  IVP_Controller_Raycast_Car::InitRaycastCarEnvironment(this, pEnvironment, pCarSystemTemplate);
  IVP_Controller_Raycast_Car::InitRaycastCarWheels(this, a2: (int)&savedregs, pCarSystemTemplate);
  do_steering = this->do_steering;
  this->steering_angle = -1.0;
  ((void (__thiscall *)(IVP_Controller_Raycast_Car *, _DWORD, _DWORD))do_steering)(a1: this, a2: 0, a3: 0);
  v5 = 0;
  if ( this->n_axis > 0 )
  {
    axis_of_car = this->axis_of_car;
    stabilizer_constant = pCarSystemTemplate->stabilizer_constant;
    do
    {
      ++v5;
      axis_of_car->stabilizer_constant = *stabilizer_constant++;
      ++axis_of_car;
    }
    while ( v5 < this->n_axis );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007D020
// Name: protected: virtual void IVP_Controller_Raycast_Car::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge IVP_Controller_Raycast_Car::do_simulation_controller(
        IVP_Controller_Raycast_Car *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *v6; // esi
  IVP_Controller_Raycast_Car *v7; // edi
  float v8; // xmm1_4
  float v9; // xmm2_4
  float gravity_y_direction; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  _BYTE v17[12]; // [esp-Ch] [ebp-AFCh] BYREF
  IVP_Raycast_Car_Wheel_Temp wt[12]; // [esp+0h] [ebp-AF0h] BYREF
  IVP_Ray_Solver_Template rst[12]; // [esp+6C0h] [ebp-430h] BYREF
  float v20[3]; // [esp+A80h] [ebp-70h] BYREF
  float frictions[17]; // [esp+A8Ch] [ebp-64h] BYREF
  IVP_Raycast_Car_Wheel_Temp *v22; // [esp+AD0h] [ebp-20h]
  IVP_RAY_SOLVER_FLAGS *p_ray_flags; // [esp+AD4h] [ebp-1Ch]
  IVP_Event_Sim *v24; // [esp+AD8h] [ebp-18h]
  IVP_Core *v25; // [esp+ADCh] [ebp-14h]
  IVP_Controller_Raycast_Car *v26; // [esp+AE0h] [ebp-10h]
  _DWORD v27[3]; // [esp+AE4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+AF0h] [ebp+0h]

  v27[0] = a2;
  v27[1] = retaddr;
  v6 = *(IVP_Core **)(LODWORD(this->axis_of_car[5].stabilizer_constant) + 148);
  v26 = this;
  v7 = (IVP_Controller_Raycast_Car *)((char *)this - 4);
  IVP_Controller_Raycast_Car::SetupWheelRaycasts(
    this: (IVP_Controller_Raycast_Car *)((char *)this - 4),
    pRaySolverTemplates: (IVP_Ray_Solver_Template *)&wt[11].inv_normal_dot_dir,
    m_world_f_core: &v6->m_world_f_core_last_psi,
    pTempWheels: (IVP_Raycast_Car_Wheel_Temp *)v17);
  ((void (__thiscall *)(IVP_Controller_Raycast_Car *, IVP_Event_Sim *, _DWORD, float *, IVP_RAY_SOLVER_FLAGS *, float *, int, int))v7->do_raycasts)(
    a1: v7,
    a2: es,
    a3: SLOWORD(v26->vector_of_cores.elem_buffer[0]),
    a4: &wt[11].inv_normal_dot_dir,
    a5: &rst[11].ray_flags,
    a6: v20,
    a7: a3,
    a8: a4);
  if ( IVP_Controller_Raycast_Car::DoSimulationWheels(
         this: v7,
         pRaySolverTemplates: (IVP_Ray_Solver_Template *)&wt[11].inv_normal_dot_dir,
         m_world_f_core: &v6->m_world_f_core_last_psi,
         pTempWheels: (IVP_Raycast_Car_Wheel_Temp *)v17,
         pRayHits: (IVP_Ray_Hit *)&rst[11].ray_flags,
         pFrictions: v20,
         pCarCore: v6) != 0 )
  {
    IVP_Controller_Raycast_Car::DoSimulationStabilizers(this: v7, pTempWheels: (IVP_Raycast_Car_Wheel_Temp *)v17);
    v8 = v26->normized_gravity_ws.k[0];
    v9 = v26->normized_gravity_ws.k[1];
    gravity_y_direction = v26->gravity_y_direction;
    v11 = (float)(*(float *)&v26->is_left_handed * v6->inv_rot_inertia.hesse_val) * es->delta_time;
    v25 = v6;
    v24 = es;
    p_ray_flags = &rst[11].ray_flags;
    v12 = (float)(v8 * v11) + v6->speed.k[1];
    v13 = (float)(v9 * v11) + v6->speed.k[2];
    v14 = (float)(gravity_y_direction * v11) + v6->speed.k[0];
    v22 = (IVP_Raycast_Car_Wheel_Temp *)v17;
    v6->speed.k[0] = v14;
    v6->speed.k[1] = v12;
    v6->speed.k[2] = v13;
    IVP_Controller_Raycast_Car::DoSimulationShocks(
      this: v7,
      a2: (int)v27,
      pTempWheels: v22,
      pRayHits: (IVP_Ray_Hit *)p_ray_flags,
      pEventSim: v24,
      pCarCore: v25);
    IVP_Controller_Raycast_Car::DoSimulationBooster(this: v7, pEventSim: es, pCarCore: v6);
    IVP_Controller_Raycast_Car::CalcSteeringForces(
      this: v7,
      a2: (int)v27,
      pTempWheels: (IVP_Raycast_Car_Wheel_Temp *)v17,
      pCarCore: v6,
      pEventSim: es,
      pForcesNeededToDriveStraight: &frictions[9]);
    IVP_Controller_Raycast_Car::ApplySteeringForces(
      this: v7,
      a2: COERCE_FLOAT(v27),
      pTempWheels: (IVP_Raycast_Car_Wheel_Temp *)v17,
      pCarCore: v6,
      pEventSim: es,
      pForcesNeededToDriveStraight: &frictions[9]);
  }
}
