// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/collisionproperty.cpp
// Functions: 80
// ============================================================

#include "game\shared\collisionproperty.h"

//------------------------------------------------------------------------------
// Address: 0x100BF890
// Name: public: virtual bool CDirtySpatialPartitionEntityList::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDirtySpatialPartitionEntityList::Init(CDirtySpatialPartitionEntityList *this)
{
  if ( this != nullptr )
    partition->InstallQueryCallback(this: partition, a2: &this->IPartitionQueryCallback);
  else
    partition->InstallQueryCallback(this: partition, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BF8C0
// Name: public: virtual void CDirtySpatialPartitionEntityList::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::Shutdown(CDirtySpatialPartitionEntityList *this)
{
  if ( this != nullptr )
    partition->RemoveQueryCallback(this: partition, a2: &this->IPartitionQueryCallback);
  else
    partition->RemoveQueryCallback(this: partition, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100BF8F0
// Name: public: virtual struct datamap_t __near * CCollisionProperty::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCollisionProperty::GetPredDescMap(CCollisionProperty *this)
{
  return &CCollisionProperty::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x100BF900
// Name: public: virtual class IClientUnknown __near * CCollisionProperty::GetIClientUnknown(void)
// Source: json
//------------------------------------------------------------------------------
IClientUnknown *__thiscall CCollisionProperty::GetIClientUnknown(CCollisionProperty *this)
{
  return this->m_pOuter->GetIClientUnknown(this: &this->m_pOuter->IClientRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x100BF910
// Name: public: virtual int CCollisionProperty::GetCollisionModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetCollisionModelIndex(CCollisionProperty *this)
{
  return C_BaseEntity::GetModelIndex(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100BF920
// Name: public: virtual struct model_t const __near * CCollisionProperty::GetCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__thiscall CCollisionProperty::GetCollisionModel(CCollisionProperty *this)
{
  return this->m_pOuter->GetModel(this: &this->m_pOuter->IClientRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x100BF930
// Name: public: virtual bool CCollisionProperty::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionProperty::TestCollision(
        CCollisionProperty *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  return this->m_pOuter->TestCollision(this: this->m_pOuter, a2: ray, a3: fContentsMask, a4: tr);
}

//------------------------------------------------------------------------------
// Address: 0x100BF950
// Name: public: virtual bool CCollisionProperty::TestHitboxes(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionProperty::TestHitboxes(
        CCollisionProperty *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  return this->m_pOuter->TestHitboxes(this: this->m_pOuter, a2: ray, a3: fContentsMask, a4: tr);
}

//------------------------------------------------------------------------------
// Address: 0x100BF970
// Name: public: void CCollisionProperty::CreatePartitionHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::CreatePartitionHandle(CCollisionProperty *this)
{
  ISpatialPartition_vtbl *v2; // edi
  int v3; // eax

  v2 = partition->__vftable;
  v3 = this->GetEntityHandle(this);
  this->m_Partition = v2->CreateHandle_2(this: partition, a2: (IHandleEntity *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x100BF9A0
// Name: public: void CCollisionProperty::DestroyPartitionHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::DestroyPartitionHandle(CCollisionProperty *this)
{
  int m_Partition; // eax

  m_Partition = this->m_Partition;
  if ( (_WORD)m_Partition != 0xFFFF )
  {
    partition->DestroyHandle(this: partition, a2: m_Partition);
    this->m_Partition = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BF9D0
// Name: public: CCollisionProperty::~CCollisionProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::~CCollisionProperty(CCollisionProperty *this)
{
  int m_Partition; // eax

  m_Partition = this->m_Partition;
  this->__vftable = (CCollisionProperty_vtbl *)&CCollisionProperty::`vftable';
  if ( (_WORD)m_Partition != 0xFFFF )
  {
    partition->DestroyHandle(this: partition, a2: m_Partition);
    this->m_Partition = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFA00
// Name: public: virtual int CCollisionProperty::GetCollisionGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetCollisionGroup(CCollisionProperty *this)
{
  return this->m_pOuter->m_CollisionGroup;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA10
// Name: public: virtual class IPhysicsObject __near * CCollisionProperty::GetVPhysicsObject(void)const
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CCollisionProperty::GetVPhysicsObject(CCollisionProperty *this)
{
  return this->m_pOuter->m_pPhysicsObject;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA20
// Name: public: virtual enum SolidType_t CCollisionProperty::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall CCollisionProperty::GetSolid(CCollisionProperty *this)
{
  return this->m_nSolidType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA30
// Name: public: virtual class Vector const __near & CCollisionProperty::GetCollisionOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::GetCollisionOrigin(CCollisionProperty *this)
{
  return this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100BFA50
// Name: public: virtual class Vector const __near & CCollisionProperty::OBBMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMaxs> *__thiscall CCollisionProperty::OBBMaxs(
        CCollisionProperty *this)
{
  return &this->m_vecMaxs;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA60
// Name: private: bool CCollisionProperty::ComputeHitboxSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionProperty::ComputeHitboxSurroundingBox(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  C_BaseAnimating *v3; // eax

  v3 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
  if ( v3 != nullptr )
    return C_BaseAnimating::ComputeHitboxSurroundingBox(this: v3, pVecWorldMins, pVecWorldMaxs);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BFA90
// Name: public: bool CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(CCollisionProperty *this)
{
  C_BaseEntity *m_pOuter; // esi
  bool result; // al

  switch ( this->m_nSurroundType.m_Value )
  {
    case 0u:
      result = false;
      if ( this->GetSolid(this) == SOLID_VPHYSICS )
      {
        m_pOuter = this->m_pOuter;
        if ( m_pOuter->m_MoveType == 6 && m_pOuter->m_pPhysicsObject != nullptr )
          result = true;
      }
      break;
    case 2u:
    case 3u:
    case 5u:
    case 6u:
    case 7u:
      result = false;
      break;
    default:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BFB00
// Name: public: class Vector const __near & CCollisionProperty::WorldToCollisionSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::WorldToCollisionSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  unsigned __int8 m_Value; // al
  const QAngle *v5; // eax
  const matrix3x4_t *v6; // eax
  const Vector *v8; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v5 = this->GetCollisionAngles(this), vec3_angle.x == v5->x) && vec3_angle.y == v5->y && vec3_angle.z == v5->z )
  {
    v8 = this->GetCollisionOrigin(this);
    pResult->x = in->x - v8->x;
    pResult->y = in->y - v8->y;
    pResult->z = in->z - v8->z;
    return pResult;
  }
  else
  {
    v6 = this->CollisionToWorldTransform(this);
    VectorITransform(in1: &in->x, in2: v6, out: &pResult->x);
    return pResult;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFBC0
// Name: public: void CDirtySpatialPartitionEntityList::LockPartitionForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::LockPartitionForRead(CDirtySpatialPartitionEntityList *this)
{
  void *v2; // edi
  signed __int32 m_i32; // edx

  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  if ( this->m_nReadLockCount[(_DWORD)v2] == 0 )
  {
    if ( (this->m_partitionMutex.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)this->m_partitionMutex.m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)&this->m_partitionMutex, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &this->m_partitionMutex);
    }
  }
  ++this->m_nReadLockCount[(_DWORD)v2];
}

//------------------------------------------------------------------------------
// Address: 0x100BFC10
// Name: public: virtual void CDirtySpatialPartitionEntityList::OnPostQuery(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::OnPostQuery(CDirtySpatialPartitionEntityList *this, __int16 listMask)
{
  void *v3; // eax

  if ( (listMask & 0x18C) != 0 && this->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence == 0 )
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    if ( (*(&this->m_partitionMutex.m_lockInfo.m_i32 + (_DWORD)v3))-- == 1 )
      _InterlockedExchangeAdd(&this->m_DirtyEntities.m_Head.value32.DepthAndSequence, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFC50
// Name: public: virtual unsigned int CCollisionProperty::GetRequiredTriggerFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetRequiredTriggerFlags(CCollisionProperty *this)
{
  if ( this->GetCollisionGroup(this) == 1 )
    return 512;
  else
    return 8 * ((this->m_usSolidFlags.m_Value & 8) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100BFC80
// Name: public: virtual struct matrix3x4_t const __near * CCollisionProperty::GetRootParentToWorldTransform(void)const
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CCollisionProperty::GetRootParentToWorldTransform(CCollisionProperty *this)
{
  C_BaseEntity *RootMoveParent; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x100) != 0
    && (RootMoveParent = C_BaseEntity::GetRootMoveParent(this: this->m_pOuter)) != nullptr )
  {
    return RootMoveParent->m_Collision.CollisionToWorldTransform(this: &RootMoveParent->m_Collision);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFCB0
// Name: public: virtual class QAngle const __near & CCollisionProperty::GetCollisionAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CCollisionProperty::GetCollisionAngles(CCollisionProperty *this)
{
  unsigned __int8 m_Value; // al

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0 )
    return &vec3_angle;
  m_Value = this->m_nSolidType.m_Value;
  if ( m_Value == 2 || m_Value == 0 )
    return &vec3_angle;
  else
    return this->m_pOuter->GetAbsAngles(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100BFCE0
// Name: public: virtual struct matrix3x4_t const __near & CCollisionProperty::CollisionToWorldTransform(void)const
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__usercall CCollisionProperty::CollisionToWorldTransform@<eax>(
        CCollisionProperty *this@<ecx>,
        int a2@<ebp>)
{
  matrix3x4_t *v3; // esi
  bool v4; // zf
  unsigned __int8 m_Value; // al
  C_BaseEntity *m_pOuter; // edi
  const Vector *v8; // eax

  if ( (_S6_28 & 1) == 0 )
    _S6_28 |= 1u;
  v3 = &s_matTemp[s_nIndex];
  v4 = (this->m_usSolidFlags.m_Value & 0x40) == 0;
  s_nIndex = ((_BYTE)s_nIndex + 1) & 3;
  if ( v4 && (m_Value = this->m_nSolidType.m_Value) != 2 && m_Value != 0 )
  {
    m_pOuter = this->m_pOuter;
    C_BaseEntity::CalcAbsolutePosition(this: m_pOuter, a2);
    return &m_pOuter->m_rgflCoordinateFrame;
  }
  else
  {
    SetIdentityMatrix(matrix: v3);
    v8 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    MatrixSetColumn(in: v8, column: 3, out: v3);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BFD60
// Name: public: class Vector const __near & CCollisionProperty::NormalizedToWorldSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::NormalizedToWorldSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  Vector vecCollisionSpace; // [esp+0h] [ebp-Ch] BYREF

  vecCollisionSpace.x = (float)((float)(this->m_vecMaxs.m_Value.x - this->m_vecMins.m_Value.x) * in->x)
                      + this->m_vecMins.m_Value.x;
  vecCollisionSpace.y = (float)((float)(this->m_vecMaxs.m_Value.y - this->m_vecMins.m_Value.y) * in->y)
                      + this->m_vecMins.m_Value.y;
  vecCollisionSpace.z = (float)((float)(this->m_vecMaxs.m_Value.z - this->m_vecMins.m_Value.z) * in->z)
                      + this->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this, in: &vecCollisionSpace, pResult);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x100BFDD0
// Name: public: void CCollisionProperty::RandomPointInBounds(class Vector const __near &,class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::RandomPointInBounds(
        CCollisionProperty *this,
        const Vector *vecNormalizedMins,
        const Vector *vecNormalizedMaxs,
        Vector *pPoint)
{
  Vector in; // [esp+24h] [ebp-18h] BYREF
  Vector vecNormalizedSpace; // [esp+30h] [ebp-Ch]

  vecNormalizedSpace.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->x),
                           a3: LODWORD(vecNormalizedMaxs->x));
  vecNormalizedSpace.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->y),
                           a3: LODWORD(vecNormalizedMaxs->y));
  vecNormalizedSpace.z = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->z),
                           a3: LODWORD(vecNormalizedMaxs->z));
  in.x = (float)((float)(this->m_vecMaxs.m_Value.x - this->m_vecMins.m_Value.x) * vecNormalizedSpace.x)
       + this->m_vecMins.m_Value.x;
  in.y = (float)((float)(this->m_vecMaxs.m_Value.y - this->m_vecMins.m_Value.y) * vecNormalizedSpace.y)
       + this->m_vecMins.m_Value.y;
  in.z = (float)((float)(this->m_vecMaxs.m_Value.z - this->m_vecMins.m_Value.z) * vecNormalizedSpace.z)
       + this->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this, &in, pResult: pPoint);
}

//------------------------------------------------------------------------------
// Address: 0x100BFEC0
// Name: private: void CCollisionProperty::CollisionAABBToWorldAABB(class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::CollisionAABBToWorldAABB(
        CCollisionProperty *this,
        const Vector *entityMins,
        const Vector *entityMaxs,
        Vector *pWorldMins,
        Vector *pWorldMaxs)
{
  unsigned __int8 m_Value; // al
  const QAngle *v7; // eax
  const Vector *v8; // eax
  const Vector *v9; // eax
  matrix3x4_t tm; // [esp+4h] [ebp-30h] BYREF

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v7 = this->GetCollisionAngles(this), vec3_angle.x == v7->x) && vec3_angle.y == v7->y && vec3_angle.z == v7->z )
  {
    v8 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    pWorldMins->x = entityMins->x + v8->x;
    pWorldMins->y = v8->y + entityMins->y;
    pWorldMins->z = v8->z + entityMins->z;
    v9 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    pWorldMaxs->x = v9->x + entityMaxs->x;
    pWorldMaxs->y = v9->y + entityMaxs->y;
    pWorldMaxs->z = v9->z + entityMaxs->z;
  }
  else
  {
    tm = *this->CollisionToWorldTransform(this);
    TransformAABB(
      transform: &tm,
      vecMinsIn: entityMins,
      vecMaxsIn: entityMaxs,
      vecMinsOut: pWorldMins,
      vecMaxsOut: pWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0010
// Name: public: bool CCollisionProperty::IsPointInBounds(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCollisionProperty::IsPointInBounds(CCollisionProperty *this, const Vector *vecWorldPt)
{
  Vector vecLocalSpace; // [esp+4h] [ebp-Ch] BYREF

  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: &vecLocalSpace);
  return vecLocalSpace.x >= this->m_vecMins.m_Value.x
      && this->m_vecMaxs.m_Value.x >= vecLocalSpace.x
      && vecLocalSpace.y >= this->m_vecMins.m_Value.y
      && this->m_vecMaxs.m_Value.y >= vecLocalSpace.y
      && vecLocalSpace.z >= this->m_vecMins.m_Value.z
      && this->m_vecMaxs.m_Value.z >= vecLocalSpace.z;
}

//------------------------------------------------------------------------------
// Address: 0x100C0080
// Name: public: void CCollisionProperty::CalcNearestPoint(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::CalcNearestPoint(
        CCollisionProperty *this,
        const Vector *vecWorldPt,
        Vector *pVecNearestWorldPt)
{
  Vector localClosestPt; // [esp+4h] [ebp-18h] BYREF
  Vector localPt; // [esp+10h] [ebp-Ch] BYREF

  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: &localPt);
  CalcClosestPointOnAABB(
    mins: &this->m_vecMins.m_Value,
    maxs: &this->m_vecMaxs.m_Value,
    point: &localPt,
    closestOut: &localClosestPt);
  CCollisionProperty::CollisionToWorldSpace(this, in: &localClosestPt, pResult: pVecNearestWorldPt);
}

//------------------------------------------------------------------------------
// Address: 0x100C00D0
// Name: public: float CCollisionProperty::CalcDistanceFromPoint(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge CCollisionProperty::CalcDistanceFromPoint@<st0>(
        CCollisionProperty *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecWorldPt)
{
  Vector v5; // [esp-Ch] [ebp-28h] BYREF
  Vector localClosestPt; // [esp+0h] [ebp-1Ch] BYREF
  float v7; // [esp+Ch] [ebp-10h]
  Vector localPt; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  localPt.x = a2;
  localPt.y = retaddr;
  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: (Vector *)&localClosestPt.y);
  CalcClosestPointOnAABB(
    mins: &this->m_vecMins.m_Value,
    maxs: &this->m_vecMaxs.m_Value,
    point: (Vector *)&localClosestPt.y,
    closestOut: &v5);
  return fsqrt(
           (float)((float)((float)(localClosestPt.z - v5.y) * (float)(localClosestPt.z - v5.y))
                 + (float)((float)(v7 - v5.z) * (float)(v7 - v5.z)))
         + (float)((float)(localClosestPt.y - v5.x) * (float)(localClosestPt.y - v5.x)));
}

//------------------------------------------------------------------------------
// Address: 0x100C0170
// Name: private: void CCollisionProperty::ComputeVPhysicsSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeVPhysicsSurroundingBox(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  const Vector *v5; // edi
  CCollisionProperty_vtbl *v6; // eax
  int v7; // eax
  int v8; // eax
  Vector *v9; // edi
  Vector *v10; // esi
  const Vector *v11; // eax
  double v12; // st7
  const Vector *v13; // eax
  double v14; // st7
  double z; // st7
  double x; // xmm0_8
  float y; // xmm1_4
  float v18; // xmm0_4
  double v19; // xmm0_8
  double v20; // xmm1_8
  float v21; // xmm1_4
  float v22; // xmm0_4
  double v23; // xmm0_8
  double v24; // xmm1_8
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  float v31; // xmm1_4
  float v32; // xmm0_4
  double v33; // xmm0_8
  double v34; // xmm1_8
  Vector vecWorldTriggerMaxs; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecWorldTriggerMins; // [esp+18h] [ebp-10h] BYREF
  float flRadius; // [esp+24h] [ebp-4h]

  m_pPhysicsObject = this->m_pOuter->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    goto LABEL_6;
  if ( m_pPhysicsObject->GetCollide(this: this->m_pOuter->m_pPhysicsObject) != nullptr )
  {
    v5 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    v6 = this->__vftable;
    flRadius = *(float *)&physcollision->__vftable;
    v7 = (int)v6->GetCollisionAngles(this);
    v8 = ((int (__thiscall *)(IPhysicsObject *, const Vector *, int))m_pPhysicsObject->GetCollide)(
           a1: m_pPhysicsObject,
           a2: v5,
           a3: v7);
    v9 = pVecWorldMaxs;
    v10 = pVecWorldMins;
    (*(void (__thiscall **)(IPhysicsCollision *, Vector *, Vector *, int))(LODWORD(flRadius) + 92))(
      a1: physcollision,
      a2: pVecWorldMins,
      a3: pVecWorldMaxs,
      a4: v8);
    goto LABEL_8;
  }
  if ( ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetSphereRadius)(a1: m_pPhysicsObject) == 0.0 )
  {
LABEL_6:
    v10 = pVecWorldMins;
    v9 = pVecWorldMaxs;
    *pVecWorldMins = *this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    pVecWorldMaxs->x = pVecWorldMins->x;
    pVecWorldMaxs->y = pVecWorldMins->y;
    z = pVecWorldMins->z;
  }
  else
  {
    flRadius = m_pPhysicsObject->GetSphereRadius(this: m_pPhysicsObject);
    v11 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    v10 = pVecWorldMins;
    v12 = flRadius;
    pVecWorldMins->x = v11->x - flRadius;
    pVecWorldMins->y = v11->y - v12;
    pVecWorldMins->z = v11->z - v12;
    v13 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    v9 = pVecWorldMaxs;
    v14 = flRadius;
    pVecWorldMaxs->x = v13->x + flRadius;
    pVecWorldMaxs->y = v13->y + v14;
    z = v14 + v13->z;
  }
  v9->z = z;
LABEL_8:
  if ( SLOBYTE(this->m_usSolidFlags.m_Value) < 0 )
  {
    this->WorldSpaceTriggerBounds(this, a2: &vecWorldTriggerMins, a3: &vecWorldTriggerMaxs);
    x = vecWorldTriggerMins.x;
    if ( vecWorldTriggerMins.x > (double)v10->x )
      x = v10->x;
    y = v10->y;
    v18 = x;
    v10->x = v18;
    v19 = vecWorldTriggerMins.y;
    v20 = y;
    if ( vecWorldTriggerMins.y > v20 )
      v19 = v20;
    v21 = v10->z;
    v22 = v19;
    v10->y = v22;
    v23 = vecWorldTriggerMins.z;
    v24 = v21;
    if ( vecWorldTriggerMins.z > v24 )
      v23 = v24;
    v25 = v23;
    v10->z = v25;
    v26 = vecWorldTriggerMaxs.x;
    if ( vecWorldTriggerMaxs.x < (double)v9->x )
      v26 = v9->x;
    v27 = v9->y;
    v28 = v26;
    v9->x = v28;
    v29 = vecWorldTriggerMaxs.y;
    v30 = v27;
    if ( vecWorldTriggerMaxs.y < v30 )
      v29 = v30;
    v31 = v9->z;
    v32 = v29;
    v9->y = v32;
    v33 = vecWorldTriggerMaxs.z;
    v34 = v31;
    if ( vecWorldTriggerMaxs.z < v34 )
      v33 = v34;
    v9->z = v33;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0380
// Name: private: void CCollisionProperty::ComputeRotationExpandedBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeRotationExpandedBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  unsigned __int8 m_Value; // al
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0 || (m_Value = this->m_nSolidType.m_Value) == 2 || m_Value == 0 )
  {
    *pVecWorldMins = this->m_vecMins.m_Value;
    *pVecWorldMaxs = this->m_vecMaxs.m_Value;
  }
  else
  {
    v4 = fabs(this->m_vecMins.m_Value.x);
    v5 = fabs(this->m_vecMaxs.m_Value.x);
    if ( v4 <= v5 )
      v4 = v5;
    pVecWorldMins->x = -v4;
    pVecWorldMaxs->x = v4;
    v6 = fabs(this->m_vecMins.m_Value.y);
    v7 = fabs(this->m_vecMaxs.m_Value.y);
    if ( v6 <= v7 )
      v6 = v7;
    pVecWorldMins->y = -v6;
    pVecWorldMaxs->y = v6;
    v8 = fabs(this->m_vecMins.m_Value.z);
    v9 = fabs(this->m_vecMaxs.m_Value.z);
    if ( v8 <= v9 )
      v8 = v9;
    pVecWorldMins->z = -v8;
    pVecWorldMaxs->z = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0450
// Name: private: void CCollisionProperty::ComputeCollisionSurroundingBox(bool,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeCollisionSurroundingBox(
        CCollisionProperty *this,
        bool bUseVPhysics,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  if ( bUseVPhysics )
    CCollisionProperty::ComputeVPhysicsSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
  else
    this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x100C0480
// Name: public: void CCollisionProperty::UpdatePartition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::UpdatePartition(CCollisionProperty *this)
{
  C_BaseEntity *m_pOuter; // eax
  int m_Partition; // eax
  const Vector *v4; // edi
  const Vector *v5; // eax
  Vector vecSurroundMins; // [esp+4h] [ebp-18h] BYREF
  Vector vecSurroundMaxs; // [esp+10h] [ebp-Ch] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x8000) != 0 )
  {
    m_pOuter->m_iEFlags &= ~0x8000u;
    if ( this->m_Partition != 0xFFFF
      && (this->m_nSolidType.m_Value != 0 && (this->m_usSolidFlags.m_Value & 4) == 0
       || (this->m_usSolidFlags.m_Value & 8) != 0
       || (this->m_pOuter->m_iEFlags & 0x40000) != 0) )
    {
      if ( this->m_flRadius == 0.0 )
      {
        v4 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
        v5 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
        ((void (__stdcall *)(_DWORD, const Vector *, const Vector *))partition->ElementMoved)(
          a1: this->m_Partition,
          a2: v5,
          a3: v4);
      }
      else
      {
        this->WorldSpaceSurroundingBounds(this, a2: &vecSurroundMins, a3: &vecSurroundMaxs);
        vecSurroundMins.x = vecSurroundMins.x - 1.0;
        vecSurroundMins.y = vecSurroundMins.y - 1.0;
        vecSurroundMins.z = vecSurroundMins.z - 1.0;
        vecSurroundMaxs.x = vecSurroundMaxs.x + 1.0;
        vecSurroundMaxs.y = vecSurroundMaxs.y + 1.0;
        m_Partition = this->m_Partition;
        vecSurroundMaxs.z = vecSurroundMaxs.z + 1.0;
        partition->ElementMoved(this: partition, a2: m_Partition, a3: &vecSurroundMins, a4: &vecSurroundMaxs);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C05C0
// Name: public: void CTSListWithFreeList<class CBaseHandle>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSListWithFreeList<CBaseHandle>::RemoveAll(CTSListWithFreeList<CBaseHandle> *this)
{
  TSLNodeBase_t *v2; // edi
  CTSListBase *p_m_FreeList; // esi
  TSLNodeBase_t *Next; // [esp-Ch] [ebp-18h]
  TSLNodeBase_t *v5; // [esp-Ch] [ebp-18h]
  int DepthAndSequence; // [esp-8h] [ebp-14h]
  int v7; // [esp-8h] [ebp-14h]
  CTSListWithFreeList<CBaseHandle>::Node_t *pNext; // [esp+8h] [ebp-4h]

  v2 = CTSListBase::Detach(this);
  if ( v2 != nullptr )
  {
    p_m_FreeList = &this->m_FreeList;
    do
    {
      DepthAndSequence = p_m_FreeList->m_Head.value32.DepthAndSequence;
      pNext = (CTSListWithFreeList<CBaseHandle>::Node_t *)v2->Next;
      Next = p_m_FreeList->m_Head.value.Next;
      v2->Next = p_m_FreeList->m_Head.value.Next;
      if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                              a1: p_m_FreeList,
                              a2: v2,
                              a3: DepthAndSequence + 65537,
                              a4: Next,
                              a5: DepthAndSequence) == 0 )
      {
        do
        {
          _mm_pause();
          v7 = p_m_FreeList->m_Head.value32.DepthAndSequence;
          v5 = p_m_FreeList->m_Head.value.Next;
          v2->Next = p_m_FreeList->m_Head.value.Next;
        }
        while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: p_m_FreeList, a2: v2, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
      }
      v2 = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0630
// Name: public: void CTSListWithFreeList<class CBaseHandle>::PushItem(class CBaseHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSListWithFreeList<CBaseHandle>::PushItem(
        CTSListWithFreeList<CBaseHandle> *this,
        const CBaseHandle *init)
{
  TSLNodeBase_t *v3; // eax

  v3 = CTSListBase::Pop(this: &this->m_FreeList);
  if ( v3 == nullptr )
  {
    v3 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 8u);
    if ( v3 != nullptr )
      *((_DWORD *)&v3->Next + 1) = -1;
    else
      v3 = nullptr;
  }
  *((CBaseHandle *)&v3->Next + 1) = (CBaseHandle)init->m_Index;
  CTSListBase::Push(this, pNode: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100C0670
// Name: public: void CDirtySpatialPartitionEntityList::AddEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::AddEntity(
        CDirtySpatialPartitionEntityList *this,
        C_BaseEntity *pEntity)
{
  const CBaseHandle *v3; // edi
  TSLNodeBase_t *v4; // eax
  CBaseHandle *v5; // eax

  v3 = pEntity->GetRefEHandle(this: pEntity);
  v4 = CTSListBase::Pop(this: &this->m_DirtyEntities.m_FreeList);
  if ( v4 == nullptr )
  {
    v5 = (CBaseHandle *)MemAlloc_Alloc(nSize: 8u);
    if ( v5 != nullptr )
    {
      v5[1].m_Index = -1;
      v5[1].m_Index = v3->m_Index;
      CTSListBase::Push(this: &this->m_DirtyEntities, pNode: (TSLNodeBase_t *)v5);
      return;
    }
    v4 = nullptr;
  }
  *((CBaseHandle *)&v4->Next + 1) = (CBaseHandle)v3->m_Index;
  CTSListBase::Push(this: &this->m_DirtyEntities, pNode: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100C06D0
// Name: public: virtual void CDirtySpatialPartitionEntityList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::LevelShutdownPostEntity(CDirtySpatialPartitionEntityList *this)
{
  CTSListWithFreeList<CBaseHandle>::RemoveAll(this: &this->m_DirtyEntities);
}

//------------------------------------------------------------------------------
// Address: 0x100C06E0
// Name: public: virtual void CCollisionProperty::WorldSpaceTriggerBounds(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::WorldSpaceTriggerBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CCollisionProperty::CollisionAABBToWorldAABB(
    this,
    entityMins: &this->m_vecMins.m_Value,
    entityMaxs: &this->m_vecMaxs.m_Value,
    pWorldMins: pVecWorldMins,
    pWorldMaxs: pVecWorldMaxs);
  if ( (this->GetSolidFlags(this) & 0x80u) != 0 )
  {
    pVecWorldMins->x = pVecWorldMins->x - (float)this->m_triggerBloat.m_Value;
    pVecWorldMins->y = pVecWorldMins->y - (float)this->m_triggerBloat.m_Value;
    pVecWorldMaxs->x = (float)this->m_triggerBloat.m_Value + pVecWorldMaxs->x;
    pVecWorldMaxs->y = (float)this->m_triggerBloat.m_Value + pVecWorldMaxs->y;
    pVecWorldMaxs->z = (float)((float)this->m_triggerBloat.m_Value * 0.5) + pVecWorldMaxs->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0790
// Name: private: void CCollisionProperty::ComputeOBBBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeOBBBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  C_BaseEntity *m_pOuter; // eax
  IPhysicsObject *m_pPhysicsObject; // eax

  if ( this->GetSolid(this) == SOLID_VPHYSICS
    && (m_pOuter = this->m_pOuter)->m_MoveType == 6
    && (m_pPhysicsObject = m_pOuter->m_pPhysicsObject) != nullptr
    && m_pPhysicsObject->IsAsleep(this: m_pPhysicsObject) )
  {
    CCollisionProperty::ComputeVPhysicsSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
  }
  else
  {
    this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C07F0
// Name: private: void CCollisionProperty::ComputeRotationExpandedSequenceBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeRotationExpandedSequenceBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  C_BaseAnimating *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  double x; // xmm2_8
  float v15; // xmm2_4
  double y; // xmm0_8
  float z; // xmm2_4
  float v18; // xmm0_4
  double v19; // xmm0_8
  double v20; // xmm2_8
  float v21; // xmm2_4
  float v22; // xmm0_4
  double v23; // xmm0_8
  double v24; // xmm2_8
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  C_BaseEntity *m_pOuter; // ecx
  float *v32; // eax
  const Vector *v33; // eax
  Vector maxs; // [esp+4h] [ebp-18h] BYREF
  Vector mins; // [esp+10h] [ebp-Ch] BYREF

  v4 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
  if ( v4 != nullptr )
  {
    C_BaseAnimating::ExtractBbox(this: v4, nSequence: v4->m_nSequence, &mins, &maxs);
    v5 = fabs(mins.x);
    v6 = fabs(maxs.x);
    if ( v5 <= v6 )
      v7 = v6;
    else
      v7 = v5;
    v8 = fabs(mins.y);
    v9 = fabs(maxs.y);
    if ( v8 <= v9 )
      v10 = v9;
    else
      v10 = v8;
    if ( v7 <= v10 )
    {
      if ( v8 <= v9 )
        v5 = v9;
      else
        v5 = v8;
    }
    else if ( v5 <= v6 )
    {
      v5 = v6;
    }
    v11 = COERCE_FLOAT(LODWORD(v5) ^ _mask__NegFloat_) - 6.0;
    v12 = v5 + 6.0;
    v13 = v5 + 6.0;
    x = v11;
    if ( v11 > (double)this->m_vecSurroundingMins.x )
      x = this->m_vecSurroundingMins.x;
    v15 = x;
    mins.x = v15;
    y = v11;
    if ( y > this->m_vecSurroundingMins.y )
      y = this->m_vecSurroundingMins.y;
    z = this->m_vecSurroundingMins.z;
    v18 = y;
    mins.y = v18;
    v19 = mins.z;
    v20 = z;
    if ( mins.z > v20 )
      v19 = v20;
    v21 = this->m_vecSurroundingMaxs.x;
    v22 = v19;
    mins.z = v22;
    v23 = v12;
    v24 = v21;
    if ( v12 < v24 )
      v23 = v24;
    v25 = v23;
    maxs.x = v25;
    v26 = v13;
    if ( v13 < (double)this->m_vecSurroundingMaxs.y )
      v26 = this->m_vecSurroundingMaxs.y;
    v27 = this->m_vecSurroundingMaxs.z;
    v28 = v26;
    maxs.y = v28;
    v29 = maxs.z;
    v30 = v27;
    if ( maxs.z < v30 )
      v29 = v30;
    m_pOuter = this->m_pOuter;
    maxs.z = v29;
    v32 = (float *)m_pOuter->GetAbsOrigin(this: m_pOuter);
    pVecWorldMins->x = *v32 + mins.x;
    pVecWorldMins->y = v32[1] + mins.y;
    pVecWorldMins->z = v32[2] + mins.z;
    v33 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    pVecWorldMaxs->x = maxs.x + v33->x;
    pVecWorldMaxs->y = v33->y + maxs.y;
    pVecWorldMaxs->z = v33->z + maxs.z;
  }
  else
  {
    CCollisionProperty::ComputeOBBBounds(this, pVecWorldMins, pVecWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0A10
// Name: private: void CCollisionProperty::ComputeSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCollisionProperty::ComputeSurroundingBox(
        CCollisionProperty *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  C_BaseAnimating *v8; // eax
  C_BaseAnimating *v9; // eax
  C_BaseAnimating *v10; // eax
  C_BaseEntity *m_pOuter; // ecx
  char *Classname; // eax
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm4_4
  float v16; // xmm6_4
  float z; // xmm5_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  SolidType_t v22; // eax
  const Vector *v23; // eax
  const Vector *v24; // eax
  float v25; // xmm4_4
  char *v26; // eax
  const char *v28; // [esp+50h] [ebp-140h]
  const char *v30; // [esp+54h] [ebp-13Ch]
  char pTemp[260]; // [esp+5Ch] [ebp-134h] BYREF
  Vector vecDelta; // [esp+160h] [ebp-30h]
  Vector vecDelta2; // [esp+16Ch] [ebp-24h] BYREF
  Vector vecTestMins; // [esp+178h] [ebp-18h] BYREF
  Vector vecTestMaxs; // [esp+184h] [ebp-Ch] BYREF
  Vector *pVecWorldMinsa; // [esp+198h] [ebp+8h]
  const char *pSeqName; // [esp+19Ch] [ebp+Ch]

  if ( this->GetSolid(this) != SOLID_CUSTOM || this->m_nSurroundType.m_Value == 4 )
  {
    switch ( this->m_nSurroundType.m_Value )
    {
      case 0u:
        CCollisionProperty::ComputeOBBBounds(this, pVecWorldMins, pVecWorldMaxs);
        goto LABEL_6;
      case 1u:
        v22 = this->GetSolid(this);
        CCollisionProperty::ComputeCollisionSurroundingBox(
          this,
          bUseVPhysics: v22 == SOLID_VPHYSICS,
          pVecWorldMins,
          pVecWorldMaxs);
        goto LABEL_6;
      case 2u:
        CCollisionProperty::ComputeHitboxSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
        goto LABEL_6;
      case 3u:
        v23 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
        pVecWorldMins->x = this->m_vecSpecifiedSurroundingMins.m_Value.x + v23->x;
        pVecWorldMins->y = this->m_vecSpecifiedSurroundingMins.m_Value.y + v23->y;
        pVecWorldMins->z = this->m_vecSpecifiedSurroundingMins.m_Value.z + v23->z;
        v24 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
        pVecWorldMaxs->x = v24->x + this->m_vecSpecifiedSurroundingMaxs.m_Value.x;
        pVecWorldMaxs->y = v24->y + this->m_vecSpecifiedSurroundingMaxs.m_Value.y;
        pVecWorldMaxs->z = v24->z + this->m_vecSpecifiedSurroundingMaxs.m_Value.z;
        goto LABEL_6;
      case 4u:
        this->m_pOuter->ComputeWorldSpaceSurroundingBox(this: this->m_pOuter, a2: pVecWorldMins, a3: pVecWorldMaxs);
        return;
      case 5u:
        CCollisionProperty::ComputeRotationExpandedBounds(this, pVecWorldMins, pVecWorldMaxs);
        goto LABEL_6;
      case 6u:
        this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
        goto LABEL_6;
      case 7u:
        CCollisionProperty::ComputeRotationExpandedSequenceBounds(this, pVecWorldMins, pVecWorldMaxs);
        goto LABEL_6;
      default:
LABEL_6:
        if ( cl_show_bounds_errors.m_pParent == nullptr
          || cl_show_bounds_errors.m_pParent->m_Value.m_nValue == 0
          || this->m_nSurroundType.m_Value != 7 )
        {
          return;
        }
        if ( this->m_pOuter->GetBaseAnimating(this: this->m_pOuter) != nullptr )
        {
          v8 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
          C_BaseAnimating::InvalidateBoneCache(this: v8);
        }
        v9 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
        if ( v9 != nullptr )
          C_BaseAnimating::ComputeHitboxSurroundingBox(
            this: v9,
            pVecWorldMins: &vecTestMins,
            pVecWorldMaxs: &vecTestMaxs);
        if ( pVecWorldMins->x <= vecTestMins.x
          && pVecWorldMins->y <= vecTestMins.y
          && pVecWorldMins->z <= vecTestMins.z
          && vecTestMaxs.x <= pVecWorldMaxs->x
          && vecTestMaxs.y <= pVecWorldMaxs->y
          && vecTestMaxs.z <= pVecWorldMaxs->z )
        {
          return;
        }
        pSeqName = "<unknown seq>";
        v10 = (C_BaseAnimating *)((int (__thiscall *)(C_BaseEntity *, int, int))this->m_pOuter->GetBaseAnimating)(
                                   a1: this->m_pOuter,
                                   a2: a3,
                                   a3: a2);
        if ( v10 != nullptr )
          pSeqName = C_BaseAnimating::GetSequenceName(this: v10, iSequence: v10->m_nSequence);
        m_pOuter = this->m_pOuter;
        pVecWorldMinsa = (Vector *)&m_pOuter->IClientNetworkable;
        Classname = C_BaseEntity::GetClassname(this: m_pOuter);
        v13 = (*(int (__thiscall **)(Vector *, char *, const char *))(LODWORD(pVecWorldMinsa->x) + 40))(
                a1: pVecWorldMinsa,
                a2: Classname,
                a3: pSeqName);
        _Warning(a1: "*** Bounds problem, index %d Eng %s, Seqeuence %s ", v13, v28, v30);
        v14 = pVecWorldMins->x - vecTestMins.x;
        v15 = 0.0;
        v16 = pVecWorldMins->z - vecTestMins.z;
        z = vecTestMaxs.z - pVecWorldMaxs->z;
        v18 = pVecWorldMins->y - vecTestMins.y;
        v19 = vecTestMaxs.x - pVecWorldMaxs->x;
        v20 = vecTestMaxs.y - pVecWorldMaxs->y;
        vecDelta.z = v16;
        vecDelta2.z = z;
        if ( v14 > 0.0 || v19 > 0.0 || v18 > 0.0 || v20 > 0.0 )
        {
          if ( v14 <= v19 )
            v21 = v19;
          else
            v21 = v14;
          if ( v18 <= v20 )
            v25 = v20;
          else
            v25 = v18;
          if ( v21 <= v25 )
          {
            if ( v18 <= v20 )
              v14 = v20;
            else
              v14 = v18;
          }
          else if ( v14 <= v19 )
          {
            v14 = v19;
          }
          _Msg(a1: "Outside X/Y by %.2f ", v14);
          z = vecDelta2.z;
          v16 = vecDelta.z;
          v15 = 0.0;
        }
        if ( v16 > 0.0 )
        {
          if ( z <= 0.0 )
            z = 0.0;
        }
        else if ( z <= 0.0 )
        {
          goto LABEL_53;
        }
        if ( v16 > 0.0 )
          v15 = v16;
        _Msg(a1: "Outside Z by (below) %.2f, (above) %.2f ", v15, z);
LABEL_53:
        _Msg(a1: "\n");
        v26 = C_BaseEntity::GetClassname(this: this->m_pOuter);
        V_snprintf(pDest: pTemp, maxLen: 260, pFormat: "%s [seq: %s]", v26, pSeqName);
        ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, QAngle *, int, _DWORD, _DWORD))debugoverlay->AddBoxOverlay)(
          a1: debugoverlay,
          a2: &vec3_origin,
          a3: &vecTestMins,
          a4: &vecTestMaxs,
          a5: &vec3_angle,
          a6: 255,
          a7: 0,
          a8: 0);
        ((void (__stdcall *)(Vector *, Vector *, Vector *, QAngle *, _DWORD, _DWORD, int, _DWORD, int))debugoverlay->AddBoxOverlay)(
          a1: &vec3_origin,
          a2: pVecWorldMins,
          a3: pVecWorldMaxs,
          a4: &vec3_angle,
          a5: 0,
          a6: 0,
          a7: 255,
          a8: 0,
          a9: 0x40000000);
        vecDelta2.x = (float)(vecTestMaxs.x + vecTestMins.x) * 0.5;
        vecDelta2.y = (float)(vecTestMaxs.y + vecTestMins.y) * 0.5;
        vecDelta2.z = (float)(vecTestMaxs.z + vecTestMins.z) * 0.5;
        ((void (__cdecl *)(IVDebugOverlay *, Vector *, int, char *))debugoverlay->AddTextOverlay_2)(
          a1: debugoverlay,
          a2: &vecDelta2,
          a3: 0x40000000,
          a4: pTemp);
        break;
    }
  }
  else
  {
    *pVecWorldMins = *this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
    *pVecWorldMaxs = *pVecWorldMins;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0EA0
// Name: public: virtual void CCollisionProperty::WorldSpaceSurroundingBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::WorldSpaceSurroundingBounds(
        CCollisionProperty *this,
        Vector *pVecMins,
        Vector *pVecMaxs)
{
  const Vector *v4; // edi
  C_BaseEntity *m_pOuter; // eax

  v4 = this->m_pOuter->GetAbsOrigin(this: this->m_pOuter);
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x4000) != 0 )
  {
    m_pOuter->m_iEFlags &= ~0x4000u;
    CCollisionProperty::ComputeSurroundingBox(
      this,
      a2: (int)pVecMaxs,
      a3: (int)v4,
      pVecWorldMins: pVecMins,
      pVecWorldMaxs: pVecMaxs);
    this->m_vecSurroundingMins.x = pVecMins->x - v4->x;
    this->m_vecSurroundingMins.y = pVecMins->y - v4->y;
    this->m_vecSurroundingMins.z = pVecMins->z - v4->z;
    this->m_vecSurroundingMaxs.x = pVecMaxs->x - v4->x;
    this->m_vecSurroundingMaxs.y = pVecMaxs->y - v4->y;
    this->m_vecSurroundingMaxs.z = pVecMaxs->z - v4->z;
  }
  else
  {
    pVecMins->x = this->m_vecSurroundingMins.x + v4->x;
    pVecMins->y = this->m_vecSurroundingMins.y + v4->y;
    pVecMins->z = this->m_vecSurroundingMins.z + v4->z;
    pVecMaxs->x = this->m_vecSurroundingMaxs.x + v4->x;
    pVecMaxs->y = this->m_vecSurroundingMaxs.y + v4->y;
    pVecMaxs->z = this->m_vecSurroundingMaxs.z + v4->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0FA0
// Name: public: void CCollisionProperty::MarkPartitionHandleDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::MarkPartitionHandleDirty(CCollisionProperty *this)
{
  C_BaseEntity *m_pOuter; // eax

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x8000) == 0 )
  {
    CDirtySpatialPartitionEntityList::AddEntity(this: &s_DirtyKDTree, pEntity: m_pOuter);
    this->m_pOuter->m_iEFlags |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C0FD0
// Name: public: CTSListWithFreeList<class CBaseHandle>::~CTSListWithFreeList<class CBaseHandle>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSListWithFreeList<CBaseHandle>::~CTSListWithFreeList<CBaseHandle>(
        CTSListWithFreeList<CBaseHandle> *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *Next; // esi
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *v5; // esi

  v2 = CTSListBase::Detach(this);
  if ( v2 != nullptr )
  {
    do
    {
      Next = v2->Next;
      C_BaseEntity::operator delete(pMem: v2);
      v2 = Next;
    }
    while ( Next != nullptr );
  }
  v4 = CTSListBase::Detach(this: &this->m_FreeList);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = v4->Next;
      C_BaseEntity::operator delete(pMem: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  CTSListBase::Detach(this: &this->m_FreeList);
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C1030
// Name: public: CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDirtySpatialPartitionEntityList *__thiscall CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(
        CDirtySpatialPartitionEntityList *this,
        const char *name)
{
  CTSListBase *p_m_FreeList; // eax
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *Next; // ebx
  TSLNodeBase_t *v6; // eax
  TSLNodeBase_t *v7; // ebx
  const char *v9; // [esp+0h] [ebp-8h]

  CAutoGameSystem::CAutoGameSystem(this, name);
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&IPartitionQueryCallback::`vftable';
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CDirtySpatialPartitionEntityList_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `CAutoGameSystem'};
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `IPartitionQueryCallback'};
  if ( (((_BYTE)this + 16) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1044E7B0, a2: v9);
    __debugbreak();
  }
  p_m_FreeList = &this->m_DirtyEntities.m_FreeList;
  this->m_DirtyEntities.m_Head.value.Next = nullptr;
  this->m_DirtyEntities.m_Head.value32.DepthAndSequence = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_1044E7B0, a2: v9);
    __debugbreak();
    p_m_FreeList = &this->m_DirtyEntities.m_FreeList;
  }
  p_m_FreeList->m_Head.value.Next = nullptr;
  p_m_FreeList->m_Head.value32.DepthAndSequence = 0;
  CThreadSpinRWLock::CThreadSpinRWLock(this: &this->m_partitionMutex);
  v4 = CTSListBase::Detach(this: &this->m_DirtyEntities);
  if ( v4 != nullptr )
  {
    do
    {
      Next = v4->Next;
      C_BaseEntity::operator delete(pMem: v4);
      v4 = Next;
    }
    while ( Next != nullptr );
  }
  v6 = CTSListBase::Detach(this: &this->m_DirtyEntities.m_FreeList);
  if ( v6 != nullptr )
  {
    do
    {
      v7 = v6->Next;
      C_BaseEntity::operator delete(pMem: v6);
      v6 = v7;
    }
    while ( v7 != nullptr );
  }
  memset(dst: (int)this->m_nReadLockCount, value: nullptr, count: sizeof(this->m_nReadLockCount));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1100
// Name: public: virtual CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(
        CDirtySpatialPartitionEntityList *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *Next; // esi
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *v5; // esi

  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CDirtySpatialPartitionEntityList_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `CAutoGameSystem'};
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `IPartitionQueryCallback'};
  v2 = CTSListBase::Detach(this: &this->m_DirtyEntities);
  if ( v2 != nullptr )
  {
    do
    {
      Next = v2->Next;
      C_BaseEntity::operator delete(pMem: v2);
      v2 = Next;
    }
    while ( Next != nullptr );
  }
  v4 = CTSListBase::Detach(this: &this->m_DirtyEntities.m_FreeList);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = v4->Next;
      C_BaseEntity::operator delete(pMem: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  CTSListWithFreeList<CBaseHandle>::~CTSListWithFreeList<CBaseHandle>(this: &this->m_DirtyEntities);
  IGameSystem::~IGameSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C1170
// Name: public: void CCollisionProperty::Init(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::Init(CCollisionProperty *this, C_BaseEntity *pEntity)
{
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *p_m_vecMins; // edi
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMins> *p_m_vecSpecifiedSurroundingMins; // edi
  void (__thiscall *NetworkStateChanged)(CCollisionProperty *, void *); // eax
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMaxs> *p_m_vecSpecifiedSurroundingMaxs; // esi

  p_m_vecMins = &this->m_vecMins;
  this->m_pOuter = pEntity;
  this->NetworkStateChanged(this, a2: &this->m_vecMins);
  p_m_vecMins->m_Value.x = 0.0;
  p_m_vecMins->m_Value.y = 0.0;
  p_m_vecMins->m_Value.z = 0.0;
  this->NetworkStateChanged(this, a2: &this->m_vecMaxs);
  this->m_vecMaxs.m_Value.x = 0.0;
  this->m_vecMaxs.m_Value.y = 0.0;
  this->m_vecMaxs.m_Value.z = 0.0;
  this->m_flRadius = 0.0;
  if ( this->m_triggerBloat.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_triggerBloat);
    this->m_triggerBloat.m_Value = 0;
  }
  if ( this->m_usSolidFlags.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_usSolidFlags);
    this->m_usSolidFlags.m_Value = 0;
  }
  if ( this->m_nSolidType.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSolidType);
    this->m_nSolidType.m_Value = 0;
  }
  if ( this->m_nSurroundType.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSurroundType);
    this->m_nSurroundType.m_Value = 0;
  }
  this->m_vecSurroundingMins = vec3_origin;
  p_m_vecSpecifiedSurroundingMins = &this->m_vecSpecifiedSurroundingMins;
  NetworkStateChanged = this->NetworkStateChanged;
  this->m_vecSurroundingMaxs = vec3_origin;
  NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMins);
  p_m_vecSpecifiedSurroundingMaxs = &this->m_vecSpecifiedSurroundingMaxs;
  p_m_vecSpecifiedSurroundingMins->m_Value.x = 0.0;
  p_m_vecSpecifiedSurroundingMins->m_Value.y = 0.0;
  p_m_vecSpecifiedSurroundingMins->m_Value.z = 0.0;
  (*(void (__stdcall **)(CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMaxs> *))(LODWORD(p_m_vecSpecifiedSurroundingMaxs[-5].m_Value.y) + 76))(a1: p_m_vecSpecifiedSurroundingMaxs);
  p_m_vecSpecifiedSurroundingMaxs->m_Value.x = 0.0;
  p_m_vecSpecifiedSurroundingMaxs->m_Value.y = 0.0;
  p_m_vecSpecifiedSurroundingMaxs->m_Value.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100C12C0
// Name: public: void CCollisionProperty::MarkSurroundingBoundsDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::MarkSurroundingBoundsDirty(CCollisionProperty *this)
{
  C_BaseEntity *m_pOuter; // eax
  IClientRenderable *v3; // eax
  C_BaseEntity *v4; // ecx
  IClientShadowMgr_vtbl *v5; // esi
  unsigned __int16 v6; // ax

  if ( this->m_pOuter->entindex(this: &this->m_pOuter->IClientNetworkable) != 0 )
  {
    this->m_pOuter->m_iEFlags |= 0x4000u;
    if ( (this->m_pOuter->m_iEFlags & 0x8000) == 0 )
    {
      CDirtySpatialPartitionEntityList::AddEntity(this: &s_DirtyKDTree, pEntity: this->m_pOuter);
      this->m_pOuter->m_iEFlags |= 0x8000u;
    }
    C_BaseEntity::MarkRenderHandleDirty(this: this->m_pOuter);
    m_pOuter = this->m_pOuter;
    if ( m_pOuter != nullptr )
      v3 = &m_pOuter->IClientRenderable;
    else
      v3 = nullptr;
    g_pClientShadowMgr->AddToDirtyShadowList(this: g_pClientShadowMgr, a2: v3, a3: false);
    v4 = this->m_pOuter;
    v5 = g_pClientShadowMgr->__vftable;
    v6 = v4->GetShadowHandle(this: &v4->IClientRenderable);
    v5->MarkRenderToTextureShadowDirty(this: g_pClientShadowMgr, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1390
// Name: public: virtual void CDirtySpatialPartitionEntityList::OnPreQuery(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::OnPreQuery(CDirtySpatialPartitionEntityList *this, __int16 listMask)
{
  CDirtySpatialPartitionEntityList *v2; // edi
  char *v3; // esi
  char *DepthAndSequence; // eax
  int v5; // edx
  CTSListWithFreeList<CBaseHandle>::Node_t *v6; // esi
  TSLNodeBase_t **v7; // edi
  TSLNodeBase_t *v8; // eax
  TSLNodeBase_t *v9; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  int m_Size; // eax
  int v12; // ebx
  CBaseHandle *m_pMemory; // ecx
  int v14; // eax
  CBaseHandle *v15; // ebx
  CBaseHandle *v16; // esi
  TSLNodeBase_t *v17; // [esp-4h] [ebp-2Ch]
  TSLNodeBase_t *v18; // [esp-4h] [ebp-2Ch]
  CUtlVector<CBaseHandle,CUtlMemory<CBaseHandle,int> > vecStillDirty; // [esp+Ch] [ebp-1Ch] BYREF
  CDirtySpatialPartitionEntityList *v20; // [esp+20h] [ebp-8h]
  CTSListWithFreeList<CBaseHandle>::Node_t *pNext; // [esp+24h] [ebp-4h]
  CBaseHandle handle; // [esp+30h] [ebp+8h]
  int handlea; // [esp+30h] [ebp+8h]

  v2 = this;
  v20 = this;
  if ( (listMask & 0x18C) != 0 )
  {
    v3 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    DepthAndSequence = (char *)v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence;
    if ( DepthAndSequence == nullptr || DepthAndSequence != v3 + 1 )
    {
      if ( C_BaseEntity::IsAbsRecomputationsEnabled()
        && LOWORD(v2->m_pszName) != 0
        && *(&v2->m_partitionMutex.m_lockInfo.m_i32 + (_DWORD)v3) == 0 )
      {
        v5 = v2->m_DirtyEntities.m_Head.value32.DepthAndSequence;
        memset(&vecStillDirty, 0, sizeof(vecStillDirty));
        if ( (v5 & 0x10000) != 0
          || _InterlockedCompareExchange(&v2->m_DirtyEntities.m_Head.value32.DepthAndSequence, 0x10000, 0) != 0 )
        {
          CThreadSpinRWLock::SpinLockForWrite(this: (CThreadSpinRWLock *)((char *)&v2->m_DirtyEntities.m_Head.value64 + 4));
        }
        else
        {
          v2->m_DirtyEntities.m_FreeList.m_Head.value.Next = (TSLNodeBase_t *)GetCurrentThreadId();
        }
        v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence = (int)(v3 + 1);
        v6 = (CTSListWithFreeList<CBaseHandle>::Node_t *)CTSListBase::Detach(this: (CTSListBase *)&v2->m_pNext);
        if ( v6 != nullptr )
        {
          do
          {
            v7 = (TSLNodeBase_t **)&v2->IPartitionQueryCallback;
            do
            {
              v8 = *v7;
              handle.m_Index = *((_DWORD *)&v6->Next + 1);
              v17 = v7[1];
              pNext = (CTSListWithFreeList<CBaseHandle>::Node_t *)v6->Next;
              v6->Next = v8;
              if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                      a1: v7,
                                      a2: v6,
                                      a3: (char *)&v17[0x2000].Next + 1,
                                      a4: v8,
                                      a5: v17) == 0 )
              {
                do
                {
                  _mm_pause();
                  v9 = *v7;
                  v18 = v7[1];
                  v6->Next = *v7;
                }
                while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                           a1: v7,
                                           a2: v6,
                                           a3: (char *)&v18[0x2000].Next + 1,
                                           a4: v9,
                                           a5: v18) == 0 );
              }
              v6 = pNext;
              BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                                       this: (CClientEntityList *)cl_entitylist.m_Index,
                                       hEnt: handle);
              if ( BaseEntityFromHandle != nullptr )
              {
                if ( (BaseEntityFromHandle->m_iEFlags & 8) != 0 )
                {
                  m_Size = vecStillDirty.m_Size;
                  v12 = vecStillDirty.m_Size;
                  if ( vecStillDirty.m_Size + 1 > vecStillDirty.m_Memory.m_nAllocationCount )
                  {
                    CUtlMemory<CChoreoActor *,int>::Grow(
                      this: (CUtlMemory<vgui::TreeNode *,int> *)&vecStillDirty,
                      num: vecStillDirty.m_Size - vecStillDirty.m_Memory.m_nAllocationCount + 1);
                    m_Size = vecStillDirty.m_Size;
                  }
                  m_pMemory = vecStillDirty.m_Memory.m_pMemory;
                  vecStillDirty.m_Size = m_Size + 1;
                  v14 = m_Size - v12;
                  vecStillDirty.m_pElements = vecStillDirty.m_Memory.m_pMemory;
                  if ( v14 > 0 )
                  {
                    _V_memmove(
                      dest: (void *)&vecStillDirty.m_Memory.m_pMemory[v12 + 1],
                      src: &vecStillDirty.m_Memory.m_pMemory[v12],
                      count: 4 * v14);
                    m_pMemory = vecStillDirty.m_Memory.m_pMemory;
                  }
                  v15 = &m_pMemory[v12];
                  if ( v15 != nullptr )
                    v15->m_Index = handle.m_Index;
                }
                else
                {
                  CCollisionProperty::UpdatePartition(this: &BaseEntityFromHandle->m_Collision);
                }
              }
            }
            while ( pNext != nullptr );
            v2 = v20;
            v6 = (CTSListWithFreeList<CBaseHandle>::Node_t *)CTSListBase::Detach(this: (CTSListBase *)&v20->m_pNext);
          }
          while ( v6 != nullptr );
          if ( vecStillDirty.m_Size > 0 )
          {
            v16 = vecStillDirty.m_Memory.m_pMemory;
            for ( handlea = vecStillDirty.m_Size; handlea != 0; --handlea )
              CTSListWithFreeList<CBaseHandle>::PushItem(
                this: (CTSListWithFreeList<CBaseHandle> *)&v2->m_pNext,
                init: v16++);
          }
        }
        v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence = 0;
        v2->m_DirtyEntities.m_FreeList.m_Head.value.Next = nullptr;
        v2->m_DirtyEntities.m_Head.value32.DepthAndSequence = 0;
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vecStillDirty);
      }
      CDirtySpatialPartitionEntityList::LockPartitionForRead(this: (CDirtySpatialPartitionEntityList *)((char *)v2 - 12));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C15A0
// Name: RecvProxy_VectorDirtySurround
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_VectorDirtySurround(const CRecvProxyData *pData, CCollisionProperty *pStruct, float *pOut)
{
  float m_Float; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  m_Float = pData->m_Value.m_Float;
  v4 = pData->m_Value.m_Vector[1];
  v5 = pData->m_Value.m_Vector[2];
  if ( m_Float != *pOut || v4 != pOut[1] || v5 != pOut[2] )
  {
    *pOut = m_Float;
    pOut[1] = v4;
    pOut[2] = v5;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: pStruct);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C15F0
// Name: RecvProxy_IntDirtySurround
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_IntDirtySurround(const CRecvProxyData *pData, CCollisionProperty *pStruct, _BYTE *pOut)
{
  if ( (unsigned __int8)*pOut != pData->m_Value.m_Int )
  {
    *pOut = LOBYTE(pData->m_Value.m_Float);
    CCollisionProperty::MarkSurroundingBoundsDirty(this: pStruct);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1620
// Name: public: CCollisionProperty::CCollisionProperty(void)
// Source: json
//------------------------------------------------------------------------------
CCollisionProperty *__thiscall CCollisionProperty::CCollisionProperty(CCollisionProperty *this)
{
  this->__vftable = (CCollisionProperty_vtbl *)&CCollisionProperty::`vftable';
  this->m_Partition = -1;
  CCollisionProperty::Init(this, pEntity: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C1640
// Name: public: void CCollisionProperty::SetSolid(enum SolidType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSolid(CCollisionProperty *this, SolidType_t val)
{
  char v2; // bl
  CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_nSolidType> *p_m_nSolidType; // edi
  C_BaseEntity *m_pOuter; // ecx
  unsigned int m_Index; // edx
  C_BaseEntity *RootMoveParent; // eax

  v2 = val;
  p_m_nSolidType = &this->m_nSolidType;
  if ( this->m_nSolidType.m_Value != val )
  {
    CCollisionProperty::MarkSurroundingBoundsDirty(this);
    if ( val == SOLID_BSP )
    {
      m_pOuter = this->m_pOuter;
      m_Index = m_pOuter->m_pMoveParent.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        RootMoveParent = C_BaseEntity::GetRootMoveParent(this: m_pOuter);
        if ( RootMoveParent->GetSolid(this: RootMoveParent) != SOLID_BSP )
          v2 = 6;
      }
    }
    if ( p_m_nSolidType->m_Value != v2 )
    {
      (*(void (__thiscall **)(CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_nSolidType> *, CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_nSolidType> *))(*(_DWORD *)&p_m_nSolidType[-34].m_Value + 76))(
        a1: p_m_nSolidType - 34,
        a2: p_m_nSolidType);
      p_m_nSolidType->m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C16D0
// Name: public: void CCollisionProperty::SetSolidFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSolidFlags(CCollisionProperty *this, unsigned __int16 flags)
{
  CNetworkVarBase<unsigned short,CCollisionProperty::NetworkVar_m_usSolidFlags> *p_m_usSolidFlags; // esi
  int m_Value; // edi
  int v4; // eax
  CCollisionProperty *v5; // [esp+Ch] [ebp-4h]

  p_m_usSolidFlags = &this->m_usSolidFlags;
  m_Value = this->m_usSolidFlags.m_Value;
  v5 = this;
  if ( this->m_usSolidFlags.m_Value != flags )
  {
    this->NetworkStateChanged(this, a2: &this->m_usSolidFlags);
    this = v5;
    p_m_usSolidFlags->m_Value = flags;
  }
  v4 = p_m_usSolidFlags->m_Value;
  if ( m_Value != v4 )
  {
    if ( (((unsigned __int8)m_Value ^ (unsigned __int8)v4) & 0xC0) != 0 )
    {
      CCollisionProperty::MarkSurroundingBoundsDirty(this);
      this = v5;
    }
    if ( (((unsigned __int8)m_Value ^ (unsigned __int8)p_m_usSolidFlags->m_Value) & 0xC) != 0 )
      C_BaseEntity::CollisionRulesChanged(this: this->m_pOuter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1730
// Name: public: void CCollisionProperty::SetCollisionBounds(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetCollisionBounds(
        CCollisionProperty *this,
        const Vector *mins,
        const Vector *maxs)
{
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *p_m_vecMins; // esi
  const Vector *v4; // edx
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMaxs> *p_m_vecMaxs; // esi
  CCollisionProperty *v6; // [esp-4h] [ebp-10h]

  p_m_vecMins = &this->m_vecMins;
  v6 = this;
  if ( mins->x == this->m_vecMins.m_Value.x
    && mins->y == this->m_vecMins.m_Value.y
    && mins->z == this->m_vecMins.m_Value.z )
  {
    v4 = maxs;
    if ( maxs->x == this->m_vecMaxs.m_Value.x
      && maxs->y == this->m_vecMaxs.m_Value.y
      && maxs->z == this->m_vecMaxs.m_Value.z )
    {
      return;
    }
  }
  else
  {
    v4 = maxs;
  }
  if ( mins->x != p_m_vecMins->m_Value.x || mins->y != this->m_vecMins.m_Value.y || mins->z != this->m_vecMins.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->m_vecMins);
    this = v6;
    p_m_vecMins->m_Value = *mins;
    v4 = maxs;
  }
  p_m_vecMaxs = &this->m_vecMaxs;
  if ( v4->x != this->m_vecMaxs.m_Value.x || v4->y != this->m_vecMaxs.m_Value.y || v4->z != this->m_vecMaxs.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->m_vecMaxs);
    this = v6;
    p_m_vecMaxs->m_Value = *maxs;
    v4 = maxs;
  }
  this->m_flRadius = fsqrt(
                       (float)((float)((float)(v4->y - mins->y) * (float)(v4->y - mins->y))
                             + (float)((float)(v4->z - mins->z) * (float)(v4->z - mins->z)))
                     + (float)((float)(v4->x - mins->x) * (float)(v4->x - mins->x)))
                   * 0.5;
  CCollisionProperty::MarkSurroundingBoundsDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C18E0
// Name: public: void CCollisionProperty::SetSurroundingBoundsType(enum SurroundingBoundsType_t,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSurroundingBoundsType(
        CCollisionProperty *this,
        SurroundingBoundsType_t type,
        const Vector *pMins,
        const Vector *pMaxs)
{
  CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_nSurroundType> *p_m_nSurroundType; // esi

  p_m_nSurroundType = &this->m_nSurroundType;
  if ( this->m_nSurroundType.m_Value != (_BYTE)type )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSurroundType);
    p_m_nSurroundType->m_Value = type;
  }
  if ( type == USE_SPECIFIED_BOUNDS )
  {
    if ( pMins->x != this->m_vecSpecifiedSurroundingMins.m_Value.x
      || pMins->y != this->m_vecSpecifiedSurroundingMins.m_Value.y
      || pMins->z != this->m_vecSpecifiedSurroundingMins.m_Value.z )
    {
      this->NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMins);
      this->m_vecSpecifiedSurroundingMins.m_Value = *pMins;
    }
    if ( pMaxs->x != this->m_vecSpecifiedSurroundingMaxs.m_Value.x
      || pMaxs->y != this->m_vecSpecifiedSurroundingMaxs.m_Value.y
      || pMaxs->z != this->m_vecSpecifiedSurroundingMaxs.m_Value.z )
    {
      this->NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMaxs);
      this->m_vecSpecifiedSurroundingMaxs.m_Value = *pMaxs;
    }
    this->m_vecSurroundingMins = *pMins;
    this->m_vecSurroundingMaxs = *pMaxs;
  }
  else
  {
    CCollisionProperty::MarkSurroundingBoundsDirty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C19E0
// Name: void UpdateDirtySpatialPartitionEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateDirtySpatialPartitionEntities()
{
  void *v0; // eax

  CDirtySpatialPartitionEntityList::OnPreQuery(
    this: (CDirtySpatialPartitionEntityList *)&s_DirtyKDTree.IPartitionQueryCallback,
    listMask: 396);
  if ( s_DirtyKDTree.m_partitionWriteId == 0 )
  {
    v0 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    if ( s_DirtyKDTree.m_nReadLockCount[(_DWORD)v0]-- == 1 )
      _InterlockedExchangeAdd((volatile signed __int32 *)&s_DirtyKDTree.m_partitionMutex, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1A20
// Name: RecvProxy_Solid
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Solid(const CRecvProxyData *pData, CCollisionProperty *pStruct)
{
  CCollisionProperty::SetSolid(this: pStruct, val: (SolidType_t)pData->m_Value.m_Int);
}

//------------------------------------------------------------------------------
// Address: 0x100C1A40
// Name: RecvProxy_SolidFlags
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_SolidFlags(const CRecvProxyData *pData, unsigned __int16 *pStruct)
{
  int v2; // ebx
  __int16 m_Float_low; // di
  _WORD *v4; // esi
  int v5; // eax

  v2 = pStruct[16];
  m_Float_low = LOWORD(pData->m_Value.m_Float);
  v4 = pStruct + 16;
  if ( pStruct[16] != m_Float_low )
  {
    (*(void (__thiscall **)(unsigned __int16 *, char *))(*(_DWORD *)pStruct + 76))(
      a1: pStruct,
      a2: (char *)pStruct + 32);
    *v4 = m_Float_low;
  }
  v5 = (unsigned __int16)*v4;
  if ( v2 != v5 )
  {
    if ( (((unsigned __int8)v2 ^ (unsigned __int8)v5) & 0xC0) != 0 )
      CCollisionProperty::MarkSurroundingBoundsDirty(this: (CCollisionProperty *)pStruct);
    if ( (((unsigned __int8)v2 ^ *(_BYTE *)v4) & 0xC) != 0 )
      C_BaseEntity::CollisionRulesChanged(this: *((C_BaseEntity **)pStruct + 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C1AA0
// Name: RecvProxy_OBBMins
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_OBBMins(const CRecvProxyData *pData, CCollisionProperty *pStruct)
{
  const Vector *v2; // eax

  v2 = pStruct->OBBMaxs(this: pStruct);
  CCollisionProperty::SetCollisionBounds(this: pStruct, mins: (const Vector *)&pData->m_Value, maxs: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100C1AD0
// Name: RecvProxy_OBBMaxs
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_OBBMaxs(const CRecvProxyData *pData, CCollisionProperty *pStruct)
{
  const Vector *v2; // eax

  v2 = pStruct->OBBMins(this: pStruct);
  CCollisionProperty::SetCollisionBounds(this: pStruct, mins: v2, maxs: (const Vector *)&pData->m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x100C1C20
// Name: public: void CCollisionProperty::UseTriggerBounds(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::UseTriggerBounds(CCollisionProperty *this, bool bEnable, float flBloat)
{
  CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_triggerBloat> *p_m_triggerBloat; // esi
  unsigned __int16 m_Value; // ax
  CNetworkVarBase<unsigned short,CCollisionProperty::NetworkVar_m_usSolidFlags> *p_m_usSolidFlags; // esi
  int v7; // ecx
  unsigned __int16 v8; // di
  int v9; // edi
  int v10; // ebx
  unsigned __int16 v11; // di
  int v12; // eax
  int bEnablea; // [esp+Ch] [ebp+8h]
  unsigned __int8 flBloat_3; // [esp+13h] [ebp+Fh]

  p_m_triggerBloat = &this->m_triggerBloat;
  flBloat_3 = (int)flBloat;
  if ( this->m_triggerBloat.m_Value != flBloat_3 )
  {
    this->NetworkStateChanged(this, a2: &this->m_triggerBloat);
    p_m_triggerBloat->m_Value = flBloat_3;
  }
  m_Value = this->m_usSolidFlags.m_Value;
  p_m_usSolidFlags = &this->m_usSolidFlags;
  if ( bEnable )
  {
    v7 = this->m_usSolidFlags.m_Value;
    v8 = m_Value | 0x80;
    bEnablea = v7;
    if ( p_m_usSolidFlags->m_Value != (m_Value | 0x80) )
    {
      this->NetworkStateChanged(this, a2: &this->m_usSolidFlags);
      v7 = bEnablea;
      p_m_usSolidFlags->m_Value = v8;
    }
    v9 = p_m_usSolidFlags->m_Value;
    if ( v7 != v9 )
    {
      if ( (((unsigned __int8)v7 ^ (unsigned __int8)v9) & 0xC0) != 0 )
      {
        CCollisionProperty::MarkSurroundingBoundsDirty(this);
        LOBYTE(v7) = bEnablea;
      }
      if ( (((unsigned __int8)v7 ^ (unsigned __int8)p_m_usSolidFlags->m_Value) & 0xC) != 0 )
        C_BaseEntity::CollisionRulesChanged(this: this->m_pOuter);
    }
  }
  else
  {
    v10 = this->m_usSolidFlags.m_Value;
    v11 = m_Value & 0xFF7F;
    if ( p_m_usSolidFlags->m_Value != (m_Value & 0xFF7F) )
    {
      (*(void (__thiscall **)(CNetworkVarBase<unsigned short,CCollisionProperty::NetworkVar_m_usSolidFlags> *, CNetworkVarBase<unsigned short,CCollisionProperty::NetworkVar_m_usSolidFlags> *))(*(_DWORD *)&p_m_usSolidFlags[-16].m_Value + 76))(
        a1: p_m_usSolidFlags - 16,
        a2: p_m_usSolidFlags);
      p_m_usSolidFlags->m_Value = v11;
    }
    v12 = p_m_usSolidFlags->m_Value;
    if ( v10 != v12 )
    {
      if ( (((unsigned __int8)v10 ^ (unsigned __int8)v12) & 0xC0) != 0 )
        CCollisionProperty::MarkSurroundingBoundsDirty(this);
      if ( (((unsigned __int8)v10 ^ LOBYTE(p_m_usSolidFlags->m_Value)) & 0xC) != 0 )
        C_BaseEntity::CollisionRulesChanged(this: this->m_pOuter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101390C0
// Name: public: virtual class IHandleEntity __near * CCollisionProperty::GetEntityHandle(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCollisionProperty::GetEntityHandle(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10415080
// Name: CCollisionProperty_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void CCollisionProperty_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  CCollisionProperty::m_PredMap.dataNumFields = 5;
  CCollisionProperty::m_PredMap.dataDesc = (typedescription_t *)&unk_105A062C;
}

//------------------------------------------------------------------------------
// Address: 0x104150A0
// Name: DT_CollisionProperty::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CollisionProperty::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CollisionProperty::g_RecvTable);
  return atexit(func: DT_CollisionProperty::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104150C0
// Name: DT_CollisionProperty::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CollisionProperty::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CollisionProperty::ignored>();
  DT_CollisionProperty::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431330
// Name: DT_CollisionProperty::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CollisionProperty::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CollisionProperty::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104150D0
// Name: _dynamic_initializer_for__cl_show_bounds_errors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_show_bounds_errors__()
{
  ConVar::ConVar(this: &cl_show_bounds_errors, pName: "cl_show_bounds_errors", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_show_bounds_errors__);
}

//------------------------------------------------------------------------------
// Address: 0x10415100
// Name: _dynamic_initializer_for__s_ColorCorrectionMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ColorCorrectionMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_ColorCorrectionMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10415110
// Name: _dynamic_initializer_for__mat_colcorrection_editor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_editor__()
{
  ConVar::ConVar(this: &mat_colcorrection_editor, pName: "mat_colcorrection_editor", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_editor__);
}

//------------------------------------------------------------------------------
// Address: 0x10415140
// Name: _dynamic_initializer_for__g_ColorCorrectionList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ColorCorrectionList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ColorCorrectionList__);
}

//------------------------------------------------------------------------------
// Address: 0x10415150
// Name: _dynamic_initializer_for__g_ColorCorrectionVolumeList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ColorCorrectionVolumeList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ColorCorrectionVolumeList__);
}

//------------------------------------------------------------------------------
// Address: 0x10431340
// Name: _dynamic_atexit_destructor_for__cl_show_bounds_errors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_show_bounds_errors__()
{
  ConVar::~ConVar(this: &cl_show_bounds_errors);
}

//------------------------------------------------------------------------------
// Address: 0x10431350
// Name: _dynamic_atexit_destructor_for__s_DirtyKDTree__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DirtyKDTree__()
{
  CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(this: &s_DirtyKDTree);
}

//------------------------------------------------------------------------------
// Address: 0x10431360
// Name: _dynamic_atexit_destructor_for__mat_colcorrection_editor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colcorrection_editor__()
{
  ConVar::~ConVar(this: &mat_colcorrection_editor);
}

//------------------------------------------------------------------------------
// Address: 0x10431370
// Name: _dynamic_atexit_destructor_for__g_ColorCorrectionList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ColorCorrectionList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ColorCorrectionList);
}

//------------------------------------------------------------------------------
// Address: 0x10431380
// Name: _dynamic_atexit_destructor_for__g_ColorCorrectionVolumeList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ColorCorrectionVolumeList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ColorCorrectionVolumeList);
}

//------------------------------------------------------------------------------
// Address: 0x10431390
// Name: _dynamic_atexit_destructor_for__s_ColorCorrectionMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ColorCorrectionMgr__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_ColorCorrectionMgr.m_colorCorrectionWeights);
  IGameSystem::~IGameSystem(this: &s_ColorCorrectionMgr);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100EDFE0
// Name: public: virtual bool CDirtySpatialPartitionEntityList::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDirtySpatialPartitionEntityList::Init(CDirtySpatialPartitionEntityList *this)
{
  if ( this != nullptr )
    partition->InstallQueryCallback(this: partition, a2: &this->IPartitionQueryCallback);
  else
    partition->InstallQueryCallback(this: partition, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EE010
// Name: public: virtual void CDirtySpatialPartitionEntityList::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::Shutdown(CDirtySpatialPartitionEntityList *this)
{
  if ( this != nullptr )
    partition->RemoveQueryCallback(this: partition, a2: &this->IPartitionQueryCallback);
  else
    partition->RemoveQueryCallback(this: partition, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100EE040
// Name: private: virtual struct datamap_t __near * CCollisionProperty::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCollisionProperty::GetDataDescMap(CCollisionProperty *this)
{
  return &CCollisionProperty::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EE050
// Name: SendProxy_Solid
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_Solid(const SendProp *pProp, const void *pStruct, const void *pData, DVariant *pOut)
{
  pOut->m_Int = (*(int (__thiscall **)(const void *))(*(_DWORD *)pStruct + 44))(a1: pStruct);
}

//------------------------------------------------------------------------------
// Address: 0x100EE070
// Name: SendProxy_SolidFlags
// Source: json
//------------------------------------------------------------------------------
void __cdecl SendProxy_SolidFlags(const SendProp *pProp, const void *pStruct, const void *pData, DVariant *pOut)
{
  pOut->m_Int = (*(int (__thiscall **)(const void *))(*(_DWORD *)pStruct + 48))(a1: pStruct);
}

//------------------------------------------------------------------------------
// Address: 0x100EE090
// Name: public: virtual int CCollisionProperty::GetCollisionModelIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetCollisionModelIndex(CCollisionProperty *this)
{
  return this->m_pOuter->GetModelIndex(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100EE0A0
// Name: public: virtual struct model_t const __near * CCollisionProperty::GetCollisionModel(void)
// Source: json
//------------------------------------------------------------------------------
const struct model_t *__thiscall CCollisionProperty::GetCollisionModel(CCollisionProperty *this)
{
  return CBaseEntity::GetModel(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100EE0B0
// Name: public: virtual bool CCollisionProperty::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::TestCollision(ConVar *this, int value, unsigned int fContentsMask, CGameTrace *tr)
{
  ((void (__thiscall *)(ConCommandBase *, int, unsigned int, CGameTrace *))this->m_pNext->ConCommandBase::__vftable[1].IsFlagSet)(
    a1: this->m_pNext,
    a2: value,
    a3: fContentsMask,
    a4: tr);
}

//------------------------------------------------------------------------------
// Address: 0x100EE0C0
// Name: public: virtual bool CCollisionProperty::TestHitboxes(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionProperty::TestHitboxes(
        CCollisionProperty *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  return this->m_pOuter->TestHitboxes(this: this->m_pOuter, a2: ray, a3: fContentsMask, a4: tr);
}

//------------------------------------------------------------------------------
// Address: 0x100EE0D0
// Name: public: void CCollisionProperty::DestroyPartitionHandle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::DestroyPartitionHandle(CCollisionProperty *this)
{
  int m_Partition; // eax

  m_Partition = this->m_Partition;
  if ( (_WORD)m_Partition != 0xFFFF )
  {
    partition->DestroyHandle(this: partition, a2: m_Partition);
    this->m_Partition = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE100
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  int DepthAndSequence; // [esp-4h] [ebp-10h]
  int v6; // [esp-4h] [ebp-10h]

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: DepthAndSequence + 65537,
                          a4: Next,
                          a5: DepthAndSequence) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v6 = this->m_Head.value32.DepthAndSequence;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v6 + 65537, a4: Next, a5: v6) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100EE160
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  Next = this->m_Head.value.Next;
  DepthAndSequence = this->m_Head.value32.DepthAndSequence;
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: DepthAndSequence - 1,
                             a4: Next,
                             a5: DepthAndSequence) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    DepthAndSequence = this->m_Head.value32.DepthAndSequence;
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x100EE1A0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: this->m_Head.value32.DepthAndSequence & 0xFFFF0000,
                            a4: Next,
                            a5: this->m_Head.value32.DepthAndSequence) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EE1E0
// Name: public: CCollisionProperty::~CCollisionProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::~CCollisionProperty(CCollisionProperty *this)
{
  int m_Partition; // eax

  m_Partition = this->m_Partition;
  this->__vftable = (CCollisionProperty_vtbl *)&CCollisionProperty::`vftable';
  if ( (_WORD)m_Partition != 0xFFFF )
  {
    partition->DestroyHandle(this: partition, a2: m_Partition);
    this->m_Partition = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE210
// Name: public: virtual class IPhysicsObject __near * CCollisionProperty::GetVPhysicsObject(void)const
// Source: json
//------------------------------------------------------------------------------
IPhysicsObject *__thiscall CCollisionProperty::GetVPhysicsObject(CCollisionProperty *this)
{
  return this->m_pOuter->m_pPhysicsObject;
}

//------------------------------------------------------------------------------
// Address: 0x100EE220
// Name: public: virtual enum SolidType_t CCollisionProperty::GetSolid(void)const
// Source: json
//------------------------------------------------------------------------------
SolidType_t __thiscall CCollisionProperty::GetSolid(CCollisionProperty *this)
{
  return this->m_nSolidType.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100EE260
// Name: public: virtual class Vector const __near & CCollisionProperty::OBBMaxs(void)const
// Source: json
//------------------------------------------------------------------------------
CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMaxs> *__thiscall CCollisionProperty::OBBMaxs(
        CCollisionProperty *this)
{
  return &this->m_vecMaxs;
}

//------------------------------------------------------------------------------
// Address: 0x100EE270
// Name: private: bool CCollisionProperty::ComputeHitboxSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionProperty::ComputeHitboxSurroundingBox(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CBaseAnimating *v3; // eax

  v3 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
  if ( v3 != nullptr )
    return CBaseAnimating::ComputeHitboxSurroundingBox(this: v3, pVecWorldMins, pVecWorldMaxs);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EE2A0
// Name: public: class Vector const __near & CCollisionProperty::WorldToCollisionSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::WorldToCollisionSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  unsigned __int8 m_Value; // al
  const QAngle *v5; // eax
  const matrix3x4_t *v6; // eax
  const Vector *v8; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v5 = this->GetCollisionAngles(this), vec3_angle.x == v5->x) && vec3_angle.y == v5->y && vec3_angle.z == v5->z )
  {
    v8 = this->GetCollisionOrigin(this);
    pResult->x = in->x - v8->x;
    pResult->y = in->y - v8->y;
    pResult->z = in->z - v8->z;
    return pResult;
  }
  else
  {
    v6 = this->CollisionToWorldTransform(this);
    VectorITransform(in1: &in->x, in2: v6, out: &pResult->x);
    return pResult;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE360
// Name: public: void CDirtySpatialPartitionEntityList::LockPartitionForRead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::LockPartitionForRead(CDirtySpatialPartitionEntityList *this)
{
  void *v2; // edi
  signed __int32 m_i32; // edx

  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
  if ( this->m_nReadLockCount[(_DWORD)v2] == 0 )
  {
    if ( (this->m_partitionMutex.m_lockInfo.m_i32 & 0x10000) != 0
      || (m_i32 = (unsigned __int16)this->m_partitionMutex.m_lockInfo.m_i32,
          _InterlockedCompareExchange((volatile signed __int32 *)&this->m_partitionMutex, m_i32 + 1, m_i32) != m_i32) )
    {
      CThreadSpinRWLock::SpinLockForRead(this: &this->m_partitionMutex);
    }
  }
  ++this->m_nReadLockCount[(_DWORD)v2];
}

//------------------------------------------------------------------------------
// Address: 0x100EE3B0
// Name: public: virtual void CDirtySpatialPartitionEntityList::OnPostQuery(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::OnPostQuery(CDirtySpatialPartitionEntityList *this, char listMask)
{
  void *v3; // eax

  if ( (listMask & 0x13) != 0 && this->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence == 0 )
  {
    v3 = GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    if ( (*(&this->m_partitionMutex.m_lockInfo.m_i32 + (_DWORD)v3))-- == 1 )
      _InterlockedExchangeAdd(&this->m_DirtyEntities.m_Head.value32.DepthAndSequence, 0xFFFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE5D0
// Name: public: virtual int CCollisionProperty::GetCollisionGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetCollisionGroup(CCollisionProperty *this)
{
  return this->m_pOuter->m_CollisionGroup.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100EE5E0
// Name: public: virtual unsigned int CCollisionProperty::GetRequiredTriggerFlags(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::GetRequiredTriggerFlags(CCollisionProperty *this)
{
  if ( this->GetCollisionGroup(this) == 1 )
    return 512;
  else
    return 8 * ((this->m_usSolidFlags.m_Value & 8) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100EE610
// Name: public: virtual struct matrix3x4_t const __near * CCollisionProperty::GetRootParentToWorldTransform(void)const
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__thiscall CCollisionProperty::GetRootParentToWorldTransform(CCollisionProperty *this)
{
  CBaseEntity *RootMoveParent; // eax

  if ( (this->m_usSolidFlags.m_Value & 0x100) != 0
    && (RootMoveParent = CBaseEntity::GetRootMoveParent(this: this->m_pOuter)) != nullptr )
  {
    return RootMoveParent->m_Collision.CollisionToWorldTransform(this: &RootMoveParent->m_Collision);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE640
// Name: public: virtual class QAngle const __near & CCollisionProperty::GetCollisionAngles(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__usercall CCollisionProperty::GetCollisionAngles@<eax>(CCollisionProperty *this@<ecx>, int a2@<ebp>)
{
  unsigned __int8 m_Value; // al
  CBaseEntity *m_pOuter; // esi

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0 )
    return &vec3_angle;
  m_Value = this->m_nSolidType.m_Value;
  if ( m_Value == 2 || m_Value == 0 )
    return &vec3_angle;
  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  return &m_pOuter->m_angAbsRotation;
}

//------------------------------------------------------------------------------
// Address: 0x100EE680
// Name: public: virtual struct matrix3x4_t const __near & CCollisionProperty::CollisionToWorldTransform(void)const
// Source: json
//------------------------------------------------------------------------------
const matrix3x4_t *__usercall CCollisionProperty::CollisionToWorldTransform@<eax>(
        CCollisionProperty *this@<ecx>,
        int a2@<ebp>)
{
  matrix3x4_t *v3; // esi
  bool v4; // zf
  unsigned __int8 m_Value; // al
  CBaseEntity *m_pOuter; // edi
  CBaseEntity *v8; // edi

  if ( (_S4_20 & 1) == 0 )
    _S4_20 |= 1u;
  v3 = &s_matTemp[s_nIndex];
  v4 = (this->m_usSolidFlags.m_Value & 0x40) == 0;
  s_nIndex = ((_BYTE)s_nIndex + 1) & 3;
  if ( v4 && (m_Value = this->m_nSolidType.m_Value) != 2 && m_Value != 0 )
  {
    m_pOuter = this->m_pOuter;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2);
    return &m_pOuter->m_rgflCoordinateFrame;
  }
  else
  {
    SetIdentityMatrix(matrix: v3);
    v8 = this->m_pOuter;
    if ( (v8->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v8, a2);
    MatrixSetColumn(in: &v8->m_vecAbsOrigin, column: 3, out: v3);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE720
// Name: public: class Vector const __near & CCollisionProperty::NormalizedToWorldSpace(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CCollisionProperty::NormalizedToWorldSpace(
        CCollisionProperty *this,
        const Vector *in,
        Vector *pResult)
{
  Vector vecCollisionSpace; // [esp+0h] [ebp-Ch] BYREF

  vecCollisionSpace.x = (float)((float)(this->m_vecMaxs.m_Value.x - this->m_vecMins.m_Value.x) * in->x)
                      + this->m_vecMins.m_Value.x;
  vecCollisionSpace.y = (float)((float)(this->m_vecMaxs.m_Value.y - this->m_vecMins.m_Value.y) * in->y)
                      + this->m_vecMins.m_Value.y;
  vecCollisionSpace.z = (float)((float)(this->m_vecMaxs.m_Value.z - this->m_vecMins.m_Value.z) * in->z)
                      + this->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this, in: &vecCollisionSpace, pResult);
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x100EE790
// Name: public: void CCollisionProperty::RandomPointInBounds(class Vector const __near &,class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::RandomPointInBounds(
        CCollisionProperty *this,
        const Vector *vecNormalizedMins,
        const Vector *vecNormalizedMaxs,
        Vector *pPoint)
{
  Vector in; // [esp+24h] [ebp-18h] BYREF
  Vector vecNormalizedSpace; // [esp+30h] [ebp-Ch]

  vecNormalizedSpace.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->x),
                           a3: LODWORD(vecNormalizedMaxs->x));
  vecNormalizedSpace.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->y),
                           a3: LODWORD(vecNormalizedMaxs->y));
  vecNormalizedSpace.z = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                           a1: random,
                           a2: LODWORD(vecNormalizedMins->z),
                           a3: LODWORD(vecNormalizedMaxs->z));
  in.x = (float)((float)(this->m_vecMaxs.m_Value.x - this->m_vecMins.m_Value.x) * vecNormalizedSpace.x)
       + this->m_vecMins.m_Value.x;
  in.y = (float)((float)(this->m_vecMaxs.m_Value.y - this->m_vecMins.m_Value.y) * vecNormalizedSpace.y)
       + this->m_vecMins.m_Value.y;
  in.z = (float)((float)(this->m_vecMaxs.m_Value.z - this->m_vecMins.m_Value.z) * vecNormalizedSpace.z)
       + this->m_vecMins.m_Value.z;
  CCollisionProperty::CollisionToWorldSpace(this, &in, pResult: pPoint);
}

//------------------------------------------------------------------------------
// Address: 0x100EE880
// Name: private: void CCollisionProperty::CollisionAABBToWorldAABB(class Vector const __near &,class Vector const __near &,class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::CollisionAABBToWorldAABB(
        CCollisionProperty *this,
        const Vector *entityMins,
        const Vector *entityMaxs,
        Vector *pWorldMins,
        Vector *pWorldMaxs)
{
  unsigned __int8 m_Value; // al
  const QAngle *v7; // eax
  CBaseEntity *m_pOuter; // esi
  CBaseEntity *v9; // esi
  matrix3x4_t tm; // [esp+4h] [ebp-30h] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0
    || (m_Value = this->m_nSolidType.m_Value) == 2
    || m_Value == 0
    || (v7 = this->GetCollisionAngles(this), vec3_angle.x == v7->x) && vec3_angle.y == v7->y && vec3_angle.z == v7->z )
  {
    m_pOuter = this->m_pOuter;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    pWorldMins->x = entityMins->x + m_pOuter->m_vecAbsOrigin.x;
    pWorldMins->y = m_pOuter->m_vecAbsOrigin.y + entityMins->y;
    pWorldMins->z = m_pOuter->m_vecAbsOrigin.z + entityMins->z;
    v9 = this->m_pOuter;
    if ( (v9->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    pWorldMaxs->x = v9->m_vecAbsOrigin.x + entityMaxs->x;
    pWorldMaxs->y = v9->m_vecAbsOrigin.y + entityMaxs->y;
    pWorldMaxs->z = v9->m_vecAbsOrigin.z + entityMaxs->z;
  }
  else
  {
    tm = *this->CollisionToWorldTransform(this);
    TransformAABB(
      transform: &tm,
      vecMinsIn: entityMins,
      vecMaxsIn: entityMaxs,
      vecMinsOut: pWorldMins,
      vecMaxsOut: pWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEA00
// Name: public: bool CCollisionProperty::IsPointInBounds(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCollisionProperty::IsPointInBounds(CCollisionProperty *this, const Vector *vecWorldPt)
{
  Vector vecLocalSpace; // [esp+4h] [ebp-Ch] BYREF

  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: &vecLocalSpace);
  return vecLocalSpace.x >= this->m_vecMins.m_Value.x
      && this->m_vecMaxs.m_Value.x >= vecLocalSpace.x
      && vecLocalSpace.y >= this->m_vecMins.m_Value.y
      && this->m_vecMaxs.m_Value.y >= vecLocalSpace.y
      && vecLocalSpace.z >= this->m_vecMins.m_Value.z
      && this->m_vecMaxs.m_Value.z >= vecLocalSpace.z;
}

//------------------------------------------------------------------------------
// Address: 0x100EEA70
// Name: public: void CCollisionProperty::CalcNearestPoint(class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::CalcNearestPoint(
        CCollisionProperty *this,
        const Vector *vecWorldPt,
        Vector *pVecNearestWorldPt)
{
  Vector localClosestPt; // [esp+4h] [ebp-18h] BYREF
  Vector localPt; // [esp+10h] [ebp-Ch] BYREF

  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: &localPt);
  CalcClosestPointOnAABB(
    mins: &this->m_vecMins.m_Value,
    maxs: &this->m_vecMaxs.m_Value,
    point: &localPt,
    closestOut: &localClosestPt);
  CCollisionProperty::CollisionToWorldSpace(this, in: &localClosestPt, pResult: pVecNearestWorldPt);
}

//------------------------------------------------------------------------------
// Address: 0x100EEAC0
// Name: public: float CCollisionProperty::CalcDistanceFromPoint(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge CCollisionProperty::CalcDistanceFromPoint@<st0>(
        CCollisionProperty *this@<ecx>,
        float a2@<ebp>,
        const Vector *vecWorldPt)
{
  Vector v5; // [esp-Ch] [ebp-28h] BYREF
  Vector localClosestPt; // [esp+0h] [ebp-1Ch] BYREF
  float v7; // [esp+Ch] [ebp-10h]
  Vector localPt; // [esp+10h] [ebp-Ch]
  float retaddr; // [esp+1Ch] [ebp+0h]

  localPt.x = a2;
  localPt.y = retaddr;
  CCollisionProperty::WorldToCollisionSpace(this, in: vecWorldPt, pResult: (Vector *)&localClosestPt.y);
  CalcClosestPointOnAABB(
    mins: &this->m_vecMins.m_Value,
    maxs: &this->m_vecMaxs.m_Value,
    point: (Vector *)&localClosestPt.y,
    closestOut: &v5);
  return fsqrt(
           (float)((float)((float)(localClosestPt.z - v5.y) * (float)(localClosestPt.z - v5.y))
                 + (float)((float)(v7 - v5.z) * (float)(v7 - v5.z)))
         + (float)((float)(localClosestPt.y - v5.x) * (float)(localClosestPt.y - v5.x)));
}

//------------------------------------------------------------------------------
// Address: 0x100EEB60
// Name: private: void CCollisionProperty::ComputeVPhysicsSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeVPhysicsSurroundingBox(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  CBaseEntity *m_pOuter; // ebx
  CCollisionProperty_vtbl *v6; // edx
  int v7; // eax
  int v8; // eax
  Vector *v9; // ebx
  Vector *v10; // esi
  CBaseEntity *v11; // ebx
  float v12; // xmm0_4
  CBaseEntity *v13; // ebx
  float x; // xmm1_4
  CBaseEntity *v15; // ebx
  double z; // st7
  double v17; // xmm0_8
  float y; // xmm1_4
  float v19; // xmm0_4
  double v20; // xmm0_8
  double v21; // xmm1_8
  float v22; // xmm1_4
  float v23; // xmm0_4
  double v24; // xmm0_8
  double v25; // xmm1_8
  float v26; // xmm0_4
  double v27; // xmm0_8
  float v28; // xmm1_4
  float v29; // xmm0_4
  double v30; // xmm0_8
  double v31; // xmm1_8
  float v32; // xmm1_4
  float v33; // xmm0_4
  double v34; // xmm0_8
  double v35; // xmm1_8
  Vector vecWorldTriggerMaxs; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecWorldTriggerMins; // [esp+18h] [ebp-10h] BYREF
  float flRadius; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF
  Vector *pVecWorldMinsa; // [esp+30h] [ebp+8h]

  m_pPhysicsObject = this->m_pOuter->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    goto LABEL_12;
  if ( m_pPhysicsObject->GetCollide(this: this->m_pOuter->m_pPhysicsObject) != nullptr )
  {
    m_pOuter = this->m_pOuter;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    v6 = this->__vftable;
    flRadius = *(float *)&physcollision->__vftable;
    v7 = (int)v6->GetCollisionAngles(this);
    v8 = ((int (__thiscall *)(IPhysicsObject *, Vector *, int))m_pPhysicsObject->GetCollide)(
           a1: m_pPhysicsObject,
           a2: &m_pOuter->m_vecAbsOrigin,
           a3: v7);
    v9 = pVecWorldMaxs;
    v10 = pVecWorldMins;
    (*(void (__thiscall **)(IPhysicsCollision *, Vector *, Vector *, int))(LODWORD(flRadius) + 92))(
      a1: physcollision,
      a2: pVecWorldMins,
      a3: pVecWorldMaxs,
      a4: v8);
    goto LABEL_15;
  }
  if ( ((double (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetSphereRadius)(a1: m_pPhysicsObject) == 0.0 )
  {
LABEL_12:
    v15 = this->m_pOuter;
    if ( (v15->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    v10 = pVecWorldMins;
    pVecWorldMins->x = v15->m_vecAbsOrigin.x;
    pVecWorldMins->y = v15->m_vecAbsOrigin.y;
    z = v15->m_vecAbsOrigin.z;
    v9 = pVecWorldMaxs;
    pVecWorldMins->z = z;
    *pVecWorldMaxs = *pVecWorldMins;
  }
  else
  {
    flRadius = m_pPhysicsObject->GetSphereRadius(this: m_pPhysicsObject);
    v11 = this->m_pOuter;
    if ( (v11->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    v10 = pVecWorldMins;
    v12 = flRadius;
    pVecWorldMins->x = v11->m_vecAbsOrigin.x - flRadius;
    pVecWorldMins->y = v11->m_vecAbsOrigin.y - v12;
    pVecWorldMins->z = v11->m_vecAbsOrigin.z - v12;
    v13 = this->m_pOuter;
    pVecWorldMinsa = (Vector *)v13;
    if ( (v13->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v13, a2: (int)&savedregs);
      v12 = flRadius;
    }
    x = v13->m_vecAbsOrigin.x;
    v9 = pVecWorldMaxs;
    pVecWorldMaxs->x = x + v12;
    pVecWorldMaxs->y = pVecWorldMinsa[38].z + v12;
    pVecWorldMaxs->z = pVecWorldMinsa[39].x + v12;
  }
LABEL_15:
  if ( SLOBYTE(this->m_usSolidFlags.m_Value) < 0 )
  {
    this->WorldSpaceTriggerBounds(this, a2: &vecWorldTriggerMins, a3: &vecWorldTriggerMaxs);
    v17 = vecWorldTriggerMins.x;
    if ( vecWorldTriggerMins.x > (double)v10->x )
      v17 = v10->x;
    y = v10->y;
    v19 = v17;
    v10->x = v19;
    v20 = vecWorldTriggerMins.y;
    v21 = y;
    if ( vecWorldTriggerMins.y > v21 )
      v20 = v21;
    v22 = v10->z;
    v23 = v20;
    v10->y = v23;
    v24 = vecWorldTriggerMins.z;
    v25 = v22;
    if ( vecWorldTriggerMins.z > v25 )
      v24 = v25;
    v26 = v24;
    v10->z = v26;
    v27 = vecWorldTriggerMaxs.x;
    if ( vecWorldTriggerMaxs.x < (double)v9->x )
      v27 = v9->x;
    v28 = v9->y;
    v29 = v27;
    v9->x = v29;
    v30 = vecWorldTriggerMaxs.y;
    v31 = v28;
    if ( vecWorldTriggerMaxs.y < v31 )
      v30 = v31;
    v32 = v9->z;
    v33 = v30;
    v9->y = v33;
    v34 = vecWorldTriggerMaxs.z;
    v35 = v32;
    if ( vecWorldTriggerMaxs.z < v35 )
      v34 = v35;
    v9->z = v34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEE00
// Name: private: void CCollisionProperty::ComputeRotationExpandedBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeRotationExpandedBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  unsigned __int8 m_Value; // al
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( (this->m_usSolidFlags.m_Value & 0x40) != 0 || (m_Value = this->m_nSolidType.m_Value) == 2 || m_Value == 0 )
  {
    *pVecWorldMins = this->m_vecMins.m_Value;
    *pVecWorldMaxs = this->m_vecMaxs.m_Value;
  }
  else
  {
    v4 = fabs(this->m_vecMins.m_Value.x);
    v5 = fabs(this->m_vecMaxs.m_Value.x);
    if ( v4 <= v5 )
      v4 = v5;
    pVecWorldMins->x = -v4;
    pVecWorldMaxs->x = v4;
    v6 = fabs(this->m_vecMins.m_Value.y);
    v7 = fabs(this->m_vecMaxs.m_Value.y);
    if ( v6 <= v7 )
      v6 = v7;
    pVecWorldMins->y = -v6;
    pVecWorldMaxs->y = v6;
    v8 = fabs(this->m_vecMins.m_Value.z);
    v9 = fabs(this->m_vecMaxs.m_Value.z);
    if ( v8 <= v9 )
      v8 = v9;
    pVecWorldMins->z = -v8;
    pVecWorldMaxs->z = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEED0
// Name: private: void CCollisionProperty::ComputeCollisionSurroundingBox(bool,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeCollisionSurroundingBox(
        CCollisionProperty *this,
        bool bUseVPhysics,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  if ( bUseVPhysics )
    CCollisionProperty::ComputeVPhysicsSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
  else
    this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
}

//------------------------------------------------------------------------------
// Address: 0x100EEF00
// Name: public: bool CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionProperty::DoesVPhysicsInvalidateSurroundingBox(CCollisionProperty *this)
{
  CBaseEntity *m_pOuter; // esi
  bool result; // al

  switch ( this->m_nSurroundType.m_Value )
  {
    case 0u:
      result = false;
      if ( this->GetSolid(this) == SOLID_VPHYSICS )
      {
        m_pOuter = this->m_pOuter;
        if ( m_pOuter->m_MoveType.m_Value == 6 && m_pOuter->m_pPhysicsObject != nullptr )
          result = true;
      }
      break;
    case 2u:
    case 3u:
    case 5u:
    case 6u:
    case 7u:
      result = false;
      break;
    default:
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100EEF70
// Name: private: unsigned int CCollisionProperty::ComputeServerPartitionMask(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionProperty::ComputeServerPartitionMask(CCollisionProperty *this)
{
  CBaseEntity *m_pOuter; // esi
  edict_t *m_pPev; // edx
  int v3; // edi
  unsigned __int16 m_Value; // dx
  char v5; // cl
  int v6; // ecx

  m_pOuter = this->m_pOuter;
  m_pPev = m_pOuter->m_Network.m_pPev;
  v3 = 0;
  if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
  {
    if ( this->m_nSolidType.m_Value != 0 && ((m_Value = this->m_usSolidFlags.m_Value) & 4) == 0
      || ((m_Value = this->m_usSolidFlags.m_Value) & 8) != 0 )
    {
      v5 = 1;
    }
    else
    {
      v5 = 0;
      if ( (m_pOuter->m_iEFlags & 0x40000) == 0 )
        return v3;
    }
    v3 = 16;
    if ( v5 != 0 )
    {
      if ( (m_Value & 4) == 0 )
        v3 = 17;
      if ( (m_Value & 8) != 0 )
        v3 |= 2u;
      v6 = m_pOuter->m_MoveType.m_Value;
      if ( v6 != 7 && m_pOuter->m_MoveType.m_Value != 0 && v6 != 6 && v6 != 8 )
        return v3 | 0x400;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100EF010
// Name: public: void CCollisionProperty::UpdatePartition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::UpdatePartition(CCollisionProperty *this)
{
  CBaseEntity *m_pOuter; // eax
  ISpatialPartition_vtbl *v3; // edi
  int v4; // eax
  unsigned __int16 v5; // ax
  ISpatialPartition *v6; // edi
  ISpatialPartition_vtbl *v7; // ebx
  int v8; // eax
  CBaseEntity *v9; // ebx
  CBaseEntity *v10; // edi
  int v11; // [esp-Ch] [ebp-28h]
  Vector vecSurroundMins; // [esp+4h] [ebp-18h] BYREF
  Vector vecSurroundMaxs; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x8000) != 0 )
  {
    m_pOuter->m_iEFlags &= ~0x8000u;
    if ( this->m_pOuter->m_Network.m_pPev != nullptr )
    {
      if ( this->m_Partition == 0xFFFF )
      {
        v3 = partition->__vftable;
        v4 = this->GetEntityHandle(this);
        v5 = v3->CreateHandle_2(this: partition, a2: (IHandleEntity *)v4);
        this->m_Partition = v5;
        if ( v5 != 0xFFFF )
        {
          v6 = partition;
          v7 = partition->__vftable;
          v11 = v5;
          v8 = CCollisionProperty::ComputeServerPartitionMask(this);
          v7->RemoveAndInsert(this: v6, a2: -1, a3: v8, a4: v11);
        }
      }
      if ( this->m_nSolidType.m_Value != 0 && (this->m_usSolidFlags.m_Value & 4) == 0
        || (this->m_usSolidFlags.m_Value & 8) != 0
        || (this->m_pOuter->m_iEFlags & 0x40000) != 0 )
      {
        if ( this->m_flRadius == 0.0 )
        {
          v9 = this->m_pOuter;
          if ( (v9->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
          v10 = this->m_pOuter;
          if ( (v10->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
          ((void (__stdcall *)(_DWORD, Vector *, Vector *))partition->ElementMoved)(
            a1: this->m_Partition,
            a2: &v10->m_vecAbsOrigin,
            a3: &v9->m_vecAbsOrigin);
        }
        else
        {
          this->WorldSpaceSurroundingBounds(this, a2: &vecSurroundMins, a3: &vecSurroundMaxs);
          vecSurroundMins.x = vecSurroundMins.x - 1.0;
          vecSurroundMins.y = vecSurroundMins.y - 1.0;
          vecSurroundMins.z = vecSurroundMins.z - 1.0;
          vecSurroundMaxs.x = vecSurroundMaxs.x + 1.0;
          vecSurroundMaxs.y = vecSurroundMaxs.y + 1.0;
          vecSurroundMaxs.z = vecSurroundMaxs.z + 1.0;
          ((void (__stdcall *)(_DWORD, Vector *, Vector *))partition->ElementMoved)(
            a1: this->m_Partition,
            a2: &vecSurroundMins,
            a3: &vecSurroundMaxs);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF220
// Name: public: void CDirtySpatialPartitionEntityList::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::AddEntity(
        CDirtySpatialPartitionEntityList *this,
        CBaseEntity *pEntity)
{
  const CBaseHandle *v3; // edi
  TSLNodeBase_t *v4; // eax
  CBaseHandle *v5; // eax

  v3 = pEntity->GetRefEHandle(this: pEntity);
  v4 = CTSListBase::Pop(this: &this->m_DirtyEntities.m_FreeList);
  if ( v4 == nullptr )
  {
    v5 = (CBaseHandle *)operator new(nSize: 8u);
    if ( v5 != nullptr )
    {
      v5[1].m_Index = -1;
      v5[1].m_Index = v3->m_Index;
      CTSListBase::Push(this: &this->m_DirtyEntities, pNode: (TSLNodeBase_t *)v5);
      return;
    }
    v4 = nullptr;
  }
  *((CBaseHandle *)&v4->Next + 1) = (CBaseHandle)v3->m_Index;
  CTSListBase::Push(this: &this->m_DirtyEntities, pNode: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100EF280
// Name: public: virtual void CDirtySpatialPartitionEntityList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::LevelShutdownPostEntity(CDirtySpatialPartitionEntityList *this)
{
  CTSListWithFreeList<CBaseHandle>::RemoveAll(this: &this->m_DirtyEntities);
}

//------------------------------------------------------------------------------
// Address: 0x100EF290
// Name: public: virtual void CCollisionProperty::WorldSpaceTriggerBounds(class Vector __near *,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::WorldSpaceTriggerBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CCollisionProperty::CollisionAABBToWorldAABB(
    this,
    entityMins: &this->m_vecMins.m_Value,
    entityMaxs: &this->m_vecMaxs.m_Value,
    pWorldMins: pVecWorldMins,
    pWorldMaxs: pVecWorldMaxs);
  if ( (this->GetSolidFlags(this) & 0x80u) != 0 )
  {
    pVecWorldMins->x = pVecWorldMins->x - (float)this->m_triggerBloat.m_Value;
    pVecWorldMins->y = pVecWorldMins->y - (float)this->m_triggerBloat.m_Value;
    pVecWorldMaxs->x = (float)this->m_triggerBloat.m_Value + pVecWorldMaxs->x;
    pVecWorldMaxs->y = (float)this->m_triggerBloat.m_Value + pVecWorldMaxs->y;
    pVecWorldMaxs->z = (float)((float)this->m_triggerBloat.m_Value * 0.5) + pVecWorldMaxs->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF340
// Name: private: void CCollisionProperty::ComputeOBBBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeOBBBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CBaseEntity *m_pOuter; // eax
  IPhysicsObject *m_pPhysicsObject; // eax

  if ( this->GetSolid(this) == SOLID_VPHYSICS
    && (m_pOuter = this->m_pOuter)->m_MoveType.m_Value == 6
    && (m_pPhysicsObject = m_pOuter->m_pPhysicsObject) != nullptr
    && m_pPhysicsObject->IsAsleep(this: m_pPhysicsObject) )
  {
    CCollisionProperty::ComputeVPhysicsSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
  }
  else
  {
    this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF3A0
// Name: private: void CCollisionProperty::ComputeRotationExpandedSequenceBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeRotationExpandedSequenceBounds(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CBaseAnimating *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  double x; // xmm2_8
  float v15; // xmm2_4
  double y; // xmm0_8
  float z; // xmm2_4
  float v18; // xmm0_4
  double v19; // xmm0_8
  double v20; // xmm2_8
  float v21; // xmm2_4
  float v22; // xmm0_4
  double v23; // xmm0_8
  double v24; // xmm2_8
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  CBaseEntity *m_pOuter; // esi
  CBaseEntity *v32; // edi
  Vector maxs; // [esp+4h] [ebp-18h] BYREF
  Vector mins; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v4 = this->m_pOuter->GetBaseAnimating(this: this->m_pOuter);
  if ( v4 != nullptr )
  {
    CBaseAnimating::ExtractBbox(this: v4, sequence: v4->m_nSequence.m_Value, &mins, &maxs);
    v5 = fabs(mins.x);
    v6 = fabs(maxs.x);
    if ( v5 <= v6 )
      v7 = v6;
    else
      v7 = v5;
    v8 = fabs(mins.y);
    v9 = fabs(maxs.y);
    if ( v8 <= v9 )
      v10 = v9;
    else
      v10 = v8;
    if ( v7 <= v10 )
    {
      if ( v8 <= v9 )
        v5 = v9;
      else
        v5 = v8;
    }
    else if ( v5 <= v6 )
    {
      v5 = v6;
    }
    v11 = COERCE_FLOAT(LODWORD(v5) ^ _mask__NegFloat_) - 6.0;
    v12 = v5 + 6.0;
    v13 = v5 + 6.0;
    x = v11;
    if ( v11 > (double)this->m_vecSurroundingMins.x )
      x = this->m_vecSurroundingMins.x;
    v15 = x;
    mins.x = v15;
    y = v11;
    if ( y > this->m_vecSurroundingMins.y )
      y = this->m_vecSurroundingMins.y;
    z = this->m_vecSurroundingMins.z;
    v18 = y;
    mins.y = v18;
    v19 = mins.z;
    v20 = z;
    if ( mins.z > v20 )
      v19 = v20;
    v21 = this->m_vecSurroundingMaxs.x;
    v22 = v19;
    mins.z = v22;
    v23 = v12;
    v24 = v21;
    if ( v12 < v24 )
      v23 = v24;
    v25 = v23;
    maxs.x = v25;
    v26 = v13;
    if ( v13 < (double)this->m_vecSurroundingMaxs.y )
      v26 = this->m_vecSurroundingMaxs.y;
    v27 = this->m_vecSurroundingMaxs.z;
    v28 = v26;
    maxs.y = v28;
    v29 = maxs.z;
    v30 = v27;
    if ( maxs.z < v30 )
      v29 = v30;
    m_pOuter = this->m_pOuter;
    maxs.z = v29;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
    pVecWorldMins->x = m_pOuter->m_vecAbsOrigin.x + mins.x;
    pVecWorldMins->y = m_pOuter->m_vecAbsOrigin.y + mins.y;
    pVecWorldMins->z = m_pOuter->m_vecAbsOrigin.z + mins.z;
    v32 = this->m_pOuter;
    if ( (v32->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v32, a2: (int)&savedregs);
    pVecWorldMaxs->x = v32->m_vecAbsOrigin.x + maxs.x;
    pVecWorldMaxs->y = v32->m_vecAbsOrigin.y + maxs.y;
    pVecWorldMaxs->z = v32->m_vecAbsOrigin.z + maxs.z;
  }
  else
  {
    CCollisionProperty::ComputeOBBBounds(this, pVecWorldMins, pVecWorldMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF5F0
// Name: private: void CCollisionProperty::ComputeSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::ComputeSurroundingBox(
        CCollisionProperty *this,
        Vector *pVecWorldMins,
        Vector *pVecWorldMaxs)
{
  CBaseEntity *m_pOuter; // esi
  SolidType_t v5; // eax
  const Vector *AbsOrigin; // eax
  const Vector *v7; // eax
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->GetSolid(this) != SOLID_CUSTOM || this->m_nSurroundType.m_Value == 4 )
  {
    switch ( this->m_nSurroundType.m_Value )
    {
      case 0u:
        CCollisionProperty::ComputeOBBBounds(this, pVecWorldMins, pVecWorldMaxs);
        break;
      case 1u:
        v5 = this->GetSolid(this);
        CCollisionProperty::ComputeCollisionSurroundingBox(
          this,
          bUseVPhysics: v5 == SOLID_VPHYSICS,
          pVecWorldMins,
          pVecWorldMaxs);
        break;
      case 2u:
        CCollisionProperty::ComputeHitboxSurroundingBox(this, pVecWorldMins, pVecWorldMaxs);
        break;
      case 3u:
        AbsOrigin = CAI_Component::GetAbsOrigin((CAI_Component *)this, a2: (int)&savedregs);
        pVecWorldMins->x = this->m_vecSpecifiedSurroundingMins.m_Value.x + AbsOrigin->x;
        pVecWorldMins->y = AbsOrigin->y + this->m_vecSpecifiedSurroundingMins.m_Value.y;
        pVecWorldMins->z = AbsOrigin->z + this->m_vecSpecifiedSurroundingMins.m_Value.z;
        v7 = CAI_Component::GetAbsOrigin((CAI_Component *)this, a2: (int)&savedregs);
        pVecWorldMaxs->x = v7->x + this->m_vecSpecifiedSurroundingMaxs.m_Value.x;
        pVecWorldMaxs->y = v7->y + this->m_vecSpecifiedSurroundingMaxs.m_Value.y;
        pVecWorldMaxs->z = v7->z + this->m_vecSpecifiedSurroundingMaxs.m_Value.z;
        break;
      case 4u:
        this->m_pOuter->ComputeWorldSpaceSurroundingBox(this: this->m_pOuter, a2: pVecWorldMins, a3: pVecWorldMaxs);
        break;
      case 5u:
        CCollisionProperty::ComputeRotationExpandedBounds(this, pVecWorldMins, pVecWorldMaxs);
        break;
      case 6u:
        this->WorldSpaceTriggerBounds(this, a2: pVecWorldMins, a3: pVecWorldMaxs);
        break;
      case 7u:
        CCollisionProperty::ComputeRotationExpandedSequenceBounds(this, pVecWorldMins, pVecWorldMaxs);
        break;
      default:
        return;
    }
  }
  else
  {
    m_pOuter = this->m_pOuter;
    if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
    *pVecWorldMins = m_pOuter->m_vecAbsOrigin;
    *pVecWorldMaxs = *pVecWorldMins;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF790
// Name: public: virtual void CCollisionProperty::WorldSpaceSurroundingBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::WorldSpaceSurroundingBounds(
        CCollisionProperty *this,
        Vector *pVecMins,
        Vector *pVecMaxs)
{
  CBaseEntity *m_pOuter; // edi
  CBaseEntity *v5; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
  v5 = this->m_pOuter;
  if ( (v5->m_iEFlags & 0x4000) != 0 )
  {
    v5->m_iEFlags &= ~0x4000u;
    CCollisionProperty::ComputeSurroundingBox(this, pVecWorldMins: pVecMins, pVecWorldMaxs: pVecMaxs);
    this->m_vecSurroundingMins.x = pVecMins->x - m_pOuter->m_vecAbsOrigin.x;
    this->m_vecSurroundingMins.y = pVecMins->y - m_pOuter->m_vecAbsOrigin.y;
    this->m_vecSurroundingMins.z = pVecMins->z - m_pOuter->m_vecAbsOrigin.z;
    this->m_vecSurroundingMaxs.x = pVecMaxs->x - m_pOuter->m_vecAbsOrigin.x;
    this->m_vecSurroundingMaxs.y = pVecMaxs->y - m_pOuter->m_vecAbsOrigin.y;
    this->m_vecSurroundingMaxs.z = pVecMaxs->z - m_pOuter->m_vecAbsOrigin.z;
  }
  else
  {
    pVecMins->x = m_pOuter->m_vecAbsOrigin.x + this->m_vecSurroundingMins.x;
    pVecMins->y = this->m_vecSurroundingMins.y + m_pOuter->m_vecAbsOrigin.y;
    pVecMins->z = this->m_vecSurroundingMins.z + m_pOuter->m_vecAbsOrigin.z;
    pVecMaxs->x = this->m_vecSurroundingMaxs.x + m_pOuter->m_vecAbsOrigin.x;
    pVecMaxs->y = this->m_vecSurroundingMaxs.y + m_pOuter->m_vecAbsOrigin.y;
    pVecMaxs->z = this->m_vecSurroundingMaxs.z + m_pOuter->m_vecAbsOrigin.z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF8D0
// Name: public: void CCollisionProperty::MarkPartitionHandleDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::MarkPartitionHandleDirty(CCollisionProperty *this)
{
  CBaseEntity *m_pOuter; // eax

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x8000) == 0 )
  {
    CDirtySpatialPartitionEntityList::AddEntity(this: &s_DirtyKDTree, pEntity: m_pOuter);
    this->m_pOuter->m_iEFlags |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF960
// Name: public: CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDirtySpatialPartitionEntityList *__thiscall CDirtySpatialPartitionEntityList::CDirtySpatialPartitionEntityList(
        CDirtySpatialPartitionEntityList *this,
        const char *name)
{
  CTSListBase *p_m_FreeList; // eax
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *Next; // ebx
  TSLNodeBase_t *v6; // eax
  TSLNodeBase_t *v7; // ebx
  const char *v9; // [esp+0h] [ebp-8h]

  CAutoGameSystem::CAutoGameSystem(this, name);
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&IPartitionQueryCallback::`vftable';
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CDirtySpatialPartitionEntityList_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `CAutoGameSystem'};
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `IPartitionQueryCallback'};
  if ( (((_BYTE)this + 16) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10458314, a2: v9);
    __debugbreak();
  }
  p_m_FreeList = &this->m_DirtyEntities.m_FreeList;
  this->m_DirtyEntities.m_Head.value.Next = nullptr;
  this->m_DirtyEntities.m_Head.value32.DepthAndSequence = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_10458314, a2: v9);
    __debugbreak();
    p_m_FreeList = &this->m_DirtyEntities.m_FreeList;
  }
  p_m_FreeList->m_Head.value.Next = nullptr;
  p_m_FreeList->m_Head.value32.DepthAndSequence = 0;
  CThreadSpinRWLock::CThreadSpinRWLock(this: &this->m_partitionMutex);
  v4 = CTSListBase::Detach(this: &this->m_DirtyEntities);
  if ( v4 != nullptr )
  {
    do
    {
      Next = v4->Next;
      free(pMem: v4);
      v4 = Next;
    }
    while ( Next != nullptr );
  }
  v6 = CTSListBase::Detach(this: &this->m_DirtyEntities.m_FreeList);
  if ( v6 != nullptr )
  {
    do
    {
      v7 = v6->Next;
      free(pMem: v6);
      v6 = v7;
    }
    while ( v7 != nullptr );
  }
  memset(dst: (int)this->m_nReadLockCount, value: nullptr, count: sizeof(this->m_nReadLockCount));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EFA30
// Name: public: virtual CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(
        CDirtySpatialPartitionEntityList *this)
{
  TSLNodeBase_t *v2; // eax
  TSLNodeBase_t *Next; // esi
  TSLNodeBase_t *v4; // eax
  TSLNodeBase_t *v5; // esi

  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CDirtySpatialPartitionEntityList_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `CAutoGameSystem'};
  this->IPartitionQueryCallback::__vftable = (IPartitionQueryCallback_vtbl *)&CDirtySpatialPartitionEntityList::`vftable'{for `IPartitionQueryCallback'};
  v2 = CTSListBase::Detach(this: &this->m_DirtyEntities);
  if ( v2 != nullptr )
  {
    do
    {
      Next = v2->Next;
      free(pMem: v2);
      v2 = Next;
    }
    while ( Next != nullptr );
  }
  v4 = CTSListBase::Detach(this: &this->m_DirtyEntities.m_FreeList);
  if ( v4 != nullptr )
  {
    do
    {
      v5 = v4->Next;
      free(pMem: v4);
      v4 = v5;
    }
    while ( v5 != nullptr );
  }
  CTSListWithFreeList<CNavArea::AreaBindInfo>::~CTSListWithFreeList<CNavArea::AreaBindInfo>(this: &this->m_DirtyEntities);
  IGameSystem::~IGameSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EFAA0
// Name: public: void CCollisionProperty::Init(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::Init(CCollisionProperty *this, CBaseEntity *pEntity)
{
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *p_m_vecMins; // edi
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMins> *p_m_vecSpecifiedSurroundingMins; // edi
  void (__thiscall *NetworkStateChanged)(CCollisionProperty *, void *); // eax
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMaxs> *p_m_vecSpecifiedSurroundingMaxs; // esi

  p_m_vecMins = &this->m_vecMins;
  this->m_pOuter = pEntity;
  this->NetworkStateChanged(this, a2: &this->m_vecMins);
  p_m_vecMins->m_Value.x = 0.0;
  p_m_vecMins->m_Value.y = 0.0;
  p_m_vecMins->m_Value.z = 0.0;
  this->NetworkStateChanged(this, a2: &this->m_vecMaxs);
  this->m_vecMaxs.m_Value.x = 0.0;
  this->m_vecMaxs.m_Value.y = 0.0;
  this->m_vecMaxs.m_Value.z = 0.0;
  this->m_flRadius = 0.0;
  if ( this->m_triggerBloat.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_triggerBloat);
    this->m_triggerBloat.m_Value = 0;
  }
  if ( this->m_usSolidFlags.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_usSolidFlags);
    this->m_usSolidFlags.m_Value = 0;
  }
  if ( this->m_nSolidType.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSolidType);
    this->m_nSolidType.m_Value = 0;
  }
  if ( this->m_nSurroundType.m_Value != 0 )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSurroundType);
    this->m_nSurroundType.m_Value = 0;
  }
  this->m_vecSurroundingMins = vec3_origin;
  p_m_vecSpecifiedSurroundingMins = &this->m_vecSpecifiedSurroundingMins;
  NetworkStateChanged = this->NetworkStateChanged;
  this->m_vecSurroundingMaxs = vec3_origin;
  NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMins);
  p_m_vecSpecifiedSurroundingMaxs = &this->m_vecSpecifiedSurroundingMaxs;
  p_m_vecSpecifiedSurroundingMins->m_Value.x = 0.0;
  p_m_vecSpecifiedSurroundingMins->m_Value.y = 0.0;
  p_m_vecSpecifiedSurroundingMins->m_Value.z = 0.0;
  (*(void (__stdcall **)(CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecSpecifiedSurroundingMaxs> *))(LODWORD(p_m_vecSpecifiedSurroundingMaxs[-5].m_Value.y) + 76))(a1: p_m_vecSpecifiedSurroundingMaxs);
  p_m_vecSpecifiedSurroundingMaxs->m_Value.x = 0.0;
  p_m_vecSpecifiedSurroundingMaxs->m_Value.y = 0.0;
  p_m_vecSpecifiedSurroundingMaxs->m_Value.z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100EFBF0
// Name: public: void CCollisionProperty::MarkSurroundingBoundsDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::MarkSurroundingBoundsDirty(CCollisionProperty *this)
{
  CBaseEntity *m_pOuter; // ecx
  edict_t *m_pPev; // eax
  CBaseEntity *v4; // esi

  m_pOuter = this->m_pOuter;
  m_pPev = m_pOuter->m_Network.m_pPev;
  if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
  {
    m_pOuter->m_iEFlags |= 0x4000u;
    if ( (this->m_pOuter->m_iEFlags & 0x8000) == 0 )
    {
      CDirtySpatialPartitionEntityList::AddEntity(this: &s_DirtyKDTree, pEntity: this->m_pOuter);
      this->m_pOuter->m_iEFlags |= 0x8000u;
    }
    v4 = this->m_pOuter;
    if ( v4->m_Network.m_pPev != nullptr )
      v4->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFC90
// Name: public: virtual void CDirtySpatialPartitionEntityList::OnPreQuery(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDirtySpatialPartitionEntityList::OnPreQuery(CDirtySpatialPartitionEntityList *this, char listMask)
{
  CDirtySpatialPartitionEntityList *v2; // edi
  char *v3; // ecx
  char *DepthAndSequence; // eax
  int v5; // eax
  CTSListWithFreeList<CBaseHandle>::Node_t *v6; // esi
  TSLNodeBase_t **v7; // edi
  CEntInfo *v8; // eax
  int v9; // eax
  int m_Size; // eax
  int v11; // ebx
  CBaseHandle *m_pMemory; // ecx
  int v13; // eax
  CBaseHandle *v14; // ebx
  TSLNodeBase_t *v15; // eax
  TSLNodeBase_t *v16; // [esp-10h] [ebp-30h]
  TSLNodeBase_t *v17; // [esp-10h] [ebp-30h]
  TSLNodeBase_t *v18; // [esp-Ch] [ebp-2Ch]
  TSLNodeBase_t *v19; // [esp-Ch] [ebp-2Ch]
  CUtlVector<CBaseHandle,CUtlMemory<CBaseHandle,int> > vecStillDirty; // [esp+4h] [ebp-1Ch] BYREF
  CDirtySpatialPartitionEntityList *v21; // [esp+18h] [ebp-8h]
  CTSListWithFreeList<CBaseHandle>::Node_t *pNext; // [esp+1Ch] [ebp-4h]
  CBaseHandle handle; // [esp+28h] [ebp+8h]
  CBaseHandle handlea; // [esp+28h] [ebp+8h]

  v2 = this;
  v21 = this;
  if ( (listMask & 0x13) != 0 )
  {
    v3 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: (GenericThreadLocals::CThreadLocalBase *)g_nThreadID.m_index);
    DepthAndSequence = (char *)v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence;
    handle.m_Index = (unsigned int)v3;
    if ( DepthAndSequence == nullptr || DepthAndSequence != v3 + 1 )
    {
      if ( LOWORD(v2->m_pszName) != 0 && *(&v2->m_partitionMutex.m_lockInfo.m_i32 + (_DWORD)v3) == 0 )
      {
        v5 = v2->m_DirtyEntities.m_Head.value32.DepthAndSequence;
        memset(&vecStillDirty, 0, sizeof(vecStillDirty));
        if ( (v5 & 0x10000) != 0
          || _InterlockedCompareExchange(&v2->m_DirtyEntities.m_Head.value32.DepthAndSequence, 0x10000, 0) != 0 )
        {
          CThreadSpinRWLock::SpinLockForWrite(this: (CThreadSpinRWLock *)((char *)&v2->m_DirtyEntities.m_Head.value64 + 4));
        }
        else
        {
          v2->m_DirtyEntities.m_FreeList.m_Head.value.Next = (TSLNodeBase_t *)GetCurrentThreadId();
        }
        v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence = handle.m_Index + 1;
        v6 = (CTSListWithFreeList<CBaseHandle>::Node_t *)CTSListBase::Detach(this: (CTSListBase *)&v2->m_pNext);
        if ( v6 != nullptr )
        {
          do
          {
            v7 = (TSLNodeBase_t **)&v2->IPartitionQueryCallback;
            do
            {
              handlea.m_Index = *((_DWORD *)&v6->Next + 1);
              v18 = v7[1];
              v16 = *v7;
              pNext = (CTSListWithFreeList<CBaseHandle>::Node_t *)v6->Next;
              v6->Next = v16;
              if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                      a1: v7,
                                      a2: v6,
                                      a3: (char *)&v18[0x2000].Next + 1,
                                      a4: v16,
                                      a5: v18) == 0 )
              {
                do
                {
                  _mm_pause();
                  v19 = v7[1];
                  v17 = *v7;
                  v6->Next = *v7;
                }
                while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                           a1: v7,
                                           a2: v6,
                                           a3: (char *)&v19[0x2000].Next + 1,
                                           a4: v17,
                                           a5: v19) == 0 );
              }
              v6 = pNext;
              if ( handlea.m_Index != -1 )
              {
                v8 = &gEntList.m_EntPtrArray[LOWORD(handlea.m_Index)];
                if ( v8->m_SerialNumber == HIWORD(handlea.m_Index) && v8->m_pEntity != nullptr )
                {
                  v9 = (int)v8->m_pEntity->__vftable[1].GetRefEHandle(this: v8->m_pEntity);
                  if ( v9 != 0 )
                  {
                    if ( (*(_DWORD *)(v9 + 196) & 8) != 0 )
                    {
                      m_Size = vecStillDirty.m_Size;
                      v11 = vecStillDirty.m_Size;
                      if ( vecStillDirty.m_Size + 1 > vecStillDirty.m_Memory.m_nAllocationCount )
                      {
                        CUtlMemory<CNavLadder *,int>::Grow(
                          this: (CUtlMemory<vgui::TreeNode *,int> *)&vecStillDirty,
                          num: vecStillDirty.m_Size - vecStillDirty.m_Memory.m_nAllocationCount + 1);
                        m_Size = vecStillDirty.m_Size;
                      }
                      m_pMemory = vecStillDirty.m_Memory.m_pMemory;
                      vecStillDirty.m_Size = m_Size + 1;
                      v13 = m_Size - v11;
                      vecStillDirty.m_pElements = vecStillDirty.m_Memory.m_pMemory;
                      if ( v13 > 0 )
                      {
                        _V_memmove(
                          dest: (void *)&vecStillDirty.m_Memory.m_pMemory[v11 + 1],
                          src: &vecStillDirty.m_Memory.m_pMemory[v11],
                          count: 4 * v13);
                        m_pMemory = vecStillDirty.m_Memory.m_pMemory;
                      }
                      v14 = &m_pMemory[v11];
                      if ( v14 != nullptr )
                        v14->m_Index = handlea.m_Index;
                    }
                    else
                    {
                      CCollisionProperty::UpdatePartition(this: (CCollisionProperty *)(v9 + 228));
                    }
                  }
                }
              }
            }
            while ( pNext != nullptr );
            v2 = v21;
            v6 = (CTSListWithFreeList<CBaseHandle>::Node_t *)CTSListBase::Detach(this: (CTSListBase *)&v21->m_pNext);
          }
          while ( v6 != nullptr );
          if ( vecStillDirty.m_Size > 0 )
          {
            do
            {
              v15 = CTSListBase::Pop(this: (CTSListBase *)&v2->IPartitionQueryCallback);
              if ( v15 == nullptr )
              {
                v15 = (TSLNodeBase_t *)operator new(nSize: 8u);
                if ( v15 != nullptr )
                  *((_DWORD *)&v15->Next + 1) = -1;
                else
                  v15 = nullptr;
              }
              *((_DWORD *)&v15->Next + 1) = vecStillDirty.m_Memory.m_pMemory[(_DWORD)v6].m_Index;
              CTSListBase::Push(this: (CTSListBase *)&v2->m_pNext, pNode: v15);
              v6 = (CTSListWithFreeList<CBaseHandle>::Node_t *)((char *)v6 + 1);
            }
            while ( (int)v6 < vecStillDirty.m_Size );
          }
        }
        v2->m_DirtyEntities.m_FreeList.m_Head.value32.DepthAndSequence = 0;
        v2->m_DirtyEntities.m_FreeList.m_Head.value.Next = nullptr;
        v2->m_DirtyEntities.m_Head.value32.DepthAndSequence = 0;
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vecStillDirty);
      }
      CDirtySpatialPartitionEntityList::LockPartitionForRead(this: (CDirtySpatialPartitionEntityList *)((char *)v2 - 12));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFEE0
// Name: public: CCollisionProperty::CCollisionProperty(void)
// Source: json
//------------------------------------------------------------------------------
CCollisionProperty *__thiscall CCollisionProperty::CCollisionProperty(CCollisionProperty *this)
{
  this->__vftable = (CCollisionProperty_vtbl *)&CCollisionProperty::`vftable';
  this->m_Partition = -1;
  CCollisionProperty::Init(this, pEntity: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EFF00
// Name: public: void CCollisionProperty::SetSolidFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSolidFlags(CCollisionProperty *this, unsigned __int16 flags)
{
  CNetworkVarBase<unsigned short,CCollisionProperty::NetworkVar_m_usSolidFlags> *p_m_usSolidFlags; // esi
  int m_Value; // edi
  int v5; // eax
  int v6; // edi
  ISpatialPartition_vtbl *v7; // edi
  int v8; // eax
  int m_Partition; // [esp-4h] [ebp-10h]

  p_m_usSolidFlags = &this->m_usSolidFlags;
  m_Value = this->m_usSolidFlags.m_Value;
  if ( this->m_usSolidFlags.m_Value != flags )
  {
    this->NetworkStateChanged(this, a2: &this->m_usSolidFlags);
    p_m_usSolidFlags->m_Value = flags;
  }
  v5 = p_m_usSolidFlags->m_Value;
  if ( m_Value != v5 )
  {
    if ( (((unsigned __int8)m_Value ^ (unsigned __int8)v5) & 0xC0) != 0 )
      CCollisionProperty::MarkSurroundingBoundsDirty(this);
    v6 = m_Value & 0xC;
    if ( v6 != (p_m_usSolidFlags->m_Value & 0xC) )
      CBaseEntity::CollisionRulesChanged(this: this->m_pOuter);
    if ( v6 != (p_m_usSolidFlags->m_Value & 0xC) )
    {
      if ( this->m_Partition != 0xFFFF )
      {
        v7 = partition->__vftable;
        m_Partition = this->m_Partition;
        v8 = CCollisionProperty::ComputeServerPartitionMask(this);
        v7->RemoveAndInsert(this: partition, a2: -1, a3: v8, a4: m_Partition);
      }
      if ( (this->m_nSolidType.m_Value == 0 || (p_m_usSolidFlags->m_Value & 4) != 0)
        && (p_m_usSolidFlags->m_Value & 8) == 0
        && CBaseEntity::IsCurrentlyTouching(this: this->m_pOuter) )
      {
        CBaseEntity::SetCheckUntouch(this: this->m_pOuter, check: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EFFC0
// Name: public: void CCollisionProperty::SetCollisionBounds(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetCollisionBounds(
        CCollisionProperty *this,
        const Vector *mins,
        const Vector *maxs)
{
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMins> *p_m_vecMins; // esi
  const Vector *v4; // edx
  CNetworkVectorBase<Vector,CCollisionProperty::NetworkVar_m_vecMaxs> *p_m_vecMaxs; // esi
  CCollisionProperty *v6; // [esp-4h] [ebp-10h]

  p_m_vecMins = &this->m_vecMins;
  v6 = this;
  if ( mins->x == this->m_vecMins.m_Value.x
    && mins->y == this->m_vecMins.m_Value.y
    && mins->z == this->m_vecMins.m_Value.z )
  {
    v4 = maxs;
    if ( maxs->x == this->m_vecMaxs.m_Value.x
      && maxs->y == this->m_vecMaxs.m_Value.y
      && maxs->z == this->m_vecMaxs.m_Value.z )
    {
      return;
    }
  }
  else
  {
    v4 = maxs;
  }
  if ( mins->x != p_m_vecMins->m_Value.x || mins->y != this->m_vecMins.m_Value.y || mins->z != this->m_vecMins.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->m_vecMins);
    this = v6;
    p_m_vecMins->m_Value = *mins;
    v4 = maxs;
  }
  p_m_vecMaxs = &this->m_vecMaxs;
  if ( v4->x != this->m_vecMaxs.m_Value.x || v4->y != this->m_vecMaxs.m_Value.y || v4->z != this->m_vecMaxs.m_Value.z )
  {
    this->NetworkStateChanged(this, a2: &this->m_vecMaxs);
    this = v6;
    p_m_vecMaxs->m_Value = *maxs;
    v4 = maxs;
  }
  this->m_flRadius = fsqrt(
                       (float)((float)((float)(v4->y - mins->y) * (float)(v4->y - mins->y))
                             + (float)((float)(v4->z - mins->z) * (float)(v4->z - mins->z)))
                     + (float)((float)(v4->x - mins->x) * (float)(v4->x - mins->x)))
                   * 0.5;
  CCollisionProperty::MarkSurroundingBoundsDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F0170
// Name: public: void CCollisionProperty::SetSurroundingBoundsType(enum SurroundingBoundsType_t,class Vector const __near *,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSurroundingBoundsType(
        CCollisionProperty *this,
        SurroundingBoundsType_t type,
        const Vector *pMins,
        const Vector *pMaxs)
{
  CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_nSurroundType> *p_m_nSurroundType; // esi

  p_m_nSurroundType = &this->m_nSurroundType;
  if ( this->m_nSurroundType.m_Value != (_BYTE)type )
  {
    this->NetworkStateChanged(this, a2: &this->m_nSurroundType);
    p_m_nSurroundType->m_Value = type;
  }
  if ( type == USE_SPECIFIED_BOUNDS )
  {
    if ( pMins->x != this->m_vecSpecifiedSurroundingMins.m_Value.x
      || pMins->y != this->m_vecSpecifiedSurroundingMins.m_Value.y
      || pMins->z != this->m_vecSpecifiedSurroundingMins.m_Value.z )
    {
      this->NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMins);
      this->m_vecSpecifiedSurroundingMins.m_Value = *pMins;
    }
    if ( pMaxs->x != this->m_vecSpecifiedSurroundingMaxs.m_Value.x
      || pMaxs->y != this->m_vecSpecifiedSurroundingMaxs.m_Value.y
      || pMaxs->z != this->m_vecSpecifiedSurroundingMaxs.m_Value.z )
    {
      this->NetworkStateChanged(this, a2: &this->m_vecSpecifiedSurroundingMaxs);
      this->m_vecSpecifiedSurroundingMaxs.m_Value = *pMaxs;
    }
    this->m_vecSurroundingMins = *pMins;
    this->m_vecSurroundingMaxs = *pMaxs;
  }
  else
  {
    CCollisionProperty::MarkSurroundingBoundsDirty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F02F0
// Name: public: void CCollisionProperty::SetSolid(enum SolidType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::SetSolid(CCollisionProperty *this, SolidType_t val)
{
  SolidType_t v2; // ebx
  unsigned __int8 m_Value; // al
  CBaseEntity *m_pOuter; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *RootMoveParent; // eax
  CBaseEntity *v8; // edx
  unsigned int v9; // eax
  int i; // esi
  ISpatialPartition *v11; // esi
  ISpatialPartition_vtbl *v12; // ebx
  int v13; // eax
  unsigned __int8 v14; // cl
  char v15; // al
  int m_Partition; // [esp-8h] [ebp-24h]
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+8h] [ebp-14h] BYREF
  char bWasNotSolid_3; // [esp+27h] [ebp+Bh]

  v2 = val;
  m_Value = this->m_nSolidType.m_Value;
  if ( m_Value != val )
  {
    if ( m_Value == 0 || (bWasNotSolid_3 = 1, (this->m_usSolidFlags.m_Value & 4) != 0) )
      bWasNotSolid_3 = 0;
    CCollisionProperty::MarkSurroundingBoundsDirty(this);
    if ( v2 == SOLID_BSP )
    {
      m_pOuter = this->m_pOuter;
      m_Index = m_pOuter->m_hMoveParent.m_Value.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        RootMoveParent = CBaseEntity::GetRootMoveParent(this: m_pOuter);
        if ( RootMoveParent->m_Collision.GetSolid(this: &RootMoveParent->m_Collision) != SOLID_BSP )
          LOBYTE(v2) = 6;
      }
      v8 = this->m_pOuter;
      v9 = v8->m_hMoveParent.m_Value.m_Index;
      if ( v9 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity == nullptr )
      {
        memset(&list, 0, sizeof(list));
        GetAllChildren(pParent: v8, &list);
        for ( i = list.m_Size - 1; i >= 0; --i )
          CCollisionProperty::SetSolidFlags(
            this: &list.m_Memory.m_pMemory[i]->m_Collision,
            flags: list.m_Memory.m_pMemory[i]->m_Collision.m_usSolidFlags.m_Value | 0x100);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
      }
    }
    if ( this->m_nSolidType.m_Value != (_BYTE)v2 )
    {
      this->NetworkStateChanged(this, a2: &this->m_nSolidType);
      this->m_nSolidType.m_Value = v2;
    }
    CBaseEntity::CollisionRulesChanged(this: this->m_pOuter);
    if ( this->m_Partition != 0xFFFF )
    {
      v11 = partition;
      v12 = partition->__vftable;
      m_Partition = this->m_Partition;
      v13 = CCollisionProperty::ComputeServerPartitionMask(this);
      v12->RemoveAndInsert(this: v11, a2: -1, a3: v13, a4: m_Partition);
    }
    v14 = this->m_nSolidType.m_Value;
    v15 = v14 != 0 && (this->m_usSolidFlags.m_Value & 4) == 0;
    if ( bWasNotSolid_3 != v15
      && (v14 == 0 || (this->m_usSolidFlags.m_Value & 4) != 0)
      && (this->m_usSolidFlags.m_Value & 8) == 0
      && CBaseEntity::IsCurrentlyTouching(this: this->m_pOuter) )
    {
      CBaseEntity::SetCheckUntouch(this: this->m_pOuter, check: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0490
// Name: public: void CCollisionProperty::UseTriggerBounds(bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionProperty::UseTriggerBounds(CCollisionProperty *this, bool bEnable, float flBloat)
{
  CNetworkVarBase<unsigned char,CCollisionProperty::NetworkVar_m_triggerBloat> *p_m_triggerBloat; // esi

  p_m_triggerBloat = &this->m_triggerBloat;
  if ( this->m_triggerBloat.m_Value != (unsigned __int8)(int)flBloat )
  {
    this->NetworkStateChanged(this, a2: &this->m_triggerBloat);
    p_m_triggerBloat->m_Value = (int)flBloat;
  }
  if ( bEnable )
    CCollisionProperty::SetSolidFlags(this, flags: this->m_usSolidFlags.m_Value | 0x80);
  else
    CCollisionProperty::SetSolidFlags(this, flags: this->m_usSolidFlags.m_Value & 0xFF7F);
}

//------------------------------------------------------------------------------
// Address: 0x1015D390
// Name: public: virtual class IHandleEntity __near * CCollisionProperty::GetEntityHandle(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCollisionProperty::GetEntityHandle(vgui::Tooltip *this)
{
  return this->m_Text.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10401320
// Name: CCollisionProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCollisionProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCollisionProperty>(__formal: nullptr);
  CCollisionProperty_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401330
// Name: DT_CollisionProperty::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CollisionProperty::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CollisionProperty::g_SendTable);
  return atexit(func: DT_CollisionProperty::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401350
// Name: DT_CollisionProperty::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CollisionProperty::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CollisionProperty::ignored>();
  DT_CollisionProperty::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A450
// Name: DT_CollisionProperty::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CollisionProperty::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CollisionProperty::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100F0270
// Name: struct datamap_t __near * DataMapInit<class CCollisionProperty>(class CCollisionProperty __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCollisionProperty>()
{
  if ( (_S2_63 & 1) == 0 )
  {
    _S2_63 |= 1u;
    nameHolder_117.m_pszBase = "CCollisionProperty";
    nameHolder_117.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_117.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_117.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_117.m_Names.m_Size = 0;
    nameHolder_117.m_Names.m_pElements = nullptr;
    nameHolder_117.m_nLenBase = 18;
    atexit(func: DataMapInit_CCollisionProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCollisionProperty::m_DataMap.baseMap = nullptr;
  CCollisionProperty::m_DataMap.dataNumFields = 11;
  CCollisionProperty::m_DataMap.dataDesc = &dataDesc_114[1];
  return &CCollisionProperty::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041A460
// Name: _ServerClassInit_DT_CollisionProperty::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CollisionProperty::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_34;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A480
// Name: _dynamic_atexit_destructor_for__s_DirtyKDTree__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DirtyKDTree__()
{
  CDirtySpatialPartitionEntityList::~CDirtySpatialPartitionEntityList(this: &s_DirtyKDTree);
}

//------------------------------------------------------------------------------
// Address: 0x1041A490
// Name: _DataMapInit_CCollisionProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCollisionProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_117);
}

} // namespace server
