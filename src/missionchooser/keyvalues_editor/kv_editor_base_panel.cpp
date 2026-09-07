// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_editor_base_panel.cpp
// Functions: 9
// ============================================================

#include "missionchooser\keyvalues_editor\kv_editor_base_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1000DD10
// Name: public: static char const __near * CKV_Editor_Base_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Editor_Base_Panel::GetPanelClassName()
{
  return "CKV_Editor_Base_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: public: virtual void CKV_Editor_Base_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CKV_Editor_Base_Panel::PerformLayout(CKV_Editor_Base_Panel *this)
{
  vgui::EditablePanel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD30
// Name: public: void CKV_Editor_Base_Panel::SetKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetKey(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  if ( pKey != this->m_pKey )
  {
    this->m_pKey = pKey;
    this->UpdatePanel(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DD60
// Name: public: void CKV_Editor_Base_Panel::SetKeyParent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetKeyParent(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  if ( pKey != this->m_pKeyParent )
    this->m_pKeyParent = pKey;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD80
// Name: public: void CKV_Editor_Base_Panel::SetFileSpecNode(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetFileSpecNode(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  CKV_Editor_Base_Panel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pFileSpecNode = pKey;
  ((void (__stdcall *)(KeyValues *))v2->ApplySettings)(a1: pKey);
}

//------------------------------------------------------------------------------
// Address: 0x1000DDA0
// Name: public: CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor_Base_Panel *__thiscall CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(
        CKV_Editor_Base_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CKV_Editor_Base_Panel_vtbl *)&CKV_Editor_Base_Panel::`vftable';
  if ( `CKV_Editor_Base_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
    v4->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor_Base_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
    v5->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor_Base_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
    v6->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pKey = nullptr;
  this->m_pKeyParent = nullptr;
  this->m_pFileSpecNode = nullptr;
  this->m_pEditor = nullptr;
  this->m_bAllowDeletion = true;
  this->m_flSortOrder = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE90
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Editor_Base_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Editor_Base_Panel::GetMessageMap(CKV_Editor_Base_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Editor_Base_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Base_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Editor_Base_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  `CKV_Editor_Base_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DEC0
// Name: public: virtual struct PanelAnimationMap __near * CKV_Editor_Base_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Editor_Base_Panel::GetAnimMap(CKV_Editor_Base_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x1000DED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Editor_Base_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Editor_Base_Panel::GetKBMap(CKV_Editor_Base_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Editor_Base_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Base_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Editor_Base_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  `CKV_Editor_Base_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00407BA0
// Name: public: static char const __near * CKV_Editor_Base_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Editor_Base_Panel::GetPanelClassName()
{
  return "CKV_Editor_Base_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x00407BB0
// Name: public: virtual void CKV_Editor_Base_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CKV_Editor_Base_Panel::PerformLayout(CKV_Editor_Base_Panel *this)
{
  vgui::EditablePanel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407BC0
// Name: public: void CKV_Editor_Base_Panel::SetKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetKey(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  if ( pKey != this->m_pKey )
  {
    this->m_pKey = pKey;
    this->UpdatePanel(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407BF0
// Name: public: void CKV_Editor_Base_Panel::SetKeyParent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetKeyParent(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  if ( pKey != this->m_pKeyParent )
    this->m_pKeyParent = pKey;
}

//------------------------------------------------------------------------------
// Address: 0x00407C10
// Name: public: void CKV_Editor_Base_Panel::SetFileSpecNode(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Editor_Base_Panel::SetFileSpecNode(CKV_Editor_Base_Panel *this, KeyValues *pKey)
{
  CKV_Editor_Base_Panel_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_pFileSpecNode = pKey;
  ((void (__stdcall *)(KeyValues *))v2->ApplySettings)(a1: pKey);
}

//------------------------------------------------------------------------------
// Address: 0x00407C30
// Name: public: CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Editor_Base_Panel *__thiscall CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(
        CKV_Editor_Base_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CKV_Editor_Base_Panel_vtbl *)&CKV_Editor_Base_Panel::`vftable';
  if ( `CKV_Editor_Base_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
    v4->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor_Base_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
    v5->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CKV_Editor_Base_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Editor_Base_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
    v6->pfnClassName = CKV_Editor_Base_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_pKey = nullptr;
  this->m_pKeyParent = nullptr;
  this->m_pFileSpecNode = nullptr;
  this->m_pEditor = nullptr;
  this->m_bAllowDeletion = true;
  this->m_flSortOrder = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407D20
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Editor_Base_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Editor_Base_Panel::GetMessageMap(CKV_Editor_Base_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Editor_Base_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Base_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Editor_Base_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  `CKV_Editor_Base_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407D50
// Name: public: virtual struct PanelAnimationMap __near * CKV_Editor_Base_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Editor_Base_Panel::GetAnimMap(CKV_Editor_Base_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x00407D60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Editor_Base_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Editor_Base_Panel::GetKBMap(CKV_Editor_Base_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Editor_Base_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Editor_Base_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Editor_Base_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  `CKV_Editor_Base_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_editor
