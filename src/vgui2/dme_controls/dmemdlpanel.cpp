// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmemdlpanel.cpp
// Functions: 5
// ============================================================

#include "vgui2\dme_controls\dmemdlpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0047F040
// Name: public: static char const __near * CDmeMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeMDLPanel::GetPanelClassName()
{
  return "CDmeMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0047F050
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeMDLPanel::GetMessageMap(CDmeMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F080
// Name: public: virtual struct PanelAnimationMap __near * CDmeMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeMDLPanel::GetAnimMap(CDmeMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0047F090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeMDLPanel::GetKBMap(CDmeMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetKBMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047F0C0
// Name: public: CDmeMDLPanel::CDmeMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmeMDLPanel::CDmeMDLPanel(CDmeMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CMDLPanel::CMDLPanel(this, pParent, pName);
  this->__vftable = (CDmeMDLPanel_vtbl *)&CDmeMDLPanel::`vftable';
  if ( `CDmeMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
    v4->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
    v5->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
    v6->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  }
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104849C0
// Name: public: static char const __near * CDmeMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeMDLPanel::GetPanelClassName()
{
  return "CDmeMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104849D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeMDLPanel::GetMessageMap(CDmeMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10484A00
// Name: public: virtual struct PanelAnimationMap __near * CDmeMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeMDLPanel::GetAnimMap(CDmeMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10484A10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeMDLPanel::GetKBMap(CDmeMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetKBMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10484A40
// Name: public: CDmeMDLPanel::CDmeMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmeMDLPanel::CDmeMDLPanel(CDmeMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CMDLPanel::CMDLPanel(this, pParent, pName);
  this->__vftable = (CDmeMDLPanel_vtbl *)&CDmeMDLPanel::`vftable';
  if ( `CDmeMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
    v4->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
    v5->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
    v6->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  }
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048FC50
// Name: public: static char const __near * CDmeMDLPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeMDLPanel::GetPanelClassName()
{
  return "CDmeMDLPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048FC60
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeMDLPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeMDLPanel::GetMessageMap(CDmeMDLPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048FC90
// Name: public: virtual struct PanelAnimationMap __near * CDmeMDLPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeMDLPanel::GetAnimMap(CDmeMDLPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0048FCA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeMDLPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeMDLPanel::GetKBMap(CDmeMDLPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeMDLPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeMDLPanel::GetKBMap'::`2'::s_pMap;
  `CDmeMDLPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
  `CDmeMDLPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048FCD0
// Name: public: CDmeMDLPanel::CDmeMDLPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMDLPanel *__thiscall CDmeMDLPanel::CDmeMDLPanel(CDmeMDLPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CMDLPanel::CMDLPanel(this, pParent, pName);
  this->__vftable = (CDmeMDLPanel_vtbl *)&CDmeMDLPanel::`vftable';
  if ( `CDmeMDLPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeMDLPanel");
    v4->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeMDLPanel");
    v5->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CMDLPanel");
  }
  if ( `CDmeMDLPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeMDLPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeMDLPanel");
    v6->pfnClassName = CDmeMDLPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPanel");
  }
  return this;
}

} // namespace sceneviewer
