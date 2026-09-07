// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/radiobutton.cpp
// Functions: 23
// ============================================================

#include "vgui2\vgui_controls\radiobutton.h"

//------------------------------------------------------------------------------
// Address: 0x1029BB90
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x102C2FD0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C2FE0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C30B0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C31F0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x102C3200
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x102C3210
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  KeyValues *v16; // [esp+14h] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      v16 = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      v16 = nullptr;
    KeyValues::SetPtr(this: v16, keyName: "panel", value: this);
    KeyValues::SetInt(this: v16, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    v13 = v8;
    if ( v8 != 0 )
    {
      v14 = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( v15 != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: v16);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: v15,
              a3: Copy,
              a4: v12);
            v8 = v13;
            v7 = v14;
          }
          v14 = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v16);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102C33A0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3400
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102C3470
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102C34C0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 1024, pFormat: "%s, int SubTabPosition", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x102C34F0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C3510
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C3520
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102C3530
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x102C3670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C36A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C36B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C36E0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x102C3820
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C38E0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3980
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3AD0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x10016530
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10034C80
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x1004E3C0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055D90
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x10055DA0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055E70
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10055FB0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10055FC0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x10056150
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100561B0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  unsigned int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10056220
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10056270
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  const char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x100562A0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100562C0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100562D0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100562E0
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10056420
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056450
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x10056460
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056490
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x100565D0
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056690
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056730
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10056880
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004266A0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C810
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0043C820
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C8F0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043CA40
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043CA50
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0043CA60
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043CA70
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0043CC00
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CC60
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043CCD0
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD20
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD50
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD70
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD80
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD90
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043CED0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF00
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0043CF10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF40
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0043D080
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D140
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D1E0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043D330
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10058AF0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C390
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x1006C3A0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C470
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006C5B0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1006C5C0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1006C5D0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1006C760
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C7C0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1006C830
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1006C880
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x1006C8B0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006C8D0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006C8E0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1006C8F0
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1006CA30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006CA60
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x1006CA70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006CAA0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x1006CBE0
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CCA0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CD40
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006CE90
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10072A70
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005F9020
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x005F9030
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x006031D0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006148B0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x006148C0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00614990
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00614AD0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x00614AE0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x00614C70
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00614CD0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00614D40
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00614D90
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x00614DC0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00614DE0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00614DF0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00614E00
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00614F40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00614F70
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x00614F80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00614FB0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x006150F0
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006151B0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00615250
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006153A0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1029BCC0
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x102C30C0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C30D0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C31A0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C32E0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x102C32F0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x102C3300
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  KeyValues *v16; // [esp+14h] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      v16 = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      v16 = nullptr;
    KeyValues::SetPtr(this: v16, keyName: "panel", value: this);
    KeyValues::SetInt(this: v16, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    v13 = v8;
    if ( v8 != 0 )
    {
      v14 = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( v15 != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: v16);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: v15,
              a3: Copy,
              a4: v12);
            v8 = v13;
            v7 = v14;
          }
          v14 = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v16);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x102C3490
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3560
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102C35B0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_9, maxLen: 1024, pFormat: "%s, int SubTabPosition", Description);
  return buf_9;
}

//------------------------------------------------------------------------------
// Address: 0x102C35E0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C3600
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C3610
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102C3620
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x102C3760
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3790
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C37A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C37D0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x102C3910
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C39D0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3A70
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3BC0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10152F30
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x102EA040
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F8690
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x10300420
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x10300430
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300500
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10300650
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10300660
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  KeyValues *v16; // [esp+14h] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      v16 = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      v16 = nullptr;
    KeyValues::SetPtr(this: v16, keyName: "panel", value: this);
    KeyValues::SetInt(this: v16, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    v13 = v8;
    if ( v8 != 0 )
    {
      v14 = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( v15 != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: v16);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: v15,
              a3: Copy,
              a4: v12);
            v8 = v13;
            v7 = v14;
          }
          v14 = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v16);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x103007F0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300850
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103008C0
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10300910
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  const char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_11, maxLen: 1024, pFormat: "%s, int SubTabPosition", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x10300940
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10300960
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10300970
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10300980
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10300AD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10300B00
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x10300B10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10300B40
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x10300C80
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300D40
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10300DE0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10300F30
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100BA750
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7CC0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x100C7CD0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C7DA0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C7EE0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x100C7EF0
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x100C7F00
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x100C7F10
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+0h] [ebp-18h]
  unsigned int v13; // [esp+8h] [ebp-10h]
  int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  KeyValues *v16; // [esp+14h] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      v16 = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      v16 = nullptr;
    KeyValues::SetPtr(this: v16, keyName: "panel", value: this);
    KeyValues::SetInt(this: v16, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    v13 = v8;
    if ( v8 != 0 )
    {
      v14 = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          v15 = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( v15 != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: v16);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: v15,
              a3: Copy,
              a4: v12);
            v8 = v13;
            v7 = v14;
          }
          v14 = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v16);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x100C80A0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8100
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100C8170
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100C81C0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_11, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_11;
}

//------------------------------------------------------------------------------
// Address: 0x100C81F0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C8210
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C8220
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100C8230
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100C8370
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C83A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x100C83B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C83E0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x100C8520
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C85E0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C8680
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C87D0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00446C30
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004553E0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0045CEA0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0045CEB0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045CF80
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045D0C0
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0045D0D0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0045D0E0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0045D270
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D2D0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0045D340
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0045D390
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x0045D3C0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0045D3E0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045D3F0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0045D400
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0045D550
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D580
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0045D590
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D5C0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0045D700
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D7C0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D860
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045D9B0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042E1D0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__userpurge vgui::ToggleButton::GetButtonFgColor@<eax>(
        vgui::ToggleButton *this@<ecx>,
        __m128i a2@<xmm0>,
        Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, a2, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043C500
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0043C510
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x00443D00
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x00443D10
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443DE0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  int v5; // eax
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // ebp
  Color *v12; // eax
  vgui::RadioButton_vtbl *v13; // ebx
  Color armedBgColor; // ebp
  Color *v15; // eax
  _BYTE v16[4]; // [esp+3Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = ((int (__thiscall *)(vgui::RadioButton *))this->IsProportional)(a1: this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  v11 = this->GetBgColor(this, result: &pScheme);
  v12 = this->GetFgColor(this, result: v16);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, _DWORD))v10->SetDefaultColor)(a1: this, a2: *v12, a3: *v11);
  v13 = this->__vftable;
  armedBgColor = this->_armedBgColor;
  v15 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, Color))v13->SetArmedColor)(a1: this, a2: *v15, a3: armedBgColor);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00443F10
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x00443F20
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(
        vgui::RadioButton *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        KeyValues *state,
        unsigned int a6)
{
  vgui::RadioButton_vtbl *v7; // eax
  KeyValues *v8; // eax
  int v9; // ebp
  KeyValues *v10; // ebx
  unsigned int v11; // edi
  int v12; // ebx
  vgui::IVGui *v13; // ebp
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // edi
  KeyValues *Copy; // eax
  int v17; // [esp+1Ch] [ebp-14h]
  KeyValues *v18; // [esp+2Ch] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  v7 = this->__vftable;
  if ( (_BYTE)state == 1 )
  {
    if ( ((unsigned __int8 (*)(void))v7->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3: a4,
      a4: a3);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v9 = 0;
    if ( v8 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v8, setName: "RadioButtonChecked");
      v18 = v10;
    }
    else
    {
      v18 = nullptr;
      v10 = nullptr;
    }
    KeyValues::SetPtr(this: v10, keyName: "panel", value: this);
    KeyValues::SetInt(this: v10, keyName: "tabposition", value: this->_oldTabPosition);
    v11 = this->GetVParent(this);
    state = (KeyValues *)v11;
    if ( v11 != 0 )
    {
      retaddr = nullptr;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v11) > 0 )
      {
        do
        {
          v12 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, int, unsigned int))g_pVGuiPanel->GetChild)(
                  a1: g_pVGuiPanel,
                  a2: v11,
                  a3: v9,
                  a4: a2);
          if ( v12 != this->GetVPanel(this) )
          {
            v13 = g_pVGui;
            p_PostMessage = &g_pVGui->PostMessage;
            v17 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
            Copy = KeyValues::MakeCopy(this: state);
            ((void (__thiscall *)(vgui::IVGui *, int, KeyValues *, int))*p_PostMessage)(
              a1: v13,
              a2: v12,
              a3: Copy,
              a4: v17);
            v11 = a6;
            v9 = (int)state;
          }
          ++v9;
          a2 = v11;
          state = (KeyValues *)v9;
        }
        while ( v9 < ((int (__thiscall *)(vgui::IPanel *))g_pVGuiPanel->GetChildCount)(a1: g_pVGuiPanel) );
        v10 = v18;
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    if ( ((int (*)(void))v7->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, (bool)state);
}

//------------------------------------------------------------------------------
// Address: 0x004440B0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444110
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00444170
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004441B0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x004441E0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00444210
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00444220
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00444230
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = nullptr;
  v11 = 0;
  v4 = this->GetParent(this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  highestRadio = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: highestRadio);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > v11 && direction == -1 )
      {
        v3 = v8;
        v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++highestRadio >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
LABEL_18:
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00444370
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004443A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x004443B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004443E0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x00444540
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444600
// Name: public: static void vgui::RadioButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::RadioButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
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
// Address: 0x00444680
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::RadioButton::AddToMap(
      scriptname: "RadioButtonChecked",
      function: (unsigned int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "tabposition",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004446E0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00444830
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063A8C0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064A9E0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0064A9F0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064AAC0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0064AC00
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0064AC10
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0064AC20
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0064AC30
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0064ADC0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064AE20
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0064AE90
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0064AEE0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x0064AF10
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0064AF30
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0064AF40
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0064AF50
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0064B090
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064B0C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0064B0D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0064B100
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, int proportional)
{
  int v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = (int)byte_5A5A5A;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, char *, int))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: byte_5A5A5A,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v3 + 12))(
                  a1: v3,
                  a2: "Marlett",
                  a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0064B240
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064B300
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0064B3A0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0064B4F0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10042940
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x10058D00
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x10060070
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x10060080
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060150
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10060290
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x100602A0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x10060430
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060490
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10060500
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10060550
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x10060580
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100605A0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100605B0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100605C0
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10060700
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10060730
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x10060740
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10060770
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x100608B0
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060970
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060A10
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10060B60
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10064F70
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100735C0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1007AFC0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x1007AFD0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B0A0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007B1E0
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x1007B1F0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x1007B200
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1007B390
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B3F0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007B460
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007B4B0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x1007B4E0
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007B500
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007B510
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1007B520
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1007B660
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B690
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x1007B6A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B6D0
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x1007B810
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B8D0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B970
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007BAC0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004369D0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445020
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0044CA30
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0044CA40
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CB10
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044CC50
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0044CC60
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0044CC70
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0044CE00
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CE60
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044CED0
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF20
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x0044CF50
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF70
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF80
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0044CF90
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044D0D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044D100
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0044D110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044D140
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0044D280
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D340
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D3E0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044D530
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0048E4D0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x00495C40
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x00495C50
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00495D20
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  int v5; // eax
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // ebp
  Color *v12; // eax
  vgui::RadioButton_vtbl *v13; // ebx
  Color armedBgColor; // ebp
  Color *v15; // eax
  _BYTE v16[4]; // [esp+3Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = ((int (__thiscall *)(vgui::RadioButton *))this->IsProportional)(a1: this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  v11 = this->GetBgColor(this, result: &pScheme);
  v12 = this->GetFgColor(this, result: v16);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, _DWORD))v10->SetDefaultColor)(a1: this, a2: *v12, a3: *v11);
  v13 = this->__vftable;
  armedBgColor = this->_armedBgColor;
  v15 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, Color))v13->SetArmedColor)(a1: this, a2: *v15, a3: armedBgColor);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00495E50
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x00495E60
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(
        vgui::RadioButton *this@<ecx>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        KeyValues *state,
        unsigned int a6)
{
  vgui::RadioButton_vtbl *v7; // eax
  KeyValues *v8; // eax
  int v9; // ebp
  KeyValues *v10; // ebx
  unsigned int v11; // edi
  int v12; // ebx
  vgui::IVGui *v13; // ebp
  void (__thiscall **p_PostMessage)(vgui::IVGui *, unsigned int, KeyValues *, unsigned int, float); // edi
  KeyValues *Copy; // eax
  int v17; // [esp+1Ch] [ebp-14h]
  KeyValues *v18; // [esp+2Ch] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h]

  v7 = this->__vftable;
  if ( (_BYTE)state == 1 )
  {
    if ( ((unsigned __int8 (*)(void))v7->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3: a4,
      a4: a3);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v9 = 0;
    if ( v8 != nullptr )
    {
      v10 = KeyValues::KeyValues(this: v8, setName: "RadioButtonChecked");
      v18 = v10;
    }
    else
    {
      v18 = nullptr;
      v10 = nullptr;
    }
    KeyValues::SetPtr(this: v10, keyName: "panel", value: this);
    KeyValues::SetInt(this: v10, keyName: "tabposition", value: this->_oldTabPosition);
    v11 = this->GetVParent(this);
    state = (KeyValues *)v11;
    if ( v11 != 0 )
    {
      retaddr = nullptr;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v11) > 0 )
      {
        do
        {
          v12 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, int, unsigned int))g_pVGuiPanel->GetChild)(
                  a1: g_pVGuiPanel,
                  a2: v11,
                  a3: v9,
                  a4: a2);
          if ( v12 != this->GetVPanel(this) )
          {
            v13 = g_pVGui;
            p_PostMessage = &g_pVGui->PostMessage;
            v17 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0.0);
            Copy = KeyValues::MakeCopy(this: state);
            ((void (__thiscall *)(vgui::IVGui *, int, KeyValues *, int))*p_PostMessage)(
              a1: v13,
              a2: v12,
              a3: Copy,
              a4: v17);
            v11 = a6;
            v9 = (int)state;
          }
          ++v9;
          a2 = v11;
          state = (KeyValues *)v9;
        }
        while ( v9 < ((int (__thiscall *)(vgui::IPanel *))g_pVGuiPanel->GetChildCount)(a1: g_pVGuiPanel) );
        v10 = v18;
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    if ( ((int (*)(void))v7->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, (bool)state);
}

//------------------------------------------------------------------------------
// Address: 0x00495FF0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496050
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004960B0
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004960F0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x00496120
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00496150
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00496160
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x00496170
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v3 = nullptr;
  v11 = 0;
  v4 = this->GetParent(this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  highestRadio = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_18;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: highestRadio);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > v11 && direction == -1 )
      {
        v3 = v8;
        v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++highestRadio >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
LABEL_18:
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004962B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004962E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x004962F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00496320
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x00496480
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496540
// Name: public: static void vgui::RadioButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::RadioButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
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
// Address: 0x004965C0
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::RadioButton::AddToMap(
      scriptname: "RadioButtonChecked",
      function: (unsigned int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "tabposition",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00496620
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00496770
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049BDE0
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x004252F0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433960
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0043B3E0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0043B3F0
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B4C0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043B610
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043B620
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043B630
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0043B7C0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B820
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043B890
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0043B8E0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 1024, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x0043B910
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043B930
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x0043B940
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043B950
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043BAA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BAD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0043BAE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BB10
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0043BC50
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BD10
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BDB0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043BF00
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00428D00
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004373E0
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043EEF0
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x0043EF00
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043EFD0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043F110
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x0043F120
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x0043F130
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x0043F2C0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F320
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0043F390
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0043F3E0
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_7, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_7;
}

//------------------------------------------------------------------------------
// Address: 0x0043F410
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0043F430
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// Force-skipped: ?Paint@RadioButton@vgui@@MAEXXZ

//------------------------------------------------------------------------------
// Address: 0x0043F440
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x0043F450
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043F590
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043F5C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x0043F5D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043F600
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x0043F740
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F800
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F8A0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0043F9F0
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039E4E0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD010
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x103B4A60
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x103B4A70
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B4B40
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B4C90
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x103B4CA0
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x103B4CB0
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x103B4E40
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B4EA0
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103B4F10
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103B4F60
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_12, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_12;
}

//------------------------------------------------------------------------------
// Address: 0x103B4F90
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B4FB0
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B4FC0
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x103B4FD0
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x103B5110
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B5140
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x103B5150
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B5180
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x103B52C0
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B5380
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarNegateCheckButton::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "tabposition";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B5420
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)MemAlloc_Alloc(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B5570
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10396ED0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::ToggleButton::GetButtonFgColor(vgui::ToggleButton *this, Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ACE00
// Name: public: static char const __near * vgui::RadioButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RadioButton::GetPanelClassName()
{
  return "RadioButton";
}

//------------------------------------------------------------------------------
// Address: 0x103ACE10
// Name: public: virtual void RadioImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::Paint(RadioImage *this)
{
  RadioImage_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  this->DrawSetTextFont(this, a2: this->_font);
  if ( this->_radioButton->IsEnabled(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->_radioButton->GetBgColor(this: this->_radioButton, result: v4);
    ((void (__thiscall *)(RadioImage *, _DWORD))v2->DrawSetTextColor_2)(a1: this, a2: *v3);
  }
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 110);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 106);
  ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
  this->DrawPrintChar(this, a2: 0, a3: 1, a4: 107);
  if ( this->_radioButton->IsSelected(this: this->_radioButton) )
  {
    ((void (__thiscall *)(RadioImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 104);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ACEE0
// Name: protected: virtual void vgui::RadioButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySchemeSettings(vgui::RadioButton *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  RadioImage_vtbl *v4; // ebx
  bool v5; // al
  vgui::RadioButton_vtbl *v6; // ebx
  Color *v7; // eax
  vgui::RadioButton_vtbl *v8; // ebx
  Color *v9; // eax
  vgui::RadioButton_vtbl *v10; // ebx
  Color *v11; // eax
  vgui::RadioButton_vtbl *v12; // ebx
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v14; // eax
  Color v15; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme);
  v4 = this->_radioBoxImage->__vftable;
  v5 = this->IsProportional(this);
  v4->ApplySchemeSettings(this: this->_radioBoxImage, a2: v2, a3: v5);
  v6 = this->__vftable;
  v7 = this->GetSchemeColor_2(this, result: &pScheme, a3: "RadioButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v6->SetFgColor)(a1: this, a2: *v7);
  v8 = this->__vftable;
  v9 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::RadioButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v8->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v16,
                              a3: "RadioButton.SelectedTextColor",
                              a4: *v9,
                              a5: v2);
  v10 = this->__vftable;
  pScheme = (vgui::IScheme *)this->GetBgColor(this, result: v16);
  v11 = this->GetFgColor(this, result: &v15);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme_vtbl *))v10->SetDefaultColor)(
    a1: this,
    a2: *v11,
    a3: pScheme->__vftable);
  v12 = this->__vftable;
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme = (vgui::IScheme *)this->_armedBgColor;
  v14 = (_DWORD *)GetSchemeColor_2(this, result: &v15, a3: "RadioButton.ArmedTextColor", a4: v2);
  ((void (__thiscall *)(vgui::RadioButton *, _DWORD, vgui::IScheme *))v12->SetArmedColor)(
    a1: this,
    a2: *v14,
    a3: pScheme);
  this->SetContentAlignment(this, a2: a_west);
  this->SetImageAtIndex(this, a2: 0, a3: this->_radioBoxImage, a4: 0);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103AD020
// Name: public: virtual int vgui::RadioButton::GetSubTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetSubTabPosition(vgui::RadioButton *this)
{
  return this->_subTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x103AD030
// Name: public: virtual void vgui::RadioButton::SetSubTabPosition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::SetSubTabPosition(vgui::TextEntry *this, int count)
{
  this->_tabSpaces = count;
}

//------------------------------------------------------------------------------
// Address: 0x103AD040
// Name: public: virtual int vgui::RadioButton::GetRadioTabPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::RadioButton::GetRadioTabPosition(vgui::RadioButton *this)
{
  return this->_oldTabPosition;
}

//------------------------------------------------------------------------------
// Address: 0x103AD050
// Name: public: virtual void vgui::RadioButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::RadioButton::SetSelected(vgui::RadioButton *this@<ecx>, int a2@<ebx>, int a3@<edi>, bool state)
{
  vgui::RadioButton_vtbl *v5; // eax
  KeyValues *v6; // eax
  int v7; // ebx
  unsigned int v8; // edi
  vgui::IVGui *v9; // ebx
  vgui::IVGui_vtbl *v10; // edi
  KeyValues *Copy; // eax
  int v12; // [esp+18h] [ebp-18h]
  unsigned int radioParent; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int child; // [esp+28h] [ebp-8h]
  KeyValues *msg; // [esp+2Ch] [ebp-4h]

  v5 = this->__vftable;
  if ( state )
  {
    if ( ((unsigned __int8 (*)(void))v5->IsEnabled)() == 0 )
      return;
    ((void (__thiscall *)(vgui::RadioButton *, int, int, int))this->SetTabPosition)(
      a1: this,
      a2: this->_oldTabPosition,
      a3,
      a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v7 = 0;
    if ( v6 != nullptr )
      msg = KeyValues::KeyValues(this: v6, setName: "RadioButtonChecked");
    else
      msg = nullptr;
    KeyValues::SetPtr(this: msg, keyName: "panel", value: this);
    KeyValues::SetInt(this: msg, keyName: "tabposition", value: this->_oldTabPosition);
    v8 = this->GetVParent(this);
    radioParent = v8;
    if ( v8 != 0 )
    {
      i = 0;
      if ( g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) > 0 )
      {
        do
        {
          child = g_pVGuiPanel->GetChild(this: g_pVGuiPanel, a2: v8, a3: v7);
          if ( child != this->GetVPanel(this) )
          {
            v9 = g_pVGui;
            v10 = g_pVGui->__vftable;
            v12 = ((int (__thiscall *)(vgui::RadioButton *, _DWORD))this->GetVPanel)(a1: this, a2: 0);
            Copy = KeyValues::MakeCopy(this: msg);
            ((void (__thiscall *)(vgui::IVGui *, unsigned int, KeyValues *, int))v10->PostMessage)(
              a1: v9,
              a2: child,
              a3: Copy,
              a4: v12);
            v8 = radioParent;
            v7 = i;
          }
          i = ++v7;
        }
        while ( v7 < g_pVGuiPanel->GetChildCount(this: g_pVGuiPanel, a2: v8) );
      }
    }
    this->RequestFocus(this, a2: 0);
    this->PostActionSignal(this, a2: msg);
  }
  else
  {
    if ( ((int (*)(void))v5->GetTabPosition)() != 0 )
      this->_oldTabPosition = this->GetTabPosition(this);
    this->SetTabPosition(this, a2: 0);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  vgui::Button::SetSelected(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x103AD1E0
// Name: protected: virtual void vgui::RadioButton::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::PerformLayout(vgui::RadioButton *this)
{
  vgui::RadioButton_vtbl *v2; // edi
  Color *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsSelected(this) )
  {
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))this->SetFgColor)(
      a1: this,
      a2: *(_DWORD *)&this->_selectedFgColor);
    vgui::Button::PerformLayout(this);
  }
  else
  {
    v2 = this->__vftable;
    v3 = this->GetButtonFgColor(this, result: v4);
    ((void (__thiscall *)(vgui::RadioButton *, _DWORD))v2->SetFgColor)(a1: this, a2: *v3);
    vgui::Button::PerformLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD240
// Name: protected: virtual void vgui::RadioButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::ApplySettings(vgui::RadioButton *this, KeyValues *inResourceData)
{
  int Int; // eax
  RadioImage *radioBoxImage; // ecx

  vgui::Button::ApplySettings(this, inResourceData);
  this->SetTextColorState(this, a2: CS_NORMAL);
  this->_subTabPosition = KeyValues::GetInt(this: inResourceData, keyName: "SubTabPosition", defaultValue: 0);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "TabPosition", defaultValue: 0);
  radioBoxImage = this->_radioBoxImage;
  this->_oldTabPosition = Int;
  this->SetImageAtIndex(this, a2: 0, a3: radioBoxImage, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103AD2B0
// Name: protected: virtual void vgui::RadioButton::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::GetSettings(vgui::RadioButton *this, KeyValues *outResourceData)
{
  int v3; // eax

  vgui::Button::GetSettings(this, outResourceData);
  KeyValues::SetInt(this: outResourceData, keyName: "SubTabPosition", value: this->_subTabPosition);
  v3 = this->GetRadioTabPosition(this);
  KeyValues::SetInt(this: outResourceData, keyName: "TabPosition", value: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103AD300
// Name: protected: virtual char const __near * vgui::RadioButton::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::RadioButton::GetDescription(vgui::RadioButton *this)
{
  char *Description; // eax

  Description = vgui::Button::GetDescription(this);
  V_snprintf(pDest: buf_8, maxLen: 0x400u, pFormat: "%s, int SubTabPosition", Description);
  return buf_8;
}

//------------------------------------------------------------------------------
// Address: 0x103AD330
// Name: protected: virtual void vgui::RadioButton::OnRadioButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnRadioButtonChecked(vgui::RadioButton *this, int tabPosition)
{
  if ( tabPosition == this->_oldTabPosition )
    this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x103AD350
// Name: protected: virtual void vgui::RadioButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall vgui::RadioButton::Paint(vgui::RadioButton *this)
{
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AD360
// Name: protected: virtual void vgui::RadioButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::DoClick(vgui::RadioButton *this)
{
  this->SetSelected(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x103AD370
// Name: protected: class vgui::RadioButton __near * vgui::RadioButton::FindBestRadioButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::FindBestRadioButton(vgui::RadioButton *this, int direction)
{
  vgui::RadioButton *v2; // esi
  void *v3; // edi
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // ebx
  vgui::Panel *Child; // eax
  void *v7; // eax
  void *v8; // esi
  int highestRadio; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  v2 = this;
  v3 = nullptr;
  highestRadio = 0;
  v4 = (vgui::Panel *)((int (__fastcall *)(vgui::RadioButton *))this->GetParent)(a1: this);
  v5 = v4;
  if ( v4 == nullptr )
    return (vgui::RadioButton *)v3;
  i = 0;
  if ( vgui::Panel::GetChildCount(this: v4) <= 0 )
    goto LABEL_19;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this: v5, index: i);
    v7 = __RTDynamicCast(
           inptr: Child,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &vgui::RadioButton `RTTI Type Descriptor',
           isReference: 0);
    v8 = v7;
    if ( v7 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1152))(a1: v7) == this->_oldTabPosition )
    {
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == direction + this->_subTabPosition )
        break;
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) == 0 && direction == 1 )
      {
LABEL_12:
        v3 = v8;
        goto LABEL_13;
      }
      if ( (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8) > highestRadio && direction == -1 )
      {
        v3 = v8;
        highestRadio = (*(int (__thiscall **)(void *))(*(_DWORD *)v8 + 1144))(a1: v8);
      }
      else if ( v3 == nullptr )
      {
        goto LABEL_12;
      }
    }
LABEL_13:
    if ( ++i >= vgui::Panel::GetChildCount(this: v5) )
      goto LABEL_16;
  }
  v3 = v8;
LABEL_16:
  if ( v3 != nullptr )
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v3 + 48))(a1: v3, a2: 0);
  v2 = this;
LABEL_19:
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  v2->Repaint(this: v2);
  return (vgui::RadioButton *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x103AD4B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RadioButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RadioButton::GetMessageMap(vgui::RadioButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RadioButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetMessageMap'::`2'::s_pMap;
  `vgui::RadioButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
  `vgui::RadioButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AD4E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::RadioButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RadioButton::GetAnimMap(vgui::RadioButton *this)
{
  return FindOrAddPanelAnimationMap(className: "RadioButton");
}

//------------------------------------------------------------------------------
// Address: 0x103AD4F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RadioButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RadioButton::GetKBMap(vgui::RadioButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RadioButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RadioButton::GetKBMap'::`2'::s_pMap;
  `vgui::RadioButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
  `vgui::RadioButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AD520
// Name: public: virtual void RadioImage::ApplySchemeSettings(class vgui::IScheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RadioImage::ApplySchemeSettings(RadioImage *this, int pScheme, BOOL proportional)
{
  vgui::IScheme *v3; // edi
  Color v5; // ecx
  vgui::RadioButton *radioButton; // ecx
  vgui::RadioButton *v7; // ecx

  v3 = (vgui::IScheme *)pScheme;
  v5 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, int))this->_radioButton->GetSchemeColor)(
                   a1: this->_radioButton,
                   a2: &pScheme,
                   a3: "CheckButton.BgColor",
                   a4: 9868950,
                   a5: pScheme);
  pScheme = 1315860;
  this->_bgColor = v5;
  this->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))this->_radioButton->GetSchemeColor)(
                                    a1: this->_radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border1",
                                    a4: 1315860,
                                    a5: v3);
  radioButton = this->_radioButton;
  pScheme = 5921370;
  this->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))radioButton->GetSchemeColor)(
                                    a1: radioButton,
                                    a2: &pScheme,
                                    a3: "CheckButton.Border2",
                                    a4: 5921370,
                                    a5: v3);
  v7 = this->_radioButton;
  pScheme = 1315860;
  this->_checkColor = *(Color *)((int (__thiscall *)(vgui::RadioButton *, int *, const char *, int, vgui::IScheme *))v7->GetSchemeColor)(
                                  a1: v7,
                                  a2: &pScheme,
                                  a3: "CheckButton.Check",
                                  a4: 1315860,
                                  a5: v3);
  this->_font = v3->GetFont(this: v3, a2: "Marlett", a3: proportional);
}

//------------------------------------------------------------------------------
// Address: 0x103AD660
// Name: protected: virtual void vgui::RadioButton::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::RadioButton::OnKeyCodeTyped(vgui::RadioButton *this, ButtonCode_t code)
{
  vgui::RadioButton *v2; // esi
  bool v3; // al
  vgui::RadioButton *BestRadioButton; // eax

  v2 = this;
  switch ( code )
  {
    case KEY_ENTER:
    case KEY_SPACE:
      v3 = this->IsSelected(this);
      this = v2;
      if ( v3 )
        goto LABEL_8;
      v2->SetSelected(this: v2, a2: true);
      break;
    case KEY_UP:
    case KEY_LEFT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: -1);
      if ( BestRadioButton != nullptr )
        goto LABEL_5;
      break;
    case KEY_DOWN:
    case KEY_RIGHT:
      BestRadioButton = vgui::RadioButton::FindBestRadioButton(this, direction: 1);
      if ( BestRadioButton != nullptr )
LABEL_5:
        BestRadioButton->SetSelected(this: BestRadioButton, a2: true);
      break;
    default:
LABEL_8:
      vgui::Panel::OnKeyCodeTyped(this, keycode: code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD720
// Name: public: static void vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::CvarToggleCheckButton<ConVarRef>::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "tabposition";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AD7C0
// Name: public: vgui::RadioButton::RadioButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__thiscall vgui::RadioButton::RadioButton(
        vgui::RadioButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Image *v8; // eax
  RadioImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::RadioButton_vtbl *)&vgui::RadioButton::`vftable';
  if ( `vgui::RadioButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "RadioButton");
    v5->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "RadioButton");
    v6->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::RadioButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::RadioButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "RadioButton");
    v7->pfnClassName = vgui::RadioButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::RadioButton::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  v8 = (vgui::Image *)operator new(nSize: 0x30u);
  v9 = (RadioImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::Image::Image(this: v8);
    v9->__vftable = (RadioImage_vtbl *)&RadioImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_radioButton = this;
    v9->_font = 0;
    vgui::Image::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_radioBoxImage = v9;
  this->_oldTabPosition = 0;
  this->_subTabPosition = 0;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_radioBoxImage, offset: 0);
  vgui::Button::SetButtonActivationType(this, activationType: ACTIVATE_ONPRESSED);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AD910
// Name: Create_RadioButton
// Source: json
//------------------------------------------------------------------------------
vgui::RadioButton *__cdecl Create_RadioButton()
{
  vgui::RadioButton *v0; // eax

  v0 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v0 != nullptr )
    return vgui::RadioButton::RadioButton(this: v0, parent: nullptr, panelName: nullptr, text: "RadioButton");
  else
    return nullptr;
}

} // namespace server
