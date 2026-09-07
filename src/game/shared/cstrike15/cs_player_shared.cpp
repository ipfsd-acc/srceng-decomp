// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_player_shared.cpp
// Functions: 24
// ============================================================

#include "game\shared\cstrike15\cs_player_shared.h"

//------------------------------------------------------------------------------
// Address: 0x101C6AF0
// Name: public: void C_CSPlayer::GetBulletTypeParameters(int,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::GetBulletTypeParameters(
        C_CSPlayer *this,
        int iBulletType,
        float *fPenetrationPower,
        float *flPenetrationDistance)
{
  int v4; // xmm0_4

  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_50AE") )
  {
    *fPenetrationPower = 30.0;
    *flPenetrationDistance = 1000.0;
    return;
  }
  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_762MM") )
  {
    *fPenetrationPower = 39.0;
    *flPenetrationDistance = 5000.0;
    return;
  }
  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_556MM")
    || IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_556MM_BOX") )
  {
    *fPenetrationPower = 35.0;
    *flPenetrationDistance = 4000.0;
  }
  else
  {
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_338MAG") )
    {
      *fPenetrationPower = 45.0;
      *flPenetrationDistance = 8000.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_9MM") )
    {
      v4 = 1101529088;
LABEL_17:
      *(_DWORD *)fPenetrationPower = v4;
      *flPenetrationDistance = 800.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_BUCKSHOT") )
    {
      *fPenetrationPower = 0.0;
      *flPenetrationDistance = 0.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_45ACP") )
    {
      *fPenetrationPower = 15.0;
      *flPenetrationDistance = 500.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_357SIG") )
    {
      v4 = 1103626240;
      goto LABEL_17;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_57MM") )
    {
      *fPenetrationPower = 30.0;
      *flPenetrationDistance = 2000.0;
    }
    else
    {
      IsAmmoType(iAmmoType: iBulletType, pAmmoName: "AMMO_TYPE_TASERCHARGE");
      *fPenetrationPower = 0.0;
      *flPenetrationDistance = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6D10
// Name: public: void C_CSPlayer::CreateWeaponTracer(class Vector,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_CSPlayer::CreateWeaponTracer(
        C_CSPlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        Vector vecStart,
        Vector vecEnd)
{
  C_CSPlayer *v5; // edi
  int v6; // ebx
  C_CSPlayer *LocalPlayer; // esi
  bool v8; // bl
  C_BaseViewModel *ViewModel; // eax
  C_BaseViewModel *v10; // esi
  int v11; // eax
  int v12; // eax
  C_BaseEntity *v13; // esi
  int v14; // eax
  int v15; // edi
  int m_iTracerFequency; // ecx
  int v17; // edx
  const char *v18; // eax
  int iEntIndex; // [esp+4h] [ebp-18h]
  C_WeaponCSBase *pWeapon; // [esp+8h] [ebp-14h]
  int iAttachment; // [esp+Ch] [ebp-10h]
  int nModelIndex; // [esp+14h] [ebp-8h]
  bool bUseObserverTarget; // [esp+1Bh] [ebp-1h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v5 = this;
  pWeapon = (C_WeaponCSBase *)C_CSPlayer::GetActiveCSWeapon(this);
  if ( pWeapon != nullptr )
  {
    iEntIndex = v5->entindex(this: &v5->IClientNetworkable);
    bUseObserverTarget = false;
    v6 = 0;
    while ( 1 )
    {
      LocalPlayer = CClientTools::GetLocalPlayer();
      if ( LocalPlayer != nullptr
        && LocalPlayer->GetObserverTarget(this: LocalPlayer) == v5
        && LocalPlayer->GetObserverMode(this: LocalPlayer) == 4 )
      {
        break;
      }
      if ( ++v6 != 0 )
        goto LABEL_9;
    }
    bUseObserverTarget = true;
LABEL_9:
    v8 = clienttools->IsInRecordingMode(this: clienttools);
    if ( C_BasePlayer::IsLocalPlayer(pEntity: v5) && !v8 || bUseObserverTarget )
    {
      ViewModel = C_BasePlayer::GetViewModel(this: v5, index: 0);
      v10 = ViewModel;
      if ( ViewModel != nullptr )
      {
        v11 = ViewModel->LookupAttachment(this: &ViewModel->IClientRenderable, a2: "1");
        v10->GetAttachment(this: v10, a2: v11, a3: &vecStart);
      }
    }
    else if ( !v5->IsDormant(this: &v5->IClientNetworkable) )
    {
      v12 = (int)v5->GetActiveWeapon(this: v5);
      v13 = (C_BaseEntity *)v12;
      if ( v12 != 0 )
      {
        iAttachment = (*(int (__thiscall **)(int, const char *, int, int))(*(_DWORD *)(v12 + 4) + 132))(
                        a1: v12 + 4,
                        a2: "muzzle_flash",
                        a3,
                        a4: a2);
        nModelIndex = C_BaseEntity::GetModelIndex(this: v13);
        v14 = ((int (__thiscall *)(C_BaseEntity *))v13->IClientEntity::IClientUnknown::IHandleEntity::__vftable[2].IsBlurred)(a1: v13);
        v15 = v14;
        if ( v8 && nModelIndex != v14 )
          C_BaseEntity::SetModelIndex(this: v13, index: v14);
        v13->GetAttachment(this: v13, a2: iAttachment, a3: &vecStart);
        if ( v8 && nModelIndex != v15 )
          C_BaseEntity::SetModelIndex(this: v13, index: nModelIndex);
        v5 = this;
      }
    }
    m_iTracerFequency = C_WeaponCSBase::GetCSWpnData(this: pWeapon)->m_iTracerFequency;
    if ( m_iTracerFequency == 0
      || (v17 = tracerCount_0 % m_iTracerFequency, ++tracerCount_0, v17 != 0)
      || pWeapon->IsSilenced(this: pWeapon) )
    {
      FX_TracerSound(a1: COERCE_FLOAT(&savedregs), start: &vecStart, end: &vecEnd, iTracerType: 1);
    }
    else
    {
      v18 = v5->GetTracerType(this: v5);
      if ( v18 != nullptr && *v18 != 0 )
        UTIL_ParticleTracer(pszTracerEffectName: v18, &vecStart, &vecEnd, iEntIndex, iAttachment: -1, bWhiz: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6EF0
// Name: public: virtual unsigned int C_CSPlayer::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_CSPlayer::PhysicsSolidMaskForEntity(C_CSPlayer *this)
{
  unsigned int result; // eax

  if ( !C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) )
    return 33636363;
  switch ( this->GetTeamNumber(this) )
  {
    case 2:
      result = 33638411;
      break;
    case 3:
      result = 33640459;
      break;
    default:
      return 33636363;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6F40
// Name: public: void C_CSPlayer::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::OnJump(C_CSPlayer *this, float fImpulse)
{
  C_BaseCombatWeapon *ActiveCSWeapon; // eax

  ActiveCSWeapon = C_CSPlayer::GetActiveCSWeapon(this);
  if ( ActiveCSWeapon != nullptr )
    ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD))ActiveCSWeapon->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetIClientEntity)(
      a1: ActiveCSWeapon,
      a2: LODWORD(fImpulse));
}

//------------------------------------------------------------------------------
// Address: 0x101C6F70
// Name: public: void C_CSPlayer::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::OnLand(C_CSPlayer *this, float fVelocity)
{
  C_BaseCombatWeapon *ActiveCSWeapon; // eax

  ActiveCSWeapon = C_CSPlayer::GetActiveCSWeapon(this);
  if ( ActiveCSWeapon != nullptr )
    ((void (__thiscall *)(C_BaseCombatWeapon *, _DWORD))ActiveCSWeapon->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetBaseEntity)(
      a1: ActiveCSWeapon,
      a2: LODWORD(fVelocity));
}

//------------------------------------------------------------------------------
// Address: 0x101C6FA0
// Name: public: virtual class C_WeaponCSBase __near * C_CSPlayer::CSAnim_GetActiveWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_WeaponCSBase *__thiscall C_CSPlayer::CSAnim_GetActiveWeapon(C_CSPlayer *this)
{
  return (C_WeaponCSBase *)C_CSPlayer::GetActiveCSWeapon(this: (C_CSPlayer *)((char *)this - 6732));
}

//------------------------------------------------------------------------------
// Address: 0x101C6FB0
// Name: public: virtual class ClientClass __near * C_FootstepControl::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FootstepControl::GetClientClass(C_FootstepControl *this)
{
  return &__g_C_FootstepControlClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101C7070
// Name: public: virtual float C_CSPlayer::GetPlayerMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSPlayer::GetPlayerMaxSpeed(C_CSPlayer *this)
{
  double PlayerMaxSpeed; // st7
  C_BaseCombatWeapon *v4; // eax
  void *v5; // eax
  float speed; // [esp+4h] [ebp-4h]

  if ( this->m_MoveType == 0 )
    return 1.0;
  if ( this->GetObserverMode(this) != 0 )
    return 900.0;
  if ( C_CSPlayer::State_Get(this) != STATE_ACTIVE && C_CSPlayer::State_Get(this) != STATE_OBSERVER_MODE
    || this->m_bIsDefusing.m_Value
    || C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)g_pGameRules) )
  {
    return 1.0;
  }
  PlayerMaxSpeed = C_BasePlayer::GetPlayerMaxSpeed(this);
  speed = PlayerMaxSpeed;
  if ( PlayerMaxSpeed > 260.0 )
    speed = 260.0;
  if ( C_CSPlayer::IsVIP(this) )
    return 227.0;
  v4 = this->GetActiveWeapon(this);
  v5 = __RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
    return (float)((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v5 + 1488))(a1: v5);
  return speed;
}

//------------------------------------------------------------------------------
// Address: 0x101C7170
// Name: public: virtual void C_CSPlayer::UpdateStepSound(struct surfacedata_t __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_CSPlayer::UpdateStepSound(
        C_CSPlayer *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        surfacedata_t *psurface,
        const Vector *vecOrigin,
        const Vector *vecVelocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( (float)((float)(vecVelocity->x * vecVelocity->x) + (float)(vecVelocity->y * vecVelocity->y)) >= 22500.0 )
    C_BasePlayer::UpdateStepSound(this, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3, psurface, vecOrigin, vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x101C71B0
// Name: public: void C_CSPlayer::KickBack(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::KickBack(
        C_CSPlayer *this,
        float fAngle,
        float fAngleVariance,
        float fMagnitude,
        float fMagnitudeVariance)
{
  __m128 v6; // xmm0
  double v7; // xmm0_8
  double v8; // xmm0_8
  QAngle angle; // [esp+10h] [ebp-Ch] BYREF
  unsigned int fAnglea; // [esp+24h] [ebp+8h]
  unsigned int fAngleb; // [esp+24h] [ebp+8h]
  float fMagnitudea; // [esp+2Ch] [ebp+10h]

  *(float *)&fAnglea = SharedRandomFloat(
                         sharedname: "KickBack",
                         flMinVal: COERCE_FLOAT(LODWORD(fAngleVariance) ^ _mask__NegFloat_),
                         flMaxVal: fAngleVariance,
                         additionalSeed: 0)
                     + fAngle;
  fMagnitudea = SharedRandomFloat(
                  sharedname: "KickBack",
                  flMinVal: COERCE_FLOAT(LODWORD(fMagnitudeVariance) ^ _mask__NegFloat_),
                  flMaxVal: fMagnitudeVariance,
                  additionalSeed: 0)
              + fMagnitude;
  angle = *this->GetPunchAngle(this);
  v6 = (__m128)fAnglea;
  *(float *)&fAngleb = *(float *)&fAnglea * 0.017453292;
  v6.m128_f32[0] = *(float *)&fAngleb;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v6));
  *(float *)&v7 = v7;
  angle.y = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v7 * fMagnitudea) ^ _mask__NegFloat_) + angle.y;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)fAngleb));
  *(float *)&v8 = v8;
  angle.x = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v8 * fMagnitudea) ^ _mask__NegFloat_) + angle.x;
  C_BasePlayer::SetPunchAngle(this, &angle);
}

//------------------------------------------------------------------------------
// Address: 0x101C72A0
// Name: public: bool C_CSPlayer::CanMove(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::CanMove(C_CSPlayer *this)
{
  bool result; // al
  bool v3; // al
  C_BaseCombatWeapon *v4; // eax
  _BYTE *v5; // eax

  result = false;
  if ( this->m_MoveType != 0 )
  {
    if ( this->GetObserverMode(this) != 0 )
      return true;
    v3 = C_CSPlayer::State_Get(this) == STATE_ACTIVE || C_CSPlayer::State_Get(this) == STATE_OBSERVER_MODE;
    if ( !this->m_bIsDefusing.m_Value && v3 && !C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)g_pGameRules) )
    {
      v4 = this->GetActiveWeapon(this);
      v5 = __RTDynamicCast(
             inptr: v4,
             VfDelta: 0,
             SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
             TargetType: &C_C4 `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 == nullptr || v5[3536] == 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C7330
// Name: public: virtual bool C_CSPlayer::CSAnim_CanMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::CSAnim_CanMove(C_CSPlayer *this)
{
  return C_CSPlayer::CanMove(this: (C_CSPlayer *)((char *)this - 6732));
}

//------------------------------------------------------------------------------
// Address: 0x101C7340
// Name: public: void C_CSPlayer::FireBullet(class Vector,class QAngle const __near &,float,int,int,int,float,class C_BaseEntity __near *,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge C_CSPlayer::FireBullet(
        C_CSPlayer *this@<ecx>,
        IHandleEntity_vtbl *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector vecSrc,
        const QAngle *shootAngles,
        float flDistance,
        int iPenetration,
        int iBulletType,
        int iDamage,
        float flRangeModifier,
        C_BaseEntity *pevAttacker,
        bool bDoEffects,
        float xSpread,
        float ySpread)
{
  float v15; // edi
  float v16; // esi
  int m_nValue; // eax
  C_BasePlayer *v18; // eax
  void (__thiscall *BeginLock)(IMDLCache *); // eax
  float v20; // xmm0_4
  float z; // xmm7_4
  float y; // xmm6_4
  float x; // xmm5_4
  float v24; // esi
  char v25; // al
  int v26; // xmm0_4
  int v27; // eax
  C_BaseAnimating *v28; // esi
  C_BaseAnimating *v29; // ecx
  double v30; // xmm0_8
  int v31; // esi
  C_BaseCombatWeapon *ActiveCSWeapon; // eax
  int v33; // edi
  bool v34; // zf
  float v35; // xmm0_4
  surfacedata_t *(__thiscall *GetSurfaceData)(IPhysicsSurfaceProps *, int); // edx
  int v37; // eax
  __int128 v38; // xmm0
  float v39; // xmm1_4
  Vector v42; // [esp+74h] [ebp-25Ch] BYREF
  _BYTE exitTr[88]; // [esp+80h] [ebp-250h] OVERLAPPED BYREF
  CEffectData data; // [esp+D8h] [ebp-1F8h] BYREF
  int v45; // [esp+13Ch] [ebp-194h]
  int v46; // [esp+140h] [ebp-190h]
  _BYTE v47[12]; // [esp+144h] [ebp-18Ch] BYREF
  Vector v48; // [esp+150h] [ebp-180h] BYREF
  Vector vecUp; // [esp+15Ch] [ebp-174h] BYREF
  Vector v50; // [esp+168h] [ebp-168h] BYREF
  Vector vecDirShooting; // [esp+174h] [ebp-15Ch] BYREF
  Vector vecRight; // [esp+180h] [ebp-150h] BYREF
  Vector v53; // [esp+18Ch] [ebp-144h] BYREF
  _BYTE tr[92]; // [esp+198h] [ebp-138h] OVERLAPPED BYREF
  float v55; // [esp+20Ch] [ebp-C4h]
  int material; // [esp+210h] [ebp-C0h]
  IMDLCache *v57; // [esp+214h] [ebp-BCh]
  float v58; // [esp+218h] [ebp-B8h]
  int iEnterMaterial; // [esp+21Ch] [ebp-B4h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+220h] [ebp-B0h]
  Vector vecEnd; // [esp+224h] [ebp-ACh] BYREF
  CGameTrace waterTrace; // [esp+230h] [ebp-A0h] BYREF
  Vector v63; // [esp+288h] [ebp-48h] BYREF
  Vector penetrationEnd; // [esp+294h] [ebp-3Ch] BYREF
  float flPenetrationDistance; // [esp+2A0h] [ebp-30h] BYREF
  float v66; // [esp+2A4h] [ebp-2Ch]
  C_BasePlayer *lastPlayerHit; // [esp+2A8h] [ebp-28h]
  _BYTE vecDir[20]; // [esp+2ACh] [ebp-24h] OVERLAPPED BYREF
  float fCurrentDamage; // [esp+2C0h] [ebp-10h]
  IHandleEntity v70; // [esp+2C4h] [ebp-Ch] OVERLAPPED BYREF
  float flDamageModifier; // [esp+2C8h] [ebp-8h]
  float flPenetrationModifier; // [esp+2CCh] [ebp-4h] BYREF
  float retaddr; // [esp+2D0h] [ebp+0h]

  v70.__vftable = a2;
  flDamageModifier = retaddr;
  v15 = *(float *)&this;
  *(float *)&vecDir[8] = (float)iDamage;
  LODWORD(penetrationEnd.y) = this;
  *(_DWORD *)&vecDir[4] = 0;
  AngleVectors(angles: shootAngles, forward: &v50, right: &vecDirShooting, up: &v48);
  *(_DWORD *)vecDir = 0;
  penetrationEnd.x = 0.0;
  C_CSPlayer::GetBulletTypeParameters(
    this: (C_CSPlayer *)LODWORD(v15),
    iBulletType,
    fPenetrationPower: (float *)vecDir,
    flPenetrationDistance: &penetrationEnd.x);
  flPenetrationDistance = (float)((float)(vecDirShooting.x * xSpread) + v50.x) + (float)(v48.x * ySpread);
  v66 = (float)(v50.y + (float)(vecDirShooting.y * xSpread)) + (float)(v48.y * ySpread);
  *(float *)&lastPlayerHit = (float)(v50.z + (float)(vecDirShooting.z * xSpread)) + (float)(v48.z * ySpread);
  VectorNormalize(vec: (Vector *)&flPenetrationDistance);
  v16 = 0.0;
  if ( sv_showplayerhitboxes.m_pParent != nullptr )
  {
    m_nValue = sv_showplayerhitboxes.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      v18 = UTIL_PlayerByIndex(entindex: m_nValue);
      if ( v18 != nullptr )
        C_BaseAnimating::DrawClientHitboxes(this: v18, duration: 4.0, monocolor: true);
    }
  }
  BeginLock = mdlcache->BeginLock;
  v57 = mdlcache;
  ((void (__cdecl *)(int, int))BeginLock)(a1: a3, a2: a4);
  if ( *(float *)&vecDir[8] > 0.0 )
  {
    v20 = flDistance;
    z = vecSrc.z;
    y = vecSrc.y;
    x = vecSrc.x;
    while ( 1 )
    {
      *(float *)&iEnterMaterial = y + (float)(v66 * v20);
      v58 = x + (float)(flPenetrationDistance * v20);
      *(float *)&cacheCriticalSection.m_pCache = z + (float)(*(float *)&lastPlayerHit * v20);
      waterTrace.startpos.z = *(float *)&iEnterMaterial - y;
      waterTrace.startpos.y = v58 - x;
      waterTrace.endpos.x = *(float *)&cacheCriticalSection.m_pCache - z;
      BYTE1(waterTrace.fractionleftsolid) = (float)((float)((float)(waterTrace.startpos.z * waterTrace.startpos.z)
                                                          + (float)(waterTrace.startpos.y * waterTrace.startpos.y))
                                                  + (float)(waterTrace.endpos.x * waterTrace.endpos.x)) != 0.0;
      memset(&waterTrace.plane.dist, 0, 12);
      *(_DWORD *)&waterTrace.dispFlags = 0;
      LOBYTE(waterTrace.fractionleftsolid) = 1;
      memset(&waterTrace.endpos.z, 0, 12);
      vecEnd.x = x;
      vecEnd.y = y;
      vecEnd.z = z;
      CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        this: (CTraceFilterSkipTwoEntities *)&tr[76],
        passentity: (const IHandleEntity *)LODWORD(v15),
        passentity2: (const IHandleEntity *)LODWORD(v16),
        collisionGroup: 0);
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)&vecEnd,
        a3: 1174421515u,
        a4: (ITraceFilter *)&tr[76],
        a5: (CGameTrace *)&v53);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v53, vecAbsEnd: (const Vector *)tr, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        this: (CTraceFilterSkipTwoEntities *)&tr[76],
        passentity: (const IHandleEntity *)LODWORD(v15),
        passentity2: (const IHandleEntity *)LODWORD(v16),
        collisionGroup: 0);
      vecRight.x = (float)(flPenetrationDistance * 40.0) + v58;
      vecRight.y = (float)(v66 * 40.0) + *(float *)&iEnterMaterial;
      vecRight.z = (float)(*(float *)&lastPlayerHit * 40.0) + *(float *)&cacheCriticalSection.m_pCache;
      UTIL_ClipTraceToPlayers(
        a1: (int)&v70,
        vecAbsStart: &vecSrc,
        vecAbsEnd: &vecRight,
        mask: 0x4600400Bu,
        filter: (ITraceFilter *)&tr[76],
        tr: (CGameTrace *)&v53);
      v24 = *(float *)&tr[64];
      if ( *(_DWORD *)&tr[64] == 0
        || (v25 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 584))(a1: *(_DWORD *)&tr[64]),
            penetrationEnd.z = v24,
            v25 == 0) )
      {
        penetrationEnd.z = 0.0;
      }
      if ( *(float *)&tr[32] == 1.0 )
        break;
      material = physprops->GetSurfaceData(this: physprops, a2: *(__int16 *)&tr[52])->game.material;
      switch ( material )
      {
        case 'C':
          fCurrentDamage = 0.40000001;
          v26 = 1048576000;
          break;
        case 'D':
        case 'M':
          fCurrentDamage = 0.5;
          v26 = 1050253722;
          break;
        case 'G':
          fCurrentDamage = 1.0;
          v26 = 1065185444;
          break;
        case 'P':
          fCurrentDamage = 0.40000001;
          v26 = 1055286886;
          break;
        case 'T':
          fCurrentDamage = 0.64999998;
          v26 = 1050253722;
          break;
        case 'V':
          fCurrentDamage = 0.5;
          v26 = 1055286886;
          break;
        case 'W':
          fCurrentDamage = 1.0;
          v26 = 1058642330;
          break;
        default:
          fCurrentDamage = 1.0;
          v26 = 1056964608;
          break;
      }
      *(_DWORD *)&vecDir[16] = v26;
      vecDir[15] = (tr[36] & 8) != 0;
      if ( (tr[36] & 8) != 0 )
      {
        fCurrentDamage = 1.0;
        *(_DWORD *)&vecDir[16] = 1065185444;
      }
      if ( sv_showimpacts.m_pParent != nullptr )
      {
        v27 = sv_showimpacts.m_pParent->m_Value.m_nValue;
        if ( v27 == 1 || v27 == 2 )
        {
          *(_DWORD *)&vecDir[16] = debugoverlay;
          memset(v47, 0, sizeof(v47));
          vecUp.x = 2.0;
          vecUp.y = 2.0;
          vecUp.z = 2.0;
          data.m_iEffectName = -1073741824;
          v45 = -1073741824;
          v46 = -1073741824;
          ((void (__thiscall *)(IVDebugOverlay *, _BYTE *, int *, Vector *, _BYTE *, int, _DWORD, _DWORD, int, int))debugoverlay->AddBoxOverlay)(
            a1: debugoverlay,
            a2: tr,
            a3: &data.m_iEffectName,
            a4: &vecUp,
            a5: v47,
            a6: 255,
            a7: 0,
            a8: 0,
            a9: 127,
            a10: 1082130432);
          if ( *(_DWORD *)&tr[64] != 0
            && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 584))(a1: *(_DWORD *)&tr[64]) != 0 )
          {
            v28 = *(C_BaseAnimating **)&tr[64];
            if ( *(_DWORD *)&tr[64] != 0
              && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 584))(a1: *(_DWORD *)&tr[64]) != 0 )
            {
              v29 = v28;
            }
            else
            {
              v29 = nullptr;
            }
            C_BaseAnimating::DrawClientHitboxes(this: v29, duration: 4.0, monocolor: true);
          }
        }
      }
      *(float *)&vecDir[4] = (float)(*(float *)&tr[32] * flDistance) + *(float *)&vecDir[4];
      v30 = flRangeModifier;
      __libm_sse2_pow();
      *(float *)&v30 = v30;
      *(float *)&vecDir[8] = *(float *)&v30 * *(float *)&vecDir[8];
      if ( *(float *)&vecDir[4] > penetrationEnd.x && iPenetration > 0 )
        iPenetration = 0;
      v31 = 4098;
      ActiveCSWeapon = C_CSPlayer::GetActiveCSWeapon(this: (C_BasePlayer *)LODWORD(v15));
      if ( ActiveCSWeapon != nullptr
        && ActiveCSWeapon->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetRefEHandle(this: ActiveCSWeapon) == (const CBaseHandle *)22 )
      {
        v31 = 4352;
      }
      if ( bDoEffects )
      {
        if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)tr, a3: 16432, a4: nullptr) & 0x30) != 0 )
        {
          UTIL_TraceLine(
            a1: &v70,
            a2: v31,
            vecAbsStart: &vecSrc,
            vecAbsEnd: (const Vector *)tr,
            mask: 0x46004033u,
            ignore: (const IHandleEntity *)LODWORD(v15),
            collisionGroup: 0,
            ptr: (CGameTrace *)&vecEnd);
          if ( waterTrace.plane.pad[0] != 1 )
          {
            memset((void *)&data, 0, 12);
            memset((void *)&data.m_vNormal, 0, 16);
            memset(&data.m_fFlags, 0, 14);
            *(Vector *)&exitTr[76] = waterTrace.startpos;
            data.m_vStart = waterTrace.endpos;
            memset(&data.m_flRadius, 0, 17);
            data.m_vAngles.y = NAN;
            data.m_vAngles.z = 1.0;
            data.m_vAngles.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1090519040,
                                 a3: 1094713344);
            if ( (LOBYTE(waterTrace.plane.dist) & 0x10) != 0 )
              LODWORD(data.m_vAngles.x) |= 1u;
            DispatchEffect(pName: "gunshotsplash", data: (const CEffectData *)&exitTr[76]);
          }
        }
        else if ( (*(_WORD *)&tr[54] & 0x384) == 0 )
        {
          if ( friendlyfire.m_pParent != nullptr && friendlyfire.m_pParent->m_Value.m_nValue != 0
            || *(_DWORD *)&tr[64] == 0
            || (v33 = (*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v15) + 332))(a1: COERCE_FLOAT(LODWORD(v15))),
                v34 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr[64] + 332))(a1: *(_DWORD *)&tr[64]) == v33,
                v15 = penetrationEnd.y,
                !v34) )
          {
            UTIL_ImpactTrace(pTrace: (CGameTrace *)&v53, iDamageType: v31, pCustomImpactName: nullptr);
          }
        }
      }
      *(_QWORD *)&vecDir[8] = *(_QWORD *)tr;
      *(_DWORD *)&vecDir[16] = *(_DWORD *)&tr[8];
      C_CSPlayer::CreateWeaponTracer(
        this: (C_CSPlayer *)LODWORD(v15),
        a2: (int)&flPenetrationModifier,
        a3: v31,
        vecStart: vecSrc,
        vecEnd: *(Vector *)&vecDir[8]);
      if ( iPenetration != 0 )
      {
        if ( iPenetration < 0 )
          break;
      }
      else if ( vecDir[15] == 0 )
      {
        break;
      }
      v35 = 0.0;
      while ( 1 )
      {
        v55 = v35 + 24.0;
        *(_DWORD *)&vecDir[16] = 0;
        v63.x = *(float *)tr + (float)((float)(v35 + 24.0) * flPenetrationDistance);
        v63.y = *(float *)&tr[4] + (float)(v66 * (float)(v35 + 24.0));
        v63.z = *(float *)&tr[8] + (float)(*(float *)&lastPlayerHit * (float)(v35 + 24.0));
        if ( (enginetrace->GetPointContents(this: enginetrace, a2: &v63, a3: -1, a4: nullptr) & 0x200400B) == 0 )
          break;
        v35 = v55;
        if ( v55 > 128.0 )
          goto LABEL_76;
      }
      waterTrace.startpos.z = *(float *)&tr[4] - v63.y;
      waterTrace.startpos.y = *(float *)tr - v63.x;
      waterTrace.endpos.x = *(float *)&tr[8] - v63.z;
      BYTE1(waterTrace.fractionleftsolid) = (float)((float)((float)(waterTrace.startpos.z * waterTrace.startpos.z)
                                                          + (float)(waterTrace.startpos.y * waterTrace.startpos.y))
                                                  + (float)(waterTrace.endpos.x * waterTrace.endpos.x)) != 0.0;
      *(_DWORD *)&vecDir[16] = &v42;
      *(_DWORD *)&vecDir[12] = 0;
      memset(&waterTrace.plane.dist, 0, 12);
      *(_DWORD *)&waterTrace.dispFlags = 0;
      LOBYTE(waterTrace.fractionleftsolid) = 1;
      memset(&waterTrace.endpos.z, 0, 12);
      vecEnd = v63;
      ((void (__thiscall *)(IEngineTrace *, Vector *, int, _DWORD, Vector *, _DWORD))enginetrace->TraceRay)(
        a1: enginetrace,
        a2: &vecEnd,
        a3: 1174421515,
        a4: 0,
        a5: &v42,
        a6: LODWORD(fCurrentDamage));
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v42, vecAbsEnd: (const Vector *)exitTr, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      if ( *(_DWORD *)&exitTr[64] != *(_DWORD *)&tr[64] && *(_DWORD *)&exitTr[64] != 0 )
        UTIL_TraceLine(
          a1: &v70,
          a2: v31,
          vecAbsStart: &v63,
          vecAbsEnd: (const Vector *)tr,
          mask: 0x4600400Bu,
          ignore: *(const IHandleEntity **)&exitTr[64],
          collisionGroup: 0,
          ptr: (CGameTrace *)&v42);
      GetSurfaceData = physprops->GetSurfaceData;
      LODWORD(fCurrentDamage) = *(__int16 *)&exitTr[52];
      v37 = *(unsigned __int16 *)(((int (__thiscall *)(IPhysicsSurfaceProps *))GetSurfaceData)(a1: physprops) + 76);
      if ( material == v37 && (v37 == 87 || v37 == 77) )
        fCurrentDamage = fCurrentDamage * 2.0;
      v38 = 0;
      *(float *)&v38 = fsqrt(
                         (float)((float)((float)(*(float *)&exitTr[4] - *(float *)&tr[4])
                                       * (float)(*(float *)&exitTr[4] - *(float *)&tr[4]))
                               + (float)((float)(*(float *)&exitTr[8] - *(float *)&tr[8])
                                       * (float)(*(float *)&exitTr[8] - *(float *)&tr[8])))
                       + (float)((float)(*(float *)exitTr - *(float *)tr) * (float)(*(float *)exitTr - *(float *)tr)));
      *(_OWORD *)&tr[76] = v38;
      if ( *(float *)&v38 > (float)(fCurrentDamage * *(float *)vecDir) )
        break;
      if ( bDoEffects )
        UTIL_ImpactTrace(pTrace: (CGameTrace *)&v42, iDamageType: v31, pCustomImpactName: nullptr);
      --iPenetration;
      x = *(float *)exitTr;
      y = *(float *)&exitTr[4];
      z = *(float *)&exitTr[8];
      *(float *)vecDir = *(float *)vecDir - (float)(*(float *)&tr[76] / fCurrentDamage);
      v39 = (float)(flDistance - (float)(*(float *)&tr[76] + *(float *)&vecDir[4])) * 0.5;
      *(float *)&vecDir[4] = *(float *)&tr[76] + *(float *)&vecDir[4];
      v20 = v39;
      vecSrc = *(Vector *)exitTr;
      flDistance = v39;
      *(float *)&vecDir[8] = *(float *)&vecDir[16] * *(float *)&vecDir[8];
      if ( *(float *)&vecDir[8] <= 0.0 )
        break;
      v16 = penetrationEnd.z;
    }
  }
LABEL_76:
  v57->EndLock(this: v57);
}

//------------------------------------------------------------------------------
// Address: 0x101C7F50
// Name: public: bool C_CSPlayer::CanGrabLadder(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSPlayer::CanGrabLadder(C_CSPlayer *this, const Vector *pos, const Vector *normal)
{
  bool result; // al
  float v5; // xmm1_4

  result = true;
  if ( this->m_ladderSurpressionTimer.m_timestamp.m_Value
     - CountdownTimer::Now(this: (CEffectsClient *)&this->m_ladderSurpressionTimer) > 0.0 )
  {
    v5 = pos->y - this->m_lastLadderPos.y;
    if ( (float)((float)((float)(pos->x - this->m_lastLadderPos.x) * (float)(pos->x - this->m_lastLadderPos.x))
               + (float)(v5 * v5)) < 4096.0
      || this->m_lastLadderNormal.x == normal->x
      && this->m_lastLadderNormal.y == normal->y
      && this->m_lastLadderNormal.z == normal->z )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C8000
// Name: public: virtual struct surfacedata_t __near * C_CSPlayer::GetFootstepSurface(class Vector const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
surfacedata_t *__thiscall C_CSPlayer::GetFootstepSurface(
        C_CSPlayer *this,
        const Vector *origin,
        const char *surfaceName)
{
  int v3; // edi
  C_FootstepControl *v4; // esi
  IPhysicsSurfaceProps_vtbl *v5; // esi
  int v6; // eax
  IPhysicsSurfaceProps_vtbl *v8; // edi
  int v9; // eax

  v3 = 0;
  if ( s_footstepControllers.m_Size <= 0 )
  {
LABEL_5:
    v5 = physprops->__vftable;
    v6 = physprops->GetSurfaceIndex(this: physprops, a2: surfaceName);
    return v5->GetSurfaceData(this: physprops, a2: v6);
  }
  else
  {
    while ( 1 )
    {
      v4 = s_footstepControllers.m_Memory.m_pMemory[v3];
      if ( _V_stricmp(s1: v4->m_source, s2: surfaceName) == 0
        && CCollisionProperty::IsPointInBounds(this: &v4->m_Collision, vecWorldPt: origin) )
      {
        break;
      }
      if ( ++v3 >= s_footstepControllers.m_Size )
        goto LABEL_5;
    }
    v8 = physprops->__vftable;
    v9 = physprops->GetSurfaceIndex(this: physprops, a2: v4->m_destination);
    return v8->GetSurfaceData(this: physprops, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C80A0
// Name: public: void C_CSPlayer::SurpressLadderChecks(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::SurpressLadderChecks(C_CSPlayer *this, const Vector *pos, const Vector *normal)
{
  double v4; // st7
  float v5; // [esp+Ch] [ebp-4h]

  v4 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_ladderSurpressionTimer) + 1.0;
  if ( this->m_ladderSurpressionTimer.m_timestamp.m_Value != v4 )
  {
    this->m_ladderSurpressionTimer.NetworkStateChanged(
      this: &this->m_ladderSurpressionTimer,
      a2: &this->m_ladderSurpressionTimer.m_timestamp);
    v5 = v4;
    this->m_ladderSurpressionTimer.m_timestamp.m_Value = v5;
  }
  if ( this->m_ladderSurpressionTimer.m_duration.m_Value != 1.0 )
  {
    this->m_ladderSurpressionTimer.NetworkStateChanged(
      this: &this->m_ladderSurpressionTimer,
      a2: &this->m_ladderSurpressionTimer.m_duration);
    this->m_ladderSurpressionTimer.m_duration.m_Value = 1.0;
  }
  this->m_lastLadderPos = *pos;
  this->m_lastLadderNormal = *normal;
}

//------------------------------------------------------------------------------
// Address: 0x101C8160
// Name: public: void C_CSPlayer::KickBack(float,float,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSPlayer::KickBack(
        C_CSPlayer *this,
        float up_base,
        float lateral_base,
        float up_modifier,
        float lateral_modifier,
        float up_max,
        float lateral_max,
        IUniformRandomStream *direction_change)
{
  float v9; // xmm0_4
  float m_Value; // xmm0_4
  float v11; // xmm1_4
  bool v12; // cc
  int v13; // eax
  QAngle angle; // [esp+4h] [ebp-Ch] BYREF
  float flKickUp; // [esp+20h] [ebp+10h]

  if ( this->m_iShotsFired.m_Value == 1 )
  {
    flKickUp = up_base;
    v9 = lateral_base;
  }
  else
  {
    m_Value = (float)this->m_iShotsFired.m_Value;
    v11 = (float)(m_Value * up_modifier) + up_base;
    v9 = (float)(m_Value * lateral_modifier) + lateral_base;
    flKickUp = v11;
  }
  angle = *this->GetPunchAngle(this);
  v12 = (float)(up_max * -1.0) <= (float)(angle.x - flKickUp);
  angle.x = angle.x - flKickUp;
  if ( !v12 )
    angle.x = up_max * -1.0;
  if ( this->m_iDirection.m_Value == 1 )
  {
    angle.y = angle.y + v9;
    if ( angle.y > lateral_max )
      angle.y = lateral_max;
  }
  else
  {
    v12 = (float)(lateral_max * -1.0) <= (float)(angle.y - v9);
    angle.y = angle.y - v9;
    if ( !v12 )
      angle.y = lateral_max * -1.0;
  }
  if ( SharedRandomInt(sharedname: "KickBack", iMinVal: 0, iMaxVal: direction_change, additionalSeed: 0) == 0 )
  {
    v13 = 1 - this->m_iDirection.m_Value;
    if ( this->m_iDirection.m_Value != v13 )
      this->m_iDirection.m_Value = v13;
  }
  C_BasePlayer::SetPunchAngle(this, &angle);
}

//------------------------------------------------------------------------------
// Address: 0x101C8290
// Name: public: C_FootstepControl::C_FootstepControl(void)
// Source: json
//------------------------------------------------------------------------------
C_FootstepControl *__thiscall C_FootstepControl::C_FootstepControl(C_FootstepControl *this)
{
  int m_Size; // eax
  int v3; // edi
  C_FootstepControl **m_pMemory; // ecx
  int v5; // eax
  C_FootstepControl **v6; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->m_hPredictionOwner.m_Index = -1;
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FootstepControl_vtbl *)&C_FootstepControl::`vftable'{for `IClientUnknown'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FootstepControl::`vftable'{for `IClientRenderable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FootstepControl::`vftable'{for `IClientNetworkable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FootstepControl::`vftable'{for `IClientThinkable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FootstepControl::`vftable';
  m_Size = s_footstepControllers.m_Size;
  v3 = s_footstepControllers.m_Size;
  if ( s_footstepControllers.m_Size + 1 > s_footstepControllers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&s_footstepControllers,
      num: s_footstepControllers.m_Size - s_footstepControllers.m_Memory.m_nAllocationCount + 1);
    m_Size = s_footstepControllers.m_Size;
  }
  m_pMemory = s_footstepControllers.m_Memory.m_pMemory;
  s_footstepControllers.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  s_footstepControllers.m_pElements = s_footstepControllers.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&s_footstepControllers.m_Memory.m_pMemory[v3 + 1],
      src: (unsigned __int8 *)&s_footstepControllers.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = s_footstepControllers.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104234C0
// Name: DT_FootstepControl::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FootstepControl::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FootstepControl::g_RecvTable);
  return atexit(func: DT_FootstepControl::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104234E0
// Name: DT_FootstepControl::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FootstepControl::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FootstepControl::ignored>();
  DT_FootstepControl::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104357E0
// Name: DT_FootstepControl::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FootstepControl::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FootstepControl::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101C8390
// Name: _C_FootstepControl_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FootstepControl_CreateObject(int entnum, int serialNum)
{
  C_FootstepControl *v2; // eax
  C_FootstepControl *v3; // eax
  C_FootstepControl *v4; // esi

  v2 = (C_FootstepControl *)C_BaseEntity::operator new(stAllocateBlock: 0x9D8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FootstepControl::C_FootstepControl(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104234F0
// Name: _dynamic_initializer_for__s_footstepControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_footstepControllers__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_footstepControllers__);
}

//------------------------------------------------------------------------------
// Address: 0x104357F0
// Name: _dynamic_atexit_destructor_for__s_footstepControllers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_footstepControllers__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_footstepControllers);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10294740
// Name: public: void CCSPlayer::GetBulletTypeParameters(int,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GetBulletTypeParameters(
        CCSPlayer *this,
        int iBulletType,
        float *fPenetrationPower,
        float *flPenetrationDistance)
{
  int v4; // xmm0_4

  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_50AE") )
  {
    *fPenetrationPower = 30.0;
    *flPenetrationDistance = 1000.0;
    return;
  }
  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_762MM") )
  {
    *fPenetrationPower = 39.0;
    *flPenetrationDistance = 5000.0;
    return;
  }
  if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_556MM")
    || IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_556MM_BOX") )
  {
    *fPenetrationPower = 35.0;
    *flPenetrationDistance = 4000.0;
  }
  else
  {
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_338MAG") )
    {
      *fPenetrationPower = 45.0;
      *flPenetrationDistance = 8000.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_9MM") )
    {
      v4 = 1101529088;
LABEL_17:
      *(_DWORD *)fPenetrationPower = v4;
      *flPenetrationDistance = 800.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_BUCKSHOT") )
    {
      *fPenetrationPower = 0.0;
      *flPenetrationDistance = 0.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_45ACP") )
    {
      *fPenetrationPower = 15.0;
      *flPenetrationDistance = 500.0;
      return;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_357SIG") )
    {
      v4 = 1103626240;
      goto LABEL_17;
    }
    if ( IsAmmoType(iAmmoType: iBulletType, pAmmoName: "BULLET_PLAYER_57MM") )
    {
      *fPenetrationPower = 30.0;
      *flPenetrationDistance = 2000.0;
    }
    else
    {
      IsAmmoType(iAmmoType: iBulletType, pAmmoName: "AMMO_TYPE_TASERCHARGE");
      *fPenetrationPower = 0.0;
      *flPenetrationDistance = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10294960
// Name: public: virtual void CCSPlayer::UpdateStepSound(struct surfacedata_t __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::UpdateStepSound(
        CCSPlayer *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        surfacedata_t *psurface,
        const Vector *vecOrigin,
        const Vector *vecVelocity)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( (float)((float)(vecVelocity->x * vecVelocity->x) + (float)(vecVelocity->y * vecVelocity->y)) >= 22500.0 )
    CBasePlayer::UpdateStepSound(this, a2: COERCE_FLOAT(&savedregs), a3: a2, a4: a3, psurface, vecOrigin, vecVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x102949A0
// Name: public: void CCSPlayer::KickBack(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::KickBack(
        CCSPlayer *this,
        float fAngle,
        float fAngleVariance,
        float fMagnitude,
        float fMagnitudeVariance)
{
  __m128 v6; // xmm0
  double v7; // xmm0_8
  double v8; // xmm0_8
  QAngle angle; // [esp+10h] [ebp-Ch] BYREF
  unsigned int fAnglea; // [esp+24h] [ebp+8h]
  unsigned int fAngleb; // [esp+24h] [ebp+8h]
  float fMagnitudea; // [esp+2Ch] [ebp+10h]

  *(float *)&fAnglea = SharedRandomFloat(
                         sharedname: "KickBack",
                         flMinVal: COERCE_FLOAT(LODWORD(fAngleVariance) ^ _mask__NegFloat_),
                         flMaxVal: fAngleVariance,
                         additionalSeed: 0)
                     + fAngle;
  fMagnitudea = SharedRandomFloat(
                  sharedname: "KickBack",
                  flMinVal: COERCE_FLOAT(LODWORD(fMagnitudeVariance) ^ _mask__NegFloat_),
                  flMaxVal: fMagnitudeVariance,
                  additionalSeed: 0)
              + fMagnitude;
  angle = CBasePlayer::GetPunchAngle(this)->m_Value;
  v6 = (__m128)fAnglea;
  *(float *)&fAngleb = *(float *)&fAnglea * 0.017453292;
  v6.m128_f32[0] = *(float *)&fAngleb;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v6));
  *(float *)&v7 = v7;
  angle.y = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v7 * fMagnitudea) ^ _mask__NegFloat_) + angle.y;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)fAngleb));
  *(float *)&v8 = v8;
  angle.x = COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&v8 * fMagnitudea) ^ _mask__NegFloat_) + angle.x;
  CBasePlayer::SetPunchAngle(this, punchAngle: &angle);
}

//------------------------------------------------------------------------------
// Address: 0x10294A90
// Name: public: virtual unsigned int CCSPlayer::PhysicsSolidMaskForEntity(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSPlayer::PhysicsSolidMaskForEntity(CCSPlayer *this)
{
  unsigned int result; // eax

  if ( !CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
    return 33636363;
  switch ( CBaseEntity::GetTeamNumber(this) )
  {
    case 2:
      result = 33638411;
      break;
    case 3:
      result = 33640459;
      break;
    default:
      return 33636363;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10294AE0
// Name: public: void CCSPlayer::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnJump(CCSPlayer *this, float fImpulse)
{
  CWeaponCSBase *ActiveCSWeapon; // eax

  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
  if ( ActiveCSWeapon != nullptr )
    ((void (__thiscall *)(CWeaponCSBase *, _DWORD))ActiveCSWeapon->OnJump)(a1: ActiveCSWeapon, a2: LODWORD(fImpulse));
}

//------------------------------------------------------------------------------
// Address: 0x10294B10
// Name: public: void CCSPlayer::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnLand(CCSPlayer *this, float fVelocity)
{
  CWeaponCSBase *ActiveCSWeapon; // eax

  if ( fVelocity > 270.0 )
    CBaseEntity::EmitSound(this, soundname: "Default.Land", soundtime: 0.0, duration: nullptr);
  ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
  if ( ActiveCSWeapon != nullptr )
    ((void (__thiscall *)(CWeaponCSBase *, _DWORD))ActiveCSWeapon->OnLand)(a1: ActiveCSWeapon, a2: LODWORD(fVelocity));
}

//------------------------------------------------------------------------------
// Address: 0x10294B60
// Name: public: virtual class CWeaponCSBase __near * CCSPlayer::CSAnim_GetActiveWeapon(void)
// Source: json
//------------------------------------------------------------------------------
CWeaponCSBase *__thiscall CCSPlayer::CSAnim_GetActiveWeapon(CCSPlayer *this)
{
  return CCSPlayer::GetActiveCSWeapon(this: (CCSPlayer *)((char *)this - 4768));
}

//------------------------------------------------------------------------------
// Address: 0x10294B70
// Name: public: virtual struct datamap_t __near * CFootstepControl::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFootstepControl::GetDataDescMap(CFootstepControl *this)
{
  return &CFootstepControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10294B80
// Name: public: virtual class ServerClass __near * CFootstepControl::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFootstepControl::GetServerClass(CFootstepControl *this)
{
  return &g_CFootstepControl_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10294B90
// Name: public: virtual void CFootstepControl::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFootstepControl::Spawn(CTriggerTeleport *this)
{
  CBaseTrigger::InitTrigger(this);
}

//------------------------------------------------------------------------------
// Address: 0x10294BA0
// Name: public: bool CCSPlayer::CanGrabLadder(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CanGrabLadder(CCSPlayer *this, const Vector *pos, const Vector *normal)
{
  bool result; // al
  float v5; // xmm1_4

  result = true;
  if ( this->m_ladderSurpressionTimer.m_timestamp.m_Value
     - IntervalTimer::Now(this: (CEffectsServer *)&this->m_ladderSurpressionTimer) > 0.0 )
  {
    v5 = pos->y - this->m_lastLadderPos.y;
    if ( (float)((float)((float)(pos->x - this->m_lastLadderPos.x) * (float)(pos->x - this->m_lastLadderPos.x))
               + (float)(v5 * v5)) < 4096.0
      || this->m_lastLadderNormal.x == normal->x
      && this->m_lastLadderNormal.y == normal->y
      && this->m_lastLadderNormal.z == normal->z )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10294C40
// Name: public: virtual float CCSPlayer::GetPlayerMaxSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSPlayer::GetPlayerMaxSpeed(CCSPlayer *this)
{
  CSPlayerState m_Value; // eax
  double PlayerMaxSpeed; // st7
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v6; // edi
  float speed; // [esp+4h] [ebp-4h]

  if ( this->m_MoveType.m_Value == 0 )
    return 1.0;
  if ( (this->m_afPhysicsFlags.m_Value & 8) != 0 )
    return 900.0;
  m_Value = this->m_iPlayerState.m_Value;
  if ( m_Value != STATE_ACTIVE && m_Value != STATE_OBSERVER_MODE )
    return 1.0;
  if ( this->m_bIsDefusing.m_Value || CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules) )
    return 1.0;
  PlayerMaxSpeed = CBasePlayer::GetPlayerMaxSpeed(this);
  speed = PlayerMaxSpeed;
  if ( PlayerMaxSpeed > 260.0 )
    speed = 260.0;
  if ( CCSPlayer::IsVIP(this) )
    return 227.0;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  v6 = __RTDynamicCast(
         inptr: ActiveWeapon,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr )
  {
    if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this)
      && IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this) )
    {
      return 160.0;
    }
    return (float)((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v6 + 1516))(a1: v6);
  }
  return speed;
}

//------------------------------------------------------------------------------
// Address: 0x10294D60
// Name: public: bool CCSPlayer::CanMove(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CanMove(CCSPlayer *this)
{
  bool result; // al
  CSPlayerState m_Value; // eax
  bool v4; // al
  CBaseCombatWeapon *ActiveWeapon; // eax
  _BYTE *v6; // eax

  result = false;
  if ( this->m_MoveType.m_Value != 0 )
  {
    if ( (this->m_afPhysicsFlags.m_Value & 8) != 0 )
      return true;
    m_Value = this->m_iPlayerState.m_Value;
    v4 = m_Value == STATE_ACTIVE || m_Value == STATE_OBSERVER_MODE;
    if ( !this->m_bIsDefusing.m_Value && v4 && !CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules) )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      v6 = __RTDynamicCast(
             inptr: ActiveWeapon,
             VfDelta: 0,
             SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
             TargetType: &CC4 `RTTI Type Descriptor',
             isReference: 0);
      if ( v6 == nullptr || v6[1472] == 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10294DE0
// Name: public: void CCSPlayer::SurpressLadderChecks(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SurpressLadderChecks(CCSPlayer *this, const Vector *pos, const Vector *normal)
{
  double v4; // st7
  float v5; // [esp+Ch] [ebp-4h]

  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_ladderSurpressionTimer) + 1.0;
  if ( this->m_ladderSurpressionTimer.m_timestamp.m_Value != v4 )
  {
    this->m_ladderSurpressionTimer.NetworkStateChanged(
      this: &this->m_ladderSurpressionTimer,
      a2: &this->m_ladderSurpressionTimer.m_timestamp);
    v5 = v4;
    this->m_ladderSurpressionTimer.m_timestamp.m_Value = v5;
  }
  if ( this->m_ladderSurpressionTimer.m_duration.m_Value != 1.0 )
  {
    this->m_ladderSurpressionTimer.NetworkStateChanged(
      this: &this->m_ladderSurpressionTimer,
      a2: &this->m_ladderSurpressionTimer.m_duration);
    this->m_ladderSurpressionTimer.m_duration.m_Value = 1.0;
  }
  this->m_lastLadderPos = *pos;
  this->m_lastLadderNormal = *normal;
}

//------------------------------------------------------------------------------
// Address: 0x10294EA0
// Name: public: virtual bool CCSPlayer::CSAnim_CanMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CSAnim_CanMove(CCSPlayer *this)
{
  return CCSPlayer::CanMove(this: (CCSPlayer *)((char *)this - 4768));
}

//------------------------------------------------------------------------------
// Address: 0x10294F60
// Name: public: void CCSPlayer::CheckForWeaponFiredAchievement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CheckForWeaponFiredAchievement(CCSPlayer *this)
{
  int m_Size; // eax
  int v3; // ecx
  CSWeaponID *m_pMemory; // edx
  CSWeaponID *i; // esi
  int v6; // ecx
  CSWeaponID *j; // esi
  int v8; // ecx
  CBaseEntity *src; // [esp+4h] [ebp-4h] BYREF

  if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    m_Size = this->m_WeaponTypesUsed.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_WeaponTypesUsed.m_Memory.m_pMemory;
      for ( i = m_pMemory; *i != WEAPON_TASER; ++i )
      {
        if ( ++v3 >= m_Size )
          return;
      }
      if ( v3 != -1 )
      {
        v6 = 0;
        for ( j = this->m_WeaponTypesUsed.m_Memory.m_pMemory; *j != WEAPON_AK47; ++j )
        {
          if ( ++v6 >= m_Size )
            return;
        }
        if ( v6 != -1 )
        {
          v8 = 0;
          while ( *m_pMemory != WEAPON_DEAGLE )
          {
            ++v8;
            ++m_pMemory;
            if ( v8 >= m_Size )
              return;
          }
          if ( v8 != -1 )
          {
            src = (CBaseEntity *)7;
            if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
                   this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
                   &src) != -1 )
            {
              src = (CBaseEntity *)6;
              if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
                     this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
                     &src) != -1 )
              {
                src = (CBaseEntity *)29;
                if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
                       this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
                       &src) != -1 )
                {
                  src = (CBaseEntity *)14;
                  if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
                         this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
                         &src) != -1 )
                  {
                    src = (CBaseEntity *)12;
                    if ( CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
                           this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
                           &src) != -1 )
                      CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 6040, iCount: 1);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102950A0
// Name: public: void CCSPlayer::FireBullet(class Vector,class QAngle const __near &,float,int,int,int,float,class CBaseEntity __near *,bool,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CCSPlayer::FireBullet(
        CCSPlayer *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        Vector vecSrc,
        const QAngle *shootAngles,
        float flDistance,
        int iPenetration,
        int iBulletType,
        int iDamage,
        float flRangeModifier,
        CCSPlayer *pevAttacker,
        bool bDoEffects,
        float xSpread,
        float ySpread)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  float v17; // esi
  int m_nValue; // eax
  CBasePlayer *v19; // eax
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  float v21; // xmm0_4
  float z; // xmm7_4
  float y; // xmm6_4
  float x; // xmm5_4
  float v25; // esi
  char v26; // al
  IGameEvent *v27; // esi
  int v28; // eax
  float v29; // xmm0_4
  int v30; // eax
  CBaseAnimating *v31; // ecx
  double v32; // xmm0_8
  CWeaponCSBase *ActiveCSWeapon; // eax
  int TeamNumber; // esi
  CBaseEntity *v35; // esi
  int v36; // esi
  int v37; // esi
  float v38; // xmm0_4
  float v39; // xmm0_4
  int (__thiscall *GetPointContents)(IEngineTrace *, const Vector *, int, IHandleEntity **); // edx
  surfacedata_t *(__thiscall *GetSurfaceData)(IPhysicsSurfaceProps *, int); // edx
  int v42; // eax
  __int128 v43; // xmm1
  float v44; // xmm1_4
  _BYTE v47[12]; // [esp+80h] [ebp-2B4h] BYREF
  CTakeDamageInfo info; // [esp+8Ch] [ebp-2A8h] BYREF
  _BYTE exitTr[88]; // [esp+ECh] [ebp-248h] OVERLAPPED BYREF
  CEffectData data; // [esp+144h] [ebp-1F0h] BYREF
  float v51; // [esp+1A8h] [ebp-18Ch]
  Vector vecUp; // [esp+1ACh] [ebp-188h] BYREF
  Vector vecRight; // [esp+1B8h] [ebp-17Ch] BYREF
  Vector v54; // [esp+1C4h] [ebp-170h] BYREF
  Vector v55; // [esp+1D0h] [ebp-164h] BYREF
  Vector vecDirShooting; // [esp+1DCh] [ebp-158h] BYREF
  __int128 v57; // [esp+1E8h] [ebp-14Ch] OVERLAPPED BYREF
  Vector v58; // [esp+210h] [ebp-124h] BYREF
  CGameTrace tr; // [esp+21Ch] [ebp-118h] BYREF
  int material; // [esp+270h] [ebp-C4h]
  float v61; // [esp+274h] [ebp-C0h]
  int iMaxPenetration; // [esp+278h] [ebp-BCh]
  int iEnterMaterial; // [esp+27Ch] [ebp-B8h]
  float v64; // [esp+280h] [ebp-B4h]
  Vector vecEnd; // [esp+284h] [ebp-B0h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+290h] [ebp-A4h]
  CGameTrace waterTrace; // [esp+294h] [ebp-A0h] BYREF
  Vector v68; // [esp+2E8h] [ebp-4Ch] BYREF
  Vector penetrationEnd; // [esp+2F4h] [ebp-40h] BYREF
  CBasePlayer *lastPlayerHit; // [esp+300h] [ebp-34h] BYREF
  int flPenetrationDistance; // [esp+304h] [ebp-30h]
  int iPenetrationKills; // [esp+308h] [ebp-2Ch] BYREF
  float flPenetrationPower; // [esp+30Ch] [ebp-28h]
  int iDamageType; // [esp+310h] [ebp-24h]
  Vector vecDir; // [esp+314h] [ebp-20h]
  float flCurrentDistance; // [esp+320h] [ebp-14h]
  long double fCurrentDamage; // [esp+324h] [ebp-10h] OVERLAPPED BYREF
  long double flDamageModifier; // [esp+32Ch] [ebp-8h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+334h] [ebp+0h]

  HIDWORD(fCurrentDamage) = a2;
  LODWORD(flDamageModifier) = retaddr;
  tr.hitbox = iPenetration;
  vecDir.y = (float)iDamage;
  vecDir.x = 0.0;
  AngleVectors(angles: shootAngles, forward: &v55, right: &vecUp, up: (Vector *)&data.m_nColor);
  *(float *)&lastPlayerHit = 0.0;
  penetrationEnd.y = 0.0;
  CCSPlayer::GetBulletTypeParameters(
    this,
    iBulletType,
    fPenetrationPower: (float *)&lastPlayerHit,
    flPenetrationDistance: &penetrationEnd.y);
  if ( pevAttacker == nullptr )
    pevAttacker = this;
  *(float *)&iPenetrationKills = (float)((float)(vecUp.x * xSpread) + v55.x)
                               + (float)(*(float *)&data.m_nColor * ySpread);
  flPenetrationPower = (float)(v55.y + (float)(vecUp.y * xSpread)) + (float)(*(float *)&data.m_iEffectName * ySpread);
  *(float *)&iDamageType = (float)(v55.z + (float)(vecUp.z * xSpread)) + (float)(v51 * ySpread);
  VectorNormalize(vec: (Vector *)&iPenetrationKills);
  penetrationEnd.z = 0.0;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  CCSGameStats::Event_ShotFired(this: &CCS_GameStats, pPlayer: this, pWeapon: ActiveWeapon);
  ++this->m_bulletsFiredSinceLastSpawn;
  CCSPlayer::CheckForWeaponFiredAchievement(this);
  v17 = 0.0;
  if ( sv_showplayerhitboxes.m_pParent != nullptr )
  {
    m_nValue = sv_showplayerhitboxes.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
    {
      v19 = UTIL_PlayerByIndex(playerIndex: m_nValue);
      if ( v19 != nullptr )
        CBaseAnimating::DrawServerHitboxes(this: v19, duration: 4.0, monocolor: true);
    }
  }
  BeginLock = mdlcache->BeginLock;
  LODWORD(vecEnd.x) = mdlcache;
  ((void (__cdecl *)(int, int))BeginLock)(a1: a3, a2: a4);
  if ( vecDir.y > 0.0 )
  {
    v21 = flDistance;
    z = vecSrc.z;
    y = vecSrc.y;
    x = vecSrc.x;
    while ( 1 )
    {
      *(float *)&iEnterMaterial = y + (float)(flPenetrationPower * v21);
      *(float *)&iMaxPenetration = x + (float)(*(float *)&iPenetrationKills * v21);
      v64 = z + (float)(*(float *)&iDamageType * v21);
      waterTrace.startpos.z = *(float *)&iEnterMaterial - y;
      waterTrace.startpos.y = *(float *)&iMaxPenetration - x;
      waterTrace.endpos.x = v64 - z;
      BYTE1(waterTrace.fractionleftsolid) = (float)((float)((float)(waterTrace.startpos.z * waterTrace.startpos.z)
                                                          + (float)(waterTrace.startpos.y * waterTrace.startpos.y))
                                                  + (float)(waterTrace.endpos.x * waterTrace.endpos.x)) != 0.0;
      memset(&waterTrace.plane.dist, 0, 12);
      *(_DWORD *)&waterTrace.dispFlags = 0;
      LOBYTE(waterTrace.fractionleftsolid) = 1;
      memset(&waterTrace.endpos.z, 0, 12);
      vecEnd.y = x;
      vecEnd.z = y;
      cacheCriticalSection.m_pCache = (IMDLCache *)LODWORD(z);
      CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        this: (CTraceFilterSkipTwoEntities *)&v57,
        passentity: this,
        passentity2: (const IHandleEntity *)LODWORD(v17),
        collisionGroup: 0);
      enginetrace->TraceRay(
        this: enginetrace,
        a2: (const Ray_t *)&vecEnd.y,
        a3: 1174421515u,
        a4: (ITraceFilter *)&v57,
        a5: (CGameTrace *)&v58);
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(vecAbsStart: &v58, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
      CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
        this: (CTraceFilterSkipTwoEntities *)&v57,
        passentity: this,
        passentity2: (const IHandleEntity *)LODWORD(v17),
        collisionGroup: 0);
      v54.x = (float)(*(float *)&iPenetrationKills * 40.0) + *(float *)&iMaxPenetration;
      v54.y = (float)(flPenetrationPower * 40.0) + *(float *)&iEnterMaterial;
      v54.z = (float)(*(float *)&iDamageType * 40.0) + v64;
      UTIL_ClipTraceToPlayers(
        a1: (int)&fCurrentDamage + 4,
        vecAbsStart: &vecSrc,
        vecAbsEnd: &v54,
        mask: 0x4600400Bu,
        filter: (ITraceFilter *)&v57,
        tr: (CGameTrace *)&v58);
      v25 = *(float *)&tr.surface.surfaceProps;
      if ( *(_DWORD *)&tr.surface.surfaceProps == 0
        || (v26 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 336))(a1: *(_DWORD *)&tr.surface.surfaceProps),
            penetrationEnd.x = v25,
            v26 == 0) )
      {
        penetrationEnd.x = 0.0;
      }
      if ( tr.plane.normal.z == 1.0 )
        break;
      v27 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, _DWORD))gameeventmanager->CreateEventA)(
                            a1: gameeventmanager,
                            a2: "bullet_impact",
                            a3: 0,
                            a4: 0,
                            a5: LODWORD(fCurrentDamage));
      if ( v27 != nullptr )
      {
        v28 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
        v27->SetInt(this: v27, a2: "userid", a3: v28);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v27->SetFloat)(
          a1: v27,
          a2: "x",
          a3: LODWORD(tr.startpos.x));
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v27->SetFloat)(
          a1: v27,
          a2: "y",
          a3: LODWORD(tr.startpos.y));
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v27->SetFloat)(
          a1: v27,
          a2: "z",
          a3: LODWORD(tr.startpos.z));
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v27, a3: false);
      }
      material = physprops->GetSurfaceData(this: physprops, a2: (__int16)tr.dispFlags)->game.material;
      switch ( material )
      {
        case 'C':
          LODWORD(fCurrentDamage) = 1053609165;
          v29 = 0.25;
          break;
        case 'D':
        case 'M':
          LODWORD(fCurrentDamage) = 1056964608;
          v29 = 0.30000001;
          break;
        case 'G':
          LODWORD(fCurrentDamage) = 1065353216;
          v29 = 0.99000001;
          break;
        case 'P':
          LODWORD(fCurrentDamage) = 1053609165;
          v29 = 0.44999999;
          break;
        case 'T':
          LODWORD(fCurrentDamage) = 1059481190;
          v29 = 0.30000001;
          break;
        case 'V':
          LODWORD(fCurrentDamage) = 1056964608;
          v29 = 0.44999999;
          break;
        case 'W':
          LODWORD(fCurrentDamage) = 1065353216;
          v29 = 0.60000002;
          break;
        default:
          LODWORD(fCurrentDamage) = 1065353216;
          v29 = 0.5;
          break;
      }
      flCurrentDistance = v29;
      BYTE2(vecDir.z) = (LOBYTE(tr.plane.dist) & 8) != 0;
      if ( (LOBYTE(tr.plane.dist) & 8) != 0 )
      {
        LODWORD(fCurrentDamage) = 1065353216;
        flCurrentDistance = 0.99000001;
      }
      if ( sv_showimpacts.m_pParent != nullptr )
      {
        v30 = sv_showimpacts.m_pParent->m_Value.m_nValue;
        if ( v30 == 1 || v30 == 3 )
        {
          vecDirShooting.x = 2.0;
          vecDirShooting.y = 2.0;
          vecDirShooting.z = 2.0;
          vecRight.x = -2.0;
          vecRight.y = -2.0;
          vecRight.z = -2.0;
          NDebugOverlay::Box(
            origin: &tr.startpos,
            mins: &vecRight,
            maxs: &vecDirShooting,
            r: 0,
            g: 0,
            b: 255,
            a: 127,
            flDuration: 4.0);
          if ( *(_DWORD *)&tr.surface.surfaceProps != 0
            && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 336))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
          {
            v27 = *(IGameEvent **)&tr.surface.surfaceProps;
            if ( *(_DWORD *)&tr.surface.surfaceProps != 0
              && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)&tr.surface.surfaceProps + 336))(a1: *(_DWORD *)&tr.surface.surfaceProps) != 0 )
            {
              v31 = (CBaseAnimating *)v27;
            }
            else
            {
              v31 = nullptr;
            }
            CBaseAnimating::DrawServerHitboxes(this: v31, duration: 4.0, monocolor: true);
          }
        }
      }
      vecDir.x = (float)(tr.plane.normal.z * flDistance) + vecDir.x;
      v32 = flRangeModifier;
      __libm_sse2_pow(x: fCurrentDamage, y: flDamageModifier);
      *(float *)&v32 = v32;
      vecDir.y = *(float *)&v32 * vecDir.y;
      if ( vecDir.x > penetrationEnd.y && iPenetration > 0 )
        iPenetration = 0;
      CSoundEnt::InsertSound(
        iType: 16,
        vecOrigin: &tr.startpos,
        iVolume: 400,
        flDuration: 0.2,
        pOwner: this,
        soundChannelIndex: 0,
        pSoundTarget: nullptr);
      flPenetrationDistance = 4098;
      ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this);
      if ( ActiveCSWeapon != nullptr && ActiveCSWeapon->GetCSWeaponID(this: ActiveCSWeapon) == WEAPON_TASER )
        flPenetrationDistance = 4352;
      if ( bDoEffects )
      {
        if ( (enginetrace->GetPointContents(this: enginetrace, a2: (const Vector *)&tr, a3: 16432, a4: nullptr) & 0x30) != 0 )
        {
          UTIL_TraceLine(
            a1: (const IHandleEntity *)&fCurrentDamage + 1,
            a2: (int)v27,
            vecAbsStart: &vecSrc,
            vecAbsEnd: &tr.startpos,
            mask: 0x46004033u,
            ignore: this,
            collisionGroup: 0,
            ptr: (CGameTrace *)&vecEnd.y);
          if ( waterTrace.plane.pad[0] != 1 )
          {
            memset(&data, 0, 12);
            memset((void *)&data.m_vNormal, 0, 20);
            memset(&data.m_fFlags, 0, 14);
            *(Vector *)&exitTr[76] = waterTrace.startpos;
            data.m_vStart = waterTrace.endpos;
            memset(&data.m_flRadius, 0, 17);
            data.m_vAngles.z = 1.0;
            data.m_vAngles.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                 a1: random,
                                 a2: 1090519040,
                                 a3: 1094713344);
            if ( (LOBYTE(waterTrace.plane.dist) & 0x10) != 0 )
              LODWORD(data.m_vAngles.x) |= 1u;
            DispatchEffect(pName: "gunshotsplash", data: (const CEffectData *)&exitTr[76]);
          }
        }
        else if ( (*(_WORD *)&tr.allsolid & 0x384) == 0
               && (friendlyfire.m_pParent != nullptr && friendlyfire.m_pParent->m_Value.m_nValue != 0
                || *(_DWORD *)&tr.surface.surfaceProps == 0
                || (TeamNumber = CBaseEntity::GetTeamNumber(this: *(CBaseEntity **)&tr.surface.surfaceProps)) != CBaseEntity::GetTeamNumber(this)) )
        {
          UTIL_ImpactTrace(pTrace: (CGameTrace *)&v58, iDamageType: flPenetrationDistance, pCustomImpactName: nullptr);
        }
      }
      ClearMultiDamage();
      v35 = *(CBaseEntity **)&tr.surface.surfaceProps;
      CTakeDamageInfo::CTakeDamageInfo(
        this: (CTakeDamageInfo *)v47,
        pInflictor: pevAttacker,
        pAttacker: pevAttacker,
        flDamage: vecDir.y,
        bitsDamageType: flPenetrationDistance,
        iKillType: 0,
        iObjectsPenetrated: tr.hitbox - iPenetration);
      LODWORD(info.m_flRadius) = CCSPlayer::GetBulletGroup();
      CalculateBulletDamageForce(
        info: (CTakeDamageInfo *)v47,
        iBulletType,
        vecBulletDir: (const Vector *)&iPenetrationKills,
        vecForceOrigin: &tr.startpos,
        flScale: 1.0);
      CBaseEntity::DispatchTraceAttack(
        this: v35,
        info: (const CTakeDamageInfo *)v47,
        vecDir: (const Vector *)&iPenetrationKills,
        ptr: (CGameTrace *)&v58);
      v35->IsAlive(this: v35);
      CBaseEntity::TraceAttackToTriggers(
        this,
        a2: (int)&fCurrentDamage + 4,
        info: (const CTakeDamageInfo *)v47,
        start: &v58,
        end: &tr.startpos,
        dir: (const Vector *)&iPenetrationKills);
      ApplyMultiDamage();
      if ( HIBYTE(vecDir.z) != 0 && !v35->IsAlive(this: v35) && v35->IsPlayer(this: v35) )
      {
        v36 = CBaseEntity::GetTeamNumber(this: v35);
        if ( v36 != CBaseEntity::GetTeamNumber(this) )
          ++LODWORD(penetrationEnd.z);
      }
      v37 = iPenetration;
      if ( iPenetration != 0 )
      {
        if ( iPenetration < 0 )
          break;
      }
      else if ( BYTE2(vecDir.z) == 0 )
      {
        break;
      }
      v38 = 0.0;
      while ( 1 )
      {
        v39 = v38 + 24.0;
        flCurrentDistance = 0.0;
        v68.x = (float)(v39 * *(float *)&iPenetrationKills) + tr.startpos.x;
        v68.y = (float)(flPenetrationPower * v39) + tr.startpos.y;
        v68.z = (float)(*(float *)&iDamageType * v39) + tr.startpos.z;
        GetPointContents = enginetrace->GetPointContents;
        v61 = v39;
        if ( (GetPointContents(this: enginetrace, a2: &v68, a3: -1, a4: nullptr) & 0x200400B) == 0 )
          break;
        v38 = v61;
        if ( v61 > 128.0 )
          goto LABEL_85;
      }
      waterTrace.startpos.z = tr.startpos.y - v68.y;
      waterTrace.startpos.y = tr.startpos.x - v68.x;
      waterTrace.endpos.x = tr.startpos.z - v68.z;
      BYTE1(waterTrace.fractionleftsolid) = (float)((float)((float)(waterTrace.startpos.z * waterTrace.startpos.z)
                                                          + (float)(waterTrace.startpos.y * waterTrace.startpos.y))
                                                  + (float)(waterTrace.endpos.x * waterTrace.endpos.x)) != 0.0;
      flCurrentDistance = COERCE_FLOAT((CTakeDamageInfo *)&info.m_iObjectsPenetrated);
      vecDir.z = 0.0;
      memset(&waterTrace.plane.dist, 0, 12);
      *(_DWORD *)&waterTrace.dispFlags = 0;
      LOBYTE(waterTrace.fractionleftsolid) = 1;
      memset(&waterTrace.endpos.z, 0, 12);
      vecEnd.y = v68.x;
      vecEnd.z = v68.y;
      cacheCriticalSection.m_pCache = (IMDLCache *)LODWORD(v68.z);
      ((void (__thiscall *)(IEngineTrace *, float *, int, _DWORD, int *, _DWORD))enginetrace->TraceRay)(
        a1: enginetrace,
        a2: &vecEnd.y,
        a3: 1174421515,
        a4: 0,
        a5: &info.m_iObjectsPenetrated,
        a6: LODWORD(fCurrentDamage));
      if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
        DebugDrawLine(
          vecAbsStart: (const Vector *)&info.m_iObjectsPenetrated,
          vecAbsEnd: (const Vector *)exitTr,
          r: 255,
          g: 0,
          b: 0,
          test: 1,
          duration: -1.0);
      if ( *(_DWORD *)&exitTr[64] != *(_DWORD *)&tr.surface.surfaceProps && *(_DWORD *)&exitTr[64] != 0 )
        UTIL_TraceLine(
          a1: (const IHandleEntity *)&fCurrentDamage + 1,
          a2: v37,
          vecAbsStart: &v68,
          vecAbsEnd: &tr.startpos,
          mask: 0x4600400Bu,
          ignore: *(const IHandleEntity **)&exitTr[64],
          collisionGroup: 0,
          ptr: (CGameTrace *)&info.m_iObjectsPenetrated);
      GetSurfaceData = physprops->GetSurfaceData;
      LODWORD(fCurrentDamage) = *(__int16 *)&exitTr[52];
      v42 = *(unsigned __int16 *)(((int (__thiscall *)(IPhysicsSurfaceProps *))GetSurfaceData)(a1: physprops) + 76);
      if ( material == v42 && (v42 == 87 || v42 == 77) )
        *(float *)&fCurrentDamage = *(float *)&fCurrentDamage * 2.0;
      v43 = 0;
      *(float *)&v43 = fsqrt(
                         (float)((float)((float)(*(float *)exitTr - tr.startpos.x)
                                       * (float)(*(float *)exitTr - tr.startpos.x))
                               + (float)((float)(*(float *)&exitTr[4] - tr.startpos.y)
                                       * (float)(*(float *)&exitTr[4] - tr.startpos.y)))
                       + (float)((float)(*(float *)&exitTr[8] - tr.startpos.z)
                               * (float)(*(float *)&exitTr[8] - tr.startpos.z)));
      v57 = v43;
      if ( *(float *)&v43 > (float)(*(float *)&fCurrentDamage * *(float *)&lastPlayerHit) )
        break;
      if ( bDoEffects )
        UTIL_ImpactTrace(
          pTrace: (CGameTrace *)&info.m_iObjectsPenetrated,
          iDamageType: flPenetrationDistance,
          pCustomImpactName: nullptr);
      x = *(float *)exitTr;
      y = *(float *)&exitTr[4];
      z = *(float *)&exitTr[8];
      *(float *)&lastPlayerHit = *(float *)&lastPlayerHit - (float)(*(float *)&v57 / *(float *)&fCurrentDamage);
      v44 = (float)(flDistance - (float)(*(float *)&v57 + vecDir.x)) * 0.5;
      vecDir.x = *(float *)&v57 + vecDir.x;
      v21 = v44;
      vecSrc = *(Vector *)exitTr;
      flDistance = v44;
      vecDir.y = flCurrentDistance * vecDir.y;
      iPenetration = v37 - 1;
      if ( vecDir.y <= 0.0 )
        break;
      v17 = penetrationEnd.x;
    }
LABEL_85:
    if ( SLODWORD(penetrationEnd.z) >= 2 )
      CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 3040, iCount: 1);
  }
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(vecEnd.x) + 124))(a1: LODWORD(vecEnd.x));
}

//------------------------------------------------------------------------------
// Address: 0x10295E50
// Name: public: void CCSPlayer::KickBack(float,float,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::KickBack(
        CCSPlayer *this,
        float up_base,
        float lateral_base,
        float up_modifier,
        float lateral_modifier,
        float up_max,
        float lateral_max,
        IUniformRandomStream *direction_change)
{
  float v9; // xmm0_4
  float m_Value; // xmm0_4
  float v11; // xmm1_4
  bool v12; // cc
  int v13; // edi
  edict_t *m_pPev; // ecx
  QAngle angle; // [esp+Ch] [ebp-Ch] BYREF
  float flKickUp; // [esp+28h] [ebp+10h]

  if ( this->m_iShotsFired.m_Value == 1 )
  {
    flKickUp = up_base;
    v9 = lateral_base;
  }
  else
  {
    m_Value = (float)this->m_iShotsFired.m_Value;
    v11 = (float)(m_Value * up_modifier) + up_base;
    v9 = (float)(m_Value * lateral_modifier) + lateral_base;
    flKickUp = v11;
  }
  angle = CBasePlayer::GetPunchAngle(this)->m_Value;
  v12 = (float)(up_max * -1.0) <= (float)(angle.x - flKickUp);
  angle.x = angle.x - flKickUp;
  if ( !v12 )
    angle.x = up_max * -1.0;
  if ( this->m_iDirection.m_Value == 1 )
  {
    angle.y = angle.y + v9;
    if ( angle.y > lateral_max )
      angle.y = lateral_max;
  }
  else
  {
    v12 = (float)(lateral_max * -1.0) <= (float)(angle.y - v9);
    angle.y = angle.y - v9;
    if ( !v12 )
      angle.y = lateral_max * -1.0;
  }
  if ( SharedRandomInt(sharedname: "KickBack", iMinVal: 0, iMaxVal: direction_change, additionalSeed: 0) == 0 )
  {
    v13 = 1 - this->m_iDirection.m_Value;
    if ( this->m_iDirection.m_Value != v13 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1784u);
      }
      this->m_iDirection.m_Value = v13;
    }
  }
  CBasePlayer::SetPunchAngle(this, punchAngle: &angle);
}

//------------------------------------------------------------------------------
// Address: 0x10407DB0
// Name: _dynamic_initializer_for__player_debug_print_damage__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_debug_print_damage__()
{
  ConVar::ConVar(
    this: &player_debug_print_damage,
    pName: "player_debug_print_damage",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "When true, print amount and type of all damage received by player to console.");
  return atexit(func: dynamic_atexit_destructor_for__player_debug_print_damage__);
}

//------------------------------------------------------------------------------
// Address: 0x10407FE0
// Name: _dynamic_initializer_for__player_weaponstrip__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_weaponstrip__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CStripWeapons> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &player_weaponstrip,
           a3: "player_weaponstrip");
}

//------------------------------------------------------------------------------
// Address: 0x10408010
// Name: _dynamic_initializer_for__player_loadsaved__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_loadsaved__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CRevertSaved> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &player_loadsaved,
           a3: "player_loadsaved");
}

//------------------------------------------------------------------------------
// Address: 0x10408040
// Name: _dynamic_initializer_for__player_speedmod__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_speedmod__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CMovementSpeedMod> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &player_speedmod,
           a3: "player_speedmod");
}

//------------------------------------------------------------------------------
// Address: 0x104083A0
// Name: _dynamic_initializer_for__player_manager__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player_manager__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CPlayerResource> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &player_manager,
           a3: "player_manager");
}

//------------------------------------------------------------------------------
// Address: 0x1040EFB0
// Name: _dynamic_initializer_for__player__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__player__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CCSPlayer> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &player,
           a3: "player");
}

//------------------------------------------------------------------------------
// Address: 0x1040F350
// Name: CFootstepControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFootstepControl_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFootstepControl>(__formal: nullptr);
  CFootstepControl_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F380
// Name: DT_FootstepControl::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FootstepControl::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FootstepControl::g_SendTable);
  return atexit(func: DT_FootstepControl::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F3A0
// Name: DT_FootstepControl::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FootstepControl::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FootstepControl::ignored>();
  DT_FootstepControl::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D0B0
// Name: _dynamic_atexit_destructor_for__player_debug_print_damage__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__player_debug_print_damage__()
{
  ConVar::~ConVar(this: &player_debug_print_damage);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDB0
// Name: DT_FootstepControl::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FootstepControl::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FootstepControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10295FA0
// Name: struct datamap_t __near * DataMapInit<class CFootstepControl>(class CFootstepControl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFootstepControl>()
{
  if ( (_S2_244 & 1) == 0 )
  {
    _S2_244 |= 1u;
    nameHolder_474.m_pszBase = "CFootstepControl";
    nameHolder_474.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_474.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_474.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_474.m_Names.m_Size = 0;
    nameHolder_474.m_Names.m_pElements = nullptr;
    nameHolder_474.m_nLenBase = 16;
    atexit(func: DataMapInit_CFootstepControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFootstepControl::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CFootstepControl::m_DataMap.dataNumFields = 2;
  CFootstepControl::m_DataMap.dataDesc = &dataDesc_442[1];
  return &CFootstepControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10407DE0
// Name: _dynamic_initializer_for__givecurrentammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__givecurrentammo__()
{
  ConCommand::ConCommand(
    this: &givecurrentammo,
    pName: "givecurrentammo",
    callback: CC_GiveCurrentAmmo,
    pHelpString: "Give a supply of ammo for current weapon..\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__givecurrentammo__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F360
// Name: _dynamic_initializer_for__g_CFootstepControl_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFootstepControl_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFootstepControl_ClassReg,
           pNetworkName: "CFootstepControl",
           pTable: &DT_FootstepControl::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0C0
// Name: _dynamic_atexit_destructor_for__givecurrentammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__givecurrentammo__()
{
  ConCommand::~ConCommand(this: &givecurrentammo);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0D0
// Name: _dynamic_atexit_destructor_for__VisForce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__VisForce__()
{
  ConVar::~ConVar(this: &VisForce);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0E0
// Name: _dynamic_atexit_destructor_for__sv_clockcorrection_msecs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_clockcorrection_msecs__()
{
  ConVar::~ConVar(this: &sv_clockcorrection_msecs);
}

//------------------------------------------------------------------------------
// Address: 0x1041D0F0
// Name: _dynamic_atexit_destructor_for__sv_playerperfhistorycount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_playerperfhistorycount__()
{
  ConVar::~ConVar(this: &sv_playerperfhistorycount);
}

//------------------------------------------------------------------------------
// Address: 0x1041D100
// Name: _dynamic_atexit_destructor_for__xc_crouch_debounce__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xc_crouch_debounce__()
{
  ConVar::~ConVar(this: &xc_crouch_debounce);
}

//------------------------------------------------------------------------------
// Address: 0x1041D110
// Name: _dynamic_atexit_destructor_for__ch_createjeep__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ch_createjeep__()
{
  ConCommand::~ConCommand(this: &ch_createjeep);
}

//------------------------------------------------------------------------------
// Address: 0x1041D120
// Name: _dynamic_atexit_destructor_for__ch_createairboat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ch_createairboat__()
{
  ConCommand::~ConCommand(this: &ch_createairboat);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDC0
// Name: _ServerClassInit_DT_FootstepControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FootstepControl::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_148;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDE0
// Name: _DataMapInit_CFootstepControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CFootstepControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_474);
}

} // namespace server
