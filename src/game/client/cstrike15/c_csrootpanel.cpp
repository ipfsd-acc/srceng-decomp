// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/c_csrootpanel.cpp
// Functions: 3
// ============================================================

#include "game\client\cstrike15\c_csrootpanel.h"

//------------------------------------------------------------------------------
// Address: 0x101BF400
// Name: public: virtual void C_CSRootPanel::PaintTraverse(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSRootPanel::PaintTraverse(C_CSRootPanel *this, int Repaint, int allowForce)
{
  vgui::Panel::PaintTraverse(this, repaint: Repaint, allowForce);
}

//------------------------------------------------------------------------------
// Address: 0x101BF410
// Name: public: virtual void C_CSRootPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall C_CSRootPanel::OnThink(C_CSRootPanel *this@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  vgui::Panel::OnThink(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x101BF420
// Name: public: C_CSRootPanel::C_CSRootPanel(unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
C_CSRootPanel *__thiscall C_CSRootPanel::C_CSRootPanel(
        C_CSRootPanel *this,
        unsigned int parent,
        int slot,
        const char *panelName)
{
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent: nullptr, panelName);
  this->__vftable = (C_CSRootPanel_vtbl *)&C_CSRootPanel::`vftable';
  this->m_Effects.m_Memory.m_pMemory = nullptr;
  this->m_Effects.m_Memory.m_nAllocationCount = 0;
  this->m_Effects.m_Memory.m_nGrowSize = 0;
  this->m_Effects.m_Size = 0;
  this->m_Effects.m_pElements = nullptr;
  this->m_nSplitSlot = slot;
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPostChildPaintEnabled(this, state: true);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: (int *)&panelName);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: w, tall: (int)panelName);
  vgui::Panel::SetZPos(this, z: 0);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}
