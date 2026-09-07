// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_gamemovement.cpp
// Functions: 26
// ============================================================

#include "game\shared\cstrike15\cs_gamemovement.h"

//------------------------------------------------------------------------------
// Address: 0x101C3F80
// Name: public: virtual unsigned int CCSGameMovement::LadderMask(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSGameMovement::LadderMask(C_BaseEntity *this)
{
  return 33570827;
}

//------------------------------------------------------------------------------
// Address: 0x101C3FC0
// Name: protected: virtual unsigned int CCSGameMovement::PlayerSolidMask(bool,class C_BasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSGameMovement::PlayerSolidMask(
        CCSGameMovement *this,
        bool brushOnly,
        C_BasePlayer *testPlayer)
{
  C_BasePlayer *player; // ecx
  bool v5; // bl
  unsigned int result; // eax

  player = this->player;
  v5 = player == nullptr || C_BasePlayer::IsBot(this: player);
  result = 81931;
  if ( !brushOnly )
    result = this->player->PhysicsSolidMaskForEntity(this: this->player);
  if ( v5 )
    result |= 0x20000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C4010
// Name: public: virtual void CCSGameMovement::ProcessMovement(class C_BasePlayer __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::ProcessMovement(CCSGameMovement *this, C_CSPlayer *pBasePlayer, CMoveData *pMove)
{
  C_CSPlayer *v4; // eax

  if ( pBasePlayer != nullptr && pBasePlayer->IsPlayer(this: pBasePlayer) )
    v4 = pBasePlayer;
  else
    v4 = nullptr;
  this->m_pCSPlayer = v4;
  CGameMovement::ProcessMovement(this, pPlayer: pBasePlayer, pMove);
}

//------------------------------------------------------------------------------
// Address: 0x101C4050
// Name: public: virtual bool CCSGameMovement::OnLadder(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::OnLadder(CCSGameMovement *this, CGameTrace *trace)
{
  return trace->plane.normal.z != 1.0 && CGameMovement::OnLadder(this, trace);
}

//------------------------------------------------------------------------------
// Address: 0x101C4080
// Name: public: virtual float CCSGameMovement::ClimbSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::ClimbSpeed(CCSGameMovement *this)
{
  if ( (this->mv->m_nButtons & 4) != 0 )
    return 0.34 * 200.0;
  else
    return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C40A0
// Name: public: virtual float CCSGameMovement::LadderLateralMultiplier(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::LadderLateralMultiplier(CCSGameMovement *this)
{
  if ( (this->mv->m_nButtons & 4) != 0 )
    return 1.0;
  else
    return 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x101C40C0
// Name: public: virtual void CCSGameMovement::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::OnJump(CCSGameMovement *this, float fImpulse)
{
  C_CSPlayer::OnJump(this: this->m_pCSPlayer, fImpulse);
}

//------------------------------------------------------------------------------
// Address: 0x101C40E0
// Name: public: virtual void CCSGameMovement::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::OnLand(CCSGameMovement *this, float fVelocity)
{
  C_CSPlayer::OnLand(this: this->m_pCSPlayer, fVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x101C4100
// Name: public: virtual float CCSGameMovement::LadderDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::LadderDistance(CCSGameMovement *this)
{
  if ( this->player->m_MoveType == 9 )
    return 10.0;
  else
    return 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C4120
// Name: public: virtual void CCSGameMovement::CheckParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::CheckParameters(CCSGameMovement *this)
{
  CMoveData *mv; // edx
  CMoveData *v3; // ecx
  C_BasePlayer *player; // ecx
  unsigned __int8 m_MoveType; // al
  CMoveData *v6; // eax
  surfacedata_t *m_pSurfaceData; // ecx
  long double v8; // st7
  float v9; // xmm0_4
  C_CSPlayer *m_pCSPlayer; // eax
  CMoveData *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  CMoveData *v14; // ecx
  C_BasePlayer *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  CMoveData *v18; // edi
  CMoveData *v19; // eax
  CMoveData *v20; // eax
  C_BasePlayer_vtbl *v21; // edi
  const CViewVectors *v22; // eax
  CMoveData *v23; // edi
  C_BasePlayer *v24; // ecx
  int v25; // ebx
  C_BaseEntity *GroundEntity; // edi
  bool v27; // zf
  QAngle v_angle; // [esp+10h] [ebp-18h] BYREF
  float flConstraintSpeedFactor; // [esp+1Ch] [ebp-Ch]
  float spd; // [esp+20h] [ebp-8h]
  float flSpeedFactor; // [esp+24h] [ebp-4h]

  if ( this->m_pCSPlayer->m_duckUntilOnGround && C_BaseEntity::GetGroundEntity(this: this->player) == nullptr )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0 )
      this->m_pCSPlayer->m_duckUntilOnGround = false;
    else
      mv->m_nButtons |= 4u;
  }
  v3 = this->mv;
  if ( (v3->m_nButtons & 0x20000) != 0 )
    v3->m_flMaxSpeed = v3->m_flMaxSpeed * 0.51999998;
  player = this->player;
  m_MoveType = player->m_MoveType;
  if ( m_MoveType != 1 && m_MoveType != 8 && m_MoveType != 10 )
  {
    v6 = this->mv;
    m_pSurfaceData = player->m_pSurfaceData;
    spd = (float)((float)(v6->m_flForwardMove * v6->m_flForwardMove) + (float)(v6->m_flSideMove * v6->m_flSideMove))
        + (float)(v6->m_flUpMove * v6->m_flUpMove);
    flSpeedFactor = 1.0;
    if ( m_pSurfaceData != nullptr )
      flSpeedFactor = m_pSurfaceData->game.maxSpeedFactor;
    v8 = CGameMovement::ComputeConstraintSpeedFactor(this);
    flConstraintSpeedFactor = v8;
    if ( flSpeedFactor <= v8 )
      v9 = flSpeedFactor;
    else
      v9 = flConstraintSpeedFactor;
    m_pCSPlayer = this->m_pCSPlayer;
    if ( (m_pCSPlayer->m_fFlags & 1) != 0 )
      v9 = m_pCSPlayer->m_flVelocityModifier.m_Value * v9;
    this->mv->m_flMaxSpeed = this->mv->m_flMaxSpeed * v9;
    if ( g_bMovementOptimizations )
    {
      if ( spd != 0.0 && spd > (float)(this->mv->m_flMaxSpeed * this->mv->m_flMaxSpeed) )
      {
        v11 = this->mv;
        v12 = fsqrt(spd);
LABEL_24:
        v13 = v11->m_flMaxSpeed / v12;
        v11->m_flForwardMove = v11->m_flForwardMove * v13;
        this->mv->m_flSideMove = this->mv->m_flSideMove * v13;
        this->mv->m_flUpMove = this->mv->m_flUpMove * v13;
      }
    }
    else
    {
      v12 = fsqrt(spd);
      if ( v12 != 0.0 )
      {
        v11 = this->mv;
        if ( v12 > v11->m_flMaxSpeed )
          goto LABEL_24;
      }
    }
  }
  if ( (this->player->m_fFlags & 0x50) != 0 || CGameMovement::IsDead(this) )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
  }
  this->DecayPunchAngle(this);
  if ( CGameMovement::IsDead(this) )
  {
    v20 = this->mv;
    v20->m_vecAngles.x = v20->m_vecOldAngles.x;
    v20->m_vecAngles.y = v20->m_vecOldAngles.y;
    v20->m_vecAngles.z = v20->m_vecOldAngles.z;
  }
  else
  {
    v14 = this->mv;
    v15 = this->player;
    v_angle = v14->m_vecAngles;
    v16 = v15->m_Local.m_vecPunchAngle.m_Value.y + v_angle.y;
    v17 = v15->m_Local.m_vecPunchAngle.m_Value.z + v_angle.z;
    v_angle.x = v15->m_Local.m_vecPunchAngle.m_Value.x + v_angle.x;
    v_angle.y = v16;
    v_angle.z = v17;
    if ( v15->m_MoveType == 1 || v15->m_MoveType == 8 )
    {
      v14->m_vecAngles.z = 0.0;
    }
    else
    {
      v18 = this->mv;
      v18->m_vecAngles.z = ((double (__thiscall *)(CCSGameMovement *, QAngle *, Vector *, _DWORD, _DWORD))this->CalcRoll)(
                             a1: this,
                             a2: &v_angle,
                             a3: &v18->m_vecVelocity,
                             a4: LODWORD(sv_rollangle.m_pParent->m_Value.m_fValue),
                             a5: LODWORD(sv_rollspeed.m_pParent->m_Value.m_fValue));
    }
    v19 = this->mv;
    v19->m_vecAngles.x = v_angle.x;
    v19->m_vecAngles.y = v_angle.y;
  }
  if ( CGameMovement::IsDead(this) )
  {
    v21 = this->player->CGameMovement::__vftable;
    v22 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v21->SetViewOffset(this: this->player, a2: &v22->m_vDeadViewHeight);
  }
  v23 = this->mv;
  v23->m_vecAngles.y = AngleNormalize(angle: v23->m_vecAngles.y);
  if ( this->player->GetObserverMode(this: this->player) == 0 )
  {
    v24 = this->player;
    if ( v24->m_MoveType != 9 )
    {
      v25 = 0;
      GroundEntity = C_BaseEntity::GetGroundEntity(this: v24);
      if ( GroundEntity != nullptr )
      {
        do
        {
          if ( !GroundEntity->IsPlayer(this: GroundEntity) )
            break;
          v27 = v25 == 1000;
          if ( v25 >= 1000 )
            goto LABEL_44;
          GroundEntity = C_BaseEntity::GetGroundEntity(this: GroundEntity);
          ++v25;
        }
        while ( GroundEntity != nullptr );
        v27 = v25 == 1000;
LABEL_44:
        if ( v27 )
        {
          _Warning(a1: "BUG: CCSGameMovement::CheckParameters - too many stacking levels.\n");
        }
        else if ( v25 <= 1 )
        {
          return;
        }
        this->mv->m_flForwardMove = this->mv->m_flMaxSpeed * 3.0;
        this->mv->m_flSideMove = 0.0;
        this->mv->m_nButtons = 0;
        this->mv->m_nImpulseCommand = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C44E0
// Name: public: virtual bool CCSGameMovement::CanAccelerate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::CanAccelerate(CCSGameMovement *this)
{
  CSPlayerState v2; // eax
  C_BasePlayer *player; // ecx

  v2 = C_CSPlayer::State_Get(this: this->m_pCSPlayer);
  player = this->player;
  if ( v2 != STATE_ACTIVE )
    return player->GetObserverMode(this: player) != 0;
  else
    return C_BasePlayer::GetWaterJumpTime(this: player) == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C4530
// Name: public: virtual bool CCSGameMovement::LadderMove(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameMovement::LadderMove(CCSGameMovement *this)
{
  char v2; // bl

  v2 = CGameMovement::LadderMove(this);
  if ( v2 != 0 && this->m_pCSPlayer != nullptr )
    C_CSPlayer::SurpressLadderChecks(
      this: this->m_pCSPlayer,
      pos: &this->mv->m_vecAbsOrigin,
      normal: &this->m_pCSPlayer->m_vecLadderNormal.m_Value);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101C4570
// Name: public: virtual void CCSGameMovement::PreventBunnyJumping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::PreventBunnyJumping(CCSGameMovement *this)
{
  float v1; // xmm0_4
  CMoveData *mv; // eax
  float v3; // xmm1_4
  float v4; // xmm0_4

  v1 = this->player->m_flMaxspeed * 1.1;
  if ( v1 > 0.0 )
  {
    mv = this->mv;
    v3 = fsqrt(
           (float)((float)(mv->m_vecVelocity.x * mv->m_vecVelocity.x)
                 + (float)(mv->m_vecVelocity.y * mv->m_vecVelocity.y))
         + (float)(mv->m_vecVelocity.z * mv->m_vecVelocity.z));
    if ( v1 < v3 )
    {
      v4 = v1 / v3;
      mv->m_vecVelocity.x = mv->m_vecVelocity.x * v4;
      mv->m_vecVelocity.y = mv->m_vecVelocity.y * v4;
      mv->m_vecVelocity.z = mv->m_vecVelocity.z * v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C4620
// Name: public: virtual void CCSGameMovement::HandleDuckingSpeedCrop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::HandleDuckingSpeedCrop(CCSGameMovement *this)
{
  CMoveData *mv; // eax
  C_BasePlayer *player; // ecx

  if ( this->player->GetObserverMode(this: this->player) != 6 && (this->m_iSpeedCropped & 1) == 0 )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0 || (player = this->player)->m_Local.m_bDucking || (player->m_fFlags & 2) != 0 )
    {
      mv->m_flForwardMove = mv->m_flForwardMove * 0.34;
      this->mv->m_flSideMove = this->mv->m_flSideMove * 0.34;
      this->mv->m_flUpMove = this->mv->m_flUpMove * 0.34;
      this->m_iSpeedCropped |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C46B0
// Name: public: virtual void CCSGameMovement::FinishDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::FinishDuck(CCSGameMovement *this)
{
  const CViewVectors *v2; // edi
  const CViewVectors *v3; // eax
  const CViewVectors *v4; // edi
  const CViewVectors *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  C_BasePlayer_vtbl *v9; // edi
  const Vector *v10; // eax
  C_BasePlayer *player; // ecx
  CMoveData *mv; // eax
  const CViewVectors *v13; // edi
  const CViewVectors *v14; // eax
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  CMoveData *v18; // eax
  float viewDelta; // [esp+8h] [ebp-18h]
  float viewDelta_4; // [esp+Ch] [ebp-14h]
  float viewDelta_8; // [esp+10h] [ebp-10h]
  float orga; // [esp+14h] [ebp-Ch]
  __int64 org; // [esp+14h] [ebp-Ch]
  float org_4; // [esp+18h] [ebp-8h]
  float org_8a; // [esp+1Ch] [ebp-4h]
  float org_8; // [esp+1Ch] [ebp-4h]

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  orga = v3->m_vHullMax.x - v2->m_vHullMin.x;
  org_4 = v3->m_vHullMax.y - v2->m_vHullMin.y;
  org_8a = v3->m_vHullMax.z - v2->m_vHullMin.z;
  v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v6 = v5->m_vDuckHullMax.x - v4->m_vDuckHullMin.x;
  v7 = v5->m_vDuckHullMax.y - v4->m_vDuckHullMin.y;
  v8 = v5->m_vDuckHullMax.z - v4->m_vDuckHullMin.z;
  v9 = this->player->CGameMovement::__vftable;
  viewDelta = (float)(orga - v6) * 0.5;
  viewDelta_4 = (float)(org_4 - v7) * 0.5;
  viewDelta_8 = (float)(org_8a - v8) * 0.5;
  v10 = this->GetPlayerViewOffset(this, a2: 1);
  v9->SetViewOffset(this: this->player, a2: v10);
  C_BaseEntity::AddFlag(this: this->player, flags: 2);
  this->player->m_Local.m_bDucking = false;
  player = this->player;
  if ( !player->m_Local.m_bDucked )
  {
    mv = this->mv;
    org = *(_QWORD *)&mv->m_vecAbsOrigin.x;
    org_8 = mv->m_vecAbsOrigin.z;
    if ( C_BaseEntity::GetGroundEntity(this: player) != nullptr )
    {
      v13 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v15 = *(float *)&org - (float)(v14->m_vDuckHullMin.x - v13->m_vHullMin.x);
      v16 = *((float *)&org + 1) - (float)(v14->m_vDuckHullMin.y - v13->m_vHullMin.y);
      v17 = org_8 - (float)(v14->m_vDuckHullMin.z - v13->m_vHullMin.z);
    }
    else
    {
      v15 = viewDelta + *(float *)&org;
      v16 = *((float *)&org + 1) + viewDelta_4;
      v17 = org_8 + viewDelta_8;
    }
    v18 = this->mv;
    v18->m_vecAbsOrigin.x = v15;
    v18->m_vecAbsOrigin.y = v16;
    v18->m_vecAbsOrigin.z = v17;
    this->player->m_Local.m_bDucked = true;
  }
  this->FixPlayerCrouchStuck(this, a2: true);
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C48A0
// Name: public: virtual bool CCSGameMovement::CanUnduck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::CanUnduck(CCSGameMovement *this)
{
  CMoveData *mv; // eax
  C_BasePlayer *player; // ecx
  bool v4; // zf
  int (*GetViewVectors)(void); // edx
  float *v6; // esi
  const CViewVectors *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float *v11; // esi
  const CViewVectors *v12; // eax
  const CViewVectors *(__thiscall *v13)(C_GameRules *); // edx
  float *v14; // esi
  const CViewVectors *v15; // eax
  CMoveData *v16; // esi
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, C_BasePlayer *); // eax
  const CViewVectors *v18; // eax
  Vector *p_m_vHullMax; // [esp-14h] [ebp-88h]
  unsigned int v21; // [esp-10h] [ebp-84h]
  C_BasePlayer *v22; // [esp-Ch] [ebp-80h]
  CGameTrace trace; // [esp+8h] [ebp-6Ch] BYREF
  Vector hullSizeNormal; // [esp+5Ch] [ebp-18h]
  Vector newOrigin; // [esp+68h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  v4 = C_BaseEntity::GetGroundEntity(this: player) == nullptr;
  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( v4 )
  {
    v11 = (float *)GetViewVectors();
    v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal.x = v12->m_vHullMax.x - v11[3];
    hullSizeNormal.y = v12->m_vHullMax.y - v11[4];
    v13 = g_pGameRules->GetViewVectors;
    hullSizeNormal.z = v12->m_vHullMax.z - v11[5];
    v14 = (float *)v13(this: g_pGameRules);
    v15 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v8 = (float)(hullSizeNormal.x - (float)(v15->m_vDuckHullMax.x - v14[9])) * -0.5;
    v9 = (float)(hullSizeNormal.y - (float)(v15->m_vDuckHullMax.y - v14[10])) * -0.5;
    v10 = (float)(hullSizeNormal.z - (float)(v15->m_vDuckHullMax.z - v14[11])) * -0.5;
  }
  else
  {
    v6 = (float *)GetViewVectors();
    v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v8 = v7->m_vDuckHullMin.x - v6[3];
    v9 = v7->m_vDuckHullMin.y - v6[4];
    v10 = v7->m_vDuckHullMin.z - v6[5];
  }
  v16 = this->mv;
  PlayerSolidMask = this->PlayerSolidMask;
  v22 = this->player;
  newOrigin.z = v10 + newOrigin.z;
  newOrigin.y = v9 + newOrigin.y;
  newOrigin.x = v8 + newOrigin.x;
  v21 = PlayerSolidMask(this, a2: false, a3: nullptr);
  p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
  v18 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)&v16->m_vecAbsOrigin,
    vecAbsStart: &v16->m_vecAbsOrigin,
    vecAbsEnd: &newOrigin,
    hullMin: &v18->m_vHullMin,
    hullMax: p_m_vHullMax,
    mask: v21,
    ignore: v22,
    collisionGroup: 8,
    ptr: &trace);
  return !trace.startsolid && trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101C4A70
// Name: public: virtual void CCSGameMovement::FinishUnDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameMovement::FinishUnDuck(CCSGameMovement *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // edx
  float *v5; // edi
  const CViewVectors *v6; // eax
  float v7; // xmm1_4
  float *v8; // edi
  const CViewVectors *v9; // eax
  const CViewVectors *v10; // edi
  const CViewVectors *v11; // eax
  C_BasePlayer_vtbl *v12; // edi
  const Vector *v13; // eax
  CMoveData *mv; // eax
  CCSGameMovement_vtbl *v15; // edx
  float hullSizeNormal; // [esp+4h] [ebp-18h]
  float hullSizeNormal_4; // [esp+8h] [ebp-14h]
  float hullSizeNormal_8; // [esp+Ch] [ebp-10h]
  float newOrigina; // [esp+10h] [ebp-Ch]
  float newOrigin_8a; // [esp+18h] [ebp-4h]
  Vector newOrigin; // 0:^18.12

  newOrigin = this->mv->m_vecAbsOrigin;
  v3 = C_BaseEntity::GetGroundEntity(this: this->player) == nullptr;
  GetViewVectors = g_pGameRules->GetViewVectors;
  if ( v3 )
  {
    v8 = (float *)((int (__stdcall *)(int))GetViewVectors)(a1: a2);
    v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal = v9->m_vHullMax.x - v8[3];
    hullSizeNormal_4 = v9->m_vHullMax.y - v8[4];
    hullSizeNormal_8 = v9->m_vHullMax.z - v8[5];
    v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v7 = (float)(hullSizeNormal_4 - (float)(v11->m_vDuckHullMax.y - v10->m_vDuckHullMin.y)) * -0.5;
    newOrigina = (float)((float)(hullSizeNormal - (float)(v11->m_vDuckHullMax.x - v10->m_vDuckHullMin.x)) * -0.5)
               + newOrigin.x;
    newOrigin_8a = (float)((float)(hullSizeNormal_8 - (float)(v11->m_vDuckHullMax.z - v10->m_vDuckHullMin.z)) * -0.5)
                 + newOrigin.z;
  }
  else
  {
    v5 = (float *)((int (__stdcall *)(int))GetViewVectors)(a1: a2);
    v6 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v7 = v6->m_vDuckHullMin.y - v5[4];
    newOrigina = (float)(v6->m_vDuckHullMin.x - v5[3]) + newOrigin.x;
    newOrigin_8a = newOrigin.z + (float)(v6->m_vDuckHullMin.z - v5[5]);
  }
  this->player->m_Local.m_bDucked = false;
  C_BaseEntity::RemoveFlag(this: this->player, flagsToRemove: 2);
  this->player->m_Local.m_bDucking = false;
  v12 = this->player->CGameMovement::__vftable;
  v13 = this->GetPlayerViewOffset(this, a2: 0);
  v12->SetViewOffset(this: this->player, a2: v13);
  this->player->m_Local.m_nDuckTimeMsecs = 0;
  mv = this->mv;
  v15 = this->__vftable;
  mv->m_vecAbsOrigin.x = newOrigina;
  mv->m_vecAbsOrigin.y = v7 + newOrigin.y;
  mv->m_vecAbsOrigin.z = newOrigin_8a;
  v15->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C4C60
// Name: public: virtual void CCSGameMovement::Duck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::Duck(CCSGameMovement *this)
{
  int m_fFlags; // ecx
  CMoveData *mv; // eax
  CMoveData *v4; // ecx
  int m_nOldButtons; // eax
  int m_nButtons; // ecx
  int v7; // edx
  C_BasePlayer *player; // ecx
  bool v9; // bl
  CMoveData *v10; // eax
  bool v11; // zf
  C_CSPlayer *m_pCSPlayer; // eax
  CMoveData *v13; // eax
  C_GameRules_vtbl *v14; // edx
  float z; // xmm0_4
  const CViewVectors *(__thiscall *GetViewVectors)(C_GameRules *); // eax
  float *v17; // edi
  const CViewVectors *v18; // eax
  C_GameRules_vtbl *v19; // edx
  float v20; // xmm0_4
  const CViewVectors *(__thiscall *v21)(C_GameRules *); // eax
  float *v22; // edi
  const CViewVectors *v23; // eax
  CCSGameMovement_vtbl *v24; // edx
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, C_BasePlayer *); // eax
  const CViewVectors *v29; // eax
  C_BasePlayer *v30; // eax
  C_BasePlayer *v31; // eax
  int v32; // ecx
  bool v33; // bl
  C_BasePlayer *v34; // ecx
  C_BasePlayer *v35; // ecx
  C_BasePlayer *v36; // eax
  C_BasePlayer *v37; // ecx
  Vector *p_m_vHullMax; // [esp-10h] [ebp-94h]
  unsigned int v39; // [esp-Ch] [ebp-90h]
  CGameTrace *v40; // [esp+0h] [ebp-84h]
  float trace_44; // [esp+3Ch] [ebp-48h]
  char trace_55; // [esp+47h] [ebp-3Dh]
  Vector hullSizeNormal; // [esp+64h] [ebp-20h] BYREF
  Vector newOrigin; // [esp+70h] [ebp-14h] BYREF
  int buttonsReleased; // [esp+7Ch] [ebp-8h]
  float duckmilliseconds; // [esp+80h] [ebp-4h]
  IHandleEntity savedregs; // [esp+84h] [ebp+0h] BYREF

  m_fFlags = this->player->m_fFlags;
  if ( (m_fFlags & 1) != 0 )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0 || (mv->m_nOldButtons & 4) == 0 )
    {
      if ( (mv->m_nButtons & 4) != 0
        && (mv->m_nOldButtons & 4) == 0
        && (m_fFlags & 2) != 0
        && this->m_fTimeLastUnducked > (float)(*(float *)(gpGlobals.m_Index + 12)
                                             - sv_timebetweenducks.m_pParent->m_Value.m_fValue) )
      {
        mv->m_nButtons &= ~4u;
      }
    }
    else
    {
      this->m_fTimeLastUnducked = *(float *)(gpGlobals.m_Index + 12);
    }
  }
  v4 = this->mv;
  m_nOldButtons = v4->m_nOldButtons;
  m_nButtons = v4->m_nButtons;
  v7 = m_nOldButtons ^ m_nButtons;
  LODWORD(duckmilliseconds) = (m_nOldButtons ^ m_nButtons) & m_nButtons;
  player = this->player;
  buttonsReleased = v7 & m_nOldButtons;
  v9 = C_BaseEntity::GetGroundEntity(this: player) == nullptr && this->player->m_MoveType != 9;
  v10 = this->mv;
  if ( (v10->m_nButtons & 4) != 0 )
    v10->m_nOldButtons |= 4u;
  else
    v10->m_nOldButtons &= ~4u;
  if ( CGameMovement::IsDead(this) )
  {
    v11 = (this->player->m_fFlags & 2) == 0;
    goto LABEL_19;
  }
  this->HandleDuckingSpeedCrop(this);
  m_pCSPlayer = this->m_pCSPlayer;
  if ( m_pCSPlayer->m_duckUntilOnGround )
  {
    if ( !v9 )
    {
LABEL_23:
      m_pCSPlayer->m_duckUntilOnGround = false;
      v11 = !this->CanUnduck(this);
LABEL_19:
      if ( !v11 )
        this->FinishUnDuck(this);
      return;
    }
    v13 = this->mv;
    if ( v13->m_vecVelocity.z <= 0.0 )
    {
      v14 = g_pGameRules->__vftable;
      newOrigin.x = v13->m_vecAbsOrigin.x;
      newOrigin.y = v13->m_vecAbsOrigin.y;
      z = v13->m_vecAbsOrigin.z;
      GetViewVectors = v14->GetViewVectors;
      newOrigin.z = z;
      v17 = (float *)GetViewVectors(this: g_pGameRules);
      v18 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v19 = g_pGameRules->__vftable;
      hullSizeNormal.x = v18->m_vHullMax.x - v17[3];
      hullSizeNormal.y = v18->m_vHullMax.y - v17[4];
      v20 = v18->m_vHullMax.z - v17[5];
      v21 = v19->GetViewVectors;
      hullSizeNormal.z = v20;
      v22 = (float *)v21(this: g_pGameRules);
      v23 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v24 = this->__vftable;
      v25 = newOrigin.x - (float)(hullSizeNormal.x - (float)(v23->m_vDuckHullMax.x - v22[9]));
      v26 = newOrigin.y - (float)(hullSizeNormal.y - (float)(v23->m_vDuckHullMax.y - v22[10]));
      v40 = (CGameTrace *)this->player;
      newOrigin.z = newOrigin.z - (float)(v20 - (float)(v23->m_vDuckHullMax.z - v22[11]));
      v27 = newOrigin.z - v40[58].plane.normal.x;
      PlayerSolidMask = v24->PlayerSolidMask;
      newOrigin.x = v25;
      newOrigin.y = v26;
      hullSizeNormal.x = v25;
      hullSizeNormal.y = v26;
      hullSizeNormal.z = v27;
      v39 = ((int (__thiscall *)(CCSGameMovement *))PlayerSolidMask)(a1: this);
      p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v29 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &newOrigin,
        vecAbsEnd: &hullSizeNormal,
        hullMin: &v29->m_vHullMin,
        hullMax: p_m_vHullMax,
        mask: v39,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: v40);
      if ( trace_55 == 0 && trace_44 != 1.0 )
      {
        m_pCSPlayer = this->m_pCSPlayer;
        goto LABEL_23;
      }
    }
  }
  else if ( (this->mv->m_nButtons & 4) != 0 || (v30 = this->player)->m_Local.m_bDucking || (v30->m_fFlags & 2) != 0 )
  {
    if ( (this->mv->m_nButtons & 4) != 0 )
    {
      v31 = this->player;
      v32 = v31->m_fFlags;
      v33 = (v32 & 2) != 0;
      if ( (LOBYTE(duckmilliseconds) & 4) != 0 && (v32 & 2) == 0 )
      {
        v31->m_Local.m_nDuckTimeMsecs = 1000;
        this->player->m_Local.m_bDucking = true;
      }
      v34 = this->player;
      if ( (float)(1000.0 - (float)v34->m_Local.m_nDuckTimeMsecs) >= 0.0 )
        duckmilliseconds = 1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs;
      else
        duckmilliseconds = 0.0;
      if ( v34->m_Local.m_bDucking )
      {
        if ( (v34->m_fFlags & 4) == 0 )
          C_BaseEntity::AddFlag(this: v34, flags: 4);
        if ( duckmilliseconds > 400.0 || C_BaseEntity::GetGroundEntity(this: this->player) == nullptr || v33 )
          this->FinishDuck(this);
        else
          ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)((float)(duckmilliseconds * 0.0024999999) * (float)(duckmilliseconds * 0.0024999999)) * 3.0)
          - (float)((float)((float)((float)(duckmilliseconds * 0.0024999999) * (float)(duckmilliseconds * 0.0024999999))
                          * 2.0)
                  * (float)(duckmilliseconds * 0.0024999999)));
      }
    }
    else
    {
      v35 = this->player;
      if ( v35->m_Local.m_bAllowAutoMovement || C_BaseEntity::GetGroundEntity(this: v35) == nullptr )
      {
        if ( (buttonsReleased & 4) != 0 )
        {
          v36 = this->player;
          if ( (v36->m_fFlags & 2) != 0 )
          {
            v36->m_Local.m_nDuckTimeMsecs = 1000;
            this->player->m_Local.m_bDucking = true;
          }
        }
        if ( (float)(1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs) >= 0.0 )
          duckmilliseconds = 1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs;
        else
          duckmilliseconds = 0.0;
        if ( this->CanUnduck(this) )
        {
          v37 = this->player;
          if ( v37->m_Local.m_bDucking || v37->m_Local.m_bDucked )
          {
            if ( (v37->m_fFlags & 4) != 0 )
              C_BaseEntity::RemoveFlag(this: v37, flagsToRemove: 4);
            if ( duckmilliseconds <= 200.0 && C_BaseEntity::GetGroundEntity(this: this->player) != nullptr )
              ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
                a1: this,
                a2: (float)((float)((float)(1.0 - (float)(duckmilliseconds * 0.0024999999))
                              * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999)))
                      * 3.0)
              - (float)((float)((float)((float)(1.0 - (float)(duckmilliseconds * 0.0024999999))
                                      * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999)))
                              * 2.0)
                      * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999))));
            else
              this->FinishUnDuck(this);
          }
        }
        else
        {
          this->player->m_Local.m_nDuckTimeMsecs = 1000;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5180
// Name: public: virtual void CCSGameMovement::DecayPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::DecayPunchAngle(CCSGameMovement *this)
{
  double v2; // xmm0_8
  float v3; // xmm1_4
  float y; // xmm2_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // esi
  float x; // xmm0_4
  C_CSPlayer *m_pCSPlayer; // esi
  float v8; // xmm0_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v9; // esi
  C_CSPlayer *v10; // esi
  float z; // xmm1_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v12; // esi
  C_CSPlayer *v13; // esi
  __int64 v14; // xmm0_8
  float v15; // ecx
  float *p_x; // esi
  __m128 m_fValue_low; // xmm0
  double v18; // xmm0_8
  bool v19; // zf
  float v20; // xmm2_4
  float v21; // xmm3_4
  QAngle punchAngle; // [esp+8h] [ebp-10h] BYREF
  float len; // [esp+14h] [ebp-4h]

  if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
  {
    punchAngle = (QAngle)this->m_pCSPlayer->m_Local.m_vecPunchAngle;
    len = VectorNormalize(vec: (Vector *)&punchAngle);
    if ( (float)(len - (float)((float)((float)(len * 0.5) + 10.0) * *(float *)(gpGlobals.m_Index + 16))) <= 0.0 )
      v2 = 0.0;
    else
      v2 = len;
    v3 = v2;
    y = v3 * punchAngle.y;
    p_m_vecPunchAngle = &this->m_pCSPlayer->m_Local.m_vecPunchAngle;
    punchAngle.x = v3 * punchAngle.x;
    punchAngle.y = v3 * punchAngle.y;
    punchAngle.z = v3 * punchAngle.z;
    x = p_m_vecPunchAngle->m_Value.x;
    len = punchAngle.x;
    if ( x != punchAngle.x )
    {
      (*(void (__thiscall **)(float *, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))(LODWORD(p_m_vecPunchAngle[-9].m_Value.z) + 4))(
        a1: &p_m_vecPunchAngle[-9].m_Value.z,
        a2: p_m_vecPunchAngle);
      p_m_vecPunchAngle->m_Value.x = len;
      y = punchAngle.y;
    }
    m_pCSPlayer = this->m_pCSPlayer;
    v8 = m_pCSPlayer->m_Local.m_vecPunchAngle.m_Value.y;
    v9 = &m_pCSPlayer->m_Local.m_vecPunchAngle;
    len = y;
    if ( v8 != y )
    {
      (*(void (__thiscall **)(float *, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))(LODWORD(v9[-9].m_Value.z) + 4))(
        a1: &v9[-9].m_Value.z,
        a2: v9);
      v9->m_Value.y = len;
    }
    v10 = this->m_pCSPlayer;
    z = v10->m_Local.m_vecPunchAngle.m_Value.z;
    v12 = &v10->m_Local.m_vecPunchAngle;
    len = punchAngle.z;
    if ( z != punchAngle.z )
    {
      (*(void (__thiscall **)(float *, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))(LODWORD(v12[-9].m_Value.z) + 4))(
        a1: &v12[-9].m_Value.z,
        a2: v12);
      v12->m_Value.z = len;
    }
  }
  else
  {
    v13 = this->m_pCSPlayer;
    v14 = *(_QWORD *)&v13->m_Local.m_vecPunchAngle.m_Value.x;
    v15 = v13->m_Local.m_vecPunchAngle.m_Value.z;
    p_x = &v13->m_Local.m_vecPunchAngle.m_Value.x;
    *(_QWORD *)&punchAngle.x = v14;
    m_fValue_low = (__m128)LODWORD(weapon_recoil_decay.m_pParent->m_Value.m_fValue);
    m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * *(float *)(gpGlobals.m_Index + 28);
    punchAngle.z = v15;
    __libm_sse2_exp(a1: _mm_cvtps_pd(_mm_xor_ps(m_fValue_low, (__m128)_mask__NegFloat_)));
    *(float *)&v18 = v18;
    v19 = (float)(punchAngle.x * *(float *)&v18) == *p_x;
    v20 = punchAngle.y * *(float *)&v18;
    v21 = punchAngle.z * *(float *)&v18;
    punchAngle.x = punchAngle.x * *(float *)&v18;
    punchAngle.y = punchAngle.y * *(float *)&v18;
    punchAngle.z = punchAngle.z * *(float *)&v18;
    if ( !v19 || v20 != p_x[1] || v21 != p_x[2] )
    {
      (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_x - 25) + 4))(a1: p_x - 25, a2: p_x);
      *(QAngle *)p_x = punchAngle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C53C0
// Name: public: void C_BasePlayer::SetLadderNormal(class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePlayer::SetLadderNormal(
        C_BasePlayer *this,
        CNetworkVectorBase<Vector,C_BasePlayer::NetworkVar_m_vecLadderNormal> vecLadderNormal)
{
  if ( vecLadderNormal.m_Value.x != this->m_vecLadderNormal.m_Value.x
    || vecLadderNormal.m_Value.y != this->m_vecLadderNormal.m_Value.y
    || vecLadderNormal.m_Value.z != this->m_vecLadderNormal.m_Value.z )
  {
    this->m_vecLadderNormal = vecLadderNormal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C5420
// Name: protected: virtual void CCSGameMovement::PlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameMovement::PlayerMove(CCSGameMovement *this@<ecx>, float a2@<ebp>)
{
  C_CSPlayer *m_pCSPlayer; // esi
  float m_Value; // xmm1_4
  float v5; // xmm0_4

  if ( !C_CSPlayer::CanMove(this: this->m_pCSPlayer) )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
    this->mv->m_nButtons &= 0xFFFFF9E5;
  }
  CGameMovement::PlayerMove(this, a2);
  m_pCSPlayer = this->m_pCSPlayer;
  if ( (m_pCSPlayer->m_fFlags & 1) != 0 )
  {
    m_Value = m_pCSPlayer->m_flVelocityModifier.m_Value;
    if ( m_Value < 1.0 )
    {
      v5 = (float)(*(float *)(gpGlobals.m_Index + 16) * 0.33333334) + m_Value;
      if ( v5 >= 0.0 )
      {
        if ( v5 > 1.0 )
          v5 = 1.0;
      }
      else
      {
        v5 = 0.0;
      }
      if ( m_pCSPlayer->m_flVelocityModifier.m_Value != v5 )
        m_pCSPlayer->m_flVelocityModifier.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C54D0
// Name: protected: void CCSGameMovement::CheckForLadders(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::CheckForLadders(CCSGameMovement *this, bool wasOnGround)
{
  CMoveData *mv; // eax
  C_CSPlayer *m_pCSPlayer; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  double v8; // st7
  C_CSPlayer *v9; // eax
  CCSGameMovement_vtbl *v10; // ebx
  CMoveData *v11; // edi
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, C_BasePlayer *); // edx
  int v13; // eax
  CMoveData *v14; // ecx
  C_CSPlayer *v15; // eax
  CCSGameMovement_vtbl *v16; // edi
  unsigned int (__thiscall *v17)(struct CCSGameMovement *, bool, C_BasePlayer *); // edx
  Vector *p_m_vecAbsOrigin; // ebx
  int v19; // eax
  CGameTrace trace; // [esp+Ch] [ebp-6Ch] BYREF
  float v21; // [esp+60h] [ebp-18h] BYREF
  float v22; // [esp+64h] [ebp-14h]
  float v23; // [esp+68h] [ebp-10h]
  Vector dir; // [esp+6Ch] [ebp-Ch] BYREF
  float dist; // [esp+80h] [ebp+8h]
  float dista; // [esp+80h] [ebp+8h]

  mv = this->mv;
  if ( wasOnGround )
  {
    this->m_pCSPlayer->m_lastStandingPos = mv->m_vecAbsOrigin;
  }
  else
  {
    m_pCSPlayer = this->m_pCSPlayer;
    if ( mv->m_vecAbsOrigin.z <= m_pCSPlayer->m_lastStandingPos.z )
    {
      v5 = -m_pCSPlayer->m_lastStandingPos.y;
      v6 = -m_pCSPlayer->m_lastStandingPos.z;
      dir.x = mv->m_vecAbsOrigin.x - m_pCSPlayer->m_lastStandingPos.x;
      v7 = mv->m_vecAbsOrigin.y + v5;
      dir.y = v7;
      dir.z = mv->m_vecAbsOrigin.z + v6;
      if ( dir.x != 0.0 || v7 != 0.0 )
      {
        dir.z = 0.0;
        v8 = VectorNormalize(vec: &dir);
        dist = v8;
        if ( v8 <= 64.0 )
        {
          v9 = this->m_pCSPlayer;
          v10 = this->__vftable;
          v11 = this->mv;
          PlayerSolidMask = this->PlayerSolidMask;
          v21 = v9->m_lastStandingPos.x - (float)((float)(dist + 5.0) * dir.x);
          v22 = v9->m_lastStandingPos.y - (float)((float)(dist + 5.0) * dir.y);
          dista = dist + 5.0;
          v23 = v9->m_lastStandingPos.z - (float)(dista * dir.z);
          v13 = ((int (__thiscall *)(CCSGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
                  a1: this,
                  a2: 0,
                  a3: 0,
                  a4: 8,
                  a5: &trace);
          ((void (__thiscall *)(CCSGameMovement *, Vector *, float *, unsigned int))v10->TracePlayerBBox)(
            a1: this,
            a2: &v11->m_vecAbsOrigin,
            a3: &v21,
            a4: v13 & 0xFFFEFFFF);
          if ( trace.fraction != 1.0
            && this->OnLadder(this, a2: &trace)
            && trace.plane.normal.z != 1.0
            && C_CSPlayer::CanGrabLadder(this: this->m_pCSPlayer, pos: &trace.endpos, normal: &trace.plane.normal) )
          {
            C_BaseEntity::SetMoveType(this: this->player, val: MOVETYPE_LADDER, moveCollide: MOVECOLLIDE_DEFAULT);
            C_BaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
            C_BasePlayer::SetLadderNormal(
              this: this->player,
              vecLadderNormal: (CNetworkVectorBase<Vector,C_BasePlayer::NetworkVar_m_vecLadderNormal>)trace.plane.normal);
            v14 = this->mv;
            v15 = this->m_pCSPlayer;
            v16 = this->__vftable;
            v17 = this->PlayerSolidMask;
            v14->m_vecVelocity.x = 0.0;
            v14->m_vecVelocity.y = 0.0;
            v14->m_vecVelocity.z = 0.0;
            v21 = v15->m_lastStandingPos.x - (float)(dista * dir.x);
            v22 = v15->m_lastStandingPos.y - (float)(dista * dir.y);
            p_m_vecAbsOrigin = &v14->m_vecAbsOrigin;
            v23 = v15->m_lastStandingPos.z - (float)(dista * dir.z);
            v19 = ((int (__thiscall *)(CCSGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v17)(
                    a1: this,
                    a2: 0,
                    a3: 0,
                    a4: 8,
                    a5: &trace);
            ((void (__thiscall *)(CCSGameMovement *, Vector *, float *, int))v16->TracePlayerBBox)(
              a1: this,
              a2: p_m_vecAbsOrigin,
              a3: &v21,
              a4: v19);
            CMoveData::SetAbsOrigin(this: this->mv, vec: &trace.endpos);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C57A0
// Name: public: virtual void CCSGameMovement::ReduceTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::ReduceTimers(CCSGameMovement *this)
{
  C_CSPlayer *m_pCSPlayer; // edx
  float m_Value; // xmm0_4
  float v3; // xmm0_4

  m_pCSPlayer = this->m_pCSPlayer;
  m_Value = m_pCSPlayer->m_flStamina.m_Value;
  if ( m_Value > 0.0 )
  {
    v3 = m_Value - (float)(*(float *)(gpGlobals.m_Index + 16) * 1000.0);
    if ( m_pCSPlayer->m_flStamina.m_Value != v3 )
      m_pCSPlayer->m_flStamina.m_Value = v3;
    if ( m_pCSPlayer->m_flStamina.m_Value < 0.0 )
      m_pCSPlayer->m_flStamina.m_Value = 0.0;
  }
  CGameMovement::ReduceTimers(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C5810
// Name: public: virtual bool CCSGameMovement::CheckJumpButton(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CCSGameMovement::CheckJumpButton@<al>(CCSGameMovement *this@<ecx>, int a2@<ebx>)
{
  C_CSPlayer *m_pCSPlayer; // ecx
  C_CSPlayer *v5; // edx
  C_CSPlayer *v6; // eax
  C_BasePlayer *player; // ecx
  surfacedata_t *m_pSurfaceData; // eax
  CMoveData *mv; // ecx
  C_CSPlayer *v10; // eax
  double v11; // xmm0_8
  float v12; // xmm0_4
  float m_Value; // xmm0_4
  C_CSPlayer *v14; // ecx
  float startz; // [esp+20h] [ebp-8h]
  float flGroundFactor; // [esp+24h] [ebp-4h]

  m_pCSPlayer = this->m_pCSPlayer;
  if ( m_pCSPlayer->pl.deadflag.m_Value )
  {
    this->mv->m_nOldButtons |= 2u;
    return 0;
  }
  if ( m_pCSPlayer->m_flWaterJumpTime != 0.0 )
  {
    m_pCSPlayer->m_flWaterJumpTime = m_pCSPlayer->m_flWaterJumpTime - *(float *)(gpGlobals.m_Index + 16);
    v5 = this->m_pCSPlayer;
    if ( v5->m_flWaterJumpTime < 0.0 )
      v5->m_flWaterJumpTime = 0.0;
    return 0;
  }
  if ( m_pCSPlayer->m_nWaterLevel >= 2u )
  {
    this->SetGroundEntity(this, a2: nullptr);
    if ( C_BaseEntity::GetWaterType(this: this->m_pCSPlayer) == 32 )
    {
      this->mv->m_vecVelocity.z = 100.0;
    }
    else if ( C_BaseEntity::GetWaterType(this: this->m_pCSPlayer) == 16 )
    {
      this->mv->m_vecVelocity.z = 80.0;
    }
    v6 = this->m_pCSPlayer;
    if ( v6->m_flSwimSoundTime <= 0.0 )
    {
      v6->m_flSwimSoundTime = 1000.0;
      CGameMovement::PlaySwimSound(this);
    }
    return 0;
  }
  if ( C_BaseEntity::GetGroundEntity(this: m_pCSPlayer) == nullptr )
  {
    this->mv->m_nOldButtons |= 2u;
    return 0;
  }
  if ( (this->mv->m_nOldButtons & 2) != 0 )
    return 0;
  if ( sv_enablebunnyhopping.m_pParent == nullptr || sv_enablebunnyhopping.m_pParent->m_Value.m_nValue == 0 )
    this->PreventBunnyJumping(this);
  ((void (__thiscall *)(CCSGameMovement *, _DWORD, int))this->SetGroundEntity)(a1: this, a2: 0, a3: a2);
  ((void (__stdcall *)(Vector *, surfacedata_t *, int, int))this->m_pCSPlayer->PlayStepSound)(
    a1: &this->mv->m_vecAbsOrigin,
    a2: this->player->m_pSurfaceData,
    a3: 1065353216,
    a4: 1);
  C_CSPlayer::DoAnimationEvent(this: this->m_pCSPlayer, event: PLAYERANIMEVENT_JUMP, nData: 0);
  player = this->player;
  m_pSurfaceData = player->m_pSurfaceData;
  flGroundFactor = 1.0;
  if ( m_pSurfaceData != nullptr )
    flGroundFactor = m_pSurfaceData->game.jumpFactor;
  if ( (player == nullptr || C_BasePlayer::IsBot(this: player)) && (this->mv->m_nButtons & 4) == 0 )
  {
    this->m_pCSPlayer->m_duckUntilOnGround = true;
    this->FinishDuck(this);
  }
  mv = this->mv;
  v10 = this->m_pCSPlayer;
  startz = mv->m_vecVelocity.z;
  if ( v10->m_duckUntilOnGround || v10->m_Local.m_bDucking || (v10->m_fFlags & 2) != 0 )
    v11 = sqrt(91200.0) * flGroundFactor;
  else
    v11 = sqrt(91200.0) * flGroundFactor + mv->m_vecVelocity.z;
  v12 = v11;
  mv->m_vecVelocity.z = v12;
  m_Value = this->m_pCSPlayer->m_flStamina.m_Value;
  if ( m_Value > 0.0 )
    this->mv->m_vecVelocity.z = (float)((100.0 - m_Value * 0.001 * 19.0) * 0.01) * this->mv->m_vecVelocity.z;
  v14 = this->m_pCSPlayer;
  if ( v14->m_flStamina.m_Value != 1315.7894 )
    v14->m_flStamina.m_Value = 1315.7894;
  this->FinishGravity(this);
  this->mv->m_outWishVel.z = (float)(this->mv->m_vecVelocity.z - startz) + this->mv->m_outWishVel.z;
  this->mv->m_outStepHeight = this->mv->m_outStepHeight + 0.1;
  ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->OnJump)(a1: this, a2: LODWORD(this->mv->m_outWishVel.z));
  this->mv->m_nOldButtons |= 2u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C5B40
// Name: public: virtual void CCSGameMovement::WalkMove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameMovement::WalkMove(CCSGameMovement *this@<ecx>, unsigned int a2@<ebp>, int a3@<edi>)
{
  float m_Value; // xmm0_4
  float v5; // xmm0_4
  C_BaseEntity *GroundEntity; // eax

  m_Value = this->m_pCSPlayer->m_flStamina.m_Value;
  if ( m_Value > 0.0 )
  {
    __libm_sse2_pow();
    v5 = (100.0 - m_Value * 0.001 * 19.0) * 0.01;
    this->mv->m_vecVelocity.x = this->mv->m_vecVelocity.x * v5;
    this->mv->m_vecVelocity.y = this->mv->m_vecVelocity.y * v5;
  }
  CGameMovement::WalkMove(this, a2, a3, a4: (int)this);
  GroundEntity = C_BaseEntity::GetGroundEntity(this: this->player);
  CCSGameMovement::CheckForLadders(this, wasOnGround: GroundEntity != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101C5BF0
// Name: public: virtual void CCSGameMovement::AirMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::AirMove(CCSGameMovement *this)
{
  CGameMovement::AirMove(this);
  CCSGameMovement::CheckForLadders(this, wasOnGround: false);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1026AF60
// Name: public: virtual unsigned int CCSGameMovement::LadderMask(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSGameMovement::LadderMask(CBaseEntity *this)
{
  return 33570827;
}

//------------------------------------------------------------------------------
// Address: 0x1026AFA0
// Name: protected: virtual unsigned int CCSGameMovement::PlayerSolidMask(bool,class CBasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCSGameMovement::PlayerSolidMask(
        CCSGameMovement *this,
        bool brushOnly,
        CBasePlayer *testPlayer)
{
  bool v4; // bl
  unsigned int result; // eax

  v4 = this->player == nullptr || this->player->IsBot(this: this->player);
  result = 81931;
  if ( !brushOnly )
    result = this->player->PhysicsSolidMaskForEntity(this: this->player);
  if ( v4 )
    result |= 0x20000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026AFF0
// Name: public: virtual void CCSGameMovement::ProcessMovement(class CBasePlayer __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::ProcessMovement(CCSGameMovement *this, CBasePlayer *pBasePlayer, CMoveData *pMove)
{
  CCSPlayer *v4; // eax

  if ( pBasePlayer != nullptr && pBasePlayer->IsPlayer(this: pBasePlayer) )
    v4 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pBasePlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  else
    v4 = nullptr;
  this->m_pCSPlayer = v4;
  CGameMovement::ProcessMovement(this, pPlayer: pBasePlayer, pMove);
}

//------------------------------------------------------------------------------
// Address: 0x1026B050
// Name: public: virtual bool CCSGameMovement::OnLadder(class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::OnLadder(CCSGameMovement *this, CGameTrace *trace)
{
  return trace->plane.normal.z != 1.0 && CGameMovement::OnLadder(this, trace);
}

//------------------------------------------------------------------------------
// Address: 0x1026B080
// Name: public: virtual float CCSGameMovement::ClimbSpeed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::ClimbSpeed(CCSGameMovement *this)
{
  if ( (this->mv->m_nButtons & 4) != 0 )
    return 0.34 * 200.0;
  else
    return 200.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026B0A0
// Name: public: virtual float CCSGameMovement::LadderLateralMultiplier(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::LadderLateralMultiplier(CCSGameMovement *this)
{
  if ( (this->mv->m_nButtons & 4) != 0 )
    return 1.0;
  else
    return 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x1026B0C0
// Name: public: virtual void CCSGameMovement::OnJump(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::OnJump(CCSGameMovement *this, float fImpulse)
{
  CCSPlayer::OnJump(this: this->m_pCSPlayer, fImpulse);
}

//------------------------------------------------------------------------------
// Address: 0x1026B0E0
// Name: public: virtual void CCSGameMovement::OnLand(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::OnLand(CCSGameMovement *this, float fVelocity)
{
  CCSPlayer::OnLand(this: this->m_pCSPlayer, fVelocity);
}

//------------------------------------------------------------------------------
// Address: 0x1026B100
// Name: public: virtual bool CCSGameMovement::LadderMove(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameMovement::LadderMove(CCSGameMovement *this)
{
  char v2; // bl

  v2 = CGameMovement::LadderMove(this);
  if ( v2 != 0 && this->m_pCSPlayer != nullptr )
    CCSPlayer::SurpressLadderChecks(
      this: this->m_pCSPlayer,
      pos: &this->mv->m_vecAbsOrigin,
      normal: &this->m_pCSPlayer->m_vecLadderNormal.m_Value);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1026B140
// Name: public: virtual void CCSGameMovement::PreventBunnyJumping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::PreventBunnyJumping(CCSGameMovement *this)
{
  float v1; // xmm0_4
  CMoveData *mv; // eax
  float v3; // xmm1_4
  float v4; // xmm0_4

  v1 = this->player->m_flMaxspeed.m_Value * 1.1;
  if ( v1 > 0.0 )
  {
    mv = this->mv;
    v3 = fsqrt(
           (float)((float)(mv->m_vecVelocity.x * mv->m_vecVelocity.x)
                 + (float)(mv->m_vecVelocity.y * mv->m_vecVelocity.y))
         + (float)(mv->m_vecVelocity.z * mv->m_vecVelocity.z));
    if ( v1 < v3 )
    {
      v4 = v1 / v3;
      mv->m_vecVelocity.x = mv->m_vecVelocity.x * v4;
      mv->m_vecVelocity.y = mv->m_vecVelocity.y * v4;
      mv->m_vecVelocity.z = mv->m_vecVelocity.z * v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026B1F0
// Name: public: virtual float CCSGameMovement::LadderDistance(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameMovement::LadderDistance(CCSGameMovement *this)
{
  if ( this->player->m_MoveType.m_Value == 9 )
    return 10.0;
  else
    return 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026B210
// Name: public: virtual void CCSGameMovement::CheckParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::CheckParameters(CCSGameMovement *this)
{
  CMoveData *mv; // edx
  CMoveData *v3; // ecx
  CBasePlayer *player; // ecx
  unsigned __int8 m_Value; // al
  CMoveData *v6; // eax
  surfacedata_t *m_pSurfaceData; // ecx
  long double v8; // st7
  float v9; // xmm0_4
  CCSPlayer *m_pCSPlayer; // eax
  CMoveData *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  CMoveData *v14; // ecx
  CBasePlayer *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  CMoveData *v18; // edi
  CMoveData *v19; // eax
  CMoveData *v20; // eax
  CBasePlayer_vtbl *v21; // edi
  const CViewVectors *v22; // eax
  CMoveData *v23; // edi
  CBasePlayer *v24; // ecx
  int v25; // ebx
  CBaseEntity *GroundEntity; // edi
  bool v27; // zf
  QAngle v_angle; // [esp+10h] [ebp-18h] BYREF
  float flConstraintSpeedFactor; // [esp+1Ch] [ebp-Ch]
  float spd; // [esp+20h] [ebp-8h]
  float flSpeedFactor; // [esp+24h] [ebp-4h]

  if ( this->m_pCSPlayer->m_duckUntilOnGround && CBaseEntity::GetGroundEntity(this: this->player) == nullptr )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0 )
      this->m_pCSPlayer->m_duckUntilOnGround = false;
    else
      mv->m_nButtons |= 4u;
  }
  v3 = this->mv;
  if ( (v3->m_nButtons & 0x20000) != 0 )
    v3->m_flMaxSpeed = v3->m_flMaxSpeed * 0.51999998;
  player = this->player;
  m_Value = player->m_MoveType.m_Value;
  if ( m_Value != 1 && m_Value != 8 && m_Value != 10 )
  {
    v6 = this->mv;
    m_pSurfaceData = player->m_pSurfaceData;
    spd = (float)((float)(v6->m_flForwardMove * v6->m_flForwardMove) + (float)(v6->m_flSideMove * v6->m_flSideMove))
        + (float)(v6->m_flUpMove * v6->m_flUpMove);
    flSpeedFactor = 1.0;
    if ( m_pSurfaceData != nullptr )
      flSpeedFactor = m_pSurfaceData->game.maxSpeedFactor;
    v8 = CGameMovement::ComputeConstraintSpeedFactor(this);
    flConstraintSpeedFactor = v8;
    if ( flSpeedFactor <= v8 )
      v9 = flSpeedFactor;
    else
      v9 = flConstraintSpeedFactor;
    m_pCSPlayer = this->m_pCSPlayer;
    if ( (m_pCSPlayer->m_fFlags.m_Value & 1) != 0 )
      v9 = m_pCSPlayer->m_flVelocityModifier.m_Value * v9;
    this->mv->m_flMaxSpeed = this->mv->m_flMaxSpeed * v9;
    if ( g_bMovementOptimizations )
    {
      if ( spd != 0.0 && spd > (float)(this->mv->m_flMaxSpeed * this->mv->m_flMaxSpeed) )
      {
        v11 = this->mv;
        v12 = fsqrt(spd);
LABEL_24:
        v13 = v11->m_flMaxSpeed / v12;
        v11->m_flForwardMove = v11->m_flForwardMove * v13;
        this->mv->m_flSideMove = this->mv->m_flSideMove * v13;
        this->mv->m_flUpMove = this->mv->m_flUpMove * v13;
      }
    }
    else
    {
      v12 = fsqrt(spd);
      if ( v12 != 0.0 )
      {
        v11 = this->mv;
        if ( v12 > v11->m_flMaxSpeed )
          goto LABEL_24;
      }
    }
  }
  if ( (this->player->m_fFlags.m_Value & 0x50) != 0 || CGameMovement::IsDead(this) )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
  }
  this->DecayPunchAngle(this);
  if ( CGameMovement::IsDead(this) )
  {
    v20 = this->mv;
    v20->m_vecAngles.x = v20->m_vecOldAngles.x;
    v20->m_vecAngles.y = v20->m_vecOldAngles.y;
    v20->m_vecAngles.z = v20->m_vecOldAngles.z;
  }
  else
  {
    v14 = this->mv;
    v15 = this->player;
    v_angle = v14->m_vecAngles;
    v16 = v15->m_Local.m_vecPunchAngle.m_Value.y + v_angle.y;
    v17 = v15->m_Local.m_vecPunchAngle.m_Value.z + v_angle.z;
    v_angle.x = v15->m_Local.m_vecPunchAngle.m_Value.x + v_angle.x;
    v_angle.y = v16;
    v_angle.z = v17;
    if ( v15->m_MoveType.m_Value == 1 || v15->m_MoveType.m_Value == 8 )
    {
      v14->m_vecAngles.z = 0.0;
    }
    else
    {
      v18 = this->mv;
      v18->m_vecAngles.z = ((double (__thiscall *)(CCSGameMovement *, QAngle *, Vector *, _DWORD, _DWORD))this->CalcRoll)(
                             a1: this,
                             a2: &v_angle,
                             a3: &v18->m_vecVelocity,
                             a4: LODWORD(sv_rollangle.m_pParent->m_Value.m_fValue),
                             a5: LODWORD(sv_rollspeed.m_pParent->m_Value.m_fValue));
    }
    v19 = this->mv;
    v19->m_vecAngles.x = v_angle.x;
    v19->m_vecAngles.y = v_angle.y;
  }
  if ( CGameMovement::IsDead(this) )
  {
    v21 = this->player->CGameMovement::__vftable;
    v22 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v21->SetViewOffset(this: this->player, a2: &v22->m_vDeadViewHeight);
  }
  v23 = this->mv;
  v23->m_vecAngles.y = AngleNormalize(angle: v23->m_vecAngles.y);
  v24 = this->player;
  if ( (v24->m_afPhysicsFlags.m_Value & 8) == 0 && v24->m_MoveType.m_Value != 9 )
  {
    v25 = 0;
    GroundEntity = CBaseEntity::GetGroundEntity(this: v24);
    if ( GroundEntity != nullptr )
    {
      do
      {
        if ( !GroundEntity->IsPlayer(this: GroundEntity) )
          break;
        v27 = v25 == 1000;
        if ( v25 >= 1000 )
          goto LABEL_44;
        GroundEntity = CBaseEntity::GetGroundEntity(this: GroundEntity);
        ++v25;
      }
      while ( GroundEntity != nullptr );
      v27 = v25 == 1000;
LABEL_44:
      if ( v27 )
      {
        _Warning(a1: "BUG: CCSGameMovement::CheckParameters - too many stacking levels.\n");
      }
      else if ( v25 <= 1 )
      {
        return;
      }
      this->mv->m_flForwardMove = this->mv->m_flMaxSpeed * 3.0;
      this->mv->m_flSideMove = 0.0;
      this->mv->m_nButtons = 0;
      this->mv->m_nImpulseCommand = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026B5D0
// Name: public: virtual bool CCSGameMovement::CanAccelerate(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::CanAccelerate(CCSGameMovement *this)
{
  CCSPlayer *m_pCSPlayer; // eax
  CBasePlayer *player; // ecx

  m_pCSPlayer = this->m_pCSPlayer;
  player = this->player;
  if ( m_pCSPlayer->m_iPlayerState.m_Value != STATE_ACTIVE )
    return (player->m_afPhysicsFlags.m_Value & 8) != 0;
  else
    return CBasePlayer::GetWaterJumpTime(this: player) == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026B610
// Name: public: virtual void CCSGameMovement::HandleDuckingSpeedCrop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::HandleDuckingSpeedCrop(CCSGameMovement *this)
{
  CMoveData *mv; // eax
  CBasePlayer *player; // ecx

  if ( this->player->GetObserverMode(this: this->player) != 6 && (this->m_iSpeedCropped & 1) == 0 )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0
      || (player = this->player)->m_Local.m_bDucking.m_Value
      || (player->m_fFlags.m_Value & 2) != 0 )
    {
      mv->m_flForwardMove = mv->m_flForwardMove * 0.34;
      this->mv->m_flSideMove = this->mv->m_flSideMove * 0.34;
      this->mv->m_flUpMove = this->mv->m_flUpMove * 0.34;
      this->m_iSpeedCropped |= 1u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026B6A0
// Name: public: virtual bool CCSGameMovement::CanUnduck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameMovement::CanUnduck(CCSGameMovement *this)
{
  CMoveData *mv; // eax
  CBasePlayer *player; // ecx
  bool v4; // zf
  int (*GetViewVectors)(void); // edx
  float *v6; // esi
  const CViewVectors *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float *v11; // esi
  const CViewVectors *v12; // eax
  const CViewVectors *(__thiscall *v13)(CGameRules *); // edx
  float *v14; // esi
  const CViewVectors *v15; // eax
  CMoveData *v16; // esi
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, CBasePlayer *); // eax
  const CViewVectors *v18; // eax
  Vector *p_m_vHullMax; // [esp-14h] [ebp-88h]
  unsigned int v21; // [esp-10h] [ebp-84h]
  CBasePlayer *v22; // [esp-Ch] [ebp-80h]
  CGameTrace trace; // [esp+8h] [ebp-6Ch] BYREF
  Vector hullSizeNormal; // [esp+5Ch] [ebp-18h]
  Vector newOrigin; // [esp+68h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+74h] [ebp+0h] BYREF

  mv = this->mv;
  player = this->player;
  newOrigin = mv->m_vecAbsOrigin;
  v4 = CBaseEntity::GetGroundEntity(this: player) == nullptr;
  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( v4 )
  {
    v11 = (float *)GetViewVectors();
    v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal.x = v12->m_vHullMax.x - v11[3];
    hullSizeNormal.y = v12->m_vHullMax.y - v11[4];
    v13 = g_pGameRules->GetViewVectors;
    hullSizeNormal.z = v12->m_vHullMax.z - v11[5];
    v14 = (float *)v13(this: g_pGameRules);
    v15 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v8 = (float)(hullSizeNormal.x - (float)(v15->m_vDuckHullMax.x - v14[9])) * -0.5;
    v9 = (float)(hullSizeNormal.y - (float)(v15->m_vDuckHullMax.y - v14[10])) * -0.5;
    v10 = (float)(hullSizeNormal.z - (float)(v15->m_vDuckHullMax.z - v14[11])) * -0.5;
  }
  else
  {
    v6 = (float *)GetViewVectors();
    v7 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v8 = v7->m_vDuckHullMin.x - v6[3];
    v9 = v7->m_vDuckHullMin.y - v6[4];
    v10 = v7->m_vDuckHullMin.z - v6[5];
  }
  v16 = this->mv;
  PlayerSolidMask = this->PlayerSolidMask;
  v22 = this->player;
  newOrigin.z = v10 + newOrigin.z;
  newOrigin.y = v9 + newOrigin.y;
  newOrigin.x = v8 + newOrigin.x;
  v21 = PlayerSolidMask(this, a2: false, a3: nullptr);
  p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
  v18 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)&v16->m_vecAbsOrigin,
    vecAbsStart: &v16->m_vecAbsOrigin,
    vecAbsEnd: &newOrigin,
    hullMin: &v18->m_vHullMin,
    hullMax: p_m_vHullMax,
    mask: v21,
    ignore: v22,
    collisionGroup: 8,
    ptr: &trace);
  return !trace.startsolid && trace.fraction == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026B870
// Name: public: virtual void CCSGameMovement::DecayPunchAngle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::DecayPunchAngle(CCSGameMovement *this)
{
  double v2; // xmm0_8
  float v3; // xmm1_4
  float y; // xmm2_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *p_m_vecPunchAngle; // esi
  float x; // xmm0_4
  CCSPlayer *m_pCSPlayer; // esi
  float v8; // xmm0_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v9; // esi
  CCSPlayer *v10; // esi
  float z; // xmm1_4
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v12; // esi
  CCSPlayer *v13; // esi
  __int64 v14; // xmm0_8
  float v15; // ecx
  float *p_x; // esi
  __m128 m_fValue_low; // xmm0
  double v18; // xmm0_8
  bool v19; // zf
  float v20; // xmm2_4
  float v21; // xmm3_4
  QAngle punchAngle; // [esp+8h] [ebp-10h] BYREF
  float len; // [esp+14h] [ebp-4h]

  if ( weapon_recoil_legacy.m_pParent != nullptr && weapon_recoil_legacy.m_pParent->m_Value.m_nValue != 0 )
  {
    punchAngle = (QAngle)this->m_pCSPlayer->m_Local.m_vecPunchAngle;
    len = VectorNormalize(vec: (Vector *)&punchAngle);
    if ( (float)(len - (float)((float)((float)(len * 0.5) + 10.0) * gpGlobals->frametime)) <= 0.0 )
      v2 = 0.0;
    else
      v2 = len;
    v3 = v2;
    y = v3 * punchAngle.y;
    p_m_vecPunchAngle = &this->m_pCSPlayer->m_Local.m_vecPunchAngle;
    punchAngle.x = v3 * punchAngle.x;
    punchAngle.y = v3 * punchAngle.y;
    punchAngle.z = v3 * punchAngle.z;
    x = p_m_vecPunchAngle->m_Value.x;
    len = punchAngle.x;
    if ( x != punchAngle.x )
    {
      (*(void (__thiscall **)(int, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))LODWORD(p_m_vecPunchAngle[-10].m_Value.z))(
        a1: (int)&p_m_vecPunchAngle[-10].m_Value.z,
        a2: p_m_vecPunchAngle);
      p_m_vecPunchAngle->m_Value.x = len;
      y = punchAngle.y;
    }
    m_pCSPlayer = this->m_pCSPlayer;
    v8 = m_pCSPlayer->m_Local.m_vecPunchAngle.m_Value.y;
    v9 = &m_pCSPlayer->m_Local.m_vecPunchAngle;
    len = y;
    if ( v8 != y )
    {
      (*(void (__thiscall **)(int, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))LODWORD(v9[-10].m_Value.z))(
        a1: (int)&v9[-10].m_Value.z,
        a2: v9);
      v9->m_Value.y = len;
    }
    v10 = this->m_pCSPlayer;
    z = v10->m_Local.m_vecPunchAngle.m_Value.z;
    v12 = &v10->m_Local.m_vecPunchAngle;
    len = punchAngle.z;
    if ( z != punchAngle.z )
    {
      (*(void (__thiscall **)(int, CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *))LODWORD(v12[-10].m_Value.z))(
        a1: (int)&v12[-10].m_Value.z,
        a2: v12);
      v12->m_Value.z = len;
    }
  }
  else
  {
    v13 = this->m_pCSPlayer;
    v14 = *(_QWORD *)&v13->m_Local.m_vecPunchAngle.m_Value.x;
    v15 = v13->m_Local.m_vecPunchAngle.m_Value.z;
    p_x = &v13->m_Local.m_vecPunchAngle.m_Value.x;
    *(_QWORD *)&punchAngle.x = v14;
    m_fValue_low = (__m128)LODWORD(weapon_recoil_decay.m_pParent->m_Value.m_fValue);
    m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * gpGlobals->interval_per_tick;
    punchAngle.z = v15;
    __libm_sse2_exp(a1: _mm_cvtps_pd(_mm_xor_ps(m_fValue_low, (__m128)_mask__NegFloat_)));
    *(float *)&v18 = v18;
    v19 = (float)(punchAngle.x * *(float *)&v18) == *p_x;
    v20 = punchAngle.y * *(float *)&v18;
    v21 = punchAngle.z * *(float *)&v18;
    punchAngle.x = punchAngle.x * *(float *)&v18;
    punchAngle.y = punchAngle.y * *(float *)&v18;
    punchAngle.z = punchAngle.z * *(float *)&v18;
    if ( !v19 || v20 != p_x[1] || v21 != p_x[2] )
    {
      (**((void (__thiscall ***)(int, float *))p_x - 28))(a1: (int)(p_x - 28), a2: p_x);
      *(QAngle *)p_x = punchAngle;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026BAA0
// Name: public: void CBasePlayer::SetLadderNormal(class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePlayer::SetLadderNormal(CBasePlayer *this, Vector vecLadderNormal)
{
  CNetworkVectorBase<Vector,CBasePlayer::NetworkVar_m_vecLadderNormal> *p_m_vecLadderNormal; // esi
  edict_t *m_pPev; // ecx

  p_m_vecLadderNormal = &this->m_vecLadderNormal;
  if ( vecLadderNormal.x != this->m_vecLadderNormal.m_Value.x
    || vecLadderNormal.y != this->m_vecLadderNormal.m_Value.y
    || vecLadderNormal.z != this->m_vecLadderNormal.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xEDCu);
    }
    p_m_vecLadderNormal->m_Value = vecLadderNormal;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026BB30
// Name: protected: virtual void CCSGameMovement::PlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __usercall CCSGameMovement::PlayerMove(CCSGameMovement *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  CCSPlayer *m_pCSPlayer; // eax
  float m_Value; // xmm1_4
  float *p_m_Value; // edi
  float x; // xmm0_4
  float v9; // xmm1_4
  CBaseEdict *v10; // ecx
  int v11; // eax
  const Vector *(__thiscall *GetPlayerMins)(struct CCSGameMovement *, bool); // edx
  int v13; // eax
  const Vector *(__thiscall *GetPlayerMaxs)(struct CCSGameMovement *, bool); // edx
  int v15; // eax
  CBasePlayer *player; // edi
  __int64 v17; // xmm0_8
  float v18; // eax
  unsigned int v19; // ecx
  __int64 v20; // xmm1_8
  CGameRules_vtbl *v21; // edx
  unsigned int m_Index; // eax
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, CBasePlayer *); // edx
  unsigned int v24; // edi
  CBasePlayer *v25; // edi
  CBasePlayer *v26; // eax
  CBasePlayer *v27; // eax
  CBasePlayer_vtbl *v28; // edi
  int v29; // eax
  const CViewVectors *v30; // edi
  const CViewVectors *v31; // eax
  CGameRules_vtbl *v32; // edx
  float v33; // xmm0_4
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  int v35; // edi
  const CViewVectors *v36; // eax
  float v37; // xmm0_4
  float v38; // xmm2_4
  const Vector *(__thiscall *GetPlayerViewOffset)(struct CCSGameMovement *, bool); // eax
  float *v40; // eax
  CBasePlayer *v41; // ecx
  _BYTE v44[12]; // [esp+34h] [ebp-FCh] BYREF
  Ray_t ray; // [esp+40h] [ebp-F0h] BYREF
  _BYTE trace[88]; // [esp+90h] [ebp-A0h] OVERLAPPED BYREF
  float v47; // [esp+E8h] [ebp-48h]
  Vector offset; // [esp+ECh] [ebp-44h] BYREF
  Vector vHullMax; // [esp+F8h] [ebp-38h] BYREF
  float v50; // [esp+104h] [ebp-2Ch]
  Vector duckEyeHeight; // [esp+108h] [ebp-28h] BYREF
  Vector hullSizeNormal; // [esp+114h] [ebp-1Ch] BYREF
  Vector lowerClearance; // [esp+120h] [ebp-10h] BYREF
  float retaddr; // [esp+130h] [ebp+0h]

  lowerClearance.y = a2;
  lowerClearance.z = retaddr;
  if ( !CCSPlayer::CanMove(this: this->m_pCSPlayer) )
  {
    this->mv->m_flForwardMove = 0.0;
    this->mv->m_flSideMove = 0.0;
    this->mv->m_flUpMove = 0.0;
    this->mv->m_nButtons &= 0xFFFFF9E5;
  }
  CGameMovement::PlayerMove(this, a2: a3);
  m_pCSPlayer = this->m_pCSPlayer;
  if ( (m_pCSPlayer->m_fFlags.m_Value & 1) != 0 )
  {
    m_Value = m_pCSPlayer->m_flVelocityModifier.m_Value;
    p_m_Value = &m_pCSPlayer->m_flVelocityModifier.m_Value;
    if ( m_Value < 1.0 )
    {
      x = (float)(gpGlobals->frametime * 0.33333334) + m_Value;
      if ( x >= 0.0 )
      {
        if ( x > 1.0 )
          x = 1.0;
      }
      else
      {
        x = 0.0;
      }
      v9 = *p_m_Value;
      lowerClearance.x = x;
      if ( v9 != x )
      {
        if ( m_pCSPlayer->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&m_pCSPlayer->m_Network + 76) |= 1u;
        }
        else
        {
          v10 = &m_pCSPlayer->m_Network.m_pPev->CBaseEdict;
          if ( v10 != nullptr )
          {
            CBaseEdict::StateChanged(this: v10, offset: 0x178Cu);
            x = lowerClearance.x;
          }
        }
        *p_m_Value = x;
      }
    }
  }
  if ( ((unsigned __int8 (__thiscall *)(CCSPlayer *, int, int))this->m_pCSPlayer->IsAlive)(
         a1: this->m_pCSPlayer,
         a2: a3,
         a3: a4) != 0 )
  {
    v11 = ((int (__thiscall *)(CBasePlayer *, _DWORD, _DWORD))this->player->GetViewOffset)(
            a1: this->player,
            a2: LODWORD(hullSizeNormal.z),
            a3: LODWORD(lowerClearance.x));
    GetPlayerMins = this->GetPlayerMins;
    *(_QWORD *)&trace[80] = *(_QWORD *)v11;
    v47 = *(float *)(v11 + 8);
    v13 = (int)GetPlayerMins(this, a2: this->player->m_Local.m_bDucked.m_Value);
    GetPlayerMaxs = this->GetPlayerMaxs;
    v50 = *(float *)(v13 + 8);
    LODWORD(lowerClearance.x) = this->player->m_Local.m_bDucked.m_Value;
    *(_QWORD *)&vHullMax.y = *(_QWORD *)v13;
    v15 = (int)GetPlayerMaxs(this, a2: LODWORD(lowerClearance.x));
    player = this->player;
    v17 = *(_QWORD *)v15;
    v18 = *(float *)(v15 + 8);
    v19 = (unsigned int)player->m_iEFlags >> 11;
    *(_QWORD *)&offset.x = v17;
    offset.z = v18;
    if ( (v19 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&lowerClearance.y);
    v20 = *(_QWORD *)&player->m_vecAbsOrigin.x;
    duckEyeHeight.z = player->m_vecAbsOrigin.z;
    v21 = g_pGameRules->__vftable;
    *(_QWORD *)&duckEyeHeight.x = v20;
    *(_QWORD *)&hullSizeNormal.x = v20;
    duckEyeHeight.z = duckEyeHeight.z + offset.z;
    hullSizeNormal.z = duckEyeHeight.z;
    ((void (*)(void))v21->GetViewVectors)();
    vHullMax.y = vHullMax.y + 1.0;
    offset.x = offset.x - 1.0;
    vHullMax.z = vHullMax.z + 1.0;
    v50 = 0.0;
    offset.y = offset.y - 1.0;
    offset.z = 0.0;
    ray.m_Extents.y = 0.0;
    Ray_t::Init(
      this: (Ray_t *)v44,
      start: &duckEyeHeight,
      end: &hullSizeNormal,
      mins: (Vector *)&vHullMax.y,
      maxs: &offset);
    m_Index = this->mv->m_nPlayerHandle.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      lowerClearance.x = 0.0;
    else
      LODWORD(lowerClearance.x) = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    PlayerSolidMask = this->PlayerSolidMask;
    lowerClearance.x = 0.0;
    hullSizeNormal.z = 0.0;
    v24 = ((int (__thiscall *)(CCSGameMovement *))PlayerSolidMask)(a1: this);
    CTraceFilterSimple::CTraceFilterSimple(
      this: (CTraceFilterSimple *)&vHullMax,
      passedict: (const IHandleEntity *)LODWORD(lowerClearance.x),
      collisionGroup: 8,
      pExtraShouldHitFunc: nullptr);
    enginetrace->TraceRay(
      this: enginetrace,
      a2: (const Ray_t *)v44,
      a3: v24,
      a4: (ITraceFilter *)&vHullMax,
      a5: (CGameTrace *)&ray.m_IsRay);
    if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
      DebugDrawLine(
        vecAbsStart: (const Vector *)&ray.m_IsRay,
        vecAbsEnd: (const Vector *)trace,
        r: 255,
        g: 0,
        b: 0,
        test: 1,
        duration: -1.0);
    if ( *(float *)&trace[32] < 1.0 )
    {
      v25 = this->player;
      if ( (v25->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: this->player, a2: (int)&lowerClearance.y);
      v26 = this->player;
      if ( (v26->m_fFlags.m_Value & 2) == 0 && !v26->m_Local.m_bDucking.m_Value && !v26->m_Local.m_bDucked.m_Value
        || v47 > (float)((float)((float)((float)((float)(hullSizeNormal.z - duckEyeHeight.z) * *(float *)&trace[32])
                                       + duckEyeHeight.z)
                               - v25->m_vecAbsOrigin.z)
                       - 12.0) )
      {
        v47 = (float)((float)((float)((float)(hullSizeNormal.z - duckEyeHeight.z) * *(float *)&trace[32])
                            + duckEyeHeight.z)
                    - v25->m_vecAbsOrigin.z)
            - 12.0;
      }
      v26->SetViewOffset(this: v26, a2: (const Vector *)&trace[80]);
      return;
    }
    v27 = this->player;
    if ( (v27->m_fFlags.m_Value & 2) == 0 && !v27->m_Local.m_bDucking.m_Value && !v27->m_Local.m_bDucked.m_Value )
    {
      v28 = v27->__vftable;
      v29 = ((int (__thiscall *)(CGameRules *, _DWORD))g_pGameRules->GetViewVectors)(
              a1: g_pGameRules,
              a2: LODWORD(hullSizeNormal.z));
LABEL_43:
      v28->SetViewOffset(this: this->player, a2: (const Vector *)v29);
      return;
    }
    if ( this->m_pCSPlayer->m_duckUntilOnGround )
    {
      v30 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v31 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v32 = g_pGameRules->__vftable;
      duckEyeHeight.x = v31->m_vHullMax.x - v30->m_vHullMin.x;
      duckEyeHeight.y = v31->m_vHullMax.y - v30->m_vHullMin.y;
      v33 = v31->m_vHullMax.z - v30->m_vHullMin.z;
      GetViewVectors = v32->GetViewVectors;
      duckEyeHeight.z = v33;
      v35 = (int)GetViewVectors(this: g_pGameRules);
      v36 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v37 = v36->m_vDuckHullMax.x - *(float *)(v35 + 36);
      v38 = v36->m_vDuckHullMax.z - *(float *)(v35 + 44);
      GetPlayerViewOffset = this->GetPlayerViewOffset;
      hullSizeNormal.y = 0.0;
      hullSizeNormal.x = duckEyeHeight.x - v37;
      hullSizeNormal.z = duckEyeHeight.z - v38;
      v40 = (float *)((int (__thiscall *)(CCSGameMovement *))GetPlayerViewOffset)(a1: this);
      v41 = this->player;
      vHullMax.y = *v40 - hullSizeNormal.x;
      vHullMax.z = v40[1] - hullSizeNormal.y;
      v50 = v40[2] - hullSizeNormal.z;
      v41->SetViewOffset(this: v41, a2: (Vector *)&vHullMax.y);
      return;
    }
    if ( v27->m_Local.m_bDucked.m_Value && !v27->m_Local.m_bDucking.m_Value )
    {
      v28 = v27->__vftable;
      v29 = ((int (__thiscall *)(CGameRules *, _DWORD))g_pGameRules->GetViewVectors)(
              a1: g_pGameRules,
              a2: LODWORD(hullSizeNormal.z))
          + 60;
      goto LABEL_43;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026C060
// Name: public: virtual void CCSGameMovement::ReduceTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::ReduceTimers(CCSGameMovement *this)
{
  CCSPlayer *m_pCSPlayer; // esi
  float m_Value; // xmm0_4
  float v4; // xmm0_4
  CBaseEdict *v5; // ecx
  CCSPlayer *v6; // esi
  CBaseEdict *v7; // ecx

  m_pCSPlayer = this->m_pCSPlayer;
  m_Value = m_pCSPlayer->m_flStamina.m_Value;
  if ( m_Value > 0.0 )
  {
    v4 = m_Value - (float)(gpGlobals->frametime * 1000.0);
    if ( m_pCSPlayer->m_flStamina.m_Value != v4 )
    {
      if ( m_pCSPlayer->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&m_pCSPlayer->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = &m_pCSPlayer->m_Network.m_pPev->CBaseEdict;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: v5, offset: 0x1780u);
      }
      m_pCSPlayer->m_flStamina.m_Value = v4;
    }
    v6 = this->m_pCSPlayer;
    if ( v6->m_flStamina.m_Value < 0.0 )
    {
      if ( v6->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v6->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v6->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x1780u);
      }
      v6->m_flStamina.m_Value = 0.0;
    }
  }
  CGameMovement::ReduceTimers(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026C140
// Name: public: virtual bool CCSGameMovement::CheckJumpButton(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameMovement::CheckJumpButton(CCSGameMovement *this)
{
  CCSPlayer *m_pCSPlayer; // ecx
  CCSPlayer *v4; // edx
  CCSPlayer *v5; // eax
  CBasePlayer *player; // eax
  surfacedata_t *m_pSurfaceData; // ecx
  CMoveData *mv; // ecx
  CCSPlayer *v9; // eax
  double v10; // xmm0_8
  float v11; // xmm0_4
  float m_Value; // xmm0_4
  CCSPlayer *v13; // edi
  CBaseEdict *v14; // ecx
  IGameEvent *v15; // eax
  IGameEvent *v16; // edi
  IGameEvent_vtbl *v17; // ebx
  int UserID; // eax
  float startz; // [esp+20h] [ebp-8h]
  float flGroundFactor; // [esp+24h] [ebp-4h]

  m_pCSPlayer = this->m_pCSPlayer;
  if ( m_pCSPlayer->pl.deadflag.m_Value )
    goto LABEL_2;
  if ( m_pCSPlayer->m_flWaterJumpTime == 0.0 )
  {
    if ( m_pCSPlayer->m_nWaterLevel.m_Value < 2u )
    {
      if ( CBaseEntity::GetGroundEntity(this: m_pCSPlayer) == nullptr )
      {
LABEL_2:
        this->mv->m_nOldButtons |= 2u;
        return 0;
      }
      if ( (this->mv->m_nOldButtons & 2) != 0 )
        return 0;
      if ( sv_enablebunnyhopping.m_pParent == nullptr || sv_enablebunnyhopping.m_pParent->m_Value.m_nValue == 0 )
        this->PreventBunnyJumping(this);
      this->SetGroundEntity(this, a2: nullptr);
      ((void (__stdcall *)(Vector *, surfacedata_t *, int, int))this->m_pCSPlayer->PlayStepSound)(
        a1: &this->mv->m_vecAbsOrigin,
        a2: this->player->m_pSurfaceData,
        a3: 1065353216,
        a4: 1);
      CCSPlayer::DoAnimationEvent(this: this->m_pCSPlayer, event: PLAYERANIMEVENT_JUMP, nData: 0);
      player = this->player;
      m_pSurfaceData = player->m_pSurfaceData;
      flGroundFactor = 1.0;
      if ( m_pSurfaceData != nullptr )
        flGroundFactor = m_pSurfaceData->game.jumpFactor;
      if ( (player == nullptr || player->IsBot(this: player)) && (this->mv->m_nButtons & 4) == 0 )
      {
        this->m_pCSPlayer->m_duckUntilOnGround = true;
        this->FinishDuck(this);
      }
      mv = this->mv;
      v9 = this->m_pCSPlayer;
      startz = mv->m_vecVelocity.z;
      if ( v9->m_duckUntilOnGround || v9->m_Local.m_bDucking.m_Value || (v9->m_fFlags.m_Value & 2) != 0 )
        v10 = sqrt(91200.0) * flGroundFactor;
      else
        v10 = sqrt(91200.0) * flGroundFactor + mv->m_vecVelocity.z;
      v11 = v10;
      mv->m_vecVelocity.z = v11;
      m_Value = this->m_pCSPlayer->m_flStamina.m_Value;
      if ( m_Value > 0.0 )
        this->mv->m_vecVelocity.z = (float)((100.0 - m_Value * 0.001 * 19.0) * 0.01) * this->mv->m_vecVelocity.z;
      v13 = this->m_pCSPlayer;
      if ( v13->m_flStamina.m_Value != 1315.7894 )
      {
        if ( v13->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v13->m_Network + 76) |= 1u;
        }
        else
        {
          v14 = &v13->m_Network.m_pPev->CBaseEdict;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: v14, offset: 0x1780u);
        }
        v13->m_flStamina.m_Value = 1315.7894;
      }
      this->FinishGravity(this);
      this->mv->m_outWishVel.z = (float)(this->mv->m_vecVelocity.z - startz) + this->mv->m_outWishVel.z;
      this->mv->m_outStepHeight = this->mv->m_outStepHeight + 0.1;
      ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->OnJump)(a1: this, a2: LODWORD(this->mv->m_outWishVel.z));
      v15 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_jump", a3: 0, a4: 0);
      v16 = v15;
      if ( v15 != nullptr )
      {
        v17 = v15->__vftable;
        UserID = CBasePlayer::GetUserID(this: this->m_pCSPlayer);
        v17->SetInt(this: v16, a2: "userid", a3: UserID);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v16, a3: false);
      }
      this->mv->m_nOldButtons |= 2u;
      return 1;
    }
    else
    {
      this->SetGroundEntity(this, a2: nullptr);
      if ( CBaseEntity::GetWaterType(this: this->m_pCSPlayer) == 32 )
      {
        this->mv->m_vecVelocity.z = 100.0;
      }
      else if ( CBaseEntity::GetWaterType(this: this->m_pCSPlayer) == 16 )
      {
        this->mv->m_vecVelocity.z = 80.0;
      }
      v5 = this->m_pCSPlayer;
      if ( v5->m_flSwimSoundTime <= 0.0 )
      {
        v5->m_flSwimSoundTime = 1000.0;
        CGameMovement::PlaySwimSound(this);
      }
      return 0;
    }
  }
  else
  {
    m_pCSPlayer->m_flWaterJumpTime = m_pCSPlayer->m_flWaterJumpTime - gpGlobals->frametime;
    v4 = this->m_pCSPlayer;
    if ( v4->m_flWaterJumpTime < 0.0 )
      v4->m_flWaterJumpTime = 0.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026C4E0
// Name: public: virtual void CCSGameMovement::FinishUnDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::FinishUnDuck(CCSGameMovement *this)
{
  bool v2; // zf
  int (*GetViewVectors)(void); // edx
  float *v4; // esi
  const CViewVectors *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float *v9; // esi
  const CViewVectors *v10; // eax
  const CViewVectors *v11; // esi
  const CViewVectors *v12; // eax
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // esi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // esi
  CBasePlayer_vtbl *v15; // esi
  const Vector *v16; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // esi
  float hullSizeNormal; // [esp+8h] [ebp-18h]
  float hullSizeNormal_4; // [esp+Ch] [ebp-14h]
  float hullSizeNormal_8; // [esp+10h] [ebp-10h]
  Vector newOrigin; // [esp+14h] [ebp-Ch]

  newOrigin = this->mv->m_vecAbsOrigin;
  v2 = CBaseEntity::GetGroundEntity(this: this->player) == nullptr;
  GetViewVectors = (int (*)(void))g_pGameRules->GetViewVectors;
  if ( v2 )
  {
    v9 = (float *)GetViewVectors();
    v10 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    hullSizeNormal = v10->m_vHullMax.x - v9[3];
    hullSizeNormal_4 = v10->m_vHullMax.y - v9[4];
    hullSizeNormal_8 = v10->m_vHullMax.z - v9[5];
    v11 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v6 = (float)(hullSizeNormal - (float)(v12->m_vDuckHullMax.x - v11->m_vDuckHullMin.x)) * -0.5;
    v7 = (float)(hullSizeNormal_4 - (float)(v12->m_vDuckHullMax.y - v11->m_vDuckHullMin.y)) * -0.5;
    v8 = (float)(hullSizeNormal_8 - (float)(v12->m_vDuckHullMax.z - v11->m_vDuckHullMin.z)) * -0.5;
  }
  else
  {
    v4 = (float *)GetViewVectors();
    v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
    v6 = v5->m_vDuckHullMin.x - v4[3];
    v7 = v5->m_vDuckHullMin.y - v4[4];
    v8 = v5->m_vDuckHullMin.z - v4[5];
  }
  p_m_bDucked = &this->player->m_Local.m_bDucked;
  newOrigin.z = v8 + newOrigin.z;
  newOrigin.y = v7 + newOrigin.y;
  newOrigin.x = v6 + newOrigin.x;
  if ( p_m_bDucked->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucked);
    p_m_bDucked->m_Value = false;
  }
  CBaseEntity::RemoveFlag(this: this->player, flagsToRemove: 2);
  p_m_bDucking = &this->player->m_Local.m_bDucking;
  if ( p_m_bDucking->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
    p_m_bDucking->m_Value = false;
  }
  v15 = this->player->CGameMovement::__vftable;
  v16 = this->GetPlayerViewOffset(this, a2: 0);
  v15->SetViewOffset(this: this->player, a2: v16);
  p_m_nDuckTimeMsecs = &this->player->m_Local.m_nDuckTimeMsecs;
  if ( p_m_nDuckTimeMsecs->m_Value != 0 )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_nDuckTimeMsecs);
    p_m_nDuckTimeMsecs->m_Value = 0;
  }
  this->mv->m_vecAbsOrigin = newOrigin;
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026C6F0
// Name: public: virtual void CCSGameMovement::FinishDuck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::FinishDuck(CCSGameMovement *this)
{
  const CViewVectors *v2; // edi
  const CViewVectors *v3; // eax
  const CViewVectors *v4; // edi
  const CViewVectors *v5; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  CBasePlayer_vtbl *v9; // edi
  const Vector *v10; // eax
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // edi
  CBasePlayer *player; // ecx
  CMoveData *mv; // eax
  const CViewVectors *v14; // edi
  const CViewVectors *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  CMoveData *v19; // eax
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *p_m_bDucked; // edi
  float viewDelta; // [esp+8h] [ebp-18h]
  float viewDelta_4; // [esp+Ch] [ebp-14h]
  float viewDelta_8; // [esp+10h] [ebp-10h]
  float orga; // [esp+14h] [ebp-Ch]
  __int64 org; // [esp+14h] [ebp-Ch]
  float org_4; // [esp+18h] [ebp-8h]
  float org_8a; // [esp+1Ch] [ebp-4h]
  float org_8; // [esp+1Ch] [ebp-4h]

  v2 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  orga = v3->m_vHullMax.x - v2->m_vHullMin.x;
  org_4 = v3->m_vHullMax.y - v2->m_vHullMin.y;
  org_8a = v3->m_vHullMax.z - v2->m_vHullMin.z;
  v4 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v6 = v5->m_vDuckHullMax.x - v4->m_vDuckHullMin.x;
  v7 = v5->m_vDuckHullMax.y - v4->m_vDuckHullMin.y;
  v8 = v5->m_vDuckHullMax.z - v4->m_vDuckHullMin.z;
  v9 = this->player->CGameMovement::__vftable;
  viewDelta = (float)(orga - v6) * 0.5;
  viewDelta_4 = (float)(org_4 - v7) * 0.5;
  viewDelta_8 = (float)(org_8a - v8) * 0.5;
  v10 = this->GetPlayerViewOffset(this, a2: 1);
  v9->SetViewOffset(this: this->player, a2: v10);
  CBaseEntity::AddFlag(this: this->player, flags: 2);
  p_m_bDucking = &this->player->m_Local.m_bDucking;
  if ( p_m_bDucking->m_Value )
  {
    this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
    p_m_bDucking->m_Value = false;
  }
  player = this->player;
  if ( !player->m_Local.m_bDucked.m_Value )
  {
    mv = this->mv;
    org = *(_QWORD *)&mv->m_vecAbsOrigin.x;
    org_8 = mv->m_vecAbsOrigin.z;
    if ( CBaseEntity::GetGroundEntity(this: player) != nullptr )
    {
      v14 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v15 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v16 = *(float *)&org - (float)(v15->m_vDuckHullMin.x - v14->m_vHullMin.x);
      v17 = *((float *)&org + 1) - (float)(v15->m_vDuckHullMin.y - v14->m_vHullMin.y);
      v18 = org_8 - (float)(v15->m_vDuckHullMin.z - v14->m_vHullMin.z);
    }
    else
    {
      v16 = viewDelta + *(float *)&org;
      v17 = *((float *)&org + 1) + viewDelta_4;
      v18 = org_8 + viewDelta_8;
    }
    v19 = this->mv;
    p_m_bDucked = &this->player->m_Local.m_bDucked;
    v19->m_vecAbsOrigin.x = v16;
    v19->m_vecAbsOrigin.y = v17;
    v19->m_vecAbsOrigin.z = v18;
    if ( !p_m_bDucked->m_Value )
    {
      (**(void (__thiscall ***)(int, CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucked> *))&p_m_bDucked[-80].m_Value)(
        a1: (int)&p_m_bDucked[-80],
        a2: p_m_bDucked);
      p_m_bDucked->m_Value = true;
    }
  }
  this->FixPlayerCrouchStuck(this, a2: true);
  this->CategorizePosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026C910
// Name: public: virtual void CCSGameMovement::Duck(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::Duck(CCSGameMovement *this)
{
  int m_Value; // ecx
  CMoveData *mv; // eax
  CMoveData *v4; // ecx
  int m_nOldButtons; // eax
  int m_nButtons; // ecx
  int v7; // edx
  char v8; // bl
  CBasePlayer *player; // ecx
  CMoveData *v10; // eax
  bool v11; // zf
  CCSPlayer *m_pCSPlayer; // eax
  CMoveData *v13; // eax
  CGameRules_vtbl *v14; // edx
  float z; // xmm0_4
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // eax
  float *v17; // edi
  const CViewVectors *v18; // eax
  CGameRules_vtbl *v19; // edx
  float v20; // xmm0_4
  const CViewVectors *(__thiscall *v21)(CGameRules *); // eax
  float *v22; // edi
  const CViewVectors *v23; // eax
  CCSGameMovement_vtbl *v24; // edx
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, CBasePlayer *); // eax
  const CViewVectors *v29; // eax
  CBasePlayer *v30; // eax
  CBasePlayer *v31; // eax
  int v32; // ecx
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *p_m_nDuckTimeMsecs; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *p_m_bDucking; // edi
  CBasePlayer *v35; // ecx
  CBasePlayer *v36; // ecx
  CBasePlayer *v37; // eax
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v38; // edi
  CNetworkVarBase<bool,CPlayerLocalData::NetworkVar_m_bDucking> *v39; // edi
  CBasePlayer *v40; // ecx
  CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *v41; // esi
  Vector *p_m_vHullMax; // [esp-8h] [ebp-94h]
  unsigned int v43; // [esp-4h] [ebp-90h]
  CBasePlayer *v44; // [esp+8h] [ebp-84h]
  float trace_44; // [esp+44h] [ebp-48h]
  char trace_55; // [esp+4Fh] [ebp-3Dh]
  Vector hullSizeNormal; // [esp+6Ch] [ebp-20h] BYREF
  Vector newOrigin; // [esp+78h] [ebp-14h] BYREF
  float duckmilliseconds; // [esp+84h] [ebp-8h]
  bool alreadyDucked; // [esp+8Bh] [ebp-1h]
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  m_Value = this->player->m_fFlags.m_Value;
  if ( (m_Value & 1) != 0 )
  {
    mv = this->mv;
    if ( (mv->m_nButtons & 4) != 0 || (mv->m_nOldButtons & 4) == 0 )
    {
      if ( (mv->m_nButtons & 4) != 0
        && (mv->m_nOldButtons & 4) == 0
        && (m_Value & 2) != 0
        && this->m_fTimeLastUnducked > (float)(gpGlobals->curtime - sv_timebetweenducks.m_pParent->m_Value.m_fValue) )
      {
        mv->m_nButtons &= ~4u;
      }
    }
    else
    {
      this->m_fTimeLastUnducked = gpGlobals->curtime;
    }
  }
  v4 = this->mv;
  m_nOldButtons = v4->m_nOldButtons;
  m_nButtons = v4->m_nButtons;
  v7 = m_nOldButtons ^ m_nButtons;
  v8 = (m_nOldButtons ^ m_nButtons) & m_nButtons;
  player = this->player;
  LODWORD(duckmilliseconds) = v7 & m_nOldButtons;
  if ( CBaseEntity::GetGroundEntity(this: player) != nullptr
    || (v11 = this->player->m_MoveType.m_Value == 9, alreadyDucked = true, v11) )
  {
    alreadyDucked = false;
  }
  v10 = this->mv;
  if ( (v10->m_nButtons & 4) != 0 )
    v10->m_nOldButtons |= 4u;
  else
    v10->m_nOldButtons &= ~4u;
  if ( CGameMovement::IsDead(this) )
  {
    v11 = (this->player->m_fFlags.m_Value & 2) == 0;
    goto LABEL_18;
  }
  this->HandleDuckingSpeedCrop(this);
  m_pCSPlayer = this->m_pCSPlayer;
  if ( m_pCSPlayer->m_duckUntilOnGround )
  {
    if ( !alreadyDucked )
    {
LABEL_22:
      m_pCSPlayer->m_duckUntilOnGround = false;
      v11 = !this->CanUnduck(this);
LABEL_18:
      if ( v11 )
        return;
      goto LABEL_19;
    }
    v13 = this->mv;
    if ( v13->m_vecVelocity.z <= 0.0 )
    {
      v14 = g_pGameRules->__vftable;
      newOrigin.x = v13->m_vecAbsOrigin.x;
      newOrigin.y = v13->m_vecAbsOrigin.y;
      z = v13->m_vecAbsOrigin.z;
      GetViewVectors = v14->GetViewVectors;
      newOrigin.z = z;
      v17 = (float *)GetViewVectors(this: g_pGameRules);
      v18 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v19 = g_pGameRules->__vftable;
      hullSizeNormal.x = v18->m_vHullMax.x - v17[3];
      hullSizeNormal.y = v18->m_vHullMax.y - v17[4];
      v20 = v18->m_vHullMax.z - v17[5];
      v21 = v19->GetViewVectors;
      hullSizeNormal.z = v20;
      v22 = (float *)v21(this: g_pGameRules);
      v23 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      v24 = this->__vftable;
      v25 = newOrigin.x - (float)(hullSizeNormal.x - (float)(v23->m_vDuckHullMax.x - v22[9]));
      v26 = newOrigin.y - (float)(hullSizeNormal.y - (float)(v23->m_vDuckHullMax.y - v22[10]));
      v44 = this->player;
      newOrigin.z = newOrigin.z - (float)(v20 - (float)(v23->m_vDuckHullMax.z - v22[11]));
      v27 = newOrigin.z - v44->m_Local.m_flStepSize.m_Value;
      PlayerSolidMask = v24->PlayerSolidMask;
      newOrigin.x = v25;
      newOrigin.y = v26;
      hullSizeNormal.x = v25;
      hullSizeNormal.y = v26;
      hullSizeNormal.z = v27;
      v43 = ((int (__thiscall *)(CCSGameMovement *))PlayerSolidMask)(a1: this);
      p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v29 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      UTIL_TraceHull(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &newOrigin,
        vecAbsEnd: &hullSizeNormal,
        hullMin: &v29->m_vHullMin,
        hullMax: p_m_vHullMax,
        mask: v43,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: (CGameTrace *)v44);
      if ( trace_55 == 0 && trace_44 != 1.0 )
      {
        m_pCSPlayer = this->m_pCSPlayer;
        goto LABEL_22;
      }
    }
  }
  else if ( (this->mv->m_nButtons & 4) != 0
         || (v30 = this->player)->m_Local.m_bDucking.m_Value
         || (v30->m_fFlags.m_Value & 2) != 0 )
  {
    if ( (this->mv->m_nButtons & 4) != 0 )
    {
      v31 = this->player;
      v32 = v31->m_fFlags.m_Value;
      alreadyDucked = (v32 & 2) != 0;
      if ( (v8 & 4) != 0 && (v32 & 2) == 0 )
      {
        p_m_nDuckTimeMsecs = &v31->m_Local.m_nDuckTimeMsecs;
        if ( v31->m_Local.m_nDuckTimeMsecs.m_Value != 1000 )
        {
          v31->m_Local.NetworkStateChanged(this: &v31->m_Local, a2: &v31->m_Local.m_nDuckTimeMsecs);
          p_m_nDuckTimeMsecs->m_Value = 1000;
        }
        p_m_bDucking = &this->player->m_Local.m_bDucking;
        if ( !p_m_bDucking->m_Value )
        {
          this->player->m_Local.NetworkStateChanged(this: &this->player->m_Local, a2: &this->player->m_Local.m_bDucking);
          p_m_bDucking->m_Value = true;
        }
      }
      v35 = this->player;
      if ( (float)(1000.0 - (float)v35->m_Local.m_nDuckTimeMsecs.m_Value) >= 0.0 )
        duckmilliseconds = 1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs.m_Value;
      else
        duckmilliseconds = 0.0;
      if ( v35->m_Local.m_bDucking.m_Value )
      {
        if ( (v35->m_fFlags.m_Value & 4) == 0 )
          CBaseEntity::AddFlag(this: v35, flags: 4);
        if ( duckmilliseconds > 400.0 || CBaseEntity::GetGroundEntity(this: this->player) == nullptr || alreadyDucked )
          this->FinishDuck(this);
        else
          ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
            a1: this,
            a2: (float)((float)((float)(duckmilliseconds * 0.0024999999) * (float)(duckmilliseconds * 0.0024999999)) * 3.0)
          - (float)((float)((float)((float)(duckmilliseconds * 0.0024999999) * (float)(duckmilliseconds * 0.0024999999))
                          * 2.0)
                  * (float)(duckmilliseconds * 0.0024999999)));
      }
    }
    else
    {
      v36 = this->player;
      if ( v36->m_Local.m_bAllowAutoMovement.m_Value || CBaseEntity::GetGroundEntity(this: v36) == nullptr )
      {
        if ( (LOBYTE(duckmilliseconds) & 4) != 0 )
        {
          v37 = this->player;
          if ( (v37->m_fFlags.m_Value & 2) != 0 )
          {
            v38 = &v37->m_Local.m_nDuckTimeMsecs;
            if ( v37->m_Local.m_nDuckTimeMsecs.m_Value != 1000 )
            {
              v37->m_Local.NetworkStateChanged(this: &v37->m_Local, a2: &v37->m_Local.m_nDuckTimeMsecs);
              v38->m_Value = 1000;
            }
            v39 = &this->player->m_Local.m_bDucking;
            if ( !v39->m_Value )
            {
              this->player->m_Local.NetworkStateChanged(
                this: &this->player->m_Local,
                a2: &this->player->m_Local.m_bDucking);
              v39->m_Value = true;
            }
          }
        }
        if ( (float)(1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs.m_Value) >= 0.0 )
          duckmilliseconds = 1000.0 - (float)this->player->m_Local.m_nDuckTimeMsecs.m_Value;
        else
          duckmilliseconds = 0.0;
        if ( this->CanUnduck(this) )
        {
          v40 = this->player;
          if ( v40->m_Local.m_bDucking.m_Value || v40->m_Local.m_bDucked.m_Value )
          {
            if ( (v40->m_fFlags.m_Value & 4) != 0 )
              CBaseEntity::RemoveFlag(this: v40, flagsToRemove: 4);
            if ( duckmilliseconds > 200.0 || CBaseEntity::GetGroundEntity(this: this->player) == nullptr )
            {
LABEL_19:
              this->FinishUnDuck(this);
              return;
            }
            ((void (__thiscall *)(CCSGameMovement *, _DWORD))this->SetDuckedEyeOffset)(
              a1: this,
              a2: (float)((float)((float)(1.0 - (float)(duckmilliseconds * 0.0024999999))
                            * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999)))
                    * 3.0)
            - (float)((float)((float)((float)(1.0 - (float)(duckmilliseconds * 0.0024999999))
                                    * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999)))
                            * 2.0)
                    * (float)(1.0 - (float)(duckmilliseconds * 0.0024999999))));
          }
        }
        else
        {
          v41 = &this->player->m_Local.m_nDuckTimeMsecs;
          if ( v41->m_Value != 1000 )
          {
            (*(void (__thiscall **)(CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *, CNetworkVarBase<int,CPlayerLocalData::NetworkVar_m_nDuckTimeMsecs> *))v41[-21].m_Value)(
              a1: v41 - 21,
              a2: v41);
            v41->m_Value = 1000;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026CEA0
// Name: protected: void CCSGameMovement::CheckForLadders(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::CheckForLadders(CCSGameMovement *this, bool wasOnGround)
{
  CMoveData *mv; // eax
  CCSPlayer *m_pCSPlayer; // ecx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  double v8; // st7
  CCSPlayer *v9; // eax
  CCSGameMovement_vtbl *v10; // ebx
  CMoveData *v11; // edi
  unsigned int (__thiscall *PlayerSolidMask)(struct CCSGameMovement *, bool, CBasePlayer *); // edx
  int v13; // eax
  CMoveData *v14; // ecx
  CCSPlayer *v15; // eax
  CCSGameMovement_vtbl *v16; // edi
  unsigned int (__thiscall *v17)(struct CCSGameMovement *, bool, CBasePlayer *); // edx
  Vector *p_m_vecAbsOrigin; // ebx
  int v19; // eax
  CGameTrace trace; // [esp+Ch] [ebp-6Ch] BYREF
  float v21; // [esp+60h] [ebp-18h] BYREF
  float v22; // [esp+64h] [ebp-14h]
  float v23; // [esp+68h] [ebp-10h]
  Vector dir; // [esp+6Ch] [ebp-Ch] BYREF
  float dist; // [esp+80h] [ebp+8h]
  float dista; // [esp+80h] [ebp+8h]

  mv = this->mv;
  if ( wasOnGround )
  {
    this->m_pCSPlayer->m_lastStandingPos = mv->m_vecAbsOrigin;
  }
  else
  {
    m_pCSPlayer = this->m_pCSPlayer;
    if ( mv->m_vecAbsOrigin.z <= m_pCSPlayer->m_lastStandingPos.z )
    {
      v5 = -m_pCSPlayer->m_lastStandingPos.y;
      v6 = -m_pCSPlayer->m_lastStandingPos.z;
      dir.x = mv->m_vecAbsOrigin.x - m_pCSPlayer->m_lastStandingPos.x;
      v7 = mv->m_vecAbsOrigin.y + v5;
      dir.y = v7;
      dir.z = mv->m_vecAbsOrigin.z + v6;
      if ( dir.x != 0.0 || v7 != 0.0 )
      {
        dir.z = 0.0;
        v8 = VectorNormalize(vec: &dir);
        dist = v8;
        if ( v8 <= 64.0 )
        {
          v9 = this->m_pCSPlayer;
          v10 = this->__vftable;
          v11 = this->mv;
          PlayerSolidMask = this->PlayerSolidMask;
          v21 = v9->m_lastStandingPos.x - (float)((float)(dist + 5.0) * dir.x);
          v22 = v9->m_lastStandingPos.y - (float)((float)(dist + 5.0) * dir.y);
          dista = dist + 5.0;
          v23 = v9->m_lastStandingPos.z - (float)(dista * dir.z);
          v13 = ((int (__thiscall *)(CCSGameMovement *, _DWORD, _DWORD, int, CGameTrace *))PlayerSolidMask)(
                  a1: this,
                  a2: 0,
                  a3: 0,
                  a4: 8,
                  a5: &trace);
          ((void (__thiscall *)(CCSGameMovement *, Vector *, float *, unsigned int))v10->TracePlayerBBox)(
            a1: this,
            a2: &v11->m_vecAbsOrigin,
            a3: &v21,
            a4: v13 & 0xFFFEFFFF);
          if ( trace.fraction != 1.0
            && this->OnLadder(this, a2: &trace)
            && trace.plane.normal.z != 1.0
            && CCSPlayer::CanGrabLadder(this: this->m_pCSPlayer, pos: &trace.endpos, normal: &trace.plane.normal) )
          {
            CBaseEntity::SetMoveType(this: this->player, val: MOVETYPE_LADDER, moveCollide: MOVECOLLIDE_DEFAULT);
            CBaseEntity::SetMoveCollide(this: this->player, val: MOVECOLLIDE_DEFAULT);
            CBasePlayer::SetLadderNormal(this: this->player, vecLadderNormal: trace.plane.normal);
            v14 = this->mv;
            v15 = this->m_pCSPlayer;
            v16 = this->__vftable;
            v17 = this->PlayerSolidMask;
            v14->m_vecVelocity.x = 0.0;
            v14->m_vecVelocity.y = 0.0;
            v14->m_vecVelocity.z = 0.0;
            v21 = v15->m_lastStandingPos.x - (float)(dista * dir.x);
            v22 = v15->m_lastStandingPos.y - (float)(dista * dir.y);
            p_m_vecAbsOrigin = &v14->m_vecAbsOrigin;
            v23 = v15->m_lastStandingPos.z - (float)(dista * dir.z);
            v19 = ((int (__thiscall *)(CCSGameMovement *, _DWORD, _DWORD, int, CGameTrace *))v17)(
                    a1: this,
                    a2: 0,
                    a3: 0,
                    a4: 8,
                    a5: &trace);
            ((void (__thiscall *)(CCSGameMovement *, Vector *, float *, int))v16->TracePlayerBBox)(
              a1: this,
              a2: p_m_vecAbsOrigin,
              a3: &v21,
              a4: v19);
            CMoveData::SetAbsOrigin(this: this->mv, vec: &trace.endpos);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D170
// Name: public: virtual void CCSGameMovement::WalkMove(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1026D220
// Name: public: virtual void CCSGameMovement::AirMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameMovement::AirMove(CCSGameMovement *this)
{
  CGameMovement::AirMove(this);
  CCSGameMovement::CheckForLadders(this, wasOnGround: false);
}

//------------------------------------------------------------------------------
// Address: 0x1026D240
// Name: __CreateCServerGameTagsIServerGameTags_interface_10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_10()
{
  return &_g_CServerGameTags_singleton_10;
}

} // namespace server
