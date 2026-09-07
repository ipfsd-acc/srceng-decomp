// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_main.cpp
// Functions: 46
// ============================================================

#include "game\server\physics_main.h"

//------------------------------------------------------------------------------
// Address: 0x10191DB0
// Name: private: void CBaseEntity::PhysicsNone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsNone(CBaseEntity *this)
{
  CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS);
}

//------------------------------------------------------------------------------
// Address: 0x10191DC0
// Name: Physics_TraceEntity
// Source: json
//------------------------------------------------------------------------------
void __usercall Physics_TraceEntity(
        CBaseEntity *pBaseEntity@<esi>,
        CGameTrace *ptr@<edi>,
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        unsigned int mask)
{
  if ( pBaseEntity->GetDamageType(this: pBaseEntity) != 0 )
    g_pGameRules->WeaponTraceEntity(
      this: g_pGameRules,
      a2: pBaseEntity,
      a3: vecAbsStart,
      a4: vecAbsEnd,
      a5: mask,
      a6: ptr);
  else
    UTIL_TraceEntity(pEntity: pBaseEntity, vecAbsStart, vecAbsEnd, mask, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10191E10
// Name: protected: virtual void CPhysicsPushedEntities::FinishRotPushedEntity(class CBaseEntity __near *,struct CPhysicsPushedEntities::RotatingPushMove_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::FinishRotPushedEntity(
        CPhysicsPushedEntities *this,
        CBaseEntity *pPushedEntity,
        const CPhysicsPushedEntities::RotatingPushMove_t *rotPushMove)
{
  float z; // eax
  float y; // xmm0_4
  float v5; // edx
  float v6; // xmm0_4
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( pPushedEntity->IsPlayer(this: pPushedEntity) )
  {
    z = pPushedEntity->m_vecAngVelocity.z;
    *(_QWORD *)&angles.x = *(_QWORD *)&pPushedEntity->m_vecAngVelocity.x;
    y = rotPushMove->amove.y;
    angles.z = z;
    angles.y = y;
    CBaseEntity::SetLocalAngularVelocity(this: pPushedEntity, vecAngVelocity: &angles);
    if ( pPushedEntity->IsNetClient(this: pPushedEntity) )
    {
      LODWORD(pPushedEntity[3].m_vecAbsVelocity.y) = 2;
      pPushedEntity[3].m_vecAbsVelocity.z = pPushedEntity[3].m_vecAbsVelocity.z + rotPushMove->amove.x;
      pPushedEntity[3].m_vecAngVelocity.x = rotPushMove->amove.y + pPushedEntity[3].m_vecAngVelocity.x;
      pPushedEntity[3].m_vecAngVelocity.y = rotPushMove->amove.z + pPushedEntity[3].m_vecAngVelocity.y;
    }
  }
  else
  {
    if ( (pPushedEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPushedEntity, a2: (int)&savedregs);
    v5 = pPushedEntity->m_angAbsRotation.z;
    *(_QWORD *)&angles.x = *(_QWORD *)&pPushedEntity->m_angAbsRotation.x;
    v6 = rotPushMove->amove.y + angles.y;
    angles.z = v5;
    angles.y = v6;
    CBaseEntity::SetAbsAngles(this: pPushedEntity, absAngles: &angles);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191FA0
// Name: public: virtual bool CTraceFilterPushMove::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterPushMove::ShouldHitEntity(
        CTraceFilterPushMove *this,
        CBaseEntity *pHandleEntity,
        int contentsMask)
{
  IHandleEntity_vtbl *m_pPhysicsObject; // ecx

  if ( UTIL_EntityHasMatchingRootParent(pRootParent: this->m_pRootParent, pEntity: pHandleEntity) )
    return 0;
  if ( pHandleEntity->m_MoveType.m_Value == 6
    && (m_pPhysicsObject = (IHandleEntity_vtbl *)pHandleEntity->m_pPhysicsObject) != nullptr
    && (*((unsigned __int8 (__thiscall **)(IHandleEntity_vtbl *))m_pPhysicsObject->dtr_IHandleEntity + 10))(a1: m_pPhysicsObject) != 0 )
  {
    return 0;
  }
  else
  {
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192000
// Name: PhysicsCheckSweep
// Source: json
//------------------------------------------------------------------------------
void __usercall PhysicsCheckSweep(
        CBaseEntity *pEntity@<esi>,
        const Vector *vecAbsStart@<edi>,
        const Vector *vecAbsDelta,
        CGameTrace *pTrace)
{
  unsigned int v5; // eax
  bool v6; // zf
  unsigned int m_Index; // ecx
  Vector vecAbsEnd; // [esp+4h] [ebp-Ch] BYREF
  unsigned int mask; // [esp+18h] [ebp+8h]

  v5 = pEntity->PhysicsSolidMaskForEntity(this: pEntity);
  v6 = pEntity->m_Collision.m_nSolidType.m_Value == 0;
  vecAbsEnd.x = vecAbsStart->x + vecAbsDelta->x;
  vecAbsEnd.y = vecAbsStart->y + vecAbsDelta->y;
  mask = v5;
  vecAbsEnd.z = vecAbsStart->z + vecAbsDelta->z;
  if ( v6
    || (pEntity->m_Collision.m_usSolidFlags.m_Value & 4) != 0
    || (pEntity->m_Collision.m_usSolidFlags.m_Value & 0x20) != 0 )
  {
    m_Index = pEntity->m_hMoveParent.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      UTIL_ClearTrace(trace: pTrace);
      return;
    }
    mask = v5 & 0xFDFFFFFF;
  }
  if ( ((int (__thiscall *)(CBaseEntity *, _DWORD, _DWORD, _DWORD))pEntity->GetDamageType)(
         a1: pEntity,
         a2: LODWORD(vecAbsEnd.x),
         a3: LODWORD(vecAbsEnd.y),
         a4: LODWORD(vecAbsEnd.z)) != 0 )
    g_pGameRules->WeaponTraceEntity(
      this: g_pGameRules,
      a2: pEntity,
      a3: vecAbsStart,
      a4: &vecAbsEnd,
      a5: mask,
      a6: pTrace);
  else
    UTIL_TraceEntity(pEntity, vecAbsStart, &vecAbsEnd, mask, ptr: pTrace);
}

//------------------------------------------------------------------------------
// Address: 0x101920F0
// Name: protected: void CPhysicsPushedEntities::ComputeRotationalPushDirection(class CBaseEntity __near *,struct CPhysicsPushedEntities::RotatingPushMove_t const __near &,class Vector __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::ComputeRotationalPushDirection(
        CPhysicsPushedEntities *this,
        CBasePlayer *pBlocker,
        const CPhysicsPushedEntities::RotatingPushMove_t *rotPushMove,
        Vector *pMove,
        CBaseEntity *pRoot)
{
  Vector *v5; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v6; // edx
  float x; // xmm1_4
  bool v8; // cc
  float y; // xmm1_4
  float z; // xmm0_4
  bool (__thiscall *IsPlayer)(CBaseEntity *); // eax
  Vector local; // [esp+Ch] [ebp-3Ch] BYREF
  Vector end; // [esp+18h] [ebp-30h] BYREF
  Vector vecAbsMins; // [esp+24h] [ebp-24h] BYREF
  Vector vecAbsMaxs; // [esp+30h] [ebp-18h] BYREF
  Vector start; // [esp+3Ch] [ebp-Ch] BYREF

  v5 = pBlocker->m_Collision.GetCollisionOrigin(this: &pBlocker->m_Collision);
  v6 = pRoot->m_Collision.__vftable;
  start = *v5;
  if ( v6->GetSolid(this: &pRoot->m_Collision) == SOLID_VPHYSICS )
  {
    CCollisionProperty::CollisionAABBToWorldAABB(
      this: &pBlocker->m_Collision,
      entityMins: &pBlocker->m_Collision.m_vecMins.m_Value,
      entityMaxs: &pBlocker->m_Collision.m_vecMaxs.m_Value,
      pWorldMins: &vecAbsMins,
      pWorldMaxs: &vecAbsMaxs);
    if ( pMove->x >= 0.0 )
      x = vecAbsMins.x;
    else
      x = vecAbsMaxs.x;
    v8 = pMove->y >= 0.0;
    start.x = x;
    if ( v8 )
      y = vecAbsMins.y;
    else
      y = vecAbsMaxs.y;
    v8 = pMove->z >= 0.0;
    start.y = y;
    if ( v8 )
      z = vecAbsMins.z;
    else
      z = vecAbsMaxs.z;
    IsPlayer = pBlocker->IsPlayer;
    start.z = z;
    if ( IsPlayer(this: pBlocker) )
      CBasePlayer::SetPhysicsFlag(this: pBlocker, nFlag: 32, bSet: true);
  }
  VectorITransform(in1: &start.x, in2: &rotPushMove->startLocalToWorld, out: &local.x);
  VectorTransform(in1: &local.x, in2: &rotPushMove->endLocalToWorld, out: &end.x);
  pMove->x = end.x - start.x;
  pMove->y = end.y - start.y;
  pMove->z = end.z - start.z;
}

//------------------------------------------------------------------------------
// Address: 0x10192220
// Name: public: virtual bool CTraceFilterPushFinal::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterPushFinal::ShouldHitEntity(
        CTraceFilterPushFinal *this,
        IHandleEntity *pHandleEntity,
        int contentsMask)
{
  IHandleEntity_vtbl *v4; // ecx

  if ( BYTE2(pHandleEntity[53].__vftable) == 6
    && (v4 = pHandleEntity[82].__vftable) != nullptr
    && (*((unsigned __int8 (__thiscall **)(IHandleEntity_vtbl *))v4->dtr_IHandleEntity + 10))(a1: v4) != 0 )
  {
    return 0;
  }
  else
  {
    return CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192270
// Name: protected: bool CPhysicsPushedEntities::IsPushedPositionValid(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsPushedEntities::IsPushedPositionValid(CPhysicsPushedEntities *this, CBaseEntity *pBlocker)
{
  unsigned int v2; // ecx
  unsigned int v3; // eax
  CGameTrace trace; // [esp+8h] [ebp-64h] BYREF
  CTraceFilterPushFinal pushFilter; // [esp+5Ch] [ebp-10h] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF

  CTraceFilterSimple::CTraceFilterSimple(
    this: &pushFilter,
    passedict: pBlocker,
    collisionGroup: pBlocker->m_CollisionGroup.m_Value,
    pExtraShouldHitFunc: nullptr);
  v2 = (unsigned int)pBlocker->m_iEFlags >> 11;
  pushFilter.__vftable = (CTraceFilterPushFinal_vtbl *)&CTraceFilterPushFinal::`vftable';
  if ( (v2 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pBlocker, a2: (int)&savedregs);
  if ( (pBlocker->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pBlocker, a2: (int)&savedregs);
  v3 = pBlocker->PhysicsSolidMaskForEntity(this: pBlocker);
  UTIL_TraceEntity(
    pEntity: pBlocker,
    vecAbsStart: &pBlocker->m_vecAbsOrigin,
    vecAbsEnd: &pBlocker->m_vecAbsOrigin,
    mask: v3,
    pFilter: &pushFilter,
    ptr: &trace);
  return !trace.startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x10192300
// Name: protected: bool CPhysicsPushedEntities::SpeculativelyCheckPush(struct CPhysicsPushedEntities::PhysicsPushedInfo_t __near &,class Vector const __near &,bool,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsPushedEntities::SpeculativelyCheckPush(
        CPhysicsPushedEntities *this,
        CPhysicsPushedEntities::PhysicsPushedInfo_t *info,
        const Vector *vecAbsPush,
        bool bRotationalPush,
        CBaseEntity *pRoot)
{
  CBaseEntity *m_pEntity; // esi
  int m_Size; // edi
  void *v8; // esp
  int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edi
  CPhysicsPushedEntities::PhysicsPushedInfo_t *v13; // edi
  CPhysicsPushedEntities::PhysicsPusherInfo_t *m_pMemory; // edi
  CBaseEntity *GroundEntity; // eax
  bool v16; // zf
  bool v17; // al
  float z; // edx
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v19; // eax
  CBaseEntity *v20; // edi
  float v21; // xmm3_4
  bool result; // al
  const char *pszValue; // eax
  const char *v24; // esi
  bool v25; // al
  float v26; // edx
  CWorld *v27; // eax
  const Vector *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm1_4
  bool v31; // al
  IGameMovement_vtbl *v32; // edi
  CBasePlayer *v33; // eax
  bool v34; // al
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v35; // edx
  CBaseEntity *v36; // edi
  float v37; // xmm3_4
  bool v38; // al
  CBaseEntity *v39; // [esp-4h] [ebp-68h]
  int v40; // [esp+0h] [ebp-64h] BYREF
  CTraceFilterSimple v41; // [esp+Ch] [ebp-58h] BYREF
  CBaseEntity *RootMoveParent; // [esp+1Ch] [ebp-48h]
  Vector absOrigin; // [esp+20h] [ebp-44h] BYREF
  Vector m_vecAbsOrigin; // [esp+2Ch] [ebp-38h] BYREF
  Vector vecAbsEnd; // [esp+38h] [ebp-2Ch] BYREF
  Vector vec; // [esp+44h] [ebp-20h] BYREF
  Vector out; // [esp+50h] [ebp-14h] BYREF
  int *v48; // [esp+5Ch] [ebp-8h]
  unsigned int v49; // [esp+60h] [ebp-4h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  int v51; // [esp+70h] [ebp+Ch]
  char v52; // [esp+73h] [ebp+Fh]
  int v53; // [esp+74h] [ebp+10h]
  int v54; // [esp+74h] [ebp+10h]

  m_pEntity = info->m_pEntity;
  m_Size = this->m_rgPusher.m_Size;
  v8 = alloca(4 * m_Size);
  v9 = m_Size - 1;
  v48 = &v40;
  if ( v9 >= 0 )
  {
    v49 = 16 * v9;
    do
    {
      v10 = partition->HideElement(
              this: partition,
              a2: this->m_rgPusher.m_Memory.m_pMemory[v49 / 0x10].m_pEntity->m_Collision.m_Partition);
      v49 -= 16;
      v48[v9--] = v10;
    }
    while ( v9 >= 0 );
  }
  CTraceFilterSimple::CTraceFilterSimple(
    this: &v41,
    passedict: m_pEntity,
    collisionGroup: m_pEntity->m_CollisionGroup.m_Value,
    pExtraShouldHitFunc: nullptr);
  v41.__vftable = (CTraceFilterSimple_vtbl *)&CTraceFilterPushMove::`vftable';
  RootMoveParent = CBaseEntity::GetRootMoveParent(this: m_pEntity);
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  vecAbsEnd.x = m_pEntity->m_vecAbsOrigin.x + vecAbsPush->x;
  vecAbsEnd.y = vecAbsPush->y + m_pEntity->m_vecAbsOrigin.y;
  vecAbsEnd.z = vecAbsPush->z + m_pEntity->m_vecAbsOrigin.z;
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  v11 = m_pEntity->PhysicsSolidMaskForEntity(this: m_pEntity);
  UTIL_TraceEntity(
    pEntity: m_pEntity,
    vecAbsStart: &m_pEntity->m_vecAbsOrigin,
    &vecAbsEnd,
    mask: v11,
    pFilter: &v41,
    ptr: &info->m_Trace);
  v12 = this->m_rgPusher.m_Size - 1;
  if ( v12 >= 0 )
  {
    v51 = v12;
    do
      partition->UnhideElement(
        this: partition,
        a2: this->m_rgPusher.m_Memory.m_pMemory[v51--].m_pEntity->m_Collision.m_Partition,
        a3: v48[v12--]);
    while ( v12 >= 0 );
  }
  v13 = info;
  info->m_bPusherIsGround = false;
  if ( CBaseEntity::GetGroundEntity(this: m_pEntity) != nullptr )
  {
    m_pMemory = this->m_rgPusher.m_Memory.m_pMemory;
    GroundEntity = CBaseEntity::GetGroundEntity(this: m_pEntity);
    if ( CBaseEntity::GetRootMoveParent(this: GroundEntity) == m_pMemory->m_pEntity )
      info->m_bPusherIsGround = true;
    v13 = info;
  }
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  v16 = !this->m_bIsUnblockableByPlayer;
  m_vecAbsOrigin = m_pEntity->m_vecAbsOrigin;
  if ( !v16 && (m_pEntity->IsPlayer(this: m_pEntity) || m_pEntity->MyNPCPointer(this: m_pEntity) != nullptr) )
  {
    v52 = 1;
    CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &vecAbsEnd);
  }
  else
  {
    v52 = 0;
    if ( pRoot != nullptr )
    {
      result = pRoot->CanPushEntity(this: pRoot, a2: m_pEntity);
      if ( !result )
      {
        v13->m_bBlocked = true;
        return result;
      }
    }
    if ( v13->m_Trace.fraction != 0.0 )
      CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &v13->m_Trace.endpos);
    if ( m_pEntity->m_Collision.m_flRadius == 0.0
      || m_pEntity->m_Collision.m_nSolidType.m_Value == 0
      || (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 4) != 0
      || (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 0x20) != 0 )
    {
      return true;
    }
    if ( !bRotationalPush && v13->m_Trace.fraction == 1.0 )
    {
      if ( !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity) )
      {
        pszValue = this->m_rgPusher.m_Memory.m_pMemory->m_pEntity->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        v24 = m_pEntity->m_iClassname.pszValue;
        if ( v24 == nullptr )
          v24 = locale;
        _Warning(a1: "Interpenetrating entities! (%s and %s)\n", v24, pszValue);
        return true;
      }
      return true;
    }
  }
  v17 = !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity);
  v13->m_bBlocked = v17;
  if ( !v17 )
    return true;
  if ( v52 != 0 )
  {
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
    z = m_pEntity->m_vecAbsOrigin.z;
    *(_QWORD *)&vec.x = *(_QWORD *)&m_pEntity->m_vecAbsOrigin.x;
    vec.z = z;
    v53 = 0;
    while ( 1 )
    {
      v19 = this->m_rgPusher.m_Memory.m_pMemory;
      v20 = v19->m_pEntity;
      if ( (v19->m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v19->m_pEntity, a2: (int)&savedregs);
      MatrixGetColumn(in: &v20->m_rgflCoordinateFrame, column: v53 >> 1, &out);
      v21 = (v53 & 1) != 0 ? -0.5 : 0.5;
      absOrigin.y = vec.y + (float)(out.y * v21);
      absOrigin.x = vec.x + (float)(out.x * v21);
      absOrigin.z = vec.z + (float)(out.z * v21);
      CBaseEntity::SetAbsOrigin(this: m_pEntity, &absOrigin);
      v25 = !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity);
      info->m_bBlocked = v25;
      if ( !v25 )
        break;
      if ( ++v53 >= 4 )
      {
        CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &vecAbsEnd);
        _DevMsg(a1: 1, a2: "Ignoring player blocking train!\n");
        return true;
      }
    }
LABEL_53:
    _DevMsg(a1: 1, a2: "Fixing player blocking train!\n");
    return true;
  }
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  v26 = m_pEntity->m_vecAbsOrigin.z;
  *(_QWORD *)&out.x = *(_QWORD *)&m_pEntity->m_vecAbsOrigin.x;
  out.z = v26;
  v27 = (CWorld *)CBaseEntity::GetGroundEntity(this: m_pEntity);
  if ( v27 != nullptr && v27 != g_WorldEntity )
  {
    v28 = CBaseEntity::GetAbsOrigin(this: v27);
    v29 = v28->x - out.x;
    vec.x = v29;
    v30 = v28->y - out.y;
    vec.z = 0.0;
    vec.y = v30;
    if ( v29 <= -0.0099999998 || v29 >= 0.0099999998 || v30 <= -0.0099999998 || v30 >= 0.0099999998 )
    {
      VectorNormalize(&vec);
      absOrigin.x = (float)(vec.x * 16.0) + out.x;
      absOrigin.y = (float)(vec.y * 16.0) + out.y;
      absOrigin.z = (float)(vec.z * 16.0) + out.z;
      CBaseEntity::SetAbsOrigin(this: m_pEntity, &absOrigin);
      v31 = !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity);
      v13->m_bBlocked = v31;
      if ( !v31 )
      {
        _DevMsg(a1: 1, a2: "Fixing player blocking train by moving to center!\n");
        return true;
      }
    }
  }
  if ( !m_pEntity->IsPlayer(this: m_pEntity) )
  {
    v54 = 0;
    while ( 1 )
    {
      v35 = this->m_rgPusher.m_Memory.m_pMemory;
      v36 = v35->m_pEntity;
      if ( (v35->m_pEntity->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v35->m_pEntity, a2: (int)&savedregs);
      MatrixGetColumn(in: &v36->m_rgflCoordinateFrame, column: v54 >> 1, out: &absOrigin);
      v37 = (v54 & 1) != 0 ? -0.5 : 0.5;
      vec.x = (float)(absOrigin.x * v37) + out.x;
      vec.y = (float)(absOrigin.y * v37) + out.y;
      vec.z = (float)(absOrigin.z * v37) + out.z;
      CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &vec);
      v38 = !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity);
      info->m_bBlocked = v38;
      if ( !v38 )
        goto LABEL_53;
      if ( ++v54 >= 4 )
      {
        CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &out);
        goto LABEL_84;
      }
    }
  }
  CBaseEntity::SetAbsOrigin(this: m_pEntity, absOrigin: &m_vecAbsOrigin);
  v32 = g_pGameMovement->__vftable;
  v39 = this->m_rgPusher.m_Memory.m_pMemory->m_pEntity;
  v33 = ToBasePlayer(pEntity: m_pEntity);
  v32->UnblockPusher(this: g_pGameMovement, a2: v33, a3: v39);
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
  v34 = m_vecAbsOrigin.x == m_pEntity->m_vecAbsOrigin.x
     && m_vecAbsOrigin.y == m_pEntity->m_vecAbsOrigin.y
     && m_vecAbsOrigin.z == m_pEntity->m_vecAbsOrigin.z
     || !CPhysicsPushedEntities::IsPushedPositionValid(this, pBlocker: m_pEntity);
  info->m_bBlocked = v34;
  if ( !v34 )
  {
    _DevMsg(a1: 1, a2: "Fixing player blocking train via gamemovement!\n");
    return true;
  }
LABEL_84:
  _DevMsg(a1: 2, a2: "Blocked by player on train!\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101929F0
// Name: protected: virtual bool CPhysicsPushedEntities::SpeculativelyCheckRotPush(struct CPhysicsPushedEntities::RotatingPushMove_t const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsPushedEntities::SpeculativelyCheckRotPush(
        CPhysicsPushedEntities *this,
        const CPhysicsPushedEntities::RotatingPushMove_t *rotPushMove,
        CBaseEntity *pRoot)
{
  int v4; // ebx
  int i; // edi
  Vector vecAbsPush; // [esp+Ch] [ebp-Ch] BYREF

  v4 = this->m_rgMoved.m_Size - 1;
  this->m_nBlocker = -1;
  if ( v4 < 0 )
    return 1;
  for ( i = v4; ; --i )
  {
    CPhysicsPushedEntities::ComputeRotationalPushDirection(
      this,
      pBlocker: (CBasePlayer *)this->m_rgMoved.m_Memory.m_pMemory[i].m_pEntity,
      rotPushMove,
      pMove: &vecAbsPush,
      pRoot);
    if ( !CPhysicsPushedEntities::SpeculativelyCheckPush(
            this,
            info: &this->m_rgMoved.m_Memory.m_pMemory[i],
            &vecAbsPush,
            bRotationalPush: true,
            pRoot) )
      break;
    if ( --v4 < 0 )
      return 1;
  }
  this->m_nBlocker = v4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10192A70
// Name: protected: virtual bool CPhysicsPushedEntities::SpeculativelyCheckLinearPush(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsPushedEntities::SpeculativelyCheckLinearPush(
        CPhysicsPushedEntities *this,
        const Vector *vecAbsPush)
{
  int v3; // esi
  int i; // edi

  v3 = this->m_rgMoved.m_Size - 1;
  this->m_nBlocker = -1;
  if ( v3 < 0 )
    return 1;
  for ( i = v3;
        CPhysicsPushedEntities::SpeculativelyCheckPush(
          this,
          info: &this->m_rgMoved.m_Memory.m_pMemory[i],
          vecAbsPush,
          bRotationalPush: false,
          pRoot: nullptr);
        --i )
  {
    if ( --v3 < 0 )
      return 1;
  }
  this->m_nBlocker = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10192AD0
// Name: public: void CPhysicsPushedEntities::StoreMovedEntities(struct physicspushlist_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::StoreMovedEntities(CPhysicsPushedEntities *this, physicspushlist_t *list)
{
  CPhysicsPushedEntities *v2; // esi
  unsigned int m_Size; // eax
  int v4; // edi
  float *p_z; // ebx
  int v6; // ecx
  float *v7; // edi
  CBaseEntity *v8; // esi
  float v9; // xmm1_4
  float v10; // xmm2_4
  int i; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  CHandle<CBaseEntity> *pushedEnts; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v2 = this;
  list->localMoveTime = this->m_rootPusherStartLocaltime;
  list->localOrigin = this->m_rootPusherStartLocalOrigin;
  list->localAngles = this->m_rootPusherStartLocalAngles;
  m_Size = this->m_rgMoved.m_Size;
  list->pushedCount = m_Size;
  if ( m_Size > 0x20 )
    list->pushedCount = 32;
  v4 = 0;
  i = 0;
  if ( list->pushedCount > 0 )
  {
    v13 = 0;
    pushedEnts = list->pushedEnts;
    p_z = &list->pushVec[0].z;
    while ( 1 )
    {
      v6 = *(int *)((char *)&v2->m_rgMoved.m_Memory.m_pMemory->m_pEntity + v4);
      if ( v6 != 0 )
        pushedEnts->m_Index = *(unsigned int *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
      else
        pushedEnts->m_Index = -1;
      v7 = (float *)((char *)v2->m_rgMoved.m_Memory.m_pMemory + v4);
      v8 = *(CBaseEntity **)v7;
      if ( (*(_DWORD *)(*(_DWORD *)v7 + 196) & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: *(CBaseEntity **)v7, a2: (int)&savedregs);
      v9 = v8->m_vecAbsOrigin.y - v7[2];
      v10 = v8->m_vecAbsOrigin.z - v7[3];
      ++pushedEnts;
      v13 += 104;
      *(p_z - 2) = v8->m_vecAbsOrigin.x - v7[1];
      *(p_z - 1) = v9;
      *p_z = v10;
      p_z += 3;
      if ( ++i >= list->pushedCount )
        break;
      v4 = v13;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192BE0
// Name: protected: void CPhysicsPushedEntities::RotateRootEntity(class CBaseEntity __near *,float,struct CPhysicsPushedEntities::RotatingPushMove_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::RotateRootEntity(
        CPhysicsPushedEntities *this,
        CBaseEntity *pRoot,
        float movetime,
        CPhysicsPushedEntities::RotatingPushMove_t *rotation)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float z; // eax
  float v7; // xmm3_4
  float v8; // xmm0_4
  QAngle angles; // [esp+0h] [ebp-Ch] BYREF
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  v4 = movetime * pRoot->m_vecAngVelocity.y;
  v5 = movetime * pRoot->m_vecAngVelocity.z;
  rotation->amove.x = movetime * pRoot->m_vecAngVelocity.x;
  rotation->amove.y = v4;
  rotation->amove.z = v5;
  if ( (pRoot->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pRoot, a2: (int)&savedregs);
  rotation->origin = pRoot->m_vecAbsOrigin;
  if ( (pRoot->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pRoot, a2: (int)&savedregs);
  MatrixCopy(in: &pRoot->m_rgflCoordinateFrame, out: &rotation->startLocalToWorld);
  z = pRoot->m_angRotation.m_Value.z;
  *(_QWORD *)&angles.x = *(_QWORD *)&pRoot->m_angRotation.m_Value.x;
  v7 = angles.x + (float)(movetime * pRoot->m_vecAngVelocity.x);
  v8 = movetime * pRoot->m_vecAngVelocity.z;
  angles.y = angles.y + (float)(movetime * pRoot->m_vecAngVelocity.y);
  angles.x = v7;
  angles.z = z + v8;
  CBaseEntity::SetLocalAngles(this: pRoot, &angles);
  if ( (pRoot->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pRoot, a2: (int)&savedregs);
  MatrixCopy(in: &pRoot->m_rgflCoordinateFrame, out: &rotation->endLocalToWorld);
}

//------------------------------------------------------------------------------
// Address: 0x10192D10
// Name: protected: void CPhysicsPushedEntities::LinearlyMoveRootEntity(class CBaseEntity __near *,float,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::LinearlyMoveRootEntity(
        CPhysicsPushedEntities *this,
        CBaseEntity *pRoot,
        float movetime,
        Vector *pAbsPushVector)
{
  float z; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  __int64 v7; // xmm3_8
  float v8; // xmm1_4
  float v9; // xmm2_4
  Vector origin; // [esp+0h] [ebp-Ch] BYREF
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  z = pRoot->m_vecOrigin.m_Value.z;
  v5 = pRoot->m_vecVelocity.m_Value.y * movetime;
  v6 = pRoot->m_vecVelocity.m_Value.z * movetime;
  v7 = *(_QWORD *)&pRoot->m_vecOrigin.m_Value.x;
  origin.x = (float)(movetime * pRoot->m_vecVelocity.m_Value.x) + *(float *)&v7;
  origin.y = *((float *)&v7 + 1) + v5;
  origin.z = z + v6;
  CBaseEntity::SetLocalOrigin(this: pRoot, &origin);
  if ( (pRoot->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: pRoot, a2: (int)&savedregs);
  v8 = pRoot->m_vecAbsVelocity.y * movetime;
  v9 = pRoot->m_vecAbsVelocity.z * movetime;
  pAbsPushVector->x = pRoot->m_vecAbsVelocity.x * movetime;
  pAbsPushVector->y = v8;
  pAbsPushVector->z = v9;
}

//------------------------------------------------------------------------------
// Address: 0x10192DE0
// Name: private: void CBaseEntity::PhysicsDispatchThink(void (CBaseEntity::*)(void))
// Source: json
//------------------------------------------------------------------------------
// write access to const memory has been detected, the output may be wrong!
void __thiscall CBaseEntity::PhysicsDispatchThink(CBaseEntity *this, void (__thiscall *thinkFunc)(CBaseEntity *this))
{
  const char *v3; // eax
  IEntityFactoryDictionary *v4; // eax
  const char *pszValue; // edx
  int v6; // esi
  ISteamUtils *m_pSteamUtils; // ecx
  int v8; // eax
  bool v9; // bl
  double v10; // st7
  CAI_BaseNPC *v11; // eax
  const char *v12; // esi
  const char *v13; // eax
  double startTime; // [esp+38h] [ebp-Ch]
  float thinkLimit; // [esp+40h] [ebp-4h]
  float time; // [esp+4Ch] [ebp+8h]

  if ( vprof_scope_entity_thinks.m_pParent != nullptr && vprof_scope_entity_thinks.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = EntityFactoryDictionary();
    pszValue = this->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v3 = v4->GetCannonicalName(this: v4, a2: pszValue);
  }
  else
  {
    v3 = "CBaseEntity::PhysicsDispatchThink";
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: v3,
    a3: 1,
    a4: "Unaccounted",
    a5: false,
    a6: 0);
  thinkLimit = think_limit.m_pParent->m_Value.m_fValue;
  startTime = 0.0;
  if ( thinkLimit != 0.0 )
    startTime = _Plat_FloatTime();
  if ( thinkFunc != nullptr )
  {
    if ( (_S3_89 & 1) == 0 )
    {
      _S3_89 |= 1u;
      ConVarRef::ConVarRef(this: &think_trace_limit, pName: "think_trace_limit");
    }
    v6 = abs32(think_trace_limit.m_pConVarState->m_Value.m_nValue);
    if ( (_S2_165 & 1) == 0 )
    {
      m_pSteamUtils = steamapicontext->m_pSteamUtils;
      _S2_165 |= 1u;
      if ( m_pSteamUtils == nullptr
        || (v8 = m_pSteamUtils->GetConnectedUniverse(this: m_pSteamUtils), byte_1062D488 = 1, v8 != 1) )
      {
        byte_1062D488 = 0;
      }
    }
    v9 = byte_1062D488 == 0;
    if ( byte_1062D488 == 0 )
      enginetrace->GetSetDebugTraceCounter(this: enginetrace, a2: v6, a3: kTRACE_COUNTER_SET);
    thinkFunc(this);
    if ( v9 )
      enginetrace->GetSetDebugTraceCounter(this: enginetrace, a2: 0, a3: kTRACE_COUNTER_SET);
  }
  if ( thinkLimit != 0.0 )
  {
    v10 = (_Plat_FloatTime() - startTime) * 1000.0;
    time = v10;
    if ( v10 > thinkLimit )
    {
      if ( vprof_think_limit.m_pParent != nullptr && vprof_think_limit.m_pParent->m_Value.m_nValue != 0 )
        _g_VProfSignalSpike = true;
      v11 = this->MyNPCPointer(this);
      if ( v11 != nullptr && v11->m_pSchedule != nullptr )
      {
        v11->ReportOverThinkLimit(this: v11, a2: COERCE_FLOAT(LODWORD(time)));
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return;
      }
      v12 = this->m_iClassname.pszValue;
      if ( v12 == nullptr )
        v12 = locale;
      v13 = type_info::raw_name(this: &CBaseEntity * `RTTI Type Descriptor');
      _Msg(a1: "%s(%s) thinking for %.02f ms!!!\n", v12, v13, time);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10192FF0
// Name: public: void CBaseEntity::PhysicsPushEntity(class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsPushEntity(CBaseEntity *this, const Vector *push, CGameTrace *pTrace)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  CBaseEntity **v10; // eax
  CBaseEntity *v11; // eax
  const char *v12; // eax
  CBaseEntity *m_pEnt; // eax
  const char *DebugName; // [esp-4h] [ebp-1Ch]
  Vector prevOrigin; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      DebugName = CBaseEntity::GetDebugName(this: v11);
      v12 = CBaseEntity::GetDebugName(this);
      _Warning(a1: "pushing entity (%s) that has parent (%s)!\n", v12, DebugName);
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  prevOrigin = this->m_vecAbsOrigin;
  PhysicsCheckSweep(pEntity: this, vecAbsStart: &prevOrigin, vecAbsDelta: push, pTrace);
  if ( pTrace->fraction != 0.0 )
    CBaseEntity::SetAbsOrigin(this, absOrigin: &pTrace->endpos);
  CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: &prevOrigin);
  m_pEnt = pTrace->m_pEnt;
  if ( m_pEnt != nullptr )
    CBaseEntity::PhysicsImpact(this, other: m_pEnt, trace: pTrace);
}

//------------------------------------------------------------------------------
// Address: 0x101930F0
// Name: private: void CBaseEntity::PhysicsNoclip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsNoclip(CBaseEntity *this)
{
  float frametime; // xmm0_4
  Vector origin; // [esp+8h] [ebp-Ch] BYREF

  if ( CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
  {
    CBaseEntity::SimulateAngles(this, flFrameTime: gpGlobals->frametime);
    frametime = gpGlobals->frametime;
    origin.x = (float)(this->m_vecVelocity.m_Value.x * frametime) + this->m_vecOrigin.m_Value.x;
    origin.y = (float)(this->m_vecVelocity.m_Value.y * frametime) + this->m_vecOrigin.m_Value.y;
    origin.z = (float)(this->m_vecVelocity.m_Value.z * frametime) + this->m_vecOrigin.m_Value.z;
    CBaseEntity::SetLocalOrigin(this, &origin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193190
// Name: private: void CBaseEntity::PhysicsCustom(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsCustom(CBaseEntity *this)
{
  CBaseEntity *GroundEntity; // eax
  float z; // ecx
  unsigned int v4; // edx
  float v5; // eax
  unsigned int v6; // ecx
  float v7; // edx
  __int64 v8; // xmm0_8
  void (__thiscall *PerformCustomPhysics)(CBaseEntity *, Vector *, Vector *, QAngle *, QAngle *); // edx
  float v10; // xmm1_4
  float v11; // xmm2_4
  CGameTrace trace; // [esp+4h] [ebp-90h] BYREF
  Vector vecNewVelocity; // [esp+58h] [ebp-3Ch] BYREF
  Vector move; // [esp+64h] [ebp-30h] BYREF
  QAngle angNewAngVelocity; // [esp+70h] [ebp-24h] BYREF
  QAngle angNewAngles; // [esp+7Ch] [ebp-18h] BYREF
  Vector vecNewPosition; // [esp+88h] [ebp-Ch] BYREF
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  CBaseEntity::PhysicsCheckWater(this);
  if ( CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
  {
    if ( this->m_vecVelocity.m_Value.z > 0.0
      || CBaseEntity::GetGroundEntity(this) == nullptr
      || (GroundEntity = CBaseEntity::GetGroundEntity(this), !CBaseEntity::IsStandable(this: GroundEntity)) )
    {
      CBaseEntity::SetGroundEntity(this, ground: nullptr);
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    v4 = (unsigned int)this->m_iEFlags >> 12;
    *(_QWORD *)&vecNewPosition.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vecNewPosition.z = z;
    if ( (v4 & 1) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    v5 = this->m_vecAbsVelocity.z;
    v6 = (unsigned int)this->m_iEFlags >> 11;
    *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
    vecNewVelocity.z = v5;
    if ( (v6 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v7 = this->m_angAbsRotation.z;
    v8 = *(_QWORD *)&this->m_angAbsRotation.x;
    angNewAngVelocity.z = this->m_vecAngVelocity.z;
    angNewAngles.z = v7;
    PerformCustomPhysics = this->PerformCustomPhysics;
    *(_QWORD *)&angNewAngles.x = v8;
    *(_QWORD *)&angNewAngVelocity.x = *(_QWORD *)&this->m_vecAngVelocity.x;
    PerformCustomPhysics(this, a2: &vecNewPosition, a3: &vecNewVelocity, a4: &angNewAngles, a5: &angNewAngVelocity);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecNewVelocity);
    CBaseEntity::SetAbsAngles(this, absAngles: &angNewAngles);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &angNewAngVelocity);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v10 = vecNewPosition.y - this->m_vecAbsOrigin.y;
    v11 = vecNewPosition.z - this->m_vecAbsOrigin.z;
    move.x = vecNewPosition.x - this->m_vecAbsOrigin.x;
    move.y = v10;
    move.z = v11;
    if ( (float)((float)((float)(move.x * move.x) + (float)(v10 * v10)) + (float)(v11 * v11)) > 0.000001
      && (CBaseEntity::PhysicsPushEntity(this, push: &move, pTrace: &trace),
          CBaseEntity::PhysicsCheckVelocity(this),
          trace.allsolid) )
    {
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    }
    else if ( (this->m_Network.m_pPev->m_fStateFlags & 2) == 0 )
    {
      CBaseEntity::PhysicsCheckWaterTransition(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193380
// Name: public: void CBaseEntity::PhysicsStepRecheckGround(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CBaseEntity::PhysicsStepRecheckGround(
        CBaseEntity *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  float x; // eax
  unsigned int v6; // ecx
  CBaseEntity::NetworkVar_m_Collision_vtbl *v7; // edx
  float v8; // xmm0_4
  const Vector *(__thiscall *OBBMaxs)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  float *v10; // edi
  int i; // edi
  float v12; // xmm0_4
  float y; // xmm0_4
  ICollideable *(__thiscall *GetCollideable)(struct CBaseEntity *); // eax
  Vector v16; // [esp+1Ch] [ebp-F4h] BYREF
  CGameTrace trace; // [esp+28h] [ebp-E8h] BYREF
  int v18; // [esp+7Ch] [ebp-94h]
  int v19; // [esp+80h] [ebp-90h]
  float v20; // [esp+84h] [ebp-8Ch] BYREF
  float z; // [esp+88h] [ebp-88h]
  int v22; // [esp+8Ch] [ebp-84h]
  int v23; // [esp+90h] [ebp-80h]
  int v24; // [esp+94h] [ebp-7Ch]
  int v25; // [esp+98h] [ebp-78h]
  int v26; // [esp+9Ch] [ebp-74h]
  int v27; // [esp+A0h] [ebp-70h]
  int v28; // [esp+A4h] [ebp-6Ch]
  int v29; // [esp+A8h] [ebp-68h]
  int v30; // [esp+ACh] [ebp-64h]
  int v31; // [esp+B0h] [ebp-60h]
  int v32; // [esp+B4h] [ebp-5Ch]
  int v33; // [esp+B8h] [ebp-58h]
  int v34; // [esp+BCh] [ebp-54h]
  int v35; // [esp+C0h] [ebp-50h]
  int v36; // [esp+C4h] [ebp-4Ch]
  int v37; // [esp+C8h] [ebp-48h]
  int v38; // [esp+CCh] [ebp-44h]
  int v39; // [esp+D0h] [ebp-40h]
  int v40; // [esp+D4h] [ebp-3Ch]
  float v41; // [esp+D8h] [ebp-38h]
  float v42; // [esp+DCh] [ebp-34h]
  int v43; // [esp+E0h] [ebp-30h]
  Vector maxs; // [esp+E4h] [ebp-2Ch]
  Vector mins; // [esp+F0h] [ebp-20h] BYREF
  unsigned int mask; // [esp+FCh] [ebp-14h]
  Vector point; // [esp+100h] [ebp-10h] BYREF
  float retaddr; // [esp+110h] [ebp+0h]

  point.y = a2;
  point.z = retaddr;
  LODWORD(mins.x) = ((int (__thiscall *)(CBaseEntity *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, int, int, _DWORD, _DWORD, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int))this->PhysicsSolidMaskForEntity)(
                      a1: this,
                      a2: a3,
                      a3: a4,
                      a4: LODWORD(v16.x),
                      a5: LODWORD(v16.y),
                      a6: LODWORD(v16.z),
                      a7: LODWORD(trace.startpos.x),
                      a8: LODWORD(trace.startpos.y),
                      a9: LODWORD(trace.startpos.z),
                      a10: LODWORD(trace.endpos.x),
                      a11: LODWORD(trace.endpos.y),
                      a12: LODWORD(trace.endpos.z),
                      a13: LODWORD(trace.plane.normal.x),
                      a14: LODWORD(trace.plane.normal.y),
                      a15: LODWORD(trace.plane.normal.z),
                      a16: LODWORD(trace.plane.dist),
                      a17: *(_DWORD *)&trace.plane.type,
                      a18: LODWORD(trace.fraction),
                      a19: trace.contents,
                      a20: *(_DWORD *)&trace.dispFlags,
                      a21: LODWORD(trace.fractionleftsolid),
                      a22: trace.surface.name,
                      a23: *(_DWORD *)&trace.surface.surfaceProps,
                      a24: trace.hitgroup,
                      a25: *(_DWORD *)&trace.physicsbone,
                      a26: trace.m_pEnt,
                      a27: trace.hitbox,
                      a28: v18,
                      a29: v19,
                      a30: LODWORD(v20),
                      a31: LODWORD(z),
                      a32: v22,
                      a33: v23,
                      a34: v24,
                      a35: v25,
                      a36: v26,
                      a37: v27,
                      a38: v28,
                      a39: v29,
                      a40: v30,
                      a41: v31,
                      a42: v32,
                      a43: v33,
                      a44: v34,
                      a45: v35,
                      a46: v36,
                      a47: v37,
                      a48: v38,
                      a49: v39,
                      a50: v40,
                      a51: LODWORD(v41),
                      a52: LODWORD(v42),
                      a53: v43,
                      a54: LODWORD(maxs.x),
                      a55: LODWORD(maxs.y),
                      a56: LODWORD(maxs.z),
                      a57: LODWORD(mins.x),
                      a58: LODWORD(mins.y),
                      a59: LODWORD(mins.z),
                      a60: mask);
  x = COERCE_FLOAT((int)this->m_Collision.OBBMins(this: &this->m_Collision));
  v6 = (unsigned int)this->m_iEFlags >> 11;
  point.x = x;
  if ( (v6 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&point.y);
    x = point.x;
  }
  v7 = this->m_Collision.__vftable;
  maxs.x = *(float *)LODWORD(x) + this->m_vecAbsOrigin.x;
  maxs.y = *(float *)(LODWORD(x) + 4) + this->m_vecAbsOrigin.y;
  v8 = this->m_vecAbsOrigin.z + *(float *)(LODWORD(x) + 8);
  OBBMaxs = v7->OBBMaxs;
  maxs.z = v8;
  v10 = (float *)OBBMaxs(this: &this->m_Collision);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&point.y);
  v41 = *v10 + this->m_vecAbsOrigin.x;
  v42 = v10[1] + this->m_vecAbsOrigin.y;
  *(float *)&mask = maxs.z - 1.0;
  point.x = 0.0;
  while ( 2 )
  {
    for ( i = 0; i <= 1; ++i )
    {
      if ( LODWORD(point.x) != 0 )
        v12 = v41;
      else
        v12 = maxs.x;
      mins.y = v12;
      if ( i != 0 )
        y = v42;
      else
        y = maxs.y;
      GetCollideable = this->GetCollideable;
      mins.z = y;
      if ( (int)GetCollideable(this) != 0 && this->IsNPC(this) )
      {
        UTIL_TraceLineFilterEntity(
          pEntity: this,
          vecAbsStart: (Vector *)&mins.y,
          vecAbsEnd: (Vector *)&mins.y,
          mask: LODWORD(mins.x),
          nCollisionGroup: 0,
          ptr: (CGameTrace *)&v16);
      }
      else
      {
        v24 = 0;
        v25 = 0;
        v26 = 0;
        v34 = 0;
        v33 = 0;
        v32 = 0;
        v30 = 0;
        v29 = 0;
        v28 = 0;
        v20 = mins.y;
        z = mins.z;
        v36 = 0;
        LOWORD(v37) = 1;
        v22 = 0;
        CTraceFilterSimple::CTraceFilterSimple(
          this: (CTraceFilterSimple *)&trace.m_pEnt,
          passedict: this,
          collisionGroup: 0,
          pExtraShouldHitFunc: nullptr);
        enginetrace->TraceRay(
          this: enginetrace,
          a2: (const Ray_t *)&v20,
          a3: LODWORD(mins.x),
          a4: (ITraceFilter *)&trace.m_pEnt,
          a5: (CGameTrace *)&v16);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(vecAbsStart: &v16, vecAbsEnd: &trace.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      }
      if ( trace.plane.pad[1] != 0 )
      {
        CBaseEntity::SetGroundEntity(this, ground: *(CBaseEntity **)&trace.surface.surfaceProps);
        return;
      }
    }
    ++LODWORD(point.x);
    if ( SLODWORD(point.x) <= 1 )
      continue;
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101935F0
// Name: void Physics_SimulateEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Physics_SimulateEntity(CBaseEntity *pEntity)
{
  unsigned int m_Index; // ecx
  CBasePlayer *m_pEntity; // eax

  if ( pEntity->m_Network.m_pPev != nullptr )
  {
    if ( !pEntity->m_bIsPlayerSimulated.m_Value )
    {
LABEL_8:
      pEntity->PhysicsSimulate(this: pEntity);
      return;
    }
    m_Index = pEntity->m_hPlayerSimulationOwner.m_Value.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || (m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) == nullptr
      || CBasePlayer::GetTimeBase(this: m_pEntity) <= gpGlobals->curtime - 1.0 )
    {
      CBaseEntity::UnsetPlayerSimulated(this: pEntity);
      goto LABEL_8;
    }
  }
  else
  {
    CBaseEntity::PhysicsRunThink(this: pEntity, thinkMethod: THINK_FIRE_ALL_FUNCTIONS);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10193680
// Name: public: void CPhysicsPushedEntities::UpdatePusherPhysicsEndOfTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::UpdatePusherPhysicsEndOfTick(CPhysicsPushedEntities *this)
{
  int m_Size; // ebx
  int v3; // edi
  int v4; // edi
  int v5; // edi
  int i; // edi
  int nCount; // [esp+14h] [ebp-4h]

  m_Size = this->m_rgUpdatedPushers.m_Size;
  nCount = m_Size;
  if ( m_Size > 0 )
  {
    v3 = 0;
    do
    {
      CBaseEntity::PhysicsTouchTriggers(
        this: this->m_rgUpdatedPushers.m_Memory.m_pMemory[v3].m_pEntity,
        pPrevAbsOrigin: &this->m_rgUpdatedPushers.m_Memory.m_pMemory[v3].m_vecStartAbsOrigin);
      ++v3;
      --m_Size;
    }
    while ( m_Size != 0 );
    m_Size = nCount;
  }
  v4 = 0;
  if ( this->m_rgUpdatedChildren.m_Size > 0 )
  {
    do
      CBaseEntity::PhysicsTouchTriggers(
        this: this->m_rgUpdatedChildren.m_Memory.m_pMemory[v4++],
        pPrevAbsOrigin: nullptr);
    while ( v4 < this->m_rgUpdatedChildren.m_Size );
    m_Size = nCount;
  }
  if ( m_Size > 0 )
  {
    v5 = 0;
    do
    {
      ((void (__stdcall *)(_DWORD))this->m_rgUpdatedPushers.m_Memory.m_pMemory[v5++].m_pEntity->UpdatePhysicsShadowToCurrentPosition)(a1: LODWORD(gpGlobals->frametime));
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  for ( i = 0; i < this->m_rgUpdatedChildren.m_Size; ++i )
    ((void (__stdcall *)(_DWORD))this->m_rgUpdatedChildren.m_Memory.m_pMemory[i]->UpdatePhysicsShadowToCurrentPosition)(a1: LODWORD(gpGlobals->frametime));
  this->m_rgUpdatedPushers.m_Size = 0;
  this->m_rgUpdatedChildren.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10193740
// Name: private: int CBaseEntity::PhysicsTryMove(float,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseEntity::PhysicsTryMove(CBaseEntity *this, float flTime, CGameTrace *steptrace)
{
  CBaseEntity *v3; // edi
  unsigned int (__thiscall *PhysicsSolidMaskForEntity)(CBaseEntity *); // edx
  unsigned int v5; // eax
  float z; // ecx
  float v7; // xmm3_4
  float x; // xmm1_4
  float y; // xmm2_4
  const Vector *v10; // esi
  float v11; // xmm0_4
  unsigned int v12; // eax
  float v13; // xmm2_4
  float v14; // xmm0_4
  CBaseEntity_vtbl *v15; // edx
  CBaseEntity *GroundEntity; // eax
  float v17; // edx
  Vector *AbsVelocity; // eax
  Vector *v19; // eax
  Vector *v20; // ebx
  float (__thiscall *GetFriction)(CBaseEntity *); // eax
  double v22; // st7
  const Vector *v23; // ebx
  int v24; // eax
  int v25; // edx
  float *p_z; // ecx
  bool v27; // zf
  float *v28; // ecx
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm0_4
  float overbounce; // [esp+4h] [ebp-104h]
  Vector planes[5]; // [esp+14h] [ebp-F4h] BYREF
  CGameTrace trace; // [esp+50h] [ebp-B8h] BYREF
  Vector vecCurrentVelocity; // [esp+A4h] [ebp-64h] BYREF
  Vector end; // [esp+B0h] [ebp-58h] BYREF
  Vector primal_velocity; // [esp+BCh] [ebp-4Ch]
  float m_fValue; // [esp+C8h] [ebp-40h]
  int bumpcount; // [esp+CCh] [ebp-3Ch]
  unsigned int mask; // [esp+D0h] [ebp-38h]
  CBaseEntity *v42; // [esp+D4h] [ebp-34h]
  float time_left; // [esp+D8h] [ebp-30h]
  Vector new_velocity; // [esp+DCh] [ebp-2Ch] BYREF
  Vector original_velocity; // [esp+E8h] [ebp-20h] BYREF
  const Vector *normal; // [esp+F4h] [ebp-14h]
  int blocked; // [esp+F8h] [ebp-10h]
  Vector vecAbsVelocity; // [esp+FCh] [ebp-Ch] BYREF
  int savedregs; // [esp+108h] [ebp+0h] BYREF

  v3 = this;
  PhysicsSolidMaskForEntity = this->PhysicsSolidMaskForEntity;
  v42 = this;
  mask = ((int (__fastcall *)(CBaseEntity *))PhysicsSolidMaskForEntity)(a1: this);
  v5 = (unsigned int)v3->m_iEFlags >> 12;
  memset((void *)&new_velocity, 0, sizeof(new_velocity));
  if ( (v5 & 1) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: v3, a2: (int)&savedregs);
  z = v3->m_vecAbsVelocity.z;
  v7 = flTime;
  *(_QWORD *)&vecAbsVelocity.x = *(_QWORD *)&v3->m_vecAbsVelocity.x;
  x = vecAbsVelocity.x;
  y = vecAbsVelocity.y;
  v10 = nullptr;
  vecAbsVelocity.z = z;
  v11 = z;
  blocked = 0;
  original_velocity = vecAbsVelocity;
  primal_velocity = vecAbsVelocity;
  time_left = flTime;
  bumpcount = 0;
  while ( vec3_origin.x != x || vec3_origin.y != y || vec3_origin.z != v11 )
  {
    if ( (v3->m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
      v11 = vecAbsVelocity.z;
      y = vecAbsVelocity.y;
      x = vecAbsVelocity.x;
      v7 = time_left;
    }
    v12 = (unsigned int)v3->m_iEFlags >> 11;
    v13 = (float)(y * v7) + v3->m_vecAbsOrigin.y;
    v14 = (float)(v11 * v7) + v3->m_vecAbsOrigin.z;
    end.x = (float)(x * v7) + v3->m_vecAbsOrigin.x;
    end.y = v13;
    end.z = v14;
    if ( (v12 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    if ( v3->GetDamageType(this: v3) != 0 )
      g_pGameRules->WeaponTraceEntity(
        this: g_pGameRules,
        a2: v3,
        a3: &v3->m_vecAbsOrigin,
        a4: &end,
        a5: mask,
        a6: &trace);
    else
      UTIL_TraceEntity(pEntity: v3, vecAbsStart: &v3->m_vecAbsOrigin, vecAbsEnd: &end, mask, ptr: &trace);
    if ( trace.startsolid )
    {
      CBaseEntity::SetAbsVelocity(this: v3, vecAbsVelocity: &vec3_origin);
      return 4;
    }
    if ( trace.fraction > 0.0 )
    {
      CBaseEntity::SetAbsOrigin(this: v3, absOrigin: &trace.endpos);
      original_velocity = vecAbsVelocity;
      v10 = nullptr;
    }
    if ( trace.fraction == 1.0 )
      break;
    if ( trace.m_pEnt == nullptr )
    {
      CBaseEntity::SetAbsVelocity(this: v3, &vecAbsVelocity);
      _Warning(a1: "PhysicsTryMove: !trace.u.ent");
      return 4;
    }
    if ( trace.plane.normal.z > 0.7 )
    {
      v15 = v3->__vftable;
      blocked |= 1u;
      if ( v15->CanStandOn_2(this: v3, a2: trace.m_pEnt) )
      {
        GroundEntity = CBaseEntity::GetGroundEntity(this: v3);
        if ( GroundEntity != trace.m_pEnt )
          CBaseEntity::SetGroundChangeTime(
            this: v3,
            flTime: (float)(flTime - (float)((float)(1.0 - trace.fraction) * time_left)) + gpGlobals->curtime);
        CBaseEntity::SetGroundEntity(this: v3, ground: trace.m_pEnt);
      }
    }
    if ( trace.plane.normal.z == 0.0 )
    {
      blocked |= 2u;
      if ( steptrace != nullptr )
        CGameTrace::operator=(this: steptrace, __that: &trace);
    }
    if ( (v3->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: v3, a2: (int)&savedregs);
    v17 = v3->m_vecAbsVelocity.z;
    *(_QWORD *)&vecCurrentVelocity.x = *(_QWORD *)&v3->m_vecAbsVelocity.x;
    vecCurrentVelocity.z = v17;
    CBaseEntity::PhysicsImpact(this: v3, other: trace.m_pEnt, &trace);
    if ( (v3->m_iEFlags & 1) != 0 || (v3->m_Network.m_pPev->m_fStateFlags & 2) != 0 )
      break;
    time_left = time_left - (float)(trace.fraction * time_left);
    if ( (int)v10 >= 5 )
      goto LABEL_80;
    planes[(_DWORD)v10] = trace.plane.normal;
    v10 = (const Vector *)((char *)v10 + 1);
    AbsVelocity = CBaseEntity::GetAbsVelocity(this: v3);
    if ( Vector::operator!=(this: AbsVelocity, src: &vecCurrentVelocity) )
    {
      vecAbsVelocity = *CBaseEntity::GetAbsVelocity(this: v3);
      v19 = CBaseEntity::GetAbsVelocity(this: v3);
      y = vecAbsVelocity.y;
      x = vecAbsVelocity.x;
      original_velocity = *v19;
      v11 = vecAbsVelocity.z;
    }
    else if ( v3->m_MoveType.m_Value != 2
           || (v3->m_fFlags.m_Value & 1) != 0 && ((double (__thiscall *)(CBaseEntity *))v3->GetFriction)(a1: v3) == 1.0 )
    {
      v23 = nullptr;
      if ( (int)v10 <= 0 )
      {
        v11 = new_velocity.z;
        y = new_velocity.y;
        x = new_velocity.x;
      }
      else
      {
        normal = planes;
        do
        {
          CBaseEntity::PhysicsClipVelocity(
            this: v3,
            in: &original_velocity,
            normal,
            out: &new_velocity,
            overbounce: 1.0);
          v11 = new_velocity.z;
          y = new_velocity.y;
          x = new_velocity.x;
          v24 = 0;
          if ( (int)v10 >= 4 )
          {
            v25 = 2;
            p_z = &planes[0].z;
            while ( 1 )
            {
              if ( (const Vector *)v24 != v23
                && (float)((float)((float)(*(p_z - 1) * new_velocity.y) + (float)(*(p_z - 2) * new_velocity.x))
                         + (float)(*p_z * new_velocity.z)) < 0.0 )
              {
                goto LABEL_67;
              }
              if ( (const Vector *)(v25 - 1) != v23
                && (float)((float)((float)(p_z[2] * new_velocity.y) + (float)(p_z[1] * new_velocity.x))
                         + (float)(p_z[3] * new_velocity.z)) < 0.0 )
              {
                break;
              }
              if ( (const Vector *)v25 != v23
                && (float)((float)((float)(p_z[5] * new_velocity.y) + (float)(p_z[4] * new_velocity.x))
                         + (float)(p_z[6] * new_velocity.z)) < 0.0 )
              {
                v24 += 2;
                goto LABEL_66;
              }
              if ( (const Vector *)(v25 + 1) != v23
                && (float)((float)((float)(p_z[8] * new_velocity.y) + (float)(p_z[7] * new_velocity.x))
                         + (float)(p_z[9] * new_velocity.z)) < 0.0 )
              {
                v24 += 3;
                goto LABEL_66;
              }
              v24 += 4;
              v25 += 4;
              p_z += 12;
              v3 = v42;
              if ( v24 >= (int)&v10[-1].z + 1 )
                goto LABEL_57;
            }
            ++v24;
LABEL_66:
            v3 = v42;
            goto LABEL_67;
          }
LABEL_57:
          v27 = v24 == (_DWORD)v10;
          if ( v24 < (int)v10 )
          {
            v28 = &planes[v24].z;
            do
            {
              if ( (const Vector *)v24 != v23
                && (float)((float)((float)(*(v28 - 1) * new_velocity.y) + (float)(*(v28 - 2) * new_velocity.x))
                         + (float)(*v28 * new_velocity.z)) < 0.0 )
              {
                break;
              }
              ++v24;
              v28 += 3;
            }
            while ( v24 < (int)v10 );
LABEL_67:
            v27 = v24 == (_DWORD)v10;
          }
          if ( v27 )
            break;
          ++normal;
          v23 = (const Vector *)((char *)v23 + 1);
        }
        while ( (int)v23 < (int)v10 );
      }
      if ( v23 == v10 )
      {
        if ( v10 != (const Vector *)2 )
          break;
        v29 = (float)(planes[1].x * planes[0].z) - (float)(planes[1].z * planes[0].x);
        v30 = (float)(planes[1].y * planes[0].x) - (float)(planes[1].x * planes[0].y);
        v31 = (float)((float)(v29 * vecAbsVelocity.y)
                    + (float)((float)((float)(planes[1].z * planes[0].y) - (float)(planes[1].y * planes[0].z))
                            * vecAbsVelocity.x))
            + (float)(v30 * vecAbsVelocity.z);
        x = (float)((float)(planes[1].z * planes[0].y) - (float)(planes[1].y * planes[0].z)) * v31;
        y = v29 * v31;
        v11 = v31 * v30;
      }
      vecAbsVelocity.z = v11;
      vecAbsVelocity.y = y;
      vecAbsVelocity.x = x;
      if ( (float)((float)((float)(primal_velocity.y * y) + (float)(primal_velocity.x * x))
                 + (float)(primal_velocity.z * v11)) <= 0.0 )
      {
LABEL_80:
        CBaseEntity::SetAbsVelocity(this: v3, vecAbsVelocity: &vec3_origin);
        return blocked;
      }
    }
    else
    {
      if ( (int)v10 > 0 )
      {
        v20 = planes;
        for ( normal = v10; normal != nullptr; normal = (const Vector *)((char *)normal - 1) )
        {
          if ( v20->z <= 0.7 )
          {
            GetFriction = v3->GetFriction;
            m_fValue = sv_bounce.m_pParent->m_Value.m_fValue;
            v22 = ((double (__thiscall *)(CBaseEntity *))GetFriction)(a1: v3);
            overbounce = (1.0 - v22) * m_fValue + 1.0;
            CBaseEntity::PhysicsClipVelocity(
              this: v3,
              in: &original_velocity,
              normal: v20,
              out: &new_velocity,
              overbounce);
          }
          else
          {
            CBaseEntity::PhysicsClipVelocity(
              this: v3,
              in: &original_velocity,
              normal: v20,
              out: &new_velocity,
              overbounce: 1.0);
            original_velocity = new_velocity;
          }
          ++v20;
        }
      }
      x = new_velocity.x;
      y = new_velocity.y;
      v11 = new_velocity.z;
      vecAbsVelocity = new_velocity;
      original_velocity = new_velocity;
    }
    if ( ++bumpcount >= 4 )
      break;
    v7 = time_left;
  }
  CBaseEntity::SetAbsVelocity(this: v3, &vecAbsVelocity);
  return blocked;
}

//------------------------------------------------------------------------------
// Address: 0x10193F40
// Name: void Physics_RunThinkFunctions(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Physics_RunThinkFunctions(bool simulating)
{
  IMDLCache *m_pCache; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  int m_nValue; // eax
  int j; // esi
  CBasePlayer *v5; // edi
  int v6; // esi
  void *v7; // esp
  int v8; // ebx
  int i; // esi
  void (__thiscall *EndLock)(IMDLCache *); // eax
  CBaseEntity *v11; // [esp-4h] [ebp-18h]
  CBaseEntity *v12[3]; // [esp+0h] [ebp-14h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+Ch] [ebp-8h]
  float starttime; // [esp+10h] [ebp-4h]

  m_pCache = mdlcache;
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( sv_teststepsimulation.m_pParent != nullptr )
    m_nValue = sv_teststepsimulation.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_bTestMoveTypeStepSimulation = m_nValue != 0;
  starttime = gpGlobals->curtime;
  CGlobalEntityList::CleanupDeleteList(this: &gEntList);
  if ( simulating )
  {
    UTIL_DisableRemoveImmediate();
    v6 = SimThink_ListCount();
    if ( v6 <= 1 )
      v6 = 1;
    v7 = alloca(4 * v6);
    v8 = SimThink_ListCopy(pList: v12, listMax: v6);
    for ( i = 0; i < v8; ++i )
    {
      v11 = v12[i];
      gpGlobals->curtime = starttime;
      Physics_SimulateEntity(pEntity: v11);
    }
    CPhysicsPushedEntities::UpdatePusherPhysicsEndOfTick(this: g_pPushedEntities);
    UTIL_EnableRemoveImmediate();
    physenv->CleanupDeleteList(this: physenv);
    m_pCache = cacheCriticalSection.m_pCache;
  }
  else
  {
    for ( j = 1; j <= gpGlobals->maxClients; ++j )
    {
      v5 = UTIL_PlayerByIndex(playerIndex: j);
      if ( v5 != nullptr )
      {
        gpGlobals->curtime = starttime;
        CBasePlayer::ForceSimulation(this: v5);
        Physics_SimulateEntity(pEntity: v5);
      }
    }
  }
  EndLock = m_pCache->EndLock;
  gpGlobals->curtime = starttime;
  EndLock(this: m_pCache);
}

//------------------------------------------------------------------------------
// Address: 0x10194140
// Name: public: CPhysicsPushedEntities::CPhysicsPushedEntities(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsPushedEntities *__thiscall CPhysicsPushedEntities::CPhysicsPushedEntities(CPhysicsPushedEntities *this)
{
  CPhysicsPushedEntities::PhysicsPusherInfo_t *v2; // eax
  CPhysicsPushedEntities::PhysicsPushedInfo_t *v3; // eax

  this->__vftable = (CPhysicsPushedEntities_vtbl *)&CPhysicsPushedEntities::`vftable';
  this->m_rgPusher.m_Memory.m_nAllocationCount = 8;
  this->m_rgPusher.m_Memory.m_nGrowSize = 8;
  this->m_rgPusher.m_Memory.m_pMemory = nullptr;
  v2 = (CPhysicsPushedEntities::PhysicsPusherInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 128);
  this->m_rgPusher.m_Memory.m_pMemory = v2;
  this->m_rgPusher.m_pElements = v2;
  this->m_rgPusher.m_Size = 0;
  this->m_rgMoved.m_Memory.m_nAllocationCount = 32;
  this->m_rgMoved.m_Memory.m_nGrowSize = 32;
  this->m_rgMoved.m_Memory.m_pMemory = nullptr;
  v3 = (CPhysicsPushedEntities::PhysicsPushedInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 3328);
  this->m_rgMoved.m_Memory.m_pMemory = v3;
  this->m_rgMoved.m_Size = 0;
  this->m_rgMoved.m_pElements = v3;
  this->m_rgUpdatedPushers.m_Memory.m_pMemory = nullptr;
  this->m_rgUpdatedPushers.m_Memory.m_nAllocationCount = 0;
  this->m_rgUpdatedPushers.m_Memory.m_nGrowSize = 0;
  this->m_rgUpdatedPushers.m_Size = 0;
  this->m_rgUpdatedPushers.m_pElements = nullptr;
  this->m_rgUpdatedChildren.m_Memory.m_pMemory = nullptr;
  this->m_rgUpdatedChildren.m_Memory.m_nAllocationCount = 0;
  this->m_rgUpdatedChildren.m_Memory.m_nGrowSize = 0;
  this->m_rgUpdatedChildren.m_Size = 0;
  this->m_rgUpdatedChildren.m_pElements = nullptr;
  this->m_flMoveTime = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101941E0
// Name: protected: void CPhysicsPushedEntities::FinishPush(bool,struct CPhysicsPushedEntities::RotatingPushMove_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::FinishPush(
        CPhysicsPushedEntities *this,
        bool bIsRotPush,
        const CPhysicsPushedEntities::RotatingPushMove_t *pRotPushMove)
{
  int v4; // eax
  int v5; // eax
  CPhysicsPushedEntities::PhysicsPushedInfo_t *m_pMemory; // esi
  CBaseEntity *v7; // ecx
  _DWORD *v8; // esi
  CBaseEntity *v9; // ebx
  CAI_BaseNPC *v10; // eax
  CBaseEntity *v11; // eax
  int i; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]

  CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddVectorToTail(
    this: &this->m_rgUpdatedPushers,
    src: &this->m_rgPusher);
  v4 = this->m_rgMoved.m_Size - 1;
  i = v4;
  if ( v4 >= 0 )
  {
    v5 = 104 * v4;
    for ( j = v5; ; v5 = j )
    {
      m_pMemory = this->m_rgMoved.m_Memory.m_pMemory;
      v7 = *(CBaseEntity **)((char *)&m_pMemory->m_pEntity + v5);
      v8 = (CBaseEntity **)((char *)&m_pMemory->m_pEntity + v5);
      v9 = v7;
      CBaseEntity::PhysicsTouchTriggers(this: v7, pPrevAbsOrigin: (const Vector *)(v8 + 1));
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 632))(a1: LODWORD(gpGlobals->frametime));
      v10 = (CAI_BaseNPC *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v8 + 296))(a1: *v8);
      if ( *((_BYTE *)v8 + 101) != 0 && v10 != nullptr )
        CAI_BaseNPC::NotifyPushMove(this: v10);
      v11 = (CBaseEntity *)v8[23];
      if ( v11 != nullptr )
        CBaseEntity::PhysicsImpact(this: v9, other: v11, trace: (CGameTrace *)(v8 + 4));
      if ( bIsRotPush )
        this->FinishRotPushedEntity(this, a2: v9, a3: pRotPushMove);
      j -= 104;
      if ( --i < 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101942B0
// Name: public: virtual bool CTraceFilterAgainstEntityList::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTraceFilterAgainstEntityList::ShouldHitEntity(
        CTraceFilterAgainstEntityList *this,
        IHandleEntity *pEntity,
        int contentsMask)
{
  int v3; // eax
  IHandleEntity **i; // ecx

  v3 = this->m_entityList.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  for ( i = &this->m_entityList.m_Memory.m_pMemory[v3]; *i != pEntity; --i )
  {
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101942E0
// Name: private: void CBaseEntity::PhysicsAddHalfGravity(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsAddHalfGravity(CBaseEntity *this, float timestep)
{
  float m_flGravity; // xmm0_4
  unsigned int v4; // eax
  __int64 v5; // xmm1_8
  __int64 vecNewBaseVelocity; // [esp+8h] [ebp-1Ch]
  Vector vecAbsVelocity; // [esp+14h] [ebp-10h] BYREF
  float ent_gravity; // [esp+20h] [ebp-4h]
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  m_flGravity = this->m_flGravity;
  if ( m_flGravity == 0.0 )
    m_flGravity = 1.0;
  v4 = (unsigned int)this->m_iEFlags >> 12;
  ent_gravity = m_flGravity;
  if ( (v4 & 1) != 0 )
  {
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    m_flGravity = ent_gravity;
  }
  v5 = *(_QWORD *)&this->m_vecAbsVelocity.x;
  vecAbsVelocity.z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecAbsVelocity.x = v5;
  vecAbsVelocity.z = vecAbsVelocity.z
                   - (float)((float)((float)(m_flGravity * 0.5) * sv_gravity.m_pParent->m_Value.m_fValue) * timestep);
  vecAbsVelocity.z = (float)(gpGlobals->frametime * this->m_vecBaseVelocity.m_Value.z) + vecAbsVelocity.z;
  CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
  vecNewBaseVelocity = *(_QWORD *)&this->m_vecBaseVelocity.m_Value.x;
  if ( *(float *)&vecNewBaseVelocity != this->m_vecBaseVelocity.m_Value.x
    || *((float *)&vecNewBaseVelocity + 1) != this->m_vecBaseVelocity.m_Value.y
    || this->m_vecBaseVelocity.m_Value.z != 0.0 )
  {
    this->NetworkStateChanged_m_vecBaseVelocity(this, a2: &this->m_vecBaseVelocity);
    *(_QWORD *)&this->m_vecBaseVelocity.m_Value.x = vecNewBaseVelocity;
    this->m_vecBaseVelocity.m_Value.z = 0.0;
  }
  CBaseEntity::PhysicsCheckVelocity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10194410
// Name: private: void CBaseEntity::PhysicsStepRunTimestep(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseEntity::PhysicsStepRunTimestep(
        CBaseEntity *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        float timestep)
{
  int m_Value; // eax
  float y; // xmm1_4
  float x; // xmm2_4
  float (__thiscall *GetFriction)(CBaseEntity *); // edx
  double v9; // st7
  float m_fValue; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // [esp+18h] [ebp-3Ch]
  Vector m_vecAbsVelocity; // [esp+30h] [ebp-24h] BYREF
  Vector vecAbsVelocity; // [esp+3Ch] [ebp-18h]
  float fFallingSpeed; // [esp+48h] [ebp-Ch] BYREF
  float friction; // [esp+4Ch] [ebp-8h]
  float retaddr; // [esp+54h] [ebp+0h]

  fFallingSpeed = a2;
  friction = retaddr;
  CBaseEntity::PhysicsCheckVelocity(this);
  HIWORD(vecAbsVelocity.z) = this->m_fFlags.m_Value & 1;
  BYTE1(vecAbsVelocity.z) = CBaseEntity::PhysicsCheckWater(this);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&fFallingSpeed);
  vecAbsVelocity.x = this->m_vecAbsVelocity.z;
  if ( BYTE2(vecAbsVelocity.z) == 0 )
  {
    m_Value = this->m_fFlags.m_Value;
    if ( (m_Value & 0x800) == 0 && ((m_Value & 0x1000) == 0 || this->m_nWaterLevel.m_Value == 0) )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&fFallingSpeed);
      if ( BYTE1(vecAbsVelocity.z) == 0 )
      {
        CBaseEntity::PhysicsAddHalfGravity(this, timestep);
        HIBYTE(vecAbsVelocity.z) = 1;
      }
    }
  }
  if ( (this->m_fFlags.m_Value & 0x400000) == 0 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&fFallingSpeed);
    if ( vec3_origin.x != this->m_vecAbsVelocity.x
      || vec3_origin.y != this->m_vecAbsVelocity.y
      || vec3_origin.z != this->m_vecAbsVelocity.z
      || vec3_origin.x != this->m_vecBaseVelocity.m_Value.x
      || vec3_origin.y != this->m_vecBaseVelocity.m_Value.y
      || vec3_origin.z != this->m_vecBaseVelocity.m_Value.z )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&fFallingSpeed);
      m_vecAbsVelocity = this->m_vecAbsVelocity;
      CBaseEntity::SetGroundEntity(this, ground: nullptr);
      y = m_vecAbsVelocity.y;
      x = m_vecAbsVelocity.x;
      if ( BYTE2(vecAbsVelocity.z) != 0 )
      {
        v15 = fsqrt(
                (float)((float)(m_vecAbsVelocity.y * m_vecAbsVelocity.y)
                      + (float)(m_vecAbsVelocity.z * m_vecAbsVelocity.z))
              + (float)(m_vecAbsVelocity.x * m_vecAbsVelocity.x));
        if ( v15 != 0.0 )
        {
          GetFriction = this->GetFriction;
          vecAbsVelocity.y = sv_friction.m_pParent->m_Value.m_fValue;
          v9 = ((double (__thiscall *)(CBaseEntity *))GetFriction)(a1: this);
          m_fValue = sv_stopspeed.m_pParent->m_Value.m_fValue;
          vecAbsVelocity.y = v9 * vecAbsVelocity.y;
          if ( m_fValue <= v15 )
            m_fValue = v15;
          v11 = v15 - (float)((float)(m_fValue * timestep) * vecAbsVelocity.y);
          if ( v11 < 0.0 )
            v11 = 0.0;
          v12 = v11 / v15;
          x = m_vecAbsVelocity.x * v12;
          y = m_vecAbsVelocity.y * v12;
        }
      }
      m_vecAbsVelocity.x = this->m_vecBaseVelocity.m_Value.x + x;
      m_vecAbsVelocity.y = this->m_vecBaseVelocity.m_Value.y + y;
      m_vecAbsVelocity.z = this->m_vecBaseVelocity.m_Value.z + m_vecAbsVelocity.z;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &m_vecAbsVelocity);
      CBaseEntity::SimulateAngles(this, flFrameTime: timestep);
      CBaseEntity::PhysicsCheckVelocity(this);
      CBaseEntity::PhysicsTryMove(this, flTime: timestep, steptrace: nullptr);
      CBaseEntity::PhysicsCheckVelocity(this);
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&fFallingSpeed);
      v13 = this->m_vecAbsVelocity.y - this->m_vecBaseVelocity.m_Value.y;
      v14 = this->m_vecAbsVelocity.z - this->m_vecBaseVelocity.m_Value.z;
      m_vecAbsVelocity.x = this->m_vecAbsVelocity.x - this->m_vecBaseVelocity.m_Value.x;
      m_vecAbsVelocity.y = v13;
      m_vecAbsVelocity.z = v14;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &m_vecAbsVelocity);
      CBaseEntity::PhysicsCheckVelocity(this);
      if ( (this->m_fFlags.m_Value & 1) == 0 )
        CBaseEntity::PhysicsStepRecheckGround(this, a2: COERCE_FLOAT(&fFallingSpeed), a3, a4: (int)this);
      CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
    }
  }
  if ( (this->m_fFlags.m_Value & 1) == 0 )
  {
    if ( HIBYTE(vecAbsVelocity.z) == 0 )
      return;
    CBaseEntity::PhysicsAddHalfGravity(this, timestep);
  }
  if ( HIBYTE(vecAbsVelocity.z) != 0 && (this->m_fFlags.m_Value & 1) != 0 )
    ((void (__thiscall *)(CBaseEntity *, _DWORD))this->PhysicsLandedOnGround)(a1: this, a2: LODWORD(vecAbsVelocity.x));
}

//------------------------------------------------------------------------------
// Address: 0x101947D0
// Name: public: CPushBlockerEnum::CPushBlockerEnum(class CPhysicsPushedEntities __near *)
// Source: json
//------------------------------------------------------------------------------
CPushBlockerEnum *__thiscall CPushBlockerEnum::CPushBlockerEnum(
        CPushBlockerEnum *this,
        CPhysicsPushedEntities *pPushedEntities)
{
  CPhysicsPushedEntities *m_pPushedEntities; // edx
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  IHandleEntity **m_pMemory; // ecx
  int v10; // eax
  IHandleEntity **v11; // ebx
  int m_collisionGroupCount; // edi
  int m_Value; // ebx
  int v14; // eax
  int *m_collisionGroups; // ecx
  int v17; // [esp+8h] [ebp-8h]
  int v18; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  this->m_pPushedEntities = pPushedEntities;
  this->__vftable = (CPushBlockerEnum_vtbl *)&CPushBlockerEnum::`vftable';
  this->m_pushersOnly.__vftable = (CTraceFilterAgainstEntityList_vtbl *)&CTraceFilterAgainstEntityList::`vftable';
  this->m_pushersOnly.m_entityList.m_Memory.m_pMemory = nullptr;
  this->m_pushersOnly.m_entityList.m_Memory.m_nAllocationCount = 0;
  this->m_pushersOnly.m_entityList.m_Memory.m_nGrowSize = 0;
  this->m_pushersOnly.m_entityList.m_Size = 0;
  this->m_pushersOnly.m_entityList.m_pElements = nullptr;
  this->m_pRootHighestParent = CBaseEntity::GetRootMoveParent(this: this->m_pPushedEntities->m_rgPusher.m_Memory.m_pMemory->m_pEntity);
  ++CPushBlockerEnum::s_nEnumCount;
  m_pPushedEntities = this->m_pPushedEntities;
  this->m_collisionGroupCount = 0;
  v4 = m_pPushedEntities->m_rgPusher.m_Size - 1;
  i = v4;
  if ( v4 >= 0 )
  {
    v5 = 16 * v4;
    v18 = v4;
    do
    {
      v6 = *(int *)((char *)&this->m_pPushedEntities->m_rgPusher.m_Memory.m_pMemory->m_pEntity + v5);
      v17 = v6;
      if ( *(_BYTE *)(v6 + 262) != 0 && (*(_BYTE *)(v6 + 260) & 4) == 0 )
      {
        m_Size = this->m_pushersOnly.m_entityList.m_Size;
        m_nAllocationCount = this->m_pushersOnly.m_entityList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pushersOnly.m_entityList,
            num: m_Size - m_nAllocationCount + 1);
          v6 = v17;
        }
        ++this->m_pushersOnly.m_entityList.m_Size;
        m_pMemory = this->m_pushersOnly.m_entityList.m_Memory.m_pMemory;
        v10 = this->m_pushersOnly.m_entityList.m_Size - m_Size - 1;
        this->m_pushersOnly.m_entityList.m_pElements = m_pMemory;
        if ( v10 > 0 )
        {
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
          v6 = v17;
        }
        v11 = &this->m_pushersOnly.m_entityList.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = (IHandleEntity *)v6;
        m_collisionGroupCount = this->m_collisionGroupCount;
        m_Value = this->m_pPushedEntities->m_rgPusher.m_Memory.m_pMemory[v18].m_pEntity->m_CollisionGroup.m_Value;
        v14 = 0;
        if ( m_collisionGroupCount <= 0 )
        {
LABEL_15:
          if ( (unsigned int)m_collisionGroupCount < 8 )
          {
            this->m_collisionGroups[m_collisionGroupCount] = m_Value;
            ++this->m_collisionGroupCount;
          }
        }
        else
        {
          m_collisionGroups = this->m_collisionGroups;
          while ( *m_collisionGroups != m_Value )
          {
            ++v14;
            ++m_collisionGroups;
            if ( v14 >= m_collisionGroupCount )
              goto LABEL_15;
          }
        }
        v4 = i;
      }
      --v4;
      v5 = v18 * 16 - 16;
      i = v4;
      --v18;
    }
    while ( v4 >= 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10194910
// Name: private: bool CPushBlockerEnum::IsStandingOnPusher(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPushBlockerEnum::IsStandingOnPusher(CPushBlockerEnum *this, CBaseEntity *pCheck)
{
  CBaseEntity *GroundEntity; // eax
  CPhysicsPushedEntities *m_pPushedEntities; // esi
  int v5; // ecx
  CPhysicsPushedEntities::PhysicsPusherInfo_t *i; // edx

  GroundEntity = CBaseEntity::GetGroundEntity(this: pCheck);
  if ( (pCheck->m_fFlags.m_Value & 1) == 0 && GroundEntity == nullptr )
    return 0;
  m_pPushedEntities = this->m_pPushedEntities;
  v5 = m_pPushedEntities->m_rgPusher.m_Size - 1;
  if ( v5 < 0 )
    return 0;
  for ( i = &m_pPushedEntities->m_rgPusher.m_Memory.m_pMemory[v5]; i->m_pEntity != GroundEntity; --i )
  {
    if ( --v5 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10194960
// Name: private: bool CPushBlockerEnum::IntersectsPushers(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPushBlockerEnum::IntersectsPushers(CPushBlockerEnum *this, CBaseEntity *pTest)
{
  ICollideable *(__thiscall *GetCollideable)(struct CBaseEntity *); // edx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  CGameTrace tr; // [esp+Ch] [ebp-58h] BYREF
  CPushBlockerEnum *v9; // [esp+60h] [ebp-4h]
  int savedregs; // [esp+64h] [ebp+0h] BYREF
  CBaseEntity *pTesta; // [esp+6Ch] [ebp+8h]

  GetCollideable = pTest->GetCollideable;
  v9 = this;
  v4 = (int)GetCollideable(this: pTest);
  if ( (pTest->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTest, a2: (int)&savedregs);
  if ( (pTest->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pTest, a2: (int)&savedregs);
  pTesta = (CBaseEntity *)enginetrace->__vftable;
  v5 = ((int (__thiscall *)(CBaseEntity *, CTraceFilterAgainstEntityList *, CGameTrace *))pTest->PhysicsSolidMaskForEntity)(
         a1: pTest,
         a2: &v9->m_pushersOnly,
         a3: &tr);
  v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 36))(a1: v4, a2: v5);
  (*(void (__thiscall **)(IEngineTrace *, int, Vector *, Vector *, int))&pTesta->m_Network.m_PVSInfo.m_nAreaNum)(
    a1: enginetrace,
    a2: v4,
    a3: &pTest->m_vecAbsOrigin,
    a4: &pTest->m_vecAbsOrigin,
    a5: v6);
  return tr.startsolid;
}

//------------------------------------------------------------------------------
// Address: 0x10194A00
// Name: private: class CBaseEntity __near * CPushBlockerEnum::GetPushableEntity(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CPushBlockerEnum::GetPushableEntity(CPushBlockerEnum *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  int v6; // eax
  CBaseEntity *v7; // esi
  int v9; // eax
  int v10; // edi
  int *i; // ebx
  CBaseEntity *RootMoveParent; // ebx

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
  if ( v4->m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  m_pEntity = v4->m_pEntity;
  if ( m_pEntity == nullptr )
    return nullptr;
  v6 = (int)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  v7 = (CBaseEntity *)v6;
  if ( v6 == 0 )
    return nullptr;
  if ( *(_DWORD *)(v6 + 456) == CPushBlockerEnum::s_nEnumCount )
    return nullptr;
  if ( *(_BYTE *)(v6 + 262) == 0 )
    return nullptr;
  if ( (*(_BYTE *)(v6 + 260) & 4) != 0 )
    return nullptr;
  v9 = *(unsigned __int8 *)(v6 + 214);
  if ( v9 == 7 || v7->m_MoveType.m_Value == 0 || v9 == 6 || v9 == 8 )
    return nullptr;
  v10 = 0;
  v7->m_nPushEnumCount = CPushBlockerEnum::s_nEnumCount;
  if ( this->m_collisionGroupCount <= 0 )
    return nullptr;
  for ( i = this->m_collisionGroups;
        !g_pGameRules->ShouldCollide(this: g_pGameRules, a2: v7->m_CollisionGroup.m_Value, a3: *i);
        ++i )
  {
    if ( ++v10 >= this->m_collisionGroupCount )
      return nullptr;
  }
  RootMoveParent = CBaseEntity::GetRootMoveParent(this: v7);
  if ( RootMoveParent != this->m_pRootHighestParent
    && (CPushBlockerEnum::IsStandingOnPusher(this, pCheck: v7) != 0
     || CPushBlockerEnum::IntersectsPushers(this, pTest: v7)) )
  {
    return RootMoveParent;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194B10
// Name: protected: void CPhysicsPushedEntities::GenerateBlockingEntityList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::GenerateBlockingEntityList(CPhysicsPushedEntities *this)
{
  int v2; // esi
  int v3; // edi
  CBaseEntity *m_pEntity; // eax
  CPushBlockerEnum blockerEnum; // [esp+8h] [ebp-60h] BYREF
  Vector vecAbsMins; // [esp+50h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+5Ch] [ebp-Ch] BYREF

  this->m_rgMoved.m_Size = 0;
  CPushBlockerEnum::CPushBlockerEnum(this: &blockerEnum, pPushedEntities: this);
  v2 = this->m_rgPusher.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      m_pEntity = this->m_rgPusher.m_Memory.m_pMemory[v3].m_pEntity;
      if ( m_pEntity->m_Collision.m_nSolidType.m_Value != 0
        && (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 4) == 0
        && (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 0x20) == 0 )
      {
        CCollisionProperty::CollisionAABBToWorldAABB(
          this: &m_pEntity->m_Collision,
          entityMins: &m_pEntity->m_Collision.m_vecMins.m_Value,
          entityMaxs: &m_pEntity->m_Collision.m_vecMaxs.m_Value,
          pWorldMins: &vecAbsMins,
          pWorldMaxs: &vecAbsMaxs);
        partition->EnumerateElementsInBox(
          this: partition,
          a2: 1024,
          a3: &vecAbsMins,
          a4: &vecAbsMaxs,
          a5: false,
          a6: &blockerEnum);
      }
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&blockerEnum.m_pushersOnly.m_entityList);
}

//------------------------------------------------------------------------------
// Address: 0x10194BC0
// Name: protected: void CPhysicsPushedEntities::GenerateBlockingEntityListAddBox(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::GenerateBlockingEntityListAddBox(
        CPhysicsPushedEntities *this,
        const Vector *vecMoved)
{
  int v3; // esi
  int v4; // edi
  CBaseEntity *m_pEntity; // eax
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  IHandleEntity **m_pMemory; // eax
  CPushBlockerEnum blockerEnum; // [esp+Ch] [ebp-60h] BYREF
  Vector vecAbsMins; // [esp+54h] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+60h] [ebp-Ch] BYREF

  this->m_rgMoved.m_Size = 0;
  CPushBlockerEnum::CPushBlockerEnum(this: &blockerEnum, pPushedEntities: this);
  v3 = this->m_rgPusher.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = v3;
    do
    {
      m_pEntity = this->m_rgPusher.m_Memory.m_pMemory[v4].m_pEntity;
      if ( m_pEntity->m_Collision.m_nSolidType.m_Value != 0
        && (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 4) == 0
        && (m_pEntity->m_Collision.m_usSolidFlags.m_Value & 0x20) == 0 )
      {
        CCollisionProperty::CollisionAABBToWorldAABB(
          this: &m_pEntity->m_Collision,
          entityMins: &m_pEntity->m_Collision.m_vecMins.m_Value,
          entityMaxs: &m_pEntity->m_Collision.m_vecMaxs.m_Value,
          pWorldMins: &vecAbsMins,
          pWorldMaxs: &vecAbsMaxs);
        x = vecMoved->x;
        if ( vecMoved->x < 0.0 )
          vecAbsMaxs.x = vecAbsMaxs.x - x;
        else
          vecAbsMins.x = vecAbsMins.x - x;
        y = vecMoved->y;
        if ( y < 0.0 )
          vecAbsMaxs.y = vecAbsMaxs.y - y;
        else
          vecAbsMins.y = vecAbsMins.y - y;
        z = vecMoved->z;
        if ( z < 0.0 )
          vecAbsMaxs.z = vecAbsMaxs.z - z;
        else
          vecAbsMins.z = vecAbsMins.z - z;
        partition->EnumerateElementsInBox(
          this: partition,
          a2: 1024,
          a3: &vecAbsMins,
          a4: &vecAbsMaxs,
          a5: false,
          a6: &blockerEnum);
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  m_pMemory = blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_pMemory;
  blockerEnum.m_pushersOnly.m_entityList.m_Size = 0;
  if ( blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_pMemory = nullptr;
    }
    blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_nAllocationCount = 0;
  }
  blockerEnum.m_pushersOnly.m_entityList.m_pElements = m_pMemory;
  if ( blockerEnum.m_pushersOnly.m_entityList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10194D30
// Name: protected: void CPhysicsPushedEntities::SetupAllInHierarchy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::SetupAllInHierarchy(CPhysicsPushedEntities *this, CBaseEntity *pRoot)
{
  CBaseEntity *panel; // ebx
  CPhysicsPushedEntities *v3; // edi
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_rgPusher; // esi
  CBaseEntityList *v5; // edx
  unsigned int m_Index; // eax
  vgui::Panel *m_pEntity; // ebx
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // edi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v10; // ecx
  int v11; // eax
  unsigned int m_nGrowSize; // eax
  IHandleEntity *v13; // eax
  int v14; // ebx
  vgui::Panel *v15; // edi
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v16; // ecx
  int p_labelPanel; // eax
  int nRecurseIndex; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]

  panel = pRoot;
  v3 = this;
  if ( pRoot != nullptr )
  {
    p_m_rgPusher = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&this->m_rgPusher;
    this->m_rgPusher.m_Memory.m_pMemory[CUtlVector<CPhysicsPushedEntities::PhysicsPusherInfo_t,CUtlMemory<CPhysicsPushedEntities::PhysicsPusherInfo_t,int>>::AddToTail(this: &this->m_rgPusher)].m_pEntity = pRoot;
    v5 = g_pEntityList;
    nRecurseIndex = 0;
    for ( i = 0; ; panel = (CBaseEntity *)p_m_rgPusher->m_pMemory[i].m_Element.panel )
    {
      m_Index = panel->m_hMoveChild.m_Index;
      if ( m_Index == -1 || v5->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = (vgui::Panel *)v5->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        do
        {
          m_pMemory = p_m_rgPusher[1].m_pMemory;
          m_nAllocationCount = p_m_rgPusher->m_nAllocationCount;
          if ( (int)&m_pMemory->m_Element.panel + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
              this: p_m_rgPusher,
              num: (int)&m_pMemory->m_Element.panel - m_nAllocationCount + 1);
          ++p_m_rgPusher[1].m_pMemory;
          v10 = p_m_rgPusher->m_pMemory;
          v11 = (char *)p_m_rgPusher[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_rgPusher[1].m_nAllocationCount = (int)p_m_rgPusher->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[(int)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 16 * v11);
          p_m_rgPusher->m_pMemory[(_DWORD)m_pMemory].m_Element.panel = m_pEntity;
          m_nGrowSize = m_pEntity->m_sNavDownName.m_Storage.m_Memory.m_nGrowSize;
          v5 = g_pEntityList;
          if ( m_nGrowSize == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nGrowSize].m_SerialNumber != HIWORD(m_nGrowSize) )
          {
            v13 = nullptr;
          }
          else
          {
            v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nGrowSize].m_pEntity;
          }
          m_pEntity = (vgui::Panel *)v13;
        }
        while ( v13 != nullptr );
        v3 = this;
      }
      ++i;
      if ( ++nRecurseIndex >= v3->m_rgPusher.m_Size )
        break;
    }
    v14 = 0;
    ia = 0;
    if ( v3->m_rgPusher.m_Size > 0 )
    {
      do
      {
        v15 = p_m_rgPusher->m_pMemory[v14].m_Element.panel;
        if ( ((int)v15->m_sNavUpName.m_Storage.m_Memory.m_pMemory & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(
            this: (CBaseEntity *)p_m_rgPusher->m_pMemory[v14].m_Element.panel,
            a2: (int)&savedregs);
        v16 = p_m_rgPusher->m_pMemory;
        v16[v14].m_Element.labelPanel = (vgui::Panel *)v15[1].m_OverridableColorEntries.m_Memory.m_nGrowSize;
        p_labelPanel = (int)&v16[v14].m_Element.labelPanel;
        *(float *)(p_labelPanel + 4) = *(float *)&v15[1].m_OverridableColorEntries.m_Size;
        ++v14;
        *(float *)(p_labelPanel + 8) = *(float *)&v15[1].m_OverridableColorEntries.m_pElements;
        ++ia;
      }
      while ( ia < this->m_rgPusher.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194EB0
// Name: public: class CBaseEntity __near * CPhysicsPushedEntities::PerformRotatePush(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CPhysicsPushedEntities::PerformRotatePush(
        CPhysicsPushedEntities *this,
        CBaseEntity *pRoot,
        float movetime)
{
  float z; // ecx
  CPhysicsPushedEntities::PhysicsPushedInfo_t *v6; // edi
  CBaseEntity *m_pEnt; // eax
  int v8; // edi
  int v9; // ebx
  CPhysicsPushedEntities::RotatingPushMove_t rotPushMove; // [esp+10h] [ebp-84h] BYREF
  QAngle angPrevAngles; // [esp+88h] [ebp-Ch] BYREF
  CBaseEntity *pBlocker; // [esp+9Ch] [ebp+8h]

  this->m_bIsUnblockableByPlayer = pRoot->m_fFlags.m_Value < 0;
  this->m_rgPusher.m_Size = 0;
  CPhysicsPushedEntities::SetupAllInHierarchy(this, pRoot);
  z = pRoot->m_angRotation.m_Value.z;
  *(_QWORD *)&angPrevAngles.x = *(_QWORD *)&pRoot->m_angRotation.m_Value.x;
  angPrevAngles.z = z;
  CPhysicsPushedEntities::RotateRootEntity(this, pRoot, movetime, rotation: &rotPushMove);
  CPhysicsPushedEntities::GenerateBlockingEntityList(this);
  if ( this->SpeculativelyCheckRotPush(this, a2: &rotPushMove, a3: pRoot) != 0 )
  {
    CPhysicsPushedEntities::FinishPush(this, bIsRotPush: true, pRotPushMove: &rotPushMove);
    return nullptr;
  }
  else
  {
    v6 = &this->m_rgMoved.m_Memory.m_pMemory[this->m_nBlocker];
    m_pEnt = v6->m_Trace.m_pEnt;
    if ( m_pEnt != nullptr )
      CBaseEntity::PhysicsImpact(this: v6->m_pEntity, other: m_pEnt, trace: &v6->m_Trace);
    pBlocker = v6->m_pEntity;
    CBaseEntity::SetLocalAngles(this: pRoot, angles: &angPrevAngles);
    v8 = this->m_rgMoved.m_Size - 1;
    if ( v8 >= 0 )
    {
      v9 = v8;
      do
      {
        CBaseEntity::SetAbsOrigin(
          this: this->m_rgMoved.m_Memory.m_pMemory[v9].m_pEntity,
          absOrigin: &this->m_rgMoved.m_Memory.m_pMemory[v9].m_vecStartAbsOrigin);
        --v9;
        --v8;
      }
      while ( v8 >= 0 );
    }
    return pBlocker;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10194FA0
// Name: public: class CBaseEntity __near * CPhysicsPushedEntities::PerformLinearPush(class CBaseEntity __near *,float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__userpurge CPhysicsPushedEntities::PerformLinearPush@<eax>(
        CPhysicsPushedEntities *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        CBaseEntity *pRoot,
        float movetime)
{
  float z; // ecx
  CPhysicsPushedEntities::PhysicsPushedInfo_t *v7; // edi
  CBaseEntity *m_pEnt; // eax
  int v9; // edi
  int v10; // ebx
  Vector vecPrevOrigin; // [esp+10h] [ebp-18h] BYREF
  Vector vecAbsPush; // [esp+1Ch] [ebp-Ch] BYREF
  CBaseEntity *pBlocker; // [esp+34h] [ebp+Ch]

  this->m_flMoveTime = movetime;
  this->m_bIsUnblockableByPlayer = pRoot->m_fFlags.m_Value < 0;
  this->m_rgPusher.m_Size = 0;
  CPhysicsPushedEntities::SetupAllInHierarchy(this, pRoot);
  z = pRoot->m_vecOrigin.m_Value.z;
  *(_QWORD *)&vecPrevOrigin.x = *(_QWORD *)&pRoot->m_vecOrigin.m_Value.x;
  vecPrevOrigin.z = z;
  CPhysicsPushedEntities::LinearlyMoveRootEntity(this, pRoot, movetime, pAbsPushVector: &vecAbsPush);
  CPhysicsPushedEntities::GenerateBlockingEntityListAddBox(this, vecMoved: &vecAbsPush);
  if ( ((unsigned __int8 (__thiscall *)(CPhysicsPushedEntities *, Vector *, int, int))this->SpeculativelyCheckLinearPush)(
         a1: this,
         a2: &vecAbsPush,
         a3,
         a4: a2) != 0 )
  {
    CPhysicsPushedEntities::FinishPush(this, bIsRotPush: false, pRotPushMove: nullptr);
    return nullptr;
  }
  else
  {
    v7 = &this->m_rgMoved.m_Memory.m_pMemory[this->m_nBlocker];
    m_pEnt = v7->m_Trace.m_pEnt;
    if ( m_pEnt != nullptr )
      CBaseEntity::PhysicsImpact(this: v7->m_pEntity, other: m_pEnt, trace: &v7->m_Trace);
    pBlocker = v7->m_pEntity;
    CBaseEntity::SetLocalOrigin(this: pRoot, origin: &vecPrevOrigin);
    v9 = this->m_rgMoved.m_Size - 1;
    if ( v9 >= 0 )
    {
      v10 = v9;
      do
      {
        CBaseEntity::SetAbsOrigin(
          this: this->m_rgMoved.m_Memory.m_pMemory[v10].m_pEntity,
          absOrigin: &this->m_rgMoved.m_Memory.m_pMemory[v10].m_vecStartAbsOrigin);
        --v10;
        --v9;
      }
      while ( v9 >= 0 );
    }
    return pBlocker;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195090
// Name: private: class CBaseEntity __near * CBaseEntity::PhysicsPushMove(float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__userpurge CBaseEntity::PhysicsPushMove@<eax>(CBaseEntity *this@<ecx>, int a2@<ebx>, float movetime)
{
  CBaseEntity *result; // eax

  this->m_flLocalTime = movetime + this->m_flLocalTime;
  if ( vec3_origin.x == this->m_vecVelocity.m_Value.x
    && vec3_origin.y == this->m_vecVelocity.m_Value.y
    && vec3_origin.z == this->m_vecVelocity.m_Value.z )
  {
    return nullptr;
  }
  result = CPhysicsPushedEntities::PerformLinearPush(this: g_pPushedEntities, a2, a3: (int)this, pRoot: this, movetime);
  if ( result != nullptr )
    this->m_flLocalTime = this->m_flLocalTime - movetime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10195130
// Name: private: class CBaseEntity __near * CBaseEntity::PhysicsPushRotate(float)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseEntity::PhysicsPushRotate(CBaseEntity *this, float movetime)
{
  CBaseEntity *result; // eax

  this->m_flLocalTime = movetime + this->m_flLocalTime;
  if ( vec3_angle.x == this->m_vecAngVelocity.x
    && vec3_angle.y == this->m_vecAngVelocity.y
    && vec3_angle.z == this->m_vecAngVelocity.z )
  {
    return nullptr;
  }
  result = CPhysicsPushedEntities::PerformRotatePush(this: g_pPushedEntities, pRoot: this, movetime);
  if ( result != nullptr )
    this->m_flLocalTime = this->m_flLocalTime - movetime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101951D0
// Name: private: void CBaseEntity::PerformPush(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PerformPush(CBaseEntity *this, float movetime)
{
  CPhysicsPushedEntities *v2; // eax
  float v3; // xmm0_4
  unsigned int m_Index; // ebx
  CBaseEntity *v6; // edi
  CBaseEntity *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CBaseEntity **v15; // eax
  CBaseEntity *v16; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  unsigned int v18; // eax
  physicspushlist_t *DataObject; // eax
  float m_flMoveDoneTime; // xmm0_4
  float flRotateLocalTime; // [esp+14h] [ebp-8h]
  float flInitialLocalTime; // [esp+18h] [ebp-4h]

  v2 = g_pPushedEntities;
  v3 = movetime;
  m_Index = this->m_pBlocker.m_Index;
  g_pPushedEntities->m_rgMoved.m_Size = 0;
  v2->m_rgPusher.m_Size = 0;
  v2->m_rootPusherStartLocalOrigin = this->m_vecOrigin.m_Value;
  v2->m_rootPusherStartLocalAngles = this->m_angRotation.m_Value;
  v2->m_rootPusherStartLocaltime = this->m_flLocalTime;
  if ( movetime <= 0.0 )
    goto LABEL_34;
  if ( vec3_angle.x == this->m_vecAngVelocity.x
    && vec3_angle.y == this->m_vecAngVelocity.y
    && vec3_angle.z == this->m_vecAngVelocity.z )
  {
    v7 = CBaseEntity::PhysicsPushMove(this, a2: m_Index, movetime);
    goto LABEL_13;
  }
  if ( vec3_origin.x == this->m_vecVelocity.m_Value.x
    && vec3_origin.y == this->m_vecVelocity.m_Value.y
    && vec3_origin.z == this->m_vecVelocity.m_Value.z )
  {
    v7 = CBaseEntity::PhysicsPushRotate(this, movetime);
LABEL_13:
    v6 = v7;
    goto LABEL_14;
  }
  flInitialLocalTime = this->m_flLocalTime;
  v6 = CBaseEntity::PhysicsPushRotate(this, movetime);
  if ( v6 == nullptr )
  {
    flRotateLocalTime = this->m_flLocalTime;
    this->m_flLocalTime = flInitialLocalTime;
    v6 = CBaseEntity::PhysicsPushMove(this, a2: m_Index, movetime);
    if ( flRotateLocalTime > this->m_flLocalTime )
      this->m_flLocalTime = flRotateLocalTime;
LABEL_14:
    if ( v6 == nullptr )
    {
      this->m_pBlocker.m_Index = -1;
      goto LABEL_17;
    }
  }
  this->m_pBlocker.m_Index = v6->GetRefEHandle(this: v6)->m_Index;
LABEL_17:
  if ( this->m_pBlocker.m_Index != m_Index )
  {
    if ( m_Index != -1 )
      this->EndBlocked(this);
    v8 = this->m_pBlocker.m_Index;
    if ( v8 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity != nullptr )
    {
      this->StartBlocked(this, a2: v6);
    }
  }
  v9 = this->m_pBlocker.m_Index;
  if ( v9 != -1 )
  {
    v10 = (unsigned __int16)v9;
    v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v9];
    v12 = HIWORD(v9);
    if ( v11->m_SerialNumber == v12 && v11->m_pEntity != nullptr )
    {
      v13 = v10;
      v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
      v15 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v13];
      if ( v14 )
        v16 = *v15;
      else
        v16 = nullptr;
      this->Blocked(this, a2: v16);
    }
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
  v3 = movetime;
LABEL_34:
  if ( this->m_pPhysicsObject != nullptr )
  {
    if ( v3 > 0.0 )
    {
      v18 = this->m_pBlocker.m_Index;
      if ( (v18 == -1
         || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18)
         || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity == nullptr)
        && this->m_Collision.GetSolid(this: &this->m_Collision) == SOLID_VPHYSICS
        && g_pPushedEntities->m_rgMoved.m_Size > 0 )
      {
        DataObject = (physicspushlist_t *)CBaseEntity::CreateDataObject(this, type: 5);
        if ( DataObject != nullptr )
          CPhysicsPushedEntities::StoreMovedEntities(this: g_pPushedEntities, list: DataObject);
      }
    }
  }
  else
  {
    m_flMoveDoneTime = this->m_flMoveDoneTime;
    if ( this->m_flLocalTime >= m_flMoveDoneTime && m_flMoveDoneTime > 0.0 )
    {
      CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
      this->MoveDone(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101954F0
// Name: private: void CBaseEntity::PhysicsPusher(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsPusher(CBaseEntity *this)
{
  float m_flMoveDoneTime; // xmm0_4
  float m_flLocalTime; // xmm1_4
  float movetime; // xmm0_4

  if ( CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
  {
    m_flMoveDoneTime = this->m_flMoveDoneTime;
    m_flLocalTime = this->m_flLocalTime;
    this->m_flVPhysicsUpdateLocalTime = m_flLocalTime;
    if ( m_flMoveDoneTime < 0.0 )
      movetime = -1.0;
    else
      movetime = m_flMoveDoneTime - m_flLocalTime;
    if ( movetime > gpGlobals->frametime )
      movetime = gpGlobals->frametime;
    CBaseEntity::PerformPush(this, movetime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195550
// Name: private: void CBaseEntity::CheckStepSimulationChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::CheckStepSimulationChanged(CBaseEntity *this)
{
  bool v2; // bl
  edict_t *m_pPev; // ecx
  bool HasDataObjectType; // al

  if ( this->m_bSimulatedEveryTick.m_Value != g_bTestMoveTypeStepSimulation )
  {
    v2 = g_bTestMoveTypeStepSimulation;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1F5u);
    }
    this->m_bSimulatedEveryTick.m_Value = v2;
  }
  HasDataObjectType = CBaseEntity::HasDataObjectType(this, type: 2);
  if ( g_bTestMoveTypeStepSimulation )
  {
    if ( !HasDataObjectType )
      CBaseEntity::CreateDataObject(this, type: 2);
  }
  else if ( HasDataObjectType )
  {
    CBaseEntity::DestroyDataObject(this, type: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101955C0
// Name: private: void CBaseEntity::StepSimulationThink(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::StepSimulationThink(CBaseEntity *this, float dt)
{
  char *DataObject; // eax
  char *v4; // esi
  Vector *v5; // eax
  CBaseAnimating *v6; // eax
  Vector *v7; // eax
  QAngle *v8; // eax
  _BYTE v9[12]; // [esp+14h] [ebp-18h] BYREF
  QAngle stepAngles; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  CBaseEntity::CheckStepSimulationChanged(this);
  DataObject = (char *)CBaseEntity::GetDataObject(this, type: 2);
  v4 = DataObject;
  if ( DataObject != nullptr )
  {
    *(_WORD *)DataObject = 257;
    *((_DWORD *)DataObject + 36) = -1;
    *((_DWORD *)DataObject + 37) = 0;
    *((_DWORD *)DataObject + 38) = 0;
    *((_DWORD *)DataObject + 39) = 0;
    *((_DWORD *)DataObject + 43) = 0;
    *((_DWORD *)DataObject + 44) = 0;
    *((_DWORD *)DataObject + 45) = 0;
    *((_DWORD *)DataObject + 1) = *((_DWORD *)DataObject + 9);
    *((float *)DataObject + 2) = *((float *)DataObject + 10);
    *((float *)DataObject + 3) = *((float *)DataObject + 11);
    *((float *)DataObject + 4) = *((float *)DataObject + 12);
    *(_QWORD *)(DataObject + 20) = *(_QWORD *)(DataObject + 52);
    *(_QWORD *)(DataObject + 28) = *(_QWORD *)(DataObject + 60);
    *((_DWORD *)DataObject + 9) = gpGlobals->tickcount;
    v5 = this->GetStepOrigin(this, result: v9);
    *((float *)v4 + 10) = v5->x;
    *((float *)v4 + 11) = v5->y;
    *((float *)v4 + 12) = v5->z;
    this->GetStepAngles(this, result: &stepAngles);
    AngleQuaternion(angles: &stepAngles, outQuat: (Quaternion *)(v4 + 52));
    CBaseEntity::PhysicsStepRunTimestep(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, timestep: dt);
    CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_BASE_ONLY);
    if ( this->GetBaseAnimating(this) != nullptr )
    {
      v6 = this->GetBaseAnimating(this);
      CBaseAnimating::UpdateStepOrigin(this: v6);
    }
    v7 = this->GetStepOrigin(this, result: v9);
    *((float *)v4 + 26) = v7->x;
    *((float *)v4 + 27) = v7->y;
    *((float *)v4 + 28) = v7->z;
    stepAngles = *this->GetStepAngles(this, result: v9);
    AngleQuaternion(angles: &stepAngles, outQuat: (Quaternion *)(v4 + 116));
    v8 = this->GetStepAngles(this, result: v9);
    *((float *)v4 + 33) = v8->x;
    *((float *)v4 + 34) = v8->y;
    *((float *)v4 + 35) = v8->z;
    *((_DWORD *)v4 + 25) = CBaseEntity::GetNextThinkTick(this, szContext: nullptr);
    if ( CBaseEntity::IsSimulatingOnAlternateTicks() )
      ++*((_DWORD *)v4 + 25);
    if ( dt > 0.0
      && (float)((float)((float)((float)((float)(*((float *)v4 + 26) - *((float *)v4 + 10))
                                       * (float)(*((float *)v4 + 26) - *((float *)v4 + 10)))
                               + (float)((float)(*((float *)v4 + 27) - *((float *)v4 + 11))
                                       * (float)(*((float *)v4 + 27) - *((float *)v4 + 11))))
                       + (float)((float)(*((float *)v4 + 28) - *((float *)v4 + 12))
                               * (float)(*((float *)v4 + 28) - *((float *)v4 + 12))))
               / (float)(dt * dt)) >= 16777216.0 )
    {
      *(_WORD *)v4 = 0;
    }
  }
  else
  {
    CBaseEntity::PhysicsStepRunTimestep(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, timestep: dt);
    CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_BASE_ONLY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195800
// Name: private: void CBaseEntity::PhysicsStep(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::PhysicsStep(CBaseEntity *this)
{
  __int16 v2; // bx
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  float v9; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *v11; // ecx
  float v12; // xmm0_4
  float z; // ecx
  int m_nValue; // eax
  bool startsolid; // bl
  float *DataObject; // edi
  IPhysicsShadowController *v17; // eax
  IPhysicsShadowController *v18; // eax
  IPhysicsObject *m_pPhysicsObject; // edi
  const Vector *AbsOrigin; // eax
  const Vector *v21; // eax
  double LastThink; // st7
  IPhysicsObject *v23; // ebx
  IPhysicsObject_vtbl *v24; // edi
  const Vector *v25; // eax
  const Vector *v26; // [esp+24h] [ebp-8Ch]
  BOOL v27; // [esp+24h] [ebp-8Ch]
  unsigned int dt; // [esp+28h] [ebp-88h]
  float dta; // [esp+28h] [ebp-88h]
  CGameTrace tr; // [esp+38h] [ebp-78h] BYREF
  Vector oldOrigin; // [esp+8Ch] [ebp-24h] BYREF
  Vector position; // [esp+98h] [ebp-18h] BYREF
  int thinktick; // [esp+A4h] [ebp-Ch]
  int maxAngular; // [esp+A8h] [ebp-8h] BYREF
  float thinktime; // [esp+ACh] [ebp-4h]
  int savedregs; // [esp+B0h] [ebp+0h] BYREF

  v2 = (_WORD)this + 700;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: v2 - (_WORD)this);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v5 = this->m_Network.m_pPev;
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: v2 - (_WORD)this + 8);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v6 = this->m_Network.m_pPev;
    if ( v6 != nullptr )
      CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x2C8u);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v7 = this->m_Network.m_pPev;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x2CCu);
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    v8 = this->m_Network.m_pPev;
    if ( v8 != nullptr )
      CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x2D0u);
  }
  m_Value = this->m_flSimulationTime.m_Value;
  thinktime = gpGlobals->curtime;
  v9 = thinktime;
  if ( m_Value != thinktime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x68u);
        v9 = thinktime;
      }
    }
    this->m_flSimulationTime.m_Value = v9;
  }
  CBaseEntity::PhysicsRunThink(this, thinkMethod: THINK_FIRE_ALL_BUT_BASE);
  thinktick = CBaseEntity::GetNextThinkTick(this, szContext: nullptr);
  v12 = (float)thinktick * gpGlobals->interval_per_tick;
  thinktime = v12;
  if ( v12 <= 0.0 || (float)(v12 - gpGlobals->curtime) > 0.5 )
  {
    CBaseEntity::PhysicsStepRunTimestep(
      this,
      a2: COERCE_FLOAT(&savedregs),
      a3: (int)this,
      timestep: gpGlobals->frametime);
    CBaseEntity::PhysicsCheckWaterTransition(this);
    CBaseEntity::SetLastThink(this, nContextIndex: -1, thinkTime: gpGlobals->curtime);
    ((void (__thiscall *)(CBaseEntity *, _DWORD))this->UpdatePhysicsShadowToCurrentPosition)(
      a1: this,
      a2: LODWORD(gpGlobals->frametime));
    CBaseEntity::PhysicsRelinkChildren(this, dt: gpGlobals->frametime);
    return;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&oldOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  oldOrigin.z = z;
  if ( npc_vphysics.m_pParent != nullptr )
    m_nValue = npc_vphysics.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  startsolid = m_nValue != 0;
  if ( CBaseEntity::HasDataObjectType(this, type: 6) )
  {
    DataObject = (float *)CBaseEntity::GetDataObject(this, type: 6);
    if ( DataObject[1] > gpGlobals->curtime )
    {
      startsolid = true;
LABEL_39:
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr && CBaseEntity::GetParent(this) == nullptr )
      {
        m_pPhysicsObject->GetShadowPosition(this: m_pPhysicsObject, a2: &position, a3: nullptr);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        if ( (float)((float)((float)((float)(AbsOrigin->x - position.x) * (float)(AbsOrigin->x - position.x))
                           + (float)((float)(AbsOrigin->y - position.y) * (float)(AbsOrigin->y - position.y)))
                   + (float)((float)(AbsOrigin->z - position.z) * (float)(AbsOrigin->z - position.z))) < 1.0 )
        {
          dt = this->PhysicsSolidMaskForEntity(this);
          v26 = CBaseEntity::GetAbsOrigin(this);
          v21 = CBaseEntity::GetAbsOrigin(this);
          Physics_TraceEntity(pBaseEntity: this, ptr: &tr, vecAbsStart: v21, vecAbsEnd: v26, mask: dt);
          startsolid = tr.startsolid;
        }
        if ( startsolid )
        {
          CBaseEntity::SetAbsOrigin(this, absOrigin: &position);
          CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
        }
      }
      goto LABEL_45;
    }
    v17 = this->m_pPhysicsObject->GetShadowController(this: this->m_pPhysicsObject);
    v17->GetMaxSpeed(this: v17, a2: nullptr, a3: (float *)&maxAngular);
    v18 = this->m_pPhysicsObject->GetShadowController(this: this->m_pPhysicsObject);
    ((void (__thiscall *)(IPhysicsShadowController *, _DWORD, int))v18->MaxSpeed)(
      a1: v18,
      a2: *((_DWORD *)DataObject + 2),
      a3: maxAngular);
    CBaseEntity::DestroyDataObject(this, type: 6);
  }
  if ( startsolid )
    goto LABEL_39;
LABEL_45:
  if ( thinktick <= gpGlobals->tickcount )
  {
    if ( gpGlobals->curtime > thinktime )
      thinktime = gpGlobals->curtime;
    LastThink = CBaseEntity::GetLastThink(this, szContext: nullptr);
    thinktime = thinktime - LastThink;
    CBaseEntity::StepSimulationThink(this, dt: thinktime);
    CBaseEntity::PhysicsCheckWaterTransition(this);
    if ( this->m_pPhysicsObject != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( !VectorCompare(v1: &oldOrigin, v2: &this->m_vecAbsOrigin) )
      {
        v23 = this->m_pPhysicsObject;
        v24 = v23->__vftable;
        dta = thinktime;
        v27 = (this->m_fFlags.m_Value & 0x800) != 0;
        v25 = CBaseEntity::GetAbsOrigin(this);
        v24->UpdateShadow(this: v23, a2: v25, a3: &vec3_angle, a4: v27, a5: COERCE_FLOAT(LODWORD(dta)));
      }
    }
    CBaseEntity::PhysicsRelinkChildren(this, dt: thinktime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10195C10
// Name: protected: void CPhysicsPushedEntities::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPushedEntities::AddEntity(CPhysicsPushedEntities *this, CBaseEntity *ent)
{
  int m_nAllocationCount; // eax
  CUtlMemory<damageevent_t,int> *p_m_rgMoved; // esi
  int m_Size; // edi
  damageevent_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  m_nAllocationCount = this->m_rgMoved.m_Memory.m_nAllocationCount;
  p_m_rgMoved = (CUtlMemory<damageevent_t,int> *)&this->m_rgMoved;
  m_Size = this->m_rgMoved.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<damageevent_t,int>::Grow(this: p_m_rgMoved, num: m_Size - m_nAllocationCount + 1);
  ++p_m_rgMoved[1].m_pMemory;
  m_pMemory = p_m_rgMoved->m_pMemory;
  v6 = (int)p_m_rgMoved[1].m_pMemory - m_Size - 1;
  p_m_rgMoved[1].m_nAllocationCount = (int)p_m_rgMoved->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 104 * v6);
  v7 = m_Size;
  p_m_rgMoved->m_pMemory[v7].pEntity = ent;
  if ( (ent->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: ent, a2: (int)&savedregs);
  *(Vector *)&p_m_rgMoved->m_pMemory[v7].pInflictorPhysics = ent->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10195CB0
// Name: public: virtual enum IterationRetval_t CPushBlockerEnum::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
IterationRetval_t __thiscall CPushBlockerEnum::EnumElement(CPushBlockerEnum *this, IHandleEntity *pHandleEntity)
{
  CBaseEntity *PushableEntity; // eax

  PushableEntity = CPushBlockerEnum::GetPushableEntity(this, pHandleEntity);
  if ( PushableEntity != nullptr )
    CPhysicsPushedEntities::AddEntity(this: this->m_pPushedEntities, ent: PushableEntity);
  return ITERATION_CONTINUE;
}
