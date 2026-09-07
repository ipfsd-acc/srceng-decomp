// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/location_editor/mission_txt_leaf_panel.cpp
// Functions: 11
// ============================================================

#include "missionchooser\vgui\location_editor\mission_txt_leaf_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10011A70
// Name: public: static char const __near * CMission_Txt_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMission_Txt_Panel::GetPanelClassName()
{
  return "CMission_Txt_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10011A80
// Name: public: void CMission_Txt_Panel::DoPick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMission_Txt_Panel::DoPick(CMission_Txt_Panel *this)
{
  vgui::FileOpenDialog *v2; // eax
  vgui::FileOpenDialog *v3; // esi
  char template_dir[1024]; // [esp+Ch] [ebp-400h] BYREF

  v2 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v2 != nullptr )
    v3 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Pick Room Template",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v3 = nullptr;
  V_snprintf(pDest: template_dir, maxLen: 1024, pFormat: "%s\\tilegen\\missions", g_gamedir);
  _Msg(a1: "DoPick(): missions dir is %s\n", template_dir);
  _Msg(a1: "  g_gamedir is %s\n", g_gamedir);
  vgui::FileOpenDialog::SetStartDirectory(this: v3, dir: template_dir);
  vgui::FileOpenDialog::AddFilter(
    this: v3,
    filter: "*.txt",
    filterName: "Mission txt (*.txt)",
    bActive: true,
    pFilterInfo: nullptr);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  vgui::FileOpenDialog::DoModal(this: v3, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x10011B40
// Name: public: virtual struct vgui::PanelMap_t __near * CMission_Txt_Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CMission_Txt_Panel::GetPanelMap(CMission_Txt_Panel *this)
{
  return &CMission_Txt_Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x10011B50
// Name: public: void CMission_Txt_Panel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMission_Txt_Panel::OnFileSelected(CMission_Txt_Panel *this, const char *fullpath)
{
  char buffer[260]; // [esp+8h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePath(this: g_pFullFileSystem, a2: fullpath, a3: buffer, a4: 260) )
  {
    V_FixSlashes(pname: buffer, separator: 92);
    this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: buffer);
    this->TextEntryChanged(this, a2: this->m_pTextEntry);
  }
  else
  {
    _Warning(a1: "Failed to convert this to a relative path: %s\n", fullpath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011BE0
// Name: public: virtual void CMission_Txt_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMission_Txt_Panel::PerformLayout(CMission_Txt_Panel *this)
{
  int v2; // eax

  CKV_Leaf_Panel::PerformLayout((CKV_Combo_Leaf_Panel *)this);
  if ( vgui::Panel::GetWide(this: this->m_pLabel) + 5 <= 100 )
    v2 = 100;
  else
    v2 = vgui::Panel::GetWide(this: this->m_pLabel) + 5;
  vgui::Panel::SetBounds(this: this->m_pTextEntry, x: v2, y: 0, wide: 365 - v2, tall: 20);
  vgui::Panel::SetSize(this, wide: 420, tall: 20);
  vgui::Panel::SetBounds(this: this->m_pPickButton, x: 367, y: 0, wide: 25, tall: 20);
}

//------------------------------------------------------------------------------
// Address: 0x10011C50
// Name: public: virtual void CMission_Txt_Panel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMission_Txt_Panel::OnCommand(CMission_Txt_Panel *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Pick") == 0 )
    CMission_Txt_Panel::DoPick(this);
  CKV_Leaf_Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10011C90
// Name: public: CMission_Txt_Panel::CMission_Txt_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMission_Txt_Panel *__thiscall CMission_Txt_Panel::CMission_Txt_Panel(
        CMission_Txt_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax

  CKV_Leaf_Panel::CKV_Leaf_Panel(this, parent, name);
  this->__vftable = (CMission_Txt_Panel_vtbl *)&CMission_Txt_Panel::`vftable';
  if ( `CMission_Txt_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CMission_Txt_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMission_Txt_Panel");
    v4->pfnClassName = CMission_Txt_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Leaf_Panel");
  }
  if ( `CMission_Txt_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMission_Txt_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMission_Txt_Panel");
    v5->pfnClassName = CMission_Txt_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Leaf_Panel");
  }
  if ( `CMission_Txt_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMission_Txt_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMission_Txt_Panel");
    v6->pfnClassName = CMission_Txt_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Leaf_Panel");
  }
  v7 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pPickButton = vgui::Button::Button(
                            this: v7,
                            parent: this,
                            panelName: "PickButton",
                            text: "...",
                            pActionSignalTarget: this,
                            pCmd: "Pick");
  else
    this->m_pPickButton = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011D90
// Name: public: virtual struct vgui::PanelMessageMap __near * CMission_Txt_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMission_Txt_Panel::GetMessageMap(CMission_Txt_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMission_Txt_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMission_Txt_Panel::GetMessageMap'::`2'::s_pMap;
  `CMission_Txt_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMission_Txt_Panel");
  `CMission_Txt_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011DC0
// Name: public: virtual struct PanelAnimationMap __near * CMission_Txt_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMission_Txt_Panel::GetAnimMap(CMission_Txt_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMission_Txt_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x10011DD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMission_Txt_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMission_Txt_Panel::GetKBMap(CMission_Txt_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMission_Txt_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMission_Txt_Panel::GetKBMap'::`2'::s_pMap;
  `CMission_Txt_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMission_Txt_Panel");
  `CMission_Txt_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011E00
// Name: Create_CMission_Txt_Panel
// Source: json
//------------------------------------------------------------------------------
CMission_Txt_Panel *__cdecl Create_CMission_Txt_Panel()
{
  CMission_Txt_Panel *v0; // eax

  v0 = (CMission_Txt_Panel *)operator new(nSize: 0x1B0u);
  if ( v0 != nullptr )
    return CMission_Txt_Panel::CMission_Txt_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}
