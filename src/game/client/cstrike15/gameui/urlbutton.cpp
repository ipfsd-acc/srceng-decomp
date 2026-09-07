// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/urlbutton.cpp
// Functions: 43
// ============================================================

#include "game\client\cstrike15\gameui\urlbutton.h"

//------------------------------------------------------------------------------
// Address: 0x101EAF20
// Name: public: static char const __near * vgui::URLButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::URLButton::GetPanelClassName()
{
  return "URLButton";
}

//------------------------------------------------------------------------------
// Address: 0x101EAF30
// Name: public: virtual void vgui::URLButton::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnHotkey(vgui::URLButton *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EAF40
// Name: public: virtual void vgui::URLButton::SetButtonActivationType(enum vgui::URLButton::ActivationType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetButtonActivationType(
        vgui::URLButton *this,
        vgui::URLButton::ActivationType_t activationType)
{
  this->_activationType = activationType;
}

//------------------------------------------------------------------------------
// Address: 0x101EAF50
// Name: public: virtual void vgui::URLButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::DoClick(vgui::URLButton *this)
{
  this->SetSelected(this, a2: true);
  this->FireActionSignal(this);
  this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101EAF80
// Name: protected: virtual void vgui::URLButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::Paint(vgui::URLButton *this)
{
  vgui::ISurface *v2; // ebx
  vgui::ISurface_vtbl *v3; // ecx
  Color *(__thiscall *GetButtonFgColor)(vgui::URLButton *, Color *); // edx
  int v5; // edi
  _DWORD *v6; // eax
  Color v7; // [esp+Ch] [ebp-1Ch] BYREF
  int textHeight; // [esp+10h] [ebp-18h] BYREF
  int controlWidth; // [esp+14h] [ebp-14h] BYREF
  int x; // [esp+18h] [ebp-10h]
  vgui::ISurface_vtbl *v11; // [esp+1Ch] [ebp-Ch]
  int controlHeight; // [esp+20h] [ebp-8h] BYREF
  int textWidth; // [esp+24h] [ebp-4h] BYREF

  vgui::Label::Paint(this);
  vgui::Panel::GetSize(this, wide: &controlWidth, tall: &controlHeight);
  this->GetContentSize(this, a2: &textWidth, a3: &textHeight);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  GetButtonFgColor = this->GetButtonFgColor;
  x = textWidth;
  v11 = v3;
  v5 = controlHeight - 4;
  v6 = (_DWORD *)GetButtonFgColor(this, result: &v7);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))v11->DrawSetColor)(a1: v2, a2: *v6);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: v5, a4: x, a5: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101EB010
// Name: public: virtual void vgui::URLButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::PerformLayout(vgui::URLButton *this)
{
  vgui::URLButton_vtbl *v2; // edi
  Color *v3; // eax
  vgui::URLButton_vtbl *v4; // edi
  Color *v5; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetButtonFgColor(this, result: v6);
  ((void (__thiscall *)(vgui::URLButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
  v4 = this->__vftable;
  v5 = this->GetButtonBgColor(this, result: v6);
  ((void (__thiscall *)(vgui::URLButton *, _DWORD))v4->SetBgColor)(a1: this, a2: *v5);
  vgui::Label::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EB060
// Name: public: virtual class Color vgui::URLButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::URLButton::GetButtonFgColor(vgui::URLButton *this, Color *result)
{
  *result = this->_defaultFgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EB080
// Name: public: virtual class Color vgui::URLButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::URLButton::GetButtonBgColor(vgui::URLButton *this, Color *result)
{
  *result = this->_defaultBgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EB0A0
// Name: public: virtual void vgui::URLButton::SetMouseClickEnabled(enum ButtonCode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetMouseClickEnabled(vgui::URLButton *this, ButtonCode_t code, bool state)
{
  int v3; // edx

  v3 = 1 << (code + 1);
  if ( state )
    this->_mouseClickMask |= v3;
  else
    this->_mouseClickMask &= ~v3;
}

//------------------------------------------------------------------------------
// Address: 0x101EB0D0
// Name: public: virtual void vgui::URLButton::SetCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetCommand(vgui::URLButton *this, char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "command", firstValue: command);
    this->SetCommand(this, a2: v4);
  }
  else
  {
    this->SetCommand(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB120
// Name: public: virtual void vgui::URLButton::SetCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetCommand(vgui::URLButton *this, KeyValues *message)
{
  KeyValues *actionMessage; // ecx

  actionMessage = this->_actionMessage;
  if ( actionMessage != nullptr )
    KeyValues::deleteThis(this: actionMessage);
  this->_actionMessage = message;
}

//------------------------------------------------------------------------------
// Address: 0x101EB170
// Name: public: virtual void vgui::URLButton::FireActionSignal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::FireActionSignal(vgui::URLButton *this)
{
  KeyValues *actionMessage; // ecx
  const char *Name; // eax
  char *String; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  vgui::ISystem *v7; // edi
  vgui::ISystem_vtbl *v8; // ebx
  char *v9; // eax
  vgui::URLButton_vtbl *v10; // edi
  KeyValues *Copy; // eax

  actionMessage = this->_actionMessage;
  if ( actionMessage != nullptr )
  {
    Name = KeyValues::GetName(this: actionMessage);
    if ( _V_stricmp(s1: Name, s2: "command") == 0 )
    {
      String = KeyValues::GetString(this: this->_actionMessage, keyName: "command", defaultValue: prType);
      if ( V_strncasecmp(s1: String, s2: "url ", n: 4) == 0 )
      {
        v5 = (unsigned __int8 *)KeyValues::GetString(
                                  this: this->_actionMessage,
                                  keyName: "command",
                                  defaultValue: prType);
        strstr(str1: v5, str2: "://");
        if ( v6 != 0 )
        {
          v7 = g_pVGuiSystem;
          v8 = g_pVGuiSystem->__vftable;
          v9 = KeyValues::GetString(this: this->_actionMessage, keyName: "command", defaultValue: "      ");
          v8->ShellExecute(this: v7, a2: "open", a3: v9 + 4);
        }
      }
    }
    v10 = this->__vftable;
    Copy = KeyValues::MakeCopy(this: this->_actionMessage);
    v10->PostActionSignal(this, a2: Copy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB240
// Name: public: virtual bool vgui::URLButton::RequestInfo(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::URLButton::RequestInfo(vgui::URLButton *this, KeyValues *outputData)
{
  const char *Name; // eax
  bool v4; // al
  const char *v6; // eax
  KeyValues *actionMessage; // ecx
  char *String; // [esp-4h] [ebp-Ch]

  Name = KeyValues::GetName(this: outputData);
  if ( _V_stricmp(s1: Name, s2: "GetState") != 0 )
  {
    v6 = KeyValues::GetName(this: outputData);
    if ( _V_stricmp(s1: v6, s2: "GetCommand") != 0 )
    {
      return vgui::Label::RequestInfo(this, outputData);
    }
    else
    {
      actionMessage = this->_actionMessage;
      String = (char *)prType;
      if ( actionMessage != nullptr )
        String = KeyValues::GetString(this: actionMessage, keyName: "command", defaultValue: prType);
      KeyValues::SetString(this: outputData, keyName: "command", value: String);
      return true;
    }
  }
  else
  {
    v4 = this->IsSelected(this);
    KeyValues::SetInt(this: outputData, keyName: "state", value: v4);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB2E0
// Name: protected: virtual void vgui::URLButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::URLButton::ApplySettings(vgui::URLButton *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // eax
  int Int; // eax

  vgui::Label::ApplySettings(this, a2, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "command", defaultValue: prType);
  if ( *String != 0 )
    this->SetCommand(this, a2: String);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "selected", defaultValue: -1);
  if ( Int != -1 )
  {
    this->SetSelected(this, a2: Int != 0);
    this->m_bSelectionStateSaved = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB350
// Name: protected: virtual char const __near * vgui::URLButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::URLButton::GetDescription(vgui::URLButton *this)
{
  char *Description; // eax

  Description = vgui::Label::GetDescription(this);
  V_snprintf(pDest: buf_0, maxLen: 0x400u, pFormat: "%s, string command, int default", Description);
  return buf_0;
}

//------------------------------------------------------------------------------
// Address: 0x101EB3B0
// Name: public: virtual void vgui::URLButton::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnCursorEntered(vgui::URLButton *this)
{
  if ( this->IsEnabled(this) )
    this->SetArmed(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101EB3E0
// Name: protected: virtual void vgui::URLButton::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnMousePressed(vgui::URLButton *this, ButtonCode_t code)
{
  vgui::URLButton_vtbl *v3; // eax
  vgui::IInput *v4; // edi
  vgui::IInput_vtbl *v5; // ebx
  int v6; // eax

  if ( this->IsEnabled(this) )
  {
    v3 = this->__vftable;
    if ( this->_activationType == ACTIVATE_ONPRESSED )
    {
      if ( v3->IsKeyBoardInputEnabled(this) )
        this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
    else if ( v3->IsUseCaptureMouseEnabled(this) && this->_activationType == ACTIVATE_ONPRESSEDANDRELEASED )
    {
      if ( this->IsKeyBoardInputEnabled(this) )
        this->RequestFocus(this, a2: 0);
      this->SetSelected(this, a2: true);
      this->Repaint(this);
      v4 = g_pVGuiInput;
      v5 = g_pVGuiInput->__vftable;
      v6 = this->GetVPanel(this);
      v5->SetMouseCapture(this: v4, a2: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB4C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::URLButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::URLButton::GetMessageMap(vgui::URLButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::URLButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLButton::GetMessageMap'::`2'::s_pMap;
  `vgui::URLButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "URLButton");
  `vgui::URLButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EB4F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::URLButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::URLButton::GetAnimMap(vgui::URLButton *this)
{
  return FindOrAddPanelAnimationMap(className: "URLButton");
}

//------------------------------------------------------------------------------
// Address: 0x101EB500
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::URLButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::URLButton::GetKBMap(vgui::URLButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::URLButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::URLButton::GetKBMap'::`2'::s_pMap;
  `vgui::URLButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "URLButton");
  `vgui::URLButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EB570
// Name: private: void vgui::URLButton::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::Init(vgui::URLButton *this)
{
  void (__thiscall *SetTextInset)(vgui::Label *, int, int); // edx

  this->_buttonFlags.m_nFlags |= 0x18u;
  SetTextInset = this->SetTextInset;
  this->_mouseClickMask = 0;
  this->_actionMessage = nullptr;
  this->m_bSelectionStateSaved = false;
  ((void (__stdcall *)(_DWORD, _DWORD))SetTextInset)(a1: 0, a2: 0);
  this->SetMouseClickEnabled(this, a2: KEY_COUNT, a3: true);
  this->SetButtonActivationType(this, a2: ACTIVATE_ONPRESSEDANDRELEASED);
  this->SetPaintBackgroundEnabled(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101EB5E0
// Name: public: virtual void vgui::URLButton::SetButtonBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetButtonBorderEnabled(vgui::URLButton *this, bool state)
{
  if ( state != ((this->_buttonFlags.m_nFlags & 8) != 0) )
  {
    if ( state )
      this->_buttonFlags.m_nFlags |= 8u;
    else
      this->_buttonFlags.m_nFlags &= ~8u;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB640
// Name: public: virtual void vgui::URLButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetSelected(vgui::URLButton *this, bool state)
{
  if ( LOBYTE(this->_buttonFlags.m_nFlags) >> 7 != state )
  {
    if ( state )
      this->_buttonFlags.m_nFlags |= 0x80u;
    else
      this->_buttonFlags.m_nFlags &= ~0x80u;
    this->RecalculateDepressedState(this);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB6A0
// Name: public: virtual void vgui::URLButton::ForceDepressed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::ForceDepressed(vgui::URLButton *this, bool state)
{
  if ( ((this->_buttonFlags.m_nFlags & 4) != 0) != state )
  {
    if ( state )
      this->_buttonFlags.m_nFlags |= 4u;
    else
      this->_buttonFlags.m_nFlags &= ~4u;
    this->RecalculateDepressedState(this);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB700
// Name: public: virtual void vgui::URLButton::RecalculateDepressedState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::RecalculateDepressedState(vgui::URLButton *this)
{
  unsigned __int16 m_nFlags; // ax
  char v3; // al

  if ( !this->IsEnabled(this) )
    goto LABEL_7;
  m_nFlags = this->_buttonFlags.m_nFlags;
  if ( (m_nFlags & 4) != 0 )
  {
    v3 = 1;
    goto LABEL_8;
  }
  if ( (this->_buttonFlags.m_nFlags & 1) != 0 && (m_nFlags & 0x80u) != 0 )
    v3 = 1;
  else
LABEL_7:
    v3 = 0;
LABEL_8:
  if ( v3 != 0 )
    this->_buttonFlags.m_nFlags |= 2u;
  else
    this->_buttonFlags.m_nFlags &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x101EB760
// Name: public: virtual void vgui::URLButton::SetUseCaptureMouse(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetUseCaptureMouse(vgui::URLButton *this, bool state)
{
  if ( state )
    this->_buttonFlags.m_nFlags |= 0x10u;
  else
    this->_buttonFlags.m_nFlags &= ~0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x101EB790
// Name: public: virtual bool vgui::URLButton::IsUseCaptureMouseEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::URLButton::IsUseCaptureMouseEnabled(vgui::URLButton *this)
{
  return (this->_buttonFlags.m_nFlags & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EB7A0
// Name: public: virtual void vgui::URLButton::SetArmed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SetArmed(vgui::URLButton *this, bool state)
{
  if ( (this->_buttonFlags.m_nFlags & 1) != state )
  {
    if ( state )
      this->_buttonFlags.m_nFlags |= 1u;
    else
      this->_buttonFlags.m_nFlags &= ~1u;
    this->RecalculateDepressedState(this);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB800
// Name: public: virtual bool vgui::URLButton::IsArmed(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::URLButton::IsArmed(vgui::URLButton *this)
{
  return this->_buttonFlags.m_nFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EB810
// Name: public: virtual bool vgui::URLButton::IsSelected(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::URLButton::IsSelected(vgui::URLButton *this)
{
  return (this->_buttonFlags.m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EB820
// Name: public: virtual bool vgui::URLButton::IsDepressed(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::URLButton::IsDepressed(vgui::URLButton *this)
{
  return (this->_buttonFlags.m_nFlags & 2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EB830
// Name: protected: virtual void vgui::URLButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::ApplySchemeSettings(vgui::URLButton *this, int pScheme)
{
  int v2; // edi
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color v5; // ecx

  v2 = pScheme;
  vgui::Label::ApplySchemeSettings(this, (vgui::Label_vtbl *)pScheme);
  GetSchemeColor = this->GetSchemeColor;
  pScheme = -1;
  v5 = *(Color *)((int (__thiscall *)(vgui::URLButton *, int *, const char *, int, int))GetSchemeColor)(
                   a1: this,
                   a2: &pScheme,
                   a3: "Button.TextColor",
                   a4: -1,
                   a5: v2);
  pScheme = -16777216;
  this->_defaultFgColor = v5;
  this->_defaultBgColor = *(Color *)((int (__thiscall *)(vgui::URLButton *, int *, const char *, int, int))this->GetSchemeColor)(
                                      a1: this,
                                      a2: &pScheme,
                                      a3: "Button.BgColor",
                                      a4: -16777216,
                                      a5: v2);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101EB8B0
// Name: protected: virtual void vgui::URLButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::GetSettings(vgui::URLButton *this, KeyValues *outResourceData)
{
  KeyValues *actionMessage; // ecx
  char *String; // eax
  bool v5; // al

  vgui::Label::GetSettings(this, outResourceData);
  actionMessage = this->_actionMessage;
  if ( actionMessage != nullptr )
  {
    String = KeyValues::GetString(this: actionMessage, keyName: "command", defaultValue: prType);
    KeyValues::SetString(this: outResourceData, keyName: "command", value: String);
  }
  KeyValues::SetInt(this: outResourceData, keyName: "default", value: (this->_buttonFlags.m_nFlags >> 6) & 1);
  if ( this->m_bSelectionStateSaved )
  {
    v5 = this->IsSelected(this);
    KeyValues::SetInt(this: outResourceData, keyName: "selected", value: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EB930
// Name: public: virtual void vgui::URLButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnCursorExited(vgui::URLButton *this)
{
  if ( (this->_buttonFlags.m_nFlags & 0x20) == 0 )
    this->SetArmed(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101EB950
// Name: protected: virtual void vgui::URLButton::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnMouseReleased(vgui::URLButton *this, ButtonCode_t code)
{
  unsigned int v3; // edi

  if ( this->IsUseCaptureMouseEnabled(this) )
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  if ( this->_activationType != ACTIVATE_ONPRESSED
    && (this->IsSelected(this) || this->_activationType != ACTIVATE_ONPRESSEDANDRELEASED) )
  {
    if ( this->IsEnabled(this)
      && ((v3 = g_pVGuiInput->GetMouseOver(this: g_pVGuiInput), this->GetVPanel(this) == v3)
       || (this->_buttonFlags.m_nFlags & 0x20) != 0) )
    {
      this->DoClick(this);
      this->Repaint(this);
    }
    else
    {
      this->SetSelected(this, a2: false);
      this->Repaint(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBA10
// Name: protected: virtual void vgui::URLButton::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnKeyCodePressed(vgui::URLButton *this, ButtonCode_t code)
{
  if ( code == KEY_SPACE || code == KEY_ENTER )
  {
    this->SetArmed(this, a2: true);
    this->_buttonFlags.m_nFlags |= 0x20u;
    this->OnMousePressed(this, a2: KEY_COUNT);
    if ( this->IsUseCaptureMouseEnabled(this) )
      g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
  else
  {
    this->_buttonFlags.m_nFlags &= ~0x20u;
    vgui::Panel::OnKeyCodePressed(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBA90
// Name: protected: virtual void vgui::URLButton::OnKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::OnKeyCodeReleased(vgui::URLButton *this, ButtonCode_t code)
{
  if ( (this->_buttonFlags.m_nFlags & 0x20) != 0 && (code == KEY_SPACE || code == KEY_ENTER) )
  {
    this->SetArmed(this, a2: true);
    this->OnMouseReleased(this, a2: KEY_COUNT);
  }
  else
  {
    vgui::Panel::OnKeyCodeReleased(this, code);
  }
  this->_buttonFlags.m_nFlags &= ~0x20u;
  this->SetArmed(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101EBB00
// Name: public: static void vgui::URLButton::PanelMessageFunc_DoClick::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::URLButton::PanelMessageFunc_DoClick::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::URLButton::PanelMessageFunc_DoClick::InitVar'::`2'::bAdded )
  {
    `vgui::URLButton::PanelMessageFunc_DoClick::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::URLButton::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "URLButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PressButton";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBB90
// Name: public: static void vgui::URLButton::PanelMessageFunc_OnHotkey::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::URLButton::PanelMessageFunc_OnHotkey::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::URLButton::PanelMessageFunc_OnHotkey::InitVar'::`2'::bAdded )
  {
    `vgui::URLButton::PanelMessageFunc_OnHotkey::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertySheet::`vcall'{1040,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "URLButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Hotkey";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBC20
// Name: public: static void vgui::URLButton::PanelMessageFunc_OnSetState::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::URLButton::PanelMessageFunc_OnSetState::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::URLButton::PanelMessageFunc_OnSetState::InitVar'::`2'::bAdded )
  {
    `vgui::URLButton::PanelMessageFunc_OnSetState::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::URLButton::`vcall'{1080,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "URLButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetState";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBCC0
// Name: public: vgui::URLButton::URLButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::URLButton *__thiscall vgui::URLButton::URLButton(
        vgui::URLButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionSignalTarget,
        char *pCmd)
{
  vgui::PanelMessageMap *v7; // edi
  PanelAnimationMap *v8; // edi
  vgui::PanelKeyBindingMap *v9; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (vgui::URLButton_vtbl *)&vgui::URLButton::`vftable';
  if ( `vgui::URLButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLButton::ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelMessageMap(className: "URLButton");
    v7->pfnClassName = vgui::URLButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelMessageMap(className: "Label");
  }
  if ( `vgui::URLButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::URLButton::ChainToAnimationMap'::`2'::chained = 1;
    v8 = FindOrAddPanelAnimationMap(className: "URLButton");
    v8->pfnClassName = vgui::URLButton::GetPanelClassName;
    v8->baseMap = FindOrAddPanelAnimationMap(className: "Label");
  }
  if ( `vgui::URLButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::URLButton::KB_ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelKeyBindingMap(className: "URLButton");
    v9->pfnClassName = vgui::URLButton::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  }
  vgui::URLButton::PanelMessageFunc_DoClick::InitVar();
  vgui::URLButton::PanelMessageFunc_OnHotkey::InitVar();
  vgui::URLButton::PanelMessageFunc_OnSetState::InitVar();
  this->_buttonFlags.m_nFlags = 0;
  this->_defaultFgColor = 0;
  this->_defaultBgColor = 0;
  vgui::URLButton::Init(this);
  if ( pActionSignalTarget != nullptr && pCmd != nullptr )
  {
    vgui::Panel::AddActionSignalTarget(this, messageTarget: pActionSignalTarget);
    vgui::URLButton::SetCommand(this, command: pCmd);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EBDD0
// Name: Create_URLButton
// Source: json
//------------------------------------------------------------------------------
vgui::URLButton *__cdecl Create_URLButton()
{
  vgui::URLButton *v0; // eax

  v0 = (vgui::URLButton *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v0 != nullptr )
    return vgui::URLButton::URLButton(
             this: v0,
             parent: nullptr,
             panelName: nullptr,
             text: "URLButton",
             pActionSignalTarget: nullptr,
             pCmd: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1039C5F0
// Name: public: virtual void vgui::URLButton::SizeToContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::URLButton::SizeToContents(vgui::Button *this)
{
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  this->GetContentSize(this, a2: &wide, a3: &tall);
  vgui::Panel::SetSize(this, wide: wide + 8, tall: tall + 8);
}
