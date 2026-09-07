// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudwinpanel.cpp
// Functions: 14
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudwinpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10219B00
// Name: public: virtual void SFHudWinPanel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::SetActive(SFHudFreezePanel *this, bool bActive)
{
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10225DA0
// Name: public: virtual void SFHudWinPanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::FlashReady(SFHudWinPanel *this)
{
  void *m_FlashAPI; // eax
  void *v3; // eax
  ISFTextObject **m_hWinner; // edi
  ISFTextObject *v5; // esi
  void *v6; // eax
  char *panelNames[3]; // [esp+4h] [ebp-10h]
  int panelIdx; // [esp+10h] [ebp-4h]

  m_FlashAPI = this->m_FlashAPI;
  if ( m_FlashAPI != nullptr )
  {
    v3 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: m_FlashAPI, a3: "WinPanel");
    this->m_hRoot = v3;
    if ( v3 != nullptr )
    {
      panelNames[0] = "InnerWinPanel";
      panelNames[1] = "InnerWinPanelT";
      panelNames[2] = "InnerWinPanelDraw";
      panelIdx = 0;
      m_hWinner = this->m_hWinner;
      do
      {
        v5 = (ISFTextObject *)g_pScaleformUI->Value_GetMember(
                                this: g_pScaleformUI,
                                a2: this->m_hRoot,
                                a3: panelNames[panelIdx]);
        m_hWinner[18] = v5;
        if ( v5 != nullptr )
        {
          *m_hWinner = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                         this: g_pScaleformUI,
                         a2: v5,
                         a3: "WinnerText");
          m_hWinner[3] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: v5,
                           a3: "WinDescription");
          m_hWinner[6] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: v5,
                           a3: "AwardText");
          m_hWinner[9] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                           this: g_pScaleformUI,
                           a2: v5,
                           a3: "FunFact");
          m_hWinner[12] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                            this: g_pScaleformUI,
                            a2: v5,
                            a3: "WinText");
          m_hWinner[15] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                            this: g_pScaleformUI,
                            a2: v5,
                            a3: "TimerText");
        }
        ++m_hWinner;
        ++panelIdx;
      }
      while ( panelIdx < 3 );
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_end", a4: false);
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_start", a4: false);
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "cs_win_panel_round", a4: false);
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "cs_win_panel_match", a4: false);
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "round_mvp", a4: false);
      v6 = this->m_FlashAPI;
      if ( v6 != nullptr )
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: v6,
          a3: "hide",
          a4: nullptr,
          a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225F90
// Name: public: virtual void SFHudWinPanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::LevelInit(SFHudWinPanel *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "WinPanel",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudWinPanel_WinPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10225FC0
// Name: public: virtual bool SFHudWinPanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudWinPanel::PreUnloadFlash(SFHudWinPanel *this)
{
  void **m_hRootPanels; // edi
  char j; // al
  char k; // al
  char m; // al
  char n; // al
  char ii; // al
  char jj; // al
  int i; // [esp+Ch] [ebp-4h]

  m_hRootPanels = this->m_hRootPanels;
  for ( i = 3; i != 0; --i )
  {
    if ( this->m_pScaleformUI != nullptr && *m_hRootPanels != nullptr )
    {
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: *m_hRootPanels);
      *m_hRootPanels = nullptr;
    }
    if ( *(m_hRootPanels - 18) != nullptr )
    {
      for ( j = 1; j != 0; j = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 18) + 28))(a1: *(m_hRootPanels - 18));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 18) = nullptr;
    }
    if ( *(m_hRootPanels - 15) != nullptr )
    {
      for ( k = 1; k != 0; k = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 15) + 28))(a1: *(m_hRootPanels - 15));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 15) = nullptr;
    }
    if ( *(m_hRootPanels - 12) != nullptr )
    {
      for ( m = 1; m != 0; m = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 12) + 28))(a1: *(m_hRootPanels - 12));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 12) = nullptr;
    }
    if ( *(m_hRootPanels - 9) != nullptr )
    {
      for ( n = 1; n != 0; n = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 9) + 28))(a1: *(m_hRootPanels - 9));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 9) = nullptr;
    }
    if ( *(m_hRootPanels - 6) != nullptr )
    {
      for ( ii = 1; ii != 0; ii = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 6) + 28))(a1: *(m_hRootPanels - 6));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 6) = nullptr;
    }
    if ( *(m_hRootPanels - 3) != nullptr )
    {
      for ( jj = 1; jj != 0; jj = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*(m_hRootPanels - 3) + 28))(a1: *(m_hRootPanels - 3));
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *(m_hRootPanels - 3) = nullptr;
    }
    ++m_hRootPanels;
  }
  if ( this->m_pScaleformUI != nullptr && this->m_hRoot != nullptr )
  {
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_hRoot);
    this->m_hRoot = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102261D0
// Name: protected: void SFHudWinPanel::SetMVP(class C_CSPlayer __near *,enum CSMvpReason_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudWinPanel::SetMVP(SFHudWinPanel *this@<ecx>, int a2@<edi>, C_CSPlayer *pPlayer, int reason)
{
  C_CSPlayer *v5; // ebx
  C_BasePlayer *v6; // eax
  vgui::ILocalize_vtbl *v7; // edi
  const char *PlayerName; // eax
  char *v9; // eax
  const char *v10; // eax
  const wchar_t *v11; // eax
  int v12; // eax
  char i; // al
  ISFTextObject **m_hMVP; // edi
  ISFTextObject *v15; // ebx
  void *v16; // edi
  char j; // al
  ISFTextObject **v18; // edi
  ISFTextObject *v19; // ebx
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI_vtbl *v21; // edx
  void *v22; // edi
  wchar_t wszBuf[256]; // [esp+4h] [ebp-34Ch] BYREF
  char xuidText[256]; // [esp+204h] [ebp-14Ch] BYREF
  wchar_t wszPlayerName[32]; // [esp+304h] [ebp-4Ch] BYREF
  BOOL isDraw; // [esp+344h] [ebp-Ch]
  ISFTextObject **v28; // [esp+348h] [ebp-8h]
  BOOL isCT; // [esp+34Ch] [ebp-4h]
  C_CSPlayer *pPlayera; // [esp+358h] [ebp+8h]
  int idx; // [esp+35Ch] [ebp+Ch]
  ISFTextObject **idxa; // [esp+35Ch] [ebp+Ch]

  if ( this->m_bFlashAPIIsValid )
  {
    if ( g_PR != nullptr && (v5 = pPlayer, pPlayer != nullptr) )
    {
      if ( pPlayer->m_bIsControllingBot )
      {
        v6 = UTIL_PlayerByIndex(entindex: pPlayer->m_iControlledBotEntIndex);
        pPlayer = ToBasePlayer(pEntity: v6);
        v5 = pPlayer;
      }
      v7 = g_pVGuiLocalize->__vftable;
      PlayerName = C_BasePlayer::GetPlayerName(this: v5);
      v9 = UTIL_SafeName(oldName: PlayerName);
      ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *, int, int))v7->ConvertANSIToUnicode)(
        a1: g_pVGuiLocalize,
        a2: v9,
        a3: wszPlayerName,
        a4: 64,
        a5: a2);
      switch ( reason )
      {
        case 1:
          v10 = "winpanel_mvp_award_kills";
          break;
        case 2:
          v10 = "winpanel_mvp_award_bombplant";
          break;
        case 3:
          v10 = "winpanel_mvp_award_bombdefuse";
          break;
        case 4:
          v10 = "winpanel_mvp_award_rescue";
          break;
        case 5:
          v10 = "winpanel_mvp_award_gungame";
          break;
        default:
          v10 = "winpanel_mvp_award";
          break;
      }
      v11 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v10);
      if ( v11 == nullptr )
        v11 = L"%s1";
      g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: wszBuf, a3: 512, a4: v11, a5: 1, wszPlayerName);
      v12 = v5->entindex(this: &v5->IClientNetworkable);
      C_PlayerResource::FillXuidText(this: g_PR, iIndex: v12, buf: xuidText, bufSize: 0xFFu);
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        m_hMVP = this->m_hMVP;
        idx = 0;
        v28 = this->m_hMVP;
        do
        {
          if ( *m_hMVP != nullptr )
            (*m_hMVP)->SetText(this: *m_hMVP, a2: wszBuf);
          v15 = m_hMVP[12];
          if ( v15 != nullptr )
          {
            LOBYTE(isDraw) = idx == 2;
            LOBYTE(isCT) = pPlayer->GetTeamNumber(this: pPlayer) == 3;
            v16 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 4);
            if ( v16 != nullptr )
            {
              this->m_pScaleformUI->ValueArray_SetElement_6(this: this->m_pScaleformUI, a2: v16, a3: 0, a4: v15);
              this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v16, a3: 1, a4: xuidText);
              this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v16, a3: 2, a4: isDraw);
              this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v16, a3: 3, a4: isCT);
              this->m_pScaleformUI->Value_InvokeWithoutReturn(
                this: this->m_pScaleformUI,
                a2: this->m_FlashAPI,
                a3: "ShowAvatar",
                a4: v16,
                a5: 4u);
              this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v16, a3: 4u);
            }
            m_hMVP = v28;
          }
          ++m_hMVP;
          ++idx;
          v28 = m_hMVP;
        }
        while ( idx < 3 );
      }
    }
    else
    {
      for ( j = 1; j != 0; j = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        v18 = this->m_hMVP;
        pPlayera = nullptr;
        idxa = this->m_hMVP;
        do
        {
          if ( *v18 != nullptr )
            (*v18)->SetText_2(this: *v18, a2: prType);
          v19 = v18[12];
          if ( v19 != nullptr )
          {
            m_pScaleformUI = this->m_pScaleformUI;
            v21 = m_pScaleformUI->__vftable;
            LOBYTE(isCT) = pPlayera == (C_CSPlayer *)2;
            v22 = v21->CreateValueArray(this: m_pScaleformUI, a2: 2u);
            if ( v22 != nullptr )
            {
              this->m_pScaleformUI->ValueArray_SetElement_6(this: this->m_pScaleformUI, a2: v22, a3: 0, a4: v19);
              this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v22, a3: 1, a4: isCT);
              this->m_pScaleformUI->Value_InvokeWithoutReturn(
                this: this->m_pScaleformUI,
                a2: this->m_FlashAPI,
                a3: "HideAvatar",
                a4: v22,
                a5: 2u);
              this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v22, a3: 2u);
            }
            v18 = idxa;
          }
          ++v18;
          pPlayera = (C_CSPlayer *)((char *)pPlayera + 1);
          idxa = v18;
        }
        while ( (int)pPlayera < 3 );
      }
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226510
// Name: protected: void SFHudWinPanel::SetFunFactLabel(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::SetFunFactLabel(SFHudWinPanel *this, const wchar_t *szFunFact)
{
  char i; // al
  ISFTextObject **m_hFunFact; // esi
  int j; // edi

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      m_hFunFact = this->m_hFunFact;
      for ( j = 3; j != 0; --j )
      {
        if ( *m_hFunFact != nullptr )
          (*m_hFunFact)->SetText(this: *m_hFunFact, a2: L"%s", szFunFact);
        ++m_hFunFact;
      }
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226580
// Name: public: void SFHudWinPanel::TransitionToScoreboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::TransitionToScoreboard(SFHudWinPanel *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IViewPort *ViewPortInterface; // eax

  this->m_transitionToScoreboardTime = 0.0;
  for ( i = 1; ; i = 0 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "hide",
      a4: nullptr,
      a5: 0);
  }
  if ( m_pScaleformUI != nullptr )
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226600
// Name: private: void SFHudWinPanel::ShowTeamWinPanel(enum SFHudWinPanel::WinPanelTypes,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::ShowTeamWinPanel(
        SFHudWinPanel *this,
        SFHudWinPanel::WinPanelTypes type,
        const char *winnerText,
        const char *winText)
{
  char i; // al
  ISFTextObject_vtbl *v7; // edi
  wchar_t *v8; // eax
  ISFTextObject_vtbl *v9; // edi
  wchar_t *v10; // eax
  void *v11; // edi
  bool IsPlayingGunGameProgressive; // al
  IViewPort *ViewPortInterface; // eax
  void (__thiscall **typea)(IScaleformUI *, void *, int, bool); // [esp+10h] [ebp+8h]

  if ( this->m_hWinner[type] != nullptr && this->m_hWinIndicator[type] != nullptr && this->m_FlashAPI != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v7 = this->m_hWinner[type]->__vftable;
      v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: winnerText);
      v7->SetText(this: this->m_hWinner[type], a2: v8);
      v9 = this->m_hWinIndicator[type]->__vftable;
      v10 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: winText);
      v9->SetText(this: this->m_hWinIndicator[type], a2: v10);
      v11 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
      this->m_pScaleformUI->ValueArray_SetElement_6(
        this: this->m_pScaleformUI,
        a2: v11,
        a3: 0,
        a4: this->m_hRootPanels[type]);
      typea = &this->m_pScaleformUI->ValueArray_SetElement_3;
      IsPlayingGunGameProgressive = C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules);
      (*typea)(this: this->m_pScaleformUI, a2: v11, a3: 1, a4: IsPlayingGunGameProgressive);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showTeamWin",
        a4: v11,
        a5: 2u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v11, a3: 2u);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    if ( GetViewPortInterface() != nullptr )
    {
      ViewPortInterface = GetViewPortInterface();
      ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "all", a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226750
// Name: public: bool SFHudWinPanel::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFHudWinPanel::IsVisible(SFHudWinPanel *this)
{
  void *m_hRoot; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  bool result; // al
  ScaleformDisplayInfo dinfo; // [esp+0h] [ebp-38h] BYREF

  result = false;
  if ( this->m_bFlashAPIIsValid )
  {
    m_hRoot = this->m_hRoot;
    if ( m_hRoot != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      dinfo.m_iSetFlags = 0;
      m_pScaleformUI->Value_GetDisplayInfo(this: m_pScaleformUI, a2: m_hRoot, a3: &dinfo);
      if ( dinfo.m_bVisibility )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102267C0
// Name: public: void SFHudWinPanel::OnShowScoreboard(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall SFHudWinPanel::OnShowScoreboard(SFHudWinPanel *this, IScaleformUI *pui, IScaleformUI *obj)
{
  SFHudWinPanel::TransitionToScoreboard(this);
}

//------------------------------------------------------------------------------
// Address: 0x102267D0
// Name: public: virtual void SFHudWinPanel::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::FireGameEvent(SFHudWinPanel *this, IGameEvent *event)
{
  const char *v4; // esi
  char n; // al
  IScaleformUI *v6; // ecx
  char m; // al
  int v8; // eax
  C_BasePlayer *v9; // esi
  C_CSPlayer *v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  ISFTextObject **m_hTimer; // esi
  C_CSPlayer *v18; // esi
  C_BasePlayer *v19; // eax
  const char *PlayerName; // eax
  const char *v21; // esi
  wchar_t *v22; // eax
  vgui::ILocalize_vtbl *v23; // esi
  wchar_t *v24; // eax
  unsigned int m_pConVarState; // esi
  char j; // al
  IScaleformUI *v27; // ecx
  ISFTextObject **m_hReason; // esi
  int k; // ebx
  ISFTextObject *v30; // eax
  int v31; // [esp-4h] [ebp-328h]
  wchar_t funFactText[256]; // [esp+Ch] [ebp-318h] BYREF
  wchar_t playerText[64]; // [esp+20Ch] [ebp-118h] BYREF
  wchar_t dataText1[8]; // [esp+28Ch] [ebp-98h] BYREF
  wchar_t dataText2[8]; // [esp+29Ch] [ebp-88h] BYREF
  wchar_t time[8]; // [esp+2ACh] [ebp-78h] BYREF
  wchar_t dataText3[8]; // [esp+2BCh] [ebp-68h] BYREF
  char *endEventToString[16]; // [esp+2CCh] [ebp-58h] BYREF
  int param1; // [esp+30Ch] [ebp-18h]
  int param2; // [esp+310h] [ebp-14h]
  int param3; // [esp+314h] [ebp-10h] BYREF
  int v42; // [esp+318h] [ebp-Ch]
  ConVarRef v43; // [esp+31Ch] [ebp-8h] BYREF
  int wszEventMessage; // [esp+32Ch] [ebp+8h]
  const wchar_t *wszEventMessagea; // [esp+32Ch] [ebp+8h]
  const wchar_t *wszEventMessageb; // [esp+32Ch] [ebp+8h]

  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: "round_start", s2: v4) != 0 )
  {
    if ( _V_strcmp(s1: "cs_win_panel_match", s2: v4) != 0 )
    {
      if ( _V_strcmp(s1: "round_mvp", s2: v4) != 0 )
      {
        if ( _V_strcmp(s1: "cs_win_panel_round", s2: v4) == 0 && g_PR != nullptr )
        {
          if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules) )
          {
            ConVarRef::ConVarRef(this: (ConVarRef *)&param3, pName: "mp_ggprogressive_round_restart_delay");
            ConVarRef::ConVarRef(this: &v43, pName: "mp_ggprogressive_win_panel_pct");
            this->m_transitionToScoreboardTime = (float)(v43.m_pConVarState->m_Value.m_fValue * *(float *)(v42 + 44))
                                               + *(float *)(gpGlobals.m_Index + 12);
          }
          v11 = event->GetInt(this: event, a2: "timer_time", a3: 0);
          if ( v11 / 60 >= 0 )
          {
            v12 = 99;
            if ( v11 / 60 <= 99 )
              v12 = v11 / 60;
          }
          else
          {
            v12 = 0;
          }
          v13 = v11 % 60;
          v14 = v13;
          if ( v13 >= 0 )
          {
            if ( v13 > 59 )
              v14 = 59;
          }
          else
          {
            v14 = 0;
          }
          _snwprintf(string: time, count: 8u, format: L"%d:%02d", v12, v14);
          for ( i = 1; ; i = 0 )
          {
            m_pScaleformUI = this->m_pScaleformUI;
            if ( i == 0 )
              break;
            if ( m_pScaleformUI != nullptr )
              m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
            m_hTimer = this->m_hTimer;
            for ( wszEventMessage = 3; wszEventMessage != 0; --wszEventMessage )
            {
              if ( *m_hTimer != nullptr )
                (*m_hTimer)->SetText(this: *m_hTimer, a2: time);
              ++m_hTimer;
            }
          }
          if ( m_pScaleformUI != nullptr )
            m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
          SFHudWinPanel::SetFunFactLabel(this, szFunFact: &szFunFact);
          wszEventMessagea = (const wchar_t *)event->GetInt(this: event, a2: "funfact_player", a3: 0);
          v18 = (C_CSPlayer *)UTIL_PlayerByIndex(entindex: (int)wszEventMessagea);
          if ( v18 != nullptr && v18->IsPlayer(this: v18) )
          {
            if ( v18->m_bIsControllingBot )
            {
              v19 = UTIL_PlayerByIndex(entindex: v18->m_iControlledBotEntIndex);
              v18 = ToBasePlayer(pEntity: v19);
            }
          }
          else
          {
            v18 = nullptr;
          }
          v43.m_pConVarState = (ConVar *)event->GetString(this: event, a2: "funfact_token", a3: prType);
          if ( strlen((const char *)v43.m_pConVarState) != 0 )
          {
            param1 = event->GetInt(this: event, a2: "funfact_data1", a3: 0);
            param2 = event->GetInt(this: event, a2: "funfact_data2", a3: 0);
            v42 = event->GetInt(this: event, a2: "funfact_data3", a3: 0);
            if ( (unsigned int)wszEventMessagea - 1 > 0x3F )
            {
              V_snwprintf(pDest: playerText, maxLen: 64, pFormat: &szFunFact);
            }
            else if ( v18 != nullptr
                   && (PlayerName = C_BasePlayer::GetPlayerName(this: v18), v21 = PlayerName, PlayerName != nullptr)
                   && _V_strcmp(s1: PlayerName, s2: "unconnected") != 0
                   && _V_strcmp(s1: v21, s2: "ERRORNAME") != 0 )
            {
              V_strtowcs(pString: v21, nInSize: -1, pWString: playerText, nOutSize: 64);
            }
            else
            {
              v22 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#winpanel_former_player");
              V_snwprintf(pDest: playerText, maxLen: 64, pFormat: L"%s", v22);
            }
            V_snwprintf(pDest: dataText1, maxLen: 8, pFormat: L"%i", param1);
            V_snwprintf(pDest: dataText2, maxLen: 8, pFormat: L"%i", param2);
            V_snwprintf(pDest: dataText3, maxLen: 8, pFormat: L"%i", v42);
            v23 = g_pVGuiLocalize->__vftable;
            v24 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v43.m_pConVarState);
            ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, wchar_t *))v23->ConstructString_3)(
              a1: g_pVGuiLocalize,
              a2: funFactText,
              a3: 512,
              a4: v24);
            SFHudWinPanel::SetFunFactLabel(this, szFunFact: funFactText);
          }
          m_pConVarState = event->GetInt(this: event, a2: "final_event", a3: 0);
          v43.m_pConVarState = (ConVar *)m_pConVarState;
          _V_memset(dest: (int)endEventToString, fill: nullptr, count: 0x40u);
          endEventToString[0] = "#winpanel_end_target_bombed";
          endEventToString[2] = "#winpanel_end_vip_assassinated";
          endEventToString[3] = "#winpanel_end_terrorists_escaped";
          endEventToString[8] = "#winpanel_end_terrorists__kill";
          endEventToString[12] = "#winpanel_end_hostages_not_rescued";
          endEventToString[14] = "#winpanel_end_vip_not_escaped";
          endEventToString[1] = "#winpanel_end_vip_escaped";
          endEventToString[4] = "#winpanel_end_cts_prevent_escape";
          endEventToString[5] = "#winpanel_end_escaping_terrorists_neutralized";
          endEventToString[6] = "#winpanel_end_bomb_defused";
          endEventToString[7] = "#winpanel_end_cts_win";
          endEventToString[10] = "#winpanel_end_all_hostages_rescued";
          endEventToString[11] = "#winpanel_end_target_saved";
          endEventToString[13] = "#winpanel_end_terrorists_not_escaped";
          endEventToString[15] = (char *)prType;
          endEventToString[9] = (char *)prType;
          wszEventMessageb = nullptr;
          if ( m_pConVarState <= 0xF )
            wszEventMessageb = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: endEventToString[m_pConVarState]);
          for ( j = 1; ; j = 0 )
          {
            v27 = this->m_pScaleformUI;
            if ( j == 0 )
              break;
            if ( v27 != nullptr )
              v27->LockSlot(this: v27, a2: this->m_iFlashSlot);
            m_hReason = this->m_hReason;
            for ( k = 3; k != 0; --k )
            {
              if ( *m_hReason != nullptr )
              {
                v30 = *m_hReason;
                if ( wszEventMessageb != nullptr )
                  v30->SetText(this: v30, a2: wszEventMessageb);
                else
                  v30->SetText_2(this: v30, a2: prType);
              }
              ++m_hReason;
            }
            m_pConVarState = (unsigned int)v43.m_pConVarState;
          }
          if ( v27 != nullptr )
            v27->UnlockSlot(this: v27, a2: this->m_iFlashSlot);
          switch ( m_pConVarState )
          {
            case 0u:
            case 2u:
            case 3u:
            case 8u:
            case 0xCu:
            case 0xEu:
              SFHudWinPanel::ShowTeamWinPanel(
                this,
                type: WinPanel_T,
                winnerText: "SFUI_WinPanel_T_Win",
                winText: "SFUI_WinPanel_Win");
              break;
            case 1u:
            case 4u:
            case 5u:
            case 6u:
            case 7u:
            case 0xAu:
            case 0xBu:
            case 0xDu:
              SFHudWinPanel::ShowTeamWinPanel(
                this,
                type: WinPanel_CT,
                winnerText: "SFUI_WinPanel_CT_Win",
                winText: "SFUI_WinPanel_Win");
              break;
            case 9u:
              SFHudWinPanel::ShowTeamWinPanel(
                this,
                type: WinPanel_Draw,
                winnerText: "SFUI_WinPanel_Round_Draw",
                winText: "SFUI_WinPanel_Draw");
              break;
            default:
              break;
          }
          SFHudWinPanel::SetMVP(this, a2: (int)this, pPlayer: nullptr, reason: 0);
        }
      }
      else
      {
        v8 = event->GetInt(this: event, a2: "userid", a3: 0);
        v9 = UTIL_PlayerByUserId(userID: v8);
        if ( v9 != nullptr )
        {
          v31 = event->GetInt(this: event, a2: "reason", a3: 0);
          v10 = ToBasePlayer(pEntity: v9);
          SFHudWinPanel::SetMVP(this, a2: (int)this, pPlayer: v10, reason: v31);
        }
      }
    }
    else if ( this->m_FlashAPI != nullptr )
    {
      for ( m = 1; ; m = 0 )
      {
        v6 = this->m_pScaleformUI;
        if ( m == 0 )
          break;
        if ( v6 != nullptr )
          v6->LockSlot(this: v6, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hide",
          a4: nullptr,
          a5: 0);
      }
      if ( v6 != nullptr )
        goto LABEL_9;
    }
  }
  else
  {
    this->m_transitionToScoreboardTime = 0.0;
    if ( this->m_FlashAPI != nullptr )
    {
      for ( n = 1; ; n = 0 )
      {
        v6 = this->m_pScaleformUI;
        if ( n == 0 )
          break;
        if ( v6 != nullptr )
          v6->LockSlot(this: v6, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hide",
          a4: nullptr,
          a5: 0);
      }
      if ( v6 != nullptr )
LABEL_9:
        v6->UnlockSlot(this: v6, a2: this->m_iFlashSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226DF0
// Name: public: virtual void SFHudWinPanel::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudWinPanel::ProcessInput(SFHudWinPanel *this)
{
  float m_transitionToScoreboardTime; // xmm0_4

  if ( C_CSGameRules::IsPlayingGunGameProgressive(this: (C_CSGameRules *)g_pGameRules) )
  {
    m_transitionToScoreboardTime = this->m_transitionToScoreboardTime;
    if ( *(float *)(gpGlobals.m_Index + 12) > m_transitionToScoreboardTime && m_transitionToScoreboardTime > 0.0 )
      SFHudWinPanel::TransitionToScoreboard(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226E30
// Name: public: SFHudWinPanel::SFHudWinPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudWinPanel *__thiscall SFHudWinPanel::SFHudWinPanel(SFHudWinPanel *this, const char *value)
{
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
  this->__vftable = (SFHudWinPanel_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudWinPanel_vtbl *)&SFHudWinPanel::`vftable';
  this->m_hRoot = nullptr;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  this->m_transitionToScoreboardTime = 0.0;
  this->m_hWinner[0] = nullptr;
  this->m_hReason[0] = nullptr;
  this->m_hMVP[0] = nullptr;
  this->m_hFunFact[0] = nullptr;
  this->m_hWinIndicator[0] = nullptr;
  this->m_hTimer[0] = nullptr;
  this->m_hWinner[1] = nullptr;
  this->m_hReason[1] = nullptr;
  this->m_hMVP[1] = nullptr;
  this->m_hFunFact[1] = nullptr;
  this->m_hWinIndicator[1] = nullptr;
  this->m_hTimer[1] = nullptr;
  this->m_hWinner[2] = nullptr;
  this->m_hReason[2] = nullptr;
  this->m_hMVP[2] = nullptr;
  this->m_hFunFact[2] = nullptr;
  this->m_hWinIndicator[2] = nullptr;
  this->m_hTimer[2] = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10226EE0
// Name: Create_SFHudWinPanel
// Source: json
//------------------------------------------------------------------------------
SFHudWinPanel *__cdecl Create_SFHudWinPanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 164);
  memset(dst: v0, value: 0, count: 0xA4u);
  if ( v0 != nullptr )
    return SFHudWinPanel::SFHudWinPanel(this: (SFHudWinPanel *)v0, value: "SFHudWinPanel");
  else
    return nullptr;
}
