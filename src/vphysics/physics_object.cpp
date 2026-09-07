// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_object.cpp
// Functions: 134
// ============================================================

#include "vphysics\physics_object.h"

//------------------------------------------------------------------------------
// Address: 0x100068B0
// Name: public: virtual void __near * CPhysicsObject::GetGameData(void)const
// Source: json
//------------------------------------------------------------------------------
const IVP_Compact_Ledge *__thiscall CPhysicsObject::GetGameData(IVP_SurfaceManager_Ball *this)
{
  return this->compact_ledge;
}

//------------------------------------------------------------------------------
// Address: 0x10019650
// Name: public: virtual void CPhysicsObject::Wake(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::Wake(CPhysicsObject *this)
{
  IVP_Real_Object::ensure_in_simulation(this: this->m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10019660
// Name: public: virtual void CPhysicsObject::Sleep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::Sleep(CPhysicsObject *this)
{
  IVP_Real_Object::disable_simulation(this: this->m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10019670
// Name: public: void CPhysicsObject::NotifySleep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::NotifySleep(CPhysicsObject *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 21);
  if ( (v1 & 3) != 0 )
    *((_BYTE *)this + 21) = v1 & 0xFC | 2;
  else
    *((_BYTE *)this + 21) = v1 & 0xFC | 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019690
// Name: public: void CPhysicsObject::NotifyWake(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::NotifyWake(CPhysicsObject *this)
{
  *((_BYTE *)this + 20) &= ~0x40u;
  *((_BYTE *)this + 21) &= 0xFCu;
}

//------------------------------------------------------------------------------
// Address: 0x100196A0
// Name: public: virtual void CPhysicsObject::SetCallbackFlags(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetCallbackFlags(CPhysicsObject *this, unsigned __int16 callbackflags)
{
  this->m_callbacks = callbackflags;
}

//------------------------------------------------------------------------------
// Address: 0x100196B0
// Name: public: virtual unsigned short CPhysicsObject::GetCallbackFlags(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CPhysicsObject::GetCallbackFlags(CPhysicsObject *this)
{
  return this->m_callbacks;
}

//------------------------------------------------------------------------------
// Address: 0x100196C0
// Name: public: virtual void CPhysicsObject::SetGameFlags(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetGameFlags(CPhysicsObject *this, unsigned __int16 userFlags)
{
  this->m_gameFlags = userFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100196D0
// Name: public: virtual unsigned short CPhysicsObject::GetGameFlags(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CPhysicsObject::GetGameFlags(CPhysicsObject *this)
{
  return this->m_gameFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100196E0
// Name: public: virtual void CPhysicsObject::SetGameIndex(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetGameIndex(CPhysicsObject *this, unsigned __int16 gameIndex)
{
  this->m_gameIndex = gameIndex;
}

//------------------------------------------------------------------------------
// Address: 0x100196F0
// Name: public: virtual unsigned short CPhysicsObject::GetGameIndex(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CPhysicsObject::GetGameIndex(CPhysicsObject *this)
{
  return this->m_gameIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10019700
// Name: public: virtual void CPhysicsObject::EnableCollisions(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::EnableCollisions(CPhysicsObject *this@<ecx>, int a2@<esi>, bool enable)
{
  IVP_Real_Object *m_pObject; // ecx
  IPhysicsFrictionSnapshot *i; // esi

  if ( enable )
  {
    m_pObject = this->m_pObject;
    this->m_callbacks |= 0x800u;
    IVP_Real_Object::enable_collision_detection(this: m_pObject, enable: IVP_TRUE);
    this->m_callbacks &= ~0x800u;
  }
  else
  {
    if ( this->IsCollisionEnabled(this) )
    {
      for ( i = (IPhysicsFrictionSnapshot *)((int (__thiscall *)(CPhysicsObject *, int))this->CreateFrictionSnapshot)(
                                              a1: this,
                                              a2); i->IsValid(this: i); i->NextFrictionData(this: i) )
        i->MarkContactForDelete(this: i);
      i->DeleteAllMarkedContacts(this: i, a2: true);
      this->DestroyFrictionSnapshot(this, a2: i);
    }
    IVP_Real_Object::enable_collision_detection(this: this->m_pObject, enable: IVP_FALSE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100197A0
// Name: public: virtual void CPhysicsObject::SetCollisionHints(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetCollisionHints(CPhysicsObject *this, unsigned int collisionHints)
{
  *(_DWORD *)&this->m_pObject->flags ^= (*(_DWORD *)&this->m_pObject->flags ^ (collisionHints << 9)) & 0x200;
  *(_DWORD *)&this->m_pObject->flags ^= (*(_DWORD *)&this->m_pObject->flags ^ (collisionHints >> 1 << 10)) & 0x400;
}

//------------------------------------------------------------------------------
// Address: 0x100197E0
// Name: public: virtual unsigned int CPhysicsObject::GetCollisionHints(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysicsObject::GetCollisionHints(CPhysicsObject *this)
{
  IVP_Real_Object_Fast::<unnamed_type_flags> flags; // ecx
  unsigned int result; // eax

  flags = this->m_pObject->flags;
  result = (*(_WORD *)&flags & 0x200) != 0;
  if ( (*(_WORD *)&flags & 0x400) != 0 )
    result |= 2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019810
// Name: public: virtual bool CPhysicsObject::IsMoveable(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsMoveable(CPhysicsObject *this)
{
  return !this->IsStatic(this) && this->IsMotionEnabled(this);
}

//------------------------------------------------------------------------------
// Address: 0x10019840
// Name: public: virtual void CPhysicsObject::SetDragCoefficient(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::SetDragCoefficient(
        CPhysicsObject *this@<ecx>,
        char a2@<efl>,
        float *pDrag,
        float *pAngularDrag)
{
  int v4; // eax
  float m_angDragCoefficient; // xmm1_4
  bool v6; // cf
  bool v7; // zf
  char v8; // sf
  char v9; // of
  char v10; // pf

  if ( pDrag != nullptr )
    this->m_dragCoefficient = *pDrag;
  HIWORD(v4) = HIWORD(pAngularDrag);
  if ( pAngularDrag != nullptr )
    this->m_angDragCoefficient = *pAngularDrag;
  if ( this->m_dragCoefficient == 0.0
    && (m_angDragCoefficient = this->m_angDragCoefficient,
        v6 = m_angDragCoefficient < 0.0,
        v10 = 0,
        v7 = m_angDragCoefficient == 0.0,
        v8 = 0,
        v9 = 0,
        BYTE1(v4) = a2,
        m_angDragCoefficient == 0.0) )
  {
    LOBYTE(v4) = 0;
    this->EnableDrag(this, a2: v4);
  }
  else
  {
    this->EnableDrag(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100198A0
// Name: public: virtual void CPhysicsObject::SyncWith(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SyncWith(CPhysicsObject *this, IPhysicsObject *pOther)
{
  char v4; // al
  char bOtherCollision; // [esp+Eh] [ebp-12h]
  char bOtherMotion; // [esp+12h] [ebp-Eh]
  char bOtherDrag; // [esp+16h] [ebp-Ah]
  char bOtherGravity; // [esp+1Ah] [ebp-6h]
  char bDrag; // [esp+1Eh] [ebp-2h]
  char bGravity; // [esp+1Fh] [ebp-1h]
  char bCollision_3; // [esp+2Bh] [ebp+Bh]

  bOtherCollision = pOther->IsCollisionEnabled(this: pOther);
  bOtherGravity = pOther->IsGravityEnabled(this: pOther);
  bOtherDrag = pOther->IsDragEnabled(this: pOther);
  bOtherMotion = pOther->IsMotionEnabled(this: pOther);
  bCollision_3 = this->IsCollisionEnabled(this);
  bGravity = this->IsGravityEnabled(this);
  bDrag = this->IsDragEnabled(this);
  v4 = this->IsMotionEnabled(this);
  if ( bCollision_3 != bOtherCollision || bGravity != bOtherGravity || bDrag != bOtherDrag || v4 != bOtherMotion )
  {
    this->EnableCollisions(this, a2: bOtherCollision);
    this->EnableGravity(this, a2: bOtherGravity);
    this->EnableDrag(this, a2: bOtherDrag);
    this->EnableMotion(this, a2: bOtherMotion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019970
// Name: public: virtual void CPhysicsObject::EnableMotion(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::EnableMotion(CPhysicsObject *this, bool enable)
{
  if ( !this->IsStatic(this) && this->IsMotionEnabled(this) != enable )
  {
    IVP_Real_Object::set_pinned(this: this->m_pObject, is_pinned: (IVP_BOOL)!enable);
    if ( enable && this->IsHinged(this) )
      this->BecomeHinged(this, a2: ((*((unsigned __int8 *)this + 21) >> 2) & 7) - 1);
    this->RecheckCollisionFilter(this);
    this->RecheckContactPoints(this, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100199F0
// Name: public: virtual class IPhysicsFrictionSnapshot __near * CPhysicsObject::CreateFrictionSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsFrictionSnapshot *__thiscall CPhysicsObject::CreateFrictionSnapshot(CPhysicsObject *this)
{
  return CreateFrictionSnapshot(pObject: this->m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10019A00
// Name: public: virtual void CPhysicsObject::SetBuoyancyRatio(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetBuoyancyRatio(CPhysicsObject *this, float ratio)
{
  this->m_buoyancyRatio = ratio;
}

//------------------------------------------------------------------------------
// Address: 0x10019A30
// Name: public: virtual void CPhysicsObject::SetShadow(float,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetShadow(
        CPhysicsObject *this,
        float maxSpeed,
        float maxAngularSpeed,
        bool allowPhysicsMovement,
        bool allowPhysicsRotation)
{
  CShadowController *m_pShadow; // eax
  CShadowController *ShadowController; // eax

  m_pShadow = this->m_pShadow;
  if ( m_pShadow != nullptr )
  {
    ((void (__thiscall *)(IPhysicsShadowController *, _DWORD, _DWORD))m_pShadow->MaxSpeed)(
      a1: &m_pShadow->IPhysicsShadowController,
      a2: LODWORD(maxSpeed),
      a3: LODWORD(maxAngularSpeed));
  }
  else
  {
    *((_BYTE *)this + 20) &= 0xE0u;
    ShadowController = CreateShadowController(
                         pObject: this,
                         allowTranslation: allowPhysicsMovement,
                         allowRotation: allowPhysicsRotation);
    this->m_pShadow = ShadowController;
    ((void (__thiscall *)(IPhysicsShadowController *, _DWORD, _DWORD))ShadowController->MaxSpeed)(
      a1: &ShadowController->IPhysicsShadowController,
      a2: LODWORD(maxSpeed),
      a3: LODWORD(maxAngularSpeed));
    this->RecheckCollisionFilter(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019AB0
// Name: public: virtual void CPhysicsObject::UpdateShadow(class Vector const __near &,class QAngle const __near &,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::UpdateShadow(
        CPhysicsObject *this,
        const Vector *targetPosition,
        const QAngle *targetAngles,
        bool tempDisableGravity,
        float timeOffset)
{
  CShadowController *m_pShadow; // edi

  m_pShadow = this->m_pShadow;
  if ( m_pShadow != nullptr )
  {
    if ( tempDisableGravity != (*((_BYTE *)this + 20) & 0x1F) )
    {
      *((_BYTE *)this + 20) ^= (tempDisableGravity ^ *((_BYTE *)this + 20)) & 0x1F;
      if ( m_pShadow->AllowsTranslation(this: &m_pShadow->IPhysicsShadowController) )
        this->EnableGravity(this, a2: (*((_BYTE *)this + 20) & 0x1F) == 0);
    }
    CShadowController::Update_Internal(
      this: this->m_pShadow,
      position: targetPosition,
      angles: targetAngles,
      secondsToArrival: timeOffset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019B20
// Name: public: virtual class IPhysicsShadowController __near * CPhysicsObject::GetShadowController(void)const
// Source: json
//------------------------------------------------------------------------------
IPhysicsShadowController *__thiscall CPhysicsObject::GetShadowController(CPhysicsObject *this)
{
  CShadowController *m_pShadow; // eax

  m_pShadow = this->m_pShadow;
  if ( m_pShadow != nullptr )
    return &m_pShadow->IPhysicsShadowController;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019B40
// Name: public: virtual void CPhysicsObject::SetMaterialIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetMaterialIndex(CPhysicsObject *this, int materialIndex)
{
  IVP_Real_Object *m_pObject; // ecx
  CPhysicsObject_vtbl *v4; // edx
  IPhysicsShadowController *v5; // eax

  if ( this->m_materialIndex != materialIndex )
  {
    this->m_materialIndex = materialIndex;
    this->m_pObject->l_default_material = physprops->GetIVPMaterial(this: physprops, a2: materialIndex);
    m_pObject = this->m_pObject;
    this->m_callbacks |= 0x800u;
    IVP_Real_Object::recompile_material_changed(this: m_pObject);
    v4 = this->__vftable;
    this->m_callbacks &= ~0x800u;
    if ( v4->GetShadowController(this) != nullptr )
    {
      v5 = this->GetShadowController(this);
      v5->ObjectMaterialChanged(this: v5, a2: materialIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019BC0
// Name: public: virtual float CPhysicsObject::ComputeShadowControl(struct hlshadowcontrol_params_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CPhysicsObject::ComputeShadowControl(
        CPhysicsObject *this,
        const hlshadowcontrol_params_t *params,
        float secondsToArrival,
        float dt)
{
  return ComputeShadowControllerHL(pObject: this, params, secondsToArrival, dt);
}

//------------------------------------------------------------------------------
// Address: 0x10019BF0
// Name: class ISaveRestoreOps __near * MaterialIndexDataOps(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialIndexOps *__cdecl MaterialIndexDataOps()
{
  return &g_MaterialIndexDataOps;
}

//------------------------------------------------------------------------------
// Address: 0x10019C00
// Name: public: virtual void CPredictedPhysicsObject::SetErrorDelta_Position(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::SetErrorDelta_Position(CPredictedPhysicsObject *this, const Vector *vPosition)
{
  this->m_ActiveBackup.origin.x = this->m_ActiveBackup.origin.x + vPosition->x;
  this->m_ActiveBackup.origin.y = vPosition->y + this->m_ActiveBackup.origin.y;
  this->m_ActiveBackup.origin.z = vPosition->z + this->m_ActiveBackup.origin.z;
  this->m_vOriginErrorDelta = *vPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10019C70
// Name: public: virtual void CPredictedPhysicsObject::SetErrorDelta_Velocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::SetErrorDelta_Velocity(CPredictedPhysicsObject *this, const Vector *vVelocity)
{
  this->m_ActiveBackup.velocity.x = this->m_ActiveBackup.velocity.x + vVelocity->x;
  this->m_ActiveBackup.velocity.y = vVelocity->y + this->m_ActiveBackup.velocity.y;
  this->m_ActiveBackup.velocity.z = vVelocity->z + this->m_ActiveBackup.velocity.z;
  this->m_vVelocityErrorDelta = *vVelocity;
}

//------------------------------------------------------------------------------
// Address: 0x10019D10
// Name: public: virtual bool CPhysicsObject::IsAsleep(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsAsleep(CPhysicsObject *this)
{
  return (*((_BYTE *)this + 21) & 3) != 0 && (*(_BYTE *)&this->m_pObject->physical_core->IVP_Core_Fast_Static & 4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019D30
// Name: public: virtual bool CPhysicsObject::IsStatic(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsStatic(CPhysicsObject *this)
{
  return (*(_BYTE *)&this->m_pObject->physical_core->IVP_Core_Fast_Static & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019D40
// Name: public: virtual void CPhysicsObject::RecheckCollisionFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RecheckCollisionFilter(CPhysicsObject *this)
{
  unsigned __int16 m_callbacks; // ax
  IVP_Real_Object *m_pObject; // ecx

  m_callbacks = this->m_callbacks;
  if ( (m_callbacks & 0x400) == 0 )
  {
    m_pObject = this->m_pObject;
    this->m_callbacks = m_callbacks | 0x800;
    IVP_Real_Object::recheck_collision_filter(this: m_pObject);
    this->m_callbacks &= ~0x800u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019D70
// Name: public: virtual void CPhysicsObject::RecheckContactPoints(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RecheckContactPoints(CPhysicsObject *this, bool bSearchForNewContacts)
{
  IVP_Collision_Filter *collision_filter; // ebx
  IPhysicsFrictionSnapshot *i; // esi
  int v5; // eax

  if ( bSearchForNewContacts )
    IVP_Real_Object::force_grow_friction_system(this: this->m_pObject);
  collision_filter = this->m_pObject->environment->collision_filter;
  for ( i = this->CreateFrictionSnapshot(this); i->IsValid(this: i); i->NextFrictionData(this: i) )
  {
    v5 = (int)i->GetObject(this: i, a2: 1);
    if ( collision_filter->check_objects_for_collision_detection(
           this: collision_filter,
           a2: this->m_pObject,
           a3: *(IVP_Real_Object **)(v5 + 8)) == 0 )
      i->MarkContactForDelete(this: i);
  }
  i->DeleteAllMarkedContacts(this: i, a2: true);
  this->DestroyFrictionSnapshot(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x10019E10
// Name: public: class CPhysicsEnvironment __near * CPhysicsObject::GetVPhysicsEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsEnvironment *__thiscall CPhysicsObject::GetVPhysicsEnvironment(CPhysicsObject *this)
{
  return (CPhysicsEnvironment *)this->m_pObject->environment->client_data;
}

//------------------------------------------------------------------------------
// Address: 0x10019E20
// Name: public: virtual bool CPhysicsObject::IsGravityEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsObject::IsGravityEnabled(CPhysicsObject *this)
{
  IVP_Core *physical_core; // ecx
  IVP_Standard_Gravity_Controller *standard_gravity_controller; // esi
  int n_elems; // edx
  int v5; // eax
  void **i; // ecx

  if ( this->IsStatic(this) )
    return 0;
  physical_core = this->m_pObject->physical_core;
  standard_gravity_controller = physical_core->environment->standard_gravity_controller;
  n_elems = physical_core->controllers_of_core.n_elems;
  v5 = 0;
  if ( physical_core->controllers_of_core.n_elems == 0 )
    return 0;
  for ( i = physical_core->controllers_of_core.elems; *i != standard_gravity_controller; ++i )
  {
    if ( ++v5 >= n_elems )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019E70
// Name: public: virtual bool CPhysicsObject::IsDragEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsObject::IsDragEnabled(CPhysicsObject *this)
{
  IVP_Real_Object *m_pObject; // eax
  void *v3; // esi
  IVP_Core *physical_core; // edx
  int n_elems; // ecx
  int v6; // eax
  void **i; // edx

  if ( this->IsStatic(this) )
    return 0;
  m_pObject = this->m_pObject;
  v3 = *((void **)m_pObject->environment->client_data + 2);
  physical_core = m_pObject->physical_core;
  n_elems = physical_core->controllers_of_core.n_elems;
  v6 = 0;
  if ( physical_core->controllers_of_core.n_elems == 0 )
    return 0;
  for ( i = physical_core->controllers_of_core.elems; *i != v3; ++i )
  {
    if ( ++v6 >= n_elems )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019EC0
// Name: public: virtual bool CPhysicsObject::IsMotionEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsMotionEnabled(CPhysicsObject *this)
{
  return (*(_BYTE *)&this->m_pObject->physical_core->IVP_Core_Fast_Static & 0x10) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019EE0
// Name: public: virtual void CPhysicsObject::EnableGravity(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::EnableGravity(CPhysicsObject *this, bool enable)
{
  IVP_Core *physical_core; // ecx
  IVP_Controller *standard_gravity_controller; // [esp-4h] [ebp-8h]

  if ( !this->IsStatic(this) && enable != this->IsGravityEnabled(this) )
  {
    physical_core = this->m_pObject->physical_core;
    standard_gravity_controller = physical_core->environment->standard_gravity_controller;
    if ( enable )
      IVP_Core::add_core_controller(this: physical_core, add_cntrl: standard_gravity_controller);
    else
      IVP_Core::rem_core_controller(this: physical_core, rem_cntrl: standard_gravity_controller);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F30
// Name: public: virtual void CPhysicsObject::SetUseAlternateGravity(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetUseAlternateGravity(CPhysicsObject *this, bool bSet)
{
  *(_WORD *)&this->m_pObject->physical_core->IVP_Core_Fast_Static = *(_WORD *)&this->m_pObject->physical_core->IVP_Core_Fast_Static
                                                                  & 0xFFDF
                                                                  | (32 * bSet);
}

//------------------------------------------------------------------------------
// Address: 0x10019F60
// Name: public: virtual void CPhysicsObject::EnableDrag(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::EnableDrag(CPhysicsObject *this, bool enable)
{
  IVP_Real_Object *m_pObject; // eax
  IVP_Core *physical_core; // ecx
  IVP_Controller *v5; // [esp-4h] [ebp-8h]

  if ( !this->IsStatic(this) && enable != this->IsDragEnabled(this) )
  {
    m_pObject = this->m_pObject;
    v5 = *((IVP_Controller **)m_pObject->environment->client_data + 2);
    physical_core = m_pObject->physical_core;
    if ( enable )
      IVP_Core::add_core_controller(this: physical_core, add_cntrl: v5);
    else
      IVP_Core::rem_core_controller(this: physical_core, rem_cntrl: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019FB0
// Name: protected: void CPhysicsObject::RecomputeDragBases(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RecomputeDragBases(CPhysicsObject *this)
{
  IPhysicsCollision_vtbl *v2; // edi
  int v3; // eax
  IPhysicsCollision_vtbl *v4; // edi
  const CPhysCollide *v5; // eax
  float (__thiscall *GetInvMass)(IPhysicsObject *); // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  double v13; // st7
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  IVP_Core *physical_core; // eax
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm4_4
  float v24; // xmm1_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  Vector dragMins; // [esp+4h] [ebp-44h] BYREF
  Vector dragMaxs; // [esp+10h] [ebp-38h] BYREF
  Vector delta; // [esp+1Ch] [ebp-2Ch]
  Vector areaFractions; // [esp+28h] [ebp-20h] BYREF
  float v33; // [esp+34h] [ebp-14h]
  float v34; // [esp+38h] [ebp-10h]
  float v35; // [esp+3Ch] [ebp-Ch]
  float v36; // [esp+40h] [ebp-8h]
  float v37; // [esp+44h] [ebp-4h]

  if ( !this->IsStatic(this) && this->GetCollide(this) != nullptr )
  {
    v2 = physcollision->__vftable;
    v3 = ((int (__thiscall *)(CPhysicsObject *, Vector *, QAngle *))this->GetCollide)(
           a1: this,
           a2: &vec3_origin,
           a3: &vec3_angle);
    ((void (__thiscall *)(IPhysicsCollision *, Vector *, Vector *, int))v2->CollideGetAABB)(
      a1: physcollision,
      a2: &dragMins,
      a3: &dragMaxs,
      a4: v3);
    v4 = physcollision->__vftable;
    v5 = this->GetCollide(this);
    v4->CollideGetOrthographicAreas(this: physcollision, result: &areaFractions, a3: v5);
    GetInvMass = this->GetInvMass;
    v7 = fabs(g_PhysicsUnits.unitScaleMeters * (float)(dragMaxs.x - dragMins.x));
    v8 = fabs(COERCE_FLOAT(COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMeters * (float)(dragMaxs.z - dragMins.z)) ^ _mask__NegFloat_));
    v9 = fabs(g_PhysicsUnits.unitScaleMeters * (float)(dragMaxs.y - dragMins.y));
    v10 = (float)(v9 * v8) * areaFractions.x;
    delta.y = v8;
    delta.z = v9;
    v11 = (float)(v9 * v7) * areaFractions.y;
    v12 = (float)(v8 * v7) * areaFractions.z;
    delta.x = v7;
    this->m_dragBasis.x = v10;
    this->m_dragBasis.y = v11;
    this->m_dragBasis.z = v12;
    v13 = ((double (__thiscall *)(CPhysicsObject *))GetInvMass)(a1: this);
    x = delta.x;
    y = delta.y;
    z = delta.z;
    this->m_dragBasis.x = this->m_dragBasis.x * v13;
    v17 = x * 0.5;
    v18 = y * 0.5;
    v19 = z * 0.5;
    this->m_dragBasis.y = this->m_dragBasis.y * v13;
    this->m_dragBasis.z = v13 * this->m_dragBasis.z;
    physical_core = this->m_pObject->physical_core;
    v37 = v17 * v17;
    v33 = physical_core->inv_rot_inertia.k[0];
    v36 = v18 * v18;
    v21 = (float)((float)((float)((float)((float)((float)((float)(v18 * v18) * 0.33333334) * v17) * (float)(v17 * v17))
                                + (float)((float)((float)((float)(v18 * v18) * 0.5) * (float)(v18 * v18)) * v17))
                        + (float)((float)((float)(v18 * v18) * v17) * (float)(v19 * v19)))
                * v33)
        * areaFractions.z;
    v22 = (float)((float)((float)((float)(v19 * v19) * 0.5) * (float)(v19 * v19)) * v17)
        + (float)((float)((float)((float)(v19 * v19) * 0.33333334) * v17) * (float)(v17 * v17));
    v23 = (float)((float)(v19 * v19) * v17) * (float)(v18 * v18);
    v24 = v17 * v17;
    this->m_angDragBasis.x = v21 + (float)((float)((float)(v22 + v23) * v33) * areaFractions.y);
    v35 = v19 * v19;
    v34 = v19 * v19;
    v33 = physical_core->inv_rot_inertia.k[1];
    v25 = v36;
    v26 = (float)((float)((float)((float)((float)((float)((float)(v19 * v19) * 0.5) * (float)(v19 * v19)) * v18)
                                + (float)((float)((float)((float)(v19 * v19) * 0.33333334) * v18) * v36))
                        + (float)((float)((float)(v19 * v19) * v18) * v24))
                * v33)
        * areaFractions.x;
    v27 = (float)((float)((float)((float)((float)((float)(v24 * 0.5) * v24) * v18)
                                + (float)((float)((float)(v24 * 0.33333334) * v18) * v36))
                        + (float)((float)(v24 * v18) * (float)(v19 * v19)))
                * v33)
        * areaFractions.z;
    v28 = v37;
    this->m_angDragBasis.y = v26 + v27;
    this->m_angDragBasis.z = (float)((float)((float)((float)((float)((float)((float)(v25 * 0.5) * v25) * v19)
                                                           + (float)((float)((float)(v25 * 0.33333334) * v19) * v35))
                                                   + (float)((float)(v25 * v19) * v28))
                                           * physical_core->inv_rot_inertia.k[2])
                                   * areaFractions.x)
                           + (float)((float)((float)((float)((float)((float)((float)(v28 * 0.5) * v28) * v19)
                                                           + (float)((float)((float)(v28 * 0.33333334) * v19) * v35))
                                                   + (float)((float)(v28 * v19) * v25))
                                           * physical_core->inv_rot_inertia.k[2])
                                   * areaFractions.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A300
// Name: public: bool CPhysicsObject::IsControlledByGame(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsControlledByGame(CPhysicsObject *this)
{
  return this->m_pShadow != nullptr
      && !this->m_pShadow->IsPhysicallyControlled(this: &this->m_pShadow->IPhysicsShadowController)
      || (this->m_callbacks & 0x2000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001A330
// Name: public: virtual class Vector CPhysicsObject::GetMassCenterLocalSpace(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsObject::GetMassCenterLocalSpace(CPhysicsObject *this, Vector *result)
{
  IVP_Real_Object *m_pObject; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  m_pObject = this->m_pObject;
  if ( (*(_DWORD *)&m_pObject->flags & 0x800) != 0 )
  {
    *result = vec3_origin;
  }
  else
  {
    v4 = m_pObject->shift_core_f_object.k[1] * g_PhysicsUnits.unitScaleMetersInv;
    v5 = m_pObject->shift_core_f_object.k[2] * g_PhysicsUnits.unitScaleMetersInv;
    result->x = -(float)(m_pObject->shift_core_f_object.k[0] * g_PhysicsUnits.unitScaleMetersInv);
    result->y = -v5;
    result->z = -(float)-v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A3B0
// Name: public: virtual float CPhysicsObject::GetMass(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsObject::GetMass(CPhysicsObject *this)
{
  return this->m_pObject->physical_core->rot_inertia.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x1001A3C0
// Name: public: virtual float CPhysicsObject::GetInvMass(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsObject::GetInvMass(CPhysicsObject *this)
{
  return this->m_pObject->physical_core->inv_rot_inertia.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x1001A3D0
// Name: public: virtual void CPhysicsObject::SetInertia(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::SetInertia(CPhysicsObject *this@<ecx>, float a2@<ebp>, const Vector *inertia)
{
  IVP_Real_Object *m_pObject; // ecx
  float v4; // xmm0_4
  float v5; // xmm2_4
  _DWORD v6[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point ri; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  ri.k[1] = a2;
  ri.k[2] = retaddr;
  m_pObject = this->m_pObject;
  v4 = fabs(COERCE_FLOAT(LODWORD(inertia->z) ^ _mask__NegFloat_));
  v5 = fabs(inertia->y);
  v6[0] = fabs(inertia->x);
  *(float *)&v6[1] = v4;
  *(float *)&v6[2] = v5;
  IVP_Core::set_rotation_inertia(this: m_pObject->physical_core, r: (const IVP_U_Float_Point *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x1001A440
// Name: public: virtual void CPhysicsObject::GetDamping(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::GetDamping(CPhysicsObject *this, float *speed, float *rot)
{
  IVP_Core *physical_core; // eax

  physical_core = this->m_pObject->physical_core;
  if ( speed != nullptr )
    *speed = physical_core->speed_damp_factor;
  if ( rot != nullptr )
    *rot = physical_core->rot_speed_damp_factor.k[0];
}

//------------------------------------------------------------------------------
// Address: 0x1001A470
// Name: public: virtual void CPhysicsObject::SetDamping(float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetDamping(CPhysicsObject *this, float *speed, float *rot)
{
  IVP_Core *physical_core; // eax
  float v4; // xmm0_4

  physical_core = this->m_pObject->physical_core;
  if ( speed != nullptr )
    physical_core->speed_damp_factor = *speed;
  if ( rot != nullptr )
  {
    v4 = *rot;
    physical_core->rot_speed_damp_factor.k[0] = *rot;
    physical_core->rot_speed_damp_factor.k[1] = v4;
    physical_core->rot_speed_damp_factor.k[2] = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A4B0
// Name: protected: void CPhysicsObject::SetVolume(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetVolume(CPhysicsObject *this, float volume)
{
  CPhysicsObject *matDensity; // [esp+0h] [ebp-4h] BYREF
  float density; // [esp+Ch] [ebp+8h]
  float densitya; // [esp+Ch] [ebp+8h]

  matDensity = this;
  this->m_volume = volume;
  if ( volume == 0.0 )
  {
    this->m_buoyancyRatio = 1.0;
  }
  else
  {
    if ( volume < 5.0 )
      volume = 5.0;
    density = g_PhysicsUnits.unitScaleMeters
            * (g_PhysicsUnits.unitScaleMeters
             * g_PhysicsUnits.unitScaleMeters)
            * volume;
    densitya = ((double (__thiscall *)(CPhysicsObject *))this->GetMass)(a1: this) / density;
    ((void (__stdcall *)(_DWORD, CPhysicsObject **, _DWORD, _DWORD, _DWORD))physprops->GetPhysicsProperties)(
      a1: this->m_materialIndex,
      a2: &matDensity,
      a3: 0,
      a4: 0,
      a5: 0);
    this->m_buoyancyRatio = densitya / *(float *)&matDensity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A540
// Name: public: virtual void CPhysicsObject::LocalToWorld(class Vector __near *,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::LocalToWorld(CPhysicsObject *this, Vector *worldPosition, const Vector *localPosition)
{
  __int64 v3; // xmm0_8
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  __int64 in1; // [esp+30h] [ebp-Ch] BYREF
  float z; // [esp+38h] [ebp-4h]

  this->GetPositionMatrix(this, a2: &matrix);
  v3 = *(_QWORD *)&localPosition->x;
  z = localPosition->z;
  in1 = v3;
  VectorTransform((const float *)&in1, in2: &matrix, out: &worldPosition->x);
}

//------------------------------------------------------------------------------
// Address: 0x1001A580
// Name: public: virtual void CPhysicsObject::WorldToLocal(class Vector __near *,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::WorldToLocal(CPhysicsObject *this, Vector *localPosition, const Vector *worldPosition)
{
  __int64 v3; // xmm0_8
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  __int64 in1; // [esp+30h] [ebp-Ch] BYREF
  float z; // [esp+38h] [ebp-4h]

  this->GetPositionMatrix(this, a2: &matrix);
  v3 = *(_QWORD *)&worldPosition->x;
  z = worldPosition->z;
  in1 = v3;
  VectorITransform((const float *)&in1, in2: &matrix, out: &localPosition->x);
}

//------------------------------------------------------------------------------
// Address: 0x1001A5C0
// Name: public: virtual void CPhysicsObject::LocalToWorldVector(class Vector __near *,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::LocalToWorldVector(
        CPhysicsObject *this,
        Vector *worldVector,
        const Vector *localVector)
{
  __int64 v3; // xmm0_8
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  __int64 in1; // [esp+30h] [ebp-Ch] BYREF
  float z; // [esp+38h] [ebp-4h]

  this->GetPositionMatrix(this, a2: &matrix);
  v3 = *(_QWORD *)&localVector->x;
  z = localVector->z;
  in1 = v3;
  VectorRotate((const float *)&in1, in2: &matrix, out: &worldVector->x);
}

//------------------------------------------------------------------------------
// Address: 0x1001A600
// Name: public: virtual void CPhysicsObject::WorldToLocalVector(class Vector __near *,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::WorldToLocalVector(
        CPhysicsObject *this,
        Vector *localVector,
        const Vector *worldVector)
{
  __int64 v3; // xmm0_8
  matrix3x4_t matrix; // [esp+0h] [ebp-3Ch] BYREF
  __int64 in1; // [esp+30h] [ebp-Ch] BYREF
  float z; // [esp+38h] [ebp-4h]

  this->GetPositionMatrix(this, a2: &matrix);
  v3 = *(_QWORD *)&worldVector->x;
  z = worldVector->z;
  in1 = v3;
  VectorIRotate((const float *)&in1, in2: &matrix, out: &localVector->x);
}

//------------------------------------------------------------------------------
// Address: 0x1001A640
// Name: public: virtual void CPhysicsObject::CalculateForceOffset(class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::CalculateForceOffset(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const Vector *forceVector,
        const Vector *worldPosition,
        Vector *centerForce,
        Vector *centerTorque)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float *physical_core; // esi
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point cross_point_dir; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Float_Point point_d_ws; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Float_Point force; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  force.k[1] = a2;
  force.k[2] = retaddr;
  point_d_ws.k[1] = forceVector->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(point_d_ws.k[2]) = COERCE_UNSIGNED_INT(forceVector->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  x = worldPosition->x;
  y = worldPosition->y;
  point_d_ws.hesse_val = forceVector->y * g_PhysicsUnits.unitScaleMeters;
  physical_core = (float *)this->m_pObject->physical_core;
  v9 = COERCE_FLOAT(COERCE_UNSIGNED_INT(worldPosition->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_)
     - physical_core[37];
  v10 = (float)(y * g_PhysicsUnits.unitScaleMeters) - physical_core[38];
  cross_point_dir.k[1] = (float)(x * g_PhysicsUnits.unitScaleMeters) - physical_core[36];
  cross_point_dir.k[2] = v9;
  cross_point_dir.hesse_val = v10;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)v14,
    v1: (IVP_U_Float_Point *)&cross_point_dir.k[1],
    v2: (IVP_U_Float_Point *)&point_d_ws.k[1]);
  v11 = (float)((float)(physical_core[30] * v14[1]) + (float)(physical_core[26] * v14[0]))
      + (float)(physical_core[34] * v14[2]);
  v12 = (float)((float)(physical_core[28] * v14[1]) + (float)(v14[0] * physical_core[24]))
      + (float)(physical_core[32] * v14[2]);
  centerTorque->z = -(float)((float)((float)((float)(physical_core[29] * v14[1]) + (float)(physical_core[25] * v14[0]))
                                   + (float)(physical_core[33] * v14[2]))
                           * 57.29578);
  centerTorque->y = v11 * 57.29578;
  centerTorque->x = v12 * 57.29578;
  v13 = g_PhysicsUnits.unitScaleMetersInv * point_d_ws.hesse_val;
  centerForce->z = -(float)(g_PhysicsUnits.unitScaleMetersInv * point_d_ws.k[2]);
  centerForce->y = v13;
  centerForce->x = g_PhysicsUnits.unitScaleMetersInv * point_d_ws.k[1];
}

//------------------------------------------------------------------------------
// Address: 0x1001A7F0
// Name: public: virtual void CPhysicsObject::CalculateVelocityOffset(class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::CalculateVelocityOffset(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const Vector *forceVector,
        const Vector *worldPosition,
        Vector *centerVelocity,
        Vector *centerAngularVelocity)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float *physical_core; // esi
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float hesse_val; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point point_d_ws; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Float_Point force; // [esp+10h] [ebp-20h] BYREF
  IVP_U_Float_Point cross_point_dir; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  cross_point_dir.k[1] = a2;
  cross_point_dir.k[2] = retaddr;
  point_d_ws.k[1] = forceVector->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(point_d_ws.k[2]) = COERCE_UNSIGNED_INT(forceVector->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  x = worldPosition->x;
  y = worldPosition->y;
  point_d_ws.hesse_val = forceVector->y * g_PhysicsUnits.unitScaleMeters;
  physical_core = (float *)this->m_pObject->physical_core;
  v9 = COERCE_FLOAT(COERCE_UNSIGNED_INT(worldPosition->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_)
     - physical_core[37];
  v10 = (float)(y * g_PhysicsUnits.unitScaleMeters) - physical_core[38];
  v21[0] = (float)(x * g_PhysicsUnits.unitScaleMeters) - physical_core[36];
  v21[1] = v9;
  v21[2] = v10;
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&force.k[1],
    v1: (const IVP_U_Float_Point *)v21,
    v2: (IVP_U_Float_Point *)&point_d_ws.k[1]);
  v11 = (float)((float)(physical_core[30] * force.k[2]) + (float)(physical_core[26] * force.k[1]))
      + (float)(physical_core[34] * force.hesse_val);
  v12 = (float)((float)(physical_core[28] * force.k[2]) + (float)(force.k[1] * physical_core[24]))
      + (float)(physical_core[32] * force.hesse_val);
  force.k[2] = (float)((float)(physical_core[29] * force.k[2]) + (float)(physical_core[25] * force.k[1]))
             + (float)(physical_core[33] * force.hesse_val);
  force.k[1] = v12;
  force.hesse_val = v11;
  v13 = physical_core[14] * v11;
  v14 = physical_core[12] * v12;
  force.k[2] = physical_core[13] * force.k[2];
  force.hesse_val = v13;
  force.k[1] = v14;
  centerAngularVelocity->z = -(float)(force.k[2] * 57.29578);
  centerAngularVelocity->y = v13 * 57.29578;
  v15 = point_d_ws.k[2];
  hesse_val = point_d_ws.hesse_val;
  centerAngularVelocity->x = v14 * 57.29578;
  v17 = physical_core[15];
  v18 = (float)(v15 * v17) * g_PhysicsUnits.unitScaleMetersInv;
  v19 = point_d_ws.k[1] * v17;
  v20 = g_PhysicsUnits.unitScaleMetersInv * (float)(hesse_val * v17);
  centerVelocity->z = -v18;
  centerVelocity->y = v20;
  centerVelocity->x = g_PhysicsUnits.unitScaleMetersInv * v19;
}

//------------------------------------------------------------------------------
// Address: 0x1001A9F0
// Name: public: virtual void CPhysicsObject::GetImplicitVelocity(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::GetImplicitVelocity(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        Vector *velocity,
        Vector *angularVelocity)
{
  IVP_Core *physical_core; // esi
  float v5; // xmm0_4
  float x; // xmm0_4
  float v7; // xmm0_4
  _DWORD v8[3]; // [esp-Ch] [ebp-3Ch] BYREF
  Quaternion q; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Quat q_core_f_core; // [esp+10h] [ebp-20h] BYREF
  Vector axis; // [esp+20h] [ebp-10h] BYREF
  float retaddr; // [esp+30h] [ebp+0h]

  axis.y = a2;
  axis.z = retaddr;
  if ( velocity != nullptr || angularVelocity != nullptr )
  {
    physical_core = this->m_pObject->physical_core;
    if ( velocity != nullptr )
    {
      v5 = physical_core->delta_world_f_core_psis.k[2] * g_PhysicsUnits.unitScaleMetersInv;
      LODWORD(velocity->z) = COERCE_UNSIGNED_INT(physical_core->delta_world_f_core_psis.k[1] * g_PhysicsUnits.unitScaleMetersInv)
                           ^ _mask__NegFloat_;
      velocity->y = v5;
      velocity->x = physical_core->delta_world_f_core_psis.k[0] * g_PhysicsUnits.unitScaleMetersInv;
    }
    if ( angularVelocity != nullptr )
    {
      IVP_U_Quat::set_invert_mult(
        this: (IVP_U_Quat *)&q.y,
        q1: &physical_core->q_world_f_core_last_psi,
        q2: &physical_core->q_world_f_core_next_psi);
      v8[0] = LODWORD(q.y);
      v8[1] = LODWORD(q.z);
      v8[2] = LODWORD(q.w);
      x = -1.0;
      if ( q_core_f_core.x >= -1.0 )
      {
        x = 1.0;
        if ( q_core_f_core.x <= 1.0 )
          x = q_core_f_core.x;
      }
      q.x = x;
      QuaternionAxisAngle(q: (const Quaternion *)v8, axis: (Vector *)&q_core_f_core.y, angle: &axis.x);
      v7 = physical_core->i_delta_time * axis.x;
      angularVelocity->x = q_core_f_core.y * v7;
      angularVelocity->y = q_core_f_core.w * v7;
      LODWORD(angularVelocity->z) = COERCE_UNSIGNED_INT(q_core_f_core.z * v7) ^ _mask__NegFloat_;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AB30
// Name: public: virtual void CPhysicsObject::GetVelocity(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::GetVelocity(CPhysicsObject *this, Vector *velocity, Vector *angularVelocity)
{
  IVP_Core *physical_core; // eax
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm1_4

  if ( velocity != nullptr || angularVelocity != nullptr )
  {
    physical_core = this->m_pObject->physical_core;
    if ( velocity != nullptr )
    {
      v4 = physical_core->speed.k[0] + physical_core->speed_change.k[0];
      v5 = g_PhysicsUnits.unitScaleMetersInv * (float)(physical_core->speed.k[2] + physical_core->speed_change.k[2]);
      velocity->z = -(float)(g_PhysicsUnits.unitScaleMetersInv
                           * (float)(physical_core->speed.k[1] + physical_core->speed_change.k[1]));
      velocity->y = v5;
      velocity->x = g_PhysicsUnits.unitScaleMetersInv * v4;
    }
    if ( angularVelocity != nullptr )
    {
      v6 = (float)(physical_core->rot_speed.k[2] + physical_core->rot_speed_change.k[2]) * 57.29578;
      v7 = (float)(physical_core->rot_speed.k[0] + physical_core->rot_speed_change.k[0]) * 57.29578;
      angularVelocity->z = -(float)((float)(physical_core->rot_speed.k[1] + physical_core->rot_speed_change.k[1])
                                  * 57.29578);
      angularVelocity->y = v6;
      angularVelocity->x = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AC20
// Name: public: virtual void CPhysicsObject::GetVelocityAtPoint(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::GetVelocityAtPoint(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const Vector *worldPosition,
        Vector *pVelocity)
{
  IVP_Core *physical_core; // esi
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point av_ws; // [esp+0h] [ebp-30h] BYREF
  IVP_U_Float_Point rotSpeed; // [esp+10h] [ebp-20h]
  IVP_U_Point pos; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  pos.k[1] = a2;
  pos.k[2] = retaddr;
  physical_core = this->m_pObject->physical_core;
  v5 = physical_core->rot_speed_change.k[0] + physical_core->rot_speed.k[0];
  rotSpeed.k[1] = worldPosition->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(rotSpeed.k[2]) = COERCE_UNSIGNED_INT(worldPosition->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v6 = physical_core->rot_speed.k[2] + physical_core->rot_speed_change.k[2];
  rotSpeed.hesse_val = worldPosition->y * g_PhysicsUnits.unitScaleMeters;
  v7 = physical_core->rot_speed.k[1] + physical_core->rot_speed_change.k[1];
  av_ws.k[1] = v5;
  av_ws.k[2] = v7;
  av_ws.hesse_val = v6;
  IVP_U_Matrix3::vmult3(
    this: &physical_core->m_world_f_core_last_psi,
    p_in: (IVP_U_Float_Point *)&av_ws.k[1],
    p_out: (IVP_U_Float_Point *)v18);
  v8 = rotSpeed.hesse_val - physical_core->m_world_f_core_last_psi.vv.k[2];
  v9 = rotSpeed.k[1] - physical_core->m_world_f_core_last_psi.vv.k[0];
  v10 = rotSpeed.k[2] - physical_core->m_world_f_core_last_psi.vv.k[1];
  v11 = v18[1] * v8;
  v12 = (float)(v18[2] * v9) - (float)(v8 * v18[0]);
  v13 = physical_core->speed_change.k[0];
  v14 = physical_core->speed.k[2] + (float)((float)(v10 * v18[0]) - (float)(v18[1] * v9));
  v15 = physical_core->speed.k[0] + (float)(v11 - (float)(v18[2] * v10));
  v16 = (float)(physical_core->speed_change.k[1] + (float)(physical_core->speed.k[1] + v12))
      * g_PhysicsUnits.unitScaleMetersInv;
  v17 = (float)(physical_core->speed_change.k[2] + v14) * g_PhysicsUnits.unitScaleMetersInv;
  LODWORD(pVelocity->z) = LODWORD(v16) ^ _mask__NegFloat_;
  pVelocity->y = v17;
  pVelocity->x = (float)(v13 + v15) * g_PhysicsUnits.unitScaleMetersInv;
}

//------------------------------------------------------------------------------
// Address: 0x1001ADB0
// Name: public: virtual void CPhysicsObject::SetPosition(class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::SetPosition(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *worldPosition,
        const QAngle *angles,
        bool isTeleport)
{
  IVP_Real_Object *m_pObject; // ecx
  _BYTE v10[12]; // [esp+14h] [ebp-2Ch] BYREF
  IVP_U_Quat rot; // [esp+20h] [ebp-20h] BYREF
  IVP_U_Point pos; // [esp+30h] [ebp-10h] BYREF
  float retaddr; // [esp+40h] [ebp+0h]

  pos.k[1] = a2;
  pos.k[2] = retaddr;
  ((void (__thiscall *)(CPhysicsObject *, const Vector *, const QAngle *, _DWORD, _DWORD, int, int))this->UpdateShadow)(
    a1: this,
    a2: worldPosition,
    a3: angles,
    a4: 0,
    a5: 0,
    a6: a3,
    a7: a4);
  rot.y = worldPosition->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(rot.z) = COERCE_UNSIGNED_INT(worldPosition->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  rot.w = worldPosition->y * g_PhysicsUnits.unitScaleMeters;
  ConvertRotationToIVP(a1: (int)&pos.k[1], angles, out: (IVP_U_Quat *)v10);
  m_pObject = this->m_pObject;
  if ( (*(_DWORD *)&m_pObject->flags & 0x100) != 0 && isTeleport )
  {
    this->EnableCollisions(this, a2: false);
    IVP_Real_Object::beam_object_to_new_position(
      this: this->m_pObject,
      rotation_world_f_object: (const IVP_U_Quat *)v10,
      position_w_f_o: (const IVP_U_Point *)&rot.y,
      optimize_for_repeated_calls: IVP_FALSE);
    this->EnableCollisions(this, a2: true);
  }
  else
  {
    IVP_Real_Object::beam_object_to_new_position(
      this: m_pObject,
      rotation_world_f_object: (const IVP_U_Quat *)v10,
      position_w_f_o: (const IVP_U_Point *)&rot.y,
      optimize_for_repeated_calls: IVP_TRUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AEA0
// Name: public: virtual bool CPhysicsObject::GetContactPoint(class Vector __near *,class IPhysicsObject __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsObject::GetContactPoint(
        CPhysicsObject *this,
        Vector *contactPoint,
        IPhysicsObject **contactObject)
{
  IVP_Synapse_Friction *friction_synapses; // eax
  int contact_point_offset; // ecx
  float v6; // xmm2_4
  float v7; // xmm1_4

  friction_synapses = this->m_pObject->friction_synapses;
  if ( friction_synapses == nullptr )
    return 0;
  if ( contactPoint != nullptr )
  {
    contact_point_offset = friction_synapses->contact_point_offset;
    v6 = *(float *)((char *)&friction_synapses[5].contact_point_offset + contact_point_offset);
    v7 = g_PhysicsUnits.unitScaleMetersInv * *(float *)((char *)&friction_synapses[6].next + contact_point_offset);
    LODWORD(contactPoint->z) = COERCE_UNSIGNED_INT(
                                 g_PhysicsUnits.unitScaleMetersInv
                               * *(float *)((char *)&friction_synapses[5].edge + contact_point_offset))
                             ^ _mask__NegFloat_;
    contactPoint->y = v7;
    contactPoint->x = g_PhysicsUnits.unitScaleMetersInv * v6;
  }
  if ( contactObject != nullptr )
    *contactObject = (IPhysicsObject *)GetOppositeSynapseObject(pfriction: friction_synapses)->client_data;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF20
// Name: public: virtual void CPhysicsObject::RemoveShadowController(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RemoveShadowController(CPhysicsObject *this)
{
  CShadowController *m_pShadow; // eax
  void *client_data; // ecx

  m_pShadow = this->m_pShadow;
  if ( m_pShadow != nullptr )
  {
    client_data = this->m_pObject->environment->client_data;
    (*(void (__thiscall **)(void *, IPhysicsShadowController *))(*(_DWORD *)client_data + 104))(
      a1: client_data,
      a2: &m_pShadow->IPhysicsShadowController);
    this->m_pShadow = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AF50
// Name: public: float CPhysicsObject::GetDragInDirection(class IVP_U_Float_Point const __near &)const
// Source: json
//------------------------------------------------------------------------------
long double __userpurge CPhysicsObject::GetDragInDirection@<st0>(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Float_Point *velocity)
{
  float v5[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point local; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  local.k[1] = a2;
  local.k[2] = retaddr;
  IVP_U_Matrix3::vimult3(
    this: &this->m_pObject->physical_core->m_world_f_core_last_psi,
    p_in: velocity,
    p_out: (IVP_U_Float_Point *)v5);
  return (fabs(this->m_dragBasis.y * v5[1]) + fabs(this->m_dragBasis.x * v5[0]) + fabs(this->m_dragBasis.z * v5[2]))
       * this->m_dragCoefficient;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFB0
// Name: public: float CPhysicsObject::GetAngularDragInDirection(class IVP_U_Float_Point const __near &)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysicsObject::GetAngularDragInDirection(
        CPhysicsObject *this,
        const IVP_U_Float_Point *angVelocity)
{
  return (fabs(this->m_angDragBasis.y * angVelocity->k[1])
        + fabs(this->m_angDragBasis.x * angVelocity->k[0])
        + fabs(this->m_angDragBasis.z * angVelocity->k[2]))
       * this->m_angDragCoefficient;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFE0
// Name: public: virtual char const __near * CPhysicsObject::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsObject::GetName(CPhysicsObject *this)
{
  return this->m_pObject->name;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFF0
// Name: public: virtual float CPhysicsObject::GetEnergy(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsObject::GetEnergy(CPhysicsObject *this)
{
  IVP_Core *physical_core; // eax

  physical_core = this->m_pObject->physical_core;
  return (0.5
        * (physical_core->rot_speed.k[1] * (float)(physical_core->rot_inertia.k[1] * physical_core->rot_speed.k[1])
         + physical_core->rot_speed.k[0] * (float)(physical_core->rot_speed.k[0] * physical_core->rot_inertia.k[0])
         + physical_core->rot_speed.k[2] * (float)(physical_core->rot_inertia.k[2] * physical_core->rot_speed.k[2]))
        + physical_core->rot_inertia.hesse_val
        * 0.5
        * (physical_core->speed.k[1] * physical_core->speed.k[1]
         + physical_core->speed.k[0] * physical_core->speed.k[0]
         + physical_core->speed.k[2] * physical_core->speed.k[2]))
       * 1550.0032;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0C0
// Name: public: virtual float CPhysicsObject::GetSphereRadius(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsObject::GetSphereRadius(CPhysicsObject *this)
{
  if ( (*((_BYTE *)this + 21) & 0xE0) == 0x40 )
    return this->m_pObject->extra_radius * g_PhysicsUnits.unitScaleMetersInv;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0E0
// Name: public: virtual void CPhysicsObject::SetSphereRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetSphereRadius(CPhysicsObject *this, float radius)
{
  if ( (*((_BYTE *)this + 21) & 0xE0) == 0x40 )
    IVP_Real_Object::set_extra_radius(this: this->m_pObject, new_radius: g_PhysicsUnits.unitScaleMeters * radius);
}

//------------------------------------------------------------------------------
// Address: 0x1001B110
// Name: public: virtual float CPhysicsObject::CalculateLinearDrag(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
long double __userpurge CPhysicsObject::CalculateLinearDrag@<st0>(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const Vector *unitDirection)
{
  IVP_Real_Object *m_pObject; // edx
  IVP_U_Float_Point v6; // [esp-1Ch] [ebp-2Ch] BYREF
  _DWORD v7[3]; // [esp-Ch] [ebp-1Ch] BYREF
  IVP_U_Float_Point ivpDir; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  ivpDir.k[1] = a2;
  ivpDir.k[2] = retaddr;
  v7[0] = LODWORD(unitDirection->x);
  v7[1] = LODWORD(unitDirection->z) ^ _mask__NegFloat_;
  m_pObject = this->m_pObject;
  v7[2] = LODWORD(unitDirection->y);
  IVP_U_Matrix3::vimult3(
    this: &m_pObject->physical_core->m_world_f_core_last_psi,
    p_in: (const IVP_U_Float_Point *)v7,
    p_out: &v6);
  return (fabs(this->m_dragBasis.y * v6.k[1]) + fabs(this->m_dragBasis.x * v6.k[0]) + fabs(this->m_dragBasis.z * v6.k[2]))
       * this->m_dragCoefficient;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1A0
// Name: public: virtual float CPhysicsObject::CalculateAngularDrag(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CPhysicsObject::CalculateAngularDrag(
        CPhysicsObject *this,
        const Vector *objectSpaceRotationAxis)
{
  return (fabs(objectSpaceRotationAxis->x * this->m_angDragBasis.x)
        + fabs(-objectSpaceRotationAxis->z * this->m_angDragBasis.y)
        + fabs(objectSpaceRotationAxis->y * this->m_angDragBasis.z))
       * this->m_angDragCoefficient
       * 0.017453292;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1E0
// Name: public: virtual void CPhysicsObject::BecomeTrigger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::BecomeTrigger(CPhysicsObject *this)
{
  IPhysicsShadowController *v2; // eax
  CPhysicsObject_vtbl *v3; // edx
  bool (__thiscall *IsCollisionEnabled)(IPhysicsObject *); // eax
  bool v5; // al
  CPhysicsObject_vtbl *v6; // edx
  IVP_Template_Phantom trigger; // [esp+4h] [ebp-1Ch] BYREF
  BOOL enableCollisions; // [esp+1Ch] [ebp-4h]

  if ( !this->IsTrigger(this) )
  {
    if ( this->GetShadowController(this) != nullptr )
    {
      v2 = this->GetShadowController(this);
      v2->UseShadowMaterial(this: v2, a2: false);
    }
    this->EnableDrag(this, a2: false);
    this->EnableGravity(this, a2: false);
    IVP_Template_Phantom::IVP_Template_Phantom(this: &trigger);
    v3 = this->__vftable;
    trigger.manage_intruding_cores = IVP_TRUE;
    trigger.manage_sleeping_cores = IVP_TRUE;
    trigger.dont_check_for_unmoveables = IVP_TRUE;
    IsCollisionEnabled = v3->IsCollisionEnabled;
    trigger.exit_policy_extra_radius = 0.1;
    v5 = IsCollisionEnabled(this);
    v6 = this->__vftable;
    LOBYTE(enableCollisions) = v5;
    v6->EnableCollisions(this, a2: false);
    IVP_Real_Object::convert_to_phantom(this: this->m_pObject, tmpl: &trigger);
    CPhysicsEnvironment::PhantomAdd(
      this: (CPhysicsEnvironment *)this->m_pObject->environment->client_data,
      pObject: this);
    this->EnableCollisions(this, a2: enableCollisions);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B2A0
// Name: public: virtual void CPhysicsObject::RemoveTrigger(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RemoveTrigger(CPhysicsObject *this)
{
  IVP_Controller_Phantom *controller_phantom; // ecx

  controller_phantom = this->m_pObject->controller_phantom;
  if ( controller_phantom != nullptr )
    ((void (__thiscall *)(IVP_Controller_Phantom *, int))controller_phantom->dtr_IVP_Listener_Object)(
      a1: controller_phantom,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001B2C0
// Name: public: virtual bool CPhysicsObject::IsTrigger(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsTrigger(CPhysicsObject *this)
{
  return this->m_pObject->controller_phantom != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2D0
// Name: public: virtual bool CPhysicsObject::IsFluid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsFluid(CPhysicsObject *this)
{
  IVP_Controller_Phantom *controller_phantom; // eax

  controller_phantom = this->m_pObject->controller_phantom;
  return controller_phantom != nullptr && controller_phantom->client_data != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2F0
// Name: public: virtual void CPhysicsObject::BecomeHinged(int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CPhysicsObject::BecomeHinged(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int localAxis)
{
  IVP_Core *physical_core; // esi
  void (__thiscall *SetMass)(IPhysicsObject *, float); // eax
  int v8; // eax
  CPhysicsObject_vtbl *v9; // edx
  __int64 v11; // [esp+18h] [ebp-2Ch]
  _BYTE v12[20]; // [esp+20h] [ebp-24h] OVERLAPPED
  float savedRI[3]; // [esp+34h] [ebp-10h]
  float retaddr; // [esp+44h] [ebp+0h]

  savedRI[1] = a2;
  savedRI[2] = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsObject *, int, int))this->IsMoveable)(a1: this, a2: a3, a3: a4) != 0 )
  {
    savedRI[0] = this->GetMass(this);
    physical_core = this->m_pObject->physical_core;
    SetMass = this->SetMass;
    *(float *)&v12[8] = physical_core->inv_rot_inertia.k[0];
    *(float *)&v12[12] = physical_core->inv_rot_inertia.k[1];
    ((void (__thiscall *)(CPhysicsObject *, int))SetMass)(a1: this, a2: 1195593728);
    v11 = *(_QWORD *)physical_core->inv_rot_inertia.k;
    *(_DWORD *)&v12[16] = localAxis;
    *(_QWORD *)v12 = *(_QWORD *)&physical_core->inv_rot_inertia.k[2];
    v8 = ConvertCoordinateAxisToIVP(axisIndex: localAxis);
    v9 = this->__vftable;
    *(float *)&v12[4 * v8 - 8] = *(float *)&v12[4 * v8 + 8];
    ((void (__thiscall *)(CPhysicsObject *, _DWORD))v9->SetMass)(a1: this, a2: LODWORD(savedRI[0]));
    *(_QWORD *)physical_core->inv_rot_inertia.k = v11;
    *(_QWORD *)&physical_core->inv_rot_inertia.k[2] = *(_QWORD *)v12;
  }
  *((_BYTE *)this + 21) ^= (*((_BYTE *)this + 21) ^ (4 * (localAxis + 1))) & 0x1C;
}

//------------------------------------------------------------------------------
// Address: 0x1001B3D0
// Name: public: virtual void CPhysicsObject::RemoveHinged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::RemoveHinged(CPhysicsObject *this)
{
  IVP_Real_Object *m_pObject; // eax

  m_pObject = this->m_pObject;
  *((_BYTE *)this + 21) &= 0xE3u;
  IVP_Core::calc_calc(this: m_pObject->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x1001B3F0
// Name: public: virtual void CPhysicsObject::OutputDebugInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::OutputDebugInfo(CPhysicsObject *this)
{
  unsigned __int64 v2; // st7
  double v3; // st7
  IVP_Core *physical_core; // eax
  int v5; // edi
  void *v6; // ecx
  const char *v7; // eax
  __int16 v8; // ax
  const char *v9; // edi
  bool v10; // al
  bool v11; // al
  unsigned __int16 v12; // ax
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // ax
  int m_materialIndex; // eax
  const char *v16; // eax
  const CPhysCollide *v17; // eax
  double v18; // [esp+28h] [ebp-84h]
  double v19; // [esp+30h] [ebp-7Ch]
  double v20; // [esp+38h] [ebp-74h]
  double v21; // [esp+40h] [ebp-6Ch]
  double v22; // [esp+44h] [ebp-68h]
  int v23; // [esp+44h] [ebp-68h]
  int v24; // [esp+48h] [ebp-64h]
  int v25; // [esp+48h] [ebp-64h]
  Vector angSpeed; // [esp+58h] [ebp-54h] BYREF
  Vector speed; // [esp+64h] [ebp-48h] BYREF
  Vector inertia; // [esp+70h] [ebp-3Ch] BYREF
  Vector invInertia; // [esp+7Ch] [ebp-30h] BYREF
  float damp; // [esp+88h] [ebp-24h] BYREF
  float angDamp; // [esp+8Ch] [ebp-20h] BYREF
  float matDensity; // [esp+90h] [ebp-1Ch] BYREF
  float matThickness; // [esp+94h] [ebp-18h] BYREF
  float matFriction; // [esp+98h] [ebp-14h] BYREF
  float matElasticity; // [esp+9Ch] [ebp-10h] BYREF
  const char *v36; // [esp+A0h] [ebp-Ch]
  const char *v37; // [esp+A4h] [ebp-8h]
  const char *v38; // [esp+A8h] [ebp-4h]

  _Msg(a1: "-----------------\nObject: %s\n", this->m_pObject->name);
  *(double *)&v2 = ((double (__thiscall *)(CPhysicsObject *))this->GetInvMass)(a1: this);
  v3 = ((double (__thiscall *)(CPhysicsObject *, _DWORD, _DWORD))this->GetMass)(a1: this, a2: v2, a3: HIDWORD(v2));
  _Msg(a1: "Mass: %.1f (inv %.3f)\n", v3, v22);
  this->GetInertia(this, result: &inertia);
  this->GetInvInertia(this, result: &invInertia);
  _Msg(
    a1: "Inertia: %.2f, %.2f, %.2f (inv %.3f, %.3f, %.3f)\n",
    inertia.x,
    inertia.y,
    inertia.z,
    invInertia.x,
    invInertia.y,
    invInertia.z);
  this->GetVelocity(this, a2: &speed, a3: &angSpeed);
  _Msg(a1: "Velocity: %.2f, %.2f, %.2f \n", speed.x, speed.y, speed.z);
  _Msg(a1: "Ang Velocity: %.2f, %.2f, %.2f \n", angSpeed.x, angSpeed.y, angSpeed.z);
  this->GetDamping(this, a2: &damp, a3: &angDamp);
  _Msg(a1: "Damping %.2f linear, %.2f angular\n", damp, angDamp);
  _Msg(
    a1: "Linear Drag: %.2f, %.2f, %.2f (factor %.2f)\n",
    this->m_dragBasis.x,
    this->m_dragBasis.y,
    this->m_dragBasis.z,
    this->m_dragCoefficient);
  _Msg(
    a1: "Angular Drag: %.2f, %.2f, %.2f (factor %.2f)\n",
    this->m_angDragBasis.x,
    this->m_angDragBasis.y,
    this->m_angDragBasis.z,
    this->m_angDragCoefficient);
  if ( this->IsHinged(this) )
    _Msg(
      a1: "Hinged on %s axis\n",
      *((const char **)&g_MaterialIndexDataOps.__vftable + ((*((unsigned __int8 *)this + 21) >> 2) & 7)));
  _Msg(a1: "attached to %d controllers\n", this->m_pObject->physical_core->controllers_of_core.n_elems);
  physical_core = this->m_pObject->physical_core;
  v5 = physical_core->controllers_of_core.n_elems - 1;
  if ( physical_core->controllers_of_core.n_elems != 0 )
  {
    do
    {
      v6 = this->m_pObject->physical_core->controllers_of_core.elems[v5];
      v7 = (const char *)(*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 24))(a1: v6);
      _Msg(a1: "%d) %s\n", v5--, v7);
    }
    while ( v5 >= 0 );
  }
  v8 = this->GetCallbackFlags(this);
  v37 = "Debug! ";
  if ( v8 >= 0 )
    v37 = str;
  v9 = "Disabled";
  if ( this->IsStatic(this) )
  {
    v38 = "Static";
  }
  else
  {
    v10 = this->IsMotionEnabled(this);
    v38 = "Enabled";
    if ( !v10 )
      v38 = "Disabled";
  }
  if ( this->IsCollisionEnabled(this) )
    v9 = "Enabled";
  v11 = this->IsAsleep(this);
  v36 = "Asleep";
  if ( !v11 )
    v36 = "Awake";
  v12 = this->GetGameIndex(this);
  v13 = ((int (__thiscall *)(CPhysicsObject *, _DWORD))this->GetGameFlags)(a1: this, a2: v12);
  v14 = ((int (__thiscall *)(CPhysicsObject *, _DWORD))this->GetCallbackFlags)(a1: this, a2: v13);
  _Msg(a1: "State: %s, Collision %s, Motion %s, %sFlags %04X (game %04x, index %d)\n", v36, v9, v38, v37, v14, v23, v24);
  m_materialIndex = this->m_materialIndex;
  matDensity = 0.0;
  matThickness = 0.0;
  matFriction = 0.0;
  matElasticity = 0.0;
  physprops->GetPhysicsProperties(
    this: physprops,
    a2: m_materialIndex,
    a3: &matDensity,
    a4: &matThickness,
    a5: &matFriction,
    a6: &matElasticity);
  v16 = (const char *)((int (__thiscall *)(IPhysicsSurfacePropsInternal *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))physprops->GetPropName)(
                        a1: physprops,
                        a2: this->m_materialIndex,
                        a3: COERCE_UNSIGNED_INT64(matDensity),
                        a4: HIDWORD(COERCE_UNSIGNED_INT64(matDensity)),
                        a5: COERCE_UNSIGNED_INT64(matThickness),
                        a6: HIDWORD(COERCE_UNSIGNED_INT64(matThickness)),
                        a7: COERCE_UNSIGNED_INT64(matFriction),
                        a8: HIDWORD(COERCE_UNSIGNED_INT64(matFriction)),
                        a9: COERCE_UNSIGNED_INT64(matElasticity),
                        a10: HIDWORD(COERCE_UNSIGNED_INT64(matElasticity)));
  _Msg(a1: "Material: %s : density(%.1f), thickness(%.2f), friction(%.2f), elasticity(%.2f)\n", v16, v18, v19, v20, v21);
  if ( ((int (__thiscall *)(CPhysicsObject *, int))this->GetCollide)(a1: this, a2: v25) != 0 )
  {
    v17 = this->GetCollide(this);
    OutputCollideDebugInfo(pCollisionModel: v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B800
// Name: public: virtual bool CPhysicsObject::IsAttachedToConstraint(bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsObject::IsAttachedToConstraint(CPhysicsObject *this, bool bExternalOnly)
{
  IVP_Real_Object *m_pObject; // eax
  IVP_Core *physical_core; // eax
  int v5; // edi
  IVP_Controller *v6; // esi
  void *v7; // eax

  m_pObject = this->m_pObject;
  if ( m_pObject == nullptr )
    return 0;
  physical_core = m_pObject->physical_core;
  v5 = physical_core->controllers_of_core.n_elems - 1;
  if ( physical_core->controllers_of_core.n_elems == 0 )
    return 0;
  while ( 1 )
  {
    v6 = (IVP_Controller *)this->m_pObject->physical_core->controllers_of_core.elems[v5];
    if ( v6->get_controller_priority(this: v6) == IVP_CP_CONSTRAINTS )
    {
      if ( !bExternalOnly )
        break;
      v7 = this->GetGameData(this);
      if ( IsExternalConstraint(pLCS: v6, pGameData: v7) )
        break;
    }
    if ( --v5 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B880
// Name: InitObjectTemplate
// Source: json
//------------------------------------------------------------------------------
void __usercall InitObjectTemplate(
        IVP_Template_Real_Object *objectTemplate@<esi>,
        int materialIndex@<eax>,
        objectparams_t *pParams@<edi>,
        bool isStatic)
{
  int v4; // xmm1_4
  float mass; // xmm0_4
  IPhysicsSurfacePropsInternal_vtbl *v6; // edx
  IVP_Material *v7; // eax
  float inertia; // xmm0_4
  float rotdamping; // xmm0_4

  *(float *)&v4 = 0.1;
  objectTemplate->mass = pParams->mass;
  mass = objectTemplate->mass;
  if ( mass < 0.1 || (*(float *)&v4 = 50000.0, mass > 50000.0) )
    mass = *(float *)&v4;
  objectTemplate->mass = mass;
  v6 = physprops->__vftable;
  if ( materialIndex < 0 )
    v7 = (IVP_Material *)((int (__stdcall *)(_DWORD))v6->GetIVPMaterial)(a1: 0);
  else
    v7 = (IVP_Material *)((int (__stdcall *)(int))v6->GetIVPMaterial)(a1: materialIndex);
  objectTemplate->material = v7;
  IVP_Template_Object::set_name(this: objectTemplate, s: pParams->pName);
  objectTemplate->rot_inertia_is_factor = IVP_TRUE;
  objectTemplate->physical_unmoveable = isStatic;
  inertia = pParams->inertia;
  if ( inertia > 0.0 )
  {
    if ( inertia > 9.9999998e17 )
      inertia = 9.9999998e17;
  }
  else
  {
    inertia = 1.0;
  }
  objectTemplate->rot_inertia.k[0] = inertia;
  objectTemplate->rot_inertia.k[1] = inertia;
  objectTemplate->rot_inertia.k[2] = inertia;
  rotdamping = pParams->rotdamping;
  objectTemplate->rot_speed_damp_factor.k[0] = rotdamping;
  objectTemplate->rot_speed_damp_factor.k[1] = rotdamping;
  objectTemplate->rot_speed_damp_factor.k[2] = rotdamping;
  objectTemplate->speed_damp_factor = pParams->damping;
  objectTemplate->auto_check_rot_inertia = pParams->rotInertiaLimit;
}

//------------------------------------------------------------------------------
// Address: 0x1001B960
// Name: public: virtual bool CDefSaveRestoreOps::Parse(struct SaveRestoreFieldInfo_t const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDefSaveRestoreOps::Parse(
        CDefSaveRestoreOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        const SaveRestoreFieldInfo_t *szValue)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001B970
// Name: public: virtual bool CPhysicsObject::IsCollisionEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsObject::IsCollisionEnabled(CPhysicsObject *this)
{
  return (*(_DWORD *)&this->m_pObject->flags & 0x100) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B980
// Name: public: void CPhysicsObject::WriteToTemplate(struct vphysics_save_cphysicsobject_t __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::WriteToTemplate(
        CPhysicsObject *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        vphysics_save_cphysicsobject_t *objectTemplate)
{
  Vector *v6; // eax
  __int128 v7; // xmm0
  CShadowController *m_pShadow; // eax
  IPhysicsShadowController *v9; // eax
  void (__thiscall *GetPosition)(IPhysicsObject *, Vector *, QAngle *); // eax
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // edx
  __int128 v13; // [esp-20h] [ebp-2Ch] BYREF
  Vector *p_velocity; // [esp-Ch] [ebp-18h] BYREF
  Vector *p_speedDamping; // [esp-8h] [ebp-14h]
  QAngle *p_rotSpeedDamping; // [esp-4h] [ebp-10h]
  int v17; // [esp+0h] [ebp-Ch]
  void *v18; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v17 = a2;
  v18 = retaddr;
  if ( (*((_BYTE *)this + 21) & 0xE0) == 0x40 )
  {
    objectTemplate->pCollide = nullptr;
    objectTemplate->sphereRadius = ((double (__thiscall *)(CPhysicsObject *, int, int))this->GetSphereRadius)(
                                     a1: this,
                                     a2: a3,
                                     a3: a4);
  }
  else
  {
    objectTemplate->pCollide = (const CPhysCollide *)((int (__thiscall *)(CPhysicsObject *, int, int))this->GetCollide)(
                                                       a1: this,
                                                       a2: a3,
                                                       a3: a4);
    objectTemplate->sphereRadius = 0.0;
  }
  objectTemplate->isStatic = ((int (__thiscall *)(CPhysicsObject *, int, void *))this->IsStatic)(
                               a1: this,
                               a2: v17,
                               a3: v18);
  objectTemplate->collisionEnabled = this->IsCollisionEnabled(this);
  objectTemplate->gravityEnabled = this->IsGravityEnabled(this);
  objectTemplate->dragEnabled = this->IsDragEnabled(this);
  objectTemplate->motionEnabled = this->IsMotionEnabled(this);
  objectTemplate->isAsleep = this->IsAsleep(this);
  objectTemplate->isTrigger = this->IsTrigger(this);
  objectTemplate->asleepSinceCreation = (*((_BYTE *)this + 20) & 0x40) != 0;
  objectTemplate->materialIndex = this->m_materialIndex;
  objectTemplate->mass = this->GetMass(this);
  v6 = this->GetInertia(this, result: &p_velocity);
  objectTemplate->rotInertia.x = v6->x;
  p_rotSpeedDamping = (QAngle *)&objectTemplate->rotSpeedDamping;
  objectTemplate->rotInertia.y = v6->y;
  p_speedDamping = (Vector *)&objectTemplate->speedDamping;
  objectTemplate->rotInertia.z = v6->z;
  this->GetDamping(this, a2: (float *)p_speedDamping, a3: (float *)p_rotSpeedDamping);
  objectTemplate->massCenterOverride.x = 0.0;
  objectTemplate->massCenterOverride.y = 0.0;
  objectTemplate->massCenterOverride.z = 0.0;
  this->GetMassCenterLocalSpace(this, result: (Vector *)&p_velocity);
  this->m_pObject->surface_manager->get_mass_center(
    this: this->m_pObject->surface_manager,
    a2: (IVP_U_Float_Point *)&v13);
  v7 = 0;
  *(float *)&v7 = fsqrt(
                    (float)((float)((float)((float)(g_PhysicsUnits.unitScaleMetersInv * *((float *)&v13 + 2))
                                          - *(float *)&p_speedDamping)
                                  * (float)((float)(g_PhysicsUnits.unitScaleMetersInv * *((float *)&v13 + 2))
                                          - *(float *)&p_speedDamping))
                          + (float)((float)(COERCE_FLOAT(
                                              COERCE_UNSIGNED_INT(*((float *)&v13 + 1) * g_PhysicsUnits.unitScaleMetersInv)
                                            ^ _mask__NegFloat_)
                                          - *(float *)&p_rotSpeedDamping)
                                  * (float)(COERCE_FLOAT(
                                              COERCE_UNSIGNED_INT(*((float *)&v13 + 1) * g_PhysicsUnits.unitScaleMetersInv)
                                            ^ _mask__NegFloat_)
                                          - *(float *)&p_rotSpeedDamping)))
                  + (float)((float)((float)(g_PhysicsUnits.unitScaleMetersInv * *(float *)&v13) - *(float *)&p_velocity)
                          * (float)((float)(g_PhysicsUnits.unitScaleMetersInv * *(float *)&v13) - *(float *)&p_velocity)));
  v13 = v7;
  if ( g_PhysicsUnits.collisionSweepIncrementalEpsilon < *(float *)&v7 )
    objectTemplate->massCenterOverride = *this->GetMassCenterLocalSpace(this, result: &p_velocity);
  objectTemplate->callbacks = this->m_callbacks;
  objectTemplate->gameFlags = this->m_gameFlags;
  objectTemplate->volume = this->m_volume;
  objectTemplate->dragCoefficient = this->m_dragCoefficient;
  objectTemplate->angDragCoefficient = this->m_angDragCoefficient;
  m_pShadow = this->m_pShadow;
  if ( m_pShadow != nullptr )
    v9 = &m_pShadow->IPhysicsShadowController;
  else
    v9 = nullptr;
  objectTemplate->pShadow = v9;
  objectTemplate->hasShadowController = this->m_pShadow != nullptr;
  objectTemplate->hasTouchedDynamic = (*((_BYTE *)this + 20) & 0x20) != 0;
  objectTemplate->collideType = *((_BYTE *)this + 21) >> 5;
  objectTemplate->gameIndex = this->m_gameIndex;
  objectTemplate->contentsMask = this->m_contentsMask;
  objectTemplate->hingeAxis = (*((unsigned __int8 *)this + 21) >> 2) & 7;
  GetPosition = this->GetPosition;
  p_rotSpeedDamping = &objectTemplate->angles;
  ((void (__thiscall *)(CPhysicsObject *, Vector *))GetPosition)(a1: this, a2: &objectTemplate->origin);
  GetVelocity = this->GetVelocity;
  p_speedDamping = &objectTemplate->angVelocity;
  p_velocity = &objectTemplate->velocity;
  ((void (__thiscall *)(CPhysicsObject *))GetVelocity)(a1: this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BBE0
// Name: public: struct vphysics_save_cphysicsobject_t __near & vphysics_save_cphysicsobject_t::operator=(struct vphysics_save_cphysicsobject_t const __near &)
// Source: json
//------------------------------------------------------------------------------
vphysics_save_cphysicsobject_t *__thiscall vphysics_save_cphysicsobject_t::operator=(
        vphysics_save_cphysicsobject_t *this,
        const vphysics_save_cphysicsobject_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD30
// Name: public: virtual bool CPredictedPhysicsObject::IsAsleep(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPredictedPhysicsObject::IsAsleep(CPredictedPhysicsObject *this)
{
  if ( this->m_pReferencedBackup != nullptr )
    return this->m_ActiveBackup.isAsleep;
  if ( (*((_BYTE *)&this->CPhysicsObject + 21) & 3) != 0 )
    return (*(_BYTE *)&this->m_pObject->physical_core->IVP_Core_Fast_Static & 4) == 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD60
// Name: public: virtual void CPredictedPhysicsObject::SetPosition(class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPredictedPhysicsObject::SetPosition(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const Vector *worldPosition,
        const QAngle *angles,
        bool isTeleport)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( this->m_pReferencedBackup != nullptr )
  {
    this->m_ActiveBackup.origin = *worldPosition;
    this->m_ActiveBackup.angles = *angles;
  }
  else
  {
    CPhysicsObject::SetPosition(this, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3, worldPosition, angles, isTeleport);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BDB0
// Name: public: virtual void CPredictedPhysicsObject::GetVelocity(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::GetVelocity(
        CPredictedPhysicsObject *this,
        Vector *velocity,
        Vector *angularVelocity)
{
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( velocity != nullptr )
      *velocity = this->m_ActiveBackup.velocity;
    if ( angularVelocity != nullptr )
      *angularVelocity = this->m_ActiveBackup.angVelocity;
  }
  else
  {
    CPhysicsObject::GetVelocity(this, velocity, angularVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BE10
// Name: public: virtual void CPredictedPhysicsObject::GetImplicitVelocity(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPredictedPhysicsObject::GetImplicitVelocity(
        CPredictedPhysicsObject *this,
        Vector *velocity,
        Vector *angularVelocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( velocity != nullptr )
      *velocity = this->m_ActiveBackup.velocity;
    if ( angularVelocity != nullptr )
      *angularVelocity = this->m_ActiveBackup.angVelocity;
  }
  else
  {
    CPhysicsObject::GetImplicitVelocity(this, a2: COERCE_FLOAT(&savedregs), velocity, angularVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BE70
// Name: public: virtual void CPredictedPhysicsObject::GetVelocityAtPoint(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CPredictedPhysicsObject::GetVelocityAtPoint(
        CPredictedPhysicsObject *this,
        const Vector *worldPosition,
        Vector *pVelocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( pVelocity != nullptr )
      *pVelocity = this->m_ActiveBackup.velocity;
  }
  else
  {
    CPhysicsObject::GetVelocityAtPoint(this, a2: COERCE_FLOAT(&savedregs), worldPosition, pVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BEB0
// Name: bool SavePhysicsObject(struct physsaveparams_t const __near &,class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall SavePhysicsObject@<al>(
        int a1@<edi>,
        int a2@<esi>,
        const physsaveparams_t *params,
        CPhysicsObject *pObject)
{
  vphysics_save_cphysicsobject_t objectTemplate; // [esp+4h] [ebp-94h] BYREF
  int savedregs; // [esp+98h] [ebp+0h] BYREF

  memset(dst: (unsigned __int8 *)&objectTemplate, value: 0, count: sizeof(objectTemplate));
  CPhysicsObject::WriteToTemplate(this: pObject, a2: (int)&savedregs, a3: a1, a4: a2, &objectTemplate);
  params->pSave->WriteAll(this: params->pSave, a2: &objectTemplate, a3: &vphysics_save_cphysicsobject_t::m_DataMap);
  return !objectTemplate.hasShadowController || SavePhysicsShadowController(params, pIShadow: objectTemplate.pShadow);
}

//------------------------------------------------------------------------------
// Address: 0x1001BF20
// Name: public: void CUtlMemory<struct CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>::Grow(
        CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pMemory; // edx
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
    v7 = 744 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *)_g_pMemAlloc->Realloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: m_pMemory,
                                                                                       a3: v7);
    else
      this->m_pMemory = (CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *)_g_pMemAlloc->Alloc_2(
                                                                                       this: _g_pMemAlloc,
                                                                                       a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BFC0
// Name: public: virtual bool CPhysicsObject::IsHinged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsObject::IsHinged(CPhysicsObject *this)
{
  return (*((_BYTE *)this + 21) & 0x1C) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BFD0
// Name: public: virtual unsigned int CPhysicsObject::GetContents(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CPhysicsObject::GetContents(CPhysicsObject *this)
{
  return this->m_contentsMask;
}

//------------------------------------------------------------------------------
// Address: 0x1001BFE0
// Name: public: virtual int CPhysicsObject::GetMaterialIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsObject::GetMaterialIndex(CPhysicsObject *this)
{
  return this->m_materialIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1001BFF0
// Name: public: void CPhysicsObject::Init(class CPhysCollide const __near *,class IVP_Real_Object __near *,int,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::Init(
        CPhysicsObject *this,
        const CPhysCollide *pCollisionModel,
        IVP_Real_Object *pObject,
        unsigned __int16 materialIndex,
        float volume,
        float drag,
        float angDrag)
{
  char v8; // dl

  this->m_pCollide = pCollisionModel;
  this->m_materialIndex = materialIndex;
  this->m_pObject = pObject;
  pObject->client_data = this;
  *((_BYTE *)this + 20) &= 0x60u;
  this->m_gameFlags = 0;
  v8 = *((_BYTE *)this + 21);
  *(_DWORD *)&this->m_activeIndex = 287834111;
  this->m_pGameData = nullptr;
  this->m_pShadow = nullptr;
  this->m_gameIndex = 0;
  *((_BYTE *)this + 21) = v8 & 0xFC | 2;
  this->m_dragBasis = vec3_origin;
  this->m_angDragBasis = vec3_origin;
  if ( this->IsStatic(this) || this->GetCollide(this) == nullptr )
  {
    angDrag = 0.0;
    drag = 0.0;
  }
  else
  {
    CPhysicsObject::RecomputeDragBases(this);
  }
  this->m_angDragCoefficient = angDrag;
  this->m_dragCoefficient = drag;
  CPhysicsObject::SetVolume(this, volume);
}

//------------------------------------------------------------------------------
// Address: 0x1001C0E0
// Name: public: virtual CPhysicsObject::~CPhysicsObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::~CPhysicsObject(CPhysicsObject *this)
{
  CShadowController *m_pShadow; // eax
  void *client_data; // ecx
  IVP_Real_Object *m_pObject; // eax
  IVP_Core *physical_core; // edi
  int n_elems; // eax
  int v7; // ebx
  void (__thiscall ***v8)(_DWORD, IVP_Core *); // ecx
  IVP_SurfaceManager *surface_manager; // edi
  void *v10; // ecx

  m_pShadow = this->m_pShadow;
  this->__vftable = (CPhysicsObject_vtbl *)&CPhysicsObject::`vftable';
  if ( m_pShadow != nullptr )
  {
    client_data = this->m_pObject->environment->client_data;
    (*(void (__thiscall **)(void *, IPhysicsShadowController *))(*(_DWORD *)client_data + 104))(
      a1: client_data,
      a2: &m_pShadow->IPhysicsShadowController);
    this->m_pShadow = nullptr;
  }
  m_pObject = this->m_pObject;
  if ( m_pObject != nullptr )
  {
    this->m_callbacks = 0;
    this->m_pGameData = nullptr;
    m_pObject->client_data = nullptr;
    physical_core = this->m_pObject->physical_core;
    if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
    {
      n_elems = physical_core->controllers_of_core.n_elems;
      if ( (_WORD)n_elems != 0 )
      {
        v7 = n_elems - 1;
        do
        {
          v8 = (void (__thiscall ***)(_DWORD, IVP_Core *))physical_core->controllers_of_core.elems[v7];
          (**v8)(a1: v8, a2: physical_core);
          --v7;
        }
        while ( v7 >= 0 );
      }
    }
    if ( (*((_BYTE *)this + 21) & 0xE0) == 0x40 )
      surface_manager = nullptr;
    else
      surface_manager = this->m_pObject->surface_manager;
    v10 = this->m_pObject->environment->client_data;
    if ( *((char *)this + 20) < 0
      || v10 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v10 + 316))(a1: v10) != 0
      || (*((_BYTE *)this + 20) & 0x20) == 0 )
    {
      CPolyhedron_AllocByNew::Release(this: (CPolyhedron_AllocByNew *)this->m_pObject);
    }
    else
    {
      IVP_Real_Object::delete_and_check_vicinity(this: this->m_pObject);
    }
    if ( surface_manager != nullptr )
      ((void (__thiscall *)(IVP_SurfaceManager *, int))surface_manager->dtr_IVP_SurfaceManager)(
        a1: surface_manager,
        a2: 1);
    this->__vftable = (CPhysicsObject_vtbl *)&IPhysicsObject::`vftable';
  }
  else
  {
    this->__vftable = (CPhysicsObject_vtbl *)&IPhysicsObject::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C1E0
// Name: public: virtual void CPhysicsObject::SetMass(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetMass(CPhysicsObject *this, float mass)
{
  char v3; // bl
  float new_mass; // xmm0_4

  v3 = 0;
  if ( !this->IsMoveable(this) )
  {
    v3 = 1;
    this->EnableMotion(this, a2: true);
  }
  new_mass = 0.0;
  if ( mass >= 0.0 )
  {
    new_mass = 50000.0;
    if ( mass <= 50000.0 )
      new_mass = mass;
  }
  IVP_Real_Object::change_mass(this: this->m_pObject, new_mass);
  CPhysicsObject::SetVolume(this, volume: this->m_volume);
  CPhysicsObject::RecomputeDragBases(this);
  if ( v3 != 0 )
    this->EnableMotion(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1001C260
// Name: public: virtual class Vector CPhysicsObject::GetInertia(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsObject::GetInertia(CPhysicsObject *this, Vector *result)
{
  IVP_Core *physical_core; // ecx
  float v4; // xmm0_4
  double v5; // st7

  physical_core = this->m_pObject->physical_core;
  v4 = physical_core->rot_inertia.k[1];
  result->y = physical_core->rot_inertia.k[2];
  v5 = physical_core->rot_inertia.k[0];
  LODWORD(result->z) = LODWORD(v4) ^ _mask__NegFloat_;
  result->x = v5;
  result->x = fabs(result->x);
  result->y = fabs(result->y);
  result->z = fabs(result->z);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C2C0
// Name: public: virtual class Vector CPhysicsObject::GetInvInertia(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsObject::GetInvInertia(CPhysicsObject *this, Vector *result)
{
  IVP_Core *physical_core; // ecx
  float v4; // xmm0_4
  double v5; // st7

  physical_core = this->m_pObject->physical_core;
  v4 = physical_core->inv_rot_inertia.k[1];
  result->y = physical_core->inv_rot_inertia.k[2];
  v5 = physical_core->inv_rot_inertia.k[0];
  LODWORD(result->z) = LODWORD(v4) ^ _mask__NegFloat_;
  result->x = v5;
  result->x = fabs(result->x);
  result->y = fabs(result->y);
  result->z = fabs(result->z);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C320
// Name: public: virtual void CPhysicsObject::ApplyForceCenter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::ApplyForceCenter(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *forceVector)
{
  float z; // xmm2_4
  float y; // xmm1_4
  IVP_Real_Object *m_pObject; // ecx
  float hesse_val; // xmm3_4
  float v10; // [esp-Ch] [ebp-1Ch] BYREF
  float v11; // [esp-8h] [ebp-18h]
  float v12; // [esp-4h] [ebp-14h]
  IVP_U_Float_Point tmp; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  tmp.k[1] = a2;
  tmp.k[2] = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsObject *, int))this->IsMoveable)(a1: this, a2: a3) != 0 )
  {
    z = forceVector->z;
    y = forceVector->y;
    m_pObject = this->m_pObject;
    v10 = forceVector->x * g_PhysicsUnits.unitScaleMeters;
    v12 = y * g_PhysicsUnits.unitScaleMeters;
    LODWORD(v11) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    hesse_val = m_pObject->physical_core->inv_rot_inertia.hesse_val;
    v10 = v10 * hesse_val;
    v11 = hesse_val * v11;
    v12 = (float)(y * g_PhysicsUnits.unitScaleMeters) * hesse_val;
    IVP_Real_Object::async_add_speed_object_ws(this: m_pObject, speed_vec: (const IVP_U_Float_Point *)&v10);
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C3E0
// Name: public: virtual void CPhysicsObject::ApplyForceOffset(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::ApplyForceOffset(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *forceVector,
        const Vector *worldPosition)
{
  float x; // xmm1_4
  IVP_Real_Object *m_pObject; // edx
  float z; // xmm2_4
  float y; // xmm1_4
  float v11[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point pos; // [esp+0h] [ebp-20h] BYREF
  IVP_U_Float_Point force; // [esp+10h] [ebp-10h]
  float retaddr; // [esp+20h] [ebp+0h]

  force.k[1] = a2;
  force.k[2] = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsObject *, int))this->IsMoveable)(a1: this, a2: a3) != 0 )
  {
    x = forceVector->x;
    m_pObject = this->m_pObject;
    LODWORD(pos.k[2]) = COERCE_UNSIGNED_INT(forceVector->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    pos.hesse_val = forceVector->y * g_PhysicsUnits.unitScaleMeters;
    v11[0] = worldPosition->x * g_PhysicsUnits.unitScaleMeters;
    z = worldPosition->z;
    pos.k[1] = x * g_PhysicsUnits.unitScaleMeters;
    y = worldPosition->y;
    LODWORD(force.k[0]) = &pos.k[1];
    LODWORD(v11[1]) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    v11[2] = y * g_PhysicsUnits.unitScaleMeters;
    IVP_Core::async_push_core_ws(
      this: m_pObject->physical_core,
      world_point: (const IVP_U_Point *)v11,
      impulse_in_world: (IVP_U_Point *)&pos.k[1]);
    this->Wake(this);
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C4C0
// Name: public: virtual void CPhysicsObject::ApplyTorqueCenter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::ApplyTorqueCenter(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        const Vector *torqueImpulse)
{
  float v5; // ecx
  float y; // xmm1_4
  IVP_Real_Object *m_pObject; // ecx
  float v9[3]; // [esp+14h] [ebp-1Ch] BYREF
  IVP_U_Float_Point ivpTorque; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  ivpTorque.k[1] = a2;
  ivpTorque.k[2] = retaddr;
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsObject *, int))this->IsMoveable)(a1: this, a2: a3) != 0 )
  {
    v9[0] = torqueImpulse->x * 0.017453292;
    LODWORD(v9[1]) = COERCE_UNSIGNED_INT(torqueImpulse->z * 0.017453292) ^ _mask__NegFloat_;
    y = torqueImpulse->y;
    ivpTorque.k[0] = v5;
    m_pObject = this->m_pObject;
    v9[2] = y * 0.017453292;
    IVP_Core::async_rot_push_core_multiple_ws(
      this: m_pObject->physical_core,
      angular_impulse_ws: (const IVP_U_Float_Point *)v9,
      factor: 1.0);
    this->Wake(this);
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C570
// Name: public: virtual void CPhysicsObject::GetPositionMatrix(struct matrix3x4_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::GetPositionMatrix(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        matrix3x4_t *positionMatrix)
{
  _BYTE v3[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix matrix; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  matrix.vv.k[1] = a2;
  matrix.vv.k[2] = retaddr;
  IVP_Real_Object::get_m_world_f_object_AT(this: this->m_pObject, m_world_f_object_out: (IVP_U_Matrix *)v3);
  ConvertMatrixToHL(in: (const IVP_U_Matrix *)v3, output: positionMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1001C5B0
// Name: public: virtual void CPhysicsObject::AddVelocity(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::AddVelocity(
        CPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  IVP_Core *physical_core; // esi
  float v5; // xmm1_4
  float v6; // xmm0_4
  float z; // xmm1_4
  float y; // xmm2_4

  if ( this->IsMoveable(this) )
  {
    physical_core = this->m_pObject->physical_core;
    this->Wake(this);
    if ( velocity != nullptr )
    {
      v5 = physical_core->speed_change.k[1] - (float)(velocity->z * g_PhysicsUnits.unitScaleMeters);
      v6 = physical_core->speed_change.k[2] + (float)(velocity->y * g_PhysicsUnits.unitScaleMeters);
      physical_core->speed_change.k[0] = physical_core->speed_change.k[0]
                                       + (float)(velocity->x * g_PhysicsUnits.unitScaleMeters);
      physical_core->speed_change.k[1] = v5;
      physical_core->speed_change.k[2] = v6;
    }
    if ( angularVelocity != nullptr )
    {
      z = angularVelocity->z;
      y = angularVelocity->y;
      physical_core->rot_speed_change.k[0] = (float)(angularVelocity->x * 0.017453292)
                                           + physical_core->rot_speed_change.k[0];
      physical_core->rot_speed_change.k[1] = physical_core->rot_speed_change.k[1] - (float)(z * 0.017453292);
      physical_core->rot_speed_change.k[2] = physical_core->rot_speed_change.k[2] + (float)(y * 0.017453292);
    }
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C6D0
// Name: public: virtual void CPhysicsObject::SetPositionMatrix(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::SetPositionMatrix(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        const matrix3x4_t *matrix,
        bool isTeleport)
{
  IVP_Real_Object *m_pObject; // ecx
  _BYTE v6[12]; // [esp+14h] [ebp-7Ch] BYREF
  IVP_U_Matrix mat; // [esp+20h] [ebp-70h] BYREF
  IVP_U_Quat rot; // [esp+60h] [ebp-30h] BYREF
  Vector worldPosition; // [esp+78h] [ebp-18h] BYREF
  QAngle angles; // [esp+84h] [ebp-Ch]
  float retaddr; // [esp+90h] [ebp+0h]

  angles.x = a2;
  angles.y = retaddr;
  if ( this->m_pShadow != nullptr )
  {
    MatrixAngles(matrix, angles: &worldPosition.x);
    MatrixGetColumn(in: matrix, column: 3, out: (Vector *)&rot.w);
    ((void (__thiscall *)(CPhysicsObject *, float *, Vector *, _DWORD, _DWORD))this->UpdateShadow)(
      a1: this,
      a2: &rot.w,
      a3: &worldPosition,
      a4: 0,
      a5: 0);
  }
  ConvertMatrixToIVP(matrix, out: (IVP_U_Matrix *)v6);
  IVP_U_Quat::set_quaternion(this: (IVP_U_Quat *)&mat.vv.k[1], mat: (const IVP_U_Matrix3 *)v6);
  m_pObject = this->m_pObject;
  if ( (*(_DWORD *)&m_pObject->flags & 0x100) != 0 && isTeleport )
  {
    this->EnableCollisions(this, a2: false);
    IVP_Real_Object::beam_object_to_new_position(
      this: this->m_pObject,
      rotation_world_f_object: (const IVP_U_Quat *)&mat.vv.k[1],
      position_w_f_o: (const IVP_U_Point *)&mat.rows[2].k[1],
      optimize_for_repeated_calls: IVP_FALSE);
    this->EnableCollisions(this, a2: true);
  }
  else
  {
    IVP_Real_Object::beam_object_to_new_position(
      this: m_pObject,
      rotation_world_f_object: (const IVP_U_Quat *)&mat.vv.k[1],
      position_w_f_o: (const IVP_U_Point *)&mat.rows[2].k[1],
      optimize_for_repeated_calls: IVP_FALSE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C7B0
// Name: public: virtual void CPhysicsObject::SetVelocityInstantaneous(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetVelocityInstantaneous(
        CPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  IVP_Core *physical_core; // esi
  float y; // xmm1_4
  float v6; // xmm1_4

  if ( this->IsMoveable(this) )
  {
    physical_core = this->m_pObject->physical_core;
    this->Wake(this);
    if ( velocity != nullptr )
    {
      y = velocity->y;
      physical_core->speed.k[0] = velocity->x * g_PhysicsUnits.unitScaleMeters;
      physical_core->speed.k[1] = -(float)(velocity->z * g_PhysicsUnits.unitScaleMeters);
      physical_core->speed.k[2] = g_PhysicsUnits.unitScaleMeters * y;
      physical_core->speed_change.k[2] = 0.0;
      physical_core->speed_change.k[1] = 0.0;
      physical_core->speed_change.k[0] = 0.0;
    }
    if ( angularVelocity != nullptr )
    {
      v6 = angularVelocity->y;
      physical_core->rot_speed.k[0] = angularVelocity->x * 0.017453292;
      physical_core->rot_speed.k[1] = -(float)(angularVelocity->z * 0.017453292);
      physical_core->rot_speed.k[2] = v6 * 0.017453292;
      physical_core->rot_speed_change.k[2] = 0.0;
      physical_core->rot_speed_change.k[1] = 0.0;
      physical_core->rot_speed_change.k[0] = 0.0;
    }
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C8C0
// Name: public: virtual void CPhysicsObject::SetVelocity(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsObject::SetVelocity(
        CPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  IVP_Core *physical_core; // esi
  float y; // xmm1_4
  float v6; // xmm1_4

  if ( this->IsMoveable(this) )
  {
    physical_core = this->m_pObject->physical_core;
    this->Wake(this);
    if ( velocity != nullptr )
    {
      y = velocity->y;
      physical_core->speed_change.k[0] = velocity->x * g_PhysicsUnits.unitScaleMeters;
      physical_core->speed_change.k[1] = -(float)(velocity->z * g_PhysicsUnits.unitScaleMeters);
      physical_core->speed_change.k[2] = g_PhysicsUnits.unitScaleMeters * y;
      physical_core->speed.k[2] = 0.0;
      physical_core->speed.k[1] = 0.0;
      physical_core->speed.k[0] = 0.0;
    }
    if ( angularVelocity != nullptr )
    {
      v6 = angularVelocity->y;
      physical_core->rot_speed_change.k[0] = angularVelocity->x * 0.017453292;
      physical_core->rot_speed_change.k[1] = -(float)(angularVelocity->z * 0.017453292);
      physical_core->rot_speed_change.k[2] = v6 * 0.017453292;
      physical_core->rot_speed.k[2] = 0.0;
      physical_core->rot_speed.k[1] = 0.0;
      physical_core->rot_speed.k[0] = 0.0;
    }
    if ( this->m_pShadow == nullptr )
      IVP_Core::apply_velocity_limit(this: this->m_pObject->physical_core);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C9D0
// Name: public: virtual int CPhysicsObject::GetShadowPosition(class Vector __near *,class QAngle __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CPhysicsObject::GetShadowPosition@<eax>(
        CPhysicsObject *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Vector *position,
        QAngle *angles)
{
  IVP_Real_Object *m_pObject; // ecx
  float v6; // xmm1_4
  _BYTE v8[12]; // [esp-Ch] [ebp-5Ch] BYREF
  _BYTE matrix_36[32]; // [esp+24h] [ebp-2Ch] OVERLAPPED
  int v10; // [esp+44h] [ebp-Ch]
  long double psi; // [esp+48h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  v10 = a2;
  LODWORD(psi) = retaddr;
  m_pObject = this->m_pObject;
  *(long double *)&matrix_36[24] = m_pObject->environment->time_of_next_psi.seconds;
  IVP_Real_Object::calc_at_matrix(
    this: m_pObject,
    current_time: *(IVP_Time *)&matrix_36[24],
    m_world_f_object_out: (IVP_U_Matrix *)v8);
  if ( angles != nullptr )
    ConvertRotationToHL(a1: a3, in: (const IVP_U_Matrix3 *)v8, angles);
  if ( position != nullptr )
  {
    v6 = g_PhysicsUnits.unitScaleMetersInv * *(float *)&matrix_36[8];
    LODWORD(position->z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * *(float *)&matrix_36[4])
                         ^ _mask__NegFloat_;
    position->y = v6;
    position->x = g_PhysicsUnits.unitScaleMetersInv * *(float *)matrix_36;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA80
// Name: public: virtual void CMaterialIndexOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialIndexOps::Save(CMaterialIndexOps *this, const SaveRestoreFieldInfo_t *fieldInfo, ISave *pSave)
{
  const char *v3; // edi
  unsigned int v4; // eax
  ISave *v5; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx

  v3 = physprops->GetPropName(this: physprops, a2: *(_DWORD *)fieldInfo->pField);
  if ( v3 == nullptr )
    v3 = physprops->GetPropName(this: physprops, a2: 0);
  v4 = strlen(v3);
  v5 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  fieldInfo = (const SaveRestoreFieldInfo_t *)(v4 + 1);
  WriteInt_2(this: pSave, a2: (const int *)&fieldInfo, a3: 1);
  v5->WriteString_4(this: v5, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001CAF0
// Name: public: virtual void CMaterialIndexOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialIndexOps::Restore(
        CMaterialIndexOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  int v3; // eax
  _DWORD *pField; // esi
  int v5; // eax
  char nameBuf[1024]; // [esp+4h] [ebp-400h] BYREF

  v3 = pRestore->ReadInt(this: pRestore);
  pRestore->ReadString_2(this: pRestore, a2: nameBuf, a3: 1024, a4: v3);
  pField = fieldInfo->pField;
  v5 = physprops->GetSurfaceIndex(this: physprops, a2: nameBuf);
  *pField = v5;
  if ( v5 < 0 )
    *pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB50
// Name: public: virtual bool CMaterialIndexOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMaterialIndexOps::IsEmpty(CMaterialIndexOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *(_DWORD *)fieldInfo->pField == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB70
// Name: public: virtual void CMaterialIndexOps::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialIndexOps::MakeEmpty(CMaterialIndexOps *this, const SaveRestoreFieldInfo_t *fieldInfo)
{
  *(_DWORD *)fieldInfo->pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CB90
// Name: public: void CPhysicsObject::InitFromTemplate(class CPhysicsEnvironment __near *,void __near *,struct vphysics_save_cphysicsobject_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsObject::InitFromTemplate(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        CPhysicsEnvironment *pEnvironment,
        void *pGameData,
        const vphysics_save_cphysicsobject_t *objectTemplate)
{
  int materialIndex; // eax
  float mass; // xmm0_4
  IPhysicsSurfacePropsInternal_vtbl *v10; // edx
  IVP_BOOL v11; // eax
  bool v12; // zf
  float speedDamping; // xmm0_4
  float x; // xmm0_4
  IVP_Polygon *ball; // eax
  IVP_SurfaceManager *SurfaceManager; // eax
  char v17; // cl
  void (__thiscall *SetInertia)(IPhysicsObject *, const Vector *); // edx
  int hingeAxis; // eax
  int v21; // [esp+1Ch] [ebp-F4h]
  int v22; // [esp+20h] [ebp-F0h]
  _DWORD v23[3]; // [esp+24h] [ebp-ECh] BYREF
  IVP_U_Matrix massCenterMatrix; // [esp+30h] [ebp-E0h] BYREF
  IVP_Template_Real_Object ivpObjectTemplate; // [esp+70h] [ebp-A0h] BYREF
  IVP_U_Quat rotation; // [esp+D0h] [ebp-40h] BYREF
  IVP_U_Point center; // [esp+E0h] [ebp-30h] BYREF
  IVP_U_Point pos; // [esp+F0h] [ebp-20h] BYREF
  IVP_Real_Object *pName; // [esp+100h] [ebp-10h]
  IVP_Template_Ball ballTemplate; // [esp+104h] [ebp-Ch] BYREF
  void *collideType; // [esp+108h] [ebp-8h]
  void *retaddr; // [esp+110h] [ebp+0h]

  ballTemplate.radius = a2;
  collideType = retaddr;
  *((_BYTE *)this + 21) = *((_BYTE *)this + 21) & 0x1F | (32 * LOBYTE(objectTemplate->collideType));
  IVP_Template_Real_Object::IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1]);
  ConvertRotationToIVP(
    a1: (int)&ballTemplate,
    angles: &objectTemplate->angles,
    out: (IVP_U_Quat *)&ivpObjectTemplate.mass_center_override);
  materialIndex = objectTemplate->materialIndex;
  center.k[1] = objectTemplate->origin.x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(center.k[2]) = COERCE_UNSIGNED_INT(objectTemplate->origin.z * g_PhysicsUnits.unitScaleMeters)
                       ^ _mask__NegFloat_;
  mass = objectTemplate->mass;
  center.hesse_val = objectTemplate->origin.y * g_PhysicsUnits.unitScaleMeters;
  *(float *)&ivpObjectTemplate.enable_piling_optimization = mass;
  v10 = physprops->__vftable;
  if ( materialIndex < 0 )
    v11 = ((int (__stdcall *)(_DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, char *, IVP_BOOL, IVP_BOOL, IVP_BOOL, IVP_Material *, _DWORD, IVP_BOOL, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IVP_U_Matrix *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IVP_Real_Object *))v10->GetIVPMaterial)(
            a1: 0,
            a2: a3,
            a3: a4,
            a4: v21,
            a5: v22,
            a6: v23[0],
            a7: v23[1],
            a8: v23[2],
            a9: LODWORD(massCenterMatrix.rows[0].k[0]),
            a10: LODWORD(massCenterMatrix.rows[0].k[1]),
            a11: LODWORD(massCenterMatrix.rows[0].k[2]),
            a12: LODWORD(massCenterMatrix.rows[0].hesse_val),
            a13: LODWORD(massCenterMatrix.rows[1].k[0]),
            a14: LODWORD(massCenterMatrix.rows[1].k[1]),
            a15: LODWORD(massCenterMatrix.rows[1].k[2]),
            a16: LODWORD(massCenterMatrix.rows[1].hesse_val),
            a17: LODWORD(massCenterMatrix.rows[2].k[0]),
            a18: LODWORD(massCenterMatrix.rows[2].k[1]),
            a19: LODWORD(massCenterMatrix.rows[2].k[2]),
            a20: LODWORD(massCenterMatrix.rows[2].hesse_val),
            a21: LODWORD(massCenterMatrix.vv.k[0]),
            a22: LODWORD(massCenterMatrix.vv.k[1]),
            a23: LODWORD(massCenterMatrix.vv.k[2]),
            a24: LODWORD(massCenterMatrix.vv.hesse_val),
            a25: ivpObjectTemplate.name,
            a26: ivpObjectTemplate.physical_unmoveable,
            a27: ivpObjectTemplate.enable_piling_optimization,
            a28: ivpObjectTemplate.pinned,
            a29: ivpObjectTemplate.material,
            a30: LODWORD(ivpObjectTemplate.mass),
            a31: ivpObjectTemplate.rot_inertia_is_factor,
            a32: *((_DWORD *)&ivpObjectTemplate.rot_inertia_is_factor + 1),
            a33: LODWORD(ivpObjectTemplate.rot_inertia.k[0]),
            a34: LODWORD(ivpObjectTemplate.rot_inertia.k[1]),
            a35: LODWORD(ivpObjectTemplate.rot_inertia.k[2]),
            a36: LODWORD(ivpObjectTemplate.rot_inertia.hesse_val),
            a37: LODWORD(ivpObjectTemplate.auto_check_rot_inertia),
            a38: LODWORD(ivpObjectTemplate.speed_damp_factor),
            a39: *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 1),
            a40: *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 2),
            a41: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[0]),
            a42: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[1]),
            a43: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[2]),
            a44: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.hesse_val),
            a45: LODWORD(ivpObjectTemplate.extra_radius),
            a46: ivpObjectTemplate.mass_center_override,
            a47: ivpObjectTemplate.client_data,
            a48: *((_DWORD *)&ivpObjectTemplate.client_data + 1),
            a49: LODWORD(rotation.x),
            a50: LODWORD(rotation.y),
            a51: LODWORD(rotation.z),
            a52: LODWORD(rotation.w),
            a53: LODWORD(center.k[0]),
            a54: LODWORD(center.k[1]),
            a55: LODWORD(center.k[2]),
            a56: LODWORD(center.hesse_val),
            a57: LODWORD(pos.k[0]),
            a58: LODWORD(pos.k[1]),
            a59: LODWORD(pos.k[2]),
            a60: LODWORD(pos.hesse_val),
            a61: pName);
  else
    v11 = ((int (__stdcall *)(int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, char *, IVP_BOOL, IVP_BOOL, IVP_BOOL, IVP_Material *, _DWORD, IVP_BOOL, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IVP_U_Matrix *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IVP_Real_Object *))v10->GetIVPMaterial)(
            a1: materialIndex,
            a2: a3,
            a3: a4,
            a4: v21,
            a5: v22,
            a6: v23[0],
            a7: v23[1],
            a8: v23[2],
            a9: LODWORD(massCenterMatrix.rows[0].k[0]),
            a10: LODWORD(massCenterMatrix.rows[0].k[1]),
            a11: LODWORD(massCenterMatrix.rows[0].k[2]),
            a12: LODWORD(massCenterMatrix.rows[0].hesse_val),
            a13: LODWORD(massCenterMatrix.rows[1].k[0]),
            a14: LODWORD(massCenterMatrix.rows[1].k[1]),
            a15: LODWORD(massCenterMatrix.rows[1].k[2]),
            a16: LODWORD(massCenterMatrix.rows[1].hesse_val),
            a17: LODWORD(massCenterMatrix.rows[2].k[0]),
            a18: LODWORD(massCenterMatrix.rows[2].k[1]),
            a19: LODWORD(massCenterMatrix.rows[2].k[2]),
            a20: LODWORD(massCenterMatrix.rows[2].hesse_val),
            a21: LODWORD(massCenterMatrix.vv.k[0]),
            a22: LODWORD(massCenterMatrix.vv.k[1]),
            a23: LODWORD(massCenterMatrix.vv.k[2]),
            a24: LODWORD(massCenterMatrix.vv.hesse_val),
            a25: ivpObjectTemplate.name,
            a26: ivpObjectTemplate.physical_unmoveable,
            a27: ivpObjectTemplate.enable_piling_optimization,
            a28: ivpObjectTemplate.pinned,
            a29: ivpObjectTemplate.material,
            a30: LODWORD(ivpObjectTemplate.mass),
            a31: ivpObjectTemplate.rot_inertia_is_factor,
            a32: *((_DWORD *)&ivpObjectTemplate.rot_inertia_is_factor + 1),
            a33: LODWORD(ivpObjectTemplate.rot_inertia.k[0]),
            a34: LODWORD(ivpObjectTemplate.rot_inertia.k[1]),
            a35: LODWORD(ivpObjectTemplate.rot_inertia.k[2]),
            a36: LODWORD(ivpObjectTemplate.rot_inertia.hesse_val),
            a37: LODWORD(ivpObjectTemplate.auto_check_rot_inertia),
            a38: LODWORD(ivpObjectTemplate.speed_damp_factor),
            a39: *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 1),
            a40: *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 2),
            a41: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[0]),
            a42: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[1]),
            a43: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[2]),
            a44: LODWORD(ivpObjectTemplate.rot_speed_damp_factor.hesse_val),
            a45: LODWORD(ivpObjectTemplate.extra_radius),
            a46: ivpObjectTemplate.mass_center_override,
            a47: ivpObjectTemplate.client_data,
            a48: *((_DWORD *)&ivpObjectTemplate.client_data + 1),
            a49: LODWORD(rotation.x),
            a50: LODWORD(rotation.y),
            a51: LODWORD(rotation.z),
            a52: LODWORD(rotation.w),
            a53: LODWORD(center.k[0]),
            a54: LODWORD(center.k[1]),
            a55: LODWORD(center.k[2]),
            a56: LODWORD(center.hesse_val),
            a57: LODWORD(pos.k[0]),
            a58: LODWORD(pos.k[1]),
            a59: LODWORD(pos.k[2]),
            a60: LODWORD(pos.hesse_val),
            a61: pName);
  pName = (IVP_Real_Object *)objectTemplate->pName;
  ivpObjectTemplate.physical_unmoveable = v11;
  IVP_Template_Object::set_name(this: (IVP_Template_Object *)&massCenterMatrix.vv.k[1], s: (const char *)pName);
  v12 = !objectTemplate->isStatic;
  ivpObjectTemplate.mass = 1.0;
  ivpObjectTemplate.rot_inertia_is_factor = 1065353216;
  *((_DWORD *)&ivpObjectTemplate.rot_inertia_is_factor + 1) = 1065353216;
  ivpObjectTemplate.speed_damp_factor = objectTemplate->rotSpeedDamping;
  *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 1) = LODWORD(ivpObjectTemplate.speed_damp_factor);
  *((_DWORD *)&ivpObjectTemplate.speed_damp_factor + 2) = LODWORD(ivpObjectTemplate.speed_damp_factor);
  speedDamping = objectTemplate->speedDamping;
  LODWORD(massCenterMatrix.vv.k[2]) = !v12;
  ivpObjectTemplate.pinned = IVP_TRUE;
  ivpObjectTemplate.rot_inertia.k[2] = speedDamping;
  IVP_U_Matrix::init(this: (IVP_U_Matrix *)v23);
  x = objectTemplate->massCenterOverride.x;
  if ( vec3_origin.x != x
    || vec3_origin.y != objectTemplate->massCenterOverride.y
    || vec3_origin.z != objectTemplate->massCenterOverride.z )
  {
    rotation.y = x * g_PhysicsUnits.unitScaleMeters;
    LODWORD(rotation.z) = COERCE_UNSIGNED_INT(objectTemplate->massCenterOverride.z * g_PhysicsUnits.unitScaleMeters)
                        ^ _mask__NegFloat_;
    rotation.w = objectTemplate->massCenterOverride.y * g_PhysicsUnits.unitScaleMeters;
    IVP_U_Matrix::shift_os(this: (IVP_U_Matrix *)v23, v_in: (const IVP_U_Point *)&rotation.y);
    LODWORD(ivpObjectTemplate.rot_speed_damp_factor.k[2]) = v23;
  }
  if ( (*((_BYTE *)this + 21) & 0xE0) == 0x40 )
  {
    ball = (IVP_Polygon *)IVP_Environment::create_ball(
                            this: pEnvironment->m_pPhysEnv,
                            templ_ball: (const IVP_Template_Ball *)&pos.k[2],
                            templ: COERCE_CONST_IVP_TEMPLATE_REAL_OBJECT_(objectTemplate->sphereRadius * g_PhysicsUnits.unitScaleMeters),
                            rotation: (const IVP_U_Quat *)&ivpObjectTemplate.mass_center_override,
                            position: (IVP_U_Point *)&center.k[1]);
  }
  else
  {
    SurfaceManager = CreateSurfaceManager(
                       pCollisionModel: objectTemplate->pCollide,
                       collideType: (__int16 *)&pos.hesse_val);
    v17 = *((_BYTE *)this + 21) & 0x1F | (32 * LOBYTE(pos.hesse_val));
    pName = (IVP_Real_Object *)&center.k[1];
    LODWORD(pos.hesse_val) = &ivpObjectTemplate.mass_center_override;
    *((_BYTE *)this + 21) = v17;
    ball = IVP_Environment::create_polygon(
             this: pEnvironment->m_pPhysEnv,
             vic: SurfaceManager,
             templ: (const IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1],
             rotation: (const IVP_U_Quat *)LODWORD(pos.hesse_val),
             position: (const IVP_U_Point *)pName);
  }
  SetInertia = this->SetInertia;
  this->m_pObject = ball;
  pName = (IVP_Real_Object *)&objectTemplate->rotInertia;
  ((void (__thiscall *)(CPhysicsObject *))SetInertia)(a1: this);
  CPhysicsObject::Init(
    this,
    pCollisionModel: objectTemplate->pCollide,
    pObject: pName,
    materialIndex: objectTemplate->materialIndex,
    volume: objectTemplate->volume,
    drag: objectTemplate->dragCoefficient,
    angDrag: objectTemplate->dragCoefficient);
  this->SetCallbackFlags(this, a2: objectTemplate->callbacks);
  this->SetGameFlags(this, a2: objectTemplate->gameFlags);
  this->SetGameIndex(this, a2: objectTemplate->gameIndex);
  this->SetGameData(this, a2: pGameData);
  this->SetContents(this, a2: objectTemplate->contentsMask);
  if ( objectTemplate->dragEnabled )
    this->EnableDrag(this, a2: true);
  if ( !objectTemplate->motionEnabled )
    this->EnableMotion(this, a2: false);
  if ( objectTemplate->isTrigger )
    this->BecomeTrigger(this);
  if ( !objectTemplate->gravityEnabled )
    this->EnableGravity(this, a2: false);
  if ( objectTemplate->collisionEnabled )
    this->EnableCollisions(this, a2: true);
  if ( (float)((float)((float)(objectTemplate->velocity.x * objectTemplate->velocity.x)
                     + (float)(objectTemplate->velocity.y * objectTemplate->velocity.y))
             + (float)(objectTemplate->velocity.z * objectTemplate->velocity.z)) != 0.0
    || (float)((float)((float)(objectTemplate->angVelocity.x * objectTemplate->angVelocity.x)
                     + (float)(objectTemplate->angVelocity.y * objectTemplate->angVelocity.y))
             + (float)(objectTemplate->angVelocity.z * objectTemplate->angVelocity.z)) != 0.0 )
  {
    this->SetVelocityInstantaneous(this, a2: &objectTemplate->velocity, a3: &objectTemplate->angVelocity);
    if ( objectTemplate->isAsleep )
      this->Sleep(this);
  }
  *((_BYTE *)this + 20) ^= (*((_BYTE *)this + 20) ^ (objectTemplate->asleepSinceCreation << 6)) & 0x40;
  if ( !objectTemplate->isAsleep )
    this->Wake(this);
  hingeAxis = objectTemplate->hingeAxis;
  if ( hingeAxis != 0 )
    this->BecomeHinged(this, a2: hingeAxis - 1);
  if ( objectTemplate->hasTouchedDynamic )
    *((_BYTE *)this + 20) |= 0x20u;
  this->m_pShadow = nullptr;
  IVP_Template_Real_Object::~IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1001CF80
// Name: private: void CPredictedPhysicsObject::PullDeltasForward(struct vphysics_save_cphysicsobject_t __near *,struct vphysics_save_cphysicsobject_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::PullDeltasForward(
        CPredictedPhysicsObject *this,
        vphysics_save_cphysicsobject_t *pNewBackup,
        const vphysics_save_cphysicsobject_t *pCompareCurrentTo,
        float fSimulationTime)
{
  float y; // xmm2_4
  float z; // xmm3_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float vOriginDelta; // [esp+4h] [ebp-18h]
  float vOriginDelta_4; // [esp+8h] [ebp-14h]
  float vOriginDelta_8; // [esp+Ch] [ebp-10h]
  float vVelocityDelta; // [esp+10h] [ebp-Ch]
  float vVelocityDelta_4; // [esp+14h] [ebp-8h]
  float vVelocityDelta_8; // [esp+18h] [ebp-4h]

  vOriginDelta = this->m_ActiveBackup.origin.x - pCompareCurrentTo->origin.x;
  vOriginDelta_4 = this->m_ActiveBackup.origin.y - pCompareCurrentTo->origin.y;
  vOriginDelta_8 = this->m_ActiveBackup.origin.z - pCompareCurrentTo->origin.z;
  vVelocityDelta = this->m_ActiveBackup.velocity.x - pCompareCurrentTo->velocity.x;
  vVelocityDelta_4 = this->m_ActiveBackup.velocity.y - pCompareCurrentTo->velocity.y;
  vVelocityDelta_8 = this->m_ActiveBackup.velocity.z - pCompareCurrentTo->velocity.z;
  if ( this->m_ActiveBackup.isAsleep )
    fSimulationTime = 0.0;
  vphysics_save_cphysicsobject_t::operator=(this: &this->m_ActiveBackup, __that: pNewBackup);
  y = this->m_ActiveBackup.velocity.y;
  z = this->m_ActiveBackup.velocity.z;
  this->m_ActiveBackup.velocity.x = this->m_ActiveBackup.velocity.x + vVelocityDelta;
  this->m_ActiveBackup.velocity.y = y + vVelocityDelta_4;
  this->m_ActiveBackup.velocity.z = z + vVelocityDelta_8;
  v7 = this->m_ActiveBackup.origin.x + (float)((float)(vVelocityDelta * fSimulationTime) + vOriginDelta);
  this->m_ActiveBackup.origin.y = this->m_ActiveBackup.origin.y
                                + (float)((float)(vVelocityDelta_4 * fSimulationTime) + vOriginDelta_4);
  v8 = this->m_ActiveBackup.origin.z;
  this->m_ActiveBackup.origin.x = v7;
  this->m_ActiveBackup.origin.z = v8 + (float)((float)(vVelocityDelta_8 * fSimulationTime) + vOriginDelta_8);
  this->m_pReferencedBackup = pNewBackup;
}

//------------------------------------------------------------------------------
// Address: 0x1001D0D0
// Name: public: void CPredictedPhysicsObject::PreSimulation(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::PreSimulation(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        bool bBackup)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( bBackup )
    CPhysicsObject::WriteToTemplate(
      this,
      a2: (int)&savedregs,
      a3: a2,
      a4: a3,
      objectTemplate: &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1].Backup_PreSimulation);
}

//------------------------------------------------------------------------------
// Address: 0x1001D100
// Name: public: void CPredictedPhysicsObject::PreAnyController(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::PreAnyController(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<edi>,
        float fSimulationTime,
        bool bBackup)
{
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pMemory; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( !this->m_bPreControllerCalled )
  {
    m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
    if ( bBackup )
      CPhysicsObject::WriteToTemplate(
        this,
        a2: (int)&savedregs,
        a3: a2,
        a4: (int)this,
        objectTemplate: &m_pMemory[this->m_PredictionBackups.m_Size - 1].Backup_PreController);
    else
      CPredictedPhysicsObject::PullDeltasForward(
        this,
        pNewBackup: &m_pMemory[this->m_iBackupIndex].Backup_PreController,
        pCompareCurrentTo: &m_pMemory[this->m_iBackupIndex].Backup_PreSimulation,
        fSimulationTime: 0.0);
    this->m_bPreControllerCalled = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D180
// Name: public: void CPredictedPhysicsObject::PostAnyController(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::PostAnyController(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float fSimulationTime,
        bool bBackup)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( bBackup )
    CPhysicsObject::WriteToTemplate(
      this,
      a2: (int)&savedregs,
      a3: a2,
      a4: a3,
      objectTemplate: &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1].Backup_PostController);
}

//------------------------------------------------------------------------------
// Address: 0x1001D1B0
// Name: public: void CPredictedPhysicsObject::PostSimulation(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::PostSimulation(
        CPredictedPhysicsObject *this,
        float fSimulationTime,
        bool bBackup)
{
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *v4; // edi
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *v5; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( bBackup )
  {
    v4 = &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1];
    CPhysicsObject::WriteToTemplate(
      this,
      a2: (int)&savedregs,
      a3: (int)v4,
      a4: (int)this,
      objectTemplate: &v4->Backup_PostSimulation);
    if ( !this->m_bPreControllerCalled )
    {
      vphysics_save_cphysicsobject_t::operator=(this: &v4->Backup_PreController, __that: &v4->Backup_PostSimulation);
      vphysics_save_cphysicsobject_t::operator=(this: &v4->Backup_PostController, __that: &v4->Backup_PostSimulation);
    }
  }
  else
  {
    v5 = &this->m_PredictionBackups.m_Memory.m_pMemory[this->m_iBackupIndex];
    if ( this->m_bPreControllerCalled )
      CPredictedPhysicsObject::PullDeltasForward(
        this,
        pNewBackup: &v5->Backup_PostSimulation,
        pCompareCurrentTo: &v5->Backup_PostController,
        fSimulationTime);
    else
      CPredictedPhysicsObject::PullDeltasForward(
        this,
        pNewBackup: &v5->Backup_PostSimulation,
        pCompareCurrentTo: &v5->Backup_PreSimulation,
        fSimulationTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D260
// Name: public: virtual void CPredictedPhysicsObject::SetPositionMatrix(struct matrix3x4_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::SetPositionMatrix(
        CPredictedPhysicsObject *this,
        const matrix3x4_t *matrix,
        bool isTeleport)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_pReferencedBackup != nullptr )
  {
    MatrixAngles(matrix, angles: &this->m_ActiveBackup.angles.x);
    this->m_ActiveBackup.origin.x = matrix->m_flMatVal[0][3];
    this->m_ActiveBackup.origin.y = matrix->m_flMatVal[1][3];
    this->m_ActiveBackup.origin.z = matrix->m_flMatVal[2][3];
  }
  else
  {
    CPhysicsObject::SetPositionMatrix(this, a2: COERCE_FLOAT(&savedregs), matrix, isTeleport);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D2C0
// Name: public: virtual void CPredictedPhysicsObject::GetPositionMatrix(struct matrix3x4_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::GetPositionMatrix(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<ebp>,
        matrix3x4_t *positionMatrix)
{
  IVP_U_Matrix v3; // [esp-40h] [ebp-4Ch] BYREF
  int v4; // [esp+0h] [ebp-Ch]
  void *v5; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v4 = a2;
  v5 = retaddr;
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( positionMatrix != nullptr )
      AngleMatrix(angles: &this->m_ActiveBackup.angles, position: &this->m_ActiveBackup.origin, matrix: positionMatrix);
  }
  else
  {
    IVP_Real_Object::get_m_world_f_object_AT(this: this->m_pObject, m_world_f_object_out: &v3);
    ConvertMatrixToHL(in: &v3, output: positionMatrix);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D330
// Name: public: virtual void CPredictedPhysicsObject::SetVelocity(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::SetVelocity(
        CPredictedPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( velocity != nullptr )
      this->m_ActiveBackup.velocity = *velocity;
    if ( angularVelocity != nullptr )
      this->m_ActiveBackup.angVelocity = *angularVelocity;
  }
  else
  {
    CPhysicsObject::SetVelocity(this, velocity, angularVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D390
// Name: public: virtual void CPredictedPhysicsObject::SetVelocityInstantaneous(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::SetVelocityInstantaneous(
        CPredictedPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( velocity != nullptr )
      this->m_ActiveBackup.velocity = *velocity;
    if ( angularVelocity != nullptr )
      this->m_ActiveBackup.angVelocity = *angularVelocity;
  }
  else
  {
    CPhysicsObject::SetVelocityInstantaneous(this, velocity, angularVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D3F0
// Name: public: virtual void CPredictedPhysicsObject::AddVelocity(class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::AddVelocity(
        CPredictedPhysicsObject *this,
        const Vector *velocity,
        const Vector *angularVelocity)
{
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( velocity != nullptr )
    {
      this->m_ActiveBackup.velocity.x = this->m_ActiveBackup.velocity.x + velocity->x;
      this->m_ActiveBackup.velocity.y = velocity->y + this->m_ActiveBackup.velocity.y;
      this->m_ActiveBackup.velocity.z = velocity->z + this->m_ActiveBackup.velocity.z;
    }
    if ( angularVelocity != nullptr )
    {
      this->m_ActiveBackup.angVelocity.x = this->m_ActiveBackup.angVelocity.x + angularVelocity->x;
      this->m_ActiveBackup.angVelocity.y = angularVelocity->y + this->m_ActiveBackup.angVelocity.y;
      this->m_ActiveBackup.angVelocity.z = angularVelocity->z + this->m_ActiveBackup.angVelocity.z;
    }
  }
  else
  {
    CPhysicsObject::AddVelocity(this, velocity, angularVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D4A0
// Name: class IPhysicsObject __near * CreateObjectFromBuffer_UseExistingMemory(class CPhysicsEnvironment __near *,void __near *,unsigned char __near *,unsigned int,class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsObject *__cdecl CreateObjectFromBuffer_UseExistingMemory(
        CPhysicsEnvironment *pEnvironment,
        void *pGameData,
        unsigned __int8 *pBuffer,
        unsigned int bufferSize,
        CPhysicsObject *pExistingMemory)
{
  CPhysicsObject *v5; // esi
  char v6; // cl
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( bufferSize < 0x94 )
    return nullptr;
  v5 = pExistingMemory;
  if ( pExistingMemory != nullptr )
  {
    pExistingMemory->__vftable = (CPhysicsObject_vtbl *)&CPhysicsObject::`vftable';
    memset(dst: (unsigned __int8 *)&pExistingMemory->m_pGameData, value: 0, count: 0x48u);
    v6 = *((_BYTE *)pExistingMemory + 21) & 0x1F | 0x40;
    *((_BYTE *)pExistingMemory + 20) &= ~0x20u;
    *((_BYTE *)pExistingMemory + 21) = v6;
    pExistingMemory->m_contentsMask = 1;
  }
  else
  {
    v5 = nullptr;
  }
  CPhysicsObject::InitFromTemplate(
    this: v5,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)pBuffer,
    a4: (int)v5,
    pEnvironment,
    pGameData,
    objectTemplate: (const vphysics_save_cphysicsobject_t *)pBuffer);
  if ( pBuffer[13] != 0 )
    v5->EnableCollisions(this: v5, a2: true);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001D550
// Name: public: virtual void CPhysicsObject::GetPosition(class Vector __near *,class QAngle __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsObject::GetPosition(
        CPhysicsObject *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        Vector *worldPosition,
        QAngle *angles)
{
  float v5; // xmm1_4
  _BYTE v6[12]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix matrix; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  matrix.vv.k[1] = a2;
  matrix.vv.k[2] = retaddr;
  IVP_Real_Object::get_m_world_f_object_AT(this: this->m_pObject, m_world_f_object_out: (IVP_U_Matrix *)v6);
  if ( worldPosition != nullptr )
  {
    v5 = g_PhysicsUnits.unitScaleMetersInv * matrix.rows[2].hesse_val;
    LODWORD(worldPosition->z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * matrix.rows[2].k[2])
                              ^ _mask__NegFloat_;
    worldPosition->y = v5;
    worldPosition->x = g_PhysicsUnits.unitScaleMetersInv * matrix.rows[2].k[1];
  }
  if ( angles != nullptr )
    ConvertRotationToHL(a1: a3, in: (const IVP_U_Matrix3 *)v6, angles);
}

//------------------------------------------------------------------------------
// Address: 0x1001D5D0
// Name: public: void CPredictedPhysicsObject::DoneReferencingPreviousCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPredictedPhysicsObject::DoneReferencingPreviousCommands(
        CPredictedPhysicsObject *this,
        int iCommandNum)
{
  int v3; // edi
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pMemory; // edx
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *i; // eax
  int v6; // ecx
  const vphysics_save_cphysicsobject_t *m_pReferencedBackup; // eax
  int v8; // ebx

  v3 = 0;
  if ( this->m_PredictionBackups.m_Size != 0 )
  {
    m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
    for ( i = m_pMemory; i->iCommandNum < iCommandNum; ++i )
    {
      if ( ++v3 == this->m_PredictionBackups.m_Size )
        return;
    }
    if ( v3 > 0 )
    {
      v6 = v3;
      if ( m_pMemory[v3 - 1].iCommandNum != -1 )
      {
        m_pReferencedBackup = this->m_pReferencedBackup;
        this->m_iBackupIndex -= v3;
        if ( m_pReferencedBackup != nullptr )
        {
          v8 = (char *)&m_pReferencedBackup[-v3] - (char *)m_pMemory;
          if ( this->m_PredictionBackups.m_Size - v3 > 0 )
            _V_memmove(dest: m_pMemory, src: &m_pMemory[v6], count: 744 * (this->m_PredictionBackups.m_Size - v3));
          this->m_PredictionBackups.m_Size -= v3;
          if ( v8 < 0 )
            this->m_pReferencedBackup = nullptr;
          else
            this->m_pReferencedBackup = (const vphysics_save_cphysicsobject_t *)((char *)this->m_PredictionBackups.m_Memory.m_pMemory
                                                                               + v8);
        }
        else
        {
          if ( this->m_PredictionBackups.m_Size - v3 > 0 )
            _V_memmove(dest: m_pMemory, src: &m_pMemory[v6], count: 744 * (this->m_PredictionBackups.m_Size - v3));
          this->m_PredictionBackups.m_Size -= v3;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D6B0
// Name: public: virtual void CPredictedPhysicsObject::GetPosition(class Vector __near *,class QAngle __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::GetPosition(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Vector *worldPosition,
        QAngle *angles)
{
  float v5; // xmm1_4
  IVP_U_Matrix v6; // [esp-40h] [ebp-4Ch] BYREF
  int v7; // [esp+0h] [ebp-Ch]
  void *v8; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v7 = a2;
  v8 = retaddr;
  if ( this->m_pReferencedBackup != nullptr )
  {
    if ( worldPosition != nullptr )
      *worldPosition = this->m_ActiveBackup.origin;
    if ( angles != nullptr )
      *angles = this->m_ActiveBackup.angles;
  }
  else
  {
    IVP_Real_Object::get_m_world_f_object_AT(this: this->m_pObject, m_world_f_object_out: &v6);
    if ( worldPosition != nullptr )
    {
      v5 = g_PhysicsUnits.unitScaleMetersInv * v6.vv.k[2];
      LODWORD(worldPosition->z) = COERCE_UNSIGNED_INT(g_PhysicsUnits.unitScaleMetersInv * v6.vv.k[1]) ^ _mask__NegFloat_;
      worldPosition->y = v5;
      worldPosition->x = g_PhysicsUnits.unitScaleMetersInv * v6.vv.k[0];
    }
    if ( angles != nullptr )
      ConvertRotationToHL(a1: a3, in: &v6, angles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D880
// Name: public: CPredictedPhysicsObject::CPredictedPhysicsObject(void)
// Source: json
//------------------------------------------------------------------------------
CPredictedPhysicsObject *__thiscall CPredictedPhysicsObject::CPredictedPhysicsObject(CPredictedPhysicsObject *this)
{
  char v2; // cl

  memset(dst: (unsigned __int8 *)&this->m_pGameData, value: 0, count: 0x48u);
  v2 = *((_BYTE *)&this->CPhysicsObject + 21);
  *((_BYTE *)&this->CPhysicsObject + 20) &= ~0x20u;
  this->m_contentsMask = 1;
  this->__vftable = (CPredictedPhysicsObject_vtbl *)&CPredictedPhysicsObject::`vftable';
  *((_BYTE *)&this->CPhysicsObject + 21) = v2 & 0x1F | 0x40;
  this->m_PredictionBackups.m_Memory.m_pMemory = nullptr;
  this->m_PredictionBackups.m_Memory.m_nAllocationCount = 0;
  this->m_PredictionBackups.m_Memory.m_nGrowSize = 0;
  this->m_PredictionBackups.m_Size = 0;
  this->m_PredictionBackups.m_pElements = nullptr;
  this->m_pReferencedBackup = nullptr;
  this->m_bPreControllerCalled = false;
  this->m_iBackupIndex = 0;
  this->m_vOriginErrorDelta = vec3_origin;
  this->m_vVelocityErrorDelta = vec3_origin;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001D940
// Name: void PostRestorePhysicsObject(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostRestorePhysicsObject()
{
  postrestore_objectlist_t *m_pMemory; // eax
  int i; // esi
  CPhysicsObject *pObject; // ecx

  m_pMemory = g_PostRestoreObjectList.m_Memory.m_pMemory;
  for ( i = g_PostRestoreObjectList.m_Size - 1; i >= 0; --i )
  {
    pObject = m_pMemory[i].pObject;
    if ( pObject != nullptr )
    {
      if ( m_pMemory[i].growFriction )
      {
        IVP_Real_Object::force_grow_friction_system(this: pObject->m_pObject);
        m_pMemory = g_PostRestoreObjectList.m_Memory.m_pMemory;
      }
      if ( m_pMemory[i].enableCollisions )
      {
        m_pMemory[i].pObject->EnableCollisions(this: m_pMemory[i].pObject, a2: true);
        m_pMemory = g_PostRestoreObjectList.m_Memory.m_pMemory;
      }
    }
  }
  g_PostRestoreObjectList.m_Size = 0;
  if ( g_PostRestoreObjectList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      m_pMemory = nullptr;
      g_PostRestoreObjectList.m_Memory.m_pMemory = nullptr;
    }
    g_PostRestoreObjectList.m_Memory.m_nAllocationCount = 0;
  }
  g_PostRestoreObjectList.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA00
// Name: public: void CPredictedPhysicsObject::OnPredictionCommandChanged(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPredictedPhysicsObject::OnPredictionCommandChanged(
        CPredictedPhysicsObject *this@<ecx>,
        int a2@<edi>,
        int iCommandNum,
        bool bBackup)
{
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pReferencedBackup; // eax
  bool v6; // bl
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *m_pMemory; // edx
  int m_Size; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  const vphysics_save_cphysicsobject_t *v15; // eax
  const vphysics_save_cphysicsobject_t *v16; // eax
  int v17; // eax
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *v18; // edi
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *i; // ecx
  const vphysics_save_cphysicsobject_t *v20; // edx
  bool v21; // dl
  CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t temp; // [esp+10h] [ebp-2F4h] BYREF
  Vector vVelocityDelta; // [esp+2F8h] [ebp-Ch]
  int savedregs; // [esp+304h] [ebp+0h] BYREF

  if ( bBackup )
  {
    m_pReferencedBackup = (CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *)this->m_pReferencedBackup;
    v6 = m_pReferencedBackup != nullptr
      && m_pReferencedBackup == (CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t *)&this->m_PredictionBackups.m_Memory.m_pMemory[this->m_PredictionBackups.m_Size - 1].Backup_PostSimulation;
    this->m_pReferencedBackup = nullptr;
    temp.iCommandNum = iCommandNum;
    CPhysicsObject::WriteToTemplate(
      this,
      a2: (int)&savedregs,
      a3: a2,
      a4: (int)this,
      objectTemplate: &temp.Backup_OnPredictionCommandChanged);
    if ( v6 && !this->IsStatic(this) && this->IsMotionEnabled(this) )
    {
      m_pMemory = this->m_PredictionBackups.m_Memory.m_pMemory;
      m_Size = this->m_PredictionBackups.m_Size;
      v9 = this->m_ActiveBackup.origin.x - m_pMemory[m_Size - 1].Backup_PostSimulation.origin.x;
      v10 = this->m_ActiveBackup.origin.y - m_pMemory[m_Size - 1].Backup_PostSimulation.origin.y;
      v11 = this->m_ActiveBackup.origin.z - m_pMemory[m_Size - 1].Backup_PostSimulation.origin.z;
      x = this->m_ActiveBackup.velocity.x - m_pMemory[m_Size - 1].Backup_PostSimulation.velocity.x;
      y = this->m_ActiveBackup.velocity.y - m_pMemory[m_Size - 1].Backup_PostSimulation.velocity.y;
      z = this->m_ActiveBackup.velocity.z - m_pMemory[m_Size - 1].Backup_PostSimulation.velocity.z;
      vVelocityDelta.x = x;
      vVelocityDelta.y = y;
      vVelocityDelta.z = z;
      if ( (float)((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11)) > 1.0 )
      {
        temp.Backup_OnPredictionCommandChanged.origin.y = temp.Backup_OnPredictionCommandChanged.origin.y + v10;
        temp.Backup_OnPredictionCommandChanged.origin.x = temp.Backup_OnPredictionCommandChanged.origin.x + v9;
        temp.Backup_OnPredictionCommandChanged.origin.z = temp.Backup_OnPredictionCommandChanged.origin.z + v11;
        CPhysicsObject::SetPosition(
          this,
          a2: COERCE_FLOAT(&savedregs),
          a3: a2,
          a4: (int)this,
          worldPosition: &temp.Backup_OnPredictionCommandChanged.origin,
          angles: &temp.Backup_OnPredictionCommandChanged.angles,
          isTeleport: false);
        z = vVelocityDelta.z;
        y = vVelocityDelta.y;
        x = vVelocityDelta.x;
      }
      if ( (float)((float)((float)(y * y) + (float)(x * x)) + (float)(z * z)) > 0.1 )
      {
        temp.Backup_OnPredictionCommandChanged.velocity.y = temp.Backup_OnPredictionCommandChanged.velocity.y + y;
        temp.Backup_OnPredictionCommandChanged.velocity.x = x + temp.Backup_OnPredictionCommandChanged.velocity.x;
        temp.Backup_OnPredictionCommandChanged.velocity.z = temp.Backup_OnPredictionCommandChanged.velocity.z + z;
        CPhysicsObject::SetVelocityInstantaneous(
          this,
          velocity: &temp.Backup_OnPredictionCommandChanged.velocity,
          angularVelocity: nullptr);
      }
    }
    v15 = vphysics_save_cphysicsobject_t::operator=(
            this: &temp.Backup_PreSimulation,
            __that: &temp.Backup_OnPredictionCommandChanged);
    v16 = vphysics_save_cphysicsobject_t::operator=(this: &temp.Backup_PreController, __that: v15);
    vphysics_save_cphysicsobject_t::operator=(this: &temp.Backup_PostSimulation, __that: v16);
    this->m_iBackupIndex = CUtlVector<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,CUtlMemory<CPredictedPhysicsObject::PhysicsObjectPredictionBackups_t,int>>::InsertBefore(
                             this: &this->m_PredictionBackups,
                             elem: this->m_PredictionBackups.m_Size,
                             src: &temp);
    this->m_vOriginErrorDelta = vec3_origin;
    this->m_vVelocityErrorDelta = vec3_origin;
    this->m_bPreControllerCalled = false;
  }
  else
  {
    v17 = this->m_PredictionBackups.m_Size - 1;
    if ( v17 >= 0 )
    {
      v18 = this->m_PredictionBackups.m_Memory.m_pMemory;
      for ( i = &v18[v17]; i->iCommandNum > iCommandNum; --i )
      {
        if ( --v17 < 0 )
        {
          this->m_bPreControllerCalled = false;
          return;
        }
      }
      v20 = this->m_pReferencedBackup;
      v21 = v20 != nullptr && v17 > 0 && v20 == &v18[v17 - 1].Backup_PostSimulation;
      this->m_iBackupIndex = v17;
      if ( v21 )
      {
        CPredictedPhysicsObject::PullDeltasForward(
          this,
          pNewBackup: &i->Backup_OnPredictionCommandChanged,
          pCompareCurrentTo: &i->Backup_OnPredictionCommandChanged,
          fSimulationTime: 0.0);
        this->m_bPreControllerCalled = false;
        return;
      }
      this->m_pReferencedBackup = &i->Backup_OnPredictionCommandChanged;
      vphysics_save_cphysicsobject_t::operator=(
        this: &this->m_ActiveBackup,
        __that: &i->Backup_OnPredictionCommandChanged);
      this->m_vOriginErrorDelta = vec3_origin;
      this->m_vVelocityErrorDelta = vec3_origin;
    }
    this->m_bPreControllerCalled = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DDC0
// Name: bool RestorePhysicsObject(struct physrestoreparams_t const __near &,class CPhysicsObject __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RestorePhysicsObject(const physrestoreparams_t *params, CPredictedPhysicsObject **ppObject)
{
  const CPhysCollide *pCollisionModel; // eax
  IPhysicsEnvironment *pEnvironment; // ecx
  CPredictedPhysicsObject *v4; // eax
  CPredictedPhysicsObject *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 v8; // dl
  CPhysicsObject *v9; // ebx
  bool result; // al
  CPhysicsObject *v11; // esi
  vphysics_save_cphysicsobject_t objectTemplate; // [esp+8h] [ebp-9Ch] BYREF
  postrestore_objectlist_t entry; // [esp+9Ch] [ebp-8h] BYREF
  int savedregs; // [esp+A4h] [ebp+0h] BYREF

  memset(dst: (unsigned __int8 *)&objectTemplate, value: 0, count: sizeof(objectTemplate));
  params->pRestore->ReadAll(this: params->pRestore, a2: &objectTemplate, a3: &vphysics_save_cphysicsobject_t::m_DataMap);
  pCollisionModel = params->pCollisionModel;
  objectTemplate.pName = params->pName;
  pEnvironment = params->pEnvironment;
  objectTemplate.pCollide = pCollisionModel;
  if ( pEnvironment->IsPredicted(this: pEnvironment) )
  {
    v4 = (CPredictedPhysicsObject *)p_malloc(size: 0x118u);
    if ( v4 != nullptr )
    {
      v5 = CPredictedPhysicsObject::CPredictedPhysicsObject(this: v4);
      goto LABEL_7;
    }
  }
  else
  {
    v6 = (unsigned __int8 *)p_malloc(size: 0x4Cu);
    v7 = v6;
    if ( v6 != nullptr )
    {
      *(_DWORD *)v6 = &CPhysicsObject::`vftable';
      memset(dst: v6 + 4, value: 0, count: 0x48u);
      v8 = v7[21] & 0x1F | 0x40;
      v7[20] &= ~0x20u;
      v7[21] = v8;
      *((_DWORD *)v7 + 8) = 1;
      v5 = (CPredictedPhysicsObject *)v7;
      goto LABEL_7;
    }
  }
  v5 = nullptr;
LABEL_7:
  v9 = nullptr;
  *ppObject = v5;
  entry.pObject = nullptr;
  *(_WORD *)&entry.growFriction = 0;
  if ( objectTemplate.collisionEnabled )
  {
    v9 = v5;
    entry.pObject = v5;
    entry.enableCollisions = true;
    objectTemplate.collisionEnabled = false;
  }
  CPhysicsObject::InitFromTemplate(
    this: v5,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)params,
    a4: (int)ppObject,
    pEnvironment: (CPhysicsEnvironment *)params->pEnvironment,
    pGameData: params->pGameData,
    &objectTemplate);
  if ( (*ppObject)->IsAsleep(this: *ppObject)
    && (*((_BYTE *)&(*ppObject)->CPhysicsObject + 20) & 0x40) == 0
    && !(*ppObject)->IsStatic(this: *ppObject) )
  {
    v9 = *ppObject;
    entry.pObject = *ppObject;
    entry.growFriction = true;
  }
  if ( v9 != nullptr )
    CUtlVector<CPhysicsEnvironment::PredictedData_t,CUtlMemory<CPhysicsEnvironment::PredictedData_t,int>>::InsertBefore(
      this: (CUtlVector<CCollisionSolver::realobjectpair_t,CUtlMemory<CCollisionSolver::realobjectpair_t,int> > *)&g_PostRestoreObjectList,
      elem: g_PostRestoreObjectList.m_Size,
      src: (const CCollisionSolver::realobjectpair_t *)&entry);
  if ( objectTemplate.hasShadowController )
  {
    result = RestorePhysicsShadowControllerInternal(
               params,
               ppShadowController: &objectTemplate.pShadow,
               pObject: *ppObject);
    v11 = *ppObject;
    if ( objectTemplate.pShadow != nullptr )
      v11->m_pShadow = (CShadowController *)&objectTemplate.pShadow[-1];
    else
      v11->m_pShadow = nullptr;
  }
  else
  {
    if ( params->pEnvironment->IsPredicted(this: params->pEnvironment) )
      CPredictedPhysicsObject::OnPredictionCommandChanged(
        this: *ppObject,
        a2: (int)params,
        iCommandNum: -1,
        bBackup: true);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF60
// Name: class IPhysicsObject __near * CreateObjectFromBuffer(class CPhysicsEnvironment __near *,void __near *,unsigned char __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CPredictedPhysicsObject *__cdecl CreateObjectFromBuffer(
        CPhysicsEnvironment *pEnvironment,
        void *pGameData,
        unsigned __int8 *pBuffer,
        unsigned int bufferSize,
        bool enableCollisions)
{
  CPredictedPhysicsObject *v5; // eax
  CPredictedPhysicsObject *v6; // esi
  char v7; // cl
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( pEnvironment->IsPredicted(this: pEnvironment) )
  {
    v5 = (CPredictedPhysicsObject *)p_malloc(size: 0x118u);
    if ( v5 != nullptr )
    {
      v6 = CPredictedPhysicsObject::CPredictedPhysicsObject(this: v5);
      goto LABEL_7;
    }
  }
  else
  {
    v6 = (CPredictedPhysicsObject *)p_malloc(size: 0x4Cu);
    if ( v6 != nullptr )
    {
      v6->__vftable = (CPredictedPhysicsObject_vtbl *)&CPhysicsObject::`vftable';
      memset(dst: (unsigned __int8 *)&v6->m_pGameData, value: 0, count: 0x48u);
      v7 = *((_BYTE *)&v6->CPhysicsObject + 21) & 0x1F | 0x40;
      *((_BYTE *)&v6->CPhysicsObject + 20) &= ~0x20u;
      *((_BYTE *)&v6->CPhysicsObject + 21) = v7;
      v6->m_contentsMask = 1;
      goto LABEL_7;
    }
  }
  v6 = nullptr;
LABEL_7:
  if ( bufferSize < 0x94 )
    return nullptr;
  pBuffer[21] = 0;
  CPhysicsObject::InitFromTemplate(
    this: v6,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)pBuffer,
    a4: (int)v6,
    pEnvironment,
    pGameData,
    objectTemplate: (const vphysics_save_cphysicsobject_t *)pBuffer);
  if ( pBuffer[13] != 0 && enableCollisions )
    v6->EnableCollisions(this: v6, a2: true);
  if ( pEnvironment->IsPredicted(this: pEnvironment) )
    CPredictedPhysicsObject::OnPredictionCommandChanged(this: v6, a2: (int)pBuffer, iCommandNum: -1, bBackup: true);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1001E040
// Name: class CPhysicsObject __near * CreatePhysicsObject(class CPhysicsEnvironment __near *,class CPhysCollide const __near *,int,class Vector const __near &,class QAngle const __near &,struct objectparams_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CPredictedPhysicsObject *__usercall CreatePhysicsObject@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CPhysicsEnvironment *pEnvironment,
        const CPhysCollide *pCollisionModel,
        int materialIndex,
        const Vector *position,
        const QAngle *angles,
        objectparams_t *pParams,
        bool isStatic)
{
  const QAngle *v10; // eax
  Vector *massCenterOverride; // eax
  float y; // xmm0_4
  CPredictedPhysicsObject *v13; // eax
  CPredictedPhysicsObject *v14; // esi
  CPredictedPhysicsObject *v15; // eax
  char v16; // dl
  IVP_SurfaceManager *SurfaceManager; // eax
  char hesse_val_low; // cl
  char v20; // dl
  IVP_Polygon *polygon; // eax
  int v22; // [esp+Ch] [ebp-FCh]
  int v23; // [esp+10h] [ebp-F8h]
  _BYTE v24[12]; // [esp+1Ch] [ebp-ECh] BYREF
  IVP_U_Matrix massCenterMatrix; // [esp+28h] [ebp-E0h] BYREF
  IVP_Template_Real_Object objectTemplate; // [esp+68h] [ebp-A0h] BYREF
  IVP_U_Quat rotation; // [esp+C8h] [ebp-40h] BYREF
  IVP_U_Point center; // [esp+D8h] [ebp-30h] BYREF
  IVP_U_Point pos; // [esp+E8h] [ebp-20h] BYREF
  float x; // [esp+F8h] [ebp-10h]
  int v31; // [esp+FCh] [ebp-Ch] BYREF
  void *collideType; // [esp+100h] [ebp-8h]
  void *retaddr; // [esp+108h] [ebp+0h]

  v31 = a1;
  collideType = retaddr;
  v23 = a3;
  v22 = a2;
  if ( materialIndex < 0 )
    materialIndex = 0;
  IVP_Template_Real_Object::IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1]);
  x = position->x;
  if ( (LODWORD(x) & 0x7F800000) == 0x7F800000
    || (x = position->y, (LODWORD(x) & 0x7F800000) == 0x7F800000)
    || (x = position->z, (LODWORD(x) & 0x7F800000) == 0x7F800000)
    || (v10 = angles, x = angles->x, (LODWORD(x) & 0x7F800000) == 0x7F800000)
    || (x = angles->y, (LODWORD(x) & 0x7F800000) == 0x7F800000)
    || (x = angles->z, (LODWORD(x) & 0x7F800000) == 0x7F800000) )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: a2, a2: a3) != 0 )
      __debugbreak();
    _Warning(a1: "Invalid initial position on %s\n", pParams->pName);
    x = position->x;
    if ( (LODWORD(x) & 0x7F800000) == 0x7F800000
      || (x = position->y, (LODWORD(x) & 0x7F800000) == 0x7F800000)
      || (x = position->z, (LODWORD(x) & 0x7F800000) == 0x7F800000) )
    {
      position->x = 0.0;
      position->y = 0.0;
      position->z = 0.0;
    }
    v10 = angles;
    x = angles->x;
    if ( (LODWORD(x) & 0x7F800000) == 0x7F800000
      || (x = angles->y, (LODWORD(x) & 0x7F800000) == 0x7F800000)
      || (x = angles->z, v10 = angles, (LODWORD(x) & 0x7F800000) == 0x7F800000) )
    {
      v10->x = 0.0;
      v10->y = 0.0;
      v10->z = 0.0;
      v10 = angles;
    }
  }
  ConvertRotationToIVP(a1: (int)&v31, angles: v10, out: (IVP_U_Quat *)&objectTemplate.mass_center_override);
  center.k[1] = position->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(center.k[2]) = COERCE_UNSIGNED_INT(position->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  center.hesse_val = position->y * g_PhysicsUnits.unitScaleMeters;
  InitObjectTemplate(
    objectTemplate: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1],
    materialIndex,
    pParams,
    isStatic);
  IVP_U_Matrix::init(this: (IVP_U_Matrix *)v24);
  massCenterOverride = pParams->massCenterOverride;
  if ( pParams->massCenterOverride != nullptr )
  {
    y = massCenterOverride->y;
    rotation.y = massCenterOverride->x * g_PhysicsUnits.unitScaleMeters;
    LODWORD(rotation.z) = COERCE_UNSIGNED_INT(massCenterOverride->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
    rotation.w = y * g_PhysicsUnits.unitScaleMeters;
    IVP_U_Matrix::shift_os(this: (IVP_U_Matrix *)v24, v_in: (const IVP_U_Point *)&rotation.y);
    LODWORD(objectTemplate.rot_speed_damp_factor.k[2]) = v24;
  }
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsEnvironment *, int, int))pEnvironment->IsPredicted)(
         a1: pEnvironment,
         a2: v22,
         a3: v23) != 0 )
  {
    v13 = (CPredictedPhysicsObject *)p_malloc(size: 0x118u);
    if ( v13 != nullptr )
    {
      v14 = CPredictedPhysicsObject::CPredictedPhysicsObject(this: v13);
      goto LABEL_27;
    }
  }
  else
  {
    v15 = (CPredictedPhysicsObject *)p_malloc(size: 0x4Cu);
    v14 = v15;
    if ( v15 != nullptr )
    {
      LODWORD(pos.hesse_val) = 72;
      LOBYTE(pos.k[2]) = 0;
      LODWORD(pos.k[1]) = &v15->m_pGameData;
      v15->__vftable = (CPredictedPhysicsObject_vtbl *)&CPhysicsObject::`vftable';
      memset(dst: (unsigned __int8 *)LODWORD(pos.k[1]), value: LOBYTE(pos.k[2]), count: LODWORD(pos.hesse_val));
      v16 = *((_BYTE *)&v14->CPhysicsObject + 21) & 0x1F | 0x40;
      *((_BYTE *)&v14->CPhysicsObject + 20) &= ~0x20u;
      *((_BYTE *)&v14->CPhysicsObject + 21) = v16;
      v14->m_contentsMask = 1;
      goto LABEL_27;
    }
  }
  v14 = nullptr;
LABEL_27:
  SurfaceManager = CreateSurfaceManager(pCollisionModel, collideType: (__int16 *)&pos.hesse_val);
  if ( SurfaceManager != nullptr )
  {
    hesse_val_low = LOBYTE(pos.hesse_val);
    v20 = *((_BYTE *)&v14->CPhysicsObject + 21);
    *((_BYTE *)&v14->CPhysicsObject + 20) |= 0x40u;
    *((_BYTE *)&v14->CPhysicsObject + 21) = (32 * hesse_val_low) | v20 & 0x1F;
    polygon = IVP_Environment::create_polygon(
                this: pEnvironment->m_pPhysEnv,
                vic: SurfaceManager,
                templ: (const IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1],
                rotation: (const IVP_U_Quat *)&objectTemplate.mass_center_override,
                position: (IVP_U_Point *)&center.k[1]);
    CPhysicsObject::Init(
      this: v14,
      pCollisionModel,
      pObject: polygon,
      materialIndex,
      volume: pParams->volume,
      drag: pParams->dragCoefficient,
      angDrag: pParams->dragCoefficient);
    v14->SetGameData(this: v14, a2: pParams->pGameData);
    if ( pParams->enableCollisions )
      v14->EnableCollisions(this: v14, a2: true);
    if ( !isStatic && pParams->dragCoefficient != 0.0 )
      v14->EnableDrag(this: v14, a2: true);
    if ( pEnvironment->IsPredicted(this: pEnvironment) )
      CPredictedPhysicsObject::OnPredictionCommandChanged(this: v14, a2: (int)pParams, iCommandNum: -1, bBackup: true);
    IVP_Template_Real_Object::~IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1]);
    return v14;
  }
  else
  {
    IVP_Template_Real_Object::~IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)&massCenterMatrix.vv.k[1]);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E430
// Name: class CPhysicsObject __near * CreatePhysicsSphere(class CPhysicsEnvironment __near *,float,int,class Vector const __near &,class QAngle const __near &,struct objectparams_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CPredictedPhysicsObject *__usercall CreatePhysicsSphere@<eax>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CPhysicsEnvironment *pEnvironment,
        float radius,
        int materialIndex,
        const Vector *position,
        const QAngle *angles,
        objectparams_t *pParams,
        bool isStatic)
{
  IVP_Environment *m_pPhysEnv; // ecx
  IVP_Ball *ball; // eax
  float volume; // xmm0_4
  CPredictedPhysicsObject *v13; // eax
  CPredictedPhysicsObject *v14; // esi
  char v15; // cl
  _BYTE v17[12]; // [esp+1Ch] [ebp-9Ch] BYREF
  IVP_Template_Real_Object objectTemplate; // [esp+28h] [ebp-90h] BYREF
  IVP_U_Quat rotation; // [esp+88h] [ebp-30h] BYREF
  IVP_U_Point pos; // [esp+98h] [ebp-20h] BYREF
  unsigned int angDrag; // [esp+A8h] [ebp-10h]
  IVP_Template_Ball ballTemplate; // [esp+ACh] [ebp-Ch] BYREF
  IVP_Ball *realObject; // [esp+B0h] [ebp-8h]
  IVP_Ball *retaddr; // [esp+B8h] [ebp+0h]

  ballTemplate.radius = a1;
  realObject = retaddr;
  ConvertRotationToIVP(a1: (int)&ballTemplate, angles, out: (IVP_U_Quat *)&objectTemplate.mass_center_override);
  rotation.y = position->x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(rotation.z) = COERCE_UNSIGNED_INT(position->z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  rotation.w = position->y * g_PhysicsUnits.unitScaleMeters;
  IVP_Template_Real_Object::IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)v17);
  InitObjectTemplate(objectTemplate: (IVP_Template_Real_Object *)v17, materialIndex, pParams, isStatic);
  m_pPhysEnv = pEnvironment->m_pPhysEnv;
  pos.k[2] = g_PhysicsUnits.unitScaleMeters * radius;
  ball = IVP_Environment::create_ball(
           this: m_pPhysEnv,
           templ_ball: (const IVP_Template_Ball *)&pos.k[2],
           templ: (const IVP_Template_Real_Object *)v17,
           rotation: (const IVP_U_Quat *)&objectTemplate.mass_center_override,
           position: (const IVP_U_Point *)&rotation.y);
  volume = pParams->volume;
  LODWORD(pos.hesse_val) = ball;
  *(float *)&angDrag = volume;
  if ( volume <= 0.0 )
    *(float *)&angDrag = (float)((float)((float)(radius * 4.0) * radius) * radius)
                       * 3.141592653589793
                       * 0.3333333333333333;
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsEnvironment *, int, int))pEnvironment->IsPredicted)(
         a1: pEnvironment,
         a2,
         a3) != 0 )
  {
    v13 = (CPredictedPhysicsObject *)p_malloc(size: 0x118u);
    if ( v13 != nullptr )
    {
      v14 = CPredictedPhysicsObject::CPredictedPhysicsObject(this: v13);
      goto LABEL_9;
    }
  }
  else
  {
    v14 = (CPredictedPhysicsObject *)p_malloc(size: 0x4Cu);
    if ( v14 != nullptr )
    {
      angDrag = 72;
      LOBYTE(pos.hesse_val) = 0;
      LODWORD(pos.k[2]) = &v14->m_pGameData;
      v14->__vftable = (CPredictedPhysicsObject_vtbl *)&CPhysicsObject::`vftable';
      memset(dst: (unsigned __int8 *)LODWORD(pos.k[2]), value: LOBYTE(pos.hesse_val), count: angDrag);
      v15 = *((_BYTE *)&v14->CPhysicsObject + 21) & 0x1F | 0x40;
      *((_BYTE *)&v14->CPhysicsObject + 20) &= ~0x20u;
      *((_BYTE *)&v14->CPhysicsObject + 21) = v15;
      v14->m_contentsMask = 1;
      goto LABEL_9;
    }
  }
  v14 = nullptr;
LABEL_9:
  CPhysicsObject::Init(
    this: v14,
    pCollisionModel: nullptr,
    pObject: (IVP_Real_Object *)LODWORD(pos.hesse_val),
    materialIndex,
    volume: 0.0,
    drag: 0.0,
    angDrag: 0.0);
  v14->SetGameData(this: v14, a2: pParams->pGameData);
  if ( pParams->enableCollisions )
    v14->EnableCollisions(this: v14, a2: true);
  if ( pEnvironment->IsPredicted(this: pEnvironment) )
    CPredictedPhysicsObject::OnPredictionCommandChanged(this: v14, a2: (int)pParams, iCommandNum: -1, bBackup: true);
  IVP_Template_Real_Object::~IVP_Template_Real_Object(this: (IVP_Template_Real_Object *)v17);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x100AC620
// Name: public: virtual bool CPredictedPhysicsObject::IsPredicted(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPredictedPhysicsObject::IsPredicted(CDataManagerBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C6AC0
// Name: vphysics_save_cphysicsobject_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cphysicsobject_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cphysicsobject_t>(__formal: nullptr);
  vphysics_save_cphysicsobject_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E620
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cphysicsobject_t>(struct vphysics_save_cphysicsobject_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cphysicsobject_t>()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    nameHolder_13.m_pszBase = "vphysics_save_cphysicsobject_t";
    nameHolder_13.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_13.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_13.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_13.m_Names.m_Size = 0;
    nameHolder_13.m_Names.m_pElements = nullptr;
    nameHolder_13.m_nLenBase = 30;
    atexit(func: DataMapInit_vphysics_save_cphysicsobject_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cphysicsobject_t::m_DataMap.baseMap = nullptr;
  vphysics_save_cphysicsobject_t::m_DataMap.dataNumFields = 30;
  vphysics_save_cphysicsobject_t::m_DataMap.dataDesc = &dataDesc_13[1];
  return &vphysics_save_cphysicsobject_t::m_DataMap;
}
