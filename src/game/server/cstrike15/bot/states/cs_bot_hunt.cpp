// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_hunt.cpp
// Functions: 4
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_hunt.h"

//------------------------------------------------------------------------------
// Address: 0x102D59B0
// Name: public: bool CCSBotManager::IsTimeToPlantBomb(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBotManager::IsTimeToPlantBomb(CCSBotManager *this)
{
  return gpGlobals->curtime >= this->m_earliestBombPlantTimestamp;
}

//------------------------------------------------------------------------------
// Address: 0x102D59D0
// Name: public: virtual void HuntState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HuntState::OnEnter(HuntState *this, CCSBot *me)
{
  if ( CCSBot::IsUsingKnife(this: me) && CCSBot::IsWellPastSafe(this: me) && !CCSBot::IsHurrying(this: me) )
    me->Walk(this: me);
  else
    me->Run(this: me);
  me->StandUp(this: me);
  CCSBot::SetDisposition(this: me, disposition: ENGAGE_AND_INVESTIGATE);
  me->m_task = SEEK_AND_DESTROY;
  me->m_taskEntity.m_Index = -1;
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D5A50
// Name: public: virtual void HuntState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall HuntState::OnUpdate(HuntState *this, CCSBot *me)
{
  float v3; // xmm0_4
  HuntState *v4; // edi
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // eax
  float curtime; // xmm0_4
  const Vector *BombPosition; // ebx
  CCSNavArea *NavArea; // eax
  CBaseEntity *LooseBomb; // eax
  CHostage *NearestVisibleFreeHostage; // eax
  const Vector *Centroid; // eax
  CCSNavArea *NearestNavArea; // eax
  CCSNavArea *v13; // edi
  int v14; // ebx
  IUniformRandomStream *v15; // ecx
  int TeamNumber; // eax
  CBaseEntity *RandomSpawn; // eax
  const Vector *v18; // eax
  CNavArea *v19; // edi
  int v20; // eax
  int v21; // eax
  int i; // ecx
  CNavArea *m_huntArea; // eax
  Extent extent; // [esp+1Ch] [ebp-20h] BYREF
  float oldest; // [esp+34h] [ebp-8h]
  HuntState *v26; // [esp+38h] [ebp-4h]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF
  int areaCount; // [esp+44h] [ebp+8h]

  v3 = gpGlobals->curtime - me->m_stateTimestamp;
  v4 = this;
  v26 = this;
  if ( v3 > 30.0 )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Giving up hunting.\n");
    me->m_isRogue = false;
    CCSBot::Idle(this: me);
    return;
  }
  m_pMemory = TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory;
  if ( m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
  {
    if ( CBaseEntity::GetTeamNumber(this: me) == 2 )
    {
      if ( !CCSPlayer::HasC4(this: me)
        || (curtime = gpGlobals->curtime) < *(float *)&TheBots[1].m_debugMessage[0].m_string[468]
        && (!me->m_bInBombZone.m_Value || (float)(curtime - me->m_lastSawEnemyTimestamp) <= 3.0) )
      {
        if ( CCSBot::NoticeLooseBomb(this: me) )
        {
          CCSBot::FetchBomb(this: me);
          return;
        }
        BombPosition = CSGameState::GetBombPosition(this: &me->m_gameState);
        if ( !CCSBot::IsRogue(this: me) && me->m_gameState.m_bombState == 2 && BombPosition != nullptr )
        {
          me->m_task = GUARD_TICKING_BOMB;
          me->m_taskEntity.m_Index = -1;
          NavArea = (CCSNavArea *)CNavMesh::GetNavArea(this: TheNavMesh, pos: BombPosition, beneathLimit: 120.0);
          CCSBot::Hide(this: me, searchFromArea: NavArea, duration: -1.0, hideRange: 750.0, holdPosition: false);
          return;
        }
        goto LABEL_33;
      }
    }
    else
    {
      if ( !CCSBot::IsRogue(this: me) && CCSBot::CanSeeLooseBomb(this: me, a2: (int)&savedregs) )
      {
        me->m_task = GUARD_LOOSE_BOMB;
        me->m_taskEntity.m_Index = -1;
        CCSBot::Hide(
          this: me,
          searchFromArea: *(CCSNavArea **)&TheBots[1].m_debugMessage[0].m_string[480],
          duration: -1.0,
          hideRange: 750.0,
          holdPosition: false);
        LooseBomb = CCSBotManager::GetLooseBomb(this: (CCSBotManager *)TheBots);
        BotChatterInterface::GuardingLooseBomb(this: &me->m_chatter, bomb: LooseBomb);
        return;
      }
      if ( TheBots[1].m_debugMessage[0].m_string[460] == 0
        || CCSBot::IsRogue(this: me) && *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[472] != 0 )
      {
        goto LABEL_33;
      }
    }
    CCSBot::Idle(this: me);
    return;
  }
  if ( m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2
    && CBaseEntity::GetTeamNumber(this: me) == 2 )
  {
    if ( CSGameState::AreAllHostagesBeingRescued(this: &me->m_gameState)
      && CCSBot::GuardRandomZone(this: me, range: 500.0) != 0 )
    {
      me->m_task = GUARD_HOSTAGE_RESCUE_ZONE;
      me->m_taskEntity.m_Index = -1;
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Trying to beat them to an escape zone!\n");
      CCSBot::SetDisposition(this: me, disposition: OPPORTUNITY_FIRE);
      BotChatterInterface::GuardingHostageEscapeZone(this: &me->m_chatter, isPlan: true);
      return;
    }
    if ( !CCSBot::IsRogue(this: me) && !CCSBot::IsSafe(this: me) )
    {
      NearestVisibleFreeHostage = CSGameState::GetNearestVisibleFreeHostage(this: &me->m_gameState);
      if ( NearestVisibleFreeHostage != nullptr )
      {
        Centroid = GetCentroid(result: &extent.hi, player: NearestVisibleFreeHostage);
        NearestNavArea = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                         this: TheNavMesh,
                                         pos: Centroid,
                                         anyZ: false,
                                         maxDist: 10000.0,
                                         checkLOS: false,
                                         checkGround: true);
        v13 = NearestNavArea;
        if ( NearestNavArea != nullptr )
        {
          me->m_task = GUARD_HOSTAGES;
          me->m_taskEntity.m_Index = -1;
          CCSBot::Hide(this: me, searchFromArea: NearestNavArea, duration: -1.0, hideRange: 750.0, holdPosition: false);
          CBot<CCSPlayer>::PrintIfWatched(this: me, format: "I'm guarding hostages\n");
          BotChatterInterface::GuardingHostages(this: &me->m_chatter, place: v13->m_place, isPlan: true);
          return;
        }
        v4 = v26;
      }
    }
  }
LABEL_33:
  if ( CCSBot::HeardInterestingNoise(this: me) )
  {
    CCSBot::InvestigateNoise(this: me);
  }
  else
  {
    v14 = 0;
    CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT(&savedregs), a3: (int)v4, updateNow: false);
    if ( me->GetLastKnownArea(this: me) == v4->m_huntArea
      || CCSBot::UpdatePathMovement(this: me, a2: (int)&savedregs, allowSpeedChange: true) != 0 )
    {
      v15 = (IUniformRandomStream *)gpGlobals;
      if ( (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) >= 45.0
        || me->m_hasVisitedEnemySpawn )
      {
        v4->m_huntArea = nullptr;
        oldest = 0.0;
        areaCount = 0;
        if ( TheNavAreas.m_Size > 0 )
        {
          do
          {
            v19 = TheNavAreas.m_Memory.m_pMemory[v14];
            ++areaCount;
            CNavArea::GetExtent(this: v19, &extent);
            if ( (float)(extent.hi.x - extent.lo.x) >= 150.0 && (float)(extent.hi.y - extent.lo.y) >= 150.0 )
            {
              v20 = (CBaseEntity::GetTeamNumber(this: me) - 1) % 2;
              v15 = (IUniformRandomStream *)gpGlobals;
              if ( (float)(gpGlobals->curtime - v19->m_clearedTimestamp[v20]) > oldest )
              {
                oldest = gpGlobals->curtime - v19->m_clearedTimestamp[v20];
                v26->m_huntArea = v19;
              }
            }
            ++v14;
          }
          while ( v14 < TheNavAreas.m_Size );
          v4 = v26;
        }
        v21 = _RandomInt(this: v15, a2: 0, a3: areaCount - 1);
        for ( i = 0; i < TheNavAreas.m_Size; --v21 )
        {
          v4->m_huntArea = TheNavAreas.m_Memory.m_pMemory[i];
          if ( v21 == 0 )
            break;
          ++i;
        }
      }
      else
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this: me);
        RandomSpawn = CCSBotManager::GetRandomSpawn(this: (CCSBotManager *)TheBots, team: (TeamNumber == 2) + 2);
        if ( RandomSpawn != nullptr )
        {
          v18 = RandomSpawn->WorldSpaceCenter(this: RandomSpawn);
          v4->m_huntArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: v18, beneathLimit: 120.0);
        }
      }
      m_huntArea = v4->m_huntArea;
      if ( m_huntArea != nullptr )
        CCSBot::ComputePath(this: me, goal: &m_huntArea->m_center, route: SAFEST_ROUTE);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D5F80
// Name: __CreateCServerGameTagsIServerGameTags_interface_45
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_45()
{
  return &_g_CServerGameTags_singleton_45;
}
