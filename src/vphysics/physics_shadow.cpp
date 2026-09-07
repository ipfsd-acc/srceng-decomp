// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_shadow.cpp
// Functions: 79
// ============================================================

#include "vphysics\physics_shadow.h"

//------------------------------------------------------------------------------
// Address: 0x10007D90
// Name: public: virtual class IPhysicsObject __near * CPlayerController::GetObject(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerController::GetObject(CCollisionQuery *this)
{
  return this->m_ledges.n_elems;
}

//------------------------------------------------------------------------------
// Address: 0x100108A0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY CShadowController::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowController::get_controller_priority(CDragController *this)
{
  return 500;
}

//------------------------------------------------------------------------------
// Address: 0x10016AD0
// Name: void DestroyPlayerController(class IPhysicsPlayerController __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyPlayerController(IPhysicsFrictionSnapshot *pSnapshot)
{
  if ( pSnapshot != nullptr )
    ((void (__thiscall *)(IPhysicsFrictionSnapshot *, int))pSnapshot->dtr_IPhysicsFrictionSnapshot)(
      a1: pSnapshot,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10019A20
// Name: public: virtual void CPlayerController::SetEventHandler(class IPhysicsPlayerControllerEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::SetEventHandler(CPhysicsObject *this, unsigned int contents)
{
  this->m_contentsMask = contents;
}

//------------------------------------------------------------------------------
// Address: 0x1001E6D0
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY CPlayerController::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerController::get_controller_priority(CPlayerController *this)
{
  return 501;
}

//------------------------------------------------------------------------------
// Address: 0x1001E6E0
// Name: public: virtual char const __near * CPlayerController::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPlayerController::get_controller_name(CPlayerController *this)
{
  return "vphysics:player";
}

//------------------------------------------------------------------------------
// Address: 0x1001E6F0
// Name: public: virtual void CPlayerController::SetPushMassLimit(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::SetPushMassLimit(CPlayerController *this, float maxPushMass)
{
  this->m_secondsToArrival = maxPushMass;
}

//------------------------------------------------------------------------------
// Address: 0x1001E710
// Name: public: virtual void CPlayerController::SetPushSpeedLimit(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::SetPushSpeedLimit(CPlayerController *this, float maxPushSpeed)
{
  this->m_pushableMassLimit = maxPushSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x1001E730
// Name: public: virtual float CPlayerController::GetPushMassLimit(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPlayerController::GetPushMassLimit(CPlayerController *this)
{
  return this->m_secondsToArrival;
}

//------------------------------------------------------------------------------
// Address: 0x1001E740
// Name: public: virtual float CPlayerController::GetPushSpeedLimit(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPlayerController::GetPushSpeedLimit(CPlayerController *this)
{
  return this->m_pushableMassLimit;
}

//------------------------------------------------------------------------------
// Address: 0x1001E750
// Name: public: virtual void CPlayerController::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::event_object_deleted(CPlayerController *this, IVP_Event_Object *pEvent)
{
  this->m_saveRot.k[2] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E770
// Name: public: virtual bool CPlayerController::IsInContact(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerController::IsInContact(CPlayerController *this)
{
  return ((int (__thiscall *)(CPlayerController *, _DWORD))this->IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable[1].get_controller_name)(
           a1: this,
           a2: 0)
       & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001E780
// Name: public: virtual void CPredictedPlayerController::SetCallOrderRegistrar(class CPredictableControllerSimulationOrderTracker __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::SetCallOrderRegistrar(
        CPredictedPlayerController *this,
        CPredictableControllerSimulationOrderTracker *pRegistrar)
{
  this->m_pCallOrderRegistrar = pRegistrar;
}

//------------------------------------------------------------------------------
// Address: 0x1001E790
// Name: public: virtual char const __near * CShadowController::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CShadowController::get_controller_name(CShadowController *this)
{
  return "vphysics:shadow";
}

//------------------------------------------------------------------------------
// Address: 0x1001E7A0
// Name: public: virtual bool CShadowController::AllowsTranslation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowController::AllowsTranslation(CShadowController *this)
{
  return (BYTE2(this->m_secondsToArrival) & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7B0
// Name: public: virtual bool CShadowController::AllowsRotation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowController::AllowsRotation(CShadowController *this)
{
  return (BYTE2(this->m_secondsToArrival) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7C0
// Name: public: virtual void CShadowController::SetPhysicallyControlled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::SetPhysicallyControlled(CShadowController *this, bool isPhysicallyControlled)
{
  BYTE2(this->m_secondsToArrival) ^= (BYTE2(this->m_secondsToArrival) ^ (8 * isPhysicallyControlled)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7E0
// Name: public: virtual bool CShadowController::IsPhysicallyControlled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowController::IsPhysicallyControlled(CShadowController *this)
{
  return (BYTE2(this->m_secondsToArrival) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7F0
// Name: public: virtual void CShadowController::ObjectMaterialChanged(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::ObjectMaterialChanged(CShadowController *this, __int16 materialIndex)
{
  if ( this->IPhysicsShadowController::__vftable != nullptr )
    LOWORD(this->m_secondsToArrival) = materialIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1001E810
// Name: public: virtual void CShadowController::MaxSpeed(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::MaxSpeed(CShadowController *this, float maxSpeed, float maxAngularSpeed)
{
  this->m_shadow.maxDampAngular = maxSpeed;
  this->m_shadow.maxSpeed = maxSpeed;
  this->m_shadow.lastImpulse.hesse_val = maxAngularSpeed;
  this->m_shadow.maxAngular = maxAngularSpeed;
}

//------------------------------------------------------------------------------
// Address: 0x1001E840
// Name: public: virtual void CShadowController::GetMaxSpeed(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::GetMaxSpeed(
        CShadowController *this,
        float *pMaxSpeedOut,
        float *pMaxAngularSpeedOut)
{
  if ( pMaxSpeedOut != nullptr )
    *pMaxSpeedOut = this->m_shadow.maxDampAngular;
  if ( pMaxAngularSpeedOut != nullptr )
    *pMaxAngularSpeedOut = this->m_shadow.lastImpulse.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x1001E890
// Name: void ComputeController(class IVP_U_Float_Point __near &,class IVP_U_Float_Point const __near &,float,float,float,float,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeController(
        IVP_U_Float_Point *currentSpeed,
        IVP_U_Float_Point *delta,
        float maxSpeed,
        float maxDampSpeed,
        float scaleDelta,
        float damping,
        IVP_U_Float_Point *pOutImpulse)
{
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm7_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  double v15; // st7
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v21; // [esp+10h] [ebp-10h]
  IVP_U_Float_Point v22; // 0:^10.16

  v7 = currentSpeed->k[1];
  v8 = currentSpeed->k[0];
  v9 = currentSpeed->k[2];
  v10 = (float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9);
  if ( v10 >= 0.000001 )
  {
    if ( maxDampSpeed > 0.0 )
    {
      v11 = v8 * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_);
      v12 = v7 * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_);
      v13 = v9 * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_);
      v14 = fsqrt(v10) * COERCE_FLOAT(LODWORD(damping) & _mask__AbsFloat_);
      if ( v14 > maxDampSpeed )
      {
        v11 = v11 * (float)(maxDampSpeed / v14);
        v12 = v12 * (float)(maxDampSpeed / v14);
        v13 = v13 * (float)(maxDampSpeed / v14);
      }
      currentSpeed->k[2] = currentSpeed->k[2] + v13;
      currentSpeed->k[0] = v8 + v11;
      currentSpeed->k[1] = v7 + v12;
    }
  }
  else
  {
    currentSpeed->k[2] = 0.0;
    currentSpeed->k[1] = 0.0;
    currentSpeed->k[0] = 0.0;
  }
  if ( maxSpeed <= 0.0 )
  {
    if ( pOutImpulse != nullptr )
    {
      pOutImpulse->k[2] = 0.0;
      pOutImpulse->k[1] = 0.0;
      pOutImpulse->k[0] = 0.0;
    }
  }
  else
  {
    v22.k[0] = delta->k[0] * scaleDelta;
    v22.k[1] = delta->k[1] * scaleDelta;
    v22.k[2] = delta->k[2] * scaleDelta;
    v15 = IVP_U_Float_Point::fast_real_length(this: delta) * scaleDelta;
    v21 = v15;
    if ( v15 <= maxSpeed )
    {
      v16 = v22.k[1];
      v17 = v22.k[2];
    }
    else
    {
      v22.k[0] = v22.k[0] * (float)(maxSpeed / v21);
      v16 = v22.k[1] * (float)(maxSpeed / v21);
      v17 = (float)(maxSpeed / v21) * v22.k[2];
      v22.k[1] = v16;
      v22.k[2] = v17;
    }
    v18 = v16 + currentSpeed->k[1];
    v19 = v17 + currentSpeed->k[2];
    currentSpeed->k[0] = currentSpeed->k[0] + v22.k[0];
    currentSpeed->k[1] = v18;
    currentSpeed->k[2] = v19;
    if ( pOutImpulse != nullptr )
      *pOutImpulse = v22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EA70
// Name: void ComputeController(class IVP_U_Float_Point __near &,class IVP_U_Float_Point const __near &,class IVP_U_Float_Point const __near &,float,float,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeController(
        IVP_U_Float_Point *currentSpeed,
        const IVP_U_Float_Point *delta,
        const IVP_U_Float_Point *maxSpeed,
        float scaleDelta,
        float damping,
        IVP_U_Float_Point *pOutImpulse)
{
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm7_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v17; // [esp+10h] [ebp-10h]
  IVP_U_Float_Point v18; // 0:^0.16

  v6 = delta->k[0] * scaleDelta;
  v7 = delta->k[1] * scaleDelta;
  v8 = delta->k[2] * scaleDelta;
  if ( (float)((float)((float)(currentSpeed->k[0] * currentSpeed->k[0])
                     + (float)(currentSpeed->k[1] * currentSpeed->k[1]))
             + (float)(currentSpeed->k[2] * currentSpeed->k[2])) < 0.000001 )
  {
    *(_QWORD *)&currentSpeed->k[1] = 0;
    currentSpeed->k[0] = 0.0;
  }
  v9 = currentSpeed->k[1];
  v10 = (float)(currentSpeed->k[0] * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_)) + v6;
  v17 = currentSpeed->k[2];
  v11 = maxSpeed->k[2];
  v12 = (float)(v17 * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_)) + v8;
  v13 = (float)(v9 * COERCE_FLOAT(LODWORD(damping) ^ _mask__NegFloat_)) + v7;
  v18.k[0] = v10;
  v18.k[1] = v13;
  v18.k[2] = v12;
  if ( v11 <= fabs(v12) )
  {
    if ( v12 < 0.0 )
      LODWORD(v11) ^= _mask__NegFloat_;
    v12 = v11;
    v18.k[2] = v11;
  }
  v14 = maxSpeed->k[1];
  if ( v14 <= fabs(v13) )
  {
    if ( v13 < 0.0 )
      v14 = -v14;
    v13 = v14;
    v18.k[1] = v14;
  }
  v15 = maxSpeed->k[0];
  if ( maxSpeed->k[0] <= fabs(v10) )
  {
    if ( v10 < 0.0 )
      v15 = -v15;
    v10 = v15;
    v18.k[0] = v15;
  }
  currentSpeed->k[0] = currentSpeed->k[0] + v10;
  currentSpeed->k[1] = v9 + v13;
  currentSpeed->k[2] = v17 + v12;
  if ( pOutImpulse != nullptr )
    *pOutImpulse = v18;
}

//------------------------------------------------------------------------------
// Address: 0x1001EC10
// Name: IsOnGround
// Source: json
//------------------------------------------------------------------------------
char __usercall IsOnGround@<al>(IVP_Real_Object *pivp@<eax>)
{
  IPhysicsFrictionSnapshot *FrictionSnapshot; // esi
  char v2; // bl
  Vector normal; // [esp+8h] [ebp-10h] BYREF
  bool bGround; // [esp+17h] [ebp-1h]

  FrictionSnapshot = CreateFrictionSnapshot(pObject: pivp);
  v2 = 0;
  if ( FrictionSnapshot->IsValid(this: FrictionSnapshot) )
  {
    while ( 1 )
    {
      FrictionSnapshot->GetSurfaceNormal(this: FrictionSnapshot, a2: &normal);
      if ( normal.z < -0.69999999 )
        break;
      FrictionSnapshot->NextFrictionData(this: FrictionSnapshot);
      if ( !FrictionSnapshot->IsValid(this: FrictionSnapshot) )
      {
        DestroyPlayerController(pSnapshot: FrictionSnapshot);
        return 0;
      }
    }
    bGround = true;
    v2 = 1;
  }
  DestroyPlayerController(pSnapshot: FrictionSnapshot);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001EC90
// Name: public: virtual bool CPlayerController::WasFrozen(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPlayerController::WasFrozen(CPlayerController *this)
{
  return (**((_BYTE **)this->event_object_revived + 37) & 0xC0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001ECB0
// Name: public: virtual void CPlayerController::GetLastImpulse(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::GetLastImpulse(CPlayerController *this, Vector *pOut)
{
  float v2; // xmm0_4

  v2 = this->m_lastImpulse.k[1] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pOut->z) = COERCE_UNSIGNED_INT(this->m_lastImpulse.k[0] * g_PhysicsUnits.unitScaleMetersInv)
                   ^ _mask__NegFloat_;
  pOut->y = v2;
  pOut->x = this->m_currentSpeed.hesse_val * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x1001ED00
// Name: protected: void CPlayerController::AttachObject(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlayerController::AttachObject(CPlayerController *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  IVP_Core *physical_core; // edi
  __int64 v6; // [esp-8h] [ebp-14h]

  ((void (__thiscall *)(CPhysicsObject *, _DWORD, int, int))this->m_pObject->EnableDrag)(
    a1: this->m_pObject,
    a2: 0,
    a3: a2,
    a4: a3);
  physical_core = this->m_pObject->m_pObject->physical_core;
  this->m_saveRot = physical_core->rot_speed_damp_factor;
  LODWORD(v6) = 1120403456;
  *(_QWORD *)physical_core->rot_speed_damp_factor.k = 0x42C8000042C80000LL;
  *(_QWORD *)&physical_core->rot_speed_damp_factor.k[2] = v6;
  IVP_Core::calc_calc(this: physical_core);
  IVP_Controller_Manager::add_controller_to_core(cntrl: this, core: physical_core);
  this->m_pObject->m_callbacks |= 0x2000u;
}

//------------------------------------------------------------------------------
// Address: 0x1001EDA0
// Name: protected: void CPlayerController::DetachObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::DetachObject(CPlayerController *this)
{
  CPhysicsObject *m_pObject; // eax
  IVP_Core *physical_core; // edi
  CPhysicsObject *m_pGround; // eax
  IVP_Real_Object *v5; // eax

  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    physical_core = m_pObject->m_pObject->physical_core;
    physical_core->rot_speed_damp_factor = this->m_saveRot;
    IVP_Core::calc_calc(this: physical_core);
    this->m_pObject->m_callbacks &= ~0x2000u;
    this->m_pObject = nullptr;
    IVP_Controller_Manager::remove_controller_from_core(cntrl: this, core: physical_core);
    m_pGround = this->m_pGround;
    if ( m_pGround != nullptr )
    {
      v5 = m_pGround->m_pObject;
      if ( v5 != nullptr )
        IVP_Real_Object::remove_listener_object(this: v5, listener: &this->IVP_Listener_Object);
      this->m_pGround = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EE10
// Name: public: virtual void CPredictedPlayerController::SetObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPlayerController::SetObject(
        CPredictedPlayerController *this@<ecx>,
        int a2@<edi>,
        IPhysicsObject *pObject)
{
  if ( pObject != (IPhysicsObject *)this->CPlayerController::IVP_Listener_Object::__vftable )
  {
    CPlayerController::DetachObject(this: (CPredictedPlayerController *)((char *)this - 4));
    this->CPlayerController::IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)pObject;
    CPlayerController::AttachObject(this: (CPredictedPlayerController *)((char *)this - 4), a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EE40
// Name: protected: int CPlayerController::TryTeleportObject(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CPlayerController::TryTeleportObject@<eax>(CPlayerController *this@<ecx>, float a2@<ebp>)
{
  IPhysicsPlayerControllerEvent *m_handler; // ecx
  CPhysicsObject *v4; // edx
  int result; // eax
  IVP_Real_Object *m_pObject; // edi
  int v7; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Point outPosition; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Quat targetOrientation; // [esp+10h] [ebp-20h] BYREF
  int v10; // [esp+20h] [ebp-10h]
  Vector hlPosition; // [esp+24h] [ebp-Ch]
  float retaddr; // [esp+30h] [ebp+0h]

  hlPosition.x = a2;
  hlPosition.y = retaddr;
  m_handler = this->m_handler;
  if ( m_handler == nullptr
    || (*((_BYTE *)this + 144) & 4) != 0
    || (v10 = COERCE_UNSIGNED_INT(this->m_targetPosition.k[1] * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_,
        targetOrientation.w = this->m_targetPosition.k[2] * g_PhysicsUnits.unitScaleMetersInv,
        v4 = this->m_pObject,
        targetOrientation.z = this->m_targetPosition.k[0] * g_PhysicsUnits.unitScaleMetersInv,
        (result = m_handler->ShouldMoveTo(this: m_handler, a2: v4, a3: (const Vector *)&targetOrientation.z)) != 0) )
  {
    m_pObject = this->m_pObject->m_pObject;
    IVP_Real_Object::get_quat_world_f_object_AT(
      this: m_pObject,
      quat_world_f_object: (IVP_U_Quat *)&outPosition.k[1],
      position: (IVP_U_Point *)&v7);
    if ( (*(_DWORD *)&m_pObject->flags & 0x100) != 0 )
    {
      this->m_pObject->EnableCollisions(this: this->m_pObject, a2: false);
      IVP_Real_Object::beam_object_to_new_position(
        this: m_pObject,
        rotation_world_f_object: (const IVP_U_Quat *)&outPosition.k[1],
        position_w_f_o: &this->m_targetPosition,
        optimize_for_repeated_calls: IVP_TRUE);
      this->m_pObject->EnableCollisions(this: this->m_pObject, a2: true);
    }
    else
    {
      IVP_Real_Object::beam_object_to_new_position(
        this: m_pObject,
        rotation_world_f_object: (const IVP_U_Quat *)&outPosition.k[1],
        position_w_f_o: &this->m_targetPosition,
        optimize_for_repeated_calls: IVP_TRUE);
    }
    *((_BYTE *)this + 144) &= ~4u;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EF30
// Name: public: virtual void CPlayerController::StepUp(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPlayerController::StepUp(CPlayerController *this@<ecx>, float a2@<ebp>, float height)
{
  void (__thiscall *event_object_revived)(IVP_Listener_Object *, IVP_Event_Object *); // esi
  _BYTE v4[12]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Quat world_f_object; // [esp+0h] [ebp-30h]
  IVP_U_Point deltaIVP; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Point positionIVP; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  positionIVP.k[1] = a2;
  positionIVP.k[2] = retaddr;
  if ( height != 0.0 )
  {
    event_object_revived = this->event_object_revived;
    world_f_object.y = g_PhysicsUnits.unitScaleMeters * 0.0;
    LODWORD(world_f_object.z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * height) ^ _mask__NegFloat_;
    world_f_object.w = g_PhysicsUnits.unitScaleMeters * 0.0;
    IVP_Real_Object::get_quat_world_f_object_AT(
      this: (IVP_Real_Object *)event_object_revived,
      quat_world_f_object: (IVP_U_Quat *)v4,
      position: (IVP_U_Point *)&deltaIVP.k[1]);
    deltaIVP.k[1] = deltaIVP.k[1] + world_f_object.y;
    deltaIVP.k[2] = world_f_object.z + deltaIVP.k[2];
    deltaIVP.hesse_val = deltaIVP.hesse_val + world_f_object.w;
    IVP_Real_Object::beam_object_to_new_position(
      this: (IVP_Real_Object *)event_object_revived,
      rotation_world_f_object: (const IVP_U_Quat *)v4,
      position_w_f_o: (IVP_U_Point *)&deltaIVP.k[1],
      optimize_for_repeated_calls: IVP_TRUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EFF0
// Name: public: virtual void CPlayerController::Update(class Vector const __near &,class Vector const __near &,float,bool,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerController::Update(
        CPlayerController *this,
        const Vector *position,
        const Vector *velocity,
        float secondsToArrival,
        bool onground,
        IPhysicsObject *ground)
{
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  char v13; // al
  IPhysicsObject *v14; // edi
  float hesse_val; // eax
  IVP_Real_Object *v16; // eax
  IVP_Real_Object *v17; // edi
  float v18; // eax
  float v19; // [esp-Ch] [ebp-2Ch]
  const IVP_U_Float_Point *v20; // [esp+10h] [ebp-10h]

  LODWORD(v7) = COERCE_UNSIGNED_INT(position->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v8 = velocity->y * g_PhysicsUnits.unitScaleMeters;
  LODWORD(v9) = COERCE_UNSIGNED_INT(velocity->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v10 = position->x * g_PhysicsUnits.unitScaleMeters;
  v11 = position->y * g_PhysicsUnits.unitScaleMeters;
  v19 = velocity->x * g_PhysicsUnits.unitScaleMeters;
  LOBYTE(this->m_lastImpulse.hesse_val) = LOBYTE(this->m_lastImpulse.hesse_val) & 7 | 8;
  if ( (float)((float)((float)((float)(v9 - this->m_currentSpeed.k[0]) * (float)(v9 - this->m_currentSpeed.k[0]))
                     + (float)((float)(v19 - this->m_maxSpeed.hesse_val) * (float)(v19 - this->m_maxSpeed.hesse_val)))
             + (float)((float)(v8 - this->m_currentSpeed.k[1]) * (float)(v8 - this->m_currentSpeed.k[1]))) >= 0.000001
    || (float)((float)((float)((float)(v7 - this->m_targetPosition.k[0]) * (float)(v7 - this->m_targetPosition.k[0]))
                     + (float)((float)(v10 - *(&this->m_pushableSpeedLimit + 1))
                             * (float)(v10 - *(&this->m_pushableSpeedLimit + 1))))
             + (float)((float)(v11 - this->m_targetPosition.k[1]) * (float)(v11 - this->m_targetPosition.k[1]))) >= 0.000001 )
  {
    v12 = 0.0;
    this->m_targetPosition.k[0] = v7;
    v20 = (const IVP_U_Float_Point *)(&this->m_pushableSpeedLimit + 1);
    *(&this->m_pushableSpeedLimit + 1) = v10;
    this->m_targetPosition.k[1] = v11;
    if ( secondsToArrival >= 0.0 )
      v12 = secondsToArrival;
    this->m_dampFactor = v12;
    this->m_maxSpeed.hesse_val = v19;
    this->m_currentSpeed.k[0] = v9;
    this->m_currentSpeed.k[1] = v8;
    IVP_Controller_Manager::ensure_core_in_simulation(
      this: *(IVP_Controller_Manager **)(*((_DWORD *)this->event_object_revived + 6) + 52),
      core: *((IVP_Core **)this->event_object_revived + 37));
    v13 = LOBYTE(this->m_lastImpulse.hesse_val) & 0xFC | 1;
    LOBYTE(this->m_lastImpulse.hesse_val) = v13;
    if ( (float)((float)((float)(velocity->y * velocity->y) + (float)(velocity->x * velocity->x))
               + (float)(velocity->z * velocity->z)) > 0.1 )
    {
      ((void (__thiscall *)(CPlayerController *, const Vector *))this->do_simulation_controller)(a1: this, a2: velocity);
      v14 = ground;
    }
    else
    {
      LOBYTE(this->m_lastImpulse.hesse_val) = v13 & 0xFE;
      v14 = nullptr;
    }
    hesse_val = this->m_saveRot.hesse_val;
    if ( (IPhysicsObject *)LODWORD(hesse_val) != v14 )
    {
      if ( hesse_val != 0.0 )
      {
        v16 = *(IVP_Real_Object **)(LODWORD(hesse_val) + 8);
        if ( v16 != nullptr )
          IVP_Real_Object::remove_listener_object(
            this: v16,
            listener: (IVP_Listener_Object *)&this->IPhysicsPlayerController);
      }
      LODWORD(this->m_saveRot.hesse_val) = v14;
      if ( v14 != nullptr )
      {
        v17 = (IVP_Real_Object *)v14[2].__vftable;
        if ( v17 != nullptr )
          IVP_Real_Object::add_listener_object(
            this: v17,
            listener: (IVP_Listener_Object *)&this->IPhysicsPlayerController);
      }
    }
    v18 = this->m_saveRot.hesse_val;
    if ( v18 != 0.0 )
      IVP_U_Matrix::vimult4(
        this: (IVP_U_Matrix *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v18) + 8) + 148) + 96),
        p_in: v20,
        p_out: (IVP_U_Float_Point *)&this->m_targetPosition.hesse_val);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F210
// Name: public: virtual void CPlayerController::MaxSpeed(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPlayerController::MaxSpeed(CPlayerController *this@<ecx>, int a2@<ebp>, const Vector *velocity)
{
  float *v4; // esi
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  _BYTE v10[28]; // [esp-Ch] [ebp-3Ch] OVERLAPPED BYREF
  float v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  void *v13; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  v4 = *((float **)this->event_object_revived + 37);
  *(float *)&v10[16] = velocity->x * g_PhysicsUnits.unitScaleMeters;
  *(_DWORD *)&v10[20] = COERCE_UNSIGNED_INT(velocity->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  *(float *)&v10[24] = velocity->y * g_PhysicsUnits.unitScaleMeters;
  *(__m128i *)v10 = _mm_load_si128((const __m128i *)&v10[16]);
  v11 = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&v10[16]);
  v5 = (float)((float)(v4[52] * *(float *)&v10[16]) + (float)(v4[53] * *(float *)&v10[20]))
     + (float)(v4[54] * *(float *)&v10[24]);
  if ( v5 <= 0.0 )
  {
    v9 = *(float *)&v10[8];
    v8 = *(float *)&v10[4];
    v7 = *(float *)v10;
  }
  else
  {
    v6 = v5 * v11;
    *(float *)&v10[16] = v6 * *(float *)&v10[16];
    v7 = *(float *)v10 - *(float *)&v10[16];
    *(float *)&v10[20] = v6 * *(float *)&v10[20];
    *(float *)&v10[24] = *(float *)&v10[24] * v6;
    v8 = *(float *)&v10[4] - *(float *)&v10[20];
    v9 = *(float *)&v10[8] - *(float *)&v10[24];
  }
  v4[52] = v4[52];
  v4[53] = v4[53];
  v4[54] = v4[54];
  this->m_groundPosition.hesse_val = fabs(v7);
  this->m_maxSpeed.k[0] = fabs(v8);
  this->m_maxSpeed.k[1] = fabs(v9);
}

//------------------------------------------------------------------------------
// Address: 0x1001F380
// Name: public: virtual void CPlayerController::GetShadowVelocity(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPlayerController::GetShadowVelocity(CPlayerController *this@<ecx>, float a2@<ebp>, Vector *velocity)
{
  float *v3; // eax
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm4_4
  float hesse_val; // eax
  float v8; // xmm1_4
  float v9[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point baseVelocity; // [esp+0h] [ebp-20h]
  IVP_U_Float_Point speed; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  speed.k[1] = a2;
  speed.k[2] = retaddr;
  v3 = *((float **)this->event_object_revived + 37);
  if ( velocity != nullptr )
  {
    v4 = v3[52] + v3[44];
    v5 = v3[53] + v3[45];
    v6 = v3[54] + v3[46];
    hesse_val = this->m_saveRot.hesse_val;
    baseVelocity.k[1] = v4;
    baseVelocity.k[2] = v5;
    baseVelocity.hesse_val = v6;
    if ( hesse_val != 0.0 )
    {
      IVP_Core::get_surface_speed(
        this: *(IVP_Core **)(*(_DWORD *)(LODWORD(hesse_val) + 8) + 148),
        point_core: (const IVP_U_Float_Point *)&this->m_targetPosition.hesse_val,
        speed_world_out: (IVP_U_Float_Point *)v9);
      v4 = baseVelocity.k[1] - v9[0];
      v5 = baseVelocity.k[2] - v9[1];
      v6 = baseVelocity.hesse_val - v9[2];
    }
    v8 = g_PhysicsUnits.unitScaleMetersInv * v6;
    LODWORD(velocity->z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * v5) ^ _mask__NegFloat_;
    velocity->y = v8;
    velocity->x = g_PhysicsUnits.unitScaleMetersInv * v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F470
// Name: public: virtual unsigned int CPlayerController::GetContactState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPlayerController::GetContactState(CPlayerController *this, unsigned __int16 nGameFlags)
{
  void (__thiscall *event_object_revived)(IVP_Listener_Object *, IVP_Event_Object *); // eax
  int v3; // ebx
  IVP_Synapse_Friction *i; // edi
  IVP_Real_Object *OppositeSynapseObject; // eax
  CPhysicsObject *client_data; // esi

  event_object_revived = this->event_object_revived;
  v3 = 0;
  if ( (*((_DWORD *)event_object_revived + 17) & 0x100) == 0 )
    return 0;
  for ( i = *((IVP_Synapse_Friction **)event_object_revived + 10); i != nullptr; i = i->next )
  {
    OppositeSynapseObject = GetOppositeSynapseObject(pfriction: i);
    if ( (*(_DWORD *)&OppositeSynapseObject->flags & 0x100) != 0
      && (*(_WORD *)&OppositeSynapseObject->physical_core->IVP_Core_Fast_Static & 0x12) == 0 )
    {
      client_data = (CPhysicsObject *)OppositeSynapseObject->client_data;
      if ( !CPhysicsObject::IsControlledByGame(this: client_data) )
        v3 |= 1u;
      if ( (client_data->GetGameFlags(this: client_data) & nGameFlags) != 0 )
        v3 |= 2u;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001F4F0
// Name: public: virtual void CPredictedPlayerController::MaxSpeed(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPredictedPlayerController::MaxSpeed(CPredictedPlayerController *this, const Vector *maxVelocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( *((_DWORD *)&this->CPlayerController + 39) != 0 )
    *(Vector *)&this->m_ActiveBackup.vGroundPosition.z = *maxVelocity;
  else
    CPlayerController::MaxSpeed(this, a2: (int)&savedregs, velocity: maxVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x1001F530
// Name: public: virtual void CPredictedPlayerController::StepUp(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPlayerController::StepUp(
        CPredictedPlayerController *this@<ecx>,
        float a2@<ebp>,
        float height)
{
  IVP_Listener_Object_vtbl *v4; // ecx
  void (__thiscall *event_object_revived)(IVP_Listener_Object *, IVP_Event_Object *); // esi
  IVP_U_Quat v6; // [esp-30h] [ebp-3Ch] BYREF
  float v7; // [esp-20h] [ebp-2Ch]
  float v8; // [esp-1Ch] [ebp-28h]
  float v9; // [esp-18h] [ebp-24h]
  IVP_U_Point v10; // [esp-10h] [ebp-1Ch] BYREF
  Vector vCurrentPosition; // [esp+0h] [ebp-Ch]
  float retaddr; // [esp+Ch] [ebp+0h]

  vCurrentPosition.x = a2;
  vCurrentPosition.y = retaddr;
  if ( *((_DWORD *)&this->CPlayerController + 39) != 0 )
  {
    (*((void (__thiscall **)(IVP_Listener_Object_vtbl *, float *, _DWORD))this->event_object_deleted + 48))(
      a1: this->CPlayerController::IVP_Listener_Object::__vftable,
      a2: &v10.k[1],
      a3: 0);
    v4 = this->CPlayerController::IVP_Listener_Object::__vftable;
    LODWORD(v10.k[1]) = 1;
    v10.hesse_val = v10.hesse_val + height;
    (*((void (__thiscall **)(IVP_Listener_Object_vtbl *, float *, QAngle *))v4->event_object_deleted + 46))(
      a1: v4,
      a2: &v10.k[1],
      a3: &vec3_angle);
  }
  else if ( height != 0.0 )
  {
    event_object_revived = this->event_object_revived;
    v7 = g_PhysicsUnits.unitScaleMeters * 0.0;
    LODWORD(v8) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * height) ^ _mask__NegFloat_;
    v9 = g_PhysicsUnits.unitScaleMeters * 0.0;
    IVP_Real_Object::get_quat_world_f_object_AT(
      this: (IVP_Real_Object *)event_object_revived,
      quat_world_f_object: &v6,
      position: &v10);
    v10.k[0] = v10.k[0] + v7;
    v10.k[1] = v10.k[1] + v8;
    v10.k[2] = v10.k[2] + v9;
    IVP_Real_Object::beam_object_to_new_position(
      this: (IVP_Real_Object *)event_object_revived,
      rotation_world_f_object: &v6,
      position_w_f_o: &v10,
      optimize_for_repeated_calls: IVP_TRUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F630
// Name: public: virtual void CPredictedPlayerController::GetShadowVelocity(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPredictedPlayerController::GetShadowVelocity(CPredictedPlayerController *this, Vector *velocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( *((_DWORD *)&this->CPlayerController + 39) != 0 )
    (*((void (__thiscall **)(IVP_Listener_Object_vtbl *, Vector *, _DWORD))this->event_object_deleted + 52))(
      a1: this->CPlayerController::IVP_Listener_Object::__vftable,
      a2: velocity,
      a3: 0);
  else
    CPlayerController::GetShadowVelocity(this, a2: COERCE_FLOAT(&savedregs), velocity);
}

//------------------------------------------------------------------------------
// Address: 0x1001F660
// Name: public: virtual void CPredictedPlayerController::GetLastImpulse(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::GetLastImpulse(CPredictedPlayerController *this, Vector *pOut)
{
  float v2; // xmm0_4

  if ( *((_DWORD *)&this->CPlayerController + 39) != 0 )
    *pOut = *(Vector *)&this->m_ActiveBackup.vMaxSpeed.z;
  v2 = this->m_lastImpulse.k[1] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pOut->z) = COERCE_UNSIGNED_INT(this->m_lastImpulse.k[0] * g_PhysicsUnits.unitScaleMetersInv)
                   ^ _mask__NegFloat_;
  pOut->y = v2;
  pOut->x = this->m_currentSpeed.hesse_val * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x1001F6D0
// Name: protected: int CPredictedPlayerController::TryTeleportObject(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPredictedPlayerController::TryTeleportObject(CPredictedPlayerController *this)
{
  IPhysicsPlayerControllerEvent *m_handler; // ecx
  CPhysicsObject *m_pObject; // edx
  int result; // eax
  Vector hlPosition; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( this->m_pReferencedBackup == nullptr )
    return CPlayerController::TryTeleportObject(this, a2: COERCE_FLOAT(&savedregs));
  m_handler = this->m_handler;
  if ( m_handler == nullptr
    || this->m_ActiveBackup.bForceTeleport
    || (LODWORD(hlPosition.z) = COERCE_UNSIGNED_INT(this->m_targetPosition.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                              ^ _mask__NegFloat_,
        hlPosition.y = this->m_targetPosition.k[2] * g_PhysicsUnits.unitScaleMetersInv,
        m_pObject = this->m_pObject,
        hlPosition.x = this->m_targetPosition.k[0] * g_PhysicsUnits.unitScaleMetersInv,
        (result = m_handler->ShouldMoveTo(this: m_handler, a2: m_pObject, a3: &hlPosition)) != 0) )
  {
    this->m_pObject->SetPosition(
      this: this->m_pObject,
      a2: (const Vector *)&this->m_ActiveBackup,
      a3: &vec3_angle,
      a4: true);
    this->m_ActiveBackup.bForceTeleport = false;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F780
// Name: protected: void CPredictedPlayerController::SetGround(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::SetGround(CPredictedPlayerController *this, CPhysicsObject *pGroundObject)
{
  CPhysicsObject *m_pGround; // eax
  IVP_Real_Object *m_pObject; // eax
  IVP_Real_Object *v5; // ecx

  if ( this->m_pReferencedBackup != nullptr )
    this->m_ActiveBackup.pGround = pGroundObject;
  m_pGround = this->m_pGround;
  if ( m_pGround != pGroundObject )
  {
    if ( m_pGround != nullptr )
    {
      m_pObject = m_pGround->m_pObject;
      if ( m_pObject != nullptr )
        IVP_Real_Object::remove_listener_object(this: m_pObject, listener: &this->IVP_Listener_Object);
    }
    this->m_pGround = pGroundObject;
    if ( pGroundObject != nullptr )
    {
      v5 = pGroundObject->m_pObject;
      if ( v5 != nullptr )
        IVP_Real_Object::add_listener_object(this: v5, listener: &this->IVP_Listener_Object);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F7E0
// Name: void QuaternionDiff(class IVP_U_Quat const __near &,class IVP_U_Quat const __near &,class IVP_U_Quat __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall QuaternionDiff(int a1@<ebp>, const IVP_U_Quat *p, const IVP_U_Quat *q, IVP_U_Quat *qt)
{
  float w; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Quat q2; // [esp+0h] [ebp-20h]
  float v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  void *v16; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v15 = a1;
  v16 = retaddr;
  IVP_U_Quat::set_invert_unit_quat(this: (IVP_U_Quat *)v12, q1: q);
  w = p->w;
  y = p->y;
  x = p->x;
  z = p->z;
  v9 = (float)((float)((float)(y * q2.x) + (float)(p->w * v12[1])) + (float)(p->x * v12[2])) - (float)(p->z * v12[0]);
  v10 = (float)((float)((float)(z * q2.x) + (float)(p->w * v12[2])) + (float)(p->y * v12[0])) - (float)(p->x * v12[1]);
  v14 = (float)((float)(w * q2.x) - (float)(p->x * v12[0])) - (float)(y * v12[1]);
  v11 = v14 - (float)(z * v12[2]);
  qt->x = (float)((float)((float)(w * v12[0]) + (float)(x * q2.x)) + (float)(z * v12[1])) - (float)(y * v12[2]);
  qt->y = v9;
  qt->z = v10;
  qt->w = v11;
  IVP_U_Quat::normize_quat(this: qt);
}

//------------------------------------------------------------------------------
// Address: 0x1001F900
// Name: float ComputeShadowControllerIVP(class IVP_Real_Object __near *,struct shadowcontrol_params_t __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
double __usercall ComputeShadowControllerIVP@<st0>(
        int a1@<ebp>,
        long double a2@<esi:edi>,
        IVP_Real_Object *pivp,
        shadowcontrol_params_t *params,
        float secondsToArrival,
        float dt)
{
  float v7; // xmm0_4
  IVP_Core *physical_core; // ecx
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm2_4
  IVP_U_Matrix3 *p_m_world_f_core_last_psi; // ecx
  bool v13; // zf
  float teleportDistance; // xmm7_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float damping; // xmm1_4
  IVP_Core *v20; // edi
  float v21; // xmm0_4
  float v22; // xmm1_4
  double x; // xmm0_8
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float maxDampAngular; // xmm7_4
  float dampFactor; // xmm0_4
  float v29; // xmm6_4
  float hesse_val; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  double v39; // st7
  double v40; // st7
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  IVP_U_Float_Point v48; // [esp+24h] [ebp-7Ch] BYREF
  _DWORD v49[3]; // [esp+34h] [ebp-6Ch] BYREF
  IVP_U_Quat deltaRotation; // [esp+40h] [ebp-60h] BYREF
  IVP_U_Float_Point delta_position; // [esp+50h] [ebp-50h] BYREF
  IVP_U_Float_Point deltaAngles; // [esp+60h] [ebp-40h]
  IVP_U_Point positionIVP; // [esp+70h] [ebp-30h] BYREF
  Vector axis; // [esp+80h] [ebp-20h]
  float v55; // [esp+8Ch] [ebp-14h]
  float maxAngular; // [esp+90h] [ebp-10h]
  _DWORD v57[2]; // [esp+94h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+A0h] [ebp+0h]
  float secondsToArrivala; // [esp+ACh] [ebp+Ch]

  v57[0] = a1;
  v57[1] = retaddr;
  v7 = 1.0;
  maxAngular = 1.0;
  if ( secondsToArrival > 0.0 )
  {
    v7 = dt / secondsToArrival;
    maxAngular = dt / secondsToArrival;
    if ( (float)(dt / secondsToArrival) > 1.0 )
    {
      v7 = 1.0;
      maxAngular = 1.0;
    }
  }
  secondsToArrivala = secondsToArrival - dt;
  if ( (float)(secondsToArrival - dt) < 0.0 )
    secondsToArrivala = 0.0;
  if ( v7 > 0.0 )
  {
    physical_core = pivp->physical_core;
    v9 = physical_core->m_world_f_core_last_psi.vv.k[0];
    v10 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v11 = physical_core->m_world_f_core_last_psi.vv.k[2];
    p_m_world_f_core_last_psi = &physical_core->m_world_f_core_last_psi;
    v13 = (*(_DWORD *)&pivp->flags & 0x800) == 0;
    deltaAngles.k[1] = v9;
    deltaAngles.k[2] = v10;
    deltaAngles.hesse_val = v11;
    if ( v13 )
    {
      IVP_U_Matrix3::vmult3(this: p_m_world_f_core_last_psi, p_in: &pivp->shift_core_f_object, p_out: &v48);
      v9 = v48.k[0] + deltaAngles.k[1];
      v10 = v48.k[1] + deltaAngles.k[2];
      v11 = v48.k[2] + deltaAngles.hesse_val;
      deltaAngles.k[1] = v48.k[0] + deltaAngles.k[1];
      deltaAngles.k[2] = v48.k[1] + deltaAngles.k[2];
      deltaAngles.hesse_val = v48.k[2] + deltaAngles.hesse_val;
    }
    teleportDistance = params->teleportDistance;
    v15 = params->targetPosition.k[0] - v9;
    v16 = params->targetPosition.k[1] - v10;
    v17 = params->targetPosition.k[2] - v11;
    deltaRotation.y = v15;
    deltaRotation.z = v16;
    deltaRotation.w = v17;
    if ( teleportDistance > 0.0 )
    {
      v18 = params->lastPosition.k[0] == 0.0 && params->lastPosition.k[1] == 0.0 && params->lastPosition.k[2] == 0.0
          ? (float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v17 * v17)
          : (float)((float)((float)(v10 - params->lastPosition.k[1]) * (float)(v10 - params->lastPosition.k[1]))
                  + (float)((float)(v9 - params->lastPosition.k[0]) * (float)(v9 - params->lastPosition.k[0])))
          + (float)((float)(v11 - params->lastPosition.k[2]) * (float)(v11 - params->lastPosition.k[2]));
      if ( v18 > (float)(params->teleportDistance * params->teleportDistance) )
      {
        if ( (*(_DWORD *)&pivp->flags & 0x100) != 0 )
        {
          IVP_Real_Object::enable_collision_detection(this: pivp, enable: IVP_FALSE);
          IVP_Real_Object::beam_object_to_new_position(
            this: pivp,
            rotation_world_f_object: &params->targetRotation,
            position_w_f_o: &params->targetPosition,
            optimize_for_repeated_calls: IVP_TRUE);
          IVP_Real_Object::enable_collision_detection(this: pivp, enable: IVP_TRUE);
        }
        else
        {
          IVP_Real_Object::beam_object_to_new_position(
            this: pivp,
            rotation_world_f_object: &params->targetRotation,
            position_w_f_o: &params->targetPosition,
            optimize_for_repeated_calls: IVP_TRUE);
        }
        memset(&deltaRotation.y, 0, 12);
      }
    }
    damping = params->dampFactor;
    v20 = pivp->physical_core;
    axis.z = (float)(1.0 / dt) * maxAngular;
    ComputeController(
      currentSpeed: &v20->speed,
      delta: (IVP_U_Float_Point *)&deltaRotation.y,
      maxSpeed: params->maxSpeed,
      maxDampSpeed: params->maxDampSpeed,
      scaleDelta: axis.z,
      damping,
      pOutImpulse: &params->lastImpulse);
    v21 = (float)(v20->speed.k[1] * dt) + deltaAngles.k[2];
    v22 = (float)(v20->speed.k[2] * dt) + deltaAngles.hesse_val;
    params->lastPosition.k[0] = (float)(v20->speed.k[0] * dt) + deltaAngles.k[1];
    params->lastPosition.k[1] = v21;
    params->lastPosition.k[2] = v22;
    QuaternionDiff(a1: (int)v57, p: &params->targetRotation, q: &v20->q_world_f_core_next_psi, qt: (IVP_U_Quat *)v49);
    x = deltaRotation.x;
    __libm_sse2_acos(x: a2);
    *(float *)&x = x;
    v24 = *(float *)&x * 2.0;
    maxAngular = v24;
    if ( v24 > 3.141592653589793 )
    {
      v25 = v24 - 6.283185307179586;
      maxAngular = v25;
    }
    LODWORD(positionIVP.k[1]) = v49[0];
    LODWORD(positionIVP.k[2]) = v49[1];
    LODWORD(positionIVP.hesse_val) = v49[2];
    VectorNormalize(vec: (Vector *)&positionIVP.k[1]);
    v26 = maxAngular;
    maxDampAngular = params->maxDampAngular;
    delta_position.k[1] = positionIVP.k[1] * maxAngular;
    maxAngular = params->maxAngular;
    dampFactor = params->dampFactor;
    v29 = positionIVP.k[2] * v26;
    delta_position.k[2] = positionIVP.k[2] * v26;
    hesse_val = positionIVP.hesse_val * v26;
    delta_position.hesse_val = positionIVP.hesse_val * v26;
    v31 = v20->rot_speed.k[1];
    v32 = v20->rot_speed.k[0];
    v33 = v20->rot_speed.k[2];
    v55 = dampFactor;
    v34 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33);
    axis.x = maxDampAngular;
    if ( v34 >= 0.000001 )
    {
      if ( maxDampAngular <= 0.0 )
        goto LABEL_29;
      v35 = v32 * COERCE_FLOAT(LODWORD(v55) ^ _mask__NegFloat_);
      v36 = v31 * COERCE_FLOAT(LODWORD(v55) ^ _mask__NegFloat_);
      v37 = v33 * COERCE_FLOAT(LODWORD(v55) ^ _mask__NegFloat_);
      axis.y = fsqrt(v34);
      v38 = axis.y * COERCE_FLOAT(LODWORD(v55) & _mask__AbsFloat_);
      if ( v38 > axis.x )
      {
        v35 = v35 * (float)(axis.x / v38);
        v36 = v36 * (float)(axis.x / v38);
        v37 = v37 * (float)(axis.x / v38);
      }
      v20->rot_speed.k[0] = v32 + v35;
      v20->rot_speed.k[1] = v31 + v36;
      v20->rot_speed.k[2] = v33 + v37;
    }
    else
    {
      v20->rot_speed.k[2] = 0.0;
      v20->rot_speed.k[1] = 0.0;
      v20->rot_speed.k[0] = 0.0;
    }
    v29 = delta_position.k[2];
    hesse_val = delta_position.hesse_val;
LABEL_29:
    if ( maxAngular > 0.0 )
    {
      deltaAngles.k[1] = axis.z * delta_position.k[1];
      deltaAngles.k[2] = axis.z * v29;
      deltaAngles.hesse_val = axis.z * hesse_val;
      v39 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&delta_position.k[1]);
      v40 = v39 * axis.z;
      v41 = deltaAngles.k[1];
      v42 = deltaAngles.k[2];
      axis.x = v40;
      if ( v40 <= maxAngular )
      {
        v43 = deltaAngles.hesse_val;
      }
      else
      {
        v41 = deltaAngles.k[1] * (float)(maxAngular / axis.x);
        v42 = deltaAngles.k[2] * (float)(maxAngular / axis.x);
        v43 = (float)(maxAngular / axis.x) * deltaAngles.hesse_val;
      }
      v44 = v20->rot_speed.k[0] + v41;
      v20->rot_speed.k[1] = v20->rot_speed.k[1] + v42;
      v45 = v20->rot_speed.k[2] + v43;
      v20->rot_speed.k[0] = v44;
      v20->rot_speed.k[2] = v45;
    }
  }
  return secondsToArrivala;
}

//------------------------------------------------------------------------------
// Address: 0x1001FE10
// Name: float ComputeShadowControllerHL(class CPhysicsObject __near *,struct hlshadowcontrol_params_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
double __usercall ComputeShadowControllerHL@<st0>(
        float a1@<ebp>,
        long double a2@<esi:edi>,
        CPhysicsObject *pObject,
        const hlshadowcontrol_params_t *params,
        float secondsToArrival,
        float dt)
{
  float x; // xmm1_4
  IVP_Real_Object *m_pObject; // eax
  float dampFactor; // xmm0_4
  float v9; // xmm1_4
  float v11[3]; // [esp+18h] [ebp-6Ch] BYREF
  shadowcontrol_params_t ivpParams; // [esp+24h] [ebp-60h] BYREF
  _UNKNOWN *retaddr; // [esp+84h] [ebp+0h]

  ivpParams.teleportDistance = a1;
  *((_DWORD *)&ivpParams.teleportDistance + 1) = retaddr;
  HIDWORD(a2) = params;
  x = params->targetPosition.x;
  memset(&ivpParams.targetRotation.y, 0, 12);
  memset(&ivpParams.lastPosition.k[1], 0, 12);
  v11[0] = x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(v11[1]) = COERCE_UNSIGNED_INT(params->targetPosition.z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v11[2] = params->targetPosition.y * g_PhysicsUnits.unitScaleMeters;
  ConvertRotationToIVP(
    a1: (int)&ivpParams.teleportDistance,
    angles: &params->targetRotation,
    out: (IVP_U_Quat *)&ivpParams.targetPosition.k[1]);
  m_pObject = pObject->m_pObject;
  ivpParams.maxSpeed = params->teleportDistance * g_PhysicsUnits.unitScaleMeters;
  ivpParams.lastImpulse.hesse_val = params->maxSpeed * g_PhysicsUnits.unitScaleMeters;
  dampFactor = params->dampFactor;
  ivpParams.maxAngular = params->maxDampSpeed * g_PhysicsUnits.unitScaleMeters;
  v9 = params->maxAngular * 0.017453292;
  ivpParams.maxDampAngular = dampFactor;
  ivpParams.lastImpulse.k[1] = v9;
  ivpParams.lastImpulse.k[2] = params->maxDampAngular * 0.017453292;
  return ComputeShadowControllerIVP(
           a1: (int)&ivpParams.teleportDistance,
           a2,
           pivp: m_pObject,
           params: (shadowcontrol_params_t *)v11,
           secondsToArrival,
           dt);
}

//------------------------------------------------------------------------------
// Address: 0x1001FF40
// Name: private: void CShadowController::AttachObject(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CShadowController::AttachObject(
        CShadowController *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CPhysicsObject *m_pObject; // ecx
  IVP_Core *physical_core; // edi
  CPhysicsObject *v7; // ecx
  unsigned int m_callbacks; // eax
  __int64 v11; // [esp+20h] [ebp-3Ch] BYREF
  _BYTE v12[17]; // [esp+28h] [ebp-34h] OVERLAPPED BYREF
  const QAngle *v13; // [esp+40h] [ebp-1Ch]
  QAngle angles; // [esp+44h] [ebp-18h] BYREF
  Vector position; // [esp+50h] [ebp-Ch] BYREF
  float retaddr; // [esp+5Ch] [ebp+0h]

  position.x = a2;
  position.y = retaddr;
  m_pObject = this->m_pObject;
  physical_core = m_pObject->m_pObject->physical_core;
  this->m_saveRot = physical_core->rot_speed_damp_factor;
  this->m_savedRI = (IVP_U_Float_Point)physical_core->rot_inertia;
  this->m_savedMass = physical_core->rot_inertia.hesse_val;
  this->m_savedMaterialIndex = m_pObject->m_materialIndex;
  ((void (__thiscall *)(CPhysicsObject *, QAngle *, _BYTE *, int, int))m_pObject->GetPosition)(
    a1: m_pObject,
    a2: &angles,
    a3: &v12[16],
    a4: a3,
    a5: a4);
  this->m_shadow.targetPosition.k[0] = g_PhysicsUnits.unitScaleMeters * angles.x;
  LODWORD(this->m_shadow.targetPosition.k[1]) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * angles.z)
                                              ^ _mask__NegFloat_;
  LODWORD(angles.x) = &this->m_shadow.targetRotation;
  v13 = (const QAngle *)&v12[16];
  this->m_shadow.targetPosition.k[2] = g_PhysicsUnits.unitScaleMeters * angles.y;
  ConvertRotationToIVP(a1: (int)&position, angles: v13, out: (IVP_U_Quat *)LODWORD(angles.x));
  this->UseShadowMaterial(this: &this->IPhysicsShadowController, a2: true);
  v11 = 0x42C8000042C80000LL;
  *(_DWORD *)v12 = 1120403456;
  *(_QWORD *)physical_core->rot_speed_damp_factor.k = 0x42C8000042C80000LL;
  *(_QWORD *)&physical_core->rot_speed_damp_factor.k[2] = *(_QWORD *)v12;
  if ( (*((_BYTE *)this + 18) & 4) == 0 )
  {
    v11 = 0x58635FA958635FA9LL;
    *(_DWORD *)v12 = 1482907561;
    IVP_Core::set_rotation_inertia(this: physical_core, r: (const IVP_U_Float_Point *)&v11);
  }
  if ( (*((_BYTE *)this + 18) & 2) == 0 )
  {
    ((void (__stdcall *)(int))this->m_pObject->SetMass)(a1: 1195593728);
    this->m_pObject->EnableGravity(this: this->m_pObject, a2: false);
  }
  v7 = this->m_pObject;
  m_callbacks = v7->m_callbacks;
  this->m_savedFlags = m_callbacks;
  v7->SetCallbackFlags(this: v7, a2: m_callbacks & 0xFFCD | 0x10);
  this->m_pObject->EnableDrag(this: this->m_pObject, a2: false);
  IVP_Core::calc_calc(this: physical_core);
  IVP_Controller_Manager::add_controller_to_core(cntrl: this, core: physical_core);
  *(_QWORD *)&this->m_shadow.lastPosition.k[1] = 0;
  this->m_shadow.lastPosition.k[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100200F0
// Name: private: void CShadowController::DetachObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::DetachObject(CShadowController *this)
{
  CPhysicsObject *m_pObject; // ecx
  IVP_Core *physical_core; // edi

  m_pObject = this->m_pObject;
  physical_core = m_pObject->m_pObject->physical_core;
  if ( (((int (__thiscall *)(CPhysicsObject *))m_pObject->GetCallbackFlags)(a1: m_pObject) & 0x400) == 0 )
  {
    *(_QWORD *)physical_core->rot_speed_damp_factor.k = *(_QWORD *)this->m_saveRot.k;
    *(_QWORD *)&physical_core->rot_speed_damp_factor.k[2] = *(_QWORD *)&this->m_saveRot.k[2];
    IVP_Core::set_mass(this: physical_core, new_mass: this->m_savedMass);
    this->m_pObject->SetCallbackFlags(this: this->m_pObject, a2: this->m_savedFlags);
    this->m_pObject->EnableDrag(this: this->m_pObject, a2: true);
    this->m_pObject->EnableGravity(this: this->m_pObject, a2: true);
    this->UseShadowMaterial(this: &this->IPhysicsShadowController, a2: false);
    IVP_Core::set_rotation_inertia(this: physical_core, r: &this->m_savedRI);
  }
  this->m_pObject = nullptr;
  IVP_Controller_Manager::remove_controller_from_core(cntrl: this, core: physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x100201A0
// Name: public: virtual void CShadowController::GetLastImpulse(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::GetLastImpulse(CShadowController *this, Vector *pOut)
{
  float v2; // xmm0_4

  v2 = this->m_shadow.lastImpulse.k[1] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pOut->z) = COERCE_UNSIGNED_INT(this->m_shadow.lastImpulse.k[0] * g_PhysicsUnits.unitScaleMetersInv)
                   ^ _mask__NegFloat_;
  pOut->y = v2;
  pOut->x = this->m_shadow.lastPosition.hesse_val * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x100201F0
// Name: public: virtual void CShadowController::UseShadowMaterial(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::UseShadowMaterial(CShadowController *this, bool bUseShadowMaterial)
{
  IPhysicsShadowController_vtbl *v2; // eax
  int AllowsRotation_low; // edx
  int m_secondsToArrival_low; // eax

  v2 = this->IPhysicsShadowController::__vftable;
  if ( v2 != nullptr )
  {
    AllowsRotation_low = LOWORD(v2->AllowsRotation);
    m_secondsToArrival_low = 61440;
    if ( !bUseShadowMaterial )
      m_secondsToArrival_low = LOWORD(this->m_secondsToArrival);
    if ( m_secondsToArrival_low != AllowsRotation_low )
      (*((void (__thiscall **)(IPhysicsShadowController_vtbl *, int))this->dtr_IPhysicsShadowController + 39))(
        a1: this->IPhysicsShadowController::__vftable,
        a2: m_secondsToArrival_low);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020230
// Name: public: virtual void CShadowController::StepUp(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowController::StepUp(CShadowController *this@<ecx>, float a2@<ebp>, float height)
{
  void (__thiscall *MaxSpeed)(IPhysicsShadowController *, float, float); // esi
  _BYTE v4[12]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Quat world_f_object; // [esp+0h] [ebp-30h]
  IVP_U_Point deltaIVP; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Point positionIVP; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  positionIVP.k[1] = a2;
  positionIVP.k[2] = retaddr;
  MaxSpeed = this->MaxSpeed;
  world_f_object.y = g_PhysicsUnits.unitScaleMeters * 0.0;
  LODWORD(world_f_object.z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * height) ^ _mask__NegFloat_;
  world_f_object.w = g_PhysicsUnits.unitScaleMeters * 0.0;
  IVP_Real_Object::get_quat_world_f_object_AT(
    this: (IVP_Real_Object *)MaxSpeed,
    quat_world_f_object: (IVP_U_Quat *)v4,
    position: (IVP_U_Point *)&deltaIVP.k[1]);
  deltaIVP.k[1] = deltaIVP.k[1] + world_f_object.y;
  deltaIVP.k[2] = world_f_object.z + deltaIVP.k[2];
  deltaIVP.hesse_val = deltaIVP.hesse_val + world_f_object.w;
  IVP_Real_Object::beam_object_to_new_position(
    this: (IVP_Real_Object *)MaxSpeed,
    rotation_world_f_object: (const IVP_U_Quat *)v4,
    position_w_f_o: (IVP_U_Point *)&deltaIVP.k[1],
    optimize_for_repeated_calls: IVP_TRUE);
}

//------------------------------------------------------------------------------
// Address: 0x100202E0
// Name: public: virtual void CShadowController::SetTeleportDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::SetTeleportDistance(CShadowController *this, float teleportDistance)
{
  this->m_shadow.dampFactor = g_PhysicsUnits.unitScaleMeters * teleportDistance;
}

//------------------------------------------------------------------------------
// Address: 0x10020300
// Name: public: virtual float CShadowController::GetTeleportDistance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShadowController::GetTeleportDistance(CShadowController *this)
{
  return this->m_shadow.dampFactor * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10020310
// Name: public: virtual void CShadowController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::do_simulation_controller(
        CShadowController *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  long double v3; // rdi
  int v5; // edx
  float v6; // xmm0_4
  float v7; // xmm0_4
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  float gravDt; // [esp+1Ch] [ebp+8h]

  HIDWORD(v3) = this;
  if ( (*((_BYTE *)this + 18) & 1) != 0 )
  {
    LODWORD(v3) = this->m_pObject->m_pObject;
    ComputeShadowControllerIVP(
      a1: (int)&savedregs,
      a2: v3,
      pivp: (IVP_Real_Object *)LODWORD(v3),
      params: (shadowcontrol_params_t *)(HIDWORD(v3) + 32),
      secondsToArrival: this->m_secondsToArrival,
      dt: es->delta_time);
    if ( (*(_BYTE *)(HIDWORD(v3) + 18) & 2) != 0 )
    {
      v5 = *(_DWORD *)(LODWORD(v3) + 24);
      gravDt = *(float *)(v5 + 180) * es->delta_time;
      if ( *(float *)(HIDWORD(v3) + 84) > (float)(*(float *)(v5 + 180) * es->delta_time)
        && IsOnGround(pivp: (IVP_Real_Object *)LODWORD(v3)) != 0 )
      {
        v6 = gravDt - *(float *)(HIDWORD(v3) + 84);
        *(float *)(*(_DWORD *)(LODWORD(v3) + 148) + 212) = v6 + *(float *)(*(_DWORD *)(LODWORD(v3) + 148) + 212);
        *(float *)(HIDWORD(v3) + 84) = *(float *)(HIDWORD(v3) + 84) + v6;
      }
    }
    v7 = *(float *)(HIDWORD(v3) + 12) - es->delta_time;
    *(float *)(HIDWORD(v3) + 12) = v7;
    if ( v7 < 0.0 )
      *(_DWORD *)(HIDWORD(v3) + 12) = 0;
  }
  else
  {
    *(_QWORD *)&this->m_shadow.lastPosition.k[1] = 0;
    this->m_shadow.lastPosition.k[0] = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100203F0
// Name: public: void CShadowController::Update_Internal(class Vector const __near &,class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CShadowController::Update_Internal(
        CShadowController *this@<ecx>,
        int a2@<ebp>,
        const Vector *position,
        const QAngle *angles,
        float secondsToArrival)
{
  char v6; // al
  float v7; // xmm0_4
  CPhysicsObject *m_pObject; // ecx
  __int64 v9; // [esp-Ch] [ebp-2Ch] BYREF
  _BYTE v10[32]; // [esp-4h] [ebp-24h] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+20h] [ebp+0h]

  *(_DWORD *)&v10[24] = a2;
  *(_DWORD *)&v10[28] = retaddr;
  *(float *)&v10[8] = position->x * g_PhysicsUnits.unitScaleMeters;
  *(_DWORD *)&v10[12] = COERCE_UNSIGNED_INT(position->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  *(float *)&v10[16] = position->y * g_PhysicsUnits.unitScaleMeters;
  ConvertRotationToIVP(a1: (int)&v10[24], angles, out: (IVP_U_Quat *)&v9);
  v6 = *((_BYTE *)this + 18);
  if ( (v6 & 1) == 0 )
    *((_BYTE *)this + 18) = v6 | 1;
  if ( (float)((float)((float)((float)(*(float *)&v10[12] - this->m_shadow.targetPosition.k[1])
                             * (float)(*(float *)&v10[12] - this->m_shadow.targetPosition.k[1]))
                     + (float)((float)(*(float *)&v10[8] - this->m_shadow.targetPosition.k[0])
                             * (float)(*(float *)&v10[8] - this->m_shadow.targetPosition.k[0])))
             + (float)((float)(*(float *)&v10[16] - this->m_shadow.targetPosition.k[2])
                     * (float)(*(float *)&v10[16] - this->m_shadow.targetPosition.k[2]))) >= 0.0000000099999999
    || (float)((float)((float)(fabs(*((float *)&v9 + 1) - this->m_shadow.targetRotation.y)
                             + fabs(*(float *)&v9 - this->m_shadow.targetRotation.x))
                     + fabs(*(float *)v10 - this->m_shadow.targetRotation.z))
             + fabs(*(float *)&v10[4] - this->m_shadow.targetRotation.w)) >= 0.0000000099999999 )
  {
    *(_QWORD *)this->m_shadow.targetPosition.k = *(_QWORD *)&v10[8];
    *(_QWORD *)&this->m_shadow.targetPosition.k[2] = *(_QWORD *)&v10[16];
    *(_QWORD *)&this->m_shadow.targetRotation.x = v9;
    *(_QWORD *)&this->m_shadow.targetRotation.z = *(_QWORD *)v10;
    v7 = 0.0;
    if ( secondsToArrival >= 0.0 )
      v7 = secondsToArrival;
    m_pObject = this->m_pObject;
    this->m_secondsToArrival = v7;
    m_pObject->Wake(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020540
// Name: public: virtual void CShadowController::Update(class Vector const __near &,class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowController::Update(
        CShadowController *this@<ecx>,
        int a2@<ebp>,
        const Vector *position,
        const QAngle *angles,
        CPhysicsObject *secondsToArrival)
{
  char v6; // al
  CPhysicsObject *v7; // xmm0_4
  IPhysicsShadowController_vtbl *v8; // ecx
  IVP_U_Quat v9; // [esp-20h] [ebp-2Ch] BYREF
  __int64 v10; // [esp-10h] [ebp-1Ch]
  __int64 v11; // [esp-8h] [ebp-14h]
  _DWORD v12[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v12[0] = a2;
  v12[1] = retaddr;
  *(float *)&v10 = position->x * g_PhysicsUnits.unitScaleMeters;
  HIDWORD(v10) = COERCE_UNSIGNED_INT(position->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  *(float *)&v11 = position->y * g_PhysicsUnits.unitScaleMeters;
  ConvertRotationToIVP(a1: (int)v12, angles, out: &v9);
  v6 = BYTE2(this->m_secondsToArrival);
  if ( (v6 & 1) == 0 )
    BYTE2(this->m_secondsToArrival) = v6 | 1;
  if ( (float)((float)((float)((float)(*((float *)&v10 + 1) - this->m_shadow.targetPosition.k[0])
                             * (float)(*((float *)&v10 + 1) - this->m_shadow.targetPosition.k[0]))
                     + (float)((float)(*(float *)&v10 - *((float *)this + 7))
                             * (float)(*(float *)&v10 - *((float *)this + 7))))
             + (float)((float)(*(float *)&v11 - this->m_shadow.targetPosition.k[1])
                     * (float)(*(float *)&v11 - this->m_shadow.targetPosition.k[1]))) >= 0.0000000099999999
    || (float)((float)((float)(fabs(v9.y - this->m_shadow.targetRotation.x)
                             + fabs(v9.x - this->m_shadow.targetPosition.hesse_val))
                     + fabs(v9.z - this->m_shadow.targetRotation.y))
             + fabs(v9.w - this->m_shadow.targetRotation.z)) >= 0.0000000099999999 )
  {
    *(_QWORD *)((char *)this + 28) = v10;
    *(_QWORD *)&this->m_shadow.targetPosition.k[1] = v11;
    *(IVP_U_Quat *)&this->m_shadow.targetPosition.hesse_val = v9;
    v7 = nullptr;
    if ( *(float *)&secondsToArrival >= 0.0 )
      v7 = secondsToArrival;
    v8 = this->IPhysicsShadowController::__vftable;
    this->m_pObject = v7;
    (*((void (__thiscall **)(IPhysicsShadowController_vtbl *))v8->dtr_IPhysicsShadowController + 24))(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020690
// Name: public: virtual float CShadowController::GetTargetPosition(class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CShadowController::GetTargetPosition(
        CShadowController *this,
        Vector *pPositionOut,
        QAngle *pAnglesOut)
{
  float v4; // xmm0_4
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( pPositionOut != nullptr )
  {
    v4 = this->m_shadow.targetPosition.k[1] * g_PhysicsUnits.unitScaleMetersInv;
    LODWORD(pPositionOut->z) = COERCE_UNSIGNED_INT(this->m_shadow.targetPosition.k[0] * g_PhysicsUnits.unitScaleMetersInv)
                             ^ _mask__NegFloat_;
    pPositionOut->y = v4;
    pPositionOut->x = *((float *)this + 7) * g_PhysicsUnits.unitScaleMetersInv;
  }
  if ( pAnglesOut != nullptr )
    ConvertRotationToHL(
      a1: (int)&savedregs,
      a2: (int)this,
      in: (IVP_U_Quat *)&this->m_shadow.targetPosition.hesse_val,
      angles: pAnglesOut);
  return *(float *)&this->m_pObject;
}

//------------------------------------------------------------------------------
// Address: 0x10020700
// Name: public: void CShadowController::WriteToTemplate(struct vphysics_save_cshadowcontroller_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::WriteToTemplate(
        CShadowController *this,
        vphysics_save_cshadowcontroller_t *controllerTemplate)
{
  float v3; // xmm0_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  controllerTemplate->pObject = this->m_pObject;
  controllerTemplate->secondsToArrival = this->m_secondsToArrival;
  controllerTemplate->saveRot = this->m_saveRot;
  controllerTemplate->savedRI = this->m_savedRI;
  controllerTemplate->savedMass = this->m_savedMass;
  controllerTemplate->savedFlags = this->m_savedFlags;
  controllerTemplate->savedMaterial = this->m_savedMaterialIndex;
  controllerTemplate->enable = *((_BYTE *)this + 18) & 1;
  controllerTemplate->allowPhysicsMovement = (*((_BYTE *)this + 18) & 2) != 0;
  controllerTemplate->allowPhysicsRotation = (*((_BYTE *)this + 18) & 4) != 0;
  controllerTemplate->isPhysicallyControlled = (*((_BYTE *)this + 18) & 8) != 0;
  v3 = this->m_shadow.targetPosition.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(controllerTemplate->shadowParams.targetPosition.z) = COERCE_UNSIGNED_INT(
                                                                 this->m_shadow.targetPosition.k[1]
                                                               * g_PhysicsUnits.unitScaleMetersInv)
                                                             ^ _mask__NegFloat_;
  controllerTemplate->shadowParams.targetPosition.y = v3;
  controllerTemplate->shadowParams.targetPosition.x = this->m_shadow.targetPosition.k[0]
                                                    * g_PhysicsUnits.unitScaleMetersInv;
  ConvertRotationToHL(
    a1: (int)&savedregs,
    a2: (int)this,
    in: &this->m_shadow.targetRotation,
    angles: &controllerTemplate->shadowParams.targetRotation);
  controllerTemplate->shadowParams.teleportDistance = this->m_shadow.teleportDistance
                                                    * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->shadowParams.maxSpeed = this->m_shadow.maxSpeed * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->shadowParams.maxDampSpeed = this->m_shadow.maxDampSpeed * g_PhysicsUnits.unitScaleMetersInv;
  controllerTemplate->shadowParams.maxAngular = this->m_shadow.maxAngular * 57.29578;
  controllerTemplate->shadowParams.maxDampAngular = this->m_shadow.maxDampAngular * 57.29578;
  controllerTemplate->shadowParams.dampFactor = this->m_shadow.dampFactor;
}

//------------------------------------------------------------------------------
// Address: 0x10020850
// Name: public: void CShadowController::InitFromTemplate(struct vphysics_save_cshadowcontroller_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowController::InitFromTemplate(
        CShadowController *this,
        const vphysics_save_cshadowcontroller_t *controllerTemplate)
{
  char v3; // al
  char v4; // cl
  float y; // xmm0_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  this->m_pObject = controllerTemplate->pObject;
  this->m_secondsToArrival = controllerTemplate->secondsToArrival;
  this->m_saveRot = controllerTemplate->saveRot;
  this->m_savedRI = controllerTemplate->savedRI;
  this->m_savedMass = controllerTemplate->savedMass;
  this->m_savedFlags = controllerTemplate->savedFlags;
  this->m_savedMaterialIndex = controllerTemplate->savedMaterial;
  *((_BYTE *)this + 18) ^= (*((_BYTE *)this + 18) ^ controllerTemplate->enable) & 1;
  v3 = *((_BYTE *)this + 18) ^ (*((_BYTE *)this + 18) ^ (2 * controllerTemplate->allowPhysicsMovement)) & 2;
  *((_BYTE *)this + 18) = v3;
  v4 = v3 ^ (v3 ^ (4 * controllerTemplate->allowPhysicsRotation)) & 4;
  *((_BYTE *)this + 18) = v4;
  *((_BYTE *)this + 18) = v4 ^ (v4 ^ (8 * controllerTemplate->isPhysicallyControlled)) & 8;
  y = controllerTemplate->shadowParams.targetPosition.y;
  this->m_shadow.targetPosition.k[0] = controllerTemplate->shadowParams.targetPosition.x
                                     * g_PhysicsUnits.unitScaleMeters;
  LODWORD(this->m_shadow.targetPosition.k[1]) = COERCE_UNSIGNED_INT(
                                                  controllerTemplate->shadowParams.targetPosition.z
                                                * g_PhysicsUnits.unitScaleMeters)
                                              ^ _mask__NegFloat_;
  this->m_shadow.targetPosition.k[2] = g_PhysicsUnits.unitScaleMeters * y;
  ConvertRotationToIVP(
    a1: (int)&savedregs,
    angles: &controllerTemplate->shadowParams.targetRotation,
    out: &this->m_shadow.targetRotation);
  this->m_shadow.teleportDistance = controllerTemplate->shadowParams.teleportDistance * g_PhysicsUnits.unitScaleMeters;
  this->m_shadow.maxSpeed = controllerTemplate->shadowParams.maxSpeed * g_PhysicsUnits.unitScaleMeters;
  this->m_shadow.maxDampSpeed = controllerTemplate->shadowParams.maxDampSpeed * g_PhysicsUnits.unitScaleMeters;
  this->m_shadow.maxAngular = controllerTemplate->shadowParams.maxAngular * 0.017453292;
  this->m_shadow.maxDampAngular = controllerTemplate->shadowParams.maxDampAngular * 0.017453292;
  this->m_shadow.dampFactor = controllerTemplate->shadowParams.dampFactor;
  IVP_Controller_Manager::add_controller_to_core(cntrl: this, core: this->m_pObject->m_pObject->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x100209C0
// Name: void ControlPhysicsPlayerControllerAttachment_Silent(class IPhysicsPlayerController __near *,class IVP_Real_Object __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ControlPhysicsPlayerControllerAttachment_Silent(
        IPhysicsPlayerController *pController,
        IVP_Real_Object *pivp,
        bool bAttach)
{
  IVP_Controller_Independent *v3; // eax
  IVP_Controller_Independent *v4; // eax

  if ( bAttach )
  {
    if ( pController != nullptr )
      v3 = (IVP_Controller_Independent *)&pController[-1];
    else
      v3 = nullptr;
    IVP_Controller_Manager::add_controller_to_core(cntrl: v3, core: pivp->physical_core);
  }
  else
  {
    if ( pController != nullptr )
      v4 = (IVP_Controller_Independent *)&pController[-1];
    else
      v4 = nullptr;
    IVP_Controller_Manager::remove_controller_from_core(cntrl: v4, core: pivp->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020A10
// Name: public: void CUtlMemory<struct CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>::Grow(
        CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 200 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPredictedPlayerController::PlayerControllerPredictionBackups_t *)_g_pMemAlloc->Realloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: m_pMemory,
                                                                                             a3: v7);
    else
      this->m_pMemory = (CPredictedPlayerController::PlayerControllerPredictionBackups_t *)_g_pMemAlloc->Alloc_2(
                                                                                             this: _g_pMemAlloc,
                                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020AD0
// Name: public: virtual void CPredictedPlayerController::Update(class Vector const __near &,class Vector const __near &,float,bool,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPredictedPlayerController::Update(
        CPredictedPlayerController *this@<ecx>,
        int a2@<ebp>,
        const Vector *position,
        const Vector *velocity,
        float secondsToArrival,
        bool onground,
        CPhysicsObject *ground)
{
  __int128 v8; // xmm0
  __int128 v9; // xmm0
  float v10; // xmm0_4
  CPhysicsObject *v11; // edi
  _BYTE v12[12]; // [esp+1Ch] [ebp-8Ch] BYREF
  matrix3x4_t matInverseGround; // [esp+28h] [ebp-80h] BYREF
  __int128 matGround_36; // [esp+7Ch] [ebp-2Ch] OVERLAPPED
  CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t **p_m_pReferencedBackup; // [esp+98h] [ebp-10h]
  int v16; // [esp+9Ch] [ebp-Ch]
  void *v17; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v16 = a2;
  v17 = retaddr;
  if ( *((_DWORD *)&this->CPlayerController + 39) != 0 )
  {
    BYTE1(this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_pElements) = 1;
    v8 = 0;
    *(float *)&v8 = fsqrt(
                      (float)((float)((float)(velocity->y - this->m_ActiveBackup.vCurrentSpeed.x)
                                    * (float)(velocity->y - this->m_ActiveBackup.vCurrentSpeed.x))
                            + (float)((float)(velocity->z - this->m_ActiveBackup.vCurrentSpeed.y)
                                    * (float)(velocity->z - this->m_ActiveBackup.vCurrentSpeed.y)))
                    + (float)((float)(velocity->x - this->m_ActiveBackup.vLastImpulse.z)
                            * (float)(velocity->x - this->m_ActiveBackup.vLastImpulse.z)));
    matGround_36 = v8;
    if ( *(float *)&v8 >= 0.000001
      || (v9 = 0,
          *(float *)&v9 = fsqrt(
                            (float)((float)((float)(position->y - this->m_ActiveBackup.vTargetPosition.x)
                                          * (float)(position->y - this->m_ActiveBackup.vTargetPosition.x))
                                  + (float)((float)(position->z - this->m_ActiveBackup.vTargetPosition.y)
                                          * (float)(position->z - this->m_ActiveBackup.vTargetPosition.y)))
                          + (float)((float)(position->x - *(float *)&this->m_pReferencedBackup)
                                  * (float)(position->x - *(float *)&this->m_pReferencedBackup))),
          matGround_36 = v9,
          *(float *)&v9 >= 0.000001) )
    {
      v10 = 0.0;
      *(float *)&this->m_pReferencedBackup = position->x;
      this->m_ActiveBackup.vTargetPosition.x = position->y;
      p_m_pReferencedBackup = &this->m_pReferencedBackup;
      this->m_ActiveBackup.vTargetPosition.y = position->z;
      if ( secondsToArrival >= 0.0 )
        v10 = secondsToArrival;
      this->m_ActiveBackup.vSimulationGravity.z = v10;
      *(Vector *)&this->m_ActiveBackup.vLastImpulse.z = *velocity;
      IVP_Controller_Manager::ensure_core_in_simulation(
        this: *(IVP_Controller_Manager **)(*((_DWORD *)this->event_object_revived + 6) + 52),
        core: *((IVP_Core **)this->event_object_revived + 37));
      HIBYTE(this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_pElements) = 1;
      if ( (float)((float)((float)(velocity->y * velocity->y) + (float)(velocity->x * velocity->x))
                 + (float)(velocity->z * velocity->z)) > 0.1 )
      {
        ((void (__thiscall *)(CPredictedPlayerController *, const Vector *))this->do_simulation_controller)(
          a1: this,
          a2: velocity);
        v11 = ground;
      }
      else
      {
        HIBYTE(this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_pElements) = 0;
        v11 = nullptr;
      }
      CPredictedPlayerController::SetGround(this: (CPredictedPlayerController *)((char *)this - 4), pGroundObject: v11);
      if ( LODWORD(this->m_ActiveBackup.fSecondsToArrival) != 0 )
      {
        v11->GetPositionMatrix(this: v11, a2: (matrix3x4_t *)&matInverseGround.m_flMatVal[2][1]);
        MatrixInvert(in: (matrix3x4_t *)&matInverseGround.m_flMatVal[2][1], out: (matrix3x4_t *)v12);
        VectorTransform(
          in1: (const float *)p_m_pReferencedBackup,
          in2: (const matrix3x4_t *)v12,
          out: &this->m_ActiveBackup.vTargetPosition.z);
      }
    }
  }
  else
  {
    CPlayerController::Update(this, position, velocity, secondsToArrival, onground, ground);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020D00
// Name: class CShadowController __near * CreateShadowController(class CPhysicsObject __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CShadowController *__usercall CreateShadowController@<eax>(
        int a1@<edi>,
        CPhysicsObject *pObject,
        bool allowTranslation,
        bool allowRotation)
{
  char *v4; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v4 = (char *)p_malloc(size: 0xB0u);
  if ( v4 == nullptr )
    return nullptr;
  *((_DWORD *)v4 + 1) = &IPhysicsShadowController::`vftable';
  *(_DWORD *)v4 = &CShadowController::`vftable'{for `IVP_Controller_Independent'};
  *((_DWORD *)v4 + 1) = &CShadowController::`vftable'{for `IPhysicsShadowController'};
  *(_QWORD *)(v4 + 68) = 0;
  *((_DWORD *)v4 + 16) = 0;
  *(_QWORD *)(v4 + 84) = 0;
  *((_DWORD *)v4 + 20) = 0;
  *((_DWORD *)v4 + 2) = pObject;
  *((_DWORD *)v4 + 28) = 1065353216;
  *((_DWORD *)v4 + 29) = 0;
  *((_DWORD *)v4 + 27) = 0;
  *((_DWORD *)v4 + 25) = 0;
  *(_QWORD *)(v4 + 36) = 0;
  *((_DWORD *)v4 + 8) = 0;
  *((_QWORD *)v4 + 7) = 0;
  *((_QWORD *)v4 + 6) = 0;
  v4[18] = v4[18] & 0xF0 | (2 * (allowTranslation | (2 * allowRotation)));
  CShadowController::AttachObject(this: (CShadowController *)v4, a2: COERCE_FLOAT(&savedregs), a3: a1, a4: (int)v4);
  return (CShadowController *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10020DD0
// Name: bool RestorePhysicsShadowControllerInternal(struct physrestoreparams_t const __near &,class IPhysicsShadowController __near * __near *,class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __usercall RestorePhysicsShadowControllerInternal@<al>(
        int a1@<ebp>,
        int a2@<esi>,
        const physrestoreparams_t *params,
        IPhysicsShadowController **ppShadowController,
        CPhysicsObject *pObject)
{
  char *v5; // eax
  CShadowController *v6; // esi
  _BYTE controllerTemplate[136]; // [esp-Ch] [ebp-8Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&controllerTemplate[128] = a1;
  *(_DWORD *)&controllerTemplate[132] = retaddr;
  memset(dst: controllerTemplate, value: 0, count: 0x80u);
  ((void (__thiscall *)(IRestore *, _BYTE *, datamap_t *, int))params->pRestore->ReadAll)(
    a1: params->pRestore,
    a2: controllerTemplate,
    a3: &vphysics_save_cshadowcontroller_t::m_DataMap,
    a4: a2);
  *(_DWORD *)controllerTemplate = pObject;
  v5 = (char *)p_malloc(size: 0xB0u);
  if ( v5 != nullptr )
  {
    *(_QWORD *)(v5 + 68) = 0;
    *((_DWORD *)v5 + 16) = 0;
    *(_QWORD *)(v5 + 84) = 0;
    *((_DWORD *)v5 + 20) = 0;
    *(_QWORD *)(v5 + 36) = 0;
    *((_DWORD *)v5 + 8) = 0;
    *((_DWORD *)v5 + 1) = &IPhysicsShadowController::`vftable';
    *(_DWORD *)v5 = &CShadowController::`vftable'{for `IVP_Controller_Independent'};
    *((_DWORD *)v5 + 1) = &CShadowController::`vftable'{for `IPhysicsShadowController'};
    *((_QWORD *)v5 + 7) = 0;
    *((_QWORD *)v5 + 6) = 0;
    v6 = (CShadowController *)v5;
  }
  else
  {
    v6 = nullptr;
  }
  CShadowController::InitFromTemplate(this: v6, (const vphysics_save_cshadowcontroller_t *)controllerTemplate);
  if ( v6 != nullptr )
    *ppShadowController = &v6->IPhysicsShadowController;
  else
    *ppShadowController = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10020EC0
// Name: public: CPlayerController::CPlayerController(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
CPlayerController *__userpurge CPlayerController::CPlayerController@<eax>(
        CPlayerController *this@<ecx>,
        int a2@<edi>,
        CPhysicsObject *pObject)
{
  float v4; // xmm0_4

  this->IPhysicsPlayerController::__vftable = (IPhysicsPlayerController_vtbl *)&IPhysicsPlayerController::`vftable';
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->m_pObject = pObject;
  this->IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPlayerController_vtbl *)&CPlayerController::`vftable'{for `IPredictable_Controller_Independant'};
  this->IPhysicsPlayerController::__vftable = (IPhysicsPlayerController_vtbl *)&CPlayerController::`vftable'{for `IPhysicsPlayerController'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPlayerController::`vftable'{for `IVP_Listener_Object'};
  this->m_pGround = nullptr;
  this->m_handler = nullptr;
  v4 = g_PhysicsUnits.unitScaleMeters * 24.0;
  *((_BYTE *)this + 144) &= ~4u;
  this->m_maxDeltaPosition = v4;
  this->m_dampFactor = 1.0;
  this->m_targetPosition.k[2] = 0.0;
  this->m_targetPosition.k[1] = 0.0;
  this->m_targetPosition.k[0] = 0.0;
  this->m_pushableMassLimit = 50000.0;
  this->m_pushableSpeedLimit = 10000.0;
  CPlayerController::AttachObject(this, a2, a3: (int)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10020FB0
// Name: public: virtual int CPlayerController::GetShadowPosition(class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CPlayerController::GetShadowPosition@<eax>(
        CPlayerController *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Vector *position,
        QAngle *angles)
{
  float v5; // xmm1_4
  _BYTE v7[12]; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE matrix_36[32]; // [esp+24h] [ebp-2Ch] OVERLAPPED
  int v9; // [esp+44h] [ebp-Ch]
  long double psi; // [esp+48h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  v9 = a2;
  LODWORD(psi) = retaddr;
  *(_QWORD *)&matrix_36[24] = *(_QWORD *)(*((_DWORD *)this->event_object_revived + 6) + 248);
  IVP_Real_Object::calc_at_matrix(
    this: (IVP_Real_Object *)this->event_object_revived,
    current_time: *(IVP_Time *)&matrix_36[24],
    m_world_f_object_out: (IVP_U_Matrix *)v7);
  if ( angles != nullptr )
    ConvertRotationToHL(a1: a3, in: (const IVP_U_Matrix3 *)v7, angles);
  if ( position != nullptr )
  {
    v5 = g_PhysicsUnits.unitScaleMetersInv * *(float *)&matrix_36[8];
    LODWORD(position->z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * *(float *)&matrix_36[4])
                         ^ _mask__NegFloat_;
    position->y = v5;
    position->x = g_PhysicsUnits.unitScaleMetersInv * *(float *)matrix_36;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10021070
// Name: public: virtual int CPredictedPlayerController::GetShadowPosition(class Vector __near *,class QAngle __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CPredictedPlayerController::GetShadowPosition@<eax>(
        CPredictedPlayerController *this@<ecx>,
        int a2@<esi>,
        Vector *position,
        QAngle *angles)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( *((_DWORD *)&this->CPlayerController + 39) == 0 )
    return CPlayerController::GetShadowPosition(this, a2: (int)&savedregs, a3: a2, position, angles);
  (*((void (__thiscall **)(IVP_Listener_Object_vtbl *, Vector *, QAngle *))this->event_object_deleted + 48))(
    a1: this->CPlayerController::IVP_Listener_Object::__vftable,
    a2: position,
    a3: angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100210E0
// Name: bool SavePhysicsShadowController(struct physsaveparams_t const __near &,class IPhysicsShadowController __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall SavePhysicsShadowController@<al>(
        int a1@<ebp>,
        const physsaveparams_t *params,
        IPhysicsShadowController *pIShadow)
{
  CShadowController *v3; // ecx
  _BYTE v5[136]; // [esp-Ch] [ebp-8Ch] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h]

  *(_DWORD *)&v5[128] = a1;
  *(_DWORD *)&v5[132] = retaddr;
  memset(dst: v5, value: 0, count: 0x80u);
  if ( pIShadow != nullptr )
    v3 = (CShadowController *)&pIShadow[-1];
  else
    v3 = nullptr;
  CShadowController::WriteToTemplate(this: v3, controllerTemplate: (vphysics_save_cshadowcontroller_t *)v5);
  params->pSave->WriteAll(this: params->pSave, a2: v5, a3: &vphysics_save_cshadowcontroller_t::m_DataMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10021150
// Name: public: class Vector CNormalList::ClampVector(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CNormalList::ClampVector(CNormalList *this, Vector *result, const Vector *inVector, float limitVel)
{
  int m_Size; // eax
  int v5; // edx
  float *v6; // ecx
  float z; // edx
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float y; // xmm2_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm0_4

  m_Size = this->m_Normals.m_Size;
  if ( m_Size <= 2 )
  {
    if ( m_Size == 2 )
    {
      v9 = (float)(*(float *)&this->m_Normals.m_Memory.m_Memory[4] * *(float *)&this->m_Normals.m_Memory.m_Memory[20])
         - (float)(*(float *)&this->m_Normals.m_Memory.m_Memory[8] * *(float *)&this->m_Normals.m_Memory.m_Memory[16]);
      v10 = (float)(*(float *)&this->m_Normals.m_Memory.m_Memory[8] * *(float *)&this->m_Normals.m_Memory.m_Memory[12])
          - (float)(*(float *)this->m_Normals.m_Memory.m_Memory * *(float *)&this->m_Normals.m_Memory.m_Memory[20]);
      v11 = (float)(*(float *)this->m_Normals.m_Memory.m_Memory * *(float *)&this->m_Normals.m_Memory.m_Memory[16])
          - (float)(*(float *)&this->m_Normals.m_Memory.m_Memory[4] * *(float *)&this->m_Normals.m_Memory.m_Memory[12]);
      v12 = (float)((float)(inVector->y * v10) + (float)(inVector->x * v9)) + (float)(inVector->z * v11);
      result->x = v9 * v12;
      result->y = v10 * v12;
      result->z = v11 * v12;
      return result;
    }
    else if ( m_Size == 1
           && (v13 = *(float *)&this->m_Normals.m_Memory.m_Memory[4],
               y = inVector->y,
               v15 = *(float *)&this->m_Normals.m_Memory.m_Memory[8],
               v16 = inVector->z,
               (v17 = (float)((float)(v13 * y) + (float)(*(float *)this->m_Normals.m_Memory.m_Memory * inVector->x))
                    + (float)(v15 * v16)) > limitVel) )
    {
      result->x = inVector->x + (float)(*(float *)this->m_Normals.m_Memory.m_Memory * (float)(limitVel - v17));
      result->y = y + (float)(v13 * (float)(limitVel - v17));
      result->z = v16 + (float)(v15 * (float)(limitVel - v17));
      return result;
    }
    else
    {
LABEL_6:
      z = inVector->z;
      *(_QWORD *)&result->x = *(_QWORD *)&inVector->x;
      result->z = z;
      return result;
    }
  }
  else
  {
    v5 = 0;
    v6 = (float *)&this->m_Normals.m_Memory.m_Memory[8];
    while ( (float)((float)((float)(*(v6 - 2) * inVector->x) + (float)(*(v6 - 1) * inVector->y))
                  + (float)(inVector->z * *v6)) <= 0.0 )
    {
      ++v5;
      v6 += 3;
      if ( v5 >= m_Size )
        goto LABEL_6;
    }
    *result = vec3_origin;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021300
// Name: public: virtual void CPredictedPlayerController::Prediction_Resimulate(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPlayerController::Prediction_Resimulate(
        CPredictedPlayerController *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        float fSimulationTime)
{
  float unitScaleMeters; // xmm0_4
  CPhysicsObject *pGround; // ecx
  float y; // xmm5_4
  float z; // xmm4_4
  float v9; // xmm6_4
  bool v10; // zf
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float fSecondsToArrival; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float damping; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm5_4
  float v31; // xmm4_4
  float v32; // xmm2_4
  float v33; // xmm4_4
  float v34; // xmm6_4
  CPhysicsObject *m_pObject; // ecx
  float v36; // xmm0_4
  float limitVel; // [esp+24h] [ebp-D0h]
  _BYTE v38[12]; // [esp+34h] [ebp-C0h] BYREF
  matrix3x4_t matGround; // [esp+40h] [ebp-B4h] BYREF
  Vector vNewVelocity; // [esp+70h] [ebp-84h] BYREF
  Vector vCurVelocity; // [esp+7Ch] [ebp-78h] BYREF
  Vector vCurPos; // [esp+88h] [ebp-6Ch] BYREF
  IVP_U_Float_Point tmp; // [esp+94h] [ebp-60h] BYREF
  IVP_U_Float_Point lastImpulse; // [esp+A4h] [ebp-50h] BYREF
  float v45; // [esp+B4h] [ebp-40h]
  float v46; // [esp+C4h] [ebp-30h]
  float v47; // [esp+C8h] [ebp-2Ch] BYREF
  float v48; // [esp+CCh] [ebp-28h] BYREF
  float fraction; // [esp+D0h] [ebp-24h]
  Vector vBaseVelocity; // [esp+D4h] [ebp-20h] BYREF
  float v51; // [esp+E0h] [ebp-14h]
  IVP_U_Float_Point coreSpeed; // [esp+E4h] [ebp-10h]
  float retaddr; // [esp+F4h] [ebp+0h]

  coreSpeed.k[1] = a2;
  coreSpeed.k[2] = retaddr;
  CPredictedPhysicsObject::PreAnyController(
    this: (CPredictedPhysicsObject *)this->m_pObject,
    a2: a3,
    fSimulationTime,
    bBackup: false);
  if ( this->m_ActiveBackup.bEnable )
  {
    this->m_pObject->GetPosition(this: this->m_pObject, a2: &vCurVelocity, a3: nullptr);
    this->m_pObject->GetVelocity(this: this->m_pObject, a2: &vNewVelocity, a3: nullptr);
    unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
    pGround = this->m_ActiveBackup.pGround;
    y = vNewVelocity.x * g_PhysicsUnits.unitScaleMeters;
    z = -(float)(vNewVelocity.z * g_PhysicsUnits.unitScaleMeters);
    v9 = vNewVelocity.y * g_PhysicsUnits.unitScaleMeters;
    vBaseVelocity.y = vNewVelocity.x * g_PhysicsUnits.unitScaleMeters;
    vBaseVelocity.z = z;
    v51 = vNewVelocity.y * g_PhysicsUnits.unitScaleMeters;
    memset(&lastImpulse.k[1], 0, 12);
    if ( pGround != nullptr )
    {
      pGround->GetPositionMatrix(this: pGround, a2: (matrix3x4_t *)v38);
      VectorTransform(
        in1: &this->m_ActiveBackup.vGroundPosition.x,
        in2: (const matrix3x4_t *)v38,
        out: &this->m_ActiveBackup.vTargetPosition.x);
      this->m_ActiveBackup.pGround->GetVelocityAtPoint(
        this: this->m_ActiveBackup.pGround,
        a2: &this->m_ActiveBackup.vGroundPosition,
        a3: (Vector *)&v48);
      unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
      y = vBaseVelocity.y - (float)(v48 * g_PhysicsUnits.unitScaleMeters);
      z = vBaseVelocity.z - (float)-(float)(vBaseVelocity.x * g_PhysicsUnits.unitScaleMeters);
      v9 = v51 - (float)(fraction * g_PhysicsUnits.unitScaleMeters);
      lastImpulse.k[1] = v48 * g_PhysicsUnits.unitScaleMeters;
      lastImpulse.k[2] = -(float)(vBaseVelocity.x * g_PhysicsUnits.unitScaleMeters);
      lastImpulse.hesse_val = fraction * g_PhysicsUnits.unitScaleMeters;
      vBaseVelocity.y = y;
      vBaseVelocity.z = z;
      v51 = v9;
    }
    v10 = !this->m_ActiveBackup.bForceTeleport;
    v11 = (float)(this->m_ActiveBackup.vTargetPosition.x - vCurVelocity.x) * unitScaleMeters;
    v12 = -(float)((float)(this->m_ActiveBackup.vTargetPosition.z - vCurVelocity.z) * unitScaleMeters);
    v13 = (float)(this->m_ActiveBackup.vTargetPosition.y - vCurVelocity.y) * unitScaleMeters;
    v47 = v11;
    v48 = v12;
    fraction = v13;
    if ( !v10
      || (float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13)) > (float)(this->m_maxDeltaPosition
                                                                                                * this->m_maxDeltaPosition) )
    {
      if ( CPredictedPlayerController::TryTeleportObject(this) != 0 )
        return;
      unitScaleMeters = g_PhysicsUnits.unitScaleMeters;
      v9 = v51;
      z = vBaseVelocity.z;
      y = vBaseVelocity.y;
    }
    v10 = !this->m_ActiveBackup.bOnGround;
    v14 = this->m_ActiveBackup.vSimulationGravity.z;
    v15 = this->m_ActiveBackup.vSimulationGravity.y;
    vCurPos.x = (float)(this->m_ActiveBackup.vSimulationGravity.x * fSimulationTime) * unitScaleMeters;
    v16 = -(float)((float)(v14 * fSimulationTime) * unitScaleMeters);
    v17 = (float)(v15 * fSimulationTime) * unitScaleMeters;
    if ( !v10 )
    {
      vBaseVelocity.y = y - vCurPos.x;
      vBaseVelocity.z = z - v16;
      v51 = v9 - v17;
    }
    fSecondsToArrival = this->m_ActiveBackup.fSecondsToArrival;
    v19 = 1.0;
    v46 = 1.0;
    if ( fSecondsToArrival > 0.0 )
    {
      v19 = fSimulationTime / fSecondsToArrival;
      v46 = fSimulationTime / fSecondsToArrival;
      if ( (float)(fSimulationTime / fSecondsToArrival) > 1.0 )
      {
        v19 = 1.0;
        v46 = 1.0;
      }
    }
    v10 = !this->m_ActiveBackup.bUpdatedSinceLast;
    tmp.k[1] = unitScaleMeters * this->m_ActiveBackup.vLastImpulse.x;
    v20 = this->m_ActiveBackup.vLastImpulse.z * unitScaleMeters;
    v21 = unitScaleMeters * this->m_ActiveBackup.vLastImpulse.y;
    tmp.k[2] = -v20;
    tmp.hesse_val = v21;
    if ( v10 )
    {
      vCurPos.x = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&tmp.k[1]);
      damping = this->m_dampFactor;
      vCurPos.y = vCurPos.x;
      vCurPos.z = vCurPos.x;
      ComputeController(
        currentSpeed: (IVP_U_Float_Point *)&vBaseVelocity.y,
        delta: (const IVP_U_Float_Point *)&v47,
        maxSpeed: (const IVP_U_Float_Point *)&vCurPos,
        scaleDelta: v46 / fSimulationTime,
        damping,
        pOutImpulse: nullptr);
    }
    else
    {
      ComputeController(
        currentSpeed: (IVP_U_Float_Point *)&vBaseVelocity.y,
        delta: (const IVP_U_Float_Point *)&v47,
        maxSpeed: &this->m_maxSpeed,
        scaleDelta: v19 / fSimulationTime,
        damping: this->m_dampFactor,
        pOutImpulse: (IVP_U_Float_Point *)&tmp.k[1]);
    }
    v23 = vBaseVelocity.y + lastImpulse.k[1];
    v24 = lastImpulse.k[2] + vBaseVelocity.z;
    v25 = lastImpulse.hesse_val + v51;
    this->m_ActiveBackup.bUpdatedSinceLast = false;
    vBaseVelocity.y = v23;
    v48 = v23 * g_PhysicsUnits.unitScaleMetersInv;
    limitVel = this->m_ActiveBackup.fFrictionSnapshotLimitVel;
    LODWORD(vBaseVelocity.x) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * v24) ^ _mask__NegFloat_;
    vBaseVelocity.z = v24;
    v51 = v25;
    fraction = v25 * g_PhysicsUnits.unitScaleMetersInv;
    CNormalList::ClampVector(
      this: &this->m_ActiveBackup.frictionSnapshotNormals,
      result: (Vector *)&lastImpulse.k[2],
      inVector: (const Vector *)&v48,
      limitVel);
    v10 = !this->m_ActiveBackup.bFrictionSnapshotGround;
    v26 = (float)(lastImpulse.k[2] - v48) * g_PhysicsUnits.unitScaleMeters;
    v27 = v26 + tmp.k[1];
    v28 = v26 + vBaseVelocity.y;
    v29 = tmp.k[2] - (float)((float)(v45 - vBaseVelocity.x) * g_PhysicsUnits.unitScaleMeters);
    v30 = vBaseVelocity.z - (float)((float)(v45 - vBaseVelocity.x) * g_PhysicsUnits.unitScaleMeters);
    v31 = (float)(lastImpulse.hesse_val - fraction) * g_PhysicsUnits.unitScaleMeters;
    v32 = v31 + tmp.hesse_val;
    v33 = v31 + v51;
    tmp.k[1] = v27;
    tmp.k[2] = v29;
    tmp.hesse_val = v32;
    if ( !v10 && v29 >= 0.0 )
    {
      v29 = 0.0;
      v30 = 0.0;
      tmp.k[2] = 0.0;
    }
    v34 = g_PhysicsUnits.unitScaleMetersInv * v29;
    this->m_ActiveBackup.vLastImpulse.y = v32 * g_PhysicsUnits.unitScaleMetersInv;
    this->m_ActiveBackup.vLastImpulse.z = -v34;
    this->m_ActiveBackup.vLastImpulse.x = v27 * g_PhysicsUnits.unitScaleMetersInv;
    m_pObject = this->m_pObject;
    matGround.m_flMatVal[2][3] = -(float)(g_PhysicsUnits.unitScaleMetersInv * v30);
    matGround.m_flMatVal[2][2] = v33 * g_PhysicsUnits.unitScaleMetersInv;
    matGround.m_flMatVal[2][1] = v28 * g_PhysicsUnits.unitScaleMetersInv;
    m_pObject->SetVelocityInstantaneous(this: m_pObject, a2: (const Vector *)&matGround.m_flMatVal[2][1], a3: nullptr);
    v36 = this->m_ActiveBackup.fSecondsToArrival - fSimulationTime;
    this->m_ActiveBackup.fSecondsToArrival = v36;
    if ( v36 < 0.0 )
      this->m_ActiveBackup.fSecondsToArrival = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021DB0
// Name: public: struct CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t __near & CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::operator=(struct CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *__thiscall CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::operator=(
        CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *this,
        const CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *__that)
{
  this->vTargetPosition = __that->vTargetPosition;
  this->vGroundPosition = __that->vGroundPosition;
  this->vMaxSpeed = __that->vMaxSpeed;
  this->vLastImpulse = __that->vLastImpulse;
  this->vCurrentSpeed = __that->vCurrentSpeed;
  this->vSimulationGravity = __that->vSimulationGravity;
  this->fSecondsToArrival = __that->fSecondsToArrival;
  this->pGround = __that->pGround;
  this->fFrictionSnapshotLimitVel = __that->fFrictionSnapshotLimitVel;
  CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::operator=(
    this: &this->frictionSnapshotNormals.m_Normals,
    other: &__that->frictionSnapshotNormals.m_Normals);
  this->bFrictionSnapshotGround = __that->bFrictionSnapshotGround;
  this->bUpdatedSinceLast = __that->bUpdatedSinceLast;
  this->bForceTeleport = __that->bForceTeleport;
  this->bEnable = __that->bEnable;
  this->bOnGround = __that->bOnGround;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021E90
// Name: public: void CPredictedPlayerController::DoneReferencingPreviousCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::DoneReferencingPreviousCommands(
        CPredictedPlayerController *this,
        int iCommandNum)
{
  int v3; // eax
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pMemory; // edx
  int *i; // ecx
  CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *m_pReferencedBackup; // ecx
  int v7; // esi

  v3 = 0;
  if ( this->m_PredictionBackups.m_Size != 0 )
  {
    m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
    for ( i = &m_pMemory->iCommandNum; *i < iCommandNum; i += 50 )
    {
      if ( ++v3 == this->m_PredictionBackups.m_Size )
        return;
    }
    if ( v3 > 0 && m_pMemory[v3 - 1].iCommandNum != -1 )
    {
      m_pReferencedBackup = this->m_pReferencedBackup;
      if ( m_pReferencedBackup != nullptr )
      {
        v7 = (char *)&m_pReferencedBackup[-v3] - (char *)m_pMemory;
        CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::RemoveMultipleFromHead(
          this: &this->m_PredictionBackups,
          num: v3);
        if ( v7 < 0 )
          this->m_pReferencedBackup = nullptr;
        else
          this->m_pReferencedBackup = (CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *)((char *)&this->m_PredictionBackups.m_Memory.m_pMemory->Backup_OnPredictionCommandChanged + v7);
      }
      else
      {
        CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::RemoveMultipleFromHead(
          this: &this->m_PredictionBackups,
          num: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021F40
// Name: public: virtual void CPlayerController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPlayerController::do_simulation_controller(
        CPlayerController *this@<ecx>,
        int a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Real_Object *m_pObject; // edx
  IVP_U_Matrix3 *physical_core; // edi
  CPhysicsObject *m_pGround; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  IVP_Environment *environment; // eax
  int v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float m_secondsToArrival; // xmm1_4
  float z; // xmm0_4
  float damping; // xmm0_4
  float *v23; // edx
  float v24; // xmm1_4
  float v25; // xmm2_4
  IPhysicsFrictionSnapshot *FrictionSnapshot; // eax
  float hesse_val; // xmm0_4
  float v28; // edi
  bool (__thiscall *IsValid)(IPhysicsFrictionSnapshot *); // eax
  float m_pushableSpeedLimit; // xmm0_4
  int v31; // edi
  double (__thiscall *v32)(_DWORD); // edx
  double v33; // st7
  int v34; // eax
  float *v35; // ecx
  int v36; // edi
  float v37; // xmm0_4
  IVP_Real_Object *v38; // edi
  IVP_Core *v39; // eax
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm0_4
  _BYTE v49[12]; // [esp+14h] [ebp-F4h] BYREF
  CNormalList normalList; // [esp+20h] [ebp-E8h] BYREF
  float v51; // [esp+98h] [ebp-70h]
  float v52; // [esp+9Ch] [ebp-6Ch] BYREF
  __int64 v53; // [esp+A0h] [ebp-68h] OVERLAPPED
  IVP_U_Float_Point baseVelocity; // [esp+A8h] [ebp-60h]
  float v55; // [esp+B8h] [ebp-50h]
  float v56; // [esp+BCh] [ebp-4Ch] BYREF
  IPhysicsFrictionSnapshot *pSnapshot; // [esp+C0h] [ebp-48h] BYREF
  float gravDt; // [esp+C4h] [ebp-44h]
  float v59; // [esp+C8h] [ebp-40h]
  IVP_Real_Object *v60; // [esp+D8h] [ebp-30h]
  float v61; // [esp+DCh] [ebp-2Ch] BYREF
  float v62; // [esp+E0h] [ebp-28h] BYREF
  IVP_Real_Object *pivp; // [esp+E4h] [ebp-24h]
  float v64; // [esp+E8h] [ebp-20h]
  Vector normal; // [esp+ECh] [ebp-1Ch]
  char v66; // [esp+FBh] [ebp-Dh]
  int v67; // [esp+FCh] [ebp-Ch] BYREF
  float limitVel; // [esp+100h] [ebp-8h]
  float retaddr; // [esp+108h] [ebp+0h]

  v67 = a2;
  limitVel = retaddr;
  if ( (*((_BYTE *)this + 144) & 1) != 0 )
  {
    m_pObject = this->m_pObject->m_pObject;
    physical_core = (IVP_U_Matrix3 *)m_pObject->physical_core;
    m_pGround = this->m_pGround;
    v60 = m_pObject;
    v53 = 0;
    v52 = 0.0;
    if ( m_pGround != nullptr )
    {
      IVP_U_Matrix::vmult4(
        this: &m_pGround->m_pObject->physical_core->m_world_f_core_last_psi,
        p_in: &this->m_groundPosition,
        p_out: &this->m_targetPosition);
      IVP_Core::get_surface_speed(
        this: this->m_pGround->m_pObject->physical_core,
        point_core: &this->m_groundPosition,
        speed_world_out: (IVP_U_Float_Point *)&v52);
      v8 = physical_core[4].rows[1].k[1] - *(float *)&v53;
      v9 = physical_core[4].rows[1].k[2] - *((float *)&v53 + 1);
      m_pObject = v60;
      physical_core[4].rows[1].k[0] = physical_core[4].rows[1].k[0] - v52;
      physical_core[4].rows[1].k[1] = v8;
      physical_core[4].rows[1].k[2] = v9;
    }
    v10 = (*(_DWORD *)&m_pObject->flags & 0x800) == 0;
    v11 = this->m_targetPosition.k[0] - physical_core[3].rows[0].k[0];
    v12 = this->m_targetPosition.k[1] - physical_core[3].rows[0].k[1];
    v13 = this->m_targetPosition.k[2] - physical_core[3].rows[0].k[2];
    v61 = v11;
    v62 = v12;
    *(float *)&pivp = v13;
    if ( v10 )
    {
      IVP_U_Matrix3::vmult3(
        this: physical_core + 2,
        p_in: &m_pObject->shift_core_f_object,
        p_out: (IVP_U_Float_Point *)&v56);
      v11 = v61 - v56;
      v12 = v62 - *(float *)&pSnapshot;
      v13 = *(float *)&pivp - gravDt;
      v61 = v61 - v56;
      v62 = v62 - *(float *)&pSnapshot;
      *(float *)&pivp = *(float *)&pivp - gravDt;
    }
    if ( (*((_BYTE *)this + 144) & 4) == 0
      && (float)((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13)) <= (float)(this->m_maxDeltaPosition
                                                                                                 * this->m_maxDeltaPosition)
      || CPlayerController::TryTeleportObject(this, a2: COERCE_FLOAT(&v67)) == 0 )
    {
      v10 = (*((_BYTE *)this + 144) & 2) == 0;
      environment = es->environment;
      *(float *)&v15 = environment->gravity.k[1] * es->delta_time;
      v16 = environment->gravity.k[2] * es->delta_time;
      v17 = environment->gravity.k[0] * es->delta_time;
      *(float *)&normalList.m_Normals.m_Memory.m_Memory[92] = v17;
      normalList.m_Normals.m_Size = v15;
      *(float *)&normalList.m_Normals.m_pElements = v16;
      if ( !v10 )
      {
        v18 = physical_core[4].rows[1].k[1] - *(float *)&v15;
        v19 = physical_core[4].rows[1].k[2] - v16;
        physical_core[4].rows[1].k[0] = physical_core[4].rows[1].k[0] - v17;
        physical_core[4].rows[1].k[1] = v18;
        physical_core[4].rows[1].k[2] = v19;
      }
      m_secondsToArrival = this->m_secondsToArrival;
      z = 1.0;
      normal.z = 1.0;
      if ( m_secondsToArrival > 0.0 )
      {
        normal.z = es->delta_time / m_secondsToArrival;
        z = normal.z;
        if ( normal.z > 1.0 )
        {
          z = 1.0;
          normal.z = 1.0;
        }
      }
      if ( (*((_BYTE *)this + 144) & 0xF8) != 0 )
      {
        ComputeController(
          currentSpeed: &physical_core[4].rows[1],
          delta: (const IVP_U_Float_Point *)&v61,
          maxSpeed: &this->m_maxSpeed,
          scaleDelta: z / es->delta_time,
          damping: this->m_dampFactor,
          pOutImpulse: &this->m_lastImpulse);
      }
      else
      {
        v56 = IVP_U_Float_Point::fast_real_length(this: &this->m_lastImpulse);
        damping = this->m_dampFactor;
        *(float *)&pSnapshot = v56;
        gravDt = v56;
        ComputeController(
          currentSpeed: &physical_core[4].rows[1],
          delta: (const IVP_U_Float_Point *)&v61,
          maxSpeed: (const IVP_U_Float_Point *)&v56,
          scaleDelta: normal.z / es->delta_time,
          damping,
          pOutImpulse: nullptr);
      }
      v24 = v23[2] + *((float *)&v53 + 1);
      v25 = *v23 + v52;
      v23[1] = *(float *)&v53 + v23[1];
      *v23 = v25;
      v23[2] = v24;
      *((_BYTE *)this + 144) &= 7u;
      LODWORD(v59) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * v23[1]) ^ _mask__NegFloat_;
      gravDt = v23[2] * g_PhysicsUnits.unitScaleMetersInv;
      *(float *)&pSnapshot = *v23 * g_PhysicsUnits.unitScaleMetersInv;
      FrictionSnapshot = CreateFrictionSnapshot(pObject: v60);
      hesse_val = v60->physical_core->inv_rot_inertia.hesse_val;
      v28 = *(float *)&FrictionSnapshot;
      *(_DWORD *)&normalList.m_Normals.m_Memory.m_Memory[84] = 0;
      v66 = 0;
      *(_DWORD *)&normalList.m_Normals.m_Memory.m_Memory[88] = v49;
      IsValid = FrictionSnapshot->IsValid;
      v51 = hesse_val;
      m_pushableSpeedLimit = this->m_pushableSpeedLimit;
      baseVelocity.hesse_val = v28;
      normal.z = m_pushableSpeedLimit;
      if ( IsValid(this: (IPhysicsFrictionSnapshot *)LODWORD(v28)) )
      {
        do
        {
          (*(void (__thiscall **)(float, float *))(*(_DWORD *)LODWORD(v28) + 20))(
            a1: COERCE_FLOAT(LODWORD(v28)),
            a2: &v62);
          if ( v64 < -0.69999999 )
            v66 = 1;
          if ( v64 > -0.99000001 )
          {
            v31 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(v28) + 8))(
                    a1: COERCE_FLOAT(LODWORD(v28)),
                    a2: 1);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v31 + 40))(a1: v31) == 0
              || ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v31 + 116))(a1: v31) > this->m_pushableMassLimit )
            {
              normal.z = 0.0;
            }
            v32 = *(double (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(baseVelocity.hesse_val) + 24);
            v55 = *(float *)&pSnapshot * v62 + gravDt * *(float *)&pivp + v59 * v64;
            v33 = v32(a1: LODWORD(baseVelocity.hesse_val));
            if ( v33 * v51 + v55 > normal.z && *(_DWORD *)&normalList.m_Normals.m_Memory.m_Memory[84] != 8 )
            {
              v34 = *(_DWORD *)&normalList.m_Normals.m_Memory.m_Memory[84] - 1;
              if ( *(_DWORD *)&normalList.m_Normals.m_Memory.m_Memory[84] - 1 < 0 )
              {
LABEL_30:
                CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::AddToTail(
                  this: (CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *)v49,
                  src: (const Vector *)&v62);
              }
              else
              {
                v35 = (float *)&v49[12 * v34 + 8];
                while ( (float)((float)((float)(*(v35 - 1) * *(float *)&pivp) + (float)(*(v35 - 2) * v62))
                              + (float)(*v35 * v64)) <= 0.99000001 )
                {
                  v35 -= 3;
                  if ( --v34 < 0 )
                    goto LABEL_30;
                }
              }
            }
            v28 = baseVelocity.hesse_val;
          }
          (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v28) + 48))(a1: COERCE_FLOAT(LODWORD(v28)));
        }
        while ( (*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(v28) + 4))(a1: COERCE_FLOAT(LODWORD(v28))) != 0 );
      }
      DestroyPlayerController(pSnapshot: (IPhysicsFrictionSnapshot *)LODWORD(v28));
      if ( this->IsPredicted(this) )
      {
        v36 = 200 * *((_DWORD *)this + 93) + *((_DWORD *)this + 90) - 200;
        CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::operator=(
          this: (CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *)(v36 + 84),
          other: (const CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0> > *)v49);
        v37 = normal.z;
        *(_BYTE *)(v36 + 188) = v66;
        *(float *)(v36 + 80) = v37;
      }
      CNormalList::ClampVector(
        this: (CNormalList *)v49,
        result: (Vector *)&v62,
        inVector: (const Vector *)&pSnapshot,
        limitVel: normal.z);
      v10 = v66 == 0;
      v38 = v60;
      v39 = v60->physical_core;
      LODWORD(v40) = COERCE_UNSIGNED_INT((float)(v64 - v59) * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
      v41 = (float)(v62 - *(float *)&pSnapshot) * g_PhysicsUnits.unitScaleMeters;
      v42 = (float)(*(float *)&pivp - gravDt) * g_PhysicsUnits.unitScaleMeters;
      v39->speed.k[0] = v39->speed.k[0] + v41;
      v39->speed.k[1] = v39->speed.k[1] + v40;
      v39->speed.k[2] = v39->speed.k[2] + v42;
      v43 = this->m_lastImpulse.k[0] + v41;
      v44 = this->m_lastImpulse.k[1] + v40;
      v45 = this->m_lastImpulse.k[2] + v42;
      this->m_lastImpulse.k[0] = v43;
      this->m_lastImpulse.k[1] = v44;
      this->m_lastImpulse.k[2] = v45;
      if ( !v10 )
      {
        v55 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&normalList.m_Normals.m_Memory.m_Memory[92]);
        v46 = this->m_lastImpulse.k[1];
        if ( v46 >= 0.0 )
        {
          v47 = v55 - v46;
          v38->physical_core->speed.k[1] = v38->physical_core->speed.k[1] + (float)(v55 - v46);
          this->m_lastImpulse.k[1] = this->m_lastImpulse.k[1] + v47;
        }
      }
      v48 = this->m_secondsToArrival - es->delta_time;
      this->m_secondsToArrival = v48;
      if ( v48 < 0.0 )
        this->m_secondsToArrival = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022580
// Name: public: virtual void CPredictedPlayerController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::do_simulation_controller(
        CPredictedPlayerController *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *cores)
{
  Vector *p_vSimulationGravity; // ecx
  IVP_Environment *environment; // eax
  float v6; // xmm0_4
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  CPredictedPhysicsObject::PreAnyController(
    this: (CPredictedPhysicsObject *)this->m_pObject,
    a2: (int)es,
    fSimulationTime: es->delta_time,
    bBackup: true);
  CPredictableControllerSimulationOrderTracker::RegisterSimulation(this: this->m_pCallOrderRegistrar, pController: this);
  p_vSimulationGravity = &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1].Backup_OnPredictionCommandChanged.vSimulationGravity;
  environment = es->environment;
  v6 = environment->gravity.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(p_vSimulationGravity->z) = COERCE_UNSIGNED_INT(environment->gravity.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                                   ^ _mask__NegFloat_;
  p_vSimulationGravity->y = v6;
  p_vSimulationGravity->x = environment->gravity.k[0] * g_PhysicsUnits.unitScaleMetersInv;
  CPlayerController::do_simulation_controller(this, a2: (int)&savedregs, es, __formal: cores);
  CPredictedPhysicsObject::PostAnyController(
    this: (CPredictedPhysicsObject *)this->m_pObject,
    a2: (int)es,
    a3: (int)this,
    fSimulationTime: es->delta_time,
    bBackup: true);
}

//------------------------------------------------------------------------------
// Address: 0x10022640
// Name: public: CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::BackupData_t(struct CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *__thiscall CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::BackupData_t(
        CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *this,
        const CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *__that)
{
  CNormalList *p_frictionSnapshotNormals; // ecx

  this->vTargetPosition = __that->vTargetPosition;
  this->vGroundPosition = __that->vGroundPosition;
  this->vMaxSpeed = __that->vMaxSpeed;
  this->vLastImpulse = __that->vLastImpulse;
  this->vCurrentSpeed = __that->vCurrentSpeed;
  this->vSimulationGravity = __that->vSimulationGravity;
  this->fSecondsToArrival = __that->fSecondsToArrival;
  this->pGround = __that->pGround;
  p_frictionSnapshotNormals = &this->frictionSnapshotNormals;
  this->fFrictionSnapshotLimitVel = __that->fFrictionSnapshotLimitVel;
  p_frictionSnapshotNormals->m_Normals.m_Size = 0;
  p_frictionSnapshotNormals->m_Normals.m_pElements = (Vector *)p_frictionSnapshotNormals;
  CUtlVector<Vector,CUtlMemoryFixed<Vector,8,0>>::operator=(
    this: &p_frictionSnapshotNormals->m_Normals,
    other: &__that->frictionSnapshotNormals.m_Normals);
  this->bFrictionSnapshotGround = __that->bFrictionSnapshotGround;
  this->bUpdatedSinceLast = __that->bUpdatedSinceLast;
  this->bForceTeleport = __that->bForceTeleport;
  this->bEnable = __that->bEnable;
  this->bOnGround = __that->bOnGround;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100227B0
// Name: public: void CPredictedPlayerController::OnPredictionCommandChanged(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::OnPredictionCommandChanged(
        CPredictedPlayerController *this,
        int iCommandNum,
        bool bBackup)
{
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pReferencedBackup; // eax
  bool v5; // al
  float y; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  bool bUpdatedSinceLast; // cl
  unsigned __int8 v12; // al
  float v13; // xmm2_4
  float v14; // xmm1_4
  int v15; // eax
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *m_pMemory; // edx
  CPredictedPlayerController::PlayerControllerPredictionBackups_t *v17; // edi
  CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *v18; // ecx
  CPredictedPlayerController::PlayerControllerPredictionBackups_t temp; // [esp+4h] [ebp-C8h] BYREF

  if ( bBackup )
  {
    m_pReferencedBackup = (CPredictedPlayerController::PlayerControllerPredictionBackups_t *)this->m_pReferencedBackup;
    v5 = m_pReferencedBackup != nullptr
      && m_pReferencedBackup == &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1];
    this->m_pReferencedBackup = nullptr;
    temp.Backup_OnPredictionCommandChanged.frictionSnapshotNormals.m_Normals.m_Size = 0;
    temp.Backup_OnPredictionCommandChanged.frictionSnapshotNormals.m_Normals.m_pElements = (Vector *)&temp.Backup_OnPredictionCommandChanged.frictionSnapshotNormals;
    temp.iCommandNum = iCommandNum;
    if ( v5 )
    {
      y = this->m_ActiveBackup.vTargetPosition.y;
      this->m_targetPosition.k[0] = this->m_ActiveBackup.vTargetPosition.x * g_PhysicsUnits.unitScaleMeters;
      this->m_targetPosition.k[1] = -(float)(this->m_ActiveBackup.vTargetPosition.z * g_PhysicsUnits.unitScaleMeters);
      this->m_targetPosition.k[2] = y * g_PhysicsUnits.unitScaleMeters;
      v7 = this->m_ActiveBackup.vGroundPosition.y;
      this->m_groundPosition.k[0] = this->m_ActiveBackup.vGroundPosition.x * g_PhysicsUnits.unitScaleMeters;
      this->m_groundPosition.k[1] = -(float)(this->m_ActiveBackup.vGroundPosition.z * g_PhysicsUnits.unitScaleMeters);
      this->m_groundPosition.k[2] = v7 * g_PhysicsUnits.unitScaleMeters;
      v8 = this->m_ActiveBackup.vMaxSpeed.y;
      this->m_maxSpeed.k[0] = this->m_ActiveBackup.vMaxSpeed.x * g_PhysicsUnits.unitScaleMeters;
      this->m_maxSpeed.k[1] = -(float)(this->m_ActiveBackup.vMaxSpeed.z * g_PhysicsUnits.unitScaleMeters);
      this->m_maxSpeed.k[2] = v8 * g_PhysicsUnits.unitScaleMeters;
      v9 = this->m_ActiveBackup.vLastImpulse.y;
      this->m_lastImpulse.k[0] = this->m_ActiveBackup.vLastImpulse.x * g_PhysicsUnits.unitScaleMeters;
      this->m_lastImpulse.k[1] = -(float)(this->m_ActiveBackup.vLastImpulse.z * g_PhysicsUnits.unitScaleMeters);
      this->m_lastImpulse.k[2] = v9 * g_PhysicsUnits.unitScaleMeters;
      v10 = this->m_ActiveBackup.vCurrentSpeed.y;
      this->m_currentSpeed.k[0] = this->m_ActiveBackup.vCurrentSpeed.x * g_PhysicsUnits.unitScaleMeters;
      this->m_currentSpeed.k[1] = -(float)(this->m_ActiveBackup.vCurrentSpeed.z * g_PhysicsUnits.unitScaleMeters);
      this->m_currentSpeed.k[2] = v10 * g_PhysicsUnits.unitScaleMeters;
      bUpdatedSinceLast = this->m_ActiveBackup.bUpdatedSinceLast;
      this->m_secondsToArrival = this->m_ActiveBackup.fSecondsToArrival;
      *((_BYTE *)&this->CPlayerController + 144) = this->m_ActiveBackup.bEnable
                                                 | (2
                                                  * (this->m_ActiveBackup.bOnGround
                                                   | (2 * ((2 * bUpdatedSinceLast) | this->m_ActiveBackup.bForceTeleport))));
      CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::operator=(
        this: &temp.Backup_OnPredictionCommandChanged,
        __that: &this->m_ActiveBackup);
    }
    else
    {
      temp.Backup_OnPredictionCommandChanged.vTargetPosition.z = -(float)(this->m_targetPosition.k[1]
                                                                        * g_PhysicsUnits.unitScaleMetersInv);
      temp.Backup_OnPredictionCommandChanged.vTargetPosition.y = this->m_targetPosition.k[2]
                                                               * g_PhysicsUnits.unitScaleMetersInv;
      temp.Backup_OnPredictionCommandChanged.vTargetPosition.x = g_PhysicsUnits.unitScaleMetersInv
                                                               * this->m_targetPosition.k[0];
      temp.Backup_OnPredictionCommandChanged.vGroundPosition.z = -(float)(this->m_groundPosition.k[1]
                                                                        * g_PhysicsUnits.unitScaleMetersInv);
      temp.Backup_OnPredictionCommandChanged.vGroundPosition.y = this->m_groundPosition.k[2]
                                                               * g_PhysicsUnits.unitScaleMetersInv;
      v12 = *((_BYTE *)&this->CPlayerController + 144);
      temp.Backup_OnPredictionCommandChanged.vGroundPosition.x = g_PhysicsUnits.unitScaleMetersInv
                                                               * this->m_groundPosition.k[0];
      temp.Backup_OnPredictionCommandChanged.vMaxSpeed.z = -(float)(this->m_maxSpeed.k[1]
                                                                  * g_PhysicsUnits.unitScaleMetersInv);
      temp.Backup_OnPredictionCommandChanged.vMaxSpeed.y = this->m_maxSpeed.k[2] * g_PhysicsUnits.unitScaleMetersInv;
      temp.Backup_OnPredictionCommandChanged.vMaxSpeed.x = g_PhysicsUnits.unitScaleMetersInv * this->m_maxSpeed.k[0];
      temp.Backup_OnPredictionCommandChanged.vLastImpulse.z = -(float)(this->m_lastImpulse.k[1]
                                                                     * g_PhysicsUnits.unitScaleMetersInv);
      temp.Backup_OnPredictionCommandChanged.vLastImpulse.y = this->m_lastImpulse.k[2]
                                                            * g_PhysicsUnits.unitScaleMetersInv;
      temp.Backup_OnPredictionCommandChanged.vLastImpulse.x = g_PhysicsUnits.unitScaleMetersInv
                                                            * this->m_lastImpulse.k[0];
      v13 = this->m_currentSpeed.k[1];
      v14 = this->m_currentSpeed.k[2] * g_PhysicsUnits.unitScaleMetersInv;
      temp.Backup_OnPredictionCommandChanged.vCurrentSpeed.x = g_PhysicsUnits.unitScaleMetersInv
                                                             * this->m_currentSpeed.k[0];
      temp.Backup_OnPredictionCommandChanged.fSecondsToArrival = this->m_secondsToArrival;
      temp.Backup_OnPredictionCommandChanged.bUpdatedSinceLast = v12 >> 3;
      temp.Backup_OnPredictionCommandChanged.vSimulationGravity = vec3_origin;
      temp.Backup_OnPredictionCommandChanged.vCurrentSpeed.z = -(float)(v13 * g_PhysicsUnits.unitScaleMetersInv);
      temp.Backup_OnPredictionCommandChanged.vCurrentSpeed.y = v14;
      temp.Backup_OnPredictionCommandChanged.bForceTeleport = (v12 & 4) != 0;
      temp.Backup_OnPredictionCommandChanged.bEnable = v12 & 1;
      temp.Backup_OnPredictionCommandChanged.bOnGround = (v12 & 2) != 0;
    }
    temp.Backup_OnPredictionCommandChanged.pGround = this->m_pGround;
    CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::InsertBefore(
      this: &this->m_PredictionBackups,
      elem: this->m_PredictionBackups.m_Size,
      src: &temp);
  }
  else
  {
    v15 = this->m_PredictionBackups.m_Size - 1;
    if ( v15 < 0 )
    {
LABEL_14:
      CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::operator=(
        this: &this->m_ActiveBackup,
        __that: &this->m_PredictionBackups.m_Memory.m_pMemory->Backup_OnPredictionCommandChanged);
      this->m_pReferencedBackup = &this->m_ActiveBackup;
    }
    else
    {
      m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
      v17 = &m_pMemory[v15];
      while ( v17->iCommandNum > iCommandNum )
      {
        --v17;
        if ( --v15 < 0 )
          goto LABEL_14;
      }
      v18 = this->m_pReferencedBackup;
      if ( v18 != nullptr
        && v15 > 0
        && v18 == (CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t *)&m_pMemory[v15 - 1] )
      {
        v17->Backup_OnPredictionCommandChanged.vTargetPosition.x = this->m_ActiveBackup.vTargetPosition.x;
        v17->Backup_OnPredictionCommandChanged.vTargetPosition.y = this->m_ActiveBackup.vTargetPosition.y;
        v17->Backup_OnPredictionCommandChanged.vTargetPosition.z = this->m_ActiveBackup.vTargetPosition.z;
        v17->Backup_OnPredictionCommandChanged.vGroundPosition.x = this->m_ActiveBackup.vGroundPosition.x;
        v17->Backup_OnPredictionCommandChanged.vGroundPosition.y = this->m_ActiveBackup.vGroundPosition.y;
        v17->Backup_OnPredictionCommandChanged.vGroundPosition.z = this->m_ActiveBackup.vGroundPosition.z;
        v17->Backup_OnPredictionCommandChanged.vMaxSpeed.x = this->m_ActiveBackup.vMaxSpeed.x;
        v17->Backup_OnPredictionCommandChanged.vMaxSpeed.y = this->m_ActiveBackup.vMaxSpeed.y;
        v17->Backup_OnPredictionCommandChanged.vMaxSpeed.z = this->m_ActiveBackup.vMaxSpeed.z;
        v17->Backup_OnPredictionCommandChanged.vLastImpulse.x = this->m_ActiveBackup.vLastImpulse.x;
        v17->Backup_OnPredictionCommandChanged.vLastImpulse.y = this->m_ActiveBackup.vLastImpulse.y;
        v17->Backup_OnPredictionCommandChanged.vLastImpulse.z = this->m_ActiveBackup.vLastImpulse.z;
        v17->Backup_OnPredictionCommandChanged.vCurrentSpeed.x = this->m_ActiveBackup.vCurrentSpeed.x;
        v17->Backup_OnPredictionCommandChanged.vCurrentSpeed.y = this->m_ActiveBackup.vCurrentSpeed.y;
        v17->Backup_OnPredictionCommandChanged.vCurrentSpeed.z = this->m_ActiveBackup.vCurrentSpeed.z;
        v17->Backup_OnPredictionCommandChanged.fSecondsToArrival = this->m_ActiveBackup.fSecondsToArrival;
        v17->Backup_OnPredictionCommandChanged.pGround = this->m_ActiveBackup.pGround;
        v17->Backup_OnPredictionCommandChanged.bUpdatedSinceLast = this->m_ActiveBackup.bUpdatedSinceLast;
        v17->Backup_OnPredictionCommandChanged.bForceTeleport = this->m_ActiveBackup.bForceTeleport;
        v17->Backup_OnPredictionCommandChanged.bEnable = this->m_ActiveBackup.bEnable;
        v17->Backup_OnPredictionCommandChanged.bOnGround = this->m_ActiveBackup.bOnGround;
        this->m_pReferencedBackup = &v17->Backup_OnPredictionCommandChanged;
      }
      else
      {
        CPredictedPlayerController::PlayerControllerPredictionBackups_t::BackupData_t::operator=(
          this: &this->m_ActiveBackup,
          __that: &v17->Backup_OnPredictionCommandChanged);
        this->m_pReferencedBackup = &v17->Backup_OnPredictionCommandChanged;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022CD0
// Name: public: CPredictedPlayerController::CPredictedPlayerController(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
CPredictedPlayerController *__userpurge CPredictedPlayerController::CPredictedPlayerController@<eax>(
        CPredictedPlayerController *this@<ecx>,
        int a2@<edi>,
        CPhysicsObject *pObject)
{
  CPlayerController::CPlayerController(this, a2, pObject);
  this->CPlayerController::IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPredictedPlayerController_vtbl *)&CPredictedPlayerController::`vftable'{for `IPredictable_Controller_Independant'};
  this->CPlayerController::IPhysicsPlayerController::__vftable = (IPhysicsPlayerController_vtbl *)&CPredictedPlayerController::`vftable'{for `IPhysicsPlayerController'};
  this->CPlayerController::IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPredictedPlayerController::`vftable'{for `IVP_Listener_Object'};
  this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_Size = 0;
  this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_pElements = (Vector *)&this->m_ActiveBackup.frictionSnapshotNormals;
  this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
  this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  this->m_PredictionBackups.m_Memory.m_nGrowSize = 0;
  this->m_PredictionBackups.m_Size = 0;
  this->m_PredictionBackups.m_pElements = nullptr;
  this->m_pReferencedBackup = nullptr;
  this->m_pCallOrderRegistrar = nullptr;
  CPredictedPlayerController::OnPredictionCommandChanged(this, iCommandNum: -1, bBackup: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10022D60
// Name: public: virtual CPredictedPlayerController::~CPredictedPlayerController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPlayerController::~CPredictedPlayerController(CPredictedPlayerController *this)
{
  CUtlVector<CPredictedPlayerController::PlayerControllerPredictionBackups_t,CUtlMemory<CPredictedPlayerController::PlayerControllerPredictionBackups_t,int>>::Purge(this: &this->m_PredictionBackups);
  if ( this->m_PredictionBackups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PredictionBackups.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PredictionBackups.m_Memory.m_pMemory);
      this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_Size = 0;
  this->m_ActiveBackup.frictionSnapshotNormals.m_Normals.m_pElements = (Vector *)&this->m_ActiveBackup.frictionSnapshotNormals;
  this->CPlayerController::IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPredictedPlayerController_vtbl *)&CPlayerController::`vftable'{for `IPredictable_Controller_Independant'};
  this->CPlayerController::IPhysicsPlayerController::__vftable = (IPhysicsPlayerController_vtbl *)&CPlayerController::`vftable'{for `IPhysicsPlayerController'};
  this->CPlayerController::IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPlayerController::`vftable'{for `IVP_Listener_Object'};
  CPlayerController::DetachObject(this);
  this->CPlayerController::IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->CPlayerController::IPhysicsPlayerController::__vftable = (IPhysicsPlayerController_vtbl *)&IPhysicsPlayerController::`vftable';
  this->CPlayerController::IPredictable_Controller_Independant::IVP_Controller_Independent::IVP_Controller::__vftable = (CPredictedPlayerController_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10022E20
// Name: class IPhysicsPlayerController __near * CreatePlayerController(class CPhysicsObject __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsPlayerController *__usercall CreatePlayerController@<eax>(
        int a1@<edi>,
        CPhysicsObject *pObject,
        bool bPredicted)
{
  CPredictedPlayerController *v3; // eax
  CPredictedPlayerController *v4; // eax
  CPlayerController *v5; // eax

  if ( bPredicted )
  {
    v3 = (CPredictedPlayerController *)p_malloc(size: 0x180u);
    if ( v3 == nullptr )
      return nullptr;
    v4 = CPredictedPlayerController::CPredictedPlayerController(this: v3, a2: a1, pObject);
  }
  else
  {
    v5 = (CPlayerController *)p_malloc(size: 0xA0u);
    if ( v5 == nullptr )
      return nullptr;
    v4 = (CPredictedPlayerController *)CPlayerController::CPlayerController(this: v5, a2: a1, pObject);
  }
  if ( v4 != nullptr )
    return &v4->IPhysicsPlayerController;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100C6AD0
// Name: vphysics_save_shadowcontrolparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_shadowcontrolparams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_shadowcontrolparams_t>();
  vphysics_save_shadowcontrolparams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6AE0
// Name: vphysics_save_cshadowcontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cshadowcontroller_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cshadowcontroller_t>();
  vphysics_save_cshadowcontroller_t_DataDescInit::g_DataMapHolder = result;
  return result;
}
