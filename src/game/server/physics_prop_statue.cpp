// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_prop_statue.cpp
// Functions: 55
// ============================================================

#include "game\server\physics_prop_statue.h"

//------------------------------------------------------------------------------
// Address: 0x10132470
// Name: public: virtual float CBreakableProp::GetDmgModBullet(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetDmgModBullet(CBreakable *this)
{
  return *(float *)&this->m_aThinkFunctions.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x10132480
// Name: public: virtual float CBreakableProp::GetDmgModExplosive(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetDmgModExplosive(CBreakable *this)
{
  return *(float *)&this->m_aThinkFunctions.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101324A0
// Name: public: virtual float CBreakableProp::GetExplosiveDamage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetExplosiveDamage(CBreakable *this)
{
  return *(float *)&this->m_fEffects.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10132500
// Name: public: virtual struct string_t CBreakableProp::GetPhysicsDamageTable(void)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBreakableProp::GetPhysicsDamageTable(CBreakable *this, ResponseContext_t **a2)
{
  *a2 = this->m_ResponseContexts.m_Memory.m_pMemory;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x10132550
// Name: public: virtual int CBreakableProp::GetBreakableSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakableProp::GetBreakableSkin(CChoreoChannel *this)
{
  return this->m_Events.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10132590
// Name: public: virtual void CBreakableProp::SetMaxBreakableSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetMaxBreakableSize(CBreakable *this, string_t iszBase)
{
  this->m_ResponseContexts.m_pElements = (ResponseContext_t *)iszBase.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x101A2F70
// Name: public: virtual class ServerClass __near * CStatueProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CStatueProp::GetServerClass(CStatueProp *this)
{
  return &g_CStatueProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101A2F80
// Name: public: virtual struct datamap_t __near * CStatueProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CStatueProp::GetDataDescMap(CStatueProp *this)
{
  return &CStatueProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101A2F90
// Name: public: virtual int CStatueProp::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __thiscall CStatueProp::OnTakeDamage(CStatueProp *this, const CTakeDamageInfo *info)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  return CPhysicsProp::OnTakeDamage(this, a2: COERCE_FLOAT(&savedregs), info);
}

//------------------------------------------------------------------------------
// Address: 0x101A2FA0
// Name: public: virtual void CStatueProp::Freeze(float,class CBaseEntity __near *,struct Ray_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::Freeze(CStatueProp *this, float flFreezeAmount, CBaseEntity *pFreezer, Ray_t *pFreezeRay)
{
  const CTakeDamageInfo *v5; // eax
  CTakeDamageInfo v6; // [esp+14h] [ebp-5Ch] BYREF

  v5 = CTakeDamageInfo::CTakeDamageInfo(
         this: &v6,
         pInflictor: pFreezer,
         pAttacker: pFreezer,
         flDamage: 1.0,
         bitsDamageType: 0,
         iKillType: 0,
         iObjectsPenetrated: 0);
  CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101A2FE0
// Name: public: virtual bool CStatueProp::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CStatueProp::TestCollision(
        CStatueProp *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  const struct CPhysCollide *v5; // eax
  Vector vecPosition; // [esp+4h] [ebp-18h] BYREF
  QAngle vecAngles; // [esp+10h] [ebp-Ch] BYREF

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    return false;
  m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: &vecPosition, a3: &vecAngles);
  v5 = m_pPhysicsObject->GetCollide(this: m_pPhysicsObject);
  physcollision->TraceBox_2(this: physcollision, a2: ray, a3: v5, a4: &vecPosition, a5: &vecAngles, a6: tr);
  return tr->fraction < 1.0 || tr->allsolid || tr->startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x101A31D0
// Name: public: virtual void CStatueProp::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::ComputeWorldSpaceSurroundingBox(CStatueProp *this, Vector *pMins, Vector *pMaxs)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hInitBaseAnimating.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    ((void (__thiscall *)(IHandleEntity *, Vector *, Vector *))m_pEntity[57].__vftable[5].dtr_IHandleEntity)(
      a1: &m_pEntity[57],
      a2: pMins,
      a3: pMaxs);
  }
  else
  {
    this->m_Collision.WorldSpaceSurroundingBounds(this: &this->m_Collision, a2: pMins, a3: pMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3220
// Name: private: bool CStatueProp::CreateVPhysicsFromOBBs(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CStatueProp::CreateVPhysicsFromOBBs(CStatueProp *this, CBaseAnimating *pInitBaseAnimating)
{
  CPhysConvex **v3; // eax
  const CUtlVector<outer_collision_obb_t,CUtlMemory<outer_collision_obb_t,int> > *m_pInitOBBs; // ecx
  CPhysConvex **v5; // edi
  outer_collision_obb_t *v6; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  unsigned int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  const CUtlVector<outer_collision_obb_t,CUtlMemory<outer_collision_obb_t,int> > *v14; // eax
  const struct CPhysCollide *v15; // ebx
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // edi
  IPhysicsObject *v19; // edi
  __int64 v20; // xmm0_8
  float v21; // xmm0_4
  float v22; // xmm0_4
  Vector vecForward; // [esp+58h] [ebp-178h] BYREF
  Vector vecUp; // [esp+64h] [ebp-16Ch] BYREF
  objectparams_t params; // [esp+70h] [ebp-160h] BYREF
  matrix3x4_t matToWorld; // [esp+9Ch] [ebp-134h] BYREF
  Vector vecInitialVelocity; // [esp+CCh] [ebp-104h] BYREF
  float pPlanes[24]; // [esp+D8h] [ebp-F8h] BYREF
  Vector vecNormalLocal[3]; // [esp+138h] [ebp-98h] BYREF
  Vector vecMinCorner; // [esp+15Ch] [ebp-74h] BYREF
  Vector vecMins; // [esp+168h] [ebp-68h] BYREF
  Vector vecMaxCorner; // [esp+174h] [ebp-5Ch] BYREF
  Vector vecMaxs; // [esp+180h] [ebp-50h] BYREF
  Vector vecCornerLocal[2]; // [esp+18Ch] [ebp-44h] BYREF
  Vector vecRight; // [esp+1A4h] [ebp-2Ch] BYREF
  int i; // [esp+1B0h] [ebp-20h]
  float flDensity; // [esp+1B4h] [ebp-1Ch] BYREF
  const QAngle *in2; // [esp+1B8h] [ebp-18h]
  float flThickness; // [esp+1BCh] [ebp-14h] BYREF
  unsigned int v41; // [esp+1C0h] [ebp-10h]
  float flTotalVolume; // [esp+1C4h] [ebp-Ch]
  float flTotalSurfaceArea; // [esp+1C8h] [ebp-8h]
  int nMaterialIndex; // [esp+1CCh] [ebp-4h]
  int savedregs; // [esp+1D0h] [ebp+0h] BYREF

  v3 = (CPhysConvex **)operator new(nSize: 4 * this->m_pInitOBBs->m_Size);
  m_pInitOBBs = this->m_pInitOBBs;
  v5 = v3;
  nMaterialIndex = (int)v3;
  flTotalVolume = 0.0;
  flTotalSurfaceArea = 0.0;
  i = 0;
  if ( m_pInitOBBs->m_Size > 0 )
  {
    v41 = 0;
    do
    {
      v6 = &this->m_pInitOBBs->m_Memory.m_pMemory[v41 / 0x48];
      v7 = v6->vecMaxs.y - v6->vecMins.y;
      v8 = v6->vecMaxs.x - v6->vecMins.x;
      v9 = v6->vecMaxs.z - v6->vecMins.z;
      flTotalVolume = (float)((float)(v7 * v8) * v9) + flTotalVolume;
      flTotalSurfaceArea = (float)((float)((float)((float)(v9 + v7) * v8) + (float)(v9 * v7)) * 2.0)
                         + flTotalSurfaceArea;
      in2 = &v6->angAngles;
      VectorRotate(in1: &v6->vecMins, in2: &v6->angAngles, out: &vecMins);
      VectorRotate(in1: &v6->vecMaxs, in2, out: &vecMaxs);
      vecMinCorner.x = v6->vecPos.x + vecMins.x;
      vecMinCorner.y = v6->vecPos.y + vecMins.y;
      vecMinCorner.z = v6->vecPos.z + vecMins.z;
      vecMaxCorner.x = v6->vecPos.x + vecMaxs.x;
      vecMaxCorner.y = v6->vecPos.y + vecMaxs.y;
      vecMaxCorner.z = v6->vecPos.z + vecMaxs.z;
      AngleVectors(angles: in2, forward: &vecForward, right: &vecRight, up: &vecUp);
      v10 = (unsigned int)this->m_iEFlags >> 11;
      vecRight.x = -vecRight.x;
      vecRight.y = -vecRight.y;
      vecRight.z = -vecRight.z;
      if ( (v10 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      matToWorld = this->m_rgflCoordinateFrame;
      VectorITransform(in1: &vecMaxCorner.x, in2: &matToWorld, out: &vecCornerLocal[0].x);
      VectorITransform(in1: &vecMinCorner.x, in2: &matToWorld, out: &vecCornerLocal[1].x);
      VectorIRotate(in1: &vecForward.x, in2: &matToWorld, out: &vecNormalLocal[0].x);
      VectorIRotate(in1: &vecRight.x, in2: &matToWorld, out: &vecNormalLocal[1].x);
      VectorIRotate(in1: &vecUp.x, in2: &matToWorld, out: &vecNormalLocal[2].x);
      pPlanes[3] = (float)((float)(vecCornerLocal[0].y * vecNormalLocal[0].y)
                         + (float)(vecCornerLocal[0].x * vecNormalLocal[0].x))
                 + (float)(vecCornerLocal[0].z * vecNormalLocal[0].z);
      pPlanes[4] = vecNormalLocal[0].x * -1.0;
      pPlanes[5] = vecNormalLocal[0].y * -1.0;
      pPlanes[6] = vecNormalLocal[0].z * -1.0;
      *(Vector *)pPlanes = vecNormalLocal[0];
      pPlanes[7] = (float)((float)((float)(vecCornerLocal[1].y * vecNormalLocal[0].y)
                                 + (float)(vecCornerLocal[1].x * vecNormalLocal[0].x))
                         + (float)(vecCornerLocal[1].z * vecNormalLocal[0].z))
                 * -1.0;
      pPlanes[11] = (float)((float)(vecNormalLocal[1].y * vecCornerLocal[0].y)
                          + (float)(vecNormalLocal[1].x * vecCornerLocal[0].x))
                  + (float)(vecNormalLocal[1].z * vecCornerLocal[0].z);
      *(Vector *)&pPlanes[8] = vecNormalLocal[1];
      pPlanes[12] = vecNormalLocal[1].x * -1.0;
      pPlanes[13] = vecNormalLocal[1].y * -1.0;
      pPlanes[15] = (float)((float)((float)(vecNormalLocal[1].y * vecCornerLocal[1].y)
                                  + (float)(vecNormalLocal[1].x * vecCornerLocal[1].x))
                          + (float)(vecNormalLocal[1].z * vecCornerLocal[1].z))
                  * -1.0;
      pPlanes[20] = vecNormalLocal[2].x * -1.0;
      pPlanes[21] = vecNormalLocal[2].y * -1.0;
      *(Vector *)&pPlanes[16] = vecNormalLocal[2];
      pPlanes[14] = vecNormalLocal[1].z * -1.0;
      pPlanes[19] = (float)((float)(vecNormalLocal[2].y * vecCornerLocal[0].y)
                          + (float)(vecNormalLocal[2].x * vecCornerLocal[0].x))
                  + (float)(vecNormalLocal[2].z * vecCornerLocal[0].z);
      pPlanes[22] = vecNormalLocal[2].z * -1.0;
      pPlanes[23] = (float)((float)((float)(vecNormalLocal[2].y * vecCornerLocal[1].y)
                                  + (float)(vecNormalLocal[2].x * vecCornerLocal[1].x))
                          + (float)(vecNormalLocal[2].z * vecCornerLocal[1].z))
                  * -1.0;
      v11 = ((int (__thiscall *)(IPhysicsCollision *, float *, int, _DWORD))physcollision->ConvexFromPlanes)(
              a1: physcollision,
              a2: pPlanes,
              a3: 6,
              a4: 0);
      v12 = i;
      v13 = nMaterialIndex;
      *(_DWORD *)(nMaterialIndex + 4 * i) = v11;
      v14 = this->m_pInitOBBs;
      v41 += 72;
      i = v12 + 1;
    }
    while ( v12 + 1 < v14->m_Size );
    v5 = (CPhysConvex **)v13;
  }
  v15 = physcollision->ConvertConvexToCollide(this: physcollision, a2: v5, a3: this->m_pInitOBBs->m_Size);
  free(pMem: v5);
  *(_QWORD *)&params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  params.pName = g_PhysDefaultObjectParams.pName;
  *(_DWORD *)&params.enableCollisions = 1;
  *(_QWORD *)&params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  params.pGameData = this;
  v16 = physprops->GetSurfaceIndex(this: physprops, a2: "ice");
  v17 = (unsigned int)this->m_iEFlags >> 11;
  v18 = v16;
  nMaterialIndex = v16;
  if ( (v17 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v19 = physenv->CreatePolyObject(
          this: physenv,
          a2: v15,
          a3: v18,
          a4: &this->m_vecAbsOrigin,
          a5: &this->m_angAbsRotation,
          a6: &params);
  if ( (pInitBaseAnimating->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: pInitBaseAnimating, a2: (int)&savedregs);
  v20 = *(_QWORD *)&pInitBaseAnimating->m_vecAbsVelocity.x;
  vecInitialVelocity.z = pInitBaseAnimating->m_vecAbsVelocity.z;
  *(_QWORD *)&vecInitialVelocity.x = v20;
  v19->SetVelocity(this: v19, a2: &vecInitialVelocity, a3: nullptr);
  physprops->GetPhysicsProperties(
    this: physprops,
    a2: nMaterialIndex,
    a3: &flDensity,
    a4: &flThickness,
    a5: nullptr,
    a6: nullptr);
  v21 = flThickness + 0.5;
  if ( (float)(flThickness + 0.5) <= 1.0 )
  {
    flThickness = flThickness + 0.5;
    if ( v21 <= 0.0 )
      v22 = flTotalVolume;
    else
      v22 = v21 * flTotalSurfaceArea;
  }
  else
  {
    flThickness = 1.0;
    v22 = 1.0 * flTotalSurfaceArea;
  }
  ((void (__thiscall *)(IPhysicsObject *, _DWORD))v19->SetMass)(a1: v19, a2: (float)(v22 * 0.000016387063) * flDensity);
  v19->EnableGravity(this: v19, a2: true);
  CBaseEntity::VPhysicsSetObject(this, pPhysics: v19);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_pInitOBBs = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A38F0
// Name: public: class CBaseAnimating const __near * CNetworkHandleBase<class CBaseAnimating,class CStatueProp::NetworkVar_m_hInitBaseAnimating>::Set(class CBaseAnimating const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseAnimating *__thiscall CNetworkHandleBase<CBaseAnimating,CStatueProp::NetworkVar_m_hInitBaseAnimating>::Set(
        CNetworkHandleBase<CBaseAnimating,CStatueProp::NetworkVar_m_hInitBaseAnimating> *this,
        const CBaseAnimating *val)
{
  unsigned int m_Index; // eax
  const CBaseAnimating *m_pEntity; // ecx
  CNetworkHandleBase<CBaseAnimating,CStatueProp::NetworkVar_m_hInitBaseAnimating> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 444;
    if ( *((_BYTE *)this - 1692) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x6F0u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x101A3980
// Name: public: CStatueProp::CStatueProp(void)
// Source: json
//------------------------------------------------------------------------------
CStatueProp *__thiscall CStatueProp::CStatueProp(CStatueProp *this)
{
  CPhysicsProp::CPhysicsProp(this);
  this->CPhysicsProp::CBreakableProp::CBaseProp::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CStatueProp_vtbl *)&CStatueProp::`vftable'{for `CBaseProp'};
  this->CPhysicsProp::CBreakableProp::IBreakableWithPropData::__vftable = (IBreakableWithPropData_vtbl *)&CStatueProp::`vftable'{for `IBreakableWithPropData'};
  this->CPhysicsProp::CBreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CStatueProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->CPhysicsProp::INavAvoidanceObstacle::__vftable = (INavAvoidanceObstacle_vtbl *)&CStatueProp::`vftable';
  this->m_hInitBaseAnimating.m_Value.m_Index = -1;
  if ( (_S4_45 & 1) == 0 )
  {
    _S4_45 |= 1u;
    ConVarRef::ConVarRef(this: &vcollide_wireframe, pName: "vcollide_wireframe");
  }
  s_vcollide_wireframe = &vcollide_wireframe;
  this->m_pInitOBBs = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A39F0
// Name: public: virtual float CBreakableProp::GetAutoAimRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetAutoAimRadius(CBreakableProp *this)
{
  return 24.0;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A00
// Name: public: virtual bool CBreakableProp::HasPreferredCarryAnglesForPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBreakableProp::HasPreferredCarryAnglesForPlayer(CBreakableProp *this, CBasePlayer *pPlayer)
{
  return (*(unsigned __int8 (__thiscall **)(char *, int))(*((_DWORD *)this - 1) + 96))(a1: (char *)this - 4, a2: 5) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A20
// Name: public: virtual class QAngle CBreakableProp::PreferredCarryAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CBreakableProp::PreferredCarryAngles(CBreakableProp *this, QAngle *result)
{
  __int64 v2; // xmm0_8
  const char *pszValue; // ecx

  v2 = *(_QWORD *)&this->m_Network.m_TimerEvent.m_bRegistered;
  pszValue = this->m_iClassname.pszValue;
  *(_QWORD *)&result->x = v2;
  LODWORD(result->z) = pszValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A40
// Name: public: virtual void CBreakableProp::SetDmgModBullet(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetDmgModBullet(CBreakable *this, int flDmgMod)
{
  this->m_aThinkFunctions.m_Memory.m_nAllocationCount = flDmgMod;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A60
// Name: public: virtual void CBreakableProp::SetDmgModExplosive(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetDmgModExplosive(CBreakableProp *this, int flDmgMod)
{
  this->m_aThinkFunctions.m_Size = flDmgMod;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A80
// Name: public: virtual float CBreakableProp::GetDmgModFire(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetDmgModFire(CBreakableProp *this)
{
  return *(float *)&this->m_aThinkFunctions.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x101A3A90
// Name: public: virtual void CBreakableProp::SetExplosiveRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetExplosiveRadius(CBreakableProp *this, const char *flRadius)
{
  this->m_ModelName.pszValue = flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x101A3AB0
// Name: public: virtual void CBreakableProp::SetExplosiveDamage(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetExplosiveDamage(CBreakable *this, int flRadius)
{
  this->m_fEffects.m_Value = flRadius;
}

//------------------------------------------------------------------------------
// Address: 0x101A3AD0
// Name: public: virtual float CBreakableProp::GetExplosiveRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetExplosiveRadius(CBreakableProp *this)
{
  return *(float *)&this->m_ModelName.pszValue;
}

//------------------------------------------------------------------------------
// Address: 0x101A3AE0
// Name: public: virtual struct string_t CBreakableProp::GetBreakableModel(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CBreakableProp::GetBreakableModel(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B00
// Name: public: virtual void CBreakableProp::SetBreakableCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetBreakableCount(CBreakable *this, int iSize)
{
  this->m_ResponseContexts.m_Size = iSize;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B10
// Name: public: virtual int CBreakableProp::GetMaxBreakableSize(void)
// Source: json
//------------------------------------------------------------------------------
ResponseContext_t *__thiscall CBreakableProp::GetMaxBreakableSize(CBreakableProp *this)
{
  return this->m_ResponseContexts.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B20
// Name: public: virtual void CBreakableProp::SetPropDataBlocksLOS(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetPropDataBlocksLOS(CBreakableProp *this, bool bBlocksLOS)
{
  this->m_clrRender.m_Value.r = 1;
  CBaseEntity::SetBlocksLOS(this: (CBreakableProp *)((char *)this - 1164), bBlocksLOS);
}

//------------------------------------------------------------------------------
// Address: 0x101A3B40
// Name: public: virtual void CBreakableProp::SetPropDataIsAIWalkable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetPropDataIsAIWalkable(CBreakableProp *this, bool b)
{
  this->m_clrRender.m_Value.g = 1;
  CBaseEntity::SetAIWalkable(this: (CBreakableProp *)((char *)this - 1164), bBlocksLOS: b);
}

//------------------------------------------------------------------------------
// Address: 0x101A3B60
// Name: public: virtual void CBreakableProp::SetBasePropData(struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetBasePropData(CBreakableProp *this, string_t iszBase)
{
  this->m_iszResponseContext = iszBase;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B70
// Name: public: virtual struct string_t CBreakableProp::GetBasePropData(void)
// Source: json
//------------------------------------------------------------------------------
string_t __thiscall CBreakableProp::GetBasePropData(CBreakableProp *this, const char **a2)
{
  *a2 = this->m_iszResponseContext.pszValue;
  return (string_t)a2;
}

//------------------------------------------------------------------------------
// Address: 0x101A3B90
// Name: public: virtual void CBreakableProp::SetInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetInteraction(CBreakableProp *this, propdata_interactions_t Interaction)
{
  this->m_nNextThinkTick.m_Value |= 1 << Interaction;
}

//------------------------------------------------------------------------------
// Address: 0x101A3BB0
// Name: public: virtual bool CBreakableProp::HasInteraction(enum propdata_interactions_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBreakableProp::HasInteraction(CBreakableProp *this, propdata_interactions_t Interaction)
{
  return ((1 << Interaction) & this->m_nNextThinkTick.m_Value) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A3BD0
// Name: public: virtual void CBreakableProp::SetMultiplayerBreakMode(enum mp_break_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetMultiplayerBreakMode(CBreakableProp *this, float mode)
{
  this->m_Collision.m_vecSurroundingMaxs.y = mode;
}

//------------------------------------------------------------------------------
// Address: 0x101A3BE0
// Name: public: virtual enum mp_break_t CBreakableProp::GetMultiplayerBreakMode(void)const
// Source: json
//------------------------------------------------------------------------------
mp_break_t __thiscall CBreakableProp::GetMultiplayerBreakMode(CBreakableProp *this)
{
  return LODWORD(this->m_Collision.m_vecSurroundingMaxs.y);
}

//------------------------------------------------------------------------------
// Address: 0x101A3BF0
// Name: public: virtual void CBreakableProp::SetPhysicsMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBreakableProp::SetPhysicsMode(CBreakableProp *this, int iMode)
{
  LODWORD(this->m_flAnimTime.m_Value) = iMode;
}

//------------------------------------------------------------------------------
// Address: 0x101A3C00
// Name: public: virtual int CBreakableProp::GetPhysicsMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBreakableProp::GetPhysicsMode(CBreakableProp *this)
{
  return LODWORD(this->m_flAnimTime.m_Value);
}

//------------------------------------------------------------------------------
// Address: 0x101A3C10
// Name: public: virtual class CBaseEntity __near * CPhysicsProp::GetObstructingEntity(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsProp *__thiscall CPhysicsProp::GetObstructingEntity(CPhysicsProp *this)
{
  return (CPhysicsProp *)((char *)this - 1512);
}

//------------------------------------------------------------------------------
// Address: 0x101A3C50
// Name: public: virtual void CStatueProp::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::VPhysicsUpdate(CStatueProp *this, Vector *pPhysics)
{
  Vector *v2; // esi
  const struct CPhysCollide *v3; // edi
  int v4; // ebx
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  unsigned int v8; // edx
  IPhysicsObject_vtbl *y_low; // xmm4_4
  IPhysicsObject_vtbl *x_low; // xmm3_4
  IPhysicsObject_vtbl *z_low; // xmm5_4
  float *p_x; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  IPhysicsObject_vtbl *v15; // xmm4_4
  IPhysicsObject_vtbl *v16; // xmm3_4
  IPhysicsObject_vtbl *v17; // xmm5_4
  float *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm2_4
  IPhysicsObject_vtbl *v21; // xmm4_4
  IPhysicsObject_vtbl *v22; // xmm3_4
  IPhysicsObject_vtbl *v23; // xmm5_4
  float *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm2_4
  IPhysicsObject_vtbl *v27; // xmm4_4
  IPhysicsObject_vtbl *v28; // xmm3_4
  IPhysicsObject_vtbl *v29; // xmm5_4
  float *v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  int v33; // ecx
  int v34; // edx
  IPhysicsObject_vtbl *v35; // xmm4_4
  IPhysicsObject_vtbl *v36; // xmm3_4
  IPhysicsObject_vtbl *v37; // xmm5_4
  float *v38; // eax
  float v39; // xmm1_4
  float v40; // xmm2_4
  int v41; // esi
  VMatrix tmp; // [esp+20h] [ebp-58h] BYREF
  Vector vecOrigin; // [esp+60h] [ebp-18h] BYREF
  QAngle angAngles; // [esp+6Ch] [ebp-Ch] BYREF

  v2 = pPhysics;
  CPhysicsProp::VPhysicsUpdate(this, (IPhysicsObject *)pPhysics);
  if ( s_vcollide_wireframe->m_pConVarState->m_Value.m_nValue != 0 )
  {
    v3 = (const struct CPhysCollide *)(*(int (__thiscall **)(Vector *))(LODWORD(v2->x) + 296))(a1: v2);
    (*(void (__thiscall **)(Vector *, Vector *, QAngle *))(LODWORD(v2->x) + 192))(
      a1: v2,
      a2: &vecOrigin,
      a3: &angAngles);
    if ( v3 != nullptr )
    {
      v4 = physcollision->CreateDebugMesh(this: physcollision, a2: v3, a3: &pPhysics);
      v5 = v4 / 3;
      SetupMatrixOrgAngles(result: &tmp, origin: &vecOrigin, vAngles: &angAngles);
      v6 = 0;
      if ( v4 >= 4 )
      {
        v7 = 0;
        v8 = ((unsigned int)(v4 - 4) >> 2) + 1;
        v6 = 4 * v8;
        do
        {
          y_low = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7].y);
          x_low = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7].x);
          z_low = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7].z);
          p_x = &pPhysics[v7].x;
          v13 = (float)((float)((float)(tmp.m[1][1] * *(float *)&y_low) + (float)(tmp.m[1][0] * *(float *)&x_low))
                      + (float)(tmp.m[1][2] * *(float *)&z_low))
              + tmp.m[1][3];
          v14 = (float)((float)((float)(tmp.m[2][1] * *(float *)&y_low) + (float)(tmp.m[2][0] * *(float *)&x_low))
                      + (float)(tmp.m[2][2] * *(float *)&z_low))
              + tmp.m[2][3];
          *p_x = (float)((float)((float)(tmp.m[0][0] * *(float *)&x_low) + (float)(*(float *)&y_low * tmp.m[0][1]))
                       + (float)(tmp.m[0][2] * *(float *)&z_low))
               + tmp.m[0][3];
          p_x[1] = v13;
          p_x[2] = v14;
          v15 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 1].y);
          v16 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 1].x);
          v17 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 1].z);
          v18 = &pPhysics[v7 + 1].x;
          v19 = (float)((float)((float)(tmp.m[1][1] * *(float *)&v15) + (float)(tmp.m[1][0] * *(float *)&v16))
                      + (float)(tmp.m[1][2] * *(float *)&v17))
              + tmp.m[1][3];
          v20 = (float)((float)((float)(tmp.m[2][1] * *(float *)&v15) + (float)(tmp.m[2][0] * *(float *)&v16))
                      + (float)(tmp.m[2][2] * *(float *)&v17))
              + tmp.m[2][3];
          *v18 = (float)((float)((float)(tmp.m[0][0] * *(float *)&v16) + (float)(*(float *)&v15 * tmp.m[0][1]))
                       + (float)(tmp.m[0][2] * *(float *)&v17))
               + tmp.m[0][3];
          v18[1] = v19;
          v18[2] = v20;
          v21 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 2].y);
          v22 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 2].x);
          v23 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 2].z);
          v24 = &pPhysics[v7 + 2].x;
          v25 = (float)((float)((float)(tmp.m[1][1] * *(float *)&v21) + (float)(tmp.m[1][0] * *(float *)&v22))
                      + (float)(tmp.m[1][2] * *(float *)&v23))
              + tmp.m[1][3];
          v26 = (float)((float)((float)(tmp.m[2][1] * *(float *)&v21) + (float)(tmp.m[2][0] * *(float *)&v22))
                      + (float)(tmp.m[2][2] * *(float *)&v23))
              + tmp.m[2][3];
          *v24 = (float)((float)((float)(tmp.m[0][0] * *(float *)&v22) + (float)(*(float *)&v21 * tmp.m[0][1]))
                       + (float)(tmp.m[0][2] * *(float *)&v23))
               + tmp.m[0][3];
          v24[1] = v25;
          v24[2] = v26;
          v27 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 3].y);
          v28 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 3].x);
          v29 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v7 + 3].z);
          v30 = &pPhysics[v7 + 3].x;
          v31 = (float)((float)((float)(tmp.m[1][1] * *(float *)&v27) + (float)(tmp.m[1][0] * *(float *)&v28))
                      + (float)(tmp.m[1][2] * *(float *)&v29))
              + tmp.m[1][3];
          v32 = (float)((float)((float)(tmp.m[2][1] * *(float *)&v27) + (float)(tmp.m[2][0] * *(float *)&v28))
                      + (float)(tmp.m[2][2] * *(float *)&v29))
              + tmp.m[2][3];
          *v30 = (float)((float)((float)(tmp.m[0][0] * *(float *)&v28) + (float)(*(float *)&v27 * tmp.m[0][1]))
                       + (float)(tmp.m[0][2] * *(float *)&v29))
               + tmp.m[0][3];
          v7 += 4;
          --v8;
          v30[1] = v31;
          v30[2] = v32;
        }
        while ( v8 != 0 );
      }
      if ( v6 < v4 )
      {
        v33 = v6;
        v34 = v4 - v6;
        do
        {
          v35 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v33].y);
          v36 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v33].x);
          v37 = (IPhysicsObject_vtbl *)LODWORD(pPhysics[v33].z);
          v38 = &pPhysics[v33].x;
          v39 = (float)((float)((float)(tmp.m[1][1] * *(float *)&v35) + (float)(tmp.m[1][0] * *(float *)&v36))
                      + (float)(tmp.m[1][2] * *(float *)&v37))
              + tmp.m[1][3];
          v40 = (float)((float)((float)(tmp.m[2][1] * *(float *)&v35) + (float)(tmp.m[2][0] * *(float *)&v36))
                      + (float)(tmp.m[2][2] * *(float *)&v37))
              + tmp.m[2][3];
          ++v33;
          --v34;
          *v38 = (float)((float)((float)(tmp.m[0][0] * *(float *)&v36) + (float)(*(float *)&v35 * tmp.m[0][1]))
                       + (float)(tmp.m[0][2] * *(float *)&v37))
               + tmp.m[0][3];
          v38[1] = v39;
          v38[2] = v40;
        }
        while ( v34 != 0 );
      }
      if ( v5 > 0 )
      {
        v41 = 0;
        do
        {
          NDebugOverlay::Line(
            origin: &pPhysics[v41],
            target: &pPhysics[v41 + 1],
            r: 0,
            g: 255,
            b: 255,
            noDepthTest: 0,
            duration: 0.0);
          NDebugOverlay::Line(
            origin: &pPhysics[v41 + 1],
            target: &pPhysics[v41 + 2],
            r: 0,
            g: 255,
            b: 255,
            noDepthTest: 0,
            duration: 0.0);
          NDebugOverlay::Line(
            origin: &pPhysics[v41 + 2],
            target: &pPhysics[v41],
            r: 0,
            g: 255,
            b: 255,
            noDepthTest: 0,
            duration: 0.0);
          v41 += 3;
          --v5;
        }
        while ( v5 != 0 );
      }
      physcollision->DestroyDebugMesh(this: physcollision, a2: v4, a3: pPhysics);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A40F0
// Name: public: virtual void CStatueProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::Spawn(CStatueProp *this)
{
  edict_t *m_pPev; // ecx

  ((void (__thiscall *)(IBreakableWithPropData *, const char *))this->SetBreakableModel)(
    a1: &this->IBreakableWithPropData,
    a2: "ConcreteChunks");
  this->SetBreakableCount(this: &this->IBreakableWithPropData, a2: 6);
  this->SetHealth(this, a2: 5);
  CPhysicsProp::Spawn(this);
  if ( this->m_flFrozen.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flFrozen.m_Value = 1.0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x44Cu);
      this->m_flFrozen.m_Value = 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4190
// Name: public: virtual void CStatueProp::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::Event_Killed(CStatueProp *this, const CTakeDamageInfo *info)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  Vector m_vecDamagePosition; // 0:^1C.12
  Vector m_vecDamageForce; // 0:^1C.12

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr && !m_pPhysicsObject->IsMoveable(this: this->m_pPhysicsObject) )
  {
    m_pPhysicsObject->EnableMotion(this: m_pPhysicsObject, a2: true);
    this->VPhysicsTakeDamage(this, a2: info);
  }
  if ( this->m_nShatterFlags.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x6F8u);
    }
    this->m_nShatterFlags.m_Value = 0;
  }
  m_vecDamagePosition = info->m_vecDamagePosition;
  if ( m_vecDamagePosition.x != this->m_vShatterPosition.m_Value.x
    || m_vecDamagePosition.y != this->m_vShatterPosition.m_Value.y
    || m_vecDamagePosition.z != this->m_vShatterPosition.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x6FCu);
    }
    this->m_vShatterPosition.m_Value = m_vecDamagePosition;
  }
  m_vecDamageForce = info->m_vecDamageForce;
  if ( info->m_vecDamageForce.x != this->m_vShatterForce.m_Value.x
    || m_vecDamageForce.y != this->m_vShatterForce.m_Value.y
    || m_vecDamageForce.z != this->m_vShatterForce.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x708u);
    }
    this->m_vShatterForce.m_Value = m_vecDamageForce;
  }
  if ( !this->m_bShatter.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x6F4u);
    }
    this->m_bShatter.m_Value = true;
  }
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101A43B0
// Name: public: void CStatueProp::CollisionPartnerThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatueProp::CollisionPartnerThink(CStatueProp *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hInitBaseAnimating.m_Value.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    UTIL_Remove(oldObj: this);
  }
  if ( this->m_iHealth.m_Value <= 0 )
  {
    this->SetHealth(this, a2: 5);
    if ( this->m_takedamage.m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 2;
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101A4450
// Name: class CBaseEntity __near * CreateServerStatue(class CBaseAnimating __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__cdecl CreateServerStatue(CBaseAnimating *pAnimating)
{
  CBaseEntity *result; // eax
  CBaseEntity *v2; // esi
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  result = CreateEntityByName(className: "physics_prop_statue", iForceEdictIndex: -1, bNotify: true);
  v2 = result;
  if ( result != nullptr )
  {
    CNetworkHandleBase<CBaseAnimating,CStatueProp::NetworkVar_m_hInitBaseAnimating>::Set(
      this: (CNetworkHandleBase<CBaseAnimating,CStatueProp::NetworkVar_m_hInitBaseAnimating> *)&result[2].m_Network.m_TimerEvent.m_flNextEventTime,
      val: pAnimating);
    v2->m_ModelName.pszValue = *(const char **)((int (__thiscall *)(CBaseAnimating *, _BYTE *))pAnimating->GetModelName)(
                                                 a1: pAnimating,
                                                 a2: v3);
    CBaseEntity::DispatchUpdateTransmitState(this: v2);
    if ( (pAnimating->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pAnimating, a2: (int)&savedregs);
    CBaseEntity::SetAbsOrigin(this: v2, absOrigin: &pAnimating->m_vecAbsOrigin);
    if ( (pAnimating->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pAnimating, a2: (int)&savedregs);
    CBaseEntity::SetAbsAngles(this: v2, absAngles: &pAnimating->m_angAbsRotation);
    DispatchSpawn(pEntity: v2, bRunVScripts: true);
    v2->Activate(this: v2);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4630
// Name: private: bool CStatueProp::CreateVPhysicsFromHitBoxes(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CStatueProp::CreateVPhysicsFromHitBoxes@<al>(
        CStatueProp *this@<ecx>,
        int a2@<ebx>,
        CStatueProp *pInitBaseAnimating)
{
  unsigned __int8 r; // al
  unsigned __int8 b; // dl
  unsigned __int8 a; // dl
  edict_t *m_pPev; // ecx
  CStudioHdr *m_pStudioHdr; // eax
  int v10; // ebx
  void *v11; // edi
  int v12; // edi
  int v13; // edx
  int v14; // edi
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  unsigned int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // edx
  const struct CPhysCollide *v22; // ebx
  int v23; // eax
  unsigned int v24; // ecx
  int v25; // edi
  IPhysicsObject *v26; // edi
  __int64 v27; // xmm0_8
  float v28; // xmm0_4
  float v29; // xmm0_4
  unsigned int m_Index; // esi
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v32; // edi
  char *v33; // eax
  _BYTE *v34; // esi
  CBaseEdict *v35; // ecx
  IHandleEntity_vtbl *v36; // eax
  IHandleEntity *v37; // eax
  Vector vecUp; // [esp+58h] [ebp-194h] BYREF
  Vector vecForward; // [esp+64h] [ebp-188h] BYREF
  objectparams_t params; // [esp+70h] [ebp-17Ch] BYREF
  matrix3x4_t matToWorld; // [esp+9Ch] [ebp-150h] BYREF
  Vector vecInitialVelocity; // [esp+CCh] [ebp-120h] BYREF
  float pPlanes[24]; // [esp+D8h] [ebp-114h] BYREF
  Vector vecMins; // [esp+138h] [ebp-B4h] BYREF
  Vector position; // [esp+144h] [ebp-A8h] BYREF
  Vector vecMaxCorner; // [esp+150h] [ebp-9Ch] BYREF
  QAngle angles; // [esp+15Ch] [ebp-90h] BYREF
  Vector vecNormalLocal[3]; // [esp+168h] [ebp-84h] BYREF
  Vector vecMinCorner; // [esp+18Ch] [ebp-60h] BYREF
  Vector vecMaxs; // [esp+198h] [ebp-54h] BYREF
  Vector vecCornerLocal[2]; // [esp+1A4h] [ebp-48h] BYREF
  Vector vecRight; // [esp+1BCh] [ebp-30h] BYREF
  int i; // [esp+1C8h] [ebp-24h]
  float flDensity; // [esp+1CCh] [ebp-20h] BYREF
  float flThickness; // [esp+1D0h] [ebp-1Ch] BYREF
  float flTotalSurfaceArea; // [esp+1D4h] [ebp-18h]
  int v58; // [esp+1D8h] [ebp-14h]
  float flTotalVolume; // [esp+1DCh] [ebp-10h]
  int nMaterialIndex; // [esp+1E0h] [ebp-Ch]
  unsigned __int8 v61; // [esp+1E8h] [ebp-4h]
  int savedregs; // [esp+1ECh] [ebp+0h] BYREF

  if ( pInitBaseAnimating == nullptr )
    return 0;
  CBaseAnimating::CopyAnimationDataFrom(this, pSource: pInitBaseAnimating);
  r = pInitBaseAnimating->m_clrRender.m_Value.r;
  b = pInitBaseAnimating->m_clrRender.m_Value.b;
  BYTE1(nMaterialIndex) = pInitBaseAnimating->m_clrRender.m_Value.g;
  LOBYTE(nMaterialIndex) = r;
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: r,
    gVal: BYTE1(nMaterialIndex),
    bVal: b);
  a = pInitBaseAnimating->m_clrRender.m_Value.a;
  v61 = a;
  if ( this->m_clrRender.m_Value.a != a )
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
        a = v61;
      }
    }
    this->m_clrRender.m_Value.a = a;
  }
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return 0;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    return 0;
  v10 = (int)m_pStudioHdr->m_pStudioHdr + 12 * this->m_nHitboxSet.m_Value + m_pStudioHdr->m_pStudioHdr->hitboxsetindex;
  if ( v10 == 0 )
    return 0;
  v11 = operator new(nSize: 4 * *(_DWORD *)(v10 + 4));
  nMaterialIndex = (int)v11;
  flTotalVolume = 0.0;
  flTotalSurfaceArea = 0.0;
  i = 0;
  if ( *(int *)(v10 + 4) > 0 )
  {
    v58 = 0;
    do
    {
      v12 = v58 + *(_DWORD *)(v10 + 8);
      v13 = *(_DWORD *)(v12 + v10);
      v14 = v10 + v12;
      CBaseAnimating::GetBonePosition(this, iBone: v13, origin: &position, &angles);
      v15 = *(float *)(v14 + 24) - *(float *)(v14 + 12);
      v16 = *(float *)(v14 + 20) - *(float *)(v14 + 8);
      v17 = *(float *)(v14 + 28) - *(float *)(v14 + 16);
      flTotalVolume = (float)((float)(v15 * v16) * v17) + flTotalVolume;
      flTotalSurfaceArea = (float)((float)((float)((float)(v17 + v15) * v16) + (float)(v17 * v15)) * 2.0)
                         + flTotalSurfaceArea;
      VectorRotate(in1: (const Vector *)(v14 + 8), in2: &angles, out: &vecMins);
      VectorRotate(in1: (const Vector *)(v14 + 20), in2: &angles, out: &vecMaxs);
      vecMinCorner.z = vecMins.z + position.z;
      vecMaxCorner.y = vecMaxs.y + position.y;
      vecMinCorner.x = vecMins.x + position.x;
      vecMinCorner.y = vecMins.y + position.y;
      vecMaxCorner.x = vecMaxs.x + position.x;
      vecMaxCorner.z = vecMaxs.z + position.z;
      AngleVectors(&angles, forward: &vecForward, right: &vecRight, up: &vecUp);
      vecRight.x = -vecRight.x;
      vecRight.y = -vecRight.y;
      v18 = (unsigned int)this->m_iEFlags >> 11;
      vecRight.z = -vecRight.z;
      if ( (v18 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      matToWorld = this->m_rgflCoordinateFrame;
      VectorITransform(in1: &vecMaxCorner.x, in2: &matToWorld, out: &vecCornerLocal[0].x);
      VectorITransform(in1: &vecMinCorner.x, in2: &matToWorld, out: &vecCornerLocal[1].x);
      VectorIRotate(in1: &vecForward.x, in2: &matToWorld, out: &vecNormalLocal[0].x);
      VectorIRotate(in1: &vecRight.x, in2: &matToWorld, out: &vecNormalLocal[1].x);
      VectorIRotate(in1: &vecUp.x, in2: &matToWorld, out: &vecNormalLocal[2].x);
      pPlanes[3] = (float)((float)(vecCornerLocal[0].x * vecNormalLocal[0].x)
                         + (float)(vecCornerLocal[0].y * vecNormalLocal[0].y))
                 + (float)(vecCornerLocal[0].z * vecNormalLocal[0].z);
      pPlanes[4] = vecNormalLocal[0].x * -1.0;
      pPlanes[5] = vecNormalLocal[0].y * -1.0;
      pPlanes[6] = vecNormalLocal[0].z * -1.0;
      *(Vector *)pPlanes = vecNormalLocal[0];
      pPlanes[7] = (float)((float)((float)(vecCornerLocal[1].y * vecNormalLocal[0].y)
                                 + (float)(vecCornerLocal[1].x * vecNormalLocal[0].x))
                         + (float)(vecCornerLocal[1].z * vecNormalLocal[0].z))
                 * -1.0;
      *(Vector *)&pPlanes[8] = vecNormalLocal[1];
      pPlanes[12] = vecNormalLocal[1].x * -1.0;
      pPlanes[13] = vecNormalLocal[1].y * -1.0;
      pPlanes[15] = (float)((float)((float)(vecNormalLocal[1].y * vecCornerLocal[1].y)
                                  + (float)(vecNormalLocal[1].x * vecCornerLocal[1].x))
                          + (float)(vecNormalLocal[1].z * vecCornerLocal[1].z))
                  * -1.0;
      pPlanes[14] = vecNormalLocal[1].z * -1.0;
      pPlanes[11] = (float)((float)(vecNormalLocal[1].y * vecCornerLocal[0].y)
                          + (float)(vecNormalLocal[1].x * vecCornerLocal[0].x))
                  + (float)(vecNormalLocal[1].z * vecCornerLocal[0].z);
      pPlanes[20] = vecNormalLocal[2].x * -1.0;
      pPlanes[21] = vecNormalLocal[2].y * -1.0;
      *(Vector *)&pPlanes[16] = vecNormalLocal[2];
      pPlanes[19] = (float)((float)(vecNormalLocal[2].y * vecCornerLocal[0].y)
                          + (float)(vecNormalLocal[2].x * vecCornerLocal[0].x))
                  + (float)(vecNormalLocal[2].z * vecCornerLocal[0].z);
      pPlanes[22] = vecNormalLocal[2].z * -1.0;
      pPlanes[23] = (float)((float)((float)(vecNormalLocal[2].y * vecCornerLocal[1].y)
                                  + (float)(vecNormalLocal[2].x * vecCornerLocal[1].x))
                          + (float)(vecNormalLocal[2].z * vecCornerLocal[1].z))
                  * -1.0;
      v19 = ((int (__thiscall *)(IPhysicsCollision *, float *, int, _DWORD))physcollision->ConvexFromPlanes)(
              a1: physcollision,
              a2: pPlanes,
              a3: 6,
              a4: 0);
      v20 = i;
      v21 = nMaterialIndex;
      *(_DWORD *)(nMaterialIndex + 4 * i) = v19;
      v58 += 68;
      i = v20 + 1;
    }
    while ( v20 + 1 < *(_DWORD *)(v10 + 4) );
    v11 = (void *)v21;
  }
  v22 = (const struct CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *, void *, _DWORD, int))physcollision->ConvertConvexToCollide)(
                                       a1: physcollision,
                                       a2: v11,
                                       a3: *(_DWORD *)(v10 + 4),
                                       a4: a2);
  free(pMem: v11);
  *(_QWORD *)&params.massCenterOverride = *(_QWORD *)&g_PhysDefaultObjectParams.massCenterOverride;
  *(_QWORD *)&params.inertia = *(_QWORD *)&g_PhysDefaultObjectParams.inertia;
  *(_QWORD *)&params.rotdamping = *(_QWORD *)&g_PhysDefaultObjectParams.rotdamping;
  params.pName = g_PhysDefaultObjectParams.pName;
  *(_DWORD *)&params.enableCollisions = 1;
  *(_QWORD *)&params.volume = *(_QWORD *)&g_PhysDefaultObjectParams.volume;
  params.pGameData = this;
  v23 = physprops->GetSurfaceIndex(this: physprops, a2: "ice");
  v24 = (unsigned int)this->m_iEFlags >> 11;
  v25 = v23;
  nMaterialIndex = v23;
  if ( (v24 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v26 = physenv->CreatePolyObject(
          this: physenv,
          a2: v22,
          a3: v25,
          a4: &this->m_vecAbsOrigin,
          a5: &this->m_angAbsRotation,
          a6: &params);
  if ( (pInitBaseAnimating->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: pInitBaseAnimating, a2: (int)&savedregs);
  v27 = *(_QWORD *)&pInitBaseAnimating->m_vecAbsVelocity.x;
  vecInitialVelocity.z = pInitBaseAnimating->m_vecAbsVelocity.z;
  *(_QWORD *)&vecInitialVelocity.x = v27;
  v26->SetVelocity(this: v26, a2: &vecInitialVelocity, a3: nullptr);
  physprops->GetPhysicsProperties(
    this: physprops,
    a2: nMaterialIndex,
    a3: &flDensity,
    a4: &flThickness,
    a5: nullptr,
    a6: nullptr);
  v28 = flThickness + 0.5;
  if ( (float)(flThickness + 0.5) <= 1.0 )
  {
    flThickness = flThickness + 0.5;
    if ( v28 <= 0.0 )
      v29 = flTotalVolume;
    else
      v29 = v28 * flTotalSurfaceArea;
  }
  else
  {
    flThickness = 1.0;
    v29 = 1.0 * flTotalSurfaceArea;
  }
  ((void (__thiscall *)(IPhysicsObject *, _DWORD))v26->SetMass)(a1: v26, a2: (float)(v29 * 0.000016387063) * flDensity);
  v26->EnableGravity(this: v26, a2: true);
  CBaseEntity::VPhysicsSetObject(this, pPhysics: v26);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( pInitBaseAnimating != this )
  {
    TransferChildren(pOldParent: pInitBaseAnimating, pNewParent: this);
    m_Index = this->m_hMoveChild.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v32 = m_pEntity;
    if ( m_pEntity != nullptr )
    {
      do
      {
        v33 = (char *)__RTDynamicCast(
                        inptr: v32,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CEntityFreezing `RTTI Type Descriptor',
                        isReference: 0);
        if ( v33 != nullptr )
        {
          v34 = v33 + 868;
          if ( v33[868] != 1 )
          {
            if ( v33[84] != 0 )
            {
              v33[88] |= 1u;
            }
            else
            {
              v35 = *((CBaseEdict **)v33 + 6);
              if ( v35 != nullptr )
                CBaseEdict::StateChanged(this: v35, offset: 0x364u);
            }
            *v34 = 1;
          }
        }
        v36 = v32[56].__vftable;
        if ( v36 == (IHandleEntity_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_SerialNumber != (unsigned int)v36 >> 16 )
        {
          v37 = nullptr;
        }
        else
        {
          v37 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_pEntity;
        }
        v32 = v37;
      }
      while ( v37 != nullptr );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A4EB0
// Name: public: virtual bool CStatueProp::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CStatueProp::CreateVPhysics@<al>(CStatueProp *this@<ecx>, int a2@<ebx>)
{
  bool v3; // zf
  unsigned int m_Index; // ecx
  CStatueProp *m_pEntity; // eax

  v3 = this->m_pInitOBBs == nullptr;
  m_Index = this->m_hInitBaseAnimating.m_Value.m_Index;
  if ( v3 )
  {
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CStatueProp *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( CStatueProp::CreateVPhysicsFromHitBoxes(this, a2, pInitBaseAnimating: m_pEntity) != 0 )
      return 1;
    else
      return CStatueProp::CreateVPhysicsFromHitBoxes(this, a2, pInitBaseAnimating: this);
  }
  else if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    return CStatueProp::CreateVPhysicsFromOBBs(this, pInitBaseAnimating: nullptr);
  }
  else
  {
    return CStatueProp::CreateVPhysicsFromOBBs(
             this,
             pInitBaseAnimating: (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034B520
// Name: public: virtual float CBreakableProp::GetDmgModClub(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBreakableProp::GetDmgModClub(CChoreoScene *this)
{
  return this->m_flCurrentTime;
}

//------------------------------------------------------------------------------
// Address: 0x104077E0
// Name: DT_StatueProp::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_StatueProp::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_StatueProp::g_SendTable);
  return atexit(func: DT_StatueProp::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407800
// Name: DT_StatueProp::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_StatueProp::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_StatueProp::ignored>();
  DT_StatueProp::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407810
// Name: CStatueProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CStatueProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CStatueProp>();
  CStatueProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CE60
// Name: DT_StatueProp::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_StatueProp::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_StatueProp::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE70
// Name: _ServerClassInit_DT_StatueProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_StatueProp::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_168;
  for ( i = 6; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE90
// Name: _DataMapInit_CStatueProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CStatueProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_313);
}

//------------------------------------------------------------------------------
// Address: 0x1041CEA0
// Name: _DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_PhysBlockHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_314);
}

//------------------------------------------------------------------------------
// Address: 0x1041CEB0
// Name: _DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_PhysObjectHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_315);
}

//------------------------------------------------------------------------------
// Address: 0x1041CEC0
// Name: _dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PhysSaveRestoreBlockHandler__()
{
  CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short,CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CPhysCollide const *,BBox_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysCollideBBoxModels.m_Tree);
  CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysObjectCustomModels.m_Tree);
  CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_PhysObjectModels.m_Tree);
  CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short,CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CBaseEntity *,CPhysSaveRestoreBlockHandler::CEntityRestoreSet *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_PhysSaveRestoreBlockHandler.m_QueuedRestores.m_Tree);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PhysSaveRestoreBlockHandler.m_QueuedSaves);
}
