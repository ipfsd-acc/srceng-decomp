// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_game_viewport.cpp
// Functions: 3
// ============================================================

#include "game\client\vgui_game_viewport.h"

//------------------------------------------------------------------------------
// Address: 0x101833B0
// Name: class IGameSystem __near * ViewportClientSystem(void)
// Source: json
//------------------------------------------------------------------------------
CViewportClientSystem *__cdecl ViewportClientSystem()
{
  return &g_ViewportClientSystem;
}

//------------------------------------------------------------------------------
// Address: 0x101833C0
// Name: public: virtual char const __near * CViewportClientSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CViewportClientSystem::Name(CViewportClientSystem *this)
{
  return "CViewportClientSystem";
}

//------------------------------------------------------------------------------
// Address: 0x101833D0
// Name: public: virtual bool CViewportClientSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CViewportClientSystem::Init(CViewportClientSystem *this)
{
  IClientMode *ClientMode; // eax

  ClientMode = GetClientMode();
  ClientMode->Layout(this: ClientMode, a2: false);
  return 1;
}
