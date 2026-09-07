// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_playermove.cpp
// Functions: 3
// ============================================================

#include "game\server\cstrike15\cs_playermove.h"

//------------------------------------------------------------------------------
// Address: 0x10297850
// Name: class CPlayerMove __near * PlayerMove(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayerMove *__cdecl PlayerMove()
{
  return &g_PlayerMove;
}

//------------------------------------------------------------------------------
// Address: 0x10297860
// Name: public: virtual void CCSPlayerMove::SetupMove(class CBasePlayer __near *,class CUserCmd __near *,class IMoveHelper __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerMove::SetupMove(
        CCSPlayerMove *this,
        CBasePlayer *player,
        CUserCmd *ucmd,
        IMoveHelper *pHelper,
        CMoveData *move)
{
  IServerVehicle *v6; // ecx

  CBasePlayer::AvoidPhysicsProps(this: player, pCmd: ucmd);
  CPlayerMove::SetupMove(this, player, ucmd, pHelper, move);
  v6 = player->GetVehicle(this: player);
  if ( v6 != nullptr && gpGlobals->frametime != 0.0 )
    v6->SetupMove(this: v6, a2: player, a3: ucmd, a4: pHelper, a5: move);
}

//------------------------------------------------------------------------------
// Address: 0x102978D0
// Name: public: virtual void CCSPlayerMove::FinishMove(class CBasePlayer __near *,class CUserCmd __near *,class CMoveData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayerMove::FinishMove(CCSPlayerMove *this, CBasePlayer *player, CUserCmd *ucmd, CMoveData *move)
{
  IServerVehicle *v4; // ecx
  void *v5; // edi
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  CBaseEdict *v8; // ecx

  CPlayerMove::FinishMove(this, player, ucmd, move);
  v4 = player->GetVehicle(this: player);
  if ( v4 != nullptr && gpGlobals->frametime != 0.0 )
    v4->FinishMove(this: v4, a2: player, a3: ucmd, a4: move);
  if ( player->IsPlayer(this: player) )
    v5 = __RTDynamicCast(
           inptr: player,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CCSPlayer `RTTI Type Descriptor',
           isReference: 0);
  else
    v5 = nullptr;
  if ( *((_BYTE *)v5 + 6000) != 0 )
  {
    if ( *((_BYTE *)v5 + 84) != 0 )
    {
      *((_BYTE *)v5 + 88) |= 1u;
    }
    else
    {
      v6 = *((CBaseEdict **)v5 + 6);
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1770u);
    }
    *((_BYTE *)v5 + 6000) = 0;
  }
  *((_BYTE *)v5 + 6008) = 0;
  if ( *((_BYTE *)v5 + 6001) != 0 )
  {
    if ( *((_BYTE *)v5 + 84) != 0 )
    {
      *((_BYTE *)v5 + 88) |= 1u;
    }
    else
    {
      v7 = *((CBaseEdict **)v5 + 6);
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x1771u);
    }
    *((_BYTE *)v5 + 6001) = 0;
  }
  if ( *((_BYTE *)v5 + 6012) != 0 )
  {
    if ( *((_BYTE *)v5 + 84) != 0 )
    {
      *((_BYTE *)v5 + 88) |= 1u;
      *((_BYTE *)v5 + 6012) = 0;
    }
    else
    {
      v8 = *((CBaseEdict **)v5 + 6);
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0x177Cu);
      *((_BYTE *)v5 + 6012) = 0;
    }
  }
}
