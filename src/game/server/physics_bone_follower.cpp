// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_bone_follower.cpp
// Functions: 44
// ============================================================

#include "game\server\physics_bone_follower.h"

//------------------------------------------------------------------------------
// Address: 0x1018D230
// Name: private: virtual struct datamap_t __near * CBoneFollower::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBoneFollower::GetDataDescMap(CBoneFollower *this)
{
  return &CBoneFollower::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018D240
// Name: public: virtual class ServerClass __near * CBoneFollower::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBoneFollower::GetServerClass(CBoneFollower *this)
{
  return &g_CBoneFollower_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1018D250
// Name: HitGroupFromPhysicsBone
// Source: json
//------------------------------------------------------------------------------
int __usercall HitGroupFromPhysicsBone@<eax>(CBaseAnimating *pAnim@<eax>, int physicsBone)
{
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v4; // ecx
  int v5; // eax
  int v6; // edx
  _DWORD *i; // esi

  if ( pAnim->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pAnim) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pAnim);
  m_pStudioHdr = pAnim->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v4 = m_pStudioHdr->m_pStudioHdr;
  v5 = (int)m_pStudioHdr->m_pStudioHdr + 12 * pAnim->m_nHitboxSet.m_Value + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  v6 = 0;
  if ( *(int *)(v5 + 4) <= 0 )
    return 0;
  for ( i = (_DWORD *)(v5 + *(_DWORD *)(v5 + 8));
        *(int *)((char *)&v4->numhitboxsets + 216 * *i + v4->boneindex) != physicsBone;
        i += 17 )
  {
    if ( ++v6 >= *(_DWORD *)(v5 + 4) )
      return 0;
  }
  return *(_DWORD *)(*(_DWORD *)(v5 + 8) + 68 * v6 + v5 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1018D2F0
// Name: public: virtual void CBoneFollower::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::VPhysicsUpdate(CBoneFollower *this, IPhysicsObject *pPhysics)
{
  QAngle angles; // [esp+4h] [ebp-18h] BYREF
  Vector origin; // [esp+10h] [ebp-Ch] BYREF

  pPhysics->GetPosition(this: pPhysics, a2: &origin, a3: &angles);
  CBaseEntity::SetAbsOrigin(this, absOrigin: &origin);
  CBaseEntity::SetAbsAngles(this, absAngles: &angles);
}

//------------------------------------------------------------------------------
// Address: 0x1018D330
// Name: public: struct physfollower_t __near * CBoneFollowerManager::GetBoneFollower(int)
// Source: json
//------------------------------------------------------------------------------
physfollower_t *__thiscall CBoneFollowerManager::GetBoneFollower(CBoneFollowerManager *this, int iFollowerIndex)
{
  if ( iFollowerIndex < 0 || iFollowerIndex >= this->m_iNumBones )
    return nullptr;
  else
    return &this->m_physBones.m_Memory.m_pMemory[iFollowerIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1018D420
// Name: public: virtual void CBoneFollower::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::VPhysicsCollision(CBoneFollower *this, int index, gamevcollisionevent_t *pEvent)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v4; // eax
  CBaseEntity *v5; // esi
  IPhysicsObject *m_pPhysicsObject; // edi
  IPhysicsObject *v7; // [esp-10h] [ebp-10h]

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v5 = *v4;
      if ( *v4 != nullptr )
      {
        m_pPhysicsObject = v5->m_pPhysicsObject;
        v7 = pEvent->pObjects[index];
        if ( m_pPhysicsObject != nullptr )
          CBaseEntity::VPhysicsSwapObject(this: v5, pSwap: v7);
        else
          CBaseEntity::VPhysicsSetObject(this: v5, pPhysics: v7);
        v5->VPhysicsCollision(this: v5, a2: index, a3: pEvent);
        CBaseEntity::VPhysicsSwapObject(this: v5, pSwap: m_pPhysicsObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D4A0
// Name: public: virtual void CBoneFollower::VPhysicsShadowCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::VPhysicsShadowCollision(CBoneFollower *this, int index, gamevcollisionevent_t *pEvent)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v4; // eax
  CBaseEntity *v5; // esi
  IPhysicsObject *m_pPhysicsObject; // edi
  IPhysicsObject *v7; // [esp-10h] [ebp-10h]

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v5 = *v4;
      if ( *v4 != nullptr )
      {
        m_pPhysicsObject = v5->m_pPhysicsObject;
        v7 = pEvent->pObjects[index];
        if ( m_pPhysicsObject != nullptr )
          CBaseEntity::VPhysicsSwapObject(this: v5, pSwap: v7);
        else
          CBaseEntity::VPhysicsSetObject(this: v5, pPhysics: v7);
        v5->VPhysicsShadowCollision(this: v5, a2: index, a3: pEvent);
        CBaseEntity::VPhysicsSwapObject(this: v5, pSwap: m_pPhysicsObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D520
// Name: public: virtual void CBoneFollower::VPhysicsFriction(class IPhysicsObject __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::VPhysicsFriction(
        CBoneFollower *this,
        IPhysicsObject *pObject,
        float energy,
        int surfaceProps,
        int surfacePropsHit)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v6; // eax
  CBaseEntity *v7; // esi
  IPhysicsObject *m_pPhysicsObject; // ebx

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v6 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v7 = *v6;
      if ( *v6 != nullptr )
      {
        m_pPhysicsObject = v7->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
          CBaseEntity::VPhysicsSwapObject(this: v7, pSwap: pObject);
        else
          CBaseEntity::VPhysicsSetObject(this: v7, pPhysics: pObject);
        ((void (__thiscall *)(CBaseEntity *, IPhysicsObject *, _DWORD, int, int))v7->VPhysicsFriction)(
          a1: v7,
          a2: pObject,
          a3: LODWORD(energy),
          a4: surfaceProps,
          a5: surfacePropsHit);
        CBaseEntity::VPhysicsSwapObject(this: v7, pSwap: m_pPhysicsObject);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D5A0
// Name: public: virtual bool CBoneFollower::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBoneFollower::TestCollision(
        CBoneFollower *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  IVModelInfo_vtbl *v5; // edi
  int v6; // eax
  int v7; // ebx
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v5 = modelinfo->__vftable;
  v6 = this->GetModelIndex(this);
  v7 = (int)v5->GetVCollide(this: modelinfo, a2: v6);
  UTIL_ClearTrace(trace);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  physcollision->TraceBox_2(
    this: physcollision,
    a2: ray,
    a3: *(const struct CPhysCollide **)(*(_DWORD *)(v7 + 4) + 4 * this->m_solidIndex.m_Value),
    a4: &this->m_vecAbsOrigin,
    a5: &this->m_angAbsRotation,
    a6: trace);
  if ( trace->fraction >= 1.0 )
    return 0;
  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  trace->m_pEnt = m_pEntity;
  trace->hitgroup = this->m_hitGroup;
  trace->physicsbone = this->m_physicsBone;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018D690
// Name: public: virtual int CBoneFollower::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBoneFollower::ObjectCaps(CBoneFollower *this)
{
  unsigned int m_Index; // ecx
  CEntInfo *v3; // eax
  IHandleEntity *m_pEntity; // ecx
  int v5; // edi

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 )
    return CBaseEntity::ObjectCaps(this);
  v3 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return CBaseEntity::ObjectCaps(this);
  m_pEntity = v3->m_pEntity;
  if ( v3->m_pEntity == nullptr || m_pEntity[127].__vftable == nullptr )
    return CBaseEntity::ObjectCaps(this);
  v5 = (int)m_pEntity->__vftable[12].GetRefEHandle(this: m_pEntity);
  return (v5 | CBaseEntity::ObjectCaps(this)) & 0xFFFFFF7F;
}

//------------------------------------------------------------------------------
// Address: 0x1018D6F0
// Name: public: virtual void CBoneFollower::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::Use(
        CBoneFollower *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    ((void (__thiscall *)(IHandleEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, _DWORD))m_pEntity->__vftable[33].dtr_IHandleEntity)(
      a1: m_pEntity,
      a2: pActivator,
      a3: pCaller,
      a4: useType,
      a5: LODWORD(value));
  }
  else
  {
    CBaseEntity::Use(this, pActivator, pCaller, useType, value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D770
// Name: public: virtual void CBoneFollower::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::Touch(CBoneFollower *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    ((void (__thiscall *)(IHandleEntity *, CBaseEntity *))m_pEntity->__vftable[33].GetRefEHandle)(
      a1: m_pEntity,
      a2: pOther);
  }
  else
  {
    CBaseEntity::Touch(this, pOther);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D7C0
// Name: public: virtual void CBoneFollower::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollower::TraceAttack(
        CBoneFollower *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  unsigned int m_Index; // edx
  CBaseEntity *m_pEntity; // eax

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    CBaseEntity::DispatchTraceAttack(this: m_pEntity, info, vecDir, ptr);
  }
  else
  {
    CBaseEntity::TraceAttack(this, info, vecDir, ptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018D8C0
// Name: public: void CBoneFollowerManager::UpdateBoneFollowers(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBoneFollowerManager::UpdateBoneFollowers(
        CBoneFollowerManager *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        CBaseAnimating *pParentEntity)
{
  int i; // esi
  physfollower_t *v6; // edx
  unsigned int m_Index; // eax
  physfollower_t *m_pMemory; // eax
  unsigned int v9; // eax
  IHandleEntity *m_pEntity; // ecx
  matrix3x4_t boneToWorld; // [esp+18h] [ebp-48h] BYREF
  QAngle boneAngles; // [esp+48h] [ebp-18h] BYREF
  Vector bonePosition; // [esp+54h] [ebp-Ch] BYREF

  if ( this->m_iNumBones != 0 )
  {
    for ( i = 0; i < this->m_iNumBones; ++i )
    {
      v6 = &this->m_physBones.m_Memory.m_pMemory[i];
      m_Index = v6->hFollower.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        ((void (__thiscall *)(CBaseAnimating *, int, matrix3x4_t *, int, int))pParentEntity->GetBoneTransform)(
          a1: pParentEntity,
          a2: v6->boneIndex,
          a3: &boneToWorld,
          a4: a2,
          a5: a3);
        MatrixAngles(a1: i, src: (const VMatrix *)&boneToWorld, vAngles: &boneAngles);
        m_pMemory = this->m_physBones.m_Memory.m_pMemory;
        bonePosition.x = boneToWorld.m_flMatVal[0][3];
        bonePosition.y = boneToWorld.m_flMatVal[1][3];
        bonePosition.z = boneToWorld.m_flMatVal[2][3];
        v9 = m_pMemory[i].hFollower.m_Index;
        if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
        a3 = 1036831949;
        a2 = 0;
        (*((void (__stdcall **)(Vector *, QAngle *))m_pEntity[82].dtr_IHandleEntity + 69))(
          a1: &bonePosition,
          a2: &boneAngles);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018DA10
// Name: public: void CBoneFollowerManager::DestroyBoneFollowers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollowerManager::DestroyBoneFollowers(CBoneFollowerManager *this)
{
  int v2; // edi
  CBaseEntityList *v3; // ebx
  CHandle<CBoneFollower> *p_hFollower; // edx
  unsigned int m_Index; // eax
  unsigned int v6; // eax
  CBaseEntity *m_pEntity; // ecx
  bool v8; // sf

  v2 = 0;
  if ( this->m_iNumBones > 0 )
  {
    v3 = g_pEntityList;
    do
    {
      p_hFollower = &this->m_physBones.m_Memory.m_pMemory[v2].hFollower;
      m_Index = p_hFollower->m_Index;
      if ( p_hFollower->m_Index != -1
        && v3->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && v3->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        v6 = p_hFollower->m_Index;
        if ( p_hFollower->m_Index == -1 || v3->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CBaseEntity *)v3->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
        UTIL_Remove(oldObj: m_pEntity);
        this->m_physBones.m_Memory.m_pMemory[v2].hFollower.m_Index = -1;
        v3 = g_pEntityList;
      }
      ++v2;
    }
    while ( v2 < this->m_iNumBones );
  }
  v8 = this->m_physBones.m_Memory.m_nGrowSize < 0;
  this->m_physBones.m_Size = 0;
  if ( !v8 )
  {
    if ( this->m_physBones.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_physBones.m_Memory.m_pMemory);
      this->m_physBones.m_Memory.m_pMemory = nullptr;
    }
    this->m_physBones.m_Memory.m_nAllocationCount = 0;
  }
  this->m_physBones.m_pElements = this->m_physBones.m_Memory.m_pMemory;
  this->m_iNumBones = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1018DAD0
// Name: public: bool CBoneFollower::Init(class CBaseEntity __near *,char const __near *,struct solid_t __near &,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBoneFollower::Init(
        CBoneFollower *this,
        CBaseEntity *pOwner,
        const char *pModelName,
        solid_t *solid,
        const Vector *position,
        const QAngle *orientation)
{
  int v7; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  IPhysicsObject *inited; // esi
  unsigned __int16 v12; // ax
  IPhysicsCollision_vtbl *v13; // ebx
  int v14; // eax
  IPhysicsObject_vtbl *v15; // edi
  unsigned __int16 v16; // ax
  int v17; // eax
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  this->SetOwnerEntity(this, a2: pOwner);
  UTIL_SetModel(pEntity: this, pModelName);
  CBaseEntity::AddEffects(this, nEffects: 32);
  v7 = modelinfo->GetModelIndex(this: modelinfo, a2: pModelName);
  if ( this->m_modelIndex.m_Value != v7 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    this->m_modelIndex.m_Value = v7;
  }
  if ( this->m_solidIndex.m_Value != solid->index )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x358u);
    }
    this->m_solidIndex.m_Value = solid->index;
  }
  CBaseEntity::SetAbsOrigin(this, absOrigin: position);
  CBaseEntity::SetAbsAngles(this, absAngles: orientation);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_PUSH, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: pOwner->m_CollisionGroup.m_Value);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  solid->params.pGameData = this;
  inited = CBaseEntity::VPhysicsInitShadow(this, allowPhysicsMovement: 0, allowPhysicsRotation: 0, pSolid: solid);
  if ( inited == nullptr )
    return 0;
  v12 = inited->GetGameFlags(this: inited);
  inited->SetGameFlags(this: inited, a2: v12 | 0x1000);
  v13 = physcollision->__vftable;
  v14 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *))inited->GetCollide)(
          a1: inited,
          a2: &vec3_origin,
          a3: &vec3_angle);
  ((void (__thiscall *)(IPhysicsCollision *, Vector *, Vector *, int))v13->CollideGetAABB)(
    a1: physcollision,
    a2: &mins,
    a3: &maxs,
    a4: v14);
  CBaseEntity::SetCollisionBounds(this, &mins, &maxs);
  v15 = inited->__vftable;
  v16 = inited->GetCallbackFlags(this: inited);
  v15->SetCallbackFlags(this: inited, a2: v16 | 4);
  inited->EnableGravity(this: inited, a2: false);
  if ( pOwner->IsNPC(this: pOwner) )
  {
    v17 = (int)inited->GetShadowController(this: inited);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v17 + 28))(a1: v17, a2: 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018DD20
// Name: public: CBoneFollowerManager::CBoneFollowerManager(void)
// Source: json
//------------------------------------------------------------------------------
CBoneFollowerManager *__thiscall CBoneFollowerManager::CBoneFollowerManager(CBoneFollowerManager *this)
{
  this->m_physBones.m_Memory.m_pMemory = nullptr;
  this->m_physBones.m_Memory.m_nAllocationCount = 0;
  this->m_physBones.m_Memory.m_nGrowSize = 0;
  this->m_physBones.m_Size = 0;
  this->m_physBones.m_pElements = nullptr;
  this->m_iNumBones = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018DD40
// Name: public: CBoneFollowerManager::~CBoneFollowerManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollowerManager::~CBoneFollowerManager(CBoneFollowerManager *this)
{
  CBoneFollowerManager::DestroyBoneFollowers(this);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_physBones);
}

//------------------------------------------------------------------------------
// Address: 0x1018DD60
// Name: private: bool CBoneFollowerManager::CreatePhysicsFollower(class CBaseAnimating __near *,struct physfollower_t __near &,char const __near *,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBoneFollowerManager::CreatePhysicsFollower(
        CBoneFollowerManager *this,
        CBaseAnimating *pParentEntity,
        physfollower_t *follow,
        char *pBoneName,
        solid_t *pSolid)
{
  CStudioHdr *m_pStudioHdr; // esi
  const char *v7; // edi
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v11; // eax
  physfollower_t *v12; // edi
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  IServerNetworkable *EntityByName; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  unsigned int v17; // eax
  CBaseEntity *v18; // esi
  bool v19; // al
  int v21; // [esp-4h] [ebp-698h]
  solid_t solidTmp; // [esp+Ch] [ebp-688h] BYREF
  matrix3x4_t boneToWorld; // [esp+64Ch] [ebp-48h] BYREF
  QAngle boneAngles; // [esp+67Ch] [ebp-18h] BYREF
  Vector bonePosition; // [esp+688h] [ebp-Ch] BYREF
  int boneIndex; // [esp+69Ch] [ebp+8h]
  const char *boneIndexa; // [esp+69Ch] [ebp+8h]

  if ( pParentEntity->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: pParentEntity) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pParentEntity);
  m_pStudioHdr = pParentEntity->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v7 = pBoneName;
  v8 = Studio_BoneIndexByName(pStudioHdr: m_pStudioHdr, pName: pBoneName);
  boneIndex = v8;
  if ( v8 < 0 )
  {
    _Warning(a1: "ERROR: Tried to create bone follower on invalid bone %s\n", v7);
    return 0;
  }
  v9 = *(const char **)((char *)&m_pStudioHdr->m_pStudioHdr->numhitboxsets
                      + 216 * v8
                      + m_pStudioHdr->m_pStudioHdr->boneindex);
  pBoneName = (char *)v9;
  if ( pSolid == nullptr )
  {
    v21 = (int)v9;
    v10 = pParentEntity->GetModelIndex(this: pParentEntity);
    if ( PhysModelParseSolidByIndex(
           a1: (int)v7,
           solid: &solidTmp,
           pEntity: pParentEntity,
           modelIndex: v10,
           solidIndex: v21) )
    {
      pSolid = &solidTmp;
      goto LABEL_11;
    }
    return 0;
  }
LABEL_11:
  v11 = Studio_BoneIndexByName(pStudioHdr: m_pStudioHdr, pName: pSolid->name);
  v12 = follow;
  follow->boneIndex = v11;
  if ( v11 < 0 )
    v12->boneIndex = boneIndex;
  pParentEntity->GetBoneTransform(this: pParentEntity, a2: v12->boneIndex, a3: &boneToWorld);
  MatrixAngles(a1: (int)m_pStudioHdr, src: (const VMatrix *)&boneToWorld, vAngles: &boneAngles);
  GetModelName = pParentEntity->GetModelName;
  bonePosition.x = boneToWorld.m_flMatVal[0][3];
  bonePosition.y = boneToWorld.m_flMatVal[1][3];
  bonePosition.z = boneToWorld.m_flMatVal[2][3];
  boneIndexa = *(const char **)((int (__thiscall *)(CBaseAnimating *, physfollower_t **))GetModelName)(
                                 a1: pParentEntity,
                                 a2: &follow);
  if ( boneIndexa == nullptr )
    boneIndexa = locale;
  EntityByName = CreateEntityByName(className: "phys_bone_follower", iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
  {
    CBoneFollower::Init(
      this: (CBoneFollower *)EntityByName,
      pOwner: pParentEntity,
      pModelName: boneIndexa,
      solid: pSolid,
      position: &bonePosition,
      orientation: &boneAngles);
    v12->hFollower.m_Index = EntityByName->GetEdict(this: EntityByName)->m_fStateFlags;
  }
  else
  {
    v12->hFollower.m_Index = -1;
  }
  m_Index = v12->hFollower.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  m_pEntity[216].__vftable = (IHandleEntity_vtbl *)HitGroupFromPhysicsBone(
                                                     pAnim: pParentEntity,
                                                     physicsBone: (int)pBoneName);
  m_pEntity[215].__vftable = (IHandleEntity_vtbl *)pBoneName;
  v17 = v12->hFollower.m_Index;
  if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
    v18 = nullptr;
  else
    v18 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
  v19 = CBaseEntity::BlocksLOS(this: pParentEntity);
  CBaseEntity::SetBlocksLOS(this: v18, bBlocksLOS: v19);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018E0D0
// Name: public: void CBoneFollowerManager::AddBoneFollower(class CBaseAnimating __near *,char const __near *,struct solid_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBoneFollowerManager::AddBoneFollower(
        CBoneFollowerManager *this,
        CBaseAnimating *pParentEntity,
        char *pFollowerBoneName,
        solid_t *pSolid)
{
  int v5; // eax

  ++this->m_iNumBones;
  v5 = CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int>>::InsertBefore(
         this: &this->m_physBones,
         elem: this->m_physBones.m_Size);
  CBoneFollowerManager::CreatePhysicsFollower(
    this,
    pParentEntity,
    follow: &this->m_physBones.m_Memory.m_pMemory[v5],
    pBoneName: pFollowerBoneName,
    pSolid);
}

//------------------------------------------------------------------------------
// Address: 0x1018E190
// Name: void CreateBoneFollowersFromRagdoll(class CBaseAnimating __near *,class CBoneFollowerManager __near *,struct vcollide_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateBoneFollowersFromRagdoll(
        CBaseAnimating *pEntity,
        CBoneFollowerManager *pManager,
        vcollide_t *pCollide)
{
  IVPhysicsKeyParser *v3; // ebx
  const char *v4; // eax
  int v5; // eax
  IVPhysicsKeyParser_vtbl *v6; // edx
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // eax
  CBoneFollowerManager *v8; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<physfollower_t,CUtlMemory<physfollower_t,int> > *p_m_physBones; // esi
  physfollower_t *m_pMemory; // ecx
  int v13; // eax
  int v14; // eax
  solid_t solid; // [esp+4h] [ebp-644h] BYREF
  char v16[4]; // [esp+644h] [ebp-4h] BYREF

  v3 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  while ( !v3->Finished(this: v3) )
  {
    v4 = v3->GetCurrentBlockName(this: v3);
    v5 = _V_stricmp(s1: v4, s2: "solid");
    v6 = v3->__vftable;
    if ( v5 != 0 )
    {
      v6->SkipBlock(this: v3);
    }
    else
    {
      v6->ParseSolid(this: v3, a2: &solid, a3: nullptr);
      GetModelName = pEntity->GetModelName;
      solid.params.enableCollisions = true;
      solid.params.pName = *(const char **)((int (__thiscall *)(CBaseAnimating *, char *))GetModelName)(
                                             a1: pEntity,
                                             a2: v16);
      if ( solid.params.pName == nullptr )
        solid.params.pName = locale;
      v8 = pManager;
      ++pManager->m_iNumBones;
      m_Size = pManager->m_physBones.m_Size;
      m_nAllocationCount = pManager->m_physBones.m_Memory.m_nAllocationCount;
      p_m_physBones = &pManager->m_physBones;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
          this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)p_m_physBones,
          num: m_Size - m_nAllocationCount + 1);
        v8 = pManager;
      }
      ++pManager->m_physBones.m_Size;
      m_pMemory = p_m_physBones->m_Memory.m_pMemory;
      v13 = pManager->m_physBones.m_Size - m_Size - 1;
      pManager->m_physBones.m_pElements = pManager->m_physBones.m_Memory.m_pMemory;
      if ( v13 > 0 )
      {
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v13);
        v8 = pManager;
      }
      v14 = (int)&p_m_physBones->m_Memory.m_pMemory[m_Size];
      if ( v14 != 0 )
        *(_DWORD *)(v14 + 4) = -1;
      CBoneFollowerManager::CreatePhysicsFollower(
        this: v8,
        pParentEntity: pEntity,
        follow: &p_m_physBones->m_Memory.m_pMemory[m_Size],
        pBoneName: solid.name,
        pSolid: &solid);
    }
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x104072A0
// Name: physfollower_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *physfollower_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<physfollower_t>();
  physfollower_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104072B0
// Name: CBoneFollowerManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBoneFollowerManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBoneFollowerManager>();
  CBoneFollowerManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104072C0
// Name: CBoneFollower_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBoneFollower_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBoneFollower>(__formal: nullptr);
  CBoneFollower_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104072F0
// Name: DT_BoneFollower::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BoneFollower::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BoneFollower::g_SendTable);
  return atexit(func: DT_BoneFollower::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407310
// Name: DT_BoneFollower::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BoneFollower::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BoneFollower::ignored>();
  DT_BoneFollower::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CC00
// Name: DT_BoneFollower::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BoneFollower::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BoneFollower::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1018E110
// Name: struct datamap_t __near * DataMapInit<class CBoneFollower>(class CBoneFollower __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBoneFollower>()
{
  if ( (_S4_44 & 1) == 0 )
  {
    _S4_44 |= 1u;
    nameHolder_306.m_pszBase = "CBoneFollower";
    nameHolder_306.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_306.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_306.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_306.m_Names.m_Size = 0;
    nameHolder_306.m_Names.m_pElements = nullptr;
    nameHolder_306.m_nLenBase = 13;
    atexit(func: DataMapInit_CBoneFollower__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBoneFollower::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBoneFollower::m_DataMap.dataNumFields = 4;
  CBoneFollower::m_DataMap.dataDesc = &dataDesc_293[1];
  return &CBoneFollower::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104072D0
// Name: _dynamic_initializer_for__g_CBoneFollower_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBoneFollower_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBoneFollower_ClassReg,
           pNetworkName: "CBoneFollower",
           pTable: &DT_BoneFollower::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC10
// Name: _ServerClassInit_DT_BoneFollower::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BoneFollower::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_22;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC30
// Name: _DataMapInit_physfollower_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_physfollower_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_304);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC40
// Name: _DataMapInit_CBoneFollowerManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBoneFollowerManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_305);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC50
// Name: _DataMapInit_CBoneFollower__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBoneFollower__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_306);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC60
// Name: _DataMapInit_CThrustController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CThrustController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_307);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC70
// Name: _DataMapInit_CPhysicsCannister__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsCannister__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_308);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC80
// Name: _dynamic_atexit_destructor_for__vprof_think_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_think_limit__()
{
  ConVar::~ConVar(this: &vprof_think_limit);
}

//------------------------------------------------------------------------------
// Address: 0x1041CC90
// Name: _dynamic_atexit_destructor_for__vprof_scope_entity_thinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_scope_entity_thinks__()
{
  ConVar::~ConVar(this: &vprof_scope_entity_thinks);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCA0
// Name: _dynamic_atexit_destructor_for__vprof_scope_entity_gamephys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__vprof_scope_entity_gamephys__()
{
  ConVar::~ConVar(this: &vprof_scope_entity_gamephys);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCB0
// Name: _dynamic_atexit_destructor_for__npc_vphysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__npc_vphysics__()
{
  ConVar::~ConVar(this: &npc_vphysics);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCC0
// Name: _dynamic_atexit_destructor_for__sv_teststepsimulation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_teststepsimulation__()
{
  ConVar::~ConVar(this: &sv_teststepsimulation);
}

//------------------------------------------------------------------------------
// Address: 0x1041CCD0
// Name: _dynamic_atexit_destructor_for__s_PushedEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_PushedEntities__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PushedEntities.m_rgUpdatedChildren);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PushedEntities.m_rgUpdatedPushers);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PushedEntities.m_rgMoved);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_PushedEntities.m_rgPusher);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD00
// Name: _dynamic_atexit_destructor_for__g_EdictTouchLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EdictTouchLinks__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EdictTouchLinks);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD10
// Name: _dynamic_atexit_destructor_for__g_EntityGroundLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityGroundLinks__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &g_EntityGroundLinks);
}

//------------------------------------------------------------------------------
// Address: 0x1041CD20
// Name: _dynamic_atexit_destructor_for__think_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__think_limit__()
{
  ConVar::~ConVar(this: &think_limit);
}
