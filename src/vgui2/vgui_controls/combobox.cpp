// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/combobox.cpp
// Functions: 52
// ============================================================

#include "vgui2\vgui_controls\combobox.h"

//------------------------------------------------------------------------------
// Address: 0x1029A020
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x1029A030
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A070
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1029A1E0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A220
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A250
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x1029A260
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x1029A280
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x1029A2D0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x1029A350
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029A3D0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029A460
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1029A480
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1029A4A0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1029A4C0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A4D0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A4E0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1029A500
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x1029A520
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A560
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5A0
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5B0
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5F0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1029A610
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A690
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6D0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1029A710
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A820
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A860
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A890
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A8A0
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A930
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029AB20
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029AB40
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029AB80
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029ABE0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x1029AC30
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x1029AC50
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029ACE0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x1029ACF0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1029AD20
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x1029AD80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029ADB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x1029ADC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029AE40
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029AF70
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B0A0
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x1029B110
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B1B0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B240
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B2D0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B370
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar();
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10049B60
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x10049B70
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049BB0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10049D20
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049D60
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10049D90
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x10049DA0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x10049DC0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10049E10
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10049E90
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049F10
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049FA0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10049FC0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10049FE0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1004A000
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1004A010
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1004A020
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1004A040
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x1004A060
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1004A0A0
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1004A0E0
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1004A0F0
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1004A130
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1004A150
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A1D0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x1004A210
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1004A250
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004A360
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A3A0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A3D0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004A3E0
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A470
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A660
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004A680
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A6C0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004A720
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x1004A770
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x1004A790
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A820
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x1004A830
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1004A860
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x1004A8C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A8F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x1004A900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A980
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1004AAB0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004ABE0
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x1004AC50
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004ACF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AD80
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AE10
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AEB0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004282E0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x004282F0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428330
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004284A0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004284E0
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428510
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x00428520
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x00428530
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x00428540
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00428560
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x004285B0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00428630
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004286B0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00428740
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00428760
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00428780
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x004287A0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x004287B0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x004287D0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x004287F0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00428870
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00428880
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004288C0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004288E0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428960
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x004289A0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x004289E0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428AF0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428B30
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428B60
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428B70
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428C00
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428DF0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428E10
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428E50
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00428EB0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x00428F00
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00428F20
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428FB0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00428FC0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00428FF0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00429050
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429080
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00429090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429110
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00429240
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429370
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x004293E0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429480
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429510
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004295A0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429640
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00443970
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004470F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447120
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x00447130
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10036AE0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x10036AF0
// Name: public: static char const __near * vgui::Button::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Button::GetPanelClassName()
{
  return "Button";
}

//------------------------------------------------------------------------------
// Address: 0x10036B10
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036B20
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036B60
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10036CD0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036D10
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10036D40
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x10036D50
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10036D70
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x10036D80
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x10036DA0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10036DF0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10036E70
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036EF0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036F80
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10036FA0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10036FC0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10036FE0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10036FF0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10037000
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10037020
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x10037040
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10037080
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x100370D0
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x100370E0
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10037120
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10037140
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100371C0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x10037200
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10037240
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037350
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037390
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100373C0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x100373D0
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037460
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037650
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037670
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100376B0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037710
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  CBaseFileSystem::InstallDirtyDiskReportFunc(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x10037760
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x10037780
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037810
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x10037820
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10037850
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x10037930
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037960
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x10037970
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100379F0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10037B20
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037C50
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x10037CC0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037D60
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037DF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037E80
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037F20
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056960
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  wchar_t v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x10057F70
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x100584A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100584D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x100584E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00604E70
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x00604E80
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00604EC0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00605040
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605080
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x006050B0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x006050D0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00605120
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x006051A0
// Name: public: void vgui::ComboBox::DeleteItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::DeleteItem(vgui::ComboBox *this, int itemID)
{
  if ( this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID) )
    vgui::Menu::DeleteItem(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x006051E0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00605260
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006052F0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00605310
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00605330
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00605350
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00605360
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00605370
// Name: public: int vgui::ComboBox::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemIDFromRow(vgui::ComboBox *this, int row)
{
  return this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00605390
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x006053B0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x006053D0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00605410
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00605460
// Name: public: void vgui::ComboBox::GetItemText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, char *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x00605470
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00605480
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x006054C0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x006054E0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605560
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x006055A0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x006055E0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x006056F0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605730
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605760
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00605770
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605800
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006059F0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x00605A10
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605A50
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00605AB0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x00605B00
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00605B20
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605BB0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00605BC0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00605BF0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00605D10
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00605E40
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00605F70
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00605FF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606090
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606120
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006061B0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606250
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1029A120
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x1029A130
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A170
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1029A2E0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A320
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A360
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x1029A380
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x1029A450
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029A580
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5C0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5D0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A5E0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1029A600
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x1029A620
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A660
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6A0
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6B0
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1029A6F0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1029A790
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x1029A7D0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1029A810
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A920
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A960
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029A990
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029A9A0
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029AA30
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029AC20
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029AC40
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029AC80
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1029AD30
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x1029AD50
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029ADE0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x1029ADF0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1029AE20
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x1029AE80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029AEB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x1029AEC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029B1D0
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x1029B2E0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B400
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B4A0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EBC30
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x102EBC40
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBC80
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102EBDF0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EBE30
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EBE60
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE70
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x102EBE90
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x102EBEE0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x102EBF60
// Name: public: void vgui::ComboBox::DeleteItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::DeleteItem(vgui::ComboBox *this, int itemID)
{
  if ( this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID) )
    vgui::Menu::DeleteItem(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x102EBFA0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC020
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EC0B0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x102EC0D0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x102EC0F0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x102EC110
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x102EC120
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x102EC130
// Name: public: int vgui::ComboBox::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemIDFromRow(vgui::ComboBox *this, int row)
{
  return this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x102EC150
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x102EC170
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x102EC190
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x102EC1D0
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x102EC220
// Name: public: void vgui::ComboBox::GetItemText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, char *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x102EC230
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x102EC240
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102EC280
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102EC2A0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC320
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x102EC360
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x102EC3A0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EC4B0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC4F0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC520
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EC530
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC5C0
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC7B0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EC7D0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC810
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EC870
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x102EC8C0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x102EC8E0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EC970
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x102EC980
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x102EC9B0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x102EC9F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA20
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x102ECA30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102ECAB0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x102ECBE0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECD10
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x102ECD80
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECE20
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECEB0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECF40
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102ECFF0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        vgui::Panel *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040B22A
// Name: public: void CMFCCaptionMenuButton::ShowMenu(struct HMENU__ __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionMenuButton::ShowMenu(CMFCCaptionMenuButton *this, HMENU__ *hMenu, CWnd *pWndOwner)
{
  int v4; // ebx
  int v5; // ebx
  CRect *v6; // eax
  int v7; // eax
  CMFCCaptionMenuButton_vtbl *v8; // eax
  const RECT *v9; // eax
  CPoint point; // [esp+10h] [ebp-2Ch] BYREF
  CRect v11; // [esp+18h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+28h] [ebp-14h] BYREF

  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: pWndOwner->m_hWnd, lpRect: &rectWnd);
  CMFCCaptionButton::GetSize(result: (CSize *)&point);
  v4 = rectWnd.left + this->m_ptOrg.x;
  point.y += rectWnd.top + this->m_ptOrg.y;
  v5 = point.x + v4;
  this->m_bMenuIsActive = 1;
  this->m_bPushed = 1;
  v6 = this->GetRect(this, result: &v11);
  InvalidateRect(hWnd: pWndOwner->m_hWnd, lpRect: v6, bErase: true);
  SendMessageA(hWnd: pWndOwner->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
  if ( this->m_bOSMenu != 0 || afxContextMenuManager == nullptr )
    v7 = TrackPopupMenu(
           hMenu,
           uFlags: 0x180u,
           x: v5,
           y: point.y,
           nReserved: 0,
           hWnd: pWndOwner->m_hWnd,
           prcRect: nullptr);
  else
    v7 = afxContextMenuManager->TrackPopupMenu(
           this: afxContextMenuManager,
           a2: hMenu,
           a3: v5,
           a4: point.y,
           a5: pWndOwner,
           a6: 1);
  this->m_nMenuResult = v7;
  v8 = this->__vftable;
  this->m_bMenuIsActive = 0;
  this->m_bPushed = 0;
  v9 = v8->GetRect(this, result: &v11);
  InvalidateRect(hWnd: pWndOwner->m_hWnd, lpRect: v9, bErase: true);
  SendMessageA(hWnd: pWndOwner->m_hWnd, Msg: 0x85u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1040B332
// Name: public: virtual struct CRuntimeClass __near * CMFCListCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCListCtrl::GetRuntimeClass(CMFCListCtrl *this)
{
  return &CMFCListCtrl::classCMFCListCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1040B338
// Name: public: virtual CMFCListCtrl::~CMFCListCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::~CMFCListCtrl(CMFCListCtrl *this)
{
  this->__vftable = (CMFCListCtrl_vtbl *)&CMFCListCtrl::`vftable';
  CMFCHeaderCtrl::~CMFCHeaderCtrl(this: &this->m_wndHeader);
  CListCtrl::~CListCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040B36C
// Name: protected: virtual void CMFCListCtrl::InitHeader(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::InitHeader(CMFCListCtrl *this)
{
  CWnd::SubclassDlgItem(this: &this->m_wndHeader, nID: 0, pParent: this);
}

//------------------------------------------------------------------------------
// Address: 0x1040B37A
// Name: public: int CMFCListCtrl::IsMultipleSort(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCListCtrl::IsMultipleSort(CMFCListCtrl *this)
{
  return this->GetHeaderCtrl(this)->m_bMultipleSort;
}

//------------------------------------------------------------------------------
// Address: 0x1040B389
// Name: public: virtual int COleDocIPFrameWndEx::OnDrawMenuImage(class CDC __near *,class CMFCToolBarMenuButton const __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleDocIPFrameWndEx::OnDrawMenuImage(
        CBasePane *this,
        CBasePane *pDockBar,
        CBasePane *lpRect,
        const tagRECT *dockMethod)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040B38E
// Name: protected: static int CMFCListCtrl::CompareProc(long,long,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCListCtrl::CompareProc(int lParam1, int lParam2, _DWORD *lParamSort)
{
  int result; // eax

  result = (*(int (__thiscall **)(_DWORD *, int, int, _DWORD))(*lParamSort + 364))(
             a1: lParamSort,
             a2: lParam1,
             a3: lParam2,
             a4: lParamSort[73]);
  if ( lParamSort[74] == 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B3BD
// Name: public: CMFCListCtrl::CMFCListCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCListCtrl *__thiscall CMFCListCtrl::CMFCListCtrl(CMFCListCtrl *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMFCListCtrl_vtbl *)&CMFCListCtrl::`vftable';
  CMFCHeaderCtrl::CMFCHeaderCtrl(this: &this->m_wndHeader);
  this->m_iSortedColumn = -1;
  this->m_bMarkSortedColumn = 0;
  this->m_clrSortedColumn = -1;
  this->m_hOldFont = nullptr;
  this->m_bAscending = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040B434
// Name: protected: void CMFCListCtrl::OnColumnClick(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::OnColumnClick(CMFCListCtrl *this, tagNMHDR *pNMHDR, int *pResult)
{
  unsigned int idFrom; // ebx
  int v5; // esi
  CMFCHeaderCtrl *v6; // eax
  int ColumnState; // eax
  BOOL v8; // eax
  BOOL bAscending; // [esp+14h] [ebp+8h]

  if ( pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  idFrom = pNMHDR[1].idFrom;
  v5 = GetAsyncKeyState(vKey: 16) & 0x8000;
  v6 = this->GetHeaderCtrl(this);
  ColumnState = CMFCHeaderCtrl::GetColumnState(this: v6, iColumn: idFrom);
  bAscending = true;
  if ( ColumnState != 0 )
    bAscending = ColumnState <= 0;
  v8 = v5 != 0 && CMFCListCtrl::IsMultipleSort(this) != 0;
  this->Sort(this, a2: idFrom, a3: bAscending, a4: v8);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040B4B7
// Name: protected: void CMFCListCtrl::OnCustomDraw(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCListCtrl::OnCustomDraw(CMFCListCtrl *this@<ecx>, int a2@<ebx>, tagNMHDR *pNMHDR, int *pResult)
{
  unsigned int code; // ebx
  void *v7; // eax
  HFONT__ *v8; // eax
  HWND__ *iRow; // [esp+10h] [ebp+8h]

  if ( pNMHDR == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  switch ( (unsigned int)pNMHDR[1].hwndFrom )
  {
    case 1u:
    case 0x10001u:
      *pResult = 32;
      break;
    case 0x30001u:
      code = pNMHDR[4].code;
      iRow = pNMHDR[3].hwndFrom;
      pNMHDR[4].idFrom = ((int (__thiscall *)(CMFCListCtrl *, HWND__ *, unsigned int, int))this->OnGetCellBkColor)(
                           a1: this,
                           a2: iRow,
                           a3: code,
                           a4: a2);
      pNMHDR[4].hwndFrom = (HWND__ *)this->OnGetCellTextColor(this, a2: (int)iRow, a3: code);
      if ( code == this->m_iSortedColumn
        && this->m_bMarkSortedColumn != 0
        && pNMHDR[4].idFrom == SendMessageA(hWnd: this->m_hWnd, Msg: 0x1000u, wParam: 0, lParam: 0) )
      {
        pNMHDR[4].idFrom = this->m_clrSortedColumn;
      }
      v7 = (void *)((int (__thiscall *)(CMFCListCtrl *, HWND__ *, unsigned int))this->OnGetCellFont)(
                     a1: this,
                     a2: iRow,
                     a3: code);
      if ( v7 == nullptr )
      {
LABEL_9:
        *pResult = 0;
        return;
      }
      v8 = (HFONT__ *)SelectObject(hdc: (HDC)pNMHDR[1].idFrom, h: v7);
      this->m_hOldFont = v8;
      if ( v8 == nullptr )
        goto LABEL_2;
      *pResult = 18;
      break;
    case 0x30002u:
      if ( this->m_hOldFont != nullptr )
      {
        SelectObject(hdc: (HDC)pNMHDR[1].idFrom, h: this->m_hOldFont);
        this->m_hOldFont = nullptr;
      }
      goto LABEL_9;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040B5B5
// Name: protected: void CMFCListCtrl::InitColors(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::InitColors(CMFCListCtrl *this)
{
  LRESULT v2; // eax

  v2 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1000u, wParam: 0, lParam: 0);
  this->m_clrSortedColumn = CDrawingManager::PixelAlpha(srcPixel: v2, percentR: 0.97, percentG: 0.97, percentB: 0.97);
}

//------------------------------------------------------------------------------
// Address: 0x1040B5EE
// Name: protected: long CMFCListCtrl::OnStyleChanged(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCListCtrl::OnStyleChanged(CMFCListCtrl *this, unsigned int wp, _BYTE *lp)
{
  CMFCHeaderCtrl *v4; // eax

  CWnd::Default(this);
  if ( (lp[4] & 1) != 0 && (*lp & 1) == 0 )
  {
    v4 = this->GetHeaderCtrl(this);
    if ( v4 == nullptr || v4->m_hWnd == nullptr )
      this->InitHeader(this);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040B62E
// Name: protected: void CMFCListCtrl::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCListCtrl::OnSize(CMFCListCtrl *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  if ( this != (CMFCListCtrl *)-116 && this->m_wndHeader.m_hWnd != nullptr )
    RedrawWindow(hWnd: this->m_wndHeader.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1040B65E
// Name: protected: int CMFCListCtrl::InitList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCListCtrl::InitList(CMFCListCtrl *this)
{
  this->InitHeader(this);
  CMFCListCtrl::InitColors(this);
  return 1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x1009D050
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x1009D060
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D0A0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1009D210
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D250
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D280
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x1009D290
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x1009D2A0
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x1009D2B0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x1009D2D0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x1009D320
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x1009D3A0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D420
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009D4B0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1009D4D0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1009D4F0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x1009D510
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1009D520
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1009D530
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x1009D550
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x1009D570
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D5B0
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1009D5F0
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1009D600
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1009D640
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1009D660
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D6E0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x1009D720
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1009D760
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D870
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D8B0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D8E0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D8F0
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D980
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DB70
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009DB90
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DBD0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009DC30
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x1009DC80
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x1009DCA0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DD30
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x1009DD40
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1009DD70
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x1009DDD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DE00
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x1009DE10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DEC0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x1009DFF0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E120
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x1009E190
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E230
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E2C0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E350
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E3F0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0043A140
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A170
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x0043A180
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448860
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x00448870
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004488B0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00448A20
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448A60
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448A90
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x00448AA0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00448AC0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00448B10
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00448B90
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448C10
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448CA0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00448CC0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448CE0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448D00
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00448D10
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00448D20
// Name: public: int vgui::ComboBox::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemIDFromRow(vgui::ComboBox *this, int row)
{
  return this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00448D40
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00448D60
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00448D80
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00448E00
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00448E10
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00448E50
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448E70
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448EF0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x00448F30
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x00448F70
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449080
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004490C0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004490F0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449100
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449190
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449380
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x004493A0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004493E0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449440
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x00449490
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x004494B0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449540
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00449550
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00449580
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x004495E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449610
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00449620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004496A0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x004497D0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449900
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00449970
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449A10
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449AA0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449B30
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449BD0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00464330
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042FEA0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x0042FEB0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FEF0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  vgui::IScheme_vtbl *v5; // ebp
  int v6; // eax
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // ebp
  Color *v12; // eax
  vgui::ComboBoxButton_vtbl *v13; // ebx
  Color *v14; // ebp
  Color *v15; // eax
  vgui::ComboBoxButton_vtbl *v16; // ebx
  Color *v17; // ebp
  Color *v18; // eax
  char v19[4]; // [esp+78h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = v2->__vftable;
  v6 = ((int (__thiscall *)(vgui::ComboBoxButton *))this->IsProportional)(a1: this);
  v7 = v5->GetFont(this: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  v11 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v12 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v10->SetDefaultColor)(a1: this, a2: *v12, a3: *v11);
  v13 = this->__vftable;
  v14 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v13->SetArmedColor)(a1: this, a2: *v15, a3: *v14);
  v16 = this->__vftable;
  v17 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v18 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v16->SetDepressedColor)(a1: this, a2: *v18, a3: *v17);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00430050
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430090
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::~ComboBox(vgui::ComboBox *this@<ecx>, int a2@<ebp>)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x004300C0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x004300D0
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x004300E0
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x004300F0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00430100
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00430150
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+8h] [ebp-84h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: &ansi[4], a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: &ansi[4], a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x004301E0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430260
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004302F0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00430300
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00430310
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00430320
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00430330
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00430340
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00430350
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00430360
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x004303A0
// Name: private: void vgui::ComboBox::DoMenuLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::DoMenuLayout(vgui::ComboBox *this)
{
  vgui::Menu_vtbl *v2; // edi
  int Wide; // eax

  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v2 = this->m_pDropDown->__vftable;
  Wide = vgui::Panel::GetWide(this);
  v2->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00430420
// Name: public: void vgui::ComboBox::GetItemText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, char *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x00430430
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00430440
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00430470
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00430480
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        ButtonCode_t code)
{
  bool v6; // zf
  vgui::ComboBox_vtbl *v7; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v6 = !this->IsCursorOver(this);
    v7 = this->__vftable;
    if ( v6 )
    {
      v7->HideMenu(this);
    }
    else if ( v7->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, a4, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430500
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x00430530
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x00430570
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char cbuf[255]; // [esp+8h] [ebp-304h] BYREF
  unsigned __int16 wbuf[258]; // [esp+108h] [ebp-204h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: &cbuf[4], a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[5]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: &wbuf[2], a3: 254);
  if ( wcscmp(&wbuf[2], v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00430680
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004306C0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004306F0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00430700
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430790
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  void (__thiscall **p_SetFixedWidth)(vgui::Menu *, int); // edi
  int Wide; // eax
  unsigned __int16 comboBoxContents[256]; // [esp+10h] [ebp-404h] BYREF
  wchar_t menuItemName[258]; // [esp+210h] [ebp-204h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: &comboBoxContents[4], a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: &menuItemName[4], a3: 255);
        if ( wcscmp(&menuItemName[4], &comboBoxContents[4]) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    p_SetFixedWidth = &this->m_pDropDown->SetFixedWidth;
    Wide = vgui::Panel::GetWide(this);
    (*p_SetFixedWidth)(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430990
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x004309B0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004309F0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[258]; // [esp+0h] [ebp-204h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: &name[2], bufLenInBytes: 512);
    this->OnSetText(this, a2: &name[2]);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00430A50
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x00430AA0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00430AC0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[258]; // [esp+8h] [ebp-204h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: &menuItemName[2], a3: 254);
    this->OnSetText(this, a2: &menuItemName[2]);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430B50
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00430B60
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00430B90
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00430BF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430C20
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00430C30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430CA0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  int v9; // eax
  int tall; // [esp+14h] [ebp-10h] BYREF
  int wide; // [esp+18h] [ebp-Ch] BYREF
  int button_tall; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v13[4]; // [esp+20h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &button_tall, a3: &wide);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( wide < v3 )
    v3 = wide;
  v4 = wide - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &tall, a3: (int *)v13);
  v5 = tall;
  if ( v3 > tall )
  {
    v5 = v3;
    tall = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: button_tall - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = ((int (__thiscall *)(vgui::ComboBox *))this->IsEnabled)(a1: this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  vgui::ComboBox::DoMenuLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00430D90
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430EB0
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00430F20
// Name: public: static void vgui::ComboBox::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ComboBox::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00430FA0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "ActivateItem",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "itemID",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431000
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431060
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "MenuItemSelected",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004310C0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "SetText",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)7,
      p1name: "text",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431120
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar();
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iDirection = 3;
  this->m_iOpenOffsetY = 0;
  return this;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063C510
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x0063C520
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063C560
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0063C6D0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063C710
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063C740
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x0063C760
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x0063C7B0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x0063C830
// Name: public: void vgui::ComboBox::DeleteItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::DeleteItem(vgui::ComboBox *this, int itemID)
{
  if ( this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID) )
    vgui::Menu::DeleteItem(this: this->m_pDropDown, itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0063C870
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063C8F0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063C980
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0063C9A0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x0063C9C0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x0063C9E0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0063C9F0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0063CA00
// Name: public: int vgui::ComboBox::GetItemIDFromRow(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemIDFromRow(vgui::ComboBox *this, int row)
{
  return this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x0063CA20
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0063CA40
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x0063CA60
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x0063CAA0
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0063CAF0
// Name: public: void vgui::ComboBox::GetItemText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, char *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x0063CB00
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0063CB10
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0063CB50
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0063CB70
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063CBF0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x0063CC30
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x0063CC70
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063CD80
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063CDC0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063CDF0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063CE00
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063CE90
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D080
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063D0A0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D0E0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063D140
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x0063D190
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x0063D1B0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D240
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x0063D250
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0063D280
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x0063D3A0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0063D4D0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D600
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x0063D670
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D710
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D7A0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D830
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D8D0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10038AC0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x10038AD0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038B10
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10038C90
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038CD0
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10038D00
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10038D10
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x10038D20
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x10038D40
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10038D90
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10038E10
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038E90
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038F20
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10038F40
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10038F60
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10038F80
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10038F90
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10038FA0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10038FC0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x10038FE0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10039020
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10039070
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10039080
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100390C0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100390E0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039160
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x100391A0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x100391E0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x100392F0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039330
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039360
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x10039370
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039400
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100395F0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x10039610
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039650
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100396B0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x10039700
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x10039720
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100397B0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x100397C0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x100397F0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x10039860
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039890
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x100398A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039920
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10039A50
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039B80
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x10039BF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039C90
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039D20
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039DB0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039E50
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006E390
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10066BA0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x10066BB0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066BF0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10066D60
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066DA0
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10066DD0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x10066DE0
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10066DF0
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x10066E00
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x10066E20
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10066E70
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10066EF0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066F70
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067000
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10067020
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10067040
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10067060
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10067070
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10067090
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x100670B0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10067120
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10067130
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10067170
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10067190
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067210
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x10067250
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10067290
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x100673A0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100673E0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067410
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x10067420
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100674B0
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100676A0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x100676C0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067700
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10067760
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x100677B0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x100677D0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067860
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x10067870
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x100678A0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x10067900
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067930
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x10067940
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100679C0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10067AF0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067C20
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x10067C90
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067D30
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067DC0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067E50
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067EF0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand_2(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10081FF0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100857A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100857D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x100857E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004385C0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x004385D0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438610
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00438780
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004387C0
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x004387F0
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x00438800
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x00438810
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00438830
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00438880
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00438900
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438980
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438A10
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00438A30
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00438A50
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00438A70
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00438A80
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00438A90
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00438AB0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00438AD0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00438B10
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00438B50
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00438B60
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00438BA0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00438BC0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438C40
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x00438C80
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x00438CC0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438DD0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438E10
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438E40
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00438E50
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00438EE0
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004390D0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x004390F0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439130
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00439190
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x004391E0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00439200
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439290
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x004392A0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x004392D0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00439330
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439360
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00439370
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439420
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00439550
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439680
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x004396F0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439790
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439820
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004398B0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVGUI_Src_Editor_Dialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439950
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00453FA0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00457730
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00457770
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045A3D0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00481E10
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x00481E60
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  vgui::IScheme_vtbl *v5; // ebp
  int v6; // eax
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // ebp
  Color *v12; // eax
  vgui::ComboBoxButton_vtbl *v13; // ebx
  Color *v14; // ebp
  Color *v15; // eax
  vgui::ComboBoxButton_vtbl *v16; // ebx
  Color *v17; // ebp
  Color *v18; // eax
  char v19[4]; // [esp+78h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = v2->__vftable;
  v6 = ((int (__thiscall *)(vgui::ComboBoxButton *))this->IsProportional)(a1: this);
  v7 = v5->GetFont(this: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  v11 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v12 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v10->SetDefaultColor)(a1: this, a2: *v12, a3: *v11);
  v13 = this->__vftable;
  v14 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v13->SetArmedColor)(a1: this, a2: *v15, a3: *v14);
  v16 = this->__vftable;
  v17 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ComboBoxButton.BgColor", a4: v2);
  v18 = this->GetSchemeColor_2(this, result: v19, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, _DWORD))v16->SetDepressedColor)(a1: this, a2: *v18, a3: *v17);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00481FC0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482000
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482030
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x00482040
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x00482050
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x00482060
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00482070
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x004820C0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+8h] [ebp-84h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: &ansi[4], a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: &ansi[4], a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00482150
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004821D0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482260
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00482270
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00482280
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00482290
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x004822A0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x004822B0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x004822C0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00482300
// Name: private: void vgui::ComboBox::DoMenuLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::DoMenuLayout(vgui::ComboBox *this)
{
  vgui::Menu_vtbl *v2; // edi
  int Wide; // eax

  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v2 = this->m_pDropDown->__vftable;
  Wide = vgui::Panel::GetWide(this);
  v2->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00482380
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00482390
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004823C0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004823D0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        ButtonCode_t code)
{
  bool v6; // zf
  vgui::ComboBox_vtbl *v7; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v6 = !this->IsCursorOver(this);
    v7 = this->__vftable;
    if ( v6 )
    {
      v7->HideMenu(this);
    }
    else if ( v7->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, a4, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482450
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x00482480
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x004824C0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char cbuf[255]; // [esp+8h] [ebp-304h] BYREF
  unsigned __int16 wbuf[258]; // [esp+108h] [ebp-204h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: &cbuf[4], a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[5]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: &wbuf[2], a3: 254);
  if ( wcscmp(&wbuf[2], v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x004825D0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482610
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482640
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482650
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004826E0
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  void (__thiscall **p_SetFixedWidth)(vgui::Menu *, int); // edi
  int Wide; // eax
  unsigned __int16 comboBoxContents[256]; // [esp+10h] [ebp-404h] BYREF
  wchar_t menuItemName[258]; // [esp+210h] [ebp-204h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: &comboBoxContents[4], a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: &menuItemName[4], a3: 255);
        if ( wcscmp(&menuItemName[4], &comboBoxContents[4]) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    p_SetFixedWidth = &this->m_pDropDown->SetFixedWidth;
    Wide = vgui::Panel::GetWide(this);
    (*p_SetFixedWidth)(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004828E0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482900
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482940
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[258]; // [esp+0h] [ebp-204h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: &name[2], bufLenInBytes: 512);
    this->OnSetText(this, a2: &name[2]);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x004829A0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x004829F0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00482A10
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[258]; // [esp+8h] [ebp-204h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: &menuItemName[2], a3: 254);
    this->OnSetText(this, a2: &menuItemName[2]);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482AA0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00482AB0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00482AE0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00482B50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482B80
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00482B90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482C00
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  int v9; // eax
  int tall; // [esp+14h] [ebp-10h] BYREF
  int wide; // [esp+18h] [ebp-Ch] BYREF
  int button_tall; // [esp+1Ch] [ebp-8h] BYREF
  _BYTE v13[4]; // [esp+20h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &button_tall, a3: &wide);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( wide < v3 )
    v3 = wide;
  v4 = wide - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &tall, a3: (int *)v13);
  v5 = tall;
  if ( v3 > tall )
  {
    v5 = v3;
    tall = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: button_tall - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = ((int (__thiscall *)(vgui::ComboBox *))this->IsEnabled)(a1: this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  vgui::ComboBox::DoMenuLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482CF0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482E10
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00482E80
// Name: public: static void vgui::ComboBox::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ComboBox::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00482F00
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "ActivateItem",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "itemID",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482F60
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "MenuClose",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482FC0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "MenuItemSelected",
      function: (unsigned int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483020
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    vgui::ComboBox::AddToMap(
      scriptname: "SetText",
      function: (unsigned int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)7,
      p1name: "text",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483080
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar();
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iDirection = 3;
  this->m_iOpenOffsetY = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049C7E0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int x; // [esp+14h] [ebp-10h] BYREF
  int cx0; // [esp+18h] [ebp-Ch] BYREF
  int cx1; // [esp+1Ch] [ebp-8h] BYREF
  int v7; // [esp+20h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cx0, a3: &x);
  vgui::Panel::ScreenToLocal(this, x: &cx0, y: &x);
  v2 = this->PixelToCursorSpace(this, a2: cx0, a3: x);
  if ( this->GetSelectedRange(this, a2: &cx1, a3: &v7) && v2 >= cx1 && v2 < v7 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004A0070
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A00A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x004A00B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00426EF0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x00426F00
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426F40
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004270B0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004270F0
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427120
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x00427130
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x00427140
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x00427160
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x004271B0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x00427230
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004272B0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427340
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x00427360
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x00427380
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x004273A0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x004273B0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x004273C0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x004273E0
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x00427400
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00427470
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00427480
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004274C0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004274E0
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427560
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x004275A0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x004275E0
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x004276F0
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427730
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427760
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427770
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427800
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004279F0
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427A10
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427A50
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427AB0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x00427B00
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x00427B20
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427BB0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x00427BC0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00427BF0
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x00427C50
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427C80
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x00427C90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427D10
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x00427E40
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427F70
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00427FF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428090
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428120
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004281B0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428250
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00442540
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00445D00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445D30
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x00445D40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448970
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0042A8F0
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x0042A900
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A940
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0042AAC0
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AB00
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042AB30
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x0042AB40
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x0042AB50
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x0042AB60
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x0042AB80
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x0042ABD0
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, const wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x0042AC50
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const char *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042ACD0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        const wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD60
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0042AD80
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x0042ADA0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x0042ADC0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0042ADD0
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0042ADE0
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x0042AE00
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x0042AE20
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x0042AE90
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0042AEA0
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0042AEE0
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0042AF00
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AF80
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x0042AFC0
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x0042B000
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, const wchar_t *newtext)
{
  const wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B110
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B150
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B180
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B190
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B220
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B410
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B430
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B470
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B4D0
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x0042B520
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042B540
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B5D0
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x0042B5E0
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0042B610
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x0042B670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B6A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x0042B6B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B760
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x0042B890
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B9C0
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x0042BA30
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BAD0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BB60
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BBF0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BC90
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A0660
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x103A0670
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A06B0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103A0820
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0860
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A0890
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x103A08B0
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x103A0900
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x103A0980
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A0A00
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A0A90
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x103A0AB0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x103A0AD0
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x103A0AF0
// Name: public: void vgui::ComboBox::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::RemoveAll(vgui::ComboBox *this)
{
  vgui::Menu::DeleteAllItems(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103A0B00
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103A0B10
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x103A0B30
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x103A0B50
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x103A0B90
// Name: public: int vgui::ComboBox::GetActiveItem(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetActiveItem(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetActiveItem(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103A0BE0
// Name: public: void vgui::ComboBox::GetItemText(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, wchar_t *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x103A0BF0
// Name: public: void vgui::ComboBox::GetItemText(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::GetItemText(vgui::ComboBox *this, int itemID, char *text, int bufLenInBytes)
{
  vgui::Menu::GetItemText(this: this->m_pDropDown, itemID, text, bufLenInBytes);
}

//------------------------------------------------------------------------------
// Address: 0x103A0C00
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103A0C10
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103A0C50
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103A0C70
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::ComboBox::OnMousePressed(
        vgui::ComboBox *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        ButtonCode_t code)
{
  bool v5; // zf
  vgui::ComboBox_vtbl *v6; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v5 = !this->IsCursorOver(this);
    v6 = this->__vftable;
    if ( v5 )
    {
      v6->HideMenu(this);
    }
    else if ( v6->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, a2, a3, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0CF0
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x103A0D30
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x103A0D70
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A0E80
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0EC0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0EF0
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A0F00
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A0F90
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1180
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A11A0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A11E0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A1240
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x103A1290
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x103A12B0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1340
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x103A1350
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x103A1380
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x103A14D0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103A1600
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1730
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x103A17A0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ActivateItem";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1840
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuClose";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A18D0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MenuItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1960
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SetText";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x700000001LL;
    LODWORD(v4.m[2][2]) = "text";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A1A00
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar();
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar();
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10398A90
// Name: public: static char const __near * vgui::ComboBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ComboBox::GetPanelClassName()
{
  return "ComboBox";
}

//------------------------------------------------------------------------------
// Address: 0x10398AA0
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398AE0
// Name: public: virtual void vgui::ComboBoxButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::ApplySchemeSettings(vgui::ComboBoxButton *this, Color *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::ComboBoxButton_vtbl *v4; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v6; // al
  int v7; // eax
  vgui::ComboBoxButton_vtbl *v8; // ebx
  int v9; // eax
  vgui::ComboBoxButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::ComboBoxButton_vtbl *v12; // ebx
  Color *v13; // eax
  vgui::ComboBoxButton_vtbl *v14; // ebx
  Color *v15; // eax
  _BYTE v16[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v17[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::Button::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (Color *)v2->__vftable;
  v6 = IsProportional(this);
  v7 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3])(a1: v2, a2: "Marlett", a3: v6);
  v4->SetFont(this, a2: v7);
  this->SetContentAlignment(this, a2: a_west);
  this->SetTextInset(this, a2: 3, a3: 0);
  v8 = this->__vftable;
  v9 = (int)v2->GetBorder(this: v2, a2: "ScrollBarButtonBorder");
  v8->SetDefaultBorder(this, a2: (vgui::IBorder *)v9);
  v10 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.BgColor", a4: v2);
  v11 = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.ArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v12 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v13 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v12->SetArmedColor)(
    a1: this,
    a2: *v13,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  v14 = this->__vftable;
  pScheme = this->GetSchemeColor_2(this, result: v16, a3: "ComboBoxButton.BgColor", a4: v2);
  v15 = this->GetSchemeColor_2(this, result: v17, a3: "ComboBoxButton.ArmedArrowColor", a4: v2);
  ((void (__thiscall *)(vgui::ComboBoxButton *, _DWORD, vgui::IScheme_vtbl *))v14->SetDepressedColor)(
    a1: this,
    a2: *v15,
    a3: *(vgui::IScheme_vtbl **)pScheme);
  this->m_DisabledBgColor = *this->GetSchemeColor_2(
                               this,
                               result: &pScheme,
                               a3: "ComboBoxButton.DisabledBgColor",
                               a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10398C50
// Name: public: virtual void vgui::ComboBoxButton::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBoxButton::OnCursorExited(vgui::ComboBoxButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CursorExited");
    vgui::Panel::CallParentFunction(this, message: v3);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398C90
// Name: public: virtual vgui::ComboBox::~ComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::~ComboBox(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  m_pDropDown->DeletePanel(this: m_pDropDown);
  this->m_pButton->DeletePanel(this: this->m_pButton);
  vgui::TextEntry::~TextEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10398CC0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x10398CD0
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10398CE0
// Name: public: virtual class vgui::Menu __near * vgui::ComboBox::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::ComboBox::GetMenu(vgui::ComboBox *this)
{
  return this->m_pDropDown;
}

//------------------------------------------------------------------------------
// Address: 0x10398CF0
// Name: public: virtual void vgui::ComboBox::SetNumberOfEditLines(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetNumberOfEditLines(vgui::ComboBox *this, int numLines)
{
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
}

//------------------------------------------------------------------------------
// Address: 0x10398D10
// Name: public: virtual int vgui::ComboBox::AddItem(char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, char *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText", firstKey: "text", firstValue: itemText);
  else
    v5 = nullptr;
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: itemText, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10398D60
// Name: public: virtual int vgui::ComboBox::AddItem(wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::AddItem(vgui::ComboBox *this, wchar_t *itemText, const KeyValues *userData)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  char ansi[128]; // [esp+Ch] [ebp-80h] BYREF

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SetText");
  else
    v5 = nullptr;
  KeyValues::SetWString(this: v5, keyName: "text", value: itemText);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: itemText, a3: ansi, a4: 128);
  return this->m_pDropDown->AddMenuItem(this: this->m_pDropDown, a2: ansi, a3: v5, a4: this, a5: userData);
}

//------------------------------------------------------------------------------
// Address: 0x10398DE0
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,char const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(vgui::ComboBox *this, int itemID, char *itemText, const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText", firstKey: "text", firstValue: itemText);
    else
      v7 = nullptr;
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398E60
// Name: public: virtual bool vgui::ComboBox::UpdateItem(int,wchar_t const __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::UpdateItem(
        vgui::ComboBox *this,
        int itemID,
        wchar_t *itemText,
        const KeyValues *userData)
{
  bool result; // al
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  result = this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
  if ( result )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "SetText");
    else
      v7 = nullptr;
    KeyValues::SetWString(this: v7, keyName: "text", value: itemText);
    this->m_pDropDown->UpdateMenuItem(this: this->m_pDropDown, a2: itemID, a3: itemText, a4: v7, a5: userData);
    this->InvalidateLayout(this, a2: false, a3: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398EF0
// Name: public: virtual bool vgui::ComboBox::IsItemIDValid(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsItemIDValid(vgui::ComboBox *this, int itemID)
{
  return this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10398F10
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, const char *itemText, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemText, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10398F30
// Name: public: virtual void vgui::ComboBox::SetItemEnabled(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetItemEnabled(vgui::ComboBox *this, int itemID, BOOL state)
{
  this->m_pDropDown->SetItemEnabled(this: this->m_pDropDown, a2: itemID, a3: state);
}

//------------------------------------------------------------------------------
// Address: 0x10398F50
// Name: public: virtual int vgui::ComboBox::GetItemCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ComboBox::GetItemCount(vgui::ComboBox *this)
{
  return this->m_pDropDown->GetItemCount(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10398F60
// Name: public: virtual void vgui::ComboBox::ActivateItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItem(vgui::ComboBox *this, int itemID)
{
  this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: itemID);
}

//------------------------------------------------------------------------------
// Address: 0x10398F80
// Name: public: void vgui::ComboBox::ActivateItemByRow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ActivateItemByRow(vgui::ComboBox *this, int row)
{
  this->m_pDropDown->ActivateItemByRow(this: this->m_pDropDown, a2: row);
}

//------------------------------------------------------------------------------
// Address: 0x10398FA0
// Name: public: virtual void vgui::ComboBox::SetMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetMenu(vgui::ComboBox *this, vgui::Menu *menu)
{
  vgui::Menu *m_pDropDown; // ecx

  m_pDropDown = this->m_pDropDown;
  if ( m_pDropDown != nullptr )
    m_pDropDown->MarkForDeletion(this: m_pDropDown);
  this->m_pDropDown = menu;
  if ( menu != nullptr )
    menu->SetParent_2(this: menu, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10399010
// Name: public: virtual bool vgui::ComboBox::IsDropdownVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ComboBox::IsDropdownVisible(vgui::ComboBox *this)
{
  return this->m_pDropDown->IsVisible(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x10399020
// Name: protected: virtual void vgui::ComboBox::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ApplySchemeSettings(vgui::ComboBox *this, vgui::IScheme *pScheme)
{
  vgui::ComboBox_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "ComboBoxBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10399060
// Name: public: virtual void vgui::ComboBox::SetDropdownButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetDropdownButtonVisible(vgui::ComboBox *this, BOOL state)
{
  this->m_pButton->SetVisible(this: this->m_pButton, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10399080
// Name: protected: virtual void vgui::ComboBox::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMousePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  bool v3; // zf
  vgui::ComboBox_vtbl *v4; // eax

  if ( this->m_pDropDown != nullptr && this->IsEnabled(this) )
  {
    v3 = !this->IsCursorOver(this);
    v4 = this->__vftable;
    if ( v3 )
    {
      v4->HideMenu(this);
    }
    else if ( v4->IsEditable(this) )
    {
      vgui::TextEntry::OnMousePressed(this, code);
      this->HideMenu(this);
    }
    else
    {
      this->RequestFocus(this, a2: 0);
      this->DoClick(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399100
// Name: protected: virtual void vgui::ComboBox::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMouseDoublePressed(vgui::ComboBox *this, ButtonCode_t code)
{
  if ( this->IsEditable(this) )
    vgui::TextEntry::OnMouseDoublePressed(this, code);
  else
    this->OnMousePressed(this, a2: code);
}

//------------------------------------------------------------------------------
// Address: 0x10399140
// Name: protected: virtual void vgui::ComboBox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCommand(vgui::ComboBox *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "ButtonClicked") == 0 )
    this->DoClick(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10399180
// Name: protected: virtual void vgui::ComboBox::OnSetText(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetText(vgui::ComboBox *this, wchar_t *newtext)
{
  wchar_t *v3; // edi
  unsigned int v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned __int16 wbuf[256]; // [esp+8h] [ebp-300h] BYREF
  char cbuf[255]; // [esp+208h] [ebp-100h] BYREF

  v3 = newtext;
  if ( *newtext == 35 )
  {
    g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: newtext, a3: cbuf, a4: 255);
    v4 = g_pVGuiLocalize->FindIndex(this: g_pVGuiLocalize, a2: &cbuf[1]);
    if ( v4 != -1 )
      v3 = g_pVGuiLocalize->GetValueByIndex(this: g_pVGuiLocalize, a2: v4);
  }
  this->GetText(this, a2: wbuf, a3: 254);
  if ( wcscmp(wbuf, v3) != 0 )
  {
    this->SetText_2(this, a2: v3);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "TextChanged", firstKey: "text", firstValue: v3);
    else
      v6 = nullptr;
    this->PostActionSignal(this, a2: v6);
    this->Repaint(this);
  }
  this->HideMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x10399290
// Name: public: virtual void vgui::ComboBox::HideMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::HideMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->Repaint(this);
    this->OnHideMenu(this, a2: this->m_pDropDown);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103992D0
// Name: public: virtual void vgui::ComboBox::ShowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::ShowMenu(vgui::ComboBox *this)
{
  if ( this->m_pDropDown != nullptr )
  {
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: false);
    this->DoClick(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399300
// Name: public: virtual void vgui::ComboBox::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::ComboBox::OnKillFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::SelectNoText(this);
}

//------------------------------------------------------------------------------
// Address: 0x10399310
// Name: public: virtual void vgui::ComboBox::OnMenuClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuClose(vgui::ComboBox *this)
{
  vgui::ComboBox_vtbl *v2; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  this->HideMenu(this);
  if ( this->HasFocus(this) )
  {
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
  else
  {
    v2 = this->__vftable;
    if ( this->m_bHighlight )
    {
      RequestFocus = v2->RequestFocus;
      this->m_bHighlight = false;
      ((void (__stdcall *)(_DWORD))RequestFocus)(a1: 0);
    }
    else if ( ((unsigned __int8 (__fastcall *)(vgui::ComboBox *))v2->IsCursorOver)(a1: this) != 0 )
    {
      vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
      this->OnCursorEntered(this);
      this->RequestFocus(this, a2: 0);
    }
    else
    {
      this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103993A0
// Name: public: virtual void vgui::ComboBox::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::ComboBox::DoClick(vgui::ComboBox *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::MenuItem *MenuItem; // eax
  int v6; // eax
  vgui::Menu_vtbl *v7; // edi
  int Wide; // eax
  wchar_t menuItemName[256]; // [esp+4h] [ebp-400h] BYREF
  unsigned __int16 comboBoxContents[256]; // [esp+204h] [ebp-200h] BYREF

  if ( this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->HideMenu(this);
  }
  else if ( this->m_pDropDown->IsEnabled(this: this->m_pDropDown) )
  {
    ((void (__thiscall *)(vgui::Menu *, int))this->m_pDropDown->PerformLayout)(a1: this->m_pDropDown, a2);
    this->GetText(this, a2: comboBoxContents, a3: 255);
    v3 = 0;
    if ( this->m_pDropDown->GetItemCount(this: this->m_pDropDown) > 0 )
    {
      while ( 1 )
      {
        v4 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v4);
        MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 255);
        if ( wcscmp(menuItemName, comboBoxContents) == 0 )
          break;
        if ( ++v3 >= this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
          goto LABEL_10;
      }
      if ( v3 >= 0 )
      {
        v6 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: v3);
        vgui::Menu::SetCurrentlyHighlightedItem(this: this->m_pDropDown, itemID: v6);
      }
    }
LABEL_10:
    ((void (__thiscall *)(vgui::Menu *, vgui::ComboBox *, vgui::Menu::MenuDirection_e, int))this->m_pDropDown->PositionRelativeToPanel)(
      a1: this->m_pDropDown,
      a2: this,
      a3: this->m_iDirection,
      a4: this->m_iOpenOffsetY);
    v7 = this->m_pDropDown->__vftable;
    Wide = vgui::Panel::GetWide(this);
    v7->SetFixedWidth(this: this->m_pDropDown, a2: Wide);
    vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
    this->MoveToFront(this);
    this->OnShowMenu(this, a2: this->m_pDropDown);
    this->m_pDropDown->SetVisible(this: this->m_pDropDown, a2: true);
    this->m_pDropDown->RequestFocus(this: this->m_pDropDown, a2: 0);
    vgui::TextEntry::SelectNoText(this);
    this->m_pButton->SetArmed(this: this->m_pButton, a2: true);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399590
// Name: protected: virtual void vgui::ComboBox::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorEntered(vgui::ComboBox *this)
{
  this->m_pButton->OnCursorEntered(this: this->m_pButton);
  vgui::TextEntry::OnCursorEntered(this);
}

//------------------------------------------------------------------------------
// Address: 0x103995B0
// Name: protected: virtual void vgui::ComboBox::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnCursorExited(vgui::ComboBox *this)
{
  if ( !this->m_pDropDown->IsVisible(this: this->m_pDropDown) )
  {
    this->m_pButton->SetArmed(this: this->m_pButton, a2: false);
    vgui::TextEntry::OnCursorExited(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103995F0
// Name: protected: virtual void vgui::ComboBox::OnMenuItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnMenuItemSelected(vgui::ComboBox *this)
{
  vgui::Menu *m_pDropDown; // ecx
  int v3; // eax
  wchar_t name[256]; // [esp+4h] [ebp-200h] BYREF

  m_pDropDown = this->m_pDropDown;
  this->m_bHighlight = true;
  v3 = m_pDropDown->GetActiveItem(this: m_pDropDown);
  if ( v3 >= 0 )
  {
    vgui::Menu::GetItemText(this: this->m_pDropDown, itemID: v3, text: name, bufLenInBytes: 512);
    this->OnSetText(this, a2: name);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10399650
// Name: public: virtual void vgui::ComboBox::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSizeChanged(vgui::ComboBox *this, int wide, int tall)
{
  int v3; // edi

  v3 = wide;
  vgui::TextEntry::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->PerformLayout(this);
  vgui::Panel::GetSize(this: this->m_pButton, wide: &tall, tall: &wide);
  vgui::TextEntry::SetDrawWidth(this, width: v3 - tall);
}

//------------------------------------------------------------------------------
// Address: 0x103996A0
// Name: protected: virtual void vgui::ComboBox::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnSetFocus(vgui::ComboBox *this)
{
  vgui::TextEntry::OnSetFocus(this);
  this->GotoTextEnd(this);
  vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
}

//------------------------------------------------------------------------------
// Address: 0x103996C0
// Name: protected: void vgui::ComboBox::SelectMenuItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SelectMenuItem(vgui::ComboBox *this, int itemToSelect)
{
  int v3; // eax
  vgui::MenuItem *MenuItem; // eax
  wchar_t menuItemName[256]; // [esp+8h] [ebp-200h] BYREF

  if ( itemToSelect >= 0 && itemToSelect < this->m_pDropDown->GetItemCount(this: this->m_pDropDown) )
  {
    v3 = this->m_pDropDown->GetMenuID(this: this->m_pDropDown, a2: itemToSelect);
    MenuItem = vgui::Menu::GetMenuItem(this: this->m_pDropDown, itemID: v3);
    MenuItem->GetText(this: MenuItem, a2: menuItemName, a3: 254);
    this->OnSetText(this, a2: menuItemName);
    vgui::TextEntry::SelectAllText(this, bResetCursorPos: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399750
// Name: public: virtual void vgui::ComboBox::SetOpenDirection(enum vgui::Menu::MenuDirection_e)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetOpenDirection(vgui::ComboBox *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x10399760
// Name: public: virtual void vgui::ComboBox::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetFont(vgui::ComboBox *this, unsigned int font)
{
  vgui::TextEntry::SetFont(this, font);
  this->m_pDropDown->SetFont(this: this->m_pDropDown, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10399790
// Name: public: virtual void vgui::ComboBox::SetUseFallbackFont(bool,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::SetUseFallbackFont(vgui::ComboBox *this, bool bState, unsigned int hFallback)
{
  vgui::TextEntry::SetUseFallbackFont(this, bState, hFallback);
  vgui::Menu::SetUseFallbackFont(this: this->m_pDropDown, bState, hFallback);
}

//------------------------------------------------------------------------------
// Address: 0x10399800
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ComboBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ComboBox::GetMessageMap(vgui::ComboBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ComboBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetMessageMap'::`2'::s_pMap;
  `vgui::ComboBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
  `vgui::ComboBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10399830
// Name: public: virtual struct PanelAnimationMap __near * vgui::ComboBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ComboBox::GetAnimMap(vgui::ComboBox *this)
{
  return FindOrAddPanelAnimationMap(className: "ComboBox");
}

//------------------------------------------------------------------------------
// Address: 0x10399840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ComboBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ComboBox::GetKBMap(vgui::ComboBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ComboBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ComboBox::GetKBMap'::`2'::s_pMap;
  `vgui::ComboBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
  `vgui::ComboBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103998C0
// Name: public: virtual void vgui::ComboBox::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::PerformLayout(vgui::ComboBox *this)
{
  unsigned int v2; // eax
  int v3; // edi
  int v4; // kr00_4
  int v5; // eax
  bool v6; // zf
  void (__thiscall *SetCursor)(vgui::Panel *, unsigned int); // eax
  vgui::ComboBoxButton_vtbl *v8; // edi
  bool v9; // al
  vgui::Menu_vtbl *v10; // edi
  int v11; // eax
  int button_tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int tall; // [esp+10h] [ebp-8h] BYREF
  int button_wide; // [esp+14h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  vgui::TextEntry::PerformLayout(this);
  v2 = this->m_pButton->GetFont(this: this->m_pButton);
  v3 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v2);
  if ( tall < v3 )
    v3 = tall;
  v4 = tall - v3 - 1;
  this->m_pButton->GetContentSize(this: this->m_pButton, a2: &button_wide, a3: &button_tall);
  v5 = button_wide;
  if ( v3 > button_wide )
  {
    v5 = v3;
    button_wide = v3;
  }
  vgui::Panel::SetBounds(this: this->m_pButton, x: wide - v5, y: v4 / 2, wide: v5, tall: v3);
  v6 = !this->IsEditable(this);
  SetCursor = this->SetCursor;
  if ( v6 )
    ((void (__stdcall *)(int))SetCursor)(a1: 2);
  else
    ((void (__stdcall *)(int))SetCursor)(a1: 3);
  v8 = this->m_pButton->__vftable;
  v9 = this->IsEnabled(this);
  v8->SetEnabled(this: this->m_pButton, a2: v9);
  this->m_pDropDown->PositionRelativeToPanel(
    this: this->m_pDropDown,
    a2: this,
    a3: this->m_iDirection,
    a4: this->m_iOpenOffsetY,
    a5: false);
  v10 = this->m_pDropDown->__vftable;
  v11 = vgui::Panel::GetWide(this);
  v10->SetFixedWidth(this: this->m_pDropDown, a2: v11);
  vgui::Menu::ForceCalculateWidth(this: this->m_pDropDown);
}

//------------------------------------------------------------------------------
// Address: 0x103999F0
// Name: protected: virtual void vgui::ComboBox::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyCodeTyped(vgui::ComboBox *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // eax
  int CurrentlyHighlightedItem; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
  {
    if ( code == KEY_UP || code == KEY_DOWN )
      this->DoClick(this);
    else
      vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
  else
  {
    switch ( code )
    {
      case KEY_ENTER:
        CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( !this->m_pDropDown->IsValidMenuID(this: this->m_pDropDown, a2: CurrentlyHighlightedItem) )
          goto LABEL_12;
        this->m_pDropDown->ActivateItem(this: this->m_pDropDown, a2: CurrentlyHighlightedItem);
        break;
      case KEY_HOME:
      case KEY_END:
      case KEY_PAGEUP:
      case KEY_PAGEDOWN:
      case KEY_UP:
      case KEY_DOWN:
        v3 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        this->m_pDropDown->OnKeyCodeTyped(this: this->m_pDropDown, a2: code);
        v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
        if ( v4 != v3 )
          vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
        break;
      default:
LABEL_12:
        vgui::TextEntry::OnKeyCodeTyped(this, code);
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399B20
// Name: protected: virtual void vgui::ComboBox::OnKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ComboBox::OnKeyTyped(vgui::ComboBox *this, int unichar)
{
  int CurrentlyHighlightedItem; // edi
  int v4; // eax
  vgui::ComboBox *v5; // ecx

  if ( this->IsEditable(this) || (_WORD)unichar == 9 )
  {
    v5 = this;
  }
  else
  {
    CurrentlyHighlightedItem = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    this->m_pDropDown->OnKeyTyped(this: this->m_pDropDown, a2: unichar);
    v4 = vgui::Menu::GetCurrentlyHighlightedItem(this: this->m_pDropDown);
    v5 = this;
    if ( v4 != CurrentlyHighlightedItem )
    {
      vgui::ComboBox::SelectMenuItem(this, itemToSelect: v4);
      return;
    }
  }
  vgui::TextEntry::OnKeyTyped(this: v5, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x10399B90
// Name: public: static void vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1204,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ActivateItem";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399C30
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1224,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuClose";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399CC0
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ComboBox::`vcall'{1240,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "MenuItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399D50
// Name: public: static void vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded )
  {
    `vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "SetText";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTWCHARPTR;
    v4.firstParamName = "text";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10399DF0
// Name: public: vgui::ComboBox::ComboBox(class vgui::Panel __near *,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ComboBox *__thiscall vgui::ComboBox::ComboBox(
        vgui::ComboBox *this,
        vgui::Panel *parent,
        const char *panelName,
        int numLines,
        bool allowEdit)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Menu *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::ComboBoxButton *v13; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName);
  this->__vftable = (vgui::ComboBox_vtbl *)&vgui::ComboBox::`vftable';
  if ( `vgui::ComboBox::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "ComboBox");
    v6->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "ComboBox");
    v7->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `vgui::ComboBox::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ComboBox::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "ComboBox");
    v8->pfnClassName = vgui::ComboBox::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  vgui::ComboBox::PanelMessageFunc_ActivateItem::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuClose::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  vgui::ComboBox::PanelMessageFunc_OnSetText::InitVar(a1: (int)&savedregs);
  vgui::TextEntry::SetEditable(this, state: allowEdit);
  vgui::TextEntry::SetHorizontalScrolling(this, status: false);
  v9 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v9 != nullptr )
    v10 = vgui::Menu::Menu(this: v9, parent: this, panelName: nullptr);
  else
    v10 = nullptr;
  this->m_pDropDown = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->m_pDropDown->SetTypeAheadMode(this: this->m_pDropDown, a2: TYPE_AHEAD_MODE);
  v11 = (vgui::Button *)operator new(nSize: 0x1F8u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    vgui::Button::Button(
      this: v11,
      parent: this,
      panelName: nullptr,
      text: "u",
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
    v12->__vftable = (vgui::Button_vtbl *)&vgui::ComboBoxButton::`vftable';
    v12[1].__vftable = nullptr;
    vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
    v13 = (vgui::ComboBoxButton *)v12;
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pButton = v13;
  v13->SetCommand(this: v13, a2: "ButtonClicked");
  this->m_pButton->AddActionSignalTarget_2(this: this->m_pButton, a2: this);
  this->m_pDropDown->SetNumberOfVisibleItems(this: this->m_pDropDown, a2: numLines);
  this->m_bHighlight = false;
  this->m_iOpenOffsetY = 0;
  this->m_iDirection = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B3EA0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103B7660
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B7690
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x103B76A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace server
