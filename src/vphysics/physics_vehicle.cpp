// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_vehicle.cpp
// Functions: 78
// ============================================================

#include "vphysics\physics_vehicle.h"

//------------------------------------------------------------------------------
// Address: 0x100235A0
// Name: public: virtual class IPhysicsObject __near * CVehicleController::GetWheel(int)
// Source: json
//------------------------------------------------------------------------------
CPhysicsObject *__thiscall CVehicleController::GetWheel(CVehicleController *this, int index)
{
  unsigned int m_nVehicleType; // edx
  CPhysics_Car_System_Raycast_Wheels *m_pCarSystem; // ecx
  CPhysics_Airboat *v6; // eax

  m_nVehicleType = this->m_nVehicleType;
  if ( m_nVehicleType == 1 )
    return this->m_pWheels[index];
  if ( m_nVehicleType == 2 )
  {
    m_pCarSystem = (CPhysics_Car_System_Raycast_Wheels *)this->m_pCarSystem;
    if ( m_pCarSystem != nullptr )
      return (CPhysicsObject *)CPhysics_Car_System_Raycast_Wheels::GetWheel(this: m_pCarSystem, index);
  }
  if ( m_nVehicleType == 8 )
  {
    v6 = (CPhysics_Airboat *)this->m_pCarSystem;
    if ( v6 != nullptr )
      return (CPhysicsObject *)CPhysics_Airboat::GetWheel(this: v6, index);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100235F0
// Name: public: virtual void CVehicleController::SetWheelFriction(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::SetWheelFriction(CVehicleController *this, int wheelIndex, float friction)
{
  CPhysics_Airboat *m_pCarSystem; // ecx

  m_pCarSystem = (CPhysics_Airboat *)this->m_pCarSystem;
  if ( m_pCarSystem != nullptr )
    CPhysics_Airboat::SetWheelFriction(this: m_pCarSystem, iWheel: wheelIndex, flFriction: friction);
}

//------------------------------------------------------------------------------
// Address: 0x10023620
// Name: protected: void CVehicleController::ShutdownCarSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::ShutdownCarSystem(CVehicleController *this)
{
  IVP_Car_System *m_pCarSystem; // ecx
  int v3; // ebx
  IPhysicsObject **m_pWheels; // edi

  m_pCarSystem = this->m_pCarSystem;
  v3 = 0;
  if ( m_pCarSystem != nullptr )
    ((void (__thiscall *)(IVP_Car_System *, int))m_pCarSystem->dtr_IVP_Car_System)(a1: m_pCarSystem, a2: 1);
  this->m_pCarSystem = nullptr;
  if ( this->m_wheelCount > 0 )
  {
    m_pWheels = this->m_pWheels;
    do
    {
      if ( *m_pWheels != nullptr )
        this->m_pEnv->DestroyObject(this: this->m_pEnv, a2: *m_pWheels);
      *m_pWheels = nullptr;
      ++v3;
      ++m_pWheels;
    }
    while ( v3 < this->m_wheelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023670
// Name: public: virtual void CVehicleController::SetSpringLength(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::SetSpringLength(CVehicleController *this, int wheelIndex, float length)
{
  ((void (__stdcall *)(int, _DWORD))this->m_pCarSystem->change_spring_length)(a1: wheelIndex, a2: LODWORD(length));
}

//------------------------------------------------------------------------------
// Address: 0x10023690
// Name: public: virtual float CVehicleController::UpdateBooster(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVehicleController::UpdateBooster(CVehicleController *this, float dt)
{
  double result; // st7

  ((void (__stdcall *)(_DWORD))this->m_pCarSystem->update_booster)(a1: LODWORD(dt));
  result = ((double (__thiscall *)(IVP_Car_System *))this->m_pCarSystem->get_booster_delay)(a1: this->m_pCarSystem);
  this->m_currentState.boostDelay = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100236C0
// Name: protected: virtual bool CVehicleController::IsBoosting(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVehicleController::IsBoosting(CVehicleController *this)
{
  return ((double (__thiscall *)(IVP_Car_System *))this->m_pCarSystem->get_booster_time_to_go)(a1: this->m_pCarSystem) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100236E0
// Name: protected: void CVehicleController::CalcEngineTransmission(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::CalcEngineTransmission(CVehicleController *this, float flThrottle)
{
  int v3; // edi
  long double v4; // st7
  float v5; // xmm1_4
  float v6; // xmm0_4
  int v7; // ecx
  int gear; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  float flAvgRotSpeed; // [esp+4h] [ebp-4h]

  if ( this->m_vehicleData.engine.isAutoTransmission )
  {
    v3 = 0;
    for ( flAvgRotSpeed = 0.0; v3 < this->m_wheelCount; flAvgRotSpeed = fabs(v4) + flAvgRotSpeed )
      v4 = ((double (__thiscall *)(IVP_Car_System *, int))this->m_pCarSystem->get_wheel_angular_velocity)(
             a1: this->m_pCarSystem,
             a2: v3++);
    v5 = this->m_vehicleData.engine.axleRatio * (float)((float)(0.15915494 / (float)this->m_wheelCount) * flAvgRotSpeed);
    v6 = (float)(this->m_vehicleData.engine.gearRatio[this->m_currentState.gear] * v5) * 60.0;
    if ( flThrottle > 0.0 && v6 > this->m_vehicleData.engine.shiftUpRPM )
    {
      v7 = this->m_vehicleData.engine.gearCount - 1;
      do
      {
        gear = this->m_currentState.gear;
        if ( gear >= v7 )
          break;
        v9 = gear + 1;
        this->m_currentState.gear = v9;
        v6 = (float)(this->m_vehicleData.engine.gearRatio[v9] * v5) * 60.0;
      }
      while ( v6 > this->m_vehicleData.engine.shiftUpRPM );
    }
    for ( ;
          this->m_vehicleData.engine.shiftDownRPM > v6;
          v6 = (float)(this->m_vehicleData.engine.gearRatio[v11] * v5) * 60.0 )
    {
      v10 = this->m_currentState.gear;
      if ( v10 <= 0 )
        break;
      v11 = v10 - 1;
      this->m_currentState.gear = v11;
    }
    this->m_currentState.engineRPM = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023800
// Name: public: virtual void CVehicleController::OnVehicleEnter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::OnVehicleEnter(CVehicleController *this)
{
  bool v1; // zf
  CPhysicsObject *m_pCarBody; // ecx
  float flDampSpeed; // [esp+0h] [ebp-8h] BYREF
  float flDampRotSpeed; // [esp+4h] [ebp-4h] BYREF

  v1 = this->m_nVehicleType == 8;
  this->m_bOccupied = true;
  if ( v1 )
  {
    m_pCarBody = this->m_pCarBody;
    flDampSpeed = 0.0;
    flDampRotSpeed = 0.0;
    m_pCarBody->SetDamping(this: m_pCarBody, a2: &flDampSpeed, a3: &flDampRotSpeed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023840
// Name: public: virtual void CVehicleController::OnVehicleExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::OnVehicleExit(CVehicleController *this)
{
  bool v2; // zf
  IVP_POS_WHEEL v3; // ebx
  int v4; // edi
  CPhysicsObject *m_pCarBody; // ecx
  float flDampRotSpeed; // [esp+4h] [ebp-Ch] BYREF
  int *flDampSpeed; // [esp+8h] [ebp-8h] BYREF
  CPhysicsObject **v8; // [esp+Ch] [ebp-4h]

  v2 = !this->m_vehicleData.steering.isSkidAllowed;
  this->m_bOccupied = false;
  if ( !v2 )
  {
    v3 = IVP_FRONT_LEFT;
    flDampRotSpeed = 0.0;
    if ( this->m_vehicleData.axleCount > 0 )
    {
      flDampSpeed = &this->m_vehicleData.axles[0].wheels.materialIndex;
      do
      {
        v4 = 0;
        if ( this->m_vehicleData.wheelsPerAxle > 0 )
        {
          v8 = &this->m_pWheels[v3];
          do
          {
            if ( this->m_nTireType != 0 )
              (*v8)->SetMaterialIndex(this: *v8, a2: *flDampSpeed);
            this->m_pCarSystem->fix_wheel(this: this->m_pCarSystem, a2: v3, a3: IVP_TRUE);
            ++v8;
            ++v4;
            ++v3;
          }
          while ( v4 < this->m_vehicleData.wheelsPerAxle );
        }
        flDampSpeed += 29;
        ++LODWORD(flDampRotSpeed);
      }
      while ( SLODWORD(flDampRotSpeed) < this->m_vehicleData.axleCount );
    }
    this->m_nTireType = 0;
    this->m_currentState.skidSpeed = 0.0;
  }
  if ( this->m_nVehicleType == 8 )
  {
    m_pCarBody = this->m_pCarBody;
    flDampSpeed = (int *)1065353216;
    flDampRotSpeed = 1.0;
    m_pCarBody->SetDamping(this: m_pCarBody, a2: (const float *)&flDampSpeed, a3: &flDampRotSpeed);
  }
  this->SetEngineDisabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10023920
// Name: public: IVP_Template_Car_System::IVP_Template_Car_System(int,int)
// Source: json
//------------------------------------------------------------------------------
IVP_Template_Car_System *__thiscall IVP_Template_Car_System::IVP_Template_Car_System(
        IVP_Template_Car_System *this,
        int n_wheels_,
        int n_axis_)
{
  int v4; // eax
  float *wheel_reversed_sign; // ecx

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(IVP_Template_Car_System));
  this->n_axis = n_axis_;
  v4 = 0;
  this->n_wheels = n_wheels_;
  if ( n_wheels_ > 0 )
  {
    wheel_reversed_sign = this->wheel_reversed_sign;
    do
    {
      *wheel_reversed_sign = 1.0;
      ++v4;
      this->index_x = IVP_INDEX_X;
      this->index_y = IVP_INDEX_Y;
      this->index_z = IVP_INDEX_Z;
      this->is_left_handed = IVP_FALSE;
      ++wheel_reversed_sign;
    }
    while ( v4 < this->n_wheels );
  }
  this->fast_turn_factor = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023990
// Name: bool ShouldOverrideWheelContactFriction(float __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall ShouldOverrideWheelContactFriction@<al>(
        int a1@<ebp>,
        float *pFrictionOut,
        IVP_Real_Object *pivp0,
        IVP_Real_Object *pivp1,
        IVP_U_Float_Point *pNormal)
{
  IVP_Real_Object *v5; // ecx
  _BYTE *client_data; // eax
  _BYTE *v7; // eax
  int v9; // [esp-Ch] [ebp-2Ch] BYREF
  int v10; // [esp+14h] [ebp-Ch]
  void *v11; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  v5 = pivp0;
  if ( pivp0->physical_core->car_wheel == nullptr && pivp1->physical_core->car_wheel == nullptr )
    return 0;
  client_data = pivp0->client_data;
  if ( client_data == nullptr || (client_data[28] & 0x40) == 0 )
  {
    v7 = pivp1->client_data;
    if ( v7 == nullptr || (v7[28] & 0x40) == 0 )
      return 0;
    v5 = pivp1;
  }
  if ( (float)((float)((float)(pNormal->k[1] * pNormal->k[1]) + (float)(pNormal->k[0] * pNormal->k[0]))
             + (float)(pNormal->k[2] * pNormal->k[2])) >= 0.000099999997 )
  {
    IVP_U_Matrix3::vimult3(
      this: &v5->physical_core->m_world_f_core_last_psi,
      p_in: pNormal,
      p_out: (IVP_U_Float_Point *)&v9);
    if ( COERCE_FLOAT(v9 & _mask__AbsFloat_) > 0.2588 )
    {
      *pFrictionOut = 0.0;
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10023A70
// Name: public: virtual struct vehicle_operatingparams_t const __near & CVehicleController::GetOperatingParams(void)
// Source: json
//------------------------------------------------------------------------------
const vehicle_operatingparams_t *__thiscall CVehicleController::GetOperatingParams(CVehicleController *this)
{
  return &this->m_currentState;
}

//------------------------------------------------------------------------------
// Address: 0x10023A80
// Name: public: virtual struct vehicleparams_t __near & CVehicleController::GetVehicleParamsForChange(void)
// Source: json
//------------------------------------------------------------------------------
vehicleparams_t *__thiscall CVehicleController::GetVehicleParamsForChange(CVehicleController *this)
{
  return &this->m_vehicleData;
}

//------------------------------------------------------------------------------
// Address: 0x10023A90
// Name: public: virtual void CVehicleController::SetEngineDisabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::SetEngineDisabled(CVehicleController *this, bool bDisable)
{
  this->m_bEngineDisable = bDisable;
}

//------------------------------------------------------------------------------
// Address: 0x10023AA0
// Name: public: virtual bool CVehicleController::IsEngineDisabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVehicleController::IsEngineDisabled(CVehicleController *this)
{
  return this->m_bEngineDisable;
}

//------------------------------------------------------------------------------
// Address: 0x10023AC0
// Name: public: virtual bool CVehicleController::GetWheelContactPoint(int,class Vector __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CVehicleController::GetWheelContactPoint@<al>(
        CVehicleController *this@<ecx>,
        int a2@<esi>,
        int index,
        Vector *pContactPoint,
        int *pSurfaceProps)
{
  bool result; // al
  int v8; // esi
  double v9; // st7
  float thisForce; // [esp+8h] [ebp-8h]
  bool bSet; // [esp+Fh] [ebp-1h]
  float forceMax; // [esp+18h] [ebp+8h]

  result = false;
  bSet = false;
  if ( index >= this->m_wheelCount )
  {
    if ( pContactPoint != nullptr )
    {
      pContactPoint->x = 0.0;
      pContactPoint->y = 0.0;
      pContactPoint->z = 0.0;
    }
    if ( pSurfaceProps != nullptr )
      *pSurfaceProps = 0;
  }
  else
  {
    v8 = ((int (__thiscall *)(CPhysicsObject *, int))this->m_pWheels[index]->CreateFrictionSnapshot)(
           a1: this->m_pWheels[index],
           a2);
    forceMax = -1.0;
    this->m_pWheels[index]->GetPosition(this: this->m_pWheels[index], a2: pContactPoint, a3: nullptr);
    while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8) != 0 )
    {
      v9 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v8 + 24))(a1: v8);
      if ( v9 > forceMax )
      {
        thisForce = v9;
        forceMax = thisForce;
        if ( pContactPoint != nullptr )
          (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v8 + 16))(a1: v8, a2: pContactPoint);
        if ( pSurfaceProps != nullptr )
          *pSurfaceProps = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 12))(a1: v8, a2: 1);
        bSet = true;
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 48))(a1: v8);
    }
    ((void (__thiscall *)(CPhysicsObject *))this->m_pWheels[index]->DestroyFrictionSnapshot)(a1: this->m_pWheels[index]);
    return bSet;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023BD0
// Name: public: virtual void CVehicleController::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::event_object_deleted(CVehicleController *this, IVP_Event_Object *pEvent)
{
  this->IVP_Listener_Object::__vftable = nullptr;
  CVehicleController::ShutdownCarSystem(this: (CVehicleController *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x10023BF0
// Name: protected: class IVP_Real_Object __near * CVehicleController::CreateWheel(int,struct vehicle_axleparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
IVP_Real_Object *__userpurge CVehicleController::CreateWheel@<eax>(
        CVehicleController *this@<ecx>,
        _BYTE *a2@<ebp>,
        int wheelIndex,
        vehicle_axleparams_t *axle)
{
  CPhysicsObject *v6; // eax
  float v7; // eax
  float v8; // xmm0_4
  CPhysicsObject *m_pCarBody; // ecx
  int v10; // xmm0_4
  int v11; // eax
  int v12; // xmm0_4
  CPhysicsEnvironment *m_pEnv; // ecx
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm1_4
  CPhysicsObject *v17; // esi
  CPhysicsObject *v18; // ecx
  CPhysicsObject_vtbl *v19; // edx
  unsigned __int16 v20; // ax
  float v21; // xmm1_4
  CPhysicsObject *v22; // edx
  float *k; // eax
  _BYTE v24[16]; // [esp+30h] [ebp-CCh] BYREF
  matrix3x4_t matrix; // [esp+40h] [ebp-BCh] BYREF
  Vector bodyPosition; // [esp+70h] [ebp-8Ch]
  IVP_U_Point wheelPositionBs; // [esp+7Ch] [ebp-80h] BYREF
  IVP_U_Point wheelPositionIVP; // [esp+8Ch] [ebp-70h] BYREF
  _BYTE v29[60]; // [esp+A4h] [ebp-58h] OVERLAPPED BYREF
  Vector wheelPositionHL; // [esp+E0h] [ebp-1Ch] BYREF
  _BYTE *v31; // [esp+ECh] [ebp-10h]
  Vector position; // [esp+F0h] [ebp-Ch]
  int retaddr; // [esp+FCh] [ebp+0h]

  v31 = a2;
  position.x = position.z;
  if ( retaddr >= 8 )
    return nullptr;
  v6 = this->m_pWheels[retaddr];
  if ( v6 != nullptr )
    return v6->m_pObject;
  memset(dst: v29, value: 0, count: 0x2Cu);
  this->m_pCarBody->GetPosition(
    this: this->m_pCarBody,
    a2: (Vector *)matrix.m_flMatVal[2],
    a3: (QAngle *)&wheelPositionIVP.hesse_val);
  AngleMatrix(
    angles: (const QAngle *)&wheelPositionIVP.hesse_val,
    position: (const Vector *)matrix.m_flMatVal[2],
    matrix: (matrix3x4_t *)v24);
  v7 = *(float *)(wheelIndex + 8);
  *(_QWORD *)&wheelPositionHL.x = *(_QWORD *)wheelIndex;
  wheelPositionHL.z = v7;
  if ( (retaddr & 1) != 0 )
  {
    wheelPositionHL.x = *(float *)(wheelIndex + 12) + wheelPositionHL.x;
    wheelPositionHL.y = *(float *)(wheelIndex + 16) + wheelPositionHL.y;
    v8 = *(float *)(wheelIndex + 20) + wheelPositionHL.z;
  }
  else
  {
    wheelPositionHL.x = wheelPositionHL.x - *(float *)(wheelIndex + 12);
    wheelPositionHL.y = wheelPositionHL.y - *(float *)(wheelIndex + 16);
    v8 = wheelPositionHL.z - *(float *)(wheelIndex + 20);
  }
  VectorTransform(in1: &wheelPositionHL.x, in2: (const matrix3x4_t *)v24, out: (float *)LODWORD(v8));
  m_pCarBody = this->m_pCarBody;
  *(_DWORD *)&v29[12] = *(_DWORD *)(wheelIndex + 60);
  *(_DWORD *)&v29[36] = 0;
  *(_DWORD *)&v29[8] = *(_DWORD *)(wheelIndex + 56);
  v10 = *(_DWORD *)(wheelIndex + 52);
  v29[40] = 0;
  *(_DWORD *)&v29[4] = v10;
  v11 = ((int (__thiscall *)(CPhysicsObject *, _BYTE *, _DWORD, _DWORD, _DWORD))m_pCarBody->GetGameData)(
          a1: m_pCarBody,
          a2: v31,
          a3: LODWORD(position.x),
          a4: LODWORD(position.y),
          a5: LODWORD(position.z));
  v12 = *(_DWORD *)(wheelIndex + 64);
  m_pEnv = this->m_pEnv;
  *(_DWORD *)&v29[28] = v11;
  position.z = 0.0;
  *(_DWORD *)&v29[16] = v12;
  LODWORD(position.y) = v29;
  *(_DWORD *)&v29[20] = 0;
  v14 = *(float *)(wheelIndex + 48);
  LODWORD(position.x) = &wheelPositionIVP.hesse_val;
  v31 = &v29[44];
  v15 = *(_DWORD *)(wheelIndex + 72);
  v16 = (float)((float)(v14 * v14) * v14) * 3.141592653589793;
  *(_DWORD *)&v29[24] = "VehicleWheel";
  *(_DWORD *)v29 = 0;
  *(float *)&v29[32] = v16;
  v17 = (CPhysicsObject *)((int (__cdecl *)(float, int, _BYTE *, float *, _BYTE *, _DWORD))m_pEnv->CreateSphereObject)(
                            a1: COERCE_FLOAT(LODWORD(v14)),
                            a2: v15,
                            a3: &v29[44],
                            a4: &wheelPositionIVP.hesse_val,
                            a5: v29,
                            a6: 0);
  v17->Wake(this: v17);
  v17->SetCallbackFlags(this: v17, a2: 0);
  v18 = this->m_pCarBody;
  v19 = v18->__vftable;
  *(_DWORD *)&v29[56] = v17->__vftable;
  v20 = v19->GetGameFlags(this: v18);
  (*(void (__thiscall **)(CPhysicsObject *, _DWORD))(*(_DWORD *)&v29[56] + 72))(a1: v17, a2: v20);
  v21 = *(float *)&v29[44];
  this->m_pWheels[retaddr] = v17;
  wheelPositionBs.k[0] = v21 * g_PhysicsUnits.unitScaleMeters;
  v22 = this->m_pCarBody;
  LODWORD(wheelPositionBs.k[1]) = COERCE_UNSIGNED_INT(*(float *)&v29[52] * g_PhysicsUnits.unitScaleMeters)
                                ^ _mask__NegFloat_;
  wheelPositionBs.k[2] = *(float *)&v29[48] * g_PhysicsUnits.unitScaleMeters;
  TransformIVPToLocal(
    pointIn: &wheelPositionBs,
    pointOut: (IVP_U_Point *)&matrix.m_flMatVal[2][3],
    pObject: v22->m_pObject,
    translate: true);
  k = this->m_wheelPosition_Bs[retaddr].k;
  *k = matrix.m_flMatVal[2][3];
  k[1] = bodyPosition.x;
  k[2] = bodyPosition.y;
  v17->m_callbacks |= 0x40u;
  return v17->m_pObject;
}

//------------------------------------------------------------------------------
// Address: 0x10023E70
// Name: protected: void CVehicleController::CreateTraceData(int,struct vehicle_axleparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVehicleController::CreateTraceData(
        CVehicleController *this@<ecx>,
        float a2@<ebp>,
        int wheelIndex,
        vehicle_axleparams_t *axle)
{
  float z; // ecx
  float v6; // xmm0_4
  CPhysicsObject *m_pCarBody; // edx
  IVP_U_Float_Point *v8; // eax
  _BYTE v9[12]; // [esp-Ch] [ebp-8Ch] BYREF
  matrix3x4_t matrix; // [esp+0h] [ebp-80h] BYREF
  IVP_U_Point tracePositionBs; // [esp+30h] [ebp-50h] BYREF
  IVP_U_Point tracePositionIVP; // [esp+40h] [ebp-40h] BYREF
  QAngle bodyAngles; // [esp+50h] [ebp-30h] BYREF
  Vector bodyPosition; // [esp+5Ch] [ebp-24h] BYREF
  Vector tracePositionHL; // [esp+68h] [ebp-18h] BYREF
  Vector tracePosition; // [esp+74h] [ebp-Ch]
  float retaddr; // [esp+80h] [ebp+0h]

  tracePosition.x = a2;
  tracePosition.y = retaddr;
  if ( wheelIndex < 8 )
  {
    this->m_pCarBody->GetPosition(
      this: this->m_pCarBody,
      a2: (Vector *)&bodyAngles,
      a3: (QAngle *)&tracePositionIVP.k[1]);
    AngleMatrix(
      angles: (const QAngle *)&tracePositionIVP.k[1],
      position: (const Vector *)&bodyAngles,
      matrix: (matrix3x4_t *)v9);
    z = axle->raytraceCenterOffset.z;
    *(_QWORD *)&tracePositionHL.x = *(_QWORD *)&axle->raytraceCenterOffset.x;
    tracePositionHL.z = z;
    if ( (wheelIndex & 1) != 0 )
    {
      tracePositionHL.x = axle->raytraceOffset.x + tracePositionHL.x;
      tracePositionHL.y = axle->raytraceOffset.y + tracePositionHL.y;
      v6 = axle->raytraceOffset.z + tracePositionHL.z;
    }
    else
    {
      tracePositionHL.x = tracePositionHL.x - axle->raytraceOffset.x;
      tracePositionHL.y = tracePositionHL.y - axle->raytraceOffset.y;
      v6 = tracePositionHL.z - axle->raytraceOffset.z;
    }
    tracePositionHL.z = v6;
    VectorTransform(in1: &tracePositionHL.x, in2: (const matrix3x4_t *)v9, out: &bodyPosition.x);
    m_pCarBody = this->m_pCarBody;
    tracePositionBs.k[1] = bodyPosition.x * g_PhysicsUnits.unitScaleMeters;
    LODWORD(tracePositionBs.k[2]) = COERCE_UNSIGNED_INT(bodyPosition.z * g_PhysicsUnits.unitScaleMeters)
                                  ^ _mask__NegFloat_;
    tracePositionBs.hesse_val = bodyPosition.y * g_PhysicsUnits.unitScaleMeters;
    TransformIVPToLocal(
      pointIn: (IVP_U_Point *)&tracePositionBs.k[1],
      pointOut: (IVP_U_Point *)&matrix.m_flMatVal[2][1],
      pObject: m_pCarBody->m_pObject,
      translate: true);
    v8 = &this->m_tracePosition_Bs[wheelIndex];
    *(_QWORD *)v8->k = *(_QWORD *)&matrix.m_flMatVal[2][1];
    v8->k[2] = matrix.m_flMatVal[2][3];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023FD0
// Name: public: virtual void CVehicleController::VehicleDataReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::VehicleDataReload(CVehicleController *this)
{
  bool v1; // cc
  float v2; // xmm0_4
  int axleCount; // edx
  float *p_torqueFactor; // eax

  v1 = this->m_vehicleData.axleCount <= 0;
  this->m_torqueScale = 1.0;
  v2 = 0.0;
  if ( !v1 )
  {
    axleCount = this->m_vehicleData.axleCount;
    p_torqueFactor = &this->m_vehicleData.axles[0].torqueFactor;
    do
    {
      v2 = v2 + *p_torqueFactor;
      p_torqueFactor += 29;
      --axleCount;
    }
    while ( axleCount != 0 );
    if ( v2 > 0.0 )
      this->m_torqueScale = 1.0 / v2;
  }
  this->m_vehicleData.engine.maxSpeed = (float)(this->m_vehicleData.engine.maxSpeed * 0.44707)
                                      * g_PhysicsUnits.unitScaleMetersInv;
  this->m_vehicleData.engine.maxRevSpeed = (float)(this->m_vehicleData.engine.maxRevSpeed * 0.44707)
                                         * g_PhysicsUnits.unitScaleMetersInv;
  this->m_vehicleData.engine.boostMaxSpeed = (float)(this->m_vehicleData.engine.boostMaxSpeed * 0.44707)
                                           * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10024070
// Name: protected: void CVehicleController::InitCarSystemWheels(class IVP_Template_Car_System __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::InitCarSystemWheels(
        CVehicleController *this,
        IVP_Template_Car_System *ivpVehicleData)
{
  int v3; // ecx
  IVP_Template_Car_System *v4; // edi
  float *wheel_max_rotation_speed; // eax
  float *p_stabilizerConstant; // ebx
  int v7; // edi
  IVP_Real_Object *v8; // eax
  double upper_limit_radius; // st7
  IVP_U_Float_Point *v10; // eax
  _QWORD *v11; // ecx
  float boostMaxSpeed; // xmm1_4
  float v13; // xmm0_4
  int v14; // edi
  CPhysicsObject **m_pWheels; // ebx
  IVP_Real_Object *pWheel; // [esp+0h] [ebp-1Ch]
  float *v17; // [esp+4h] [ebp-18h]
  int i; // [esp+8h] [ebp-14h]
  int w; // [esp+Ch] [ebp-10h]
  _QWORD *k; // [esp+10h] [ebp-Ch]
  IVP_U_Float_Point *v21; // [esp+14h] [ebp-8h]
  int wheelIndex; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = 0;
  wheelIndex = 0;
  this->m_wheelRadius = 0.0;
  this->m_totalWheelMass = 0.0;
  i = 0;
  if ( this->m_vehicleData.axleCount > 0 )
  {
    v4 = ivpVehicleData;
    wheel_max_rotation_speed = ivpVehicleData->wheel_max_rotation_speed;
    v17 = ivpVehicleData->wheel_max_rotation_speed;
    p_stabilizerConstant = &this->m_vehicleData.axles[0].suspension.stabilizerConstant;
    do
    {
      w = 0;
      if ( this->m_vehicleData.wheelsPerAxle > 0 )
      {
        k = (_QWORD *)v4->trace_pos_Bos[v3].k;
        v21 = &this->m_tracePosition_Bs[v3];
        v7 = (int)&v4->wheel_radius[v3];
        do
        {
          v8 = CVehicleController::CreateWheel(
                 this,
                 a2: &savedregs,
                 wheelIndex: v3,
                 axle: (vehicle_axleparams_t *)(p_stabilizerConstant - 24));
          pWheel = v8;
          if ( v8 != nullptr )
          {
            if ( this->m_bTraceData )
            {
              CVehicleController::CreateTraceData(
                this,
                a2: COERCE_FLOAT(&savedregs),
                wheelIndex,
                axle: (vehicle_axleparams_t *)(p_stabilizerConstant - 24));
              v8 = pWheel;
            }
            *(_DWORD *)(v7 - 80) = v8;
            upper_limit_radius = v8->physical_core->upper_limit_radius;
            *(_DWORD *)(v7 + 40) = 1065353216;
            *(float *)v7 = upper_limit_radius;
            v10 = v21;
            v11 = k;
            *(float *)(v7 - 40) = *(p_stabilizerConstant - 7);
            *(float *)(v7 + 420) = *(p_stabilizerConstant - 2) * this->m_bodyMass;
            *(float *)(v7 + 460) = *(p_stabilizerConstant - 1) * this->m_bodyMass;
            *(float *)(v7 + 500) = p_stabilizerConstant[1] * this->m_bodyMass;
            *(float *)(v7 + 540) = p_stabilizerConstant[2] * this->m_bodyMass;
            *(float *)(v7 + 580) = -(float)(*(p_stabilizerConstant - 3) * g_PhysicsUnits.unitScaleMeters);
            *(k - 20) = *(_QWORD *)v21[-8].k;
            *(k - 19) = *(_QWORD *)&v21[-8].k[2];
            if ( this->m_bTraceData )
            {
              *k = *(_QWORD *)v21->k;
              k[1] = *(_QWORD *)&v21->k[2];
            }
            this->m_totalWheelMass = *(p_stabilizerConstant - 11) + this->m_totalWheelMass;
          }
          else
          {
            v10 = v21;
            v11 = k;
          }
          ++w;
          ++wheelIndex;
          v7 += 4;
          k = v11 + 2;
          v3 = wheelIndex;
          v21 = v10 + 1;
        }
        while ( w < this->m_vehicleData.wheelsPerAxle );
        v4 = ivpVehicleData;
        wheel_max_rotation_speed = v17;
      }
      *(wheel_max_rotation_speed - 5) = this->m_bodyMass * *p_stabilizerConstant;
      boostMaxSpeed = this->m_vehicleData.engine.boostMaxSpeed;
      v13 = *(p_stabilizerConstant - 12) * g_PhysicsUnits.unitScaleMeters;
      if ( boostMaxSpeed <= this->m_vehicleData.engine.maxSpeed )
        boostMaxSpeed = this->m_vehicleData.engine.maxSpeed;
      *wheel_max_rotation_speed = boostMaxSpeed / v13;
      if ( v13 > this->m_wheelRadius )
        this->m_wheelRadius = v13;
      ++wheel_max_rotation_speed;
      p_stabilizerConstant += 29;
      ++i;
      v17 = wheel_max_rotation_speed;
    }
    while ( i < this->m_vehicleData.axleCount );
  }
  v14 = 0;
  if ( this->m_wheelCount > 0 )
  {
    m_pWheels = this->m_pWheels;
    do
    {
      (*m_pWheels)->EnableCollisions(this: *m_pWheels, a2: true);
      ++v14;
      ++m_pWheels;
    }
    while ( v14 < this->m_wheelCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100242C0
// Name: public: struct vehicle_axleparams_t __near & vehicle_axleparams_t::operator=(struct vehicle_axleparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
vehicle_axleparams_t *__thiscall vehicle_axleparams_t::operator=(
        vehicle_axleparams_t *this,
        const vehicle_axleparams_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024370
// Name: protected: void CVehicleController::UpdateHandbrake(struct vehicle_controlparams_t const __near &,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::UpdateHandbrake(
        CVehicleController *this,
        const vehicle_controlparams_t *controls,
        float flThrottle,
        bool bHandbrake,
        bool bPowerslide)
{
  float v6; // xmm0_4
  int v7; // edi
  CPhysicsObject **m_pWheels; // ebx
  int m_vehicleFlags; // eax
  int v10; // eax
  IVP_POS_WHEEL v11; // edi
  float v12; // [esp+Ch] [ebp-4h]

  v12 = this->m_pCarSystem->get_body_speed(this: this->m_pCarSystem, a2: IVP_INDEX_Z);
  v6 = g_PhysicsUnits.unitScaleMetersInv * v12;
  this->m_currentState.speed = g_PhysicsUnits.unitScaleMetersInv * v12;
  if ( !bPowerslide && (flThrottle < 0.0 && v6 > 5.0 || flThrottle > 0.0 && v6 < -5.0) || bHandbrake )
  {
    v7 = 0;
    bHandbrake = false;
    if ( this->m_wheelCount > 0 )
    {
      m_pWheels = this->m_pWheels;
      while ( !(*m_pWheels)->GetContactPoint(this: *m_pWheels, a2: nullptr, a3: nullptr) )
      {
        ++v7;
        ++m_pWheels;
        if ( v7 >= this->m_wheelCount )
          goto LABEL_13;
      }
      bHandbrake = true;
    }
  }
LABEL_13:
  m_vehicleFlags = this->m_vehicleFlags;
  if ( bHandbrake != ((m_vehicleFlags & 2) != 0) )
  {
    if ( bHandbrake )
      v10 = m_vehicleFlags | 2;
    else
      v10 = m_vehicleFlags & 0xFFFFFFFD;
    v11 = IVP_FRONT_LEFT;
    for ( this->m_vehicleFlags = v10; v11 < this->m_wheelCount; ++v11 )
      this->m_pCarSystem->fix_wheel(this: this->m_pCarSystem, a2: v11, a3: (IVP_BOOL)bHandbrake);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024460
// Name: protected: void CVehicleController::UpdateSkidding(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVehicleController::UpdateSkidding(CVehicleController *this@<ecx>, int a2@<ebp>, bool bHandbrake)
{
  int m_wheelCount; // eax
  float x; // xmm0_4
  int v6; // edi
  float skidSpeed; // xmm0_4
  int y_low; // eax
  float v9; // [esp-24h] [ebp-4Ch]
  _BYTE v10[12]; // [esp-Ch] [ebp-34h] BYREF
  Vector contact; // [esp+0h] [ebp-28h] BYREF
  Vector velocity; // [esp+Ch] [ebp-1Ch] BYREF
  CPhysicsObject **flAbsSpeed; // [esp+18h] [ebp-10h]
  int surfaceProps; // [esp+1Ch] [ebp-Ch]
  void *v15; // [esp+20h] [ebp-8h]
  void *retaddr; // [esp+28h] [ebp+0h]

  surfaceProps = a2;
  v15 = retaddr;
  m_wheelCount = this->m_wheelCount;
  this->m_currentState.skidSpeed = 0.0;
  this->m_currentState.skidMaterial = 0;
  this->m_currentState.wheelsInContact = m_wheelCount;
  this->m_currentState.wheelsNotInContact = 0;
  if ( this->m_vehicleData.steering.isSkidAllowed )
  {
    LODWORD(x) = LODWORD(this->m_currentState.speed) & _mask__AbsFloat_;
    v6 = 0;
    velocity.x = x;
    this->m_currentState.wheelsInContact = 0;
    this->m_currentState.wheelsNotInContact = 0;
    if ( m_wheelCount > 0 )
    {
      flAbsSpeed = this->m_pWheels;
      do
      {
        if ( this->GetWheelContactPoint(this, a2: v6, a3: (Vector *)v10, a4: (int *)&velocity.y) )
        {
          (*flAbsSpeed)->GetVelocityAtPoint(this: *flAbsSpeed, a2: (const Vector *)v10, a3: &contact);
          velocity.z = contact.x * contact.x;
          v9 = fsqrt(
                 (float)((float)(contact.x * contact.x) + (float)(contact.y * contact.y))
               + (float)(contact.z * contact.z));
          skidSpeed = this->m_currentState.skidSpeed;
          if ( v9 > skidSpeed || skidSpeed <= 0.0 )
          {
            y_low = LODWORD(velocity.y);
            this->m_currentState.skidSpeed = v9;
            this->m_currentState.skidMaterial = y_low;
          }
          ++this->m_currentState.wheelsInContact;
        }
        else
        {
          ++this->m_currentState.wheelsNotInContact;
        }
        ++flAbsSpeed;
        ++v6;
      }
      while ( v6 < this->m_wheelCount );
      x = velocity.x;
    }
    if ( bHandbrake && x > 30.0 )
      this->m_currentState.skidSpeed = x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100245D0
// Name: protected: void CVehicleController::UpdateExtraForces(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CVehicleController::UpdateExtraForces(
        CVehicleController *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CPhysicsObject *m_pCarBody; // eax
  IVP_Real_Object *m_pObject; // edi
  IVP_Cache_Object *cache_object; // ecx
  IVP_Cache_Object *v8; // edi
  float v9; // xmm0_4
  CPhysicsObject *v10; // ecx
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // edx
  float maxAngularVelocity; // xmm1_4
  float v13; // xmm0_4
  CPhysicsObject *v14; // esi
  int v17; // [esp+Ch] [ebp-34h]
  int v18; // [esp+10h] [ebp-30h]
  int v19; // [esp+14h] [ebp-2Ch]
  int v20; // [esp+18h] [ebp-28h]
  int v21; // [esp+1Ch] [ebp-24h]
  int v22; // [esp+20h] [ebp-20h]
  Vector v23; // [esp+24h] [ebp-1Ch] BYREF
  Vector angVel; // [esp+30h] [ebp-10h]
  float retaddr; // [esp+40h] [ebp+0h]

  angVel.y = a2;
  angVel.z = retaddr;
  m_pCarBody = this->m_pCarBody;
  m_pObject = m_pCarBody->m_pObject;
  if ( m_pObject->cache_object == nullptr )
    m_pObject->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                                this: m_pObject->environment->cache_object_manager,
                                object: m_pCarBody->m_pObject);
  ++m_pObject->cache_object->reference_count;
  if ( *(_BYTE *)&m_pObject->flags < 8 )
  {
    cache_object = m_pObject->cache_object;
    if ( m_pObject->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v8 = m_pObject->cache_object;
  if ( fabs(v8->m_world_f_object.rows[1].k[1]) >= 0.05 )
    v9 = 0.0;
  else
    v9 = (float)(this->m_gravityLength * this->m_vehicleData.body.tiltForce) * this->m_bodyMass;
  ((void (__stdcall *)(_DWORD, int, int, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pCarSystem->change_body_downforce)(
    a1: LODWORD(v9),
    a2: a3,
    a3: a4,
    a4: v17,
    a5: v18,
    a6: v19,
    a7: v20,
    a8: v21,
    a9: v22,
    a10: LODWORD(v23.x),
    a11: LODWORD(v23.y),
    a12: LODWORD(v23.z),
    a13: LODWORD(angVel.x));
  --v8->reference_count;
  if ( this->m_nVehicleType == 1 )
    this->m_pCarSystem->update_body_countertorque(this: this->m_pCarSystem);
  v10 = this->m_pCarBody;
  GetVelocity = v10->GetVelocity;
  LODWORD(angVel.x) = &v23;
  ((void (__thiscall *)(CPhysicsObject *, _DWORD))GetVelocity)(a1: v10, a2: 0);
  maxAngularVelocity = this->m_vehicleData.body.maxAngularVelocity;
  if ( maxAngularVelocity > 0.0 )
  {
    angVel.x = v23.y * v23.y;
    if ( fsqrt((float)((float)(v23.y * v23.y) + (float)(v23.x * v23.x)) + (float)(v23.z * v23.z)) > maxAngularVelocity )
    {
      VectorNormalize(vec: &v23);
      v13 = this->m_vehicleData.body.maxAngularVelocity;
      v14 = this->m_pCarBody;
      v23.x = v13 * v23.x;
      v23.y = v23.y * v13;
      v23.z = v23.z * v13;
      v14->SetVelocityInstantaneous(this: v14, a2: nullptr, a3: &v23);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024760
// Name: public: void CVehicleController::WriteToTemplate(struct vphysics_save_cvehiclecontroller_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::WriteToTemplate(
        CVehicleController *this,
        vphysics_save_cvehiclecontroller_t *controllerTemplate)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  CPhysicsObject *v6; // ecx
  float v7; // xmm3_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  CPhysicsObject *v12; // ecx
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  CPhysicsObject *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  CPhysicsObject *v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm1_4
  CPhysicsObject *v26; // ecx
  float v27; // xmm1_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  CPhysicsObject *v30; // ecx
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm1_4
  CPhysicsObject *v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm1_4
  float v39; // xmm1_4
  float v40; // xmm1_4

  this->m_vehicleFlags &= ~2u;
  controllerTemplate->m_pCarBody = this->m_pCarBody;
  controllerTemplate->m_wheelCount = this->m_wheelCount;
  controllerTemplate->m_wheelRadius = this->m_wheelRadius;
  controllerTemplate->m_bodyMass = this->m_bodyMass;
  controllerTemplate->m_totalWheelMass = this->m_totalWheelMass;
  controllerTemplate->m_gravityLength = this->m_gravityLength;
  controllerTemplate->m_torqueScale = this->m_torqueScale;
  controllerTemplate->m_vehicleFlags = this->m_vehicleFlags;
  controllerTemplate->m_nTireType = this->m_nTireType;
  controllerTemplate->m_nVehicleType = this->m_nVehicleType;
  controllerTemplate->m_bTraceData = this->m_bTraceData;
  controllerTemplate->m_bOccupied = this->m_bOccupied;
  controllerTemplate->m_bEngineDisable = this->m_bEngineDisable;
  controllerTemplate->m_currentState = this->m_currentState;
  qmemcpy((void *)&controllerTemplate->m_vehicleData, &this->m_vehicleData, sizeof(controllerTemplate->m_vehicleData));
  v3 = this->m_wheelPosition_Bs[0].k[1];
  v4 = this->m_wheelPosition_Bs[0].k[2];
  controllerTemplate->m_pWheels[0] = this->m_pWheels[0];
  v5 = v3 * g_PhysicsUnits.unitScaleMetersInv;
  v6 = this->m_pWheels[1];
  controllerTemplate->m_wheelPosition_Bs[0].y = v4 * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_wheelPosition_Bs[0].z = -v5;
  controllerTemplate->m_wheelPosition_Bs[0].x = this->m_wheelPosition_Bs[0].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v7 = this->m_tracePosition_Bs[0].k[1] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[0].y = this->m_tracePosition_Bs[0].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[0].z = -v7;
  controllerTemplate->m_tracePosition_Bs[0].x = this->m_tracePosition_Bs[0].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v8 = this->m_wheelPosition_Bs[1].k[1];
  v9 = this->m_wheelPosition_Bs[1].k[2];
  controllerTemplate->m_pWheels[1] = v6;
  v10 = v9 * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_wheelPosition_Bs[1].z = -(float)(v8 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[1].y = v10;
  controllerTemplate->m_wheelPosition_Bs[1].x = this->m_wheelPosition_Bs[1].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v11 = this->m_tracePosition_Bs[1].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  v12 = this->m_pWheels[2];
  controllerTemplate->m_tracePosition_Bs[1].z = -(float)(this->m_tracePosition_Bs[1].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[1].y = v11;
  controllerTemplate->m_tracePosition_Bs[1].x = this->m_tracePosition_Bs[1].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v13 = this->m_wheelPosition_Bs[2].k[1];
  v14 = this->m_wheelPosition_Bs[2].k[2];
  controllerTemplate->m_pWheels[2] = v12;
  v15 = v14 * g_PhysicsUnits.unitScaleMetersInv;
  v16 = this->m_pWheels[3];
  controllerTemplate->m_wheelPosition_Bs[2].z = -(float)(v13 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[2].y = v15;
  controllerTemplate->m_wheelPosition_Bs[2].x = this->m_wheelPosition_Bs[2].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v17 = this->m_tracePosition_Bs[2].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[2].z = -(float)(this->m_tracePosition_Bs[2].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[2].y = v17;
  controllerTemplate->m_tracePosition_Bs[2].x = this->m_tracePosition_Bs[2].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v18 = this->m_wheelPosition_Bs[3].k[1];
  v19 = this->m_wheelPosition_Bs[3].k[2];
  controllerTemplate->m_pWheels[3] = v16;
  v20 = v19 * g_PhysicsUnits.unitScaleMetersInv;
  v21 = this->m_pWheels[4];
  controllerTemplate->m_wheelPosition_Bs[3].z = -(float)(v18 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[3].y = v20;
  controllerTemplate->m_wheelPosition_Bs[3].x = this->m_wheelPosition_Bs[3].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v22 = this->m_tracePosition_Bs[3].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[3].z = -(float)(this->m_tracePosition_Bs[3].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[3].y = v22;
  controllerTemplate->m_tracePosition_Bs[3].x = this->m_tracePosition_Bs[3].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v23 = this->m_wheelPosition_Bs[4].k[1];
  v24 = this->m_wheelPosition_Bs[4].k[2];
  controllerTemplate->m_pWheels[4] = v21;
  v25 = v24 * g_PhysicsUnits.unitScaleMetersInv;
  v26 = this->m_pWheels[5];
  controllerTemplate->m_wheelPosition_Bs[4].z = -(float)(v23 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[4].y = v25;
  controllerTemplate->m_wheelPosition_Bs[4].x = this->m_wheelPosition_Bs[4].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v27 = this->m_tracePosition_Bs[4].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[4].z = -(float)(this->m_tracePosition_Bs[4].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[4].y = v27;
  controllerTemplate->m_tracePosition_Bs[4].x = this->m_tracePosition_Bs[4].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v28 = this->m_wheelPosition_Bs[5].k[2];
  controllerTemplate->m_pWheels[5] = v26;
  v29 = v28 * g_PhysicsUnits.unitScaleMetersInv;
  v30 = this->m_pWheels[6];
  controllerTemplate->m_wheelPosition_Bs[5].z = -(float)(this->m_wheelPosition_Bs[5].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[5].y = v29;
  controllerTemplate->m_wheelPosition_Bs[5].x = this->m_wheelPosition_Bs[5].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v31 = this->m_tracePosition_Bs[5].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[5].z = -(float)(this->m_tracePosition_Bs[5].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[5].y = v31;
  controllerTemplate->m_tracePosition_Bs[5].x = this->m_tracePosition_Bs[5].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v32 = this->m_wheelPosition_Bs[6].k[1];
  v33 = this->m_wheelPosition_Bs[6].k[2];
  controllerTemplate->m_pWheels[6] = v30;
  v34 = v33 * g_PhysicsUnits.unitScaleMetersInv;
  v35 = this->m_pWheels[7];
  controllerTemplate->m_wheelPosition_Bs[6].z = -(float)(v32 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[6].y = v34;
  controllerTemplate->m_wheelPosition_Bs[6].x = this->m_wheelPosition_Bs[6].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v36 = this->m_tracePosition_Bs[6].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[6].z = -(float)(this->m_tracePosition_Bs[6].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[6].y = v36;
  controllerTemplate->m_tracePosition_Bs[6].x = this->m_tracePosition_Bs[6].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v37 = this->m_wheelPosition_Bs[7].k[1];
  v38 = this->m_wheelPosition_Bs[7].k[2];
  controllerTemplate->m_pWheels[7] = v35;
  v39 = v38 * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_wheelPosition_Bs[7].z = -(float)(v37 * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_wheelPosition_Bs[7].y = v39;
  controllerTemplate->m_wheelPosition_Bs[7].x = this->m_wheelPosition_Bs[7].k[0] * g_PhysicsUnits.unitScaleMetersInv;
  v40 = this->m_tracePosition_Bs[7].k[2] * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->m_tracePosition_Bs[7].z = -(float)(this->m_tracePosition_Bs[7].k[1]
                                                       * g_PhysicsUnits.unitScaleMetersInv);
  controllerTemplate->m_tracePosition_Bs[7].y = v40;
  controllerTemplate->m_tracePosition_Bs[7].x = this->m_tracePosition_Bs[7].k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10024DD0
// Name: protected: void CVehicleController::CreateIVPObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVehicleController::CreateIVPObjects(CVehicleController *this@<ecx>, float a2@<ebp>)
{
  IVP_Real_Object *m_pObject; // eax
  CPhysics_Airboat *v4; // eax
  IVP_Car_System_Real_Wheels *v5; // eax
  CPhysics_Car_System_Raycast_Wheels *v6; // eax
  IVP_Car_System_Real_Wheels *v7; // eax
  _DWORD v8[3]; // [esp-Ch] [ebp-31Ch] BYREF
  IVP_Template_Car_System ivpVehicleData; // [esp+0h] [ebp-310h]
  float retaddr; // [esp+310h] [ebp+0h]

  ivpVehicleData.wheel_max_rotation_speed[5] = a2;
  ivpVehicleData.wheel_max_rotation_speed[6] = retaddr;
  IVP_Template_Car_System::IVP_Template_Car_System(
    this: (IVP_Template_Car_System *)v8,
    n_wheels_: this->m_wheelCount,
    n_axis_: this->m_vehicleData.axleCount);
  m_pObject = this->m_pCarBody->m_pObject;
  ivpVehicleData.wheel_reversed_sign[7] = this->m_vehicleData.body.counterTorqueFactor;
  ivpVehicleData.body_counter_torque_factor = this->m_vehicleData.body.tiltForceHeight * g_PhysicsUnits.unitScaleMeters;
  ivpVehicleData.wheel_reversed_sign[8] = (float)(this->m_gravityLength * this->m_vehicleData.body.addGravity)
                                        * this->m_bodyMass;
  ivpVehicleData.index_y = (IVP_COORDINATE_INDEX)m_pObject;
  v8[2] = 0;
  ivpVehicleData.n_wheels = 1;
  ivpVehicleData.n_axis = 2;
  ivpVehicleData.wheel_reversed_sign[9] = 0.0;
  CVehicleController::InitCarSystemWheels(this, ivpVehicleData: (IVP_Template_Car_System *)v8);
  switch ( this->m_nVehicleType )
  {
    case 1u:
      v7 = (IVP_Car_System_Real_Wheels *)p_malloc(size: 0x360u);
      if ( v7 != nullptr )
      {
        v5 = IVP_Car_System_Real_Wheels::IVP_Car_System_Real_Wheels(
               this: v7,
               env: this->m_pEnv->m_pPhysEnv,
               templ: (IVP_Template_Car_System *)v8);
        goto LABEL_11;
      }
      goto LABEL_10;
    case 2u:
      v6 = (CPhysics_Car_System_Raycast_Wheels *)p_malloc(size: 0x980u);
      if ( v6 != nullptr )
      {
        v5 = (IVP_Car_System_Real_Wheels *)CPhysics_Car_System_Raycast_Wheels::CPhysics_Car_System_Raycast_Wheels(
                                             this: v6,
                                             pEnv: this->m_pEnv->m_pPhysEnv,
                                             pCarSystem: (const IVP_Template_Car_System *)v8);
        goto LABEL_11;
      }
LABEL_10:
      v5 = nullptr;
      goto LABEL_11;
    case 8u:
      v4 = (CPhysics_Airboat *)p_malloc(size: 0x5D0u);
      if ( v4 != nullptr )
      {
        v5 = (IVP_Car_System_Real_Wheels *)CPhysics_Airboat::CPhysics_Airboat(
                                             this: v4,
                                             pEnv: this->m_pEnv->m_pPhysEnv,
                                             pCarSystem: (const IVP_Template_Car_System *)v8,
                                             pGameTrace: this->m_pGameTrace);
LABEL_11:
        this->m_pCarSystem = v5;
        break;
      }
      goto LABEL_10;
    default:
      break;
  }
  IVP_Real_Object::add_listener_object(this: this->m_pCarBody->m_pObject, listener: &this->IVP_Listener_Object);
}

//------------------------------------------------------------------------------
// Address: 0x10024F40
// Name: public: void CVehicleController::InitCarSystem(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::InitCarSystem(CVehicleController *this, int pBodyObject)
{
  int v3; // ecx
  CPhysicsObject *m_pCarBody; // ecx
  float flDampSpeed; // [esp+4h] [ebp-4h] BYREF
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( this->m_pCarSystem != nullptr )
    CVehicleController::ShutdownCarSystem(this);
  v3 = pBodyObject;
  this->m_pCarBody = (CPhysicsObject *)pBodyObject;
  this->m_bodyMass = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 116))(a1: v3);
  this->m_gravityLength = IVP_U_Float_Point::fast_real_length(this: &this->m_pEnv->m_pPhysEnv->gravity);
  this->m_wheelCount = this->m_vehicleData.axleCount * this->m_vehicleData.wheelsPerAxle;
  CVehicleController::CreateIVPObjects(this, a2: COERCE_FLOAT(&savedregs));
  if ( this->m_nVehicleType == 8 )
  {
    m_pCarBody = this->m_pCarBody;
    flDampSpeed = 1.0;
    pBodyObject = 1065353216;
    m_pCarBody->SetDamping(this: m_pCarBody, a2: &flDampSpeed, a3: (const float *)&pBodyObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024FD0
// Name: public: struct vehicleparams_t __near & vehicleparams_t::operator=(struct vehicleparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
vehicleparams_t *__thiscall vehicleparams_t::operator=(vehicleparams_t *this, const vehicleparams_t *__that)
{
  int v3; // eax
  vehicle_axleparams_t *axles; // edi
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  this->axleCount = __that->axleCount;
  this->wheelsPerAxle = __that->wheelsPerAxle;
  this->body = __that->body;
  v3 = (char *)__that - (char *)this;
  axles = this->axles;
  v6 = (char *)__that - (char *)this;
  v7 = 4;
  while ( 1 )
  {
    vehicle_axleparams_t::operator=(this: axles, __that: (vehicle_axleparams_t *)((char *)axles + v3));
    ++axles;
    if ( --v7 == 0 )
      break;
    v3 = v6;
  }
  qmemcpy(&this->engine, &__that->engine, sizeof(this->engine));
  qmemcpy(&this->steering, &__that->steering, sizeof(this->steering));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025080
// Name: protected: void CVehicleController::UpdatePowerslide(struct vehicle_controlparams_t const __near &,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::UpdatePowerslide(
        CVehicleController *this,
        const vehicle_controlparams_t *controls,
        bool bPowerslide,
        float flSpeed)
{
  bool v5; // zf
  unsigned int v6; // edx
  int *p_skidMaterialIndex; // eax
  int v8; // ecx
  int v9; // edi
  CPhysicsObject **v10; // esi
  float v11; // xmm1_4
  float v12; // xmm0_4
  int *v13; // [esp+1Ch] [ebp-14h]
  int iAxle; // [esp+20h] [ebp-10h]
  int iWheel; // [esp+24h] [ebp-Ch]
  int materialIndex; // [esp+28h] [ebp-8h]
  unsigned int newTireType; // [esp+2Ch] [ebp-4h]
  float powerSlide; // [esp+38h] [ebp+8h]
  char powerSlide_3; // [esp+3Bh] [ebp+Bh]
  char bPowerslideLeft; // [esp+3Fh] [ebp+Fh]

  if ( !this->m_vehicleData.steering.isSkidAllowed || !this->m_bOccupied )
    return;
  if ( !bPowerslide || (bPowerslideLeft = 1, !controls->handbrakeLeft) )
    bPowerslideLeft = 0;
  if ( !bPowerslide || (v5 = !controls->handbrakeRight, powerSlide_3 = 1, v5) )
    powerSlide_3 = 0;
  v6 = 0;
  iWheel = 0;
  newTireType = 0;
  if ( bPowerslideLeft != 0 || powerSlide_3 != 0 )
  {
    newTireType = 2;
  }
  else
  {
    if ( !bPowerslide )
      goto LABEL_15;
    newTireType = 1;
  }
  v6 = newTireType;
LABEL_15:
  if ( v6 != this->m_nTireType )
  {
    iAxle = 0;
    if ( this->m_vehicleData.axleCount > 0 )
    {
      p_skidMaterialIndex = &this->m_vehicleData.axles[0].wheels.skidMaterialIndex;
      v13 = &this->m_vehicleData.axles[0].wheels.skidMaterialIndex;
      while ( 1 )
      {
        materialIndex = *(p_skidMaterialIndex - 2);
        if ( v6 == 2 )
          break;
        if ( v6 == 1 )
        {
          v8 = *(p_skidMaterialIndex - 1);
LABEL_22:
          if ( v8 != -1 )
            materialIndex = v8;
        }
        v9 = 0;
        if ( this->m_vehicleData.wheelsPerAxle > 0 )
        {
          v10 = &this->m_pWheels[iWheel];
          do
          {
            (*v10)->SetMaterialIndex(this: *v10, a2: materialIndex);
            ++iWheel;
            ++v9;
            ++v10;
          }
          while ( v9 < this->m_vehicleData.wheelsPerAxle );
          v6 = newTireType;
          p_skidMaterialIndex = v13;
        }
        p_skidMaterialIndex += 29;
        this->m_nTireType = v6;
        ++iAxle;
        v13 = p_skidMaterialIndex;
        if ( iAxle >= this->m_vehicleData.axleCount )
          goto LABEL_29;
      }
      v8 = *p_skidMaterialIndex;
      goto LABEL_22;
    }
  }
LABEL_29:
  v11 = 0.0;
  v12 = 0.0;
  if ( flSpeed > 0.0 && bPowerslideLeft != powerSlide_3 )
  {
    powerSlide = RemapValClamped(
                   val: flSpeed,
                   A: this->m_vehicleData.steering.speedSlow,
                   B: this->m_vehicleData.steering.speedFast,
                   C: 0.0,
                   D: 1.0);
    v12 = (float)(this->m_vehicleData.steering.powerSlideAccel * g_PhysicsUnits.unitScaleMeters) * powerSlide;
    v11 = v12;
    if ( bPowerslideLeft != 0 )
      LODWORD(v12) ^= _mask__NegFloat_;
    else
      LODWORD(v11) = LODWORD(v12) ^ _mask__NegFloat_;
  }
  ((void (__thiscall *)(IVP_Car_System *, _DWORD, _DWORD))this->m_pCarSystem->set_powerslide)(
    a1: this->m_pCarSystem,
    a2: LODWORD(v11),
    a3: LODWORD(v12));
}

//------------------------------------------------------------------------------
// Address: 0x10025230
// Name: protected: float CVehicleController::CalcSteering(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVehicleController::CalcSteering(
        CVehicleController *this,
        float dt,
        float speed,
        float steering,
        bool bAnalog)
{
  float speedSlow; // xmm3_4
  float speedFast; // xmm1_4
  float degreesFast; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float maxSpeed; // xmm2_4
  float boostMaxSpeed; // xmm1_4
  float degreesBoost; // xmm3_4
  float v15; // xmm0_4
  int v16; // eax
  float v17; // xmm0_4
  float v18; // xmm0_4
  long double v20; // [esp+0h] [ebp-Ch]
  long double var4; // [esp+8h] [ebp-4h]
  float v22; // [esp+8h] [ebp-4h]
  float degrees; // [esp+18h] [ebp+Ch]
  float sign; // [esp+1Ch] [ebp+10h]

  speedSlow = this->m_vehicleData.steering.speedSlow;
  speedFast = this->m_vehicleData.steering.speedFast;
  degreesFast = this->m_vehicleData.steering.degreesFast;
  v9 = degreesFast;
  if ( speedSlow == speedFast )
  {
    if ( (float)(speed - speedFast) < 0.0 )
    {
      degrees = this->m_vehicleData.steering.degreesSlow;
      goto LABEL_10;
    }
  }
  else
  {
    v10 = (float)(speed - speedSlow) / (float)(speedFast - speedSlow);
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    v9 = (float)((float)(degreesFast - this->m_vehicleData.steering.degreesSlow) * v10)
       + this->m_vehicleData.steering.degreesSlow;
  }
  degrees = v9;
LABEL_10:
  v11 = (float)(speed * 0.44707) * g_PhysicsUnits.unitScaleMetersInv;
  maxSpeed = this->m_vehicleData.engine.maxSpeed;
  if ( v11 <= maxSpeed )
    goto LABEL_20;
  boostMaxSpeed = this->m_vehicleData.engine.boostMaxSpeed;
  degreesBoost = this->m_vehicleData.steering.degreesBoost;
  if ( maxSpeed == boostMaxSpeed )
  {
    if ( (float)(v11 - boostMaxSpeed) < 0.0 )
    {
      degrees = this->m_vehicleData.steering.degreesFast;
      goto LABEL_20;
    }
  }
  else
  {
    v15 = (float)(v11 - maxSpeed) / (float)(boostMaxSpeed - maxSpeed);
    if ( v15 >= 0.0 )
    {
      if ( v15 > 1.0 )
        v15 = 1.0;
    }
    else
    {
      v15 = 0.0;
    }
    degreesBoost = (float)((float)(degreesBoost - degreesFast) * v15) + degreesFast;
  }
  degrees = degreesBoost;
LABEL_20:
  *(float *)&v20 = this->m_vehicleData.steering.steeringExponent;
  if ( *(float *)&v20 == 0.0 )
    return degrees * steering;
  if ( steering >= 0.0 )
    v16 = 1;
  else
    v16 = -1;
  LODWORD(v17) = LODWORD(steering) & _mask__AbsFloat_;
  sign = (float)v16;
  *((float *)&v20 + 1) = v17;
  if ( !bAnalog )
    return pow(v17, *(float *)&v20) * sign * degrees;
  *(float *)&var4 = this->m_vehicleData.steering.degreesSlow;
  __libm_sse2_pow(x: v20, y: var4);
  v18 = (float)(v17 * sign) * v22;
  if ( COERCE_FLOAT(LODWORD(degrees) ^ _mask__NegFloat_) > v18 )
    return COERCE_FLOAT(LODWORD(degrees) ^ _mask__NegFloat_);
  if ( v18 <= degrees )
    return v18;
  return degrees;
}

//------------------------------------------------------------------------------
// Address: 0x10025410
// Name: protected: void CVehicleController::CalcEngine(float,float,bool,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::CalcEngine(
        CVehicleController *this,
        float throttle,
        float brake_val,
        bool handbrake,
        float steeringVal,
        bool torqueBoost)
{
  float speed; // xmm6_4
  bool v8; // cl
  float v9; // xmm3_4
  float boostMaxSpeed; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float horsepower; // xmm1_4
  float maxRPM; // xmm0_4
  float v15; // xmm1_4
  int v16; // ebx
  vehicle_wheelparams_t *p_wheels; // edi
  float v18; // xmm2_4
  float v19; // xmm0_4
  float maxSpeed; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  int v25; // edi
  float v26; // xmm1_4
  float v27; // xmm0_4
  int v28; // ebx
  float *p_radius; // eax
  int v30; // edi
  float v31; // xmm0_4
  int m_vehicleFlags; // eax
  int v33; // edi
  float torque_val; // [esp+18h] [ebp-18h]
  int i; // [esp+20h] [ebp-10h]
  vehicle_wheelparams_t *v36; // [esp+2Ch] [ebp-4h]
  float wheel_force_by_throttle; // [esp+3Ch] [ebp+Ch]
  vehicle_wheelparams_t *wheel_force_by_throttlea; // [esp+3Ch] [ebp+Ch]
  float steeringVala; // [esp+44h] [ebp+14h]
  int torqueBoosta; // [esp+48h] [ebp+18h]

  CVehicleController::CalcEngineTransmission(this, flThrottle: throttle);
  speed = this->m_currentState.speed;
  v8 = torqueBoost;
  v9 = fabs(speed);
  if ( torqueBoost )
    boostMaxSpeed = this->m_vehicleData.engine.boostMaxSpeed;
  else
    boostMaxSpeed = this->m_vehicleData.engine.maxSpeed;
  if ( boostMaxSpeed < 1.0 )
    boostMaxSpeed = 1.0;
  v11 = throttle;
  if ( throttle <= 0.0 || v9 <= boostMaxSpeed )
  {
    v12 = brake_val;
    goto LABEL_14;
  }
  if ( (float)(v9 / boostMaxSpeed) <= this->m_vehicleData.engine.autobrakeSpeedGain )
  {
    v12 = brake_val;
    goto LABEL_12;
  }
  v12 = (float)((float)(v9 / boostMaxSpeed) - 1.0) * this->m_vehicleData.engine.autobrakeSpeedFactor;
  v11 = 0.0;
  if ( this->m_currentState.wheelsInContact != 0 )
  {
LABEL_12:
    v11 = v11 * 0.1;
    throttle = v11;
    goto LABEL_14;
  }
  v11 = 0.0 * 0.1;
  v12 = 0.0;
  throttle = 0.0 * 0.1;
LABEL_14:
  if ( v11 < 0.0 && !torqueBoost && v9 > this->m_vehicleData.engine.maxRevSpeed )
  {
    v11 = v11 * 0.1;
    throttle = v11;
  }
  if ( v11 == 0.0 )
  {
    if ( v12 == 0.0 )
    {
      m_vehicleFlags = this->m_vehicleFlags;
      if ( (m_vehicleFlags & 1) == 0 )
      {
        v33 = 0;
        for ( this->m_vehicleFlags = m_vehicleFlags | 1; v33 < this->m_wheelCount; ++v33 )
          ((void (__stdcall *)(int, _DWORD))this->m_pCarSystem->change_wheel_torque)(a1: v33, a2: 0);
      }
    }
    else
    {
      this->m_vehicleFlags &= ~1u;
      v26 = (float)(this->m_totalWheelMass + this->m_bodyMass) * (float)(this->m_gravityLength * v12);
      if ( speed < 0.0 )
        v27 = 1.0;
      else
        v27 = -1.0;
      v28 = 0;
      torqueBoosta = 0;
      if ( this->m_vehicleData.axleCount > 0 )
      {
        p_radius = &this->m_vehicleData.axles[0].wheels.radius;
        steeringVala = (float)(v27 * 0.5) * v26;
        wheel_force_by_throttlea = &this->m_vehicleData.axles[0].wheels;
        do
        {
          v30 = 0;
          v31 = (float)(*p_radius * g_PhysicsUnits.unitScaleMeters) * (float)(p_radius[16] * steeringVala);
          torque_val = v31;
          if ( this->m_vehicleData.wheelsPerAxle > 0 )
          {
            while ( 1 )
            {
              ((void (__stdcall *)(int, _DWORD))this->m_pCarSystem->change_wheel_torque)(a1: v28, a2: LODWORD(v31));
              ++v30;
              ++v28;
              if ( v30 >= this->m_vehicleData.wheelsPerAxle )
                break;
              v31 = torque_val;
            }
            p_radius = &wheel_force_by_throttlea->radius;
          }
          p_radius += 29;
          ++torqueBoosta;
          wheel_force_by_throttlea = (vehicle_wheelparams_t *)p_radius;
        }
        while ( torqueBoosta < this->m_vehicleData.axleCount );
      }
    }
  }
  else
  {
    horsepower = this->m_vehicleData.engine.horsepower;
    this->m_vehicleFlags &= ~1u;
    maxRPM = this->m_vehicleData.engine.maxRPM;
    v15 = (float)((float)((float)((float)(horsepower * v11) * 44700.0)
                        * this->m_vehicleData.engine.gearRatio[this->m_currentState.gear])
                * this->m_vehicleData.engine.axleRatio)
        / (float)((float)(this->m_wheelRadius * maxRPM) * 6.2831855);
    wheel_force_by_throttle = v15;
    if ( this->m_currentState.engineRPM >= maxRPM )
    {
      v15 = 0.0;
      wheel_force_by_throttle = 0.0;
    }
    v16 = 0;
    i = 0;
    if ( this->m_vehicleData.axleCount > 0 )
    {
      p_wheels = &this->m_vehicleData.axles[0].wheels;
      v36 = &this->m_vehicleData.axles[0].wheels;
      while ( 1 )
      {
        v18 = p_wheels[1].frictionScale * this->m_torqueScale;
        v19 = 0.5;
        if ( v8 )
        {
          if ( !this->IsBoosting(this) )
            goto LABEL_36;
          maxSpeed = this->m_vehicleData.engine.maxSpeed;
          if ( maxSpeed == 0.0 )
          {
            v21 = (float)(v9 - maxSpeed) < 0.0 ? 0.1 : 1.0;
          }
          else
          {
            v22 = v9 / maxSpeed;
            if ( (float)(v9 / maxSpeed) >= 0.0 )
            {
              if ( v22 > 1.0 )
                v22 = 1.0;
            }
            else
            {
              v22 = 0.0;
            }
            v21 = (float)(v22 * 0.89999998) + 0.1;
          }
          v19 = (float)(1.0 - (float)(COERCE_FLOAT(LODWORD(steeringVal) & _mask__AbsFloat_) * 0.94999999))
              * (float)(this->m_vehicleData.engine.boostForce * v21);
          if ( v19 <= 0.5 )
LABEL_36:
            v19 = 0.5;
          v15 = wheel_force_by_throttle;
        }
        v23 = (float)(v19 * v15) * v18;
        v24 = g_PhysicsUnits.unitScaleMeters * p_wheels->radius;
        v25 = 0;
        if ( this->m_vehicleData.wheelsPerAxle > 0 )
        {
          do
          {
            ((void (__stdcall *)(int, _DWORD))this->m_pCarSystem->change_wheel_torque)(a1: v16, a2: v23 * v24);
            ++v25;
            ++v16;
          }
          while ( v25 < this->m_vehicleData.wheelsPerAxle );
          v15 = wheel_force_by_throttle;
        }
        v36 = (vehicle_wheelparams_t *)((char *)v36 + 116);
        if ( ++i >= this->m_vehicleData.axleCount )
          break;
        p_wheels = v36;
        v8 = torqueBoost;
      }
    }
  }
  ((void (__stdcall *)(_DWORD))this->m_pCarSystem->update_throttle)(a1: LODWORD(throttle));
}

//------------------------------------------------------------------------------
// Address: 0x100257F0
// Name: public: virtual void CVehicleController::GetCarSystemDebugData(struct vehicle_debugcarsystem_t __near &)
// Source: json
//------------------------------------------------------------------------------
// Force-skipped: ?GetCarSystemDebugData@CVehicleController@@UAEXAAUvehicle_debugcarsystem_t@@@Z

//------------------------------------------------------------------------------
// Address: 0x10026200
// Name: public: void CVehicleController::InitFromTemplate(class CPhysicsEnvironment __near *,void __near *,class IPhysicsGameTrace __near *,struct vphysics_save_cvehiclecontroller_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVehicleController::InitFromTemplate(
        CVehicleController *this,
        CPhysicsEnvironment *pEnv,
        void *pGameData,
        IPhysicsGameTrace *pGameTrace,
        const vphysics_save_cvehiclecontroller_t *controllerTemplate)
{
  float m_torqueScale; // xmm1_4
  float y; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  CPhysicsObject *v11; // ecx
  float v12; // xmm1_4
  CPhysicsObject *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  CPhysicsObject *v19; // eax
  float v20; // xmm1_4
  CPhysicsObject *v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  CPhysicsObject *v25; // eax
  float v26; // xmm1_4
  float v27; // xmm1_4
  CPhysicsObject *m_pCarBody; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  this->m_pEnv = pEnv;
  this->m_pGameTrace = pGameTrace;
  this->m_pCarBody = controllerTemplate->m_pCarBody;
  this->m_wheelCount = controllerTemplate->m_wheelCount;
  this->m_wheelRadius = controllerTemplate->m_wheelRadius;
  this->m_bodyMass = controllerTemplate->m_bodyMass;
  this->m_totalWheelMass = controllerTemplate->m_totalWheelMass;
  this->m_gravityLength = controllerTemplate->m_gravityLength;
  this->m_torqueScale = controllerTemplate->m_torqueScale;
  this->m_vehicleFlags = controllerTemplate->m_vehicleFlags;
  this->m_nTireType = controllerTemplate->m_nTireType;
  this->m_nVehicleType = controllerTemplate->m_nVehicleType;
  m_torqueScale = this->m_torqueScale;
  this->m_bTraceData = controllerTemplate->m_bTraceData;
  this->m_bOccupied = controllerTemplate->m_bOccupied;
  this->m_bEngineDisable = controllerTemplate->m_bEngineDisable;
  this->m_pCarSystem = nullptr;
  this->m_currentState = controllerTemplate->m_currentState;
  qmemcpy((void *)&this->m_vehicleData, &controllerTemplate->m_vehicleData, sizeof(this->m_vehicleData));
  if ( m_torqueScale == 0.0 )
    this->m_torqueScale = 1.0;
  if ( this->m_vehicleData.steering.steeringRateSlow == 0.0 )
    this->m_vehicleData.steering.steeringRateSlow = 4.5;
  if ( this->m_vehicleData.steering.steeringRateFast == 0.0 )
    this->m_vehicleData.steering.steeringRateFast = 0.5;
  if ( this->m_vehicleData.steering.steeringRestRateSlow == 0.0 )
    this->m_vehicleData.steering.steeringRestRateSlow = 3.0;
  if ( this->m_vehicleData.steering.steeringRestRateFast == 0.0 )
    this->m_vehicleData.steering.steeringRestRateFast = 1.8;
  if ( this->m_vehicleData.steering.speedSlow == 0.0 )
    this->m_vehicleData.steering.speedSlow = this->m_vehicleData.engine.maxSpeed * 0.25;
  if ( this->m_vehicleData.steering.speedFast == 0.0 )
    this->m_vehicleData.steering.speedFast = this->m_vehicleData.engine.maxSpeed * 0.75;
  if ( this->m_vehicleData.steering.degreesSlow == 0.0 )
    this->m_vehicleData.steering.degreesSlow = 50.0;
  if ( this->m_vehicleData.steering.degreesFast == 0.0 )
    this->m_vehicleData.steering.degreesFast = 18.0;
  if ( this->m_vehicleData.steering.degreesBoost == 0.0 )
    this->m_vehicleData.steering.degreesBoost = 10.0;
  if ( this->m_vehicleData.steering.turnThrottleReduceSlow == 0.0 )
    this->m_vehicleData.steering.turnThrottleReduceSlow = 0.30000001;
  if ( this->m_vehicleData.steering.turnThrottleReduceFast == 0.0 )
    this->m_vehicleData.steering.turnThrottleReduceFast = 3.0;
  if ( this->m_vehicleData.steering.brakeSteeringRateFactor == 0.0 )
    this->m_vehicleData.steering.brakeSteeringRateFactor = 6.0;
  if ( this->m_vehicleData.steering.throttleSteeringRestRateFactor == 0.0 )
    this->m_vehicleData.steering.throttleSteeringRestRateFactor = 2.0;
  if ( this->m_vehicleData.steering.boostSteeringRestRateFactor == 0.0 )
    this->m_vehicleData.steering.boostSteeringRestRateFactor = 1.0;
  if ( this->m_vehicleData.steering.boostSteeringRateFactor == 0.0 )
    this->m_vehicleData.steering.boostSteeringRateFactor = 1.0;
  if ( this->m_vehicleData.steering.powerSlideAccel == 0.0 )
    this->m_vehicleData.steering.powerSlideAccel = 200.0;
  if ( this->m_vehicleData.engine.autobrakeSpeedGain == 0.0 )
    this->m_vehicleData.engine.autobrakeSpeedGain = 1.0;
  if ( this->m_vehicleData.engine.autobrakeSpeedFactor == 0.0 )
    this->m_vehicleData.engine.autobrakeSpeedFactor = 2.0;
  y = controllerTemplate->m_wheelPosition_Bs[0].y;
  this->m_pWheels[0] = controllerTemplate->m_pWheels[0];
  this->m_wheelPosition_Bs[0].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[0].x;
  this->m_wheelPosition_Bs[0].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[0].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[0].k[2] = g_PhysicsUnits.unitScaleMeters * y;
  v8 = controllerTemplate->m_tracePosition_Bs[0].y;
  this->m_tracePosition_Bs[0].k[0] = controllerTemplate->m_tracePosition_Bs[0].x * g_PhysicsUnits.unitScaleMeters;
  this->m_tracePosition_Bs[0].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[0].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[0].k[2] = g_PhysicsUnits.unitScaleMeters * v8;
  v9 = controllerTemplate->m_wheelPosition_Bs[1].y;
  this->m_pWheels[1] = controllerTemplate->m_pWheels[1];
  this->m_wheelPosition_Bs[1].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[1].x;
  this->m_wheelPosition_Bs[1].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[1].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[1].k[2] = g_PhysicsUnits.unitScaleMeters * v9;
  v10 = controllerTemplate->m_tracePosition_Bs[1].y;
  this->m_tracePosition_Bs[1].k[0] = controllerTemplate->m_tracePosition_Bs[1].x * g_PhysicsUnits.unitScaleMeters;
  v11 = controllerTemplate->m_pWheels[2];
  this->m_tracePosition_Bs[1].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[1].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[1].k[2] = g_PhysicsUnits.unitScaleMeters * v10;
  v12 = controllerTemplate->m_wheelPosition_Bs[2].y;
  this->m_pWheels[2] = v11;
  this->m_wheelPosition_Bs[2].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[2].x;
  v13 = controllerTemplate->m_pWheels[3];
  this->m_wheelPosition_Bs[2].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[2].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[2].k[2] = g_PhysicsUnits.unitScaleMeters * v12;
  v14 = controllerTemplate->m_tracePosition_Bs[2].y;
  this->m_tracePosition_Bs[2].k[0] = controllerTemplate->m_tracePosition_Bs[2].x * g_PhysicsUnits.unitScaleMeters;
  this->m_tracePosition_Bs[2].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[2].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[2].k[2] = g_PhysicsUnits.unitScaleMeters * v14;
  v15 = controllerTemplate->m_wheelPosition_Bs[3].y;
  this->m_pWheels[3] = v13;
  this->m_wheelPosition_Bs[3].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[3].x;
  this->m_wheelPosition_Bs[3].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[3].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[3].k[2] = g_PhysicsUnits.unitScaleMeters * v15;
  v16 = controllerTemplate->m_tracePosition_Bs[3].y;
  this->m_tracePosition_Bs[3].k[0] = controllerTemplate->m_tracePosition_Bs[3].x * g_PhysicsUnits.unitScaleMeters;
  this->m_tracePosition_Bs[3].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[3].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[3].k[2] = g_PhysicsUnits.unitScaleMeters * v16;
  v17 = controllerTemplate->m_wheelPosition_Bs[4].y;
  this->m_pWheels[4] = controllerTemplate->m_pWheels[4];
  this->m_wheelPosition_Bs[4].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[4].x;
  this->m_wheelPosition_Bs[4].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[4].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[4].k[2] = g_PhysicsUnits.unitScaleMeters * v17;
  v18 = controllerTemplate->m_tracePosition_Bs[4].y;
  this->m_tracePosition_Bs[4].k[0] = controllerTemplate->m_tracePosition_Bs[4].x * g_PhysicsUnits.unitScaleMeters;
  v19 = controllerTemplate->m_pWheels[5];
  this->m_tracePosition_Bs[4].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[4].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[4].k[2] = g_PhysicsUnits.unitScaleMeters * v18;
  v20 = controllerTemplate->m_wheelPosition_Bs[5].y;
  this->m_pWheels[5] = v19;
  this->m_wheelPosition_Bs[5].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[5].x;
  v21 = controllerTemplate->m_pWheels[6];
  this->m_wheelPosition_Bs[5].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[5].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[5].k[2] = g_PhysicsUnits.unitScaleMeters * v20;
  v22 = controllerTemplate->m_tracePosition_Bs[5].y;
  this->m_tracePosition_Bs[5].k[0] = controllerTemplate->m_tracePosition_Bs[5].x * g_PhysicsUnits.unitScaleMeters;
  this->m_tracePosition_Bs[5].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[5].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[5].k[2] = g_PhysicsUnits.unitScaleMeters * v22;
  v23 = controllerTemplate->m_wheelPosition_Bs[6].y;
  this->m_pWheels[6] = v21;
  this->m_wheelPosition_Bs[6].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[6].x;
  this->m_wheelPosition_Bs[6].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[6].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[6].k[2] = g_PhysicsUnits.unitScaleMeters * v23;
  v24 = controllerTemplate->m_tracePosition_Bs[6].y;
  this->m_tracePosition_Bs[6].k[0] = controllerTemplate->m_tracePosition_Bs[6].x * g_PhysicsUnits.unitScaleMeters;
  v25 = controllerTemplate->m_pWheels[7];
  this->m_tracePosition_Bs[6].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[6].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[6].k[2] = g_PhysicsUnits.unitScaleMeters * v24;
  v26 = controllerTemplate->m_wheelPosition_Bs[7].y;
  this->m_pWheels[7] = v25;
  this->m_wheelPosition_Bs[7].k[0] = g_PhysicsUnits.unitScaleMeters * controllerTemplate->m_wheelPosition_Bs[7].x;
  this->m_wheelPosition_Bs[7].k[1] = -(float)(controllerTemplate->m_wheelPosition_Bs[7].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_wheelPosition_Bs[7].k[2] = g_PhysicsUnits.unitScaleMeters * v26;
  v27 = controllerTemplate->m_tracePosition_Bs[7].y;
  this->m_tracePosition_Bs[7].k[0] = controllerTemplate->m_tracePosition_Bs[7].x * g_PhysicsUnits.unitScaleMeters;
  this->m_tracePosition_Bs[7].k[1] = -(float)(controllerTemplate->m_tracePosition_Bs[7].z
                                            * g_PhysicsUnits.unitScaleMeters);
  this->m_tracePosition_Bs[7].k[2] = g_PhysicsUnits.unitScaleMeters * v27;
  CVehicleController::CreateIVPObjects(this, a2: COERCE_FLOAT(&savedregs));
  m_pCarBody = this->m_pCarBody;
  if ( m_pCarBody != nullptr )
    m_pCarBody->SetVelocity(this: m_pCarBody, a2: nullptr, a3: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x10026B00
// Name: bool SavePhysicsVehicleController(struct physsaveparams_t const __near &,class CVehicleController __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SavePhysicsVehicleController(const physsaveparams_t *params, CVehicleController *pVehicleController)
{
  vphysics_save_cvehiclecontroller_t controllerTemplate; // [esp+0h] [ebp-3D8h] BYREF

  memset(dst: (unsigned __int8 *)&controllerTemplate, value: 0, count: sizeof(controllerTemplate));
  CVehicleController::WriteToTemplate(this: pVehicleController, &controllerTemplate);
  params->pSave->WriteAll(
    this: params->pSave,
    a2: &controllerTemplate,
    a3: &vphysics_save_cvehiclecontroller_t::m_DataMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026B50
// Name: bool RestorePhysicsVehicleController(struct physrestoreparams_t const __near &,class CVehicleController __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RestorePhysicsVehicleController(
        const physrestoreparams_t *params,
        CVehicleController **ppVehicleController)
{
  CVehicleController *v2; // eax
  vphysics_save_cvehiclecontroller_t controllerTemplate; // [esp+0h] [ebp-3D8h] BYREF

  v2 = (CVehicleController *)p_malloc(size: 0x430u);
  if ( v2 != nullptr )
  {
    v2->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
    v2->IPhysicsVehicleController::__vftable = (CVehicleController_vtbl *)&CVehicleController::`vftable'{for `IPhysicsVehicleController'};
    v2->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CVehicleController::`vftable'{for `IVP_Listener_Object'};
  }
  else
  {
    v2 = nullptr;
  }
  *ppVehicleController = v2;
  memset(dst: (unsigned __int8 *)&controllerTemplate, value: 0, count: sizeof(controllerTemplate));
  params->pRestore->ReadAll(
    this: params->pRestore,
    a2: &controllerTemplate,
    a3: &vphysics_save_cvehiclecontroller_t::m_DataMap);
  CVehicleController::InitFromTemplate(
    this: *ppVehicleController,
    pEnv: (CPhysicsEnvironment *)params->pEnvironment,
    pGameData: params->pGameData,
    pGameTrace: params->pGameTrace,
    &controllerTemplate);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026BE0
// Name: public: CVehicleController::CVehicleController(struct vehicleparams_t const __near &,class CPhysicsEnvironment __near *,unsigned int,class IPhysicsGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
CVehicleController *__thiscall CVehicleController::CVehicleController(
        CVehicleController *this,
        const vehicleparams_t *params,
        CPhysicsEnvironment *pEnv,
        unsigned int nVehicleType,
        IPhysicsGameTrace *pGameTrace)
{
  bool v6; // zf

  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->m_pEnv = pEnv;
  this->m_pGameTrace = pGameTrace;
  this->IPhysicsVehicleController::__vftable = (CVehicleController_vtbl *)&CVehicleController::`vftable'{for `IPhysicsVehicleController'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CVehicleController::`vftable'{for `IVP_Listener_Object'};
  this->m_pCarSystem = nullptr;
  this->m_nVehicleType = nVehicleType;
  vehicleparams_t::operator=(this: &this->m_vehicleData, __that: params);
  this->VehicleDataReload(this);
  this->m_pWheels[0] = nullptr;
  this->m_pWheels[1] = nullptr;
  this->m_pWheels[2] = nullptr;
  this->m_pWheels[3] = nullptr;
  this->m_pWheels[4] = nullptr;
  this->m_pWheels[5] = nullptr;
  this->m_pWheels[6] = nullptr;
  this->m_pWheels[7] = nullptr;
  this->m_torqueScale = 1.0;
  this->m_pCarBody = nullptr;
  this->m_wheelCount = 0;
  this->m_wheelRadius = 0.0;
  memset(dst: (unsigned __int8 *)&this->m_currentState, value: 0, count: sizeof(this->m_currentState));
  this->m_bodyMass = 0.0;
  this->m_vehicleFlags = 0;
  memset(dst: (unsigned __int8 *)this->m_wheelPosition_Bs, value: 0, count: sizeof(this->m_wheelPosition_Bs));
  memset(dst: (unsigned __int8 *)this->m_tracePosition_Bs, value: 0, count: sizeof(this->m_tracePosition_Bs));
  v6 = this->m_nVehicleType == 8;
  this->m_bTraceData = false;
  if ( v6 )
    this->m_bTraceData = true;
  this->m_nTireType = 0;
  *(_WORD *)&this->m_bOccupied = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026CF0
// Name: public: virtual void CVehicleController::Update(float,struct vehicle_controlparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CVehicleController::Update(
        CVehicleController *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        float dt,
        vehicle_controlparams_t *controlsIn)
{
  IVP_Car_System *m_pCarSystem; // ecx
  float (__thiscall *get_body_speed)(IVP_Car_System *, IVP_COORDINATE_INDEX); // edx
  float v9; // xmm0_4
  float v10; // xmm1_4
  char v11; // bl
  int v12; // xmm0_4
  double v13; // st7
  float v14; // xmm0_4
  int v15; // edi
  bool v16; // bl
  void (__thiscall *activate_booster)(IVP_Car_System *, float, float, float); // eax
  float boostDuration; // xmm0_4
  float brake_val; // xmm0_4
  char v20; // bl
  float v21; // xmm0_4
  float v22; // xmm1_4
  float steeringa; // [esp+34h] [ebp-34h]
  float steeringb; // [esp+34h] [ebp-34h]
  float boostDelay; // [esp+38h] [ebp-30h]
  bool v27; // [esp+38h] [ebp-30h]
  _BYTE controls[25]; // [esp+3Ch] [ebp-2Ch] OVERLAPPED BYREF
  float flSpeed; // [esp+58h] [ebp-10h]
  float flAbsSpeed; // [esp+5Ch] [ebp-Ch]
  float flBrake; // [esp+60h] [ebp-8h]
  int bPowerslide; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF
  float flThrottlea; // [esp+74h] [ebp+Ch]
  float flThrottle; // [esp+74h] [ebp+Ch]

  *(_QWORD *)controls = *(_QWORD *)&controlsIn->throttle;
  m_pCarSystem = this->m_pCarSystem;
  *(_QWORD *)&controls[8] = *(_QWORD *)&controlsIn->brake;
  get_body_speed = m_pCarSystem->get_body_speed;
  *(_QWORD *)&controls[16] = *(_QWORD *)&controlsIn->handbrake;
  flThrottlea = ((double (__thiscall *)(IVP_Car_System *, int, int, int, int))get_body_speed)(
                  a1: m_pCarSystem,
                  a2: 2,
                  a3,
                  a4,
                  a5: a2);
  v9 = g_PhysicsUnits.unitScaleMetersInv * flThrottlea;
  v10 = *(float *)controls;
  v11 = controls[16];
  this->m_currentState.speed = g_PhysicsUnits.unitScaleMetersInv * flThrottlea;
  flSpeed = (float)(v9 * g_PhysicsUnits.unitScaleMeters) * 2.2367861;
  flThrottle = v10;
  LODWORD(flAbsSpeed) = LODWORD(flSpeed) & _mask__AbsFloat_;
  flBrake = *(float *)&controls[8];
  if ( v11 == 0 || (LOBYTE(bPowerslide) = 1, COERCE_FLOAT(LODWORD(flSpeed) & _mask__AbsFloat_) <= 18.0) )
    LOBYTE(bPowerslide) = 0;
  if ( v11 != 0 )
    flThrottle = 0.0;
  if ( this->IsBoosting(this) )
  {
    *(float *)&v12 = 1.0;
    *(_DWORD *)&controls[12] = 1065353216;
    if ( flThrottle < 0.0 )
      *(float *)&v12 = -1.0;
    flThrottle = *(float *)&v12;
  }
  else if ( flThrottle == 0.0 && *(float *)&controls[8] == 0.0 && v11 == 0 )
  {
    flBrake = 0.1;
  }
  v13 = CVehicleController::CalcSteering(
          this,
          dt,
          speed: flAbsSpeed,
          steering: *(float *)&controls[4],
          bAnalog: controls[21]);
  flAbsSpeed = v13;
  steeringa = v13 * 0.017453292;
  ((void (__stdcall *)(_DWORD, _DWORD))this->m_pCarSystem->do_steering)(
    a1: LODWORD(steeringa),
    a2: *(_DWORD *)&controls[21]);
  v14 = flSpeed;
  v15 = bPowerslide;
  this->m_currentState.steeringAngle = flAbsSpeed;
  CVehicleController::UpdatePowerslide(this, (const vehicle_controlparams_t *)controls, bPowerslide: v15, flSpeed: v14);
  v16 = false;
  LOBYTE(bPowerslide) = 0;
  if ( *(float *)&controls[12] > 0.0 )
  {
    activate_booster = this->m_pCarSystem->activate_booster;
    if ( this->m_vehicleData.engine.torqueBoost )
    {
      boostDelay = this->m_vehicleData.engine.boostDelay;
      boostDuration = this->m_vehicleData.engine.boostDuration;
      v16 = true;
      LOBYTE(bPowerslide) = 1;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))activate_booster)(
        a1: 0,
        a2: LODWORD(boostDuration),
        a3: LODWORD(boostDelay));
    }
    else
    {
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))activate_booster)(
        a1: this->m_vehicleData.engine.boostForce * *(float *)&controls[12],
        a2: LODWORD(this->m_vehicleData.engine.boostDuration),
        a3: LODWORD(this->m_vehicleData.engine.boostDelay));
    }
  }
  ((void (__stdcall *)(_DWORD))this->m_pCarSystem->update_booster)(a1: LODWORD(dt));
  this->m_currentState.boostDelay = this->m_pCarSystem->get_booster_delay(this: this->m_pCarSystem);
  v27 = bPowerslide;
  steeringb = *(float *)&controls[4];
  brake_val = flBrake;
  this->m_currentState.isTorqueBoosting = v16;
  v20 = controls[16];
  CVehicleController::CalcEngine(
    this,
    throttle: flThrottle,
    brake_val,
    handbrake: controls[16],
    steeringVal: steeringb,
    torqueBoost: v27);
  v21 = this->m_vehicleData.engine.boostDelay + this->m_vehicleData.engine.boostDuration;
  if ( v21 > 0.0 )
  {
    v22 = this->m_currentState.boostDelay;
    if ( v22 <= 0.0 )
      this->m_currentState.boostTimeLeft = 100;
    else
      this->m_currentState.boostTimeLeft = (int)(float)(100.0 - (float)((float)(v22 / v21) * 100.0));
  }
  CVehicleController::UpdateHandbrake(
    this,
    (const vehicle_controlparams_t *)controls,
    flThrottle,
    bHandbrake: v20,
    bPowerslide: v15);
  CVehicleController::UpdateSkidding(this, a2: (int)&savedregs, bHandbrake: v20);
  CVehicleController::UpdateExtraForces(this, a2: COERCE_FLOAT(&savedregs), a3: v15, a4: (int)this);
  if ( this->m_nVehicleType == 2 )
    this->m_pCarSystem->update_wheel_positions(this: this->m_pCarSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10026FD0
// Name: class IPhysicsVehicleController __near * CreateVehicleController(class CPhysicsEnvironment __near *,class CPhysicsObject __near *,struct vehicleparams_t const __near &,unsigned int,class IPhysicsGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
CVehicleController *__cdecl CreateVehicleController(
        CPhysicsEnvironment *pEnv,
        CPhysicsObject *pBodyObject,
        const vehicleparams_t *params,
        unsigned int nVehicleType,
        IPhysicsGameTrace *pGameTrace)
{
  CVehicleController *v5; // eax
  CVehicleController *v6; // esi

  v5 = (CVehicleController *)p_malloc(size: 0x430u);
  if ( v5 != nullptr )
  {
    v6 = CVehicleController::CVehicleController(this: v5, params, pEnv, nVehicleType, pGameTrace);
    CVehicleController::InitCarSystem(this: v6, (int)pBodyObject);
    return v6;
  }
  else
  {
    CVehicleController::InitCarSystem(this: nullptr, (int)pBodyObject);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C6B00
// Name: vphysics_save_cvehiclecontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cvehiclecontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cvehiclecontroller_t>(__formal: nullptr);
  vphysics_save_cvehiclecontroller_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B10
// Name: vehicle_operatingparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_operatingparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_operatingparams_t>(__formal: nullptr);
  vehicle_operatingparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B20
// Name: vehicle_bodyparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_bodyparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_bodyparams_t>(__formal: nullptr);
  vehicle_bodyparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B30
// Name: vehicle_wheelparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_wheelparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_wheelparams_t>(__formal: nullptr);
  vehicle_wheelparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B40
// Name: vehicle_suspensionparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_suspensionparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_suspensionparams_t>(__formal: nullptr);
  vehicle_suspensionparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B50
// Name: vehicle_axleparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_axleparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_axleparams_t>(__formal: nullptr);
  vehicle_axleparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B60
// Name: vehicle_steeringparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_steeringparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_steeringparams_t>(__formal: nullptr);
  vehicle_steeringparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B70
// Name: vehicle_engineparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicle_engineparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicle_engineparams_t>(__formal: nullptr);
  vehicle_engineparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B80
// Name: vehicleparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vehicleparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vehicleparams_t>(__formal: nullptr);
  vehicleparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027020
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cvehiclecontroller_t>(struct vphysics_save_cvehiclecontroller_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cvehiclecontroller_t>()
{
  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    nameHolder_17.m_pszBase = "vphysics_save_cvehiclecontroller_t";
    nameHolder_17.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_17.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_17.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_17.m_Names.m_Size = 0;
    nameHolder_17.m_Names.m_pElements = nullptr;
    nameHolder_17.m_nLenBase = 34;
    atexit(func: DataMapInit_vphysics_save_cvehiclecontroller_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cvehiclecontroller_t::m_DataMap.baseMap = nullptr;
  vphysics_save_cvehiclecontroller_t::m_DataMap.dataNumFields = 18;
  vphysics_save_cvehiclecontroller_t::m_DataMap.dataDesc = &dataDesc_17[1];
  return &vphysics_save_cvehiclecontroller_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100270A0
// Name: struct datamap_t __near * DataMapInit<struct vehicle_operatingparams_t>(struct vehicle_operatingparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_operatingparams_t>()
{
  if ( (_S2_2 & 1) == 0 )
  {
    _S2_2 |= 1u;
    nameHolder_18.m_pszBase = "vehicle_operatingparams_t";
    nameHolder_18.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_18.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_18.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_18.m_Names.m_Size = 0;
    nameHolder_18.m_Names.m_pElements = nullptr;
    nameHolder_18.m_nLenBase = 25;
    atexit(func: DataMapInit_vehicle_operatingparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_operatingparams_t::m_DataMap.baseMap = nullptr;
  if ( (_S2_2 & 2) == 0 )
  {
    _S2_2 |= 2u;
    dataDesc_18[7].pSaveRestoreOps = MaterialIndexDataOps();
    dataDesc_18[8].flags = 2;
    *(_QWORD *)&dataDesc_18[7].td = 0;
    *(_QWORD *)&dataDesc_18[7].override_field = 0;
    *(_QWORD *)&dataDesc_18[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_18[7].flatOffset[1] = 0;
    dataDesc_18[8].fieldSize = 1;
    dataDesc_18[9].fieldType = FIELD_INTEGER;
    dataDesc_18[10].fieldType = FIELD_INTEGER;
    *(_QWORD *)dataDesc_18[8].flatOffset = 0;
    dataDesc_18[9].fieldSize = 1;
    dataDesc_18[8].fieldSizeInBytes = 4;
    dataDesc_18[9].fieldSizeInBytes = 4;
    dataDesc_18[10].fieldSize = 1;
    dataDesc_18[10].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_18[9].flatOffset = 0;
    dataDesc_18[8].fieldTolerance = 0.0;
    dataDesc_18[9].fieldTolerance = 0.0;
    dataDesc_18[10].fieldTolerance = 0.0;
    dataDesc_18[11].fieldTolerance = 0.0;
    dataDesc_18[7].inputFunc = nullptr;
    dataDesc_18[8].fieldType = FIELD_FLOAT;
    dataDesc_18[8].fieldName = "steeringAngle";
    dataDesc_18[8].fieldOffset = 28;
    dataDesc_18[8].externalName = nullptr;
    dataDesc_18[8].pSaveRestoreOps = nullptr;
    dataDesc_18[8].inputFunc = nullptr;
    dataDesc_18[8].td = nullptr;
    dataDesc_18[8].override_field = nullptr;
    dataDesc_18[8].override_count = 0;
    *(_DWORD *)&dataDesc_18[8].flatGroup = 0;
    dataDesc_18[9].fieldName = "wheelsInContact";
    dataDesc_18[9].fieldOffset = 36;
    dataDesc_18[9].flags = 2;
    dataDesc_18[9].externalName = nullptr;
    dataDesc_18[9].pSaveRestoreOps = nullptr;
    dataDesc_18[9].inputFunc = nullptr;
    dataDesc_18[9].td = nullptr;
    dataDesc_18[9].override_field = nullptr;
    dataDesc_18[9].override_count = 0;
    *(_DWORD *)&dataDesc_18[9].flatGroup = 0;
    dataDesc_18[10].fieldName = "wheelsNotInContact";
    dataDesc_18[10].fieldOffset = 32;
    dataDesc_18[10].flags = 2;
    dataDesc_18[10].externalName = nullptr;
    dataDesc_18[10].pSaveRestoreOps = nullptr;
    dataDesc_18[10].inputFunc = nullptr;
    dataDesc_18[10].td = nullptr;
    dataDesc_18[10].override_field = nullptr;
    dataDesc_18[10].override_count = 0;
    *(_QWORD *)dataDesc_18[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_18[10].flatGroup = 0;
    dataDesc_18[11].fieldType = FIELD_BOOLEAN;
    dataDesc_18[11].fieldName = "isTorqueBoosting";
    dataDesc_18[11].fieldOffset = 40;
    *(_DWORD *)&dataDesc_18[11].fieldSize = 131073;
    dataDesc_18[11].externalName = nullptr;
    dataDesc_18[11].pSaveRestoreOps = nullptr;
    dataDesc_18[11].inputFunc = nullptr;
    dataDesc_18[11].td = nullptr;
    dataDesc_18[11].fieldSizeInBytes = 1;
    dataDesc_18[11].override_field = nullptr;
    dataDesc_18[11].override_count = 0;
    *(_QWORD *)dataDesc_18[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_18[11].flatGroup = 0;
  }
  vehicle_operatingparams_t::m_DataMap.dataNumFields = 11;
  vehicle_operatingparams_t::m_DataMap.dataDesc = &dataDesc_18[1];
  return &vehicle_operatingparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10027330
// Name: struct datamap_t __near * DataMapInit<struct vehicle_bodyparams_t>(struct vehicle_bodyparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_bodyparams_t>()
{
  if ( (_S3_1 & 1) == 0 )
  {
    _S3_1 |= 1u;
    nameHolder_19.m_pszBase = "vehicle_bodyparams_t";
    nameHolder_19.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_19.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_19.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_19.m_Names.m_Size = 0;
    nameHolder_19.m_Names.m_pElements = nullptr;
    nameHolder_19.m_nLenBase = 20;
    atexit(func: DataMapInit_vehicle_bodyparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_bodyparams_t::m_DataMap.baseMap = nullptr;
  vehicle_bodyparams_t::m_DataMap.dataNumFields = 8;
  vehicle_bodyparams_t::m_DataMap.dataDesc = &dataDesc_19[1];
  return &vehicle_bodyparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100273B0
// Name: struct datamap_t __near * DataMapInit<struct vehicle_wheelparams_t>(struct vehicle_wheelparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_wheelparams_t>()
{
  ISaveRestoreOps *v0; // eax

  if ( (_S4_0 & 1) == 0 )
  {
    _S4_0 |= 1u;
    nameHolder_20.m_pszBase = "vehicle_wheelparams_t";
    nameHolder_20.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_20.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_20.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_20.m_Names.m_Size = 0;
    nameHolder_20.m_Names.m_pElements = nullptr;
    nameHolder_20.m_nLenBase = 21;
    atexit(func: DataMapInit_vehicle_wheelparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_wheelparams_t::m_DataMap.baseMap = nullptr;
  if ( (_S4_0 & 2) == 0 )
  {
    _S4_0 |= 2u;
    dataDesc_20[7].pSaveRestoreOps = MaterialIndexDataOps();
    dataDesc_20[7].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_20[7].td = 0;
    *(_QWORD *)&dataDesc_20[7].override_field = 0;
    *(_QWORD *)&dataDesc_20[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_20[7].flatOffset[1] = 0;
    dataDesc_20[8].fieldType = FIELD_CUSTOM;
    dataDesc_20[8].fieldName = "brakeMaterialIndex";
    dataDesc_20[8].fieldOffset = 28;
    dataDesc_20[8].fieldSize = 1;
    dataDesc_20[8].flags = 2;
    dataDesc_20[8].externalName = nullptr;
    dataDesc_20[8].pSaveRestoreOps = MaterialIndexDataOps();
    dataDesc_20[8].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_20[8].td = 0;
    *(_QWORD *)&dataDesc_20[8].override_field = 0;
    *(_QWORD *)&dataDesc_20[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_20[8].flatOffset[1] = 0;
    dataDesc_20[9].fieldType = FIELD_CUSTOM;
    dataDesc_20[9].fieldName = "skidMaterialIndex";
    dataDesc_20[9].fieldOffset = 32;
    dataDesc_20[9].fieldSize = 1;
    dataDesc_20[9].flags = 2;
    dataDesc_20[9].externalName = nullptr;
    v0 = MaterialIndexDataOps();
    *(_QWORD *)&dataDesc_20[9].td = 0;
    *(_QWORD *)&dataDesc_20[9].override_field = 0;
    *(_QWORD *)&dataDesc_20[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_20[9].flatOffset[1] = 0;
    dataDesc_20[10].fieldTolerance = 0.0;
    dataDesc_20[9].pSaveRestoreOps = v0;
    dataDesc_20[9].inputFunc = nullptr;
    dataDesc_20[10].fieldType = FIELD_FLOAT;
    dataDesc_20[10].fieldName = "springAdditionalLength";
    dataDesc_20[10].fieldOffset = 36;
    *(_DWORD *)&dataDesc_20[10].fieldSize = 131073;
    dataDesc_20[10].externalName = nullptr;
    dataDesc_20[10].pSaveRestoreOps = nullptr;
    dataDesc_20[10].inputFunc = nullptr;
    dataDesc_20[10].td = nullptr;
    dataDesc_20[10].fieldSizeInBytes = 4;
    dataDesc_20[10].override_field = nullptr;
    dataDesc_20[10].override_count = 0;
    *(_QWORD *)dataDesc_20[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_20[10].flatGroup = 0;
  }
  vehicle_wheelparams_t::m_DataMap.dataNumFields = 10;
  vehicle_wheelparams_t::m_DataMap.dataDesc = &dataDesc_20[1];
  return &vehicle_wheelparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100275C0
// Name: struct datamap_t __near * DataMapInit<struct vehicle_suspensionparams_t>(struct vehicle_suspensionparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_suspensionparams_t>()
{
  if ( (_S5_0 & 1) == 0 )
  {
    _S5_0 |= 1u;
    nameHolder_21.m_pszBase = "vehicle_suspensionparams_t";
    nameHolder_21.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_21.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_21.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_21.m_Names.m_Size = 0;
    nameHolder_21.m_Names.m_pElements = nullptr;
    nameHolder_21.m_nLenBase = 26;
    atexit(func: DataMapInit_vehicle_suspensionparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_suspensionparams_t::m_DataMap.baseMap = nullptr;
  vehicle_suspensionparams_t::m_DataMap.dataNumFields = 5;
  vehicle_suspensionparams_t::m_DataMap.dataDesc = &dataDesc_21[1];
  return &vehicle_suspensionparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10027640
// Name: struct datamap_t __near * DataMapInit<struct vehicle_axleparams_t>(struct vehicle_axleparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_axleparams_t>()
{
  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    nameHolder_22.m_pszBase = "vehicle_axleparams_t";
    nameHolder_22.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_22.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_22.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_22.m_Names.m_Size = 0;
    nameHolder_22.m_Names.m_pElements = nullptr;
    nameHolder_22.m_nLenBase = 20;
    atexit(func: DataMapInit_vehicle_axleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_axleparams_t::m_DataMap.baseMap = nullptr;
  vehicle_axleparams_t::m_DataMap.dataNumFields = 8;
  vehicle_axleparams_t::m_DataMap.dataDesc = &dataDesc_22[1];
  return &vehicle_axleparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100276C0
// Name: struct datamap_t __near * DataMapInit<struct vehicle_steeringparams_t>(struct vehicle_steeringparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_steeringparams_t>()
{
  if ( (_S7_0 & 1) == 0 )
  {
    _S7_0 |= 1u;
    nameHolder_23.m_pszBase = "vehicle_steeringparams_t";
    nameHolder_23.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_23.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_23.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_23.m_Names.m_Size = 0;
    nameHolder_23.m_Names.m_pElements = nullptr;
    nameHolder_23.m_nLenBase = 24;
    atexit(func: DataMapInit_vehicle_steeringparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_steeringparams_t::m_DataMap.baseMap = nullptr;
  vehicle_steeringparams_t::m_DataMap.dataNumFields = 19;
  vehicle_steeringparams_t::m_DataMap.dataDesc = &dataDesc_23[1];
  return &vehicle_steeringparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10027740
// Name: struct datamap_t __near * DataMapInit<struct vehicle_engineparams_t>(struct vehicle_engineparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicle_engineparams_t>()
{
  if ( (_S8_0 & 1) == 0 )
  {
    _S8_0 |= 1u;
    nameHolder_24.m_pszBase = "vehicle_engineparams_t";
    nameHolder_24.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_24.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_24.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_24.m_Names.m_Size = 0;
    nameHolder_24.m_Names.m_pElements = nullptr;
    nameHolder_24.m_nLenBase = 22;
    atexit(func: DataMapInit_vehicle_engineparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicle_engineparams_t::m_DataMap.baseMap = nullptr;
  vehicle_engineparams_t::m_DataMap.dataNumFields = 19;
  vehicle_engineparams_t::m_DataMap.dataDesc = &dataDesc_24[1];
  return &vehicle_engineparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100277C0
// Name: struct datamap_t __near * DataMapInit<struct vehicleparams_t>(struct vehicleparams_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vehicleparams_t>()
{
  if ( (_S9_0 & 1) == 0 )
  {
    _S9_0 |= 1u;
    nameHolder_25.m_pszBase = "vehicleparams_t";
    nameHolder_25.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_25.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_25.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_25.m_Names.m_Size = 0;
    nameHolder_25.m_Names.m_pElements = nullptr;
    nameHolder_25.m_nLenBase = 15;
    atexit(func: DataMapInit_vehicleparams_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vehicleparams_t::m_DataMap.baseMap = nullptr;
  vehicleparams_t::m_DataMap.dataNumFields = 6;
  vehicleparams_t::m_DataMap.dataDesc = &dataDesc_25[1];
  return &vehicleparams_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C6B90
// Name: _dynamic_initializer_for__g_MeshFrameLocksPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MeshFrameLocksPool__()
{
  if ( ((unsigned __int8)&g_MeshFrameLocksPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MeshFrameLocksPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MeshFrameLocksPool__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6BC0
// Name: _dynamic_initializer_for__g_pMeshFrameLocks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_pMeshFrameLocks__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_pMeshFrameLocks);
  return atexit(func: dynamic_atexit_destructor_for__g_pMeshFrameLocks__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6BE0
// Name: _dynamic_initializer_for__g_MeshManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MeshManager__()
{
  CDataManagerBase::CDataManagerBase(this: &g_MeshManager, maxSize: 0x80000u);
  g_MeshManager.__vftable = (CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>_vtbl *)&CDataManager<CMeshInstance,virtualmeshlist_t,CMeshInstance *,CThreadFastMutex>::`vftable';
  g_MeshManager.m_mutex.m_ownerID = 0;
  g_MeshManager.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MeshManager__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6C20
// Name: _dynamic_initializer_for__s_BuildVirtualMeshMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_BuildVirtualMeshMutex__()
{
  s_BuildVirtualMeshMutex.m_ownerID = 0;
  s_BuildVirtualMeshMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C6C30
// Name: _dynamic_initializer_for__g_VisitHashPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VisitHashPool__()
{
  if ( ((unsigned __int8)&g_VisitHashPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VisitHashPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VisitHashPool__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6C60
// Name: _dynamic_initializer_for__g_IdentityIVPToHLWorld__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_IdentityIVPToHLWorld__()
{
  g_IdentityIVPToHLWorld.m_flMatVal[0][0] = g_PhysicsUnits.unitScaleMetersInv;
  g_IdentityIVPToHLWorld.m_flMatVal[1][2] = g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(g_IdentityIVPToHLWorld.m_flMatVal[2][1]) = LODWORD(g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
}

//------------------------------------------------------------------------------
// Address: 0x100C6C90
// Name: _dynamic_initializer_for__nullsurface__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *dynamic_initializer_for__nullsurface__()
{
  nullsurface.name = map_nullname;
  nullsurface.flags = 0;
  return map_nullname;
}

//------------------------------------------------------------------------------
// Address: 0x100C6CB0
// Name: _dynamic_initializer_for__s_VPhysPtrMap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_VPhysPtrMap__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_VPhysPtrMap__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6CC0
// Name: _dynamic_initializer_for__IVP_Controller_Independent::empty_list__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__IVP_Controller_Independent::empty_list__()
{
  return atexit(func: dynamic_atexit_destructor_for__IVP_Controller_Independent::empty_list__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6CD0
// Name: _dynamic_initializer_for__IVP_Environment_Manager::static_environment_manager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__IVP_Environment_Manager::static_environment_manager__()
{
  return atexit(func: dynamic_atexit_destructor_for__IVP_Environment_Manager::static_environment_manager__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6CE0
// Name: _dynamic_initializer_for__ivp_debugmanager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ivp_debugmanager__()
{
  memset(ivp_debugmanager.flag_list, 0, sizeof(ivp_debugmanager.flag_list));
  ivp_debugmanager.initialized = 1;
  return atexit(func: dynamic_atexit_destructor_for__ivp_debugmanager__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6D10
// Name: _dynamic_initializer_for__ivp_mindist_settings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__ivp_mindist_settings__()
{
  IVP_Mindist_Settings::set_collision_tolerance(this: &ivp_mindist_settings, t: 0.0099999998, gravLength: 9.8100004);
  ivp_mindist_settings.event_queue_min_delta_time_base = 1.0;
  ivp_mindist_settings.max_spawned_mindist_count = 1000;
}

//------------------------------------------------------------------------------
// Address: 0x100C6D60
// Name: _dynamic_initializer_for__ivp_surface_manager_ball_global__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ivp_surface_manager_ball_global__()
{
  ivp_surface_manager_ball_global.compact_ledge = (IVP_Compact_Ledge *)ivp_malloc_aligned(size: 32, alignment: 16);
  *(_QWORD *)ivp_surface_manager_ball_global.compact_ledge = 0;
  *((_QWORD *)ivp_surface_manager_ball_global.compact_ledge + 1) = 0;
  *(_QWORD *)&ivp_surface_manager_ball_global.compact_ledge[1].c_point_offset = 0;
  *((_QWORD *)&ivp_surface_manager_ball_global.compact_ledge[1] + 1) = 0;
  return atexit(func: dynamic_atexit_destructor_for__ivp_surface_manager_ball_global__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6DB0
// Name: _dynamic_initializer_for__s_TempMemoryPolyhedron_Buffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TempMemoryPolyhedron_Buffer__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_TempMemoryPolyhedron_Buffer__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6DC0
// Name: _dynamic_initializer_for__s_TempMemoryPolyhedron__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TempMemoryPolyhedron__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_TempMemoryPolyhedron__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6DD0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6E30
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6E60
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6E80
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100C6E90
// Name: _dynamic_initializer_for__LOG_HavokConsole__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LOG_HavokConsole__()
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))_LoggingSystem_RegisterLoggingChannel)(
             a1: "HavokConsole",
             a2: 0,
             a3: 0,
             a4: 0,
             a5: UNSPECIFIED_LOGGING_COLOR_140);
  LOG_HavokConsole = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6EB0
// Name: _dynamic_initializer_for__hk_Console::m_default_console_buffer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hk_Console::m_default_console_buffer__()
{
  return atexit(func: dynamic_atexit_destructor_for__hk_Console::m_default_console_buffer__);
}
