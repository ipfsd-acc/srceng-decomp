// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/createstartscreen_scaleform.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\scaleform\createstartscreen_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020AE90
// Name: protected: virtual void CCreateStartScreenScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateStartScreenScaleform::PostUnloadFlash(CCreateStartScreenScaleform *this)
{
  IMatchEventsSink *v2; // edi
  IMatchEventsSubscription *v3; // eax

  if ( this != nullptr )
    v2 = &this->IMatchEventsSink;
  else
    v2 = nullptr;
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Unsubscribe(this: v3, a2: v2);
  CCreateStartScreenScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CCreateStartScreenScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020AEE0
// Name: protected: virtual void CCreateStartScreenScaleform::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateStartScreenScaleform::OnEvent(CCreateStartScreenScaleform *this, KeyValues *pEvent)
{
  const char *Name; // edi
  char *v3; // eax
  CCStrike15BasePanel *v4; // eax
  char *String; // eax
  CCStrike15BasePanel *v6; // eax
  int Int; // [esp-4h] [ebp-Ch]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnSysSigninChange") != 0
    || (v3 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType),
        _V_stricmp(s1: "signin", s2: v3) != 0) )
  {
    if ( _V_stricmp(s1: Name, s2: "OnSysXUIEvent") == 0 )
    {
      String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
      if ( _V_stricmp(s1: "closed", s2: String) == 0 )
      {
        v6 = BasePanel();
        CBaseModPanel::NotifySignInCancelled(this: v6);
      }
    }
  }
  else
  {
    Int = KeyValues::GetInt(this: pEvent, keyName: "user0", defaultValue: -1);
    v4 = BasePanel();
    CBaseModPanel::NotifySignInCompleted(this: v4, userID: Int);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AFA0
// Name: protected: void CCreateStartScreenScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateStartScreenScaleform::Show(CCreateStartScreenScaleform *this)
{
  char i; // al
  IScaleformUI *v3; // eax
  CGameUI *v4; // eax

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v3 = ScaleformUI();
    v3->Value_InvokeWithoutReturn(this: v3, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  v4 = GameUI();
  CGameUI::SetBackgroundMusicDesired(this: v4, bPlayMusic: true);
}

//------------------------------------------------------------------------------
// Address: 0x1020B010
// Name: public: static void CCreateStartScreenScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateStartScreenScaleform::UnloadDialog()
{
  if ( CCreateStartScreenScaleform::m_pInstance != nullptr
    && CCreateStartScreenScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateStartScreenScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateStartScreenScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateStartScreenScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateStartScreenScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B040
// Name: protected: virtual void CCreateStartScreenScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCreateStartScreenScaleform::FlashReady(CCreateStartScreenScaleform *this)
{
  CCreateStartScreenScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020B050
// Name: protected: CCreateStartScreenScaleform::CCreateStartScreenScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CCreateStartScreenScaleform *__thiscall CCreateStartScreenScaleform::CCreateStartScreenScaleform(
        CCreateStartScreenScaleform *this)
{
  IMatchEventsSink *v2; // edi
  IMatchEventsSubscription *v3; // eax

  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  v2 = &this->IMatchEventsSink;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCreateStartScreenScaleform_vtbl *)&CCreateStartScreenScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CCreateStartScreenScaleform::`vftable'{for `IMatchEventsSink'};
  v3 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v3->Subscribe(this: v3, a2: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020B0A0
// Name: public: static void CCreateStartScreenScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateStartScreenScaleform::LoadDialog()
{
  CCreateStartScreenScaleform *v0; // eax
  CCreateStartScreenScaleform *started; // eax

  if ( CCreateStartScreenScaleform::m_pInstance == nullptr )
  {
    v0 = (CCreateStartScreenScaleform *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v0 != nullptr )
      started = CCreateStartScreenScaleform::CCreateStartScreenScaleform(this: v0);
    else
      started = nullptr;
    CCreateStartScreenScaleform::m_pInstance = started;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "StartScreen",
      a4: (ScaleformUIFunctionHandlerObject *)started,
      a5: pScaleformFunctionHandler_CCreateStartScreenScaleform_StartScreen);
  }
}
