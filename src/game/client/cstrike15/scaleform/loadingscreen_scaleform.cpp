// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/loadingscreen_scaleform.cpp
// Functions: 18
// ============================================================

#include "game\client\cstrike15\scaleform\loadingscreen_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020B570
// Name: public: virtual void CLoadingScreenScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingScreenScaleform::PostUnloadFlash(CLoadingScreenScaleform *this)
{
  CLoadingScreenScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CLoadingScreenScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020B590
// Name: public: static void CLoadingScreenScaleform::DisplayVACBannedError(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLoadingScreenScaleform::DisplayVACBannedError()
{
  _Warning(a1: "CLoadingScreenScaleform::DisplayVACBannedError Not Implemented\n");
}

//------------------------------------------------------------------------------
// Address: 0x1020B5A0
// Name: public: static void CLoadingScreenScaleform::DisplayNoSteamConnectionError(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLoadingScreenScaleform::DisplayNoSteamConnectionError()
{
  _Warning(a1: "CLoadingScreenScaleform::DisplayNoSteamConnectionError Not Implemented\n");
}

//------------------------------------------------------------------------------
// Address: 0x1020B5B0
// Name: public: static void CLoadingScreenScaleform::DisplayLoggedInElsewhereError(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLoadingScreenScaleform::DisplayLoggedInElsewhereError()
{
  _Warning(a1: "CLoadingScreenScaleform::DisplayLoggedInElsewhereError Not Implemented\n");
}

//------------------------------------------------------------------------------
// Address: 0x1020B5C0
// Name: public: static bool CLoadingScreenScaleform::IsOpen(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CLoadingScreenScaleform::IsOpen()
{
  return CLoadingScreenScaleform::m_pInstance != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1020B5E0
// Name: public: void CLoadingScreenScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingScreenScaleform::Show(CLoadingScreenScaleform *this)
{
  char i; // al
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax
  CGameUI *v6; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showPanel",
        a4: nullptr,
        a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "LoadingScreenOpened");
    else
      v4 = nullptr;
    v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v5->BroadcastEvent(this: v5, a2: v4);
    CCreateMainMenuScreenScaleform::ShowPanel(bShow: false, immediate: true);
    v6 = GameUI();
    CGameUI::SetBackgroundMusicDesired(this: v6, bPlayMusic: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B690
// Name: public: virtual bool CLoadingScreenScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLoadingScreenScaleform::PreUnloadFlash(CLoadingScreenScaleform *this)
{
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pPlayerCount);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pType);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pMode);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pScenario);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pCTInstructions);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTInstructions);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTitleText);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTLabel);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pCTLabel);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pRulesLabel);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pGeneralInstructions);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(
    this,
    value: &this->m_pRetrievingDataNotification);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020B720
// Name: protected: void CLoadingScreenScaleform::PopulateLevelInfo(char const __near *,char const __near *,char const __near *,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLoadingScreenScaleform::PopulateLevelInfo(
        CLoadingScreenScaleform *this@<ecx>,
        int a2@<edi>,
        const char *mapName,
        const char *gameTypeNameID,
        const char *gameModeNameID,
        bool isGunGameProgressive,
        bool isGunGameSelect,
        bool isGunGameTRBomb)
{
  char i; // al
  void *v10; // edi
  const wchar_t *v11; // eax
  const wchar_t *v12; // edi
  const wchar_t *v13; // ebx
  bool v14; // bl
  bool v15; // zf
  BOOL v16; // edi
  const wchar_t *v17; // eax
  vgui::ILocalize_vtbl *v18; // edx
  int v19; // eax
  const wchar_t *v20; // eax
  vgui::ILocalize_vtbl *v21; // edx
  const wchar_t *v22; // eax
  vgui::ILocalize_vtbl *v23; // edx
  int v25; // [esp-4h] [ebp-44h]
  char mapLookup[44]; // [esp+8h] [ebp-38h] BYREF
  BOOL showUnifiedRules; // [esp+34h] [ebp-Ch]
  const wchar_t *generalInstructions; // [esp+38h] [ebp-8h]
  const wchar_t *scenarioName; // [esp+3Ch] [ebp-4h]
  const wchar_t *ctInstructions; // [esp+4Ch] [ebp+Ch]
  const wchar_t *tInstructions; // [esp+50h] [ebp+10h]

  if ( mapName == nullptr || (int)_V_strlen(str: mapName) < 3 )
    return;
  if ( this->m_pRetrievingDataNotification != nullptr )
    this->m_pRetrievingDataNotification->SetVisible(this: this->m_pRetrievingDataNotification, a2: false);
  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v10 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
    this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v10, a3: 0, a4: mapName);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "setMapImage",
      a4: v10,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v10, a3: 1u);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  mapLookup[0] = 0;
  V_snprintf(pDest: mapLookup, maxLen: 0x2Bu, pFormat: "#SFUI_Map_%s", mapName);
  v11 = (const wchar_t *)((int (__thiscall *)(IScaleformUI *, char *, _DWORD, int))g_pScaleformUI->Translate)(
                           a1: g_pScaleformUI,
                           a2: mapLookup,
                           a3: 0,
                           a4: a2);
  if ( this->m_pTitleText != nullptr && v11 != nullptr )
    this->m_pTitleText->SetText(this: this->m_pTitleText, a2: v11);
  v12 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: gameTypeNameID);
  v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: gameModeNameID);
  if ( this->m_pType != nullptr && v12 != nullptr )
    this->m_pType->SetText(this: this->m_pType, a2: v12);
  if ( this->m_pMode != nullptr && v13 != nullptr )
    this->m_pMode->SetText(this: this->m_pMode, a2: v13);
  scenarioName = &szFunFact;
  ctInstructions = &szFunFact;
  tInstructions = &szFunFact;
  generalInstructions = &szFunFact;
  v14 = isGunGameSelect || isGunGameProgressive;
  v15 = this->m_pTLabel == nullptr;
  LOBYTE(showUnifiedRules) = v14;
  if ( !v15 )
    this->m_pTLabel->SetVisible(this: this->m_pTLabel, a2: !v14);
  if ( this->m_pCTLabel != nullptr )
    this->m_pCTLabel->SetVisible(this: this->m_pCTLabel, a2: !v14);
  if ( this->m_pScenario != nullptr )
    this->m_pScenario->SetVisible(this: this->m_pScenario, a2: !v14);
  if ( this->m_pTInstructions != nullptr )
    this->m_pTInstructions->SetVisible(this: this->m_pTInstructions, a2: !v14);
  if ( this->m_pCTInstructions != nullptr )
    this->m_pCTInstructions->SetVisible(this: this->m_pCTInstructions, a2: !v14);
  v16 = showUnifiedRules;
  if ( this->m_pRulesLabel != nullptr )
    this->m_pRulesLabel->SetVisible(this: this->m_pRulesLabel, a2: showUnifiedRules);
  if ( this->m_pGeneralInstructions != nullptr )
    this->m_pGeneralInstructions->SetVisible(this: this->m_pGeneralInstructions, a2: v16);
  if ( v14 )
  {
    if ( isGunGameProgressive )
    {
      generalInstructions = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "SFUI_Rules_GunGame_Progressive");
    }
    else if ( isGunGameSelect )
    {
      generalInstructions = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "SFUI_Rules_GunGame_Select");
    }
    goto LABEL_51;
  }
  if ( isGunGameTRBomb )
  {
    v17 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int))g_pVGuiLocalize->Find)(
                             a1: g_pVGuiLocalize,
                             a2: "SFUI_Rules_TRBomb_Header",
                             a3: v25);
    v18 = g_pVGuiLocalize->__vftable;
    scenarioName = v17;
    v19 = (int)v18->Find(this: g_pVGuiLocalize, a2: "SFUI_Rules_TRBomb_CT");
LABEL_50:
    ctInstructions = (const wchar_t *)v19;
    tInstructions = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *))g_pVGuiLocalize->Find)(a1: g_pVGuiLocalize);
    goto LABEL_51;
  }
  if ( V_strnicmp(s1: mapName, s2: "cs_", n: 3) == 0 )
  {
    v20 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int))g_pVGuiLocalize->Find)(
                             a1: g_pVGuiLocalize,
                             a2: "SFUI_Rules_Hostage_Header",
                             a3: v25);
    v21 = g_pVGuiLocalize->__vftable;
    scenarioName = v20;
    v19 = (int)v21->Find(this: g_pVGuiLocalize, a2: "SFUI_Rules_Hostage_CT");
    goto LABEL_50;
  }
  if ( V_strnicmp(s1: mapName, s2: "de_", n: 3) == 0 )
  {
    v22 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int))g_pVGuiLocalize->Find)(
                             a1: g_pVGuiLocalize,
                             a2: "SFUI_Rules_Bomb_Header",
                             a3: v25);
    v23 = g_pVGuiLocalize->__vftable;
    scenarioName = v22;
    v19 = (int)v23->Find(this: g_pVGuiLocalize, a2: "SFUI_Rules_Bomb_CT");
    goto LABEL_50;
  }
LABEL_51:
  if ( this->m_pScenario != nullptr
    && this->m_pTInstructions != nullptr
    && this->m_pCTInstructions != nullptr
    && this->m_pGeneralInstructions != nullptr )
  {
    this->m_pCTInstructions->SetText(this: this->m_pCTInstructions, a2: ctInstructions);
    this->m_pTInstructions->SetText(this: this->m_pTInstructions, a2: tInstructions);
    this->m_pScenario->SetText(this: this->m_pScenario, a2: scenarioName);
    this->m_pGeneralInstructions->SetText(this: this->m_pGeneralInstructions, a2: generalInstructions);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BAC0
// Name: public: virtual void CLoadingScreenScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLoadingScreenScaleform::FlashReady(CLoadingScreenScaleform *this@<ecx>, int a2@<ebx>)
{
  void *v3; // edi
  int v4; // eax
  IScaleformUI_vtbl *v5; // edx
  void *v6; // ebx
  void *v7; // eax
  void *v8; // edi
  ISFTextObject *m_pTitleText; // eax
  ISFTextObject *m_pPlayerCount; // eax
  ISFTextObject *m_pType; // eax
  ISFTextObject *m_pMode; // eax
  ISFTextObject *m_pScenario; // eax
  ISFTextObject *m_pCTInstructions; // eax
  ISFTextObject *m_pTInstructions; // eax
  ISFTextObject *m_pGeneralInstructions; // eax
  ISFTextObject *m_pTLabel; // ecx
  ISFTextObject *m_pCTLabel; // ecx
  ISFTextObject *m_pRulesLabel; // ecx
  void *middleLevel; // [esp+8h] [ebp-8h]
  void *topLevel; // [esp+Ch] [ebp-4h]

  v3 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: this->m_FlashAPI, a3: "Panel");
  topLevel = v3;
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IScaleformUI *, void *, const char *, int))g_pScaleformUI->Value_GetMember)(
           a1: g_pScaleformUI,
           a2: v3,
           a3: "Panel",
           a4: a2);
    v5 = g_pScaleformUI->__vftable;
    v6 = (void *)v4;
    middleLevel = (void *)v4;
    if ( v4 != 0 )
    {
      v7 = (void *)((int (__stdcall *)(int, const char *))v5->Value_GetMember)(a1: v4, a2: "Text");
      v8 = v7;
      if ( v7 != nullptr )
      {
        this->m_pPlayerCount = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                 this: g_pScaleformUI,
                                 a2: v7,
                                 a3: "NumPlayers");
        this->m_pType = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: v8, a3: "Type");
        this->m_pMode = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: v8, a3: "Mode");
        this->m_pScenario = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                              this: g_pScaleformUI,
                              a2: v8,
                              a3: "Scenario");
        this->m_pCTInstructions = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                    this: g_pScaleformUI,
                                    a2: v8,
                                    a3: "CTInstructions");
        this->m_pTInstructions = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                   this: g_pScaleformUI,
                                   a2: v8,
                                   a3: "TInstructions");
        this->m_pTLabel = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                            this: g_pScaleformUI,
                            a2: v8,
                            a3: "THeader");
        this->m_pCTLabel = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                             this: g_pScaleformUI,
                             a2: v8,
                             a3: "CTHeader");
        this->m_pRulesLabel = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                this: g_pScaleformUI,
                                a2: v8,
                                a3: "GeneralRulesHeader");
        this->m_pGeneralInstructions = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                         this: g_pScaleformUI,
                                         a2: v8,
                                         a3: "GeneralRules");
        this->m_pRetrievingDataNotification = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                                this: g_pScaleformUI,
                                                a2: v8,
                                                a3: "RetrievingDataNotification");
        g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: v8);
        if ( g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: v6, a3: "TitleText") != nullptr )
          this->m_pTitleText = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                 this: g_pScaleformUI,
                                 a2: v8,
                                 a3: "Title");
        ((void (__thiscall *)(IScaleformUI *))g_pScaleformUI->ReleaseValue)(a1: g_pScaleformUI);
        g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: middleLevel);
        g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: topLevel);
        m_pTitleText = this->m_pTitleText;
        if ( m_pTitleText != nullptr )
          m_pTitleText->SetText_2(this: m_pTitleText, a2: prType);
        m_pPlayerCount = this->m_pPlayerCount;
        if ( m_pPlayerCount != nullptr )
          m_pPlayerCount->SetText_2(this: m_pPlayerCount, a2: prType);
        m_pType = this->m_pType;
        if ( m_pType != nullptr )
          m_pType->SetText_2(this: m_pType, a2: prType);
        m_pMode = this->m_pMode;
        if ( m_pMode != nullptr )
          m_pMode->SetText_2(this: m_pMode, a2: prType);
        m_pScenario = this->m_pScenario;
        if ( m_pScenario != nullptr )
          m_pScenario->SetText_2(this: m_pScenario, a2: prType);
        m_pCTInstructions = this->m_pCTInstructions;
        if ( m_pCTInstructions != nullptr )
          m_pCTInstructions->SetText_2(this: m_pCTInstructions, a2: prType);
        m_pTInstructions = this->m_pTInstructions;
        if ( m_pTInstructions != nullptr )
          m_pTInstructions->SetText_2(this: m_pTInstructions, a2: prType);
        m_pGeneralInstructions = this->m_pGeneralInstructions;
        if ( m_pGeneralInstructions != nullptr )
          m_pGeneralInstructions->SetText_2(this: m_pGeneralInstructions, a2: prType);
        m_pTLabel = this->m_pTLabel;
        if ( m_pTLabel != nullptr )
          m_pTLabel->SetVisible(this: m_pTLabel, a2: false);
        m_pCTLabel = this->m_pCTLabel;
        if ( m_pCTLabel != nullptr )
          m_pCTLabel->SetVisible(this: m_pCTLabel, a2: false);
        m_pRulesLabel = this->m_pRulesLabel;
        if ( m_pRulesLabel != nullptr )
          m_pRulesLabel->SetVisible(this: m_pRulesLabel, a2: false);
        CLoadingScreenScaleform::Show(this);
      }
      else
      {
        ((void (__thiscall *)(IScaleformUI *))g_pScaleformUI->ReleaseValue)(a1: g_pScaleformUI);
        g_pScaleformUI->ReleaseValue(this: g_pScaleformUI, a2: topLevel);
      }
    }
    else
    {
      ((void (__cdecl *)(void *))v5->ReleaseValue)(a1: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BDF0
// Name: public: void CLoadingScreenScaleform::SetProgressInternal(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingScreenScaleform::SetProgressInternal(CLoadingScreenScaleform *this, float fraction)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *v5; // edi
  const char *v6; // eax
  C_CSGameRules *v7; // edi
  C_CSGameRules *v8; // ebx
  const char *v9; // eax
  const char *v10; // [esp-8h] [ebp-1Ch]
  bool IsPlayingGunGameProgressive; // [esp-4h] [ebp-18h]
  char IsPlayingGunGameSelect; // [esp+0h] [ebp-14h]
  bool IsPlayingGunGameTRBomb; // [esp+4h] [ebp-10h]
  const char *mapName; // [esp+1Ch] [ebp+8h]

  if ( this->m_FlashAPI != nullptr )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v5 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, _DWORD))this->m_pScaleformUI->ValueArray_SetElement_4)(
        a1: this->m_pScaleformUI,
        a2: v5,
        a3: 0,
        a4: LODWORD(fraction));
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setProgressFraction",
        a4: v5,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v5, a3: 1u);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    v6 = engine->GetLevelNameShort(this: engine);
    mapName = v6;
    if ( !this->m_serverInfoReady && v6 != nullptr && *v6 != 0 )
    {
      v7 = (C_CSGameRules *)g_pGameRules;
      v8 = (C_CSGameRules *)g_pGameRules;
      IsPlayingGunGameTRBomb = C_CSGameRules::IsPlayingGunGameTRBomb(this: (C_CSGameRules *)g_pGameRules);
      IsPlayingGunGameSelect = C_CSGameRules::IsPlayingGunGameSelect(this: v7);
      IsPlayingGunGameProgressive = C_CSGameRules::IsPlayingGunGameProgressive(this: v8);
      v10 = g_pGameTypes->GetCurrentGameModeNameID(this: g_pGameTypes);
      v9 = g_pGameTypes->GetCurrentGameTypeNameID(this: g_pGameTypes);
      CLoadingScreenScaleform::PopulateLevelInfo(
        this,
        a2: (int)v7,
        mapName,
        gameTypeNameID: v9,
        gameModeNameID: v10,
        isGunGameProgressive: IsPlayingGunGameProgressive,
        isGunGameSelect: IsPlayingGunGameSelect,
        isGunGameTRBomb: IsPlayingGunGameTRBomb);
      this->m_serverInfoReady = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BF00
// Name: protected: void CLoadingScreenScaleform::PopulateLevelInfoFromLocalHost(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingScreenScaleform::PopulateLevelInfoFromLocalHost(
        CLoadingScreenScaleform *this,
        const char *mapName,
        const char *szGameType,
        const char *szGameMode)
{
  const char *gameTypeNameID; // [esp+Ch] [ebp-14h] BYREF
  const char *gameModeNameID; // [esp+10h] [ebp-10h] BYREF
  BOOL isGunGameProgressive; // [esp+14h] [ebp-Ch]
  int iGameMode; // [esp+18h] [ebp-8h] BYREF
  int iGameType; // [esp+1Ch] [ebp-4h] BYREF
  char isGunGameSelect; // [esp+2Ch] [ebp+Ch]
  bool isGunGameTRBomb; // [esp+30h] [ebp+10h]

  iGameType = -1;
  iGameMode = -1;
  if ( g_pGameTypes->GetGameModeAndTypeIntsFromStrings(
         this: g_pGameTypes,
         a2: szGameType,
         a3: szGameMode,
         a4: &iGameType,
         a5: &iGameMode) )
  {
    if ( iGameType != 1 || iGameMode != 0 )
    {
      LOBYTE(isGunGameProgressive) = 0;
      if ( iGameType == 1 && iGameMode == 1 )
      {
        isGunGameSelect = iGameType;
LABEL_7:
        isGunGameTRBomb = false;
LABEL_8:
        gameTypeNameID = nullptr;
        gameModeNameID = nullptr;
        if ( g_pGameTypes->GetGameModeAndTypeNameIdsFromStrings(
               this: g_pGameTypes,
               a2: szGameType,
               a3: szGameMode,
               a4: &gameTypeNameID,
               a5: &gameModeNameID) )
        {
          CLoadingScreenScaleform::PopulateLevelInfo(
            this,
            a2: (int)szGameType,
            mapName,
            gameTypeNameID,
            gameModeNameID,
            isGunGameProgressive,
            isGunGameSelect,
            isGunGameTRBomb);
        }
        return;
      }
    }
    else
    {
      LOBYTE(isGunGameProgressive) = 1;
    }
    isGunGameSelect = 0;
    if ( iGameType == 1 )
    {
      isGunGameTRBomb = true;
      if ( iGameMode == 2 )
        goto LABEL_8;
    }
    goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BFC0
// Name: public: static void CLoadingScreenScaleform::Close(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLoadingScreenScaleform::Close()
{
  if ( CLoadingScreenScaleform::m_pInstance != nullptr && CLoadingScreenScaleform::m_pInstance->m_bFlashAPIIsValid )
    CLoadingScreenScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CLoadingScreenScaleform::m_pInstance->m_pScaleformUI,
      a2: CLoadingScreenScaleform::m_pInstance->m_iFlashSlot,
      a3: CLoadingScreenScaleform::m_pInstance->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x1020BFF0
// Name: public: CLoadingScreenScaleform::CLoadingScreenScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CLoadingScreenScaleform *__thiscall CLoadingScreenScaleform::CLoadingScreenScaleform(CLoadingScreenScaleform *this)
{
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (CLoadingScreenScaleform_vtbl *)&CLoadingScreenScaleform::`vftable';
  this->m_pPlayerCount = nullptr;
  this->m_pType = nullptr;
  this->m_pMode = nullptr;
  this->m_pScenario = nullptr;
  this->m_pCTInstructions = nullptr;
  this->m_pTInstructions = nullptr;
  this->m_pTitleText = nullptr;
  this->m_pTLabel = nullptr;
  this->m_pCTLabel = nullptr;
  this->m_pRulesLabel = nullptr;
  this->m_pGeneralInstructions = nullptr;
  this->m_pRetrievingDataNotification = nullptr;
  this->m_pPendingKeyValues = nullptr;
  *(_WORD *)&this->m_serverInfoReady = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020C040
// Name: public: static void CLoadingScreenScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CLoadingScreenScaleform::LoadDialog()
{
  CLoadingScreenScaleform *v0; // eax
  CLoadingScreenScaleform *v1; // eax

  if ( CLoadingScreenScaleform::m_pInstance == nullptr )
  {
    v0 = (CLoadingScreenScaleform *)MemAlloc_Alloc(nSize: 0x44Cu);
    if ( v0 != nullptr )
      v1 = CLoadingScreenScaleform::CLoadingScreenScaleform(this: v0);
    else
      v1 = nullptr;
    CLoadingScreenScaleform::m_pInstance = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "LoadingScreen",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CLoadingScreenScaleform_LoadingScreen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C090
// Name: public: void CLoadingScreenScaleform::ReadyForLoading(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadingScreenScaleform::ReadyForLoading(
        CLoadingScreenScaleform *this,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  char *m_pendingCommand; // edi
  KeyValues *m_pPendingKeyValues; // ecx
  char *String; // edi
  char *v7; // ebx
  char *v8; // eax

  m_pendingCommand = this->m_pendingCommand;
  if ( this->m_pendingCommand[0] != 0 )
  {
    engine->ClientCmd_Unrestricted(this: engine, a2: m_pendingCommand);
    *m_pendingCommand = 0;
  }
  else
  {
    m_pPendingKeyValues = this->m_pPendingKeyValues;
    if ( m_pPendingKeyValues != nullptr )
    {
      String = KeyValues::GetString(this: m_pPendingKeyValues, keyName: "game/bspname", defaultValue: prType);
      v7 = KeyValues::GetString(this: this->m_pPendingKeyValues, keyName: "game/type", defaultValue: prType);
      v8 = KeyValues::GetString(this: this->m_pPendingKeyValues, keyName: "game/mode", defaultValue: prType);
      this->m_serverInfoReady = true;
      CLoadingScreenScaleform::PopulateLevelInfoFromLocalHost(this, mapName: String, szGameType: v7, szGameMode: v8);
      g_pMatchFramework->ApplySettings(this: g_pMatchFramework, a2: this->m_pPendingKeyValues);
      KeyValues::deleteThis(this: this->m_pPendingKeyValues);
      this->m_pPendingKeyValues = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C140
// Name: public: static void CLoadingScreenScaleform::LoadDialogForCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CLoadingScreenScaleform::LoadDialogForCommand(char *command)
{
  CLoadingScreenScaleform *v1; // eax
  CLoadingScreenScaleform *v2; // eax
  CLoadingScreenScaleform *v3; // eax

  v1 = CLoadingScreenScaleform::m_pInstance;
  if ( CLoadingScreenScaleform::m_pInstance != nullptr
    || ((v2 = (CLoadingScreenScaleform *)MemAlloc_Alloc(nSize: 0x44Cu)) == nullptr
      ? (v3 = nullptr)
      : (v3 = CLoadingScreenScaleform::CLoadingScreenScaleform(this: v2)),
        CLoadingScreenScaleform::m_pInstance = v3,
        g_pScaleformUI->RequestElement(
          this: g_pScaleformUI,
          a2: 1,
          a3: "LoadingScreen",
          a4: (ScaleformUIFunctionHandlerObject *)v3,
          a5: pScaleformFunctionHandler_CLoadingScreenScaleform_LoadingScreen),
        v1 = CLoadingScreenScaleform::m_pInstance,
        CLoadingScreenScaleform::m_pInstance != nullptr) )
  {
    V_strncpy(pDest: v1->m_pendingCommand, pSrc: command, maxLen: 1024);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C1B0
// Name: public: static void CLoadingScreenScaleform::LoadDialogForKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CLoadingScreenScaleform::LoadDialogForKeyValues(KeyValues *keyValues)
{
  CLoadingScreenScaleform *v1; // eax
  CLoadingScreenScaleform *v2; // eax
  CLoadingScreenScaleform *v3; // eax
  KeyValues *m_pPendingKeyValues; // ecx
  KeyValues **p_m_pPendingKeyValues; // esi

  v1 = CLoadingScreenScaleform::m_pInstance;
  if ( CLoadingScreenScaleform::m_pInstance != nullptr
    || ((v2 = (CLoadingScreenScaleform *)MemAlloc_Alloc(nSize: 0x44Cu)) == nullptr
      ? (v3 = nullptr)
      : (v3 = CLoadingScreenScaleform::CLoadingScreenScaleform(this: v2)),
        CLoadingScreenScaleform::m_pInstance = v3,
        g_pScaleformUI->RequestElement(
          this: g_pScaleformUI,
          a2: 1,
          a3: "LoadingScreen",
          a4: (ScaleformUIFunctionHandlerObject *)v3,
          a5: pScaleformFunctionHandler_CLoadingScreenScaleform_LoadingScreen),
        v1 = CLoadingScreenScaleform::m_pInstance,
        CLoadingScreenScaleform::m_pInstance != nullptr) )
  {
    m_pPendingKeyValues = v1->m_pPendingKeyValues;
    p_m_pPendingKeyValues = &v1->m_pPendingKeyValues;
    if ( m_pPendingKeyValues != nullptr )
      KeyValues::deleteThis(this: m_pPendingKeyValues);
    *p_m_pPendingKeyValues = KeyValues::MakeCopy(this: keyValues);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C230
// Name: public: static bool CLoadingScreenScaleform::SetProgressPoint(float,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CLoadingScreenScaleform::SetProgressPoint(float fraction, bool showDialog)
{
  if ( CLoadingScreenScaleform::m_pInstance != nullptr )
  {
    CLoadingScreenScaleform::SetProgressInternal(this: CLoadingScreenScaleform::m_pInstance, fraction);
    return 1;
  }
  else
  {
    if ( showDialog )
      CLoadingScreenScaleform::LoadDialog();
    return 1;
  }
}
