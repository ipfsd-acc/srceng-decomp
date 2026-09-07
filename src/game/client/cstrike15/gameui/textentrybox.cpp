// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/textentrybox.cpp
// Functions: 4
// ============================================================

#include "game\client\cstrike15\gameui\textentrybox.h"

//------------------------------------------------------------------------------
// Address: 0x101E8550
// Name: public: static char const __near * vgui::QueryBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::QueryBox::GetPanelClassName()
{
  return "QueryBox";
}

//------------------------------------------------------------------------------
// Address: 0x101E8560
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::QueryBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::QueryBox::GetMessageMap(vgui::QueryBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::QueryBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::QueryBox::GetMessageMap'::`2'::s_pMap;
  `vgui::QueryBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
  `vgui::QueryBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E8590
// Name: public: virtual struct PanelAnimationMap __near * vgui::QueryBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::QueryBox::GetAnimMap(vgui::QueryBox *this)
{
  return FindOrAddPanelAnimationMap(className: "QueryBox");
}

//------------------------------------------------------------------------------
// Address: 0x101E85A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::QueryBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::QueryBox::GetKBMap(vgui::QueryBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::QueryBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::QueryBox::GetKBMap'::`2'::s_pMap;
  `vgui::QueryBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
  `vgui::QueryBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}
