// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics.cpp
// Functions: 118
// ============================================================

#include "game\server\physics.h"

//------------------------------------------------------------------------------
// Address: 0x10185220
// Name: void TimescaleChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TimescaleChanged()
{
  if ( physenv != nullptr )
    physenv->ResetSimulationClock(this: physenv);
}

//------------------------------------------------------------------------------
// Address: 0x10185240
// Name: class IGameSystem __near * PhysicsGameSystem(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsHook *__cdecl PhysicsGameSystem()
{
  return &g_PhysicsHook;
}

//------------------------------------------------------------------------------
// Address: 0x10185250
// Name: public: virtual void CPhysicsHook::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsHook::LevelInitPostEntity(CPhysicsHook *this)
{
  this->m_bPaused = false;
}

//------------------------------------------------------------------------------
// Address: 0x10185260
// Name: public: virtual void CPhysicsHook::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsHook::LevelShutdownPreEntity(CPhysicsHook *this)
{
  if ( physenv != nullptr )
    physenv->SetQuickDelete(this: physenv, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10185280
// Name: bool PhysIsFinalTick(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysIsFinalTick()
{
  return g_PhysicsHook.m_isFinalTick;
}

//------------------------------------------------------------------------------
// Address: 0x10185290
// Name: public: virtual bool CCollisionEvent::ShouldFreezeContacts(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionEvent::ShouldFreezeContacts(
        CCollisionEvent *this,
        IPhysicsObject **pObjectList,
        int objectCount)
{
  int m_inCallback; // eax
  int tickcount; // ecx

  m_inCallback = this->m_inCallback;
  tickcount = gpGlobals->tickcount;
  if ( m_inCallback > tickcount || m_inCallback < tickcount - 1 )
    DevWarning(a1: "Performance Warning: large friction system (%d objects)!!!\n", objectCount);
  this->m_inCallback = gpGlobals->tickcount;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101852E0
// Name: public: virtual void CCollisionEvent::ObjectWake(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectWake(CCollisionEvent *this, IPhysicsObject *pObject)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)pObject->GetGameData(this: pObject);
  v3 = v2;
  if ( v2 != nullptr && CBaseEntity::HasDataObjectType(this: v2, type: 7) )
    ReportVPhysicsStateChanged(pPhysics: pObject, pEntity: v3, bAwake: true);
}

//------------------------------------------------------------------------------
// Address: 0x10185320
// Name: public: virtual void CCollisionEvent::ObjectSleep(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectSleep(CCollisionEvent *this, IPhysicsObject *pObject)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)pObject->GetGameData(this: pObject);
  v3 = v2;
  if ( v2 != nullptr && CBaseEntity::HasDataObjectType(this: v2, type: 7) )
    ReportVPhysicsStateChanged(pPhysics: pObject, pEntity: v3, bAwake: false);
}

//------------------------------------------------------------------------------
// Address: 0x10185360
// Name: bool PhysIsInCallback(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysIsInCallback()
{
  return physenv != nullptr && physenv->IsInSimulation(this: physenv) || g_Collisions.m_inCallback > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10185390
// Name: void IterateActivePhysicsEntities(void (*)(class CBaseEntity __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl IterateActivePhysicsEntities(void (__cdecl *func)(CBaseEntity *))
{
  int v1; // ebx
  void *v2; // esp
  int i; // esi
  CBaseEntity *v4; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-Ch] BYREF

  v1 = physenv->GetActiveObjectCount(this: physenv);
  if ( v1 != 0 )
  {
    v2 = alloca(4 * v1);
    physenv->GetActiveObjects(this: physenv, a2: (IPhysicsObject **)v5);
    for ( i = 0; i < v1; ++i )
    {
      v4 = (CBaseEntity *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v5[i] + 68))(a1: v5[i]);
      if ( v4 != nullptr )
        func(a1: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185400
// Name: CallbackHighlight
// Source: json
//------------------------------------------------------------------------------
void __cdecl CallbackHighlight(CBaseEntity *pEntity)
{
  pEntity->m_debugOverlays |= 0x28u;
}

//------------------------------------------------------------------------------
// Address: 0x10185410
// Name: physics_highlight_active
// Source: json
//------------------------------------------------------------------------------
void __cdecl physics_highlight_active()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    IterateActivePhysicsEntities(func: CallbackHighlight);
}

//------------------------------------------------------------------------------
// Address: 0x10185430
// Name: void PhysAddShadow(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysAddShadow(CBaseEntity *pEntity)
{
  CEntityList::AddEntity(this: g_pShadowEntities, pEnt: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10185450
// Name: void PhysRemoveShadow(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysRemoveShadow(CBaseEntity *pEntity)
{
  CEntityList::DeleteEntity(this: g_pShadowEntities, pEnt: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10185470
// Name: void PhysEnableFloating(class IPhysicsObject __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysEnableFloating(IPhysicsObject *pObject, bool bEnable)
{
  unsigned __int16 v2; // ax

  if ( pObject != nullptr )
  {
    v2 = pObject->GetCallbackFlags(this: pObject);
    if ( bEnable )
      pObject->SetCallbackFlags(this: pObject, a2: v2 | 0x1000);
    else
      pObject->SetCallbackFlags(this: pObject, a2: v2 & 0xEFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101854C0
// Name: public: virtual void CCollisionEvent::PostCollision(struct vcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::PostCollision(CCollisionEvent *this, vcollisionevent_t *pEvent)
{
  int v3; // edi
  IPhysicsObject *v4; // esi
  int v5; // eax
  vcollisionevent_t *v6; // eax
  CBaseEntity **v7; // edi
  CBaseEntity *v8; // ecx
  int v9; // esi
  char flags; // [esp+Ch] [ebp-10h]
  CBaseEntity **pEntities; // [esp+10h] [ebp-Ch]
  Vector *postVelocity; // [esp+14h] [ebp-8h]
  bool isShadow[4]; // [esp+18h] [ebp-4h]

  ++this->m_inCallback;
  postVelocity = this->m_gameEvent.postVelocity;
  *(_WORD *)isShadow = 0;
  v3 = 0;
  pEntities = this->m_gameEvent.pEntities;
  do
  {
    v4 = pEvent->pObjects[v3];
    if ( v4 != nullptr )
    {
      v5 = (int)v4->GetGameData(this: pEvent->pObjects[v3]);
      if ( v5 == 0 )
        goto LABEL_22;
      *pEntities = (CBaseEntity *)v5;
      flags = v4->GetCallbackFlags(this: v4);
      v4->GetVelocity(this: v4, a2: postVelocity, a3: nullptr);
      if ( (flags & 0x10) != 0 )
        isShadow[v3] = true;
    }
    ++postVelocity;
    ++pEntities;
    ++v3;
  }
  while ( v3 < 2 );
  v6 = pEvent;
  v7 = this->m_gameEvent.pEntities;
  this->m_gameEvent.collisionSpeed = pEvent->collisionSpeed;
  this->m_gameEvent.pInternalData = pEvent->pInternalData;
  v8 = this->m_gameEvent.pEntities[0];
  if ( v8 == this->m_gameEvent.pEntities[1] )
  {
    if ( pEvent->isCollision && v8 != nullptr )
    {
      v8->VPhysicsCollision(this: v8, a2: 0, a3: &this->m_gameEvent);
      --this->m_inCallback;
      return;
    }
  }
  else
  {
    if ( isShadow[0] && isShadow[1] )
      pEvent->isCollision = false;
    v9 = 0;
    while ( 1 )
    {
      if ( v6->isCollision )
        (*v7)->VPhysicsCollision(this: *v7, a2: v9, a3: &this->m_gameEvent);
      if ( pEvent->isShadowCollision && isShadow[v9] )
        (*v7)->VPhysicsShadowCollision(this: *v7, a2: v9, a3: &this->m_gameEvent);
      ++v9;
      ++v7;
      if ( v9 >= 2 )
        break;
      v6 = pEvent;
    }
  }
LABEL_22:
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x10185600
// Name: public: struct friction_t __near * CCollisionEvent::FindFriction(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
friction_t *__thiscall CCollisionEvent::FindFriction(CCollisionEvent *this, CBaseEntity *pObject)
{
  friction_t *result; // eax
  int v3; // edx
  CBaseEntity **i; // esi

  result = nullptr;
  v3 = 0;
  for ( i = &this->m_current[0].pObject; ; i += 4 )
  {
    if ( *i == nullptr && result == nullptr )
      result = (friction_t *)(i - 1);
    if ( *i == pObject )
      break;
    if ( (unsigned int)++v3 >= 4 )
      return result;
  }
  return &this->m_current[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10185640
// Name: private: void CCollisionEvent::UpdateFrictionSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateFrictionSounds(CCollisionEvent *this)
{
  friction_t *m_current; // esi
  int i; // edi
  CSoundEnvelopeController *Controller; // eax

  m_current = this->m_current;
  for ( i = 4; i != 0; --i )
  {
    if ( m_current->patch != nullptr && (float)(gpGlobals->curtime - 0.1) > m_current->flLastUpdateTime )
    {
      Controller = CSoundEnvelopeController::GetController();
      Controller->SoundDestroy(this: Controller, a2: m_current->patch);
      m_current->patch = nullptr;
      m_current->pObject = nullptr;
    }
    ++m_current;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101856A0
// Name: public: class CTakeDamageInfo __near & CTakeDamageInfo::operator=(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CTakeDamageInfo *__thiscall CTakeDamageInfo::operator=(CTakeDamageInfo *this, const CTakeDamageInfo *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10185740
// Name: PostSimulation_ImpulseEvent
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostSimulation_ImpulseEvent(
        IPhysicsObject *pObject,
        const Vector *centerForce,
        const Vector *centerTorque)
{
  pObject->ApplyForceCenter(this: pObject, a2: centerForce);
  pObject->ApplyTorqueCenter(this: pObject, a2: centerTorque);
}

//------------------------------------------------------------------------------
// Address: 0x10185770
// Name: public: void CCollisionEvent::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::LevelShutdown(CCollisionEvent *this)
{
  friction_t *m_current; // esi
  int i; // edi
  CSoundEnvelopeController *Controller; // eax

  m_current = this->m_current;
  for ( i = 4; i != 0; --i )
  {
    if ( m_current->patch != nullptr )
    {
      Controller = CSoundEnvelopeController::GetController();
      Controller->SoundDestroy(this: Controller, a2: m_current->patch);
      m_current->patch = nullptr;
      m_current->pObject = nullptr;
    }
    ++m_current;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101857B0
// Name: CountPhysicsObjectEntityContacts
// Source: json
//------------------------------------------------------------------------------
int __usercall CountPhysicsObjectEntityContacts@<eax>(IPhysicsObject *pObject@<edi>, CBaseEntity *pEntity)
{
  IPhysicsFrictionSnapshot *v2; // esi
  int v3; // ebx
  int v4; // eax

  v2 = pObject->CreateFrictionSnapshot(this: pObject);
  v3 = 0;
  while ( v2->IsValid(this: v2) )
  {
    v4 = (int)v2->GetObject(this: v2, a2: 1);
    if ( (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 68))(a1: v4) == pEntity )
      ++v3;
    v2->NextFrictionData(this: v2);
  }
  pObject->DestroyFrictionSnapshot(this: pObject, a2: v2);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10185820
// Name: bool PhysGetTriggerEvent(struct triggerevent_t __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PhysGetTriggerEvent(triggerevent_t *pEvent, CBaseEntity *pTriggerEntity)
{
  if ( pEvent == nullptr || pTriggerEntity != g_Collisions.m_currentTriggerEvent.pTriggerEntity )
    return 0;
  *pEvent = g_Collisions.m_currentTriggerEvent;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10185860
// Name: void PhysCollisionDust(struct gamevcollisionevent_t __near *,struct surfacedata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCollisionDust(gamevcollisionevent_t *pEvent, surfacedata_t *phit)
{
  float v2; // xmm0_4
  Vector vecNormal; // [esp+4h] [ebp-30h] BYREF
  Vector vecPos; // [esp+10h] [ebp-24h] BYREF
  QAngle angNormal; // [esp+1Ch] [ebp-18h] BYREF
  Vector vecVel; // [esp+28h] [ebp-Ch]

  if ( phit->game.material == 67 )
  {
    v2 = 340.0;
LABEL_6:
    if ( v2 <= pEvent->collisionSpeed )
    {
      pEvent->pInternalData->GetContactPoint(this: pEvent->pInternalData, a2: &vecPos);
      pEvent->pInternalData->GetSurfaceNormal(this: pEvent->pInternalData, a2: &vecNormal);
      VectorAngles(forward: &vecNormal, angles: &angNormal);
      vecVel.z = pEvent->collisionSpeed;
      vecVel.x = vecVel.z;
      vecVel.y = vecVel.z;
      DispatchParticleEffect(
        pszParticleName: "impact_physics_dust",
        vecOrigin: vecPos,
        vecStart: vecVel,
        vecAngles: angNormal,
        pEntity: nullptr,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr);
    }
    return;
  }
  if ( phit->game.material == 68 || phit->game.material == 78 )
  {
    v2 = 200.0;
    goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185940
// Name: void PhysCleanupFrictionSounds(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCleanupFrictionSounds(CBaseEntity *pEntity)
{
  friction_t *v1; // esi
  unsigned int v2; // eax
  CBaseEntity **p_pObject; // ecx
  CSoundEnvelopeController *Controller; // eax

  v1 = nullptr;
  v2 = 0;
  p_pObject = &g_Collisions.m_current[0].pObject;
  while ( 1 )
  {
    if ( *p_pObject == nullptr && v1 == nullptr )
      v1 = (friction_t *)(p_pObject - 1);
    if ( *p_pObject == pEntity )
      break;
    ++v2;
    p_pObject += 4;
    if ( v2 >= 4 )
      goto LABEL_9;
  }
  v1 = &g_Collisions.m_current[v2];
LABEL_9:
  if ( v1 != nullptr && v1->patch != nullptr )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->SoundDestroy(this: Controller, a2: v1->patch);
    v1->patch = nullptr;
    v1->pObject = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185A50
// Name: public: virtual void CPhysicsHook::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsHook::LevelInitPreEntity(CPhysicsHook *this)
{
  IPhysicsEnvironment *v2; // eax
  int v3; // xmm0_4
  CWorld *WorldEntity; // esi
  vcollide_t *v5; // eax
  CEntityList *v6; // eax
  physics_performanceparams_t params; // [esp+2Ch] [ebp-38h] BYREF
  factorylist_t factories; // [esp+4Ch] [ebp-18h] BYREF
  _DWORD v9[3]; // [esp+58h] [ebp-Ch] BYREF

  v2 = physics->CreateEnvironment(this: physics);
  params.maxVelocity = 2000.0;
  params.maxAngularVelocity = 3600.0;
  params.lookAheadTimeObjectsVsWorld = 1.0;
  params.lookAheadTimeObjectsVsObject = 0.5;
  params.minFrictionMass = 10.0;
  physenv = v2;
  params.maxCollisionChecksPerTimestep = 250;
  params.maxFrictionMass = 2500.0;
  params.maxCollisionsPerObjectPerTimestep = 10;
  v2->SetPerformanceSettings(this: v2, a2: &params);
  g_EntityCollisionHash = physics->CreateObjectPairHash(this: physics);
  FactoryList_Retrieve(destData: &factories);
  physenv->SetDebugOverlay(this: physenv, a2: factories.engineFactory);
  physenv->EnableDeleteQueue(this: physenv, a2: true);
  physenv->SetCollisionSolver(this: physenv, a2: &g_Collisions.IPhysicsCollisionSolver);
  physenv->SetCollisionEventHandler(this: physenv, a2: &g_Collisions);
  physenv->SetConstraintEventHandler(this: physenv, a2: g_pConstraintEvents);
  physenv->EnableConstraintNotify(this: physenv, a2: true);
  physenv->SetObjectEventHandler(this: physenv, a2: &g_Collisions.IPhysicsObjectEvent);
  ((void (__stdcall *)(int))physenv->SetSimulationTimestep)(a1: 1015580809);
  v3 = LODWORD(sv_gravity.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
  v9[0] = 0;
  v9[1] = 0;
  v9[2] = v3;
  physenv->SetGravity(this: physenv, a2: (const Vector *)v9);
  g_PhysAverageSimTime = 0.0;
  WorldEntity = GetWorldEntity();
  staticpropmgr->CreateVPhysicsRepresentations(this: staticpropmgr, a2: physenv, a3: &g_SolidSetup, a4: WorldEntity);
  v5 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *))modelinfo->GetVCollide)(a1: modelinfo);
  g_PhysWorldObject = PhysCreateWorld_Shared(
                        pWorld: WorldEntity,
                        pWorldCollide: v5,
                        defaultParams: (const objectparams_t *)1);
  v6 = (CEntityList *)operator new(nSize: 8u);
  if ( v6 != nullptr )
    g_pShadowEntities = CEntityList::CEntityList(this: v6);
  else
    g_pShadowEntities = nullptr;
  PrecachePhysicsSounds();
  this->m_bPaused = true;
}

//------------------------------------------------------------------------------
// Address: 0x10185C70
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
// Address: 0x10185D20
// Name: bool FindMaxContact(class IPhysicsObject __near *,float,class IPhysicsObject __near * __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FindMaxContact(
        IPhysicsObject *pObject,
        float minForce,
        IPhysicsObject **pOtherObject,
        Vector *contactPos,
        Vector *pForce)
{
  IPhysicsObject *v5; // edi
  int v6; // esi
  IPhysicsObject *v7; // ebx
  double v8; // st7
  float force; // [esp+8h] [ebp-8h]
  float mass; // [esp+Ch] [ebp-4h]

  v5 = pObject;
  mass = pObject->GetMass(this: pObject);
  *pOtherObject = nullptr;
  v6 = (int)v5->CreateFrictionSnapshot(this: v5);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6) != 0 )
  {
    do
    {
      v7 = (IPhysicsObject *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 8))(a1: v6, a2: 1);
      if ( v7->IsMoveable(this: v7) && ((double (__thiscall *)(IPhysicsObject *))v7->GetMass)(a1: v7) > mass )
      {
        v8 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 24))(a1: v6);
        force = v8;
        if ( v8 > minForce )
        {
          *pOtherObject = v7;
          (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v6 + 16))(a1: v6, a2: contactPos);
          (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v6 + 20))(a1: v6, a2: pForce);
          pForce->x = pForce->x * force;
          pForce->y = pForce->y * force;
          pForce->z = pForce->z * force;
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 48))(a1: v6);
    }
    while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6) != 0 );
    v5 = pObject;
  }
  v5->DestroyFrictionSnapshot(this: v5, a2: (IPhysicsFrictionSnapshot *)v6);
  return *pOtherObject != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10185E30
// Name: UpdateEntityPenetrationFlag
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateEntityPenetrationFlag(CBaseEntity *pEntity@<ecx>, int a2@<esi>, bool isPenetrating)
{
  int v3; // ebx
  int i; // edi
  int v5; // esi
  __int16 v6; // ax
  unsigned __int16 v7; // ax
  _DWORD v9[1024]; // [esp+0h] [ebp-1000h] BYREF

  if ( pEntity != nullptr )
  {
    v3 = pEntity->VPhysicsGetObjectList(this: pEntity, a2: (IPhysicsObject **)v9, a3: 1024);
    for ( i = 0; i < v3; ++i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)v9[i] + 4))(a1: v9[i]) == 0 )
      {
        v5 = v9[i];
        v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 76))(a1: v5, a2);
        if ( isPenetrating )
          v7 = v6 | 0x40;
        else
          v7 = v6 & 0xFFBF;
        a2 = v7;
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 72))(a1: v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185EC0
// Name: MarkVPhysicsDebug
// Source: json
//------------------------------------------------------------------------------
void __cdecl MarkVPhysicsDebug(CBaseEntity *pEntity)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  unsigned __int16 v2; // ax

  if ( pEntity != nullptr )
  {
    m_pPhysicsObject = pEntity->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      v2 = m_pPhysicsObject->GetCallbackFlags(this: m_pPhysicsObject);
      m_pPhysicsObject->SetCallbackFlags(this: m_pPhysicsObject, a2: v2 ^ 0x8000);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10185F00
// Name: public: virtual void CCollisionEvent::PreCollision(struct vcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCollisionEvent::PreCollision(
        CCollisionEvent *this@<ecx>,
        Vector *a2@<edi>,
        vcollisionevent_t *pEvent)
{
  vcollisionevent_t *v3; // eax
  int v5; // edi
  IPhysicsObject *v6; // ebx
  IPhysicsObject *v7; // ecx
  int v8; // eax
  double v9; // st7
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm0_4
  void (__thiscall *SetVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  Vector velocity; // [esp+8h] [ebp-20h] BYREF
  Vector angVel; // [esp+14h] [ebp-14h] BYREF
  Vector *preVelocity; // [esp+20h] [ebp-8h]
  float len; // [esp+24h] [ebp-4h]

  v3 = pEvent;
  ++this->m_inCallback;
  this->m_gameEvent.vcollisionevent_t = *pEvent;
  v5 = 0;
  this->m_gameEvent.pEntities[0] = nullptr;
  this->m_gameEvent.pEntities[1] = nullptr;
  preVelocity = this->m_gameEvent.preVelocity;
  do
  {
    v6 = v3->pObjects[v5];
    if ( v6 != nullptr )
    {
      if ( (((int (__thiscall *)(IPhysicsObject *, Vector *))v6->GetGameFlags)(a1: v6, a2) & 4) != 0 )
      {
        v7 = pEvent->pObjects[v5 == 0];
        v8 = (int)v7->GetGameData(this: v7);
        if ( v8 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 336))(a1: v8) == 0 )
        {
          v6->GetVelocity(this: v6, a2: &velocity, a3: &angVel);
          v9 = VectorNormalize(vec: &velocity);
          len = v9;
          if ( v9 > 10.0 )
            v10 = len;
          else
            v10 = 10.0;
          velocity.x = velocity.x * v10;
          velocity.y = velocity.y * v10;
          velocity.z = velocity.z * v10;
          v11 = VectorNormalize(vec: &angVel);
          len = v11;
          if ( v11 > 1.0 )
            v12 = len;
          else
            v12 = 1.0;
          SetVelocity = v6->SetVelocity;
          angVel.x = angVel.x * v12;
          angVel.y = angVel.y * v12;
          angVel.z = angVel.z * v12;
          SetVelocity(this: v6, a2: &velocity, a3: &angVel);
        }
      }
      a2 = preVelocity + 4;
      ((void (__thiscall *)(IPhysicsObject *, Vector *))v6->GetVelocity)(a1: v6, a2: preVelocity);
      v3 = pEvent;
    }
    ++preVelocity;
    ++v5;
  }
  while ( v5 < 2 );
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x101860A0
// Name: void PhysForceEntityToSleep(class CBaseEntity __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysForceEntityToSleep(CBaseEntity *pEntity, IPhysicsObject *pObject)
{
  const char *pszValue; // eax
  int v3; // edi
  int i; // esi
  IPhysicsObject *pPhys[1024]; // [esp+0h] [ebp-1000h] BYREF

  if ( pObject != nullptr && pObject->IsMoveable(this: pObject) )
  {
    pszValue = pEntity->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    _DevMsg(a1: 2, a2: "Putting entity to sleep: %s\n", pszValue);
    v3 = pEntity->VPhysicsGetObjectList(this: pEntity, a2: pPhys, a3: 1024);
    for ( i = 0; i < v3; ++i )
    {
      PhysForceClearVelocity(pPhys: pPhys[i]);
      pPhys[i]->Sleep(this: pPhys[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186130
// Name: public: virtual void CCollisionEvent::Friction(class IPhysicsObject __near *,float,int,int,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::Friction(
        CCollisionEvent *this,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit,
        CBaseEntity *pData)
{
  friction_t *v7; // ecx
  unsigned int v8; // edx
  CBaseEntity **p_pObject; // esi
  friction_t *v10; // edx
  float curtime; // xmm0_4
  Vector vecPos; // [esp+34h] [ebp-18h] BYREF
  Vector vecVel; // [esp+40h] [ebp-Ch] BYREF
  CBaseEntity *pEntity; // [esp+64h] [ebp+18h]

  ++this->m_inCallback;
  pData->SetRefEHandle(this: pData, a2: (const CBaseHandle *)&vecPos);
  pObject->GetVelocityAtPoint(this: pObject, a2: &vecPos, a3: &vecVel);
  pEntity = (CBaseEntity *)pObject->GetGameData(this: pObject);
  if ( pEntity != nullptr )
  {
    v7 = nullptr;
    v8 = 0;
    p_pObject = &g_Collisions.m_current[0].pObject;
    while ( 1 )
    {
      if ( *p_pObject == nullptr && v7 == nullptr )
        v7 = (friction_t *)(p_pObject - 1);
      if ( *p_pObject == pEntity )
        break;
      ++v8;
      p_pObject += 4;
      if ( v8 >= 4 )
      {
        v10 = v7;
        goto LABEL_9;
      }
    }
    v10 = &g_Collisions.m_current[v8];
LABEL_9:
    if ( v10 != nullptr && v10->pObject != nullptr )
    {
      curtime = gpGlobals->curtime;
      if ( (float)(v10->flLastEffectTime + 0.5) > curtime )
      {
        v10->flLastUpdateTime = curtime;
        --this->m_inCallback;
        return;
      }
    }
    ((void (__stdcall *)(IPhysicsObject *, _DWORD, int, int))pEntity->VPhysicsFriction)(
      a1: pObject,
      a2: LODWORD(energy),
      a3: surfaceProps,
      a4: surfacePropsHit);
  }
  PhysFrictionEffect(&vecPos, vecVel, energy, surfaceProps, surfacePropsHit);
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x10186250
// Name: void PhysCollisionScreenShake(struct gamevcollisionevent_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCollisionScreenShake(gamevcollisionevent_t *pEvent, int index)
{
  BOOL v3; // ebx
  double v4; // st7
  float amplitude; // xmm0_4
  Vector vecPos; // [esp+2Ch] [ebp-Ch] BYREF
  float mass; // [esp+44h] [ebp+Ch]

  v3 = index == 0;
  v4 = ((double (__thiscall *)(IPhysicsObject *))pEvent->pObjects[index]->GetMass)(a1: pEvent->pObjects[index]);
  mass = v4;
  if ( v4 >= 500.0
    && pEvent->pObjects[v3]->IsStatic(this: pEvent->pObjects[v3])
    && (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[index]->GetGameFlags)(a1: pEvent->pObjects[index]) & 0x40) == 0 )
  {
    if ( mass > 2000.0 )
      mass = 2000.0;
    if ( pEvent->collisionSpeed > 30.0 && pEvent->deltaCollisionTime > 0.25 )
    {
      pEvent->pInternalData->GetContactPoint(this: pEvent->pInternalData, a2: &vecPos);
      amplitude = (float)(pEvent->collisionSpeed * mass)
                * (float)(collision_shake_amp.m_pParent->m_Value.m_fValue * 0.000066666667);
      UTIL_ScreenShake(
        center: &vecPos,
        amplitude,
        frequency: collision_shake_freq.m_pParent->m_Value.m_fValue,
        duration: collision_shake_time.m_pParent->m_Value.m_fValue,
        radius: amplitude * 60.0,
        eCommand: SHAKE_START,
        bAirShake: false,
        ignore: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186560
// Name: void CC_AirDensity(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_AirDensity(const CCommand *args)
{
  double v1; // st7
  const char *v2; // eax
  float density; // [esp+8h] [ebp-4h]

  if ( physenv != nullptr )
  {
    if ( args->m_nArgc >= 2 )
    {
      v2 = locale;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      density = atof(nptr: v2);
      ((void (__thiscall *)(IPhysicsEnvironment *, _DWORD))physenv->SetAirDensity)(a1: physenv, a2: LODWORD(density));
    }
    else
    {
      v1 = ((double (*)(void))physenv->GetAirDensity)();
      _Msg(a1: "air_density <value>\nCurrent air density is %.2f\n", v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101866D0
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
// Address: 0x10186780
// Name: WheelCollidesWith
// Source: json
//------------------------------------------------------------------------------
bool __usercall WheelCollidesWith@<al>(IPhysicsObject *pObj@<ecx>, CBaseEntity *pEntity@<eax>)
{
  bool result; // al
  unsigned __int8 m_Value; // al

  result = false;
  if ( pEntity->m_CollisionGroup.m_Value != 3 )
  {
    m_Value = pEntity->m_MoveType.m_Value;
    if ( m_Value == 7 || m_Value == 6 || pObj->IsStatic(this: pObj) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101867B0
// Name: public: virtual int CCollisionEvent::ShouldCollide(class IPhysicsObject __near *,class IPhysicsObject __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::ShouldCollide(
        CCollisionEvent *this,
        IPhysicsObject *pObj0,
        IPhysicsObject *pObj1,
        CBaseEntity *pGameData0,
        CBaseEntity *pGameData1)
{
  unsigned __int16 v8; // ax
  int result; // eax
  IPhysics_vtbl *v10; // edi
  int v11; // eax
  IPhysicsCollisionSet *v12; // esi
  IPhysicsCollisionSet_vtbl *v13; // edi
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  CBaseEntity *RootMoveParent; // ebx
  IPhysicsObject *m_pPhysicsObject; // ebx
  unsigned __int8 SolidFlags; // al
  int m_Value; // ecx
  int v20; // eax
  bool v21; // bl
  CCollisionEvent *v22; // eax
  unsigned int v23; // ebx
  unsigned int v24; // ebx
  bool v25; // zf
  unsigned __int8 nSolidFlags0; // [esp+Ch] [ebp-18h]
  SolidType_t solid1; // [esp+10h] [ebp-14h]
  SolidType_t solid0; // [esp+14h] [ebp-10h]
  unsigned __int8 nSolidFlags1; // [esp+18h] [ebp-Ch]
  int movetype0; // [esp+1Ch] [ebp-8h]
  unsigned __int16 pParent1; // [esp+34h] [ebp+10h]
  CBaseEntity *pParent1a; // [esp+34h] [ebp+10h]
  char pParent1_3; // [esp+37h] [ebp+13h]
  int movetype1; // [esp+38h] [ebp+14h]

  ++this->m_removeObjects.m_pElements;
  if ( pGameData0 != nullptr && pGameData1 != nullptr )
  {
    pParent1 = pObj0->GetGameFlags(this: pObj0);
    v8 = pObj1->GetGameFlags(this: pObj1);
    if ( pGameData0 == pGameData1 )
    {
      if ( ((pParent1 | v8) & 0x8000) != 0 )
      {
LABEL_5:
        --this->m_removeObjects.m_pElements;
        return 0;
      }
      v10 = physics->__vftable;
      v11 = pGameData0->GetModelIndex(this: pGameData0);
      v12 = v10->FindCollisionSet(this: physics, a2: v11);
      if ( v12 != nullptr )
      {
        v13 = v12->__vftable;
        v14 = pObj1->GetGameIndex(this: pObj1);
        v15 = ((int (__thiscall *)(IPhysicsObject *, _DWORD))pObj0->GetGameIndex)(a1: pObj0, a2: v14);
        LOBYTE(result) = ((int (__thiscall *)(IPhysicsCollisionSet *, _DWORD))v13->ShouldCollide)(a1: v12, a2: v15);
        --this->m_removeObjects.m_pElements;
        return (unsigned __int8)result;
      }
      goto LABEL_8;
    }
    if ( ((unsigned __int8)pParent1 & (unsigned __int8)v8 & 2) != 0
      || (((int (__thiscall *)(IPhysicsObject *))pObj0->GetCallbackFlags)(a1: pObj0) & 0x40) != 0
      && !WheelCollidesWith(pObj: pObj1, pEntity: pGameData1)
      || (((int (__thiscall *)(IPhysicsObject *))pObj1->GetCallbackFlags)(a1: pObj1) & 0x40) != 0
      && !WheelCollidesWith(pObj: pObj0, pEntity: pGameData0) )
    {
      goto LABEL_5;
    }
    if ( pGameData0->ForceVPhysicsCollide(this: pGameData0, a2: pGameData1)
      || pGameData1->ForceVPhysicsCollide(this: pGameData1, a2: pGameData0) )
    {
LABEL_8:
      --this->m_removeObjects.m_pElements;
      return 1;
    }
    if ( pGameData0->m_Network.m_pPev != nullptr
      && pGameData1->m_Network.m_pPev != nullptr
      && (CBaseEntity::GetOwnerEntity(this: pGameData0) == pGameData1
       || CBaseEntity::GetOwnerEntity(this: pGameData1) == pGameData0) )
    {
      goto LABEL_5;
    }
    if ( CBaseEntity::GetMoveParent(this: pGameData0) != nullptr
      || CBaseEntity::GetMoveParent(this: pGameData1) != nullptr )
    {
      RootMoveParent = CBaseEntity::GetRootMoveParent(this: pGameData0);
      pParent1a = CBaseEntity::GetRootMoveParent(this: pGameData1);
      if ( RootMoveParent == pParent1a )
        goto LABEL_23;
      if ( g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: RootMoveParent, a3: pParent1a) )
        goto LABEL_23;
      m_pPhysicsObject = RootMoveParent->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr
        && pParent1a->m_pPhysicsObject != nullptr
        && g_EntityCollisionHash->IsObjectPairInHash(
             this: g_EntityCollisionHash,
             a2: m_pPhysicsObject,
             a3: pParent1a->m_pPhysicsObject) )
      {
        goto LABEL_23;
      }
    }
    solid0 = CBaseEntity::GetSolid(this: pGameData0);
    solid1 = CBaseEntity::GetSolid(this: pGameData1);
    nSolidFlags0 = CBaseEntity::GetSolidFlags(this: pGameData0);
    SolidFlags = CBaseEntity::GetSolidFlags(this: pGameData1);
    m_Value = pGameData1->m_MoveType.m_Value;
    nSolidFlags1 = SolidFlags;
    v20 = pGameData0->m_MoveType.m_Value;
    movetype0 = v20;
    movetype1 = m_Value;
    if ( v20 == 7 || (pParent1_3 = 0, pGameData0->m_MoveType.m_Value == 0) )
      pParent1_3 = 1;
    v21 = m_Value == 7 || m_Value == 0;
    if ( v20 == 11 && pObj0->GetShadowController(this: pObj0) != nullptr )
      pParent1_3 = 1;
    if ( movetype1 == 11 && pObj1->GetShadowController(this: pObj1) != nullptr )
      v21 = true;
    if ( CBaseEntity::GetMoveParent(this: pGameData0) != nullptr
      && (movetype0 != 6 || CBaseEntity::GetRootMoveParent(this: pGameData0)->m_MoveType.m_Value != 6) )
    {
      pParent1_3 = 1;
    }
    if ( CBaseEntity::GetMoveParent(this: pGameData1) != nullptr
      && (movetype1 != 6 || CBaseEntity::GetRootMoveParent(this: pGameData1)->m_MoveType.m_Value != 6) )
    {
      v21 = true;
    }
    if ( pParent1_3 != 0 && !pObj1->IsMoveable(this: pObj1)
      || v21 && !pObj0->IsMoveable(this: pObj0)
      || pParent1_3 != 0 && v21
      || pObj0->GetShadowController(this: pObj0) != nullptr && pObj1->GetShadowController(this: pObj1) != nullptr
      || solid0 == SOLID_NONE
      || solid1 == SOLID_NONE )
    {
      goto LABEL_23;
    }
    if ( ((nSolidFlags0 | nSolidFlags1) & 4) != 0 )
    {
      if ( pObj0->IsTrigger(this: pObj0) && (nSolidFlags1 & 4) == 0
        || pObj1->IsTrigger(this: pObj1) && (nSolidFlags0 & 4) == 0 )
      {
        v22 = this;
LABEL_63:
        --v22->m_removeObjects.m_pElements;
        return 1;
      }
LABEL_23:
      --this->m_removeObjects.m_pElements;
      return 0;
    }
    if ( (nSolidFlags0 & 8) != 0 && solid1 != SOLID_VPHYSICS && solid1 != SOLID_BSP && movetype1 != 6 )
      goto LABEL_23;
    if ( (nSolidFlags1 & 8) != 0 && solid0 != SOLID_VPHYSICS && solid0 != SOLID_BSP && movetype0 != 6 )
      goto LABEL_23;
    if ( !g_pGameRules->ShouldCollide(
            this: g_pGameRules,
            a2: pGameData0->m_CollisionGroup.m_Value,
            a3: pGameData1->m_CollisionGroup.m_Value) )
      goto LABEL_23;
    v23 = pObj0->GetContents(this: pObj0);
    if ( (v23 & pGameData1->PhysicsSolidMaskForEntity(this: pGameData1)) == 0 )
      goto LABEL_23;
    v24 = pObj1->GetContents(this: pObj1);
    if ( (v24 & pGameData0->PhysicsSolidMaskForEntity(this: pGameData0)) == 0
      || g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: pGameData0, a3: pGameData1) )
    {
      goto LABEL_23;
    }
    v25 = !g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: pObj0, a3: pObj1);
    v22 = this;
    if ( v25 )
      goto LABEL_63;
    --this->m_removeObjects.m_pElements;
    return 0;
  }
  else
  {
    --this->m_removeObjects.m_pElements;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186C50
// Name: ReportPenetration
// Source: json
//------------------------------------------------------------------------------
void __usercall ReportPenetration(CBaseEntity *pEntity@<esi>, float duration)
{
  const char *DebugName; // eax
  const char *v3; // eax

  if ( pEntity->m_MoveType.m_Value == 6 )
  {
    if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue > 1 )
      pEntity->m_debugOverlays |= 0x20u;
    DebugName = CBaseEntity::GetDebugName(this: pEntity);
    v3 = UTIL_VarArgs(format: "VPhysics Penetration Error (%s)!", DebugName);
    CBaseEntity::AddTimedOverlay(this: pEntity, msg: v3, endTime: (int)duration);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186CA0
// Name: CanResolvePenetrationWithNPC
// Source: json
//------------------------------------------------------------------------------
bool __usercall CanResolvePenetrationWithNPC@<al>(CBaseEntity *pEntity@<edi>, IPhysicsObject *pObject@<esi>)
{
  return pEntity->m_MoveType.m_Value == 6
      && !pObject->IsHinged(this: pObject)
      && !pObject->IsAttachedToConstraint(this: pObject, a2: true)
      && (pObject->IsMoveable(this: pObject) || pEntity->GetServerVehicle(this: pEntity) != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10186CF0
// Name: void PhysSolidOverride(struct solid_t __near &,struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysSolidOverride(solid_t *solid, char *overrideScript)
{
  bool enableCollisions; // bl
  const char *i; // esi
  IVPhysicsKeyParser *v4; // esi
  char pDest[4096]; // [esp+0h] [ebp-1104h] BYREF
  char token[256]; // [esp+1000h] [ebp-104h] BYREF
  void **v7; // [esp+1100h] [ebp-4h] BYREF

  if ( overrideScript != nullptr )
  {
    enableCollisions = solid->params.enableCollisions;
    V_strncpy(pDest, pSrc: "solid { ", maxLen: 4096);
    for ( i = nexttoken(token, str: overrideScript, sep: 44); token[0] != 0; i = nexttoken(token, str: i, sep: 44) )
    {
      V_strncat(pDest, pSrc: "\"", destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: token, destBufferSize: 0x1000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: "\" ", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    }
    V_strncat(pDest, pSrc: "}", destBufferSize: 0x1000u, max_chars_to_copy: -1);
    v4 = physcollision->VPhysicsKeyParserCreate_2(this: physcollision, a2: pDest);
    v7 = &CSkipKeys::`vftable';
    v4->ParseSolid(this: v4, a2: solid, a3: (IVPhysicsKeyHandler *)&v7);
    physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v4);
    solid->params.enableCollisions = enableCollisions;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10186E30
// Name: CallbackReport
// Source: json
//------------------------------------------------------------------------------
void __cdecl CallbackReport(CBaseEntity *pEntity)
{
  CBaseEntity *v1; // esi
  const char *pszValue; // edi
  const char *v3; // esi

  v1 = pEntity;
  pszValue = pEntity->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_strlen(str: pszValue) == 0 )
  {
    pszValue = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))v1->GetModelName)(
                                 a1: v1,
                                 a2: &pEntity);
    if ( pszValue == nullptr )
      pszValue = locale;
  }
  v3 = v1->m_iClassname.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  _Msg(a1: "%s - %s\n", v3, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x10186E90
// Name: physics_report_active
// Source: json
//------------------------------------------------------------------------------
void __cdecl physics_report_active()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    IterateActivePhysicsEntities(func: CallbackReport);
}

//------------------------------------------------------------------------------
// Address: 0x10186EB0
// Name: surfaceprop
// Source: json
//------------------------------------------------------------------------------
void __usercall surfaceprop(IHandleEntity_vtbl *a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v5; // eax
  Vector *(__thiscall *v6)(CBaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  IVModelInfo_vtbl *v8; // esi
  int v9; // eax
  const struct model_t *v10; // esi
  ICollideable *v11; // eax
  const char *v12; // edi
  bool v13; // zf
  const char *v14; // eax
  const char *v15; // eax
  __int128 v16; // xmm0
  const char *v17; // eax
  const char *v18; // [esp-2Ch] [ebp-1ECh]
  const char *v19; // [esp-28h] [ebp-1E8h]
  const char *v20; // [esp-24h] [ebp-1E4h]
  const char *v21; // [esp-20h] [ebp-1E0h]
  void **v23; // [esp-Ch] [ebp-1CCh] BYREF
  __int16 v24; // [esp-8h] [ebp-1C8h] BYREF
  CFmtStrN<256> modelStuff; // [esp+0h] [ebp-1C0h] BYREF
  __int128 v26; // [esp+114h] [ebp-ACh] BYREF
  float v27[3]; // [esp+12Ch] [ebp-94h] BYREF
  CGameTrace tr; // [esp+138h] [ebp-88h] BYREF
  Vector v29; // [esp+18Ch] [ebp-34h] BYREF
  Vector forward; // [esp+198h] [ebp-28h] BYREF
  float v31; // [esp+1A4h] [ebp-1Ch]
  float v32; // [esp+1A8h] [ebp-18h]
  float v33; // [esp+1ACh] [ebp-14h]
  const char *v34; // [esp+1B0h] [ebp-10h]
  IHandleEntity v35[2]; // [esp+1B4h] [ebp-Ch] BYREF
  IHandleEntity_vtbl *retaddr; // [esp+1C0h] [ebp+0h]

  v35[0].__vftable = a1;
  v35[1].__vftable = retaddr;
  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    CommandClient = UTIL_GetCommandClient();
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &v29, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v31 = v29.x * 16384.0;
    v32 = v29.y * 16384.0;
    v33 = v29.z * 16384.0;
    v5 = (float *)((int (__thiscall *)(CBasePlayer *, int *, int))EyePosition)(
                    a1: CommandClient,
                    a2: &modelStuff.m_nLength,
                    a3: a2);
    v6 = CommandClient->EyePosition;
    forward.x = v31 + *v5;
    forward.y = v5[1] + v32;
    forward.z = v5[2] + v33;
    v7 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v6)(a1: CommandClient);
    UTIL_TraceLine(
      a1: v35,
      a2: (int)CommandClient,
      vecAbsStart: v7,
      vecAbsEnd: (const Vector *)((char *)&v26 + 4),
      mask: (unsigned int)&forward,
      ignore: (const IHandleEntity *)0x600400B,
      collisionGroup: (int)CommandClient,
      ptr: nullptr);
    if ( tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
    {
      v8 = modelinfo->__vftable;
      v9 = (*(int (__thiscall **)(_DWORD, float *))(**(_DWORD **)&tr.surface.surfaceProps + 24))(
             a1: *(_DWORD *)&tr.surface.surfaceProps,
             a2: v27);
      v10 = v8->GetModel(this: modelinfo, a2: v9);
      v34 = *(const char **)(*(int (__thiscall **)(_DWORD, int *))(**(_DWORD **)&tr.surface.surfaceProps + 28))(
                              a1: *(_DWORD *)&tr.surface.surfaceProps,
                              a2: &tr.hitbox);
      if ( v34 == nullptr )
        v34 = locale;
      if ( CGameTrace::DidHitWorld(this: (CGameTrace *)v27) && tr.hitgroup > 0 )
      {
        v11 = staticpropmgr->GetStaticPropByIndex(this: staticpropmgr, a2: tr.hitgroup - 1);
        v10 = v11->GetCollisionModel(this: v11);
        v34 = modelinfo->GetModelName(this: modelinfo, a2: v10);
      }
      v23 = &CFmtStrN<256>::`vftable';
      v24 = 1;
      *(_DWORD *)&modelStuff.m_szBuf[247] = 0;
      if ( v10 != nullptr )
      {
        v12 = "  Two-pass.";
        if ( ((unsigned __int8 (__thiscall *)(IVModelInfo *, const struct model_t *, int))modelinfo->IsTranslucentTwoPass)(
               a1: modelinfo,
               a2: v10,
               a3) == 0 )
          v12 = locale;
        v13 = ((unsigned __int8 (__thiscall *)(IVModelInfo *))modelinfo->IsTranslucent)(a1: modelinfo) == 0;
        v14 = "Translucent";
        if ( v13 )
          v14 = "Opaque";
        CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: (CFmtStrN<256> *)&v23, pszFormat: "%s.%s ", v14, v12);
      }
      v15 = *(const char **)(*(_DWORD *)&tr.surface.surfaceProps + 92);
      v16 = 0;
      *(float *)&v16 = fsqrt(
                         (float)((float)((float)(v27[1] - tr.startpos.y) * (float)(v27[1] - tr.startpos.y))
                               + (float)((float)(v27[2] - tr.startpos.z) * (float)(v27[2] - tr.startpos.z)))
                       + (float)((float)(v27[0] - tr.startpos.x) * (float)(v27[0] - tr.startpos.x)));
      v26 = v16;
      if ( v15 == nullptr )
        v15 = locale;
      v17 = (const char *)((int (__thiscall *)(IPhysicsSurfaceProps *, _DWORD, const char *, const char *, char *, int))physprops->GetPropName)(
                            a1: physprops,
                            a2: (__int16)tr.dispFlags,
                            a3: v15,
                            a4: v34,
                            a5: (char *)&v24 + 1,
                            a6: tr.contents);
      _Msg(a1: "Hit surface \"%s\" (entity %s, model \"%s\" %s), texture \"%s\"\n", v17, v18, v19, v20, v21);
      _Msg(a1: "Distance to surface: %d\n", (int)*(float *)&v16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187140
// Name: void PhysicsCommand(class CCommand const __near &,void (*)(class CBaseEntity __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsCommand(const CCommand *args, void (__cdecl *func)())
{
  CBasePlayer *CommandClient; // esi
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v4; // eax
  Vector *(__thiscall *v5)(CBaseEntity *, Vector *); // edx
  const Vector *v6; // eax
  const char *v7; // eax
  CBasePlayer *i; // esi
  const char *v9; // eax
  float tr_44; // [esp+34h] [ebp-64h]
  char tr_54; // [esp+3Eh] [ebp-5Ah]
  char tr_55; // [esp+3Fh] [ebp-59h]
  Vector vecAbsEnd; // [esp+5Ch] [ebp-3Ch] BYREF
  Vector v14; // [esp+68h] [ebp-30h] BYREF
  Vector forward; // [esp+74h] [ebp-24h] BYREF
  unsigned int mask[3]; // [esp+80h] [ebp-18h] BYREF
  float v17; // [esp+8Ch] [ebp-Ch]
  float v18; // [esp+90h] [ebp-8h]
  float v19; // [esp+94h] [ebp-4h]
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    v7 = CCommand::operator[](this: args, nIndex: 1);
    for ( i = CGlobalEntityList::FindEntityGeneric(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: v7,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr);
          i != nullptr;
          i = CGlobalEntityList::FindEntityGeneric(
                this: &gEntList,
                pStartEntity: i,
                szName: v9,
                pSearchingEntity: nullptr,
                pActivator: nullptr,
                pCaller: nullptr) )
    {
      ((void (__cdecl *)(CBasePlayer *))func)(a1: i);
      v9 = CCommand::operator[](this: args, nIndex: 1);
    }
  }
  else
  {
    CommandClient = UTIL_GetCommandClient();
    CBasePlayer::EyeVectors(this: CommandClient, pForward: &forward, pRight: nullptr, pUp: nullptr);
    EyePosition = CommandClient->EyePosition;
    v17 = forward.x * 16384.0;
    v18 = forward.y * 16384.0;
    v19 = forward.z * 16384.0;
    v4 = (float *)EyePosition(this: CommandClient, result: &v14);
    v5 = CommandClient->EyePosition;
    *(float *)mask = *v4 + v17;
    *(float *)&mask[1] = v4[1] + v18;
    *(float *)&mask[2] = v4[2] + v19;
    v6 = (const Vector *)((int (__thiscall *)(CBasePlayer *))v5)(a1: CommandClient);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)CommandClient,
      vecAbsStart: v6,
      &vecAbsEnd,
      (unsigned int)mask,
      ignore: (const IHandleEntity *)0x600400B,
      collisionGroup: (int)CommandClient,
      ptr: nullptr);
    if ( tr_44 < 1.0 || tr_54 != 0 || tr_55 != 0 )
      func();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187290
// Name: physics_select
// Source: json
//------------------------------------------------------------------------------
void __cdecl physics_select(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    PhysicsCommand(args, func: (void (__cdecl *)())MarkVPhysicsDebug);
}

//------------------------------------------------------------------------------
// Address: 0x101872B0
// Name: private: void CCollisionEvent::DispatchStartTouch(class CBaseEntity __near *,class CBaseEntity __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::DispatchStartTouch(
        CCollisionEvent *this,
        CBaseEntity *pEntity0,
        CBaseEntity *pEntity1,
        const Vector *point,
        const Vector *normal)
{
  float x; // xmm0_4
  float z; // xmm2_4
  float y; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  CGameTrace trace; // [esp+0h] [ebp-54h] BYREF

  memset(dst: (int)&trace, value: nullptr, count: sizeof(trace));
  x = point->x;
  z = point->z;
  y = normal->y;
  v8 = normal->x;
  v9 = normal->z;
  trace.endpos.y = point->y;
  trace.endpos.x = x;
  trace.endpos.z = z;
  trace.plane.dist = (float)((float)(y * trace.endpos.y) + (float)(v8 * x)) + (float)(v9 * z);
  trace.plane.normal.x = v8;
  trace.plane.normal.y = y;
  trace.plane.normal.z = v9;
  CBaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(this: pEntity0, other: pEntity1, &trace);
}

//------------------------------------------------------------------------------
// Address: 0x10187340
// Name: private: void CCollisionEvent::RestoreDamageInflictorState(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::RestoreDamageInflictorState(
        CCollisionEvent *this,
        int inflictorStateIndex,
        float velocityBlend)
{
  inflictorstate_t *i; // esi
  float y; // xmm3_4
  float z; // xmm4_4
  float v7; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  __int16 nextIndex; // ax
  Vector angVel; // [esp+8h] [ebp-18h] BYREF
  Vector velocity; // [esp+14h] [ebp-Ch] BYREF

  for ( i = &this->m_damageInflictors.m_Memory.m_pMemory[inflictorStateIndex];
        i->restored == 0;
        i = &this->m_damageInflictors.m_Memory.m_pMemory[nextIndex] )
  {
    i->restored = 1;
    if ( velocityBlend > 0.0 )
    {
      i->pInflictorPhysics->GetVelocity(this: i->pInflictorPhysics, a2: &velocity, a3: &angVel);
      y = i->savedVelocity.y;
      z = i->savedVelocity.z;
      v7 = (float)(1.0 - velocityBlend) * velocity.z;
      v8 = (float)(1.0 - velocityBlend) * velocity.y;
      i->savedVelocity.x = (float)(i->savedVelocity.x * velocityBlend)
                         + (float)((float)(1.0 - velocityBlend) * velocity.x);
      i->savedVelocity.z = (float)(z * velocityBlend) + v7;
      i->savedVelocity.y = (float)(y * velocityBlend) + v8;
      v9 = (float)(i->savedAngularVelocity.y * velocityBlend) + (float)((float)(1.0 - velocityBlend) * angVel.y);
      v10 = (float)(i->savedAngularVelocity.z * velocityBlend) + (float)((float)(1.0 - velocityBlend) * angVel.z);
      i->savedAngularVelocity.x = (float)(velocityBlend * i->savedAngularVelocity.x)
                                + (float)((float)(1.0 - velocityBlend) * angVel.x);
      i->savedAngularVelocity.y = v9;
      i->savedAngularVelocity.z = v10;
      i->pInflictorPhysics->SetVelocity(this: i->pInflictorPhysics, a2: &i->savedVelocity, a3: &i->savedAngularVelocity);
    }
    nextIndex = i->nextIndex;
    if ( nextIndex < 0 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10187490
// Name: class IPhysicsObject __near * FindPhysicsObjectByName(char const __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl FindPhysicsObjectByName(const char *pName, CBaseEntity *pErrorEntity)
{
  CBasePlayer *EntityByName; // esi
  const char *pszValue; // ebx
  Vector *AbsOrigin; // eax
  __int64 v7; // xmm0_8
  float z; // eax
  CFmtStrN<256> *v9; // eax
  CBasePlayer *i; // esi
  const char *v11; // eax
  __int64 v12; // [esp+8h] [ebp-134h]
  CFmtStrN<256> v13; // [esp+24h] [ebp-118h] BYREF
  Vector origin; // [esp+130h] [ebp-Ch]
  IPhysicsObject *pBestObject; // [esp+144h] [ebp+8h]

  if ( pName == nullptr || strlen(pName) == 0 )
    return nullptr;
  v12 = (unsigned int)pName;
  pBestObject = nullptr;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: (const char *)v12,
                   pSearchingEntity: (CBaseEntity *)HIDWORD(v12),
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return pBestObject;
  while ( EntityByName->m_pPhysicsObject == nullptr )
  {
LABEL_7:
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: pName,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      return pBestObject;
  }
  if ( pBestObject == nullptr )
  {
    pBestObject = EntityByName->m_pPhysicsObject;
    goto LABEL_7;
  }
  if ( pErrorEntity != nullptr )
  {
    pszValue = pErrorEntity->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    AbsOrigin = CBaseEntity::GetAbsOrigin(this: pErrorEntity);
  }
  else
  {
    pszValue = "Unknown";
    AbsOrigin = &vec3_origin;
  }
  v7 = *(_QWORD *)&AbsOrigin->x;
  z = AbsOrigin->z;
  *(_QWORD *)&origin.x = v7;
  origin.z = z;
  v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "(%f, %f, %f)", *(float *)&v7, *((float *)&v7 + 1), z);
  DevWarning(
    a1: "entity %s at %s has physics attachment to more than one entity with the name %s!!!\n",
    pszValue,
    v9->m_szBuf,
    pName);
  for ( i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: EntityByName,
              szName: pName,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
        i != nullptr;
        i = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: i,
              szName: pName,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr) )
  {
    v11 = i->m_iClassname.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    DevWarning(a1: "Found %s\n", v11);
  }
  return pBestObject;
}

//------------------------------------------------------------------------------
// Address: 0x10187610
// Name: void DebugDrawContactPoints(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugDrawContactPoints(IPhysicsObject *pPhysics)
{
  IPhysicsObject *v1; // edi
  IPhysicsFrictionSnapshot *v2; // esi
  int v3; // eax
  CBaseEntity *v4; // edi
  const char *pszValue; // ebx
  const char *DebugName; // eax
  double v7; // [esp+10h] [ebp-164h]
  CFmtStrN<256> str; // [esp+24h] [ebp-150h] BYREF
  _BYTE v9[4]; // [esp+130h] [ebp-44h] BYREF
  Vector mins; // [esp+134h] [ebp-40h] BYREF
  Vector target; // [esp+140h] [ebp-34h] BYREF
  Vector normal; // [esp+14Ch] [ebp-28h] BYREF
  Vector maxs; // [esp+158h] [ebp-1Ch] BYREF
  Vector pt; // [esp+164h] [ebp-10h] BYREF
  const char *v15; // [esp+170h] [ebp-4h]
  int savedregs; // [esp+174h] [ebp+0h] BYREF

  v1 = pPhysics;
  v2 = pPhysics->CreateFrictionSnapshot(this: pPhysics);
  if ( v2->IsValid(this: v2) )
  {
    do
    {
      v2->GetContactPoint(this: v2, a2: &pt);
      v2->GetSurfaceNormal(this: v2, a2: &normal);
      maxs.x = 1.0;
      maxs.y = 1.0;
      maxs.z = 1.0;
      mins.x = -1.0;
      mins.y = -1.0;
      mins.z = -1.0;
      NDebugOverlay::Box(origin: &pt, &mins, &maxs, r: 0, g: 255, b: 0, a: 32, flDuration: 0.0);
      target.y = pt.y - (float)(normal.y * 20.0);
      target.z = pt.z - (float)(normal.z * 20.0);
      target.x = pt.x - (float)(normal.x * 20.0);
      NDebugOverlay::Line(origin: &pt, &target, r: 0, g: 255, b: 0, noDepthTest: 0, duration: 0.0);
      v3 = (int)v2->GetObject(this: v2, a2: 1);
      v4 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(a1: v3);
      v15 = *(const char **)((int (__thiscall *)(CBaseEntity *, _BYTE *))v4->GetModelName)(a1: v4, a2: v9);
      if ( v15 == nullptr )
        v15 = locale;
      pszValue = v4->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v7 = ((double (__thiscall *)(IPhysicsFrictionSnapshot *))v2->GetFrictionCoefficient)(a1: v2);
      DebugName = CBaseEntity::GetDebugName(this: v4);
      CFmtStrN<256>::CFmtStrN<256>(this: &str, pszFormat: "%s (%s): %s [%0.2f]", pszValue, v15, DebugName, v7);
      NDebugOverlay::Text(
        a1: COERCE_FLOAT(&savedregs),
        origin: &pt,
        text: str.m_szBuf,
        bViewCheck: false,
        duration: 0.0);
      v2->NextFrictionData(this: v2);
    }
    while ( v2->IsValid(this: v2) );
    v1 = pPhysics;
  }
  v2->DeleteAllMarkedContacts(this: v2, a2: true);
  v1->DestroyFrictionSnapshot(this: v1, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101877F0
// Name: public: CTSQueue<class CFunctor __near *,0,1>::CTSQueue<class CFunctor __near *,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1> *__thiscall CTSQueue<CFunctor *,0,1>::CTSQueue<CFunctor *,0,1>(CTSQueue<CFunctor *,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // eax
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+0h] [ebp-Ch]

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10458314, a2: v5);
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1049AE60, a2: v5);
    __debugbreak();
    _Error(this: (ISceneTokenProcessor *)&stru_1049AE60, a2: v6);
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<CFunctor *,0,1>::Node_t *)operator new(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10187880
// Name: public: struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near * CTSQueue<class CFunctor __near *,0,1>::Push(struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1>::Node_t *__thiscall CTSQueue<CFunctor *,0,1>::Push(
        CTSQueue<CFunctor *,0,1> *this,
        CTSQueue<CFunctor *,0,1>::Node_t *pNode)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // edi
  int i; // [esp-4h] [ebp-10h]

  pNode->pNext = (CTSQueue<CFunctor *,0,1>::Node_t *)this;
  v3 = this->m_Tail.value.pNode;
  for ( i = this->m_Tail.value.sequence;
        (CTSQueue<CFunctor *,0,1> *)_InterlockedCompareExchange(
                                      (volatile signed __int32 *)v3,
                                      (signed __int32)pNode,
                                      (signed __int32)this) != this;
        i = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: v3->pNext, a3: i + 1, a4: v3, a5: i);
    v3 = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: i + 1, a4: v3, a5: i);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10187930
// Name: public: struct CTSQueue<class CFunctor __near *,0,1>::Node_t __near * CTSQueue<class CFunctor __near *,0,1>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<CFunctor *,0,1>::Node_t *__thiscall CTSQueue<CFunctor *,0,1>::Pop(CTSQueue<CFunctor *,0,1> *this)
{
  CTSQueue<CFunctor *,0,1> *v1; // esi
  CTSQueue<CFunctor *,0,1> *pNext; // eax
  CFunctor *sequence; // edi
  CTSQueue<CFunctor *,0,1>::Node_t *pNode; // [esp-Ch] [ebp-2Ch]
  CTSQueue<CFunctor *,0,1>::NodeLink_t *head_4; // [esp+4h] [ebp-1Ch]
  int *pHead; // [esp+Ch] [ebp-14h]
  CTSQueue<CFunctor *,0,1>::NodeLink_t *pTailNode; // [esp+10h] [ebp-10h]

  v1 = this;
  pTailNode = &this->m_Tail;
  pHead = &this->m_Head.value.sequence;
  head_4 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<CFunctor *,0,1> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != head_4->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: pTailNode->value.sequence + 1,
          a4: pNode,
          a5: pTailNode->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (CFunctor *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNext, a3: *pHead + 1, a4: pNode, a5: *pHead) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x10187BC0
// Name: public: virtual void CFunctor4<class CBaseEntity __near * (*)(class CBaseEntity __near *,class CBaseEntity __near *,bool,float),class CBaseEntity __near *,class CBaseEntity __near *,bool,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor4<CBaseEntity * (__cdecl *)(CBaseEntity *,CBaseEntity *,bool,float),CBaseEntity *,CBaseEntity *,bool,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor4<CBaseEntity * (__cdecl*)(CBaseEntity *,CBaseEntity *,bool,float),CBaseEntity *,CBaseEntity *,bool,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(CBaseEntity *, CBaseEntity *, bool, _DWORD))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: this->m_arg3,
    a4: LODWORD(this->m_arg4));
}

//------------------------------------------------------------------------------
// Address: 0x10187BF0
// Name: public: virtual void CFunctor3<void (*)(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &),class IPhysicsObject __near *,class Vector,class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor3<void (__cdecl *)(IPhysicsObject *,Vector const &,Vector const &),IPhysicsObject *,Vector,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor3<void (__cdecl*)(IPhysicsObject *,Vector const &,Vector const &),IPhysicsObject *,Vector,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: &this->m_arg2, a3: &this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10187E00
// Name: private: void CCollisionEvent::UpdatePenetrateEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdatePenetrateEvents(CCollisionEvent *this)
{
  CCollisionEvent *v1; // ebx
  int v2; // eax
  int v3; // edx
  char *v4; // edx
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v7; // eax
  CBaseEntity *v8; // esi
  int v9; // eax
  CAI_BaseNPC *v10; // eax
  CBaseEntity *v11; // ecx
  int m_Size; // eax
  penetrateevent_t *m_pMemory; // ecx
  int v14; // eax
  __int64 v15; // xmm0_8
  int v16; // eax
  int i; // [esp+10h] [ebp-10h]
  CBaseEntity *pEntity0; // [esp+14h] [ebp-Ch]
  int j; // [esp+18h] [ebp-8h]

  v1 = this;
  v2 = this->m_penetrateEvents.m_Size - 1;
  i = v2;
  if ( v2 >= 0 )
  {
    v3 = 20 * v2;
    for ( j = v2; ; v3 = j * 20 )
    {
      v4 = (char *)v1->m_penetrateEvents.m_Memory.m_pMemory + v3;
      v5 = *(_DWORD *)v4;
      if ( *(_DWORD *)v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      v7 = *((_DWORD *)v4 + 1);
      pEntity0 = m_pEntity;
      if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        v8 = nullptr;
      else
        v8 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      v9 = *((_DWORD *)v4 + 4);
      if ( v9 == 1 )
      {
        if ( m_pEntity != nullptr && v8 != nullptr )
        {
          if ( m_pEntity->m_pPhysicsObject != nullptr )
            PhysForceEntityToSleep(pEntity: m_pEntity, pObject: m_pEntity->m_pPhysicsObject);
          if ( v8->m_pPhysicsObject != nullptr )
            PhysForceEntityToSleep(pEntity: v8, pObject: v8->m_pPhysicsObject);
          v1->m_penetrateEvents.m_Memory.m_pMemory[j].collisionState = 4;
          goto LABEL_47;
        }
      }
      else
      {
        if ( v9 == 2 )
        {
          if ( m_pEntity == nullptr || v8 == nullptr )
            goto LABEL_27;
          v10 = m_pEntity->MyNPCPointer(this: m_pEntity);
          v11 = v8;
          if ( v10 == nullptr )
          {
            v10 = v8->MyNPCPointer(this: v8);
            v11 = m_pEntity;
          }
          NPCPhysics_CreateSolver(pNPC: v10, pPhysicsObject: v11, disableCollisions: true, separationDuration: 1.0);
        }
        else
        {
          if ( v9 == 3 )
          {
            if ( m_pEntity != nullptr && v8 != nullptr )
            {
              if ( (unsigned int)(v8->m_CollisionGroup.m_Value - 1) > 2 || v8->m_MoveType.m_Value != 6 )
              {
                pEntity0 = v8;
                v8 = m_pEntity;
              }
              EntityPhysics_CreateSolver(
                pMovingEntity: pEntity0,
                pPhysicsObject: v8,
                disableCollisions: true,
                separationDuration: 1.0);
            }
            goto LABEL_27;
          }
          if ( (float)(gpGlobals->curtime - *((float *)v4 + 3)) <= 1.0 )
            goto LABEL_46;
          if ( v9 == 4
            && m_pEntity != nullptr
            && v8 != nullptr
            && m_pEntity->m_pPhysicsObject != nullptr
            && v8->m_pPhysicsObject != nullptr )
          {
            *((_DWORD *)v4 + 4) = 0;
LABEL_46:
            v1 = this;
            goto LABEL_47;
          }
        }
        v1 = this;
      }
LABEL_27:
      m_Size = v1->m_penetrateEvents.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
        {
          m_pMemory = v1->m_penetrateEvents.m_Memory.m_pMemory;
          v14 = m_Size;
          v15 = *(_QWORD *)&m_pMemory[v14 - 1].hEntity0.m_Index;
          v16 = (int)&m_pMemory[v14 - 1];
          *(_QWORD *)&m_pMemory[j].hEntity0.m_Index = v15;
          *(_QWORD *)&m_pMemory[j].startTime = *(_QWORD *)(v16 + 8);
          m_pMemory[j].collisionState = *(_DWORD *)(v16 + 16);
        }
        --v1->m_penetrateEvents.m_Size;
      }
      UpdateEntityPenetrationFlag(pEntity: pEntity0, a2: (int)v8, isPenetrating: false);
      UpdateEntityPenetrationFlag(pEntity: v8, a2: (int)v8, isPenetrating: false);
LABEL_47:
      --j;
      if ( --i < 0 )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188050
// Name: void PhysGetMassCenterOverride(class CBaseEntity __near *,struct vcollide_t __near *,struct solid_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhysGetMassCenterOverride(
        float a1@<ebp>,
        CBaseEntity *pEntity,
        vcollide_t *pCollide,
        solid_t *solidOut)
{
  const char *pszValue; // edi
  int m_Size; // ecx
  float v6; // eax
  string_t *i; // edx
  float v8; // edi
  masscenteroverride_t *v9; // esi
  int alignType; // edx
  CBaseEntity *v11; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  int m_iEFlags; // eax
  float v16; // xmm0_4
  CBaseEntity *v17; // ecx
  __int64 v18; // xmm0_8
  masscenteroverride_t *v19; // eax
  masscenteroverride_t *v20; // ecx
  __int128 v21; // xmm0
  __int128 v22; // [esp-10h] [ebp-3Ch] BYREF
  Vector massCenterLocal; // [esp+0h] [ebp-2Ch] BYREF
  Vector defaultMassCenterWS; // [esp+Ch] [ebp-20h] BYREF
  Vector massCenterWS; // [esp+18h] [ebp-14h] BYREF
  void *v26; // [esp+24h] [ebp-8h]
  void *retaddr; // [esp+2Ch] [ebp+0h]

  massCenterWS.z = a1;
  v26 = retaddr;
  pszValue = pEntity->m_iName.m_Value.pszValue;
  if ( pszValue != nullptr )
  {
    m_Size = g_PhysicsHook.m_massCenterOverrides.m_Size;
    if ( g_PhysicsHook.m_massCenterOverrides.m_Size != 0 )
    {
      v6 = 0.0;
      if ( g_PhysicsHook.m_massCenterOverrides.m_Size > 0 )
      {
        for ( i = &g_PhysicsHook.m_massCenterOverrides.m_Memory.m_pMemory->entityName; i->pszValue != pszValue; i += 8 )
        {
          ++LODWORD(v6);
          if ( SLODWORD(v6) >= g_PhysicsHook.m_massCenterOverrides.m_Size )
            return;
        }
        massCenterWS.y = v6;
        if ( v6 >= 0.0 )
        {
          LODWORD(v8) = 32 * LODWORD(v6);
          v9 = &g_PhysicsHook.m_massCenterOverrides.m_Memory.m_pMemory[LODWORD(v6)];
          defaultMassCenterWS = v9->center;
          alignType = v9->alignType;
          if ( alignType != 0 )
          {
            if ( alignType != 1 )
            {
LABEL_20:
              if ( m_Size > 0 )
              {
                if ( LODWORD(v6) != m_Size - 1 )
                {
                  v18 = *(_QWORD *)&g_PhysicsHook.m_massCenterOverrides.m_Memory.m_pMemory[m_Size - 1].center.x;
                  v19 = &g_PhysicsHook.m_massCenterOverrides.m_Memory.m_pMemory[m_Size - 1];
                  v20 = (masscenteroverride_t *)((char *)g_PhysicsHook.m_massCenterOverrides.m_Memory.m_pMemory
                                               + LODWORD(v8));
                  *(_QWORD *)&v20->center.x = v18;
                  *(_QWORD *)&v20->center.z = *(_QWORD *)&v19->center.z;
                  *(_QWORD *)&v20->axis.y = *(_QWORD *)&v19->axis.y;
                  *(_QWORD *)&v20->alignType = *(_QWORD *)&v19->alignType;
                  m_Size = g_PhysicsHook.m_massCenterOverrides.m_Size;
                }
                g_PhysicsHook.m_massCenterOverrides.m_Size = m_Size - 1;
              }
              v21 = 0;
              *(float *)&v21 = fsqrt(
                                 (float)((float)(solidOut->massCenterOverride.x * solidOut->massCenterOverride.x)
                                       + (float)(solidOut->massCenterOverride.y * solidOut->massCenterOverride.y))
                               + (float)(solidOut->massCenterOverride.z * solidOut->massCenterOverride.z));
              v22 = v21;
              if ( *(float *)&v21 > 0.03125 )
                solidOut->params.massCenterOverride = &solidOut->massCenterOverride;
              return;
            }
            physcollision->CollideGetMassCenter(
              this: physcollision,
              a2: pCollide->solids[solidOut->index],
              a3: (Vector *)((char *)&v22 + 4));
            v11 = pEntity;
            if ( (pEntity->m_iEFlags & 0x800) != 0 )
            {
              CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&massCenterWS.z);
              v11 = pEntity;
            }
            LODWORD(massCenterWS.x) = &v11->m_rgflCoordinateFrame;
            VectorTransform(in1: (const float *)&v22 + 1, in2: &v11->m_rgflCoordinateFrame, out: &massCenterLocal.x);
            y = v9->axis.y;
            x = v9->axis.x;
            z = v9->axis.z;
            m_iEFlags = pEntity->m_iEFlags;
            v16 = (float)((float)((float)(y * massCenterLocal.y) + (float)(x * massCenterLocal.x))
                        + (float)(z * massCenterLocal.z))
                - (float)((float)((float)(v9->center.y * y) + (float)(v9->center.x * x)) + (float)(v9->center.z * z));
            defaultMassCenterWS.y = defaultMassCenterWS.y + (float)(y * v16);
            defaultMassCenterWS.x = (float)(x * v16) + defaultMassCenterWS.x;
            defaultMassCenterWS.z = defaultMassCenterWS.z + (float)(z * v16);
            if ( (m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&massCenterWS.z);
            VectorITransform(
              in1: &defaultMassCenterWS.x,
              in2: (const matrix3x4_t *)LODWORD(massCenterWS.x),
              out: &solidOut->massCenterOverride.x);
          }
          else
          {
            v17 = pEntity;
            if ( (pEntity->m_iEFlags & 0x800) != 0 )
            {
              CBaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)&massCenterWS.z);
              v17 = pEntity;
            }
            VectorITransform(
              in1: &defaultMassCenterWS.x,
              in2: &v17->m_rgflCoordinateFrame,
              out: &solidOut->massCenterOverride.x);
          }
          v6 = massCenterWS.y;
          m_Size = g_PhysicsHook.m_massCenterOverrides.m_Size;
          goto LABEL_20;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101882F0
// Name: private: void CCollisionEvent::UpdateRemoveObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateRemoveObjects(CCollisionEvent *this)
{
  int v2; // edi

  v2 = 0;
  if ( this->m_removeObjects.m_Size <= 0 )
  {
    this->m_removeObjects.m_Size = 0;
  }
  else
  {
    do
      UTIL_Remove(oldObj: this->m_removeObjects.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_removeObjects.m_Size );
    this->m_removeObjects.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188340
// Name: private: void CCollisionEvent::UpdateFluidEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateFluidEvents(CCollisionEvent *this)
{
  int v1; // eax
  int v2; // edi
  int m_Size; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi

  v1 = this->m_fluidEvents.m_Size - 1;
  if ( v1 >= 0 )
  {
    if ( this->m_fluidEvents.m_Size >= 4 )
    {
      v2 = this->m_fluidEvents.m_Size - 3;
      do
      {
        if ( (float)(gpGlobals->curtime - this->m_fluidEvents.m_Memory.m_pMemory[v1].impactTime) > 2.0 )
        {
          m_Size = this->m_fluidEvents.m_Size;
          if ( m_Size > 0 )
          {
            if ( v1 != m_Size - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1] = this->m_fluidEvents.m_Memory.m_pMemory[m_Size - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(gpGlobals->curtime - this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1].impactTime) > 2.0 )
        {
          v4 = this->m_fluidEvents.m_Size;
          if ( v4 > 0 )
          {
            if ( v2 + 1 != v4 - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1] = this->m_fluidEvents.m_Memory.m_pMemory[v4 - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(gpGlobals->curtime - *((float *)&this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1] - 1)) > 2.0 )
        {
          v5 = this->m_fluidEvents.m_Size;
          if ( v5 > 0 )
          {
            if ( v2 != v5 - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1 - 2] = this->m_fluidEvents.m_Memory.m_pMemory[v5 - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(gpGlobals->curtime - *((float *)&this->m_fluidEvents.m_Memory.m_pMemory[v1 - 2] - 1)) > 2.0 )
        {
          v6 = this->m_fluidEvents.m_Size;
          if ( v6 > 0 )
          {
            if ( v2 - 1 != v6 - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1 - 3] = this->m_fluidEvents.m_Memory.m_pMemory[v6 - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        v1 -= 4;
        v2 -= 4;
      }
      while ( v1 >= 3 );
    }
    for ( ; v1 >= 0; --v1 )
    {
      if ( (float)(gpGlobals->curtime - this->m_fluidEvents.m_Memory.m_pMemory[v1].impactTime) > 2.0 )
      {
        v7 = this->m_fluidEvents.m_Size;
        if ( v7 > 0 )
        {
          if ( v1 != v7 - 1 )
            this->m_fluidEvents.m_Memory.m_pMemory[v1] = this->m_fluidEvents.m_Memory.m_pMemory[v7 - 1];
          --this->m_fluidEvents.m_Size;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188510
// Name: private: void CCollisionEvent::UpdateTouchEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateTouchEvents(CCollisionEvent *this)
{
  touchevent_t *v2; // edi
  float y; // xmm3_4
  float x; // xmm0_4
  float v5; // xmm4_4
  float z; // xmm5_4
  float v7; // xmm2_4
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // ecx
  CBaseEntity *pEntity1; // ebx
  CBaseEntity *pEntity0; // edi
  int v12; // edi
  int j; // ebx
  triggerevent_t *m_pMemory; // eax
  int v15; // ecx
  bool v16; // zf
  CBaseEntity *pTriggerEntity; // ecx
  bool v18; // cl
  CGameTrace dst; // [esp+Ch] [ebp-60h] BYREF
  int i; // [esp+60h] [ebp-Ch]
  unsigned int v21; // [esp+64h] [ebp-8h]
  bool bOldTouchEvents; // [esp+6Bh] [ebp-1h]

  bOldTouchEvents = this->m_bBufferTouchEvents;
  this->m_bBufferTouchEvents = true;
  i = 0;
  if ( this->m_touchEvents.m_Size > 0 )
  {
    v21 = 0;
    do
    {
      v2 = &this->m_touchEvents.m_Memory.m_pMemory[v21 / 0x24];
      if ( v2->touchType != 0 )
      {
        pEntity1 = v2->pEntity1;
        pEntity0 = v2->pEntity0;
        CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: pEntity0, other: pEntity1);
        CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: pEntity1, other: pEntity0);
      }
      else
      {
        memset((int)&dst, value: nullptr, count: sizeof(dst));
        y = v2->normal.y;
        x = v2->endPoint.x;
        v5 = v2->normal.x;
        z = v2->normal.z;
        v7 = v2->endPoint.z;
        v8 = v2->pEntity1;
        v9 = v2->pEntity0;
        dst.endpos.y = v2->endPoint.y;
        dst.endpos.x = x;
        dst.endpos.z = v7;
        dst.plane.dist = (float)((float)(y * dst.endpos.y) + (float)(v5 * x)) + (float)(z * v7);
        dst.plane.normal.x = v5;
        dst.plane.normal.y = y;
        dst.plane.normal.z = z;
        CBaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(this: v9, other: v8, trace: &dst);
      }
      v21 += 36;
      ++i;
    }
    while ( i < this->m_touchEvents.m_Size );
  }
  v12 = 0;
  this->m_touchEvents.m_Size = 0;
  for ( j = 0; j < this->m_triggerEvents.m_Size; ++v12 )
  {
    m_pMemory = this->m_triggerEvents.m_Memory.m_pMemory;
    *(_QWORD *)&this->m_currentTriggerEvent.pTriggerEntity = *(_QWORD *)&m_pMemory[v12].pTriggerEntity;
    *(_QWORD *)&this->m_currentTriggerEvent.pEntity = *(_QWORD *)&m_pMemory[v12].pEntity;
    v15 = *(_DWORD *)&m_pMemory[v12].bStart;
    *(_DWORD *)&this->m_currentTriggerEvent.bStart = v15;
    v16 = (_BYTE)v15 == 0;
    pTriggerEntity = this->m_currentTriggerEvent.pTriggerEntity;
    if ( v16 )
      pTriggerEntity->EndTouch(this: pTriggerEntity, a2: this->m_currentTriggerEvent.pEntity);
    else
      pTriggerEntity->StartTouch(this: pTriggerEntity, a2: this->m_currentTriggerEvent.pEntity);
    ++j;
  }
  v18 = bOldTouchEvents;
  this->m_triggerEvents.m_Size = 0;
  *(_QWORD *)&this->m_currentTriggerEvent.pTriggerEntity = 0;
  *(_QWORD *)&this->m_currentTriggerEvent.pEntity = 0;
  *(_DWORD *)&this->m_currentTriggerEvent.bStart = 0;
  this->m_bBufferTouchEvents = v18;
}

//------------------------------------------------------------------------------
// Address: 0x101886B0
// Name: private: void CCollisionEvent::RestoreDamageInflictorState(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::RestoreDamageInflictorState(CCollisionEvent *this, float pInflictor)
{
  int v3; // esi
  inflictorstate_t *m_pMemory; // ecx
  IPhysicsObject **i; // eax
  inflictorstate_t *v6; // edi
  IPhysicsObject *pInflictorPhysics; // ecx
  float (__thiscall *GetMass)(IPhysicsObject *); // edx
  double v9; // st7
  float otherMassMax; // xmm0_4
  float v11; // xmm1_4
  double v12; // st7
  double v13; // st7
  float minVal; // [esp+20h] [ebp-8h] BYREF
  float inflictorMass; // [esp+24h] [ebp-4h] BYREF

  if ( pInflictor != 0.0 )
  {
    v3 = this->m_damageInflictors.m_Size - 1;
    if ( v3 >= 0 )
    {
      m_pMemory = this->m_damageInflictors.m_Memory.m_pMemory;
      for ( i = &m_pMemory[v3].pInflictorPhysics; *i != (IPhysicsObject *)LODWORD(pInflictor); i -= 9 )
      {
        if ( --v3 < 0 )
          return;
      }
      v6 = &m_pMemory[v3];
      if ( v6->restored == 0 )
      {
        pInflictorPhysics = v6->pInflictorPhysics;
        GetMass = pInflictorPhysics->GetMass;
        pInflictor = 1.0;
        v9 = ((double (__thiscall *)(IPhysicsObject *))GetMass)(a1: pInflictorPhysics);
        inflictorMass = v9;
        if ( v9 < 500.0
          && (((int (__thiscall *)(IPhysicsObject *))v6->pInflictorPhysics->GetGameFlags)(a1: v6->pInflictorPhysics) & 1) == 0 )
        {
          otherMassMax = v6->otherMassMax;
          if ( otherMassMax <= 0.0 )
            otherMassMax = 1.0;
          v11 = inflictorMass / otherMassMax;
          inflictorMass = 10.0;
          pInflictor = v11;
          minVal = 0.1;
          v12 = clamp<float,float,float>(val: &pInflictor, &minVal, maxVal: &inflictorMass);
          pInflictor = v12;
          if ( v12 >= 1.0 )
            v13 = RemapVal(val: pInflictor, A: 1.0, B: 10.0, C: 0.5, D: 1.0);
          else
            v13 = RemapVal(val: pInflictor, A: 0.1, B: 1.0, C: 0.0, D: 0.5);
          pInflictor = v13;
        }
        CCollisionEvent::RestoreDamageInflictorState(this, inflictorStateIndex: v3, velocityBlend: pInflictor);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10188840
// Name: public: void CTSQueue<class CFunctor __near *,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<CFunctor *,0,1>::Purge(CTSQueue<CFunctor *,0,1> *this)
{
  CTSQueue<CFunctor *,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<CFunctor *,0,1>::Pop(this); i != nullptr; i = CTSQueue<CFunctor *,0,1>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10188AA0
// Name: private: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueFunctorInternal(class CFunctor __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CFunctor *pFunctor)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // eax

  if ( this->m_bNoQueue )
  {
    pFunctor->operator()(this: pFunctor);
    pFunctor->Release(this: pFunctor);
  }
  else
  {
    v3 = (CTSQueue<CFunctor *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v3 != nullptr || (v3 = (CTSQueue<CFunctor *,0,1>::Node_t *)operator new(nSize: 8u)) != nullptr )
    {
      v3->elem = pFunctor;
      CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: v3);
    }
    else
    {
      CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189490
// Name: public: void vehiclesounds_t::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vehiclesounds_t::Init(vehiclesounds_t *this)
{
  float *minStateTime; // eax
  int i; // ecx

  this->pGears.m_Size = 0;
  if ( this->pGears.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->pGears.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->pGears.m_Memory.m_pMemory);
      this->pGears.m_Memory.m_pMemory = nullptr;
    }
    this->pGears.m_Memory.m_nAllocationCount = 0;
  }
  this->pGears.m_pElements = this->pGears.m_Memory.m_pMemory;
  this->crashSounds.m_Size = 0;
  if ( this->crashSounds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->crashSounds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->crashSounds.m_Memory.m_pMemory);
      this->crashSounds.m_Memory.m_pMemory = nullptr;
    }
    this->crashSounds.m_Memory.m_nAllocationCount = 0;
  }
  this->crashSounds.m_pElements = this->crashSounds.m_Memory.m_pMemory;
  this->iszSound[0].pszValue = nullptr;
  this->iszSound[1].pszValue = nullptr;
  this->iszSound[2].pszValue = nullptr;
  this->iszSound[3].pszValue = nullptr;
  this->iszSound[4].pszValue = nullptr;
  this->iszSound[5].pszValue = nullptr;
  this->iszSound[6].pszValue = nullptr;
  this->iszSound[7].pszValue = nullptr;
  this->iszSound[8].pszValue = nullptr;
  minStateTime = this->minStateTime;
  for ( i = 20; i != 0; --i )
  {
    *(minStateTime - 20) = 0.0;
    *minStateTime++ = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189530
// Name: public: virtual bool CPhysicsHook::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsHook::Init(CPhysicsHook *this)
{
  IPhysicsSurfaceProps *v2; // eax
  factorylist_t factories; // [esp+4h] [ebp-Ch] BYREF

  FactoryList_Retrieve(destData: &factories);
  if ( factories.physicsFactory == nullptr )
    return 0;
  physics = (IPhysics *)factories.physicsFactory(a1: "VPhysics031", a2: 0);
  if ( physics == nullptr )
    return 0;
  physcollision = (IPhysicsCollision *)factories.physicsFactory(a1: "VPhysicsCollision007", a2: 0);
  if ( physcollision == nullptr )
    return 0;
  v2 = (IPhysicsSurfaceProps *)factories.physicsFactory(a1: "VPhysicsSurfaceProps001", a2: 0);
  physprops = v2;
  if ( v2 == nullptr )
    return 0;
  PhysParseSurfaceData(pProps: v2, pFileSystem: filesystem);
  this->m_isFinalTick = true;
  this->m_impactSoundTime = 0.0;
  CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::EnsureCapacity(this: &this->m_vehicleScripts, num: 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101895D0
// Name: public: CCollisionEvent::CCollisionEvent(void)
// Source: json
//------------------------------------------------------------------------------
CCollisionEvent *__thiscall CCollisionEvent::CCollisionEvent(CCollisionEvent *this)
{
  this->IPhysicsCollisionSolver::__vftable = (IPhysicsCollisionSolver_vtbl *)&IPhysicsCollisionSolver::`vftable';
  this->IPhysicsObjectEvent::__vftable = (IPhysicsObjectEvent_vtbl *)&IPhysicsObjectEvent::`vftable';
  this->IPhysicsCollisionEvent::__vftable = (CCollisionEvent_vtbl *)&CCollisionEvent::`vftable'{for `IPhysicsCollisionEvent'};
  this->IPhysicsCollisionSolver::__vftable = (IPhysicsCollisionSolver_vtbl *)&CCollisionEvent::`vftable'{for `IPhysicsCollisionSolver'};
  this->IPhysicsObjectEvent::__vftable = (IPhysicsObjectEvent_vtbl *)&CCollisionEvent::`vftable'{for `IPhysicsObjectEvent'};
  this->m_triggerEvents.m_Memory.m_pMemory = nullptr;
  this->m_triggerEvents.m_Memory.m_nAllocationCount = 0;
  this->m_triggerEvents.m_Memory.m_nGrowSize = 0;
  this->m_triggerEvents.m_Size = 0;
  this->m_triggerEvents.m_pElements = nullptr;
  this->m_touchEvents.m_Memory.m_pMemory = nullptr;
  this->m_touchEvents.m_Memory.m_nAllocationCount = 0;
  this->m_touchEvents.m_Memory.m_nGrowSize = 0;
  this->m_touchEvents.m_Size = 0;
  this->m_touchEvents.m_pElements = nullptr;
  this->m_damageEvents.m_Memory.m_pMemory = nullptr;
  this->m_damageEvents.m_Memory.m_nAllocationCount = 0;
  this->m_damageEvents.m_Memory.m_nGrowSize = 0;
  this->m_damageEvents.m_Size = 0;
  this->m_damageEvents.m_pElements = nullptr;
  this->m_damageInflictors.m_Memory.m_pMemory = nullptr;
  this->m_damageInflictors.m_Memory.m_nAllocationCount = 0;
  this->m_damageInflictors.m_Memory.m_nGrowSize = 0;
  this->m_damageInflictors.m_Size = 0;
  this->m_damageInflictors.m_pElements = nullptr;
  this->m_penetrateEvents.m_Memory.m_pMemory = nullptr;
  this->m_penetrateEvents.m_Memory.m_nAllocationCount = 0;
  this->m_penetrateEvents.m_Memory.m_nGrowSize = 0;
  this->m_penetrateEvents.m_Size = 0;
  this->m_penetrateEvents.m_pElements = nullptr;
  this->m_fluidEvents.m_Memory.m_pMemory = nullptr;
  this->m_fluidEvents.m_Memory.m_nAllocationCount = 0;
  this->m_fluidEvents.m_Memory.m_nGrowSize = 0;
  this->m_fluidEvents.m_Size = 0;
  this->m_fluidEvents.m_pElements = nullptr;
  this->m_removeObjects.m_Memory.m_pMemory = nullptr;
  this->m_removeObjects.m_Memory.m_nAllocationCount = 0;
  this->m_removeObjects.m_Memory.m_nGrowSize = 0;
  this->m_removeObjects.m_Size = 0;
  this->m_removeObjects.m_pElements = nullptr;
  this->m_inCallback = 0;
  this->m_bBufferTouchEvents = false;
  this->m_lastTickFrictionError = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101896E0
// Name: public: virtual int CCollisionEvent::AdditionalCollisionChecksThisTick(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::AdditionalCollisionChecksThisTick(CCollisionEvent *this, int currentChecksDone)
{
  if ( currentChecksDone >= 1200 )
  {
    _DevMsg(
      a1: 1,
      a2: "%s: VPhysics exceeded collision check limit (%d)!!!\nInterpenetration may result!\n",
      "SERVER",
      currentChecksDone);
    return 0;
  }
  else
  {
    _DevMsg(
      a1: 1,
      a2: "%s: VPhysics Collision detection getting expensive, check for too many convex pieces!\n",
      "SERVER");
    return 1200 - currentChecksDone;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189730
// Name: private: void CCollisionEvent::UpdateDamageEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateDamageEvents(CCollisionEvent *this)
{
  damageevent_t *v1; // esi
  int v2; // edi
  int v3; // edi
  int v4; // ebx
  int v5; // ebx
  int i; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  CCollisionEvent *v8; // [esp+8h] [ebp-4h]

  v8 = this;
  i = 0;
  if ( this->m_damageEvents.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      v1 = &this->m_damageEvents.m_Memory.m_pMemory[v7];
      v2 = (2 * (v1->pEntity->m_iEFlags & 1)) | v1->pEntity->IsAlive(this: v1->pEntity);
      v3 = v1->pEntity->m_Collision.GetSolidFlags(this: &v1->pEntity->m_Collision) & 4 | v2;
      CBaseEntity::TakeDamage(this: v1->pEntity, a2: (int)v1, inputInfo: &v1->info);
      v4 = (2 * (v1->pEntity->m_iEFlags & 1)) | v1->pEntity->IsAlive(this: v1->pEntity);
      v5 = v1->pEntity->m_Collision.GetSolidFlags(this: &v1->pEntity->m_Collision) & 4 | v4;
      if ( v1->bRestoreVelocity && v3 != v5 )
        CCollisionEvent::RestoreDamageInflictorState(this: v8, pInflictor: *(float *)&v1->pInflictorPhysics);
      ++v7;
      ++i;
      this = v8;
    }
    while ( i < v8->m_damageEvents.m_Size );
  }
  this->m_damageEvents.m_Size = 0;
  this->m_damageInflictors.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10189820
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::CallQueued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(CCallQueueT<CTSQueue<CFunctor *,0,1> > *this)
{
  CTSQueue<CFunctor *,0,1>::Node_t *v2; // eax
  CTSQueue<CFunctor *,0,1>::Node_t *v3; // eax
  CFunctor *elem; // esi

  if ( this->m_queue.m_Count.m_value != 0 )
  {
    v2 = (CTSQueue<CFunctor *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_queue.m_FreeNodes);
    if ( v2 != nullptr )
    {
      v2->elem = nullptr;
    }
    else
    {
      v2 = (CTSQueue<CFunctor *,0,1>::Node_t *)operator new(nSize: 8u);
      if ( v2 != nullptr )
        v2->elem = nullptr;
      else
        v2 = nullptr;
    }
    CTSQueue<CFunctor *,0,1>::Push(this: &this->m_queue, pNode: v2);
    while ( 1 )
    {
      v3 = CTSQueue<CFunctor *,0,1>::Pop(this: &this->m_queue);
      if ( v3 == nullptr )
        break;
      elem = v3->elem;
      CTSListBase::Push(this: &this->m_queue.m_FreeNodes, pNode: (TSLNodeBase_t *)v3);
      if ( elem == nullptr )
        break;
      elem->operator()(this: elem);
      elem->Release(this: elem);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101898F0
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,bool,float,class CBaseEntity __near *,class CBaseEntity __near *,bool,float>(class CBaseEntity __near * (*)(class CBaseEntity __near *,class CBaseEntity __near *,bool,float),class CBaseEntity __near * const __near &,class CBaseEntity __near * const __near &,bool const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBaseEntity *,CBaseEntity *,CBaseEntity *,bool,float,CBaseEntity *,CBaseEntity *,bool,float>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        CBaseEntity *(__cdecl *pfnProxied)(CBaseEntity *, CBaseEntity *, bool, float),
        CBaseEntity *const *arg1,
        CFunctor_vtbl **arg2,
        const bool *arg3,
        const float *arg4)
{
  CFunctor *v7; // eax

  v7 = (CFunctor *)operator new(nSize: 0x24u);
  if ( v7 != nullptr )
  {
    v7[1].m_nUserID = 1;
    v7[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v7->__vftable = (CFunctor_vtbl *)&CFunctor4<CBaseEntity * (__cdecl *)(CBaseEntity *,CBaseEntity *,bool,float),CBaseEntity *,CBaseEntity *,bool,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v7[1].__vftable = (CFunctor_vtbl *)&CFunctor4<CBaseEntity * (__cdecl *)(CBaseEntity *,CBaseEntity *,bool,float),CBaseEntity *,CBaseEntity *,bool,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v7[2].m_nUserID = (unsigned int)*arg1;
    v7[3].__vftable = *arg2;
    LOBYTE(v7[3].m_nUserID) = *arg3;
    *(float *)&v7[4].__vftable = *arg4;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v7);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189960
// Name: public: void CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>::QueueCall<void,class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &,class IPhysicsObject __near *,class Vector,class Vector>(void (*)(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &),class IPhysicsObject __near * const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<void,IPhysicsObject *,Vector const &,Vector const &,IPhysicsObject *,Vector,Vector>(
        CCallQueueT<CTSQueue<CFunctor *,0,1> > *this,
        void (__cdecl *pfnProxied)(IPhysicsObject *, const Vector *, const Vector *),
        IPhysicsObject *const *arg1,
        const Vector *arg2,
        const Vector *arg3)
{
  CFunctor *v6; // eax

  v6 = (CFunctor *)operator new(nSize: 0x30u);
  if ( v6 != nullptr )
  {
    v6[1].m_nUserID = 1;
    v6[2].__vftable = (CFunctor_vtbl *)pfnProxied;
    v6->__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(IPhysicsObject *,Vector const &,Vector const &),IPhysicsObject *,Vector,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
    v6[1].__vftable = (CFunctor_vtbl *)&CFunctor3<void (__cdecl *)(IPhysicsObject *,Vector const &,Vector const &),IPhysicsObject *,Vector,Vector,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v6[2].m_nUserID = (unsigned int)*arg1;
    *(Vector *)&v6[3].__vftable = *arg2;
    *(Vector *)&v6[4].m_nUserID = *arg3;
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: v6);
  }
  else
  {
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueFunctorInternal(this, pFunctor: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189A60
// Name: void physicssound::AddImpactSound(struct physicssound::soundlist_t __near &,void __near *,int,int,class IPhysicsObject __near *,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl physicssound::AddImpactSound(
        CUtlMemory<CAI_InterestTarget_t,int> *list,
        void *pGameData,
        int entityIndex,
        int soundChannel,
        IPhysicsObject *pObject,
        int surfaceProps,
        unsigned __int16 surfacePropsHit,
        float volume,
        float impactSpeed)
{
  int m_pMemory; // edi
  int v10; // eax
  float v11; // xmm1_4
  physicssound::impactsound_t *v12; // ebx
  int m_nAllocationCount; // eax
  physicssound::impactsound_t *v14; // ecx
  int v15; // eax
  physicssound::impactsound_t *v16; // esi
  float v17; // xmm0_4
  float v18; // xmm0_4

  m_pMemory = (int)list[1].m_pMemory;
  v10 = m_pMemory - 1;
  v11 = impactSpeed + 0.0001;
  if ( m_pMemory - 1 < 0 )
  {
LABEL_6:
    m_nAllocationCount = list->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<touchevent_t,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v14 = (physicssound::impactsound_t *)list->m_pMemory;
    v15 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[m_pMemory + 1], src: &v14[m_pMemory], count: 36 * v15);
    v16 = (physicssound::impactsound_t *)&list->m_pMemory[m_pMemory];
    v16->entityIndex = entityIndex;
    v16->pGameData = pGameData;
    v16->soundChannel = soundChannel;
    pObject->GetPosition(this: pObject, a2: &v16->origin, a3: nullptr);
    v16->volume = volume;
    v16->surfaceProps = surfaceProps;
    v16->surfacePropsHit = surfacePropsHit;
    v16->impactSpeed = v11;
  }
  else
  {
    v12 = (physicssound::impactsound_t *)&list->m_pMemory[v10];
    while ( surfaceProps != v12->surfaceProps && m_pMemory <= 4 )
    {
      --v12;
      if ( --v10 < 0 )
        goto LABEL_6;
    }
    v17 = volume;
    if ( volume > v12->volume )
    {
      pObject->GetPosition(this: pObject, a2: &v12->origin, a3: nullptr);
      v17 = volume;
      v12->pGameData = pGameData;
      v12->entityIndex = entityIndex;
      v12->soundChannel = soundChannel;
      v12->surfacePropsHit = surfacePropsHit;
    }
    v12->volume = v17 + v12->volume;
    v18 = v12->impactSpeed;
    if ( v11 > v18 )
      v18 = impactSpeed + 0.0001;
    v12->impactSpeed = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189BC0
// Name: void physicssound::AddBreakSound(class CUtlVector<struct physicssound::breaksound_t,class CUtlMemory<struct physicssound::breaksound_t,int>> __near &,class Vector const __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __cdecl physicssound::AddBreakSound(
        CUtlVector<physicssound::breaksound_t,CUtlMemory<physicssound::breaksound_t,int> > *list,
        const Vector *origin,
        unsigned __int16 surfaceProps)
{
  int m_Size; // edi
  int v4; // ecx
  physicssound::breaksound_t *v5; // eax
  int m_nAllocationCount; // eax
  physicssound::breaksound_t *m_pMemory; // ecx
  int v8; // eax
  physicssound::breaksound_t *v9; // edi
  float v10; // xmm1_4
  float v11; // xmm2_4
  physicssound::breaksound_t sound; // [esp+4h] [ebp-10h]

  if ( physprops->GetSurfaceData(this: physprops, a2: surfaceProps)->sounds.breakSound != 0 )
  {
    m_Size = list->m_Size;
    v4 = m_Size - 1;
    if ( m_Size - 1 < 0 )
    {
LABEL_7:
      sound.origin = *origin;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      sound.surfacePropsBreak = surfaceProps;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v8 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v8);
      v9 = &list->m_Memory.m_pMemory[m_Size];
      if ( v9 != nullptr )
        *v9 = sound;
    }
    else
    {
      v5 = &list->m_Memory.m_pMemory[v4];
      while ( m_Size <= 2 || surfaceProps != v5->surfacePropsBreak )
      {
        --v5;
        if ( --v4 < 0 )
          goto LABEL_7;
      }
      v10 = (float)(origin->y + v5->origin.y) * 0.5;
      v11 = (float)(origin->z + v5->origin.z) * 0.5;
      v5->origin.x = (float)(v5->origin.x + origin->x) * 0.5;
      v5->origin.y = v10;
      v5->origin.z = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189CF0
// Name: public: void CCollisionEvent::GetListOfPenetratingEntities(class CBaseEntity __near *,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::GetListOfPenetratingEntities(
        CCollisionEvent *this,
        CBaseEntity *pSearch,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *list)
{
  int v3; // eax
  CBaseEntityList *v4; // edx
  int v5; // edi
  unsigned int *v6; // edi
  unsigned int v7; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v9; // eax
  unsigned int v10; // eax
  CBaseEntity *v11; // ebx
  unsigned int v12; // eax
  CBaseEntity *v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v19; // eax
  CBaseEntity **v20; // eax
  CCollisionEvent *v21; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int j; // [esp+8h] [ebp-4h]

  v3 = this->m_penetrateEvents.m_Size - 1;
  v21 = this;
  i = v3;
  if ( v3 >= 0 )
  {
    v4 = g_pEntityList;
    v5 = 20 * v3;
    for ( j = 20 * v3; ; v5 = j )
    {
      v6 = (unsigned int *)((char *)&this->m_penetrateEvents.m_Memory.m_pMemory->hEntity0.m_Index + v5);
      v7 = *v6;
      if ( *v6 == -1 || v4->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
        m_pEntity = nullptr;
      else
        m_pEntity = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      if ( m_pEntity == pSearch
        && (v9 = v6[1]) != -1
        && v4->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9)
        && v4->m_EntPtrArray[(unsigned __int16)v9].m_pEntity != nullptr )
      {
        v10 = v6[1];
        if ( v10 == -1 || v4->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          goto LABEL_26;
        v11 = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      }
      else
      {
        v12 = v6[1];
        if ( v12 == -1 || v4->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v13 = nullptr;
        else
          v13 = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        if ( v13 != pSearch )
          goto LABEL_34;
        v14 = *v6;
        if ( *v6 == -1
          || v4->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14)
          || v4->m_EntPtrArray[(unsigned __int16)v14].m_pEntity == nullptr )
        {
          goto LABEL_34;
        }
        v15 = *v6;
        if ( *v6 == -1 || v4->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
        {
LABEL_26:
          v11 = nullptr;
          goto LABEL_27;
        }
        v11 = (CBaseEntity *)v4->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
      }
LABEL_27:
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v19 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v19 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v19);
      v20 = &list->m_Memory.m_pMemory[m_Size];
      if ( v20 != nullptr )
        *v20 = v11;
      v4 = g_pEntityList;
LABEL_34:
      j -= 20;
      if ( --i < 0 )
        return;
      this = v21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189E90
// Name: private: struct penetrateevent_t __near & CCollisionEvent::FindOrAddPenetrateEvent(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CTreeViewListControl::CColumnInfo *__thiscall CCollisionEvent::FindOrAddPenetrateEvent(
        CCollisionEvent *this,
        CBaseEntity *pEntity0,
        CBaseEntity *pEntity1)
{
  CCollisionEvent *v3; // ebx
  int v4; // esi
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_penetrateEvents; // ebx
  penetrateevent_t *v6; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  unsigned int v9; // eax
  CBaseEntity *v10; // edx
  int v11; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v15; // eax
  vgui::CTreeViewListControl::CColumnInfo *v16; // ecx
  int v17; // edi
  vgui::CTreeViewListControl::CColumnInfo *result; // eax

  v3 = this;
  v4 = this->m_penetrateEvents.m_Size - 1;
  if ( v4 >= 0 )
  {
    p_m_penetrateEvents = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_penetrateEvents;
    v6 = &this->m_penetrateEvents.m_Memory.m_pMemory[v4];
    do
    {
      m_Index = v6->hEntity0.m_Index;
      if ( v6->hEntity0.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEntity0 )
      {
        v9 = v6->hEntity1.m_Index;
        if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
          v10 = nullptr;
        else
          v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
        if ( v10 == pEntity1 )
        {
          v11 = v4;
          goto LABEL_30;
        }
      }
      --v6;
      --v4;
    }
    while ( v4 >= 0 );
    v3 = this;
  }
  m_Size = v3->m_penetrateEvents.m_Size;
  m_nAllocationCount = v3->m_penetrateEvents.m_Memory.m_nAllocationCount;
  p_m_penetrateEvents = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&v3->m_penetrateEvents;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
      this: p_m_penetrateEvents,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_penetrateEvents[1].m_pMemory;
  m_pMemory = p_m_penetrateEvents->m_pMemory;
  v15 = (int)p_m_penetrateEvents[1].m_pMemory - m_Size - 1;
  p_m_penetrateEvents[1].m_nAllocationCount = (int)p_m_penetrateEvents->m_pMemory;
  if ( v15 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v15);
  v16 = &p_m_penetrateEvents->m_pMemory[m_Size];
  if ( v16 != nullptr )
  {
    *(_DWORD *)&v16->m_Title.m_Id = -1;
    v16->m_Width = -1;
  }
  v17 = (int)&p_m_penetrateEvents->m_pMemory[m_Size];
  if ( pEntity0 != nullptr )
    *(_DWORD *)v17 = pEntity0->GetRefEHandle(this: pEntity0)->m_Index;
  else
    *(_DWORD *)v17 = -1;
  if ( pEntity1 != nullptr )
    *(_DWORD *)(v17 + 4) = pEntity1->GetRefEHandle(this: pEntity1)->m_Index;
  else
    *(_DWORD *)(v17 + 4) = -1;
  *(float *)(v17 + 8) = gpGlobals->curtime;
  *(_DWORD *)(v17 + 16) = 0;
  UpdateEntityPenetrationFlag(pEntity: pEntity0, a2: (int)pEntity0, isPenetrating: true);
  UpdateEntityPenetrationFlag(pEntity: pEntity1, a2: (int)pEntity0, isPenetrating: true);
  v11 = m_Size;
LABEL_30:
  result = &p_m_penetrateEvents->m_pMemory[v11];
  *(float *)&result->m_Right = gpGlobals->curtime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A020
// Name: public: virtual int CCollisionEvent::ShouldSolvePenetration(class IPhysicsObject __near *,class IPhysicsObject __near *,void __near *,void __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::ShouldSolvePenetration(
        CCollisionEvent *this,
        IPhysicsObject *pObj0,
        IPhysicsObject *pObj1,
        CBaseEntity *pGameData0,
        penetrateevent_t *pGameData1,
        float dt)
{
  CCollisionEvent *v7; // edi
  CBaseEntity *v8; // ebx
  int result; // eax
  IPhysicsObject *v10; // esi
  IPhysicsObject *v11; // eax
  unsigned __int16 v12; // ax
  const char *DebugName; // eax
  const char *v14; // eax
  ragdoll_t *Ragdoll; // eax
  const char *v16; // [esp-8h] [ebp-20h]
  int v17; // [esp-4h] [ebp-1Ch]
  int v18; // [esp-4h] [ebp-1Ch]
  int duration; // [esp+0h] [ebp-18h]
  float eventTime; // [esp+10h] [ebp-8h]
  CCollisionEvent *v21; // [esp+14h] [ebp-4h]
  CBaseEntity *pEntity1; // [esp+28h] [ebp+10h]
  vgui::CTreeViewListControl::CColumnInfo *event; // [esp+2Ch] [ebp+14h]

  ++this->m_removeObjects.m_pElements;
  v7 = (CCollisionEvent *)((char *)this - 4);
  v21 = (CCollisionEvent *)((char *)this - 4);
  v8 = pGameData0;
  pEntity1 = (CBaseEntity *)pGameData1;
  if ( g_PhysicsHook.m_bPaused )
  {
    v7->m_inCallback = (int)this->m_removeObjects.m_pElements - 1;
    return 1;
  }
  if ( pGameData0 <= (CBaseEntity *)pGameData1 )
  {
    v10 = pObj0;
  }
  else
  {
    v10 = pObj1;
    pEntity1 = pGameData0;
    v11 = pObj0;
    v8 = (CBaseEntity *)pGameData1;
    pObj0 = pObj1;
    pObj1 = v11;
  }
  if ( v8 == pEntity1 && (((int (__thiscall *)(IPhysicsObject *))v10->GetGameFlags)(a1: v10) & 8) != 0 )
  {
    v12 = pObj1->GetGameIndex(this: pObj1);
    v17 = ((unsigned __int16 (__thiscall *)(IPhysicsObject *, _DWORD))v10->GetGameIndex)(a1: v10, a2: v12);
    DebugName = CBaseEntity::GetDebugName(this: v8);
    v14 = (const char *)((int (__thiscall *)(IPhysicsObject *, const char *, int))v10->GetName)(
                          a1: v10,
                          a2: DebugName,
                          a3: v17);
    _DevMsg(a1: 2, a2: "Solving ragdoll self penetration! %s (%s) (%d v %d)\n", v14, v16, v18, duration);
    Ragdoll = Ragdoll_GetRagdoll(pEntity: v8);
    Ragdoll->pGroup->SolvePenetration(this: Ragdoll->pGroup, a2: v10, a3: pObj1);
    --v7->m_inCallback;
    return 0;
  }
  event = CCollisionEvent::FindOrAddPenetrateEvent(this: v7, pEntity0: v8, pEntity1);
  eventTime = gpGlobals->curtime - *(float *)&event->m_Left;
  if ( v8->MyNPCPointer(this: v8) != nullptr )
  {
    if ( CanResolvePenetrationWithNPC(pEntity: pEntity1, pObject: pObj1) )
    {
LABEL_14:
      event->m_ciFlags = 2;
      goto LABEL_15;
    }
    v10 = pObj0;
  }
  if ( pEntity1->MyNPCPointer(this: pEntity1) != nullptr )
  {
    if ( CanResolvePenetrationWithNPC(pEntity: v8, pObject: v10) )
      goto LABEL_14;
LABEL_15:
    v10 = pObj0;
    v7 = v21;
  }
  if ( ((unsigned int)(v8->m_CollisionGroup.m_Value - 1) <= 2 && !pObj1->IsStatic(this: pObj1)
     || (unsigned int)(pEntity1->m_CollisionGroup.m_Value - 1) <= 2 && !v10->IsStatic(this: v10))
    && eventTime > 0.5 )
  {
    event->m_ciFlags = 3;
  }
  if ( eventTime <= 3.0 )
    goto LABEL_32;
  if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue != 0 && v8 != pEntity1 )
  {
    ReportPenetration(pEntity: v8, duration: phys_penetration_error_time.m_pParent->m_Value.m_fValue);
    ReportPenetration(pEntity: pEntity1, duration: phys_penetration_error_time.m_pParent->m_Value.m_fValue);
    v10 = pObj0;
  }
  *(float *)&event->m_Left = gpGlobals->curtime;
  if ( v8->IsPlayer(this: v8)
    || pEntity1->IsPlayer(this: pEntity1)
    || v10->GetShadowController(this: v10) != nullptr
    || (result = (int)pObj1->GetShadowController(this: pObj1)) != 0 )
  {
LABEL_32:
    --v7->m_inCallback;
    return 1;
  }
  else
  {
    event->m_ciFlags = 1;
    --v7->m_inCallback;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018A2A0
// Name: void PhysSetMassCenterOverride(struct masscenteroverride_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysSetMassCenterOverride(masscenteroverride_t *override)
{
  if ( override->entityName.pszValue != nullptr )
    CUtlVector<masscenteroverride_t,CUtlMemory<masscenteroverride_t,int>>::InsertBefore(
      this: &g_PhysicsHook.m_massCenterOverrides,
      elem: g_PhysicsHook.m_massCenterOverrides.m_Size,
      src: override);
}

//------------------------------------------------------------------------------
// Address: 0x1018A2C0
// Name: OutputVPhysicsDebugInfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl OutputVPhysicsDebugInfo(CBaseEntity *pEntity)
{
  CBaseEntity *v1; // ebx
  int v2; // esi
  const char *v3; // ecx
  const char *pszValue; // edi
  const char *DebugName; // eax
  CBaseEntity **m_pMemory; // edi
  const char *v7; // eax
  const char *v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  const char *v12; // [esp-Ch] [ebp-1028h]
  int m_Value; // [esp-8h] [ebp-1024h]
  const char *v14; // [esp-4h] [ebp-1020h]
  _DWORD v15[1024]; // [esp+8h] [ebp-1014h] BYREF
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+1008h] [ebp-14h] BYREF

  v1 = pEntity;
  v2 = 0;
  if ( pEntity != nullptr )
  {
    v3 = "NAV IGNORE";
    if ( pEntity->m_flNavIgnoreUntilTime < gpGlobals->curtime )
      v3 = locale;
    pszValue = pEntity->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    m_Value = pEntity->m_CollisionGroup.m_Value;
    v12 = v3;
    DebugName = CBaseEntity::GetDebugName(this: pEntity);
    _Msg(a1: "Entity %s (%s) %s Collision Group %d\n", pszValue, DebugName, v12, m_Value);
    memset(&list, 0, sizeof(list));
    CCollisionEvent::GetListOfPenetratingEntities(this: &g_Collisions, pSearch: v1, &list);
    if ( list.m_Size <= 0 )
    {
      m_pMemory = list.m_Memory.m_pMemory;
    }
    else
    {
      do
      {
        m_pMemory = list.m_Memory.m_pMemory;
        v7 = *(const char **)((int (__thiscall *)(CBaseEntity *, CBaseEntity **))list.m_Memory.m_pMemory[v2]->GetModelName)(
                               a1: list.m_Memory.m_pMemory[v2],
                               a2: &pEntity);
        if ( v7 == nullptr )
          v7 = locale;
        v14 = v7;
        v8 = CBaseEntity::GetDebugName(this: m_pMemory[v2]);
        _Msg(a1: "  penetration with entity %s (%s)\n", v8, v14);
        ++v2;
      }
      while ( v2 < list.m_Size );
    }
    v9 = ((int (__thiscall *)(CBaseEntity *, _DWORD *))v1->VPhysicsGetObjectList)(a1: v1, a2: v15);
    v10 = v9;
    if ( v9 != 0 )
    {
      if ( v9 <= 1 )
      {
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[0] + 328))(a1: v15[0]);
      }
      else
      {
        v11 = 0;
        do
        {
          _Msg(a1: "Object %d (of %d) =========================\n", v11 + 1, v10);
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v15[v11] + 328))(a1: v15[v11]);
          ++v11;
        }
        while ( v11 < v10 );
        m_pMemory = list.m_Memory.m_pMemory;
      }
    }
    if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A410
// Name: public: void CConstraintFloodList::BuildGraphFromEntity(class CBaseEntity __near *,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConstraintFloodList::BuildGraphFromEntity(
        CConstraintFloodList *this,
        CBaseEntity *pEntity,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *constraintList)
{
  unsigned __int16 v4; // ax
  CConstraintFloodEntry *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CBaseEntity **m_pMemory; // ecx
  int v9; // eax
  CBaseEntity **v10; // edi
  int v11; // edi
  CUtlMap<CBaseEntity *,int,unsigned short>::Node_t search; // [esp+4h] [ebp-Ch] BYREF
  CUtlRBTree<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // [esp+Ch] [ebp-4h]

  p_m_Tree = &this->m_list.m_Tree;
  search.key = pEntity;
  v4 = CUtlRBTree<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_list.m_Tree,
         &search);
  if ( v4 != 0xFFFF )
  {
    v5 = &this->m_entryList.m_Memory.m_pMemory[this->m_list.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem];
    if ( !v5->isMarked )
    {
      if ( v5->isConstraint )
      {
        m_Size = constraintList->m_Size;
        m_nAllocationCount = constraintList->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)constraintList,
            num: m_Size - m_nAllocationCount + 1);
        ++constraintList->m_Size;
        m_pMemory = constraintList->m_Memory.m_pMemory;
        v9 = constraintList->m_Size - m_Size - 1;
        constraintList->m_pElements = constraintList->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &constraintList->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = pEntity;
      }
      v11 = 0;
      for ( v5->isMarked = true; v11 < v5->linkList.m_Size; ++v11 )
        CConstraintFloodList::BuildGraphFromEntity(
          this: (CConstraintFloodList *)p_m_Tree,
          pEntity: v5->linkList.m_Memory.m_pMemory[v11],
          constraintList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A4E0
// Name: physics_debug_entity
// Source: json
//------------------------------------------------------------------------------
void __cdecl physics_debug_entity(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    PhysicsCommand(args, func: (void (__cdecl *)())OutputVPhysicsDebugInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1018A500
// Name: public: virtual void CCollisionEvent::PostSimulationFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::PostSimulationFrame(CCollisionEvent *this)
{
  CCollisionEvent::UpdateDamageEvents(this);
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_PostSimulationQueue);
  CCollisionEvent::UpdateRemoveObjects(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018A520
// Name: public: void CCollisionEvent::FlushQueuedOperations(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::FlushQueuedOperations(CCollisionEvent *this)
{
  int v2; // ebx
  int i; // edi

  v2 = 0;
  do
  {
    if ( this->m_triggerEvents.m_Size
       + this->m_touchEvents.m_Size
       + this->m_damageEvents.m_Size
       + this->m_removeObjects.m_Size
       + g_PostSimulationQueue.m_queue.m_Count.m_value == 0 )
      break;
    _Warning(a1: "Physics queue not empty, error!\n");
    ++v2;
    CCollisionEvent::UpdateTouchEvents(this);
    CCollisionEvent::UpdateDamageEvents(this);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_PostSimulationQueue);
    for ( i = 0; i < this->m_removeObjects.m_Size; ++i )
      UTIL_Remove(oldObj: this->m_removeObjects.m_Memory.m_pMemory[i]);
    this->m_removeObjects.m_Size = 0;
  }
  while ( v2 < 20 );
}

//------------------------------------------------------------------------------
// Address: 0x1018A5D0
// Name: void PhysOnCleanupDeleteList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysOnCleanupDeleteList()
{
  CCollisionEvent::FlushQueuedOperations(this: &g_Collisions);
  if ( physenv != nullptr )
    physenv->CleanupDeleteList(this: physenv);
}

//------------------------------------------------------------------------------
// Address: 0x1018A5F0
// Name: private: float CCollisionEvent::DeltaTimeSinceLastFluid(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCollisionEvent::DeltaTimeSinceLastFluid(CCollisionEvent *this, CBaseEntity *pEntity)
{
  int v2; // esi
  fluidevent_t *v3; // edi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<fluidevent_t,CUtlMemory<fluidevent_t,int> > *p_m_fluidEvents; // esi
  fluidevent_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  fluidevent_t *v12; // eax
  fluidevent_t *v13; // edi

  v2 = this->m_fluidEvents.m_Size - 1;
  if ( v2 < 0 )
  {
LABEL_9:
    m_Size = this->m_fluidEvents.m_Size;
    m_nAllocationCount = this->m_fluidEvents.m_Memory.m_nAllocationCount;
    p_m_fluidEvents = &this->m_fluidEvents;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
        this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&this->m_fluidEvents,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_fluidEvents->m_Size;
    m_pMemory = p_m_fluidEvents->m_Memory.m_pMemory;
    v10 = p_m_fluidEvents->m_Size - m_Size - 1;
    p_m_fluidEvents->m_pElements = p_m_fluidEvents->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v10);
    v11 = m_Size;
    v12 = &p_m_fluidEvents->m_Memory.m_pMemory[m_Size];
    if ( v12 != nullptr )
      v12->hEntity.m_Index = -1;
    v13 = p_m_fluidEvents->m_Memory.m_pMemory;
    if ( pEntity != nullptr )
      v13[v11].hEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    else
      v13[v11].hEntity.m_Index = -1;
    p_m_fluidEvents->m_Memory.m_pMemory[v11].impactTime = gpGlobals->curtime;
    return 2.0;
  }
  else
  {
    v3 = &this->m_fluidEvents.m_Memory.m_pMemory[v2];
    while ( 1 )
    {
      m_Index = v3->hEntity.m_Index;
      if ( v3->hEntity.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEntity )
        return gpGlobals->curtime - this->m_fluidEvents.m_Memory.m_pMemory[v2].impactTime;
      --v3;
      if ( --v2 < 0 )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A700
// Name: private: void CCollisionEvent::AddTouchEvent(class CBaseEntity __near *,class CBaseEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::AddTouchEvent(
        CCollisionEvent *this,
        CBaseEntity *pEntity0,
        CBaseEntity *pEntity1,
        int touchType,
        const Vector *point,
        const Vector *normal)
{
  touchevent_t *v6; // eax

  if ( pEntity0 != nullptr && pEntity1 != nullptr )
  {
    v6 = &this->m_touchEvents.m_Memory.m_pMemory[CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int>>::AddToTail(this: &this->m_touchEvents)];
    v6->pEntity0 = pEntity0;
    v6->pEntity1 = pEntity1;
    v6->touchType = touchType;
    v6->endPoint = *point;
    v6->normal = *normal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A770
// Name: public: void CCollisionEvent::AddRemoveObject(class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::AddRemoveObject(CCollisionEvent *this, IServerNetworkable *pRemove)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_removeObjects; // esi
  int m_Size; // ecx
  int v4; // eax
  IServerNetworkable **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  if ( pRemove != nullptr )
  {
    p_m_removeObjects = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_removeObjects;
    m_Size = this->m_removeObjects.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = (IServerNetworkable **)p_m_removeObjects->m_pMemory;
    while ( *m_pMemory != pRemove )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 == -1 )
    {
LABEL_8:
      m_nAllocationCount = p_m_removeObjects->m_nAllocationCount;
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: p_m_removeObjects, num: m_Size - m_nAllocationCount + 1);
      ++p_m_removeObjects[1].m_pMemory;
      v8 = p_m_removeObjects->m_pMemory;
      v9 = (int)p_m_removeObjects[1].m_pMemory - v7 - 1;
      p_m_removeObjects[1].m_nAllocationCount = (int)p_m_removeObjects->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
      v10 = &p_m_removeObjects->m_pMemory[v7];
      if ( v10 != nullptr )
        *v10 = (vgui::TreeNode *)pRemove;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A800
// Name: private: int CCollisionEvent::AddDamageInflictor(class IPhysicsObject __near *,float,class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::AddDamageInflictor(
        CCollisionEvent *this,
        IPhysicsObject *pInflictorPhysics,
        float otherMass,
        const Vector *savedVel,
        const Vector *savedAngVel,
        bool addList)
{
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CUtlMemory<CAI_InterestTarget_t,int> *p_m_damageInflictors; // esi
  CAI_InterestTarget_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax
  void *v12; // eax
  int v13; // eax
  int v14; // edx
  int v15; // edi
  IPhysicsObject *v16; // ecx
  int v17; // eax
  IPhysicsObject *pInflictorPhysicsa[1024]; // [esp+2Ch] [ebp-101Ch] BYREF
  Vector savedVela; // [esp+102Ch] [ebp-1Ch] BYREF
  Vector savedAngVela; // [esp+1038h] [ebp-10h] BYREF
  CCollisionEvent *v22; // [esp+1044h] [ebp-4h]
  int v23; // [esp+1058h] [ebp+10h]
  int v24; // [esp+1060h] [ebp+18h]

  m_nAllocationCount = this->m_damageInflictors.m_Memory.m_nAllocationCount;
  m_Size = this->m_damageInflictors.m_Size;
  p_m_damageInflictors = (CUtlMemory<CAI_InterestTarget_t,int> *)&this->m_damageInflictors;
  v22 = this;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<touchevent_t,int>::Grow(this: p_m_damageInflictors, num: m_Size - m_nAllocationCount + 1);
  ++p_m_damageInflictors[1].m_pMemory;
  m_pMemory = p_m_damageInflictors->m_pMemory;
  v10 = (int)p_m_damageInflictors[1].m_pMemory - m_Size - 1;
  p_m_damageInflictors[1].m_nAllocationCount = (int)p_m_damageInflictors->m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 36 * v10);
  v11 = (int)&p_m_damageInflictors->m_pMemory[m_Size];
  *(_DWORD *)(v11 + 24) = pInflictorPhysics;
  *(Vector *)v11 = *savedVel;
  *(Vector *)(v11 + 12) = *savedAngVel;
  *(_WORD *)(v11 + 34) = 0;
  *(float *)(v11 + 28) = otherMass;
  *(_WORD *)(v11 + 32) = -1;
  if ( !addList )
    return m_Size;
  v12 = pInflictorPhysics->GetGameData(this: pInflictorPhysics);
  if ( v12 == nullptr )
    return m_Size;
  v13 = (*(int (__thiscall **)(void *, IPhysicsObject **, int))(*(_DWORD *)v12 + 636))(
          a1: v12,
          a2: pInflictorPhysicsa,
          a3: 1024);
  v23 = v13;
  if ( v13 <= 1 )
    return m_Size;
  v14 = 0;
  v15 = m_Size;
  v24 = 0;
  do
  {
    v16 = pInflictorPhysicsa[v14];
    if ( v16 != pInflictorPhysics )
    {
      v16->GetVelocity(this: v16, a2: &savedVela, a3: &savedAngVela);
      v17 = CCollisionEvent::AddDamageInflictor(
              this: v22,
              pInflictorPhysics: pInflictorPhysicsa[v24],
              otherMass,
              savedVel: &savedVela,
              savedAngVel: &savedAngVela,
              addList: false);
      LOWORD(p_m_damageInflictors->m_pMemory[v15].m_flInterest) = v17;
      v14 = v24;
      v15 = v17;
      v13 = v23;
    }
    v24 = ++v14;
  }
  while ( v14 < v13 );
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1018A980
// Name: public: virtual void CCollisionEvent::StartTouch(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::StartTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject1,
        IPhysicsObject *pObject2,
        IPhysicsCollisionData *pTouchData)
{
  CBaseEntity *v5; // edi
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // ebx
  Vector endPoint; // [esp+Ch] [ebp-18h] BYREF
  Vector normal; // [esp+18h] [ebp-Ch] BYREF

  ++this->m_inCallback;
  v5 = (CBaseEntity *)pObject1->GetGameData(this: pObject1);
  v6 = (CBaseEntity *)pObject2->GetGameData(this: pObject2);
  v7 = v6;
  if ( v5 != nullptr && v6 != nullptr )
  {
    pTouchData->GetContactPoint(this: pTouchData, a2: &endPoint);
    pTouchData->GetSurfaceNormal(this: pTouchData, a2: &normal);
    if ( !this->m_bBufferTouchEvents )
    {
      CCollisionEvent::DispatchStartTouch(this, pEntity0: v5, pEntity1: v7, point: &endPoint, &normal);
      --this->m_inCallback;
      return;
    }
    CCollisionEvent::AddTouchEvent(this, pEntity0: v5, pEntity1: v7, touchType: 0, point: &endPoint, &normal);
  }
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1018AA20
// Name: public: virtual void CCollisionEvent::EndTouch(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::EndTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject1,
        IPhysicsObject *pObject2,
        IPhysicsCollisionData *pTouchData)
{
  CBaseEntity *v5; // ebx
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // edi
  int v8; // eax
  touchevent_t *m_pMemory; // edx
  int v10; // ecx
  Vector *v11; // eax
  IPhysicsObject *pObject[1024]; // [esp+Ch] [ebp-1020h] BYREF
  Vector v13; // [esp+100Ch] [ebp-20h] BYREF
  _BYTE v14[12]; // [esp+1018h] [ebp-14h] BYREF
  int v15; // [esp+1024h] [ebp-8h]
  CBaseEntity *v16; // [esp+1028h] [ebp-4h]
  int v17; // [esp+1034h] [ebp+8h]
  int v18; // [esp+1038h] [ebp+Ch]

  ++this->m_inCallback;
  v5 = (CBaseEntity *)pObject1->GetGameData(this: pObject1);
  v6 = (CBaseEntity *)pObject2->GetGameData(this: pObject2);
  v7 = v6;
  v16 = v6;
  if ( v5 != nullptr && v6 != nullptr )
  {
    v15 = v5->VPhysicsGetObjectList(this: v5, a2: pObject, a3: 1024);
    v18 = 0;
    v17 = 0;
    if ( v15 <= 0 )
    {
LABEL_6:
      pTouchData->GetContactPoint(this: pTouchData, a2: (Vector *)v14);
      pTouchData->GetSurfaceNormal(this: pTouchData, a2: &v13);
      if ( !this->m_bBufferTouchEvents )
      {
        CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: v5, other: v7);
        CBaseEntity::PhysicsNotifyOtherOfUntouch(ent: v7, other: v5);
        --this->m_inCallback;
        return;
      }
      v8 = CUtlVector<touchevent_t,CUtlMemory<touchevent_t,int>>::AddToTail(this: &this->m_touchEvents);
      m_pMemory = this->m_touchEvents.m_Memory.m_pMemory;
      v10 = v8;
      m_pMemory[v10].pEntity0 = v5;
      m_pMemory[v10].pEntity1 = v7;
      m_pMemory[v10].touchType = 1;
      v11 = (Vector *)&m_pMemory[v8];
      v11[1] = vec3_origin;
      v11[2] = vec3_origin;
    }
    else
    {
      while ( 1 )
      {
        v18 += CountPhysicsObjectEntityContacts(pObject: pObject[v17], pEntity: v7);
        if ( v18 > 1 )
          break;
        v7 = v16;
        if ( ++v17 >= v15 )
          goto LABEL_6;
      }
    }
  }
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1018AB90
// Name: public: virtual void CCollisionEvent::ObjectEnterTrigger(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectEnterTrigger(
        CCollisionEvent *this,
        IPhysicsObject *pTrigger,
        IPhysicsObject *pObject)
{
  CBaseEntity *v4; // edi
  CBaseEntity *v5; // eax

  v4 = (CBaseEntity *)pTrigger->GetGameData(this: pTrigger);
  v5 = (CBaseEntity *)pObject->GetGameData(this: pObject);
  if ( v4 != nullptr && v5 != nullptr )
  {
    ++this->m_inCallback;
    this->m_currentTriggerEvent.pEntity = v5;
    this->m_currentTriggerEvent.bStart = true;
    this->m_currentTriggerEvent.pTriggerEntity = v4;
    this->m_currentTriggerEvent.pTriggerPhysics = pTrigger;
    this->m_currentTriggerEvent.pObject = pObject;
    v4->StartTouch(this: v4, a2: v5);
    *(_QWORD *)&this->m_currentTriggerEvent.pTriggerEntity = 0;
    *(_QWORD *)&this->m_currentTriggerEvent.pEntity = 0;
    *(_DWORD *)&this->m_currentTriggerEvent.bStart = 0;
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AC20
// Name: public: virtual void CCollisionEvent::ObjectLeaveTrigger(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectLeaveTrigger(
        CCollisionEvent *this,
        IPhysicsObject *pTrigger,
        IPhysicsObject *pObject)
{
  CBaseEntity *v4; // edi
  CBaseEntity *v5; // eax

  v4 = (CBaseEntity *)pTrigger->GetGameData(this: pTrigger);
  v5 = (CBaseEntity *)pObject->GetGameData(this: pObject);
  if ( v4 != nullptr && v5 != nullptr )
  {
    ++this->m_inCallback;
    this->m_currentTriggerEvent.pEntity = v5;
    this->m_currentTriggerEvent.pObject = pObject;
    this->m_currentTriggerEvent.pTriggerEntity = v4;
    this->m_currentTriggerEvent.pTriggerPhysics = pTrigger;
    this->m_currentTriggerEvent.bStart = false;
    v4->EndTouch(this: v4, a2: v5);
    *(_QWORD *)&this->m_currentTriggerEvent.pTriggerEntity = 0;
    *(_QWORD *)&this->m_currentTriggerEvent.pEntity = 0;
    *(_DWORD *)&this->m_currentTriggerEvent.bStart = 0;
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ACB0
// Name: void PhysGetListOfPenetratingEntities(class CBaseEntity __near *,class CUtlVector<class CBaseEntity __near *,class CUtlMemory<class CBaseEntity __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysGetListOfPenetratingEntities(
        CBaseEntity *pSearch,
        CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *list)
{
  CCollisionEvent::GetListOfPenetratingEntities(this: &g_Collisions, pSearch, list);
}

//------------------------------------------------------------------------------
// Address: 0x1018ACD0
// Name: void PhysCollisionSound(class CBaseEntity __near *,class IPhysicsObject __near *,int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCollisionSound(
        CBaseEntity *pEntity,
        IPhysicsObject *pPhysObject,
        int channel,
        int surfaceProps,
        unsigned __int16 surfacePropsHit,
        float deltaTime,
        float speed)
{
  float volume; // xmm0_4
  edict_t *m_pPev; // eax

  if ( deltaTime >= 0.050000001 && speed >= 70.0 )
  {
    volume = (float)(speed * speed) * 0.0000097656248;
    if ( volume > 1.0 )
      volume = 1.0;
    m_pPev = pEntity->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    physicssound::AddImpactSound(
      list: (CUtlMemory<CAI_InterestTarget_t,int> *)&g_PhysicsHook.m_impactSounds,
      pGameData: pEntity,
      entityIndex: (int)m_pPev,
      soundChannel: channel,
      pObject: pPhysObject,
      surfaceProps,
      surfacePropsHit,
      volume,
      impactSpeed: speed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AD60
// Name: void PhysBreakSound(class CBaseEntity __near *,class IPhysicsObject __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysBreakSound(CBaseEntity *pEntity, IPhysicsObject *pPhysObject, Vector vecOrigin)
{
  unsigned __int16 v3; // ax

  if ( pPhysObject != nullptr )
  {
    v3 = pPhysObject->GetMaterialIndex(this: pPhysObject);
    physicssound::AddBreakSound(list: &g_PhysicsHook.m_breakSounds, origin: &vecOrigin, surfaceProps: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018AD90
// Name: void PhysCallbackImpulse(class IPhysicsObject __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCallbackImpulse(
        IPhysicsObject *pPhysicsObject,
        const Vector *vecCenterForce,
        const Vector *vecCenterTorque)
{
  __int64 v3; // xmm0_8
  float z; // ecx
  __int64 v5; // xmm0_8
  Vector arg2; // [esp+0h] [ebp-18h] BYREF
  Vector arg3; // [esp+Ch] [ebp-Ch] BYREF

  v3 = *(_QWORD *)&vecCenterTorque->x;
  arg3.z = vecCenterTorque->z;
  z = vecCenterForce->z;
  *(_QWORD *)&arg3.x = v3;
  v5 = *(_QWORD *)&vecCenterForce->x;
  arg2.z = z;
  *(_QWORD *)&arg2.x = v5;
  CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<void,IPhysicsObject *,Vector const &,Vector const &,IPhysicsObject *,Vector,Vector>(
    this: &g_PostSimulationQueue,
    pfnProxied: PostSimulation_ImpulseEvent,
    arg1: &pPhysicsObject,
    &arg2,
    &arg3);
}

//------------------------------------------------------------------------------
// Address: 0x1018ADE0
// Name: void PhysCallbackRemove(class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCallbackRemove(IServerNetworkable *pRemove)
{
  if ( physenv != nullptr && physenv->IsInSimulation(this: physenv) || g_Collisions.m_inCallback > 0 )
    CCollisionEvent::AddRemoveObject(this: &g_Collisions, pRemove);
  else
    UTIL_Remove(oldObj: pRemove);
}

//------------------------------------------------------------------------------
// Address: 0x1018AF00
// Name: void physicssound::PlayImpactSounds(struct physicssound::soundlist_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall physicssound::PlayImpactSounds(int a1@<edi>, physicssound::soundlist_t *list)
{
  physicssound::soundlist_t *v2; // ecx
  int v3; // eax
  int v4; // eax
  char *v5; // esi
  surfacedata_t *v6; // edi
  int v7; // eax
  int impactHard; // edx
  float hardVelocityThreshold; // xmm0_4
  const char *v10; // eax
  float attenuation; // xmm0_4
  float v12; // xmm0_4
  CSoundParameters params; // [esp+1Ch] [ebp-128h] BYREF
  CPASAttenuationFilter filter; // [esp+D0h] [ebp-74h] BYREF
  EmitSound_t ep; // [esp+F0h] [ebp-54h] BYREF
  soundlevel_t soundlevel; // [esp+138h] [ebp-Ch]
  int i; // [esp+13Ch] [ebp-8h]
  int v19; // [esp+140h] [ebp-4h]
  int savedregs; // [esp+144h] [ebp+0h] BYREF

  v2 = list;
  v3 = list->elements.m_Size - 1;
  i = v3;
  if ( v3 >= 0 )
  {
    v4 = 36 * v3;
    v19 = v4;
    while ( 1 )
    {
      v5 = (char *)v2->elements.m_Memory.m_pMemory + v4;
      v6 = physprops->GetSurfaceData(this: physprops, a2: *((unsigned __int16 *)v5 + 10));
      if ( v6->sounds.impactHard != 0 )
      {
        v7 = ((int (__stdcall *)(_DWORD, int))physprops->GetSurfaceData)(a1: *((unsigned __int16 *)v5 + 11), a2: a1);
        impactHard = v6->sounds.impactHard;
        if ( v7 != 0
          && v6->sounds.impactSoft != 0
          && (v6->audio.hardThreshold > *(float *)(v7 + 24)
           || (hardVelocityThreshold = v6->audio.hardVelocityThreshold) > 0.0
           && hardVelocityThreshold > *((float *)v5 + 4)) )
        {
          impactHard = v6->sounds.impactSoft;
        }
        a1 = impactHard;
        v10 = (const char *)((int (__thiscall *)(IPhysicsSurfaceProps *))physprops->GetString)(a1: physprops);
        params.pitch = 100;
        params.pitchlow = 100;
        params.pitchhigh = 100;
        params.channel = 0;
        params.volume = 1.0;
        params.soundlevel = SNDLVL_NORM;
        params.soundname[0] = 0;
        params.play_to_owner_only = false;
        params.count = 0;
        params.delay_msec = 0;
        params.m_nSoundEntryVersion = 1;
        params.m_hSoundScriptHandle = -1;
        params.m_pOperatorsKV = nullptr;
        params.m_nRandomSeed = -1;
        if ( !CBaseEntity::GetParametersForSound(soundname: v10, &params, actormodel: nullptr) )
        {
          list->elements.m_Size = 0;
          return;
        }
        if ( *((float *)v5 + 3) > 1.0 )
          *((_DWORD *)v5 + 3) = 1065353216;
        soundlevel = params.soundlevel;
        CRecipientFilter::CRecipientFilter(this: &filter);
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
        CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: (const Vector *)v5 + 2);
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
        if ( soundlevel <= SNDLVL_50dB )
        {
          if ( soundlevel != SNDLVL_NONE )
            attenuation = 4.0;
          else
            attenuation = 0.0;
        }
        else
        {
          attenuation = 20.0 / (float)(soundlevel - 50);
        }
        CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: (const Vector *)v5 + 2, attenuation);
        ep.m_nChannel = *((_DWORD *)v5 + 2);
        ep.m_pSoundName = params.soundname;
        ep.m_nPitch = params.pitch;
        ep.m_flSoundTime = 0.0;
        v12 = *((float *)v5 + 3) * params.volume;
        ep.m_hSoundScriptHandle = params.m_hSoundScriptHandle;
        ep.m_SoundLevel = params.soundlevel;
        ep.m_nFlags = 0;
        ep.m_pflSoundDuration = nullptr;
        *(_WORD *)&ep.m_bEmitCloseCaption = 1;
        ep.m_bWarnOnDirectWaveReference = false;
        ep.m_nSpeakerEntity = -1;
        memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
        ep.m_flVolume = v12;
        ep.m_pOrigin = (const Vector *)(v5 + 24);
        ep.m_nSoundEntryVersion = params.m_nSoundEntryVersion;
        CBaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        CRecipientFilter::~CRecipientFilter(this: &filter);
      }
      v19 -= 36;
      if ( --i < 0 )
      {
        list->elements.m_Size = 0;
        return;
      }
      v4 = v19;
      v2 = list;
    }
  }
  list->elements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018B180
// Name: void physicssound::PlayBreakSounds(class CUtlVector<struct physicssound::breaksound_t,class CUtlMemory<struct physicssound::breaksound_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl physicssound::PlayBreakSounds(
        CUtlVector<physicssound::breaksound_t,CUtlMemory<physicssound::breaksound_t,int> > *list)
{
  int v1; // eax
  int v2; // eax
  char *v3; // esi
  surfacedata_t *v4; // eax
  const char *v5; // eax
  soundlevel_t soundlevel; // edi
  float attenuation; // xmm0_4
  Vector *m_pMemory; // eax
  CSoundParameters params; // [esp+18h] [ebp-124h] BYREF
  CPASAttenuationFilter filter; // [esp+CCh] [ebp-70h] BYREF
  EmitSound_t ep; // [esp+ECh] [ebp-50h] BYREF
  int i; // [esp+134h] [ebp-8h]
  int j; // [esp+138h] [ebp-4h]
  int savedregs; // [esp+13Ch] [ebp+0h] BYREF

  v1 = list->m_Size - 1;
  i = v1;
  if ( v1 < 0 )
  {
LABEL_19:
    list->m_Size = 0;
  }
  else
  {
    v2 = 16 * v1;
    for ( j = v2; ; v2 = j )
    {
      v3 = (char *)list->m_Memory.m_pMemory + v2;
      v4 = physprops->GetSurfaceData(this: physprops, a2: *((_DWORD *)v3 + 3));
      v5 = physprops->GetString(this: physprops, a2: v4->sounds.breakSound);
      params.pitch = 100;
      params.pitchlow = 100;
      params.pitchhigh = 100;
      params.channel = 0;
      params.volume = 1.0;
      params.soundlevel = SNDLVL_NORM;
      params.soundname[0] = 0;
      params.play_to_owner_only = false;
      params.count = 0;
      params.delay_msec = 0;
      params.m_nSoundEntryVersion = 1;
      params.m_hSoundScriptHandle = -1;
      params.m_pOperatorsKV = nullptr;
      params.m_nRandomSeed = -1;
      if ( !CBaseEntity::GetParametersForSound(soundname: v5, &params, actormodel: nullptr) )
        break;
      soundlevel = params.soundlevel;
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: (const Vector *)v3);
      filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
      if ( soundlevel <= SNDLVL_50dB )
      {
        if ( soundlevel != SNDLVL_NONE )
          attenuation = 4.0;
        else
          attenuation = 0.0;
      }
      else
      {
        attenuation = 20.0 / (float)(soundlevel - 50);
      }
      CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: (const Vector *)v3, attenuation);
      ep.m_pSoundName = params.soundname;
      ep.m_nPitch = params.pitch;
      ep.m_hSoundScriptHandle = params.m_hSoundScriptHandle;
      ep.m_SoundLevel = params.soundlevel;
      ep.m_flSoundTime = 0.0;
      ep.m_nFlags = 0;
      ep.m_pflSoundDuration = nullptr;
      *(_WORD *)&ep.m_bEmitCloseCaption = 1;
      ep.m_bWarnOnDirectWaveReference = false;
      ep.m_nSpeakerEntity = -1;
      memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
      ep.m_nChannel = 6;
      ep.m_flVolume = params.volume;
      ep.m_pOrigin = (const Vector *)v3;
      ep.m_nSoundEntryVersion = params.m_nSoundEntryVersion;
      CBaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
      m_pMemory = ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory;
      ep.m_UtlVecSoundOrigin.m_Size = 0;
      if ( ep.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
      {
        if ( ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
        }
        ep.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
      }
      ep.m_UtlVecSoundOrigin.m_pElements = m_pMemory;
      if ( ep.m_UtlVecSoundOrigin.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
          ep.m_UtlVecSoundOrigin.m_Memory.m_pMemory = nullptr;
        }
        ep.m_UtlVecSoundOrigin.m_Memory.m_nAllocationCount = 0;
      }
      CRecipientFilter::~CRecipientFilter(this: &filter);
      j -= 16;
      if ( --i < 0 )
        goto LABEL_19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B3B0
// Name: public: virtual void CPhysicsHook::PreClientUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsHook::PreClientUpdate(CPhysicsHook *this@<ecx>, int a2@<edi>)
{
  float v3; // xmm0_4

  v3 = gpGlobals->frametime + this->m_impactSoundTime;
  this->m_impactSoundTime = v3;
  if ( v3 > 0.050000001 )
  {
    physicssound::PlayImpactSounds(a1: a2, list: &this->m_impactSounds);
    this->m_impactSoundTime = 0.0;
    physicssound::PlayBreakSounds(list: &this->m_breakSounds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B3F0
// Name: public: virtual void CCollisionEvent::FluidStartTouch(class IPhysicsObject __near *,class IPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCollisionEvent::FluidStartTouch(
        CCollisionEvent *this@<ecx>,
        int a2@<esi>,
        IPhysicsObject *pObject,
        IPhysicsFluidController *pFluid)
{
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // esi
  CBaseEntity_vtbl *v8; // eax
  int v9; // eax
  float (__thiscall *CalculateLinearDrag)(IPhysicsObject *, const Vector *); // edx
  double v11; // st7
  double v12; // st7
  float v13; // xmm0_4
  float v14; // xmm0_4
  double v15; // st7
  float v16; // xmm0_4
  float v17; // xmm0_4
  Vector rotAxis; // [esp+8h] [ebp-44h] BYREF
  Vector unitVel; // [esp+14h] [ebp-38h] BYREF
  Vector normal; // [esp+20h] [ebp-2Ch] BYREF
  Vector vel; // [esp+2Ch] [ebp-20h] BYREF
  Vector angVel; // [esp+38h] [ebp-14h] BYREF
  float dist; // [esp+44h] [ebp-8h] BYREF
  float linearScale; // [esp+48h] [ebp-4h]
  CBaseEntity_vtbl *dragScalea; // [esp+54h] [ebp+8h]
  float dragScaleb; // [esp+54h] [ebp+8h]
  float dragScale; // [esp+54h] [ebp+8h]
  float dragScalec; // [esp+54h] [ebp+8h]

  ++this->m_inCallback;
  if ( pObject != nullptr && pFluid != nullptr )
  {
    v6 = (CBaseEntity *)pObject->GetGameData(this: pObject);
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = v6->__vftable;
      v7->m_iEFlags |= 0x80000u;
      dragScalea = v8;
      v9 = pFluid->GetContents(this: pFluid);
      dragScalea->OnEntityEvent(this: v7, a2: ENTITY_EVENT_WATER_TOUCH, a3: (void *)v9);
      if ( CCollisionEvent::DeltaTimeSinceLastFluid(this, pEntity: v7) >= 0.5 )
      {
        ((void (__thiscall *)(IPhysicsFluidController *, Vector *, float *, int))pFluid->GetSurfacePlane)(
          a1: pFluid,
          a2: &normal,
          a3: &dist,
          a4: a2);
        pObject->GetVelocity(this: pObject, a2: &vel, a3: &angVel);
        unitVel = vel;
        VectorNormalize(vec: &unitVel);
        dragScaleb = pFluid->GetDensity(this: pFluid);
        dragScale = ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetSimulationTimestep)(a1: physenv)
                  * dragScaleb;
        CalculateLinearDrag = pObject->CalculateLinearDrag;
        normal.x = -normal.x;
        normal.y = -normal.y;
        normal.z = -normal.z;
        linearScale = (float)((float)(unitVel.y * normal.y) + (float)(normal.x * unitVel.x))
                    + (float)(unitVel.z * normal.z);
        v11 = ((double (__thiscall *)(IPhysicsObject *, Vector *))CalculateLinearDrag)(a1: pObject, a2: &normal);
        v12 = v11 * (linearScale * 0.5) * dragScale;
        linearScale = v12;
        if ( v12 >= 0.0 )
        {
          v13 = linearScale;
          if ( linearScale > 1.0 )
            v13 = 1.0;
        }
        else
        {
          v13 = 0.0;
        }
        LODWORD(v14) = LODWORD(v13) ^ _mask__NegFloat_;
        vel.x = vel.x * v14;
        vel.y = vel.y * v14;
        vel.z = vel.z * v14;
        rotAxis = angVel;
        VectorNormalize(vec: &rotAxis);
        v15 = ((double (__thiscall *)(IPhysicsObject *, Vector *))pObject->CalculateAngularDrag)(
                a1: pObject,
                a2: &angVel)
            * 0.25
            * dragScale;
        if ( v15 >= 0.0 )
        {
          v16 = v15;
          dragScalec = v15;
          if ( dragScalec > 1.0 )
            v16 = 1.0;
        }
        else
        {
          v16 = 0.0;
        }
        LODWORD(v17) = LODWORD(v16) ^ _mask__NegFloat_;
        angVel.x = angVel.x * v17;
        angVel.y = angVel.y * v17;
        angVel.z = angVel.z * v17;
        PhysicsSplash(pFluid, pObject, pEntity: v7);
        ((void (__thiscall *)(IPhysicsObject *, Vector *))pObject->AddVelocity)(a1: pObject, a2: &vel);
      }
    }
    --this->m_inCallback;
  }
  else
  {
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B670
// Name: public: virtual void CCollisionEvent::FluidEndTouch(class IPhysicsObject __near *,class IPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::FluidEndTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject,
        IPhysicsFluidController *pFluid)
{
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // edi
  IPhysicsObject *v6; // ecx
  int v7; // eax
  IPhysicsObject *pObjecta; // [esp+10h] [ebp+8h]

  ++this->m_inCallback;
  if ( pObject != nullptr && pFluid != nullptr )
  {
    v4 = (CBaseEntity *)((int (*)(void))pObject->GetGameData)();
    v5 = v4;
    if ( v4 != nullptr )
    {
      if ( CCollisionEvent::DeltaTimeSinceLastFluid(this, pEntity: v4) >= 0.5 )
        PhysicsSplash(pFluid, pObject, pEntity: v5);
      v6 = (IPhysicsObject *)v5->__vftable;
      v5->m_iEFlags &= ~0x80000u;
      pObjecta = v6;
      v7 = pFluid->GetContents(this: pFluid);
      ((void (__thiscall *)(CBaseEntity *, int, int))pObjecta[94].__vftable)(a1: v5, a2: 1, a3: v7);
    }
    --this->m_inCallback;
  }
  else
  {
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018B710
// Name: PhysFrame
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFrame(float deltaTime)
{
  IPhysicsEnvironment *v1; // ecx
  float v2; // xmm1_4
  float v3; // xmm0_4
  int m_nValue; // eax
  int v5; // esi
  void *v6; // esp
  void (__thiscall *GetActiveObjects)(IPhysicsEnvironment *, IPhysicsObject **); // eax
  IPhysicsObject **v8; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // edi
  CBaseEntity *v13; // esi
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // edi
  const Vector *v15; // eax
  entitem_t *j; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v18; // ecx
  IHandleEntity *m_pEntity; // esi
  IHandleEntity_vtbl *v20; // edi
  double v21; // st7
  float v22; // xmm0_4
  int v23; // esi
  float v24; // xmm1_4
  CCollisionEvent *v25; // ecx
  int k; // esi
  const Vector *v27; // [esp+8h] [ebp-3Ch]
  _DWORD v28[3]; // [esp+24h] [ebp-20h] BYREF
  IPhysicsObject **pActiveList; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  float simRealTime; // [esp+38h] [ebp-Ch]
  int activeCount; // [esp+3Ch] [ebp-8h]
  bool bProfile; // [esp+43h] [ebp-1h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF
  int deltaTimea; // [esp+4Ch] [ebp+8h]

  v1 = physenv;
  if ( physenv != nullptr && !g_PhysicsHook.m_bPaused )
  {
    v2 = deltaTime;
    if ( deltaTime > 1.0 || deltaTime < 0.0 )
    {
      _Msg(a1: "Reset physics clock\n");
      v1 = physenv;
      v2 = 0.0;
    }
    else if ( deltaTime > 0.1 )
    {
      v2 = 0.1;
    }
    simRealTime = 0.0;
    v3 = phys_timescale.m_pParent->m_Value.m_fValue * v2;
    deltaTimea = LODWORD(v3);
    if ( v3 > 0.1 )
    {
      v3 = 0.1;
      deltaTimea = 1036831949;
    }
    if ( phys_speeds.m_pParent != nullptr )
      m_nValue = phys_speeds.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    bProfile = m_nValue != 0;
    if ( m_nValue != 0 )
    {
      simRealTime = _Plat_FloatTime();
      v1 = physenv;
      v3 = *(float *)&deltaTimea;
    }
    if ( phys_debug_check_contacts.m_pParent != nullptr && phys_debug_check_contacts.m_pParent->m_Value.m_nValue != 0 )
    {
      v1->DebugCheckContacts(this: v1);
      v1 = physenv;
      v3 = *(float *)&deltaTimea;
    }
    g_Collisions.m_bBufferTouchEvents = true;
    ((void (__stdcall *)(float))v1->Simulate)(a1: COERCE_FLOAT(LODWORD(v3)));
    v5 = physenv->GetActiveObjectCount(this: physenv);
    activeCount = v5;
    if ( v5 != 0 )
    {
      v6 = alloca(4 * v5);
      GetActiveObjects = physenv->GetActiveObjects;
      v8 = (IPhysicsObject **)v28;
      pActiveList = (IPhysicsObject **)v28;
      GetActiveObjects(this: physenv, a2: (IPhysicsObject **)v28);
      v9 = 0;
      if ( v5 > 0 )
      {
        do
        {
          v10 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v28[v9] + 68))(a1: v28[v9]);
          v11 = v10;
          if ( v10 != 0 )
          {
            if ( CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(this: (CCollisionProperty *)(v10 + 228)) )
              CCollisionProperty::MarkSurroundingBoundsDirty(this: (CCollisionProperty *)(v11 + 228));
            (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v11 + 608))(a1: v11, a2: v28[v9]);
          }
          ++v9;
        }
        while ( v9 < activeCount );
      }
      if ( phys_show_active.m_pParent != nullptr && phys_show_active.m_pParent->m_Value.m_nValue != 0 )
      {
        v12 = 0;
        for ( i = 0; v12 < activeCount; i = v12 )
        {
          v13 = (CBaseEntity *)v8[v12]->GetGameData(this: v8[v12]);
          if ( v13 != nullptr )
          {
            if ( (v13->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
            NDebugOverlay::Cross3D(
              position: &v13->m_vecAbsOrigin,
              size: 12.0,
              r: 255,
              g: 0,
              b: 0,
              noDepthTest: 0,
              flDuration: 0.0);
            p_m_Collision = &v13->m_Collision;
            if ( (v13->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
            if ( (v13->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
            v27 = p_m_Collision->OBBMaxs(this: p_m_Collision);
            v15 = p_m_Collision->OBBMins(this: p_m_Collision);
            NDebugOverlay::BoxAngles(
              origin: &v13->m_vecAbsOrigin,
              mins: v15,
              maxs: v27,
              angles: &v13->m_angAbsRotation,
              r: 255,
              g: 255,
              b: 0,
              a: 8,
              duration: 0.0);
            v12 = i;
            v8 = pActiveList;
          }
          ++v12;
        }
      }
    }
    for ( j = g_pShadowEntities->m_pItemList; j != nullptr; j = j->pNext )
    {
      m_Index = j->hEnt.m_Index;
      if ( j->hEnt.m_Index != -1
        && (v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
        && (m_pEntity = v18->m_pEntity, v18->m_pEntity != nullptr) )
      {
        v20 = m_pEntity[82].__vftable;
        if ( v20 != nullptr
          && (*((unsigned __int8 (__thiscall **)(IHandleEntity_vtbl *))v20->dtr_IHandleEntity + 2))(a1: m_pEntity[82].__vftable) == 0 )
        {
          ((void (__thiscall *)(IHandleEntity *, IHandleEntity_vtbl *))m_pEntity->__vftable[51].GetRefEHandle)(
            a1: m_pEntity,
            a2: v20);
        }
      }
      else
      {
        _Msg(a1: "Dangling pointer to physics entity!!!\n");
      }
    }
    if ( bProfile )
    {
      v21 = _Plat_FloatTime() - simRealTime;
      simRealTime = v21;
      if ( v21 >= 0.0 )
        v22 = simRealTime;
      else
        v22 = 0.0;
      v23 = activeCount;
      v24 = (float)(g_PhysAverageSimTime * 0.8) + v22 * 0.2;
      g_PhysAverageSimTime = v24;
      if ( lastObjectCount != 0 || activeCount != 0 )
        _Msg(
          a1: "Physics: %3d objects, %4.1fms / AVG: %4.1fms\n",
          activeCount,
          (float)(v22 * 1000.0),
          (float)(v24 * 1000.0));
      lastObjectCount = v23;
    }
    g_Collisions.m_bBufferTouchEvents = false;
    CCollisionEvent::UpdateFrictionSounds(this: &g_Collisions);
    CCollisionEvent::UpdateTouchEvents(this: &g_Collisions);
    CCollisionEvent::UpdatePenetrateEvents(this: &g_Collisions);
    CCollisionEvent::UpdateFluidEvents(this: &g_Collisions);
    CCollisionEvent::UpdateDamageEvents(this: v25);
    CCallQueueT<CTSQueue<CFunctor *,0,1>>::CallQueued(this: &g_PostSimulationQueue);
    for ( k = 0; k < g_Collisions.m_removeObjects.m_Size; ++k )
      UTIL_Remove(oldObj: g_Collisions.m_removeObjects.m_Memory.m_pMemory[k]);
    g_Collisions.m_removeObjects.m_Size = 0;
    CCollisionEvent::FlushQueuedOperations(this: &g_Collisions);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BB40
// Name: public: virtual void CCollisionEvent::AddDamageEvent(class CBaseEntity __near *,class CTakeDamageInfo const __near &,class IPhysicsObject __near *,bool,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::AddDamageEvent(
        CCollisionEvent *this,
        CBaseEntity *pEntity,
        const CTakeDamageInfo *info,
        IPhysicsObject *pInflictorPhysics,
        bool bRestoreVelocity,
        const Vector *savedVel,
        const Vector *savedAngVel)
{
  damageevent_t *v8; // esi
  int v9; // eax
  inflictorstate_t *m_pMemory; // esi
  IPhysicsObject **p_pInflictorPhysics; // ecx
  bool v12; // cc
  inflictorstate_t *v13; // eax
  float otherMass; // [esp+34h] [ebp+14h]

  if ( (pEntity->m_iEFlags & 1) == 0 )
  {
    g_pGameRules->Damage_GetTimeBased(this: g_pGameRules);
    v8 = &this->m_damageEvents.m_Memory.m_pMemory[CUtlVector<damageevent_t,CUtlMemory<damageevent_t,int>>::InsertBefore(
                                                    this: &this->m_damageEvents,
                                                    elem: this->m_damageEvents.m_Size)];
    v8->pEntity = pEntity;
    CTakeDamageInfo::operator=(this: &v8->info, __that: info);
    v8->pInflictorPhysics = pInflictorPhysics;
    v8->bRestoreVelocity = bRestoreVelocity;
    if ( pInflictorPhysics == nullptr || !pInflictorPhysics->IsMoveable(this: pInflictorPhysics) )
      v8->bRestoreVelocity = false;
    if ( v8->bRestoreVelocity )
    {
      otherMass = pEntity->m_pPhysicsObject->GetMass(this: pEntity->m_pPhysicsObject);
      v9 = this->m_damageInflictors.m_Size - 1;
      if ( v9 < 0 )
      {
LABEL_10:
        CCollisionEvent::AddDamageInflictor(this, pInflictorPhysics, otherMass, savedVel, savedAngVel, addList: true);
      }
      else
      {
        m_pMemory = this->m_damageInflictors.m_Memory.m_pMemory;
        p_pInflictorPhysics = &m_pMemory[v9].pInflictorPhysics;
        while ( *p_pInflictorPhysics != pInflictorPhysics )
        {
          p_pInflictorPhysics -= 9;
          if ( --v9 < 0 )
            goto LABEL_10;
        }
        v12 = otherMass <= m_pMemory[v9].otherMassMax;
        v13 = &m_pMemory[v9];
        if ( !v12 )
          v13->otherMassMax = otherMass;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BC40
// Name: void PhysCallbackDamage(class CBaseEntity __near *,class CTakeDamageInfo const __near &,struct gamevcollisionevent_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCallbackDamage(
        CBaseEntity *pEntity,
        const CTakeDamageInfo *info,
        gamevcollisionevent_t *event,
        int hurtIndex)
{
  CCollisionEvent::AddDamageEvent(
    this: &g_Collisions,
    pEntity,
    info,
    pInflictorPhysics: event->pObjects[hurtIndex == 0],
    bRestoreVelocity: true,
    savedVel: &event->preVelocity[hurtIndex == 0],
    savedAngVel: &event->preAngularVelocity[hurtIndex == 0]);
}

//------------------------------------------------------------------------------
// Address: 0x1018BC80
// Name: void PhysCallbackDamage(class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall PhysCallbackDamage(int a1@<esi>, CBaseEntity *pEntity, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  IPhysicsObject *v5; // eax
  unsigned int v6; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *v13; // eax
  const char *v14; // eax
  const char *pszValue; // ecx

  if ( physenv != nullptr && physenv->IsInSimulation(this: physenv) || g_Collisions.m_inCallback > 0 )
  {
    m_Index = info->m_hInflictor.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      v5 = (IPhysicsObject *)m_pEntity[82].__vftable;
    }
    else
    {
      v5 = nullptr;
    }
    CCollisionEvent::AddDamageEvent(
      this: &g_Collisions,
      pEntity,
      info,
      pInflictorPhysics: v5,
      bRestoreVelocity: false,
      savedVel: &vec3_origin,
      savedAngVel: &vec3_origin);
    if ( pEntity != nullptr )
    {
      v6 = info->m_hInflictor.m_Index;
      if ( v6 != -1 )
      {
        v7 = (unsigned __int16)v6;
        v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v6];
        v9 = HIWORD(v6);
        if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
        {
          v10 = v7;
          v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
          v12 = &g_pEntityList->m_EntPtrArray[v10];
          if ( v11 )
            v13 = v12->m_pEntity;
          else
            v13 = nullptr;
          v14 = (const char *)v13[23].__vftable;
          if ( v14 == nullptr )
            v14 = locale;
          pszValue = pEntity->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          _DevMsg(a1: 2, a2: "Warning: Physics damage event with no recovery info!\nObjects: %s, %s\n", pszValue, v14);
        }
      }
    }
  }
  else
  {
    CBaseEntity::TakeDamage(this: pEntity, a2: a1, inputInfo: info);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018BF00
// Name: public: virtual void CPhysicsHook::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsHook::FrameUpdatePostEntityThink(CPhysicsHook *this)
{
  float deltaTime; // xmm0_4

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CPhysicsHook::FrameUpdatePostEntityThink",
    a3: 0,
    a4: "Physics",
    a5: false,
    a6: 4);
  deltaTime = 0.0;
  if ( gpGlobals->frametime > 0.0 )
    deltaTime = gpGlobals->interval_per_tick;
  if ( CBaseEntity::IsSimulatingOnAlternateTicks() )
  {
    this->m_isFinalTick = false;
    PhysFrame(deltaTime);
  }
  this->m_isFinalTick = true;
  PhysFrame(deltaTime);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1018BF90
// Name: public: virtual bool CCollisionEvent::ShouldFreezeObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __userpurge CCollisionEvent::ShouldFreezeObject@<al>(
        CCollisionEvent *this@<ecx>,
        CBaseEntity *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IPhysicsObject *pObject)
{
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // esi
  IPhysicsObject_vtbl *v8; // eax
  float (__thiscall *GetMass)(IPhysicsObject *); // edx
  CBaseEntity *v10; // eax
  bool v11; // cc
  __int128 v12; // xmm0
  _BYTE v13[12]; // [esp+24h] [ebp-ACh] BYREF
  __int128 dmgInfo_84; // [esp+84h] [ebp-4Ch] OVERLAPPED
  Vector v15; // [esp+9Ch] [ebp-34h] BYREF
  Vector contactPos; // [esp+A8h] [ebp-28h] BYREF
  Vector force; // [esp+B4h] [ebp-1Ch] BYREF
  CBaseEntity *pEntity; // [esp+C0h] [ebp-10h] BYREF
  CBaseEntity *pOther; // [esp+C4h] [ebp-Ch]
  IPhysicsObject *pOtherObject; // [esp+C8h] [ebp-8h]
  IPhysicsObject *retaddr; // [esp+D0h] [ebp+0h]

  pOther = a2;
  pOtherObject = retaddr;
  v5 = (CBaseEntity *)((int (__thiscall *)(IPhysicsObject *, int, int))pObject->GetGameData)(
                        a1: pObject,
                        a2: a3,
                        a3: a4);
  v6 = v5;
  LODWORD(force.x) = v5;
  if ( v5 != nullptr )
  {
    if ( v5->m_MoveType.m_Value == 7
      || v5->m_MoveType.m_Value == 0
      || v5->GetServerVehicle(this: v5) != nullptr
      && (((int (__thiscall *)(IPhysicsObject *))pObject->GetCallbackFlags)(a1: pObject) & 0x40) == 0 )
    {
      return 0;
    }
    if ( (unsigned int)(v6->m_CollisionGroup.m_Value - 1) <= 2 && !v6->IsNPC(this: v6) )
    {
      LODWORD(force.z) = &contactPos;
      v8 = pObject->__vftable;
      LODWORD(force.y) = &v15;
      LODWORD(force.x) = &force.z;
      GetMass = v8->GetMass;
      force.z = 0.0;
      contactPos.z = ((double (__thiscall *)(IPhysicsObject *))GetMass)(a1: pObject) * 10.0;
      if ( FindMaxContact(
             pObject,
             minForce: contactPos.z,
             pOtherObject: (IPhysicsObject **)LODWORD(force.x),
             contactPos: (Vector *)LODWORD(force.y),
             pForce: (Vector *)LODWORD(force.z)) )
      {
        v10 = (CBaseEntity *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(force.z) + 68))(a1: LODWORD(force.z));
        v11 = v6->m_takedamage.m_Value <= 1;
        LODWORD(force.y) = v10;
        if ( !v11 )
        {
          v12 = 0;
          *(float *)&v12 = fsqrt(
                             (float)((float)(contactPos.x * contactPos.x) + (float)(contactPos.y * contactPos.y))
                           + (float)(contactPos.z * contactPos.z));
          dmgInfo_84 = v12;
          CTakeDamageInfo::CTakeDamageInfo(
            this: (CTakeDamageInfo *)v13,
            pInflictor: v10,
            pAttacker: v10,
            damageForce: &contactPos,
            damagePosition: &v15,
            flDamage: *(float *)&v12 * 0.1,
            bitsDamageType: 1,
            iKillType: 0,
            reportedPosition: nullptr,
            iObjectsPenetrated: 0);
          PhysCallbackDamage(a1: (int)v6, pEntity: v6, info: (const CTakeDamageInfo *)v13);
          return 1;
        }
        if ( PropIsGib(pEntity: v6) )
        {
          PhysCallbackRemove(pRemove: &v6->m_Network);
          return 1;
        }
        HIBYTE(pEntity) = 1;
        CCallQueueT<CTSQueue<CFunctor *,0,1>>::QueueCall<CBaseEntity *,CBaseEntity *,CBaseEntity *,bool,float,CBaseEntity *,CBaseEntity *,bool,float>(
          this: &g_PostSimulationQueue,
          pfnProxied: EntityPhysics_CreateSolver,
          arg1: (CBaseEntity *const *)&force.y,
          arg2: (CFunctor_vtbl **)&force,
          arg3: (const bool *)&pEntity + 3,
          arg4: (const float *)0x3F800000);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018C170
// Name: physics_budget
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl physics_budget()
{
  int m_Size; // esi
  int v1; // edi
  CBaseEntity **m_pMemory; // ebx
  void *v3; // esp
  IPhysicsEnvironment_vtbl *v4; // edx
  float v5; // ecx
  int v6; // eax
  int v7; // edi
  float *v8; // edi
  int v9; // edi
  int j; // esi
  double v11; // xmm2_8
  double v12; // xmm0_8
  double v13; // xmm0_8
  int v14; // esi
  CBaseEntity *v15; // ecx
  unsigned int v16; // eax
  CBaseEntity *v17; // ecx
  unsigned int v18; // edx
  CBaseEntity *v19; // edi
  CFmtStrN<256> *v20; // eax
  CBaseEntity *v21; // ecx
  const char *pszValue; // edi
  const char *DebugName; // eax
  double v24; // [esp+10h] [ebp-178h]
  double v25; // [esp+18h] [ebp-170h]
  const char *m_szBuf; // [esp+20h] [ebp-168h]
  _BYTE v27[12]; // [esp+24h] [ebp-164h] BYREF
  CFmtStrN<256> v28; // [esp+30h] [ebp-158h] BYREF
  double v29; // [esp+13Ch] [ebp-4Ch]
  CUtlVector<double,CUtlMemory<double,int> > times; // [esp+144h] [ebp-44h] BYREF
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > ents; // [esp+158h] [ebp-30h] BYREF
  double v32; // [esp+16Ch] [ebp-1Ch] OVERLAPPED
  double i; // [esp+174h] [ebp-14h]
  float fraction; // [esp+17Ch] [ebp-Ch]
  double v35; // [esp+180h] [ebp-8h] OVERLAPPED
  int savedregs; // [esp+188h] [ebp+0h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() )
  {
    m_Size = 0;
    v1 = physenv->GetActiveObjectCount(this: physenv);
    m_pMemory = nullptr;
    HIDWORD(v32) = v1;
    memset(&ents, 0, sizeof(ents));
    if ( v1 != 0 )
    {
      v3 = alloca(4 * v1);
      v4 = physenv->__vftable;
      HIDWORD(v35) = v27;
      v4->GetActiveObjects(this: physenv, a2: (IPhysicsObject **)v27);
      HIDWORD(i) = 0;
      if ( v1 <= 0 )
        goto LABEL_19;
      do
      {
        v5 = COERCE_FLOAT((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(HIDWORD(v35) + 4 * HIDWORD(i)) + 68))(a1: *(_DWORD *)(HIDWORD(v35) + 4 * HIDWORD(i))));
        fraction = v5;
        if ( v5 != 0.0 )
        {
          v6 = 0;
          if ( m_Size <= 0 )
            goto LABEL_10;
          while ( (CBaseEntity *)LODWORD(v5) != m_pMemory[v6] )
          {
            if ( ++v6 >= m_Size )
              goto LABEL_10;
          }
          if ( v6 < 0 )
          {
LABEL_10:
            v7 = m_Size;
            if ( m_Size + 1 > ents.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&ents,
                num: m_Size - ents.m_Memory.m_nAllocationCount + 1);
              m_Size = ents.m_Size;
              m_pMemory = ents.m_Memory.m_pMemory;
              v5 = fraction;
            }
            ents.m_Size = ++m_Size;
            ents.m_pElements = m_pMemory;
            if ( m_Size - v7 - 1 > 0 )
            {
              _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
              v5 = fraction;
            }
            v8 = (float *)&m_pMemory[v7];
            if ( v8 != nullptr )
              *v8 = v5;
            v1 = HIDWORD(v32);
          }
        }
        ++HIDWORD(i);
      }
      while ( SHIDWORD(i) < v1 );
      v9 = 0;
      if ( m_Size == 0 )
      {
LABEL_19:
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ents);
        return;
      }
      memset(&times, 0, 12);
      times.m_pElements = nullptr;
      i = 0.0;
      g_Collisions.m_bBufferTouchEvents = true;
      v35 = _Plat_FloatTime();
      ((void (__stdcall *)(int))physenv->Simulate)(a1: 1015580809);
      v32 = _Plat_FloatTime() - v35;
      times.m_Size = 0;
      CUtlVector<double,CUtlMemory<double,int>>::InsertMultipleBefore(this: &times, elem: 0, num: m_Size);
      if ( m_Size <= 0 )
        goto LABEL_29;
      do
      {
        for ( j = 0; j < v9; ++j )
          PhysForceEntityToSleep(pEntity: m_pMemory[j], pObject: m_pMemory[j]->m_pPhysicsObject);
        *((float *)&v35 + 1) = _Plat_FloatTime();
        ((void (__stdcall *)(int))physenv->Simulate)(a1: 1015580809);
        v35 = _Plat_FloatTime() - *((float *)&v35 + 1);
        v11 = v35;
        v12 = v32 - v35;
        if ( v32 - v35 >= 0.00001 )
        {
          if ( v12 > 1.0 )
            v12 = 1.0;
        }
        else
        {
          v12 = 0.00001;
        }
        times.m_Memory.m_pMemory[v9] = v12;
        v13 = v12 + i;
        ++v9;
        i = v13;
        v32 = v11;
      }
      while ( v9 < ents.m_Size );
      if ( v13 <= 0.001 )
      {
LABEL_29:
        v13 = 0.001;
        i = 0.001;
      }
      v14 = 0;
      if ( ents.m_Size > 0 )
      {
        v29 = 1.0 / v13;
        do
        {
          v15 = m_pMemory[v14];
          v16 = (unsigned int)v15->m_iEFlags >> 11;
          fraction = times.m_Memory.m_pMemory[v14] * v29;
          HIDWORD(v35) = v15;
          if ( (v16 & 1) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v15, a2: (int)&savedregs);
          v17 = m_pMemory[v14];
          v18 = (unsigned int)v17->m_iEFlags >> 11;
          HIDWORD(v32) = v17;
          if ( (v18 & 1) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
          v19 = m_pMemory[v14];
          if ( (v19->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: m_pMemory[v14], a2: (int)&savedregs);
          v20 = CFmtStrN<256>::CFmtStrN<256>(
                  this: &v28,
                  pszFormat: "(%f, %f, %f)",
                  v19->m_vecAbsOrigin.x,
                  *(float *)(HIDWORD(v32) + 464),
                  *(float *)(HIDWORD(v35) + 468));
          v21 = m_pMemory[v14];
          pszValue = v21->m_iClassname.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          m_szBuf = v20->m_szBuf;
          v25 = (float)(fraction * 100.0);
          v24 = fraction * i * 1000.0;
          DebugName = CBaseEntity::GetDebugName(this: v21);
          _Msg(a1: "%s (%s): %.3fms (%.3f%%) @ %s\n", pszValue, DebugName, v24, v25, m_szBuf);
          ++v14;
        }
        while ( v14 < ents.m_Size );
      }
      g_Collisions.m_bBufferTouchEvents = false;
      if ( times.m_Memory.m_nGrowSize >= 0 && times.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: times.m_Memory.m_pMemory);
    }
    if ( ents.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018C780
// Name: public: struct vehiclesounds_t __near & vehiclesounds_t::operator=(struct vehiclesounds_t const __near &)
// Source: json
//------------------------------------------------------------------------------
vehiclesounds_t *__thiscall vehiclesounds_t::operator=(vehiclesounds_t *this, const vehiclesounds_t *__that)
{
  string_t *iszStateSounds; // eax
  int v4; // edx
  int i; // ecx
  float *v6; // ecx
  float *minStateTime; // eax
  int v8; // edi
  double v9; // st7

  CUtlVector<vehicle_gear_t,CUtlMemory<vehicle_gear_t,int>>::operator=(this: &this->pGears, other: &__that->pGears);
  CUtlVector<vehicle_crashsound_t,CUtlMemory<vehicle_crashsound_t,int>>::operator=(
    this: &this->crashSounds,
    other: &__that->crashSounds);
  qmemcpy(this->iszSound, __that->iszSound, sizeof(this->iszSound));
  iszStateSounds = this->iszStateSounds;
  v4 = (char *)__that - (char *)this;
  for ( i = 20; i != 0; --i )
  {
    iszStateSounds->pszValue = *(const char **)((char *)iszStateSounds + v4);
    ++iszStateSounds;
  }
  v6 = &__that->minStateTime[2];
  minStateTime = this->minStateTime;
  v8 = 2;
  do
  {
    v9 = *(float *)((char *)minStateTime + v4);
    minStateTime += 10;
    *(minStateTime - 10) = v9;
    v6 += 10;
    --v8;
    *(minStateTime - 9) = *(v6 - 11);
    *(minStateTime - 8) = *(v6 - 10);
    *(minStateTime - 7) = *(v6 - 9);
    *(minStateTime - 6) = *(v6 - 8);
    *(minStateTime - 5) = *(v6 - 7);
    *(minStateTime - 4) = *(v6 - 6);
    *(minStateTime - 3) = *(v6 - 5);
    *(minStateTime - 2) = *(v6 - 4);
    *(minStateTime - 1) = *(v6 - 3);
  }
  while ( v8 != 0 );
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018C850
// Name: public: void CConstraintFloodList::AddLink(class CBaseEntity __near *,class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConstraintFloodList::AddLink(
        CConstraintFloodList *this,
        CWorld *pEntity,
        CWorld *pLink,
        bool bIsConstraint)
{
  unsigned __int16 v6; // ax
  CUtlMemory<vgui::TreeNode *,int> *v7; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  CWorld **v12; // edi
  CUtlMap<CBaseEntity *,int,unsigned short>::Node_t search; // [esp+8h] [ebp-10h] BYREF
  CUtlMap<CBaseEntity *,int,unsigned short>::Node_t insert; // [esp+10h] [ebp-8h] BYREF
  int pEntitya; // [esp+20h] [ebp+8h]

  if ( pEntity != nullptr
    && pLink != nullptr
    && (pEntity->m_Network.m_pPev == nullptr || pEntity != g_WorldEntity)
    && (pLink->m_Network.m_pPev == nullptr || pLink != g_WorldEntity) )
  {
    search.key = pEntity;
    v6 = CUtlRBTree<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: &this->m_list.m_Tree,
           &search);
    if ( v6 == 0xFFFF )
    {
      pEntitya = CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int>>::InsertBefore(
                   this: &this->m_entryList,
                   elem: this->m_entryList.m_Size);
      this->m_entryList.m_Memory.m_pMemory[pEntitya].isConstraint = bIsConstraint;
      insert.key = pEntity;
      insert.elem = pEntitya;
      v6 = CUtlRBTree<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
             this: &this->m_list.m_Tree,
             &insert);
    }
    v7 = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_entryList.m_Memory.m_pMemory[this->m_list.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem];
    if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
           this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)v7,
           src: &pLink) < 0 )
    {
      m_pMemory = v7[1].m_pMemory;
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(this: v7, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v7[1].m_pMemory;
      v10 = v7->m_pMemory;
      v11 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[(_DWORD)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 4 * v11);
      v12 = (CWorld **)&v7->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        *v12 = pLink;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CAA0
// Name: public: virtual void CPhysicsHook::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsHook::LevelShutdownPostEntity(CPhysicsHook *this)
{
  CEntityList *v2; // ebx

  if ( physenv != nullptr )
  {
    g_pPhysSaveRestoreManager->ForgetAllModels(this: g_pPhysSaveRestoreManager);
    CCollisionEvent::LevelShutdown(this: &g_Collisions);
    physics->DestroyEnvironment(this: physics, a2: physenv);
    physenv = nullptr;
    physics->DestroyObjectPairHash(this: physics, a2: g_EntityCollisionHash);
    g_EntityCollisionHash = nullptr;
    physics->DestroyAllCollisionSets(this: physics);
    g_PhysWorldObject = nullptr;
    v2 = g_pShadowEntities;
    if ( g_pShadowEntities != nullptr )
    {
      CEntityList::~CEntityList(this: g_pShadowEntities);
      free(pMem: v2);
    }
    g_pShadowEntities = nullptr;
    this->m_impactSounds.elements.m_Size = 0;
    this->m_breakSounds.m_Size = 0;
    this->m_massCenterOverrides.m_Size = 0;
    if ( this->m_massCenterOverrides.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_massCenterOverrides.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_massCenterOverrides.m_Memory.m_pMemory);
        this->m_massCenterOverrides.m_Memory.m_pMemory = nullptr;
      }
      this->m_massCenterOverrides.m_Memory.m_nAllocationCount = 0;
    }
    this->m_massCenterOverrides.m_pElements = this->m_massCenterOverrides.m_Memory.m_pMemory;
    CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::RemoveAll(this: &this->m_vehicleScripts);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018CB70
// Name: public: bool CPhysicsHook::FindOrAddVehicleScript(char const __near *,struct vehicleparams_t __near *,struct vehiclesounds_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsHook::FindOrAddVehicleScript(
        CPhysicsHook *this,
        const char *pScriptName,
        vehicleparams_t *pVehicle,
        vehiclesounds_t *pSounds)
{
  int v5; // esi
  int v6; // ebx
  const char *pszValue; // eax
  int v8; // eax
  vehiclescript_t *m_pMemory; // esi
  int v10; // ebx
  IVPhysicsKeyParser *v11; // esi
  int v12; // esi
  CVehicleSoundsParser soundParser; // [esp+Ch] [ebp-20h] BYREF
  unsigned __int8 *pFile; // [esp+20h] [ebp-Ch]
  int index; // [esp+24h] [ebp-8h]
  bool bLoadedSounds; // [esp+2Bh] [ebp-1h]

  v5 = 0;
  bLoadedSounds = false;
  index = -1;
  if ( this->m_vehicleScripts.m_Size <= 0 )
    goto LABEL_9;
  v6 = 0;
  while ( 1 )
  {
    pszValue = this->m_vehicleScripts.m_Memory.m_pMemory[v6].scriptName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( _V_stricmp(s1: pszValue, s2: pScriptName) == 0 )
      break;
    ++v5;
    ++v6;
    if ( v5 >= this->m_vehicleScripts.m_Size )
      goto LABEL_9;
  }
  index = v5;
  bLoadedSounds = true;
  if ( v5 >= 0 )
  {
    v12 = index;
  }
  else
  {
LABEL_9:
    pFile = UTIL_LoadFileForMe(filename: pScriptName, pLength: nullptr);
    if ( pFile != nullptr )
    {
      v8 = CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::InsertBefore(
             this: &this->m_vehicleScripts,
             elem: this->m_vehicleScripts.m_Size);
      m_pMemory = this->m_vehicleScripts.m_Memory.m_pMemory;
      v10 = v8;
      index = v8;
      m_pMemory[v10].scriptName.pszValue = *(const char **)AllocPooledString(
                                                             pszValue: (char *)&pScriptName,
                                                             pszValuea: pScriptName).pszValue;
      vehiclesounds_t::Init(this: &this->m_vehicleScripts.m_Memory.m_pMemory[v10].sounds);
      v11 = physcollision->VPhysicsKeyParserCreate_2(this: physcollision, a2: pFile);
      while ( !v11->Finished(this: v11) )
      {
        pScriptName = v11->GetCurrentBlockName(this: v11);
        if ( _V_stricmp(s1: pScriptName, s2: "vehicle") != 0 )
        {
          if ( _V_stricmp(s1: pScriptName, s2: "vehicle_sounds") != 0 )
          {
            v11->SkipBlock(this: v11);
          }
          else
          {
            bLoadedSounds = true;
            CVehicleSoundsParser::CVehicleSoundsParser(this: &soundParser);
            v11->ParseCustom(this: v11, a2: &this->m_vehicleScripts.m_Memory.m_pMemory[v10].sounds, a3: &soundParser);
          }
        }
        else
        {
          v11->ParseVehicle(this: v11, a2: &this->m_vehicleScripts.m_Memory.m_pMemory[v10].params, a3: nullptr);
        }
      }
      physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v11);
      UTIL_FreeFile(buffer: pFile);
    }
    v12 = index;
    if ( index < 0 )
      return 0;
  }
  if ( pVehicle != nullptr )
    vehicleparams_t::operator=(this: pVehicle, __that: &this->m_vehicleScripts.m_Memory.m_pMemory[v12].params);
  if ( pSounds != nullptr )
  {
    if ( !bLoadedSounds )
      return 0;
    vehiclesounds_t::operator=(this: pSounds, __that: &this->m_vehicleScripts.m_Memory.m_pMemory[v12].sounds);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018CD60
// Name: public: CConstraintFloodList::CConstraintFloodList(void)
// Source: json
//------------------------------------------------------------------------------
CConstraintFloodList *__thiscall CConstraintFloodList::CConstraintFloodList(CConstraintFloodList *this)
{
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *v3; // eax
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *v4; // eax
  CConstraintFloodEntry *v5; // eax
  IMemAlloc_vtbl *v6; // edx
  CConstraintFloodEntry *v7; // eax

  this->m_list.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_list.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_list.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_list.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_list.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_list.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_list.m_Tree.m_FirstFree = -1;
  this->m_list.m_Tree.m_pElements = m_pMemory;
  this->m_entryList.m_Memory.m_pMemory = nullptr;
  this->m_entryList.m_Memory.m_nAllocationCount = 0;
  this->m_entryList.m_Memory.m_nGrowSize = 0;
  this->m_entryList.m_Size = 0;
  this->m_entryList.m_pElements = nullptr;
  if ( this->m_list.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_list.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
  if ( this->m_list.m_Tree.m_Elements.m_nAllocationCount < 64 && this->m_list.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    v3 = this->m_list.m_Tree.m_Elements.m_pMemory;
    this->m_list.m_Tree.m_Elements.m_nAllocationCount = 64;
    if ( v3 != nullptr )
      v4 = (UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: v3,
                                                                                                  a3: 1024);
    else
      v4 = (UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: 1024);
    this->m_list.m_Tree.m_Elements.m_pMemory = v4;
  }
  if ( this->m_entryList.m_Memory.m_nAllocationCount < 64 && this->m_entryList.m_Memory.m_nGrowSize >= 0 )
  {
    v5 = this->m_entryList.m_Memory.m_pMemory;
    this->m_entryList.m_Memory.m_nAllocationCount = 64;
    v6 = _g_pMemAlloc->__vftable;
    if ( v5 != nullptr )
    {
      v7 = (CConstraintFloodEntry *)((int (__stdcall *)(CConstraintFloodEntry *, int))v6->Realloc_2)(a1: v5, a2: 1536);
      this->m_entryList.m_Memory.m_pMemory = v7;
      this->m_entryList.m_pElements = v7;
      return this;
    }
    this->m_entryList.m_Memory.m_pMemory = (CConstraintFloodEntry *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 1536);
  }
  this->m_entryList.m_pElements = this->m_entryList.m_Memory.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018CE30
// Name: bool PhysFindOrAddVehicleScript(char const __near *,struct vehicleparams_t __near *,struct vehiclesounds_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PhysFindOrAddVehicleScript(const char *pScriptName, vehicleparams_t *pParams, vehiclesounds_t *pSounds)
{
  return CPhysicsHook::FindOrAddVehicleScript(this: &g_PhysicsHook, pScriptName, pVehicle: pParams, pSounds);
}

//------------------------------------------------------------------------------
// Address: 0x1018CE50
// Name: void PhysFlushVehicleScripts(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysFlushVehicleScripts()
{
  CUtlVector<vehiclescript_t,CUtlMemory<vehiclescript_t,int>>::RemoveAll(this: &g_PhysicsHook.m_vehicleScripts);
}

//------------------------------------------------------------------------------
// Address: 0x1018CEC0
// Name: public: virtual char const __near * CPhysicsHook::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPhysicsHook::Name(CPhysicsHook *this)
{
  return "CPhysicsHook";
}

//------------------------------------------------------------------------------
// Address: 0x1018CF20
// Name: DebugConstraints
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugConstraints(CBaseEntity *pEntity)
{
  int v1; // ebx
  CWorld *j; // esi
  int v3; // esi
  const char *v4; // esi
  const char *v5; // edi
  const char *pszValue; // eax
  CBaseEntity **m_pMemory; // eax
  CConstraintFloodEntry *v8; // eax
  UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short> *v9; // eax
  CConstraintFloodList list; // [esp+8h] [ebp-68h] BYREF
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > constraints; // [esp+38h] [ebp-38h] BYREF
  IPhysicsObject *pAttachVPhysics[2]; // [esp+4Ch] [ebp-24h] BYREF
  CBaseEntity *pAttach[2]; // [esp+54h] [ebp-1Ch] BYREF
  _BYTE v14[4]; // [esp+5Ch] [ebp-14h] BYREF
  _BYTE v15[4]; // [esp+60h] [ebp-10h] BYREF
  int index0; // [esp+64h] [ebp-Ch]
  const char *pName0; // [esp+68h] [ebp-8h]
  const char *pName1; // [esp+6Ch] [ebp-4h]
  int i; // [esp+78h] [ebp+8h]

  v1 = 0;
  if ( pEntity != nullptr )
  {
    CConstraintFloodList::CConstraintFloodList(this: &list);
    for ( j = (CWorld *)CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
          j != nullptr;
          j = (CWorld *)CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: j) )
    {
      if ( GetConstraintAttachments(pEntity: j, pAttachOut: pAttach, pAttachVPhysics) != 0
        || GetSpringAttachments(pEntity: j, pAttachOut: pAttach, pAttachVPhysics) )
      {
        CConstraintFloodList::AddLink(this: &list, pEntity: j, pLink: (CWorld *)pAttach[0], bIsConstraint: true);
        CConstraintFloodList::AddLink(this: &list, pEntity: j, pLink: (CWorld *)pAttach[1], bIsConstraint: true);
        CConstraintFloodList::AddLink(this: &list, pEntity: (CWorld *)pAttach[0], pLink: j, bIsConstraint: false);
        CConstraintFloodList::AddLink(this: &list, pEntity: (CWorld *)pAttach[1], pLink: j, bIsConstraint: false);
      }
    }
    memset(&constraints, 0, sizeof(constraints));
    CConstraintFloodList::BuildGraphFromEntity(this: &list, pEntity, constraintList: &constraints);
    v3 = 0;
    i = 0;
    if ( constraints.m_Size > 0 )
    {
      while ( 1 )
      {
        if ( GetConstraintAttachments(pEntity: constraints.m_Memory.m_pMemory[v3], pAttachOut: pAttach, pAttachVPhysics) == 0 )
          GetSpringAttachments(pEntity: constraints.m_Memory.m_pMemory[v3], pAttachOut: pAttach, pAttachVPhysics);
        v4 = locale;
        pName0 = "world";
        pName1 = "world";
        v5 = locale;
        index0 = 0;
        if ( pAttach[0] != nullptr )
        {
          pName0 = pAttach[0]->m_iClassname.pszValue;
          if ( pName0 == nullptr )
            pName0 = locale;
          v5 = *(const char **)((int (__stdcall *)(_BYTE *))pAttach[0]->GetModelName)(a1: v15);
          if ( v5 == nullptr )
            v5 = locale;
          index0 = pAttachVPhysics[0]->GetGameIndex(this: pAttachVPhysics[0]);
        }
        if ( pAttach[1] != nullptr )
        {
          pName1 = pAttach[1]->m_iClassname.pszValue;
          if ( pName1 == nullptr )
            pName1 = locale;
          v4 = *(const char **)((int (__stdcall *)(_BYTE *))pAttach[1]->GetModelName)(a1: v14);
          if ( v4 == nullptr )
            v4 = locale;
          v1 = pAttachVPhysics[1]->GetGameIndex(this: pAttachVPhysics[1]);
        }
        pszValue = constraints.m_Memory.m_pMemory[i]->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        _Msg(
          a1: "**********************\n%s connects %s(%s:%d) to %s(%s:%d)\n",
          pszValue,
          pName0,
          v5,
          index0,
          pName1,
          v4,
          v1);
        DebugConstraint(pEntity: constraints.m_Memory.m_pMemory[i]);
        constraints.m_Memory.m_pMemory[i]->m_debugOverlays |= 5u;
        v1 = 0;
        if ( ++i >= constraints.m_Size )
          break;
        v3 = i;
      }
    }
    m_pMemory = constraints.m_Memory.m_pMemory;
    constraints.m_Size = 0;
    if ( constraints.m_Memory.m_nGrowSize >= 0 )
    {
      if ( constraints.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: constraints.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        constraints.m_Memory.m_pMemory = nullptr;
      }
      constraints.m_Memory.m_nAllocationCount = 0;
    }
    constraints.m_pElements = m_pMemory;
    if ( constraints.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        constraints.m_Memory.m_pMemory = nullptr;
      }
      constraints.m_Memory.m_nAllocationCount = 0;
    }
    CUtlVector<CConstraintFloodEntry,CUtlMemory<CConstraintFloodEntry,int>>::RemoveAll(this: &list.m_entryList);
    v8 = list.m_entryList.m_Memory.m_pMemory;
    if ( list.m_entryList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( list.m_entryList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_entryList.m_Memory.m_pMemory);
        v8 = nullptr;
        list.m_entryList.m_Memory.m_pMemory = nullptr;
      }
      list.m_entryList.m_Memory.m_nAllocationCount = 0;
    }
    list.m_entryList.m_pElements = v8;
    if ( list.m_entryList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v8 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
        list.m_entryList.m_Memory.m_pMemory = nullptr;
      }
      list.m_entryList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlRBTree<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &list.m_list.m_Tree);
    v9 = list.m_list.m_Tree.m_Elements.m_pMemory;
    list.m_list.m_Tree.m_FirstFree = -1;
    if ( list.m_list.m_Tree.m_Elements.m_nGrowSize >= 0 )
    {
      if ( list.m_list.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_list.m_Tree.m_Elements.m_pMemory);
        v9 = nullptr;
        list.m_list.m_Tree.m_Elements.m_pMemory = nullptr;
      }
      list.m_list.m_Tree.m_Elements.m_nAllocationCount = 0;
    }
    list.m_list.m_Tree.m_LastAlloc.index = -1;
    if ( list.m_list.m_Tree.m_Elements.m_nGrowSize >= 0 && v9 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D210
// Name: physics_constraints
// Source: json
//------------------------------------------------------------------------------
void __cdecl physics_constraints(const CCommand *args)
{
  if ( UTIL_IsCommandIssuedByServerAdmin() )
    PhysicsCommand(args, func: (void (__cdecl *)())DebugConstraints);
}
