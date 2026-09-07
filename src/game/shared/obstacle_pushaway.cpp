// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/obstacle_pushaway.cpp
// Functions: 7
// ============================================================

#include "game\shared\obstacle_pushaway.h"

//------------------------------------------------------------------------------
// Address: 0x101273E0
// Name: public: bool Vector::IsZero(float)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Vector::IsZero(Vector *this, float tolerance)
{
  float v2; // xmm0_4
  float y; // xmm1_4
  float z; // xmm1_4
  BOOL result; // eax

  LODWORD(v2) = LODWORD(tolerance) ^ _mask__NegFloat_;
  result = false;
  if ( this->x > COERCE_FLOAT(LODWORD(tolerance) ^ _mask__NegFloat_) && tolerance > this->x )
  {
    y = this->y;
    if ( y > v2 && tolerance > y )
    {
      z = this->z;
      if ( z > v2 && tolerance > z )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10127430
// Name: bool IsPushAwayEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPushAwayEntity(C_BaseEntity *pEnt)
{
  return pEnt != nullptr && pEnt->m_CollisionGroup == 17;
}

//------------------------------------------------------------------------------
// Address: 0x10127450
// Name: public: virtual enum IterationRetval_t CPushAwayEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CPushAwayEnumerator::EnumElement(CPushAwayEnumerator *this, IHandleEntity *pHandleEntity)
{
  CBaseHandle *v3; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  int m_nAlreadyHit; // ecx

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v3->m_Index);
  if ( BaseEntityFromHandle != nullptr && BaseEntityFromHandle->m_CollisionGroup == 17 )
  {
    m_nAlreadyHit = this->m_nAlreadyHit;
    if ( m_nAlreadyHit < this->m_nMaxHits )
    {
      this->m_AlreadyHit[m_nAlreadyHit] = BaseEntityFromHandle;
      ++this->m_nAlreadyHit;
    }
  }
  return ITERATION_CONTINUE;
}

//------------------------------------------------------------------------------
// Address: 0x101274A0
// Name: bool IsPushableEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPushableEntity(C_BaseEntity *pEnt)
{
  return pEnt != nullptr
      && sv_turbophysics.m_pParent != nullptr
      && sv_turbophysics.m_pParent->m_Value.m_nValue != 0
      && pEnt->m_CollisionGroup == 0
      && FClassnameIs(pEntity: pEnt, szClassname: "class CPhysicsPropMultiplayer");
}

//------------------------------------------------------------------------------
// Address: 0x101274E0
// Name: int GetPushawayEnts(class C_BaseCombatCharacter __near *,class C_BaseEntity __near * __near *,int,float,int,class CPushAwayEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall GetPushawayEnts@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        C_BaseCombatCharacter *pPushingEntity,
        C_BaseEntity **ents,
        int nMaxEnts,
        float flPlayerExpand,
        int PartitionMask,
        CPushAwayEnumerator *enumerator)
{
  int v10; // edi
  float *v11; // eax
  IterationRetval_t (__thiscall *EnumElement)(struct CPushAwayEnumerator *, IHandleEntity *); // edx
  float *v13; // eax
  C_BaseCombatCharacter_vtbl *v14; // edx
  float v15; // xmm1_4
  int v16; // eax
  const Vector *v17; // eax
  CPushAwayEnumerator *v18; // edi
  CPushAwayEnumerator *v19; // esi
  CPushAwayEnumerator *v20; // eax
  void (__thiscall *EnumerateElementsAlongRay)(ISpatialPartition *, int, const Ray_t *, bool, IPartitionEnumerator *); // eax
  int m_nAlreadyHit; // edi
  _BYTE v25[12]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-70h]
  float v27; // [esp+54h] [ebp-1Ch] BYREF
  float v28; // [esp+58h] [ebp-18h]
  float v29; // [esp+5Ch] [ebp-14h]
  CPushAwayEnumerator *v30; // [esp+60h] [ebp-10h]
  int v31; // [esp+64h] [ebp-Ch]
  void *v32; // [esp+68h] [ebp-8h]
  void *retaddr; // [esp+70h] [ebp+0h]

  v31 = a1;
  v32 = retaddr;
  v10 = ((int (__thiscall *)(C_BaseCombatCharacter *, int, int))pPushingEntity->GetCollideable)(
          a1: pPushingEntity,
          a2,
          a3);
  v30 = (CPushAwayEnumerator *)pPushingEntity->GetCollideable(this: pPushingEntity);
  v11 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
  v27 = *v11 + flPlayerExpand;
  v28 = v11[1] + flPlayerExpand;
  EnumElement = v30->__vftable[1].EnumElement;
  v29 = v11[2] + flPlayerExpand;
  v13 = (float *)((int (__thiscall *)(CPushAwayEnumerator *))EnumElement)(a1: v30);
  v14 = pPushingEntity->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  *(float *)(&ray.m_IsSwept + 3) = *v13 - flPlayerExpand;
  *(float *)(&ray.m_IsSwept + 7) = v13[1] - flPlayerExpand;
  v15 = v13[2];
  v27 = COERCE_FLOAT(&v27);
  v16 = ((int (__thiscall *)(C_BaseCombatCharacter *, _DWORD))v14->GetAbsOrigin)(
          a1: pPushingEntity,
          a2: v15 - flPlayerExpand);
  v17 = (const Vector *)((int (__thiscall *)(C_BaseCombatCharacter *, int))pPushingEntity->GetAbsOrigin)(
                          a1: pPushingEntity,
                          a2: v16);
  Ray_t::Init(
    this: (Ray_t *)v25,
    start: v17,
    end: (const Vector *)LODWORD(v28),
    mins: (const Vector *)LODWORD(v29),
    maxs: (const Vector *)v30);
  v18 = enumerator;
  v19 = nullptr;
  if ( enumerator == nullptr )
  {
    v20 = (CPushAwayEnumerator *)MemAlloc_Alloc(nSize: 0x10u);
    if ( v20 != nullptr )
    {
      v20->m_nAlreadyHit = 0;
      v20->__vftable = (CPushAwayEnumerator_vtbl *)&CPushAwayEnumerator::`vftable';
      v20->m_AlreadyHit = ents;
      v20->m_nMaxHits = nMaxEnts;
      v19 = v20;
    }
    v18 = v19;
  }
  EnumerateElementsAlongRay = partition->EnumerateElementsAlongRay;
  v30 = v18;
  ((void (__thiscall *)(ISpatialPartition *, int, _BYTE *, _DWORD))EnumerateElementsAlongRay)(
    a1: partition,
    a2: PartitionMask,
    a3: v25,
    a4: 0);
  m_nAlreadyHit = v18->m_nAlreadyHit;
  if ( v19 != nullptr )
    C_BaseEntity::operator delete(pMem: v19);
  return m_nAlreadyHit;
}

//------------------------------------------------------------------------------
// Address: 0x10127620
// Name: void AvoidPushawayProps(class C_BaseCombatCharacter __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall AvoidPushawayProps(
        C_BaseEntity *a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        C_BaseCombatCharacter *pPlayer,
        CUserCmd *pCmd)
{
  char v5; // al
  QAngle *p_viewangles; // eax
  int PushawayEnts; // esi
  const Vector *(__thiscall *WorldSpaceCenter)(C_BaseEntity *); // eax
  int v9; // ebx
  const Vector *v10; // edi
  int (__thiscall ***v11)(_DWORD); // eax
  int (__thiscall ***v12)(_DWORD); // esi
  float v13; // xmm0_4
  double v14; // st7
  C_BaseEntity *v15; // ecx
  double v16; // st7
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  const Vector *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm4_4
  float m_fValue; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  C_BaseEntity *props[512]; // [esp+18h] [ebp-848h] BYREF
  Vector nearestPlayerPoint; // [esp+818h] [ebp-48h] BYREF
  Vector currentdir; // [esp+824h] [ebp-3Ch] BYREF
  Vector rightdir; // [esp+830h] [ebp-30h] BYREF
  int nEnts; // [esp+83Ch] [ebp-24h]
  Vector nearestPropPoint; // [esp+840h] [ebp-20h] BYREF
  float flDist; // [esp+84Ch] [ebp-14h]
  float mass; // [esp+850h] [ebp-10h]
  Vector vPushAway; // [esp+854h] [ebp-Ch] BYREF

  v5 = ((int (__thiscall *)(C_GameRules *, C_BaseEntity *))g_pGameRules->IsTopDown)(a1: g_pGameRules, a2: props[0]);
  props[0] = nullptr;
  if ( v5 != 0 )
    p_viewangles = g_pGameRules->GetTopDownMovementAxis(this: g_pGameRules);
  else
    p_viewangles = &pCmd->viewangles;
  AngleVectors(angles: p_viewangles, forward: &currentdir, right: &rightdir, up: (Vector *)props[0]);
  props[0] = a1;
  PushawayEnts = GetPushawayEnts(
                   pPushingEntity: pPlayer,
                   ents: props,
                   nMaxEnts: 512,
                   flPlayerExpand: 0.0,
                   PartitionMask: 4,
                   enumerator: nullptr);
  WorldSpaceCenter = pPlayer->WorldSpaceCenter;
  nEnts = PushawayEnts;
  v9 = 0;
  v10 = (const Vector *)((int (__thiscall *)(C_BaseCombatCharacter *, int, int))WorldSpaceCenter)(a1: pPlayer, a2, a3);
  while ( v9 < nEnts )
  {
    v11 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                          inptr: props[v9],
                                          VfDelta: 0,
                                          SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                          TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                          isReference: 0);
    v12 = v11;
    if ( v11 != nullptr && (**v11)(a1: v11) != 1 )
      goto LABEL_37;
    v13 = 30.0;
    if ( v12 != nullptr )
    {
      v14 = ((double (__thiscall *)(int (__thiscall ***)(_DWORD)))(*v12)[1])(a1: v12);
      mass = v14;
      if ( v14 >= 10.0 )
      {
        v13 = mass;
        if ( mass > 30.0 )
          v13 = 30.0;
      }
      else
      {
        v13 = 10.0;
      }
    }
    if ( v13 <= 0.0 )
      v13 = 0.0;
    v15 = props[v9];
    mass = v13 * 0.033333335;
    CCollisionProperty::CalcNearestPoint(
      this: &v15->m_Collision,
      vecWorldPt: v10,
      pVecNearestWorldPt: &nearestPropPoint);
    CCollisionProperty::CalcNearestPoint(
      this: &pPlayer->m_Collision,
      vecWorldPt: &nearestPropPoint,
      pVecNearestWorldPt: &nearestPlayerPoint);
    vPushAway.x = nearestPlayerPoint.x - nearestPropPoint.x;
    vPushAway.y = nearestPlayerPoint.y - nearestPropPoint.y;
    vPushAway.z = nearestPlayerPoint.z - nearestPropPoint.z;
    v16 = VectorNormalize(vec: &vPushAway);
    flDist = v16;
    if ( v16 > 5.0 && !CCollisionProperty::IsPointInBounds(this: &pPlayer->m_Collision, vecWorldPt: &nearestPropPoint) )
      goto LABEL_37;
    x = vPushAway.x;
    y = vPushAway.y;
    if ( vPushAway.x <= -0.0099999998 )
      goto LABEL_31;
    if ( vPushAway.x < 0.0099999998 && vPushAway.y > -0.0099999998 && vPushAway.y < 0.0099999998 )
    {
      z = vPushAway.z;
      if ( vPushAway.z <= -0.0099999998 || vPushAway.z >= 0.0099999998 )
        goto LABEL_24;
      v20 = v10->y - nearestPropPoint.y;
      v21 = v10->z - nearestPropPoint.z;
      vPushAway.x = v10->x - nearestPropPoint.x;
      vPushAway.y = v20;
      vPushAway.z = v21;
      flDist = VectorNormalize(vec: &vPushAway);
      y = vPushAway.y;
      x = vPushAway.x;
    }
    z = vPushAway.z;
LABEL_24:
    if ( x > -0.0099999998
      && x < 0.0099999998
      && y > -0.0099999998
      && y < 0.0099999998
      && z > -0.0099999998
      && z < 0.0099999998 )
    {
      v22 = props[v9]->WorldSpaceCenter(this: props[v9]);
      v23 = v10->y - v22->y;
      v24 = v10->z - v22->z;
      vPushAway.x = v10->x - v22->x;
      vPushAway.y = v23;
      vPushAway.z = v24;
      flDist = VectorNormalize(vec: &vPushAway);
      y = vPushAway.y;
      x = vPushAway.x;
LABEL_31:
      z = vPushAway.z;
    }
    v25 = flDist;
    if ( flDist <= 1.0 )
      v25 = 1.0;
    m_fValue = (float)(sv_pushaway_player_force.m_pParent->m_Value.m_fValue / v25) * mass;
    if ( sv_pushaway_max_player_force.m_pParent->m_Value.m_fValue <= m_fValue )
      m_fValue = sv_pushaway_max_player_force.m_pParent->m_Value.m_fValue;
    v27 = m_fValue * 0.25;
    v28 = x * v27;
    v29 = y * v27;
    v30 = v27 * z;
    pCmd->forwardmove = (float)((float)((float)(currentdir.y * v29) + (float)(currentdir.x * v28))
                              + (float)(currentdir.z * v30))
                      + pCmd->forwardmove;
    vPushAway.y = v29;
    vPushAway.x = v28;
    v31 = (float)((float)((float)(rightdir.y * v29) + (float)(rightdir.x * v28)) + (float)(rightdir.z * v30))
        + pCmd->sidemove;
    vPushAway.z = v30;
    pCmd->sidemove = v31;
LABEL_37:
    ++v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101279C0
// Name: void PerformObstaclePushaway(class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall PerformObstaclePushaway(
        float a1@<ebp>,
        float *a2@<edi>,
        int a3@<esi>,
        C_BaseCombatCharacter *pPushingEntity)
{
  C_BaseEntity *v4; // eax
  int PushawayEnts; // eax
  float y; // esi
  int (__thiscall ***v7)(_DWORD); // eax
  __int128 v8; // xmm0
  float *v9; // esi
  const Vector *v10; // eax
  double v11; // st7
  float v12; // xmm1_4
  float m_fValue; // xmm0_4
  int v14; // esi
  const Vector *(__thiscall *WorldSpaceCenter)(C_BaseEntity *); // eax
  int v17; // [esp+10h] [ebp-458h]
  C_BaseEntity *v18[3]; // [esp+1Ch] [ebp-44Ch] BYREF
  __int128 props_1012; // [esp+41Ch] [ebp-4Ch] OVERLAPPED
  float v20[3]; // [esp+434h] [ebp-34h] BYREF
  float v21; // [esp+440h] [ebp-28h]
  int v22; // [esp+444h] [ebp-24h]
  float v23; // [esp+448h] [ebp-20h] BYREF
  float flDist; // [esp+44Ch] [ebp-1Ch]
  int nEnts; // [esp+450h] [ebp-18h]
  Vector vPushAway; // [esp+454h] [ebp-14h] BYREF
  IPhysicsObject *pObj; // [esp+460h] [ebp-8h]
  IPhysicsObject *retaddr; // [esp+468h] [ebp+0h]

  vPushAway.z = a1;
  pObj = retaddr;
  v17 = a3;
  if ( pPushingEntity->m_lifeState == 0
    && sv_pushaway_clientside.m_pParent != nullptr
    && sv_pushaway_clientside.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = pPushingEntity->IsPlayer(this: pPushingEntity)
       ? (C_BaseEntity *)__RTDynamicCast(
                           inptr: pPushingEntity,
                           VfDelta: 0,
                           SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                           TargetType: &C_BasePlayer `RTTI Type Descriptor',
                           isReference: 0)
       : nullptr;
    if ( sv_pushaway_clientside.m_pParent == nullptr
      || sv_pushaway_clientside.m_pParent->m_Value.m_nValue != 1
      || v4 != nullptr && C_BasePlayer::IsLocalPlayer(pEntity: v4) )
    {
      PushawayEnts = GetPushawayEnts(
                       a1: (int)&vPushAway.z,
                       a2: (int)pPushingEntity,
                       a3,
                       pPushingEntity,
                       ents: v18,
                       nMaxEnts: 256,
                       flPlayerExpand: 3.0,
                       PartitionMask: 8,
                       enumerator: nullptr);
      y = 0.0;
      v22 = PushawayEnts;
      vPushAway.y = 0.0;
      if ( PushawayEnts > 0 )
      {
        do
        {
          v7 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                               inptr: v18[LODWORD(y)],
                                               VfDelta: 0,
                                               SrcType: &C_BaseEntity `RTTI Type Descriptor',
                                               TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                               isReference: 0);
          if ( v7 == nullptr
            || (**v7)(a1: v7) != 1
            || (C_BaseEntity::CalcAbsoluteVelocity(this: pPushingEntity),
                v8 = 0,
                *(float *)&v8 = fsqrt(
                                  (float)(pPushingEntity->m_vecAbsVelocity.x * pPushingEntity->m_vecAbsVelocity.x)
                                + (float)(pPushingEntity->m_vecAbsVelocity.y * pPushingEntity->m_vecAbsVelocity.y)),
                props_1012 = v8,
                sv_pushaway_min_player_speed.m_pParent->m_Value.m_fValue <= *(float *)&v8) )
          {
            LODWORD(vPushAway.x) = v18[LODWORD(y)]->m_pPhysicsObject;
            if ( LODWORD(vPushAway.x) != 0 )
            {
              v9 = (float *)((int (__thiscall *)(C_BaseCombatCharacter *, float *, int))pPushingEntity->WorldSpaceCenter)(
                              a1: pPushingEntity,
                              a2,
                              a3: v17);
              v10 = v18[LODWORD(vPushAway.y)]->WorldSpaceCenter(this: v18[LODWORD(vPushAway.y)]);
              v23 = v10->x - *v9;
              flDist = v10->y - v9[1];
              *(float *)&nEnts = 0.0;
              v11 = VectorNormalize(vec: (Vector *)&v23);
              v21 = v11;
              if ( v11 > 1.0 )
                v12 = v21;
              else
                v12 = 1.0;
              m_fValue = sv_pushaway_force.m_pParent->m_Value.m_fValue / v12;
              if ( sv_pushaway_max_force.m_pParent->m_Value.m_fValue <= m_fValue )
                m_fValue = sv_pushaway_max_force.m_pParent->m_Value.m_fValue;
              v14 = *(_DWORD *)LODWORD(vPushAway.x);
              WorldSpaceCenter = pPushingEntity->WorldSpaceCenter;
              v20[0] = v23 * m_fValue;
              v20[1] = flDist * m_fValue;
              v20[2] = m_fValue * *(float *)&nEnts;
              v17 = (int)WorldSpaceCenter(this: pPushingEntity);
              a2 = v20;
              (*(void (__thiscall **)(_DWORD))(v14 + 244))(a1: LODWORD(vPushAway.x));
              y = vPushAway.y;
            }
          }
          ++LODWORD(y);
          vPushAway.y = y;
        }
        while ( SLODWORD(y) < v22 );
      }
    }
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1017B120
// Name: bool IsPushAwayEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsPushAwayEntity(CBaseEntity *pEnt)
{
  _DWORD *v1; // eax
  int v2; // eax
  bool v3; // zf
  _DWORD *v5; // eax

  if ( pEnt == nullptr )
    return 0;
  if ( pEnt->m_CollisionGroup.m_Value != 17 )
  {
    if ( pEnt->m_iClassname.pszValue == "func_door_rotating"
      || CBaseEntity::ClassMatchesComplex(this: pEnt, pszClassOrWildcard: "func_door_rotating") != 0 )
    {
      v1 = __RTDynamicCast(
             inptr: pEnt,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CBaseDoor `RTTI Type Descriptor',
             isReference: 0);
      if ( v1 == nullptr )
        return 0;
      v2 = v1[213];
      v3 = v2 == 2;
    }
    else
    {
      if ( pEnt->m_iClassname.pszValue != "prop_door_rotating"
        && CBaseEntity::ClassMatchesComplex(this: pEnt, pszClassOrWildcard: "prop_door_rotating") == 0 )
      {
        return 0;
      }
      v5 = __RTDynamicCast(
             inptr: pEnt,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CBasePropDoor `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 == nullptr )
        return 0;
      v2 = v5[413];
      v3 = v2 == 1;
    }
    if ( !v3 && v2 != 3 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017B1D0
// Name: bool IsPushableEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsPushableEntity(CBaseEntity *pEnt)
{
  return pEnt != nullptr
      && sv_turbophysics.m_pParent != nullptr
      && sv_turbophysics.m_pParent->m_Value.m_nValue != 0
      && pEnt->m_CollisionGroup.m_Value == 0
      && (pEnt->m_iClassname.pszValue == "prop_physics_multiplayer"
       || CBaseEntity::ClassMatchesComplex(this: pEnt, pszClassOrWildcard: "prop_physics_multiplayer") != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017B220
// Name: bool IsBreakableEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsBreakableEntity(CBaseEntity *pEnt)
{
  int m_Value; // eax
  int (__thiscall ***v2)(_DWORD); // eax
  void *v4; // eax
  int *v5; // eax

  if ( pEnt == nullptr )
    return false;
  if ( pEnt->m_takedamage.m_Value != 2 )
    return false;
  m_Value = pEnt->m_CollisionGroup.m_Value;
  if ( m_Value != 17 && m_Value != 6 && m_Value != 0 )
    return false;
  if ( pEnt->m_iHealth.m_Value > 200 )
    return false;
  v2 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                       inptr: pEnt,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                       isReference: 0);
  if ( v2 != nullptr )
  {
    if ( (**v2)(a1: v2) != 1 )
      return false;
  }
  else if ( FClassnameIs(pEntity: pEnt, szClassname: "func_breakable")
         || FClassnameIs(pEntity: pEnt, szClassname: "func_breakable_surf") )
  {
    if ( FClassnameIs(pEntity: pEnt, szClassname: "func_breakable_surf")
      && LOBYTE(pEnt[1].m_hMoveParent.m_Value.m_Index) != 0 )
    {
      return false;
    }
  }
  else if ( (pEnt->PhysicsSolidMaskForEntity(this: pEnt) & 0x10000) != 0 )
  {
    return false;
  }
  v4 = __RTDynamicCast(
         inptr: pEnt,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &IBreakableWithPropData `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr && ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v4 + 12))(a1: v4) <= 0.0 )
    return false;
  v5 = (int *)__RTDynamicCast(
                inptr: pEnt,
                VfDelta: 0,
                SrcType: &CBaseEntity `RTTI Type Descriptor',
                TargetType: &CBreakableProp `RTTI Type Descriptor',
                isReference: 0);
  return v5 == nullptr || v5[312] < 50;
}

//------------------------------------------------------------------------------
// Address: 0x1017B340
// Name: int GetPushawayEnts(class CBaseCombatCharacter __near *,class CBaseEntity __near * __near *,int,float,int,class CPushAwayEnumerator __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall GetPushawayEnts@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseCombatCharacter *pPushingEntity,
        CBaseEntity **ents,
        int nMaxEnts,
        float flPlayerExpand,
        int PartitionMask,
        CPushAwayEnumerator *enumerator)
{
  int v9; // edi
  float *v10; // eax
  const Vector *(__thiscall *OBBMins)(ICollideable *); // edx
  float *v12; // eax
  float v13; // xmm1_4
  unsigned int v14; // eax
  CPushAwayEnumerator *v15; // edi
  CPushAwayEnumerator *v16; // esi
  CPushAwayEnumerator *v17; // eax
  void (__thiscall *EnumerateElementsAlongRay)(ISpatialPartition *, int, const Ray_t *, bool, IPartitionEnumerator *); // eax
  int m_nAlreadyHit; // edi
  _BYTE v21[12]; // [esp-Ch] [ebp-7Ch] BYREF
  Ray_t ray; // [esp+0h] [ebp-70h] BYREF
  float v23; // [esp+50h] [ebp-20h]
  Vector v24; // [esp+54h] [ebp-1Ch] BYREF
  ICollideable *v25; // [esp+60h] [ebp-10h]
  _DWORD v26[3]; // [esp+64h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v26[0] = a1;
  v26[1] = retaddr;
  v9 = ((int (__thiscall *)(CBaseCombatCharacter *, int, int))pPushingEntity->GetCollideable)(
         a1: pPushingEntity,
         a2,
         a3);
  v25 = pPushingEntity->GetCollideable(this: pPushingEntity);
  v10 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  v24.x = *v10 + flPlayerExpand;
  v24.y = v10[1] + flPlayerExpand;
  OBBMins = v25->OBBMins;
  v24.z = v10[2] + flPlayerExpand;
  v12 = (float *)OBBMins(this: v25);
  *(float *)(&ray.m_IsSwept + 3) = *v12 - flPlayerExpand;
  *(float *)(&ray.m_IsSwept + 7) = v12[1] - flPlayerExpand;
  v13 = v12[2];
  v14 = (unsigned int)pPushingEntity->m_iEFlags >> 11;
  v23 = v13 - flPlayerExpand;
  if ( (v14 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPushingEntity, a2: (int)v26);
  if ( (pPushingEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPushingEntity, a2: (int)v26);
  Ray_t::Init(
    this: (Ray_t *)v21,
    start: &pPushingEntity->m_vecAbsOrigin,
    end: &pPushingEntity->m_vecAbsOrigin,
    mins: (const Vector *)(&ray.m_IsSwept + 3),
    maxs: &v24);
  v15 = enumerator;
  v16 = nullptr;
  if ( enumerator == nullptr )
  {
    v17 = (CPushAwayEnumerator *)operator new(nSize: 0x10u);
    if ( v17 != nullptr )
    {
      v17->m_nAlreadyHit = 0;
      v17->__vftable = (CPushAwayEnumerator_vtbl *)&CPushAwayEnumerator::`vftable';
      v17->m_AlreadyHit = ents;
      v17->m_nMaxHits = nMaxEnts;
      v16 = v17;
    }
    v15 = v16;
  }
  EnumerateElementsAlongRay = partition->EnumerateElementsAlongRay;
  v25 = (ICollideable *)v15;
  ((void (__thiscall *)(ISpatialPartition *, int, _BYTE *, _DWORD))EnumerateElementsAlongRay)(
    a1: partition,
    a2: PartitionMask,
    a3: v21,
    a4: 0);
  m_nAlreadyHit = v15->m_nAlreadyHit;
  if ( v16 != nullptr )
    free(pMem: v16);
  return m_nAlreadyHit;
}

//------------------------------------------------------------------------------
// Address: 0x1017B490
// Name: void AvoidPushawayProps(class CBaseCombatCharacter __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall AvoidPushawayProps(
        CBaseEntity *a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseCombatCharacter *pPlayer,
        CUserCmd *pCmd)
{
  char v5; // al
  QAngle *p_viewangles; // eax
  int PushawayEnts; // esi
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  int v9; // ebx
  const Vector *i; // edi
  int (__thiscall ***v11)(_DWORD); // eax
  int (__thiscall ***v12)(_DWORD); // esi
  float v13; // xmm0_4
  double v14; // st7
  CBaseEntity *v15; // ecx
  double v16; // st7
  float x; // xmm3_4
  float y; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  const Vector *v21; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float m_fValue; // xmm1_4
  CBaseEntity *v27; // ecx
  CBaseEntity *v28; // ecx
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  CBaseEntity *props[512]; // [esp+18h] [ebp-84Ch] BYREF
  Vector nearestPlayerPoint; // [esp+818h] [ebp-4Ch] BYREF
  Vector currentdir; // [esp+824h] [ebp-40h] BYREF
  Vector rightdir; // [esp+830h] [ebp-34h] BYREF
  int nEnts; // [esp+83Ch] [ebp-28h]
  Vector nearestPropPoint; // [esp+840h] [ebp-24h] BYREF
  float flDist; // [esp+84Ch] [ebp-18h]
  float mass; // [esp+850h] [ebp-14h]
  float flForce; // [esp+854h] [ebp-10h]
  Vector vPushAway; // [esp+858h] [ebp-Ch] BYREF
  int savedregs; // [esp+864h] [ebp+0h] BYREF

  v5 = ((int (__thiscall *)(CGameRules *, CBaseEntity *))g_pGameRules->IsTopDown)(a1: g_pGameRules, a2: props[0]);
  props[0] = nullptr;
  if ( v5 != 0 )
    p_viewangles = g_pGameRules->GetTopDownMovementAxis(this: g_pGameRules);
  else
    p_viewangles = &pCmd->viewangles;
  AngleVectors(angles: p_viewangles, forward: &currentdir, right: &rightdir, up: (Vector *)props[0]);
  props[0] = a1;
  PushawayEnts = GetPushawayEnts(
                   a1: (int)&savedregs,
                   a2: (int)pPlayer,
                   a3,
                   pPushingEntity: pPlayer,
                   ents: props,
                   nMaxEnts: 512,
                   flPlayerExpand: 0.0,
                   PartitionMask: 1,
                   enumerator: nullptr);
  WorldSpaceCenter = pPlayer->WorldSpaceCenter;
  nEnts = PushawayEnts;
  v9 = 0;
  for ( i = (const Vector *)((int (__thiscall *)(CBaseCombatCharacter *, int, int))WorldSpaceCenter)(
                              a1: pPlayer,
                              a2,
                              a3); v9 < nEnts; ++v9 )
  {
    v11 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                          inptr: props[v9],
                                          VfDelta: 0,
                                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                                          TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                          isReference: 0);
    v12 = v11;
    if ( v11 == nullptr || (**v11)(a1: v11) == 1 )
    {
      v13 = 30.0;
      if ( v12 != nullptr )
      {
        v14 = ((double (__thiscall *)(int (__thiscall ***)(_DWORD)))(*v12)[1])(a1: v12);
        mass = v14;
        if ( v14 >= 10.0 )
        {
          v13 = mass;
          if ( mass > 30.0 )
            v13 = 30.0;
        }
        else
        {
          v13 = 10.0;
        }
      }
      if ( v13 <= 0.0 )
        v13 = 0.0;
      v15 = props[v9];
      mass = v13 * 0.033333335;
      CCollisionProperty::CalcNearestPoint(
        this: &v15->m_Collision,
        vecWorldPt: i,
        pVecNearestWorldPt: &nearestPropPoint);
      CCollisionProperty::CalcNearestPoint(
        this: &pPlayer->m_Collision,
        vecWorldPt: &nearestPropPoint,
        pVecNearestWorldPt: &nearestPlayerPoint);
      vPushAway.x = nearestPlayerPoint.x - nearestPropPoint.x;
      vPushAway.y = nearestPlayerPoint.y - nearestPropPoint.y;
      vPushAway.z = nearestPlayerPoint.z - nearestPropPoint.z;
      v16 = VectorNormalize(vec: &vPushAway);
      flDist = v16;
      if ( v16 <= 5.0 || CCollisionProperty::IsPointInBounds(this: &pPlayer->m_Collision, vecWorldPt: &nearestPropPoint) )
      {
        x = vPushAway.x;
        if ( vPushAway.x > -0.0099999998 )
        {
          y = vPushAway.y;
          if ( vPushAway.x < 0.0099999998
            && vPushAway.y > -0.0099999998
            && vPushAway.y < 0.0099999998
            && vPushAway.z > -0.0099999998
            && vPushAway.z < 0.0099999998 )
          {
            v19 = i->y - nearestPropPoint.y;
            v20 = i->z - nearestPropPoint.z;
            vPushAway.x = i->x - nearestPropPoint.x;
            vPushAway.y = v19;
            vPushAway.z = v20;
            flDist = VectorNormalize(vec: &vPushAway);
            y = vPushAway.y;
            x = vPushAway.x;
          }
          if ( x > -0.0099999998
            && x < 0.0099999998
            && y > -0.0099999998
            && y < 0.0099999998
            && vPushAway.z > -0.0099999998
            && vPushAway.z < 0.0099999998 )
          {
            v21 = props[v9]->WorldSpaceCenter(this: props[v9]);
            v22 = i->y - v21->y;
            v23 = i->z - v21->z;
            vPushAway.x = i->x - v21->x;
            vPushAway.y = v22;
            vPushAway.z = v23;
            flDist = VectorNormalize(vec: &vPushAway);
          }
        }
        v24 = flDist;
        if ( flDist <= 1.0 )
          v24 = 1.0;
        v25 = (float)(sv_pushaway_player_force.m_pParent->m_Value.m_fValue / v24) * mass;
        m_fValue = sv_pushaway_max_player_force.m_pParent->m_Value.m_fValue;
        flForce = v25;
        if ( m_fValue <= v25 )
          flForce = m_fValue;
        pPlayer->PushawayTouch(this: pPlayer, a2: props[v9]);
        v27 = props[v9];
        if ( v27 != nullptr
          && (v27->m_iClassname.pszValue == "func_door_rotating"
           || CBaseEntity::ClassMatchesComplex(this: v27, pszClassOrWildcard: "func_door_rotating") != 0)
          || (v28 = props[v9]) != nullptr
          && (v28->m_iClassname.pszValue == "prop_door_rotating"
           || CBaseEntity::ClassMatchesComplex(this: v28, pszClassOrWildcard: "prop_door_rotating") != 0) )
        {
          v29 = flForce * 0.25;
        }
        else
        {
          v29 = flForce;
        }
        v30 = vPushAway.x * v29;
        v31 = vPushAway.y * v29;
        v32 = vPushAway.z * v29;
        pCmd->forwardmove = (float)((float)((float)(currentdir.y * (float)(vPushAway.y * v29))
                                          + (float)(currentdir.x * (float)(vPushAway.x * v29)))
                                  + (float)(currentdir.z * (float)(vPushAway.z * v29)))
                          + pCmd->forwardmove;
        vPushAway.y = v31;
        vPushAway.x = v30;
        v33 = (float)((float)((float)(rightdir.y * v31) + (float)(rightdir.x * v30)) + (float)(rightdir.z * v32))
            + pCmd->sidemove;
        vPushAway.z = v32;
        pCmd->sidemove = v33;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017B8A0
// Name: void PerformObstaclePushaway(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall PerformObstaclePushaway(
        IPhysicsObject *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseCombatCharacter *pPushingEntity)
{
  CBaseEntity **v4; // edi
  int (__thiscall ***v5)(_DWORD); // eax
  __int128 v6; // xmm0
  float *v7; // edi
  float *v8; // eax
  double v9; // st7
  float y; // xmm1_4
  float m_fValue; // xmm0_4
  int v12; // edi
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  CBaseEntity *v14; // [esp-8h] [ebp-470h]
  float *v15; // [esp+Ch] [ebp-45Ch]
  CBaseEntity *v17[3]; // [esp+1Ch] [ebp-44Ch] BYREF
  __int128 props_1012; // [esp+41Ch] [ebp-4Ch] OVERLAPPED
  float v19[3]; // [esp+434h] [ebp-34h] BYREF
  int PushawayEnts; // [esp+440h] [ebp-28h]
  float v21; // [esp+444h] [ebp-24h] BYREF
  float v22; // [esp+448h] [ebp-20h]
  int nEnts; // [esp+44Ch] [ebp-1Ch]
  Vector vPushAway; // [esp+450h] [ebp-18h]
  IPhysicsObject *pObj; // [esp+45Ch] [ebp-Ch] BYREF
  float flDist; // [esp+460h] [ebp-8h]
  float retaddr; // [esp+468h] [ebp+0h]

  pObj = a1;
  flDist = retaddr;
  v15 = (float *)a2;
  if ( pPushingEntity->m_lifeState.m_Value == 0 )
  {
    PushawayEnts = GetPushawayEnts(
                     a1: (int)&pObj,
                     a2,
                     a3: (int)pPushingEntity,
                     pPushingEntity,
                     ents: v17,
                     nMaxEnts: 256,
                     flPlayerExpand: 3.0,
                     PartitionMask: 1,
                     enumerator: nullptr);
    vPushAway.z = 0.0;
    if ( PushawayEnts > 0 )
    {
      do
      {
        v4 = &v17[LODWORD(vPushAway.z)];
        v14 = *v4;
        LODWORD(vPushAway.y) = v4;
        v5 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                             inptr: v14,
                                             VfDelta: 0,
                                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                                             TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                             isReference: 0);
        if ( v5 == nullptr || (**v5)(a1: v5) != 1 )
          goto LABEL_8;
        if ( (pPushingEntity->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this: pPushingEntity, a2: (int)&pObj);
        v6 = 0;
        *(float *)&v6 = fsqrt(
                          (float)(pPushingEntity->m_vecAbsVelocity.x * pPushingEntity->m_vecAbsVelocity.x)
                        + (float)(pPushingEntity->m_vecAbsVelocity.y * pPushingEntity->m_vecAbsVelocity.y));
        props_1012 = v6;
        if ( sv_pushaway_min_player_speed.m_pParent->m_Value.m_fValue <= *(float *)&v6 )
        {
LABEL_8:
          LODWORD(vPushAway.x) = (*v4)->m_pPhysicsObject;
          if ( LODWORD(vPushAway.x) != 0 )
          {
            v7 = (float *)((int (__thiscall *)(CBaseCombatCharacter *, float *, int))pPushingEntity->WorldSpaceCenter)(
                            a1: pPushingEntity,
                            a2: v15,
                            a3);
            v8 = (float *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)LODWORD(vPushAway.y) + 588))(a1: *(_DWORD *)LODWORD(vPushAway.y));
            v21 = *v8 - *v7;
            v22 = v8[1] - v7[1];
            *(float *)&nEnts = 0.0;
            v9 = VectorNormalize(vec: (Vector *)&v21);
            vPushAway.y = v9;
            if ( v9 > 1.0 )
              y = vPushAway.y;
            else
              y = 1.0;
            m_fValue = sv_pushaway_force.m_pParent->m_Value.m_fValue / y;
            if ( sv_pushaway_max_force.m_pParent->m_Value.m_fValue <= m_fValue )
              m_fValue = sv_pushaway_max_force.m_pParent->m_Value.m_fValue;
            v12 = *(_DWORD *)LODWORD(vPushAway.x);
            WorldSpaceCenter = pPushingEntity->WorldSpaceCenter;
            v19[0] = v21 * m_fValue;
            v19[1] = v22 * m_fValue;
            v19[2] = m_fValue * *(float *)&nEnts;
            a3 = (int)WorldSpaceCenter(this: pPushingEntity);
            v15 = v19;
            (*(void (__thiscall **)(_DWORD))(v12 + 244))(a1: LODWORD(vPushAway.x));
          }
        }
        ++LODWORD(vPushAway.z);
      }
      while ( SLODWORD(vPushAway.z) < PushawayEnts );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017BAA0
// Name: public: virtual enum IterationRetval_t CPushAwayEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CPushAwayEnumerator::EnumElement(CPushAwayEnumerator *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v6; // edi
  int m_nAlreadyHit; // eax

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index != -1
    && (v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index])->m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = v4->m_pEntity) != nullptr )
  {
    v6 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  }
  else
  {
    v6 = nullptr;
  }
  if ( IsPushAwayEntity(pEnt: v6) != 0 )
  {
    m_nAlreadyHit = this->m_nAlreadyHit;
    if ( m_nAlreadyHit < this->m_nMaxHits )
    {
      this->m_AlreadyHit[m_nAlreadyHit] = v6;
      ++this->m_nAlreadyHit;
    }
  }
  return ITERATION_CONTINUE;
}

} // namespace server
