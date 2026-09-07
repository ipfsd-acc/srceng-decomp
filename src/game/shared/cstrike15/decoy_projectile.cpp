// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/decoy_projectile.cpp
// Functions: 8
// ============================================================

#include "game\shared\cstrike15\decoy_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x102284D0
// Name: public: virtual class ClientClass __near * C_DecoyProjectile::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DecoyProjectile::GetClientClass(C_DecoyProjectile *this)
{
  return &__g_C_DecoyProjectileClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10228550
// Name: public: virtual bool C_DecoyProjectile::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_DecoyProjectile::Simulate(C_DecoyProjectile *this)
{
  CNewParticleEffect *m_pObject; // edi
  const Vector *v4; // eax

  C_BaseEntity::CalcAbsoluteVelocity(this);
  if ( fsqrt(
         (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
               + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
       + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z)) <= 0.1 )
  {
    m_pObject = this->m_decoyParticleEffect.m_pObject;
    if ( m_pObject == nullptr )
    {
      DispatchParticleEffect(
        pszParticleName: "weapon_decoy_ground_effect",
        iAttachType: PATTACH_POINT_FOLLOW,
        pEntity: this,
        pszAttachmentName: "Wick",
        bResetAllParticlesOnEntity: false,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr);
      C_BaseAnimating::Simulate(this);
      return 1;
    }
    v4 = this->GetAbsOrigin(this);
    m_pObject->m_vSortOrigin.x = v4->x;
    m_pObject->m_vSortOrigin.y = v4->y;
    m_pObject->m_vSortOrigin.z = v4->z;
    *((_BYTE *)this->m_decoyParticleEffect.m_pObject + 944) |= 8u;
    C_BaseAnimating::Simulate(this);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10228710
// Name: public: virtual void C_DecoyProjectile::OnNewParticleEffect(char const __near *,class CNewParticleEffect __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DecoyProjectile::OnNewParticleEffect(
        C_DecoyProjectile *this,
        const char *pszParticleName,
        CNewParticleEffect *pNewParticleEffect)
{
  CNewParticleEffect *m_pObject; // eax
  CUtlReference<CSheet> *p_m_decoyParticleEffect; // esi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  if ( _V_stricmp(s1: pszParticleName, s2: "weapon_decoy_ground_effect") == 0 )
  {
    m_pObject = this->m_decoyParticleEffect.m_pObject;
    p_m_decoyParticleEffect = (CUtlReference<CSheet> *)&this->m_decoyParticleEffect;
    if ( m_pObject != pNewParticleEffect )
    {
      if ( m_pObject != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
          this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
          which: p_m_decoyParticleEffect);
        p_m_decoyParticleEffect->m_pObject = nullptr;
      }
      p_m_decoyParticleEffect->m_pObject = (CSheet *)pNewParticleEffect;
      if ( pNewParticleEffect != nullptr )
      {
        p_m_decoyParticleEffect->m_pNext = (CUtlReference<CSheet> *)pNewParticleEffect->m_References.m_pHead;
        m_pHead = pNewParticleEffect->m_References.m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_decoyParticleEffect;
        p_m_decoyParticleEffect->m_pPrev = nullptr;
        pNewParticleEffect->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_decoyParticleEffect;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10427A90
// Name: DT_DecoyProjectile::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyProjectile::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DecoyProjectile::g_RecvTable);
  return atexit(func: DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10427AB0
// Name: DT_DecoyProjectile::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyProjectile::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DecoyProjectile::ignored>();
  DT_DecoyProjectile::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435DF0
// Name: DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DecoyProjectile::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10228640
// Name: _C_DecoyProjectile_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DecoyProjectile_CreateObject(int entnum, int serialNum)
{
  C_BaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xD00u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseGrenade::C_BaseGrenade(this: v2);
  *v3 = &C_DecoyProjectile::`vftable'{for `IClientUnknown'};
  v3[1] = &C_DecoyProjectile::`vftable'{for `IClientRenderable'};
  v3[2] = &C_DecoyProjectile::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_DecoyProjectile::`vftable'{for `IClientThinkable'};
  v3[4] = &C_DecoyProjectile::`vftable';
  v3[829] = 0;
  v3[828] = 0;
  v3[830] = 0;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10427AC0
// Name: _dynamic_initializer_for____g_C_MolotovProjectileClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_MolotovProjectileClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_MolotovProjectileClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_MolotovProjectileClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10299BF0
// Name: public: virtual void decoy_projectilePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall decoy_projectilePrecache::CResourcePrecacher::Cache(
        decoy_projectilePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "decoy_projectile",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10299C20
// Name: public: virtual class ServerClass __near * CDecoyProjectile::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CDecoyProjectile::GetServerClass(CDecoyProjectile *this)
{
  return &g_CDecoyProjectile_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10299C30
// Name: public: virtual struct datamap_t __near * CDecoyProjectile::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CDecoyProjectile::GetDataDescMap(CDecoyProjectile *this)
{
  return &CDecoyProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10299C40
// Name: public: virtual void CDecoyProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecoyProjectile::Spawn(CDecoyProjectile *this)
{
  this->SetModel(this, a2: "models/Weapons/w_eq_decoy_thrown.mdl");
  CBaseCSGrenadeProjectile::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10299C60
// Name: public: virtual void CDecoyProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDecoyProjectile::Precache(CDecoyProjectile *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/Weapons/w_eq_decoy_thrown.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "Flashbang.Explode");
  CBaseEntity::PrecacheScriptSound(soundname: "Flashbang.Bounce");
  CBaseCSGrenadeProjectile::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10299D40
// Name: private: void CDecoyProjectile::GunfireThink(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CDecoyProjectile::GunfireThink(CDecoyProjectile *this@<ecx>, int a2@<ebp>)
{
  DecoyActivity *v3; // eax
  CBaseCombatCharacter *Thrower; // eax
  IUniformRandomStream *v5; // ecx
  CBaseCombatCharacter *v6; // edi
  const edict_t **v7; // ebx
  IGameEvent *v8; // edi
  int v9; // eax
  edict_t *m_pPev; // eax
  float curtime; // xmm0_4
  IGameEvent *v12; // edi
  const edict_t **v13; // ebx
  int v14; // eax
  edict_t *v15; // eax
  float v16; // [esp+30h] [ebp-40h]
  const char *thinkTime; // [esp+34h] [ebp-3Ch]

  if ( this->m_shotsRemaining <= 0 )
  {
    v3 = &gDecoyActivities[_RandomInt((IUniformRandomStream *)this, a2: 0, a3: 4)];
    this->m_pActivity = v3;
    this->m_shotsRemaining = _RandomInt(this: (IUniformRandomStream *)v3->maxShots, a2: v3->minShots, a3: v3->maxShots);
  }
  CBaseEntity::EmitSound(this, soundname: this->m_pActivity->szSound, soundtime: 0.0, duration: nullptr);
  Thrower = CBaseGrenade::GetThrower(this);
  v6 = Thrower;
  if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
  {
    v7 = (const edict_t **)__RTDynamicCast(
                             inptr: v6,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CCSPlayer `RTTI Type Descriptor',
                             isReference: 0);
    if ( v7 != nullptr )
    {
      v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "decoy_firing", a3: 0, a4: 0);
      if ( v8 != nullptr )
      {
        v9 = engine->GetPlayerUserId(this: engine, a2: v7[6]);
        v8->SetInt(this: v8, a2: "userid", a3: v9);
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        v8->SetInt(this: v8, a2: "entityid", a3: (int)m_pPev);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "x",
          a3: LODWORD(this->m_vecAbsOrigin.x));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "y",
          a3: LODWORD(this->m_vecAbsOrigin.y));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "z",
          a3: LODWORD(this->m_vecAbsOrigin.z));
        thinkTime = nullptr;
        ((void (__thiscall *)(IGameEventManager2 *, IGameEvent *))gameeventmanager->FireEvent)(
          a1: gameeventmanager,
          a2: v8);
      }
    }
  }
  if ( --this->m_shotsRemaining <= 0 )
  {
    curtime = gpGlobals->curtime;
    if ( this->m_fExpireTime <= curtime )
    {
      v12 = (IGameEvent *)CBaseGrenade::GetThrower(this);
      if ( v12 != nullptr && ((unsigned __int8 (__thiscall *)(IGameEvent *))v12->__vftable[5].GetString)(a1: v12) != 0 )
      {
        v13 = (const edict_t **)__RTDynamicCast(
                                  inptr: v12,
                                  VfDelta: 0,
                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                                  isReference: 0);
        if ( v13 != nullptr )
        {
          v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "decoy_detonate", a3: 0, a4: 0);
          if ( v12 != nullptr )
          {
            v14 = engine->GetPlayerUserId(this: engine, a2: v13[6]);
            v12->SetInt(this: v12, a2: "userid", a3: v14);
            v15 = this->m_Network.m_pPev;
            if ( v15 != nullptr )
              v15 -= (int)gpGlobals->pEdicts;
            v12->SetInt(this: v12, a2: "entityid", a3: (int)v15);
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2);
            ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v12->SetFloat)(
              a1: v12,
              a2: "x",
              a3: LODWORD(this->m_vecAbsOrigin.x));
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2);
            ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v12->SetFloat)(
              a1: v12,
              a2: "y",
              a3: LODWORD(this->m_vecAbsOrigin.y));
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2);
            ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v12->SetFloat)(
              a1: v12,
              a2: "z",
              a3: LODWORD(this->m_vecAbsOrigin.z));
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v12, a3: false);
          }
        }
      }
      CBaseGrenade::Detonate(this, a2: (int)v12, a3: (int)this);
      UTIL_Remove(oldObj: this);
    }
    else
    {
      CBaseEntity::SetNextThink(this, thinkTime: curtime + 0.30000001, szContext: nullptr);
    }
  }
  else
  {
    v16 = _RandomFloat(this: v5, a2: this->m_pActivity->minDelay, a3: this->m_pActivity->maxDelay) + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime: v16, szContext: thinkTime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A0D0
// Name: private: void CDecoyProjectile::Think_Detonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDecoyProjectile::Think_Detonate(
        CDecoyProjectile *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  __int128 v5; // xmm0
  CBaseCombatCharacter *Thrower; // eax
  CBaseCombatCharacter *v7; // esi
  IGameEvent *v8; // esi
  int v9; // eax
  edict_t *m_pPev; // eax
  _DWORD *v13; // [esp+74h] [ebp-10h]
  _DWORD v14[2]; // [esp+78h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+84h] [ebp+0h]

  v14[0] = a2;
  v14[1] = retaddr;
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v14);
  v5 = 0;
  *(float *)&v5 = fsqrt(
                    (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                          + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                  + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
  if ( *(float *)&v5 <= 0.1 )
  {
    Thrower = CBaseGrenade::GetThrower(this);
    v7 = Thrower;
    if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
    {
      v13 = __RTDynamicCast(
              inptr: v7,
              VfDelta: 0,
              SrcType: &CBaseEntity `RTTI Type Descriptor',
              TargetType: &CCSPlayer `RTTI Type Descriptor',
              isReference: 0);
      if ( v13 != nullptr )
      {
        v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "decoy_started", a3: 0, a4: 0);
        if ( v8 != nullptr )
        {
          v9 = ((int (__thiscall *)(IVEngineServer *, _DWORD, int, int))engine->GetPlayerUserId)(
                 a1: engine,
                 a2: v13[6],
                 a3,
                 a4);
          v8->SetInt(this: v8, a2: "userid", a3: v9);
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            m_pPev -= (int)gpGlobals->pEdicts;
          v8->SetInt(this: v8, a2: "entityid", a3: (int)m_pPev);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v14);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
            a1: v8,
            a2: "x",
            a3: LODWORD(this->m_vecAbsOrigin.x));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v14);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
            a1: v8,
            a2: "y",
            a3: LODWORD(this->m_vecAbsOrigin.y));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v14);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
            a1: v8,
            a2: "z",
            a3: LODWORD(this->m_vecAbsOrigin.z));
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
        }
      }
    }
    this->m_shotsRemaining = 0;
    this->m_fExpireTime = gpGlobals->curtime + 8.0;
    this->m_pActivity = nullptr;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CDecoyProjectile::GunfireThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBotManager::SetGrenadeRadius(this: TheBots, grenade: this, radius: 115.0);
    CDecoyProjectile::GunfireThink(this, a2: (int)v14);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A330
// Name: public: static class CDecoyProjectile __near * CDecoyProjectile::Create(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
CDecoyProjectile *__cdecl CDecoyProjectile::Create(
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        CBaseCombatCharacter *pOwner)
{
  CBaseEntity *v5; // esi
  CBaseEdict *v6; // ecx
  float v7; // xmm0_4
  CBaseEdict *v8; // ecx
  CBaseEntity_vtbl *v9; // edi
  int TeamNumber; // eax
  CBaseEdict *v11; // ecx

  v5 = CBaseEntity::Create(szName: "decoy_projectile", vecOrigin: position, vecAngles: angles, pOwner);
  CBaseEntity::ThinkSet(
    this: v5,
    func: (void (__thiscall *)(CBaseEntity *))CDecoyProjectile::Think_Detonate,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v5, thinkTime: gpGlobals->curtime + 1.5, szContext: nullptr);
  CBotManager::SetGrenadeRadius(this: TheBots, grenade: (CBaseGrenade *)v5, radius: 0.0);
  CBaseEntity::SetAbsVelocity(this: v5, vecAbsVelocity: velocity);
  CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(this: (CBaseCSGrenadeProjectile *)v5, velocity);
  CBaseGrenade::SetThrower(this: (CBaseGrenade *)v5, pThrower: pOwner);
  if ( *(float *)&v5[1].m_nWaterTouch != 25.0 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x4A4u);
    }
    *(_DWORD *)&v5[1].m_nWaterTouch = 1103626240;
  }
  v7 = *(float *)&v5[1].m_nWaterTouch * 3.5;
  if ( *(float *)&v5[1].m_hOwnerEntity.m_Value.m_Index != v7 )
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
    *(float *)&v5[1].m_hOwnerEntity.m_Value.m_Index = v7;
  }
  v9 = v5->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: pOwner);
  v9->ChangeTeam(this: v5, a2: TeamNumber);
  CBaseEntity::ApplyLocalAngularVelocityImpulse(this: v5, angImpulse: angVelocity);
  v5->m_flGravity = 0.40000001;
  v5->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseGrenade::BounceTouch;
  CBaseEntity::SetFriction(this: v5, flFriction: 0.2);
  if ( v5->m_flElasticity.m_Value != 0.44999999 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x1B8u);
    }
    v5->m_flElasticity.m_Value = 0.44999999;
  }
  LODWORD(v5[1].m_vecAbsVelocity.x) = GetWeaponInfo(weaponID: WEAPON_DECOY);
  return (CDecoyProjectile *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1040F5A0
// Name: decoy_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int decoy_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  decoy_projectilePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&decoy_projectilePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F5E0
// Name: DT_DecoyProjectile::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyProjectile::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_DecoyProjectile::g_SendTable);
  return atexit(func: DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F600
// Name: DT_DecoyProjectile::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DecoyProjectile::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_DecoyProjectile::ignored>();
  DT_DecoyProjectile::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F610
// Name: CDecoyProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CDecoyProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CDecoyProjectile>(__formal: nullptr);
  CDecoyProjectile_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FED0
// Name: DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DecoyProjectile::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_DecoyProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1029A510
// Name: struct datamap_t __near * DataMapInit<class CDecoyProjectile>(class CDecoyProjectile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDecoyProjectile>()
{
  if ( (_S3_150 & 1) == 0 )
  {
    _S3_150 |= 1u;
    nameHolder_477.m_pszBase = "CDecoyProjectile";
    nameHolder_477.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_477.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_477.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_477.m_Names.m_Size = 0;
    nameHolder_477.m_Names.m_pElements = nullptr;
    nameHolder_477.m_nLenBase = 16;
    atexit(func: DataMapInit_CDecoyProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDecoyProjectile::m_DataMap.baseMap = &CBaseCSGrenadeProjectile::m_DataMap;
  if ( (_S3_150 & 2) == 0 )
  {
    _S3_150 |= 2u;
    dataDesc_499[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_477,
                                  pszIdentifier: "Think_Detonate");
    dataDesc_499[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_499[1].fieldSize = 2097153;
    dataDesc_499[1].externalName = nullptr;
    dataDesc_499[1].pSaveRestoreOps = nullptr;
    dataDesc_499[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDecoyProjectile::Think_Detonate;
    *(_QWORD *)&dataDesc_499[1].td = 0;
    *(_QWORD *)&dataDesc_499[1].override_field = 0;
    *(_QWORD *)&dataDesc_499[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_499[1].flatOffset[1] = 0;
    dataDesc_499[2].fieldType = FIELD_VOID;
    dataDesc_499[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_477,
                                  pszIdentifier: "GunfireThink");
    dataDesc_499[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_499[2].fieldSize = 2097153;
    dataDesc_499[2].externalName = nullptr;
    dataDesc_499[2].pSaveRestoreOps = nullptr;
    dataDesc_499[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDecoyProjectile::GunfireThink;
    *(_QWORD *)&dataDesc_499[2].td = 0;
    *(_QWORD *)&dataDesc_499[2].override_field = 0;
    *(_QWORD *)&dataDesc_499[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_499[2].flatOffset[1] = 0;
  }
  CDecoyProjectile::m_DataMap.dataNumFields = 2;
  CDecoyProjectile::m_DataMap.dataDesc = &dataDesc_499[1];
  return &CDecoyProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040F5C0
// Name: _dynamic_initializer_for__g_CDecoyProjectile_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CDecoyProjectile_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CDecoyProjectile_ClassReg,
           pNetworkName: "CDecoyProjectile",
           pTable: &DT_DecoyProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FEE0
// Name: _ServerClassInit_DT_DecoyProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_DecoyProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_248;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF00
// Name: _DataMapInit_CDecoyProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CDecoyProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_477);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF10
// Name: _DataMapInit_CFlashbangProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFlashbangProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_478);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF20
// Name: _DataMapInit_CBombTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBombTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_479);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF30
// Name: _DataMapInit_CBuyZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBuyZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_480);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF40
// Name: _DataMapInit_CHostageRescueZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CHostageRescueZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_481);
}

} // namespace server
