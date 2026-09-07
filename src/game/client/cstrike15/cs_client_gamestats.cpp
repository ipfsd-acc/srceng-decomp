// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_client_gamestats.cpp
// Functions: 20
// ============================================================

#include "game\client\cstrike15\cs_client_gamestats.h"

//------------------------------------------------------------------------------
// Address: 0x101C2B00
// Name: protected: void CCSClientGameStats::RetrieveSteamStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::RetrieveSteamStats(CCSClientGameStats *this)
{
  bool v1; // zf
  int v2; // edi
  const char **v3; // esi
  IGameEvent *v4; // eax
  int iData; // [esp+0h] [ebp-8h] BYREF
  CCSClientGameStats *v6; // [esp+4h] [ebp-4h]

  v1 = steamapicontext->m_pSteamUserStats == nullptr;
  v6 = this;
  if ( !v1 && !this->m_bSteamStatsDownload )
  {
    v2 = 0;
    v3 = (const char **)off_105AF104;
    do
    {
      if ( *v3 != nullptr )
      {
        if ( steamapicontext->m_pSteamUserStats->GetStat_2(
               this: steamapicontext->m_pSteamUserStats,
               a2: *v3,
               a3: &iData) )
        {
          v6->m_lifetimeStats[0].m_iValue[(_DWORD)*(v3 - 1)] = iData;
        }
        else
        {
          ++v2;
        }
      }
      v3 += 4;
    }
    while ( (int)v3 < (int)&unk_105B0164 );
    if ( v2 <= 0 )
    {
      v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_stats_updated", a3: 0, a4: 0);
      if ( v4 != nullptr )
        gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v4);
      v6->m_bSteamStatsDownload = true;
    }
    else
    {
      _Msg(a1: "RetrieveSteamStats: failed to get %i stats\n", v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2BC0
// Name: protected: void CCSClientGameStats::UpdateSteamStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::UpdateSteamStats(CCSClientGameStats *this)
{
  const char **v2; // esi

  if ( steamapicontext->m_pSteamUserStats != nullptr )
  {
    if ( this->m_bSteamStatsDownload )
    {
      v2 = (const char **)off_105AF104;
      do
      {
        if ( *v2 != nullptr )
          steamapicontext->m_pSteamUserStats->SetStat_2(
            this: steamapicontext->m_pSteamUserStats,
            a2: *v2,
            a3: this->m_lifetimeStats[0].m_iValue[(_DWORD)*(v2 - 1)]);
        v2 += 4;
      }
      while ( (int)v2 < (int)&unk_105B0164 );
      g_AchievementMgrCS.m_bDirty[0] = true;
    }
    else if ( *(float *)(gpGlobals.m_Index + 12) > (float)(fLastStatsRetrieveTime + 30.0) )
    {
      fLastStatsRetrieveTime = *(float *)(gpGlobals.m_Index + 12);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2C40
// Name: public: struct PlayerStatData_t CCSClientGameStats::GetStatById(int,int)
// Source: json
//------------------------------------------------------------------------------
PlayerStatData_t *__thiscall CCSClientGameStats::GetStatById(
        CCSClientGameStats *this,
        PlayerStatData_t *result,
        unsigned int id,
        int nUserSlot)
{
  int statId; // edx
  char *v5; // eax
  vgui::ILocalize *v6; // ecx

  if ( id > 0x105 )
  {
    *(_QWORD *)&result->pStatDisplayName = 0xFFFFFFFF00000000uLL;
    result->iStatValue = 0;
    return result;
  }
  else
  {
    statId = CSStatProperty_Table[id].statId;
    v5 = (&off_105AF108)[4 * id];
    result->iStatValue = this->m_lifetimeStats[nUserSlot].m_iValue[statId];
    v6 = g_pVGuiLocalize;
    result->iStatId = statId;
    result->pStatDisplayName = v6->Find(this: v6, a2: v5);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2CC0
// Name: public: struct StatsCollection_t const __near & CCSClientGameStats::GetLifetimeStats(int)
// Source: json
//------------------------------------------------------------------------------
const StatsCollection_t *__thiscall CCSClientGameStats::GetLifetimeStats(CCSClientGameStats *this, int nUserSlot)
{
  return this->m_lifetimeStats;
}

//------------------------------------------------------------------------------
// Address: 0x101C2CE0
// Name: public: void CCSClientGameStats::ResetAllStats(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::ResetAllStats(CCSClientGameStats *this, int nUSerSlot)
{
  int v2; // eax
  char *v3; // edx
  IGameEvent *v4; // eax

  v2 = nUSerSlot;
  if ( nUSerSlot != 0 )
    v2 = 0;
  v3 = (char *)this + 1048 * v2;
  memset(v3 + 24, 0, 0x418u);
  memset(v3 + 1072, 0, 0x418u);
  memset(v3 + 2120, 0, 0x418u);
  CCSClientGameStats::UpdateSteamStats(this);
  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_stats_updated", a3: 0, a4: 0);
  if ( v4 != nullptr )
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101C2D60
// Name: public: void CCSClientGameStats::ResetMatchStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::ResetMatchStats(CCSClientGameStats *this)
{
  memset(this->m_matchStats, 0, sizeof(this->m_matchStats));
  this->m_matchMaxPlayerCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C2D80
// Name: public: void CCSClientGameStats::ResetRoundStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::ResetRoundStats(CCSClientGameStats *this)
{
  memset(this->m_roundStats, 0, sizeof(this->m_roundStats));
}

//------------------------------------------------------------------------------
// Address: 0x101C2DA0
// Name: protected: void CCSClientGameStats::CalculateMatchFavoriteWeapons(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::CalculateMatchFavoriteWeapons(CCSClientGameStats *this)
{
  int v1; // eax
  int v2; // ebx
  int v3; // edx
  int *v4; // esi
  int v5; // edx
  int v6; // esi
  int v7; // eax

  v1 = 0;
  v2 = -1;
  v3 = 22;
  v4 = &this->m_matchStats[0].m_iValue[21];
  do
  {
    if ( *(v4 - 1) > v1 )
    {
      v1 = *(v4 - 1);
      v2 = v3 - 2;
    }
    if ( *v4 > v1 )
    {
      v1 = *v4;
      v2 = v3 - 1;
    }
    if ( v4[1] > v1 )
    {
      v1 = v4[1];
      v2 = v3;
    }
    if ( v4[2] > v1 )
    {
      v1 = v4[2];
      v2 = v3 + 1;
    }
    v3 += 4;
    v4 += 4;
  }
  while ( v3 - 2 <= 35 );
  if ( v2 == -1 )
  {
    this->m_lifetimeStats[0].m_iValue[258] = 0;
    this->m_lifetimeStats[0].m_iValue[259] = 0;
    this->m_lifetimeStats[0].m_iValue[260] = 0;
    this->m_lifetimeStats[0].m_iValue[261] = 0;
  }
  else
  {
    v5 = 20;
    v6 = -1;
    v7 = 0;
    while ( v5 != v2 )
    {
      ++v7;
      v5 = dword_104A578C[5 * v7];
      if ( v5 == -1 )
        goto LABEL_18;
    }
    v6 = v7;
LABEL_18:
    this->m_lifetimeStats[0].m_iValue[258] = WeaponName_StatId_Table[v6].weaponId;
    this->m_lifetimeStats[0].m_iValue[259] = this->m_matchStats[0].m_iValue[dword_104A5790[5 * v6]];
    this->m_lifetimeStats[0].m_iValue[260] = this->m_matchStats[0].m_iValue[dword_104A5794[5 * v6]];
    this->m_lifetimeStats[0].m_iValue[261] = this->m_matchStats[0].m_iValue[dword_104A578C[5 * v6]];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C2E90
// Name: public: bool CCSClientGameStats::SyncCSMatchmakingDataToTitleData(int,enum CSSyncStatValueDirection_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSClientGameStats::SyncCSMatchmakingDataToTitleData(
        CCSClientGameStats *this,
        int iController,
        CSSyncStatValueDirection_t eOp)
{
  IMatchSystem *v3; // eax
  int v4; // eax

  v3 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v4 = v3->GetPlayerManager(this: v3);
  return (*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 4))(a1: v4, a2: iController) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C2EC0
// Name: public: CCSClientGameStats::CCSClientGameStats(void)
// Source: json
//------------------------------------------------------------------------------
CCSClientGameStats *__thiscall CCSClientGameStats::CCSClientGameStats(CCSClientGameStats *this)
{
  CAutoGameSystem::CAutoGameSystem(this, name: nullptr);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CAutoGameSystem::CBaseGameSystem::IGameSystem::__vftable = (CCSClientGameStats_vtbl *)&CCSClientGameStats::`vftable'{for `CAutoGameSystem'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSClientGameStats::`vftable'{for `CGameEventListener'};
  memset(this->m_lifetimeStats, 0, sizeof(this->m_lifetimeStats));
  memset(this->m_matchStats, 0, sizeof(this->m_matchStats));
  memset(this->m_roundStats, 0, sizeof(this->m_roundStats));
  memset(&this->m_directCTStatAverages, 0, sizeof(this->m_directCTStatAverages));
  memset(&this->m_directTStatAverages, 0, sizeof(this->m_directTStatAverages));
  memset(&this->m_directPlayerStatAverages, 0, sizeof(this->m_directPlayerStatAverages));
  this->m_bSteamStatsDownload = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C2F60
// Name: protected: virtual void CCSClientGameStats::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::FireGameEvent(CCSClientGameStats *this, IGameEvent *event)
{
  const char *v3; // edi
  int v4; // edi
  IMatchSystem *v5; // eax
  int v6; // eax
  int v7; // esi
  IMatchSystem *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  C_Team *GlobalTeam; // eax
  C_Team *v15; // eax
  float v16; // eax

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "player_stats_updated") != 0 )
  {
    if ( _V_strcmp(s1: v3, s2: "user_data_downloaded") != 0 )
    {
      if ( _V_strcmp(s1: v3, s2: "read_game_titledata") != 0 )
      {
        if ( _V_strcmp(s1: v3, s2: "write_game_titledata") != 0 )
        {
          if ( _V_strcmp(s1: v3, s2: "reset_game_titledata") != 0 )
          {
            if ( _V_strcmp(s1: v3, s2: "update_matchmaking_stats") != 0 )
            {
              if ( _V_strcmp(s1: v3, s2: "round_end") != 0 )
              {
                _V_strcmp(s1: v3, s2: "write_leaderboard_stats");
              }
              else
              {
                v13 = 0;
                if ( GetGlobalTeam(iTeamNumber: 3) != nullptr )
                {
                  GlobalTeam = GetGlobalTeam(iTeamNumber: 3);
                  v13 = GlobalTeam->Get_Number_Players(this: GlobalTeam);
                }
                if ( GetGlobalTeam(iTeamNumber: 2) != nullptr )
                {
                  v15 = GetGlobalTeam(iTeamNumber: 2);
                  v13 += v15->Get_Number_Players(this: v15);
                }
                v16 = this->m_directPlayerStatAverages.m_fStat[259];
                if ( SLODWORD(v16) <= v13 )
                  v16 = *(float *)&v13;
                this->m_directPlayerStatAverages.m_fStat[259] = v16;
              }
            }
          }
          else
          {
            InitBuyMenuLoadoutData();
            v12 = event->GetInt(this: event, a2: "controllerId", a3: 0);
            if ( v12 != 0 )
              v12 = 0;
            CCSClientGameStats::ResetAllStats(this: &g_CSClientGameStats, nUSerSlot: v12);
          }
        }
        else
        {
          ((void (__thiscall *)(IGameEvent *, const char *))event->GetInt)(a1: event, a2: "controllerId");
          v10 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))event->GetInt)(
                  a1: event,
                  a2: "controllerId",
                  a3: 0,
                  a4: 0);
          CCSClientGameStats::SyncCSMatchmakingDataToTitleData(
            this: (CCSClientGameStats *)((char *)this - 12),
            iController: v10,
            eOp: CSSTAT_WRITE_STAT);
          v11 = event->GetInt(this: event, a2: "controllerId", a3: 0);
          CCSClientGameStats::SyncCSMatchmakingDataToTitleData(
            this: (CCSClientGameStats *)((char *)this - 12),
            iController: v11,
            eOp: CSSTAT_WRITE_STAT);
        }
      }
      else
      {
        event->GetInt(this: event, a2: "controllerId", a3: 0);
        v4 = event->GetInt(this: event, a2: "controllerId", a3: 0);
        v5 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
        v6 = v5->GetPlayerManager(this: v5);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 4))(a1: v6, a2: v4);
        v7 = event->GetInt(this: event, a2: "controllerId", a3: 0);
        v8 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
        v9 = v8->GetPlayerManager(this: v8);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 4))(a1: v9, a2: v7);
      }
    }
    else
    {
      CCSClientGameStats::RetrieveSteamStats(this: (CCSClientGameStats *)((char *)this - 12));
    }
  }
  else
  {
    CCSClientGameStats::UpdateSteamStats(this: (CCSClientGameStats *)((char *)this - 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3190
// Name: protected: void CCSClientGameStats::UpdateStats(struct StatsCollection_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::UpdateStats(
        CCSClientGameStats *this,
        const StatsCollection_t *stats,
        int nUserSlot)
{
  char *v4; // esi
  IGameEvent *v5; // eax

  if ( CClientTools::GetLocalPlayer() != nullptr
    && CAchievementMgr::CheckAchievementsEnabled(this: &g_AchievementMgrCS) != 0 )
  {
    if ( !C_CSGameRules::IsPlayingFreestyle(this: (C_CSGameRules *)g_pGameRules) )
    {
      v4 = (char *)this + 1048 * nUserSlot;
      StatsCollection_t::Aggregate(this: (StatsCollection_t *)(v4 + 24), other: stats);
      StatsCollection_t::Aggregate(this: (StatsCollection_t *)(v4 + 1072), other: stats);
      StatsCollection_t::Aggregate(this: (StatsCollection_t *)(v4 + 2120), other: stats);
    }
    v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_stats_updated", a3: 0, a4: 0);
    if ( v5 != nullptr )
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3220
// Name: public: void CCSClientGameStats::UpdateLastMatchStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::UpdateLastMatchStats(CCSClientGameStats *this)
{
  int v2; // edi
  int *i; // esi
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // eax

  v2 = 0;
  for ( i = &this->m_lifetimeStats[0].m_iValue[244]; i[31] != 0; i += 262 )
  {
    if ( i[22] + i[28] + i[189] + i[21] + i[20] + i[185] != 0
      && !C_CSGameRules::IsPlayingFreestyle(this: (C_CSGameRules *)g_pGameRules) )
    {
      v4 = i[191];
      v5 = i[29];
      *i = i[190];
      i[3] = i[30];
      v6 = i[20];
      i[1] = v4;
      v7 = i[28];
      i[2] = v5;
      v8 = i[31];
      i[6] = v6;
      v9 = i[22];
      i[4] = v7;
      v10 = i[21];
      i[5] = v8;
      v11 = i[189];
      i[9] = v9;
      v12 = i[188];
      i[7] = v10;
      v13 = i[185];
      i[8] = v11;
      v14 = i[186];
      i[12] = v12;
      i[10] = v13;
      i[11] = v14;
      i[13] = this->m_matchMaxPlayerCount;
      CCSClientGameStats::CalculateMatchFavoriteWeapons(this);
    }
    if ( ++v2 >= 1 )
    {
      memset(this->m_matchStats, 0, sizeof(this->m_matchStats));
      this->m_matchMaxPlayerCount = 0;
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3360
// Name: public: virtual void CCSClientGameStats::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::LevelShutdownPreEntity(CCSClientGameStats *this)
{
  CCSClientGameStats::UpdateLastMatchStats(this);
  CCSClientGameStats::UpdateSteamStats(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C3370
// Name: public: void CCSClientGameStats::MsgFunc_MatchStatsUpdate(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::MsgFunc_MatchStatsUpdate(CCSClientGameStats *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  __int16 v5; // si
  int v6; // ecx
  __int16 v7; // di
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v13; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v15; // esi
  unsigned int v16; // ebx
  const unsigned int *m_pData; // ecx
  int m_nDataBits; // ecx
  int v19; // esi
  unsigned int v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // esi
  const unsigned int *v23; // ecx
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // esi
  unsigned int v27; // esi
  unsigned int v28; // ebx
  int v29; // esi
  unsigned int v30; // ecx
  const unsigned int *v31; // edx
  const unsigned int *v32; // esi
  const unsigned int *v33; // ecx
  unsigned int v34; // edi
  int v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // esi
  unsigned int v38; // ebx
  int v39; // esi
  unsigned int v40; // ecx
  const unsigned int *v41; // edx
  const unsigned int *v42; // esi
  const unsigned int *v43; // ecx
  unsigned int v44; // edi
  int v45; // edx
  const unsigned int *v46; // esi
  unsigned int v47; // esi
  unsigned int v48; // ebx
  int iStat; // [esp+Ch] [ebp-8h]
  int v51; // [esp+10h] [ebp-4h]
  int v52; // [esp+10h] [ebp-4h]
  int v53; // [esp+10h] [ebp-4h]
  bf_read *msga; // [esp+1Ch] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v13 = 16 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v15 = msg->m_nInBufWord;
      v16 = (v15 & CBitBuffer::s_nMaskTable[v13]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v13;
      v7 = v16 | m_nInBufWord;
      msg->m_nInBufWord = v15 >> v13;
    }
    goto LABEL_19;
  }
  v4 = msg->m_nInBufWord;
  v5 = v4;
  v6 = m_nBitsAvail - 16;
  msg->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v4);
    v7 = v4;
  }
  else
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v8 + 1;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        v10 = *v8;
        msg->m_pDataIn = v8 + 1;
        msg->m_nInBufWord = v10;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  iStat = v7;
  if ( v7 < 262 )
  {
    for ( msga = (bf_read *)&this->m_directCTStatAverages.m_fStat[v7]; ; msga = (bf_read *)((char *)msga + 4) )
    {
      m_pData = msg->m_pData;
      if ( m_pData != nullptr )
      {
        m_nDataBits = 32 * (msg->m_pDataIn - m_pData) - msg->m_nBitsAvail + 8 * (msg->m_nDataBytes & 3);
        if ( m_nDataBits >= msg->m_nDataBits )
          m_nDataBits = msg->m_nDataBits;
      }
      else
      {
        m_nDataBits = 0;
      }
      if ( msg->m_nDataBits - m_nDataBits < 0 || ((msg->m_nDataBits - m_nDataBits) & 0xFFFFFFF8) == 0 )
        return;
      v19 = msg->m_nBitsAvail;
      if ( v19 < 32 )
        break;
      v20 = msg->m_nInBufWord;
      msg->m_nBitsAvail = v19 - 32;
      if ( v19 == 32 )
      {
        v21 = msg->m_pDataIn;
        v22 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v21 == v22 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v21 + 1;
          v51 = v20;
        }
        else
        {
          if ( v21 <= v22 )
          {
            msg->m_nInBufWord = *v21;
            msg->m_pDataIn = v21 + 1;
          }
          else
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
          }
          v51 = v20;
        }
      }
      else
      {
        msg->m_nInBufWord = 0;
        v51 = v20;
      }
LABEL_44:
      *(_DWORD *)&msga[29].m_bOverflow = v51;
      v29 = msg->m_nBitsAvail;
      if ( v29 < 32 )
      {
        v33 = msg->m_pDataIn;
        v34 = msg->m_nInBufWord;
        v35 = 32 - v29;
        v36 = msg->m_pBufferEnd;
        if ( v33 == v36 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
          goto LABEL_58;
        }
        if ( v33 <= v36 )
        {
          msg->m_nInBufWord = *v33;
LABEL_58:
          msg->m_pDataIn = v33 + 1;
        }
        else
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
        }
        if ( msg->m_bOverflow )
        {
          v52 = 0;
        }
        else
        {
          v37 = msg->m_nInBufWord;
          v38 = (v37 & CBitBuffer::s_nMaskTable[v35]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v35;
          v52 = v38 | v34;
          msg->m_nInBufWord = v37 >> v35;
        }
        goto LABEL_62;
      }
      v30 = msg->m_nInBufWord;
      msg->m_nBitsAvail = v29 - 32;
      if ( v29 == 32 )
      {
        v31 = msg->m_pDataIn;
        v32 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v31 == v32 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v31 + 1;
          v52 = v30;
        }
        else
        {
          if ( v31 <= v32 )
          {
            msg->m_nInBufWord = *v31;
            msg->m_pDataIn = v31 + 1;
          }
          else
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
          }
          v52 = v30;
        }
      }
      else
      {
        msg->m_nInBufWord = 0;
        v52 = v30;
      }
LABEL_62:
      msga->m_pDebugName = (const char *)v52;
      v39 = msg->m_nBitsAvail;
      if ( v39 >= 32 )
      {
        v40 = msg->m_nInBufWord;
        msg->m_nBitsAvail = v39 - 32;
        if ( v39 == 32 )
        {
          v41 = msg->m_pDataIn;
          v42 = msg->m_pBufferEnd;
          msg->m_nBitsAvail = 32;
          if ( v41 == v42 )
          {
            msg->m_nBitsAvail = 1;
            msg->m_nInBufWord = 0;
            msg->m_pDataIn = v41 + 1;
            v53 = v40;
          }
          else
          {
            if ( v41 <= v42 )
            {
              msg->m_nInBufWord = *v41;
              msg->m_pDataIn = v41 + 1;
            }
            else
            {
              msg->m_bOverflow = true;
              msg->m_nInBufWord = 0;
            }
            v53 = v40;
          }
        }
        else
        {
          msg->m_nInBufWord = 0;
          v53 = v40;
        }
        goto LABEL_80;
      }
      v43 = msg->m_pDataIn;
      v44 = msg->m_nInBufWord;
      v45 = 32 - v39;
      v46 = msg->m_pBufferEnd;
      if ( v43 == v46 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      else
      {
        if ( v43 > v46 )
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
          goto LABEL_77;
        }
        msg->m_nInBufWord = *v43;
      }
      msg->m_pDataIn = v43 + 1;
LABEL_77:
      if ( msg->m_bOverflow )
      {
        v53 = 0;
      }
      else
      {
        v47 = msg->m_nInBufWord;
        v48 = (v47 & CBitBuffer::s_nMaskTable[v45]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v45;
        v53 = v48 | v44;
        msg->m_nInBufWord = v47 >> v45;
      }
LABEL_80:
      msga[58].m_nDataBits = v53;
      if ( ++iStat >= 262 )
        return;
    }
    v23 = msg->m_pDataIn;
    v24 = msg->m_nInBufWord;
    v25 = 32 - v19;
    v26 = msg->m_pBufferEnd;
    if ( v23 == v26 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v26 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_41;
      }
      msg->m_nInBufWord = *v23;
    }
    msg->m_pDataIn = v23 + 1;
LABEL_41:
    if ( msg->m_bOverflow )
    {
      v51 = 0;
    }
    else
    {
      v27 = msg->m_nInBufWord;
      v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v25;
      v51 = v28 | v24;
      msg->m_nInBufWord = v27 >> v25;
    }
    goto LABEL_44;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C37A0
// Name: public: void CCSClientGameStats::MsgFunc_PlayerStatsUpdate(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::MsgFunc_PlayerStatsUpdate(CCSClientGameStats *this, bf_read *msg)
{
  bf_read *v2; // esi
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v5; // edx
  int v6; // ecx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  char v17; // dl
  int v18; // ecx
  const unsigned int *v19; // ecx
  unsigned int v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edi
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ebx
  unsigned int v26; // edx
  int v27; // ecx
  unsigned int v28; // eax
  __int16 v29; // dx
  int v30; // ecx
  const unsigned int *v31; // ecx
  unsigned int v32; // ecx
  const unsigned int *v33; // edx
  unsigned int v34; // edi
  const unsigned int *v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // ebx
  unsigned int v38; // edx
  int v39; // ecx
  unsigned int v40; // edx
  unsigned __int16 v41; // ax
  int v42; // ecx
  unsigned int v43; // edx
  const unsigned int *v44; // ecx
  const unsigned int *v45; // edx
  const unsigned int *v46; // edx
  unsigned int v47; // edi
  int v48; // eax
  const unsigned int *v49; // ecx
  unsigned int v50; // edx
  unsigned int v51; // ebx
  int v52; // eax
  int v53; // eax
  const unsigned int *v54; // eax
  const unsigned int *v55; // ecx
  const unsigned int *v56; // edx
  int v57; // ecx
  const unsigned int *v58; // eax
  int v59; // ecx
  unsigned int v60; // eax
  int v61; // ecx
  int v62; // edi
  const unsigned int *v63; // ecx
  const unsigned int *v64; // edx
  const unsigned int *v65; // edx
  unsigned int v66; // edi
  int v67; // eax
  const unsigned int *v68; // ecx
  unsigned int v69; // edx
  unsigned int v70; // ebx
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  int v73; // eax
  StatsCollection_t deltaStats; // [esp+Ch] [ebp-430h] BYREF
  unsigned int key; // [esp+424h] [ebp-18h] BYREF
  CCSClientGameStats *v76; // [esp+428h] [ebp-14h]
  int delta; // [esp+42Ch] [ebp-10h] BYREF
  int i; // [esp+430h] [ebp-Ch]
  unsigned int crc; // [esp+434h] [ebp-8h] BYREF
  unsigned __int8 version; // [esp+43Ah] [ebp-2h] BYREF
  unsigned __int8 iStatsToRead; // [esp+43Bh] [ebp-1h] BYREF

  v76 = this;
  memset(&deltaStats, 0, sizeof(deltaStats));
  CRC32_Init(pulCRC: &crc);
  key = -2099601588;
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &key, nBuffer: 4);
  version = 2;
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &version, nBuffer: 1);
  v2 = msg;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    v6 = m_nBitsAvail - 8;
    msg->m_nBitsAvail = v6;
    if ( v6 != 0 )
    {
      v2->m_nInBufWord = m_nInBufWord >> 8;
    }
    else
    {
      m_pDataIn = v2->m_pDataIn;
      m_pBufferEnd = v2->m_pBufferEnd;
      v2->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        v2->m_nBitsAvail = 1;
        v2->m_nInBufWord = 0;
        v2->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        v2->m_nInBufWord = *m_pDataIn;
        v2->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
      }
    }
    goto LABEL_17;
  }
  v9 = msg->m_pBufferEnd;
  v10 = msg->m_nInBufWord;
  v11 = 8 - m_nBitsAvail;
  v12 = (unsigned int *)msg->m_pDataIn;
  if ( v12 == v9 )
  {
    msg->m_nBitsAvail = 1;
    v2->m_nInBufWord = 0;
    v2->m_bOverflow = true;
LABEL_14:
    v2->m_pDataIn = v12 + 1;
    goto LABEL_15;
  }
  if ( v12 <= v9 )
  {
    msg->m_nInBufWord = *v12;
    goto LABEL_14;
  }
  msg->m_bOverflow = true;
  v2->m_nInBufWord = 0;
LABEL_15:
  if ( v2->m_bOverflow )
  {
LABEL_18:
    _Warning(a1: "PlayerStatsUpdate message: ignoring unsupported version\n");
    return;
  }
  v13 = v2->m_nInBufWord;
  v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << v2->m_nBitsAvail;
  v2->m_nBitsAvail = 32 - v11;
  v2->m_nInBufWord = v13 >> v11;
  v5 = v14 | v10;
LABEL_17:
  if ( v5 != 2 )
    goto LABEL_18;
  v15 = v2->m_nBitsAvail;
  if ( v15 < 8 )
  {
    v21 = v2->m_pBufferEnd;
    v22 = v2->m_nInBufWord;
    v16 = 8 - v15;
    v23 = v2->m_pDataIn;
    if ( v23 == v21 )
    {
      v2->m_nBitsAvail = 1;
      v2->m_nInBufWord = 0;
      v2->m_bOverflow = true;
    }
    else
    {
      if ( v23 > v21 )
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
        goto LABEL_34;
      }
      v2->m_nInBufWord = *v23;
    }
    v2->m_pDataIn = v23 + 1;
LABEL_34:
    if ( v2->m_bOverflow )
    {
      LOBYTE(v16) = 0;
    }
    else
    {
      v24 = v2->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v16]) << v2->m_nBitsAvail;
      v2->m_nBitsAvail = 32 - v16;
      v26 = v24 >> v16;
      LOBYTE(v16) = v25 | v22;
      v2->m_nInBufWord = v26;
    }
    goto LABEL_37;
  }
  v16 = v2->m_nInBufWord;
  v17 = v16;
  v18 = v15 - 8;
  v2->m_nBitsAvail = v18;
  if ( v18 != 0 )
  {
    v2->m_nInBufWord = v16 >> 8;
  }
  else
  {
    v16 = (unsigned int)v2->m_pDataIn;
    v19 = v2->m_pBufferEnd;
    v2->m_nBitsAvail = 32;
    if ( (const unsigned int *)v16 == v19 )
    {
      v2->m_pDataIn = (const unsigned int *)(v16 + 4);
      v2->m_nBitsAvail = 1;
      v2->m_nInBufWord = 0;
      LOBYTE(v16) = v17;
    }
    else
    {
      if ( v16 <= (unsigned int)v19 )
      {
        v20 = *(_DWORD *)v16;
        v2->m_pDataIn = (const unsigned int *)(v16 + 4);
        v2->m_nInBufWord = v20;
      }
      else
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
      }
      LOBYTE(v16) = v17;
    }
  }
LABEL_37:
  iStatsToRead = v16;
  CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &iStatsToRead, nBuffer: 1);
  i = 0;
  if ( iStatsToRead != 0 )
  {
    while ( 1 )
    {
      v27 = v2->m_nBitsAvail;
      if ( v27 < 16 )
        break;
      v28 = v2->m_nInBufWord;
      v29 = v28;
      v30 = v27 - 16;
      v2->m_nBitsAvail = v30;
      if ( v30 != 0 )
      {
        v2->m_nInBufWord = HIWORD(v28);
      }
      else
      {
        v28 = (unsigned int)v2->m_pDataIn;
        v31 = v2->m_pBufferEnd;
        v2->m_nBitsAvail = 32;
        if ( (const unsigned int *)v28 == v31 )
        {
          v2->m_pDataIn = (const unsigned int *)(v28 + 4);
          v2->m_nBitsAvail = 1;
          v2->m_nInBufWord = 0;
          LOWORD(v28) = v29;
        }
        else
        {
          if ( v28 <= (unsigned int)v31 )
          {
            v32 = *(_DWORD *)v28;
            v2->m_pDataIn = (const unsigned int *)(v28 + 4);
            v2->m_nInBufWord = v32;
          }
          else
          {
            v2->m_bOverflow = true;
            v2->m_nInBufWord = 0;
          }
          LOWORD(v28) = v29;
        }
      }
LABEL_56:
      msg = (bf_read *)(unsigned __int16)v28;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &msg, nBuffer: 2);
      if ( (__int16)msg >= 262 )
      {
        _Warning(a1: "PlayerStatsUpdate: invalid statId encountered; ignoring stats update\n");
        return;
      }
      v39 = v2->m_nBitsAvail;
      if ( v39 < 16 )
      {
        v46 = v2->m_pBufferEnd;
        v47 = v2->m_nInBufWord;
        v48 = 16 - v39;
        v49 = v2->m_pDataIn;
        if ( v49 == v46 )
        {
          v2->m_nBitsAvail = 1;
          v2->m_nInBufWord = 0;
          v2->m_bOverflow = true;
          goto LABEL_70;
        }
        if ( v49 <= v46 )
        {
          v2->m_nInBufWord = *v49;
LABEL_70:
          v2->m_pDataIn = v49 + 1;
        }
        else
        {
          v2->m_bOverflow = true;
          v2->m_nInBufWord = 0;
        }
        if ( !v2->m_bOverflow )
        {
          v50 = v2->m_nInBufWord;
          v51 = (v50 & CBitBuffer::s_nMaskTable[v48]) << v2->m_nBitsAvail;
          v2->m_nBitsAvail = 32 - v48;
          v43 = v50 >> v48;
          v41 = v51 | v47;
          goto LABEL_74;
        }
        v41 = 0;
        goto LABEL_75;
      }
      v40 = v2->m_nInBufWord;
      v41 = v40;
      v42 = v39 - 16;
      v2->m_nBitsAvail = v42;
      if ( v42 != 0 )
      {
        v43 = HIWORD(v40);
LABEL_74:
        v2->m_nInBufWord = v43;
        goto LABEL_75;
      }
      v44 = v2->m_pDataIn;
      v45 = v2->m_pBufferEnd;
      v2->m_nBitsAvail = 32;
      if ( v44 == v45 )
      {
        v2->m_nBitsAvail = 1;
        v2->m_nInBufWord = 0;
        v2->m_pDataIn = v44 + 1;
      }
      else
      {
        if ( v44 <= v45 )
        {
          v43 = *v44;
          v2->m_pDataIn = v44 + 1;
          goto LABEL_74;
        }
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
      }
LABEL_75:
      delta = v41;
      deltaStats.m_iValue[(__int16)msg] = (__int16)v41;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &delta, nBuffer: 2);
      if ( ++i >= iStatsToRead )
        goto LABEL_76;
    }
    v33 = v2->m_pBufferEnd;
    v34 = v2->m_nInBufWord;
    v28 = 16 - v27;
    v35 = v2->m_pDataIn;
    if ( v35 == v33 )
    {
      v2->m_nBitsAvail = 1;
      v2->m_nInBufWord = 0;
      v2->m_bOverflow = true;
    }
    else
    {
      if ( v35 > v33 )
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
        goto LABEL_53;
      }
      v2->m_nInBufWord = *v35;
    }
    v2->m_pDataIn = v35 + 1;
LABEL_53:
    if ( v2->m_bOverflow )
    {
      LOWORD(v28) = 0;
    }
    else
    {
      v36 = v2->m_nInBufWord;
      v37 = (v36 & CBitBuffer::s_nMaskTable[v28]) << v2->m_nBitsAvail;
      v2->m_nBitsAvail = 32 - v28;
      v38 = v36 >> v28;
      LOWORD(v28) = v37 | v34;
      v2->m_nInBufWord = v38;
    }
    goto LABEL_56;
  }
LABEL_76:
  v52 = v2->m_nBitsAvail;
  if ( v52 >= 16 )
  {
    v53 = v52 - 16;
    v2->m_nBitsAvail = v53;
    if ( v53 != 0 )
    {
      v2->m_nInBufWord = HIWORD(v2->m_nInBufWord);
    }
    else
    {
      v54 = v2->m_pDataIn;
      v55 = v2->m_pBufferEnd;
      v2->m_nBitsAvail = 32;
      if ( v54 == v55 )
      {
        v2->m_nBitsAvail = 1;
        v2->m_nInBufWord = 0;
        v2->m_pDataIn = v54 + 1;
      }
      else if ( v54 <= v55 )
      {
        v2->m_nInBufWord = *v54;
        v2->m_pDataIn = v54 + 1;
      }
      else
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
      }
    }
    goto LABEL_93;
  }
  v56 = v2->m_pBufferEnd;
  v57 = 16 - v52;
  v58 = v2->m_pDataIn;
  if ( v58 == v56 )
  {
    v2->m_nBitsAvail = 1;
    v2->m_nInBufWord = 0;
    v2->m_bOverflow = true;
  }
  else
  {
    if ( v58 > v56 )
    {
      v2->m_bOverflow = true;
      v2->m_nInBufWord = 0;
      goto LABEL_91;
    }
    v2->m_nInBufWord = *v58;
  }
  v2->m_pDataIn = v58 + 1;
LABEL_91:
  if ( !v2->m_bOverflow )
  {
    v2->m_nInBufWord >>= v57;
    v2->m_nBitsAvail = 32 - v57;
  }
LABEL_93:
  CRC32_Final(pulCRC: &crc);
  v59 = v2->m_nBitsAvail;
  if ( v59 < 32 )
  {
    v65 = v2->m_pBufferEnd;
    v66 = v2->m_nInBufWord;
    v67 = 32 - v59;
    v68 = v2->m_pDataIn;
    if ( v68 == v65 )
    {
      v2->m_nBitsAvail = 1;
      v2->m_nInBufWord = 0;
      v2->m_bOverflow = true;
    }
    else
    {
      if ( v68 > v65 )
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
        goto LABEL_108;
      }
      v2->m_nInBufWord = *v68;
    }
    v2->m_pDataIn = v68 + 1;
LABEL_108:
    if ( v2->m_bOverflow )
    {
      v62 = 0;
    }
    else
    {
      v69 = v2->m_nInBufWord;
      v70 = (v69 & CBitBuffer::s_nMaskTable[v67]) << v2->m_nBitsAvail;
      v2->m_nBitsAvail = 32 - v67;
      v62 = v70 | v66;
      v2->m_nInBufWord = v69 >> v67;
    }
    goto LABEL_111;
  }
  v60 = v2->m_nInBufWord;
  v61 = v59 - 32;
  v2->m_nBitsAvail = v61;
  if ( v61 != 0 )
  {
    v2->m_nInBufWord = 0;
    v62 = v60;
  }
  else
  {
    v63 = v2->m_pDataIn;
    v64 = v2->m_pBufferEnd;
    v2->m_nBitsAvail = 32;
    if ( v63 == v64 )
    {
      v2->m_nBitsAvail = 1;
      v2->m_nInBufWord = 0;
      v2->m_pDataIn = v63 + 1;
      v62 = v60;
    }
    else
    {
      if ( v63 <= v64 )
      {
        v2->m_nInBufWord = *v63;
        v2->m_pDataIn = v63 + 1;
      }
      else
      {
        v2->m_bOverflow = true;
        v2->m_nInBufWord = 0;
      }
      v62 = v60;
    }
  }
LABEL_111:
  if ( v62 != crc || v2->m_bOverflow )
    goto LABEL_123;
  m_pData = v2->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (v2->m_pDataIn - m_pData) - v2->m_nBitsAvail + 8 * (v2->m_nDataBytes & 3);
    if ( m_nDataBits >= v2->m_nDataBits )
      m_nDataBits = v2->m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( ((v2->m_nDataBits - m_nDataBits) & 0xFFFFFFF8) != 0 )
  {
LABEL_123:
    _Warning(a1: "PlayerStatsUpdate message from server is corrupt; ignoring\n");
  }
  else
  {
    v73 = 0;
    while ( deltaStats.m_iValue[v73] < 0x4000u )
    {
      if ( ++v73 >= 262 )
      {
        CCSClientGameStats::UpdateStats(this: v76, stats: &deltaStats, nUserSlot: 0);
        return;
      }
    }
    _Warning(a1: "PlayerStatsUpdate message from server has out of band values; ignoring\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C3E30
// Name: void MsgFunc_PlayerStatsUpdate(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_PlayerStatsUpdate(bf_read *msg)
{
  CCSClientGameStats::MsgFunc_PlayerStatsUpdate(this: &g_CSClientGameStats, msg);
}

//------------------------------------------------------------------------------
// Address: 0x101C3E50
// Name: void MsgFunc_MatchStatsUpdate(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_MatchStatsUpdate(bf_read *msg)
{
  CCSClientGameStats::MsgFunc_MatchStatsUpdate(this: &g_CSClientGameStats, msg);
}

//------------------------------------------------------------------------------
// Address: 0x101C3E70
// Name: public: virtual void CCSClientGameStats::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSClientGameStats::PostInit(CCSClientGameStats *this)
{
  CGameEventListener *v1; // esi

  v1 = &this->CGameEventListener;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "player_stats_updated",
    a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "user_data_downloaded", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "round_end", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "read_game_titledata", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "write_game_titledata", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "reset_game_titledata", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "update_matchmaking_stats", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "write_leaderboard_stats", a4: false);
  CUserMessages::HookMessage(this: usermessages, name: "PlayerStatsUpdate", hook: MsgFunc_PlayerStatsUpdate);
  CUserMessages::HookMessage(this: usermessages, name: "MatchStatsUpdate", hook: MsgFunc_MatchStatsUpdate);
}

//------------------------------------------------------------------------------
// Address: 0x101C3F70
// Name: __CreateCGameMovementIGameMovement_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCSGameMovement *__cdecl _CreateCGameMovementIGameMovement_interface()
{
  return &g_GameMovement;
}
