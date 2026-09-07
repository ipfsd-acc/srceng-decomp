// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/molotov_projectile.cpp
// Functions: 9
// ============================================================

#include "game\shared\cstrike15\molotov_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x10228790
// Name: public: virtual class ClientClass __near * C_MolotovProjectile::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_MolotovProjectile::GetClientClass(C_MolotovProjectile *this)
{
  return &__g_C_MolotovProjectileClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10228810
// Name: public: virtual bool C_MolotovProjectile::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_MolotovProjectile::Simulate(C_MolotovProjectile *this)
{
  CNewParticleEffect *m_pObject; // edi
  const Vector *v4; // eax

  m_pObject = this->m_molotovParticleEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    v4 = this->GetAbsOrigin(this);
    m_pObject->m_vSortOrigin.x = v4->x;
    m_pObject->m_vSortOrigin.y = v4->y;
    m_pObject->m_vSortOrigin.z = v4->z;
    *((_BYTE *)this->m_molotovParticleEffect.m_pObject + 944) |= 8u;
  }
  else
  {
    DispatchParticleEffect(
      pszParticleName: "weapon_molotov_thrown",
      iAttachType: PATTACH_POINT_FOLLOW,
      pEntity: this,
      pszAttachmentName: "Wick",
      bResetAllParticlesOnEntity: false,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
  }
  C_BaseAnimating::Simulate(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10228900
// Name: public: virtual void C_MolotovProjectile::OnNewParticleEffect(char const __near *,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MolotovProjectile::OnNewParticleEffect(
        C_MolotovProjectile *this,
        const char *pszParticleName,
        CNewParticleEffect *pNewParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_molotovParticleEffect; // esi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  if ( _V_stricmp(s1: pszParticleName, s2: "weapon_molotov_thrown") == 0 )
  {
    m_pObject = this->m_molotovParticleEffect.m_pObject;
    p_m_molotovParticleEffect = (CUtlReference<CSheet> *)&this->m_molotovParticleEffect;
    if ( m_pObject != pNewParticleEffect )
    {
      if ( m_pObject != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
          this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
          which: p_m_molotovParticleEffect);
        p_m_molotovParticleEffect->m_pObject = nullptr;
      }
      p_m_molotovParticleEffect->m_pObject = (CSheet *)pNewParticleEffect;
      if ( pNewParticleEffect != nullptr )
      {
        p_m_molotovParticleEffect->m_pNext = (CUtlReference<CSheet> *)pNewParticleEffect->m_References.m_pHead;
        m_pHead = pNewParticleEffect->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_molotovParticleEffect;
        p_m_molotovParticleEffect->m_pPrev = nullptr;
        pNewParticleEffect->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_molotovParticleEffect;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10228980
// Name: public: virtual void C_MolotovProjectile::OnParticleEffectDeleted(class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MolotovProjectile::OnParticleEffectDeleted(
        C_DecoyProjectile *this,
        CNewParticleEffect *pParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CNewParticleEffect> *p_m_decoyParticleEffect; // esi

  if ( pParticleEffect == this->m_decoyParticleEffect.m_pObject )
  {
    m_pObject = this->m_decoyParticleEffect.m_pObject;
    p_m_decoyParticleEffect = &this->m_decoyParticleEffect;
    if ( m_pObject != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
        which: (CUtlReference<CSheet> *)&this->m_decoyParticleEffect);
      p_m_decoyParticleEffect->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427AE0
// Name: DT_MolotovProjectile::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovProjectile::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_MolotovProjectile::g_RecvTable);
  return atexit(func: DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427B00
// Name: DT_MolotovProjectile::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovProjectile::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_MolotovProjectile::ignored>();
  DT_MolotovProjectile::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435E00
// Name: DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_MolotovProjectile::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10228880
// Name: _C_MolotovProjectile_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_MolotovProjectile_CreateObject(int entnum, int serialNum)
{
  C_BaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xD00u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseGrenade::C_BaseGrenade(this: v2);
  *v3 = &C_MolotovProjectile::`vftable'{for `IClientUnknown'};
  v3[1] = &C_MolotovProjectile::`vftable'{for `IClientRenderable'};
  v3[2] = &C_MolotovProjectile::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_MolotovProjectile::`vftable'{for `IClientThinkable'};
  v3[4] = &C_MolotovProjectile::`vftable';
  v3[829] = 0;
  v3[828] = 0;
  v3[830] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427B10
// Name: _dynamic_initializer_for____g_C_AK47ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_AK47ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_AK47ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_AK47ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102A4A80
// Name: public: virtual void molotov_projectilePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall molotov_projectilePrecache::CResourcePrecacher::Cache(
        molotov_projectilePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "molotov_projectile",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A4AB0
// Name: public: virtual class ServerClass __near * CMolotovProjectile::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CMolotovProjectile::GetServerClass(CMolotovProjectile *this)
{
  return &g_CMolotovProjectile_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102A4AC0
// Name: public: virtual void CMolotovProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMolotovProjectile::Precache(CMolotovProjectile *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/Weapons/w_eq_molotov_thrown.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "Molotov.Throw");
  CBaseEntity::PrecacheScriptSound(soundname: "Molotov.Loop");
  PrecacheParticleSystem(pParticleSystemName: "weapon_molotov_thrown");
  PrecacheParticleSystem(pParticleSystemName: "weapon_molotov_held");
  CBaseCSGrenadeProjectile::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A4B10
// Name: public: virtual void CMolotovProjectile::BounceSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovProjectile::BounceSound(CMolotovProjectile *this)
{
  CBaseEntity::EmitSound(this, soundname: "GlassBottle.ImpactHard", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A4BB0
// Name: public: virtual void CMolotovProjectile::BounceTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovProjectile::BounceTouch(CMolotovProjectile *this, CBaseCombatCharacter *other)
{
  CBaseCombatCharacter *Thrower; // eax
  const CGameTrace *TouchTrace; // eax
  const CGameTrace *v5; // esi
  CTakeDamageInfo info; // [esp+18h] [ebp-68h] BYREF
  Vector vel; // [esp+74h] [ebp-Ch] BYREF

  if ( (other->m_Collision.m_usSolidFlags.m_Value & 0x28) == 0
    && other != CBaseGrenade::GetThrower(this)
    && other->m_iClassname.pszValue != "func_breakable"
    && CBaseEntity::ClassMatchesComplex(this: other, pszClassOrWildcard: "func_breakable") == 0
    && other->m_iClassname.pszValue != "func_breakable_surf"
    && CBaseEntity::ClassMatchesComplex(this: other, pszClassOrWildcard: "func_breakable_surf") == 0 )
  {
    if ( FClassnameIs(pEntity: other, szClassname: "prop_car_alarm")
      || FClassnameIs(pEntity: other, szClassname: "prop_car_glass") )
    {
      Thrower = CBaseGrenade::GetThrower(this);
      CTakeDamageInfo::CTakeDamageInfo(
        this: &info,
        pInflictor: this,
        pAttacker: Thrower,
        flDamage: 10.0,
        bitsDamageType: 0,
        iKillType: 0,
        iObjectsPenetrated: 0);
      other->OnTakeDamage(this: other, a2: &info);
    }
    TouchTrace = CBaseEntity::GetTouchTrace();
    v5 = TouchTrace;
    if ( TouchTrace->m_pEnt == nullptr
      || TouchTrace->m_pEnt->MyCombatCharacterPointer(this: TouchTrace->m_pEnt) == nullptr )
    {
      if ( v5->plane.normal.z > 0.0 )
      {
        this->Detonate(this);
      }
      else
      {
        *(_QWORD *)&vel.x = *(_QWORD *)&CBaseEntity::GetAbsVelocity(this)->x;
        vel.x = vel.x * 0.5;
        vel.y = vel.y * 0.5;
        vel.z = -10.0;
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A4D10
// Name: public: virtual void CMolotovProjectile::Detonate(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CMolotovProjectile::Detonate(
        CMolotovProjectile *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CGameTrace *TouchTrace; // eax
  bool v6; // zf
  CBaseCombatCharacter *Thrower; // edi
  IGameEvent *v8; // edi
  int v9; // eax
  void (__thiscall *SetFloat)(IGameEvent *, const char *, float); // eax
  int m_iEFlags; // edx
  float z; // xmm0_4
  CBaseCombatCharacter *v13; // eax
  CBaseEntity *v14; // eax
  float v15; // edx
  CInferno *v16; // edi
  __int128 v17; // xmm0
  int v20; // [esp+4Ch] [ebp-ACh] BYREF
  CGameTrace tr; // [esp+58h] [ebp-A0h]
  __int128 v22; // [esp+ACh] [ebp-4Ch] OVERLAPPED BYREF
  Vector v23; // [esp+BCh] [ebp-3Ch] BYREF
  Vector splashNormal; // [esp+C8h] [ebp-30h] BYREF
  Vector startpos; // [esp+D4h] [ebp-24h] BYREF
  Vector burnPos; // [esp+E0h] [ebp-18h] BYREF
  Vector vBurnDir; // [esp+ECh] [ebp-Ch] BYREF
  float retaddr; // [esp+F8h] [ebp+0h]

  vBurnDir.x = a2;
  vBurnDir.y = retaddr;
  TouchTrace = (CGameTrace *)CBaseEntity::GetTouchTrace();
  v6 = (TouchTrace->surface.flags & 4) == 0;
  tr.m_pEnt = (CBaseEntity *)TouchTrace;
  if ( !v6 )
    return;
  Thrower = CBaseGrenade::GetThrower(this);
  if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
  {
    tr.hitbox = (int)__RTDynamicCast(
                       inptr: Thrower,
                       VfDelta: 0,
                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                       isReference: 0);
    if ( tr.hitbox != 0 )
    {
      v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "molotov_detonate", a3: 0, a4: 0);
      if ( v8 != nullptr )
      {
        v9 = ((int (__thiscall *)(IVEngineServer *, _DWORD, int, int))engine->GetPlayerUserId)(
               a1: engine,
               a2: *(_DWORD *)(tr.hitbox + 24),
               a3,
               a4);
        v8->SetInt(this: v8, a2: "userid", a3: v9);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vBurnDir);
        SetFloat = v8->SetFloat;
        tr.startpos.x = this->m_vecAbsOrigin.x;
        ((void (__thiscall *)(IGameEvent *, const char *))SetFloat)(a1: v8, a2: "x");
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vBurnDir);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "y",
          a3: LODWORD(this->m_vecAbsOrigin.y));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vBurnDir);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "z",
          a3: LODWORD(this->m_vecAbsOrigin.z));
        ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
      }
    }
  }
  if ( CGameTrace::DidHitWorld(this: (CGameTrace *)tr.m_pEnt) )
  {
    LODWORD(startpos.x) = tr.m_pEnt->m_Network.__vftable;
    LODWORD(startpos.y) = tr.m_pEnt->m_Network.__vftable;
    LODWORD(startpos.z) = tr.m_pEnt->m_Network.m_pOuter;
    LODWORD(v23.x) = tr.m_pEnt->m_Network.m_pPev;
    v23.y = *(float *)&tr.m_pEnt->m_Network.m_PVSInfo.m_nHeadNode;
    z = *(float *)&tr.m_pEnt->m_Network.m_PVSInfo.m_pClusters;
    goto LABEL_21;
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vBurnDir);
  m_iEFlags = this->m_iEFlags;
  *(_QWORD *)((char *)&v22 + 4) = *(_QWORD *)&this->m_vecAbsOrigin.x;
  *((float *)&v22 + 3) = this->m_vecAbsOrigin.z - 999999.88;
  if ( (m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&vBurnDir);
  splashNormal.x = this->m_vecAbsOrigin.x;
  splashNormal.y = this->m_vecAbsOrigin.y;
  splashNormal.z = this->m_vecAbsOrigin.z + 10.0;
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vBurnDir,
    a2: (int)this,
    vecAbsStart: &splashNormal,
    vecAbsEnd: (const Vector *)((char *)&v22 + 4),
    mask: 0x200400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: (CGameTrace *)&v20);
  if ( (tr.allsolid & 4) == 0 )
  {
    startpos = tr.startpos;
    v23.x = tr.endpos.x;
    v23.y = tr.endpos.y;
    z = tr.endpos.z;
LABEL_21:
    v23.z = z;
    CBotManager::SetGrenadeRadius(this: TheBots, grenade: this, radius: 115.0);
    memset((void *)&splashNormal, 0, sizeof(splashNormal));
    v13 = CBaseGrenade::GetThrower(this);
    v14 = CBaseEntity::Create(
            szName: "inferno",
            vecOrigin: &startpos,
            vecAngles: (const QAngle *)&splashNormal,
            pOwner: v13);
    v15 = this->m_vInitialVelocity.m_Value.z;
    v16 = (CInferno *)v14;
    *(_QWORD *)&burnPos.x = *(_QWORD *)&this->m_vInitialVelocity.m_Value.x;
    burnPos.z = v15;
    VectorNormalize(vec: &burnPos);
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&vBurnDir);
    v17 = 0;
    *(float *)&v17 = fsqrt(
                       (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                             + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                     + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
    v22 = v17;
    burnPos.x = burnPos.x * *(float *)&v17;
    burnPos.y = burnPos.y * *(float *)&v17;
    burnPos.z = burnPos.z * *(float *)&v17;
    CInferno::StartBurning(
      this: v16,
      a2: (int)&vBurnDir.z,
      a3: (int)v16,
      a4: (int)this,
      pos: &startpos,
      normal: &v23,
      velocity: &burnPos,
      initialDepth: 0);
    CBaseEntity::StopSound(this, soundname: "Molotov.Loop");
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A50E0
// Name: public: virtual void CMolotovProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovProjectile::Spawn(CMolotovProjectile *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  p_m_timestamp = &this->m_stillTimer.m_timestamp;
  if ( this->m_stillTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_stillTimer.NetworkStateChanged(this: &this->m_stillTimer, a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
  this->SetModel(this, a2: "models/Weapons/w_eq_molotov_thrown.mdl");
  CBaseCSGrenadeProjectile::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5130
// Name: private: void CMolotovProjectile::DetonateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMolotovProjectile::DetonateThink(CMolotovProjectile *this)
{
  float m_Value; // xmm0_4
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  double v4; // st7
  float v5; // [esp+14h] [ebp-4h]
  float v6; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  m_Value = this->m_stillTimer.m_timestamp.m_Value;
  p_m_timestamp = &this->m_stillTimer.m_timestamp;
  if ( (float)((float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                     + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
             + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z)) <= 25.0 )
  {
    if ( m_Value <= 0.0 )
    {
      v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stillTimer);
      if ( this->m_stillTimer.m_timestamp.m_Value != v4 )
      {
        this->m_stillTimer.NetworkStateChanged(this: &this->m_stillTimer, a2: &this->m_stillTimer.m_timestamp);
        v5 = v4;
        this->m_stillTimer.m_timestamp.m_Value = v5;
      }
    }
  }
  else if ( m_Value != -1.0 )
  {
    this->m_stillTimer.NetworkStateChanged(this: &this->m_stillTimer, a2: &this->m_stillTimer.m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
  if ( p_m_timestamp->m_Value <= 0.0
    || this->m_stillTimer.m_timestamp.m_Value > 0.0
    && (v6 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_stillTimer) - this->m_stillTimer.m_timestamp.m_Value) <= 0.5 )
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
  else
  {
    this->Detonate(this);
  }
  CBotManager::SetGrenadeRadius(this: TheBots, grenade: this, radius: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x102A5280
// Name: public: static class CMolotovProjectile __near * CMolotovProjectile::Create(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
CMolotovProjectile *__cdecl CMolotovProjectile::Create(
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        CBaseCombatCharacter *owner)
{
  CBaseEntity *v5; // esi
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  CBaseEdict *v8; // ecx
  CBaseEntity_vtbl *v9; // edi
  int TeamNumber; // eax

  v5 = CBaseEntity::Create(szName: "molotov_projectile", vecOrigin: position, vecAngles: angles, pOwner: owner);
  UTIL_LogPrintf(
    fmt: "Molotov projectile spawned at %f %f %f, velocity %f %f %f\n",
    position->x,
    position->y,
    position->z,
    velocity->x,
    velocity->y,
    velocity->z);
  CBaseCSGrenadeProjectile::SetDetonateTimerLength(this: (CBaseCSGrenadeProjectile *)v5, timer: 5.0);
  CBaseEntity::SetAbsVelocity(this: v5, vecAbsVelocity: velocity);
  CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(this: (CBaseCSGrenadeProjectile *)v5, velocity);
  CBaseGrenade::SetThrower(this: (CBaseGrenade *)v5, pThrower: owner);
  v5->m_flGravity = 0.40000001;
  CBaseEntity::SetFriction(this: v5, flFriction: 0.2);
  if ( v5->m_flElasticity.m_Value != 0.44999999 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1B8u);
    }
    v5->m_flElasticity.m_Value = 0.44999999;
  }
  v5->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *)) __thiscall CMolotovProjectile::`vcall'{952,{flat}};
  CBaseEntity::ThinkSet(
    this: v5,
    func: (void (__thiscall *)(CBaseEntity *))CMolotovProjectile::DetonateThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v5, thinkTime: gpGlobals->curtime + 2.0, szContext: nullptr);
  if ( *(float *)&v5[1].m_nWaterTouch != 200.0 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x4A4u);
    }
    *(_DWORD *)&v5[1].m_nWaterTouch = 1128792064;
  }
  if ( *(float *)&v5[1].m_hOwnerEntity.m_Value.m_Index != 300.0 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0x494u);
    }
    v5[1].m_hOwnerEntity.m_Value.m_Index = 1133903872;
  }
  v9 = v5->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: owner);
  v9->ChangeTeam(this: v5, a2: TeamNumber);
  CBaseEntity::ApplyLocalAngularVelocityImpulse(this: v5, angImpulse: angVelocity);
  CBaseEntity::ThinkSet(
    this: v5,
    func: (void (__thiscall *)(CBaseEntity *))CBaseCSGrenadeProjectile::DangerSoundThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v5, thinkTime: gpGlobals->curtime, szContext: nullptr);
  LODWORD(v5[1].m_vecAbsVelocity.x) = GetWeaponInfo(weaponID: WEAPON_MOLOTOV);
  CBaseEntity::EmitSound(this: v5, soundname: "Molotov.Throw", soundtime: 0.0, duration: nullptr);
  CBaseEntity::EmitSound(this: v5, soundname: "Molotov.Loop", soundtime: 0.0, duration: nullptr);
  return (CMolotovProjectile *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10410470
// Name: _dynamic_initializer_for__molotov_projectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__molotov_projectile__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CMolotovProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &molotov_projectile,
           a3: "molotov_projectile");
}

//------------------------------------------------------------------------------
// Address: 0x10410490
// Name: molotov_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int molotov_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  molotov_projectilePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&molotov_projectilePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104104D0
// Name: DT_MolotovProjectile::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovProjectile::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_MolotovProjectile::g_SendTable);
  return atexit(func: DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104104F0
// Name: DT_MolotovProjectile::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_MolotovProjectile::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_MolotovProjectile::ignored>();
  DT_MolotovProjectile::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420030
// Name: DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_MolotovProjectile::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_MolotovProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102A5510
// Name: class CMolotovProjectile __near * _CreateEntityTemplate<class CMolotovProjectile>(class CMolotovProjectile __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMolotovProjectile *__cdecl _CreateEntityTemplate<CMolotovProjectile>(
        CMolotovProjectile *newEnt,
        const char *className)
{
  CBaseGrenade *v2; // eax
  _DWORD *v3; // esi
  int v4; // edx

  v2 = (CBaseGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x4D4u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBaseGrenade::CBaseGrenade(this: v2);
    *v3 = &CMolotovProjectile::`vftable'{for `CBaseAnimating'};
    v3[291] = &CMolotovProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    v3[306] = &IntervalTimer::`vftable';
    v4 = v3[306];
    v3[307] = -1082130432;
    (*(void (__stdcall **)(_DWORD *))(v4 + 4))(a1: v3 + 307);
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CMolotovProjectile *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104104B0
// Name: _dynamic_initializer_for__g_CMolotovProjectile_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CMolotovProjectile_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CMolotovProjectile_ClassReg,
           pNetworkName: "CMolotovProjectile",
           pTable: &DT_MolotovProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420040
// Name: _ServerClassInit_DT_MolotovProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_MolotovProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_256;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420060
// Name: _DataMapInit_CSurroundTest__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSurroundTest__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_485);
}

//------------------------------------------------------------------------------
// Address: 0x10420070
// Name: _DataMapInit_CSmokeGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSmokeGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_486);
}

} // namespace server
