// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/hostage/cs_simple_hostage.cpp
// Functions: 65
// ============================================================

#include "game\server\cstrike15\hostage\cs_simple_hostage.h"

//------------------------------------------------------------------------------
// Address: 0x102DB2D0
// Name: public: virtual struct datamap_t __near * CHostage::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CHostage::GetDataDescMap(CHostage *this)
{
  return &CHostage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102DB2E0
// Name: public: virtual class ServerClass __near * CHostage::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CHostage::GetServerClass(CHostage *this)
{
  return &g_CHostage_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102DB2F0
// Name: public: virtual void CHostage::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Precache(CHostage *this)
{
  const char **v2; // esi

  v2 = (const char **)HostageModel;
  do
    CBaseEntity::PrecacheModel(a1: (bool (__cdecl *)(const char *))this, name: *v2++, bPreload: true);
  while ( (int)v2 < (int)&CHostage::m_DataMap );
  CBaseEntity::PrecacheScriptSound(soundname: "Hostage.StartFollowCT");
  CBaseEntity::PrecacheScriptSound(soundname: "Hostage.StopFollowCT");
  CBaseEntity::PrecacheScriptSound(soundname: "Hostage.Pain");
  CBaseCombatCharacter::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DB350
// Name: private: void CHostage::PushawayThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostage::PushawayThink(CHostage *this@<ecx>, IPhysicsObject *a2@<ebp>, int a3@<edi>)
{
  PerformObstaclePushaway(a1: a2, a2: a3, a3: (int)this, pPushingEntity: this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.050000001, szContext: "HostagePushawayThink");
}

//------------------------------------------------------------------------------
// Address: 0x102DB390
// Name: public: virtual void CHostage::PhysicsSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::PhysicsSimulate(CHostage *this)
{
  CBaseEntity::PhysicsSimulate(this);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &this->m_vel);
}

//------------------------------------------------------------------------------
// Address: 0x102DB3B0
// Name: public: void CHostage::GiveCTUseBonus(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::GiveCTUseBonus(CHostage *this, CCSPlayer *rescuer)
{
  CAutoGameSystemPerFrame **p_m_pNext; // esi

  p_m_pNext = &g_pGameRules[134].m_pNext;
  *p_m_pNext = (CAutoGameSystemPerFrame *)((char *)*p_m_pNext
                                         + CCSGameRules::TeamCashAwardValue(
                                             this: (CCSGameRules *)g_pGameRules,
                                             reason: TEAM_CASH_AWARD_HOSTAGE_INTERACTION));
  CCSPlayer::AddAccount(this: rescuer, reason: CASH_AWARD_INTERACT_WITH_HOSTAGE, bTrackChange: true, bItemBought: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DB3E0
// Name: public: virtual class Vector const __near & CHostage::GetCentroid(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CHostage::GetCentroid(CHostage *this)
{
  float *v1; // eax

  if ( (_S4_71 & 1) == 0 )
    _S4_71 |= 1u;
  v1 = (float *)((int (__thiscall *)(CHostage *))this->SetRefEHandle)(a1: this);
  centroid.x = *v1;
  centroid.y = v1[1];
  centroid.z = v1[2] + 35.5;
  return &centroid;
}

//------------------------------------------------------------------------------
// Address: 0x102DB430
// Name: public: virtual class CNavArea __near * CHostage::GetLastKnownArea(void)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CHostage::GetLastKnownArea(CHostage *this)
{
  return this->m_lastKnownArea;
}

//------------------------------------------------------------------------------
// Address: 0x102DB440
// Name: public: virtual bool CHostage::GetSimpleGroundHeightWithFloor(class Vector const __near &,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHostage::GetSimpleGroundHeightWithFloor(
        CHostage *this,
        const Vector *pos,
        float *height,
        Vector *normal)
{
  float z; // ecx
  float v6; // xmm0_4
  float normala; // [esp+24h] [ebp+10h]
  float normalb; // [esp+24h] [ebp+10h]

  if ( !CNavMesh::GetSimpleGroundHeight(this: TheNavMesh, pos, height, normal) )
    return 0;
  z = this->m_path.m_path[166].pos.z;
  if ( z != 0.0 && CNavArea::IsOverlapping(this: (CNavArea *)LODWORD(z), pos, tolerance: 0.0) )
  {
    normala = CNavArea::GetZ(this: (CNavArea *)LODWORD(this->m_path.m_path[166].pos.z), x: pos->x, y: pos->y);
    v6 = *height;
    if ( *height <= normala )
    {
      normalb = CNavArea::GetZ(this: (CNavArea *)LODWORD(this->m_path.m_path[166].pos.z), x: pos->x, y: pos->y);
      v6 = normalb;
    }
    *height = v6;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DB500
// Name: public: virtual void CHostage::Crouch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Crouch(CHostage *this)
{
  BYTE1(this->m_Network.m_hParent.m_Index) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DB510
// Name: public: virtual void CHostage::StandUp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::StandUp(CHostage *this)
{
  BYTE1(this->m_Network.m_hParent.m_Index) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102DB520
// Name: public: virtual bool CHostage::IsCrouching(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHostage::IsCrouching(CHostage *this)
{
  return BYTE1(this->m_Network.m_hParent.m_Index);
}

//------------------------------------------------------------------------------
// Address: 0x102DB530
// Name: public: virtual void CHostage::Run(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Run(CHostage *this)
{
  LOBYTE(this->m_Network.m_hParent.m_Index) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x102DB540
// Name: public: virtual void CHostage::Walk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Walk(CHostage *this)
{
  LOBYTE(this->m_Network.m_hParent.m_Index) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102DB550
// Name: public: virtual bool CHostage::IsRunning(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHostage::IsRunning(CHostage *this)
{
  return this->m_Network.m_hParent.m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x102DB580
// Name: public: float HostagePathCost::operator()(class CNavArea __near *,class CNavArea __near *,class CNavLadder const __near *,class CFuncElevator const __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall HostagePathCost::operator()(
        HostagePathCost *this,
        CNavArea *area,
        CNavArea *fromArea,
        const CNavLadder *ladder,
        const CFuncElevator *elevator,
        float length)
{
  int m_attributeFlags; // ecx
  float v8; // xmm0_4
  float v9; // [esp-20h] [ebp-2Ch]
  float v10; // [esp-4h] [ebp-10h]

  if ( fromArea == nullptr )
    return 0.0;
  m_attributeFlags = area->m_attributeFlags;
  if ( (m_attributeFlags & 0x800) != 0 )
    return -1.0;
  if ( ladder != nullptr )
    return -1.0;
  v8 = area->m_center.x - fromArea->m_center.x;
  v9 = fsqrt(
         (float)((float)((float)(area->m_center.y - fromArea->m_center.y)
                       * (float)(area->m_center.y - fromArea->m_center.y))
               + (float)((float)(area->m_center.z - fromArea->m_center.z)
                       * (float)(area->m_center.z - fromArea->m_center.z)))
       + (float)(v8 * v8));
  v10 = fromArea->m_costSoFar + v9;
  if ( (m_attributeFlags & 1) != 0 )
    return -1.0;
  if ( (m_attributeFlags & 2) != 0 )
    return (float)((float)(v9 * 5.0) + (float)(fromArea->m_costSoFar + v9));
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x102DB650
// Name: private: void CHostage::AvoidPhysicsProps(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostage::AvoidPhysicsProps(CHostage *this@<ecx>, int a2@<edi>)
{
  int v3; // ebx
  int (__thiscall ***v4)(_DWORD); // eax
  int (__thiscall ***v5)(_DWORD); // edi
  double v6; // st7
  float v7; // xmm0_4
  float v8; // xmm0_4
  CBaseEntity *v9; // ecx
  const Vector *(__thiscall *WorldSpaceCenter)(CBaseEntity *); // eax
  float *v11; // edi
  const Vector *v12; // eax
  double v13; // st7
  float v14; // xmm1_4
  float m_fValue; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float x; // xmm0_4
  float y; // xmm0_4
  float v22; // xmm0_4
  float z; // edx
  float v24; // eax
  __int64 v25; // xmm0_8
  float v26; // xmm1_4
  CBaseEntity *props[512]; // [esp+14h] [ebp-884h] BYREF
  CGameTrace trace; // [esp+814h] [ebp-84h] BYREF
  float flDist; // [esp+868h] [ebp-30h]
  Vector vecAbsEnd; // [esp+86Ch] [ebp-2Ch] BYREF
  Vector forward; // [esp+878h] [ebp-20h] BYREF
  float groundFraction; // [esp+884h] [ebp-14h]
  float mass; // [esp+888h] [ebp-10h]
  Vector start; // [esp+88Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+898h] [ebp+0h] BYREF

  if ( this->m_lifeState.m_Value != 2 )
  {
    v3 = 0;
    groundFraction = COERCE_FLOAT(
                       GetPushawayEnts(
                         a1: (int)&savedregs,
                         a2,
                         a3: (int)this,
                         pPushingEntity: this,
                         ents: props,
                         nMaxEnts: 512,
                         flPlayerExpand: 0.0,
                         PartitionMask: 1,
                         enumerator: nullptr));
    if ( SLODWORD(groundFraction) > 0 )
    {
      while ( 1 )
      {
        v4 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                             inptr: props[v3],
                                             VfDelta: 0,
                                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                                             TargetType: &IMultiplayerPhysics `RTTI Type Descriptor',
                                             isReference: 0);
        v5 = v4;
        if ( v4 == nullptr )
          break;
        if ( (**v4)(a1: v4) == 1 )
        {
          v6 = ((double (__thiscall *)(int (__thiscall ***)(_DWORD)))(*v5)[1])(a1: v5);
          mass = v6;
          if ( v6 < 30.0 )
            v7 = mass;
          else
            v7 = 30.0;
          goto LABEL_8;
        }
LABEL_16:
        if ( ++v3 >= SLODWORD(groundFraction) )
          goto LABEL_17;
      }
      v7 = 30.0;
LABEL_8:
      v8 = v7 - 10.0;
      if ( v8 <= 0.0 )
        v8 = 0.0;
      v9 = props[v3];
      WorldSpaceCenter = v9->WorldSpaceCenter;
      mass = v8 * 0.050000001;
      v11 = (float *)WorldSpaceCenter(this: v9);
      v12 = this->WorldSpaceCenter(this);
      start.x = v12->x - *v11;
      start.y = v12->y - v11[1];
      start.z = v12->z - v11[2];
      v13 = VectorNormalize(vec: &start);
      flDist = v13;
      if ( v13 > 1.0 )
        v14 = flDist;
      else
        v14 = 1.0;
      m_fValue = (float)(sv_pushaway_hostage_force.m_pParent->m_Value.m_fValue / v14) * mass;
      if ( sv_pushaway_max_hostage_force.m_pParent->m_Value.m_fValue <= m_fValue )
        m_fValue = sv_pushaway_max_hostage_force.m_pParent->m_Value.m_fValue;
      v16 = start.x * m_fValue;
      v17 = start.y * m_fValue;
      v18 = start.z * m_fValue;
      this->m_accel.x = this->m_accel.x + (float)(start.x * m_fValue);
      this->m_accel.y = this->m_accel.y + v17;
      v19 = this->m_accel.z + v18;
      start.x = v16;
      start.y = v17;
      start.z = v18;
      this->m_accel.z = v19;
      goto LABEL_16;
    }
LABEL_17:
    x = this->m_accel.x;
    if ( x <= -0.0099999998
      || x >= 0.0099999998
      || (y = this->m_accel.y) <= -0.0099999998
      || y >= 0.0099999998
      || (v22 = this->m_accel.z) <= -0.0099999998
      || v22 >= 0.0099999998 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = this->m_vecAbsOrigin.z;
      v24 = this->m_accel.z;
      *(_QWORD *)&start.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      v25 = *(_QWORD *)&this->m_accel.x;
      start.z = z;
      *(_QWORD *)&forward.x = v25;
      forward.z = v24;
      VectorNormalize(vec: &forward);
      vecAbsEnd.x = forward.x + start.x;
      vecAbsEnd.y = forward.y + start.y;
      vecAbsEnd.z = forward.z + start.z;
      UTIL_TraceEntity(
        pEntity: this,
        vecAbsStart: &start,
        &vecAbsEnd,
        mask: 0x201400Bu,
        pIgnore: this,
        nCollisionGroup: 5,
        ptr: &trace);
      if ( !trace.startsolid && trace.fraction < 1.0 && trace.plane.normal.z < 0.69999999 )
      {
        vecAbsEnd.x = forward.x + start.x;
        groundFraction = trace.fraction;
        vecAbsEnd.y = forward.y + start.y;
        v26 = forward.z + (float)(start.z + 18.0);
        start.z = start.z + 18.0;
        vecAbsEnd.z = v26;
        UTIL_TraceEntity(
          pEntity: this,
          vecAbsStart: &start,
          &vecAbsEnd,
          mask: 0x201400Bu,
          pIgnore: this,
          nCollisionGroup: 5,
          ptr: &trace);
        if ( !trace.startsolid && trace.fraction > groundFraction )
          CBaseEntity::SetAbsOrigin(this, absOrigin: &start);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DB9C0
// Name: public: bool CHostage::IsFollowing(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHostage::IsFollowing(CHostage *this, const CBaseEntity *entity)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return entity == nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == entity;
}

//------------------------------------------------------------------------------
// Address: 0x102DBA10
// Name: public: bool CHostage::IsRescued(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHostage::IsRescued(CHostage *this)
{
  return this->m_isRescued.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102DBA20
// Name: public: class CCSPlayer __near * CHostage::GetLeader(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CHostage::GetLeader(CHostage *this)
{
  unsigned int m_Index; // eax
  CEntInfo *v2; // ecx
  IHandleEntity *m_pEntity; // esi

  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index != -1
    && (v2 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v2->m_pEntity, v2->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v2->m_pEntity) != 0 )
  {
    return (CCSPlayer *)__RTDynamicCast(
                          inptr: m_pEntity,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DBA80
// Name: public: void CHostage::FaceTowards(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::FaceTowards(CHostage *this, const Vector *target, float deltaT)
{
  const Vector *v4; // eax
  float z; // eax
  QAngle desiredAngles; // [esp+10h] [ebp-24h] BYREF
  Vector to; // [esp+1Ch] [ebp-18h] BYREF
  QAngle angles; // [esp+28h] [ebp-Ch] BYREF
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v4 = this->GetFeet(this: &this->CImprovLocomotor);
  to.x = target->x - v4->x;
  to.y = target->y - v4->y;
  to.z = 0.0;
  VectorAngles(forward: &to, angles: &desiredAngles);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_angAbsRotation.z;
  *(_QWORD *)&angles.x = *(_QWORD *)&this->m_angAbsRotation.x;
  angles.z = z;
  angles.y = ApproachAngle(target: desiredAngles.y, value: angles.y, speed: deltaT * 250.0);
  CBaseEntity::SetAbsAngles(this, absAngles: &angles);
}

//------------------------------------------------------------------------------
// Address: 0x102DBB50
// Name: public: virtual class Vector const __near & CHostage::GetFeet(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CHostage::GetFeet@<eax>(CHostage *this@<ecx>, int a2@<ebp>)
{
  char *v2; // esi

  if ( (_S5_39 & 1) == 0 )
    _S5_39 |= 1u;
  v2 = (char *)this - 2284;
  if ( (*(&this->m_iEFlags - 571) & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v2, a2);
  feet = *(Vector *)(v2 + 460);
  return &feet;
}

//------------------------------------------------------------------------------
// Address: 0x102DBBC0
// Name: public: virtual class Vector const __near & CHostage::GetEyes(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CHostage::GetEyes(CHostage *this)
{
  Vector v2; // [esp+0h] [ebp-Ch] BYREF

  if ( (_S6_30 & 1) == 0 )
    _S6_30 |= 1u;
  (*(void (__thiscall **)(char *, Vector *))(*((_DWORD *)this - 571) + 504))(a1: (char *)this - 2284, a2: &v2);
  eyes = v2;
  return &eyes;
}

//------------------------------------------------------------------------------
// Address: 0x102DBC30
// Name: public: virtual float CHostage::GetMoveAngle(void)const
// Source: json
//------------------------------------------------------------------------------
double __usercall CHostage::GetMoveAngle@<st0>(CHostage *this@<ecx>, int a2@<ebp>)
{
  float *v2; // esi

  v2 = (float *)((char *)this - 2284);
  if ( (*((_DWORD *)this - 522) & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: (CHostage *)((char *)this - 2284), a2);
  return v2[119];
}

//------------------------------------------------------------------------------
// Address: 0x102DC370
// Name: public: virtual int CHostage::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CHostage::OnTakeDamage_Alive@<eax>(CHostage *this@<ecx>, int a2@<edi>, const CTakeDamageInfo *info)
{
  CHostage *v3; // ebx
  unsigned int m_Index; // eax
  CEntInfo *v5; // ecx
  IHandleEntity *m_pEntity; // esi
  CCSPlayer *v7; // eax
  CCSPlayer *v8; // edi
  IGameEvent *v9; // esi
  int v10; // eax
  float actualDamage; // [esp+14h] [ebp-4h]

  actualDamage = info->m_flDamage;
  v3 = this;
  CBaseEntity::EmitSound(this, soundname: "Hostage.Pain", soundtime: 0.0, duration: nullptr);
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1 )
  {
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v5->m_pEntity;
      if ( v5->m_pEntity != nullptr
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v5->m_pEntity) != 0 )
      {
        v7 = (CCSPlayer *)__RTDynamicCast(
                            inptr: m_pEntity,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        v8 = v7;
        if ( v7 != nullptr )
        {
          v7->m_bInjuredAHostage = true;
          LOBYTE(g_pGameRules[141].__vftable) = 1;
          CCSGameRules::ScoreHostageDamage(this: (CCSGameRules *)g_pGameRules, pPlayer: v7, fDamage: actualDamage);
          if ( (v8->m_iDisplayHistoryBits & 0x20) == 0 )
          {
            CCSPlayer::HintMessage(
              this: v8,
              pMessage: "#Hint_careful_around_hostages",
              bDisplayIfDead: false,
              bOverrideClientSettings: false);
            v8->m_iDisplayHistoryBits |= 0x20u;
          }
          v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_hurt", a3: 0, a4: 0);
          if ( v9 != nullptr )
          {
            v10 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                    a1: engine,
                    a2: v8->m_Network.m_pPev,
                    a3: a2);
            v9->SetInt(this: v9, a2: "userid", a3: v10);
            ((void (__thiscall *)(IGameEvent *, const char *))v9->SetInt)(a1: v9, a2: "hostage");
            v9->SetInt(this: v9, a2: "priority", a3: 5);
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v9, a3: false);
          }
          CCSPlayer::AddAccount(this: v8, amount: -20 * (int)actualDamage, bTrackChange: true, bItemBought: false);
          v3 = this;
        }
      }
    }
  }
  return CBaseCombatCharacter::OnTakeDamage_Alive(this: v3, info);
}

//------------------------------------------------------------------------------
// Address: 0x102DC510
// Name: public: virtual void CHostage::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::TraceAttack(
        CHostage *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  IPredictionSystem *i; // eax
  float z; // xmm2_4
  float v7; // xmm0_4
  CBaseEntity *m_pEnt; // esi
  float y; // xmm1_4
  float v10; // xmm0_4
  edict_t *m_pPev; // esi
  IPredictionSystem *j; // eax
  CEffectData data; // [esp+1Ch] [ebp-68h] BYREF
  CBaseEntity *v14; // [esp+80h] [ebp-4h]

  v14 = this;
  CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&data.m_vOrigin.z, __that: info);
  if ( this->m_takedamage.m_Value != 0 )
  {
    for ( i = IPredictionSystem::g_pPredictionSystems; i != nullptr; i = i->m_pNextSystem )
      ++i->m_nStatusPushed;
    AddMultiDamage(info, pEntity: this);
    CBaseEntity::TraceBleed(this: v14, flDamage: info->m_flDamage, vecDir, ptr, bitsDamageType: info->m_bitsDamageType);
    z = vecDir->z;
    memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
    memset((void *)&data.m_vAngles, 0, 20);
    memset(&data.m_flMagnitude, 0, 14);
    data.m_vOrigin.x = ptr->endpos.x;
    data.m_vOrigin.y = ptr->endpos.y;
    v7 = ptr->endpos.z;
    m_pEnt = ptr->m_pEnt;
    data.m_flScale = 1.0;
    y = vecDir->y;
    data.m_vOrigin.z = v7;
    v10 = vecDir->x * -1.0;
    memset(&data.m_nMaterial, 0, 17);
    data.m_vNormal.x = v10;
    data.m_vNormal.y = y * -1.0;
    data.m_vNormal.z = z * -1.0;
    if ( m_pEnt != nullptr )
    {
      m_pPev = m_pEnt->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        data.m_nEntIndex = m_pPev - gpGlobals->pEdicts;
      else
        data.m_nEntIndex = 0;
    }
    else
    {
      data.m_nEntIndex = 0;
    }
    data.m_flMagnitude = info->m_flDamage;
    DispatchEffect(pName: "csblood", &data);
    for ( j = IPredictionSystem::g_pPredictionSystems; j != nullptr; j = j->m_pNextSystem )
      --j->m_nStatusPushed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DC690
// Name: public: void CHostage::CheckForHostageAbuse(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::CheckForHostageAbuse(CHostage *this, CCSPlayer *player)
{
  int m_nValue; // eax
  int v3; // ecx
  const char *v4; // eax
  int v5; // eax
  IVEngineServer_vtbl *v6; // esi
  char *v7; // eax

  if ( mp_hostagepenalty.m_pParent != nullptr )
  {
    m_nValue = mp_hostagepenalty.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      v3 = ++player->m_iHostagesKilled;
      if ( v3 == m_nValue - 1 )
      {
        CCSPlayer::HintMessage(
          this: player,
          pMessage: "#Hint_removed_for_next_hostage_killed",
          bDisplayIfDead: true,
          bOverrideClientSettings: false);
      }
      else if ( v3 >= m_nValue )
      {
        v4 = player->GetPlayerName(this: player);
        _Msg(a1: "Kicking client \"%s\" for killing too many hostages\n", v4);
        v5 = engine->GetPlayerUserId(this: engine, a2: player->m_Network.m_pPev);
        v6 = engine->__vftable;
        v7 = UTIL_VarArgs(format: "kickid %d \"For killing too many hostages\"\n", v5);
        v6->ServerCommand(this: engine, a2: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DC740
// Name: public: virtual void CHostage::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Event_Killed(CHostage *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // esi
  CCSPlayer *v6; // eax
  CCSPlayer *v7; // esi
  IGameEvent *v8; // edi
  int v9; // eax
  edict_t *m_pPev; // eax

  CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules);
  BYTE1(g_pGameRules[141].__vftable) = 1;
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1
    && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v4->m_pEntity, v4->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v4->m_pEntity) != 0 )
  {
    v6 = (CCSPlayer *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    v7 = v6;
    if ( v6 != nullptr )
    {
      CCSGameRules::ScoreHostageKilled(this: (CCSGameRules *)g_pGameRules, pPlayer: v6);
      if ( (v7->m_iDisplayHistoryBits & 0x40) == 0 )
      {
        CCSPlayer::HintMessage(
          this: v7,
          pMessage: "#Hint_lost_money",
          bDisplayIfDead: false,
          bOverrideClientSettings: false);
        v7->m_iDisplayHistoryBits |= 0x40u;
      }
      CCSPlayer::AddAccount(
        this: v7,
        amount: 20 * (-25 - (int)info->m_flDamage),
        bTrackChange: true,
        bItemBought: false);
      if ( CBaseEntity::GetTeamNumber(this: v7) == 2 )
        CHostage::CheckForHostageAbuse(this, player: v7);
    }
  }
  else
  {
    v7 = nullptr;
  }
  this->m_lastLeaderID = 0;
  this->m_pfnUse = nullptr;
  CBaseCombatCharacter::Event_Killed(this, info);
  v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_killed", a3: 0, a4: 0);
  if ( v8 != nullptr )
  {
    if ( v7 != nullptr )
      v9 = engine->GetPlayerUserId(this: engine, a2: v7->m_Network.m_pPev);
    else
      v9 = 0;
    v8->SetInt(this: v8, a2: "userid", a3: v9);
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v8->SetInt(this: v8, a2: "hostage", a3: (int)m_pPev);
    v8->SetInt(this: v8, a2: "priority", a3: 6);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DC8D0
// Name: public: bool CHostage::IsFollowingSomeone(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHostage::IsFollowingSomeone(CHostage *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_leader.m_Value.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102DC910
// Name: public: bool CHostage::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHostage::IsValid(CHostage *this)
{
  return this->m_iHealth.m_Value > 0 && !this->m_isRescued.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102DC930
// Name: public: virtual bool CHostage::IsJumping(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHostage::IsJumping(CHostage *this)
{
  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_Network.m_TimerEvent) <= this->m_Network.m_TimerEvent.m_flUpdateInterval;
}

//------------------------------------------------------------------------------
// Address: 0x102DC960
// Name: public: virtual void CHostage::TrackPath(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::TrackPath(CHostage *this, const Vector *pathGoal, float deltaT)
{
  int v4; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm3_4
  float *v9; // eax
  float v10; // xmm3_4
  float v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  QAngle angles; // [esp+Ch] [ebp-18h] BYREF
  Vector to; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v4 = *((_DWORD *)this - 522) >> 11;
  x = this->m_Network.m_PVSInfo.m_vCenter[0] * 10.0;
  y = this->m_Network.m_PVSInfo.m_vCenter[1] * 10.0;
  z = this->m_Network.m_PVSInfo.m_vCenter[2] * 10.0;
  to.x = x;
  to.y = y;
  to.z = z;
  if ( (v4 & 1) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: (CHostage *)((char *)this - 2284), a2: (int)&savedregs);
    z = to.z;
    y = to.y;
    x = to.x;
  }
  v8 = *((float *)this - 456) + x;
  to.y = *((float *)this - 455) + y;
  to.z = *((float *)this - 454) + z;
  to.x = v8;
  CHostage::FaceTowards(this: (CHostage *)((char *)this - 2284), target: &to, deltaT);
  if ( (*((_BYTE *)this - 2084) & 1) != 0 )
  {
    v9 = (float *)((int (__thiscall *)(CHostage *))this->SetRefEHandle)(a1: this);
    to.x = pathGoal->x - *v9;
    to.y = pathGoal->y - v9[1];
    to.z = 0.0;
    VectorNormalize(vec: &to);
    v10 = 1000.0;
  }
  else
  {
    if ( (*((_DWORD *)this - 522) & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: (CHostage *)((char *)this - 2284), a2: (int)&savedregs);
    v11 = *((float *)this - 451);
    *(_QWORD *)&angles.x = *(_QWORD *)((char *)this - 1812);
    angles.z = v11;
    AngleVectors(&angles, forward: &to);
    v10 = 350.0;
  }
  v12 = (float)(to.y * v10) + *(float *)&this->m_Network.m_PVSInfo.m_pClustersInline[2];
  v13 = (float)(to.x * v10) + *(float *)this->m_Network.m_PVSInfo.m_pClustersInline;
  *(float *)&this->m_Network.m_pServerClass = (float)(to.z * v10) + *(float *)&this->m_Network.m_pServerClass;
  *(float *)&this->m_Network.m_PVSInfo.m_pClustersInline[2] = v12;
  *(float *)this->m_Network.m_PVSInfo.m_pClustersInline = v13;
}

//------------------------------------------------------------------------------
// Address: 0x102DCD10
// Name: public: virtual void CHostage::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Touch(CHostage *this, CBaseEntity *other)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  Vector to; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  CBaseEntity::Touch(this, pOther: other);
  if ( other->IsPlayer(this: other) && CBaseEntity::GetTeamNumber(this: other) == 3
    || other->m_iClassname.pszValue == "hostage_entity"
    || CBaseEntity::ClassMatchesComplex(this: other, pszClassOrWildcard: "hostage_entity") != 0 )
  {
    if ( (other->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: other, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    to.x = this->m_vecAbsOrigin.x - other->m_vecAbsOrigin.x;
    to.y = this->m_vecAbsOrigin.y - other->m_vecAbsOrigin.y;
    to.z = 0.0;
    VectorNormalize(vec: &to);
    v3 = to.z * 500.0;
    v4 = this->m_accel.x + (float)(to.x * 500.0);
    this->m_accel.y = this->m_accel.y + (float)(to.y * 500.0);
    v5 = this->m_accel.z + v3;
    this->m_accel.x = v4;
    this->m_accel.z = v5;
  }
  else if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_inhibitDoorTimer) > this->m_inhibitDoorTimer.m_timestamp.m_Value
         && (other->m_iClassname.pszValue == "func_door*"
          || CBaseEntity::ClassMatchesComplex(this: other, pszClassOrWildcard: "func_door*") != 0
          || other->m_iClassname.pszValue == "prop_door*"
          || CBaseEntity::ClassMatchesComplex(this: other, pszClassOrWildcard: "prop_door*") != 0) )
  {
    CountdownTimer::Start(this: &this->m_inhibitDoorTimer, duration: 3.0);
    ((void (__thiscall *)(CBaseEntity *, CHostage *, CHostage *, int, _DWORD))other->Use)(
      a1: other,
      a2: this,
      a3: this,
      a4: 3,
      a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DCEC0
// Name: private: void CHostage::Wiggle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Wiggle(CHostage *this)
{
  CountdownTimer *p_m_wiggleTimer; // edi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  double v6; // st7
  void (__thiscall *NetworkStateChanged)(CountdownTimer *, void *); // edx
  float m_Value; // xmm0_4
  float *p_m_Value; // edi
  float x; // xmm0_4
  float v11; // xmm3_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  Vector dir; // [esp+Ch] [ebp-20h] BYREF
  Vector lat; // [esp+18h] [ebp-14h] BYREF
  float v19; // [esp+24h] [ebp-8h]
  float v20; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  p_m_wiggleTimer = &this->m_wiggleTimer;
  p_m_timestamp = &this->m_wiggleTimer.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_wiggleTimer) > this->m_wiggleTimer.m_timestamp.m_Value )
  {
    this->m_wiggleDirection = _RandomInt(this: v4, a2: 0, a3: 3);
    v20 = _RandomFloat(this: v5, a2: 0.30000001, a3: 0.5);
    v6 = IntervalTimer::Now(this: (CEffectsServer *)p_m_wiggleTimer) + v20;
    v19 = v6;
    if ( p_m_timestamp->m_Value != v6 )
    {
      NetworkStateChanged = p_m_wiggleTimer->NetworkStateChanged;
      LODWORD(dir.x) = &p_m_wiggleTimer->m_timestamp;
      ((void (__thiscall *)(CountdownTimer *))NetworkStateChanged)(a1: p_m_wiggleTimer);
      p_m_timestamp->m_Value = v19;
    }
    m_Value = p_m_wiggleTimer->m_duration.m_Value;
    p_m_Value = &p_m_wiggleTimer->m_duration.m_Value;
    if ( m_Value != v20 )
    {
      (**((void (__thiscall ***)(int, float *))p_m_Value - 1))(a1: (int)(p_m_Value - 1), a2: p_m_Value);
      *p_m_Value = v20;
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &dir, right: &lat, up: nullptr);
  switch ( this->m_wiggleDirection )
  {
    case 0:
      x = dir.x;
      v11 = 500.0;
      y = dir.y;
      z = dir.z;
      goto LABEL_14;
    case 1:
      x = lat.x;
      y = lat.y;
      z = lat.z;
      goto LABEL_13;
    case 2:
      x = dir.x;
      y = dir.y;
      z = dir.z;
LABEL_13:
      v11 = -500.0;
      goto LABEL_14;
    case 3:
      x = lat.x;
      v11 = 500.0;
      y = lat.y;
      z = lat.z;
LABEL_14:
      v14 = y * v11;
      v15 = z * v11;
      v16 = this->m_accel.x + (float)(x * v11);
      this->m_accel.y = this->m_accel.y + v14;
      this->m_accel.z = this->m_accel.z + v15;
      this->m_accel.x = v16;
      break;
    default:
      break;
  }
  if ( this->m_pathFollower.m_stuckMonitor.m_isStuck
    && (this->m_pathFollower.m_stuckMonitor.m_stuckTimer.m_timestamp.m_Value <= 0.0
     || (v19 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_pathFollower.m_stuckMonitor.m_stuckTimer)
             - this->m_pathFollower.m_stuckMonitor.m_stuckTimer.m_timestamp.m_Value) > 0.25) )
  {
    this->Jump(this: &this->CImprovLocomotor);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD0C0
// Name: public: virtual void CHostage::Jump(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Jump(CHostage *this)
{
  __int64 v2; // xmm0_8
  Vector vel; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_Network.m_TimerEvent) > this->m_Network.m_TimerEvent.m_flUpdateInterval
    && (*((_BYTE *)this - 2084) & 1) != 0 )
  {
    CountdownTimer::Start(this: (CountdownTimer *)&this->m_Network.m_TimerEvent, duration: 0.5);
    if ( (*((_DWORD *)this - 522) & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: (CHostage *)((char *)this - 2284), a2: (int)&savedregs);
    v2 = *((_QWORD *)this - 240);
    vel.z = *((float *)this - 478);
    *(_QWORD *)&vel.x = v2;
    vel.z = vel.z + 200.0;
    CBaseEntity::SetAbsVelocity(this: (CHostage *)((char *)this - 2284), vecAbsVelocity: &vel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD170
// Name: private: virtual void CHostage::NetworkStateChanged_m_iMaxHealth(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::NetworkStateChanged_m_iMaxHealth(CAI_BaseNPC *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      m_pPev->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: &m_pPev->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD1A0
// Name: public: void CHostage::Idle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Idle(CHostage *this)
{
  CNetworkVarBase<CHandle<CBaseEntity>,CHostage::NetworkVar_m_leader> *p_m_leader; // esi
  IHandleEntity *m_pEntity; // edi
  unsigned int m_Index; // ecx
  IHandleEntity *v4; // eax
  CNetworkVarBase<CHandle<CBaseEntity>,CHostage::NetworkVar_m_leader> *v5; // eax
  CBaseEdict *v6; // ecx

  p_m_leader = &this->m_leader;
  if ( g_pEntityList->m_EntPtrArray[0].m_SerialNumber != 0 )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[0].m_pEntity;
  m_Index = p_m_leader->m_Value.m_Index;
  if ( p_m_leader->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    v4 = nullptr;
  }
  else
  {
    v4 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( v4 != m_pEntity )
  {
    v5 = p_m_leader - 575;
    if ( LOBYTE(p_m_leader[-554].m_Value.m_Index) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
      p_m_leader->m_Value.m_Index = 0;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x8FCu);
      p_m_leader->m_Value.m_Index = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD220
// Name: public: void CHostage::Follow(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Follow(CHostage *this, CCSPlayer *leader)
{
  CHostage *v2; // ebx
  unsigned int m_Index; // edi
  IHandleEntity *m_pEntity; // edx
  unsigned int v5; // eax
  IHandleEntity *v6; // ecx
  CBaseEdict *v7; // ecx

  v2 = this;
  if ( leader == nullptr )
  {
    m_Index = -1;
LABEL_6:
    m_pEntity = nullptr;
    goto LABEL_7;
  }
  ++leader->m_iNumFollowers;
  leader->m_bIsRescuing = true;
  m_Index = leader->GetRefEHandle(this: leader)->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    goto LABEL_6;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
LABEL_7:
  v5 = v2->m_leader.m_Value.m_Index;
  if ( v5 == -1 || (v2 = this, g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)) )
    v6 = nullptr;
  else
    v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
  if ( v6 != m_pEntity )
  {
    if ( v2->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v2->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = &v2->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x8FCu);
    }
    v2->m_leader.m_Value.m_Index = m_Index;
    v2 = this;
  }
  v2->m_isWaitingForLeader = false;
  if ( leader != nullptr )
    v2->m_lastLeaderID = engine->GetPlayerUserId(this: engine, a2: leader->m_Network.m_pPev);
  else
    v2->m_lastLeaderID = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102DD320
// Name: protected: virtual void CHostage::HostageUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::HostageUse(
        CHostage *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CCSPlayer *v6; // ebx
  unsigned int v7; // eax
  CCSPlayer *Leader; // eax
  CountdownTimer *p_m_reuseTimer; // esi
  IGameEvent *v10; // eax
  IGameEvent *v11; // esi
  int UserID; // eax
  edict_t *v13; // eax
  unsigned int m_iDisplayHistoryBits; // eax
  IGameEvent_vtbl *v15; // [esp+3Ch] [ebp-4h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (pActivator->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pActivator, a2: (int)&savedregs);
  if ( (float)((float)((float)((float)(pActivator->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x)
                             * (float)(pActivator->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x))
                     + (float)((float)(pActivator->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                             * (float)(pActivator->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)))
             + (float)((float)(pActivator->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                     * (float)(pActivator->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z))) <= 1000000.0
    && pActivator->IsPlayer(this: pActivator) )
  {
    v6 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pActivator,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v6 != nullptr )
    {
      if ( hostage_debug.m_pParent != nullptr && hostage_debug.m_pParent->m_Value.m_nValue != 0
        || CBaseEntity::GetTeamNumber(this: v6) == 3 )
      {
        Leader = CHostage::GetLeader(this);
        if ( Leader != nullptr && !Leader->IsAlive(this: Leader) )
          CHostage::Idle(this);
        p_m_reuseTimer = &this->m_reuseTimer;
        if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_reuseTimer) > this->m_reuseTimer.m_timestamp.m_Value )
        {
          if ( !this->m_hasBeenUsed )
          {
            this->m_hasBeenUsed = true;
            CHostage::GiveCTUseBonus(this, rescuer: v6);
            CCSGameRules::HostageTouched(this: (CCSGameRules *)g_pGameRules);
          }
          if ( CHostage::IsFollowing(this, entity: v6) )
          {
            CHostage::Idle(this);
            CBaseEntity::EmitSound(this, soundname: "Hostage.StopFollowCT", soundtime: 0.0, duration: nullptr);
          }
          else
          {
            if ( CHostage::IsFollowingSomeone(this) )
              return;
            CHostage::Follow(this, leader: v6);
            CBaseEntity::EmitSound(this, soundname: "Hostage.StartFollowCT", soundtime: 0.0, duration: nullptr);
            v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_follows", a3: 0, a4: 0);
            v11 = v10;
            if ( v10 != nullptr )
            {
              v15 = v10->__vftable;
              UserID = CBasePlayer::GetUserID(this: v6);
              v15->SetInt(this: v11, a2: "userid", a3: UserID);
              v13 = CBaseEntity::entindex(this);
              v11->SetInt(this: v11, a2: "hostage", a3: (int)v13);
              v11->SetInt(this: v11, a2: "priority", a3: 6);
              gameeventmanager->FireEvent(this: gameeventmanager, a2: v11, a3: false);
            }
            m_iDisplayHistoryBits = v6->m_iDisplayHistoryBits;
            if ( (m_iDisplayHistoryBits & 0x10) == 0 )
            {
              v6->m_iDisplayHistoryBits = m_iDisplayHistoryBits | 0x10;
              CCSPlayer::HintMessage(
                this: v6,
                pMessage: "#Hint_lead_hostage_to_rescue_point",
                bDisplayIfDead: false,
                bOverrideClientSettings: false);
            }
            p_m_reuseTimer = &this->m_reuseTimer;
          }
          CountdownTimer::Start(this: p_m_reuseTimer, duration: 1.0);
        }
      }
      else if ( CBaseEntity::GetTeamNumber(this: v6) == 2 )
      {
        v7 = v6->m_iDisplayHistoryBits;
        if ( (v7 & 0x200000) == 0 )
        {
          v6->m_iDisplayHistoryBits = v7 | 0x200000;
          CCSPlayer::HintMessage(
            this: v6,
            pMessage: "#Only_CT_Can_Move_Hostages",
            bDisplayIfDead: false,
            bOverrideClientSettings: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DD5B0
// Name: public: CHostage::CHostage(void)
// Source: json
//------------------------------------------------------------------------------
CHostage *__thiscall CHostage::CHostage(CHostage *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx
  CountdownTimer_vtbl *v9; // edx
  CountdownTimer_vtbl *v10; // edx
  CountdownTimer_vtbl *v11; // edx
  CountdownTimer_vtbl *v12; // edx
  CountdownTimer_vtbl *v13; // edx
  int m_Size; // eax
  int v15; // edi
  CHostage **m_pMemory; // ecx
  int v17; // eax
  CHostage **v18; // edi

  CBaseCombatCharacter::CBaseCombatCharacter(this);
  this->CImprovLocomotor::__vftable = (CImprovLocomotor_vtbl *)&CImprovLocomotor::`vftable';
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&ICSPlayerAnimStateHelpers::`vftable';
  this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CHostage_vtbl *)&CHostage::`vftable'{for `CBaseCombatCharacter'};
  this->CImprovLocomotor::__vftable = (CImprovLocomotor_vtbl *)&CHostage::`vftable'{for `CImprovLocomotor'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CHostage::`vftable'{for `ICSPlayerAnimStateHelpers'};
  this->m_leader.m_Value.m_Index = -1;
  this->m_reuseTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_reuseTimer.__vftable;
  this->m_reuseTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_reuseTimer.m_duration);
  v3 = this->m_reuseTimer.__vftable;
  this->m_reuseTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_reuseTimer, a2: &this->m_reuseTimer.m_timestamp);
  this->m_jumpTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_jumpTimer.__vftable;
  this->m_jumpTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_jumpTimer.m_duration);
  v5 = this->m_jumpTimer.__vftable;
  this->m_jumpTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_jumpTimer, a2: &this->m_jumpTimer.m_timestamp);
  this->m_path.m_segmentCount = 0;
  this->m_repathTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_repathTimer.__vftable;
  this->m_repathTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_repathTimer.m_duration);
  v7 = this->m_repathTimer.__vftable;
  this->m_repathTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
  this->m_inhibitDoorTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v8 = this->m_inhibitDoorTimer.__vftable;
  this->m_inhibitDoorTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v8->NetworkStateChanged)(a1: &this->m_inhibitDoorTimer.m_duration);
  v9 = this->m_inhibitDoorTimer.__vftable;
  this->m_inhibitDoorTimer.m_timestamp.m_Value = -1.0;
  v9->NetworkStateChanged(this: &this->m_inhibitDoorTimer, a2: &this->m_inhibitDoorTimer.m_timestamp);
  CNavPathFollower::CNavPathFollower(this: &this->m_pathFollower);
  this->m_inhibitObstacleAvoidanceTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v10 = this->m_inhibitObstacleAvoidanceTimer.__vftable;
  this->m_inhibitObstacleAvoidanceTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v10->NetworkStateChanged)(a1: &this->m_inhibitObstacleAvoidanceTimer.m_duration);
  v11 = this->m_inhibitObstacleAvoidanceTimer.__vftable;
  this->m_inhibitObstacleAvoidanceTimer.m_timestamp.m_Value = -1.0;
  v11->NetworkStateChanged(
    this: &this->m_inhibitObstacleAvoidanceTimer,
    a2: &this->m_inhibitObstacleAvoidanceTimer.m_timestamp);
  this->m_wiggleTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v12 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v12->NetworkStateChanged)(a1: &this->m_wiggleTimer.m_duration);
  v13 = this->m_wiggleTimer.__vftable;
  this->m_wiggleTimer.m_timestamp.m_Value = -1.0;
  v13->NetworkStateChanged(this: &this->m_wiggleTimer, a2: &this->m_wiggleTimer.m_timestamp);
  m_Size = g_Hostages.m_Size;
  v15 = g_Hostages.m_Size;
  if ( g_Hostages.m_Size + 1 > g_Hostages.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Hostages,
      num: g_Hostages.m_Size - g_Hostages.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Hostages.m_Size;
  }
  m_pMemory = g_Hostages.m_Memory.m_pMemory;
  g_Hostages.m_Size = m_Size + 1;
  v17 = m_Size - v15;
  g_Hostages.m_pElements = g_Hostages.m_Memory.m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(dest: &g_Hostages.m_Memory.m_pMemory[v15 + 1], src: &g_Hostages.m_Memory.m_pMemory[v15], count: 4 * v17);
    m_pMemory = g_Hostages.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v15];
  if ( v18 != nullptr )
    *v18 = this;
  this->m_PlayerAnimState = CreateHostageAnimState(
                              pEntity: this,
                              pHelpers: &this->ICSPlayerAnimStateHelpers,
                              legAnimType: LEGANIM_8WAY,
                              bUseAimSequences: false);
  CBaseAnimating::UseClientSideAnimation(this);
  CBaseCombatCharacter::SetBloodColor(this, nBloodColor: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DD870
// Name: public: void CHostage::HostageRescueZoneTouch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHostage::HostageRescueZoneTouch(CHostage *this@<ecx>, int a2@<edi>, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  CCSPlayer *Leader; // eax
  CCSPlayer *v6; // edi
  IGameEvent *v7; // esi
  int v8; // eax
  CGameRules *v9; // esi
  CAutoGameSystemPerFrame *m_pNext; // eax
  CAutoGameSystemPerFrame *v11; // eax
  IHandleEntity *m_pEntity; // ecx
  bool v13; // bl
  double v14; // st7
  int v15; // eax
  CHostage *v16; // ecx
  CGlobalVars *v17; // esi
  float v20; // [esp+Ch] [ebp-4h]

  if ( !this->m_isRescued.m_Value )
  {
    if ( !this->m_isRescued.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x8F8u);
      }
      this->m_isRescued.m_Value = true;
    }
    this->m_lastLeaderID = 0;
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0);
    this->m_disappearTime = gpGlobals->curtime + 3.0;
    this->m_pfnUse = nullptr;
    if ( this->m_takedamage.m_Value != 0 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 0;
    }
    Leader = CHostage::GetLeader(this);
    v6 = Leader;
    if ( Leader != nullptr )
      CCSPlayer::AddAccount(this: Leader, reason: CASH_AWARD_RESCUED_HOSTAGE, bTrackChange: true, bItemBought: false);
    CHostage::Idle(this);
    v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_rescued", a3: 0, a4: 0);
    if ( v7 != nullptr )
    {
      if ( v6 != nullptr )
        v8 = engine->GetPlayerUserId(this: engine, a2: v6->m_Network.m_pPev);
      else
        v8 = -1;
      ((void (__thiscall *)(IGameEvent *, const char *, int, int))v7->SetInt)(a1: v7, a2: "userid", a3: v8, a4: a2);
      ((void (__thiscall *)(IGameEvent *, const char *))v7->SetInt)(a1: v7, a2: "hostage");
      v7->SetInt(this: v7, a2: "site", a3: 0);
      v7->SetInt(this: v7, a2: "priority", a3: 9);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
    }
    ++g_pGameRules[137].m_pNext;
    v9 = g_pGameRules;
    m_pNext = g_pGameRules[140].m_pNext;
    if ( m_pNext != (CAutoGameSystemPerFrame *)-1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pNext].m_SerialNumber == (unsigned int)m_pNext >> 16
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pNext].m_pEntity != nullptr )
    {
      v11 = g_pGameRules[140].m_pNext;
      if ( v11 == (CAutoGameSystemPerFrame *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != (unsigned int)v11 >> 16 )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      }
      if ( m_pEntity != v6 )
      {
        if ( v6 != nullptr )
          v9[140].m_pNext = (CAutoGameSystemPerFrame *)v6->GetRefEHandle(this: v6)->m_Index;
        else
          g_pGameRules[140].m_pNext = (CAutoGameSystemPerFrame *)-1;
        ++g_pGameRules[140].m_pszName;
      }
    }
    else
    {
      if ( v6 != nullptr )
        v9[140].m_pNext = (CAutoGameSystemPerFrame *)v6->GetRefEHandle(this: v6)->m_Index;
      else
        g_pGameRules[140].m_pNext = (CAutoGameSystemPerFrame *)-1;
      g_pGameRules[140].m_pszName = (const char *)1;
    }
    v13 = g_pGameRules[130].m_pszName != nullptr;
    if ( !CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules) )
    {
      if ( IntervalTimer::Now(this: (CEffectsServer *)&announceTimer) > announceTimer.m_timestamp.m_Value )
        CCSGameRules::BroadcastSound(this: (CCSGameRules *)g_pGameRules, sound: "Event.HostageRescued", team: -1);
      v14 = IntervalTimer::Now(this: (CEffectsServer *)&announceTimer) + 2.0;
      if ( announceTimer.m_timestamp.m_Value != v14 )
      {
        announceTimer.NetworkStateChanged(this: &announceTimer, a2: &announceTimer.m_timestamp);
        v20 = v14;
        announceTimer.m_timestamp.m_Value = v20;
      }
      if ( announceTimer.m_duration.m_Value != 2.0 )
      {
        announceTimer.NetworkStateChanged(this: &announceTimer, a2: &announceTimer.m_duration);
        announceTimer.m_duration.m_Value = 2.0;
      }
LABEL_52:
      if ( v6 != nullptr )
      {
        CCSGameStats::Event_HostageRescued(this: &CCS_GameStats, pPlayer: v6);
        CCSGameRules::ScoreHostageRescue(this: (CCSGameRules *)g_pGameRules, pPlayer: v6, pHostage: this);
      }
      return;
    }
    if ( g_pGameRules[140].m_pszName == (const char *)1 && BYTE1(g_pGameRules[141].__vftable) == 0 )
    {
      v15 = 0;
      if ( g_Hostages.m_Size <= 0 )
      {
LABEL_46:
        CBaseMultiplayerPlayer::AwardAchievement(this: v6, iAchievement: 2001, iCount: 1);
        v17 = gpGlobals;
        if ( v17->curtime - CCSGameRules::GetRoundStartTime(this: (CCSGameRules *)g_pGameRules) < 90.0 )
        {
          if ( v6 == nullptr )
            return;
          CBaseMultiplayerPlayer::AwardAchievement(this: v6, iAchievement: 2003, iCount: 1);
        }
      }
      else
      {
        while ( 1 )
        {
          v16 = g_Hostages.m_Memory.m_pMemory[v15];
          if ( v16->m_iHealth.m_Value > 0 && !v16->m_isRescued.m_Value )
            break;
          if ( ++v15 >= g_Hostages.m_Size )
            goto LABEL_46;
        }
      }
    }
    if ( v6 != nullptr )
    {
      if ( !v13 )
        CCSPlayer::IncrementNumMVPs(this: v6, mvpReason: CSMVP_HOSTAGERESCUE);
      goto LABEL_52;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDC50
// Name: private: void CHostage::UpdateFollowing(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::UpdateFollowing(CHostage *this, float deltaT)
{
  unsigned int m_Index; // eax
  IGameEvent *v4; // edi
  edict_t *m_pPev; // eax
  CCSPlayer *Leader; // eax
  CBaseEntity *v7; // edi
  float *v8; // ebx
  float z; // ecx
  unsigned int v10; // edx
  __int64 v11; // xmm0_8
  float v12; // xmm0_4
  bool IsElapsed; // al
  ConVar *m_pParent; // eax
  Vector from; // [esp+3Ch] [ebp-1Ch] BYREF
  Vector to; // [esp+48h] [ebp-10h] BYREF
  float v17; // [esp+54h] [ebp-4h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  m_Index = this->m_leader.m_Value.m_Index;
  if ( (m_Index == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr)
    && this->m_lastLeaderID != 0 )
  {
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_stops_following", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v4->SetInt(this: v4, a2: "userid", a3: this->m_lastLeaderID);
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      v4->SetInt(this: v4, a2: "hostage", a3: (int)m_pPev);
      v4->SetInt(this: v4, a2: "priority", a3: 6);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
    }
    this->m_lastLeaderID = 0;
  }
  Leader = CHostage::GetLeader(this);
  v7 = Leader;
  if ( Leader != nullptr )
  {
    if ( Leader->IsAlive(this: Leader) )
    {
      if ( this->m_path.m_segmentCount <= 0 )
        goto LABEL_18;
      v8 = (float *)(&this->m_jumpTimer + 2 * this->m_path.m_segmentCount);
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
      if ( (float)((float)((float)((float)(v7->m_vecAbsOrigin.x - *v8) * (float)(v7->m_vecAbsOrigin.x - *v8))
                         + (float)((float)(v7->m_vecAbsOrigin.y - v8[1]) * (float)(v7->m_vecAbsOrigin.y - v8[1])))
                 + (float)((float)(v7->m_vecAbsOrigin.z - v8[2]) * (float)(v7->m_vecAbsOrigin.z - v8[2]))) > 10000.0 )
        this->m_path.m_segmentCount = 0;
      if ( this->m_path.m_segmentCount <= 0 )
      {
LABEL_18:
        if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_repathTimer) > this->m_repathTimer.m_timestamp.m_Value )
        {
          CountdownTimer::Start(this: &this->m_repathTimer, duration: 0.5);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          z = this->m_vecAbsOrigin.z;
          v10 = (unsigned int)v7->m_iEFlags >> 11;
          *(_QWORD *)&from.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
          from.z = z;
          if ( (v10 & 1) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
          v11 = *(_QWORD *)&v7->m_vecAbsOrigin.x;
          to.z = v7->m_vecAbsOrigin.z;
          *(_QWORD *)&to.x = v11;
          CCSNavPath::Compute<HostagePathCost>(
            this: &this->m_path,
            start: &from,
            goal: &to,
            costFunc: (HostagePathCost *)&deltaT + 3);
          CNavPathFollower::Reset(this: &this->m_pathFollower);
        }
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (v7->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
      v12 = (float)((float)((float)(v7->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x)
                          * (float)(v7->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x))
                  + (float)((float)(v7->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)
                          * (float)(v7->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y)))
          + (float)((float)(v7->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                  * (float)(v7->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z));
      v17 = v12;
      if ( v12 <= 4000000.0 )
      {
        if ( this->m_path.m_segmentCount <= 0 )
        {
LABEL_32:
          if ( this->m_isWaitingForLeader )
          {
            if ( v12 > 22500.0 )
              this->m_isWaitingForLeader = false;
          }
          else if ( v12 < 15625.0 )
          {
            this->m_isWaitingForLeader = true;
          }
          if ( !this->m_isWaitingForLeader )
          {
            IsElapsed = CountdownTimer::IsElapsed(this: &this->m_inhibitObstacleAvoidanceTimer);
            CNavPathFollower::Update(this: &this->m_pathFollower, deltaT, avoidObstacles: IsElapsed);
            m_pParent = hostage_debug.m_pParent;
            if ( hostage_debug.m_pParent != nullptr && hostage_debug.m_pParent->m_Value.m_nValue != 0 )
            {
              this->m_pathFollower.m_isDebug = true;
              m_pParent = hostage_debug.m_pParent;
            }
            if ( this->m_pathFollower.m_stuckMonitor.m_isStuck )
            {
              CHostage::Wiggle(this);
              m_pParent = hostage_debug.m_pParent;
            }
            if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
            {
              to.x = 1.0;
              to.y = 0.30000001;
              to.z = 0.0;
              CCSNavPath::Draw(this: &this->m_path, color: &to);
            }
          }
          return;
        }
        if ( CCSNavPath::GetLength(this: &this->m_path) <= 4000.0 )
        {
          v12 = v17;
          goto LABEL_32;
        }
      }
      if ( hostage_debug.m_pParent != nullptr && hostage_debug.m_pParent->m_Value.m_nValue >= 2 )
        return;
    }
    CHostage::Idle(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE010
// Name: public: void CHostage::HostageThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHostage::HostageThink(CHostage *this@<ecx>, int a2@<edi>)
{
  CNavArea *NavArea; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  ICSPlayerAnimState *m_PlayerAnimState; // edi
  unsigned int v13; // ecx
  float m_disappearTime; // xmm0_4
  Vector mins; // [esp+10h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+1Ch] [ebp-10h] BYREF
  float v17; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( !this->m_isAdjusted )
  {
    maxs.x = 13.0;
    maxs.y = 13.0;
    maxs.z = 72.0;
    mins.x = -13.0;
    mins.y = -13.0;
    this->m_isAdjusted = true;
    mins.z = 0.0;
    CBaseEntity::SetCollisionBounds(this, &mins, &maxs);
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &this->m_vecAbsOrigin, beneathLimit: 120.0);
  if ( NavArea != nullptr && NavArea != this->m_lastKnownArea )
    this->m_lastKnownArea = NavArea;
  CHostage::UpdateFollowing(this, deltaT: 0.1);
  CHostage::AvoidPhysicsProps(this, a2);
  v4 = this->m_accel.y - (float)(this->m_vel.y * 2.0);
  v5 = this->m_accel.z - (float)(this->m_vel.z * 2.0);
  this->m_vel.x = (float)((float)(this->m_accel.x - (float)(this->m_vel.x * 2.0)) * 0.1) + this->m_vel.x;
  this->m_vel.y = this->m_vel.y + (float)(v4 * 0.1);
  this->m_vel.z = this->m_vel.z + (float)(v5 * 0.1);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  this->m_vel.z = this->m_vecAbsVelocity.z;
  x = this->m_accel.x;
  if ( x > -0.0099999998 && x < 0.0099999998 )
  {
    y = this->m_accel.y;
    if ( y > -0.0099999998 && y < 0.0099999998 )
    {
      z = this->m_accel.z;
      if ( z > -0.0099999998 && z < 0.0099999998 )
      {
        v9 = this->m_vel.x;
        if ( v9 > -1.0 && v9 < 1.0 )
        {
          v10 = this->m_vel.y;
          if ( v10 > -1.0 && v10 < 1.0 )
          {
            this->m_vel.x = 0.0;
            this->m_vel.y = 0.0;
          }
        }
      }
    }
  }
  this->m_accel.x = 0.0;
  this->m_accel.y = 0.0;
  this->m_accel.z = 0.0;
  this->StudioFrameAdvance(this);
  v11 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_IDLE);
  if ( this->m_nSequence.m_Value != v11 )
    CBaseAnimating::SetSequence(this, nSequence: v11);
  m_PlayerAnimState = this->m_PlayerAnimState;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v13 = (unsigned int)this->m_iEFlags >> 11;
  v17 = this->m_angAbsRotation.x;
  if ( (v13 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  (*(void (__thiscall **)(_BYTE *, _DWORD, float))(*(_DWORD *)&m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)m_PlayerAnimState->gap4
                                                                                                 + 4)]
                                                 + 4))(
    a1: &m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)m_PlayerAnimState->gap4 + 4)],
    a2: LODWORD(this->m_angAbsRotation.y),
    a3: COERCE_FLOAT(LODWORD(v17)));
  m_disappearTime = this->m_disappearTime;
  if ( m_disappearTime != 0.0 && gpGlobals->curtime > m_disappearTime )
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0);
    this->m_disappearTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE4B0
// Name: public: virtual void CHostage::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostage::Spawn(CHostage *this)
{
  char *v2; // eax
  void (__thiscall *SetModel)(CBaseEntity *, const char *); // edx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  void (__thiscall *SetViewOffset)(CBaseEntity *, const Vector *); // edx
  IHandleEntity *m_pEntity; // ebx
  unsigned int m_Index; // ecx
  IHandleEntity *v8; // eax
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx
  int m_iEFlags; // edx
  float z; // edx
  Vector GroundPos; // [esp+34h] [ebp-24h] BYREF
  Vector pos; // [esp+40h] [ebp-18h] BYREF
  Vector vMaxs; // [esp+4Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  this->Precache(this);
  v2 = HostageModel[index % 4];
  SetModel = this->SetModel;
  ++index;
  SetModel(this, a2: v2);
  this->m_eHull = HULL_HUMAN;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 5);
  p_m_iHealth = &this->m_iHealth;
  this->m_flGravity = 1.0;
  if ( this->m_iHealth.m_Value != 100 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = 100;
  }
  if ( this->m_iMaxHealth.m_Value != p_m_iHealth->m_Value )
  {
    this->NetworkStateChanged_m_iMaxHealth(this, a2: &this->m_iMaxHealth);
    this->m_iMaxHealth.m_Value = p_m_iHealth->m_Value;
  }
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  this->InitBoneControllers(this);
  SetViewOffset = this->SetViewOffset;
  vMaxs.x = 0.0;
  vMaxs.y = 0.0;
  vMaxs.z = 60.0;
  SetViewOffset(this, a2: &vMaxs);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CHostage::HostageThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CHostage::PushawayThink,
    thinkTime: gpGlobals->curtime + 0.050000001,
    szContext: "HostagePushawayThink");
  this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float)) __thiscall CHostage::`vcall'{1356,{flat}};
  if ( g_pEntityList->m_EntPtrArray[0].m_SerialNumber != 0 )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[0].m_pEntity;
  m_Index = this->m_leader.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( v8 != m_pEntity )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x8FCu);
    }
    this->m_leader.m_Value.m_Index = 0;
  }
  if ( this->m_reuseTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_reuseTimer.NetworkStateChanged(this: &this->m_reuseTimer, a2: &this->m_reuseTimer.m_timestamp);
    this->m_reuseTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_hasBeenUsed = false;
  if ( this->m_isRescued.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x8F8u);
    }
    this->m_isRescued.m_Value = false;
  }
  this->m_vel.x = 0.0;
  this->m_vel.y = 0.0;
  this->m_vel.z = 0.0;
  this->m_accel.x = 0.0;
  this->m_accel.y = 0.0;
  this->m_accel.z = 0.0;
  this->m_path.m_segmentCount = 0;
  if ( this->m_repathTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_repathTimer.NetworkStateChanged(this: &this->m_repathTimer, a2: &this->m_repathTimer.m_timestamp);
    this->m_repathTimer.m_timestamp.m_Value = -1.0;
  }
  CNavPathFollower::Reset(this: &this->m_pathFollower);
  m_iEFlags = this->m_iEFlags;
  vMaxs.x = 13.0;
  vMaxs.y = 13.0;
  vMaxs.z = 72.0;
  pos.x = -13.0;
  pos.y = -13.0;
  this->m_pathFollower.m_path = &this->m_path;
  this->m_pathFollower.m_improv = &this->CImprovLocomotor;
  this->m_lastKnownArea = nullptr;
  pos.z = 0.0;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  DropToGround(a1: (int)this, result: &GroundPos, pMainEnt: this, vPos: &this->m_vecAbsOrigin, vMins: &pos, &vMaxs);
  CBaseEntity::SetAbsOrigin(this, absOrigin: &GroundPos);
  if ( TheNavMesh != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    *(_QWORD *)&pos.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    pos.z = z;
    this->m_lastKnownArea = CNavMesh::GetNearestNavArea(
                              this: TheNavMesh,
                              &pos,
                              anyZ: false,
                              maxDist: 10000.0,
                              checkLOS: false,
                              checkGround: true);
  }
  *(_WORD *)&this->m_isRunning = 1;
  if ( this->m_jumpTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_jumpTimer.NetworkStateChanged(this: &this->m_jumpTimer, a2: &this->m_jumpTimer.m_timestamp);
    this->m_jumpTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_inhibitObstacleAvoidanceTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_inhibitObstacleAvoidanceTimer.NetworkStateChanged(
      this: &this->m_inhibitObstacleAvoidanceTimer,
      a2: &this->m_inhibitObstacleAvoidanceTimer.m_timestamp);
    this->m_inhibitObstacleAvoidanceTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_isWaitingForLeader = false;
  this->m_isAdjusted = false;
  this->m_lastLeaderID = 0;
  if ( announceTimer.m_timestamp.m_Value != -1.0 )
  {
    announceTimer.NetworkStateChanged(this: &announceTimer, a2: &announceTimer.m_timestamp);
    announceTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_disappearTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10411AF0
// Name: _dynamic_initializer_for__hostage_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostage_debug__()
{
  ConVar::ConVar(
    this: &hostage_debug,
    pName: "hostage_debug",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show hostage AI debug information");
  return atexit(func: dynamic_atexit_destructor_for__hostage_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10411B80
// Name: _dynamic_initializer_for__hostage_entity__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__hostage_entity__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CHostage> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &hostage_entity,
           a3: "hostage_entity");
}

//------------------------------------------------------------------------------
// Address: 0x10411BA0
// Name: CHostage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CHostage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CHostage>(__formal: nullptr);
  CHostage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411BD0
// Name: DT_CHostage::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CHostage::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CHostage::g_SendTable);
  return atexit(func: DT_CHostage::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411BF0
// Name: DT_CHostage::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CHostage::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CHostage::ignored>();
  DT_CHostage::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420650
// Name: _dynamic_atexit_destructor_for__hostage_debug__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hostage_debug__()
{
  ConVar::~ConVar(this: &hostage_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10420680
// Name: DT_CHostage::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CHostage::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CHostage::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102DE350
// Name: struct datamap_t __near * DataMapInit<class CHostage>(class CHostage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CHostage>()
{
  if ( (_S2_265 & 1) == 0 )
  {
    _S2_265 |= 1u;
    nameHolder_489.m_pszBase = "CHostage";
    nameHolder_489.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_489.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_489.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_489.m_Names.m_Size = 0;
    nameHolder_489.m_Names.m_pElements = nullptr;
    nameHolder_489.m_nLenBase = 8;
    atexit(func: DataMapInit_CHostage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CHostage::m_DataMap.baseMap = &CBaseCombatCharacter::m_DataMap;
  if ( (_S2_265 & 2) == 0 )
  {
    _S2_265 |= 2u;
    dataDesc_449[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_489,
                                  pszIdentifier: "HostageUse");
    dataDesc_449[2].flags = 32;
    dataDesc_449[2].fieldOffset = 0;
    dataDesc_449[2].fieldSize = 1;
    dataDesc_449[2].externalName = nullptr;
    dataDesc_449[2].pSaveRestoreOps = nullptr;
    dataDesc_449[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CHostage::`vcall'{1356,{flat}};
    *(_QWORD *)&dataDesc_449[2].td = 0;
    *(_QWORD *)&dataDesc_449[2].override_field = 0;
    *(_QWORD *)&dataDesc_449[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_449[2].flatOffset[1] = 0;
    dataDesc_449[3].fieldType = FIELD_VOID;
    dataDesc_449[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_489,
                                  pszIdentifier: "HostageThink");
    dataDesc_449[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_449[3].fieldSize = 2097153;
    dataDesc_449[3].externalName = nullptr;
    dataDesc_449[3].pSaveRestoreOps = nullptr;
    dataDesc_449[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CHostage::HostageThink;
    *(_QWORD *)&dataDesc_449[3].td = 0;
    *(_QWORD *)&dataDesc_449[3].override_field = 0;
    *(_QWORD *)&dataDesc_449[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_449[3].flatOffset[1] = 0;
  }
  CHostage::m_DataMap.dataNumFields = 3;
  CHostage::m_DataMap.dataDesc = &dataDesc_449[1];
  return &CHostage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10411B20
// Name: _dynamic_initializer_for__sv_pushaway_hostage_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_hostage_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_hostage_force,
    pName: "sv_pushaway_hostage_force",
    pDefaultValue: "20000",
    flags: 24576,
    pHelpString: "How hard the hostage is pushed away from physics objects (falls off with inverse square of distance).");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_hostage_force__);
}

//------------------------------------------------------------------------------
// Address: 0x10411B50
// Name: _dynamic_initializer_for__sv_pushaway_max_hostage_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_pushaway_max_hostage_force__()
{
  ConVar::ConVar(
    this: &sv_pushaway_max_hostage_force,
    pName: "sv_pushaway_max_hostage_force",
    pDefaultValue: "1000",
    flags: 24576,
    pHelpString: "Maximum of how hard the hostage is pushed away from physics objects.");
  return atexit(func: dynamic_atexit_destructor_for__sv_pushaway_max_hostage_force__);
}

//------------------------------------------------------------------------------
// Address: 0x10411BB0
// Name: _dynamic_initializer_for__g_CHostage_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CHostage_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CHostage_ClassReg,
           pNetworkName: "CHostage",
           pTable: &DT_CHostage::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10411C00
// Name: _dynamic_initializer_for__g_Hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Hostages__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Hostages__);
}

//------------------------------------------------------------------------------
// Address: 0x10411C10
// Name: _dynamic_initializer_for__announceTimer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__announceTimer__()
{
  void (__thiscall *NetworkStateChanged)(CountdownTimer *, void *); // edx

  CNavMesh::SaveCustomData(this: (vgui::TreeView *)&announceTimer, itemIndex: (int)&announceTimer.m_duration);
  NetworkStateChanged = announceTimer.NetworkStateChanged;
  announceTimer.m_timestamp.m_Value = -1.0;
  return ((int (__thiscall *)(CountdownTimer *, CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *))NetworkStateChanged)(
           a1: &announceTimer,
           a2: &announceTimer.m_timestamp);
}

//------------------------------------------------------------------------------
// Address: 0x10411C50
// Name: _dynamic_initializer_for__nav_restart_after_analysis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__nav_restart_after_analysis__()
{
  ConVar::ConVar(
    this: &nav_restart_after_analysis,
    pName: "nav_restart_after_analysis",
    pDefaultValue: "1",
    flags: 4,
    pHelpString: "When nav nav_restart_after_analysis finishes, restart the server.  Turning this off can cause crashes, but is useful"
    " for incremental generation.");
  return atexit(func: dynamic_atexit_destructor_for__nav_restart_after_analysis__);
}

//------------------------------------------------------------------------------
// Address: 0x10411C80
// Name: _dynamic_initializer_for__g_CAK47_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CAK47_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CAK47_ClassReg, pNetworkName: "CAK47", pTable: &DT_WeaponAK47::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420660
// Name: _dynamic_atexit_destructor_for__sv_pushaway_hostage_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_hostage_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_hostage_force);
}

//------------------------------------------------------------------------------
// Address: 0x10420670
// Name: _dynamic_atexit_destructor_for__sv_pushaway_max_hostage_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_max_hostage_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_max_hostage_force);
}

//------------------------------------------------------------------------------
// Address: 0x10420690
// Name: _ServerClassInit_DT_CHostage::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CHostage::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_153;
  for ( i = 14; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104206B0
// Name: _DataMapInit_CHostage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CHostage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_489);
}

//------------------------------------------------------------------------------
// Address: 0x104206C0
// Name: _dynamic_atexit_destructor_for__g_Hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Hostages__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Hostages);
}

//------------------------------------------------------------------------------
// Address: 0x104206D0
// Name: _dynamic_atexit_destructor_for__nav_restart_after_analysis__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_restart_after_analysis__()
{
  ConVar::~ConVar(this: &nav_restart_after_analysis);
}
