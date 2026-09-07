// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_statemachine.cpp
// Functions: 34
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_statemachine.h"

//------------------------------------------------------------------------------
// Address: 0x102C08B0
// Name: public: struct CCSNavPath::PathSegment const __near * CCSNavPath::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
CCSNavPath *__thiscall CCSNavPath::operator[](CCSNavPath *this, int i)
{
  if ( i < 0 || i >= this->m_segmentCount )
    return nullptr;
  else
    return (CCSNavPath *)((char *)this + 24 * i);
}

//------------------------------------------------------------------------------
// Address: 0x102C08E0
// Name: public: void CCSBot::OpenDoor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OpenDoor(CCSBot *this, CBaseEntity *door)
{
  void (__thiscall *OnEnter)(struct OpenDoorState *, CCSBot *); // eax

  OpenDoorState::SetDoor(this: &this->m_openDoorState, door);
  OnEnter = this->m_openDoorState.OnEnter;
  this->m_isOpeningDoor = true;
  OnEnter(this: &this->m_openDoorState, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0920
// Name: public: bool CCSBot::IsAttacking(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsAttacking(CCSBot *this)
{
  return this->m_isAttacking;
}

//------------------------------------------------------------------------------
// Address: 0x102C0930
// Name: public: bool CCSBot::IsEscapingFromBomb(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsEscapingFromBomb(CCSBot *this)
{
  return this->m_state == &this->m_escapeFromBombState;
}

//------------------------------------------------------------------------------
// Address: 0x102C0940
// Name: public: bool CCSBot::IsEscapingFromFlames(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsEscapingFromFlames(CCSBot *this)
{
  return this->m_state == &this->m_escapeFromFlamesState;
}

//------------------------------------------------------------------------------
// Address: 0x102C0950
// Name: public: bool CCSBot::IsDefusingBomb(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsDefusingBomb(CCSBot *this)
{
  return this->m_state == &this->m_defuseBombState;
}

//------------------------------------------------------------------------------
// Address: 0x102C0960
// Name: public: bool CCSBot::IsHiding(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsHiding(CCSBot *this)
{
  return this->m_state == &this->m_hideState;
}

//------------------------------------------------------------------------------
// Address: 0x102C0970
// Name: public: bool CCSBot::IsAtHidingSpot(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsAtHidingSpot(CCSBot *this)
{
  return this->m_state == &this->m_hideState && this->m_hideState.m_isAtSpot;
}

//------------------------------------------------------------------------------
// Address: 0x102C0990
// Name: public: bool CCSBot::IsHunting(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsHunting(CCSBot *this)
{
  return this->m_state == &this->m_huntState;
}

//------------------------------------------------------------------------------
// Address: 0x102C09A0
// Name: public: bool CCSBot::IsBuying(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsBuying(CCSBot *this)
{
  return this->m_state == &this->m_buyState;
}

//------------------------------------------------------------------------------
// Address: 0x102C09B0
// Name: public: bool CCSBot::IsInvestigatingNoise(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsInvestigatingNoise(CCSBot *this)
{
  return this->m_state == &this->m_investigateNoiseState;
}

//------------------------------------------------------------------------------
// Address: 0x102C09C0
// Name: public: void CCSBot::Attack(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Attack(CCSBot *this, CCSPlayer *victim)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  const Vector *AbsOrigin; // eax
  IUniformRandomStream *v5; // ecx
  void (__thiscall *OnEnter)(struct AttackState *, CCSBot *); // edx
  Vector *Centroid; // eax
  float v8; // xmm0_4
  IUniformRandomStream *v9; // ecx
  double v10; // st7
  Vector result; // [esp+14h] [ebp-30h] BYREF
  QAngle idealAngle; // [esp+20h] [ebp-24h] BYREF
  Vector toEnemy; // [esp+2Ch] [ebp-18h] BYREF
  Vector victimOrigin; // [esp+38h] [ebp-Ch] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  if ( victim != nullptr && (cv_bot_zombie.m_pParent == nullptr || cv_bot_zombie.m_pParent->m_Value.m_nValue == 0) )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( ActiveWeapon == nullptr || !ActiveWeapon->m_bInReload.m_Value )
    {
      CCSBot::SetBotEnemy(this, enemy: victim);
      if ( !this->m_isAttacking )
      {
        if ( CCSBot::IsUsingGrenade(this) )
        {
          AbsOrigin = CBaseEntity::GetAbsOrigin(this: victim);
          CCSBot::ThrowGrenade(this, target: AbsOrigin);
        }
        else
        {
          this->m_attackState.m_crouchAndHold = CCSBot::IsAtHidingSpot(this)
                                             && _RandomFloat(this: v5, a2: 0.0, a3: 100.0) < 60.0;
          OnEnter = this->m_attackState.OnEnter;
          this->m_isAttacking = true;
          OnEnter(this: &this->m_attackState, a2: this);
          GetCentroid(result: &victimOrigin, player: victim);
          this->m_lastEnemyPosition = victimOrigin;
          this->m_lastSawEnemyTimestamp = gpGlobals->curtime;
          this->m_aimSpreadTimestamp = gpGlobals->curtime;
          Centroid = GetCentroid(&result, player: this);
          toEnemy.x = victimOrigin.x - Centroid->x;
          toEnemy.y = victimOrigin.y - Centroid->y;
          toEnemy.z = victimOrigin.z - Centroid->z;
          VectorAngles(forward: &toEnemy, angles: &idealAngle);
          for ( LODWORD(v8) = COERCE_UNSIGNED_INT(this->m_lookYaw - idealAngle.y) & _mask__AbsFloat_;
                v8 > 180.0;
                v8 = v8 - 360.0 )
          {
            ;
          }
          if ( v8 < 0.0 )
            LODWORD(v8) ^= _mask__NegFloat_;
          CCSBot::SetAimOffset(
            this,
            a2: (int)&savedregs,
            a3: (int)victim,
            accuracy: this->m_profile->m_skill / (float)((float)(v8 * 0.0055555557) + 1.0));
          v10 = _RandomFloat(this: v9, a2: (float)(v8 * 0.0055555557) + 0.25, a3: 1.5) + gpGlobals->curtime;
          this->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
          this->m_lookAtDesc = nullptr;
          this->m_aimOffsetTimestamp = v10;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0C00
// Name: public: void CCSBot::StopFollowing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::StopFollowing(CCSBot *this)
{
  this->m_isFollowing = false;
  this->m_leader.m_Index = -1;
  this->m_allowAutoFollowTime = gpGlobals->curtime + 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C0C30
// Name: public: float CCSBot::GetHidingTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetHidingTime(CCSBot *this)
{
  if ( this->m_state != &this->m_hideState )
    return 0.0;
  if ( this->m_hideState.m_isAtSpot )
    return this->m_hideState.m_duration
         - (this->m_hideState.m_hideTimer.m_timestamp.m_Value
          - IntervalTimer::Now(this: (CEffectsServer *)&this->m_hideState.m_hideTimer));
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102C0EA0
// Name: public: void CCSBot::StopAttacking(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::StopAttacking(CCSBot *this)
{
  bool v2; // zf

  CBot<CCSPlayer>::PrintIfWatched(this, format: "ATTACK END\n");
  this->m_attackState.OnExit(this: &this->m_attackState, a2: this);
  v2 = !this->m_isFollowing;
  this->m_isAttacking = false;
  if ( !v2 )
    CCSBot::Idle(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0EE0
// Name: private: void CCSBot::SetState(class BotState __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetState(CCSBot *this, BotState *state)
{
  BotState *m_state; // ecx
  const char *v4; // ebx
  const char *v5; // eax
  const char *v6; // eax
  bool v7; // zf
  BotState *v8; // ecx
  const char *v9; // [esp-8h] [ebp-14h]
  const char *v10; // [esp-4h] [ebp-10h]

  m_state = this->m_state;
  if ( m_state != nullptr )
    v4 = m_state->GetName(this: m_state);
  else
    v4 = "NULL";
  v5 = state->GetName(this: state);
  v6 = (const char *)((int (__thiscall *)(CCSBot *, const char *, const char *))this->GetPlayerName)(
                       a1: this,
                       a2: v4,
                       a3: v5);
  CBot<CCSPlayer>::PrintIfWatched(this, format: "%s: SetState: %s -> %s\n", v6, v9, v10);
  if ( this->m_isAttacking )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "ATTACK END\n");
    this->m_attackState.OnExit(this: &this->m_attackState, a2: this);
    v7 = !this->m_isFollowing;
    this->m_isAttacking = false;
    if ( !v7 )
      CCSBot::Idle(this);
  }
  v8 = this->m_state;
  if ( v8 != nullptr )
    v8->OnExit(this: v8, a2: this);
  state->OnEnter(this: state, a2: this);
  this->m_state = state;
  this->m_stateTimestamp = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102C0FB0
// Name: public: void CCSBot::Idle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Idle(CCSBot *this)
{
  this->m_task = SEEK_AND_DESTROY;
  this->m_taskEntity.m_Index = -1;
  CCSBot::SetState(this, state: &this->m_idleState);
}

//------------------------------------------------------------------------------
// Address: 0x102C0FE0
// Name: public: void CCSBot::EscapeFromBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::EscapeFromBomb(CCSBot *this)
{
  this->m_task = ESCAPE_FROM_BOMB;
  this->m_taskEntity.m_Index = -1;
  CCSBot::SetState(this, state: &this->m_escapeFromBombState);
}

//------------------------------------------------------------------------------
// Address: 0x102C1010
// Name: public: void CCSBot::EscapeFromFlames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::EscapeFromFlames(CCSBot *this)
{
  this->m_task = ESCAPE_FROM_FLAMES;
  this->m_taskEntity.m_Index = -1;
  CCSBot::SetState(this, state: &this->m_escapeFromFlamesState);
}

//------------------------------------------------------------------------------
// Address: 0x102C1040
// Name: public: void CCSBot::Follow(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Follow(CCSBot *this, CCSPlayer *player)
{
  unsigned int m_Index; // eax
  CCSPlayer *m_pEntity; // ecx

  if ( player != nullptr )
  {
    if ( !this->m_isFollowing
      || ((m_Index = this->m_leader.m_Index) == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        ? (m_pEntity = nullptr)
        : (m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity),
          m_pEntity != player) )
    {
      this->m_followTimestamp = gpGlobals->curtime;
    }
    this->m_isFollowing = true;
    this->m_leader.m_Index = player->GetRefEHandle(this: player)->m_Index;
    this->m_task = FOLLOW;
    this->m_taskEntity.m_Index = -1;
    this->m_followState.m_leader.m_Index = player->GetRefEHandle(this: player)->m_Index;
    CCSBot::SetState(this, state: &this->m_followState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C10F0
// Name: public: void CCSBot::ContinueFollowing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ContinueFollowing(CCSBot *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  this->m_task = FOLLOW;
  this->m_taskEntity.m_Index = -1;
  m_Index = this->m_leader.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
    this->m_followState.m_leader.m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  else
    this->m_followState.m_leader.m_Index = -1;
  CCSBot::SetState(this, state: &this->m_followState);
}

//------------------------------------------------------------------------------
// Address: 0x102C1170
// Name: public: void CCSBot::UseEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UseEntity(CCSBot *this, CBaseEntity *entity)
{
  if ( entity != nullptr )
    this->m_useEntityState.m_entity.m_Index = entity->GetRefEHandle(this: entity)->m_Index;
  else
    this->m_useEntityState.m_entity.m_Index = -1;
  CCSBot::SetState(this, state: &this->m_useEntityState);
}

//------------------------------------------------------------------------------
// Address: 0x102C11C0
// Name: public: void CCSBot::Hide(class CNavArea __near *,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Hide(
        CCSBot *this,
        CCSNavArea *searchFromArea,
        float duration,
        float hideRange,
        bool holdPosition)
{
  CCSNavArea *m_lastKnownArea; // edi
  float z; // xmm0_4
  Vector *Centroid; // eax
  bool IsSniper; // al
  Vector *NearbyHidingSpot; // eax
  Vector result; // [esp+18h] [ebp-24h] BYREF
  Vector useSpot; // [esp+24h] [ebp-18h] BYREF
  Vector sourcePos; // [esp+30h] [ebp-Ch] BYREF

  m_lastKnownArea = searchFromArea;
  this->m_isStopping = false;
  this->m_pathLength = 0;
  this->m_pathLadder = nullptr;
  if ( searchFromArea != nullptr )
  {
    sourcePos.x = searchFromArea->m_center.x;
    sourcePos.y = searchFromArea->m_center.y;
    z = searchFromArea->m_center.z;
  }
  else
  {
    m_lastKnownArea = this->m_lastKnownArea;
    Centroid = GetCentroid(&result, player: this);
    sourcePos.x = Centroid->x;
    sourcePos.y = Centroid->y;
    z = Centroid->z;
  }
  sourcePos.z = z;
  if ( m_lastKnownArea == nullptr )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Hide from area is NULL.\n");
LABEL_6:
    this->m_task = SEEK_AND_DESTROY;
    this->m_taskEntity.m_Index = -1;
    CCSBot::SetState(this, state: &this->m_idleState);
    return;
  }
  this->m_hideState.m_range = hideRange;
  this->m_hideState.m_searchFromArea = m_lastKnownArea;
  this->m_hideState.m_duration = duration;
  this->m_hideState.m_isHoldingPosition = holdPosition;
  IsSniper = CCSBot::IsSniper(this);
  NearbyHidingSpot = FindNearbyHidingSpot(
                       me: this,
                       pos: &sourcePos,
                       maxRange: hideRange,
                       isSniper: IsSniper,
                       useNearest: false);
  if ( NearbyHidingSpot == nullptr )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "No available hiding spots.\n");
    NearbyHidingSpot = GetCentroid(&result, player: this);
  }
  useSpot = *NearbyHidingSpot;
  this->m_hideState.m_hidingSpot = useSpot;
  if ( CCSBot::ComputePath(this, goal: &useSpot, route: FASTEST_ROUTE) == 0 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Can't pathfind to hiding spot\n");
    goto LABEL_6;
  }
  CCSBot::SetState(this, state: &this->m_hideState);
}

//------------------------------------------------------------------------------
// Address: 0x102C1340
// Name: public: void CCSBot::Hide(class Vector const __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Hide(CCSBot *this, const Vector *hidingSpot, float duration, bool holdPosition)
{
  CNavArea *NearestNavArea; // eax

  NearestNavArea = CNavMesh::GetNearestNavArea(
                     this: TheNavMesh,
                     pos: hidingSpot,
                     anyZ: false,
                     maxDist: 10000.0,
                     checkLOS: false,
                     checkGround: true);
  if ( NearestNavArea != nullptr )
  {
    this->m_hideState.m_range = 750.0;
    this->m_hideState.m_isHoldingPosition = holdPosition;
    this->m_isStopping = false;
    this->m_pathLength = 0;
    this->m_pathLadder = nullptr;
    this->m_hideState.m_searchFromArea = NearestNavArea;
    this->m_hideState.m_duration = duration;
    this->m_hideState.m_hidingSpot = *hidingSpot;
    if ( CCSBot::ComputePath(this, goal: hidingSpot, route: FASTEST_ROUTE) != 0 )
    {
      CCSBot::SetState(this, state: &this->m_hideState);
    }
    else
    {
      CBot<CCSPlayer>::PrintIfWatched(this, format: "Can't pathfind to hiding spot\n");
      this->m_task = SEEK_AND_DESTROY;
      this->m_taskEntity.m_Index = -1;
      CCSBot::SetState(this, state: &this->m_idleState);
    }
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Hiding spot off nav mesh\n");
    this->m_task = SEEK_AND_DESTROY;
    this->m_taskEntity.m_Index = -1;
    CCSBot::SetState(this, state: &this->m_idleState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1450
// Name: public: bool CCSBot::TryToHide(class CNavArea __near *,float,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::TryToHide(
        CCSBot *this,
        CCSNavArea *searchFromArea,
        float duration,
        float hideRange,
        bool holdPosition,
        bool useNearest)
{
  CCSNavArea *m_lastKnownArea; // edi
  float z; // xmm0_4
  Vector *Centroid; // eax
  bool IsSniper; // al
  const Vector *NearbyHidingSpot; // eax
  Vector v13; // [esp+14h] [ebp-18h] BYREF
  Vector sourcePos; // [esp+20h] [ebp-Ch] BYREF

  m_lastKnownArea = searchFromArea;
  if ( searchFromArea != nullptr )
  {
    sourcePos.x = searchFromArea->m_center.x;
    sourcePos.y = searchFromArea->m_center.y;
    z = searchFromArea->m_center.z;
  }
  else
  {
    m_lastKnownArea = this->m_lastKnownArea;
    Centroid = GetCentroid(result: &v13, player: this);
    sourcePos.x = Centroid->x;
    sourcePos.y = Centroid->y;
    z = Centroid->z;
  }
  sourcePos.z = z;
  if ( m_lastKnownArea != nullptr )
  {
    this->m_hideState.m_range = hideRange;
    this->m_hideState.m_isHoldingPosition = holdPosition;
    this->m_hideState.m_searchFromArea = m_lastKnownArea;
    this->m_hideState.m_duration = duration;
    IsSniper = CCSBot::IsSniper(this);
    NearbyHidingSpot = FindNearbyHidingSpot(
                         me: this,
                         pos: &sourcePos,
                         maxRange: hideRange,
                         isSniper: IsSniper,
                         useNearest);
    if ( NearbyHidingSpot != nullptr )
    {
      this->m_hideState.m_hidingSpot.x = NearbyHidingSpot->x;
      this->m_hideState.m_hidingSpot.y = NearbyHidingSpot->y;
      this->m_hideState.m_hidingSpot.z = NearbyHidingSpot->z;
      if ( CCSBot::ComputePath(this, goal: NearbyHidingSpot, route: FASTEST_ROUTE) != 0 )
      {
        CCSBot::SetState(this, state: &this->m_hideState);
        return 1;
      }
      else
      {
        CBot<CCSPlayer>::PrintIfWatched(this, format: "Can't pathfind to hiding spot\n");
        return 0;
      }
    }
    else
    {
      CBot<CCSPlayer>::PrintIfWatched(this, format: "No available hiding spots.\n");
      return 0;
    }
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Hide from area is NULL.\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C1590
// Name: public: bool CCSBot::TryToRetreat(float,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall CCSBot::TryToRetreat(CCSBot *this, float maxRange, float duration)
{
  const Vector *NearbyRetreatSpot; // edi
  IUniformRandomStream *v5; // ecx

  NearbyRetreatSpot = FindNearbyRetreatSpot(me: this, maxRange);
  if ( NearbyRetreatSpot == nullptr )
    return 0;
  CCSBot::IgnoreEnemies(this, duration: 10.0);
  if ( duration < 0.0 )
    duration = _RandomFloat(this: v5, a2: 3.0, a3: 15.0);
  this->StandUp(this);
  this->Run(this);
  CCSBot::Hide(this, hidingSpot: NearbyRetreatSpot, duration, holdPosition: false);
  CBot<CCSPlayer>::PrintIfWatched(this, format: "Retreating to a safe spot!\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C1650
// Name: public: void CCSBot::Hunt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Hunt(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_huntState);
}

//------------------------------------------------------------------------------
// Address: 0x102C1660
// Name: public: void CCSBot::MoveTo(class Vector const __near &,enum RouteType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::MoveTo(CCSBot *this, const Vector *pos, RouteType route)
{
  this->m_moveToState.m_goalPosition = *pos;
  this->m_moveToState.m_routeType = route;
  CCSBot::SetState(this, state: &this->m_moveToState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16A0
// Name: public: void CCSBot::PlantBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::PlantBomb(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_plantBombState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16B0
// Name: public: void CCSBot::FetchBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::FetchBomb(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_fetchBombState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16C0
// Name: public: void CCSBot::DefuseBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::DefuseBomb(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_defuseBombState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16D0
// Name: public: void CCSBot::InvestigateNoise(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::InvestigateNoise(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_investigateNoiseState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16E0
// Name: public: void CCSBot::Buy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Buy(CCSBot *this)
{
  CCSBot::SetState(this, state: &this->m_buyState);
}

//------------------------------------------------------------------------------
// Address: 0x102C16F0
// Name: public: bool CCSBot::MoveToInitialEncounter(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::MoveToInitialEncounter(CCSBot *this)
{
  int TeamNumber; // edi
  CBaseEntity *RandomSpawn; // eax
  CBaseEntity *v4; // esi
  unsigned int v6; // eax
  const Vector *v7; // eax
  int m_segmentCount; // edx
  int v9; // esi
  CCSNavPath *v10; // ecx
  CCSNavPath *v11; // eax
  float v12; // xmm0_4
  CCSNavPath *v13; // eax
  const CNavArea **p_area; // eax
  CCSNavPath::PathSegment *v15; // eax
  int v16; // ebx
  CCSNavPath::PathSegment *v17; // eax
  int p_m_center; // edi
  bool IsSniper; // al
  CCSBot *v20; // edi
  const HidingSpot *InitialEncounterSpot; // eax
  CCSNavPath::PathSegment *v22; // ecx
  float v23; // xmm1_4
  const Vector *v24; // [esp-4h] [ebp-1838h]
  CCSNavPath v25; // [esp+18h] [ebp-181Ch] BYREF
  int v26; // [esp+181Ch] [ebp-18h]
  int v27; // [esp+1820h] [ebp-14h]
  int v28; // [esp+1824h] [ebp-10h]
  CCSBot *v29; // [esp+1828h] [ebp-Ch]
  PathCost costFunc; // [esp+182Ch] [ebp-8h] BYREF
  int savedregs; // [esp+1834h] [ebp+0h] BYREF

  v29 = this;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  v26 = TeamNumber;
  v28 = (TeamNumber == 2) + 2;
  RandomSpawn = CCSBotManager::GetRandomSpawn(this: (CCSBotManager *)TheBots, team: v28);
  v4 = RandomSpawn;
  if ( RandomSpawn != nullptr )
  {
    v25.m_segmentCount = 0;
    v6 = (unsigned int)RandomSpawn->m_iEFlags >> 11;
    costFunc.m_bot = this;
    costFunc.m_route = FASTEST_ROUTE;
    if ( (v6 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4, a2: (int)&savedregs);
    v7 = this->WorldSpaceCenter(this);
    CCSNavPath::Compute<PathCost>(this: &v25, start: v7, goal: &v4->m_vecAbsOrigin, &costFunc);
    m_segmentCount = v25.m_segmentCount;
    if ( v25.m_segmentCount > 0 )
    {
      v9 = 0;
      v27 = 4 * (TeamNumber % 2) + 212;
      costFunc.m_route = 4 * (v28 % 2) + 212;
      v10 = &v25;
      do
      {
        if ( v9 < 0 || v9 >= v25.m_segmentCount )
          v11 = nullptr;
        else
          v11 = v10;
        v12 = *(float *)((char *)&v11->m_path[0].area->__vftable + v27);
        if ( v9 < 0 || v9 >= v25.m_segmentCount )
          v13 = nullptr;
        else
          v13 = v10;
        if ( v12 > *(float *)((char *)&v13->m_path[0].area->__vftable + costFunc.m_route) )
          break;
        ++v9;
        v10 = (CCSNavPath *)((char *)v10 + 24);
      }
      while ( v9 < v25.m_segmentCount );
      if ( v9 == v25.m_segmentCount )
      {
        CBot<CCSPlayer>::PrintIfWatched(this, format: "MoveToInitialEncounter: Can't find battlefront!\n");
        return 0;
      }
      else
      {
        if ( v9 < 0 || v9 >= v25.m_segmentCount )
          p_area = nullptr;
        else
          p_area = (const CNavArea **)&v25.m_path[v9].area;
        this->m_initialEncounterArea = *p_area;
        if ( v9 < 0 || v9 >= m_segmentCount )
          v15 = nullptr;
        else
          v15 = &v25.m_path[v9];
        v16 = 4 * (v28 % 2) + 212;
        costFunc.m_route = *(RouteType *)((char *)&v15->area->__vftable + v16);
        if ( v9 < 0 || v9 >= m_segmentCount )
          v17 = nullptr;
        else
          v17 = &v25.m_path[v9];
        p_m_center = (int)&v17->area->m_center;
        IsSniper = CCSBot::IsSniper(this: v29);
        v24 = (const Vector *)p_m_center;
        v20 = v29;
        InitialEncounterSpot = FindInitialEncounterSpot(
                                 me: v29,
                                 searchOrigin: v24,
                                 enemyArriveTime: *(float *)&costFunc.m_route,
                                 maxRange: 1500.0,
                                 isSniper: IsSniper);
        if ( InitialEncounterSpot != nullptr )
        {
          if ( v9 < 0 || v9 >= v25.m_segmentCount )
            v22 = nullptr;
          else
            v22 = &v25.m_path[v9];
          v23 = *(float *)((char *)&v22->area->__vftable + v16)
              - InitialEncounterSpot->m_area->m_earliestOccupyTime[v26 % 2];
          if ( (float)((float)(v20->m_profile->m_aggression * 4.0) + 3.0) > v23 )
            v23 = (float)(v20->m_profile->m_aggression * 4.0) + 3.0;
          CCSBot::Hide(this: v20, hidingSpot: &InitialEncounterSpot->m_pos, duration: v23, holdPosition: false);
          return 1;
        }
        else
        {
          CBot<CCSPlayer>::PrintIfWatched(this: v20, format: "MoveToInitialEncounter: Can't find a hiding spot\n");
          return 0;
        }
      }
    }
    else
    {
      CBot<CCSPlayer>::PrintIfWatched(this, format: "MoveToInitialEncounter: Pathfind failed.\n");
      return 0;
    }
  }
  else
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "MoveToInitialEncounter: No enemy spawn points?\n");
    return 0;
  }
}
