// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_msg.cpp
// Functions: 3
// ============================================================

#include "game\client\hud_msg.h"

//------------------------------------------------------------------------------
// Address: 0x1010E4B0
// Name: public: void CHud::MsgFunc_SendAudio(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::MsgFunc_SendAudio(CHud *this, bf_read *msg)
{
  char szString[2048]; // [esp+8h] [ebp-820h] BYREF
  CLocalPlayerFilter filter; // [esp+808h] [ebp-20h] BYREF

  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: -1,
    soundname: szString,
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1010E510
// Name: public: void CHud::ResetHUD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHud::ResetHUD(CHud *this)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v3; // eax
  int i; // esi
  const UniqueId_t *HudList; // eax
  IClientMode *v6; // eax
  vgui::AnimationController *v7; // eax

  ClientMode = GetClientMode();
  v3 = ClientMode->GetViewportAnimationController(this: ClientMode);
  vgui::AnimationController::CancelAllAnimations(this: v3);
  for ( i = 0; i < *(_DWORD *)&CHud::GetHudList((CDmxElement *)this)->m_Value[12]; ++i )
  {
    HudList = CHud::GetHudList((CDmxElement *)this);
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)HudList->m_Value + 4 * i) + 32))(a1: *(_DWORD *)(*(_DWORD *)HudList->m_Value + 4 * i));
  }
  v6 = GetClientMode();
  v7 = v6->GetViewportAnimationController(this: v6);
  vgui::AnimationController::RunAllAnimationsToCompletion(this: v7);
  this->m_flMouseSensitivity = 0.0;
  this->m_flMouseSensitivityFactor = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1010E580
// Name: public: void CHud::MsgFunc_ResetHUD(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHud::MsgFunc_ResetHUD(CHud *this, bf_read *msg)
{
  CHud::ResetHUD(this);
}
