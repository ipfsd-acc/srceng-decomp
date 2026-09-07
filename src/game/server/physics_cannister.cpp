// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_cannister.cpp
// Functions: 43
// ============================================================

#include "game\server\physics_cannister.h"

//------------------------------------------------------------------------------
// Address: 0x10163240
// Name: public: virtual void CPhysicsCannister::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::Use(
        CGib *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
    ((void (__thiscall *)(CBaseEntity *, CGib *, int))pActivator->__vftable[2].NetworkStateChanged_m_nNextThinkTick)(
      a1: pActivator,
      a2: this,
      a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1018E390
// Name: public: virtual struct datamap_t __near * CPhysicsCannister::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsCannister::GetDataDescMap(CPhysicsCannister *this)
{
  return &CPhysicsCannister::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018E3A0
// Name: public: virtual void CPhysicsCannister::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::OnRestore(CPhysicsCannister *this)
{
  CBaseAnimatingOverlay::OnRestore(this);
  if ( this->m_pController != nullptr )
    this->m_pController->SetEventHandler(this: this->m_pController, a2: &this->m_thruster);
}

//------------------------------------------------------------------------------
// Address: 0x1018E3D0
// Name: private: class Vector CPhysicsCannister::CalcLocalThrust(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsCannister::CalcLocalThrust(CPhysicsCannister *this, Vector *result, const Vector *offset)
{
  CPhysicsCannister_vtbl *v4; // esi
  int v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  matrix3x4_t nozzleMatrix; // [esp+8h] [ebp-30h] BYREF

  v4 = this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v5 = CBaseAnimating::LookupAttachment(this, szName: "nozzle");
  v4->GetAttachment(this, a2: v5, a3: &nozzleMatrix);
  MatrixGetColumn(in: &nozzleMatrix, column: 2, out: result);
  MatrixGetColumn(in: &nozzleMatrix, column: 3, out: &this->m_thrustOrigin);
  v6 = offset->y + (float)(result->y * -5.0);
  v7 = offset->z + (float)(result->z * -5.0);
  result->x = offset->x + (float)(result->x * -5.0);
  result->y = v6;
  result->z = v7;
  VectorNormalize(vec: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018E480
// Name: public: virtual int CPhysicsCannister::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsCannister::ObjectCaps(CFlexCycler *this)
{
  return CBaseEntity::ObjectCaps(this) | 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018E490
// Name: public: virtual bool CPhysicsCannister::ShouldPuntUseLaunchForces(enum PhysGunForce_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsCannister::ShouldPuntUseLaunchForces(CPhysicsCannister *this, PhysGunForce_t reason)
{
  return reason == PHYSGUN_FORCE_LAUNCHED && *(float *)&this->m_Network.m_pServerClass != 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1018E4C0
// Name: public: virtual class Vector CPhysicsCannister::PhysGunLaunchVelocity(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CPhysicsCannister::PhysGunLaunchVelocity(
        CPhysicsCannister *this,
        Vector *result,
        const Vector *forward,
        float flMass)
{
  *result = vec3_origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018E4E0
// Name: public: virtual class QAngle CPhysicsCannister::PreferredCarryAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CPhysicsCannister::PreferredCarryAngles(CPhysicsCannister *this, QAngle *result)
{
  result->x = -90.0;
  result->y = 0.0;
  result->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018E560
// Name: public: virtual void CPhysicsCannister::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::Precache(CPhysicsCannister *this)
{
  string_t *v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  v2 = (string_t *)((int (__thiscall *)(CPhysicsCannister *, _BYTE *))this->GetModelName)(a1: this, a2: v3);
  PropBreakablePrecacheAll(modelName: (string_t)v2->pszValue);
  if ( this->m_gasSound.pszValue != nullptr )
    CBaseEntity::PrecacheScriptSound(soundname: this->m_gasSound.pszValue);
  CBaseCombatCharacter::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018E5D0
// Name: public: virtual enum IMotionEvent::simresult_e CThrustController::Simulate(class IPhysicsMotionController __near *,class IPhysicsObject __near *,float,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThrustController::Simulate(
        CThrustController *this,
        IPhysicsMotionController *pController,
        IPhysicsObject *pObject,
        float deltaTime,
        Vector *linear,
        Vector *angular)
{
  *angular = this->m_torqueVector;
  *linear = this->m_thrustVector;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018E610
// Name: public: virtual bool CPhysicsCannister::CreateVPhysics(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPhysicsCannister::CreateVPhysics(CPhysicsCannister *this)
{
  CBaseEntity::VPhysicsInitNormal(
    this,
    solidType: SOLID_VPHYSICS,
    nSolidFlags: 0,
    createAsleep: this->m_spawnflags.m_Value & 1,
    pSolid: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1018E630
// Name: public: virtual bool CPhysicsCannister::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsCannister::TestCollision(
        CPhysicsCannister *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  bool result; // al
  Vector vecAbsMins; // [esp+Ch] [ebp-18h] BYREF
  Vector vecAbsMaxs; // [esp+18h] [ebp-Ch] BYREF

  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &vecAbsMins,
    pWorldMaxs: &vecAbsMaxs);
  result = IsBoxIntersectingRay(
             boxMin: &vecAbsMins,
             boxMax: &vecAbsMaxs,
             origin: &ray->m_Start,
             vecDelta: &ray->m_Delta,
             flTolerance: 0);
  if ( result )
    return CBaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018E6A0
// Name: public: virtual void CPhysicsCannister::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::OnPhysGunPickup(
        CPhysicsCannister *this,
        CBasePlayer *pPhysGunUser,
        PhysGunPickup_t reason)
{
  float curtime; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( pPhysGunUser != nullptr )
    this->m_aThinkFunctions.m_pElements = (thinkfunc_t *)pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_aThinkFunctions.m_pElements = (thinkfunc_t *)-1;
  *(float *)&this->m_ResponseContexts.m_Memory.m_pMemory = curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1018E700
// Name: public: virtual class CBasePlayer __near * CPhysicsCannister::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CPhysicsCannister::HasPhysicsAttacker(CPhysicsCannister *this, float dt)
{
  unsigned int m_Index; // ecx

  if ( this->m_flLastPhysicsInfluenceTime < (float)(gpGlobals->curtime - dt) )
    return nullptr;
  m_Index = this->m_hPhysicsAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1018E760
// Name: public: CPhysicsCannister::CPhysicsCannister(void)
// Source: json
//------------------------------------------------------------------------------
CPhysicsCannister *__thiscall CPhysicsCannister::CPhysicsCannister(CPhysicsCannister *this)
{
  CBaseCombatCharacter::CBaseCombatCharacter(this);
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CPhysicsCannister_vtbl *)&CPhysicsCannister::`vftable'{for `CBaseCombatCharacter'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CPhysicsCannister::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_thruster.__vftable = (CThrustController_vtbl *)&CThrustController::`vftable';
  this->m_onActivate.m_Value.iVal = 0;
  this->m_onActivate.m_Value.eVal.m_Index = -1;
  this->m_onActivate.m_Value.fieldType = FIELD_VOID;
  this->m_OnAwakened.m_Value.iVal = 0;
  this->m_OnAwakened.m_Value.eVal.m_Index = -1;
  this->m_OnAwakened.m_Value.fieldType = FIELD_VOID;
  this->m_hPhysicsAttacker.m_Index = -1;
  this->m_hLauncher.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1018E7D0
// Name: public: virtual void CPhysicsCannister::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::Spawn(CPhysicsCannister *this)
{
  const char *v2; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  CGlobalVars *v4; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  bool (__thiscall *CreateVPhysics)(CBaseEntity *); // edx
  _BYTE v9[4]; // [esp+1Ch] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CPhysicsCannister *, _BYTE *))this->GetModelName)(a1: this, a2: v9);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CBaseCombatCharacter::SetBloodColor(this, nBloodColor: -1);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 1);
  if ( this->m_takedamage.m_Value != 2 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 2;
  }
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value <= 0 && p_m_iHealth->m_Value != 25 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = 25;
  }
  v4 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v4->curtime;
  }
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  CreateVPhysics = this->CreateVPhysics;
  this->m_bFired = false;
  this->m_active = false;
  CreateVPhysics(this);
  if ( this->m_pPhysicsObject == nullptr )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1018E980
// Name: public: void CPhysicsCannister::ShutdownJet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::ShutdownJet(CPhysicsCannister *this)
{
  CSteamJet *m_pJet; // esi
  CBaseEdict *v3; // ecx
  CSteamJet *v4; // esi
  CBaseEdict *v5; // ecx

  CEventQueue::AddEvent(
    this: &g_EventQueue,
    target: this->m_pJet,
    action: "kill",
    fireDelay: 5.0,
    pActivator: nullptr,
    pCaller: nullptr,
    outputID: 0);
  m_pJet = this->m_pJet;
  if ( m_pJet->m_bEmit.m_Value != 0 )
  {
    if ( m_pJet->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&m_pJet->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = &m_pJet->m_Network.m_pPev->CBaseEdict;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: v3, offset: 0x36Cu);
    }
    m_pJet->m_bEmit.m_Value = 0;
  }
  v4 = this->m_pJet;
  if ( v4->m_Rate.m_Value != 0.0 )
  {
    if ( v4->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v4->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &v4->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: 0x364u);
    }
    v4->m_Rate.m_Value = 0.0;
  }
  this->m_pJet = nullptr;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1018EA60
// Name: public: void CPhysicsCannister::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::Deactivate(CPhysicsCannister *this)
{
  IPhysicsMotionController *m_pController; // ecx
  bool v3; // zf
  const char *pszValue; // eax
  edict_t *m_pPev; // esi

  m_pController = this->m_pController;
  if ( m_pController != nullptr )
  {
    m_pController->DetachObject(this: m_pController, a2: this->m_pPhysicsObject);
    physenv->DestroyMotionController(this: physenv, a2: this->m_pController);
    this->m_pController = nullptr;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    v3 = this->m_pJet == nullptr;
    this->m_thrustTime = 0.0;
    this->m_active = false;
    if ( !v3 )
      CPhysicsCannister::ShutdownJet(this);
    if ( this->m_gasSound.pszValue != nullptr )
    {
      pszValue = this->m_gasSound.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEntity::StopSound(
          iEntIndex: m_pPev - gpGlobals->pEdicts,
          iChannel: 3,
          pSample: pszValue,
          bIsStoppingSpeakerSound: 0);
      else
        CBaseEntity::StopSound(iEntIndex: 0, iChannel: 3, pSample: pszValue, bIsStoppingSpeakerSound: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EB20
// Name: public: void CPhysicsCannister::Explode(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::Explode(CPhysicsCannister *this, CBaseEntity *pAttacker)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // edi
  void (__thiscall *GetVelocity)(IPhysicsObject *, Vector *, Vector *); // eax
  int v5; // eax
  IPhysicsObject *v6; // [esp-8h] [ebp-50h]
  Vector velocity; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector angVelocity; // [esp+38h] [ebp-10h] BYREF
  IPhysicsObject *pPhysics; // [esp+44h] [ebp-4h]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  p_m_takedamage = &this->m_takedamage;
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    p_m_takedamage->m_Value = 0;
  }
  CPhysicsCannister::Deactivate(this);
  GetVelocity = this->m_pPhysicsObject->GetVelocity;
  pPhysics = this->m_pPhysicsObject;
  ((void (__stdcall *)(Vector *, Vector *))GetVelocity)(a1: &velocity, a2: &angVelocity);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v6 = pPhysics;
  v5 = this->GetModelIndex(this);
  PropBreakableCreateAll(
    modelindex: v5,
    pPhysics: v6,
    origin: &this->m_vecAbsOrigin,
    angles: &this->m_angAbsRotation,
    &velocity,
    angularVelocity: &angVelocity,
    impactEnergyScale: 1.0,
    defBurstScale: 20.0,
    defCollisionGroup: 1,
    pEntity: nullptr,
    defaultLocation: true);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ExplosionCreate(
    center: &this->m_vecAbsOrigin,
    angles: &this->m_angAbsRotation,
    pOwner: pAttacker,
    magnitude: (int)this->m_damage,
    radius: 0,
    doDamage: true,
    flExplosionForce: 0.0,
    bSurfaceOnly: false,
    bSilent: false,
    iCustomDamageType: 0xFFFFFFFF);
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1018EC50
// Name: public: void CPhysicsCannister::ExplodeTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::ExplodeTouch(CPhysicsCannister *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // edx

  if ( pOther->m_takedamage.m_Value != 0 )
  {
    m_Index = this->m_hLauncher.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      CPhysicsCannister::Explode(this, pAttacker: nullptr);
    else
      CPhysicsCannister::Explode(
        this,
        pAttacker: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ECA0
// Name: public: virtual void CPhysicsCannister::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::VPhysicsCollision(
        CPhysicsCannister *this,
        surfacedata_t *index,
        CBaseEntity *pEvent)
{
  CBaseEntity *v4; // eax

  if ( !this->m_bFired || !this->m_active )
  {
LABEL_7:
    CBaseEntity::VPhysicsCollision(this, index, pEvent);
    return;
  }
  if ( *(float *)&pEvent->m_Network.m_pOuter >= 0.5
    || *((CPhysicsCannister **)&pEvent->m_flSimulationTime.m_Value + (index == nullptr)) != this )
  {
    if ( *(float *)&pEvent->m_Network.m_pPev > 1000.0 )
    {
      v4 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_hLauncher);
      CPhysicsCannister::Explode(this, pAttacker: v4);
      return;
    }
    goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018ED10
// Name: public: void CPhysicsCannister::BeginShutdownThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysicsCannister::BeginShutdownThink(CPhysicsCannister *this)
{
  CPhysicsCannister::Deactivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018ED20
// Name: public: virtual void CPhysicsCannister::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::VPhysicsUpdate(CPhysicsCannister *this, IPhysicsObject *pPhysics)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  unsigned int v4; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v5; // eax
  CBaseEdict *m_Value; // ecx

  CBaseCombatCharacter::VPhysicsUpdate(this, pPhysics);
  p_m_spawnflags = &this->m_spawnflags;
  if ( (this->m_spawnflags.m_Value & 1) != 0 && !pPhysics->IsAsleep(this: pPhysics) )
  {
    COutputEvent::FireOutput(this: &this->m_OnAwakened, pActivator: this, pCaller: this, fDelay: 0.0);
    v4 = p_m_spawnflags->m_Value & 0xFFFFFFFE;
    if ( p_m_spawnflags->m_Value != v4 )
    {
      v5 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v5[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v4;
      }
      else
      {
        m_Value = (CBaseEdict *)v5[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018EE70
// Name: public: void CPhysicsCannister::CannisterActivate(class CBaseEntity __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsCannister::CannisterActivate(
        CPhysicsCannister *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CBaseEntity *pActivator,
        const Vector *thrustOffset)
{
  float m_thrust; // xmm0_4
  IPhysicsObject *m_pPhysicsObject; // edi
  float (__thiscall *GetMass)(IPhysicsObject *); // edx
  void (__thiscall *CalculateVelocityOffset)(IPhysicsObject *, const Vector *, const Vector *, Vector *, Vector *); // edx
  IPhysicsMotionController *v10; // eax
  IPhysicsObject *v11; // edi
  CBaseEntity *v12; // eax
  CSteamJet *v13; // eax
  float v14; // xmm0_4
  CSteamJet *m_pJet; // edi
  float v16; // xmm0_4
  CBaseEdict *v17; // ecx
  CSteamJet *v18; // edi
  float v19; // xmm0_4
  CBaseEdict *v20; // ecx
  CSteamJet *v21; // edi
  CBaseEdict *v22; // ecx
  CSteamJet *v23; // edi
  CBaseEdict *v24; // ecx
  CSteamJet *v25; // edi
  float v26; // xmm0_4
  CBaseEdict *v27; // ecx
  CSteamJet *v28; // edi
  CBaseEdict *v29; // ecx
  const char *pszValue; // eax
  edict_t *m_pPev; // esi
  int thinkTime; // [esp+38h] [ebp-A4h]
  int attenuation; // [esp+3Ch] [ebp-A0h]
  CPASAttenuationFilter filter; // [esp+44h] [ebp-98h] BYREF
  EmitSound_t ep; // [esp+64h] [ebp-78h] BYREF
  QAngle angles; // [esp+ACh] [ebp-30h] BYREF
  float v37; // [esp+B8h] [ebp-24h]
  float v38; // [esp+BCh] [ebp-20h]
  float v39; // [esp+C0h] [ebp-1Ch]
  Vector thrustDirection; // [esp+C4h] [ebp-18h] BYREF
  Vector forward; // [esp+D0h] [ebp-Ch] BYREF
  float pActivatorb; // [esp+E4h] [ebp+8h]
  float pActivatora; // [esp+E4h] [ebp+8h]

  if ( !this->m_active && this->m_thrustTime != 0.0 )
  {
    attenuation = a2;
    thinkTime = a3;
    if ( pActivator != nullptr )
      this->m_hLauncher.m_Index = *(_DWORD *)((int (__thiscall *)(CBaseEntity *, int, int))pActivator->GetRefEHandle)(
                                               a1: pActivator,
                                               a2: a3,
                                               a3: a2);
    else
      this->m_hLauncher.m_Index = -1;
    CPhysicsCannister::CalcLocalThrust(this, result: &thrustDirection, offset: thrustOffset);
    COutputEvent::FireOutput(this: &this->m_onActivate, pActivator, pCaller: this, fDelay: 0.0);
    m_thrust = this->m_thruster.m_thrust;
    m_pPhysicsObject = this->m_pPhysicsObject;
    GetMass = m_pPhysicsObject->GetMass;
    v37 = thrustDirection.x * m_thrust;
    v38 = thrustDirection.y * m_thrust;
    v39 = thrustDirection.z * m_thrust;
    pActivatorb = ((double (__thiscall *)(IPhysicsObject *, int, int))GetMass)(
                    a1: m_pPhysicsObject,
                    a2: thinkTime,
                    a3: attenuation);
    CalculateVelocityOffset = m_pPhysicsObject->CalculateVelocityOffset;
    forward.x = v37 * pActivatorb;
    forward.y = v38 * pActivatorb;
    forward.z = v39 * pActivatorb;
    CalculateVelocityOffset(
      this: m_pPhysicsObject,
      a2: &forward,
      a3: &this->m_thrustOrigin,
      a4: &this->m_thruster.m_thrustVector,
      a5: &this->m_thruster.m_torqueVector);
    m_pPhysicsObject->WorldToLocalVector(
      this: m_pPhysicsObject,
      a2: &this->m_thruster.m_thrustVector,
      a3: &this->m_thruster.m_thrustVector);
    v10 = physenv->CreateMotionController(this: physenv, a2: &this->m_thruster);
    v11 = this->m_pPhysicsObject;
    this->m_pController = v10;
    v10->AttachObject(this: v10, a2: v11, a3: true);
    v11->Wake(this: v11);
    this->m_active = true;
    this->m_activateTime = gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_thrustTime, szContext: nullptr);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CPhysicsCannister::BeginShutdownThink,
      thinkTime: 0.0,
      szContext: nullptr);
    forward.x = -thrustDirection.x;
    forward.y = -thrustDirection.y;
    forward.z = -thrustDirection.z;
    VectorAngles(&forward, &angles);
    v12 = CBaseEntity::Create(szName: "env_steam", vecOrigin: &this->m_thrustOrigin, vecAngles: &angles, pOwner: this);
    v13 = (CSteamJet *)__RTDynamicCast(
                         inptr: v12,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CSteamJet `RTTI Type Descriptor',
                         isReference: 0);
    this->m_pJet = v13;
    v13->SetParent(this: v13, a2: this, a3: -1);
    v14 = this->m_thruster.m_thrust * 0.00019999999;
    if ( v14 >= 0.0 )
    {
      if ( v14 <= 1.0 )
        pActivatora = this->m_thruster.m_thrust * 0.00019999999;
      else
        pActivatora = 1.0;
    }
    else
    {
      pActivatora = 0.0;
    }
    m_pJet = this->m_pJet;
    v16 = (float)(this->m_thruster.m_thrust * 15.0) * 0.001;
    if ( m_pJet->m_SpreadSpeed.m_Value != v16 )
    {
      if ( m_pJet->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pJet->m_Network + 76) |= 1u;
      }
      else
      {
        v17 = &m_pJet->m_Network.m_pPev->CBaseEdict;
        if ( v17 != nullptr )
          CBaseEdict::StateChanged(this: v17, offset: 0x354u);
      }
      m_pJet->m_SpreadSpeed.m_Value = v16;
    }
    v18 = this->m_pJet;
    v19 = (float)(pActivatora * 100.0) + 128.0;
    if ( v18->m_Speed.m_Value != v19 )
    {
      if ( v18->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v18->m_Network + 76) |= 1u;
      }
      else
      {
        v20 = &v18->m_Network.m_pPev->CBaseEdict;
        if ( v20 != nullptr )
        {
          CBaseEdict::StateChanged(this: v20, offset: 0x358u);
          v19 = (float)(pActivatora * 100.0) + 128.0;
        }
      }
      v18->m_Speed.m_Value = v19;
    }
    v21 = this->m_pJet;
    if ( v21->m_StartSize.m_Value != 10.0 )
    {
      if ( v21->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v21->m_Network + 76) |= 1u;
      }
      else
      {
        v22 = &v21->m_Network.m_pPev->CBaseEdict;
        if ( v22 != nullptr )
          CBaseEdict::StateChanged(this: v22, offset: 0x35Cu);
      }
      v21->m_StartSize.m_Value = 10.0;
    }
    v23 = this->m_pJet;
    if ( v23->m_EndSize.m_Value != 25.0 )
    {
      if ( v23->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v23->m_Network + 76) |= 1u;
      }
      else
      {
        v24 = &v23->m_Network.m_pPev->CBaseEdict;
        if ( v24 != nullptr )
          CBaseEdict::StateChanged(this: v24, offset: 0x360u);
      }
      v23->m_EndSize.m_Value = 25.0;
    }
    v25 = this->m_pJet;
    v26 = (float)(20 * (int)pActivatora + 52);
    if ( v25->m_Rate.m_Value != v26 )
    {
      if ( v25->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v25->m_Network + 76) |= 1u;
      }
      else
      {
        v27 = &v25->m_Network.m_pPev->CBaseEdict;
        if ( v27 != nullptr )
          CBaseEdict::StateChanged(this: v27, offset: 0x364u);
      }
      v25->m_Rate.m_Value = v26;
    }
    v28 = this->m_pJet;
    if ( v28->m_JetLength.m_Value != 64.0 )
    {
      if ( v28->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v28->m_Network + 76) |= 1u;
      }
      else
      {
        v29 = &v28->m_Network.m_pPev->CBaseEdict;
        if ( v29 != nullptr )
          CBaseEdict::StateChanged(this: v29, offset: 0x368u);
      }
      v28->m_JetLength.m_Value = 64.0;
    }
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::operator=(
      this: &this->m_pJet->m_clrRender,
      val: &this->m_clrRender);
    ((void (__stdcall *)(CPhysicsCannister *, CPhysicsCannister *))this->m_pJet->Use)(a1: this, a2: this);
    if ( this->m_gasSound.pszValue != nullptr )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
      EmitSound_t::EmitSound_t(this: &ep);
      pszValue = this->m_gasSound.pszValue;
      ep.m_nChannel = 3;
      ep.m_pSoundName = pszValue;
      if ( pszValue == nullptr )
        ep.m_pSoundName = locale;
      m_pPev = this->m_Network.m_pPev;
      ep.m_flVolume = 1.0;
      ep.m_SoundLevel = SNDLVL_NORM;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      CBaseEntity::EmitSound(&filter, iEntIndex: (int)m_pPev, params: &ep);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018F3C0
// Name: public: void CPhysicsCannister::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsCannister::InputActivate(
        CPhysicsCannister *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        inputdata_t *data)
{
  CBaseEntity *pActivator; // eax
  Vector thrustOffset; // [esp+0h] [ebp-Ch] BYREF

  thrustOffset.x = 0.0;
  pActivator = data->pActivator;
  thrustOffset.y = 0.1;
  thrustOffset.z = -0.25;
  CPhysicsCannister::CannisterActivate(this, a2, a3, pActivator, &thrustOffset);
}

//------------------------------------------------------------------------------
// Address: 0x1018F400
// Name: public: void CPhysicsCannister::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CPhysicsCannister::InputDeactivate(CPhysicsCannister *this, inputdata_t *data)
{
  CPhysicsCannister::Deactivate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1018F410
// Name: public: void CPhysicsCannister::InputExplode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::InputExplode(CPhysicsCannister *this, inputdata_t *data)
{
  CPhysicsCannister::Explode(this, pAttacker: data->pActivator);
}

//------------------------------------------------------------------------------
// Address: 0x1018F430
// Name: public: virtual void CPhysicsCannister::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsCannister::OnPhysGunDrop(
        CPhysicsCannister *this@<ecx>,
        int a2@<ebx>,
        CBasePlayer *pPhysGunUser,
        PhysGunDrop_t Reason)
{
  CPhysicsCannister *v4; // esi
  float curtime; // [esp+0h] [ebp-4h]

  curtime = gpGlobals->curtime;
  v4 = (CPhysicsCannister *)((char *)this - 2284);
  if ( pPhysGunUser != nullptr )
    v4->m_hPhysicsAttacker.m_Index = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    v4->m_hPhysicsAttacker.m_Index = -1;
  v4->m_flLastPhysicsInfluenceTime = curtime;
  if ( Reason == LAUNCHED_BY_CANNON )
    CPhysicsCannister::CannisterActivate(
      this: v4,
      a2,
      a3: (int)pPhysGunUser,
      pActivator: pPhysGunUser,
      thrustOffset: &vec3_origin);
}

//------------------------------------------------------------------------------
// Address: 0x1018FEA0
// Name: public: virtual int CPhysicsCannister::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPhysicsCannister::OnTakeDamage(CPhysicsCannister *this, const CTakeDamageInfo *info)
{
  CPhysicsCannister *v2; // edx
  int m_Value; // eax
  int m_flDamage; // ecx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // edi
  int v6; // esi
  unsigned int m_Index; // ecx
  int m_bitsDamageType; // eax
  CBaseEntity *v10; // eax
  CBaseEntity *Attacker; // eax

  v2 = this;
  if ( this->m_takedamage.m_Value == 0 )
    return 0;
  if ( this->m_active )
  {
    if ( (float)(gpGlobals->curtime - this->m_activateTime) > 0.1 && (info->m_bitsDamageType & 0x2000004A) != 0 )
    {
      Attacker = CTakeDamageInfo::GetAttacker(this: info);
      CPhysicsCannister::Explode(this, pAttacker: Attacker);
    }
    return 0;
  }
  m_Value = this->m_iHealth.m_Value;
  m_flDamage = (int)info->m_flDamage;
  p_m_iHealth = &v2->m_iHealth;
  v6 = m_Value - m_flDamage;
  if ( m_Value != m_Value - m_flDamage )
  {
    v2->NetworkStateChanged_m_iHealth(this: v2, a2: &v2->m_iHealth);
    v2 = this;
    p_m_iHealth->m_Value = v6;
  }
  if ( p_m_iHealth->m_Value >= 0 )
  {
    m_bitsDamageType = info->m_bitsDamageType;
    if ( (m_bitsDamageType & 0x40) != 0
      || (m_bitsDamageType & 0x85) != 0 && random->RandomInt(this: random, a2: 1, a3: 100) < 50 )
    {
      v10 = CTakeDamageInfo::GetAttacker(this: info);
      CPhysicsCannister::CannisterActivate(
        this,
        a2: (int)info,
        a3: (int)p_m_iHealth,
        pActivator: v10,
        thrustOffset: &g_vecAttackDir);
    }
    return 1;
  }
  else
  {
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      CPhysicsCannister::Explode(this: v2, pAttacker: nullptr);
      return 1;
    }
    else
    {
      CPhysicsCannister::Explode(
        this: v2,
        pAttacker: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity);
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018FFE0
// Name: public: virtual void CPhysicsCannister::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsCannister::TraceAttack(
        CPhysicsCannister *this,
        const CTakeDamageInfo *info,
        const Vector *dir,
        CGameTrace *ptr)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  Vector direction; // [esp+Ch] [ebp-Ch] BYREF

  if ( !this->m_active && ptr->hitgroup != 0 )
  {
    direction.x = -dir->x;
    direction.y = -dir->y;
    direction.z = (float)-dir->z - 5.0;
    VectorNormalize(vec: &direction);
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CPhysicsCannister::CannisterActivate(
      this,
      a2: (int)info,
      a3: (int)dir,
      pActivator: m_pEntity,
      thrustOffset: &direction);
  }
  CBaseEntity::TraceAttack(this, info, vecDir: dir, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10407340
// Name: CThrustController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CThrustController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CThrustController>();
  CThrustController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407370
// Name: CPhysicsCannister_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsCannister_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsCannister>(__formal: nullptr);
  CPhysicsCannister_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1018F4A0
// Name: struct datamap_t __near * DataMapInit<class CPhysicsCannister>(class CPhysicsCannister __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsCannister>()
{
  if ( (_S3_88 & 1) == 0 )
  {
    _S3_88 |= 1u;
    nameHolder_308.m_pszBase = "CPhysicsCannister";
    nameHolder_308.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_308.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_308.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_308.m_Names.m_Size = 0;
    nameHolder_308.m_Names.m_pElements = nullptr;
    nameHolder_308.m_nLenBase = 17;
    atexit(func: DataMapInit_CPhysicsCannister__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsCannister::m_DataMap.baseMap = &CBaseCombatCharacter::m_DataMap;
  if ( (_S3_88 & 2) == 0 )
  {
    _S3_88 |= 2u;
    *(_QWORD *)&dataDesc_295[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_295[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_295[1].override_count = 0;
    *(_QWORD *)dataDesc_295[1].flatOffset = 0;
    *(_QWORD *)&dataDesc_295[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_295[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_295[2].override_count = 0;
    *(_QWORD *)dataDesc_295[2].flatOffset = 0;
    dataDesc_295[2].fieldSize = 1;
    dataDesc_295[2].flags = 22;
    dataDesc_295[1].pSaveRestoreOps = eventFuncs;
    dataDesc_295[2].fieldType = FIELD_CUSTOM;
    dataDesc_295[2].pSaveRestoreOps = eventFuncs;
    dataDesc_295[5].fieldType = FIELD_CUSTOM;
    dataDesc_295[3].fieldTolerance = 0.0;
    dataDesc_295[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[1].flatGroup = 0;
    dataDesc_295[2].fieldName = "m_OnAwakened";
    dataDesc_295[2].fieldOffset = 2392;
    dataDesc_295[2].externalName = "OnAwakened";
    *(_DWORD *)&dataDesc_295[2].flatGroup = 0;
    dataDesc_295[3].fieldType = FIELD_VECTOR;
    dataDesc_295[3].fieldName = "m_thrustOrigin";
    dataDesc_295[3].fieldOffset = 2288;
    dataDesc_295[3].fieldSize = 1;
    dataDesc_295[3].flags = 2;
    dataDesc_295[3].externalName = nullptr;
    dataDesc_295[3].pSaveRestoreOps = nullptr;
    dataDesc_295[3].inputFunc = nullptr;
    dataDesc_295[3].td = nullptr;
    dataDesc_295[3].fieldSizeInBytes = 12;
    dataDesc_295[3].override_field = nullptr;
    dataDesc_295[3].override_count = 0;
    *(_QWORD *)dataDesc_295[3].flatOffset = 0;
    *(_DWORD *)&dataDesc_295[3].flatGroup = 0;
    dataDesc_295[4].fieldType = FIELD_EMBEDDED;
    dataDesc_295[4].fieldName = "m_thruster";
    dataDesc_295[4].fieldOffset = 2300;
    dataDesc_295[4].fieldSize = 1;
    dataDesc_295[4].flags = 2;
    dataDesc_295[4].externalName = nullptr;
    dataDesc_295[4].pSaveRestoreOps = nullptr;
    dataDesc_295[4].inputFunc = nullptr;
    dataDesc_295[4].td = &CThrustController::m_DataMap;
    dataDesc_295[4].fieldSizeInBytes = 32;
    dataDesc_295[4].override_field = nullptr;
    dataDesc_295[4].override_count = 0;
    *(_QWORD *)dataDesc_295[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_295[4].flatGroup = 0;
    dataDesc_295[5].fieldName = "m_pController";
    dataDesc_295[5].fieldOffset = 2332;
    dataDesc_295[5].fieldSize = 1;
    dataDesc_295[5].flags = 2;
    dataDesc_295[5].externalName = nullptr;
    dataDesc_295[5].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    dataDesc_295[5].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_295[5].td = 0;
    *(_QWORD *)&dataDesc_295[5].override_field = 0;
    *(_QWORD *)&dataDesc_295[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[5].flatOffset[1] = 0;
    dataDesc_295[6].fieldType = FIELD_CLASSPTR;
    dataDesc_295[6].fieldName = "m_pJet";
    dataDesc_295[6].fieldSize = 1;
    dataDesc_295[7].fieldSize = 1;
    dataDesc_295[7].flags = 2;
    dataDesc_295[8].fieldSize = 1;
    dataDesc_295[8].flags = 6;
    dataDesc_295[9].fieldSize = 1;
    *(_QWORD *)dataDesc_295[6].flatOffset = 0;
    dataDesc_295[9].flags = 6;
    *(_QWORD *)dataDesc_295[7].flatOffset = 0;
    dataDesc_295[6].flags = 2;
    dataDesc_295[10].fieldSize = 1;
    *(_QWORD *)dataDesc_295[8].flatOffset = 0;
    dataDesc_295[6].fieldOffset = 2336;
    dataDesc_295[6].externalName = nullptr;
    dataDesc_295[6].pSaveRestoreOps = nullptr;
    dataDesc_295[6].inputFunc = nullptr;
    dataDesc_295[6].td = nullptr;
    dataDesc_295[6].fieldSizeInBytes = 4;
    dataDesc_295[6].override_field = nullptr;
    dataDesc_295[6].override_count = 0;
    dataDesc_295[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[6].flatGroup = 0;
    dataDesc_295[7].fieldType = FIELD_BOOLEAN;
    dataDesc_295[7].fieldName = "m_active";
    dataDesc_295[7].fieldOffset = 2340;
    dataDesc_295[7].externalName = nullptr;
    dataDesc_295[7].pSaveRestoreOps = nullptr;
    dataDesc_295[7].inputFunc = nullptr;
    dataDesc_295[7].td = nullptr;
    dataDesc_295[7].fieldSizeInBytes = 1;
    dataDesc_295[7].override_field = nullptr;
    dataDesc_295[7].override_count = 0;
    dataDesc_295[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[7].flatGroup = 0;
    dataDesc_295[8].fieldType = FIELD_FLOAT;
    dataDesc_295[8].fieldName = "m_thrustTime";
    dataDesc_295[8].fieldOffset = 2344;
    dataDesc_295[8].externalName = "fuel";
    dataDesc_295[8].pSaveRestoreOps = nullptr;
    dataDesc_295[8].inputFunc = nullptr;
    dataDesc_295[8].td = nullptr;
    dataDesc_295[8].fieldSizeInBytes = 4;
    dataDesc_295[8].override_field = nullptr;
    dataDesc_295[8].override_count = 0;
    dataDesc_295[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[8].flatGroup = 0;
    dataDesc_295[9].fieldType = FIELD_FLOAT;
    dataDesc_295[9].fieldName = "m_damage";
    dataDesc_295[9].fieldOffset = 2348;
    dataDesc_295[9].externalName = "expdamage";
    dataDesc_295[9].pSaveRestoreOps = nullptr;
    dataDesc_295[9].inputFunc = nullptr;
    dataDesc_295[9].td = nullptr;
    dataDesc_295[9].fieldSizeInBytes = 4;
    dataDesc_295[9].override_field = nullptr;
    dataDesc_295[9].override_count = 0;
    dataDesc_295[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_295[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_295[9].flatGroup = 0;
    dataDesc_295[10].fieldType = FIELD_FLOAT;
    dataDesc_295[10].fieldName = "m_damageRadius";
    dataDesc_295[10].fieldOffset = 2352;
    dataDesc_295[10].flags = 6;
    dataDesc_295[10].externalName = "expradius";
    dataDesc_295[10].pSaveRestoreOps = nullptr;
    dataDesc_295[11].fieldSize = 1;
    dataDesc_295[11].flags = 2;
    dataDesc_295[12].fieldSize = 1;
    dataDesc_295[13].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_295[10].flatOffset = 0;
    *(_QWORD *)dataDesc_295[11].flatOffset = 0;
    dataDesc_295[12].flags = 6;
    dataDesc_295[13].fieldSize = 1;
    *(_QWORD *)dataDesc_295[12].flatOffset = 0;
    dataDesc_295[13].flags = 2;
    dataDesc_295[14].fieldSize = 1;
    *(_QWORD *)dataDesc_295[13].flatOffset = 0;
    dataDesc_295[10].inputFunc = nullptr;
    dataDesc_295[10].td = nullptr;
    dataDesc_295[10].fieldSizeInBytes = 4;
    dataDesc_295[10].override_field = nullptr;
    dataDesc_295[10].override_count = 0;
    dataDesc_295[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[10].flatGroup = 0;
    dataDesc_295[11].fieldType = FIELD_TIME;
    dataDesc_295[11].fieldName = "m_activateTime";
    dataDesc_295[11].fieldOffset = 2356;
    dataDesc_295[11].externalName = nullptr;
    dataDesc_295[11].pSaveRestoreOps = nullptr;
    dataDesc_295[11].inputFunc = nullptr;
    dataDesc_295[11].td = nullptr;
    dataDesc_295[11].fieldSizeInBytes = 4;
    dataDesc_295[11].override_field = nullptr;
    dataDesc_295[11].override_count = 0;
    dataDesc_295[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[11].flatGroup = 0;
    dataDesc_295[12].fieldType = FIELD_SOUNDNAME;
    dataDesc_295[12].fieldName = "m_gasSound";
    dataDesc_295[12].fieldOffset = 2360;
    dataDesc_295[12].externalName = "gassound";
    dataDesc_295[12].pSaveRestoreOps = nullptr;
    dataDesc_295[12].inputFunc = nullptr;
    dataDesc_295[12].td = nullptr;
    dataDesc_295[12].fieldSizeInBytes = 4;
    dataDesc_295[12].override_field = nullptr;
    dataDesc_295[12].override_count = 0;
    dataDesc_295[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[12].flatGroup = 0;
    dataDesc_295[13].fieldName = "m_bFired";
    dataDesc_295[13].fieldOffset = 2364;
    dataDesc_295[13].externalName = nullptr;
    dataDesc_295[13].pSaveRestoreOps = nullptr;
    dataDesc_295[13].inputFunc = nullptr;
    dataDesc_295[13].td = nullptr;
    dataDesc_295[13].fieldSizeInBytes = 1;
    dataDesc_295[13].override_field = nullptr;
    dataDesc_295[13].override_count = 0;
    dataDesc_295[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_295[13].flatGroup = 0;
    dataDesc_295[14].fieldType = FIELD_EHANDLE;
    dataDesc_295[14].fieldName = "m_hPhysicsAttacker";
    dataDesc_295[14].fieldOffset = 2416;
    dataDesc_295[14].flags = 2;
    dataDesc_295[14].externalName = nullptr;
    dataDesc_295[14].pSaveRestoreOps = nullptr;
    dataDesc_295[14].inputFunc = nullptr;
    dataDesc_295[14].td = nullptr;
    dataDesc_295[14].fieldSizeInBytes = 4;
    dataDesc_295[14].override_field = nullptr;
    dataDesc_295[14].override_count = 0;
    dataDesc_295[14].fieldTolerance = 0.0;
    dataDesc_295[15].fieldType = FIELD_TIME;
    dataDesc_295[16].fieldType = FIELD_EHANDLE;
    dataDesc_295[15].fieldSize = 1;
    dataDesc_295[15].fieldTolerance = 0.0;
    dataDesc_295[16].fieldTolerance = 0.0;
    dataDesc_295[15].fieldSizeInBytes = 4;
    dataDesc_295[16].fieldSizeInBytes = 4;
    dataDesc_295[16].fieldSize = 1;
    *(_QWORD *)dataDesc_295[16].flatOffset = 0;
    dataDesc_295[15].flags = 2;
    dataDesc_295[16].flags = 2;
    dataDesc_295[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_295[17].td = 0;
    *(_QWORD *)&dataDesc_295[17].override_field = 0;
    *(_QWORD *)&dataDesc_295[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[17].flatOffset[1] = 0;
    dataDesc_295[17].flags = 8;
    dataDesc_295[18].fieldSize = 1;
    *(_QWORD *)dataDesc_295[14].flatOffset = 0;
    *(_QWORD *)&dataDesc_295[18].td = 0;
    *(_QWORD *)&dataDesc_295[18].override_field = 0;
    *(_QWORD *)&dataDesc_295[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[18].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_295[14].flatGroup = 0;
    dataDesc_295[15].fieldName = "m_flLastPhysicsInfluenceTime";
    dataDesc_295[15].fieldOffset = 2420;
    dataDesc_295[15].externalName = nullptr;
    dataDesc_295[15].pSaveRestoreOps = nullptr;
    dataDesc_295[15].inputFunc = nullptr;
    dataDesc_295[15].td = nullptr;
    dataDesc_295[15].override_field = nullptr;
    dataDesc_295[15].override_count = 0;
    *(_QWORD *)dataDesc_295[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_295[15].flatGroup = 0;
    dataDesc_295[16].fieldName = "m_hLauncher";
    dataDesc_295[16].fieldOffset = 2424;
    dataDesc_295[16].externalName = nullptr;
    dataDesc_295[16].pSaveRestoreOps = nullptr;
    dataDesc_295[16].inputFunc = nullptr;
    dataDesc_295[16].td = nullptr;
    dataDesc_295[16].override_field = nullptr;
    dataDesc_295[16].override_count = 0;
    *(_DWORD *)&dataDesc_295[16].flatGroup = 0;
    dataDesc_295[17].fieldType = FIELD_VOID;
    dataDesc_295[17].fieldName = "InputActivate";
    dataDesc_295[17].fieldOffset = 0;
    dataDesc_295[17].externalName = "Activate";
    dataDesc_295[17].pSaveRestoreOps = nullptr;
    dataDesc_295[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsCannister::InputActivate;
    dataDesc_295[18].fieldType = FIELD_VOID;
    dataDesc_295[18].fieldName = "InputDeactivate";
    dataDesc_295[18].fieldOffset = 0;
    dataDesc_295[18].flags = 8;
    dataDesc_295[18].externalName = "Deactivate";
    dataDesc_295[18].pSaveRestoreOps = nullptr;
    dataDesc_295[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsCannister::InputDeactivate;
    dataDesc_295[19].fieldType = FIELD_VOID;
    dataDesc_295[19].fieldName = "InputExplode";
    dataDesc_295[19].fieldOffset = 0;
    dataDesc_295[19].fieldSize = 1;
    dataDesc_295[19].flags = 8;
    dataDesc_295[19].externalName = "Explode";
    dataDesc_295[19].pSaveRestoreOps = nullptr;
    dataDesc_295[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsCannister::InputExplode;
    *(_QWORD *)&dataDesc_295[19].td = 0;
    *(_QWORD *)&dataDesc_295[19].override_field = 0;
    *(_QWORD *)&dataDesc_295[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[19].flatOffset[1] = 0;
    dataDesc_295[20].flags = 8;
    dataDesc_295[20].fieldType = FIELD_VOID;
    dataDesc_295[20].fieldName = "InputWake";
    dataDesc_295[20].fieldOffset = 0;
    dataDesc_295[20].fieldSize = 1;
    dataDesc_295[20].externalName = "Wake";
    dataDesc_295[20].pSaveRestoreOps = nullptr;
    dataDesc_295[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsProp::InputWake;
    *(_QWORD *)&dataDesc_295[20].td = 0;
    *(_QWORD *)&dataDesc_295[20].override_field = 0;
    *(_QWORD *)&dataDesc_295[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[20].flatOffset[1] = 0;
    dataDesc_295[21].fieldType = FIELD_VOID;
    dataDesc_295[21].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_308,
                                   pszIdentifier: "BeginShutdownThink");
    dataDesc_295[21].fieldOffset = 0;
    dataDesc_295[21].fieldSize = 1;
    dataDesc_295[21].flags = 32;
    dataDesc_295[21].externalName = nullptr;
    dataDesc_295[21].pSaveRestoreOps = nullptr;
    dataDesc_295[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsCannister::BeginShutdownThink;
    *(_QWORD *)&dataDesc_295[21].td = 0;
    *(_QWORD *)&dataDesc_295[21].override_field = 0;
    *(_QWORD *)&dataDesc_295[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[21].flatOffset[1] = 0;
    dataDesc_295[22].fieldType = FIELD_VOID;
    dataDesc_295[22].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_308,
                                   pszIdentifier: "ExplodeTouch");
    dataDesc_295[22].fieldOffset = 0;
    *(_DWORD *)&dataDesc_295[22].fieldSize = 2097153;
    dataDesc_295[22].externalName = nullptr;
    dataDesc_295[22].pSaveRestoreOps = nullptr;
    dataDesc_295[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPhysicsCannister::ExplodeTouch;
    *(_QWORD *)&dataDesc_295[22].td = 0;
    *(_QWORD *)&dataDesc_295[22].override_field = 0;
    *(_QWORD *)&dataDesc_295[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_295[22].flatOffset[1] = 0;
  }
  CPhysicsCannister::m_DataMap.dataNumFields = 22;
  CPhysicsCannister::m_DataMap.dataDesc = &dataDesc_295[1];
  return &CPhysicsCannister::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10407380
// Name: _dynamic_initializer_for__vprof_think_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_think_limit__()
{
  ConVar::ConVar(this: &vprof_think_limit, pName: "vprof_think_limit", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_think_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x104073B0
// Name: _dynamic_initializer_for__vprof_scope_entity_thinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_scope_entity_thinks__()
{
  ConVar::ConVar(this: &vprof_scope_entity_thinks, pName: "vprof_scope_entity_thinks", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_scope_entity_thinks__);
}

//------------------------------------------------------------------------------
// Address: 0x104073E0
// Name: _dynamic_initializer_for__vprof_scope_entity_gamephys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__vprof_scope_entity_gamephys__()
{
  ConVar::ConVar(this: &vprof_scope_entity_gamephys, pName: "vprof_scope_entity_gamephys", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__vprof_scope_entity_gamephys__);
}

//------------------------------------------------------------------------------
// Address: 0x10407410
// Name: _dynamic_initializer_for__npc_vphysics__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_vphysics__()
{
  ConVar::ConVar(this: &npc_vphysics, pName: "npc_vphysics", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__npc_vphysics__);
}

//------------------------------------------------------------------------------
// Address: 0x10407440
// Name: _dynamic_initializer_for__s_PushedEntities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_PushedEntities__()
{
  CPhysicsPushedEntities::CPhysicsPushedEntities(this: &s_PushedEntities);
  return atexit(func: dynamic_atexit_destructor_for__s_PushedEntities__);
}

//------------------------------------------------------------------------------
// Address: 0x10407460
// Name: _dynamic_initializer_for__sv_teststepsimulation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_teststepsimulation__()
{
  ConVar::ConVar(this: &sv_teststepsimulation, pName: "sv_teststepsimulation", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_teststepsimulation__);
}

//------------------------------------------------------------------------------
// Address: 0x10407490
// Name: _dynamic_initializer_for__g_EdictTouchLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EdictTouchLinks__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EdictTouchLinks,
    blockSize: 20,
    numElements: 2048,
    growMode: 0,
    pszAllocOwner: "g_EdictTouchLinks",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EdictTouchLinks__);
}

//------------------------------------------------------------------------------
// Address: 0x104074C0
// Name: _dynamic_initializer_for__g_EntityGroundLinks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityGroundLinks__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_EntityGroundLinks,
    blockSize: 12,
    numElements: 2048,
    growMode: 0,
    pszAllocOwner: "g_EntityGroundLinks",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_EntityGroundLinks__);
}

//------------------------------------------------------------------------------
// Address: 0x104074F0
// Name: _dynamic_initializer_for__g_WatcherList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WatcherList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_WatcherList__);
}

//------------------------------------------------------------------------------
// Address: 0x10407500
// Name: _dynamic_initializer_for__think_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__think_limit__()
{
  ConVar::ConVar(
    this: &think_limit,
    pName: "think_limit",
    pDefaultValue: "10",
    flags: 532480,
    pHelpString: "Maximum think time in milliseconds, warning is printed if this is exceeded.");
  return atexit(func: dynamic_atexit_destructor_for__think_limit__);
}
