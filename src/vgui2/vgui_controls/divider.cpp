// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/divider.cpp
// Functions: 7
// ============================================================

#include "vgui2\vgui_controls\divider.h"

//------------------------------------------------------------------------------
// Address: 0x102C7A60
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x102C7A70
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x102C7AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7AE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x102C7AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7B20
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C7C20
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1004F470
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x1004F480
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1004F4C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F4F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x1004F500
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004F530
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F630
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00429D30
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x00429D40
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x00429D80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429DB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x00429DC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429DF0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429EF0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1005A1B0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x1005A1C0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1005A200
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A230
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x1005A240
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005A270
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005A370
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00606940
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x00606950
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x00606990
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006069C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x006069D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00606A00
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00606B00
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C7B30
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x102C7B40
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x102C7B80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7BB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x102C7BC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C7BF0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, __m128i *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C7CF0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102ED6D0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x102ED6E0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x102ED720
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED750
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x102ED760
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ED790
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102ED890
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BBE20
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x100BBE30
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x100BBE70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBEA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x100BBEB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BBEE0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BBFE0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0044A2C0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x0044A2D0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x0044A310
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A340
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x0044A350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A380
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044A480
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00431830
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x00431840
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x00431880
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004318B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x004318C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004318F0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004319F0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063DFC0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x0063DFD0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x0063E010
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063E040
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x0063E050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063E080
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063E180
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10062AE0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x10062AF0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x10062B30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062B60
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x10062B70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062BA0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062CA0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100685D0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x100685E0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x10068620
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068650
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x10068660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068690
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068790
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x0043A040
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x0043A050
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x0043A090
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A0C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x0043A0D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A100
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A200
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004837A0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x004837B0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x004837F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483820
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x00483830
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483860
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483960
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00428930
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x00428940
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x00428980
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004289B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x004289C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004289F0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428AF0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042C370
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x0042C380
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x0042C3C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C3F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x0042C400
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042C430
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042C530
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A20D0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x103A20E0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x103A2120
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A2150
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x103A2160
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A2190
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103A2290
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1039A4E0
// Name: public: static char const __near * vgui::Divider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Divider::GetPanelClassName()
{
  return "Divider";
}

//------------------------------------------------------------------------------
// Address: 0x1039A4F0
// Name: public: virtual void vgui::Divider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Divider::ApplySchemeSettings(vgui::Divider *this, vgui::IScheme *pScheme)
{
  vgui::Divider_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ButtonDepressedBorder");
  v3->SetBorder(this, a2: v4);
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1039A530
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Divider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Divider::GetMessageMap(vgui::Divider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Divider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetMessageMap'::`2'::s_pMap;
  `vgui::Divider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Divider");
  `vgui::Divider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A560
// Name: public: virtual struct PanelAnimationMap __near * vgui::Divider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Divider::GetAnimMap(vgui::Divider *this)
{
  return FindOrAddPanelAnimationMap(className: "Divider");
}

//------------------------------------------------------------------------------
// Address: 0x1039A570
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Divider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Divider::GetKBMap(vgui::Divider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Divider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Divider::GetKBMap'::`2'::s_pMap;
  `vgui::Divider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
  `vgui::Divider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039A5A0
// Name: public: vgui::Divider::Divider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__thiscall vgui::Divider::Divider(vgui::Divider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (vgui::Divider_vtbl *)&vgui::Divider::`vftable';
  if ( `vgui::Divider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Divider");
    v4->pfnClassName = vgui::Divider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Divider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Divider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Divider");
    v5->pfnClassName = vgui::Divider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Divider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Divider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Divider");
    v6->pfnClassName = vgui::Divider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::Panel::SetSize(this, wide: 128, tall: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039A6A0
// Name: Create_Divider
// Source: json
//------------------------------------------------------------------------------
vgui::Divider *__cdecl Create_Divider()
{
  vgui::Divider *v0; // eax

  v0 = (vgui::Divider *)operator new(nSize: 0x150u);
  if ( v0 != nullptr )
    return vgui::Divider::Divider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace server
