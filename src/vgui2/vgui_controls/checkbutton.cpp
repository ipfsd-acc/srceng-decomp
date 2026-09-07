// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/checkbutton.cpp
// Functions: 11
// ============================================================

#include "vgui2\vgui_controls\checkbutton.h"

//------------------------------------------------------------------------------
// Address: 0x102A56E0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x102A5700
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A59F0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5A20
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5A80
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102A5B70
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102A5E40
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x102A5EE0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A6080
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102DC630
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A5AA0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1003B580
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x1003B590
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B880
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003B8C0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B920
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x1003B9B0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B9E0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x1003B9F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BA60
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1003BD40
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x1003BDE0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003BF80
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003B940
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00427870
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00427880
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x004278A0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427B90
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427BD0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427C30
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00427CB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427CE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00427CF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427D90
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00428070
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x00428110
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004282B0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045C190
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427C50
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10052900
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x10052910
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10052930
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052C20
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10052C60
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052CC0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10052D40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052D70
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x10052D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052E20
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100530F0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x10053190
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10053330
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10089060
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052CE0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00604400
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00604410
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00604430
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00604720
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00604760
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006047C0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00604840
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00604870
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00604880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00604920
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00604C00
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x00604CA0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00604E40
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00640350
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006047E0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102A57F0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x102A5810
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5B00
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5B30
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5B90
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102A5C50
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102A5F20
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x102A5FD0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A6170
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102DC730
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A5BB0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102EB200
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x102EB210
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x102EB230
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB520
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EB560
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EB5C0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x102EB640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EB670
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x102EB680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102EB6F0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102EB9C0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x102EBA60
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102EBC00
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1032FB50
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10360BCF
// Name: public: ATL::CImage::CImage(void)
// Source: class_map
//------------------------------------------------------------------------------
ATL::CImage *__thiscall ATL::CImage::CImage(ATL::CImage *this)
{
  this->m_iTransparentColor = -1;
  this->m_clrTransparentColor = -1;
  this->__vftable = (ATL::CImage_vtbl *)&ATL::CImage::`vftable';
  this->m_hBitmap = nullptr;
  this->m_pBits = nullptr;
  this->m_nWidth = 0;
  this->m_nHeight = 0;
  this->m_nPitch = 0;
  this->m_nBPP = 0;
  *(_WORD *)&this->m_bIsDIBSection = 0;
  this->m_hDC = nullptr;
  this->m_nDCRefCount = 0;
  this->m_hOldBitmap = nullptr;
  ATL::CImage::CInitGDIPlus::IncreaseCImageCount(this: &ATL::CImage::s_initGDIPlus);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10360C60
// Name: public: void ATL::CImage::ReleaseDC(void)const
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::ReleaseDC(ATL::CImage *this)
{
  if ( this->m_nDCRefCount-- == 1 )
  {
    SelectObject(hdc: this->m_hDC, h: this->m_hOldBitmap);
    ATL::CImage::CDCCache::ReleaseDC(this: &ATL::CImage::s_cache, hDC: this->m_hDC);
    this->m_hDC = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10360C89
// Name: private: void ATL::CImage::UpdateBitmapInfo(enum ATL::CImage::DIBOrientation)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::UpdateBitmapInfo(ATL::CImage *this, ATL::CImage::DIBOrientation eOrientation)
{
  int biWidth; // eax
  unsigned int v4; // edi
  int v5; // kr00_4
  char *bmBits; // ecx
  int v7; // eax
  int bmBitsPixel; // eax
  int biHeight; // [esp-4h] [ebp-64h]
  tagDIBSECTION dibsection; // [esp+8h] [ebp-58h] BYREF

  if ( GetObjectA(h: this->m_hBitmap, c: 84, pv: &dibsection) == 84 )
  {
    biWidth = dibsection.dsBmih.biWidth;
    biHeight = dibsection.dsBmih.biHeight;
    this->m_bIsDIBSection = true;
    this->m_nWidth = biWidth;
    v4 = abs(lnumber: biHeight);
    v5 = dibsection.dsBmih.biBitCount * this->m_nWidth + 31;
    this->m_nBPP = dibsection.dsBmih.biBitCount;
    bmBits = (char *)dibsection.dsBm.bmBits;
    v7 = 4 * (v5 / 32);
    this->m_nHeight = v4;
    this->m_nPitch = v7;
    this->m_pBits = bmBits;
    if ( eOrientation == DIBOR_DEFAULT )
      eOrientation = (dibsection.dsBmih.biHeight > 0) + 1;
    if ( eOrientation == DIBOR_BOTTOMUP )
    {
      this->m_pBits = &bmBits[v7 * (v4 - 1)];
      this->m_nPitch = -4 * (v5 / 32);
    }
  }
  else
  {
    this->m_nWidth = dibsection.dsBm.bmWidth;
    this->m_nHeight = dibsection.dsBm.bmHeight;
    bmBitsPixel = dibsection.dsBm.bmBitsPixel;
    this->m_bIsDIBSection = false;
    this->m_nBPP = bmBitsPixel;
    this->m_nPitch = 0;
    this->m_pBits = nullptr;
  }
  this->m_iTransparentColor = -1;
  this->m_bHasAlphaChannel = false;
}

//------------------------------------------------------------------------------
// Address: 0x1036113A
// Name: public: int ATL::CImage::AlphaBlend(struct HDC__ __near *,int,int,int,int,int,int,int,int,unsigned char,unsigned char)const
// Source: class_map
//------------------------------------------------------------------------------
BOOL __thiscall ATL::CImage::AlphaBlend(
        ATL::CImage *this,
        HDC__ *hDestDC,
        int xDest,
        int yDest,
        int nDestWidth,
        int nDestHeight,
        int xSrc,
        int ySrc,
        int nSrcWidth,
        int nSrcHeight,
        __int16 bSrcAlpha,
        unsigned __int8 bBlendOp)
{
  BOOL v13; // edi
  BLENDFUNCTION blend; // [esp+34h] [ebp+2Ch]

  blend.SourceConstantAlpha = bSrcAlpha;
  *(_WORD *)&blend.BlendOp = bBlendOp;
  blend.AlphaFormat = this->m_bHasAlphaChannel;
  ATL::CImage::GetDC(this);
  v13 = AlphaBlend(
          hdcDest: hDestDC,
          xoriginDest: xDest,
          yoriginDest: yDest,
          wDest: nDestWidth,
          hDest: nDestHeight,
          hdcSrc: this->m_hDC,
          xoriginSrc: xSrc,
          yoriginSrc: ySrc,
          wSrc: nSrcWidth,
          hSrc: nSrcHeight,
          ftn: blend);
  ATL::CImage::ReleaseDC(this);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1036119A
// Name: public: int ATL::CImage::AlphaBlend(struct HDC__ __near *,struct tagRECT const __near &,struct tagRECT const __near &,unsigned char,unsigned char)const
// Source: class_map
//------------------------------------------------------------------------------
BOOL __thiscall ATL::CImage::AlphaBlend(
        ATL::CImage *this,
        HDC__ *hDestDC,
        const tagRECT *rectDest,
        const tagRECT *rectSrc,
        __int16 bSrcAlpha,
        unsigned __int8 bBlendOp)
{
  return ATL::CImage::AlphaBlend(
           this,
           hDestDC,
           xDest: rectDest->left,
           yDest: rectDest->top,
           nDestWidth: rectDest->right - rectDest->left,
           nDestHeight: rectDest->bottom - rectDest->top,
           xSrc: rectSrc->left,
           ySrc: rectSrc->top,
           nSrcWidth: rectSrc->right - rectSrc->left,
           nSrcHeight: rectSrc->bottom - rectSrc->top,
           bSrcAlpha,
           bBlendOp);
}

//------------------------------------------------------------------------------
// Address: 0x1036292B
// Name: public: virtual class Gdiplus::Image __near * Gdiplus::Image::Clone(void)
// Source: json
//------------------------------------------------------------------------------
Gdiplus::Image *__thiscall Gdiplus::Image::Clone(Gdiplus::Image *this)
{
  Gdiplus::Status v2; // eax
  Gdiplus::Image *result; // eax
  Gdiplus::Status lastResult; // esi
  Gdiplus::GpImage *v5; // ecx
  Gdiplus::GpImage *cloneimage; // [esp+4h] [ebp-4h] BYREF

  cloneimage = nullptr;
  v2 = GdipCloneImage(a1: (int)this->nativeImage, a2: (int)&cloneimage);
  if ( v2 != Ok )
    this->lastResult = v2;
  result = (Gdiplus::Image *)GdipAlloc(a1: 16);
  if ( result == nullptr )
    return nullptr;
  lastResult = this->lastResult;
  v5 = cloneimage;
  result->__vftable = (Gdiplus::Image_vtbl *)&Gdiplus::Image::`vftable';
  result->nativeImage = v5;
  result->lastResult = lastResult;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036296F
// Name: public: virtual ATL::CImage::~CImage(void)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::~CImage(ATL::CImage *this)
{
  bool v1; // zf
  HBITMAP__ *v2; // eax

  v1 = this->m_hBitmap == nullptr;
  this->__vftable = (ATL::CImage_vtbl *)&ATL::CImage::`vftable';
  if ( !v1 )
  {
    v2 = ATL::CImage::Detach(this);
    DeleteObject(ho: v2);
  }
  ATL::CImage::CInitGDIPlus::DecreaseCImageCount(this: &ATL::CImage::s_initGDIPlus);
}

//------------------------------------------------------------------------------
// Address: 0x10362991
// Name: public: int ATL::CImage::CreateEx(int,int,int,unsigned long,unsigned long const __near *,unsigned long)
// Source: class_map
//------------------------------------------------------------------------------
int __thiscall ATL::CImage::CreateEx(
        ATL::CImage *this,
        int nWidth,
        int nHeight,
        int nBPP,
        unsigned int eCompression,
        const unsigned int *pdwBitfields,
        char dwFlags)
{
  unsigned __int8 *v8; // eax
  BITMAPINFO *v9; // esi
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v10; // esi
  int v12; // eax
  HBITMAP__ *DIBSection; // eax
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v14; // esi
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *m_pHead; // esi
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v16; // [esp-8h] [ebp-14h]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v17; // [esp-8h] [ebp-14h]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v18; // [esp-4h] [ebp-10h]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator> _AtlSafeAllocaManager; // [esp+8h] [ebp-4h] BYREF

  _AtlSafeAllocaManager.m_pHead = nullptr;
  v8 = (unsigned __int8 *)ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::Allocate(
                            this: &_AtlSafeAllocaManager,
                            nRequestedSize: 0x428u);
  v9 = (BITMAPINFO *)v8;
  if ( v8 != nullptr )
  {
    memset(dst: v8, value: 0, count: 0x28u);
    v9->bmiHeader.biWidth = nWidth;
    v9->bmiHeader.biPlanes = 1;
    v9->bmiHeader.biSize = 40;
    v9->bmiHeader.biHeight = nHeight;
    v9->bmiHeader.biBitCount = nBPP;
    v9->bmiHeader.biCompression = eCompression;
    if ( nBPP > 8 )
    {
      if ( eCompression == 3 )
      {
        v12 = memcpy_s(dst: v9->bmiColors, sizeInBytes: 0xCu, src: pdwBitfields, count: 0xCu);
        AfxCrtErrorCheck(error: v12);
      }
    }
    else
    {
      memset(dst: (unsigned __int8 *)v9->bmiColors, value: 0, count: 0x400u);
    }
    DIBSection = CreateDIBSection(
                   hdc: nullptr,
                   pbmi: v9,
                   usage: 0,
                   ppvBits: &this->m_pBits,
                   hSection: nullptr,
                   offset: 0);
    if ( DIBSection != nullptr )
    {
      this->m_hBitmap = DIBSection;
      ATL::CImage::UpdateBitmapInfo(this, eOrientation: (ATL::CImage::DIBOrientation)((nHeight >= 0) + 1));
      if ( (dwFlags & 1) != 0 )
        this->m_bHasAlphaChannel = true;
      m_pHead = _AtlSafeAllocaManager.m_pHead;
      while ( m_pHead != nullptr )
      {
        v17 = m_pHead;
        m_pHead = m_pHead->m_pNext;
        free(pMem: v17);
      }
      return 1;
    }
    else
    {
      v14 = _AtlSafeAllocaManager.m_pHead;
      while ( v14 != nullptr )
      {
        v16 = v14;
        v14 = v14->m_pNext;
        free(pMem: v16);
      }
      return 0;
    }
  }
  else
  {
    v10 = _AtlSafeAllocaManager.m_pHead;
    while ( v10 != nullptr )
    {
      v18 = v10;
      v10 = v10->m_pNext;
      free(pMem: v18);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103732F5
// Name: public: virtual unsigned long CPreviewDC::SetBkColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
COLORREF __thiscall CPreviewDC::SetBkColor(CPreviewDC *this, COLORREF crColor)
{
  COLORREF NearestColor; // eax

  if ( this->m_hDC != nullptr )
  {
    NearestColor = GetNearestColor(hdc: this->m_hAttribDC, color: crColor);
    SetBkColor(hdc: this->m_hDC, color: NearestColor);
  }
  return SetBkColor(hdc: this->m_hAttribDC, color: crColor);
}

//------------------------------------------------------------------------------
// Address: 0x103B90B9
// Name: public: unsigned int Gdiplus::Image::GetWidth(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Gdiplus::Image::GetWidth(Gdiplus::Image *this)
{
  Gdiplus::Status ImageWidth; // eax
  unsigned int width; // [esp+4h] [ebp-4h] BYREF

  width = 0;
  ImageWidth = GdipGetImageWidth(a1: (int)this->nativeImage, a2: (int)&width);
  if ( ImageWidth != Ok )
    this->lastResult = ImageWidth;
  return width;
}

//------------------------------------------------------------------------------
// Address: 0x103B90DF
// Name: public: unsigned int Gdiplus::Image::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Gdiplus::Image::GetHeight(Gdiplus::Image *this)
{
  Gdiplus::Status ImageHeight; // eax
  unsigned int height; // [esp+4h] [ebp-4h] BYREF

  height = 0;
  ImageHeight = GdipGetImageHeight(a1: (int)this->nativeImage, a2: (int)&height);
  if ( ImageHeight != Ok )
    this->lastResult = ImageHeight;
  return height;
}

//------------------------------------------------------------------------------
// Address: 0x103B9105
// Name: public: int Gdiplus::Image::GetPixelFormat(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Gdiplus::Image::GetPixelFormat(Gdiplus::Image *this)
{
  Gdiplus::Status ImagePixelFormat; // eax
  int format; // [esp+4h] [ebp-4h] BYREF

  ImagePixelFormat = GdipGetImagePixelFormat(a1: (int)this->nativeImage, a2: (int)&format);
  if ( ImagePixelFormat != Ok )
    this->lastResult = ImagePixelFormat;
  return format;
}

//------------------------------------------------------------------------------
// Address: 0x103B9127
// Name: public: int Gdiplus::Image::GetPaletteSize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Gdiplus::Image::GetPaletteSize(Gdiplus::Image *this)
{
  Gdiplus::Status ImagePaletteSize; // eax
  int size; // [esp+4h] [ebp-4h] BYREF

  size = 0;
  ImagePaletteSize = GdipGetImagePaletteSize(a1: (int)this->nativeImage, a2: (int)&size);
  if ( ImagePaletteSize != Ok )
    this->lastResult = ImagePaletteSize;
  return size;
}

//------------------------------------------------------------------------------
// Address: 0x103B914D
// Name: public: enum Gdiplus::Status Gdiplus::Image::GetPalette(struct Gdiplus::ColorPalette __near *,int)
// Source: json
//------------------------------------------------------------------------------
Gdiplus::Status __thiscall Gdiplus::Image::GetPalette(Gdiplus::Image *this, Gdiplus::ColorPalette *palette, int size)
{
  Gdiplus::Status result; // eax

  result = GdipGetImagePalette(a1: (int)this->nativeImage, a2: (int)palette, a3: size);
  if ( result == Ok )
    return Ok;
  this->lastResult = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B91AE
// Name: public: void ATL::CImage::SetColorTable(unsigned int,unsigned int,struct tagRGBQUAD const __near *)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall ATL::CImage::SetColorTable(
        ATL::CImage *this,
        UINT iFirstColor,
        UINT nColors,
        const tagRGBQUAD *prgbColors)
{
  ATL::CImage::GetDC(this);
  SetDIBColorTable(hdc: this->m_hDC, iStart: iFirstColor, cEntries: nColors, prgbq: prgbColors);
  ATL::CImage::ReleaseDC(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BBED0
// Name: private: long ATL::CImage::CreateFromGdiplusBitmap(class Gdiplus::Bitmap __near &)
// Source: class_map
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CImage::CreateFromGdiplusBitmap(ATL::CImage *this, Gdiplus::Bitmap *bmSrc)
{
  int PixelFormat; // eax
  int v4; // edi
  int Width; // eax
  unsigned __int8 *PaletteSize; // eax
  unsigned int v8; // edi
  void *v9; // esp
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v10; // edi
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v11; // esi
  unsigned int v12; // eax
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v13; // esi
  int v14; // ecx
  unsigned int v15; // eax
  Gdiplus::Status m_nWidth; // eax
  Gdiplus::Status v17; // eax
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v18; // esi
  unsigned int v19; // edi
  char *m_pBits; // ebx
  unsigned int v21; // edi
  bool v22; // cc
  Gdiplus::Status lastResult; // esi
  int v24; // eax
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v25; // esi
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *m_pHead; // [esp-4h] [ebp-45Ch]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v27; // [esp-4h] [ebp-45Ch]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v28; // [esp-4h] [ebp-45Ch]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *v29; // [esp-4h] [ebp-45Ch]
  int v30; // [esp+0h] [ebp-458h] BYREF
  Gdiplus::BitmapData data; // [esp+Ch] [ebp-44Ch] BYREF
  Gdiplus::Bitmap bmDest; // [esp+24h] [ebp-434h] BYREF
  int eSrcPixelFormat; // [esp+34h] [ebp-424h]
  Gdiplus::Graphics gDest; // [esp+38h] [ebp-420h] BYREF
  unsigned int nBPP; // [esp+40h] [ebp-418h]
  unsigned int iColor; // [esp+44h] [ebp-414h]
  int y; // [esp+48h] [ebp-410h]
  unsigned __int8 *pbSrcRow; // [esp+4Ch] [ebp-40Ch]
  ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator> _AtlSafeAllocaManager; // [esp+50h] [ebp-408h] BYREF
  tagRGBQUAD argbPalette[256]; // [esp+54h] [ebp-404h] BYREF

  gDest.lastResult = (Gdiplus::Status)bmSrc;
  PixelFormat = Gdiplus::Image::GetPixelFormat(this: bmSrc);
  pbSrcRow = nullptr;
  v4 = PixelFormat;
  eSrcPixelFormat = PixelFormat;
  nBPP = 32;
  y = 139273;
  if ( (PixelFormat & 0x20000) != 0 )
  {
    nBPP = BYTE1(PixelFormat);
    y = PixelFormat;
  }
  if ( (PixelFormat & 0x40000) != 0 )
  {
    nBPP = 32;
    pbSrcRow = (unsigned __int8 *)1;
    y = 2498570;
  }
  iColor = Gdiplus::Image::GetHeight(this: bmSrc);
  Width = Gdiplus::Image::GetWidth(this: bmSrc);
  if ( ATL::CImage::CreateEx(
         this,
         nWidth: Width,
         nHeight: iColor,
         nBPP,
         eCompression: 0,
         pdwBitfields: nullptr,
         dwFlags: (char)pbSrcRow) == 0 )
    return -2147467259;
  _AtlSafeAllocaManager.m_pHead = nullptr;
  if ( (v4 & 0x10000) != 0 )
  {
    PaletteSize = (unsigned __int8 *)Gdiplus::Image::GetPaletteSize(this: bmSrc);
    v8 = (unsigned int)PaletteSize;
    pbSrcRow = PaletteSize;
    if ( (unsigned int)PaletteSize <= 0x400
      && ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(Size: (unsigned int)PaletteSize) != 0 )
    {
      v9 = alloca(v8);
      v10 = (ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::CAtlSafeAllocBufferNode *)&v30;
    }
    else
    {
      v10 = ATL::_ATL_SAFE_ALLOCA_IMPL::CAtlSafeAllocBufferManager<ATL::CCRTAllocator>::Allocate(
              this: &_AtlSafeAllocaManager,
              nRequestedSize: v8);
    }
    if ( v10 == nullptr )
    {
      if ( _AtlSafeAllocaManager.m_pHead != nullptr )
      {
        do
        {
          m_pHead = _AtlSafeAllocaManager.m_pHead;
          _AtlSafeAllocaManager.m_pHead = _AtlSafeAllocaManager.m_pHead->m_pNext;
          v11 = _AtlSafeAllocaManager.m_pHead;
          free(pMem: m_pHead);
        }
        while ( v11 != nullptr );
      }
      return -2147024882;
    }
    Gdiplus::Image::GetPalette(this: bmSrc, palette: (Gdiplus::ColorPalette *)v10, size: (int)pbSrcRow);
    v12 = *(_DWORD *)v10->_pad;
    if ( v12 == 0 || v12 > 0x100 )
    {
      if ( _AtlSafeAllocaManager.m_pHead != nullptr )
      {
        do
        {
          v27 = _AtlSafeAllocaManager.m_pHead;
          _AtlSafeAllocaManager.m_pHead = _AtlSafeAllocaManager.m_pHead->m_pNext;
          v13 = _AtlSafeAllocaManager.m_pHead;
          free(pMem: v27);
        }
        while ( v13 != nullptr );
      }
      return -2147467259;
    }
    iColor = 0;
    pbSrcRow = (unsigned __int8 *)&v10[1];
    do
    {
      v14 = *(_DWORD *)pbSrcRow;
      v15 = iColor;
      pbSrcRow += 4;
      argbPalette[iColor++].rgbRed = BYTE2(v14);
      argbPalette[v15].rgbGreen = BYTE1(v14);
      argbPalette[v15].rgbBlue = v14;
      argbPalette[v15].rgbReserved = 0;
    }
    while ( iColor < *(_DWORD *)v10->_pad );
    ATL::CImage::SetColorTable(this, iFirstColor: 0, nColors: *(_DWORD *)v10->_pad, prgbColors: argbPalette);
    v4 = eSrcPixelFormat;
  }
  if ( y == v4 )
  {
    m_nWidth = this->m_nWidth;
    bmDest.__vftable = nullptr;
    bmDest.nativeImage = nullptr;
    bmDest.lastResult = m_nWidth;
    bmDest.loadStatus = this->m_nHeight;
    v17 = GdipBitmapLockBits(a1: (int)bmSrc->nativeImage, a2: (int)&bmDest, a3: 1, a4: v4, a5: (int)&data);
    if ( v17 != Ok )
      bmSrc->lastResult = v17;
    else
      v17 = Ok;
    if ( v17 != Ok )
    {
      if ( _AtlSafeAllocaManager.m_pHead != nullptr )
      {
        do
        {
          v28 = _AtlSafeAllocaManager.m_pHead;
          _AtlSafeAllocaManager.m_pHead = _AtlSafeAllocaManager.m_pHead->m_pNext;
          v18 = _AtlSafeAllocaManager.m_pHead;
          free(pMem: v28);
        }
        while ( v18 != nullptr );
      }
      return -2147024882;
    }
    v19 = nBPP * this->m_nWidth;
    y = 0;
    m_pBits = (char *)this->m_pBits;
    v21 = (v19 + 7) >> 3;
    v22 = this->m_nHeight <= 0;
    pbSrcRow = (unsigned __int8 *)data.Scan0;
    if ( !v22 )
    {
      do
      {
        ATL::Checked::memcpy_s(_S1: m_pBits, _S1max: v21, _S2: pbSrcRow, _N: v21);
        pbSrcRow += data.Stride;
        m_pBits += this->m_nPitch;
        ++y;
      }
      while ( y < this->m_nHeight );
    }
    lastResult = gDest.lastResult;
    v24 = GdipBitmapUnlockBits(a1: *(_DWORD *)(gDest.lastResult + 4), a2: (int)&data);
    if ( v24 != 0 )
      *(_DWORD *)(lastResult + 8) = v24;
  }
  else
  {
    Gdiplus::Bitmap::Bitmap(
      this: &bmDest,
      width: this->m_nWidth,
      height: this->m_nHeight,
      stride: this->m_nPitch,
      format: y,
      scan0: (unsigned __int8 *)this->m_pBits);
    Gdiplus::Graphics::Graphics(this: &gDest, image: &bmDest);
    Gdiplus::Graphics::DrawImage(this: &gDest, image: bmSrc, x: 0, y: 0);
    GdipDeleteGraphics(a1: (int)gDest.nativeGraphics);
    GdipDisposeImage(a1: (int)bmDest.nativeImage);
  }
  if ( _AtlSafeAllocaManager.m_pHead != nullptr )
  {
    do
    {
      v29 = _AtlSafeAllocaManager.m_pHead;
      _AtlSafeAllocaManager.m_pHead = _AtlSafeAllocaManager.m_pHead->m_pNext;
      v25 = _AtlSafeAllocaManager.m_pHead;
      free(pMem: v29);
    }
    while ( v25 != nullptr );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BC262
// Name: public: long ATL::CImage::Load(struct IStream __near *)
// Source: class_map
//------------------------------------------------------------------------------
HRESULT __thiscall ATL::CImage::Load(ATL::CImage *this, IStream *pStream)
{
  int BitmapFromStream; // eax
  HRESULT v5; // esi
  Gdiplus::Bitmap bmSrc; // [esp+4h] [ebp-14h] BYREF
  Gdiplus::GpImage *v7; // [esp+14h] [ebp-4h] BYREF

  if ( !ATL::CImage::CInitGDIPlus::Init(this: &ATL::CImage::s_initGDIPlus) )
    return -2147467259;
  v7 = nullptr;
  bmSrc.__vftable = (Gdiplus::Bitmap_vtbl *)&Gdiplus::Bitmap::`vftable';
  BitmapFromStream = GdipCreateBitmapFromStream(a1: (int)pStream, a2: (int)&v7);
  bmSrc.lastResult = Ok;
  bmSrc.nativeImage = v7;
  if ( BitmapFromStream != 0 )
  {
    GdipDisposeImage(a1: (int)v7);
    return -2147467259;
  }
  v5 = ATL::CImage::CreateFromGdiplusBitmap(this, &bmSrc);
  GdipDisposeImage(a1: (int)bmSrc.nativeImage);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x105C59A7
// Name: _dynamic_initializer_for__ATL::CImage::s_initGDIPlus__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__ATL::CImage::s_initGDIPlus__()
{
  ATL::CImage::CInitGDIPlus::CInitGDIPlus(this: &ATL::CImage::s_initGDIPlus);
  return atexit(func: dynamic_atexit_destructor_for__ATL::CImage::s_initGDIPlus__);
}

//------------------------------------------------------------------------------
// Address: 0x105C59BD
// Name: _dynamic_initializer_for__ATL::CImage::s_cache__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__ATL::CImage::s_cache__()
{
  ATL::CImage::s_cache.m_ahDCs[0] = nullptr;
  ATL::CImage::s_cache.m_ahDCs[1] = nullptr;
  ATL::CImage::s_cache.m_ahDCs[2] = nullptr;
  ATL::CImage::s_cache.m_ahDCs[3] = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__ATL::CImage::s_cache__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC89B
// Name: _dynamic_atexit_destructor_for__ATL::CImage::s_initGDIPlus__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ATL::CImage::s_initGDIPlus__()
{
  ATL::CImage::CInitGDIPlus::ReleaseGDIPlus(this: &ATL::CImage::s_initGDIPlus);
  DeleteCriticalSection(lpCriticalSection: &ATL::CImage::s_initGDIPlus.m_sect);
}

//------------------------------------------------------------------------------
// Address: 0x105CC8B1
// Name: _dynamic_atexit_destructor_for__ATL::CImage::s_cache__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ATL::CImage::s_cache__()
{
  ATL::CImage::CDCCache::~CDCCache(this: &ATL::CImage::s_cache);
}

//------------------------------------------------------------------------------
// Address: 0x102EB5E0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10360C0F
// Name: public: struct HBITMAP__ __near * ATL::CImage::Detach(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBITMAP__ *__thiscall ATL::CImage::Detach(ATL::CImage *this)
{
  HBITMAP__ *result; // eax

  result = this->m_hBitmap;
  this->m_iTransparentColor = -1;
  this->m_clrTransparentColor = -1;
  this->m_hBitmap = nullptr;
  this->m_pBits = nullptr;
  this->m_nWidth = 0;
  this->m_nHeight = 0;
  this->m_nBPP = 0;
  this->m_nPitch = 0;
  *(_WORD *)&this->m_bIsDIBSection = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10360C33
// Name: public: struct HDC__ __near * ATL::CImage::GetDC(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HDC__ *__thiscall ATL::CImage::GetDC(ATL::CImage *this)
{
  HDC__ *DC; // eax
  HBITMAP__ *m_hBitmap; // [esp-4h] [ebp-8h]

  ++this->m_nDCRefCount;
  if ( this->m_hDC == nullptr )
  {
    DC = ATL::CImage::CDCCache::GetDC(this: &ATL::CImage::s_cache);
    m_hBitmap = this->m_hBitmap;
    this->m_hDC = DC;
    this->m_hOldBitmap = (HBITMAP__ *)SelectObject(hdc: DC, h: m_hBitmap);
  }
  return this->m_hDC;
}

//------------------------------------------------------------------------------
// Address: 0x10360D50
// Name: public: static class CMFCVisualManager __near * CMFCVisualManager::GetInstance(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCVisualManager *__stdcall CMFCVisualManager::GetInstance()
{
  CMFCVisualManager *result; // eax
  CMFCVisualManager *v1; // ecx
  CMFCVisualManager *Object; // eax

  result = CMFCVisualManager::m_pVisManager;
  if ( CMFCVisualManager::m_pVisManager == nullptr )
  {
    if ( CMFCVisualManager::m_pRTIDefault != nullptr )
    {
      Object = (CMFCVisualManager *)CRuntimeClass::CreateObject(this: CMFCVisualManager::m_pRTIDefault);
    }
    else
    {
      v1 = (CMFCVisualManager *)operator new(nSize: 0xD4u);
      if ( v1 != nullptr )
        Object = CMFCVisualManager::CMFCVisualManager(this: v1, bIsTemporary: 0);
      else
        Object = nullptr;
    }
    CMFCVisualManager::m_pVisManager = Object;
    Object->m_bAutoDestroy = 1;
    CMFCVisualManager::m_pVisManager->OnUpdateSystemColors(this: CMFCVisualManager::m_pVisManager);
    return CMFCVisualManager::m_pVisManager;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10360DC2
// Name: protected: int CFrameImpl::IsOwnerDrawCaption(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameImpl::IsOwnerDrawCaption(CFrameImpl *this)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  return Instance->IsOwnerDrawCaption(this: Instance) != 0 && this->m_bIsOleInPlaceActive == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10360DE9
// Name: public: virtual struct CRuntimeClass __near * CMDIChildWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMDIChildWndEx::GetRuntimeClass(CMDIChildWndEx *this)
{
  return &CMDIChildWndEx::classCMDIChildWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x10360DEF
// Name: protected: long CMDIChildWndEx::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnSetText(CMDIChildWndEx *this, unsigned int __formal, const char *lParam)
{
  int v4; // edi
  CMDIFrameWndEx *m_pMDIFrame; // eax

  v4 = CWnd::Default(this);
  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr )
    CMDIClientAreaWnd::UpdateTabs(this: &m_pMDIFrame->m_wndClientArea, bSetActiveTabVisible: 1);
  CFrameImpl::OnSetText(this: &this->m_Impl, __formal: lParam);
  this->SetTaskbarTabText(this, a2: lParam);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10360E39
// Name: protected: long CMDIChildWndEx::OnSetIcon(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnSetIcon(CMDIChildWndEx *this, unsigned int __formal, unsigned int __formala)
{
  int v4; // edi
  CMDIFrameWndEx *m_pMDIFrame; // eax

  v4 = CWnd::Default(this);
  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr )
    CMDIClientAreaWnd::UpdateTabs(this: &m_pMDIFrame->m_wndClientArea, bSetActiveTabVisible: 0);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10360E64
// Name: protected: virtual int CMDIChildWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::PreCreateWindow(CMDIChildWndEx *this, tagCREATESTRUCTA *cs)
{
  CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
  return CMDIChildWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x10360E87
// Name: public: int CMDIChildWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::AddPane(CMDIChildWndEx *this, CBasePane *pControlBar, int bTail)
{
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10360EA5
// Name: public: int CMDIChildWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::InsertPane(CMDIChildWndEx *this, CBasePane *pControlBar, CBasePane *pTarget, int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x10360EB6
// Name: public: void CMDIChildWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::RemovePaneFromDockManager(
        CMDIChildWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
}

//------------------------------------------------------------------------------
// Address: 0x10360EC7
// Name: public: void CMDIChildWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::DockPane(
        CMDIChildWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *__formal)
{
  if ( pBar->CanFloat(this: pBar) != 0 && CMDIChildWndEx::m_bEnableFloatingBars == 0 )
    pBar->m_dwControlBarStyle &= ~1u;
  if ( pBar->CanBeResized(this: pBar) != 0 || pBar->CanFloat(this: pBar) != 0 )
  {
    pBar->EnableDocking(this: pBar, a2: 61440u);
    CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect: nullptr);
  }
  else
  {
    CMDIChildWndEx::AddPane(this, pControlBar: pBar, bTail: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10360F3F
// Name: public: class CBasePane __near * CMDIChildWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall CMDIChildWndEx::PaneFromPoint(
        CMDIChildWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10360F66
// Name: public: int CMDIChildWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::IsPointNearDockSite(
        CMDIChildWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x10360F86
// Name: public: virtual int CMDIChildWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnMoveMiniFrame(CMDIChildWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x103611F0
// Name: public: int CDockingManager::IsOLEContainerMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDockingManager::IsOLEContainerMode(CDockingManager *this)
{
  CFrameWnd *m_pParentWnd; // eax

  m_pParentWnd = this->m_pParentWnd;
  return m_pParentWnd != nullptr && m_pParentWnd->m_hWnd != nullptr && m_pParentWnd->m_pNotifyHook != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10361211
// Name: protected: CMDIChildWndEx::CMDIChildWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDIChildWndEx *__thiscall CMDIChildWndEx::CMDIChildWndEx(CMDIChildWndEx *this)
{
  CMDIChildWnd::CMDIChildWnd(this);
  this->__vftable = (CMDIChildWndEx_vtbl *)&CMDIChildWndEx::`vftable';
  this->m_rectOriginal.left = 0;
  this->m_rectOriginal.top = 0;
  this->m_rectOriginal.right = 0;
  this->m_rectOriginal.bottom = 0;
  CFrameImpl::CFrameImpl(this: &this->m_Impl, pFrame: this);
  CDockingManager::CDockingManager(this: &this->m_dockManager);
  CMDITabProxyWnd::CMDITabProxyWnd(this: &this->m_tabProxyWnd);
  this->m_pMDIFrame = nullptr;
  this->m_bToBeDestroyed = 0;
  this->m_bWasMaximized = 0;
  this->m_bIsMinimized = 0;
  SetRectEmpty(lprc: &this->m_rectOriginal);
  this->m_bActivating = 0;
  this->m_bInOnCreate = 0;
  this->m_pRelatedTabGroup = nullptr;
  this->m_pTabbedControlBar = nullptr;
  this->m_bTabRegistered = 0;
  this->m_bEnableTaskbarThumbnailClip = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103612BC
// Name: public: virtual int CMDIChildWndEx::CanShowOnMDITabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::CanShowOnMDITabs(CMDIChildWndEx *this)
{
  return (CWnd::GetStyle(this) & 0x10000000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103612C8
// Name: protected: virtual CMDIChildWndEx::~CMDIChildWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::~CMDIChildWndEx(CMDIChildWndEx *this)
{
  CMDITabProxyWnd *p_m_tabProxyWnd; // ecx

  this->__vftable = (CMDIChildWndEx_vtbl *)&CMDIChildWndEx::`vftable';
  p_m_tabProxyWnd = &this->m_tabProxyWnd;
  p_m_tabProxyWnd->__vftable = (CMDITabProxyWnd_vtbl *)&CMDITabProxyWnd::`vftable';
  CWnd::~CWnd(this: p_m_tabProxyWnd);
  CDockingManager::~CDockingManager(this: &this->m_dockManager);
  CFrameImpl::~CFrameImpl(this: &this->m_Impl);
  CFrameWnd::~CFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10361326
// Name: public: virtual int CMDIChildWndEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::PreTranslateMessage(CMDIChildWndEx *this, tagMSG *pMsg)
{
  unsigned int message; // ecx
  HWND Capture; // eax
  CWnd *v6; // eax
  CMFCTabCtrl *m_pRelatedTabGroup; // esi

  message = pMsg->message;
  if ( message >= 0x100
    && message <= 0x109
    && this->m_pMDIFrame != nullptr
    && CMFCPopupMenu::m_pActivePopupMenu != nullptr )
  {
    return false;
  }
  if ( message == 256 && pMsg->wParam == 27 && this->m_pRelatedTabGroup != nullptr )
  {
    Capture = GetCapture();
    v6 = CWnd::FromHandle(hWnd: Capture);
    m_pRelatedTabGroup = this->m_pRelatedTabGroup;
    if ( v6 == m_pRelatedTabGroup )
      PostMessageA(hWnd: m_pRelatedTabGroup->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
  }
  return CMDIChildWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x103613A4
// Name: protected: int CMDIChildWndEx::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnCreate(CMDIChildWndEx *this, tagCREATESTRUCTA *lpCreateStruct)
{
  tagCREATESTRUCTA *v2; // esi
  CMDIFrameWnd *MDIFrame; // eax
  HWND Parent; // eax
  CWnd *v6; // eax
  int x; // eax
  int cx; // ecx
  int cy; // edx
  CMDIFrameWndEx *m_pMDIFrame; // eax
  HWND v11; // eax
  CWnd *v12; // eax
  int result; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-4Ch]
  HWND__ *v15; // [esp-8h] [ebp-4Ch]
  CRect rectClient; // [esp+10h] [ebp-34h] BYREF
  CRect rectScreen; // [esp+20h] [ebp-24h] BYREF
  CRect rect; // [esp+30h] [ebp-14h] BYREF

  v2 = lpCreateStruct;
  MDIFrame = CMDIChildWnd::GetMDIFrame(this);
  this->m_pMDIFrame = (CMDIFrameWndEx *)AfxDynamicDownCast(
                                          pClass: &CMDIFrameWndEx::classCMDIFrameWndEx,
                                          pObject: MDIFrame);
  this->m_Impl.m_bHasBorder = (lpCreateStruct->style & 0x800000) != 0;
  this->m_bInOnCreate = 1;
  if ( (CWnd::GetStyle(this) & 0x80000) == 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v6 = CWnd::FromHandle(hWnd: Parent);
    SendMessageA(hWnd: v6->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    x = lpCreateStruct->x;
    cx = lpCreateStruct->cx;
    cy = lpCreateStruct->cy;
    rectScreen.top = lpCreateStruct->y;
    rectScreen.left = x;
    rectScreen.bottom = cy + rectScreen.top;
    rectScreen.right = cx + x;
    m_pMDIFrame = this->m_pMDIFrame;
    this->m_rectOriginal = rectScreen;
    if ( m_pMDIFrame != nullptr && m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup == 0 )
    {
      memset(&rect, 0, sizeof(rect));
      GetClientRect(hWnd: m_pMDIFrame->m_wndClientArea.m_hWnd, lpRect: &rect);
      m_hWnd = this->m_hWnd;
      memset(&rectClient, 0, sizeof(rectClient));
      GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
      CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rectClient);
      v15 = this->m_hWnd;
      memset(&rectScreen, 0, sizeof(rectScreen));
      GetWindowRect(hWnd: v15, lpRect: &rectScreen);
      rect.left += rectScreen.left - rectClient.left;
      rect.top += rectScreen.top - rectClient.top;
      rect.bottom += rectScreen.bottom - rectClient.bottom;
      rect.right += rectScreen.right - rectClient.right;
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: nullptr,
        x: rect.left,
        y: rect.top,
        cx: rect.right - rect.left,
        cy: rect.bottom - rect.top,
        nFlags: 0x14u);
    }
    v11 = GetParent(hWnd: this->m_hWnd);
    v12 = CWnd::FromHandle(hWnd: v11);
    SendMessageA(hWnd: v12->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    v2 = lpCreateStruct;
  }
  result = CMDIChildWnd::OnCreate(this, lpCreateStruct: v2);
  if ( result != -1 )
  {
    if ( CFrameImpl::IsPrintPreview(this: &this->m_pMDIFrame->m_Impl) )
      SendMessageA(hWnd: this->m_pMDIFrame->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    CFrameImpl::AddFrame(pFrame: this);
    this->RegisterTaskbarTab(this, a2: nullptr);
    PostMessageA(hWnd: this->m_hWnd, Msg: AFX_WM_CHANGEVISUALMANAGER, wParam: 0, lParam: 0);
    result = 0;
  }
  this->m_bInOnCreate = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036159A
// Name: public: int CMDIChildWndEx::IsRegisteredWithTaskbarTabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::IsRegisteredWithTaskbarTabs(CMDIChildWndEx *this)
{
  void *p_m_tabProxyWnd; // eax

  p_m_tabProxyWnd = &this->m_tabProxyWnd;
  if ( this != (CMDIChildWndEx *)-1084 )
    p_m_tabProxyWnd = this->m_tabProxyWnd.m_hWnd;
  return p_m_tabProxyWnd != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103615B1
// Name: public: int CMDIChildWndEx::IsTaskbarTabsSupportEnabled(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::IsTaskbarTabsSupportEnabled(CMDIChildWndEx *this)
{
  CFrameWnd *TopLevelFrame; // eax
  CWinApp *m_pCurrentWinApp; // eax
  BOOL result; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  result = false;
  if ( AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame) != nullptr )
  {
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp != nullptr
      && m_pCurrentWinApp->IsTaskbarInteractionEnabled(this: m_pCurrentWinApp) != 0
      && this->CanShowOnTaskBarTabs(this) != 0
      && afxGlobalData.bIsWindows7 != 0
      && (CWnd::GetStyle(this) & 0x80000) == 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10361614
// Name: public: int CMDIChildWndEx::InvalidateIconicBitmaps(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::InvalidateIconicBitmaps(CMDIChildWndEx *this)
{
  CRect *v2; // eax
  HMODULE ModuleHandleA; // eax
  HRESULT (__stdcall *DwmInvalidateIconicBitmaps)(HWND); // eax
  CMDITabProxyWnd *p_m_tabProxyWnd; // ebx
  int rectThumbnailClip; // [esp+Ch] [ebp-24h]
  int rectThumbnailClip_4; // [esp+10h] [ebp-20h]
  int rectThumbnailClip_8; // [esp+14h] [ebp-1Ch]
  int rectThumbnailClip_12; // [esp+18h] [ebp-18h]
  _BYTE v11[16]; // [esp+1Ch] [ebp-14h] BYREF

  if ( !CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) || !CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this) )
    return 0;
  rectThumbnailClip = 0;
  rectThumbnailClip_4 = 0;
  rectThumbnailClip_8 = 0;
  rectThumbnailClip_12 = 0;
  if ( this->m_bEnableTaskbarThumbnailClip != 0 )
  {
    v2 = this->GetTaskbarThumbnailClipRect(this, result: v11);
    rectThumbnailClip = v2->left;
    rectThumbnailClip_4 = v2->top;
    rectThumbnailClip_8 = v2->right;
    rectThumbnailClip_12 = v2->bottom;
  }
  ((void (__thiscall *)(CMDIChildWndEx *, int, int, int, int))this->SetTaskbarThumbnailClipRect)(
    a1: this,
    a2: rectThumbnailClip,
    a3: rectThumbnailClip_4,
    a4: rectThumbnailClip_8,
    a5: rectThumbnailClip_12);
  ModuleHandleA = GetModuleHandleA(lpModuleName: "DWMAPI");
  if ( ModuleHandleA != nullptr )
  {
    DwmInvalidateIconicBitmaps = (HRESULT (__stdcall *)(HWND))GetProcAddress(
                                                                hModule: ModuleHandleA,
                                                                lpProcName: "DwmInvalidateIconicBitmaps");
    if ( DwmInvalidateIconicBitmaps != nullptr )
    {
      p_m_tabProxyWnd = &this->m_tabProxyWnd;
      if ( p_m_tabProxyWnd != nullptr )
        p_m_tabProxyWnd = (CMDITabProxyWnd *)p_m_tabProxyWnd->m_hWnd;
      DwmInvalidateIconicBitmaps(hwnd: (HWND)p_m_tabProxyWnd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103616C9
// Name: public: virtual void CMDIChildWndEx::UpdateTaskbarTabIcon(struct HICON__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::UpdateTaskbarTabIcon(CMDIChildWndEx *this, HICON__ *hIcon)
{
  if ( this != (CMDIChildWndEx *)-1084 && this->m_tabProxyWnd.m_hWnd != nullptr )
    SendMessageA(hWnd: this->m_tabProxyWnd.m_hWnd, Msg: 0x80u, wParam: 0, lParam: (LPARAM)hIcon);
}

//------------------------------------------------------------------------------
// Address: 0x103616F8
// Name: public: void CMDIChildWndEx::SetTaskbarTabOrder(class CMDIChildWndEx __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::SetTaskbarTabOrder(CMDIChildWndEx *this, CMDIChildWndEx *pWndBefore)
{
  CMDITabProxyWnd *p_m_tabProxyWnd; // esi
  ITaskbarList3 *ITaskbarList3; // eax
  HWND__ *m_hWnd; // ecx

  if ( CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) && CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this) )
  {
    p_m_tabProxyWnd = &this->m_tabProxyWnd;
    if ( p_m_tabProxyWnd != nullptr && p_m_tabProxyWnd->m_hWnd != nullptr )
    {
      ITaskbarList3 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
      if ( pWndBefore == nullptr || pWndBefore == (CMDIChildWndEx *)-1084 )
        m_hWnd = nullptr;
      else
        m_hWnd = pWndBefore->m_tabProxyWnd.m_hWnd;
      if ( ITaskbarList3 != nullptr )
        ITaskbarList3->SetTabOrder(this: ITaskbarList3, a2: p_m_tabProxyWnd->m_hWnd, a3: m_hWnd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10361756
// Name: public: void CMDIChildWndEx::SetTaskbarTabActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::SetTaskbarTabActive(CMDIChildWndEx *this)
{
  ITaskbarList3 *ITaskbarList3; // edi
  CFrameWnd *TopLevelFrame; // eax
  CObject *v4; // eax
  CObject_vtbl *v5; // ecx
  HWND__ *p_m_tabProxyWnd; // eax

  if ( CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) )
  {
    ITaskbarList3 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
    if ( ITaskbarList3 != nullptr )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
      v4 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
      if ( v4 != nullptr )
        v5 = v4[8].__vftable;
      else
        v5 = nullptr;
      p_m_tabProxyWnd = (HWND__ *)&this->m_tabProxyWnd;
      if ( this != (CMDIChildWndEx *)-1084 )
        p_m_tabProxyWnd = this->m_tabProxyWnd.m_hWnd;
      ITaskbarList3->SetTabActive(this: ITaskbarList3, a2: p_m_tabProxyWnd, a3: (HWND__ *)v5, a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103617AE
// Name: protected: void CMDIChildWndEx::OnMDIActivate(int,class CWnd __near *,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnMDIActivate(
        CMDIChildWndEx *this,
        int bActivate,
        CWnd *pActivateWnd,
        CWnd *pDeactivateWnd)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax
  HWND__ *m_hWnd; // esi
  CWinApp *m_pCurrentWinApp; // eax
  int v8; // eax
  CMDIChildWndEx *v9; // eax
  CMDIFrameWndEx *v10; // eax
  CDockingManager *p_m_dockManager; // esi

  this->m_dockManager.OnActivateFrame(this: &this->m_dockManager, a2: bActivate);
  this->m_bActivating = bActivate;
  if ( bActivating == 0 )
  {
    bActivating = 1;
    CMDIChildWnd::OnMDIActivate(this, bActivate, pActivateWnd, __formal: pDeactivateWnd);
    if ( bActivate != 0 )
    {
      m_pMDIFrame = this->m_pMDIFrame;
      if ( m_pMDIFrame != nullptr )
      {
        if ( pActivateWnd != nullptr )
          m_hWnd = pActivateWnd->m_hWnd;
        else
          m_hWnd = nullptr;
        CMDIClientAreaWnd::SetActiveTab(this: &m_pMDIFrame->m_wndClientArea, hwnd: m_hWnd);
      }
    }
    if ( CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) && CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this) )
    {
      m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
      if ( m_pCurrentWinApp != nullptr )
      {
        v8 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp);
        if ( v8 == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 48))(a1: v8) == 0 )
        {
          CMDIChildWndEx::InvalidateIconicBitmaps(this);
          v9 = (CMDIChildWndEx *)AfxDynamicDownCast(
                                   pClass: &CMDIChildWndEx::classCMDIChildWndEx,
                                   pObject: pDeactivateWnd);
          if ( v9 != nullptr )
            CMDIChildWndEx::InvalidateIconicBitmaps(this: v9);
          CMDIChildWndEx::SetTaskbarTabActive(this);
        }
      }
    }
    bActivating = 0;
    if ( bActivate == 0 )
    {
LABEL_24:
      if ( CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this) )
        return;
      goto LABEL_25;
    }
    v10 = this->m_pMDIFrame;
    if ( v10 != nullptr )
    {
      if ( (p_m_dockManager = &v10->m_dockManager, v10 != (CMDIFrameWndEx *)-332)
        && CDockingManager::IsOLEContainerMode(this: &v10->m_dockManager)
        || CDockingManager::IsOLEContainerMode(this: &this->m_dockManager) )
      {
        CGlobalUtils::ForceAdjustLayout(
          this: &afxGlobalUtils,
          pDockManager: p_m_dockManager,
          bForce: 1,
          bForceInvisible: 0);
      }
    }
  }
  if ( bActivate == 0 || CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) )
    goto LABEL_24;
LABEL_25:
  ((void (__thiscall *)(CMDIChildWndEx *, _DWORD, _DWORD, _DWORD, _DWORD))this->SetTaskbarThumbnailClipRect)(
    a1: this,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1036190D
// Name: public: virtual void CMDIChildWndEx::ActivateFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::ActivateFrame(CMDIChildWndEx *this, int nCmdShow)
{
  HWND Parent; // eax
  CWnd *v4; // eax
  CWnd *v5; // esi
  HWND m_hWnd; // eax
  CMDIFrameWndEx *m_pMDIFrame; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = v4;
  if ( CMDIFrameWndEx::m_bDisableSetRedraw == 0 && v4 != nullptr && (m_hWnd = v4->m_hWnd) != nullptr )
  {
    SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    CMDIChildWnd::ActivateFrame(this, nCmdShow);
    SendMessageA(hWnd: v5->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    RedrawWindow(hWnd: v5->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
  }
  else
  {
    if ( (CWnd::GetStyle(this) & 0x80000) == 0 )
      nCmdShow = 3;
    m_pMDIFrame = this->m_pMDIFrame;
    if ( m_pMDIFrame != nullptr && m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup != 0 )
      nCmdShow = 1;
    CMDIChildWnd::ActivateFrame(this, nCmdShow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103619B4
// Name: public: virtual struct HICON__ __near * CMDIChildWndEx::GetFrameIcon(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall CMDIChildWndEx::GetFrameIcon(CMDIChildWndEx *this)
{
  HICON__ *result; // eax

  result = (HICON__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x7Fu, wParam: 0, lParam: 0);
  if ( result == nullptr )
    return (HICON__ *)GetClassLongA(hWnd: this->m_hWnd, nIndex: -34);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103619DA
// Name: protected: void CMDIChildWndEx::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnSize(CMDIChildWndEx *this, unsigned int nType, int cx, int cy)
{
  CMFCVisualManager *Instance; // eax
  CMDIFrameWndEx *m_pMDIFrame; // eax
  CFrameWnd *ParentFrame; // eax
  CMDIFrameWndEx *v8; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-48h]
  HWND__ *v10; // [esp-Ch] [ebp-44h]
  tagWINDOWPOS wndpos; // [esp+8h] [ebp-30h] BYREF
  CRect rectWindow; // [esp+24h] [ebp-14h] BYREF

  if ( this->m_bToBeDestroyed == 0 )
  {
    CMDIChildWndEx::InvalidateIconicBitmaps(this);
    this->m_bIsMinimized = nType == 1;
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsOwnerDrawCaption(this: Instance) != 0 )
    {
      m_pMDIFrame = this->m_pMDIFrame;
      if ( m_pMDIFrame == nullptr || m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup != 0 )
      {
        if ( this->m_Impl.m_bIsWindowRgn != 0 )
        {
          m_hWnd = this->m_hWnd;
          this->m_Impl.m_bIsWindowRgn = 0;
          SetWindowRgn(hWnd: m_hWnd, hRgn: nullptr, bRedraw: true);
        }
      }
      else
      {
        v10 = this->m_hWnd;
        memset(&rectWindow, 0, sizeof(rectWindow));
        GetWindowRect(hWnd: v10, lpRect: &rectWindow);
        wndpos.x = rectWindow.left;
        wndpos.cy = rectWindow.bottom - rectWindow.top;
        wndpos.y = rectWindow.top;
        wndpos.flags = 32;
        wndpos.cx = rectWindow.right - rectWindow.left;
        CFrameImpl::OnWindowPosChanging(this: &this->m_Impl, lpwndpos: &wndpos);
      }
    }
    if ( this->m_bIsMinimized != 0 || nType == 2 || this->m_bWasMaximized != 0 )
    {
      CMDIChildWnd::OnSize(this, nType, cx, cy);
      if ( nType == 2 || nType == 0 && this->m_bWasMaximized != 0 )
      {
        this->RecalcLayout(this, a2: 1);
        if ( this->m_pNotifyHook != nullptr && nType == 0 )
        {
          ParentFrame = CWnd::GetParentFrame(this);
          v8 = (CMDIFrameWndEx *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: ParentFrame);
          if ( v8 == nullptr || !CMDIFrameWndEx::AreMDITabs(this: v8, pnMDITabsType: nullptr) )
            CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0xCF0000u, nFlags: 0);
        }
      }
      this->m_bWasMaximized = nType == 2;
    }
    else
    {
      this->m_dockManager.m_bSizeFrame = 1;
      CMDIChildWnd::OnSize(this, nType, cx, cy);
      this->AdjustDockingLayout(this, a2: nullptr);
      this->m_dockManager.m_bSizeFrame = 0;
    }
    CFrameImpl::UpdateCaption(this: &this->m_Impl);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10361B77
// Name: public: virtual void CMDIChildWndEx::OnSetPreviewMode(int,struct CPrintPreviewState __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnSetPreviewMode(CMDIChildWndEx *this, HWND__ *bPreview, CPrintPreviewState *pState)
{
  CWnd *MainWnd; // eax
  CObject *v5; // eax
  unsigned int dwStates; // ebx

  MainWnd = AfxGetMainWnd();
  v5 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: MainWnd);
  if ( v5 != nullptr )
    v5[82].__vftable = bPreview != nullptr ? (CObject_vtbl *)this : nullptr;
  CDockingManager::SetPrintPreviewMode(this: &this->m_dockManager, (int)bPreview, __formal: pState);
  dwStates = pState->dwStates;
  CFrameWnd::OnSetPreviewMode(this, bPreview, pState);
  pState->dwStates = dwStates;
  this->AdjustDockingLayout(this, a2: nullptr);
  this->RecalcLayout(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10361BE8
// Name: protected: void CMDIChildWndEx::AdjustClientArea(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::AdjustClientArea(CMDIChildWndEx *this)
{
  HWND Parent; // eax
  CDockablePane *m_pTabbedControlBar; // esi
  CWnd *pChildWnd; // [esp+1Ch] [ebp-4h]

  if ( this->m_pTabbedControlBar != nullptr
    && this->m_pTabbedControlBar->IsMDITabbed(this: (CBasePane *)this->m_pTabbedControlBar) != 0
    && (Parent = GetParent(hWnd: this->m_pTabbedControlBar->m_hWnd), CWnd::FromHandle(hWnd: Parent) == this) )
  {
    m_pTabbedControlBar = this->m_pTabbedControlBar;
    pChildWnd = &m_pTabbedControlBar->CPane;
  }
  else
  {
    pChildWnd = CWnd::GetDlgItem(this, nID: 59648);
    m_pTabbedControlBar = (CDockablePane *)pChildWnd;
  }
  if ( m_pTabbedControlBar != nullptr )
  {
    if ( CObject::IsKindOf(this: &m_pTabbedControlBar->CPane, pClass: &CSplitterWnd::classCSplitterWnd) != 0
      || CObject::IsKindOf(this: &m_pTabbedControlBar->CPane, pClass: &CFormView::classCFormView) != 0 )
    {
      CWnd::ModifyStyle(this: &m_pTabbedControlBar->CPane, dwRemove: 0, dwAdd: 0x4000000u, nFlags: 0);
    }
    else
    {
      CWnd::ModifyStyle(this: &m_pTabbedControlBar->CPane, dwRemove: 0, dwAdd: 0x6000000u, nFlags: 0);
    }
    if ( this->m_bInOnCreate == 0 && CDockingManager::m_bFullScreenMode == 0 )
      CWnd::SetWindowPos(
        this: pChildWnd,
        pWndInsertAfter: &CWnd::wndBottom,
        x: this->m_rectBorder.left + this->m_dockManager.m_rectClientAreaBounds.left,
        y: this->m_rectBorder.top + this->m_dockManager.m_rectClientAreaBounds.top,
        cx: this->m_dockManager.m_rectClientAreaBounds.right
      - this->m_rectBorder.right
      - (this->m_rectBorder.left
       + this->m_dockManager.m_rectClientAreaBounds.left),
        cy: this->m_dockManager.m_rectClientAreaBounds.bottom
      - this->m_rectBorder.bottom
      - (this->m_rectBorder.top
       + this->m_dockManager.m_rectClientAreaBounds.top),
        nFlags: 0x10u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10361CE1
// Name: public: virtual void CMDIChildWndEx::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::RecalcLayout(CMDIChildWndEx *this, int bNotify)
{
  CView *ActiveView; // edi
  CFrameWnd *ParentFrame; // eax
  CObject *v5; // eax
  int v6; // eax
  CFrameWnd *v7; // eax
  CView *pView; // [esp+8h] [ebp-18h]
  CRect rectClient; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_bInRecalcLayout == 0 )
  {
    this->m_bInRecalcLayout = 1;
    if ( this->m_bIsMinimized == 0 )
    {
      pView = CFrameWnd::GetActiveView(this);
      if ( this->m_dockManager.m_bIsPrintPreviewMode != 0
        || CDockingManager::IsOLEContainerMode(this: &this->m_dockManager) )
      {
        if ( pView != nullptr && CObject::IsKindOf(this: pView, pClass: &CPreviewViewEx::classCPreviewViewEx) != 0 )
        {
          this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: bNotify);
          CWnd::SetWindowPos(
            this: pView,
            pWndInsertAfter: nullptr,
            x: this->m_dockManager.m_rectClientAreaBounds.left,
            y: this->m_dockManager.m_rectClientAreaBounds.top,
            cx: this->m_dockManager.m_rectClientAreaBounds.right - this->m_dockManager.m_rectClientAreaBounds.left,
            cy: this->m_dockManager.m_rectClientAreaBounds.bottom - this->m_dockManager.m_rectClientAreaBounds.top,
            nFlags: 0x14u);
          goto LABEL_7;
        }
        ActiveView = CFrameWnd::GetActiveView(this);
        if ( ActiveView != nullptr )
        {
          ParentFrame = CWnd::GetParentFrame(this);
          if ( ParentFrame->GetActiveFrame(this: ParentFrame) == this && this->m_bActivating != 0 )
          {
            v5 = AfxDynamicDownCast(pClass: &COleDocument::classCOleDocument, pObject: ActiveView->m_pDocument);
            if ( v5 != nullptr )
            {
              v6 = ((int (__thiscall *)(CObject *, CView *))v5->__vftable[22].Serialize)(a1: v5, a2: ActiveView);
              if ( bNotify != 0 && v6 != 0 && *(_DWORD *)(v6 + 96) != 0 )
                (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v6 + 96) + 80))(a1: *(_DWORD *)(v6 + 96));
            }
            memset(&rectClient, 0, sizeof(rectClient));
            v7 = CWnd::GetParentFrame(this: ActiveView);
            if ( v7 != nullptr )
            {
              GetClientRect(hWnd: v7->m_hWnd, lpRect: &rectClient);
              CWnd::SetWindowPos(
                this: ActiveView,
                pWndInsertAfter: nullptr,
                x: 0,
                y: 0,
                cx: rectClient.right - rectClient.left,
                cy: rectClient.bottom - rectClient.top,
                nFlags: 0x14u);
            }
            goto LABEL_7;
          }
        }
      }
      else
      {
        this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: bNotify);
      }
      CMDIChildWndEx::AdjustClientArea(this);
    }
LABEL_7:
    this->m_bInRecalcLayout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10361E66
// Name: protected: void CMDIChildWndEx::OnSizing(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnSizing(CMDIChildWndEx *this, unsigned int fwSide, tagRECT *pRect)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  tagRECT rcDst; // [esp+Ch] [ebp-24h] BYREF
  CRect rect; // [esp+1Ch] [ebp-14h] BYREF

  CWnd::Default(this);
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  CopyRect(lprcDst: &rcDst, lprcSrc: pRect);
  if ( rect.right - rect.left != rcDst.right - rcDst.left || rect.bottom - rect.top != rcDst.bottom - rcDst.top )
    this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10361EE7
// Name: public: void CMDIChildWndEx::UnregisterTaskbarTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::UnregisterTaskbarTab(CMDIChildWndEx *this, int bCheckRegisteredMDIChildCount)
{
  CMDITabProxyWnd *p_m_tabProxyWnd; // esi
  ITaskbarList3 *ITaskbarList3; // eax
  CFrameWnd *TopLevelFrame; // eax
  CMDIFrameWndEx *v6; // eax
  CMDIFrameWndEx *v7; // esi
  ITaskbarList3 *v8; // eax

  p_m_tabProxyWnd = &this->m_tabProxyWnd;
  if ( this != (CMDIChildWndEx *)-1084 && this->m_tabProxyWnd.m_hWnd != nullptr )
  {
    ITaskbarList3 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
    if ( ITaskbarList3 != nullptr )
      ITaskbarList3->UnregisterTab(this: ITaskbarList3, a2: p_m_tabProxyWnd->m_hWnd);
    if ( p_m_tabProxyWnd->m_hWnd != nullptr )
      p_m_tabProxyWnd->DestroyWindow(this: p_m_tabProxyWnd);
    if ( bCheckRegisteredMDIChildCount != 0 )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this);
      v6 = (CMDIFrameWndEx *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
      v7 = v6;
      if ( v6 != nullptr && CMDIFrameWndEx::GetRegisteredWithTaskBarMDIChildCount(this: v6) == 0 )
      {
        v8 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
        if ( v8 != nullptr )
          v8->SetThumbnailClip(this: v8, a2: v7->m_hWnd, a3: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362A99
// Name: public: static class CObject __near * CMDIChildWndEx::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDIChildWndEx *__stdcall CMDIChildWndEx::CreateObject()
{
  CMDIChildWndEx *v0; // ecx
  CMDIChildWndEx *result; // eax

  v0 = (CMDIChildWndEx *)operator new(nSize: 0x4BCu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMDIChildWndEx::CMDIChildWndEx(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10362AEA
// Name: public: virtual void CMDIChildWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::AdjustDockingLayout(CMDIChildWndEx *this, void *hdwp)
{
  if ( this->m_dockManager.m_bAdjustingBarLayout == 0 )
  {
    ((void (__stdcall *)(void *))this->m_dockManager.AdjustDockingLayout)(a1: hdwp);
    CMDIChildWndEx::AdjustClientArea(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362B15
// Name: protected: void CMDIChildWndEx::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnDestroy(CMDIChildWndEx *this)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax
  CDockablePane *m_pTabbedControlBar; // eax
  HWND Parent; // eax
  CMDIFrameWndEx *v5; // eax
  CDockablePane *v6; // edi
  CWnd *v7; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *v9; // eax
  HWND i; // eax
  CWnd *v11; // eax
  CWnd *v12; // edi
  CList<HWND__ *,HWND__ *>::CNode *v13; // edi
  HWND__ *v14; // eax
  CObject *data; // [esp-4h] [ebp-40h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-40h]
  CList<HWND__ *,HWND__ *> lstChildren; // [esp+10h] [ebp-2Ch] BYREF
  HWND__ *hwndNext; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+38h] [ebp-4h]

  CMDIChildWndEx::UnregisterTaskbarTab(this, bCheckRegisteredMDIChildCount: 1);
  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr && CFrameImpl::IsPrintPreview(this: &m_pMDIFrame->m_Impl) )
    SendMessageA(hWnd: this->m_pMDIFrame->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  m_pTabbedControlBar = this->m_pTabbedControlBar;
  if ( m_pTabbedControlBar != nullptr
    && CWnd::FromHandlePermanent(hWnd: (CDocument *)m_pTabbedControlBar->m_hWnd) != nullptr )
  {
    Parent = GetParent(hWnd: this->m_pTabbedControlBar->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) == this )
    {
      v5 = this->m_pMDIFrame;
      if ( v5 != nullptr && v5->m_bClosing == 0 )
      {
        CWnd::ShowWindow(this: &this->m_pTabbedControlBar->CPane, nCmdShow: 0);
        v6 = this->m_pTabbedControlBar;
        v7 = v6->GetDockSiteFrameWnd(this: &v6->CPane);
        CWnd::SetParent(this: &v6->CPane, pWndNewParent: v7);
        CDockingManager::AddHiddenMDITabbedBar(
          this: &this->m_pMDIFrame->m_dockManager,
          pBar: (HWND__ *)this->m_pTabbedControlBar);
      }
    }
    this->m_pTabbedControlBar = nullptr;
  }
  CFrameImpl::RemoveFrame(pFrame: this);
  m_pNodeHead = this->m_dockManager.m_lstMiniFrames.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v9 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: data);
    if ( v9 != nullptr )
      v9->__vftable[8].GetRuntimeClass(this: v9);
  }
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&lstChildren.m_pNodeHead, 0, 20);
  lstChildren.m_nBlockSize = 10;
  m_hWnd = this->m_hWnd;
  v19 = 0;
  for ( i = GetTopWindow(hWnd: m_hWnd); ; i = GetWindow(hWnd: v12->m_hWnd, uCmd: 2u) )
  {
    v11 = CWnd::FromHandle(hWnd: i);
    v12 = v11;
    if ( v11 == nullptr )
      break;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&lstChildren,
      newElement: (CFrameWnd *)v11->m_hWnd);
  }
  v13 = lstChildren.m_pNodeHead;
  while ( v13 != nullptr )
  {
    v14 = v13->data;
    v13 = v13->pNext;
    hwndNext = v14;
    if ( IsWindow(hWnd: v14) && GetParent(hWnd: hwndNext) == this->m_hWnd )
      DestroyWindow(hWnd: hwndNext);
  }
  this->m_pRelatedTabGroup = nullptr;
  CMDIChildWnd::OnDestroy(this);
  v19 = -1;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&lstChildren);
}

//------------------------------------------------------------------------------
// Address: 0x10362CBA
// Name: public: virtual int CMDIChildWndEx::OnTaskbarTabThumbnailStretch(struct HBITMAP__ __near *,class CRect const __near &,struct HBITMAP__ __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::OnTaskbarTabThumbnailStretch(
        CMDIChildWndEx *this,
        Gdiplus::GpImage *hBmpDst,
        const CRect *rectDst,
        HBITMAP__ *hBmpSrc,
        const CRect *rectSrc)
{
  HBITMAP__ *v6; // esi
  HDC CompatibleDC; // eax
  HBITMAP__ *v8; // eax
  HDC__ *m_hDC; // esi
  BOOL v10; // esi
  int BitmapFromHBITMAP; // eax
  Gdiplus::Status v12; // eax
  ATL::CImage image; // [esp+10h] [ebp-80h] BYREF
  CClientDC dcClient; // [esp+44h] [ebp-4Ch] BYREF
  Gdiplus::Image v16; // [esp+58h] [ebp-38h] BYREF
  CDC dc; // [esp+68h] [ebp-28h] BYREF
  Gdiplus::Graphics v18; // [esp+78h] [ebp-18h] BYREF
  HBITMAP__ *hOldBmp; // [esp+80h] [ebp-10h]
  int v20; // [esp+8Ch] [ebp-4h]

  v6 = hBmpSrc;
  if ( hBmpSrc == nullptr || hBmpDst == nullptr )
    return false;
  ATL::CImage::CImage(this: &image);
  v20 = 0;
  image.m_hBitmap = v6;
  ATL::CImage::UpdateBitmapInfo(this: &image, eOrientation: DIBOR_DEFAULT);
  CClientDC::CClientDC(this: &dcClient, pWnd: this);
  LOBYTE(v20) = 1;
  CDC::CDC(this: &dc);
  LOBYTE(v20) = 2;
  CompatibleDC = CreateCompatibleDC(hdc: dcClient.m_hDC);
  CDC::Attach(this: &dc, hDC: CompatibleDC);
  v8 = (HBITMAP__ *)SelectObject(hdc: dc.m_hDC, h: hBmpDst);
  m_hDC = dc.m_hDC;
  hOldBmp = v8;
  if ( ATL::CImage::CInitGDIPlus::Init(this: &ATL::CImage::s_initGDIPlus) )
  {
    v16.__vftable = (Gdiplus::Image_vtbl *)&Gdiplus::Bitmap::`vftable';
    hBmpDst = nullptr;
    BitmapFromHBITMAP = GdipCreateBitmapFromHBITMAP(a1: (int)image.m_hBitmap, a2: 0, a3: (int)&hBmpDst);
    v16.nativeImage = hBmpDst;
    v16.lastResult = Ok;
    if ( BitmapFromHBITMAP == 0 )
    {
      hBmpSrc = nullptr;
      v18.lastResult = GdipCreateFromHDC(a1: (int)m_hDC, a2: (int)&hBmpSrc);
      v18.nativeGraphics = (Gdiplus::GpGraphics *)hBmpSrc;
      v12 = GdipSetInterpolationMode(a1: (int)hBmpSrc, a2: 7);
      if ( v12 != Ok )
        v18.lastResult = v12;
      v10 = Gdiplus::Graphics::DrawImage(
              this: &v18,
              image: &v16,
              x: rectDst->left,
              y: rectDst->top,
              width: rectDst->right - rectDst->left,
              height: rectDst->bottom - rectDst->top) == Ok;
      GdipDeleteGraphics(a1: (int)v18.nativeGraphics);
      GdipDisposeImage(a1: (int)hBmpDst);
      goto LABEL_10;
    }
    GdipDisposeImage(a1: (int)hBmpDst);
  }
  v10 = false;
LABEL_10:
  if ( hOldBmp != nullptr )
    SelectObject(hdc: dc.m_hDC, h: hOldBmp);
  LOBYTE(v20) = 1;
  CDC::~CDC(this: &dc);
  LOBYTE(v20) = 0;
  CClientDC::~CClientDC(this: &dcClient);
  ATL::CImage::~CImage(this: &image);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10362E0F
// Name: public: struct HBITMAP__ __near * CMDITabProxyWnd::GetClientBitmap(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBITMAP__ *__thiscall CMDITabProxyWnd::GetClientBitmap(
        CMDITabProxyWnd *this,
        int nWidth,
        int nHeight,
        int bIsThumbnail)
{
  CMDIChildWndEx *m_pRelatedMDIChildFrame; // ecx
  CWnd *v5; // esi
  HDC CompatibleDC; // eax
  char *m_pBits; // eax
  int bottom; // ecx
  int right; // edx
  _BYTE *v10; // eax
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st4
  HDC v15; // eax
  HGDIOBJ v16; // esi
  HBITMAP__ *v17; // esi
  HWND m_hWnd; // [esp-8h] [ebp-F4h]
  ATL::CImage v20; // [esp+10h] [ebp-DCh] BYREF
  CClientDC v21; // [esp+44h] [ebp-A8h] BYREF
  ATL::CImage v22; // [esp+58h] [ebp-94h] BYREF
  CDC v23; // [esp+8Ch] [ebp-60h] BYREF
  int v24; // [esp+9Ch] [ebp-50h]
  CMDITabProxyWnd *v25; // [esp+A0h] [ebp-4Ch]
  int v26; // [esp+A4h] [ebp-48h] BYREF
  CWnd *v27; // [esp+A8h] [ebp-44h]
  CDC v28; // [esp+ACh] [ebp-40h] BYREF
  tagRECT rectDest; // [esp+BCh] [ebp-30h] BYREF
  tagRECT Rect; // [esp+CCh] [ebp-20h] BYREF
  int v31; // [esp+E8h] [ebp-4h]

  v25 = this;
  v24 = nWidth;
  if ( this->m_pRelatedMDIChildFrame == nullptr )
    return nullptr;
  if ( nWidth <= 0 )
    return nullptr;
  if ( nHeight <= 0 )
    return nullptr;
  m_pRelatedMDIChildFrame = this->m_pRelatedMDIChildFrame;
  memset(&Rect, 0, sizeof(Rect));
  v5 = m_pRelatedMDIChildFrame->GetTaskbarPreviewWnd(this: m_pRelatedMDIChildFrame);
  m_hWnd = v5->m_hWnd;
  v27 = v5;
  GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
  OffsetRect(lprc: &Rect, dx: -Rect.left, dy: -Rect.top);
  if ( Rect.right - Rect.left <= 0 || Rect.bottom - Rect.top <= 0 )
    return nullptr;
  ATL::CImage::CImage(this: &v22);
  v31 = 0;
  ATL::CImage::CreateEx(
    this: &v22,
    nWidth: Rect.right - Rect.left,
    nHeight: Rect.bottom - Rect.top,
    nBPP: 32,
    eCompression: 0,
    pdwBitfields: nullptr,
    dwFlags: 1);
  CClientDC::CClientDC(this: &v21, pWnd: v5);
  LOBYTE(v31) = 1;
  CDC::CDC(this: &v23);
  LOBYTE(v31) = 2;
  CompatibleDC = CreateCompatibleDC(hdc: v21.m_hDC);
  CDC::Attach(this: &v23, hDC: CompatibleDC);
  if ( v22.m_hBitmap != nullptr )
    v28.m_bPrinting = (int)SelectObject(hdc: v23.m_hDC, h: v22.m_hBitmap);
  else
    v28.m_bPrinting = 0;
  v26 = 0;
  ((void (__thiscall *)(CWnd *, CDC *, int, int, int, int, int, int, int, int *))v5->OnDrawIconicThumbnailOrLivePreview)(
    a1: v27,
    a2: &v23,
    a3: Rect.left,
    a4: Rect.top,
    a5: Rect.right,
    a6: Rect.bottom,
    a7: nWidth,
    a8: nHeight,
    a9: bIsThumbnail,
    a10: &v26);
  if ( v28.m_bPrinting != 0 )
    SelectObject(hdc: v23.m_hDC, h: (HGDIOBJ)v28.m_bPrinting);
  if ( v26 != 0 )
  {
    bottom = Rect.bottom;
    right = Rect.right;
  }
  else
  {
    m_pBits = (char *)v22.m_pBits;
    if ( v22.m_nPitch < 0 )
      m_pBits = (char *)v22.m_pBits + v22.m_nPitch * (v22.m_nHeight - 1);
    bottom = Rect.bottom;
    right = Rect.right;
    v28.m_bPrinting = 0;
    if ( (Rect.right - Rect.left) * (Rect.bottom - Rect.top) > 0 )
    {
      v10 = m_pBits + 3;
      do
      {
        *v10 = -1;
        bottom = Rect.bottom;
        right = Rect.right;
        v10 += 4;
        ++v28.m_bPrinting;
      }
      while ( v28.m_bPrinting < (Rect.right - Rect.left) * (Rect.bottom - Rect.top) );
    }
  }
  v28.m_hAttribDC = (HDC__ *)(right - Rect.left);
  v11 = (double)(right - Rect.left);
  v27 = (CWnd *)(bottom - Rect.top);
  v12 = (double)v24 / v11;
  v13 = (double)(bottom - Rect.top);
  v14 = (double)nHeight / v13;
  if ( v14 <= v12 )
    v12 = v14;
  rectDest.left = 0;
  rectDest.right = (int)(v11 * v12);
  rectDest.top = 0;
  rectDest.bottom = (int)(v13 * v12);
  ATL::CImage::CImage(this: &v20);
  LOBYTE(v31) = 3;
  ATL::CImage::CreateEx(
    this: &v20,
    nWidth: (int)(v11 * v12),
    nHeight: -(int)(v13 * v12),
    nBPP: 32,
    eCompression: 0,
    pdwBitfields: nullptr,
    dwFlags: 1);
  if ( bIsThumbnail == 0
    || v25->m_pRelatedMDIChildFrame->OnTaskbarTabThumbnailStretch(
         this: v25->m_pRelatedMDIChildFrame,
         a2: v20.m_hBitmap,
         a3: (const CRect *)&rectDest,
         a4: v22.m_hBitmap,
         a5: (const CRect *)&Rect) == 0 )
  {
    CDC::CDC(this: &v28);
    LOBYTE(v31) = 4;
    v15 = CreateCompatibleDC(hdc: v21.m_hDC);
    CDC::Attach(this: &v28, hDC: v15);
    if ( v20.m_hBitmap != nullptr )
      v16 = SelectObject(hdc: v28.m_hDC, h: v20.m_hBitmap);
    else
      v16 = nullptr;
    ATL::CImage::AlphaBlend(this: &v22, hDestDC: v28.m_hDC, &rectDest, rectSrc: &Rect, bSrcAlpha: 255, bBlendOp: 0);
    if ( v16 != nullptr )
      SelectObject(hdc: v28.m_hDC, h: v16);
    LOBYTE(v31) = 3;
    CDC::~CDC(this: &v28);
  }
  v17 = ATL::CImage::Detach(this: &v20);
  ATL::CImage::~CImage(this: &v20);
  LOBYTE(v31) = 1;
  CDC::~CDC(this: &v23);
  LOBYTE(v31) = 0;
  CClientDC::~CClientDC(this: &v21);
  ATL::CImage::~CImage(this: &v22);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10363117
// Name: protected: long CMDITabProxyWnd::OnSendIconicThumbnail(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CMDITabProxyWnd::OnSendIconicThumbnail@<eax>(
        CMDITabProxyWnd *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int wParam,
        unsigned int lParam)
{
  unsigned int v7; // esi
  HMODULE ModuleHandleA; // eax
  HBITMAP__ *ClientBitmap; // ebx
  HRESULT (__stdcall *pfnSetIconicThumbnail)(HWND__ *, HBITMAP__ *, unsigned int); // [esp+4h] [ebp-4h]

  if ( this->m_pRelatedMDIChildFrame == nullptr )
    return CWnd::Default(this);
  v7 = HIWORD(lParam);
  ModuleHandleA = GetModuleHandleA(lpModuleName: "DWMAPI");
  if ( ModuleHandleA != nullptr )
  {
    pfnSetIconicThumbnail = (HRESULT (__stdcall *)(HWND__ *, HBITMAP__ *, unsigned int))GetProcAddress(
                                                                                          hModule: ModuleHandleA,
                                                                                          lpProcName: "DwmSetIconicThumbnail");
    if ( pfnSetIconicThumbnail != nullptr )
    {
      ClientBitmap = (HBITMAP__ *)((int (__thiscall *)(CMDIChildWndEx *, unsigned int, _DWORD, int, int))this->m_pRelatedMDIChildFrame->OnGetIconicThumbnail)(
                                    a1: this->m_pRelatedMDIChildFrame,
                                    a2: v7,
                                    a3: (unsigned __int16)lParam,
                                    a4: a3,
                                    a5: a2);
      if ( ClientBitmap == nullptr )
        ClientBitmap = CMDITabProxyWnd::GetClientBitmap(
                         this,
                         nWidth: v7,
                         nHeight: (unsigned __int16)lParam,
                         bIsThumbnail: 1);
      ((void (__stdcall *)(HWND__ *))pfnSetIconicThumbnail)(a1: this->m_hWnd);
      DeleteObject(ho: ClientBitmap);
    }
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036319F
// Name: protected: long CMDITabProxyWnd::OnSendIconicLivePreviewBitmap(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDITabProxyWnd::OnSendIconicLivePreviewBitmap(CMDITabProxyWnd *this, unsigned int wParam, int lParam)
{
  BOOL IsMDIChildActive; // eax
  CMDIChildWndEx *m_pRelatedMDIChildFrame; // ecx
  HBITMAP ClientBitmap; // ebx
  CFrameWnd *TopLevelFrame; // eax
  CObject *v8; // eax
  CMDIChildWndEx *v9; // ecx
  CWnd *v10; // ebx
  int v11; // eax
  HMODULE ModuleHandleA; // eax
  HRESULT (__stdcall *DwmSetIconicLivePreviewBitmap)(HWND, HBITMAP, POINT *, DWORD); // eax
  CPoint ptClient; // [esp+8h] [ebp-1Ch] BYREF
  CRect rectWnd; // [esp+10h] [ebp-14h] BYREF

  if ( this->m_pRelatedMDIChildFrame != nullptr )
  {
    IsMDIChildActive = CMDITabProxyWnd::IsMDIChildActive(this);
    m_pRelatedMDIChildFrame = this->m_pRelatedMDIChildFrame;
    ptClient.x = 0;
    ptClient.y = 0;
    ClientBitmap = m_pRelatedMDIChildFrame->OnGetIconicLivePreviewBitmap(
                     this: m_pRelatedMDIChildFrame,
                     a2: IsMDIChildActive,
                     a3: &ptClient);
    if ( ClientBitmap == nullptr )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this: this->m_pRelatedMDIChildFrame);
      v8 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
      v9 = this->m_pRelatedMDIChildFrame;
      v10 = (CWnd *)v8;
      memset(&rectWnd, 0, sizeof(rectWnd));
      v11 = (int)v9->GetTaskbarPreviewWnd(this: v9);
      GetWindowRect(hWnd: *(HWND *)(v11 + 32), lpRect: &rectWnd);
      CWnd::ScreenToClient(this: v10, lpRect: (tagPOINT *)&rectWnd);
      ptClient.y = rectWnd.top;
      ptClient.x = rectWnd.left;
      ClientBitmap = CMDITabProxyWnd::GetClientBitmap(
                       this,
                       nWidth: rectWnd.right - rectWnd.left,
                       nHeight: rectWnd.bottom - rectWnd.top,
                       bIsThumbnail: 0);
    }
    ModuleHandleA = GetModuleHandleA(lpModuleName: "DWMAPI");
    if ( ModuleHandleA != nullptr )
    {
      DwmSetIconicLivePreviewBitmap = (HRESULT (__stdcall *)(HWND, HBITMAP, POINT *, DWORD))GetProcAddress(
                                                                                              hModule: ModuleHandleA,
                                                                                              lpProcName: "DwmSetIconicLivePreviewBitmap");
      if ( DwmSetIconicLivePreviewBitmap != nullptr )
        DwmSetIconicLivePreviewBitmap(hwnd: this->m_hWnd, hbmp: ClientBitmap, pptClient: &ptClient, dwSITFlags: 0);
    }
    DeleteObject(ho: ClientBitmap);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103632B0
// Name: public: void CMDIChildWndEx::SetTaskbarTabProperties(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::SetTaskbarTabProperties(CMDIChildWndEx *this, STPFLAG dwFlags)
{
  CMDITabProxyWnd *p_m_tabProxyWnd; // esi
  ITaskbarList3 *ITaskbarList3; // eax
  ITaskbarList4 *p; // ecx
  ATL::CComQIPtr<ITaskbarList4,&_GUID_c43dc798_95d1_4bea_9030_bb99e2983a1a> spTaskbarList4; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  if ( CMDIChildWndEx::IsTaskbarTabsSupportEnabled(this) && CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this) )
  {
    p_m_tabProxyWnd = &this->m_tabProxyWnd;
    if ( p_m_tabProxyWnd != nullptr && p_m_tabProxyWnd->m_hWnd != nullptr )
    {
      ITaskbarList3 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
      p = nullptr;
      spTaskbarList4.p = nullptr;
      if ( ITaskbarList3 != nullptr )
      {
        ITaskbarList3->QueryInterface(
          this: ITaskbarList3,
          a2: &_GUID_c43dc798_95d1_4bea_9030_bb99e2983a1a,
          a3: (void **)&spTaskbarList4.p);
        p = spTaskbarList4.p;
      }
      v7 = 0;
      if ( p != nullptr )
      {
        p->SetTabProperties(this: p, a2: p_m_tabProxyWnd->m_hWnd, a3: dwFlags);
        p = spTaskbarList4.p;
      }
      v7 = -1;
      if ( p != nullptr )
        p->Release(this: p);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037332A
// Name: public: virtual unsigned long CPreviewDC::SetTextColor(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COLORREF __thiscall CPreviewDC::SetTextColor(CPreviewDC *this, COLORREF crColor)
{
  COLORREF NearestColor; // eax

  if ( this->m_hDC != nullptr )
  {
    NearestColor = GetNearestColor(hdc: this->m_hAttribDC, color: crColor);
    SetTextColor(hdc: this->m_hDC, color: NearestColor);
  }
  return SetTextColor(hdc: this->m_hAttribDC, color: crColor);
}

//------------------------------------------------------------------------------
// Address: 0x1037335F
// Name: int _AfxComputeNextTab(int,unsigned int,int __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxComputeNextTab(int x, unsigned int nTabStops, int *lpnTabStops, int nTabOrigin, int nTabWidth)
{
  unsigned int v5; // edx
  int v6; // eax
  int v8; // eax

  v5 = 0;
  if ( nTabWidth == 0 )
    AfxThrowInvalidArgException();
  v6 = x - nTabOrigin;
  if ( nTabStops != 0 )
  {
    while ( *lpnTabStops <= v6 )
    {
      ++v5;
      ++lpnTabStops;
      if ( v5 >= nTabStops )
        goto LABEL_6;
    }
    v8 = *lpnTabStops;
  }
  else
  {
LABEL_6:
    v8 = nTabWidth * (v6 / nTabWidth + 1);
  }
  return nTabOrigin + v8;
}

//------------------------------------------------------------------------------
// Address: 0x103B9173
// Name: public: Gdiplus::Bitmap::Bitmap(int,int,int,int,unsigned char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Gdiplus::Bitmap *__thiscall Gdiplus::Bitmap::Bitmap(
        Gdiplus::Bitmap *this,
        int width,
        int height,
        int stride,
        int format,
        unsigned __int8 *scan0)
{
  Gdiplus::GpBitmap *bitmap; // [esp+4h] [ebp-4h] BYREF

  bitmap = nullptr;
  this->__vftable = (Gdiplus::Bitmap_vtbl *)&Gdiplus::Bitmap::`vftable';
  this->lastResult = GdipCreateBitmapFromScan0(
                       a1: width,
                       a2: height,
                       a3: stride,
                       a4: format,
                       a5: (int)scan0,
                       a6: (int)&bitmap);
  this->nativeImage = bitmap;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103BC2CB
// Name: public: int CPngImage::LoadFromBuffer(unsigned char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPngImage::LoadFromBuffer(CPngImage *this, unsigned __int8 *lpBuffer, SIZE_T uiSize)
{
  HGLOBAL v3; // eax
  void *v4; // esi
  unsigned __int8 *v6; // eax
  ATL::CImage *v7; // eax
  ATL::CImage *v8; // eax
  HBITMAP__ *v9; // eax
  int v10; // esi
  IStream *pStream; // [esp+8h] [ebp-4h] BYREF

  v3 = GlobalAlloc(uFlags: 2u, dwBytes: uiSize);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  pStream = nullptr;
  v6 = (unsigned __int8 *)GlobalLock(hMem: v3);
  memcpy(dst: v6, src: lpBuffer, count: uiSize);
  if ( CreateStreamOnHGlobal(hGlobal: v4, fDeleteOnRelease: false, ppstm: &pStream) != 0 )
    return 0;
  if ( CMFCToolBarImages::m_bMultiThreaded != 0 )
    EnterCriticalSection(lpCriticalSection: &CMFCToolBarImages::m_CriticalSection.m_sect);
  v7 = CPngImage::m_pImage;
  if ( CPngImage::m_pImage == nullptr )
  {
    v8 = (ATL::CImage *)operator new(nSize: 0x34u);
    v7 = v8 != nullptr ? ATL::CImage::CImage(this: v8) : nullptr;
    CPngImage::m_pImage = v7;
    if ( v7 == nullptr )
      AfxThrowInvalidArgException();
  }
  ATL::CImage::Load(this: v7, pStream);
  pStream->Release(this: pStream);
  v9 = ATL::CImage::Detach(this: CPngImage::m_pImage);
  v10 = CGdiObject::Attach(this, hObject: v9);
  if ( CMFCToolBarImages::m_bMultiThreaded != 0 )
    LeaveCriticalSection(lpCriticalSection: &CMFCToolBarImages::m_CriticalSection.m_sect);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x103BC39D
// Name: public: int CPngImage::Load(char const __near *,struct HINSTANCE__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPngImage::Load(CPngImage *this, const char *lpszResourceName, HINSTANCE__ *hinstRes)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // esi
  HRSRC ResourceA; // eax
  HRSRC v5; // edi
  HGLOBAL Resource; // eax
  unsigned __int8 *v8; // ebx
  int v9; // esi
  SIZE_T v10; // eax
  void *hGlobal; // [esp+18h] [ebp+Ch]

  m_hCurrentResourceHandle = hinstRes;
  if ( hinstRes == nullptr )
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
  ResourceA = FindResourceA(
                hModule: m_hCurrentResourceHandle,
                lpName: lpszResourceName,
                lpType: CMFCToolBarImages::m_strPngResType.m_pszData);
  v5 = ResourceA;
  if ( ResourceA == nullptr )
    return 0;
  Resource = LoadResource(hModule: m_hCurrentResourceHandle, hResInfo: ResourceA);
  hGlobal = Resource;
  if ( Resource == nullptr )
    return 0;
  v8 = (unsigned __int8 *)LockResource(hResData: Resource);
  if ( v8 != nullptr )
  {
    v10 = SizeofResource(hModule: m_hCurrentResourceHandle, hResInfo: v5);
    v9 = CPngImage::LoadFromBuffer(this, lpBuffer: v8, uiSize: v10);
  }
  else
  {
    v9 = 0;
  }
  FreeResource(hResData: hGlobal);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x103BC418
// Name: public: virtual CMFCToolBarImages::~CMFCToolBarImages(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarImages::~CMFCToolBarImages(CMFCToolBarImages *this)
{
  CDC *p_m_dcMem; // ebx
  HDC__ *m_hDC; // eax
  void *m_hObject; // eax

  this->__vftable = (CMFCToolBarImages_vtbl *)&CMFCToolBarImages::`vftable';
  p_m_dcMem = &this->m_dcMem;
  if ( this == (CMFCToolBarImages *)-64 )
    m_hDC = nullptr;
  else
    m_hDC = this->m_dcMem.m_hDC;
  if ( m_hDC != nullptr
    || (this != (CMFCToolBarImages *)-152 ? (m_hObject = this->m_bmpMem.m_hObject) : (m_hObject = nullptr),
        m_hObject != nullptr || this->m_pBmpOriginal != nullptr) )
  {
    AfxThrowInvalidArgException();
  }
  if ( this->m_bIsTemporary == 0 )
  {
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageWell);
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageLight);
    AfxDeleteObject(pObject: (void **)&this->m_hbmImageShadow);
  }
  this->m_mapOrigResOffsets.__vftable = (CMap<unsigned int,unsigned int,int,int>_vtbl *)&CMap<unsigned int,unsigned int,int,int>::`vftable';
  CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&this->m_mapOrigResOffsets);
  this->m_lstOrigResInstances.__vftable = (CList<HINSTANCE__ *,HINSTANCE__ *>_vtbl *)&CList<HINSTANCE__ *,HINSTANCE__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResInstances);
  this->m_lstOrigResIds.__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstOrigResIds);
  this->m_bmpMem.__vftable = (CBitmap_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_bmpMem);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strUDLPath.m_pszData - 1);
  CDC::~CDC(this: p_m_dcMem);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100B8A60
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x100B8A70
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x100B8A90
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8D80
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B8DD0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8E30
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x100B8EB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8EE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100B8EF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8F90
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100B9260
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x100B9300
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B94A0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D8950
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B8E50
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00447E20
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00447E30
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00447E60
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448150
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448180
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004481E0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00448260
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448290
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x004482A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448310
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x004485F0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x00448690
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00448830
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047F810
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448200
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0042F350
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x0042F360
// Name: public: CheckImage::CheckImage(class vgui::CheckButton __near *)
// Source: json
//------------------------------------------------------------------------------
CheckImage *__thiscall CheckImage::CheckImage(CheckImage *this, vgui::CheckButton *CheckButton)
{
  vgui::TextImage::TextImage(this, text: "g");
  this->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
  this->_borderColor1 = 0;
  this->_borderColor2 = 0;
  this->_checkColor = 0;
  this->_bgColor = 0;
  this->_CheckButton = CheckButton;
  this->_drawMode = 0;
  vgui::TextImage::SetSize(this, wide: 20, tall: 13);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042F3B0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x0042F3C0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int y; // [esp+6Ch] [ebp-10h] BYREF
  int wide; // [esp+70h] [ebp-Ch] BYREF
  int tall; // [esp+74h] [ebp-8h] BYREF
  int v10; // [esp+78h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &y, a3: &wide);
    this->GetContentSize(this, a2: &tall, a3: &v10);
    CheckButton = this->_CheckButton;
    ++y;
    tall -= 2;
    ++wide;
    v10 -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y + 1, a3: wide + 1, a4: y + tall - 1, a5: v10 + wide - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y + 1, a3: wide, a4: y + tall - 1, a5: wide + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y, a3: wide + 1, a4: y + 1, a5: v10 + wide - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: y + 1,
      a3: wide + v10 - 1,
      a4: y + tall - 1,
      a5: wide + v10);
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: tall + y - 1,
      a3: wide + 1,
      a4: tall + y,
      a5: wide + v10 - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F6F0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042F720
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F780
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0042F810
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F840
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042F850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F8C0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // ebp
  Color *v6; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v9)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v10; // ebp
  Color *v11; // eax
  Color *(__thiscall *v12)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  vgui::CheckButton_vtbl *v14; // edx
  vgui::CheckButton_vtbl *v15; // ebp
  Color *v16; // eax
  Color *(__thiscall *v17)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  vgui::CheckButton_vtbl *v18; // ebp
  Color *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  CheckImage_vtbl *v21; // ebx
  vgui::IScheme v22; // ebp
  int v23; // eax
  int v24; // eax
  Color bgDepressedColor; // [esp+C0h] [ebp-Ch] BYREF
  int v26; // [esp+C4h] [ebp-8h] BYREF
  _BYTE v27[4]; // [esp+C8h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  v6 = this->GetSchemeColor_2(this, result: v27, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, _DWORD))v4->SetDefaultColor)(a1: this, a2: *v6, a3: *v5);
  GetSchemeColor = this->GetSchemeColor;
  pScheme = -13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v8 = this->GetSchemeColor;
  pScheme = -15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  pScheme = -10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->GetSchemeColor;
  pScheme = -15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v9)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  v10 = this->__vftable;
  v11 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v10->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v27,
                              a3: "CheckButton.SelectedTextColor",
                              a4: *v11,
                              a5: v2);
  v12 = this->GetSchemeColor;
  pScheme = -8224126;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v12)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme = -13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->__vftable;
  pScheme = -13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  v15 = this->__vftable;
  v16 = this->GetFgColor(this, result: &pScheme);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, Color))v15->SetArmedColor)(
    a1: this,
    a2: *v16,
    a3: bgDepressedColor);
  v17 = this->GetSchemeColor;
  pScheme = -13154754;
  ((void (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v17)(
    a1: this,
    a2: &v26,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->__vftable;
  v19 = this->GetFgColor(this, result: &pScheme);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, _DWORD))v18->SetDepressedColor)(a1: this, a2: *v19, a3: v26);
  v20 = this->GetSchemeColor;
  pScheme = -13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->_checkBoxImage->__vftable;
  v22.__vftable = v2->__vftable;
  v23 = ((int (__thiscall *)(vgui::CheckButton *))this->IsProportional)(a1: this);
  v24 = v22.GetFont(this: v2, a2: "Marlett", a3: v23);
  v21->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042FC00
// Name: public: static void vgui::CheckButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CheckButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
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
// Address: 0x0042FC80
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::CheckButton::AddToMap(
      scriptname: "CheckButtonChecked",
      function: (unsigned int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)4,
      p1name: "panel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042FCE0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CheckImage *v8; // eax
  CheckImage *v9; // eax

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (CheckImage *)operator new(nSize: 0x98u);
  if ( v8 != nullptr )
    v9 = CheckImage::CheckImage(this: v8, CheckButton: this);
  else
    v9 = nullptr;
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042FE70
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00463900
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F7A0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__userpurge vgui::CheckButton::GetButtonFgColor@<eax>(
        vgui::CheckButton *this@<ecx>,
        __m128i a2@<xmm0>,
        Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, a2, result);
    return result;
  }
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0063BA80
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x0063BA90
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x0063BAB0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BDA0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063BDF0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063BE50
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0063BEE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063BF10
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0063BF20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063BFC0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0063C2A0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x0063C340
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0063C4E0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006705A0
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063BE70
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x100418C0
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x100418D0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x100418F0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041BE0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x10041C10
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041C70
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10041CF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041D20
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x10041D30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041DD0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100420A0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x10042140
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100422E0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007D8C0
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10041C90
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10066140
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x10066150
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10066170
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066460
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x100664A0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10066500
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10066580
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100665B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100665C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066660
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10066930
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x100669D0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10066B70
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10097C80
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10066520
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00437B70
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00437B80
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00437BA0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437E90
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00437ED0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437F30
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00437FB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437FE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00438000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00438070
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00438350
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x004383F0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00438590
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004721A0
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437F50
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00481290
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x004812A0
// Name: public: CheckImage::CheckImage(class vgui::CheckButton __near *)
// Source: json
//------------------------------------------------------------------------------
CheckImage *__thiscall CheckImage::CheckImage(CheckImage *this, vgui::CheckButton *CheckButton)
{
  vgui::TextImage::TextImage(this, text: "g");
  this->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
  this->_borderColor1 = 0;
  this->_borderColor2 = 0;
  this->_checkColor = 0;
  this->_bgColor = 0;
  this->_CheckButton = CheckButton;
  this->_drawMode = 0;
  vgui::TextImage::SetSize(this, wide: 20, tall: 13);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004812F0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00481300
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int y; // [esp+6Ch] [ebp-10h] BYREF
  int wide; // [esp+70h] [ebp-Ch] BYREF
  int tall; // [esp+74h] [ebp-8h] BYREF
  int v10; // [esp+78h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &y, a3: &wide);
    this->GetContentSize(this, a2: &tall, a3: &v10);
    CheckButton = this->_CheckButton;
    ++y;
    tall -= 2;
    ++wide;
    v10 -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y + 1, a3: wide + 1, a4: y + tall - 1, a5: v10 + wide - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y + 1, a3: wide, a4: y + tall - 1, a5: wide + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: y, a3: wide + 1, a4: y + 1, a5: v10 + wide - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: y + 1,
      a3: wide + v10 - 1,
      a4: y + tall - 1,
      a5: wide + v10);
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: tall + y - 1,
      a3: wide + 1,
      a4: tall + y,
      a5: wide + v10 - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481630
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x00481670
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004816D0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x00481760
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481790
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x004817A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00481830
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // ebp
  Color *v6; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v9)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v10; // ebp
  Color *v11; // eax
  Color *(__thiscall *v12)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  vgui::CheckButton_vtbl *v14; // edx
  vgui::CheckButton_vtbl *v15; // ebp
  Color *v16; // eax
  Color *(__thiscall *v17)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  vgui::CheckButton_vtbl *v18; // ebp
  Color *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  CheckImage_vtbl *v21; // ebx
  vgui::IScheme v22; // ebp
  int v23; // eax
  int v24; // eax
  Color bgDepressedColor; // [esp+C0h] [ebp-Ch] BYREF
  int v26; // [esp+C4h] [ebp-8h] BYREF
  _BYTE v27[4]; // [esp+C8h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme;
  vgui::ToggleButton::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  v4 = this->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  v6 = this->GetSchemeColor_2(this, result: v27, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, _DWORD))v4->SetDefaultColor)(a1: this, a2: *v6, a3: *v5);
  GetSchemeColor = this->GetSchemeColor;
  pScheme = -13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v8 = this->GetSchemeColor;
  pScheme = -15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  pScheme = -10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->GetSchemeColor;
  pScheme = -15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v9)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  v10 = this->__vftable;
  v11 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ControlText", a4: v2);
  this->_selectedFgColor = *((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))v10->GetSchemeColor)(
                              a1: this,
                              a2: (Color *)v27,
                              a3: "CheckButton.SelectedTextColor",
                              a4: *v11,
                              a5: v2);
  v12 = this->GetSchemeColor;
  pScheme = -8224126;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v12)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme = -13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->__vftable;
  pScheme = -13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  v15 = this->__vftable;
  v16 = this->GetFgColor(this, result: &pScheme);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, Color))v15->SetArmedColor)(
    a1: this,
    a2: *v16,
    a3: bgDepressedColor);
  v17 = this->GetSchemeColor;
  pScheme = -13154754;
  ((void (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v17)(
    a1: this,
    a2: &v26,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->__vftable;
  v19 = this->GetFgColor(this, result: &pScheme);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, _DWORD))v18->SetDepressedColor)(a1: this, a2: *v19, a3: v26);
  v20 = this->GetSchemeColor;
  pScheme = -13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, int *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->_checkBoxImage->__vftable;
  v22.__vftable = v2->__vftable;
  v23 = ((int (__thiscall *)(vgui::CheckButton *))this->IsProportional)(a1: this);
  v24 = v22.GetFont(this: v2, a2: "Marlett", a3: v23);
  v21->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00481B70
// Name: public: static void vgui::CheckButton::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::CheckButton::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
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
// Address: 0x00481BF0
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    vgui::CheckButton::AddToMap(
      scriptname: "CheckButtonChecked",
      function: (unsigned int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)4,
      p1name: "panel",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481C50
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CheckImage *v8; // eax
  CheckImage *v9; // eax

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (CheckImage *)MemAlloc_Alloc(nSize: 0x98u);
  if ( v8 != nullptr )
    v9 = CheckImage::CheckImage(this: v8, CheckButton: this);
  else
    v9 = nullptr;
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00481DE0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00426490
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x004264A0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x004264C0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004267B0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x004267E0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426840
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x004268C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004268F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x00426900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004269A0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00426C80
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x00426D20
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x98u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426EC0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00467750
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426860
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00429EC0
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x00429ED0
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00429EF0
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A1E0
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A220
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A280
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x0042A300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A330
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x0042A340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A3B0
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042A680
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x0042A720
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8C0
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00468270
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A2A0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1039DB40
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DE30
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039DE60
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039DEC0
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x1039DF80
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1039E250
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039E2F0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039E490
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1039DEE0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10398060
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x10398070
// Name: public: virtual void vgui::Image::SetBkColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetBkColor(vgui::Image *this, Color color)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10398090
// Name: public: virtual void CheckImage::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CheckImage::Paint(CheckImage *this)
{
  CheckImage_vtbl *v2; // edi
  unsigned int v3; // eax
  vgui::CheckButton *CheckButton; // ecx
  bool v5; // al
  CheckImage_vtbl *v6; // edx
  int tall; // [esp+8h] [ebp-10h] BYREF
  int wide; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int x; // [esp+14h] [ebp-4h] BYREF

  v2 = this->__vftable;
  v3 = this->GetFont(this);
  v2->DrawSetTextFont(this, a2: v3);
  if ( this->_drawMode != 0 )
  {
    this->GetPos(this, a2: &x, a3: &y);
    this->GetContentSize(this, a2: &wide, a3: &tall);
    CheckButton = this->_CheckButton;
    ++x;
    wide -= 2;
    ++y;
    tall -= 2;
    if ( CheckButton->IsEnabled(this: CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + 1, a4: wide + x - 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y, a4: wide + x - 1, a5: y + 1);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y + 1, a4: x + 1, a5: tall + y - 1);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->_borderColor2);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x + 1, a3: y + tall - 1, a4: wide + x - 1, a5: y + tall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: wide + x - 1, a3: y + 1, a4: wide + x, a5: tall + y - 1);
  }
  else
  {
    if ( this->_CheckButton->IsEnabled(this: this->_CheckButton)
      && this->_CheckButton->IsCheckButtonCheckable(this: this->_CheckButton) )
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_bgColor);
    }
    else
    {
      ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledBgColor);
    }
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 103);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor1);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 101);
    ((void (__thiscall *)(CheckImage *, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_borderColor2);
    this->DrawPrintChar(this, a2: 0, a3: 1, a4: 102);
  }
  if ( this->_CheckButton->IsSelected(this: this->_CheckButton) )
  {
    v5 = this->_CheckButton->IsEnabled(this: this->_CheckButton);
    v6 = this->__vftable;
    if ( v5 )
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(a1: this, a2: *(_DWORD *)&this->_checkColor);
    else
      ((void (__thiscall *)(CheckImage *, _DWORD))v6->DrawSetTextColor_2)(
        a1: this,
        a2: *(_DWORD *)&this->_CheckButton->_disabledFgColor);
    this->DrawPrintChar(this, a2: 0, a3: 2, a4: 98);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398380
// Name: public: virtual vgui::CheckButton::~CheckButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::~CheckButton(vgui::CheckButton *this)
{
  CheckImage *checkBoxImage; // ecx

  checkBoxImage = this->_checkBoxImage;
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( checkBoxImage != nullptr )
    ((void (__thiscall *)(CheckImage *, int))checkBoxImage->dtr_IImage)(a1: checkBoxImage, a2: 1);
  vgui::Button::~Button(this);
}

//------------------------------------------------------------------------------
// Address: 0x103983B0
// Name: public: virtual void vgui::CheckButton::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetSelected(vgui::CheckButton *this, bool state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->m_bCheckButtonCheckable )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "CheckButtonChecked", firstKey: "state", firstValue: state);
    else
      v4 = nullptr;
    this->PostActionSignal(this, a2: v4);
    vgui::Button::SetSelected(this, state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398410
// Name: public: virtual void vgui::CheckButton::SetCheckButtonCheckable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::SetCheckButtonCheckable(vgui::CheckButton *this, bool state)
{
  vgui::CheckButton_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_bCheckButtonCheckable = state;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x103984A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103984D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x103984E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398550
// Name: protected: virtual void vgui::CheckButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CheckButton::ApplySchemeSettings(vgui::CheckButton *this, vgui::IScheme pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::CheckButton_vtbl *v4; // ebx
  Color *v5; // eax
  Color *(__thiscall *GetSchemeColor)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v7)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  Color *(__thiscall *v8)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v9; // eax
  Color *(__thiscall *GetSchemeColor_2)(vgui::Panel *, Color *, const char *, vgui::IScheme *); // edx
  _DWORD *v11; // eax
  Color v12; // ecx
  Color *(__thiscall *v13)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *v14)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // edx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v16; // eax
  vgui::CheckButton_vtbl *v17; // eax
  Color *(__thiscall *v18)(vgui::Panel *, Color *); // edx
  _DWORD *v19; // eax
  Color *(__thiscall *v20)(vgui::Panel *, Color *, const char *, Color, vgui::IScheme *); // eax
  vgui::CheckButton_vtbl *v21; // eax
  CheckImage_vtbl *v22; // ebx
  bool v23; // al
  int v24; // eax
  Color v25; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v26[4]; // [esp+10h] [ebp-Ch] BYREF
  Color bgDepressedColor; // [esp+14h] [ebp-8h] BYREF
  Color bgArmedColor; // [esp+18h] [ebp-4h] BYREF

  v2 = (vgui::IScheme *)pScheme.__vftable;
  vgui::ToggleButton::ApplySchemeSettings(this, pScheme: (vgui::IScheme *)pScheme.__vftable);
  v4 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->GetBgColor(this, result: v26);
  v5 = this->GetSchemeColor_2(this, result: &v25, a3: "CheckButton.TextColor", a4: v2);
  ((void (__thiscall *)(vgui::CheckButton *, _DWORD, vgui::IScheme_vtbl *))v4->SetDefaultColor)(
    a1: this,
    a2: *v5,
    a3: pScheme.dtr_IBaseInterface);
  GetSchemeColor = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_checkBoxImage->_bgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))GetSchemeColor)(
                                               a1: this,
                                               a2: &pScheme,
                                               a3: "CheckButton.BgColor",
                                               a4: -13154754,
                                               a5: v2);
  v7 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_borderColor1 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v7)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border1",
                                                    a4: -15461356,
                                                    a5: v2);
  v8 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-10855846;
  this->_checkBoxImage->_borderColor2 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v8)(
                                                    a1: this,
                                                    a2: &pScheme,
                                                    a3: "CheckButton.Border2",
                                                    a4: -10855846,
                                                    a5: v2);
  v9 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-15461356;
  this->_checkBoxImage->_checkColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v9->GetSchemeColor)(
                                                  a1: this,
                                                  a2: &pScheme,
                                                  a3: "CheckButton.Check",
                                                  a4: -15461356,
                                                  a5: v2);
  GetSchemeColor_2 = this->GetSchemeColor_2;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v11 = (_DWORD *)GetSchemeColor_2(this, result: &v25, a3: "ControlText", a4: v2);
  v12 = *(Color *)((int (__thiscall *)(vgui::CheckButton *, _BYTE *, const char *, _DWORD, vgui::IScheme *))pScheme.__vftable[10].GetName)(
                    a1: this,
                    a2: v26,
                    a3: "CheckButton.SelectedTextColor",
                    a4: *v11,
                    a5: v2);
  pScheme.__vftable = (vgui::IScheme_vtbl *)-8224126;
  this->_selectedFgColor = v12;
  this->_disabledFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))this->GetSchemeColor)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledFgColor",
                                       a4: -8224126,
                                       a5: v2);
  v13 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_disabledBgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v13)(
                                       a1: this,
                                       a2: &pScheme,
                                       a3: "CheckButton.DisabledBgColor",
                                       a4: -13154754,
                                       a5: v2);
  v14 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v14)(
    a1: this,
    a2: &bgArmedColor,
    a3: "CheckButton.ArmedBgColor",
    a4: -13154754,
    a5: v2);
  GetFgColor = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v16 = (_DWORD *)GetFgColor(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].dtr_IBaseInterface)(
    a1: this,
    a2: *v16,
    a3: bgArmedColor);
  v17 = this->__vftable;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  ((void (__thiscall *)(vgui::CheckButton *, Color *, const char *, int, vgui::IScheme *))v17->GetSchemeColor)(
    a1: this,
    a2: &bgDepressedColor,
    a3: "CheckButton.DepressedBgColor",
    a4: -13154754,
    a5: v2);
  v18 = this->GetFgColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)this->__vftable;
  v19 = (_DWORD *)v18(this, result: &v25);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))pScheme.__vftable[34].GetResourceString)(
    a1: this,
    a2: *v19,
    a3: bgDepressedColor);
  v20 = this->GetSchemeColor;
  pScheme.__vftable = (vgui::IScheme_vtbl *)-13154754;
  this->_highlightFgColor = *(Color *)((int (__thiscall *)(vgui::CheckButton *, vgui::IScheme *, const char *, int, vgui::IScheme *))v20)(
                                        a1: this,
                                        a2: &pScheme,
                                        a3: "CheckButton.HighlightFgColor",
                                        a4: -13154754,
                                        a5: v2);
  this->SetContentAlignment(this, a2: a_west);
  v21 = this->__vftable;
  v22 = this->_checkBoxImage->__vftable;
  pScheme.__vftable = v2->__vftable;
  v23 = v21->IsProportional(this);
  v24 = pScheme.GetFont(this: v2, a2: "Marlett", a3: v23);
  v22->SetFont(this: this->_checkBoxImage, a2: v24);
  vgui::TextImage::ResizeImageToContent(this: this->_checkBoxImage);
  this->SetImageAtIndex(this, a2: 0, a3: this->_checkBoxImage, a4: 6);
  this->SetPaintBackgroundEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10398820
// Name: public: static void vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuItem::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "CheckButtonChecked";
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
// Address: 0x103988C0
// Name: public: vgui::CheckButton::CheckButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__thiscall vgui::CheckButton::CheckButton(
        vgui::CheckButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextImage *v8; // eax
  CheckImage *v9; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::ToggleButton::ToggleButton(this, parent, panelName, text);
  this->__vftable = (vgui::CheckButton_vtbl *)&vgui::CheckButton::`vftable';
  if ( `vgui::CheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
    v5->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CheckButton");
    v6->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "ToggleButton");
  }
  if ( `vgui::CheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CheckButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
    v7->pfnClassName = vgui::CheckButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ToggleButton");
  }
  vgui::CheckButton::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->_selectedFgColor = 0;
  this->_disabledFgColor = 0;
  this->_disabledBgColor = 0;
  this->_highlightFgColor = 0;
  vgui::Label::SetContentAlignment(this, alignment: a_west);
  this->m_bCheckButtonCheckable = true;
  v8 = (vgui::TextImage *)operator new(nSize: 0x94u);
  v9 = (CheckImage *)v8;
  if ( v8 != nullptr )
  {
    vgui::TextImage::TextImage(this: v8, text: "g");
    v9->__vftable = (CheckImage_vtbl *)&CheckImage::`vftable';
    v9->_borderColor1 = 0;
    v9->_borderColor2 = 0;
    v9->_checkColor = 0;
    v9->_bgColor = 0;
    v9->_CheckButton = this;
    v9->_drawMode = 0;
    vgui::TextImage::SetSize(this: v9, wide: 20, tall: 13);
  }
  else
  {
    v9 = nullptr;
  }
  this->_checkBoxImage = v9;
  vgui::Label::SetTextImageIndex(this, newIndex: 1);
  vgui::Label::SetImageAtIndex(this, index: 0, image: this->_checkBoxImage, offset: 6);
  this->_selectedFgColor = (Color)-11487804;
  this->_disabledFgColor = (Color)-8224126;
  this->_disabledBgColor = (Color)-13154754;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10398A60
// Name: Create_CheckButton
// Source: json
//------------------------------------------------------------------------------
vgui::CheckButton *__cdecl Create_CheckButton()
{
  vgui::CheckButton *v0; // eax

  v0 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v0 != nullptr )
    return vgui::CheckButton::CheckButton(this: v0, parent: nullptr, panelName: nullptr, text: "CheckButton");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103CC2C0
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398430
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Color *__thiscall vgui::CheckButton::GetButtonFgColor(vgui::CheckButton *this, Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, result);
    return result;
  }
}

} // namespace server
