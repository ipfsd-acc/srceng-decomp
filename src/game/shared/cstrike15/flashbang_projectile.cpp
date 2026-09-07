// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/flashbang_projectile.cpp
// Functions: 14
// ============================================================

#include "game\shared\cstrike15\flashbang_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x10299C90
// Name: public: virtual void CFlashbangProjectile::BounceSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashbangProjectile::BounceSound(CDecoyProjectile *this)
{
  CBaseEntity::EmitSound(this, soundname: "Flashbang.Bounce", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6B0
// Name: public: virtual void flashbang_projectilePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall flashbang_projectilePrecache::CResourcePrecacher::Cache(
        flashbang_projectilePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "flashbang_projectile",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6E0
// Name: public: virtual struct datamap_t __near * CFlashbangProjectile::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFlashbangProjectile::GetDataDescMap(CFlashbangProjectile *this)
{
  return &CFlashbangProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1029A6F0
// Name: public: static class CFlashbangProjectile __near * CFlashbangProjectile::Create(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
CFlashbangProjectile *__cdecl CFlashbangProjectile::Create(
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        CBaseCombatCharacter *pOwner)
{
  CBaseCSGrenadeProjectile *v5; // esi
  CBaseCSGrenadeProjectile_vtbl *v6; // ebx
  int TeamNumber; // eax

  v5 = (CBaseCSGrenadeProjectile *)CBaseEntity::Create(
                                     szName: "flashbang_projectile",
                                     vecOrigin: position,
                                     vecAngles: angles,
                                     pOwner);
  CBaseEntity::SetAbsVelocity(this: v5, vecAbsVelocity: velocity);
  CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(this: v5, velocity);
  CBaseGrenade::SetThrower(this: v5, pThrower: pOwner);
  v6 = v5->CBaseGrenade::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: pOwner);
  v6->ChangeTeam(this: v5, a2: TeamNumber);
  CBaseEntity::ApplyLocalAngularVelocityImpulse(this: v5, angImpulse: angVelocity);
  return (CFlashbangProjectile *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x1029A760
// Name: public: virtual void CFlashbangProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFlashbangProjectile::Precache(
        CFlashbangProjectile *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/Weapons/w_eq_flashbang_thrown.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "Flashbang.Explode");
  CBaseEntity::PrecacheScriptSound(soundname: "Flashbang.Bounce");
  CBaseCSGrenadeProjectile::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A790
// Name: public: void CFlashbangProjectile::InputSetTimer(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashbangProjectile::InputSetTimer(CFlashbangProjectile *this, inputdata_t *inputdata)
{
  const char *timer; // xmm0_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    timer = inputdata->value.iszVal.pszValue;
  else
    timer = nullptr;
  LODWORD(this->m_flTimeToDetonate) = timer;
  CBaseCSGrenadeProjectile::SetDetonateTimerLength(this, timer: *(float *)&timer);
}

//------------------------------------------------------------------------------
// Address: 0x1029A7D0
// Name: float PercentageOfFlashForPlayer(class CBaseEntity __near *,class Vector,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __usercall PercentageOfFlashForPlayer@<st0>(
        int a1@<edi>,
        int a2@<esi>,
        CBaseEntity *player,
        Vector flashPos,
        CBaseEntity *pevInflictor)
{
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  Vector *v6; // eax
  CBaseEntity *v7; // edi
  float v9; // xmm0_4
  QAngle tempAngle; // [esp+0h] [ebp-A0h] BYREF
  CGameTrace tr; // [esp+Ch] [ebp-94h] BYREF
  _BYTE v13[12]; // [esp+60h] [ebp-40h] BYREF
  Vector forward; // [esp+6Ch] [ebp-34h] BYREF
  Vector vecRight; // [esp+78h] [ebp-28h] BYREF
  Vector vecUp; // [esp+84h] [ebp-1Ch] BYREF
  float retval; // [esp+90h] [ebp-10h]
  Vector pos; // [esp+94h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+A0h] [ebp+0h] BYREF

  EyePosition = player->EyePosition;
  retval = 0.0;
  ((void (__thiscall *)(CBaseEntity *, Vector *, int, int))EyePosition)(a1: player, a2: &pos, a3: a1, a4: a2);
  v6 = player->EyePosition(this: player, result: v13);
  forward.x = v6->x - flashPos.x;
  forward.y = v6->y - flashPos.y;
  forward.z = v6->z - flashPos.z;
  VectorAngles(&forward, angles: &tempAngle);
  AngleVectors(angles: &tempAngle, forward: nullptr, right: &vecRight, up: &vecUp);
  VectorNormalize(vec: &vecRight);
  VectorNormalize(vec: &vecUp);
  v7 = pevInflictor;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &flashPos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: pevInflictor,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 || tr.m_pEnt == player )
    return 1.0;
  if ( !player->IsPlayer(this: player) )
    return 0.0;
  pos.x = (float)(vecUp.x * 50.0) + flashPos.x;
  pos.y = (float)(vecUp.y * 50.0) + flashPos.y;
  pos.z = (float)(vecUp.z * 50.0) + flashPos.z;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &flashPos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  pos = *player->EyePosition(this: player, result: v13);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &tr.endpos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 || tr.m_pEnt == player )
    retval = 0.167;
  pos.x = (float)((float)(vecRight.x * 75.0) + flashPos.x) + (float)(vecUp.x * 10.0);
  pos.y = (float)((float)(vecRight.y * 75.0) + flashPos.y) + (float)(vecUp.y * 10.0);
  pos.z = (float)((float)(vecRight.z * 75.0) + flashPos.z) + (float)(vecUp.z * 10.0);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &flashPos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  pos = *player->EyePosition(this: player, result: v13);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &tr.endpos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 || tr.m_pEnt == player )
  {
    v9 = retval + 0.167;
    retval = v9;
  }
  pos.x = (float)(flashPos.x - (float)(vecRight.x * 75.0)) + (float)(vecUp.x * 10.0);
  pos.y = (float)(flashPos.y - (float)(vecRight.y * 75.0)) + (float)(vecUp.y * 10.0);
  pos.z = (float)(flashPos.z - (float)(vecRight.z * 75.0)) + (float)(vecUp.z * 10.0);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &flashPos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  pos = *player->EyePosition(this: player, result: v13);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)player,
    vecAbsStart: &tr.endpos,
    vecAbsEnd: &pos,
    mask: 0x6004001u,
    ignore: v7,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 || tr.m_pEnt == player )
    return (float)(retval + 0.167);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1029ABE0
// Name: void RadiusFlash(class Vector,class CBaseEntity __near *,class CBaseEntity __near *,float,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall RadiusFlash(
        CCSPlayer *a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        Vector vecSrc,
        CBaseEntity *pevInflictor,
        CBaseEntity *pevAttacker,
        float flDamage)
{
  CBaseEntity *v7; // edi
  int v8; // eax
  CCSPlayer *i; // esi
  const char *pszValue; // eax
  float *v11; // eax
  double v13; // st7
  float *v14; // eax
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  CCSPlayer_vtbl *v17; // edx
  const QAngle *v18; // eax
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  float v21; // xmm0_4
  float y; // xmm0_4
  float v23; // xmm1_4
  bool v24; // cf
  float v25; // xmm0_4
  CBaseEntity *v26; // eax
  CBaseEntity *v27; // edi
  unsigned int *v28; // eax
  float z; // xmm0_4
  int TeamNumber; // edi
  void (__thiscall *DynamicLight)(ITempEntsSystem *, IRecipientFilter *, float, const Vector *, int, int, int, int, float, float, float); // edx
  int v33; // [esp+68h] [ebp-B0h] BYREF
  int v34; // [esp+74h] [ebp-A4h] BYREF
  _DWORD v35[3]; // [esp+80h] [ebp-98h] BYREF
  CPVSFilter filter; // [esp+8Ch] [ebp-8Ch] BYREF
  __int128 vForward; // [esp+ACh] [ebp-6Ch] OVERLAPPED
  float v38; // [esp+D8h] [ebp-40h]
  float v39; // [esp+DCh] [ebp-3Ch]
  float v40; // [esp+E0h] [ebp-38h]
  Vector vecEyePos; // [esp+E4h] [ebp-34h]
  float falloff; // [esp+F0h] [ebp-28h]
  float fadeHold; // [esp+F4h] [ebp-24h] BYREF
  float flDot; // [esp+F8h] [ebp-20h]
  float fadeTime; // [esp+FCh] [ebp-1Ch]
  Vector vecLOS; // [esp+100h] [ebp-18h]
  CCSPlayer *attacker; // [esp+10Ch] [ebp-Ch]
  void *flAdjustedDamage; // [esp+110h] [ebp-8h]
  void *retaddr; // [esp+118h] [ebp+0h]

  attacker = a1;
  flAdjustedDamage = retaddr;
  v7 = pevAttacker;
  vecSrc.z = vecSrc.z + 1.0;
  if ( pevAttacker == nullptr )
  {
    pevAttacker = pevInflictor;
    v7 = pevInflictor;
  }
  v8 = ((int (__thiscall *)(IEngineTrace *, Vector *, int, _DWORD, int, int))enginetrace->GetPointContents)(
         a1: enginetrace,
         a2: &vecSrc,
         a3: 16432,
         a4: 0,
         a5: a2,
         a6: a3);
  vecLOS.z = flRadius;
  BYTE1(vecLOS.z) = v8 == 32;
  for ( i = (CCSPlayer *)CGlobalEntityList::FindEntityInSphere(
                           this: &gEntList,
                           pStartEntity: nullptr,
                           vecCenter: &vecSrc,
                           flRadius: vecLOS.z);
        i != nullptr;
        i = (CCSPlayer *)CGlobalEntityList::FindEntityInSphere(
                           this: &gEntList,
                           pStartEntity: i,
                           vecCenter: &vecSrc,
                           flRadius: flRadius) )
  {
    HIBYTE(vecLOS.z) = ((int (__thiscall *)(CCSPlayer *, CCSPlayer *, void *))i->IsPlayer)(
                         a1: i,
                         a2: attacker,
                         a3: flAdjustedDamage);
    pszValue = i->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    BYTE2(vecLOS.z) = _V_stricmp(s1: pszValue, s2: "hostage_entity") == 0;
    if ( HIWORD(vecLOS.z) != 0 )
    {
      v11 = (float *)i->EyePosition(this: i, result: (Vector *)&v34);
      v38 = *v11;
      v39 = v11[1];
      v40 = v11[2];
      if ( !(BYTE1(vecLOS.z) != 0 ? i->m_nWaterLevel.m_Value == 0 : i->m_nWaterLevel.m_Value == 3) )
      {
        v13 = PercentageOfFlashForPlayer(a1: (int)v7, a2: (int)i, player: i, flashPos: vecSrc, pevInflictor);
        vecLOS.x = v13;
        if ( v13 > 0.0 )
        {
          v14 = (float *)i->EyePosition(this: i, result: (Vector *)&v33);
          v15 = 0;
          *(float *)&v15 = (float)((float)((float)(vecSrc.y - v14[1]) * (float)(vecSrc.y - v14[1]))
                                 + (float)((float)(vecSrc.z - v14[2]) * (float)(vecSrc.z - v14[2])))
                         + (float)((float)(vecSrc.x - *v14) * (float)(vecSrc.x - *v14));
          v16 = v15;
          *(float *)&v16 = fsqrt(*(float *)&v15);
          vForward = v16;
          vecLOS.y = flDamage - (float)(*(float *)&v16 * vecEyePos.x);
          if ( vecLOS.y > 0.0 )
          {
            v17 = i->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
            LODWORD(vecLOS.z) = &filter.m_Recipients.m_Size;
            v18 = v17->EyeAngles(this: i);
            AngleVectors(angles: v18, forward: (Vector *)LODWORD(vecLOS.z));
            flDot = vecSrc.y - v39;
            fadeTime = vecSrc.z - v40;
            fadeHold = vecSrc.x - v38;
            v19 = 0;
            *(float *)&v19 = (float)((float)(flDot * flDot) + (float)(fadeTime * fadeTime))
                           + (float)(fadeHold * fadeHold);
            v20 = v19;
            *(float *)&v20 = fsqrt(*(float *)&v19);
            vForward = v20;
            VectorNormalize(vec: (Vector *)&fadeHold);
            v21 = (float)((float)(*(float *)&filter.m_Recipients.m_pElements * flDot)
                        + (float)(*(float *)&filter.m_Recipients.m_Size * fadeHold))
                + (float)(*(float *)&filter.m_bUsingPredictionRules * fadeTime);
            vecEyePos.z = v21;
            if ( v21 < 0.6 )
            {
              if ( v21 < 0.3 )
              {
                v24 = v21 < -0.2;
                y = vecLOS.y;
                if ( v24 )
                {
                  y = vecLOS.y * 0.5;
                  v23 = vecLOS.y * 0.25;
                }
                else
                {
                  v23 = vecLOS.y * 0.5;
                }
              }
              else
              {
                y = vecLOS.y * 1.75;
                v23 = vecLOS.y * 0.80000001;
              }
            }
            else
            {
              y = vecLOS.y * 2.5;
              v23 = vecLOS.y * 1.25;
            }
            v25 = y * vecLOS.x;
            falloff = v25;
            vecEyePos.y = v23 * vecLOS.x;
            if ( HIBYTE(vecLOS.z) != 0 )
            {
              if ( v7 != nullptr && v7->IsPlayer(this: v7) )
              {
                v26 = (CBaseEntity *)__RTDynamicCast(
                                       inptr: v7,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                                       isReference: 0);
                v27 = v26;
                LODWORD(vecLOS.x) = v26;
                if ( v26 != nullptr )
                {
                  v28 = (unsigned int *)v26->GetRefEHandle(this: v26);
                  z = vecEyePos.z;
                  i->m_lastFlashBangAttacker.m_Index = *v28;
                  if ( z >= 0.0 )
                  {
                    TeamNumber = CBaseEntity::GetTeamNumber(this: v27);
                    if ( TeamNumber == CBaseEntity::GetTeamNumber(this: i) )
                      CCSGameRules::ScoreBlindFriendly(
                        this: (CCSGameRules *)g_pGameRules,
                        pPlayer: (CCSPlayer *)LODWORD(vecLOS.x));
                    else
                      CCSGameRules::ScoreBlindEnemy(
                        this: (CCSGameRules *)g_pGameRules,
                        pPlayer: (CCSPlayer *)LODWORD(vecLOS.x));
                  }
                }
                v7 = pevAttacker;
              }
              ((void (__thiscall *)(CCSPlayer *, _DWORD, _DWORD, int))i->Blind)(
                a1: i,
                a2: LODWORD(vecEyePos.y),
                a3: LODWORD(falloff),
                a4: 1132396544);
              CCSPlayer::Deafen(this: i, flDistance: *(float *)&vForward);
            }
            else if ( BYTE2(vecLOS.z) != 0 )
            {
              *(float *)&vForward = v25;
              ((void (__thiscall *)(CCSPlayer *, const char *, CBaseEntity *, CBaseEntity *, float, _DWORD, _DWORD, int, int, _DWORD))i->AcceptInput)(
                a1: i,
                a2: "flashbang",
                a3: pevInflictor,
                a4: v7,
                a5: COERCE_FLOAT(LODWORD(v25)),
                a6: DWORD1(vForward),
                a7: DWORD2(vForward),
                a8: -1,
                a9: 1,
                a10: 0);
            }
          }
        }
      }
    }
  }
  CRecipientFilter::CRecipientFilter(this: (CRecipientFilter *)v35);
  v35[0] = &CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: (CRecipientFilter *)v35, origin: &vecSrc);
  DynamicLight = te->DynamicLight;
  *(_QWORD *)&vecLOS.y = 0x444000003DCCCCCDLL;
  vecLOS.x = 400.0;
  ((void (__stdcall *)(_DWORD *, _DWORD, Vector *, int, int, int, int))DynamicLight)(
    a1: v35,
    a2: 0,
    a3: &vecSrc,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 2);
  CRecipientFilter::~CRecipientFilter(this: (CRecipientFilter *)v35);
}

//------------------------------------------------------------------------------
// Address: 0x1029B0E0
// Name: public: virtual void CFlashbangProjectile::Detonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFlashbangProjectile::Detonate(CFlashbangProjectile *this@<ecx>, CCSPlayer *a2@<ebp>, int a3@<edi>)
{
  CBaseCombatCharacter *Thrower; // eax
  CBaseCombatCharacter *v5; // eax
  CBaseCombatCharacter *v6; // edi
  const edict_t **v7; // ebx
  IGameEvent *v8; // edi
  int v9; // eax

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, (int)a2);
  Thrower = CBaseGrenade::GetThrower(this);
  RadiusFlash(
    a1: a2,
    a2: a3,
    a3: (int)this,
    vecSrc: this->m_vecAbsOrigin,
    pevInflictor: this,
    pevAttacker: Thrower,
    flDamage: 4.0);
  CBaseEntity::EmitSound(this, soundname: "Flashbang.Explode", soundtime: 0.0, duration: nullptr);
  v5 = CBaseGrenade::GetThrower(this);
  v6 = v5;
  if ( v5 != nullptr && v5->IsPlayer(this: v5) )
  {
    v7 = (const edict_t **)__RTDynamicCast(
                             inptr: v6,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CCSPlayer `RTTI Type Descriptor',
                             isReference: 0);
    if ( v7 != nullptr )
    {
      v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "flashbang_detonate", a3: 0, a4: 0);
      if ( v8 != nullptr )
      {
        v9 = engine->GetPlayerUserId(this: engine, a2: v7[6]);
        v8->SetInt(this: v8, a2: "userid", a3: v9);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, (int)a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "x",
          a3: LODWORD(this->m_vecAbsOrigin.x));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, (int)a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "y",
          a3: LODWORD(this->m_vecAbsOrigin.y));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, (int)a2);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v8->SetFloat)(
          a1: v8,
          a2: "z",
          a3: LODWORD(this->m_vecAbsOrigin.z));
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
      }
    }
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1029B290
// Name: public: CFlashbangProjectile::CFlashbangProjectile(void)
// Source: json
//------------------------------------------------------------------------------
CFlashbangProjectile *__thiscall CFlashbangProjectile::CFlashbangProjectile(CFlashbangProjectile *this)
{
  edict_t *m_pPev; // ecx

  CBaseGrenade::CBaseGrenade(this);
  this->CBaseCSGrenadeProjectile::CBaseGrenade::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CFlashbangProjectile_vtbl *)&CFlashbangProjectile::`vftable'{for `CBaseAnimating'};
  this->CBaseCSGrenadeProjectile::CBaseGrenade::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CFlashbangProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  if ( this->m_flDamage.m_Value != 100.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A4u);
    }
    this->m_flDamage.m_Value = 100.0;
  }
  this->m_flTimeToDetonate = 1.5;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1029B340
// Name: public: virtual void CFlashbangProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlashbangProjectile::Spawn(CFlashbangProjectile *this)
{
  edict_t *m_pPev; // ecx

  this->SetModel(this, a2: "models/Weapons/w_eq_flashbang_thrown.mdl");
  CBaseCSGrenadeProjectile::SetDetonateTimerLength(this, timer: this->m_flTimeToDetonate);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseGrenade::BounceTouch;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CBaseCSGrenadeProjectile::DangerSoundThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->m_flGravity = 0.40000001;
  CBaseEntity::SetFriction(this, flFriction: 0.2);
  if ( this->m_flElasticity.m_Value != 0.44999999 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1B8u);
    }
    this->m_flElasticity.m_Value = 0.44999999;
  }
  this->m_pWeaponInfo = GetWeaponInfo(weaponID: WEAPON_FLASHBANG);
  CBaseCSGrenadeProjectile::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040F620
// Name: _dynamic_initializer_for__flashbang_projectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__flashbang_projectile__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CFlashbangProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &flashbang_projectile,
           a3: "flashbang_projectile");
}

//------------------------------------------------------------------------------
// Address: 0x1040F640
// Name: flashbang_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int flashbang_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  flashbang_projectilePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&flashbang_projectilePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F660
// Name: CFlashbangProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFlashbangProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFlashbangProjectile>();
  CFlashbangProjectile_DataDescInit::g_DataMapHolder = result;
  return result;
}
