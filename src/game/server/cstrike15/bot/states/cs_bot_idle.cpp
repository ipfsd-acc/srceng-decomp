// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_idle.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_idle.h"

//------------------------------------------------------------------------------
// Address: 0x102D5F90
// Name: public: void CCSBot::SetGoalEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetGoalEntity(CCSBot *this, CBaseEntity *entity)
{
  if ( entity != nullptr )
    this->m_goalEntity.m_Index = entity->GetRefEHandle(this: entity)->m_Index;
  else
    this->m_goalEntity.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x102D5FC0
// Name: public: virtual void IdleState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IdleState::OnEnter(IdleState *this, CCSBot *me)
{
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
  CCSBot::SetBotEnemy(this: me, enemy: nullptr);
  if ( CCSBot::IsUsingKnife(this: me) && CCSBot::IsWellPastSafe(this: me) && !CCSBot::IsHurrying(this: me) )
    me->Walk(this: me);
  me->m_task = SEEK_AND_DESTROY;
  me->m_taskEntity.m_Index = -1;
  CCSBot::SetDisposition(this: me, disposition: ENGAGE_AND_INVESTIGATE);
}

//------------------------------------------------------------------------------
// Address: 0x102D6030
// Name: public: void CCSBot::ResetWaitForHostagePatience(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ResetWaitForHostagePatience(CCSBot *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  p_m_timestamp = &this->m_inhibitWaitingForHostageTimer.m_timestamp;
  this->m_isWaitingForHostage = false;
  if ( this->m_inhibitWaitingForHostageTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_inhibitWaitingForHostageTimer.NetworkStateChanged(
      this: &this->m_inhibitWaitingForHostageTimer,
      a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D6140
// Name: public: virtual void IdleState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IdleState::OnUpdate(IdleState *this@<ecx>, BOOL a2@<ebx>, float a3@<edi>, float me)
{
  float v4; // esi
  CCSBotManager *v5; // edi
  CNavArea *v6; // eax
  const CCSBotManager::Zone *Closest; // eax
  const Vector *RandomPositionInZone; // edi
  CBot<CCSPlayer> *v9; // ecx
  IUniformRandomStream *v10; // ecx
  const CCSBotManager::Zone *RandomZone; // eax
  CCSNavArea *RandomAreaInZone; // eax
  double v13; // st7
  const CCSBotManager::Zone *v14; // eax
  CCSNavArea *v15; // edi
  const CCSBotManager::Zone *v16; // eax
  CCSBotManager *v17; // edi
  CNavArea *v18; // eax
  const Vector *v19; // edi
  CCSBotManager *v20; // edi
  int TeamNumber; // eax
  IUniformRandomStream *v22; // ecx
  IUniformRandomStream *v23; // ecx
  CCSNavArea *v24; // eax
  double v25; // st6
  double v26; // st7
  IUniformRandomStream *v27; // ecx
  const Vector *RandomFreeHostagePosition; // edi
  CHostage *NearestVisibleFreeHostage; // eax
  const Vector *Centroid; // eax
  CCSNavArea *v31; // eax
  IUniformRandomStream *v32; // ecx
  double v33; // st7
  int v34; // edi
  IUniformRandomStream *v35; // ecx
  double v36; // st7
  const Vector *v37; // eax
  CCSNavArea *v38; // edi
  IUniformRandomStream *v39; // ecx
  IUniformRandomStream *v40; // ecx
  IUniformRandomStream *v41; // ecx
  int v42; // edi
  IUniformRandomStream *v43; // ecx
  double v44; // st7
  CHostage *NearestFreeHostage; // edi
  const Vector *v46; // eax
  CCSNavArea *v47; // eax
  const CCSBotManager::Zone *v48; // ebx
  int v49; // edx
  CCSBotManager *v50; // ebx
  CNavArea *v51; // eax
  float v52; // eax
  int v53; // edx
  int (__thiscall *v54)(_DWORD); // eax
  CNavArea *v55; // eax
  const Vector *v56; // eax
  CNavArea *v57; // eax
  double v58; // st7
  const Vector *v59; // eax
  const Vector *v60; // edi
  const Vector *v61; // eax
  CBotManager *v62; // edi
  const Vector *v63; // eax
  const Vector *v64; // ebx
  unsigned int v65; // edi
  bool IsSniper; // al
  const Vector *RandomHidingSpot; // eax
  CCSNavArea *v68; // eax
  int v69; // eax
  const Vector *v70; // eax
  unsigned int Place; // eax
  CCSBotManager *v72; // edi
  CNavArea *v73; // eax
  const CCSBotManager::Zone *v74; // eax
  const Vector *v75; // edi
  int v76; // edi
  IUniformRandomStream *v77; // ecx
  double v78; // st7
  IUniformRandomStream *v79; // ecx
  const Vector *v80; // eax
  const Vector *BombPosition; // edi
  CCSNavArea *NavArea; // eax
  CBotManager *v83; // edi
  int v84; // edi
  CCSBotManager *v85; // ecx
  int v86; // edi
  int v87; // ebx
  CNavArea *v88; // eax
  double v89; // st7
  int NextBombsiteToSearch; // eax
  const CCSBotManager::Zone *v91; // eax
  IUniformRandomStream *v92; // ecx
  const Vector *v93; // edi
  CNavArea *v94; // eax
  const CCSBotManager::Zone *v95; // eax
  CCSNavArea *v96; // edi
  double v97; // st7
  const CCSBotManager::Zone *v98; // eax
  CNavArea *v99; // edi
  int v100; // edi
  IUniformRandomStream *v101; // ecx
  double v102; // st7
  CNavArea *v103; // [esp+Ch] [ebp-58h]
  CCSNavArea *v104; // [esp+10h] [ebp-54h]
  CCSNavArea *NearestNavArea; // [esp+10h] [ebp-54h]
  char *duration; // [esp+14h] [ebp-50h]
  const Vector *durationa; // [esp+14h] [ebp-50h]
  float range; // [esp+1Ch] [ebp-48h]
  float rangeb; // [esp+1Ch] [ebp-48h]
  char *rangea; // [esp+1Ch] [ebp-48h]
  float v112; // [esp+20h] [ebp-44h]
  Vector v113; // [esp+24h] [ebp-40h] BYREF
  Vector v114; // [esp+30h] [ebp-34h] BYREF
  Vector v115; // [esp+3Ch] [ebp-28h] BYREF
  Vector result; // [esp+48h] [ebp-1Ch] BYREF
  Vector v117; // [esp+54h] [ebp-10h] BYREF
  float toZone; // [esp+60h] [ebp-4h]

  v4 = me;
  if ( (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(me) + 1320))(a1: LODWORD(me)) == 0
    && CCSBot::StayOnNavMesh(this: (CCSBot *)LODWORD(v4)) == 0 )
  {
    return;
  }
  if ( cv_bot_zombie.m_pParent != nullptr && cv_bot_zombie.m_pParent->m_Value.m_nValue != 0 )
  {
    CCSBot::ResetStuckMonitor(this: (CCSBot *)LODWORD(v4));
    return;
  }
  if ( CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4))
    && CCSBot::EquipGrenade(this: (CCSBot *)LODWORD(v4), noSmoke: false) == 0
    && *(float *)(*(_DWORD *)(LODWORD(v4) + 7072) + 8) > 0.33000001 )
  {
    CCSBot::EquipKnife(this: (CCSBot *)LODWORD(v4));
  }
  range = *(float *)&a2;
  if ( CRecipientFilter::IsReliable(this: (CRecipientFilter *)(LODWORD(v4) + 14420)) )
  {
    if ( *(_BYTE *)(LODWORD(v4) + 14780) != 0 )
    {
      v5 = (CCSBotManager *)TheBots;
      v6 = (CNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
      Closest = CCSBotManager::GetClosestZone<PathCost>(
                  this: v5,
                  startArea: v6,
                  costFunc: (PathCost)(LODWORD(v4) | 0x100000000LL),
                  travelDistance: nullptr);
      RandomPositionInZone = CCSBotManager::GetRandomPositionInZone(this: (CCSBotManager *)TheBots, zone: Closest);
      if ( RandomPositionInZone != nullptr )
      {
        *(_DWORD *)(LODWORD(v4) + 7844) = 15;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 2056))(a1: COERCE_FLOAT(LODWORD(v4)));
        CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: SELF_DEFENSE);
        CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: RandomPositionInZone, route: FASTEST_ROUTE);
        CBot<CCSPlayer>::PrintIfWatched(
          this: (CBot<CCSPlayer> *)LODWORD(v4),
          format: "Trying to rescue hostages at the end of the round\n");
        return;
      }
    }
    goto LABEL_195;
  }
  if ( *(_BYTE *)(LODWORD(v4) + 7356) != 0 )
  {
    CCSBot::ContinueFollowing(this: (CCSBot *)LODWORD(v4));
    return;
  }
  v9 = (CBot<CCSPlayer> *)LODWORD(v4);
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory != (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
  {
    if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory != (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2 )
    {
      if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)3 )
      {
        if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)LODWORD(v4)) == 2 )
        {
          if ( CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4)) && _RandomFloat(this: v10, a2: 0.0, a3: 100.0) <= 75.0 )
          {
            RandomZone = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
            if ( RandomZone != nullptr )
            {
              RandomAreaInZone = (CCSNavArea *)CCSBotManager::GetRandomAreaInZone(
                                                 this: (CCSBotManager *)TheBots,
                                                 zone: RandomZone);
              if ( RandomAreaInZone != nullptr )
              {
                *(_DWORD *)(LODWORD(v4) + 7844) = 19;
                *(_DWORD *)(LODWORD(v4) + 7848) = -1;
                CCSBot::Hide(
                  this: (CCSBot *)LODWORD(v4),
                  searchFromArea: RandomAreaInZone,
                  duration: -1.0,
                  hideRange: 2000.0,
                  holdPosition: false);
                CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
                CBot<CCSPlayer>::PrintIfWatched(
                  this: (CBot<CCSPlayer> *)LODWORD(v4),
                  format: "Sniping near escape zone\n");
                return;
              }
            }
          }
          if ( !CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) && TheBots[1].m_debugMessage[0].m_string[700] == 0 )
          {
            me = *(float *)(LODWORD(v4) + 7320);
            v13 = _RandomFloat(this: (IUniformRandomStream *)TheBots, a2: 0.0, a3: 100.0);
            if ( (double)SLODWORD(me) * -34.0 > v13 )
            {
              v14 = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
              if ( v14 != nullptr )
              {
                v15 = (CCSNavArea *)CCSBotManager::GetRandomAreaInZone(this: (CCSBotManager *)TheBots, zone: v14);
                if ( v15 != nullptr )
                {
                  LODWORD(v113.x) = "I'm guarding an escape zone\n";
                  *(_DWORD *)(LODWORD(v4) + 7844) = 13;
                  *(_DWORD *)(LODWORD(v4) + 7848) = -1;
                  CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: (char *)LODWORD(v113.x));
                  CCSBot::Hide(
                    this: (CCSBot *)LODWORD(v4),
                    searchFromArea: v15,
                    duration: -1.0,
                    hideRange: (float)((float)(*(_DWORD *)(LODWORD(v4) + 7320) + 3) * 250.0) + 750.0,
                    holdPosition: false);
                  CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
                  return;
                }
              }
            }
          }
          goto LABEL_195;
        }
        if ( *(_BYTE *)(LODWORD(v4) + 4902) != 0 )
        {
          if ( (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) >= 20.0 )
          {
            v17 = (CCSBotManager *)TheBots;
            v18 = (CNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
            v16 = CCSBotManager::GetClosestZone<PathCost>(
                    this: v17,
                    startArea: v18,
                    costFunc: (PathCost)(LODWORD(v4) | 0x200000000LL),
                    travelDistance: nullptr);
          }
          else
          {
            v16 = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
          }
          if ( v16 != nullptr )
          {
            v19 = CCSBotManager::GetRandomPositionInZone(this: (CCSBotManager *)TheBots, zone: v16);
            if ( v19 != nullptr )
            {
              *(_DWORD *)(LODWORD(v4) + 7844) = 12;
              *(_DWORD *)(LODWORD(v4) + 7848) = -1;
              (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 2056))(a1: COERCE_FLOAT(LODWORD(v4)));
              CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: v19, route: SAFEST_ROUTE);
              if ( CBot<CCSPlayer>::GetFriendsRemaining(this: (CBot<CCSPlayer> *)LODWORD(v4)) != 0 )
              {
                v20 = (CCSBotManager *)TheBots;
                TeamNumber = CBaseEntity::GetTeamNumber(this: (CBaseEntity *)LODWORD(v4));
                if ( CCSBotManager::GetRadioMessageInterval(this: v20, event: RADIO_FOLLOW_ME, teamID: TeamNumber) > 30.0 )
                  CCSBot::SendRadioMessage(this: (CCSBot *)LODWORD(v4), event: RADIO_FOLLOW_ME);
              }
              return;
            }
          }
LABEL_195:
          CCSBot::Hunt(this: (CCSBot *)LODWORD(v4));
          return;
        }
        v9 = (CBot<CCSPlayer> *)LODWORD(v4);
      }
      if ( CBot<CCSPlayer>::GetFriendsRemaining(this: v9) == 0
        || !CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
        || _RandomFloat(this: v22, a2: 0.0, a3: 100.0) >= 10.0 )
      {
        goto LABEL_195;
      }
LABEL_44:
      *(_DWORD *)(LODWORD(v4) + 7844) = 19;
      *(_DWORD *)(LODWORD(v4) + 7848) = -1;
      rangeb = _RandomFloat(this: v23, a2: 10.0, a3: 30.0);
      v24 = (CCSNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
      CCSBot::Hide(
        this: (CCSBot *)LODWORD(v4),
        searchFromArea: v24,
        duration: rangeb,
        hideRange: v112,
        holdPosition: SLOBYTE(v113.x));
      CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
      CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: "Sniping!\n");
      return;
    }
    if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)LODWORD(v4)) == 2 )
    {
      if ( CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4)) )
      {
        HIBYTE(me) = 1;
      }
      else if ( *(_BYTE *)(LODWORD(v4) + 14777) != 0
             || CSGameState::AreAllHostagesBeingRescued(this: (CSGameState *)(LODWORD(v4) + 14420))
             || (me = (gpGlobals->curtime
                     - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]
                     - *(float *)(LODWORD(v4) + 7328))
                    * 100.0
                    * 0.0083333338,
                 v25 = _RandomFloat(this: (IUniformRandomStream *)gpGlobals, a2: 0.0, a3: 100.0),
                 v26 = me,
                 HIBYTE(me) = 1,
                 v25 <= v26) )
      {
        HIBYTE(me) = 0;
      }
      if ( CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4)) )
      {
        if ( CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4))
          && CCSBot::MoveToInitialEncounter(this: (CCSBot *)LODWORD(v4)) != 0 )
        {
          CBot<CCSPlayer>::PrintIfWatched(
            this: (CBot<CCSPlayer> *)LODWORD(v4),
            format: "I'm sniping an initial encounter area\n");
LABEL_194:
          *(_DWORD *)(LODWORD(v4) + 7844) = 8;
          *(_DWORD *)(LODWORD(v4) + 7848) = -1;
          CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
          return;
        }
        if ( _RandomFloat(this: v27, a2: 0.0, a3: 100.0) <= 75.0 )
        {
          RandomFreeHostagePosition = CSGameState::GetRandomFreeHostagePosition(this: (CSGameState *)(LODWORD(v4) + 14420));
          if ( RandomFreeHostagePosition != nullptr && HIBYTE(me) != 0 )
          {
            *(_DWORD *)(LODWORD(v4) + 7844) = 19;
            *(_DWORD *)(LODWORD(v4) + 7848) = -1;
            CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: "Sniping near hostages\n");
            NearestNavArea = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                             this: TheNavMesh,
                                             pos: RandomFreeHostagePosition,
                                             anyZ: false,
                                             maxDist: 10000.0,
                                             checkLOS: false,
                                             checkGround: true);
            CCSBot::Hide(
              this: (CCSBot *)LODWORD(v4),
              searchFromArea: NearestNavArea,
              duration: -1.0,
              hideRange: 2000.0,
              holdPosition: false);
LABEL_188:
            CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
            return;
          }
          if ( CCSBot::GuardRandomZone(this: (CCSBot *)LODWORD(v4), range: 2000.0) != 0 )
          {
            *(_DWORD *)(LODWORD(v4) + 7844) = 19;
            *(_DWORD *)(LODWORD(v4) + 7848) = -1;
            CBot<CCSPlayer>::PrintIfWatched(
              this: (CBot<CCSPlayer> *)LODWORD(v4),
              format: "Sniping near a rescue zone\n");
            CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
            return;
          }
        }
      }
      if ( !CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4)) && !CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) )
      {
        NearestVisibleFreeHostage = CSGameState::GetNearestVisibleFreeHostage(this: (CSGameState *)(LODWORD(v4) + 14420));
        if ( NearestVisibleFreeHostage != nullptr )
        {
          Centroid = GetCentroid(&result, player: NearestVisibleFreeHostage);
          v31 = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                this: TheNavMesh,
                                pos: Centroid,
                                anyZ: false,
                                maxDist: 10000.0,
                                checkLOS: false,
                                checkGround: true);
          if ( v31 != nullptr )
          {
            *(_DWORD *)(LODWORD(v4) + 7844) = 16;
            *(_DWORD *)(LODWORD(v4) + 7848) = -1;
            CCSBot::Hide(
              this: (CCSBot *)LODWORD(v4),
              searchFromArea: v31,
              duration: -1.0,
              hideRange: 750.0,
              holdPosition: false);
            CBot<CCSPlayer>::PrintIfWatched(
              this: (CBot<CCSPlayer> *)LODWORD(v4),
              format: "I'm guarding hostages I found\n");
            return;
          }
        }
      }
      toZone = *(float *)(LODWORD(v4) + 7320);
      if ( CBot<CCSPlayer>::GetFriendsRemaining(this: (CBot<CCSPlayer> *)LODWORD(v4)) != 0 )
      {
        if ( CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) )
          goto LABEL_195;
        if ( TheBots[1].m_debugMessage[0].m_string[700] != 0 )
          goto LABEL_195;
        v33 = _RandomFloat(this: v32, a2: 0.0, a3: 100.0);
        if ( (double)SLODWORD(toZone) * 25.0 + 70.0 > v33 )
          goto LABEL_195;
      }
      if ( !CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4))
        || (v34 = *(_DWORD *)(LODWORD(v4) + 7320), !CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4)))
        && (v36 = _RandomFloat(this: v35, a2: 0.0, a3: 100.0),
            LODWORD(toZone) = v34 - 2,
            (double)(v34 - 2) * -17.0 <= v36)
        || CCSBot::MoveToInitialEncounter(this: (CCSBot *)LODWORD(v4)) == 0 )
      {
        v37 = CSGameState::GetRandomFreeHostagePosition(this: (CSGameState *)(LODWORD(v4) + 14420));
        if ( v37 == nullptr
          || HIBYTE(me) == 0
          || (v38 = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                    this: TheNavMesh,
                                    pos: v37,
                                    anyZ: false,
                                    maxDist: 10000.0,
                                    checkLOS: false,
                                    checkGround: true)) == nullptr )
        {
          if ( CCSBot::GuardRandomZone(this: (CCSBot *)LODWORD(v4), range: 500.0) != 0 )
          {
            LODWORD(v113.z) = "I'm guarding a rescue zone\n";
            *(_DWORD *)(LODWORD(v4) + 7844) = 17;
            v113.y = v4;
            *(_DWORD *)(LODWORD(v4) + 7848) = -1;
            CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v113.y), format: (char *)LODWORD(v113.z));
            CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
            BotChatterInterface::GuardingHostageEscapeZone(
              this: (BotChatterInterface *)(LODWORD(v4) + 16800),
              isPlan: true);
            return;
          }
          goto LABEL_195;
        }
        LODWORD(v113.z) = "I'm guarding hostages\n";
        *(_DWORD *)(LODWORD(v4) + 7844) = 16;
        v113.y = v4;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v113.y), format: (char *)LODWORD(v113.z));
        CCSBot::Hide(
          this: (CCSBot *)LODWORD(v4),
          searchFromArea: v38,
          duration: -1.0,
          hideRange: (float)((float)(*(_DWORD *)(LODWORD(v4) + 7320) + 3) * 250.0) + 750.0,
          holdPosition: false);
        CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
        if ( _RandomFloat(this: v39, a2: 0.0, a3: 100.0) < 50.0 )
          BotChatterInterface::GuardingHostages(
            this: (BotChatterInterface *)(LODWORD(v4) + 16800),
            place: v38->m_place,
            isPlan: true);
        return;
      }
LABEL_193:
      LODWORD(v113.z) = "I'm guarding an initial encounter area\n";
      CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: duration);
      goto LABEL_194;
    }
    if ( *(_BYTE *)(LODWORD(v4) + 14780) == 0 )
    {
      if ( CBot<CCSPlayer>::GetFriendsRemaining(this: (CBot<CCSPlayer> *)LODWORD(v4)) != 0
        && CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
        && _RandomFloat(this: v40, a2: 0.0, a3: 100.0) < 10.0 )
      {
        goto LABEL_44;
      }
      if ( CBot<CCSPlayer>::GetFriendsRemaining(this: (CBot<CCSPlayer> *)LODWORD(v4)) != 0
        && *(_BYTE *)(LODWORD(v4) + 14780) == 0
        && (CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) || _RandomFloat(this: v41, a2: 0.0, a3: 100.0) < 33.299999) )
      {
        goto LABEL_195;
      }
    }
    if ( CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4)) )
    {
      v42 = *(_DWORD *)(LODWORD(v4) + 7320);
      if ( CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
        || (v44 = _RandomFloat(this: v43, a2: 0.0, a3: 100.0), LODWORD(me) = v42 - 2, (double)(v42 - 2) * -17.0 > v44) )
      {
        if ( CCSBot::MoveToInitialEncounter(this: (CCSBot *)LODWORD(v4)) != 0 )
          goto LABEL_193;
      }
    }
    NearestFreeHostage = CSGameState::GetNearestFreeHostage(
                           this: (CSGameState *)(LODWORD(v4) + 14420),
                           knowPos: nullptr);
    if ( !CCSBot::IsDoingScenario(this: (CCSBot *)LODWORD(v4)) )
    {
      if ( NearestFreeHostage != nullptr )
      {
        v46 = GetCentroid(result: &v115, player: NearestFreeHostage);
        v47 = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                              this: TheNavMesh,
                              pos: v46,
                              anyZ: false,
                              maxDist: 10000.0,
                              checkLOS: false,
                              checkGround: true);
        if ( v47 != nullptr )
        {
          LOBYTE(v113.z) = 0;
          v113.y = 750.0;
          v113.x = -1.0;
          *(_DWORD *)(LODWORD(v4) + 7844) = 16;
          *(_DWORD *)(LODWORD(v4) + 7848) = -1;
          CCSBot::Hide(
            this: (CCSBot *)LODWORD(v4),
            searchFromArea: v47,
            duration: v113.x,
            hideRange: v113.y,
            holdPosition: SLOBYTE(v113.z));
          CBot<CCSPlayer>::PrintIfWatched(
            this: (CBot<CCSPlayer> *)LODWORD(v4),
            format: "I'm securing the hostages for a human to rescue\n");
          return;
        }
      }
      goto LABEL_195;
    }
    v48 = nullptr;
    *(_DWORD *)(LODWORD(v4) + 7864) = -1;
    HIBYTE(me) = 0;
    if ( *(_BYTE *)(LODWORD(v4) + 14780) != 0 )
    {
      v49 = *(_DWORD *)LODWORD(v4);
      v50 = (CCSBotManager *)TheBots;
      v113.z = 0.0;
      v51 = (CNavArea *)(*(int (__thiscall **)(float))(v49 + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
      v48 = CCSBotManager::GetClosestZone<PathCost>(
              this: v50,
              startArea: v51,
              costFunc: (PathCost)(LODWORD(v4) | 0x100000000LL),
              travelDistance: nullptr);
    }
    if ( NearestFreeHostage != nullptr )
    {
      GetCentroid(result: &v117, player: NearestFreeHostage);
      if ( v48 == nullptr )
        goto LABEL_110;
      v52 = *(float *)v48->m_area;
      v113.z = 0.0;
      LODWORD(v113.y) = &v117.y;
      v53 = *(_DWORD *)LODWORD(v4);
      v113.x = v52;
      v54 = *(int (__thiscall **)(_DWORD))(v53 + 1320);
      v117.y = v4;
      LODWORD(v117.z) = 1;
      v55 = (CNavArea *)v54(a1: LODWORD(v4));
      toZone = NavAreaTravelDistance<PathCost>(
                 startArea: v55,
                 endArea: (CNavArea *)LODWORD(v113.x),
                 costFunc: (PathCost *)&v117.y,
                 maxPathLength: 0.0);
      v113.z = 0.0;
      LODWORD(v113.y) = &v117.y;
      v56 = GetCentroid(result: &v114, player: NearestFreeHostage);
      LODWORD(v113.x) = CNavMesh::GetNearestNavArea(
                          this: TheNavMesh,
                          pos: v56,
                          anyZ: false,
                          maxDist: 10000.0,
                          checkLOS: false,
                          checkGround: true);
      v57 = (CNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
      v58 = NavAreaTravelDistance<PathCost>(
              startArea: v57,
              endArea: (CNavArea *)LODWORD(v113.x),
              costFunc: (PathCost *)&v117.y,
              maxPathLength: 0.0);
      me = v58;
      if ( v58 >= 0.0 && me <= toZone )
      {
LABEL_110:
        *(_DWORD *)(LODWORD(v4) + 7844) = 14;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 2056))(a1: COERCE_FLOAT(LODWORD(v4)));
        CCSBot::SetGoalEntity(this: (CCSBot *)LODWORD(v4), entity: NearestFreeHostage);
        CCSBot::ResetWaitForHostagePatience(this: (CCSBot *)LODWORD(v4));
        LODWORD(v113.z) = (*(_BYTE *)(LODWORD(v4) + 14780) == 0) + 1;
        v61 = GetCentroid(result: &v113, player: NearestFreeHostage);
        CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: v61, route: SLODWORD(v113.z));
        CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: "I'm collecting hostages\n");
        return;
      }
    }
    else if ( v48 == nullptr )
    {
      goto LABEL_105;
    }
    HIBYTE(me) = 1;
LABEL_105:
    v59 = CCSBotManager::GetRandomPositionInZone(this: (CCSBotManager *)TheBots, zone: v48);
    v60 = v59;
    if ( HIBYTE(me) != 0 && v59 != nullptr )
    {
      *(_DWORD *)(LODWORD(v4) + 7844) = 15;
      *(_DWORD *)(LODWORD(v4) + 7848) = -1;
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 2056))(a1: COERCE_FLOAT(LODWORD(v4)));
      CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: SELF_DEFENSE);
      CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: v60, route: FASTEST_ROUTE);
      CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: "I'm rescuing hostages\n");
      BotChatterInterface::EscortingHostages(this: (BotChatterInterface *)(LODWORD(v4) + 16800));
      return;
    }
    goto LABEL_195;
  }
  if ( CBaseEntity::GetTeamNumber(this: (CBaseEntity *)LODWORD(v4)) != 2 )
  {
    if ( *(_DWORD *)(LODWORD(v4) + 14428) != 2 )
      goto LABEL_166;
    BombPosition = CSGameState::GetBombPosition(this: (CSGameState *)(LODWORD(v4) + 14420));
    if ( BombPosition != nullptr )
    {
      if ( *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[472] != 0 )
      {
        if ( !CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) )
        {
          durationa = nullptr;
          *(_DWORD *)(LODWORD(v4) + 7844) = 5;
          goto LABEL_147;
        }
        goto LABEL_166;
      }
      if ( CCSBot::IsDoingScenario(this: (CCSBot *)LODWORD(v4)) )
      {
        *(_DWORD *)(LODWORD(v4) + 7844) = 3;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
        CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: BombPosition, route: SAFEST_ROUTE);
        return;
      }
    }
    else
    {
      if ( CSGameState::GetPlantedBombsite(this: (CSGameState *)(LODWORD(v4) + 14420)) == -1 )
      {
        v85 = (CCSBotManager *)TheBots;
        v86 = 0;
        v87 = 0;
        toZone = 0.0;
        me = 10000000.0;
        if ( *(int *)&TheBots[1].m_debugMessage[0].m_string[456] <= 0 )
          goto LABEL_165;
        do
        {
          if ( v85->m_zone[v86].m_areaCount != 0 )
          {
            if ( CSGameState::IsBombsiteClear(this: (CSGameState *)(LODWORD(v4) + 14420), zoneIndex: v87)
              || (v103 = CNavMesh::GetNearestNavArea(
                           this: TheNavMesh,
                           pos: (const Vector *)&TheBots[1].m_debugMessage[0].m_string[v86 * 120 + 48],
                           anyZ: false,
                           maxDist: 10000.0,
                           checkLOS: false,
                           checkGround: true),
                  v88 = (CNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4))),
                  v89 = NavAreaTravelDistance<ShortestPathCost>(
                          startArea: v88,
                          endArea: v103,
                          costFunc: (ShortestPathCost *)&me + 3,
                          maxPathLength: 0.0),
                  v117.z = v89,
                  v89 < 0.0)
              || me <= v117.z )
            {
              v85 = (CCSBotManager *)TheBots;
            }
            else
            {
              v85 = (CCSBotManager *)TheBots;
              LODWORD(toZone) = (char *)&TheBots[1].m_activeGrenadeList.m_Memory.m_nAllocationCount + v86 * 120;
              me = v117.z;
            }
          }
          ++v87;
          ++v86;
        }
        while ( v87 < v85->m_zoneCount );
        if ( toZone == 0.0 || me > 2000.0 )
        {
LABEL_165:
          NextBombsiteToSearch = CSGameState::GetNextBombsiteToSearch(this: (CSGameState *)(LODWORD(v4) + 14420));
          v85 = (CCSBotManager *)TheBots;
          v91 = (const CCSBotManager::Zone *)(&TheBots[1].m_activeGrenadeList.m_Memory.m_nAllocationCount
                                            + 30 * NextBombsiteToSearch);
          if ( v91 == nullptr )
            goto LABEL_166;
        }
        else
        {
          v91 = (const CCSBotManager::Zone *)LODWORD(toZone);
        }
        v70 = CCSBotManager::GetRandomPositionInZone(this: v85, zone: v91);
        if ( v70 != nullptr )
          goto LABEL_120;
LABEL_166:
        if ( CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
          && !CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4))
          && _RandomFloat(this: v92, a2: 0.0, a3: 100.0) <= 75.0 )
        {
          v93 = CSGameState::GetBombPosition(this: (CSGameState *)(LODWORD(v4) + 14420));
          if ( CSGameState::IsLooseBombLocationKnown(this: (CSGameState *)(LODWORD(v4) + 14420)) && v93 != nullptr )
          {
            v94 = CNavMesh::GetNearestNavArea(
                    this: TheNavMesh,
                    pos: v93,
                    anyZ: false,
                    maxDist: 10000.0,
                    checkLOS: false,
                    checkGround: true);
            rangea = "Sniping near loose bomb\n";
            goto LABEL_177;
          }
          v95 = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
          if ( v95 != nullptr )
          {
            v94 = CCSBotManager::GetRandomAreaInZone(this: (CCSBotManager *)TheBots, zone: v95);
            rangea = "Sniping near bombsite\n";
LABEL_177:
            v96 = (CCSNavArea *)v94;
            CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: rangea);
            if ( v96 != nullptr )
            {
              *(_DWORD *)(LODWORD(v4) + 7844) = 19;
              *(_DWORD *)(LODWORD(v4) + 7848) = -1;
              CCSBot::Hide(
                this: (CCSBot *)LODWORD(v4),
                searchFromArea: v96,
                duration: -1.0,
                hideRange: 2000.0,
                holdPosition: false);
              CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
              return;
            }
          }
        }
        if ( CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4))
          || TheBots[1].m_debugMessage[0].m_string[700] != 0
          || CSGameState::IsLooseBombLocationKnown(this: (CSGameState *)(LODWORD(v4) + 14420))
          || !CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4))
          && !CCSBot::HasNotSeenEnemyForLongTime(this: (CCSBot *)LODWORD(v4)) )
        {
          goto LABEL_195;
        }
        me = *(float *)(LODWORD(v4) + 7320);
        v97 = _RandomFloat(this: (IUniformRandomStream *)LODWORD(me), a2: 0.0, a3: 100.0);
        if ( (double)SLODWORD(me) * -34.0 > v97 )
        {
          v98 = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
          if ( v98 != nullptr )
          {
            v99 = CCSBotManager::GetRandomAreaInZone(this: (CCSBotManager *)TheBots, zone: v98);
            if ( v99 != nullptr )
            {
              CBot<CCSPlayer>::PrintIfWatched(this: (CBot<CCSPlayer> *)LODWORD(v4), format: "I'm guarding a bombsite\n");
              BotChatterInterface::GuardingBombsite(
                this: (BotChatterInterface *)(LODWORD(v4) + 16800),
                place: v99->m_place);
              v113.x = 0.0;
              *(_DWORD *)(LODWORD(v4) + 7844) = 7;
              *(_DWORD *)(LODWORD(v4) + 7848) = -1;
              CCSBot::Hide(
                this: (CCSBot *)LODWORD(v4),
                searchFromArea: v104,
                duration: *(float *)&duration,
                hideRange: *(float *)&v99,
                holdPosition: false);
              goto LABEL_188;
            }
          }
        }
        if ( !CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4)) )
          goto LABEL_195;
        v100 = *(_DWORD *)(LODWORD(v4) + 7320);
        if ( !CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4)) )
        {
          v102 = _RandomFloat(this: v101, a2: 0.0, a3: 100.0);
          LODWORD(me) = v100 - 2;
          if ( (double)(v100 - 2) * -17.0 <= v102 )
            goto LABEL_195;
        }
        if ( CCSBot::MoveToInitialEncounter(this: (CCSBot *)LODWORD(v4)) == 0 )
          goto LABEL_195;
        goto LABEL_193;
      }
      v83 = TheBots;
      v84 = (int)(&v83[1].m_activeGrenadeList.m_Memory.m_nAllocationCount
                + 30 * CSGameState::GetPlantedBombsite(this: (CSGameState *)(LODWORD(v4) + 14420)));
      if ( v84 == 0 )
        goto LABEL_166;
      BombPosition = (const Vector *)(v84 + 72);
      if ( CCSBot::IsDoingScenario(this: (CCSBot *)LODWORD(v4)) )
      {
        *(_DWORD *)(LODWORD(v4) + 7844) = 3;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: BombPosition, route: SAFEST_ROUTE);
        CCSBot::SetDisposition(this: (CCSBot *)LODWORD(v4), disposition: OPPORTUNITY_FIRE);
        return;
      }
    }
    *(_DWORD *)(LODWORD(v4) + 7844) = 7;
    *(_DWORD *)(LODWORD(v4) + 7848) = -1;
    CNavMesh::GetNavArea(this: TheNavMesh, pos: BombPosition, beneathLimit: 120.0);
    CCSBot::Hide(
      this: (CCSBot *)LODWORD(v4),
      searchFromArea: (CCSNavArea *)0x443B8000,
      duration: 0.0,
      hideRange: a3,
      holdPosition: a2);
    goto LABEL_188;
  }
  if ( *(_DWORD *)(LODWORD(v4) + 14428) != 2 )
  {
    if ( CCSPlayer::HasC4(this: (CCSPlayer *)LODWORD(v4)) )
    {
      if ( *(_BYTE *)(LODWORD(v4) + 6000) != 0 )
      {
        *(_DWORD *)(LODWORD(v4) + 7844) = 1;
        *(_DWORD *)(LODWORD(v4) + 7848) = -1;
        CCSBot::PlantBomb(this: (CCSBot *)LODWORD(v4));
        Place = CCSBot::GetPlace(this: (CCSBot *)LODWORD(v4));
        BotChatterInterface::PlantingTheBomb(this: (BotChatterInterface *)(LODWORD(v4) + 16800), place: Place);
        return;
      }
      v72 = (CCSBotManager *)TheBots;
      if ( CCSBotManager::IsTimeToPlantBomb(this: (CCSBotManager *)TheBots) )
      {
        v73 = (CNavArea *)(*(int (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 1320))(a1: COERCE_FLOAT(LODWORD(v4)));
        v74 = CCSBotManager::GetClosestZone<PathCost>(
                this: v72,
                startArea: v73,
                costFunc: (PathCost)(LODWORD(v4) | 0x200000000LL),
                travelDistance: nullptr);
        if ( v74 != nullptr )
        {
          v75 = CCSBotManager::GetRandomPositionInZone(this: (CCSBotManager *)TheBots, zone: v74);
          if ( v75 != nullptr )
          {
            *(_DWORD *)(LODWORD(v4) + 7844) = 1;
            *(_DWORD *)(LODWORD(v4) + 7848) = -1;
            (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v4) + 2056))(a1: COERCE_FLOAT(LODWORD(v4)));
            CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: v75, route: SAFEST_ROUTE);
            return;
          }
        }
      }
      goto LABEL_195;
    }
    if ( CCSBot::IsSafe(this: (CCSBot *)LODWORD(v4)) )
    {
      v76 = *(_DWORD *)(LODWORD(v4) + 7320);
      if ( CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
        || (v78 = _RandomFloat(this: v77, a2: 0.0, a3: 100.0), LODWORD(me) = v76 - 2, (double)(v76 - 2) * -17.0 > v78) )
      {
        if ( CCSBot::MoveToInitialEncounter(this: (CCSBot *)LODWORD(v4)) != 0 )
          goto LABEL_193;
      }
    }
    if ( CBot<CCSPlayer>::GetFriendsRemaining(this: (CBot<CCSPlayer> *)LODWORD(v4)) != 0
      && CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4))
      && _RandomFloat(this: v79, a2: 0.0, a3: 100.0) < 10.0 )
    {
      goto LABEL_44;
    }
    if ( CCSBot::NoticeLooseBomb(this: (CCSBot *)LODWORD(v4)) )
    {
      CCSBot::FetchBomb(this: (CCSBot *)LODWORD(v4));
      return;
    }
    if ( CCSBot::IsRogue(this: (CCSBot *)LODWORD(v4)) )
      goto LABEL_195;
    if ( *(_DWORD *)(LODWORD(v4) + 14428) != 2 )
      goto LABEL_195;
    if ( CSGameState::GetBombPosition(this: (CSGameState *)(LODWORD(v4) + 14420)) == nullptr )
      goto LABEL_195;
    v80 = CSGameState::GetBombPosition(this: (CSGameState *)(LODWORD(v4) + 14420));
    if ( v80 == nullptr )
      goto LABEL_195;
    v113.x = 0.0;
    v112 = 750.0;
    range = -1.0;
    a3 = 120.0;
    *(_DWORD *)(LODWORD(v4) + 7844) = 4;
    durationa = v80;
LABEL_147:
    *(_DWORD *)(LODWORD(v4) + 7848) = -1;
    NavArea = (CCSNavArea *)CNavMesh::GetNavArea(this: TheNavMesh, pos: durationa, beneathLimit: a3);
    CCSBot::Hide(
      this: (CCSBot *)LODWORD(v4),
      searchFromArea: NavArea,
      duration: range,
      hideRange: v112,
      holdPosition: SLOBYTE(v113.x));
    return;
  }
  if ( CSGameState::GetPlantedBombsite(this: (CSGameState *)(LODWORD(v4) + 14420)) == -1 )
  {
    BotChatterInterface::RequestBombLocation(this: (BotChatterInterface *)(LODWORD(v4) + 16800));
    v69 = CSGameState::GetNextBombsiteToSearch(this: (CSGameState *)(LODWORD(v4) + 14420));
    v70 = CCSBotManager::GetRandomPositionInZone(
            this: (CCSBotManager *)TheBots,
            zone: (const CCSBotManager::Zone *)&TheBots[1].m_activeGrenadeList.m_Memory.m_nAllocationCount + v69);
    if ( v70 == nullptr )
      goto LABEL_195;
LABEL_120:
    *(_DWORD *)(LODWORD(v4) + 7844) = 2;
    *(_DWORD *)(LODWORD(v4) + 7848) = -1;
    CCSBot::MoveTo(this: (CCSBot *)LODWORD(v4), pos: v70, route: SAFEST_ROUTE);
    return;
  }
  v62 = TheBots;
  v63 = (const Vector *)(&v62[1].m_activeGrenadeList.m_Memory.m_nAllocationCount
                       + 30 * CSGameState::GetPlantedBombsite(this: (CSGameState *)(LODWORD(v4) + 14420)));
  if ( v63 == nullptr )
    goto LABEL_195;
  *(_DWORD *)(LODWORD(v4) + 7844) = 4;
  v64 = v63 + 6;
  *(_DWORD *)(LODWORD(v4) + 7848) = -1;
  v65 = CNavMesh::GetPlace(this: TheNavMesh, pos: v63 + 6);
  if ( v65 != 0
    && (IsSniper = CCSBot::IsSniper(this: (CCSBot *)LODWORD(v4)),
        (RandomHidingSpot = FindRandomHidingSpot(me: (CBaseEntity *)LODWORD(v4), place: v65, isSniper: IsSniper)) != nullptr) )
  {
    CCSBot::Hide(this: (CCSBot *)LODWORD(v4), hidingSpot: RandomHidingSpot, duration: -1.0, holdPosition: false);
  }
  else
  {
    v68 = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                          this: TheNavMesh,
                          pos: v64,
                          anyZ: false,
                          maxDist: 10000.0,
                          checkLOS: false,
                          checkGround: true);
    CCSBot::Hide(
      this: (CCSBot *)LODWORD(v4),
      searchFromArea: v68,
      duration: -1.0,
      hideRange: 750.0,
      holdPosition: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D77D0
// Name: __CreateCServerGameTagsIServerGameTags_interface_46
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_46()
{
  return &_g_CServerGameTags_singleton_46;
}
