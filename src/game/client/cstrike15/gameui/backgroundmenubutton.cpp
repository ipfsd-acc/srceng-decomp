// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/backgroundmenubutton.cpp
// Functions: 3
// ============================================================

#include "game\client\cstrike15\gameui\backgroundmenubutton.h"

//------------------------------------------------------------------------------
// Address: 0x101833F0
// Name: public: virtual void CBackgroundMenuButton::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBackgroundMenuButton::OnCommand(VideoPanel *this, const char *pcCommand)
{
  vgui::Panel::OnCommand(this, command: pcCommand);
}

//------------------------------------------------------------------------------
// Address: 0x101D0220
// Name: public: CBackgroundMenuButton::CBackgroundMenuButton(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBackgroundMenuButton *__thiscall CBackgroundMenuButton::CBackgroundMenuButton(
        CBackgroundMenuButton *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::Button::Button(this, parent, panelName: name, text: prType, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (CBackgroundMenuButton_vtbl *)&CBackgroundMenuButton::`vftable';
  this->m_pImage = nullptr;
  this->m_pMouseOverImage = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D0290
// Name: protected: virtual void CBackgroundMenuButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBackgroundMenuButton::ApplySchemeSettings(CBackgroundMenuButton *this, vgui::IScheme *pScheme)
{
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  ((void (__thiscall *)(CBackgroundMenuButton *, int))this->SetFgColor)(a1: this, a2: -1);
  ((void (__thiscall *)(CBackgroundMenuButton *, _DWORD))this->SetBgColor)(a1: this, a2: 0);
  ((void (__thiscall *)(CBackgroundMenuButton *, int, _DWORD))this->SetDefaultColor)(a1: this, a2: -1, a3: 0);
  ((void (__thiscall *)(CBackgroundMenuButton *, int, _DWORD))this->SetArmedColor)(a1: this, a2: -16711681, a3: 0);
  ((void (__thiscall *)(CBackgroundMenuButton *, int, _DWORD))this->SetDepressedColor)(a1: this, a2: -16711681, a3: 0);
  this->SetContentAlignment(this, a2: a_west);
  this->SetBorder(this, a2: nullptr);
  this->SetDefaultBorder(this, a2: nullptr);
  this->SetDepressedBorder(this, a2: nullptr);
  this->SetKeyFocusBorder(this, a2: nullptr);
  this->SetTextInset(this, a2: 0, a3: 0);
  vgui::Panel::SetAlpha(this, alpha: 0);
}
