// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/commandcheckbutton.cpp
// Functions: 4
// ============================================================

#include "game\client\cstrike15\gameui\commandcheckbutton.h"

//------------------------------------------------------------------------------
// Address: 0x101D1890
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x101D18A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D18D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x101D18E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}
