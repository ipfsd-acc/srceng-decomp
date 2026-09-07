// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/explode.cpp
// Functions: 30
// ============================================================

#include "game\server\explode.h"

//------------------------------------------------------------------------------
// Address: 0x10122780
// Name: public: virtual struct datamap_t __near * CEnvExplosion::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvExplosion::GetDataDescMap(CEnvExplosion *this)
{
  return &CEnvExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10122790
// Name: public: virtual int CEnvExplosion::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEnvExplosion::DrawDebugTextOverlays(CEnvExplosion *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    magnitude: %i", this->m_iMagnitude);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10122810
// Name: public: virtual void CShower::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShower::Think(CShower *this@<ecx>, int a2@<ebp>)
{
  float v3; // xmm0_4

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  g_pEffects->Sparks(this: g_pEffects, a2: &this->m_vecAbsOrigin, a3: 1, a4: 1, a5: nullptr);
  v3 = this->m_flSpeed - 0.1;
  this->m_flSpeed = v3;
  if ( v3 <= 0.0 )
    UTIL_Remove(oldObj: this);
  else
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CBaseEntity::SetGroundEntity(this, ground: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101228B0
// Name: public: virtual bool CEnvExplosion::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvExplosion::KeyValue(CEnvExplosion *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "fireballsprite" && _V_stricmp(s1: szKeyName, s2: "fireballsprite") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  this->m_iszFireballSprite.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10122910
// Name: public: virtual void CEnvExplosion::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvExplosion::Precache(CEnvExplosion *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // eax

  if ( this->m_iszFireballSprite.pszValue != nullptr )
  {
    pszValue = this->m_iszFireballSprite.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    this->m_sFireballSprite = CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
  }
  CBaseEntity::PrecacheScriptSound(soundname: "explode_3");
}

//------------------------------------------------------------------------------
// Address: 0x10122950
// Name: public: virtual void CEnvExplosion::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvExplosion::Spawn(CEnvExplosion *this)
{
  int m_Value; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm1_4

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  m_Value = this->m_spawnflags.m_Value;
  v3 = (double)(this->m_iMagnitude - 50) * 0.6;
  if ( (m_Value & 0x800) != 0 )
    v4 = 1.0;
  else
    v4 = 10.0;
  if ( v4 > v3 )
    v3 = v4;
  if ( (m_Value & 0x1000) != 0 )
    v5 = 200.0;
  else
    v5 = 50.0;
  if ( v3 > v5 )
    v3 = v5;
  this->m_spriteScale = (int)v3;
  this->m_iCustomDamageType = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10122A00
// Name: public: void CEnvExplosion::Smoke(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvExplosion::Smoke(CEnvExplosion *this)
{
  if ( (this->m_spawnflags.m_Value & 2) == 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10122AA0
// Name: public: virtual void CShower::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShower::Spawn(CShower *this)
{
  double v2; // st7
  double v3; // st7
  float v4; // xmm0_4
  Vector vecForward; // [esp+24h] [ebp-1Ch] BYREF
  Vector vecNewVelocity; // [esp+30h] [ebp-10h] BYREF
  float v7; // [esp+3Ch] [ebp-4h]

  AngleVectors(angles: &this->m_angRotation.m_Value, forward: &vecForward);
  v7 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: 1128792064,
         a3: 1133903872);
  vecNewVelocity.x = vecForward.x * v7;
  vecNewVelocity.y = vecForward.y * v7;
  vecNewVelocity.z = vecForward.z * v7;
  v2 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1027080192,
         a3: 1120403456);
  vecNewVelocity.x = v2 + vecNewVelocity.x;
  v3 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1027080192,
         a3: 1120403456);
  vecNewVelocity.y = v3 + vecNewVelocity.y;
  if ( vecNewVelocity.z < 0.0 )
    v4 = vecNewVelocity.z - 200.0;
  else
    v4 = vecNewVelocity.z + 200.0;
  vecNewVelocity.z = v4;
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecNewVelocity);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_FLY_BOUNCE);
  this->m_flGravity = UTIL_ScaleForGravity(desiredGravity: 400.0);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->m_flSpeed = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                      a1: random,
                      a2: 1056964608,
                      a3: 1069547520);
  CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
}

//------------------------------------------------------------------------------
// Address: 0x10122C60
// Name: public: virtual void CShower::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShower::Touch(CShower *this, CBaseEntity *pOther)
{
  bool v3; // zf
  float z; // ecx
  float v5; // xmm2_4
  Vector vecNewVelocity; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  v3 = (this->m_fFlags.m_Value & 1) == 0;
  z = this->m_vecAbsVelocity.z;
  *(_QWORD *)&vecNewVelocity.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
  vecNewVelocity.z = z;
  if ( v3 )
    v5 = 0.60000002;
  else
    v5 = 0.1;
  vecNewVelocity.y = vecNewVelocity.y * v5;
  vecNewVelocity.x = vecNewVelocity.x * v5;
  vecNewVelocity.z = z * v5;
  if ( (float)((float)(vecNewVelocity.y * vecNewVelocity.y) + (float)(vecNewVelocity.x * vecNewVelocity.x)) < 10.0 )
    this->m_flSpeed = 0.0;
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecNewVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x10122D10
// Name: public: void CEnvExplosion::InputExplode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvExplosion::InputExplode(CEnvExplosion *this, inputdata_t *inputdata)
{
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // edx
  int m_Value; // eax
  int v7; // eax
  int v8; // edi
  unsigned __int8 v9; // cl
  int m_iRadiusOverride; // eax
  float v11; // xmm0_4
  double v12; // xmm0_8
  int v13; // eax
  float v14; // xmm0_4
  int v15; // edx
  unsigned int m_Index; // ecx
  CBaseEntityList *v17; // ebx
  int v18; // eax
  CEntInfo *v19; // edi
  unsigned int v20; // ecx
  int v21; // eax
  bool v22; // zf
  CBaseEntity **v23; // eax
  int m_iCustomDamageType; // edi
  unsigned int v25; // eax
  const CBaseHandle *v26; // eax
  CBaseEntity *m_pEntity; // eax
  unsigned int v28; // eax
  CBaseEntity *v29; // edi
  int v30; // eax
  int i; // esi
  CTakeDamageInfo info; // [esp+48h] [ebp-100h] BYREF
  CGameTrace tr; // [esp+A4h] [ebp-A4h] BYREF
  CPASFilter filter; // [esp+F8h] [ebp-50h] BYREF
  Vector vecAbsEnd; // [esp+118h] [ebp-30h] BYREF
  QAngle angles; // [esp+124h] [ebp-24h] BYREF
  Vector vecExplodeOrigin; // [esp+130h] [ebp-18h] BYREF
  CBaseEntity *pAttacker; // [esp+13Ch] [ebp-Ch]
  int iRadius; // [esp+140h] [ebp-8h]
  unsigned int v40; // [esp+144h] [ebp-4h]
  IHandleEntity savedregs; // [esp+148h] [ebp+0h] BYREF

  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  x = this->m_vecAbsOrigin.x;
  y = this->m_vecAbsOrigin.y;
  angles.z = this->m_vecAbsOrigin.z + 8.0;
  angles.x = x;
  angles.y = y;
  vecAbsEnd.x = x;
  vecAbsEnd.y = y;
  vecAbsEnd.z = angles.z - 40.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: (const Vector *)&angles,
    &vecAbsEnd,
    mask: 0x403Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecExplodeOrigin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecExplodeOrigin.z = z;
  if ( tr.fraction != 1.0 )
  {
    vecExplodeOrigin.x = tr.endpos.x + (float)(tr.plane.normal.x * 24.0);
    vecExplodeOrigin.y = tr.endpos.y + (float)(tr.plane.normal.y * 24.0);
    vecExplodeOrigin.z = tr.endpos.z + (float)(tr.plane.normal.z * 24.0);
  }
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x10) == 0 )
  {
    if ( (m_Value & 0x8000) != 0 )
      UTIL_DecalTrace(pTrace: &tr, decalName: "Ice_Explosion_Decal");
    else
      UTIL_DecalTrace(pTrace: &tr, decalName: "Scorch");
  }
  v7 = this->m_spawnflags.m_Value;
  v8 = 0;
  if ( (v7 & 4) != 0 )
    v8 = 64;
  if ( (v7 & 0x40) != 0 )
    v8 |= 4u;
  if ( (v7 & 0x80u) != 0 )
    v8 |= 0x20u;
  v9 = this->m_nRenderMode.m_Value;
  if ( v9 == 4 )
  {
    v8 |= 0x10u;
  }
  else if ( v9 != 5 )
  {
    v8 |= 1u;
  }
  if ( (v7 & 0x200) != 0 )
    v8 |= 8u;
  if ( (v7 & 0x400) == 0 )
    v8 |= 2u;
  if ( (v7 & 0x100) != 0 )
    v8 |= 0x80u;
  if ( (v7 & 0x8000) != 0 )
    v8 |= 0x100u;
  m_iRadiusOverride = this->m_iRadiusOverride;
  if ( m_iRadiusOverride <= 0 )
    v11 = (float)this->m_iMagnitude * 2.5;
  else
    v11 = (float)m_iRadiusOverride;
  iRadius = (int)v11;
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &vecExplodeOrigin);
  if ( (this->m_spawnflags.m_Value & 4) != 0 )
    v12 = 0.0;
  else
    v12 = (double)this->m_spriteScale * 0.1;
  LOWORD(v13) = this->m_sFireballSprite;
  if ( (__int16)v13 >= 1 )
    v13 = (__int16)v13;
  else
    v13 = g_sModelIndexFireball;
  v14 = v12;
  ((void (__stdcall *)(CPASFilter *, _DWORD, Vector *, int, _DWORD, int, int, int, int, _DWORD, int))te->Explosion)(
    a1: &filter,
    a2: 0,
    a3: &vecExplodeOrigin,
    a4: v13,
    a5: LODWORD(v14),
    a6: 15,
    a7: v8,
    a8: iRadius,
    a9: this->m_iMagnitude,
    a10: 0,
    a11: 67);
  v15 = this->m_spawnflags.m_Value;
  if ( (v15 & 1) == 0 )
  {
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    v17 = g_pEntityList;
    if ( m_Index != -1
      && (v18 = (unsigned __int16)m_Index,
          v19 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v20 = HIWORD(m_Index),
          v19->m_SerialNumber == v20)
      && v19->m_pEntity != nullptr )
    {
      v21 = v18;
      v22 = g_pEntityList->m_EntPtrArray[v21].m_SerialNumber == v20;
      v23 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v21];
      if ( v22 )
        pAttacker = *v23;
      else
        pAttacker = nullptr;
    }
    else
    {
      pAttacker = this;
    }
    m_iCustomDamageType = this->m_iCustomDamageType;
    if ( m_iCustomDamageType == -1 )
      m_iCustomDamageType = ((v15 & 0x4000) == 0) << 6;
    v25 = this->m_hInflictor.m_Index;
    if ( v25 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber == HIWORD(v25)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity != nullptr )
    {
      v40 = this->m_hInflictor.m_Index;
    }
    else
    {
      v26 = this->GetRefEHandle(this);
      v17 = g_pEntityList;
      v40 = v26->m_Index;
    }
    if ( v40 == -1 || v17->m_EntPtrArray[(unsigned __int16)v40].m_SerialNumber != HIWORD(v40) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)v17->m_EntPtrArray[(unsigned __int16)v40].m_pEntity;
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: m_pEntity,
      pAttacker,
      flDamage: (float)this->m_iMagnitude,
      bitsDamageType: m_iCustomDamageType,
      iKillType: 0,
      iObjectsPenetrated: 0);
    if ( (this->m_spawnflags.m_Value & 0x2000) != 0 )
      info.m_bitsDamageType |= 0x8000000u;
    if ( this->m_flDamageForce != 0.0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      info.m_vecDamagePosition = this->m_vecAbsOrigin;
      info.m_vecDamageForce.x = this->m_flDamageForce;
      info.m_vecDamageForce.y = 0.0;
      info.m_vecDamageForce.z = 0.0;
    }
    v28 = this->m_hEntityIgnore.m_Index;
    if ( v28 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_SerialNumber != HIWORD(v28) )
      v29 = nullptr;
    else
      v29 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_pEntity;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    RadiusDamage(
      &info,
      vecSrc: &this->m_vecAbsOrigin,
      flRadius: (float)iRadius,
      iClassIgnore: this->m_iClassIgnore,
      pEntityIgnore: v29);
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvExplosion::Smoke,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.3, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: &this->m_vecAbsOrigin, a3: 16432, a4: nullptr) & 0x20) != 0
    && (this->m_spawnflags.m_Value & 0x20) == 0 )
  {
    v30 = random->RandomInt(this: random, a2: 0, a3: 3);
    if ( v30 > 0 )
    {
      for ( i = v30; i != 0; --i )
      {
        VectorAngles(forward: &tr.plane.normal, &angles);
        CBaseEntity::Create(szName: "spark_shower", vecOrigin: &vecExplodeOrigin, vecAngles: &angles, pOwner: nullptr);
      }
    }
  }
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x101232E0
// Name: void ExplosionCreate(class Vector const __near &,class QAngle const __near &,class CBaseEntity __near *,int,int,int,float,class CBaseEntity __near *,int,class CHandle<class CBaseEntity> const __near *,enum Class_T)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExplosionCreate(
        const Vector *center,
        const QAngle *angles,
        CBaseEntity *pOwner,
        int magnitude,
        int radius,
        int nSpawnFlags,
        float flExplosionForce,
        CBaseEntity *pInflictor,
        unsigned int iCustomDamageType,
        const CHandle<CBaseEntity> *ignoredEntity,
        Class_T ignoredClass)
{
  CHandle<CBaseEntity> *v11; // esi
  int v12; // edi
  CBaseEdict *m_Index; // ecx
  bool v14; // zf
  CBaseEdict *v15; // ecx
  __m128i v16; // xmm0
  float v17; // ecx
  char buf[128]; // [esp+24h] [ebp-94h] BYREF
  variant_t emptyVariant; // [esp+A4h] [ebp-14h] BYREF

  v11 = (CHandle<CBaseEntity> *)CBaseEntity::Create(
                                  szName: "env_explosion",
                                  vecOrigin: center,
                                  vecAngles: angles,
                                  pOwner);
  V_snprintf(pDest: buf, maxLen: 128, pFormat: "%3d", magnitude);
  (*(void (__thiscall **)(CHandle<CBaseEntity> *, const char *, char *))(v11->m_Index + 136))(
    a1: v11,
    a2: "iMagnitude",
    a3: buf);
  v12 = nSpawnFlags | v11[190].m_Index;
  if ( v11[190].m_Index != v12 )
  {
    if ( LOBYTE(v11[21].m_Index) != 0 )
    {
      LOBYTE(v11[22].m_Index) |= 1u;
    }
    else
    {
      m_Index = (CBaseEdict *)v11[6].m_Index;
      if ( m_Index != nullptr )
        CBaseEdict::StateChanged(this: m_Index, offset: 0x2F8u);
    }
    v11[190].m_Index = v12;
  }
  if ( radius != 0 )
  {
    V_snprintf(pDest: buf, maxLen: 128, pFormat: "%d", radius);
    (*(void (__thiscall **)(CHandle<CBaseEntity> *, const char *, char *))(v11->m_Index + 136))(
      a1: v11,
      a2: "iRadiusOverride",
      a3: buf);
  }
  if ( flExplosionForce != 0.0 )
  {
    V_snprintf(pDest: buf, maxLen: 128, pFormat: "%.3f", flExplosionForce);
    (*(void (__thiscall **)(CHandle<CBaseEntity> *, const char *, char *))(v11->m_Index + 136))(
      a1: v11,
      a2: "DamageForce",
      a3: buf);
  }
  v14 = BYTE1(v11[45].m_Index) == 5;
  emptyVariant.iVal = 0;
  if ( !v14 )
  {
    if ( LOBYTE(v11[21].m_Index) != 0 )
    {
      LOBYTE(v11[22].m_Index) |= 1u;
    }
    else
    {
      v15 = (CBaseEdict *)v11[6].m_Index;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: v15, offset: 0xB5u);
    }
    BYTE1(v11[45].m_Index) = 5;
  }
  (*(void (__thiscall **)(CHandle<CBaseEntity> *, CBaseEntity *))(v11->m_Index + 72))(a1: v11, a2: pOwner);
  (*(void (__thiscall **)(CHandle<CBaseEntity> *))(v11->m_Index + 96))(a1: v11);
  if ( pInflictor != nullptr )
    v11[219].m_Index = pInflictor->GetRefEHandle(this: pInflictor)->m_Index;
  else
    v11[219].m_Index = -1;
  v11[220].m_Index = iCustomDamageType;
  if ( ignoredEntity != nullptr )
    v11[222].m_Index = ignoredEntity->m_Index;
  v16 = _mm_loadl_epi64((const __m128i *)&emptyVariant);
  v17 = emptyVariant.vecVal[2];
  v11[221].m_Index = ignoredClass;
  (*(void (__thiscall **)(CHandle<CBaseEntity> *, const char *, _DWORD, _DWORD, _DWORD, int, float, int, _DWORD, _DWORD))(v11->m_Index + 156))(
    a1: v11,
    a2: "Explode",
    a3: 0,
    a4: 0,
    a5: 0,
    a6: v16.m128i_i32[1],
    a7: COERCE_FLOAT(LODWORD(v17)),
    a8: -1,
    a9: 0,
    a10: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101234E0
// Name: void ExplosionCreate(class Vector const __near &,class QAngle const __near &,class CBaseEntity __near *,int,int,bool,float,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExplosionCreate(
        const Vector *center,
        const QAngle *angles,
        CBaseEntity *pOwner,
        int magnitude,
        int radius,
        bool doDamage,
        float flExplosionForce,
        bool bSurfaceOnly,
        bool bSilent,
        unsigned int iCustomDamageType)
{
  int v10; // eax

  v10 = 1064;
  if ( !doDamage )
    v10 = 1065;
  if ( bSurfaceOnly )
    v10 |= 0x2000u;
  if ( bSilent )
    v10 |= 0x40u;
  ExplosionCreate(
    center,
    angles,
    pOwner,
    magnitude,
    radius,
    nSpawnFlags: v10,
    flExplosionForce,
    pInflictor: nullptr,
    iCustomDamageType,
    ignoredEntity: nullptr,
    ignoredClass: CLASS_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x10400E80
// Name: _dynamic_initializer_for__explode_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__explode_command__()
{
  ConCommand::ConCommand(
    this: &explode_command,
    pName: "explode",
    callback: (void (__cdecl *)())explode,
    pHelpString: "Kills the player with explosive damage",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__explode_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10402FE0
// Name: CEnvExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvExplosion_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvExplosion>(__formal: nullptr);
  CEnvExplosion_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A2A0
// Name: _dynamic_atexit_destructor_for__explode_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__explode_command__()
{
  ConCommand::~ConCommand(this: &explode_command);
}

//------------------------------------------------------------------------------
// Address: 0x10123540
// Name: struct datamap_t __near * DataMapInit<class CEnvExplosion>(class CEnvExplosion __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvExplosion>()
{
  if ( (_S2_101 & 1) == 0 )
  {
    _S2_101 |= 1u;
    nameHolder_185.m_pszBase = "CEnvExplosion";
    nameHolder_185.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_185.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_185.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_185.m_Names.m_Size = 0;
    nameHolder_185.m_Names.m_pElements = nullptr;
    nameHolder_185.m_nLenBase = 13;
    atexit(func: DataMapInit_CEnvExplosion__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvExplosion::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_101 & 2) == 0 )
  {
    _S2_101 |= 2u;
    dataDesc_175[11].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_185,
                                   pszIdentifier: "Smoke");
    *(_QWORD *)&dataDesc_175[11].td = 0;
    *(_QWORD *)&dataDesc_175[11].override_field = 0;
    *(_QWORD *)&dataDesc_175[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_175[11].flatOffset[1] = 0;
    dataDesc_175[11].fieldOffset = 0;
    dataDesc_175[11].fieldSize = 1;
    dataDesc_175[11].flags = 32;
    dataDesc_175[11].externalName = nullptr;
    dataDesc_175[11].pSaveRestoreOps = nullptr;
    dataDesc_175[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvExplosion::Smoke;
    dataDesc_175[12].fieldType = FIELD_VOID;
    dataDesc_175[12].fieldName = "InputExplode";
    dataDesc_175[12].fieldOffset = 0;
    *(_DWORD *)&dataDesc_175[12].fieldSize = 524289;
    dataDesc_175[12].externalName = "Explode";
    dataDesc_175[12].pSaveRestoreOps = nullptr;
    dataDesc_175[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvExplosion::InputExplode;
    *(_QWORD *)&dataDesc_175[12].td = 0;
    *(_QWORD *)&dataDesc_175[12].override_field = 0;
    *(_QWORD *)&dataDesc_175[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_175[12].flatOffset[1] = 0;
  }
  CEnvExplosion::m_DataMap.dataNumFields = 12;
  CEnvExplosion::m_DataMap.dataDesc = &dataDesc_175[1];
  return &CEnvExplosion::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400EB0
// Name: _dynamic_initializer_for__killvector_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__killvector_command__()
{
  ConCommand::ConCommand(
    this: &killvector_command,
    pName: "killvector",
    callback: (void (__cdecl *)())killvector,
    pHelpString: "Kills a player applying force. Usage: killvector <player> <x value> <y value> <z value>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__killvector_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400EE0
// Name: _dynamic_initializer_for__explodevector_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__explodevector_command__()
{
  ConCommand::ConCommand(
    this: &explodevector_command,
    pName: "explodevector",
    callback: (void (__cdecl *)())explodevector,
    pHelpString: "Kills a player applying an explosive force. Usage: explodevector <player> <x value> <y value> <z value>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__explodevector_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400F10
// Name: _dynamic_initializer_for__buddha_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__buddha_command__()
{
  ConCommand::ConCommand(
    this: &buddha_command,
    pName: "buddha",
    callback: buddha,
    pHelpString: "Toggle.  Player takes damage but won't die. (Shows red cross when health is zero)",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buddha_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400F40
// Name: _dynamic_initializer_for__say_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__say_command__()
{
  ConCommand::ConCommand(
    this: &say_command,
    pName: "say",
    callback: (void (__cdecl *)())say,
    pHelpString: "Display player message",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__say_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400F70
// Name: _dynamic_initializer_for__say_team_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__say_team_command__()
{
  ConCommand::ConCommand(
    this: &say_team_command,
    pName: "say_team",
    callback: (void (__cdecl *)())say_team,
    pHelpString: "Display player message to team",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__say_team_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400FA0
// Name: _dynamic_initializer_for__give_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__give_command__()
{
  ConCommand::ConCommand(
    this: &give_command,
    pName: "give",
    callback: (void (__cdecl *)())give,
    pHelpString: "Give item to player.\n\tArguments: <item_name>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__give_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10400FD0
// Name: _dynamic_initializer_for__setmodel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setmodel__()
{
  ConCommand::ConCommand(
    this: &setmodel,
    pName: "setmodel",
    callback: (void (__cdecl *)())CC_Player_SetModel,
    pHelpString: "Changes's player's model",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setmodel__);
}

//------------------------------------------------------------------------------
// Address: 0x1041A2B0
// Name: _dynamic_atexit_destructor_for__killvector_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__killvector_command__()
{
  ConCommand::~ConCommand(this: &killvector_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A2C0
// Name: _dynamic_atexit_destructor_for__explodevector_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__explodevector_command__()
{
  ConCommand::~ConCommand(this: &explodevector_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A2D0
// Name: _dynamic_atexit_destructor_for__buddha_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buddha_command__()
{
  ConCommand::~ConCommand(this: &buddha_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A2E0
// Name: _dynamic_atexit_destructor_for__say_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__say_command__()
{
  ConCommand::~ConCommand(this: &say_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A2F0
// Name: _dynamic_atexit_destructor_for__say_team_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__say_team_command__()
{
  ConCommand::~ConCommand(this: &say_team_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A300
// Name: _dynamic_atexit_destructor_for__give_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__give_command__()
{
  ConCommand::~ConCommand(this: &give_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041A310
// Name: _dynamic_atexit_destructor_for__setmodel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setmodel__()
{
  ConCommand::~ConCommand(this: &setmodel);
}
