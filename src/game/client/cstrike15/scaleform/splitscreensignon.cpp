// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/splitscreensignon.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\scaleform\splitscreensignon.h"

//------------------------------------------------------------------------------
// Address: 0x10214190
// Name: public: virtual bool SplitScreenSignonWidget::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SplitScreenSignonWidget::PreUnloadFlash(SplitScreenSignonWidget *this)
{
  IMatchEventsSubscription *v2; // eax

  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  v2 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v2->Unsubscribe(this: v2, a2: &this->IMatchEventsSink);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102141E0
// Name: public: void SplitScreenSignonWidget::OnShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplitScreenSignonWidget::OnShow(SplitScreenSignonWidget *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v4; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = ScaleformUI();
      v4->Value_InvokeWithoutReturn(this: v4, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
    {
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_bVisible = true;
      return;
    }
  }
  else if ( !this->m_bLoading )
  {
    this->m_bLoading = true;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "SplitScreenSignon",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SplitScreenSignonWidget_SplitScreenSignon);
  }
  this->m_bVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x10214270
// Name: public: void SplitScreenSignonWidget::OnHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplitScreenSignonWidget::OnHide(SplitScreenSignonWidget *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v4; // eax

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v4 = ScaleformUI();
      v4->Value_InvokeWithoutReturn(this: v4, a2: this->m_FlashAPI, a3: "hidePanel", a4: nullptr, a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x102142D0
// Name: public: void SplitScreenSignonWidget::RevertUIToOnePlayerMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplitScreenSignonWidget::RevertUIToOnePlayerMode(SplitScreenSignonWidget *this)
{
  ConVarRef ss_pipsplit; // [esp+0h] [ebp-10h] BYREF
  ConVarRef ss_enable; // [esp+8h] [ebp-8h] BYREF

  this->m_iSecondPlayerId = -1;
  this->m_bWaitingForSignon = false;
  ConVarRef::ConVarRef(this: &ss_enable, pName: "ss_enable");
  ss_enable.m_pConVar->SetValue_2(this: ss_enable.m_pConVar, a2: 0);
  ConVarRef::ConVarRef(this: &ss_pipsplit, pName: "ss_pipsplit");
  ss_pipsplit.m_pConVar->SetValue_2(this: ss_pipsplit.m_pConVar, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10214320
// Name: public: virtual void SplitScreenSignonWidget::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplitScreenSignonWidget::FireGameEvent(SplitScreenSignonWidget *this, IGameEvent *pEvent)
{
  const char *v3; // eax
  const char *v4; // ebx
  const char *v5; // eax
  const char *v6; // esi
  bool v7; // zf
  SplitScreenSignonWidget *v8; // ecx

  v3 = pEvent->GetName(this: pEvent);
  if ( _V_stricmp(s1: v3, s2: "sfuievent") == 0 )
  {
    v4 = pEvent->GetString(this: pEvent, a2: "action", a3: prType);
    v5 = pEvent->GetString(this: pEvent, a2: "data", a3: prType);
    v6 = v5;
    if ( v4 != nullptr
      && *v4 != 0
      && v5 != nullptr
      && *v5 != 0
      && (_V_stricmp(s1: v5, s2: "mainmenu") == 0 || _V_stricmp(s1: v6, s2: "creategamedialog") == 0) )
    {
      if ( _V_stricmp(s1: v4, s2: "show") != 0 )
      {
        if ( this->m_bWantShown )
        {
          v7 = !this->m_bVisible;
          this->m_bWantShown = false;
          if ( !v7 )
          {
            v8 = this;
LABEL_16:
            SplitScreenSignonWidget::OnHide(this: v8);
          }
        }
      }
      else if ( !this->m_bWantShown )
      {
        v7 = !this->m_bConditionsAreValid;
        this->m_bWantShown = true;
        if ( !v7 != this->m_bVisible )
        {
          v8 = this;
          if ( !v7 )
          {
            SplitScreenSignonWidget::OnShow(this);
            return;
          }
          goto LABEL_16;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10214410
// Name: public: SplitScreenSignonWidget::SplitScreenSignonWidget(void)
// Source: json
//------------------------------------------------------------------------------
SplitScreenSignonWidget *__thiscall SplitScreenSignonWidget::SplitScreenSignonWidget(SplitScreenSignonWidget *this)
{
  this->m_bFlashAPIIsValid = false;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->m_nDebugID = 42;
  this->m_iFlashSlot = -1;
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->m_pPlayer2Name = nullptr;
  *(_DWORD *)&this->m_bVisible = 0;
  *(_WORD *)&this->m_bWaitingForSignon = 0;
  this->ScaleformFlashInterfaceMixin<CGameEventListener>::CGameEventListener::IGameEventListener2::__vftable = (SplitScreenSignonWidget_vtbl *)&SplitScreenSignonWidget::`vftable'{for `ScaleformFlashInterfaceMixin<CGameEventListener>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&SplitScreenSignonWidget::`vftable'{for `IMatchEventsSink'};
  this->m_iSecondPlayerId = -1;
  this->m_iControllerThatPressedStart = -1;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "sfuievent", a4: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10214470
// Name: public: virtual void SplitScreenSignonWidget::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SplitScreenSignonWidget::FlashReady(SplitScreenSignonWidget *this)
{
  IMatchEventsSubscription *v2; // eax

  this->m_bLoading = false;
  v2 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v2->Subscribe(this: v2, a2: &this->IMatchEventsSink);
  if ( this->m_bVisible )
    SplitScreenSignonWidget::OnShow(this);
  else
    SplitScreenSignonWidget::OnHide(this);
}
