// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_npc_solver.cpp
// Functions: 24
// ============================================================

#include "game\server\physics_npc_solver.h"

//------------------------------------------------------------------------------
// Address: 0x1019B5E0
// Name: public: virtual struct datamap_t __near * CPhysicsNPCSolver::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsNPCSolver::GetDataDescMap(CPhysicsNPCSolver *this)
{
  return &CPhysicsNPCSolver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1019B5F0
// Name: public: virtual struct datamap_t __near * CPhysicsEntitySolver::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsEntitySolver::GetDataDescMap(CPhysicsEntitySolver *this)
{
  return &CPhysicsEntitySolver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1019B620
// Name: public: virtual CPhysicsNPCSolver::~CPhysicsNPCSolver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsNPCSolver::~CPhysicsNPCSolver(CPhysicsNPCSolver *this)
{
  CPhysicsNPCSolver *v1; // eax
  CPhysicsNPCSolver **p_m_pNext; // edx

  this->CLogicalEntity::CServerOnlyEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsNPCSolver_vtbl *)&CPhysicsNPCSolver::`vftable'{for `CLogicalEntity'};
  this->IMotionEvent::__vftable = (IMotionEvent_vtbl *)&CPhysicsNPCSolver::`vftable'{for `IMotionEvent'};
  v1 = CEntityClassList<CPhysicsNPCSolver>::m_pClassList;
  p_m_pNext = &CEntityClassList<CPhysicsNPCSolver>::m_pClassList;
  if ( CEntityClassList<CPhysicsNPCSolver>::m_pClassList != nullptr )
  {
    while ( v1 != this )
    {
      p_m_pNext = &v1->m_pNext;
      v1 = v1->m_pNext;
      if ( v1 == nullptr )
        goto LABEL_4;
    }
    *p_m_pNext = v1->m_pNext;
  }
LABEL_4:
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1019B670
// Name: private: bool CPhysicsNPCSolver::IsContactOnNPCHead(class IPhysicsFrictionSnapshot __near *,class IPhysicsObject __near *,class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsNPCSolver::IsContactOnNPCHead(
        CPhysicsNPCSolver *this,
        IPhysicsFrictionSnapshot *pSnapshot,
        IPhysicsObject *pPhysics,
        CAI_BaseNPC *pNPC)
{
  const Vector *v4; // eax
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // edx
  Vector point; // [esp+4h] [ebp-1Ch] BYREF
  Vector vel; // [esp+10h] [ebp-10h] BYREF
  float heightCheck; // [esp+1Ch] [ebp-4h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  if ( (pNPC->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pNPC, a2: (int)&savedregs);
  v4 = NAI_Hull::Maxs(id: pNPC->m_eHull);
  GetVelocity = pPhysics->GetVelocity;
  heightCheck = pNPC->m_vecAbsOrigin.z + v4->z;
  GetVelocity(this: pPhysics, a2: &vel, a3: nullptr);
  pSnapshot->GetContactPoint(this: pSnapshot, a2: &point);
  return (float)((float)((float)(vel.y * vel.y) + (float)(vel.x * vel.x)) + (float)(vel.z * vel.z)) < 100.0
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(point.z - heightCheck) & _mask__AbsFloat_) < 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x1019B740
// Name: public: virtual void CPhysicsEntitySolver::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEntitySolver::UpdateOnRemove(CPhysicsEntitySolver *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  unsigned int v4; // eax
  CBaseEntity *v5; // esi

  m_Index = this->m_hMovingEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = this->m_hPhysicsBlocker.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    v5 = nullptr;
  else
    v5 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    if ( v5 == nullptr )
      goto LABEL_14;
    PhysEnableEntityCollisions(pEntity0: m_pEntity, pEntity1: v5);
  }
  if ( v5 != nullptr )
    CBaseEntity::SetCollisionGroup(this: v5, collisionGroup: this->m_savedCollisionGroup);
LABEL_14:
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x1019B7D0
// Name: public: virtual void CPhysicsNPCSolver::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsNPCSolver::OnRestore(CPhysicsNPCSolver *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v4; // eax

  CBaseEntity::OnRestore(this);
  if ( this->m_allowIntersection )
  {
    m_Index = this->m_hEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v4 = this->m_hNPC.m_Index;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
      PhysDisableEntityCollisions(pEntity0: nullptr, pEntity1: m_pEntity);
    else
      PhysDisableEntityCollisions(
        pEntity0: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity,
        pEntity1: m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B880
// Name: private: void CPhysicsNPCSolver::BecomePenetrationSolver(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsNPCSolver::BecomePenetrationSolver(CPhysicsNPCSolver *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  unsigned int m_Index; // eax
  CBaseEntity **v5; // ecx
  CBaseEntity *v6; // esi
  int v7; // ebx
  unsigned int v8; // eax
  CBaseEntity *m_pEntity; // eax
  int v10; // esi
  _DWORD v12[1024]; // [esp+4h] [ebp-1000h] BYREF

  m_Index = this->m_hEntity.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v6 = *v5;
      if ( *v5 != nullptr )
      {
        this->m_allowIntersection = true;
        v7 = ((int (__thiscall *)(CBaseEntity *, _DWORD *, int, int, int))v6->VPhysicsGetObjectList)(
               a1: v6,
               a2: v12,
               a3: 1024,
               a4: a2,
               a5: a3);
        v8 = this->m_hNPC.m_Index;
        if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
        PhysDisableEntityCollisions(pEntity0: m_pEntity, pEntity1: v6);
        v10 = 0;
        for ( this->m_pController = physenv->CreateMotionController(this: physenv, a2: &this->IMotionEvent); v10 < v7; ++v10 )
        {
          this->m_pController->AttachObject(this: this->m_pController, a2: (IPhysicsObject *)v12[v10], a3: false);
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v12[v10] + 96))(a1: v12[v10]);
        }
        this->m_pController->SetPriority(this: this->m_pController, a2: HIGH_PRIORITY);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B990
// Name: public: virtual void CPhysicsNPCSolver::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsNPCSolver::Spawn(CPhysicsNPCSolver *this@<ecx>, int a2@<ebx>)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float thinkTime; // xmm0_4

  if ( this->m_allowIntersection )
  {
    CPhysicsNPCSolver::BecomePenetrationSolver(this, a2, a3: (int)this);
  }
  else
  {
    m_Index = this->m_hEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( *(float *)&m_pEntity[85].__vftable < 3.4028235e38 )
      m_pEntity[85].__vftable = (IHandleEntity_vtbl *)2139095039;
  }
  thinkTime = this->m_separationDuration + gpGlobals->curtime;
  this->m_cancelTime = thinkTime;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019BA20
// Name: public: virtual void CPhysicsNPCSolver::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsNPCSolver::UpdateOnRemove(CPhysicsNPCSolver *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v4; // eax
  unsigned int v5; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  IHandleEntity *v12; // eax

  if ( this->m_allowIntersection )
  {
    physenv->DestroyMotionController(this: physenv, a2: this->m_pController);
    this->m_pController = nullptr;
    m_Index = this->m_hEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v4 = this->m_hNPC.m_Index;
    if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    {
      PhysEnableEntityCollisions(pEntity0: nullptr, pEntity1: m_pEntity);
      CBaseEntity::UpdateOnRemove(this);
    }
    else
    {
      PhysEnableEntityCollisions(
        pEntity0: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity,
        pEntity1: m_pEntity);
      CBaseEntity::UpdateOnRemove(this);
    }
  }
  else
  {
    v5 = this->m_hEntity.m_Index;
    if ( v5 != -1 )
    {
      v6 = (unsigned __int16)v5;
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
      v8 = HIWORD(v5);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        v9 = v6;
        v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = &g_pEntityList->m_EntPtrArray[v9];
        if ( v10 )
          v12 = v11->m_pEntity;
        else
          v12 = nullptr;
        v12[85].__vftable = nullptr;
      }
    }
    CBaseEntity::UpdateOnRemove(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019BB20
// Name: private: bool CPhysicsNPCSolver::IsIntersecting(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CPhysicsNPCSolver::IsIntersecting@<al>(
        CPhysicsNPCSolver *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v6; // eax
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v8; // eax
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // edx
  float *v10; // eax
  float v11; // xmm1_4
  unsigned int v12; // eax
  IEngineTrace_vtbl *v13; // edi
  CBaseEntity_vtbl *v14; // edx
  int v15; // eax
  int v18; // [esp-Ch] [ebp-D4h] BYREF
  int *v19; // [esp-8h] [ebp-D0h]
  CGameTrace tr; // [esp+0h] [ebp-C8h] BYREF
  Ray_t ray; // [esp+58h] [ebp-70h] BYREF
  float v22; // [esp+A8h] [ebp-20h]
  Vector maxs; // [esp+ACh] [ebp-1Ch] BYREF
  Vector mins; // [esp+B8h] [ebp-10h] BYREF
  float retaddr; // [esp+C8h] [ebp+0h]

  mins.y = a2;
  mins.z = retaddr;
  m_Index = this->m_hNPC.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = this->m_hEntity.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    mins.x = 0.0;
  else
    LODWORD(mins.x) = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( m_pEntity == nullptr || LODWORD(mins.x) == 0 )
    return false;
  OBBMins = m_pEntity->m_Collision.OBBMins;
  ray.m_Extents.y = 0.0;
  v8 = (float *)((int (__thiscall *)(CBaseEntity::NetworkVar_m_Collision *, int, int, int, int *))OBBMins)(
                  a1: &m_pEntity->m_Collision,
                  a2: a3,
                  a3: a4,
                  a4: v18,
                  a5: v19);
  maxs.x = *v8 - 1.0;
  maxs.y = v8[1] - 1.0;
  OBBMaxs = m_pEntity->m_Collision.OBBMaxs;
  maxs.z = v8[2] - 1.0;
  v10 = (float *)OBBMaxs(this: &m_pEntity->m_Collision);
  *(float *)(&ray.m_IsSwept + 3) = *v10 + 1.0;
  *(float *)(&ray.m_IsSwept + 7) = v10[1] + 1.0;
  v11 = v10[2];
  v12 = (unsigned int)m_pEntity->m_iEFlags >> 11;
  v22 = v11 + 1.0;
  if ( (v12 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&mins.y);
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&mins.y);
  Ray_t::Init(
    this: (Ray_t *)&tr.m_pEnt,
    start: &m_pEntity->m_vecAbsOrigin,
    end: &m_pEntity->m_vecAbsOrigin,
    mins: &maxs,
    maxs: (const Vector *)(&ray.m_IsSwept + 3));
  v13 = enginetrace->__vftable;
  v14 = m_pEntity->__vftable;
  v19 = &v18;
  v15 = ((int (__thiscall *)(CBaseEntity *, _DWORD))v14->PhysicsSolidMaskForEntity)(a1: m_pEntity, a2: LODWORD(mins.x));
  ((void (__thiscall *)(IEngineTrace *, CBaseEntity **, int))v13->ClipRayToEntity)(
    a1: enginetrace,
    a2: &tr.m_pEnt,
    a3: v15);
  return tr.plane.pad[1] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019BCD0
// Name: private: bool CPhysicsNPCSolver::CheckTouching(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CPhysicsNPCSolver::CheckTouching@<al>(CPhysicsNPCSolver *this@<ecx>, int a2@<ebx>)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // esi
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  IPhysicsObject *v9; // edi
  int v10; // ebx
  IPhysicsFrictionSnapshot *v11; // esi
  IHandleEntity *v13; // [esp+8h] [ebp-10h]
  CAI_BaseNPC *pNPC; // [esp+Ch] [ebp-Ch]
  bool found; // [esp+16h] [ebp-2h]
  bool penetrate; // [esp+17h] [ebp-1h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  m_Index = this->m_hNPC.m_Index;
  if ( m_Index == -1 )
    return false;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return false;
  m_pEntity = v4->m_pEntity;
  pNPC = (CAI_BaseNPC *)v4->m_pEntity;
  if ( v4->m_pEntity == nullptr )
    return false;
  v7 = this->m_hEntity.m_Index;
  if ( v7 == -1 )
    return false;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    return false;
  v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  v13 = v8;
  if ( v8 == nullptr )
    return false;
  v9 = (IPhysicsObject *)v8[82].__vftable;
  v10 = (int)m_pEntity[82].__vftable;
  if ( v10 == 0 || v9 == nullptr )
    return false;
  v11 = (IPhysicsFrictionSnapshot *)((int (__thiscall *)(IPhysicsObject *, int))v9->CreateFrictionSnapshot)(a1: v9, a2);
  found = false;
  penetrate = false;
  if ( v11->IsValid(this: v11) )
  {
    while ( v11->GetObject(this: v11, a2: 1) != (IPhysicsObject *)v10 )
    {
      v11->NextFrictionData(this: v11);
      if ( !v11->IsValid(this: v11) )
        goto LABEL_16;
    }
    found = true;
    if ( CPhysicsNPCSolver::IsContactOnNPCHead(this, pSnapshot: v11, pPhysics: v9, pNPC) )
    {
      penetrate = true;
      v11->MarkContactForDelete(this: v11);
    }
  }
LABEL_16:
  v11->DeleteAllMarkedContacts(this: v11, a2: true);
  v9->DestroyFrictionSnapshot(this: v9, a2: v11);
  if ( penetrate
    || (((int (__thiscall *)(IPhysicsObject *))v9->GetGameFlags)(a1: v9) & 0x40) != 0
    && CPhysicsNPCSolver::IsIntersecting(this, a2: COERCE_FLOAT(&savedregs), a3: (int)v9, a4: (int)v11) )
  {
    v13[85].__vftable = nullptr;
    CPhysicsNPCSolver::BecomePenetrationSolver(this, a2: v10, a3: (int)v11);
  }
  return found;
}

//------------------------------------------------------------------------------
// Address: 0x1019BE30
// Name: public: virtual void CPhysicsNPCSolver::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysicsNPCSolver::Think(CPhysicsNPCSolver *this@<ecx>, int a2@<ebx>, float a3@<ebp>, int a4@<edi>)
{
  bool IsIntersecting; // al
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v8; // eax
  float thinkTime; // xmm0_4

  if ( this->m_allowIntersection )
    IsIntersecting = CPhysicsNPCSolver::IsIntersecting(this, a2: a3, a3: a4, a4: (int)this);
  else
    IsIntersecting = CPhysicsNPCSolver::CheckTouching(this, a2);
  if ( !IsIntersecting )
  {
LABEL_5:
    UTIL_Remove(oldObj: this);
    return;
  }
  if ( this->m_allowIntersection )
  {
    m_Index = this->m_hEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v8 = m_pEntity[82].__vftable;
    if ( v8 == nullptr )
      goto LABEL_5;
    (*((void (__thiscall **)(IHandleEntity_vtbl *))v8->dtr_IHandleEntity + 24))(a1: v8);
  }
  thinkTime = this->m_separationDuration + gpGlobals->curtime;
  this->m_cancelTime = thinkTime;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019BEE0
// Name: public: virtual enum IMotionEvent::simresult_e CPhysicsNPCSolver::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CPhysicsNPCSolver::Simulate@<eax>(
        CPhysicsNPCSolver *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  float thinkTime; // xmm0_4
  IPhysicsObject_vtbl *v10; // edx
  unsigned __int16 (__thiscall *GetGameFlags)(IPhysicsObject *); // eax
  CServerNetworkProperty_vtbl *v12; // eax
  IHandleEntity *m_pEntity; // ecx
  void (__thiscall *m_pfnThink)(CBaseEntity *); // eax
  CBaseEntity *v16; // ebx
  float v17; // xmm0_4
  bool (__thiscall *GetContactPoint)(IPhysicsObject *, Vector *, IPhysicsObject **); // edx
  Vector vel; // [esp+20h] [ebp-48h] BYREF
  Vector inputVelocity; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector angVel; // [esp+38h] [ebp-30h] BYREF
  Vector origin; // [esp+44h] [ebp-24h] BYREF
  Vector pushImpulse; // [esp+50h] [ebp-18h] BYREF
  Vector dir; // [esp+5Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  if ( !CPhysicsNPCSolver::IsIntersecting(
          this: (CPhysicsNPCSolver *)((char *)this - 852),
          a2: COERCE_FLOAT(&savedregs),
          a3: a2,
          a4: a3) )
    return 0;
  if ( (((int (__thiscall *)(IPhysicsObject *))pObject->GetGameFlags)(a1: pObject) & 4) != 0 )
    UTIL_GetLocalPlayer();
  thinkTime = *(float *)&this->m_Network.m_pOuter + gpGlobals->curtime;
  *(float *)&this->m_Network.m_pPev = thinkTime;
  CBaseEntity::SetNextThink(this: (CPhysicsNPCSolver *)((char *)this - 852), thinkTime, szContext: nullptr);
  v10 = pObject->__vftable;
  angular->x = 0.0;
  angular->y = 0.0;
  angular->z = 0.0;
  GetGameFlags = v10->GetGameFlags;
  linear->x = 0.0;
  linear->y = 0.0;
  linear->z = 0.0;
  if ( (((int (__thiscall *)(IPhysicsObject *))GetGameFlags)(a1: pObject) & 0x10) != 0 )
  {
    v12 = this->m_Network.CLogicalEntity::CServerOnlyEntity::CBaseEntity::__vftable;
    if ( v12 == (CServerNetworkProperty_vtbl *)-1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != (unsigned int)v12 >> 16 )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
    }
    if ( ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[30].SetRefEHandle)(a1: m_pEntity) != 0 )
      return 0;
  }
  pObject->GetPosition(this: pObject, a2: &origin, a3: nullptr);
  pObject->GetVelocity(this: pObject, a2: &vel, a3: nullptr);
  m_pfnThink = this->m_pfnThink;
  if ( m_pfnThink == (void (__thiscall *)(CBaseEntity *))-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pfnThink].m_SerialNumber != (unsigned int)m_pfnThink >> 16 )
  {
    v16 = nullptr;
  }
  else
  {
    v16 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pfnThink].m_pEntity;
  }
  if ( (v16->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&savedregs);
  dir.x = origin.x - v16->m_vecAbsOrigin.x;
  dir.y = origin.y - v16->m_vecAbsOrigin.y;
  if ( (float)(origin.z - v16->m_vecAbsOrigin.z) <= 0.0 )
    v17 = -0.1;
  else
    v17 = 0.1;
  dir.z = v17;
  VectorNormalize(vec: &dir);
  inputVelocity.x = dir.x * 150.0;
  inputVelocity.y = dir.y * 150.0;
  memset((void *)&angVel, 0, sizeof(angVel));
  inputVelocity.z = dir.z * 150.0;
  PhysComputeSlideDirection(
    a1: (int)pObject,
    pPhysics: pObject,
    &inputVelocity,
    inputAngularVelocity: &angVel,
    pOutputVelocity: &pushImpulse,
    pOutputAngularVelocity: nullptr,
    minMass: 0.0);
  dir = pushImpulse;
  VectorNormalize(vec: &dir);
  if ( (float)((float)((float)(vel.y * dir.y) + (float)(vel.x * dir.x)) + (float)(vel.z * dir.z)) < 75.0 )
  {
    GetContactPoint = pObject->GetContactPoint;
    *linear = pushImpulse;
    if ( GetContactPoint(this: pObject, a2: nullptr, a3: nullptr) )
      linear->z = sv_gravity.m_pParent->m_Value.m_fValue + linear->z;
  }
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1019C190
// Name: public: static class CPhysicsEntitySolver __near * CPhysicsEntitySolver::Create(class CBaseEntity __near *,class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
CPhysicsEntitySolver *__cdecl CPhysicsEntitySolver::Create(
        CBaseEntity *pMovingEntity,
        CBaseEntity *pPhysicsBlocker,
        void (__thiscall *separationTime)(CBaseEntity *this))
{
  CBaseEntity *NoSpawn; // eax
  CBaseEntity *v4; // esi
  void (__thiscall *Spawn)(CBaseEntity *); // eax

  NoSpawn = CBaseEntity::CreateNoSpawn(
              szName: "physics_entity_solver",
              vecOrigin: &vec3_origin,
              vecAngles: &vec3_angle,
              pOwner: nullptr);
  v4 = NoSpawn;
  if ( pMovingEntity != nullptr )
    NoSpawn[1].__vftable = (CBaseEntity_vtbl *)pMovingEntity->GetRefEHandle(this: pMovingEntity)->m_Index;
  else
    NoSpawn[1].__vftable = (CBaseEntity_vtbl *)-1;
  if ( pPhysicsBlocker != nullptr )
    v4[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))pPhysicsBlocker->GetRefEHandle(this: pPhysicsBlocker)->m_Index;
  else
    v4[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))-1;
  Spawn = v4->Spawn;
  v4[1].m_pfnThink = separationTime;
  Spawn(this: v4);
  return (CPhysicsEntitySolver *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1019C210
// Name: public: virtual void CPhysicsEntitySolver::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsEntitySolver::Spawn(CPhysicsEntitySolver *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v4; // eax
  CBaseEntity *v5; // ecx
  unsigned int v6; // eax
  IHandleEntity *v7; // ecx
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  unsigned int v10; // eax
  IHandleEntity *v11; // ecx

  CBaseEntity::SetNextThink(this, thinkTime: this->m_separationDuration + gpGlobals->curtime, szContext: nullptr);
  m_Index = this->m_hPhysicsBlocker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v4 = this->m_hMovingEntity.m_Index;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    v5 = nullptr;
  else
    v5 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  PhysDisableEntityCollisions(pEntity0: v5, pEntity1: m_pEntity);
  v6 = this->m_hPhysicsBlocker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  this->m_savedCollisionGroup = (int)v7[81].__vftable;
  v8 = this->m_hPhysicsBlocker.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  CBaseEntity::SetCollisionGroup(this: v9, collisionGroup: 1);
  v10 = this->m_hPhysicsBlocker.m_Index;
  if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
    v11 = nullptr;
  else
    v11 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  if ( v11[82].__vftable != nullptr )
  {
    if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
      (*(void (__thiscall **)(_DWORD, _DWORD))(*MEMORY[0x148] + 108))(a1: MEMORY[0x148], a2: 0);
    else
      (*((void (__thiscall **)(IHandleEntity_vtbl *, _DWORD))g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity[82].dtr_IHandleEntity
       + 27))(
        a1: g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity[82].__vftable,
        a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C380
// Name: class CBaseEntity __near * EntityPhysics_CreateSolver(class CBaseEntity __near *,class CBaseEntity __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
CPhysicsEntitySolver *__cdecl EntityPhysics_CreateSolver(
        CBaseEntity *pMovingEntity,
        CBaseEntity *pPhysicsObject,
        bool disableCollisions,
        void (__thiscall *separationDuration)(CBaseEntity *this))
{
  if ( PhysEntityCollisionsAreDisabled(pEntity0: pMovingEntity, pEntity1: pPhysicsObject) )
    return nullptr;
  else
    return CPhysicsEntitySolver::Create(
             pMovingEntity,
             pPhysicsBlocker: pPhysicsObject,
             separationTime: separationDuration);
}

//------------------------------------------------------------------------------
// Address: 0x1019C440
// Name: public: void CPhysicsNPCSolver::Init(class CAI_BaseNPC __near *,class CBaseEntity __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsNPCSolver::Init(
        CPhysicsNPCSolver *this,
        CAI_BaseNPC *pNPC,
        CBaseEntity *pPhysicsObject,
        bool disableCollisions,
        float separationTime)
{
  if ( pNPC != nullptr )
    this->m_hNPC.m_Index = pNPC->GetRefEHandle(this: pNPC)->m_Index;
  else
    this->m_hNPC.m_Index = -1;
  if ( pPhysicsObject != nullptr )
    this->m_hEntity.m_Index = pPhysicsObject->GetRefEHandle(this: pPhysicsObject)->m_Index;
  else
    this->m_hEntity.m_Index = -1;
  this->m_pController = nullptr;
  this->m_separationDuration = separationTime;
  this->m_allowIntersection = disableCollisions;
}

//------------------------------------------------------------------------------
// Address: 0x1019C520
// Name: class CBaseEntity __near * NPCPhysics_CreateSolver(class CAI_BaseNPC __near *,class CBaseEntity __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
CPhysicsNPCSolver *__cdecl NPCPhysics_CreateSolver(
        CAI_BaseNPC *pNPC,
        CBaseEntity *pPhysicsObject,
        bool disableCollisions,
        float separationDuration)
{
  CPhysicsNPCSolver *NoSpawn; // esi

  if ( disableCollisions )
  {
    if ( PhysEntityCollisionsAreDisabled(pEntity0: pNPC, pEntity1: pPhysicsObject) )
      return nullptr;
  }
  else if ( pPhysicsObject->m_flNavIgnoreUntilTime >= gpGlobals->curtime )
  {
    return nullptr;
  }
  NoSpawn = (CPhysicsNPCSolver *)CBaseEntity::CreateNoSpawn(
                                   szName: "physics_npc_solver",
                                   vecOrigin: &vec3_origin,
                                   vecAngles: &vec3_angle,
                                   pOwner: nullptr);
  CPhysicsNPCSolver::Init(this: NoSpawn, pNPC, pPhysicsObject, disableCollisions, separationTime: separationDuration);
  NoSpawn->Spawn(this: NoSpawn);
  return NoSpawn;
}

//------------------------------------------------------------------------------
// Address: 0x10407620
// Name: CPhysicsNPCSolver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsNPCSolver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsNPCSolver>(__formal: nullptr);
  CPhysicsNPCSolver_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407670
// Name: CPhysicsEntitySolver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsEntitySolver_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsEntitySolver>(__formal: nullptr);
  CPhysicsEntitySolver_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C3C0
// Name: class CPhysicsNPCSolver __near * _CreateEntityTemplate<class CPhysicsNPCSolver>(class CPhysicsNPCSolver __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysicsNPCSolver *__cdecl _CreateEntityTemplate<CPhysicsNPCSolver>(CPhysicsNPCSolver *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CPhysicsNPCSolver *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = (CPhysicsNPCSolver *)v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->IMotionEvent::__vftable = (IMotionEvent_vtbl *)&IMotionEvent::`vftable';
    v3->CLogicalEntity::CServerOnlyEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsNPCSolver_vtbl *)&CPhysicsNPCSolver::`vftable'{for `CLogicalEntity'};
    v3->IMotionEvent::__vftable = (IMotionEvent_vtbl *)&CPhysicsNPCSolver::`vftable'{for `IMotionEvent'};
    v3->m_hNPC.m_Index = -1;
    v3->m_hEntity.m_Index = -1;
    v3->m_pNext = CEntityClassList<CPhysicsNPCSolver>::m_pClassList;
    CEntityClassList<CPhysicsNPCSolver>::m_pClassList = v3;
    v3->PostConstructor(this: v3, a2: className);
    return v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C5A0
// Name: struct datamap_t __near * DataMapInit<class CPhysicsNPCSolver>(class CPhysicsNPCSolver __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsNPCSolver>()
{
  if ( (_S2_166 & 1) == 0 )
  {
    _S2_166 |= 1u;
    nameHolder_309.m_pszBase = "CPhysicsNPCSolver";
    nameHolder_309.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_309.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_309.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_309.m_Names.m_Size = 0;
    nameHolder_309.m_Names.m_pElements = nullptr;
    nameHolder_309.m_nLenBase = 17;
    atexit(func: DataMapInit_CPhysicsNPCSolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsNPCSolver::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_166 & 2) == 0 )
  {
    _S2_166 |= 2u;
    dataDesc_296[6].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    dataDesc_296[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_296[6].td = 0;
    *(_QWORD *)&dataDesc_296[6].override_field = 0;
    *(_QWORD *)&dataDesc_296[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_296[6].flatOffset[1] = 0;
  }
  CPhysicsNPCSolver::m_DataMap.dataNumFields = 6;
  CPhysicsNPCSolver::m_DataMap.dataDesc = &dataDesc_296[1];
  return &CPhysicsNPCSolver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1019C670
// Name: struct datamap_t __near * DataMapInit<class CPhysicsEntitySolver>(class CPhysicsEntitySolver __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsEntitySolver>()
{
  if ( (_S3_90 & 1) == 0 )
  {
    _S3_90 |= 1u;
    nameHolder_310.m_pszBase = "CPhysicsEntitySolver";
    nameHolder_310.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_310.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_310.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_310.m_Names.m_Size = 0;
    nameHolder_310.m_Names.m_pElements = nullptr;
    nameHolder_310.m_nLenBase = 20;
    atexit(func: DataMapInit_CPhysicsEntitySolver__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsEntitySolver::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPhysicsEntitySolver::m_DataMap.dataNumFields = 5;
  CPhysicsEntitySolver::m_DataMap.dataDesc = &dataDesc_297[1];
  return &CPhysicsEntitySolver::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10407630
// Name: _dynamic_initializer_for__g_SolverList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SolverList__()
{
  CBaseEntityClassList::CBaseEntityClassList(this: &g_SolverList);
  g_SolverList.__vftable = (CEntityClassList<CPhysicsNPCSolver>_vtbl *)&CEntityClassList<CPhysicsNPCSolver>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_SolverList__);
}
