// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/querybox.cpp
// Functions: 10
// ============================================================

#include "vgui2\vgui_controls\querybox.h"

//------------------------------------------------------------------------------
// Address: 0x1003DEA0
// Name: public: static char const __near * vgui::QueryBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::QueryBox::GetPanelClassName()
{
  return "QueryBox";
}

//------------------------------------------------------------------------------
// Address: 0x1003DEB0
// Name: public: virtual void vgui::QueryBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::PerformLayout(vgui::QueryBox *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-30h]
  int boxWidth; // [esp+4h] [ebp-28h] BYREF
  int boxTall; // [esp+8h] [ebp-24h] BYREF
  int oldTall; // [esp+Ch] [ebp-20h] BYREF
  int oldWide; // [esp+10h] [ebp-1Ch] BYREF
  int y; // [esp+14h] [ebp-18h] BYREF
  int x; // [esp+18h] [ebp-14h] BYREF
  int btnTall; // [esp+1Ch] [ebp-10h] BYREF
  int btnWide; // [esp+20h] [ebp-Ch] BYREF
  int wide; // [esp+24h] [ebp-8h] BYREF
  int tall; // [esp+28h] [ebp-4h] BYREF

  vgui::MessageBox::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
  this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v2, tall: v3);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v4 = vgui::Panel::GetTall(this: this->m_pOkButton);
  v7 = tall - v4 - 15;
  v5 = vgui::Panel::GetWide(this: this->m_pOkButton);
  vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 2 - v5 - 1, y: v7);
  v6 = vgui::Panel::GetTall(this: this->m_pCancelButton);
  vgui::Panel::SetPos(this: this->m_pCancelButton, x: wide / 2 + x + 16, y: tall - v6 - 15);
}

//------------------------------------------------------------------------------
// Address: 0x1003DFD0
// Name: protected: virtual void vgui::QueryBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnCommand(vgui::QueryBox *this, const char *command)
{
  KeyValues *m_pOkCommand; // ecx
  vgui::QueryBox_vtbl *v4; // edi
  KeyValues *v5; // eax
  KeyValues *m_pCancelCommand; // ecx
  vgui::QueryBox_vtbl *v7; // edi
  KeyValues *Copy; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") == 0 )
    {
      this->OnCommand(this, a2: "Close");
      m_pCancelCommand = this->m_pCancelCommand;
      if ( m_pCancelCommand != nullptr )
      {
        v7 = this->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pCancelCommand);
        v7->PostActionSignal(this, a2: Copy);
      }
    }
  }
  else
  {
    this->OnCommand(this, a2: "Close");
    m_pOkCommand = this->m_pOkCommand;
    if ( m_pOkCommand != nullptr )
    {
      v4 = this->__vftable;
      v5 = KeyValues::MakeCopy(this: m_pOkCommand);
      v4->PostActionSignal(this, a2: v5);
      vgui::MessageBox::OnCommand(this, pCommand: command);
      return;
    }
  }
  vgui::MessageBox::OnCommand(this, pCommand: command);
}

//------------------------------------------------------------------------------
// Address: 0x1003E080
// Name: public: void vgui::QueryBox::SetOKCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetOKCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pOkCommand; // ecx

  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  this->m_pOkCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x1003E0C0
// Name: protected: virtual void vgui::QueryBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnKeyCodeTyped(vgui::QueryBox *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->OnCommand(this, a2: "Cancel");
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1003E0F0
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
// Address: 0x1003E120
// Name: public: virtual struct PanelAnimationMap __near * vgui::QueryBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::QueryBox::GetAnimMap(vgui::QueryBox *this)
{
  return FindOrAddPanelAnimationMap(className: "QueryBox");
}

//------------------------------------------------------------------------------
// Address: 0x1003E130
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

//------------------------------------------------------------------------------
// Address: 0x1003E160
// Name: public: vgui::QueryBox::QueryBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::QueryBox *__thiscall vgui::QueryBox::QueryBox(
        vgui::QueryBox *this,
        const char *title,
        const char *queryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *m_pOkButton; // ecx

  vgui::MessageBox::MessageBox(this, title, text: queryText, parent);
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( `vgui::QueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
    v5->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "QueryBox");
    v6->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
    v7->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#QueryBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  v9->SetCommand(this: v9, a2: "Cancel");
  this->m_pOkButton->SetCommand(this: this->m_pOkButton, a2: "OK");
  m_pOkButton = this->m_pOkButton;
  this->m_pCancelCommand = nullptr;
  this->m_pOkCommand = nullptr;
  m_pOkButton->SetTabPosition(this: m_pOkButton, a2: 1);
  this->m_pCancelButton->SetTabPosition(this: this->m_pCancelButton, a2: 2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003E320
// Name: public: vgui::QueryBox::QueryBox(wchar_t const __near *,wchar_t const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::QueryBox *__thiscall vgui::QueryBox::QueryBox(
        vgui::QueryBox *this,
        const wchar_t *wszTitle,
        const wchar_t *wszQueryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *m_pOkButton; // ecx

  vgui::MessageBox::MessageBox(this, wszTitle, wszText: wszQueryText, parent);
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( `vgui::QueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
    v5->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "QueryBox");
    v6->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
    v7->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#QueryBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  v9->SetCommand(this: v9, a2: "Cancel");
  this->m_pOkButton->SetCommand(this: this->m_pOkButton, a2: "OK");
  m_pOkButton = this->m_pOkButton;
  this->m_pCancelCommand = nullptr;
  this->m_pOkCommand = nullptr;
  m_pOkButton->SetTabPosition(this: m_pOkButton, a2: 1);
  this->m_pCancelButton->SetTabPosition(this: this->m_pCancelButton, a2: 2);
  return this;
}

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10057860
// Name: public: static char const __near * vgui::QueryBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::QueryBox::GetPanelClassName()
{
  return "QueryBox";
}

//------------------------------------------------------------------------------
// Address: 0x10057870
// Name: public: virtual vgui::QueryBox::~QueryBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::~QueryBox(vgui::QueryBox *this)
{
  vgui::Button *m_pCancelButton; // ecx
  KeyValues *m_pOkCommand; // ecx
  KeyValues *m_pCancelCommand; // ecx

  m_pCancelButton = this->m_pCancelButton;
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( m_pCancelButton != nullptr )
    ((void (__thiscall *)(vgui::Button *, int))m_pCancelButton->dtr_Panel)(a1: m_pCancelButton, a2: 1);
  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  m_pCancelCommand = this->m_pCancelCommand;
  if ( m_pCancelCommand != nullptr )
    KeyValues::deleteThis(this: m_pCancelCommand);
  vgui::MessageBox::~MessageBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x100578C0
// Name: public: virtual void vgui::QueryBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::PerformLayout(vgui::QueryBox *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-30h]
  int boxWidth; // [esp+4h] [ebp-28h] BYREF
  int boxTall; // [esp+8h] [ebp-24h] BYREF
  int oldTall; // [esp+Ch] [ebp-20h] BYREF
  int oldWide; // [esp+10h] [ebp-1Ch] BYREF
  int y; // [esp+14h] [ebp-18h] BYREF
  int x; // [esp+18h] [ebp-14h] BYREF
  int btnTall; // [esp+1Ch] [ebp-10h] BYREF
  int btnWide; // [esp+20h] [ebp-Ch] BYREF
  int wide; // [esp+24h] [ebp-8h] BYREF
  int tall; // [esp+28h] [ebp-4h] BYREF

  vgui::MessageBox::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
  this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v2, tall: v3);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v4 = vgui::Panel::GetTall(this: this->m_pOkButton);
  v7 = tall - v4 - 15;
  v5 = vgui::Panel::GetWide(this: this->m_pOkButton);
  vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 2 - v5 - 1, y: v7);
  v6 = vgui::Panel::GetTall(this: this->m_pCancelButton);
  vgui::Panel::SetPos(this: this->m_pCancelButton, x: wide / 2 + x + 16, y: tall - v6 - 15);
}

//------------------------------------------------------------------------------
// Address: 0x100579E0
// Name: protected: virtual void vgui::QueryBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnCommand(vgui::QueryBox *this, const char *command)
{
  KeyValues *m_pOkCommand; // ecx
  vgui::QueryBox_vtbl *v4; // edi
  KeyValues *v5; // eax
  KeyValues *m_pCancelCommand; // ecx
  vgui::QueryBox_vtbl *v7; // edi
  KeyValues *Copy; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") == 0 )
    {
      this->OnCommand(this, a2: "Close");
      m_pCancelCommand = this->m_pCancelCommand;
      if ( m_pCancelCommand != nullptr )
      {
        v7 = this->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pCancelCommand);
        v7->PostActionSignal(this, a2: Copy);
      }
    }
  }
  else
  {
    this->OnCommand(this, a2: "Close");
    m_pOkCommand = this->m_pOkCommand;
    if ( m_pOkCommand != nullptr )
    {
      v4 = this->__vftable;
      v5 = KeyValues::MakeCopy(this: m_pOkCommand);
      v4->PostActionSignal(this, a2: v5);
      vgui::MessageBox::OnCommand(this, pCommand: command);
      return;
    }
  }
  vgui::MessageBox::OnCommand(this, pCommand: command);
}

//------------------------------------------------------------------------------
// Address: 0x10057A90
// Name: public: void vgui::QueryBox::SetOKCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetOKCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pOkCommand; // ecx

  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  this->m_pOkCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x10057AD0
// Name: protected: virtual void vgui::QueryBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnKeyCodeTyped(vgui::QueryBox *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->OnCommand(this, a2: "Cancel");
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10057B00
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
// Address: 0x10057B30
// Name: public: virtual struct PanelAnimationMap __near * vgui::QueryBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::QueryBox::GetAnimMap(vgui::QueryBox *this)
{
  return FindOrAddPanelAnimationMap(className: "QueryBox");
}

//------------------------------------------------------------------------------
// Address: 0x10057B40
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

//------------------------------------------------------------------------------
// Address: 0x10057B70
// Name: public: vgui::QueryBox::QueryBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::QueryBox *__thiscall vgui::QueryBox::QueryBox(
        vgui::QueryBox *this,
        const char *title,
        const char *queryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *m_pOkButton; // ecx

  vgui::MessageBox::MessageBox(this, title, text: queryText, parent);
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( `vgui::QueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
    v5->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "QueryBox");
    v6->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
    v7->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#QueryBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  v9->SetCommand_2(this: v9, a2: "Cancel");
  this->m_pOkButton->SetCommand_2(this: this->m_pOkButton, a2: "OK");
  m_pOkButton = this->m_pOkButton;
  this->m_pCancelCommand = nullptr;
  this->m_pOkCommand = nullptr;
  m_pOkButton->SetTabPosition(this: m_pOkButton, a2: 1);
  this->m_pCancelButton->SetTabPosition(this: this->m_pCancelButton, a2: 2);
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0045E1C0
// Name: public: static char const __near * vgui::QueryBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::QueryBox::GetPanelClassName()
{
  return "QueryBox";
}

//------------------------------------------------------------------------------
// Address: 0x0045E1D0
// Name: public: virtual void vgui::QueryBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::PerformLayout(vgui::QueryBox *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-30h]
  int boxWidth; // [esp+4h] [ebp-28h] BYREF
  int boxTall; // [esp+8h] [ebp-24h] BYREF
  int oldTall; // [esp+Ch] [ebp-20h] BYREF
  int oldWide; // [esp+10h] [ebp-1Ch] BYREF
  int y; // [esp+14h] [ebp-18h] BYREF
  int x; // [esp+18h] [ebp-14h] BYREF
  int btnTall; // [esp+1Ch] [ebp-10h] BYREF
  int btnWide; // [esp+20h] [ebp-Ch] BYREF
  int wide; // [esp+24h] [ebp-8h] BYREF
  int tall; // [esp+28h] [ebp-4h] BYREF

  vgui::MessageBox::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
  this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v2, tall: v3);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v4 = vgui::Panel::GetTall(this: this->m_pOkButton);
  v7 = tall - v4 - 15;
  v5 = vgui::Panel::GetWide(this: this->m_pOkButton);
  vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 2 - v5 - 1, y: v7);
  v6 = vgui::Panel::GetTall(this: this->m_pCancelButton);
  vgui::Panel::SetPos(this: this->m_pCancelButton, x: wide / 2 + x + 16, y: tall - v6 - 15);
}

//------------------------------------------------------------------------------
// Address: 0x0045E2F0
// Name: protected: virtual void vgui::QueryBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnCommand(vgui::QueryBox *this, const char *command)
{
  KeyValues *m_pOkCommand; // ecx
  vgui::QueryBox_vtbl *v4; // edi
  KeyValues *v5; // eax
  KeyValues *m_pCancelCommand; // ecx
  vgui::QueryBox_vtbl *v7; // edi
  KeyValues *Copy; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") == 0 )
    {
      this->OnCommand(this, a2: "Close");
      m_pCancelCommand = this->m_pCancelCommand;
      if ( m_pCancelCommand != nullptr )
      {
        v7 = this->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pCancelCommand);
        v7->PostActionSignal(this, a2: Copy);
      }
    }
  }
  else
  {
    this->OnCommand(this, a2: "Close");
    m_pOkCommand = this->m_pOkCommand;
    if ( m_pOkCommand != nullptr )
    {
      v4 = this->__vftable;
      v5 = KeyValues::MakeCopy(this: m_pOkCommand);
      v4->PostActionSignal(this, a2: v5);
      vgui::MessageBox::OnCommand(this, pCommand: command);
      return;
    }
  }
  vgui::MessageBox::OnCommand(this, pCommand: command);
}

//------------------------------------------------------------------------------
// Address: 0x0045E3A0
// Name: public: void vgui::QueryBox::SetOKCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetOKCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pOkCommand; // ecx

  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  this->m_pOkCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x0045E3E0
// Name: public: void vgui::QueryBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetCancelCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pCancelCommand; // ecx

  m_pCancelCommand = this->m_pCancelCommand;
  if ( m_pCancelCommand != nullptr )
    KeyValues::deleteThis(this: m_pCancelCommand);
  this->m_pCancelCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x0045E420
// Name: protected: virtual void vgui::QueryBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnKeyCodeTyped(vgui::QueryBox *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->OnCommand(this, a2: "Cancel");
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0045E450
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
// Address: 0x0045E480
// Name: public: virtual struct PanelAnimationMap __near * vgui::QueryBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::QueryBox::GetAnimMap(vgui::QueryBox *this)
{
  return FindOrAddPanelAnimationMap(className: "QueryBox");
}

//------------------------------------------------------------------------------
// Address: 0x0045E490
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

//------------------------------------------------------------------------------
// Address: 0x0045E4C0
// Name: public: vgui::QueryBox::QueryBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::QueryBox *__thiscall vgui::QueryBox::QueryBox(
        vgui::QueryBox *this,
        const char *title,
        const char *queryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *m_pOkButton; // ecx

  vgui::MessageBox::MessageBox(this, title, text: queryText, parent);
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( `vgui::QueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
    v5->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "QueryBox");
    v6->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
    v7->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#QueryBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  v9->SetCommand(this: v9, a2: "Cancel");
  this->m_pOkButton->SetCommand(this: this->m_pOkButton, a2: "OK");
  m_pOkButton = this->m_pOkButton;
  this->m_pCancelCommand = nullptr;
  this->m_pOkCommand = nullptr;
  m_pOkButton->SetTabPosition(this: m_pOkButton, a2: 1);
  this->m_pCancelButton->SetTabPosition(this: this->m_pCancelButton, a2: 2);
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103C36B0
// Name: public: virtual vgui::QueryBox::~QueryBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::~QueryBox(vgui::QueryBox *this)
{
  vgui::Button *m_pCancelButton; // ecx
  KeyValues *m_pOkCommand; // ecx
  KeyValues *m_pCancelCommand; // ecx

  m_pCancelButton = this->m_pCancelButton;
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( m_pCancelButton != nullptr )
    ((void (__thiscall *)(vgui::Button *, int))m_pCancelButton->dtr_Panel)(a1: m_pCancelButton, a2: 1);
  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  m_pCancelCommand = this->m_pCancelCommand;
  if ( m_pCancelCommand != nullptr )
    KeyValues::deleteThis(this: m_pCancelCommand);
  vgui::MessageBox::~MessageBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C3700
// Name: public: virtual void vgui::QueryBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::PerformLayout(vgui::QueryBox *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-4h] [ebp-30h]
  int boxWidth; // [esp+4h] [ebp-28h] BYREF
  int boxTall; // [esp+8h] [ebp-24h] BYREF
  int oldTall; // [esp+Ch] [ebp-20h] BYREF
  int oldWide; // [esp+10h] [ebp-1Ch] BYREF
  int y; // [esp+14h] [ebp-18h] BYREF
  int x; // [esp+18h] [ebp-14h] BYREF
  int btnTall; // [esp+1Ch] [ebp-10h] BYREF
  int btnWide; // [esp+20h] [ebp-Ch] BYREF
  int wide; // [esp+24h] [ebp-8h] BYREF
  int tall; // [esp+28h] [ebp-4h] BYREF

  vgui::MessageBox::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  wide += x;
  tall += y;
  vgui::Panel::GetSize(this: this->m_pCancelButton, wide: &oldWide, tall: &oldTall);
  this->m_pCancelButton->GetContentSize(this: this->m_pCancelButton, a2: &btnWide, a3: &btnTall);
  v2 = btnWide + 10;
  if ( oldWide > btnWide + 10 )
    v2 = oldWide;
  v3 = btnTall + 10;
  btnWide = v2;
  if ( oldTall > btnTall + 10 )
    v3 = oldTall;
  btnTall = v3;
  vgui::Panel::SetSize(this: this->m_pCancelButton, wide: v2, tall: v3);
  vgui::Panel::GetSize(this, wide: &boxWidth, tall: &boxTall);
  v4 = vgui::Panel::GetTall(this: this->m_pOkButton);
  v7 = tall - v4 - 15;
  v5 = vgui::Panel::GetWide(this: this->m_pOkButton);
  vgui::Panel::SetPos(this: this->m_pOkButton, x: x + wide / 2 - v5 - 1, y: v7);
  v6 = vgui::Panel::GetTall(this: this->m_pCancelButton);
  vgui::Panel::SetPos(this: this->m_pCancelButton, x: wide / 2 + x + 16, y: tall - v6 - 15);
}

//------------------------------------------------------------------------------
// Address: 0x103C3820
// Name: protected: virtual void vgui::QueryBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnCommand(vgui::QueryBox *this, const char *command)
{
  KeyValues *m_pOkCommand; // ecx
  vgui::QueryBox_vtbl *v4; // edi
  KeyValues *v5; // eax
  KeyValues *m_pCancelCommand; // ecx
  vgui::QueryBox_vtbl *v7; // edi
  KeyValues *Copy; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") == 0 )
    {
      this->OnCommand(this, a2: "Close");
      m_pCancelCommand = this->m_pCancelCommand;
      if ( m_pCancelCommand != nullptr )
      {
        v7 = this->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pCancelCommand);
        v7->PostActionSignal(this, a2: Copy);
      }
    }
  }
  else
  {
    this->OnCommand(this, a2: "Close");
    m_pOkCommand = this->m_pOkCommand;
    if ( m_pOkCommand != nullptr )
    {
      v4 = this->__vftable;
      v5 = KeyValues::MakeCopy(this: m_pOkCommand);
      v4->PostActionSignal(this, a2: v5);
      vgui::MessageBox::OnCommand(this, pCommand: command);
      return;
    }
  }
  vgui::MessageBox::OnCommand(this, pCommand: command);
}

//------------------------------------------------------------------------------
// Address: 0x103C38D0
// Name: public: void vgui::QueryBox::SetOKCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetOKCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pOkCommand; // ecx

  m_pOkCommand = this->m_pOkCommand;
  if ( m_pOkCommand != nullptr )
    KeyValues::deleteThis(this: m_pOkCommand);
  this->m_pOkCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x103C3910
// Name: public: void vgui::QueryBox::SetCancelCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetCancelCommand(vgui::QueryBox *this, KeyValues *keyValues)
{
  KeyValues *m_pCancelCommand; // ecx

  m_pCancelCommand = this->m_pCancelCommand;
  if ( m_pCancelCommand != nullptr )
    KeyValues::deleteThis(this: m_pCancelCommand);
  this->m_pCancelCommand = keyValues;
}

//------------------------------------------------------------------------------
// Address: 0x103C3950
// Name: public: void vgui::QueryBox::SetCancelButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::SetCancelButtonText(vgui::QueryBox *this, const char *buttonText)
{
  this->m_pCancelButton->SetText(this: this->m_pCancelButton, a2: buttonText);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C3980
// Name: protected: virtual void vgui::QueryBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::QueryBox::OnKeyCodeTyped(vgui::QueryBox *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->OnCommand(this, a2: "Cancel");
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x103C39B0
// Name: public: vgui::QueryBox::QueryBox(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::QueryBox *__thiscall vgui::QueryBox::QueryBox(
        vgui::QueryBox *this,
        const char *title,
        const char *queryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *m_pOkButton; // ecx

  vgui::MessageBox::MessageBox(this, title, text: queryText, parent);
  this->__vftable = (vgui::QueryBox_vtbl *)&vgui::QueryBox::`vftable';
  if ( `vgui::QueryBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "QueryBox");
    v5->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "QueryBox");
    v6->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "MessageBox");
  }
  if ( `vgui::QueryBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::QueryBox::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "QueryBox");
    v7->pfnClassName = vgui::QueryBox::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "CancelButton",
           text: "#QueryBox_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pCancelButton = v9;
  v9->SetCommand(this: v9, a2: "Cancel");
  this->m_pOkButton->SetCommand(this: this->m_pOkButton, a2: "OK");
  m_pOkButton = this->m_pOkButton;
  this->m_pCancelCommand = nullptr;
  this->m_pOkCommand = nullptr;
  m_pOkButton->SetTabPosition(this: m_pOkButton, a2: 1);
  this->m_pCancelButton->SetTabPosition(this: this->m_pCancelButton, a2: 2);
  return this;
}

} // namespace client
