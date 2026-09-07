// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/gib.cpp
// Functions: 30
// ============================================================

#include "game\server\gib.h"

//------------------------------------------------------------------------------
// Address: 0x10155D20
// Name: public: virtual struct datamap_t __near * CGib::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGib::GetDataDescMap(CGib *this)
{
  return &CGib::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10155D30
// Name: public: void CGib::SetBloodColor(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::SetBloodColor(CGib *this, int nBloodColor)
{
  this->m_bloodColor = nBloodColor;
}

//------------------------------------------------------------------------------
// Address: 0x10155D40
// Name: public: class CBaseEntity __near * CGib::GetFlame(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGib::GetFlame(CGib *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hFlame.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10155D70
// Name: public: void CGib::LimitVelocity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::LimitVelocity(CGib *this)
{
  float z; // ecx
  Vector vecNewVelocity; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
  vecNewVelocity.z = z;
  if ( VectorNormalize(vec: &vecNewVelocity) > 1500.0 )
  {
    vecNewVelocity.x = vecNewVelocity.x * 1500.0;
    vecNewVelocity.y = vecNewVelocity.y * 1500.0;
    vecNewVelocity.z = vecNewVelocity.z * 1500.0;
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecNewVelocity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155E00
// Name: public: void CGib::InitGib(class CBaseEntity __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::InitGib(CGib *this, CBaseEntity *pVictim, float fMinVelocity, float fMaxVelocity)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  float z; // eax
  int m_Value; // edi
  float v11; // xmm0_4
  IUniformRandomStream *v12; // ecx
  IPhysicsObject *m_pPhysicsObject; // edi
  IUniformRandomStream *v14; // ecx
  IUniformRandomStream *v15; // ecx
  Vector vecOrigin; // [esp+40h] [ebp-30h] BYREF
  Vector angImpulse; // [esp+4Ch] [ebp-24h] BYREF
  QAngle vecNewAngularVelocity; // [esp+58h] [ebp-18h] BYREF
  Vector vecNewVelocity; // [esp+64h] [ebp-Ch] BYREF

  if ( pVictim != nullptr )
  {
    angImpulse.x = 1.0;
    angImpulse.y = 1.0;
    angImpulse.z = 1.0;
    CCollisionProperty::RandomPointInBounds(
      this: &pVictim->m_Collision,
      vecNormalizedMins: &vec3_origin,
      vecNormalizedMaxs: &angImpulse,
      pPoint: &vecOrigin);
    vecOrigin.z = vecOrigin.z + 1.0;
    CBaseEntity::SetAbsOrigin(this, absOrigin: &vecOrigin);
    vecNewVelocity.x = g_vecAttackDir.x * -1.0;
    vecNewVelocity.y = g_vecAttackDir.y * -1.0;
    vecNewVelocity.z = -1.0 * g_vecAttackDir.z;
    v5 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1098907648,
           a3: 1048576000);
    vecNewVelocity.x = v5 + vecNewVelocity.x;
    v6 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1098907648,
           a3: 1048576000);
    vecNewVelocity.y = v6 + vecNewVelocity.y;
    v7 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: -1098907648,
           a3: 1048576000);
    vecNewVelocity.z = v7 + vecNewVelocity.z;
    v8 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
           a1: random,
           a2: LODWORD(fMaxVelocity),
           a3: LODWORD(fMinVelocity));
    z = this->m_vecAngVelocity.z;
    *(_QWORD *)&vecNewAngularVelocity.x = *(_QWORD *)&this->m_vecAngVelocity.x;
    vecNewVelocity.x = vecNewVelocity.x * v8;
    vecNewVelocity.y = vecNewVelocity.y * v8;
    vecNewVelocity.z = v8 * vecNewVelocity.z;
    vecNewAngularVelocity.z = z;
    vecNewAngularVelocity.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1120403456,
                                a3: 1128792064);
    vecNewAngularVelocity.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1120403456,
                                a3: 1133903872);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vecNewAngularVelocity);
    this->m_bloodColor = pVictim->BloodColor(this: pVictim);
    m_Value = pVictim->m_iHealth.m_Value;
    if ( m_Value <= -50 )
    {
      if ( m_Value <= -200 )
        v11 = 4.0;
      else
        v11 = 2.0;
    }
    else
    {
      v11 = 0.69999999;
    }
    vecNewVelocity.x = vecNewVelocity.x * v11;
    vecNewVelocity.y = vecNewVelocity.y * v11;
    vecNewVelocity.z = vecNewVelocity.z * v11;
    if ( CBaseEntity::VPhysicsInitNormal(
           this,
           solidType: SOLID_BBOX,
           nSolidFlags: 0,
           createAsleep: false,
           pSolid: nullptr) != nullptr )
    {
      m_pPhysicsObject = this->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
      {
        angImpulse.x = _RandomFloat(this: v12, a2: -500.0, a3: 500.0);
        angImpulse.y = _RandomFloat(this: v14, a2: -500.0, a3: 500.0);
        angImpulse.z = _RandomFloat(this: v15, a2: -500.0, a3: 500.0);
        m_pPhysicsObject->AddVelocity(this: m_pPhysicsObject, a2: &vecNewVelocity, a3: &angImpulse);
      }
    }
    else
    {
      CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
      CBaseEntity::SetCollisionBounds(this, mins: &vec3_origin, maxs: &vec3_origin);
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecNewVelocity);
    }
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  }
  CGib::LimitVelocity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10156130
// Name: public: void CGib::DieThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::DieThink(CGib *this)
{
  unsigned int m_Index; // ecx
  CBaseEntityList *v3; // edx
  int v4; // eax
  CEntInfo *v5; // esi
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax
  CSprite *v11; // eax
  CSprite *v12; // esi
  unsigned int v13; // ecx
  int v14; // eax
  CEntInfo *v15; // esi
  unsigned int v16; // ecx
  int v17; // eax
  CEntInfo *v18; // eax
  IHandleEntity *v19; // eax
  CEntityFlame *v20; // eax

  m_Index = this->m_hSprite.m_Index;
  if ( m_Index != -1 )
  {
    v3 = g_pEntityList;
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber != v6 || v5->m_pEntity == nullptr )
      goto LABEL_10;
    v7 = v4;
    v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
    v9 = &g_pEntityList->m_EntPtrArray[v7];
    if ( v8 )
      m_pEntity = v9->m_pEntity;
    else
      m_pEntity = nullptr;
    v11 = (CSprite *)__RTDynamicCast(
                       inptr: m_pEntity,
                       VfDelta: 0,
                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                       TargetType: &CSprite `RTTI Type Descriptor',
                       isReference: 0);
    v12 = v11;
    if ( v11 != nullptr )
    {
      CSprite::SetBrightness(this: v11, brightness: 0, time: 0.0);
      CBaseEntity::ThinkSet(
        this: v12,
        func: (void (__thiscall *)(CBaseEntity *))CSprite::AnimateUntilDead,
        thinkTime: 0.0,
        szContext: nullptr);
      v12->m_flDieTime = gpGlobals->curtime;
      CBaseEntity::SetNextThink(this: v12, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
  v3 = g_pEntityList;
LABEL_10:
  v13 = this->m_hFlame.m_Index;
  if ( v13 != -1 )
  {
    v14 = (unsigned __int16)v13;
    v15 = &v3->m_EntPtrArray[(unsigned __int16)v13];
    v16 = HIWORD(v13);
    if ( v15->m_SerialNumber == v16 && v15->m_pEntity != nullptr )
    {
      v17 = v14;
      v8 = v3->m_EntPtrArray[v17].m_SerialNumber == v16;
      v18 = &v3->m_EntPtrArray[v17];
      v19 = v8 ? v18->m_pEntity : nullptr;
      v20 = (CEntityFlame *)__RTDynamicCast(
                              inptr: v19,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CEntityFlame `RTTI Type Descriptor',
                              isReference: 0);
      if ( v20 != nullptr )
        CEntityFlame::SetLifetime(this: v20, lifetime: 1.0);
    }
  }
  if ( g_pGameRules->IsMultiplayer(this: g_pGameRules) )
  {
    UTIL_Remove(oldObj: this);
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_FadeOut, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101562C0
// Name: public: virtual bool CGib::SUB_AllowedToFade(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGib::SUB_AllowedToFade(CGib *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  CBasePlayer *LocalPlayer; // eax
  int v5; // edx
  unsigned int m_Index; // eax
  CGib *m_pEntity; // ecx

  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr
    && ((((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) != 0
     || (this->m_iEFlags & 0x100000) != 0) )
  {
    return 0;
  }
  if ( gpGlobals->maxClients != 1 )
    return 1;
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer == nullptr || !LocalPlayer->FInViewCone(this: LocalPlayer, a2: this) || this->m_bForceRemove )
    return 1;
  v5 = 0;
  if ( CGib::s_ExtantGibs.m_Size - 75 <= 0 )
    return 0;
  while ( 1 )
  {
    m_Index = CGib::s_ExtantGibs.m_Memory.m_pMemory[v5].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CGib *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( this == m_pEntity )
      break;
    if ( ++v5 >= CGib::s_ExtantGibs.m_Size - 75 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10156390
// Name: public: void CGib::BounceGibTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::BounceGibTouch(CGib *this, CBaseEntity *pOther)
{
  const Vector *AbsOrigin; // eax
  float x; // xmm1_4
  float y; // xmm2_4
  float v6; // xmm0_4
  double v7; // xmm0_8
  edict_t *m_pPev; // eax
  float volume; // xmm0_4
  CGameTrace tr; // [esp+10h] [ebp-6Ch] BYREF
  Vector vecAbsVelocity; // [esp+64h] [ebp-18h] BYREF
  QAngle angles; // [esp+70h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+7Ch] [ebp+0h] BYREF

  if ( this->m_pPhysicsObject == nullptr )
  {
    if ( (this->m_fFlags.m_Value & 1) != 0 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      vecAbsVelocity.x = this->m_vecAbsVelocity.x * 0.89999998;
      vecAbsVelocity.y = this->m_vecAbsVelocity.y * 0.89999998;
      vecAbsVelocity.z = this->m_vecAbsVelocity.z * 0.89999998;
      CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
      angles.y = this->m_angRotation.m_Value.y;
      angles.x = 0.0;
      angles.z = 0.0;
      CBaseEntity::SetLocalAngles(this, &angles);
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    }
    else
    {
      if ( (g_Language.m_pParent == nullptr || g_Language.m_pParent->m_Value.m_nValue != 1)
        && this->m_cBloodDecals > 0
        && this->m_bloodColor != -1 )
      {
        AbsOrigin = CBaseEntity::GetAbsOrigin(this);
        x = AbsOrigin->x;
        y = AbsOrigin->y;
        angles.z = AbsOrigin->z + 8.0;
        angles.x = x;
        angles.y = y;
        vecAbsVelocity.x = x;
        vecAbsVelocity.y = y;
        vecAbsVelocity.z = angles.z - 24.0;
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: (const Vector *)&angles,
          vecAbsEnd: &vecAbsVelocity,
          mask: 0x400Bu,
          ignore: this,
          collisionGroup: 0,
          ptr: &tr);
        UTIL_BloodDecalTrace(pTrace: &tr, bloodColor: this->m_bloodColor);
        --this->m_cBloodDecals;
      }
      if ( this->m_material != 10 && random->RandomInt(this: random, a2: 0, a3: 2) == 0 )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
        v6 = COERCE_FLOAT(LODWORD(this->m_vecAbsVelocity.z) & _mask__AbsFloat_) * 0.0022222223;
        if ( v6 <= 1.0 )
          v7 = v6;
        else
          v7 = 1.0;
        m_pPev = this->m_Network.m_pPev;
        volume = v7 * 0.800000011920929;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        CBreakable::MaterialSoundRandom(entindex: (int)m_pPev, soundMaterial: (Materials)this->m_material, volume);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156590
// Name: public: void CGib::StickyGibTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::StickyGibTouch(CGib *this, CBaseEntity *pOther)
{
  unsigned int v3; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int m_iEFlags; // ecx
  CGameTrace tr; // [esp+Ch] [ebp-78h] BYREF
  QAngle angles; // [esp+60h] [ebp-24h] BYREF
  Vector vecForward; // [esp+6Ch] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+78h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+84h] [ebp+0h] BYREF

  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 10.0, szContext: nullptr);
  if ( pOther != nullptr
    && (pOther->m_iClassname.pszValue == "worldspawn"
     || CBaseEntity::ClassMatchesComplex(this: pOther, pszClassOrWildcard: "worldspawn") != 0) )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    v3 = (unsigned int)this->m_iEFlags >> 11;
    x = this->m_vecAbsVelocity.x * 32.0;
    y = this->m_vecAbsVelocity.y * 32.0;
    z = this->m_vecAbsVelocity.z * 32.0;
    vecAbsEnd.x = x;
    vecAbsEnd.y = y;
    vecAbsEnd.z = z;
    if ( (v3 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      y = vecAbsEnd.y;
      x = vecAbsEnd.x;
      z = vecAbsEnd.z;
    }
    m_iEFlags = this->m_iEFlags;
    vecAbsEnd.x = x + this->m_vecAbsOrigin.x;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + y;
    vecAbsEnd.z = this->m_vecAbsOrigin.z + z;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    UTIL_BloodDecalTrace(pTrace: &tr, bloodColor: this->m_bloodColor);
    vecForward.x = tr.plane.normal.x * -1.0;
    vecForward.y = tr.plane.normal.y * -1.0;
    vecForward.z = tr.plane.normal.z * -1.0;
    VectorAngles(forward: &vecForward, &angles);
    CBaseEntity::SetLocalAngles(this, &angles);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156770
// Name: public: void CRagGib::Spawn(char const __near *,class Vector const __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagGib::Spawn(
        CRagGib *this,
        const char *szModel,
        const Vector *vecOrigin,
        const Vector *vecForce,
        float flFadeTime)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  this->SetModel(this, a2: szModel);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  UTIL_SetOrigin(entity: this, vecOrigin, bFireTriggers: false);
  if ( !this->BecomeRagdollOnClient(this, a2: vecForce) )
  {
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
    CCollisionProperty::SetSolidFlags(
      this: &this->m_Collision,
      flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
    if ( flFadeTime > 0.0 )
      CBaseEntity::SUB_StartFadeOut(this, delay: flFadeTime, notSolid: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156870
// Name: public: virtual int CGib::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CGib::ObjectCaps(CGib *this)
{
  return CBaseEntity::ObjectCaps(this) & 0x7FFFFF7E | 0x80000001;
}

//------------------------------------------------------------------------------
// Address: 0x10156880
// Name: public: virtual void CGib::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::OnPhysGunPickup(CGib *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t Reason)
{
  float curtime; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( pPhysGunUser != nullptr )
    this->m_Network.m_pOuter = (CBaseEntity *)pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_Network.m_pOuter = (CBaseEntity *)-1;
  *(float *)&this->m_Network.m_pPev = curtime;
}

//------------------------------------------------------------------------------
// Address: 0x101568D0
// Name: public: virtual class CBasePlayer __near * CGib::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CGib::HasPhysicsAttacker(CGib *this, float dt)
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
// Address: 0x10156930
// Name: public: virtual CGib::~CGib(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::~CGib(CGib *this)
{
  unsigned int m_Index; // eax
  int v3; // eax
  CHandle<CBaseEntity> src; // [esp+4h] [ebp-4h] BYREF

  m_Index = this->m_RefEHandle.m_Index;
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CGib_vtbl *)&CGib::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CGib::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  src.m_Index = m_Index;
  v3 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(this: &CGib::s_ExtantGibs, &src);
  if ( v3 < 0 )
  {
    if ( _executeCount_2 < 20 )
    {
      ++_executeCount_2;
      _Warning(a1: "CGibs are being created which circumvent Spawn() - this can result in a leak.\n");
    }
    CBaseAnimating::~CBaseAnimating(this);
  }
  else
  {
    if ( CGib::s_ExtantGibs.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &CGib::s_ExtantGibs.m_Memory.m_pMemory[v3],
        src: &CGib::s_ExtantGibs.m_Memory.m_pMemory[v3 + 1],
        count: 4 * (CGib::s_ExtantGibs.m_Size - v3 - 1));
    --CGib::s_ExtantGibs.m_Size;
    CBaseAnimating::~CBaseAnimating(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156A00
// Name: class CBaseEntity __near * CreateRagGib(char const __near *,class Vector const __near &,class QAngle const __near &,class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
CRagGib *__cdecl CreateRagGib(
        const char *szModel,
        const Vector *vecOrigin,
        const QAngle *vecAngles,
        const Vector *vecForce,
        float flFadeTime,
        bool bShouldIgnite)
{
  CRagGib *EntityByName; // edi
  CBaseAnimating *v8; // eax
  CBaseAnimating *v9; // esi
  CBaseAnimating_vtbl *v10; // ebx
  float v11; // [esp+14h] [ebp-10h]

  EntityByName = (CRagGib *)CreateEntityByName(className: "raggib", iForceEdictIndex: -1, bNotify: true);
  CBaseEntity::SetLocalAngles(this: EntityByName, angles: vecAngles);
  if ( EntityByName != nullptr )
  {
    if ( bShouldIgnite )
    {
      v8 = EntityByName->GetBaseAnimating(this: EntityByName);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v10 = v8->__vftable;
        v11 = ((double (__thiscall *)(IUniformRandomStream *, int, int, _DWORD, _DWORD, _DWORD))random->RandomFloat)(
                a1: random,
                a2: 1090519040,
                a3: 1094713344,
                a4: 0,
                a5: 0,
                a6: 0);
        ((void (__thiscall *)(CBaseAnimating *, _DWORD))v10->Ignite)(a1: v9, a2: LODWORD(v11));
      }
    }
    CRagGib::Spawn(this: EntityByName, szModel, vecOrigin, vecForce, flFadeTime);
    return EntityByName;
  }
  else
  {
    _Msg(a1: "**Can't create ragdoll gib!\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156B60
// Name: public: void CGib::WaitTillLand(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGib::WaitTillLand(CGib *this@<ecx>, int a2@<ebp>)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *Sprite; // eax
  CSprite *v7; // edi
  unsigned int v8; // eax
  CBaseEntity *Flame; // eax
  CEntityFlame *v10; // eax

  if ( CBaseEntity::IsInWorld(this, a2) )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2);
    if ( vec3_origin.x == this->m_vecAbsVelocity.x
      && vec3_origin.y == this->m_vecAbsVelocity.y
      && vec3_origin.z == this->m_vecAbsVelocity.z )
    {
      if ( this->m_clrRender.m_Value.a != 0xFF )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
        }
        this->m_clrRender.m_Value.a = -1;
      }
      if ( this->m_nRenderMode.m_Value != 2 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v4 = this->m_Network.m_pPev;
          if ( v4 != nullptr )
            CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xB5u);
        }
        this->m_nRenderMode.m_Value = 2;
      }
      if ( this->m_MoveType.m_Value != 6 )
        CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
      CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_lifeTime, szContext: nullptr);
      CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_FadeOut, thinkTime: 0.0, szContext: nullptr);
      m_Index = this->m_hSprite.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        Sprite = CGib::GetSprite(this);
        v7 = (CSprite *)__RTDynamicCast(
                          inptr: Sprite,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CSprite `RTTI Type Descriptor',
                          isReference: 0);
        if ( v7 != nullptr )
        {
          if ( this->m_lifeTime == 0.0 )
            this->m_lifeTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1065353216,
                                 a3: 1077936128);
          CSprite::FadeAndDie(this: v7, duration: this->m_lifeTime);
        }
      }
      v8 = this->m_hFlame.m_Index;
      if ( v8 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == HIWORD(v8)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity != nullptr )
      {
        Flame = CGib::GetFlame(this);
        v10 = (CEntityFlame *)__RTDynamicCast(
                                inptr: Flame,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CEntityFlame `RTTI Type Descriptor',
                                isReference: 0);
        if ( v10 != nullptr )
          CEntityFlame::SetLifetime(this: v10, lifetime: 1.0);
      }
    }
    else
    {
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10156DE0
// Name: public: void CGib::Spawn(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGib::Spawn(CGib *this, const char *szGibModel, float flLifetime)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // eax
  unsigned int m_Index; // ebx
  int m_Size; // eax
  int v10; // edi
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v12; // eax
  CHandle<CBaseEntity> *v13; // eax

  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_FLY_BOUNCE);
  CBaseEntity::SetFriction(this, flFriction: 0.55000001);
  if ( this->m_clrRender.m_Value.a != 0xFF )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = -1;
  }
  if ( this->m_nRenderMode.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 0;
  }
  if ( this->m_nRenderFX.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xB4u);
    }
    this->m_nRenderFX.m_Value = 0;
  }
  if ( this->m_takedamage.m_Value != 1 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 1;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  this->SetModel(this, a2: szGibModel);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 4.0, szContext: nullptr);
  GetRefEHandle = this->GetRefEHandle;
  this->m_lifeTime = flLifetime;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CGib::BounceGibTouch;
  this->m_bForceRemove = false;
  this->m_material = 10;
  this->m_cBloodDecals = 5;
  m_Index = GetRefEHandle(this)->m_Index;
  m_Size = CGib::s_ExtantGibs.m_Size;
  v10 = CGib::s_ExtantGibs.m_Size;
  if ( CGib::s_ExtantGibs.m_Size + 1 > CGib::s_ExtantGibs.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CGib::s_ExtantGibs,
      num: CGib::s_ExtantGibs.m_Size - CGib::s_ExtantGibs.m_Memory.m_nAllocationCount + 1);
    m_Size = CGib::s_ExtantGibs.m_Size;
  }
  m_pMemory = CGib::s_ExtantGibs.m_Memory.m_pMemory;
  CGib::s_ExtantGibs.m_Size = m_Size + 1;
  v12 = m_Size - v10;
  CGib::s_ExtantGibs.m_pElements = CGib::s_ExtantGibs.m_Memory.m_pMemory;
  if ( v12 > 0 )
  {
    _V_memmove(
      dest: &CGib::s_ExtantGibs.m_Memory.m_pMemory[v10 + 1],
      src: &CGib::s_ExtantGibs.m_Memory.m_pMemory[v10],
      count: 4 * v12);
    m_pMemory = CGib::s_ExtantGibs.m_Memory.m_pMemory;
  }
  v13 = &m_pMemory[v10];
  if ( v13 != nullptr )
    v13->m_Index = m_Index;
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_FadeOut, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + this->m_lifeTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10157250
// Name: public: static void CGib::SpawnHeadGib(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGib::SpawnHeadGib(int a1@<ebx>, CBaseEntity *pVictim)
{
  CBaseEntity *EntityByName; // eax
  char *v3; // esi
  CBaseEdict *v4; // ecx
  __int64 v5; // xmm0_8
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  const Vector *v7; // eax
  edict_t *ClientInPVS; // ebx
  CBaseEntity *v9; // ebx
  float *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  double v13; // st7
  __int64 v14; // xmm0_8
  int m_Value; // edi
  float v16; // xmm0_4
  float v17; // [esp+40h] [ebp-24h] BYREF
  float v18; // [esp+44h] [ebp-20h]
  QAngle vecNewAngularVelocity; // [esp+4Ch] [ebp-18h] BYREF
  Vector vecNewVelocity; // [esp+58h] [ebp-Ch] BYREF
  int savedregs; // [esp+64h] [ebp+0h] BYREF

  EntityByName = CreateEntityByName(className: "gib", iForceEdictIndex: -1, bNotify: true);
  v3 = (char *)__RTDynamicCast(
                 inptr: EntityByName,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CGib `RTTI Type Descriptor',
                 isReference: 0);
  if ( v3 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "gib");
  if ( g_Language.m_pParent != nullptr && g_Language.m_pParent->m_Value.m_nValue == 1 )
    CGib::Spawn(this: (CGib *)v3, szGibModel: "models/germangibs.mdl", flLifetime: 25.0);
  else
    CGib::Spawn(this: (CGib *)v3, szGibModel: "models/gibs/hgibs.mdl", flLifetime: 25.0);
  if ( *((_DWORD *)v3 + 220) != 0 )
  {
    if ( v3[84] != 0 )
    {
      v3[88] |= 1u;
    }
    else
    {
      v4 = *((CBaseEdict **)v3 + 6);
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x370u);
    }
    *((_DWORD *)v3 + 220) = 0;
  }
  if ( pVictim != nullptr )
  {
    if ( (*((_DWORD *)v3 + 49) & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this: (CBaseEntity *)v3, a2: (int)&savedregs);
    v5 = *(_QWORD *)(v3 + 364);
    EyePosition = pVictim->EyePosition;
    vecNewVelocity.z = *((float *)v3 + 93);
    *(_QWORD *)&vecNewVelocity.x = v5;
    v7 = (const Vector *)((int (__thiscall *)(CBaseEntity *, float *, int))EyePosition)(a1: pVictim, a2: &v17, a3: a1);
    CBaseEntity::SetLocalOrigin(this: (CBaseEntity *)v3, origin: v7);
    ClientInPVS = UTIL_FindClientInPVS(pEdict: *((edict_t **)v3 + 6));
    if ( random->RandomInt(this: random, a2: 0, a3: 100) <= 5 && ClientInPVS != nullptr )
    {
      v9 = CBaseEntity::Instance(pent: ClientInPVS);
      if ( v9 != nullptr )
      {
        if ( (*((_DWORD *)v3 + 49) & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v3, a2: (int)&savedregs);
        v10 = (float *)v9->EyePosition(this: v9, result: (Vector *)&v17);
        v11 = v10[1] - *((float *)v3 + 116);
        v12 = v10[2] - *((float *)v3 + 117);
        vecNewVelocity.x = *v10 - *((float *)v3 + 115);
        vecNewVelocity.y = v11;
        vecNewVelocity.z = v12;
        VectorNormalize(vec: &vecNewVelocity);
        vecNewVelocity.x = vecNewVelocity.x * 300.0;
        vecNewVelocity.y = vecNewVelocity.y * 300.0;
        vecNewVelocity.z = (float)(vecNewVelocity.z * 300.0) + 100.0;
      }
    }
    else
    {
      v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: -1027080192,
              a3: 1120403456);
      v18 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: -1027080192,
              a3: 1120403456);
      v13 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1128792064,
              a3: 1133903872);
      vecNewVelocity.x = v17;
      vecNewVelocity.y = v18;
      vecNewVelocity.z = v13;
    }
    v14 = *((_QWORD *)v3 + 47);
    vecNewAngularVelocity.z = *((float *)v3 + 96);
    *(_QWORD *)&vecNewAngularVelocity.x = v14;
    vecNewAngularVelocity.x = ((double (__thiscall *)(IUniformRandomStream *, int))random->RandomFloat)(
                                a1: random,
                                a2: 1120403456);
    vecNewAngularVelocity.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                a1: random,
                                a2: 1120403456,
                                a3: 1133903872);
    CBaseEntity::SetLocalAngularVelocity(this: (CBaseEntity *)v3, vecAngVelocity: &vecNewAngularVelocity);
    *((_DWORD *)v3 + 298) = pVictim->BloodColor(this: pVictim);
    m_Value = pVictim->m_iHealth.m_Value;
    if ( m_Value <= -50 )
    {
      if ( m_Value <= -200 )
        v16 = 4.0;
      else
        v16 = 2.0;
    }
    else
    {
      v16 = 0.69999999;
    }
    vecNewVelocity.x = vecNewVelocity.x * v16;
    vecNewVelocity.y = vecNewVelocity.y * v16;
    vecNewVelocity.z = vecNewVelocity.z * v16;
    CBaseEntity::SetAbsVelocity(this: (CBaseEntity *)v3, vecAbsVelocity: &vecNewVelocity);
  }
  CGib::LimitVelocity(this: (CGib *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x101575E0
// Name: public: static void CGib::SpawnRandomGibs(class CBaseEntity __near *,int,enum GibType_e)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CGib::SpawnRandomGibs(CBaseEntity *pVictim, int cGibs, GibType_e eGibType)
{
  CBaseEntity *EntityByName; // eax
  CGib *v4; // esi
  int v5; // eax
  int v6; // ebx
  CBaseEdict *v7; // ecx

  if ( cGibs > 0 )
  {
    while ( 1 )
    {
      EntityByName = CreateEntityByName(className: "gib", iForceEdictIndex: -1, bNotify: true);
      v4 = (CGib *)__RTDynamicCast(
                     inptr: EntityByName,
                     VfDelta: 0,
                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                     TargetType: &CGib `RTTI Type Descriptor',
                     isReference: 0);
      if ( v4 == nullptr )
        _Warning(a1: "classname %s used to create wrong class type\n", "gib");
      if ( g_Language.m_pParent != nullptr && g_Language.m_pParent->m_Value.m_nValue == 1 )
      {
        CGib::Spawn(this: v4, szGibModel: "models/germangibs.mdl", flLifetime: 25.0);
        v5 = random->RandomInt(this: random, a2: 0, a3: 3);
        goto LABEL_11;
      }
      if ( eGibType == GIB_HUMAN )
        break;
      if ( eGibType == GIB_ALIEN )
      {
        CGib::Spawn(this: v4, szGibModel: "models/gibs/agibs.mdl", flLifetime: 25.0);
        v5 = random->RandomInt(this: random, a2: 0, a3: 3);
        goto LABEL_11;
      }
LABEL_17:
      CGib::InitGib(this: v4, pVictim, fMinVelocity: 300.0, fMaxVelocity: 400.0);
      if ( --cGibs == 0 )
        return;
    }
    CGib::Spawn(this: v4, szGibModel: "models/gibs/hgibs.mdl", flLifetime: 25.0);
    v5 = random->RandomInt(this: random, a2: 1, a3: 5);
LABEL_11:
    v6 = v5;
    if ( v4->m_nBody.m_Value != v5 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x370u);
      }
      v4->m_nBody.m_Value = v6;
    }
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404F10
// Name: _dynamic_initializer_for__CGib::s_ExtantGibs__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CGib::s_ExtantGibs__()
{
  return atexit(func: dynamic_atexit_destructor_for__CGib::s_ExtantGibs__);
}

//------------------------------------------------------------------------------
// Address: 0x10404F20
// Name: CGib_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGib_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGib>(__formal: nullptr);
  CGib_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BE90
// Name: _dynamic_atexit_destructor_for__CGib::s_ExtantGibs__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CGib::s_ExtantGibs__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CGib::s_ExtantGibs);
}

//------------------------------------------------------------------------------
// Address: 0x10156AC0
// Name: class CGib __near * _CreateEntityTemplate<class CGib>(class CGib __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGib *__cdecl _CreateEntityTemplate<CGib>(CGib *newEnt, const char *className)
{
  CBaseAnimating *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x4B4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3[291] = &CDefaultPlayerPickupVPhysics::`vftable';
    *v3 = &CGib::`vftable'{for `CBaseAnimating'};
    v3[291] = &CGib::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    v3[296] = -1;
    v3[299] = -1;
    v3[300] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGib *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157010
// Name: struct datamap_t __near * DataMapInit<class CGib>(class CGib __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGib>()
{
  char *Name; // eax

  if ( (_S2_132 & 1) == 0 )
  {
    _S2_132 |= 1u;
    nameHolder_230.m_pszBase = "CGib";
    nameHolder_230.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_230.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_230.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_230.m_Names.m_Size = 0;
    nameHolder_230.m_Names.m_pElements = nullptr;
    nameHolder_230.m_nLenBase = 4;
    atexit(func: DataMapInit_CGib__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGib::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_132 & 2) == 0 )
  {
    _S2_132 |= 2u;
    dataDesc_479[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_230,
                                  pszIdentifier: "BounceGibTouch");
    dataDesc_479[1].flags = 32;
    dataDesc_479[1].fieldOffset = 0;
    dataDesc_479[1].fieldSize = 1;
    dataDesc_479[1].externalName = nullptr;
    dataDesc_479[1].pSaveRestoreOps = nullptr;
    dataDesc_479[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGib::BounceGibTouch;
    *(_QWORD *)&dataDesc_479[1].td = 0;
    *(_QWORD *)&dataDesc_479[1].override_field = 0;
    *(_QWORD *)&dataDesc_479[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_479[1].flatOffset[1] = 0;
    dataDesc_479[2].fieldType = FIELD_VOID;
    dataDesc_479[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_230,
                                  pszIdentifier: "StickyGibTouch");
    dataDesc_479[2].fieldOffset = 0;
    dataDesc_479[2].fieldSize = 1;
    dataDesc_479[2].flags = 32;
    dataDesc_479[2].externalName = nullptr;
    dataDesc_479[2].pSaveRestoreOps = nullptr;
    dataDesc_479[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGib::StickyGibTouch;
    *(_QWORD *)&dataDesc_479[2].td = 0;
    *(_QWORD *)&dataDesc_479[2].override_field = 0;
    *(_QWORD *)&dataDesc_479[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_479[2].flatOffset[1] = 0;
    dataDesc_479[3].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_230, pszIdentifier: "WaitTillLand");
    dataDesc_479[3].fieldSize = 1;
    dataDesc_479[3].fieldName = Name;
    dataDesc_479[3].fieldOffset = 0;
    dataDesc_479[3].flags = 32;
    dataDesc_479[3].externalName = nullptr;
    dataDesc_479[3].pSaveRestoreOps = nullptr;
    dataDesc_479[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGib::WaitTillLand;
    *(_QWORD *)&dataDesc_479[3].td = 0;
    *(_QWORD *)&dataDesc_479[3].override_field = 0;
    *(_QWORD *)&dataDesc_479[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_479[3].flatOffset[1] = 0;
    dataDesc_479[4].fieldType = FIELD_VOID;
    dataDesc_479[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_230,
                                  pszIdentifier: "DieThink");
    dataDesc_479[4].fieldOffset = 0;
    *(_DWORD *)&dataDesc_479[4].fieldSize = 2097153;
    dataDesc_479[4].externalName = nullptr;
    dataDesc_479[4].pSaveRestoreOps = nullptr;
    dataDesc_479[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGib::DieThink;
    *(_QWORD *)&dataDesc_479[4].td = 0;
    *(_QWORD *)&dataDesc_479[4].override_field = 0;
    *(_QWORD *)&dataDesc_479[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_479[4].flatOffset[1] = 0;
  }
  CGib::m_DataMap.dataNumFields = 4;
  CGib::m_DataMap.dataDesc = &dataDesc_479[1];
  return &CGib::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10404F30
// Name: _dynamic_initializer_for__gib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gib__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGib> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &gib,
           a3: "gib");
}

//------------------------------------------------------------------------------
// Address: 0x10404F50
// Name: _dynamic_initializer_for__raggib__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__raggib__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagGib> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &raggib,
           a3: "raggib");
}

//------------------------------------------------------------------------------
// Address: 0x10404F70
// Name: _dynamic_initializer_for__GlobalEventLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__GlobalEventLog__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &GlobalEventLog, name: nullptr);
  GlobalEventLog.__vftable = (CGlobalEventLog_vtbl *)&CGlobalEventLog::`vftable';
  GlobalEventLog.m_Events.m_Memory.m_pMemory = nullptr;
  GlobalEventLog.m_Events.m_Memory.m_nAllocationCount = 0;
  GlobalEventLog.m_Events.m_Memory.m_nGrowSize = 0;
  GlobalEventLog.m_Events.m_Size = 0;
  GlobalEventLog.m_Events.m_pElements = nullptr;
  GlobalEventLog.m_TempEvents.m_Memory.m_pMemory = nullptr;
  GlobalEventLog.m_TempEvents.m_Memory.m_nAllocationCount = 0;
  GlobalEventLog.m_TempEvents.m_Memory.m_nGrowSize = 0;
  GlobalEventLog.m_TempEvents.m_Size = 0;
  GlobalEventLog.m_TempEvents.m_pElements = nullptr;
  GlobalEventLog.m_DirtyEvents.m_Memory.m_pMemory = nullptr;
  GlobalEventLog.m_DirtyEvents.m_Memory.m_nAllocationCount = 0;
  GlobalEventLog.m_DirtyEvents.m_Memory.m_nGrowSize = 0;
  GlobalEventLog.m_DirtyEvents.m_Size = 0;
  GlobalEventLog.m_DirtyEvents.m_pElements = nullptr;
  GlobalEventLog.m_nNextID = 1;
  return atexit(func: dynamic_atexit_destructor_for__GlobalEventLog__);
}

//------------------------------------------------------------------------------
// Address: 0x10405000
// Name: _dynamic_initializer_for__EventSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__EventSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &EventSymbols, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__EventSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BEA0
// Name: _DataMapInit_CGib__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGib__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_230);
}

//------------------------------------------------------------------------------
// Address: 0x1041BEB0
// Name: _dynamic_atexit_destructor_for__EventSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__EventSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &EventSymbols);
}
