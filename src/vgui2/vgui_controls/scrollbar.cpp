// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/scrollbar.cpp
// Functions: 39
// ============================================================

#include "vgui2\vgui_controls\scrollbar.h"

//------------------------------------------------------------------------------
// Address: 0x1020A740
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x102BF9B0
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x102BF9C0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x102BFC40
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BFCF0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFD20
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFD50
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFD80
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BFF70
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x102BFF90
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102BFFA0
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x102BFFC0
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x102BFFF0
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0040
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0090
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C00C0
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x102C00D0
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102C00E0
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102C00F0
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0180
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x102C01A0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0200
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x102C0210
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C02B0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0310
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C0340
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x102C0350
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x102C0370
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102C0380
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0400
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0440
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C04E0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0690
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0730
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C07D0
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0830
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar();
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar();
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0BD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0C00
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C0C10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x1002E7B0
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Button::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Button::GetUnpackStructure(vgui::Button *this)
{
  return vgui::Button::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x10030E20
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x1003CE60
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  __m128 v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      cBlendedColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      cBlendedColor = this->_armedFgColor;
    }
    else
    {
      cBlendedColor = this->_defaultFgColor;
    }
    v4 = 0;
    v4.m128_f32[0] = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[0] * v6));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[1] * v6));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[2] * v6));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[3] * v6));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1003D000
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonBgColor(vgui::Button *this, Color *result)
{
  Color *v2; // eax

  if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
  {
    *result = this->_depressedBgColor;
    return result;
  }
  else
  {
    v2 = result;
    if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
      *result = this->_armedBgColor;
    else
      *result = this->_defaultBgColor;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1005AE60
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x1005AE70
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x1005B0F0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  unsigned int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, unsigned int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B1A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1005B1D0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1005B200
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1005B230
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B420
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x1005B440
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1005B450
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x1005B470
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x1005B490
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B4E0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B530
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B560
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x1005B570
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1005B580
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1005B590
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B620
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x1005B640
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1005B6A0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x1005B6B0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B750
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B7B0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1005B7E0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x1005B7F0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x1005B810
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1005B820
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B8A0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B8E0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005B980
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BB30
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BBD0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BC70
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005BCD0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005C070
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1005C0A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x1005C0B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x00441660
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00441670
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x004418F0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x004419A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004419D0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00441A00
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00441A30
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441C20
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00441C40
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00441C50
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00441C70
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00441C90
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441CE0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441D30
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441D60
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00441D70
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00441D80
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00441D90
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441E20
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00441E40
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00441EA0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00441EB0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441F50
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441FB0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00441FE0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00441FF0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00442010
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00442020
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004420A0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004420E0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442180
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442330
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004423D0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442470
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004424D0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00442870
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004428A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x004428B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10036B00
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Button::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Button::GetUnpackStructure(vgui::Button *this)
{
  return vgui::Button::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x100378F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x10054230
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  __m128 v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      cBlendedColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      cBlendedColor = this->_armedFgColor;
    }
    else
    {
      cBlendedColor = this->_defaultFgColor;
    }
    v4 = 0;
    v4.m128_f32[0] = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[0] * v6));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[1] * v6));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[2] * v6));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[3] * v6));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100543D0
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonBgColor(vgui::Button *this, Color *result)
{
  Color *v2; // eax

  if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
  {
    *result = this->_depressedBgColor;
    return result;
  }
  else
  {
    v2 = result;
    if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
      *result = this->_armedBgColor;
    else
      *result = this->_defaultBgColor;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10071120
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x10071130
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x100713B0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10071460
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10071490
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100714C0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100714F0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100716E0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x10071700
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10071710
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x10071730
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x10071750
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100717A0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100717F0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10071820
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x10071830
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10071840
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10071850
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100718E0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x10071900
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10071960
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x10071970
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071A10
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071A70
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10071AA0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x10071AB0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x10071AD0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10071AE0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071B60
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071BA0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071C40
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071E20
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071EC0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071F60
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10071FD0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10072370
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100723A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x100723B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00619570
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00619580
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x00619790
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00619840
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00619870
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x006198A0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x006198D0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00619AC0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00619AE0
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00619AF0
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00619B10
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00619B30
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619B80
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619BD0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00619C00
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00619C10
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00619C20
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00619C30
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00619CC0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00619CE0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00619D40
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00619D50
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619DF0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619E50
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00619E80
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00619E90
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00619EB0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00619EC0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619F40
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00619F80
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061A020
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061A1D0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061A270
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061A310
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0061A370
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: (void **)"ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0061A710
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061A740
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x0061A750
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1020A880
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x102BFA90
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x102BFAA0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x102BFDD0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFE00
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFE30
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x102BFE60
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0050
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x102C0070
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102C0080
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x102C00A0
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x102C0110
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0160
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0190
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x102C01B0
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x102C01C0
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C0250
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x102C0270
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C02D0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x102C02E0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C03E0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C0410
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x102C0420
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x102C0450
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C04D0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0510
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C05B0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0760
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0800
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C08A0
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C0900
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0CA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0CD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C0CE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10305430
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x10305440
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x103056C0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10305770
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103057A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103057D0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10305800
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103059F0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x10305A10
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10305A20
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x10305A40
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x10305A60
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305AB0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305B00
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10305B30
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x10305B40
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10305B50
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10305B60
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10305BF0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x10305C10
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10305C70
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x10305C80
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305D20
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305D80
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10305DB0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x10305DC0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x10305DE0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10305DF0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305E70
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305EB0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10305F50
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306130
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103061D0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10306270
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103062D0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10306670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103066A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x103066B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034889A
// Name: public: virtual int CScrollBar::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CScrollBar::Create(
        CScrollBar *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "SCROLLBAR", a3: nullptr, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103488BD
// Name: public: virtual CScrollBar::~CScrollBar(void)
// Source: class_map
//------------------------------------------------------------------------------
void __thiscall CScrollBar::~CScrollBar(CScrollBar *this)
{
  this->__vftable = (CScrollBar_vtbl *)&CScrollBar::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034890C
// Name: public: virtual struct CRuntimeClass __near * CScrollBar::GetRuntimeClass(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CScrollBar::GetRuntimeClass(CScrollBar *this)
{
  return &CScrollBar::classCScrollBar;
}

//------------------------------------------------------------------------------
// Address: 0x103AA5B2
// Name: public: class CMFCToolBarButton __near * CMFCToolBar::GetButton(int)const
// Source: json
//------------------------------------------------------------------------------
__POSITION *__thiscall CMFCToolBar::GetButton(CMFCToolBar *this, int nIndex)
{
  __POSITION *result; // eax

  result = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_Buttons, nIndex);
  if ( result != nullptr )
  {
    result = *(__POSITION **)&result[8];
    if ( result == nullptr )
      AfxThrowInvalidArgException();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AA5DA
// Name: public: virtual int CMFCToolBar::HitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::HitTest(CMFCToolBar *this, CPoint point)
{
  CObList::CNode *m_pNodeHead; // esi
  int i; // ebx
  CObject *data; // edi

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  for ( i = 0; ; ++i )
  {
    if ( m_pNodeHead == nullptr )
      return -1;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( PtInRect(lprc: (const RECT *)&data[21], pt: point.tagPOINT) && data[16].__vftable == nullptr )
      break;
  }
  if ( ((int)data[9].__vftable & 1) != 0 )
    return -1;
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x103AA633
// Name: protected: void CMFCToolBar::UpdateImagesColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::UpdateImagesColor(CMFCToolBar *this)
{
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_Images);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_ColdImages);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_ImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_ColdImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_MenuImages);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_DisabledMenuImages);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_MenuImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_DisabledImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_DisabledMenuImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_LargeImages);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_LargeColdImages);
  CMFCToolBarImages::OnSysColorChange(this: &CMFCToolBar::m_LargeDisabledImages);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_LargeImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_LargeColdImagesLocked);
  CMFCToolBarImages::OnSysColorChange(this: &this->m_LargeDisabledImagesLocked);
}

//------------------------------------------------------------------------------
// Address: 0x103AA6D7
// Name: public: virtual void CMFCToolBarCmdUI::SetRadio(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarCmdUI::SetRadio(CMFCToolBarCmdUI *this, int bOn)
{
  CMFCToolBar *m_pOther; // ecx
  __POSITION *Button; // eax

  this->SetCheck(this, a2: bOn != 0);
  m_pOther = (CMFCToolBar *)this->m_pOther;
  if ( m_pOther == nullptr )
    AfxThrowInvalidArgException();
  Button = CMFCToolBar::GetButton(this: m_pOther, nIndex: this->m_nIndex);
  (*(void (__thiscall **)(__POSITION *))(*(_DWORD *)Button + 192))(a1: Button);
}

//------------------------------------------------------------------------------
// Address: 0x103AA712
// Name: public: void CMFCToolBar::UpdateButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::UpdateButton(CMFCToolBar *this, int nIndex)
{
  CWnd *v3; // ebx
  __POSITION *Button; // eax
  __POSITION *v5; // esi
  unsigned int v6; // eax
  CWnd_vtbl *v7; // edi
  unsigned int v8; // esi
  int v9; // eax
  CMFCToolBarCmdUI state; // [esp+8h] [ebp-28h] BYREF

  v3 = this->GetCommandTarget(this);
  if ( v3 != nullptr )
  {
    CCmdUI::CCmdUI(this: &state);
    state.m_nIndexMax = this->m_Buttons.m_nCount;
    state.__vftable = (CMFCToolBarCmdUI_vtbl *)&CMFCToolBarCmdUI::`vftable';
    state.m_pOther = this;
    state.m_nIndex = nIndex;
    Button = CMFCToolBar::GetButton(this, nIndex);
    v5 = Button;
    if ( Button != nullptr )
    {
      v6 = *(_DWORD *)&Button[32];
      if ( v6 != 0 && v6 - 61440 > 0x1EF && v6 < 0xFF00 )
      {
        v7 = nullptr;
        if ( v3->IsFrameWnd(this: v3) != 0 )
          v7 = v3[1].__vftable;
        state.m_nID = *(_DWORD *)&v5[32];
        v9 = false;
        if ( v7 != nullptr
          && (afxUserToolsManager == nullptr
           || (v8 = *(_DWORD *)&v5[32]) < afxUserToolsManager->m_uiCmdFirst
           || v8 > afxUserToolsManager->m_uiCmdLast) )
        {
          v9 = true;
        }
        CCmdUI::DoUpdate(this: &state, pTarget: v3, bDisableIfNoHndler: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AA7C7
// Name: protected: virtual unsigned long CMFCToolBar::OnDragEnter(class COleDataObject __near *,unsigned long,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCToolBar::OnDragEnter(
        CMFCToolBar *this,
        COleDataObject *pDataObject,
        unsigned int dwKeyState,
        CPoint point)
{
  if ( this->m_bDisableCustomize != 0 )
    return 0;
  this->m_iDragIndex = -1;
  CMFCToolBar::m_DropSource.m_bDeleteOnDrop = 0;
  return ((unsigned int (__thiscall *)(CMFCToolBar *, COleDataObject *, unsigned int, int, int))this->OnDragOver)(
           a1: this,
           a2: pDataObject,
           a3: dwKeyState,
           a4: point.x,
           a5: point.y);
}

//------------------------------------------------------------------------------
// Address: 0x103AA7FF
// Name: public: static int CMFCToolBar::GetCommandButtons(unsigned int,class CObList __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBar::GetCommandButtons(CObject_vtbl *uiCmd, CObList *listButtons)
{
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // esi
  CObject_vtbl *v5; // esi
  CObject *Serialize; // eax

  CObList::RemoveAll(this: listButtons);
  if ( uiCmd == nullptr )
    return 0;
  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    if ( m_pNodeHead == nullptr || (data = m_pNodeHead->data, m_pNodeHead = m_pNodeHead->pNext, data == nullptr) )
      AfxThrowInvalidArgException();
    if ( CWnd::FromHandlePermanent(hWnd: (CDocument *)data[8].__vftable) != nullptr )
    {
      v5 = data[755].__vftable;
      while ( v5 != nullptr )
      {
        Serialize = (CObject *)v5->Serialize;
        v5 = (CObject_vtbl *)v5->GetRuntimeClass;
        if ( Serialize == nullptr )
          break;
        if ( Serialize[8].__vftable == uiCmd )
          CPtrList::AddTail(this: listButtons, newElement: Serialize);
      }
    }
  }
  return listButtons->m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x103AA87F
// Name: protected: virtual void CMFCToolBar::DrawDragCursor(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::DrawDragCursor(CMFCToolBar *this, CDC *pDC)
{
  BOOL v3; // ebx
  int i; // edi
  CPoint v5; // [esp+Ch] [ebp-34h] BYREF
  CPoint v6; // [esp+14h] [ebp-2Ch] BYREF
  CPoint v7; // [esp+1Ch] [ebp-24h] BYREF
  CPoint v8; // [esp+24h] [ebp-1Ch] BYREF
  CPoint v9; // [esp+2Ch] [ebp-14h] BYREF
  CPoint result; // [esp+34h] [ebp-Ch] BYREF
  CPen *pOldPen; // [esp+3Ch] [ebp-4h]

  v3 = (this->GetCurrentAlignment(this) & 0xA000) != 0;
  pOldPen = (CPen *)CDC::SelectObject(this: pDC, pFont: (CFont *)&this->m_penDrag);
  for ( i = 0; i < 2; ++i )
  {
    if ( v3 )
    {
      CDC::MoveTo(
        this: pDC,
        &result,
        x: this->m_rectDrag.left + (this->m_rectDrag.right - this->m_rectDrag.left) / 2 + i - 1,
        y: this->m_rectDrag.top);
      CDC::LineTo(
        this: pDC,
        x: this->m_rectDrag.left + (this->m_rectDrag.right - this->m_rectDrag.left) / 2 + i - 1,
        y: this->m_rectDrag.bottom);
      CDC::MoveTo(this: pDC, result: &v9, x: i + this->m_rectDrag.left, y: i + this->m_rectDrag.top);
      CDC::LineTo(this: pDC, x: this->m_rectDrag.right - i, y: i + this->m_rectDrag.top);
      CDC::MoveTo(this: pDC, result: &v8, x: i + this->m_rectDrag.left, y: this->m_rectDrag.bottom - i - 1);
      CDC::LineTo(this: pDC, x: this->m_rectDrag.right - i, y: this->m_rectDrag.bottom - i - 1);
    }
    else
    {
      CDC::MoveTo(
        this: pDC,
        result: &v7,
        x: this->m_rectDrag.left,
        y: this->m_rectDrag.top + (this->m_rectDrag.bottom - this->m_rectDrag.top) / 2 + i - 1);
      CDC::LineTo(
        this: pDC,
        x: this->m_rectDrag.right,
        y: this->m_rectDrag.top + (this->m_rectDrag.bottom - this->m_rectDrag.top) / 2 + i - 1);
      CDC::MoveTo(this: pDC, result: &v6, x: i + this->m_rectDrag.left, y: i + this->m_rectDrag.top);
      CDC::LineTo(this: pDC, x: i + this->m_rectDrag.left, y: this->m_rectDrag.bottom - i);
      CDC::MoveTo(this: pDC, result: &v5, x: this->m_rectDrag.right - i - 1, y: i + this->m_rectDrag.top);
      CDC::LineTo(this: pDC, x: this->m_rectDrag.right - i - 1, y: this->m_rectDrag.bottom - i);
    }
  }
  CDC::SelectObject(this: pDC, pFont: (CFont *)pOldPen);
}

//------------------------------------------------------------------------------
// Address: 0x103AAA63
// Name: protected: void CMFCToolBar::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnDestroy(CMFCToolBar *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi
  __POSITION *posSave; // [esp+8h] [ebp-4h]

  CGdiObject::DeleteObject(this: &this->m_penDrag);
  CTooltipManager::DeleteToolTip(pToolTip: &this->m_pToolTip);
  CPane::OnDestroy(this);
  if ( CMFCToolBar::m_pSelToolbar == this )
    CMFCToolBar::m_pSelToolbar = nullptr;
  m_pNodeHead = afxAllToolBars.m_pNodeHead;
  if ( afxAllToolBars.m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      posSave = (__POSITION *)m_pNodeHead;
      if ( m_pNodeHead == nullptr || (data = m_pNodeHead->data, m_pNodeHead = m_pNodeHead->pNext, data == nullptr) )
        AfxThrowInvalidArgException();
      if ( CWnd::FromHandlePermanent(hWnd: (CDocument *)data[8].__vftable) != nullptr && data == this )
        break;
      if ( m_pNodeHead == nullptr )
        return;
    }
    CPtrList::RemoveAt(this: &afxAllToolBars, position: posSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AAAE4
// Name: protected: void CMFCToolBar::OnToolbarDelete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarDelete(CMFCToolBar *this)
{
  this->RemoveButton(this, a2: this->m_iSelected);
  this->m_iSelected = -1;
  this->OnAfterButtonDelete(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AAB0B
// Name: protected: virtual void CMFCToolBar::OnAfterButtonDelete(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnAfterButtonDelete(CMFCToolBar *this)
{
  bool v2; // zf
  CMFCToolBar_vtbl *v3; // eax

  v2 = this->IsFloating(this) == 0;
  v3 = this->__vftable;
  if ( v2 )
    v3->AdjustSizeImmediate(this, a2: 1);
  else
    v3->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AAB31
// Name: protected: void CMFCToolBar::OnToolbarImage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarImage(CMFCToolBar *this)
{
  __POSITION *Button; // eax
  CMFCToolBarButton *v3; // esi
  int v4; // eax
  bool v5; // zf
  int m_iImage; // eax
  int v7; // eax
  int v8; // eax
  int v9; // [esp+10h] [ebp-4E8h]
  int m_bImage; // [esp+14h] [ebp-4E4h]
  CMFCToolBarButtonCustomizeDialog v11; // [esp+18h] [ebp-4E0h] BYREF
  int v12; // [esp+4F4h] [ebp-4h]

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  v3 = (CMFCToolBarButton *)Button;
  if ( Button != nullptr )
  {
    v4 = *(_DWORD *)&Button[8];
    v3->m_bText = 0;
    v5 = v3->m_bUserButton == 0;
    v9 = v4;
    m_bImage = v3->m_bImage;
    v3->m_bImage = 1;
    if ( v5 )
      m_iImage = v3->m_iImage;
    else
      m_iImage = v3->m_iUserImage;
    if ( m_iImage < 0 )
    {
      v7 = this->IsPureMenuButton(this, a2: v3);
      CMFCToolBarButtonCustomizeDialog::CMFCToolBarButtonCustomizeDialog(
        this: &v11,
        pButton: v3,
        pImages: CMFCToolBar::m_pUserImages,
        pParent: this,
        iStartImage: 0,
        bMenuMode: v7);
      v12 = 0;
      v8 = CDialog::DoModal(this: &v11);
      v12 = -1;
      if ( v8 != 1 )
      {
        v3->m_bText = v9;
        v3->m_bImage = m_bImage;
        CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v11);
        return;
      }
      CMFCToolBarButtonCustomizeDialog::~CMFCToolBarButtonCustomizeDialog(this: &v11);
    }
    this->AdjustLayout(this);
    this->AdjustSizeImmediate(this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AABFF
// Name: protected: void CMFCToolBar::OnToolbarStartGroup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnToolbarStartGroup(CMFCToolBar *this)
{
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // ecx
  int v4; // edx
  CObList::CNode *v5; // edi
  CMFCToolBar_vtbl *v6; // eax
  int m_iSelected; // [esp-8h] [ebp-Ch]

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  data = nullptr;
  v4 = 0;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v5 = m_pNodeHead;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( v4 == this->m_iSelected )
        break;
      data = v5->data;
      ++v4;
      if ( m_pNodeHead == nullptr )
        goto LABEL_11;
    }
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( ((int)data[9].__vftable & 1) != 0 )
    {
      if ( data[20].__vftable != nullptr )
        this->RemoveButton(this, a2: this->m_iSelected - 1);
    }
    else
    {
      v6 = this->__vftable;
      m_iSelected = this->m_iSelected;
      this->m_iSelected = m_iSelected + 1;
      v6->InsertSeparator(this, a2: m_iSelected);
    }
  }
LABEL_11:
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AAC7C
// Name: public: int CMFCToolBar::GetCount(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::GetCount(CMFCToolBar *this)
{
  return this->m_Buttons.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x103AAC83
// Name: protected: virtual int CMFCToolBar::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnCommand(CMFCToolBar *this, unsigned int wParam, HWND__ *lParam)
{
  unsigned int v5; // edi
  CObList::CNode *m_pNodeHead; // esi
  CMFCToolBarButton *data; // ebx
  HWND v8; // eax
  int bAccelerator; // [esp+Ch] [ebp-8h]
  HWND__ *hWndCtrl; // [esp+10h] [ebp-4h]

  if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bLocked == 0 )
    return CWnd::OnCommand(this, wParam, lParam);
  v5 = HIWORD(wParam);
  bAccelerator = 0;
  hWndCtrl = lParam;
  if ( lParam != nullptr )
    goto LABEL_10;
  if ( wParam != 2 )
  {
    if ( wParam != 1 )
      return 0;
    hWndCtrl = GetFocus();
    if ( hWndCtrl == nullptr )
      return 0;
    bAccelerator = 1;
    v5 = 0;
LABEL_10:
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    if ( m_pNodeHead != nullptr )
    {
      while ( 1 )
      {
        data = (CMFCToolBarButton *)m_pNodeHead->data;
        m_pNodeHead = m_pNodeHead->pNext;
        v8 = data->GetHwnd(this: data);
        if ( v8 != nullptr && (v8 == hWndCtrl || IsChild(hWndParent: v8, hWnd: hWndCtrl)) )
          break;
        if ( m_pNodeHead == nullptr )
          return 0;
      }
      if ( this->NotifyControlCommand(this, a2: data, a3: bAccelerator, a4: v5, a5: wParam, a6: (int)lParam) != 0 )
        return 1;
    }
    return 0;
  }
  this->RestoreFocus(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AAD55
// Name: public: virtual class CSize CMFCToolBar::CalcSize(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolBar::CalcSize(CMFCToolBar *this, CSize *result, int bVertDock)
{
  CFont *v5; // eax
  CObList::CNode *m_pNodeHead; // eax
  CObject *data; // edi
  CObList::CNode *pNext; // eax
  int cy; // eax
  int *v10; // eax
  int v11; // ecx
  int m_nMaxBtnHeight; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  CSize *v17; // esi
  CSize v18; // [esp+10h] [ebp-80h] BYREF
  char v19[8]; // [esp+18h] [ebp-78h] BYREF
  int v20; // [esp+20h] [ebp-70h]
  CClientDC v21; // [esp+28h] [ebp-68h] BYREF
  _DWORD v22[2]; // [esp+3Ch] [ebp-54h] BYREF
  int v23; // [esp+44h] [ebp-4Ch]
  BOOL v24; // [esp+48h] [ebp-48h]
  CSize *v25; // [esp+4Ch] [ebp-44h]
  CObList::CNode *v26; // [esp+50h] [ebp-40h]
  int v27; // [esp+54h] [ebp-3Ch]
  int v28; // [esp+58h] [ebp-38h]
  CFont *pFont; // [esp+5Ch] [ebp-34h]
  int v30; // [esp+60h] [ebp-30h]
  int v31; // [esp+64h] [ebp-2Ch]
  int v32; // [esp+68h] [ebp-28h]
  BOOL v33; // [esp+6Ch] [ebp-24h]
  tagRECT rc; // [esp+70h] [ebp-20h] BYREF
  int v35; // [esp+8Ch] [ebp-4h]

  v25 = result;
  v23 = bVertDock;
  if ( this->m_Buttons.m_nCount == 0 )
  {
    CMFCToolBar::GetButtonSize(this, a2: (int)this, result);
    return v25;
  }
  CClientDC::CClientDC(this: &v21, pWnd: this);
  v35 = 0;
  if ( bVertDock != 0 )
    v5 = CDC::SelectObject(this: &v21, pFont: &afxGlobalData.fontVert);
  else
    v5 = CBasePane::SelectDefaultFont(this, pDC: &v21);
  pFont = v5;
  if ( v5 == nullptr )
    AfxThrowInvalidArgException();
  v27 = this->GetRowHeight(this);
  v20 = this->GetColumnWidth(this);
  v30 = v20;
  v31 = v27;
  memset(&rc, 0, sizeof(rc));
  SetRectEmpty(lprc: &rc);
  v24 = bVertDock == 0;
  CPane::CalcInsideRect(this, rect: (CRect *)&rc, bHorz: v24);
  v28 = bVertDock == 0;
  v32 = v28;
  v33 = bVertDock != 0;
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      pNext = m_pNodeHead->pNext;
      v26 = pNext;
      if ( data == nullptr || pNext == nullptr && this->m_pCustomizeBtn != nullptr && this->IsFloating(this) != 0 )
        goto LABEL_38;
      if ( this->m_bDrawTextLabels != 0 )
        cy = CMFCToolBar::GetButtonSize(this, a2: (int)this, result: &v18)->cy;
      else
        cy = v27;
      v22[0] = v20;
      v22[1] = cy;
      v10 = (int *)((int (__thiscall *)(CObject *, char *, CClientDC *, _DWORD *, BOOL))data->__vftable[2].dtr_CObject)(
                     a1: data,
                     a2: v19,
                     a3: &v21,
                     a4: v22,
                     a5: v24);
      v11 = *v10;
      m_nMaxBtnHeight = v10[1];
      if ( this->m_bDrawTextLabels != 0 )
        m_nMaxBtnHeight = this->m_nMaxBtnHeight;
      if ( v23 != 0 )
        break;
      if ( (v32 == v28 || data[4].__vftable != nullptr) && ((int)data[9].__vftable & 1) != 0 )
      {
        v11 = 0;
        m_nMaxBtnHeight = 0;
      }
      v13 = v32 + v11;
      if ( v13 > v30 )
        v30 = v13;
      v14 = v33 + m_nMaxBtnHeight;
      if ( v14 > v31 )
        v31 = v14;
      v32 = v13;
      if ( data[4].__vftable != nullptr )
      {
        v32 = v28;
        v15 = v33 + v27 + 5;
LABEL_36:
        v33 = v15;
      }
      if ( v26 == nullptr )
        goto LABEL_38;
      m_pNodeHead = v26;
    }
    v16 = v32 + v11;
    if ( v16 > v30 )
      v30 = v16;
    v15 = v33 + m_nMaxBtnHeight;
    if ( v15 > v31 )
      v31 = v15;
    v32 = v28;
    goto LABEL_36;
  }
LABEL_38:
  CDC::SelectObject(this: &v21, pFont);
  v17 = v25;
  v35 = -1;
  v25->cx = v30;
  v17->cy = v31;
  CClientDC::~CClientDC(this: &v21);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x103AAF67
// Name: protected: virtual void CMFCToolBar::DrawSeparator(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::DrawSeparator(CMFCToolBar *this, CDC *pDC, const CRect *rect, int bHorz)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBar *, int, int, int, int, int))Instance->OnDrawSeparator)(
    a1: Instance,
    a2: pDC,
    a3: this,
    a4: rect->left,
    a5: rect->top,
    a6: rect->right,
    a7: rect->bottom,
    a8: bHorz);
}

//------------------------------------------------------------------------------
// Address: 0x103AAF97
// Name: public: class CMFCToolBarButton __near * CMFCToolBar::GetHighlightedButton(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__POSITION *__thiscall CMFCToolBar::GetHighlightedButton(CMFCToolBar *this)
{
  if ( this->m_iHighlighted >= 0 )
    return CMFCToolBar::GetButton(this, nIndex: this->m_iHighlighted);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103AAFAB
// Name: protected: virtual void CMFCToolBar::OnCustomizeMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnCustomizeMode(CMFCToolBar *this, int bSet)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi

  this->m_iButtonCapture = -1;
  this->m_iHighlighted = -1;
  this->m_iSelected = -1;
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    data->__vftable[7].dtr_CObject(this: data);
    if ( ((int)data[9].__vftable & 0x40000) == 0 )
      data->__vftable[12].Serialize(this: data, a2: (CArchive *)(bSet == 0));
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB013
// Name: public: virtual int CMFCToolBar::CanBeRestored(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::CanBeRestored(CMFCToolBar *this)
{
  return this->m_uiOriginalResID != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103AB01F
// Name: public: static unsigned long CMFCToolBar::GetHotTextColor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall CMFCToolBar::GetHotTextColor()
{
  unsigned int result; // eax

  result = CMFCToolBar::m_clrTextHot;
  if ( CMFCToolBar::m_clrTextHot == -1 )
    return afxGlobalData.clrBtnText;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB02F
// Name: protected: void CMFCToolBar::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnNcCalcSize(CMFCToolBar *this, int __formal, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CMFCControlBarImpl::CalcNcSize(this: &this->m_Impl, lpncsp);
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100B94D0
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x100B94E0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x100B96F0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B97A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100B97D0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100B9800
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100B9830
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9A20
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x100B9A40
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100B9A50
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x100B9A70
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x100B9A90
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9AE0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9B30
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9B60
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x100B9B70
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100B9B80
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100B9B90
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9C20
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x100B9C40
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B9CA0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x100B9CB0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9D50
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9DB0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100B9DE0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x100B9DF0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E10
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100B9E20
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9EA0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9EE0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9F80
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA130
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA1D0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA270
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA2D0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BA670
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA6A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x100BA6B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0043F290
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x00442DF0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  long double v6; // [esp+0h] [ebp-8h]
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      HIDWORD(v6) = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      HIDWORD(v6) = this->_armedFgColor;
    }
    else
    {
      HIDWORD(v6) = this->_defaultFgColor;
    }
    v4 = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(x: v6);
    v5 = (float)(v4 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[0] * v5));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[1] * v5));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[2] * v5));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[3] * v5));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00462030
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00462040
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x004622C0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00462370
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004623A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004623D0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00462400
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004625F0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00462610
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00462620
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00462640
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00462660
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004626B0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462700
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00462730
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00462740
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00462750
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00462760
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x004627F0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00462810
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00462870
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00462880
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462920
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462980
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004629B0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x004629C0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004629E0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x004629F0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462A70
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462AB0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462B50
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462D00
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462DA0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462E40
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462EA0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00463240
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00463270
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x00463280
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00402620
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Button::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Button::GetUnpackStructure(vgui::Button *this)
{
  return vgui::Button::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x004138A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x0042A450
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__userpurge vgui::Button::GetButtonFgColor@<eax>(vgui::Button *this@<ecx>, __m128i a2@<xmm0>, Color *result)
{
  Color *v4; // eax
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color depressedFgColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      depressedFgColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      depressedFgColor = this->_armedFgColor;
    }
    else
    {
      depressedFgColor = this->_defaultFgColor;
    }
    *(double *)a2.m128i_i64 = (float)((float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998);
    __libm_sse2_sin(X: a2);
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      depressedFgColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[0] * v6));
      depressedFgColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[1] * v6));
      depressedFgColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[2] * v6));
      depressedFgColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[3] * v6));
    }
    *result = depressedFgColor;
    return result;
  }
  else
  {
    v4 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0042A5D0
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonBgColor(vgui::Button *this, Color *result)
{
  Color *v2; // eax

  if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
  {
    *result = this->_depressedBgColor;
    return result;
  }
  else
  {
    v2 = result;
    if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
      *result = this->_armedBgColor;
    else
      *result = this->_defaultBgColor;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00448840
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00448850
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x00448AC0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  vgui::ISchemeManager_vtbl *v6; // ebp
  int v7; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      v6 = g_pVGuiSchemeManager->__vftable;
      v7 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v6->GetProportionalScaledValueEx)(a1: v5, a2: v7);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448B70
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448B90
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448BB0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00448BD0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  int v4; // eax
  int tall; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &tall, a3: &y);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: tall, wide: tall, tall: y - 2 * tall + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: y - tall, wide: tall, tall);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: y, y: 0, wide: tall - 2 * y + 1, tall: y);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: y, tall: y);
      vgui::Panel::SetBounds(this: this->_button[1], x: tall - y, y: 0, wide: y, tall: y);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x: v8, y: x, wide: tall, tall: y);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x: v8, y: x, wide: tall, tall: y);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pLine, x: v8, y: x, wide: tall, tall: y);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: tall, wide: tall, tall);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = ((int (__thiscall *)(vgui::ScrollBarSlider *))this->_slider->IsSliderVisible)(a1: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448DF0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00448E00
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00448E10
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00448E20
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00448E30
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448E80
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448ED0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448F00
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00448F10
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00448F20
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00448F30
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00448FC0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00448FD0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00449020
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00449030
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004490D0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449120
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00449160
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00449170
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00449180
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00449190
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  int i; // ebp
  bool v5; // al
  vgui::Panel *v6; // ecx
  int Tall; // eax

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v5 = this->_slider->IsVertical(this: this->_slider);
        v6 = *button;
        if ( v5 )
          Tall = vgui::Panel::GetTall(this: v6);
        else
          Tall = vgui::Panel::GetWide(this: v6);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449210
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449250
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004492F0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int min; // [esp+18h] [ebp-18h] BYREF
  int x; // [esp+1Ch] [ebp-14h] BYREF
  int w; // [esp+20h] [ebp-10h] BYREF
  int y; // [esp+24h] [ebp-Ch] BYREF
  int t; // [esp+28h] [ebp-8h] BYREF
  int tall; // [esp+2Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &x, a3: &w);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = w - v3;
    if ( w - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - x > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, x: &w, y: &t, wide: &y, &tall);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &x, a3: &min);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x: w, y: t + x, wide: y, tall: min - x);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: w + x, y: 0, wide: min - x, tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004494C0
// Name: public: static void vgui::ScrollBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ScrollBar::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
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
// Address: 0x00449540
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    vgui::ScrollBar::AddToMap(
      scriptname: "ScrollBarSliderMoved",
      function: (unsigned int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "position",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004495A0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    vgui::ScrollBar::AddToMap(
      scriptname: "ScrollBarSliderReleased",
      function: (unsigned int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "position",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449600
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449660
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // edi
  vgui::Button *v12; // eax
  vgui::Button *v13; // edi
  vgui::ScrollBarSlider *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // edi
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar();
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar();
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    vgui::ScrollBar::SetSlider(this, slider: v9);
    v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v11 = v10;
    if ( v10 != nullptr )
    {
      vgui::Button::Button(
        this: v10,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v11->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v11, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v11, alignment: a_center);
    }
    else
    {
      v11 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v11, index: 0);
    v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v13 = v12;
    if ( v12 != nullptr )
    {
      vgui::Button::Button(
        this: v12,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v13->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v13, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v13, alignment: a_center);
    }
    else
    {
      v13 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v13, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v14 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v14 = nullptr;
    vgui::ScrollBar::SetSlider(this, slider: v14);
    v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      vgui::Button::Button(
        this: v15,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v16->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v16, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v16, alignment: a_center);
    }
    else
    {
      v16 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v16, index: 0);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00449990
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004499C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x004499D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0060B440
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x00638DC0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  long double v6; // [esp+0h] [ebp-8h]
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      HIDWORD(v6) = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      HIDWORD(v6) = this->_armedFgColor;
    }
    else
    {
      HIDWORD(v6) = this->_defaultFgColor;
    }
    v4 = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(x: v6);
    v5 = (float)(v4 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[0] * v5));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[1] * v5));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[2] * v5));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[3] * v5));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0064FAB0
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x0064FAC0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x0064FCD0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x0064FD80
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0064FDB0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0064FDE0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0064FE10
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00650000
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00650020
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00650030
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00650050
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00650070
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006500C0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650110
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00650140
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00650150
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00650160
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00650170
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00650200
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00650220
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00650280
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650320
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650380
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x006503B0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x006503C0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x006503E0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x006503F0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650470
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006504B0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650550
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006506E0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650780
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650820
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650880
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00650C20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00650C50
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x00650C60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00666400
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x1000D740
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Button::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Button::GetUnpackStructure(vgui::Button *this)
{
  return vgui::Button::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x10020610
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x10049910
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004C780
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  __m128 v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      cBlendedColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      cBlendedColor = this->_armedFgColor;
    }
    else
    {
      cBlendedColor = this->_defaultFgColor;
    }
    v4 = 0;
    v4.m128_f32[0] = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[0] * v6));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[1] * v6));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[2] * v6));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[3] * v6));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004C920
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonBgColor(vgui::Button *this, Color *result)
{
  Color *v2; // eax

  if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
  {
    *result = this->_depressedBgColor;
    return result;
  }
  else
  {
    v2 = result;
    if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
      *result = this->_armedBgColor;
    else
      *result = this->_defaultBgColor;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1006CAF0
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x1006CB00
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x1006CD80
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE30
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE60
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1006CE90
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1006CEC0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006D0B0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x1006D0D0
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1006D0E0
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x1006D100
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x1006D120
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D170
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D1C0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006D1F0
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x1006D200
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1006D210
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1006D220
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006D2B0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x1006D2D0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006D330
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x1006D340
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D3E0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D440
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006D470
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x1006D480
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x1006D4A0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x1006D4B0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D530
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D570
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D610
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D7C0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D860
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D900
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D960
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006DD00
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006DD30
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x1006DD40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1007FD40
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x1007FD50
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x1007FF60
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080010
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10080040
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x10080070
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x100800A0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080290
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x100802B0
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100802C0
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x100802E0
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x10080300
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080350
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100803A0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x100803D0
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x100803E0
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x100803F0
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10080400
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080490
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x100804B0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080510
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x10080520
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100805C0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080620
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10080650
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x10080660
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x10080680
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x10080690
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080710
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080750
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100807F0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100809A0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080A40
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080AE0
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080B40
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10080EE0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080F10
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x10080F20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00451C90
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00451CA0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x00451F20
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00451FD0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00452000
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00452030
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00452060
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x00452250
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00452270
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00452280
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x004522A0
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x004522C0
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452310
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452360
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00452390
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x004523A0
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x004523B0
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x004523C0
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00452450
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00452470
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x004524D0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x004524E0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452580
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004525E0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00452610
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00452620
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00452640
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00452650
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004526D0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452710
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004527B0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452960
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452A00
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452AA0
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452B00
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00452EA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452ED0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x00452EE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0049A620
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x0049A630
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x0049A830
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  vgui::ISchemeManager_vtbl *v6; // ebp
  int v7; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      v6 = g_pVGuiSchemeManager->__vftable;
      v7 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v6->GetProportionalScaledValueEx)(a1: v5, a2: v7);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049A8E0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0049A900
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0049A920
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x0049A940
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  int v4; // eax
  int tall; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &tall, a3: &y);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: tall, wide: tall, tall: y - 2 * tall + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: y - tall, wide: tall, tall);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: y, y: 0, wide: tall - 2 * y + 1, tall: y);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: y, tall: y);
      vgui::Panel::SetBounds(this: this->_button[1], x: tall - y, y: 0, wide: y, tall: y);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x: v8, y: x, wide: tall, tall: y);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x: v8, y: x, wide: tall, tall: y);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, x: &v8, y: &x, wide: &tall, tall: &y);
      vgui::Panel::SetBounds(this: this->m_pLine, x: v8, y: x, wide: tall, tall: y);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: tall, wide: tall, tall);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = ((int (__thiscall *)(vgui::ScrollBarSlider *))this->_slider->IsSliderVisible)(a1: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049AB60
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x0049AB70
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x0049AB80
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x0049AB90
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x0049ABA0
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049ABF0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AC40
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049AC70
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x0049AC80
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x0049AC90
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x0049ACA0
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049AD30
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x0049AD40
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x0049AD90
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x0049ADA0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AE40
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AE90
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0049AED0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x0049AEE0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x0049AEF0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x0049AF00
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  int i; // ebp
  bool v5; // al
  vgui::Panel *v6; // ecx
  int Tall; // eax

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v5 = this->_slider->IsVertical(this: this->_slider);
        v6 = *button;
        if ( v5 )
          Tall = vgui::Panel::GetTall(this: v6);
        else
          Tall = vgui::Panel::GetWide(this: v6);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AF80
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AFC0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B060
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int min; // [esp+18h] [ebp-18h] BYREF
  int x; // [esp+1Ch] [ebp-14h] BYREF
  int w; // [esp+20h] [ebp-10h] BYREF
  int y; // [esp+24h] [ebp-Ch] BYREF
  int t; // [esp+28h] [ebp-8h] BYREF
  int tall; // [esp+2Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &x, a3: &w);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = w - v3;
    if ( w - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - x > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, x: &w, y: &t, wide: &y, &tall);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &x, a3: &min);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x: w, y: t + x, wide: y, tall: min - x);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: w + x, y: 0, wide: min - x, tall);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B250
// Name: public: static void vgui::ScrollBar::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl vgui::ScrollBar::AddToMap(
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

  v8 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
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
// Address: 0x0049B2D0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    vgui::ScrollBar::AddToMap(
      scriptname: "ScrollBarSliderMoved",
      function: (unsigned int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "position",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B330
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    vgui::ScrollBar::AddToMap(
      scriptname: "ScrollBarSliderReleased",
      function: (unsigned int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)2,
      p1name: "position",
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B390
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B3F0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // edi
  vgui::Button *v12; // eax
  vgui::Button *v13; // edi
  vgui::ScrollBarSlider *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // edi
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar();
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar();
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    vgui::ScrollBar::SetSlider(this, slider: v9);
    v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v11 = v10;
    if ( v10 != nullptr )
    {
      vgui::Button::Button(
        this: v10,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v11->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v11, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v11, alignment: a_center);
    }
    else
    {
      v11 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v11, index: 0);
    v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v13 = v12;
    if ( v12 != nullptr )
    {
      vgui::Button::Button(
        this: v12,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v13->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v13, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v13, alignment: a_center);
    }
    else
    {
      v13 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v13, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v14 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v14 = nullptr;
    vgui::ScrollBar::SetSlider(this, slider: v14);
    v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v16 = v15;
    if ( v15 != nullptr )
    {
      vgui::Button::Button(
        this: v15,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v16->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v16, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v16, alignment: a_center);
    }
    else
    {
      v16 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v16, index: 0);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049B720
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B750
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x0049B760
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00440230
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00440240
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x004404C0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440570
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004405A0
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004405D0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00440600
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004407F0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00440810
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00440820
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00440840
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00440860
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004408B0
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440900
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440930
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00440940
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00440950
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00440960
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x004409F0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x00440A10
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440A70
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00440A80
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440B20
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440B80
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00440BB0
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00440BC0
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x00440BE0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00440BF0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440C70
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440CB0
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440D50
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440F00
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440FA0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441040
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004410A0
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441440
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441470
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x00441480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x00444060
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x00444070
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x00444280
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x00444330
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00444360
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x00444390
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x004443C0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x004445B0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x004445D0
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x004445E0
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00444600
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x00444620
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444670
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004446C0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x004446F0
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x00444700
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00444710
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x00444720
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x004447B0
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x004447D0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00444830
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x00444840
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004448E0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444940
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00444970
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x00444980
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x004449A0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x004449B0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444A30
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444A70
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444B10
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444CC0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444D60
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444E00
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444E60
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00445200
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00445230
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x00445240
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10180160
// Name: public: virtual struct PanelAnimationMap __near * vgui::Button::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Button::GetAnimMap(vgui::Button *this)
{
  return FindOrAddPanelAnimationMap(className: "Button");
}

//------------------------------------------------------------------------------
// Address: 0x1039CB00
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  __m128 v4; // xmm0
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      cBlendedColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      cBlendedColor = this->_armedFgColor;
    }
    else
    {
      cBlendedColor = this->_defaultFgColor;
    }
    v4 = 0;
    v4.m128_f32[0] = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v4));
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[0] * v6));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[1] * v6));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[2] * v6));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                           + (float)((float)cBlendedColor._color[3] * v6));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103B5E20
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x103B60A0
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B6150
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B6180
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B61B0
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B61E0
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B63D0
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x103B63F0
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B6400
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x103B6420
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x103B6440
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6490
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B64E0
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B6510
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x103B6520
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B6530
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B6540
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B65F0
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B6650
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B66F0
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6750
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B6780
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x103B6790
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x103B67B0
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B67C0
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6840
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6880
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6920
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6AD0
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6B70
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ScrollBarSliderReleased";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6C10
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B6C70
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar();
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)MemAlloc_Alloc(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x103B1B90
// Name: public: static char const __near * vgui::ScrollBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::ScrollBar::GetPanelClassName()
{
  return "ScrollBar";
}

//------------------------------------------------------------------------------
// Address: 0x103B1BA0
// Name: private: static void __near * vgui::ScrollBar::GetVar_m_bAutoHideButtons(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseReleased *__cdecl vgui::ScrollBar::GetVar_m_bAutoHideButtons(
        vgui::Panel *panel)
{
  return &panel[1].m_InternalMouseReleased_register;
}

//------------------------------------------------------------------------------
// Address: 0x103B1E20
// Name: protected: virtual void vgui::ScrollBar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::ApplySchemeSettings(vgui::ScrollBar *this, vgui::IScheme *pScheme)
{
  const char *v3; // eax
  int v4; // edi
  vgui::ISchemeManager *v5; // ebx
  int v6; // eax
  int Wide; // [esp-8h] [ebp-10h]
  int Tall; // [esp-4h] [ebp-Ch]
  vgui::IScheme *pSchemea; // [esp+10h] [ebp+8h]

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = pScheme->GetResourceString(this: pScheme, a2: "ScrollBar.Wide");
  if ( v3 != nullptr )
  {
    v4 = atoi(nptr: v3);
    if ( this->IsProportional(this) )
    {
      v5 = g_pVGuiSchemeManager;
      pSchemea = (vgui::IScheme *)g_pVGuiSchemeManager->__vftable;
      v6 = ((int (__thiscall *)(vgui::ScrollBar *, int))this->GetScheme)(a1: this, a2: v4);
      v4 = ((int (__thiscall *)(vgui::ISchemeManager *, int))pSchemea[13].__vftable)(a1: v5, a2: v6);
    }
    if ( this->_slider != nullptr && this->_slider->IsVertical(this: this->_slider) )
    {
      Tall = vgui::Panel::GetTall(this);
      vgui::Panel::SetSize(this, wide: v4, tall: Tall);
    }
    else
    {
      Wide = vgui::Panel::GetWide(this);
      vgui::Panel::SetSize(this, wide: Wide, tall: v4);
    }
  }
  this->UpdateButtonsForImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B1ED0
// Name: public: virtual void vgui::ScrollBar::SetPaintBorderEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBorderEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBorderEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B1F00
// Name: public: virtual void vgui::ScrollBar::SetPaintBackgroundEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintBackgroundEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintBackgroundEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B1F30
// Name: public: virtual void vgui::ScrollBar::SetPaintEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetPaintEnabled(vgui::ScrollBar *this, BOOL state)
{
  if ( this->_slider != nullptr )
    this->_slider->SetPaintEnabled(this: this->_slider, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x103B1F60
// Name: protected: virtual void vgui::ScrollBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::PerformLayout(vgui::ScrollBar *this)
{
  vgui::ImagePanel *m_pBox; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  bool v4; // al
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  if ( this->_slider != nullptr )
  {
    this->GetPaintSize(this, a2: &wide, a3: &tall);
    if ( this->_slider->IsVertical(this: this->_slider) )
    {
      vgui::Panel::SetBounds(this: this->_slider, x: 0, y: wide, wide, tall: tall - 2 * wide + 1);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide, tall: wide);
      vgui::Panel::SetBounds(this: this->_button[1], x: 0, y: tall - wide, wide, tall: wide);
    }
    else
    {
      vgui::Panel::SetBounds(this: this->_slider, x: tall, y: 0, wide: wide - 2 * tall + 1, tall);
      vgui::Panel::SetBounds(this: this->_button[0], x: 0, y: 0, wide: tall, tall);
      vgui::Panel::SetBounds(this: this->_button[1], x: wide - tall, y: 0, wide: tall, tall);
    }
    if ( this->m_pUpArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[0], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pUpArrow, x, y, wide, tall);
    }
    if ( this->m_pDownArrow != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_button[1], &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pDownArrow, x, y, wide, tall);
    }
    if ( this->m_pLine != nullptr )
    {
      vgui::Panel::GetBounds(this: this->_slider, &x, &y, &wide, &tall);
      vgui::Panel::SetBounds(this: this->m_pLine, x, y, wide, tall);
    }
    m_pBox = this->m_pBox;
    if ( m_pBox != nullptr )
      vgui::Panel::SetBounds(this: m_pBox, x: 0, y: wide, wide, tall: wide);
    this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
    this->UpdateSliderImages(this);
  }
  if ( this->m_bAutoHideButtons )
  {
    v3 = this->__vftable;
    v4 = this->_slider->IsSliderVisible(this: this->_slider);
    v3->SetScrollbarButtonsVisible(this, a2: v4);
  }
  vgui::Panel::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2150
// Name: public: virtual void vgui::ScrollBar::SetValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetValue(vgui::ScrollBar *this, int value)
{
  this->_slider->SetValue(this: this->_slider, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x103B2170
// Name: public: virtual int vgui::ScrollBar::GetValue(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetValue(vgui::ScrollBar *this)
{
  return this->_slider->GetValue(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B2180
// Name: public: virtual void vgui::ScrollBar::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRange(vgui::ScrollBar *this, int min, int max)
{
  this->_slider->SetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x103B21A0
// Name: public: virtual void vgui::ScrollBar::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::GetRange(vgui::ScrollBar *this, int *min, int *max)
{
  this->_slider->GetRange(this: this->_slider, a2: min, a3: max);
}

//------------------------------------------------------------------------------
// Address: 0x103B21C0
// Name: protected: virtual void vgui::ScrollBar::SendSliderMoveMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendSliderMoveMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderMoved", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2210
// Name: protected: virtual void vgui::ScrollBar::SendScrollBarSliderReleasedMessage(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SendScrollBarSliderReleasedMessage(vgui::ScrollBar *this, int value)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ScrollBarSliderReleased", firstKey: "position", firstValue: value);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2260
// Name: protected: virtual void vgui::ScrollBar::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderMoved(vgui::ScrollBar *this, int value)
{
  this->SendSliderMoveMessage(this, a2: value);
  this->UpdateSliderImages(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2290
// Name: protected: virtual void vgui::ScrollBar::OnSliderReleased(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSliderReleased(vgui::ScrollBar *this, int value)
{
  this->SendScrollBarSliderReleasedMessage(this, a2: value);
}

//------------------------------------------------------------------------------
// Address: 0x103B22A0
// Name: public: virtual bool vgui::ScrollBar::IsVertical(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::IsVertical(vgui::ScrollBar *this)
{
  return this->_slider->IsVertical(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B22B0
// Name: public: virtual bool vgui::ScrollBar::HasFullRange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::ScrollBar::HasFullRange(vgui::ScrollBar *this)
{
  return this->_slider->HasFullRange(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B22C0
// Name: public: virtual void vgui::ScrollBar::SetButton(class vgui::Button __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButton(vgui::ScrollBar *this, vgui::Button *button, int index)
{
  vgui::Button *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v4 = this->_button[index];
  if ( v4 != nullptr )
    v4->SetParent_2(this: v4, a2: nullptr);
  this->_button[index] = button;
  button->SetParent_2(this: button, a2: this);
  this->_button[index]->AddActionSignalTarget_2(this: this->_button[index], a2: this);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ScrollButtonPressed", firstKey: "index", firstValue: index);
  else
    v6 = nullptr;
  this->_button[index]->SetCommand(this: this->_button[index], a2: v6);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2350
// Name: public: virtual class vgui::Button __near * vgui::ScrollBar::GetButton(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Button *__thiscall vgui::ScrollBar::GetButton(vgui::ScrollBar *this, int index)
{
  return this->_button[index];
}

//------------------------------------------------------------------------------
// Address: 0x103B2370
// Name: public: virtual void vgui::ScrollBar::SetSlider(class vgui::ScrollBarSlider __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetSlider(vgui::ScrollBar *this, vgui::ScrollBarSlider *slider)
{
  vgui::ScrollBarSlider *v3; // ecx

  v3 = this->_slider;
  if ( v3 != nullptr )
    v3->SetParent_2(this: v3, a2: nullptr);
  this->_slider = slider;
  slider->AddActionSignalTarget_2(this: slider, a2: this);
  this->_slider->SetParent_2(this: this->_slider, a2: this);
  this->Validate(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B23D0
// Name: public: virtual class vgui::ScrollBarSlider __near * vgui::ScrollBar::GetSlider(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBarSlider *__thiscall vgui::ScrollBar::GetSlider(vgui::ScrollBar *this)
{
  return this->_slider;
}

//------------------------------------------------------------------------------
// Address: 0x103B23E0
// Name: public: virtual void vgui::ScrollBar::OnMouseFocusTicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnMouseFocusTicked(vgui::ScrollBar *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax

  if ( this->_button[0]->IsDepressed(this: this->_button[0]) )
  {
    v2 = -1;
  }
  else
  {
    if ( !this->_button[1]->IsDepressed(this: this->_button[1]) )
    {
      v4 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
      this->_respond = true;
      this->_scrollDelay = v4 + 400;
      return;
    }
    v2 = 1;
  }
  this->RespondToScrollArrow(this, a2: v2);
  if ( this->_scrollDelay >= g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->_respond = false;
  }
  else
  {
    v3 = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem);
    this->_respond = true;
    this->_scrollDelay = v3 + 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2480
// Name: protected: virtual void vgui::ScrollBar::RespondToScrollArrow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::RespondToScrollArrow(vgui::ScrollBar *this, int direction)
{
  int v3; // edi

  if ( this->_respond )
  {
    v3 = direction * this->_buttonPressedScrollValue + this->_slider->GetValue(this: this->_slider);
    this->_slider->SetValue(this: this->_slider, a2: v3);
    this->SendSliderMoveMessage(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B24E0
// Name: protected: virtual void vgui::ScrollBar::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::OnSizeChanged(vgui::ScrollBar *this, int wide, int tall)
{
  this->InvalidateLayout(this, a2: false, a3: false);
  this->_slider->InvalidateLayout(this: this->_slider, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103B2510
// Name: public: virtual void vgui::ScrollBar::SetButtonPressedScrollValue(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetButtonPressedScrollValue(vgui::ScrollBar *this, int value)
{
  this->_buttonPressedScrollValue = value;
}

//------------------------------------------------------------------------------
// Address: 0x103B2520
// Name: public: virtual void vgui::ScrollBar::SetRangeWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetRangeWindow(vgui::ScrollBar *this, int rangeWindow)
{
  this->_slider->SetRangeWindow(this: this->_slider, a2: rangeWindow);
}

//------------------------------------------------------------------------------
// Address: 0x103B2540
// Name: public: virtual int vgui::ScrollBar::GetRangeWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::ScrollBar::GetRangeWindow(vgui::ScrollBar *this)
{
  return this->_slider->GetRangeWindow(this: this->_slider);
}

//------------------------------------------------------------------------------
// Address: 0x103B2550
// Name: public: virtual void vgui::ScrollBar::Validate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::Validate(vgui::ScrollBar *this)
{
  int v2; // edi
  vgui::Button **button; // esi
  bool v4; // al
  vgui::Panel *v5; // ecx
  int Tall; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( this->_slider != nullptr )
  {
    v2 = 0;
    button = this->_button;
    for ( i = 2; i != 0; --i )
    {
      if ( *button != nullptr && (*button)->IsVisible(this: *button) )
      {
        v4 = this->_slider->IsVertical(this: this->_slider);
        v5 = *button;
        if ( v4 )
          Tall = vgui::Panel::GetTall(this: v5);
        else
          Tall = vgui::Panel::GetWide(this: v5);
        v2 += Tall;
      }
      ++button;
    }
    this->_slider->SetButtonOffset(this: this->_slider, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B25D0
// Name: public: virtual void vgui::ScrollBar::SetScrollbarButtonsVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::SetScrollbarButtonsVisible(vgui::ScrollBar *this, BOOL visible)
{
  vgui::Button **button; // esi
  int i; // edi

  button = this->_button;
  for ( i = 2; i != 0; --i )
  {
    if ( *button != nullptr )
    {
      (*button)->_paint = visible;
      (*button)->SetEnabled(this: *button, a2: visible);
    }
    ++button;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2610
// Name: protected: virtual void vgui::ScrollBar::UpdateButtonsForImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateButtonsForImages(vgui::ScrollBar *this)
{
  vgui::ScrollBarSlider *slider; // ecx

  if ( this->m_pUpArrow != nullptr || this->m_pDownArrow != nullptr )
  {
    this->SetScrollbarButtonsVisible(this, a2: false);
    this->_button[0]->SetPaintBorderEnabled(this: this->_button[0], a2: false);
    this->_button[1]->SetPaintBorderEnabled(this: this->_button[1], a2: false);
    this->m_bAutoHideButtons = false;
  }
  if ( this->m_pLine != nullptr || this->m_pBox != nullptr )
  {
    this->SetPaintBackgroundEnabled(this, a2: false);
    this->SetPaintBorderEnabled(this, a2: false);
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetPaintEnabled(this: slider, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B26B0
// Name: protected: virtual void vgui::ScrollBar::UpdateSliderImages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::ScrollBar::UpdateSliderImages(vgui::ScrollBar *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  vgui::ScrollBarSlider *v5; // eax
  vgui::ScrollBarSlider *v6; // edi
  int t; // [esp+8h] [ebp-18h] BYREF
  int y; // [esp+Ch] [ebp-14h] BYREF
  int w; // [esp+10h] [ebp-10h] BYREF
  int x; // [esp+14h] [ebp-Ch] BYREF
  int min; // [esp+18h] [ebp-8h] BYREF
  int max; // [esp+1Ch] [ebp-4h] BYREF

  if ( this->m_pUpArrow != nullptr && this->m_pDownArrow != nullptr )
  {
    this->GetRange(this, a2: &min, a3: &x);
    v2 = this->GetValue(this);
    v3 = this->GetRangeWindow(this);
    v4 = x - v3;
    if ( x - v3 < 0 )
      v4 = 0;
    vgui::Panel::SetAlpha(this: this->m_pUpArrow, alpha: v2 - min > 0 ? 255 : 90);
    vgui::Panel::SetAlpha(this: this->m_pDownArrow, alpha: v2 < v4 ? 255 : 90);
  }
  if ( this->m_pLine != nullptr && this->m_pBox != nullptr )
  {
    v5 = this->GetSlider(this);
    v6 = v5;
    if ( v5 != nullptr && v5->GetRangeWindow(this: v5) > 0 )
    {
      vgui::Panel::GetBounds(this: this->m_pLine, &x, &y, wide: &w, tall: &t);
      if ( v6->IsLayoutInvalid(this: v6) )
        v6->InvalidateLayout(this: v6, a2: true, a3: false);
      v6->GetNobPos(this: v6, a2: &min, a3: &max);
      if ( this->IsVertical(this) )
        vgui::Panel::SetBounds(this: this->m_pBox, x, y: y + min, wide: w, tall: max - min);
      else
        vgui::Panel::SetBounds(this: this->m_pBox, x: x + min, y: 0, wide: max - min, tall: t);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2860
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2900
// Name: public: static void vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(int a1@<ebp>)
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
  if ( !`vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderReleased";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B29A0
// Name: public: static void vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded )
  {
    `vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "autohide_buttons";
    src.m_pszVariable = "m_bAutoHideButtons";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::ScrollBar::GetVar_m_bAutoHideButtons;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103B2A00
// Name: public: vgui::ScrollBar::ScrollBar(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::ScrollBar *__thiscall vgui::ScrollBar::ScrollBar(
        vgui::ScrollBar *this,
        vgui::Panel *parent,
        const char *panelName,
        bool vertical)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ScrollBarSlider *v8; // eax
  vgui::ScrollBarSlider *v9; // edi
  vgui::ScrollBarSlider *slider; // ecx
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::ScrollBarSlider *v15; // edi
  vgui::ScrollBarSlider *v16; // ecx
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::ScrollBar_vtbl *)&vgui::ScrollBar::`vftable';
  if ( `vgui::ScrollBar::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
    v5->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "ScrollBar");
    v6->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::ScrollBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::ScrollBar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
    v7->pfnClassName = vgui::ScrollBar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::ScrollBar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelMessageFunc_OnSliderReleased::InitVar(a1: (int)&savedregs);
  vgui::ScrollBar::PanelAnimationVar_m_bAutoHideButtons::InitVar();
  this->m_bAutoHideButtons = false;
  this->_slider = nullptr;
  this->_button[0] = nullptr;
  this->_button[1] = nullptr;
  this->_scrollDelay = 400;
  this->_respond = true;
  this->m_pUpArrow = nullptr;
  this->m_pLine = nullptr;
  this->m_pDownArrow = nullptr;
  this->m_pBox = nullptr;
  v8 = (vgui::ScrollBarSlider *)operator new(nSize: 0x198u);
  if ( vertical )
  {
    if ( v8 != nullptr )
      v9 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "vslider", vertical: true);
    else
      v9 = nullptr;
    slider = this->_slider;
    if ( slider != nullptr )
      slider->SetParent_2(this: slider, a2: nullptr);
    this->_slider = v9;
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v12 = v11;
    if ( v11 != nullptr )
    {
      vgui::Button::Button(
        this: v11,
        parent: nullptr,
        panelName: "top",
        text: "t",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v12->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v12, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v12, alignment: a_center);
    }
    else
    {
      v12 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v12, index: 0);
    v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v14 = v13;
    if ( v13 != nullptr )
    {
      vgui::Button::Button(
        this: v13,
        parent: nullptr,
        panelName: "bottom",
        text: "u",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v14->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v14, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v14, alignment: a_center);
    }
    else
    {
      v14 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v14, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 1);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: -1);
    vgui::Panel::SetSize(this, wide: 17, tall: 64);
  }
  else
  {
    if ( v8 != nullptr )
      v15 = vgui::ScrollBarSlider::ScrollBarSlider(this: v8, parent: nullptr, panelName: "hslider", vertical: false);
    else
      v15 = nullptr;
    v16 = this->_slider;
    if ( v16 != nullptr )
      v16->SetParent_2(this: v16, a2: nullptr);
    this->_slider = v15;
    v15->AddActionSignalTarget_2(this: v15, a2: this);
    this->_slider->SetParent_2(this: this->_slider, a2: this);
    this->Validate(this);
    v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v18 = v17;
    if ( v17 != nullptr )
    {
      vgui::Button::Button(
        this: v17,
        parent: nullptr,
        panelName: "left",
        text: "w",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v18->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v18, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v18, alignment: a_center);
    }
    else
    {
      v18 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v18, index: 0);
    v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
    v20 = v19;
    if ( v19 != nullptr )
    {
      vgui::Button::Button(
        this: v19,
        parent: nullptr,
        panelName: "right",
        text: "4",
        pActionSignalTarget: nullptr,
        pCmd: nullptr);
      v20->__vftable = (vgui::Button_vtbl *)&`anonymous namespace'::ScrollBarButton::`vftable';
      vgui::Button::SetButtonActivationType(this: v20, activationType: ACTIVATE_ONPRESSED);
      vgui::Label::SetContentAlignment(this: v20, alignment: a_center);
    }
    else
    {
      v20 = nullptr;
    }
    vgui::ScrollBar::SetButton(this, button: v20, index: 1);
    this->_button[0]->SetTextInset(this: this->_button[0], a2: 0, a3: 0);
    this->_button[1]->SetTextInset(this: this->_button[1], a2: 0, a3: 0);
    vgui::Panel::SetSize(this, wide: 64, tall: 17);
  }
  vgui::Panel::SetPaintBorderEnabled(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: true);
  this->_buttonPressedScrollValue = 20;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::ScrollBar::Validate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B2DA0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::ScrollBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::ScrollBar::GetMessageMap(vgui::ScrollBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "ScrollBar");
  `vgui::ScrollBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B2DD0
// Name: public: virtual struct PanelAnimationMap __near * vgui::ScrollBar::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::ScrollBar::GetAnimMap(vgui::ScrollBar *this)
{
  return FindOrAddPanelAnimationMap(className: "ScrollBar");
}

//------------------------------------------------------------------------------
// Address: 0x103B2DE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::ScrollBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::ScrollBar::GetKBMap(vgui::ScrollBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::ScrollBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::ScrollBar::GetKBMap'::`2'::s_pMap;
  `vgui::ScrollBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "ScrollBar");
  `vgui::ScrollBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace server
