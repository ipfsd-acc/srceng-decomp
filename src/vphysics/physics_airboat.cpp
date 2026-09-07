// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_airboat.cpp
// Functions: 52
// ============================================================

#include "vphysics\physics_airboat.h"

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: protected: void CPhysics_Airboat::InitAirboat(class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::InitAirboat(CPhysics_Airboat *this, const IVP_Template_Car_System *pCarSystem)
{
  const IVP_Template_Car_System *v2; // esi
  int v3; // ebx
  IVP_Real_Object **m_pWheels; // edi
  IVP_Real_Object **car_wheel; // esi
  IVP_Real_Object *v6; // ecx
  int *client_data; // esi
  int v8; // edi
  __int16 v9; // ax

  v2 = pCarSystem;
  v3 = 0;
  if ( pCarSystem->n_wheels > 0 )
  {
    m_pWheels = this->m_pWheels;
    car_wheel = pCarSystem->car_wheel;
    do
    {
      v6 = *car_wheel;
      *m_pWheels = *car_wheel;
      IVP_Real_Object::enable_collision_detection(this: v6, enable: IVP_FALSE);
      ++v3;
      ++car_wheel;
      ++m_pWheels;
    }
    while ( v3 < pCarSystem->n_wheels );
    v2 = pCarSystem;
  }
  client_data = (int *)v2->car_body->client_data;
  (*(void (__thiscall **)(int *, _DWORD))(*client_data + 52))(a1: client_data, a2: 0);
  v8 = *client_data;
  v9 = (*(int (__thiscall **)(int *))(*client_data + 92))(a1: client_data);
  (*(void (__thiscall **)(int *, int))(v8 + 88))(a1: client_data, a2: v9 & 0xEFFF);
}

//------------------------------------------------------------------------------
// Address: 0x10003960
// Name: public: class IPhysicsObject __near * CPhysics_Airboat::GetWheel(int)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CPhysics_Airboat::GetWheel(CPhysics_Airboat *this, int index)
{
  return (IPhysicsObject *)this->m_pWheels[index]->client_data;
}

//------------------------------------------------------------------------------
// Address: 0x10003980
// Name: public: virtual void CPhysics_Airboat::update_throttle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::update_throttle(CPhysics_Airboat *this, float flThrottle)
{
  if ( COERCE_FLOAT(LODWORD(flThrottle) & _mask__AbsFloat_) >= 0.0099999998 )
  {
    if ( flThrottle <= 0.0 )
    {
      if ( flThrottle < 0.0 )
        this->m_flThrust = flThrottle * 7.5;
    }
    else
    {
      this->m_flThrust = flThrottle * 11.0;
    }
  }
  else
  {
    this->m_flThrust = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039F0
// Name: public: virtual void CPhysics_Airboat::change_body_downforce(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_body_downforce(CPhysics_Airboat *this, float force)
{
  this->down_force = force;
}

//------------------------------------------------------------------------------
// Address: 0x10003A20
// Name: public: virtual void CPhysics_Airboat::SetCarSystemDebugData(struct IVP_CarSystemDebugData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::SetCarSystemDebugData(
        CPhysics_Airboat *this,
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
}

//------------------------------------------------------------------------------
// Address: 0x10003B30
// Name: public: virtual void CPhysics_Airboat::GetCarSystemDebugData(struct IVP_CarSystemDebugData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::GetCarSystemDebugData(
        CPhysics_Airboat *this,
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
}

//------------------------------------------------------------------------------
// Address: 0x10003C60
// Name: public: virtual char const __near * IVP_Controller::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Controller::get_controller_name(IVP_Controller *this)
{
  return "sys";
}

//------------------------------------------------------------------------------
// Address: 0x10003C70
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = (float)((float)((float)(this->m_Extents.x * this->m_Extents.x)
                                + (float)(this->m_Extents.y * this->m_Extents.y))
                        + (float)(this->m_Extents.z * this->m_Extents.z)) < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10003E40
// Name: public: virtual void CAirboatFrictionData::GetSurfaceNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAirboatFrictionData::GetSurfaceNormal(CAirboatFrictionData *this, Vector *out)
{
  *out = this->m_vecPoint;
}

//------------------------------------------------------------------------------
// Address: 0x10003E60
// Name: public: virtual void CAirboatFrictionData::GetContactPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAirboatFrictionData::GetContactPoint(CAirboatFrictionData *this, Vector *out)
{
  *out = this->m_vecNormal;
}

//------------------------------------------------------------------------------
// Address: 0x10003E80
// Name: public: virtual void CAirboatFrictionData::GetContactSpeed(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAirboatFrictionData::GetContactSpeed(CAirboatFrictionData *this, Vector *out)
{
  *out = this->m_vecVelocity;
}

//------------------------------------------------------------------------------
// Address: 0x10003EA0
// Name: private: void CPhysics_Airboat::PreRaycasts(class IVP_Ray_Solver_Template __near *,class IVP_U_Matrix const __near *,class IVP_Raycast_Airboat_Impact __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::PreRaycasts(
        CPhysics_Airboat *this,
        IVP_Ray_Solver_Template *pRaySolverTemplates,
        IVP_U_Matrix *matWorldFromCore,
        IVP_Raycast_Airboat_Impact *pImpacts)
{
  IVP_U_Float_Point *p_raycast_dir_ws; // edi
  float *v5; // esi
  IVP_U_Float_Point *p_raycast_dir_cs; // ebx
  float v7; // xmm0_4
  float v8; // xmm1_4
  IVP_Raycast_Airboat_Impact *pImpactsa; // [esp+10h] [ebp+10h]

  if ( this->n_wheels > 0 )
  {
    p_raycast_dir_ws = &pImpacts->raycast_dir_ws;
    v5 = &pRaySolverTemplates->ray_normized_direction.k[2];
    p_raycast_dir_cs = &this->m_aAirboatWheels[0].raycast_dir_cs;
    pImpactsa = (IVP_Raycast_Airboat_Impact *)this->n_wheels;
    do
    {
      if ( p_raycast_dir_cs != (IVP_U_Float_Point *)32 )
      {
        IVP_U_Matrix::vmult4(this: matWorldFromCore, p_in: p_raycast_dir_cs - 1, p_out: (IVP_U_Float_Point *)(v5 - 6));
        IVP_U_Matrix3::vmult3(this: matWorldFromCore, p_in: p_raycast_dir_cs, p_out: p_raycast_dir_ws);
        v7 = p_raycast_dir_ws->k[1];
        v8 = p_raycast_dir_ws->k[2];
        *(v5 - 2) = p_raycast_dir_ws->k[0];
        *(v5 - 1) = v7;
        *v5 = v8;
        *((_QWORD *)v5 + 1) = 1051931443;
      }
      v5 += 12;
      p_raycast_dir_cs += 12;
      p_raycast_dir_ws += 12;
      pImpactsa = (IVP_Raycast_Airboat_Impact *)((char *)pImpactsa - 1);
    }
    while ( pImpactsa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003F30
// Name: private: void CPhysics_Airboat::UpdateAirborneState(class IVP_Raycast_Airboat_Impact __near *,class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::UpdateAirborneState(
        CPhysics_Airboat *this,
        IVP_Raycast_Airboat_Impact *pImpacts,
        IVP_Event_Sim *pEventSim)
{
  int n_wheels; // ecx
  int v5; // edx
  IVP_U_Float_Point *p_speed; // ecx

  n_wheels = this->n_wheels;
  v5 = 0;
  if ( n_wheels <= 0 )
    goto LABEL_7;
  do
  {
    if ( pImpacts != nullptr && pImpacts->bImpact != IVP_FALSE )
      ++v5;
    ++pImpacts;
    --n_wheels;
  }
  while ( n_wheels != 0 );
  if ( v5 != 0 )
  {
    this->m_bAirborne = false;
    this->m_bWeakJump = false;
  }
  else
  {
LABEL_7:
    if ( this->m_bAirborne )
    {
      this->m_flAirTime = pEventSim->delta_time + this->m_flAirTime;
    }
    else
    {
      p_speed = &this->m_pCore->speed;
      this->m_bAirborne = true;
      this->m_flAirTime = 0.0;
      if ( IVP_U_Float_Point::fast_real_length(this: p_speed) < 11.0 )
        this->m_bWeakJump = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FD0
// Name: private: bool CPhysics_Airboat::PostRaycasts(class IVP_Ray_Solver_Template __near *,class IVP_U_Matrix const __near *,class IVP_Raycast_Airboat_Impact __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CPhysics_Airboat::PostRaycasts@<al>(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        IVP_Ray_Solver_Template *pRaySolverTemplates,
        const IVP_U_Matrix *matWorldFromCore,
        IVP_Raycast_Airboat_Impact *pImpacts)
{
  int n_wheels; // ecx
  float *v7; // edi
  float *v8; // esi
  float hesse_val; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  double v12; // st7
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // edx
  float v16; // xmm1_4
  float v17; // xmm2_4
  bool v18; // zf
  float v20[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point vecDelta; // [esp+0h] [ebp-20h]
  char v22; // [esp+13h] [ebp-Dh]
  int v23; // [esp+14h] [ebp-Ch]
  void *v24; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v23 = a2;
  v24 = retaddr;
  n_wheels = this->n_wheels;
  LODWORD(vecDelta.k[1]) = this;
  v22 = 1;
  if ( n_wheels <= 0 )
    return 1;
  v7 = &pRaySolverTemplates->ray_start_point.k[1];
  v8 = &pImpacts->raycast_dir_ws.k[1];
  LODWORD(hesse_val) = &this->m_aAirboatWheels[0].raycast_dist;
  vecDelta.hesse_val = hesse_val;
  LODWORD(vecDelta.k[2]) = n_wheels;
  do
  {
    if ( LODWORD(hesse_val) != 180 && v8 != (float *)20 && v7 != (float *)4 )
    {
      *(float *)(LODWORD(hesse_val) - 132) = v7[7];
      if ( *((_DWORD *)v8 + 27) != 0 )
      {
        v10 = *v8 * -1.0;
        v11 = v8[1] * -1.0;
        *(v8 - 1) = *(v8 - 1) * -1.0;
        *v8 = v10;
        v8[1] = v11;
      }
      if ( *((_DWORD *)v8 + 25) != 0 )
      {
        v20[0] = v8[31] - *(v7 - 1);
        v20[1] = v8[32] - *v7;
        v20[2] = v8[33] - v7[1];
        v12 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v20);
        hesse_val = vecDelta.hesse_val;
        *(float *)LODWORD(vecDelta.hesse_val) = v12;
        v8[24] = 1.1
               / (float)(COERCE_FLOAT(
                           COERCE_UNSIGNED_INT((float)((float)(v8[36] * *v8) + (float)(v8[35] * *(v8 - 1))) + (float)(v8[1] * v8[37]))
                         & _mask__AbsFloat_)
                       + 0.1);
        *(v8 - 5) = *(float *)(LODWORD(hesse_val) - 68) * v8[40];
      }
      else
      {
        *(float *)LODWORD(hesse_val) = *(float *)(LODWORD(hesse_val) - 132);
        v8[24] = 1.0;
        *(v8 - 3) = 0.0;
        v13 = *v8 * -1.0;
        v14 = v8[1] * -1.0;
        v8[35] = *(v8 - 1) * -1.0;
        v8[36] = v13;
        v8[37] = v14;
        *(v8 - 5) = 1.0;
      }
      v15 = vecDelta.k[1];
      v16 = (float)(*v8 * *(float *)LODWORD(hesse_val)) + *v7;
      v17 = (float)(v8[1] * *(float *)LODWORD(hesse_val)) + v7[1];
      v8[31] = (float)(*(float *)LODWORD(hesse_val) * *(v8 - 1)) + *(v7 - 1);
      v8[32] = v16;
      v8[33] = v17;
      IVP_Core::get_surface_speed_ws(
        this: *(IVP_Core **)(LODWORD(v15) + 28),
        position_ws_in: (const IVP_U_Point *)(v8 + 31),
        speed_ws_out: (IVP_U_Float_Point *)(v8 + 7));
      IVP_U_Float_Point::set_orthogonal_part(
        this: (IVP_U_Float_Point *)(v8 + 11),
        vector: (const IVP_U_Float_Point *)(v8 + 7),
        normal_v: (const IVP_U_Float_Point *)(v8 + 35));
      IVP_U_Matrix3::vmult3(
        this: &matWorldFromCore->IVP_U_Matrix3,
        p_in: (const IVP_U_Float_Point *)(LODWORD(vecDelta.hesse_val) - 52),
        p_out: (IVP_U_Float_Point *)(v8 + 15));
      IVP_U_Float_Point::set_orthogonal_part(
        this: (IVP_U_Float_Point *)(v8 + 19),
        vector: (const IVP_U_Float_Point *)(v8 + 15),
        normal_v: (const IVP_U_Float_Point *)(v8 + 35));
      if ( IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)(v8 + 19)) == IVP_FAULT )
      {
        DevMsg(a1: "CPhysics_Airboat::do_simulation_controller projected_axis_direction_ws.normize failed\n");
        v22 = 0;
      }
      hesse_val = vecDelta.hesse_val;
    }
    LODWORD(hesse_val) += 192;
    v8 += 48;
    v7 += 12;
    v18 = LODWORD(vecDelta.k[2])-- == 1;
    vecDelta.hesse_val = hesse_val;
  }
  while ( !v18 );
  return v22;
}

//------------------------------------------------------------------------------
// Address: 0x10004260
// Name: private: void CPhysics_Airboat::DoSimulationDrag(class IVP_Raycast_Airboat_Impact __near *,class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationDrag(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Raycast_Airboat_Impact *pImpacts,
        IVP_Event_Sim *pEventSim)
{
  IVP_Core *m_pCore; // eax
  IVP_Core *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm1_4
  unsigned int v11; // eax
  void *v12; // esp
  int v13; // esi
  void *v14; // esp
  unsigned __int8 *v15; // esi
  float v16; // eax
  float z; // xmm3_4
  float y; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float unitScaleMetersInv; // xmm5_4
  float v23; // ecx
  int v24; // eax
  bool v25; // zf
  int *v26; // ecx
  float v27; // xmm2_4
  unsigned __int8 *v28; // eax
  int v29; // esi
  float v30; // xmm2_4
  IVP_Core *v31; // edx
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  void *client_data; // esi
  double (__thiscall *v36)(void *, int, int); // edx
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm1_4
  double v42; // st7
  CPhysicsObject *v43; // esi
  CPhysicsEnvironment *VPhysicsEnvironment; // eax
  IPhysicsCollisionEvent *CollisionEventHandler; // edi
  double v46; // st7
  double v47; // st7
  unsigned int v48; // [esp+0h] [ebp-9Ch]
  int v49; // [esp+10h] [ebp-8Ch] BYREF
  int v50; // [esp+14h] [ebp-88h]
  void **v51; // [esp+18h] [ebp-84h] BYREF
  float v52; // [esp+1Ch] [ebp-80h]
  float v53; // [esp+20h] [ebp-7Ch]
  float v54; // [esp+24h] [ebp-78h]
  Vector v55; // [esp+28h] [ebp-74h] BYREF
  float v56; // [esp+34h] [ebp-68h]
  float v57; // [esp+38h] [ebp-64h]
  int v58; // [esp+3Ch] [ebp-60h]
  IVP_U_Float_Point v59; // [esp+40h] [ebp-5Ch] BYREF
  IVP_U_Float_Point v60; // [esp+50h] [ebp-4Ch] BYREF
  float delta_time; // [esp+64h] [ebp-38h]
  float hesse_val; // [esp+68h] [ebp-34h]
  float v63; // [esp+6Ch] [ebp-30h]
  unsigned __int8 *v64; // [esp+70h] [ebp-2Ch]
  int *v65; // [esp+74h] [ebp-28h]
  float v66; // [esp+78h] [ebp-24h]
  float v67; // [esp+7Ch] [ebp-20h]
  int v68; // [esp+80h] [ebp-1Ch]
  int v69; // [esp+84h] [ebp-18h]
  int v70; // [esp+88h] [ebp-14h]
  int v71; // [esp+8Ch] [ebp-10h]
  int nMaxSurfacePropIdx; // [esp+90h] [ebp-Ch]
  int nPointsOnGround; // [esp+94h] [ebp-8h]
  int retaddr; // [esp+9Ch] [ebp+0h]

  nMaxSurfacePropIdx = a2;
  nPointsOnGround = retaddr;
  v50 = a4;
  v49 = a3;
  m_pCore = this->m_pCore;
  LODWORD(delta_time) = &m_pCore->m_world_f_core_last_psi;
  v66 = IVP_U_Float_Point::fast_real_length(this: &m_pCore->speed);
  v8 = this->m_pCore;
  v56 = 0.0;
  v57 = 0.0;
  v58 = 0;
  v52 = 0.0;
  v53 = 0.0;
  v54 = 0.0;
  memset(&v55, 0, sizeof(v55));
  v51 = &CAirboatFrictionData::`vftable';
  v9 = v8->speed.k[2];
  v58 = LODWORD(v8->speed.k[1]) ^ _mask__NegFloat_;
  v57 = v9;
  v10 = v8->speed.k[0];
  v11 = (4 * this->n_wheels + 15) & 0xFFFFFFF0;
  v56 = v10;
  v68 = 0;
  v70 = 0;
  v67 = 0.0;
  v12 = alloca(v11);
  v13 = 4 * this->n_wheels;
  v65 = &v49;
  v14 = alloca(v13);
  v64 = (unsigned __int8 *)&v49;
  memset(dst: (unsigned __int8 *)&v49, value: 0, count: v13);
  v48 = v13;
  v15 = v64;
  memset(dst: v64, value: 0xFFu, count: v48);
  LODWORD(v16) = this->n_wheels;
  z = v55.z;
  y = v55.y;
  v19 = v54;
  v20 = v53;
  v21 = v52;
  v71 = 0;
  v69 = 0;
  if ( SLODWORD(v16) > 0 )
  {
    unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
    LODWORD(v23) = &pImpacts->bImpactWater;
    hesse_val = v16;
    LODWORD(v63) = &pImpacts->bImpactWater;
    do
    {
      if ( LODWORD(v23) != 124 && *(_DWORD *)(LODWORD(v23) - 4) != 0 )
      {
        if ( *(_DWORD *)LODWORD(v23) != 0 )
        {
          ++v68;
        }
        else
        {
          ++v70;
          v24 = 0;
          v67 = *(float *)(LODWORD(v23) + 56) + v67;
          v25 = v71 == 0;
          if ( v71 > 0 )
          {
            do
            {
              if ( *(_DWORD *)&v15[4 * v24] == *(_DWORD *)(LODWORD(v23) + 64) )
                break;
              ++v24;
            }
            while ( v24 < v71 );
            v25 = v24 == v71;
          }
          if ( v25 )
            ++v71;
          *(_DWORD *)&v15[4 * v24] = *(_DWORD *)(LODWORD(v23) + 64);
          v26 = v65;
          ++v65[v24];
          if ( v26[v24] > v26[v69] )
            v69 = v24;
          v23 = v63;
          v15 = v64;
          v19 = v54 - (float)(*(float *)(LODWORD(v63) + 24) * unitScaleMetersInv);
          v27 = *(float *)(LODWORD(v63) + 20) * unitScaleMetersInv;
          z = v55.z - *(float *)(LODWORD(v63) + 40);
          v20 = v20 + (float)(*(float *)(LODWORD(v63) + 28) * unitScaleMetersInv);
          y = *(float *)(LODWORD(v63) + 44) + v55.y;
          v55.x = *(float *)(LODWORD(v63) + 36) + v55.x;
          unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
          v21 = v21 + v27;
          v54 = v19;
          v55.y = y;
          v55.z = z;
        }
      }
      LODWORD(v23) += 192;
      v25 = LODWORD(hesse_val)-- == 1;
      v63 = v23;
    }
    while ( !v25 );
    v53 = v20;
    v52 = v21;
  }
  v28 = *(unsigned __int8 **)&v15[4 * v69];
  v29 = v70;
  v64 = v28;
  if ( v70 > 0 )
  {
    v30 = 1.0 / (float)v70;
    v54 = v19 * v30;
    v52 = v30 * v21;
    v53 = v20 * v30;
    v55.x = v30 * v55.x;
    v55.y = y * v30;
    v55.z = z * v30;
    VectorNormalize(vec: &v55);
  }
  if ( v68 != 0 )
  {
    v31 = this->m_pCore;
    v32 = -this->m_vecLocalVelocity.k[2];
    v33 = (float)-this->m_vecLocalVelocity.k[0] * 0.60000002;
    v60.k[1] = (float)-this->m_vecLocalVelocity.k[1] * 0.0024999999;
    v60.k[2] = v32 * 0.0049999999;
    v60.k[0] = v33;
    v34 = (float)(v31->rot_inertia.hesse_val * v66) * pEventSim->delta_time;
    v60.k[0] = v34 * v33;
    v60.k[1] = v60.k[1] * v34;
    v60.k[2] = (float)(v32 * 0.0049999999) * v34;
    IVP_U_Matrix3::vmult3(this: (IVP_U_Matrix3 *)LODWORD(delta_time), p_in: &v60, p_out: &v59);
    IVP_Core::center_push_core_multiple_ws(this: this->m_pCore, delta_speed: &v59, factor: 1.0);
  }
  if ( v29 != 0 && v66 > 0.0 )
  {
    client_data = this->m_pAirboatBody->client_data;
    v36 = *(double (__thiscall **)(void *, int, int))(*(_DWORD *)client_data + 176);
    hesse_val = this->m_pCore->rot_inertia.hesse_val;
    v63 = v36(a1: client_data, a2: v49, a3: v50);
    v37 = (float)-this->m_vecLocalVelocity.k[1] * 0.8;
    v38 = (float)((float)((float)(v67 / (float)v70) * (float)((float)(hesse_val * 9.8100004) * 0.60000002)) / v66)
        * pEventSim->delta_time;
    v39 = v37 * v38;
    v40 = v38 * (float)((float)-this->m_vecLocalVelocity.k[0] * 2.0);
    v41 = v38 * (float)-this->m_vecLocalVelocity.k[2];
    v60.k[0] = v40;
    v60.k[1] = v39;
    v60.k[2] = v41;
    IVP_U_Matrix3::vmult3(this: (IVP_U_Matrix3 *)LODWORD(delta_time), p_in: &v60, p_out: &v59);
    IVP_Core::center_push_core_multiple_ws(this: this->m_pCore, delta_speed: &v59, factor: 1.0);
    v42 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)client_data + 176))(a1: client_data);
    v43 = (CPhysicsObject *)this->m_pAirboatBody->client_data;
    v66 = v63 - v42;
    v25 = (v43->m_callbacks & 2) == 0;
    delta_time = pEventSim->delta_time;
    if ( !v25 )
    {
      VPhysicsEnvironment = CPhysicsObject::GetVPhysicsEnvironment(this: v43);
      CollisionEventHandler = CPhysicsEnvironment::GetCollisionEventHandler(this: VPhysicsEnvironment);
      if ( CollisionEventHandler != nullptr )
      {
        v46 = ((double (__thiscall *)(CPhysicsObject *))v43->GetMass)(a1: v43);
        v47 = delta_time / v46 * v66;
        v66 = v47;
        if ( v47 > 0.050000001 )
          CollisionEventHandler->Friction(
            this: CollisionEventHandler,
            a2: v43,
            a3: COERCE_FLOAT(LODWORD(v66)),
            a4: v43->m_materialIndex,
            a5: (int)v64,
            a6: (IPhysicsCollisionData *)&v51);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004750
// Name: private: void CPhysics_Airboat::DoSimulationTurbine(class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationTurbine(
        CPhysics_Airboat *this@<ecx>,
        float a2@<ebp>,
        IVP_Event_Sim *pEventSim)
{
  float m_flThrust; // xmm1_4
  IVP_Core *m_pCore; // eax
  IVP_COORDINATE_INDEX index_z; // ecx
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10[3]; // [esp+4h] [ebp-1Ch] BYREF
  IVP_U_Float_Point vecImpulse; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  vecImpulse.k[1] = a2;
  vecImpulse.k[2] = retaddr;
  m_flThrust = this->m_flThrust;
  if ( this->m_bWeakJump || this->m_bAirborne && m_flThrust < 0.0 )
    m_flThrust = m_flThrust * 0.5;
  m_pCore = this->m_pCore;
  index_z = this->index_z;
  v6 = m_pCore->m_world_f_core_last_psi.rows[1].k[index_z];
  v7 = m_pCore->m_world_f_core_last_psi.rows[2].k[index_z];
  if ( v6 < -0.5 && m_flThrust > 0.0 )
  {
    v8 = v6 + 1.0;
LABEL_11:
    m_flThrust = m_flThrust * v8;
    goto LABEL_12;
  }
  if ( v6 > 0.5 && m_flThrust < 0.0 )
  {
    v8 = 1.0 - v6;
    goto LABEL_11;
  }
LABEL_12:
  v9 = (float)(m_pCore->rot_inertia.hesse_val * m_flThrust) * pEventSim->delta_time;
  v10[0] = v9 * m_pCore->m_world_f_core_last_psi.rows[0].k[index_z];
  v10[1] = v9 * v6;
  v10[2] = v9 * v7;
  IVP_Core::center_push_core_multiple_ws(this: m_pCore, delta_speed: (const IVP_U_Float_Point *)v10, factor: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x10004840
// Name: private: void CPhysics_Airboat::DoSimulationKeepUprightPitch(class IVP_Raycast_Airboat_Impact __near *,class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationKeepUprightPitch(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        IVP_Raycast_Airboat_Impact *pImpacts,
        IVP_Event_Sim *pEventSim)
{
  IVP_Core *m_pCore; // ecx
  long double v7; // st7
  int n_wheels; // ecx
  int v9; // edx
  float v11; // xmm0_4
  IVP_Core *v12; // ecx
  float v13; // xmm1_4
  long double v14; // [esp-1Ch] [ebp-7Ch]
  long double v15; // [esp-1Ch] [ebp-7Ch]
  _DWORD v16[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point vecGoalAxisWS; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Float_Point vecRotAxisCS; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Float_Point vecGoalAxisCS; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point vecUpCS; // [esp+30h] [ebp-30h] BYREF
  float v21; // [esp+50h] [ebp-10h]
  int v22; // [esp+54h] [ebp-Ch]
  void *v23; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  LODWORD(v14) = a3;
  if ( !this->m_bWeakJump )
  {
    vecGoalAxisCS.k[1] = 0.0;
    __libm_sse2_cos(x: v14);
    LODWORD(vecGoalAxisCS.k[2]) = COERCE_UNSIGNED_INT(0.1745329201221466) ^ _mask__NegFloat_;
    __libm_sse2_sin(x: v15);
    m_pCore = this->m_pCore;
    vecGoalAxisCS.hesse_val = 0.1745329201221466;
    v16[0] = 0;
    v16[1] = -1082130432;
    v16[2] = 0;
    IVP_U_Matrix3::vimult3(
      this: &m_pCore->m_world_f_core_last_psi,
      p_in: (const IVP_U_Float_Point *)v16,
      p_out: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
    vecRotAxisCS.k[1] = vecGoalAxisCS.k[1];
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
    IVP_U_Float_Point::calc_cross_product(
      this: (IVP_U_Float_Point *)&vecGoalAxisWS.k[1],
      v1: (IVP_U_Float_Point *)&vecGoalAxisCS.k[1],
      v2: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
    v21 = (float)((float)(vecRotAxisCS.k[2] * vecGoalAxisCS.k[2]) + (float)(vecRotAxisCS.k[1] * vecGoalAxisCS.k[1]))
        + (float)(vecRotAxisCS.hesse_val * vecGoalAxisCS.hesse_val);
    v7 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&vecGoalAxisWS.k[1]);
    n_wheels = this->n_wheels;
    v9 = 0;
    v21 = atan2(v7, v21);
    if ( n_wheels <= 0 )
      goto LABEL_9;
    do
    {
      if ( pImpacts != nullptr && pImpacts->bImpact != IVP_FALSE )
        ++v9;
      ++pImpacts;
      --n_wheels;
    }
    while ( n_wheels != 0 );
    if ( v9 <= 0 )
    {
LABEL_9:
      v11 = (float)((float)((float)(v21 - this->m_flPitchErrorPrev) * (float)(pEventSim->i_delta_time * 0.039999999))
                  + (float)(v21 * 0.1))
          * this->m_pCore->rot_inertia.hesse_val;
      vecUpCS.k[1] = vecGoalAxisWS.k[1] * v11;
      vecUpCS.k[2] = vecGoalAxisWS.k[2] * v11;
      vecUpCS.hesse_val = vecGoalAxisWS.hesse_val * v11;
      this->m_flPitchErrorPrev = v21;
      v21 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&vecUpCS.k[1]);
      v12 = this->m_pCore;
      v13 = v21;
      if ( v21 > (float)(v12->rot_inertia.hesse_val * 0.02617994) )
        v13 = v12->rot_inertia.hesse_val * 0.02617994;
      vecUpCS.k[1] = vecUpCS.k[1] * v13;
      vecUpCS.k[2] = vecUpCS.k[2] * v13;
      vecUpCS.hesse_val = vecUpCS.hesse_val * v13;
      IVP_Core::rot_push_core_cs(this: v12, rot_impulse_cs: (IVP_U_Float_Point *)&vecUpCS.k[1]);
    }
    else
    {
      this->m_flPitchErrorPrev = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A40
// Name: private: void CPhysics_Airboat::DoSimulationKeepUprightRoll(class IVP_Raycast_Airboat_Impact __near *,class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationKeepUprightRoll(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        IVP_Raycast_Airboat_Impact *pImpacts,
        IVP_Event_Sim *pEventSim)
{
  IVP_Core *m_pCore; // ecx
  long double v7; // st7
  int n_wheels; // ecx
  int v9; // edx
  float v11; // xmm0_4
  IVP_Core *v12; // ecx
  float v13; // xmm1_4
  long double v14; // [esp-1Ch] [ebp-7Ch]
  long double v15; // [esp-1Ch] [ebp-7Ch]
  _DWORD v16[3]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Float_Point vecGoalAxisWS; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Float_Point vecRotAxisCS; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Float_Point vecGoalAxisCS; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point vecUpCS; // [esp+30h] [ebp-30h] BYREF
  float v21; // [esp+50h] [ebp-10h]
  int v22; // [esp+54h] [ebp-Ch]
  void *v23; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  LODWORD(v14) = a3;
  vecGoalAxisCS.k[1] = 0.0;
  __libm_sse2_cos(x: v14);
  LODWORD(vecGoalAxisCS.k[2]) = COERCE_UNSIGNED_INT(0.1745329201221466) ^ _mask__NegFloat_;
  __libm_sse2_sin(x: v15);
  m_pCore = this->m_pCore;
  vecGoalAxisCS.hesse_val = 0.1745329201221466;
  v16[0] = 0;
  v16[1] = -1082130432;
  v16[2] = 0;
  IVP_U_Matrix3::vimult3(
    this: &m_pCore->m_world_f_core_last_psi,
    p_in: (const IVP_U_Float_Point *)v16,
    p_out: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
  vecRotAxisCS.k[2] = vecGoalAxisCS.k[2];
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&vecGoalAxisWS.k[1],
    v1: (IVP_U_Float_Point *)&vecGoalAxisCS.k[1],
    v2: (IVP_U_Float_Point *)&vecRotAxisCS.k[1]);
  v21 = (float)((float)(vecGoalAxisCS.k[1] * vecRotAxisCS.k[1]) + (float)(vecRotAxisCS.k[2] * vecGoalAxisCS.k[2]))
      + (float)(vecRotAxisCS.hesse_val * vecGoalAxisCS.hesse_val);
  v7 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&vecGoalAxisWS.k[1]);
  n_wheels = this->n_wheels;
  v9 = 0;
  v21 = atan2(v7, v21);
  if ( n_wheels <= 0 )
    goto LABEL_8;
  do
  {
    if ( pImpacts != nullptr && pImpacts->bImpact != IVP_FALSE )
      ++v9;
    ++pImpacts;
    --n_wheels;
  }
  while ( n_wheels != 0 );
  if ( v9 <= 0 )
  {
LABEL_8:
    if ( COERCE_FLOAT(LODWORD(v21) & _mask__AbsFloat_) >= 0.17453292 )
    {
      v11 = (float)((float)((float)(v21 - this->m_flRollErrorPrev) * (float)(pEventSim->i_delta_time * 0.30000001))
                  + (float)(v21 * 0.2))
          * this->m_pCore->rot_inertia.hesse_val;
      vecUpCS.k[1] = vecGoalAxisWS.k[1] * v11;
      vecUpCS.k[2] = vecGoalAxisWS.k[2] * v11;
      vecUpCS.hesse_val = vecGoalAxisWS.hesse_val * v11;
      this->m_flRollErrorPrev = v21;
      v21 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&vecUpCS.k[1]);
      v12 = this->m_pCore;
      v13 = v21;
      if ( v21 > (float)(v12->rot_inertia.hesse_val * 0.034906585) )
        v13 = v12->rot_inertia.hesse_val * 0.034906585;
      vecUpCS.k[1] = vecUpCS.k[1] * v13;
      vecUpCS.k[2] = vecUpCS.k[2] * v13;
      vecUpCS.hesse_val = vecUpCS.hesse_val * v13;
      IVP_Core::rot_push_core_cs(this: v12, rot_impulse_cs: (IVP_U_Float_Point *)&vecUpCS.k[1]);
    }
    else
    {
      this->m_flRollErrorPrev = v21;
    }
  }
  else
  {
    this->m_flRollErrorPrev = v21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C60
// Name: public: virtual void CPhysics_Airboat::do_steering_wheel(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::do_steering_wheel(CPhysics_Airboat *this, IVP_POS_WHEEL wheel_nr, float s_angle)
{
  IVP_Raycast_Airboat_Wheel *v3; // edx

  v3 = &this->m_aAirboatWheels[wheel_nr];
  v3->axis_direction_cs.k[2] = 0.0;
  v3->axis_direction_cs.k[1] = 0.0;
  v3->axis_direction_cs.k[0] = 0.0;
  v3->axis_direction_cs.k[this->index_x] = 1.0;
  IVP_U_Float_Point::rotate(
    this: &this->m_aAirboatWheels[wheel_nr].axis_direction_cs,
    axis: this->index_y,
    angle: s_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10004CD0
// Name: public: virtual void CPhysics_Airboat::change_spring_constant(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_spring_constant(
        CPhysics_Airboat *this,
        IVP_POS_WHEEL pos,
        float spring_constant)
{
  this->m_aAirboatWheels[pos].spring_constant = spring_constant;
}

//------------------------------------------------------------------------------
// Address: 0x10004CF0
// Name: public: virtual void CPhysics_Airboat::change_spring_dampening(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_spring_dampening(
        CPhysics_Airboat *this,
        IVP_POS_WHEEL pos,
        float spring_dampening)
{
  this->m_aAirboatWheels[pos].spring_damp_relax = spring_dampening;
}

//------------------------------------------------------------------------------
// Address: 0x10004D10
// Name: public: virtual void CPhysics_Airboat::change_spring_dampening_compression(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_spring_dampening_compression(
        CPhysics_Airboat *this,
        IVP_POS_WHEEL pos,
        float spring_dampening)
{
  this->m_aAirboatWheels[pos].spring_damp_compress = spring_dampening;
}

//------------------------------------------------------------------------------
// Address: 0x10004D30
// Name: public: virtual void CPhysics_Airboat::change_spring_pre_tension(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_spring_pre_tension(
        CPhysics_Airboat *this,
        IVP_POS_WHEEL pos,
        float pre_tension_length)
{
  this->m_aAirboatWheels[pos].spring_len = (float)(this->m_aAirboatWheels[pos].distance_orig_hp_to_hp
                                                 - pre_tension_length)
                                         * this->gravity_y_direction;
}

//------------------------------------------------------------------------------
// Address: 0x10004D60
// Name: public: virtual void CPhysics_Airboat::change_spring_length(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_spring_length(CPhysics_Airboat *this, IVP_POS_WHEEL pos, float spring_length)
{
  this->m_aAirboatWheels[pos].spring_len = spring_length;
}

//------------------------------------------------------------------------------
// Address: 0x10004D80
// Name: public: virtual void CPhysics_Airboat::change_wheel_torque(enum IVP_POS_WHEEL,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_wheel_torque(CPhysics_Airboat *this, IVP_POS_WHEEL pos, float torque)
{
  this->m_aAirboatWheels[pos].torque = torque;
  if ( this != nullptr )
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: this->m_pAirboatBody->environment->controller_manager,
      cntrl: &this->IVP_Controller_Dependent);
  else
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: *(IVP_Controller_Manager **)(*(_DWORD *)(MEMORY[0x34] + 24) + 52),
      cntrl: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10004DD0
// Name: public: virtual float CPhysics_Airboat::get_wheel_torque(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysics_Airboat::get_wheel_torque(CPhysics_Airboat *this, IVP_POS_WHEEL pos)
{
  return this->m_aAirboatWheels[pos].torque;
}

//------------------------------------------------------------------------------
// Address: 0x10004DF0
// Name: public: virtual void CPhysics_Airboat::fix_wheel(enum IVP_POS_WHEEL,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::fix_wheel(CPhysics_Airboat *this, IVP_POS_WHEEL pos, IVP_BOOL stop_wheel)
{
  this->m_aAirboatWheels[pos].wheel_is_fixed = stop_wheel;
}

//------------------------------------------------------------------------------
// Address: 0x10004E10
// Name: public: virtual void CPhysics_Airboat::change_stabilizer_constant(enum IVP_POS_AXIS,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::change_stabilizer_constant(
        CPhysics_Airboat *this,
        IVP_POS_AXIS pos,
        float stabi_constant)
{
  this->m_aAirboatAxles[pos].stabilizer_constant = stabi_constant;
}

//------------------------------------------------------------------------------
// Address: 0x10004E30
// Name: public: virtual void CPhysics_Airboat::do_steering(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::do_steering(CPhysics_Airboat *this, float steering_angle_in, bool bAnalog)
{
  IVP_Real_Object *m_pAirboatBody; // ecx
  int i; // edi

  if ( this->m_SteeringAngle != steering_angle_in )
  {
    m_pAirboatBody = this->m_pAirboatBody;
    this->m_bAnalogSteering = bAnalog;
    this->m_SteeringAngle = steering_angle_in;
    IVP_Controller_Manager::ensure_controller_in_simulation(
      this: m_pAirboatBody->environment->controller_manager,
      cntrl: &this->IVP_Controller_Dependent);
    for ( i = 0;
          i < this->wheels_per_axis;
          ((void (__thiscall *)(CPhysics_Airboat *, int, _DWORD))this->do_steering_wheel)(
            a1: this,
            a2: i++,
            a3: LODWORD(this->m_SteeringAngle)) )
    {
      ;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004EB0
// Name: public: virtual float CPhysics_Airboat::get_wheel_angular_velocity(enum IVP_POS_WHEEL)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysics_Airboat::get_wheel_angular_velocity(CPhysics_Airboat *this, IVP_POS_WHEEL pos)
{
  return this->m_aAirboatWheels[pos].wheel_angular_velocity;
}

//------------------------------------------------------------------------------
// Address: 0x10004ED0
// Name: public: virtual float CPhysics_Airboat::get_body_speed(enum IVP_COORDINATE_INDEX)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysics_Airboat::get_body_speed(CPhysics_Airboat *this, IVP_COORDINATE_INDEX index)
{
  IVP_Core *physical_core; // eax

  physical_core = this->m_pAirboatBody->physical_core;
  return physical_core->m_world_f_core_last_psi.rows[0].k[index] * physical_core->speed.k[0]
       + physical_core->m_world_f_core_last_psi.rows[1].k[index] * physical_core->speed.k[1]
       + physical_core->m_world_f_core_last_psi.rows[2].k[index] * physical_core->speed.k[2];
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: virtual float CPhysics_Airboat::get_orig_front_wheel_distance(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysics_Airboat::get_orig_front_wheel_distance(CPhysics_Airboat *this)
{
  return fabs(this->m_aAirboatWheels[0].hp_cs.k[this->index_x] - this->m_aAirboatWheels[1].hp_cs.k[this->index_x]);
}

//------------------------------------------------------------------------------
// Address: 0x10004F30
// Name: public: virtual float CPhysics_Airboat::get_orig_axles_distance(void)
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysics_Airboat::get_orig_axles_distance(CPhysics_Airboat *this)
{
  return fabs(this->m_aAirboatWheels[0].hp_cs.k[this->index_z] - this->m_aAirboatWheels[2].hp_cs.k[this->index_z]);
}

//------------------------------------------------------------------------------
// Address: 0x10004F50
// Name: public: virtual void CPhysics_Airboat::get_skid_info(class IVP_Wheel_Skid_Info __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::get_skid_info(CPhysics_Airboat *this, IVP_Wheel_Skid_Info *array_of_skid_info_out)
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
// Address: 0x10004FC0
// Name: float RemapValClamped(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl RemapValClamped(float val, float A, float B, float C, float D)
{
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( A == B )
  {
    if ( (float)(val - B) < 0.0 )
      return C;
    else
      return D;
  }
  else
  {
    v6 = (float)(val - A) / (float)(B - A);
    v7 = 0.0;
    if ( v6 < 0.0 )
      return C + (D - C) * v7;
    v7 = 1.0;
    if ( v6 > 1.0 )
      return C + (D - C) * v7;
    else
      return C + (D - C) * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005060
// Name: public: virtual CPhysics_Airboat::~CPhysics_Airboat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::~CPhysics_Airboat(CPhysics_Airboat *this)
{
  IVP_Controller_Dependent *v2; // edi
  CPhysics_Airboat *elems; // eax

  v2 = &this->IVP_Controller_Dependent;
  this->IVP_Car_System::__vftable = (CPhysics_Airboat_vtbl *)&CPhysics_Airboat::`vftable'{for `IVP_Car_System'};
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&CPhysics_Airboat::`vftable'{for `IVP_Controller_Dependent'};
  IVP_Controller_Manager::remove_controller_from_environment(cntrl: &this->IVP_Controller_Dependent, silently: IVP_TRUE);
  elems = (CPhysics_Airboat *)this->vector_of_cores.elems;
  if ( elems != (CPhysics_Airboat *)this->vector_of_cores.elem_buffer )
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
// Address: 0x100050D0
// Name: public: virtual char const __near * CPhysics_Airboat::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysics_Airboat::get_controller_name(CPhysics_Airboat *this)
{
  return "sys:airboat";
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: public: void CPhysics_Airboat::SetWheelFriction(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::SetWheelFriction(CPhysics_Airboat *this, int iWheel, float flFriction)
{
  this->m_aAirboatWheels[iWheel].friction_of_wheel = flFriction;
}

//------------------------------------------------------------------------------
// Address: 0x10005120
// Name: protected: void CPhysics_Airboat::pre_raycasts_gameside(int,class IVP_Ray_Solver_Template __near *,struct Ray_t __near *,class IVP_Raycast_Airboat_Impact __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::pre_raycasts_gameside(
        CPhysics_Airboat *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int nRaycastCount,
        IVP_Ray_Solver_Template *pRays,
        Ray_t *pGameRays,
        IVP_Raycast_Airboat_Impact *pImpacts)
{
  float v8; // xmm0_4
  double v9; // st7
  float v10; // xmm0_4
  int v11; // eax
  float *p_y; // esi
  float *v13; // edi
  float unitScaleMetersInv; // xmm0_4
  float v15; // xmm2_4
  CPhysics_Airboat *v16; // ecx
  float v17; // xmm2_4
  float v18; // xmm0_4
  IVP_BOOL *v19; // ecx
  float v20; // xmm1_4
  float v21; // xmm2_4
  IPhysicsGameTrace *m_pGameTrace; // ecx
  float v23; // xmm3_4
  float v24; // xmm0_4
  int v25; // eax
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  long double v29; // xmm0_8
  int v30; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v34; // xmm5_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  int v37; // eax
  int v38; // edi
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // esi
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  long double v45; // xmm0_8
  float v46; // xmm4_4
  float v47; // xmm2_4
  float v48; // xmm5_4
  float v49; // xmm3_4
  float v50; // xmm6_4
  float v51; // xmm2_4
  float v52; // xmm3_4
  long double v53; // [esp+18h] [ebp-A0h]
  Vector vecStart[4]; // [esp+20h] [ebp-98h] BYREF
  Vector vecDirection[4]; // [esp+50h] [ebp-68h]
  float v56; // [esp+80h] [ebp-38h]
  float v57; // [esp+84h] [ebp-34h]
  float v58; // [esp+88h] [ebp-30h]
  float v59; // [esp+8Ch] [ebp-2Ch]
  float v60; // [esp+90h] [ebp-28h]
  int iRaycast; // [esp+94h] [ebp-24h]
  Vector vecEnd; // [esp+98h] [ebp-20h] BYREF
  CPhysics_Airboat *v63; // [esp+A4h] [ebp-14h]
  IVP_BOOL *p_bInWater; // [esp+A8h] [ebp-10h]
  float flForwardSpeedRatio; // [esp+ACh] [ebp-Ch]
  int nFrontPontoonsInWater; // [esp+B0h] [ebp-8h]
  float flSpeedRatio; // [esp+B4h] [ebp-4h]
  float *nRaycastCounta; // [esp+C0h] [ebp+8h]
  float pRaysa; // [esp+C4h] [ebp+Ch]
  float flRayLength; // [esp+C8h] [ebp+10h]
  int i; // [esp+CCh] [ebp+14h]
  int ia; // [esp+CCh] [ebp+14h]

  HIDWORD(v53) = a3;
  v8 = this->m_vecLocalVelocity.k[2] * 0.1;
  v63 = this;
  if ( v8 >= 0.0 )
  {
    if ( v8 <= 1.0 )
      flForwardSpeedRatio = v8;
    else
      flForwardSpeedRatio = 1.0;
  }
  else
  {
    flForwardSpeedRatio = 0.0;
  }
  v9 = IVP_U_Float_Point::fast_real_length(this: &this->m_pCore->speed) * 0.06666667;
  *(float *)&nFrontPontoonsInWater = v9;
  if ( v9 < 0.0 )
  {
    v10 = 0.0;
LABEL_8:
    flSpeedRatio = v10;
    goto LABEL_9;
  }
  v10 = *(float *)&nFrontPontoonsInWater;
  if ( *(float *)&nFrontPontoonsInWater <= 1.0 )
    goto LABEL_8;
  flSpeedRatio = 1.0;
LABEL_9:
  if ( this->m_flThrust == 0.0 )
    flForwardSpeedRatio = flForwardSpeedRatio * 0.5;
  v11 = 0;
  *(float *)&nFrontPontoonsInWater = 0.0;
  iRaycast = 0;
  if ( nRaycastCount > 0 )
  {
    LODWORD(v53) = a2;
    p_y = &pGameRays->m_Extents.y;
    p_bInWater = &pImpacts->bInWater;
    LODWORD(v58) = &pGameRays->m_Extents.y;
    v13 = &pRays->ray_normized_direction.k[2];
    i = 0;
    while ( 1 )
    {
      unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
      *(float *)((char *)&vecDirection[0].y + v11) = *v13;
      v15 = *(v13 - 5);
      v16 = v63;
      *(float *)((char *)&vecDirection[0].x + v11) = *(v13 - 2);
      *(float *)((char *)&vecStart[0].z + v11) = -(float)(v15 * unitScaleMetersInv);
      *(float *)((char *)&vecStart[0].y + v11) = *(v13 - 4) * unitScaleMetersInv;
      v17 = *(v13 - 6) * unitScaleMetersInv;
      v18 = unitScaleMetersInv * v13[2];
      *(float *)((char *)&vecStart[0].x + v11) = v17;
      *(float *)((char *)&vecDirection[0].z + v11) = -*(v13 - 1);
      *p_bInWater = IVP_FALSE;
      if ( ((unsigned __int8 (__thiscall *)(IPhysicsGameTrace *, char *, _DWORD))v16->m_pGameTrace->VehiclePointInWater)(
             a1: v16->m_pGameTrace,
             a2: (char *)vecStart + v11,
             a3: LODWORD(v53)) != 0 )
      {
        v19 = p_bInWater;
        *(float *)((char *)&vecDirection[0].x + i) = -*(float *)((char *)&vecDirection[0].x + i);
        *(float *)((char *)&vecDirection[0].y + i) = -*(float *)((char *)&vecDirection[0].y + i);
        *(float *)((char *)&vecDirection[0].z + i) = -*(float *)((char *)&vecDirection[0].z + i);
        *v19 = IVP_TRUE;
      }
      v20 = *(float *)((char *)&vecDirection[0].y + i);
      v21 = *(float *)((char *)&vecDirection[0].z + i);
      m_pGameTrace = v63->m_pGameTrace;
      v56 = *(float *)((char *)&vecDirection[0].x + i);
      v59 = v20;
      v60 = v21;
      v23 = *(float *)((char *)&vecStart[0].x + i) + (float)(v56 * v18);
      vecEnd.y = *(float *)((char *)&vecStart[0].y + i) + (float)(v20 * v18);
      v24 = *(float *)((char *)&vecStart[0].z + i) + (float)(v21 * v18);
      vecEnd.x = v23;
      vecEnd.z = v24;
      LODWORD(v53) = &vecEnd;
      if ( ((unsigned __int8 (__thiscall *)(IPhysicsGameTrace *))m_pGameTrace->VehiclePointInWater)(a1: m_pGameTrace) != 0 )
      {
        v25 = iRaycast;
        v13[2] = 0.1;
        if ( v25 >= 2 )
        {
          v30 = i;
          x = *(float *)((char *)&vecStart[0].x + i) + (float)(v56 * (float)(g_PhysicsUnits.unitScaleMetersInv * 0.1));
          y = *(float *)((char *)&vecStart[0].y + i) + (float)(v59 * (float)(g_PhysicsUnits.unitScaleMetersInv * 0.1));
          z = *(float *)((char *)&vecStart[0].z + i) + (float)(v60 * (float)(g_PhysicsUnits.unitScaleMetersInv * 0.1));
          vecEnd.x = x;
          vecEnd.y = y;
          vecEnd.z = z;
          goto LABEL_32;
        }
        v26 = flSpeedRatio;
        ++nFrontPontoonsInWater;
        v27 = 1.0 - flSpeedRatio;
        if ( (float)(1.0 - flSpeedRatio) >= 0.0 )
        {
          if ( v27 > 1.0 )
            v27 = 1.0;
        }
        else
        {
          v27 = 0.0;
        }
        v57 = (float)(v27 * 0.02) + 0.0099999998;
        v28 = 0.0;
        if ( flSpeedRatio < 0.3 )
          v28 = (double)v25 * 1.5;
        if ( flSpeedRatio >= 0.0 )
        {
          if ( flSpeedRatio > 1.0 )
            v26 = 1.0;
        }
        else
        {
          v26 = 0.0;
        }
        v29 = (v28 + v63->m_pCore->environment->current_time.seconds) * (float)((float)(v26 * 0.0) + 1.5);
        __libm_sse2_sin(x: v53);
        *(float *)&v29 = v29 * v57;
        v13[2] = *(float *)&v29 + 0.1;
      }
      v30 = i;
      x = vecEnd.x;
      y = vecEnd.y;
      z = vecEnd.z;
LABEL_32:
      v34 = *(float *)((char *)&vecStart[0].y + v30);
      v35 = *(float *)((char *)&vecStart[0].x + v30);
      *(p_y - 8) = y - v34;
      v36 = *(float *)((char *)&vecStart[0].z + v30);
      *(p_y - 7) = z - v36;
      *(p_y - 9) = x - v35;
      p_y[3] = 0.0;
      *((_BYTE *)p_y + 17) = (float)((float)((float)(*(p_y - 9) * *(p_y - 9)) + (float)(*(p_y - 8) * *(p_y - 8)))
                                   + (float)(*(p_y - 7) * *(p_y - 7))) != 0.0;
      *p_y = 0.0;
      p_y[1] = 0.0;
      *(p_y - 1) = 0.0 * 0.5;
      *p_y = *p_y * 0.5;
      p_y[1] = p_y[1] * 0.5;
      *((_BYTE *)p_y + 16) = (float)((float)((float)(*(p_y - 1) * *(p_y - 1)) + (float)(*p_y * *p_y))
                                   + (float)(p_y[1] * p_y[1])) < 0.000001;
      *(p_y - 4) = 0.0;
      *(p_y - 3) = 0.0;
      v37 = iRaycast;
      p_bInWater += 48;
      *(p_y - 5) = 0.0 * 0.5;
      *(p_y - 4) = *(p_y - 4) * 0.5;
      *(p_y - 3) = *(p_y - 3) * 0.5;
      *(p_y - 13) = v35 + *(p_y - 5);
      *(p_y - 12) = *(p_y - 4) + v34;
      *(p_y - 11) = v36 + *(p_y - 3);
      *(p_y - 5) = *(p_y - 5) * -1.0;
      *(p_y - 4) = *(p_y - 4) * -1.0;
      *(p_y - 3) = *(p_y - 3) * -1.0;
      v13 += 12;
      p_y += 20;
      iRaycast = v37 + 1;
      i = v30 + 12;
      if ( v37 + 1 >= nRaycastCount )
      {
        if ( nFrontPontoonsInWater == 2 )
        {
          v38 = 0;
          ia = 0;
          flRayLength = RemapValClamped(val: flForwardSpeedRatio, A: 0.0, B: 1.0, C: 0.1, D: 0.34999999);
          v39 = 1.0;
          v40 = flSpeedRatio;
          v41 = v58;
          v42 = 1.0 - flSpeedRatio;
          v43 = flSpeedRatio;
          v59 = 1.0 - flSpeedRatio;
          v60 = flSpeedRatio;
          nRaycastCounta = &pRays->ray_length;
          while ( 1 )
          {
            *nRaycastCounta = flRayLength;
            if ( v42 >= 0.0 )
            {
              if ( v42 > 1.0 )
                v42 = 1.0;
            }
            else
            {
              v42 = 0.0;
            }
            pRaysa = (float)(v42 * 0.02) + 0.0099999998;
            v44 = 0.0;
            if ( v40 < 0.3 )
              v44 = (double)ia * 1.5;
            if ( v43 >= 0.0 )
            {
              if ( v43 <= 1.0 )
                v39 = v43;
            }
            else
            {
              v39 = 0.0;
            }
            v45 = (v44 + v63->m_pCore->environment->current_time.seconds) * (float)((float)(0.0 * v39) + 1.5);
            __libm_sse2_sin(x: v53);
            v46 = vecStart[v38].x;
            v47 = vecDirection[v38].x;
            v48 = vecStart[v38].y;
            v49 = vecDirection[v38].y;
            v50 = vecStart[v38].z;
            *(float *)&v45 = v45 * pRaysa;
            *(float *)&v45 = *(float *)&v45 + flRayLength;
            *nRaycastCounta = *(float *)&v45;
            *(float *)&v45 = *(float *)&v45 * g_PhysicsUnits.unitScaleMetersInv;
            v51 = v47 * *(float *)&v45;
            v52 = v49 * *(float *)&v45;
            *(float *)&v45 = *(float *)&v45 * vecDirection[v38].z;
            *(float *)(LODWORD(v41) - 36) = (float)(v46 + v51) - v46;
            *(float *)(LODWORD(v41) - 32) = (float)(v48 + v52) - v48;
            *(float *)(LODWORD(v41) - 28) = (float)(v50 + *(float *)&v45) - v50;
            *(_DWORD *)(LODWORD(v41) + 12) = 0;
            *(_BYTE *)(LODWORD(v41) + 17) = (float)((float)((float)(*(float *)(LODWORD(v41) - 32)
                                                                  * *(float *)(LODWORD(v41) - 32))
                                                          + (float)(*(float *)(LODWORD(v41) - 36)
                                                                  * *(float *)(LODWORD(v41) - 36)))
                                                  + (float)(*(float *)(LODWORD(v41) - 28) * *(float *)(LODWORD(v41) - 28))) != 0.0;
            *(_DWORD *)LODWORD(v41) = 0;
            *(_DWORD *)(LODWORD(v41) + 4) = 0;
            *(float *)(LODWORD(v41) - 4) = 0.0 * 0.5;
            *(float *)LODWORD(v41) = *(float *)LODWORD(v41) * 0.5;
            *(float *)(LODWORD(v41) + 4) = *(float *)(LODWORD(v41) + 4) * 0.5;
            v58 = (float)(*(float *)LODWORD(v41) * *(float *)LODWORD(v41))
                + (float)(*(float *)(LODWORD(v41) - 4) * *(float *)(LODWORD(v41) - 4));
            *(_BYTE *)(LODWORD(v41) + 16) = (float)(v58
                                                  + (float)(*(float *)(LODWORD(v41) + 4) * *(float *)(LODWORD(v41) + 4))) < 0.000001;
            *(_DWORD *)(LODWORD(v41) - 16) = 0;
            *(_DWORD *)(LODWORD(v41) - 12) = 0;
            ++ia;
            nRaycastCounta += 12;
            *(float *)(LODWORD(v41) - 20) = 0.0 * 0.5;
            *(float *)(LODWORD(v41) - 16) = *(float *)(LODWORD(v41) - 16) * 0.5;
            *(float *)(LODWORD(v41) - 12) = *(float *)(LODWORD(v41) - 12) * 0.5;
            *(float *)(LODWORD(v41) - 52) = v46 + *(float *)(LODWORD(v41) - 20);
            *(float *)(LODWORD(v41) - 48) = v48 + *(float *)(LODWORD(v41) - 16);
            *(float *)(LODWORD(v41) - 44) = v50 + *(float *)(LODWORD(v41) - 12);
            *(float *)(LODWORD(v41) - 20) = *(float *)(LODWORD(v41) - 20) * -1.0;
            *(float *)(LODWORD(v41) - 16) = *(float *)(LODWORD(v41) - 16) * -1.0;
            *(float *)(LODWORD(v41) - 12) = *(float *)(LODWORD(v41) - 12) * -1.0;
            ++v38;
            LODWORD(v41) += 80;
            if ( v38 >= 2 )
              break;
            v43 = v60;
            v42 = v59;
            v40 = flSpeedRatio;
            v39 = 1.0;
          }
        }
        return;
      }
      v11 = v30 + 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: protected: float CPhysics_Airboat::GetWaterDepth(struct Ray_t __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
double __userpurge CPhysics_Airboat::GetWaterDepth@<st0>(
        CPhysics_Airboat *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Ray_t *pGameRay,
        IPhysicsObject *pPhysAirboat)
{
  float z; // eax
  IPhysicsGameTrace *m_pGameTrace; // ecx
  IPhysicsGameTrace_vtbl *v9; // esi
  int v10; // eax
  int v14; // [esp-Ch] [ebp-C4h] BYREF
  CGameTrace trace; // [esp+0h] [ebp-B8h] BYREF
  float v16; // [esp+54h] [ebp-64h]
  Ray_t waterRay; // [esp+58h] [ebp-60h] BYREF
  float v18; // [esp+A8h] [ebp-10h]
  Vector vecStart; // [esp+ACh] [ebp-Ch]
  float retaddr; // [esp+B8h] [ebp+0h]

  vecStart.x = a2;
  vecStart.y = retaddr;
  z = pGameRay->m_Start.z;
  *(_QWORD *)(&waterRay.m_IsSwept + 3) = *(_QWORD *)&pGameRay->m_Start.x;
  v18 = z;
  waterRay.m_Start.z = 0.0;
  waterRay.m_Start.w = (float)(z + 1000.0) - z;
  waterRay.m_Start.y = 0.0;
  waterRay.m_Extents.y = 0.0;
  BYTE1(waterRay.m_Extents.z) = (float)((float)((float)(0.0 * 0.0) + (float)(0.0 * 0.0))
                                      + (float)(waterRay.m_Start.w * waterRay.m_Start.w)) != 0.0;
  m_pGameTrace = this->m_pGameTrace;
  *(_QWORD *)&trace.m_pEnt = *(_QWORD *)(&waterRay.m_IsSwept + 3);
  LOBYTE(waterRay.m_Extents.z) = 1;
  memset(&waterRay.m_StartOffset.y, 0, 12);
  v16 = z;
  waterRay.m_Delta.y = -0.0;
  waterRay.m_Delta.z = -0.0;
  waterRay.m_Delta.w = -0.0;
  v9 = m_pGameTrace->__vftable;
  v10 = ((int (__thiscall *)(IPhysicsObject *, int *, int, int))pPhysAirboat->GetGameData)(
          a1: pPhysAirboat,
          a2: &v14,
          a3,
          a4);
  ((void (__thiscall *)(IPhysicsGameTrace *, CBaseEntity **, int))v9->VehicleTraceRayWithWater)(
    a1: this->m_pGameTrace,
    a2: &trace.m_pEnt,
    a3: v10);
  return trace.fraction * 1000.0;
}

//------------------------------------------------------------------------------
// Address: 0x10005AA0
// Name: protected: void CPhysics_Airboat::do_raycasts_gameside(int,class IVP_Ray_Solver_Template __near *,class IVP_Raycast_Airboat_Impact __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPhysics_Airboat::do_raycasts_gameside(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        int nRaycastCount,
        IVP_Ray_Solver_Template *pRays,
        IVP_Raycast_Airboat_Impact *pImpacts)
{
  CPhysics_Airboat *v6; // eax
  float *v7; // edi
  float *v8; // esi
  IPhysicsObject *client_data; // ecx
  void *(__thiscall *GetGameData)(IPhysicsObject *); // edx
  CBaseEntity *v11; // eax
  int v12; // eax
  double WaterDepth; // st7
  float *v14; // edi
  IVP_Real_Object *m_pAirboatBody; // edx
  IPhysicsObject *m_pGameTrace; // eax
  IPhysicsObject v17; // edi
  int *v18; // ecx
  int v19; // edx
  int v20; // eax
  float *v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  IPhysicsObject *v25; // eax
  float v26; // xmm4_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm2_4
  __int128 v33; // xmm0
  bool v34; // zf
  int dispFlags; // eax
  surfacedata_t *v36; // eax
  int v37; // [esp-Ch] [ebp-1DCh] BYREF
  int v38; // [esp-8h] [ebp-1D8h] BYREF
  _BYTE gameRays_52[272]; // [esp+34h] [ebp-19Ch] OVERLAPPED
  _BYTE v40[12]; // [esp+14Ch] [ebp-84h] BYREF
  CGameTrace trace; // [esp+158h] [ebp-78h]
  int v42; // [esp+1ACh] [ebp-24h]
  IPhysicsObject *v43; // [esp+1B0h] [ebp-20h]
  CPhysics_Airboat *v44; // [esp+1B4h] [ebp-1Ch]
  float *v45; // [esp+1B8h] [ebp-18h]
  IPhysicsObject *pPhysAirboat; // [esp+1BCh] [ebp-14h]
  float *v47; // [esp+1C0h] [ebp-10h]
  _DWORD v48[3]; // [esp+1C4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+1D0h] [ebp+0h]

  v48[0] = a2;
  v48[1] = retaddr;
  *(_DWORD *)gameRays_52 = 0;
  *(_DWORD *)&gameRays_52[80] = 0;
  *(_DWORD *)&gameRays_52[160] = 0;
  *(_DWORD *)&gameRays_52[240] = 0;
  v44 = this;
  CPhysics_Airboat::pre_raycasts_gameside(
    this,
    a2: (int)pImpacts,
    a3: (int)this,
    nRaycastCount,
    pRays,
    pGameRays: (Ray_t *)&v37,
    pImpacts);
  if ( nRaycastCount > 0 )
  {
    v6 = v44;
    v7 = &pImpacts->vecImpactPointWS.k[2];
    pPhysAirboat = (IPhysicsObject *)this->m_CarSystemDebugData.wheelRaycastImpacts;
    v8 = (float *)&v38;
    v45 = &pImpacts->vecImpactPointWS.k[2];
    v47 = &v44->m_CarSystemDebugData.wheelRaycasts[0][0].k[2];
    v42 = nRaycastCount;
    while ( 1 )
    {
      if ( *((_DWORD *)v7 - 6) != 0 )
      {
        client_data = (IPhysicsObject *)v6->m_pAirboatBody->client_data;
        GetGameData = client_data->GetGameData;
        trace.hitbox = (int)v6->m_pGameTrace;
        v11 = *(CBaseEntity **)trace.hitbox;
        v43 = client_data;
        trace.m_pEnt = v11;
        v12 = ((int (__stdcall *)(_BYTE *))GetGameData)(a1: v40);
        (*(void (__thiscall **)(int, float *, int))trace.m_pEnt)(a1: trace.hitbox, a2: v8 - 1, a3: v12);
        WaterDepth = CPhysics_Airboat::GetWaterDepth(
                       this: v44,
                       a2: COERCE_FLOAT(v48),
                       a3: (int)(v8 - 1),
                       a4: (int)v8,
                       pGameRay: (Ray_t *)(v8 - 1),
                       pPhysAirboat: v43);
        v14 = v45;
        v45[6] = WaterDepth;
      }
      else
      {
        m_pAirboatBody = v6->m_pAirboatBody;
        m_pGameTrace = (IPhysicsObject *)v6->m_pGameTrace;
        v17.__vftable = m_pGameTrace->__vftable;
        v18 = (int *)m_pAirboatBody->client_data;
        v19 = *v18;
        v43 = m_pGameTrace;
        v20 = (*(int (__thiscall **)(int *, _BYTE *))(v19 + 68))(a1: v18, a2: v40);
        ((void (__thiscall *)(IPhysicsObject *, float *, int))v17.IsStatic)(a1: v43, a2: v8 - 1, a3: v20);
        v14 = v45;
      }
      v21 = v47;
      v22 = v8[7] + *(v8 - 1);
      v23 = v8[9] + v8[1];
      v24 = v8[8] + *v8;
      v25 = pPhysAirboat;
      *(v47 - 2) = g_PhysicsUnits.unitScaleMeters * v22;
      v26 = v24;
      v27 = v24 + v8[4];
      *(v21 - 1) = -(float)(v23 * g_PhysicsUnits.unitScaleMeters);
      v28 = v8[3] + v22;
      v29 = v8[5];
      *v21 = v26 * g_PhysicsUnits.unitScaleMeters;
      v21[2] = v28 * g_PhysicsUnits.unitScaleMeters;
      v30 = v8[4];
      v21[3] = -(float)((float)(v29 + v23) * g_PhysicsUnits.unitScaleMeters);
      v31 = v8[5];
      v21[4] = v27 * g_PhysicsUnits.unitScaleMeters;
      v32 = (float)((float)(v8[3] * v8[3]) + (float)(v30 * v30)) + (float)(v31 * v31);
      v33 = 0;
      *(float *)&v33 = fsqrt(v32);
      *(_OWORD *)&gameRays_52[256] = v33;
      *(float *)&v33 = trace.plane.normal.z;
      *(float *)&v25->__vftable = *(float *)&gameRays_52[256] * trace.plane.normal.z;
      *(v14 - 7) = 0.0;
      *(v14 - 8) = 0.0;
      if ( *(float *)&v33 != 1.0 )
      {
        v34 = (LOWORD(trace.plane.dist) & 0x4030) == 0;
        *((_DWORD *)v14 - 8) = 1;
        v14[6] = 0.0;
        if ( !v34 )
          *((_DWORD *)v14 - 7) = 1;
        dispFlags = (__int16)trace.dispFlags;
        *(v14 - 2) = trace.startpos.x * g_PhysicsUnits.unitScaleMeters;
        *(v14 - 1) = -(float)(trace.startpos.z * g_PhysicsUnits.unitScaleMeters);
        *v14 = trace.startpos.y * g_PhysicsUnits.unitScaleMeters;
        v14[2] = trace.endpos.x;
        v14[3] = -trace.endpos.z;
        v14[4] = trace.endpos.y;
        v36 = physprops->GetSurfaceData(this: physprops, a2: dispFlags);
        *((_DWORD *)v14 + 9) = (__int16)trace.dispFlags;
        v21 = v47;
        v14[8] = v36->physics.dampening;
        v14[7] = v36->physics.friction;
      }
      ++pPhysAirboat;
      v7 = v14 + 48;
      v8 += 20;
      v34 = v42-- == 1;
      v47 = v21 + 8;
      v45 = v7;
      if ( v34 )
        break;
      v6 = v44;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005D90
// Name: private: void CPhysics_Airboat::DoSimulationPontoons(class IVP_Raycast_Airboat_Impact __near *,class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationPontoons(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        IVP_Raycast_Airboat_Impact *pImpacts,
        IVP_Event_Sim *pEventSim)
{
  int n_wheels; // eax
  float *v5; // esi
  float *p_raycast_length; // edi
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  IVP_Core *m_pCore; // ecx
  float v16; // xmm0_4
  float v17; // xmm0_4
  IVP_Core *v18; // ecx
  float v19; // xmm1_4
  IVP_U_Float_Point v20; // [esp-30h] [ebp-3Ch] BYREF
  IVP_U_Float_Point v21; // [esp-20h] [ebp-2Ch] BYREF
  int i; // [esp-8h] [ebp-14h]
  CPhysics_Airboat *v23; // [esp-4h] [ebp-10h]
  int v24; // [esp+0h] [ebp-Ch]
  void *v25; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  n_wheels = this->n_wheels;
  v23 = this;
  if ( n_wheels > 0 )
  {
    v5 = &pImpacts->surface_speed_wheel_ws.k[1];
    p_raycast_length = &this->m_aAirboatWheels[0].raycast_length;
    for ( i = n_wheels; i != 0; --i )
    {
      if ( p_raycast_length != (float *)48 )
      {
        if ( *((_DWORD *)v5 + 17) != 0 )
        {
          v7 = p_raycast_length[33] - *p_raycast_length;
          if ( v7 < 0.0 )
          {
            v8 = p_raycast_length[10] * v7;
            v9 = v5[16];
            LODWORD(v10) = LODWORD(v8) ^ _mask__NegFloat_;
            if ( v9 >= 0.0 )
            {
              if ( v9 > 3.0 )
                v9 = 3.0;
            }
            else
            {
              v9 = 0.0;
            }
            v11 = v9 * v10;
            v12 = (float)((float)(*(v5 - 9) * (float)(v5[3] - *(v5 - 1))) + (float)(*(v5 - 8) * (float)(v5[4] - *v5)))
                + (float)(*(v5 - 7) * (float)(v5[5] - v5[1]));
            if ( v12 <= 0.0 )
              v13 = v12 * p_raycast_length[12];
            else
              v13 = v12 * p_raycast_length[11];
            v14 = v11 - v13;
            if ( v14 < 0.0 )
              v14 = 0.0;
            m_pCore = this->m_pCore;
            v16 = pEventSim->delta_time * v14;
            v21.k[0] = v5[27] * v16;
            v21.k[1] = v5[28] * v16;
            v21.k[2] = v5[29] * v16;
            IVP_Core::push_core_ws(this: m_pCore, world_point: (const IVP_U_Point *)(v5 + 23), impulse_in_world: &v21);
LABEL_22:
            this = v23;
          }
        }
        else if ( *((_DWORD *)v5 + 19) != 0 )
        {
          v17 = v5[31];
          if ( v17 >= 0.0 )
          {
            if ( v17 > 0.41 )
              v17 = 0.41;
          }
          else
          {
            v17 = 0.0;
          }
          v18 = this->m_pCore;
          v19 = (float)((float)((float)((float)(v17 * 2.8) * 0.0254) * (float)(v18->rot_inertia.hesse_val * 0.40000001))
                      * 1000.0)
              * pEventSim->delta_time;
          v20.k[0] = v19 * 0.0;
          v20.k[1] = v19 * -1.0;
          v20.k[2] = v19 * 0.0;
          IVP_Core::push_core_ws(this: v18, world_point: (const IVP_U_Point *)(v5 + 23), impulse_in_world: &v20);
          goto LABEL_22;
        }
      }
      p_raycast_length += 48;
      v5 += 48;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F90
// Name: private: void CPhysics_Airboat::DoSimulationSteering(class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::DoSimulationSteering(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *pEventSim)
{
  float v3; // xmm1_4
  float m_flThrust; // xmm0_4
  bool v5; // cc
  float m_flSteerTime; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float m_flPrevSteeringAngle; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  double v12; // xmm0_8
  IVP_Core *m_pCore; // ecx
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16[3]; // [esp-Ch] [ebp-2Ch] BYREF
  float m_SteeringAngle; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch]
  void *v19; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  m_SteeringAngle = this->m_SteeringAngle;
  v3 = m_SteeringAngle;
  if ( m_SteeringAngle == 0.0 || this->m_flThrust != 0.0 )
  {
    m_flThrust = this->m_flThrust;
    if ( this->m_bAnalogSteering )
    {
      if ( m_flThrust < -2.0 )
      {
        this->m_bSteeringReversed = true;
        goto LABEL_13;
      }
      v5 = m_flThrust <= 2.0;
    }
    else
    {
      if ( m_flThrust < 0.0 )
      {
        this->m_bSteeringReversed = true;
        goto LABEL_13;
      }
      v5 = m_flThrust == 0.0;
    }
    if ( !v5 || this->m_vecLocalVelocity.k[2] > 0.0 )
      this->m_bSteeringReversed = false;
  }
LABEL_13:
  m_flSteerTime = fabs(v3);
  v7 = 0.0;
  if ( m_flSteerTime > 0.01 )
  {
    if ( v3 >= 0.0 )
      v8 = 1.0;
    else
      v8 = -1.0;
    if ( this->m_bSteeringReversed )
      v8 = v8 * -1.0;
    m_flPrevSteeringAngle = this->m_flPrevSteeringAngle;
    if ( m_flPrevSteeringAngle >= 0.0 )
      v10 = 1.0;
    else
      v10 = -1.0;
    if ( fabs(m_flPrevSteeringAngle) < 0.01 || v8 != v10 )
      this->m_flSteerTime = 0.0;
    if ( !this->m_bAnalogSteering )
      m_flSteerTime = this->m_flSteerTime;
    v11 = m_flSteerTime * 2.0;
    if ( v11 >= 0.0 )
    {
      if ( v11 > 1.0 )
        v11 = 1.0;
    }
    else
    {
      v11 = 0.0;
    }
    v3 = m_SteeringAngle;
    LODWORD(v7) = COERCE_UNSIGNED_INT(
                    (float)((float)(this->m_pCore->rot_inertia.hesse_val * (float)((float)(v11 * 0.0018) + 0.00044999999))
                          * pEventSim->i_delta_time)
                  * v8)
                ^ _mask__NegFloat_;
    this->m_flSteerTime = this->m_flSteerTime + pEventSim->delta_time;
  }
  if ( this->m_bSteeringReversed )
    v12 = -1.0;
  else
    v12 = 1.0;
  this->m_flPrevSteeringAngle = v3 * v12;
  m_pCore = this->m_pCore;
  if ( m_pCore->rot_speed.k[1] >= 0.0 )
    v14 = 1.0;
  else
    v14 = -1.0;
  v15 = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(m_pCore->rot_speed.k[1]) & _mask__AbsFloat_) * 0.001)
                              * m_pCore->rot_inertia.hesse_val)
                      * pEventSim->i_delta_time)
              * v14)
      + (float)((float)((float)((float)((float)((float)(m_pCore->rot_speed.k[1] * 0.000039999999)
                                              * m_pCore->rot_speed.k[1])
                                      * m_pCore->rot_inertia.hesse_val)
                              * pEventSim->i_delta_time)
                      * v14)
              + v7);
  v16[0] = v15 * 0.0;
  v16[1] = v15 * -1.0;
  v16[2] = v15 * 0.0;
  IVP_Core::rot_push_core_cs(this: m_pCore, rot_impulse_cs: (const IVP_U_Float_Point *)v16);
}

//------------------------------------------------------------------------------
// Address: 0x10006200
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY IVP_Standard_Gravity_Controller::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Standard_Gravity_Controller::get_controller_priority(IVP_Standard_Gravity_Controller *this)
{
  return 1000;
}

//------------------------------------------------------------------------------
// Address: 0x10006210
// Name: public: virtual char const __near * IVP_Standard_Gravity_Controller::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Standard_Gravity_Controller::get_controller_name(IVP_Standard_Gravity_Controller *this)
{
  return "sys:gravity";
}

//------------------------------------------------------------------------------
// Address: 0x10006220
// Name: private: void CPhysics_Airboat::InitRaycastCarBody(class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::InitRaycastCarBody(
        CPhysics_Airboat *this,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  __int16 n_wheels; // ax
  __int16 n_axis; // cx
  IVP_Real_Object *car_body; // eax
  double body_down_force_vertical_offset; // st7
  const IVP_Template_Car_System *pCarSystemTemplatea; // [esp+14h] [ebp+8h]

  n_wheels = pCarSystemTemplate->n_wheels;
  this->n_wheels = pCarSystemTemplate->n_wheels;
  n_axis = pCarSystemTemplate->n_axis;
  this->n_axis = n_axis;
  this->wheels_per_axis = n_wheels / n_axis;
  car_body = pCarSystemTemplate->car_body;
  this->m_pAirboatBody = car_body;
  pCarSystemTemplatea = (const IVP_Template_Car_System *)car_body->physical_core;
  if ( this->vector_of_cores.n_elems >= this->vector_of_cores.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->vector_of_cores);
  this->vector_of_cores.elems[this->vector_of_cores.n_elems++] = (void *)pCarSystemTemplatea;
  body_down_force_vertical_offset = pCarSystemTemplate->body_down_force_vertical_offset;
  this->down_force = 0.0;
  this->down_force_vertical_offset = body_down_force_vertical_offset;
  this->m_pAirboatBody->physical_core->rot_speed.k[0] = 0.0;
  this->m_pAirboatBody->physical_core->speed.k[0] = 0.0;
  this->m_pAirboatBody->physical_core->rot_speed.k[1] = 0.0;
  this->m_pAirboatBody->physical_core->speed.k[1] = 0.0;
  this->m_pAirboatBody->physical_core->rot_speed.k[2] = 0.0;
  this->m_pAirboatBody->physical_core->speed.k[2] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10006340
// Name: protected: virtual void CPhysics_Airboat::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::do_simulation_controller(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *pEventSim,
        IVP_U_Vector<IVP_Core> *__formal)
{
  int v5; // eax
  IVP_U_Matrix3 *v6; // edi
  CPhysics_Airboat *v7; // edi
  _BYTE v9[12]; // [esp-Ch] [ebp-3DCh] BYREF
  IVP_Raycast_Airboat_Impact impacts[4]; // [esp+0h] [ebp-3D0h] BYREF
  IVP_U_Matrix *v11; // [esp+3C0h] [ebp-10h]
  _DWORD v12[2]; // [esp+3C4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+3D0h] [ebp+0h]

  v12[0] = a2;
  v12[1] = retaddr;
  v5 = *(_DWORD *)(LODWORD(this->m_flSpeed) + 148);
  v6 = (IVP_U_Matrix3 *)(v5 + 96);
  this->m_pGameTrace = (IPhysicsGameTrace *)v5;
  v11 = (IVP_U_Matrix *)(v5 + 96);
  this->m_vecLocalVelocity.hesse_val = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)(v5 + 208));
  IVP_U_Matrix3::vimult3(
    this: v6,
    p_in: (const IVP_U_Float_Point *)&this->m_pGameTrace[52],
    p_out: (IVP_U_Float_Point *)&this->m_pCore);
  v7 = (CPhysics_Airboat *)((char *)this - 4);
  CPhysics_Airboat::PreRaycasts(
    this: (CPhysics_Airboat *)((char *)this - 4),
    pRaySolverTemplates: (IVP_Ray_Solver_Template *)&impacts[3].flFriction,
    matWorldFromCore: v11,
    pImpacts: (IVP_Raycast_Airboat_Impact *)v9);
  CPhysics_Airboat::do_raycasts_gameside(
    this: (CPhysics_Airboat *)((char *)this - 4),
    a2: (int)v12,
    nRaycastCount: SLOWORD(this->m_pAirboatBody),
    pRays: (IVP_Ray_Solver_Template *)&impacts[3].flFriction,
    pImpacts: (IVP_Raycast_Airboat_Impact *)v9);
  if ( CPhysics_Airboat::PostRaycasts(
         this: (CPhysics_Airboat *)((char *)this - 4),
         a2: (int)v12,
         pRaySolverTemplates: (IVP_Ray_Solver_Template *)&impacts[3].flFriction,
         matWorldFromCore: v11,
         pImpacts: (IVP_Raycast_Airboat_Impact *)v9) != 0 )
  {
    CPhysics_Airboat::UpdateAirborneState(this: v7, pImpacts: (IVP_Raycast_Airboat_Impact *)v9, pEventSim);
    CPhysics_Airboat::DoSimulationPontoons(
      this: v7,
      a2: (int)v12,
      pImpacts: (IVP_Raycast_Airboat_Impact *)v9,
      pEventSim);
    CPhysics_Airboat::DoSimulationDrag(
      this: v7,
      a2: (int)v12,
      a3: (int)v7,
      a4: (int)pEventSim,
      pImpacts: (IVP_Raycast_Airboat_Impact *)v9,
      pEventSim);
    CPhysics_Airboat::DoSimulationTurbine(this: v7, a2: COERCE_FLOAT(v12), pEventSim);
    CPhysics_Airboat::DoSimulationSteering(this: v7, a2: (int)v12, pEventSim);
    CPhysics_Airboat::DoSimulationKeepUprightPitch(
      this: v7,
      a2: (int)v12,
      a3: (int)pEventSim,
      pImpacts: (IVP_Raycast_Airboat_Impact *)v9,
      pEventSim);
    CPhysics_Airboat::DoSimulationKeepUprightRoll(
      this: v7,
      a2: (int)v12,
      a3: (int)pEventSim,
      pImpacts: (IVP_Raycast_Airboat_Impact *)v9,
      pEventSim);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006460
// Name: private: void CPhysics_Airboat::InitRaycastCarEnvironment(class IVP_Environment __near *,class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysics_Airboat::InitRaycastCarEnvironment(
        CPhysics_Airboat *this,
        IVP_Environment *pEnvironment,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  IVP_Controller *v4; // eax
  IVP_COORDINATE_INDEX index_y; // ecx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  this->index_x = pCarSystemTemplate->index_x;
  this->index_y = pCarSystemTemplate->index_y;
  this->index_z = pCarSystemTemplate->index_z;
  this->is_left_handed = pCarSystemTemplate->is_left_handed;
  v4 = (IVP_Controller *)p_malloc(size: 0x30u);
  if ( v4 != nullptr )
    v4->__vftable = (IVP_Controller_vtbl *)&IVP_Standard_Gravity_Controller::`vftable';
  else
    v4 = nullptr;
  v4[4].__vftable = nullptr;
  v4[5].__vftable = (IVP_Controller_vtbl *)1092416963;
  v4[6].__vftable = nullptr;
  IVP_Core::add_core_controller(this: this->m_pAirboatBody->physical_core, add_cntrl: v4);
  IVP_Controller_Manager::announce_controller_to_environment(
    this: pEnvironment->controller_manager,
    cntrl: &this->IVP_Controller_Dependent);
  index_y = this->index_y;
  this->extra_gravity = pCarSystemTemplate->extra_gravity_force_value;
  if ( pEnvironment->gravity.k[index_y] <= 0.0 )
    v6 = -1.0;
  else
    v6 = 1.0;
  this->gravity_y_direction = v6;
  v7 = pEnvironment->gravity.k[1];
  v8 = pEnvironment->gravity.k[2];
  this->normized_gravity_ws.k[0] = pEnvironment->gravity.k[0];
  this->normized_gravity_ws.k[1] = v7;
  this->normized_gravity_ws.k[2] = v8;
  IVP_U_Float_Point::fast_normize(this: &this->normized_gravity_ws);
}

//------------------------------------------------------------------------------
// Address: 0x10006560
// Name: private: void CPhysics_Airboat::InitRaycastCarWheels(class IVP_Template_Car_System const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysics_Airboat::InitRaycastCarWheels(
        CPhysics_Airboat *this@<ecx>,
        int a2@<ebp>,
        const IVP_Template_Car_System *pCarSystemTemplate)
{
  float *v4; // esi
  float *v5; // eax
  float hesse_val; // ecx
  double v7; // st7
  float v8; // eax
  double v9; // st7
  int n_wheels; // ecx
  _BYTE v11[12]; // [esp+14h] [ebp-5Ch] BYREF
  IVP_U_Matrix m_core_f_object; // [esp+20h] [ebp-50h]
  const IVP_U_Float_Point *trace_pos_Bos; // [esp+60h] [ebp-10h]
  int v14; // [esp+64h] [ebp-Ch]
  int iWheel; // [esp+68h] [ebp-8h]
  int retaddr; // [esp+70h] [ebp+0h]

  v14 = a2;
  iWheel = retaddr;
  IVP_Real_Object::calc_m_core_f_object(this: this->m_pAirboatBody, m_core_f_object: (IVP_U_Matrix *)v11);
  m_core_f_object.vv.hesse_val = 0.0;
  if ( this->n_wheels > 0 )
  {
    LODWORD(m_core_f_object.vv.k[2]) = pCarSystemTemplate->spring_constant;
    trace_pos_Bos = pCarSystemTemplate->trace_pos_Bos;
    v4 = &this->m_aAirboatWheels[0].raycast_dir_cs.k[1];
    do
    {
      memset(dst: (unsigned __int8 *)v4 - 36, value: 0, count: 0xC0u);
      IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v11, p_in: trace_pos_Bos - 10, p_out: (IVP_U_Float_Point *)(v4 - 9));
      IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v11, p_in: trace_pos_Bos, p_out: (IVP_U_Float_Point *)(v4 - 5));
      v4[3] = 0.34999999;
      *(_QWORD *)v4 = 0;
      *(v4 - 1) = 0.0;
      v4[this->index_y - 1] = this->gravity_y_direction;
      v5 = (float *)LODWORD(m_core_f_object.vv.k[2]);
      *((_DWORD *)v4 + 12) = *(_DWORD *)(LODWORD(m_core_f_object.vv.k[2]) + 160) ^ _mask__NegFloat_;
      *((_QWORD *)v4 + 4) = 0;
      v4[7] = 0.0;
      v4[this->index_y + 7] = this->gravity_y_direction;
      hesse_val = m_core_f_object.vv.hesse_val;
      v4[13] = *v5;
      v4[14] = v5[10];
      v7 = v5[20];
      v4[19] = 1.0;
      v4[15] = v7;
      v4[17] = *(v5 - 105);
      v4[18] = 1.0 / *(v5 - 105);
      ((void (__thiscall *)(CPhysics_Airboat *, _DWORD, _DWORD))this->do_steering_wheel)(
        a1: this,
        a2: LODWORD(hesse_val),
        a3: 0);
      v8 = m_core_f_object.vv.hesse_val;
      ++trace_pos_Bos;
      LODWORD(m_core_f_object.vv.k[2]) += 4;
      v4[21] = 0.0;
      v9 = pCarSystemTemplate->wheel_max_rotation_speed[SLODWORD(v8) >> 1];
      *((_DWORD *)v4 + 21) = 1;
      v4[16] = v9;
      n_wheels = this->n_wheels;
      v4 += 48;
      LODWORD(m_core_f_object.vv.hesse_val) = LODWORD(v8) + 1;
    }
    while ( LODWORD(v8) + 1 < n_wheels );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100066F0
// Name: public: CPhysics_Airboat::CPhysics_Airboat(class IVP_Environment __near *,class IVP_Template_Car_System const __near *,class IPhysicsGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysics_Airboat *__thiscall CPhysics_Airboat::CPhysics_Airboat(
        CPhysics_Airboat *this,
        IVP_Environment *pEnv,
        const IVP_Template_Car_System *pCarSystem,
        IPhysicsGameTrace *pGameTrace)
{
  void (__thiscall *do_steering)(struct CPhysics_Airboat *, float, bool); // eax
  int v6; // edx
  IVP_Raycast_Airboat_Axle *m_aAirboatAxles; // ecx
  float *stabilizer_constant; // eax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  IVP_Car_System::IVP_Car_System(this);
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&IVP_Controller_Dependent::`vftable';
  this->IVP_Car_System::__vftable = (CPhysics_Airboat_vtbl *)&CPhysics_Airboat::`vftable'{for `IVP_Car_System'};
  this->IVP_Controller_Dependent::IVP_Controller::__vftable = (IVP_Controller_Dependent_vtbl *)&CPhysics_Airboat::`vftable'{for `IVP_Controller_Dependent'};
  this->vector_of_cores.elems = this->vector_of_cores.elem_buffer;
  *(_DWORD *)&this->vector_of_cores.memsize = 1;
  CPhysics_Airboat::InitRaycastCarBody(this, pCarSystemTemplate: pCarSystem);
  CPhysics_Airboat::InitRaycastCarEnvironment(this, pEnvironment: pEnv, pCarSystemTemplate: pCarSystem);
  CPhysics_Airboat::InitRaycastCarWheels(this, a2: (int)&savedregs, pCarSystemTemplate: pCarSystem);
  do_steering = this->do_steering;
  this->m_SteeringAngle = -1.0;
  ((void (__thiscall *)(CPhysics_Airboat *, _DWORD, _DWORD))do_steering)(a1: this, a2: 0, a3: 0);
  v6 = 0;
  if ( this->n_axis > 0 )
  {
    m_aAirboatAxles = this->m_aAirboatAxles;
    stabilizer_constant = pCarSystem->stabilizer_constant;
    do
    {
      ++v6;
      m_aAirboatAxles->stabilizer_constant = *stabilizer_constant++;
      ++m_aAirboatAxles;
    }
    while ( v6 < this->n_axis );
  }
  CPhysics_Airboat::InitAirboat(this, pCarSystem);
  this->m_bSteeringReversed = false;
  this->m_bAirborne = false;
  this->m_bWeakJump = false;
  this->m_pGameTrace = pGameTrace;
  this->m_SteeringAngle = 0.0;
  this->m_flThrust = 0.0;
  this->m_flAirTime = 0.0;
  this->m_flPitchErrorPrev = 0.0;
  this->m_flRollErrorPrev = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016EB0
// Name: public: virtual float CPhysics_Airboat::get_booster_time_to_go(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysics_Airboat::get_booster_time_to_go(IVP_Controller_Buoyancy *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10006820
// Name: __CreateCPhysicsCollisionIPhysicsCollision_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysicsCollision *__cdecl _CreateCPhysicsCollisionIPhysicsCollision_interface()
{
  return &g_PhysicsCollision;
}
