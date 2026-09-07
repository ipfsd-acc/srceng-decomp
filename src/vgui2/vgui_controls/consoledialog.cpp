// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/consoledialog.cpp
// Functions: 43
// ============================================================

#include "vgui2\vgui_controls\consoledialog.h"

//------------------------------------------------------------------------------
// Address: 0x10038EF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10066940
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10066950
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x10066960
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066A00
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066A60
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  free(pMem: this->m_text);
  v4 = strlen(text);
  v5 = (char *)operator new(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: (int)v5, fill: nullptr, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    free(pMem: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)operator new(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: (int)v7, fill: nullptr, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066B10
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = defaultValue;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x10066B80
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x10066BC0
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: defaultValue);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10066C10
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10066C30
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10066C50
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(char *partial@<eax>, int a2@<esi>)
{
  _BYTE *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066CC0
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = _V_strlen(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = _V_strlen(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = _V_strlen(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066DB0
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066E70
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10066E90
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10066FD0
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067050
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)operator new(nSize: 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  free(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100670E0
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100671B0
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100671D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067200
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x10067210
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10067270
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100672A0
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x100672E0
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067500
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x100675F0
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067660
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100678E0
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067A50
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        free(pMem: *p_m_text);
        free(pMem: p_m_text[1]);
        *p_m_text = nullptr;
        free(pMem: p_m_text);
        v3->m_pText = nullptr;
      }
      free(pMem: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067B80
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067C20
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "CloseCompletionList";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067CB0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "CompletionCommand";
    v4.func = v2;
    v4.firstParamName = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10067D50
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)operator new(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)operator new(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)operator new(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10068090
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100680C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100680D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10068100
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100681D0
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::CompletionItem *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  char **v4; // ebx
  vgui::CConsolePanel::CompletionItem *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel::CompletionItem **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  char *v13; // eax
  vgui::CConsolePanel *v14; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  vgui::CConsolePanel *v19; // eax
  ICvar::ICVarIteratorInternal *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  ICvar::ICVarIteratorInternal **v25; // esi
  ICvar::ICVarIteratorInternal_vtbl *v26; // esi
  char *v27; // edi
  unsigned int v28; // kr00_4
  void (__thiscall *v29)(ICvar::ICVarIteratorInternal *); // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  vgui::CConsolePanel::CompletionItem *v35; // eax
  vgui::CConsolePanel *v36; // esi
  int m_Size; // ebx
  int v38; // eax
  vgui::CConsolePanel::CompletionItem **v39; // ecx
  int v40; // eax
  vgui::CConsolePanel::CompletionItem **v41; // ebx
  vgui::CConsolePanel::CompletionItem *v42; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  vgui::CHistoryItem *v51; // esi
  char *v52; // eax
  vgui::CHistoryItem *v53; // eax
  vgui::CHistoryItem *v54; // esi
  unsigned int v55; // kr04_4
  char *v56; // eax
  char v57; // [esp+10h] [ebp-238h]
  char *v58; // [esp+10h] [ebp-238h]
  char strValue[512]; // [esp+20h] [ebp-228h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+220h] [ebp-28h] BYREF
  float v61; // [esp+234h] [ebp-14h]
  char *bCheckSubstrings; // [esp+238h] [ebp-10h]
  vgui::CConsolePanel *v63; // [esp+23Ch] [ebp-Ch]
  ICvar::Iterator iter; // [esp+240h] [ebp-8h]
  vgui::CConsolePanel::CompletionItem *item; // [esp+244h] [ebp-4h]
  vgui::CConsolePanel::CompletionItem *comp; // [esp+250h] [ebp+8h]
  vgui::CConsolePanel::CompletionItem *compa; // [esp+250h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  v63 = this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)_V_strlen(str: (const char *)&text->m_bIsCommand) < 1 )
  {
    iter.m_pIter = nullptr;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      item = nullptr;
      while ( 1 )
      {
        v4 = (char **)(&item->m_bIsCommand + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          v5->m_bIsCommand = true;
          v5->m_pCommand = nullptr;
          v5->m_pText = nullptr;
          comp = v5;
        }
        else
        {
          comp = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<unsigned long,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel::CompletionItem **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = comp;
        comp->m_bIsCommand = false;
        comp->m_pCommand = nullptr;
        v11 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = (char *)defaultValue;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        v14 = v63;
        ++item;
        comp->m_pText = v12;
        if ( (int)++iter.m_pIter >= v14->m_CommandHistory.m_Size )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)v14;
      }
    }
    return;
  }
  LOBYTE(bCheckSubstrings) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(
                                        partial: (char *)&text->m_bIsCommand,
                                        a2: (int)text);
    m_pIter = nullptr;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&commands, 0, sizeof(commands));
      v19 = (vgui::CConsolePanel *)AutoCompleteSuggest(
                                     this: AutoCompleteCommmandFromPartial,
                                     a2: (const char *)&text->m_bIsCommand,
                                     a3: &commands);
      if ( (int)v19 > 0 )
      {
        compa = nullptr;
        v63 = v19;
        while ( 1 )
        {
          v20 = (ICvar::ICVarIteratorInternal *)operator new(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1].__vftable = nullptr;
            v20[2].__vftable = nullptr;
            LOBYTE(v20->__vftable) = 1;
            m_pIter = v20;
            iter.m_pIter = v20;
          }
          else
          {
            iter.m_pIter = nullptr;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<unsigned long,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (ICvar::ICVarIteratorInternal **)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_pIter;
          LOBYTE(m_pIter->__vftable) = 0;
          m_pIter[1].__vftable = nullptr;
          v26 = (ICvar::ICVarIteratorInternal_vtbl *)operator new(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = (char *)CUtlString::operator char const *(this: (CUtlString *)(&compa->m_bIsCommand
                                                                               + (unsigned int)commands.m_Memory.m_pMemory));
            bCheckSubstrings = v27;
            v26->SetFirst = nullptr;
            v26->Next = nullptr;
            LOBYTE(v26->IsValid) = 0;
            free(pMem: nullptr);
            v28 = strlen(v27);
            v29 = (void (__thiscall *)(ICvar::ICVarIteratorInternal *))operator new(nSize: v28 + 1);
            v26->SetFirst = v29;
            _V_memset(dest: (int)v29, fill: nullptr, count: v28 + 1);
            V_strncpy(pDest: (char *)v26->SetFirst, pSrc: bCheckSubstrings, maxLen: v28 + 1);
            m_pIter = iter.m_pIter;
            LOBYTE(v26->IsValid) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          compa = (vgui::CConsolePanel::CompletionItem *)((char *)compa + 16);
          v30 = v63 == (vgui::CConsolePanel *)1;
          v63 = (vgui::CConsolePanel *)((char *)v63 - 1);
          m_pIter[2].__vftable = v26;
          if ( v30 )
            break;
          m_pIter = nullptr;
        }
      }
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &commands);
      return;
    }
    LOBYTE(bCheckSubstrings) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  iter.m_pIter = v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_80;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_80;
    v57 = (char)bCheckSubstrings;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: v63,
            command: v34,
            text: (char *)&text->m_bIsCommand,
            bCheckSubstrings: v57) )
      goto LABEL_80;
    v35 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      v35->m_bIsCommand = true;
      v35->m_pCommand = nullptr;
      v35->m_pText = nullptr;
      item = v35;
    }
    else
    {
      item = nullptr;
    }
    v36 = v63;
    m_Size = v63->m_CompletionList.m_Size;
    v38 = v63->m_CompletionList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v38 )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v63->m_CompletionList,
        num: m_Size - v38 + 1);
    ++v36->m_CompletionList.m_Size;
    v39 = v36->m_CompletionList.m_Memory.m_pMemory;
    v40 = v36->m_CompletionList.m_Size - m_Size - 1;
    v36->m_CompletionList.m_pElements = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v39[m_Size + 1], src: (unsigned __int8 *)&v39[m_Size], count: 4 * v40);
    v41 = &v36->m_CompletionList.m_Memory.m_pMemory[m_Size];
    if ( v41 != nullptr )
      *v41 = item;
    v42 = item;
    item->m_pCommand = v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      v42->m_bIsCommand = true;
      v53 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      v54 = v53;
      if ( v53 != nullptr )
      {
        v53->m_text = nullptr;
        v53->m_extraText = nullptr;
        v53->m_bHasExtra = false;
        free(pMem: nullptr);
        v55 = strlen(v43);
        v56 = (char *)operator new(nSize: v55 + 1);
        v54->m_text = v56;
        _V_memset(dest: (int)v56, fill: nullptr, count: v55 + 1);
        V_strncpy(pDest: v54->m_text, pSrc: v43, maxLen: v55 + 1);
        v54->m_bHasExtra = false;
      }
      else
      {
        v54 = nullptr;
      }
      item->m_pText = v54;
    }
    else
    {
      v42->m_bIsCommand = false;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: (void *)&ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = defaultValue;
            }
            v58 = (char *)m_pszName;
            v47 = (char *)v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v58);
            item->m_pText = v48;
          }
          else
          {
            item->m_pText = nullptr;
          }
          goto LABEL_79;
        }
        v49 = (int)v33[1].m_pNext[2].__vftable;
      }
      if ( v44 != nullptr )
      {
        v61 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = v61;
      }
      else
      {
        v50 = *(float *)&v33[1].m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%f", v50);
      v51 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      if ( v51 != nullptr )
      {
        v52 = (char *)v33->GetName(this: v33);
        v51->m_text = nullptr;
        v51->m_extraText = nullptr;
        v51->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v51, text: v52, extra: strValue);
        item->m_pText = v51;
      }
      else
      {
        item->m_pText = nullptr;
      }
    }
LABEL_79:
    v31 = iter.m_pIter;
LABEL_80:
    v31->Next(this: v31);
  }
  if ( v63->m_CompletionList.m_Size >= 2 )
    CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int>>::Sort(
      this: &v63->m_CompletionList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))vgui::CConsolePanel::CompletionItemCompare);
  free(pMem: v31);
}

//------------------------------------------------------------------------------
// Address: 0x100687F0
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp+20h] [ebp-110h]
  int v19; // [esp+24h] [ebp-10Ch]
  char text[259]; // [esp+2Ch] [ebp-104h] BYREF
  bool altKeyDown; // [esp+12Fh] [ebp-1h]
  char hitTilde_3; // [esp+13Bh] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = _V_strlen(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (hitTilde_3 = 0, v6 == 96) )
      hitTilde_3 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), altKeyDown = false, v7) )
    {
      altKeyDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && hitTilde_3 != 0 )
    {
      v9 = !altKeyDown;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: defaultValue,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(
        this,
        text: (vgui::CConsolePanel::CompletionItem *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          text[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest: text, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest: text, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: text);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: text, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068AB0
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel::CompletionItem *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      free(pMem: m_pMemory->m_text);
      free(pMem: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: (int)v21, value: nullptr, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: (int)v6, value: nullptr, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = defaultValue;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (char *)v21,
    extra: (char *)v6);
  m_szPartialText = (vgui::CConsolePanel::CompletionItem *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10068D90
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: defaultValue);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)_V_strlen(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102E4C10
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10323DC0
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x10323DD0
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x10323DE0
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323E80
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323EE0
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  operator delete(p: this->m_text);
  v4 = strlen(text);
  v5 = (char *)operator new(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: (unsigned __int8 *)v5, fill: 0, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    operator delete(p: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)operator new(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: (unsigned __int8 *)v7, fill: 0, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323F90
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)&var;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = &var;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x10324000
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)&var;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x10324040
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: &var);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10324090
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x103240B0
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x103240D0
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(char *partial@<eax>, int a2@<esi>)
{
  _BYTE *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10324140
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = std::char_traits<char>::length(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = std::char_traits<char>::length(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = std::char_traits<char>::length(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324230
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103242F0
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10324310
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10324450
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103244D0
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)operator new(nSize: 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  operator delete(p: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10324530
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10324600
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10324620
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10324650
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x10324660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103246C0
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103246F0
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x10324730
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324950
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)&var;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)&var;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x10324A40
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324AB0
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324D30
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324E20
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        operator delete(p: *p_m_text);
        operator delete(p: p_m_text[1]);
        *p_m_text = nullptr;
        operator delete(p: p_m_text);
        v3->m_pText = nullptr;
      }
      operator delete(p: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324F50
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324FF0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CloseCompletionList";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325080
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CompletionCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325120
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)operator new(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)operator new(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)operator new(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: (vgui::Panel *)"ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10325460
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10325490
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x103254A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103254D0
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103255A0
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(vgui::CConsolePanel *this, vgui::CConsolePanel *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  char **v4; // ebx
  vgui::CConsolePanel *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  char *v13; // eax
  int m_nGrowSize; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  int m_Size; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  int v19; // eax
  _DWORD *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  int *v25; // esi
  unsigned __int8 **v26; // esi
  const char *v27; // edi
  unsigned int v28; // kr00_4
  unsigned __int8 *v29; // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  CUtlString *v35; // eax
  _DWORD *v36; // esi
  int v37; // ebx
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  CUtlString **v41; // ebx
  CUtlString *m_pElements; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  ConCommandBase *m_pNext; // eax
  vgui::CHistoryItem *v52; // esi
  char *v53; // eax
  _DWORD *v54; // eax
  int v55; // esi
  unsigned int v56; // kr04_4
  unsigned __int8 *v57; // eax
  char v58; // [esp+4h] [ebp-238h]
  char *v59; // [esp+4h] [ebp-238h]
  char pDest[20]; // [esp+14h] [ebp-228h] BYREF
  char strValue[512]; // [esp+28h] [ebp-214h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+228h] [ebp-14h]
  vgui::CConsolePanel *v63; // [esp+244h] [ebp+8h]
  vgui::CConsolePanel *v64; // [esp+244h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  commands.m_Memory.m_nGrowSize = (int)this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)std::char_traits<char>::length(str: (const char *)text) < 1 )
  {
    commands.m_Size = 0;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      commands.m_pElements = nullptr;
      while ( 1 )
      {
        v4 = (char **)((char *)commands.m_pElements + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel *)operator new(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          LOBYTE(v5->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable) = 1;
          *(_DWORD *)&v5->vgui::EditablePanel::vgui::Panel::m_RegisterClass = 0;
          *(_DWORD *)&v5->m_OnCommand_register = 0;
          v63 = v5;
        }
        else
        {
          v63 = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = v63;
        LOBYTE(v63->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable) = 0;
        *(_DWORD *)&v63->vgui::EditablePanel::vgui::Panel::m_RegisterClass = 0;
        v11 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = (char *)&var;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        m_nGrowSize = commands.m_Memory.m_nGrowSize;
        commands.m_pElements = (CUtlString *)((char *)commands.m_pElements + 12);
        *(_DWORD *)&v63->m_OnCommand_register = v12;
        if ( ++commands.m_Size >= *(_DWORD *)(m_nGrowSize + 968) )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)m_nGrowSize;
      }
    }
    return;
  }
  LOBYTE(commands.m_Memory.m_nAllocationCount) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(partial: (char *)text, a2: (int)text);
    m_Size = 0;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&strValue[492], 0, 20);
      v19 = AutoCompleteSuggest(
              this: AutoCompleteCommmandFromPartial,
              a2: (const char *)text,
              a3: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&strValue[492]);
      if ( v19 > 0 )
      {
        v64 = nullptr;
        commands.m_Memory.m_nGrowSize = v19;
        while ( 1 )
        {
          v20 = operator new(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1] = 0;
            v20[2] = 0;
            *(_BYTE *)v20 = 1;
            m_Size = (int)v20;
            commands.m_Size = (int)v20;
          }
          else
          {
            commands.m_Size = 0;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (int *)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_Size;
          *(_BYTE *)m_Size = 0;
          *(_DWORD *)(m_Size + 4) = 0;
          v26 = (unsigned __int8 **)operator new(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = CUtlString::operator char const *(this: (CUtlString *)((char *)v64 + *(_DWORD *)&strValue[492]));
            commands.m_Memory.m_nAllocationCount = (int)v27;
            *v26 = nullptr;
            v26[1] = nullptr;
            *((_BYTE *)v26 + 8) = 0;
            operator delete(p: nullptr);
            v28 = strlen(v27);
            v29 = (unsigned __int8 *)operator new(nSize: v28 + 1);
            *v26 = v29;
            _V_memset(dest: v29, fill: 0, count: v28 + 1);
            V_strncpy(pDest: (char *)*v26, pSrc: (char *)commands.m_Memory.m_nAllocationCount, maxLen: v28 + 1);
            m_Size = commands.m_Size;
            *((_BYTE *)v26 + 8) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          v64 = (vgui::CConsolePanel *)((char *)v64 + 16);
          v30 = commands.m_Memory.m_nGrowSize-- == 1;
          *(_DWORD *)(m_Size + 8) = v26;
          if ( v30 )
            break;
          m_Size = 0;
        }
      }
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&strValue[492]);
      return;
    }
    LOBYTE(commands.m_Memory.m_nAllocationCount) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  commands.m_Size = (int)v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_81;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_81;
    v58 = commands.m_Memory.m_nAllocationCount;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: (vgui::CConsolePanel *)commands.m_Memory.m_nGrowSize,
            command: v34,
            (char *)text,
            bCheckSubstrings: v58) )
      goto LABEL_81;
    v35 = (CUtlString *)operator new(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      LOBYTE(v35->m_Storage.m_Memory.m_pMemory) = 1;
      v35->m_Storage.m_Memory.m_nAllocationCount = 0;
      v35->m_Storage.m_Memory.m_nGrowSize = 0;
      commands.m_pElements = v35;
    }
    else
    {
      commands.m_pElements = nullptr;
    }
    v36 = (_DWORD *)commands.m_Memory.m_nGrowSize;
    v37 = *(_DWORD *)(commands.m_Memory.m_nGrowSize + 948);
    v38 = *(_DWORD *)(commands.m_Memory.m_nGrowSize + 940);
    if ( v37 + 1 > v38 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)(commands.m_Memory.m_nGrowSize + 936),
        num: v37 - v38 + 1);
    ++v36[237];
    v39 = v36[234];
    v40 = v36[237] - v37 - 1;
    v36[238] = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)(v39 + 4 * v37 + 4), src: (unsigned __int8 *)(v39 + 4 * v37), count: 4 * v40);
    v41 = (CUtlString **)(v36[234] + 4 * v37);
    if ( v41 != nullptr )
      *v41 = commands.m_pElements;
    m_pElements = commands.m_pElements;
    commands.m_pElements->m_Storage.m_Memory.m_nAllocationCount = (int)v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      LOBYTE(m_pElements->m_Storage.m_Memory.m_pMemory) = 1;
      v54 = operator new(nSize: 0xCu);
      v55 = (int)v54;
      if ( v54 != nullptr )
      {
        *v54 = 0;
        v54[1] = 0;
        *((_BYTE *)v54 + 8) = 0;
        operator delete(p: nullptr);
        v56 = strlen(v43);
        v57 = (unsigned __int8 *)operator new(nSize: v56 + 1);
        *(_DWORD *)v55 = v57;
        _V_memset(dest: v57, fill: 0, count: v56 + 1);
        V_strncpy(pDest: *(char **)v55, pSrc: v43, maxLen: v56 + 1);
        *(_BYTE *)(v55 + 8) = 0;
      }
      else
      {
        v55 = 0;
      }
      commands.m_pElements->m_Storage.m_Memory.m_nGrowSize = v55;
    }
    else
    {
      LOBYTE(m_pElements->m_Storage.m_Memory.m_pMemory) = 0;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: (void *)&ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
        *(float *)&commands.m_Memory.m_pMemory = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = *(float *)&commands.m_Memory.m_pMemory;
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = &var;
            }
            v59 = (char *)m_pszName;
            v47 = (char *)v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v59);
            commands.m_pElements->m_Storage.m_Memory.m_nGrowSize = (int)v48;
          }
          else
          {
            commands.m_pElements->m_Storage.m_Memory.m_nGrowSize = 0;
          }
          goto LABEL_80;
        }
        m_pNext = v33[1].m_pNext;
        if ( m_pNext != nullptr )
          v49 = (int)m_pNext[2].__vftable;
        else
          v49 = 0;
        v50 = *(float *)&m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest, maxLen: 0x200u, pFormat: "%f", v50);
      v52 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      if ( v52 != nullptr )
      {
        v53 = (char *)v33->GetName(this: v33);
        v52->m_text = nullptr;
        v52->m_extraText = nullptr;
        v52->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v52, text: v53, extra: pDest);
        commands.m_pElements->m_Storage.m_Memory.m_nGrowSize = (int)v52;
      }
      else
      {
        commands.m_pElements->m_Storage.m_Memory.m_nGrowSize = 0;
      }
    }
LABEL_80:
    v31 = (ICvar::ICVarIteratorInternal *)commands.m_Size;
LABEL_81:
    v31->Next(this: v31);
  }
  if ( *(int *)(commands.m_Memory.m_nGrowSize + 948) >= 2 )
    CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
      this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)(commands.m_Memory.m_nGrowSize + 936),
      pfnCompare: vgui::CConsolePanel::CompletionItemCompare);
  operator delete(p: v31);
}

//------------------------------------------------------------------------------
// Address: 0x10325BC0
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp-4h] [ebp-110h]
  int v19; // [esp+0h] [ebp-10Ch]
  char pDest[40]; // [esp+8h] [ebp-104h] BYREF
  char text_219; // [esp+10Bh] [ebp-1h] OVERLAPPED
  char text_231; // [esp+117h] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = std::char_traits<char>::length(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (text_231 = 0, v6 == 96) )
      text_231 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), text_219 = 0, v7) )
    {
      text_219 = 1;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && text_231 != 0 )
    {
      v9 = text_219 == 0;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: &var,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(this, text: (vgui::CConsolePanel *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          pDest[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: pDest);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: pDest, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10325E80
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      operator delete(p: m_pMemory->m_text);
      operator delete(p: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: v21, value: 0, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: v6, value: 0, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = &var;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (char *)v21,
    extra: (char *)v6);
  m_szPartialText = (vgui::CConsolePanel *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10326160
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: &var);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)std::char_traits<char>::length(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00439840
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00439850
// Name: public: static char const __near * vgui::CConsoleDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsoleDialog::GetPanelClassName()
{
  return "CConsoleDialog";
}

//------------------------------------------------------------------------------
// Address: 0x00439860
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x00439870
// Name: public: static char const __near * vgui::TextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TextEntry::GetPanelClassName()
{
  return "TextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x00439880
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x00439890
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439930
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439990
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  free(pMem: this->m_text);
  v4 = strlen(text);
  v5 = (char *)operator new(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: (unsigned __int8 *)v5, fill: 0, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    free(pMem: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)operator new(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: (unsigned __int8 *)v7, fill: 0, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439A40
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = defaultValue;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x00439AB0
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x00439AF0
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: defaultValue);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00439B40
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00439B60
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00439B80
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(char *partial@<eax>, int a2@<esi>)
{
  _BYTE *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00439BF0
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = _V_strlen(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = _V_strlen(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = _V_strlen(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439CE0
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439DA0
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00439DC0
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00439F00
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00439F80
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)operator new(nSize: 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  free(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00439FE0
// Name: public: virtual void vgui::CConsoleDialog::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::OnScreenSizeChanged(vgui::CConsoleDialog *this, int iOldWide, int iOldTall)
{
  int v4; // eax
  int v5; // ecx
  int sx; // [esp+4h] [ebp-8h] BYREF
  int sy; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::OnScreenSizeChanged(this, iOldWide, iOldTall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &sx, a3: &sy);
  vgui::Panel::GetSize(this, wide: &iOldWide, tall: &iOldTall);
  v4 = iOldWide;
  if ( iOldWide <= sx )
  {
    if ( iOldTall <= sy )
      return;
    goto LABEL_5;
  }
  v4 = sx;
  v5 = iOldTall;
  iOldWide = sx;
  if ( iOldTall > sy )
  {
LABEL_5:
    v5 = sy;
    iOldTall = sy;
  }
  vgui::Panel::SetSize(this, wide: v4, tall: v5);
}

//------------------------------------------------------------------------------
// Address: 0x0043A060
// Name: public: virtual void vgui::CConsoleDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::PerformLayout(vgui::CConsoleDialog *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: this->m_pConsolePanel, x, y, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x0043A0B0
// Name: public: virtual void vgui::CConsoleDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Activate(vgui::CConsoleDialog *this)
{
  vgui::Frame::Activate(this);
  this->m_pConsolePanel->m_pEntry->RequestFocus(this: this->m_pConsolePanel->m_pEntry, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043A0D0
// Name: public: virtual void vgui::CConsoleDialog::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::OnCommandSubmitted(vgui::CConsoleDialog *this, char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: pCommand);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A1B0
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A280
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043A2A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A2D0
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x0043A2E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043A340
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043A370
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043A3B0
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A5D0
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x0043A6C0
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A730
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043A9B0
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AB20
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        free(pMem: *p_m_text);
        free(pMem: p_m_text[1]);
        *p_m_text = nullptr;
        free(pMem: p_m_text);
        v3->m_pText = nullptr;
      }
      free(pMem: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AC50
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043ACF0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CloseCompletionList";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AD80
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CompletionCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AE20
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Activate";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AEB0
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043AF50
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)operator new(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand_2(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)operator new(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)operator new(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B290
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B2C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0043B2D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043B300
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043B3A0
// Name: public: vgui::CConsoleDialog::CConsoleDialog(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsoleDialog *__thiscall vgui::CConsoleDialog::CConsoleDialog(
        vgui::CConsoleDialog *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CConsolePanel *v8; // eax
  vgui::CConsolePanel *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: pName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::CConsoleDialog_vtbl *)&vgui::CConsoleDialog::`vftable';
  if ( `vgui::CConsoleDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v5->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsoleDialog");
    v6->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
    v7->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(a1: (int)&savedregs);
  vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetTitle(this, title: "#Console_Title", surfaceTitle: true);
  v8 = (vgui::CConsolePanel *)operator new(nSize: 0x3D0u);
  if ( v8 != nullptr )
    v9 = vgui::CConsolePanel::CConsolePanel(this: v8, pParent: this, pName: "ConsolePage", bStatusVersion);
  else
    v9 = nullptr;
  this->m_pConsolePanel = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043B630
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::CompletionItem *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  char **v4; // ebx
  vgui::CConsolePanel::CompletionItem *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel::CompletionItem **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  char *v13; // eax
  vgui::CConsolePanel *v14; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  vgui::CConsolePanel *v19; // eax
  ICvar::ICVarIteratorInternal *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  ICvar::ICVarIteratorInternal **v25; // esi
  ICvar::ICVarIteratorInternal_vtbl *v26; // esi
  char *v27; // edi
  unsigned int v28; // kr00_4
  unsigned __int8 *v29; // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  vgui::CConsolePanel::CompletionItem *v35; // eax
  vgui::CConsolePanel *v36; // esi
  int m_Size; // ebx
  int v38; // eax
  vgui::CConsolePanel::CompletionItem **v39; // ecx
  int v40; // eax
  vgui::CConsolePanel::CompletionItem **v41; // ebx
  vgui::CConsolePanel::CompletionItem *v42; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  vgui::CHistoryItem *v51; // esi
  char *v52; // eax
  vgui::CHistoryItem *v53; // eax
  vgui::CHistoryItem *v54; // esi
  unsigned int v55; // kr04_4
  unsigned __int8 *v56; // eax
  char v57; // [esp+10h] [ebp-238h]
  char *v58; // [esp+10h] [ebp-238h]
  char strValue[512]; // [esp+20h] [ebp-228h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+220h] [ebp-28h] BYREF
  float v61; // [esp+234h] [ebp-14h]
  char *bCheckSubstrings; // [esp+238h] [ebp-10h]
  vgui::CConsolePanel *v63; // [esp+23Ch] [ebp-Ch]
  ICvar::Iterator iter; // [esp+240h] [ebp-8h]
  vgui::CConsolePanel::CompletionItem *item; // [esp+244h] [ebp-4h]
  vgui::CConsolePanel::CompletionItem *comp; // [esp+250h] [ebp+8h]
  vgui::CConsolePanel::CompletionItem *compa; // [esp+250h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  v63 = this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)_V_strlen(str: (const char *)&text->m_bIsCommand) < 1 )
  {
    iter.m_pIter = nullptr;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      item = nullptr;
      while ( 1 )
      {
        v4 = (char **)(&item->m_bIsCommand + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          v5->m_bIsCommand = true;
          v5->m_pCommand = nullptr;
          v5->m_pText = nullptr;
          comp = v5;
        }
        else
        {
          comp = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<unsigned long,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel::CompletionItem **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = comp;
        comp->m_bIsCommand = false;
        comp->m_pCommand = nullptr;
        v11 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = (char *)defaultValue;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        v14 = v63;
        ++item;
        comp->m_pText = v12;
        if ( (int)++iter.m_pIter >= v14->m_CommandHistory.m_Size )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)v14;
      }
    }
    return;
  }
  LOBYTE(bCheckSubstrings) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(
                                        partial: (char *)&text->m_bIsCommand,
                                        a2: (int)text);
    m_pIter = nullptr;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&commands, 0, sizeof(commands));
      v19 = (vgui::CConsolePanel *)AutoCompleteSuggest(
                                     this: AutoCompleteCommmandFromPartial,
                                     a2: (const char *)&text->m_bIsCommand,
                                     a3: &commands);
      if ( (int)v19 > 0 )
      {
        compa = nullptr;
        v63 = v19;
        while ( 1 )
        {
          v20 = (ICvar::ICVarIteratorInternal *)operator new(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1].__vftable = nullptr;
            v20[2].__vftable = nullptr;
            LOBYTE(v20->__vftable) = 1;
            m_pIter = v20;
            iter.m_pIter = v20;
          }
          else
          {
            iter.m_pIter = nullptr;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<unsigned long,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (ICvar::ICVarIteratorInternal **)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_pIter;
          LOBYTE(m_pIter->__vftable) = 0;
          m_pIter[1].__vftable = nullptr;
          v26 = (ICvar::ICVarIteratorInternal_vtbl *)operator new(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = (char *)CUtlString::operator char const *(this: (CUtlString *)(&compa->m_bIsCommand
                                                                               + (unsigned int)commands.m_Memory.m_pMemory));
            bCheckSubstrings = v27;
            v26->SetFirst = nullptr;
            v26->Next = nullptr;
            LOBYTE(v26->IsValid) = 0;
            free(pMem: nullptr);
            v28 = strlen(v27);
            v29 = (unsigned __int8 *)operator new(nSize: v28 + 1);
            v26->SetFirst = (void (__thiscall *)(ICvar::ICVarIteratorInternal *))v29;
            _V_memset(dest: v29, fill: 0, count: v28 + 1);
            V_strncpy(pDest: (char *)v26->SetFirst, pSrc: bCheckSubstrings, maxLen: v28 + 1);
            m_pIter = iter.m_pIter;
            LOBYTE(v26->IsValid) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          compa = (vgui::CConsolePanel::CompletionItem *)((char *)compa + 16);
          v30 = v63 == (vgui::CConsolePanel *)1;
          v63 = (vgui::CConsolePanel *)((char *)v63 - 1);
          m_pIter[2].__vftable = v26;
          if ( v30 )
            break;
          m_pIter = nullptr;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &commands);
      return;
    }
    LOBYTE(bCheckSubstrings) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  iter.m_pIter = v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_80;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_80;
    v57 = (char)bCheckSubstrings;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: v63,
            command: v34,
            text: (char *)&text->m_bIsCommand,
            bCheckSubstrings: v57) )
      goto LABEL_80;
    v35 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      v35->m_bIsCommand = true;
      v35->m_pCommand = nullptr;
      v35->m_pText = nullptr;
      item = v35;
    }
    else
    {
      item = nullptr;
    }
    v36 = v63;
    m_Size = v63->m_CompletionList.m_Size;
    v38 = v63->m_CompletionList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v38 )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v63->m_CompletionList,
        num: m_Size - v38 + 1);
    ++v36->m_CompletionList.m_Size;
    v39 = v36->m_CompletionList.m_Memory.m_pMemory;
    v40 = v36->m_CompletionList.m_Size - m_Size - 1;
    v36->m_CompletionList.m_pElements = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v39[m_Size + 1], src: (unsigned __int8 *)&v39[m_Size], count: 4 * v40);
    v41 = &v36->m_CompletionList.m_Memory.m_pMemory[m_Size];
    if ( v41 != nullptr )
      *v41 = item;
    v42 = item;
    item->m_pCommand = v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      v42->m_bIsCommand = true;
      v53 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      v54 = v53;
      if ( v53 != nullptr )
      {
        v53->m_text = nullptr;
        v53->m_extraText = nullptr;
        v53->m_bHasExtra = false;
        free(pMem: nullptr);
        v55 = strlen(v43);
        v56 = (unsigned __int8 *)operator new(nSize: v55 + 1);
        v54->m_text = (char *)v56;
        _V_memset(dest: v56, fill: 0, count: v55 + 1);
        V_strncpy(pDest: v54->m_text, pSrc: v43, maxLen: v55 + 1);
        v54->m_bHasExtra = false;
      }
      else
      {
        v54 = nullptr;
      }
      item->m_pText = v54;
    }
    else
    {
      v42->m_bIsCommand = false;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: &ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = defaultValue;
            }
            v58 = (char *)m_pszName;
            v47 = (char *)v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v58);
            item->m_pText = v48;
          }
          else
          {
            item->m_pText = nullptr;
          }
          goto LABEL_79;
        }
        v49 = (int)v33[1].m_pNext[2].__vftable;
      }
      if ( v44 != nullptr )
      {
        v61 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = v61;
      }
      else
      {
        v50 = *(float *)&v33[1].m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%f", v50);
      v51 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      if ( v51 != nullptr )
      {
        v52 = (char *)v33->GetName(this: v33);
        v51->m_text = nullptr;
        v51->m_extraText = nullptr;
        v51->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v51, text: v52, extra: strValue);
        item->m_pText = v51;
      }
      else
      {
        item->m_pText = nullptr;
      }
    }
LABEL_79:
    v31 = iter.m_pIter;
LABEL_80:
    v31->Next(this: v31);
  }
  if ( v63->m_CompletionList.m_Size >= 2 )
    CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int>>::Sort(
      this: &v63->m_CompletionList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))vgui::CConsolePanel::CompletionItemCompare);
  free(pMem: v31);
}

//------------------------------------------------------------------------------
// Address: 0x0043BC50
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp+20h] [ebp-110h]
  int v19; // [esp+24h] [ebp-10Ch]
  char text[259]; // [esp+2Ch] [ebp-104h] BYREF
  bool altKeyDown; // [esp+12Fh] [ebp-1h]
  char hitTilde_3; // [esp+13Bh] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = _V_strlen(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (hitTilde_3 = 0, v6 == 96) )
      hitTilde_3 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), altKeyDown = false, v7) )
    {
      altKeyDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && hitTilde_3 != 0 )
    {
      v9 = !altKeyDown;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: defaultValue,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(
        this,
        text: (vgui::CConsolePanel::CompletionItem *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          text[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest: text, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest: text, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: text);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: text, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BF10
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel::CompletionItem *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      free(pMem: m_pMemory->m_text);
      free(pMem: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: v21, value: 0, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: v6, value: 0, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = defaultValue;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (char *)v21,
    extra: (char *)v6);
  m_szPartialText = (vgui::CConsolePanel::CompletionItem *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0043C1F0
// Name: public: virtual void vgui::CConsoleDialog::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Close(vgui::CConsoleDialog *this)
{
  vgui::CConsolePanel *m_pConsolePanel; // esi

  this->OnClose(this);
  m_pConsolePanel = this->m_pConsolePanel;
  m_pConsolePanel->OnClose(this: m_pConsolePanel);
  m_pConsolePanel->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(
    this: m_pConsolePanel,
    text: (vgui::CConsolePanel::CompletionItem *)defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0043C230
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: defaultValue);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: (unsigned __int8 *)szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)_V_strlen(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046A6D0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00626EB0
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00626EC0
// Name: public: static char const __near * vgui::CConsoleDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsoleDialog::GetPanelClassName()
{
  return "CConsoleDialog";
}

//------------------------------------------------------------------------------
// Address: 0x00626ED0
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x00626EE0
// Name: public: static char const __near * vgui::TextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TextEntry::GetPanelClassName()
{
  return "TextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x00626EF0
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626F90
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00626FF0
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  free(pMem: this->m_text);
  v4 = strlen(text);
  v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: (unsigned __int8 *)v5, fill: 0, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    free(pMem: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)MemAlloc_Alloc(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: (unsigned __int8 *)v7, fill: 0, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006270A0
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = defaultValue;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x00627110
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)defaultValue;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x00627150
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: defaultValue);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x006271A0
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x006271C0
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x006271E0
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(char *partial@<eax>, int a2@<esi>)
{
  _BYTE *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00627250
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = _V_strlen(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = _V_strlen(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = _V_strlen(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627340
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627400
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00627420
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00627560
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006275E0
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)bufSize >> 31 != 0 ? -1 : 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  free(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00627640
// Name: public: virtual void vgui::CConsoleDialog::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::OnScreenSizeChanged(vgui::CConsoleDialog *this, int iOldWide, int iOldTall)
{
  int v4; // eax
  int v5; // ecx
  int sx; // [esp+4h] [ebp-8h] BYREF
  int sy; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::OnScreenSizeChanged(this, iOldWide, iOldTall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &sx, a3: &sy);
  vgui::Panel::GetSize(this, wide: &iOldWide, tall: &iOldTall);
  v4 = iOldWide;
  if ( iOldWide <= sx )
  {
    if ( iOldTall <= sy )
      return;
    goto LABEL_5;
  }
  v4 = sx;
  v5 = iOldTall;
  iOldWide = sx;
  if ( iOldTall > sy )
  {
LABEL_5:
    v5 = sy;
    iOldTall = sy;
  }
  vgui::Panel::SetSize(this, wide: v4, tall: v5);
}

//------------------------------------------------------------------------------
// Address: 0x006276C0
// Name: public: virtual void vgui::CConsoleDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::PerformLayout(vgui::CConsoleDialog *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: this->m_pConsolePanel, x, y, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x00627710
// Name: public: virtual void vgui::CConsoleDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Activate(vgui::CConsoleDialog *this)
{
  vgui::Frame::Activate(this);
  this->m_pConsolePanel->m_pEntry->RequestFocus(this: this->m_pConsolePanel->m_pEntry, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006277A0
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00627870
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00627890
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006278C0
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x006278D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00627900
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00627930
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x00627970
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627B90
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)defaultValue;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x00627C80
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627CF0
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627F70
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00628060
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        free(pMem: *p_m_text);
        free(pMem: p_m_text[1]);
        *p_m_text = nullptr;
        free(pMem: p_m_text);
        v3->m_pText = nullptr;
      }
      free(pMem: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00628190
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00628230
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CloseCompletionList";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006282C0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CompletionCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00628360
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Activate";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006283F0
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00628490
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand_2(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)MemAlloc_Alloc(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006287D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628800
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x00628810
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628840
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x006288E0
// Name: public: vgui::CConsoleDialog::CConsoleDialog(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsoleDialog *__thiscall vgui::CConsoleDialog::CConsoleDialog(
        vgui::CConsoleDialog *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CConsolePanel *v8; // eax
  vgui::CConsolePanel *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: pName, showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (vgui::CConsoleDialog_vtbl *)&vgui::CConsoleDialog::`vftable';
  if ( `vgui::CConsoleDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v5->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsoleDialog");
    v6->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
    v7->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(a1: (int)&savedregs);
  vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetTitle(this, title: "#Console_Title", surfaceTitle: true);
  v8 = (vgui::CConsolePanel *)MemAlloc_Alloc(nSize: 0x3D0u);
  if ( v8 != nullptr )
    v9 = vgui::CConsolePanel::CConsolePanel(this: v8, pParent: this, pName: "ConsolePage", bStatusVersion);
  else
    v9 = nullptr;
  this->m_pConsolePanel = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00628A00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsoleDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsoleDialog::GetMessageMap(vgui::CConsoleDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628A30
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsoleDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsoleDialog::GetAnimMap(vgui::CConsoleDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsoleDialog");
}

//------------------------------------------------------------------------------
// Address: 0x00628A40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsoleDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsoleDialog::GetKBMap(vgui::CConsoleDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap;
  `vgui::CConsoleDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
  `vgui::CConsoleDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628AA0
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::CompletionItem *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  char **v4; // ebx
  vgui::CConsolePanel::CompletionItem *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel::CompletionItem **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  char *v13; // eax
  vgui::CConsolePanel *v14; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  vgui::CConsolePanel *v19; // eax
  ICvar::ICVarIteratorInternal *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  ICvar::ICVarIteratorInternal **v25; // esi
  ICvar::ICVarIteratorInternal_vtbl *v26; // esi
  char *v27; // edi
  unsigned int v28; // kr00_4
  unsigned __int8 *v29; // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  vgui::CConsolePanel::CompletionItem *v35; // eax
  vgui::CConsolePanel *v36; // esi
  int m_Size; // ebx
  int v38; // eax
  vgui::CConsolePanel::CompletionItem **v39; // ecx
  int v40; // eax
  vgui::CConsolePanel::CompletionItem **v41; // ebx
  vgui::CConsolePanel::CompletionItem *v42; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  vgui::CHistoryItem *v51; // esi
  char *v52; // eax
  vgui::CHistoryItem *v53; // eax
  vgui::CHistoryItem *v54; // esi
  unsigned int v55; // kr04_4
  unsigned __int8 *v56; // eax
  char v57; // [esp+10h] [ebp-238h]
  char *v58; // [esp+10h] [ebp-238h]
  char strValue[512]; // [esp+20h] [ebp-228h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+220h] [ebp-28h] BYREF
  float v61; // [esp+234h] [ebp-14h]
  char *bCheckSubstrings; // [esp+238h] [ebp-10h]
  vgui::CConsolePanel *v63; // [esp+23Ch] [ebp-Ch]
  ICvar::Iterator iter; // [esp+240h] [ebp-8h]
  vgui::CConsolePanel::CompletionItem *item; // [esp+244h] [ebp-4h]
  vgui::CConsolePanel::CompletionItem *comp; // [esp+250h] [ebp+8h]
  vgui::CConsolePanel::CompletionItem *compa; // [esp+250h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  v63 = this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)_V_strlen(str: (const char *)&text->m_bIsCommand) < 1 )
  {
    iter.m_pIter = nullptr;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      item = nullptr;
      while ( 1 )
      {
        v4 = (char **)(&item->m_bIsCommand + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel::CompletionItem *)MemAlloc_Alloc(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          v5->m_bIsCommand = true;
          v5->m_pCommand = nullptr;
          v5->m_pText = nullptr;
          comp = v5;
        }
        else
        {
          comp = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel::CompletionItem **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = comp;
        comp->m_bIsCommand = false;
        comp->m_pCommand = nullptr;
        v11 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = (char *)defaultValue;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        v14 = v63;
        ++item;
        comp->m_pText = v12;
        if ( (int)++iter.m_pIter >= v14->m_CommandHistory.m_Size )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)v14;
      }
    }
    return;
  }
  LOBYTE(bCheckSubstrings) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(
                                        partial: (char *)&text->m_bIsCommand,
                                        a2: (int)text);
    m_pIter = nullptr;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&commands, 0, sizeof(commands));
      v19 = (vgui::CConsolePanel *)AutoCompleteSuggest(
                                     this: AutoCompleteCommmandFromPartial,
                                     a2: (const char *)&text->m_bIsCommand,
                                     a3: &commands);
      if ( (int)v19 > 0 )
      {
        compa = nullptr;
        v63 = v19;
        while ( 1 )
        {
          v20 = (ICvar::ICVarIteratorInternal *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1].__vftable = nullptr;
            v20[2].__vftable = nullptr;
            LOBYTE(v20->__vftable) = 1;
            m_pIter = v20;
            iter.m_pIter = v20;
          }
          else
          {
            iter.m_pIter = nullptr;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (ICvar::ICVarIteratorInternal **)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_pIter;
          LOBYTE(m_pIter->__vftable) = 0;
          m_pIter[1].__vftable = nullptr;
          v26 = (ICvar::ICVarIteratorInternal_vtbl *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = (char *)CUtlString::operator char const *(this: (CUtlString *)(&compa->m_bIsCommand
                                                                               + (unsigned int)commands.m_Memory.m_pMemory));
            bCheckSubstrings = v27;
            v26->SetFirst = nullptr;
            v26->Next = nullptr;
            LOBYTE(v26->IsValid) = 0;
            free(pMem: nullptr);
            v28 = strlen(v27);
            v29 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v28 + 1);
            v26->SetFirst = (void (__thiscall *)(ICvar::ICVarIteratorInternal *))v29;
            _V_memset(dest: v29, fill: 0, count: v28 + 1);
            V_strncpy(pDest: (char *)v26->SetFirst, pSrc: bCheckSubstrings, maxLen: v28 + 1);
            m_pIter = iter.m_pIter;
            LOBYTE(v26->IsValid) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          compa = (vgui::CConsolePanel::CompletionItem *)((char *)compa + 16);
          v30 = v63 == (vgui::CConsolePanel *)1;
          v63 = (vgui::CConsolePanel *)((char *)v63 - 1);
          m_pIter[2].__vftable = v26;
          if ( v30 )
            break;
          m_pIter = nullptr;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &commands);
      return;
    }
    LOBYTE(bCheckSubstrings) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  iter.m_pIter = v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_80;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_80;
    v57 = (char)bCheckSubstrings;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: v63,
            command: v34,
            text: (char *)&text->m_bIsCommand,
            bCheckSubstrings: v57) )
      goto LABEL_80;
    v35 = (vgui::CConsolePanel::CompletionItem *)MemAlloc_Alloc(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      v35->m_bIsCommand = true;
      v35->m_pCommand = nullptr;
      v35->m_pText = nullptr;
      item = v35;
    }
    else
    {
      item = nullptr;
    }
    v36 = v63;
    m_Size = v63->m_CompletionList.m_Size;
    v38 = v63->m_CompletionList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v38 )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v63->m_CompletionList,
        num: m_Size - v38 + 1);
    ++v36->m_CompletionList.m_Size;
    v39 = v36->m_CompletionList.m_Memory.m_pMemory;
    v40 = v36->m_CompletionList.m_Size - m_Size - 1;
    v36->m_CompletionList.m_pElements = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v39[m_Size + 1], src: (unsigned __int8 *)&v39[m_Size], count: 4 * v40);
    v41 = &v36->m_CompletionList.m_Memory.m_pMemory[m_Size];
    if ( v41 != nullptr )
      *v41 = item;
    v42 = item;
    item->m_pCommand = v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      v42->m_bIsCommand = true;
      v53 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
      v54 = v53;
      if ( v53 != nullptr )
      {
        v53->m_text = nullptr;
        v53->m_extraText = nullptr;
        v53->m_bHasExtra = false;
        free(pMem: nullptr);
        v55 = strlen(v43);
        v56 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v55 + 1);
        v54->m_text = (char *)v56;
        _V_memset(dest: v56, fill: 0, count: v55 + 1);
        V_strncpy(pDest: v54->m_text, pSrc: v43, maxLen: v55 + 1);
        v54->m_bHasExtra = false;
      }
      else
      {
        v54 = nullptr;
      }
      item->m_pText = v54;
    }
    else
    {
      v42->m_bIsCommand = false;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: &ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = defaultValue;
            }
            v58 = (char *)m_pszName;
            v47 = (char *)v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v58);
            item->m_pText = v48;
          }
          else
          {
            item->m_pText = nullptr;
          }
          goto LABEL_79;
        }
        v49 = (int)v33[1].m_pNext[2].__vftable;
      }
      if ( v44 != nullptr )
      {
        v61 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = v61;
      }
      else
      {
        v50 = *(float *)&v33[1].m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%f", v50);
      v51 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
      if ( v51 != nullptr )
      {
        v52 = (char *)v33->GetName(this: v33);
        v51->m_text = nullptr;
        v51->m_extraText = nullptr;
        v51->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v51, text: v52, extra: strValue);
        item->m_pText = v51;
      }
      else
      {
        item->m_pText = nullptr;
      }
    }
LABEL_79:
    v31 = iter.m_pIter;
LABEL_80:
    v31->Next(this: v31);
  }
  if ( v63->m_CompletionList.m_Size >= 2 )
    CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
      this: &v63->m_CompletionList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))vgui::CConsolePanel::CompletionItemCompare);
  free(pMem: v31);
}

//------------------------------------------------------------------------------
// Address: 0x006290C0
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp+20h] [ebp-110h]
  int v19; // [esp+24h] [ebp-10Ch]
  char text[259]; // [esp+2Ch] [ebp-104h] BYREF
  bool altKeyDown; // [esp+12Fh] [ebp-1h]
  char hitTilde_3; // [esp+13Bh] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = _V_strlen(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (hitTilde_3 = 0, v6 == 96) )
      hitTilde_3 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), altKeyDown = false, v7) )
    {
      altKeyDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && hitTilde_3 != 0 )
    {
      v9 = !altKeyDown;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: defaultValue,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(
        this,
        text: (vgui::CConsolePanel::CompletionItem *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          text[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest: text, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest: text, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: text);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: text, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00629380
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel::CompletionItem *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      free(pMem: m_pMemory->m_text);
      free(pMem: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: v21, value: 0, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: v6, value: 0, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = defaultValue;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (char *)v21,
    extra: (char *)v6);
  m_szPartialText = (vgui::CConsolePanel::CompletionItem *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00629660
// Name: public: virtual void vgui::CConsoleDialog::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Close(vgui::CConsoleDialog *this)
{
  vgui::CConsolePanel *m_pConsolePanel; // esi

  this->OnClose(this);
  m_pConsolePanel = this->m_pConsolePanel;
  m_pConsolePanel->OnClose(this: m_pConsolePanel);
  m_pConsolePanel->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(
    this: m_pConsolePanel,
    text: (vgui::CConsolePanel::CompletionItem *)defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x006296A0
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: defaultValue);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: (unsigned __int8 *)szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)_V_strlen(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00457760
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x00466130
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x00466140
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x00466150
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004661F0
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466250
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  free(pMem: this->m_text);
  v4 = strlen(text);
  v5 = (char *)operator new(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: v5, fill: 0, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    free(pMem: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)operator new(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: v7, fill: 0, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466300
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)&defaultValue;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = &defaultValue;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x00466370
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)&defaultValue;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x004663B0
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: &defaultValue);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00466400
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00466420
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x00466440
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(char *partial@<eax>, int a2@<esi>)
{
  _BYTE *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004664B0
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = _V_strlen(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = _V_strlen(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = _V_strlen(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004665A0
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466660
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00466680
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004667C0
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466840
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)operator new(nSize: 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  free(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004668B0
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466980
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004669A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004669D0
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x004669E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466A40
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466A70
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x00466AB0
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466CD0
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)&defaultValue;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)&defaultValue;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x00466DC0
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466E30
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004670B0
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467220
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        free(pMem: *p_m_text);
        free(pMem: p_m_text[1]);
        *p_m_text = nullptr;
        free(pMem: p_m_text);
        v3->m_pText = nullptr;
      }
      free(pMem: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467350
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004673F0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "CloseCompletionList";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467480
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CConsolePanel::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "CompletionCommand";
    v4.func = v2;
    v4.firstParamName = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467520
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)operator new(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)operator new(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)operator new(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00467860
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00467890
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004678A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004678D0
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004679A0
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::CompletionItem *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  char **v4; // ebx
  vgui::CConsolePanel::CompletionItem *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel::CompletionItem **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  char *v13; // eax
  vgui::CConsolePanel *v14; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  vgui::CConsolePanel *v19; // eax
  ICvar::ICVarIteratorInternal *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  ICvar::ICVarIteratorInternal **v25; // esi
  ICvar::ICVarIteratorInternal_vtbl *v26; // esi
  char *v27; // edi
  unsigned int v28; // kr00_4
  void (__thiscall *v29)(ICvar::ICVarIteratorInternal *); // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  vgui::CConsolePanel::CompletionItem *v35; // eax
  vgui::CConsolePanel *v36; // esi
  int m_Size; // ebx
  int v38; // eax
  vgui::CConsolePanel::CompletionItem **v39; // ecx
  int v40; // eax
  vgui::CConsolePanel::CompletionItem **v41; // ebx
  vgui::CConsolePanel::CompletionItem *v42; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  vgui::CHistoryItem *v51; // esi
  char *v52; // eax
  vgui::CHistoryItem *v53; // eax
  vgui::CHistoryItem *v54; // esi
  unsigned int v55; // kr04_4
  char *v56; // eax
  char v57; // [esp+10h] [ebp-238h]
  char *v58; // [esp+10h] [ebp-238h]
  char strValue[512]; // [esp+20h] [ebp-228h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+220h] [ebp-28h] BYREF
  float v61; // [esp+234h] [ebp-14h]
  char *bCheckSubstrings; // [esp+238h] [ebp-10h]
  vgui::CConsolePanel *v63; // [esp+23Ch] [ebp-Ch]
  ICvar::Iterator iter; // [esp+240h] [ebp-8h]
  vgui::CConsolePanel::CompletionItem *item; // [esp+244h] [ebp-4h]
  vgui::CConsolePanel::CompletionItem *comp; // [esp+250h] [ebp+8h]
  vgui::CConsolePanel::CompletionItem *compa; // [esp+250h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  v63 = this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)_V_strlen(str: (const char *)&text->m_bIsCommand) < 1 )
  {
    iter.m_pIter = nullptr;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      item = nullptr;
      while ( 1 )
      {
        v4 = (char **)(&item->m_bIsCommand + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          v5->m_bIsCommand = true;
          v5->m_pCommand = nullptr;
          v5->m_pText = nullptr;
          comp = v5;
        }
        else
        {
          comp = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<unsigned long,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel::CompletionItem **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = comp;
        comp->m_bIsCommand = false;
        comp->m_pCommand = nullptr;
        v11 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = (char *)&defaultValue;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        v14 = v63;
        ++item;
        comp->m_pText = v12;
        if ( (int)++iter.m_pIter >= v14->m_CommandHistory.m_Size )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)v14;
      }
    }
    return;
  }
  LOBYTE(bCheckSubstrings) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(
                                        partial: (char *)&text->m_bIsCommand,
                                        a2: (int)text);
    m_pIter = nullptr;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&commands, 0, sizeof(commands));
      v19 = (vgui::CConsolePanel *)AutoCompleteSuggest(
                                     this: AutoCompleteCommmandFromPartial,
                                     a2: (const char *)&text->m_bIsCommand,
                                     a3: &commands);
      if ( (int)v19 > 0 )
      {
        compa = nullptr;
        v63 = v19;
        while ( 1 )
        {
          v20 = (ICvar::ICVarIteratorInternal *)operator new(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1].__vftable = nullptr;
            v20[2].__vftable = nullptr;
            LOBYTE(v20->__vftable) = 1;
            m_pIter = v20;
            iter.m_pIter = v20;
          }
          else
          {
            iter.m_pIter = nullptr;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<unsigned long,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (ICvar::ICVarIteratorInternal **)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_pIter;
          LOBYTE(m_pIter->__vftable) = 0;
          m_pIter[1].__vftable = nullptr;
          v26 = (ICvar::ICVarIteratorInternal_vtbl *)operator new(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = (char *)CUtlString::operator char const *(this: (CUtlString *)(&compa->m_bIsCommand
                                                                               + (unsigned int)commands.m_Memory.m_pMemory));
            bCheckSubstrings = v27;
            v26->SetFirst = nullptr;
            v26->Next = nullptr;
            LOBYTE(v26->IsValid) = 0;
            free(pMem: nullptr);
            v28 = strlen(v27);
            v29 = (void (__thiscall *)(ICvar::ICVarIteratorInternal *))operator new(nSize: v28 + 1);
            v26->SetFirst = v29;
            _V_memset(dest: v29, fill: 0, count: v28 + 1);
            V_strncpy(pDest: (char *)v26->SetFirst, pSrc: bCheckSubstrings, maxLen: v28 + 1);
            m_pIter = iter.m_pIter;
            LOBYTE(v26->IsValid) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          compa = (vgui::CConsolePanel::CompletionItem *)((char *)compa + 16);
          v30 = v63 == (vgui::CConsolePanel *)1;
          v63 = (vgui::CConsolePanel *)((char *)v63 - 1);
          m_pIter[2].__vftable = v26;
          if ( v30 )
            break;
          m_pIter = nullptr;
        }
      }
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &commands);
      return;
    }
    LOBYTE(bCheckSubstrings) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  iter.m_pIter = v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_80;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_80;
    v57 = (char)bCheckSubstrings;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: v63,
            command: v34,
            text: (char *)&text->m_bIsCommand,
            bCheckSubstrings: v57) )
      goto LABEL_80;
    v35 = (vgui::CConsolePanel::CompletionItem *)operator new(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      v35->m_bIsCommand = true;
      v35->m_pCommand = nullptr;
      v35->m_pText = nullptr;
      item = v35;
    }
    else
    {
      item = nullptr;
    }
    v36 = v63;
    m_Size = v63->m_CompletionList.m_Size;
    v38 = v63->m_CompletionList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v38 )
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v63->m_CompletionList,
        num: m_Size - v38 + 1);
    ++v36->m_CompletionList.m_Size;
    v39 = v36->m_CompletionList.m_Memory.m_pMemory;
    v40 = v36->m_CompletionList.m_Size - m_Size - 1;
    v36->m_CompletionList.m_pElements = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v39[m_Size + 1], src: (unsigned __int8 *)&v39[m_Size], count: 4 * v40);
    v41 = &v36->m_CompletionList.m_Memory.m_pMemory[m_Size];
    if ( v41 != nullptr )
      *v41 = item;
    v42 = item;
    item->m_pCommand = v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      v42->m_bIsCommand = true;
      v53 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      v54 = v53;
      if ( v53 != nullptr )
      {
        v53->m_text = nullptr;
        v53->m_extraText = nullptr;
        v53->m_bHasExtra = false;
        free(pMem: nullptr);
        v55 = strlen(v43);
        v56 = (char *)operator new(nSize: v55 + 1);
        v54->m_text = v56;
        _V_memset(dest: v56, fill: 0, count: v55 + 1);
        V_strncpy(pDest: v54->m_text, pSrc: v43, maxLen: v55 + 1);
        v54->m_bHasExtra = false;
      }
      else
      {
        v54 = nullptr;
      }
      item->m_pText = v54;
    }
    else
    {
      v42->m_bIsCommand = false;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: (void *)&ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = &defaultValue;
            }
            v58 = (char *)m_pszName;
            v47 = (char *)v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v58);
            item->m_pText = v48;
          }
          else
          {
            item->m_pText = nullptr;
          }
          goto LABEL_79;
        }
        v49 = (int)v33[1].m_pNext[2].__vftable;
      }
      if ( v44 != nullptr )
      {
        v61 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = v61;
      }
      else
      {
        v50 = *(float *)&v33[1].m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%f", v50);
      v51 = (vgui::CHistoryItem *)operator new(nSize: 0xCu);
      if ( v51 != nullptr )
      {
        v52 = (char *)v33->GetName(this: v33);
        v51->m_text = nullptr;
        v51->m_extraText = nullptr;
        v51->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v51, text: v52, extra: strValue);
        item->m_pText = v51;
      }
      else
      {
        item->m_pText = nullptr;
      }
    }
LABEL_79:
    v31 = iter.m_pIter;
LABEL_80:
    v31->Next(this: v31);
  }
  if ( v63->m_CompletionList.m_Size >= 2 )
    CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int>>::Sort(
      this: &v63->m_CompletionList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))vgui::CConsolePanel::CompletionItemCompare);
  free(pMem: v31);
}

//------------------------------------------------------------------------------
// Address: 0x00467FC0
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp+20h] [ebp-110h]
  int v19; // [esp+24h] [ebp-10Ch]
  char text[259]; // [esp+2Ch] [ebp-104h] BYREF
  bool altKeyDown; // [esp+12Fh] [ebp-1h]
  char hitTilde_3; // [esp+13Bh] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = _V_strlen(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (hitTilde_3 = 0, v6 == 96) )
      hitTilde_3 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), altKeyDown = false, v7) )
    {
      altKeyDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && hitTilde_3 != 0 )
    {
      v9 = !altKeyDown;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: &defaultValue,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(
        this,
        text: (vgui::CConsolePanel::CompletionItem *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          text[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest: text, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest: text, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: text);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: text, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468280
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel::CompletionItem *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      free(pMem: m_pMemory->m_text);
      free(pMem: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: v21, value: 0, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: v6, value: 0, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = &defaultValue;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (char *)v21,
    extra: (char *)v6);
  m_szPartialText = (vgui::CConsolePanel::CompletionItem *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00468560
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: &defaultValue);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: (unsigned __int8 *)szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)_V_strlen(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100F43C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x103C0A70
// Name: public: static char const __near * vgui::CConsolePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsolePanel::GetPanelClassName()
{
  return "CConsolePanel";
}

//------------------------------------------------------------------------------
// Address: 0x103C0A80
// Name: public: static char const __near * vgui::CConsoleDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CConsoleDialog::GetPanelClassName()
{
  return "CConsoleDialog";
}

//------------------------------------------------------------------------------
// Address: 0x103C0A90
// Name: public: static char const __near * CNonFocusableMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNonFocusableMenu::GetPanelClassName()
{
  return "CNonFocusableMenu";
}

//------------------------------------------------------------------------------
// Address: 0x103C0AA0
// Name: public: virtual void TabCatchingTextEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKeyCodeTyped(TabCatchingTextEntry *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  vgui::Panel *v6; // eax
  TabCatchingTextEntry_vtbl *v7; // edi
  int v8; // eax

  if ( code == KEY_TAB )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: KEY_TAB);
  }
  else if ( code == KEY_ENTER )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "submit");
    else
      v5 = nullptr;
    v6 = this->GetParent(this);
    v7 = this->__vftable;
    v8 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v6->GetVPanel)(a1: v6, a2: v5, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v7->PostMessage_2)(a1: this, a2: v8);
  }
  else
  {
    vgui::TextEntry::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0B40
// Name: public: virtual void TabCatchingTextEntry::OnKillFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TabCatchingTextEntry::OnKillFocus(TabCatchingTextEntry *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  TabCatchingTextEntry_vtbl *v4; // edi
  int v5; // eax

  if ( g_pVGuiInput->GetFocus(this: g_pVGuiInput) != this->m_pCompletionList )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "CloseCompletionList");
    else
      v3 = nullptr;
    v4 = this->__vftable;
    v5 = ((int (__thiscall *)(TabCatchingTextEntry *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v3, a3: 0);
    ((void (__thiscall *)(TabCatchingTextEntry *, int))v4->PostMessage)(a1: this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0BA0
// Name: public: void vgui::CHistoryItem::SetText(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CHistoryItem::SetText(vgui::CHistoryItem *this, char *text, char *extra)
{
  unsigned int v4; // kr00_4
  char *v5; // eax
  unsigned int v6; // kr04_4
  char *v7; // eax
  char *m_extraText; // [esp-4h] [ebp-10h]

  C_BaseEntity::operator delete(pMem: this->m_text);
  v4 = strlen(text);
  v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
  this->m_text = v5;
  _V_memset(dest: (int)v5, fill: nullptr, count: v4 + 1);
  V_strncpy(pDest: this->m_text, pSrc: text, maxLen: v4 + 1);
  if ( extra != nullptr )
  {
    m_extraText = this->m_extraText;
    this->m_bHasExtra = true;
    C_BaseEntity::operator delete(pMem: m_extraText);
    v6 = strlen(extra);
    v7 = (char *)MemAlloc_Alloc(nSize: v6 + 1);
    this->m_extraText = v7;
    _V_memset(dest: (int)v7, fill: nullptr, count: v6 + 1);
    V_strncpy(pDest: this->m_extraText, pSrc: extra, maxLen: v6 + 1);
  }
  else
  {
    this->m_bHasExtra = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0C50
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetItemText(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetItemText(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  const char *m_extraText; // ecx
  const char *v3; // eax
  char *m_text; // eax

  text[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText == nullptr )
    return text;
  if ( !m_pText->m_bHasExtra )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)prType;
    V_strncpy(pDest: text, pSrc: m_text, maxLen: 256);
    return text;
  }
  m_extraText = m_pText->m_extraText;
  v3 = m_pText->m_text;
  if ( v3 == nullptr )
    v3 = prType;
  V_snprintf(pDest: text, maxLen: 0x100u, pFormat: "%s %s", v3, m_extraText);
  return text;
}

//------------------------------------------------------------------------------
// Address: 0x103C0CC0
// Name: public: char const __near * vgui::CConsolePanel::CompletionItem::GetCommand(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::CConsolePanel::CompletionItem::GetCommand(vgui::CConsolePanel::CompletionItem *this)
{
  vgui::CHistoryItem *m_pText; // eax
  char *m_text; // eax

  text_0[0] = 0;
  m_pText = this->m_pText;
  if ( m_pText != nullptr )
  {
    m_text = m_pText->m_text;
    if ( m_text == nullptr )
      m_text = (char *)prType;
    V_strncpy(pDest: text_0, pSrc: m_text, maxLen: 256);
  }
  return text_0;
}

//------------------------------------------------------------------------------
// Address: 0x103C0D00
// Name: public: virtual void vgui::CConsolePanel::ColorPrint(class Color const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ColorPrint(vgui::CConsolePanel *this, const Color *clr, const char *msg)
{
  if ( this->m_szPartialText[134] != 0 )
  {
    vgui::RichText::SetText(this: *(vgui::RichText **)&this->m_OnDelete_register, text: prType);
    vgui::RichText::GotoTextEnd(this: *(vgui::RichText **)&this->m_OnDelete_register);
  }
  vgui::RichText::InsertColorChange(this: *(vgui::RichText **)&this->m_OnDelete_register, col: *clr);
  vgui::RichText::InsertString(this: *(vgui::RichText **)&this->m_OnDelete_register, text: msg);
}

//------------------------------------------------------------------------------
// Address: 0x103C0D50
// Name: public: virtual void vgui::CConsolePanel::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::Print(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalMouseDoublePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x103C0D70
// Name: public: virtual void vgui::CConsolePanel::DPrint(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DPrint(vgui::CConsolePanel *this, const char *msg)
{
  ((void (__stdcall *)(vgui::Panel::PanelMessageFunc_InternalKeyCodePressed *, const char *))this->GetVPanel)(
    a1: &this->m_InternalKeyCodePressed_register,
    a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x103C0D90
// Name: FindAutoCompleteCommmandFromPartial
// Source: json
//------------------------------------------------------------------------------
ConCommand *__usercall FindAutoCompleteCommmandFromPartial@<eax>(const char *partial@<eax>, int a2@<esi>)
{
  char *v2; // eax
  ConCommand *result; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  V_strncpy(pDest: command, pSrc: partial, maxLen: 256);
  v2 = _V_strstr(s1: command, search: " ");
  if ( v2 != nullptr )
    *v2 = 0;
  result = (ConCommand *)((int (__thiscall *)(ICvar *, char *, int))g_pCVar->FindCommand_2)(
                           a1: g_pCVar,
                           a2: command,
                           a3: a2);
  if ( result != nullptr )
    return ((unsigned __int8 (__thiscall *)(ConCommand *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))result->CanAutoComplete)(
             a1: result,
             a2: *(_DWORD *)command,
             a3: *(_DWORD *)&command[4],
             a4: *(_DWORD *)&command[8],
             a5: *(_DWORD *)&command[12],
             a6: *(_DWORD *)&command[16],
             a7: *(_DWORD *)&command[20],
             a8: *(_DWORD *)&command[24],
             a9: *(_DWORD *)&command[28],
             a10: *(_DWORD *)&command[32],
             a11: *(_DWORD *)&command[36],
             a12: *(_DWORD *)&command[40],
             a13: *(_DWORD *)&command[44],
             a14: *(_DWORD *)&command[48],
             a15: *(_DWORD *)&command[52],
             a16: *(_DWORD *)&command[56],
             a17: *(_DWORD *)&command[60],
             a18: *(_DWORD *)&command[64],
             a19: *(_DWORD *)&command[68],
             a20: *(_DWORD *)&command[72],
             a21: *(_DWORD *)&command[76],
             a22: *(_DWORD *)&command[80],
             a23: *(_DWORD *)&command[84],
             a24: *(_DWORD *)&command[88],
             a25: *(_DWORD *)&command[92],
             a26: *(_DWORD *)&command[96],
             a27: *(_DWORD *)&command[100],
             a28: *(_DWORD *)&command[104],
             a29: *(_DWORD *)&command[108],
             a30: *(_DWORD *)&command[112],
             a31: *(_DWORD *)&command[116],
             a32: *(_DWORD *)&command[120],
             a33: *(_DWORD *)&command[124],
             a34: *(_DWORD *)&command[128],
             a35: *(_DWORD *)&command[132],
             a36: *(_DWORD *)&command[136],
             a37: *(_DWORD *)&command[140],
             a38: *(_DWORD *)&command[144],
             a39: *(_DWORD *)&command[148],
             a40: *(_DWORD *)&command[152],
             a41: *(_DWORD *)&command[156],
             a42: *(_DWORD *)&command[160],
             a43: *(_DWORD *)&command[164],
             a44: *(_DWORD *)&command[168],
             a45: *(_DWORD *)&command[172],
             a46: *(_DWORD *)&command[176],
             a47: *(_DWORD *)&command[180],
             a48: *(_DWORD *)&command[184],
             a49: *(_DWORD *)&command[188],
             a50: *(_DWORD *)&command[192],
             a51: *(_DWORD *)&command[196],
             a52: *(_DWORD *)&command[200],
             a53: *(_DWORD *)&command[204],
             a54: *(_DWORD *)&command[208],
             a55: *(_DWORD *)&command[212],
             a56: *(_DWORD *)&command[216],
             a57: *(_DWORD *)&command[220],
             a58: *(_DWORD *)&command[224],
             a59: *(_DWORD *)&command[228],
             a60: *(_DWORD *)&command[232],
             a61: *(_DWORD *)&command[236],
             a62: *(_DWORD *)&command[240],
             a63: *(_DWORD *)&command[244],
             a64: *(_DWORD *)&command[248]) != 0
         ? result
         : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C0E00
// Name: protected: bool vgui::CConsolePanel::CommandMatchesText(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::CommandMatchesText(
        vgui::CConsolePanel *this,
        char *command,
        char *text,
        bool bCheckSubstrings)
{
  signed int v4; // ebx
  char *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // edi
  int v8; // eax
  signed int v9; // eax
  unsigned int v11; // eax
  char uprCommand[256]; // [esp+4h] [ebp-200h] BYREF
  char substring[256]; // [esp+104h] [ebp-100h] BYREF

  if ( bCheckSubstrings )
  {
    v4 = _V_strlen(str: text);
    V_strncpy(pDest: substring, pSrc: text, maxLen: 256);
    V_strncpy(pDest: uprCommand, pSrc: command, maxLen: 256);
    _V_strupr(start: uprCommand);
    _V_strupr(start: substring);
    v5 = substring;
    while ( 1 )
    {
      _V_strstr(s1: v5, search: " ");
      v7 = v6;
      if ( v6 != nullptr )
        *v6 = 0;
      _V_strstr(s1: uprCommand, search: v5);
      if ( v8 == 0 )
        break;
      v9 = _V_strlen(str: v5) + 1;
      if ( v4 > v9 )
      {
        v4 -= v9;
        v5 += v9;
        if ( v7 != nullptr )
          continue;
      }
      return true;
    }
    return false;
  }
  else
  {
    v11 = _V_strlen(str: text);
    return V_strncasecmp(s1: text, s2: command, n: v11) == 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0EF0
// Name: public: bool vgui::CConsolePanel::TextEntryHasFocus(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::CConsolePanel::TextEntryHasFocus(vgui::CConsolePanel *this)
{
  vgui::IInput *v1; // esi
  unsigned int v2; // edi

  v1 = g_pVGuiInput;
  v2 = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  return v1->GetFocus(this: v1) == v2;
}

//------------------------------------------------------------------------------
// Address: 0x103C0F20
// Name: protected: void vgui::CConsolePanel::UpdateCompletionListPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::UpdateCompletionListPosition(vgui::CConsolePanel *this)
{
  int Tall; // eax
  int menuwide; // [esp+4h] [ebp-10h] BYREF
  int menutall; // [esp+8h] [ebp-Ch] BYREF
  int ex; // [esp+Ch] [ebp-8h] BYREF
  int ey; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pEntry, x: &ex, y: &ey);
  if ( this->m_bStatusVersion )
  {
    vgui::Panel::GetSize(this: this->m_pCompletionList, wide: &menuwide, tall: &menutall);
    ey += -4 - menutall;
  }
  else
  {
    Tall = vgui::Panel::GetTall(this: this->m_pEntry);
    ey += Tall;
  }
  vgui::Panel::LocalToScreen(this, x: &ex, y: &ey);
  vgui::Panel::SetPos(this: this->m_pCompletionList, x: ex, y: ey);
  if ( this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
  {
    this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    this->MoveToFront(this);
    this->m_pCompletionList->MoveToFront(this: this->m_pCompletionList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0FE0
// Name: protected: virtual void vgui::CConsolePanel::CloseCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::CloseCompletionList(vgui::CConsolePanel *this)
{
  this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C1000
// Name: protected: virtual void vgui::CConsolePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ApplySchemeSettings(vgui::CConsolePanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::IScheme v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v9; // al
  int v10; // eax
  vgui::Menu_vtbl *v11; // ebx
  bool (__thiscall *v12)(vgui::IClientPanel *); // eax
  bool v13; // al
  int v14; // eax
  vgui::Button_vtbl *v15; // ebx
  bool (__thiscall *v16)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "Console.DevTextColor", a4: v2);
  v4.__vftable = v2->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4.GetFont(this: v2, a2: "ConsoleText", a3: v5);
  vgui::RichText::SetFont(this: this->m_pHistory, font: v6);
  v7 = this->m_pEntry->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v9 = IsProportional(this);
  v10 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v9);
  v7->SetFont(this: this->m_pEntry, a2: v10);
  v11 = this->m_pCompletionList->__vftable;
  v12 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v13 = v12(this);
  v14 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v13);
  v11->SetFont(this: this->m_pCompletionList, a2: v14);
  v15 = this->m_pSubmit->__vftable;
  v16 = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v17 = v16(this);
  v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
          a1: v2,
          a2: "DefaultSmall",
          a3: v17);
  v15->SetFont(this: this->m_pSubmit, a2: v18);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C1140
// Name: protected: virtual void vgui::CConsolePanel::OnMenuItemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnMenuItemSelected(vgui::CConsolePanel *this, char *command)
{
  int v3; // eax

  strstr(str1: (unsigned __int8 *)command, str2: "...");
  if ( v3 != 0 )
  {
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: true);
  }
  else
  {
    this->m_pEntry->SetText(this: this->m_pEntry, a2: command);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
    this->m_pEntry->InsertChar(this: this->m_pEntry, a2: 32);
    this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C11C0
// Name: public: virtual void vgui::CConsolePanel::GetConsoleText(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::GetConsoleText(vgui::CConsolePanel *this, char *pchText, unsigned int bufSize)
{
  wchar_t *v4; // esi

  v4 = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)bufSize >> 31 != 0 ? -1 : 2 * bufSize);
  vgui::RichText::GetText(
    this: *(vgui::RichText **)&this->m_OnDelete_register,
    offset: 0,
    buf: v4,
    bufLenInBytes: 2 * bufSize);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v4, a3: pchText, a4: bufSize);
  C_BaseEntity::operator delete(pMem: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103C1220
// Name: public: void vgui::CConsolePanel::DumpConsoleTextToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::DumpConsoleTextToFile(vgui::CConsolePanel *this)
{
  vgui::CConsolePanel *v1; // edi
  int v2; // esi
  void *v3; // esi
  int v4; // kr00_4
  int v5; // esi
  int v6; // esi
  wchar_t buf[512]; // [esp+8h] [ebp-810h] BYREF
  char ansi[512]; // [esp+408h] [ebp-410h] BYREF
  char szfile[512]; // [esp+608h] [ebp-210h] BYREF
  vgui::CConsolePanel *v10; // [esp+808h] [ebp-10h]
  int pos; // [esp+80Ch] [ebp-Ch]
  void *handle; // [esp+810h] [ebp-8h]
  char ret; // [esp+817h] [ebp-1h] BYREF

  v1 = this;
  v10 = this;
  v2 = 0;
  while ( 1 )
  {
    _snprintf(string: szfile, count: 0x200u, format: "condump%03d.txt", v2);
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szfile, a3: nullptr) )
      break;
    if ( ++v2 >= 1000 )
    {
      v1->Print(
        this: &v1->IConsoleDisplayFunc,
        a2: "Can't condump! Too many existing condump output files in the gamedir!\n");
      return;
    }
  }
  v3 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szfile, a3: "wb", a4: 0);
  handle = v3;
  if ( v3 != nullptr )
  {
    vgui::RichText::GetText(this: v1->m_pHistory, offset: 0, buf, bufLenInBytes: 0x400u);
    pos = 511;
    if ( buf[0] != 0 )
    {
      do
      {
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: buf, a3: ansi, a4: 512);
        v4 = strlen(ansi);
        v5 = 0;
        if ( v4 > 0 )
        {
          do
          {
            if ( ansi[v5] == 10 )
            {
              ret = 13;
              g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &ret, a3: 1, a4: handle);
            }
            g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: &ansi[v5++], a3: 1, a4: handle);
          }
          while ( v5 < v4 );
          v1 = v10;
        }
        v6 = pos;
        vgui::RichText::GetText(this: v1->m_pHistory, offset: pos, buf, bufLenInBytes: 0x400u);
        pos = v6 + 511;
      }
      while ( buf[0] != 0 );
      v3 = handle;
    }
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
    v1->Print(this: &v1->IConsoleDisplayFunc, a2: "console dumped to ");
    v1->Print(this: &v1->IConsoleDisplayFunc, a2: szfile);
  }
  else
  {
    v1->Print(this: &v1->IConsoleDisplayFunc, a2: "Unable to condump to ");
    v1->Print(this: &v1->IConsoleDisplayFunc, a2: szfile);
  }
  v1->Print(this: &v1->IConsoleDisplayFunc, a2: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x103C1440
// Name: public: virtual void vgui::CConsoleDialog::OnScreenSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::OnScreenSizeChanged(vgui::CConsoleDialog *this, int iOldWide, int iOldTall)
{
  int v4; // eax
  int v5; // ecx
  int sx; // [esp+4h] [ebp-8h] BYREF
  int sy; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::OnScreenSizeChanged(this, iOldWide, iOldTall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &sx, a3: &sy);
  vgui::Panel::GetSize(this, wide: &iOldWide, tall: &iOldTall);
  v4 = iOldWide;
  if ( iOldWide <= sx )
  {
    if ( iOldTall <= sy )
      return;
    goto LABEL_5;
  }
  v4 = sx;
  v5 = iOldTall;
  iOldWide = sx;
  if ( iOldTall > sy )
  {
LABEL_5:
    v5 = sy;
    iOldTall = sy;
  }
  vgui::Panel::SetSize(this, wide: v4, tall: v5);
}

//------------------------------------------------------------------------------
// Address: 0x103C14C0
// Name: public: virtual void vgui::CConsoleDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::PerformLayout(vgui::CConsoleDialog *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: this->m_pConsolePanel, x, y, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x103C1510
// Name: public: virtual void vgui::CConsoleDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Activate(vgui::CConsoleDialog *this)
{
  vgui::Frame::Activate(this);
  this->m_pConsolePanel->m_pEntry->RequestFocus(this: this->m_pConsolePanel->m_pEntry, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103C1530
// Name: public: virtual void vgui::CConsoleDialog::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::OnCommandSubmitted(vgui::CConsoleDialog *this, char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: pCommand);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1580
// Name: public: void vgui::CConsoleDialog::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Clear(vgui::CConsoleDialog *this)
{
  vgui::CConsolePanel *m_pConsolePanel; // esi

  m_pConsolePanel = this->m_pConsolePanel;
  vgui::RichText::SetText(this: m_pConsolePanel->m_pHistory, text: prType);
  vgui::RichText::GotoTextEnd(this: m_pConsolePanel->m_pHistory);
}

//------------------------------------------------------------------------------
// Address: 0x103C15B0
// Name: public: void vgui::CConsoleDialog::DumpConsoleTextToFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::DumpConsoleTextToFile(vgui::CConsoleDialog *this)
{
  vgui::CConsolePanel::DumpConsoleTextToFile(this: this->m_pConsolePanel);
}

//------------------------------------------------------------------------------
// Address: 0x103C15F0
// Name: public: CNonFocusableMenu::CNonFocusableMenu(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNonFocusableMenu *__thiscall CNonFocusableMenu::CNonFocusableMenu(
        CNonFocusableMenu *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Menu::Menu(this, parent, panelName);
  this->__vftable = (CNonFocusableMenu_vtbl *)&CNonFocusableMenu::`vftable';
  if ( `CNonFocusableMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
    v4->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
    v5->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Menu");
  }
  if ( `CNonFocusableMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNonFocusableMenu::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
    v6->pfnClassName = CNonFocusableMenu::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Menu");
  }
  this->m_pFocus = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C16C0
// Name: public: virtual unsigned int CNonFocusableMenu::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNonFocusableMenu::GetCurrentKeyFocus(CNonFocusableMenu *this)
{
  if ( this->m_pFocus != nullptr )
    return this->m_pFocus->GetVPanel(this: this->m_pFocus);
  else
    return this->GetVPanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C16E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CNonFocusableMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNonFocusableMenu::GetMessageMap(CNonFocusableMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C1710
// Name: public: virtual struct PanelAnimationMap __near * CNonFocusableMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNonFocusableMenu::GetAnimMap(CNonFocusableMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CNonFocusableMenu");
}

//------------------------------------------------------------------------------
// Address: 0x103C1720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNonFocusableMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNonFocusableMenu::GetKBMap(CNonFocusableMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNonFocusableMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNonFocusableMenu::GetKBMap'::`2'::s_pMap;
  `CNonFocusableMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNonFocusableMenu");
  `CNonFocusableMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C1780
// Name: public: vgui::CHistoryItem::CHistoryItem(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CHistoryItem *__thiscall vgui::CHistoryItem::CHistoryItem(vgui::CHistoryItem *this, char *text, char *extra)
{
  this->m_text = nullptr;
  this->m_extraText = nullptr;
  this->m_bHasExtra = false;
  vgui::CHistoryItem::SetText(this, text, extra);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C17B0
// Name: protected: virtual void vgui::CConsolePanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall vgui::CConsolePanel::OnThink(vgui::CConsolePanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->IsVisible(this) && this->m_pCompletionList->IsVisible(this: this->m_pCompletionList) )
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C17F0
// Name: protected: virtual void vgui::CConsolePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::PerformLayout(vgui::CConsolePanel *this)
{
  vgui::FocusNavGroup *v2; // eax
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::TextEntry_vtbl *v7; // ebx
  int v8; // edi
  int v9; // eax
  vgui::RichText_vtbl *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // edi
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  v2 = this->GetFocusNavGroup(this);
  v2->SetDefaultButton(this: v2, a2: this->m_pSubmit);
  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  v7 = this->m_pEntry->__vftable;
  v8 = v6;
  v9 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 8))(a1: v6, a2: "DepressedButtonBorder");
  v7->SetBorder(this: this->m_pEntry, a2: (vgui::IBorder *)v9);
  v10 = this->m_pHistory->__vftable;
  v11 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 8))(a1: v8, a2: "DepressedButtonBorder");
  v10->SetBorder(this: this->m_pHistory, a2: (vgui::IBorder *)v11);
  vgui::Panel::GetSize(this, &wide, &tall);
  if ( this->m_bStatusVersion )
  {
    v13 = wide / 2;
    if ( wide > 400 )
      v13 = 200;
    vgui::Panel::SetBounds(this: this->m_pEntry, x: 2, y: 2, wide: v13, tall: tall - 4);
    vgui::Panel::SetBounds(this: this->m_pHistory, x: v13 + 4, y: 2, wide: wide - v13 - 2, tall: tall - 4);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
  else
  {
    vgui::Panel::SetPos(this: this->m_pHistory, x: 8, y: 12);
    vgui::Panel::SetSize(this: this->m_pHistory, wide: wide - 16, tall: tall - 52);
    this->m_pHistory->InvalidateLayout(this: this->m_pHistory, a2: false, a3: false);
    v12 = wide - 79;
    vgui::Panel::SetPos(this: this->m_pSubmit, x: wide - 79, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pSubmit, wide: 64, tall: 24);
    vgui::Panel::SetPos(this: this->m_pEntry, x: 8, y: tall - 32);
    vgui::Panel::SetSize(this: this->m_pEntry, wide: v12 - 20, tall: 24);
    vgui::CConsolePanel::UpdateCompletionListPosition(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1A10
// Name: public: static int vgui::CConsolePanel::CompletionItemCompare(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl vgui::CConsolePanel::CompletionItemCompare(
        vgui::CConsolePanel::CompletionItem *const *i1,
        vgui::CConsolePanel::CompletionItem *const *i2)
{
  _BYTE *v2; // eax
  const char *v3; // esi
  char **v4; // eax
  char *v5; // eax
  _BYTE *v6; // eax
  const char *v7; // eax
  char **v8; // eax
  char *v9; // eax

  v2 = *i2;
  if ( **(_BYTE **)i2 != 0 || *((_DWORD *)v2 + 1) != 0 )
  {
    v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v2 + 1) + 24))(a1: *((_DWORD *)v2 + 1));
  }
  else
  {
    text_0[0] = 0;
    v4 = *((char ***)v2 + 2);
    if ( v4 != nullptr )
    {
      v5 = *v4;
      if ( v5 == nullptr )
        v5 = (char *)prType;
      V_strncpy(pDest: text_0, pSrc: v5, maxLen: 256);
    }
    v3 = text_0;
  }
  v6 = *i1;
  if ( **(_BYTE **)i1 != 0 || *((_DWORD *)v6 + 1) != 0 )
  {
    v7 = (const char *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v6 + 1) + 24))(a1: *((_DWORD *)v6 + 1));
  }
  else
  {
    text_0[0] = 0;
    v8 = *((char ***)v6 + 2);
    if ( v8 != nullptr )
    {
      v9 = *v8;
      if ( v9 == nullptr )
        v9 = (char *)prType;
      V_strncpy(pDest: text_0, pSrc: v9, maxLen: 256);
    }
    v7 = text_0;
  }
  return strcmp(v7, v3);
}

//------------------------------------------------------------------------------
// Address: 0x103C1B00
// Name: protected: bool vgui::CConsolePanel::GetCompletionItemText(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::CConsolePanel::GetCompletionItemText(
        vgui::CConsolePanel *this,
        char *pDest,
        int completionIndex,
        int maxLen)
{
  vgui::CConsolePanel::CompletionItem *v4; // ecx
  char *Command; // eax
  char *ItemText; // eax

  *pDest = 0;
  if ( completionIndex < 0 || completionIndex >= this->m_CompletionList.m_Size )
    return 0;
  v4 = this->m_CompletionList.m_Memory.m_pMemory[completionIndex];
  if ( v4->m_bIsCommand || v4->m_pCommand == nullptr )
  {
    ItemText = (char *)vgui::CConsolePanel::CompletionItem::GetItemText(this: v4);
    V_strncpy(pDest, pSrc: ItemText, maxLen);
    return 1;
  }
  else
  {
    Command = (char *)vgui::CConsolePanel::CompletionItem::GetCommand(this: v4);
    V_strncpy(pDest, pSrc: Command, maxLen);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1B70
// Name: protected: void vgui::CConsolePanel::OnAutoComplete(enum vgui::CConsolePanel::eCompletionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnAutoComplete(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::eCompletionType completionType)
{
  vgui::CConsolePanel::eCompletionType v3; // ebx
  bool v4; // sf
  int m_iNextCompletion; // eax
  int v6; // ecx
  int m_Size; // eax
  vgui::CConsolePanel::CompletionItem *v8; // ecx
  unsigned int v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  char *Command; // [esp-Ch] [ebp-218h]
  char *ItemText; // [esp-Ch] [ebp-218h]
  char lastMatchText[256]; // [esp+8h] [ebp-204h] BYREF
  char completedText[260]; // [esp+108h] [ebp-104h] BYREF

  if ( !this->m_bAutoCompleteMode )
  {
    this->m_iNextCompletion = 0;
    this->m_bAutoCompleteMode = true;
  }
  v3 = completionType;
  if ( completionType == COMPLETE_TYPE_REVERSE )
  {
    v4 = this->m_iNextCompletion - 2 < 0;
    this->m_iNextCompletion -= 2;
    if ( v4 )
      this->m_iNextCompletion = this->m_CompletionList.m_Size - 1;
  }
  m_iNextCompletion = this->m_iNextCompletion;
  if ( m_iNextCompletion < 0 || m_iNextCompletion >= this->m_CompletionList.m_Size )
    this->m_iNextCompletion = 0;
  v6 = this->m_iNextCompletion;
  if ( v6 >= 0 )
  {
    m_Size = this->m_CompletionList.m_Size;
    if ( v6 < m_Size )
    {
      if ( completionType == COMPLETE_TYPE_COMMON_STRING && m_Size > 1 )
      {
        completedText[0] = 0;
        v8 = *this->m_CompletionList.m_Memory.m_pMemory;
        if ( v8->m_bIsCommand || v8->m_pCommand == nullptr )
        {
          ItemText = (char *)vgui::CConsolePanel::CompletionItem::GetItemText(this: v8);
          V_strncpy(pDest: completedText, pSrc: ItemText, maxLen: 254);
        }
        else
        {
          Command = (char *)vgui::CConsolePanel::CompletionItem::GetCommand(this: v8);
          V_strncpy(pDest: completedText, pSrc: Command, maxLen: 254);
        }
        vgui::CConsolePanel::GetCompletionItemText(
          this,
          pDest: lastMatchText,
          completionIndex: this->m_CompletionList.m_Size - 1,
          maxLen: 254);
        v9 = 0;
        if ( V_strncasecmp(s1: this->m_szPartialText, s2: completedText, n: strlen(this->m_szPartialText)) == 0
          && V_strncasecmp(s1: this->m_szPartialText, s2: lastMatchText, n: strlen(this->m_szPartialText)) == 0
          && strlen(completedText) != 0 )
        {
          do
          {
            v10 = toupper(c: lastMatchText[v9]);
            if ( toupper(c: completedText[v9]) != v10 )
              break;
            ++v9;
          }
          while ( v9 < strlen(completedText) );
        }
        completedText[v9] = 0;
        v3 = completionType;
      }
      else
      {
        vgui::CConsolePanel::GetCompletionItemText(this, pDest: completedText, completionIndex: v6, maxLen: 254);
        _V_strstr(s1: completedText, search: " ");
        if ( v11 == 0 )
          V_strncat(pDest: completedText, pSrc: " ", destBufferSize: 0x100u, max_chars_to_copy: -1);
        ++this->m_iNextCompletion;
      }
      if ( strlen(completedText) > strlen(this->m_szPartialText) )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: completedText);
        if ( v3 == COMPLETE_TYPE_COMMON_STRING )
          this->OnTextChanged(this, a2: this->m_pEntry);
      }
      this->m_pEntry->GotoTextEnd(this: this->m_pEntry);
      this->m_pEntry->SelectNone(this: this->m_pEntry);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1DF0
// Name: protected: virtual void vgui::CConsolePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnKeyCodeTyped(vgui::CConsolePanel *this, ButtonCode_t code)
{
  vgui::IInput *v4; // edi
  ButtonCode_t codea; // [esp+14h] [ebp+8h]

  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  v4 = g_pVGuiInput;
  codea = this->m_pEntry->GetVPanel(this: this->m_pEntry);
  if ( v4->GetFocus(this: v4) == codea )
  {
    switch ( code )
    {
      case KEY_TAB:
        if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
          && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
        {
          goto LABEL_5;
        }
        break;
      case KEY_DOWN:
LABEL_5:
        vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_FORWARD);
LABEL_9:
        this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
        return;
      case KEY_UP:
        break;
      default:
        return;
    }
    vgui::CConsolePanel::OnAutoComplete(this, completionType: COMPLETE_TYPE_REVERSE);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C1EE0
// Name: protected: void vgui::CConsolePanel::ClearCompletionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::ClearCompletionList(vgui::CConsolePanel *this)
{
  int v2; // eax
  vgui::CConsolePanel::CompletionItem *v3; // edi
  void **p_m_text; // esi
  bool v5; // sf
  vgui::CConsolePanel::CompletionItem **m_pMemory; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_CompletionList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_CompletionList.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      p_m_text = (void **)&v3->m_pText->m_text;
      if ( p_m_text != nullptr )
      {
        C_BaseEntity::operator delete(pMem: *p_m_text);
        C_BaseEntity::operator delete(pMem: p_m_text[1]);
        *p_m_text = nullptr;
        C_BaseEntity::operator delete(pMem: p_m_text);
        v3->m_pText = nullptr;
      }
      C_BaseEntity::operator delete(pMem: v3);
      v2 = i;
    }
    --v2;
  }
  v5 = this->m_CompletionList.m_Memory.m_nGrowSize < 0;
  this->m_CompletionList.m_Size = 0;
  if ( v5 )
  {
    this->m_CompletionList.m_pElements = this->m_CompletionList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_CompletionList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CompletionList.m_Memory.m_pMemory);
      this->m_CompletionList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_CompletionList.m_Memory.m_pMemory;
    this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
    this->m_CompletionList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2010
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C20B0
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarSlider::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CloseCompletionList";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2140
// Name: public: static void vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CompletionCommand";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C21E0
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Activate";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2270
// Name: public: static void vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C2310
// Name: public: vgui::CConsolePanel::CConsolePanel(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsolePanel *__thiscall vgui::CConsolePanel::CConsolePanel(
        vgui::CConsolePanel *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::RichText *v8; // eax
  vgui::RichText *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CNonFocusableMenu *v12; // eax
  CNonFocusableMenu *v13; // ebx
  vgui::TextEntry *v14; // edi
  vgui::TextEntry *v15; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  unsigned int bStatusVersiona; // [esp+1Ch] [ebp+10h]

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&IConsoleDisplayFunc::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  if ( `vgui::CConsolePanel::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
    v5->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsolePanel");
    v6->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsolePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
    v7->pfnClassName = vgui::CConsolePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::CConsolePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::CConsolePanel::PanelMessageFunc_CloseCompletionList::InitVar();
  vgui::CConsolePanel::PanelMessageFunc_OnMenuItemSelected::InitVar(a1: (int)&savedregs);
  this->m_PrintColor = 0;
  this->m_DPrintColor = 0;
  this->m_bStatusVersion = bStatusVersion;
  this->m_CompletionList.m_Memory.m_pMemory = nullptr;
  this->m_CompletionList.m_Memory.m_nAllocationCount = 0;
  this->m_CompletionList.m_Memory.m_nGrowSize = 0;
  this->m_CompletionList.m_Size = 0;
  this->m_CompletionList.m_pElements = nullptr;
  this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
  this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  this->m_CommandHistory.m_Memory.m_nGrowSize = 0;
  this->m_CommandHistory.m_Size = 0;
  this->m_CommandHistory.m_pElements = nullptr;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  if ( !this->m_bStatusVersion )
    vgui::Panel::SetMinimumSize(this, wide: 100, tall: 100);
  v8 = (vgui::RichText *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v8 != nullptr )
    v9 = vgui::RichText::RichText(this: v8, parent: this, panelName: "ConsoleHistory");
  else
    v9 = nullptr;
  this->m_pHistory = v9;
  vgui::Panel::SetAllowKeyBindingChainToParent(this: v9, state: false);
  vgui::Panel::MakeReadyForUse(this: this->m_pHistory);
  vgui::RichText::SetVerticalScrollbar(this: this->m_pHistory, state: !this->m_bStatusVersion);
  if ( this->m_bStatusVersion )
    this->m_pHistory->SetDrawOffsets(this: this->m_pHistory, a2: 3, a3: 3);
  vgui::RichText::GotoTextEnd(this: this->m_pHistory);
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "ConsoleSubmit",
            text: "#Console_Submit",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pSubmit = v11;
  v11->SetCommand(this: v11, a2: "submit");
  this->m_pSubmit->SetVisible(this: this->m_pSubmit, a2: !this->m_bStatusVersion);
  v12 = (CNonFocusableMenu *)MemAlloc_Alloc(nSize: 0x428u);
  if ( v12 != nullptr )
    v13 = CNonFocusableMenu::CNonFocusableMenu(this: v12, parent: this, panelName: "CompletionList");
  else
    v13 = nullptr;
  this->m_pCompletionList = v13;
  v13->SetVisible(this: v13, a2: false);
  v14 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x440u);
  if ( v14 != nullptr )
  {
    bStatusVersiona = this->m_pCompletionList->GetVPanel(this: this->m_pCompletionList);
    vgui::TextEntry::TextEntry(this: v14, parent: this, panelName: "ConsoleEntry");
    v14->__vftable = (vgui::TextEntry_vtbl *)&TabCatchingTextEntry::`vftable';
    v14[1].__vftable = (vgui::TextEntry_vtbl *)bStatusVersiona;
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v14, state: true);
    vgui::Panel::SetDragEnabled(this: v14, enabled: true);
    v15 = v14;
  }
  else
  {
    v15 = nullptr;
  }
  this->m_pEntry = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->m_pEntry->SendNewLine(this: this->m_pEntry, a2: true);
  v13->m_pFocus = this->m_pEntry;
  this->m_PrintColor = (Color)-2892072;
  this->m_DPrintColor = (Color)-11487804;
  this->m_pEntry->SetTabPosition(this: this->m_pEntry, a2: 1);
  this->m_bAutoCompleteMode = false;
  this->m_szPartialText[0] = 0;
  this->m_szPreviousPartialText[0] = 0;
  g_pCVar->InstallConsoleDisplayFunc(this: g_pCVar, a2: &this->IConsoleDisplayFunc);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C2650
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CConsolePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CConsolePanel::GetMessageMap(vgui::CConsolePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C2680
// Name: public: virtual struct PanelAnimationMap __near * vgui::CConsolePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CConsolePanel::GetAnimMap(vgui::CConsolePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePanel");
}

//------------------------------------------------------------------------------
// Address: 0x103C2690
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CConsolePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CConsolePanel::GetKBMap(vgui::CConsolePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap;
  `vgui::CConsolePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePanel");
  `vgui::CConsolePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C26C0
// Name: public: virtual vgui::CConsolePanel::~CConsolePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::~CConsolePanel(vgui::CConsolePanel *this)
{
  IConsoleDisplayFunc *v2; // ebx

  v2 = &this->IConsoleDisplayFunc;
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::CConsolePanel_vtbl *)&vgui::CConsolePanel::`vftable'{for `vgui::EditablePanel'};
  this->IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&vgui::CConsolePanel::`vftable'{for `IConsoleDisplayFunc'};
  vgui::CConsolePanel::ClearCompletionList(this);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this: &this->m_CommandHistory);
  if ( this->m_CommandHistory.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_CommandHistory.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_CommandHistory.m_Memory.m_pMemory);
      this->m_CommandHistory.m_Memory.m_pMemory = nullptr;
    }
    this->m_CommandHistory.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CommandHistory.m_pElements = this->m_CommandHistory.m_Memory.m_pMemory;
  g_pCVar->RemoveConsoleDisplayFunc(this: g_pCVar, a2: v2);
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(this: &this->m_CommandHistory);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_CompletionList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C2760
// Name: public: vgui::CConsoleDialog::CConsoleDialog(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::CConsoleDialog *__thiscall vgui::CConsoleDialog::CConsoleDialog(
        vgui::CConsoleDialog *this,
        vgui::Panel *pParent,
        const char *pName,
        bool bStatusVersion)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CConsolePanel *v8; // eax
  vgui::CConsolePanel *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: pName, showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (vgui::CConsoleDialog_vtbl *)&vgui::CConsoleDialog::`vftable';
  if ( `vgui::CConsoleDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CConsoleDialog");
    v5->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CConsoleDialog");
    v6->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CConsoleDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsoleDialog");
    v7->pfnClassName = vgui::CConsoleDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::CConsoleDialog::PanelMessageFunc_Activate::InitVar();
  vgui::CConsoleDialog::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetTitle(this, title: "#Console_Title", surfaceTitle: true);
  v8 = (vgui::CConsolePanel *)MemAlloc_Alloc(nSize: 0x3D0u);
  if ( v8 != nullptr )
    v9 = vgui::CConsolePanel::CConsolePanel(this: v8, pParent: this, pName: "ConsolePage", bStatusVersion);
  else
    v9 = nullptr;
  this->m_pConsolePanel = v9;
  v9->AddActionSignalTarget_2(this: v9, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C2950
// Name: protected: void vgui::CConsolePanel::RebuildCompletionList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::RebuildCompletionList(
        vgui::CConsolePanel *this,
        vgui::CConsolePanel::CompletionItem *text)
{
  CUtlMemory<vgui::TreeNode *,int> *v2; // ebx
  CUtlMemory<vgui::TreeNode *,int> *v3; // edi
  const char **v4; // ebx
  vgui::CConsolePanel::CompletionItem *v5; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::CConsolePanel::CompletionItem **v10; // esi
  vgui::CHistoryItem *v11; // eax
  vgui::CHistoryItem *v12; // esi
  const char *v13; // eax
  vgui::CConsolePanel *v14; // ecx
  int v15; // eax
  ConCommand *AutoCompleteCommmandFromPartial; // eax
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  int (__thiscall *AutoCompleteSuggest)(ConCommand *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // edx
  vgui::CConsolePanel *v19; // eax
  ICvar::ICVarIteratorInternal *v20; // eax
  vgui::TreeNode **v21; // esi
  int v22; // eax
  vgui::TreeNode **v23; // ecx
  int v24; // eax
  ICvar::ICVarIteratorInternal **v25; // esi
  ICvar::ICVarIteratorInternal_vtbl *v26; // esi
  char *v27; // edi
  unsigned int v28; // kr00_4
  void (__thiscall *v29)(ICvar::ICVarIteratorInternal *); // eax
  bool v30; // zf
  ICvar::ICVarIteratorInternal *v31; // esi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConCommandBase *v33; // edi
  char *v34; // eax
  vgui::CConsolePanel::CompletionItem *v35; // eax
  vgui::CConsolePanel *v36; // esi
  int m_Size; // ebx
  int v38; // eax
  vgui::CConsolePanel::CompletionItem **v39; // ecx
  int v40; // eax
  vgui::CConsolePanel::CompletionItem **v41; // ebx
  vgui::CConsolePanel::CompletionItem *v42; // esi
  char *v43; // ebx
  void *v44; // esi
  vgui::CHistoryItem *v45; // esi
  const char *m_pszName; // eax
  const char *v47; // eax
  vgui::CHistoryItem *v48; // eax
  int v49; // ebx
  float v50; // xmm0_4
  ConCommandBase *m_pNext; // eax
  vgui::CHistoryItem *v52; // esi
  const char *v53; // eax
  vgui::CHistoryItem *v54; // eax
  vgui::CHistoryItem *v55; // esi
  unsigned int v56; // kr04_4
  char *v57; // eax
  char v58; // [esp+10h] [ebp-238h]
  const char *v59; // [esp+10h] [ebp-238h]
  char strValue[512]; // [esp+20h] [ebp-228h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > commands; // [esp+220h] [ebp-28h] BYREF
  float v62; // [esp+234h] [ebp-14h]
  char *bCheckSubstrings; // [esp+238h] [ebp-10h]
  vgui::CConsolePanel *v64; // [esp+23Ch] [ebp-Ch]
  ICvar::Iterator iter; // [esp+240h] [ebp-8h]
  vgui::CConsolePanel::CompletionItem *item; // [esp+244h] [ebp-4h]
  vgui::CConsolePanel::CompletionItem *comp; // [esp+250h] [ebp+8h]
  vgui::CConsolePanel::CompletionItem *compa; // [esp+250h] [ebp+8h]

  v2 = (CUtlMemory<vgui::TreeNode *,int> *)this;
  v64 = this;
  vgui::CConsolePanel::ClearCompletionList(this);
  if ( (int)_V_strlen(str: (const char *)&text->m_bIsCommand) < 1 )
  {
    iter.m_pIter = nullptr;
    if ( v2[80].m_nGrowSize > 0 )
    {
      v3 = v2 + 78;
      item = nullptr;
      while ( 1 )
      {
        v4 = (const char **)(&item->m_bIsCommand + v2[79].m_nGrowSize);
        v5 = (vgui::CConsolePanel::CompletionItem *)MemAlloc_Alloc(nSize: 0xCu);
        if ( v5 != nullptr )
        {
          v5->m_bIsCommand = true;
          v5->m_pCommand = nullptr;
          v5->m_pText = nullptr;
          comp = v5;
        }
        else
        {
          comp = nullptr;
        }
        m_pMemory = v3[1].m_pMemory;
        m_nAllocationCount = v3->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(this: v3, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++v3[1].m_pMemory;
        v8 = v3->m_pMemory;
        v9 = (char *)v3[1].m_pMemory - (char *)m_pMemory - 1;
        v3[1].m_nAllocationCount = (int)v3->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
            count: 4 * v9);
        v10 = (vgui::CConsolePanel::CompletionItem **)&v3->m_pMemory[(_DWORD)m_pMemory];
        if ( v10 != nullptr )
          *v10 = comp;
        comp->m_bIsCommand = false;
        comp->m_pCommand = nullptr;
        v11 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
        v12 = v11;
        if ( v11 != nullptr )
        {
          v11->m_text = nullptr;
          v11->m_extraText = nullptr;
          v11->m_bHasExtra = false;
          v13 = *v4;
          if ( *v4 == nullptr )
            v13 = prType;
          vgui::CHistoryItem::SetText(this: v12, text: v13, extra: v4[1]);
        }
        else
        {
          v12 = nullptr;
        }
        v14 = v64;
        ++item;
        comp->m_pText = v12;
        if ( (int)++iter.m_pIter >= v14->m_CommandHistory.m_Size )
          break;
        v2 = (CUtlMemory<vgui::TreeNode *,int> *)v14;
      }
    }
    return;
  }
  LOBYTE(bCheckSubstrings) = 0;
  strstr(str1: (unsigned __int8 *)text, str2: " ");
  if ( v15 != 0 )
  {
    AutoCompleteCommmandFromPartial = FindAutoCompleteCommmandFromPartial(
                                        partial: (const char *)&text->m_bIsCommand,
                                        a2: (int)text);
    m_pIter = nullptr;
    if ( AutoCompleteCommmandFromPartial != nullptr )
    {
      AutoCompleteSuggest = AutoCompleteCommmandFromPartial->AutoCompleteSuggest;
      memset(&commands, 0, sizeof(commands));
      v19 = (vgui::CConsolePanel *)AutoCompleteSuggest(
                                     this: AutoCompleteCommmandFromPartial,
                                     a2: (const char *)&text->m_bIsCommand,
                                     a3: &commands);
      if ( (int)v19 > 0 )
      {
        compa = nullptr;
        v64 = v19;
        while ( 1 )
        {
          v20 = (ICvar::ICVarIteratorInternal *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v20 != nullptr )
          {
            v20[1].__vftable = nullptr;
            v20[2].__vftable = nullptr;
            LOBYTE(v20->__vftable) = 1;
            m_pIter = v20;
            iter.m_pIter = v20;
          }
          else
          {
            iter.m_pIter = nullptr;
          }
          v21 = v2[79].m_pMemory;
          v22 = v2[78].m_nAllocationCount;
          if ( (int)v21 + 1 > v22 )
            CUtlMemory<CChoreoActor *,int>::Grow(this: v2 + 78, num: (int)v21 - v22 + 1);
          ++v2[79].m_pMemory;
          v23 = v2[78].m_pMemory;
          v24 = (char *)v2[79].m_pMemory - (char *)v21 - 1;
          v2[79].m_nAllocationCount = (int)v23;
          if ( v24 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v23[(_DWORD)v21 + 1],
              src: (unsigned __int8 *)&v23[(_DWORD)v21],
              count: 4 * v24);
          v25 = (ICvar::ICVarIteratorInternal **)&v2[78].m_pMemory[(_DWORD)v21];
          if ( v25 != nullptr )
            *v25 = m_pIter;
          LOBYTE(m_pIter->__vftable) = 0;
          m_pIter[1].__vftable = nullptr;
          v26 = (ICvar::ICVarIteratorInternal_vtbl *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v26 != nullptr )
          {
            v27 = (char *)CUtlString::operator char const *(this: (CUtlString *)(&compa->m_bIsCommand
                                                                               + (unsigned int)commands.m_Memory.m_pMemory));
            bCheckSubstrings = v27;
            v26->SetFirst = nullptr;
            v26->Next = nullptr;
            LOBYTE(v26->IsValid) = 0;
            C_BaseEntity::operator delete(pMem: nullptr);
            v28 = strlen(v27);
            v29 = (void (__thiscall *)(ICvar::ICVarIteratorInternal *))MemAlloc_Alloc(nSize: v28 + 1);
            v26->SetFirst = v29;
            _V_memset(dest: (int)v29, fill: nullptr, count: v28 + 1);
            V_strncpy(pDest: (char *)v26->SetFirst, pSrc: bCheckSubstrings, maxLen: v28 + 1);
            m_pIter = iter.m_pIter;
            LOBYTE(v26->IsValid) = 0;
          }
          else
          {
            v26 = nullptr;
          }
          compa = (vgui::CConsolePanel::CompletionItem *)((char *)compa + 16);
          v30 = v64 == (vgui::CConsolePanel *)1;
          v64 = (vgui::CConsolePanel *)((char *)v64 - 1);
          m_pIter[2].__vftable = v26;
          if ( v30 )
            break;
          m_pIter = nullptr;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&commands);
      return;
    }
    LOBYTE(bCheckSubstrings) = 1;
  }
  v31 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  SetFirst = v31->SetFirst;
  iter.m_pIter = v31;
  SetFirst(this: v31);
  while ( v31->IsValid(this: v31) )
  {
    v33 = v31->Get(this: v31);
    if ( v33->IsFlagSet(this: v33, a2: 2) )
      goto LABEL_81;
    if ( v33->IsFlagSet(this: v33, a2: 16) )
      goto LABEL_81;
    v58 = (char)bCheckSubstrings;
    v34 = (char *)v33->GetName(this: v33);
    if ( !vgui::CConsolePanel::CommandMatchesText(
            this: v64,
            command: v34,
            text: (char *)&text->m_bIsCommand,
            bCheckSubstrings: v58) )
      goto LABEL_81;
    v35 = (vgui::CConsolePanel::CompletionItem *)MemAlloc_Alloc(nSize: 0xCu);
    if ( v35 != nullptr )
    {
      v35->m_bIsCommand = true;
      v35->m_pCommand = nullptr;
      v35->m_pText = nullptr;
      item = v35;
    }
    else
    {
      item = nullptr;
    }
    v36 = v64;
    m_Size = v64->m_CompletionList.m_Size;
    v38 = v64->m_CompletionList.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v38 )
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v64->m_CompletionList,
        num: m_Size - v38 + 1);
    ++v36->m_CompletionList.m_Size;
    v39 = v36->m_CompletionList.m_Memory.m_pMemory;
    v40 = v36->m_CompletionList.m_Size - m_Size - 1;
    v36->m_CompletionList.m_pElements = v39;
    if ( v40 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v39[m_Size + 1], src: (unsigned __int8 *)&v39[m_Size], count: 4 * v40);
    v41 = &v36->m_CompletionList.m_Memory.m_pMemory[m_Size];
    if ( v41 != nullptr )
      *v41 = item;
    v42 = item;
    item->m_pCommand = v33;
    v43 = (char *)v33->GetName(this: v33);
    if ( v33->IsCommand(this: v33) )
    {
      v42->m_bIsCommand = true;
      v54 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
      v55 = v54;
      if ( v54 != nullptr )
      {
        v54->m_text = nullptr;
        v54->m_extraText = nullptr;
        v54->m_bHasExtra = false;
        C_BaseEntity::operator delete(pMem: nullptr);
        v56 = strlen(v43);
        v57 = (char *)MemAlloc_Alloc(nSize: v56 + 1);
        v55->m_text = v57;
        _V_memset(dest: (int)v57, fill: nullptr, count: v56 + 1);
        V_strncpy(pDest: v55->m_text, pSrc: v43, maxLen: v56 + 1);
        v55->m_bHasExtra = false;
      }
      else
      {
        v55 = nullptr;
      }
      item->m_pText = v55;
    }
    else
    {
      v42->m_bIsCommand = false;
      v44 = __RTDynamicCast(
              inptr: v33,
              VfDelta: 0,
              SrcType: &ConVar `RTTI Type Descriptor',
              TargetType: &ConVar_ServerBounded `RTTI Type Descriptor',
              isReference: 0);
      if ( v44 != nullptr )
      {
        v49 = (*(int (__thiscall **)(void *))(*(_DWORD *)v44 + 80))(a1: v44);
        v62 = ((double (__thiscall *)(void *))*(_DWORD *)(*(_DWORD *)v44 + 76))(a1: v44);
        v50 = v62;
      }
      else
      {
        if ( !v33->IsFlagSet(this: v33, a2: 4096) )
        {
          v45 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
          if ( v45 != nullptr )
          {
            if ( (v33->m_nFlags & 0x1000) != 0 )
            {
              m_pszName = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszName = v33[1].m_pNext[1].m_pszName;
              if ( m_pszName == nullptr )
                m_pszName = prType;
            }
            v59 = m_pszName;
            v47 = v33->GetName(this: v33);
            v48 = vgui::CHistoryItem::CHistoryItem(this: v45, text: v47, extra: v59);
            item->m_pText = v48;
          }
          else
          {
            item->m_pText = nullptr;
          }
          goto LABEL_80;
        }
        m_pNext = v33[1].m_pNext;
        if ( m_pNext != nullptr )
          v49 = (int)m_pNext[2].__vftable;
        else
          v49 = 0;
        v50 = *(float *)&m_pNext[1].m_nFlags;
      }
      if ( v50 == (float)v49 )
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%d", v49);
      else
        V_snprintf(pDest: strValue, maxLen: 0x200u, pFormat: "%f", v50);
      v52 = (vgui::CHistoryItem *)MemAlloc_Alloc(nSize: 0xCu);
      if ( v52 != nullptr )
      {
        v53 = v33->GetName(this: v33);
        v52->m_text = nullptr;
        v52->m_extraText = nullptr;
        v52->m_bHasExtra = false;
        vgui::CHistoryItem::SetText(this: v52, text: v53, extra: strValue);
        item->m_pText = v52;
      }
      else
      {
        item->m_pText = nullptr;
      }
    }
LABEL_80:
    v31 = iter.m_pIter;
LABEL_81:
    v31->Next(this: v31);
  }
  if ( v64->m_CompletionList.m_Size >= 2 )
    CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
      this: &v64->m_CompletionList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))vgui::CConsolePanel::CompletionItemCompare);
  C_BaseEntity::operator delete(pMem: v31);
}

//------------------------------------------------------------------------------
// Address: 0x103C2F70
// Name: protected: virtual void vgui::CConsolePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::CConsolePanel::OnTextChanged(
        vgui::CConsolePanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        vgui::TextEntry *panel)
{
  signed int v5; // ebx
  char v6; // al
  bool v7; // al
  bool v8; // al
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int i; // edi
  KeyValues *v16; // eax
  KeyValues *v17; // ebx
  char *ItemText; // [esp+20h] [ebp-110h]
  int v19; // [esp+24h] [ebp-10Ch]
  char text[259]; // [esp+2Ch] [ebp-104h] BYREF
  bool altKeyDown; // [esp+12Fh] [ebp-1h]
  char hitTilde_3; // [esp+13Bh] [ebp+Bh]

  if ( panel == this->m_pEntry )
  {
    V_strncpy(pDest: this->m_szPreviousPartialText, pSrc: this->m_szPartialText, maxLen: 256);
    ((void (__thiscall *)(vgui::TextEntry *, char *, int, int, int))this->m_pEntry->GetText_2)(
      a1: this->m_pEntry,
      a2: this->m_szPartialText,
      a3: 256,
      a4: a3,
      a5: a2);
    v5 = _V_strlen(str: this->m_szPartialText);
    v6 = *((_BYTE *)&this->m_iNextCompletion + v5 + 3);
    if ( v6 == 126 || (hitTilde_3 = 0, v6 == 96) )
      hitTilde_3 = 1;
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || (v7 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), altKeyDown = false, v7) )
    {
      altKeyDown = true;
    }
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || (v8 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL)) )
    {
      v8 = true;
    }
    if ( v5 > 0 && hitTilde_3 != 0 )
    {
      v9 = !altKeyDown;
      *((_BYTE *)&this->m_iNextCompletion + v5 + 3) = 0;
      if ( !v9 || v8 )
      {
        this->m_pEntry->SetText(this: this->m_pEntry, a2: this->m_szPartialText);
      }
      else
      {
        ((void (__thiscall *)(vgui::TextEntry *, const char *, int))this->m_pEntry->SetText)(
          a1: this->m_pEntry,
          a2: prType,
          a3: v19);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "Close");
        else
          v11 = nullptr;
        ((void (__thiscall *)(vgui::CConsolePanel *, vgui::CConsolePanel *, KeyValues *))this->PostMessage)(
          a1: this,
          a2: this,
          a3: v11);
        v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v12 != nullptr )
        {
          v13 = KeyValues::KeyValues(this: v12, setName: "ClosedByHittingTilde");
          this->PostActionSignal(this, a2: v13);
        }
        else
        {
          this->PostActionSignal(this, a2: nullptr);
        }
      }
    }
    else
    {
      this->m_bAutoCompleteMode = false;
      vgui::CConsolePanel::RebuildCompletionList(
        this,
        text: (vgui::CConsolePanel::CompletionItem *)this->m_szPartialText);
      SetVisible = this->m_pCompletionList->SetVisible;
      if ( this->m_CompletionList.m_Size >= 1 )
      {
        ((void (__stdcall *)(int, int))SetVisible)(a1: 1, a2: v19);
        vgui::Menu::DeleteAllItems(this: this->m_pCompletionList);
        for ( i = 0; i < this->m_CompletionList.m_Size; ++i )
        {
          if ( i >= 10 )
            break;
          text[0] = 0;
          if ( i == 9 )
          {
            V_strncpy(pDest: text, pSrc: "...", maxLen: 256);
          }
          else
          {
            ItemText = (char *)vgui::CConsolePanel::CompletionItem::GetItemText(this: this->m_CompletionList.m_Memory.m_pMemory[i]);
            V_strncpy(pDest: text, pSrc: ItemText, maxLen: 256);
          }
          v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          v17 = v16 != nullptr ? KeyValues::KeyValues(this: v16, setName: "CompletionCommand") : nullptr;
          KeyValues::SetString(this: v17, keyName: "command", value: text);
          this->m_pCompletionList->AddMenuItem(this: this->m_pCompletionList, a2: text, a3: v17, a4: this, a5: nullptr);
        }
        vgui::CConsolePanel::UpdateCompletionListPosition(this);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, int))SetVisible)(a1: 0, a2: v19);
      }
      this->RequestFocus(this, a2: 0);
      this->m_pEntry->RequestFocus(this: this->m_pEntry, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C3230
// Name: protected: void vgui::CConsolePanel::AddToHistory(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::AddToHistory(vgui::CConsolePanel *this, char *commandText, char *extraText)
{
  vgui::CHistoryItem *m_pMemory; // esi
  vgui::CConsolePanel *v4; // esi
  void *v5; // esp
  unsigned __int8 *v6; // ebx
  signed int i; // eax
  int v8; // edi
  int v9; // eax
  char *v10; // esi
  const char *v11; // eax
  bool v12; // zf
  const char *v13; // esi
  vgui::CConsolePanel *v14; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  vgui::CHistoryItem *v17; // ecx
  int v18; // eax
  int v19; // ecx
  vgui::CConsolePanel::CompletionItem *m_szPartialText; // [esp-4h] [ebp-14h]
  unsigned __int8 v21[12]; // [esp+0h] [ebp-10h] BYREF
  vgui::CConsolePanel *v22; // [esp+Ch] [ebp-4h]
  const char *extraTexta; // [esp+1Ch] [ebp+Ch]

  v22 = this;
  if ( this->m_CommandHistory.m_Size >= 100 )
  {
    while ( 1 )
    {
      m_pMemory = this->m_CommandHistory.m_Memory.m_pMemory;
      C_BaseEntity::operator delete(pMem: m_pMemory->m_text);
      C_BaseEntity::operator delete(pMem: m_pMemory->m_extraText);
      m_pMemory->m_text = nullptr;
      v4 = v22;
      if ( v22->m_CommandHistory.m_Size - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)v22->m_CommandHistory.m_Memory.m_pMemory,
          src: (unsigned __int8 *)&v22->m_CommandHistory.m_Memory.m_pMemory[1],
          count: 12 * (v22->m_CommandHistory.m_Size - 1));
      --v22->m_CommandHistory.m_Size;
      if ( v4->m_CommandHistory.m_Size < 100 )
        break;
      this = v4;
    }
  }
  v5 = alloca(strlen(commandText) + 1);
  if ( v21 != nullptr )
  {
    memset(dst: (int)v21, value: nullptr, count: strlen(commandText) + 1);
    strncpy(dest: v21, source: (unsigned __int8 *)commandText, count: strlen(commandText));
    if ( v21[strlen((const char *)v21) - 1] == 32 )
      v21[strlen((const char *)v21) - 1] = 0;
  }
  v6 = nullptr;
  if ( extraText != nullptr )
  {
    v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(extraText) + 1);
    if ( v6 != nullptr )
    {
      memset(dst: (int)v6, value: nullptr, count: strlen(extraText) + 1);
      strncpy(dest: v6, source: (unsigned __int8 *)extraText, count: strlen(extraText));
      for ( i = strlen((const char *)v6) - 1; i >= 0; v6[i--] = 0 )
      {
        if ( v6[i] != 32 )
          break;
      }
    }
  }
  v8 = v22->m_CommandHistory.m_Size - 1;
  if ( v8 >= 0 )
  {
    v9 = 12 * v8;
    extraTexta = (const char *)(12 * v8);
    while ( 1 )
    {
      v10 = (char *)v22->m_CommandHistory.m_Memory.m_pMemory + v9;
      if ( v10 != nullptr )
      {
        v11 = *(const char **)v10;
        if ( *(_DWORD *)v10 == 0 )
          v11 = prType;
        if ( _V_stricmp(s1: v11, s2: (const char *)v21) == 0 )
        {
          if ( v6 == nullptr )
            break;
          v13 = *((const char **)v10 + 1);
          if ( v13 != nullptr )
          {
            v12 = _V_stricmp(s1: v13, s2: (const char *)v6) == 0;
LABEL_25:
            if ( v12 )
              CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
                this: &v22->m_CommandHistory,
                elem: v8);
          }
        }
      }
      v9 = (int)(extraTexta - 12);
      --v8;
      extraTexta -= 12;
      if ( v8 < 0 )
        goto LABEL_28;
    }
    v12 = *((_DWORD *)v10 + 1) == 0;
    goto LABEL_25;
  }
LABEL_28:
  v14 = v22;
  m_Size = v22->m_CommandHistory.m_Size;
  m_nAllocationCount = v22->m_CommandHistory.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v22->m_CommandHistory,
      num: m_Size - m_nAllocationCount + 1);
  ++v14->m_CommandHistory.m_Size;
  v17 = v14->m_CommandHistory.m_Memory.m_pMemory;
  v18 = v14->m_CommandHistory.m_Size - m_Size - 1;
  v14->m_CommandHistory.m_pElements = v17;
  if ( v18 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v17[m_Size + 1], src: (unsigned __int8 *)&v17[m_Size], count: 12 * v18);
  v19 = (int)&v14->m_CommandHistory.m_Memory.m_pMemory[m_Size];
  if ( v19 != 0 )
  {
    *(_DWORD *)v19 = 0;
    *(_DWORD *)(v19 + 4) = 0;
    *(_BYTE *)(v19 + 8) = 0;
  }
  vgui::CHistoryItem::SetText(
    this: &v14->m_CommandHistory.m_Memory.m_pMemory[m_Size],
    text: (const char *)v21,
    extra: (const char *)v6);
  m_szPartialText = (vgui::CConsolePanel::CompletionItem *)v14->m_szPartialText;
  v14->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: v14, text: m_szPartialText);
  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x103C3510
// Name: public: virtual void vgui::CConsoleDialog::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsoleDialog::Close(vgui::CConsoleDialog *this)
{
  vgui::CConsolePanel *m_pConsolePanel; // esi

  this->OnClose(this);
  m_pConsolePanel = this->m_pConsolePanel;
  m_pConsolePanel->OnClose(this: m_pConsolePanel);
  m_pConsolePanel->m_iNextCompletion = 0;
  vgui::CConsolePanel::RebuildCompletionList(this: m_pConsolePanel, text: (vgui::CConsolePanel::CompletionItem *)prType);
}

//------------------------------------------------------------------------------
// Address: 0x103C3550
// Name: protected: virtual void vgui::CConsolePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CConsolePanel::OnCommand(vgui::CConsolePanel *this, const char *command)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char *v5; // eax
  char *v6; // edi
  char szCommand[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Submit") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    this->m_pEntry->GetText_2(this: this->m_pEntry, a2: szCommand, a3: 256);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: szCommand);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "] ");
    this->Print(this: &this->IConsoleDisplayFunc, a2: szCommand);
    this->Print(this: &this->IConsoleDisplayFunc, a2: "\n");
    this->m_pEntry->SetText(this: this->m_pEntry, a2: prType);
    this->OnTextChanged(this, a2: this->m_pEntry);
    vgui::RichText::GotoTextEnd(this: this->m_pHistory);
    strchr(string: szCommand, chr: 0x20u);
    v6 = v5;
    if ( v5 != nullptr )
    {
      *v5 = 0;
      v6 = v5 + 1;
    }
    if ( (int)_V_strlen(str: szCommand) > 0 )
      vgui::CConsolePanel::AddToHistory(this, commandText: szCommand, extraText: v6);
    this->m_pCompletionList->SetVisible(this: this->m_pCompletionList, a2: false);
  }
}

} // namespace client
