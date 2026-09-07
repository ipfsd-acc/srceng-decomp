// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudinfopanel.cpp
// Functions: 20
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudinfopanel.h"

//------------------------------------------------------------------------------
// Address: 0x1021AC40
// Name: GetTextBoxForElement
// Source: json
//------------------------------------------------------------------------------
void __usercall GetTextBoxForElement(
        IScaleformUI *pScaleformUI@<esi>,
        void *root@<edx>,
        const char *elementName@<ecx>,
        const char *textElementName,
        void **sfv)
{
  void *v5; // edi

  v5 = pScaleformUI->Value_GetMember(this: pScaleformUI, a2: root, a3: elementName);
  if ( v5 != nullptr )
  {
    *sfv = pScaleformUI->Value_GetMember(this: pScaleformUI, a2: v5, a3: textElementName);
    pScaleformUI->ReleaseValue(this: pScaleformUI, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021AC90
// Name: protected: void SFHudInfoPanel::HideAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::HideAll(SFHudInfoPanel *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_FlashAPI != nullptr )
  {
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
        a3: "hideAll",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_PreviousDefusePercent = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021AD00
// Name: public: virtual void SFHudInfoPanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::FlashReady(SFHudInfoPanel *this)
{
  void *v2; // eax
  void *v3; // ebx
  IScaleformUI *m_pScaleformUI; // esi
  int v5; // eax
  IScaleformUI *v6; // esi
  int v7; // eax
  void *v8; // eax
  void *v9; // ebx
  IScaleformUI *v10; // esi
  int v11; // eax
  IScaleformUI *v12; // esi
  int v13; // eax
  void *v14; // eax
  void *v15; // ebx
  IScaleformUI *v16; // esi
  int v17; // eax
  IScaleformUI *v18; // esi
  int v19; // eax
  void *v20; // eax
  void *v21; // ebx
  IScaleformUI *v22; // esi
  int v23; // eax
  void *v24; // esi
  void *v25; // ebx
  void *AnimatedPanelHandle; // [esp+Ch] [ebp-8h]
  void *TitleBarHandle; // [esp+10h] [ebp-4h]
  void *TitleBarHandlea; // [esp+10h] [ebp-4h]
  void *TitleBarHandleb; // [esp+10h] [ebp-4h]
  void *TitleBarHandlec; // [esp+10h] [ebp-4h]
  void *TitleBarHandled; // [esp+10h] [ebp-4h]
  void *TitleBarHandlee; // [esp+10h] [ebp-4h]
  void *TitleBarHandlef; // [esp+10h] [ebp-4h]

  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "achievement_earned_local", a4: false);
  v2 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanelHelp");
  this->m_HelpPanelHandle = v2;
  if ( v2 != nullptr )
  {
    v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v2, a3: "Panel");
    if ( v3 != nullptr )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      v5 = (int)m_pScaleformUI->Value_GetMember(this: m_pScaleformUI, a2: v3, a3: "HelpTextTitle");
      TitleBarHandle = (void *)v5;
      if ( v5 != 0 )
      {
        this->m_HelpTitleTextHandle = m_pScaleformUI->Value_GetMember(
                                        this: m_pScaleformUI,
                                        a2: (void *)v5,
                                        a3: "TextBox");
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: TitleBarHandle);
      }
      v6 = this->m_pScaleformUI;
      v7 = (int)v6->Value_GetMember(this: v6, a2: v3, a3: "HelpText");
      TitleBarHandlea = (void *)v7;
      if ( v7 != 0 )
      {
        this->m_HelpBodyTextHandle = v6->Value_GetMember(this: v6, a2: (void *)v7, a3: "TextBox");
        v6->ReleaseValue(this: v6, a2: TitleBarHandlea);
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v3);
    }
  }
  v8 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanelCenter");
  this->m_PriorityMessagePanelHandle = v8;
  if ( v8 != nullptr )
  {
    v9 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "Panel");
    if ( v9 != nullptr )
    {
      v10 = this->m_pScaleformUI;
      v11 = (int)v10->Value_GetMember(this: v10, a2: v9, a3: "CenterTextTitle");
      TitleBarHandleb = (void *)v11;
      if ( v11 != 0 )
      {
        this->m_PriorityMessageTitleTextHandle = v10->Value_GetMember(this: v10, a2: (void *)v11, a3: "TextBox");
        v10->ReleaseValue(this: v10, a2: TitleBarHandleb);
      }
      v12 = this->m_pScaleformUI;
      v13 = (int)v12->Value_GetMember(this: v12, a2: v9, a3: "CenterText");
      TitleBarHandlec = (void *)v13;
      if ( v13 != 0 )
      {
        this->m_PriorityMessageBodyTextHandle = v12->Value_GetMember(this: v12, a2: (void *)v13, a3: "TextBox");
        v12->ReleaseValue(this: v12, a2: TitleBarHandlec);
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v9);
    }
  }
  v14 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanelMedal");
  this->m_MedalPanelHandle = v14;
  if ( v14 != nullptr )
  {
    v15 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v14, a3: "Panel");
    if ( v15 != nullptr )
    {
      v16 = this->m_pScaleformUI;
      v17 = (int)v16->Value_GetMember(this: v16, a2: v15, a3: "MedalTitleText");
      TitleBarHandled = (void *)v17;
      if ( v17 != 0 )
      {
        this->m_MedalTitleTextHandle = v16->Value_GetMember(this: v16, a2: (void *)v17, a3: "TextBox");
        v16->ReleaseValue(this: v16, a2: TitleBarHandled);
      }
      v18 = this->m_pScaleformUI;
      v19 = (int)v18->Value_GetMember(this: v18, a2: v15, a3: "MedalText");
      TitleBarHandlee = (void *)v19;
      if ( v19 != 0 )
      {
        this->m_MedalBodyTextHandle = v18->Value_GetMember(this: v18, a2: (void *)v19, a3: "TextBox");
        v18->ReleaseValue(this: v18, a2: TitleBarHandlee);
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v15);
    }
  }
  v20 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "HudPanelDefuse");
  this->m_DefusePanelHandle = v20;
  if ( v20 != nullptr )
  {
    v21 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v20, a3: "Panel");
    AnimatedPanelHandle = v21;
    if ( v21 != nullptr )
    {
      v22 = this->m_pScaleformUI;
      v23 = (int)v22->Value_GetMember(this: v22, a2: v21, a3: "DefuseText");
      TitleBarHandlef = (void *)v23;
      if ( v23 != 0 )
      {
        this->m_DefuseBodyTextHandle = v22->Value_GetMember(this: v22, a2: (void *)v23, a3: "TextBox");
        v22->ReleaseValue(this: v22, a2: TitleBarHandlef);
      }
      v24 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v21, a3: "DefuseTextTitle");
      if ( v24 != nullptr )
      {
        v25 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v24, a3: "DefuseTitle");
        if ( v25 != nullptr )
        {
          GetTextBoxForElement(
            pScaleformUI: this->m_pScaleformUI,
            root: v25,
            elementName: "DefuseTitle",
            textElementName: "TextBox1",
            sfv: &this->m_DefuseTitleTextHandle);
          GetTextBoxForElement(
            pScaleformUI: this->m_pScaleformUI,
            root: v25,
            elementName: "DefuseTitle",
            textElementName: "TextBox2",
            sfv: &this->m_DefuseTimerTextHandle);
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v25);
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v24);
        v21 = AnimatedPanelHandle;
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v21);
    }
  }
  SFHudInfoPanel::HideAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1021B0C0
// Name: public: virtual bool SFHudInfoPanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudInfoPanel::PreUnloadFlash(SFHudInfoPanel *this)
{
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v3; // ecx
  IScaleformUI *v4; // ecx
  IScaleformUI *v5; // ecx
  IScaleformUI *v6; // ecx
  IScaleformUI *v7; // ecx
  IScaleformUI *v8; // ecx
  IScaleformUI *v9; // ecx
  IScaleformUI *v10; // ecx
  IScaleformUI *v11; // ecx
  IScaleformUI *v12; // ecx
  IScaleformUI *v13; // ecx
  IScaleformUI *v14; // ecx

  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  m_pScaleformUI = this->m_pScaleformUI;
  if ( m_pScaleformUI != nullptr && this->m_HelpPanelHandle != nullptr )
  {
    m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: this->m_HelpPanelHandle);
    this->m_HelpPanelHandle = nullptr;
  }
  v3 = this->m_pScaleformUI;
  if ( v3 != nullptr && this->m_HelpTitleTextHandle != nullptr )
  {
    v3->ReleaseValue(this: v3, a2: this->m_HelpTitleTextHandle);
    this->m_HelpTitleTextHandle = nullptr;
  }
  v4 = this->m_pScaleformUI;
  if ( v4 != nullptr && this->m_HelpBodyTextHandle != nullptr )
  {
    v4->ReleaseValue(this: v4, a2: this->m_HelpBodyTextHandle);
    this->m_HelpBodyTextHandle = nullptr;
  }
  v5 = this->m_pScaleformUI;
  if ( v5 != nullptr && this->m_MedalPanelHandle != nullptr )
  {
    v5->ReleaseValue(this: v5, a2: this->m_MedalPanelHandle);
    this->m_MedalPanelHandle = nullptr;
  }
  v6 = this->m_pScaleformUI;
  if ( v6 != nullptr && this->m_MedalTitleTextHandle != nullptr )
  {
    v6->ReleaseValue(this: v6, a2: this->m_MedalTitleTextHandle);
    this->m_MedalTitleTextHandle = nullptr;
  }
  v7 = this->m_pScaleformUI;
  if ( v7 != nullptr && this->m_MedalBodyTextHandle != nullptr )
  {
    v7->ReleaseValue(this: v7, a2: this->m_MedalBodyTextHandle);
    this->m_MedalBodyTextHandle = nullptr;
  }
  v8 = this->m_pScaleformUI;
  if ( v8 != nullptr && this->m_DefusePanelHandle != nullptr )
  {
    v8->ReleaseValue(this: v8, a2: this->m_DefusePanelHandle);
    this->m_DefusePanelHandle = nullptr;
  }
  v9 = this->m_pScaleformUI;
  if ( v9 != nullptr && this->m_DefuseTitleTextHandle != nullptr )
  {
    v9->ReleaseValue(this: v9, a2: this->m_DefuseTitleTextHandle);
    this->m_DefuseTitleTextHandle = nullptr;
  }
  v10 = this->m_pScaleformUI;
  if ( v10 != nullptr && this->m_DefuseTimerTextHandle != nullptr )
  {
    v10->ReleaseValue(this: v10, a2: this->m_DefuseTimerTextHandle);
    this->m_DefuseTimerTextHandle = nullptr;
  }
  v11 = this->m_pScaleformUI;
  if ( v11 != nullptr && this->m_DefuseBodyTextHandle != nullptr )
  {
    v11->ReleaseValue(this: v11, a2: this->m_DefuseBodyTextHandle);
    this->m_DefuseBodyTextHandle = nullptr;
  }
  v12 = this->m_pScaleformUI;
  if ( v12 != nullptr && this->m_PriorityMessagePanelHandle != nullptr )
  {
    v12->ReleaseValue(this: v12, a2: this->m_PriorityMessagePanelHandle);
    this->m_PriorityMessagePanelHandle = nullptr;
  }
  v13 = this->m_pScaleformUI;
  if ( v13 != nullptr && this->m_PriorityMessageTitleTextHandle != nullptr )
  {
    v13->ReleaseValue(this: v13, a2: this->m_PriorityMessageTitleTextHandle);
    this->m_PriorityMessageTitleTextHandle = nullptr;
  }
  v14 = this->m_pScaleformUI;
  if ( v14 != nullptr && this->m_PriorityMessageBodyTextHandle != nullptr )
  {
    v14->ReleaseValue(this: v14, a2: this->m_PriorityMessageBodyTextHandle);
    this->m_PriorityMessageBodyTextHandle = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1021B270
// Name: public: virtual void SFHudInfoPanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::LevelInit(SFHudInfoPanel *this)
{
  if ( this->m_bFlashAPIIsValid )
    SFHudInfoPanel::HideAll(this);
  else
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "HelpAchievementModule",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudInfoPanel_HelpAchievementModule);
}

//------------------------------------------------------------------------------
// Address: 0x1021B2A0
// Name: public: virtual void SFHudInfoPanel::Reset(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall SFHudInfoPanel::Reset(SFHudInfoPanel *this)
{
  SFHudInfoPanel::HideAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1021B2B0
// Name: public: virtual void SFHudInfoPanel::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::SetActive(SFHudInfoPanel *this, bool bActive)
{
  if ( this->m_bActive && !bActive )
    SFHudInfoPanel::HideAll(this);
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1021B2E0
// Name: public: void SFHudInfoPanel::ApplyYOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::ApplyYOffset(SFHudInfoPanel *this, int nOffset)
{
  char i; // al
  void *v4; // edi

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v4, a3: 0, a4: nOffset);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setYOffset",
        a4: v4,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v4, a3: 1u);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B380
// Name: protected: bool SFHudInfoPanel::SetHintText(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFHudInfoPanel::SetHintText(SFHudInfoPanel *this, wchar_t *text)
{
  bool result; // al
  IScaleformUI *m_pScaleformUI; // ecx
  double v5; // st7
  void *m_HelpTitleTextHandle; // eax
  IScaleformUI *v7; // ecx
  IScaleformUI_vtbl *v8; // edi
  int v9; // eax
  void *v10; // edi
  void *v11; // edi
  float v12; // [esp+4h] [ebp-8h]
  float v13; // [esp+8h] [ebp-4h]

  result = true;
  if ( this->m_bFlashAPIIsValid )
  {
    while ( 1 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( !result )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      if ( text != nullptr )
      {
        v13 = g_HintDisplayTime;
        v5 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_HintDisplayTimer) + v13;
        if ( this->m_HintDisplayTimer.m_timestamp.m_Value != v5 )
        {
          this->m_HintDisplayTimer.NetworkStateChanged(
            this: &this->m_HintDisplayTimer,
            a2: &this->m_HintDisplayTimer.m_timestamp);
          v12 = v5;
          this->m_HintDisplayTimer.m_timestamp.m_Value = v12;
        }
        if ( this->m_HintDisplayTimer.m_duration.m_Value != v13 )
        {
          this->m_HintDisplayTimer.NetworkStateChanged(
            this: &this->m_HintDisplayTimer,
            a2: &this->m_HintDisplayTimer.m_duration);
          this->m_HintDisplayTimer.m_duration.m_Value = v13;
        }
        m_HelpTitleTextHandle = this->m_HelpTitleTextHandle;
        if ( m_HelpTitleTextHandle != nullptr )
          this->m_pScaleformUI->Value_SetText_2(
            this: this->m_pScaleformUI,
            a2: m_HelpTitleTextHandle,
            a3: "#SFUIHUD_InfoPanel_HelpTitle");
        if ( this->m_HelpBodyTextHandle != nullptr )
        {
          v7 = this->m_pScaleformUI;
          v8 = v7->__vftable;
          v9 = (int)v7->ReplaceGlyphKeywordsWithHTML_2(this: v7, a2: text, a3: 0);
          v8->Value_SetTextHTML(this: this->m_pScaleformUI, a2: this->m_HelpBodyTextHandle, a3: (const wchar_t *)v9);
        }
        if ( this->m_bActive && this->m_FlashAPI != nullptr )
        {
          v10 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
          this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v10, a3: 0, a4: 1);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "showPanel",
            a4: v10,
            a5: 1u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v10, a3: 1u);
          result = false;
        }
        else
        {
          this->m_bDeferRaiseHelpPanel = true;
          result = false;
        }
      }
      else
      {
        if ( this->m_HintDisplayTimer.m_timestamp.m_Value != -1.0 )
        {
          this->m_HintDisplayTimer.NetworkStateChanged(
            this: &this->m_HintDisplayTimer,
            a2: &this->m_HintDisplayTimer.m_timestamp);
          this->m_HintDisplayTimer.m_timestamp.m_Value = -1.0;
        }
        if ( this->m_bActive && this->m_FlashAPI != nullptr )
        {
          v11 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
          this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v11, a3: 0, a4: 1);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "hidePanel",
            a4: v11,
            a5: 1u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v11, a3: 1u);
        }
        result = false;
      }
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1021B580
// Name: protected: void SFHudInfoPanel::ModifyPriorityTextWindow(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::ModifyPriorityTextWindow(SFHudInfoPanel *this, bool bMsgSet)
{
  double v3; // st7
  void *m_PriorityMessageTitleTextHandle; // eax
  void *v5; // edi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  void *v7; // edi
  float v8; // [esp+8h] [ebp-8h]
  float m_fValue; // [esp+Ch] [ebp-4h]
  bool bAlreadyActive; // [esp+1Bh] [ebp+Bh]

  if ( bMsgSet )
  {
    if ( this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value <= 0.0
      || (bAlreadyActive = true,
          CountdownTimer::Now(this: (CEffectsClient *)&this->m_PriorityMsgDisplayTimer) > this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value) )
    {
      bAlreadyActive = false;
    }
    if ( (_S5_144 & 1) == 0 )
    {
      _S5_144 |= 1u;
      ConVarRef::ConVarRef(this: &scr_centertime_0, pName: "scr_centertime");
    }
    m_fValue = scr_centertime_0.m_pConVarState->m_Value.m_fValue;
    v3 = CountdownTimer::Now(this: (CEffectsClient *)&this->m_PriorityMsgDisplayTimer) + m_fValue;
    if ( this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value != v3 )
    {
      this->m_PriorityMsgDisplayTimer.NetworkStateChanged(
        this: &this->m_PriorityMsgDisplayTimer,
        a2: &this->m_PriorityMsgDisplayTimer.m_timestamp);
      v8 = v3;
      this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value = v8;
    }
    if ( this->m_PriorityMsgDisplayTimer.m_duration.m_Value != m_fValue )
    {
      this->m_PriorityMsgDisplayTimer.NetworkStateChanged(
        this: &this->m_PriorityMsgDisplayTimer,
        a2: &this->m_PriorityMsgDisplayTimer.m_duration);
      this->m_PriorityMsgDisplayTimer.m_duration.m_Value = m_fValue;
    }
    m_PriorityMessageTitleTextHandle = this->m_PriorityMessageTitleTextHandle;
    if ( m_PriorityMessageTitleTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: m_PriorityMessageTitleTextHandle,
        a3: "#SFUIHUD_InfoPanel_PriorityMsgTitle");
    if ( bAlreadyActive )
    {
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "flashCenterText",
        a4: nullptr,
        a5: 0);
    }
    else if ( this->m_bActive && this->m_FlashAPI != nullptr )
    {
      v5 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v5, a3: 0, a4: 4);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showPanel",
        a4: v5,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v5, a3: 1u);
    }
    else
    {
      this->m_bDeferRaisePriorityMessagePanel = true;
    }
  }
  else
  {
    p_m_timestamp = &this->m_PriorityMsgDisplayTimer.m_timestamp;
    if ( this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value != -1.0 )
    {
      this->m_PriorityMsgDisplayTimer.NetworkStateChanged(
        this: &this->m_PriorityMsgDisplayTimer,
        a2: &this->m_PriorityMsgDisplayTimer.m_timestamp);
      p_m_timestamp->m_Value = -1.0;
    }
    if ( this->m_bActive && this->m_FlashAPI != nullptr )
    {
      v7 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v7, a3: 0, a4: 4);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hidePanel",
        a4: v7,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v7, a3: 1u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B7A0
// Name: public: void SFHudInfoPanel::SetPriorityText(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::SetPriorityText(SFHudInfoPanel *this, char *pMsg)
{
  char i; // al
  void *m_PriorityMessageBodyTextHandle; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      SFHudInfoPanel::ModifyPriorityTextWindow(this, bMsgSet: pMsg != nullptr);
      if ( pMsg != nullptr )
      {
        m_PriorityMessageBodyTextHandle = this->m_PriorityMessageBodyTextHandle;
        if ( m_PriorityMessageBodyTextHandle != nullptr )
          this->m_pScaleformUI->Value_SetText_2(
            this: this->m_pScaleformUI,
            a2: m_PriorityMessageBodyTextHandle,
            a3: pMsg);
      }
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B820
// Name: public: void SFHudInfoPanel::SetPriorityText(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::SetPriorityText(SFHudInfoPanel *this, wchar_t *pMsg)
{
  char i; // al
  void *m_PriorityMessageBodyTextHandle; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      SFHudInfoPanel::ModifyPriorityTextWindow(this, bMsgSet: pMsg != nullptr);
      if ( pMsg != nullptr )
      {
        m_PriorityMessageBodyTextHandle = this->m_PriorityMessageBodyTextHandle;
        if ( m_PriorityMessageBodyTextHandle != nullptr )
          this->m_pScaleformUI->Value_SetText(this: this->m_pScaleformUI, a2: m_PriorityMessageBodyTextHandle, a3: pMsg);
      }
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021B8A0
// Name: public: virtual void SFHudInfoPanel::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::ProcessInput(SFHudInfoPanel *this)
{
  int v2; // ebx
  C_CSPlayer *LocalPlayer; // edi
  C_BaseEntity *v4; // edi
  int m_Value; // eax
  float v6; // xmm2_4
  int v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  IScaleformUI *v10; // ecx
  IScaleformUI *m_pScaleformUI; // ecx
  bool v12; // zf
  void *v13; // edi
  IScaleformUI *v14; // ecx
  char i; // al
  IScaleformUI *v16; // ecx
  IScaleformUI *v17; // ecx
  void *v18; // edi
  IScaleformUI *v19; // ecx
  void *v20; // edi
  IScaleformUI *v21; // ecx
  void *m_DefuseTitleTextHandle; // eax
  void *m_DefuseBodyTextHandle; // eax
  void *v24; // edi
  IScaleformUI *v25; // ecx
  void *v26; // edi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  IScaleformUI *v28; // ecx
  void *v29; // edi
  IScaleformUI *v30; // ecx
  IScaleformUI *v31; // ecx
  void *m_MedalPanelHandle; // eax
  SFHudInfoPanel::AchivementQueueInfo *m_pMemory; // ecx
  int v34; // eax
  float v35; // xmm0_4
  eCSAchievementType type; // edi
  int playerSlot; // ebx
  IAchievementMgr *v38; // eax
  int v39; // eax
  int v40; // edi
  IScaleformUI *v41; // ecx
  const char *v42; // eax
  CFmtStrN<256> *v43; // eax
  IScaleformUI_vtbl *v44; // ebx
  wchar_t *v45; // eax
  const char *v46; // eax
  CFmtStrN<256> *v47; // eax
  IScaleformUI_vtbl *v48; // ebx
  wchar_t *v49; // eax
  void *v50; // eax
  int v51; // edx
  void *v52; // ebx
  int v53; // eax
  void *v54; // edi
  IScaleformUI *v55; // ecx
  CFmtStrN<256> v56; // [esp+B4h] [ebp-1CCh] BYREF
  char cTimerStr[128]; // [esp+1C0h] [ebp-C0h] BYREF
  ScaleformDisplayInfo dinfo; // [esp+240h] [ebp-40h] BYREF
  float DefusePercent; // [esp+278h] [ebp-8h]
  bool bDefuseCanceled; // [esp+27Eh] [ebp-2h]
  bool bSlotIsLocked; // [esp+27Fh] [ebp-1h]

  DefusePercent = -1.0;
  v2 = -1;
  bDefuseCanceled = false;
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && (LocalPlayer->GetObserverMode(this: LocalPlayer) != 4
     || (v4 = LocalPlayer->GetObserverTarget(this: LocalPlayer)) != nullptr
     && v4->IsPlayer(this: v4)
     && (LocalPlayer = ToBasePlayer(pEntity: v4)) != nullptr
     && LocalPlayer->IsAlive(this: LocalPlayer)) )
  {
    m_Value = LocalPlayer->m_iProgressBarDuration.m_Value;
    bDefuseCanceled = m_Value == 0;
    if ( m_Value > 0 )
    {
      v6 = LocalPlayer->m_flSimulationTime - LocalPlayer->m_flProgressBarStartTime.m_Value;
      *(float *)&v7 = 0.0;
      v8 = v6 / (float)m_Value;
      if ( v8 < 0.0 || (*(float *)&v7 = 1.0, v8 > 1.0) )
        v8 = *(float *)&v7;
      DefusePercent = v8;
      v2 = (int)ceil(X: (float)((float)m_Value - v6));
    }
  }
  else if ( this->m_PreviousDefusePercent >= 0.0 )
  {
    bDefuseCanceled = true;
  }
  v9 = this->m_HintDisplayTimer.m_timestamp.m_Value;
  bSlotIsLocked = false;
  if ( v9 > 0.0 )
  {
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_HintDisplayTimer) <= this->m_HintDisplayTimer.m_timestamp.m_Value )
    {
      if ( this->m_bActive && this->m_bDeferRaiseHelpPanel )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        v12 = !this->m_bActive;
        bSlotIsLocked = true;
        if ( v12 || this->m_FlashAPI == nullptr )
        {
          this->m_bDeferRaiseHelpPanel = true;
        }
        else
        {
          v13 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
          this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v13, a3: 0, a4: 1);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "showPanel",
            a4: v13,
            a5: 1u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v13, a3: 1u);
        }
      }
    }
    else
    {
      v10 = this->m_pScaleformUI;
      if ( v10 != nullptr )
        v10->LockSlot(this: v10, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
      SFHudInfoPanel::SetHintText(this, text: nullptr);
    }
  }
  if ( this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value > 0.0 )
  {
    if ( CountdownTimer::Now(this: (CEffectsClient *)&this->m_PriorityMsgDisplayTimer) <= this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value )
    {
      if ( this->m_bActive && this->m_bDeferRaisePriorityMessagePanel )
      {
        if ( !bSlotIsLocked )
        {
          v17 = this->m_pScaleformUI;
          if ( v17 != nullptr )
            v17->LockSlot(this: v17, a2: this->m_iFlashSlot);
          bSlotIsLocked = true;
        }
        if ( this->m_bActive && this->m_FlashAPI != nullptr )
        {
          v18 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
          this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v18, a3: 0, a4: 4);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "showPanel",
            a4: v18,
            a5: 1u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v18, a3: 1u);
        }
        else
        {
          this->m_bDeferRaisePriorityMessagePanel = true;
        }
      }
    }
    else
    {
      if ( !bSlotIsLocked )
      {
        v14 = this->m_pScaleformUI;
        if ( v14 != nullptr )
          v14->LockSlot(this: v14, a2: this->m_iFlashSlot);
        bSlotIsLocked = true;
      }
      if ( this->m_bFlashAPIIsValid )
      {
        for ( i = 1; ; i = 0 )
        {
          v16 = this->m_pScaleformUI;
          if ( i == 0 )
            break;
          if ( v16 != nullptr )
            v16->LockSlot(this: v16, a2: this->m_iFlashSlot);
          SFHudInfoPanel::ModifyPriorityTextWindow(this, bMsgSet: false);
        }
        if ( v16 != nullptr )
          v16->UnlockSlot(this: v16, a2: this->m_iFlashSlot);
      }
    }
  }
  if ( DefusePercent >= 0.0 )
  {
    if ( !bSlotIsLocked )
    {
      v19 = this->m_pScaleformUI;
      if ( v19 != nullptr )
        v19->LockSlot(this: v19, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    if ( v2 >= 0 && this->m_DefuseTimerTextHandle != nullptr )
    {
      V_snprintf(
        pDest: cTimerStr,
        maxLen: 0x80u,
        pFormat: "%02d:%02d",
        (v2 <= 0 ? 0 : v2) / 60,
        (v2 <= 0 ? 0 : v2) % 60);
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: this->m_DefuseTimerTextHandle,
        a3: cTimerStr);
    }
    v20 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
    ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, _DWORD))this->m_pScaleformUI->ValueArray_SetElement_4)(
      a1: this->m_pScaleformUI,
      a2: v20,
      a3: 0,
      a4: LODWORD(DefusePercent));
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "setDefuseProgress",
      a4: v20,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v20, a3: 1u);
  }
  if ( this->m_PreviousDefusePercent < 0.0 && DefusePercent >= 0.0 )
  {
    if ( !bSlotIsLocked )
    {
      v21 = this->m_pScaleformUI;
      if ( v21 != nullptr )
        v21->LockSlot(this: v21, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    m_DefuseTitleTextHandle = this->m_DefuseTitleTextHandle;
    if ( m_DefuseTitleTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: m_DefuseTitleTextHandle,
        a3: "#SFUIHUD_InfoPanel_DefuseTitle");
    m_DefuseBodyTextHandle = this->m_DefuseBodyTextHandle;
    if ( m_DefuseBodyTextHandle != nullptr )
      this->m_pScaleformUI->Value_SetText_2(
        this: this->m_pScaleformUI,
        a2: m_DefuseBodyTextHandle,
        a3: "#SFUIHUD_InfoPanel_DefuseText");
    if ( this->m_bActive && this->m_FlashAPI != nullptr )
    {
      v24 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v24, a3: 0, a4: 2);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "showPanel",
        a4: v24,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v24, a3: 1u);
    }
  }
  if ( this->m_PreviousDefusePercent >= 0.0 && bDefuseCanceled )
  {
    if ( !bSlotIsLocked )
    {
      v25 = this->m_pScaleformUI;
      if ( v25 != nullptr )
        v25->LockSlot(this: v25, a2: this->m_iFlashSlot);
      bSlotIsLocked = true;
    }
    if ( this->m_bActive && this->m_FlashAPI != nullptr )
    {
      v26 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v26, a3: 0, a4: 2);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hidePanel",
        a4: v26,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v26, a3: 1u);
    }
  }
  v12 = this->m_activeAchievement == CSInvalidAchievement;
  this->m_PreviousDefusePercent = DefusePercent;
  if ( !v12 )
  {
    p_m_timestamp = &this->m_AchievementDisplayTimer.m_timestamp;
    if ( this->m_AchievementDisplayTimer.m_timestamp.m_Value <= 0.0
      || CountdownTimer::Now(this: (CEffectsClient *)&this->m_AchievementDisplayTimer) <= this->m_AchievementDisplayTimer.m_timestamp.m_Value )
    {
      if ( this->m_MedalPanelHandle != nullptr )
      {
        if ( !bSlotIsLocked )
        {
          v30 = this->m_pScaleformUI;
          if ( v30 != nullptr )
            v30->LockSlot(this: v30, a2: this->m_iFlashSlot);
          bSlotIsLocked = true;
        }
        v31 = this->m_pScaleformUI;
        m_MedalPanelHandle = this->m_MedalPanelHandle;
        dinfo.m_iSetFlags = 0;
        v31->Value_GetDisplayInfo(this: v31, a2: m_MedalPanelHandle, a3: &dinfo);
        if ( !dinfo.m_bVisibility )
          this->m_activeAchievement = CSInvalidAchievement;
      }
    }
    else
    {
      if ( !bSlotIsLocked )
      {
        v28 = this->m_pScaleformUI;
        if ( v28 != nullptr )
          v28->LockSlot(this: v28, a2: this->m_iFlashSlot);
        bSlotIsLocked = true;
      }
      if ( p_m_timestamp->m_Value != -1.0 )
      {
        this->m_AchievementDisplayTimer.NetworkStateChanged(
          this: &this->m_AchievementDisplayTimer,
          a2: &this->m_AchievementDisplayTimer.m_timestamp);
        p_m_timestamp->m_Value = -1.0;
      }
      if ( this->m_bActive && this->m_FlashAPI != nullptr )
      {
        v29 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
        this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v29, a3: 0, a4: 3);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hidePanel",
          a4: v29,
          a5: 1u);
        this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v29, a3: 1u);
      }
    }
    goto LABEL_118;
  }
  if ( this->m_achievementQueue.m_heap.m_Size <= 0 )
  {
LABEL_118:
    if ( bSlotIsLocked )
    {
      v55 = this->m_pScaleformUI;
      if ( v55 != nullptr )
        v55->UnlockSlot(this: v55, a2: this->m_iFlashSlot);
    }
    if ( this->m_bActive )
      *(_WORD *)&this->m_bDeferRaiseHelpPanel = 0;
    return;
  }
  m_pMemory = this->m_achievementQueue.m_heap.m_Memory.m_pMemory;
  this->m_achievementQueue.m_current.type = m_pMemory->type;
  v34 = this->m_achievementQueue.m_heap.m_Size - 1;
  this->m_achievementQueue.m_current.playerSlot = m_pMemory->playerSlot;
  if ( v34 > 0 )
    _V_memmove(dest: (unsigned __int8 *)m_pMemory, src: (unsigned __int8 *)&m_pMemory[1], count: 8 * v34);
  v35 = g_MedalDisplayTime;
  --this->m_achievementQueue.m_heap.m_Size;
  type = this->m_achievementQueue.m_current.type;
  playerSlot = this->m_achievementQueue.m_current.playerSlot;
  CountdownTimer::Start(this: &this->m_AchievementDisplayTimer, duration: v35);
  this->m_activeAchievement = type;
  g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/achievement_earned.wav");
  v38 = engine->GetAchievementMgr(this: engine);
  if ( v38 != nullptr )
  {
    v39 = (int)v38->GetAchievementByID(this: v38, a2: this->m_activeAchievement, a3: playerSlot);
    if ( v39 != 0 )
    {
      v40 = v39 + 12;
      if ( v39 != -12 )
      {
        if ( !bSlotIsLocked )
        {
          v41 = this->m_pScaleformUI;
          if ( v41 != nullptr )
            v41->LockSlot(this: v41, a2: this->m_iFlashSlot);
          bSlotIsLocked = true;
        }
        if ( this->m_MedalTitleTextHandle != nullptr )
        {
          v42 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v40 + 4))(a1: v40);
          v43 = CFmtStrN<256>::CFmtStrN<256>(this: &v56, pszFormat: "#%s_NAME", v42);
          v44 = this->m_pScaleformUI->SFHudFlashInterface::ScaleformFlashInterfaceMixin<CHudElement>::__vftable;
          v45 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v43->m_szBuf);
          v44->Value_SetText(this: this->m_pScaleformUI, a2: this->m_MedalTitleTextHandle, a3: v45);
        }
        if ( this->m_MedalBodyTextHandle != nullptr )
        {
          v46 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v40 + 4))(a1: v40);
          v47 = CFmtStrN<256>::CFmtStrN<256>(this: &v56, pszFormat: "#%s_DESC", v46);
          v48 = this->m_pScaleformUI->SFHudFlashInterface::ScaleformFlashInterfaceMixin<CHudElement>::__vftable;
          v49 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v47->m_szBuf);
          v48->Value_SetText(this: this->m_pScaleformUI, a2: this->m_MedalBodyTextHandle, a3: v49);
        }
        v50 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
        v51 = *(_DWORD *)v40;
        v52 = v50;
        LODWORD(DefusePercent) = &this->m_pScaleformUI->ValueArray_SetElement_2;
        v53 = (*(int (__thiscall **)(int))(v51 + 4))(a1: v40);
        (*(void (__thiscall **)(IScaleformUI *, void *, _DWORD, int))LODWORD(DefusePercent))(
          a1: this->m_pScaleformUI,
          a2: v52,
          a3: 0,
          a4: v53);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "setMedalAnnouncement",
          a4: v52,
          a5: 1u);
        this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v52, a3: 1u);
        if ( this->m_bActive && this->m_FlashAPI != nullptr )
        {
          v54 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
          this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v54, a3: 0, a4: 3);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "showPanel",
            a4: v54,
            a5: 1u);
          this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v54, a3: 1u);
        }
      }
    }
    goto LABEL_118;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021C190
// Name: protected: void SFHudInfoPanel::LocalizeAndDisplay(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::LocalizeAndDisplay(
        SFHudInfoPanel *this,
        const char *pszHudTxtMsg,
        const char *szRawString)
{
  vgui::ILocalize_vtbl *v4; // edx
  int v5; // eax
  char *v6; // esi
  wchar_t keyBindingBuf[512]; // [esp+Ch] [ebp-600h] BYREF
  wchar_t szBuf[256]; // [esp+40Ch] [ebp-200h] BYREF

  szBuf[0] = 0;
  v4 = g_pVGuiLocalize->__vftable;
  if ( pszHudTxtMsg != nullptr )
    v5 = ((int (__stdcall *)(const char *))v4->Find)(a1: pszHudTxtMsg);
  else
    v5 = ((int (__stdcall *)(const char *))v4->Find)(a1: szRawString);
  v6 = (char *)v5;
  if ( v5 == 0 )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szRawString, a3: szBuf, a4: 510);
    v6 = (char *)szBuf;
  }
  UTIL_ReplaceKeyBindings(a1: v6, inbuf: (const wchar_t *)v6, inbufsizebytes: 510, outbuf: keyBindingBuf);
  SFHudInfoPanel::SetHintText(this, text: (wchar_t *)v6);
}

//------------------------------------------------------------------------------
// Address: 0x1021C220
// Name: public: void CUtlQueue<struct SFHudInfoPanel::AchivementQueueInfo,class CUtlMemory<struct SFHudInfoPanel::AchivementQueueInfo,int>>::Insert(struct SFHudInfoPanel::AchivementQueueInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlQueue<SFHudInfoPanel::AchivementQueueInfo,CUtlMemory<SFHudInfoPanel::AchivementQueueInfo,int>>::Insert(
        CUtlQueue<SFHudInfoPanel::AchivementQueueInfo,CUtlMemory<SFHudInfoPanel::AchivementQueueInfo,int> > *this,
        const SFHudInfoPanel::AchivementQueueInfo *element)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  SFHudInfoPanel::AchivementQueueInfo *m_pMemory; // ecx
  int v6; // eax

  m_nAllocationCount = this->m_heap.m_Memory.m_nAllocationCount;
  m_Size = this->m_heap.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
      (CUtlMemory<vgui::PropertySheet::Page_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_heap.m_Size;
  m_pMemory = this->m_heap.m_Memory.m_pMemory;
  v6 = this->m_heap.m_Size - m_Size - 1;
  this->m_heap.m_pElements = this->m_heap.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 8 * v6);
  this->m_heap.m_Memory.m_pMemory[m_Size] = *element;
}

//------------------------------------------------------------------------------
// Address: 0x1021C290
// Name: void __MsgFunc_SFHudInfoPanel_KeyHintText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_SFHudInfoPanel_KeyHintText(bf_read *msg)
{
  CHud *Hud; // eax
  SFHudInfoPanel *Element; // esi
  const char *v3; // eax
  char pStr[256]; // [esp+4h] [ebp-100h] BYREF

  Hud = GetHud(nSlot: -1);
  Element = (SFHudInfoPanel *)CHud::FindElement(this: Hud, pName: "SFHudInfoPanel");
  if ( Element != nullptr )
  {
    CBitRead::ReadString(this: msg, pStr, maxLen: 255, bLine: false, pOutNumChars: nullptr);
    v3 = hudtextmessage->LookupString(this: hudtextmessage, a2: pStr, a3: 0);
    SFHudInfoPanel::LocalizeAndDisplay(this: Element, pszHudTxtMsg: v3, szRawString: pStr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021C300
// Name: public: SFHudInfoPanel::SFHudInfoPanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudInfoPanel *__thiscall SFHudInfoPanel::SFHudInfoPanel(SFHudInfoPanel *this, const char *value)
{
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx

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
  this->__vftable = (SFHudInfoPanel_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudInfoPanel_vtbl *)&SFHudInfoPanel::`vftable';
  this->m_HelpPanelHandle = nullptr;
  this->m_HelpTitleTextHandle = nullptr;
  this->m_HelpBodyTextHandle = nullptr;
  this->m_HintDisplayTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v3 = this->m_HintDisplayTimer.__vftable;
  this->m_HintDisplayTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v3->NetworkStateChanged)(a1: &this->m_HintDisplayTimer.m_duration);
  v4 = this->m_HintDisplayTimer.__vftable;
  this->m_HintDisplayTimer.m_timestamp.m_Value = -1.0;
  v4->NetworkStateChanged(this: &this->m_HintDisplayTimer, a2: &this->m_HintDisplayTimer.m_timestamp);
  this->m_PreviousDefusePercent = -1.0;
  this->m_DefusePanelHandle = nullptr;
  this->m_DefuseTitleTextHandle = nullptr;
  this->m_DefuseBodyTextHandle = nullptr;
  this->m_DefuseTimerTextHandle = nullptr;
  this->m_MedalPanelHandle = nullptr;
  this->m_MedalTitleTextHandle = nullptr;
  this->m_MedalBodyTextHandle = nullptr;
  this->m_achievementQueue.m_heap.m_Memory.m_pMemory = nullptr;
  this->m_achievementQueue.m_heap.m_Memory.m_nAllocationCount = 0;
  this->m_achievementQueue.m_heap.m_Memory.m_nGrowSize = 0;
  this->m_achievementQueue.m_heap.m_Size = 0;
  this->m_achievementQueue.m_heap.m_pElements = nullptr;
  this->m_activeAchievement = CSInvalidAchievement;
  this->m_AchievementDisplayTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v5 = this->m_AchievementDisplayTimer.__vftable;
  this->m_AchievementDisplayTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v5->NetworkStateChanged)(a1: &this->m_AchievementDisplayTimer.m_duration);
  v6 = this->m_AchievementDisplayTimer.__vftable;
  this->m_AchievementDisplayTimer.m_timestamp.m_Value = -1.0;
  v6->NetworkStateChanged(this: &this->m_AchievementDisplayTimer, a2: &this->m_AchievementDisplayTimer.m_timestamp);
  this->m_PriorityMsgDisplayTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v7 = this->m_PriorityMsgDisplayTimer.__vftable;
  this->m_PriorityMsgDisplayTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v7->NetworkStateChanged)(a1: &this->m_PriorityMsgDisplayTimer.m_duration);
  v8 = this->m_PriorityMsgDisplayTimer.__vftable;
  this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value = -1.0;
  v8->NetworkStateChanged(this: &this->m_PriorityMsgDisplayTimer, a2: &this->m_PriorityMsgDisplayTimer.m_timestamp);
  this->m_PriorityMessagePanelHandle = nullptr;
  this->m_PriorityMessageTitleTextHandle = nullptr;
  this->m_PriorityMessageBodyTextHandle = nullptr;
  *(_WORD *)&this->m_bDeferRaiseHelpPanel = 0;
  CUserMessages::HookMessage(this: usermessages, name: "HintText", hook: __MsgFunc_SFHudInfoPanel_KeyHintText);
  CUserMessages::HookMessage(this: usermessages, name: "KeyHintText", hook: __MsgFunc_SFHudInfoPanel_KeyHintText);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  if ( this->m_HintDisplayTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_HintDisplayTimer.NetworkStateChanged(
      this: &this->m_HintDisplayTimer,
      a2: &this->m_HintDisplayTimer.m_timestamp);
    this->m_HintDisplayTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_AchievementDisplayTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_AchievementDisplayTimer.NetworkStateChanged(
      this: &this->m_AchievementDisplayTimer,
      a2: &this->m_AchievementDisplayTimer.m_timestamp);
    this->m_AchievementDisplayTimer.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_PriorityMsgDisplayTimer.NetworkStateChanged(
      this: &this->m_PriorityMsgDisplayTimer,
      a2: &this->m_PriorityMsgDisplayTimer.m_timestamp);
    this->m_PriorityMsgDisplayTimer.m_timestamp.m_Value = -1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021C590
// Name: public: virtual void SFHudInfoPanel::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudInfoPanel::FireGameEvent(SFHudInfoPanel *this, IGameEvent *event)
{
  const char *v3; // eax
  int v4; // esi
  int (__thiscall *GetActiveSplitScreenPlayerSlot)(IVEngineClient *); // edx
  SFHudInfoPanel::AchivementQueueInfo queueInfo; // [esp+8h] [ebp-8h] BYREF

  v3 = event->GetName(this: event);
  if ( cl_show_scaleform_achievement_popups.m_pParent != nullptr
    && cl_show_scaleform_achievement_popups.m_pParent->m_Value.m_nValue != 0
    && _V_strcmp(s1: "achievement_earned_local", s2: v3) == 0 )
  {
    queueInfo.type = event->GetInt(this: event, a2: "achievement", a3: 0);
    v4 = event->GetInt(this: event, a2: "splitscreenplayer", a3: 0);
    GetActiveSplitScreenPlayerSlot = engine->GetActiveSplitScreenPlayerSlot;
    queueInfo.playerSlot = v4;
    if ( v4 == GetActiveSplitScreenPlayerSlot(this: engine) )
      CUtlQueue<SFHudInfoPanel::AchivementQueueInfo,CUtlMemory<SFHudInfoPanel::AchivementQueueInfo,int>>::Insert(
        this: &this->m_achievementQueue,
        element: &queueInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021C620
// Name: Create_SFHudInfoPanel
// Source: json
//------------------------------------------------------------------------------
SFHudInfoPanel *__cdecl Create_SFHudInfoPanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 200);
  memset(dst: v0, value: 0, count: 0xC8u);
  if ( v0 != nullptr )
    return SFHudInfoPanel::SFHudInfoPanel(this: (SFHudInfoPanel *)v0, value: "SFHudInfoPanel");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10222A40
// Name: public: virtual bool SFHudInfoPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SFHudInfoPanel::ShouldDraw(SFHudTeamCounter *this)
{
  return cl_drawhud.m_pParent != nullptr
      && cl_drawhud.m_pParent->m_Value.m_nValue != 0
      && CHudElement::ShouldDraw(this) != 0;
}
