// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/teammenu_scaleform.cpp
// Functions: 24
// ============================================================

#include "game\client\cstrike15\scaleform\teammenu_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x10214520
// Name: public: virtual void CCSTeamMenuScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::PostUnloadFlash(CCSTeamMenuScaleform *this)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v3; // esi
  IViewPort *ViewPortInterface; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->m_bLoading = false;
  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetObserverMode(this: LocalPlayer) != 3
    && v3->GetObserverMode(this: v3) != 6
    && v3->GetObserverMode(this: v3) != 0 )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "specgui", a3: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102145C0
// Name: public: void CCSTeamMenuScaleform::OnAutoSelect(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CCSTeamMenuScaleform::OnAutoSelect(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+0h] [ebp-4h] BYREF

  g_UISSGuard.m_nSaveSlot = (int)this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  ((void (__thiscall *)(IVEngineClient *, const char *, int))engine->ClientCmd)(
    a1: engine,
    a2: "jointeam 0",
    a3: g_UISSGuard.m_nSaveSlot);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102145F0
// Name: public: void CCSTeamMenuScaleform::OnShowScoreboard(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::OnShowScoreboard(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  IViewPort *ViewPortInterface; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+0h] [ebp-4h] BYREF

  g_UISSGuard.m_nSaveSlot = (int)this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( GetViewPortInterface() != nullptr )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "scores", a3: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214640
// Name: public: void CCSTeamMenuScaleform::Hide(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::Hide(CCSTeamMenuScaleform *this, bool bRemove)
{
  CMessageBoxScaleform *m_pConfirmDialog; // ecx
  char v4; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_bLoading || !this->m_bFlashAPIIsValid || !this->m_bVisible )
    goto LABEL_21;
  m_pConfirmDialog = this->m_pConfirmDialog;
  if ( m_pConfirmDialog == nullptr )
  {
    v4 = 1;
    if ( bRemove )
    {
      while ( 1 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( v4 == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hidePanelAndRemove",
          a4: nullptr,
          a5: 0);
        v4 = 0;
      }
      if ( m_pScaleformUI == nullptr )
        goto LABEL_20;
    }
    else
    {
      while ( 1 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( v4 == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hidePanel",
          a4: nullptr,
          a5: 0);
        v4 = 0;
      }
      if ( m_pScaleformUI == nullptr )
        goto LABEL_20;
    }
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
LABEL_20:
    this->m_pViewPort->ShowBackGround(this: &this->m_pViewPort->IViewPort, a2: false);
    goto LABEL_21;
  }
  if ( this->m_OnClosedAction == NOTHING )
  {
    this->m_OnClosedAction = HIDEPANEL;
    CMessageBoxScaleform::Hide(this: m_pConfirmDialog);
    this->m_bVisible = false;
    return;
  }
LABEL_21:
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x10214740
// Name: public: virtual bool CCSTeamMenuScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSTeamMenuScaleform::PreUnloadFlash(CCSTeamMenuScaleform *this)
{
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pCTCountHuman);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTCountHuman);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pCTCountBot);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTCountBot);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pNavText);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTimerTextGreen);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTimerTextRed);
  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTimerTextLabel);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102147A0
// Name: public: void CCSTeamMenuScaleform::RefreshCounts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::RefreshCounts(CCSTeamMenuScaleform *this)
{
  int i; // edi
  int v3; // eax
  ISFTextObject *m_pCTCountHuman; // ecx
  ISFTextObject *m_pCTCountBot; // ecx
  ISFTextObject *m_pTCountHuman; // ecx
  ISFTextObject *m_pTCountBot; // ecx
  void *v8; // edi
  char j; // al
  IScaleformUI *m_pScaleformUI; // ecx
  int nTBotCount; // [esp+Ch] [ebp-8h]
  int nCTBotCount; // [esp+10h] [ebp-4h]

  this->m_nCTHumanCount = 0;
  this->m_nTHumanCount = 0;
  nCTBotCount = 0;
  nTBotCount = 0;
  for ( i = 1; i <= 64; ++i )
  {
    if ( g_PR != nullptr && g_PR->IsConnected(this: &g_PR->IGameResources, a2: i) )
    {
      v3 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: i);
      if ( v3 == 3 )
      {
        if ( g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: i) )
          ++nCTBotCount;
        else
          ++this->m_nCTHumanCount;
      }
      else if ( v3 == 2 )
      {
        if ( g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: i) )
          ++nTBotCount;
        else
          ++this->m_nTHumanCount;
      }
    }
  }
  m_pCTCountHuman = this->m_pCTCountHuman;
  if ( m_pCTCountHuman != nullptr )
    m_pCTCountHuman->SetText_4(this: m_pCTCountHuman, a2: this->m_nCTHumanCount);
  m_pCTCountBot = this->m_pCTCountBot;
  if ( m_pCTCountBot != nullptr )
    m_pCTCountBot->SetText_4(this: m_pCTCountBot, a2: nCTBotCount);
  m_pTCountHuman = this->m_pTCountHuman;
  if ( m_pTCountHuman != nullptr )
    m_pTCountHuman->SetText_4(this: m_pTCountHuman, a2: this->m_nTHumanCount);
  m_pTCountBot = this->m_pTCountBot;
  if ( m_pTCountBot != nullptr )
    m_pTCountBot->SetText_4(this: m_pTCountBot, a2: nTBotCount);
  v8 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
  if ( v8 != nullptr )
  {
    this->m_pScaleformUI->ValueArray_SetElement_3(
      this: this->m_pScaleformUI,
      a2: v8,
      a3: 0,
      a4: this->m_nCTHumanCount >= 5);
    this->m_pScaleformUI->ValueArray_SetElement_3(
      this: this->m_pScaleformUI,
      a2: v8,
      a3: 1,
      a4: this->m_nTHumanCount >= 5);
    for ( j = 1; ; j = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( j == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setTeamsFull",
        a4: v8,
        a5: 2u);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v8, a3: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214960
// Name: public: void CCSTeamMenuScaleform::OnOk(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::OnOk(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  int v4; // esi
  C_CSPlayer *LocalPlayer; // eax
  int v6; // eax
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v8; // esi
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v4 = (int)g_pScaleformUI->Params_GetArgAsNumber(this: g_pScaleformUI, a2: obj, a3: 0);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v6 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
    if ( v4 != 3 )
    {
      if ( v4 != 2 || v6 != 2 )
        goto LABEL_4;
LABEL_13:
      CCSTeamMenuScaleform::Hide(this, bRemove: true);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
    if ( v6 == 3 )
      goto LABEL_13;
  }
LABEL_4:
  if ( (_S5_143 & 1) == 0 )
  {
    _S5_143 |= 1u;
    CGameUIConVarRef::CGameUIConVarRef(this: &s_player_teamplayedlast, pName: "player_teamplayedlast");
  }
  GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
  s_player_teamplayedlast.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_2(
    this: s_player_teamplayedlast.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar,
    a2: v4);
  v8 = v4 - 2;
  if ( v8 != 0 )
  {
    if ( v8 == 1 )
    {
      if ( this->m_nCTHumanCount >= 5 )
        g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "buttons/weapon_cant_buy.wav");
      engine->ClientCmd(this: engine, a2: "jointeam 3");
    }
  }
  else
  {
    if ( this->m_nTHumanCount >= 5 )
      g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "buttons/weapon_cant_buy.wav");
    engine->ClientCmd(this: engine, a2: "jointeam 2");
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214A70
// Name: public: void CCSTeamMenuScaleform::OnCancel(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::OnCancel(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  CounterStrikeViewport *m_pViewPort; // eax
  CCStrike15BasePanel *v5; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( this->m_pConfirmDialog == nullptr )
  {
    m_pViewPort = this->m_pViewPort;
    if ( m_pViewPort == nullptr || !m_pViewPort->m_bChoseTeamAndClass )
    {
      v5 = BasePanel();
      v5->OnOpenMessageBoxInSlot(
        this: v5,
        a2: this->m_iFlashSlot,
        a3: "#SFUI_TeamConfirmTitle",
        a4: "#SFUI_TeamConfirmMsg",
        a5: "#SFUI_TeamConfirmNav",
        a6: 7u,
        a7: &this->IMessageBoxEventCallback,
        a8: &this->m_pConfirmDialog);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
    CCSTeamMenuScaleform::Hide(this, bRemove: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214B00
// Name: public: virtual bool CCSTeamMenuScaleform::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSTeamMenuScaleform::OnMessageBoxEvent(CCSTeamMenuScaleform *this, MessageBoxFlags_t buttonPressed)
{
  char *v3; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: (int)this->m_pTCountBot);
  if ( (buttonPressed & 4) != 0 )
  {
    v3 = (char *)&this->m_pTCountHuman[-1].__vftable + 3;
    this->IViewPortPanel::__vftable = nullptr;
    if ( v3 != nullptr )
    {
      if ( v3 != (char *)1 )
      {
LABEL_7:
        this->m_pTCountHuman = nullptr;
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
        return 1;
      }
    }
    else
    {
      engine->ClientCmd_Unrestricted(this: engine, a2: "disconnect");
    }
    CCSTeamMenuScaleform::Hide(this: (CCSTeamMenuScaleform *)((char *)this - 24), bRemove: true);
    goto LABEL_7;
  }
  this->m_pTCountHuman = (ISFTextObject *)(buttonPressed & 1);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10214B80
// Name: public: void CCSTeamMenuScaleform::OnSpectate(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::OnSpectate(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( this->m_bAllowSpectate )
  {
    engine->ClientCmd(this: engine, a2: "jointeam 1");
    CCSTeamMenuScaleform::Hide(this, bRemove: true);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214BD0
// Name: protected: void CCSTeamMenuScaleform::HandlePostTeamSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::HandlePostTeamSelect(CCSTeamMenuScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_bFlashAPIIsValid )
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
        a3: "showPreMatchOverlay",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bPostSelectOverlay = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214C30
// Name: public: void CCSTeamMenuScaleform::HandleForceSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::HandleForceSelect(CCSTeamMenuScaleform *this)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v3; // edi
  float m_fForceTeam; // xmm0_4
  int v5; // edi
  bool v6; // zf
  ISFTextObject *m_pTimerTextLabel; // ecx
  char i; // al
  wchar_t szTime[32]; // [esp+10h] [ebp-44h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+50h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr && LocalPlayer->GetTeamNumber(this: LocalPlayer) == 0 )
  {
    m_fForceTeam = v3->m_fForceTeam;
    if ( m_fForceTeam != -1.0 )
    {
      v5 = (int)ceil(X: (float)(m_fForceTeam - *(float *)(gpGlobals.m_Index + 12)));
      if ( (float)this->m_nForceSelectTimeLast == -1.0 )
        this->m_nForceSelectTimeLast = v5 + 1;
      if ( v5 < this->m_nForceSelectTimeLast )
      {
        szTime[0] = 0;
        V_snwprintf(pDest: szTime, maxLen: 32, pFormat: L"%d:%.2d", v5 / 60, v5 % 60);
        v6 = !this->m_bFlashAPIIsValid;
        this->m_nForceSelectTimeLast = v5;
        if ( !v6 && this->m_pTimerTextGreen != nullptr && this->m_pTimerTextRed != nullptr )
        {
          m_pTimerTextLabel = this->m_pTimerTextLabel;
          if ( m_pTimerTextLabel != nullptr )
          {
            if ( v5 > 3 )
            {
              if ( !this->m_bGreenTimerVisible )
              {
                m_pTimerTextLabel->SetVisible(this: m_pTimerTextLabel, a2: true);
                this->m_pTimerTextGreen->SetVisible(this: this->m_pTimerTextGreen, a2: true);
                this->m_pTimerTextRed->SetVisible(this: this->m_pTimerTextRed, a2: false);
                this->m_bGreenTimerVisible = true;
LABEL_18:
                for ( i = 1; i != 0; i = 0 )
                {
                  ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::LockScaleformSlot(this);
                  if ( this->m_bGreenTimerVisible )
                    this->m_pTimerTextGreen->SetText(this: this->m_pTimerTextGreen, a2: szTime);
                  else
                    this->m_pTimerTextRed->SetText(this: this->m_pTimerTextRed, a2: szTime);
                }
                ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::UnlockScaleformSlot(this);
                goto LABEL_25;
              }
            }
            else if ( !this->m_bRedTimerVisible )
            {
              m_pTimerTextLabel->SetVisible(this: m_pTimerTextLabel, a2: true);
              this->m_pTimerTextGreen->SetVisible(this: this->m_pTimerTextGreen, a2: false);
              this->m_pTimerTextRed->SetVisible(this: this->m_pTimerTextRed, a2: true);
              *(_WORD *)&this->m_bGreenTimerVisible = 256;
              goto LABEL_18;
            }
            if ( v5 < 0 )
            {
              m_pTimerTextLabel->SetVisible(this: m_pTimerTextLabel, a2: false);
              this->m_pTimerTextGreen->SetVisible(this: this->m_pTimerTextGreen, a2: false);
              this->m_pTimerTextRed->SetVisible(this: this->m_pTimerTextRed, a2: false);
            }
            goto LABEL_18;
          }
        }
      }
    }
  }
LABEL_25:
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214E10
// Name: public: virtual void CCSTeamMenuScaleform::ViewportThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::ViewportThink(CCSTeamMenuScaleform *this)
{
  CCSTeamMenuScaleform::HandleForceSelect(this: (CCSTeamMenuScaleform *)((char *)this - 20));
}

//------------------------------------------------------------------------------
// Address: 0x10214E20
// Name: public: void CCSTeamMenuScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSTeamMenuScaleform::Show(CCSTeamMenuScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  C_CSPlayer *LocalPlayer; // ebx
  int v5; // eax
  void *v6; // edi
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( this->m_bLoading )
    goto LABEL_18;
  if ( !this->m_bFlashAPIIsValid )
  {
    this->m_bLoading = true;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: this->m_iSplitScreenSlot + 2,
      a3: "TeamMenu",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_CCSTeamMenuScaleform_TeamMenu);
LABEL_18:
    this->m_bVisible = true;
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
  LocalPlayer = CClientTools::GetLocalPlayer();
  v5 = ((int (__thiscall *)(IScaleformUI *, int, int))this->m_pScaleformUI->CreateValueArray)(
         a1: this->m_pScaleformUI,
         a2: 1,
         a3);
  v6 = (void *)v5;
  if ( v5 != 0 )
  {
    if ( LocalPlayer == nullptr || (v5 = LocalPlayer->GetTeamNumber(this: LocalPlayer)) != 0 )
      LOBYTE(v5) = 0;
    else
      v5 = 1;
    ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, int, int))this->m_pScaleformUI->ValueArray_SetElement_3)(
      a1: this->m_pScaleformUI,
      a2: v6,
      a3: 0,
      a4: v5,
      a5: a2);
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
        a3: "showPanel",
        a4: v6,
        a5: 1u);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
      a1: this->m_pScaleformUI,
      a2: v6);
  }
  this->m_pViewPort->ShowBackGround(this: &this->m_pViewPort->IViewPort, a2: true);
  CCSTeamMenuScaleform::HandleForceSelect(this);
  this->m_bVisible = true;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10214F60
// Name: public: virtual void CCSTeamMenuScaleform::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSTeamMenuScaleform::ShowPanel(
        CCSTeamMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        bool bShow)
{
  CCSTeamMenuScaleform *v5; // ecx

  if ( IsValidSplitScreenSlot(i: (int)this->m_pNavText) && bShow != LOBYTE(this->m_pTimerTextRed) )
  {
    v5 = (CCSTeamMenuScaleform *)((char *)this - 20);
    if ( bShow )
      CCSTeamMenuScaleform::Show(this: v5, a2, a3);
    else
      CCSTeamMenuScaleform::Hide(this: v5, bRemove: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214FA0
// Name: public: void CCSTeamMenuScaleform::UpdateSpectatorOption(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::UpdateSpectatorOption(CCSTeamMenuScaleform *this)
{
  ConVar *v2; // ebx
  int v3; // esi
  char v4; // cl
  ConVar *m_pParent; // eax
  C_Team *GlobalTeam; // eax
  C_CSGameRules *v7; // esi
  int v8; // ebx
  const char *v9; // eax
  const wchar_t *v10; // eax

  if ( this->m_pNavText != nullptr )
  {
    v2 = cvar->FindVar_2(this: cvar, a2: "mp_allowspectators");
    if ( CClientTools::GetLocalPlayer() != nullptr && g_pGameRules != nullptr )
    {
      v3 = 1;
      while ( !g_PR->IsAlive(this: &g_PR->IGameResources, a2: v3)
           || !g_PR->IsConnected(this: &g_PR->IGameResources, a2: v3)
           || g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: v3) )
      {
        if ( ++v3 > 64 )
        {
          v4 = 0;
          goto LABEL_11;
        }
      }
      v4 = 1;
LABEL_11:
      this->m_bAllowSpectate = false;
      if ( v2 != nullptr )
      {
        m_pParent = v2->m_pParent;
        if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 && v4 != 0 )
        {
          GlobalTeam = GetGlobalTeam(iTeamNumber: 1);
          v7 = (C_CSGameRules *)g_pGameRules;
          v8 = GlobalTeam->GetNumPlayers(this: GlobalTeam);
          if ( v8 < C_CSGameRules::GetMaxSpectatorSlots(this: v7) )
            this->m_bAllowSpectate = true;
        }
      }
      v9 = "#SFUI_TeamNavWithSpectate@15";
      if ( !this->m_bAllowSpectate )
        v9 = "#SFUI_TeamNavNoSpectate@15";
      v10 = g_pScaleformUI->Translate(this: g_pScaleformUI, a2: v9, a3: 0);
      this->m_pNavText->SetTextHTML(this: this->m_pNavText, a2: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102150D0
// Name: public: void CCSTeamMenuScaleform::OnTimer(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::OnTimer(CCSTeamMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bFlashAPIIsValid )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iSplitScreenSlot);
    CCSTeamMenuScaleform::RefreshCounts(this);
    CCSTeamMenuScaleform::UpdateSpectatorOption(this);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215110
// Name: public: virtual void CCSTeamMenuScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::FireGameEvent(CCSTeamMenuScaleform *this, IGameEvent *event)
{
  const char *v4; // ebx
  IViewPort *ViewPortInterface; // eax
  C_CSPlayer *LocalPlayer; // ebx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-4h] BYREF
  IGameEvent *eventa; // [esp+18h] [ebp+8h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: (int)this->m_pTCountHuman);
  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: v4, s2: "cs_match_end_restart") == 0 )
  {
    ViewPortInterface = GetViewPortInterface();
    ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "team", a3: true);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
  if ( _V_strcmp(s1: v4, s2: "player_spawned") != 0 )
  {
    if ( _V_strcmp(s1: v4, s2: "round_start") != 0 )
    {
      if ( _V_strcmp(s1: v4, s2: "cs_game_disconnected") != 0 )
        goto LABEL_16;
    }
    else
    {
      if ( HIBYTE(this->m_pTimerTextLabel) == 0 )
        goto LABEL_16;
      HIBYTE(this->m_pTimerTextLabel) = 0;
    }
  }
  else
  {
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer == nullptr )
      goto LABEL_16;
    eventa = (IGameEvent *)event->GetInt(this: event, a2: "userid", a3: 0);
    if ( (IGameEvent *)C_BasePlayer::GetUserID(this: LocalPlayer) != eventa )
      goto LABEL_16;
    this->m_pTimerTextRed = (ISFTextObject *)-1;
    LOWORD(this->m_pTimerTextGreen) = 0;
    if ( event->GetBool(this: event, a2: "inrestart", a3: false) )
    {
      CCSTeamMenuScaleform::HandlePostTeamSelect(this: (CCSTeamMenuScaleform *)((char *)this - 28));
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
  }
  if ( LOBYTE(this->m_pTimerTextLabel) != 0 )
  {
    CCSTeamMenuScaleform::Hide(this: (CCSTeamMenuScaleform *)((char *)this - 28), bRemove: true);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
  if ( *((_BYTE *)this - 12) != 0 )
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this - 6) + 76))(
      a1: *((_DWORD *)this - 6),
      a2: *((_DWORD *)this - 4),
      a3: *((_DWORD *)this - 5));
LABEL_16:
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10215270
// Name: public: CCSTeamMenuScaleform::CCSTeamMenuScaleform(class CounterStrikeViewport __near *)
// Source: json
//------------------------------------------------------------------------------
CCSTeamMenuScaleform *__thiscall CCSTeamMenuScaleform::CCSTeamMenuScaleform(
        CCSTeamMenuScaleform *this,
        CounterStrikeViewport *pViewPort)
{
  this->m_bFlashAPIIsValid = false;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->m_iFlashSlot = -1;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&IMessageBoxEventCallback::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_pViewPort = pViewPort;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSTeamMenuScaleform_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `IViewPortPanel'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `IMessageBoxEventCallback'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `CGameEventListener'};
  this->m_pConfirmDialog = nullptr;
  this->m_pCTCountHuman = nullptr;
  this->m_pCTCountBot = nullptr;
  this->m_pTCountHuman = nullptr;
  this->m_pTCountBot = nullptr;
  this->m_pNavText = nullptr;
  this->m_pTimerTextLabel = nullptr;
  this->m_pTimerTextGreen = nullptr;
  this->m_pTimerTextRed = nullptr;
  this->m_OnClosedAction = NOTHING;
  this->m_nCTHumanCount = 0;
  this->m_nTHumanCount = 0;
  *(_DWORD *)&this->m_bVisible = 0;
  *(_WORD *)&this->m_bGreenTimerVisible = 0;
  this->m_nForceSelectTimeLast = -1;
  this->m_iSplitScreenSlot = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10215300
// Name: public: virtual char const __near * CCSTeamMenuScaleform::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSTeamMenuScaleform::GetName(CCSTeamMenuScaleform *this)
{
  return "team";
}

//------------------------------------------------------------------------------
// Address: 0x10215310
// Name: public: virtual bool CCSTeamMenuScaleform::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSTeamMenuScaleform::IsVisible(CCSTeamMenuScaleform *this)
{
  return (bool)this->m_pTimerTextRed;
}

//------------------------------------------------------------------------------
// Address: 0x10215340
// Name: public: virtual CCSTeamMenuScaleform::~CCSTeamMenuScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSTeamMenuScaleform::~CCSTeamMenuScaleform(CCSTeamMenuScaleform *this)
{
  CGameEventListener *v2; // edi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSTeamMenuScaleform_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `IViewPortPanel'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `IMessageBoxEventCallback'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSTeamMenuScaleform::`vftable'{for `CGameEventListener'};
  v3 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  v3 = !this->m_bFlashAPIIsValid;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSTeamMenuScaleform_vtbl *)&ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::`vftable';
  if ( !v3 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x102153C0
// Name: public: virtual void CCSTeamMenuScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSTeamMenuScaleform::FlashLoaded(CCSTeamMenuScaleform *this@<ecx>, int a2@<edi>)
{
  void *v3; // ebx
  void *v4; // edi
  ISFTextObject *v5; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  ISFTextObject *v7; // eax
  IScaleformUI *v8; // ecx
  ISFTextObject *v9; // eax
  IScaleformUI *v10; // ecx
  ISFTextObject *v11; // eax
  IScaleformUI *v12; // ecx
  ISFTextObject *v13; // eax
  IScaleformUI *v14; // ecx
  void *v15; // ebx
  ISFTextObject *v16; // eax
  IScaleformUI *v17; // ecx
  ISFTextObject *v18; // eax
  IScaleformUI *v19; // ecx
  ISFTextObject *v20; // eax
  bool v21; // zf
  CGameEventListener *v22; // esi
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-Ch] BYREF
  void *panelValue; // [esp+Ch] [ebp-8h]
  CGameUiSetActiveSplitScreenPlayerGuard v25; // [esp+10h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "Panel");
  panelValue = v3;
  if ( v3 != nullptr )
  {
    v4 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                   a1: this->m_pScaleformUI,
                   a2: v3,
                   a3: "NavPanel",
                   a4: a2);
    if ( v4 != nullptr )
    {
      v5 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
             this: this->m_pScaleformUI,
             a2: v4,
             a3: "CT_CountHuman");
      m_pScaleformUI = this->m_pScaleformUI;
      this->m_pCTCountHuman = v5;
      v7 = m_pScaleformUI->TextObject_MakeTextObjectFromMember(this: m_pScaleformUI, a2: v4, a3: "T_CountHuman");
      v8 = this->m_pScaleformUI;
      this->m_pTCountHuman = v7;
      v9 = v8->TextObject_MakeTextObjectFromMember(this: v8, a2: v4, a3: "CT_CountBot");
      v10 = this->m_pScaleformUI;
      this->m_pCTCountBot = v9;
      v11 = v10->TextObject_MakeTextObjectFromMember(this: v10, a2: v4, a3: "T_CountBot");
      v12 = this->m_pScaleformUI;
      this->m_pTCountBot = v11;
      v13 = v12->TextObject_MakeTextObjectFromMember(this: v12, a2: v4, a3: "Nav_Text");
      v14 = this->m_pScaleformUI;
      this->m_pNavText = v13;
      v15 = v14->Value_GetMember(this: v14, a2: v4, a3: "Timer");
      if ( v15 != nullptr )
      {
        v16 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                this: this->m_pScaleformUI,
                a2: v15,
                a3: "TimerTextGreen");
        v17 = this->m_pScaleformUI;
        this->m_pTimerTextGreen = v16;
        v18 = v17->TextObject_MakeTextObjectFromMember(this: v17, a2: v15, a3: "TimerTextRed");
        v19 = this->m_pScaleformUI;
        this->m_pTimerTextRed = v18;
        v20 = v19->TextObject_MakeTextObjectFromMember(this: v19, a2: v15, a3: "TimerTextLabel");
        v21 = this->m_pTimerTextGreen == nullptr;
        this->m_pTimerTextLabel = v20;
        if ( !v21 && this->m_pTimerTextRed != nullptr && v20 != nullptr )
        {
          v20->SetVisible(this: v20, a2: false);
          this->m_pTimerTextGreen->SetVisible(this: this->m_pTimerTextGreen, a2: false);
          this->m_pTimerTextRed->SetVisible(this: this->m_pTimerTextRed, a2: false);
          *(_WORD *)&this->m_bGreenTimerVisible = 0;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v15);
      }
      if ( this->m_bFlashAPIIsValid )
      {
        CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
          this: &v25,
          slot: this->m_iSplitScreenSlot);
        CCSTeamMenuScaleform::RefreshCounts(this);
        CCSTeamMenuScaleform::UpdateSpectatorOption(this);
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v25);
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v4);
      v3 = panelValue;
    }
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v3);
  }
  v22 = &this->CGameEventListener;
  v22->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v22, a3: "cs_match_end_restart", a4: false);
  v22->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v22, a3: "cs_game_disconnected", a4: false);
  v22->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v22, a3: "player_spawned", a4: false);
  v22->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v22, a3: "round_start", a4: false);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102155F0
// Name: public: virtual void CCSTeamMenuScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSTeamMenuScaleform::FlashReady(CCSTeamMenuScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v3; // zf

  v3 = !this->m_bVisible;
  this->m_bLoading = false;
  if ( v3 )
    CCSTeamMenuScaleform::Hide(this, bRemove: false);
  else
    CCSTeamMenuScaleform::Show(this, a2, a3);
}
