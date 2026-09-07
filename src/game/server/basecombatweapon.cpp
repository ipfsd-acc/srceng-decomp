// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/basecombatweapon.cpp
// Functions: 26
// ============================================================

#include "game\server\basecombatweapon.h"

//------------------------------------------------------------------------------
// Address: 0x100ACD20
// Name: public: void constraint_fixedparams_t::Defaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall constraint_fixedparams_t::Defaults(constraint_fixedparams_t *this)
{
  SetIdentityMatrix(matrix: &this->attachedRefXform);
  this->constraint.forceLimit = 0.0;
  this->constraint.torqueLimit = 0.0;
  this->constraint.strength = 1.0;
  this->constraint.bodyMassScale[0] = 1.0;
  this->constraint.bodyMassScale[1] = 1.0;
  this->constraint.isActive = true;
}

//------------------------------------------------------------------------------
// Address: 0x100ACD60
// Name: public: virtual void WeaponResourcesPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall WeaponResourcesPrecache::CResourcePrecacher::Cache(
        WeaponResourcesPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/zerogxplode.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexFireball);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/steam1.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexSmoke);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/bubble.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexBubbles);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "sprites/laserbeam.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: &g_sModelIndexLaser);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_red_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_green_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "blood_impact_yellow_01",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "models/weapons/w_bullet.mdl",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "effects/bubble.vmt",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "BaseCombatWeapon.WeaponDrop",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "BaseCombatWeapon.WeaponMaterialize",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100ACE60
// Name: void W_Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl W_Precache()
{
  const unsigned __int8 *v0; // eax

  v0 = g_pGameRules->GetEncryptionKey(this: g_pGameRules);
  PrecacheFileWeaponInfoDatabase(filesystem: filesystem, pICEKey: v0);
}

//------------------------------------------------------------------------------
// Address: 0x100ACE80
// Name: public: virtual int CBaseCombatWeapon::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::UpdateTransmitState(CBaseCombatWeapon *this)
{
  if ( CBaseCombatWeapon::GetOwner(this) != nullptr )
    return CBaseEntity::SetTransmitState(this, nFlag: 32);
  else
    return CBaseEntity::UpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ACEA0
// Name: public: virtual int CBaseCombatWeapon::WeaponRangeAttack1Condition(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::WeaponRangeAttack1Condition(CBaseCombatWeapon *this, float flDot, float flDist)
{
  int result; // eax

  if ( CBaseCombatWeapon::UsesPrimaryAmmo(this) && !this->HasPrimaryAmmo(this) )
    return 4;
  if ( this->m_fMinRange1 > flDist )
    return 38;
  if ( flDist > this->m_fMaxRange1 )
    return 39;
  result = 40;
  if ( flDot >= 0.5 )
    return 21;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ACF20
// Name: public: virtual void CBaseCombatWeapon::Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Delete(CBaseCombatWeapon *this)
{
  this->m_pfnTouch = nullptr;
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100ACF70
// Name: public: void CBaseCombatWeapon::AttemptToMaterialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::AttemptToMaterialize(CBaseCombatWeapon *this)
{
  double v2; // st7
  float time; // [esp+10h] [ebp-4h]

  v2 = ((double (__thiscall *)(CGameRules *, CBaseCombatWeapon *))g_pGameRules->FlWeaponTryRespawn)(
         a1: g_pGameRules,
         a2: this);
  if ( v2 == 0.0 )
  {
    this->Materialize(this);
  }
  else
  {
    time = v2;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + time, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACFD0
// Name: public: virtual void CBaseCombatWeapon::CheckRespawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::CheckRespawn(CBaseCombatWeapon *this)
{
  if ( g_pGameRules->WeaponShouldRespawn(this: g_pGameRules, a2: this) == 1 )
    this->Respawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x100AD010
// Name: public: virtual void CTraceFilterSkipTwoEntities::SetPassEntity2(class IHandleEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSkipTwoEntities::SetPassEntity2(
        CTraceFilterSkipTwoEntities *this,
        const IHandleEntity *pPassEntity2)
{
  this->m_pPassEnt2 = pPassEntity2;
}

//------------------------------------------------------------------------------
// Address: 0x100AD020
// Name: public: void constraint_fixedparams_t::InitWithCurrentObjectState(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall constraint_fixedparams_t::InitWithCurrentObjectState(
        constraint_fixedparams_t *this,
        IPhysicsObject *pRef,
        IPhysicsObject *pAttached)
{
  matrix3x4_t out; // [esp+4h] [ebp-90h] BYREF
  matrix3x4_t in; // [esp+34h] [ebp-60h] BYREF
  matrix3x4_t in2; // [esp+64h] [ebp-30h] BYREF

  pRef->GetPositionMatrix(this: pRef, a2: &in);
  MatrixInvert(&in, &out);
  pAttached->GetPositionMatrix(this: pAttached, a2: &in2);
  ConcatTransforms(in1: &out, &in2, out: &this->attachedRefXform);
}

//------------------------------------------------------------------------------
// Address: 0x100AD080
// Name: public: virtual void CBaseCombatWeapon::Operator_FrameUpdate(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Operator_FrameUpdate(CBaseCombatWeapon *this, CBaseCombatCharacter *pOperator)
{
  int v3; // eax
  CBasePlayer *Owner; // edi
  CBaseViewModel *ViewModel; // edi
  CStudioHdr *m_pStudioHdr; // eax
  CStudioHdr *v7; // ebx
  CStudioHdr *v8; // eax

  this->StudioFrameAdvance(this);
  if ( this->m_bSequenceFinished && this->m_bSequenceLoops )
  {
    v3 = CBaseAnimating::SelectWeightedSequence(this, activity: this->m_Activity);
    if ( v3 != -1 )
      CBaseAnimating::ResetSequence(this, nSequence: v3);
  }
  Owner = (CBasePlayer *)CBaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
  {
    ViewModel = CBasePlayer::GetViewModel(this: Owner, index: this->m_nViewModelIndex.m_Value);
    if ( ViewModel != nullptr )
    {
      if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
        CBaseAnimating::LockStudioHdr(this);
      m_pStudioHdr = this->m_pStudioHdr;
      if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
        v7 = this->m_pStudioHdr;
      else
        v7 = nullptr;
      if ( ViewModel->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: ViewModel) != nullptr )
        CBaseAnimating::LockStudioHdr(this: ViewModel);
      v8 = ViewModel->m_pStudioHdr;
      if ( v8 == nullptr || v8->m_pStudioHdr == nullptr )
        v8 = nullptr;
      if ( v7->m_pStudioHdr != v8->m_pStudioHdr )
        this->DispatchAnimEvents(this, a2: pOperator);
      ViewModel->StudioFrameAdvance(this: ViewModel);
      ViewModel->DispatchAnimEvents(this: ViewModel, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD190
// Name: public: virtual void CBaseCombatWeapon::Operator_HandleAnimEvent(struct animevent_t __near *,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Operator_HandleAnimEvent(
        CBaseCombatWeapon *this,
        animevent_t *pEvent,
        CBaseCombatCharacter *pOperator)
{
  int type; // edx
  int event_lowword; // edi
  int WeaponSoundFromString; // eax
  const char *pszValue; // esi
  const char *v8; // eax

  type = pEvent->type;
  if ( (type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( (pEvent->type & 0x400) != 0 && (type & 1) != 0 )
  {
    if ( event_lowword == 14 )
    {
      LOBYTE(pEvent) = atoi(nptr: pEvent->options) != 0;
      this->Operator_ForceNPCFire(this, a2: pOperator, a3: (bool)pEvent, a4: nullptr);
      return;
    }
    if ( event_lowword == 45 )
    {
      WeaponSoundFromString = GetWeaponSoundFromString(pszString: pEvent->options);
      if ( WeaponSoundFromString != -1 )
        ((void (__thiscall *)(CBaseCombatWeapon *, int, _DWORD))this->WeaponSound)(
          a1: this,
          a2: WeaponSoundFromString,
          a3: 0);
    }
  }
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v8 = pOperator->m_iClassname.pszValue;
  if ( v8 == nullptr )
    v8 = locale;
  _DevWarning(a1: 2, a2: "Unhandled animation event %d from %s --> %s\n", event_lowword, v8, pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x100AD250
// Name: public: virtual void CBaseCombatWeapon::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::HandleAnimEvent(CBaseCombatWeapon *this, animevent_t *pEvent)
{
  CBaseCombatCharacter *Owner; // esi

  Owner = CBaseCombatWeapon::GetOwner(this);
  if ( Owner != nullptr && Owner->IsPlayer(this: Owner) )
    this->Operator_HandleAnimEvent(this, a2: pEvent, a3: Owner);
}

//------------------------------------------------------------------------------
// Address: 0x100AD290
// Name: public: virtual void CBaseCombatWeapon::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Use(
        CBaseCombatWeapon *this,
        CBaseCombatCharacter *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
  {
    COutputEvent::FireOutput(this: &this->m_OnPlayerUse, pActivator, pCaller, fDelay: 0.0);
    if ( ((unsigned __int8 (__thiscall *)(CBaseCombatCharacter *, CBaseCombatWeapon *))pActivator->__vftable[1].IsBaseObject)(
           a1: pActivator,
           a2: this) != 0 )
      this->OnPickedUp(this, a2: pActivator);
    else
      ((void (__thiscall *)(CBaseCombatCharacter *, CBaseCombatWeapon *, int))pActivator->__vftable[1].StartTouch)(
        a1: pActivator,
        a2: this,
        a3: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD310
// Name: public: virtual class CBaseEntity __near * CBaseCombatWeapon::Respawn(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CBaseCombatWeapon::Respawn(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *pszValue; // esi
  const Vector *v5; // eax
  CBaseEntity *v6; // eax
  CBaseEntity *v7; // esi
  const char *v9; // edi
  float thinkTime; // [esp+Ch] [ebp-1Ch]
  CBaseEntity *v11; // [esp+10h] [ebp-18h]
  _BYTE v12[12]; // [esp+1Ch] [ebp-Ch] BYREF

  m_Index = this->m_hOwnerEntity.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v11 = (CBaseEntity *)m_pEntity;
  v5 = g_pGameRules->VecWeaponRespawnSpot(this: g_pGameRules, result: v12, a3: this);
  v6 = CBaseEntity::Create(szName: pszValue, vecOrigin: v5, vecAngles: &this->m_angRotation.m_Value, pOwner: v11);
  v7 = v6;
  if ( v6 != nullptr )
  {
    CBaseEntity::AddEffects(this: v6, nEffects: 32);
    v7->m_pfnTouch = nullptr;
    CBaseEntity::ThinkSet(
      this: v7,
      func: (void (__thiscall *)(CBaseEntity *))CBaseCombatWeapon::AttemptToMaterialize,
      thinkTime: 0.0,
      szContext: nullptr);
    UTIL_DropToFloor(pEntity: this, mask: 0x200400Bu, pIgnore: nullptr);
    thinkTime = ((double (__thiscall *)(CGameRules *, CBaseCombatWeapon *))g_pGameRules->FlWeaponRespawnTime)(
                  a1: g_pGameRules,
                  a2: this)
              + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this: v7, thinkTime, szContext: nullptr);
    return v7;
  }
  else
  {
    v9 = this->m_iClassname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    _Warning(a1: "Respawn failed to create %s!\n", v9);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD410
// Name: public: virtual bool CWeaponLOSFilter::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWeaponLOSFilter::ShouldHitEntity(CWeaponLOSFilter *this, CBaseEntity *pServerEntity, int contentsMask)
{
  CBreakable *v5; // eax
  CBreakable *v6; // edi

  if ( pServerEntity->m_CollisionGroup.m_Value == 11 || pServerEntity == this->m_pVehicle )
    return false;
  if ( pServerEntity->m_iHealth.m_Value > 0 )
  {
    v5 = (CBreakable *)__RTDynamicCast(
                         inptr: pServerEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CBreakable `RTTI Type Descriptor',
                         isReference: 0);
    v6 = v5;
    if ( v5 != nullptr && CBreakable::IsBreakable(this: v5) && v6->m_Material == matGlass )
      return false;
  }
  return CTraceFilterSkipTwoEntities::ShouldHitEntity(this, pHandleEntity: pServerEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x100AD490
// Name: public: virtual void CBaseCombatWeapon::FallInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::FallInit(CBaseCombatWeapon *this)
{
  CBaseCombatWeapon_vtbl *v2; // edi
  const char *v3; // eax
  int v4; // eax
  IPhysicsObject *v5; // edi
  IPhysicsObject *m_pPhysicsObject; // ebx
  IPhysicsConstraint *v7; // eax
  constraint_fixedparams_t fixed; // [esp+28h] [ebp-48h] BYREF

  v2 = this->__vftable;
  v3 = this->GetWorldModel(this);
  v2->SetModel(this, a2: v3);
  this->VPhysicsDestroyObject(this);
  v4 = this->m_Collision.GetSolidFlags(this: &this->m_Collision);
  if ( CBaseEntity::VPhysicsInitNormal(
         this,
         solidType: SOLID_BBOX,
         nSolidFlags: v4 | 8,
         createAsleep: false,
         pSolid: nullptr) != nullptr )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      v5 = g_PhysWorldObject;
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( g_PhysWorldObject != nullptr && m_pPhysicsObject != nullptr )
      {
        SetIdentityMatrix(matrix: &fixed.attachedRefXform);
        fixed.constraint.forceLimit = 0.0;
        fixed.constraint.torqueLimit = 0.0;
        fixed.constraint.strength = 1.0;
        fixed.constraint.bodyMassScale[0] = 1.0;
        fixed.constraint.bodyMassScale[1] = 1.0;
        fixed.constraint.isActive = true;
        constraint_fixedparams_t::InitWithCurrentObjectState(this: &fixed, pRef: v5, pAttached: m_pPhysicsObject);
        fixed.constraint.forceLimit = 4545.4546;
        fixed.constraint.torqueLimit = 4545.4546;
        v7 = physenv->CreateFixedConstraint(this: physenv, a2: v5, a3: m_pPhysicsObject, a4: 0, a5: &fixed);
        this->m_pConstraint = v7;
        v7->SetGameData(this: v7, a2: this);
      }
    }
  }
  else
  {
    CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  }
  this->SetPickupTouch(this);
  CBaseEntity::ThinkSet(
    this,
    func:  __thiscall CBaseCombatWeapon::`vcall'{1408,{flat}},
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100AD600
// Name: public: virtual void CBaseCombatWeapon::FallThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::FallThink(CBaseCombatWeapon *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  bool v3; // al
  unsigned int m_Index; // ecx

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    v3 = m_pPhysicsObject->IsAsleep(this: m_pPhysicsObject);
  else
    v3 = this->m_fFlags.m_Value & 1;
  if ( v3 )
  {
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::EmitSound(this, soundname: "BaseCombatWeapon.WeaponDrop", soundtime: 0.0, duration: nullptr);
    }
    this->Materialize(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD6A0
// Name: public: virtual int CBaseCombatWeapon::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseCombatWeapon::ObjectCaps(CBaseCombatWeapon *this)
{
  int v2; // edi

  v2 = CBaseEntity::ObjectCaps(this);
  if ( !CBaseEntity::IsFollowingEntity(this) && (this->m_spawnflags.m_Value & 2) == 0 )
    return v2 | 1;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100AD6D0
// Name: public: virtual bool CBaseCombatWeapon::WeaponLOSCondition(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseCombatWeapon::WeaponLOSCondition(
        CBaseCombatWeapon *this,
        const Vector *ownerPos,
        const Vector *targetPos,
        bool bSetConditions)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CAI_BaseNPC *v7; // esi
  float *v8; // eax
  float v9; // xmm2_4
  float v10; // xmm3_4
  unsigned int v11; // eax
  float v12; // xmm0_4
  IHandleEntity *v13; // edi
  const IHandleEntity *v14; // eax
  int v15; // eax
  CBaseEntity *m_pEnt; // edi
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  CBaseEntity *v21; // ebx
  IServerVehicle *v22; // eax
  int v23; // eax
  CGameTrace tr; // [esp+14h] [ebp-84h] BYREF
  Vector v25; // [esp+68h] [ebp-30h] BYREF
  CWeaponLOSFilter traceFilter; // [esp+74h] [ebp-24h] BYREF
  Vector barrelPos; // [esp+8Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+98h] [ebp+0h] BYREF

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v7 = (CAI_BaseNPC *)m_pEntity->__vftable[24].GetRefEHandle(this: m_pEntity);
  if ( (v7->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
  v8 = (float *)v7->Weapon_ShootPosition(this: v7, result: &v25);
  v9 = v8[2] - v7->m_vecAbsOrigin.z;
  v10 = ownerPos->x + (float)(*v8 - v7->m_vecAbsOrigin.x);
  barrelPos.y = ownerPos->y + (float)(v8[1] - v7->m_vecAbsOrigin.y);
  v11 = this->m_hOwner.m_Value.m_Index;
  v12 = ownerPos->z + v9;
  barrelPos.x = v10;
  barrelPos.z = v12;
  if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    v13 = nullptr;
  else
    v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
  v14 = v7->GetEnemy_2(this: v7);
  CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
    this: &traceFilter,
    passentity: v13,
    passentity2: v14,
    collisionGroup: 6);
  traceFilter.__vftable = (CWeaponLOSFilter_vtbl *)&CWeaponLOSFilter::`vftable';
  traceFilter.m_pVehicle = nullptr;
  if ( v13 != nullptr )
  {
    v15 = ((int (__thiscall *)(IHandleEntity *))v13->__vftable[25].dtr_IHandleEntity)(a1: v13);
    if ( v15 != 0 )
      traceFilter.m_pVehicle = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 1268))(a1: v15);
  }
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)v7,
    vecAbsStart: &barrelPos,
    vecAbsEnd: targetPos,
    mask: 0x46004003u,
    pFilter: &traceFilter,
    ptr: &tr);
  if ( tr.fraction != 1.0 )
  {
    m_pEnt = tr.m_pEnt;
    v18 = (int)v7->GetEnemy_2(this: v7);
    v19 = v18;
    if ( v18 == 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v18 + 336))(a1: v18) == 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v19 + 1260))(a1: v19) == 0
      || (v20 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 1264))(a1: v19),
          v21 = (CBaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 32))(a1: v20),
          m_pEnt != v21)
      && CBaseEntity::GetOwnerEntity(this: m_pEnt) != v21 )
    {
      if ( m_pEnt == v7->GetEnemy_2(this: v7) )
      {
        if ( ai_debug_shoot_positions.m_pParent != nullptr && ai_debug_shoot_positions.m_pParent->m_Value.m_nValue != 0 )
          NDebugOverlay::Line(
            origin: &barrelPos,
            target: targetPos,
            r: 0,
            g: 255,
            b: 0,
            noDepthTest: false,
            duration: 1.0);
        return 1;
      }
      v22 = m_pEnt->GetServerVehicle(this: m_pEnt);
      if ( v22 != nullptr )
        v23 = v22->GetPassenger(this: v22, a2: 0);
      else
        v23 = (int)m_pEnt->MyCombatCharacterPointer(this: m_pEnt);
      if ( v23 == 0 )
      {
        if ( bSetConditions )
        {
          CAI_BaseNPC::SetCondition(this: v7, iCondition: 45);
          CAI_BaseNPC::SetEnemyOccluder(this: v7, pBlocker: m_pEnt);
          if ( ai_debug_shoot_positions.m_pParent != nullptr
            && ai_debug_shoot_positions.m_pParent->m_Value.m_nValue != 0 )
          {
            NDebugOverlay::Line(
              origin: &tr.startpos,
              target: &tr.endpos,
              r: 255,
              g: 0,
              b: 0,
              noDepthTest: false,
              duration: 1.0);
          }
        }
        return 0;
      }
      if ( v7->IRelationType(this: v7, a2: (CBaseEntity *)v23) != D_HT )
      {
        if ( bSetConditions )
        {
          CAI_BaseNPC::SetCondition(this: v7, iCondition: 42);
          return 0;
        }
        return 0;
      }
    }
    return 1;
  }
  if ( ai_debug_shoot_positions.m_pParent != nullptr && ai_debug_shoot_positions.m_pParent->m_Value.m_nValue != 0 )
    NDebugOverlay::Line(origin: &barrelPos, target: targetPos, r: 0, g: 255, b: 0, noDepthTest: false, duration: 1.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AD9E0
// Name: public: void CBaseCombatWeapon::DestroyItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::DestroyItem(CBaseCombatWeapon *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax

  m_Index = this->m_hOwner.m_Value.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      ((void (__thiscall *)(IHandleEntity *, CBaseCombatWeapon *))m_pEntity->__vftable[95].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: this);
  }
  this->Kill(this);
}

//------------------------------------------------------------------------------
// Address: 0x100ADA30
// Name: public: virtual void CBaseCombatWeapon::Materialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::Materialize(CBaseCombatWeapon *this)
{
  unsigned int v2; // ebx
  edict_t *m_pPev; // ecx

  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    CBaseEntity::EmitSound(this, soundname: "BaseCombatWeapon.WeaponMaterialize", soundtime: 0.0, duration: nullptr);
    v2 = this->m_fEffects.m_Value & 0xFFFFFFDF;
    if ( this->m_fEffects.m_Value != v2 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
      }
      this->m_fEffects.m_Value = v2;
    }
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseAnimating::DoMuzzleFlash(this);
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  this->SetPickupTouch(this);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100ADB00
// Name: public: virtual void CBaseCombatWeapon::MakeWeaponNameFromEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCombatWeapon::MakeWeaponNameFromEntity(CBaseCombatWeapon *this, CBaseEntity *pOther)
{
  const char *pszValue; // eax
  const char *v4; // edi
  edict_t *m_pPev; // ecx

  pszValue = pOther->m_iName.m_Value.pszValue;
  if ( pszValue != nullptr )
  {
    UTIL_VarArgs(format: "%s_weapon", pszValue);
    AllocPooledString(pszValue: (const char *)&pOther);
    v4 = (const char *)pOther;
    if ( (CBaseEntity *)this->m_iName.m_Value.pszValue != pOther )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xCCu);
      }
      this->m_iName.m_Value.pszValue = v4;
    }
    CGlobalEntityList::UpdateName(this: &gEntList, pEnt: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FF660
// Name: WeaponResourcesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int WeaponResourcesPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  WeaponResourcesPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&WeaponResourcesPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF680
// Name: _dynamic_initializer_for__g_WeaponList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WeaponList__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_WeaponList, name: "CWeaponList");
  g_WeaponList.__vftable = (CWeaponList_vtbl *)&CWeaponList::`vftable';
  g_WeaponList.m_list.m_Memory.m_pMemory = nullptr;
  g_WeaponList.m_list.m_Memory.m_nAllocationCount = 0;
  g_WeaponList.m_list.m_Memory.m_nGrowSize = 0;
  g_WeaponList.m_list.m_LastAlloc.index = -1;
  *(_DWORD *)&g_WeaponList.m_list.m_Head = -1;
  *(_DWORD *)&g_WeaponList.m_list.m_FirstFree = 0xFFFF;
  g_WeaponList.m_list.m_NumAlloced = 0;
  g_WeaponList.m_list.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_WeaponList__);
}

//------------------------------------------------------------------------------
// Address: 0x103FF6E0
// Name: _dynamic_initializer_for__g_CBaseCombatWeapon_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseCombatWeapon_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseCombatWeapon_ClassReg,
           pNetworkName: "CBaseCombatWeapon",
           pTable: &DT_BaseCombatWeapon::g_SendTable);
}
