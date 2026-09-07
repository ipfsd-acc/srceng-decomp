// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudtrialtimer.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudtrialtimer.h"

//------------------------------------------------------------------------------
// Address: 0x10222BE0
// Name: public: SFHudTrialTimer::SFHudTrialTimer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudTrialTimer *__thiscall SFHudTrialTimer::SFHudTrialTimer(SFHudTrialTimer *this, const char *value)
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
  this->__vftable = (SFHudTrialTimer_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudTrialTimer_vtbl *)&SFHudTrialTimer::`vftable';
  this->m_fNextUpdate = 0.0;
  this->m_bVisible = false;
  CTraceFilterSkipTwoEntities::SetPassEntity2((CTraceFilterSkipTwoEntities *)this, pPassEntity2: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10222C50
// Name: public: virtual void SFHudTrialTimer::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTrialTimer::LevelInit(SFHudTrialTimer *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "TrialTimer",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudTrialTimer_TrialTimer);
}

//------------------------------------------------------------------------------
// Address: 0x10222C80
// Name: protected: void SFHudTrialTimer::ShowPanel(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTrialTimer::ShowPanel(SFHudTrialTimer *this, bool bShow, bool force)
{
  bool v4; // zf
  void (*ProcessInput)(void); // edx
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  char j; // al

  if ( bShow != this->m_bVisible || force )
  {
    v4 = this->m_FlashAPI == nullptr;
    this->m_bVisible = bShow;
    if ( !v4 )
    {
      if ( bShow )
      {
        ProcessInput = (void (*)(void))this->ProcessInput;
        this->m_fNextUpdate = 0.0;
        ProcessInput();
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
            a3: "ShowPanel",
            a4: nullptr,
            a5: 0);
        }
        if ( m_pScaleformUI != nullptr )
LABEL_18:
          m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      }
      else
      {
        for ( j = 1; ; j = 0 )
        {
          m_pScaleformUI = this->m_pScaleformUI;
          if ( j == 0 )
            break;
          if ( m_pScaleformUI != nullptr )
            m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "HidePanel",
            a4: nullptr,
            a5: 0);
        }
        if ( m_pScaleformUI != nullptr )
          goto LABEL_18;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222D60
// Name: public: virtual void SFHudTrialTimer::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudTrialTimer::ProcessInput(SFHudTrialTimer *this@<ecx>, int a2@<edi>)
{
  float v3; // xmm0_4
  __m128 m_fValue_low; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  float v9; // xmm1_4
  int v10; // edx
  int v11; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  vgui::ILocalize_vtbl *v13; // edi
  int v14; // eax
  char i; // al
  IScaleformUI *v16; // ecx
  wchar_t buffer[128]; // [esp+4h] [ebp-140h] BYREF
  wchar_t wTrialTime[16]; // [esp+104h] [ebp-40h] BYREF
  char strTrialTime[16]; // [esp+124h] [ebp-20h] BYREF
  ConVarRef xbox_arcade_remaining_trial_time; // [esp+134h] [ebp-10h] BYREF
  ConVarRef xbox_arcade_title_unlocked; // [esp+13Ch] [ebp-8h] BYREF

  if ( this->m_bFlashAPIIsValid )
  {
    v3 = *(float *)(gpGlobals.m_Index + 12);
    if ( v3 > this->m_fNextUpdate )
    {
      this->m_fNextUpdate = v3 + 60.0;
      ConVarRef::ConVarRef(this: &xbox_arcade_title_unlocked, pName: "xbox_arcade_title_unlocked");
      ConVarRef::ConVarRef(this: &xbox_arcade_remaining_trial_time, pName: "xbox_arcade_remaining_trial_time");
      if ( xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue == 0 )
      {
        m_fValue_low = (__m128)LODWORD(xbox_arcade_remaining_trial_time.m_pConVarState->m_Value.m_fValue);
        m_fValue_low.m128_f32[0] = m_fValue_low.m128_f32[0] * 0.016666668;
        v5.m128_i32[0] = 1258291200;
        v6 = _mm_and_ps((__m128)0x80000000, m_fValue_low);
        v5.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(m_fValue_low, v6), v5).m128_f32[0]) & 0x4B000000
                       | v6.m128_i32[0];
        v7 = m_fValue_low;
        v7.m128_f32[0] = (float)(m_fValue_low.m128_f32[0] + v5.m128_f32[0]) - v5.m128_f32[0];
        v8 = v7;
        v8.m128_f32[0] = v7.m128_f32[0] - m_fValue_low.m128_f32[0];
        v9 = v7.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v8, v6).m128_u32[0] & 0x3F800000);
        v10 = ((int)v9 <= 0) - 1;
        v11 = v10 & (int)v9;
        if ( v11 == 1 )
        {
          while ( 1 )
          {
            m_pScaleformUI = this->m_pScaleformUI;
            if ( (_BYTE)v11 == 0 )
              break;
            if ( m_pScaleformUI != nullptr )
              m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
            this->m_pTimerMessage->SetTextHTML_2(this: this->m_pTimerMessage, a2: "#SFUI_TrialHudTextMinute");
            LOBYTE(v11) = 0;
          }
          if ( m_pScaleformUI != nullptr )
            m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        }
        else
        {
          V_snprintf(pDest: strTrialTime, maxLen: 0x10u, pFormat: "%d", v10 & (int)v9);
          ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *, int, int))g_pVGuiLocalize->ConvertANSIToUnicode)(
            a1: g_pVGuiLocalize,
            a2: strTrialTime,
            a3: wTrialTime,
            a4: 32,
            a5: a2);
          v13 = g_pVGuiLocalize->__vftable;
          v14 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
                  a1: g_pVGuiLocalize,
                  a2: "#SFUI_TrialHudTextMinutes",
                  a3: 1,
                  a4: wTrialTime);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v13->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: buffer,
            a3: 256,
            a4: v14);
          for ( i = 1; ; i = 0 )
          {
            v16 = this->m_pScaleformUI;
            if ( i == 0 )
              break;
            if ( v16 != nullptr )
              v16->LockSlot(this: v16, a2: this->m_iFlashSlot);
            this->m_pTimerMessage->SetTextHTML(this: this->m_pTimerMessage, a2: buffer);
          }
          if ( v16 != nullptr )
            v16->UnlockSlot(this: v16, a2: this->m_iFlashSlot);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222F20
// Name: public: virtual void SFHudTrialTimer::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTrialTimer::SetActive(SFHudTrialTimer *this, bool bActive)
{
  bool v3; // zf
  void (*ProcessInput)(void); // edx
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  char j; // al
  IScaleformUI *v8; // ecx

  if ( bActive != this->m_bVisible )
  {
    v3 = this->m_FlashAPI == nullptr;
    this->m_bVisible = bActive;
    if ( !v3 )
    {
      if ( bActive )
      {
        ProcessInput = (void (*)(void))this->ProcessInput;
        this->m_fNextUpdate = 0.0;
        ProcessInput();
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
            a3: "ShowPanel",
            a4: nullptr,
            a5: 0);
        }
        if ( m_pScaleformUI != nullptr )
        {
          m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
          CHudElement::SetActive(this, bActive);
          return;
        }
      }
      else
      {
        for ( j = 1; ; j = 0 )
        {
          v8 = this->m_pScaleformUI;
          if ( j == 0 )
            break;
          if ( v8 != nullptr )
            v8->LockSlot(this: v8, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "HidePanel",
            a4: nullptr,
            a5: 0);
        }
        if ( v8 != nullptr )
          v8->UnlockSlot(this: v8, a2: this->m_iFlashSlot);
      }
    }
  }
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10223000
// Name: public: virtual bool SFHudTrialTimer::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall SFHudTrialTimer::ShouldDraw(SFHudTrialTimer *this)
{
  int m_nValue; // esi
  ConVarRef xbox_arcade_title_unlocked; // [esp+8h] [ebp-8h] BYREF

  if ( cl_drawhud.m_pParent != nullptr )
    m_nValue = cl_drawhud.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  ConVarRef::ConVarRef(this: &xbox_arcade_title_unlocked, pName: "xbox_arcade_title_unlocked");
  return m_nValue != 0
      && xbox_arcade_title_unlocked.m_pConVarState->m_Value.m_nValue == 0
      && CHudElement::ShouldDraw(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10223060
// Name: public: virtual void SFHudTrialTimer::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudTrialTimer::FlashReady(SFHudTrialTimer *this)
{
  void *v2; // edi
  ISFTextObject *v3; // eax
  IScaleformUI *m_pScaleformUI; // ecx

  v2 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "Panel");
  if ( v2 != nullptr )
  {
    v3 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
           this: this->m_pScaleformUI,
           a2: v2,
           a3: "AnimatedText");
    m_pScaleformUI = this->m_pScaleformUI;
    this->m_pTimerMessage = v3;
    m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v2);
  }
  SFHudTrialTimer::ShowPanel(this, bShow: this->m_bVisible, force: true);
}

//------------------------------------------------------------------------------
// Address: 0x102230C0
// Name: Create_SFHudTrialTimer
// Source: json
//------------------------------------------------------------------------------
SFHudTrialTimer *__cdecl Create_SFHudTrialTimer()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 84);
  memset(dst: v0, value: 0, count: 0x54u);
  if ( v0 != nullptr )
    return SFHudTrialTimer::SFHudTrialTimer(this: (SFHudTrialTimer *)v0, value: "SFHudTrialTimer");
  else
    return nullptr;
}
