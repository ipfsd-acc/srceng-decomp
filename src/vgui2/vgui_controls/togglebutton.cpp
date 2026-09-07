// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/togglebutton.cpp
// Functions: 9
// ============================================================

#include "vgui2\vgui_controls\togglebutton.h"

//------------------------------------------------------------------------------
// Address: 0x102BB390
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x102BB3E0
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BB4A0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102BB4E0
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102BB500
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BB5E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB610
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x102BB620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB650
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004E3B0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x1004E400
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004E4C0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1004E500
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1004E520
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004E600
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E630
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x1004E640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004E670
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00426690
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x004266E0
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004267A0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004267E0
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00426800
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004268E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426910
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00426920
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426980
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10058AE0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x10058B30
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058BF0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10058C30
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10058C50
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10058D30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058D60
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x10058D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10058DA0
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x006031C0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00603210
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x006032D0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00603310
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00603330
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00603410
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00603440
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00603450
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00603480
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102BB440
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x102BB490
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BB550
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102BB590
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102BB5B0
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BB690
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB6C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x102BB6D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BB700
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EA020
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x102EA080
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EA140
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102EA180
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102EA1A0
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EA280
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EA2B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x102EA2C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EA2F0
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BA740
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x100BA7A0
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BA860
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100BA8A0
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x100BA8C0
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA9D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x100BA9E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BAA10
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00446C10
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00446C70
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00446D30
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00446D70
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00446D90
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00446E70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00446EA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00446EB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00446F10
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042E1C0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x0042E210
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  BOOL v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  LOBYTE(v5) = !this->IsSelected(this);
  v4->SetSelected(this, a2: v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042E2C0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0042E300
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0042E320
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042E400
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E430
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042E440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042E470
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063A8B0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x0063A900
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063A9C0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0063AA00
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0063AA20
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063AB00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063AB30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x0063AB40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063AB70
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1004B600
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x1004B660
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004B720
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1004B760
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1004B780
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004B860
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B890
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x1004B8A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B8D0
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10064F60
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x10064FB0
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10065070
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100650B0
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x100650D0
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100651B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100651E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x100651F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10065220
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004369C0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00436A10
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00436AD0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00436B10
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00436B30
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00436C10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436C40
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00436C50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00436C80
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004800E0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00480130
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  BOOL v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  LOBYTE(v5) = !this->IsSelected(this);
  v4->SetSelected(this, a2: v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004801E0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00480220
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00480240
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00480320
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480350
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00480360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480390
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004252E0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00425330
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004253F0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00425430
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00425450
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425530
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00425560
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00425570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004255A0
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00428CF0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x00428D40
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428E00
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00428E40
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00428E60
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428F40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428F70
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x00428F80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428FB0
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039E4C0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x1039E520
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039E5E0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1039E620
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1039E640
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039E720
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039E750
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x1039E760
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039E790
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10396EB0
// Name: public: static char const __near * vgui::ToggleButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ToggleButton::GetPanelClassName()
{
  return "ToggleButton";
}

//------------------------------------------------------------------------------
// Address: 0x10396F10
// Name: public: virtual void vgui::ToggleButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::DoClick(vgui::ToggleButton *this)
{
  bool v2; // zf
  vgui::ToggleButton_vtbl *v3; // eax
  vgui::ToggleButton_vtbl *v4; // edi
  bool v5; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al

  v2 = !this->IsSelected(this);
  v3 = this->__vftable;
  if ( v2 )
  {
    if ( !v3->IsSelected(this) )
      ((void (__stdcall *)(int))this->ForceDepressed)(a1: 1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->ForceDepressed)(a1: 0);
  }
  v4 = this->__vftable;
  v5 = this->IsSelected(this);
  v4->SetSelected(this, a2: !v5);
  this->FireActionSignal(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ButtonToggled");
  else
    v7 = nullptr;
  v8 = this->IsSelected(this);
  KeyValues::SetInt(this: v7, keyName: "state", value: v8);
  this->PostActionSignal(this, a2: v7);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10396FD0
// Name: protected: virtual void vgui::ToggleButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::ApplySchemeSettings(vgui::ToggleButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  this->_selectedColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "ToggleButton.SelectedTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10397010
// Name: protected: virtual void vgui::ToggleButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ToggleButton::OnKeyCodePressed(vgui::ToggleButton *this, ButtonCode_t code)
{
  if ( code != KEY_ENTER )
    vgui::Button::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10397030
// Name: public: vgui::ToggleButton::ToggleButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__thiscall vgui::ToggleButton::ToggleButton(
        vgui::ToggleButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(this, parent, panelName, text, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (vgui::ToggleButton_vtbl *)&vgui::ToggleButton::`vftable';
  if ( `vgui::ToggleButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
    v5->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Button");
  }
  if ( `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ToggleButton");
    v6->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Button");
  }
  if ( `vgui::ToggleButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ToggleButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
    v7->pfnClassName = vgui::ToggleButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  }
  this->_selectedColor = 0;
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10397110
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ToggleButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ToggleButton::GetMessageMap(vgui::ToggleButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  `vgui::ToggleButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10397140
// Name: public: virtual struct PanelAnimationMap __near * vgui::ToggleButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ToggleButton::GetAnimMap(vgui::ToggleButton *this)
{
  return FindOrAddPanelAnimationMap(className: "ToggleButton");
}

//------------------------------------------------------------------------------
// Address: 0x10397150
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ToggleButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ToggleButton::GetKBMap(vgui::ToggleButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ToggleButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ToggleButton::GetKBMap'::`2'::s_pMap;
  `vgui::ToggleButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  `vgui::ToggleButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10397180
// Name: Create_ToggleButton
// Source: json
//------------------------------------------------------------------------------
vgui::ToggleButton *__cdecl Create_ToggleButton()
{
  vgui::ToggleButton *v0; // eax

  v0 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return vgui::ToggleButton::ToggleButton(this: v0, parent: nullptr, panelName: nullptr, text: "ToggleButton");
  else
    return nullptr;
}

} // namespace server
