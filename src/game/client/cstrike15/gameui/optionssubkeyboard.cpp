// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubkeyboard.cpp
// Functions: 37
// ============================================================

#include "game\client\cstrike15\gameui\optionssubkeyboard.h"

//------------------------------------------------------------------------------
// Address: 0x101D9920
// Name: int GetJoystickForCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetJoystickForCode(ButtonCode_t code)
{
  if ( (unsigned int)(code - 114) > 0xBF )
    return 0;
  if ( code <= JOYSTICK_LAST_BUTTON )
    return (code - 114) / 32;
  if ( (unsigned int)(code - 242) > 0xF )
    return (code - 258) / 12;
  return (code - 242) / 4;
}

//------------------------------------------------------------------------------
// Address: 0x101D9990
// Name: public: static char const __near * COptionsSubKeyboard::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubKeyboard::GetPanelClassName()
{
  return "COptionsSubKeyboard";
}

//------------------------------------------------------------------------------
// Address: 0x101D99A0
// Name: private: virtual void COptionsSubKeyboard::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::OnKeyCodeTyped(COptionsSubKeyboard *this, ButtonCode_t code)
{
  if ( code == KEY_ENTER )
    this->OnCommand(this, a2: "ChangeKey");
  else
    vgui::PropertyPage::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x101D99D0
// Name: char const __near * UTIL_Parse(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl UTIL_Parse(const char *data, char *token, int sizeofToken)
{
  return engine->ParseFile(this: engine, a2: data, a3: token, a4: sizeofToken);
}

//------------------------------------------------------------------------------
// Address: 0x101D99F0
// Name: char __near * UTIL_va(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *UTIL_va(char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  curstring_0 = (curstring_0 + 1) % 4;
  V_vsnprintf(pDest: string_2[curstring_0], maxLen: 1024, pFormat: format, params);
  return string_2[curstring_0];
}

//------------------------------------------------------------------------------
// Address: 0x101D9A40
// Name: private: class KeyValues __near * COptionsSubKeyboard::GetItemForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall COptionsSubKeyboard::GetItemForBinding(COptionsSubKeyboard *this, const char *binding)
{
  int v3; // eax
  int v4; // ebx
  VControlsListPanel *m_pKeyBindList; // ecx
  VControlsListPanel_vtbl *v6; // esi
  int v7; // eax
  KeyValues *v8; // esi
  KeyValues *Key; // eax
  char *String; // eax

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    v3 = _KeyValuesSystem(a1: this);
    bindingSymbol = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 12))(a1: v3, a2: "Binding", a3: 1);
  }
  v4 = 0;
  if ( this->m_pKeyBindList->GetItemCount(this: this->m_pKeyBindList) <= 0 )
    return nullptr;
  while ( 1 )
  {
    m_pKeyBindList = this->m_pKeyBindList;
    v6 = m_pKeyBindList->__vftable;
    v7 = ((int (__stdcall *)(int))m_pKeyBindList->GetItemIDFromRow)(a1: v4);
    v8 = v6->GetItemData(this: this->m_pKeyBindList, a2: v7);
    if ( v8 != nullptr )
    {
      Key = KeyValues::FindKey(this: v8, keySymbol: bindingSymbol);
      String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: prType);
      if ( _V_stricmp(s1: String, s2: binding) == 0 )
        break;
    }
    if ( ++v4 >= this->m_pKeyBindList->GetItemCount(this: this->m_pKeyBindList) )
      return nullptr;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101D9B10
// Name: private: void COptionsSubKeyboard::ClearBindItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::ClearBindItems(COptionsSubKeyboard *this)
{
  int i; // ebx
  VControlsListPanel_vtbl *v3; // edi
  int v4; // eax
  KeyValues *v5; // eax

  for ( i = 0; i < this->m_pKeyBindList->GetItemCount(this: this->m_pKeyBindList); ++i )
  {
    v3 = this->m_pKeyBindList->__vftable;
    v4 = v3->GetItemIDFromRow(this: this->m_pKeyBindList, a2: i);
    v5 = v3->GetItemData(this: this->m_pKeyBindList, a2: v4);
    if ( v5 != nullptr )
    {
      KeyValues::SetString(this: v5, keyName: "Key", value: (char *)prType);
      this->m_pKeyBindList->InvalidateItem(this: this->m_pKeyBindList, a2: i);
    }
  }
  this->m_pKeyBindList->InvalidateLayout(this: this->m_pKeyBindList, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101D9BB0
// Name: private: void COptionsSubKeyboard::RemoveKeyFromBindItems(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COptionsSubKeyboard::RemoveKeyFromBindItems(
        COptionsSubKeyboard *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        KeyValues *org_item,
        char *key)
{
  unsigned int v6; // ebx
  unsigned __int8 *v7; // esi
  int v8; // ebx
  VControlsListPanel *m_pKeyBindList; // ecx
  VControlsListPanel_vtbl *v10; // esi
  int v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  char *String; // eax
  char *v15; // eax
  char *pszKey; // [esp+4h] [ebp-4h]
  char *org_binding; // [esp+14h] [ebp+Ch]

  if ( key != nullptr && *key != 0 )
  {
    v6 = _V_strlen(str: key) + 1;
    v7 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v6);
    pszKey = (char *)v7;
    if ( v7 != nullptr )
    {
      _V_memcpy(dest: v7, src: (unsigned __int8 *)key, count: v6);
      v8 = 0;
      if ( ((int (__thiscall *)(VControlsListPanel *, int, int))this->m_pKeyBindList->GetItemCount)(
             a1: this->m_pKeyBindList,
             a2: a3,
             a3: a2) > 0 )
      {
        do
        {
          m_pKeyBindList = this->m_pKeyBindList;
          v10 = m_pKeyBindList->__vftable;
          v11 = ((int (__stdcall *)(int))m_pKeyBindList->GetItemIDFromRow)(a1: v8);
          v12 = v10->GetItemData(this: this->m_pKeyBindList, a2: v11);
          v13 = v12;
          if ( v12 != nullptr )
          {
            String = KeyValues::GetString(this: v12, keyName: "Key", defaultValue: prType);
            if ( _V_stricmp(s1: pszKey, s2: String) == 0 )
            {
              if ( org_item == nullptr
                || (org_binding = KeyValues::GetString(this: org_item, keyName: "Binding", defaultValue: prType),
                    v15 = KeyValues::GetString(this: v13, keyName: "Binding", defaultValue: prType),
                    _V_stricmp(s1: org_binding, s2: v15) != 0) )
              {
                KeyValues::SetString(this: v13, keyName: "Key", value: (char *)prType);
                this->m_pKeyBindList->InvalidateItem(this: this->m_pKeyBindList, a2: v8);
              }
            }
          }
          ++v8;
        }
        while ( v8 < this->m_pKeyBindList->GetItemCount(this: this->m_pKeyBindList) );
        v7 = (unsigned __int8 *)pszKey;
      }
      C_BaseEntity::operator delete(pMem: v7);
      this->m_pKeyBindList->InvalidateLayout(this: this->m_pKeyBindList, a2: false, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9D10
// Name: private: void COptionsSubKeyboard::SaveCurrentBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::SaveCurrentBindings(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard::KeyBinding *m_Bindings; // ebx
  COptionsSubKeyboard::KeyBinding *v2; // esi
  int j; // edi
  ButtonCode_t v4; // esi
  const char *v5; // eax
  char *v6; // ebx
  unsigned int v7; // kr00_4
  char *v8; // edi
  int i; // [esp+Ch] [ebp-8h]
  COptionsSubKeyboard::KeyBinding *v10; // [esp+10h] [ebp-4h]

  m_Bindings = this->m_Bindings;
  v2 = this->m_Bindings;
  for ( j = 306; j != 0; --j )
  {
    if ( v2->binding != nullptr )
    {
      C_BaseEntity::operator delete(pMem: v2->binding);
      v2->binding = nullptr;
    }
    ++v2;
  }
  v4 = BUTTON_CODE_NONE;
  i = 0;
  v10 = m_Bindings;
  do
  {
    v5 = gameuifuncs->GetBindingForButtonCode(this: gameuifuncs, a2: v4);
    v6 = (char *)v5;
    if ( v5 != nullptr && *v5 != 0 )
    {
      v7 = strlen(v5);
      v8 = (char *)MemAlloc_Alloc(nSize: v7 + 1);
      V_strncpy(pDest: v8, pSrc: v6, maxLen: v7 + 1);
      v4 = i;
      v10->binding = v8;
    }
    ++v10;
    i = ++v4;
  }
  while ( v4 < BUTTON_CODE_LAST );
}

//------------------------------------------------------------------------------
// Address: 0x101D9DB0
// Name: public: virtual void COptionsSubKeyboard::ItemSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::ItemSelected(COptionsSubKeyboard *this, int itemID)
{
  bool v3; // al
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  char *String; // eax

  this->m_pKeyBindList->SetItemOfInterest(this: this->m_pKeyBindList, a2: itemID);
  v3 = this->m_pKeyBindList->IsItemIDValid(this: this->m_pKeyBindList, a2: itemID);
  SetEnabled = this->m_pSetBindingButton->SetEnabled;
  if ( v3 )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    v5 = this->m_pKeyBindList->GetItemData(this: this->m_pKeyBindList, a2: itemID);
    v6 = v5;
    if ( v5 != nullptr )
    {
      String = KeyValues::GetString(this: v5, keyName: "Key", defaultValue: nullptr);
      if ( String != nullptr && *String != 0 )
        this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: true);
      else
        this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: false);
      if ( KeyValues::GetInt(this: v6, keyName: "Header", defaultValue: 0) != 0 )
        this->m_pSetBindingButton->SetEnabled(this: this->m_pSetBindingButton, a2: false);
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9E80
// Name: public: virtual void COptionsSubKeyboard::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::OnKeyCodePressed(COptionsSubKeyboard *this, int code)
{
  bool v3; // al
  ButtonCode_t v4; // ebx
  int v5; // edi
  KeyValues *v6; // eax
  char *String; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int x; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int w; // [esp+14h] [ebp-4h] BYREF

  v3 = this->m_pKeyBindList->IsCapturing(this: this->m_pKeyBindList);
  v4 = code;
  if ( !v3
    && (v5 = this->m_pKeyBindList->GetItemOfInterest(this: this->m_pKeyBindList),
        this->m_pKeyBindList->GetCellBounds(
          this: this->m_pKeyBindList,
          a2: v5,
          a3: 1,
          a4: &x,
          a5: &y,
          a6: &w,
          a7: &code))
    && v4 == KEY_DELETE )
  {
    v6 = this->m_pKeyBindList->GetItemData(this: this->m_pKeyBindList, a2: v5);
    String = KeyValues::GetString(this: v6, keyName: "Key", defaultValue: nullptr);
    if ( String != nullptr && *String != 0 )
      COptionsSubKeyboard::RemoveKeyFromBindItems(this, a2: 73, a3: (int)this, org_item: nullptr, key: String);
    this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: false);
    this->m_pKeyBindList->InvalidateItem(this: this->m_pKeyBindList, a2: v5);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = KeyValues::KeyValues(this: v8, setName: "ApplyButtonEnable");
      this->PostActionSignal(this, a2: v9);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
  else
  {
    vgui::Panel::OnKeyCodePressed(this, code: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D9FA0
// Name: public: static char const __near * COptionsSubKeyboardAdvancedDlg::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubKeyboardAdvancedDlg::GetPanelClassName()
{
  return "COptionsSubKeyboardAdvancedDlg";
}

//------------------------------------------------------------------------------
// Address: 0x101D9FB0
// Name: enum ButtonCode_t ButtonCodeToJoystickButtonCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCodeToJoystickButtonCode(ButtonCode_t code, int nDesiredJoystick)
{
  ButtonCode_t result; // eax
  int v3; // esi

  result = code;
  if ( (unsigned int)(code - 114) <= 0xBF )
  {
    v3 = nDesiredJoystick;
    if ( nDesiredJoystick != 0 )
    {
      if ( nDesiredJoystick >= 0 )
      {
        if ( nDesiredJoystick > 3 )
          v3 = 3;
      }
      else
      {
        v3 = 0;
      }
      result = GetBaseButtonCode(code);
      if ( (unsigned int)(result - 114) > 0x7F )
      {
        if ( (unsigned int)(result - 242) > 0xF )
        {
          if ( (unsigned int)(result - 258) <= 0x2F )
            result += 12 * v3;
        }
        else
        {
          result += 4 * v3;
        }
      }
      else
      {
        result += 32 * v3;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA020
// Name: private: void COptionsSubKeyboard::AddBinding(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::AddBinding(COptionsSubKeyboard *this, KeyValues *item, char *keyname)
{
  char *String; // eax
  int i; // ebx
  VControlsListPanel_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  char *v10; // eax
  char *binding; // [esp+14h] [ebp+8h]

  String = KeyValues::GetString(this: item, keyName: "Key", defaultValue: prType);
  if ( _V_stricmp(s1: String, s2: keyname) != 0 )
  {
    COptionsSubKeyboard::RemoveKeyFromBindItems(this, a2: (int)keyname, a3: (int)this, org_item: item, key: keyname);
    binding = KeyValues::GetString(this: item, keyName: "Binding", defaultValue: prType);
    for ( i = 0; i < this->m_pKeyBindList->GetItemCount(this: this->m_pKeyBindList); ++i )
    {
      v6 = this->m_pKeyBindList->__vftable;
      v7 = v6->GetItemIDFromRow(this: this->m_pKeyBindList, a2: i);
      v8 = v6->GetItemData(this: this->m_pKeyBindList, a2: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v10 = KeyValues::GetString(this: v8, keyName: "Binding", defaultValue: prType);
        if ( _V_stricmp(s1: v10, s2: binding) == 0 )
        {
          KeyValues::SetString(this: v9, keyName: "Key", value: keyname);
          this->m_pKeyBindList->InvalidateItem(this: this->m_pKeyBindList, a2: i);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA120
// Name: private: void COptionsSubKeyboard::Finish(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::Finish(COptionsSubKeyboard *this, ButtonCode_t code)
{
  int v3; // ebx
  KeyValues *v4; // edi
  char *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v3 = this->m_pKeyBindList->GetItemOfInterest(this: this->m_pKeyBindList);
  this->m_pKeyBindList->EndCaptureMode(this: this->m_pKeyBindList, a2: 2u);
  v4 = this->m_pKeyBindList->GetItemData(this: this->m_pKeyBindList, a2: v3);
  if ( v4 != nullptr )
  {
    if ( code != BUTTON_CODE_NONE && code != KEY_ESCAPE && code != BUTTON_CODE_INVALID )
    {
      v5 = (char *)g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: code);
      COptionsSubKeyboard::AddBinding(this, item: v4, keyname: v5);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "ApplyButtonEnable");
      else
        v7 = nullptr;
      this->PostActionSignal(this, a2: v7);
    }
    this->m_pKeyBindList->InvalidateItem(this: this->m_pKeyBindList, a2: v3);
  }
  this->m_pSetBindingButton->SetEnabled(this: this->m_pSetBindingButton, a2: true);
  this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101DA200
// Name: public: virtual void COptionsSubKeyboard::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubKeyboard::OnThink(COptionsSubKeyboard *this@<ecx>, int a2@<ebx>)
{
  ButtonCode_t code; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->m_pKeyBindList->IsCapturing(this: this->m_pKeyBindList) )
  {
    code = BUTTON_CODE_INVALID;
    if ( engine->CheckDoneKeyTrapping(this: engine, a2: &code) )
      COptionsSubKeyboard::Finish(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA250
// Name: public: COptionsSubKeyboardAdvancedDlg::COptionsSubKeyboardAdvancedDlg(unsigned int)
// Source: json
//------------------------------------------------------------------------------
COptionsSubKeyboardAdvancedDlg *__thiscall COptionsSubKeyboardAdvancedDlg::COptionsSubKeyboardAdvancedDlg(
        COptionsSubKeyboardAdvancedDlg *this,
        unsigned int hParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  vgui::Frame::Frame(this, parent: nullptr, panelName: nullptr, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COptionsSubKeyboardAdvancedDlg_vtbl *)&COptionsSubKeyboardAdvancedDlg::`vftable';
  if ( `COptionsSubKeyboardAdvancedDlg::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboardAdvancedDlg::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubKeyboardAdvancedDlg");
    v3->pfnClassName = COptionsSubKeyboardAdvancedDlg::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COptionsSubKeyboardAdvancedDlg::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboardAdvancedDlg::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubKeyboardAdvancedDlg");
    v4->pfnClassName = COptionsSubKeyboardAdvancedDlg::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COptionsSubKeyboardAdvancedDlg::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboardAdvancedDlg::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubKeyboardAdvancedDlg");
    v5->pfnClassName = COptionsSubKeyboardAdvancedDlg::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetTitle(this, title: "#GameUI_KeyboardAdvanced_Title", surfaceTitle: true);
  vgui::Panel::SetSize(this, wide: 280, tall: 140);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/OptionsSubKeyboardAdvancedDlg.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DA360
// Name: public: virtual void COptionsSubKeyboardAdvancedDlg::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboardAdvancedDlg::Activate(COptionsSubKeyboardAdvancedDlg *this)
{
  vgui::IInput *v2; // edi
  vgui::IInput_vtbl *v3; // ebx
  int v4; // eax
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v6; // eax
  CGameUIConVarRef hud_fastswitch; // [esp+Ch] [ebp-20h] BYREF
  CGameUIConVarRef con_enable; // [esp+1Ch] [ebp-10h] BYREF

  vgui::Frame::Activate(this);
  v2 = g_pVGuiInput;
  v3 = g_pVGuiInput->__vftable;
  v4 = this->GetVPanel(this);
  v3->SetAppModalSurface(this: v2, a2: v4);
  CGameUIConVarRef::CGameUIConVarRef(this: &con_enable, pName: "con_enable");
  if ( CGameUIConVarRef::IsValid(this: &con_enable) )
  {
    GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
    this->SetControlInt(
      this,
      a2: "ConsoleCheck",
      a3: con_enable.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVarState->m_Value.m_nValue != 0);
  }
  CGameUIConVarRef::CGameUIConVarRef(this: &hud_fastswitch, pName: "hud_fastswitch", bIgnoreMissing: true);
  if ( CGameUIConVarRef::IsValid(this: &hud_fastswitch) )
  {
    v6 = GetGameUIActiveSplitScreenPlayerSlot();
    this->SetControlInt(
      this,
      a2: "FastSwitchCheck",
      a3: hud_fastswitch.m_Info[v6].m_pConVarState->m_Value.m_nValue != 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA410
// Name: public: virtual void COptionsSubKeyboardAdvancedDlg::OnApplyData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboardAdvancedDlg::OnApplyData(COptionsSubKeyboardAdvancedDlg *this)
{
  int v2; // edi
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v4; // esi
  int v5; // eax
  CGameUIConVarRef hud_fastswitch; // [esp+8h] [ebp-20h] BYREF
  CGameUIConVarRef con_enable; // [esp+18h] [ebp-10h] BYREF

  CGameUIConVarRef::CGameUIConVarRef(this: &con_enable, pName: "con_enable");
  v2 = this->GetControlInt(this, a2: "ConsoleCheck", a3: 0);
  GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
  con_enable.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_2(
    this: con_enable.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar,
    a2: v2);
  CGameUIConVarRef::CGameUIConVarRef(this: &hud_fastswitch, pName: "hud_fastswitch", bIgnoreMissing: true);
  v4 = this->GetControlInt(this, a2: "FastSwitchCheck", a3: 0);
  v5 = GetGameUIActiveSplitScreenPlayerSlot();
  hud_fastswitch.m_Info[v5].m_pConVar->SetValue_2(this: hud_fastswitch.m_Info[v5].m_pConVar, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101DA490
// Name: public: virtual void COptionsSubKeyboardAdvancedDlg::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboardAdvancedDlg::OnCommand(COptionsSubKeyboardAdvancedDlg *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    this->OnApplyData(this);
    this->Close(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DA4E0
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubKeyboardAdvancedDlg::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubKeyboardAdvancedDlg::GetMessageMap(COptionsSubKeyboardAdvancedDlg *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubKeyboardAdvancedDlg::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubKeyboardAdvancedDlg::GetMessageMap'::`2'::s_pMap;
  `COptionsSubKeyboardAdvancedDlg::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubKeyboardAdvancedDlg");
  `COptionsSubKeyboardAdvancedDlg::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA510
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubKeyboardAdvancedDlg::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubKeyboardAdvancedDlg::GetAnimMap(COptionsSubKeyboardAdvancedDlg *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubKeyboardAdvancedDlg");
}

//------------------------------------------------------------------------------
// Address: 0x101DA520
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubKeyboardAdvancedDlg::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubKeyboardAdvancedDlg::GetKBMap(COptionsSubKeyboardAdvancedDlg *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubKeyboardAdvancedDlg::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubKeyboardAdvancedDlg::GetKBMap'::`2'::s_pMap;
  `COptionsSubKeyboardAdvancedDlg::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubKeyboardAdvancedDlg");
  `COptionsSubKeyboardAdvancedDlg::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DA550
// Name: private: void COptionsSubKeyboard::OpenKeyboardAdvancedDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::OpenKeyboardAdvancedDialog(COptionsSubKeyboard *this)
{
  COptionsSubKeyboardAdvancedDlg *v2; // edi
  unsigned int v3; // eax
  COptionsSubKeyboardAdvancedDlg *v4; // eax
  vgui::Panel *v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_OptionsSubKeyboardAdvancedDlg) == nullptr )
  {
    v2 = (COptionsSubKeyboardAdvancedDlg *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
    {
      v3 = this->GetVParent(this);
      v4 = COptionsSubKeyboardAdvancedDlg::COptionsSubKeyboardAdvancedDlg(this: v2, hParent: v3);
    }
    else
    {
      v4 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_OptionsSubKeyboardAdvancedDlg, pPanel: v4);
  }
  v5 = vgui::PHandle::Get(this: &this->m_OptionsSubKeyboardAdvancedDlg);
  v5->__vftable[1].OnTick(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101DA5C0
// Name: private: void COptionsSubKeyboard::ApplyAllBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::ApplyAllBindings(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard *v1; // edi
  int j; // ebx
  ButtonCode_t v3; // esi
  const char *v4; // eax
  int JoystickForCode; // eax
  char *v6; // eax
  void **p_binding; // esi
  int k; // ebx
  VControlsListPanel_vtbl *v9; // esi
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  char *String; // eax
  const char *v14; // ebx
  char *v15; // eax
  ButtonCode_t v16; // eax
  ButtonCode_t v17; // esi
  const char *v18; // eax
  int v19; // eax
  char *v20; // eax
  unsigned int v21; // kr00_4
  char *v22; // ebx
  const char *v23; // [esp-8h] [ebp-24h]
  const char *v24; // [esp-4h] [ebp-20h]
  IVEngineClient_vtbl *v25; // [esp+Ch] [ebp-10h]
  IVEngineClient_vtbl *ia; // [esp+10h] [ebp-Ch]
  int i; // [esp+10h] [ebp-Ch]
  char *binding; // [esp+18h] [ebp-4h]

  v1 = this;
  for ( j = 0; j < v1->m_KeysToUnbind.m_Size; ++j )
  {
    v3 = v1->m_KeysToUnbind.m_Memory.m_pMemory[j];
    v4 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v3);
    if ( v4 != nullptr && *v4 != 0 )
    {
      v24 = v4;
      ia = engine->__vftable;
      JoystickForCode = GetJoystickForCode(code: v3);
      v6 = UTIL_va(format: "cmd%d unbind \"%s\"\n", JoystickForCode + 1, v24);
      ia->ClientCmd_Unrestricted(this: engine, a2: v6);
    }
  }
  v1->m_KeysToUnbind.m_Size = 0;
  p_binding = (void **)&v1->m_Bindings[0].binding;
  for ( k = 306; k != 0; --k )
  {
    if ( *p_binding != nullptr )
    {
      C_BaseEntity::operator delete(pMem: *p_binding);
      *p_binding = nullptr;
    }
    ++p_binding;
  }
  for ( i = 0; i < v1->m_pKeyBindList->GetItemCount(this: v1->m_pKeyBindList); k = i )
  {
    v9 = v1->m_pKeyBindList->__vftable;
    v10 = v9->GetItemIDFromRow(this: v1->m_pKeyBindList, a2: k);
    v11 = v9->GetItemData(this: v1->m_pKeyBindList, a2: v10);
    v12 = v11;
    if ( v11 != nullptr )
    {
      String = KeyValues::GetString(this: v11, keyName: "Binding", defaultValue: prType);
      v14 = String;
      binding = String;
      if ( String != nullptr && *String != 0 )
      {
        v15 = KeyValues::GetString(this: v12, keyName: "Key", defaultValue: prType);
        if ( v15 != nullptr && *v15 != 0 )
        {
          v16 = g_pInputSystem->StringToButtonCode(this: g_pInputSystem, a2: v15);
          v17 = v16;
          if ( (unsigned int)(v16 - 114) <= 0xBF )
            v17 = ButtonCodeToJoystickButtonCode(code: v16, nDesiredJoystick: v1->m_nSplitScreenUser);
          v18 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v17);
          if ( v18 != nullptr && *v18 != 0 )
          {
            v23 = v18;
            v25 = engine->__vftable;
            v19 = GetJoystickForCode(code: v17);
            v20 = UTIL_va(format: "cmd%d bind \"%s\" \"%s\"\n", v19 + 1, v23, v14);
            v25->ClientCmd_Unrestricted(this: engine, a2: v20);
            v14 = binding;
          }
          if ( v17 != BUTTON_CODE_INVALID )
          {
            v21 = strlen(v14);
            v22 = (char *)MemAlloc_Alloc(nSize: v21 + 1);
            V_strncpy(pDest: v22, pSrc: binding, maxLen: v21 + 1);
            this->m_Bindings[v17].binding = v22;
            v1 = this;
          }
        }
      }
    }
    ++i;
  }
  engine->ClientCmd_Unrestricted(this: engine, a2: "exec userconfig.cfg\nhost_writeconfig\n");
}

//------------------------------------------------------------------------------
// Address: 0x101DA800
// Name: private: void COptionsSubKeyboard::FillInDefaultBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::FillInDefaultBindings(COptionsSubKeyboard *this)
{
  void *v2; // esi
  int v3; // edi
  const char *m_pMemory; // esi
  int GameUIActiveSplitScreenPlayerSlot; // eax
  int v6; // edi
  const char *v7; // eax
  KeyValues *ItemForBinding; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  char szBinding[256]; // [esp+8h] [ebp-380h] BYREF
  char szValue[256]; // [esp+108h] [ebp-280h] BYREF
  char szKeyName[256]; // [esp+208h] [ebp-180h] BYREF
  char cmd[64]; // [esp+308h] [ebp-80h] BYREF
  CUtlBuffer buf; // [esp+348h] [ebp-40h] BYREF
  CGameUIConVarRef var; // [esp+378h] [ebp-10h] BYREF

  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: "cfg/config_default.cfg", a3: "rb", a4: 0);
  if ( v2 != nullptr )
  {
    engine->ClientCmd_Unrestricted(this: engine, a2: "unbindall\n");
    v3 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v3, nFlags: 1u);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: v3, a4: v2);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
    COptionsSubKeyboard::ClearBindItems(this);
    m_pMemory = (const char *)buf.m_Memory.m_pMemory;
    while ( m_pMemory != nullptr )
    {
      m_pMemory = engine->ParseFile(this: engine, a2: m_pMemory, a3: cmd, a4: 64);
      if ( cmd[0] == 0 )
        break;
      if ( _V_stricmp(s1: cmd, s2: "bind") != 0 && _V_stricmp(s1: cmd, s2: "cmd2 bind") != 0 )
      {
        CGameUIConVarRef::CGameUIConVarRef(this: &var, pName: cmd);
        if ( CGameUIConVarRef::IsValid(this: &var) )
        {
          memset(szValue, 0, sizeof(szValue));
          m_pMemory = engine->ParseFile(this: engine, a2: m_pMemory, a3: szValue, a4: 256);
          GameUIActiveSplitScreenPlayerSlot = GetGameUIActiveSplitScreenPlayerSlot();
          var.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar->SetValue_4(
            this: var.m_Info[GameUIActiveSplitScreenPlayerSlot].m_pConVar,
            a2: szValue);
        }
      }
      else
      {
        v6 = _V_stricmp(s1: cmd, s2: "cmd2 bind") == 0;
        v7 = engine->ParseFile(this: engine, a2: m_pMemory, a3: szKeyName, a4: 256);
        if ( szKeyName[0] == 0 )
          break;
        m_pMemory = engine->ParseFile(this: engine, a2: v7, a3: szBinding, a4: 256);
        if ( szKeyName[0] == 0 )
          break;
        if ( v6 == this->m_nSplitScreenUser )
        {
          ItemForBinding = COptionsSubKeyboard::GetItemForBinding(this, binding: szBinding);
          if ( ItemForBinding != nullptr )
            COptionsSubKeyboard::AddBinding(this, item: ItemForBinding, keyname: szKeyName);
        }
      }
    }
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "ApplyButtonEnable");
    else
      v10 = nullptr;
    this->PostActionSignal(this, a2: v10);
    v11 = COptionsSubKeyboard::GetItemForBinding(this, binding: "toggleconsole");
    if ( v11 != nullptr )
      COptionsSubKeyboard::AddBinding(this, item: v11, keyname: "`");
    v12 = COptionsSubKeyboard::GetItemForBinding(this, binding: "cancelselect");
    if ( v12 != nullptr )
      COptionsSubKeyboard::AddBinding(this, item: v12, keyname: "ESCAPE");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DAA80
// Name: public: virtual COptionsSubKeyboard::~COptionsSubKeyboard(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::~COptionsSubKeyboard(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard::KeyBinding *m_Bindings; // esi
  int i; // edi

  this->__vftable = (COptionsSubKeyboard_vtbl *)&COptionsSubKeyboard::`vftable';
  m_Bindings = this->m_Bindings;
  for ( i = 306; i != 0; --i )
  {
    if ( m_Bindings->binding != nullptr )
    {
      C_BaseEntity::operator delete(pMem: m_Bindings->binding);
      m_Bindings->binding = nullptr;
    }
    ++m_Bindings;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_KeysToUnbind);
  vgui::PropertyPage::~PropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DAAD0
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubKeyboard::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubKeyboard::GetMessageMap(COptionsSubKeyboard *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubKeyboard::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubKeyboard::GetMessageMap'::`2'::s_pMap;
  `COptionsSubKeyboard::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubKeyboard");
  `COptionsSubKeyboard::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DAB00
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubKeyboard::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubKeyboard::GetAnimMap(COptionsSubKeyboard *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubKeyboard");
}

//------------------------------------------------------------------------------
// Address: 0x101DAB10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubKeyboard::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubKeyboard::GetKBMap(COptionsSubKeyboard *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubKeyboard::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubKeyboard::GetKBMap'::`2'::s_pMap;
  `COptionsSubKeyboard::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubKeyboard");
  `COptionsSubKeyboard::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DAB40
// Name: public: virtual void COptionsSubKeyboard::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COptionsSubKeyboard::OnApplyChanges(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard::ApplyAllBindings(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DAB50
// Name: private: virtual void COptionsSubKeyboard::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::OnCommand(COptionsSubKeyboard *this, const char *command)
{
  vgui::QueryBox *v3; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( _V_stricmp(s1: command, s2: "Defaults") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "DefaultsOK") != 0 )
    {
      if ( this->m_pKeyBindList->IsCapturing(this: this->m_pKeyBindList)
        || _V_stricmp(s1: command, s2: "ChangeKey") != 0 )
      {
        if ( this->m_pKeyBindList->IsCapturing(this: this->m_pKeyBindList)
          || _V_stricmp(s1: command, s2: "ClearKey") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "Advanced") != 0 )
            vgui::Panel::OnCommand(this, command);
          else
            COptionsSubKeyboard::OpenKeyboardAdvancedDialog(this);
        }
        else
        {
          this->OnKeyCodePressed(this, a2: KEY_DELETE);
          this->m_pKeyBindList->RequestFocus(this: this->m_pKeyBindList, a2: 0);
        }
      }
      else
      {
        this->m_pKeyBindList->StartCaptureMode(this: this->m_pKeyBindList, a2: 15u);
      }
    }
    else
    {
      COptionsSubKeyboard::FillInDefaultBindings(this);
      this->m_pKeyBindList->RequestFocus(this: this->m_pKeyBindList, a2: 0);
    }
  }
  else
  {
    v3 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
    if ( v3 != nullptr )
      Box = vgui::QueryBox::QueryBox(
              this: v3,
              title: "#GameUI_KeyboardSettings",
              queryText: "#GameUI_KeyboardSettingsText",
              parent: nullptr);
    else
      Box = nullptr;
    Box->AddActionSignalTarget_2(this: Box, a2: this);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Command", firstKey: "command", firstValue: "DefaultsOK");
    else
      v6 = nullptr;
    vgui::QueryBox::SetOKCommand(this: Box, keyValues: v6);
    Box->DoModal_2(this: Box, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DACD0
// Name: private: void COptionsSubKeyboard::ParseActionDescriptions(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubKeyboard::ParseActionDescriptions(
        COptionsSubKeyboard *this@<ecx>,
        int a2@<ebx>,
        char *a3@<edi>)
{
  int v4; // ebx
  const char *i; // edi
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  int v7; // edi
  vgui::ISchemeManager_vtbl *v8; // edi
  int v9; // eax
  int v10; // eax
  COptionsSubKeyboard_vtbl *v11; // edx
  vgui::ISchemeManager_vtbl *v12; // edi
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  char szBinding[256]; // [esp+4h] [ebp-43Ch] BYREF
  char token[512]; // [esp+104h] [ebp-33Ch] BYREF
  char szDescription[256]; // [esp+304h] [ebp-13Ch] BYREF
  CUtlBuffer buf; // [esp+404h] [ebp-3Ch] BYREF
  const char *data; // [esp+434h] [ebp-Ch]
  vgui::ISchemeManager *v23; // [esp+438h] [ebp-8h]
  int nColumn1; // [esp+43Ch] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  if ( g_pFullFileSystem->ReadFile(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "scripts/kb_act.lst",
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    v4 = 0;
    for ( i = engine->ParseFile(this: engine, a2: buf.m_Memory.m_pMemory, a3: token, a4: 512);
          strlen(token) != 0;
          i = engine->ParseFile(this: engine, a2: data, a3: token, a4: 512) )
    {
      V_strncpy(pDest: szBinding, pSrc: token, maxLen: 256);
      data = engine->ParseFile(this: engine, a2: i, a3: token, a4: 512);
      if ( strlen(token) == 0 )
        break;
      V_strncpy(pDest: szDescription, pSrc: token, maxLen: 256);
      if ( szDescription[0] != 61 )
      {
        if ( _V_stricmp(s1: szBinding, s2: "blank") != 0 )
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "Item");
          else
            v15 = nullptr;
          KeyValues::SetString(this: v15, keyName: "Action", value: szDescription);
          KeyValues::SetString(this: v15, keyName: "Binding", value: szBinding);
          KeyValues::SetString(this: v15, keyName: "Key", value: (char *)prType);
          this->m_pKeyBindList->AddItem(this: this->m_pKeyBindList, a2: v4, a3: v15);
          KeyValues::deleteThis(this: v15);
        }
        else
        {
          IsProportional = this->IsProportional;
          nColumn1 = 286;
          v7 = 128;
          if ( ((unsigned __int8 (__thiscall *)(COptionsSubKeyboard *, char *, int))IsProportional)(
                 a1: this,
                 a2: a3,
                 a3: a2) != 0 )
          {
            v8 = g_pVGuiSchemeManager->__vftable;
            nColumn1 = (int)g_pVGuiSchemeManager;
            v9 = ((int (__thiscall *)(COptionsSubKeyboard *, int))this->GetScheme)(a1: this, a2: 286);
            v10 = ((int (__thiscall *)(int, int))v8->GetProportionalScaledValueEx)(a1: nColumn1, a2: v9);
            v11 = this->__vftable;
            nColumn1 = v10;
            v12 = g_pVGuiSchemeManager->__vftable;
            v23 = g_pVGuiSchemeManager;
            v13 = ((int (__thiscall *)(COptionsSubKeyboard *, int))v11->GetScheme)(a1: this, a2: 128);
            v7 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v12->GetProportionalScaledValueEx)(a1: v23, a2: v13);
          }
          a2 = 0;
          a3 = szDescription;
          ((void (__thiscall *)(VControlsListPanel *, int))this->m_pKeyBindList->AddSection_2)(
            a1: this->m_pKeyBindList,
            a2: ++v4);
          this->m_pKeyBindList->AddColumnToSection_2(
            this: this->m_pKeyBindList,
            a2: v4,
            a3: "Action",
            a4: szDescription,
            a5: 4,
            a6: nColumn1,
            a7: 0);
          this->m_pKeyBindList->AddColumnToSection_2(
            this: this->m_pKeyBindList,
            a2: v4,
            a3: "Key",
            a4: "#GameUI_KeyButton",
            a5: 4,
            a6: v7,
            a7: 0);
        }
      }
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101DAF80
// Name: public: static void COptionsSubKeyboard::PanelMessageFunc_ItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubKeyboard::PanelMessageFunc_ItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubKeyboard::PanelMessageFunc_ItemSelected::InitVar'::`2'::bAdded )
  {
    `COptionsSubKeyboard::PanelMessageFunc_ItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubKeyboard");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "itemID";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB020
// Name: public: COptionsSubKeyboard::COptionsSubKeyboard(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubKeyboard *__userpurge COptionsSubKeyboard::COptionsSubKeyboard@<eax>(
        COptionsSubKeyboard *this@<ecx>,
        int a2@<ebx>,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  bool v7; // zf
  int m_nValue; // eax
  VControlsListPanel *v9; // eax
  VControlsListPanel *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubKeyboard_vtbl *)&COptionsSubKeyboard::`vftable';
  if ( `COptionsSubKeyboard::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboard::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubKeyboard");
    v4->pfnClassName = COptionsSubKeyboard::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubKeyboard::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboard::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "COptionsSubKeyboard");
    v5->pfnClassName = COptionsSubKeyboard::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubKeyboard::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubKeyboard::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubKeyboard");
    v6->pfnClassName = COptionsSubKeyboard::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubKeyboard::PanelMessageFunc_ItemSelected::InitVar();
  this->m_OptionsSubKeyboardAdvancedDlg.m_iPanelID = -1;
  this->m_KeysToUnbind.m_Memory.m_pMemory = nullptr;
  this->m_KeysToUnbind.m_Memory.m_nAllocationCount = 0;
  this->m_KeysToUnbind.m_Memory.m_nGrowSize = 0;
  this->m_KeysToUnbind.m_Size = 0;
  this->m_KeysToUnbind.m_pElements = nullptr;
  _V_memset(dest: (int)this->m_Bindings, fill: nullptr, count: 0x4C8u);
  v7 = (_S1_2 & 1) == 0;
  this->m_nSplitScreenUser = 0;
  if ( v7 )
  {
    _S1_2 |= 1u;
    CGameUIConVarRef::CGameUIConVarRef(this: &in_forceuser, pName: "in_forceuser");
  }
  if ( CGameUIConVarRef::IsValid(this: &in_forceuser) )
  {
    m_nValue = in_forceuser.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue;
    if ( m_nValue >= 0 )
    {
      if ( m_nValue > 1 )
        m_nValue = 1;
    }
    else
    {
      m_nValue = 0;
    }
  }
  else if ( engine->GetActiveSplitScreenPlayerSlot(this: engine) >= 0 )
  {
    m_nValue = engine->GetActiveSplitScreenPlayerSlot(this: engine);
  }
  else
  {
    m_nValue = 0;
  }
  this->m_nSplitScreenUser = m_nValue;
  v9 = (VControlsListPanel *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v9 != nullptr )
    v10 = VControlsListPanel::VControlsListPanel(this: v9, parent: this, listName: "listpanel_keybindlist");
  else
    v10 = nullptr;
  this->m_pKeyBindList = v10;
  COptionsSubKeyboard::SaveCurrentBindings(this);
  COptionsSubKeyboard::ParseActionDescriptions(this, a2, a3: nullptr);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "ChangeKeyButton",
            text: prType,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pSetBindingButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "ClearKeyButton",
            text: prType,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pClearBindingButton = v14;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/OptionsSubKeyboard.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pSetBindingButton->SetEnabled(this: this->m_pSetBindingButton, a2: false);
  this->m_pClearBindingButton->SetEnabled(this: this->m_pClearBindingButton, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DB2A0
// Name: private: void COptionsSubKeyboard::FillInCurrentBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::FillInCurrentBindings(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard *v1; // esi
  CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *p_m_KeysToUnbind; // edi
  ButtonCode_t v3; // ebx
  int v4; // eax
  const char *v5; // eax
  KeyValues *ItemForBinding; // esi
  char *v7; // ebx
  char *String; // eax
  ButtonCode_t v9; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  int *v14; // eax
  CGameUIConVarRef var; // [esp+Ch] [ebp-20h] BYREF
  ButtonCode_t currentBC; // [esp+1Ch] [ebp-10h] BYREF
  COptionsSubKeyboard *v17; // [esp+20h] [ebp-Ch]
  int i; // [esp+24h] [ebp-8h]
  bool bIsJoystickCode; // [esp+2Ah] [ebp-2h]
  bool bJoystick; // [esp+2Bh] [ebp-1h]

  v1 = this;
  p_m_KeysToUnbind = (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_KeysToUnbind;
  v3 = BUTTON_CODE_NONE;
  v17 = this;
  this->m_KeysToUnbind.m_Size = 0;
  COptionsSubKeyboard::ClearBindItems(this);
  bJoystick = false;
  CGameUIConVarRef::CGameUIConVarRef(this: &var, pName: "joystick");
  if ( CGameUIConVarRef::IsValid(this: &var) )
    bJoystick = var.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue != 0;
  i = 0;
  while ( 1 )
  {
    if ( (unsigned int)(v3 - 114) > 0xBF )
    {
      bIsJoystickCode = false;
    }
    else
    {
      bIsJoystickCode = true;
      if ( v3 > JOYSTICK_LAST_BUTTON )
      {
        if ( (unsigned int)(v3 - 242) > 0xF )
          v4 = (v3 - 258) / 12;
        else
          v4 = (v3 - 242) / 4;
      }
      else
      {
        v4 = (v3 - 114) / 32;
      }
      if ( v4 != v1->m_nSplitScreenUser )
        goto LABEL_28;
    }
    v5 = gameuifuncs->GetBindingForButtonCode(this: gameuifuncs, a2: v3);
    if ( v5 != nullptr )
    {
      ItemForBinding = COptionsSubKeyboard::GetItemForBinding(this: v1, binding: v5);
      if ( ItemForBinding != nullptr )
      {
        v7 = (char *)g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: v3);
        String = KeyValues::GetString(this: ItemForBinding, keyName: "Key", defaultValue: prType);
        if ( String != nullptr && *String != 0 )
        {
          v9 = gameuifuncs->GetButtonCodeForBind(this: gameuifuncs, a2: String, a3: -1);
          currentBC = v9;
          if ( !bJoystick || !bIsJoystickCode || (unsigned int)(v9 - 114) <= 0xBF )
          {
            v3 = i;
            goto LABEL_28;
          }
          CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
            this: p_m_KeysToUnbind,
            src: (vgui::TreeNode **)&currentBC);
        }
        COptionsSubKeyboard::AddBinding(this: v17, item: ItemForBinding, keyname: v7);
        m_Size = p_m_KeysToUnbind->m_Size;
        m_nAllocationCount = p_m_KeysToUnbind->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(this: &p_m_KeysToUnbind->m_Memory, num: m_Size - m_nAllocationCount + 1);
        ++p_m_KeysToUnbind->m_Size;
        m_pMemory = p_m_KeysToUnbind->m_Memory.m_pMemory;
        v13 = p_m_KeysToUnbind->m_Size - m_Size - 1;
        p_m_KeysToUnbind->m_pElements = p_m_KeysToUnbind->m_Memory.m_pMemory;
        if ( v13 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v13);
        v3 = i;
        v14 = (int *)&p_m_KeysToUnbind->m_Memory.m_pMemory[m_Size];
        if ( v14 != nullptr )
          *v14 = i;
      }
    }
LABEL_28:
    i = ++v3;
    if ( v3 >= BUTTON_CODE_LAST )
      break;
    v1 = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB460
// Name: public: virtual void COptionsSubKeyboard::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubKeyboard::OnResetData(COptionsSubKeyboard *this)
{
  COptionsSubKeyboard::FillInCurrentBindings(this);
  if ( this->IsVisible(this) )
    this->m_pKeyBindList->SetSelectedItem(this: this->m_pKeyBindList, a2: 0);
}
