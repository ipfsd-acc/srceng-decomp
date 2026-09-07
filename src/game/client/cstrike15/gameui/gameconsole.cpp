// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/gameconsole.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\gameui\gameconsole.h"

//------------------------------------------------------------------------------
// Address: 0x101D51B0
// Name: class CGameConsole __near & GameConsole(void)
// Source: json
//------------------------------------------------------------------------------
CGameConsole *__cdecl GameConsole()
{
  return &g_GameConsole;
}

//------------------------------------------------------------------------------
// Address: 0x101D51C0
// Name: public: virtual void CGameConsole::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsole::Activate(CGameConsole *this)
{
  if ( this->m_bInitialized )
  {
    g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
    this->m_pConsole->Activate(this: this->m_pConsole);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D51F0
// Name: public: virtual void CGameConsole::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsole::Hide(CGameConsole *this)
{
  if ( this->m_bInitialized )
    vgui::CConsoleDialog::Close(this: this->m_pConsole);
}

//------------------------------------------------------------------------------
// Address: 0x101D5200
// Name: public: virtual void CGameConsole::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsole::Clear(CGameConsole *this)
{
  if ( this->m_bInitialized )
    vgui::CConsoleDialog::Clear(this: this->m_pConsole);
}

//------------------------------------------------------------------------------
// Address: 0x101D5210
// Name: public: virtual bool CGameConsole::IsConsoleVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameConsole::IsConsoleVisible(CGameConsole *this)
{
  return this->m_bInitialized && this->m_pConsole->IsVisible(this: this->m_pConsole);
}

//------------------------------------------------------------------------------
// Address: 0x101D5230
// Name: public: virtual void CGameConsole::SetParent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsole::SetParent(CGameConsole *this, unsigned int parent)
{
  if ( this->m_bInitialized )
    this->m_pConsole->SetParent(this: this->m_pConsole, a2: parent);
}

//------------------------------------------------------------------------------
// Address: 0x101D5250
// Name: condump
// Source: json
//------------------------------------------------------------------------------
void __cdecl condump()
{
  vgui::CConsoleDialog::DumpConsoleTextToFile(this: g_GameConsole.m_pConsole);
}

//------------------------------------------------------------------------------
// Address: 0x101D5260
// Name: public: virtual void CGameConsole::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameConsole::Initialize(CGameConsole *this)
{
  CGameConsoleDialog *v2; // eax
  CGameConsoleDialog *v3; // edi
  int v4; // eax
  int stall; // [esp+8h] [ebp-8h] BYREF
  int swide; // [esp+Ch] [ebp-4h] BYREF

  v2 = (CGameConsoleDialog *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CGameConsoleDialog::CGameConsoleDialog(this: v2);
  else
    v3 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v3);
  this->m_pConsole = v3;
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: &stall);
  v4 = g_pVGuiSchemeManager->GetProportionalScaledValue(this: g_pVGuiSchemeManager, a2: 16);
  vgui::Panel::SetBounds(
    this: this->m_pConsole,
    x: swide / 2 - 4 * v4,
    y: v4,
    wide: v4 + swide / 2 + 2 * v4,
    tall: stall - 8 * v4);
  this->m_bInitialized = true;
}
