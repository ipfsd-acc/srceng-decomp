// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/new_child_dialog.cpp
// Functions: 10
// ============================================================

#include "utils\vgui_editor\vgui\new_child_dialog.h"

//------------------------------------------------------------------------------
// Address: 0x0040AA30
// Name: public: static char const __near * CNew_Child_Dialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNew_Child_Dialog::GetPanelClassName()
{
  return "CNew_Child_Dialog";
}

//------------------------------------------------------------------------------
// Address: 0x0040AA40
// Name: public: virtual void CNew_Child_Dialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Child_Dialog::ApplySchemeSettings(CNew_Child_Dialog *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/UI/vgui_editor/NewChildDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  this->m_pNameBox->RequestFocus(this: this->m_pNameBox, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040AA80
// Name: public: virtual void CNew_Child_Dialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Child_Dialog::OnCommand(CNew_Child_Dialog *this, const char *command)
{
  char szName[128]; // [esp+8h] [ebp-100h] BYREF
  char szPanelClass[128]; // [esp+88h] [ebp-80h] BYREF

  if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Create") == 0 )
    {
      this->m_pNameBox->GetText_2(this: this->m_pNameBox, a2: szName, a3: 128);
      this->m_pPanelClassBox->GetText_2(this: this->m_pPanelClassBox, a2: szPanelClass, a3: 128);
      CManaged_Panel_Data::CreateNewManagedChild(this: this->m_pManagedPanel, szName, szPanelClass);
      this->MarkForDeletion(this);
    }
  }
  else
  {
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AB30
// Name: public: void CNew_Child_Dialog::SetManagedPanel(class CManaged_Panel_Data __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Child_Dialog::SetManagedPanel(CNew_Child_Dialog *this, CManaged_Panel_Data *pManagedPanelData)
{
  char buffer[128]; // [esp+4h] [ebp-80h] BYREF

  this->m_pManagedPanel = pManagedPanelData;
  V_snprintf(pDest: buffer, maxLen: 128, pFormat: "New child for %s\n", pManagedPanelData->m_szName);
  this->SetTitle_2(this, a2: buffer, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0040AB80
// Name: public: virtual struct vgui::PanelMessageMap __near * CNew_Child_Dialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNew_Child_Dialog::GetMessageMap(CNew_Child_Dialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNew_Child_Dialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNew_Child_Dialog::GetMessageMap'::`2'::s_pMap;
  `CNew_Child_Dialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNew_Child_Dialog");
  `CNew_Child_Dialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040ABB0
// Name: public: virtual struct PanelAnimationMap __near * CNew_Child_Dialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNew_Child_Dialog::GetAnimMap(CNew_Child_Dialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CNew_Child_Dialog");
}

//------------------------------------------------------------------------------
// Address: 0x0040ABC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNew_Child_Dialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNew_Child_Dialog::GetKBMap(CNew_Child_Dialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNew_Child_Dialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNew_Child_Dialog::GetKBMap'::`2'::s_pMap;
  `CNew_Child_Dialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNew_Child_Dialog");
  `CNew_Child_Dialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040ABF0
// Name: public: CNew_Child_Dialog::CNew_Child_Dialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNew_Child_Dialog *__thiscall CNew_Child_Dialog::CNew_Child_Dialog(
        CNew_Child_Dialog *this,
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
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CNew_Child_Dialog_vtbl *)&CNew_Child_Dialog::`vftable';
  if ( `CNew_Child_Dialog::ChainToMap'::`2'::chained == 0 )
  {
    `CNew_Child_Dialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNew_Child_Dialog");
    v4->pfnClassName = CNew_Child_Dialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNew_Child_Dialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNew_Child_Dialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNew_Child_Dialog");
    v5->pfnClassName = CNew_Child_Dialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNew_Child_Dialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNew_Child_Dialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNew_Child_Dialog");
    v6->pfnClassName = CNew_Child_Dialog::GetPanelClassName;
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
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "PanelClassLabel", text: "Child Class:");
  else
    v10 = nullptr;
  this->m_pPanelClassLabel = v10;
  v11 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "NameBox");
  else
    v12 = nullptr;
  this->m_pNameBox = v12;
  v13 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v13 != nullptr )
    v14 = vgui::TextEntry::TextEntry(this: v13, parent: this, panelName: "PanelClassBox");
  else
    v14 = nullptr;
  this->m_pPanelClassBox = v14;
  v14->SetText(this: v14, a2: "vgui::Label");
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
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040AF20
// Name: public: virtual void CNew_Child_Dialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Child_Dialog::OnClose(CNew_Child_Dialog *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040AF40
// Name: public: virtual void CNew_Child_Dialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNew_Child_Dialog::PerformLayout(CNew_Child_Dialog *this)
{
  vgui::Panel *v2; // eax
  int Wide; // eax
  int v4; // [esp-4h] [ebp-18h]
  float v5; // [esp+4h] [ebp-10h]
  float v6; // [esp+8h] [ebp-Ch]
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  v2 = this->GetParent(this);
  vgui::Panel::GetSize(this: v2, wide: &w, tall: &h);
  v6 = (float)h * 0.5;
  v5 = (float)w * 0.5;
  v4 = (int)(float)(v6 - (float)((float)vgui::Panel::GetTall(this) * 0.5));
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetPos(this, x: (int)(float)(v5 - (float)((float)Wide * 0.5)), y: v4);
}
