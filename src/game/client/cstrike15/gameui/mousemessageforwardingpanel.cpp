// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/mousemessageforwardingpanel.cpp
// Functions: 7
// ============================================================

#include "game\client\cstrike15\gameui\mousemessageforwardingpanel.h"

//------------------------------------------------------------------------------
// Address: 0x101D72C0
// Name: public: static char const __near * CMouseMessageForwardingPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMouseMessageForwardingPanel::GetPanelClassName()
{
  return "CMouseMessageForwardingPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101D72D0
// Name: public: virtual void CMouseMessageForwardingPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::PerformLayout(CMouseMessageForwardingPanel *this)
{
  vgui::Panel *v2; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int t; // [esp+8h] [ebp-4h] BYREF

  v2 = this->GetParent(this);
  vgui::Panel::GetSize(this: v2, wide: &w, tall: &t);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: w, tall: t);
}

//------------------------------------------------------------------------------
// Address: 0x101D7360
// Name: public: CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMouseMessageForwardingPanel *__thiscall CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(
        CMouseMessageForwardingPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CMouseMessageForwardingPanel_vtbl *)&CMouseMessageForwardingPanel::`vftable';
  if ( `CMouseMessageForwardingPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMouseMessageForwardingPanel");
    v4->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CMouseMessageForwardingPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMouseMessageForwardingPanel");
    v5->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CMouseMessageForwardingPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMouseMessageForwardingPanel");
    v6->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7440
// Name: public: virtual struct vgui::PanelMessageMap __near * CMouseMessageForwardingPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMouseMessageForwardingPanel::GetMessageMap(CMouseMessageForwardingPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMouseMessageForwardingPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMouseMessageForwardingPanel::GetMessageMap'::`2'::s_pMap;
  `CMouseMessageForwardingPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMouseMessageForwardingPanel");
  `CMouseMessageForwardingPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D7470
// Name: public: virtual struct PanelAnimationMap __near * CMouseMessageForwardingPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMouseMessageForwardingPanel::GetAnimMap(CMouseMessageForwardingPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMouseMessageForwardingPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101D7480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMouseMessageForwardingPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMouseMessageForwardingPanel::GetKBMap(CMouseMessageForwardingPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMouseMessageForwardingPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMouseMessageForwardingPanel::GetKBMap'::`2'::s_pMap;
  `CMouseMessageForwardingPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMouseMessageForwardingPanel");
  `CMouseMessageForwardingPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B7110
// Name: public: virtual void CMouseMessageForwardingPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::OnMouseDoublePressed(vgui::TreeViewSubPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "MouseDoublePressed", firstKey: "code", firstValue: code);
    vgui::Panel::CallParentFunction(this, message: v4);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}
