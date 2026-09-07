// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/new_panel_dialog.cpp
// Functions: 7
// ============================================================

#include "utils\vgui_editor\vgui\new_panel_dialog.h"

//------------------------------------------------------------------------------
// Address: 0x0040AE20
// Name: public: static char const __near * CNew_Panel_Dialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNew_Panel_Dialog::GetPanelClassName()
{
  return "CNew_Panel_Dialog";
}

//------------------------------------------------------------------------------
// Address: 0x0040AE30
// Name: public: virtual void CNew_Panel_Dialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Panel_Dialog::ApplySchemeSettings(CNew_Panel_Dialog *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/UI/vgui_editor/NewPanelDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  this->m_pNameBox->RequestFocus(this: this->m_pNameBox, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE70
// Name: public: virtual void CNew_Panel_Dialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Panel_Dialog::OnCommand(CNew_Panel_Dialog *this, const char *command)
{
  CVGUI_Src_Editor *v3; // eax
  char szName[128]; // [esp+8h] [ebp-100h] BYREF
  char szParentClass[128]; // [esp+88h] [ebp-80h] BYREF

  if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Create") == 0 )
    {
      this->m_pNameBox->GetText_2(this: this->m_pNameBox, a2: szName, a3: 128);
      this->m_pParentClassBox->GetText_2(this: this->m_pParentClassBox, a2: szParentClass, a3: 128);
      v3 = VGUI_Src_Editor();
      CVGUI_Src_Editor::CreateNewManagedPanel(this: v3, szName, szParentClass);
      this->MarkForDeletion(this);
    }
  }
  else
  {
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B000
// Name: public: virtual struct vgui::PanelMessageMap __near * CNew_Panel_Dialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNew_Panel_Dialog::GetMessageMap(CNew_Panel_Dialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNew_Panel_Dialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNew_Panel_Dialog::GetMessageMap'::`2'::s_pMap;
  `CNew_Panel_Dialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNew_Panel_Dialog");
  `CNew_Panel_Dialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B030
// Name: public: virtual struct PanelAnimationMap __near * CNew_Panel_Dialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNew_Panel_Dialog::GetAnimMap(CNew_Panel_Dialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CNew_Panel_Dialog");
}

//------------------------------------------------------------------------------
// Address: 0x0040B040
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNew_Panel_Dialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNew_Panel_Dialog::GetKBMap(CNew_Panel_Dialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNew_Panel_Dialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNew_Panel_Dialog::GetKBMap'::`2'::s_pMap;
  `CNew_Panel_Dialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNew_Panel_Dialog");
  `CNew_Panel_Dialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B070
// Name: public: CNew_Panel_Dialog::CNew_Panel_Dialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNew_Panel_Dialog *__thiscall CNew_Panel_Dialog::CNew_Panel_Dialog(
        CNew_Panel_Dialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::ComboBox *v11; // eax
  vgui::ComboBox *v12; // eax
  vgui::ComboBox *v13; // eax
  vgui::ComboBox *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CNew_Panel_Dialog_vtbl *)&CNew_Panel_Dialog::`vftable';
  if ( `CNew_Panel_Dialog::ChainToMap'::`2'::chained == 0 )
  {
    `CNew_Panel_Dialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNew_Panel_Dialog");
    v4->pfnClassName = CNew_Panel_Dialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNew_Panel_Dialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNew_Panel_Dialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNew_Panel_Dialog");
    v5->pfnClassName = CNew_Panel_Dialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNew_Panel_Dialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNew_Panel_Dialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNew_Panel_Dialog");
    v6->pfnClassName = CNew_Panel_Dialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "NameLabel", text: "Name:");
  else
    v8 = nullptr;
  this->m_pNameLabel = v8;
  v9 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "ParentClassLabel", text: "Parent Class:");
  else
    v10 = nullptr;
  this->m_pParentClassLabel = v10;
  v11 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v11 != nullptr )
    v12 = vgui::ComboBox::ComboBox(this: v11, parent: this, panelName: "NameBox", numLines: 0, allowEdit: true);
  else
    v12 = nullptr;
  this->m_pNameBox = v12;
  v13 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v13 != nullptr )
    v14 = vgui::ComboBox::ComboBox(this: v13, parent: this, panelName: "ParentClassBox", numLines: 0, allowEdit: true);
  else
    v14 = nullptr;
  this->m_pParentClassBox = v14;
  v14->AddItem_2(this: v14, a2: "vgui::EditablePanel", a3: nullptr);
  this->m_pParentClassBox->AddItem_2(this: this->m_pParentClassBox, a2: "vgui::Frame", a3: nullptr);
  this->m_pParentClassBox->SetText(this: this->m_pParentClassBox, a2: "vgui::EditablePanel");
  v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "CreateButton",
            text: "Create",
            pActionSignalTarget: this,
            pCmd: "Create");
  else
    v16 = nullptr;
  this->m_pCreateButton = v16;
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "CancelButton",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v18 = nullptr;
  this->m_pCancelButton = v18;
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}
