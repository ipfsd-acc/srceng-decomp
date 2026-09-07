// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physconstraint.cpp
// Functions: 78
// ============================================================

#include "game\server\physconstraint.h"

//------------------------------------------------------------------------------
// Address: 0x10180E90
// Name: public: void constraint_ragdollparams_t::Defaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall constraint_ragdollparams_t::Defaults(constraint_ragdollparams_t *this)
{
  this->constraint.isActive = true;
  this->isActive = true;
  this->constraint.forceLimit = 0.0;
  this->constraint.torqueLimit = 0.0;
  this->constraint.strength = 1.0;
  this->constraint.bodyMassScale[0] = 1.0;
  this->constraint.bodyMassScale[1] = 1.0;
  SetIdentityMatrix(matrix: &this->constraintToReference);
  SetIdentityMatrix(matrix: &this->constraintToAttached);
  this->parentIndex = -1;
  this->childIndex = -1;
  this->axes[0].minRotation = 0.0;
  this->axes[0].maxRotation = 0.0;
  this->axes[0].angularVelocity = 0.0;
  this->axes[0].torque = 0.0;
  this->axes[1].minRotation = 0.0;
  this->axes[1].maxRotation = 0.0;
  this->axes[1].angularVelocity = 0.0;
  this->axes[1].torque = 0.0;
  this->axes[2].minRotation = 0.0;
  this->axes[2].maxRotation = 0.0;
  this->axes[2].angularVelocity = 0.0;
  this->axes[2].torque = 0.0;
  this->onlyAngularLimits = false;
  this->useClockwiseRotations = false;
}

//------------------------------------------------------------------------------
// Address: 0x10180F60
// Name: public: virtual struct datamap_t __near * CConstraintAnchor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CConstraintAnchor::GetDataDescMap(CConstraintAnchor *this)
{
  return &CConstraintAnchor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180F70
// Name: public: virtual struct datamap_t __near * CPhysConstraintSystem::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysConstraintSystem::GetDataDescMap(CPhysConstraintSystem *this)
{
  return &CPhysConstraintSystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10180F80
// Name: public: virtual void CPhysConstraintSystem::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraintSystem::Spawn(CPhysConstraintSystem *this)
{
  constraint_groupparams_t group; // [esp+0h] [ebp-Ch] BYREF

  group.additionalIterations = this->m_additionalIterations;
  group.minErrorTicks = 15;
  group.errorTolerance = 3.0;
  this->m_pMachine = physenv->CreateConstraintGroup(this: physenv, a2: &group);
}

//------------------------------------------------------------------------------
// Address: 0x10180FE0
// Name: public: virtual struct datamap_t __near * CPhysConstraint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysConstraint::GetDataDescMap(CPhysConstraint *this)
{
  return &CPhysConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10181000
// Name: bool GetConstraintAttachments(class CBaseEntity __near *,class CBaseEntity __near * __near * const,class IPhysicsObject __near * __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetConstraintAttachments(CBaseEntity *pEntity, CBaseEntity **pAttachOut, IPhysicsObject **pAttachVPhysics)
{
  _DWORD *v3; // eax
  int v4; // esi
  IPhysicsObject *v5; // eax
  CBaseEntity *v6; // eax
  IPhysicsObject *v7; // eax

  v3 = __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPhysConstraint `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 == nullptr )
    return 0;
  v4 = v3[213];
  if ( v4 == 0 )
    return 0;
  v5 = (IPhysicsObject *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 20))(a1: v4);
  *pAttachVPhysics = v5;
  if ( v5 != nullptr )
    v6 = (CBaseEntity *)v5->GetGameData(this: v5);
  else
    v6 = nullptr;
  *pAttachOut = v6;
  v7 = (IPhysicsObject *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 24))(a1: v4);
  pAttachVPhysics[1] = v7;
  if ( v7 != nullptr )
  {
    pAttachOut[1] = (CBaseEntity *)v7->GetGameData(this: v7);
    return 1;
  }
  else
  {
    pAttachOut[1] = nullptr;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181090
// Name: void DebugConstraint(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugConstraint(CBaseEntity *pEntity)
{
  _DWORD *v1; // eax
  int v2; // ecx

  v1 = __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CPhysConstraint `RTTI Type Descriptor',
         isReference: 0);
  if ( v1 != nullptr )
  {
    v2 = v1[213];
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 48))(a1: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101810D0
// Name: public: virtual struct datamap_t __near * CPhysHinge::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysHinge::GetDataDescMap(CPhysHinge *this)
{
  return &CPhysHinge::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101810E0
// Name: public: virtual struct datamap_t __near * CPhysSlideConstraint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysSlideConstraint::GetDataDescMap(CPhysSlideConstraint *this)
{
  return &CPhysSlideConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101810F0
// Name: public: virtual struct datamap_t __near * CPhysPulley::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysPulley::GetDataDescMap(CPhysPulley *this)
{
  return &CPhysPulley::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10181100
// Name: public: virtual struct datamap_t __near * CPhysLength::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysLength::GetDataDescMap(CPhysLength *this)
{
  return &CPhysLength::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10181110
// Name: public: virtual struct datamap_t __near * CRagdollConstraint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollConstraint::GetDataDescMap(CRagdollConstraint *this)
{
  return &CRagdollConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10181120
// Name: public: void constraint_slidingparams_t::InitWithCurrentObjectState(class IPhysicsObject __near *,class IPhysicsObject __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall constraint_slidingparams_t::InitWithCurrentObjectState(
        constraint_slidingparams_t *this,
        IPhysicsObject *pRef,
        IPhysicsObject *pAttached,
        const Vector *slideDirWorldspace)
{
  matrix3x4_t tmp; // [esp+8h] [ebp-C0h] BYREF
  matrix3x4_t in; // [esp+38h] [ebp-90h] BYREF
  matrix3x4_t out; // [esp+68h] [ebp-60h] BYREF
  matrix3x4_t in2; // [esp+98h] [ebp-30h] BYREF

  pRef->GetPositionMatrix(this: pRef, a2: &in);
  MatrixInvert(&in, &out);
  pAttached->GetPositionMatrix(this: pAttached, a2: &in2);
  ConcatTransforms(in1: &out, &in2, out: &this->attachedRefXform);
  pRef->GetPositionMatrix(this: pRef, a2: &tmp);
  VectorIRotate(in1: &slideDirWorldspace->x, in2: &tmp, out: &this->slideAxisRef.x);
}

//------------------------------------------------------------------------------
// Address: 0x101811B0
// Name: public: virtual void CPhysConstraint::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::Deactivate(CPhysConstraint *this)
{
  IPhysicsObject *v2; // edi
  unsigned __int16 v3; // ax
  IPhysicsObject *v4; // eax
  IPhysicsObject *v5; // edi
  unsigned __int16 v6; // ax
  IPhysicsObject *v7; // edi
  IPhysicsObject *v8; // eax

  if ( this->m_pConstraint != nullptr )
  {
    this->m_pConstraint->Deactivate(this: this->m_pConstraint);
    v2 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
    if ( v2 != nullptr )
    {
      v3 = v2->GetGameFlags(this: v2);
      v2->SetGameFlags(this: v2, a2: v3 & 0xFFFD);
    }
    v4 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4->GetGameFlags(this: v4);
      v5->SetGameFlags(this: v5, a2: v6 & 0xFFFD);
    }
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      v7 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
      v8 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
      if ( v7 != nullptr && v8 != nullptr )
        PhysEnableEntityCollisions(pObject0: v7, pObject1: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181270
// Name: DrawPhysicsBounds
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawPhysicsBounds(IPhysicsObject *pObject@<esi>, int r, int g, int b, int a)
{
  const struct CPhysCollide *v5; // edi
  Vector pos; // [esp+24h] [ebp-30h] BYREF
  QAngle angles; // [esp+30h] [ebp-24h] BYREF
  Vector mins; // [esp+3Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+48h] [ebp-Ch] BYREF

  v5 = pObject->GetCollide(this: pObject);
  pObject->GetPosition(this: pObject, a2: &pos, a3: &angles);
  physcollision->CollideGetAABB(this: physcollision, a2: &mins, a3: &maxs, a4: v5, a5: &vec3_origin, a6: &vec3_angle);
  mins.x = mins.x - 1.0;
  mins.y = mins.y - 1.0;
  mins.z = mins.z - 1.0;
  maxs.x = maxs.x + 1.0;
  maxs.y = maxs.y + 1.0;
  maxs.z = maxs.z + 1.0;
  NDebugOverlay::BoxAngles(origin: &pos, &mins, &maxs, &angles, r, g, b, a, duration: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10181350
// Name: DrawConstraintObjectsAxes
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawConstraintObjectsAxes(IPhysicsConstraint *pConstraint@<edi>, CBaseEntity *pConstraintEntity)
{
  bool v2; // bl
  IPhysicsObject *v3; // eax
  IPhysicsObject *v4; // esi
  IPhysicsObject *v5; // eax
  IPhysicsObject *v6; // esi
  matrix3x4_t xformAtt; // [esp+2Ch] [ebp-84h] BYREF
  matrix3x4_t xformRef; // [esp+5Ch] [ebp-54h] BYREF
  QAngle angles; // [esp+8Ch] [ebp-24h] BYREF
  Vector posWorld; // [esp+98h] [ebp-18h] BYREF
  Vector pos; // [esp+A4h] [ebp-Ch] BYREF

  if ( pConstraint != nullptr && pConstraintEntity != nullptr )
  {
    v2 = pConstraint->GetConstraintTransform(this: pConstraint, a2: &xformRef, a3: &xformAtt);
    v3 = pConstraint->GetReferenceObject(this: pConstraint);
    v4 = v3;
    if ( v3 != nullptr && !v3->IsStatic(this: v3) )
    {
      if ( v2 )
      {
        MatrixAngles(matrix: &xformRef, &angles, position: &pos);
        v4->LocalToWorld(this: v4, a2: &posWorld, a3: &pos);
        NDebugOverlay::Axis(position: &posWorld, angles: &vec3_angle, size: 12.0, noDepthTest: 0, flDuration: 0.0);
      }
      DrawPhysicsBounds(pObject: v4, r: 0, g: 255, b: 0, a: 12);
    }
    v5 = pConstraint->GetAttachedObject(this: pConstraint);
    v6 = v5;
    if ( v5 != nullptr && !v5->IsStatic(this: v5) )
    {
      if ( v2 )
      {
        MatrixAngles(matrix: &xformAtt, &angles, position: &posWorld);
        v6->LocalToWorld(this: v6, a2: &pos, a3: &posWorld);
        NDebugOverlay::Axis(position: &pos, angles: &vec3_angle, size: 12.0, noDepthTest: 0, flDuration: 0.0);
      }
      DrawPhysicsBounds(pObject: v6, r: 255, g: 0, b: 0, a: 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101814A0
// Name: public: virtual void CPhysConstraint::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::DrawDebugGeometryOverlays(CPhysConstraint *this)
{
  if ( (this->m_debugOverlays & 0x2C) != 0 )
    DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x101814D0
// Name: public: virtual void CPhysConstraint::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::Precache(CPhysConstraint *this)
{
  if ( this->m_breakSound.pszValue != nullptr )
    CBaseEntity::PrecacheScriptSound(soundname: this->m_breakSound.pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x101814F0
// Name: public: virtual void CPhysConstraint::OnConstraintSetup(struct hl_constraint_info_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::OnConstraintSetup(CPhysConstraint *this, hl_constraint_info_t *info)
{
  CBaseEntity *v3; // eax
  CBaseEntity *v4; // eax

  if ( info->pObjects[0] != nullptr && info->pObjects[1] != nullptr )
  {
    v3 = (CBaseEntity *)info->pObjects[0]->GetGameData(this: info->pObjects[0]);
    if ( v3 != nullptr )
      g_pNotify->AddEntity(this: g_pNotify, a2: this, a3: v3);
    v4 = (CBaseEntity *)info->pObjects[1]->GetGameData(this: info->pObjects[1]);
    if ( v4 != nullptr )
      g_pNotify->AddEntity(this: g_pNotify, a2: this, a3: v4);
  }
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    PhysDisableEntityCollisions(pObject0: info->pObjects[0], pObject1: info->pObjects[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10181560
// Name: class IPhysicsConstraintGroup __near * GetConstraintGroup(struct string_t)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraintGroup *__cdecl GetConstraintGroup(string_t systemName)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  _DWORD *v3; // eax

  pszValue = systemName.pszValue;
  if ( systemName.pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr
    && (v3 = __RTDynamicCast(
               inptr: EntityByName,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CPhysConstraintSystem `RTTI Type Descriptor',
               isReference: 0)) != nullptr )
  {
    return (IPhysicsConstraintGroup *)v3[213];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101815B0
// Name: public: void CPhysHinge::InputSetVelocity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysHinge::InputSetVelocity(
        CPhysHinge *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  IPhysicsConstraint *m_pConstraint; // ecx
  IPhysicsObject *(__thiscall *GetReferenceObject)(IPhysicsConstraint *); // edx
  int v9; // edi
  int v10; // eax
  IPhysicsObject *v11; // eax
  float *v12; // eax
  IPhysicsConstraint *v13; // ecx
  IPhysicsObject *(__thiscall *v14)(IPhysicsConstraint *); // edx
  __int128 v15; // xmm0
  int v16; // eax
  IPhysicsObject *v17; // eax
  IPhysicsObject *v18; // eax
  float *v19; // eax
  IPhysicsConstraint *v20; // ecx
  IPhysicsObject *(__thiscall *GetAttachedObject)(IPhysicsConstraint *); // edx
  __int128 v22; // xmm0
  int v23; // eax
  float v24; // xmm2_4
  float m_systemLoadScale; // xmm0_4
  _QWORD v28[2]; // [esp+20h] [ebp-2Ch] BYREF
  float v29; // [esp+38h] [ebp-14h]
  float v30; // [esp+3Ch] [ebp-10h]
  int v31; // [esp+40h] [ebp-Ch]
  float speed; // [esp+44h] [ebp-8h]
  float retaddr; // [esp+4Ch] [ebp+0h]

  v31 = a2;
  speed = retaddr;
  if ( this->m_pConstraint != nullptr
    && this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint) != nullptr
    && this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint) != nullptr )
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      pszValue = inputdata->value.iszVal.pszValue;
    else
      *(float *)&pszValue = 0.0;
    m_pConstraint = this->m_pConstraint;
    GetReferenceObject = m_pConstraint->GetReferenceObject;
    v29 = *(float *)&pszValue;
    v30 = 1.0;
    v9 = 0;
    v10 = ((int (__thiscall *)(IPhysicsConstraint *, int, int))GetReferenceObject)(a1: m_pConstraint, a2: a3, a3: a4);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 40))(a1: v10) != 0 )
    {
      v11 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
      v12 = (float *)v11->GetInertia(this: v11, result: (Vector *)((char *)v28 + 4));
      v13 = this->m_pConstraint;
      v14 = v13->GetReferenceObject;
      v15 = 0;
      *(float *)&v15 = fsqrt((float)((float)(*v12 * *v12) + (float)(v12[1] * v12[1])) + (float)(v12[2] * v12[2]));
      *(_OWORD *)v28 = v15;
      v30 = *(float *)&v15;
      v9 = 1;
      v16 = (int)v14(this: v13);
      (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 96))(a1: v16);
    }
    v17 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    if ( v17->IsMoveable(this: v17) )
    {
      v18 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
      v19 = (float *)v18->GetInertia(this: v18, result: (Vector *)((char *)v28 + 4));
      v20 = this->m_pConstraint;
      GetAttachedObject = v20->GetAttachedObject;
      v22 = 0;
      *(float *)&v22 = fsqrt((float)((float)(*v19 * *v19) + (float)(v19[1] * v19[1])) + (float)(v19[2] * v19[2]));
      *(_OWORD *)v28 = v22;
      v30 = *(float *)&v22 + v30;
      ++v9;
      v23 = (int)GetAttachedObject(this: v20);
      (*(void (__thiscall **)(int))(*(_DWORD *)v23 + 96))(a1: v23);
    }
    v24 = v30;
    if ( v9 > 0 )
      v24 = v30 / (float)v9;
    m_systemLoadScale = this->m_systemLoadScale;
    if ( m_systemLoadScale == 0.0 )
      m_systemLoadScale = 1.0;
    ((void (__thiscall *)(IPhysicsConstraint *, _DWORD, _DWORD))this->m_pConstraint->SetAngularMotor)(
      a1: this->m_pConstraint,
      a2: LODWORD(v29),
      a3: 1.0 / gpGlobals->interval_per_tick * (float)((float)((float)(m_systemLoadScale * v29) * v24) * m_systemLoadScale));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101817E0
// Name: public: void CPhysHinge::InputSetHingeFriction(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysHinge::InputSetHingeFriction(CPhysHinge *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  float v4; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  this->m_hingeFriction = flVal;
  _Msg(a1: "Setting hinge friction to %f\n", flVal);
  v4 = this->m_hingeFriction * 1000.0;
  this->m_hinge.hingeAxis.minRotation = 0.0;
  this->m_hinge.hingeAxis.maxRotation = 0.0;
  this->m_hinge.hingeAxis.angularVelocity = 0.0;
  this->m_hinge.hingeAxis.torque = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10181860
// Name: GetUnitAxisIndex
// Source: json
//------------------------------------------------------------------------------
int __usercall GetUnitAxisIndex@<eax>(const Vector *axis@<esi>)
{
  char v1; // cl
  int v2; // edx
  float y; // xmm0_4
  float z; // xmm0_4

  v1 = 0;
  v2 = -1;
  if ( axis->x != 0.0 )
  {
    if ( fabs(axis->x) == 1.0 )
    {
      v2 = 0;
      v1 = 1;
    }
    else
    {
      v1 = 0;
    }
  }
  y = axis->y;
  if ( y != 0.0 )
  {
    if ( fabs(y) == 1.0 && v2 < 0 )
    {
      v2 = 1;
      v1 = 1;
    }
    else
    {
      v1 = 0;
    }
  }
  z = axis->z;
  if ( z == 0.0 )
  {
    if ( v1 != 0 )
      return v2;
  }
  else if ( fabs(z) == 1.0 && v2 < 0 )
  {
    return 2;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10181900
// Name: public: void CPhysSlideConstraint::InputSetVelocity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSlideConstraint::InputSetVelocity(CPhysSlideConstraint *this, inputdata_t *inputdata)
{
  const char *pszValue; // xmm0_4
  int v4; // edi
  IPhysicsObject *v5; // eax
  IPhysicsObject *v6; // eax
  IPhysicsObject *v7; // eax
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // eax
  IPhysicsObject *v10; // eax
  float v11; // xmm2_4
  float m_systemLoadScale; // xmm0_4
  float speed; // [esp+Ch] [ebp-4h]
  float massLoad; // [esp+18h] [ebp+8h]

  if ( this->m_pConstraint != nullptr
    && this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint) != nullptr
    && this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint) != nullptr )
  {
    if ( inputdata->value.fieldType == FIELD_FLOAT )
      pszValue = inputdata->value.iszVal.pszValue;
    else
      pszValue = nullptr;
    speed = *(float *)&pszValue;
    massLoad = 1.0;
    v4 = 0;
    v5 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
    if ( v5->IsMoveable(this: v5) )
    {
      v6 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
      massLoad = v6->GetMass(this: v6);
      v4 = 1;
      v7 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
      v7->Wake(this: v7);
    }
    v8 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    if ( v8->IsMoveable(this: v8) )
    {
      v9 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
      massLoad = ((double (__thiscall *)(IPhysicsObject *))v9->GetMass)(a1: v9) + massLoad;
      ++v4;
      v10 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
      v10->Wake(this: v10);
    }
    v11 = massLoad;
    if ( v4 > 0 )
      v11 = massLoad / (float)v4;
    m_systemLoadScale = this->m_systemLoadScale;
    if ( m_systemLoadScale == 0.0 )
      m_systemLoadScale = 1.0;
    ((void (__thiscall *)(IPhysicsConstraint *, _DWORD, _DWORD))this->m_pConstraint->SetLinearMotor)(
      a1: this->m_pConstraint,
      a2: LODWORD(speed),
      a3: 1.0 / gpGlobals->interval_per_tick * (float)((float)(m_systemLoadScale * speed) * v11));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181B60
// Name: public: struct constraint_anchor_t __near * CAnchorList::Find(struct string_t)
// Source: json
//------------------------------------------------------------------------------
constraint_anchor_t *__thiscall CAnchorList::Find(CAnchorList *this, string_t name)
{
  int v3; // esi
  int i; // edi
  const char *pszValue; // ecx
  const char *v6; // eax

  v3 = this->m_list.m_Size - 1;
  if ( v3 < 0 )
    return nullptr;
  for ( i = v3; ; --i )
  {
    pszValue = name.pszValue;
    if ( name.pszValue == nullptr )
      pszValue = locale;
    v6 = this->m_list.m_Memory.m_pMemory[i].name.pszValue;
    if ( v6 == nullptr )
      v6 = locale;
    if ( v6 == pszValue || _V_stricmp(s1: v6, s2: pszValue) == 0 )
      break;
    if ( --v3 < 0 )
      return nullptr;
  }
  return &this->m_list.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x10181C20
// Name: void PhysTeleportConstrainedEntity(class CBaseEntity __near *,class IPhysicsObject __near *,class IPhysicsObject __near *,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PhysTeleportConstrainedEntity(
        CBaseEntity *pTeleportSource,
        IPhysicsObject *pObject0,
        IPhysicsObject *pObject1,
        const Vector *prevPosition,
        const QAngle *prevAngles,
        bool physicsRotate)
{
  CBaseEntity *v6; // edi
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx
  float z; // eax
  const matrix3x4_t *v11; // eax
  const matrix3x4_t *v12; // eax
  matrix3x4_t endCoord; // [esp+4h] [ebp-E4h] BYREF
  matrix3x4_t startInv; // [esp+34h] [ebp-B4h] BYREF
  matrix3x4_t xform; // [esp+64h] [ebp-84h] BYREF
  matrix3x4_t startCoord; // [esp+94h] [ebp-54h] BYREF
  Vector fixupPos; // [esp+C4h] [ebp-24h] BYREF
  QAngle fixupAngles; // [esp+D0h] [ebp-18h] BYREF
  QAngle oldAngles; // [esp+DCh] [ebp-Ch] BYREF

  v6 = (CBaseEntity *)pObject0->GetGameData(this: pObject0);
  v7 = (CBaseEntity *)pObject1->GetGameData(this: pObject1);
  if ( v6 != nullptr && v7 != nullptr )
  {
    v8 = v7;
    if ( pTeleportSource != v6 )
    {
      if ( pTeleportSource != v7 )
      {
        _Msg(a1: "Bogus teleport notification!!\n");
        return;
      }
      v8 = v6;
    }
    if ( v8->m_MoveType.m_Value == 6 )
    {
      m_pPhysicsObject = v8->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr && m_pPhysicsObject->IsMoveable(this: m_pPhysicsObject) )
      {
        z = prevAngles->z;
        *(_QWORD *)&oldAngles.x = *(_QWORD *)&prevAngles->x;
        oldAngles.z = z;
        if ( !physicsRotate )
          oldAngles = *CBaseEntity::GetAbsAngles(this: pTeleportSource);
        AngleMatrix(angles: &oldAngles, position: prevPosition, matrix: &startCoord);
        MatrixInvert(in: &startCoord, out: &startInv);
        v11 = CBaseEntity::EntityToWorldTransform(this: pTeleportSource);
        ConcatTransforms(in1: v11, in2: &startInv, out: &xform);
        v12 = CBaseEntity::EntityToWorldTransform(this: v8);
        ConcatTransforms(in1: &xform, in2: v12, out: &endCoord);
        MatrixAngles(matrix: &endCoord, angles: &fixupAngles, position: &fixupPos);
        v8->Teleport(this: v8, a2: &fixupPos, a3: &fixupAngles, a4: nullptr, a5: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10181D70
// Name: public: virtual int CPhysConstraint::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysConstraint::DrawDebugTextOverlays(CPhysConstraint *this)
{
  int result; // eax
  int v3; // edi
  CFmtStrN<256> str; // [esp+20h] [ebp-124h] BYREF
  constraint_breakableparams_t params; // [esp+12Ch] [ebp-18h] BYREF
  int savedregs; // [esp+144h] [ebp+0h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( this->m_pConstraint != nullptr && (this->m_debugOverlays & 1) != 0 )
  {
    _V_memset(dest: &params, fill: 0, count: 24);
    this->m_pConstraint->GetConstraintParams(this: this->m_pConstraint, a2: &params);
    if ( params.bodyMassScale[0] != 1.0 && params.bodyMassScale[0] != 0.0
      || params.bodyMassScale[1] != 1.0 && params.bodyMassScale[1] != 0.0 )
    {
      CFmtStrN<256>::CFmtStrN<256>(
        this: &str,
        pszFormat: "mass ratio %.4f:%.4f\n",
        params.bodyMassScale[0],
        params.bodyMassScale[1]);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      NDebugOverlay::EntityTextAtPosition(
        origin: &this->m_vecAbsOrigin,
        text_offset: v3,
        text: str.m_szBuf,
        duration: 0.0,
        r: 255,
        g: 255,
        b: 0,
        a: 255);
    }
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10181E70
// Name: void FindPhysicsAnchor(struct string_t,struct hl_constraint_info_t __near &,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FindPhysicsAnchor(string_t name, hl_constraint_info_t *info, int index, CBaseEntity *pErrorEntity)
{
  constraint_anchor_t *v4; // eax
  constraint_anchor_t *v5; // esi
  unsigned int v6; // eax
  CHandle<CBaseEntity> *p_hEntity; // edx
  hl_constraint_info_t *v8; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseAnimating *v11; // ebx
  CBaseEntity *v12; // eax
  int AttachmentBone; // eax
  int PhysicsBone; // eax
  _DWORD *v15; // ebx
  float *p_x; // eax
  unsigned int v17; // eax
  const char *pszValue; // eax
  _DWORD v19[1024]; // [esp+8h] [ebp-1018h] BYREF
  Vector absOrigin; // [esp+1008h] [ebp-18h] BYREF
  int v21; // [esp+1014h] [ebp-Ch]
  CBaseAnimating *v22; // [esp+1018h] [ebp-8h]
  CHandle<CBaseEntity> *v23; // [esp+101Ch] [ebp-4h]

  v4 = CAnchorList::Find(this: &g_AnchorList, name);
  v5 = v4;
  if ( v4 != nullptr
    && (v6 = v4->hEntity.m_Index, p_hEntity = &v5->hEntity, v23 = &v5->hEntity, v6 != -1)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity != nullptr )
  {
    v8 = info;
    info->massScale[index] = v5->massScale;
    if ( v5->parentAttachment > 0 )
    {
      m_Index = p_hEntity->m_Index;
      if ( p_hEntity->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      }
      v11 = (CBaseAnimating *)m_pEntity->__vftable[17].GetRefEHandle(this: m_pEntity);
      v22 = v11;
      if ( v11 != nullptr )
      {
        v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: v23);
        v21 = v12->VPhysicsGetObjectList(this: v12, a2: (IPhysicsObject **)v19, a3: 1024);
        AttachmentBone = CBaseAnimating::GetAttachmentBone(this: v11, iAttachment: v5->parentAttachment);
        PhysicsBone = CBaseAnimating::GetPhysicsBone(this: v11, boneIndex: AttachmentBone);
        if ( PhysicsBone < v21 )
        {
          v15 = &v19[PhysicsBone];
          info->pObjects[index] = (IPhysicsObject *)*v15;
          CBaseAnimating::GetAttachment(
            this: v22,
            iAttachment: v5->parentAttachment,
            &absOrigin,
            forward: nullptr,
            right: nullptr,
            up: nullptr);
          (*(void (__thiscall **)(_DWORD, Vector *, Vector *))(*(_DWORD *)*v15 + 228))(
            a1: *v15,
            a2: &info->anchorPosition[index],
            a3: &absOrigin);
          return;
        }
      }
      v8 = info;
      p_hEntity = v23;
    }
    p_x = &v8->anchorPosition[index].x;
    *p_x = v5->localOrigin.x;
    p_x[1] = v5->localOrigin.y;
    p_x[2] = v5->localOrigin.z;
    v17 = p_hEntity->m_Index;
    if ( p_hEntity->m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
      v8->pObjects[index] = (IPhysicsObject *)MEMORY[0x148];
    else
      v8->pObjects[index] = (IPhysicsObject *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity[82].__vftable;
  }
  else
  {
    info->anchorPosition[index] = vec3_origin;
    pszValue = name.pszValue;
    if ( name.pszValue == nullptr )
      pszValue = locale;
    info->pObjects[index] = FindPhysicsObjectByName(pName: pszValue, pErrorEntity);
    info->massScale[index] = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182080
// Name: protected: void CPhysConstraint::GetConstraintObjects(struct hl_constraint_info_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::GetConstraintObjects(CPhysConstraint *this, hl_constraint_info_t *info)
{
  const char *pszValue; // eax
  const char *v4; // ecx
  const char *v5; // eax
  const char *DebugName; // eax
  const char *v7; // eax
  const char *v8; // ecx
  const char *v9; // eax
  const char *v10; // eax
  IPhysicsObject *v11; // ecx
  CBaseEntity *v12; // eax
  ragdoll_t *Ragdoll; // eax
  IPhysicsConstraintGroup *pGroup; // eax
  IPhysicsObject *v15; // ecx
  CBaseEntity *v16; // eax
  ragdoll_t *v17; // eax
  const char *v18; // [esp-8h] [ebp-10h]
  const char *v19; // [esp-8h] [ebp-10h]
  const char *v20; // [esp-4h] [ebp-Ch]
  const char *v21; // [esp-4h] [ebp-Ch]

  FindPhysicsAnchor(name: this->m_nameAttach1, info, index: 0, pErrorEntity: this);
  FindPhysicsAnchor(name: this->m_nameAttach2, info, index: 1, pErrorEntity: this);
  if ( info->pObjects[0] == nullptr )
  {
    if ( info->pObjects[1] == nullptr )
      goto LABEL_24;
    pszValue = this->m_nameAttach1.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( _V_strlen(str: pszValue) != 0 )
    {
      v4 = this->m_nameAttach2.pszValue;
      if ( v4 == nullptr )
        v4 = locale;
      v5 = this->m_nameAttach1.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      v20 = v4;
      v18 = v5;
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(a1: "Bogus constraint %s (attaches ENTITY NOT FOUND:%s to %s)\n", DebugName, v18, v20);
    }
    info->pObjects[0] = g_PhysWorldObject;
    goto LABEL_23;
  }
  if ( info->pObjects[1] == nullptr )
  {
    v7 = this->m_nameAttach2.pszValue;
    if ( v7 == nullptr )
      v7 = locale;
    if ( _V_strlen(str: v7) != 0 )
    {
      v8 = this->m_nameAttach2.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      v9 = this->m_nameAttach1.pszValue;
      if ( v9 == nullptr )
        v9 = locale;
      v21 = v8;
      v19 = v9;
      v10 = CBaseEntity::GetDebugName(this);
      _Warning(a1: "Bogus constraint %s (attaches %s to ENTITY NOT FOUND:%s)\n", v10, v19, v21);
    }
    info->pObjects[1] = info->pObjects[0];
    info->pObjects[0] = g_PhysWorldObject;
    info->swapped = true;
LABEL_23:
    info->massScale[0] = 1.0;
    info->massScale[1] = 1.0;
  }
LABEL_24:
  v11 = info->pObjects[0];
  if ( v11 != nullptr
    && (v12 = (CBaseEntity *)v11->GetGameData(this: v11), (Ragdoll = Ragdoll_GetRagdoll(pEntity: v12)) != nullptr) )
  {
    pGroup = Ragdoll->pGroup;
  }
  else
  {
    pGroup = nullptr;
  }
  info->pGroup = pGroup;
  if ( pGroup == nullptr )
  {
    v15 = info->pObjects[1];
    if ( v15 != nullptr
      && (v16 = (CBaseEntity *)v15->GetGameData(this: v15), (v17 = Ragdoll_GetRagdoll(pEntity: v16)) != nullptr) )
    {
      info->pGroup = v17->pGroup;
    }
    else
    {
      info->pGroup = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182200
// Name: protected: bool CPhysConstraint::ActivateConstraint(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CPhysConstraint::ActivateConstraint@<al>(CPhysConstraint *this@<ecx>, int a2@<edi>)
{
  IPhysicsConstraint *m_pConstraint; // ecx
  IPhysicsObject *v4; // eax
  IPhysicsConstraint *v5; // ecx
  const char *pszValue; // ecx
  const char *v8; // eax
  const char *v9; // esi
  const char *v10; // ecx
  const char *v11; // eax
  const char *v12; // esi
  IPhysicsConstraintGroup *ConstraintGroup; // edi
  IPhysicsConstraint *v14; // eax
  hl_constraint_info_t info; // [esp+0h] [ebp-30h] BYREF

  m_pConstraint = this->m_pConstraint;
  memset(&info, 0, 36);
  info.swapped = false;
  info.massScale[1] = 1.0;
  info.massScale[0] = 1.0;
  if ( m_pConstraint != nullptr )
  {
    v4 = m_pConstraint->GetReferenceObject(this: m_pConstraint);
    v5 = this->m_pConstraint;
    info.pObjects[0] = v4;
    info.pObjects[1] = v5->GetAttachedObject(this: v5);
    this->OnConstraintSetup(this, a2: &info);
    return 1;
  }
  CPhysConstraint::GetConstraintObjects(this, &info);
  if ( info.pObjects[0] == nullptr && info.pObjects[1] == nullptr )
    return 0;
  if ( ((unsigned __int8 (*)(void))info.pObjects[0]->IsStatic)() != 0
    && info.pObjects[1]->IsStatic(this: info.pObjects[1]) )
  {
    if ( this->m_nameAttach2.pszValue != nullptr )
    {
      pszValue = this->m_nameAttach2.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
    }
    else
    {
      pszValue = "world";
    }
    v8 = this->m_nameAttach1.pszValue;
    if ( v8 == nullptr )
      v8 = locale;
    v9 = this->m_iName.m_Value.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    _Warning(a1: "Constraint (%s) attached to two static objects (%s and %s)!!!\n", v9, v8, pszValue);
    return 0;
  }
  if ( info.pObjects[0]->GetShadowController(this: info.pObjects[0]) != nullptr
    && info.pObjects[1]->GetShadowController(this: info.pObjects[1]) != nullptr )
  {
    if ( this->m_nameAttach2.pszValue != nullptr )
    {
      v10 = this->m_nameAttach2.pszValue;
      if ( v10 == nullptr )
        v10 = locale;
    }
    else
    {
      v10 = "world";
    }
    v11 = this->m_nameAttach1.pszValue;
    if ( v11 == nullptr )
      v11 = locale;
    v12 = this->m_iName.m_Value.pszValue;
    if ( v12 == nullptr )
      v12 = locale;
    _Warning(a1: "Constraint (%s) attached to two shadow objects (%s and %s)!!!\n", v12, v11, v10);
    return 0;
  }
  else
  {
    ConstraintGroup = GetConstraintGroup(systemName: this->m_nameSystem);
    if ( ConstraintGroup == nullptr )
      ConstraintGroup = info.pGroup;
    v14 = (IPhysicsConstraint *)((int (__thiscall *)(CPhysConstraint *, IPhysicsConstraintGroup *, hl_constraint_info_t *, int))this->CreateConstraint)(
                                  a1: this,
                                  a2: ConstraintGroup,
                                  a3: &info,
                                  a4: a2);
    this->m_pConstraint = v14;
    if ( v14 != nullptr )
    {
      v14->SetGameData(this: v14, a2: this);
      if ( ConstraintGroup != nullptr )
        ConstraintGroup->Activate(this: ConstraintGroup);
      this->OnConstraintSetup(this, a2: &info);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182400
// Name: public: virtual void CPhysConstraint::NotifySystemEvent(class CBaseEntity __near *,enum notify_system_event_t,struct notify_system_event_params_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysConstraint::NotifySystemEvent(
        CPhysConstraint *this@<ecx>,
        int a2@<ebp>,
        CBaseEntity *pNotify,
        notify_system_event_t eventType,
        const notify_system_event_params_t *params)
{
  float v6; // xmm0_4
  IPhysicsConstraint *m_pConstraint; // esi
  IPhysicsObject *v8; // eax
  IPhysicsObject *v9; // [esp-40h] [ebp-4Ch]
  const notify_teleport_params_t *pTeleport; // [esp-3Ch] [ebp-48h]
  QAngle *p_prevAngles; // [esp-38h] [ebp-44h]
  bool physicsRotate; // [esp-34h] [ebp-40h]
  _DWORD v13[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v13[0] = a2;
  v13[1] = retaddr;
  if ( eventType == NOTIFY_EVENT_TELEPORT && gpGlobals->tickcount != this->m_teleportTick )
  {
    if ( (pNotify->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pNotify, a2: (int)v13);
    v6 = params->pTeleport->prevOrigin.x - pNotify->m_vecAbsOrigin.x;
    if ( this->m_minTeleportDistance < fsqrt(
                                         (float)((float)((float)(params->pTeleport->prevOrigin.y
                                                               - pNotify->m_vecAbsOrigin.y)
                                                       * (float)(params->pTeleport->prevOrigin.y
                                                               - pNotify->m_vecAbsOrigin.y))
                                               + (float)((float)(params->pTeleport->prevOrigin.z
                                                               - pNotify->m_vecAbsOrigin.z)
                                                       * (float)(params->pTeleport->prevOrigin.z
                                                               - pNotify->m_vecAbsOrigin.z)))
                                       + (float)(v6 * v6)) )
    {
      this->m_teleportTick = gpGlobals->tickcount;
      m_pConstraint = this->m_pConstraint;
      physicsRotate = params->pTeleport->physicsRotate;
      p_prevAngles = &params->pTeleport->prevAngles;
      pTeleport = params->pTeleport;
      v9 = m_pConstraint->GetAttachedObject(this: m_pConstraint);
      v8 = m_pConstraint->GetReferenceObject(this: m_pConstraint);
      PhysTeleportConstrainedEntity(
        pTeleportSource: pNotify,
        pObject0: v8,
        pObject1: v9,
        prevPosition: &pTeleport->prevOrigin,
        prevAngles: p_prevAngles,
        physicsRotate);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182500
// Name: private: bool CPhysHinge::IsWorldHinge(struct hl_constraint_info_t const __near &,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysHinge::IsWorldHinge(CPhysHinge *this, const hl_constraint_info_t *info, int *pAxisOut)
{
  int UnitAxisIndex; // eax
  Vector localHinge; // [esp+10h] [ebp-Ch] BYREF

  if ( (this->m_spawnflags.m_Value & 8) == 0 )
    return 0;
  if ( info->pObjects[0] != g_PhysWorldObject )
    return 0;
  info->pObjects[1]->WorldToLocalVector(this: info->pObjects[1], a2: &localHinge, a3: &this->m_hinge.worldAxisDirection);
  UTIL_SnapDirectionToAxis(direction: &localHinge, epsilon: 0.0020000001);
  UnitAxisIndex = GetUnitAxisIndex(axis: &localHinge);
  if ( UnitAxisIndex < 0 )
    return 0;
  *pAxisOut = UnitAxisIndex;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10182580
// Name: public: virtual class IPhysicsConstraint __near * CPhysSlideConstraint::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysSlideConstraint::CreateConstraint(
        CPhysSlideConstraint *this,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  int m_Value; // ecx
  float v5; // xmm1_4
  int m_iEFlags; // edx
  float v7; // xmm0_4
  float v8; // xmm1_4
  bool v9; // zf
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  constraint_slidingparams_t sliding; // [esp+Ch] [ebp-7Ch] BYREF
  Vector position; // [esp+70h] [ebp-18h] BYREF
  Vector axisDirection; // [esp+7Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+88h] [ebp+0h] BYREF

  SetIdentityMatrix(matrix: &sliding.attachedRefXform);
  m_Value = this->m_spawnflags.m_Value;
  v5 = this->m_forceLimit * 0.45454544;
  m_iEFlags = this->m_iEFlags;
  memset((void *)&sliding.slideAxisRef, 0, sizeof(sliding.slideAxisRef));
  memset(&sliding.limitMin, 0, 16);
  sliding.constraint.bodyMassScale[0] = info->massScale[0];
  v7 = info->massScale[1];
  sliding.constraint.forceLimit = v5;
  v8 = this->m_torqueLimit * 0.45454544;
  sliding.constraint.bodyMassScale[1] = v7;
  sliding.constraint.torqueLimit = v8;
  sliding.constraint.isActive = (m_Value & 4) == 0;
  sliding.constraint.strength = 1.0;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  axisDirection.x = this->m_axisEnd.x - this->m_vecAbsOrigin.x;
  axisDirection.y = this->m_axisEnd.y - this->m_vecAbsOrigin.y;
  axisDirection.z = this->m_axisEnd.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &axisDirection);
  UTIL_SnapDirectionToAxis(direction: &axisDirection, epsilon: 0.0020000001);
  constraint_slidingparams_t::InitWithCurrentObjectState(
    this: &sliding,
    pRef: info->pObjects[0],
    pAttached: info->pObjects[1],
    slideDirWorldspace: &axisDirection);
  v9 = (this->m_spawnflags.m_Value & 2) == 0;
  sliding.friction = this->m_slideFriction;
  if ( !v9 )
  {
    info->pObjects[1]->GetPosition(this: info->pObjects[1], a2: &position, a3: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v10 = (float)((float)(this->m_vecAbsOrigin.y * axisDirection.y) + (float)(axisDirection.x * this->m_vecAbsOrigin.x))
        + (float)(this->m_vecAbsOrigin.z * axisDirection.z);
    v11 = (float)((float)(this->m_axisEnd.x * axisDirection.x) + (float)(axisDirection.y * this->m_axisEnd.y))
        + (float)(this->m_axisEnd.z * axisDirection.z);
    if ( v10 > v11 )
    {
      v10 = (float)((float)(this->m_axisEnd.x * axisDirection.x) + (float)(axisDirection.y * this->m_axisEnd.y))
          + (float)(this->m_axisEnd.z * axisDirection.z);
      v11 = (float)((float)(this->m_vecAbsOrigin.y * axisDirection.y) + (float)(axisDirection.x * this->m_vecAbsOrigin.x))
          + (float)(this->m_vecAbsOrigin.z * axisDirection.z);
    }
    v12 = (float)((float)(position.y * axisDirection.y) + (float)(position.x * axisDirection.x))
        + (float)(position.z * axisDirection.z);
    if ( v10 <= v12 )
    {
      if ( v12 > v11 )
        v11 = (float)((float)(position.y * axisDirection.y) + (float)(position.x * axisDirection.x))
            + (float)(position.z * axisDirection.z);
    }
    else
    {
      v10 = (float)((float)(position.y * axisDirection.y) + (float)(position.x * axisDirection.x))
          + (float)(position.z * axisDirection.z);
    }
    sliding.limitMin = v10 - v12;
    sliding.limitMax = v11 - v12;
  }
  return physenv->CreateSlidingConstraint(
           this: physenv,
           a2: info->pObjects[0],
           a3: info->pObjects[1],
           a4: pGroup,
           a5: &sliding);
}

//------------------------------------------------------------------------------
// Address: 0x101827D0
// Name: public: virtual class IPhysicsConstraint __near * CPhysFixed::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysFixed::CreateConstraint(
        CPhysFixed *this,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  IPhysicsObject *v4; // ecx
  IPhysicsObject *v5; // ebx
  float v6; // xmm1_4
  IPhysicsObject *v7; // ecx
  unsigned int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  IPhysicsObject *v12; // edi
  unsigned __int16 v13; // ax
  matrix3x4_t in; // [esp+Ch] [ebp-D8h] BYREF
  matrix3x4_t out; // [esp+3Ch] [ebp-A8h] BYREF
  matrix3x4_t in2; // [esp+6Ch] [ebp-78h] BYREF
  constraint_fixedparams_t fixed; // [esp+9Ch] [ebp-48h] BYREF

  SetIdentityMatrix(matrix: &fixed.attachedRefXform);
  v4 = info->pObjects[0];
  v5 = info->pObjects[1];
  fixed.constraint.forceLimit = 0.0;
  fixed.constraint.torqueLimit = 0.0;
  fixed.constraint.strength = 1.0;
  fixed.constraint.bodyMassScale[0] = 1.0;
  fixed.constraint.bodyMassScale[1] = 1.0;
  fixed.constraint.isActive = true;
  v4->GetPositionMatrix(this: v4, a2: &in);
  MatrixInvert(&in, &out);
  v5->GetPositionMatrix(this: v5, a2: &in2);
  ConcatTransforms(in1: &out, &in2, out: &fixed.attachedRefXform);
  v6 = this->m_forceLimit * 0.45454544;
  v7 = info->pObjects[0];
  v8 = (unsigned int)this->m_spawnflags.m_Value >> 2;
  fixed.constraint.strength = 1.0;
  v9 = info->massScale[0];
  fixed.constraint.forceLimit = v6;
  v10 = this->m_torqueLimit * 0.45454544;
  fixed.constraint.bodyMassScale[0] = v9;
  v11 = info->massScale[1];
  fixed.constraint.torqueLimit = v10;
  fixed.constraint.isActive = (v8 & 1) == 0;
  fixed.constraint.bodyMassScale[1] = v11;
  if ( v7 == g_PhysWorldObject )
  {
    v12 = info->pObjects[1];
    v13 = v12->GetGameFlags(this: v12);
    v12->SetGameFlags(this: v12, a2: v13 | 2);
  }
  return physenv->CreateFixedConstraint(
           this: physenv,
           a2: info->pObjects[0],
           a3: info->pObjects[1],
           a4: pGroup,
           a5: &fixed);
}

//------------------------------------------------------------------------------
// Address: 0x10182920
// Name: public: virtual class IPhysicsConstraint __near * CPhysPulley::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IPhysicsConstraint *__userpurge CPhysPulley::CreateConstraint@<eax>(
        CPhysPulley *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  unsigned int v7; // eax
  IPhysicsObject *v8; // ecx
  float x; // xmm0_4
  float v10; // xmm2_4
  float z; // xmm1_4
  double v12; // st7
  float v13; // xmm1_4
  double v14; // st7
  float v15; // xmm1_4
  float v16; // xmm0_4
  double y; // st7
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  __int128 v21; // xmm0
  float v22; // xmm2_4
  __int128 v23; // xmm0
  float m_gearRatio; // xmm0_4
  int m_Value; // eax
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  IPhysicsConstraint *(__thiscall *CreatePulleyConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_pulleyparams_t *); // edx
  _BYTE v33[12]; // [esp-Ch] [ebp-CCh] BYREF
  __int128 matrix_36; // [esp+24h] [ebp-9Ch] OVERLAPPED
  __int128 v35; // [esp+34h] [ebp-8Ch]
  float v36[3]; // [esp+44h] [ebp-7Ch] BYREF
  Vector world[2]; // [esp+50h] [ebp-70h] BYREF
  constraint_pulleyparams_t pulley; // [esp+68h] [ebp-58h] BYREF
  _UNKNOWN *retaddr; // [esp+C0h] [ebp+0h]

  pulley.gearRatio = a2;
  *(_DWORD *)&pulley.isRigid = retaddr;
  v7 = (unsigned int)this->m_iEFlags >> 11;
  world[1].y = 0.0;
  world[1].z = 0.0;
  world[1].x = 1.0;
  pulley.constraint.strength = 1.0;
  pulley.constraint.forceLimit = 1.0;
  LOBYTE(pulley.constraint.torqueLimit) = 1;
  pulley.objectPosition[1].x = 1.0;
  pulley.objectPosition[1].y = 1.0;
  memset(pulley.constraint.bodyMassScale, 0, 48);
  LOBYTE(pulley.objectPosition[1].z) = 0;
  if ( (v7 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&pulley.gearRatio);
  v8 = info->pObjects[0];
  *(_QWORD *)pulley.constraint.bodyMassScale = *(_QWORD *)&this->m_vecAbsOrigin.x;
  *(float *)&pulley.constraint.isActive = this->m_vecAbsOrigin.z;
  pulley.pulleyPosition[0] = this->m_position2;
  ((void (__thiscall *)(IPhysicsObject *, _BYTE *, int, int))v8->GetPositionMatrix)(a1: v8, a2: v33, a3, a4);
  VectorTransform(in1: (const float *)info, in2: (const matrix3x4_t *)v33, out: v36);
  info->pObjects[1]->GetPositionMatrix(this: info->pObjects[1], a2: (matrix3x4_t *)v33);
  VectorTransform(in1: &info->anchorPosition[1].x, in2: (const matrix3x4_t *)v33, out: &world[0].x);
  x = info->anchorPosition[0].x;
  v10 = v36[2] - *(float *)&pulley.constraint.isActive;
  pulley.pulleyPosition[1].y = info->anchorPosition[0].y;
  z = info->anchorPosition[0].z;
  this->m_offset[0].x = x;
  this->m_offset[0].y = info->anchorPosition[0].y;
  pulley.pulleyPosition[1].x = x;
  v12 = info->anchorPosition[0].z;
  pulley.pulleyPosition[1].z = z;
  v13 = v36[1];
  this->m_offset[0].z = v12;
  v14 = info->anchorPosition[1].x;
  v15 = v13 - pulley.constraint.bodyMassScale[1];
  pulley.objectPosition[0].x = info->anchorPosition[1].x;
  pulley.objectPosition[0].y = info->anchorPosition[1].y;
  v16 = info->anchorPosition[1].z;
  this->m_offset[1].x = v14;
  y = info->anchorPosition[1].y;
  pulley.objectPosition[0].z = v16;
  v18 = v36[0];
  this->m_offset[1].y = y;
  v19 = (float)(v18 - pulley.constraint.bodyMassScale[0]) * (float)(v18 - pulley.constraint.bodyMassScale[0]);
  this->m_offset[1].z = info->anchorPosition[1].z;
  v20 = (float)((float)(v15 * v15) + (float)(v10 * v10)) + v19;
  v21 = 0;
  *(float *)&v21 = fsqrt(v20);
  v35 = v21;
  v22 = this->m_addLength + *(float *)&v21;
  v23 = 0;
  *(float *)&v23 = fsqrt(
                     (float)((float)((float)(world[0].y - pulley.pulleyPosition[0].y)
                                   * (float)(world[0].y - pulley.pulleyPosition[0].y))
                           + (float)((float)(world[0].z - pulley.pulleyPosition[0].z)
                                   * (float)(world[0].z - pulley.pulleyPosition[0].z)))
                   + (float)((float)(world[0].x - pulley.pulleyPosition[0].x)
                           * (float)(world[0].x - pulley.pulleyPosition[0].x)));
  matrix_36 = v23;
  m_gearRatio = this->m_gearRatio;
  pulley.objectPosition[1].x = (float)(m_gearRatio * *(float *)&matrix_36) + v22;
  if ( m_gearRatio != 0.0 )
    pulley.objectPosition[1].y = m_gearRatio;
  m_Value = this->m_spawnflags.m_Value;
  v26 = this->m_forceLimit * 0.45454544;
  world[1].x = 1.0;
  v27 = info->massScale[0];
  world[1].y = v26;
  v28 = this->m_torqueLimit * 0.45454544;
  pulley.constraint.strength = v27;
  v29 = info->massScale[1];
  world[1].z = v28;
  LOBYTE(pulley.constraint.torqueLimit) = (m_Value & 4) == 0;
  pulley.constraint.forceLimit = v29;
  if ( (m_Value & 2) != 0 )
    LOBYTE(pulley.objectPosition[1].z) = 1;
  CreatePulleyConstraint = physenv->CreatePulleyConstraint;
  LODWORD(pulley.totalLength) = &world[1];
  LODWORD(pulley.objectPosition[1].z) = pGroup;
  LODWORD(pulley.objectPosition[1].y) = info->pObjects[1];
  return (IPhysicsConstraint *)((int (__thiscall *)(IPhysicsEnvironment *, IPhysicsObject *))CreatePulleyConstraint)(
                                 a1: physenv,
                                 a2: info->pObjects[0]);
}

//------------------------------------------------------------------------------
// Address: 0x10182C30
// Name: public: virtual class IPhysicsConstraint __near * CPhysLength::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
IPhysicsConstraint *__userpurge CPhysLength::CreateConstraint@<eax>(
        CPhysLength *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  unsigned int v7; // eax
  bool v8; // zf
  BOOL v9; // eax
  IPhysicsObject *v10; // ecx
  void (__thiscall *WorldToLocal)(IPhysicsObject *, Vector *, const Vector *); // edx
  float *v12; // edi
  float v13; // xmm1_4
  int m_Value; // ecx
  __int128 v15; // xmm0
  float m_minLength; // xmm1_4
  float v17; // xmm0_4
  int v18; // edx
  float v19; // xmm1_4
  float v20; // xmm0_4
  IPhysicsObject *v21; // esi
  float v22; // xmm0_4
  IPhysicsObject *v23; // eax
  IPhysicsConstraint *(__thiscall *CreateLengthConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_lengthparams_t *); // edx
  float v28[3]; // [esp-Ch] [ebp-7Ch] BYREF
  constraint_lengthparams_t length; // [esp+0h] [ebp-70h] BYREF
  _BYTE position[28]; // [esp+38h] [ebp-38h] OVERLAPPED
  IPhysicsObject *v31; // [esp+58h] [ebp-18h]
  float *p_z; // [esp+5Ch] [ebp-14h]
  float *v33; // [esp+60h] [ebp-10h]
  _DWORD v34[3]; // [esp+64h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v34[0] = a2;
  v34[1] = retaddr;
  v7 = (unsigned int)this->m_iEFlags >> 11;
  v28[1] = 0.0;
  v28[2] = 0.0;
  v28[0] = 1.0;
  length.constraint.strength = 1.0;
  length.constraint.forceLimit = 1.0;
  LOBYTE(length.constraint.torqueLimit) = 1;
  memset(length.constraint.bodyMassScale, 0, 24);
  length.objectPosition[1].x = 1.0;
  length.objectPosition[1].y = 0.0;
  if ( (v7 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)v34);
  v8 = !info->swapped;
  length.objectPosition[1].z = this->m_vecAbsOrigin.x;
  v9 = !v8;
  length.totalLength = this->m_vecAbsOrigin.y;
  length.minLength = this->m_vecAbsOrigin.z;
  *(float *)position = this->m_vecAttach.x;
  *(float *)&position[4] = this->m_vecAttach.y;
  *(float *)&position[8] = this->m_vecAttach.z;
  v10 = info->pObjects[0];
  v33 = (float *)info->pObjects[1];
  WorldToLocal = v10->WorldToLocal;
  p_z = &length.objectPosition[v9 + 1].z;
  v12 = &length.objectPosition[!v9 + 1].z;
  ((void (__thiscall *)(IPhysicsObject *, float *, float *, int, int))WorldToLocal)(
    a1: v10,
    a2: length.constraint.bodyMassScale,
    a3: p_z,
    a4: a3,
    a5: a4);
  (*(void (__thiscall **)(float *, Vector *, float *))(*(_DWORD *)v33 + 228))(
    a1: v33,
    a2: length.objectPosition,
    a3: v12);
  v13 = p_z[1] - v12[1];
  m_Value = this->m_spawnflags.m_Value;
  v15 = 0;
  *(float *)&v15 = (float)((float)(v13 * v13) + (float)((float)(p_z[2] - v12[2]) * (float)(p_z[2] - v12[2])))
                 + (float)((float)(*p_z - *v12) * (float)(*p_z - *v12));
  m_minLength = this->m_minLength;
  *(float *)&v15 = fsqrt(*(float *)&v15);
  *(_OWORD *)&position[12] = v15;
  v17 = this->m_addLength + *(float *)&v15;
  length.objectPosition[1].x = v17;
  length.objectPosition[1].y = m_minLength;
  this->m_totalLength = v17;
  if ( (m_Value & 2) != 0 )
    length.objectPosition[1].y = v17;
  *(_QWORD *)&this->m_offset[0].x = *(_QWORD *)length.constraint.bodyMassScale;
  this->m_offset[0].z = *(float *)&length.constraint.isActive;
  this->m_offset[1] = length.objectPosition[0];
  v18 = this->m_spawnflags.m_Value;
  v28[1] = this->m_forceLimit * 0.45454544;
  v19 = this->m_torqueLimit * 0.45454544;
  v33 = v28;
  v28[0] = 1.0;
  v20 = info->massScale[0];
  p_z = (float *)pGroup;
  v21 = info->pObjects[1];
  length.constraint.strength = v20;
  v22 = info->massScale[1];
  v23 = info->pObjects[0];
  LOBYTE(length.constraint.torqueLimit) = (v18 & 4) == 0;
  v28[2] = v19;
  length.constraint.forceLimit = v22;
  CreateLengthConstraint = physenv->CreateLengthConstraint;
  v31 = v21;
  return (IPhysicsConstraint *)((int (__thiscall *)(IPhysicsEnvironment *, IPhysicsObject *))CreateLengthConstraint)(
                                 a1: physenv,
                                 a2: v23);
}

//------------------------------------------------------------------------------
// Address: 0x10182EA0
// Name: public: virtual class IPhysicsConstraint __near * CRagdollConstraint::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CRagdollConstraint::CreateConstraint(
        CRagdollConstraint *this,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  int m_Value; // eax
  float m_xmin; // xmm0_4
  float m_ymax; // xmm1_4
  float m_xmax; // xmm0_4
  float m_yfriction; // xmm1_4
  float m_zmin; // xmm1_4
  float m_zmax; // xmm1_4
  float m_zfriction; // xmm0_4
  matrix3x4_t entityToWorld; // [esp+8h] [ebp-114h] BYREF
  matrix3x4_t worldToEntity; // [esp+38h] [ebp-E4h] BYREF
  constraint_ragdollparams_t ragdoll; // [esp+68h] [ebp-B4h] BYREF
  int savedregs; // [esp+11Ch] [ebp+0h] BYREF

  constraint_ragdollparams_t::Defaults(this: &ragdoll);
  info->pObjects[0]->GetPositionMatrix(this: info->pObjects[0], a2: &entityToWorld);
  MatrixInvert(in: &entityToWorld, out: &worldToEntity);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ConcatTransforms(in1: &worldToEntity, in2: &this->m_rgflCoordinateFrame, out: &ragdoll.constraintToReference);
  info->pObjects[1]->GetPositionMatrix(this: info->pObjects[1], a2: &entityToWorld);
  MatrixInvert(in: &entityToWorld, out: &worldToEntity);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ConcatTransforms(in1: &worldToEntity, in2: &this->m_rgflCoordinateFrame, out: &ragdoll.constraintToAttached);
  m_Value = this->m_spawnflags.m_Value;
  m_xmin = this->m_xmin;
  ragdoll.axes[0].torque = this->m_xfriction;
  ragdoll.axes[1].minRotation = this->m_ymin;
  m_ymax = this->m_ymax;
  ragdoll.axes[0].minRotation = m_xmin;
  m_xmax = this->m_xmax;
  ragdoll.axes[1].maxRotation = m_ymax;
  m_yfriction = this->m_yfriction;
  ragdoll.axes[0].maxRotation = m_xmax;
  ragdoll.axes[1].torque = m_yfriction;
  m_zmin = this->m_zmin;
  ragdoll.axes[0].angularVelocity = 0.0;
  ragdoll.axes[1].angularVelocity = 0.0;
  ragdoll.axes[2].minRotation = m_zmin;
  m_zmax = this->m_zmax;
  ragdoll.axes[2].angularVelocity = 0.0;
  m_zfriction = this->m_zfriction;
  ragdoll.onlyAngularLimits = (m_Value & 2) != 0;
  ragdoll.axes[2].maxRotation = m_zmax;
  ragdoll.axes[2].torque = m_zfriction;
  if ( (m_Value & 4) != 0 )
    ragdoll.isActive = false;
  return physenv->CreateRagdollConstraint(
           this: physenv,
           a2: info->pObjects[0],
           a3: info->pObjects[1],
           a4: pGroup,
           a5: &ragdoll);
}

//------------------------------------------------------------------------------
// Address: 0x10183040
// Name: private: virtual void CPhysConstraintEvents::ConstraintBroken(class IPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraintEvents::ConstraintBroken(CPhysConstraintEvents *this, IPhysicsConstraint *pConstraint)
{
  void *v2; // eax
  void *v3; // esi
  void (__thiscall ***v4)(void *, IPhysicsConstraint *); // eax

  v2 = pConstraint->GetGameData(this: pConstraint);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = (void (__thiscall ***)(void *, IPhysicsConstraint *))__RTDynamicCast(
                                                                inptr: v2,
                                                                VfDelta: 0,
                                                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                                TargetType: &IPhysicsConstraintEvent `RTTI Type Descriptor',
                                                                isReference: 0);
    if ( v4 != nullptr )
      (**v4)(a1: v4, a2: pConstraint);
    else
      (*(void (__thiscall **)(void *, const char *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v3 + 156))(
        a1: v3,
        a2: "ConstraintBroken",
        a3: 0,
        a4: 0,
        a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183140
// Name: public: void CPhysConstraint::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysConstraint::InputTurnOn(CPhysConstraint *this@<ecx>, int a2@<edi>, inputdata_t *inputdata)
{
  IPhysicsObject *v4; // eax
  IPhysicsObject *v5; // eax

  if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
    CPhysConstraint::ActivateConstraint(this, a2);
  if ( this->m_pConstraint != nullptr
    && this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint) != nullptr
    && this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint) != nullptr )
  {
    this->m_pConstraint->Activate(this: this->m_pConstraint);
    v4 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
    v4->Wake(this: v4);
    v5 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    v5->Wake(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101831C0
// Name: public: virtual void CPhysConstraint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPhysConstraint::Activate(CPhysConstraint *this@<ecx>, int a2@<edi>)
{
  CBaseEntity::Activate(this);
  if ( (this->m_spawnflags.m_Value & 0x10) == 0 && CPhysConstraint::ActivateConstraint(this, a2) == 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10183230
// Name: public: CPhysHinge::CPhysHinge(void)
// Source: json
//------------------------------------------------------------------------------
CPhysHinge *__thiscall CPhysHinge::CPhysHinge(CPhysHinge *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->IVPhysicsWatcher::IWatcherCallback::__vftable = (IVPhysicsWatcher_vtbl *)&IVPhysicsWatcher::`vftable';
  this->CPhysConstraint::CLogicalEntity::CServerOnlyEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysHinge_vtbl *)&CPhysHinge::`vftable'{for `CPhysConstraint'};
  this->IVPhysicsWatcher::IWatcherCallback::__vftable = (IVPhysicsWatcher_vtbl *)&CPhysHinge::`vftable'{for `IVPhysicsWatcher'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101832B0
// Name: public: virtual void CPhysHinge::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysHinge::DrawDebugGeometryOverlays(CPhysHinge *this)
{
  float v2; // xmm2_4
  float v3; // xmm3_4
  Vector target; // [esp+8h] [ebp-Ch] BYREF

  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    v2 = this->m_hinge.worldAxisDirection.z * 48.0;
    v3 = this->m_hinge.worldPosition.x + (float)(this->m_hinge.worldAxisDirection.x * 48.0);
    target.y = this->m_hinge.worldPosition.y + (float)(this->m_hinge.worldAxisDirection.y * 48.0);
    target.z = this->m_hinge.worldPosition.z + v2;
    target.x = v3;
    NDebugOverlay::Line(
      origin: &this->m_hinge.worldPosition,
      &target,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 0,
      duration: 0.0);
    if ( (this->m_debugOverlays & 0x2C) != 0 )
      DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10183370
// Name: public: virtual void CPhysHinge::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysHinge::Deactivate(CPhysHinge *this)
{
  IPhysicsObject *v2; // eax

  if ( (this->m_spawnflags.m_Value & 8) != 0
    && this->m_pConstraint != nullptr
    && this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint) != nullptr )
  {
    v2 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    v2->RemoveHinged(this: v2);
  }
  CPhysConstraint::Deactivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101833C0
// Name: public: CPhysBallSocket::CPhysBallSocket(void)
// Source: json
//------------------------------------------------------------------------------
CPhysBallSocket *__thiscall CPhysBallSocket::CPhysBallSocket(CPhysBallSocket *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->__vftable = (CPhysBallSocket_vtbl *)&CPhysBallSocket::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183420
// Name: public: virtual class IPhysicsConstraint __near * CPhysBallSocket::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysBallSocket::CreateConstraint(
        CPhysBallSocket *this,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  IPhysicsObject **pObjects; // esi
  constraint_ballsocketparams_t *p_ballsocket; // edi
  int m_Value; // ecx
  float v7; // xmm0_4
  IPhysicsObject *v8; // eax
  IPhysicsObject *v10; // [esp-18h] [ebp-50h]
  constraint_ballsocketparams_t ballsocket; // [esp+0h] [ebp-38h] BYREF
  IPhysicsObject **v12; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  pObjects = info->pObjects;
  ballsocket.constraint.forceLimit = 0.0;
  ballsocket.constraint.torqueLimit = 0.0;
  ballsocket.constraint.strength = 1.0;
  ballsocket.constraint.bodyMassScale[0] = 1.0;
  ballsocket.constraint.bodyMassScale[1] = 1.0;
  ballsocket.constraint.isActive = true;
  memset((void *)&ballsocket, 0, 24);
  p_ballsocket = &ballsocket;
  v12 = info->pObjects;
  for ( i = 2; i != 0; --i )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    (*pObjects)->WorldToLocal(this: *pObjects, a2: p_ballsocket->constraintPosition, a3: &this->m_vecAbsOrigin);
    ++pObjects;
    p_ballsocket = (constraint_ballsocketparams_t *)((char *)p_ballsocket + 12);
  }
  m_Value = this->m_spawnflags.m_Value;
  ballsocket.constraint.strength = 1.0;
  ballsocket.constraint.forceLimit = this->m_forceLimit * 0.45454544;
  ballsocket.constraint.bodyMassScale[0] = info->massScale[0];
  v7 = info->massScale[1];
  v10 = info->pObjects[1];
  v8 = *v12;
  ballsocket.constraint.isActive = (m_Value & 4) == 0;
  ballsocket.constraint.bodyMassScale[1] = v7;
  ballsocket.constraint.torqueLimit = 0.0;
  return physenv->CreateBallsocketConstraint(this: physenv, a2: v8, a3: v10, a4: pGroup, a5: &ballsocket);
}

//------------------------------------------------------------------------------
// Address: 0x10183540
// Name: public: CPhysSlideConstraint::CPhysSlideConstraint(void)
// Source: json
//------------------------------------------------------------------------------
CPhysSlideConstraint *__thiscall CPhysSlideConstraint::CPhysSlideConstraint(CPhysSlideConstraint *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->IVPhysicsWatcher::IWatcherCallback::__vftable = (IVPhysicsWatcher_vtbl *)&IVPhysicsWatcher::`vftable';
  this->CPhysConstraint::CLogicalEntity::CServerOnlyEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysSlideConstraint_vtbl *)&CPhysSlideConstraint::`vftable'{for `CPhysConstraint'};
  this->IVPhysicsWatcher::IWatcherCallback::__vftable = (IVPhysicsWatcher_vtbl *)&CPhysSlideConstraint::`vftable'{for `IVPhysicsWatcher'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101835D0
// Name: public: virtual void CPhysSlideConstraint::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysSlideConstraint::DrawDebugGeometryOverlays(CPhysSlideConstraint *this)
{
  unsigned int v2; // eax
  Vector mins; // [esp+10h] [ebp-18h] BYREF
  Vector maxs; // [esp+1Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    v2 = (unsigned int)this->m_iEFlags >> 11;
    maxs.x = 8.0;
    maxs.y = 8.0;
    maxs.z = 8.0;
    mins.x = -8.0;
    mins.y = -8.0;
    mins.z = -8.0;
    if ( (v2 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 0, g: 255, b: 0, a: 0, flDuration: 0.0);
    mins.x = 4.0;
    mins.y = 4.0;
    mins.z = 4.0;
    maxs.x = -4.0;
    maxs.y = -4.0;
    maxs.z = -4.0;
    NDebugOverlay::Box(origin: &this->m_axisEnd, mins: &maxs, maxs: &mins, r: 0, g: 0, b: 255, a: 0, flDuration: 0.0);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    NDebugOverlay::Line(
      origin: &this->m_vecAbsOrigin,
      target: &this->m_axisEnd,
      r: 255,
      g: 255,
      b: 0,
      noDepthTest: 0,
      duration: 0.0);
    if ( (this->m_debugOverlays & 0x2C) != 0 )
      DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10183770
// Name: public: CPhysFixed::CPhysFixed(void)
// Source: json
//------------------------------------------------------------------------------
CPhysFixed *__thiscall CPhysFixed::CPhysFixed(CPhysFixed *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->__vftable = (CPhysFixed_vtbl *)&CPhysFixed::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101837D0
// Name: public: void CPhysFixed::MoveToRefPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysFixed::MoveToRefPosition(CPhysFixed *this)
{
  IPhysicsObject *v2; // eax
  IPhysicsObject *v3; // esi
  void (__thiscall *LocalToWorld)(IPhysicsObject *, Vector *, const Vector *); // edx
  matrix3x4_t xformRef; // [esp+4h] [ebp-48h] BYREF
  Vector posWorld; // [esp+34h] [ebp-18h] BYREF
  Vector pos; // [esp+40h] [ebp-Ch] BYREF

  if ( this->m_pConstraint != nullptr )
  {
    this->m_pConstraint->GetConstraintTransform(this: this->m_pConstraint, a2: &xformRef, a3: nullptr);
    v2 = this->m_pConstraint->GetReferenceObject(this: this->m_pConstraint);
    v3 = v2;
    if ( v2 != nullptr && v2->IsMoveable(this: v2) )
    {
      LocalToWorld = v3->LocalToWorld;
      pos.x = xformRef.m_flMatVal[0][3];
      pos.y = xformRef.m_flMatVal[1][3];
      pos.z = xformRef.m_flMatVal[2][3];
      LocalToWorld(this: v3, a2: &posWorld, a3: &pos);
      CBaseEntity::SetAbsOrigin(this, absOrigin: &posWorld);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183860
// Name: public: virtual void CPhysFixed::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysFixed::DrawDebugGeometryOverlays(CPhysFixed *this)
{
  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    CPhysFixed::MoveToRefPosition(this);
    if ( (this->m_debugOverlays & 0x2C) != 0 )
      DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x101838A0
// Name: public: virtual int CPhysFixed::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysFixed::DrawDebugTextOverlays(CPhysFixed *this)
{
  if ( (this->m_debugOverlays & 1) != 0 )
    CPhysFixed::MoveToRefPosition(this);
  return CPhysConstraint::DrawDebugTextOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10183910
// Name: public: CPhysPulley::CPhysPulley(void)
// Source: json
//------------------------------------------------------------------------------
CPhysPulley *__thiscall CPhysPulley::CPhysPulley(CPhysPulley *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->__vftable = (CPhysPulley_vtbl *)&CPhysPulley::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183970
// Name: public: virtual void CPhysPulley::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysPulley::DrawDebugGeometryOverlays(CPhysPulley *this)
{
  IPhysicsConstraint *m_pConstraint; // ecx
  int v3; // eax
  IPhysicsObject *v4; // eax
  matrix3x4_t matrix; // [esp+14h] [ebp-6Ch] BYREF
  Vector mins; // [esp+44h] [ebp-3Ch] BYREF
  Vector maxs; // [esp+50h] [ebp-30h] BYREF
  Vector attachPos; // [esp+5Ch] [ebp-24h] BYREF
  Vector refPos; // [esp+68h] [ebp-18h] BYREF
  Vector origin; // [esp+74h] [ebp-Ch] BYREF
  int savedregs; // [esp+80h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    origin.z = this->m_vecAbsOrigin.z;
    m_pConstraint = this->m_pConstraint;
    attachPos.z = origin.z;
    *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    refPos = origin;
    *(_QWORD *)&attachPos.x = *(_QWORD *)&origin.x;
    v3 = (int)m_pConstraint->GetReferenceObject(this: m_pConstraint);
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, matrix3x4_t *))(*(_DWORD *)v3 + 196))(a1: v3, a2: &matrix);
      VectorTransform(in1: &this->m_offset[0].x, in2: &matrix, out: &refPos.x);
    }
    v4 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    if ( v4 != nullptr )
    {
      v4->GetPositionMatrix(this: v4, a2: &matrix);
      VectorTransform(in1: &this->m_offset[1].x, in2: &matrix, out: &attachPos.x);
    }
    NDebugOverlay::Line(origin: &refPos, target: &origin, r: 0, g: 255, b: 0, noDepthTest: 0, duration: 0.0);
    NDebugOverlay::Line(&origin, target: &this->m_position2, r: 128, g: 128, b: 128, noDepthTest: 0, duration: 0.0);
    NDebugOverlay::Line(
      origin: &this->m_position2,
      target: &attachPos,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 0,
      duration: 0.0);
    maxs.x = 8.0;
    maxs.y = 8.0;
    maxs.z = 8.0;
    mins.x = -8.0;
    mins.y = -8.0;
    mins.z = -8.0;
    NDebugOverlay::Box(&origin, &mins, &maxs, r: 128, g: 255, b: 128, a: 32, flDuration: 0.0);
    mins.x = 8.0;
    mins.y = 8.0;
    mins.z = 8.0;
    maxs.x = -8.0;
    maxs.y = -8.0;
    maxs.z = -8.0;
    NDebugOverlay::Box(
      origin: &this->m_position2,
      mins: &maxs,
      maxs: &mins,
      r: 255,
      g: 128,
      b: 128,
      a: 32,
      flDuration: 0.0);
    if ( (this->m_debugOverlays & 0x2C) != 0 )
      DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10183B80
// Name: public: CPhysLength::CPhysLength(void)
// Source: json
//------------------------------------------------------------------------------
CPhysLength *__thiscall CPhysLength::CPhysLength(CPhysLength *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->__vftable = (CPhysLength_vtbl *)&CPhysLength::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183BE0
// Name: public: virtual void CPhysLength::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysLength::DrawDebugGeometryOverlays(CPhysLength *this)
{
  IPhysicsConstraint *m_pConstraint; // ecx
  int v3; // eax
  IPhysicsObject *v4; // eax
  float m_totalLength; // xmm3_4
  matrix3x4_t matrix; // [esp+10h] [ebp-64h] BYREF
  Vector mid; // [esp+40h] [ebp-34h] BYREF
  Vector dir; // [esp+4Ch] [ebp-28h] BYREF
  Vector attachPos; // [esp+58h] [ebp-1Ch] BYREF
  Vector refPos; // [esp+64h] [ebp-10h] BYREF
  float len; // [esp+70h] [ebp-4h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 0x2C) != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    refPos.z = this->m_vecAbsOrigin.z;
    m_pConstraint = this->m_pConstraint;
    attachPos.z = refPos.z;
    *(_QWORD *)&refPos.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    *(_QWORD *)&attachPos.x = *(_QWORD *)&refPos.x;
    v3 = (int)m_pConstraint->GetReferenceObject(this: m_pConstraint);
    if ( v3 != 0 )
    {
      (*(void (__thiscall **)(int, matrix3x4_t *))(*(_DWORD *)v3 + 196))(a1: v3, a2: &matrix);
      VectorTransform(in1: &this->m_offset[0].x, in2: &matrix, out: &refPos.x);
    }
    v4 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    if ( v4 != nullptr )
    {
      v4->GetPositionMatrix(this: v4, a2: &matrix);
      VectorTransform(in1: &this->m_offset[1].x, in2: &matrix, out: &attachPos.x);
    }
    dir.x = attachPos.x - refPos.x;
    dir.y = attachPos.y - refPos.y;
    dir.z = attachPos.z - refPos.z;
    len = VectorNormalize(vec: &dir);
    m_totalLength = this->m_totalLength;
    if ( len <= m_totalLength )
    {
      NDebugOverlay::Line(origin: &refPos, target: &attachPos, r: 0, g: 255, b: 0, noDepthTest: 0, duration: 0.0);
    }
    else
    {
      mid.x = (float)(dir.x * m_totalLength) + refPos.x;
      mid.y = (float)(m_totalLength * dir.y) + refPos.y;
      mid.z = (float)(dir.z * m_totalLength) + refPos.z;
      NDebugOverlay::Line(origin: &refPos, target: &mid, r: 0, g: 255, b: 0, noDepthTest: 0, duration: 0.0);
      NDebugOverlay::Line(origin: &mid, target: &attachPos, r: 255, g: 0, b: 0, noDepthTest: 0, duration: 0.0);
    }
    if ( (this->m_debugOverlays & 0x2C) != 0 )
      DrawConstraintObjectsAxes(pConstraint: this->m_pConstraint, pConstraintEntity: this);
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10183DB0
// Name: public: CRagdollConstraint::CRagdollConstraint(void)
// Source: json
//------------------------------------------------------------------------------
CRagdollConstraint *__thiscall CRagdollConstraint::CRagdollConstraint(CRagdollConstraint *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->m_OnBreak.m_Value.iVal = 0;
  this->m_OnBreak.m_Value.eVal.m_Index = -1;
  this->m_OnBreak.m_Value.fieldType = FIELD_VOID;
  this->m_pConstraint = nullptr;
  this->m_nameAttach1.pszValue = nullptr;
  this->m_nameAttach2.pszValue = nullptr;
  this->m_forceLimit = 0.0;
  this->m_torqueLimit = 0.0;
  this->m_teleportTick = -1;
  this->m_minTeleportDistance = 0.0;
  this->__vftable = (CRagdollConstraint_vtbl *)&CRagdollConstraint::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10183E90
// Name: public: virtual void CAnchorList::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnchorList::LevelShutdownPostEntity(CAnchorList *this)
{
  bool v2; // sf
  constraint_anchor_t *m_pMemory; // ecx

  v2 = this->m_list.m_Memory.m_nGrowSize < 0;
  this->m_list.m_Size = 0;
  if ( v2 )
  {
    this->m_list.m_pElements = this->m_list.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_list.m_Memory.m_pMemory);
      this->m_list.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_list.m_Memory.m_pMemory;
    this->m_list.m_Memory.m_nAllocationCount = 0;
    this->m_list.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183EE0
// Name: public: void CAnchorList::AddToList(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnchorList::AddToList(CAnchorList *this, CBaseEntity *pEntity, float massScale)
{
  CUtlVector<constraint_anchor_t,CUtlMemory<constraint_anchor_t,int> > *p_m_list; // esi
  int v4; // ecx
  unsigned int m_Index; // eax
  int v6; // esi
  IHandleEntity *m_pEntity; // ecx

  p_m_list = &this->m_list;
  v4 = CUtlVector<constraint_anchor_t,CUtlMemory<constraint_anchor_t,int>>::InsertBefore(
         this: &this->m_list,
         elem: this->m_list.m_Size);
  m_Index = pEntity->m_pParent.m_Index;
  v6 = (int)&p_m_list->m_Memory.m_pMemory[v4];
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
    *(_DWORD *)(v6 + 12) = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  else
    *(_DWORD *)(v6 + 12) = -1;
  *(_DWORD *)(v6 + 16) = pEntity->m_iParentAttachment.m_Value;
  *(_DWORD *)(v6 + 20) = pEntity->m_iName.m_Value.pszValue;
  *(CNetworkVectorXY_SeparateZBase<Vector,CBaseEntity::NetworkVar_m_vecOrigin> *)v6 = pEntity->m_vecOrigin;
  *(float *)(v6 + 24) = massScale;
}

//------------------------------------------------------------------------------
// Address: 0x10183F90
// Name: public: virtual void CConstraintAnchor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConstraintAnchor::Spawn(CConstraintAnchor *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CAnchorList::AddToList(this: &g_AnchorList, pEntity: this, massScale: this->m_massScale);
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183FF0
// Name: public: virtual class IPhysicsConstraint __near * CPhysHinge::CreateConstraint(class IPhysicsConstraintGroup __near *,struct hl_constraint_info_t const __near &)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__thiscall CPhysHinge::CreateConstraint(
        CPhysHinge *this,
        IPhysicsConstraintGroup *pGroup,
        const hl_constraint_info_t *info)
{
  const hl_constraint_info_t *v5; // ebx
  float v6; // xmm1_4
  int m_Value; // eax
  const hl_constraint_info_t *v8; // edx
  edict_t *m_pPev; // ecx

  if ( vec3_origin.x == this->m_hinge.worldAxisDirection.x
    && vec3_origin.y == this->m_hinge.worldAxisDirection.y
    && vec3_origin.z == this->m_hinge.worldAxisDirection.z )
  {
    DevMsg(a1: "ERROR: Hinge with bad data!!!\n");
    return nullptr;
  }
  else
  {
    this->m_hinge.constraint.bodyMassScale[0] = 1.0;
    this->m_hinge.constraint.bodyMassScale[1] = 1.0;
    this->m_hinge.constraint.forceLimit = 0.0;
    this->m_hinge.constraint.torqueLimit = 0.0;
    this->m_hinge.constraint.strength = 1.0;
    this->m_hinge.constraint.isActive = true;
    this->m_hinge.constraint.forceLimit = this->m_forceLimit * 0.45454544;
    this->m_hinge.constraint.torqueLimit = this->m_torqueLimit * 0.45454544;
    v5 = info;
    this->m_hinge.constraint.isActive = (this->m_spawnflags.m_Value & 4) == 0;
    *(_QWORD *)this->m_hinge.constraint.bodyMassScale = *(_QWORD *)v5->massScale;
    this->m_hinge.constraint.strength = 1.0;
    v6 = this->m_hingeFriction * 1000.0;
    this->m_hinge.hingeAxis.minRotation = 0.0;
    this->m_hinge.hingeAxis.maxRotation = 0.0;
    this->m_hinge.hingeAxis.angularVelocity = 0.0;
    this->m_hinge.hingeAxis.torque = v6;
    info = nullptr;
    if ( CPhysHinge::IsWorldHinge(this, info: v5, pAxisOut: (int *)&info) != 0 )
    {
      v5->pObjects[1]->BecomeHinged(this: v5->pObjects[1], a2: (int)info);
    }
    else
    {
      m_Value = this->m_spawnflags.m_Value;
      v8 = (const hl_constraint_info_t *)(m_Value & 0xFFFFFFF7);
      info = (const hl_constraint_info_t *)(m_Value & 0xFFFFFFF7);
      if ( m_Value != (m_Value & 0xFFFFFFF7) )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
            v8 = info;
          }
        }
        this->m_spawnflags.m_Value = (int)v8;
      }
    }
    return physenv->CreateHingeConstraint(
             this: physenv,
             a2: v5->pObjects[0],
             a3: v5->pObjects[1],
             a4: pGroup,
             a5: &this->m_hinge);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101841B0
// Name: public: virtual void CPhysHinge::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysHinge::Spawn(CPhysHinge *this)
{
  Vector *p_worldAxisDirection; // edi
  const char *pszValue; // eax
  const char *v4; // edx
  float z; // xmm0_4
  float y; // xmm0_4
  float v7; // xmm0_4
  masscenteroverride_t params; // [esp+Ch] [ebp-20h] BYREF

  this->m_hinge.worldPosition = this->m_vecOrigin.m_Value;
  p_worldAxisDirection = &this->m_hinge.worldAxisDirection;
  this->m_hinge.worldAxisDirection.x = this->m_hinge.worldAxisDirection.x - this->m_vecOrigin.m_Value.x;
  this->m_hinge.worldAxisDirection.y = this->m_hinge.worldAxisDirection.y - this->m_vecOrigin.m_Value.y;
  this->m_hinge.worldAxisDirection.z = this->m_hinge.worldAxisDirection.z - this->m_vecOrigin.m_Value.z;
  VectorNormalize(vec: &this->m_hinge.worldAxisDirection);
  UTIL_SnapDirectionToAxis(direction: p_worldAxisDirection, epsilon: 0.0020000001);
  this->m_hinge.hingeAxis.minRotation = 0.0;
  this->m_hinge.hingeAxis.maxRotation = 0.0;
  this->m_hinge.hingeAxis.angularVelocity = 0.0;
  this->m_hinge.hingeAxis.torque = 0.0;
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    pszValue = this->m_nameAttach1.pszValue;
    if ( pszValue == nullptr )
    {
      v4 = this->m_nameAttach2.pszValue;
      params.center = this->m_hinge.worldPosition;
      params.axis.x = p_worldAxisDirection->x;
      params.axis.y = p_worldAxisDirection->y;
      z = p_worldAxisDirection->z;
      params.entityName.pszValue = v4;
      params.axis.z = z;
      params.alignType = 1;
      PhysSetMassCenterOverride(override: &params);
      this->Precache(this);
      return;
    }
    if ( this->m_nameAttach2.pszValue == nullptr )
    {
      params.center = this->m_hinge.worldPosition;
      params.axis.x = p_worldAxisDirection->x;
      y = p_worldAxisDirection->y;
      params.alignType = 1;
      params.axis.y = y;
      v7 = p_worldAxisDirection->z;
      params.entityName.pszValue = pszValue;
      params.axis.z = v7;
      PhysSetMassCenterOverride(override: &params);
      this->Precache(this);
      return;
    }
    CBaseEntity::RemoveSpawnFlags(this, nFlags: 8);
  }
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x101846E0
// Name: public: void CPhysConstraint::OnBreak(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::OnBreak(CPhysConstraint *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  __int64 v5; // xmm0_8
  IPhysicsConstraint *m_pConstraint; // ecx
  IPhysicsObject *v7; // eax
  IPhysicsObject *v8; // edi
  IPhysicsObject *v9; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  const char *pszValue; // eax
  edict_t *m_pPev; // eax
  signed int v15; // eax
  float attenuation[3]; // [esp+1Ch] [ebp-98h] BYREF
  CPASAttenuationFilter filter; // [esp+28h] [ebp-8Ch] BYREF
  EmitSound_t ep; // [esp+48h] [ebp-6Ch] BYREF
  Vector origin; // [esp+90h] [ebp-24h] BYREF
  Vector refPos; // [esp+9Ch] [ebp-18h] BYREF
  Vector attachPos; // [esp+A8h] [ebp-Ch] BYREF
  int savedregs; // [esp+B4h] [ebp+0h] BYREF

  this->Deactivate(this);
  if ( this->m_breakSound.pszValue != nullptr )
  {
    v2 = (const Vector *)((int (__thiscall *)(CPhysConstraint *))this->GetSoundEmissionOrigin)(a1: this);
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
    GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    v4 = (const Vector *)((int (__thiscall *)(CPhysConstraint *, float *, int))GetSoundEmissionOrigin)(
                           a1: this,
                           a2: attenuation,
                           a3: 1067450368);
    CPASAttenuationFilter::Filter(
      this: &filter,
      a2: (int)&savedregs,
      origin: v4,
      attenuation: COERCE_FLOAT(attenuation));
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v5 = *(_QWORD *)&this->m_vecAbsOrigin.x;
    origin.z = this->m_vecAbsOrigin.z;
    m_pConstraint = this->m_pConstraint;
    attachPos.z = origin.z;
    *(_QWORD *)&origin.x = v5;
    *(_QWORD *)&refPos.x = v5;
    refPos.z = origin.z;
    *(_QWORD *)&attachPos.x = v5;
    v7 = m_pConstraint->GetReferenceObject(this: m_pConstraint);
    v8 = v7;
    if ( v7 != nullptr && v7 != g_PhysWorldObject )
    {
      v7->GetPosition(this: v7, a2: &refPos, a3: nullptr);
      attachPos = refPos;
    }
    v9 = this->m_pConstraint->GetAttachedObject(this: this->m_pConstraint);
    if ( v9 == nullptr
      || v9 == g_PhysWorldObject
      || (v9->GetPosition(this: v9, a2: &attachPos, a3: nullptr), v8 != nullptr) && v8 != g_PhysWorldObject )
    {
      z = attachPos.z;
      y = attachPos.y;
      x = attachPos.x;
    }
    else
    {
      x = attachPos.x;
      y = attachPos.y;
      z = attachPos.z;
      refPos = attachPos;
    }
    ep.m_hSoundScriptHandle = -1;
    pszValue = this->m_breakSound.pszValue;
    origin.x = (float)(x + refPos.x) * 0.5;
    origin.y = (float)(y + refPos.y) * 0.5;
    origin.z = (float)(z + refPos.z) * 0.5;
    ep.m_nFlags = 0;
    ep.m_nPitch = 100;
    ep.m_flSoundTime = 0.0;
    ep.m_pflSoundDuration = nullptr;
    *(_WORD *)&ep.m_bEmitCloseCaption = 1;
    ep.m_bWarnOnDirectWaveReference = false;
    ep.m_nSpeakerEntity = -1;
    memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
    ep.m_nSoundEntryVersion = 1;
    ep.m_nChannel = 6;
    ep.m_pSoundName = pszValue;
    if ( pszValue == nullptr )
      ep.m_pSoundName = locale;
    m_pPev = this->m_Network.m_pPev;
    ep.m_flVolume = 1.0;
    ep.m_SoundLevel = SNDLVL_STATIC;
    ep.m_pOrigin = &origin;
    if ( m_pPev != nullptr )
      v15 = m_pPev - gpGlobals->pEdicts;
    else
      v15 = 0;
    CBaseEntity::EmitSound(&filter, iEntIndex: v15, params: &ep);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  COutputEvent::FireOutput(this: &this->m_OnBreak, pActivator: this, pCaller: this, fDelay: 0.0);
  PhysCallbackRemove(pRemove: &this->m_Network);
}

//------------------------------------------------------------------------------
// Address: 0x10184970
// Name: public: void CPhysConstraint::InputBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysConstraint::InputBreak(CPhysConstraint *this, inputdata_t *inputdata)
{
  if ( this->m_pConstraint != nullptr )
    this->m_pConstraint->Deactivate(this: this->m_pConstraint);
  CPhysConstraint::OnBreak(this);
}

//------------------------------------------------------------------------------
// Address: 0x101849A0
// Name: public: void CPhysConstraint::InputOnBreak(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysConstraint::InputOnBreak(CPhysConstraint *this, inputdata_t *inputdata)
{
  CPhysConstraint::OnBreak(this);
}

//------------------------------------------------------------------------------
// Address: 0x10406DA0
// Name: CConstraintAnchor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CConstraintAnchor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CConstraintAnchor>();
  CConstraintAnchor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406DD0
// Name: CPhysConstraintSystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysConstraintSystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysConstraintSystem>();
  CPhysConstraintSystem_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406E00
// Name: CPhysConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysConstraint>(__formal: nullptr);
  CPhysConstraint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406E10
// Name: CPhysHinge_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysHinge_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysHinge>(__formal: nullptr);
  CPhysHinge_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406E80
// Name: CPhysSlideConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysSlideConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysSlideConstraint>(__formal: nullptr);
  CPhysSlideConstraint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406EB0
// Name: CPhysPulley_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysPulley_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysPulley>(__formal: nullptr);
  CPhysPulley_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406EE0
// Name: CPhysLength_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysLength_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysLength>(__formal: nullptr);
  CPhysLength_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406F10
// Name: CRagdollConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollConstraint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollConstraint>(__formal: nullptr);
  CRagdollConstraint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101849B0
// Name: struct datamap_t __near * DataMapInit<class CPhysConstraint>(class CPhysConstraint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysConstraint>()
{
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S4_43 & 1) == 0 )
  {
    _S4_43 |= 1u;
    nameHolder_298.m_pszBase = "CPhysConstraint";
    nameHolder_298.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_298.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_298.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_298.m_Names.m_Size = 0;
    nameHolder_298.m_Names.m_pElements = nullptr;
    nameHolder_298.m_nLenBase = 15;
    atexit(func: DataMapInit_CPhysConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysConstraint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_43 & 2) == 0 )
  {
    _S4_43 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)dataDesc_285[2].flatOffset = 0;
    dataDesc_285[1].pSaveRestoreOps = PhysObjSaveRestoreOps;
    *(_QWORD *)dataDesc_285[3].flatOffset = 0;
    dataDesc_285[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_285[1].td = 0;
    *(_QWORD *)&dataDesc_285[1].override_field = 0;
    *(_QWORD *)&dataDesc_285[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_285[1].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_285[4].flatOffset = 0;
    dataDesc_285[1].inputFunc = nullptr;
    dataDesc_285[2].fieldType = FIELD_STRING;
    dataDesc_285[2].fieldName = "m_nameSystem";
    dataDesc_285[2].fieldOffset = 868;
    dataDesc_285[2].flags = 6;
    dataDesc_285[2].externalName = "constraintsystem";
    dataDesc_285[2].pSaveRestoreOps = nullptr;
    dataDesc_285[2].inputFunc = nullptr;
    dataDesc_285[2].td = nullptr;
    dataDesc_285[2].fieldSizeInBytes = 4;
    dataDesc_285[2].override_field = nullptr;
    dataDesc_285[2].override_count = 0;
    dataDesc_285[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_285[2].flatGroup = 0;
    dataDesc_285[3].fieldType = FIELD_STRING;
    dataDesc_285[3].fieldName = "m_nameAttach1";
    dataDesc_285[3].fieldOffset = 856;
    dataDesc_285[3].fieldSize = 1;
    dataDesc_285[3].flags = 6;
    dataDesc_285[3].externalName = "attach1";
    dataDesc_285[3].pSaveRestoreOps = nullptr;
    dataDesc_285[3].inputFunc = nullptr;
    dataDesc_285[3].td = nullptr;
    dataDesc_285[3].fieldSizeInBytes = 4;
    dataDesc_285[3].override_field = nullptr;
    dataDesc_285[3].override_count = 0;
    dataDesc_285[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_285[3].flatGroup = 0;
    dataDesc_285[4].fieldType = FIELD_STRING;
    dataDesc_285[4].fieldName = "m_nameAttach2";
    dataDesc_285[4].fieldOffset = 860;
    dataDesc_285[4].fieldSize = 1;
    dataDesc_285[4].flags = 6;
    dataDesc_285[4].externalName = "attach2";
    dataDesc_285[4].pSaveRestoreOps = nullptr;
    dataDesc_285[4].inputFunc = nullptr;
    dataDesc_285[4].td = nullptr;
    dataDesc_285[4].fieldSizeInBytes = 4;
    dataDesc_285[4].override_field = nullptr;
    dataDesc_285[4].override_count = 0;
    dataDesc_285[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_285[4].flatGroup = 0;
    dataDesc_285[5].fieldType = FIELD_SOUNDNAME;
    dataDesc_285[5].fieldName = "m_breakSound";
    dataDesc_285[5].fieldOffset = 864;
    dataDesc_285[5].fieldSize = 1;
    dataDesc_285[5].flags = 6;
    dataDesc_285[5].externalName = "breaksound";
    dataDesc_285[5].pSaveRestoreOps = nullptr;
    dataDesc_285[5].inputFunc = nullptr;
    dataDesc_285[5].td = nullptr;
    dataDesc_285[5].fieldSizeInBytes = 4;
    dataDesc_285[5].override_field = nullptr;
    dataDesc_285[5].override_count = 0;
    dataDesc_285[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_285[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_285[5].flatGroup = 0;
    dataDesc_285[6].fieldType = FIELD_FLOAT;
    dataDesc_285[6].fieldTolerance = 0.0;
    dataDesc_285[7].fieldTolerance = 0.0;
    dataDesc_285[8].fieldTolerance = 0.0;
    dataDesc_285[6].flags = 6;
    dataDesc_285[6].fieldSizeInBytes = 4;
    dataDesc_285[7].flags = 6;
    dataDesc_285[7].fieldSizeInBytes = 4;
    dataDesc_285[8].flags = 6;
    dataDesc_285[8].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_285[8].flatOffset = 0;
    dataDesc_285[9].flags = 22;
    dataDesc_285[9].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)dataDesc_285[6].flatOffset = 0;
    *(_QWORD *)&dataDesc_285[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_285[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_285[9].override_count = 0;
    *(_QWORD *)dataDesc_285[9].flatOffset = 0;
    dataDesc_285[6].fieldName = "m_forceLimit";
    dataDesc_285[6].fieldOffset = 872;
    dataDesc_285[6].fieldSize = 1;
    dataDesc_285[6].externalName = "forcelimit";
    dataDesc_285[6].pSaveRestoreOps = nullptr;
    dataDesc_285[6].inputFunc = nullptr;
    dataDesc_285[6].td = nullptr;
    dataDesc_285[6].override_field = nullptr;
    dataDesc_285[6].override_count = 0;
    *(_DWORD *)&dataDesc_285[6].flatGroup = 0;
    dataDesc_285[7].fieldType = FIELD_FLOAT;
    dataDesc_285[7].fieldName = "m_torqueLimit";
    dataDesc_285[7].fieldOffset = 876;
    dataDesc_285[7].fieldSize = 1;
    dataDesc_285[7].externalName = "torquelimit";
    dataDesc_285[7].pSaveRestoreOps = nullptr;
    dataDesc_285[7].inputFunc = nullptr;
    dataDesc_285[7].td = nullptr;
    dataDesc_285[7].override_field = nullptr;
    dataDesc_285[7].override_count = 0;
    *(_QWORD *)dataDesc_285[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_285[7].flatGroup = 0;
    dataDesc_285[8].fieldType = FIELD_FLOAT;
    dataDesc_285[8].fieldName = "m_minTeleportDistance";
    dataDesc_285[8].fieldOffset = 884;
    dataDesc_285[8].fieldSize = 1;
    dataDesc_285[8].externalName = "teleportfollowdistance";
    dataDesc_285[8].pSaveRestoreOps = nullptr;
    dataDesc_285[8].inputFunc = nullptr;
    dataDesc_285[8].td = nullptr;
    dataDesc_285[8].override_field = nullptr;
    dataDesc_285[8].override_count = 0;
    *(_DWORD *)&dataDesc_285[8].flatGroup = 0;
    dataDesc_285[9].fieldType = FIELD_CUSTOM;
    dataDesc_285[9].fieldName = "m_OnBreak";
    dataDesc_285[9].fieldOffset = 888;
    dataDesc_285[9].fieldSize = 1;
    dataDesc_285[9].externalName = "OnBreak";
    *(_DWORD *)&dataDesc_285[9].flatGroup = 0;
    dataDesc_285[10].fieldType = FIELD_VOID;
    dataDesc_285[10].fieldName = "InputBreak";
    dataDesc_285[10].fieldOffset = 0;
    dataDesc_285[10].fieldSize = 1;
    dataDesc_285[10].flags = 8;
    dataDesc_285[10].externalName = "Break";
    dataDesc_285[10].pSaveRestoreOps = nullptr;
    dataDesc_285[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysConstraint::InputBreak;
    *(_QWORD *)&dataDesc_285[10].td = 0;
    *(_QWORD *)&dataDesc_285[10].override_field = 0;
    *(_QWORD *)&dataDesc_285[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_285[10].flatOffset[1] = 0;
    dataDesc_285[11].fieldType = FIELD_VOID;
    dataDesc_285[11].fieldName = "InputOnBreak";
    dataDesc_285[11].fieldOffset = 0;
    dataDesc_285[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_285[11].td = 0;
    *(_QWORD *)&dataDesc_285[11].override_field = 0;
    *(_QWORD *)&dataDesc_285[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_285[11].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_285[12].td = 0;
    *(_QWORD *)&dataDesc_285[12].override_field = 0;
    *(_QWORD *)&dataDesc_285[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_285[12].flatOffset[1] = 0;
    dataDesc_285[11].flags = 8;
    dataDesc_285[11].externalName = "ConstraintBroken";
    dataDesc_285[11].pSaveRestoreOps = nullptr;
    dataDesc_285[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysConstraint::InputOnBreak;
    dataDesc_285[12].fieldType = FIELD_VOID;
    dataDesc_285[12].fieldName = "InputTurnOn";
    dataDesc_285[12].fieldOffset = 0;
    *(_DWORD *)&dataDesc_285[12].fieldSize = 524289;
    dataDesc_285[12].externalName = "TurnOn";
    dataDesc_285[12].pSaveRestoreOps = nullptr;
    dataDesc_285[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysConstraint::InputTurnOn;
    dataDesc_285[13].fieldType = FIELD_VOID;
    dataDesc_285[13].fieldName = "InputTurnOff";
    dataDesc_285[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_285[13].fieldSize = 524289;
    dataDesc_285[13].externalName = "TurnOff";
    dataDesc_285[13].pSaveRestoreOps = nullptr;
    dataDesc_285[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAmbientGeneric::InputToggleSound;
    *(_QWORD *)&dataDesc_285[13].td = 0;
    *(_QWORD *)&dataDesc_285[13].override_field = 0;
    *(_QWORD *)&dataDesc_285[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_285[13].flatOffset[1] = 0;
  }
  CPhysConstraint::m_DataMap.dataNumFields = 13;
  CPhysConstraint::m_DataMap.dataDesc = &dataDesc_285[1];
  return &CPhysConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10184FA0
// Name: struct datamap_t __near * DataMapInit<class CPhysHinge>(class CPhysHinge __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysHinge>()
{
  if ( (_S5_21 & 1) == 0 )
  {
    _S5_21 |= 1u;
    nameHolder_299.m_pszBase = "CPhysHinge";
    nameHolder_299.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_299.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_299.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_299.m_Names.m_Size = 0;
    nameHolder_299.m_Names.m_pElements = nullptr;
    nameHolder_299.m_nLenBase = 10;
    atexit(func: DataMapInit_CPhysHinge__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysHinge::m_DataMap.baseMap = &CPhysConstraint::m_DataMap;
  CPhysHinge::m_DataMap.dataNumFields = 6;
  CPhysHinge::m_DataMap.dataDesc = &dataDesc_286[1];
  return &CPhysHinge::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10185020
// Name: struct datamap_t __near * DataMapInit<class CPhysSlideConstraint>(class CPhysSlideConstraint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysSlideConstraint>()
{
  if ( (_S6_16 & 1) == 0 )
  {
    _S6_16 |= 1u;
    nameHolder_300.m_pszBase = "CPhysSlideConstraint";
    nameHolder_300.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_300.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_300.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_300.m_Names.m_Size = 0;
    nameHolder_300.m_Names.m_pElements = nullptr;
    nameHolder_300.m_nLenBase = 20;
    atexit(func: DataMapInit_CPhysSlideConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysSlideConstraint::m_DataMap.baseMap = &CPhysConstraint::m_DataMap;
  CPhysSlideConstraint::m_DataMap.dataNumFields = 4;
  CPhysSlideConstraint::m_DataMap.dataDesc = &dataDesc_287[1];
  return &CPhysSlideConstraint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101850A0
// Name: struct datamap_t __near * DataMapInit<class CPhysPulley>(class CPhysPulley __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysPulley>()
{
  if ( (_S7_9 & 1) == 0 )
  {
    _S7_9 |= 1u;
    nameHolder_301.m_pszBase = "CPhysPulley";
    nameHolder_301.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_301.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_301.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_301.m_Names.m_Size = 0;
    nameHolder_301.m_Names.m_pElements = nullptr;
    nameHolder_301.m_nLenBase = 11;
    atexit(func: DataMapInit_CPhysPulley__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysPulley::m_DataMap.baseMap = &CPhysConstraint::m_DataMap;
  CPhysPulley::m_DataMap.dataNumFields = 4;
  CPhysPulley::m_DataMap.dataDesc = &dataDesc_288[1];
  return &CPhysPulley::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10185120
// Name: struct datamap_t __near * DataMapInit<class CPhysLength>(class CPhysLength __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysLength>()
{
  if ( (_S8_7 & 1) == 0 )
  {
    _S8_7 |= 1u;
    nameHolder_302.m_pszBase = "CPhysLength";
    nameHolder_302.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_302.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_302.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_302.m_Names.m_Size = 0;
    nameHolder_302.m_Names.m_pElements = nullptr;
    nameHolder_302.m_nLenBase = 11;
    atexit(func: DataMapInit_CPhysLength__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysLength::m_DataMap.baseMap = &CPhysConstraint::m_DataMap;
  CPhysLength::m_DataMap.dataNumFields = 5;
  CPhysLength::m_DataMap.dataDesc = &dataDesc_289[1];
  return &CPhysLength::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101851A0
// Name: struct datamap_t __near * DataMapInit<class CRagdollConstraint>(class CRagdollConstraint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollConstraint>()
{
  if ( (_S9_4 & 1) == 0 )
  {
    _S9_4 |= 1u;
    nameHolder_303.m_pszBase = "CRagdollConstraint";
    nameHolder_303.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_303.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_303.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_303.m_Names.m_Size = 0;
    nameHolder_303.m_Names.m_pElements = nullptr;
    nameHolder_303.m_nLenBase = 18;
    atexit(func: DataMapInit_CRagdollConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollConstraint::m_DataMap.baseMap = &CPhysConstraint::m_DataMap;
  CRagdollConstraint::m_DataMap.dataNumFields = 9;
  CRagdollConstraint::m_DataMap.dataDesc = &dataDesc_290[1];
  return &CRagdollConstraint::m_DataMap;
}
