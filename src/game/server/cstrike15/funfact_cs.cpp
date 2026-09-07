// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/funfact_cs.cpp
// Functions: 136
// ============================================================

#include "game\server\cstrike15\funfact_cs.h"

//------------------------------------------------------------------------------
// Address: 0x1029C0B0
// Name: bool PlayerQualifies(class CBasePlayer const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PlayerQualifies(CBasePlayer *pPlayer, __int16 flags)
{
  CGameRules *v3; // edi
  CGameRules *v4; // edi
  bool IsPlayingGunGameTRBomb; // bl

  if ( (flags & 1) != 0 && CBaseEntity::GetTeamNumber(this: pPlayer) != 3
    || (flags & 2) != 0 && CBaseEntity::GetTeamNumber(this: pPlayer) != 2
    || CBaseEntity::GetTeamNumber(this: pPlayer) == 1
    || (flags & 0x10) != 0 && pPlayer->IsAlive(this: pPlayer)
    || (flags & 8) != 0 && !pPlayer->IsAlive(this: pPlayer) )
  {
    return false;
  }
  if ( (flags & 0x20) != 0 )
  {
    v3 = g_pGameRules;
    if ( (const char *)CBaseEntity::GetTeamNumber(this: pPlayer) != v3[130].m_pszName )
      return false;
  }
  if ( (flags & 0x40) != 0 )
  {
    v4 = g_pGameRules;
    if ( (const char *)CBaseEntity::GetTeamNumber(this: pPlayer) == v4[130].m_pszName )
      return false;
  }
  IsPlayingGunGameTRBomb = false;
  if ( (flags & 0x80u) != 0 )
    IsPlayingGunGameTRBomb = CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules);
  if ( (flags & 0x100) != 0 && CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
    IsPlayingGunGameTRBomb = true;
  if ( (flags & 0x200) != 0
    && (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    IsPlayingGunGameTRBomb = true;
  }
  return CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules) && (flags & 0x400) == 0
      || IsPlayingGunGameTRBomb;
}

//------------------------------------------------------------------------------
// Address: 0x1029C1D0
// Name: float GetTeamAccuracy(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetTeamAccuracy(int teamNumber)
{
  int v1; // edi
  int v2; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  int i; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v2 = 0;
  i = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0.0;
  do
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && CBaseEntity::GetTeamNumber(this: v3) == teamNumber )
    {
      v1 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v4)->statsCurrentRound.m_iValue[1];
      v2 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v4)->statsCurrentRound.m_iValue[0];
    }
    ++i;
  }
  while ( i <= gpGlobals->maxClients );
  if ( v1 <= 10 )
    return 0.0;
  else
    return (double)v2 / (double)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029C270
// Name: bool FFEVAL_CT_WIN_NO_KILLS(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_CT_WIN_NO_KILLS()
{
  BOOL result; // eax

  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return g_pGameRules[130].m_pszName == (const char *)3 && LOBYTE(g_pGameRules[138].m_pNext) != 0;
  result = CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules);
  if ( result )
    return g_pGameRules[130].m_pszName == (const char *)3 && LOBYTE(g_pGameRules[138].m_pNext) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C2B0
// Name: bool FFEVAL_T_WIN_NO_KILLS(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_T_WIN_NO_KILLS()
{
  BOOL result; // eax

  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return g_pGameRules[130].m_pszName == (const char *)2 && BYTE1(g_pGameRules[138].m_pNext) != 0;
  result = CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules);
  if ( result )
    return g_pGameRules[130].m_pszName == (const char *)2 && BYTE1(g_pGameRules[138].m_pNext) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C2F0
// Name: bool FFEVAL_T_WIN_NO_CASUALTIES(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_T_WIN_NO_CASUALTIES()
{
  BOOL result; // eax

  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return g_pGameRules[130].m_pszName == (const char *)2 && LOBYTE(g_pGameRules[138].m_pNext) != 0;
  result = CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules);
  if ( result )
    return g_pGameRules[130].m_pszName == (const char *)2 && LOBYTE(g_pGameRules[138].m_pNext) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C330
// Name: bool FFEVAL_CT_WIN_NO_CASUALTIES(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_CT_WIN_NO_CASUALTIES()
{
  BOOL result; // eax

  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return g_pGameRules[130].m_pszName == (const char *)3 && BYTE1(g_pGameRules[138].m_pNext) != 0;
  result = CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules);
  if ( result )
    return g_pGameRules[130].m_pszName == (const char *)3 && BYTE1(g_pGameRules[138].m_pNext) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C370
// Name: int FFEVAL_KILLED_DEFUSER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_KILLED_DEFUSER(CCSPlayer *pPlayer)
{
  return pPlayer->m_bKilledDefuser;
}

//------------------------------------------------------------------------------
// Address: 0x1029C390
// Name: int FFEVAL_KILLED_RESCUER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_KILLED_RESCUER(CCSPlayer *pPlayer)
{
  return pPlayer->m_bKilledRescuer;
}

//------------------------------------------------------------------------------
// Address: 0x1029C3B0
// Name: int FFEVAL_KILLS_WITH_GRENADE(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_KILLS_WITH_GRENADE(CCSPlayer *pPlayer)
{
  return pPlayer->m_maxGrenadeKills;
}

//------------------------------------------------------------------------------
// Address: 0x1029C3C0
// Name: int FFEVAL_DAMAGE_NO_KILLS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_DAMAGE_NO_KILLS(CCSPlayer *pPlayer)
{
  if ( CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer)->statsCurrentRound.m_iValue[2] != 0 )
    return 0;
  else
    return CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer)->statsCurrentRound.m_iValue[4];
}

//------------------------------------------------------------------------------
// Address: 0x1029C400
// Name: int FFEVAL_ACCURACY(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_ACCURACY(CCSPlayer *pPlayer)
{
  const PlayerStats_t *PlayerStats; // eax
  float shots; // [esp+8h] [ebp-4h]

  shots = (float)CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer)->statsCurrentRound.m_iValue[1];
  PlayerStats = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer);
  if ( shots < 10.0 )
    return 0;
  else
    return (int)(float)((float)((float)PlayerStats->statsCurrentRound.m_iValue[0] * 100.0) / shots);
}

//------------------------------------------------------------------------------
// Address: 0x1029C470
// Name: int FFEVAL_QUARTER_HEALTH(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_QUARTER_HEALTH(CCSPlayer *pPlayer)
{
  return pPlayer->m_iMediumHealthKills;
}

//------------------------------------------------------------------------------
// Address: 0x1029C480
// Name: int FFEVAL_STEPS_TAKEN(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_STEPS_TAKEN(CCSPlayer *pPlayer)
{
  return pPlayer->m_iFootsteps;
}

//------------------------------------------------------------------------------
// Address: 0x1029C490
// Name: int FFEVAL_MOST_CONCURRENT_DOMINATIONS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_MOST_CONCURRENT_DOMINATIONS(CCSPlayer *pPlayer)
{
  return CCSPlayer::GetNumConcurrentDominations(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1029C4A0
// Name: int FFEVAL_MOST_BOTS_ASSUMED(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_MOST_BOTS_ASSUMED(CCSPlayer *pPlayer)
{
  return pPlayer->m_botsControlled;
}

//------------------------------------------------------------------------------
// Address: 0x1029C4B0
// Name: int FFEVAL_HIGHEST_PROXIMITY_SCORE(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_HIGHEST_PROXIMITY_SCORE(CCSPlayer *pPlayer)
{
  return pPlayer->m_iRoundProximityScore;
}

//------------------------------------------------------------------------------
// Address: 0x1029C4C0
// Name: int FFEVAL_BIGGEST_GRIEFER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_BIGGEST_GRIEFER(CCSPlayer *pPlayer)
{
  return (int)(float)((float)pPlayer->m_iRoundScore * -1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1029C4E0
// Name: int FFEVAL_HIGHEST_CONTRIBUTING(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_HIGHEST_CONTRIBUTING(CCSPlayer *pPlayer)
{
  return pPlayer->m_iRoundScore;
}

//------------------------------------------------------------------------------
// Address: 0x1029C4F0
// Name: int FFEVAL_ROUNDS_WITHOUT_DYING(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_ROUNDS_WITHOUT_DYING(CCSPlayer *pPlayer)
{
  return pPlayer->m_maxNumRoundsSurvived;
}

//------------------------------------------------------------------------------
// Address: 0x1029C500
// Name: int FFEVAL_DEFAULT_WEAPON(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_DEFAULT_WEAPON(CCSPlayer *pPlayer)
{
  return !pPlayer->m_bPickedUpWeapon;
}

//------------------------------------------------------------------------------
// Address: 0x1029C520
// Name: int FFEVAL_KILLED_HALF_OF_ENEMIES(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_KILLED_HALF_OF_ENEMIES(CCSPlayer *pPlayer)
{
  return CCSPlayer::GetPercentageOfEnemyTeamKilled(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1029C530
// Name: int FFEVAL_MAX_NUM_RESPAWNS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_MAX_NUM_RESPAWNS(CCSPlayer *pPlayer)
{
  return pPlayer->m_iNumSpawns;
}

//------------------------------------------------------------------------------
// Address: 0x1029C540
// Name: int FFEVAL_KILL_STREAK_BEFORE_DYING(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_KILL_STREAK_BEFORE_DYING(CCSPlayer *pPlayer)
{
  return pPlayer->m_maxNumEnemiesKillStreak;
}

//------------------------------------------------------------------------------
// Address: 0x1029C550
// Name: void GetTeamRoundScore(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetTeamRoundScore(int teamNumber, int *num_players, int *contribution_sum)
{
  CBasePlayer *v3; // esi
  CBaseEntity *v4; // eax
  CBaseEntity *v5; // esi
  int i; // [esp+0h] [ebp-4h]

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v3 != nullptr && v3->IsPlayer(this: v3) )
    {
      v4 = (CBaseEntity *)__RTDynamicCast(
                            inptr: v3,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
      v5 = v4;
      if ( v4 != nullptr && CBaseEntity::GetTeamNumber(this: v4) == teamNumber )
      {
        ++*num_players;
        *contribution_sum += (int)v5[8].m_Network.m_TimerEvent.m_pEventMgr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029C5E0
// Name: bool FFEVAL_FAILED_BOMB_PLANTS(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_FAILED_BOMB_PLANTS(int *iPlayer, int *data1)
{
  bool result; // al
  int v3; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  float *v6; // eax

  result = CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    *data1 = 0;
    v3 = 1;
    if ( gpGlobals->maxClients < 1 )
      return false;
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      v5 = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v6 = (float *)__RTDynamicCast(
                        inptr: v5,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
        if ( v6 != nullptr && v6[1672] < 0.0 && *((_BYTE *)v6 + 6650) != 0 )
        {
          *iPlayer = v3;
          ++*data1;
        }
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    return *data1 >= 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C690
// Name: bool FFEVAL_BOMB_PLANTED_BEFORE_KILL(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_BOMB_PLANTED_BEFORE_KILL(int *iPlayer, int *data1, int *data2)
{
  bool result; // al
  int v4; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  float *v7; // eax
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float fFirstKillTime; // [esp+0h] [ebp-8h]
  float fBombPlantedTime; // [esp+4h] [ebp-4h]

  result = CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    v4 = 1;
    fBombPlantedTime = -1.0;
    fFirstKillTime = -1.0;
    if ( gpGlobals->maxClients < 1 )
      return false;
    do
    {
      v5 = UTIL_PlayerByIndex(playerIndex: v4);
      v6 = v5;
      if ( v5 != nullptr
        && v5->IsPlayer(this: v5)
        && (v7 = (float *)__RTDynamicCast(
                            inptr: v6,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0)) != nullptr )
      {
        v8 = v7[1672];
        v9 = fBombPlantedTime;
        if ( v8 >= 0.0 && (fBombPlantedTime >= v8 || fBombPlantedTime < 0.0) )
        {
          *iPlayer = v4;
          v9 = v7[1672];
          fBombPlantedTime = v9;
          *data1 = (int)v9;
        }
        v10 = v7[1674];
        v11 = fFirstKillTime;
        if ( v10 != 0.0 && (fFirstKillTime < 0.0 || fFirstKillTime > v10) )
        {
          v11 = v7[1674];
          fFirstKillTime = v11;
          *data2 = (int)v10;
        }
      }
      else
      {
        v9 = fBombPlantedTime;
        v11 = fFirstKillTime;
      }
      ++v4;
    }
    while ( v4 <= gpGlobals->maxClients );
    return v9 > 0.0 && v11 <= 0.0 || v11 > v9;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C7C0
// Name: bool FFEVAL_PICKUP_BOMB(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_PICKUP_BOMB(int *iPlayer, int *data1)
{
  bool result; // al
  int v3; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  float *v6; // eax
  int v7; // edi
  CBasePlayer *v8; // eax
  CBasePlayer *v9; // esi
  float *v10; // eax

  result = CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    *data1 = 0;
    v3 = 1;
    if ( gpGlobals->maxClients < 1 )
      return false;
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      v5 = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v6 = (float *)__RTDynamicCast(
                        inptr: v5,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
        if ( v6 != nullptr && v6[1671] >= 0.0 )
          ++*data1;
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    if ( *data1 <= 2 )
      return false;
    v7 = 1;
    if ( gpGlobals->maxClients < 1 )
    {
      return false;
    }
    else
    {
      while ( 1 )
      {
        v8 = UTIL_PlayerByIndex(playerIndex: v7);
        v9 = v8;
        if ( v8 != nullptr && v8->IsPlayer(this: v8) )
        {
          v10 = (float *)__RTDynamicCast(
                           inptr: v9,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
          if ( v10 != nullptr && v10[1672] >= 0.0 )
            break;
        }
        if ( ++v7 > gpGlobals->maxClients )
          return false;
      }
      --*data1;
      *iPlayer = v7;
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C8D0
// Name: bool FFEVAL_TICKING_TIME(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_TICKING_TIME(int *iPlayer, int *data1)
{
  bool result; // al
  int v3; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  _BYTE *v6; // eax

  result = CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    *data1 = 0;
    v3 = 1;
    if ( gpGlobals->maxClients < 1 )
      return false;
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      v5 = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v6 = __RTDynamicCast(
               inptr: v5,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0);
        if ( v6 != nullptr && v6[6199] != 0 )
          ++*data1;
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    return *data1 > 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029C970
// Name: bool FFEVAL_KNIFE_LEVEL_REACHED(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_KNIFE_LEVEL_REACHED(int *iPlayer, int *data1)
{
  bool result; // al
  int i; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  CCSPlayer *v6; // eax
  CWeaponCSBase *ActiveCSWeapon; // eax

  result = CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v4 = UTIL_PlayerByIndex(playerIndex: i);
      v5 = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v6 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v5,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        if ( v6 != nullptr )
        {
          ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: v6);
          if ( ActiveCSWeapon != nullptr && ActiveCSWeapon->GetCSWeaponID(this: ActiveCSWeapon) == WEAPON_KNIFE )
            ++*data1;
        }
      }
    }
    return *data1 > 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029CA10
// Name: bool FFEVAL_WON_AS_LAST_MEMBER(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FFEVAL_WON_AS_LAST_MEMBER(int *iPlayer, int *data1)
{
  bool result; // al
  const char *m_pszName; // ebx
  int v4; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  CBaseEntity *v7; // eax
  CBasePlayer *v8; // esi
  const PlayerStats_t *PlayerStats; // eax
  int v10; // eax
  CCSGameRules::TeamPlayerCounts playerCounts[4]; // [esp+0h] [ebp-64h] BYREF
  int losingTeam; // [esp+60h] [ebp-4h]

  result = CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules);
  if ( result )
  {
    m_pszName = g_pGameRules[130].m_pszName;
    if ( m_pszName == (const char *)2 || m_pszName == (const char *)3 )
    {
      losingTeam = (m_pszName == (const char *)2) + 2;
      CCSGameRules::GetPlayerCounts(this: (CCSGameRules *)g_pGameRules, teamCounts: playerCounts);
      v4 = 1;
      if ( gpGlobals->maxClients < 1 )
      {
        return false;
      }
      else
      {
        while ( 1 )
        {
          v5 = UTIL_PlayerByIndex(playerIndex: v4);
          v6 = v5;
          if ( v5 != nullptr && v5->IsPlayer(this: v5) )
          {
            v7 = (CBaseEntity *)__RTDynamicCast(
                                  inptr: v6,
                                  VfDelta: 0,
                                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                                  isReference: 0);
            v8 = (CBasePlayer *)v7;
            if ( v7 != nullptr
              && (const char *)CBaseEntity::GetTeamNumber(this: v7) == m_pszName
              && v8->IsAlive(this: v8)
              && playerCounts[(_DWORD)m_pszName].totalAlivePlayers == 1
              && playerCounts[losingTeam].totalAlivePlayers == 0 )
            {
              PlayerStats = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v8);
              *iPlayer = v4;
              v10 = PlayerStats->statsCurrentRound.m_iValue[153];
              *data1 = v10;
              if ( v10 >= 2 )
                break;
            }
          }
          if ( ++v4 > gpGlobals->maxClients )
            return false;
        }
        return true;
      }
    }
    else
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB30
// Name: int FFEVAL_PULLED_TRIGGER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_PULLED_TRIGGER(CCSPlayer *pPlayer)
{
  return pPlayer->m_triggerPulls;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB40
// Name: int FFEVAL_SURVIVAL_TIME(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_SURVIVAL_TIME(CCSPlayer *pPlayer)
{
  return (int)pPlayer->m_longestLife;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB50
// Name: int FFEVAL_MOLOTOV_BURNS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_MOLOTOV_BURNS(CCSPlayer *pPlayer)
{
  return CCSPlayer::GetNumPlayersDamagedWithFire(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1029CB60
// Name: int FFEVAL_KNIFE_WITHOUT_AMMO(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_KNIFE_WITHOUT_AMMO(CCSPlayer *pPlayer)
{
  return pPlayer->m_knifeKillsWhenOutOfAmmo;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB70
// Name: int FFEVAL_KNIFE_BOMB_PLANTER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_KNIFE_BOMB_PLANTER(CCSPlayer *pPlayer)
{
  return pPlayer->m_knifeKillBombPlacer;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB80
// Name: int FFEVAL_BOMB_CARRIERS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_BOMB_CARRIERS(CCSPlayer *pPlayer)
{
  return pPlayer->m_bombCarrierkills;
}

//------------------------------------------------------------------------------
// Address: 0x1029CB90
// Name: int FFEVAL_KNIFE_IN_GUNFIGHT(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_KNIFE_IN_GUNFIGHT(CCSPlayer *pPlayer)
{
  return pPlayer->m_bWieldingKnifeAndKilledByGun;
}

//------------------------------------------------------------------------------
// Address: 0x1029CBB0
// Name: int FFEVAL_MULTIPLE_ATTACKER_COUNT(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_MULTIPLE_ATTACKER_COUNT(CCSPlayer *pPlayer)
{
  return CCSPlayer::GetNumEnemyDamagers(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1029CBC0
// Name: int FFEVAL_USED_ALL_AMMO(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_USED_ALL_AMMO(CCSPlayer *pPlayer)
{
  void *v1; // eax
  void *v2; // edi
  void *v3; // eax
  void *v4; // esi
  int v6; // [esp+0h] [ebp-8h]

  v1 = (void *)((int (__thiscall *)(CCSPlayer *, _DWORD, _DWORD))pPlayer->Weapon_GetSlot)(a1: pPlayer, a2: 0, a3: 0);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: (int)&CBaseCombatWeapon `RTTI Type Descriptor',
         SrcType: &CWeaponCSBase `RTTI Type Descriptor',
         TargetType: nullptr,
         isReference: v6);
  v3 = (void *)((int (__thiscall *)(CCSPlayer *))pPlayer->Weapon_GetSlot)(a1: pPlayer);
  v4 = __RTDynamicCast(
         inptr: v3,
         VfDelta: 1,
         SrcType: nullptr,
         TargetType: &CBaseCombatWeapon `RTTI Type Descriptor',
         isReference: (int)&CWeaponCSBase `RTTI Type Descriptor');
  return v2 != nullptr
      && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v2 + 956))(a1: v2) == 0
      && v4 != nullptr
      && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v4 + 956))(a1: v4) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029CC50
// Name: int FFEVAL_DAMAGE_MULTIPLE_ENEMIES(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_DAMAGE_MULTIPLE_ENEMIES(CCSPlayer *pPlayer)
{
  return CCSPlayer::GetNumEnemiesDamaged(this: pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1029CC60
// Name: int FFEVAL_DEFUSED_WITH_DROPPED_KIT(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FFEVAL_DEFUSED_WITH_DROPPED_KIT(CCSPlayer *pPlayer)
{
  return pPlayer->m_bDefusedWithPickedUpKit;
}

//------------------------------------------------------------------------------
// Address: 0x1029CC80
// Name: bool FFEVAL_TERRORIST_ACCURACY(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_TERRORIST_ACCURACY(int *iPlayer, int *data1)
{
  float ctAccuracy; // [esp+0h] [ebp-8h]
  float terroristAccuracy; // [esp+4h] [ebp-4h]

  terroristAccuracy = GetTeamAccuracy(teamNumber: 2);
  ctAccuracy = GetTeamAccuracy(teamNumber: 3);
  if ( terroristAccuracy <= 0.2 || terroristAccuracy <= ctAccuracy )
    return 0;
  *data1 = (int)(float)(terroristAccuracy * 100.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029CCE0
// Name: bool FFEVAL_CT_ACCURACY(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_CT_ACCURACY(int *iPlayer, int *data1)
{
  double TeamAccuracy; // st7
  float terroristAccuracy; // [esp+0h] [ebp-8h]
  float ctAccuracy; // [esp+4h] [ebp-4h]

  terroristAccuracy = GetTeamAccuracy(teamNumber: 2);
  TeamAccuracy = GetTeamAccuracy(teamNumber: 3);
  if ( TeamAccuracy <= 0.2 )
    return 0;
  ctAccuracy = TeamAccuracy;
  if ( ctAccuracy <= terroristAccuracy )
    return 0;
  *data1 = (int)(float)(ctAccuracy * 100.0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029CD40
// Name: bool FFEVAL_BEST_TERRORIST_ACCURACY(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_BEST_TERRORIST_ACCURACY(int *iPlayer, int *data1, int *data2)
{
  CGlobalVars *v3; // eax
  int i; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  const PlayerStats_t *PlayerStats; // eax
  float v8; // xmm0_4
  int v9; // edi
  int v10; // ebx
  CBasePlayer *v11; // eax
  CBasePlayer *v12; // esi
  float v13; // xmm0_4
  float shots; // [esp+0h] [ebp-Ch]
  float shotsa; // [esp+0h] [ebp-Ch]
  float fBestAccuracy; // [esp+4h] [ebp-8h]
  float fAccuracy; // [esp+8h] [ebp-4h]
  int fAccuracya; // [esp+8h] [ebp-4h]

  v3 = gpGlobals;
  fAccuracy = 0.0;
  fBestAccuracy = 0.0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    v6 = v5;
    if ( v5 != nullptr && CBaseEntity::GetTeamNumber(this: v5) == 2 )
    {
      shots = (float)CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v6)->statsCurrentRound.m_iValue[1];
      PlayerStats = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v6);
      if ( shots <= 10.0 )
      {
        v8 = fAccuracy;
      }
      else
      {
        v8 = (float)PlayerStats->statsCurrentRound.m_iValue[0] / shots;
        fAccuracy = v8;
      }
      if ( v8 > fBestAccuracy )
      {
        fBestAccuracy = v8;
        *iPlayer = i;
      }
    }
    v3 = gpGlobals;
  }
  v9 = 0;
  v10 = 0;
  fAccuracya = 1;
  if ( v3->maxClients < 1 )
    goto LABEL_17;
  do
  {
    v11 = UTIL_PlayerByIndex(playerIndex: fAccuracya);
    v12 = v11;
    if ( v11 != nullptr && CBaseEntity::GetTeamNumber(this: v11) == 2 )
    {
      v9 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v12)->statsCurrentRound.m_iValue[1];
      v10 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v12)->statsCurrentRound.m_iValue[0];
    }
    ++fAccuracya;
  }
  while ( fAccuracya <= gpGlobals->maxClients );
  if ( v9 <= 10 )
LABEL_17:
    v13 = 0.0;
  else
    v13 = (float)v10 / (float)v9;
  if ( (float)(fBestAccuracy - v13) < 0.1 )
    return 0;
  *data1 = (int)(float)(fBestAccuracy * 100.0);
  shotsa = GetTeamAccuracy(teamNumber: 2) * 100.0;
  *data2 = (int)shotsa;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029CEE0
// Name: bool FFEVAL_BEST_COUNTERTERRORIST_ACCURACY(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_BEST_COUNTERTERRORIST_ACCURACY(int *iPlayer, int *data1, int *data2)
{
  CGlobalVars *v3; // eax
  int i; // edi
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  const PlayerStats_t *PlayerStats; // eax
  float v8; // xmm0_4
  int v9; // edi
  int v10; // ebx
  CBasePlayer *v11; // eax
  CBasePlayer *v12; // esi
  float v13; // xmm0_4
  float shots; // [esp+0h] [ebp-Ch]
  float shotsa; // [esp+0h] [ebp-Ch]
  float fBestAccuracy; // [esp+4h] [ebp-8h]
  float fAccuracy; // [esp+8h] [ebp-4h]
  int fAccuracya; // [esp+8h] [ebp-4h]

  v3 = gpGlobals;
  fAccuracy = 0.0;
  fBestAccuracy = 0.0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    v6 = v5;
    if ( v5 != nullptr && CBaseEntity::GetTeamNumber(this: v5) == 3 )
    {
      shots = (float)CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v6)->statsCurrentRound.m_iValue[1];
      PlayerStats = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v6);
      if ( shots <= 10.0 )
      {
        v8 = fAccuracy;
      }
      else
      {
        v8 = (float)PlayerStats->statsCurrentRound.m_iValue[0] / shots;
        fAccuracy = v8;
      }
      if ( v8 > fBestAccuracy )
      {
        fBestAccuracy = v8;
        *iPlayer = i;
      }
    }
    v3 = gpGlobals;
  }
  v9 = 0;
  v10 = 0;
  fAccuracya = 1;
  if ( v3->maxClients < 1 )
    goto LABEL_17;
  do
  {
    v11 = UTIL_PlayerByIndex(playerIndex: fAccuracya);
    v12 = v11;
    if ( v11 != nullptr && CBaseEntity::GetTeamNumber(this: v11) == 3 )
    {
      v9 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v12)->statsCurrentRound.m_iValue[1];
      v10 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v12)->statsCurrentRound.m_iValue[0];
    }
    ++fAccuracya;
  }
  while ( fAccuracya <= gpGlobals->maxClients );
  if ( v9 <= 10 )
LABEL_17:
    v13 = 0.0;
  else
    v13 = (float)v10 / (float)v9;
  if ( (float)(fBestAccuracy - v13) < 0.1 )
    return 0;
  *data1 = (int)(float)(fBestAccuracy * 100.0);
  shotsa = GetTeamAccuracy(teamNumber: 3) * 100.0;
  *data2 = (int)shotsa;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D080
// Name: CreateFunFact_FUNFACT_DAMAGE_WITH_GRENADES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DAMAGE_WITH_GRENADES()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 6;
  *((_DWORD *)v0 + 2) = "#funfact_damage_with_grenade";
  *((_DWORD *)v0 + 3) = 1056964608;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 174;
  *((_DWORD *)v0 + 5) = 200;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_damage_with_grenade", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D110
// Name: CreateFunFact_FUNFACT_KNIFE_KILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KNIFE_KILLS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 15;
  *((_DWORD *)v0 + 2) = "#funfact_knife_kills";
  *((_DWORD *)v0 + 3) = 1056964608;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 36;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_knife_kills", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D1A0
// Name: CreateFunFact_FUNFACT_KILLS_WITH_GRENADES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLS_WITH_GRENADES()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 7;
  *((_DWORD *)v0 + 2) = "#funfact_kills_grenades";
  *((_DWORD *)v0 + 3) = 1060320051;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 37;
  *((_DWORD *)v0 + 5) = 2;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_kills_grenades", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D230
// Name: CreateFunFact_FUNFACT_BLIND_KILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BLIND_KILLS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 16;
  *((_DWORD *)v0 + 2) = "#funfact_blind_kills";
  *((_DWORD *)v0 + 3) = 1063675494;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 146;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_blind_kills", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D2C0
// Name: CreateFunFact_FUNFACT_KILLED_ENEMIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLED_ENEMIES()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 10;
  *((_DWORD *)v0 + 2) = "#funfact_killed_enemies";
  *((_DWORD *)v0 + 3) = 1058642330;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 2;
  *((_DWORD *)v0 + 5) = 3;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_killed_enemies", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D350
// Name: CreateFunFact_FUNFACT_KILLS_WITH_LAST_ROUND
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLS_WITH_LAST_ROUND()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 17;
  *((_DWORD *)v0 + 2) = "#funfact_kills_with_last_round";
  *((_DWORD *)v0 + 3) = 1058642330;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 147;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_kills_with_last_round", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D3E0
// Name: CreateFunFact_FUNFACT_DONATED_WEAPONS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DONATED_WEAPONS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 18;
  *((_DWORD *)v0 + 2) = "#funfact_donated_weapons";
  *((_DWORD *)v0 + 3) = 1050253722;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 165;
  *((_DWORD *)v0 + 5) = 2;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_donated_weapons", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D470
// Name: CreateFunFact_FUNFACT_NUM_TIMES_JUMPED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_NUM_TIMES_JUMPED()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 21;
  *((_DWORD *)v0 + 2) = "#funfact_num_times_jumped";
  *((_DWORD *)v0 + 3) = 1045220557;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 152;
  *((_DWORD *)v0 + 5) = 10;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_num_times_jumped", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D500
// Name: CreateFunFact_FUNFACT_FALL_DAMAGE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_FALL_DAMAGE()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 22;
  *((_DWORD *)v0 + 2) = "#funfact_fall_damage";
  *((_DWORD *)v0 + 3) = 1045220557;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 155;
  *((_DWORD *)v0 + 5) = 50;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_fall_damage", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D590
// Name: CreateFunFact_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 19;
  *((_DWORD *)v0 + 2) = "#funfact_posthumous_kills_with_grenade";
  *((_DWORD *)v0 + 3) = 1065353216;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 175;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_posthumous_kills_with_grenade", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D620
// Name: CreateFunFact_FUNFACT_ITEMS_PURCHASED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_ITEMS_PURCHASED()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 23;
  *((_DWORD *)v0 + 2) = "#funfact_items_purchased";
  *((_DWORD *)v0 + 3) = 1045220557;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 166;
  *((_DWORD *)v0 + 5) = 5;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_items_purchased", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D6B0
// Name: CreateFunFact_FUNFACT_NUMBER_OF_OVERKILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_NUMBER_OF_OVERKILLS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 25;
  *((_DWORD *)v0 + 2) = "#funfact_number_of_overkills";
  *((_DWORD *)v0 + 3) = 1056964608;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 169;
  *((_DWORD *)v0 + 5) = 2;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_number_of_overkills", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D740
// Name: CreateFunFact_FUNFACT_MONEY_SPENT
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_MONEY_SPENT()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 27;
  *((_DWORD *)v0 + 2) = "#funfact_money_spent";
  *((_DWORD *)v0 + 3) = 1045220557;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 167;
  *((_DWORD *)v0 + 5) = 5000;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_money_spent", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D7D0
// Name: CreateFunFact_FUNFACT_GRENADES_THROWN
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_GRENADES_THROWN()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 31;
  *((_DWORD *)v0 + 2) = "#funfact_grenades_thrown";
  *((_DWORD *)v0 + 3) = 1050253722;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 176;
  *((_DWORD *)v0 + 5) = 2;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_grenades_thrown", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D860
// Name: CreateFunFact_FUNFACT_DEFENDED_BOMB
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DEFENDED_BOMB()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 33;
  *((_DWORD *)v0 + 2) = "#funfact_defended_bomb";
  *((_DWORD *)v0 + 3) = 1056964608;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 150;
  *((_DWORD *)v0 + 5) = 2;
  *((_DWORD *)v0 + 38) = 132;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_defended_bomb", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D8F0
// Name: CreateFunFact_FUNFACT_ITEMS_DROPPED_VALUE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_ITEMS_DROPPED_VALUE()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 34;
  *((_DWORD *)v0 + 2) = "#funfact_items_dropped_value";
  *((_DWORD *)v0 + 3) = 1056964608;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 177;
  *((_DWORD *)v0 + 5) = 10000;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_items_dropped_value", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029D980
// Name: CreateFunFact_FUNFACT_KILL_WOUNDED_ENEMIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILL_WOUNDED_ENEMIES()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 35;
  *((_DWORD *)v0 + 2) = "#funfact_kill_wounded_enemies";
  *((_DWORD *)v0 + 3) = 1053609165;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 154;
  *((_DWORD *)v0 + 5) = 3;
  *((_DWORD *)v0 + 38) = 900;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_kill_wounded_enemies", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029DA10
// Name: CreateFunFact_FUNFACT_KILLS_HEADSHOTS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLS_HEADSHOTS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 43;
  *((_DWORD *)v0 + 2) = "#funfact_kills_headshots";
  *((_DWORD *)v0 + 3) = 1060320051;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 144;
  *((_DWORD *)v0 + 5) = 3;
  *((_DWORD *)v0 + 38) = 900;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_kills_headshots", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029DAA0
// Name: CreateFunFact_FUNFACT_BROKE_WINDOWS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BROKE_WINDOWS()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 44;
  *((_DWORD *)v0 + 2) = "#funfact_broke_windows";
  *((_DWORD *)v0 + 3) = 1050253722;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 157;
  *((_DWORD *)v0 + 5) = 5;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_broke_windows", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029DB30
// Name: CreateFunFact_FUNFACT_SHOTS_FIRED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SHOTS_FIRED()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 26;
  result->m_pLocalizationToken = "#funfact_shots_fired";
  result->m_fCoolness = 0.1;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_StatSum::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)1;
  result[1].m_id = 200;
  result[1].m_pLocalizationToken = (const char *)896;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DB80
// Name: CreateFunFact_FUNFACT_KILL_DEFUSER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILL_DEFUSER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 2;
  result->m_pLocalizationToken = "#funfact_kill_defuser";
  result->m_fCoolness = 0.60000002;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KILLED_DEFUSER;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)34;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DBD0
// Name: CreateFunFact_FUNFACT_KILL_RESCUER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILL_RESCUER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 3;
  result->m_pLocalizationToken = "#funfact_kill_rescuer";
  result->m_fCoolness = 0.60000002;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KILLED_RESCUER;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DC20
// Name: CreateFunFact_FUNFACT_KILLS_WITH_SINGLE_GRENADE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLS_WITH_SINGLE_GRENADE()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 8;
  result->m_pLocalizationToken = "#funfact_kills_with_single_grenade";
  result->m_fCoolness = 0.80000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KILLS_WITH_GRENADE;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DC70
// Name: CreateFunFact_FUNFACT_DAMAGE_NO_KILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DAMAGE_NO_KILLS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 9;
  result->m_pLocalizationToken = "#funfact_damage_no_kills";
  result->m_fCoolness = 0.40000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_DAMAGE_NO_KILLS;
  result[1].m_id = 200;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DCC0
// Name: CreateFunFact_FUNFACT_BEST_ACCURACY
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BEST_ACCURACY()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 14;
  result->m_pLocalizationToken = "#funfact_best_accuracy";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_ACCURACY;
  result[1].m_id = 20;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DD10
// Name: CreateFunFact_FUNFACT_KNIFE_IN_GUNFIGHT
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KNIFE_IN_GUNFIGHT()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 20;
  result->m_pLocalizationToken = "#funfact_knife_in_gunfight";
  result->m_fCoolness = 0.60000002;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KNIFE_IN_GUNFIGHT;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DD60
// Name: CreateFunFact_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 28;
  result->m_pLocalizationToken = "#funfact_survived_multiple_attackers";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MULTIPLE_ATTACKER_COUNT;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)908;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DDB0
// Name: CreateFunFact_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 29;
  result->m_pLocalizationToken = "#funfact_died_from_multiple_attackers";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MULTIPLE_ATTACKER_COUNT;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)20;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DE00
// Name: CreateFunFact_FUNFACT_USED_ALL_AMMO
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_USED_ALL_AMMO()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 32;
  result->m_pLocalizationToken = "#funfact_used_all_ammo";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_USED_ALL_AMMO;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)896;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DE50
// Name: CreateFunFact_FUNFACT_DAMAGE_MULTIPLE_ENEMIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DAMAGE_MULTIPLE_ENEMIES()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 30;
  result->m_pLocalizationToken = "#funfact_damage_multiple_enemies";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_DAMAGE_MULTIPLE_ENEMIES;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DEA0
// Name: CreateFunFact_FUNFACT_DEFUSED_WITH_DROPPED_KIT
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DEFUSED_WITH_DROPPED_KIT()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 46;
  result->m_pLocalizationToken = "#funfact_defused_with_dropped_kit";
  result->m_fCoolness = 0.40000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_DEFUSED_WITH_DROPPED_KIT;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DEF0
// Name: CreateFunFact_FUNFACT_KILLED_HALF_OF_ENEMIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KILLED_HALF_OF_ENEMIES()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 47;
  result->m_pLocalizationToken = "#funfact_killed_half_of_enemies";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KILLED_HALF_OF_ENEMIES;
  result[1].m_id = 50;
  result[1].m_pLocalizationToken = (const char *)36;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DF40
// Name: CreateFunFact_FUNFACT_CT_WIN_NO_KILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_CT_WIN_NO_KILLS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 0;
  result->m_pLocalizationToken = "#funfact_ct_win_no_kills";
  result->m_fCoolness = 0.40000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_CT_WIN_NO_KILLS;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DF80
// Name: CreateFunFact_FUNFACT_T_WIN_NO_KILLS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_T_WIN_NO_KILLS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 1;
  result->m_pLocalizationToken = "#funfact_t_win_no_kills";
  result->m_fCoolness = 0.40000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_T_WIN_NO_KILLS;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029DFC0
// Name: CreateFunFact_FUNFACT_T_WIN_NO_CASUALTIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_T_WIN_NO_CASUALTIES()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 4;
  result->m_pLocalizationToken = "#funfact_t_win_no_casualties";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_T_WIN_NO_CASUALTIES;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E000
// Name: CreateFunFact_FUNFACT_CT_WIN_NO_CASUALTIES
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_CT_WIN_NO_CASUALTIES()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 5;
  result->m_pLocalizationToken = "#funfact_ct_win_no_casualties";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_CT_WIN_NO_CASUALTIES;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E040
// Name: CreateFunFact_FUNFACT_WON_AS_LAST_MEMBER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_WON_AS_LAST_MEMBER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 24;
  result->m_pLocalizationToken = "#funfact_won_as_last_member";
  result->m_fCoolness = 0.60000002;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_WON_AS_LAST_MEMBER;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E080
// Name: CreateFunFact_FUNFACT_TERRORIST_ACCURACY
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_TERRORIST_ACCURACY()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 37;
  result->m_pLocalizationToken = "#funfact_terrorist_accuracy";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_TERRORIST_ACCURACY;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E0C0
// Name: CreateFunFact_FUNFACT_CT_ACCURACY
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_CT_ACCURACY()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 38;
  result->m_pLocalizationToken = "#funfact_ct_accuracy";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_CT_ACCURACY;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E100
// Name: CreateFunFact_FUNFACT_BEST_TERRORIST_ACCURACY
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BEST_TERRORIST_ACCURACY()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 39;
  result->m_pLocalizationToken = "#funfact_best_terrorist_accuracy";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_BEST_TERRORIST_ACCURACY;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E140
// Name: CreateFunFact_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 40;
  result->m_pLocalizationToken = "#funfact_best_counterterrorist_accuracy";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_BEST_COUNTERTERRORIST_ACCURACY;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E180
// Name: CreateFunFact_FUNFACT_SHOTS_FIRED_FALLBACK
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SHOTS_FIRED_FALLBACK()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 49;
  result->m_pLocalizationToken = "#funfact_shots_fired";
  result->m_fCoolness = 0.1;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_StatSum::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)1;
  result[1].m_id = 0;
  result[1].m_pLocalizationToken = (const char *)896;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E1D0
// Name: CreateFunFact_FUNFACT_KNIFE_LEVEL_REACHED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KNIFE_LEVEL_REACHED()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 48;
  result->m_pLocalizationToken = "#funfact_knife_level_reached";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KNIFE_LEVEL_REACHED;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E210
// Name: CreateFunFact_FUNFACT_MAX_KILLED_BEFORE_DYING
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_MAX_KILLED_BEFORE_DYING()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 50;
  result->m_pLocalizationToken = "#funfact_killed_before_dying";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KILL_STREAK_BEFORE_DYING;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E260
// Name: CreateFunFact_FUNFACT_MAX_RESPAWNS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_MAX_RESPAWNS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 51;
  result->m_pLocalizationToken = "#funfact_respawned";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MAX_NUM_RESPAWNS;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E2B0
// Name: CreateFunFact_FUNFACT_DEFAULT_WEAPON
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DEFAULT_WEAPON()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 52;
  result->m_pLocalizationToken = "#funfact_default_weapon";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_DEFAULT_WEAPON;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)1576;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E300
// Name: CreateFunFact_FUNFACT_ROUNDS_WITHOUT_DYING
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_ROUNDS_WITHOUT_DYING()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 53;
  result->m_pLocalizationToken = "#funfact_rounds_without_dying";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_ROUNDS_WITHOUT_DYING;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)1580;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E350
// Name: CreateFunFact_FUNFACT_TASER_KILL
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_TASER_KILL()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 54;
  *((_DWORD *)v0 + 2) = "#funfact_taser_kill";
  *((_DWORD *)v0 + 3) = 1053609165;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 45;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 1540;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_taser_kill", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029E3E0
// Name: CreateFunFact_FUNFACT_TICKING_TIME
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_TICKING_TIME()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 55;
  result->m_pLocalizationToken = "#funfact_ticking_time";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_TICKING_TIME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E420
// Name: CreateFunFact_FUNFACT_HIGHEST_CONTRIBUTING
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_HIGHEST_CONTRIBUTING()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 58;
  result->m_pLocalizationToken = "#funfact_highest_contributing";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_HIGHEST_CONTRIBUTING;
  result[1].m_id = 1000;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E470
// Name: CreateFunFact_FUNFACT_BIGGEST_GRIEFER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BIGGEST_GRIEFER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 59;
  result->m_pLocalizationToken = "#funfact_biggest_griefer";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_BIGGEST_GRIEFER;
  result[1].m_id = 10;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E4C0
// Name: CreateFunFact_FUNFACT_HIGHEST_PROXIMITY_SCORE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_HIGHEST_PROXIMITY_SCORE()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 62;
  result->m_pLocalizationToken = "#funfact_highest_proximity_score";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_HIGHEST_PROXIMITY_SCORE;
  result[1].m_id = 25;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E510
// Name: CreateFunFact_FUNFACT_BOTS_ASSUMED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BOTS_ASSUMED()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 63;
  result->m_pLocalizationToken = "#funfact_bots_assumed";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MOST_BOTS_ASSUMED;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E560
// Name: CreateFunFact_FUNFACT_DOMINATION
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_DOMINATION()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 64;
  result->m_pLocalizationToken = "#funfact_domination";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MOST_CONCURRENT_DOMINATIONS;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)900;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E5B0
// Name: CreateFunFact_FUNFACT_REVENGE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_REVENGE()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x9Cu);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = 65;
  *((_DWORD *)v0 + 2) = "#funfact_revenge";
  *((_DWORD *)v0 + 3) = 1050253722;
  *(_DWORD *)v0 = &CFunFact_StatBest::`vftable';
  *((_DWORD *)v0 + 4) = 170;
  *((_DWORD *)v0 + 5) = 1;
  *((_DWORD *)v0 + 38) = 4;
  V_strncpy(pDest: v0 + 24, pSrc: "#funfact_revenge", maxLen: 128);
  if ( *((_DWORD *)v1 + 5) == 1 )
    V_strncat(pDest: v1 + 24, pSrc: "_singular", destBufferSize: 0x80u, max_chars_to_copy: -1);
  return (FunFactEvaluator *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1029E640
// Name: CreateFunFact_FUNFACT_STEPS_TAKEN
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_STEPS_TAKEN()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 66;
  result->m_pLocalizationToken = "#funfact_steps_taken";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_STEPS_TAKEN;
  result[1].m_id = 20;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E690
// Name: CreateFunFact_FUNFACT_QUARTER_HEALTH
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_QUARTER_HEALTH()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 67;
  result->m_pLocalizationToken = "#funfact_quarter_health";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_QUARTER_HEALTH;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E6E0
// Name: CreateFunFact_FUNFACT_PICKUP_BOMB
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_PICKUP_BOMB()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 71;
  result->m_pLocalizationToken = "#funfact_pickup_bomb";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_PICKUP_BOMB;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E720
// Name: CreateFunFact_FUNFACT_BOMB_CARRIERS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BOMB_CARRIERS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 72;
  result->m_pLocalizationToken = "#funfact_bomb_carriers";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_BOMB_CARRIERS;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1156;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E770
// Name: CreateFunFact_FUNFACT_KNIFE_BOMB_PLANTER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KNIFE_BOMB_PLANTER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 73;
  result->m_pLocalizationToken = "#funfact_knife_bomb_planter";
  result->m_fCoolness = 0.89999998;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KNIFE_BOMB_PLANTER;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)1164;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E7C0
// Name: CreateFunFact_FUNFACT_BOMB_PLANTED_BEFORE_KILL
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_BOMB_PLANTED_BEFORE_KILL()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 74;
  result->m_pLocalizationToken = "#funfact_bomb_planted_before_kill";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_BOMB_PLANTED_BEFORE_KILL;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E800
// Name: CreateFunFact_FUNFACT_FAILED_BOMB_PLANTS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_FAILED_BOMB_PLANTS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 75;
  result->m_pLocalizationToken = "#funfact_failed_bomb_plants";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_FAILED_BOMB_PLANTS;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E840
// Name: CreateFunFact_FUNFACT_KNIFE_WITHOUT_AMMO
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_KNIFE_WITHOUT_AMMO()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 76;
  result->m_pLocalizationToken = "#funfact_knife_without_ammo";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_KNIFE_WITHOUT_AMMO;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1156;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E890
// Name: CreateFunFact_FUNFACT_MOLOTOV_BURNS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_MOLOTOV_BURNS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 77;
  result->m_pLocalizationToken = "#funfact_molotov_burns";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_MOLOTOV_BURNS;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E8E0
// Name: CreateFunFact_FUNFACT_SURVIVAL_TIME
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SURVIVAL_TIME()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 78;
  result->m_pLocalizationToken = "#funfact_survival_time";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_SURVIVAL_TIME;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E930
// Name: CreateFunFact_FUNFACT_PULLED_TRIGGER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_PULLED_TRIGGER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 79;
  result->m_pLocalizationToken = "#funfact_pulled_trigger";
  result->m_fCoolness = 0.89999998;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_PULLED_TRIGGER;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1284;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029E9B0
// Name: bool FFEVAL_CT_WIN_TIME(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_CT_WIN_TIME(int *iPlayer, int *data1)
{
  float m_pszName; // [esp+0h] [ebp-4h]
  float v4; // [esp+0h] [ebp-4h]

  if ( !CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return 0;
  m_pszName = (float)(int)g_pGameRules[46].m_pszName;
  if ( m_pszName - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules) >= 60.0
    || g_pGameRules[130].m_pszName != (const char *)3 )
  {
    return 0;
  }
  v4 = (float)(int)g_pGameRules[46].m_pszName;
  *data1 = (int)(v4 - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029EA30
// Name: bool FFEVAL_TER_WIN_TIME(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_TER_WIN_TIME(int *iPlayer, int *data1)
{
  float m_pszName; // [esp+0h] [ebp-4h]
  float v4; // [esp+0h] [ebp-4h]

  if ( !CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    return 0;
  m_pszName = (float)(int)g_pGameRules[46].m_pszName;
  if ( m_pszName - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules) >= 60.0
    || g_pGameRules[130].m_pszName != (const char *)2 )
  {
    return 0;
  }
  v4 = (float)(int)g_pGameRules[46].m_pszName;
  *data1 = (int)(v4 - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029EAB0
// Name: bool FFEVAL_SHORT_ROUND(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_SHORT_ROUND(int *iPlayer, int *data1)
{
  float m_pszName; // [esp+0h] [ebp-4h]
  float v4; // [esp+0h] [ebp-4h]

  if ( !CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules) )
    return 0;
  m_pszName = (float)(int)g_pGameRules[46].m_pszName;
  if ( m_pszName - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules) >= 30.0 )
    return 0;
  v4 = (float)(int)g_pGameRules[46].m_pszName;
  *data1 = (int)(v4 - CCSGameRules::GetRoundRemainingTime(this: (CCSGameRules *)g_pGameRules));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029EB20
// Name: int FFEVAL_SLOW_TRIGGER(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_SLOW_TRIGGER(CCSPlayer *pPlayer)
{
  return pPlayer->m_WeaponTypesHeld.m_Size - pPlayer->m_WeaponTypesUsed.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1029EB40
// Name: int FFEVAL_EMPTY_GUNS(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_EMPTY_GUNS(CCSPlayer *pPlayer)
{
  return pPlayer->m_WeaponTypesRunningOutOfAmmo.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1029EB50
// Name: bool FFEVAL_TER_AVERAGE(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_TER_AVERAGE(int *iPlayer, int *data1)
{
  ConVarRef score_typical_good_score; // [esp+0h] [ebp-10h] BYREF
  int contribution_sum; // [esp+8h] [ebp-8h] BYREF
  int num_players; // [esp+Ch] [ebp-4h] BYREF

  num_players = 0;
  contribution_sum = 0;
  GetTeamRoundScore(teamNumber: 2, &num_players, &contribution_sum);
  ConVarRef::ConVarRef(this: &score_typical_good_score, pName: "score_typical_good_score");
  if ( num_players <= 0 || contribution_sum / num_players <= score_typical_good_score.m_pConVarState->m_Value.m_nValue )
    return 0;
  *data1 = contribution_sum / num_players;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029EBB0
// Name: bool FFEVAL_CT_AVERAGE(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FFEVAL_CT_AVERAGE(int *iPlayer, int *data1)
{
  ConVarRef roundStartScore; // [esp+0h] [ebp-10h] BYREF
  int contribution_sum; // [esp+8h] [ebp-8h] BYREF
  int num_players; // [esp+Ch] [ebp-4h] BYREF

  num_players = 0;
  contribution_sum = 0;
  GetTeamRoundScore(teamNumber: 3, &num_players, &contribution_sum);
  ConVarRef::ConVarRef(this: &roundStartScore, pName: "score_default");
  if ( num_players <= 0 || contribution_sum / num_players <= roundStartScore.m_pConVarState->m_Value.m_nValue + 75 )
    return 0;
  *data1 = contribution_sum / num_players;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029EC10
// Name: int FFEVAL_GUNS_USED(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_GUNS_USED(CCSPlayer *pPlayer)
{
  return pPlayer->m_WeaponTypesUsed.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1029EC20
// Name: CreateFunFact_FUNFACT_USED_MULTIPLE_WEAPONS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_USED_MULTIPLE_WEAPONS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 36;
  result->m_pLocalizationToken = "#funfact_used_multiple_weapons";
  result->m_fCoolness = 0.5;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_GUNS_USED;
  result[1].m_id = 4;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EC70
// Name: CreateFunFact_FUNFACT_SHORT_ROUND
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SHORT_ROUND()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 13;
  result->m_pLocalizationToken = "#funfact_short_round";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_SHORT_ROUND;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029ECB0
// Name: CreateFunFact_FUNFACT_CT_WIN_TIME
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_CT_WIN_TIME()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 56;
  result->m_pLocalizationToken = "#funfact_ct_win_time";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_CT_WIN_TIME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029ECF0
// Name: CreateFunFact_FUNFACT_TER_WIN_TIME
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_TER_WIN_TIME()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 57;
  result->m_pLocalizationToken = "#funfact_ter_win_time";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_TER_WIN_TIME;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029ED30
// Name: CreateFunFact_FUNFACT_CT_AVERAGE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_CT_AVERAGE()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 60;
  result->m_pLocalizationToken = "#funfact_ct_average";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_CT_AVERAGE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029ED70
// Name: CreateFunFact_FUNFACT_TER_AVERAGE
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_TER_AVERAGE()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x14u);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 61;
  result->m_pLocalizationToken = "#funfact_ter_average";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_GenericEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_TER_AVERAGE;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EDB0
// Name: CreateFunFact_FUNFACT_GUNS_USED
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_GUNS_USED()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 68;
  result->m_pLocalizationToken = "#funfact_guns_used";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_GUNS_USED;
  result[1].m_id = 3;
  result[1].m_pLocalizationToken = (const char *)1540;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EE00
// Name: CreateFunFact_FUNFACT_EMPTY_GUNS
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_EMPTY_GUNS()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 69;
  result->m_pLocalizationToken = "#funfact_empty_guns";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_EMPTY_GUNS;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1540;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EE50
// Name: CreateFunFact_FUNFACT_SLOW_TRIGGER
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_SLOW_TRIGGER()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 70;
  result->m_pLocalizationToken = "#funfact_slow_trigger";
  result->m_fCoolness = 0.30000001;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_SLOW_TRIGGER;
  result[1].m_id = 2;
  result[1].m_pLocalizationToken = (const char *)1556;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EEA0
// Name: int FFEVAL_FIRST_KILL(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_FIRST_KILL(CCSPlayer *pPlayer)
{
  CGameRules_vtbl *v1; // ecx
  CCSPlayer *m_pEntity; // eax
  CAutoGameSystemPerFrame *m_pNext; // xmm0_4

  v1 = g_pGameRules[139].__vftable;
  if ( v1 == (CGameRules_vtbl *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_SerialNumber != (unsigned int)v1 >> 16 )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_pEntity;
  }
  if ( pPlayer == m_pEntity && (m_pNext = g_pGameRules[139].m_pNext, *(float *)&m_pNext < 45.0) )
    return (int)*(float *)&m_pNext;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029EF00
// Name: int FFEVAL_FIRST_BLOOD(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FFEVAL_FIRST_BLOOD(CCSPlayer *pPlayer)
{
  const char *m_pszName; // ecx
  CCSPlayer *m_pEntity; // eax
  CGameRules_vtbl *v3; // xmm0_4

  m_pszName = g_pGameRules[139].m_pszName;
  if ( m_pszName == (const char *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pszName].m_SerialNumber != (unsigned int)m_pszName >> 16 )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pszName].m_pEntity;
  }
  if ( pPlayer == m_pEntity && (v3 = g_pGameRules[140].__vftable, *(float *)&v3 < 45.0) )
    return (int)*(float *)&v3;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1029EF60
// Name: CreateFunFact_FUNFACT_FIRST_KILL
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_FIRST_KILL()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 11;
  result->m_pLocalizationToken = "#funfact_first_kill";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_FIRST_KILL;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029EFB0
// Name: CreateFunFact_FUNFACT_FIRST_BLOOD
// Source: json
//------------------------------------------------------------------------------
FunFactEvaluator *__cdecl CreateFunFact_FUNFACT_FIRST_BLOOD()
{
  FunFactEvaluator *result; // eax

  result = (FunFactEvaluator *)operator new(nSize: 0x1Cu);
  if ( result == nullptr )
    return nullptr;
  result->m_id = 12;
  result->m_pLocalizationToken = "#funfact_first_blood";
  result->m_fCoolness = 0.2;
  result->__vftable = (FunFactEvaluator_vtbl *)&CFunFact_PlayerEvalFunction::`vftable';
  result[1].__vftable = (FunFactEvaluator_vtbl *)FFEVAL_FIRST_BLOOD;
  result[1].m_id = 1;
  result[1].m_pLocalizationToken = (const char *)4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029F000
// Name: public: virtual bool CFunFact_GenericEvalFunction::Evaluate(class CUtlVector<struct FunFact,class CUtlMemory<struct FunFact,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFunFact_GenericEvalFunction::Evaluate(
        CFunFact_GenericEvalFunction *this,
        CUtlVector<FunFact,CUtlMemory<FunFact,int> > *results)
{
  bool (__cdecl *m_pfnEval)(int *, int *, int *, int *); // ecx
  const char *m_pLocalizationToken; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  FunFact funfact; // [esp+0h] [ebp-1Ch] BYREF

  memset(&funfact.szLocalizationToken, 0, 24);
  m_pfnEval = this->m_pfnEval;
  funfact.id = -1;
  if ( ((unsigned __int8 (__stdcall *)(int *))m_pfnEval)(a1: &funfact.iPlayer) == 0 )
    return 0;
  m_pLocalizationToken = this->m_pLocalizationToken;
  funfact.id = this->m_id;
  m_Size = results->m_Size;
  funfact.szLocalizationToken = m_pLocalizationToken;
  funfact.fMagnitude = 0.0;
  CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
    this: (CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *)results,
    elem: m_Size,
    src: (const TeleportListEntry_t *)&funfact);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029F080
// Name: public: virtual bool CFunFact_PlayerEvalFunction::Evaluate(class CUtlVector<struct FunFact,class CUtlMemory<struct FunFact,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFunFact_PlayerEvalFunction::Evaluate(
        CFunFact_PlayerEvalFunction *this,
        CUtlVector<FunFact,CUtlMemory<FunFact,int> > *results)
{
  int v3; // ecx
  bool result; // al
  int v5; // ebx
  CBasePlayer *v6; // edi
  CCSPlayer *v7; // edi
  int v8; // eax
  int m_min; // ecx
  const char *m_pLocalizationToken; // edx
  int v11; // edx
  int m_id; // eax
  float v13; // xmm1_4
  int v14; // edx
  int m_Size; // [esp-14h] [ebp-3Ch]
  FunFact funfact; // [esp+0h] [ebp-28h] BYREF
  int iBestPlayer; // [esp+1Ch] [ebp-Ch]
  int iBestValue; // [esp+20h] [ebp-8h]
  bool bResult; // [esp+27h] [ebp-1h]

  v3 = 0;
  result = false;
  v5 = 1;
  iBestValue = 0;
  iBestPlayer = 0;
  bResult = false;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v6 = UTIL_PlayerByIndex(playerIndex: v5);
      if ( v6 != nullptr && v6->IsPlayer(this: v6) )
      {
        v7 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v6,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        if ( v7 != nullptr && PlayerQualifies(pPlayer: v7, flags: this->m_flags) )
        {
          v8 = this->m_pfnEval(a1: v7);
          if ( (this->m_flags & 4) != 0 )
          {
            if ( v8 > iBestValue )
            {
              iBestValue = v8;
              iBestPlayer = v5;
            }
          }
          else
          {
            m_min = this->m_min;
            if ( v8 >= m_min )
            {
              funfact.iData2 = 0;
              funfact.iData3 = 0;
              funfact.id = this->m_id;
              m_pLocalizationToken = this->m_pLocalizationToken;
              funfact.iData1 = v8;
              funfact.szLocalizationToken = m_pLocalizationToken;
              m_Size = results->m_Size;
              funfact.iPlayer = v5;
              funfact.fMagnitude = 1.0 - (float)((float)m_min / (float)v8);
              CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
                this: (CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *)results,
                elem: m_Size,
                src: (const TeleportListEntry_t *)&funfact);
              bResult = true;
            }
          }
        }
      }
      ++v5;
    }
    while ( v5 <= gpGlobals->maxClients );
    result = bResult;
    v3 = iBestValue;
  }
  if ( (this->m_flags & 4) != 0 )
  {
    v11 = this->m_min;
    if ( v3 >= v11 )
    {
      funfact.iData2 = 0;
      funfact.iData3 = 0;
      m_id = this->m_id;
      funfact.iData1 = v3;
      funfact.id = m_id;
      v13 = (float)v11;
      v14 = results->m_Size;
      funfact.szLocalizationToken = this->m_pLocalizationToken;
      funfact.iPlayer = iBestPlayer;
      funfact.fMagnitude = 1.0 - (float)(v13 / (float)v3);
      CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
        this: (CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *)results,
        elem: v14,
        src: (const TeleportListEntry_t *)&funfact);
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029F200
// Name: public: virtual bool CFunFact_StatBest::Evaluate(class CUtlVector<struct FunFact,class CUtlMemory<struct FunFact,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFunFact_StatBest::Evaluate(
        CFunFact_StatBest *this,
        CUtlVector<FunFact,CUtlMemory<FunFact,int> > *results)
{
  CFunFact_StatBest *v2; // edi
  int v3; // esi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // ebx
  CSStatType_t m_statId; // edi
  int v7; // eax
  int m_min; // eax
  int m_id; // edx
  const char *m_singularLocalizationToken; // edi
  int m_Size; // [esp-8h] [ebp-38h]
  FunFact funfact; // [esp+8h] [ebp-28h] BYREF
  int iBestPlayer; // [esp+24h] [ebp-Ch]
  CFunFact_StatBest *v15; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]

  v2 = this;
  v3 = 0;
  v15 = this;
  iBestPlayer = 0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: i);
    v5 = v4;
    if ( v4 != nullptr && PlayerQualifies(pPlayer: v4, flags: v2->m_flags) )
    {
      m_statId = v2->m_statId;
      v7 = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v5)->statsCurrentRound.m_iValue[m_statId];
      v2 = v15;
      if ( v7 > v3 )
      {
        v3 = v7;
        iBestPlayer = i;
      }
    }
  }
  m_min = v2->m_min;
  if ( v3 < m_min )
    return 0;
  m_id = v2->m_id;
  funfact.iData2 = 0;
  funfact.iData3 = 0;
  funfact.id = m_id;
  if ( v3 == 1 )
    m_singularLocalizationToken = v2->m_singularLocalizationToken;
  else
    m_singularLocalizationToken = v2->m_pLocalizationToken;
  funfact.iPlayer = iBestPlayer;
  m_Size = results->m_Size;
  funfact.szLocalizationToken = m_singularLocalizationToken;
  funfact.iData1 = v3;
  funfact.fMagnitude = 1.0 - (float)((float)m_min / (float)v3);
  CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
    this: (CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *)results,
    elem: m_Size,
    src: (const TeleportListEntry_t *)&funfact);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1029F310
// Name: public: virtual bool CFunFact_StatSum::Evaluate(class CUtlVector<struct FunFact,class CUtlMemory<struct FunFact,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFunFact_StatSum::Evaluate(
        CFunFact_StatSum *this,
        CUtlVector<FunFact,CUtlMemory<FunFact,int> > *results)
{
  int v3; // esi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // ebx
  int m_min; // eax
  const char *m_pLocalizationToken; // edx
  int m_Size; // [esp-8h] [ebp-34h]
  FunFact funfact; // [esp+8h] [ebp-24h] BYREF
  CSStatType_t m_statId; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v3 = 0;
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v4 = UTIL_PlayerByIndex(playerIndex: i);
    v5 = v4;
    if ( v4 != nullptr && PlayerQualifies(pPlayer: v4, flags: this->m_flags) )
    {
      m_statId = this->m_statId;
      v3 += CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v5)->statsCurrentRound.m_iValue[m_statId];
    }
  }
  m_min = this->m_min;
  if ( v3 < m_min )
    return 0;
  funfact.id = this->m_id;
  m_pLocalizationToken = this->m_pLocalizationToken;
  funfact.iData2 = 0;
  funfact.iData3 = 0;
  funfact.iPlayer = 0;
  funfact.szLocalizationToken = m_pLocalizationToken;
  m_Size = results->m_Size;
  funfact.iData1 = v3;
  funfact.fMagnitude = 1.0 - (float)((float)m_min / (float)v3);
  CUtlVector<collidelist_t,CUtlMemory<collidelist_t,int>>::InsertBefore(
    this: (CUtlVector<TeleportListEntry_t,CUtlMemory<TeleportListEntry_t,int> > *)results,
    elem: m_Size,
    src: (const TeleportListEntry_t *)&funfact);
  return 1;
}
