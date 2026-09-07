// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_gamestats.cpp
// Functions: 84
// ============================================================

#include "game\server\cstrike15\cs_gamestats.h"

//------------------------------------------------------------------------------
// Address: 0x10278450
// Name: public: bool CCSPlayer::IsBlind(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::IsBlind(CCSPlayer *this)
{
  return this->m_blindUntilTime > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10278470
// Name: public: struct RoundStatsDirectAverage_t __near & RoundStatsDirectAverage_t::operator+=(struct StatsCollection_t const __near &)
// Source: json
//------------------------------------------------------------------------------
RoundStatsDirectAverage_t *__thiscall RoundStatsDirectAverage_t::operator+=(
        RoundStatsDirectAverage_t *this,
        const StatsCollection_t *other)
{
  RoundStatsDirectAverage_t *result; // eax
  unsigned int v3; // esi
  float *v4; // edx

  result = this;
  v3 = 0;
  v4 = &this->m_fStat[1];
  do
  {
    *(v4 - 1) = (float)other->m_iValue[v3] + *(v4 - 1);
    *v4 = (float)*(int *)((char *)v4 + (char *)other - (char *)this) + *v4;
    v3 += 2;
    v4 += 2;
  }
  while ( v3 < 0x106 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102784D0
// Name: public: void PlayerStats_t::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerStats_t::Reset(PlayerStats_t *this)
{
  KillStats_t *p_statsKills; // esi

  memset(this, 0, 0x418u);
  memset(&this->statsCurrentRound, 0, sizeof(this->statsCurrentRound));
  p_statsKills = &this->statsKills;
  memset(&this->statsCurrentMatch, 0, sizeof(this->statsCurrentMatch));
  _V_memset(dest: &this->statsKills, fill: 0, count: 260);
  _V_memset(dest: p_statsKills->iNumKilledBy, fill: 0, count: 260);
  _V_memset(dest: p_statsKills->iNumKilledByUnanswered, fill: 0, count: 260);
}

//------------------------------------------------------------------------------
// Address: 0x10278540
// Name: int GetCSLevelIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetCSLevelIndex(const char *pLevelName)
{
  int v1; // esi
  int v2; // eax

  v1 = 0;
  v2 = 0;
  while ( _V_strcmp(s1: pLevelName, s2: MapName_StatId_Table[v2].szMapName) != 0 )
  {
    v2 = ++v1;
    if ( dword_104D9D3C[4 * v1] == -1 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10278590
// Name: protected: void CCSGameStats::SendDirectStatsAveragesToAllPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::SendDirectStatsAveragesToAllPlayers(CCSGameStats *this)
{
  RoundStatsDirectAverage_t *p_m_directCTStatAverages; // esi
  int v2; // ebx
  int i; // edi
  CRecipientFilter filter; // [esp+10h] [ebp-24h] BYREF
  RoundStatsDirectAverage_t *v5; // [esp+30h] [ebp-4h]

  p_m_directCTStatAverages = &this->m_directCTStatAverages;
  v2 = 0;
  v5 = &this->m_directCTStatAverages;
  do
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    CRecipientFilter::AddAllPlayers(this: &filter);
    UserMessageBegin(&filter, messagename: "MatchStatsUpdate");
    MessageWriteShort(iValue: v2);
    for ( i = v2; i < 262; p_m_directCTStatAverages = (RoundStatsDirectAverage_t *)((char *)p_m_directCTStatAverages + 4) )
    {
      if ( i > v2 + 41 )
        break;
      MessageWriteFloat(flValue: p_m_directCTStatAverages[1].m_fStat[0]);
      MessageWriteFloat(flValue: p_m_directCTStatAverages->m_fStat[0]);
      MessageWriteFloat(flValue: p_m_directCTStatAverages[2].m_fStat[0]);
      ++i;
    }
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &filter);
    v2 += 42;
    p_m_directCTStatAverages = (RoundStatsDirectAverage_t *)&v5->m_fStat[42];
    v5 = (RoundStatsDirectAverage_t *)((char *)v5 + 168);
  }
  while ( v2 < 294 );
}

//------------------------------------------------------------------------------
// Address: 0x10278650
// Name: public: void CCSGameStats::DumpMatchWeaponMetrics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::DumpMatchWeaponMetrics(CCSGameStats *this)
{
  tm *v1; // eax
  int tm_year; // ecx
  int tm_mon; // edx
  int tm_hour; // ebx
  const char *pszValue; // esi
  int tm_mday; // edi
  int tm_sec; // eax
  int v8; // ecx
  int v9; // edx
  void *v10; // esi
  CSWeaponID v11; // edi
  CCSWeaponInfo *WeaponInfo; // ebx
  int *v13; // esi
  IFileSystem_vtbl *v14; // edi
  int WeaponPrice; // eax
  int m_nValue; // ecx
  int m_iBullets; // [esp+Ch] [ebp-C0h]
  double m_flCycleTime; // [esp+10h] [ebp-BCh]
  int v19; // [esp+18h] [ebp-B4h]
  int v20; // [esp+1Ch] [ebp-B0h]
  int v21; // [esp+20h] [ebp-ACh]
  int v22; // [esp+24h] [ebp-A8h]
  char filename[128]; // [esp+30h] [ebp-9Ch] BYREF
  __int64 t; // [esp+B0h] [ebp-1Ch] BYREF
  void *hLogFile; // [esp+B8h] [ebp-14h]
  const char *pWeaponName; // [esp+BCh] [ebp-10h]
  int iMode; // [esp+C0h] [ebp-Ch]
  int iWeapon; // [esp+C4h] [ebp-8h]
  CCSGameStats *v29; // [esp+C8h] [ebp-4h]

  v29 = this;
  t = _time64(timeptr: nullptr);
  v1 = _localtime64(ptime: &t);
  if ( v1 != nullptr )
  {
    tm_year = v1->tm_year;
    tm_mon = v1->tm_mon;
    tm_hour = v1->tm_hour;
    iWeapon = v1->tm_min;
    pszValue = gpGlobals->mapname.pszValue;
    tm_mday = v1->tm_mday;
    tm_sec = v1->tm_sec;
    v8 = tm_year + 1900;
    v9 = tm_mon + 1;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_snprintf(
      pDest: filename,
      maxLen: 128,
      pFormat: "wm_%4d%02d%02d_%02d%02d%02d_%s.csv",
      v8,
      v9,
      tm_mday,
      tm_hour,
      iWeapon,
      tm_sec,
      pszValue);
    v10 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: filename, a3: "wt", a4: 0);
    hLogFile = v10;
    if ( v10 != nullptr )
    {
      ((void (__stdcall *)(IFileSystem *))filesystem->FPrintf)(a1: filesystem);
      v11 = WEAPON_NONE;
      iWeapon = 0;
      v29 = (CCSGameStats *)((char *)v29 + 263624);
      do
      {
        WeaponInfo = GetWeaponInfo(weaponID: v11);
        if ( WeaponInfo != nullptr )
        {
          pWeaponName = WeaponInfo->szClassName;
          if ( WeaponInfo != (CCSWeaponInfo *)-6 )
          {
            if ( V_strncmp(s1: WeaponInfo->szClassName, s2: "weapon_", count: 7) == 0 )
              pWeaponName += 7;
            v13 = (int *)v29;
            for ( iMode = 0; iMode < 2; ++iMode )
            {
              v14 = filesystem->IAppSystem::__vftable;
              v22 = v13[1];
              v21 = v13[2];
              v20 = *v13;
              v19 = *(v13 - 1);
              m_flCycleTime = WeaponInfo->m_flCycleTime;
              m_iBullets = WeaponInfo->m_iBullets;
              WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo);
              v14->FPrintf(
                this: filesystem,
                a2: hLogFile,
                a3: "%s, %d, %d, %d, %f, %d, %d, %d, %d\n",
                pWeaponName,
                iMode,
                WeaponPrice,
                m_iBullets,
                m_flCycleTime,
                v19,
                v20,
                v21,
                v22);
              v13 += 4;
            }
            v11 = iWeapon;
            v10 = hLogFile;
          }
        }
        v29 = (CCSGameStats *)((char *)v29 + 32);
        iWeapon = ++v11;
      }
      while ( v11 < WEAPON_MAX );
      filesystem->FPrintf(this: filesystem, a2: v10, a3: "\n");
      if ( cv_bot_difficulty.m_pParent != nullptr )
        m_nValue = cv_bot_difficulty.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      filesystem->FPrintf(this: filesystem, a2: v10, a3: "bot_difficulty, %d\n", m_nValue);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278850
// Name: public: struct StatsCollection_t const __near & CCSGameStats::GetTeamStats(int)const
// Source: json
//------------------------------------------------------------------------------
const StatsCollection_t *__thiscall CCSGameStats::GetTeamStats(CCSGameStats *this, int iTeamIndex)
{
  return (const StatsCollection_t *)&this->m_aPlayerStats[64].statsCurrentRound.m_iValue[262 * iTeamIndex + 195];
}

//------------------------------------------------------------------------------
// Address: 0x10278870
// Name: public: void CCSGameStats::ResetAllStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ResetAllStats(CCSGameStats *this)
{
  int *iNumKilledByUnanswered; // esi
  bool v3; // zf
  int v4; // [esp+Ch] [ebp-4h]

  iNumKilledByUnanswered = this->m_aPlayerStats[0].statsKills.iNumKilledByUnanswered;
  v4 = 65;
  do
  {
    memset(iNumKilledByUnanswered - 916, 0, 0x418u);
    memset(iNumKilledByUnanswered - 654, 0, 0x418u);
    memset(iNumKilledByUnanswered - 392, 0, 0x418u);
    _V_memset(dest: iNumKilledByUnanswered - 130, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered - 65, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered, fill: 0, count: 260);
    memset(&this->m_rollingCTStatAverages, 0, 0x418u);
    this->m_rollingCTStatAverages.m_numberOfDataSets = 0;
    memset(&this->m_rollingTStatAverages, 0, 0x418u);
    this->m_rollingTStatAverages.m_numberOfDataSets = 0;
    memset(&this->m_rollingPlayerStatAverages, 0, 0x418u);
    this->m_rollingPlayerStatAverages.m_numberOfDataSets = 0;
    iNumKilledByUnanswered += 981;
    v3 = v4-- == 1;
    this->m_numberOfRoundsForDirectAverages = 0;
    this->m_numberOfTerroristEntriesForDirectAverages = 0;
    this->m_numberOfCounterTerroristEntriesForDirectAverages = 0;
  }
  while ( !v3 );
}

//------------------------------------------------------------------------------
// Address: 0x10278960
// Name: public: void CCSGameStats::ResetRoundStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ResetRoundStats(CCSGameStats *this)
{
  StatsCollection_t *p_statsCurrentRound; // edx
  int i; // esi
  StatsCollection_t *v3; // edi

  p_statsCurrentRound = &this->m_aPlayerStats[0].statsCurrentRound;
  for ( i = 65; i != 0; --i )
  {
    v3 = p_statsCurrentRound;
    p_statsCurrentRound = (StatsCollection_t *)((char *)p_statsCurrentRound + 3924);
    memset(v3, 0, sizeof(StatsCollection_t));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278990
// Name: public: virtual void CCSGameStats::Event_LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameStats::Event_LevelInit(CCSGameStats *this@<ecx>, int a2@<ebx>)
{
  RoundStatsRollingAverage_t *p_m_rollingCTStatAverages; // edi
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax

  memset(this->m_aTeamStats, 0, sizeof(this->m_aTeamStats));
  p_m_rollingCTStatAverages = &this->m_rollingCTStatAverages;
  _V_memset(dest: this->m_weaponStats, fill: 0, count: 1344);
  CBaseGameStats::Event_LevelInit(this);
  SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
  CSteamWorksGameStatsUploader::StartSession(this: SteamWorksSGameStatsUploader, a2, a3: (int)p_m_rollingCTStatAverages);
}

//------------------------------------------------------------------------------
// Address: 0x102789D0
// Name: public: void CCSGameStats::ResetPlayerClassMatchStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ResetPlayerClassMatchStats(CCSGameStats *this)
{
  int i; // edi
  CBasePlayer *v2; // esi
  CCSPlayer *v3; // eax

  for ( i = 1; i <= 64; ++i )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
    {
      v3 = (CCSPlayer *)__RTDynamicCast(
                          inptr: v2,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
      if ( v3 != nullptr )
        CCSPlayer::SetNumMVPs(this: v3, iNumMVP: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278A30
// Name: public: bool CCSPlayer::PlacedBombThisRound(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::PlacedBombThisRound(CCSPlayer *this)
{
  return this->m_bombPlacedTime >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10278A50
// Name: public: class CCSPlayer __near * CCSPlayer::GetControlledBot(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSPlayer::GetControlledBot(CCSPlayer *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hControlledBot.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10278A80
// Name: public: SWeaponMissData::SWeaponMissData(struct SWeaponShotData __near *)
// Source: json
//------------------------------------------------------------------------------
SWeaponMissData *__thiscall SWeaponMissData::SWeaponMissData(SWeaponMissData *this, SWeaponShotData *data)
{
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // ebx
  CBaseMultiplayerPlayer *v6; // eax
  CBaseMultiplayerPlayer *v7; // ebx
  unsigned __int64 m_unAll64Bits; // rax

  this->m_bUseGlobalData = true;
  SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
  this->TimeSubmitted = CSteamWorksGameStatsUploader::GetTimeSinceEpoch(this: SteamWorksSGameStatsUploader);
  this->m_ui8WeaponID = 0;
  this->m_uiBulletID = 0;
  this->m_uiSubBulletID = 0;
  this->m_ui64AttackerID = 0;
  this->m_vAttackerPos.x = 0.0;
  this->m_vAttackerPos.y = 0.0;
  this->m_vAttackerPos.z = 0.0;
  this->m_RoundID = 0;
  if ( data != nullptr )
  {
    v4 = UTIL_PlayerByUserId(userID: data->m_iUserID);
    v5 = v4;
    if ( v4 != nullptr && v4->IsPlayer(this: v4) )
    {
      v6 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                       inptr: v5,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                                       isReference: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        if ( v6->IsBot(this: v6) )
          m_unAll64Bits = 0;
        else
          m_unAll64Bits = CBaseMultiplayerPlayer::GetSteamIDAsUInt64(this: v7).m_unAll64Bits;
        this->m_ui64AttackerID = m_unAll64Bits;
      }
    }
    this->m_ui8WeaponID = data->m_WeaponID;
    this->m_uiBulletID = data->m_uiBulletID;
    this->m_uiSubBulletID = data->m_uiSubBulletID;
    this->m_vAttackerPos = data->m_vAttackerPos;
    this->m_RoundID = data->m_RoundID;
    this->TimeSubmitted = data->TimeSubmitted;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10278B90
// Name: SvNoNemesisChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvNoNemesisChangeCallback(IConVar *pConVar)
{
  int i; // edi
  CBasePlayer *v2; // esi
  CCSPlayer *v3; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( ConVarRef::IsValid(this: &var) && var.m_pConVarState->m_Value.m_nValue != 0 )
  {
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v2 = UTIL_PlayerByIndex(playerIndex: i);
      if ( v2 != nullptr && v2->IsPlayer(this: v2) )
      {
        v3 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v2,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        if ( v3 != nullptr )
          CCSPlayer::RemoveNemesisRelationships(this: v3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278C30
// Name: public: virtual bool CCSGameStats::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameStats::Init(CCSGameStats *this)
{
  IGameEventListener2 *v1; // esi

  v1 = (IGameEventListener2 *)((char *)this - 12);
  *((_BYTE *)&this->m_BasicStats.m_Summary - 12) = 1;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: (IGameEventListener2 *)((char *)this - 12),
    a3: "round_end",
    a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "break_prop", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "player_decal", a4: true);
  LOBYTE(v1[2].__vftable) = 1;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "cs_win_panel_match", a4: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10278CA0
// Name: public: void CCSGameStats::Event_AllHostagesRescued(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_AllHostagesRescued(CCSGameStats *this)
{
  ++this->m_aTeamStats[1].m_iValue[18];
}

//------------------------------------------------------------------------------
// Address: 0x10278CB0
// Name: protected: void CCSGameStats::ComputeDirectStatAverages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ComputeDirectStatAverages(CCSGameStats *this)
{
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // edi
  void *v4; // eax
  signed int v5; // edx
  StatsCollection_t *p_statsCurrentMatch; // edi
  int TeamNumber; // eax
  RoundStatsDirectAverage_t *p_m_directCTStatAverages; // ecx
  int v9; // eax
  float v10; // xmm1_4
  unsigned int v11; // eax
  float v12; // xmm0_4
  int *v13; // edx
  float v14; // xmm0_4
  unsigned int i; // eax
  int v16; // eax
  float v17; // xmm1_4
  unsigned int v18; // eax
  float v19; // xmm0_4
  float v20; // xmm0_4
  unsigned int j; // eax
  int v22; // eax
  float v23; // xmm2_4
  unsigned int k; // eax
  float v25; // xmm0_4
  unsigned int m; // eax
  int *p_m_numberOfRoundsForDirectAverages; // [esp+Ch] [ebp-Ch]
  int iPlayerIndex; // [esp+10h] [ebp-8h]
  RoundStatsDirectAverage_t *p_m_directPlayerStatAverages; // [esp+14h] [ebp-4h]

  ++this->m_numberOfRoundsForDirectAverages;
  p_m_numberOfRoundsForDirectAverages = &this->m_numberOfRoundsForDirectAverages;
  memset(&this->m_directCTStatAverages, 0, sizeof(this->m_directCTStatAverages));
  memset(&this->m_directTStatAverages, 0, sizeof(this->m_directTStatAverages));
  p_m_directPlayerStatAverages = &this->m_directPlayerStatAverages;
  memset(&this->m_directPlayerStatAverages, 0, sizeof(this->m_directPlayerStatAverages));
  for ( iPlayerIndex = 1; iPlayerIndex <= 64; ++iPlayerIndex )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: iPlayerIndex);
    v3 = v2;
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
    {
      v4 = __RTDynamicCast(
             inptr: v3,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CCSPlayer `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 != nullptr && *((_DWORD *)v4 + 914) != 2 )
      {
        v5 = *((_DWORD *)v4 + 6);
        if ( v5 != 0 )
          v5 = (signed int)(v5 - (unsigned int)gpGlobals->pEdicts) >> 4;
        p_statsCurrentMatch = &this->m_aPlayerStats[v5].statsCurrentMatch;
        TeamNumber = CBaseEntity::GetTeamNumber(this: (CBaseEntity *)v4);
        if ( TeamNumber == 3 )
        {
          ++this->m_numberOfCounterTerroristEntriesForDirectAverages;
          p_m_directCTStatAverages = &this->m_directCTStatAverages;
        }
        else
        {
          if ( TeamNumber != 2 )
            continue;
          ++this->m_numberOfTerroristEntriesForDirectAverages;
          p_m_directCTStatAverages = &this->m_directTStatAverages;
        }
        RoundStatsDirectAverage_t::operator+=(this: p_m_directCTStatAverages, other: p_statsCurrentMatch);
        RoundStatsDirectAverage_t::operator+=(this: p_m_directPlayerStatAverages, other: p_statsCurrentMatch);
      }
    }
  }
  v9 = this->m_numberOfTerroristEntriesForDirectAverages;
  if ( v9 <= 0 )
  {
    v13 = p_m_numberOfRoundsForDirectAverages;
  }
  else
  {
    v10 = (float)v9;
    if ( (float)v9 > 0.0 )
    {
      v11 = 0;
      v12 = 1.0 / v10;
      do
      {
        this->m_directTStatAverages.m_fStat[v11] = v12 * this->m_directTStatAverages.m_fStat[v11];
        this->m_directTStatAverages.m_fStat[v11 + 1] = v12 * this->m_directTStatAverages.m_fStat[v11 + 1];
        v11 += 2;
      }
      while ( v11 < 0x106 );
    }
    v13 = p_m_numberOfRoundsForDirectAverages;
    v14 = (float)*p_m_numberOfRoundsForDirectAverages;
    for ( i = 0; i < 0x106; i += 2 )
    {
      this->m_directTStatAverages.m_fStat[i] = this->m_directTStatAverages.m_fStat[i] * v14;
      this->m_directTStatAverages.m_fStat[i + 1] = v14 * this->m_directTStatAverages.m_fStat[i + 1];
    }
  }
  v16 = this->m_numberOfCounterTerroristEntriesForDirectAverages;
  if ( v16 > 0 )
  {
    v17 = (float)v16;
    if ( (float)v16 > 0.0 )
    {
      v18 = 0;
      v19 = 1.0 / v17;
      do
      {
        this->m_directCTStatAverages.m_fStat[v18] = this->m_directCTStatAverages.m_fStat[v18] * v19;
        this->m_directCTStatAverages.m_fStat[v18 + 1] = v19 * this->m_directCTStatAverages.m_fStat[v18 + 1];
        v18 += 2;
      }
      while ( v18 < 0x106 );
    }
    v20 = (float)*v13;
    for ( j = 0; j < 0x106; j += 2 )
    {
      this->m_directCTStatAverages.m_fStat[j] = v20 * this->m_directCTStatAverages.m_fStat[j];
      this->m_directCTStatAverages.m_fStat[j + 1] = this->m_directCTStatAverages.m_fStat[j + 1] * v20;
    }
  }
  v22 = this->m_numberOfTerroristEntriesForDirectAverages + this->m_numberOfCounterTerroristEntriesForDirectAverages;
  if ( v22 > 0 )
  {
    if ( (float)v22 > 0.0 )
    {
      v23 = 1.0 / (float)v22;
      for ( k = 0; k < 0x106; k += 2 )
      {
        p_m_directPlayerStatAverages->m_fStat[k] = v23 * p_m_directPlayerStatAverages->m_fStat[k];
        p_m_directPlayerStatAverages->m_fStat[k + 1] = v23 * p_m_directPlayerStatAverages->m_fStat[k + 1];
      }
    }
    v25 = (float)*v13;
    for ( m = 0; m < 0x106; m += 2 )
    {
      p_m_directPlayerStatAverages->m_fStat[m] = p_m_directPlayerStatAverages->m_fStat[m] * v25;
      p_m_directPlayerStatAverages->m_fStat[m + 1] = p_m_directPlayerStatAverages->m_fStat[m + 1] * v25;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278F90
// Name: public: struct PlayerStats_t const __near & CCSGameStats::FindPlayerStats(class CBasePlayer __near *)const
// Source: json
//------------------------------------------------------------------------------
const PlayerStats_t *__thiscall CCSGameStats::FindPlayerStats(CCSGameStats *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    return &this->m_aPlayerStats[m_pPev - gpGlobals->pEdicts];
  else
    return this->m_aPlayerStats;
}

//------------------------------------------------------------------------------
// Address: 0x10278FD0
// Name: public: void CCSGameStats::ResetKillHistory(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ResetKillHistory(CCSGameStats *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // edx
  signed int v3; // edx
  int v4; // esi
  int v5; // edi
  int *iNumKilledBy; // eax
  _DWORD *v7; // ecx
  int v8; // edx
  int i; // esi

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v3 = m_pPev - gpGlobals->pEdicts;
  else
    v3 = 0;
  v4 = 4 * v3 + 3404;
  v5 = 4 * v3 + 3144 - v4;
  iNumKilledBy = this->m_aPlayerStats[v3].statsKills.iNumKilledBy;
  v7 = (int *)((char *)this->m_aPlayerStats[0].statsDelta.m_iValue + v4);
  v8 = 4 * v3 + 3664 - v4;
  for ( i = 65; i != 0; --i )
  {
    *(_DWORD *)((char *)v7 + v5) = 0;
    *v7 = 0;
    *(_DWORD *)((char *)v7 + v8) = 0;
    *(iNumKilledBy - 65) = 0;
    *iNumKilledBy = 0;
    iNumKilledBy[65] = 0;
    ++iNumKilledBy;
    v7 += 981;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279050
// Name: public: void CCSGameStats::IncrementStat(class CCSPlayer __near *,enum CSStatType_t,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::IncrementStat(
        CCSGameStats *this,
        CCSPlayer *pPlayer,
        CSStatType_t statId,
        int iDelta,
        bool bPlayerOnly)
{
  CCSPlayer *v6; // ecx
  CCSPlayer *ControlledBot; // eax
  signed int m_pPev; // eax
  PlayerStats_t *v9; // edi
  unsigned int v10; // eax
  int *p_matchRequirement; // ebx
  const char *pszValue; // eax
  bool v13; // cl
  bool v14; // al
  int bPlayerOnlya; // [esp+1Ch] [ebp+14h]

  v6 = pPlayer;
  if ( pPlayer != nullptr )
  {
    while ( !v6->m_bTeamChanged )
    {
      if ( !v6->m_bIsControllingBot.m_Value )
      {
        m_pPev = (signed int)v6->m_Network.m_pPev;
        if ( m_pPev != 0 )
          m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
        v9 = &this->m_aPlayerStats[m_pPev];
        v9->statsDelta.m_iValue[statId] += iDelta;
        v9->statsCurrentRound.m_iValue[statId] += iDelta;
        v9->statsCurrentMatch.m_iValue[statId] += iDelta;
        v10 = CBaseEntity::GetTeamNumber(this: v6) - 2;
        if ( !bPlayerOnly && v10 <= 1 )
          this->m_aTeamStats[v10].m_iValue[statId] += iDelta;
        p_matchRequirement = &ServerStatBasedAchievements[0].matchRequirement;
        for ( bPlayerOnlya = 5; bPlayerOnlya != 0; --bPlayerOnlya )
        {
          if ( *(p_matchRequirement - 2) == statId )
          {
            if ( p_matchRequirement[1] == 0 )
              goto LABEL_18;
            pszValue = gpGlobals->mapname.pszValue;
            if ( pszValue == nullptr )
              pszValue = locale;
            if ( _V_strcmp(s1: pszValue, s2: (const char *)p_matchRequirement[1]) == 0 )
            {
LABEL_18:
              v13 = v9->statsCurrentRound.m_iValue[statId] - iDelta >= *(p_matchRequirement - 1)
                 && v9->statsCurrentMatch.m_iValue[statId] - iDelta >= *p_matchRequirement;
              v14 = v9->statsCurrentRound.m_iValue[statId] >= *(p_matchRequirement - 1)
                 && v9->statsCurrentMatch.m_iValue[statId] >= *p_matchRequirement;
              if ( !v13 && v14 )
                CBaseMultiplayerPlayer::AwardAchievement(
                  this: pPlayer,
                  iAchievement: *(p_matchRequirement - 3),
                  iCount: 1);
            }
          }
          p_matchRequirement += 5;
        }
        return;
      }
      ControlledBot = CCSPlayer::GetControlledBot(this: v6);
      if ( ControlledBot == nullptr )
        return;
      pPlayer = ControlledBot;
      v6 = ControlledBot;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102791B0
// Name: protected: void CCSGameStats::TrackKillStats(class CCSPlayer __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::TrackKillStats(CCSGameStats *this, CCSPlayer *pAttacker, CCSPlayer *pVictim)
{
  edict_t *m_pPev; // eax
  signed int v4; // eax
  edict_t *v5; // edx
  PlayerStats_t *v6; // esi
  PlayerStats_t *v7; // ecx

  m_pPev = pAttacker->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v4 = m_pPev - gpGlobals->pEdicts;
  else
    v4 = 0;
  v5 = pVictim->m_Network.m_pPev;
  if ( v5 != nullptr )
    v5 -= (int)gpGlobals->pEdicts;
  v6 = &this->m_aPlayerStats[v4];
  v7 = &this->m_aPlayerStats[(_DWORD)v5];
  ++v7->statsKills.iNumKilledBy[v4];
  ++v7->statsKills.iNumKilledByUnanswered[v4];
  ++v6->statsKills.iNumKilled[(_DWORD)v5];
  v6->statsKills.iNumKilledByUnanswered[(_DWORD)v5] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10279230
// Name: public: virtual void CCSGameStats::Event_LevelShutdown(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_LevelShutdown(CCSGameStats *this, float fElapsed)
{
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax

  if ( sv_dumpmatchweaponmetrics.m_pParent != nullptr && sv_dumpmatchweaponmetrics.m_pParent->m_Value.m_nValue != 0 )
    CCSGameStats::DumpMatchWeaponMetrics(this);
  CBaseGameStats::Event_LevelShutdown(this, flElapsed: fElapsed);
  SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
  CSteamWorksGameStatsUploader::EndSession(this: SteamWorksSGameStatsUploader);
}

//------------------------------------------------------------------------------
// Address: 0x102792D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,enum CSStatType_t,short>::Node_t,short>,short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short>,short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (__int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > -1 )
      {
        if ( (__int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (__int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::CResponseSystem::Enumeration,short>::Node_t,short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279370
// Name: public: SWeaponShotData::SWeaponShotData(class CCSPlayer __near *,class CWeaponCSBase __near *,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
SWeaponShotData *__thiscall SWeaponShotData::SWeaponShotData(
        SWeaponShotData *this,
        CCSPlayer *pPlayer,
        CWeaponCSBase *pWeapon,
        unsigned __int8 subBullet,
        unsigned __int8 round)
{
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  this->m_bUseGlobalData = true;
  SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
  this->TimeSubmitted = CSteamWorksGameStatsUploader::GetTimeSinceEpoch(this: SteamWorksSGameStatsUploader);
  this->m_iUserID = 0;
  this->m_WeaponID = WEAPON_NONE;
  this->m_uiBulletID = 0;
  this->m_uiSubBulletID = 0;
  this->m_vAttackerPos.x = 0.0;
  this->m_vAttackerPos.y = 0.0;
  this->m_vAttackerPos.z = 0.0;
  this->m_RoundID = 0;
  if ( pWeapon != nullptr )
    this->m_WeaponID = pWeapon->GetCSWeaponID(this: pWeapon);
  if ( pPlayer != nullptr )
  {
    this->m_iUserID = engine->GetPlayerUserId(this: engine, a2: pPlayer->m_Network.m_pPev);
    this->m_uiBulletID = CCSPlayer::GetBulletGroup();
    if ( (pPlayer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&savedregs);
    this->m_vAttackerPos = pPlayer->m_vecAbsOrigin;
  }
  this->m_RoundID = round;
  this->m_uiSubBulletID = subBullet;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10279430
// Name: public: SWeaponHitData::SWeaponHitData(class CCSPlayer __near *,class CTakeDamageInfo const __near &,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
SWeaponHitData *__thiscall SWeaponHitData::SWeaponHitData(
        SWeaponHitData *this,
        CCSPlayer *pCSTarget,
        const CTakeDamageInfo *info,
        unsigned __int8 subBullet,
        unsigned __int8 round)
{
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ebx
  unsigned int v11; // eax
  CEntInfo *v12; // ecx
  IHandleEntity *v13; // edi
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // edi
  unsigned int v17; // eax
  CEntInfo *v18; // ecx
  IHandleEntity *v19; // edi
  CBaseMultiplayerPlayer *v20; // edi
  unsigned int v21; // eax
  CEntInfo *v22; // ecx
  IHandleEntity *v23; // edi
  bool v24; // zf
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v26; // eax
  unsigned __int8 v27; // al
  unsigned __int64 m_unAll64Bits; // rax
  unsigned __int64 v29; // rax
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  this->m_bUseGlobalData = true;
  SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
  this->TimeSubmitted = CSteamWorksGameStatsUploader::GetTimeSinceEpoch(this: SteamWorksSGameStatsUploader);
  this->m_uiBulletID = 0;
  this->m_uiSubBulletID = 0;
  this->m_vAttackerPos.x = 0.0;
  this->m_vAttackerPos.y = 0.0;
  this->m_vAttackerPos.z = 0.0;
  this->m_vTargetPos.x = 0.0;
  this->m_vTargetPos.y = 0.0;
  this->m_vTargetPos.z = 0.0;
  *(_WORD *)&this->m_uiDamage = 0;
  this->m_RoundID = 0;
  this->m_ui64TargertID = 0;
  this->m_ui64AttackerID = 0;
  *(_WORD *)&this->m_ui8Health = 0;
  m_Index = info->m_hWeapon.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v9 = __RTDynamicCast(
         inptr: m_pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  v10 = v9;
  if ( v9 != nullptr )
  {
    this->m_ui8WeaponID = (*(int (__thiscall **)(_DWORD *))(*v9 + 1520))(a1: v9);
  }
  else
  {
    v11 = info->m_hInflictor.m_Index;
    if ( v11 != -1 )
    {
      v12 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v11];
      if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
      {
        v13 = v12->m_pEntity;
        if ( v12->m_pEntity != nullptr )
        {
          v14 = (const char *)v13[23].__vftable;
          if ( v14 == nullptr )
            v14 = locale;
          if ( _V_strcmp(s1: v14, s2: "hegrenade_projectile") != 0 )
          {
            v15 = (const char *)v13[23].__vftable;
            if ( v15 == nullptr )
              v15 = locale;
            if ( _V_strcmp(s1: v15, s2: "planted_c4") != 0 )
            {
              v16 = (const char *)v13[23].__vftable;
              if ( v16 == nullptr )
                v16 = locale;
              if ( _V_strcmp(s1: v16, s2: "inferno") == 0 )
                this->m_ui8WeaponID = 35;
            }
            else
            {
              this->m_ui8WeaponID = 37;
            }
          }
          else
          {
            this->m_ui8WeaponID = 33;
          }
        }
      }
    }
  }
  v17 = info->m_hAttacker.m_Index;
  if ( v17 != -1
    && (v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v17],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber == HIWORD(v17))
    && (v19 = v18->m_pEntity, v18->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v19->__vftable[28].dtr_IHandleEntity)(a1: v18->m_pEntity) != 0 )
  {
    v20 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                      inptr: v19,
                                      VfDelta: 0,
                                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                                      isReference: 0);
    if ( v20 != nullptr )
      goto LABEL_35;
  }
  else
  {
    v20 = nullptr;
  }
  if ( v10 != nullptr )
  {
    v21 = v10[80];
    if ( v21 != -1
      && (v22 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v21],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber == HIWORD(v21))
      && (v23 = v22->m_pEntity, v22->m_pEntity != nullptr)
      && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v23->__vftable[28].dtr_IHandleEntity)(a1: v22->m_pEntity) != 0 )
    {
      v20 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                        inptr: v23,
                                        VfDelta: 0,
                                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                                        isReference: 0);
    }
    else
    {
      v20 = nullptr;
    }
  }
LABEL_35:
  if ( pCSTarget != nullptr && v20 != nullptr )
  {
    v24 = this->m_ui8WeaponID == 0;
    this->m_uiBulletID = info->m_uiBulletID;
    if ( v24 && CBaseCombatCharacter::GetActiveWeapon(this: v20) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v20);
      v26 = __RTDynamicCast(
              inptr: ActiveWeapon,
              VfDelta: 0,
              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
              isReference: 0);
      if ( v26 != nullptr )
        v27 = (*(int (__thiscall **)(void *))(*(_DWORD *)v26 + 1520))(a1: v26);
      else
        v27 = 0;
      this->m_ui8WeaponID = v27;
    }
    if ( (pCSTarget->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pCSTarget, a2: (int)&savedregs);
    this->m_vTargetPos = pCSTarget->m_vecAbsOrigin;
    if ( (v20->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v20, a2: (int)&savedregs);
    this->m_vAttackerPos.x = v20->m_vecAbsOrigin.x;
    this->m_vAttackerPos.y = v20->m_vecAbsOrigin.y;
    this->m_vAttackerPos.z = v20->m_vecAbsOrigin.z;
    this->m_uiDamage = (int)info->m_flDamage;
    this->m_ui8Health = pCSTarget->m_iHealth.m_Value;
    this->m_HitRegion = pCSTarget->m_LastHitGroup;
    if ( pCSTarget->IsBot(this: pCSTarget) )
      m_unAll64Bits = 0;
    else
      m_unAll64Bits = CBaseMultiplayerPlayer::GetSteamIDAsUInt64(this: pCSTarget).m_unAll64Bits;
    this->m_ui64TargertID = m_unAll64Bits;
    if ( v20->IsBot(this: v20) )
      v29 = 0;
    else
      v29 = CBaseMultiplayerPlayer::GetSteamIDAsUInt64(this: v20).m_unAll64Bits;
    this->m_ui64AttackerID = v29;
  }
  this->m_uiSubBulletID = subBullet;
  this->m_RoundID = round;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102797B0
// Name: public: virtual void CCSGameStats::Event_ShotHit(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_ShotHit(CCSGameStats *this, CCSPlayer *pPlayer, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBasePlayer *m_pEntity; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // ebx
  int v10; // eax
  CSWeaponID v11; // edx
  __int32 v12; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  CSWeaponID weaponId; // [esp+8h] [ebp-4h]
  CCSPlayer *pCSPlayer; // [esp+14h] [ebp+8h]

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
    pCSPlayer = (CCSPlayer *)__RTDynamicCast(
                               inptr: pPlayer,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
  else
    pCSPlayer = nullptr;
  CCSGameStats::IncrementStat(this, pPlayer: pCSPlayer, statId: CSSTAT_SHOTS_HIT, iDelta: 1, bPlayerOnly: false);
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr && m_pEntity == pPlayer && CBaseCombatCharacter::GetActiveWeapon(this: pPlayer) != nullptr )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pPlayer);
      v8 = __RTDynamicCast(
             inptr: ActiveWeapon,
             VfDelta: 0,
             SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
             TargetType: &CWeaponCSBase `RTTI Type Descriptor',
             isReference: 0);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v10 = (*(int (__thiscall **)(_DWORD *))(*v8 + 1520))(a1: v8);
        v11 = WEAPON_DEAGLE;
        v12 = v10;
        v13 = 0;
        weaponId = v10;
        v14 = 0;
        while ( v11 != v12 || *(const CSStatType_t *)((char *)&dword_104D9ED0 + v14) == CSSTAT_UNDEFINED )
        {
          v11 = WeaponName_StatId_Table[++v13].weaponId;
          v14 = 20 * v13;
          if ( v11 == WEAPON_NONE )
            goto LABEL_17;
        }
        v15 = 5 * v13;
        CCSGameStats::IncrementStat(
          this,
          pPlayer: pCSPlayer,
          statId: (CSStatType_t)dword_104D9ED4[5 * v13],
          iDelta: 1,
          bPlayerOnly: false);
        CCSGameStats::IncrementStat(
          this,
          pPlayer: pCSPlayer,
          statId: (CSStatType_t)dword_104D9ED8[v15],
          iDelta: (int)info->m_flDamage,
          bPlayerOnly: false);
        v12 = weaponId;
LABEL_17:
        v16 = v9[351] + 2 * v12;
        ++this->m_weaponStats[0][v16].hits;
        this->m_weaponStats[0][v16].damage = (int)(float)((float)this->m_weaponStats[0][v16].damage + info->m_flDamage);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279950
// Name: public: virtual void CCSGameStats::Event_PlayerKilled(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerKilled(CCSGameStats *this, CBasePlayer *pPlayer, const CTakeDamageInfo *info)
{
  CCSPlayer *v4; // eax

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
  {
    v4 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pPlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    CCSGameStats::IncrementStat(this, pPlayer: v4, statId: CSSTAT_DEATHS, iDelta: 1, bPlayerOnly: false);
  }
  else
  {
    CCSGameStats::IncrementStat(this, pPlayer: nullptr, statId: CSSTAT_DEATHS, iDelta: 1, bPlayerOnly: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102799B0
// Name: public: virtual void CCSGameStats::Event_PlayerKilled_PreWeaponDrop(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerKilled_PreWeaponDrop(
        CCSGameStats *this,
        CCSPlayer *pPlayer,
        CWeaponCSBase *info)
{
  CCSPlayer *v3; // edi
  unsigned int v4; // eax
  CEntInfo *v5; // ecx
  IHandleEntity *m_pEntity; // esi
  CCSPlayer *v7; // esi
  int FOV; // ebx
  unsigned int v9; // eax
  IHandleEntity *v10; // ecx
  int TeamNumber; // ebx
  CWeaponCSBase *ActiveCSWeapon; // ebx
  CWeaponCSBase *v13; // eax
  int v14; // edi
  int v15; // ebx
  CCSPlayer *pCSPlayer; // [esp+18h] [ebp+8h]
  CWeaponCSBase *attackerWeapon; // [esp+1Ch] [ebp+Ch]

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
  {
    v3 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pPlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    pCSPlayer = v3;
  }
  else
  {
    pCSPlayer = nullptr;
    v3 = nullptr;
  }
  v4 = LODWORD(info->m_Network.m_PVSInfo.m_vCenter[0]);
  if ( v4 != -1
    && (v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4))
    && (m_pEntity = v5->m_pEntity, v5->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v5->m_pEntity) != 0 )
  {
    v7 = (CCSPlayer *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  }
  else
  {
    v7 = nullptr;
  }
  FOV = CBasePlayer::GetFOV(this: v3);
  if ( FOV != CBasePlayer::GetDefaultFOV(this: v3) )
    CCSGameStats::IncrementStat(
      this,
      pPlayer: v7,
      statId: CSSTAT_KILLS_AGAINST_ZOOMED_SNIPER,
      iDelta: 1,
      bPlayerOnly: false);
  if ( v7 != nullptr && v3 != nullptr )
  {
    v9 = *(_DWORD *)&info->m_Network.m_PVSInfo.m_nAreaNum;
    if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
      v10 = nullptr;
    else
      v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
    if ( v7 == v10 )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: v7);
      if ( TeamNumber != CBaseEntity::GetTeamNumber(this: v3) )
      {
        ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: v7);
        attackerWeapon = ActiveCSWeapon;
        v13 = CCSPlayer::GetActiveCSWeapon(this: v3);
        v14 = v13->GetCSWeaponID(this: v13);
        if ( v14 == 31 && v7 == pCSPlayer )
          CBaseMultiplayerPlayer::AwardAchievement(this: pCSPlayer, iAchievement: 3046, iCount: 1);
        if ( ActiveCSWeapon != nullptr )
        {
          v15 = ActiveCSWeapon->GetCSWeaponID(this: ActiveCSWeapon);
          if ( v15 == 31 && v14 == 31 )
            CCSGameStats::IncrementStat(
              this,
              pPlayer: v7,
              statId: CSSTAT_KILLS_KNIFE_FIGHT,
              iDelta: 1,
              bPlayerOnly: false);
          if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
          {
            if ( v15 == 31
              && CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules)
              && !CCSPlayer::HasPrimaryWeapon(this: v7)
              && !CCSPlayer::HasSecondaryWeapon(this: v7)
              && CCSPlayer::PlacedBombThisRound(this: pCSPlayer) )
            {
              v7->m_knifeKillBombPlacer = true;
            }
            if ( v14 == 31
              && !CCSPlayer::HasPrimaryWeapon(this: pCSPlayer)
              && !CCSPlayer::HasSecondaryWeapon(this: pCSPlayer) )
            {
              CBaseMultiplayerPlayer::AwardAchievement(this: v7, iAchievement: 3044, iCount: 1);
              if ( v15 == 31 )
                CBaseMultiplayerPlayer::AwardAchievement(this: v7, iAchievement: 3047, iCount: 1);
              if ( CWeaponCSBase::GetCSWpnData(this: attackerWeapon)->m_WeaponType == WEAPONTYPE_SUBMACHINEGUN )
                CBaseMultiplayerPlayer::AwardAchievement(this: v7, iAchievement: 3048, iCount: 1);
            }
            if ( v15 == 31
              && (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0
              && !CCSPlayer::HasPrimaryWeapon(this: v7)
              && !CCSPlayer::HasSecondaryWeapon(this: v7) )
            {
              CBaseMultiplayerPlayer::AwardAchievement(this: v7, iAchievement: 3045, iCount: 1);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10279C40
// Name: public: void CCSGameStats::Event_BombPlanted(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_BombPlanted(CCSGameStats *this, CCSPlayer *pPlayer)
{
  CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_NUM_BOMBS_PLANTED, iDelta: 1, bPlayerOnly: false);
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_TR_NUM_BOMBS_PLANTED, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10279C80
// Name: public: void CCSGameStats::Event_BombDefused(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_BombDefused(CCSGameStats *this, CCSPlayer *pPlayer)
{
  CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_NUM_BOMBS_DEFUSED, iDelta: 1, bPlayerOnly: false);
  CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_OBJECTIVES_COMPLETED, iDelta: 1, bPlayerOnly: false);
  if ( pPlayer != nullptr && CCSPlayer::HasDefuser(this: pPlayer) )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_BOMBS_DEFUSED_WITHKIT, iDelta: 1, bPlayerOnly: false);
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_TR_NUM_BOMBS_DEFUSED, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10279CF0
// Name: public: void CCSGameStats::Event_BombExploded(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_BombExploded(CCSGameStats *this, CCSPlayer *pPlayer)
{
  CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_OBJECTIVES_COMPLETED, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10279D10
// Name: public: void CCSGameStats::Event_HostageRescued(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_HostageRescued(CCSGameStats *this, CCSPlayer *pPlayer)
{
  CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_NUM_HOSTAGES_RESCUED, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10279D30
// Name: public: virtual void CCSGameStats::Event_WindowShattered(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_WindowShattered(CCSGameStats *this, CBasePlayer *pPlayer)
{
  CCSPlayer *v3; // eax

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
    v3 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pPlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  else
    v3 = nullptr;
  CCSGameStats::IncrementStat(this, pPlayer: v3, statId: CSSTAT_NUM_BROKEN_WINDOWS, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10279D80
// Name: public: virtual void CCSGameStats::Event_PlayerKilledOther(class CBasePlayer __near *,class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerKilledOther(
        CCSGameStats *this,
        CBasePlayer *pAttacker,
        CBaseEntity *pVictim,
        const CTakeDamageInfo *info)
{
  bool (__thiscall *IsPlayer)(CBaseEntity *); // edx
  unsigned int m_Index; // eax
  CCSPlayer *v7; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v9; // edi
  CCSWeaponInfo *WeaponInfo; // eax
  CCSGameStats *v11; // edi
  const char *pszValue; // eax
  const char *v13; // eax
  const char *v14; // eax
  int v15; // eax
  int v16; // ecx
  CCSPlayer *v17; // ebx
  edict_t *m_pPev; // eax
  int TeamNumber; // eax
  CCSGameRules::TeamPlayerCounts playerCounts[4]; // [esp+4h] [ebp-70h] BYREF
  CSWeaponMode weaponMode; // [esp+64h] [ebp-10h]
  CCSPlayer *pPlayerVictim; // [esp+68h] [ebp-Ch]
  CBasePlayer *m_pEntity; // [esp+6Ch] [ebp-8h]
  CCSGameStats *v24; // [esp+70h] [ebp-4h]
  CTeam *weaponIda; // [esp+7Ch] [ebp+8h]
  CSWeaponID weaponId; // [esp+7Ch] [ebp+8h]

  IsPlayer = pVictim->IsPlayer;
  v24 = this;
  if ( !IsPlayer(this: pVictim) )
    return;
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v7 = pAttacker != nullptr && pAttacker->IsPlayer(this: pAttacker)
     ? (CCSPlayer *)__RTDynamicCast(
                      inptr: pAttacker,
                      VfDelta: 0,
                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0)
     : nullptr;
  pPlayerVictim = pVictim->IsPlayer(this: pVictim)
                ? (CCSPlayer *)__RTDynamicCast(
                                 inptr: pVictim,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                                 isReference: 0)
                : nullptr;
  CCSGameStats::TrackKillStats(this: v24, pAttacker: v7, pVictim: pPlayerVictim);
  weaponIda = CBaseEntity::GetTeam(this: v7);
  if ( weaponIda == CBaseEntity::GetTeam(this: pVictim) )
    return;
  weaponId = WEAPON_NONE;
  weaponMode = Primary_Mode;
  if ( m_pEntity != nullptr )
  {
    if ( m_pEntity == pAttacker )
    {
      if ( CBaseCombatCharacter::GetActiveWeapon(this: pAttacker) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pAttacker);
        v9 = ActiveWeapon;
        if ( ActiveWeapon != nullptr )
        {
          weaponId = ((int (__thiscall *)(CBaseCombatWeapon *))ActiveWeapon->__vftable[1].GetModelName)(a1: ActiveWeapon);
          weaponMode = (CSWeaponMode)v9[1].__vftable;
          WeaponInfo = GetWeaponInfo(weaponID: weaponId);
          if ( WeaponInfo != nullptr
            && WeaponInfo->m_iTeam != 0
            && CBaseEntity::GetTeamNumber(this: pAttacker) != WeaponInfo->m_iTeam )
          {
            v11 = v24;
            CCSGameStats::IncrementStat(
              this: v24,
              pPlayer: v7,
              statId: CSSTAT_KILLS_ENEMY_WEAPON,
              iDelta: 1,
              bPlayerOnly: false);
            goto LABEL_35;
          }
        }
      }
    }
    else
    {
      pszValue = m_pEntity->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( _V_strcmp(s1: pszValue, s2: "hegrenade_projectile") == 0 )
        weaponId = WEAPON_HEGRENADE;
      v13 = m_pEntity->m_iClassname.pszValue;
      if ( v13 == nullptr )
        v13 = locale;
      if ( _V_strcmp(s1: v13, s2: "molotov_projectile") == 0 )
        weaponId = WEAPON_MOLOTOV;
      v14 = m_pEntity->m_iClassname.pszValue;
      if ( v14 == nullptr )
        v14 = locale;
      if ( _V_strcmp(s1: v14, s2: "decoy_projectile") == 0 )
        weaponId = WEAPON_DECOY;
    }
  }
  v11 = v24;
LABEL_35:
  ++v11->m_weaponStats[weaponId][weaponMode].kills;
  v15 = 0;
  v16 = 0;
  while ( WeaponName_StatId_Table[v16].weaponId != weaponId )
  {
    v16 = ++v15;
    if ( *((_DWORD *)&statId + 5 * v15) == -1 )
      goto LABEL_40;
  }
  CCSGameStats::IncrementStat(this: v11, pPlayer: v7, statId: *(&statId + 5 * v15), iDelta: 1, bPlayerOnly: false);
LABEL_40:
  v17 = pPlayerVictim;
  if ( pPlayerVictim != nullptr )
  {
    if ( pPlayerVictim->m_blindUntilTime > gpGlobals->curtime )
      CCSGameStats::IncrementStat(
        this: v11,
        pPlayer: v7,
        statId: CSSTAT_KILLS_ENEMY_BLINDED,
        iDelta: 1,
        bPlayerOnly: false);
    if ( v7 != nullptr )
    {
      if ( (float)(v7->m_flFlashDuration.m_Value + v7->m_blindStartTime) > gpGlobals->curtime )
        CCSGameStats::IncrementStat(
          this: v11,
          pPlayer: v7,
          statId: CSSTAT_KILLS_WHILE_BLINDED,
          iDelta: 1,
          bPlayerOnly: false);
      if ( CBaseEntity::GetTeamNumber(this: v7) == 2
        && LOBYTE(g_pGameRules[144].m_pNext) != 0
        && (CCSPlayer::IsCloseToActiveBomb(this: v7) != 0 || CCSPlayer::IsCloseToActiveBomb(this: pPlayerVictim) != 0) )
      {
        CCSGameStats::IncrementStat(
          this: v11,
          pPlayer: v7,
          statId: CSSTAT_KILLS_WHILE_DEFENDING_BOMB,
          iDelta: 1,
          bPlayerOnly: false);
      }
    }
  }
  if ( (info->m_bitsDamageType & 0x40000000) != 0 )
    CCSGameStats::IncrementStat(this: v11, pPlayer: v7, statId: CSSTAT_KILLS_HEADSHOT, iDelta: 1, bPlayerOnly: false);
  CCSGameStats::IncrementStat(this: v11, pPlayer: v7, statId: CSSTAT_KILLS, iDelta: 1, bPlayerOnly: false);
  m_pPev = pVictim->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( v11->m_aPlayerStats[(_DWORD)m_pPev].statsCurrentRound.m_iValue[2] >= 10 )
    CBaseMultiplayerPlayer::AwardAchievement(this: v7, iAchievement: 5032, iCount: 1);
  CCSGameRules::GetPlayerCounts(this: (CCSGameRules *)g_pGameRules, teamCounts: playerCounts);
  TeamNumber = CBaseEntity::GetTeamNumber(this: v7);
  if ( playerCounts[TeamNumber].totalAlivePlayers == 1 && playerCounts[TeamNumber].killedPlayers >= 2 )
    CCSGameStats::IncrementStat(
      this: v11,
      pPlayer: v7,
      statId: CSSTAT_KILLS_WHILE_LAST_PLAYER_ALIVE,
      iDelta: 1,
      bPlayerOnly: false);
  if ( CCSPlayer::GetNumEnemyDamagers(this: v17) > 1 )
    CCSGameStats::IncrementStat(
      this: v11,
      pPlayer: v7,
      statId: CSSTAT_KILLS_ENEMY_WOUNDED,
      iDelta: 1,
      bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027A140
// Name: public: void CCSGameStats::CalculateOverkill(class CCSPlayer __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::CalculateOverkill(CCSGameStats *this, CCSPlayer *pAttacker, CCSPlayer *pVictim)
{
  CTeam *Team; // ebx
  edict_t *m_pPev; // eax

  Team = CBaseEntity::GetTeam(this: pAttacker);
  if ( Team != CBaseEntity::GetTeam(this: pVictim) )
  {
    m_pPev = pVictim->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    if ( CCSPlayer::IsPlayerDominated(this: pAttacker, iPlayerIndex: (int)m_pPev) )
      CCSGameStats::IncrementStat(
        this,
        pPlayer: pAttacker,
        statId: CSSTAT_DOMINATION_OVERKILLS,
        iDelta: 1,
        bPlayerOnly: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A1A0
// Name: public: void CCSGameStats::Event_MoneyEarned(class CCSPlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_MoneyEarned(CCSGameStats *this, CCSPlayer *pPlayer, int moneyEarned)
{
  if ( pPlayer != nullptr && moneyEarned > 0 )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_MONEY_EARNED, iDelta: moneyEarned, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027A1C0
// Name: public: void CCSGameStats::Event_MoneySpent(class CCSPlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_MoneySpent(CCSGameStats *this, CCSPlayer *pPlayer, int moneySpent)
{
  if ( pPlayer != nullptr && moneySpent > 0 )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_MONEY_SPENT, iDelta: moneySpent, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027A1F0
// Name: public: void CCSGameStats::Event_PlayerDonatedWeapon(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerDonatedWeapon(CCSGameStats *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_WEAPONS_DONATED, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027A210
// Name: public: void CCSGameStats::Event_MVPEarned(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_MVPEarned(CCSGameStats *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
    CCSGameStats::IncrementStat(this, pPlayer, statId: CSSTAT_MVPS, iDelta: 1, bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1027A230
// Name: public: void CCSGameStats::ResetPlayerStats(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::ResetPlayerStats(CCSGameStats *this, CBasePlayer *pPlayer)
{
  edict_t *m_pPev; // eax

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  PlayerStats_t::Reset(this: &this->m_aPlayerStats[(_DWORD)m_pPev]);
  CCSGameStats::ResetKillHistory(this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1027A270
// Name: protected: void CCSGameStats::SendStatsToPlayer(class CCSPlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::SendStatsToPlayer(CCSGameStats *this, CCSPlayer *pPlayer, int iMinStatPriority)
{
  edict_t *m_pPev; // eax
  signed int v4; // edi
  PlayerStats_t *v5; // esi
  char v6; // dl
  unsigned int *p_flags; // eax
  PlayerStats_t *v8; // ecx
  CCSPlayer *v9; // ebx
  CCSPlayer *v10; // ecx
  int v11; // eax
  CSingleUserRecipientFilter filter; // [esp+0h] [ebp-30h] BYREF
  int delta; // [esp+20h] [ebp-10h] BYREF
  unsigned int key; // [esp+24h] [ebp-Ch] BYREF
  unsigned int crc; // [esp+28h] [ebp-8h] BYREF
  unsigned __int8 iStatsToSend; // [esp+2Fh] [ebp-1h] BYREF

  if ( pPlayer != nullptr && pPlayer->m_iConnected != PlayerDisconnected )
  {
    m_pPev = pPlayer->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v4 = iMinStatPriority;
    v5 = &this->m_aPlayerStats[(_DWORD)m_pPev];
    v6 = 0;
    iStatsToSend = 0;
    p_flags = &CSStatProperty_Table[1].flags;
    v8 = v5;
    do
    {
      if ( v8->statsDelta.m_iValue[0] != 0 && (int)(*(p_flags - 4) & 0xF) >= iMinStatPriority )
        iStatsToSend = ++v6;
      if ( v8->statsDelta.m_iValue[1] != 0 && (int)(*p_flags & 0xF) >= iMinStatPriority )
        iStatsToSend = ++v6;
      p_flags += 8;
      v8 = (PlayerStats_t *)((char *)v8 + 8);
    }
    while ( (int)p_flags < (int)off_105C8E3C );
    if ( v6 != 0 )
    {
      CRecipientFilter::CRecipientFilter(this: &filter);
      v9 = pPlayer;
      filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      CRecipientFilter::AddRecipient(this: &filter, player: pPlayer);
      CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
      UserMessageBegin(&filter, messagename: "PlayerStatsUpdate");
      CRC32_Init(pulCRC: &crc);
      key = -2099601588;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &key, nBuffer: 4);
      HIBYTE(iMinStatPriority) = 2;
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: (char *)&iMinStatPriority + 3, nBuffer: 1);
      MessageWriteByte(iValue: 2u);
      CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &iStatsToSend, nBuffer: 1);
      MessageWriteByte(iValue: iStatsToSend);
      v10 = nullptr;
      pPlayer = nullptr;
      do
      {
        if ( v5->statsDelta.m_iValue[(__int16)v10] != 0
          && (signed int)(CSStatProperty_Table[(__int16)v10].flags & 0xF) >= v4 )
        {
          CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &pPlayer, nBuffer: 2);
          MessageWriteShort(iValue: (__int16)pPlayer);
          delta = LOWORD(v5->statsDelta.m_iValue[(__int16)pPlayer]);
          CRC32_ProcessBuffer(pulCRC: &crc, pBuffer: &delta, nBuffer: 2);
          MessageWriteShort(iValue: v5->statsDelta.m_iValue[(__int16)pPlayer]);
          v5->statsDelta.m_iValue[(__int16)pPlayer] = 0;
          v10 = pPlayer;
          --iStatsToSend;
        }
        v10 = (CCSPlayer *)((char *)v10 + 1);
        pPlayer = v10;
      }
      while ( (__int16)v10 < 262 );
      v11 = engine->GetPlayerUserId(this: engine, a2: v9->m_Network.m_pPev);
      MessageWriteShort(iValue: v11);
      CRC32_Final(pulCRC: &crc);
      MessageWriteLong(iValue: crc);
      MessageEnd();
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A450
// Name: public: virtual void CCSGameStats::PreClientUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::PreClientUpdate(CCSGameStats *this)
{
  float v1; // xmm1_4
  int v2; // edi
  CCSGameStats *v3; // ebx
  CBasePlayer *v4; // esi
  CCSPlayer *v5; // eax
  int iMinStatPriority; // [esp+0h] [ebp-4h]

  this->m_directPlayerStatAverages.m_fStat[238] = gpGlobals->frametime + this->m_directPlayerStatAverages.m_fStat[238];
  this->m_directPlayerStatAverages.m_fStat[237] = gpGlobals->frametime + this->m_directPlayerStatAverages.m_fStat[237];
  if ( this->m_directPlayerStatAverages.m_fStat[238] > 0.25 )
  {
    v1 = this->m_directPlayerStatAverages.m_fStat[237];
    iMinStatPriority = 3;
    this->m_directPlayerStatAverages.m_fStat[238] = 0.0;
    if ( v1 > 2.5 )
    {
      iMinStatPriority = 2;
      this->m_directPlayerStatAverages.m_fStat[237] = 0.0;
    }
    v2 = 1;
    v3 = (CCSGameStats *)((char *)this - 100);
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v2);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
        v5 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v4,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
      else
        v5 = nullptr;
      CCSGameStats::SendStatsToPlayer(this: v3, pPlayer: v5, iMinStatPriority);
      ++v2;
    }
    while ( v2 <= 64 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A540
// Name: public: void CCSGameStats::CalcDominationAndRevenge(class CCSPlayer __near *,class CCSPlayer __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::CalcDominationAndRevenge(
        CCSGameStats *this,
        CCSPlayer *pAttacker,
        CCSPlayer *pVictim,
        int *piDeathFlags)
{
  CTeam *Team; // esi
  edict_t *m_pPev; // eax
  signed int v6; // eax
  PlayerStats_t *v7; // ecx
  edict_t *v8; // eax
  int v9; // esi
  int v10; // esi
  int v11; // ebx
  CBasePlayer *v12; // eax
  CCSPlayer *v13; // eax
  signed int v14; // eax
  edict_t *v15; // eax
  edict_t *v16; // eax

  if ( (sv_nonemesis.m_pParent == nullptr || sv_nonemesis.m_pParent->m_Value.m_nValue == 0)
    && pAttacker != nullptr
    && pVictim != nullptr )
  {
    Team = CBaseEntity::GetTeam(this: pAttacker);
    if ( Team != CBaseEntity::GetTeam(this: pVictim) )
    {
      m_pPev = pVictim->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v6 = m_pPev - gpGlobals->pEdicts;
      else
        v6 = 0;
      v7 = &this->m_aPlayerStats[v6];
      v8 = pAttacker->m_Network.m_pPev;
      if ( v8 != nullptr )
        v8 -= (int)gpGlobals->pEdicts;
      v9 = v7->statsKills.iNumKilledByUnanswered[(_DWORD)v8] + 1;
      if ( v7->statsKills.iNumKilledByUnanswered[(_DWORD)v8] == 3 )
      {
        *piDeathFlags |= 1u;
        CCSPlayer::SetPlayerDominated(this: pAttacker, pPlayer: pVictim, bDominated: true);
        v10 = 1;
        v11 = 0;
        if ( gpGlobals->maxClients >= 1 )
        {
          do
          {
            v12 = UTIL_PlayerByIndex(playerIndex: v10);
            v13 = ToCSPlayer(pEntity: v12);
            if ( v13 != nullptr )
            {
              v14 = (signed int)v13->m_Network.m_pPev;
              if ( v14 != 0 )
                v14 = (signed int)(v14 - (unsigned int)gpGlobals->pEdicts) >> 4;
              if ( CCSPlayer::IsPlayerDominated(this: pAttacker, iPlayerIndex: v14) )
                ++v11;
            }
            ++v10;
          }
          while ( v10 <= gpGlobals->maxClients );
          if ( v11 >= 3 )
            CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3019, iCount: 1);
        }
        CCSGameStats::IncrementStat(this, pPlayer: pAttacker, statId: CSSTAT_DOMINATIONS, iDelta: 1, bPlayerOnly: false);
      }
      else
      {
        v15 = CBaseEntity::entindex(this: pAttacker);
        if ( CCSPlayer::IsPlayerDominated(this: pVictim, iPlayerIndex: (int)v15) )
          *piDeathFlags |= 2u;
        if ( v9 == 8 )
          CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3018, iCount: 1);
        v16 = CBaseEntity::entindex(this: pAttacker);
        if ( CCSPlayer::IsPlayerDominated(this: pVictim, iPlayerIndex: (int)v16) )
        {
          CCSPlayer::SetPlayerDominated(this: pVictim, pPlayer: pAttacker, bDominated: false);
          CCSGameStats::IncrementStat(this, pPlayer: pAttacker, statId: CSSTAT_REVENGES, iDelta: 1, bPlayerOnly: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A6D0
// Name: public: void CCSGameStats::Event_PlayerAvengedTeammate(class CCSPlayer __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerAvengedTeammate(
        CCSGameStats *this,
        CCSPlayer *pAttacker,
        CCSPlayer *pAvengedPlayer)
{
  IGameEvent *v3; // esi
  int v4; // eax
  int v5; // eax

  if ( pAttacker != nullptr && pAvengedPlayer != nullptr )
  {
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_avenged_teammate", a3: 0, a4: 0);
    if ( v3 != nullptr )
    {
      v4 = engine->GetPlayerUserId(this: engine, a2: pAttacker->m_Network.m_pPev);
      v3->SetInt(this: v3, a2: "avenger_id", a3: v4);
      v5 = engine->GetPlayerUserId(this: engine, a2: pAvengedPlayer->m_Network.m_pPev);
      v3->SetInt(this: v3, a2: "avenged_player_id", a3: v5);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027A760
// Name: public: virtual void CCSGameStats::SubmitGameStats(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::SubmitGameStats(CCSGameStats *this, KeyValues *pKV)
{
  int m_Size; // edi
  int i; // esi

  m_Size = CCSGameStats::s_StatLists->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    CCSGameStats::s_StatLists->m_Memory.m_pMemory[i]->SendData(
      this: CCSGameStats::s_StatLists->m_Memory.m_pMemory[i],
      a2: pKV);
    CCSGameStats::s_StatLists->m_Memory.m_pMemory[i]->Clear(this: CCSGameStats::s_StatLists->m_Memory.m_pMemory[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AD10
// Name: public: void CCSGameStats::UpdatePlayerRoundStats(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::UpdatePlayerRoundStats(CCSGameStats *this, int winner)
{
  const char *pszValue; // eax
  int CSLevelIndex; // eax
  int v5; // eax
  unsigned int v6; // esi
  int v7; // ebx
  CBasePlayer *v8; // eax
  CBasePlayer *v9; // esi
  CCSPlayer *v10; // eax
  CCSPlayer *v11; // esi
  bool IsPlayingGunGameProgressive; // al
  float m_iRoundScore; // xmm0_4
  double RoundElapsedTime; // st7
  CBasePlayer *v15; // eax
  CBasePlayer *v16; // esi
  CCSPlayer *v17; // eax
  int iPlayerIndex; // [esp+Ch] [ebp-Ch]
  CSStatType_t mapStatRoundIndex; // [esp+10h] [ebp-8h]
  CSStatType_t mapStatWinIndex; // [esp+14h] [ebp-4h]

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CSLevelIndex = GetCSLevelIndex(pLevelName: pszValue);
  mapStatWinIndex = CSSTAT_UNDEFINED;
  mapStatRoundIndex = CSSTAT_UNDEFINED;
  if ( CSLevelIndex != -1 )
  {
    v5 = 4 * CSLevelIndex;
    mapStatWinIndex = dword_104D9D3C[v5];
    mapStatRoundIndex = dword_104D9D40[v5];
  }
  v6 = winner - 2;
  v7 = 1;
  if ( (unsigned int)(winner - 2) <= 1 )
    ++this->m_aTeamStats[v6].m_iValue[10];
  if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( v6 <= 1 )
      ++this->m_aTeamStats[v6].m_iValue[15];
    ++this->m_aTeamStats[0].m_iValue[16];
    ++this->m_aTeamStats[1].m_iValue[16];
  }
  if ( mapStatWinIndex != CSSTAT_UNDEFINED && v6 <= 1 )
    ++this->m_aTeamStats[v6].m_iValue[mapStatWinIndex];
  if ( (unsigned __int8)CCSGameRules::IsPistolRound(this: (CCSGameRules *)g_pGameRules) != 0 && v6 <= 1 )
    ++this->m_aTeamStats[v6].m_iValue[14];
  ++this->m_aTeamStats[0].m_iValue[13];
  ++this->m_aTeamStats[1].m_iValue[13];
  if ( mapStatRoundIndex != CSSTAT_UNDEFINED )
  {
    ++this->m_aTeamStats[0].m_iValue[mapStatRoundIndex];
    ++this->m_aTeamStats[1].m_iValue[mapStatRoundIndex];
  }
  for ( iPlayerIndex = 1; iPlayerIndex <= 64; ++iPlayerIndex )
  {
    v8 = UTIL_PlayerByIndex(playerIndex: iPlayerIndex);
    v9 = v8;
    if ( v8 != nullptr && v8->IsPlayer(this: v8) )
    {
      v10 = (CCSPlayer *)__RTDynamicCast(
                           inptr: v9,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      v11 = v10;
      if ( v10 != nullptr && v10->m_iConnected != PlayerDisconnected )
      {
        CCSGameStats::IncrementStat(this, pPlayer: v10, statId: CSSTAT_ROUNDS_PLAYED, iDelta: 1, bPlayerOnly: false);
        if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
          CCSGameStats::IncrementStat(
            this,
            pPlayer: v11,
            statId: CSTAT_GUNGAME_ROUNDS_PLAYED,
            iDelta: 1,
            bPlayerOnly: false);
        IsPlayingGunGameProgressive = CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules);
        m_iRoundScore = (float)v11->m_iRoundScore;
        if ( IsPlayingGunGameProgressive )
        {
          if ( m_iRoundScore <= 0.0 )
            m_iRoundScore = 0.0;
          CCSGameStats::IncrementStat(
            this,
            pPlayer: v11,
            statId: CSSTAT_GG_PROGRESSIVE_CONTRIBUTION_SCORE,
            iDelta: (int)m_iRoundScore,
            bPlayerOnly: false);
        }
        else
        {
          if ( m_iRoundScore <= 0.0 )
            m_iRoundScore = 0.0;
          CCSGameStats::IncrementStat(
            this,
            pPlayer: v11,
            statId: CSSTAT_CONTRIBUTION_SCORE,
            iDelta: (int)m_iRoundScore,
            bPlayerOnly: false);
        }
        v11->m_iRoundScore = 0;
        v11->m_iRoundProximityScore = 0;
        if ( winner == 3 )
        {
          CCSGameStats::IncrementStat(this, pPlayer: v11, statId: CSSTAT_CT_ROUNDS_WON, iDelta: 1, bPlayerOnly: true);
        }
        else
        {
          if ( winner != 2 )
            continue;
          CCSGameStats::IncrementStat(this, pPlayer: v11, statId: CSSTAT_T_ROUNDS_WON, iDelta: 1, bPlayerOnly: true);
        }
        if ( CBaseEntity::GetTeamNumber(this: v11) == winner )
        {
          CCSGameStats::IncrementStat(this, pPlayer: v11, statId: CSSTAT_ROUNDS_WON, iDelta: 1, bPlayerOnly: true);
          if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
            CCSGameStats::IncrementStat(
              this,
              pPlayer: v11,
              statId: CSTAT_GUNGAME_ROUNDS_WON,
              iDelta: 1,
              bPlayerOnly: true);
          if ( (unsigned __int8)CCSGameRules::IsPistolRound(this: (CCSGameRules *)g_pGameRules) != 0 )
            CCSGameStats::IncrementStat(
              this,
              pPlayer: v11,
              statId: CSSTAT_PISTOLROUNDS_WON,
              iDelta: 1,
              bPlayerOnly: true);
          if ( mapStatWinIndex == CSSTAT_UNDEFINED )
            goto LABEL_46;
          CCSGameStats::IncrementStat(this, pPlayer: v11, statId: mapStatWinIndex, iDelta: 1, bPlayerOnly: true);
        }
        if ( mapStatWinIndex != CSSTAT_UNDEFINED )
          CCSGameStats::IncrementStat(this, pPlayer: v11, statId: mapStatRoundIndex, iDelta: 1, bPlayerOnly: true);
LABEL_46:
        RoundElapsedTime = CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules);
        CCSGameStats::IncrementStat(
          this,
          pPlayer: v11,
          statId: CSSTAT_PLAYTIME,
          iDelta: (int)RoundElapsedTime,
          bPlayerOnly: true);
        continue;
      }
    }
  }
  do
  {
    v15 = UTIL_PlayerByIndex(playerIndex: v7);
    v16 = v15;
    if ( v15 != nullptr && v15->IsPlayer(this: v15) )
    {
      v17 = (CCSPlayer *)__RTDynamicCast(
                           inptr: v16,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      if ( v17 != nullptr && v17->m_iConnected != PlayerDisconnected )
        CCSGameStats::SendStatsToPlayer(this, pPlayer: v17, iMinStatPriority: 1);
    }
    ++v7;
  }
  while ( v7 <= 64 );
}

//------------------------------------------------------------------------------
// Address: 0x1027B020
// Name: public: virtual void CCSGameStats::Event_PlayerConnected(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerConnected(CCSGameStats *this, CBasePlayer *pPlayer)
{
  CBasePlayer *v3; // esi
  signed int m_pPev; // eax

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
    v3 = (CBasePlayer *)__RTDynamicCast(
                          inptr: pPlayer,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
  else
    v3 = nullptr;
  m_pPev = (signed int)v3->m_Network.m_pPev;
  if ( m_pPev != 0 )
    m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
  PlayerStats_t::Reset(this: &this->m_aPlayerStats[m_pPev]);
  CCSGameStats::ResetKillHistory(this, pPlayer: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1027B090
// Name: public: virtual void CCSGameStats::Event_PlayerDisconnected(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerDisconnected(CCSGameStats *this, CBasePlayer *pPlayer)
{
  void *v3; // eax
  CBasePlayer *v4; // esi
  signed int v5; // eax

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
  {
    v3 = __RTDynamicCast(
           inptr: pPlayer,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CCSPlayer `RTTI Type Descriptor',
           isReference: 0);
    v4 = (CBasePlayer *)v3;
    if ( v3 != nullptr )
    {
      v5 = *((_DWORD *)v3 + 6);
      if ( v5 != 0 )
        v5 = (signed int)(v5 - (unsigned int)gpGlobals->pEdicts) >> 4;
      PlayerStats_t::Reset(this: &this->m_aPlayerStats[v5]);
      CCSGameStats::ResetKillHistory(this, pPlayer: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BB60
// Name: public: virtual void IGameStatTracker::CGameStatList<struct SWeaponHitData>::SendData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameStatTracker::CGameStatList<SWeaponHitData>::SendData(
        IGameStatTracker::CGameStatList<SWeaponHitData> *this,
        KeyValues *pKV)
{
  IGameStatTracker::CGameStatList<SWeaponHitData> *v2; // esi
  int v3; // ebx
  KeyValues *Copy; // edi
  KeyValues *v5; // eax
  SWeaponHitData *v6; // esi
  const char *v7; // eax
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax

  v2 = this;
  v3 = 0;
  if ( this->m_Size <= 0 )
  {
    UniqueStatID_t<SWeaponHitData>::s_nLastID = 0;
  }
  else
  {
    while ( 1 )
    {
      if ( v2->m_Memory.m_pMemory[v3]->m_bUseGlobalData )
      {
        Copy = KeyValues::MakeCopy(this: pKV);
      }
      else
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        Copy = v5 != nullptr ? KeyValues::KeyValues(this: v5, setName: locale) : nullptr;
      }
      v6 = v2->m_Memory.m_pMemory[v3];
      KeyValues::SetName(this: Copy, setName: "CSGOWeaponHitData");
      AddDataToKV(pKV: Copy, name: "WeaponID", data: v6->m_ui8WeaponID);
      AddDataToKV(pKV: Copy, name: "BulletID", data: v6->m_uiBulletID);
      AddDataToKV(pKV: Copy, name: "AttackerID", data: v6->m_ui64AttackerID);
      AddDataToKV(pKV: Copy, name: "AttackerX", data: (int)v6->m_vAttackerPos.x);
      AddDataToKV(pKV: Copy, name: "AttackerY", data: (int)v6->m_vAttackerPos.y);
      AddDataToKV(pKV: Copy, name: "AttackerZ", data: (int)v6->m_vAttackerPos.z);
      AddDataToKV(pKV: Copy, name: "TargetID", data: v6->m_ui64TargertID);
      AddDataToKV(pKV: Copy, name: "TargetX", data: (int)v6->m_vTargetPos.x);
      AddDataToKV(pKV: Copy, name: "TargetY", data: (int)v6->m_vTargetPos.y);
      AddDataToKV(pKV: Copy, name: "TargetZ", data: (int)v6->m_vTargetPos.z);
      AddDataToKV(pKV: Copy, name: "Health", data: v6->m_ui8Health);
      AddDataToKV(pKV: Copy, name: "Damage", data: v6->m_uiDamage);
      AddDataToKV(pKV: Copy, name: "HitRegion", data: v6->m_HitRegion);
      AddDataToKV(pKV: Copy, name: "Round", data: v6->m_RoundID);
      v7 = "TimeSubmitted";
      if ( !v6->m_bUseGlobalData )
        v7 = "SessionTime";
      KeyValues::SetUint64(this: Copy, keyName: v7, value: v6->TimeSubmitted);
      SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
      CSteamWorksGameStatsUploader::AddStatsForUpload(
        this: SteamWorksSGameStatsUploader,
        pKV: Copy,
        bSendImmediately: true);
      if ( ++v3 >= this->m_Size )
        break;
      v2 = this;
    }
    UniqueStatID_t<SWeaponHitData>::s_nLastID = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BD20
// Name: public: virtual void IGameStatTracker::CGameStatList<struct SWeaponHitData>::PrintMemoryUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameStatTracker::CGameStatList<SWeaponHitData>::PrintMemoryUsage(
        IGameStatTracker::CGameStatList<SWeaponHitData> *this)
{
  int m_Size; // eax
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+0h] [ebp-10Ch] BYREF

  m_Size = this->m_Size;
  if ( m_Size != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(
           this: &v3,
           pszFormat: "\t%d\tbytes used by %s table\n",
           72 * m_Size,
           "CSGOWeaponHitData");
    _Msg(a1: v2->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BD70
// Name: public: virtual void IGameStatTracker::CGameStatList<struct SWeaponMissData>::SendData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameStatTracker::CGameStatList<SWeaponMissData>::SendData(
        IGameStatTracker::CGameStatList<SWeaponMissData> *this,
        KeyValues *pKV)
{
  IGameStatTracker::CGameStatList<SWeaponMissData> *v2; // esi
  int v3; // ebx
  KeyValues *Copy; // edi
  KeyValues *v5; // eax
  SWeaponMissData *v6; // esi
  const char *v7; // eax
  CSteamWorksGameStatsUploader *SteamWorksSGameStatsUploader; // eax

  v2 = this;
  v3 = 0;
  if ( this->m_Size <= 0 )
  {
    UniqueStatID_t<SWeaponMissData>::s_nLastID = 0;
  }
  else
  {
    while ( 1 )
    {
      if ( v2->m_Memory.m_pMemory[v3]->m_bUseGlobalData )
      {
        Copy = KeyValues::MakeCopy(this: pKV);
      }
      else
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        Copy = v5 != nullptr ? KeyValues::KeyValues(this: v5, setName: locale) : nullptr;
      }
      v6 = v2->m_Memory.m_pMemory[v3];
      KeyValues::SetName(this: Copy, setName: "CSGOWeaponMissData");
      AddDataToKV(pKV: Copy, name: "WeaponID", data: v6->m_ui8WeaponID);
      AddDataToKV(pKV: Copy, name: "BulletID", data: v6->m_uiBulletID);
      AddDataToKV(pKV: Copy, name: "AttackerID", data: v6->m_ui64AttackerID);
      AddDataToKV(pKV: Copy, name: "AttackerX", data: (int)v6->m_vAttackerPos.x);
      AddDataToKV(pKV: Copy, name: "AttackerY", data: (int)v6->m_vAttackerPos.y);
      AddDataToKV(pKV: Copy, name: "AttackerZ", data: (int)v6->m_vAttackerPos.z);
      AddDataToKV(pKV: Copy, name: "Round", data: v6->m_RoundID);
      v7 = "TimeSubmitted";
      if ( !v6->m_bUseGlobalData )
        v7 = "SessionTime";
      KeyValues::SetUint64(this: Copy, keyName: v7, value: v6->TimeSubmitted);
      SteamWorksSGameStatsUploader = GetSteamWorksSGameStatsUploader();
      CSteamWorksGameStatsUploader::AddStatsForUpload(
        this: SteamWorksSGameStatsUploader,
        pKV: Copy,
        bSendImmediately: true);
      if ( ++v3 >= this->m_Size )
        break;
      v2 = this;
    }
    UniqueStatID_t<SWeaponMissData>::s_nLastID = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BEC0
// Name: public: virtual void IGameStatTracker::CGameStatList<struct SWeaponMissData>::PrintMemoryUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameStatTracker::CGameStatList<SWeaponMissData>::PrintMemoryUsage(
        IGameStatTracker::CGameStatList<SWeaponMissData> *this)
{
  int m_Size; // ecx
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+0h] [ebp-10Ch] BYREF

  m_Size = this->m_Size;
  if ( m_Size != 0 )
  {
    v2 = CFmtStrN<256>::CFmtStrN<256>(
           this: &v3,
           pszFormat: "\t%d\tbytes used by %s table\n",
           56 * m_Size,
           "CSGOWeaponMissData");
    _Msg(a1: v2->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027BF80
// Name: public: virtual void IGameStatTracker::CGameStatList<struct SWeaponHitData>::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IGameStatTracker::CGameStatList<SWeaponHitData>::Clear(
        IGameStatTracker::CGameStatList<SWeaponMissData> *this)
{
  CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->CUtlVector<SWeaponMissData *,CUtlMemory<SWeaponMissData *,int> >);
}

//------------------------------------------------------------------------------
// Address: 0x1027BF90
// Name: public: virtual void CCSGameStats::Event_ShotFired(class CBasePlayer __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_ShotFired(CCSGameStats *this, CBasePlayer *pPlayer, CBaseCombatWeapon *pWeapon)
{
  CCSPlayer *v4; // eax
  CCSPlayer *v5; // edi
  CWeaponCSBase *v6; // edi
  SWeaponShotData *v7; // esi
  SWeaponShotData *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  SWeaponShotData **m_pMemory; // ecx
  int v12; // eax
  SWeaponShotData **v13; // eax
  CSWeaponID v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  CWeaponCSBase *pCSWeapon; // [esp+8h] [ebp-8h]
  CCSPlayer *pCSPlayer; // [esp+Ch] [ebp-4h]
  unsigned __int8 iSubBullet; // [esp+18h] [ebp+8h]
  SWeaponShotData *iSubBulleta; // [esp+18h] [ebp+8h]
  CSWeaponID weaponId; // [esp+1Ch] [ebp+Ch]

  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
  {
    v4 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pPlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    v5 = v4;
    pCSPlayer = v4;
    if ( v4 != nullptr )
    {
      CCSPlayer::PlayerUsedFirearm(this: v4, pBaseWeapon: pWeapon);
      if ( !pWeapon->HasAnyAmmo(this: pWeapon) )
        CCSPlayer::PlayerEmptiedAmmoForFirearm(this: v5, pBaseWeapon: pWeapon);
      CCSGameStats::IncrementStat(this, pPlayer: v5, statId: CSSTAT_SHOTS_FIRED, iDelta: 1, bPlayerOnly: false);
      v6 = (CWeaponCSBase *)__RTDynamicCast(
                              inptr: pWeapon,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
      pCSWeapon = v6;
      if ( v6 != nullptr )
      {
        weaponId = v6->GetCSWeaponID(this: v6);
        iSubBullet = 0;
        if ( this->m_WeaponShotData.m_Size != 0 )
        {
          v7 = this->m_WeaponShotData.m_Memory.m_pMemory[this->m_WeaponShotData.m_Size - 1];
          if ( v7 != nullptr && v7->m_uiBulletID == CCSPlayer::GetBulletGroup() )
            iSubBullet = v7->m_uiSubBulletID + 1;
        }
        v8 = (SWeaponShotData *)operator new(nSize: 0x30u);
        if ( v8 != nullptr )
          iSubBulleta = SWeaponShotData::SWeaponShotData(
                          this: v8,
                          pPlayer: pCSPlayer,
                          pWeapon: v6,
                          subBullet: iSubBullet,
                          round: (unsigned __int8)g_pGameRules[131].__vftable);
        else
          iSubBulleta = nullptr;
        m_Size = this->m_WeaponShotData.m_Size;
        m_nAllocationCount = this->m_WeaponShotData.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponShotData,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_WeaponShotData.m_Size;
        m_pMemory = this->m_WeaponShotData.m_Memory.m_pMemory;
        v12 = this->m_WeaponShotData.m_Size - m_Size - 1;
        this->m_WeaponShotData.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = &this->m_WeaponShotData.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = iSubBulleta;
        v14 = WEAPON_DEAGLE;
        v15 = 0;
        v16 = 0;
        while ( v14 != weaponId || *(const CSStatType_t *)((char *)&dword_104D9ED0 + v16) == CSSTAT_UNDEFINED )
        {
          v14 = WeaponName_StatId_Table[++v15].weaponId;
          v16 = 20 * v15;
          if ( v14 == WEAPON_NONE )
            goto LABEL_26;
        }
        CCSGameStats::IncrementStat(
          this,
          pPlayer: pCSPlayer,
          statId: *(&dword_104D9ED0 + 5 * v15),
          iDelta: 1,
          bPlayerOnly: false);
LABEL_26:
        v17 = pCSWeapon->m_weaponMode.m_Value + 2 * weaponId;
        ++this->m_weaponStats[0][v17].shots;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027C190
// Name: public: virtual void CCSGameStats::Event_PlayerDamage(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::Event_PlayerDamage(
        CCSGameStats *this,
        CBasePlayer *pBasePlayer,
        const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CEntInfo *v5; // ecx
  IHandleEntity *m_pEntity; // esi
  CBaseEntity *v7; // eax
  CCSPlayer *v8; // esi
  CTeam *Team; // ebx
  SWeaponHitData *v10; // esi
  SWeaponHitData *v11; // ebx
  CGameRules *v12; // esi
  CCSPlayer *v13; // eax
  SWeaponHitData *v14; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_WeaponHitData; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v19; // eax
  SWeaponHitData **v20; // eax
  unsigned __int8 iSubBullet; // [esp+Ch] [ebp-4h]

  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1 )
  {
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = v5->m_pEntity;
      if ( v5->m_pEntity != nullptr
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v5->m_pEntity) != 0 )
      {
        v7 = (CBaseEntity *)__RTDynamicCast(
                              inptr: m_pEntity,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CCSPlayer `RTTI Type Descriptor',
                              isReference: 0);
        v8 = (CCSPlayer *)v7;
        if ( v7 != nullptr )
        {
          Team = CBaseEntity::GetTeam(this: v7);
          if ( Team != CBaseEntity::GetTeam(this: pBasePlayer) )
            CCSGameStats::IncrementStat(
              this,
              pPlayer: v8,
              statId: CSSTAT_DAMAGE,
              iDelta: (int)info->m_flDamage,
              bPlayerOnly: false);
        }
      }
    }
  }
  iSubBullet = 0;
  if ( this->m_WeaponHitData.m_Size != 0 )
  {
    v10 = this->m_WeaponHitData.m_Memory.m_pMemory[this->m_WeaponHitData.m_Size - 1];
    if ( v10 != nullptr && v10->m_uiBulletID == CCSPlayer::GetBulletGroup() )
      iSubBullet = v10->m_uiSubBulletID + 1;
  }
  v11 = (SWeaponHitData *)operator new(nSize: 0x48u);
  if ( v11 != nullptr )
  {
    v12 = g_pGameRules;
    if ( pBasePlayer != nullptr && pBasePlayer->IsPlayer(this: pBasePlayer) )
      v13 = (CCSPlayer *)__RTDynamicCast(
                           inptr: pBasePlayer,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
    else
      v13 = nullptr;
    v14 = SWeaponHitData::SWeaponHitData(
            this: v11,
            pCSTarget: v13,
            info,
            subBullet: iSubBullet,
            round: (unsigned __int8)v12[131].__vftable);
  }
  else
  {
    v14 = nullptr;
  }
  m_nAllocationCount = this->m_WeaponHitData.m_Memory.m_nAllocationCount;
  p_m_WeaponHitData = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponHitData;
  m_Size = this->m_WeaponHitData.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(this: p_m_WeaponHitData, num: m_Size - m_nAllocationCount + 1);
  ++p_m_WeaponHitData[1].m_pMemory;
  m_pMemory = p_m_WeaponHitData->m_pMemory;
  v19 = (int)p_m_WeaponHitData[1].m_pMemory - m_Size - 1;
  p_m_WeaponHitData[1].m_nAllocationCount = (int)p_m_WeaponHitData->m_pMemory;
  if ( v19 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v19);
  v20 = (SWeaponHitData **)&p_m_WeaponHitData->m_pMemory[m_Size];
  if ( v20 != nullptr )
    *v20 = v14;
}

//------------------------------------------------------------------------------
// Address: 0x1027C390
// Name: private: class IGameStatTracker::CGameStatList<struct SWeaponHitData> __near * IGameStatTracker::GetStatTable<struct SWeaponHitData>(void)
// Source: json
//------------------------------------------------------------------------------
IGameStatTracker::CGameStatList<SWeaponHitData> *__thiscall IGameStatTracker::GetStatTable<SWeaponHitData>(
        IGameStatTracker *this)
{
  IGameStatTracker::CGameStatList<SWeaponHitData> *result; // eax
  IGameStatTracker::CGameStatList<SWeaponHitData> *v3; // eax
  CUtlMemory<vgui::TreeNode *,int> *v4; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax
  IGameStatTracker::CGameStatList<SWeaponHitData> *v10; // [esp+8h] [ebp-4h]

  result = `IGameStatTracker::GetStatTable<SWeaponHitData>'::`2'::s_vecOfType;
  if ( `IGameStatTracker::GetStatTable<SWeaponHitData>'::`2'::s_vecOfType == nullptr )
  {
    v3 = (IGameStatTracker::CGameStatList<SWeaponHitData> *)operator new(nSize: 0x18u);
    if ( v3 != nullptr )
    {
      v3->m_Memory.m_pMemory = nullptr;
      v3->m_Memory.m_nAllocationCount = 0;
      v3->m_Memory.m_nGrowSize = 0;
      v3->m_Size = 0;
      v3->m_pElements = nullptr;
      v3->__vftable = (IGameStatTracker::CGameStatList<SWeaponHitData>_vtbl *)&IGameStatTracker::CGameStatList<SWeaponHitData>::`vftable';
    }
    else
    {
      v3 = nullptr;
    }
    `IGameStatTracker::GetStatTable<SWeaponHitData>'::`2'::s_vecOfType = v3;
    v10 = v3;
    v4 = (CUtlMemory<vgui::TreeNode *,int> *)this->GetStatContainerList(this);
    m_pMemory = v4[1].m_pMemory;
    m_nAllocationCount = v4->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: v4, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++v4[1].m_pMemory;
    v7 = v4->m_pMemory;
    v8 = (char *)v4[1].m_pMemory - (char *)m_pMemory - 1;
    v4[1].m_nAllocationCount = (int)v4->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[(_DWORD)m_pMemory + 1], src: &v7[(_DWORD)m_pMemory], count: 4 * v8);
    v9 = &v4->m_pMemory[(_DWORD)m_pMemory];
    if ( v9 != nullptr )
      *v9 = (vgui::TreeNode *)v10;
    return `IGameStatTracker::GetStatTable<SWeaponHitData>'::`2'::s_vecOfType;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027C440
// Name: private: class IGameStatTracker::CGameStatList<struct SWeaponMissData> __near * IGameStatTracker::GetStatTable<struct SWeaponMissData>(void)
// Source: json
//------------------------------------------------------------------------------
IGameStatTracker::CGameStatList<SWeaponMissData> *__thiscall IGameStatTracker::GetStatTable<SWeaponMissData>(
        IGameStatTracker *this)
{
  IGameStatTracker::CGameStatList<SWeaponMissData> *result; // eax
  IGameStatTracker::CGameStatList<SWeaponMissData> *v3; // eax
  CUtlMemory<vgui::TreeNode *,int> *v4; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v7; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax
  IGameStatTracker::CGameStatList<SWeaponMissData> *v10; // [esp+8h] [ebp-4h]

  result = `IGameStatTracker::GetStatTable<SWeaponMissData>'::`2'::s_vecOfType;
  if ( `IGameStatTracker::GetStatTable<SWeaponMissData>'::`2'::s_vecOfType == nullptr )
  {
    v3 = (IGameStatTracker::CGameStatList<SWeaponMissData> *)operator new(nSize: 0x18u);
    if ( v3 != nullptr )
    {
      v3->m_Memory.m_pMemory = nullptr;
      v3->m_Memory.m_nAllocationCount = 0;
      v3->m_Memory.m_nGrowSize = 0;
      v3->m_Size = 0;
      v3->m_pElements = nullptr;
      v3->__vftable = (IGameStatTracker::CGameStatList<SWeaponMissData>_vtbl *)&IGameStatTracker::CGameStatList<SWeaponMissData>::`vftable';
    }
    else
    {
      v3 = nullptr;
    }
    `IGameStatTracker::GetStatTable<SWeaponMissData>'::`2'::s_vecOfType = v3;
    v10 = v3;
    v4 = (CUtlMemory<vgui::TreeNode *,int> *)this->GetStatContainerList(this);
    m_pMemory = v4[1].m_pMemory;
    m_nAllocationCount = v4->m_nAllocationCount;
    if ( (int)m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: v4, num: (int)m_pMemory - m_nAllocationCount + 1);
    ++v4[1].m_pMemory;
    v7 = v4->m_pMemory;
    v8 = (char *)v4[1].m_pMemory - (char *)m_pMemory - 1;
    v4[1].m_nAllocationCount = (int)v4->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &v7[(_DWORD)m_pMemory + 1], src: &v7[(_DWORD)m_pMemory], count: 4 * v8);
    v9 = &v4->m_pMemory[(_DWORD)m_pMemory];
    if ( v9 != nullptr )
      *v9 = (vgui::TreeNode *)v10;
    return `IGameStatTracker::GetStatTable<SWeaponMissData>'::`2'::s_vecOfType;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027C4F0
// Name: public: void CUtlDict<enum CSStatType_t,short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<enum CSStatType_t,short>::RemoveAll(CUtlDict<enum CSStatType_t,short> *this)
{
  __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1027C5C0
// Name: public: void CCSGameStats::Event_BreakProp(class CCSPlayer __near *,class CBreakableProp __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSGameStats::Event_BreakProp(
        CCSGameStats *this@<ecx>,
        int a2@<esi>,
        CCSPlayer *pPlayer,
        CBreakableProp *pProp)
{
  CBreakableProp *v4; // esi
  edict_t *m_pPev; // eax
  signed int v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  CCSGameStats *v10; // ebx
  __int16 v11; // ax
  int v12; // esi
  const char *v13; // [esp-Ch] [ebp-1Ch]
  int v15; // [esp-8h] [ebp-18h]
  CUtlMap<char const *,enum CSStatType_t,short>::Node_t search; // [esp+4h] [ebp-Ch] BYREF
  CCSGameStats *v17; // [esp+Ch] [ebp-4h]

  v17 = this;
  if ( pPlayer != nullptr )
  {
    v4 = pProp;
    m_pPev = pProp->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v6 = m_pPev - gpGlobals->pEdicts;
    else
      v6 = 0;
    v7 = *(const char **)((int (__thiscall *)(CBreakableProp *, CBreakableProp **, int))pProp->GetModelName)(
                           a1: pProp,
                           a2: &pProp,
                           a3: a2);
    if ( v7 == nullptr )
      v7 = locale;
    v8 = (const char *)((int (__thiscall *)(CCSPlayer *, const char *, signed int))pPlayer->GetPlayerName)(
                         a1: pPlayer,
                         a2: v7,
                         a3: v6);
    DevMsg(a1: "Player %s broke a %s (%i)\n", v8, v13, v15);
    v9 = *(const char **)((int (__thiscall *)(CBreakableProp *, CBreakableProp **))v4->GetModelName)(a1: v4, a2: &pProp);
    if ( v9 == nullptr )
      v9 = locale;
    v10 = v17;
    search.key = v9;
    v11 = CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::Find(
            this: &v17->m_PropStatTable.m_Elements.m_Tree,
            &search);
    v12 = v11;
    if ( v11 >= 0
      && v11 < v10->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_nAllocationCount
      && v11 <= v10->m_PropStatTable.m_Elements.m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::LeftChild(
           this: &v10->m_PropStatTable.m_Elements.m_Tree,
           i: v11) != v11 )
    {
      CCSGameStats::IncrementStat(
        this: v10,
        pPlayer,
        statId: v10->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem,
        iDelta: 1,
        bPlayerOnly: false);
    }
    CCSGameStats::IncrementStat(this: v10, pPlayer, statId: CSSTAT_PROPSBROKEN_ALL, iDelta: 1, bPlayerOnly: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027C6D0
// Name: public: void CCSGameStats::UploadRoundStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::UploadRoundStats(CCSGameStats *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ecx
  const char *pszValue; // eax
  int v5; // eax
  int m_Size; // edx
  int v7; // ecx
  SWeaponHitData **v8; // eax
  SWeaponMissData *v9; // eax
  int v10; // ebx
  int m_nAllocationCount; // eax
  SWeaponMissData **m_pMemory; // ecx
  int v13; // eax
  SWeaponMissData **v14; // ebx
  int v15; // ecx
  SWeaponHitData *v16; // eax
  IGameStatTracker::CGameStatList<SWeaponHitData> *Stat; // esi
  int v18; // ebx
  int v19; // eax
  SWeaponHitData **v20; // ecx
  int v21; // eax
  SWeaponHitData **v22; // ebx
  int v23; // ecx
  SWeaponMissData *v24; // eax
  IGameStatTracker::CGameStatList<SWeaponMissData> *v25; // esi
  int v26; // ebx
  int v27; // eax
  SWeaponMissData **v28; // ecx
  int v29; // eax
  SWeaponMissData **v30; // ebx
  KeyValues *pKV; // [esp+4h] [ebp-10h]
  SWeaponShotData *v32; // [esp+8h] [ebp-Ch]
  SWeaponHitData *v33; // [esp+8h] [ebp-Ch]
  SWeaponMissData *v34; // [esp+8h] [ebp-Ch]
  SWeaponMissData *v35; // [esp+Ch] [ebp-8h]
  int k; // [esp+10h] [ebp-4h]
  int ka; // [esp+10h] [ebp-4h]
  int kb; // [esp+10h] [ebp-4h]

  if ( this->m_WeaponShotData.m_Size > 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "basedata");
      pKV = v3;
      if ( v3 != nullptr )
      {
        pszValue = gpGlobals->mapname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        KeyValues::SetString(this: v3, keyName: "MapID", value: pszValue);
        v5 = 0;
        for ( k = 0; v5 < this->m_WeaponShotData.m_Size; k = v5 )
        {
          m_Size = this->m_WeaponHitData.m_Size;
          v7 = 0;
          if ( m_Size <= 0 )
          {
LABEL_12:
            v9 = (SWeaponMissData *)operator new(nSize: 0x38u);
            if ( v9 != nullptr )
              v35 = SWeaponMissData::SWeaponMissData(this: v9, data: this->m_WeaponShotData.m_Memory.m_pMemory[k]);
            else
              v35 = nullptr;
            v10 = this->m_WeaponMissData.m_Size;
            m_nAllocationCount = this->m_WeaponMissData.m_Memory.m_nAllocationCount;
            if ( v10 + 1 > m_nAllocationCount )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponMissData,
                num: v10 - m_nAllocationCount + 1);
            ++this->m_WeaponMissData.m_Size;
            m_pMemory = this->m_WeaponMissData.m_Memory.m_pMemory;
            v13 = this->m_WeaponMissData.m_Size - v10 - 1;
            this->m_WeaponMissData.m_pElements = m_pMemory;
            if ( v13 > 0 )
              _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * v13);
            v14 = &this->m_WeaponMissData.m_Memory.m_pMemory[v10];
            if ( v14 != nullptr )
              *v14 = v35;
          }
          else
          {
            v32 = this->m_WeaponShotData.m_Memory.m_pMemory[v5];
            v8 = this->m_WeaponHitData.m_Memory.m_pMemory;
            while ( v32->m_uiBulletID != (*v8)->m_uiBulletID || v32->m_uiSubBulletID != (*v8)->m_uiSubBulletID )
            {
              ++v7;
              ++v8;
              if ( v7 >= m_Size )
                goto LABEL_12;
            }
          }
          v5 = k + 1;
        }
        v15 = 0;
        ka = 0;
        if ( this->m_WeaponHitData.m_Size > 0 )
        {
          while ( 1 )
          {
            v16 = this->m_WeaponHitData.m_Memory.m_pMemory[v15];
            v16->m_uiBulletID = v16->m_uiBulletID & 0xFFFFFFF | (v16->m_uiSubBulletID << 28);
            v33 = this->m_WeaponHitData.m_Memory.m_pMemory[v15];
            Stat = IGameStatTracker::GetStatTable<SWeaponHitData>(this: &this->IGameStatTracker);
            v18 = Stat->m_Size;
            v19 = Stat->m_Memory.m_nAllocationCount;
            if ( v18 + 1 > v19 )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&Stat->CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int> >,
                num: v18 - v19 + 1);
            ++Stat->m_Size;
            v20 = Stat->m_Memory.m_pMemory;
            v21 = Stat->m_Size - v18 - 1;
            Stat->m_pElements = v20;
            if ( v21 > 0 )
              _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 4 * v21);
            v22 = &Stat->m_Memory.m_pMemory[v18];
            if ( v22 != nullptr )
              *v22 = v33;
            if ( ++ka >= this->m_WeaponHitData.m_Size )
              break;
            v15 = ka;
          }
        }
        v23 = 0;
        kb = 0;
        if ( this->m_WeaponMissData.m_Size > 0 )
        {
          while ( 1 )
          {
            v24 = this->m_WeaponMissData.m_Memory.m_pMemory[v23];
            v24->m_uiBulletID = v24->m_uiBulletID & 0xFFFFFFF | (v24->m_uiSubBulletID << 28);
            v34 = this->m_WeaponMissData.m_Memory.m_pMemory[v23];
            v25 = IGameStatTracker::GetStatTable<SWeaponMissData>(this: &this->IGameStatTracker);
            v26 = v25->m_Size;
            v27 = v25->m_Memory.m_nAllocationCount;
            if ( v26 + 1 > v27 )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v25->CUtlVector<SWeaponMissData *,CUtlMemory<SWeaponMissData *,int> >,
                num: v26 - v27 + 1);
            ++v25->m_Size;
            v28 = v25->m_Memory.m_pMemory;
            v29 = v25->m_Size - v26 - 1;
            v25->m_pElements = v28;
            if ( v29 > 0 )
              _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 4 * v29);
            v30 = &v25->m_Memory.m_pMemory[v26];
            if ( v30 != nullptr )
              *v30 = v34;
            if ( ++kb >= this->m_WeaponMissData.m_Size )
              break;
            v23 = kb;
          }
        }
        this->SubmitGameStats(this: &this->IGameStatTracker, a2: pKV);
        this->m_WeaponHitData.m_Size = 0;
        if ( this->m_WeaponHitData.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_WeaponHitData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WeaponHitData.m_Memory.m_pMemory);
            this->m_WeaponHitData.m_Memory.m_pMemory = nullptr;
          }
          this->m_WeaponHitData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_WeaponHitData.m_pElements = this->m_WeaponHitData.m_Memory.m_pMemory;
        this->m_WeaponMissData.m_Size = 0;
        if ( this->m_WeaponMissData.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_WeaponMissData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WeaponMissData.m_Memory.m_pMemory);
            this->m_WeaponMissData.m_Memory.m_pMemory = nullptr;
          }
          this->m_WeaponMissData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_WeaponMissData.m_pElements = this->m_WeaponMissData.m_Memory.m_pMemory;
        this->m_WeaponShotData.m_Size = 0;
        if ( this->m_WeaponShotData.m_Memory.m_nGrowSize >= 0 )
        {
          if ( this->m_WeaponShotData.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WeaponShotData.m_Memory.m_pMemory);
            this->m_WeaponShotData.m_Memory.m_pMemory = nullptr;
          }
          this->m_WeaponShotData.m_Memory.m_nAllocationCount = 0;
        }
        this->m_WeaponShotData.m_pElements = this->m_WeaponShotData.m_Memory.m_pMemory;
        KeyValues::deleteThis(this: pKV);
        CCSPlayer::ResetBulletGroup();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027CA90
// Name: public: virtual void CCSGameStats::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::FireGameEvent(CCSGameStats *this, CBreakableProp *event)
{
  const char *v3; // ebx
  CCSGameStats *v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  CBasePlayer *v8; // esi
  CCSPlayer *v9; // eax
  int v10; // eax
  CBasePlayer *v11; // eax
  CCSPlayer *v12; // eax
  CBreakableProp *pProp; // [esp+14h] [ebp+8h]

  v3 = (const char *)((int (__thiscall *)(CBreakableProp *))event->SetRefEHandle)(a1: event);
  if ( _V_strcmp(s1: v3, s2: "round_end") != 0 )
  {
    if ( _V_strcmp(s1: v3, s2: "break_prop") != 0 )
    {
      if ( _V_strcmp(s1: v3, s2: "player_decal") == 0 || _V_strcmp(s1: v3, s2: "cs_win_panel_match") == 0 )
      {
        v10 = ((int (__thiscall *)(CBreakableProp *, const char *, _DWORD))event->GetModelIndex)(
                a1: event,
                a2: "userid",
                a3: 0);
        v11 = UTIL_PlayerByUserId(userID: v10);
        v12 = ToCSPlayer(pEntity: v11);
        CCSGameStats::IncrementStat(
          this: (CCSGameStats *)((char *)this - 88),
          pPlayer: v12,
          statId: CSSTAT_DECAL_SPRAYS,
          iDelta: 1,
          bPlayerOnly: false);
      }
    }
    else
    {
      v6 = ((int (__thiscall *)(CBreakableProp *, const char *, _DWORD))event->GetModelIndex)(
             a1: event,
             a2: "userid",
             a3: 0);
      v7 = ((int (__thiscall *)(CBreakableProp *, const char *, _DWORD))event->GetModelIndex)(
             a1: event,
             a2: "entindex",
             a3: 0);
      pProp = (CBreakableProp *)CBaseEntity::Instance(iEnt: v7);
      v8 = UTIL_PlayerByUserId(userID: v6);
      if ( v8 != nullptr && v8->IsPlayer(this: v8) )
      {
        v9 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v8,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        CCSGameStats::Event_BreakProp(this: (CCSGameStats *)((char *)this - 88), a2: (int)v8, pPlayer: v9, pProp);
      }
      else
      {
        CCSGameStats::Event_BreakProp(this: (CCSGameStats *)((char *)this - 88), a2: (int)v8, pPlayer: nullptr, pProp);
      }
    }
  }
  else
  {
    v4 = (CCSGameStats *)((char *)this - 88);
    CCSGameStats::UploadRoundStats(this: v4);
    if ( ((int (__thiscall *)(CBreakableProp *, const char *, _DWORD))event->GetModelIndex)(
           a1: event,
           a2: "reason",
           a3: 0) == 15 )
    {
      CCSGameStats::ResetPlayerClassMatchStats(this: v4);
    }
    else
    {
      v5 = ((int (__thiscall *)(CBreakableProp *, const char *, _DWORD))event->GetModelIndex)(
             a1: event,
             a2: "winner",
             a3: 0);
      CCSGameStats::UpdatePlayerRoundStats(this: v4, winner: v5);
      CCSGameStats::ComputeDirectStatAverages(this: v4);
      CCSGameStats::SendDirectStatsAveragesToAllPlayers(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027CC10
// Name: public: short CUtlDict<enum CSStatType_t,short>::Insert(char const __near *,enum CSStatType_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<enum CSStatType_t,short>::Insert(
        CUtlDict<enum CSStatType_t,short> *this,
        const char *pName,
        CSStatType_t *element)
{
  const char *v3; // edi
  char *v5; // eax
  CSStatType_t v6; // edx
  int result; // eax
  CUtlMap<char const *,enum CSStatType_t,short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  v6 = *element;
  insert.key = v5;
  insert.elem = v6;
  element = (CSStatType_t *)-1;
  LOBYTE(pName) = 0;
  CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::FindInsertionPosition(
    this: &this->m_Elements.m_Tree,
    &insert,
    parent: (__int16 *)&element,
    leftchild: (bool *)&pName);
  result = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::InsertAt(
                               this: &this->m_Elements.m_Tree,
                               a2: v3,
                               parent: (__int16)element,
                               leftchild: (bool)pName);
  if ( &this->m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)result] != (UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short> *)-8 )
    this->m_Elements.m_Tree.m_Elements.m_pMemory[(__int16)result].m_Data = insert;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027CCC0
// Name: public: virtual CCSGameStats::~CCSGameStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameStats::~CCSGameStats(CCSGameStats *this)
{
  CGameEventListener *v2; // edi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->CBaseGameStats::__vftable = (CCSGameStats_vtbl *)&CCSGameStats::`vftable'{for `CBaseGameStats'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSGameStats::`vftable'{for `CGameEventListener'};
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CAutoGameSystemPerFrame_vtbl *)&CCSGameStats::`vftable'{for `CAutoGameSystemPerFrame'};
  this->IGameStatTracker::__vftable = (IGameStatTracker_vtbl *)&CCSGameStats::`vftable'{for `IGameStatTracker'};
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponShotData);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponMissData);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponHitData);
  CUtlDict<enum CSStatType_t,short>::RemoveAll(this: &this->m_PropStatTable);
  CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>::~CUtlRBTree<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short,CUtlMap<char const *,enum CSStatType_t,short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,enum CSStatType_t,short>::Node_t,short>,short>>(this: &this->m_PropStatTable.m_Elements.m_Tree);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &this->CAutoGameSystemPerFrame);
  v3 = !v2->m_bRegisteredForEvents;
  v2->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v2->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  CUtlDict<BasicGameStatsRecord_t,unsigned short>::RemoveAll(this: &this->m_BasicStats.m_MapTotals);
  CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,BasicGameStatsRecord_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_BasicStats.m_MapTotals.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1027CDA0
// Name: public: CCSGameStats::CCSGameStats(void)
// Source: json
//------------------------------------------------------------------------------
CCSGameStats *__thiscall CCSGameStats::CCSGameStats(CCSGameStats *this)
{
  PlayerStats_t *m_aPlayerStats; // edi
  int *iNumKilledByUnanswered; // ebx
  unsigned int v4; // eax
  int v6; // [esp+Ch] [ebp-8h]
  PlayerStats_t *v7; // [esp+10h] [ebp-4h]
  unsigned int i; // [esp+10h] [ebp-4h]

  CBaseGameStats::CBaseGameStats(this);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &this->CAutoGameSystemPerFrame, name: nullptr);
  this->IGameStatTracker::__vftable = (IGameStatTracker_vtbl *)&IGameStatTracker::`vftable';
  m_aPlayerStats = this->m_aPlayerStats;
  this->CBaseGameStats::__vftable = (CCSGameStats_vtbl *)&CCSGameStats::`vftable'{for `CBaseGameStats'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSGameStats::`vftable'{for `CGameEventListener'};
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CAutoGameSystemPerFrame_vtbl *)&CCSGameStats::`vftable'{for `CAutoGameSystemPerFrame'};
  this->IGameStatTracker::__vftable = (IGameStatTracker_vtbl *)&CCSGameStats::`vftable'{for `IGameStatTracker'};
  v7 = this->m_aPlayerStats;
  v6 = 64;
  iNumKilledByUnanswered = this->m_aPlayerStats[0].statsKills.iNumKilledByUnanswered;
  while ( 1 )
  {
    memset(m_aPlayerStats, 0, 0x418u);
    memset(iNumKilledByUnanswered - 654, 0, 0x418u);
    memset(iNumKilledByUnanswered - 392, 0, 0x418u);
    _V_memset(dest: iNumKilledByUnanswered - 130, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered - 65, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered, fill: 0, count: 260);
    memset(v7, 0, 0x418u);
    memset(iNumKilledByUnanswered - 654, 0, 0x418u);
    memset(iNumKilledByUnanswered - 392, 0, 0x418u);
    _V_memset(dest: iNumKilledByUnanswered - 130, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered - 65, fill: 0, count: 260);
    _V_memset(dest: iNumKilledByUnanswered, fill: 0, count: 260);
    ++v7;
    iNumKilledByUnanswered += 981;
    if ( --v6 < 0 )
      break;
    m_aPlayerStats = v7;
  }
  memset(this->m_aTeamStats, 0, sizeof(this->m_aTeamStats));
  memset(&this->m_rollingCTStatAverages, 0, 0x418u);
  this->m_rollingCTStatAverages.m_numberOfDataSets = 0;
  memset(&this->m_rollingTStatAverages, 0, 0x418u);
  this->m_rollingTStatAverages.m_numberOfDataSets = 0;
  memset(&this->m_rollingPlayerStatAverages, 0, 0x418u);
  this->m_rollingPlayerStatAverages.m_numberOfDataSets = 0;
  memset(&this->m_directCTStatAverages, 0, sizeof(this->m_directCTStatAverages));
  memset(&this->m_directTStatAverages, 0, sizeof(this->m_directTStatAverages));
  memset(&this->m_directPlayerStatAverages, 0, sizeof(this->m_directPlayerStatAverages));
  this->m_PropStatTable.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PropStatTable.m_Elements.m_Tree.m_Root = -1;
  this->m_PropStatTable.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PropStatTable.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PropStatTable.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PropStatTable.m_Elements.m_Tree.m_pElements = this->m_PropStatTable.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PropStatTable.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PropStatTable.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_WeaponHitData.m_Memory.m_pMemory = nullptr;
  this->m_WeaponHitData.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponHitData.m_Memory.m_nGrowSize = 0;
  this->m_WeaponHitData.m_Size = 0;
  this->m_WeaponHitData.m_pElements = nullptr;
  this->m_WeaponMissData.m_Memory.m_pMemory = nullptr;
  this->m_WeaponMissData.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponMissData.m_Memory.m_nGrowSize = 0;
  this->m_WeaponMissData.m_Size = 0;
  this->m_WeaponMissData.m_pElements = nullptr;
  this->m_WeaponShotData.m_Memory.m_pMemory = nullptr;
  this->m_WeaponShotData.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponShotData.m_Memory.m_nGrowSize = 0;
  this->m_WeaponShotData.m_Size = 0;
  this->m_WeaponShotData.m_pElements = nullptr;
  gamestats = this;
  v4 = 0;
  *(_QWORD *)&this->m_fDisseminationTimerLow = 0;
  for ( i = 0; ; v4 = i )
  {
    CUtlDict<enum CSStatType_t,short>::Insert(
      this: &this->m_PropStatTable,
      pName: *(const char **)((char *)&PropModelStatsTableInit[0].szPropModelName + v4),
      element: (CSStatType_t *)((char *)&unk_105C7B5C + v4));
    i += 8;
    if ( i >= 0x50 )
      break;
  }
  this->m_numberOfRoundsForDirectAverages = 0;
  this->m_numberOfTerroristEntriesForDirectAverages = 0;
  this->m_numberOfCounterTerroristEntriesForDirectAverages = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10363C00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ResponseRules::ResponseGroup,short>::Node_t,short>,short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short>,short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (__int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > -1 )
      {
        if ( (__int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (__int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::ResponseGroup,short>::Node_t,short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10363CA0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct ResponseRules::Criteria,short>::Node_t,short>,short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short>,short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (__int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > -1 )
      {
        if ( (__int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (__int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,ResponseRules::Criteria,short>::Node_t,short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040EC00
// Name: _dynamic_initializer_for__CCSGameStats::s_StatLists__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
CUtlVector<IGameStatTracker::IStatContainer *,CUtlMemory<IGameStatTracker::IStatContainer *,int> > *dynamic_initializer_for__CCSGameStats::s_StatLists__()
{
  CUtlVector<IGameStatTracker::IStatContainer *,CUtlMemory<IGameStatTracker::IStatContainer *,int> > *result; // eax

  result = (CUtlVector<IGameStatTracker::IStatContainer *,CUtlMemory<IGameStatTracker::IStatContainer *,int> > *)operator new(nSize: 0x14u);
  if ( result != nullptr )
  {
    result->m_Memory.m_pMemory = nullptr;
    result->m_Memory.m_nAllocationCount = 0;
    result->m_Memory.m_nGrowSize = 0;
    result->m_Size = 0;
    result->m_pElements = nullptr;
    CCSGameStats::s_StatLists = result;
  }
  else
  {
    CCSGameStats::s_StatLists = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040EC30
// Name: _dynamic_initializer_for__s_HLTVDirector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_HLTVDirector__()
{
  CHLTVDirector::CHLTVDirector(this: &s_HLTVDirector);
  s_HLTVDirector.CHLTVDirector::CGameEventListener::IGameEventListener2::__vftable = (CCSHLTVDirector_vtbl *)&CCSHLTVDirector::`vftable'{for `CGameEventListener'};
  s_HLTVDirector.CHLTVDirector::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CBaseGameSystemPerFrame_vtbl *)&CCSHLTVDirector::`vftable'{for `CBaseGameSystemPerFrame'};
  s_HLTVDirector.CHLTVDirector::IHLTVDirector::__vftable = (IHLTVDirector_vtbl *)&CCSHLTVDirector::`vftable'{for `IHLTVDirector'};
  return atexit(func: dynamic_atexit_destructor_for__s_HLTVDirector__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EC70
// Name: _dynamic_initializer_for____g_CreateCHLTVDirectorIHLTVDirector_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCHLTVDirectorIHLTVDirector_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCHLTVDirectorIHLTVDirector_reg,
           fn: _CreateCHLTVDirectorIHLTVDirector_interface,
           pName: "HLTVDirector001");
}

//------------------------------------------------------------------------------
// Address: 0x1040EC90
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___11()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_11,
           fn: _CreateCServerGameTagsIServerGameTags_interface_11,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1040ECB0
// Name: _dynamic_initializer_for__cs_ShowStateTransitions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_ShowStateTransitions__()
{
  ConVar::ConVar(
    this: &cs_ShowStateTransitions,
    pName: "cs_ShowStateTransitions",
    pDefaultValue: "-2",
    flags: 0x4000,
    pHelpString: "cs_ShowStateTransitions <ent index or -1 for all>. Show player state transitions.");
  return atexit(func: dynamic_atexit_destructor_for__cs_ShowStateTransitions__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ECE0
// Name: _dynamic_initializer_for__sv_max_usercmd_future_ticks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_max_usercmd_future_ticks__()
{
  ConVar::ConVar(
    this: &sv_max_usercmd_future_ticks,
    pName: "sv_max_usercmd_future_ticks",
    pDefaultValue: "8",
    flags: 0,
    pHelpString: "Prevents clients from running usercmds too far in the future. Prevents speed hacks.");
  return atexit(func: dynamic_atexit_destructor_for__sv_max_usercmd_future_ticks__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ED10
// Name: _dynamic_initializer_for__cs_AssistDamageThreshold__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_AssistDamageThreshold__()
{
  ConVar::ConVar(
    this: &cs_AssistDamageThreshold,
    pName: "cs_AssistDamageThreshold",
    pDefaultValue: "40.0",
    flags: 2,
    pHelpString: "cs_AssistDamageThreshold defines the amount of damage needed to score an assist");
  return atexit(func: dynamic_atexit_destructor_for__cs_AssistDamageThreshold__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ED40
// Name: _dynamic_initializer_for__sv_nomvp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_nomvp__()
{
  ConVar::ConVar(
    this: &sv_nomvp,
    pName: "sv_nomvp",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable MVP awards.",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SvNoMVPChangeCallback);
  return atexit(func: dynamic_atexit_destructor_for__sv_nomvp__);
}

//------------------------------------------------------------------------------
// Address: 0x1040ED70
// Name: _dynamic_initializer_for__sv_disablefreezecam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_disablefreezecam__()
{
  ConVar::ConVar(
    this: &sv_disablefreezecam,
    pName: "sv_disablefreezecam",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Turn on/off freezecam on server");
  return atexit(func: dynamic_atexit_destructor_for__sv_disablefreezecam__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EDA0
// Name: _dynamic_initializer_for__sv_nowinpanel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_nowinpanel__()
{
  ConVar::ConVar(
    this: &sv_nowinpanel,
    pName: "sv_nowinpanel",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Turn on/off win panel on server");
  return atexit(func: dynamic_atexit_destructor_for__sv_nowinpanel__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EDD0
// Name: _dynamic_initializer_for__bot_mimic__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_mimic__()
{
  ConVar::ConVar(this: &bot_mimic, pName: "bot_mimic", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__bot_mimic__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EE00
// Name: _dynamic_initializer_for__bot_freeze__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_freeze__()
{
  ConVar::ConVar(this: &bot_freeze, pName: "bot_freeze", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__bot_freeze__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EE30
// Name: _dynamic_initializer_for__bot_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_crouch__()
{
  ConVar::ConVar(this: &bot_crouch, pName: "bot_crouch", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__bot_crouch__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EE60
// Name: _dynamic_initializer_for__bot_mimic_yaw_offset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_mimic_yaw_offset__()
{
  ConVar::ConVar(this: &bot_mimic_yaw_offset, pName: "bot_mimic_yaw_offset", pDefaultValue: "180", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__bot_mimic_yaw_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EE90
// Name: _dynamic_initializer_for__sv_autobuyammo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_autobuyammo__()
{
  ConVar::ConVar(
    this: &sv_autobuyammo,
    pName: "sv_autobuyammo",
    pDefaultValue: "1",
    flags: 8448,
    pHelpString: "Enable automatic ammo purchase when inside buy zones during buy periods");
  return atexit(func: dynamic_atexit_destructor_for__sv_autobuyammo__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EEC0
// Name: _dynamic_initializer_for__cs_ragdoll__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_ragdoll__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CCSRagdoll> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cs_ragdoll,
           a3: "cs_ragdoll");
}

//------------------------------------------------------------------------------
// Address: 0x1040EEE0
// Name: _dynamic_initializer_for__g_CCSRagdoll_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CCSRagdoll_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CCSRagdoll_ClassReg,
           pNetworkName: "CCSRagdoll",
           pTable: &DT_CSRagdoll::g_SendTable);
}
