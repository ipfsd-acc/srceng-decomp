// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_event.cpp
// Functions: 16
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_event.h"

//------------------------------------------------------------------------------
// Address: 0x102AEE50
// Name: public: void CCSBot::OnBulletImpact(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBulletImpact(CCSBot *this, IGameEvent *event)
{
  int v3; // eax

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    if ( UTIL_PlayerByUserId(userID: v3) != this )
    {
      ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(a1: event, a2: "x", a3: 0);
      ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(a1: event, a2: "y", a3: 0);
      ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))event->GetFloat)(a1: event, a2: "z", a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AEEE0
// Name: public: void CCSBot::OnRoundEnd(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnRoundEnd(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  int TeamNumber; // eax
  CCSBot *v5; // ecx
  int v6; // eax
  bool v7; // zf

  v3 = event->GetInt(this: event, a2: "winner", a3: 0) - 2;
  if ( v3 != 0 )
  {
    if ( v3 != 1 )
      goto LABEL_7;
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    v5 = this;
    if ( TeamNumber != 3 )
      goto LABEL_4;
  }
  else
  {
    v6 = CBaseEntity::GetTeamNumber(this);
    v5 = this;
    if ( v6 == 3 )
    {
LABEL_4:
      CCSBot::DecreaseMorale(this: v5);
      goto LABEL_7;
    }
  }
  CCSBot::IncreaseMorale(this: v5);
LABEL_7:
  CSGameState::OnRoundEnd(this: &this->m_gameState, event);
  if ( !this->IsAlive(this) )
    return;
  if ( event->GetInt(this: event, a2: "winner", a3: 0) == 2 )
  {
    v7 = CBaseEntity::GetTeamNumber(this) == 2;
  }
  else
  {
    if ( event->GetInt(this: event, a2: "winner", a3: 0) != 3 )
      return;
    v7 = CBaseEntity::GetTeamNumber(this) == 3;
  }
  if ( v7 )
    BotChatterInterface::CelebrateWin(this: &this->m_chatter);
}

//------------------------------------------------------------------------------
// Address: 0x102AEFA0
// Name: public: void CCSBot::OnRoundStart(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnRoundStart(CCSBot *this, IGameEvent *event)
{
  CSGameState::OnRoundStart(this: &this->m_gameState, event);
}

//------------------------------------------------------------------------------
// Address: 0x102AEFB0
// Name: public: void CCSBot::OnHostageRescuedAll(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnHostageRescuedAll(CCSBot *this, IGameEvent *event)
{
  CSGameState::OnHostageRescuedAll(this: &this->m_gameState, event);
}

//------------------------------------------------------------------------------
// Address: 0x102AEFC0
// Name: public: void CCSBot::OnNavBlocked(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnNavBlocked(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  int v4; // ecx
  CCSBot::ConnectInfo *i; // edi

  if ( event->GetBool(this: event, a2: "blocked", a3: false) )
  {
    v3 = event->GetInt(this: event, a2: "area", a3: 0);
    if ( v3 != 0 )
    {
      v4 = 0;
      if ( this->m_pathLength > 0 )
      {
        for ( i = this->m_path; i->area == nullptr || i->area->m_id != v3; ++i )
        {
          if ( ++v4 >= this->m_pathLength )
            return;
        }
        this->m_isStopping = false;
        this->m_pathLength = 0;
        this->m_pathLadder = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF050
// Name: public: void CCSBot::OnEnteredNavArea(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnEnteredNavArea(CCSBot *this, CNavArea *newArea)
{
  newArea->m_clearedTimestamp[(CBaseEntity::GetTeamNumber(this) - 1) % 2] = gpGlobals->curtime;
  if ( (newArea->m_attributeFlags & 0x10) != 0 )
    this->m_isStopping = true;
  if ( CCSBot::IsAtEnemySpawn(this) )
    this->m_hasVisitedEnemySpawn = true;
}

//------------------------------------------------------------------------------
// Address: 0x102AF0B0
// Name: public: float CCSBot::GetTravelDistanceToPlayer(class CCSPlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetTravelDistanceToPlayer(CCSBot *this, CCSPlayer *player)
{
  edict_t *m_pPev; // eax

  if ( player == nullptr || !player->IsAlive(this: player) )
    return -1.0;
  m_pPev = player->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  return this->m_playerTravelDistance[(int)m_pPev % 64];
}

//------------------------------------------------------------------------------
// Address: 0x102AF110
// Name: private: void CCSBot::OnAudibleEvent(class IGameEvent __near *,class CBasePlayer __near *,float,enum PriorityType,bool,bool,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::OnAudibleEvent(
        CCSBot *this@<ecx>,
        float a2@<ebp>,
        IGameEvent *event,
        CCSPlayer *player,
        float range,
        PriorityType priority,
        bool isHostile,
        bool isFootstep,
        const Vector *actualOrigin)
{
  CBasePlayer *v9; // edi
  int TeamNumber; // edi
  bool v12; // zf
  const char *v13; // eax
  const char *v14; // edi
  const char *v15; // eax
  const char *v16; // eax
  float m_noiseTimestamp; // xmm0_4
  __int128 v18; // xmm0
  CNavArea *NearestNavArea; // eax
  IUniformRandomStream *v20; // ecx
  double v21; // st7
  float x; // xmm0_4
  IUniformRandomStream *v23; // ecx
  double v24; // st7
  float m_noiseTravelDistance; // xmm0_4
  float y; // [esp+10h] [ebp-58h]
  float v27; // [esp+1Ch] [ebp-4Ch]
  __int128 v28; // [esp+2Ch] [ebp-3Ch] BYREF
  Vector v29; // [esp+48h] [ebp-20h] BYREF
  Vector playerOrigin; // [esp+54h] [ebp-14h]
  void *v31; // [esp+60h] [ebp-8h]
  void *retaddr; // [esp+68h] [ebp+0h]

  playerOrigin.z = a2;
  v31 = retaddr;
  v9 = player;
  if ( player != nullptr )
  {
    if ( player->IsPlayer(this: player)
      && player->IsAlive(this: player)
      && (TeamNumber = CBaseEntity::GetTeamNumber(this: player),
          v12 = TeamNumber == CBaseEntity::GetTeamNumber(this),
          v9 = player,
          !v12)
      || (v13 = event->GetName(this: event)) == "decoy_firing"
      || _V_stricmp(s1: v13, s2: "decoy_firing") == 0 )
    {
      GetCentroid(result: &v29, player: v9);
      GetCentroid(result: (Vector *)((char *)&v28 + 4), player: this);
      if ( actualOrigin != nullptr )
        v29 = *actualOrigin;
      v27 = fsqrt(
              (float)((float)((float)(*((float *)&v28 + 2) - v29.y) * (float)(*((float *)&v28 + 2) - v29.y))
                    + (float)((float)(*((float *)&v28 + 3) - v29.z) * (float)(*((float *)&v28 + 3) - v29.z)))
            + (float)((float)(*((float *)&v28 + 1) - v29.x) * (float)(*((float *)&v28 + 1) - v29.x)));
      if ( range > v27 )
      {
        if ( CBot<CCSPlayer>::IsLocalPlayerWatchingMe(this) )
        {
          if ( cv_bot_debug.m_pParent == nullptr )
            goto LABEL_27;
          if ( cv_bot_debug.m_pParent->m_Value.m_nValue == 3 )
          {
LABEL_15:
            if ( priority == PRIORITY_HIGH )
            {
              LODWORD(playerOrigin.y) = "HIGH";
            }
            else
            {
              LODWORD(playerOrigin.y) = "MEDIUM";
              if ( priority != PRIORITY_MEDIUM )
                LODWORD(playerOrigin.y) = "LOW";
            }
            v14 = v9->GetPlayerName(this: v9);
            if ( event != nullptr )
              v15 = event->GetName(this: event);
            else
              v15 = "<no event>";
            if ( v15 != "weapon_fire" && _V_stricmp(s1: "weapon_fire", s2: v15) != 0 )
              v16 = locale;
            else
              v16 = "Weapon fire ";
            CBot<CCSPlayer>::PrintIfWatched(
              this,
              format: "Heard noise (%s from %s, pri %s, time %3.1f)\n",
              v16,
              v14,
              (const char *)LODWORD(playerOrigin.y),
              gpGlobals->curtime);
            goto LABEL_27;
          }
        }
        if ( cv_bot_debug.m_pParent != nullptr && cv_bot_debug.m_pParent->m_Value.m_nValue == 4 )
          goto LABEL_15;
LABEL_27:
        m_noiseTimestamp = this->m_noiseTimestamp;
        if ( m_noiseTimestamp <= 0.0
          || (float)(gpGlobals->curtime - m_noiseTimestamp) >= 3.0
          || priority >= this->m_noisePriority
          && (v18 = 0,
              *(float *)&v18 = fsqrt(
                                 (float)((float)((float)(*((float *)&v28 + 2) - this->m_noisePosition.y)
                                               * (float)(*((float *)&v28 + 2) - this->m_noisePosition.y))
                                       + (float)((float)(*((float *)&v28 + 3) - this->m_noisePosition.z)
                                               * (float)(*((float *)&v28 + 3) - this->m_noisePosition.z)))
                               + (float)((float)(*((float *)&v28 + 1) - this->m_noisePosition.x)
                                       * (float)(*((float *)&v28 + 1) - this->m_noisePosition.x))),
              v28 = v18,
              v27 < *(float *)&v18) )
        {
          NearestNavArea = CNavMesh::GetNearestNavArea(
                             this: TheNavMesh,
                             pos: &v29,
                             anyZ: false,
                             maxDist: 10000.0,
                             checkLOS: false,
                             checkGround: true);
          if ( NearestNavArea != nullptr )
          {
            this->m_noiseArea = NearestNavArea;
            this->m_noisePriority = priority;
            playerOrigin.y = (float)(v27 * 400.0) * 0.00050000002;
            LODWORD(playerOrigin.x) = LODWORD(playerOrigin.y) ^ _mask__NegFloat_;
            v21 = _RandomFloat(
                    this: v20,
                    a2: COERCE_FLOAT(LODWORD(playerOrigin.y) ^ _mask__NegFloat_),
                    a3: playerOrigin.y);
            y = playerOrigin.y;
            x = playerOrigin.x;
            this->m_noisePosition.x = v21 + v29.x;
            v24 = _RandomFloat(this: v23, a2: x, a3: y);
            this->m_noisePosition.y = v24 + v29.y;
            this->m_noiseTravelDistance = CCSBot::GetTravelDistanceToPlayer(this, player);
            CNavArea::GetClosestPointOnArea(
              this: this->m_noiseArea,
              pPos: &this->m_noisePosition,
              close: &this->m_noisePosition);
            m_noiseTravelDistance = this->m_noiseTravelDistance;
            this->m_noiseTimestamp = gpGlobals->curtime;
            if ( m_noiseTravelDistance < 1000.0 && m_noiseTravelDistance > 0.0 )
              CCSBot::BecomeAlert(this);
          }
          else
          {
            CBot<CCSPlayer>::PrintIfWatched(this, format: "  *** Noise occurred off the nav mesh - ignoring!\n");
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF4A0
// Name: public: void CCSBot::OnMolotovDetonate(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnMolotovDetonate(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 99999.0,
        priority: PRIORITY_HIGH,
        isHostile: true,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF500
// Name: public: void CCSBot::OnFlashbangDetonate(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnFlashbangDetonate(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1000.0,
        priority: PRIORITY_LOW,
        isHostile: true,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF560
// Name: public: void CCSBot::OnDecoyFiring(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnDecoyFiring(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // edi
  int v5; // eax
  int (__thiscall *GetInt)(IGameEvent *, const char *, int); // edx
  int v7; // eax
  int (__thiscall *v8)(IGameEvent *, const char *, int); // edx
  Vector decoySpot; // [esp+40h] [ebp-Ch] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
    {
      v5 = event->GetInt(this: event, a2: "x", a3: 0);
      GetInt = event->GetInt;
      decoySpot.x = (float)v5;
      v7 = GetInt(this: event, a2: "y", a3: 0);
      v8 = event->GetInt;
      decoySpot.y = (float)v7;
      decoySpot.z = (float)v8(this: event, a2: "z", a3: 0);
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 99999.0,
        priority: PRIORITY_HIGH,
        isHostile: true,
        isFootstep: false,
        actualOrigin: &decoySpot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF620
// Name: public: void CCSBot::OnGrenadeBounce(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnGrenadeBounce(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 500.0,
        priority: PRIORITY_LOW,
        isHostile: true,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF680
// Name: public: void CCSBot::OnBreakProp(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnBreakProp(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1100.0,
        priority: PRIORITY_MEDIUM,
        isHostile: true,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF6E0
// Name: public: void CCSBot::OnDoorMoving(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnDoorMoving(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1100.0,
        priority: PRIORITY_MEDIUM,
        isHostile: false,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF740
// Name: public: void CCSBot::OnHostageFollows(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnHostageFollows(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  CCSPlayer *v5; // edi
  Vector myOrigin; // [esp+28h] [ebp-18h] BYREF
  Vector playerOrigin; // [esp+34h] [ebp-Ch] BYREF
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    v5 = v4;
    if ( v4 != this && v4 != nullptr && CBot<CCSPlayer>::IsEnemy(this, ent: v4) )
    {
      GetCentroid(result: &playerOrigin, player: v5);
      GetCentroid(result: &myOrigin, player: this);
      if ( CBaseEntity::GetTeamNumber(this) == 2
        && (float)((float)((float)((float)(playerOrigin.x - myOrigin.x) * (float)(playerOrigin.x - myOrigin.x))
                         + (float)((float)(playerOrigin.y - myOrigin.y) * (float)(playerOrigin.y - myOrigin.y)))
                 + (float)((float)(playerOrigin.z - myOrigin.z) * (float)(playerOrigin.z - myOrigin.z))) <= 1440000.0 )
      {
        BotChatterInterface::HostagesBeingTaken(this: &this->m_chatter);
        if ( CSGameState::GetNearestVisibleFreeHostage(this: &this->m_gameState) == nullptr
          && this->m_task != GUARD_HOSTAGE_RESCUE_ZONE
          && CCSBot::GuardRandomZone(this, range: 500.0) != 0 )
        {
          this->m_task = GUARD_HOSTAGE_RESCUE_ZONE;
          this->m_taskEntity.m_Index = -1;
          CCSBot::SetDisposition(this, disposition: OPPORTUNITY_FIRE);
          CBot<CCSPlayer>::PrintIfWatched(this, format: "Trying to beat them to an escape zone!\n");
        }
        CCSBot::OnAudibleEvent(
          this,
          a2: COERCE_FLOAT(&savedregs),
          event,
          player: v5,
          range: 1200.0,
          priority: PRIORITY_MEDIUM,
          isHostile: false,
          isFootstep: false,
          actualOrigin: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AF890
// Name: __CreateCServerGameTagsIServerGameTags_interface_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_16()
{
  return &_g_CServerGameTags_singleton_16;
}
