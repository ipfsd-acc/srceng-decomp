// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/phys_controller.cpp
// Functions: 59
// ============================================================

#include "game\server\phys_controller.h"

//------------------------------------------------------------------------------
// Address: 0x1017E500
// Name: public: virtual struct datamap_t __near * CPhysForce::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysForce::GetDataDescMap(CPhysForce *this)
{
  return &CPhysForce::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017E510
// Name: public: virtual void CPhysForce::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::OnRestore(CPhysForce *this)
{
  IPhysicsMotionController *m_pController; // ecx

  CBaseEntity::OnRestore(this);
  m_pController = this->m_pController;
  if ( m_pController != nullptr )
    m_pController->SetEventHandler(this: m_pController, a2: &this->m_integrator);
  this->m_wasRestored = true;
}

//------------------------------------------------------------------------------
// Address: 0x1017E540
// Name: public: virtual struct datamap_t __near * CPhysThruster::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysThruster::GetDataDescMap(CPhysThruster *this)
{
  return &CPhysThruster::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017E550
// Name: public: virtual struct datamap_t __near * CPhysTorque::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysTorque::GetDataDescMap(CPhysTorque *this)
{
  return &CPhysTorque::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017E560
// Name: public: virtual struct datamap_t __near * CPhysMotor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysMotor::GetDataDescMap(CPhysMotor *this)
{
  return &CPhysMotor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017E570
// Name: public: void CPhysMotor::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::InputTurnOff(CPhysMotor *this, inputdata_t *inputdata)
{
  this->m_motor.m_speed = 0.0;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1017E5A0
// Name: public: virtual void CPhysMotor::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::OnRestore(CPhysMotor *this)
{
  CBaseEntity::OnRestore(this);
  if ( this->m_pController != nullptr )
    this->m_pController->SetEventHandler(this: this->m_pController, a2: &this->m_motor);
}

//------------------------------------------------------------------------------
// Address: 0x1017E5D0
// Name: public: void CKeepUpright::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeepUpright::InputTurnOn(CKeepUpright *this, inputdata_t *inputdata)
{
  this->m_bActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x1017E5E0
// Name: public: void CKeepUpright::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeepUpright::InputTurnOff(CKeepUpright *this, inputdata_t *inputdata)
{
  this->m_bActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x1017E5F0
// Name: public: virtual struct datamap_t __near * CKeepUpright::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CKeepUpright::GetDataDescMap(CKeepUpright *this)
{
  return &CKeepUpright::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017E600
// Name: public: virtual enum IMotionEvent::simresult_e CConstantForceController::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
IMotionEvent::simresult_e __thiscall CConstantForceController::Simulate(
        CConstantForceController *this,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  *linear = this->m_linear;
  *angular = this->m_angular;
  return this->m_controlType;
}

//------------------------------------------------------------------------------
// Address: 0x1017E690
// Name: public: virtual void CPhysForce::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::Spawn(CPhysForce *this)
{
  this->m_integrator.m_controlType = (~LOBYTE(this->m_spawnflags.m_Value) & 8 | 4u) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x1017E6B0
// Name: void CalculateVelocityOffsetLocal(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalculateVelocityOffsetLocal(
        IPhysicsObject *pPhys,
        const Vector *forceLocal,
        const Vector *positionLocal,
        Vector *outVelLocal,
        Vector *outAngular)
{
  Vector velWorld; // [esp+4h] [ebp-24h] BYREF
  Vector forceWorld; // [esp+10h] [ebp-18h] BYREF
  Vector posWorld; // [esp+1Ch] [ebp-Ch] BYREF

  pPhys->LocalToWorld(this: pPhys, a2: &posWorld, a3: positionLocal);
  pPhys->LocalToWorldVector(this: pPhys, a2: &forceWorld, a3: forceLocal);
  pPhys->CalculateVelocityOffset(this: pPhys, a2: &forceWorld, a3: &posWorld, a4: &velWorld, a5: outAngular);
  pPhys->WorldToLocalVector(this: pPhys, a2: outVelLocal, a3: &velWorld);
}

//------------------------------------------------------------------------------
// Address: 0x1017E720
// Name: public: virtual void CPhysTorque::SetupForces(class IPhysicsObject __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysTorque::SetupForces(
        CPhysTorque *this@<ecx>,
        int a2@<esi>,
        IPhysicsObject *pPhys,
        Vector *linear,
        Vector *angular)
{
  float m_force; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  Vector axis_ls; // [esp+30h] [ebp-Ch] BYREF

  linear->x = 0.0;
  linear->y = 0.0;
  linear->z = 0.0;
  ((void (__thiscall *)(IPhysicsObject *, matrix3x4_t *, int))pPhys->GetPositionMatrix)(a1: pPhys, a2: &matrix, a3: a2);
  VectorIRotate(in1: &this->m_axis.x, in2: &matrix, out: &axis_ls.x);
  m_force = this->m_force;
  v7 = m_force * axis_ls.y;
  v8 = axis_ls.z * m_force;
  angular->x = axis_ls.x * m_force;
  angular->y = v7;
  angular->z = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1017E7A0
// Name: public: virtual enum IMotionEvent::simresult_e CMotorController::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CMotorController::Simulate@<eax>(
        CMotorController *this@<ecx>,
        int a2@<edi>,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  Vector *v10; // eax
  float v11; // xmm7_4
  float m_lastAcceleration; // xmm5_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm2_4
  float m_maxTorque; // xmm2_4
  float v19; // xmm2_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  matrix3x4_t matrix; // [esp+0h] [ebp-54h] BYREF
  _BYTE v27[12]; // [esp+30h] [ebp-24h] BYREF
  Vector currentRotAxis; // [esp+3Ch] [ebp-18h] BYREF
  Vector motorAxis_ls; // [esp+48h] [ebp-Ch] BYREF
  float currentSpeed; // [esp+68h] [ebp+14h]

  *linear = vec3_origin;
  *angular = vec3_origin;
  if ( this->m_speed == 0.0 )
    return 0;
  ((void (__thiscall *)(IPhysicsObject *, matrix3x4_t *, int))pObject->GetPositionMatrix)(
    a1: pObject,
    a2: &matrix,
    a3: a2);
  pObject->GetVelocity(this: pObject, a2: nullptr, a3: &currentRotAxis);
  VectorIRotate(in1: &this->m_axis.x, in2: &matrix, out: &motorAxis_ls.x);
  currentSpeed = (float)((float)(currentRotAxis.y * motorAxis_ls.y) + (float)(motorAxis_ls.x * currentRotAxis.x))
               + (float)(motorAxis_ls.z * currentRotAxis.z);
  v10 = pObject->GetInertia(this: pObject, result: v27);
  v11 = currentSpeed;
  m_lastAcceleration = this->m_lastAcceleration;
  v13 = (float)(fabs(v10->y * motorAxis_ls.y) + fabs(v10->x * motorAxis_ls.x)) + fabs(v10->z * motorAxis_ls.z);
  v14 = this->m_speed - currentSpeed;
  v15 = (float)(v14 * v13) * this->m_inertiaFactor;
  if ( fabs(m_lastAcceleration) > 0.0 )
  {
    v16 = currentSpeed - this->m_lastSpeed;
    if ( (float)(v16 * v14) <= 0.0 )
    {
      v11 = currentSpeed;
      if ( currentSpeed != 0.0 && fabs(v16 / m_lastAcceleration) < 0.05 )
        v15 = (float)(this->m_restistanceDamping * this->m_lastForce) + v15;
    }
    else
    {
      v17 = v16 / m_lastAcceleration;
      if ( v17 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
      v11 = currentSpeed;
      v15 = v15 + (float)((float)((float)(1.0 - v17) * this->m_lastForce) * this->m_restistanceDamping);
    }
  }
  m_maxTorque = this->m_maxTorque;
  if ( m_maxTorque != 0.0 )
  {
    if ( v15 > m_maxTorque || (LODWORD(m_maxTorque) ^= _mask__NegFloat_, m_maxTorque > v15) )
      v15 = m_maxTorque;
  }
  v19 = v15 / v13;
  x = motorAxis_ls.x;
  this->m_lastAcceleration = v19;
  y = motorAxis_ls.y;
  this->m_lastForce = v15;
  this->m_lastSpeed = v11;
  v22 = x * v15;
  v23 = y * v15;
  v24 = v15 * motorAxis_ls.z;
  angular->x = v22;
  angular->y = v23;
  angular->z = v24;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1017E9E0
// Name: public: void CPhysMotor::InputSetTargetSpeed(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::InputSetTargetSpeed(CPhysMotor *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  _fieldtypes fieldType; // ecx
  float flVal; // xmm1_4
  IPhysicsMotionController *m_pController; // ecx
  float m_spinUp; // xmm0_4

  pszValue = nullptr;
  fieldType = inputdata->value.fieldType;
  if ( fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flSpeed != flVal )
  {
    if ( fieldType == FIELD_FLOAT )
      pszValue = inputdata->value.iszVal.pszValue;
    LODWORD(this->m_flSpeed) = pszValue;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    m_pController = this->m_pController;
    this->m_lastTime = gpGlobals->curtime;
    m_pController->WakeObjects(this: m_pController);
    m_spinUp = this->m_spinUp;
    if ( m_spinUp == 0.0 )
      LODWORD(this->m_angularAcceleration) = LODWORD(this->m_flSpeed) & _mask__AbsFloat_;
    else
      LODWORD(this->m_angularAcceleration) = COERCE_UNSIGNED_INT(this->m_flSpeed / m_spinUp) & _mask__AbsFloat_;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EAB0
// Name: public: void CPhysMotor::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::TurnOn(CPhysMotor *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  void (__thiscall *Think)(CBaseEntity *); // edx

  m_Index = this->m_attachedObject.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr && m_pEntity[82].__vftable != nullptr )
    {
      this->m_pController->WakeObjects(this: this->m_pController);
      Think = this->Think;
      this->m_lastTime = gpGlobals->curtime - gpGlobals->interval_per_tick;
      Think(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EB20
// Name: public: virtual void CPhysMotor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::Think(CPhysMotor *this)
{
  CGlobalVars *v1; // edx
  float m_flSpeed; // xmm3_4
  float m_speed; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  v1 = gpGlobals;
  m_flSpeed = this->m_flSpeed;
  m_speed = this->m_motor.m_speed;
  v4 = (float)(gpGlobals->curtime - this->m_lastTime) * this->m_angularAcceleration;
  if ( (float)(m_flSpeed - m_speed) <= v4 )
  {
    if ( COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) <= (float)(m_flSpeed - m_speed) )
      v5 = this->m_flSpeed;
    else
      v5 = m_speed - v4;
  }
  else
  {
    v5 = m_speed + v4;
  }
  this->m_motor.m_speed = v5;
  this->m_lastTime = v1->curtime;
  if ( v5 != m_flSpeed )
    CBaseEntity::SetNextThink(this, thinkTime: v1->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1017EBB0
// Name: public: void CKeepUpright::InputSetAngularLimit(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeepUpright::InputSetAngularLimit(CKeepUpright *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_angularLimit) = inputdata->value.iVal;
  else
    this->m_angularLimit = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1017EC40
// Name: public: virtual void CKeepUpright::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeepUpright::Spawn(CKeepUpright *this)
{
  this->m_localTestAxis.x = 0.0;
  this->m_localTestAxis.y = 0.0;
  this->m_localTestAxis.z = 1.0;
  this->GetVectors(this, a2: nullptr, a3: nullptr, a4: &this->m_worldGoalAxis);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_bActive = (this->m_spawnflags.m_Value & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1017ECA0
// Name: class Vector ComputeRotSpeedToAlignAxes(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl ComputeRotSpeedToAlignAxes(
        Vector *result,
        const Vector *testAxis,
        const Vector *alignAxis,
        const Vector *currentSpeed,
        float damping,
        float scale,
        float maxSpeed)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float x; // xmm5_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  double v14; // st7
  float v15; // xmm0_4
  Vector angular; // [esp+0h] [ebp-18h] BYREF
  Vector rotationAxis; // [esp+Ch] [ebp-Ch] BYREF
  float len; // [esp+24h] [ebp+Ch]
  float lena; // [esp+24h] [ebp+Ch]

  y = testAxis->y;
  z = alignAxis->z;
  v9 = testAxis->z;
  v10 = alignAxis->y;
  x = alignAxis->x;
  rotationAxis.x = (float)(z * y) - (float)(v10 * v9);
  v12 = testAxis->x;
  rotationAxis.y = (float)(x * v9) - (float)(testAxis->x * z);
  rotationAxis.z = (float)(v12 * v10) - (float)(x * y);
  len = atan2(
          VectorNormalize(vec: &rotationAxis),
          (float)((float)((float)(v12 * x) + (float)(v10 * y)) + (float)(v9 * z)))
      * 57.29578;
  v13 = (float)((float)(currentSpeed->y * rotationAxis.y) + (float)(currentSpeed->x * rotationAxis.x))
      + (float)(currentSpeed->z * rotationAxis.z);
  angular.x = (float)((float)(rotationAxis.x * scale) * len) - (float)((float)(rotationAxis.x * damping) * v13);
  angular.y = (float)((float)(rotationAxis.y * scale) * len) - (float)((float)(rotationAxis.y * damping) * v13);
  angular.z = (float)((float)(rotationAxis.z * scale) * len) - (float)((float)(rotationAxis.z * damping) * v13);
  v14 = VectorNormalize(vec: &angular);
  if ( v14 <= maxSpeed )
  {
    lena = v14;
    v15 = lena;
  }
  else
  {
    v15 = maxSpeed;
  }
  result->x = angular.x * v15;
  result->y = angular.y * v15;
  result->z = angular.z * v15;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017EEB0
// Name: public: void CPhysForce::ActivateForce(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::ActivateForce(CPhysForce *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  IPhysicsObject *v10; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  IPhysicsMotionController *v17; // eax
  Vector angular; // [esp+4h] [ebp-18h] BYREF
  Vector linear; // [esp+10h] [ebp-Ch] BYREF

  m_Index = this->m_attachedObject.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      v10 = (IPhysicsObject *)m_pEntity[82].__vftable;
      if ( v10 != nullptr )
      {
        this->SetupForces(this, a2: v10, a3: &linear, a4: &angular);
        x = linear.x;
        y = linear.y;
        z = linear.z;
        v14 = angular.x;
        v15 = angular.y;
        v16 = angular.z;
        this->m_integrator.m_linear = linear;
        this->m_integrator.m_angular.x = v14;
        this->m_integrator.m_angular.y = v15;
        this->m_integrator.m_angular.z = v16;
        this->m_integrator.m_linearSave.x = x;
        this->m_integrator.m_linearSave.y = y;
        this->m_integrator.m_linearSave.z = z;
        this->m_integrator.m_angularSave.x = v14;
        this->m_integrator.m_angularSave.y = v15;
        this->m_integrator.m_angularSave.z = v16;
        v17 = physenv->CreateMotionController(this: physenv, a2: &this->m_integrator);
        this->m_pController = v17;
        v17->AttachObject(this: v17, a2: v10, a3: true);
        v10->Wake(this: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017EFC0
// Name: public: void CPhysForce::ForceOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::ForceOff(CPhysForce *this)
{
  IPhysicsMotionController *m_pController; // eax
  unsigned int m_Index; // esi
  int v4; // eax
  CEntInfo *v5; // ecx
  unsigned int v6; // esi
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v11; // ecx

  m_pController = this->m_pController;
  if ( m_pController != nullptr )
  {
    physenv->DestroyMotionController(this: physenv, a2: m_pController);
    this->m_pController = nullptr;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    m_Index = this->m_attachedObject.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = &g_pEntityList->m_EntPtrArray[v7];
        if ( v8 )
          m_pEntity = v9->m_pEntity;
        else
          m_pEntity = nullptr;
        v11 = m_pEntity[82].__vftable;
        if ( v11 != nullptr )
          (*((void (__thiscall **)(IHandleEntity_vtbl *))v11->dtr_IHandleEntity + 24))(a1: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F070
// Name: public: virtual void CPhysThruster::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysThruster::OnActivate(CPhysThruster *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CBaseEntity **v8; // eax
  CBaseEntity *v9; // edi
  matrix3x4_t worldToAttached; // [esp+4h] [ebp-6Ch] BYREF
  matrix3x4_t thrusterToAttached; // [esp+34h] [ebp-3Ch] BYREF
  QAngle angles; // [esp+64h] [ebp-Ch] BYREF
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  m_Index = this->m_attachedObject.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        v9 = *v8;
      else
        v9 = nullptr;
      if ( (v9->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
      MatrixInvert(in: &v9->m_rgflCoordinateFrame, out: &worldToAttached);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      ConcatTransforms(in1: &worldToAttached, in2: &this->m_rgflCoordinateFrame, out: &thrusterToAttached);
      MatrixGetColumn(in: &thrusterToAttached, column: 3, out: &this->m_localOrigin);
      if ( (this->m_spawnflags.m_Value & 8) != 0 )
      {
        MatrixAngles(a1: (int)this, src: (const VMatrix *)&thrusterToAttached, vAngles: &angles);
        CBaseEntity::SetLocalAngles(this, &angles);
      }
      if ( (this->m_spawnflags.m_Value & 0x20) != 0 )
      {
        this->m_localOrigin.x = 0.0;
        this->m_localOrigin.y = 0.0;
        this->m_localOrigin.z = 0.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F180
// Name: public: virtual void CPhysThruster::SetupForces(class IPhysicsObject __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysThruster::SetupForces(CPhysThruster *this, IPhysicsObject *pPhys, Vector *linear, Vector *angular)
{
  float m_force; // xmm0_4
  bool v6; // zf
  double v7; // st7
  Vector *v8; // ebx
  Vector *v9; // edi
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // edi
  Vector position; // [esp+8h] [ebp-18h] BYREF
  Vector thrustVector; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  AngleVectors(angles: &this->m_angRotation.m_Value, forward: &thrustVector);
  m_force = this->m_force;
  thrustVector.x = thrustVector.x * m_force;
  thrustVector.y = thrustVector.y * m_force;
  v6 = (this->m_spawnflags.m_Value & 0x10) == 0;
  thrustVector.z = thrustVector.z * m_force;
  if ( !v6 )
  {
    v7 = ((double (__thiscall *)(IPhysicsObject *))pPhys->GetMass)(a1: pPhys);
    thrustVector.x = thrustVector.x * v7;
    thrustVector.y = thrustVector.y * v7;
    thrustVector.z = v7 * thrustVector.z;
  }
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    v8 = angular;
    v9 = linear;
    CalculateVelocityOffsetLocal(
      pPhys,
      forceLocal: &thrustVector,
      positionLocal: &this->m_localOrigin,
      outVelLocal: linear,
      outAngular: angular);
  }
  else
  {
    m_Index = this->m_attachedObject.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    VectorTransform(in1: &this->m_localOrigin.x, in2: &m_pEntity->m_rgflCoordinateFrame, out: &position.x);
    v8 = angular;
    v9 = linear;
    pPhys->CalculateVelocityOffset(this: pPhys, a2: &thrustVector, a3: &position, a4: linear, a5: angular);
  }
  if ( (this->m_spawnflags.m_Value & 2) == 0 )
  {
    v9->x = 0.0;
    v9->y = 0.0;
    v9->z = 0.0;
  }
  if ( (this->m_spawnflags.m_Value & 4) == 0 )
  {
    v8->x = 0.0;
    v8->y = 0.0;
    v8->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F2E0
// Name: public: void CPhysMotor::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysMotor::InputTurnOn(CPhysMotor *this, inputdata_t *inputdata)
{
  CPhysMotor::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017F2F0
// Name: public: virtual CPhysMotor::~CPhysMotor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::~CPhysMotor(CPhysMotor *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v10; // esi
  __int16 v11; // ax

  this->__vftable = (CPhysMotor_vtbl *)&CPhysMotor::`vftable';
  m_Index = this->m_attachedObject.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr && this->m_pHinge != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      v10 = m_pEntity[82].__vftable;
      if ( v10 != nullptr )
      {
        v11 = (*((int (__thiscall **)(IHandleEntity_vtbl *))v10->dtr_IHandleEntity + 19))(a1: v10);
        (*((void (__thiscall **)(IHandleEntity_vtbl *, int))v10->dtr_IHandleEntity + 18))(a1: v10, a2: v11 & 0xFF7F);
      }
    }
  }
  physenv->DestroyConstraint(this: physenv, a2: this->m_pHinge);
  physenv->DestroyMotionController(this: physenv, a2: this->m_pController);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017F3D0
// Name: public: virtual void CPhysMotor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::Spawn(CPhysMotor *this)
{
  Vector *p_m_axis; // esi
  const char *DebugName; // eax

  p_m_axis = &this->m_motor.m_axis;
  this->m_motor.m_axis.x = this->m_motor.m_axis.x - this->m_vecOrigin.m_Value.x;
  this->m_motor.m_axis.y = this->m_motor.m_axis.y - this->m_vecOrigin.m_Value.y;
  this->m_motor.m_axis.z = this->m_motor.m_axis.z - this->m_vecOrigin.m_Value.z;
  if ( VectorNormalize(vec: &this->m_motor.m_axis) <= 1.0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    _Warning(a1: "phys_motor %s does not have a valid axis helper, and self-destructed!\n", DebugName);
    this->m_motor.m_speed = 0.0;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    UTIL_Remove(oldObj: this);
  }
  else
  {
    UTIL_SnapDirectionToAxis(direction: p_m_axis, epsilon: 0.0020000001);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F490
// Name: public: virtual void CPhysMotor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysMotor::Activate(CPhysMotor *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  CEntInfo *v7; // ecx
  IHandleEntity *m_pEntity; // ecx
  float m_spinUp; // xmm0_4
  IHandleEntity_vtbl *v10; // edi
  float *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  CEntInfo *v14; // edx
  unsigned int v15; // ecx
  int v16; // eax
  bool v17; // zf
  CEntInfo *v18; // eax
  IHandleEntity *v19; // eax
  IPhysicsObject *v20; // edi
  float z; // xmm0_4
  IPhysicsConstraint *v22; // eax
  unsigned __int16 v23; // ax
  IPhysicsMotionController *v24; // eax
  unsigned int v25; // edx
  IHandleEntity *v26; // ecx
  _DWORD v27[4]; // [esp+8h] [ebp-58h] BYREF
  matrix3x4_t matrix; // [esp+18h] [ebp-48h] BYREF
  char v29[12]; // [esp+48h] [ebp-18h] BYREF
  Vector motorAxis_ls; // [esp+54h] [ebp-Ch] BYREF

  CBaseEntity::Activate(this);
  m_Index = this->m_attachedObject.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    pszValue = this->m_nameAttach.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr && EntityByName->m_MoveType.m_Value == 6 )
    {
      v5 = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      v6 = v5;
      this->m_attachedObject.m_Index = v5;
      if ( v5 == -1 || (v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5])->m_SerialNumber != HIWORD(v6) )
        m_pEntity = nullptr;
      else
        m_pEntity = v7->m_pEntity;
      m_spinUp = this->m_spinUp;
      v10 = m_pEntity[82].__vftable;
      if ( m_spinUp == 0.0 )
        this->m_angularAcceleration = fabs(this->m_flSpeed);
      else
        this->m_angularAcceleration = fabs(this->m_flSpeed / m_spinUp);
      (*((void (__thiscall **)(IHandleEntity_vtbl *, matrix3x4_t *))v10->dtr_IHandleEntity + 49))(a1: v10, a2: &matrix);
      VectorIRotate(in1: &this->m_motor.m_axis.x, in2: &matrix, out: &motorAxis_ls.x);
      v11 = (float *)(*((int (__thiscall **)(IHandleEntity_vtbl *, char *))v10->dtr_IHandleEntity + 31))(
                       a1: v10,
                       a2: v29);
      this->m_motor.m_maxTorque = (float)((float)((float)(fabs(v11[1] * motorAxis_ls.y) + fabs(motorAxis_ls.x * *v11))
                                                + fabs(v11[2] * motorAxis_ls.z))
                                        * this->m_motor.m_inertiaFactor)
                                * (float)(this->m_additionalAcceleration + this->m_angularAcceleration);
      this->m_motor.m_restistanceDamping = 1.0;
    }
  }
  v12 = this->m_attachedObject.m_Index;
  if ( v12 != -1 )
  {
    v13 = (unsigned __int16)v12;
    v14 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v12];
    v15 = HIWORD(v12);
    if ( v14->m_SerialNumber == v15 && v14->m_pEntity != nullptr )
    {
      v16 = v13;
      v17 = g_pEntityList->m_EntPtrArray[v16].m_SerialNumber == v15;
      v18 = &g_pEntityList->m_EntPtrArray[v16];
      if ( v17 )
        v19 = v18->m_pEntity;
      else
        v19 = nullptr;
      v20 = (IPhysicsObject *)v19[82].__vftable;
      if ( (this->m_spawnflags.m_Value & 4) != 0 )
      {
        if ( this->m_pHinge == nullptr )
        {
          memset(&matrix.m_flMatVal[0][2], 0, 16);
          *(_QWORD *)&matrix.m_flMatVal[2][0] = 0x3F80000000000000LL;
          v27[3] = LODWORD(this->m_motor.m_axis.x);
          *(_QWORD *)&matrix.m_flMatVal[0][0] = *(_QWORD *)&this->m_motor.m_axis.y;
          v27[0] = LODWORD(this->m_vecOrigin.m_Value.x);
          v27[1] = LODWORD(this->m_vecOrigin.m_Value.y);
          z = this->m_vecOrigin.m_Value.z;
          *(_QWORD *)&matrix.m_flMatVal[1][2] = 1065353216;
          matrix.m_flMatVal[2][2] = 1.0;
          LOBYTE(matrix.m_flMatVal[2][3]) = 1;
          *(float *)&v27[2] = z;
          v22 = physenv->CreateHingeConstraint(this: physenv, a2: g_PhysWorldObject, a3: v20, a4: 0, a5: v27);
          this->m_pHinge = v22;
          v22->SetGameData(this: v22, a2: this);
          v23 = v20->GetGameFlags(this: v20);
          v20->SetGameFlags(this: v20, a2: v23 | 0x80);
        }
        if ( (this->m_spawnflags.m_Value & 2) != 0 )
          PhysDisableEntityCollisions(pObject0: g_PhysWorldObject, pObject1: v20);
      }
      else
      {
        this->m_pHinge = nullptr;
      }
      if ( this->m_pController == nullptr )
      {
        v24 = physenv->CreateMotionController(this: physenv, a2: &this->m_motor);
        this->m_pController = v24;
        v25 = this->m_attachedObject.m_Index;
        if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
          v26 = nullptr;
        else
          v26 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
        v24->AttachObject(this: v24, a2: (IPhysicsObject *)v26[82].__vftable, a3: false);
        if ( (this->m_spawnflags.m_Value & 1) != 0 )
          CPhysMotor::TurnOn(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F820
// Name: public: virtual void CKeepUpright::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeepUpright::Activate(CKeepUpright *this)
{
  IPhysicsMotionController *m_pController; // ecx
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IPhysicsObject *PhysicsObjectByName; // edi
  const char *pszValue; // eax
  IPhysicsMotionController *v12; // eax

  CBaseEntity::Activate(this);
  m_pController = this->m_pController;
  if ( m_pController != nullptr )
  {
    m_pController->SetEventHandler(this: m_pController, a2: &this->IMotionEvent);
  }
  else
  {
    m_Index = this->m_attachedObject.m_Index;
    if ( m_Index != -1
      && (v4 = (unsigned __int16)m_Index,
          v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v6 = HIWORD(m_Index),
          v5->m_SerialNumber == v6)
      && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        PhysicsObjectByName = (IPhysicsObject *)v9->m_pEntity[82].__vftable;
      else
        PhysicsObjectByName = (IPhysicsObject *)MEMORY[0x148];
    }
    else
    {
      pszValue = this->m_nameAttach.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      PhysicsObjectByName = FindPhysicsObjectByName(pName: pszValue, pErrorEntity: this);
    }
    if ( PhysicsObjectByName != nullptr )
    {
      v12 = physenv->CreateMotionController(this: physenv, a2: &this->IMotionEvent);
      this->m_pController = v12;
      v12->AttachObject(this: v12, a2: PhysicsObjectByName, a3: false);
    }
    else
    {
      UTIL_Remove(oldObj: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017F8F0
// Name: public: virtual enum IMotionEvent::simresult_e CKeepUpright::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CKeepUpright::Simulate@<eax>(
        CKeepUpright *this@<ecx>,
        int a2@<edi>,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  Vector *v9; // eax
  Vector *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  double z; // st7
  float v14; // xmm1_4
  Vector *v15; // eax
  float x; // xmm1_4
  double v17; // st7
  matrix3x4_t matrix; // [esp+1Ch] [ebp-54h] BYREF
  Vector v19; // [esp+4Ch] [ebp-24h] BYREF
  Vector currentLocalTargetAxis; // [esp+58h] [ebp-18h] BYREF
  Vector angVel; // [esp+64h] [ebp-Ch] BYREF
  float invDeltaTime; // [esp+84h] [ebp+14h]

  if ( LOBYTE(this->m_Network.m_PVSInfo.m_vCenter[1]) == 0 )
    return 0;
  linear->x = 0.0;
  linear->y = 0.0;
  linear->z = 0.0;
  ((void (__thiscall *)(IPhysicsObject *, _DWORD, Vector *, int))pObject->GetVelocity)(
    a1: pObject,
    a2: 0,
    a3: &angVel,
    a4: a2);
  pObject->GetPositionMatrix(this: pObject, a2: &matrix);
  VectorIRotate(in1: (const float *)&this->m_pfnMoveDone, in2: &matrix, out: &currentLocalTargetAxis.x);
  invDeltaTime = 1.0 / deltaTime;
  if ( BYTE1(this->m_Network.m_PVSInfo.m_vCenter[1]) != 0 )
  {
    v9 = ComputeRotSpeedToAlignAxes(
           result: &v19,
           testAxis: (const Vector *)&this->m_Network.IEventRegisterCallback,
           alignAxis: &currentLocalTargetAxis,
           currentSpeed: &angVel,
           damping: 0.0,
           scale: 1.0 / deltaTime,
           maxSpeed: this->m_Network.m_PVSInfo.m_vCenter[0]);
    v10 = angular;
    v11 = 1.0 / deltaTime;
    angular->x = v9->x;
    v12 = angular->x - angVel.x;
    angular->y = v9->y;
    z = v9->z;
    angular->x = v12 * invDeltaTime;
    angular->z = z;
    angular->y = (float)(angular->y - angVel.y) * invDeltaTime;
    v14 = angular->z - angVel.z;
  }
  else
  {
    v15 = ComputeRotSpeedToAlignAxes(
            result: &v19,
            testAxis: (const Vector *)&this->m_Network.IEventRegisterCallback,
            alignAxis: &currentLocalTargetAxis,
            currentSpeed: &angVel,
            damping: 1.0,
            scale: 1.0 / deltaTime,
            maxSpeed: this->m_Network.m_PVSInfo.m_vCenter[0]);
    v10 = angular;
    v11 = 1.0 / deltaTime;
    angular->x = v15->x;
    x = angular->x;
    angular->y = v15->y;
    v17 = v15->z;
    angular->x = x * invDeltaTime;
    angular->z = v17;
    angular->y = invDeltaTime * angular->y;
    v14 = angular->z;
  }
  v10->z = v14 * v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017FA80
// Name: public: void CPhysForce::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysForce::InputDeactivate(CPhysForce *this, inputdata_t *inputdata)
{
  CPhysForce::ForceOff(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017FA90
// Name: public: void CPhysForce::ForceOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::ForceOn(CPhysForce *this)
{
  float m_forceTime; // xmm0_4

  if ( this->m_pController == nullptr )
  {
    CPhysForce::ActivateForce(this);
    m_forceTime = this->m_forceTime;
    if ( m_forceTime != 0.0 )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + m_forceTime, szContext: nullptr);
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPhysForce::ForceOff,
        thinkTime: 0.0,
        szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FAF0
// Name: public: void CPhysForce::ScaleForce(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::ScaleForce(CPhysForce *this, float scale)
{
  float m_forceTime; // xmm0_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm3_4

  if ( this->m_pController == nullptr )
  {
    CPhysForce::ActivateForce(this);
    m_forceTime = this->m_forceTime;
    if ( m_forceTime != 0.0 )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + m_forceTime, szContext: nullptr);
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPhysForce::ForceOff,
        thinkTime: 0.0,
        szContext: nullptr);
    }
  }
  y = this->m_integrator.m_linearSave.y;
  z = this->m_integrator.m_linearSave.z;
  this->m_integrator.m_linear.x = this->m_integrator.m_linearSave.x * scale;
  this->m_integrator.m_linear.y = y * scale;
  this->m_integrator.m_linear.z = z * scale;
  v6 = this->m_integrator.m_angularSave.y * scale;
  v7 = this->m_integrator.m_angularSave.z * scale;
  this->m_integrator.m_angular.x = this->m_integrator.m_angularSave.x * scale;
  this->m_integrator.m_angular.y = v6;
  this->m_integrator.m_angular.z = v7;
  this->m_pController->WakeObjects(this: this->m_pController);
}

//------------------------------------------------------------------------------
// Address: 0x1017FD40
// Name: public: virtual void CPhysForce::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::Activate(CPhysForce *this)
{
  unsigned int m_Index; // eax
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax

  CBaseEntity::Activate(this);
  if ( this->m_pController != nullptr )
    this->m_pController->WakeObjects(this: this->m_pController);
  if ( !this->m_wasRestored )
  {
    m_Index = this->m_attachedObject.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      pszValue = this->m_nameAttach.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: pszValue,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      if ( EntityByName != nullptr )
        this->m_attachedObject.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      else
        this->m_attachedObject.m_Index = -1;
    }
    this->OnActivate(this);
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
      CPhysForce::ForceOn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FE00
// Name: public: void CPhysForce::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::InputActivate(CPhysForce *this, inputdata_t *inputdata)
{
  float m_forceTime; // xmm0_4

  if ( this->m_pController == nullptr )
  {
    CPhysForce::ActivateForce(this);
    m_forceTime = this->m_forceTime;
    if ( m_forceTime != 0.0 )
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + m_forceTime, szContext: nullptr);
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CPhysForce::ForceOff,
        thinkTime: 0.0,
        szContext: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FE60
// Name: public: void CPhysForce::InputForceScale(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysForce::InputForceScale(CPhysForce *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    CPhysForce::ScaleForce(this, scale: inputdata->value.flVal);
  else
    CPhysForce::ScaleForce(this, scale: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1017FEA0
// Name: public: virtual void CPhysTorque::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysTorque::Spawn(CPhysTorque *this@<ecx>, int a2@<ebp>)
{
  int v3; // edi
  edict_t *m_pPev; // ecx
  unsigned int v5; // edi
  edict_t *v6; // ecx

  v3 = this->m_spawnflags.m_Value | 0x14;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  v5 = this->m_spawnflags.m_Value & 0xFFFFFFFD;
  if ( this->m_spawnflags.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v5;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  this->m_axis.x = this->m_axis.x - this->m_vecAbsOrigin.x;
  this->m_axis.y = this->m_axis.y - this->m_vecAbsOrigin.y;
  this->m_axis.z = this->m_axis.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &this->m_axis);
  UTIL_SnapDirectionToAxis(direction: &this->m_axis, epsilon: 0.0020000001);
  this->m_integrator.m_controlType = (~LOBYTE(this->m_spawnflags.m_Value) & 8 | 4u) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x10180010
// Name: class CBaseEntity __near * CreateKeepUpright(class Vector const __near &,class QAngle const __near &,class CBaseEntity __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CreateKeepUpright(
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        CBaseEntity *pOwner,
        float flAngularLimit,
        bool bActive)
{
  CBaseEntity *result; // eax
  CBaseEntity *v6; // ebx
  int v7; // esi
  CBaseEdict *v8; // ecx

  result = CBaseEntity::Create(szName: "phys_keepupright", vecOrigin, vecAngles, pOwner);
  v6 = result;
  if ( result != nullptr )
  {
    if ( pOwner != nullptr )
      *(_DWORD *)&result[1].m_Network.m_PVSInfo.m_nAreaNum = pOwner->GetRefEHandle(this: pOwner)->m_Index;
    else
      *(_DWORD *)&result[1].m_Network.m_PVSInfo.m_nAreaNum = -1;
    v6[1].m_Network.m_PVSInfo.m_vCenter[0] = flAngularLimit;
    if ( !bActive )
    {
      v7 = v6->m_spawnflags.m_Value | 1;
      if ( v6->m_spawnflags.m_Value != v7 )
      {
        if ( v6->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v6->m_Network + 76) |= 1u;
        }
        else
        {
          v8 = &v6->m_Network.m_pPev->CBaseEdict;
          if ( v8 != nullptr )
            CBaseEdict::StateChanged(this: v8, offset: 0x2F8u);
        }
        v6->m_spawnflags.m_Value = v7;
      }
    }
    v6->Spawn(this: v6);
    v6->Activate(this: v6);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406C40
// Name: CConstantForceController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CConstantForceController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CConstantForceController>(__formal: nullptr);
  CConstantForceController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406C50
// Name: CPhysForce_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysForce_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysForce>(__formal: nullptr);
  CPhysForce_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406C80
// Name: CPhysThruster_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysThruster_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysThruster>(__formal: nullptr);
  CPhysThruster_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406C90
// Name: CPhysTorque_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysTorque_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysTorque>(__formal: nullptr);
  CPhysTorque_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406CC0
// Name: CMotorController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CMotorController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CMotorController>(__formal: nullptr);
  CMotorController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406CD0
// Name: CPhysMotor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysMotor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysMotor>(__formal: nullptr);
  CPhysMotor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406D20
// Name: CKeepUpright_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CKeepUpright_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CKeepUpright>(__formal: nullptr);
  CKeepUpright_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017EE30
// Name: class CKeepUpright __near * _CreateEntityTemplate<class CKeepUpright>(class CKeepUpright __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CKeepUpright *__cdecl _CreateEntityTemplate<CKeepUpright>(CKeepUpright *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[1].__vftable = (CBaseEntity_vtbl *)&IMotionEvent::`vftable';
    v3->__vftable = (CBaseEntity_vtbl *)&CKeepUpright::`vftable'{for `CPointEntity'};
    v3[1].__vftable = (CBaseEntity_vtbl *)&CKeepUpright::`vftable'{for `IMotionEvent'};
    v3[1].m_Network.m_PVSInfo.m_vCenter[0] = 15.0;
    *(_DWORD *)&v3[1].m_Network.m_PVSInfo.m_nAreaNum = -1;
    BYTE1(v3[1].m_Network.m_PVSInfo.m_vCenter[1]) = 0;
    v3->PostConstructor(this: v3, a2: className);
    return (CKeepUpright *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FBE0
// Name: class CPhysThruster __near * _CreateEntityTemplate<class CPhysThruster>(class CPhysThruster __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysThruster *__cdecl _CreateEntityTemplate<CPhysThruster>(CPhysThruster *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)-1;
    v3[1].m_Network.m_pPev = (edict_t *)&CConstantForceController::`vftable';
    v3[1].__vftable = nullptr;
    LOBYTE(v3[1].m_Network.m_pOuter) = 0;
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysThruster::`vftable';
    v3->PostConstructor(this: v3, a2: className);
    return (CPhysThruster *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FC60
// Name: class CPhysTorque __near * _CreateEntityTemplate<class CPhysTorque>(class CPhysTorque __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysTorque *__cdecl _CreateEntityTemplate<CPhysTorque>(CPhysTorque *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[1].m_Network.__vftable = (IEventRegisterCallback_vtbl *)-1;
    v3[1].m_Network.m_pPev = (edict_t *)&CConstantForceController::`vftable';
    v3[1].__vftable = nullptr;
    LOBYTE(v3[1].m_Network.m_pOuter) = 0;
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysTorque::`vftable';
    v3->PostConstructor(this: v3, a2: className);
    return (CPhysTorque *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017FCE0
// Name: class CPhysMotor __near * _CreateEntityTemplate<class CPhysMotor>(class CPhysMotor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysMotor *__cdecl _CreateEntityTemplate<CPhysMotor>(CPhysMotor *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3A0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CPhysMotor::`vftable';
    v3[214] = -1;
    v3[221] = &CMotorController::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPhysMotor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101800D0
// Name: struct datamap_t __near * DataMapInit<class CConstantForceController>(class CConstantForceController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CConstantForceController>()
{
  if ( (_S2_161 & 1) == 0 )
  {
    _S2_161 |= 1u;
    nameHolder_289.m_pszBase = "CConstantForceController";
    nameHolder_289.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_289.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_289.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_289.m_Names.m_Size = 0;
    nameHolder_289.m_Names.m_pElements = nullptr;
    nameHolder_289.m_nLenBase = 24;
    atexit(func: DataMapInit_CConstantForceController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CConstantForceController::m_DataMap.baseMap = nullptr;
  CConstantForceController::m_DataMap.dataNumFields = 5;
  CConstantForceController::m_DataMap.dataDesc = &dataDesc_276[1];
  return &CConstantForceController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180150
// Name: struct datamap_t __near * DataMapInit<class CPhysForce>(class CPhysForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysForce>()
{
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S3_85 & 1) == 0 )
  {
    _S3_85 |= 1u;
    nameHolder_290.m_pszBase = "CPhysForce";
    nameHolder_290.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_290.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_290.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_290.m_Names.m_Size = 0;
    nameHolder_290.m_Names.m_pElements = nullptr;
    nameHolder_290.m_nLenBase = 10;
    atexit(func: DataMapInit_CPhysForce__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysForce::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_85 & 2) == 0 )
  {
    _S3_85 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    *(_QWORD *)dataDesc_277[2].flatOffset = 0;
    dataDesc_277[1].pSaveRestoreOps = PhysObjSaveRestoreOps;
    *(_QWORD *)dataDesc_277[3].flatOffset = 0;
    dataDesc_277[2].fieldSize = 1;
    dataDesc_277[2].flags = 6;
    dataDesc_277[3].flags = 6;
    dataDesc_277[4].flags = 6;
    *(_QWORD *)&dataDesc_277[1].td = 0;
    *(_QWORD *)&dataDesc_277[1].override_field = 0;
    *(_QWORD *)&dataDesc_277[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_277[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_277[4].flatOffset = 0;
    dataDesc_277[1].inputFunc = nullptr;
    dataDesc_277[2].fieldType = FIELD_STRING;
    dataDesc_277[2].fieldName = "m_nameAttach";
    dataDesc_277[2].fieldOffset = 856;
    dataDesc_277[2].externalName = "attach1";
    dataDesc_277[2].pSaveRestoreOps = nullptr;
    dataDesc_277[2].inputFunc = nullptr;
    dataDesc_277[2].td = nullptr;
    dataDesc_277[2].fieldSizeInBytes = 4;
    dataDesc_277[2].override_field = nullptr;
    dataDesc_277[2].override_count = 0;
    dataDesc_277[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_277[2].flatGroup = 0;
    dataDesc_277[3].fieldType = FIELD_FLOAT;
    dataDesc_277[3].fieldName = "m_force";
    dataDesc_277[3].fieldOffset = 860;
    dataDesc_277[3].fieldSize = 1;
    dataDesc_277[3].externalName = "force";
    dataDesc_277[3].pSaveRestoreOps = nullptr;
    dataDesc_277[3].inputFunc = nullptr;
    dataDesc_277[3].td = nullptr;
    dataDesc_277[3].fieldSizeInBytes = 4;
    dataDesc_277[3].override_field = nullptr;
    dataDesc_277[3].override_count = 0;
    dataDesc_277[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_277[3].flatGroup = 0;
    dataDesc_277[4].fieldType = FIELD_FLOAT;
    dataDesc_277[4].fieldName = "m_forceTime";
    dataDesc_277[4].fieldOffset = 864;
    dataDesc_277[4].fieldSize = 1;
    dataDesc_277[4].externalName = "forcetime";
    dataDesc_277[4].pSaveRestoreOps = nullptr;
    dataDesc_277[4].inputFunc = nullptr;
    dataDesc_277[4].td = nullptr;
    dataDesc_277[4].fieldSizeInBytes = 4;
    dataDesc_277[4].override_field = nullptr;
    dataDesc_277[4].override_count = 0;
    dataDesc_277[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_277[4].flatGroup = 0;
    dataDesc_277[5].fieldType = FIELD_EHANDLE;
    dataDesc_277[5].fieldName = "m_attachedObject";
    dataDesc_277[5].fieldOffset = 868;
    dataDesc_277[5].fieldSize = 1;
    dataDesc_277[5].flags = 2;
    dataDesc_277[5].externalName = nullptr;
    dataDesc_277[5].pSaveRestoreOps = nullptr;
    dataDesc_277[5].inputFunc = nullptr;
    dataDesc_277[5].td = nullptr;
    dataDesc_277[5].fieldSizeInBytes = 4;
    dataDesc_277[5].override_field = nullptr;
    dataDesc_277[5].override_count = 0;
    dataDesc_277[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_277[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_277[5].flatGroup = 0;
    dataDesc_277[6].fieldTolerance = 0.0;
    dataDesc_277[6].fieldSize = 1;
    *(_QWORD *)dataDesc_277[6].flatOffset = 0;
    dataDesc_277[6].flags = 2;
    dataDesc_277[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_277[7].td = 0;
    *(_QWORD *)&dataDesc_277[7].override_field = 0;
    *(_QWORD *)&dataDesc_277[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_277[7].flatOffset[1] = 0;
    dataDesc_277[7].flags = 8;
    dataDesc_277[8].fieldSize = 1;
    dataDesc_277[8].flags = 8;
    *(_QWORD *)&dataDesc_277[8].td = 0;
    *(_QWORD *)&dataDesc_277[8].override_field = 0;
    *(_QWORD *)&dataDesc_277[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_277[8].flatOffset[1] = 0;
    dataDesc_277[6].fieldType = FIELD_EMBEDDED;
    dataDesc_277[6].fieldName = "m_integrator";
    dataDesc_277[6].fieldOffset = 876;
    dataDesc_277[6].externalName = nullptr;
    dataDesc_277[6].pSaveRestoreOps = nullptr;
    dataDesc_277[6].inputFunc = nullptr;
    dataDesc_277[6].td = &CConstantForceController::m_DataMap;
    dataDesc_277[6].fieldSizeInBytes = 56;
    dataDesc_277[6].override_field = nullptr;
    dataDesc_277[6].override_count = 0;
    *(_DWORD *)&dataDesc_277[6].flatGroup = 0;
    dataDesc_277[7].fieldType = FIELD_VOID;
    dataDesc_277[7].fieldName = "InputActivate";
    dataDesc_277[7].fieldOffset = 0;
    dataDesc_277[7].externalName = "Activate";
    dataDesc_277[7].pSaveRestoreOps = nullptr;
    dataDesc_277[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysForce::InputActivate;
    dataDesc_277[8].fieldType = FIELD_VOID;
    dataDesc_277[8].fieldName = "InputDeactivate";
    dataDesc_277[8].fieldOffset = 0;
    dataDesc_277[8].externalName = "Deactivate";
    dataDesc_277[8].pSaveRestoreOps = nullptr;
    dataDesc_277[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysForce::InputDeactivate;
    dataDesc_277[9].fieldType = FIELD_FLOAT;
    dataDesc_277[9].fieldName = "InputForceScale";
    dataDesc_277[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_277[9].fieldSize = 524289;
    dataDesc_277[9].externalName = "scale";
    dataDesc_277[9].pSaveRestoreOps = nullptr;
    dataDesc_277[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysForce::InputForceScale;
    *(_QWORD *)&dataDesc_277[9].td = 0;
    *(_QWORD *)&dataDesc_277[9].override_field = 0;
    *(_QWORD *)&dataDesc_277[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_277[9].flatOffset[1] = 0;
    dataDesc_277[10].fieldType = FIELD_VOID;
    dataDesc_277[10].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_290,
                                   pszIdentifier: "ForceOff");
    dataDesc_277[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_277[10].fieldSize = 2097153;
    dataDesc_277[10].externalName = nullptr;
    dataDesc_277[10].pSaveRestoreOps = nullptr;
    dataDesc_277[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysForce::ForceOff;
    *(_QWORD *)&dataDesc_277[10].td = 0;
    *(_QWORD *)&dataDesc_277[10].override_field = 0;
    *(_QWORD *)&dataDesc_277[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_277[10].flatOffset[1] = 0;
  }
  CPhysForce::m_DataMap.dataNumFields = 10;
  CPhysForce::m_DataMap.dataDesc = &dataDesc_277[1];
  return &CPhysForce::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180600
// Name: struct datamap_t __near * DataMapInit<class CPhysThruster>(class CPhysThruster __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysThruster>()
{
  if ( (_S4_42 & 1) == 0 )
  {
    _S4_42 |= 1u;
    nameHolder_291.m_pszBase = "CPhysThruster";
    nameHolder_291.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_291.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_291.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_291.m_Names.m_Size = 0;
    nameHolder_291.m_Names.m_pElements = nullptr;
    nameHolder_291.m_nLenBase = 13;
    atexit(func: DataMapInit_CPhysThruster__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysThruster::m_DataMap.baseMap = &CPhysForce::m_DataMap;
  CPhysThruster::m_DataMap.dataNumFields = 1;
  CPhysThruster::m_DataMap.dataDesc = &dataDesc_278[1];
  return &CPhysThruster::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180670
// Name: struct datamap_t __near * DataMapInit<class CPhysTorque>(class CPhysTorque __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysTorque>()
{
  if ( (_S5_20 & 1) == 0 )
  {
    _S5_20 |= 1u;
    nameHolder_292.m_pszBase = "CPhysTorque";
    nameHolder_292.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_292.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_292.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_292.m_Names.m_Size = 0;
    nameHolder_292.m_Names.m_pElements = nullptr;
    nameHolder_292.m_nLenBase = 11;
    atexit(func: DataMapInit_CPhysTorque__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysTorque::m_DataMap.baseMap = &CPhysForce::m_DataMap;
  CPhysTorque::m_DataMap.dataNumFields = 1;
  CPhysTorque::m_DataMap.dataDesc = &dataDesc_279[1];
  return &CPhysTorque::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101806E0
// Name: struct datamap_t __near * DataMapInit<class CMotorController>(class CMotorController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMotorController>()
{
  if ( (_S6_15 & 1) == 0 )
  {
    _S6_15 |= 1u;
    nameHolder_293.m_pszBase = "CMotorController";
    nameHolder_293.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_293.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_293.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_293.m_Names.m_Size = 0;
    nameHolder_293.m_Names.m_pElements = nullptr;
    nameHolder_293.m_nLenBase = 16;
    atexit(func: DataMapInit_CMotorController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMotorController::m_DataMap.baseMap = nullptr;
  CMotorController::m_DataMap.dataNumFields = 8;
  CMotorController::m_DataMap.dataDesc = &dataDesc_280[1];
  return &CMotorController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180760
// Name: struct datamap_t __near * DataMapInit<class CPhysMotor>(class CPhysMotor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysMotor>()
{
  if ( (_S7_8 & 1) == 0 )
  {
    _S7_8 |= 1u;
    nameHolder_294.m_pszBase = "CPhysMotor";
    nameHolder_294.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_294.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_294.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_294.m_Names.m_Size = 0;
    nameHolder_294.m_Names.m_pElements = nullptr;
    nameHolder_294.m_nLenBase = 10;
    atexit(func: DataMapInit_CPhysMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysMotor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S7_8 & 2) == 0 )
  {
    _S7_8 |= 2u;
    dataDesc_281[7].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_281[7].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_281[7].td = 0;
    *(_QWORD *)&dataDesc_281[7].override_field = 0;
    *(_QWORD *)&dataDesc_281[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_281[7].flatOffset[1] = 0;
    dataDesc_281[8].fieldType = FIELD_CUSTOM;
    dataDesc_281[8].fieldName = "m_pController";
    dataDesc_281[8].fieldOffset = 880;
    dataDesc_281[8].fieldSize = 1;
    dataDesc_281[8].flags = 2;
    dataDesc_281[8].externalName = nullptr;
    dataDesc_281[8].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    *(_QWORD *)&dataDesc_281[8].td = 0;
    *(_QWORD *)&dataDesc_281[8].override_field = 0;
    *(_QWORD *)&dataDesc_281[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_281[8].flatOffset[1] = 0;
    dataDesc_281[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_281[9].td = 0;
    *(_QWORD *)&dataDesc_281[9].override_field = 0;
    *(_QWORD *)&dataDesc_281[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_281[9].flatOffset[1] = 0;
    dataDesc_281[9].flags = 8;
    dataDesc_281[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_281[10].td = 0;
    *(_QWORD *)&dataDesc_281[10].override_field = 0;
    *(_QWORD *)&dataDesc_281[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_281[10].flatOffset[1] = 0;
    dataDesc_281[8].inputFunc = nullptr;
    dataDesc_281[9].fieldType = FIELD_FLOAT;
    dataDesc_281[9].fieldName = "InputSetTargetSpeed";
    dataDesc_281[9].fieldOffset = 0;
    dataDesc_281[9].externalName = "SetSpeed";
    dataDesc_281[9].pSaveRestoreOps = nullptr;
    dataDesc_281[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMotor::InputSetTargetSpeed;
    dataDesc_281[10].fieldType = FIELD_VOID;
    dataDesc_281[10].fieldName = "InputTurnOn";
    dataDesc_281[10].fieldOffset = 0;
    dataDesc_281[10].flags = 8;
    dataDesc_281[10].externalName = "TurnOn";
    dataDesc_281[10].pSaveRestoreOps = nullptr;
    dataDesc_281[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMotor::InputTurnOn;
    dataDesc_281[11].fieldType = FIELD_VOID;
    dataDesc_281[11].fieldName = "InputTurnOff";
    dataDesc_281[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_281[11].fieldSize = 524289;
    dataDesc_281[11].externalName = "TurnOff";
    dataDesc_281[11].pSaveRestoreOps = nullptr;
    dataDesc_281[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysMotor::InputTurnOff;
    *(_QWORD *)&dataDesc_281[11].td = 0;
    *(_QWORD *)&dataDesc_281[11].override_field = 0;
    *(_QWORD *)&dataDesc_281[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_281[11].flatOffset[1] = 0;
    dataDesc_281[12].fieldType = FIELD_EMBEDDED;
    dataDesc_281[12].fieldName = "m_motor";
    dataDesc_281[12].fieldOffset = 884;
    *(_DWORD *)&dataDesc_281[12].fieldSize = 131073;
    dataDesc_281[12].externalName = nullptr;
    dataDesc_281[12].pSaveRestoreOps = nullptr;
    dataDesc_281[12].inputFunc = nullptr;
    dataDesc_281[12].td = &CMotorController::m_DataMap;
    dataDesc_281[12].fieldTolerance = 0.0;
    dataDesc_281[12].fieldSizeInBytes = 44;
    dataDesc_281[12].override_field = nullptr;
    dataDesc_281[12].override_count = 0;
    *(_DWORD *)&dataDesc_281[12].flatGroup = 0;
    *(_QWORD *)dataDesc_281[12].flatOffset = 0;
  }
  CPhysMotor::m_DataMap.dataNumFields = 12;
  CPhysMotor::m_DataMap.dataDesc = &dataDesc_281[1];
  return &CPhysMotor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180A50
// Name: struct datamap_t __near * DataMapInit<class CKeepUpright>(class CKeepUpright __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CKeepUpright>()
{
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S8_6 & 1) == 0 )
  {
    _S8_6 |= 1u;
    nameHolder_295.m_pszBase = "CKeepUpright";
    nameHolder_295.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_295.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_295.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_295.m_Names.m_Size = 0;
    nameHolder_295.m_Names.m_pElements = nullptr;
    nameHolder_295.m_nLenBase = 12;
    atexit(func: DataMapInit_CKeepUpright__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CKeepUpright::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S8_6 & 2) == 0 )
  {
    _S8_6 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    dataDesc_282[4].flags = 6;
    dataDesc_282[5].fieldSize = 1;
    dataDesc_282[3].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_282[5].flags = 2;
    dataDesc_282[4].fieldSize = 1;
    dataDesc_282[6].fieldSize = 1;
    *(_QWORD *)dataDesc_282[4].flatOffset = 0;
    dataDesc_282[4].fieldSizeInBytes = 4;
    dataDesc_282[5].fieldSizeInBytes = 4;
    dataDesc_282[6].flags = 6;
    dataDesc_282[6].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_282[3].td = 0;
    *(_QWORD *)&dataDesc_282[3].override_field = 0;
    *(_QWORD *)&dataDesc_282[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_282[3].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_282[5].flatOffset = 0;
    dataDesc_282[3].inputFunc = nullptr;
    dataDesc_282[4].fieldType = FIELD_STRING;
    dataDesc_282[4].fieldName = "m_nameAttach";
    dataDesc_282[4].fieldOffset = 884;
    dataDesc_282[4].externalName = "attach1";
    dataDesc_282[4].pSaveRestoreOps = nullptr;
    dataDesc_282[4].inputFunc = nullptr;
    dataDesc_282[4].td = nullptr;
    dataDesc_282[4].override_field = nullptr;
    dataDesc_282[4].override_count = 0;
    dataDesc_282[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_282[4].flatGroup = 0;
    dataDesc_282[5].fieldType = FIELD_EHANDLE;
    dataDesc_282[5].fieldName = "m_attachedObject";
    dataDesc_282[5].fieldOffset = 888;
    dataDesc_282[5].externalName = nullptr;
    dataDesc_282[5].pSaveRestoreOps = nullptr;
    dataDesc_282[5].inputFunc = nullptr;
    dataDesc_282[5].td = nullptr;
    dataDesc_282[5].override_field = nullptr;
    dataDesc_282[5].override_count = 0;
    dataDesc_282[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_282[5].flatGroup = 0;
    dataDesc_282[6].fieldType = FIELD_FLOAT;
    dataDesc_282[6].fieldName = "m_angularLimit";
    dataDesc_282[6].fieldOffset = 892;
    dataDesc_282[6].externalName = "angularlimit";
    dataDesc_282[6].pSaveRestoreOps = nullptr;
    dataDesc_282[6].inputFunc = nullptr;
    dataDesc_282[6].td = nullptr;
    dataDesc_282[6].override_field = nullptr;
    dataDesc_282[6].override_count = 0;
    dataDesc_282[6].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_282[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_282[6].flatGroup = 0;
    dataDesc_282[7].fieldType = FIELD_BOOLEAN;
    dataDesc_282[7].fieldName = "m_bActive";
    dataDesc_282[7].fieldOffset = 896;
    dataDesc_282[7].fieldSize = 1;
    dataDesc_282[7].flags = 2;
    dataDesc_282[7].externalName = nullptr;
    dataDesc_282[7].pSaveRestoreOps = nullptr;
    dataDesc_282[7].inputFunc = nullptr;
    dataDesc_282[7].td = nullptr;
    dataDesc_282[7].fieldTolerance = 0.0;
    dataDesc_282[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_282[8].flatOffset = 0;
    dataDesc_282[8].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)&dataDesc_282[9].td = 0;
    *(_QWORD *)&dataDesc_282[9].override_field = 0;
    *(_QWORD *)&dataDesc_282[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_282[9].flatOffset[1] = 0;
    dataDesc_282[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_282[10].td = 0;
    *(_QWORD *)&dataDesc_282[10].override_field = 0;
    *(_QWORD *)&dataDesc_282[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_282[10].flatOffset[1] = 0;
    dataDesc_282[8].flags = 2;
    dataDesc_282[7].fieldSizeInBytes = 1;
    dataDesc_282[7].override_field = nullptr;
    dataDesc_282[7].override_count = 0;
    *(_QWORD *)dataDesc_282[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_282[7].flatGroup = 0;
    dataDesc_282[8].fieldName = "m_bDampAllRotation";
    dataDesc_282[8].fieldOffset = 897;
    dataDesc_282[8].fieldSize = 1;
    dataDesc_282[8].externalName = nullptr;
    dataDesc_282[8].pSaveRestoreOps = nullptr;
    dataDesc_282[8].inputFunc = nullptr;
    dataDesc_282[8].td = nullptr;
    dataDesc_282[8].fieldSizeInBytes = 1;
    dataDesc_282[8].override_field = nullptr;
    dataDesc_282[8].override_count = 0;
    *(_DWORD *)&dataDesc_282[8].flatGroup = 0;
    dataDesc_282[9].fieldType = FIELD_VOID;
    dataDesc_282[9].fieldName = "InputTurnOn";
    dataDesc_282[9].fieldOffset = 0;
    dataDesc_282[9].flags = 8;
    dataDesc_282[9].externalName = "TurnOn";
    dataDesc_282[9].pSaveRestoreOps = nullptr;
    dataDesc_282[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CKeepUpright::InputTurnOn;
    dataDesc_282[10].fieldType = FIELD_VOID;
    dataDesc_282[10].fieldName = "InputTurnOff";
    dataDesc_282[10].fieldOffset = 0;
    dataDesc_282[10].fieldSize = 1;
    dataDesc_282[10].flags = 8;
    dataDesc_282[10].externalName = "TurnOff";
    dataDesc_282[10].pSaveRestoreOps = nullptr;
    dataDesc_282[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CKeepUpright::InputTurnOff;
    dataDesc_282[11].fieldType = FIELD_FLOAT;
    dataDesc_282[11].fieldName = "InputSetAngularLimit";
    dataDesc_282[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_282[11].fieldSize = 524289;
    dataDesc_282[11].externalName = "SetAngularLimit";
    dataDesc_282[11].pSaveRestoreOps = nullptr;
    dataDesc_282[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CKeepUpright::InputSetAngularLimit;
    *(_QWORD *)&dataDesc_282[11].td = 0;
    *(_QWORD *)&dataDesc_282[11].override_field = 0;
    *(_QWORD *)&dataDesc_282[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_282[11].flatOffset[1] = 0;
  }
  CKeepUpright::m_DataMap.dataNumFields = 11;
  CKeepUpright::m_DataMap.dataDesc = &dataDesc_282[1];
  return &CKeepUpright::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10406D30
// Name: _dynamic_initializer_for__g_debug_constraint_sounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_constraint_sounds__()
{
  ConVar::ConVar(
    this: &g_debug_constraint_sounds,
    pName: "g_debug_constraint_sounds",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enable debug printing about constraint sounds.");
  return atexit(func: dynamic_atexit_destructor_for__g_debug_constraint_sounds__);
}

//------------------------------------------------------------------------------
// Address: 0x10406D60
// Name: _dynamic_initializer_for__g_AnchorList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AnchorList__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_AnchorList, name: "CAnchorList");
  g_AnchorList.__vftable = (CAnchorList_vtbl *)&CAnchorList::`vftable';
  g_AnchorList.m_list.m_Memory.m_pMemory = nullptr;
  g_AnchorList.m_list.m_Memory.m_nAllocationCount = 0;
  g_AnchorList.m_list.m_Memory.m_nGrowSize = 0;
  g_AnchorList.m_list.m_Size = 0;
  g_AnchorList.m_list.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_AnchorList__);
}
