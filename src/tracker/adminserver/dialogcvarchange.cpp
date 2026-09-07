// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/dialogcvarchange.cpp
// Functions: 3
// ============================================================

#include "tracker\adminserver\dialogcvarchange.h"

//------------------------------------------------------------------------------
// Address: 0x10008620
// Name: public: CDialogCvarChange::CDialogCvarChange(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogCvarChange *__thiscall CDialogCvarChange::CDialogCvarChange(CDialogCvarChange *this, vgui::Panel *parent)
{
  vgui::Label *v3; // eax
  vgui::Label *v4; // eax
  vgui::Label *v5; // eax
  vgui::Label *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax

  vgui::Frame::Frame(this, parent, panelName: "DialogCvarChange", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDialogCvarChange_vtbl *)&CDialogCvarChange::`vftable';
  vgui::Panel::SetSize(this, wide: 320, tall: 200);
  this->m_bAddCvarText = true;
  v3 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v3 != nullptr )
    v4 = vgui::Label::Label(this: v3, parent: this, panelName: "InfoLabel", text: defaultValue);
  else
    v4 = nullptr;
  this->m_pInfoLabel = v4;
  v5 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v5 != nullptr )
    v6 = vgui::Label::Label(this: v5, parent: this, panelName: "CvarLabel", text: defaultValue);
  else
    v6 = nullptr;
  this->m_pCvarLabel = v6;
  v7 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "CvarEntry");
  else
    v8 = nullptr;
  this->m_pCvarEntry = v8;
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkayButton",
            text: "#Okay_Button",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pOkayButton = v10;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Admin/DialogCvarChange.res",
    pathID: "PLATFORM",
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetTitle(this, title: "#Cvar_Title", surfaceTitle: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008750
// Name: public: void CDialogCvarChange::Activate(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogCvarChange::Activate(
        CDialogCvarChange *this,
        const char *cvarName,
        const char *curValue,
        const char *type,
        const char *question)
{
  vgui::Button *m_pOkayButton; // ecx
  vgui::IInput *v7; // edi
  vgui::IInput_vtbl *v8; // ebx
  int v9; // eax

  this->m_pCvarLabel->SetText(this: this->m_pCvarLabel, a2: cvarName);
  if ( !this->m_bAddCvarText )
    this->m_pCvarLabel->SetVisible(this: this->m_pCvarLabel, a2: false);
  this->m_pInfoLabel->SetText(this: this->m_pInfoLabel, a2: question);
  m_pOkayButton = this->m_pOkayButton;
  this->m_cType = type;
  m_pOkayButton->SetAsDefaultButton(this: m_pOkayButton, a2: 1);
  vgui::Panel::MakePopup(this, showTaskbarIcon: true, disabled: false);
  this->MoveToFront(this);
  this->m_pCvarEntry->SetText(this: this->m_pCvarEntry, a2: curValue);
  this->m_pCvarEntry->RequestFocus(this: this->m_pCvarEntry, a2: 0);
  this->RequestFocus(this, a2: 0);
  v7 = g_pVGuiInput;
  v8 = g_pVGuiInput->__vftable;
  v9 = this->GetVPanel(this);
  v8->SetAppModalSurface(this: v7, a2: v9);
  this->SetVisible(this, a2: true);
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008830
// Name: private: virtual void CDialogCvarChange::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogCvarChange::OnCommand(CDialogCvarChange *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  char buf[64]; // [esp+8h] [ebp-40h] BYREF

  if ( _V_stricmp(s1: command, s2: "Okay") == 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CvarChangeValue");
    else
      v4 = nullptr;
    this->m_pCvarLabel->GetText(this: this->m_pCvarLabel, a2: buf, a3: 64);
    KeyValues::SetString(this: v4, keyName: "player", value: buf);
    this->m_pCvarEntry->GetText_2(this: this->m_pCvarEntry, a2: buf, a3: 63);
    KeyValues::SetString(this: v4, keyName: "value", value: buf);
    KeyValues::SetString(this: v4, keyName: "type", value: this->m_cType);
    this->PostActionSignal(this, a2: v4);
    goto LABEL_6;
  }
  if ( _V_stricmp(s1: command, s2: "Close") == 0 )
  {
LABEL_6:
    this->Close(this);
    return;
  }
  vgui::Frame::OnCommand(this, command);
}
