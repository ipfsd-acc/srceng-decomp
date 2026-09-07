// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/physics.cpp
// Functions: 45
// ============================================================

#include "game\client\physics.h"

//------------------------------------------------------------------------------
// Address: 0x10061A70
// Name: public: virtual bool CCollisionEvent::ShouldFreezeContacts(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionEvent::ShouldFreezeContacts(C_BaseEntity *this, bool isbeingremoved, C_BaseEntity *predicted)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061A80
// Name: public: virtual void CCollisionEvent::ObjectLeaveTrigger(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectLeaveTrigger(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1013C930
// Name: bool PhysIsInCallback(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PhysIsInCallback()
{
  return physenv != nullptr && physenv->IsInSimulation(this: physenv) || g_Collisions.m_inCallback > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013C960
// Name: bool PhysicsDLLInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __cdecl PhysicsDLLInit(void *(__cdecl *physicsFactory)(const char *, int *))
{
  physics = (IPhysics *)physicsFactory(a1: "VPhysics031", a2: nullptr);
  if ( physics == nullptr )
    return 0;
  physprops = (IPhysicsSurfaceProps *)physicsFactory(a1: "VPhysicsSurfaceProps001", a2: nullptr);
  if ( physprops == nullptr )
    return 0;
  physcollision = (IPhysicsCollision *)physicsFactory(a1: "VPhysicsCollision007", a2: nullptr);
  if ( physcollision == nullptr )
    return 0;
  PhysParseSurfaceData(pProps: physprops, pFileSystem: filesystem);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013C9D0
// Name: void PhysicsReset(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsReset()
{
  if ( physenv != nullptr )
    physenv->ResetSimulationClock(this: physenv);
}

//------------------------------------------------------------------------------
// Address: 0x1013C9F0
// Name: FindPhysicsBlocker
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl FindPhysicsBlocker(IPhysicsObject *pPhysics)
{
  IPhysicsObject *v1; // esi
  IPhysicsFrictionSnapshot *v2; // edi
  int v3; // esi
  int v4; // ebx
  double v5; // st7
  float force; // [esp+8h] [ebp-Ch]
  float forcea; // [esp+8h] [ebp-Ch]
  C_BaseEntity *pBlocker; // [esp+Ch] [ebp-8h]
  float maxVel; // [esp+10h] [ebp-4h]

  v1 = pPhysics;
  v2 = pPhysics->CreateFrictionSnapshot(this: pPhysics);
  pBlocker = nullptr;
  maxVel = 10.0;
  if ( v2->IsValid(this: v2) )
  {
    do
    {
      v3 = (int)v2->GetObject(this: v2, a2: 1);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v3 + 40))(a1: v3) != 0 )
      {
        v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(a1: v3);
        force = v2->GetNormalForce(this: v2);
        v5 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 120))(a1: v3) * force;
        if ( v5 > maxVel )
        {
          pBlocker = (C_BaseEntity *)v4;
          forcea = v5;
          maxVel = forcea;
        }
      }
      v2->NextFrictionData(this: v2);
    }
    while ( v2->IsValid(this: v2) );
    v1 = pPhysics;
  }
  v1->DestroyFrictionSnapshot(this: v1, a2: v2);
  return pBlocker;
}

//------------------------------------------------------------------------------
// Address: 0x1013CAC0
// Name: public: virtual void CPhysicsSystem::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSystem::LevelShutdownPreEntity(CPhysicsSystem *this)
{
  if ( physenv != nullptr )
    physenv->SetQuickDelete(this: physenv, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1013CAE0
// Name: bool IsBlockedShouldDisableCollisions(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBlockedShouldDisableCollisions(C_BaseEntity *pEntity)
{
  unsigned int m_Index; // edi
  int v2; // edx
  int v3; // ecx
  blocklist_t *v4; // eax
  int v5; // ecx

  m_Index = gpGlobals.m_Index;
  v2 = -1;
  v3 = 0;
  v4 = g_BlockList;
  while ( 1 )
  {
    if ( *(_DWORD *)(m_Index + 4) - v4->lastBlockFrame > 4 )
    {
      v2 = v3;
      v4->pEntity = nullptr;
    }
    if ( v4->pEntity == pEntity )
      break;
    ++v4;
    ++v3;
    if ( (int)v4 >= (int)&g_pPhysicsMiniProfilers )
      goto LABEL_8;
  }
  v2 = v3;
LABEL_8:
  if ( v2 == 0 )
    return false;
  if ( g_BlockList[v2].pEntity != pEntity )
  {
    g_BlockList[v2].pEntity = pEntity;
    g_BlockList[v2].firstBlockFrame = *(_DWORD *)(m_Index + 4);
  }
  v5 = *(_DWORD *)(m_Index + 4);
  g_BlockList[v2].lastBlockFrame = v5;
  return v5 - g_BlockList[v2].firstBlockFrame > 2;
}

//------------------------------------------------------------------------------
// Address: 0x1013CB70
// Name: public: struct friction_t __near * CCollisionEvent::FindFriction(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
friction_t *__thiscall CCollisionEvent::FindFriction(CCollisionEvent *this, C_BaseEntity *pObject)
{
  friction_t *result; // eax
  int v3; // edx
  C_BaseEntity **i; // esi

  result = nullptr;
  v3 = 0;
  for ( i = &this->m_current[0].pObject; ; i += 4 )
  {
    if ( *i == nullptr && result == nullptr )
      result = (friction_t *)(i - 1);
    if ( *i == pObject )
      break;
    if ( (unsigned int)++v3 >= 8 )
      return result;
  }
  return &this->m_current[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1013CBB0
// Name: public: void CCollisionEvent::UpdateFrictionSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateFrictionSounds(CCollisionEvent *this)
{
  friction_t *m_current; // esi
  int i; // edi
  CSoundEnvelopeController *Controller; // eax

  m_current = this->m_current;
  for ( i = 8; i != 0; --i )
  {
    if ( m_current->patch != nullptr && (float)(*(float *)(gpGlobals.m_Index + 12) - 0.1) > m_current->flLastUpdateTime )
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
// Address: 0x1013CC10
// Name: public: virtual void CCollisionEvent::FluidEndTouch(class IPhysicsObject __near *,class IPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::FluidEndTouch(CCollisionEvent *this, IPhysicsObject *pObject, IPhysicsObject *pFluid)
{
  this->m_inCallback = this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1013CC20
// Name: class IPhysicsObject __near * GetWorldPhysObject(void)
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__cdecl GetWorldPhysObject()
{
  return g_PhysWorldObject;
}

//------------------------------------------------------------------------------
// Address: 0x1013CC30
// Name: void PhysCleanupFrictionSounds(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysCleanupFrictionSounds(C_BaseEntity *pEntity)
{
  friction_t *v1; // esi
  unsigned int v2; // eax
  C_BaseEntity **p_pObject; // ecx
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
    if ( v2 >= 8 )
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
// Address: 0x1013CCA0
// Name: public: virtual void CCollisionEvent::Friction(class IPhysicsObject __near *,float,int,int,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CCollisionEvent::Friction(
        CCollisionEvent *this,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit,
        IPhysicsCollisionData *pData)
{
  C_BaseEntity *v7; // eax
  C_BaseEntity *v8; // edi
  friction_t *Friction; // eax
  float v10; // xmm0_4
  Vector vecPos; // [esp+24h] [ebp-18h] BYREF
  Vector vecVel; // [esp+30h] [ebp-Ch] BYREF

  ++this->m_inCallback;
  if ( energy < 0.050000001 || surfaceProps < 0 )
  {
    --this->m_inCallback;
  }
  else
  {
    pData->GetContactPoint(this: pData, a2: &vecPos);
    pObject->GetVelocityAtPoint(this: pObject, a2: &vecPos, a3: &vecVel);
    v7 = (C_BaseEntity *)pObject->GetGameData(this: pObject);
    v8 = v7;
    if ( v7 != nullptr )
    {
      if ( v7->m_bClientSideRagdoll )
      {
LABEL_10:
        --this->m_inCallback;
        return;
      }
      Friction = CCollisionEvent::FindFriction(this: &g_Collisions, pObject: v7);
      if ( *(int *)(gpGlobals.m_Index + 20) > 1 && Friction != nullptr && Friction->pObject != nullptr )
      {
        v10 = *(float *)(gpGlobals.m_Index + 12);
        if ( (float)(Friction->flLastEffectTime + 0.5) > v10 )
        {
          Friction->flLastUpdateTime = v10;
          goto LABEL_10;
        }
      }
      PhysFrictionSound(pEntity: v8, pObject, energy, surfaceProps, surfacePropsHit);
    }
    PhysFrictionEffect(&vecPos, vecVel, energy, surfaceProps, surfacePropsHit);
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013CDD0
// Name: void PhysicsSplash(class IPhysicsFluidController __near *,class IPhysicsObject __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall PhysicsSplash(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IPhysicsFluidController *pFluid,
        IPhysicsObject *pObject,
        C_BaseEntity *pEntity)
{
  int v6; // edi
  C_BaseEntity_vtbl *v7; // eax
  IPhysicsCollision_vtbl *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  C_BaseEntity_vtbl *v13; // edx
  float v14; // xmm0_4
  IPhysicsCollision_vtbl *v15; // edi
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  Vector *v20; // eax
  C_BaseEntity_vtbl *v21; // edx
  IPhysicsCollision_vtbl *v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  C_BaseEntity_vtbl *v27; // edx
  float v28; // xmm0_4
  IPhysicsCollision_vtbl *v29; // edi
  const QAngle *(__thiscall *v30)(IClientEntity *); // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  float *v34; // eax
  float v35; // xmm0_4
  float v36; // xmm7_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm6_4
  float v41; // xmm7_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm7_4
  float v46; // xmm1_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm7_4
  float v51; // xmm2_4
  int (__thiscall *GetPointContents)(IEngineTrace *, const Vector *, int, IHandleEntity **); // eax
  char v53; // al
  float z; // ecx
  bool v55; // al
  float *p_z; // esi
  int i; // edi
  IUniformRandomStream *v58; // ecx
  IUniformRandomStream *v59; // ecx
  double v60; // st7
  float scale; // [esp+4h] [ebp-184h]
  float scalea; // [esp+4h] [ebp-184h]
  float v63; // [esp+14h] [ebp-174h]
  float v64; // [esp+14h] [ebp-174h]
  float v65; // [esp+14h] [ebp-174h]
  float v66; // [esp+8Ch] [ebp-FCh]
  Vector v67; // [esp+9Ch] [ebp-ECh] BYREF
  Vector point; // [esp+A8h] [ebp-E0h] BYREF
  Vector velocity; // [esp+B4h] [ebp-D4h] BYREF
  Vector color; // [esp+C0h] [ebp-C8h] BYREF
  float v71; // [esp+CCh] [ebp-BCh]
  float v72; // [esp+D0h] [ebp-B8h]
  float v73; // [esp+D4h] [ebp-B4h]
  float v74; // [esp+D8h] [ebp-B0h]
  float v75; // [esp+DCh] [ebp-ACh]
  float v76; // [esp+E0h] [ebp-A8h]
  Vector binPts[2]; // [esp+E4h] [ebp-A4h] BYREF
  float dist; // [esp+FCh] [ebp-8Ch]
  float v79; // [esp+100h] [ebp-88h]
  float v80; // [esp+104h] [ebp-84h]
  float mins[2]; // [esp+108h] [ebp-80h] BYREF
  float maxs[2]; // [esp+110h] [ebp-78h]
  float luminosity; // [esp+118h] [ebp-70h]
  Vector tanPts[2]; // [esp+11Ch] [ebp-6Ch] BYREF
  float v85; // [esp+134h] [ebp-54h]
  Vector v86; // [esp+138h] [ebp-50h] BYREF
  Vector centerPoint; // [esp+144h] [ebp-44h] BYREF
  Vector binormal; // [esp+150h] [ebp-38h] BYREF
  Vector tangent; // [esp+15Ch] [ebp-2Ch] BYREF
  __int128 normal; // [esp+168h] [ebp-20h] OVERLAPPED BYREF
  bool v91; // [esp+17Bh] [ebp-Dh]
  _DWORD v92[2]; // [esp+17Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+188h] [ebp+0h]

  v92[0] = a1;
  v92[1] = retaddr;
  if ( (((int (__thiscall *)(IPhysicsObject *, int, int))pObject->GetGameFlags)(a1: pObject, a2, a3) & 8) != 0 )
  {
    pObject->GetVelocity(this: pObject, a2: &point, a3: nullptr);
    *(float *)&normal = point.x * point.x;
    v66 = fsqrt((float)((float)(point.x * point.x) + (float)(point.y * point.y)) + (float)(point.z * point.z));
    if ( v66 >= 25.0 )
    {
      pFluid->GetSurfacePlane(this: pFluid, a2: &tangent, a3: (float *)&binPts[1]);
      C_BaseEntity::CalcAbsolutePosition(this: pEntity, a2: (int)v92);
      v6 = 0;
      tanPts[1].x = -1.0;
      LODWORD(normal) = 0;
      do
      {
        MatrixGetColumn(in: &pEntity->m_rgflCoordinateFrame, column: v6, out: (Vector *)((char *)&normal + 4));
        if ( COERCE_FLOAT(
               COERCE_UNSIGNED_INT(
                 (float)((float)(tangent.x * *((float *)&normal + 1)) + (float)(*((float *)&normal + 2) * tangent.y))
               + (float)(tangent.z * *((float *)&normal + 3)))
             & _mask__AbsFloat_) > tanPts[1].x )
        {
          LODWORD(tanPts[1].x) = COERCE_UNSIGNED_INT(
                                   (float)((float)(tangent.x * *((float *)&normal + 1))
                                         + (float)(*((float *)&normal + 2) * tangent.y))
                                 + (float)(tangent.z * *((float *)&normal + 3)))
                               & _mask__AbsFloat_;
          LODWORD(normal) = v6;
        }
        ++v6;
      }
      while ( v6 < 3 );
      MatrixGetColumn(in: &pEntity->m_rgflCoordinateFrame, column: ((int)normal + 1) % 3, out: &binormal);
      centerPoint.x = (float)(binormal.z * tangent.y) - (float)(binormal.y * tangent.z);
      centerPoint.y = (float)(tangent.z * binormal.x) - (float)(binormal.z * tangent.x);
      centerPoint.z = (float)(binormal.y * tangent.x) - (float)(tangent.y * binormal.x);
      VectorNormalize(vec: &centerPoint);
      binormal.x = (float)(centerPoint.y * tangent.z) - (float)(centerPoint.z * tangent.y);
      binormal.y = (float)(centerPoint.z * tangent.x) - (float)(tangent.z * centerPoint.x);
      binormal.z = (float)(tangent.y * centerPoint.x) - (float)(centerPoint.y * tangent.x);
      VectorNormalize(vec: &binormal);
      v7 = pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      *((float *)&normal + 1) = -binormal.x;
      *((float *)&normal + 2) = -binormal.y;
      *((float *)&normal + 3) = -binormal.z;
      v8 = physcollision->__vftable;
      v9 = ((int (__thiscall *)(C_BaseEntity *, char *))v7->GetAbsAngles)(a1: pEntity, a2: (char *)&normal + 4);
      v10 = ((int (__thiscall *)(C_BaseEntity *, int))pEntity->GetAbsOrigin)(a1: pEntity, a2: v9);
      v11 = ((int (__thiscall *)(IPhysicsObject *, int))pObject->GetCollide)(a1: pObject, a2: v10);
      v12 = ((int (__thiscall *)(IPhysicsCollision *, float *, int))v8->CollideGetExtent)(
              a1: physcollision,
              a2: &tanPts[1].y,
              a3: v11);
      v13 = pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      *(_QWORD *)maxs = *(_QWORD *)v12;
      v14 = *(float *)(v12 + 8);
      v15 = physcollision->__vftable;
      GetAbsAngles = v13->GetAbsAngles;
      luminosity = v14;
      v17 = ((int (__thiscall *)(C_BaseEntity *, Vector *))GetAbsAngles)(a1: pEntity, a2: &binormal);
      v18 = ((int (__thiscall *)(C_BaseEntity *, int))pEntity->GetAbsOrigin)(a1: pEntity, a2: v17);
      v19 = ((int (__thiscall *)(IPhysicsObject *, int))pObject->GetCollide)(a1: pObject, a2: v18);
      v20 = (Vector *)((int (__thiscall *)(IPhysicsCollision *, float *, int))v15->CollideGetExtent)(
                        a1: physcollision,
                        a2: &tanPts[1].y,
                        a3: v19);
      v21 = pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      tanPts[0] = *v20;
      *((float *)&normal + 1) = -centerPoint.x;
      *((float *)&normal + 2) = -centerPoint.y;
      *((float *)&normal + 3) = -centerPoint.z;
      v22 = physcollision->__vftable;
      v23 = ((int (__thiscall *)(C_BaseEntity *, char *))v21->GetAbsAngles)(a1: pEntity, a2: (char *)&normal + 4);
      v24 = ((int (__thiscall *)(C_BaseEntity *, int))pEntity->GetAbsOrigin)(a1: pEntity, a2: v23);
      v25 = ((int (__thiscall *)(IPhysicsObject *, int))pObject->GetCollide)(a1: pObject, a2: v24);
      v26 = ((int (__thiscall *)(IPhysicsCollision *, float *, int))v22->CollideGetExtent)(
              a1: physcollision,
              a2: &tanPts[1].y,
              a3: v25);
      v74 = *(float *)v26;
      v27 = pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v75 = *(float *)(v26 + 4);
      v28 = *(float *)(v26 + 8);
      v29 = physcollision->__vftable;
      v30 = v27->GetAbsAngles;
      v76 = v28;
      v31 = ((int (__thiscall *)(C_BaseEntity *, Vector *))v30)(a1: pEntity, a2: &centerPoint);
      v32 = ((int (__thiscall *)(C_BaseEntity *, int))pEntity->GetAbsOrigin)(a1: pEntity, a2: v31);
      v33 = ((int (__thiscall *)(IPhysicsObject *, int))pObject->GetCollide)(a1: pObject, a2: v32);
      v34 = (float *)((int (__thiscall *)(IPhysicsCollision *, float *, int))v29->CollideGetExtent)(
                       a1: physcollision,
                       a2: &tanPts[1].y,
                       a3: v33);
      binPts[0].z = v34[2];
      v35 = v34[1];
      v36 = *v34 * centerPoint.x;
      dist = (float)((float)(maxs[0] * binormal.x) + (float)(maxs[1] * binormal.y)) + (float)(luminosity * binormal.z);
      v80 = (float)((float)(tanPts[0].y * binormal.y) + (float)(tanPts[0].x * binormal.x))
          + (float)(tanPts[0].z * binormal.z);
      v37 = (float)(binPts[0].z * centerPoint.z) + (float)((float)(v35 * centerPoint.y) + v36);
      v38 = (float)(v80 + dist) * 0.5;
      mins[0] = v37;
      v39 = (float)(v37
                  + (float)((float)((float)(v74 * centerPoint.x) + (float)(v75 * centerPoint.y))
                          + (float)(v76 * centerPoint.z)))
          * 0.5;
      binPts[1].z = centerPoint.x * v39;
      dist = centerPoint.y * v39;
      tanPts[0].x = (float)(binormal.x * v38) + (float)(centerPoint.x * v39);
      tanPts[0].y = (float)(binormal.y * v38) + (float)(centerPoint.y * v39);
      v40 = (float)(binormal.z * v38) + (float)(centerPoint.z * v39);
      v41 = v80 - v38;
      v42 = (float)(v80 - v38) * binormal.x;
      v43 = binormal.y * v41;
      v44 = binormal.z * v41;
      v45 = mins[0] - v39;
      v46 = (float)(mins[0] - v39) * centerPoint.x;
      v47 = centerPoint.y * v45;
      v48 = centerPoint.z * v45;
      v86.x = tanPts[0].x + (float)(tangent.x * binPts[1].x);
      binPts[1].y = v86.x - v42;
      *((float *)&normal + 1) = v86.x - v42;
      v86.y = tanPts[0].y + (float)(tangent.y * binPts[1].x);
      v49 = v40 + (float)(tangent.z * binPts[1].x);
      v50 = v86.y - v43;
      v51 = v43 + v86.y;
      v79 = v50;
      *((float *)&normal + 2) = v50;
      mins[0] = v49 - v44;
      *((float *)&normal + 3) = v49 - v44;
      tanPts[0].x = (float)(v86.x - v42) - v46;
      tanPts[0].y = v50 - v47;
      tanPts[0].z = (float)(v49 - v44) - v48;
      color.x = tanPts[0].x;
      color.y = v50 - v47;
      color.z = tanPts[0].z;
      v86.z = v49;
      *(float *)&normal = v42 + v86.x;
      v71 = (float)(v42 + v86.x) - v46;
      v74 = (float)(v42 + v86.x) + v46;
      tanPts[1].x = v44 + v49;
      v72 = v51 - v47;
      v73 = (float)(v44 + v49) - v48;
      binPts[0].x = (float)(v86.x - v42) + v46;
      tanPts[1].y = v86.x;
      v75 = v51 + v47;
      v76 = (float)(v44 + v49) + v48;
      tanPts[1].z = v86.y;
      v85 = v49 - 2.0;
      GetPointContents = enginetrace->GetPointContents;
      binPts[0].y = v50 + v47;
      binPts[0].z = (float)(v49 - v44) + v48;
      v53 = GetPointContents(this: enginetrace, a2: (Vector *)&tanPts[1].y, a3: 16432, a4: nullptr);
      z = vec3_origin.z;
      v55 = (v53 & 0x10) != 0;
      velocity = vec3_origin;
      v91 = v55;
      mins[1] = 1.0;
      if ( !v55 )
      {
        *((float *)&normal + 1) = (float)(tangent.x * 8.0) + v86.x;
        *((float *)&normal + 2) = (float)(tangent.y * 8.0) + v86.y;
        *((float *)&normal + 3) = (float)(tangent.z * 8.0) + v86.z;
        FX_GetSplashLighting(position: *(Vector *)((char *)&normal + 4), color: &velocity, luminosity: &mins[1]);
        v55 = v91;
      }
      if ( v66 <= 150.0 )
      {
        if ( !v55 )
          FX_WaterRipple(origin: &v86);
      }
      else if ( v55 )
      {
        scale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1090519040,
                  a3: 1092616192);
        FX_GunshotSlimeSplash(origin: &v86, normal: &tangent, scale);
      }
      else
      {
        scalea = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                   a1: random,
                   a2: 1090519040,
                   a3: 1092616192);
        FX_GunshotSplash(origin: &v86, normal: &tangent, scale: scalea);
      }
      p_z = &color.z;
      for ( i = 4; i != 0; --i )
      {
        tanPts[1].y = _RandomFloat(this: (IUniformRandomStream *)LODWORD(z), a2: -32.0, a3: 32.0);
        tanPts[1].z = _RandomFloat(this: v58, a2: -32.0, a3: 32.0);
        _RandomFloat(this: v59, a2: -32.0, a3: 32.0);
        v60 = *(p_z - 2) + tanPts[1].y;
        v67.z = *p_z;
        v67.x = v60;
        v67.y = *(p_z - 1) + tanPts[1].z;
        if ( v66 <= 150.0 )
        {
          if ( !v91 )
          {
            v65 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: 1056964608,
                    a3: 1065353216);
            ((void (__thiscall *)(IUniformRandomStream *, int, int, Vector *, _DWORD, _DWORD))random->RandomFloat)(
              a1: random,
              a2: 1048576000,
              a3: 1056964608,
              a4: &velocity,
              a5: LODWORD(mins[1]),
              a6: LODWORD(v65));
            FX_WaterRipple(origin: &v67);
          }
        }
        else if ( v91 )
        {
          v63 = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
          FX_GunshotSlimeSplash(origin: &v86, normal: &tangent, scale: v63);
        }
        else
        {
          v64 = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random);
          FX_GunshotSplash(origin: &v86, normal: &tangent, scale: v64);
        }
        p_z += 3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D9E0
// Name: float PhysGetSyncCreateTime(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl PhysGetSyncCreateTime()
{
  double v0; // st6
  float nextTime; // [esp+0h] [ebp-8h]
  float m_fValue; // [esp+4h] [ebp-4h]

  nextTime = physenv->GetNextFrameTime(this: physenv);
  m_fValue = cl_phys_timescale.m_pParent->m_Value.m_fValue;
  v0 = ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetSimulationTime)(a1: physenv)
     + *(float *)(gpGlobals.m_Index + 16) * m_fValue;
  if ( v0 <= nextTime )
    return *(float *)(gpGlobals.m_Index + 12);
  else
    return nextTime + *(float *)(gpGlobals.m_Index + 12) - v0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DA50
// Name: void VPhysicsShadowDataChanged(bool,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VPhysicsShadowDataChanged(bool bCreate, C_BaseEntity *pEntity)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  double v3; // st7
  float v4; // xmm0_4
  IPhysicsObject *v5; // ebx
  IPhysicsObject_vtbl *v6; // edi
  const Vector *NetworkOrigin; // eax
  const QAngle *NetworkAngles; // [esp-8h] [ebp-18h]
  float deltaTime; // [esp+18h] [ebp+8h]
  float deltaTimea; // [esp+18h] [ebp+8h]
  float deltaTimeb; // [esp+18h] [ebp+8h]

  if ( !bCreate || pEntity->m_pPhysicsObject != nullptr || (pEntity->GetSolidFlags(this: pEntity) & 4) != 0 )
  {
    m_pPhysicsObject = pEntity->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr && !m_pPhysicsObject->IsStatic(this: m_pPhysicsObject) )
    {
      deltaTime = C_BaseEntity::GetInterpolationAmount(this: pEntity, flags: 2)
                + pEntity->m_flSimulationTime
                - *(float *)(gpGlobals.m_Index + 12);
      deltaTimea = ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetSimulationTime)(a1: physenv)
                 + deltaTime
                 + *(float *)(gpGlobals.m_Index + 16);
      v3 = deltaTimea - ((double (__thiscall *)(IPhysicsEnvironment *))physenv->GetNextFrameTime)(a1: physenv);
      if ( v3 >= 0.0 )
      {
        deltaTimeb = v3;
        v4 = deltaTimeb;
      }
      else
      {
        v4 = 0.0;
      }
      v5 = pEntity->m_pPhysicsObject;
      v6 = v5->__vftable;
      NetworkAngles = C_BaseEntity::GetNetworkAngles(this: pEntity);
      NetworkOrigin = C_BaseEntity::GetNetworkOrigin(this: pEntity);
      v6->UpdateShadow(this: v5, a2: NetworkOrigin, a3: NetworkAngles, a4: false, a5: COERCE_FLOAT(LODWORD(v4)));
    }
  }
  else
  {
    if ( pEntity->GetSolid(this: pEntity) != SOLID_BSP )
      CCollisionProperty::SetSolid(this: &pEntity->m_Collision, val: SOLID_VPHYSICS);
    if ( (pEntity->GetSolidFlags(this: pEntity) & 0x800) != 0 )
      C_BaseEntity::VPhysicsInitStatic(this: pEntity);
    else
      C_BaseEntity::VPhysicsInitShadow(this: pEntity, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013DB70
// Name: void PhysicsLevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsLevelInit()
{
  int v0; // xmm0_4
  int v1; // xmm0_4
  C_World *ClientWorldEntity; // esi
  vcollide_t *v3; // eax
  int v4; // [esp+14h] [ebp-Ch] BYREF
  int v5; // [esp+18h] [ebp-8h]
  int v6; // [esp+1Ch] [ebp-4h]

  physenv = physics->CreateEnvironment(this: physics);
  if ( *(_BYTE *)(gpGlobals.m_Index + 49) != 0
    && g_pGameRules->IsMultiplayer(this: g_pGameRules)
    && cl_predictphysics.m_pParent != nullptr
    && cl_predictphysics.m_pParent->m_Value.m_nValue != 0 )
  {
    physenv->SetPredicted(this: physenv, a2: true);
  }
  g_EntityCollisionHash = physics->CreateObjectPairHash(this: physics);
  v0 = LODWORD(sv_gravity.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
  v4 = 0;
  v5 = 0;
  v6 = v0;
  physenv->SetGravity(this: physenv, a2: (const Vector *)&v4);
  v1 = LODWORD(cl_ragdoll_gravity.m_pParent->m_Value.m_fValue) ^ _mask__NegFloat_;
  v4 = 0;
  v5 = 0;
  v6 = v1;
  physenv->SetAlternateGravity(this: physenv, a2: (const Vector *)&v4);
  ((void (__stdcall *)(int))physenv->SetSimulationTimestep)(a1: 1015580809);
  physenv->SetCollisionEventHandler(this: physenv, a2: &g_Collisions);
  physenv->SetCollisionSolver(this: physenv, a2: &g_Collisions.IPhysicsCollisionSolver);
  ClientWorldEntity = GetClientWorldEntity();
  v3 = (vcollide_t *)((int (__thiscall *)(IVModelInfoClient *))modelinfo->GetVCollide)(a1: modelinfo);
  g_PhysWorldObject = PhysCreateWorld_Shared(
                        pWorld: ClientWorldEntity,
                        pWorldCollide: v3,
                        defaultParams: (const objectparams_t *)1);
  ((void (__thiscall *)(IStaticPropMgrClient *, IPhysicsEnvironment *, CSolidSetDefaults *, C_World *, objectparams_t *))staticpropmgr->CreateVPhysicsRepresentations)(
    a1: staticpropmgr,
    a2: physenv,
    a3: &g_SolidSetup,
    a4: ClientWorldEntity,
    a5: &g_PhysDefaultObjectParams);
}

//------------------------------------------------------------------------------
// Address: 0x1013DCE0
// Name: public: virtual int CCollisionEvent::ShouldCollide(class IPhysicsObject __near *,class IPhysicsObject __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::ShouldCollide(
        CCollisionEvent *this,
        IPhysicsObject *pObj0,
        IPhysicsObject *pObj1,
        C_BaseEntity *pGameData0,
        C_BaseEntity *pGameData1)
{
  unsigned __int16 v7; // ax
  int ModelIndex; // eax
  IPhysicsCollisionSet *v9; // eax
  IPhysicsCollisionSet *v10; // esi
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // ax
  int result; // eax
  int m_nValue; // eax
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  int m_MoveType; // ebx
  int v18; // eax
  bool v19; // zf
  int movetype1; // [esp+8h] [ebp-8h]
  bool aiMove1; // [esp+Fh] [ebp-1h]
  unsigned __int16 gameFlags0; // [esp+20h] [ebp+10h]
  char gameFlags0_3; // [esp+23h] [ebp+13h]
  IPhysics_vtbl *pGameData1a; // [esp+24h] [ebp+14h]
  IPhysicsCollisionSet_vtbl *pGameData1b; // [esp+24h] [ebp+14h]

  ++this->m_penetrateEvents.m_pElements;
  if ( pGameData0 != nullptr && pGameData1 != nullptr )
  {
    gameFlags0 = pObj0->GetGameFlags(this: pObj0);
    v7 = pObj1->GetGameFlags(this: pObj1);
    if ( pGameData0 == pGameData1 )
    {
      if ( ((gameFlags0 | v7) & 0x8000) == 0 )
      {
        pGameData1a = physics->__vftable;
        ModelIndex = C_BaseEntity::GetModelIndex(this: pGameData0);
        v9 = pGameData1a->FindCollisionSet(this: physics, a2: ModelIndex);
        v10 = v9;
        if ( v9 != nullptr )
        {
          pGameData1b = v9->__vftable;
          v11 = pObj1->GetGameIndex(this: pObj1);
          v12 = ((int (__thiscall *)(IPhysicsObject *, _DWORD))pObj0->GetGameIndex)(a1: pObj0, a2: v11);
          LOBYTE(result) = ((int (__thiscall *)(IPhysicsCollisionSet *, _DWORD))pGameData1b->ShouldCollide)(
                             a1: v10,
                             a2: v12);
          --this->m_penetrateEvents.m_pElements;
          return (unsigned __int8)result;
        }
        goto LABEL_46;
      }
LABEL_47:
      --this->m_penetrateEvents.m_pElements;
      return 0;
    }
    if ( (((int (__thiscall *)(IPhysicsObject *))pObj0->GetGameFlags)(a1: pObj0) & 8) == 0
      || (((int (__thiscall *)(IPhysicsObject *))pObj1->GetGameFlags)(a1: pObj1) & 8) == 0 )
    {
      if ( g_pGameRules == nullptr
        || g_pGameRules->ShouldCollide(
             this: g_pGameRules,
             a2: pGameData0->m_CollisionGroup,
             a3: pGameData1->m_CollisionGroup) )
      {
        v15 = pObj0->GetContents(this: pObj0);
        if ( (v15 & pGameData1->PhysicsSolidMaskForEntity(this: pGameData1)) != 0 )
        {
          v16 = pObj1->GetContents(this: pObj1);
          if ( (v16 & pGameData0->PhysicsSolidMaskForEntity(this: pGameData0)) != 0
            && !g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: pGameData0, a3: pGameData1)
            && !g_EntityCollisionHash->IsObjectPairInHash(this: g_EntityCollisionHash, a2: pObj0, a3: pObj1) )
          {
            m_MoveType = pGameData0->m_MoveType;
            v18 = pGameData1->m_MoveType;
            movetype1 = v18;
            if ( m_MoveType == 7 || (gameFlags0_3 = 0, pGameData0->m_MoveType == 0) )
              gameFlags0_3 = 1;
            if ( v18 == 7 || (aiMove1 = false, pGameData1->m_MoveType == 0) )
              aiMove1 = true;
            if ( m_MoveType == 11 )
            {
              v19 = pObj0->GetShadowController(this: pObj0) == nullptr;
              v18 = movetype1;
              if ( !v19 )
                gameFlags0_3 = 1;
            }
            if ( v18 == 11 && pObj1->GetShadowController(this: pObj1) != nullptr )
              aiMove1 = true;
            if ( C_BaseEntity::GetMoveParent(this: pGameData0) != nullptr
              && (m_MoveType != 6 || C_BaseEntity::GetRootMoveParent(this: pGameData0)->m_MoveType != 6) )
            {
              gameFlags0_3 = 1;
            }
            if ( C_BaseEntity::GetMoveParent(this: pGameData1) != nullptr
              && (movetype1 != 6 || C_BaseEntity::GetRootMoveParent(this: pGameData1)->m_MoveType != 6) )
            {
              aiMove1 = true;
            }
            if ( (gameFlags0_3 == 0 || pObj1->IsMoveable(this: pObj1))
              && (!aiMove1 || pObj0->IsMoveable(this: pObj0))
              && (gameFlags0_3 == 0 || !aiMove1)
              && (pObj0->GetShadowController(this: pObj0) == nullptr
               || pObj1->GetShadowController(this: pObj1) == nullptr) )
            {
LABEL_46:
              --this->m_penetrateEvents.m_pElements;
              return 1;
            }
          }
        }
      }
      goto LABEL_47;
    }
    if ( cl_ragdoll_collide.m_pParent != nullptr )
    {
      m_nValue = cl_ragdoll_collide.m_pParent->m_Value.m_nValue;
      --this->m_penetrateEvents.m_pElements;
      return m_nValue != 0;
    }
    else
    {
      --this->m_penetrateEvents.m_pElements;
      return 0;
    }
  }
  else
  {
    --this->m_penetrateEvents.m_pElements;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E000
// Name: public: virtual void CPhysicsSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysicsSystem::LevelInitPostEntity(CPhysicsSystem *this)
{
  PhysicsLevelInit();
}

//------------------------------------------------------------------------------
// Address: 0x1013E010
// Name: private: void CCollisionEvent::DispatchStartTouch(class C_BaseEntity __near *,class C_BaseEntity __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::DispatchStartTouch(
        CCollisionEvent *this,
        C_BaseEntity *pEntity0,
        C_BaseEntity *pEntity1,
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
  C_BaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(this: pEntity0, other: pEntity1, &trace);
}

//------------------------------------------------------------------------------
// Address: 0x1013E0A0
// Name: public: virtual void CPhysicsSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSystem::LevelInitPreEntity(CPhysicsSystem *this)
{
  this->m_impactSounds.elements.m_Size = 0;
  PrecachePhysicsSounds();
}

//------------------------------------------------------------------------------
// Address: 0x1013E0B0
// Name: public: void CCollisionEvent::UpdateTouchEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdateTouchEvents(CCollisionEvent *this)
{
  touchevent_t *v2; // esi
  float y; // xmm3_4
  float x; // xmm0_4
  float v5; // xmm4_4
  float z; // xmm5_4
  float v7; // xmm2_4
  C_BaseEntity *v8; // eax
  C_BaseEntity *v9; // ecx
  C_BaseEntity *pEntity1; // ebx
  C_BaseEntity *pEntity0; // esi
  bool v12; // cl
  CGameTrace dst; // [esp+4h] [ebp-60h] BYREF
  int i; // [esp+58h] [ebp-Ch]
  unsigned int v15; // [esp+5Ch] [ebp-8h]
  bool bOldTouchEvents; // [esp+63h] [ebp-1h]

  bOldTouchEvents = this->m_bBufferTouchEvents;
  this->m_bBufferTouchEvents = true;
  i = 0;
  if ( this->m_touchEvents.m_Size > 0 )
  {
    v15 = 0;
    do
    {
      v2 = &this->m_touchEvents.m_Memory.m_pMemory[v15 / 0x24];
      if ( v2->touchType != 0 )
      {
        pEntity1 = v2->pEntity1;
        pEntity0 = v2->pEntity0;
        C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: pEntity0, other: pEntity1);
        C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: pEntity1, other: pEntity0);
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
        C_BaseEntity::PhysicsMarkEntitiesAsTouchingEventDriven(this: v9, other: v8, trace: &dst);
      }
      v15 += 36;
      ++i;
    }
    while ( i < this->m_touchEvents.m_Size );
  }
  v12 = bOldTouchEvents;
  this->m_touchEvents.m_Size = 0;
  this->m_bBufferTouchEvents = v12;
}

//------------------------------------------------------------------------------
// Address: 0x1013E1C0
// Name: public: void CCollisionEvent::UpdatePenetrateEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::UpdatePenetrateEvents(CCollisionEvent *this)
{
  int v2; // ebx
  int v3; // edi
  penetrateevent_t *m_pMemory; // eax
  int m_Size; // eax
  bool v6; // zf
  penetrateevent_t *v7; // ecx
  int v8; // eax

  v2 = this->m_penetrateEvents.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      m_pMemory = this->m_penetrateEvents.m_Memory.m_pMemory;
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - m_pMemory[v3].timeStamp) <= 0.1 )
      {
        if ( (float)(m_pMemory[v3].timeStamp - m_pMemory[v3].startTime) > 3.0 )
        {
          PhysDisableEntityCollisions(pEntity0: m_pMemory[v3].pEntity0, pEntity1: m_pMemory[v3].pEntity1);
          m_Size = this->m_penetrateEvents.m_Size;
          if ( m_Size > 0 )
          {
            v6 = v2 == m_Size - 1;
            goto LABEL_9;
          }
        }
      }
      else
      {
        m_Size = this->m_penetrateEvents.m_Size;
        if ( m_Size > 0 )
        {
          v6 = v2 == m_Size - 1;
LABEL_9:
          if ( !v6 )
          {
            v7 = this->m_penetrateEvents.m_Memory.m_pMemory;
            v8 = m_Size;
            *(_QWORD *)&v7[v3].pEntity0 = *(_QWORD *)&v7[v8 - 1].pEntity0;
            *(_QWORD *)&v7[v3].startTime = *(_QWORD *)&v7[v8 - 1].startTime;
          }
          --this->m_penetrateEvents.m_Size;
        }
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013E280
// Name: public: void CCollisionEvent::UpdateFluidEvents(void)
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
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_fluidEvents.m_Memory.m_pMemory[v1].impactTime) > 2.0 )
        {
          m_Size = this->m_fluidEvents.m_Size;
          if ( m_Size > 0 )
          {
            if ( v1 != m_Size - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1] = this->m_fluidEvents.m_Memory.m_pMemory[m_Size - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1].impactTime) > 2.0 )
        {
          v4 = this->m_fluidEvents.m_Size;
          if ( v4 > 0 )
          {
            if ( v2 + 1 != v4 - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1] = this->m_fluidEvents.m_Memory.m_pMemory[v4 - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - *((float *)&this->m_fluidEvents.m_Memory.m_pMemory[v1 - 1] - 1)) > 2.0 )
        {
          v5 = this->m_fluidEvents.m_Size;
          if ( v5 > 0 )
          {
            if ( v2 != v5 - 1 )
              this->m_fluidEvents.m_Memory.m_pMemory[v1 - 2] = this->m_fluidEvents.m_Memory.m_pMemory[v5 - 1];
            --this->m_fluidEvents.m_Size;
          }
        }
        if ( (float)(*(float *)(gpGlobals.m_Index + 12) - *((float *)&this->m_fluidEvents.m_Memory.m_pMemory[v1 - 2] - 1)) > 2.0 )
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
      if ( (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_fluidEvents.m_Memory.m_pMemory[v1].impactTime) > 2.0 )
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
// Address: 0x1013E450
// Name: public: virtual void CPhysicsSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSystem::LevelShutdownPostEntity(CPhysicsSystem *this)
{
  g_Collisions.m_penetrateEvents.m_Size = 0;
  g_Collisions.m_flLastSplashTime = 0.0;
  if ( physenv != nullptr )
    physics->DestroyEnvironment(this: physics, a2: physenv);
  physics->DestroyObjectPairHash(this: physics, a2: g_EntityCollisionHash);
  g_EntityCollisionHash = nullptr;
  physics->DestroyAllCollisionSets(this: physics);
  physenv = nullptr;
  g_PhysWorldObject = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013E4B0
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
  this->m_fluidEvents.m_Memory.m_pMemory = nullptr;
  this->m_fluidEvents.m_Memory.m_nAllocationCount = 0;
  this->m_fluidEvents.m_Memory.m_nGrowSize = 0;
  this->m_fluidEvents.m_Size = 0;
  this->m_fluidEvents.m_pElements = nullptr;
  this->m_touchEvents.m_Memory.m_pMemory = nullptr;
  this->m_touchEvents.m_Memory.m_nAllocationCount = 0;
  this->m_touchEvents.m_Memory.m_nGrowSize = 0;
  this->m_touchEvents.m_Size = 0;
  this->m_touchEvents.m_pElements = nullptr;
  this->m_penetrateEvents.m_Memory.m_pMemory = nullptr;
  this->m_penetrateEvents.m_Memory.m_nAllocationCount = 0;
  this->m_penetrateEvents.m_Memory.m_nGrowSize = 0;
  this->m_penetrateEvents.m_Size = 0;
  this->m_penetrateEvents.m_pElements = nullptr;
  this->m_flLastSplashTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013E540
// Name: public: virtual bool CCollisionEvent::ShouldFreezeObject(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionEvent::ShouldFreezeObject(CCollisionEvent *this, IPhysicsObject *pObject)
{
  return pObject->GetShadowController(this: pObject) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013E560
// Name: public: virtual void CCollisionEvent::ObjectWake(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectWake(CCollisionEvent *this, IPhysicsObject *pObject)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi

  v2 = (C_BaseEntity *)pObject->GetGameData(this: pObject);
  v3 = v2;
  if ( v2 != nullptr && C_BaseEntity::HasDataObjectType(this: v2, type: 7) )
    ReportVPhysicsStateChanged(pPhysics: pObject, pEntity: v3, bAwake: true);
}

//------------------------------------------------------------------------------
// Address: 0x1013E5A0
// Name: public: virtual void CCollisionEvent::ObjectSleep(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectSleep(CCollisionEvent *this, IPhysicsObject *pObject)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi

  v2 = (C_BaseEntity *)pObject->GetGameData(this: pObject);
  v3 = v2;
  if ( v2 != nullptr && C_BaseEntity::HasDataObjectType(this: v2, type: 7) )
    ReportVPhysicsStateChanged(pPhysics: pObject, pEntity: v3, bAwake: false);
}

//------------------------------------------------------------------------------
// Address: 0x1013E630
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
  float v11; // xmm0_4
  CSoundParameters params; // [esp+0h] [ebp-124h] BYREF
  CPASAttenuationFilter filter; // [esp+B4h] [ebp-70h] BYREF
  EmitSound_t ep; // [esp+D4h] [ebp-50h] BYREF
  int i; // [esp+11Ch] [ebp-8h]
  int j; // [esp+120h] [ebp-4h]

  v2 = list;
  v3 = list->elements.m_Size - 1;
  i = v3;
  if ( v3 >= 0 )
  {
    v4 = 36 * v3;
    for ( j = v4; ; v4 = j )
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
        if ( !C_BaseEntity::GetParametersForSound(soundname: v10, &params, actormodel: nullptr) )
        {
          list->elements.m_Size = 0;
          return;
        }
        if ( *((float *)v5 + 3) > 1.0 )
          *((_DWORD *)v5 + 3) = 1065353216;
        C_RecipientFilter::C_RecipientFilter(this: &filter);
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
        C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: (const Vector *)v5 + 2);
        ep.m_nChannel = *((_DWORD *)v5 + 2);
        ep.m_pSoundName = params.soundname;
        ep.m_nPitch = params.pitch;
        ep.m_flSoundTime = 0.0;
        v11 = *((float *)v5 + 3) * params.volume;
        ep.m_hSoundScriptHandle = params.m_hSoundScriptHandle;
        ep.m_SoundLevel = params.soundlevel;
        filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
        ep.m_nFlags = 0;
        ep.m_pflSoundDuration = nullptr;
        *(_WORD *)&ep.m_bEmitCloseCaption = 1;
        ep.m_bWarnOnDirectWaveReference = false;
        ep.m_nSpeakerEntity = -1;
        memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
        ep.m_flVolume = v11;
        ep.m_pOrigin = (const Vector *)(v5 + 24);
        ep.m_nSoundEntryVersion = params.m_nSoundEntryVersion;
        C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
      }
      j -= 36;
      if ( --i < 0 )
      {
        list->elements.m_Size = 0;
        return;
      }
      v2 = list;
    }
  }
  list->elements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013E860
// Name: void physicssound::AddImpactSound(struct physicssound::soundlist_t __near &,void __near *,int,int,class IPhysicsObject __near *,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl physicssound::AddImpactSound(
        CUtlMemory<vgui::SectionedListPanel::section_t,int> *list,
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
      CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v14 = (physicssound::impactsound_t *)list->m_pMemory;
    v15 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v15 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v14[m_pMemory + 1], src: (unsigned __int8 *)&v14[m_pMemory], count: 36 * v15);
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
// Address: 0x1013E9F0
// Name: public: void CPhysicsSystem::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsSystem::PhysicsSimulate(CPhysicsSystem *this)
{
  int v1; // esi
  void *v2; // esp
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // esi
  C_BaseEntity *v8; // edi
  IPhysicsObject *v9; // ebx
  IPhysicsEnvironment *v10; // ecx
  float v11; // xmm0_4
  int m_nValue; // eax
  int v13; // ebx
  void *v14; // esp
  int v15; // esi
  int v16; // eax
  C_BaseEntity *v17; // ebx
  int v18; // eax
  double v19; // st7
  double v20; // st6
  double m_fValue; // st7
  float v22; // xmm1_4
  int v23; // ebx
  _DWORD *v24; // esi
  int v25; // edx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int m_Next; // eax
  int v31; // esi
  C_BaseEntity *m_Element; // edi
  IPhysicsObject *m_pPhysicsObject; // ebx
  CCollisionEvent *v34; // ecx
  _DWORD v35[3]; // [esp+4Ch] [ebp-80h] BYREF
  QAngle rot; // [esp+58h] [ebp-74h] BYREF
  QAngle targetAngles; // [esp+64h] [ebp-68h] BYREF
  Vector targetAxis; // [esp+70h] [ebp-5Ch] BYREF
  Vector angVel; // [esp+7Ch] [ebp-50h] BYREF
  Vector vel; // [esp+88h] [ebp-44h] BYREF
  Vector pos; // [esp+94h] [ebp-38h] BYREF
  Vector targetPos; // [esp+A0h] [ebp-2Ch] BYREF
  Vector delta; // [esp+ACh] [ebp-20h] BYREF
  CPhysicsSystem *v44; // [esp+B8h] [ebp-14h]
  C_BaseEntity *pBlocker; // [esp+BCh] [ebp-10h]
  int i; // [esp+C0h] [ebp-Ch] BYREF
  int activeCount; // [esp+C4h] [ebp-8h]
  bool bBlocked; // [esp+CBh] [ebp-1h]

  v44 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CPhysicsSystem::PhysicsSimulate",
    a3: 0,
    a4: "Physics",
    a5: false,
    a6: 4);
  activeCount = *(int *)(gpGlobals.m_Index + 16);
  if ( physenv == nullptr )
  {
LABEL_62:
    physicssound::PlayImpactSounds(list: &v44->m_impactSounds);
    goto LABEL_63;
  }
  if ( !physenv->IsPredicted(this: physenv) )
    goto LABEL_19;
  if ( !prediction->InPrediction(this: prediction) )
    goto LABEL_63;
  if ( prediction->IsFirstTimePredicted(this: prediction) )
  {
LABEL_19:
    g_Collisions.m_bBufferTouchEvents = true;
    if ( phys_debug_check_contacts.m_pParent != nullptr && phys_debug_check_contacts.m_pParent->m_Value.m_nValue != 0 )
    {
      v10 = physenv;
      if ( physenv == nullptr )
        goto LABEL_24;
      physenv->DebugCheckContacts(this: physenv);
    }
    v10 = physenv;
LABEL_24:
    v11 = cl_phys_timescale.m_pParent->m_Value.m_fValue * *(float *)&activeCount;
    *(float *)&activeCount = v11;
    if ( cl_phys_maxticks.m_pParent != nullptr )
    {
      m_nValue = cl_phys_maxticks.m_pParent->m_Value.m_nValue;
      if ( m_nValue != 0 )
      {
        v11 = 0.0;
        *(float *)&i = ((double (__thiscall *)(IPhysicsEnvironment *, int))v10->GetDeltaFrameTime)(
                         a1: v10,
                         a2: m_nValue)
                     - 0.000099999997;
        if ( *(float *)&activeCount >= 0.0 )
        {
          v11 = *(float *)&i;
          if ( *(float *)&activeCount <= *(float *)&i )
            v11 = *(float *)&activeCount;
        }
        v10 = physenv;
      }
    }
    ((void (__stdcall *)(float))v10->Simulate)(a1: COERCE_FLOAT(LODWORD(v11)));
    v13 = physenv->GetActiveObjectCount(this: physenv);
    activeCount = v13;
    if ( v13 != 0 )
    {
      v14 = alloca(4 * v13);
      physenv->GetActiveObjects(this: physenv, a2: (IPhysicsObject **)v35);
      v15 = 0;
      if ( v13 > 0 )
      {
        do
        {
          v16 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v35[v15] + 68))(a1: v35[v15]);
          v17 = (C_BaseEntity *)v16;
          if ( v16 != 0 )
          {
            if ( CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(this: (CCollisionProperty *)(v16 + 780)) )
              CCollisionProperty::MarkSurroundingBoundsDirty(this: &v17->m_Collision);
            v17->VPhysicsUpdate(this: v17, a2: (IPhysicsObject *)v35[v15]);
            v18 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v35[v15] + 284))(a1: v35[v15]);
            if ( v18 != 0 )
            {
              (*(void (__thiscall **)(int, Vector *, QAngle *))(*(_DWORD *)v18 + 48))(
                a1: v18,
                a2: &targetPos,
                a3: &targetAngles);
              (*(void (__thiscall **)(_DWORD, Vector *, QAngle *))(*(_DWORD *)v35[v15] + 192))(
                a1: v35[v15],
                a2: &pos,
                a3: &rot);
              delta.x = targetPos.x - pos.x;
              delta.y = targetPos.y - pos.y;
              delta.z = targetPos.z - pos.z;
              v19 = VectorNormalize(vec: &delta);
              *(float *)&pBlocker = v19;
              v20 = v19;
              m_fValue = cl_phys_block_dist.m_pParent->m_Value.m_fValue;
              bBlocked = false;
              if ( v20 > m_fValue )
              {
                (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(*(_DWORD *)v35[v15] + 220))(
                  a1: v35[v15],
                  a2: &vel,
                  a3: 0);
                if ( (float)(cl_phys_block_fraction.m_pParent->m_Value.m_fValue * *(float *)&pBlocker) > (float)((float)((float)(vel.y * delta.y) + (float)(delta.x * vel.x)) + (float)(vel.z * delta.z)) )
                  bBlocked = true;
              }
              RotationDeltaAxisAngle(
                srcAngles: &rot,
                destAngles: &targetAngles,
                deltaAxis: &targetAxis,
                deltaAngle: (float *)&i);
              if ( fabs(*(float *)&i) > 0.5
                && (((*(void (__thiscall **)(_DWORD, _DWORD, Vector *))(*(_DWORD *)v35[v15] + 220))(
                       a1: v35[v15],
                       a2: 0,
                       a3: &angVel),
                     *(float *)&i < 0.0)
                  ? (v22 = -1.0)
                  : (v22 = 1.0),
                    (float)(fabs(*(float *)&i) * cl_phys_block_fraction.m_pParent->m_Value.m_fValue) > (float)((float)((float)((float)(angVel.y * targetAxis.y) + (float)(targetAxis.x * angVel.x)) + (float)(angVel.z * targetAxis.z)) * v22))
                || bBlocked )
              {
                *(float *)&pBlocker = COERCE_FLOAT(FindPhysicsBlocker(pPhysics: (IPhysicsObject *)v35[v15]));
                if ( *(float *)&pBlocker != 0.0 && IsBlockedShouldDisableCollisions(pEntity: v17) )
                {
                  PhysDisableEntityCollisions(pEntity0: v17, pEntity1: pBlocker);
                  (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v35[v15] + 108))(a1: v35[v15], a2: 0);
                }
              }
            }
          }
          ++v15;
        }
        while ( v15 < activeCount );
      }
      if ( cl_phys_show_active.m_pParent != nullptr && cl_phys_show_active.m_pParent->m_Value.m_nValue != 0 )
      {
        v23 = 0;
        for ( *(float *)&i = 0.0; v23 < activeCount; i = v23 )
        {
          v24 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)v35[v23] + 68))(a1: v35[v23]);
          if ( v24 != nullptr )
          {
            v25 = *v24;
            pBlocker = (C_BaseEntity *)&debugoverlay->AddBoxOverlay;
            v26 = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD, int, _DWORD))(v25 + 44))(
                    a1: v24,
                    a2: 255,
                    a3: 255,
                    a4: 0,
                    a5: 8,
                    a6: 0);
            v27 = (*(int (__thiscall **)(_DWORD *, int))(v24[195] + 8))(a1: v24 + 195, a2: v26);
            v28 = (*(int (__thiscall **)(_DWORD *, int))(v24[195] + 4))(a1: v24 + 195, a2: v27);
            v29 = (*(int (__thiscall **)(_DWORD *, int))(*v24 + 40))(a1: v24, a2: v28);
            ((void (__thiscall *)(IVDebugOverlay *, int))pBlocker->IClientEntity::IClientUnknown::IHandleEntity::__vftable)(
              a1: debugoverlay,
              a2: v29);
            v23 = i;
          }
          ++v23;
        }
      }
    }
    if ( g_ShadowEntities.m_ElementCount != 0 )
    {
      LOWORD(m_Next) = g_ShadowEntities.m_Head;
      if ( g_ShadowEntities.m_Head != 0xFFFF )
      {
        do
        {
          v31 = (unsigned __int16)m_Next;
          m_Element = g_ShadowEntities.m_Memory.m_pMemory[v31].m_Element;
          m_pPhysicsObject = m_Element->m_pPhysicsObject;
          if ( m_pPhysicsObject != nullptr && !m_pPhysicsObject->IsAsleep(this: m_Element->m_pPhysicsObject) )
            m_Element->VPhysicsShadowUpdate(this: m_Element, a2: m_pPhysicsObject);
          m_Next = g_ShadowEntities.m_Memory.m_pMemory[v31].m_Next;
        }
        while ( m_Next != 0xFFFF );
      }
    }
    g_Collisions.m_bBufferTouchEvents = false;
    CCollisionEvent::UpdateFrictionSounds(this: &g_Collisions);
    CCollisionEvent::UpdateTouchEvents(this: &g_Collisions);
    CCollisionEvent::UpdateFluidEvents(this: &g_Collisions);
    CCollisionEvent::UpdatePenetrateEvents(this: v34);
    goto LABEL_62;
  }
  physenv->RestorePredictedSimulation(this: physenv);
  v1 = physenv->GetActiveObjectCount(this: physenv);
  i = v1;
  if ( v1 != 0 )
  {
    v2 = alloca(4 * v1);
    physenv->GetActiveObjects(this: physenv, a2: (IPhysicsObject **)v35);
    v3 = 0;
    if ( v1 > 0 )
    {
      do
      {
        v4 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v35[v3] + 68))(a1: v35[v3]);
        v5 = v4;
        if ( v4 != 0 )
        {
          if ( CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(this: (CCollisionProperty *)(v4 + 780)) )
            CCollisionProperty::MarkSurroundingBoundsDirty(this: (CCollisionProperty *)(v5 + 780));
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 260))(a1: v5, a2: v35[v3]);
        }
        ++v3;
      }
      while ( v3 < i );
    }
  }
  if ( g_ShadowEntities.m_ElementCount != 0 )
  {
    LOWORD(v6) = g_ShadowEntities.m_Head;
    if ( g_ShadowEntities.m_Head != 0xFFFF )
    {
      do
      {
        v7 = (unsigned __int16)v6;
        v8 = g_ShadowEntities.m_Memory.m_pMemory[v7].m_Element;
        v9 = v8->m_pPhysicsObject;
        if ( v9 != nullptr && !v9->IsAsleep(this: v8->m_pPhysicsObject) )
          v8->VPhysicsShadowUpdate(this: v8, a2: v9);
        v6 = g_ShadowEntities.m_Memory.m_pMemory[v7].m_Next;
      }
      while ( v6 != 0xFFFF );
    }
  }
LABEL_63:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1013EFD0
// Name: void PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysicsSimulate()
{
  CPhysicsSystem::PhysicsSimulate(this: &g_PhysicsSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1013EFE0
// Name: public: void CCollisionEvent::ObjectSound(int,struct vcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::ObjectSound(CCollisionEvent *this, int index, vcollisionevent_t *pEvent)
{
  IPhysicsObject *v5; // esi
  void *v6; // eax
  float volume; // xmm0_4
  int surfaceProps; // [esp+1Ch] [ebp+8h]
  float speed; // [esp+20h] [ebp+Ch]

  v5 = pEvent->pObjects[index];
  if ( v5 != nullptr && !v5->IsStatic(this: pEvent->pObjects[index]) )
  {
    surfaceProps = pEvent->surfaceProps[index];
    speed = pEvent->collisionSpeed * pEvent->collisionSpeed;
    v6 = v5->GetGameData(this: v5);
    if ( v6 != nullptr )
    {
      volume = speed * 0.0000097656248;
      if ( (float)(speed * 0.0000097656248) > 1.0 )
        volume = 1.0;
      if ( surfaceProps >= 0 )
        physicssound::AddImpactSound(
          list: &g_PhysicsSystem.m_impactSounds,
          pGameData: v6,
          entityIndex: 0,
          soundChannel: 6,
          pObject: v5,
          surfaceProps,
          surfacePropsHit: pEvent->surfaceProps[index == 0],
          volume,
          impactSpeed: speed);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F090
// Name: public: virtual void CCollisionEvent::PostCollision(struct vcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::PostCollision(CCollisionEvent *this, vcollisionevent_t *pEvent)
{
  ++this->m_inCallback;
  if ( pEvent->deltaCollisionTime > 0.1 && pEvent->collisionSpeed > 70.0 )
  {
    CCollisionEvent::ObjectSound(this, index: 0, pEvent);
    CCollisionEvent::ObjectSound(this, index: 1, pEvent);
  }
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1013F0E0
// Name: private: void CCollisionEvent::AddTouchEvent(class C_BaseEntity __near *,class C_BaseEntity __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::AddTouchEvent(
        CCollisionEvent *this,
        C_BaseEntity *pEntity0,
        C_BaseEntity *pEntity1,
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
// Address: 0x1013F150
// Name: public: virtual void CCollisionEvent::StartTouch(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::StartTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject1,
        IPhysicsObject *pObject2,
        IPhysicsCollisionData *pTouchData)
{
  C_BaseEntity *v5; // edi
  C_BaseEntity *v6; // eax
  C_BaseEntity *v7; // ebx
  Vector endPoint; // [esp+Ch] [ebp-18h] BYREF
  Vector normal; // [esp+18h] [ebp-Ch] BYREF

  ++this->m_inCallback;
  v5 = (C_BaseEntity *)pObject1->GetGameData(this: pObject1);
  v6 = (C_BaseEntity *)pObject2->GetGameData(this: pObject2);
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
// Address: 0x1013F1F0
// Name: public: virtual void CCollisionEvent::EndTouch(class IPhysicsObject __near *,class IPhysicsObject __near *,class IPhysicsCollisionData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::EndTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject1,
        IPhysicsObject *pObject2,
        IPhysicsCollisionData *pTouchData)
{
  C_BaseEntity *v5; // edi
  C_BaseEntity *v6; // eax
  C_BaseEntity *v7; // ebx

  ++this->m_inCallback;
  v5 = (C_BaseEntity *)pObject1->GetGameData(this: pObject1);
  v6 = (C_BaseEntity *)pObject2->GetGameData(this: pObject2);
  v7 = v6;
  if ( v5 != nullptr && v6 != nullptr )
  {
    if ( !this->m_bBufferTouchEvents )
    {
      C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: v5, other: v6);
      C_BaseEntity::PhysicsNotifyOtherOfUntouch(ent: v7, other: v5);
      --this->m_inCallback;
      return;
    }
    CCollisionEvent::AddTouchEvent(
      this,
      pEntity0: v5,
      pEntity1: v6,
      touchType: 1,
      point: &vec3_origin,
      normal: &vec3_origin);
  }
  --this->m_inCallback;
}

//------------------------------------------------------------------------------
// Address: 0x1013F270
// Name: private: void CCollisionEvent::FindOrAddPenetrateEvent(class C_BaseEntity __near *,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::FindOrAddPenetrateEvent(
        CCollisionEvent *this,
        C_BaseEntity *pEntity0,
        C_BaseEntity *pEntity1)
{
  int m_Size; // esi
  int v4; // eax
  penetrateevent_t *v5; // edx
  int v6; // edi
  int m_nAllocationCount; // eax
  CUtlVector<penetrateevent_t,CUtlMemory<penetrateevent_t,int> > *p_m_penetrateEvents; // esi
  penetrateevent_t *m_pMemory; // ecx
  int v10; // eax
  int v11; // edi

  m_Size = this->m_penetrateEvents.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    v6 = this->m_penetrateEvents.m_Size;
    m_nAllocationCount = this->m_penetrateEvents.m_Memory.m_nAllocationCount;
    p_m_penetrateEvents = &this->m_penetrateEvents;
    if ( v6 + 1 > m_nAllocationCount )
      CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&this->m_penetrateEvents,
        num: v6 - m_nAllocationCount + 1);
    ++p_m_penetrateEvents->m_Size;
    m_pMemory = p_m_penetrateEvents->m_Memory.m_pMemory;
    v10 = p_m_penetrateEvents->m_Size - v6 - 1;
    p_m_penetrateEvents->m_pElements = p_m_penetrateEvents->m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 16 * v10);
    v11 = v6;
    p_m_penetrateEvents->m_Memory.m_pMemory[v11].pEntity0 = pEntity0;
    p_m_penetrateEvents->m_Memory.m_pMemory[v11].pEntity1 = pEntity1;
    p_m_penetrateEvents->m_Memory.m_pMemory[v11].startTime = *(float *)(gpGlobals.m_Index + 12);
    p_m_penetrateEvents->m_Memory.m_pMemory[v11].timeStamp = *(float *)(gpGlobals.m_Index + 12);
  }
  else
  {
    v5 = this->m_penetrateEvents.m_Memory.m_pMemory;
    while ( v5->pEntity0 != pEntity0 || v5->pEntity1 != pEntity1 )
    {
      ++v4;
      ++v5;
      if ( v4 >= m_Size )
        goto LABEL_6;
    }
    this->m_penetrateEvents.m_Memory.m_pMemory[v4].timeStamp = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F350
// Name: public: float CCollisionEvent::DeltaTimeSinceLastFluid(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCollisionEvent::DeltaTimeSinceLastFluid(CCollisionEvent *this, C_BaseEntity *pEntity)
{
  int v2; // esi
  fluidevent_t *v3; // edi
  unsigned int m_Index; // edx
  C_BaseEntity *m_pEntity; // eax
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
        this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&this->m_fluidEvents,
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
    p_m_fluidEvents->m_Memory.m_pMemory[v11].impactTime = *(float *)(gpGlobals.m_Index + 12);
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
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      if ( m_pEntity == pEntity )
        return *(float *)(gpGlobals.m_Index + 12) - this->m_fluidEvents.m_Memory.m_pMemory[v2].impactTime;
      --v3;
      if ( --v2 < 0 )
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F460
// Name: public: virtual void CCollisionEvent::FluidStartTouch(class IPhysicsObject __near *,class IPhysicsFluidController __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionEvent::FluidStartTouch(
        CCollisionEvent *this,
        IPhysicsObject *pObject,
        IPhysicsFluidController *pFluid)
{
  C_BaseEntity *v4; // eax
  C_BaseEntity *v5; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  ++this->m_inCallback;
  if ( pObject != nullptr && pFluid != nullptr )
  {
    v4 = (C_BaseEntity *)pObject->GetGameData(this: pObject);
    v5 = v4;
    if ( v4 != nullptr
      && CCollisionEvent::DeltaTimeSinceLastFluid(this, pEntity: v4) >= 0.5
      && (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flLastSplashTime) >= 0.1 )
    {
      PhysicsSplash(a1: (int)&savedregs, a2: (int)v5, a3: (int)this, pFluid, pObject, pEntity: v5);
      this->m_flLastSplashTime = *(float *)(gpGlobals.m_Index + 12);
    }
    --this->m_inCallback;
  }
  else
  {
    --this->m_inCallback;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F500
// Name: public: virtual int CCollisionEvent::ShouldSolvePenetration(class IPhysicsObject __near *,class IPhysicsObject __near *,void __near *,void __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionEvent::ShouldSolvePenetration(
        CCollisionEvent *this,
        IPhysicsObject *pObj0,
        IPhysicsObject *pObj1,
        C_BaseEntity *pGameData0,
        C_BaseEntity *pGameData1,
        float dt)
{
  penetrateevent_t *v6; // edx
  CCollisionEvent *v8; // esi
  IPhysicsObject *v10; // eax
  IPhysicsObject *v11; // ecx
  unsigned __int8 v12; // al
  int v13; // eax
  int v14; // eax
  C_BaseEntity *pEntity0; // [esp+Ch] [ebp-4h]
  C_BaseEntity *pEntity1; // [esp+20h] [ebp+10h]
  unsigned __int8 gameFlags0; // [esp+24h] [ebp+14h]

  v6 = ++this->m_penetrateEvents.m_pElements;
  v8 = (CCollisionEvent *)((char *)this - 4);
  pEntity0 = pGameData0;
  pEntity1 = pGameData1;
  if ( pEntity0 <= pGameData1 )
  {
    v11 = pObj0;
  }
  else
  {
    v10 = pObj0;
    v11 = pObj1;
    pEntity0 = pGameData1;
    pEntity1 = pGameData0;
    pObj0 = pObj1;
    pObj1 = v10;
  }
  if ( pEntity0 != nullptr && pEntity1 != nullptr )
  {
    gameFlags0 = v11->GetGameFlags(this: v11);
    v12 = pObj1->GetGameFlags(this: pObj1);
    if ( pGameData0 == pGameData1 )
    {
      if ( (gameFlags0 & 8) != 0 )
      {
        v13 = (int)pGameData0->GetBaseAnimating(this: pGameData0);
        if ( v13 != 0 && *(_DWORD *)(v13 + 2432) != 0 )
        {
          v14 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v13 + 2432) + 36))(a1: *(_DWORD *)(v13 + 2432));
          if ( v14 != 0 )
          {
            (*(void (__thiscall **)(int, IPhysicsObject *, IPhysicsObject *))(*(_DWORD *)v14 + 24))(
              a1: v14,
              a2: pObj0,
              a3: pObj1);
            --v8->m_inCallback;
            return 0;
          }
        }
      }
    }
    else if ( ((gameFlags0 | v12) & 8) != 0
           && (pObj0->GetShadowController(this: pObj0) != nullptr || pObj1->GetShadowController(this: pObj1) != nullptr) )
    {
      CCollisionEvent::FindOrAddPenetrateEvent(this: v8, pEntity0, pEntity1);
    }
    --v8->m_inCallback;
    return 1;
  }
  else
  {
    v8->m_inCallback = (int)&v6[-1].timeStamp + 3;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F630
// Name: void PhysAddShadow(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysAddShadow(C_BaseEntity *pEntity)
{
  unsigned __int16 m_Head; // ax
  int v2; // esi
  UtlLinkedListElem_t<C_BaseEntity *,unsigned short> *v3; // eax

  m_Head = g_ShadowEntities.m_Head;
  if ( g_ShadowEntities.m_Head == 0xFFFF )
    goto LABEL_6;
  while ( g_ShadowEntities.m_Memory.m_pMemory[m_Head].m_Element != pEntity )
  {
    m_Head = g_ShadowEntities.m_Memory.m_pMemory[m_Head].m_Next;
    if ( m_Head == 0xFFFF )
      goto LABEL_6;
  }
  if ( m_Head == 0xFFFF )
  {
LABEL_6:
    v2 = (unsigned __int16)CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::AllocInternal(
                             this: &g_ShadowEntities,
                             multilist: false);
    if ( (_WORD)v2 != 0xFFFF )
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&g_ShadowEntities,
        before: 0xFFFFu,
        elem: v2);
      v3 = &g_ShadowEntities.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v3->m_Element = pEntity;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013F6B0
// Name: void PhysRemoveShadow(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysRemoveShadow(C_BaseEntity *pEntity)
{
  CUtlLinkedList<C_BaseEntity *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_BaseEntity *,unsigned short>,unsigned short>>::FindAndRemove(
    this: (CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short> > *)&g_ShadowEntities,
    src: (CEnvWindShared **)&pEntity);
}
