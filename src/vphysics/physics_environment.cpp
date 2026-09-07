// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_environment.cpp
// Functions: 155
// ============================================================

#include "vphysics\physics_environment.h"

//------------------------------------------------------------------------------
// Address: 0x100050E0
// Name: public: virtual void CEmptyCollisionListener::StartTouch(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyCollisionListener::StartTouch(CPhysics_Airboat *this, float thrust, float duration, float delay)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6B0
// Name: class IVP_Real_Object __near * GetOppositeSynapseObject(class IVP_Synapse_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Real_Object *__cdecl GetOppositeSynapseObject(IVP_Synapse_Friction *pfriction)
{
  int contact_point_offset; // eax

  contact_point_offset = pfriction->contact_point_offset;
  if ( (IVP_Synapse_Friction *)((char *)&pfriction->l_obj + contact_point_offset) == pfriction )
    return *(IVP_Real_Object **)((char *)&pfriction[1].edge + contact_point_offset);
  else
    return *(IVP_Real_Object **)((char *)&pfriction->edge + contact_point_offset);
}

//------------------------------------------------------------------------------
// Address: 0x1000F6D0
// Name: private: static bool CPhysicsListenerCollision::CorePairLessFunc(struct CPhysicsListenerCollision::corepair_t const __near &,struct CPhysicsListenerCollision::corepair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CPhysicsListenerCollision::CorePairLessFunc(
        const CPhysicsListenerCollision::corepair_t *lhs,
        const CPhysicsListenerCollision::corepair_t *rhs)
{
  bool v2; // cf

  v2 = lhs->core0 < rhs->core0;
  if ( lhs->core0 == rhs->core0 )
    return lhs->core1 < rhs->core1;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000F720
// Name: public: class IPhysicsCollisionEvent __near * CPhysicsEnvironment::GetCollisionEventHandler(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsCollisionEvent *__thiscall CPhysicsEnvironment::GetCollisionEventHandler(CPhysicsEnvironment *this)
{
  return this->m_pCollisionListener->m_pCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1000F730
// Name: public: void CPhysicsEnvironment::NotifyConstraintDisabled(class IPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::NotifyConstraintDisabled(
        CPhysicsEnvironment *this,
        IPhysicsConstraint *pConstraint)
{
  CPhysicsListenerConstraint *m_pConstraintListener; // eax

  if ( this->m_enableConstraintNotify )
  {
    m_pConstraintListener = this->m_pConstraintListener;
    if ( m_pConstraintListener->m_pCallback != nullptr )
      m_pConstraintListener->m_pCallback->ConstraintBroken(this: m_pConstraintListener->m_pCallback, a2: pConstraint);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F760
// Name: public: virtual void CPhysicsEnvironment::SetDebugOverlay(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetDebugOverlay(
        CPhysicsEnvironment *this,
        void *(__cdecl *debugOverlayFactory)(const char *, int *))
{
  this->m_pDebugOverlay = nullptr;
  if ( debugOverlayFactory != nullptr )
    this->m_pDebugOverlay = (IVPhysicsDebugOverlay *)debugOverlayFactory(a1: "VPhysicsDebugOverlay001", a2: nullptr);
  if ( this->m_pDebugOverlay == nullptr )
    this->m_pDebugOverlay = &s_DefaultDebugOverlay;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7A0
// Name: public: virtual unsigned int CPhysicsEnvironment::GetObjectSerializeSize(class IPhysicsObject __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysicsEnvironment::GetObjectSerializeSize(CPhysicsEnvironment *this, IPhysicsObject *pObject)
{
  return 148;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7B0
// Name: public: virtual void CPhysicsEnvironment::SerializeObjectToBuffer(class IPhysicsObject __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SerializeObjectToBuffer(
        CPhysicsEnvironment *this,
        CPhysicsObject *pObject,
        unsigned __int8 *pBuffer,
        unsigned int bufferSize)
{
  if ( bufferSize >= 0x94 )
    CPhysicsObject::WriteToTemplate(this: pObject, objectTemplate: (vphysics_save_cphysicsobject_t *)pBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1000F7D0
// Name: public: virtual class IPhysicsSpring __near * CPhysicsEnvironment::CreateSpring(class IPhysicsObject __near *,class IPhysicsObject __near *,struct springparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsSpring *__thiscall CPhysicsEnvironment::CreateSpring(
        CPhysicsEnvironment *this,
        CPhysicsObject *pObjectStart,
        CPhysicsObject *pObjectEnd,
        springparams_t *pParams)
{
  return CreateSpring(pEnvironment: this->m_pPhysEnv, pObjectStart, pObjectEnd, pParams);
}

//------------------------------------------------------------------------------
// Address: 0x1000F7F0
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateRagdollConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_ragdollparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateRagdollConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_ragdollparams_t *ragdoll)
{
  return CreateRagdollConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, ragdoll);
}

//------------------------------------------------------------------------------
// Address: 0x1000F820
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateLimitedHingeConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_limitedhingeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateLimitedHingeConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_limitedhingeparams_t *hinge)
{
  return CreateHingeConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, hinge);
}

//------------------------------------------------------------------------------
// Address: 0x1000F850
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateFixedConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_fixedparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateFixedConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_fixedparams_t *fixed)
{
  return CreateFixedConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, fixed);
}

//------------------------------------------------------------------------------
// Address: 0x1000F880
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateSlidingConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_slidingparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateSlidingConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_slidingparams_t *sliding)
{
  return CreateSlidingConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, sliding);
}

//------------------------------------------------------------------------------
// Address: 0x1000F8B0
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateBallsocketConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_ballsocketparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateBallsocketConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_ballsocketparams_t *ballsocket)
{
  return CreateBallsocketConstraint(
           pEnvironment: this->m_pPhysEnv,
           pReferenceObject,
           pAttachedObject,
           pGroup,
           ballsocket);
}

//------------------------------------------------------------------------------
// Address: 0x1000F8E0
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreatePulleyConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_pulleyparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreatePulleyConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_pulleyparams_t *pulley)
{
  return CreatePulleyConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, pulley);
}

//------------------------------------------------------------------------------
// Address: 0x1000F910
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateLengthConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_lengthparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateLengthConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_lengthparams_t *length)
{
  return CreateLengthConstraint(pEnvironment: this->m_pPhysEnv, pReferenceObject, pAttachedObject, pGroup, length);
}

//------------------------------------------------------------------------------
// Address: 0x1000F940
// Name: public: virtual class IPhysicsConstraintGroup __near * CPhysicsEnvironment::CreateConstraintGroup(struct constraint_groupparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraintGroup *__thiscall CPhysicsEnvironment::CreateConstraintGroup(
        CPhysicsEnvironment *this,
        const constraint_groupparams_t *group)
{
  return CreatePhysicsConstraintGroup(pEnvironment: this->m_pPhysEnv, group);
}

//------------------------------------------------------------------------------
// Address: 0x1000F960
// Name: public: virtual void CPhysicsEnvironment::SetSimulationTimestep(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetSimulationTimestep(CPhysicsEnvironment *this, float timestep)
{
  IVP_Environment::set_delta_PSI_time(this: this->m_pPhysEnv, psi_time: timestep);
}

//------------------------------------------------------------------------------
// Address: 0x1000F980
// Name: public: virtual bool CPhysicsEnvironment::IsInSimulation(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsEnvironment::IsInSimulation(CPhysicsEnvironment *this)
{
  return this->m_inSimulation;
}

//------------------------------------------------------------------------------
// Address: 0x1000F990
// Name: public: virtual void CEmptyCollisionListener::Friction(class IPhysicsObject __near *,float,int,int,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyCollisionListener::Friction(
        CEmptyCollisionListener *this,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit,
        IPhysicsCollisionData *pData)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000F9A0
// Name: public: virtual void CPhysicsEnvironment::SetCollisionSolver(class IPhysicsCollisionSolver __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetCollisionSolver(CPhysicsEnvironment *this, IPhysicsCollisionSolver *pSolver)
{
  this->m_pCollisionSolver->m_pSolver = pSolver;
}

//------------------------------------------------------------------------------
// Address: 0x1000F9C0
// Name: public: virtual void CPhysicsEnvironment::SetCollisionEventHandler(class IPhysicsCollisionEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetCollisionEventHandler(
        CPhysicsEnvironment *this,
        IPhysicsCollisionEvent *pCollisionEvents)
{
  this->m_pCollisionListener->m_pCallback = pCollisionEvents;
}

//------------------------------------------------------------------------------
// Address: 0x1000F9E0
// Name: public: virtual void CPhysicsEnvironment::SetObjectEventHandler(class IPhysicsObjectEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetObjectEventHandler(
        CPhysicsEnvironment *this,
        IPhysicsObjectEvent *pObjectEvents)
{
  this->m_pSleepEvents->m_pCallback = pObjectEvents;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA00
// Name: public: virtual void CPhysicsEnvironment::SetConstraintEventHandler(class IPhysicsConstraintEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetConstraintEventHandler(
        CPhysicsEnvironment *this,
        IPhysicsConstraintEvent *pConstraintEvents)
{
  this->m_pConstraintListener->m_pCallback = pConstraintEvents;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA20
// Name: public: virtual class IPhysicsShadowController __near * CPhysicsEnvironment::CreateShadowController(class IPhysicsObject __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsShadowController *__thiscall CPhysicsEnvironment::CreateShadowController(
        CPhysicsEnvironment *this,
        CPhysicsObject *pObject,
        bool allowTranslation,
        bool allowRotation)
{
  CShadowController *ShadowController; // eax

  ShadowController = CreateShadowController(pObject, allowTranslation, allowRotation);
  if ( ShadowController != nullptr )
    return &ShadowController->IPhysicsShadowController;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA50
// Name: public: virtual void CPhysicsEnvironment::DestroySpring(class IPhysicsSpring __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroySpring(CPhysicsInterface *this, IPhysicsObjectPairHash *pHash)
{
  if ( pHash != nullptr )
    ((void (__thiscall *)(IPhysicsObjectPairHash *, int))pHash->dtr_IPhysicsObjectPairHash)(a1: pHash, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA70
// Name: public: virtual class IPhysicsVehicleController __near * CPhysicsEnvironment::CreateVehicleController(class IPhysicsObject __near *,struct vehicleparams_t const __near &,unsigned int,class IPhysicsGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsVehicleController *__thiscall CPhysicsEnvironment::CreateVehicleController(
        CPhysicsEnvironment *this,
        CPhysicsObject *pVehicleBodyObject,
        const vehicleparams_t *params,
        unsigned int nVehicleType,
        IPhysicsGameTrace *pGameTrace)
{
  return CreateVehicleController(pEnv: this, pBodyObject: pVehicleBodyObject, params, nVehicleType, pGameTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1000FA90
// Name: public: virtual void CPhysicsEnvironment::SetAirDensity(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetAirDensity(CPhysicsEnvironment *this, IVP_Controller_vtbl *density)
{
  IVP_Controller *m_pDragController; // eax

  m_pDragController = this->m_pDragController;
  if ( m_pDragController != nullptr )
    m_pDragController[1].__vftable = density;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAB0
// Name: public: virtual float CPhysicsEnvironment::GetAirDensity(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsEnvironment::GetAirDensity(CPhysicsEnvironment *this)
{
  IVP_Controller *m_pDragController; // eax

  m_pDragController = this->m_pDragController;
  if ( m_pDragController != nullptr )
    return *(float *)&m_pDragController[1].__vftable;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAC0
// Name: public: virtual void CPhysicsEnvironment::TraceRay(struct Ray_t const __near &,unsigned int,class IPhysicsTraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::TraceRay(
        CPhysicsEnvironment *this,
        const Ray_t *ray,
        const Ray_t *fMask,
        IPhysicsTraceFilter *pTraceFilter,
        IPhysicsTraceFilter *pTrace)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAD0
// Name: public: virtual void CPhysicsEnvironment::EnableConstraintNotify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::EnableConstraintNotify(CPhysicsEnvironment *this, bool bEnable)
{
  this->m_enableConstraintNotify = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAE0
// Name: public: virtual bool CPhysicsEnvironment::IsPredicted(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsEnvironment::IsPredicted(CPhysicsEnvironment *this)
{
  return this->m_bPredicted;
}

//------------------------------------------------------------------------------
// Address: 0x1000FAF0
// Name: public: virtual int CPhysicsEnvironment::GetPredictionCommandNum(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsEnvironment::GetPredictionCommandNum(CPhysicsEnvironment *this)
{
  return this->m_iPredictionCommandNum;
}

//------------------------------------------------------------------------------
// Address: 0x1000FB60
// Name: public: virtual void CPhysicsEnvironment::SetQuickDelete(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetQuickDelete(CPhysicsEnvironment *this, bool bQuick)
{
  this->m_deleteQuick = bQuick;
}

//------------------------------------------------------------------------------
// Address: 0x1000FB70
// Name: public: virtual void CPhysicsFrictionData::GetSurfaceNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsFrictionData::GetSurfaceNormal(CPhysicsFrictionData *this@<ecx>, float a2@<ebp>, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v5; // xmm0_4
  float m_sign; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  _DWORD v9[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point normal; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  normal.k[1] = a2;
  normal.k[2] = retaddr;
  m_pContact = this->m_pContact;
  if ( m_pContact != nullptr )
  {
    v5 = m_pContact->surf_normal.k[2];
    LODWORD(out->z) = LODWORD(m_pContact->surf_normal.k[1]) ^ _mask__NegFloat_;
    out->y = v5;
    out->x = m_pContact->surf_normal.k[0];
  }
  else
  {
    IVP_Contact_Point_API::get_surface_normal_ws(
      friction_handle: (IVP_Contact_Point *)this->m_pPoint,
      pOut: (IVP_U_Float_Point *)v9);
    LODWORD(out->z) = v9[1] ^ _mask__NegFloat_;
    LODWORD(out->y) = v9[2];
    LODWORD(out->x) = v9[0];
    m_sign = this->m_sign;
    out->x = out->x * m_sign;
    v7 = out->y * m_sign;
    v8 = m_sign * out->z;
    out->y = v7;
    out->z = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FC30
// Name: public: virtual void CPhysicsFrictionData::GetContactPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsFrictionData::GetContactPoint(CPhysicsFrictionData *this, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v3; // xmm0_4
  Vector *v4; // ecx
  float v5; // xmm0_4
  const IVP_Contact_Point *m_pPoint; // eax
  float v7; // xmm0_4

  m_pContact = this->m_pContact;
  if ( m_pContact != nullptr )
  {
    v3 = m_pContact->contact_point_ws.k[2] * g_PhysicsUnits.unitScaleMetersInv;
    v4 = out;
    LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pContact->contact_point_ws.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                    ^ _mask__NegFloat_;
    out->y = v3;
    v5 = m_pContact->contact_point_ws.k[0];
  }
  else
  {
    m_pPoint = this->m_pPoint;
    v7 = m_pPoint->last_contact_point_ws.k[2] * g_PhysicsUnits.unitScaleMetersInv;
    v4 = out;
    LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pPoint->last_contact_point_ws.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                    ^ _mask__NegFloat_;
    out->y = v7;
    v5 = m_pPoint->last_contact_point_ws.k[0];
  }
  v4->x = v5 * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x1000FCD0
// Name: public: virtual void CPhysicsFrictionData::GetContactSpeed(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsFrictionData::GetContactSpeed(CPhysicsFrictionData *this, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v3; // xmm0_4

  m_pContact = this->m_pContact;
  if ( m_pContact != nullptr )
  {
    v3 = m_pContact->speed.k[2] * g_PhysicsUnits.unitScaleMetersInv;
    LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pContact->speed.k[1] * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
    out->y = v3;
    out->x = m_pContact->speed.k[0] * g_PhysicsUnits.unitScaleMetersInv;
  }
  else
  {
    out->x = 0.0;
    out->y = 0.0;
    out->z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FD40
// Name: public: void CSleepObjects::DebugCheckContacts(class IVP_Environment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::DebugCheckContacts(CSleepObjects *this, IVP_Environment *pEnvironment)
{
  IVP_Mindist *i; // esi
  IVP_Real_Object *obj[2]; // [esp+8h] [ebp-8h] BYREF

  for ( i = pEnvironment->mindist_manager->exact_mindists; i != nullptr; i = i->next )
  {
    i->get_objects(this: i, a2: obj);
    if ( pEnvironment->collision_filter->check_objects_for_collision_detection(
           this: pEnvironment->collision_filter,
           a2: obj[0],
           a3: obj[1]) == IVP_FALSE )
      _Msg(a1: "Changed collision rules for %s vs. %s without calling recheck!\n", obj[0]->name, obj[1]->name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FDB0
// Name: public: virtual void CPhysicsListenerCollision::mindist_left_volume(class IVP_Controller_Phantom __near *,class IVP_Mindist_Base __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::mindist_left_volume(
        IVP_Listener_Hull *this,
        float __formal,
        float __formala)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FDC0
// Name: public: virtual void CPhysicsListenerConstraint::event_constraint_broken(class hk_Breakable_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerConstraint::event_constraint_broken(
        CPhysicsListenerConstraint *this,
        hk_Breakable_Constraint *pConstraint)
{
  IPhysicsConstraint *ClientDataForHkConstraint; // eax

  if ( this->m_pCallback != nullptr )
  {
    ClientDataForHkConstraint = GetClientDataForHkConstraint(pHkConstraint: pConstraint);
    this->m_pCallback->ConstraintBroken(this: this->m_pCallback, a2: ClientDataForHkConstraint);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FDF0
// Name: public: virtual void CVPhysicsDebugOverlay::AddTriangleOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,int,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsDebugOverlay::AddTriangleOverlay(
        CVPhysicsDebugOverlay *this,
        const Vector *p1,
        const Vector *p2,
        const Vector *p3,
        const Vector *r,
        const QAngle *g,
        int b,
        int a,
        bool noDepthTest,
        float duration)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE00
// Name: public: virtual void CPhysicsEnvironment::SweepCollideable(class CPhysCollide const __near *,class Vector const __near &,class Vector const __near &,class QAngle const __near &,unsigned int,class IPhysicsTraceFilter __near *,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SweepCollideable(
        CVPhysicsDebugOverlay *this,
        const Vector *origin,
        const Vector *dest,
        const Vector *r,
        int g,
        int b,
        bool noDepthTest,
        float duration)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE10
// Name: public: virtual void CVPhysicsDebugOverlay::AddScreenTextOverlay(float,float,float,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsDebugOverlay::AddScreenTextOverlay(
        CVPhysicsDebugOverlay *this,
        float flXPos,
        float flYPos,
        float flDuration,
        int r,
        int g,
        int b,
        int a,
        const char *text)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE20
// Name: public: virtual void CVPhysicsDebugOverlay::AddSweptBoxOverlay(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,class QAngle const __near &,int,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVPhysicsDebugOverlay::AddSweptBoxOverlay(
        CVPhysicsDebugOverlay *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *max,
        const Vector *angles,
        const QAngle *r,
        int g,
        int b,
        int a,
        float flDuration)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE30
// Name: public: virtual void CPhysicsEnvironment::DebugCheckContacts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DebugCheckContacts(CPhysicsEnvironment *this)
{
  CSleepObjects *m_pSleepEvents; // ecx

  m_pSleepEvents = this->m_pSleepEvents;
  if ( m_pSleepEvents != nullptr )
    CSleepObjects::DebugCheckContacts(this: m_pSleepEvents, pEnvironment: this->m_pPhysEnv);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE50
// Name: public: virtual void CPhysicsEnvironment::SetGravity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsEnvironment::SetGravity(
        CPhysicsEnvironment *this@<ecx>,
        float a2@<ebp>,
        const Vector *gravityVector)
{
  IVP_Environment *m_pPhysEnv; // ecx
  float v4; // xmm0_4
  IVP_Standard_Gravity_Controller *standard_gravity_controller; // edi
  float v6; // xmm0_4
  double global_collision_tolerance; // st7
  float tolerance; // [esp+8h] [ebp-44h]
  float tolerance_4; // [esp+Ch] [ebp-40h]
  float v10[3]; // [esp+30h] [ebp-1Ch] BYREF
  IVP_U_Point gravity; // [esp+3Ch] [ebp-10h]
  float retaddr; // [esp+4Ch] [ebp+0h]

  gravity.k[1] = a2;
  gravity.k[2] = retaddr;
  m_pPhysEnv = this->m_pPhysEnv;
  v10[0] = gravityVector->x * g_PhysicsUnits.unitScaleMeters;
  v4 = g_PhysicsUnits.unitScaleMeters * gravityVector->y;
  LODWORD(v10[1]) = COERCE_UNSIGNED_INT(gravityVector->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v10[2] = v4;
  standard_gravity_controller = m_pPhysEnv->standard_gravity_controller;
  IVP_Environment::set_gravity(this: m_pPhysEnv, gravity_: (IVP_U_Point *)v10);
  if ( IVP_U_Float_Point::fast_real_length(this: &standard_gravity_controller->alt_grav_vec) < 0.000001 )
    IVP_Standard_Gravity_Controller::set_alternate_gravity(
      this: standard_gravity_controller,
      new_gravity: (IVP_U_Point *)v10);
  tolerance_4 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v10);
  tolerance = IVP_Environment::get_global_collision_tolerance();
  IVP_Environment::set_global_collision_tolerance(tolerance, gravity_length: tolerance_4);
  v6 = fsqrt(
         (float)((float)(gravityVector->x * gravityVector->x) + (float)(gravityVector->y * gravityVector->y))
       + (float)(gravityVector->z * gravityVector->z));
  global_collision_tolerance = IVP_Environment::get_global_collision_tolerance();
  _DevMsg(
    a1: 1,
    a2: "Set Gravity %.1f (%.3f tolerance)\n",
    v6,
    global_collision_tolerance * g_PhysicsUnits.unitScaleMetersInv);
}

//------------------------------------------------------------------------------
// Address: 0x1000FF60
// Name: public: virtual void CPhysicsEnvironment::GetGravity(class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::GetGravity(CPhysicsEnvironment *this, Vector *pGravityVector)
{
  IVP_Environment *m_pPhysEnv; // eax
  float v3; // xmm0_4

  m_pPhysEnv = this->m_pPhysEnv;
  v3 = m_pPhysEnv->gravity.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pGravityVector->z) = COERCE_UNSIGNED_INT(m_pPhysEnv->gravity.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                             ^ _mask__NegFloat_;
  pGravityVector->y = v3;
  pGravityVector->x = m_pPhysEnv->gravity.k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x1000FFC0
// Name: public: virtual void CPhysicsEnvironment::SetAlternateGravity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsEnvironment::SetAlternateGravity(
        CPhysicsEnvironment *this@<ecx>,
        float a2@<ebp>,
        const Vector *gravityVector)
{
  IVP_Environment *m_pPhysEnv; // ecx
  float v4[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Point gravity; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  gravity.k[1] = a2;
  gravity.k[2] = retaddr;
  m_pPhysEnv = this->m_pPhysEnv;
  v4[0] = gravityVector->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(v4[1]) = COERCE_UNSIGNED_INT(gravityVector->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v4[2] = gravityVector->y * g_PhysicsUnits.unitScaleMeters;
  IVP_Standard_Gravity_Controller::set_alternate_gravity(
    this: m_pPhysEnv->standard_gravity_controller,
    new_gravity: (IVP_U_Point *)v4);
}

//------------------------------------------------------------------------------
// Address: 0x10010030
// Name: public: virtual void CPhysicsEnvironment::GetAlternateGravity(class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::GetAlternateGravity(CPhysicsEnvironment *this, Vector *pGravityVector)
{
  IVP_Standard_Gravity_Controller *standard_gravity_controller; // eax
  float v3; // xmm0_4

  standard_gravity_controller = this->m_pPhysEnv->standard_gravity_controller;
  v3 = standard_gravity_controller->alt_grav_vec.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pGravityVector->z) = COERCE_UNSIGNED_INT(standard_gravity_controller->alt_grav_vec.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                             ^ _mask__NegFloat_;
  pGravityVector->y = v3;
  pGravityVector->x = standard_gravity_controller->alt_grav_vec.k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10010080
// Name: public: virtual void CPhysicsEnvironment::ResetSimulationClock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::ResetSimulationClock(CPhysicsEnvironment *this)
{
  IVP_Environment::reset_time(this: this->m_pPhysEnv);
  IVP_Time_Manager::env_set_current_time(this: this->m_pPhysEnv->time_manager, env: this->m_pPhysEnv, time: 0);
  IVP_Environment::reset_time(this: this->m_pPhysEnv);
  this->m_fixedTimestep = true;
  SeedRandomGenerators();
}

//------------------------------------------------------------------------------
// Address: 0x100100D0
// Name: public: virtual float CPhysicsEnvironment::GetSimulationTimestep(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsEnvironment::GetSimulationTimestep(CPhysicsEnvironment *this)
{
  return this->m_pPhysEnv->delta_PSI_time;
}

//------------------------------------------------------------------------------
// Address: 0x100100E0
// Name: public: virtual float CPhysicsEnvironment::GetSimulationTime(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysicsEnvironment::GetSimulationTime(CPhysicsEnvironment *this)
{
  return this->m_pPhysEnv->current_time.seconds;
}

//------------------------------------------------------------------------------
// Address: 0x100100F0
// Name: public: virtual float CPhysicsEnvironment::GetNextFrameTime(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysicsEnvironment::GetNextFrameTime(CPhysicsEnvironment *this)
{
  return this->m_pPhysEnv->time_of_next_psi.seconds;
}

//------------------------------------------------------------------------------
// Address: 0x10010120
// Name: public: virtual float CPhysicsEnvironment::GetDeltaFrameTime(int)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysicsEnvironment::GetDeltaFrameTime(CPhysicsEnvironment *this, int maxTicks)
{
  return this->m_pPhysEnv->time_of_next_psi.seconds
       - this->m_pPhysEnv->current_time.seconds
       + (double)maxTicks * this->m_pPhysEnv->delta_PSI_time;
}

//------------------------------------------------------------------------------
// Address: 0x10010160
// Name: public: virtual int CPhysicsEnvironment::GetActiveObjectCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsEnvironment::GetActiveObjectCount(CPhysicsEnvironment *this)
{
  return this->m_pSleepEvents->m_activeObjects.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10010170
// Name: public: void CPhysicsEnvironment::PhantomAdd(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::PhantomAdd(CPhysicsEnvironment *this, CPhysicsObject *pObject)
{
  IVP_Simulation_Unit *controller_phantom; // ecx
  CPhysicsListenerCollision *m_pCollisionListener; // eax

  controller_phantom = (IVP_Simulation_Unit *)pObject->m_pObject->controller_phantom;
  if ( controller_phantom != nullptr )
  {
    m_pCollisionListener = this->m_pCollisionListener;
    if ( m_pCollisionListener != nullptr )
      IVP_Controller_Phantom::add_listener_phantom(
        this: controller_phantom,
        add_core: (IVP_Core *)&m_pCollisionListener->IVP_Listener_Phantom);
    else
      IVP_Controller_Phantom::add_listener_phantom(this: controller_phantom, add_core: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100101B0
// Name: public: virtual void CPhysicsEnvironment::GetPerformanceSettings(struct physics_performanceparams_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::GetPerformanceSettings(
        CPhysicsEnvironment *this,
        physics_performanceparams_t *pOutput)
{
  IVP_Anomaly_Limits *anomaly_limits; // eax
  IVP_Range_Manager *range_manager; // eax

  if ( pOutput != nullptr )
  {
    anomaly_limits = this->m_pPhysEnv->anomaly_limits;
    if ( anomaly_limits != nullptr )
    {
      pOutput->maxVelocity = anomaly_limits->max_velocity * g_PhysicsUnits.unitScaleMetersInv;
      pOutput->maxAngularVelocity = (float)(anomaly_limits->max_angular_velocity_per_psi * 57.29578)
                                  * this->m_pPhysEnv->inv_delta_PSI_time;
      pOutput->maxCollisionsPerObjectPerTimestep = anomaly_limits->max_collisions_per_psi;
      pOutput->maxCollisionChecksPerTimestep = anomaly_limits->max_collision_checks_per_psi;
      pOutput->minFrictionMass = anomaly_limits->min_friction_mass;
      pOutput->maxFrictionMass = anomaly_limits->max_friction_mass;
    }
    range_manager = this->m_pPhysEnv->range_manager;
    if ( range_manager != nullptr )
    {
      pOutput->lookAheadTimeObjectsVsWorld = range_manager->look_ahead_time_world;
      pOutput->lookAheadTimeObjectsVsObject = range_manager->look_ahead_time_intra;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010230
// Name: public: virtual void CPhysicsEnvironment::SetPerformanceSettings(struct physics_performanceparams_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetPerformanceSettings(
        CPhysicsEnvironment *this,
        const physics_performanceparams_t *pSettings)
{
  IVP_Anomaly_Limits *anomaly_limits; // eax
  int v3; // xmm1_4
  float minFrictionMass; // xmm0_4
  float maxFrictionMass; // xmm0_4
  IVP_Range_Manager *range_manager; // eax

  if ( pSettings != nullptr )
  {
    anomaly_limits = this->m_pPhysEnv->anomaly_limits;
    if ( anomaly_limits != nullptr )
    {
      v3 = 1065353216;
      anomaly_limits->max_velocity = pSettings->maxVelocity * g_PhysicsUnits.unitScaleMeters;
      anomaly_limits->max_collisions_per_psi = pSettings->maxCollisionsPerObjectPerTimestep;
      anomaly_limits->max_collision_checks_per_psi = pSettings->maxCollisionChecksPerTimestep;
      anomaly_limits->max_angular_velocity_per_psi = (float)(pSettings->maxAngularVelocity * 0.017453292)
                                                   * this->m_pPhysEnv->delta_PSI_time;
      minFrictionMass = pSettings->minFrictionMass;
      if ( minFrictionMass >= 1.0 )
      {
        if ( minFrictionMass > 50000.0 )
          minFrictionMass = 50000.0;
      }
      else
      {
        minFrictionMass = 1.0;
      }
      anomaly_limits->min_friction_mass = minFrictionMass;
      maxFrictionMass = pSettings->maxFrictionMass;
      if ( maxFrictionMass < 1.0 || (v3 = 1195593728, maxFrictionMass > 50000.0) )
        maxFrictionMass = *(float *)&v3;
      anomaly_limits->max_friction_mass = maxFrictionMass;
    }
    range_manager = this->m_pPhysEnv->range_manager;
    if ( range_manager != nullptr )
    {
      range_manager->look_ahead_time_world = pSettings->lookAheadTimeObjectsVsWorld;
      range_manager->look_ahead_time_intra = pSettings->lookAheadTimeObjectsVsObject;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100102F0
// Name: public: virtual void CPhysicsEnvironment::ReadStats(struct physics_stats_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::ReadStats(CPhysicsEnvironment *this, physics_stats_t *pOutput)
{
  IVP_Statistic_Manager *p_statistic_manager; // eax

  if ( pOutput != nullptr )
  {
    p_statistic_manager = &this->m_pPhysEnv->statistic_manager;
    if ( this->m_pPhysEnv != (IVP_Environment *)-56 )
    {
      pOutput->maxRescueSpeed = this->m_pPhysEnv->statistic_manager.max_rescue_speed * g_PhysicsUnits.unitScaleMetersInv;
      pOutput->maxSpeedGain = p_statistic_manager->max_speed_gain * g_PhysicsUnits.unitScaleMetersInv;
      pOutput->impactSysNum = p_statistic_manager->impact_sys_num;
      pOutput->impactCounter = p_statistic_manager->impact_counter;
      pOutput->impactSumSys = p_statistic_manager->impact_sum_sys;
      pOutput->impactHardRescueCount = p_statistic_manager->impact_hard_rescue_counter;
      pOutput->impactRescueAfterCount = p_statistic_manager->impact_rescue_after_counter;
      pOutput->impactDelayedCount = p_statistic_manager->impact_delayed_counter;
      pOutput->impactCollisionChecks = p_statistic_manager->impact_coll_checks;
      pOutput->impactStaticCount = p_statistic_manager->impact_unmov;
      pOutput->totalEnergyDestroyed = p_statistic_manager->sum_energy_destr;
      pOutput->collisionPairsTotal = p_statistic_manager->sum_of_mindists;
      pOutput->collisionPairsCreated = p_statistic_manager->mindists_generated;
      pOutput->collisionPairsDestroyed = p_statistic_manager->mindists_deleted;
      pOutput->potentialCollisionsObjectVsObject = p_statistic_manager->range_intra_exceeded;
      pOutput->potentialCollisionsObjectVsWorld = p_statistic_manager->range_world_exceeded;
      pOutput->frictionEventsProcessed = p_statistic_manager->processed_fmindists;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100103A0
// Name: public: virtual void CPhysicsEnvironment::ClearStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::ClearStats(CPhysicsEnvironment *this)
{
  IVP_Statistic_Manager *p_statistic_manager; // ecx

  p_statistic_manager = &this->m_pPhysEnv->statistic_manager;
  if ( p_statistic_manager != nullptr )
    IVP_Statistic_Manager::clear_statistic(this: p_statistic_manager);
}

//------------------------------------------------------------------------------
// Address: 0x100103B0
// Name: public: virtual void CPhysicsEnvironment::ForceObjectsToSleep(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::ForceObjectsToSleep(
        CPhysicsEnvironment *this,
        IPhysicsObject **pList,
        int listCount)
{
  int v3; // esi
  int v5; // ecx
  int i; // eax
  IVP_Real_Object *pLista[1024]; // [esp+4h] [ebp-1004h] BYREF
  CPhysicsEnvironment *v8; // [esp+1004h] [ebp-4h]

  v3 = listCount;
  v8 = this;
  while ( v3 != 0 )
  {
    v5 = v3;
    if ( v3 >= 1024 )
      v5 = 1024;
    for ( i = 0; i < v5; ++i )
      pLista[i] = (IVP_Real_Object *)(*(IVP_Real_Object **)((char *)&pLista[i] + (char *)pList - (char *)pLista))->next_in_cluster;
    pList += v5;
    v3 -= v5;
    IVP_Real_Object::disable_simulation_list(pEnvironment: v8->m_pPhysEnv, pList: pLista, listCount: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010440
// Name: private: void CPhysicsEnvironment::UpdateDeleteHighMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::UpdateDeleteHighMark(CPhysicsEnvironment *this)
{
  this->m_lastObjectThisTick = this->m_objects.m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010450
// Name: public: virtual void CPhysicsEnvironment::SetPredicted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetPredicted(CPhysicsEnvironment *this, bool bPredicted)
{
  if ( this->m_objects.m_Size != 0 || this->m_fluids.m_Size != 0 || this->m_playerControllers.m_Size != 0 )
    _Error(a1: "Predicted physics not designed to change once objects have been made");
  else
    this->m_bPredicted = bPredicted;
}

//------------------------------------------------------------------------------
// Address: 0x10010490
// Name: public: virtual void CDeleteProxy<class IPhysicsConstraint>::Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeleteProxy<IPhysicsConstraint>::Delete(CDeleteProxy<IPhysicsConstraint> *this)
{
  IPhysicsConstraint *m_pItem; // ecx

  m_pItem = this->m_pItem;
  if ( m_pItem != nullptr )
    ((void (__thiscall *)(IPhysicsConstraint *, int))m_pItem->dtr_IPhysicsConstraint)(a1: m_pItem, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10010580
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: m_pMemory,
                                                                                                   a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                   this: _g_pMemAlloc,
                                                                                                   a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010630
// Name: public: void CUtlMemory<struct CPhysicsEnvironment::PredictedData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(
        CUtlMemory<CUtlMultiList<void *,unsigned short>::ListElem_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlMultiList<void *,unsigned short>::ListElem_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlMultiList<void *,unsigned short>::ListElem_t *)_g_pMemAlloc->Realloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: m_pMemory,
                                                                              a3: v7);
    else
      this->m_pMemory = (CUtlMultiList<void *,unsigned short>::ListElem_t *)_g_pMemAlloc->Alloc_2(
                                                                              this: _g_pMemAlloc,
                                                                              a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100106D0
// Name: public: void CSleepObjects::ProcessActiveObjects(class IVP_Environment __near *,class IPhysicsCollisionEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CSleepObjects::ProcessActiveObjects(
        CSleepObjects *this,
        IVP_Environment *pEnvironment,
        IPhysicsCollisionEvent *pEvent)
{
  float delta_PSI_time; // xmm1_4
  CSleepObjects *v4; // edx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int v7; // edi
  CPhysicsObject *v8; // eax
  bool v9; // zf
  IVP_Real_Object *m_pObject; // ecx
  IVP_Synapse_Friction *friction_synapses; // esi
  IVP_Contact_Point *v12; // eax
  IVP_Synapse_Friction *synapse; // ebx
  _BYTE *client_data; // edi
  double eliminated_energy; // st7
  int v16; // edi
  int material_index; // eax
  void (__thiscall *Friction)(IPhysicsCollisionEvent *, IPhysicsObject *, float, int, int, IPhysicsCollisionData *); // edx
  int v19; // [esp+8h] [ebp-44h]
  CPhysicsFrictionData data; // [esp+20h] [ebp-2Ch] BYREF
  CSleepObjects *v21; // [esp+30h] [ebp-1Ch]
  long double seconds; // [esp+34h] [ebp-18h] OVERLAPPED
  IVP_Real_Object *ivpObject; // [esp+3Ch] [ebp-10h]
  int i; // [esp+40h] [ebp-Ch]
  IVP_Contact_Point *friction_handle; // [esp+44h] [ebp-8h]
  float t; // [esp+48h] [ebp-4h]
  float energya; // [esp+54h] [ebp+8h]
  float energy; // [esp+54h] [ebp+8h]

  delta_PSI_time = pEnvironment->delta_PSI_time;
  v4 = this;
  seconds = pEnvironment->time_of_last_psi.seconds;
  v5 = seconds;
  v6 = v5 - this->m_lastScrapeTime;
  v21 = this;
  if ( delta_PSI_time <= v6 )
  {
    t = 0.0;
    if ( v6 != 0.0 )
      t = 1.0 / v6;
    v7 = 0;
    this->m_lastScrapeTime = v5;
    i = 0;
    if ( this->m_activeObjects.m_Size > 0 )
    {
      do
      {
        v8 = v4->m_activeObjects.m_Memory.m_pMemory[v7];
        v9 = (v8->m_callbacks & 2) == 0;
        m_pObject = v8->m_pObject;
        HIDWORD(seconds) = v8;
        ivpObject = m_pObject;
        if ( !v9 )
        {
          friction_synapses = m_pObject->friction_synapses;
          if ( friction_synapses != nullptr )
          {
            do
            {
              v12 = (IVP_Contact_Point *)((char *)friction_synapses + friction_synapses->contact_point_offset);
              synapse = v12->synapse;
              friction_handle = v12;
              if ( v12->synapse == friction_synapses )
                synapse = &v12->synapse[1];
              client_data = synapse->l_obj->client_data;
              if ( (client_data[28] & 2) != 0 )
              {
                eliminated_energy = IVP_Contact_Point_API::get_eliminated_energy(friction_handle: v12);
                if ( eliminated_energy != 0.0 )
                {
                  energya = eliminated_energy;
                  energy = (float)(energya * t) * ivpObject->physical_core->inv_rot_inertia.hesse_val;
                  if ( energy > 0.050000001 )
                  {
                    v16 = *((unsigned __int16 *)client_data + 12);
                    material_index = IVP_Synapse_Friction::get_material_index(this: synapse);
                    if ( material_index != 0 )
                      v16 = physprops->RemapIVPMaterialIndex(this: physprops, a2: material_index);
                    data.m_pPoint = (const IVP_Contact_Point *)((char *)friction_synapses
                                                              + friction_synapses->contact_point_offset);
                    Friction = pEvent->Friction;
                    v19 = *(unsigned __int16 *)(HIDWORD(seconds) + 24);
                    data.m_sign = (float)(2 * (friction_synapses == friction_handle->synapse) - 1);
                    data.__vftable = (CPhysicsFrictionData_vtbl *)&CPhysicsFrictionData::`vftable';
                    data.m_pContact = nullptr;
                    ((void (__stdcall *)(_DWORD, _DWORD, int, int, CPhysicsFrictionData *))Friction)(
                      a1: HIDWORD(seconds),
                      a2: energy * 1550.0032,
                      a3: v19,
                      a4: v16,
                      a5: &data);
                  }
                  IVP_Contact_Point_API::reset_eliminated_energy(friction_handle);
                }
              }
              friction_synapses = friction_synapses->next;
            }
            while ( friction_synapses != nullptr );
            v4 = v21;
            v7 = i;
          }
        }
        i = ++v7;
      }
      while ( v7 < v4->m_activeObjects.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010890
// Name: public: virtual char const __near * CDragController::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDragController::get_controller_name(CDragController *this)
{
  return "vphysics:drag";
}

//------------------------------------------------------------------------------
// Address: 0x100108B0
// Name: public: virtual void CDragController::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDragController::do_simulation_controller(
        CDragController *this,
        IVP_Event_Sim *event,
        IVP_U_Vector<IVP_Core> *core_list)
{
  int v3; // eax
  char *v4; // esi
  float *v5; // edi
  double v6; // st7
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  IVP_U_Float_Point *v12; // esi
  double v13; // st7
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  CPhysicsObject *angDragForce; // [esp+0h] [ebp-10h]
  float angDragForcea; // [esp+0h] [ebp-10h]
  float dragForce; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v3 = core_list->n_elems - 1;
  i = v3;
  if ( core_list->n_elems != 0 )
  {
    while ( 1 )
    {
      v4 = (char *)core_list->elems[v3];
      v5 = (float *)(v4 + 208);
      angDragForce = *(CPhysicsObject **)(**((_DWORD **)v4 + 21) + 160);
      v6 = CPhysicsObject::GetDragInDirection(this: angDragForce, velocity: (const IVP_U_Float_Point *)v4 + 13)
         * -0.5
         * this->m_airDensity
         * event->delta_time;
      if ( v6 >= -1.0 )
      {
        v7 = v6;
        dragForce = v6;
        if ( dragForce >= 0.0 )
          goto LABEL_8;
      }
      else
      {
        v7 = -1.0;
      }
      v8 = *((float *)v4 + 53) * v7;
      v9 = *((float *)v4 + 54) * v7;
      v10 = *v5 + (float)(*v5 * v7);
      *((float *)v4 + 53) = *((float *)v4 + 53) + v8;
      v11 = *((float *)v4 + 54) + v9;
      *v5 = v10;
      *((float *)v4 + 54) = v11;
LABEL_8:
      v12 = (IVP_U_Float_Point *)(v4 + 192);
      v13 = -(CPhysicsObject::GetAngularDragInDirection(this: angDragForce, angVelocity: v12)
            * this->m_airDensity
            * event->delta_time);
      if ( v13 >= -1.0 )
      {
        v14 = v13;
        angDragForcea = v13;
        if ( angDragForcea >= 0.0 )
          goto LABEL_12;
      }
      else
      {
        v14 = -1.0;
      }
      v15 = v12->k[1] * v14;
      v16 = v12->k[2] * v14;
      v17 = v12->k[0] + (float)(v12->k[0] * v14);
      v12->k[1] = v12->k[1] + v15;
      v18 = v12->k[2] + v16;
      v12->k[0] = v17;
      v12->k[2] = v18;
LABEL_12:
      if ( --i < 0 )
        return;
      v3 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010A10
// Name: public: virtual class IPhysicsObject const __near * __near * CPhysicsEnvironment::GetObjectList(int __near *)const
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject **__thiscall CPhysicsEnvironment::GetObjectList(CPhysicsEnvironment *this, int *pOutputObjectCount)
{
  int m_Size; // eax

  m_Size = this->m_objects.m_Size;
  if ( pOutputObjectCount != nullptr )
    *pOutputObjectCount = m_Size;
  if ( m_Size != 0 )
    return this->m_objects.m_Memory.m_pMemory;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10010A30
// Name: public: virtual class IPhysicsConstraint __near * CPhysicsEnvironment::CreateHingeConstraint(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_hingeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysicsEnvironment::CreateHingeConstraint(
        CPhysicsEnvironment *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        IPhysicsConstraintGroup *pGroup,
        const constraint_hingeparams_t *hinge)
{
  IVP_Environment *m_pPhysEnv; // eax
  constraint_limitedhingeparams_t limitedhinge; // [esp+0h] [ebp-58h] BYREF

  limitedhinge.worldPosition.x = hinge->worldPosition.x;
  limitedhinge.worldPosition.y = hinge->worldPosition.y;
  limitedhinge.worldPosition.z = hinge->worldPosition.z;
  limitedhinge.worldAxisDirection = hinge->worldAxisDirection;
  limitedhinge.hingeAxis = hinge->hingeAxis;
  *(_QWORD *)&limitedhinge.constraint.strength = *(_QWORD *)&hinge->constraint.strength;
  *(_QWORD *)&limitedhinge.constraint.torqueLimit = *(_QWORD *)&hinge->constraint.torqueLimit;
  m_pPhysEnv = this->m_pPhysEnv;
  *(_QWORD *)&limitedhinge.constraint.bodyMassScale[1] = *(_QWORD *)&hinge->constraint.bodyMassScale[1];
  memset(&limitedhinge.referencePerpAxisDirection, 0, 24);
  return CreateHingeConstraint(
           pEnvironment: m_pPhysEnv,
           pReferenceObject,
           pAttachedObject,
           pGroup,
           hinge: &limitedhinge);
}

//------------------------------------------------------------------------------
// Address: 0x10010AF0
// Name: public: class IPhysicsPlayerController __near * CPhysicsEnvironment::FindPlayerController(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsPlayerController *__thiscall CPhysicsEnvironment::FindPlayerController(
        CPhysicsEnvironment *this,
        IPhysicsObject *pPhysicsObject)
{
  int v3; // esi
  IPhysicsPlayerController *v4; // ecx

  v3 = this->m_playerControllers.m_Size - 1;
  if ( v3 < 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_playerControllers.m_Memory.m_pMemory[v3];
    if ( v4->GetObject(this: v4) == pPhysicsObject )
      break;
    if ( --v3 < 0 )
      return nullptr;
  }
  return this->m_playerControllers.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10010B30
// Name: public: virtual void CPhysicsEnvironment::GetActiveObjects(class IPhysicsObject __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::GetActiveObjects(CPhysicsEnvironment *this, IPhysicsObject **pOutputObjectList)
{
  CSleepObjects *m_pSleepEvents; // ecx
  int i; // eax

  m_pSleepEvents = this->m_pSleepEvents;
  for ( i = 0; i < m_pSleepEvents->m_activeObjects.m_Size; ++i )
    pOutputObjectList[i] = m_pSleepEvents->m_activeObjects.m_Memory.m_pMemory[i];
}

//------------------------------------------------------------------------------
// Address: 0x10010B60
// Name: public: virtual bool CPhysicsEnvironment::IsCollisionModelUsed(class CPhysCollide __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsEnvironment::IsCollisionModelUsed(CPhysicsEnvironment *this, CPhysCollide *pCollide)
{
  int v3; // esi
  IPhysicsObject *v4; // ecx
  int v5; // esi
  IPhysicsObject *v6; // ecx

  v3 = this->m_deadObjects.m_Size - 1;
  if ( v3 < 0 )
  {
LABEL_4:
    v5 = this->m_objects.m_Size - 1;
    if ( v5 < 0 )
      return 0;
    while ( 1 )
    {
      v6 = this->m_objects.m_Memory.m_pMemory[v5];
      if ( v6->GetCollide(this: v6) == pCollide )
        break;
      if ( --v5 < 0 )
        return 0;
    }
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_deadObjects.m_Memory.m_pMemory[v3];
      if ( v4->GetCollide(this: v4) == pCollide )
        break;
      if ( --v3 < 0 )
        goto LABEL_4;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010DF0
// Name: public: void CUtlMultiList<void __near *,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<void *,unsigned short>::RemoveAll(CUtlMultiList<void *,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011730
// Name: public: void CSleepObjects::DeleteObject(class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::DeleteObject(CSleepObjects *this, CPhysicsObject *pObject)
{
  int m_activeIndex; // eax
  int m_Size; // esi

  m_activeIndex = pObject->m_activeIndex;
  if ( m_activeIndex < this->m_activeObjects.m_Size )
  {
    m_Size = this->m_activeObjects.m_Size;
    if ( m_Size > 0 )
    {
      if ( m_activeIndex != m_Size - 1 )
        this->m_activeObjects.m_Memory.m_pMemory[m_activeIndex] = this->m_activeObjects.m_Memory.m_pMemory[m_Size - 1];
      --this->m_activeObjects.m_Size;
    }
    if ( m_activeIndex < this->m_activeObjects.m_Size )
      this->m_activeObjects.m_Memory.m_pMemory[m_activeIndex]->m_activeIndex = m_activeIndex;
    pObject->m_activeIndex = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011780
// Name: public: virtual void CPhysicsEnvironment::DestroyPlayerController(class IPhysicsPlayerController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyPlayerController(
        CPhysicsEnvironment *this,
        IPhysicsFrictionSnapshot *pController)
{
  IPhysicsFrictionSnapshot *v2; // edi
  IPredictable_Controller_Independant *v4; // edx
  int i; // eax
  IPredictable_Controller_Independant **m_pMemory; // ecx
  bool v7; // zf
  IPredictable_Controller_Independant **v8; // ecx

  v2 = pController;
  CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
    this: (CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *)&this->m_playerControllers,
    src: (IPhysicsEnvironment **)&pController);
  if ( v2 != nullptr )
    v4 = (IPredictable_Controller_Independant *)&v2[-1];
  else
    v4 = nullptr;
  for ( i = 0; i != this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size; ++i )
  {
    m_pMemory = this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory;
    v7 = m_pMemory[i] == v4;
    v8 = &m_pMemory[i];
    if ( v7 )
      *v8 = &s_StubPredictableController;
  }
  DestroyPlayerController(pSnapshot: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100117E0
// Name: public: virtual void CPhysicsEnvironment::RestorePredictedSimulation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::RestorePredictedSimulation(CPhysicsEnvironment *this)
{
  int m_Size; // edx
  int v3; // eax
  CPhysicsEnvironment::PredictedData_t *m_pMemory; // edi
  int m_iPredictionCommandNum; // ebx
  CPhysicsEnvironment::PredictedData_t *v6; // ecx
  int i; // edi
  int v8; // edx
  int v9; // ecx
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *v10; // eax
  int iControllerCallOrderStart; // edi
  int j; // ebx
  int k; // edi
  float fSimTime; // [esp+18h] [ebp-4h]

  if ( this->m_bPredicted )
  {
    m_Size = this->m_PredictionBackups.m_Size;
    v3 = 0;
    fSimTime = 0.0;
    if ( m_Size != 0 )
    {
      m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
      m_iPredictionCommandNum = this->m_iPredictionCommandNum;
      v6 = m_pMemory;
      while ( v6->iCommandNum != m_iPredictionCommandNum )
      {
        ++v3;
        ++v6;
        if ( v3 == m_Size )
          goto LABEL_8;
      }
      fSimTime = m_pMemory[v3].fSimulationStep;
    }
LABEL_8:
    for ( i = 0; i != this->m_objects.m_Size; ++i )
      CPredictedPhysicsObject::PreSimulation(
        this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[i],
        bBackup: false);
    v8 = this->m_PredictedPhysControllerCallOrder.m_Commands.m_Size;
    v9 = 0;
    if ( v8 != 0 )
    {
      v10 = this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory;
      while ( v10->iCommandNum != this->m_iPredictionCommandNum )
      {
        ++v9;
        ++v10;
        if ( v9 == v8 )
          goto LABEL_17;
      }
      iControllerCallOrderStart = v10->iControllerCallOrderStart;
      for ( j = iControllerCallOrderStart + v10->iControllerCallOrderCount;
            iControllerCallOrderStart != j;
            ++iControllerCallOrderStart )
      {
        ((void (__stdcall *)(_DWORD))this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory[iControllerCallOrderStart]->Prediction_Resimulate)(a1: LODWORD(fSimTime));
      }
    }
LABEL_17:
    for ( k = 0; k != this->m_objects.m_Size; ++k )
      CPredictedPhysicsObject::PostSimulation(
        this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[k],
        fSimulationTime: fSimTime,
        bBackup: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100118D0
// Name: public: void CPredictableControllerSimulationOrderTracker_Manager::DoneReferencingPreviousCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictableControllerSimulationOrderTracker_Manager::DoneReferencingPreviousCommands(
        CPredictableControllerSimulationOrderTracker_Manager *this,
        int iCommandNum)
{
  int v3; // ebx
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *m_pMemory; // ecx
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *i; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edx

  v3 = 0;
  if ( this->m_Commands.m_Size != 0 )
  {
    m_pMemory = this->m_Commands.m_Memory.m_pMemory;
    for ( i = this->m_Commands.m_Memory.m_pMemory; i->iCommandNum < iCommandNum; ++i )
    {
      if ( ++v3 == this->m_Commands.m_Size )
        return;
    }
    if ( v3 > 0 )
    {
      v6 = m_pMemory[v3].iControllerCallOrderStart + m_pMemory[v3].iControllerCallOrderCount;
      if ( this->m_Commands.m_Size - v3 > 0 )
        _V_memmove(
          dest: this->m_Commands.m_Memory.m_pMemory,
          src: &this->m_Commands.m_Memory.m_pMemory[v3],
          count: 12 * (this->m_Commands.m_Size - v3));
      this->m_Commands.m_Size -= v3;
      if ( v6 != 0 )
      {
        if ( this->m_CallOrder.m_Size - v6 > 0 && v6 > 0 )
          _V_memmove(
            dest: this->m_CallOrder.m_Memory.m_pMemory,
            src: &this->m_CallOrder.m_Memory.m_pMemory[v6],
            count: 4 * (this->m_CallOrder.m_Size - v6));
        this->m_CallOrder.m_Size -= v6;
        v7 = 0;
        if ( this->m_Commands.m_Size != 0 )
        {
          v8 = 0;
          do
          {
            this->m_Commands.m_Memory.m_pMemory[v8].iControllerCallOrderStart -= v6;
            ++v7;
            ++v8;
          }
          while ( v7 != this->m_Commands.m_Size );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012A70
// Name: public: virtual void CSleepObjects::event_object_frozen(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::event_object_frozen(CSleepObjects *this, IVP_Event_Object *pEvent)
{
  IPhysicsObject *client_data; // esi

  client_data = (IPhysicsObject *)pEvent->real_object->client_data;
  if ( client_data != nullptr )
  {
    CPhysicsObject::NotifySleep(this: (CPhysicsObject *)pEvent->real_object->client_data);
    if ( this->m_pCallback != nullptr )
      this->m_pCallback->ObjectSleep(this: this->m_pCallback, a2: client_data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012AB0
// Name: public: virtual void CSleepObjects::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::event_object_deleted(CSleepObjects *this, IVP_Event_Object *pEvent)
{
  _WORD *client_data; // edi
  int v3; // eax
  int m_Size; // esi

  client_data = pEvent->real_object->client_data;
  if ( client_data != nullptr )
  {
    v3 = (unsigned __int16)client_data[13];
    if ( v3 < this->m_activeObjects.m_Size )
    {
      m_Size = this->m_activeObjects.m_Size;
      if ( m_Size > 0 )
      {
        if ( v3 != m_Size - 1 )
          this->m_activeObjects.m_Memory.m_pMemory[v3] = this->m_activeObjects.m_Memory.m_pMemory[m_Size - 1];
        --this->m_activeObjects.m_Size;
      }
      if ( v3 < this->m_activeObjects.m_Size )
        this->m_activeObjects.m_Memory.m_pMemory[v3]->m_activeIndex = v3;
      client_data[13] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B10
// Name: public: virtual int CCollisionSolver::max_collision_checks_exceeded(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionSolver::max_collision_checks_exceeded(CCollisionSolver *this, int totalChecks)
{
  if ( this->delete_this_if_env_is_deleted != IVP_FALSE )
    return (*(int (__thiscall **)(IVP_BOOL, int))(*(_DWORD *)this->delete_this_if_env_is_deleted + 12))(
             a1: this->delete_this_if_env_is_deleted,
             a2: totalChecks);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012B50
// Name: public: virtual enum IVP_BOOL CCollisionSolver::check_objects_for_collision_detection(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_BOOL __thiscall CCollisionSolver::check_objects_for_collision_detection(
        CCollisionSolver *this,
        IVP_Real_Object *ivp0,
        IVP_Real_Object *ivp1)
{
  _WORD *client_data; // esi
  _WORD *v4; // edi
  IVP_BOOL result; // eax
  IPhysicsCollisionSolver_vtbl *v6; // ebx
  int v7; // eax
  int v8; // eax

  result = IVP_TRUE;
  if ( this->m_pSolver != nullptr )
  {
    client_data = ivp0->client_data;
    v4 = ivp1->client_data;
    if ( client_data != nullptr && v4 != nullptr )
    {
      if ( (client_data[14] & 0x800) != 0 && (v4[14] & 0x400) != 0 )
        return IVP_FALSE;
      if ( (v4[14] & 0x800) != 0 && (client_data[14] & 0x400) != 0 )
        return IVP_FALSE;
      v6 = this->m_pSolver->__vftable;
      v7 = (*(int (__thiscall **)(_WORD *))(*(_DWORD *)v4 + 68))(a1: v4);
      v8 = (*(int (__thiscall **)(_WORD *, int))(*(_DWORD *)client_data + 68))(a1: client_data, a2: v7);
      if ( ((int (__thiscall *)(IPhysicsCollisionSolver *, _WORD *, _WORD *, int))v6->ShouldCollide)(
             a1: this->m_pSolver,
             a2: client_data,
             a3: v4,
             a4: v8) == 0 )
        return IVP_FALSE;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012BF0
// Name: public: virtual enum IVP_BOOL CCollisionSolver::max_collisions_exceeded_check_freezing(class IVP_Anomaly_Limits __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCollisionSolver::max_collisions_exceeded_check_freezing(
        CCollisionSolver *this,
        IVP_Anomaly_Limits *__formal,
        IVP_Core *pCore)
{
  return this->delete_this_if_env_is_deleted == IVP_FALSE
      || (*(unsigned __int8 (__thiscall **)(IVP_BOOL, _DWORD))(*(_DWORD *)this->delete_this_if_env_is_deleted + 8))(
           a1: this->delete_this_if_env_is_deleted,
           a2: *((_DWORD *)*pCore->objects.elems + 40)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012C30
// Name: public: virtual void CCollisionSolver::max_velocity_exceeded(class IVP_Anomaly_Limits __near *,class IVP_Core __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionSolver::max_velocity_exceeded(
        CCollisionSolver *this,
        IVP_Anomaly_Limits *al,
        IVP_Core *pCore,
        IVP_U_Float_Point *velocity_in_out)
{
  int v5; // ecx

  v5 = *((_DWORD *)*pCore->objects.elems + 40);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 284))(a1: v5) == 0 )
    IVP_Anomaly_Manager::max_velocity_exceeded((IVP_Anomaly_Manager *)this, al, __formal: pCore, velocity_in_out);
}

//------------------------------------------------------------------------------
// Address: 0x10012C70
// Name: public: virtual enum IVP_BOOL CCollisionSolver::max_contacts_exceeded_check_freezing(class IVP_Core __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCollisionSolver::max_contacts_exceeded_check_freezing(
        CCollisionSolver *this,
        IVP_Core **pCoreList,
        int coreCount)
{
  int m_Size; // esi
  IPhysicsObject **m_pMemory; // edi
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  int v6; // eax
  int v7; // ebx
  IPhysicsObject **v8; // ebx
  BOOL v9; // esi
  CUtlVector<IPhysicsObject *,CUtlMemory<IPhysicsObject *,int> > list; // [esp+Ch] [ebp-20h] BYREF
  CCollisionSolver *v12; // [esp+20h] [ebp-Ch]
  IPhysicsObject *v13; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  v12 = this;
  memset(&list, 0, 16);
  if ( coreCount > 0 )
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    list.m_Memory.m_nAllocationCount = coreCount;
    m_pMemory = (IPhysicsObject **)Alloc_2(this: _g_pMemAlloc, a2: 4 * coreCount);
    list.m_Memory.m_pMemory = m_pMemory;
  }
  v6 = 0;
  list.m_pElements = m_pMemory;
  for ( i = 0; v6 < coreCount; i = v6 )
  {
    v13 = *((IPhysicsObject **)*pCoreList[v6]->objects.elems + 40);
    v7 = m_Size;
    if ( m_Size + 1 > list.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&list,
        num: m_Size - list.m_Memory.m_nAllocationCount + 1);
      m_Size = list.m_Size;
      m_pMemory = list.m_Memory.m_pMemory;
    }
    list.m_Size = ++m_Size;
    list.m_pElements = m_pMemory;
    if ( m_Size - v7 - 1 > 0 )
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
    v8 = &m_pMemory[v7];
    if ( v8 != nullptr )
      *v8 = v13;
    v6 = i + 1;
  }
  v9 = (*(unsigned __int8 (__thiscall **)(IVP_BOOL, IPhysicsObject **, int))(*(_DWORD *)v12->delete_this_if_env_is_deleted
                                                                           + 16))(
         a1: v12->delete_this_if_env_is_deleted,
         a2: m_pMemory,
         a3: m_Size) != 0;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10012D70
// Name: public: virtual class IPhysicsObject __near * CPhysicsEnvironment::CreatePolyObject(class CPhysCollide const __near *,int,class Vector const __near &,class QAngle const __near &,struct objectparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsObject *__thiscall CPhysicsEnvironment::CreatePolyObject(
        CPhysicsEnvironment *this,
        const CPhysCollide *pCollisionModel,
        int materialIndex,
        const Vector *position,
        const QAngle *angles,
        objectparams_t *pParams)
{
  CPhysicsObject *result; // eax
  IPhysicsObject *v8; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IPhysicsObject **m_pMemory; // ecx
  int v12; // eax
  IPhysicsObject **v13; // eax

  result = CreatePhysicsObject(
             pEnvironment: this,
             pCollisionModel,
             materialIndex,
             position,
             angles,
             pParams,
             isStatic: false);
  v8 = result;
  if ( result != nullptr )
  {
    m_nAllocationCount = this->m_objects.m_Memory.m_nAllocationCount;
    m_Size = this->m_objects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_objects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_objects.m_Size;
    m_pMemory = this->m_objects.m_Memory.m_pMemory;
    v12 = this->m_objects.m_Size - m_Size - 1;
    this->m_objects.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = &this->m_objects.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v8;
    return (CPhysicsObject *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012E00
// Name: public: virtual class IPhysicsObject __near * CPhysicsEnvironment::CreatePolyObjectStatic(class CPhysCollide const __near *,int,class Vector const __near &,class QAngle const __near &,struct objectparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsObject *__thiscall CPhysicsEnvironment::CreatePolyObjectStatic(
        CPhysicsEnvironment *this,
        const CPhysCollide *pCollisionModel,
        int materialIndex,
        const Vector *position,
        const QAngle *angles,
        objectparams_t *pParams)
{
  CPhysicsObject *result; // eax
  IPhysicsObject *v8; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IPhysicsObject **m_pMemory; // ecx
  int v12; // eax
  IPhysicsObject **v13; // eax

  result = CreatePhysicsObject(
             pEnvironment: this,
             pCollisionModel,
             materialIndex,
             position,
             angles,
             pParams,
             isStatic: true);
  v8 = result;
  if ( result != nullptr )
  {
    m_nAllocationCount = this->m_objects.m_Memory.m_nAllocationCount;
    m_Size = this->m_objects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_objects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_objects.m_Size;
    m_pMemory = this->m_objects.m_Memory.m_pMemory;
    v12 = this->m_objects.m_Size - m_Size - 1;
    this->m_objects.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = &this->m_objects.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = v8;
    return (CPhysicsObject *)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012E90
// Name: public: virtual class IPhysicsObject __near * CPhysicsEnvironment::UnserializeObjectFromBuffer(void __near *,unsigned char __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CPhysicsEnvironment::UnserializeObjectFromBuffer(
        CPhysicsEnvironment *this,
        void *pGameData,
        unsigned __int8 *pBuffer,
        unsigned int bufferSize,
        bool enableCollisions)
{
  IPhysicsObject *result; // eax
  IPhysicsObject *v7; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IPhysicsObject **m_pMemory; // ecx
  int v11; // eax
  IPhysicsObject **v12; // eax

  result = CreateObjectFromBuffer(pEnvironment: this, pGameData, pBuffer, bufferSize, enableCollisions);
  v7 = result;
  if ( result != nullptr )
  {
    m_nAllocationCount = this->m_objects.m_Memory.m_nAllocationCount;
    m_Size = this->m_objects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_objects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_objects.m_Size;
    m_pMemory = this->m_objects.m_Memory.m_pMemory;
    v11 = this->m_objects.m_Size - m_Size - 1;
    this->m_objects.m_pElements = m_pMemory;
    if ( v11 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
    v12 = &this->m_objects.m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      *v12 = v7;
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012F10
// Name: public: virtual void CPhysicsEnvironment::DestroyObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyObject(CPhysicsEnvironment *this, CPhysicsObject *pObject)
{
  int v2; // eax
  IPhysicsObject **v3; // edx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_deadObjects; // esi
  int v7; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v9; // eax
  CPhysicsObject **v10; // eax

  if ( pObject != nullptr )
  {
    v2 = this->m_objects.m_Size - 1;
    if ( v2 < 0 )
    {
LABEL_7:
      _DevMsg(a1: 1, a2: "error deleting physics object\n");
      pObject->GetCallbackFlags(this: pObject);
    }
    else
    {
      v3 = &this->m_objects.m_Memory.m_pMemory[v2];
      while ( *v3 != pObject )
      {
        --v3;
        if ( --v2 < 0 )
          goto LABEL_7;
      }
      m_Size = this->m_objects.m_Size;
      if ( m_Size > 0 )
      {
        if ( v2 != m_Size - 1 )
          this->m_objects.m_Memory.m_pMemory[v2] = this->m_objects.m_Memory.m_pMemory[m_Size - 1];
        --this->m_objects.m_Size;
      }
      pObject->m_callbacks |= 0x400u;
      if ( v2 > this->m_lastObjectThisTick )
        *((_BYTE *)pObject + 20) |= 0x80u;
      if ( this->m_inSimulation || this->m_queueDeleteObject )
      {
        m_nAllocationCount = this->m_deadObjects.m_Memory.m_nAllocationCount;
        p_m_deadObjects = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_deadObjects;
        v7 = this->m_deadObjects.m_Size;
        if ( v7 + 1 > m_nAllocationCount )
          CUtlMemory<CPredictedPhysicsObject *,int>::Grow(this: p_m_deadObjects, num: v7 - m_nAllocationCount + 1);
        ++p_m_deadObjects[1].m_pMemory;
        m_pMemory = p_m_deadObjects->m_pMemory;
        v9 = (int)p_m_deadObjects[1].m_pMemory - v7 - 1;
        p_m_deadObjects[1].m_nAllocationCount = (int)p_m_deadObjects->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v9);
        v10 = (CPhysicsObject **)&p_m_deadObjects->m_pMemory[v7];
        if ( v10 != nullptr )
          *v10 = pObject;
      }
      else
      {
        CSleepObjects::DeleteObject(this: this->m_pSleepEvents, pObject);
        ((void (__thiscall *)(CPhysicsObject *, int))pObject->dtr_IPhysicsObject)(a1: pObject, a2: 1);
      }
    }
  }
  else
  {
    DevMsg(a1: "Deleted NULL vphysics object\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013030
// Name: public: virtual void CPhysicsEnvironment::DestroyFluidController(class IPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyFluidController(CPhysicsEnvironment *this, IPhysicsFluidController *pFluid)
{
  IPhysicsFluidController *v2; // esi

  v2 = pFluid;
  CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
    this: (CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *)&this->m_fluids,
    src: (IPhysicsEnvironment **)&pFluid);
  if ( v2 != nullptr )
    ((void (__thiscall *)(IPhysicsFluidController *, int))v2->dtr_IPhysicsFluidController)(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10013060
// Name: public: void CPhysicsEnvironment::ClearDeadObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::ClearDeadObjects(CPhysicsEnvironment *this)
{
  int v1; // edi
  IPhysicsObject *v3; // ecx
  int v4; // edx
  CSleepObjects *m_pSleepEvents; // eax
  int m_Size; // ebx
  bool v7; // sf
  CDeleteQueue *m_pDeleteQueue; // ebx
  int j; // edi
  int v10; // edi
  CPhysCollide **m_pMemory; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < this->m_deadObjects.m_Size; i = v1 )
  {
    v3 = this->m_deadObjects.m_Memory.m_pMemory[v1];
    v4 = HIWORD(v3[6].__vftable);
    m_pSleepEvents = this->m_pSleepEvents;
    if ( v4 < m_pSleepEvents->m_activeObjects.m_Size )
    {
      m_Size = m_pSleepEvents->m_activeObjects.m_Size;
      if ( m_Size > 0 )
      {
        if ( v4 != m_Size - 1 )
          m_pSleepEvents->m_activeObjects.m_Memory.m_pMemory[v4] = m_pSleepEvents->m_activeObjects.m_Memory.m_pMemory[m_Size - 1];
        --m_pSleepEvents->m_activeObjects.m_Size;
        v1 = i;
      }
      if ( v4 < m_pSleepEvents->m_activeObjects.m_Size )
        m_pSleepEvents->m_activeObjects.m_Memory.m_pMemory[v4]->m_activeIndex = v4;
      HIWORD(v3[6].__vftable) = -1;
    }
    ((void (__thiscall *)(IPhysicsObject *, int))v3->dtr_IPhysicsObject)(a1: v3, a2: 1);
    ++v1;
  }
  v7 = this->m_deadObjects.m_Memory.m_nGrowSize < 0;
  this->m_deadObjects.m_Size = 0;
  if ( !v7 )
  {
    if ( this->m_deadObjects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_deadObjects.m_Memory.m_pMemory);
      this->m_deadObjects.m_Memory.m_pMemory = nullptr;
    }
    this->m_deadObjects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_deadObjects.m_pElements = this->m_deadObjects.m_Memory.m_pMemory;
  m_pDeleteQueue = this->m_pDeleteQueue;
  for ( j = m_pDeleteQueue->m_list.m_Size - 1; j >= 0; --j )
  {
    m_pDeleteQueue->m_list.m_Memory.m_pMemory[j]->Delete(this: m_pDeleteQueue->m_list.m_Memory.m_pMemory[j]);
    free(data: m_pDeleteQueue->m_list.m_Memory.m_pMemory[j]);
  }
  v10 = 0;
  for ( m_pDeleteQueue->m_list.m_Size = 0; v10 < this->m_deadObjectCollides.m_Size; ++v10 )
    physcollision->DestroyCollide(this: physcollision, a2: this->m_deadObjectCollides.m_Memory.m_pMemory[v10]);
  v7 = this->m_deadObjectCollides.m_Memory.m_nGrowSize < 0;
  this->m_deadObjectCollides.m_Size = 0;
  if ( v7 )
  {
    this->m_deadObjectCollides.m_pElements = this->m_deadObjectCollides.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_deadObjectCollides.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_deadObjectCollides.m_Memory.m_pMemory);
      this->m_deadObjectCollides.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_deadObjectCollides.m_Memory.m_pMemory;
    this->m_deadObjectCollides.m_Memory.m_nAllocationCount = 0;
    this->m_deadObjectCollides.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100131B0
// Name: public: virtual void CPhysicsEnvironment::DestroyMotionController(class IPhysicsMotionController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyMotionController(
        CPhysicsEnvironment *this,
        IPhysicsMotionController *pController)
{
  IPhysicsMotionController *v2; // edi
  IPhysicsMotionController *v3; // esi
  int i; // eax
  IPredictable_Controller_Independant **m_pMemory; // edx
  bool v6; // zf
  IPredictable_Controller_Independant **v7; // edx

  v2 = pController;
  if ( pController != nullptr )
    v3 = pController - 1;
  else
    v3 = nullptr;
  for ( i = 0; i != this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size; ++i )
  {
    m_pMemory = this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory;
    v6 = m_pMemory[i] == (IPredictable_Controller_Independant *)v3;
    v7 = &m_pMemory[i];
    if ( v6 )
      *v7 = &s_StubPredictableController;
  }
  CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
    this: (CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *)&this->m_motionControllers,
    src: (IPhysicsEnvironment **)&pController);
  if ( v2 != nullptr )
    ((void (__thiscall *)(IPhysicsMotionController *, int))v2->dtr_IPhysicsMotionController)(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10013210
// Name: public: virtual void CPhysicsEnvironment::CleanupDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysicsEnvironment::CleanupDeleteList(CPhysicsEnvironment *this)
{
  CPhysicsEnvironment::ClearDeadObjects(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013220
// Name: public: virtual class IPhysicsObject __near * CPhysicsEnvironment::CreateSphereObject(float,int,class Vector const __near &,class QAngle const __near &,struct objectparams_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPhysicsObject *__thiscall CPhysicsEnvironment::CreateSphereObject(
        CPhysicsEnvironment *this,
        float radius,
        int materialIndex,
        const Vector *position,
        const QAngle *angles,
        objectparams_t *pParams,
        bool isStatic)
{
  CPhysicsObject *PhysicsSphere; // eax
  int m_Size; // edi
  CPhysicsObject *v10; // ebx
  int m_nAllocationCount; // eax
  IPhysicsObject **m_pMemory; // ecx
  int v13; // eax
  IPhysicsObject **v14; // eax

  PhysicsSphere = CreatePhysicsSphere(pEnvironment: this, radius, materialIndex, position, angles, pParams, isStatic);
  m_Size = this->m_objects.m_Size;
  v10 = PhysicsSphere;
  m_nAllocationCount = this->m_objects.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_objects,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_objects.m_Size;
  m_pMemory = this->m_objects.m_Memory.m_pMemory;
  v13 = this->m_objects.m_Size - m_Size - 1;
  this->m_objects.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &this->m_objects.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v10;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x100132B0
// Name: public: virtual void CPhysicsEnvironment::DoneReferencingPreviousCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DoneReferencingPreviousCommands(CPhysicsEnvironment *this, int iCommandNum)
{
  int i; // edi
  IPhysicsPlayerController *v4; // eax
  CPredictedPlayerController *v5; // ecx
  int j; // edi
  IPhysicsMotionController *v7; // eax
  CPredictedPhysicsMotionController *v8; // ecx
  int k; // edi
  int m_Size; // ecx
  int v11; // edi
  CPhysicsEnvironment::PredictedData_t *m_pMemory; // eax

  if ( this->m_bPredicted )
  {
    for ( i = 0; i != this->m_playerControllers.m_Size; ++i )
    {
      v4 = this->m_playerControllers.m_Memory.m_pMemory[i];
      if ( v4 != nullptr )
        v5 = (CPredictedPlayerController *)&v4[-1];
      else
        v5 = nullptr;
      CPredictedPlayerController::DoneReferencingPreviousCommands(this: v5, iCommandNum);
    }
    for ( j = 0; j != this->m_motionControllers.m_Size; ++j )
    {
      v7 = this->m_motionControllers.m_Memory.m_pMemory[j];
      if ( v7 != nullptr )
        v8 = (CPredictedPhysicsMotionController *)&v7[-1];
      else
        v8 = nullptr;
      CPredictedPhysicsMotionController::DoneReferencingPreviousCommands(this: v8, iCommandNum);
    }
    for ( k = 0; k != this->m_objects.m_Size; ++k )
      CPredictedPhysicsObject::DoneReferencingPreviousCommands(
        this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[k],
        iCommandNum);
    m_Size = this->m_PredictionBackups.m_Size;
    v11 = 0;
    if ( m_Size != 0 )
    {
      m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
      while ( m_pMemory->iCommandNum < iCommandNum )
      {
        ++v11;
        ++m_pMemory;
        if ( v11 == m_Size )
          goto LABEL_23;
      }
      if ( v11 > 0 )
      {
        if ( m_Size - v11 > 0 )
          _V_memmove(
            dest: this->m_PredictionBackups.m_Memory.m_pMemory,
            src: &this->m_PredictionBackups.m_Memory.m_pMemory[v11],
            count: 8 * (m_Size - v11));
        this->m_PredictionBackups.m_Size -= v11;
      }
    }
LABEL_23:
    CPredictableControllerSimulationOrderTracker_Manager::DoneReferencingPreviousCommands(
      this: &this->m_PredictedPhysControllerCallOrder,
      iCommandNum);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100133B0
// Name: public: CUtlMultiList<void __near *,unsigned short>::~CUtlMultiList<void __near *,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<void *,unsigned short>::~CUtlMultiList<void *,unsigned short>(
        CUtlMultiList<void *,unsigned short> *this)
{
  CUtlMultiList<void *,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100136B0
// Name: public: virtual void CSleepObjects::event_object_revived(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::event_object_revived(CSleepObjects *this, IVP_Event_Object *pEvent)
{
  CSleepObjects *v2; // edi
  CPhysicsObject *client_data; // ebx
  int v4; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_activeObjects; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  v2 = this;
  client_data = (CPhysicsObject *)pEvent->real_object->client_data;
  if ( client_data != nullptr )
  {
    v4 = *((_BYTE *)client_data + 21) & 3;
    CPhysicsObject::NotifyWake(this: client_data);
    if ( v4 != 1 )
    {
      if ( client_data->m_pObject->flags != 16 )
      {
        if ( client_data->m_activeIndex != 0xFFFF )
          return;
        m_nAllocationCount = v2->m_activeObjects.m_Memory.m_nAllocationCount;
        p_m_activeObjects = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v2->m_activeObjects;
        m_Size = v2->m_activeObjects.m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CPredictedPhysicsObject *,int>::Grow(this: p_m_activeObjects, num: m_Size - m_nAllocationCount + 1);
        ++p_m_activeObjects[1].m_pMemory;
        m_pMemory = p_m_activeObjects->m_pMemory;
        v9 = (int)p_m_activeObjects[1].m_pMemory - m_Size - 1;
        p_m_activeObjects[1].m_nAllocationCount = (int)p_m_activeObjects->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &p_m_activeObjects->m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = (CUtlSymbolTable::StringPool_t *)client_data;
        client_data->m_activeIndex = m_Size;
        v2 = this;
      }
      if ( v2->m_pCallback != nullptr )
        v2->m_pCallback->ObjectWake(this: v2->m_pCallback, a2: client_data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013770
// Name: public: void CSleepObjects::UpdateSleepObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSleepObjects::UpdateSleepObjects(CSleepObjects *this)
{
  int v1; // eax
  int m_Size; // edx
  int m_nAllocationCount; // ecx
  int v5; // esi
  CPhysicsObject *v6; // eax
  bool v7; // zf
  int v8; // ebx
  CPhysicsObject **m_pMemory; // ecx
  CPhysicsObject **v10; // ebx
  int j; // esi
  CPhysicsObject **v12; // ebx
  CPhysicsObject *v13; // ebx
  int m_activeIndex; // eax
  int v15; // edx
  CUtlVector<CPhysicsObject *,CUtlMemory<CPhysicsObject *,int> > sleepObjects; // [esp+Ch] [ebp-20h] BYREF
  int numActiveObjects; // [esp+20h] [ebp-Ch]
  CPhysicsObject *pObject; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v1 = 0;
  m_Size = this->m_activeObjects.m_Size;
  m_nAllocationCount = 0;
  v5 = 0;
  memset(&sleepObjects, 0, sizeof(sleepObjects));
  numActiveObjects = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = this->m_activeObjects.m_Memory.m_pMemory[v1];
      v7 = (*((_BYTE *)v6 + 21) & 3) == 0;
      pObject = v6;
      if ( !v7 )
      {
        v8 = v5;
        if ( v5 + 1 > m_nAllocationCount )
        {
          CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&sleepObjects,
            num: v5 - m_nAllocationCount + 1);
          v5 = sleepObjects.m_Size;
        }
        m_pMemory = sleepObjects.m_Memory.m_pMemory;
        sleepObjects.m_Size = ++v5;
        sleepObjects.m_pElements = sleepObjects.m_Memory.m_pMemory;
        if ( v5 - v8 - 1 > 0 )
        {
          _V_memmove(
            dest: &sleepObjects.m_Memory.m_pMemory[v8 + 1],
            src: &sleepObjects.m_Memory.m_pMemory[v8],
            count: 4 * (v5 - v8 - 1));
          m_pMemory = sleepObjects.m_Memory.m_pMemory;
        }
        v10 = &m_pMemory[v8];
        if ( v10 != nullptr )
          *v10 = pObject;
      }
      v1 = i + 1;
      i = v1;
      if ( v1 >= numActiveObjects )
        break;
      m_nAllocationCount = sleepObjects.m_Memory.m_nAllocationCount;
    }
  }
  for ( j = v5 - 1; j >= 0; --j )
  {
    v12 = sleepObjects.m_Memory.m_pMemory;
    CPhysicsObject::NotifySleep(this: sleepObjects.m_Memory.m_pMemory[j]);
    v13 = v12[j];
    m_activeIndex = v13->m_activeIndex;
    if ( m_activeIndex < this->m_activeObjects.m_Size )
    {
      v15 = this->m_activeObjects.m_Size;
      if ( v15 > 0 )
      {
        if ( m_activeIndex != v15 - 1 )
          this->m_activeObjects.m_Memory.m_pMemory[m_activeIndex] = this->m_activeObjects.m_Memory.m_pMemory[v15 - 1];
        --this->m_activeObjects.m_Size;
      }
      if ( m_activeIndex < this->m_activeObjects.m_Size )
        this->m_activeObjects.m_Memory.m_pMemory[m_activeIndex]->m_activeIndex = m_activeIndex;
      v13->m_activeIndex = -1;
    }
  }
  if ( sleepObjects.m_Memory.m_nGrowSize >= 0 && sleepObjects.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sleepObjects.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100138D0
// Name: private: bool CCollisionSolver::CheckObjPair(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionSolver::CheckObjPair(CCollisionSolver *this, IVP_Real_Object *pObj0, IVP_Real_Object *pObj1)
{
  IVP_Real_Object *v3; // ebx
  IVP_Real_Object *v4; // edi
  int m_Size; // esi
  CUtlVector<CCollisionSolver::realobjectpair_t,CUtlMemory<CCollisionSolver::realobjectpair_t,int> > *p_m_rescue; // ecx
  int v7; // eax
  CCollisionSolver::realobjectpair_t *m_pMemory; // edx
  CCollisionSolver::realobjectpair_t tmp; // [esp+Ch] [ebp-8h] BYREF

  v3 = pObj0;
  if ( pObj0 >= pObj1 )
    v3 = pObj1;
  tmp.pObj0 = v3;
  v4 = pObj0;
  if ( pObj0 <= pObj1 )
    v4 = pObj1;
  m_Size = this->m_rescue.m_Size;
  p_m_rescue = &this->m_rescue;
  v7 = 0;
  tmp.pObj1 = v4;
  if ( m_Size > 0 )
  {
    m_pMemory = p_m_rescue->m_Memory.m_pMemory;
    while ( m_pMemory->pObj0 != v3 || m_pMemory->pObj1 != v4 )
    {
      ++v7;
      ++m_pMemory;
      if ( v7 >= m_Size )
        goto LABEL_10;
    }
    if ( v7 != -1 )
      return 1;
  }
LABEL_10:
  CUtlVector<CPhysicsEnvironment::PredictedData_t,CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>>::InsertBefore(
    this: p_m_rescue,
    elem: m_Size,
    src: &tmp);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013980
// Name: public: virtual class IPhysicsFluidController __near * CPhysicsEnvironment::CreateFluidController(class IPhysicsObject __near *,struct fluidparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsFluidController *__thiscall CPhysicsEnvironment::CreateFluidController(
        CPhysicsEnvironment *this,
        CPhysicsObject *pFluidObject,
        fluidparams_t *pParams)
{
  CPhysicsFluidController *FluidController; // eax
  int m_Size; // edi
  CPhysicsFluidController *v6; // ebx
  int m_nAllocationCount; // eax
  CPhysicsFluidController **m_pMemory; // ecx
  int v9; // eax
  CPhysicsFluidController **v10; // eax

  FluidController = CreateFluidController(pEnvironment: this->m_pPhysEnv, pFluidObject, pParams);
  m_Size = this->m_fluids.m_Size;
  v6 = FluidController;
  m_nAllocationCount = this->m_fluids.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_fluids,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_fluids.m_Size;
  m_pMemory = this->m_fluids.m_Memory.m_pMemory;
  v9 = this->m_fluids.m_Size - m_Size - 1;
  this->m_fluids.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_fluids.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v6;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10013A00
// Name: public: virtual void CPhysicsEnvironment::DestroyCollideOnDeadObjectFlush(class CPhysCollide __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyCollideOnDeadObjectFlush(CPhysicsEnvironment *this, CPhysCollide *pCollide)
{
  int v3; // esi
  IPhysicsObject *v4; // ecx
  int v5; // eax
  CPhysCollide **v6; // ecx
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_deadObjectCollides; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v11; // eax
  CUtlSymbolTable::StringPool_t **v12; // eax

  v3 = this->m_deadObjects.m_Size - 1;
  if ( v3 < 0 )
  {
LABEL_4:
    physcollision->DestroyCollide(this: physcollision, a2: pCollide);
  }
  else
  {
    while ( 1 )
    {
      v4 = this->m_deadObjects.m_Memory.m_pMemory[v3];
      if ( v4->GetCollide(this: v4) == pCollide )
        break;
      if ( --v3 < 0 )
        goto LABEL_4;
    }
    v5 = this->m_deadObjectCollides.m_Size - 1;
    if ( v5 < 0 )
    {
LABEL_10:
      m_nAllocationCount = this->m_deadObjectCollides.m_Memory.m_nAllocationCount;
      p_m_deadObjectCollides = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_deadObjectCollides;
      m_Size = this->m_deadObjectCollides.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
          this: p_m_deadObjectCollides,
          num: m_Size - m_nAllocationCount + 1);
      ++p_m_deadObjectCollides[1].m_pMemory;
      m_pMemory = p_m_deadObjectCollides->m_pMemory;
      v11 = (int)p_m_deadObjectCollides[1].m_pMemory - m_Size - 1;
      p_m_deadObjectCollides[1].m_nAllocationCount = (int)p_m_deadObjectCollides->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
      v12 = &p_m_deadObjectCollides->m_pMemory[m_Size];
      if ( v12 != nullptr )
        *v12 = (CUtlSymbolTable::StringPool_t *)pCollide;
    }
    else
    {
      v6 = &this->m_deadObjectCollides.m_Memory.m_pMemory[v5];
      while ( *v6 != pCollide )
      {
        v6 -= 2;
        v5 -= 2;
        if ( v5 < 0 )
          goto LABEL_10;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013AC0
// Name: public: void CPhysicsEnvironment::AddPlayerController(class IPhysicsPlayerController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::AddPlayerController(
        CPhysicsEnvironment *this,
        IPhysicsPlayerController *pController)
{
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_playerControllers; // esi
  int m_Size; // ecx
  int v4; // eax
  IPhysicsPlayerController **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbolTable::StringPool_t **v8; // ecx
  int v9; // eax
  CUtlSymbolTable::StringPool_t **v10; // eax

  p_m_playerControllers = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_playerControllers;
  m_Size = this->m_playerControllers.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (IPhysicsPlayerController **)p_m_playerControllers->m_pMemory;
  while ( *m_pMemory != pController )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_playerControllers->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(this: p_m_playerControllers, num: m_Size - m_nAllocationCount + 1);
    ++p_m_playerControllers[1].m_pMemory;
    v8 = p_m_playerControllers->m_pMemory;
    v9 = (int)p_m_playerControllers[1].m_pMemory - v7 - 1;
    p_m_playerControllers[1].m_nAllocationCount = (int)p_m_playerControllers->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_playerControllers->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = (CUtlSymbolTable::StringPool_t *)pController;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013B40
// Name: public: virtual class IPhysicsPlayerController __near * CPhysicsEnvironment::CreatePlayerController(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsPlayerController *__thiscall CPhysicsEnvironment::CreatePlayerController(
        CPhysicsEnvironment *this,
        CPhysicsObject *pObject)
{
  bool v3; // al
  IPhysicsPlayerController *PlayerController; // edi
  IPhysicsPlayerController *v5; // ecx

  v3 = this->IsPredicted(this);
  PlayerController = CreatePlayerController(pObject, bPredicted: v3);
  CPhysicsEnvironment::AddPlayerController(this, pController: PlayerController);
  if ( this->IsPredicted(this) )
  {
    if ( PlayerController != nullptr )
      v5 = PlayerController - 1;
    else
      v5 = nullptr;
    v5->GetShadowVelocity(this: v5, a2: (Vector *)&this->m_PredictedPhysControllerCallOrder);
  }
  return PlayerController;
}

//------------------------------------------------------------------------------
// Address: 0x10013BA0
// Name: public: virtual class IPhysicsMotionController __near * CPhysicsEnvironment::CreateMotionController(class IMotionEvent __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsMotionController *__thiscall CPhysicsEnvironment::CreateMotionController(
        CPhysicsEnvironment *this,
        IPhysicsMotionController *pHandler)
{
  bool v3; // al
  IPhysicsMotionController *MotionController; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IPhysicsMotionController **m_pMemory; // ecx
  int v8; // eax
  IPhysicsMotionController **v9; // edi
  IPhysicsMotionController *v10; // ecx
  IPhysicsMotionController *pController; // [esp+14h] [ebp+8h]

  v3 = this->IsPredicted(this);
  MotionController = CreateMotionController(pPhysEnv: this, (IMotionEvent *)pHandler, bPredicted: v3);
  m_Size = this->m_motionControllers.m_Size;
  pController = MotionController;
  m_nAllocationCount = this->m_motionControllers.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_motionControllers,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_motionControllers.m_Size;
  m_pMemory = this->m_motionControllers.m_Memory.m_pMemory;
  v8 = this->m_motionControllers.m_Size - m_Size - 1;
  this->m_motionControllers.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_motionControllers.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = pController;
  if ( !this->IsPredicted(this) )
    return pController;
  if ( pController != nullptr )
    v10 = pController - 1;
  else
    v10 = nullptr;
  ((void (__thiscall *)(IPhysicsMotionController *, CPredictableControllerSimulationOrderTracker_Manager *))v10->__vftable[1].dtr_IPhysicsMotionController)(
    a1: v10,
    a2: &this->m_PredictedPhysControllerCallOrder);
  return pController;
}

//------------------------------------------------------------------------------
// Address: 0x10013C70
// Name: public: CObjectPairHash::CObjectPairHash(void)
// Source: json
//------------------------------------------------------------------------------
CObjectPairHash *__thiscall CObjectPairHash::CObjectPairHash(CObjectPairHash *this)
{
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  CUtlMultiList<void *,unsigned short>::ListElem_t *v3; // eax
  IVP_VHash_Store *v4; // eax

  this->__vftable = (CObjectPairHash_vtbl *)&CObjectPairHash::`vftable';
  IVP_Collision_Filter_Exclusive_Pair::IVP_Collision_Filter_Exclusive_Pair(this: &this->m_pairHash);
  this->m_pairHash.__vftable = (CVoidPairHash_vtbl *)&CVoidPairHash::`vftable';
  this->m_objectList.m_Memory.m_pMemory = nullptr;
  this->m_objectList.m_Memory.m_nAllocationCount = 0;
  this->m_objectList.m_Memory.m_nGrowSize = 0;
  this->m_objectList.m_List.m_Memory.m_pMemory = nullptr;
  this->m_objectList.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_objectList.m_List.m_Memory.m_nGrowSize = 0;
  this->m_objectList.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_objectList.m_List.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_objectList.m_List.m_Head = -1;
  this->m_objectList.m_List.m_pElements = m_pMemory;
  this->m_objectList.m_List.m_NumAlloced = 0;
  v3 = this->m_objectList.m_Memory.m_pMemory;
  this->m_objectList.m_pElementList = nullptr;
  *(_DWORD *)&this->m_objectList.m_FirstFree = 0xFFFF;
  this->m_objectList.m_MaxElementIndex = 0;
  this->m_objectList.m_pElements = v3;
  v4 = (IVP_VHash_Store *)p_malloc(size: 0x14u);
  if ( v4 != nullptr )
    this->m_pObjectHash = IVP_VHash_Store::IVP_VHash_Store(this: v4, size_i: 1024);
  else
    this->m_pObjectHash = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013D00
// Name: public: virtual bool CObjectPairHash::IsObjectPairInHash(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CObjectPairHash::IsObjectPairInHash(
        CObjectPairHash *this,
        IVP_Real_Object *pObject0,
        IVP_Real_Object *pObject1)
{
  return this->m_pairHash.check_objects_for_collision_detection(this: &this->m_pairHash, a2: pObject0, a3: pObject1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013D20
// Name: public: virtual bool CObjectPairHash::IsObjectInHash(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CObjectPairHash::IsObjectInHash(CObjectPairHash *this, void *pObject0)
{
  return IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10013D40
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013DF0
// Name: public: unsigned short CUtlMultiList<void __near *,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<void *,unsigned short>::Alloc(CUtlMultiList<void *,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
    goto LABEL_13;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<void *,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<void *,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>::Grow(this: &this->m_Memory, num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    return result;
  }
  if ( `CUtlMultiList<void *,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<void *,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10013EB0
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<void __near *,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<void __near *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *)this,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10014030
// Name: public: virtual int CObjectPairHash::GetPairCountForObject(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectPairHash::GetPairCountForObject(CObjectPairHash *this, void *pObject0)
{
  void *elem; // eax
  unsigned __int16 v4; // dx
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  unsigned int v6; // ecx
  int result; // eax
  unsigned __int16 m_Head; // cx
  CUtlMultiList<void *,unsigned short>::ListElem_t *v9; // esi

  elem = IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject0);
  v4 = -1;
  if ( elem != nullptr )
    v4 = (unsigned __int16)elem;
  if ( v4 >= this->m_objectList.m_List.m_Memory.m_nAllocationCount )
    return 0;
  if ( v4 > this->m_objectList.m_List.m_LastAlloc.index )
    return 0;
  m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
  v6 = v4;
  if ( m_pMemory[v6].m_Previous == v4 && m_pMemory[v6].m_Next != v4 )
    return 0;
  m_Head = this->m_objectList.m_List.m_Memory.m_pMemory[v6].m_Element.m_Head;
  result = 0;
  if ( m_Head != 0xFFFF )
  {
    v9 = this->m_objectList.m_Memory.m_pMemory;
    do
    {
      m_Head = v9[m_Head].m_Next;
      ++result;
    }
    while ( m_Head != 0xFFFF );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100140B0
// Name: public: virtual int CObjectPairHash::GetPairListForObject(void __near *,int,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CObjectPairHash::GetPairListForObject(
        CObjectPairHash *this,
        void *pObject0,
        int nMaxCount,
        void **ppObjectList)
{
  void *elem; // eax
  unsigned __int16 v6; // dx
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  unsigned int v8; // ecx
  int result; // eax
  unsigned __int16 m_Head; // cx
  int v11; // ecx

  elem = IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject0);
  v6 = -1;
  if ( elem != nullptr )
    v6 = (unsigned __int16)elem;
  if ( v6 >= this->m_objectList.m_List.m_Memory.m_nAllocationCount )
    return 0;
  if ( v6 > this->m_objectList.m_List.m_LastAlloc.index )
    return 0;
  m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
  v8 = v6;
  if ( m_pMemory[v8].m_Previous == v6 && m_pMemory[v8].m_Next != v6 )
    return 0;
  m_Head = this->m_objectList.m_List.m_Memory.m_pMemory[v8].m_Element.m_Head;
  for ( result = 0; m_Head != 0xFFFF; m_Head = this->m_objectList.m_Memory.m_pMemory[v11].m_Next )
  {
    v11 = m_Head;
    ppObjectList[result++] = this->m_objectList.m_Memory.m_pMemory[v11].m_Element;
    if ( result >= nMaxCount )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014150
// Name: public: void CUtlMultiList<void __near *,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<void *,unsigned short>::Unlink(
        CUtlMultiList<void *,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  CUtlMultiList<void *,unsigned short>::ListElem_t *m_pMemory; // edx
  unsigned __int16 *p_m_Previous; // esi
  int v5; // edi
  unsigned __int16 *p_m_Next; // eax
  unsigned __int16 v7; // bx
  int v8; // edx
  unsigned __int16 v9; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx

  if ( elem < this->m_MaxElementIndex )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      p_m_Previous = &m_pMemory[elem].m_Previous;
      v5 = *p_m_Previous;
      p_m_Next = &m_pMemory[elem].m_Next;
      v7 = *p_m_Next;
      if ( (_WORD)v5 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = v7;
      else
        m_pMemory[v5].m_Next = v7;
      v8 = *p_m_Next;
      v9 = *p_m_Previous;
      if ( (_WORD)v8 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v9;
      else
        this->m_Memory.m_pMemory[v8].m_Previous = v9;
      *p_m_Next = elem;
      *p_m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elem] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014210
// Name: public: void CUtlMultiList<void __near *,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<void *,unsigned short>::LinkBefore(
        CUtlMultiList<void *,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<void *,unsigned short>::ListElem_t *v5; // ecx
  int v6; // eax
  CUtlMultiList<void *,unsigned short>::ListElem_t *v7; // eax
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<void *,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x100142D0
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v5; // ecx
  unsigned __int16 m_Tail; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v7; // ebx

  CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = &m_pMemory[before];
    m_Tail = v7->m_Previous;
    v5->m_Previous = m_Tail;
    v7->m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014360
// Name: public: void CUtlMultiList<void __near *,unsigned short>::RemoveAll(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<void *,unsigned short>::RemoveAll(
        CUtlMultiList<void *,unsigned short> *this,
        unsigned __int16 list)
{
  unsigned __int16 m_Head; // di
  CUtlMultiList<void *,unsigned short>::ListElem_t *v4; // ecx
  unsigned __int16 m_Next; // ax
  unsigned __int16 next; // [esp+8h] [ebp-4h]

  m_Head = this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = &this->m_Memory.m_pMemory[m_Head];
      m_Next = v4->m_Next;
      next = m_Next;
      if ( m_Head < this->m_MaxElementIndex && v4->m_Previous != m_Head )
      {
        CUtlMultiList<void *,unsigned short>::Unlink(this, list, elem: m_Head);
        m_Next = next;
      }
      this->m_Memory.m_pMemory[m_Head].m_Next = this->m_FirstFree;
      --this->m_TotalElements;
      this->m_FirstFree = m_Head;
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014440
// Name: class IPhysicsObjectPairHash __near * CreateObjectPairHash(void)
// Source: json
//------------------------------------------------------------------------------
CObjectPairHash *__cdecl CreateObjectPairHash()
{
  CObjectPairHash *v0; // eax

  v0 = (CObjectPairHash *)p_malloc(size: 0x48u);
  if ( v0 != nullptr )
    return CObjectPairHash::CObjectPairHash(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014460
// Name: public: void CPredictableControllerSimulationOrderTracker::RegisterSimulation(class IPredictable_Controller_Independant __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictableControllerSimulationOrderTracker::RegisterSimulation(
        CPredictableControllerSimulationOrderTracker *this,
        IPredictable_Controller_Independant *pController)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IPredictable_Controller_Independant **m_pMemory; // ecx
  int v6; // eax
  IPredictable_Controller_Independant **v7; // eax

  m_nAllocationCount = this->m_CallOrder.m_Memory.m_nAllocationCount;
  m_Size = this->m_CallOrder.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_CallOrder.m_Size;
  m_pMemory = this->m_CallOrder.m_Memory.m_pMemory;
  v6 = this->m_CallOrder.m_Size - m_Size - 1;
  this->m_CallOrder.m_pElements = this->m_CallOrder.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_CallOrder.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pController;
}

//------------------------------------------------------------------------------
// Address: 0x100145B0
// Name: public: void CDeleteQueue::QueueForDelete<class IPhysicsConstraint>(class IPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDeleteQueue::QueueForDelete<IPhysicsConstraint>(CDeleteQueue *this, IPhysicsConstraint *pItem)
{
  IDeleteQueueItem *v3; // eax
  IDeleteQueueItem *v4; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IDeleteQueueItem **m_pMemory; // ecx
  int v8; // eax
  IDeleteQueueItem **v9; // eax

  v3 = (IDeleteQueueItem *)p_malloc(size: 8u);
  if ( v3 != nullptr )
  {
    v3->__vftable = (IDeleteQueueItem_vtbl *)&CDeleteProxy<IPhysicsConstraint>::`vftable';
    v3[1].__vftable = (IDeleteQueueItem_vtbl *)pItem;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  m_nAllocationCount = this->m_list.m_Memory.m_nAllocationCount;
  m_Size = this->m_list.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_list.m_Size;
  m_pMemory = this->m_list.m_Memory.m_pMemory;
  v8 = this->m_list.m_Size - m_Size - 1;
  this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_list.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10014630
// Name: private: void CPhysicsListenerCollision::UpdatePairListPSI(class CPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::UpdatePairListPSI(
        CPhysicsListenerCollision *this,
        CPhysicsEnvironment *pEnvironment)
{
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *p_m_pairList; // esi
  unsigned __int16 Inorder; // bx
  int *v4; // eax
  unsigned int v5; // edi
  IVP_Time currentTime; // [esp+Ch] [ebp-Ch]
  unsigned __int16 next; // [esp+20h] [ebp+8h]

  p_m_pairList = &this->m_pairList;
  Inorder = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_pairList);
  *(IVP_Time *)&currentTime.seconds = pEnvironment->m_pPhysEnv->current_time;
  while ( Inorder < p_m_pairList->m_Elements.m_nAllocationCount && Inorder <= p_m_pairList->m_LastAlloc.index )
  {
    if ( (`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_100FC8CC = 0x1FFFF;
    }
    v4 = Inorder == 0xFFFF
       ? &`CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&p_m_pairList->m_Elements.m_pMemory[Inorder];
    if ( *(_WORD *)v4 == Inorder )
      break;
    v5 = Inorder;
    next = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::NextInorder(
             this: p_m_pairList,
             i: Inorder);
    if ( (float)(currentTime.seconds - this->m_pairList.m_Elements.m_pMemory[v5].m_Data.lastImpactTime.seconds) > 1.0
      && Inorder != 0xFFFF )
    {
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_pairList,
        elem: Inorder);
      p_m_pairList->m_Elements.m_pMemory[v5].m_Left = Inorder;
      p_m_pairList->m_Elements.m_pMemory[v5].m_Right = p_m_pairList->m_FirstFree;
      --p_m_pairList->m_NumElements;
      p_m_pairList->m_FirstFree = Inorder;
    }
    Inorder = next;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014740
// Name: public: CPhysicsListenerCollision::CPhysicsListenerCollision(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsListenerCollision *__thiscall CPhysicsListenerCollision::CPhysicsListenerCollision(
        CPhysicsListenerCollision *this)
{
  CPhysicsListenerCollision *result; // eax

  result = this;
  this->enabled_callbacks = 13;
  this->IVP_Listener_Phantom::__vftable = (IVP_Listener_Phantom_vtbl *)&IVP_Listener_Phantom::`vftable';
  this->IVP_Listener_Collision::__vftable = (CPhysicsListenerCollision_vtbl *)&CPhysicsListenerCollision::`vftable'{for `IVP_Listener_Collision'};
  this->IVP_Listener_Phantom::__vftable = (IVP_Listener_Phantom_vtbl *)&CPhysicsListenerCollision::`vftable'{for `IVP_Listener_Phantom'};
  this->m_pairList.m_LessFunc = nullptr;
  this->m_pairList.m_Elements.m_pMemory = nullptr;
  this->m_pairList.m_Elements.m_nAllocationCount = 0;
  this->m_pairList.m_Elements.m_nGrowSize = 0;
  this->m_pairList.m_Root = -1;
  this->m_pairList.m_NumElements = 0;
  this->m_pairList.m_FirstFree = -1;
  this->m_pairList.m_LastAlloc.index = -1;
  this->m_pairList.m_pElements = this->m_pairList.m_Elements.m_pMemory;
  this->m_pCallback = &g_EmptyCollisionListener;
  if ( this->m_pairList.m_LessFunc == nullptr )
    this->m_pairList.m_LessFunc = (bool (__cdecl *)(const CPhysicsListenerCollision::corepair_t *, const CPhysicsListenerCollision::corepair_t *))CPhysicsListenerCollision::CorePairLessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100147B0
// Name: public: virtual void CPhysicsCollisionData::GetSurfaceNormal(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollisionData::GetSurfaceNormal(CPhysicsCollisionData *this, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v3; // xmm0_4

  m_pContact = this->m_pContact;
  v3 = m_pContact->surf_normal.k[2];
  LODWORD(out->z) = LODWORD(m_pContact->surf_normal.k[1]) ^ _mask__NegFloat_;
  out->y = v3;
  out->x = m_pContact->surf_normal.k[0];
}

//------------------------------------------------------------------------------
// Address: 0x100147E0
// Name: public: virtual void CPhysicsCollisionData::GetContactPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollisionData::GetContactPoint(CPhysicsCollisionData *this, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v3; // xmm0_4

  m_pContact = this->m_pContact;
  v3 = m_pContact->contact_point_ws.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pContact->contact_point_ws.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                  ^ _mask__NegFloat_;
  out->y = v3;
  out->x = m_pContact->contact_point_ws.k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10014830
// Name: public: virtual void CPhysicsCollisionData::GetContactSpeed(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCollisionData::GetContactSpeed(CPhysicsCollisionData *this, Vector *out)
{
  const IVP_Contact_Situation *m_pContact; // eax
  float v3; // xmm0_4

  m_pContact = this->m_pContact;
  v3 = m_pContact->speed.k[2] * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(out->z) = COERCE_UNSIGNED_INT(m_pContact->speed.k[1] * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
  out->y = v3;
  out->x = m_pContact->speed.k[0] * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x10014880
// Name: public: virtual void CPhysicsListenerCollision::event_pre_collision(class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_pre_collision(
        CPhysicsListenerCollision *this,
        IVP_Event_Collision *pEvent)
{
  IVP_Contact_Situation *contact_situation; // ecx
  IPhysicsObject *client_data; // eax
  IPhysicsObject *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // ebx
  bool v8; // dl
  float d_time_since_last_collision; // xmm0_4
  IVP_Contact_Situation *v10; // eax
  int *surfaceProps; // edi
  const IVP_Material **materials; // ebx
  int v13; // eax
  CPhysicsCollisionData data; // [esp+8h] [ebp-14h] BYREF
  vcollisionevent_t *p_m_event; // [esp+10h] [ebp-Ch]
  IVP_Contact_Situation *contact; // [esp+14h] [ebp-8h]
  unsigned int flags1; // [esp+18h] [ebp-4h]
  int pEventa; // [esp+24h] [ebp+8h]

  *(_WORD *)&this->m_event.isCollision = 0;
  contact_situation = pEvent->contact_situation;
  client_data = (IPhysicsObject *)contact_situation->objects[0]->client_data;
  contact = contact_situation;
  v5 = (IPhysicsObject *)contact_situation->objects[1]->client_data;
  if ( client_data != nullptr && v5 != nullptr )
  {
    v6 = LOWORD(v5[7].__vftable);
    flags1 = LOWORD(client_data[7].__vftable);
    v7 = flags1;
    this->m_event.isCollision = ((unsigned __int8)flags1 & (unsigned __int8)v6 & 1) != 0;
    v8 = ((v7 >> 4) ^ (v6 >> 4)) & 1;
    this->m_event.pObjects[0] = client_data;
    this->m_event.isShadowCollision = v8;
    this->m_event.pObjects[1] = v5;
    d_time_since_last_collision = pEvent->d_time_since_last_collision;
    p_m_event = &this->m_event;
    this->m_event.deltaCollisionTime = d_time_since_last_collision;
    if ( d_time_since_last_collision > 999.0 )
      this->m_event.deltaCollisionTime = 1.0;
    v10 = contact;
    data.__vftable = (CPhysicsCollisionData_vtbl *)&CPhysicsCollisionData::`vftable';
    data.m_pContact = contact;
    this->m_event.pInternalData = &data;
    if ( v10->objects[0]->flags == 16 && (v6 & 0x20) == 0 )
      this->m_event.isCollision = false;
    if ( v10->objects[1]->flags == 16 && (flags1 & 0x20) == 0 )
      this->m_event.isCollision = false;
    if ( this->m_event.isCollision || v8 )
    {
      surfaceProps = this->m_event.surfaceProps;
      materials = (const IVP_Material **)v10->materials;
      for ( pEventa = 2; pEventa != 0; --pEventa )
      {
        v13 = physprops->GetIVPMaterialIndex(this: physprops, a2: *materials);
        *surfaceProps = v13;
        if ( v13 < 0 )
          *surfaceProps = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*(surfaceProps - 2) + 152))(a1: *(surfaceProps - 2));
        ++materials;
        ++surfaceProps;
      }
      this->m_pCallback->PreCollision(this: this->m_pCallback, a2: p_m_event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100149B0
// Name: public: virtual void CPhysicsListenerCollision::event_post_collision(class IVP_Event_Collision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_post_collision(
        CPhysicsListenerCollision *this,
        IVP_Event_Collision *pEvent)
{
  IVP_Contact_Situation *contact_situation; // eax
  float v3; // xmm0_4
  IPhysicsCollisionEvent *m_pCallback; // eax
  CPhysicsCollisionData data; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_event.isCollision || this->m_event.isShadowCollision )
  {
    contact_situation = pEvent->contact_situation;
    v3 = COERCE_FLOAT(
           COERCE_UNSIGNED_INT(
             (float)((float)(contact_situation->surf_normal.k[1] * contact_situation->speed.k[1])
                   + (float)(contact_situation->surf_normal.k[0] * contact_situation->speed.k[0]))
           + (float)(contact_situation->surf_normal.k[2] * contact_situation->speed.k[2]))
         & _mask__AbsFloat_)
       * g_PhysicsUnits.unitScaleMetersInv;
    data.m_pContact = contact_situation;
    m_pCallback = this->m_pCallback;
    this->m_event.collisionSpeed = v3;
    this->m_event.pInternalData = &data;
    data.__vftable = (CPhysicsCollisionData_vtbl *)&CPhysicsCollisionData::`vftable';
    m_pCallback->PostCollision(this: m_pCallback, a2: &this->m_event);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014A30
// Name: public: virtual void CPhysicsListenerCollision::event_friction_created(class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_friction_created(
        CPhysicsListenerCollision *this,
        IVP_Event_Friction *pEvent)
{
  IVP_Contact_Situation *contact_situation; // eax
  IVP_Real_Object *v4; // edx
  _WORD *client_data; // esi
  IPhysicsObject *v6; // edi
  IVP_Contact_Situation *v7; // edx
  IPhysicsCollisionEvent *m_pCallback; // ecx
  CPhysicsFrictionData data; // [esp+Ch] [ebp-14h] BYREF
  CPhysicsListenerCollision *v10; // [esp+1Ch] [ebp-4h]
  __int16 allflags; // [esp+28h] [ebp+8h]

  contact_situation = pEvent->contact_situation;
  v4 = contact_situation->objects[1];
  v10 = this;
  client_data = contact_situation->objects[0]->client_data;
  v6 = (IPhysicsObject *)v4->client_data;
  if ( client_data != nullptr && v6 != nullptr )
  {
    allflags = client_data[14] | LOWORD(v6[7].__vftable);
    if ( (*(unsigned __int8 (__thiscall **)(_WORD *))(*(_DWORD *)client_data + 4))(a1: client_data) == 0
      || !v6->IsStatic(this: v6) )
    {
      if ( (client_data[10] & 0x20) == 0 && v6->IsMoveable(this: v6) )
        *((_BYTE *)client_data + 20) |= 0x20u;
      if ( ((int)v6[5].__vftable & 0x20) == 0
        && (*(unsigned __int8 (__thiscall **)(_WORD *))(*(_DWORD *)client_data + 40))(a1: client_data) != 0 )
      {
        LOBYTE(v6[5].__vftable) |= 0x20u;
      }
    }
    if ( (allflags & 4) != 0
      && ((*(unsigned __int8 (__thiscall **)(_WORD *))(*(_DWORD *)client_data + 4))(a1: client_data) == 0
       && !v6->IsStatic(this: v6)
       || (allflags & 8) != 0) )
    {
      v7 = pEvent->contact_situation;
      data.m_pPoint = pEvent->friction_handle;
      m_pCallback = v10->m_pCallback;
      data.m_pContact = v7;
      data.__vftable = (CPhysicsFrictionData_vtbl *)&CPhysicsFrictionData::`vftable';
      data.m_sign = 1.0;
      m_pCallback->StartTouch(this: m_pCallback, a2: (IPhysicsObject *)client_data, a3: v6, a4: &data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014B20
// Name: public: virtual void CPhysicsListenerCollision::event_friction_deleted(class IVP_Event_Friction __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_friction_deleted(
        CPhysicsListenerCollision *this,
        IVP_Event_Friction *pEvent)
{
  IVP_Contact_Situation *contact_situation; // eax
  IVP_Real_Object *v3; // edx
  IPhysicsObject *client_data; // esi
  IPhysicsObject *v5; // edi
  __int16 v6; // bx
  IVP_Contact_Situation *v7; // edx
  IPhysicsCollisionEvent *m_pCallback; // ecx
  CPhysicsFrictionData data; // [esp+8h] [ebp-14h] BYREF
  CPhysicsListenerCollision *v10; // [esp+18h] [ebp-4h]

  contact_situation = pEvent->contact_situation;
  v3 = contact_situation->objects[1];
  v10 = this;
  client_data = (IPhysicsObject *)contact_situation->objects[0]->client_data;
  v5 = (IPhysicsObject *)v3->client_data;
  if ( client_data != nullptr && v5 != nullptr )
  {
    v6 = LOWORD(client_data[7].__vftable) | LOWORD(v5[7].__vftable);
    if ( (v6 & 4) != 0 && (!client_data->IsStatic(this: client_data) && !v5->IsStatic(this: v5) || (v6 & 8) != 0) )
    {
      v7 = pEvent->contact_situation;
      data.m_pPoint = pEvent->friction_handle;
      m_pCallback = v10->m_pCallback;
      data.m_pContact = v7;
      data.__vftable = (CPhysicsFrictionData_vtbl *)&CPhysicsFrictionData::`vftable';
      data.m_sign = 1.0;
      m_pCallback->EndTouch(this: m_pCallback, a2: client_data, a3: v5, a4: &data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014BC0
// Name: public: virtual void CPhysicsListenerCollision::core_entered_volume(class IVP_Controller_Phantom __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::core_entered_volume(
        CPhysicsListenerCollision *this,
        IVP_Controller_Phantom *controller,
        IVP_Core *pCore)
{
  int v3; // eax
  void *client_data; // edx

  v3 = *((_DWORD *)*pCore->objects.elems + 40);
  if ( v3 != 0 )
  {
    if ( controller->client_data != nullptr )
    {
      if ( (*(_WORD *)(v3 + 28) & 0x100) != 0 )
        (*(void (__thiscall **)(UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *, int, void *))(*(_DWORD *)this->m_pairList.m_pElements + 20))(
          a1: this->m_pairList.m_pElements,
          a2: v3,
          a3: controller->client_data);
    }
    else
    {
      client_data = controller->object->client_data;
      if ( client_data != nullptr )
        (*(void (__thiscall **)(UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *, void *, _DWORD))(*(_DWORD *)this->m_pairList.m_pElements + 32))(
          a1: this->m_pairList.m_pElements,
          a2: client_data,
          a3: *((_DWORD *)*pCore->objects.elems + 40));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014C20
// Name: public: virtual void CPhysicsListenerCollision::core_left_volume(class IVP_Controller_Phantom __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::core_left_volume(
        CPhysicsListenerCollision *this,
        IVP_Controller_Phantom *controller,
        IVP_Core *pCore)
{
  int v3; // eax
  void *client_data; // edx

  v3 = *((_DWORD *)*pCore->objects.elems + 40);
  if ( v3 != 0 )
  {
    if ( controller->client_data != nullptr )
    {
      if ( (*(_WORD *)(v3 + 28) & 0x100) != 0 )
        (*(void (__thiscall **)(UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *, int, void *))(*(_DWORD *)this->m_pairList.m_pElements + 24))(
          a1: this->m_pairList.m_pElements,
          a2: v3,
          a3: controller->client_data);
    }
    else
    {
      client_data = controller->object->client_data;
      if ( client_data != nullptr )
        (*(void (__thiscall **)(UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *, void *, _DWORD))(*(_DWORD *)this->m_pairList.m_pElements + 36))(
          a1: this->m_pairList.m_pElements,
          a2: client_data,
          a3: *((_DWORD *)*pCore->objects.elems + 40));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014C80
// Name: public: virtual void CPhysicsListenerCollision::event_friction_pair_created(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_friction_pair_created(
        CPhysicsListenerCollision *this,
        IVP_Friction_Core_Pair *pair)
{
  bool v2; // cf
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *p_m_pairList; // ebx
  unsigned int seconds_low; // edx
  unsigned __int16 v5; // ax
  int v6; // edi
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // ecx
  CPhysicsListenerCollision::corepair_t test; // [esp+Ch] [ebp-14h] BYREF
  CPhysicsListenerCollision *v9; // [esp+1Ch] [ebp-4h]

  v2 = pair->objs[0] < pair->objs[1];
  v9 = this;
  test.core0 = pair->objs[-v2 + 1];
  p_m_pairList = &this->m_pairList;
  seconds_low = LODWORD(pair->last_impact_time_pair.seconds);
  test.core1 = pair->objs[v2];
  *(_QWORD *)&test.lastImpactTime.seconds = __PAIR64__(HIDWORD(pair->last_impact_time_pair.seconds), seconds_low);
  v5 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_pairList,
         search: &test);
  v6 = v5;
  if ( v5 >= p_m_pairList->m_Elements.m_nAllocationCount
    || v5 > p_m_pairList->m_LastAlloc.index
    || CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
         this: p_m_pairList,
         i: v5) == v5 )
  {
    if ( v9->m_pairList.m_NumElements < 0x10u )
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Insert(
        this: p_m_pairList,
        insert: &test);
  }
  else
  {
    m_pMemory = v9->m_pairList.m_Elements.m_pMemory;
    if ( m_pMemory[v6].m_Data.lastImpactTime.seconds <= pair->last_impact_time_pair.seconds )
      m_pMemory[v6].m_Data.lastImpactTime.seconds = pair->last_impact_time_pair.seconds;
    else
      pair->last_impact_time_pair.seconds = m_pMemory[v6].m_Data.lastImpactTime.seconds;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014D60
// Name: public: virtual void CPhysicsListenerCollision::event_friction_pair_deleted(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsListenerCollision::event_friction_pair_deleted(
        CPhysicsListenerCollision *this,
        IVP_Friction_Core_Pair *pair)
{
  bool v2; // cf
  CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl*)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short> > *p_m_pairList; // ebx
  unsigned int seconds_low; // edx
  int v5; // edi
  UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short> *m_pMemory; // ecx
  CPhysicsListenerCollision::corepair_t test; // [esp+Ch] [ebp-14h] BYREF
  CPhysicsListenerCollision *v8; // [esp+1Ch] [ebp-4h]

  v2 = pair->objs[0] < pair->objs[1];
  v8 = this;
  test.core0 = pair->objs[-v2 + 1];
  p_m_pairList = &this->m_pairList;
  seconds_low = LODWORD(pair->last_impact_time_pair.seconds);
  test.core1 = pair->objs[v2];
  *(_QWORD *)&test.lastImpactTime.seconds = __PAIR64__(HIDWORD(pair->last_impact_time_pair.seconds), seconds_low);
  v5 = CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_pairList,
         search: &test);
  if ( (unsigned __int16)v5 >= p_m_pairList->m_Elements.m_nAllocationCount
    || (unsigned __int16)v5 > p_m_pairList->m_LastAlloc.index
    || CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::LeftChild(
         this: p_m_pairList,
         i: v5) == (_WORD)v5 )
  {
    if ( v8->m_pairList.m_NumElements < 0x10u )
      CUtlRBTree<CPhysicsListenerCollision::corepair_t,unsigned short,bool (__cdecl *)(CPhysicsListenerCollision::corepair_t const &,CPhysicsListenerCollision::corepair_t const &),CUtlMemory<UtlRBTreeNode_t<CPhysicsListenerCollision::corepair_t,unsigned short>,unsigned short>>::Insert(
        this: p_m_pairList,
        insert: &test);
  }
  else
  {
    m_pMemory = v8->m_pairList.m_Elements.m_pMemory;
    if ( pair->last_impact_time_pair.seconds > m_pMemory[v5].m_Data.lastImpactTime.seconds )
      m_pMemory[v5].m_Data.lastImpactTime.seconds = pair->last_impact_time_pair.seconds;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E20
// Name: public: virtual void CCollisionSolver::inter_penetration(class IVP_Mindist __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionSolver::inter_penetration(
        CCollisionSolver *this,
        IVP_Mindist *mindist,
        IVP_Real_Object *ivp0,
        IVP_Real_Object *ivp1,
        float speedChange)
{
  _WORD *client_data; // esi
  _WORD *v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // [esp+24h] [ebp-4h]

  if ( this->delete_this_if_env_is_deleted == IVP_FALSE
    || (client_data = ivp0->client_data, v7 = ivp1->client_data, client_data != nullptr)
    && v7 != nullptr
    && (client_data[14] & 0x400) == 0
    && (v7[14] & 0x400) == 0
    && ((*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)client_data + 40))(a1: ivp0->client_data) == 0
     || (*(unsigned __int8 (__thiscall **)(_WORD *))(*(_DWORD *)v7 + 40))(a1: v7) == 0
     || CCollisionSolver::CheckObjPair(this: (CCollisionSolver *)((char *)this - 4), pObj0: ivp0, pObj1: ivp1) == 0)
    && (v10 = *(_DWORD *)this->delete_this_if_env_is_deleted,
        v8 = (*(int (__thiscall **)(_WORD *, _DWORD))(*(_DWORD *)v7 + 68))(
               a1: v7,
               a2: LODWORD(ivp0->environment->delta_PSI_time)),
        v9 = (*(int (__thiscall **)(_WORD *, int))(*(_DWORD *)client_data + 68))(a1: client_data, a2: v8),
        (*(int (__thiscall **)(IVP_BOOL, _WORD *, _WORD *, int))(v10 + 4))(
          a1: this->delete_this_if_env_is_deleted,
          a2: client_data,
          a3: v7,
          a4: v9) != 0) )
  {
    IVP_Anomaly_Manager::inter_penetration((IVP_Anomaly_Manager *)this, mindist, obj0: ivp0, obj1: ivp1, speedChange);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014F10
// Name: public: CPhysicsEnvironment::CPhysicsEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CPhysicsEnvironment *__usercall CPhysicsEnvironment::CPhysicsEnvironment@<eax>(
        CPhysicsEnvironment *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CCollisionSolver *v5; // eax
  CCollisionSolver *v6; // edi
  CCollisionSolver *m_pCollisionSolver; // eax
  IVP_Environment *environment; // eax
  CSleepObjects *v9; // eax
  CDeleteQueue *v10; // eax
  IVP_Environment *m_pPhysEnv; // ecx
  CPhysicsListenerCollision *v12; // eax
  CPhysicsListenerCollision *v13; // eax
  IVP_Environment *v14; // ecx
  CPhysicsListenerConstraint *v15; // eax
  IVP_Environment *v16; // ecx
  IVP_Controller *v17; // eax
  IVP_Environment *v18; // edx
  _BYTE v22[12]; // [esp+18h] [ebp-6Ch] BYREF
  IVP_Application_Environment appl_env; // [esp+24h] [ebp-60h] BYREF
  physics_performanceparams_t perf; // [esp+54h] [ebp-30h] BYREF
  IVP_Environment_Manager *environment_manager; // [esp+74h] [ebp-10h]
  int v26; // [esp+78h] [ebp-Ch]
  void *v27; // [esp+7Ch] [ebp-8h]
  void *retaddr; // [esp+84h] [ebp+0h]

  v26 = a2;
  v27 = retaddr;
  this->__vftable = (CPhysicsEnvironment_vtbl *)&CPhysicsEnvironment::`vftable';
  this->m_objects.m_Memory.m_pMemory = nullptr;
  this->m_objects.m_Memory.m_nAllocationCount = 0;
  this->m_objects.m_Memory.m_nGrowSize = 0;
  this->m_objects.m_Size = 0;
  this->m_objects.m_pElements = nullptr;
  this->m_deadObjects.m_Memory.m_pMemory = nullptr;
  this->m_deadObjects.m_Memory.m_nAllocationCount = 0;
  this->m_deadObjects.m_Memory.m_nGrowSize = 0;
  this->m_deadObjects.m_Size = 0;
  this->m_deadObjects.m_pElements = nullptr;
  this->m_deadObjectCollides.m_Memory.m_pMemory = nullptr;
  this->m_deadObjectCollides.m_Memory.m_nAllocationCount = 0;
  this->m_deadObjectCollides.m_Memory.m_nGrowSize = 0;
  this->m_deadObjectCollides.m_Size = 0;
  this->m_deadObjectCollides.m_pElements = nullptr;
  this->m_fluids.m_Memory.m_pMemory = nullptr;
  this->m_fluids.m_Memory.m_nAllocationCount = 0;
  this->m_fluids.m_Memory.m_nGrowSize = 0;
  this->m_fluids.m_Size = 0;
  this->m_fluids.m_pElements = nullptr;
  this->m_playerControllers.m_Memory.m_pMemory = nullptr;
  this->m_playerControllers.m_Memory.m_nAllocationCount = 0;
  this->m_playerControllers.m_Memory.m_nGrowSize = 0;
  this->m_playerControllers.m_Size = 0;
  this->m_playerControllers.m_pElements = nullptr;
  this->m_motionControllers.m_Memory.m_pMemory = nullptr;
  this->m_motionControllers.m_Memory.m_nAllocationCount = 0;
  this->m_motionControllers.m_Memory.m_nGrowSize = 0;
  this->m_motionControllers.m_Size = 0;
  this->m_motionControllers.m_pElements = nullptr;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory = nullptr;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nAllocationCount = 0;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nGrowSize = 0;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size = 0;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_pElements = nullptr;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory = nullptr;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nAllocationCount = 0;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nGrowSize = 0;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_Size = 0;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_pElements = nullptr;
  this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
  this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  this->m_PredictionBackups.m_Memory.m_nGrowSize = 0;
  this->m_PredictionBackups.m_Size = 0;
  this->m_PredictionBackups.m_pElements = nullptr;
  this->m_deleteQuick = false;
  *(_DWORD *)&this->m_inSimulation = 0x10000;
  environment_manager = IVP_Environment_Manager::get_environment_manager();
  IVP_Application_Environment::IVP_Application_Environment(this: (IVP_Application_Environment *)v22);
  v5 = (CCollisionSolver *)p_malloc(size: 0x24u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v5->IVP_Collision_Filter::__vftable = (CCollisionSolver_vtbl *)&IVP_Collision_Filter::`vftable';
    IVP_Anomaly_Manager::IVP_Anomaly_Manager(
      this: &v5->IVP_Anomaly_Manager,
      delete_this_if_env_is_deleted_in: IVP_FALSE);
    v6->IVP_Collision_Filter::__vftable = (CCollisionSolver_vtbl *)&CCollisionSolver::`vftable'{for `IVP_Collision_Filter'};
    v6->IVP_Anomaly_Manager::__vftable = (IVP_Anomaly_Manager_vtbl *)&CCollisionSolver::`vftable'{for `IVP_Anomaly_Manager'};
    v6->m_rescue.m_Memory.m_pMemory = nullptr;
    v6->m_rescue.m_Memory.m_nAllocationCount = 0;
    v6->m_rescue.m_Memory.m_nGrowSize = 0;
    v6->m_rescue.m_Size = 0;
    v6->m_rescue.m_pElements = nullptr;
    v6->m_pSolver = nullptr;
  }
  else
  {
    v6 = nullptr;
  }
  this->m_pCollisionSolver = v6;
  appl_env.n_cache_object = ((int (__thiscall *)(IPhysicsSurfacePropsInternal *, int, int))physprops->GetIVPManager)(
                              a1: physprops,
                              a2: a3,
                              a3: a4);
  m_pCollisionSolver = this->m_pCollisionSolver;
  if ( m_pCollisionSolver != nullptr )
    appl_env.collision_filter = (IVP_Collision_Filter *)&m_pCollisionSolver->IVP_Anomaly_Manager;
  else
    appl_env.collision_filter = nullptr;
  environment = IVP_Environment_Manager::create_environment(
                  this: environment_manager,
                  appl_env: (IVP_Application_Environment *)v22,
                  costumer_name: "JAY",
                  auth_code: 0xBEEFu);
  perf.maxFrictionMass = 9.8100004;
  this->m_pPhysEnv = environment;
  IVP_Environment::set_global_collision_tolerance(
    tolerance: (float)(g_PhysicsUnits.globalCollisionTolerance - 0.000099999997) * g_PhysicsUnits.unitScaleMeters,
    gravity_length: perf.maxFrictionMass);
  v9 = (CSleepObjects *)p_malloc(size: 0x20u);
  if ( v9 != nullptr )
  {
    v9->__vftable = (CSleepObjects_vtbl *)&CSleepObjects::`vftable';
    v9->m_activeObjects.m_Memory.m_pMemory = nullptr;
    v9->m_activeObjects.m_Memory.m_nAllocationCount = 0;
    v9->m_activeObjects.m_Memory.m_nGrowSize = 0;
    v9->m_activeObjects.m_Size = 0;
    v9->m_activeObjects.m_pElements = nullptr;
    v9->m_pCallback = nullptr;
    v9->m_lastScrapeTime = 0.0;
  }
  else
  {
    v9 = nullptr;
  }
  LODWORD(perf.maxFrictionMass) = 20;
  this->m_pSleepEvents = v9;
  v10 = (CDeleteQueue *)p_malloc(size: LODWORD(perf.maxFrictionMass));
  if ( v10 != nullptr )
  {
    v10->m_list.m_Memory.m_pMemory = nullptr;
    v10->m_list.m_Memory.m_nAllocationCount = 0;
    v10->m_list.m_Memory.m_nGrowSize = 0;
    v10->m_list.m_Size = 0;
    v10->m_list.m_pElements = nullptr;
  }
  else
  {
    v10 = nullptr;
  }
  LODWORD(perf.maxFrictionMass) = this->m_pSleepEvents;
  m_pPhysEnv = this->m_pPhysEnv;
  this->m_pDeleteQueue = v10;
  IVP_Environment::add_listener_object_global(
    this: m_pPhysEnv,
    listener: (IVP_Listener_Object *)LODWORD(perf.maxFrictionMass));
  v12 = (CPhysicsListenerCollision *)p_malloc(size: 0x50u);
  if ( v12 != nullptr )
    v13 = CPhysicsListenerCollision::CPhysicsListenerCollision(this: v12);
  else
    v13 = nullptr;
  v14 = this->m_pPhysEnv;
  LODWORD(perf.maxFrictionMass) = v13;
  this->m_pCollisionListener = v13;
  IVP_Environment::add_listener_collision_global(
    this: v14,
    listener: (IVP_Listener_Collision *)LODWORD(perf.maxFrictionMass));
  v15 = (CPhysicsListenerConstraint *)p_malloc(size: 8u);
  if ( v15 != nullptr )
  {
    v15->__vftable = (CPhysicsListenerConstraint_vtbl *)&CPhysicsListenerConstraint::`vftable';
    v15->m_pCallback = nullptr;
  }
  else
  {
    v15 = nullptr;
  }
  v16 = this->m_pPhysEnv;
  LODWORD(perf.maxFrictionMass) = v15;
  this->m_pConstraintListener = v15;
  IVP_Environment::add_listener_constraint_global(
    this: v16,
    listener: (IVP_Listener_Constraint *)LODWORD(perf.maxFrictionMass));
  v17 = (IVP_Controller *)p_malloc(size: 8u);
  if ( v17 != nullptr )
  {
    v17->__vftable = (IVP_Controller_vtbl *)&CDragController::`vftable';
    v17[1].__vftable = (IVP_Controller_vtbl *)0x40000000;
  }
  else
  {
    v17 = nullptr;
  }
  appl_env.range_manager = (IVP_Range_Manager *)1157234688;
  perf.maxCollisionsPerObjectPerTimestep = 1163984896;
  perf.maxCollisionChecksPerTimestep = 1065353216;
  perf.maxVelocity = 0.5;
  perf.maxAngularVelocity = 10.0;
  LODWORD(perf.maxFrictionMass) = &appl_env.default_collision_delegator_root;
  this->m_pDragController = v17;
  appl_env.default_collision_delegator_root = (IVP_Collision_Delegator_Root *)6;
  appl_env.env_active_float_manager = (IVP_U_Active_Value_Manager *)250;
  perf.lookAheadTimeObjectsVsWorld = 2500.0;
  CPhysicsEnvironment::SetPerformanceSettings(
    this,
    pSettings: (const physics_performanceparams_t *)LODWORD(perf.maxFrictionMass));
  this->m_pPhysEnv->client_data = this;
  v18 = this->m_pPhysEnv;
  this->m_lastObjectThisTick = 0;
  *(float *)&perf.maxCollisionChecksPerTimestep = vec3_origin.x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(perf.maxVelocity) = COERCE_UNSIGNED_INT(vec3_origin.z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  perf.maxAngularVelocity = vec3_origin.y * g_PhysicsUnits.unitScaleMeters;
  IVP_Standard_Gravity_Controller::set_alternate_gravity(
    this: v18->standard_gravity_controller,
    new_gravity: (IVP_U_Point *)&perf.maxCollisionChecksPerTimestep);
  this->m_iPredictionCommandNum = -1;
  this->m_iHighestPredictionCommandNum = -1;
  this->m_bPredicted = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100152B0
// Name: public: virtual bool CPhysicsEnvironment::ShouldQuickDelete(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsEnvironment::ShouldQuickDelete(CPhysicsEnvironment *this)
{
  return this->m_deleteQuick;
}

//------------------------------------------------------------------------------
// Address: 0x100152C0
// Name: public: virtual void CPhysicsEnvironment::EnableDeleteQueue(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::EnableDeleteQueue(CPhysicsEnvironment *this, bool enable)
{
  this->m_queueDeleteObject = enable;
}

//------------------------------------------------------------------------------
// Address: 0x100152D0
// Name: public: virtual CPhysicsEnvironment::~CPhysicsEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::~CPhysicsEnvironment(CPhysicsEnvironment *this)
{
  CCollisionSolver *m_pCollisionSolver; // eax
  IVP_Environment *m_pPhysEnv; // ecx
  CPhysicsListenerCollision *v4; // ecx
  int v5; // eax
  IPhysicsObject *v6; // ebx
  IVP_Controller_Phantom *IsGravityEnabled; // ecx
  CPhysicsListenerCollision *v8; // eax
  IVP_Listener_Phantom *v9; // eax
  CSleepObjects *m_pSleepEvents; // ecx
  IVP_Controller *m_pDragController; // ecx
  IVP_Environment *v12; // ebx
  CDeleteQueue *m_pDeleteQueue; // ebx
  IDeleteQueueItem **m_pMemory; // eax
  CCollisionSolver *v15; // ecx
  CPhysicsEnvironment::PredictedData_t *v16; // eax
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *v17; // eax
  IPredictable_Controller_Independant **v18; // eax
  IPhysicsMotionController **v19; // eax
  IPhysicsPlayerController **v20; // eax
  CPhysicsFluidController **v21; // eax
  CPhysCollide **v22; // eax
  IPhysicsObject **v23; // eax
  IPhysicsObject **v24; // eax
  CPhysicsListenerCollision *m_pCollisionListener; // [esp-4h] [ebp-10h]
  int i; // [esp+8h] [ebp-4h]

  m_pCollisionSolver = this->m_pCollisionSolver;
  this->__vftable = (CPhysicsEnvironment_vtbl *)&CPhysicsEnvironment::`vftable';
  m_pCollisionSolver->m_pSolver = nullptr;
  IVP_Environment::remove_listener_object_global(this: this->m_pPhysEnv, listener: this->m_pSleepEvents);
  m_pPhysEnv = this->m_pPhysEnv;
  m_pCollisionListener = this->m_pCollisionListener;
  this->m_deleteQuick = true;
  IVP_Environment::remove_listener_collision_global(this: m_pPhysEnv, listener: m_pCollisionListener);
  v4 = this->m_pCollisionListener;
  if ( v4 != nullptr )
    ((void (__thiscall *)(CPhysicsListenerCollision *, int))v4->dtr_IVP_Listener_Collision)(a1: v4, a2: 1);
  IVP_Environment::remove_listener_constraint_global(this: this->m_pPhysEnv, listener: this->m_pConstraintListener);
  free(data: this->m_pConstraintListener);
  v5 = this->m_objects.m_Size - 1;
  i = v5;
  if ( v5 >= 0 )
  {
    while ( 1 )
    {
      v6 = this->m_objects.m_Memory.m_pMemory[v5];
      IsGravityEnabled = (IVP_Controller_Phantom *)v6[2].IsGravityEnabled;
      if ( IsGravityEnabled != nullptr )
      {
        v8 = this->m_pCollisionListener;
        if ( v8 != nullptr )
          v9 = &v8->IVP_Listener_Phantom;
        else
          v9 = nullptr;
        IVP_Controller_Phantom::remove_listener_phantom(this: IsGravityEnabled, listener: v9);
      }
      ((void (__thiscall *)(IPhysicsObject *, int))v6->dtr_IPhysicsObject)(a1: v6, a2: 1);
      if ( --i < 0 )
        break;
      v5 = i;
    }
  }
  this->m_objects.m_Size = 0;
  CPhysicsEnvironment::ClearDeadObjects(this);
  CUtlVector<CPhysicsFluidController *,CUtlMemory<CPhysicsFluidController *,int>>::PurgeAndDeleteElements(this: &this->m_fluids);
  m_pSleepEvents = this->m_pSleepEvents;
  if ( m_pSleepEvents != nullptr )
    ((void (__thiscall *)(CSleepObjects *, int))m_pSleepEvents->dtr_IVP_Listener_Object)(a1: m_pSleepEvents, a2: 1);
  m_pDragController = this->m_pDragController;
  if ( m_pDragController != nullptr )
    ((void (__thiscall *)(IVP_Controller *, int))m_pDragController->dtr_IVP_Controller)(a1: m_pDragController, a2: 1);
  v12 = this->m_pPhysEnv;
  if ( v12 != nullptr )
  {
    IVP_Environment::~IVP_Environment(this: this->m_pPhysEnv);
    free(data: v12);
  }
  m_pDeleteQueue = this->m_pDeleteQueue;
  if ( m_pDeleteQueue != nullptr )
  {
    m_pDeleteQueue->m_list.m_Size = 0;
    if ( m_pDeleteQueue->m_list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pDeleteQueue->m_list.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pDeleteQueue->m_list.m_Memory.m_pMemory);
        m_pDeleteQueue->m_list.m_Memory.m_pMemory = nullptr;
      }
      m_pDeleteQueue->m_list.m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = m_pDeleteQueue->m_list.m_Memory.m_pMemory;
    m_pDeleteQueue->m_list.m_pElements = m_pDeleteQueue->m_list.m_Memory.m_pMemory;
    if ( m_pDeleteQueue->m_list.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pDeleteQueue->m_list.m_Memory.m_pMemory = nullptr;
      }
      m_pDeleteQueue->m_list.m_Memory.m_nAllocationCount = 0;
    }
    free(data: m_pDeleteQueue);
  }
  v15 = this->m_pCollisionSolver;
  if ( v15 != nullptr )
    ((void (__thiscall *)(CCollisionSolver *, int))v15->dtr_IVP_Collision_Filter)(a1: v15, a2: 1);
  this->m_PredictionBackups.m_Size = 0;
  if ( this->m_PredictionBackups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PredictionBackups.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PredictionBackups.m_Memory.m_pMemory);
      this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  }
  v16 = this->m_PredictionBackups.m_Memory.m_pMemory;
  this->m_PredictionBackups.m_pElements = v16;
  if ( this->m_PredictionBackups.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_Size = 0;
  if ( this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory);
      this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nAllocationCount = 0;
  }
  v17 = this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory;
  this->m_PredictedPhysControllerCallOrder.m_Commands.m_pElements = v17;
  if ( this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_nAllocationCount = 0;
  }
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size = 0;
  if ( this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory);
      this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nAllocationCount = 0;
  }
  v18 = this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory;
  this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_pElements = v18;
  if ( this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_pMemory = nullptr;
    }
    this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Memory.m_nAllocationCount = 0;
  }
  this->m_motionControllers.m_Size = 0;
  if ( this->m_motionControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_motionControllers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_motionControllers.m_Memory.m_pMemory);
      this->m_motionControllers.m_Memory.m_pMemory = nullptr;
    }
    this->m_motionControllers.m_Memory.m_nAllocationCount = 0;
  }
  v19 = this->m_motionControllers.m_Memory.m_pMemory;
  this->m_motionControllers.m_pElements = v19;
  if ( this->m_motionControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v19 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19);
      this->m_motionControllers.m_Memory.m_pMemory = nullptr;
    }
    this->m_motionControllers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_playerControllers.m_Size = 0;
  if ( this->m_playerControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_playerControllers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_playerControllers.m_Memory.m_pMemory);
      this->m_playerControllers.m_Memory.m_pMemory = nullptr;
    }
    this->m_playerControllers.m_Memory.m_nAllocationCount = 0;
  }
  v20 = this->m_playerControllers.m_Memory.m_pMemory;
  this->m_playerControllers.m_pElements = v20;
  if ( this->m_playerControllers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v20 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
      this->m_playerControllers.m_Memory.m_pMemory = nullptr;
    }
    this->m_playerControllers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_fluids.m_Size = 0;
  if ( this->m_fluids.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_fluids.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_fluids.m_Memory.m_pMemory);
      this->m_fluids.m_Memory.m_pMemory = nullptr;
    }
    this->m_fluids.m_Memory.m_nAllocationCount = 0;
  }
  v21 = this->m_fluids.m_Memory.m_pMemory;
  this->m_fluids.m_pElements = v21;
  if ( this->m_fluids.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v21 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
      this->m_fluids.m_Memory.m_pMemory = nullptr;
    }
    this->m_fluids.m_Memory.m_nAllocationCount = 0;
  }
  this->m_deadObjectCollides.m_Size = 0;
  if ( this->m_deadObjectCollides.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_deadObjectCollides.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_deadObjectCollides.m_Memory.m_pMemory);
      this->m_deadObjectCollides.m_Memory.m_pMemory = nullptr;
    }
    this->m_deadObjectCollides.m_Memory.m_nAllocationCount = 0;
  }
  v22 = this->m_deadObjectCollides.m_Memory.m_pMemory;
  this->m_deadObjectCollides.m_pElements = v22;
  if ( this->m_deadObjectCollides.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v22 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
      this->m_deadObjectCollides.m_Memory.m_pMemory = nullptr;
    }
    this->m_deadObjectCollides.m_Memory.m_nAllocationCount = 0;
  }
  this->m_deadObjects.m_Size = 0;
  if ( this->m_deadObjects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_deadObjects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_deadObjects.m_Memory.m_pMemory);
      this->m_deadObjects.m_Memory.m_pMemory = nullptr;
    }
    this->m_deadObjects.m_Memory.m_nAllocationCount = 0;
  }
  v23 = this->m_deadObjects.m_Memory.m_pMemory;
  this->m_deadObjects.m_pElements = v23;
  if ( this->m_deadObjects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v23 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      this->m_deadObjects.m_Memory.m_pMemory = nullptr;
    }
    this->m_deadObjects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_objects.m_Size = 0;
  if ( this->m_objects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_objects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_objects.m_Memory.m_pMemory);
      this->m_objects.m_Memory.m_pMemory = nullptr;
    }
    this->m_objects.m_Memory.m_nAllocationCount = 0;
  }
  v24 = this->m_objects.m_Memory.m_pMemory;
  this->m_objects.m_pElements = v24;
  if ( this->m_objects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v24 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24);
      this->m_objects.m_Memory.m_pMemory = nullptr;
    }
    this->m_objects.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CPhysicsEnvironment_vtbl *)&IPhysicsEnvironment::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10015750
// Name: public: virtual bool CPhysicsEnvironment::TransferObject(class IPhysicsObject __near *,class IPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsEnvironment::TransferObject(
        CPhysicsEnvironment *this,
        CPhysicsObject *pObject,
        CPhysicsEnvironment *pDestinationEnvironment)
{
  int m_Size; // edx
  int v5; // ecx
  IPhysicsObject **i; // eax
  void *v9; // eax
  IPhysicsObject_vtbl *v10; // edx
  IPhysicsShadowController *v11; // eax
  IPhysicsObject_vtbl *v12; // edx
  IPhysicsEnvironment *v13; // ebx
  unsigned __int16 (__thiscall *GetCallbackFlags)(IPhysicsObject *); // edx
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // ebx
  IPhysicsEnvironment_vtbl *m_nAllocationCount; // eax
  IPhysicsEnvironment_vtbl *m_pMemory; // ecx
  int v20; // eax
  CPhysicsObject **v21; // ebx
  IPhysicsObject_vtbl *v22; // edi
  IVP_Real_Object *v23; // ebx
  unsigned __int16 v24; // ax
  IPhysicsShadowController *v25; // [esp-10h] [ebp-BCh]
  IPhysicsShadowController *v26; // [esp-10h] [ebp-BCh]
  IVP_Real_Object *m_pObject; // [esp-Ch] [ebp-B8h]
  IVP_Real_Object *v28; // [esp-Ch] [ebp-B8h]
  vphysics_save_cphysicsobject_t objectTemplate; // [esp+8h] [ebp-A4h] BYREF
  void *pGameData; // [esp+9Ch] [ebp-10h]
  IPhysicsShadowController *pController; // [esp+A0h] [ebp-Ch]
  int v32; // [esp+A4h] [ebp-8h]
  IPhysicsEnvironment *src; // [esp+A8h] [ebp-4h] BYREF
  IPhysicsPlayerController *pPlayerController; // [esp+B4h] [ebp+8h]

  m_Size = this->m_objects.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_objects.m_Memory.m_pMemory; *i != pObject; ++i )
  {
    if ( ++v5 >= m_Size )
      return 0;
  }
  v32 = v5;
  if ( v5 == -1 || (((int (__thiscall *)(CPhysicsObject *))pObject->GetCallbackFlags)(a1: pObject) & 0x400) != 0 )
    return 0;
  v9 = pObject->GetGameData(this: pObject);
  v10 = (IPhysicsObject_vtbl *)pObject->__vftable;
  pGameData = v9;
  v11 = v10->GetShadowController(this: pObject);
  v12 = (IPhysicsObject_vtbl *)pObject->__vftable;
  pController = v11;
  v13 = nullptr;
  pPlayerController = nullptr;
  if ( (((int (__thiscall *)(CPhysicsObject *))v12->GetCallbackFlags)(a1: pObject) & 0x2000) != 0 )
  {
    pPlayerController = CPhysicsEnvironment::FindPlayerController(this, pPhysicsObject: pObject);
    v13 = (IPhysicsEnvironment *)pPlayerController;
  }
  if ( pController != nullptr )
  {
    m_pObject = pObject->m_pObject;
    v25 = pController;
    pObject->m_pShadow = nullptr;
    ControlPhysicsPlayerControllerAttachment_Silent(
      pController: (IPhysicsPlayerController *)v25,
      pivp: m_pObject,
      bAttach: false);
  }
  else if ( v13 != nullptr )
  {
    src = v13;
    CUtlVector<IPhysicsPlayerController *,CUtlMemory<IPhysicsPlayerController *,int>>::FindAndRemove(
      this: (CUtlVector<IPhysicsEnvironment *,CUtlMemory<IPhysicsEnvironment *,int> > *)&this->m_playerControllers,
      &src);
    GetCallbackFlags = pObject->GetCallbackFlags;
    src = (IPhysicsEnvironment *)pObject->__vftable;
    v15 = GetCallbackFlags(this: pObject);
    ((void (__thiscall *)(CPhysicsObject *, int))src[22].__vftable)(a1: pObject, a2: v15 & 0xDFFF);
    ControlPhysicsPlayerControllerAttachment_Silent(
      pController: (IPhysicsPlayerController *)v13,
      pivp: pObject->m_pObject,
      bAttach: false);
  }
  memset(dst: (unsigned __int8 *)&objectTemplate, value: 0, count: sizeof(objectTemplate));
  CPhysicsObject::WriteToTemplate(this: pObject, &objectTemplate);
  v16 = this->m_objects.m_Size;
  if ( v16 > 0 )
  {
    if ( v32 != v16 - 1 )
      this->m_objects.m_Memory.m_pMemory[v32] = this->m_objects.m_Memory.m_pMemory[v16 - 1];
    --this->m_objects.m_Size;
  }
  *((_BYTE *)pObject + 20) |= 0x80u;
  CSleepObjects::DeleteObject(this: this->m_pSleepEvents, pObject);
  CPhysicsObject::~CPhysicsObject(this: pObject);
  CreateObjectFromBuffer_UseExistingMemory(
    pEnvironment: pDestinationEnvironment,
    pGameData,
    pBuffer: (unsigned __int8 *)&objectTemplate,
    bufferSize: 0x94u,
    pExistingMemory: pObject);
  v17 = pDestinationEnvironment->m_objects.m_Size;
  m_nAllocationCount = (IPhysicsEnvironment_vtbl *)pDestinationEnvironment->m_objects.m_Memory.m_nAllocationCount;
  if ( v17 + 1 > (int)m_nAllocationCount )
    CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pDestinationEnvironment->m_objects,
      num: v17 - (_DWORD)m_nAllocationCount + 1);
  ++pDestinationEnvironment->m_objects.m_Size;
  m_pMemory = (IPhysicsEnvironment_vtbl *)pDestinationEnvironment->m_objects.m_Memory.m_pMemory;
  v20 = pDestinationEnvironment->m_objects.m_Size - v17 - 1;
  pDestinationEnvironment->m_objects.m_pElements = (IPhysicsObject **)m_pMemory;
  if ( v20 > 0 )
    _V_memmove(dest: &m_pMemory->SetDebugOverlay + v17, src: &m_pMemory->dtr_IPhysicsEnvironment + v17, count: 4 * v20);
  v21 = (CPhysicsObject **)&pDestinationEnvironment->m_objects.m_Memory.m_pMemory[v17];
  if ( v21 != nullptr )
    *v21 = pObject;
  pObject->Wake(this: pObject);
  CPhysicsObject::NotifyWake(this: pObject);
  IVP_Environment::force_psi_on_next_simulation(this: pDestinationEnvironment->m_pPhysEnv);
  if ( pController != nullptr )
  {
    v28 = pObject->m_pObject;
    v26 = pController;
    pObject->m_pShadow = (CShadowController *)&pController[-1];
    ControlPhysicsPlayerControllerAttachment_Silent(
      pController: (IPhysicsPlayerController *)v26,
      pivp: v28,
      bAttach: true);
    return 1;
  }
  else
  {
    if ( pPlayerController != nullptr )
    {
      v22 = (IPhysicsObject_vtbl *)pObject->__vftable;
      v23 = pObject->m_pObject;
      v24 = pObject->GetCallbackFlags(this: pObject);
      v22->SetCallbackFlags(this: pObject, a2: v24 | 0x2000);
      ControlPhysicsPlayerControllerAttachment_Silent(pController: pPlayerController, pivp: v23, bAttach: true);
      CPhysicsEnvironment::AddPlayerController(this: pDestinationEnvironment, pController: pPlayerController);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015990
// Name: public: virtual void CPhysicsEnvironment::DestroyConstraint(class IPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::DestroyConstraint(CPhysicsEnvironment *this, IPhysicsConstraint *pConstraint)
{
  IPhysicsObject *v3; // eax
  IPhysicsObject *v4; // eax

  if ( !this->m_deleteQuick && pConstraint != nullptr )
  {
    v3 = pConstraint->GetReferenceObject(this: pConstraint);
    if ( v3 != nullptr )
      v3->Wake(this: v3);
    v4 = pConstraint->GetAttachedObject(this: pConstraint);
    if ( v4 != nullptr )
      v4->Wake(this: v4);
  }
  if ( this->m_inSimulation )
  {
    pConstraint->Deactivate(this: pConstraint);
    CDeleteQueue::QueueForDelete<IPhysicsConstraint>(this: this->m_pDeleteQueue, pItem: pConstraint);
  }
  else if ( pConstraint != nullptr )
  {
    ((void (__thiscall *)(IPhysicsConstraint *, int))pConstraint->dtr_IPhysicsConstraint)(a1: pConstraint, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015A10
// Name: public: virtual void CPhysicsEnvironment::SetPredictionCommandNum(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::SetPredictionCommandNum(CPhysicsEnvironment *this, int iCommandNum)
{
  int v4; // ebx
  IPhysicsPlayerController *v5; // eax
  CPredictedPlayerController *v6; // ecx
  int i; // ebx
  IPhysicsMotionController *v8; // eax
  CPredictedPhysicsMotionController *v9; // ecx
  int j; // ebx
  int m_Size; // [esp-Ch] [ebp-1Ch]
  int v12; // [esp-Ch] [ebp-1Ch]
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t src; // [esp+4h] [ebp-Ch] BYREF
  bool bNewest; // [esp+18h] [ebp+8h]

  if ( this->m_bPredicted )
  {
    bNewest = this->m_iHighestPredictionCommandNum < iCommandNum;
    if ( bNewest )
    {
      src.iControllerCallOrderStart = this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size;
      m_Size = this->m_PredictedPhysControllerCallOrder.m_Commands.m_Size;
      src.iCommandNum = iCommandNum;
      src.iControllerCallOrderCount = 0;
      CUtlVector<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,CUtlMemory<CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t,int>>::InsertBefore(
        this: &this->m_PredictedPhysControllerCallOrder.m_Commands,
        elem: m_Size,
        &src);
      v12 = this->m_PredictionBackups.m_Size;
      src.iControllerCallOrderStart = iCommandNum;
      src.iControllerCallOrderCount = 0;
      CUtlVector<CPhysicsEnvironment::PredictedData_t,CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>>::InsertBefore(
        this: (CUtlVector<CCollisionSolver::realobjectpair_t,CUtlMemory<CCollisionSolver::realobjectpair_t,int> > *)&this->m_PredictionBackups,
        elem: v12,
        src: (const CCollisionSolver::realobjectpair_t *)&src.iControllerCallOrderStart);
      this->m_iHighestPredictionCommandNum = iCommandNum;
    }
    v4 = 0;
    for ( this->m_iPredictionCommandNum = iCommandNum; v4 != this->m_playerControllers.m_Size; ++v4 )
    {
      v5 = this->m_playerControllers.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr )
        v6 = (CPredictedPlayerController *)&v5[-1];
      else
        v6 = nullptr;
      CPredictedPlayerController::OnPredictionCommandChanged(this: v6, iCommandNum, bBackup: bNewest);
    }
    for ( i = 0; i != this->m_motionControllers.m_Size; ++i )
    {
      v8 = this->m_motionControllers.m_Memory.m_pMemory[i];
      if ( v8 != nullptr )
        v9 = (CPredictedPhysicsMotionController *)&v8[-1];
      else
        v9 = nullptr;
      CPredictedPhysicsMotionController::OnPredictionCommandChanged(this: v9, iCommandNum, bBackup: bNewest);
    }
    for ( j = 0; j != this->m_objects.m_Size; ++j )
      CPredictedPhysicsObject::OnPredictionCommandChanged(
        this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[j],
        iCommandNum,
        bBackup: bNewest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015B10
// Name: class IPhysicsEnvironment __near * CreatePhysicsEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsEnvironment *__usercall CreatePhysicsEnvironment@<eax>(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  CPhysicsEnvironment *v3; // eax

  v3 = (CPhysicsEnvironment *)p_malloc(size: 0xECu);
  if ( v3 != nullptr )
    return CPhysicsEnvironment::CPhysicsEnvironment(this: v3, a2: a1, a3: a2, a4: a3);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10015B30
// Name: public: void CObjectPairHash::DestroyListForObject(void __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::DestroyListForObject(CObjectPairHash *this, void *pObject, unsigned __int16 listIndex)
{
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // eax
  int v4; // ebx
  CUtlMultiList<void *,unsigned short> *p_m_objectList; // edi

  if ( listIndex < this->m_objectList.m_List.m_Memory.m_nAllocationCount
    && listIndex <= this->m_objectList.m_List.m_LastAlloc.index )
  {
    m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
    v4 = listIndex;
    if ( m_pMemory[v4].m_Previous != listIndex || m_pMemory[v4].m_Next == listIndex )
    {
      p_m_objectList = &this->m_objectList;
      CUtlMultiList<void *,unsigned short>::RemoveAll(this: &this->m_objectList, list: listIndex);
      CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&p_m_objectList->m_List,
        elem: listIndex);
      p_m_objectList->m_List.m_Memory.m_pMemory[v4].m_Next = p_m_objectList->m_List.m_FirstFree;
      p_m_objectList->m_List.m_FirstFree = listIndex;
      IVP_VHash_Store::remove_elem(this: this->m_pObjectHash, key_elem: pObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015BB0
// Name: public: void CObjectPairHash::RemoveFromObjectList(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::RemoveFromObjectList(CObjectPairHash *this, void *pObject, void *pRemove)
{
  void *elem; // eax
  unsigned __int16 v5; // dx
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 m_Head; // si
  CUtlMultiList<void *,unsigned short>::ListElem_t *v9; // ecx
  int v10; // [esp+4h] [ebp-8h]
  unsigned __int16 list; // [esp+8h] [ebp-4h]

  elem = IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject);
  if ( elem != nullptr )
  {
    list = (unsigned __int16)elem;
    v5 = (unsigned __int16)elem;
  }
  else
  {
    v5 = -1;
    list = -1;
  }
  if ( v5 < this->m_objectList.m_List.m_Memory.m_nAllocationCount && v5 <= this->m_objectList.m_List.m_LastAlloc.index )
  {
    m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
    v7 = v5;
    v10 = v7 * 10;
    if ( m_pMemory[v7].m_Previous != v5 || m_pMemory[v7].m_Next == v5 )
    {
      m_Head = m_pMemory[v7].m_Element.m_Head;
      if ( m_Head != 0xFFFF )
      {
        v9 = this->m_objectList.m_Memory.m_pMemory;
        while ( v9[m_Head].m_Element != pRemove )
        {
          m_Head = v9[m_Head].m_Next;
          if ( m_Head == 0xFFFF )
            return;
        }
        if ( m_Head < this->m_objectList.m_MaxElementIndex && v9[m_Head].m_Previous != m_Head )
          CUtlMultiList<void *,unsigned short>::Unlink(this: &this->m_objectList, list, elem: m_Head);
        this->m_objectList.m_Memory.m_pMemory[m_Head].m_Next = this->m_objectList.m_FirstFree;
        --this->m_objectList.m_TotalElements;
        this->m_objectList.m_FirstFree = m_Head;
        if ( *(unsigned __int16 *)((char *)&this->m_objectList.m_List.m_Memory.m_pMemory->m_Element.m_Head + v10) == 0xFFFF )
          CObjectPairHash::DestroyListForObject(this, pObject, listIndex: list);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015CB0
// Name: public: virtual void CObjectPairHash::RemoveObjectPair(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::RemoveObjectPair(
        CObjectPairHash *this,
        IVP_Real_Object *pObject0,
        IVP_Real_Object *pObject1)
{
  if ( this->IsObjectPairInHash(this, a2: pObject0, a3: pObject1) )
  {
    IVP_Collision_Filter_Exclusive_Pair::enable_collision_between_objects(
      this: &this->m_pairHash,
      obj0: pObject0,
      obj1: pObject1);
    CObjectPairHash::RemoveFromObjectList(this, pObject: pObject0, pRemove: pObject1);
    CObjectPairHash::RemoveFromObjectList(this, pObject: pObject1, pRemove: pObject0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015CF0
// Name: public: virtual void CObjectPairHash::RemoveAllPairsForObject(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::RemoveAllPairsForObject(CObjectPairHash *this, IVP_Real_Object *pObject)
{
  void *elem; // eax
  unsigned __int16 v4; // cx
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v6; // eax
  unsigned __int16 m_Head; // di
  CUtlMultiList<void *,unsigned short>::ListElem_t *v8; // ecx
  unsigned __int16 next; // [esp+4h] [ebp-10h]
  IVP_Real_Object *pOther; // [esp+Ch] [ebp-8h]
  unsigned __int16 list; // [esp+10h] [ebp-4h]

  elem = IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject);
  if ( elem != nullptr )
  {
    v4 = (unsigned __int16)elem;
    list = (unsigned __int16)elem;
  }
  else
  {
    v4 = -1;
    list = -1;
  }
  if ( v4 < this->m_objectList.m_List.m_Memory.m_nAllocationCount && v4 <= this->m_objectList.m_List.m_LastAlloc.index )
  {
    m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory;
    v6 = v4;
    if ( m_pMemory[v6].m_Previous != v4 || m_pMemory[v6].m_Next == v4 )
    {
      m_Head = m_pMemory[v6].m_Element.m_Head;
      if ( m_Head != 0xFFFF )
      {
        do
        {
          v8 = this->m_objectList.m_Memory.m_pMemory;
          next = v8[m_Head].m_Next;
          pOther = (IVP_Real_Object *)v8[m_Head].m_Element;
          if ( m_Head < this->m_objectList.m_MaxElementIndex && v8[m_Head].m_Previous != m_Head )
            CUtlMultiList<void *,unsigned short>::Unlink(this: &this->m_objectList, list, elem: m_Head);
          this->m_objectList.m_Memory.m_pMemory[m_Head].m_Next = this->m_objectList.m_FirstFree;
          this->m_objectList.m_FirstFree = m_Head;
          --this->m_objectList.m_TotalElements;
          CObjectPairHash::RemoveFromObjectList(this, pObject: pOther, pRemove: pObject);
          IVP_Collision_Filter_Exclusive_Pair::enable_collision_between_objects(
            this: &this->m_pairHash,
            obj0: pOther,
            obj1: pObject);
          m_Head = next;
        }
        while ( next != 0xFFFF );
        v4 = list;
      }
      CObjectPairHash::DestroyListForObject(this, pObject, listIndex: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015DF0
// Name: public: unsigned short CUtlMultiList<void __near *,unsigned short>::CreateList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<void *,unsigned short>::CreateList(CUtlMultiList<void *,unsigned short> *this)
{
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_List; // esi
  int v2; // edi
  int result; // eax
  int v4; // ecx

  p_m_List = (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List;
  v2 = (unsigned __int16)CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_List,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_List,
      before: 0xFFFFu,
      elem: v2);
    result = v2;
  }
  v4 = (unsigned __int16)result;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Tail = -1;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Head = -1;
  p_m_List->m_Memory.m_pMemory[v4].m_Element.m_Count = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015EA0
// Name: public: virtual void CPhysicsEnvironment::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEnvironment::Simulate(CPhysicsEnvironment *this, float deltaTime)
{
  int m_nValue; // eax
  int i; // edi
  int v5; // eax
  DWORD CurrentThreadId; // eax
  int v7; // eax
  int v8; // eax
  CSleepObjects *m_pSleepEvents; // ecx
  CPhysicsListenerCollision *m_pCollisionListener; // edi
  bool v11; // zf
  IVP_Environment *v12; // ecx
  IVP_Environment *m_pPhysEnv; // ecx
  int j; // edi
  CPredictableControllerSimulationOrderTracker_Manager::CallOrderEntry_t *v15; // eax
  bool bThreaded; // [esp+1Bh] [ebp-1h]

  if ( g_cv_phys_enable_query_cache.m_pParent != nullptr )
    m_nValue = g_cv_phys_enable_query_cache.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_b_phys_enable_query_cache = m_nValue != 0;
  if ( this->m_pPhysEnv != nullptr )
  {
    if ( this->m_bPredicted )
    {
      for ( i = 0; i != this->m_objects.m_Size; ++i )
        CPredictedPhysicsObject::PreSimulation(
          this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[i],
          bBackup: true);
    }
    if ( vphysics_threadmode.m_pParent != nullptr )
      v5 = vphysics_threadmode.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    bThreaded = v5 != 0;
    if ( v5 == 0 )
    {
      CurrentThreadId = GetCurrentThreadId();
      if ( CurrentThreadId != g_PhysicsMutex.m_ownerID
        && _InterlockedCompareExchange((volatile signed __int32 *)&g_PhysicsMutex, CurrentThreadId, 0) != 0 )
      {
        _mm_pause();
        CThreadFastMutex::Lock(a1: &g_PhysicsMutex, a2: CurrentThreadId, a3: 0);
      }
      else
      {
        ++g_PhysicsMutex.m_depth;
      }
    }
    if ( cv_phys_enable_simd_optimizations.m_pParent != nullptr )
      v7 = cv_phys_enable_simd_optimizations.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    phys_enable_simd_optimizations = v7 != 0;
    if ( cv_phys_enable_experimental_optimizations.m_pParent != nullptr )
      v8 = cv_phys_enable_experimental_optimizations.m_pParent->m_Value.m_nValue;
    else
      v8 = 0;
    phys_enable_experimental_optimizations = v8 != 0;
    CPhysicsEnvironment::ClearDeadObjects(this);
    m_pSleepEvents = this->m_pSleepEvents;
    this->m_lastObjectThisTick = this->m_objects.m_Size - 1;
    CSleepObjects::UpdateSleepObjects(this: m_pSleepEvents);
    if ( deltaTime <= 1.0 && deltaTime > 0.0001 )
    {
      if ( deltaTime > 0.1 )
        deltaTime = 0.1;
      this->m_pCollisionSolver->m_rescue.m_Size = 0;
      m_pCollisionListener = this->m_pCollisionListener;
      m_pCollisionListener->m_pCallback->PostSimulationFrame(this: m_pCollisionListener->m_pCallback);
      CPhysicsListenerCollision::UpdatePairListPSI(this: m_pCollisionListener, pEnvironment: this);
      v11 = !this->m_fixedTimestep;
      this->m_inSimulation = true;
      if ( v11 || (v12 = this->m_pPhysEnv, deltaTime != v12->delta_PSI_time) )
      {
        m_pPhysEnv = this->m_pPhysEnv;
        this->m_fixedTimestep = false;
        IVP_Environment::simulate_dtime(this: m_pPhysEnv, dtime: deltaTime);
      }
      else
      {
        IVP_Environment::simulate_time_step(this: v12, sub_psi_time: 1.99999);
      }
      this->m_inSimulation = false;
    }
    if ( !this->m_queueDeleteObject )
      CPhysicsEnvironment::ClearDeadObjects(this);
    if ( this->m_pCollisionListener->m_pCallback != nullptr )
      CSleepObjects::ProcessActiveObjects(
        this: this->m_pSleepEvents,
        pEnvironment: this->m_pPhysEnv,
        pEvent: this->m_pCollisionListener->m_pCallback);
    VirtualMeshPSI();
    this->GetNextFrameTime(this);
    if ( this->m_bPredicted )
    {
      for ( j = 0; j != this->m_objects.m_Size; ++j )
        CPredictedPhysicsObject::PostSimulation(
          this: (CPredictedPhysicsObject *)this->m_objects.m_Memory.m_pMemory[j],
          fSimulationTime: deltaTime,
          bBackup: true);
      this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1].fSimulationStep = deltaTime;
      v15 = &this->m_PredictedPhysControllerCallOrder.m_Commands.m_Memory.m_pMemory[this->m_PredictedPhysControllerCallOrder.m_Commands.m_Size
                                                                                  - 1];
      v15->iControllerCallOrderCount = this->m_PredictedPhysControllerCallOrder.m_CallOrder.m_Size
                                     - v15->iControllerCallOrderStart;
    }
    if ( !bThreaded && --g_PhysicsMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_PhysicsMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016130
// Name: public: void CObjectPairHash::AddToObjectList(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::AddToObjectList(CObjectPairHash *this, void *pObject, void *pAdd)
{
  void *elem; // eax
  unsigned __int16 List; // bx
  UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 v7; // ax
  int v8; // edi
  CUtlMultiList<void *,unsigned short>::ListElem_t *v9; // eax

  elem = IVP_VHash_Store::find_elem(this: this->m_pObjectHash, key_elem: pObject);
  if ( elem == nullptr )
    LOWORD(elem) = -1;
  List = (unsigned __int16)elem;
  if ( (unsigned __int16)elem >= this->m_objectList.m_List.m_Memory.m_nAllocationCount
    || (unsigned __int16)elem > this->m_objectList.m_List.m_LastAlloc.index
    || (m_pMemory = this->m_objectList.m_List.m_Memory.m_pMemory)[(unsigned __int16)elem].m_Previous == (_WORD)elem
    && m_pMemory[(unsigned __int16)elem].m_Next != (_WORD)elem )
  {
    List = CUtlMultiList<void *,unsigned short>::CreateList(this: &this->m_objectList);
    IVP_VHash_Store::add_elem(this: this->m_pObjectHash, key_elem: pObject, elem: (void *)(List | 0x80000000));
  }
  v7 = CUtlMultiList<void *,unsigned short>::Alloc(this: &this->m_objectList);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    CUtlMultiList<void *,unsigned short>::LinkBefore(this: &this->m_objectList, list: List, before: 0xFFFFu, elem: v7);
    v9 = &this->m_objectList.m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
      v9->m_Element = pAdd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100161E0
// Name: public: virtual void CObjectPairHash::AddObjectPair(void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPairHash::AddObjectPair(
        CObjectPairHash *this,
        IVP_Real_Object *pObject0,
        IVP_Real_Object *pObject1)
{
  if ( !this->IsObjectPairInHash(this, a2: pObject0, a3: pObject1) )
  {
    IVP_Collision_Filter_Exclusive_Pair::disable_collision_between_objects(
      this: &this->m_pairHash,
      obj0: pObject0,
      obj1: pObject1);
    CObjectPairHash::AddToObjectList(this, pObject: pObject0, pAdd: pObject1);
    CObjectPairHash::AddToObjectList(this, pObject: pObject1, pAdd: pObject0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E2A0
// Name: public: virtual void CEmptyCollisionListener::PostSimulationFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmptyCollisionListener::PostSimulationFrame(CDataManagerBase *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1009A670
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY CPredictable_Controller_Independant_Stub::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPredictable_Controller_Independant_Stub::get_controller_priority(IVP_Collision_Delegator *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100AEE30
// Name: public: void CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v2; // edx
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // si
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    *(_DWORD *)&this->m_Head = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEEA0
// Name: protected: unsigned short CUtlLinkedList<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<struct CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(bool)restrict
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // ecx
  unsigned __int16 index; // ax
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v9; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_22:
    v9 = &this->m_Memory.m_pMemory[(unsigned __int16)result];
    if ( multilist )
    {
      v9->m_Next = -1;
      v9->m_Previous = -1;
    }
    else
    {
      v9->m_Next = result;
      v9->m_Previous = result;
    }
    return result;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    LOWORD(result) = (m_nAllocationCount > 0) - 1;
  }
  else
  {
    index = this->m_LastAlloc.index;
    if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
      LOWORD(result) = -1;
    else
      LOWORD(result) = index + 1;
  }
  if ( (unsigned __int16)result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
      this: &this->m_Memory,
      num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      LOWORD(result) = (v7 > 0) - 1;
    }
    else
    {
      v8 = this->m_LastAlloc.index;
      LOWORD(result) = (unsigned __int16)(v8 + 1) >= v7 ? -1 : v8 + 1;
    }
    if ( (unsigned __int16)result >= v7 )
    {
      if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount < 10 )
      {
        ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`12'::__executeCount;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return 0xFFFF;
    }
  }
  if ( (_WORD)result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    this->m_LastAlloc.index = result;
    result = (unsigned __int16)result;
    goto LABEL_22;
  }
  if ( `CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal'::`19'::__executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100AF020
// Name: public: void CUtlLinkedList<struct CUtlMultiList<void __near *,unsigned short>::List_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<void __near *,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<CUtlMultiList<void *,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<void *,unsigned short>::List_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // di
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *v3; // eax
  int m_Previous; // ebx
  unsigned __int16 m_Next; // dx

  v2 = elem;
  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v3 = &this->m_Memory.m_pMemory[elem];
    if ( v3->m_Previous != elem )
    {
      m_Previous = v3->m_Previous;
      m_Next = v3->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
      {
        this->m_Head = m_Next;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
        v2 = elem;
      }
      if ( m_Next == 0xFFFF )
        this->m_Tail = m_Previous;
      else
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
      v3->m_Next = v2;
      v3->m_Previous = v2;
      --this->m_ElementCount;
    }
  }
}
