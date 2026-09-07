// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhud_teamcounter.cpp
// Functions: 25
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhud_teamcounter.h"

//------------------------------------------------------------------------------
// Address: 0x102172C0
// Name: public: bool MiniStatus::Update(unsigned __int64,int,int,bool,bool,bool,bool,bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall MiniStatus::Update(
        MiniStatus *this,
        unsigned __int64 _Xuid,
        int _PlayerIdx,
        int _GunGameLevel,
        bool _IsCT,
        bool _LocalPlayer,
        bool _Dead,
        bool _Dominated,
        bool _Dominating,
        bool _Speaking,
        bool _PlayerBot,
        bool _Spectated)
{
  bool result; // al

  if ( (_DWORD)_Xuid != LODWORD(this->nXUID)
    || __PAIR64__(_PlayerIdx, HIDWORD(_Xuid)) != *(unsigned __int64 *)((char *)&this->nXUID + 4)
    || _GunGameLevel != this->nGunGameLevel
    || _IsCT != this->bIsCT
    || _LocalPlayer != this->bLocalPlayer
    || _Dead != this->bDead
    || _Dominated != this->bDominated
    || _Dominating != this->bDominating
    || _Speaking != this->bSpeaking
    || _PlayerBot != this->bPlayerBot
    || (result = _Spectated ^ this->bSpectated) )
  {
    result = true;
  }
  this->bIsCT = _IsCT;
  this->bLocalPlayer = _LocalPlayer;
  this->bDead = _Dead;
  this->bDominated = _Dominated;
  LODWORD(this->nXUID) = _Xuid;
  this->bDominating = _Dominating;
  HIDWORD(this->nXUID) = HIDWORD(_Xuid);
  this->nGunGameLevel = _GunGameLevel;
  this->bSpeaking = _Speaking;
  this->nPlayerIdx = _PlayerIdx;
  this->bPlayerBot = _PlayerBot;
  this->bSpectated = _Spectated;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10217370
// Name: protected: static int SFHudTeamCounter::GGProgSortFunction(struct MiniStatus __near * const __near *,struct MiniStatus __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SFHudTeamCounter::GGProgSortFunction(MiniStatus *const *entry1, MiniStatus *const *entry2)
{
  int v2; // esi
  int v3; // ecx
  int v4; // eax
  int v5; // edx

  if ( entry1 != nullptr )
  {
    v2 = (int)*entry1;
    if ( *entry1 != nullptr )
    {
      if ( entry2 == nullptr )
        return -1;
      v3 = (int)*entry2;
      if ( *entry2 == nullptr )
        return -1;
      v4 = *(_DWORD *)(v2 + 12);
      v5 = *(_DWORD *)(v3 + 12);
      if ( v4 > v5 )
        return -1;
      if ( v4 >= v5 )
        return *(_DWORD *)(v2 + 8) - *(_DWORD *)(v3 + 8);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102173C0
// Name: protected: void SFHudTeamCounter::InvokeAvatarSlotUpdate(void __near * __near &,struct MiniStatus const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::InvokeAvatarSlotUpdate(
        SFHudTeamCounter *this,
        void **avatarData,
        const MiniStatus *ms,
        int slotNumber)
{
  char xuidAsText[256]; // [esp+8h] [ebp-100h] BYREF

  if ( ms != nullptr )
  {
    if ( *avatarData == nullptr )
      *avatarData = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 3);
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: *avatarData, a3: 0, a4: slotNumber);
    memset(xuidAsText, 0, sizeof(xuidAsText));
    C_PlayerResource::FillXuidText(this: g_PR, iIndex: ms->nPlayerIdx, buf: xuidAsText, bufSize: 0x100u);
    this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: *avatarData, a3: 1, a4: xuidAsText);
    this->m_pScaleformUI->ValueArray_SetElement_5(
      this: this->m_pScaleformUI,
      a2: *avatarData,
      a3: 2,
      a4: ms->bIsCT
    | (2
     * (ms->bLocalPlayer
      | (2
       * (ms->bDead
        | (2
         * (ms->bDominated
          | (2
           * (ms->bDominating
            | (2
             * (ms->bSpeaking | (2 * (ms->bPlayerBot | (2 * (ms->bSpectated | (2 * (ms->nGGProgressiveRank >= 0)))))))))))))))));
    g_pScaleformUI->Value_InvokeWithoutReturn(
      this: g_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "UpdateAvatarSlot",
      a4: *avatarData,
      a5: 3u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10217500
// Name: protected: void SFHudTeamCounter::GetIconHTML(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::GetIconHTML(
        SFHudTeamCounter *this,
        const char *szIcon,
        char *szBuffer,
        unsigned int nBufferSize)
{
  if ( _V_strcmp(s1: szIcon, s2: "ump45") != 0 )
  {
    if ( _V_strcmp(s1: szIcon, s2: "p90") != 0 )
    {
      if ( _V_strcmp(s1: szIcon, s2: "mac10") != 0 )
      {
        if ( _V_strcmp(s1: szIcon, s2: "glock") != 0 )
        {
          if ( _V_strcmp(s1: szIcon, s2: "fiveseven") != 0 )
          {
            if ( _V_strcmp(s1: szIcon, s2: "deagle") != 0 )
            {
              if ( _V_strcmp(s1: szIcon, s2: "bizon") != 0
                && _V_strcmp(s1: szIcon, s2: "mag7") != 0
                && _V_strcmp(s1: szIcon, s2: "negev") != 0
                && _V_strcmp(s1: szIcon, s2: "sawedoff") != 0
                && _V_strcmp(s1: szIcon, s2: "tec9") != 0
                && _V_strcmp(s1: szIcon, s2: "taser") != 0
                && _V_strcmp(s1: szIcon, s2: "molotov") != 0
                && _V_strcmp(s1: szIcon, s2: "decoy") != 0
                && _V_strcmp(s1: szIcon, s2: "hkp2000") != 0
                && _V_strcmp(s1: szIcon, s2: "mp7") != 0
                && _V_strcmp(s1: szIcon, s2: "mp9") != 0
                && _V_strcmp(s1: szIcon, s2: "nova") != 0
                && _V_strcmp(s1: szIcon, s2: "p250") != 0
                && _V_strcmp(s1: szIcon, s2: "scar20") != 0
                && _V_strcmp(s1: szIcon, s2: "sg556") != 0
                && _V_strcmp(s1: szIcon, s2: "ssg08") != 0 )
              {
                V_snprintf(
                  pDest: szBuffer,
                  maxLen: nBufferSize,
                  pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
                  szIcon,
                  54,
                  18);
              }
              else
              {
                V_snprintf(
                  pDest: szBuffer,
                  maxLen: nBufferSize,
                  pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
                  szIcon,
                  51,
                  31);
              }
            }
            else
            {
              V_snprintf(
                pDest: szBuffer,
                maxLen: nBufferSize,
                pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
                szIcon,
                32,
                16);
            }
          }
          else
          {
            V_snprintf(
              pDest: szBuffer,
              maxLen: nBufferSize,
              pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
              szIcon,
              33,
              18);
          }
        }
        else
        {
          V_snprintf(
            pDest: szBuffer,
            maxLen: nBufferSize,
            pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
            szIcon,
            36,
            18);
        }
      }
      else
      {
        V_snprintf(
          pDest: szBuffer,
          maxLen: nBufferSize,
          pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
          szIcon,
          26,
          18);
      }
    }
    else
    {
      V_snprintf(
        pDest: szBuffer,
        maxLen: nBufferSize,
        pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
        szIcon,
        43,
        16);
    }
  }
  else
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%i' height='%i'/>",
      szIcon,
      42,
      18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102177B0
// Name: protected: void SFHudTeamCounter::ResetLeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::ResetLeader(SFHudTeamCounter *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v3; // edi
  IGameEvent *v4; // esi
  int v5; // eax
  CSWeaponID CurrentGunGameWeapon; // eax
  char *v7; // eax
  int UserID; // eax
  const char *szWeaponName; // [esp+8h] [ebp-8h]
  C_CSGameRules *v10; // [esp+Ch] [ebp-4h]
  C_CSGameRules *v11; // [esp+Ch] [ebp-4h]

  this->m_nLeaderWeaponRank = -1;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( g_pGameRules != nullptr && LocalPlayer != nullptr )
  {
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_player_levelup", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v10 = (C_CSGameRules *)g_pGameRules;
      v5 = v3->GetTeamNumber(this: v3);
      CurrentGunGameWeapon = C_CSGameRules::GetCurrentGunGameWeapon(this: v10, nCurrentWeaponIndex: 0, nTeamID: v5);
      v7 = WeaponIdAsString(weaponID: CurrentGunGameWeapon);
      v11 = (C_CSGameRules *)v4->__vftable;
      szWeaponName = v7;
      UserID = C_BasePlayer::GetUserID(this: v3);
      ((void (__thiscall *)(IGameEvent *, const char *, int))LODWORD(v11->m_flGameStartTime.m_Value))(
        a1: v4,
        a2: "userid",
        a3: UserID);
      v4->SetString(this: v4, a2: "weaponname", a3: szWeaponName);
      v4->SetInt(this: v4, a2: "weaponrank", a3: 0);
      this->FireGameEvent(this, a2: v4);
      gameeventmanager->FreeEvent(this: gameeventmanager, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102178A0
// Name: public: virtual bool SFHudTeamCounter::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudTeamCounter::PreUnloadFlash(SFHudTeamCounter *this)
{
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pTimeGreenText);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pTimeRedText);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pCTScore);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pTScore);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pCTGunGameBombScore);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pTGunGameBombScore);
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pProgressiveLeader);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10217910
// Name: public: virtual void SFHudTeamCounter::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::LevelInit(SFHudTeamCounter *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "TeamCount",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudTeamCounter_TeamCount);
}

//------------------------------------------------------------------------------
// Address: 0x10217940
// Name: protected: void SFHudTeamCounter::UpdateTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::UpdateTimer(SFHudTeamCounter *this)
{
  C_PhysPropClientside *v1; // ebx
  char j; // al
  IScaleformUI *v4; // ecx
  double X; // st7
  int v6; // edi
  double RoundStartTime; // st7
  bool m_bRoundStarted; // cl
  ISFTextObject *m_pTimeRedText; // edx
  ISFTextObject *m_pTimeGreenText; // eax
  char v11; // bl
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  wchar_t szTime[32]; // [esp+14h] [ebp-44h] BYREF
  bool bBeginTimerAlert; // [esp+56h] [ebp-2h]
  bool bCancelTimerAlert; // [esp+57h] [ebp-1h]

  v1 = (C_PhysPropClientside *)g_pGameRules;
  bBeginTimerAlert = false;
  bCancelTimerAlert = false;
  if ( g_pGameRules != nullptr )
  {
    if ( g_PlantedC4s.m_Size <= 0 )
    {
      X = C_CSGameRules::GetRoundRemainingTime(this: (C_CSGameRules *)g_pGameRules);
      v6 = (int)ceil(X);
      if ( C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)v1) )
      {
        RoundStartTime = C_CSGameRules::GetRoundStartTime(this: v1);
        v6 = (int)ceil(X: RoundStartTime - *(float *)(gpGlobals.m_Index + 12));
      }
      m_bRoundStarted = this->m_bRoundStarted;
      if ( m_bRoundStarted )
      {
        if ( this->m_bTimerAlertTriggered )
        {
          if ( v6 >= 11 )
          {
            m_pTimeGreenText = this->m_pTimeGreenText;
            this->m_bTimerAlertTriggered = false;
            this->m_pTime = m_pTimeGreenText;
            bCancelTimerAlert = true;
          }
        }
        else if ( v6 < 11 )
        {
          m_pTimeRedText = this->m_pTimeRedText;
          this->m_bTimerAlertTriggered = true;
          this->m_pTime = m_pTimeRedText;
          bBeginTimerAlert = true;
        }
      }
      if ( v6 < 0 )
        v6 = 0;
      szTime[0] = 0;
      if ( this->m_pTime != nullptr && m_bRoundStarted )
      {
        V_snwprintf(pDest: szTime, maxLen: 32, pFormat: L"%d:%.2d", v6 / 60, v6 % 60);
        v11 = 1;
      }
      else
      {
        if ( !bBeginTimerAlert && !bCancelTimerAlert )
          return;
        v11 = 0;
      }
      for ( i = 1; ; i = 0 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        if ( bCancelTimerAlert )
          g_pScaleformUI->Value_InvokeWithoutReturn(
            this: g_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "onBeginTimerNormal",
            a4: nullptr,
            a5: 0);
        if ( bBeginTimerAlert )
          g_pScaleformUI->Value_InvokeWithoutReturn(
            this: g_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "onBeginTimerAlert",
            a4: nullptr,
            a5: 0);
        if ( v11 != 0 )
          this->m_pTime->SetText(this: this->m_pTime, a2: szTime);
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    }
    else if ( !this->m_bTimerHidden )
    {
      this->m_bTimerHidden = true;
      for ( j = 1; ; j = 0 )
      {
        v4 = this->m_pScaleformUI;
        if ( j == 0 )
          break;
        if ( v4 != nullptr )
          v4->LockSlot(this: v4, a2: this->m_iFlashSlot);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "onHideTimer",
          a4: nullptr,
          a5: 0);
      }
      if ( v4 != nullptr )
        v4->UnlockSlot(this: v4, a2: this->m_iFlashSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10217B50
// Name: protected: void SFHudTeamCounter::UpdateScore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::UpdateScore(SFHudTeamCounter *this)
{
  int v1; // ebx
  int v2; // edi
  SFHudTeamCounter::VIEW_MODE m_Mode; // eax
  C_Team *GlobalTeam; // eax
  C_Team *v6; // eax
  C_CS_PlayerResource *v7; // eax
  int v8; // edi
  char *v9; // ebx
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  ISFTextObject *m_pTScore; // ecx
  ISFTextObject *m_pCTScore; // ecx
  int m_nBOPCurrentUpdate; // eax
  ISFTextObject *m_pCTGunGameBombScore; // ecx
  ISFTextObject *m_pTGunGameBombScore; // ecx
  C_CS_PlayerResource *cs_PR; // [esp+2Ch] [ebp-18h]
  float totalTGunGameBombScore; // [esp+30h] [ebp-14h]
  float totalCTGunGameBombScore; // [esp+34h] [ebp-10h]
  int nCTScore; // [esp+38h] [ebp-Ch]
  int nTScore; // [esp+3Ch] [ebp-8h]
  bool bShowTotalBombScore; // [esp+43h] [ebp-1h]

  v1 = 0;
  v2 = 0;
  totalTGunGameBombScore = 0.0;
  totalCTGunGameBombScore = 0.0;
  bShowTotalBombScore = false;
  nCTScore = 0;
  nTScore = 0;
  if ( g_PR != nullptr )
  {
    m_Mode = this->m_Mode;
    if ( m_Mode == VIEW_MODE_NORMAL || m_Mode == VIEW_MODE_GUN_GAME_BOMB )
    {
      GlobalTeam = GetGlobalTeam(iTeamNumber: 3);
      if ( GlobalTeam != nullptr )
      {
        nCTScore = GlobalTeam->Get_Score(this: GlobalTeam);
        v1 = nCTScore;
      }
      v6 = GetGlobalTeam(iTeamNumber: 2);
      if ( v6 != nullptr )
      {
        nTScore = v6->Get_Score(this: v6);
        v2 = nTScore;
      }
      if ( v1 == v2 )
        this->m_nBOPCurrentUpdate = 0;
      else
        this->m_nBOPCurrentUpdate = (v2 <= v1) + 2;
    }
    if ( C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules) )
    {
      bShowTotalBombScore = true;
      v7 = (C_CS_PlayerResource *)__RTDynamicCast(
                                    inptr: g_PR,
                                    VfDelta: 0,
                                    SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                    TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                    isReference: 0);
      cs_PR = v7;
      if ( v7 != nullptr )
      {
        v8 = 1;
        v9 = (char *)&v7->IGameResources;
        do
        {
          if ( (*(unsigned __int8 (__thiscall **)(char *, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v8) != 0 )
          {
            if ( (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 52))(a1: v9, a2: v8) == 2 )
            {
              totalTGunGameBombScore = (float)C_CS_PlayerResource::GetScore(this: cs_PR, iIndex: v8)
                                     + totalTGunGameBombScore;
            }
            else if ( (*(int (__thiscall **)(char *, int))(*(_DWORD *)v9 + 52))(a1: v9, a2: v8) == 3 )
            {
              totalCTGunGameBombScore = (float)C_CS_PlayerResource::GetScore(this: cs_PR, iIndex: v8)
                                      + totalCTGunGameBombScore;
            }
          }
          ++v8;
        }
        while ( v8 <= 64 );
        v2 = nTScore;
        v1 = nCTScore;
      }
    }
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      m_pTScore = this->m_pTScore;
      if ( m_pTScore != nullptr && this->m_nTCountLastUpdate != v2 )
      {
        this->m_nTCountLastUpdate = v2;
        m_pTScore->SetText_4(this: m_pTScore, a2: v2);
      }
      m_pCTScore = this->m_pCTScore;
      if ( m_pCTScore != nullptr && this->m_nCTCountLastUpdate != v1 )
      {
        this->m_nCTCountLastUpdate = v1;
        m_pCTScore->SetText_4(this: m_pCTScore, a2: v1);
      }
      m_nBOPCurrentUpdate = this->m_nBOPCurrentUpdate;
      if ( m_nBOPCurrentUpdate != this->m_nBOPLastUpdate )
        this->m_nBOPLastUpdate = m_nBOPCurrentUpdate;
      if ( bShowTotalBombScore )
      {
        m_pCTGunGameBombScore = this->m_pCTGunGameBombScore;
        if ( m_pCTGunGameBombScore != nullptr )
          ((void (__stdcall *)(float))m_pCTGunGameBombScore->SetText_3)(a1: COERCE_FLOAT(LODWORD(totalCTGunGameBombScore)));
        m_pTGunGameBombScore = this->m_pTGunGameBombScore;
        if ( m_pTGunGameBombScore != nullptr )
          ((void (__stdcall *)(float))m_pTGunGameBombScore->SetText_3)(a1: COERCE_FLOAT(LODWORD(totalTGunGameBombScore)));
      }
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10217D50
// Name: public: virtual void SFHudTeamCounter::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::FireGameEvent(SFHudTeamCounter *this, IGameEvent *event)
{
  const char *v3; // ebx
  char k; // al
  IScaleformUI *m_pScaleformUI; // ecx
  char i; // al
  int v7; // eax
  IVEngineClient_vtbl *v8; // ebx
  int v9; // eax
  int v10; // ebx
  const char *v11; // edi
  int v12; // ebx
  const char *v13; // ecx
  const char *v14; // eax
  char j; // al
  ISFTextObject *m_pProgressiveLeader; // eax
  wchar_t wCompleteHTML[128]; // [esp+Ch] [ebp-200h] BYREF
  char szCompleteHTML[128]; // [esp+10Ch] [ebp-100h] BYREF
  char szWeaponHTML[64]; // [esp+18Ch] [ebp-80h] BYREF
  char szPlayerHTML[64]; // [esp+1CCh] [ebp-40h] BYREF
  const char *szPlayerName; // [esp+214h] [ebp+8h]

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "round_start") != 0 )
  {
    if ( _V_strcmp(s1: v3, s2: "round_end") == 0 )
    {
      this->m_pTime = this->m_pTimeGreenText;
      *(_WORD *)&this->m_bTimerAlertTriggered = 0;
      return;
    }
    if ( _V_strcmp(s1: v3, s2: "cs_match_end_restart") != 0 )
    {
      if ( _V_strcmp(s1: v3, s2: "bomb_planted") == 0 )
      {
        if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
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
              a3: "onHideTimer",
              a4: nullptr,
              a5: 0);
          }
          if ( m_pScaleformUI != nullptr )
            goto LABEL_12;
        }
        return;
      }
      if ( _V_strcmp(s1: v3, s2: "player_spawn") != 0 )
      {
        if ( (_V_strcmp(s1: v3, s2: "gg_player_levelup") == 0
           || _V_strcmp(s1: v3, s2: "ggprogressive_player_levelup") == 0
           || _V_strcmp(s1: v3, s2: "ggtr_player_levelup") == 0)
          && this->m_FlashAPI != nullptr
          && this->m_pScaleformUI != nullptr
          && g_PR != nullptr )
        {
          v7 = event->GetInt(this: event, a2: "weaponrank", a3: 0);
          if ( v7 > this->m_nLeaderWeaponRank )
          {
            this->m_nLeaderWeaponRank = v7;
            v8 = engine->__vftable;
            v9 = event->GetInt(this: event, a2: "userid", a3: 0);
            v10 = v8->GetPlayerForUserID(this: engine, a2: v9);
            v11 = event->GetString(this: event, a2: "weaponname", a3: prType);
            if ( V_strncmp(s1: v11, s2: "weapon_", count: 7) == 0 )
              v11 += 7;
            if ( v10 <= 0 )
              szPlayerName = prType;
            else
              szPlayerName = g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: v10);
            v12 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: v10);
            SFHudTeamCounter::GetIconHTML(this, szIcon: v11, szBuffer: szWeaponHTML, nBufferSize: 0x40u);
            if ( v12 == 3 )
            {
              v13 = "CT: ";
              v14 = "#6e7d5c";
            }
            else
            {
              v13 = "T: ";
              v14 = "#9d511b";
            }
            V_snprintf(
              pDest: szPlayerHTML,
              maxLen: 0x40u,
              pFormat: "<font color=\"%s\">%s%s </font>",
              v14,
              v13,
              szPlayerName);
            V_snprintf(pDest: szCompleteHTML, maxLen: 0x80u, pFormat: "%s%s", szPlayerHTML, szWeaponHTML);
            g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szCompleteHTML, a3: wCompleteHTML, a4: 256);
            for ( j = 1; j != 0; j = 0 )
            {
              ScaleformFlashInterfaceMixin<CHudElement>::LockScaleformSlot(this);
              m_pProgressiveLeader = this->m_pProgressiveLeader;
              if ( m_pProgressiveLeader != nullptr )
                m_pProgressiveLeader->SetTextHTML(this: m_pProgressiveLeader, a2: wCompleteHTML);
            }
            ScaleformFlashInterfaceMixin<CHudElement>::UnlockScaleformSlot(this);
          }
        }
        return;
      }
      if ( this->m_nLeaderWeaponRank != -1 )
        return;
    }
    SFHudTeamCounter::ResetLeader(this);
    return;
  }
  this->m_bRoundStarted = true;
  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    for ( k = 1; ; k = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( k == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "onBeginTimerNormal",
        a4: nullptr,
        a5: 0);
      if ( this->m_Mode == VIEW_MODE_GUN_GAME_PROGRESSIVE )
        SFHudTeamCounter::ResetLeader(this);
    }
    if ( m_pScaleformUI != nullptr )
LABEL_12:
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102180B0
// Name: protected: void SFHudTeamCounter::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::ShowPanel(SFHudTeamCounter *this, bool bShow)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_FlashAPI != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      m_pScaleformUI = this->m_pScaleformUI;
      if ( bShow )
        m_pScaleformUI->Value_InvokeWithoutReturn(
          this: m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "ShowPanel",
          a4: nullptr,
          a5: 0);
      else
        m_pScaleformUI->Value_InvokeWithoutReturn(
          this: m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "HidePanel",
          a4: nullptr,
          a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10218130
// Name: protected: void SFHudTeamCounter::SetViewMode(enum SFHudTeamCounter::VIEW_MODE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::SetViewMode(SFHudTeamCounter *this, SFHudTeamCounter::VIEW_MODE mode)
{
  char v2; // al
  IScaleformUI *m_pScaleformUI; // ecx
  char v5; // al

  v2 = mode;
  this->m_Mode = mode;
  if ( mode == VIEW_MODE_GUN_GAME_PROGRESSIVE )
  {
    while ( 1 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( v2 == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "onSetModeGunGameProgressive",
        a4: nullptr,
        a5: 0);
      v2 = 0;
    }
    goto LABEL_17;
  }
  v5 = 1;
  if ( mode != VIEW_MODE_GUN_GAME_BOMB )
  {
    while ( 1 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( v5 == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "onSetModeNormal",
        a4: nullptr,
        a5: 0);
      SFHudTeamCounter::UpdateScore(this);
      v5 = 0;
    }
LABEL_17:
    if ( m_pScaleformUI == nullptr )
      return;
    goto LABEL_18;
  }
  while ( 1 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( v5 == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "onSetModeGunGameBomb",
      a4: nullptr,
      a5: 0);
    v5 = 0;
  }
  if ( m_pScaleformUI != nullptr )
LABEL_18:
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10218230
// Name: public: virtual void SFHudTeamCounter::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::SetActive(SFHudTeamCounter *this, bool bActive)
{
  if ( this->m_bFlashAPIIsValid && bActive != this->m_bActive )
    SFHudTeamCounter::ShowPanel(this, bShow: bActive);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10218260
// Name: public: virtual void SFHudTeamCounter::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudTeamCounter::FlashReady(SFHudTeamCounter *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // zf
  char v5; // al
  IScaleformUI *v6; // ecx
  IScaleformUI *m_pScaleformUI; // ecx
  void *v8; // eax
  void *v9; // edi
  void *v10; // eax
  void *v11; // ebx
  void *v12; // eax
  ISFTextObject *v13; // eax
  ISFTextObject *m_pTimeGreenText; // eax
  void *v15; // eax
  void *v16; // eax
  ISFTextObject *m_pCTScore; // eax
  void *v18; // eax
  ISFTextObject *m_pTScore; // eax
  void *v20; // eax
  ISFTextObject *m_pCTGunGameBombScore; // eax
  void *v22; // eax
  ISFTextObject *m_pTGunGameBombScore; // eax
  IScaleformUI *v24; // ecx
  int *p_nGGProgressiveRank; // eax
  int i; // ecx
  MiniStatus *m_GGProgressivePlayers; // eax
  int j; // ecx
  int v29; // [esp-8h] [ebp-1Ch]
  int v30; // [esp-4h] [ebp-18h]
  void *topPanel; // [esp+4h] [ebp-10h]
  void *panel; // [esp+8h] [ebp-Ch] BYREF
  void *tLabelPanel; // [esp+Ch] [ebp-8h] BYREF
  void *timeTextRed; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    this->m_bRegisteredForEvents = true;
    ((void (__thiscall *)(IGameEventManager2 *, SFHudTeamCounter *, const char *, _DWORD, int, int))gameeventmanager->AddListener)(
      a1: gameeventmanager,
      a2: this,
      a3: "round_start",
      a4: 0,
      a5: a3,
      a6: a2);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_end", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "cs_match_end_restart", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "bomb_planted", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_spawn", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "gg_player_levelup", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "ggprogressive_player_levelup", a4: false);
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "ggtr_player_levelup", a4: false);
    if ( this->m_GGProgRankingTimer.m_timestamp.m_Value != -1.0 )
    {
      this->m_GGProgRankingTimer.NetworkStateChanged(
        this: &this->m_GGProgRankingTimer,
        a2: &this->m_GGProgRankingTimer.m_timestamp);
      this->m_GGProgRankingTimer.m_timestamp.m_Value = -1.0;
    }
    if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules) )
    {
      SFHudTeamCounter::SetViewMode(this, mode: VIEW_MODE_GUN_GAME_PROGRESSIVE);
    }
    else
    {
      v4 = !C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules);
      v5 = 1;
      if ( v4 )
      {
        this->m_Mode = VIEW_MODE_NORMAL;
        while ( 1 )
        {
          m_pScaleformUI = this->m_pScaleformUI;
          if ( v5 == 0 )
            break;
          if ( m_pScaleformUI != nullptr )
            m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "onSetModeNormal",
            a4: nullptr,
            a5: 0);
          SFHudTeamCounter::UpdateScore(this);
          v5 = 0;
        }
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      }
      else
      {
        this->m_Mode = VIEW_MODE_GUN_GAME_BOMB;
        while ( 1 )
        {
          v6 = this->m_pScaleformUI;
          if ( v5 == 0 )
            break;
          if ( v6 != nullptr )
            v6->LockSlot(this: v6, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "onSetModeGunGameBomb",
            a4: nullptr,
            a5: 0);
          v5 = 0;
        }
        if ( v6 != nullptr )
          v6->UnlockSlot(this: v6, a2: this->m_iFlashSlot);
        this->m_nLeaderWeaponRank = -1;
      }
    }
    v8 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "TopPanel");
    topPanel = v8;
    if ( v8 != nullptr )
    {
      v9 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "Panel");
      panel = v9;
      if ( v9 != nullptr )
      {
        v10 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int, int))this->m_pScaleformUI->Value_GetMember)(
                        a1: this->m_pScaleformUI,
                        a2: v9,
                        a3: "ProgressiveLeader",
                        a4: v29,
                        a5: v30);
        timeTextRed = v10;
        if ( v10 != nullptr )
        {
          this->m_pProgressiveLeader = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                         this: this->m_pScaleformUI,
                                         a2: v10,
                                         a3: "Text");
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &timeTextRed);
        }
        v11 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "Time");
        tLabelPanel = v11;
        if ( v11 != nullptr )
        {
          v12 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v11, a3: "TimeGreen");
          timeTextRed = v12;
          if ( v12 != nullptr )
          {
            v13 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                    this: this->m_pScaleformUI,
                    a2: v12,
                    a3: "Text");
            this->m_pTimeGreenText = v13;
            this->m_pTime = v13;
            ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &timeTextRed);
            m_pTimeGreenText = this->m_pTimeGreenText;
            if ( m_pTimeGreenText != nullptr )
              m_pTimeGreenText->SetText(this: m_pTimeGreenText, a2: L"0:00");
          }
          v15 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v11, a3: "TimeRed");
          timeTextRed = v15;
          if ( v15 != nullptr )
          {
            this->m_pTimeRedText = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                     this: this->m_pScaleformUI,
                                     a2: v15,
                                     a3: "Text");
            ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &timeTextRed);
          }
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &tLabelPanel);
        }
        v16 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "CTLabel");
        tLabelPanel = v16;
        if ( v16 != nullptr )
        {
          this->m_pCTScore = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                               this: this->m_pScaleformUI,
                               a2: v16,
                               a3: "CTCount");
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &tLabelPanel);
          m_pCTScore = this->m_pCTScore;
          if ( m_pCTScore != nullptr )
            m_pCTScore->SetText(this: m_pCTScore, a2: L"0");
        }
        v18 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "TLabel");
        tLabelPanel = v18;
        if ( v18 != nullptr )
        {
          this->m_pTScore = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: this->m_pScaleformUI,
                              a2: v18,
                              a3: "TCount");
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &tLabelPanel);
          m_pTScore = this->m_pTScore;
          if ( m_pTScore != nullptr )
            m_pTScore->SetText(this: m_pTScore, a2: L"0");
        }
        v20 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v9, a3: "GunGameBombCTScore");
        tLabelPanel = v20;
        if ( v20 != nullptr )
        {
          this->m_pCTGunGameBombScore = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                          this: this->m_pScaleformUI,
                                          a2: v20,
                                          a3: "Text");
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &tLabelPanel);
          m_pCTGunGameBombScore = this->m_pCTGunGameBombScore;
          if ( m_pCTGunGameBombScore != nullptr )
            m_pCTGunGameBombScore->SetText(this: m_pCTGunGameBombScore, a2: L"0");
        }
        v22 = (void *)((int (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->Value_GetMember)(a1: this->m_pScaleformUI);
        tLabelPanel = v22;
        if ( v22 != nullptr )
        {
          this->m_pTGunGameBombScore = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                         this: this->m_pScaleformUI,
                                         a2: v22,
                                         a3: "Text");
          ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &tLabelPanel);
          m_pTGunGameBombScore = this->m_pTGunGameBombScore;
          if ( m_pTGunGameBombScore != nullptr )
            m_pTGunGameBombScore->SetText(this: m_pTGunGameBombScore, a2: L"0");
        }
        ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(this, value: &panel);
      }
      v24 = this->m_pScaleformUI;
      if ( v24 != nullptr )
        v24->ReleaseValue(this: v24, a2: topPanel);
    }
    SFHudTeamCounter::ShowPanel(this, bShow: false);
    p_nGGProgressiveRank = &this->m_CTTeam[0].nGGProgressiveRank;
    for ( i = 5; i != 0; --i )
    {
      *((_QWORD *)p_nGGProgressiveRank - 3) = 0;
      *((_QWORD *)p_nGGProgressiveRank - 2) = 0;
      *((_QWORD *)p_nGGProgressiveRank - 1) = 0;
      *(_QWORD *)p_nGGProgressiveRank = 0;
      *(p_nGGProgressiveRank - 6) = 0;
      *(p_nGGProgressiveRank - 5) = 0;
      *(p_nGGProgressiveRank - 4) = -1;
      *p_nGGProgressiveRank = -1;
      *((_QWORD *)p_nGGProgressiveRank - 23) = 0;
      *((_QWORD *)p_nGGProgressiveRank - 22) = 0;
      *((_QWORD *)p_nGGProgressiveRank - 21) = 0;
      *((_QWORD *)p_nGGProgressiveRank - 20) = 0;
      *(p_nGGProgressiveRank - 46) = 0;
      *(p_nGGProgressiveRank - 45) = 0;
      *(p_nGGProgressiveRank - 44) = -1;
      *(p_nGGProgressiveRank - 40) = -1;
      p_nGGProgressiveRank += 8;
    }
    m_GGProgressivePlayers = this->m_GGProgressivePlayers;
    for ( j = 10; j != 0; --j )
    {
      m_GGProgressivePlayers->nXUID = 0;
      *(_QWORD *)&m_GGProgressivePlayers->nPlayerIdx = 0;
      *(_QWORD *)&m_GGProgressivePlayers->bIsCT = 0;
      *(_QWORD *)&m_GGProgressivePlayers->nGGProgressiveRank = 0;
      LODWORD(m_GGProgressivePlayers->nXUID) = 0;
      HIDWORD(m_GGProgressivePlayers->nXUID) = 0;
      m_GGProgressivePlayers->nPlayerIdx = -1;
      m_GGProgressivePlayers->nGGProgressiveRank = -1;
      ++m_GGProgressivePlayers;
    }
    this->m_nTerroristTeamCount = 0;
    this->m_nCTTeamCount = 0;
    this->m_nPreviousGGProgressiveTotalPlayers = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102187D0
// Name: public: SFHudTeamCounter::SFHudTeamCounter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudTeamCounter *__thiscall SFHudTeamCounter::SFHudTeamCounter(SFHudTeamCounter *this, const char *value)
{
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (SFHudTeamCounter_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudTeamCounter_vtbl *)&SFHudTeamCounter::`vftable';
  this->m_pTimeRedText = nullptr;
  this->m_pTimeGreenText = nullptr;
  this->m_pTime = nullptr;
  this->m_pCTScore = nullptr;
  this->m_pTScore = nullptr;
  this->m_pProgressiveLeader = nullptr;
  this->m_pCTGunGameBombScore = nullptr;
  this->m_pTGunGameBombScore = nullptr;
  *(_WORD *)&this->m_bTimerAlertTriggered = 256;
  this->m_bTimerHidden = false;
  this->m_nBOPLastUpdate = 0;
  this->m_nBOPCurrentUpdate = 0;
  this->m_nLeaderWeaponRank = -1;
  this->m_Mode = VIEW_MODE_NORMAL;
  this->m_nTerroristTeamCount = -1;
  this->m_nCTTeamCount = -1;
  this->m_nTCountLastUpdate = 1;
  this->m_nCTCountLastUpdate = 1;
  LODWORD(this->m_TerroristTeam[0].nXUID) = 0;
  HIDWORD(this->m_TerroristTeam[0].nXUID) = 0;
  this->m_TerroristTeam[0].nPlayerIdx = -1;
  this->m_TerroristTeam[0].nGunGameLevel = -1;
  *(_DWORD *)&this->m_TerroristTeam[0].bIsCT = 0;
  *(_DWORD *)&this->m_TerroristTeam[0].bDominating = 0;
  this->m_TerroristTeam[0].nGGProgressiveRank = -1;
  this->m_TerroristTeam[1].nXUID = 0;
  this->m_TerroristTeam[1].nPlayerIdx = -1;
  this->m_TerroristTeam[1].nGunGameLevel = -1;
  *(_DWORD *)&this->m_TerroristTeam[1].bIsCT = 0;
  *(_DWORD *)&this->m_TerroristTeam[1].bDominating = 0;
  this->m_TerroristTeam[1].nGGProgressiveRank = -1;
  this->m_TerroristTeam[2].nXUID = 0;
  this->m_TerroristTeam[2].nPlayerIdx = -1;
  this->m_TerroristTeam[2].nGunGameLevel = -1;
  *(_DWORD *)&this->m_TerroristTeam[2].bIsCT = 0;
  *(_DWORD *)&this->m_TerroristTeam[2].bDominating = 0;
  this->m_TerroristTeam[2].nGGProgressiveRank = -1;
  this->m_TerroristTeam[3].nXUID = 0;
  this->m_TerroristTeam[3].nPlayerIdx = -1;
  this->m_TerroristTeam[3].nGunGameLevel = -1;
  *(_DWORD *)&this->m_TerroristTeam[3].bIsCT = 0;
  *(_DWORD *)&this->m_TerroristTeam[3].bDominating = 0;
  this->m_TerroristTeam[3].nGGProgressiveRank = -1;
  this->m_TerroristTeam[4].nXUID = 0;
  this->m_TerroristTeam[4].nPlayerIdx = -1;
  this->m_TerroristTeam[4].nGunGameLevel = -1;
  *(_DWORD *)&this->m_TerroristTeam[4].bIsCT = 0;
  *(_DWORD *)&this->m_TerroristTeam[4].bDominating = 0;
  this->m_TerroristTeam[4].nGGProgressiveRank = -1;
  LODWORD(this->m_CTTeam[0].nXUID) = 0;
  HIDWORD(this->m_CTTeam[0].nXUID) = 0;
  this->m_CTTeam[0].nPlayerIdx = -1;
  this->m_CTTeam[0].nGunGameLevel = -1;
  *(_DWORD *)&this->m_CTTeam[0].bIsCT = 0;
  *(_DWORD *)&this->m_CTTeam[0].bDominating = 0;
  this->m_CTTeam[0].nGGProgressiveRank = -1;
  this->m_CTTeam[1].nXUID = 0;
  this->m_CTTeam[1].nPlayerIdx = -1;
  this->m_CTTeam[1].nGunGameLevel = -1;
  *(_DWORD *)&this->m_CTTeam[1].bIsCT = 0;
  *(_DWORD *)&this->m_CTTeam[1].bDominating = 0;
  this->m_CTTeam[1].nGGProgressiveRank = -1;
  this->m_CTTeam[2].nXUID = 0;
  this->m_CTTeam[2].nPlayerIdx = -1;
  this->m_CTTeam[2].nGunGameLevel = -1;
  *(_DWORD *)&this->m_CTTeam[2].bIsCT = 0;
  *(_DWORD *)&this->m_CTTeam[2].bDominating = 0;
  this->m_CTTeam[2].nGGProgressiveRank = -1;
  this->m_CTTeam[3].nXUID = 0;
  this->m_CTTeam[3].nPlayerIdx = -1;
  this->m_CTTeam[3].nGunGameLevel = -1;
  *(_DWORD *)&this->m_CTTeam[3].bIsCT = 0;
  *(_DWORD *)&this->m_CTTeam[3].bDominating = 0;
  this->m_CTTeam[3].nGGProgressiveRank = -1;
  this->m_CTTeam[4].nXUID = 0;
  this->m_CTTeam[4].nPlayerIdx = -1;
  this->m_CTTeam[4].nGunGameLevel = -1;
  *(_DWORD *)&this->m_CTTeam[4].bIsCT = 0;
  *(_DWORD *)&this->m_CTTeam[4].bDominating = 0;
  this->m_CTTeam[4].nGGProgressiveRank = -1;
  this->m_nPreviousGGProgressiveTotalPlayers = -1;
  LODWORD(this->m_GGProgressivePlayers[0].nXUID) = 0;
  HIDWORD(this->m_GGProgressivePlayers[0].nXUID) = 0;
  this->m_GGProgressivePlayers[0].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[0].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[0].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[0].bDominating = 0;
  this->m_GGProgressivePlayers[0].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[1].nXUID = 0;
  this->m_GGProgressivePlayers[1].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[1].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[1].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[1].bDominating = 0;
  this->m_GGProgressivePlayers[1].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[2].nXUID = 0;
  this->m_GGProgressivePlayers[2].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[2].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[2].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[2].bDominating = 0;
  this->m_GGProgressivePlayers[2].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[3].nXUID = 0;
  this->m_GGProgressivePlayers[3].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[3].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[3].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[3].bDominating = 0;
  this->m_GGProgressivePlayers[3].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[4].nXUID = 0;
  this->m_GGProgressivePlayers[4].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[4].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[4].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[4].bDominating = 0;
  this->m_GGProgressivePlayers[4].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[5].nXUID = 0;
  this->m_GGProgressivePlayers[5].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[5].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[5].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[5].bDominating = 0;
  this->m_GGProgressivePlayers[5].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[6].nXUID = 0;
  this->m_GGProgressivePlayers[6].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[6].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[6].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[6].bDominating = 0;
  this->m_GGProgressivePlayers[6].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[7].nXUID = 0;
  this->m_GGProgressivePlayers[7].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[7].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[7].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[7].bDominating = 0;
  this->m_GGProgressivePlayers[7].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[8].nXUID = 0;
  this->m_GGProgressivePlayers[8].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[8].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[8].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[8].bDominating = 0;
  this->m_GGProgressivePlayers[8].nGGProgressiveRank = -1;
  this->m_GGProgressivePlayers[9].nXUID = 0;
  this->m_GGProgressivePlayers[9].nPlayerIdx = -1;
  this->m_GGProgressivePlayers[9].nGunGameLevel = -1;
  *(_DWORD *)&this->m_GGProgressivePlayers[9].bIsCT = 0;
  *(_DWORD *)&this->m_GGProgressivePlayers[9].bDominating = 0;
  this->m_GGProgressivePlayers[9].nGGProgressiveRank = -1;
  this->m_GGProgRankingTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v3 = this->m_GGProgRankingTimer.__vftable;
  this->m_GGProgRankingTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v3->NetworkStateChanged)(a1: &this->m_GGProgRankingTimer.m_duration);
  v4 = this->m_GGProgRankingTimer.__vftable;
  this->m_GGProgRankingTimer.m_timestamp.m_Value = -1.0;
  v4->NetworkStateChanged(this: &this->m_GGProgRankingTimer, a2: &this->m_GGProgRankingTimer.m_timestamp);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10218C00
// Name: protected: void SFHudTeamCounter::UpdateMiniScoreboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::UpdateMiniScoreboard(SFHudTeamCounter *this)
{
  C_CSPlayer *LocalPlayer; // edi
  int i; // edi
  int v4; // eax
  C_BasePlayer *v5; // eax
  C_BasePlayer *v6; // ebx
  CVoiceStatus *ClientVoiceMgr; // eax
  int v8; // ebx
  unsigned __int64 Xuid; // rax
  int v10; // eax
  int v11; // ecx
  MiniStatus *m_CTTeam; // eax
  MiniStatus *v13; // ebx
  int v14; // eax
  bool IsPlayerDominated; // al
  IScaleformUI *m_pScaleformUI; // ecx
  int nGGProgressiveRank; // eax
  IScaleformUI *v18; // ecx
  void *v19; // edi
  double v20; // st7
  int m_Size; // edi
  MiniStatus **m_pMemory; // ebx
  int *v23; // eax
  int j; // edi
  int v25; // edx
  IScaleformUI *v26; // ecx
  int *p_nPlayerIdx; // eax
  int v28; // ecx
  void *v29; // edi
  int v30; // edx
  IScaleformUI *v31; // ecx
  int *v32; // eax
  int v33; // ecx
  void *v34; // edi
  IScaleformUI *v35; // ecx
  int v36; // ecx
  bool IsPlayerDominatingMe; // [esp-18h] [ebp-78h]
  bool v38; // [esp-10h] [ebp-70h]
  const MiniStatus *v39; // [esp-10h] [ebp-70h]
  CUtlVector<MiniStatus *,CUtlMemory<MiniStatus *,int> > SortedList; // [esp+4h] [ebp-5Ch] BYREF
  unsigned __int64 playerXuid; // [esp+18h] [ebp-48h]
  float bIsCT; // [esp+20h] [ebp-40h]
  BOOL bIsSpectating; // [esp+24h] [ebp-3Ch]
  int TeamId; // [esp+28h] [ebp-38h]
  int localPlayerIndex; // [esp+2Ch] [ebp-34h]
  int NewIdx; // [esp+30h] [ebp-30h]
  BOOL bIsLocalPlayer; // [esp+34h] [ebp-2Ch]
  BOOL bDead; // [esp+38h] [ebp-28h]
  C_CSPlayer *pLocalPlayer; // [esp+3Ch] [ebp-24h]
  BOOL bSpeaking; // [esp+40h] [ebp-20h]
  int spectatedTargetIndex; // [esp+44h] [ebp-1Ch]
  void *avatarData; // [esp+48h] [ebp-18h] BYREF
  int BotControlledIdx; // [esp+4Ch] [ebp-14h]
  int slotIdx; // [esp+50h] [ebp-10h]
  int nCTTeamCount; // [esp+54h] [ebp-Ch]
  int nTerroristTeamCount; // [esp+58h] [ebp-8h]
  bool bGunGameProgressive; // [esp+5Eh] [ebp-2h]
  bool bSlotIsLocked; // [esp+5Fh] [ebp-1h]

  if ( !this->m_bFlashAPIIsValid )
    return;
  LocalPlayer = CClientTools::GetLocalPlayer();
  pLocalPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return;
  localPlayerIndex = GetLocalPlayerIndex();
  this->m_nTeamSelectionLastUpdate = LocalPlayer->GetTeamNumber(this: LocalPlayer);
  spectatedTargetIndex = -1;
  if ( GetSpectatorMode() == 4 || GetSpectatorMode() == 5 )
    spectatedTargetIndex = GetSpectatorTarget();
  bGunGameProgressive = C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules);
  nTerroristTeamCount = 0;
  nCTTeamCount = 0;
  avatarData = nullptr;
  bSlotIsLocked = false;
  BotControlledIdx = -1;
  if ( LocalPlayer->m_bIsControllingBot )
    BotControlledIdx = LocalPlayer->m_iControlledBotEntIndex;
  for ( i = 1; i <= 64; ++i )
  {
    if ( g_PR->IsConnected(this: &g_PR->IGameResources, a2: i) )
    {
      v4 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: i);
      TeamId = v4;
      if ( v4 == 3 || v4 == 2 )
      {
        NewIdx = -1;
        if ( bGunGameProgressive )
        {
          v5 = UTIL_PlayerByIndex(entindex: i);
          v6 = v5;
          if ( v5 != nullptr && v5->IsPlayer(this: v5) )
            NewIdx = *((_DWORD *)&v6[1].m_VarMap + 7);
        }
        LOBYTE(bIsLocalPlayer) = localPlayerIndex == i;
        ClientVoiceMgr = GetClientVoiceMgr();
        v8 = 1 << ((i - 1) & 0x1F);
        slotIdx = 4 * ((i - 1) >> 5);
        LOBYTE(bSpeaking) = (v8 & *(unsigned int *)((_BYTE *)ClientVoiceMgr->m_VoicePlayers.m_Ints + slotIdx)) != 0;
        if ( bSpeaking
          && !g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: i)
          && (v8 & *(unsigned int *)((_BYTE *)GetClientVoiceMgr()->m_AudiblePlayers.m_Ints + slotIdx)) == 0 )
        {
          LOBYTE(bSpeaking) = 0;
        }
        LOBYTE(bIsCT) = TeamId == 3;
        Xuid = C_PlayerResource::GetXuid(this: g_PR, iIndex: i);
        HIDWORD(playerXuid) = HIDWORD(Xuid);
        HIDWORD(Xuid) = g_PR->IGameResources::__vftable;
        LODWORD(playerXuid) = Xuid;
        LOBYTE(bDead) = (*(unsigned __int8 (__thiscall **)(IGameResources *, int))(HIDWORD(Xuid) + 20))(
                          a1: &g_PR->IGameResources,
                          a2: i) == 0
                     || bIsLocalPlayer && BotControlledIdx != -1;
        LOBYTE(bIsSpectating) = i == spectatedTargetIndex;
        if ( TeamId == 3 )
        {
          if ( nCTTeamCount == 5 )
            continue;
          v10 = nTerroristTeamCount;
          slotIdx = nCTTeamCount;
          v11 = ++nCTTeamCount;
        }
        else
        {
          if ( nTerroristTeamCount == 5 )
            continue;
          v11 = nCTTeamCount;
          slotIdx = nTerroristTeamCount;
          v10 = ++nTerroristTeamCount;
        }
        if ( bGunGameProgressive )
        {
          v14 = v11 + v10 - 1;
          slotIdx = v14;
          if ( v14 >= 10 )
            continue;
          v13 = &this->m_GGProgressivePlayers[v14];
        }
        else
        {
          m_CTTeam = this->m_CTTeam;
          if ( TeamId != 3 )
            m_CTTeam = this->m_TerroristTeam;
          v13 = &m_CTTeam[slotIdx];
        }
        v38 = BotControlledIdx == i;
        IsPlayerDominatingMe = C_CSPlayer::IsPlayerDominatingMe(this: pLocalPlayer, iPlayerIndex: i);
        IsPlayerDominated = C_CSPlayer::IsPlayerDominated(this: pLocalPlayer, iPlayerIndex: i);
        if ( MiniStatus::Update(
               this: v13,
               _Xuid: playerXuid,
               _PlayerIdx: i,
               _GunGameLevel: NewIdx,
               _IsCT: SLOBYTE(bIsCT),
               _LocalPlayer: bIsLocalPlayer,
               _Dead: bDead,
               _Dominated: IsPlayerDominated,
               _Dominating: IsPlayerDominatingMe,
               _Speaking: bSpeaking,
               _PlayerBot: v38,
               _Spectated: bIsSpectating)
          && (!bGunGameProgressive || v13->nGGProgressiveRank != -1) )
        {
          if ( !bSlotIsLocked )
          {
            m_pScaleformUI = this->m_pScaleformUI;
            if ( m_pScaleformUI != nullptr )
              m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
            bSlotIsLocked = true;
          }
          if ( bGunGameProgressive )
            nGGProgressiveRank = v13->nGGProgressiveRank;
          else
            nGGProgressiveRank = slotIdx;
          SFHudTeamCounter::InvokeAvatarSlotUpdate(this, &avatarData, ms: v13, slotNumber: nGGProgressiveRank);
        }
      }
    }
  }
  if ( bGunGameProgressive )
  {
    if ( nCTTeamCount + nTerroristTeamCount != this->m_nPreviousGGProgressiveTotalPlayers )
    {
      v18 = this->m_pScaleformUI;
      this->m_nPreviousGGProgressiveTotalPlayers = nCTTeamCount + nTerroristTeamCount;
      v19 = v18->CreateValueArray(this: v18, a2: 1u);
      this->m_pScaleformUI->ValueArray_SetElement_5(
        this: this->m_pScaleformUI,
        a2: v19,
        a3: 0,
        a4: this->m_nPreviousGGProgressiveTotalPlayers);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "UpdateTotalProgressivePlayers",
        a4: v19,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v19, a3: 1u);
      goto LABEL_53;
    }
    if ( this->m_GGProgRankingTimer.m_timestamp.m_Value <= 0.0
      || CountdownTimer::Now(this: (CEffectsClient *)&this->m_GGProgRankingTimer) > this->m_GGProgRankingTimer.m_timestamp.m_Value )
    {
LABEL_53:
      v20 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_GGProgRankingTimer) + 2.0;
      bIsCT = v20;
      if ( this->m_GGProgRankingTimer.m_timestamp.m_Value != v20 )
      {
        this->m_GGProgRankingTimer.NetworkStateChanged(
          this: &this->m_GGProgRankingTimer,
          a2: &this->m_GGProgRankingTimer.m_timestamp);
        this->m_GGProgRankingTimer.m_timestamp.m_Value = bIsCT;
      }
      if ( this->m_GGProgRankingTimer.m_duration.m_Value != 2.0 )
      {
        this->m_GGProgRankingTimer.NetworkStateChanged(
          this: &this->m_GGProgRankingTimer,
          a2: &this->m_GGProgRankingTimer.m_duration);
        this->m_GGProgRankingTimer.m_duration.m_Value = 2.0;
      }
      m_Size = 0;
      m_pMemory = nullptr;
      memset(&SortedList, 0, sizeof(SortedList));
      NewIdx = 0;
      if ( this->m_nPreviousGGProgressiveTotalPlayers > 0 )
      {
        slotIdx = (int)this->m_GGProgressivePlayers;
        do
        {
          BotControlledIdx = m_Size;
          if ( m_Size + 1 > SortedList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&SortedList,
              num: m_Size - SortedList.m_Memory.m_nAllocationCount + 1);
            m_Size = SortedList.m_Size;
            m_pMemory = SortedList.m_Memory.m_pMemory;
          }
          SortedList.m_Size = ++m_Size;
          SortedList.m_pElements = m_pMemory;
          if ( m_Size - BotControlledIdx - 1 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[BotControlledIdx + 1],
              src: (unsigned __int8 *)&m_pMemory[BotControlledIdx],
              count: 4 * (m_Size - BotControlledIdx - 1));
          v23 = (int *)&m_pMemory[BotControlledIdx];
          if ( v23 != nullptr )
            *v23 = slotIdx;
          slotIdx += 32;
          ++NewIdx;
        }
        while ( NewIdx < this->m_nPreviousGGProgressiveTotalPlayers );
      }
      CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
        this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&SortedList,
        pfnCompare: (int (__cdecl *)(const void *, const void *))SFHudTeamCounter::GGProgSortFunction);
      for ( j = 0; j < this->m_nPreviousGGProgressiveTotalPlayers; ++j )
      {
        v39 = m_pMemory[j];
        v39->nGGProgressiveRank = j;
        SFHudTeamCounter::InvokeAvatarSlotUpdate(this, &avatarData, ms: v39, slotNumber: j);
      }
      if ( SortedList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
  else
  {
    v25 = nTerroristTeamCount;
    if ( nTerroristTeamCount != this->m_nTerroristTeamCount && nTerroristTeamCount < 5 )
    {
      if ( !bSlotIsLocked )
      {
        v26 = this->m_pScaleformUI;
        if ( v26 != nullptr )
        {
          v26->LockSlot(this: v26, a2: this->m_iFlashSlot);
          v25 = nTerroristTeamCount;
        }
        bSlotIsLocked = true;
      }
      p_nPlayerIdx = &this->m_TerroristTeam[v25].nPlayerIdx;
      v28 = 5 - v25;
      do
      {
        *p_nPlayerIdx = -1;
        p_nPlayerIdx += 8;
        --v28;
      }
      while ( v28 != 0 );
      v29 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
      this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v29, a3: 0, a4: false);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v29, a3: 1, a4: nTerroristTeamCount);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisablePlayerIcons",
        a4: v29,
        a5: 2u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v29, a3: 2u);
    }
    v30 = nCTTeamCount;
    if ( nCTTeamCount != this->m_nCTTeamCount && nCTTeamCount < 5 )
    {
      if ( !bSlotIsLocked )
      {
        v31 = this->m_pScaleformUI;
        if ( v31 != nullptr )
        {
          v31->LockSlot(this: v31, a2: this->m_iFlashSlot);
          v30 = nCTTeamCount;
        }
        bSlotIsLocked = true;
      }
      v32 = &this->m_CTTeam[v30].nPlayerIdx;
      v33 = 5 - v30;
      do
      {
        *v32 = -1;
        v32 += 8;
        --v33;
      }
      while ( v33 != 0 );
      v34 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
      this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v34, a3: 0, a4: true);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v34, a3: 1, a4: nCTTeamCount);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisablePlayerIcons",
        a4: v34,
        a5: 2u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v34, a3: 2u);
    }
  }
  if ( avatarData != nullptr )
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: avatarData, a3: 3u);
  if ( bSlotIsLocked )
  {
    v35 = this->m_pScaleformUI;
    if ( v35 != nullptr )
      v35->UnlockSlot(this: v35, a2: this->m_iFlashSlot);
  }
  v36 = nCTTeamCount;
  this->m_nTerroristTeamCount = nTerroristTeamCount;
  this->m_nCTTeamCount = v36;
}

//------------------------------------------------------------------------------
// Address: 0x102192A0
// Name: Create_SFHudTeamCounter
// Source: json
//------------------------------------------------------------------------------
SFHudTeamCounter *__cdecl Create_SFHudTeamCounter()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 808);
  memset(dst: v0, value: 0, count: 0x328u);
  if ( v0 != nullptr )
    return SFHudTeamCounter::SFHudTeamCounter(this: (SFHudTeamCounter *)v0, value: "SFHudTeamCounter");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102192E0
// Name: public: virtual void SFHudTeamCounter::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTeamCounter::ProcessInput(SFHudTeamCounter *this)
{
  SFHudTeamCounter::UpdateTimer(this);
  SFHudTeamCounter::UpdateScore(this);
  SFHudTeamCounter::UpdateMiniScoreboard(this);
}

//------------------------------------------------------------------------------
// Address: 0x1042F6D0
// Name: _SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl SelectWeightedSequence_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1042F6E0
// Name: _dynamic_atexit_destructor_for__cl_showanimstate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showanimstate__()
{
  ConVar::~ConVar(this: &cl_showanimstate);
}

//------------------------------------------------------------------------------
// Address: 0x1042F6F0
// Name: _dynamic_atexit_destructor_for__showanimstate_log__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showanimstate_log__()
{
  ConVar::~ConVar(this: &showanimstate_log);
}

//------------------------------------------------------------------------------
// Address: 0x1042F700
// Name: _dynamic_atexit_destructor_for__showanimstate_activities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showanimstate_activities__()
{
  ConVar::~ConVar(this: &showanimstate_activities);
}

//------------------------------------------------------------------------------
// Address: 0x1042F710
// Name: _dynamic_atexit_destructor_for__mp_feetyawrate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_feetyawrate__()
{
  ConVar::~ConVar(this: &mp_feetyawrate);
}

//------------------------------------------------------------------------------
// Address: 0x1042F720
// Name: _dynamic_atexit_destructor_for__mp_facefronttime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_facefronttime__()
{
  ConVar::~ConVar(this: &mp_facefronttime);
}

//------------------------------------------------------------------------------
// Address: 0x1042F730
// Name: _dynamic_atexit_destructor_for__mp_ik__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_ik__()
{
  ConVar::~ConVar(this: &mp_ik);
}
