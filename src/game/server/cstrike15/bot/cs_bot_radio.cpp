// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_radio.cpp
// Functions: 9
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_radio.h"

//------------------------------------------------------------------------------
// Address: 0x102B2FF0
// Name: public: struct CCSBotManager::Zone const __near * CCSBotManager::GetClosestZone(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
const CCSBotManager::Zone *__thiscall CCSBotManager::GetClosestZone(CCSBotManager *this, const Vector *pos)
{
  float v2; // xmm0_4
  int m_zoneCount; // ebx
  int v4; // eax
  unsigned int v5; // edi
  float *p_z; // edx
  float *v7; // ecx
  int v8; // ebx
  const CCSBotManager::Zone *close; // [esp+4h] [ebp-4h]

  v2 = 1000000000.0;
  m_zoneCount = this->m_zoneCount;
  v4 = 0;
  close = nullptr;
  if ( m_zoneCount >= 4 )
  {
    v5 = ((unsigned int)(m_zoneCount - 4) >> 2) + 1;
    p_z = &this->m_zone[0].m_center.z;
    v4 = 4 * v5;
    do
    {
      if ( *((_BYTE *)p_z + 12) == 0
        && v2 > (float)((float)((float)((float)(*(p_z - 2) - pos->x) * (float)(*(p_z - 2) - pos->x))
                              + (float)((float)(*(p_z - 1) - pos->y) * (float)(*(p_z - 1) - pos->y)))
                      + (float)((float)(*p_z - pos->z) * (float)(*p_z - pos->z))) )
      {
        v2 = (float)((float)((float)(*(p_z - 2) - pos->x) * (float)(*(p_z - 2) - pos->x))
                   + (float)((float)(*(p_z - 1) - pos->y) * (float)(*(p_z - 1) - pos->y)))
           + (float)((float)(*p_z - pos->z) * (float)(*p_z - pos->z));
        close = (const CCSBotManager::Zone *)(p_z - 20);
      }
      if ( *((_BYTE *)p_z + 132) == 0
        && v2 > (float)((float)((float)((float)(p_z[28] - pos->x) * (float)(p_z[28] - pos->x))
                              + (float)((float)(p_z[29] - pos->y) * (float)(p_z[29] - pos->y)))
                      + (float)((float)(p_z[30] - pos->z) * (float)(p_z[30] - pos->z))) )
      {
        v2 = (float)((float)((float)(p_z[28] - pos->x) * (float)(p_z[28] - pos->x))
                   + (float)((float)(p_z[29] - pos->y) * (float)(p_z[29] - pos->y)))
           + (float)((float)(p_z[30] - pos->z) * (float)(p_z[30] - pos->z));
        close = (const CCSBotManager::Zone *)(p_z + 10);
      }
      if ( *((_BYTE *)p_z + 252) == 0
        && v2 > (float)((float)((float)((float)(p_z[58] - pos->x) * (float)(p_z[58] - pos->x))
                              + (float)((float)(p_z[59] - pos->y) * (float)(p_z[59] - pos->y)))
                      + (float)((float)(p_z[60] - pos->z) * (float)(p_z[60] - pos->z))) )
      {
        v2 = (float)((float)((float)(p_z[58] - pos->x) * (float)(p_z[58] - pos->x))
                   + (float)((float)(p_z[59] - pos->y) * (float)(p_z[59] - pos->y)))
           + (float)((float)(p_z[60] - pos->z) * (float)(p_z[60] - pos->z));
        close = (const CCSBotManager::Zone *)(p_z + 40);
      }
      if ( *((_BYTE *)p_z + 372) == 0
        && v2 > (float)((float)((float)((float)(p_z[88] - pos->x) * (float)(p_z[88] - pos->x))
                              + (float)((float)(p_z[89] - pos->y) * (float)(p_z[89] - pos->y)))
                      + (float)((float)(p_z[90] - pos->z) * (float)(p_z[90] - pos->z))) )
      {
        v2 = (float)((float)((float)(p_z[88] - pos->x) * (float)(p_z[88] - pos->x))
                   + (float)((float)(p_z[89] - pos->y) * (float)(p_z[89] - pos->y)))
           + (float)((float)(p_z[90] - pos->z) * (float)(p_z[90] - pos->z));
        close = (const CCSBotManager::Zone *)(p_z + 70);
      }
      p_z += 120;
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( v4 < m_zoneCount )
  {
    v7 = &this->m_zone[v4].m_center.z;
    v8 = m_zoneCount - v4;
    do
    {
      if ( *((_BYTE *)v7 + 12) == 0
        && v2 > (float)((float)((float)((float)(*(v7 - 2) - pos->x) * (float)(*(v7 - 2) - pos->x))
                              + (float)((float)(*(v7 - 1) - pos->y) * (float)(*(v7 - 1) - pos->y)))
                      + (float)((float)(*v7 - pos->z) * (float)(*v7 - pos->z))) )
      {
        v2 = (float)((float)((float)(*(v7 - 2) - pos->x) * (float)(*(v7 - 2) - pos->x))
                   + (float)((float)(*(v7 - 1) - pos->y) * (float)(*(v7 - 1) - pos->y)))
           + (float)((float)(*v7 - pos->z) * (float)(*v7 - pos->z));
        close = (const CCSBotManager::Zone *)(v7 - 20);
      }
      v7 += 30;
      --v8;
    }
    while ( v8 != 0 );
  }
  return close;
}

//------------------------------------------------------------------------------
// Address: 0x102C0080
// Name: private: bool CCSBot::IsRadioCommand(enum RadioType)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsRadioCommand(CCSBot *this, RadioType event)
{
  return event != RADIO_AFFIRMATIVE
      && event != RADIO_NEGATIVE
      && event != RADIO_ENEMY_SPOTTED
      && event != RADIO_SECTOR_CLEAR
      && event != RADIO_REPORTING_IN
      && event != RADIO_REPORT_IN_TEAM
      && event != RADIO_ENEMY_DOWN
      && event != RADIO_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x102C00C0
// Name: public: struct CCSBotManager::Zone const __near * CCSBotManager::GetClosestZone(class CBaseEntity const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CCSBotManager::Zone *__thiscall CCSBotManager::GetClosestZone(CCSBotManager *this, CBaseEntity *entity)
{
  __int64 v4; // xmm0_8
  Vector centroid; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  if ( entity == nullptr )
    return nullptr;
  if ( (entity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
  v4 = *(_QWORD *)&entity->m_vecAbsOrigin.x;
  centroid.z = entity->m_vecAbsOrigin.z;
  *(_QWORD *)&centroid.x = v4;
  centroid.z = centroid.z + 35.5;
  return CCSBotManager::GetClosestZone(this, pos: &centroid);
}

//------------------------------------------------------------------------------
// Address: 0x102C0130
// Name: private: void CCSBot::RespondToRadioCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::RespondToRadioCommands(CCSBot *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // eax
  unsigned int v10; // eax
  IHandleEntity *m_pEntity; // ecx
  float v12; // xmm0_4
  unsigned int v13; // eax
  CCSPlayer **v14; // ecx
  CCSPlayer *v15; // edi
  CNavArea *NearestNavArea; // eax
  float curtime; // xmm0_4
  const CCSBotManager::Zone *ClosestZone; // eax
  CCSBot *v19; // ecx

  m_Index = this->m_radioSubject.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      v9 = v7 ? v8->m_pEntity : nullptr;
      if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v9->__vftable[28].dtr_IHandleEntity)(a1: v9) != 0 )
      {
        v10 = this->m_radioSubject.m_Index;
        if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
        if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[159].SetRefEHandle)(a1: m_pEntity) != 0 )
        {
          this->m_lastRadioCommand = RADIO_INVALID;
          return;
        }
      }
    }
  }
  if ( this->m_lastRadioCommand != RADIO_INVALID )
  {
    BotChatterInterface::ResetRadioSilenceDuration(this: &this->m_chatter);
    if ( this->m_lastRadioCommand != RADIO_REPORT_IN_TEAM && CCSBot::IsBusy(this) )
    {
LABEL_49:
      this->m_lastRadioCommand = RADIO_INVALID;
      return;
    }
    v12 = (float)(this->m_profile->m_reactionTime * 2.0) + 1.0;
    if ( CCSBot::IsRogue(this) )
      v12 = v12 + 2.0;
    if ( v12 <= (float)(gpGlobals->curtime - this->m_lastRadioRecievedTimestamp) )
    {
      if ( !this->m_isFollowing && CCSBot::IsRogue(this) )
      {
        if ( CCSBot::IsRadioCommand(this, event: this->m_lastRadioCommand) )
        {
          BotChatterInterface::Negative(this: &this->m_chatter);
          this->m_lastRadioCommand = RADIO_INVALID;
          return;
        }
        goto LABEL_49;
      }
      v13 = this->m_radioSubject.m_Index;
      if ( v13 != -1 )
      {
        v14 = (CCSPlayer **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v13];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber == HIWORD(v13) )
        {
          v15 = *v14;
          if ( *v14 != nullptr )
          {
            switch ( this->m_lastRadioCommand )
            {
              case RADIO_COVER_ME:
              case RADIO_REGROUP_TEAM:
              case RADIO_FOLLOW_ME:
              case RADIO_STICK_TOGETHER_TEAM:
                if ( this->m_isFollowing )
                  goto LABEL_49;
                CCSBot::Follow(this, player: *v14);
                v15->m_allowAutoFollowTime = 0.0;
                goto LABEL_46;
              case RADIO_HOLD_THIS_POSITION:
                this->m_task = HOLD_POSITION;
                this->m_taskEntity.m_Index = -1;
                CCSBot::StopFollowing(this);
                v15->m_allowAutoFollowTime = gpGlobals->curtime + 60.0;
                NearestNavArea = CNavMesh::GetNearestNavArea(
                                   this: TheNavMesh,
                                   pos: &this->m_radioPosition,
                                   anyZ: false,
                                   maxDist: 10000.0,
                                   checkLOS: false,
                                   checkGround: true);
                CCSBot::Hide(
                  this,
                  searchFromArea: NearestNavArea,
                  duration: -1.0,
                  hideRange: 750.0,
                  holdPosition: false);
                goto LABEL_46;
              case RADIO_TAKING_FIRE:
              case RADIO_ENEMY_SPOTTED:
              case RADIO_NEED_BACKUP:
                if ( this->m_isFollowing )
                  goto LABEL_49;
                CCSBot::Follow(this, player: *v14);
                BotChatterInterface::Say(this: &this->m_chatter, phraseName: "OnMyWay", lifetime: 3.0, delay: 0.0);
                v15->m_allowAutoFollowTime = 0.0;
                this->m_lastRadioCommand = RADIO_INVALID;
                return;
              case RADIO_GO_GO_GO:
              case RADIO_STORM_THE_FRONT:
                CCSBot::StopFollowing(this);
                CCSBot::Hunt(this);
                curtime = gpGlobals->curtime;
                goto LABEL_37;
              case RADIO_TEAM_FALL_BACK:
                if ( !CCSBot::TryToRetreat(this, maxRange: 1000.0, duration: -1.0) )
                  goto LABEL_49;
                goto LABEL_46;
              case RADIO_REPORT_IN_TEAM:
                BotChatterInterface::ReportingIn(this: &this->m_chatter);
                this->m_lastRadioCommand = RADIO_INVALID;
                return;
              case RADIO_SECTOR_CLEAR:
                if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory != (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
                  goto LABEL_49;
                if ( CBaseEntity::GetTeamNumber(this) != 3 )
                  goto LABEL_49;
                if ( TheBots[1].m_debugMessage[0].m_string[460] == 0 )
                  goto LABEL_49;
                ClosestZone = CCSBotManager::GetClosestZone(this: (CCSBotManager *)TheBots, entity: v15);
                if ( ClosestZone == nullptr )
                  goto LABEL_49;
                CSGameState::ClearBombsite(this: &this->m_gameState, zoneIndex: ClosestZone->m_index);
                if ( this->m_task == FIND_TICKING_BOMB )
                  CCSBot::Idle(this);
                goto LABEL_46;
              case RADIO_GET_OUT_OF_THERE:
                if ( TheBots[1].m_debugMessage[0].m_string[460] == 0 )
                  goto LABEL_49;
                CCSBot::EscapeFromBomb(this);
                curtime = gpGlobals->curtime;
LABEL_37:
                v15->m_allowAutoFollowTime = curtime + 60.0;
LABEL_46:
                BotChatterInterface::Affirmative(this: &this->m_chatter);
                if ( CCSBot::IsRadioCommand(this, event: this->m_lastRadioCommand) && CCSBot::IsUsingGrenade(this: v19) )
                  CCSBot::EquipBestWeapon(this, mustEquip: false);
                goto LABEL_49;
              default:
                return;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0580
// Name: public: void CCSBot::SpeakAudio(char const __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SpeakAudio(CCSBot *this, const char *voiceFilename, float duration, unsigned int pitch)
{
  edict_t *m_pPev; // eax
  CRecipientFilter filter; // [esp+8h] [ebp-20h] BYREF

  if ( this->IsAlive(this) && (this->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    CCSPlayer::ConstructRadioFilter(this, (CFmtStrN<1024> *)&filter);
    UserMessageBegin(&filter, messagename: "RawAudio");
    MessageWriteByte(iValue: pitch);
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    MessageWriteByte(iValue: (unsigned int)m_pPev);
    MessageWriteFloat(flValue: duration);
    MessageWriteString(sz: voiceFilename);
    MessageEnd();
    BotChatterInterface::ResetRadioSilenceDuration(this: &this->m_chatter);
    this->m_voiceEndTimestamp = gpGlobals->curtime + duration;
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0650
// Name: public: bool CCSBot::RespondToHelpRequest(class CCSPlayer __near *,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::RespondToHelpRequest(CCSBot *this, CCSPlayer *them, unsigned int place, float maxRange)
{
  CNavArea *NearestNavArea; // eax
  double v8; // st7
  float v9; // xmm1_4
  Vector *p_themOrigin; // eax
  Vector themOrigin; // [esp+1Ch] [ebp-14h] BYREF
  PathCost cost; // [esp+28h] [ebp-8h] BYREF
  int savedregs; // [esp+30h] [ebp+0h] BYREF
  float travelDistance; // [esp+38h] [ebp+8h]

  if ( CCSBot::IsRogue(this) || CCSBot::IsBusy(this) )
    return 0;
  GetCentroid(result: &themOrigin, player: them);
  if ( maxRange > 0.0 )
  {
    cost.m_bot = this;
    cost.m_route = SAFEST_ROUTE;
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: &themOrigin,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    v8 = NavAreaTravelDistance<PathCost>(
           startArea: this->m_lastKnownArea,
           endArea: NearestNavArea,
           costFunc: &cost,
           maxPathLength: 0.0);
    if ( v8 < 0.0 )
      return 0;
    travelDistance = v8;
    if ( travelDistance > maxRange )
      return 0;
  }
  if ( place == 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (them->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: them, a2: (int)&savedregs);
    v9 = them->m_vecAbsOrigin.y - this->m_vecAbsOrigin.y;
    if ( (float)((float)((float)((float)(them->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x)
                               * (float)(them->m_vecAbsOrigin.x - this->m_vecAbsOrigin.x))
                       + (float)(v9 * v9))
               + (float)((float)(them->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z)
                       * (float)(them->m_vecAbsOrigin.z - this->m_vecAbsOrigin.z))) < 562500.0 )
      return 1;
    p_themOrigin = &themOrigin;
    goto LABEL_15;
  }
  if ( CCSBot::GetPlace(this) != place )
  {
    p_themOrigin = GetRandomSpotAtPlace(place);
    if ( p_themOrigin == nullptr )
    {
      CCSBot::MoveTo(this, pos: &themOrigin, route: FASTEST_ROUTE);
      goto LABEL_19;
    }
LABEL_15:
    CCSBot::MoveTo(this, pos: p_themOrigin, route: FASTEST_ROUTE);
LABEL_19:
    BotChatterInterface::Say(this: &this->m_chatter, phraseName: "OnMyWay", lifetime: 3.0, delay: 0.0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102C07F0
// Name: public: void CCSBot::SendRadioMessage(enum RadioType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SendRadioMessage(CCSBot *this, RadioType event)
{
  CCSBotManager *v3; // ebx
  int TeamNumber; // eax

  if ( (unsigned int)(event - 2) <= 0x16 )
  {
    CBot<CCSPlayer>::PrintIfWatched(
      this,
      format: "%3.1f: SendRadioMessage( %s )\n",
      gpGlobals->curtime,
      RadioEventName[event]);
    v3 = (CCSBotManager *)TheBots;
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    CCSBotManager::SetRadioMessageTimestamp(this: v3, event, teamID: TeamNumber);
    this->m_lastRadioSentTimestamp = gpGlobals->curtime;
    if ( event >= RADIO_START_2 )
    {
      if ( (unsigned int)(event - 9) > 5 )
        CCSPlayer::HandleMenu_Radio3(this, slot: event - 15);
      else
        CCSPlayer::HandleMenu_Radio2(this, slot: event - 8);
    }
    else
    {
      CCSPlayer::HandleMenu_Radio1(this, slot: event - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D6070
// Name: public: struct CCSBotManager::Zone const __near * CCSBotManager::GetClosestZone<class PathCost>(class CNavArea __near *,class PathCost,float __near *)const
// Source: json
//------------------------------------------------------------------------------
const CCSBotManager::Zone *__thiscall CCSBotManager::GetClosestZone<PathCost>(
        CCSBotManager *this,
        CNavArea *startArea,
        PathCost costFunc,
        float *travelDistance)
{
  int v4; // edi
  bool *p_m_isBlocked; // esi
  double v8; // st7
  float dist; // [esp+10h] [ebp-Ch]
  const CCSBotManager::Zone *closeZone; // [esp+14h] [ebp-8h]
  float closeDist; // [esp+18h] [ebp-4h]

  v4 = 0;
  closeZone = nullptr;
  closeDist = 100000000.0;
  if ( startArea == nullptr )
    return nullptr;
  if ( this->m_zoneCount > 0 )
  {
    p_m_isBlocked = &this->m_zone[0].m_isBlocked;
    do
    {
      if ( *((_DWORD *)p_m_isBlocked - 6) != 0 && !*p_m_isBlocked )
      {
        v8 = NavAreaTravelDistance<PathCost>(
               startArea,
               endArea: (CNavArea *)*((_DWORD *)p_m_isBlocked - 22),
               &costFunc,
               maxPathLength: 0.0);
        if ( v8 >= 0.0 )
        {
          dist = v8;
          if ( closeDist > dist )
          {
            closeZone = (const CCSBotManager::Zone *)(p_m_isBlocked - 92);
            closeDist = v8;
          }
        }
      }
      ++v4;
      p_m_isBlocked += 120;
    }
    while ( v4 < this->m_zoneCount );
  }
  if ( travelDistance != nullptr )
    *travelDistance = closeDist;
  return closeZone;
}

//------------------------------------------------------------------------------
// Address: 0x102C08A0
// Name: __CreateCServerGameTagsIServerGameTags_interface_25
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_25()
{
  return &_g_CServerGameTags_singleton_25;
}
