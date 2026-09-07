// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/dialogserverpassword.cpp
// Functions: 8
// ============================================================

#include "serverbrowser\dialogserverpassword.h"

//------------------------------------------------------------------------------
// Address: 0x10011920
// Name: public: CDialogServerPassword::CDialogServerPassword(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogServerPassword *__thiscall CDialogServerPassword::CDialogServerPassword(
        CDialogServerPassword *this,
        vgui::Panel *parent)
{
  vgui::Label *v3; // eax
  vgui::Label *v4; // eax
  vgui::Label *v5; // eax
  vgui::Label *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *m_pPasswordEntry; // ecx

  vgui::Frame::Frame(this, parent, panelName: "DialogServerPassword", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDialogServerPassword_vtbl *)&CDialogServerPassword::`vftable';
  this->m_iServerID = -1;
  vgui::Panel::SetSize(this, wide: 320, tall: 240);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  v3 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v3 != nullptr )
    v4 = vgui::Label::Label(
           this: v3,
           parent: this,
           panelName: "InfoLabel",
           text: "#ServerBrowser_ServerRequiresPassword");
  else
    v4 = nullptr;
  this->m_pInfoLabel = v4;
  v5 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v5 != nullptr )
    v6 = vgui::Label::Label(this: v5, parent: this, panelName: "GameLabel", text: "<game label>");
  else
    v6 = nullptr;
  this->m_pGameLabel = v6;
  v7 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "PasswordEntry");
  else
    v8 = nullptr;
  this->m_pPasswordEntry = v8;
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "ConnectButton",
            text: "#ServerBrowser_Connect",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  m_pPasswordEntry = this->m_pPasswordEntry;
  this->m_pConnectButton = v10;
  m_pPasswordEntry->SetTextHidden(this: m_pPasswordEntry, a2: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Servers/DialogServerPassword.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetTitle(this, title: "#ServerBrowser_ServerRequiresPasswordTitle", surfaceTitle: true);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011A60
// Name: public: static char const __near * vgui::Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Frame::GetPanelClassName()
{
  return "Frame";
}

//------------------------------------------------------------------------------
// Address: 0x10011A70
// Name: public: void CDialogServerPassword::Activate(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogServerPassword::Activate(
        CDialogServerPassword *this,
        const char *serverName,
        unsigned int serverID)
{
  this->m_pGameLabel->SetText_2(this: this->m_pGameLabel, a2: serverName);
  this->m_iServerID = serverID;
  this->m_pConnectButton->SetAsDefaultButton(this: this->m_pConnectButton, a2: 1);
  this->m_pPasswordEntry->RequestFocus(this: this->m_pPasswordEntry, a2: 0);
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011AC0
// Name: private: virtual void CDialogServerPassword::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogServerPassword::OnCommand(CDialogServerPassword *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char buf[64]; // [esp+18h] [ebp-40h] BYREF

  if ( _V_stricmp(s1: command, s2: "Connect") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Close") != 0 )
    {
      vgui::Frame::OnCommand(this, command);
      return;
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "JoinServerWithPassword");
    else
      v4 = nullptr;
    this->m_pPasswordEntry->GetText_2(this: this->m_pPasswordEntry, a2: buf, a3: 63);
    KeyValues::SetString(this: v4, keyName: "password", value: buf);
    KeyValues::SetInt(this: v4, keyName: "serverID", value: this->m_iServerID);
    this->PostActionSignal(this, a2: v4);
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "Close");
  else
    v6 = nullptr;
  ((void (__thiscall *)(CDialogServerPassword *, CDialogServerPassword *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v6,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10011BB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011BE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x10011BF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050120
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}
