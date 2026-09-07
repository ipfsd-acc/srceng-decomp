// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/player_command.cpp
// Functions: 6
// ============================================================

#include "game\server\player_command.h"

//------------------------------------------------------------------------------
// Address: 0x101C7B70
// Name: public: CPlayerMove::CPlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
CPlayerMove *__thiscall CPlayerMove::CPlayerMove(CPlayerMove *this)
{
  this->__vftable = (CPlayerMove_vtbl *)&CPlayerMove::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C7BB0
// Name: protected: virtual void CPlayerMove::StartCommand(class CBasePlayer __near *,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerMove::StartCommand(CPlayerMove *this, CBasePlayer *player, CUserCmd *cmd)
{
  player->m_pCurrentCommand = cmd;
  CBaseEntity::SetPredictionRandomSeed(cmd);
  CBaseEntity::m_pPredictionPlayer = player;
}

//------------------------------------------------------------------------------
// Address: 0x101C7BE0
// Name: protected: virtual void CPlayerMove::SetupMove(class CBasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerMove::SetupMove(
        CPlayerMove *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  const Vector *PreviouslyPredictedOrigin; // eax
  CUserCmd *v6; // edx
  unsigned int m_Index; // ecx
  CBaseEntity **v8; // edx
  CBaseEntity *v9; // ebx
  unsigned int v10; // ecx
  int v11; // eax
  CEntInfo *v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  bool v15; // zf
  CBaseEntity **v16; // eax
  CBaseEntity *v17; // ebx
  double z; // st7
  matrix3x4_t viewToWorld; // [esp+Ch] [ebp-60h] BYREF
  matrix3x4_t viewToParent; // [esp+3Ch] [ebp-30h] BYREF
  int savedregs; // [esp+6Ch] [ebp+0h] BYREF

  *(_BYTE *)move = *(_BYTE *)move & 0xFC | 1;
  if ( (player->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
  PreviouslyPredictedOrigin = CBasePlayer::GetPreviouslyPredictedOrigin(this: player);
  if ( player->m_vecAbsOrigin.x != PreviouslyPredictedOrigin->x
    || player->m_vecAbsOrigin.y != PreviouslyPredictedOrigin->y
    || player->m_vecAbsOrigin.z != PreviouslyPredictedOrigin->z )
  {
    *(_BYTE *)move |= 2u;
  }
  v6 = ucmd;
  move->m_nImpulseCommand = ucmd->impulse;
  move->m_vecViewAngles = ucmd->viewangles;
  m_Index = player->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 )
    goto LABEL_11;
  v8 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || (v9 = *v8, *v8 == nullptr) )
  {
    v6 = ucmd;
LABEL_11:
    move->m_vecAbsViewAngles = move->m_vecViewAngles;
    goto LABEL_15;
  }
  AngleMatrix(angles: &move->m_vecViewAngles, matrix: &viewToParent);
  if ( (v9->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&savedregs);
  ConcatTransforms(in1: &v9->m_rgflCoordinateFrame, in2: &viewToParent, out: &viewToWorld);
  MatrixAngles(a1: (int)move, src: (const VMatrix *)&viewToWorld, vAngles: &move->m_vecAbsViewAngles);
  v6 = ucmd;
LABEL_15:
  move->m_nButtons = v6->buttons;
  if ( SLOBYTE(player->m_fFlags.m_Value) >= 0 )
  {
    move->m_flForwardMove = v6->forwardmove;
    move->m_flSideMove = v6->sidemove;
    move->m_flUpMove = v6->upmove;
  }
  else
  {
    move->m_flForwardMove = 0.0;
    move->m_flSideMove = 0.0;
    move->m_flUpMove = 0.0;
  }
  move->m_flClientMaxSpeed = player->m_flMaxspeed.m_Value;
  move->m_nOldButtons = player->m_Local.m_nOldButtons;
  move->m_vecAngles = player->pl.v_angle;
  if ( (player->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: player, a2: (int)&savedregs);
  move->m_vecVelocity = player->m_vecAbsVelocity;
  move->m_nPlayerHandle.m_Index = player->GetRefEHandle(this: player)->m_Index;
  if ( (player->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
  move->m_vecAbsOrigin = player->m_vecAbsOrigin;
  v10 = player->m_hConstraintEntity.m_Value.m_Index;
  if ( v10 != -1
    && (v11 = (unsigned __int16)v10,
        v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v10],
        v13 = HIWORD(v10),
        v12->m_SerialNumber == v13)
    && v12->m_pEntity != nullptr )
  {
    v14 = v11;
    v15 = g_pEntityList->m_EntPtrArray[v14].m_SerialNumber == v13;
    v16 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v14];
    if ( v15 )
      v17 = *v16;
    else
      v17 = nullptr;
    if ( (v17->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v17, a2: (int)&savedregs);
    move->m_vecConstraintCenter.x = v17->m_vecAbsOrigin.x;
    move->m_vecConstraintCenter.y = v17->m_vecAbsOrigin.y;
    z = v17->m_vecAbsOrigin.z;
  }
  else
  {
    move->m_vecConstraintCenter.x = player->m_vecConstraintCenter.m_Value.x;
    move->m_vecConstraintCenter.y = player->m_vecConstraintCenter.m_Value.y;
    z = player->m_vecConstraintCenter.m_Value.z;
  }
  move->m_vecConstraintCenter.z = z;
  move->m_flConstraintRadius = player->m_flConstraintRadius.m_Value;
  move->m_flConstraintWidth = player->m_flConstraintWidth.m_Value;
  move->m_flConstraintSpeedFactor = player->m_flConstraintSpeedFactor.m_Value;
  move->m_bConstraintPastRadius = player->m_bConstraintPastRadius.m_Value;
  g_pGameMovement->SetupMovementBounds(this: g_pGameMovement, a2: move);
}

//------------------------------------------------------------------------------
// Address: 0x101C7EB0
// Name: protected: virtual void CPlayerMove::FinishMove(class CBasePlayer __near *,class CUserCmd __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerMove::FinishMove(CPlayerMove *this, CBasePlayer *player, CUserCmd *ucmd, CMoveData *move)
{
  edict_t *m_pPev; // ecx
  QAngle *p_m_vecAngles; // edi
  float flPitch; // xmm0_4
  int v7; // xmm1_4

  if ( player->m_flMaxspeed.m_Value != move->m_flClientMaxSpeed )
  {
    if ( player->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&player->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = player->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xED4u);
    }
    player->m_flMaxspeed.m_Value = move->m_flClientMaxSpeed;
  }
  CBaseEntity::SetAbsOrigin(this: player, absOrigin: &move->m_vecAbsOrigin);
  CBaseEntity::SetAbsVelocity(this: player, vecAbsVelocity: &move->m_vecVelocity);
  CBasePlayer::SetPreviouslyPredictedOrigin(this: player, vecAbsOrigin: &move->m_vecAbsOrigin);
  p_m_vecAngles = &move->m_vecAngles;
  player->m_Local.m_nOldButtons = move->m_nButtons;
  flPitch = move->m_vecAngles.x;
  if ( flPitch > 180.0 )
    flPitch = flPitch - 360.0;
  v7 = -1028390912;
  if ( flPitch < -90.0 || (v7 = 1119092736, flPitch > 90.0) )
    flPitch = *(float *)&v7;
  p_m_vecAngles->x = flPitch;
  CBasePlayer::SetBodyPitch(this: player, flPitch);
  CBaseEntity::SetLocalAngles(this: player, angles: p_m_vecAngles);
}

//------------------------------------------------------------------------------
// Address: 0x101C7F80
// Name: protected: void CPlayerMove::CheckMovingGround(class CBasePlayer __near *,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerMove::CheckMovingGround(CPlayerMove *this, CBasePlayer *player, long double frametime)
{
  CBaseEntity *GroundEntity; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  Vector vecNewVelocity; // [esp+4h] [ebp-Ch] BYREF

  if ( (player->m_fFlags.m_Value & 1) != 0 )
  {
    GroundEntity = CBaseEntity::GetGroundEntity(this: player);
    if ( GroundEntity != nullptr && (GroundEntity->m_fFlags.m_Value & 0x2000) != 0 )
    {
      GroundEntity->GetGroundVelocityToApply(this: GroundEntity, a2: &vecNewVelocity);
      if ( (player->m_fFlags.m_Value & 0x1000000) != 0 )
      {
        vecNewVelocity.x = player->m_vecBaseVelocity.m_Value.x + vecNewVelocity.x;
        vecNewVelocity.y = player->m_vecBaseVelocity.m_Value.y + vecNewVelocity.y;
        vecNewVelocity.z = player->m_vecBaseVelocity.m_Value.z + vecNewVelocity.z;
      }
      CBaseEntity::SetBaseVelocity(this: player, v: &vecNewVelocity);
      CBaseEntity::AddFlag(this: player, flags: 0x1000000);
    }
  }
  if ( (player->m_fFlags.m_Value & 0x1000000) == 0 )
  {
    v4 = frametime * 0.5 + 1.0;
    vecNewVelocity.x = player->m_vecBaseVelocity.m_Value.x * v4;
    v5 = v4 * player->m_vecBaseVelocity.m_Value.y;
    v6 = v4 * player->m_vecBaseVelocity.m_Value.z;
    vecNewVelocity.y = v5;
    vecNewVelocity.z = v6;
    CBaseEntity::ApplyAbsVelocityImpulse(this: player, vecImpulse: &vecNewVelocity);
    if ( vec3_origin.x != player->m_vecBaseVelocity.m_Value.x
      || vec3_origin.y != player->m_vecBaseVelocity.m_Value.y
      || vec3_origin.z != player->m_vecBaseVelocity.m_Value.z )
    {
      player->NetworkStateChanged_m_vecBaseVelocity(this: player, a2: &player->m_vecBaseVelocity);
      player->m_vecBaseVelocity.m_Value = vec3_origin;
    }
  }
  CBaseEntity::RemoveFlag(this: player, flagsToRemove: 0x1000000);
}

//------------------------------------------------------------------------------
// Address: 0x101C8100
// Name: public: virtual void CPlayerMove::RunCommand(class CBasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerMove::RunCommand(
        CPlayerMove *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *moveHelper)
{
  CGlobalVars *v6; // eax
  float interval_per_tick; // xmm0_4
  float v8; // xmm1_4
  int weaponselect; // eax
  CBaseEntity *v10; // eax
  void *v11; // eax
  int v12; // eax
  IServerVehicle *v13; // eax
  int fixangle; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  int NextThinkTick; // eax
  int v18; // ebx
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_nTickBase> *v19; // eax
  CBaseEdict *m_Value; // ecx
  float playerCurTime; // [esp+2Ch] [ebp-10h]
  float serverFrameTime; // [esp+30h] [ebp-Ch]
  float serverCurTime; // [esp+34h] [ebp-8h]
  IServerVehicle *pVehiclea; // [esp+38h] [ebp-4h]
  IServerVehicle *pVehicle; // [esp+38h] [ebp-4h]
  CNetworkVarBase<int,CBasePlayer::NetworkVar_m_nTickBase> *playera; // [esp+44h] [ebp+8h]

  this->StartCommand(this, a2: player, a3: ucmd);
  v6 = gpGlobals;
  serverCurTime = gpGlobals->curtime;
  serverFrameTime = gpGlobals->frametime;
  interval_per_tick = gpGlobals->interval_per_tick;
  v8 = (float)player->m_nTickBase.m_Value * interval_per_tick;
  playera = &player->m_nTickBase;
  playerCurTime = (float)playera->m_Value * interval_per_tick;
  if ( player->m_bGamePaused )
    interval_per_tick = 0.0;
  gpGlobals->curtime = v8;
  v6->frametime = interval_per_tick;
  ucmd->buttons |= player->m_afButtonForced;
  ucmd->buttons &= ~player->m_afButtonDisabled;
  if ( player->m_bGamePaused
    && player->m_MoveType.m_Value == 8
    && sv_cheats->m_pParent != nullptr
    && sv_cheats->m_pParent->m_Value.m_nValue != 0
    && sv_noclipduringpause.m_pParent != nullptr
    && sv_noclipduringpause.m_pParent->m_Value.m_nValue != 0 )
  {
    gpGlobals->frametime = gpGlobals->interval_per_tick;
  }
  g_pGameMovement->StartTrackPredictionErrors(this: g_pGameMovement, a2: player);
  CommentarySystem_PePlayerRunCommand(player, ucmd);
  weaponselect = ucmd->weaponselect;
  if ( weaponselect != 0 )
  {
    v10 = CBaseEntity::Instance(iEnt: weaponselect);
    v11 = __RTDynamicCast(
            inptr: v10,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBaseCombatWeapon `RTTI Type Descriptor',
            isReference: 0);
    if ( v11 != nullptr )
    {
      pVehiclea = (IServerVehicle *)player->__vftable;
      v12 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)v11 + 1320))(a1: v11, a2: ucmd->weaponsubtype);
      ((void (__thiscall *)(CBasePlayer *, int))pVehiclea[428].__vftable)(a1: player, a2: v12);
    }
  }
  v13 = player->GetVehicle(this: player);
  pVehicle = v13;
  if ( ucmd->impulse != 0 && (v13 == nullptr || CBasePlayer::UsingStandardWeaponsInVehicle(this: player)) )
    player->m_nImpulse = ucmd->impulse;
  CBasePlayer::UpdateButtonState(this: player, nUserCmdButtonMask: ucmd->buttons);
  CPlayerMove::CheckMovingGround(this, player, frametime: gpGlobals->interval_per_tick);
  g_pMoveData->m_vecOldAngles = player->pl.v_angle;
  fixangle = player->pl.fixangle;
  if ( fixangle != 0 )
  {
    if ( fixangle == 2 )
    {
      v15 = ucmd->viewangles.y + player->pl.anglechange.y;
      v16 = ucmd->viewangles.z + player->pl.anglechange.z;
      player->pl.v_angle.x = ucmd->viewangles.x + player->pl.anglechange.x;
      player->pl.v_angle.y = v15;
      player->pl.v_angle.z = v16;
    }
  }
  else
  {
    player->pl.v_angle = ucmd->viewangles;
  }
  if ( CBaseEntity::PhysicsRunThink(this: player, thinkMethod: THINK_FIRE_ALL_FUNCTIONS) )
  {
    g_pGameRules->PlayerThink(this: g_pGameRules, a2: player);
    player->PreThink(this: player);
  }
  NextThinkTick = CBaseEntity::GetNextThinkTick(this: player, szContext: nullptr);
  if ( NextThinkTick > 0 && NextThinkTick <= playera->m_Value )
  {
    CBaseEntity::SetNextThink(this: player, thinkTime: -1.0, szContext: nullptr);
    player->Think(this: player);
  }
  this->SetupMove(this, a2: player, a3: ucmd, a4: moveHelper, a5: g_pMoveData);
  if ( pVehicle != nullptr )
    pVehicle->ProcessMovement(this: pVehicle, a2: player, a3: g_pMoveData);
  else
    g_pGameMovement->ProcessMovement(this: g_pGameMovement, a2: player, a3: g_pMoveData);
  this->FinishMove(this, a2: player, a3: ucmd, a4: g_pMoveData);
  gpGlobals->curtime = serverCurTime;
  gpGlobals->frametime = serverFrameTime;
  moveHelper->ProcessImpacts(this: moveHelper);
  gpGlobals->curtime = playerCurTime;
  gpGlobals->frametime = interval_per_tick;
  player->PostThink(this: player);
  g_pGameMovement->FinishTrackPredictionErrors(this: g_pGameMovement, a2: player);
  g_pGameMovement->Reset(this: g_pGameMovement);
  player->m_pCurrentCommand = nullptr;
  CBaseEntity::SetPredictionRandomSeed(cmd: nullptr);
  CBaseEntity::m_pPredictionPlayer = nullptr;
  if ( gpGlobals->frametime > 0.0 )
  {
    v18 = playera->m_Value + 1;
    if ( playera->m_Value != v18 )
    {
      v19 = playera - 971;
      if ( LOBYTE(playera[-950].m_Value) != 0 )
      {
        LOBYTE(v19[22].m_Value) |= 1u;
        playera->m_Value = v18;
      }
      else
      {
        m_Value = (CBaseEdict *)v19[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0xF2Cu);
        playera->m_Value = v18;
      }
    }
  }
}
