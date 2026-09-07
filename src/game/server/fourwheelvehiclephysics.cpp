// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fourwheelvehiclephysics.cpp
// Functions: 35
// ============================================================

#include "game\server\fourwheelvehiclephysics.h"

//------------------------------------------------------------------------------
// Address: 0x1012D710
// Name: public: virtual struct datamap_t __near * CFourWheelVehiclePhysics::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFourWheelVehiclePhysics::GetDataDescMap(CFourWheelVehiclePhysics *this)
{
  return &CFourWheelVehiclePhysics::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012D720
// Name: public: CFourWheelVehiclePhysics::~CFourWheelVehiclePhysics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::~CFourWheelVehiclePhysics(CFourWheelVehiclePhysics *this)
{
  this->__vftable = (CFourWheelVehiclePhysics_vtbl *)&CFourWheelVehiclePhysics::`vftable';
  physenv->DestroyVehicleController(this: physenv, a2: this->m_pVehicle);
}

//------------------------------------------------------------------------------
// Address: 0x1012D740
// Name: public: void CFourWheelVehiclePhysics::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::Precache(CFourWheelVehiclePhysics *this)
{
  PrecacheEffect(pEffectName: "WheelDust");
}

//------------------------------------------------------------------------------
// Address: 0x1012D750
// Name: public: void CFourWheelVehiclePhysics::SetAction(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SetAction(CFourWheelVehiclePhysics *this, float flAction)
{
  this->m_actionSpeed = flAction;
}

//------------------------------------------------------------------------------
// Address: 0x1012D770
// Name: public: void CFourWheelVehiclePhysics::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::TurnOn(CFourWheelVehiclePhysics *this)
{
  if ( !this->m_pVehicle->IsEngineDisabled(this: this->m_pVehicle) && !this->m_bIsOn )
  {
    this->m_pOuterServerVehicle->SoundStart(this: this->m_pOuterServerVehicle);
    this->m_bIsOn = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D7A0
// Name: public: void CFourWheelVehiclePhysics::ReleaseHandbrake(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::ReleaseHandbrake(CFourWheelVehiclePhysics *this)
{
  this->m_controls.handbrake = false;
}

//------------------------------------------------------------------------------
// Address: 0x1012D7B0
// Name: public: void CFourWheelVehiclePhysics::SetHandbrake(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SetHandbrake(CFourWheelVehiclePhysics *this, bool bBrake)
{
  this->m_controls.handbrake = bBrake;
}

//------------------------------------------------------------------------------
// Address: 0x1012D7C0
// Name: public: void CFourWheelVehiclePhysics::SetDisableEngine(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SetDisableEngine(CFourWheelVehiclePhysics *this, BOOL bDisable)
{
  this->m_pVehicle->SetEngineDisabled(this: this->m_pVehicle, a2: bDisable);
}

//------------------------------------------------------------------------------
// Address: 0x1012D7D0
// Name: public: void CFourWheelVehiclePhysics::SetSteering(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SetSteering(
        CFourWheelVehiclePhysics *this,
        float flSteering,
        float flSteeringRate)
{
  float steering; // xmm0_4

  if ( flSteeringRate == 0.0 )
  {
    this->m_controls.steering = flSteering;
  }
  else
  {
    steering = this->m_controls.steering;
    if ( (float)(flSteering - steering) <= flSteeringRate )
    {
      if ( COERCE_FLOAT(LODWORD(flSteeringRate) ^ _mask__NegFloat_) <= (float)(flSteering - steering) )
        this->m_controls.steering = flSteering;
      else
        this->m_controls.steering = steering - flSteeringRate;
    }
    else
    {
      this->m_controls.steering = steering + flSteeringRate;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D840
// Name: public: void CFourWheelVehiclePhysics::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::TurnOff(CFourWheelVehiclePhysics *this)
{
  bool v2; // zf

  v2 = !this->m_bIsOn;
  *(_WORD *)&this->m_controls.handbrake = 1;
  this->m_controls.handbrakeRight = false;
  *(_QWORD *)&this->m_controls.brake = 0;
  this->m_controls.throttle = 0.0;
  this->m_controls.steering = 0.0;
  if ( !v2 )
  {
    ((void (__stdcall *)(_DWORD))this->m_pOuterServerVehicle->SoundShutdown)(a1: 0);
    this->m_bIsOn = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D890
// Name: public: void CFourWheelVehiclePhysics::Teleport(struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::Teleport(CFourWheelVehiclePhysics *this, matrix3x4_t *relativeTransform)
{
  int v3; // edi
  IPhysicsObject **m_pWheels; // esi
  CFourWheelServerVehicle *m_pOuterServerVehicle; // ecx
  int v6; // ecx
  matrix3x4_t newMatrix; // [esp+8h] [ebp-60h] BYREF
  matrix3x4_t matrix; // [esp+38h] [ebp-30h] BYREF

  v3 = 0;
  if ( this->m_wheelCount > 0 )
  {
    m_pWheels = this->m_pWheels;
    do
    {
      (*m_pWheels)->GetPositionMatrix(this: *m_pWheels, a2: &matrix);
      ConcatTransforms(in1: relativeTransform, in2: &matrix, out: &newMatrix);
      (*m_pWheels)->SetPositionMatrix(this: *m_pWheels, a2: &newMatrix, a3: true);
      ++v3;
      ++m_pWheels;
    }
    while ( v3 < this->m_wheelCount );
  }
  m_pOuterServerVehicle = this->m_pOuterServerVehicle;
  if ( m_pOuterServerVehicle != nullptr
    && CFourWheelServerVehicle::GetFourWheelVehicle(this: (vgui::TextImage *)m_pOuterServerVehicle) != 0 )
  {
    v6 = *(_DWORD *)(CFourWheelServerVehicle::GetFourWheelVehicle(this: (vgui::TextImage *)this->m_pOuterServerVehicle)
                   + 328);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 96))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D920
// Name: public: void CFourWheelVehiclePhysics::PlaceWheelDust(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::PlaceWheelDust(
        CFourWheelVehiclePhysics *this,
        int wheelIndex,
        bool ignoreSpeed)
{
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  float m_flMaxSpeed; // xmm1_4
  float m_nSpeed; // xmm0_4
  float v9; // xmm0_4
  CEffectData data; // [esp+1Ch] [ebp-7Ch] BYREF
  Vector vecPos; // [esp+80h] [ebp-18h] BYREF
  Vector vecVel; // [esp+8Ch] [ebp-Ch] BYREF

  if ( hl2_episodic.m_pParent == nullptr || hl2_episodic.m_pParent->m_Value.m_nValue == 0 )
  {
    this->m_pVehicle->GetWheelContactPoint(this: this->m_pVehicle, a2: wheelIndex, a3: &vecPos, a4: nullptr);
    vecVel.x = _RandomFloat(this: v4, a2: -1.0, a3: 1.0);
    vecVel.y = _RandomFloat(this: v5, a2: -1.0, a3: 1.0);
    vecVel.z = _RandomFloat(this: v6, a2: -1.0, a3: 1.0);
    vecVel.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 1050253722,
                 a3: 1065353216);
    VectorNormalize(vec: &vecVel);
    if ( ignoreSpeed )
    {
LABEL_6:
      v9 = 1.0;
LABEL_12:
      data.m_vOrigin = vecPos;
      data.m_vNormal = vecVel;
      memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
      memset((void *)&data.m_vAngles, 0, 20);
      memset(&data.m_flMagnitude, 0, 14);
      memset(&data.m_nMaterial, 0, 17);
      data.m_flScale = v9;
      DispatchEffect(pName: "WheelDust", &data);
      return;
    }
    m_flMaxSpeed = this->m_flMaxSpeed;
    m_nSpeed = (float)this->m_nSpeed;
    if ( m_flMaxSpeed == 5.0 )
    {
      if ( (float)(m_nSpeed - m_flMaxSpeed) < 0.0 )
        return;
      goto LABEL_6;
    }
    v9 = (float)(m_nSpeed - 5.0) / (float)(m_flMaxSpeed - 5.0);
    if ( v9 >= 0.0 )
    {
      if ( v9 > 1.0 )
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    if ( v9 != 0.0 )
      goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DB10
// Name: private: void CFourWheelVehiclePhysics::SteeringRest(float,struct vehicleparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SteeringRest(
        CFourWheelVehiclePhysics *this,
        float carSpeed,
        const vehicleparams_t *vehicleData)
{
  float speedSlow; // xmm3_4
  float speedFast; // xmm1_4
  float steeringRestRateFast; // xmm2_4
  float v6; // xmm0_4
  float steering; // xmm1_4
  float v8; // xmm0_4

  speedSlow = vehicleData->steering.speedSlow;
  speedFast = vehicleData->steering.speedFast;
  steeringRestRateFast = vehicleData->steering.steeringRestRateFast;
  if ( speedSlow == speedFast )
  {
    if ( (float)(carSpeed - speedFast) < 0.0 )
      steeringRestRateFast = vehicleData->steering.steeringRestRateSlow;
  }
  else
  {
    v6 = (float)(carSpeed - speedSlow) / (float)(speedFast - speedSlow);
    if ( v6 >= 0.0 )
    {
      if ( v6 > 1.0 )
        v6 = 1.0;
    }
    else
    {
      v6 = 0.0;
    }
    steeringRestRateFast = (float)((float)(steeringRestRateFast - vehicleData->steering.steeringRestRateSlow) * v6)
                         + vehicleData->steering.steeringRestRateSlow;
  }
  steering = this->m_controls.steering;
  v8 = gpGlobals->frametime * steeringRestRateFast;
  if ( (float)-steering <= v8 )
  {
    if ( (float)-v8 <= (float)-steering )
      this->m_controls.steering = 0.0;
    else
      this->m_controls.steering = steering - v8;
  }
  else
  {
    this->m_controls.steering = steering + v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DBE0
// Name: private: void CFourWheelVehiclePhysics::SteeringTurn(float,struct vehicleparams_t const __near &,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFourWheelVehiclePhysics::SteeringTurn(
        CFourWheelVehiclePhysics *this@<ecx>,
        int a2@<esi>,
        float carSpeed,
        const vehicleparams_t *vehicleData,
        bool bTurnLeft,
        bool bBrake,
        bool bThrottle)
{
  float speedSlow; // xmm2_4
  float speedFast; // xmm1_4
  float steeringRestRateFast; // xmm3_4
  float v11; // xmm0_4
  float maxSpeed; // xmm3_4
  float v13; // xmm2_4
  float boostMaxSpeed; // xmm0_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // eax
  char v19; // cl
  int v20; // eax
  bool v21; // al
  float v22; // xmm5_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float steeringRateFast; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float boostSteeringRateFactor; // xmm0_4
  float steering; // xmm1_4
  float v31; // xmm0_4
  float flTargetSteering; // [esp+0h] [ebp-4h]
  float flSteeringRestRate; // [esp+14h] [ebp+10h]

  if ( bTurnLeft )
    flTargetSteering = -1.0;
  else
    flTargetSteering = 1.0;
  speedSlow = vehicleData->steering.speedSlow;
  speedFast = vehicleData->steering.speedFast;
  steeringRestRateFast = vehicleData->steering.steeringRestRateFast;
  if ( speedSlow == speedFast )
  {
    if ( (float)(carSpeed - speedFast) < 0.0 )
    {
      flSteeringRestRate = vehicleData->steering.steeringRestRateSlow;
      goto LABEL_13;
    }
  }
  else
  {
    v11 = (float)(carSpeed - speedSlow) / (float)(speedFast - speedSlow);
    if ( v11 >= 0.0 )
    {
      if ( v11 > 1.0 )
        v11 = 1.0;
    }
    else
    {
      v11 = 0.0;
    }
    steeringRestRateFast = (float)((float)(steeringRestRateFast - vehicleData->steering.steeringRestRateSlow) * v11)
                         + vehicleData->steering.steeringRestRateSlow;
  }
  flSteeringRestRate = steeringRestRateFast;
LABEL_13:
  maxSpeed = vehicleData->engine.maxSpeed;
  v13 = carSpeed * 17.6;
  if ( (float)(carSpeed * 17.6) > maxSpeed )
  {
    boostMaxSpeed = vehicleData->engine.boostMaxSpeed;
    v15 = vehicleData->steering.steeringRestRateFast;
    v16 = v15 * 0.5;
    if ( maxSpeed == boostMaxSpeed )
    {
      if ( (float)(v13 - boostMaxSpeed) < 0.0 )
      {
        flSteeringRestRate = vehicleData->steering.steeringRestRateFast;
        goto LABEL_23;
      }
    }
    else
    {
      v17 = (float)(v13 - maxSpeed) / (float)(boostMaxSpeed - maxSpeed);
      if ( v17 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
      v16 = (float)((float)(v16 - v15) * v17) + v15;
    }
    flSteeringRestRate = v16;
  }
LABEL_23:
  v18 = ((int (__thiscall *)(IPhysicsVehicleController *, int))this->m_pVehicle->GetOperatingParams)(
          a1: this->m_pVehicle,
          a2);
  v19 = *(_BYTE *)(v18 + 40);
  v20 = *(_DWORD *)(v18 + 16);
  v21 = v20 != 100 && v20 != 0;
  if ( v19 != 0 )
    goto LABEL_31;
  if ( v21 && (float)(carSpeed * 17.6) > (float)(vehicleData->engine.autobrakeSpeedGain * vehicleData->engine.maxSpeed) )
  {
    v19 = 1;
LABEL_31:
    v22 = vehicleData->steering.boostSteeringRestRateFactor * flSteeringRestRate;
    goto LABEL_35;
  }
  if ( bThrottle )
    v22 = vehicleData->steering.throttleSteeringRestRateFactor * flSteeringRestRate;
  else
    v22 = flSteeringRestRate;
LABEL_35:
  v23 = vehicleData->steering.speedSlow;
  v24 = vehicleData->steering.speedFast;
  steeringRateFast = vehicleData->steering.steeringRateFast;
  if ( v23 == v24 )
  {
    if ( (float)(carSpeed - v24) < 0.0 )
      steeringRateFast = vehicleData->steering.steeringRateSlow;
  }
  else
  {
    v26 = (float)(carSpeed - v23) / (float)(v24 - v23);
    if ( v26 >= 0.0 )
    {
      if ( v26 > 1.0 )
        v26 = 1.0;
    }
    else
    {
      v26 = 0.0;
    }
    steeringRateFast = (float)((float)(steeringRateFast - vehicleData->steering.steeringRateSlow) * v26)
                     + vehicleData->steering.steeringRateSlow;
  }
  if ( v22 > fabs(steeringRateFast) )
  {
    v27 = flTargetSteering < 0.0 ? -1.0 : 1.0;
    v28 = this->m_controls.steering < 0.0 ? -1.0 : 1.0;
    if ( v27 != v28 )
      steeringRateFast = v22;
  }
  if ( v19 != 0 )
  {
    boostSteeringRateFactor = vehicleData->steering.boostSteeringRateFactor;
  }
  else
  {
    if ( !bBrake )
      goto LABEL_57;
    boostSteeringRateFactor = vehicleData->steering.brakeSteeringRateFactor;
  }
  steeringRateFast = boostSteeringRateFactor * steeringRateFast;
LABEL_57:
  steering = this->m_controls.steering;
  v31 = gpGlobals->frametime * steeringRateFast;
  if ( (float)(flTargetSteering - steering) <= v31 )
  {
    if ( COERCE_FLOAT(LODWORD(v31) ^ _mask__NegFloat_) <= (float)(flTargetSteering - steering) )
      this->m_controls.steering = flTargetSteering;
    else
      this->m_controls.steering = steering - v31;
    this->m_controls.bAnalogSteering = false;
  }
  else
  {
    this->m_controls.steering = steering + v31;
    this->m_controls.bAnalogSteering = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DED0
// Name: private: void CFourWheelVehiclePhysics::SteeringTurnAnalog(float,struct vehicleparams_t const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SteeringTurnAnalog(
        CFourWheelVehiclePhysics *this,
        float carSpeed,
        const vehicleparams_t *vehicleData,
        float sidemove)
{
  float v4; // xmm0_4
  float m_fValue; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float speedSlow; // xmm3_4
  float speedFast; // xmm1_4
  float steeringRateFast; // xmm2_4
  float v12; // xmm0_4
  float throttleSteeringRestRateFactor; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float steering; // xmm1_4
  float flSign; // [esp+10h] [ebp+10h]

  v4 = sidemove * 0.0024999999;
  if ( (float)(sidemove * 0.0024999999) <= 0.0 )
    flSign = -1.0;
  else
    flSign = 1.0;
  m_fValue = xbox_steering_deadzone.m_pParent->m_Value.m_fValue;
  v6 = fabs(v4);
  if ( m_fValue == 1.0 )
  {
    if ( (float)(v6 - 1.0) < 0.0 )
      v7 = 0.0;
    else
      v7 = 1.0;
  }
  else
  {
    v8 = (float)(v6 - m_fValue) / (float)(1.0 - m_fValue);
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    v7 = v8;
  }
  speedSlow = vehicleData->steering.speedSlow;
  speedFast = vehicleData->steering.speedFast;
  steeringRateFast = vehicleData->steering.steeringRateFast;
  if ( speedSlow == speedFast )
  {
    if ( (float)(carSpeed - speedFast) < 0.0 )
      steeringRateFast = vehicleData->steering.steeringRateSlow;
  }
  else
  {
    v12 = (float)(carSpeed - speedSlow) / (float)(speedFast - speedSlow);
    if ( v12 >= 0.0 )
    {
      if ( v12 > 1.0 )
        v12 = 1.0;
    }
    else
    {
      v12 = 0.0;
    }
    steeringRateFast = (float)((float)(steeringRateFast - vehicleData->steering.steeringRateSlow) * v12)
                     + vehicleData->steering.steeringRateSlow;
  }
  throttleSteeringRestRateFactor = vehicleData->steering.throttleSteeringRestRateFactor;
  v14 = v7 * flSign;
  this->m_controls.bAnalogSteering = true;
  v15 = gpGlobals->frametime * (float)(throttleSteeringRestRateFactor * steeringRateFast);
  if ( v15 == 0.0 )
  {
    this->m_controls.steering = v14;
  }
  else
  {
    steering = this->m_controls.steering;
    if ( (float)(v14 - steering) <= v15 )
    {
      if ( COERCE_FLOAT(LODWORD(v15) ^ _mask__NegFloat_) <= (float)(v14 - steering) )
        this->m_controls.steering = v14;
      else
        this->m_controls.steering = steering - v15;
    }
    else
    {
      this->m_controls.steering = steering + v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E040
// Name: public: void CFourWheelVehiclePhysics::UpdateDriverControls(class CUserCmd __near *,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CFourWheelVehiclePhysics::UpdateDriverControls(
        CFourWheelVehiclePhysics *this,
        CUserCmd *cmd,
        float flFrameTime)
{
  const vehicle_operatingparams_t *v4; // eax
  IPhysicsVehicleController *m_pVehicle; // ecx
  const vehicle_operatingparams_t *v6; // edi
  const vehicleparams_t *(__thiscall *GetVehicleParams)(IPhysicsVehicleController *); // eax
  const vehicleparams_t *v8; // eax
  float speed; // xmm0_4
  const vehicleparams_t *v10; // ebx
  float v11; // xmm2_4
  float carSpeed; // xmm0_4
  CUserCmd *v13; // edi
  IPhysicsVehicleController *v14; // ecx
  const vehicleparams_t *(__thiscall *v15)(IPhysicsVehicleController *); // eax
  CFourWheelServerVehicle *m_pOuterServerVehicle; // ecx
  int v17; // eax
  void *v18; // edi
  _DWORD *v19; // eax
  CUserCmd *v20; // edx
  float forwardmove; // xmm0_4
  _DWORD *v22; // ecx
  int v23; // eax
  int v24; // eax
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm0_4
  bool v28; // cc
  bool v29; // bl
  float v30; // xmm2_4
  double v31; // xmm1_8
  float v32; // xmm2_4
  float v33; // xmm1_4
  float A; // xmm0_4
  double v35; // st7
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  float brake; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  double v45; // xmm1_8
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm2_4
  float m_maxThrottle; // xmm1_4
  double v51; // xmm0_8
  float v52; // xmm3_4
  float steering; // xmm0_4
  float speedSlow; // xmm0_4
  double v55; // st7
  float v56; // xmm0_4
  float throttle; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float m_flMaxRevThrottle; // xmm1_4
  double v61; // xmm0_8
  float v62; // xmm1_4
  float v63; // xmm3_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float sidemove; // xmm0_4
  int m_nLastSpeed; // eax
  int m_nSpeed; // ecx
  double curtime; // st7
  float v70; // xmm0_4
  bool v71; // cf
  bool v72; // zf
  IPhysicsVehicleController *v73; // ecx
  int v74; // edi
  const vehicle_operatingparams_t *v75; // eax
  bool v76; // al
  CFourWheelServerVehicle *v77; // ecx
  bool v78; // al
  CFourWheelServerVehicle *v79; // ecx
  vbs_sound_update_t params; // [esp+20h] [ebp-38h] BYREF
  const vehicle_operatingparams_t *carState; // [esp+34h] [ebp-24h]
  double v82; // [esp+38h] [ebp-20h] OVERLAPPED
  const vehicleparams_t *vehicleData; // [esp+40h] [ebp-18h]
  float bThrottleDown; // [esp+44h] [ebp-14h]
  int nButtons; // [esp+48h] [ebp-10h]
  float flThrottleReduce; // [esp+4Ch] [ebp-Ch]
  BOOL bBrake; // [esp+50h] [ebp-8h]
  float flCarSign; // [esp+54h] [ebp-4h]
  float flSpeedPercentage; // [esp+60h] [ebp+8h]

  nButtons = cmd->buttons;
  v4 = this->m_pVehicle->GetOperatingParams(this: this->m_pVehicle);
  m_pVehicle = this->m_pVehicle;
  v6 = v4;
  GetVehicleParams = m_pVehicle->GetVehicleParams;
  carState = v6;
  *(float *)&v8 = COERCE_FLOAT((int)GetVehicleParams(this: m_pVehicle));
  speed = v6->speed;
  v10 = v8;
  vehicleData = v8;
  flCarSign = 0.0;
  if ( speed >= 2.0 )
  {
    v11 = 1.0;
LABEL_5:
    flCarSign = v11;
    goto LABEL_6;
  }
  if ( speed <= -2.0 )
  {
    v11 = -1.0;
    goto LABEL_5;
  }
LABEL_6:
  carSpeed = fabs(speed * 0.056818184);
  flThrottleReduce = carSpeed;
  if ( xbox_autothrottle.m_pParent != nullptr && xbox_autothrottle.m_pParent->m_Value.m_nValue != 0 )
  {
    v13 = cmd;
    if ( cmd->forwardmove > 0.0 )
    {
      v14 = this->m_pVehicle;
      v15 = v14->GetVehicleParams;
      v82 = carSpeed;
      if ( carSpeed > (double)(int)(float)(v15(this: v14)->engine.maxSpeed * 0.056818184) * 0.75
        && fabs(cmd->sidemove) > cmd->forwardmove )
      {
        cmd->forwardmove = 400.0;
      }
      carSpeed = flThrottleReduce;
    }
  }
  else
  {
    v13 = cmd;
  }
  if ( (nButtons & 0x600) != 0 )
  {
    BYTE4(v82) = (nButtons & 0x200) != 0;
    LOBYTE(bBrake) = (nButtons & 0x10) != 0;
    if ( (nButtons & 8) == 0 || (LOBYTE(bThrottleDown) = 1, (nButtons & 0x10) != 0) )
      LOBYTE(bThrottleDown) = 0;
    CFourWheelVehiclePhysics::SteeringTurn(
      this,
      a2: (int)this,
      carSpeed,
      vehicleData: v10,
      bTurnLeft: SBYTE4(v82),
      bBrake,
      bThrottle: SLOBYTE(bThrottleDown));
  }
  else if ( v13->sidemove == 0.0 )
  {
    CFourWheelVehiclePhysics::SteeringRest(this, carSpeed, vehicleData: v10);
  }
  else
  {
    CFourWheelVehiclePhysics::SteeringTurnAnalog(this, carSpeed, vehicleData: v10, sidemove: v13->sidemove);
  }
  m_pOuterServerVehicle = this->m_pOuterServerVehicle;
  *(_QWORD *)&this->m_controls.boost = 0;
  v17 = (int)m_pOuterServerVehicle->GetDriver(this: m_pOuterServerVehicle);
  v18 = (void *)v17;
  bThrottleDown = xbox_throttlebias.m_pParent->m_Value.m_fValue;
  if ( v17 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v17 + 336))(a1: v17) != 0 )
  {
    v19 = __RTDynamicCast(
            inptr: v18,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBasePlayer `RTTI Type Descriptor',
            isReference: 0);
    v20 = cmd;
    forwardmove = cmd->forwardmove;
    v22 = v19;
    if ( forwardmove == 0.0 && COERCE_FLOAT(LODWORD(cmd->sidemove) & _mask__AbsFloat_) < 200.0 )
    {
      v19[769] = 0;
      goto LABEL_40;
    }
    if ( forwardmove <= 0.0 )
    {
      if ( forwardmove >= 0.0 )
        goto LABEL_40;
      v24 = v19[769];
      if ( v24 == 1 )
      {
        if ( forwardmove > COERCE_FLOAT(LODWORD(bThrottleDown) ^ _mask__NegFloat_) )
        {
          cmd->forwardmove = xbox_throttlespoof.m_pParent->m_Value.m_fValue;
          goto LABEL_40;
        }
      }
      else if ( v24 != 0 )
      {
        goto LABEL_40;
      }
      v22[769] = 2;
    }
    else
    {
      v23 = v19[769];
      if ( v23 == 2 )
      {
        if ( bThrottleDown > forwardmove )
        {
          LODWORD(cmd->forwardmove) = LODWORD(xbox_throttlespoof.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
          goto LABEL_40;
        }
      }
      else if ( v23 != 0 )
      {
        goto LABEL_40;
      }
      v22[769] = 1;
    }
  }
  else
  {
    v20 = cmd;
  }
LABEL_40:
  v25 = v20->forwardmove;
  v26 = flFrameTime;
  if ( v25 <= 0.0 )
  {
    if ( v25 >= 0.0 )
    {
      if ( (nButtons & 8) != 0 )
      {
        v29 = true;
        if ( this->m_controls.throttle < 0.0 )
          this->m_controls.throttle = 0.0;
        m_maxThrottle = this->m_maxThrottle;
        v51 = 0.1;
        if ( m_maxThrottle >= 0.1 )
          v51 = m_maxThrottle;
        v52 = v51;
        steering = this->m_controls.steering;
        *((float *)&v82 + 1) = v52;
        bThrottleDown = steering;
        if ( steering != 0.0 )
        {
          speedSlow = vehicleData->steering.speedSlow;
          if ( speedSlow <= flThrottleReduce )
            v55 = RemapValClamped(
                    val: flThrottleReduce,
                    A: speedSlow,
                    B: vehicleData->steering.speedFast,
                    C: vehicleData->steering.turnThrottleReduceSlow,
                    D: vehicleData->steering.turnThrottleReduceFast);
          else
            v55 = RemapValClamped(
                    val: flThrottleReduce,
                    A: 0.0,
                    B: speedSlow,
                    C: 0.0,
                    D: vehicleData->steering.turnThrottleReduceSlow);
          *(float *)&vehicleData = v55;
          v56 = 1.0 - (float)(COERCE_FLOAT(LODWORD(bThrottleDown) & _mask__AbsFloat_) * *(float *)&vehicleData);
          if ( v56 < 0.0 )
            v56 = 0.0;
          v52 = *((float *)&v82 + 1);
          v26 = flFrameTime;
          if ( v56 <= *((float *)&v82 + 1) )
            v52 = v56;
        }
        throttle = this->m_controls.throttle;
        v58 = this->m_throttleRate * v26;
        if ( (float)(v52 - throttle) <= v58 )
        {
          if ( COERCE_FLOAT(LODWORD(v58) ^ _mask__NegFloat_) <= (float)(v52 - throttle) )
            v59 = v52;
          else
            v59 = throttle - v58;
        }
        else
        {
          v59 = throttle + v58;
        }
        v28 = flCarSign >= 0.0;
        this->m_controls.throttle = v59;
        if ( v28 || !this->m_controls.bHasBrakePedal )
          goto LABEL_123;
        this->m_controls.brake = Approach(
                                   target: 1.0,
                                   value: this->m_controls.brake,
                                   speed: (float)(r_vehicleBrakeRate.m_pParent->m_Value.m_fValue * v26) * 2.0);
        this->m_controls.brakepedal = true;
        this->m_controls.throttle = 0.0;
      }
      else
      {
        if ( (nButtons & 0x10) == 0 )
        {
          this->m_controls.brake = 0.0;
LABEL_125:
          this->m_controls.throttle = 0.0;
          goto LABEL_126;
        }
        v29 = true;
        if ( this->m_controls.throttle > 0.0 )
          this->m_controls.throttle = 0.0;
        m_flMaxRevThrottle = this->m_flMaxRevThrottle;
        v61 = -0.1;
        if ( m_flMaxRevThrottle <= -0.1 )
          v61 = m_flMaxRevThrottle;
        v62 = this->m_controls.throttle;
        v63 = v61;
        v64 = this->m_throttleRate * flFrameTime;
        if ( (float)(v63 - v62) <= v64 )
        {
          if ( COERCE_FLOAT(LODWORD(v64) ^ _mask__NegFloat_) <= (float)(v63 - v62) )
            v65 = v63;
          else
            v65 = v62 - v64;
        }
        else
        {
          v65 = v62 + v64;
        }
        v28 = flCarSign <= 0.0;
        this->m_controls.throttle = v65;
        if ( v28 || !this->m_controls.bHasBrakePedal )
          goto LABEL_123;
        this->m_controls.brake = Approach(
                                   target: 1.0,
                                   value: this->m_controls.brake,
                                   speed: r_vehicleBrakeRate.m_pParent->m_Value.m_fValue * flFrameTime);
        this->m_controls.brakepedal = true;
        this->m_controls.throttle = 0.0;
      }
LABEL_126:
      v29 = false;
      goto LABEL_127;
    }
    LODWORD(v43) = COERCE_UNSIGNED_INT(v25 * 0.0024999999) & _mask__AbsFloat_;
    if ( v43 >= 0.25 )
    {
      if ( v43 > 1.0 )
        v43 = 1.0;
    }
    else
    {
      v43 = 0.25;
    }
    v29 = true;
    if ( this->m_controls.throttle > 0.0 )
      this->m_controls.throttle = 0.0;
    v44 = this->m_flMaxRevThrottle;
    v45 = -0.1;
    if ( v44 <= -0.1 )
      v45 = v44;
    v46 = this->m_controls.throttle;
    v47 = (float)v45 * v43;
    v48 = this->m_throttleRate * flFrameTime;
    if ( (float)(v47 - v46) <= v48 )
    {
      if ( COERCE_FLOAT(LODWORD(v48) ^ _mask__NegFloat_) <= (float)(v47 - v46) )
        v49 = v47;
      else
        v49 = v46 - v48;
    }
    else
    {
      v49 = v46 + v48;
    }
    v28 = flCarSign <= 0.0;
    this->m_controls.throttle = v49;
    if ( !v28 && this->m_controls.bHasBrakePedal )
    {
      v41 = r_vehicleBrakeRate.m_pParent->m_Value.m_fValue * flFrameTime;
LABEL_66:
      brake = this->m_controls.brake;
      if ( (float)(1.0 - brake) <= v41 )
      {
        if ( COERCE_FLOAT(LODWORD(v41) ^ _mask__NegFloat_) <= (float)(1.0 - brake) )
          this->m_controls.brake = 1.0;
        else
          this->m_controls.brake = brake - v41;
        this->m_controls.brakepedal = true;
      }
      else
      {
        this->m_controls.brake = brake + v41;
        this->m_controls.brakepedal = true;
      }
      goto LABEL_125;
    }
  }
  else
  {
    v27 = v25 * 0.0024999999;
    if ( v27 >= 0.25 )
    {
      if ( v27 > 1.0 )
        v27 = 1.0;
    }
    else
    {
      v27 = 0.25;
    }
    v28 = this->m_controls.throttle >= 0.0;
    *(float *)&bBrake = v27;
    v29 = true;
    if ( !v28 )
      this->m_controls.throttle = 0.0;
    v30 = this->m_maxThrottle;
    v31 = 0.1;
    if ( v30 >= 0.1 )
      v31 = v30;
    v32 = this->m_controls.steering;
    v33 = v31;
    *((float *)&v82 + 1) = v33;
    bThrottleDown = v32;
    if ( v32 != 0.0 )
    {
      A = vehicleData->steering.speedSlow;
      if ( A <= flThrottleReduce )
        v35 = RemapValClamped(
                val: flThrottleReduce,
                A,
                B: vehicleData->steering.speedFast,
                C: vehicleData->steering.turnThrottleReduceSlow,
                D: vehicleData->steering.turnThrottleReduceFast);
      else
        v35 = RemapValClamped(
                val: flThrottleReduce,
                A: 0.0,
                B: A,
                C: 0.0,
                D: vehicleData->steering.turnThrottleReduceSlow);
      flThrottleReduce = v35;
      v36 = 1.0 - (float)(COERCE_FLOAT(LODWORD(bThrottleDown) & _mask__AbsFloat_) * flThrottleReduce);
      if ( v36 < 0.0 )
        v36 = 0.0;
      v33 = *((float *)&v82 + 1);
      v26 = flFrameTime;
      if ( v36 <= *((float *)&v82 + 1) )
        v33 = v36;
      v27 = *(float *)&bBrake;
    }
    v37 = this->m_controls.throttle;
    v38 = v27 * v33;
    v39 = this->m_throttleRate * v26;
    if ( (float)(v38 - v37) <= v39 )
    {
      if ( COERCE_FLOAT(LODWORD(v39) ^ _mask__NegFloat_) <= (float)(v38 - v37) )
        v40 = v38;
      else
        v40 = v37 - v39;
    }
    else
    {
      v40 = v37 + v39;
    }
    v28 = flCarSign >= 0.0;
    this->m_controls.throttle = v40;
    if ( !v28 && this->m_controls.bHasBrakePedal )
    {
      v41 = (float)(r_vehicleBrakeRate.m_pParent->m_Value.m_fValue * v26) * 2.0;
      goto LABEL_66;
    }
  }
LABEL_123:
  this->m_controls.brake = 0.0;
LABEL_127:
  if ( (nButtons & 0x20000) != 0 && !this->m_pVehicle->IsEngineDisabled(this: this->m_pVehicle) && v29 )
    this->m_controls.boost = 1.0;
  if ( (nButtons & 2) != 0 && this->m_controls.bHasBrakePedal )
  {
    this->m_controls.handbrake = true;
    sidemove = cmd->sidemove;
    if ( sidemove >= -100.0 )
    {
      if ( sidemove > 100.0 )
        this->m_controls.handbrakeRight = true;
    }
    else
    {
      this->m_controls.handbrakeLeft = true;
    }
    v29 = false;
  }
  if ( this->m_pVehicle->IsEngineDisabled(this: this->m_pVehicle) )
  {
    this->m_controls.throttle = 0.0;
    this->m_controls.handbrake = true;
    v29 = false;
  }
  else if ( v29 )
  {
    m_nLastSpeed = this->m_nLastSpeed;
    m_nSpeed = this->m_nSpeed;
    if ( m_nLastSpeed > m_nSpeed && m_nLastSpeed - m_nSpeed > 10 )
      this->m_bLastThrottle = false;
  }
  if ( this->m_controls.handbrake || this->m_controls.brakepedal )
    goto LABEL_149;
  if ( v29 )
  {
    if ( !this->m_bLastThrottle )
    {
      curtime = gpGlobals->curtime;
      this->m_bLastThrottle = true;
      this->m_throttleStartTime = curtime;
      goto LABEL_153;
    }
LABEL_149:
    if ( v29 )
      goto LABEL_153;
  }
  if ( this->m_bLastThrottle && !this->m_pVehicle->IsEngineDisabled(this: this->m_pVehicle) )
  {
    this->m_throttleActiveTime = gpGlobals->curtime - this->m_throttleStartTime;
    this->m_bLastThrottle = false;
  }
LABEL_153:
  v70 = (float)this->m_nSpeed / this->m_flMaxSpeed;
  if ( v70 >= 0.0 )
  {
    if ( v70 <= 1.0 )
      flSpeedPercentage = (float)this->m_nSpeed / this->m_flMaxSpeed;
    else
      flSpeedPercentage = 1.0;
  }
  else
  {
    flSpeedPercentage = 0.0;
  }
  v71 = this->m_controls.throttle > 0.0;
  v72 = this->m_controls.throttle == 0.0;
  params.flFrameTime = gpGlobals->frametime;
  params.flCurrentSpeedFraction = 0.0;
  params.flWorldSpaceSpeed = 0.0;
  params.bVehicleInWater = false;
  params.bExitVehicle = false;
  *(_WORD *)&params.bReverse = !v71 && !v72;
  v73 = this->m_pVehicle;
  params.bThrottleDown = v29;
  v74 = (int)v73->GetVehicleParams(this: v73);
  v75 = this->m_pVehicle->GetOperatingParams(this: this->m_pVehicle);
  v76 = v74 != 0 && v75 != nullptr && (float)(v75->boostDelay - *(float *)(v74 + 580)) > 0.0;
  v77 = this->m_pOuterServerVehicle;
  params.bTurbo = v76;
  v78 = v77->IsVehicleBodyInWater(this: v77);
  v79 = this->m_pOuterServerVehicle;
  params.bVehicleInWater = v78;
  params.flCurrentSpeedFraction = flSpeedPercentage;
  params.flFrameTime = flFrameTime;
  params.flWorldSpaceSpeed = carState->speed;
  v79->SoundUpdate(this: v79, a2: &params);
}

//------------------------------------------------------------------------------
// Address: 0x1012EA90
// Name: public: CFourWheelVehiclePhysics::CFourWheelVehiclePhysics(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
CFourWheelVehiclePhysics *__thiscall CFourWheelVehiclePhysics::CFourWheelVehiclePhysics(
        CFourWheelVehiclePhysics *this,
        CBaseAnimating *pOuter)
{
  this->m_flVehicleVolume = 0.5;
  this->__vftable = (CFourWheelVehiclePhysics_vtbl *)&CFourWheelVehiclePhysics::`vftable';
  this->m_pOuter.m_Index = -1;
  this->m_pOuterServerVehicle = nullptr;
  this->m_flMaxSpeed = 30.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1012EAD0
// Name: private: int CFourWheelVehiclePhysics::LookupPoseParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFourWheelVehiclePhysics::LookupPoseParameter(CFourWheelVehiclePhysics *this, const char *szName)
{
  unsigned int m_Index; // eax
  CBaseAnimating *m_pEntity; // esi
  CStudioHdr *m_pStudioHdr; // eax

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: m_pEntity) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pEntity);
  m_pStudioHdr = m_pEntity->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::LookupPoseParameter(this: m_pEntity, pStudioHdr: m_pStudioHdr, szName);
}

//------------------------------------------------------------------------------
// Address: 0x1012EB40
// Name: private: float CFourWheelVehiclePhysics::SetPoseParameter(int,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CFourWheelVehiclePhysics::SetPoseParameter(
        CFourWheelVehiclePhysics *this,
        int iParameter,
        float flValue)
{
  unsigned int m_Index; // eax
  CBaseAnimating *m_pEntity; // esi
  CStudioHdr *m_pStudioHdr; // eax

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: m_pEntity) != nullptr )
    CBaseAnimating::LockStudioHdr(this: m_pEntity);
  m_pStudioHdr = m_pEntity->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  return CBaseAnimating::SetPoseParameter(this: m_pEntity, pStudioHdr: m_pStudioHdr, iParameter, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x1012EBC0
// Name: private: void CFourWheelVehiclePhysics::InitializePoseParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::InitializePoseParameters(CFourWheelVehiclePhysics *this)
{
  int v2; // eax
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // eax

  this->m_poseParameters[0] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_fl_height");
  this->m_poseParameters[1] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_fr_height");
  this->m_poseParameters[2] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_rl_height");
  this->m_poseParameters[3] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_rr_height");
  this->m_poseParameters[4] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_fl_spin");
  this->m_poseParameters[5] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_fr_spin");
  this->m_poseParameters[6] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_rl_spin");
  this->m_poseParameters[7] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_wheel_rr_spin");
  this->m_poseParameters[8] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_steer");
  this->m_poseParameters[9] = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_action");
  v2 = CFourWheelVehiclePhysics::LookupPoseParameter(this, szName: "vehicle_guage");
  this->m_poseParameters[10] = v2;
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: v2, flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[8], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[0], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[1], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[2], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[3], flValue: 0.0);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[72].SetRefEHandle)(a1: m_pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1012ED50
// Name: private: void CFourWheelVehiclePhysics::CalcWheelData(struct vehicleparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFourWheelVehiclePhysics::CalcWheelData(
        CFourWheelVehiclePhysics *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vehicleparams_t *vehicle)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  CBaseAnimating *v9; // ecx
  unsigned int v10; // eax
  CBaseAnimating *v11; // ecx
  unsigned int v12; // eax
  CBaseEntity *v13; // edi
  unsigned int v14; // eax
  CBaseEntity *v15; // edi
  float x; // xmm3_4
  float z; // xmm5_4
  float y; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  unsigned int v24; // eax
  CBaseAnimating *v25; // ecx
  unsigned int v26; // eax
  CBaseAnimating *v27; // ecx
  unsigned int v28; // eax
  CBaseEntity *v29; // edi
  unsigned int v30; // eax
  CBaseEntity *v31; // edi
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm4_4
  float v35; // xmm7_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  unsigned int v40; // eax
  IHandleEntity *v41; // ecx
  unsigned int v42; // eax
  CBaseAnimating *v43; // ecx
  unsigned int v44; // eax
  CBaseAnimating *v45; // ecx
  unsigned int v46; // eax
  CBaseEntity *v47; // edi
  unsigned int v48; // eax
  CBaseEntity *v49; // edi
  float v50; // xmm0_4
  float v51; // xmm1_4
  unsigned int v52; // eax
  CBaseAnimating *v53; // ecx
  unsigned int v54; // eax
  CBaseAnimating *v55; // ecx
  unsigned int v56; // eax
  CBaseEntity *v57; // edi
  unsigned int v58; // eax
  CBaseEntity *v59; // edi
  float v60; // xmm0_4
  float v61; // xmm1_4
  int v62; // edi
  float *m_wheelTotalHeight; // ebx
  unsigned int v64; // eax
  IHandleEntity *v65; // ecx
  const char *v66; // eax
  unsigned int v67; // eax
  int v68; // ebx
  CBaseAnimating *v69; // edi
  CStudioHdr *m_pStudioHdr; // eax
  unsigned int v71; // eax
  int v72; // ebx
  CBaseAnimating *v73; // edi
  CStudioHdr *v74; // eax
  unsigned int v75; // eax
  int v76; // ebx
  CBaseAnimating *v77; // edi
  CStudioHdr *v78; // eax
  unsigned int v79; // eax
  int v80; // ebx
  CBaseAnimating *v81; // edi
  CStudioHdr *v82; // eax
  unsigned int v83; // eax
  IHandleEntity *v84; // ecx
  unsigned int v85; // eax
  CBaseAnimating *v86; // ecx
  unsigned int v87; // eax
  CBaseAnimating *v88; // ecx
  unsigned int v89; // eax
  CBaseEntity *v90; // edi
  unsigned int v91; // eax
  CBaseEntity *v92; // edi
  vehicleparams_t *v93; // ebx
  float v94; // xmm3_4
  float v95; // xmm5_4
  float v96; // xmm4_4
  float v97; // xmm0_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  unsigned int v100; // eax
  CBaseAnimating *v101; // ecx
  unsigned int v102; // eax
  CBaseAnimating *v103; // ecx
  unsigned int v104; // eax
  CBaseEntity *v105; // edi
  unsigned int v106; // esi
  CBaseEntity *v107; // esi
  float v108; // xmm3_4
  float v109; // xmm5_4
  float v110; // xmm4_4
  float v111; // xmm0_4
  float v112; // xmm1_4
  float v113; // xmm2_4
  int v114; // [esp+0h] [ebp-4Ch]
  const char *pWheelAttachments[4]; // [esp+14h] [ebp-38h]
  QAngle dummy; // [esp+24h] [ebp-28h] BYREF
  Vector left; // [esp+30h] [ebp-1Ch] BYREF
  Vector right; // [esp+3Ch] [ebp-10h] BYREF
  _BYTE v120[4]; // [esp+48h] [ebp-4h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  v114 = this->m_poseParameters[0];
  pWheelAttachments[0] = "wheel_fl";
  pWheelAttachments[1] = "wheel_fr";
  pWheelAttachments[2] = "wheel_rl";
  pWheelAttachments[3] = "wheel_rr";
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: v114, flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[1], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[2], flValue: 0.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[3], flValue: 0.0);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, int, int, int))m_pEntity->__vftable[72].SetRefEHandle)(
    a1: m_pEntity,
    a2: a3,
    a3: a4,
    a4: a2);
  v8 = this->m_pOuter.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v9, szName: "wheel_fl", absOrigin: &left, absAngles: &dummy) )
  {
    v10 = this->m_pOuter.m_Index;
    if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
      v11 = nullptr;
    else
      v11 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
    if ( CBaseAnimating::GetAttachment(this: v11, szName: "wheel_fr", absOrigin: &right, absAngles: &dummy) )
    {
      v12 = this->m_pOuter.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      if ( (v13->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
      VectorITransform(in1: &left.x, in2: &v13->m_rgflCoordinateFrame, out: &left.x);
      v14 = this->m_pOuter.m_Index;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v15 = nullptr;
      else
        v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      if ( (v15->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v15, a2: (int)&savedregs);
      VectorITransform(in1: &right.x, in2: &v15->m_rgflCoordinateFrame, out: &right.x);
      x = right.x;
      z = right.z;
      y = right.y;
      v19 = left.z;
      v20 = left.y;
      v21 = (float)(right.x + left.x) * 0.5;
      vehicle->axles[0].offset.x = v21;
      v22 = (float)(v20 + y) * 0.5;
      vehicle->axles[0].offset.y = v22;
      v23 = (float)(z + v19) * 0.5;
      vehicle->axles[0].offset.z = v23;
      vehicle->axles[0].wheelOffset.x = x - v21;
      vehicle->axles[0].wheelOffset.y = y - v22;
      vehicle->axles[0].wheelOffset.z = z - v23;
      this->m_wheelBaseHeight[0] = v19;
      this->m_wheelBaseHeight[1] = z;
    }
  }
  v24 = this->m_pOuter.m_Index;
  if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
    v25 = nullptr;
  else
    v25 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v25, szName: "wheel_rl", absOrigin: &left, absAngles: &dummy) )
  {
    v26 = this->m_pOuter.m_Index;
    if ( v26 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
      v27 = nullptr;
    else
      v27 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
    if ( CBaseAnimating::GetAttachment(this: v27, szName: "wheel_rr", absOrigin: &right, absAngles: &dummy) )
    {
      v28 = this->m_pOuter.m_Index;
      if ( v28 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_SerialNumber != HIWORD(v28) )
        v29 = nullptr;
      else
        v29 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_pEntity;
      if ( (v29->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v29, a2: (int)&savedregs);
      VectorITransform(in1: &left.x, in2: &v29->m_rgflCoordinateFrame, out: &left.x);
      v30 = this->m_pOuter.m_Index;
      if ( v30 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v30].m_SerialNumber != HIWORD(v30) )
        v31 = nullptr;
      else
        v31 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v30].m_pEntity;
      if ( (v31->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v31, a2: (int)&savedregs);
      VectorITransform(in1: &right.x, in2: &v31->m_rgflCoordinateFrame, out: &right.x);
      v32 = right.x;
      v33 = right.z;
      v34 = right.y;
      v35 = left.z;
      v36 = left.y;
      v37 = (float)(right.x + left.x) * 0.5;
      vehicle->axles[1].offset.x = v37;
      v38 = (float)(v36 + v34) * 0.5;
      vehicle->axles[1].offset.y = v38;
      v39 = (float)(v33 + v35) * 0.5;
      vehicle->axles[1].offset.z = v39;
      vehicle->axles[1].wheelOffset.x = v32 - v37;
      vehicle->axles[1].wheelOffset.y = v34 - v38;
      vehicle->axles[1].wheelOffset.z = v33 - v39;
      this->m_wheelBaseHeight[2] = v35;
      this->m_wheelBaseHeight[3] = v33;
    }
  }
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[0], flValue: 1.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[1], flValue: 1.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[2], flValue: 1.0);
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[3], flValue: 1.0);
  v40 = this->m_pOuter.m_Index;
  if ( v40 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_SerialNumber != HIWORD(v40) )
    v41 = nullptr;
  else
    v41 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v40].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *))v41->__vftable[72].SetRefEHandle)(a1: v41);
  v42 = this->m_pOuter.m_Index;
  if ( v42 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42) )
    v43 = nullptr;
  else
    v43 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v43, szName: "wheel_fl", absOrigin: &left, absAngles: &dummy) )
  {
    v44 = this->m_pOuter.m_Index;
    if ( v44 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_SerialNumber != HIWORD(v44) )
      v45 = nullptr;
    else
      v45 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v44].m_pEntity;
    if ( CBaseAnimating::GetAttachment(this: v45, szName: "wheel_fr", absOrigin: &right, absAngles: &dummy) )
    {
      v46 = this->m_pOuter.m_Index;
      if ( v46 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_SerialNumber != HIWORD(v46) )
        v47 = nullptr;
      else
        v47 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v46].m_pEntity;
      if ( (v47->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v47, a2: (int)&savedregs);
      VectorITransform(in1: &left.x, in2: &v47->m_rgflCoordinateFrame, out: &left.x);
      v48 = this->m_pOuter.m_Index;
      if ( v48 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_SerialNumber != HIWORD(v48) )
        v49 = nullptr;
      else
        v49 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v48].m_pEntity;
      if ( (v49->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v49, a2: (int)&savedregs);
      VectorITransform(in1: &right.x, in2: &v49->m_rgflCoordinateFrame, out: &right.x);
      v50 = this->m_wheelBaseHeight[0] - left.z;
      v51 = this->m_wheelBaseHeight[1] - right.z;
      this->m_wheelTotalHeight[0] = v50;
      this->m_wheelTotalHeight[1] = v51;
      vehicle->axles[0].wheels.springAdditionalLength = v50;
    }
  }
  v52 = this->m_pOuter.m_Index;
  if ( v52 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v52].m_SerialNumber != HIWORD(v52) )
    v53 = nullptr;
  else
    v53 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v52].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v53, szName: "wheel_rl", absOrigin: &left, absAngles: &dummy) )
  {
    v54 = this->m_pOuter.m_Index;
    if ( v54 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v54].m_SerialNumber != HIWORD(v54) )
      v55 = nullptr;
    else
      v55 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v54].m_pEntity;
    if ( CBaseAnimating::GetAttachment(this: v55, szName: "wheel_rr", absOrigin: &right, absAngles: &dummy) )
    {
      v56 = this->m_pOuter.m_Index;
      if ( v56 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v56].m_SerialNumber != HIWORD(v56) )
        v57 = nullptr;
      else
        v57 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v56].m_pEntity;
      if ( (v57->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v57, a2: (int)&savedregs);
      VectorITransform(in1: &left.x, in2: &v57->m_rgflCoordinateFrame, out: &left.x);
      v58 = this->m_pOuter.m_Index;
      if ( v58 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v58].m_SerialNumber != HIWORD(v58) )
        v59 = nullptr;
      else
        v59 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v58].m_pEntity;
      if ( (v59->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v59, a2: (int)&savedregs);
      VectorITransform(in1: &right.x, in2: &v59->m_rgflCoordinateFrame, out: &right.x);
      v60 = this->m_wheelBaseHeight[0] - left.z;
      v61 = this->m_wheelBaseHeight[1] - right.z;
      this->m_wheelTotalHeight[2] = v60;
      this->m_wheelTotalHeight[3] = v61;
      vehicle->axles[1].wheels.springAdditionalLength = v60;
    }
  }
  v62 = 0;
  m_wheelTotalHeight = this->m_wheelTotalHeight;
  do
  {
    if ( *m_wheelTotalHeight == 0.0 )
    {
      v64 = this->m_pOuter.m_Index;
      if ( v64 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v64].m_SerialNumber != HIWORD(v64) )
        v65 = nullptr;
      else
        v65 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v64].m_pEntity;
      v66 = *(const char **)((int (__thiscall *)(IHandleEntity *, _BYTE *))v65->__vftable[2].SetRefEHandle)(
                              a1: v65,
                              a2: v120);
      if ( v66 == nullptr )
        v66 = locale;
      DevWarning(a1: "Vehicle %s has invalid wheel attachment for %s - no movement\n", v66, pWheelAttachments[v62]);
      *m_wheelTotalHeight = 1.0;
    }
    ++v62;
    ++m_wheelTotalHeight;
  }
  while ( v62 < 4 );
  v67 = this->m_pOuter.m_Index;
  v68 = this->m_poseParameters[0];
  if ( v67 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v67].m_SerialNumber != HIWORD(v67) )
    v69 = nullptr;
  else
    v69 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v67].m_pEntity;
  if ( v69->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v69) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v69);
  m_pStudioHdr = v69->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  CBaseAnimating::SetPoseParameter(this: v69, pStudioHdr: m_pStudioHdr, iParameter: v68, flValue: 0.0);
  v71 = this->m_pOuter.m_Index;
  v72 = this->m_poseParameters[1];
  if ( v71 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v71].m_SerialNumber != HIWORD(v71) )
    v73 = nullptr;
  else
    v73 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v71].m_pEntity;
  if ( v73->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v73) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v73);
  v74 = v73->m_pStudioHdr;
  if ( v74 == nullptr || v74->m_pStudioHdr == nullptr )
    v74 = nullptr;
  CBaseAnimating::SetPoseParameter(this: v73, pStudioHdr: v74, iParameter: v72, flValue: 0.0);
  v75 = this->m_pOuter.m_Index;
  v76 = this->m_poseParameters[2];
  if ( v75 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v75].m_SerialNumber != HIWORD(v75) )
    v77 = nullptr;
  else
    v77 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v75].m_pEntity;
  if ( v77->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v77) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v77);
  v78 = v77->m_pStudioHdr;
  if ( v78 == nullptr || v78->m_pStudioHdr == nullptr )
    v78 = nullptr;
  CBaseAnimating::SetPoseParameter(this: v77, pStudioHdr: v78, iParameter: v76, flValue: 0.0);
  v79 = this->m_pOuter.m_Index;
  v80 = this->m_poseParameters[3];
  if ( v79 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v79].m_SerialNumber != HIWORD(v79) )
    v81 = nullptr;
  else
    v81 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v79].m_pEntity;
  if ( v81->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v81) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v81);
  v82 = v81->m_pStudioHdr;
  if ( v82 == nullptr || v82->m_pStudioHdr == nullptr )
    v82 = nullptr;
  CBaseAnimating::SetPoseParameter(this: v81, pStudioHdr: v82, iParameter: v80, flValue: 0.0);
  v83 = this->m_pOuter.m_Index;
  if ( v83 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v83].m_SerialNumber != HIWORD(v83) )
    v84 = nullptr;
  else
    v84 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v83].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *))v84->__vftable[72].SetRefEHandle)(a1: v84);
  v85 = this->m_pOuter.m_Index;
  if ( v85 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v85].m_SerialNumber != HIWORD(v85) )
    v86 = nullptr;
  else
    v86 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v85].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v86, szName: "raytrace_fl", absOrigin: &left, absAngles: &dummy)
    && ((v87 = this->m_pOuter.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v87].m_SerialNumber != HIWORD(v87)
      ? (v88 = nullptr)
      : (v88 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v87].m_pEntity),
        CBaseAnimating::GetAttachment(this: v88, szName: "raytrace_fr", absOrigin: &right, absAngles: &dummy)) )
  {
    v89 = this->m_pOuter.m_Index;
    if ( v89 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v89].m_SerialNumber != HIWORD(v89) )
      v90 = nullptr;
    else
      v90 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v89].m_pEntity;
    if ( (v90->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v90, a2: (int)&savedregs);
    VectorITransform(in1: &left.x, in2: &v90->m_rgflCoordinateFrame, out: &left.x);
    v91 = this->m_pOuter.m_Index;
    if ( v91 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v91].m_SerialNumber != HIWORD(v91) )
      v92 = nullptr;
    else
      v92 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v91].m_pEntity;
    if ( (v92->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v92, a2: (int)&savedregs);
    VectorITransform(in1: &right.x, in2: &v92->m_rgflCoordinateFrame, out: &right.x);
    v93 = vehicle;
    v94 = right.x;
    v95 = right.z;
    v96 = right.y;
    v97 = (float)(right.x + left.x) * 0.5;
    v98 = (float)(left.y + right.y) * 0.5;
    v99 = (float)(right.z + left.z) * 0.5;
    vehicle->axles[0].raytraceCenterOffset.x = v97;
    vehicle->axles[0].raytraceCenterOffset.y = v98;
    vehicle->axles[0].raytraceCenterOffset.z = v99;
    vehicle->axles[0].raytraceOffset.x = v94 - v97;
    vehicle->axles[0].raytraceOffset.y = v96 - v98;
    vehicle->axles[0].raytraceOffset.z = v95 - v99;
  }
  else
  {
    v93 = vehicle;
  }
  v100 = this->m_pOuter.m_Index;
  if ( v100 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v100].m_SerialNumber != HIWORD(v100) )
    v101 = nullptr;
  else
    v101 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v100].m_pEntity;
  if ( CBaseAnimating::GetAttachment(this: v101, szName: "raytrace_rl", absOrigin: &left, absAngles: &dummy) )
  {
    v102 = this->m_pOuter.m_Index;
    if ( v102 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v102].m_SerialNumber != HIWORD(v102) )
      v103 = nullptr;
    else
      v103 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v102].m_pEntity;
    if ( CBaseAnimating::GetAttachment(this: v103, szName: "raytrace_rr", absOrigin: &right, absAngles: &dummy) )
    {
      v104 = this->m_pOuter.m_Index;
      if ( v104 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v104].m_SerialNumber != HIWORD(v104) )
        v105 = nullptr;
      else
        v105 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v104].m_pEntity;
      if ( (v105->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v105, a2: (int)&savedregs);
      VectorITransform(in1: &left.x, in2: &v105->m_rgflCoordinateFrame, out: &left.x);
      v106 = this->m_pOuter.m_Index;
      if ( v106 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v106].m_SerialNumber != HIWORD(v106) )
        v107 = nullptr;
      else
        v107 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v106].m_pEntity;
      if ( (v107->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v107, a2: (int)&savedregs);
      VectorITransform(in1: &right.x, in2: &v107->m_rgflCoordinateFrame, out: &right.x);
      v108 = right.x;
      v109 = right.z;
      v110 = right.y;
      v111 = (float)(right.x + left.x) * 0.5;
      v112 = (float)(left.y + right.y) * 0.5;
      v113 = (float)(right.z + left.z) * 0.5;
      v93->axles[1].raytraceCenterOffset.x = v111;
      v93->axles[1].raytraceCenterOffset.y = v112;
      v93->axles[1].raytraceCenterOffset.z = v113;
      v93->axles[1].raytraceOffset.x = v108 - v111;
      v93->axles[1].raytraceOffset.y = v110 - v112;
      v93->axles[1].raytraceOffset.z = v109 - v113;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FAE0
// Name: public: void CFourWheelVehiclePhysics::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::Spawn(CFourWheelVehiclePhysics *this)
{
  this->m_actionValue = 0.0;
  this->m_actionSpeed = 0.0;
  this->m_maxThrottle = 1.0;
  this->m_bIsOn = false;
  *(_WORD *)&this->m_controls.handbrake = 0;
  this->m_controls.handbrakeRight = false;
  *(_WORD *)&this->m_controls.bHasBrakePedal = 1;
  this->m_flMaxRevThrottle = -1.0;
  CFourWheelVehiclePhysics::InitializePoseParameters(this);
}

//------------------------------------------------------------------------------
// Address: 0x1012FB30
// Name: public: void CFourWheelVehiclePhysics::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::DrawDebugGeometryOverlays(CFourWheelVehiclePhysics *this)
{
  int v2; // edi
  IPhysicsObject *v3; // esi
  IPhysicsObject *v4; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float *p_z; // edi
  float *v8; // esi
  float v9; // xmm4_4
  float v10; // xmm1_4
  IPhysicsObject *v11; // eax
  vehicle_debugcarsystem_t debugCarSystem; // [esp+34h] [ebp-590h] BYREF
  vehicleparams_t vehicleParams; // [esp+238h] [ebp-38Ch]
  matrix3x4_t matrix; // [esp+4D8h] [ebp-ECh] BYREF
  Vector vecAxlePositionsHL[2]; // [esp+508h] [ebp-BCh] BYREF
  Vector v16; // [esp+520h] [ebp-A4h] BYREF
  Vector mins; // [esp+52Ch] [ebp-98h] BYREF
  Vector maxs; // [esp+538h] [ebp-8Ch] BYREF
  Vector v19; // [esp+544h] [ebp-80h] BYREF
  Vector vecAxlePositions[2]; // [esp+550h] [ebp-74h] BYREF
  Vector v21; // [esp+568h] [ebp-5Ch] BYREF
  Vector v22; // [esp+574h] [ebp-50h] BYREF
  Vector vecBodyPosition; // [esp+580h] [ebp-44h] BYREF
  Vector vecImpact; // [esp+58Ch] [ebp-38h] BYREF
  QAngle angBodyDirection; // [esp+598h] [ebp-2Ch] BYREF
  IPhysicsObject *pBody; // [esp+5A4h] [ebp-20h]
  Vector vecEnd; // [esp+5A8h] [ebp-1Ch] BYREF
  Vector vecStart; // [esp+5B4h] [ebp-10h] BYREF
  int iWheel; // [esp+5C0h] [ebp-4h]

  v2 = 0;
  if ( this->m_wheelCount > 0 )
  {
    pBody = (IPhysicsObject *)this->m_wheelPosition;
    do
    {
      v3 = this->m_pVehicle->GetWheel(this: this->m_pVehicle, a2: v2);
      *(float *)&iWheel = v3->GetSphereRadius(this: v3);
      v3->GetPosition(this: v3, a2: &vecImpact, a3: (QAngle *)&vecBodyPosition);
      NDebugOverlay::Sphere(
        position: &vecImpact,
        angles: (const QAngle *)&vecBodyPosition,
        radius: *(float *)&iWheel,
        r: 0,
        g: 255,
        b: 0,
        a: 0,
        bNoDepthTest: 0,
        flDuration: 0.0);
      v4 = pBody;
      NDebugOverlay::Sphere(
        position: (const Vector *)pBody,
        angles: (const QAngle *)&pBody[12],
        radius: *(float *)&iWheel,
        r: 255,
        g: 255,
        b: 0,
        a: 0,
        bNoDepthTest: 0,
        flDuration: 0.0);
      ++v2;
      pBody = v4 + 3;
    }
    while ( v2 < this->m_wheelCount );
  }
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  pBody = (IPhysicsObject *)m_pEntity[82].__vftable;
  if ( pBody != nullptr )
  {
    vehicleParams = *this->m_pVehicle->GetVehicleParams(this: this->m_pVehicle);
    pBody->GetPosition(this: pBody, a2: &vecBodyPosition, a3: &angBodyDirection);
    vecEnd.x = 5.0;
    vecEnd.y = 5.0;
    vecEnd.z = 5.0;
    vecStart.x = -5.0;
    vecStart.y = -5.0;
    vecStart.z = -5.0;
    NDebugOverlay::BoxAngles(
      origin: &vecBodyPosition,
      mins: &vecStart,
      maxs: &vecEnd,
      angles: &angBodyDirection,
      r: 255,
      g: 0,
      b: 0,
      a: 0,
      duration: 0.0);
    AngleMatrix(angles: &angBodyDirection, position: &vecBodyPosition, &matrix);
    vecAxlePositions[0] = vehicleParams.axles[0].offset;
    vecAxlePositions[1] = vehicleParams.axles[1].offset;
    VectorTransform(in1: &vecAxlePositions[0].x, in2: &matrix, out: &vecAxlePositionsHL[0].x);
    VectorTransform(in1: &vecAxlePositions[1].x, in2: &matrix, out: &vecAxlePositionsHL[1].x);
    vecEnd.x = 3.0;
    vecEnd.y = 3.0;
    vecEnd.z = 3.0;
    vecStart.x = -3.0;
    vecStart.y = -3.0;
    vecStart.z = -3.0;
    NDebugOverlay::BoxAngles(
      origin: vecAxlePositionsHL,
      mins: &vecStart,
      maxs: &vecEnd,
      angles: &angBodyDirection,
      r: 0,
      g: 255,
      b: 0,
      a: 0,
      duration: 0.0);
    vecEnd.x = 3.0;
    vecEnd.y = 3.0;
    vecEnd.z = 3.0;
    vecStart.x = -3.0;
    vecStart.y = -3.0;
    vecStart.z = -3.0;
    NDebugOverlay::BoxAngles(
      origin: &vecAxlePositionsHL[1],
      mins: &vecStart,
      maxs: &vecEnd,
      angles: &angBodyDirection,
      r: 0,
      g: 255,
      b: 0,
      a: 0,
      duration: 0.0);
    this->m_pVehicle->GetCarSystemDebugData(this: this->m_pVehicle, a2: &debugCarSystem);
    *(float *)&iWheel = 0.0;
    p_z = &debugCarSystem.vecWheelRaycastImpacts[0].z;
    v8 = &debugCarSystem.vecWheelRaycasts[0][0].z;
    do
    {
      vecStart.z = -(float)(*(v8 - 1) * 39.370079);
      vecStart.y = *v8 * 39.370079;
      vecStart.x = *(v8 - 2) * 39.370079;
      vecEnd.z = -(float)(v8[2] * 39.370079);
      vecEnd.y = v8[3] * 39.370079;
      vecEnd.x = v8[1] * 39.370079;
      v9 = *(p_z - 1);
      vecImpact.y = *p_z * 39.370079;
      v10 = *(p_z - 2) * 39.370079;
      vecImpact.z = -(float)(v9 * 39.370079);
      vecImpact.x = v10;
      maxs.x = 1.0;
      maxs.y = 1.0;
      maxs.z = 1.0;
      mins.x = -1.0;
      mins.y = -1.0;
      mins.z = -1.0;
      NDebugOverlay::BoxAngles(
        origin: &vecStart,
        &mins,
        &maxs,
        angles: &angBodyDirection,
        r: 0,
        g: 255,
        b: 0,
        a: 0,
        duration: 0.0);
      NDebugOverlay::Line(origin: &vecStart, target: &vecEnd, r: 255, g: 255, b: 0, noDepthTest: 1, duration: 0.0);
      v21.x = 1.0;
      v21.y = 1.0;
      v21.z = 1.0;
      v22.x = -1.0;
      v22.y = -1.0;
      v22.z = -1.0;
      NDebugOverlay::BoxAngles(
        origin: &vecEnd,
        mins: &v22,
        maxs: &v21,
        angles: &angBodyDirection,
        r: 255,
        g: 0,
        b: 0,
        a: 0,
        duration: 0.0);
      v19.x = 0.5;
      v19.y = 0.5;
      v19.z = 0.5;
      v16.x = -0.5;
      v16.y = -0.5;
      v16.z = -0.5;
      NDebugOverlay::BoxAngles(
        origin: &vecImpact,
        mins: &v16,
        maxs: &v19,
        angles: &angBodyDirection,
        r: 0,
        g: 0,
        b: 255,
        a: 0,
        duration: 0.0);
      v11 = this->m_pVehicle->GetWheel(this: this->m_pVehicle, a2: iWheel);
      DebugDrawContactPoints(pPhysics: v11);
      v8 += 6;
      p_z += 3;
      ++iWheel;
    }
    while ( iWheel < 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130050
// Name: public: int CFourWheelVehiclePhysics::DrawDebugTextOverlays(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFourWheelVehiclePhysics::DrawDebugTextOverlays(CFourWheelVehiclePhysics *this, int nOffset)
{
  const vehicle_operatingparams_t *v3; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v6; // esi
  CBaseEntity *v7; // eax
  char tempstr[512]; // [esp+2Ch] [ebp-200h] BYREF

  v3 = this->m_pVehicle->GetOperatingParams(this: this->m_pVehicle);
  V_snprintf(
    pDest: tempstr,
    maxLen: 512,
    pFormat: "Speed %.1f  T/S/B (%.0f/%.0f/%.1f)",
    v3->speed,
    this->m_controls.throttle,
    this->m_controls.steering,
    this->m_controls.brake);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBaseEntity::EntityText(
    this: m_pEntity,
    text_offset: nOffset,
    text: tempstr,
    duration: 0.0,
    r: 255,
    g: 255,
    b: 255,
    a: 255);
  _Msg(a1: "%s", tempstr);
  V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Gear: %d, RPM %4d", v3->gear, (int)v3->engineRPM);
  v6 = this->m_pOuter.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  CBaseEntity::EntityText(
    this: v7,
    text_offset: nOffset + 1,
    text: tempstr,
    duration: 0.0,
    r: 255,
    g: 255,
    b: 255,
    a: 255);
  _Msg(a1: " %s\n", tempstr);
  return nOffset + 2;
}

//------------------------------------------------------------------------------
// Address: 0x101301C0
// Name: public: bool CFourWheelVehiclePhysics::Think(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFourWheelVehiclePhysics::Think(CFourWheelVehiclePhysics *this)
{
  IPhysicsVehicleController *m_pVehicle; // ecx
  const vehicle_operatingparams_t *v4; // eax
  IPhysicsVehicleController *v5; // ecx
  const vehicle_operatingparams_t *v6; // ebx
  const vehicleparams_t *(__thiscall *GetVehicleParams)(IPhysicsVehicleController *); // edx
  const vehicleparams_t *v8; // eax
  float v9; // xmm0_4
  IPhysicsVehicleController *v10; // ecx
  const vehicleparams_t *v11; // edi
  const vehicle_operatingparams_t *v12; // eax
  const vehicleparams_t *v13; // edi
  const vehicle_operatingparams_t *v14; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v17; // ecx
  bool m_bLastSkid; // bl
  float v19; // xmm1_4
  CBaseEntity *v20; // eax
  int i; // edi
  CFourWheelServerVehicle *m_pOuterServerVehicle; // ecx
  int j; // edi
  unsigned int v24; // eax
  CBaseAnimating *v25; // ecx
  double PoseParameter; // st7
  float v27; // xmm0_4
  float flValue; // xmm0_4
  int C; // [esp+14h] [ebp-40h]
  float D; // [esp+18h] [ebp-3Ch]
  CPASAttenuationFilter filter; // [esp+28h] [ebp-2Ch] BYREF
  float skidThreshold; // [esp+48h] [ebp-Ch]
  const vehicleparams_t *vehicleData; // [esp+4Ch] [ebp-8h]
  const vehicle_operatingparams_t *carState; // [esp+50h] [ebp-4h]

  m_pVehicle = this->m_pVehicle;
  if ( m_pVehicle == nullptr )
    return false;
  v4 = m_pVehicle->GetOperatingParams(this: m_pVehicle);
  v5 = this->m_pVehicle;
  v6 = v4;
  GetVehicleParams = v5->GetVehicleParams;
  carState = v4;
  v8 = GetVehicleParams(this: v5);
  v9 = v6->speed * 0.056818184;
  this->m_nLastSpeed = this->m_nSpeed;
  this->m_nSpeed = (int)fabs(v9);
  this->m_nRPM = (int)v6->engineRPM;
  v10 = this->m_pVehicle;
  this->m_nHasBoost = (int)v8->engine.boostDelay;
  vehicleData = v8;
  ((void (__stdcall *)(_DWORD, vehicle_controlparams_t *))v10->Update)(
    a1: LODWORD(gpGlobals->frametime),
    a2: &this->m_controls);
  v11 = this->m_pVehicle->GetVehicleParams(this: this->m_pVehicle);
  v12 = this->m_pVehicle->GetOperatingParams(this: this->m_pVehicle);
  if ( v11 != nullptr
    && v12 != nullptr
    && (float)(v12->boostDelay - v11->engine.boostDelay) > 0.0
    && !this->m_bLastBoost )
  {
    this->m_bLastBoost = true;
    this->m_turboTimer = gpGlobals->curtime + 2.75;
  }
  else
  {
    v13 = this->m_pVehicle->GetVehicleParams(this: this->m_pVehicle);
    v14 = this->m_pVehicle->GetOperatingParams(this: this->m_pVehicle);
    if ( (v13 == nullptr || v14 == nullptr || (float)(v14->boostDelay - v13->engine.boostDelay) <= 0.0)
      && this->m_bLastBoost
      && gpGlobals->curtime >= this->m_turboTimer )
    {
      this->m_bLastBoost = false;
    }
  }
  this->m_fLastBoost = v6->boostDelay;
  this->m_nBoostTimeLeft = v6->boostTimeLeft;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity[82].__vftable != nullptr )
  {
    v17 = m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        ? nullptr
        : g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( (*((int (__thiscall **)(IHandleEntity_vtbl *))v17[82].dtr_IHandleEntity + 71))(a1: v17[82].__vftable) == 0 )
    {
      m_bLastSkid = this->m_bLastSkid;
      if ( m_bLastSkid )
      {
        v19 = 10.0;
      }
      else
      {
        v19 = carState->speed * 0.15000001;
        if ( v19 < 10.0 )
        {
          skidThreshold = RemapValClamped(
                            val: COERCE_FLOAT(LODWORD(carState->speed) & _mask__AbsFloat_),
                            A: 0.0,
                            B: 66.666664,
                            C: 80.0,
                            D: 10.0);
          v19 = skidThreshold;
        }
      }
      if ( carState->skidSpeed > v19 && this->m_bIsOn )
      {
        if ( !m_bLastSkid )
        {
          this->m_bLastSkid = true;
          v20 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pOuter);
          CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: v20, attenuation: 0.80000001);
          this->m_pOuterServerVehicle->PlaySound(this: this->m_pOuterServerVehicle, a2: VS_SKID_FRICTION_NORMAL);
          CRecipientFilter::~CRecipientFilter(this: &filter);
        }
        for ( i = 0; i < 4; ++i )
          CFourWheelVehiclePhysics::PlaceWheelDust(this, wheelIndex: i, ignoreSpeed: true);
      }
      else if ( m_bLastSkid )
      {
        m_pOuterServerVehicle = this->m_pOuterServerVehicle;
        this->m_bLastSkid = false;
        m_pOuterServerVehicle->StopSound(this: m_pOuterServerVehicle, a2: VS_SKID_FRICTION_NORMAL);
      }
      if ( this->m_nSpeed >= 5 && vehicleData->steering.dustCloud && this->m_bIsOn )
      {
        for ( j = 0; j < 4; ++j )
          CFourWheelVehiclePhysics::PlaceWheelDust(this, wheelIndex: j, ignoreSpeed: false);
      }
      v6 = carState;
    }
  }
  v24 = this->m_pOuter.m_Index;
  if ( v24 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
    v25 = nullptr;
  else
    v25 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
  PoseParameter = CBaseAnimating::GetPoseParameter(this: v25, iParameter: this->m_poseParameters[8]);
  D = v6->steeringAngle / vehicleData->steering.degreesSlow * 0.2 + PoseParameter * 0.8;
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[8], flValue: D);
  v27 = (float)((float)(this->m_actionScale * this->m_actionSpeed) * gpGlobals->frametime) + this->m_actionValue;
  C = this->m_poseParameters[9];
  this->m_actionValue = v27;
  CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: C, flValue: v27);
  if ( this->m_bIsOn )
  {
    flValue = (double)this->m_nSpeed * 0.01;
    CFourWheelVehiclePhysics::SetPoseParameter(this, iParameter: this->m_poseParameters[10], flValue);
  }
  return this->m_bIsOn;
}

//------------------------------------------------------------------------------
// Address: 0x101305B0
// Name: public: bool CFourWheelVehiclePhysics::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFourWheelVehiclePhysics::VPhysicsUpdate(CFourWheelVehiclePhysics *this, IPhysicsObject *pPhysics)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  int m_wheelCount; // edx
  int v7; // esi
  IPhysicsObject **i; // eax
  IPhysicsObject *v9; // eax
  IPhysicsObject_vtbl *v10; // ebx
  unsigned int v11; // eax
  CBaseEntity *v12; // ebx
  Vector tmp; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF
  IPhysicsObject *pPhysicsa; // [esp+2Ch] [ebp+8h]

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pPhysics == (IPhysicsObject *)m_pEntity[82].__vftable )
    return 1;
  m_wheelCount = this->m_wheelCount;
  v7 = 0;
  if ( m_wheelCount > 0 )
  {
    for ( i = this->m_pWheels; pPhysics != *i; ++i )
    {
      if ( ++v7 >= m_wheelCount )
        return 0;
    }
    v9 = (IPhysicsObject *)((char *)this + 12 * v7);
    v10 = pPhysics->__vftable;
    pPhysicsa = v9 + 25;
    ((void (__stdcall *)(IPhysicsObject *, IPhysicsObject *))v10->GetPosition)(a1: &v9[25], a2: &v9[37]);
    v11 = this->m_pOuter.m_Index;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v12 = nullptr;
    else
      v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    if ( (v12->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v12, a2: (int)&savedregs);
    VectorITransform(in1: (const float *)pPhysicsa, in2: &v12->m_rgflCoordinateFrame, out: &tmp.x);
    CFourWheelVehiclePhysics::SetPoseParameter(
      this,
      iParameter: this->m_poseParameters[v7],
      flValue: (float)(this->m_wheelBaseHeight[v7] - tmp.z) / this->m_wheelTotalHeight[v7]);
    CFourWheelVehiclePhysics::SetPoseParameter(
      this,
      iParameter: this->m_poseParameters[v7 + 4],
      flValue: COERCE_FLOAT(LODWORD(this->m_wheelRotation[v7].z) ^ _mask__NegFloat_));
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10130700
// Name: public: int CFourWheelVehiclePhysics::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFourWheelVehiclePhysics::VPhysicsGetObjectList(
        CFourWheelVehiclePhysics *this,
        IPhysicsObject **pList,
        int listMax)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  IPhysicsObject *v5; // edx
  int result; // eax
  IPhysicsObject *v7; // edx
  IPhysicsObject *v8; // edx
  IPhysicsObject *v9; // edx
  IPhysicsObject *v10; // ecx

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (IPhysicsObject *)m_pEntity[82].__vftable;
  result = 0;
  if ( v5 != nullptr && listMax > 0 )
  {
    *pList = v5;
    result = 1;
  }
  v7 = this->m_pWheels[0];
  if ( v7 != nullptr && result < listMax )
    pList[result++] = v7;
  v8 = this->m_pWheels[1];
  if ( v8 != nullptr && result < listMax )
    pList[result++] = v8;
  v9 = this->m_pWheels[2];
  if ( v9 != nullptr && result < listMax )
    pList[result++] = v9;
  v10 = this->m_pWheels[3];
  if ( v10 != nullptr && result < listMax )
    pList[result++] = v10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10130790
// Name: private: bool CFourWheelVehiclePhysics::ParseVehicleScript(char const __near *,struct solid_t __near &,struct vehicleparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CFourWheelVehiclePhysics::ParseVehicleScript@<al>(
        CFourWheelVehiclePhysics *this@<ecx>,
        int a2@<ebx>,
        const char *pScriptName,
        solid_t *solid,
        vehicleparams_t *vehicle)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v8; // esi
  int v9; // eax
  float x; // xmm0_4
  float massOverride; // xmm0_4
  bool result; // al

  PhysFindOrAddVehicleScript(pScriptName, pParams: vehicle, pSounds: nullptr);
  this->m_debugRadius = vehicle->axles[0].wheels.radius;
  CFourWheelVehiclePhysics::CalcWheelData(this, a2, a3: (int)vehicle, a4: (int)this, vehicle);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v8 = nullptr;
  else
    v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v9 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[2].dtr_IHandleEntity)(a1: m_pEntity);
  PhysModelParseSolid(solid, pEntity: v8, modelIndex: v9);
  x = vehicle->body.massCenterOverride.x;
  if ( vec3_origin.x != x
    || vec3_origin.y != vehicle->body.massCenterOverride.y
    || vec3_origin.z != vehicle->body.massCenterOverride.z )
  {
    solid->massCenterOverride.x = x;
    solid->massCenterOverride.y = vehicle->body.massCenterOverride.y;
    solid->massCenterOverride.z = vehicle->body.massCenterOverride.z;
    solid->params.massCenterOverride = &solid->massCenterOverride;
  }
  massOverride = vehicle->body.massOverride;
  result = true;
  if ( massOverride > 0.0 )
    solid->params.mass = massOverride;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101308A0
// Name: public: bool CFourWheelVehiclePhysics::Initialize(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CFourWheelVehiclePhysics::Initialize@<al>(
        CFourWheelVehiclePhysics *this@<ecx>,
        int a2@<ebx>,
        const char *pVehicleScript,
        unsigned int nVehicleType)
{
  CBaseEntityList *v4; // edx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity *v8; // ecx
  unsigned int v9; // eax
  IHandleEntity *v10; // ecx
  unsigned int v11; // edi
  unsigned int v13; // eax
  CBaseEntity *v14; // ecx
  IPhysicsObject *inited; // esi
  unsigned __int16 v16; // ax
  IPhysicsVehicleController *v17; // eax
  int v18; // eax
  int v19; // esi
  IPhysicsObject **m_pWheels; // ebx
  solid_t solid; // [esp+8h] [ebp-8E0h] BYREF
  vehicleparams_t vehicle; // [esp+648h] [ebp-2A0h] BYREF

  v4 = g_pEntityList;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity[82].__vftable != nullptr )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v8 = nullptr;
    else
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    (*((void (__thiscall **)(IHandleEntity_vtbl *, _DWORD))v8[82].dtr_IHandleEntity + 12))(a1: v8[82].__vftable, a2: 0);
    v4 = g_pEntityList;
  }
  v9 = this->m_pOuter.m_Index;
  if ( v9 == -1 || v4->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
    v10 = nullptr;
  else
    v10 = v4->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *))v10->__vftable[50].SetRefEHandle)(a1: v10);
  if ( CFourWheelVehiclePhysics::ParseVehicleScript(this, a2, pScriptName: pVehicleScript, &solid, &vehicle) )
  {
    this->m_throttleRate = 10000.0;
    if ( vehicle.engine.throttleTime > 0.0 )
      this->m_throttleRate = 1.0 / vehicle.engine.throttleTime;
    this->m_flMaxSpeed = vehicle.engine.maxSpeed;
    v13 = this->m_pOuter.m_Index;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    inited = CBaseEntity::VPhysicsInitNormal(
               this: v14,
               solidType: SOLID_VPHYSICS,
               nSolidFlags: 0,
               createAsleep: false,
               pSolid: &solid);
    v16 = inited->GetGameFlags(this: inited);
    inited->SetGameFlags(this: inited, a2: v16 | 0x8010);
    v17 = physenv->CreateVehicleController(this: physenv, a2: inited, a3: &vehicle, a4: nVehicleType, a5: physgametrace);
    this->m_pVehicle = v17;
    v18 = v17->GetWheelCount(this: v17);
    v19 = 0;
    this->m_wheelCount = v18;
    if ( v18 > 0 )
    {
      m_pWheels = this->m_pWheels;
      do
        *m_pWheels++ = this->m_pVehicle->GetWheel(this: this->m_pVehicle, a2: v19++);
      while ( v19 < this->m_wheelCount );
    }
    return 1;
  }
  else
  {
    v11 = this->m_pOuter.m_Index;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    {
      UTIL_Remove(oldObj: nullptr);
      return 0;
    }
    else
    {
      UTIL_Remove(oldObj: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10346B80
// Name: public: void CFourWheelVehiclePhysics::SetThrottle(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFourWheelVehiclePhysics::SetThrottle(CFlexAnimationTrack *this, float value)
{
  this->m_flMax = value;
}

//------------------------------------------------------------------------------
// Address: 0x104039B0
// Name: CFourWheelVehiclePhysics_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFourWheelVehiclePhysics_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFourWheelVehiclePhysics>(__formal: nullptr);
  CFourWheelVehiclePhysics_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040C520
// Name: _dynamic_initializer_for__vehicle_flushscript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__vehicle_flushscript_command__()
{
  ConCommand::ConCommand(
    this: &vehicle_flushscript_command,
    pName: "vehicle_flushscript",
    callback: (void (__cdecl *)())vehicle_flushscript,
    pHelpString: "Flush and reload all vehicle scripts",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__vehicle_flushscript_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041EE40
// Name: _dynamic_atexit_destructor_for__vehicle_flushscript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vehicle_flushscript_command__()
{
  ConCommand::~ConCommand(this: &vehicle_flushscript_command);
}

//------------------------------------------------------------------------------
// Address: 0x10130AC0
// Name: struct datamap_t __near * DataMapInit<class CFourWheelVehiclePhysics>(class CFourWheelVehiclePhysics __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFourWheelVehiclePhysics>()
{
  if ( (_S2_110 & 1) == 0 )
  {
    _S2_110 |= 1u;
    nameHolder_207.m_pszBase = "CFourWheelVehiclePhysics";
    nameHolder_207.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_207.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_207.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_207.m_Names.m_Size = 0;
    nameHolder_207.m_Names.m_pElements = nullptr;
    nameHolder_207.m_nLenBase = 24;
    atexit(func: DataMapInit_CFourWheelVehiclePhysics__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFourWheelVehiclePhysics::m_DataMap.baseMap = nullptr;
  CFourWheelVehiclePhysics::m_DataMap.dataNumFields = 37;
  CFourWheelVehiclePhysics::m_DataMap.dataDesc = &dataDesc_197[1];
  return &CFourWheelVehiclePhysics::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040C550
// Name: _dynamic_initializer_for__g_CPropVehicleDriveable_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPropVehicleDriveable_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPropVehicleDriveable_ClassReg,
           pNetworkName: "CPropVehicleDriveable",
           pTable: &DT_PropVehicleDriveable::g_SendTable);
}
