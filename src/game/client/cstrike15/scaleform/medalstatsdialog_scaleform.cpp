// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/medalstatsdialog_scaleform.cpp
// Functions: 20
// ============================================================

#include "game\client\cstrike15\scaleform\medalstatsdialog_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020B3A0
// Name: protected: void CCreateMedalStatsDialogScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::Show(CCreateLeaderboardsDialogScaleform *this)
{
  char i; // al
  IScaleformUI *v3; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v3 = ScaleformUI();
      v3->Value_InvokeWithoutReturn(this: v3, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C2B0
// Name: UpdateLastAccessedTime
// Source: json
//------------------------------------------------------------------------------
void UpdateLastAccessedTime()
{
  tm newtime; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &newtime);
  ConVar::SetValue(
    this: (ConVar *)&player_last_medalstats_access_time1.IConVar,
    value: LOBYTE(newtime.tm_mday) | (unsigned __int16)((LOWORD(newtime.tm_mon) + 1) << 8) | ((newtime.tm_year + 1900) << 16));
  ConVar::SetValue(
    this: (ConVar *)&player_last_medalstats_access_time2.IConVar,
    value: LOBYTE(newtime.tm_sec) | ((LOBYTE(newtime.tm_min) | (LOBYTE(newtime.tm_hour) << 8)) << 8));
}

//------------------------------------------------------------------------------
// Address: 0x1020C330
// Name: AchievementDateSortPredicate
// Source: json
//------------------------------------------------------------------------------
int __cdecl AchievementDateSortPredicate(CCSBaseAchievement *const *pLeft, CCSBaseAchievement *const *pRight)
{
  unsigned int m_uUnlockTime; // eax
  unsigned int v3; // ecx

  if ( pLeft == nullptr || pRight == nullptr || *pLeft == nullptr || *pRight == nullptr )
    return 0;
  m_uUnlockTime = (*pLeft)->m_uUnlockTime;
  v3 = (*pRight)->m_uUnlockTime;
  if ( v3 <= m_uUnlockTime )
    return -(v3 < m_uUnlockTime);
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020C380
// Name: IsRecentUnlock
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IsRecentUnlock(CCSBaseAchievement *pAchievement)
{
  int v1; // ecx
  int v2; // edx
  int v3; // esi
  bool result; // al
  int second; // [esp+4h] [ebp-18h] BYREF
  int minute; // [esp+8h] [ebp-14h] BYREF
  int hour; // [esp+Ch] [ebp-10h] BYREF
  int day; // [esp+10h] [ebp-Ch] BYREF
  int year; // [esp+14h] [ebp-8h] BYREF
  int month; // [esp+18h] [ebp-4h] BYREF

  result = false;
  if ( pAchievement != nullptr
    && ClientModeShared::OverrideRenderBounds(
         this: (ClientModeShared *)pAchievement,
         x: &year,
         y: &month,
         w: &day,
         h: &hour,
         insetX: &minute,
         insetY: &second) )
  {
    v1 = (unsigned __int8)day | (((year << 8) | (unsigned __int8)month) << 8);
    v2 = player_last_medalstats_access_time1.m_pParent != nullptr
       ? player_last_medalstats_access_time1.m_pParent->m_Value.m_nValue
       : 0;
    v3 = player_last_medalstats_access_time2.m_pParent != nullptr
       ? player_last_medalstats_access_time2.m_pParent->m_Value.m_nValue
       : 0;
    if ( v1 > v2
      || v1 == v2 && ((unsigned __int8)second | (((unsigned __int8)minute | ((unsigned __int8)hour << 8)) << 8)) > v3 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C430
// Name: protected: virtual void CCreateMedalStatsDialogScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::FlashLoaded(CCreateMedalStatsDialogScaleform *this)
{
  int m_iPlayerSlot; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    m_iPlayerSlot = this->m_iPlayerSlot;
    if ( this->m_pScaleformUI != nullptr )
    {
      if ( m_iPlayerSlot == -1 )
        m_iPlayerSlot = this->m_iFlashSlot - 2;
      this->m_pScaleformUI->LockInputToSlot(this: this->m_pScaleformUI, a2: m_iPlayerSlot);
    }
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "InitDialogData",
      a4: nullptr,
      a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C480
// Name: protected: void CCreateMedalStatsDialogScaleform::UpdateMedalProgress(class CCSBaseAchievement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::UpdateMedalProgress(
        CCreateMedalStatsDialogScaleform *this,
        CCSBaseAchievement *pAchievement)
{
  CGameUI *v4; // eax
  int v5; // ebx
  int (__thiscall *GetCount)(IAchievement *); // eax
  IAchievement *v7; // edi
  char i; // al
  void *v9; // edi
  int iGoal; // [esp+4h] [ebp-4h]
  char bShowProgress_3; // [esp+13h] [ebp+Bh]

  if ( this->m_bFlashAPIIsValid )
  {
    if ( pAchievement == nullptr
      || pAchievement->GetGoal(this: &pAchievement->IAchievement) <= 1
      || (bShowProgress_3 = 1, (pAchievement->GetFlags(this: &pAchievement->IAchievement) & 0x40) != 0)
      && (v4 = GameUI(), !v4->IsInLevel(this: v4))
      && !pAchievement->IsAchieved(this: &pAchievement->IAchievement) )
    {
      bShowProgress_3 = 0;
    }
    v5 = -1;
    iGoal = -1;
    if ( bShowProgress_3 != 0 )
    {
      GetCount = pAchievement->GetCount;
      v7 = &pAchievement->IAchievement;
      v5 = GetCount(this: v7);
      iGoal = v7->GetGoal(this: v7);
      if ( v7->IsAchieved(this: v7) )
        v5 = iGoal;
    }
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v9 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v9, a3: 0, a4: v5);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v9, a3: 1, a4: iGoal);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setMedalsProgress",
        a4: v9,
        a5: 2u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v9, a3: 2u);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C5C0
// Name: protected: virtual bool CCreateMedalStatsDialogScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCreateMedalStatsDialogScaleform::PreUnloadFlash(CCreateMedalStatsDialogScaleform *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockInput(this: this->m_pScaleformUI);
  UpdateLastAccessedTime();
  if ( this->m_pScaleformUI != nullptr )
  {
    if ( this->m_MedalNameHandle != nullptr )
    {
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_MedalNameHandle);
      this->m_MedalNameHandle = nullptr;
    }
    if ( this->m_pScaleformUI != nullptr )
    {
      if ( this->m_MedalUnlockHandle != nullptr )
      {
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_MedalUnlockHandle);
        this->m_MedalUnlockHandle = nullptr;
      }
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( this->m_MedalDescHandle != nullptr )
        {
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_MedalDescHandle);
          this->m_MedalDescHandle = nullptr;
        }
        if ( this->m_pScaleformUI != nullptr )
        {
          if ( this->m_LastMatchTeamStats != nullptr )
          {
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LastMatchTeamStats);
            this->m_LastMatchTeamStats = nullptr;
          }
          if ( this->m_pScaleformUI != nullptr )
          {
            if ( this->m_LastMatchFaveWeaponName != nullptr )
            {
              this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LastMatchFaveWeaponName);
              this->m_LastMatchFaveWeaponName = nullptr;
            }
            if ( this->m_pScaleformUI != nullptr )
            {
              if ( this->m_LastMatchFaveWeaponStats != nullptr )
              {
                this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LastMatchFaveWeaponStats);
                this->m_LastMatchFaveWeaponStats = nullptr;
              }
              if ( this->m_pScaleformUI != nullptr )
              {
                if ( this->m_LastMatchPerfStats != nullptr )
                {
                  this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LastMatchPerfStats);
                  this->m_LastMatchPerfStats = nullptr;
                }
                if ( this->m_pScaleformUI != nullptr )
                {
                  if ( this->m_LastMatchMiscStats != nullptr )
                  {
                    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LastMatchMiscStats);
                    this->m_LastMatchMiscStats = nullptr;
                  }
                  if ( this->m_pScaleformUI != nullptr )
                  {
                    if ( this->m_OverallPlayerName != nullptr )
                    {
                      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_OverallPlayerName);
                      this->m_OverallPlayerName = nullptr;
                    }
                    if ( this->m_pScaleformUI != nullptr )
                    {
                      if ( this->m_OverallMVPsText != nullptr )
                      {
                        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_OverallMVPsText);
                        this->m_OverallMVPsText = nullptr;
                      }
                      if ( this->m_pScaleformUI != nullptr )
                      {
                        if ( this->m_OverallPlayerStats != nullptr )
                        {
                          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_OverallPlayerStats);
                          this->m_OverallPlayerStats = nullptr;
                        }
                        if ( this->m_pScaleformUI != nullptr )
                        {
                          if ( this->m_OverallFaveWeaponName != nullptr )
                          {
                            this->m_pScaleformUI->ReleaseValue(
                              this: this->m_pScaleformUI,
                              a2: this->m_OverallFaveWeaponName);
                            this->m_OverallFaveWeaponName = nullptr;
                          }
                          if ( this->m_pScaleformUI != nullptr )
                          {
                            if ( this->m_OverallFaveWeaponStats != nullptr )
                            {
                              this->m_pScaleformUI->ReleaseValue(
                                this: this->m_pScaleformUI,
                                a2: this->m_OverallFaveWeaponStats);
                              this->m_OverallFaveWeaponStats = nullptr;
                            }
                            if ( this->m_pScaleformUI != nullptr && this->m_OverallFaveMapStats != nullptr )
                            {
                              this->m_pScaleformUI->ReleaseValue(
                                this: this->m_pScaleformUI,
                                a2: this->m_OverallFaveMapStats);
                              this->m_OverallFaveMapStats = nullptr;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020C7A0
// Name: public: void CCreateMedalStatsDialogScaleform::GetRecentAchievementCount(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::GetRecentAchievementCount(
        CCreateMedalStatsDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  this->m_pScaleformUI->Params_SetResult_5(this: this->m_pScaleformUI, a2: obj, a3: this->m_recentAchievements.m_Size);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020C7E0
// Name: protected: void CCreateMedalStatsDialogScaleform::PopulateLastMatchStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::PopulateLastMatchStats(CCreateMedalStatsDialogScaleform *this)
{
  const StatsCollection_t *LifetimeStats; // edi
  int v3; // ebx
  CSWeaponID v4; // ebx
  CCSWeaponInfo *WeaponInfo; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // xmm0_4
  int v9; // ebx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  char i; // al
  void *v14; // edi
  void *m_LastMatchTeamStats; // eax
  void *m_LastMatchFaveWeaponName; // eax
  void *m_LastMatchFaveWeaponStats; // eax
  void *m_LastMatchPerfStats; // eax
  void *m_LastMatchMiscStats; // eax
  wchar_t miscStats[128]; // [esp+1Ch] [ebp-420h] BYREF
  wchar_t teamStats[128]; // [esp+11Ch] [ebp-320h] BYREF
  wchar_t perfStats[128]; // [esp+21Ch] [ebp-220h] BYREF
  wchar_t weaponStats[128]; // [esp+31Ch] [ebp-120h] BYREF
  const char *shortWeaponName; // [esp+41Ch] [ebp-20h]
  int stars; // [esp+420h] [ebp-1Ch]
  int roundWonValue; // [esp+424h] [ebp-18h]
  int dominations; // [esp+428h] [ebp-14h]
  int roundsPlayed; // [esp+42Ch] [ebp-10h]
  PlayerStatData_t result; // [esp+430h] [ebp-Ch] BYREF

  LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot: 0);
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xF6u, nUserSlot: 0);
  v3 = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xF7u, nUserSlot: 0);
  roundsPlayed = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xF8u, nUserSlot: 0);
  roundWonValue = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x101u, nUserSlot: 0);
  V_snwprintf(
    pDest: teamStats,
    maxLen: 128,
    pFormat: L"%d\n%d\n%d\n%d",
    v3,
    roundsPlayed,
    roundWonValue,
    LifetimeStats->m_iValue[result.iStatId]);
  roundWonValue = (int)"#SFUI_LastMatch_NoFaveWeapon";
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x102u, nUserSlot: 0);
  v4 = LifetimeStats->m_iValue[result.iStatId];
  shortWeaponName = WeaponIdAsString(weaponID: v4);
  WeaponInfo = GetWeaponInfo(weaponID: v4);
  if ( WeaponInfo != nullptr )
    roundWonValue = (int)WeaponInfo->szPrintName;
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x104u, nUserSlot: 0);
  v6 = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x105u, nUserSlot: 0);
  dominations = LifetimeStats->m_iValue[result.iStatId];
  roundsPlayed = 0;
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x103u, nUserSlot: 0);
  v7 = LifetimeStats->m_iValue[result.iStatId];
  if ( v7 != 0 )
    *(float *)&v8 = (float)((float)v6 / (float)v7) * 100.0;
  else
    v8 = roundsPlayed;
  V_snwprintf(pDest: weaponStats, maxLen: 128, pFormat: L"%d\n%d\n%3.2f", v6, dominations, *(float *)&v8);
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFCu, nUserSlot: 0);
  stars = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFAu, nUserSlot: 0);
  v9 = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFBu, nUserSlot: 0);
  dominations = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xF9u, nUserSlot: 0);
  roundsPlayed = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xF4u, nUserSlot: 0);
  v10 = 0.0;
  if ( dominations > 0 )
    v10 = (float)v9 / (float)dominations;
  v11 = (float)LifetimeStats->m_iValue[result.iStatId];
  if ( roundsPlayed > 0 )
    v11 = v11 / (float)roundsPlayed;
  V_snwprintf(pDest: perfStats, maxLen: 128, pFormat: L"%d\n%d\n%d\n%.3f\n%3.1f", stars, v9, dominations, v10, v11);
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFDu, nUserSlot: 0);
  roundsPlayed = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFFu, nUserSlot: 0);
  dominations = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0x100u, nUserSlot: 0);
  stars = LifetimeStats->m_iValue[result.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, &result, id: 0xFEu, nUserSlot: 0);
  v12 = 0.0;
  if ( v9 > 0 )
    v12 = (float)LifetimeStats->m_iValue[result.iStatId] / (float)v9;
  V_snwprintf(pDest: miscStats, maxLen: 128, pFormat: L"%d\n%.3f\n%d\n%d", roundsPlayed, v12, dominations, stars);
  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v14 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
    this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v14, a3: 0, a4: shortWeaponName);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "setLastMatchFavoriteWeapon",
      a4: v14,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v14, a3: 1u);
    m_LastMatchTeamStats = this->m_LastMatchTeamStats;
    if ( m_LastMatchTeamStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_LastMatchTeamStats, a3: teamStats);
    m_LastMatchFaveWeaponName = this->m_LastMatchFaveWeaponName;
    if ( m_LastMatchFaveWeaponName != nullptr )
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: m_LastMatchFaveWeaponName,
        a3: (const char *)roundWonValue);
    m_LastMatchFaveWeaponStats = this->m_LastMatchFaveWeaponStats;
    if ( m_LastMatchFaveWeaponStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_LastMatchFaveWeaponStats, a3: weaponStats);
    m_LastMatchPerfStats = this->m_LastMatchPerfStats;
    if ( m_LastMatchPerfStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_LastMatchPerfStats, a3: perfStats);
    m_LastMatchMiscStats = this->m_LastMatchMiscStats;
    if ( m_LastMatchMiscStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_LastMatchMiscStats, a3: miscStats);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020CC50
// Name: protected: void CCreateMedalStatsDialogScaleform::PopulateOverallStats(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCreateMedalStatsDialogScaleform::PopulateOverallStats(
        CCreateMedalStatsDialogScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  IMatchSystem *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  const StatsCollection_t *LifetimeStats; // edi
  const wchar_t *v9; // eax
  float v10; // xmm0_4
  int v11; // edi
  float v12; // xmm2_4
  float v13; // xmm1_4
  unsigned int v14; // eax
  const MapName_MapStatId *v15; // edi
  unsigned int v16; // ecx
  int iStatValue; // eax
  PlayerStatData_t *StatById; // eax
  unsigned int statRoundsId; // ecx
  int v20; // eax
  const wchar_t *v21; // eax
  unsigned int v22; // eax
  const WeaponName_StatId *v23; // edi
  unsigned int v24; // ecx
  int v25; // eax
  float v26; // xmm0_4
  CCSWeaponInfo *WeaponInfo; // eax
  PlayerStatData_t *v28; // eax
  unsigned int shotStatId; // ecx
  PlayerStatData_t *v30; // eax
  unsigned int killStatId; // ecx
  char j; // al
  void *v33; // edi
  void *m_OverallPlayerName; // eax
  void *m_OverallMVPsText; // eax
  void *m_OverallPlayerStats; // eax
  void *m_OverallFaveWeaponName; // eax
  void *m_OverallFaveWeaponStats; // eax
  void *m_OverallFaveMapStats; // eax
  int m_iPlayerSlot; // [esp+34h] [ebp-4B4h]
  wchar_t mapStats[128]; // [esp+3Ch] [ebp-4ACh] BYREF
  wchar_t starsText[128]; // [esp+13Ch] [ebp-3ACh] BYREF
  wchar_t faveWeaponStats[128]; // [esp+23Ch] [ebp-2ACh] BYREF
  wchar_t playerStats[128]; // [esp+33Ch] [ebp-1ACh] BYREF
  char faveMapName[128]; // [esp+43Ch] [ebp-ACh] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4BCh] [ebp-2Ch] BYREF
  const char *playerName; // [esp+4C0h] [ebp-28h]
  const char *shortWeaponName; // [esp+4C4h] [ebp-24h]
  int shotsFired; // [esp+4C8h] [ebp-20h]
  PlayerStatData_t stat; // [esp+4CCh] [ebp-1Ch] BYREF
  const MapName_MapStatId *mapStatId; // [esp+4D8h] [ebp-10h]
  int i; // [esp+4DCh] [ebp-Ch]
  const WeaponName_StatId *weaponStatEntry; // [esp+4E0h] [ebp-8h]
  CSWeaponID faveWeaponID; // [esp+4E4h] [ebp-4h]

  m_iPlayerSlot = this->m_iPlayerSlot;
  playerName = "Player";
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: m_iPlayerSlot);
  v4 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v5 = v4->GetPlayerManager(this: v4);
  v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 4))(a1: v5, a2: this->m_iPlayerSlot);
  if ( v6 != 0 )
    playerName = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  v7 = this->m_iPlayerSlot;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot: v7);
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 0xABu, nUserSlot: 0);
  v9 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int, int))g_pVGuiLocalize->Find)(
                          a1: g_pVGuiLocalize,
                          a2: "#SFUI_Overall_Stars",
                          a3: LifetimeStats->m_iValue[stat.iStatId],
                          a4: a3);
  V_snwprintf(pDest: starsText, maxLen: 128, pFormat: v9, a2);
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 0xDu, nUserSlot: 0);
  mapStatId = (const MapName_MapStatId *)LifetimeStats->m_iValue[stat.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 0xAu, nUserSlot: 0);
  faveWeaponID = LifetimeStats->m_iValue[stat.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 1u, nUserSlot: 0);
  shotsFired = LifetimeStats->m_iValue[stat.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 0, nUserSlot: 0);
  i = LifetimeStats->m_iValue[stat.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 2u, nUserSlot: 0);
  weaponStatEntry = (const WeaponName_StatId *)LifetimeStats->m_iValue[stat.iStatId];
  CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: 3u, nUserSlot: 0);
  v10 = 0.0;
  v11 = LifetimeStats->m_iValue[stat.iStatId];
  v12 = 0.0;
  if ( (int)mapStatId > 0 )
    v12 = (float)faveWeaponID / (float)(int)mapStatId;
  v13 = 0.0;
  if ( shotsFired > 0 )
    v13 = (float)i / (float)shotsFired;
  if ( v11 > 0 )
    v10 = (float)(int)weaponStatEntry / (float)v11;
  V_snwprintf(
    pDest: playerStats,
    maxLen: 128,
    pFormat: L"%d\n%d\n%3.2f\n%d\n%d\n%3.2f\n\n%d\n%d\n%.3f",
    mapStatId,
    faveWeaponID,
    v12,
    shotsFired,
    i,
    v13,
    weaponStatEntry,
    v11,
    v10);
  shotsFired = (int)"map_none";
  V_strncpy(pDest: faveMapName, pSrc: "#SFUI_Overall_NoFavorite", maxLen: 128);
  v14 = 0;
  v15 = nullptr;
  faveWeaponID = WEAPON_NONE;
  i = 0;
  do
  {
    v16 = dword_104A5600[v14 / 4];
    mapStatId = &MapName_StatId_Table[v14 / 0x10];
    CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: v16, nUserSlot: v7);
    if ( stat.iStatValue > faveWeaponID )
    {
      v15 = mapStatId;
      faveWeaponID = stat.iStatValue;
    }
    ++i;
    v14 = 16 * i;
  }
  while ( dword_104A55FC[4 * i] != -1 );
  iStatValue = 0;
  weaponStatEntry = nullptr;
  mapStatId = nullptr;
  if ( v15 != nullptr )
  {
    shotsFired = (int)v15->szMapName;
    V_snprintf(pDest: faveMapName, maxLen: 0x80u, pFormat: "#SFUI_Map_%s", (const char *)shotsFired);
    StatById = CCSClientGameStats::GetStatById(
                 this: &g_CSClientGameStats,
                 result: &stat,
                 id: v15->statWinsId,
                 nUserSlot: v7);
    statRoundsId = v15->statRoundsId;
    weaponStatEntry = (const WeaponName_StatId *)StatById->iStatValue;
    iStatValue = CCSClientGameStats::GetStatById(
                   this: &g_CSClientGameStats,
                   result: &stat,
                   id: statRoundsId,
                   nUserSlot: v7)->iStatValue;
  }
  v20 = ((int (__thiscall *)(vgui::ILocalize *, char *, int, const WeaponName_StatId *))g_pVGuiLocalize->Find)(
          a1: g_pVGuiLocalize,
          a2: faveMapName,
          a3: iStatValue,
          a4: weaponStatEntry);
  v21 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int))g_pVGuiLocalize->Find)(
                           a1: g_pVGuiLocalize,
                           a2: "#SFUI_Overall_MapStats",
                           a3: v20);
  V_snwprintf(pDest: mapStats, maxLen: 128, pFormat: v21);
  v22 = 0;
  v23 = nullptr;
  shortWeaponName = "weapon_none";
  mapStatId = (const MapName_MapStatId *)"#SFUI_Overall_NoFavorite";
  faveWeaponID = WEAPON_NONE;
  i = 0;
  do
  {
    if ( dword_104A5794[v22 / 4] != -1 )
    {
      v24 = dword_104A578C[v22 / 4];
      weaponStatEntry = &WeaponName_StatId_Table[v22 / 0x14];
      CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: v24, nUserSlot: v7);
      if ( stat.iStatValue > faveWeaponID )
      {
        v23 = weaponStatEntry;
        faveWeaponID = stat.iStatValue;
      }
    }
    ++i;
    v22 = 20 * i;
  }
  while ( dword_104A578C[5 * i] != -1 );
  v25 = 0;
  v26 = 0.0;
  faveWeaponID = WEAPON_NONE;
  weaponStatEntry = nullptr;
  i = 0;
  if ( v23 != nullptr )
  {
    faveWeaponID = v23->weaponId;
    shortWeaponName = WeaponIdAsString(weaponID: faveWeaponID);
    WeaponInfo = GetWeaponInfo(weaponID: faveWeaponID);
    if ( WeaponInfo != nullptr )
      mapStatId = (const MapName_MapStatId *)WeaponInfo->szPrintName;
    v28 = CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: v23->hitStatId, nUserSlot: v7);
    shotStatId = v23->shotStatId;
    faveWeaponID = v28->iStatValue;
    v30 = CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: shotStatId, nUserSlot: v7);
    killStatId = v23->killStatId;
    weaponStatEntry = (const WeaponName_StatId *)v30->iStatValue;
    v25 = CCSClientGameStats::GetStatById(this: &g_CSClientGameStats, result: &stat, id: killStatId, nUserSlot: v7)->iStatValue;
    if ( (int)weaponStatEntry <= 0 )
      v26 = *(float *)&i;
    else
      v26 = (float)v25 / (float)(int)weaponStatEntry;
  }
  V_snwprintf(
    pDest: faveWeaponStats,
    maxLen: 128,
    pFormat: L"%d\n%d\n%d\n%.3f",
    weaponStatEntry,
    faveWeaponID,
    v25,
    v26);
  for ( j = 1; j != 0; j = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v33 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
    this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v33, a3: 0, a4: shortWeaponName);
    this->m_pScaleformUI->ValueArray_SetElement_2(
      this: this->m_pScaleformUI,
      a2: v33,
      a3: 1,
      a4: (const char *)shotsFired);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "setOverallFavoriteWeaponAndMap",
      a4: v33,
      a5: 2u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v33, a3: 2u);
    m_OverallPlayerName = this->m_OverallPlayerName;
    if ( m_OverallPlayerName != nullptr )
      this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_OverallPlayerName, a3: playerName);
    m_OverallMVPsText = this->m_OverallMVPsText;
    if ( m_OverallMVPsText != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_OverallMVPsText, a3: starsText);
    m_OverallPlayerStats = this->m_OverallPlayerStats;
    if ( m_OverallPlayerStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_OverallPlayerStats, a3: playerStats);
    m_OverallFaveWeaponName = this->m_OverallFaveWeaponName;
    if ( m_OverallFaveWeaponName != nullptr )
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: m_OverallFaveWeaponName,
        a3: (const char *)mapStatId);
    m_OverallFaveWeaponStats = this->m_OverallFaveWeaponStats;
    if ( m_OverallFaveWeaponStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_OverallFaveWeaponStats, a3: faveWeaponStats);
    m_OverallFaveMapStats = this->m_OverallFaveMapStats;
    if ( m_OverallFaveMapStats != nullptr )
      this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_OverallFaveMapStats, a3: mapStats);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020D220
// Name: public: static void CCreateMedalStatsDialogScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMedalStatsDialogScaleform::UnloadDialog()
{
  if ( CCreateMedalStatsDialogScaleform::m_pInstance != nullptr
    && CCreateMedalStatsDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateMedalStatsDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateMedalStatsDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateMedalStatsDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateMedalStatsDialogScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D250
// Name: public: void CCreateMedalStatsDialogScaleform::OnOk(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::OnOk(
        CCreateMedalStatsDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+0h] [ebp-4h] BYREF

  g_UISSGuard.m_nSaveSlot = (int)this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  if ( CCreateMedalStatsDialogScaleform::m_pInstance != nullptr
    && CCreateMedalStatsDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateMedalStatsDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateMedalStatsDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateMedalStatsDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateMedalStatsDialogScaleform::m_pInstance->m_FlashAPI);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020D2A0
// Name: public: void CCreateMedalStatsDialogScaleform::UpdateCurrentAchievement(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCreateMedalStatsDialogScaleform::UpdateCurrentAchievement(
        CCreateMedalStatsDialogScaleform *this@<ecx>,
        const char *a2@<ebx>,
        void *a3@<edi>,
        IScaleformUI *pui,
        void *obj)
{
  const char *v6; // eax
  CCSBaseAchievement *v7; // ebx
  CBaseAchievement *AchievementByName; // eax
  char v9; // al
  void *m_MedalNameHandle; // eax
  const char *v11; // edx
  const char *v12; // eax
  CFmtStrN<256> *v13; // eax
  wchar_t *v14; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_MedalUnlockHandle; // eax
  const char *v17; // edx
  void *m_MedalDescHandle; // eax
  const char *v19; // edx
  const char *v20; // eax
  CFmtStrN<256> *v21; // eax
  wchar_t *v22; // eax
  IScaleformUI *v23; // ecx
  wchar_t achDate[1024]; // [esp+4h] [ebp-928h] BYREF
  CFmtStrN<256> v27; // [esp+804h] [ebp-128h] BYREF
  int minute; // [esp+910h] [ebp-1Ch] BYREF
  int hour; // [esp+914h] [ebp-18h] BYREF
  int second; // [esp+918h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+91Ch] [ebp-10h] BYREF
  int day; // [esp+920h] [ebp-Ch] BYREF
  int year; // [esp+924h] [ebp-8h] BYREF
  int month; // [esp+928h] [ebp-4h] BYREF
  char bShouldHide_3; // [esp+937h] [ebp+Bh]
  bool bClearFields_3; // [esp+93Bh] [ebp+Fh]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  if ( !this->m_bFlashAPIIsValid )
    goto LABEL_47;
  v6 = pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
  v7 = nullptr;
  bClearFields_3 = *v6 == 0;
  if ( *v6 != 0 )
  {
    AchievementByName = CAchievementMgr::GetAchievementByName(
                          this: &g_AchievementMgrCS,
                          pchName: v6,
                          nUserSlot: this->m_iPlayerSlot);
    v7 = (CCSBaseAchievement *)__RTDynamicCast(
                                 inptr: AchievementByName,
                                 VfDelta: 0,
                                 SrcType: &CBaseAchievement `RTTI Type Descriptor',
                                 TargetType: &CCSBaseAchievement `RTTI Type Descriptor',
                                 isReference: 0);
  }
  CCreateMedalStatsDialogScaleform::UpdateMedalProgress(this, pAchievement: v7);
  if ( v7 == nullptr
    || !v7->ShouldHideUntilAchieved(this: &v7->IAchievement)
    || (bShouldHide_3 = 1, v7->IsAchieved(this: &v7->IAchievement)) )
  {
    bShouldHide_3 = 0;
  }
  v9 = 1;
  while ( v9 != 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    m_MedalNameHandle = this->m_MedalNameHandle;
    if ( m_MedalNameHandle != nullptr )
    {
      if ( v7 != nullptr )
      {
        if ( bShouldHide_3 != 0 )
        {
          ((void (__stdcall *)(void *, const char *))this->m_pScaleformUI->Value_SetText_2)(
            a1: m_MedalNameHandle,
            a2: "#SFUI_MedalsInfo_LockedName");
        }
        else
        {
          v12 = v7->GetName(this: &v7->IAchievement);
          v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "#%s_NAME", v12);
          v14 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v13->m_szBuf);
          m_pScaleformUI = this->m_pScaleformUI;
          if ( v14 != nullptr )
            m_pScaleformUI->Value_SetText(this: m_pScaleformUI, a2: this->m_MedalNameHandle, a3: v14);
          else
            ((void (__stdcall *)(void *, const char *))m_pScaleformUI->Value_SetText_2)(
              a1: this->m_MedalNameHandle,
              a2: "#SFUI_MedalsInfo_Invalid");
        }
      }
      else
      {
        v11 = prType;
        if ( !bClearFields_3 )
          v11 = "#SFUI_MedalsInfo_Invalid";
        ((void (__stdcall *)(void *, const char *))this->m_pScaleformUI->Value_SetText_2)(
          a1: m_MedalNameHandle,
          a2: v11);
      }
    }
    m_MedalUnlockHandle = this->m_MedalUnlockHandle;
    if ( m_MedalUnlockHandle != nullptr )
    {
      if ( v7 != nullptr )
      {
        if ( bShouldHide_3 != 0 )
        {
          ((void (__stdcall *)(void *, const char *))this->m_pScaleformUI->Value_SetText_2)(
            a1: m_MedalUnlockHandle,
            a2: "#SFUI_MedalsInfo_LockedDate");
        }
        else
        {
          V_wcsncpy(pDest: achDate, pSrc: L"#SFUI_MedalsInfo_LockedDate", maxLenInBytes: 0x800u);
          if ( v7->IsAchieved(this: &v7->IAchievement) )
          {
            if ( ClientModeShared::OverrideRenderBounds(
                   this: (ClientModeShared *)v7,
                   x: &year,
                   y: &month,
                   w: &day,
                   h: &hour,
                   insetX: &minute,
                   insetY: &second) )
            {
              V_snwprintf(pDest: achDate, maxLen: 1024, pFormat: L"%4d-%02d-%02d", year, month, day);
            }
            else
            {
              V_wcsncpy(pDest: achDate, pSrc: L"#SFUI_MedalsInfo_Unlocked", maxLenInBytes: 0x800u);
            }
          }
          ((void (__stdcall *)(void *, wchar_t *))this->m_pScaleformUI->Value_SetText)(
            a1: this->m_MedalUnlockHandle,
            a2: achDate);
        }
      }
      else
      {
        v17 = prType;
        if ( !bClearFields_3 )
          v17 = "#SFUI_MedalsInfo_Invalid";
        this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_MedalUnlockHandle, a3: v17);
      }
    }
    m_MedalDescHandle = this->m_MedalDescHandle;
    if ( m_MedalDescHandle != nullptr )
    {
      if ( v7 != nullptr )
      {
        if ( bShouldHide_3 != 0 )
        {
          this->m_pScaleformUI->Value_SetText_2(
            this: this->m_pScaleformUI,
            a2: m_MedalDescHandle,
            a3: "#SFUI_MedalsInfo_LockedDesc");
          v9 = 0;
        }
        else
        {
          v20 = (const char *)((int (__thiscall *)(IAchievement *, void *, const char *))v7->GetName)(
                                a1: &v7->IAchievement,
                                a2: a3,
                                a3: a2);
          v21 = CFmtStrN<256>::CFmtStrN<256>(this: &v27, pszFormat: "#%s_DESC", v20);
          v22 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v21->m_szBuf);
          v23 = this->m_pScaleformUI;
          if ( v22 == nullptr )
          {
            a2 = "#SFUI_MedalsInfo_Invalid";
            a3 = this->m_MedalDescHandle;
            ((void (__thiscall *)(IScaleformUI *))v23->Value_SetText_2)(a1: v23);
            goto LABEL_44;
          }
          a2 = (const char *)v22;
          a3 = this->m_MedalDescHandle;
          ((void (__thiscall *)(IScaleformUI *))v23->Value_SetText)(a1: v23);
          v9 = 0;
        }
      }
      else
      {
        v19 = prType;
        if ( !bClearFields_3 )
          v19 = "#SFUI_MedalsInfo_Invalid";
        this->m_pScaleformUI->Value_SetText_2(this: this->m_pScaleformUI, a2: m_MedalDescHandle, a3: v19);
        v9 = 0;
      }
    }
    else
    {
LABEL_44:
      v9 = 0;
    }
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
LABEL_47:
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020D5E0
// Name: public: void CCreateMedalStatsDialogScaleform::GetRecentAchievementName(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::GetRecentAchievementName(
        CCreateMedalStatsDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  int v4; // eax
  CCSBaseAchievement *v5; // eax
  IScaleformUI_vtbl *v6; // ebx
  int v7; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  v4 = (int)pui->Params_GetArgAsNumber(this: pui, a2: obj, a3: 0);
  if ( v4 < this->m_recentAchievements.m_Size && (v5 = this->m_recentAchievements.m_Memory.m_pMemory[v4]) != nullptr )
  {
    v6 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
    v7 = (int)v5->GetName(this: &v5->IAchievement);
    v6->Params_SetResult_2(this: this->m_pScaleformUI, a2: obj, a3: (const char *)v7);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  else
  {
    this->m_pScaleformUI->Params_SetResult(this: this->m_pScaleformUI, a2: obj, a3: &szFunFact);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020D6F0
// Name: public: void CCreateMedalStatsDialogScaleform::GetAchievementStatus(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::GetAchievementStatus(
        CCreateMedalStatsDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  const char *v4; // eax
  CBaseAchievement *AchievementByName; // eax
  CCSBaseAchievement *v6; // eax
  CCSBaseAchievement *v7; // ebx
  int v8; // edi
  int m_Size; // ecx
  int v10; // eax
  CCSBaseAchievement **m_pMemory; // edx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  v4 = pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
  AchievementByName = CAchievementMgr::GetAchievementByName(
                        this: &g_AchievementMgrCS,
                        pchName: v4,
                        nUserSlot: this->m_iPlayerSlot);
  v6 = (CCSBaseAchievement *)__RTDynamicCast(
                               inptr: AchievementByName,
                               VfDelta: 0,
                               SrcType: &CBaseAchievement `RTTI Type Descriptor',
                               TargetType: &CCSBaseAchievement `RTTI Type Descriptor',
                               isReference: 0);
  v7 = v6;
  v8 = 0;
  if ( v6 != nullptr )
  {
    if ( ((unsigned __int8 (*)(void))v6->IsAchieved)() != 0 )
    {
      m_Size = this->m_recentAchievements.m_Size;
      v10 = 0;
      if ( m_Size <= 0 )
        goto LABEL_7;
      m_pMemory = this->m_recentAchievements.m_Memory.m_pMemory;
      while ( *m_pMemory != v7 )
      {
        ++v10;
        ++m_pMemory;
        if ( v10 >= m_Size )
          goto LABEL_7;
      }
      if ( v10 >= 0 && IsRecentUnlock(pAchievement: v7) )
        v8 = 3;
      else
LABEL_7:
        v8 = 1;
    }
    else if ( v7->ShouldHideUntilAchieved(this: &v7->IAchievement) )
    {
      v8 = 2;
    }
  }
  this->m_pScaleformUI->Params_SetResult_5(this: this->m_pScaleformUI, a2: obj, a3: v8);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x1020D7D0
// Name: protected: virtual void CCreateMedalStatsDialogScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::PostUnloadFlash(CCreateMedalStatsDialogScaleform *this)
{
  CGameUI *v2; // eax
  CCStrike15BasePanel *v3; // ecx
  CCStrike15BasePanel *v4; // ecx

  v2 = GameUI();
  if ( v2->IsInLevel(this: v2) )
  {
    v3 = BasePanel();
    v3->RestorePauseMenu(this: v3);
  }
  else
  {
    v4 = BasePanel();
    v4->RestoreMainMenuScreen(this: v4);
  }
  this->m_recentAchievements.m_Size = 0;
  if ( this->m_recentAchievements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_recentAchievements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_recentAchievements.m_Memory.m_pMemory);
      this->m_recentAchievements.m_Memory.m_pMemory = nullptr;
    }
    this->m_recentAchievements.m_Memory.m_nAllocationCount = 0;
  }
  this->m_recentAchievements.m_pElements = this->m_recentAchievements.m_Memory.m_pMemory;
  CCreateMedalStatsDialogScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CCreateMedalStatsDialogScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020D850
// Name: protected: CCreateMedalStatsDialogScaleform::CCreateMedalStatsDialogScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CCreateMedalStatsDialogScaleform *__thiscall CCreateMedalStatsDialogScaleform::CCreateMedalStatsDialogScaleform(
        CCreateMedalStatsDialogScaleform *this)
{
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (CCreateMedalStatsDialogScaleform_vtbl *)&CCreateMedalStatsDialogScaleform::`vftable';
  this->m_MedalNameHandle = nullptr;
  this->m_MedalUnlockHandle = nullptr;
  this->m_MedalDescHandle = nullptr;
  this->m_recentAchievements.m_Memory.m_pMemory = nullptr;
  this->m_recentAchievements.m_Memory.m_nAllocationCount = 0;
  this->m_recentAchievements.m_Memory.m_nGrowSize = 0;
  this->m_recentAchievements.m_Size = 0;
  this->m_recentAchievements.m_pElements = nullptr;
  this->m_LastMatchTeamStats = nullptr;
  this->m_LastMatchFaveWeaponName = nullptr;
  this->m_LastMatchFaveWeaponStats = nullptr;
  this->m_LastMatchPerfStats = nullptr;
  this->m_LastMatchMiscStats = nullptr;
  this->m_OverallPlayerName = nullptr;
  this->m_OverallMVPsText = nullptr;
  this->m_OverallPlayerStats = nullptr;
  this->m_OverallFaveWeaponName = nullptr;
  this->m_OverallFaveWeaponStats = nullptr;
  this->m_OverallFaveMapStats = nullptr;
  this->m_iPlayerSlot = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020D8B0
// Name: protected: void CCreateMedalStatsDialogScaleform::GenerateRecentAchievements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMedalStatsDialogScaleform::GenerateRecentAchievements(CCreateMedalStatsDialogScaleform *this)
{
  int AchievementCount; // edi
  CCSBaseAchievement **m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  CCSBaseAchievement **v5; // eax
  int v6; // eax
  IAchievement *AchievementByIndex; // eax
  CCSBaseAchievement *v8; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CCSBaseAchievement **v11; // ecx
  int v12; // eax
  CCSBaseAchievement **v13; // eax
  int v14; // eax
  int i; // [esp+10h] [ebp-8h]
  int iCount; // [esp+14h] [ebp-4h]

  AchievementCount = CAchievementMgr::GetAchievementCount(this: &g_AchievementMgrCS, bAssets: false);
  this->m_recentAchievements.m_Size = 0;
  iCount = AchievementCount;
  if ( this->m_recentAchievements.m_Memory.m_nAllocationCount < AchievementCount
    && this->m_recentAchievements.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_recentAchievements.m_Memory.m_pMemory;
    this->m_recentAchievements.m_Memory.m_nAllocationCount = AchievementCount;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = (CCSBaseAchievement **)((int (__stdcall *)(CCSBaseAchievement **, int))v4->Realloc_2)(
                                    a1: m_pMemory,
                                    a2: 4 * AchievementCount);
    else
      v5 = (CCSBaseAchievement **)((int (__stdcall *)(int))v4->Alloc_2)(a1: 4 * AchievementCount);
    this->m_recentAchievements.m_Memory.m_pMemory = v5;
  }
  v6 = 0;
  this->m_recentAchievements.m_pElements = this->m_recentAchievements.m_Memory.m_pMemory;
  for ( i = 0; v6 < AchievementCount; i = v6 )
  {
    AchievementByIndex = CAchievementMgr::GetAchievementByIndex(
                           this: &g_AchievementMgrCS,
                           index: v6,
                           nUserSlot: this->m_iPlayerSlot);
    if ( AchievementByIndex != nullptr )
    {
      v8 = (CCSBaseAchievement *)&AchievementByIndex[-3];
      if ( AchievementByIndex != (IAchievement *)12 && AchievementByIndex->IsAchieved(this: AchievementByIndex) )
      {
        m_Size = this->m_recentAchievements.m_Size;
        m_nAllocationCount = this->m_recentAchievements.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_recentAchievements,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_recentAchievements.m_Size;
        v11 = this->m_recentAchievements.m_Memory.m_pMemory;
        v12 = this->m_recentAchievements.m_Size - m_Size - 1;
        this->m_recentAchievements.m_pElements = v11;
        if ( v12 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v11[m_Size + 1], src: (unsigned __int8 *)&v11[m_Size], count: 4 * v12);
        v13 = &this->m_recentAchievements.m_Memory.m_pMemory[m_Size];
        AchievementCount = iCount;
        if ( v13 != nullptr )
          *v13 = v8;
      }
    }
    v6 = i + 1;
  }
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&this->m_recentAchievements,
    pfnCompare: (int (__cdecl *)(const void *, const void *))AchievementDateSortPredicate);
  v14 = this->m_recentAchievements.m_Size;
  if ( v14 > 32 )
    this->m_recentAchievements.m_Size -= v14 - 32;
}

//------------------------------------------------------------------------------
// Address: 0x1020D9E0
// Name: public: static void CCreateMedalStatsDialogScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateMedalStatsDialogScaleform::LoadDialog()
{
  CCreateMedalStatsDialogScaleform *v0; // eax
  CCreateMedalStatsDialogScaleform *v1; // eax

  if ( CCreateMedalStatsDialogScaleform::m_pInstance == nullptr )
  {
    v0 = (CCreateMedalStatsDialogScaleform *)MemAlloc_Alloc(nSize: 0x64u);
    if ( v0 != nullptr )
      v1 = CCreateMedalStatsDialogScaleform::CCreateMedalStatsDialogScaleform(this: v0);
    else
      v1 = nullptr;
    CCreateMedalStatsDialogScaleform::m_pInstance = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "MedalStatsScreen",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CCreateMedalStatsDialogScaleform_MedalStatsScreen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020DA80
// Name: protected: virtual void CCreateMedalStatsDialogScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCreateMedalStatsDialogScaleform::FlashReady(
        CCreateMedalStatsDialogScaleform *this@<ecx>,
        int a2@<esi>)
{
  void *v3; // ebx
  void *v4; // esi
  void *v5; // ebx
  void *v6; // eax
  void *v7; // eax
  void *v8; // ebx
  void *v9; // ebx
  void *v10; // esi
  void *v11; // ebx
  void *v12; // ebx
  void *v13; // esi
  void *v14; // eax
  void *v15; // ebx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-14h] BYREF
  void *PanelHandle; // [esp+Ch] [ebp-10h]
  void *AnimatedOverallPanel; // [esp+10h] [ebp-Ch]
  void *AnimatedMedalPanel; // [esp+14h] [ebp-8h]
  void *AnimatedPanelHandle; // [esp+18h] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iPlayerSlot);
  v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "Panel");
  PanelHandle = v3;
  if ( v3 != nullptr )
  {
    v4 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                   a1: this->m_pScaleformUI,
                   a2: v3,
                   a3: "Panel",
                   a4: a2);
    AnimatedPanelHandle = v4;
    if ( v4 != nullptr )
    {
      v5 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "Medals");
      AnimatedOverallPanel = v5;
      if ( v5 != nullptr )
      {
        v6 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v5, a3: "Medals");
        AnimatedMedalPanel = v6;
        if ( v6 != nullptr )
        {
          v7 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v6, a3: "Text");
          v8 = v7;
          if ( v7 != nullptr )
          {
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v7,
              elementName: "MedalName",
              textElementName: "MedalName",
              sfv: &this->m_MedalNameHandle);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v8,
              elementName: "MedalUnlockDate",
              textElementName: "MedalUnlockDate",
              sfv: &this->m_MedalUnlockHandle);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v8,
              elementName: "MedalDesc",
              textElementName: "MedalDesc",
              sfv: &this->m_MedalDescHandle);
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v8);
            v4 = AnimatedPanelHandle;
          }
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: AnimatedMedalPanel);
          v5 = AnimatedOverallPanel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v5);
      }
      v9 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "LastMatch");
      AnimatedMedalPanel = v9;
      if ( v9 != nullptr )
      {
        v10 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "LastMatch");
        AnimatedOverallPanel = v10;
        if ( v10 != nullptr )
        {
          v11 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v10, a3: "Text");
          if ( v11 != nullptr )
          {
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v11,
              elementName: "TeamData",
              textElementName: "TeamData",
              sfv: &this->m_LastMatchTeamStats);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v11,
              elementName: "FavoriteWeaponName",
              textElementName: "FavoriteWeaponName",
              sfv: &this->m_LastMatchFaveWeaponName);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v11,
              elementName: "WeaponData",
              textElementName: "WeaponData",
              sfv: &this->m_LastMatchFaveWeaponStats);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v11,
              elementName: "PerformanceData",
              textElementName: "PerformanceData",
              sfv: &this->m_LastMatchPerfStats);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v11,
              elementName: "MiscData",
              textElementName: "MiscData",
              sfv: &this->m_LastMatchMiscStats);
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v11);
            v10 = AnimatedOverallPanel;
          }
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v10);
          v9 = AnimatedMedalPanel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v9);
        v4 = AnimatedPanelHandle;
      }
      v12 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "OverAll");
      AnimatedMedalPanel = v12;
      if ( v12 != nullptr )
      {
        v13 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v12, a3: "OverAll");
        AnimatedOverallPanel = v13;
        if ( v13 != nullptr )
        {
          v14 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v13, a3: "Text");
          v15 = v14;
          if ( v14 != nullptr )
          {
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v14,
              elementName: "PlayerName",
              textElementName: "PlayerName",
              sfv: &this->m_OverallPlayerName);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v15,
              elementName: "Stars",
              textElementName: "Stars",
              sfv: &this->m_OverallMVPsText);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v15,
              elementName: "PlayerData",
              textElementName: "PlayerData",
              sfv: &this->m_OverallPlayerStats);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v15,
              elementName: "WeaponName",
              textElementName: "WeaponName",
              sfv: &this->m_OverallFaveWeaponName);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v15,
              elementName: "WeaponData",
              textElementName: "WeaponData",
              sfv: &this->m_OverallFaveWeaponStats);
            GetTextBoxForElement(
              pScaleformUI: this->m_pScaleformUI,
              root: v15,
              elementName: "MapDescription",
              textElementName: "MapDescription",
              sfv: &this->m_OverallFaveMapStats);
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v15);
            v13 = AnimatedOverallPanel;
          }
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v13);
          v12 = AnimatedMedalPanel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v12);
        v4 = AnimatedPanelHandle;
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v4);
      v3 = PanelHandle;
    }
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v3);
  }
  CCreateMedalStatsDialogScaleform::PopulateLastMatchStats(this);
  CCreateMedalStatsDialogScaleform::PopulateOverallStats(this, a2: (int)v3, a3: (int)this);
  CCreateMedalStatsDialogScaleform::GenerateRecentAchievements(this);
  CCreateMedalStatsDialogScaleform::Show((CCreateLeaderboardsDialogScaleform *)this);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}
