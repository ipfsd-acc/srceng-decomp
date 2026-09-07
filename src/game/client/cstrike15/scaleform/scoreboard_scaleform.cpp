// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/scoreboard_scaleform.cpp
// Functions: 48
// ============================================================

#include "game\client\cstrike15\scaleform\scoreboard_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1013F720
// Name: private: virtual void CScoreboardScaleform::SetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::SetParent(vgui::TreeView *this, int itemIndex)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1020F6F0
// Name: public: void CScoreboardScaleform::OnGetHalf(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::OnGetHalf(CScoreboardScaleform *this, IScaleformUI *pui, void *obj)
{
  int v3; // eax

  v3 = 1;
  if ( this->m_bGameOver )
  {
    v3 = 4;
  }
  else if ( this->m_bHalftime )
  {
    v3 = 2;
  }
  else if ( this->m_bSecondHalf )
  {
    v3 = 3;
  }
  this->m_pScaleformUI->Params_SetResult_5(this: this->m_pScaleformUI, a2: obj, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020F740
// Name: public: void CScoreboardScaleform::ToggleVote(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::ToggleVote(CScoreboardScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  C_CSPlayer *LocalPlayer; // esi
  C_CS_PlayerResource *v4; // esi
  int LocalPlayerIndex; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 0
    && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 1
    && LocalPlayer->m_currentVoteIssue != VoteType_None
    && g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework) )
  {
    v4 = (C_CS_PlayerResource *)__RTDynamicCast(
                                  inptr: g_PR,
                                  VfDelta: 0,
                                  SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                  TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                  isReference: 0);
    if ( v4 != nullptr )
    {
      LocalPlayerIndex = GetLocalPlayerIndex();
      if ( !C_CS_PlayerResource::GetVote(this: v4, iIndex: LocalPlayerIndex) )
        engine->ClientCmd(this: engine, a2: "player_vote 1");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F7E0
// Name: public: void CScoreboardScaleform::FlashHide(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::FlashHide(CScoreboardScaleform *this, IScaleformUI *pui, void *obj)
{
  IViewPort *ViewPortInterface; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+0h] [ebp-4h] BYREF

  g_UISSGuard.m_nSaveSlot = (int)this;
  if ( *(float *)(gpGlobals.m_Index + 12) > this->m_fGuardTime )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iFlashSlot - 2);
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: false);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F830
// Name: protected: static int CScoreboardScaleform::PlayerSortFunction(class ScoreboardEntry const __near *,class ScoreboardEntry const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CScoreboardScaleform::PlayerSortFunction(const ScoreboardEntry *entry1, const ScoreboardEntry *entry2)
{
  int m_playerIndex; // esi
  int v4; // edx
  int m_deaths; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int sortValues2[5]; // [esp+4h] [ebp-28h]
  int sortValues1[5]; // [esp+18h] [ebp-14h]

  m_playerIndex = entry1->m_playerIndex;
  if ( m_playerIndex == -1 )
    return 1;
  v4 = entry2->m_playerIndex;
  if ( v4 != -1 )
  {
    sortValues1[0] = entry1->m_killPoints;
    sortValues2[0] = entry2->m_killPoints;
    sortValues1[1] = entry1->m_contributionScore;
    sortValues2[1] = entry2->m_contributionScore;
    m_deaths = entry1->m_deaths;
    sortValues1[2] = entry1->m_kills;
    v6 = entry2->m_deaths;
    sortValues2[2] = entry2->m_kills;
    sortValues2[3] = v6;
    sortValues1[3] = m_deaths;
    sortValues1[4] = m_playerIndex;
    sortValues2[4] = v4;
    v7 = 0;
    while ( 1 )
    {
      v8 = sortValues1[v7];
      v9 = sortValues2[v7];
      if ( v8 > v9 )
        break;
      if ( v8 < v9 )
        return 1;
      if ( ++v7 >= 5 )
        return 0;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1020F8F0
// Name: protected: void CScoreboardScaleform::PopulateHalfTimeScores(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScoreboardScaleform::PopulateHalfTimeScores(CScoreboardScaleform *this@<ecx>, int a2@<edi>)
{
  C_Team *GlobalTeam; // ebx
  C_Team *v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  ISFTextObject *m_hTeam1ScoreFirstHalf; // ecx

  GlobalTeam = GetGlobalTeam(iTeamNumber: 2);
  v4 = GetGlobalTeam(iTeamNumber: 3);
  if ( GlobalTeam != nullptr && v4 != nullptr )
  {
    v5 = ((int (__thiscall *)(C_Team *, int))v4->Get_Score)(a1: v4, a2);
    v6 = GlobalTeam->Get_Score(this: GlobalTeam);
    v7 = v6;
    if ( !this->m_bSecondHalf || this->m_bHalftime )
    {
      m_hTeam1ScoreFirstHalf = this->m_hTeam1ScoreFirstHalf;
      this->m_nTeam1FirstHalfScore = v5;
      this->m_nTeam2FirstHalfScore = v6;
      ((void (__thiscall *)(ISFTextObject *))m_hTeam1ScoreFirstHalf->SetText_4)(a1: m_hTeam1ScoreFirstHalf);
      this->m_hTeam2ScoreFirstHalf->SetText_4(this: this->m_hTeam2ScoreFirstHalf, a2: this->m_nTeam2FirstHalfScore);
      this->m_hTeam1ScoreSecondHalf->SetText(this: this->m_hTeam1ScoreSecondHalf, a2: L"0");
      this->m_hTeam2ScoreSecondHalf->SetText(this: this->m_hTeam2ScoreSecondHalf, a2: L"0");
      this->m_hTeam1ScoreTotal->SetText_4(this: this->m_hTeam1ScoreTotal, a2: this->m_nTeam1FirstHalfScore);
      this->m_hTeam2ScoreTotal->SetText_4(this: this->m_hTeam2ScoreTotal, a2: this->m_nTeam2FirstHalfScore);
    }
    else
    {
      this->m_hTeam1ScoreSecondHalf->SetText_4(
        this: this->m_hTeam1ScoreSecondHalf,
        a2: v6 - this->m_nTeam1FirstHalfScore);
      this->m_hTeam2ScoreSecondHalf->SetText_4(
        this: this->m_hTeam2ScoreSecondHalf,
        a2: v5 - this->m_nTeam2FirstHalfScore);
      this->m_hTeam1ScoreFirstHalf->SetText_4(this: this->m_hTeam1ScoreFirstHalf, a2: this->m_nTeam1FirstHalfScore);
      this->m_hTeam2ScoreFirstHalf->SetText_4(this: this->m_hTeam2ScoreFirstHalf, a2: this->m_nTeam2FirstHalfScore);
      this->m_hTeam2ScoreTotal->SetText_4(this: this->m_hTeam2ScoreTotal, a2: v5);
      this->m_hTeam1ScoreTotal->SetText_4(this: this->m_hTeam1ScoreTotal, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FA40
// Name: private: void CScoreboardScaleform::PopulateTeamInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulateTeamInfo(CScoreboardScaleform *this)
{
  C_Team *GlobalTeam; // edi
  C_Team *v3; // ebx
  int v4; // eax
  ISFTextObject_vtbl *v5; // edi
  int v6; // eax
  ISFTextObject_vtbl *v7; // [esp+Ch] [ebp-4h]

  GlobalTeam = GetGlobalTeam(iTeamNumber: 2);
  v3 = GetGlobalTeam(iTeamNumber: 3);
  if ( !C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules)
    || (unsigned __int8)C_CSGameRules::IsPlayingGunGameSelect(this: (C_CSGameRules *)g_pGameRules) != 0 )
  {
    if ( this->m_hTScore != nullptr && GlobalTeam != nullptr )
    {
      v7 = this->m_hTScore->__vftable;
      v4 = GlobalTeam->Get_Score(this: GlobalTeam);
      v7->SetText_4(this: this->m_hTScore, a2: v4);
    }
    if ( this->m_hCTScore != nullptr && v3 != nullptr )
    {
      v5 = this->m_hCTScore->__vftable;
      v6 = v3->Get_Score(this: v3);
      v5->SetText_4(this: this->m_hCTScore, a2: v6);
    }
  }
  else if ( !C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules)
         && C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules) )
  {
    if ( this->m_hTScore != nullptr )
      this->m_hTScore->SetText_2(this: this->m_hTScore, a2: prType);
    if ( this->m_hCTScore != nullptr )
      this->m_hCTScore->SetText_2(this: this->m_hCTScore, a2: prType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FB50
// Name: private: void CScoreboardScaleform::PopulateGameType(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulateGameType(CScoreboardScaleform *this)
{
  const unsigned __int16 *v2; // esi
  const char *v3; // eax
  wchar_t *v4; // ebx
  const char *v5; // eax
  unsigned int v6; // edx
  wchar_t *v7; // eax
  __int16 v8; // cx
  int v9; // edi
  wchar_t *v10; // esi
  wchar_t *gameTypeString; // [esp+8h] [ebp-4h]

  if ( this->m_hGameType != nullptr )
  {
    v2 = nullptr;
    gameTypeString = nullptr;
    v3 = g_pGameTypes->GetCurrentGameTypeNameID(this: g_pGameTypes);
    if ( v3 != nullptr )
    {
      gameTypeString = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v3);
      v2 = gameTypeString;
    }
    v4 = nullptr;
    v5 = g_pGameTypes->GetCurrentGameModeNameID(this: g_pGameTypes);
    if ( v5 != nullptr )
      v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v5);
    if ( v2 != nullptr )
    {
      if ( v4 != nullptr )
      {
        v6 = wcslen(v2);
        v7 = v4;
        do
          v8 = *v7++;
        while ( v8 != 0 );
        v9 = v7 - (v4 + 1) + v6 + 4;
        v10 = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v9 >> 31 != 0 ? -1 : 2 * v9);
        V_snwprintf(pDest: v10, maxLen: v9, pFormat: L"%s - %s", gameTypeString, v4);
        this->m_hGameType->SetText(this: this->m_hGameType, a2: v10);
        C_BaseEntity::operator delete(pMem: v10);
      }
      else
      {
        this->m_hGameType->SetText_2(this: this->m_hGameType, a2: "Missing Game Mode");
      }
    }
    else
    {
      this->m_hGameType->SetText_2(this: this->m_hGameType, a2: "Missing Game Type");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FC70
// Name: private: void CScoreboardScaleform::PopulateTeamCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulateTeamCount(CScoreboardScaleform *this, int teamId)
{
  C_Team *GlobalTeam; // eax
  C_Team *v4; // esi
  int v5; // eax
  bool v6; // zf
  const char *v7; // eax
  const wchar_t *v8; // eax
  wchar_t labelText[128]; // [esp+Ch] [ebp-120h] BYREF
  wchar_t countText[16]; // [esp+10Ch] [ebp-20h] BYREF

  GlobalTeam = GetGlobalTeam(iTeamNumber: teamId);
  v4 = GlobalTeam;
  if ( GlobalTeam != nullptr )
  {
    countText[0] = 0;
    v5 = GlobalTeam->GetNumPlayers(this: GlobalTeam);
    V_snwprintf(pDest: countText, maxLen: 16, pFormat: L"%i", v5);
    countText[15] = 0;
    v6 = v4->GetNumPlayers(this: v4) == 1;
    v7 = "#SFUI_Scoreboard_Player";
    if ( !v6 )
      v7 = "#SFUI_Scoreboard_Players";
    v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v7);
    if ( v8 != nullptr )
    {
      g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: labelText, a3: 256, a4: v8, a5: 1, countText);
      if ( teamId == 2 )
      {
        if ( this->m_hNumTs != nullptr )
          this->m_hNumTs->SetText(this: this->m_hNumTs, a2: labelText);
      }
      else if ( teamId == 3 && this->m_hNumCTs != nullptr )
      {
        this->m_hNumCTs->SetText(this: this->m_hNumCTs, a2: labelText);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FD70
// Name: private: void CScoreboardScaleform::DisplayRemainingRounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::DisplayRemainingRounds(CScoreboardScaleform *this, int remainingRounds)
{
  vgui::ILocalize_vtbl *v3; // edi
  wchar_t *v4; // eax
  wchar_t wszMessage[128]; // [esp+8h] [ebp-120h] BYREF
  wchar_t wszRounds[16]; // [esp+108h] [ebp-20h] BYREF

  wszMessage[0] = 0;
  V_snwprintf(pDest: wszRounds, maxLen: 16, pFormat: L"%d", remainingRounds);
  v3 = g_pVGuiLocalize->__vftable;
  v4 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUI_Scoreboard_RoundsLeft");
  ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, wchar_t *))v3->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: wszMessage,
    a3: 256,
    a4: v4);
  if ( this->m_hRoundsLeft != nullptr )
  {
    this->m_hRoundsLeft->SetVisible(this: this->m_hRoundsLeft, a2: true);
    this->m_hRoundsLeft->SetText(this: this->m_hRoundsLeft, a2: wszMessage);
  }
  if ( this->m_hTimeLeft != nullptr )
    this->m_hTimeLeft->SetVisible(this: this->m_hTimeLeft, a2: false);
  if ( this->m_hTimerIcon != nullptr )
    this->m_hTimerIcon->SetVisible(this: this->m_hTimerIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020FE30
// Name: private: void CScoreboardScaleform::DisplayRemainingTime(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::DisplayRemainingTime(
        CScoreboardScaleform *this,
        int remainingTime,
        const char *localizationStringId)
{
  vgui::ILocalize_vtbl *v4; // edi
  wchar_t *v5; // eax
  wchar_t wszMessage[128]; // [esp+8h] [ebp-120h] BYREF
  wchar_t wszTime[16]; // [esp+108h] [ebp-20h] BYREF

  wszMessage[0] = 0;
  V_snwprintf(pDest: wszTime, maxLen: 16, pFormat: L"%.2i:%.2i", remainingTime / 60, remainingTime % 60);
  v4 = g_pVGuiLocalize->__vftable;
  v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: localizationStringId);
  ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, wchar_t *))v4->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: wszMessage,
    a3: 256,
    a4: v5);
  if ( this->m_hRoundsLeft != nullptr )
    this->m_hRoundsLeft->SetVisible(this: this->m_hRoundsLeft, a2: false);
  if ( this->m_hTimeLeft != nullptr )
  {
    this->m_hTimeLeft->SetVisible(this: this->m_hTimeLeft, a2: true);
    this->m_hTimeLeft->SetText(this: this->m_hTimeLeft, a2: wszMessage);
  }
  if ( this->m_hTimerIcon != nullptr )
    this->m_hTimerIcon->SetVisible(this: this->m_hTimerIcon, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1020FF10
// Name: private: void CScoreboardScaleform::HideMatchEndConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::HideMatchEndConditions(CScoreboardScaleform *this)
{
  if ( this->m_hRoundsLeft != nullptr )
    this->m_hRoundsLeft->SetVisible(this: this->m_hRoundsLeft, a2: false);
  if ( this->m_hTimeLeft != nullptr )
    this->m_hTimeLeft->SetVisible(this: this->m_hTimeLeft, a2: false);
  if ( this->m_hTimerIcon != nullptr )
    this->m_hTimerIcon->SetVisible(this: this->m_hTimerIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020FF60
// Name: private: void CScoreboardScaleform::UpdateSpectators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::UpdateSpectators(CScoreboardScaleform *this)
{
  char *v1; // eax
  int v2; // esi
  int v3; // edi
  char *v4; // ebx
  ISFTextObject *m_hSpectator1; // esi
  const char *v6; // eax
  CScoreboardScaleform *v7; // edi
  const char *v8; // eax
  const wchar_t *v9; // eax
  wchar_t wide_name[702]; // [esp+0h] [ebp-6A4h] BYREF
  wchar_t labelText[128]; // [esp+57Ch] [ebp-128h] BYREF
  wchar_t countText[16]; // [esp+67Ch] [ebp-28h] BYREF
  int nSpectators; // [esp+69Ch] [ebp-8h]
  CScoreboardScaleform *v14; // [esp+6A0h] [ebp-4h]

  v14 = this;
  v1 = (char *)__RTDynamicCast(
                 inptr: g_PR,
                 VfDelta: 0,
                 SrcType: &C_PlayerResource `RTTI Type Descriptor',
                 TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                 isReference: 0);
  if ( v1 == nullptr )
    return;
  v2 = 0;
  v3 = 1;
  v4 = v1 + 2432;
  do
  {
    if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*(_DWORD *)v4 + 16))(a1: v4, a2: v3) != 0
      && (unsigned int)(*(int (__thiscall **)(char *, int))(*(_DWORD *)v4 + 52))(a1: v4, a2: v3) <= 1 )
    {
      nSpectators = ++v2;
      if ( v2 == 1 )
      {
        m_hSpectator1 = v14->m_hSpectator1;
      }
      else
      {
        if ( v2 != 2 )
          goto LABEL_12;
        m_hSpectator1 = v14->m_hSpectator2;
      }
      if ( m_hSpectator1 != nullptr )
      {
        wide_name[0] = 0;
        v6 = g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: v3);
        _V_UTF8ToUnicode(a1: v6, a2: wide_name, a3: 1404);
        m_hSpectator1->SetText(this: m_hSpectator1, a2: wide_name);
      }
      v2 = nSpectators;
    }
LABEL_12:
    ++v3;
  }
  while ( v3 <= 64 );
  v7 = v14;
  if ( v14->m_hSpectator1 != nullptr && v2 == 0 )
    v14->m_hSpectator1->SetText_2(this: v14->m_hSpectator1, a2: prType);
  if ( v7->m_hSpectator2 != nullptr && v2 <= 1 )
    v7->m_hSpectator2->SetText_2(this: v7->m_hSpectator2, a2: prType);
  countText[0] = 0;
  V_snwprintf(pDest: countText, maxLen: 16, pFormat: L"%i", v2);
  countText[15] = 0;
  v8 = "#SFUI_Scoreboard_Spectator";
  if ( v2 != 1 )
    v8 = "#SFUI_Scoreboard_Spectators";
  v9 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v8);
  if ( v9 != nullptr )
  {
    g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: labelText, a3: 256, a4: v9, a5: 1, countText);
    if ( v7->m_hNumSpectators != nullptr )
      v7->m_hNumSpectators->SetText(this: v7->m_hNumSpectators, a2: labelText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210110
// Name: protected: virtual void CScoreboardScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PostUnloadFlash(CScoreboardScaleform *this)
{
  this->m_bLoading = false;
  this->m_bSecondHalf = false;
}

//------------------------------------------------------------------------------
// Address: 0x10210120
// Name: private: wchar_t const __near * CScoreboardScaleform::GetMapName(void)
// Source: json
//------------------------------------------------------------------------------
const wchar_t *__thiscall CScoreboardScaleform::GetMapName(CScoreboardScaleform *this)
{
  const char *v1; // eax
  _BYTE *v2; // eax
  char mapLookup[44]; // [esp+0h] [ebp-50h] BYREF
  char mapName[36]; // [esp+2Ch] [ebp-24h] BYREF

  mapName[0] = 0;
  v1 = engine->GetLevelName(this: engine);
  V_FileBase(in: v1, out: mapName, maxlen: 33);
  _V_strstr(s1: mapName, search: ".360");
  if ( v2 != nullptr )
    *v2 = 0;
  mapLookup[0] = 0;
  V_snprintf(pDest: mapLookup, maxLen: 0x2Bu, pFormat: "#SFUI_Map_%s", mapName);
  return g_pScaleformUI->Translate(this: g_pScaleformUI, a2: mapLookup, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102101A0
// Name: private: void CScoreboardScaleform::UpdateNavBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::UpdateNavBar(CScoreboardScaleform *this)
{
  const wchar_t *v2; // edi
  const wchar_t *v3; // eax
  ISFTextObject_vtbl *v4; // edi
  const wchar_t *v5; // eax
  C_CSPlayer *LocalPlayer; // edi
  C_CS_PlayerResource *v7; // ebx
  int LocalPlayerIndex; // eax
  wchar_t navBarText[1024]; // [esp+8h] [ebp-800h] BYREF

  v2 = &szFunFact;
  if ( this->m_showGamerCardButton )
  {
    v2 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "SFUI_Scoreboard_Navigation_Gamer_Card");
    if ( v2 == nullptr )
      v2 = &szFunFact;
  }
  v3 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "SFUI_Scoreboard_Navigation_Common");
  if ( v3 == nullptr )
    v3 = &szFunFact;
  V_snwprintf(pDest: navBarText, maxLen: 1024, pFormat: L"%s%s", v2, v3);
  if ( this->m_hNavBar != nullptr )
  {
    v4 = this->m_hNavBar->__vftable;
    v5 = this->m_pScaleformUI->ReplaceGlyphKeywordsWithHTML_2(this: this->m_pScaleformUI, a2: navBarText, a3: 0);
    v4->SetTextHTML(this: this->m_hNavBar, a2: v5);
  }
  if ( this->m_hNavBarLeft != nullptr )
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    v7 = (C_CS_PlayerResource *)__RTDynamicCast(
                                  inptr: g_PR,
                                  VfDelta: 0,
                                  SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                  TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                  isReference: 0);
    if ( v7 != nullptr
      && LocalPlayer != nullptr
      && LocalPlayer->m_currentVoteIssue != VoteType_None
      && (LocalPlayerIndex = GetLocalPlayerIndex(), !C_CS_PlayerResource::GetVote(this: v7, iIndex: LocalPlayerIndex)) )
    {
      this->m_hNavBarLeft->SetTextHTML_2(this: this->m_hNavBarLeft, a2: "#SFUI_Scoreboard_Navigation_Left");
    }
    else
    {
      this->m_hNavBarLeft->SetTextHTML_2(this: this->m_hNavBarLeft, a2: prType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102102E0
// Name: public: void ScoreboardEntry::SetStatusFromPlayerIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScoreboardEntry::SetStatusFromPlayerIndex(ScoreboardEntry *this, int playerIndex)
{
  ScoreboardEntry *v2; // ebx
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v4; // edi
  int v6; // ebx
  bool v7; // zf
  C_CS_PlayerResource *cs_PR; // [esp+Ch] [ebp-8h]
  char bShowExtraInfo_3; // [esp+1Fh] [ebp+Bh]

  v2 = this;
  cs_PR = (C_CS_PlayerResource *)__RTDynamicCast(
                                   inptr: g_PR,
                                   VfDelta: 0,
                                   SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                   TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                   isReference: 0);
  LocalPlayer = CClientTools::GetLocalPlayer();
  v4 = LocalPlayer;
  if ( cs_PR != nullptr && LocalPlayer != nullptr )
  {
    if ( LocalPlayer->GetTeamNumber(this: LocalPlayer) == 0
      || v4->GetTeamNumber(this: v4) == 1
      || C_BasePlayer::IsPlayerDead(this: v4)
      || (v6 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: playerIndex),
          v7 = v4->GetTeamNumber(this: v4) == v6,
          v2 = this,
          bShowExtraInfo_3 = 0,
          v7) )
    {
      bShowExtraInfo_3 = 1;
    }
    if ( g_PR->IsAlive(this: &g_PR->IGameResources, a2: playerIndex)
      || g_PR->GetTeam(this: &g_PR->IGameResources, a2: playerIndex) <= 1 )
    {
      if ( C_CS_PlayerResource::HasC4(this: cs_PR, iIndex: playerIndex) && bShowExtraInfo_3 != 0 )
      {
        v2->m_status = Bomb;
      }
      else if ( C_CS_PlayerResource::HasDefuser(this: cs_PR, iIndex: playerIndex) && bShowExtraInfo_3 != 0 )
      {
        v2->m_status = Defuser;
      }
      else
      {
        v2->m_status = 0;
      }
    }
    else
    {
      v2->m_status = Dead;
    }
    if ( C_CSPlayer::IsPlayerDominated(this: v4, iPlayerIndex: playerIndex) )
    {
      v2->m_status = 4 - g_PR->IsAlive(this: &g_PR->IGameResources, a2: playerIndex);
    }
    else if ( C_CSPlayer::IsPlayerDominatingMe(this: v4, iPlayerIndex: playerIndex) )
    {
      v2->m_status = 6 - g_PR->IsAlive(this: &g_PR->IGameResources, a2: playerIndex);
    }
  }
  else
  {
    v2->m_status = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102104B0
// Name: public: bool ScoreboardEntry::SetEscapedNameFromRawName(char const __near *,wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScoreboardEntry::SetEscapedNameFromRawName(
        ScoreboardEntry *this,
        const char *name,
        wchar_t *prependedString)
{
  int m_stars; // eax
  wchar_t *v6; // esi
  wchar_t v7; // ax
  wchar_t wide_name[702]; // [esp+4h] [ebp-B8Ch] BYREF
  wchar_t prepended_wide_name[702]; // [esp+580h] [ebp-610h] BYREF
  wchar_t digitSequence[68]; // [esp+AFCh] [ebp-94h] BYREF
  wchar_t numStarsString[6]; // [esp+B84h] [ebp-Ch] BYREF

  if ( name == nullptr )
    return 0;
  wide_name[0] = 0;
  _V_UTF8ToUnicode(a1: name, a2: wide_name, a3: 1404);
  prepended_wide_name[0] = 0;
  if ( prependedString != nullptr )
    wcsncat(front: prepended_wide_name, back: prependedString, count: 0x2BEu);
  wcsncat(front: prepended_wide_name, back: wide_name, count: 0x2BEu);
  g_pScaleformUI->MakeStringSafe(this: g_pScaleformUI, a2: prepended_wide_name, a3: (wchar_t *)this, a4: 702);
  if ( this->m_stars > 0 )
  {
    wcsncat(front: this->m_name, back: L"<img src='Star' width='10' height='10' vspace='3' />", count: 0x2BEu);
    m_stars = this->m_stars;
    if ( m_stars > 1 )
    {
      if ( m_stars > 9999 )
        m_stars = 9999;
      V_snwprintf(pDest: numStarsString, maxLen: 5, pFormat: L"%i", m_stars);
      v6 = numStarsString;
      if ( numStarsString[0] != 0 )
      {
        v7 = numStarsString[0];
        do
        {
          V_snwprintf(
            pDest: digitSequence,
            maxLen: 67,
            pFormat: L"<img src='SuperScriptDigit%c' height='16' width='5' vspace='0' />",
            v7);
          wcsncat(front: this->m_name, back: digitSequence, count: 0x2BEu);
          v7 = v6[1];
          ++v6;
        }
        while ( v7 != 0 );
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102105F0
// Name: public: void ScaleformPlayerScoreRow::ReleaseAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::ReleaseAll(ScaleformPlayerScoreRow *this)
{
  ISFTextObject **m_statusIcons; // esi
  int i; // edi

  if ( this->m_hName != nullptr )
    this->m_hName->Release(this: this->m_hName);
  if ( this->m_hContributionScore != nullptr )
    this->m_hContributionScore->Release(this: this->m_hContributionScore);
  if ( this->m_hKillPoints != nullptr )
    this->m_hKillPoints->Release(this: this->m_hKillPoints);
  if ( this->m_hKills != nullptr )
    this->m_hKills->Release(this: this->m_hKills);
  if ( this->m_hDeaths != nullptr )
    this->m_hDeaths->Release(this: this->m_hDeaths);
  if ( this->m_hMoneyEarned != nullptr )
    this->m_hMoneyEarned->Release(this: this->m_hMoneyEarned);
  if ( this->m_hOwningControl != nullptr )
    g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: this->m_hOwningControl);
  if ( this->m_hLocalPlayerOutline != nullptr )
    this->m_hLocalPlayerOutline->Release(this: this->m_hLocalPlayerOutline);
  if ( this->m_hVote != nullptr )
    this->m_hVote->Release(this: this->m_hVote);
  m_statusIcons = this->m_statusIcons;
  for ( i = 9; i != 0; --i )
  {
    if ( *m_statusIcons != nullptr )
      (*m_statusIcons)->Release(this: *m_statusIcons);
    ++m_statusIcons;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102106B0
// Name: public: void ScaleformPlayerScoreRow::Initialize(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::Initialize(ScaleformPlayerScoreRow *this, void *rowHandle)
{
  ISFTextObject *v3; // eax

  this->m_hName = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                    this: g_pScaleformUI,
                    a2: rowHandle,
                    a3: "Player_Name");
  this->m_hContributionScore = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                 this: g_pScaleformUI,
                                 a2: rowHandle,
                                 a3: "Score");
  this->m_hKillPoints = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                          this: g_pScaleformUI,
                          a2: rowHandle,
                          a3: "KillPoints");
  this->m_hKills = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: rowHandle, a3: "Kills");
  this->m_hDeaths = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                      this: g_pScaleformUI,
                      a2: rowHandle,
                      a3: "Death");
  this->m_hMoneyEarned = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: rowHandle,
                           a3: "MoneyEarned");
  this->m_hLocalPlayerOutline = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                  this: g_pScaleformUI,
                                  a2: rowHandle,
                                  a3: "PlayerOutline");
  this->m_statusIcons[1] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "Skull");
  this->m_statusIcons[2] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "Bomb");
  this->m_statusIcons[3] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "Dominated");
  this->m_statusIcons[4] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "DominatedDead");
  this->m_statusIcons[5] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "Nemesis");
  this->m_statusIcons[6] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "NemesisDead");
  this->m_statusIcons[7] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "defuser");
  this->m_statusIcons[8] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: rowHandle,
                             a3: "Switch");
  v3 = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: rowHandle, a3: "Vote");
  this->m_hOwningControl = rowHandle;
  this->m_hVote = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10210860
// Name: private: void ScaleformPlayerScoreRow::ShowAvatar(void __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::ShowAvatar(
        ScaleformPlayerScoreRow *this,
        void *flashAPI,
        unsigned __int64 xuid)
{
  void *v4; // esi
  char xuidText[256]; // [esp+8h] [ebp-100h] BYREF

  if ( flashAPI != nullptr && g_PR != nullptr )
  {
    C_PlayerResource::FillXuidText(this: g_PR, iIndex: this->m_playerIndex, buf: xuidText, bufSize: 0xFFu);
    v4 = g_pScaleformUI->CreateValueArray(this: g_pScaleformUI, a2: 2);
    g_pScaleformUI->ValueArray_SetElement_6(this: g_pScaleformUI, a2: v4, a3: 0, a4: this->m_hOwningControl);
    g_pScaleformUI->ValueArray_SetElement_2(this: g_pScaleformUI, a2: v4, a3: 1, a4: xuidText);
    g_pScaleformUI->Value_InvokeWithoutReturn(this: g_pScaleformUI, a2: flashAPI, a3: "ShowAvatar", a4: v4, a5: 2u);
    g_pScaleformUI->ReleaseValueArray(this: g_pScaleformUI, a2: v4, a3: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210920
// Name: private: void ScaleformPlayerScoreRow::HideAvatar(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::HideAvatar(ScaleformPlayerScoreRow *this, void *flashAPI)
{
  void *v3; // esi

  if ( flashAPI != nullptr )
  {
    v3 = g_pScaleformUI->CreateValueArray(this: g_pScaleformUI, a2: 1);
    g_pScaleformUI->ValueArray_SetElement_6(this: g_pScaleformUI, a2: v3, a3: 0, a4: this->m_hOwningControl);
    g_pScaleformUI->Value_InvokeWithoutReturn(this: g_pScaleformUI, a2: flashAPI, a3: "HideAvatar", a4: v3, a5: 1u);
    g_pScaleformUI->ReleaseValueArray(this: g_pScaleformUI, a2: v3, a3: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210AE0
// Name: private: void CScoreboardScaleform::ChangeSelectedPlayerRow(class ScaleformPlayerScoreRow __near *,class ScaleformPlayerScoreRow __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::ChangeSelectedPlayerRow(
        CScoreboardScaleform *this,
        ScaleformPlayerScoreRow *rowToHide,
        ScaleformPlayerScoreRow *rowToShow)
{
  void *v4; // edi

  v4 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
  if ( rowToHide != nullptr )
  {
    this->m_pScaleformUI->ValueArray_SetElement_6(
      this: this->m_pScaleformUI,
      a2: v4,
      a3: 0,
      a4: rowToHide->m_hOwningControl);
    g_pScaleformUI->Value_InvokeWithoutReturn(
      this: g_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "DeselectPlayerRow",
      a4: v4,
      a5: 1u);
  }
  if ( rowToShow != nullptr )
  {
    this->m_pScaleformUI->ValueArray_SetElement_6(
      this: this->m_pScaleformUI,
      a2: v4,
      a3: 0,
      a4: rowToShow->m_hOwningControl);
    g_pScaleformUI->Value_InvokeWithoutReturn(
      this: g_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SelectPlayerRow",
      a4: v4,
      a5: 1u);
    this->m_showGamerCardButton = rowToShow->m_playerIndex != -1
                               && !g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: rowToShow->m_playerIndex);
  }
  else
  {
    this->m_showGamerCardButton = false;
  }
  CScoreboardScaleform::UpdateNavBar(this);
  this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v4, a3: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10210BD0
// Name: protected: void CScoreboardScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::Hide(CScoreboardScaleform *this)
{
  bool v2; // zf
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IConVar *m_pConVar; // ecx
  SplitScreenConVarRef pHideHud; // [esp+0h] [ebp-10h] BYREF

  v2 = !this->m_bFlashAPIIsValid;
  this->m_fGuardTime = 0.0;
  if ( !v2 )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hidePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  if ( this->m_bVisible )
  {
    SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: "hidehud");
    m_pConVar = pHideHud.m_Info[this->m_iSplitScreenSlot].m_pConVar;
    m_pConVar->SetValue_2(this: m_pConVar, a2: this->m_PrevHideHudValue);
  }
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x10210C70
// Name: private: void CScoreboardScaleform::PopulateCurrentVote(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulateCurrentVote(CScoreboardScaleform *this)
{
  C_CSPlayer *LocalPlayer; // esi
  char i; // al

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      SFHudVotePanel::SetVoteString(
        voteIssue: LocalPlayer->m_currentVoteIssue,
        kickTargetIndex: LocalPlayer->m_currentVoteKickTarget,
        callingPlayerIndex: LocalPlayer->m_currentVoteCaller,
        stringId: "#SFUI_Scoreboard_VoteStatus",
        textObject: this->m_hCurrentVote);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210CE0
// Name: public: bool ScoreboardEntry::PopulateFromPlayerIndex(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScoreboardEntry::PopulateFromPlayerIndex(ScoreboardEntry *this, int playerIndex)
{
  C_CS_PlayerResource *v3; // eax
  char *v5; // ebx
  wchar_t *v7; // eax
  int starsa; // [esp+4h] [ebp-Ch]
  const char *stars; // [esp+4h] [ebp-Ch]
  int contributionScore; // [esp+8h] [ebp-8h]
  C_CS_PlayerResource *cs_PR; // [esp+Ch] [ebp-4h]
  int deaths; // [esp+18h] [ebp+8h]

  v3 = (C_CS_PlayerResource *)__RTDynamicCast(
                                inptr: g_PR,
                                VfDelta: 0,
                                SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                isReference: 0);
  cs_PR = v3;
  if ( v3 == nullptr )
    return 0;
  v5 = (char *)&v3->IGameResources;
  deaths = v3->GetDeaths(this: &v3->IGameResources, a2: playerIndex);
  starsa = C_CS_PlayerResource::GetNumMVPs(this: cs_PR, iIndex: playerIndex);
  contributionScore = C_CS_PlayerResource::GetScore(this: cs_PR, iIndex: playerIndex);
  this->m_kills = (*(int (__thiscall **)(char *, int))(*(_DWORD *)v5 + 36))(a1: v5, a2: playerIndex);
  this->m_deaths = deaths;
  this->m_playerIndex = playerIndex;
  this->m_contributionScore = contributionScore;
  this->m_killPoints = 0;
  this->m_stars = starsa;
  ScoreboardEntry::SetStatusFromPlayerIndex(this, playerIndex);
  this->m_xuid = C_PlayerResource::GetXuid(this: cs_PR, iIndex: playerIndex);
  this->m_bVote = C_CS_PlayerResource::GetVote(this: cs_PR, iIndex: playerIndex);
  stars = (const char *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)v5 + 32))(a1: v5, a2: playerIndex);
  if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*(_DWORD *)v5 + 16))(a1: v5, a2: playerIndex) != 0
    && C_CS_PlayerResource::IsControllingBot(this: cs_PR, index: playerIndex) )
  {
    v7 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUI_bot_controlled_by");
  }
  else
  {
    v7 = nullptr;
  }
  ScoreboardEntry::SetEscapedNameFromRawName(this, name: stars, prependedString: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10210E10
// Name: public: void ScaleformPlayerScoreRow::Populate(class ScoreboardEntry __near &,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::Populate(
        ScaleformPlayerScoreRow *this,
        ScoreboardEntry *entry,
        void *flashAPI)
{
  ISFTextObject *m_hName; // eax
  ISFTextObject *m_hContributionScore; // ecx
  bool IsPlayingGunGameTRBomb; // al
  ISFTextObject *m_hKillPoints; // ecx
  ISFTextObject *m_hKills; // ecx
  ISFTextObject *m_hDeaths; // ecx
  ISFTextObject *m_hMoneyEarned; // eax
  int m_playerIndex; // edi
  int LocalPlayerIndex; // eax
  ISFTextObject *m_hLocalPlayerOutline; // ecx
  ISFTextObject *m_hVote; // ecx
  ISFTextObject **m_statusIcons; // edi
  ISFTextObject *v17; // ecx
  ScoreboardStatus m_status; // [esp+8h] [ebp-4h]
  int entrya; // [esp+14h] [ebp+8h]

  m_hName = this->m_hName;
  if ( m_hName != nullptr )
    m_hName->SetTextHTML(this: m_hName, a2: entry->m_name);
  m_hContributionScore = this->m_hContributionScore;
  if ( m_hContributionScore != nullptr )
    m_hContributionScore->SetText_4(this: m_hContributionScore, a2: entry->m_contributionScore);
  if ( this->m_hKillPoints != nullptr )
  {
    IsPlayingGunGameTRBomb = C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules);
    m_hKillPoints = this->m_hKillPoints;
    if ( IsPlayingGunGameTRBomb )
      ((void (__stdcall *)(int))m_hKillPoints->SetText_4)(a1: entry->m_killPoints);
    else
      ((void (__stdcall *)(_DWORD))m_hKillPoints->SetVisible)(a1: 0);
  }
  m_hKills = this->m_hKills;
  if ( m_hKills != nullptr )
    m_hKills->SetText_4(this: m_hKills, a2: entry->m_kills);
  m_hDeaths = this->m_hDeaths;
  if ( m_hDeaths != nullptr )
    m_hDeaths->SetText_4(this: m_hDeaths, a2: entry->m_deaths);
  m_hMoneyEarned = this->m_hMoneyEarned;
  if ( m_hMoneyEarned != nullptr )
    m_hMoneyEarned->SetText_2(this: m_hMoneyEarned, a2: prType);
  m_playerIndex = entry->m_playerIndex;
  LocalPlayerIndex = GetLocalPlayerIndex();
  LOBYTE(LocalPlayerIndex) = m_playerIndex == LocalPlayerIndex;
  this->m_isLocalPlayer = LocalPlayerIndex;
  this->m_playerIndex = entry->m_playerIndex;
  m_hLocalPlayerOutline = this->m_hLocalPlayerOutline;
  if ( m_hLocalPlayerOutline != nullptr )
    m_hLocalPlayerOutline->SetVisible(this: m_hLocalPlayerOutline, a2: LocalPlayerIndex);
  m_hVote = this->m_hVote;
  if ( m_hVote != nullptr )
    m_hVote->SetVisible(this: m_hVote, a2: entry->m_bVote);
  m_status = entry->m_status;
  m_statusIcons = this->m_statusIcons;
  for ( entrya = 9; entrya != 0; --entrya )
  {
    if ( *m_statusIcons != nullptr )
      (*m_statusIcons)->SetVisible(this: *m_statusIcons, a2: false);
    ++m_statusIcons;
  }
  v17 = this->m_statusIcons[m_status];
  if ( v17 != nullptr )
    v17->SetVisible(this: v17, a2: true);
  ScaleformPlayerScoreRow::ShowAvatar(this, flashAPI, xuid: entry->m_xuid);
}

//------------------------------------------------------------------------------
// Address: 0x10210F60
// Name: public: void ScaleformPlayerScoreRow::Clear(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformPlayerScoreRow::Clear(ScaleformPlayerScoreRow *this, void *flashAPI)
{
  ISFTextObject *m_hName; // eax
  ISFTextObject *m_hContributionScore; // eax
  ISFTextObject *m_hKillPoints; // eax
  ISFTextObject *m_hKills; // eax
  ISFTextObject *m_hDeaths; // eax
  ISFTextObject *m_hMoneyEarned; // eax
  ISFTextObject *m_hLocalPlayerOutline; // ecx
  ISFTextObject *m_hVote; // ecx
  ISFTextObject **m_statusIcons; // edi
  int i; // ebx
  ISFTextObject *v13; // ecx

  m_hName = this->m_hName;
  if ( m_hName != nullptr )
    m_hName->SetText_2(this: m_hName, a2: prType);
  m_hContributionScore = this->m_hContributionScore;
  if ( m_hContributionScore != nullptr )
    m_hContributionScore->SetText_2(this: m_hContributionScore, a2: prType);
  m_hKillPoints = this->m_hKillPoints;
  if ( m_hKillPoints != nullptr )
    m_hKillPoints->SetText_2(this: m_hKillPoints, a2: prType);
  m_hKills = this->m_hKills;
  if ( m_hKills != nullptr )
    m_hKills->SetText_2(this: m_hKills, a2: prType);
  m_hDeaths = this->m_hDeaths;
  if ( m_hDeaths != nullptr )
    m_hDeaths->SetText_2(this: m_hDeaths, a2: prType);
  m_hMoneyEarned = this->m_hMoneyEarned;
  if ( m_hMoneyEarned != nullptr )
    m_hMoneyEarned->SetText_2(this: m_hMoneyEarned, a2: prType);
  m_hLocalPlayerOutline = this->m_hLocalPlayerOutline;
  if ( m_hLocalPlayerOutline != nullptr )
    m_hLocalPlayerOutline->SetVisible(this: m_hLocalPlayerOutline, a2: false);
  m_hVote = this->m_hVote;
  if ( m_hVote != nullptr )
    m_hVote->SetVisible(this: m_hVote, a2: false);
  this->m_playerIndex = -1;
  this->m_isLocalPlayer = false;
  m_statusIcons = this->m_statusIcons;
  for ( i = 9; i != 0; --i )
  {
    if ( *m_statusIcons != nullptr )
      (*m_statusIcons)->SetVisible(this: *m_statusIcons, a2: false);
    ++m_statusIcons;
  }
  v13 = this->m_statusIcons[0];
  if ( v13 != nullptr )
    v13->SetVisible(this: v13, a2: true);
  ScaleformPlayerScoreRow::HideAvatar(this, flashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10211060
// Name: public: void CScoreboardScaleform::NavigateUp(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::NavigateUp(CScoreboardScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  int m_selectionIndex; // eax
  int m_selectionTeam; // edx
  ScaleformPlayerScoreRow *v5; // esi
  int m_Size; // edx
  int v7; // eax
  int v8; // edx
  int v9; // edx

  m_selectionIndex = this->m_selectionIndex;
  m_selectionTeam = this->m_selectionTeam;
  if ( m_selectionIndex >= 0 )
  {
    if ( m_selectionTeam == 3 )
    {
      if ( m_selectionIndex < this->m_ctScoreRows.m_Size )
      {
        v5 = &this->m_ctScoreRows.m_Memory.m_pMemory[m_selectionIndex];
        goto LABEL_9;
      }
    }
    else if ( m_selectionTeam == 2 && m_selectionIndex < this->m_tScoreRows.m_Size )
    {
      v5 = &this->m_tScoreRows.m_Memory.m_pMemory[m_selectionIndex];
      goto LABEL_9;
    }
  }
  v5 = nullptr;
LABEL_9:
  if ( m_selectionIndex > 0 )
  {
    v7 = m_selectionIndex - 1;
  }
  else
  {
    if ( m_selectionTeam != 2 )
      return;
    m_Size = this->m_ctScores.m_Size;
    if ( m_Size <= 0 )
      return;
    v7 = this->m_ctScoreRows.m_Size - 1;
    v8 = m_Size - 1;
    if ( v7 >= v8 )
      v7 = v8;
    this->m_selectionTeam = 3;
  }
  v9 = this->m_selectionTeam;
  this->m_selectionIndex = v7;
  if ( v7 >= 0 )
  {
    if ( v9 == 3 )
    {
      if ( v7 < this->m_ctScoreRows.m_Size )
      {
        CScoreboardScaleform::ChangeSelectedPlayerRow(
          this,
          rowToHide: v5,
          rowToShow: &this->m_ctScoreRows.m_Memory.m_pMemory[v7]);
        return;
      }
    }
    else if ( v9 == 2 && v7 < this->m_tScoreRows.m_Size )
    {
      CScoreboardScaleform::ChangeSelectedPlayerRow(
        this,
        rowToHide: v5,
        rowToShow: &this->m_tScoreRows.m_Memory.m_pMemory[v7]);
      return;
    }
  }
  CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v5, rowToShow: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10211120
// Name: public: void CScoreboardScaleform::NavigateDown(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::NavigateDown(CScoreboardScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  int m_selectionIndex; // eax
  int m_selectionTeam; // ebx
  ScaleformPlayerScoreRow *v5; // edi
  int v6; // edx
  int v7; // eax
  int v8; // edx

  m_selectionIndex = this->m_selectionIndex;
  m_selectionTeam = this->m_selectionTeam;
  if ( m_selectionIndex >= 0 )
  {
    if ( m_selectionTeam == 3 )
    {
      if ( m_selectionIndex < this->m_ctScoreRows.m_Size )
      {
        v5 = &this->m_ctScoreRows.m_Memory.m_pMemory[m_selectionIndex];
        goto LABEL_9;
      }
    }
    else if ( m_selectionTeam == 2 && m_selectionIndex < this->m_tScoreRows.m_Size )
    {
      v5 = &this->m_tScoreRows.m_Memory.m_pMemory[m_selectionIndex];
      goto LABEL_9;
    }
  }
  v5 = nullptr;
LABEL_9:
  if ( m_selectionTeam == 2 )
  {
    v6 = this->m_tScoreRows.m_Size - 1;
    if ( v6 >= this->m_tScores.m_Size - 1 )
      v6 = this->m_tScores.m_Size - 1;
  }
  else if ( m_selectionTeam == 3 )
  {
    v6 = this->m_ctScoreRows.m_Size - 1;
    if ( v6 >= this->m_ctScores.m_Size - 1 )
      v6 = this->m_ctScores.m_Size - 1;
  }
  else
  {
    v6 = -1;
  }
  if ( m_selectionIndex < v6 )
  {
    this->m_selectionIndex = m_selectionIndex + 1;
  }
  else
  {
    if ( m_selectionTeam != 3 || this->m_tScores.m_Size <= 0 )
      return;
    this->m_selectionIndex = 0;
    this->m_selectionTeam = 2;
  }
  v7 = this->m_selectionIndex;
  v8 = this->m_selectionTeam;
  if ( v7 >= 0 )
  {
    if ( v8 == 3 )
    {
      if ( v7 < this->m_ctScoreRows.m_Size )
      {
        CScoreboardScaleform::ChangeSelectedPlayerRow(
          this,
          rowToHide: v5,
          rowToShow: &this->m_ctScoreRows.m_Memory.m_pMemory[v7]);
        return;
      }
    }
    else if ( v8 == 2 && v7 < this->m_tScoreRows.m_Size )
    {
      CScoreboardScaleform::ChangeSelectedPlayerRow(
        this,
        rowToHide: v5,
        rowToShow: &this->m_tScoreRows.m_Memory.m_pMemory[v7]);
      return;
    }
  }
  CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v5, rowToShow: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10211220
// Name: public: void CScoreboardScaleform::ShowGamerCard(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::ShowGamerCard(CScoreboardScaleform *this, IScaleformUI *pui, void *obj)
{
  int m_selectionIndex; // eax
  int m_selectionTeam; // edx
  ScaleformPlayerScoreRow *v5; // eax
  int m_playerIndex; // esi
  player_info_s playerInfo; // [esp+4h] [ebp-90h] BYREF

  if ( g_PR != nullptr )
  {
    m_selectionIndex = this->m_selectionIndex;
    m_selectionTeam = this->m_selectionTeam;
    if ( m_selectionIndex >= 0 )
    {
      if ( m_selectionTeam == 3 )
      {
        if ( m_selectionIndex >= this->m_ctScoreRows.m_Size )
          return;
        v5 = &this->m_ctScoreRows.m_Memory.m_pMemory[m_selectionIndex];
      }
      else
      {
        if ( m_selectionTeam != 2 || m_selectionIndex >= this->m_tScoreRows.m_Size )
          return;
        v5 = &this->m_tScoreRows.m_Memory.m_pMemory[m_selectionIndex];
      }
      if ( v5 != nullptr )
      {
        m_playerIndex = v5->m_playerIndex;
        if ( m_playerIndex != -1 && !g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: m_playerIndex) )
          engine->GetPlayerInfo(this: engine, a2: m_playerIndex, a3: &playerInfo);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102112B0
// Name: protected: void CScoreboardScaleform::PopulatePlayerList(class CUtlVector<class ScoreboardEntry,class CUtlMemory<class ScoreboardEntry,int>> __near &,class CUtlVector<class ScaleformPlayerScoreRow,class CUtlMemory<class ScaleformPlayerScoreRow,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulatePlayerList(
        CScoreboardScaleform *this,
        CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int> > *players,
        CUtlVector<ScaleformPlayerScoreRow,CUtlMemory<ScaleformPlayerScoreRow,int> > *rows,
        bool forceIncludeLocalPlayer)
{
  int v5; // edi
  int v6; // esi
  ScaleformPlayerScoreRow *v7; // ecx
  ScoreboardEntry *v8; // eax
  int iLocalPlayerIndex; // [esp+Ch] [ebp-10h]
  int numRows; // [esp+10h] [ebp-Ch]
  int v11; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]
  bool localPlayerIncluded; // [esp+2Fh] [ebp+13h]

  iLocalPlayerIndex = GetLocalPlayerIndex();
  localPlayerIncluded = !forceIncludeLocalPlayer;
  v5 = 0;
  v6 = 0;
  numRows = rows->m_Size;
  i = 0;
  if ( numRows > 0 )
  {
    v11 = 0;
    do
    {
      v7 = &rows->m_Memory.m_pMemory[v5];
      if ( i >= players->m_Size )
      {
        ScaleformPlayerScoreRow::Clear(this: v7, flashAPI: this->m_FlashAPI);
      }
      else
      {
        v8 = &players->m_Memory.m_pMemory[v11];
        if ( v8->m_playerIndex == iLocalPlayerIndex )
        {
          localPlayerIncluded = true;
          ScaleformPlayerScoreRow::Populate(this: v7, entry: v8, flashAPI: this->m_FlashAPI);
        }
        else
        {
          if ( !localPlayerIncluded && v6 == numRows - 1 )
            goto LABEL_11;
          ScaleformPlayerScoreRow::Populate(this: v7, entry: v8, flashAPI: this->m_FlashAPI);
        }
      }
      ++v6;
      ++v5;
LABEL_11:
      ++i;
      ++v11;
    }
    while ( v6 < numRows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211360
// Name: public: virtual void CScoreboardScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::FireGameEvent(CScoreboardScaleform *this, IGameEvent *event)
{
  const char *v3; // edi
  IViewPort *ViewPortInterface; // eax
  IViewPort *v5; // eax
  ConVar *m_pConVarState; // ecx
  IViewPort *v7; // eax
  CGameUIConVarRef mp_round_restart_delay; // [esp+4h] [ebp-10h] BYREF

  if ( !IsValidSplitScreenSlot(i: (int)this->m_hSpectator2) )
    return;
  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "cs_win_panel_match") == 0 )
  {
    BYTE2(this->m_hCurrentVote) = 1;
    CGameUIConVarRef::CGameUIConVarRef(this: &mp_round_restart_delay, pName: "mp_chattime");
    *(float *)&this->m_selectionTeam = mp_round_restart_delay.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_fValue
                                     + *(float *)(gpGlobals.m_Index + 12);
    *(float *)&this->m_hTKillPointsHeader = *(float *)(gpGlobals.m_Index + 12) + 3.0;
    return;
  }
  if ( _V_strcmp(s1: v3, s2: "cs_match_end_restart") == 0 )
  {
    HIWORD(this->m_hCurrentVote) = 0;
    BYTE2(this->m_hTopText) = 0;
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: false);
    this->m_selectionTeam = 0;
    return;
  }
  if ( _V_strcmp(s1: v3, s2: "round_start") == 0 )
  {
    this->m_hTKillPointsHeader = nullptr;
    if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules)
      || HIBYTE(this->m_hCurrentVote) != 0 )
    {
      v5 = GetViewPortInterface();
      v5->ShowPanel_2(this: v5, a2: "scores", a3: false);
    }
    HIWORD(this->m_hCurrentVote) = 0;
    this->m_selectionTeam = 0;
    return;
  }
  if ( _V_strcmp(s1: v3, s2: "round_end") == 0 )
  {
    if ( !C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules) )
      return;
    BYTE2(this->m_hCurrentVote) = 1;
    CGameUIConVarRef::CGameUIConVarRef(this: &mp_round_restart_delay, pName: "mp_ggprogressive_round_restart_delay");
    m_pConVarState = mp_round_restart_delay.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState;
    goto LABEL_18;
  }
  if ( _V_strcmp(s1: v3, s2: "cs_game_disconnected") == 0 )
  {
    HIWORD(this->m_hCurrentVote) = 0;
    this->m_hTKillPointsHeader = nullptr;
    this->m_selectionTeam = 0;
    ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::RemoveFlashElement(this: (CScoreboardScaleform *)((char *)this - 24));
    return;
  }
  if ( _V_strcmp(s1: v3, s2: "cs_halftime_started") == 0 )
  {
    HIBYTE(this->m_hCurrentVote) = 1;
    *(float *)&this->m_hTKillPointsHeader = *(float *)(gpGlobals.m_Index + 12) + 3.0;
    BYTE2(this->m_hTopText) = 1;
    v7 = GetViewPortInterface();
    v7->ShowPanel_2(this: v7, a2: "scores", a3: true);
    CGameUIConVarRef::CGameUIConVarRef(this: &mp_round_restart_delay, pName: "mp_round_restart_delay");
    m_pConVarState = mp_round_restart_delay.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState;
LABEL_18:
    *(float *)&this->m_selectionTeam = m_pConVarState->m_Value.m_fValue + *(float *)(gpGlobals.m_Index + 12);
    return;
  }
  if ( _V_strcmp(s1: v3, s2: "enable_restart_voting") == 0 )
  {
    BYTE1(this->m_hTopText) = event->GetBool(this: event, a2: "enable", a3: false);
    CScoreboardScaleform::UpdateNavBar(this: (CScoreboardScaleform *)((char *)this - 24));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211730
// Name: private: void CScoreboardScaleform::DoInitialPlayerSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::DoInitialPlayerSelection(CScoreboardScaleform *this)
{
  int m_selectionIndex; // eax
  int m_selectionTeam; // ecx
  ScaleformPlayerScoreRow *v4; // ebx
  int v5; // eax
  ScaleformPlayerScoreRow *m_pMemory; // edx
  bool *p_m_isLocalPlayer; // ecx
  int v8; // eax
  ScaleformPlayerScoreRow *v9; // edx
  bool *v10; // ecx
  ScaleformPlayerScoreRow *v11; // edi
  C_Team *GlobalTeam; // eax
  C_Team *v13; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  m_selectionIndex = this->m_selectionIndex;
  m_selectionTeam = this->m_selectionTeam;
  if ( m_selectionIndex >= 0 )
  {
    if ( m_selectionTeam == 3 )
    {
      if ( m_selectionIndex < this->m_ctScoreRows.m_Size )
      {
        v4 = &this->m_ctScoreRows.m_Memory.m_pMemory[m_selectionIndex];
        goto LABEL_9;
      }
    }
    else if ( m_selectionTeam == 2 && m_selectionIndex < this->m_tScoreRows.m_Size )
    {
      v4 = &this->m_tScoreRows.m_Memory.m_pMemory[m_selectionIndex];
      goto LABEL_9;
    }
  }
  v4 = nullptr;
LABEL_9:
  v5 = 0;
  if ( this->m_tScoreRows.m_Size > 0 )
  {
    m_pMemory = this->m_tScoreRows.m_Memory.m_pMemory;
    p_m_isLocalPlayer = &m_pMemory->m_isLocalPlayer;
    while ( !*p_m_isLocalPlayer )
    {
      ++v5;
      p_m_isLocalPlayer += 80;
      if ( v5 >= this->m_tScoreRows.m_Size )
        goto LABEL_13;
    }
    this->m_selectionTeam = 2;
    this->m_selectionIndex = v5;
    CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v4, rowToShow: &m_pMemory[v5]);
    goto LABEL_21;
  }
LABEL_13:
  v8 = 0;
  if ( this->m_ctScoreRows.m_Size > 0 )
  {
    v9 = this->m_ctScoreRows.m_Memory.m_pMemory;
    v10 = &v9->m_isLocalPlayer;
    while ( !*v10 )
    {
      ++v8;
      v10 += 80;
      if ( v8 >= this->m_ctScoreRows.m_Size )
        goto LABEL_17;
    }
    this->m_selectionIndex = v8;
    this->m_selectionTeam = 3;
    CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v4, rowToShow: &v9[v8]);
LABEL_21:
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
LABEL_17:
  v11 = nullptr;
  GlobalTeam = GetGlobalTeam(iTeamNumber: 3);
  if ( GlobalTeam->Get_Number_Players(this: GlobalTeam) <= 0 )
  {
    v13 = GetGlobalTeam(iTeamNumber: 2);
    if ( v13->Get_Number_Players(this: v13) > 0 )
    {
      v11 = nullptr;
      this->m_selectionTeam = 2;
      this->m_selectionIndex = 0;
      if ( this->m_tScoreRows.m_Size > 0 )
        v11 = this->m_tScoreRows.m_Memory.m_pMemory;
    }
  }
  else
  {
    this->m_selectionTeam = 3;
    this->m_selectionIndex = 0;
    if ( this->m_ctScoreRows.m_Size > 0 )
      v11 = this->m_ctScoreRows.m_Memory.m_pMemory;
  }
  CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v4, rowToShow: v11);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10211890
// Name: protected: void CScoreboardScaleform::Unload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::Unload(CScoreboardScaleform *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  ScaleformPlayerScoreRow *m_pMemory; // ecx

  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hMapName);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTimeLeft);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hRoundsLeft);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTimerIcon);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hGameType);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hNumCTs);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hNumTs);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hCTScore);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTScore);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTeam1ScoreFirstHalf);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTeam2ScoreFirstHalf);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(
    this,
    value: &this->m_hTeam1ScoreSecondHalf);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(
    this,
    value: &this->m_hTeam2ScoreSecondHalf);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTeam1ScoreTotal);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTeam2ScoreTotal);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hNumSpectators);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hNavBar);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hNavBarLeft);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hTKillPointsHeader);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hCTKillPointsHeader);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hSpectator1);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hSpectator2);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_hCurrentVote);
  if ( this->m_pScaleformUI != nullptr && this->m_hTopText != nullptr )
  {
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_hTopText);
    this->m_hTopText = nullptr;
  }
  v2 = 0;
  if ( this->m_ctScoreRows.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      ScaleformPlayerScoreRow::ReleaseAll(this: &this->m_ctScoreRows.m_Memory.m_pMemory[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_ctScoreRows.m_Size );
  }
  v4 = 0;
  if ( this->m_tScoreRows.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      ScaleformPlayerScoreRow::ReleaseAll(this: &this->m_tScoreRows.m_Memory.m_pMemory[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_tScoreRows.m_Size );
  }
  this->m_ctScoreRows.m_Size = 0;
  if ( this->m_ctScoreRows.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ctScoreRows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ctScoreRows.m_Memory.m_pMemory);
      this->m_ctScoreRows.m_Memory.m_pMemory = nullptr;
    }
    this->m_ctScoreRows.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ctScoreRows.m_pElements = this->m_ctScoreRows.m_Memory.m_pMemory;
  this->m_tScoreRows.m_Size = 0;
  if ( this->m_tScoreRows.m_Memory.m_nGrowSize < 0 )
  {
    this->m_tScoreRows.m_pElements = this->m_tScoreRows.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_tScoreRows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_tScoreRows.m_Memory.m_pMemory);
      this->m_tScoreRows.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_tScoreRows.m_Memory.m_pMemory;
    this->m_tScoreRows.m_Memory.m_nAllocationCount = 0;
    this->m_tScoreRows.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211AB0
// Name: protected: virtual bool CScoreboardScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScoreboardScaleform::PreUnloadFlash(CScoreboardScaleform *this)
{
  this->m_bLoading = true;
  CScoreboardScaleform::Unload(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10211AC0
// Name: public: CScoreboardScaleform::CScoreboardScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CScoreboardScaleform *__thiscall CScoreboardScaleform::CScoreboardScaleform(CScoreboardScaleform *this)
{
  CGameEventListener *v2; // edi
  ScoreboardEntry *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  ScoreboardEntry *v5; // eax
  ScoreboardEntry *v6; // eax
  ScoreboardEntry *v7; // eax
  ScaleformPlayerScoreRow *v8; // eax
  ScaleformPlayerScoreRow *v9; // eax
  ScaleformPlayerScoreRow *v10; // eax
  ScaleformPlayerScoreRow *v11; // eax

  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CScoreboardScaleform_vtbl *)&CScoreboardScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CScoreboardScaleform::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CScoreboardScaleform::`vftable'{for `CGameEventListener'};
  this->m_ctScores.m_Memory.m_pMemory = nullptr;
  this->m_ctScores.m_Memory.m_nAllocationCount = 0;
  this->m_ctScores.m_Memory.m_nGrowSize = 0;
  this->m_ctScores.m_Size = 0;
  this->m_ctScores.m_pElements = nullptr;
  this->m_tScores.m_Memory.m_pMemory = nullptr;
  this->m_tScores.m_Memory.m_nAllocationCount = 0;
  this->m_tScores.m_Memory.m_nGrowSize = 0;
  this->m_tScores.m_Size = 0;
  this->m_tScores.m_pElements = nullptr;
  v2 = &this->CGameEventListener;
  this->m_ctScoreRows.m_Memory.m_pMemory = nullptr;
  this->m_ctScoreRows.m_Memory.m_nAllocationCount = 0;
  this->m_ctScoreRows.m_Memory.m_nGrowSize = 0;
  this->m_ctScoreRows.m_Size = 0;
  this->m_ctScoreRows.m_pElements = nullptr;
  this->m_tScoreRows.m_Memory.m_pMemory = nullptr;
  this->m_tScoreRows.m_Memory.m_nAllocationCount = 0;
  this->m_tScoreRows.m_Memory.m_nGrowSize = 0;
  this->m_tScoreRows.m_Size = 0;
  this->m_tScoreRows.m_pElements = nullptr;
  if ( this->m_tScores.m_Memory.m_nAllocationCount < 64 && this->m_tScores.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_tScores.m_Memory.m_nAllocationCount = 64;
    m_pMemory = this->m_tScores.m_Memory.m_pMemory;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = (ScoreboardEntry *)((int (__stdcall *)(ScoreboardEntry *, int))v4->Realloc_2)(a1: m_pMemory, a2: 92672);
    else
      v5 = (ScoreboardEntry *)((int (__stdcall *)(int))v4->Alloc_2)(a1: 92672);
    this->m_tScores.m_Memory.m_pMemory = v5;
  }
  this->m_tScores.m_pElements = this->m_tScores.m_Memory.m_pMemory;
  if ( this->m_ctScores.m_Memory.m_nAllocationCount < 64 && this->m_ctScores.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_ctScores.m_Memory.m_nAllocationCount = 64;
    v6 = this->m_ctScores.m_Memory.m_pMemory;
    if ( v6 != nullptr )
      v7 = (ScoreboardEntry *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v6, a3: 92672);
    else
      v7 = (ScoreboardEntry *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 92672);
    this->m_ctScores.m_Memory.m_pMemory = v7;
  }
  this->m_ctScores.m_pElements = this->m_ctScores.m_Memory.m_pMemory;
  if ( this->m_tScoreRows.m_Memory.m_nAllocationCount < 64 && this->m_tScoreRows.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_tScoreRows.m_Memory.m_nAllocationCount = 64;
    v8 = this->m_tScoreRows.m_Memory.m_pMemory;
    if ( v8 != nullptr )
      v9 = (ScaleformPlayerScoreRow *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v8, a3: 5120);
    else
      v9 = (ScaleformPlayerScoreRow *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5120);
    this->m_tScoreRows.m_Memory.m_pMemory = v9;
  }
  this->m_tScoreRows.m_pElements = this->m_tScoreRows.m_Memory.m_pMemory;
  if ( this->m_ctScoreRows.m_Memory.m_nAllocationCount < 64 && this->m_ctScoreRows.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_ctScoreRows.m_Memory.m_nAllocationCount = 64;
    v10 = this->m_ctScoreRows.m_Memory.m_pMemory;
    if ( v10 != nullptr )
      v11 = (ScaleformPlayerScoreRow *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v10, a3: 5120);
    else
      v11 = (ScaleformPlayerScoreRow *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5120);
    this->m_ctScoreRows.m_Memory.m_pMemory = v11;
  }
  this->m_ctScoreRows.m_pElements = this->m_ctScoreRows.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_bVisible = 0;
  this->m_bSecondHalf = false;
  *(_WORD *)&this->m_showGamerCardButton = 256;
  this->m_iSplitScreenSlot = 0;
  this->m_hMapName = nullptr;
  this->m_hTimeLeft = nullptr;
  this->m_hRoundsLeft = nullptr;
  this->m_hTimerIcon = nullptr;
  this->m_hGameType = nullptr;
  this->m_hCTScore = nullptr;
  this->m_hTScore = nullptr;
  this->m_hTeam1ScoreFirstHalf = nullptr;
  this->m_hTeam2ScoreFirstHalf = nullptr;
  this->m_hTeam1ScoreSecondHalf = nullptr;
  this->m_hTeam2ScoreSecondHalf = nullptr;
  this->m_hTeam1ScoreTotal = nullptr;
  this->m_hTeam2ScoreTotal = nullptr;
  this->m_hNumCTs = nullptr;
  this->m_hNumTs = nullptr;
  this->m_hNumSpectators = nullptr;
  this->m_hNavBar = nullptr;
  this->m_hNavBarLeft = nullptr;
  this->m_hTopText = nullptr;
  this->m_hTKillPointsHeader = nullptr;
  this->m_hCTKillPointsHeader = nullptr;
  this->m_hSpectator1 = nullptr;
  this->m_hSpectator2 = nullptr;
  this->m_hCurrentVote = nullptr;
  this->m_fGuardTime = 0.0;
  this->m_selectionIndex = -1;
  this->m_selectionTeam = 0;
  this->m_nTeam1FirstHalfScore = 0;
  this->m_nTeam2FirstHalfScore = 0;
  this->m_matchRestartTime = 0.0;
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "cs_match_end_restart", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "cs_win_panel_match", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "cs_game_disconnected", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "round_start", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "round_end", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "cs_halftime_started", a4: false);
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "enable_restart_voting", a4: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10211DE0
// Name: private: virtual char const __near * CScoreboardScaleform::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CScoreboardScaleform::GetName(CScoreboardScaleform *this)
{
  return "scores";
}

//------------------------------------------------------------------------------
// Address: 0x10211DF0
// Name: private: virtual bool CScoreboardScaleform::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScoreboardScaleform::IsVisible(CScoreboardScaleform *this)
{
  return (bool)this->m_hTopText;
}

//------------------------------------------------------------------------------
// Address: 0x10211E20
// Name: private: virtual void CScoreboardScaleform::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::Reset(CScoreboardScaleform *this)
{
  if ( *((_BYTE *)this - 4) != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this - 4) + 76))(
      a1: *((_DWORD *)this - 4),
      a2: *((_DWORD *)this - 2),
      a3: *((_DWORD *)this - 3));
}

//------------------------------------------------------------------------------
// Address: 0x10211E40
// Name: protected: int CScoreboardScaleform::RetrieveTableRowHandles(void __near *,char const __near *,char const __near *,class CUtlVector<class ScaleformPlayerScoreRow,class CUtlMemory<class ScaleformPlayerScoreRow,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScoreboardScaleform::RetrieveTableRowHandles(
        CScoreboardScaleform *this,
        void *root,
        const char *tableName,
        const char *rowNamePrefix,
        CUtlMemory<CAttachmentData,int> *arrayToPopulate)
{
  void *v5; // esi
  void *v6; // eax
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  ScaleformPlayerScoreRow *v9; // ecx
  int v10; // eax
  ScaleformPlayerScoreRow *v11; // eax
  ScaleformPlayerScoreRow row; // [esp+8h] [ebp-60h] BYREF
  char generatedRowName[16]; // [esp+58h] [ebp-10h] BYREF
  void *hTable; // [esp+70h] [ebp+8h]
  int rowIndex; // [esp+74h] [ebp+Ch]

  v5 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: root, a3: tableName);
  hTable = v5;
  rowIndex = 0;
  V_snprintf(pDest: generatedRowName, maxLen: 0x10u, pFormat: "%s%i", rowNamePrefix, 0);
  v6 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: v5, a3: generatedRowName);
  if ( v6 != nullptr )
  {
    do
    {
      ++rowIndex;
      row.m_hOwningControl = nullptr;
      memset(&row.m_hName, 0, 68);
      row.m_playerIndex = -1;
      row.m_isLocalPlayer = false;
      ScaleformPlayerScoreRow::Initialize(this: &row, rowHandle: v6);
      m_pMemory = (int)arrayToPopulate[1].m_pMemory;
      m_nAllocationCount = arrayToPopulate->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<ScaleformPlayerScoreRow,int>::Grow(this: arrayToPopulate, num: m_pMemory - m_nAllocationCount + 1);
      ++arrayToPopulate[1].m_pMemory;
      v9 = (ScaleformPlayerScoreRow *)arrayToPopulate->m_pMemory;
      v10 = (int)arrayToPopulate[1].m_pMemory - m_pMemory - 1;
      arrayToPopulate[1].m_nAllocationCount = (int)arrayToPopulate->m_pMemory;
      if ( v10 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v9[m_pMemory + 1], src: (unsigned __int8 *)&v9[m_pMemory], count: 80 * v10);
      v11 = (ScaleformPlayerScoreRow *)&arrayToPopulate->m_pMemory[m_pMemory];
      if ( v11 != nullptr )
        *v11 = row;
      V_snprintf(pDest: generatedRowName, maxLen: 0x10u, pFormat: "%s%i", rowNamePrefix, rowIndex);
      v6 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: hTable, a3: generatedRowName);
    }
    while ( v6 != nullptr );
    v5 = hTable;
  }
  g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: v5);
  return rowIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10211FB0
// Name: private: void CScoreboardScaleform::PopulatePlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::PopulatePlayers(CScoreboardScaleform *this)
{
  int i; // esi
  IGameResources_vtbl *v3; // esi
  int LocalPlayerIndex; // eax
  int v5; // eax
  IGameResources_vtbl *v6; // esi
  int v7; // eax
  int v8; // eax
  ScoreboardEntry entry; // [esp+4h] [ebp-5A8h] BYREF

  if ( g_PR != nullptr )
  {
    this->m_tScores.m_Size = 0;
    this->m_ctScores.m_Size = 0;
    for ( i = 1; i <= 64; ++i )
    {
      if ( g_PR->IsConnected(this: &g_PR->IGameResources, a2: i)
        && ScoreboardEntry::PopulateFromPlayerIndex(this: &entry, playerIndex: i) )
      {
        if ( g_PR->GetTeam(this: &g_PR->IGameResources, a2: i) == 2 )
        {
          CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::InsertBefore(
            this: &this->m_tScores,
            elem: this->m_tScores.m_Size,
            src: &entry);
        }
        else if ( g_PR->GetTeam(this: &g_PR->IGameResources, a2: i) == 3 )
        {
          CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::InsertBefore(
            this: &this->m_ctScores,
            elem: this->m_ctScores.m_Size,
            src: &entry);
        }
      }
    }
    CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::Sort(
      this: &this->m_tScores,
      pfnCompare: (int (__cdecl *)(const void *, const void *))CScoreboardScaleform::PlayerSortFunction);
    CUtlVector<ScoreboardEntry,CUtlMemory<ScoreboardEntry,int>>::Sort(
      this: &this->m_ctScores,
      pfnCompare: (int (__cdecl *)(const void *, const void *))CScoreboardScaleform::PlayerSortFunction);
    v3 = g_PR->IGameResources::__vftable;
    LocalPlayerIndex = GetLocalPlayerIndex();
    v5 = v3->GetTeam(this: &g_PR->IGameResources, a2: LocalPlayerIndex);
    CScoreboardScaleform::PopulatePlayerList(
      this,
      players: &this->m_tScores,
      rows: &this->m_tScoreRows,
      forceIncludeLocalPlayer: v5 == 2);
    v6 = g_PR->IGameResources::__vftable;
    v7 = GetLocalPlayerIndex();
    v8 = v6->GetTeam(this: &g_PR->IGameResources, a2: v7);
    CScoreboardScaleform::PopulatePlayerList(
      this,
      players: &this->m_ctScores,
      rows: &this->m_ctScoreRows,
      forceIncludeLocalPlayer: v8 == 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212110
// Name: public: virtual CScoreboardScaleform::~CScoreboardScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::~CScoreboardScaleform(CScoreboardScaleform *this)
{
  CGameEventListener *v2; // edi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CScoreboardScaleform_vtbl *)&CScoreboardScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CScoreboardScaleform::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CScoreboardScaleform::`vftable'{for `CGameEventListener'};
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  if ( this->m_bFlashAPIIsValid )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_tScoreRows);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ctScoreRows);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_tScores);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ctScores);
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
  v3 = !this->m_bFlashAPIIsValid;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CScoreboardScaleform_vtbl *)&ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::`vftable';
  if ( !v3 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10212210
// Name: protected: void CScoreboardScaleform::Populate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScoreboardScaleform::Populate(CScoreboardScaleform *this)
{
  bool IsPlayingGunGameTRBomb; // al
  ISFTextObject *m_hTKillPointsHeader; // ecx
  ISFTextObject *m_hCTKillPointsHeader; // ecx
  const wchar_t *MapName; // eax
  int v6; // ebx
  int i; // edi
  C_Team *GlobalTeam; // eax
  int MapRemainingTime; // edi
  ConVar *m_pParent; // eax
  bool v11; // zf
  int m_nValue; // eax
  const char *v13; // eax
  int m_selectionTeam; // edx
  int v15; // eax
  int m_selectionIndex; // ecx
  ScaleformPlayerScoreRow *v17; // ebx
  BOOL v18; // eax
  int v19; // edi
  int m_Size; // eax
  int v21; // edx
  int v22; // edx
  int v23; // eax
  bool isGunGameBomb; // [esp+4h] [ebp-4h]

  if ( g_PR != nullptr )
  {
    IsPlayingGunGameTRBomb = C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules);
    m_hTKillPointsHeader = this->m_hTKillPointsHeader;
    isGunGameBomb = IsPlayingGunGameTRBomb;
    if ( m_hTKillPointsHeader != nullptr )
      m_hTKillPointsHeader->SetVisible(this: m_hTKillPointsHeader, a2: IsPlayingGunGameTRBomb);
    m_hCTKillPointsHeader = this->m_hCTKillPointsHeader;
    if ( m_hCTKillPointsHeader != nullptr )
      m_hCTKillPointsHeader->SetVisible(this: m_hCTKillPointsHeader, a2: isGunGameBomb);
    CScoreboardScaleform::PopulateCurrentVote(this);
    if ( this->m_hMapName != nullptr )
    {
      MapName = CScoreboardScaleform::GetMapName(this);
      if ( MapName != nullptr )
        this->m_hMapName->SetText(this: this->m_hMapName, a2: MapName);
      else
        this->m_hMapName->SetText_2(this: this->m_hMapName, a2: "Map name unlocalized");
    }
    CScoreboardScaleform::PopulateTeamInfo(this);
    CScoreboardScaleform::PopulateGameType(this);
    CScoreboardScaleform::PopulatePlayers(this);
    CScoreboardScaleform::UpdateNavBar(this);
    CScoreboardScaleform::PopulateTeamCount(this, teamId: 2);
    CScoreboardScaleform::PopulateTeamCount(this, teamId: 3);
    v6 = 0;
    for ( i = 2; i <= 3; ++i )
    {
      GlobalTeam = GetGlobalTeam(iTeamNumber: i);
      if ( GlobalTeam != nullptr )
        v6 += GlobalTeam->Get_Score(this: GlobalTeam);
    }
    MapRemainingTime = (int)C_CSGameRules::GetMapRemainingTime(this: (C_CSGameRules *)g_pGameRules);
    if ( C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      m_pParent = mp_ggtr_rounds_per_half.m_pParent;
    }
    else
    {
      v11 = (unsigned __int8)C_CSGameRules::IsPlayingGunGameSelect(this: (C_CSGameRules *)g_pGameRules) == 0;
      m_pParent = mp_ggselect_match_bestof_win.m_pParent;
      if ( v11 )
        m_pParent = mp_maxrounds.m_pParent;
    }
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( this->m_bSecondHalf )
      v6 -= m_nValue;
    if ( this->m_bGameOver )
    {
      CScoreboardScaleform::DisplayRemainingTime(
        this,
        remainingTime: (int)(float)(this->m_matchRestartTime - *(float *)(gpGlobals.m_Index + 12)),
        localizationStringId: "#SFUI_Scoreboard_Next_In");
    }
    else if ( this->m_bHalftime )
    {
      CScoreboardScaleform::DisplayRemainingTime(
        this,
        remainingTime: (int)(float)(this->m_matchRestartTime - *(float *)(gpGlobals.m_Index + 12)),
        localizationStringId: "#SFUI_Scoreboard_Switch_In");
    }
    else if ( m_nValue <= 0 )
    {
      if ( MapRemainingTime == -1 )
      {
        CScoreboardScaleform::HideMatchEndConditions(this);
      }
      else
      {
        v11 = !C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules);
        v13 = "#SFUI_Scoreboard_FightTime";
        if ( v11 )
          v13 = "#SFUI_Scoreboard_TimeLeft";
        CScoreboardScaleform::DisplayRemainingTime(this, remainingTime: MapRemainingTime, localizationStringId: v13);
      }
    }
    else
    {
      CScoreboardScaleform::DisplayRemainingRounds(this, remainingRounds: m_nValue - v6);
    }
    m_selectionTeam = this->m_selectionTeam;
    if ( m_selectionTeam == 2 )
    {
      v15 = this->m_tScoreRows.m_Size - 1;
      if ( v15 >= this->m_tScores.m_Size - 1 )
        v15 = this->m_tScores.m_Size - 1;
    }
    else if ( m_selectionTeam == 3 )
    {
      v15 = this->m_ctScoreRows.m_Size - 1;
      if ( v15 >= this->m_ctScores.m_Size - 1 )
        v15 = this->m_ctScores.m_Size - 1;
    }
    else
    {
      v15 = -1;
    }
    m_selectionIndex = this->m_selectionIndex;
    if ( m_selectionIndex > v15 )
    {
      if ( m_selectionIndex >= 0 )
      {
        if ( m_selectionTeam == 3 )
        {
          if ( m_selectionIndex < this->m_ctScoreRows.m_Size )
          {
            v17 = &this->m_ctScoreRows.m_Memory.m_pMemory[m_selectionIndex];
            goto LABEL_50;
          }
        }
        else if ( m_selectionTeam == 2 && m_selectionIndex < this->m_tScoreRows.m_Size )
        {
          v17 = &this->m_tScoreRows.m_Memory.m_pMemory[m_selectionIndex];
          goto LABEL_50;
        }
      }
      v17 = nullptr;
LABEL_50:
      if ( v15 >= 0 )
      {
        this->m_selectionIndex = v15;
        if ( m_selectionTeam == 3 )
        {
          if ( v15 < this->m_ctScoreRows.m_Size )
          {
            CScoreboardScaleform::ChangeSelectedPlayerRow(
              this,
              rowToHide: v17,
              rowToShow: &this->m_ctScoreRows.m_Memory.m_pMemory[v15]);
            return;
          }
        }
        else if ( m_selectionTeam == 2 && v15 < this->m_tScoreRows.m_Size )
        {
          CScoreboardScaleform::ChangeSelectedPlayerRow(
            this,
            rowToHide: v17,
            rowToShow: &this->m_tScoreRows.m_Memory.m_pMemory[v15]);
          return;
        }
LABEL_70:
        CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v17, rowToShow: nullptr);
        return;
      }
      v18 = m_selectionTeam != 3;
      v19 = v18 + 2;
      if ( m_selectionTeam == 3 )
      {
        m_Size = this->m_tScoreRows.m_Size;
        v21 = this->m_tScores.m_Size;
      }
      else
      {
        if ( !v18 )
        {
LABEL_71:
          this->m_selectionTeam = 0;
          this->m_selectionIndex = -1;
          CScoreboardScaleform::ChangeSelectedPlayerRow(this, rowToHide: v17, rowToShow: nullptr);
          return;
        }
        m_Size = this->m_ctScoreRows.m_Size;
        v21 = this->m_ctScores.m_Size;
      }
      v22 = v21 - 1;
      v23 = m_Size - 1;
      if ( v23 >= v22 )
        v23 = v22;
      if ( v23 >= 0 )
      {
        this->m_selectionIndex = 0;
        this->m_selectionTeam = v19;
        if ( v19 == 3 )
        {
          if ( this->m_ctScoreRows.m_Size > 0 )
          {
            CScoreboardScaleform::ChangeSelectedPlayerRow(
              this,
              rowToHide: v17,
              rowToShow: this->m_ctScoreRows.m_Memory.m_pMemory);
            return;
          }
        }
        else if ( v19 == 2 && this->m_tScoreRows.m_Size > 0 )
        {
          CScoreboardScaleform::ChangeSelectedPlayerRow(
            this,
            rowToHide: v17,
            rowToShow: this->m_tScoreRows.m_Memory.m_pMemory);
          return;
        }
        goto LABEL_70;
      }
      goto LABEL_71;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212560
// Name: public: void CScoreboardScaleform::TimerCallback(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CScoreboardScaleform::TimerCallback(
        CScoreboardScaleform *this@<ecx>,
        int a2@<edi>,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  if ( this->m_bVisible )
  {
    CScoreboardScaleform::Populate(this);
    CScoreboardScaleform::UpdateSpectators(this);
    CScoreboardScaleform::PopulateHalfTimeScores(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212590
// Name: protected: void CScoreboardScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScoreboardScaleform::Show(CScoreboardScaleform *this@<ecx>, int a2@<edi>)
{
  void *m_hTopText; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  int m_iSplitScreenSlot; // eax
  int m_nValue; // edx
  IConVar *m_pConVar; // eax
  SplitScreenConVarRef pHideHud; // [esp+4h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+14h] [ebp-4h] BYREF

  if ( !this->m_bLoading )
  {
    if ( this->m_bFlashAPIIsValid )
    {
      CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
        this: &g_UISSGuard,
        slot: this->m_iFlashSlot - 2);
      m_hTopText = this->m_hTopText;
      if ( m_hTopText != nullptr )
        this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_hTopText, a3: this->m_bHalftime);
      for ( i = 1; ; i = 0 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        CScoreboardScaleform::Populate(this);
        CScoreboardScaleform::PopulateHalfTimeScores(this, a2);
        CScoreboardScaleform::DoInitialPlayerSelection(this);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "showPanel",
          a4: nullptr,
          a5: 0);
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    }
    else
    {
      this->m_bLoading = true;
      g_pScaleformUI->RequestElement(
        this: g_pScaleformUI,
        a2: this->m_iSplitScreenSlot + 2,
        a3: "Scoreboard",
        a4: (ScaleformUIFunctionHandlerObject *)this,
        a5: pScaleformFunctionHandler_CScoreboardScaleform_Scoreboard);
    }
  }
  if ( !this->m_bVisible )
  {
    SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: "hidehud");
    m_iSplitScreenSlot = this->m_iSplitScreenSlot;
    m_nValue = pHideHud.m_Info[m_iSplitScreenSlot].m_pConVarState->m_Value.m_nValue;
    m_pConVar = pHideHud.m_Info[m_iSplitScreenSlot].m_pConVar;
    this->m_PrevHideHudValue = m_nValue;
    m_pConVar->SetValue_2(this: m_pConVar, a2: 4);
  }
  this->m_bVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x102126C0
// Name: private: virtual void CScoreboardScaleform::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CScoreboardScaleform::ShowPanel(CScoreboardScaleform *this@<ecx>, int a2@<edi>, bool bShow)
{
  CScoreboardScaleform *v3; // ecx

  if ( bShow != LOBYTE(this->m_hTopText) )
  {
    v3 = (CScoreboardScaleform *)((char *)this - 20);
    if ( bShow )
      CScoreboardScaleform::Show(this: v3, a2);
    else
      CScoreboardScaleform::Hide(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102126F0
// Name: protected: virtual void CScoreboardScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CScoreboardScaleform::FlashReady(CScoreboardScaleform *this@<ecx>, int a2@<edi>)
{
  void *v3; // ebx
  int v4; // eax
  IScaleformUI_vtbl *v5; // edx
  void *v6; // edi
  bool v7; // zf

  v3 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: this->m_FlashAPI, a3: "ScoreBoard");
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IScaleformUI *, void *, const char *, int))g_pScaleformUI->Value_GetMember)(
           a1: g_pScaleformUI,
           a2: v3,
           a3: "InnerScoreBoard",
           a4: a2);
    v5 = g_pScaleformUI->__vftable;
    v6 = (void *)v4;
    if ( v4 != 0 )
    {
      this->m_hTeam1ScoreFirstHalf = (ISFTextObject *)((int (__stdcall *)(int))v5->TextObject_MakeTextObjectFromMember)(a1: v4);
      this->m_hTeam2ScoreFirstHalf = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                       this: g_pScaleformUI,
                                       a2: v6,
                                       a3: "Team2FirstHalfScore");
      this->m_hTeam1ScoreSecondHalf = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                        this: g_pScaleformUI,
                                        a2: v6,
                                        a3: "Team1SecondHalfScore");
      this->m_hTeam2ScoreSecondHalf = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                        this: g_pScaleformUI,
                                        a2: v6,
                                        a3: "Team2SecondHalfScore");
      this->m_hTeam1ScoreTotal = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                   this: g_pScaleformUI,
                                   a2: v6,
                                   a3: "TeamOneScoreTotal");
      this->m_hTeam2ScoreTotal = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                   this: g_pScaleformUI,
                                   a2: v6,
                                   a3: "TeamTwoScoreTotal");
      this->m_hMapName = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: v6,
                           a3: "MapName");
      this->m_hTimeLeft = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                            this: g_pScaleformUI,
                            a2: v6,
                            a3: "GameTime");
      this->m_hRoundsLeft = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: g_pScaleformUI,
                              a2: v6,
                              a3: "RoundsLeft");
      this->m_hTimerIcon = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: v6,
                             a3: "TimerIcon");
      this->m_hGameType = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                            this: g_pScaleformUI,
                            a2: v6,
                            a3: "GameType");
      this->m_hCTScore = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: v6,
                           a3: "CT_Score");
      this->m_hTScore = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: v6, a3: "T_Score");
      this->m_hNumCTs = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                          this: g_pScaleformUI,
                          a2: v6,
                          a3: "CT_NumberPlayers");
      this->m_hNumTs = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                         this: g_pScaleformUI,
                         a2: v6,
                         a3: "T_NumberPlayers");
      this->m_hNumSpectators = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                 this: g_pScaleformUI,
                                 a2: v6,
                                 a3: "Num_Spectators");
      this->m_hNavBar = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                          this: g_pScaleformUI,
                          a2: v6,
                          a3: "Navigation");
      this->m_hNavBarLeft = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: g_pScaleformUI,
                              a2: v6,
                              a3: "NavigationLeft");
      this->m_hTKillPointsHeader = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                     this: g_pScaleformUI,
                                     a2: v6,
                                     a3: "T_KillPoints_Header");
      this->m_hCTKillPointsHeader = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                      this: g_pScaleformUI,
                                      a2: v6,
                                      a3: "CT_KillPoints_Header");
      this->m_hSpectator1 = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: g_pScaleformUI,
                              a2: v6,
                              a3: "Spectator1");
      this->m_hSpectator2 = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: g_pScaleformUI,
                              a2: v6,
                              a3: "Spectator2");
      this->m_hCurrentVote = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                               this: g_pScaleformUI,
                               a2: v6,
                               a3: "CurrentVote");
      this->m_hTopText = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: v6, a3: "TopText");
      CScoreboardScaleform::RetrieveTableRowHandles(
        this,
        root: v6,
        tableName: "CT_Scoretable",
        rowNamePrefix: "CT_ScoreRow_",
        arrayToPopulate: (CUtlMemory<CAttachmentData,int> *)&this->m_ctScoreRows);
      CScoreboardScaleform::RetrieveTableRowHandles(
        this,
        root: v6,
        tableName: "T_Scoretable",
        rowNamePrefix: "T_ScoreRow_",
        arrayToPopulate: (CUtlMemory<CAttachmentData,int> *)&this->m_tScoreRows);
      g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: v6);
      g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: v3);
      v7 = !this->m_bVisible;
      this->m_bLoading = false;
      if ( v7 )
        CScoreboardScaleform::Hide(this);
      else
        CScoreboardScaleform::Show(this, a2: (int)"Team1FirstHalfScore");
    }
    else
    {
      ((void (__cdecl *)(void *))v5->ReleaseValue)(a1: v3);
    }
  }
}
