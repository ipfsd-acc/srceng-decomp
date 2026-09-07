// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/slider.cpp
// Functions: 42
// ============================================================

#include "vgui2\vgui_controls\slider.h"

//------------------------------------------------------------------------------
// Address: 0x102B93F0
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x102B9400
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x102B9430
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B9460
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B94D0
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x102B9510
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102B9540
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x102B95D0
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x102B95F0
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B9640
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B9690
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B96E0
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9880
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9910
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySettings(vgui::Slider *this, KeyValues *inResourceData)
{
  const char *String; // ebx
  int Int; // eax
  const char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x102B9980
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_5, maxLen: 1024, pFormat: "%s, string leftText, string rightText", Description);
  return buf_5;
}

//------------------------------------------------------------------------------
// Address: 0x102B99B0
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x102B9A10
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B9A40
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9BD0
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9D20
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x102B9DE0
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102B9E80
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102B9F20
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x102B9FC0
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x102BA020
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x102BA040
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA140
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BA160
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BA170
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA320
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA360
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x102BA380
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x102BA3A0
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x102BA3B0
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BA4D0
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA6A0
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BA800
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BA830
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x102BA840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BA870
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102DCE30
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

//------------------------------------------------------------------------------
// Address: 0x102DD700
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00601550
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

//------------------------------------------------------------------------------
// Address: 0x00634210
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x00634220
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x00634250
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x00634280
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x006342F0
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x00634330
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00634360
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x006343F0
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x00634410
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00634460
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x006344B0
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00634500
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006346A0
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00634730
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::ApplySettings(vgui::Slider *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // ebx
  int Int; // eax
  char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2, a3: (int)this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x006347A0
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_13, maxLen: 0x400u, pFormat: "%s, string leftText, string rightText", Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x006347D0
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x00634830
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x00634860
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006349F0
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00634B40
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x00634C00
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00634CA0
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00634D50
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x00634DF0
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x00634E50
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x00634E70
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00634F70
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00634F90
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00634FB0
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00635160
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006351A0
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x006351C0
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x006351E0
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x006351F0
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00635310
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006354E0
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00635640
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00635670
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x00635680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006356B0
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00640400
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102B0320
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

//------------------------------------------------------------------------------
// Address: 0x102B94A0
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x102B94B0
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x102B94E0
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B9590
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x102B9600
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x102B96B0
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B9700
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B9750
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102B97A0
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9940
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B99D0
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::ApplySettings(vgui::Slider *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // ebx
  int Int; // eax
  char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2, a3: (int)this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x102B9A70
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x102B9AD0
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x102B9B00
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9C90
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B9EA0
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102B9F40
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102B9FE0
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x102BA080
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x102BA0E0
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x102BA100
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA200
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BA220
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BA230
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA3E0
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA420
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x102BA440
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x102BA460
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x102BA470
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BA590
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BA760
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, __m128i *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BA8C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BA8F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x102BA900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BA930
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102DCF10
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10045A40
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Panel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Panel::GetUnpackStructure(vgui::Panel *this)
{
  return vgui::Panel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x102C6000
// Name: public: virtual class Color vgui::Panel::GetBgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetBgColor(vgui::Panel *this, Color *result)
{
  *result = this->_bgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6020
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1032FBE0
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

//------------------------------------------------------------------------------
// Address: 0x1059BF30
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x1059BF40
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x1059BF70
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059BFA0
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059C020
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x1059C060
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1059C090
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x1059C120
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1059C140
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1059C190
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1059C1E0
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1059C230
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059C3D0
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059C460
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySettings(vgui::Slider *this, KeyValues *inResourceData)
{
  const char *String; // ebx
  int Int; // eax
  const char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x1059C4D0
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_18, maxLen: 1024, pFormat: "%s, string leftText, string rightText", Description);
  return buf_18;
}

//------------------------------------------------------------------------------
// Address: 0x1059C500
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x1059C560
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059C590
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059C720
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059C870
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x1059C930
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1059C9D0
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x1059CA70
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x1059CB10
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x1059CB70
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x1059CB90
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059CC90
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059CCB0
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059CCC0
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059CE70
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059CEB0
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x1059CED0
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

//------------------------------------------------------------------------------
// Address: 0x1059CEE0
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x1059CF10
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059D030
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059D200
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1059D360
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D390
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x1059D3A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D3D0
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1059D3F0
// Name: xtoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge xtoa(unsigned int val@<eax>, char *buf@<ecx>, unsigned int radix, int is_neg)
{
  char *v4; // esi
  char v5; // dl
  unsigned int v6; // et2
  char v7; // dl
  char *v8; // ecx
  char v9; // al

  if ( is_neg != 0 )
  {
    *buf++ = 45;
    val = -val;
  }
  v4 = buf;
  do
  {
    v6 = val % radix;
    val /= radix;
    v5 = v6;
    if ( v6 <= 9 )
      v7 = v5 + 48;
    else
      v7 = v5 + 87;
    *buf++ = v7;
  }
  while ( val != 0 );
  *buf = 0;
  v8 = buf - 1;
  do
  {
    v9 = *v8;
    *v8-- = *v4;
    *v4++ = v9;
  }
  while ( v4 < v8 );
}

//------------------------------------------------------------------------------
// Address: 0x1059D433
// Name: _itoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl itoa(int val, char *buf, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    xtoa(val, buf, radix: 0xAu, is_neg: 1);
  else
    xtoa(val, buf, radix, is_neg: 0);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x1059D45D
// Name: _ultoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl ultoa(unsigned int val, char *buf, unsigned int radix)
{
  xtoa(val, buf, radix, is_neg: 0);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x1059D477
// Name: _strupr_s_l_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall strupr_s_l_stat@<eax>(char *string@<edi>, localeinfo_struct *plocinfo@<ebx>, unsigned int sizeInBytes)
{
  int *v3; // eax
  int v4; // esi
  unsigned int v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp+0h] [ebp-10h] BYREF
  int dstsize; // [esp+4h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+8h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x200u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)&v15;
      if ( &v15 != nullptr )
      {
        v15 = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x200u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 97 && v7 <= 122 )
      *i = v7 - 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1059D5EB
// Name: __strupr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strupr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = strupr_s_l_stat(string, plocinfo: &_loc_update.localeinfo, sizeInBytes);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D620
// Name: _strupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strupr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strupr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 97 && v3 <= 122 )
          *i = v3 - 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D67D
// Name: __wcsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsicmp_l(wchar_t *dst, wchar_t *src, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v3; // ebx
  int result; // eax
  unsigned __int16 *v5; // edi
  int v6; // ebx
  unsigned int v7; // eax
  unsigned __int16 v8; // si
  unsigned int v9; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = dst;
  if ( dst != nullptr )
  {
    v5 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v8 = _towlower_l(c: *v3++, plocinfo: &_loc_update.localeinfo);
          LOWORD(v9) = _towlower_l(c: *v5++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v8 != 0 && v8 == (_WORD)v9 );
      }
      else
      {
        v6 = (char *)dst - (char *)src;
        do
        {
          v7 = *(unsigned __int16 *)((char *)v5 + v6);
          if ( v7 < 0x41 || v7 > 0x5A )
            v8 = *(unsigned __int16 *)((char *)v5 + v6);
          else
            v8 = v7 + 32;
          v9 = *v5;
          if ( v9 >= 0x41 && v9 <= 0x5A )
            LOWORD(v9) = v9 + 32;
          ++v5;
        }
        while ( v8 != 0 && v8 == (_WORD)v9 );
      }
      result = v8 - (unsigned __int16)v9;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D780
// Name: __wcsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsicmp(wchar_t *dst, wchar_t *src)
{
  wchar_t *v3; // ecx
  int v4; // esi
  unsigned int v5; // eax
  unsigned __int16 v6; // dx
  unsigned int v7; // eax

  if ( __locale_changed != 0 )
    return _wcsicmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && (v3 = src, src != nullptr) )
  {
    v4 = (char *)dst - (char *)src;
    do
    {
      v5 = *(wchar_t *)((char *)v3 + v4);
      if ( v5 < 0x41 || v5 > 0x5A )
        v6 = *(wchar_t *)((char *)v3 + v4);
      else
        v6 = v5 + 32;
      v7 = *v3;
      if ( v7 >= 0x41 && v7 <= 0x5A )
        LOWORD(v7) = v7 + 32;
      ++v3;
    }
    while ( v6 != 0 && v6 == (_WORD)v7 );
    return v6 - (unsigned __int16)v7;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059D80B
// Name: __wcsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicmp_l(wchar_t *first, wchar_t *last, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned __int16 *v5; // ebx
  unsigned __int16 *v6; // edi
  int v7; // ebx
  unsigned int v8; // eax
  unsigned __int16 v9; // si
  unsigned int v10; // eax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  result = 0;
  if ( count != 0 )
  {
    v5 = first;
    if ( first != nullptr && (v6 = last, last != nullptr) )
    {
      _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v9 = _towlower_l(c: *v5, plocinfo: &_loc_update.localeinfo);
          LOWORD(v10) = _towlower_l(c: *v6, plocinfo: &_loc_update.localeinfo);
          ++v5;
          ++v6;
          --count;
        }
        while ( count != 0 && v9 != 0 && v9 == (_WORD)v10 );
      }
      else
      {
        v7 = (char *)first - (char *)last;
        do
        {
          v8 = *(unsigned __int16 *)((char *)v6 + v7);
          if ( v8 < 0x41 || v8 > 0x5A )
            v9 = *(unsigned __int16 *)((char *)v6 + v7);
          else
            v9 = v8 + 32;
          v10 = *v6;
          if ( v10 >= 0x41 && v10 <= 0x5A )
            LOWORD(v10) = v10 + 32;
          ++v6;
          --count;
        }
        while ( count != 0 && v9 != 0 && v9 == (_WORD)v10 );
      }
      result = v9 - (unsigned __int16)v10;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D8F0
// Name: __wcsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicmp(wchar_t *first, wchar_t *last, unsigned int count)
{
  int result; // eax
  wchar_t *v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( __locale_changed != 0 )
    return _wcsnicmp_l(first, last, count, plocinfo: nullptr);
  result = 0;
  if ( count != 0 )
  {
    if ( first != nullptr && (v4 = last, last != nullptr) )
    {
      v5 = (char *)first - (char *)last;
      do
      {
        v6 = *(wchar_t *)((char *)v4 + v5);
        if ( v6 < 0x41 || v6 > 0x5A )
          v7 = *(wchar_t *)((char *)v4 + v5);
        else
          v7 = v6 + 32;
        v8 = *v4;
        if ( v8 >= 0x41 && v8 <= 0x5A )
          LOWORD(v8) = v8 + 32;
        ++v4;
        --count;
      }
      while ( count != 0 && v7 != 0 && v7 == (_WORD)v8 );
      return v7 - (unsigned __int16)v8;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059D990
// Name: shortsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort_s(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // edx
  char *v6; // edi
  unsigned int v7; // ecx
  char *v8; // esi
  char *v9; // ebx
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // ecx
  char v13; // dl

  v5 = lo;
  v6 = hi;
  if ( hi > lo )
  {
    v7 = width;
    do
    {
      v8 = &lo[width];
      v9 = v5;
      if ( &lo[width] <= v6 )
      {
        do
        {
          if ( comp(a1: context, a2: v8, a3: v9) > 0 )
            v9 = v8;
          v8 += width;
        }
        while ( v8 <= v6 );
        v7 = width;
        v5 = lo;
      }
      v10 = v7;
      v11 = v6;
      if ( v9 != v6 && v7 != 0 )
      {
        v12 = v9 - v6;
        do
        {
          v13 = v11[v12];
          v11[v12] = *v11;
          *v11++ = v13;
          --v10;
        }
        while ( v10 != 0 );
        v7 = width;
        v5 = lo;
      }
      v6 -= v7;
    }
    while ( v6 > v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059DA20
// Name: _qsort_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort_s(
        char *base,
        unsigned int num,
        unsigned int width,
        int (__cdecl *comp)(void *, const void *, const void *),
        void *context)
{
  char *v5; // ebx
  unsigned int v6; // esi
  char *v7; // edi
  unsigned int v8; // eax
  char *v9; // esi
  unsigned int v10; // edx
  char *v11; // eax
  int v12; // ecx
  unsigned int v13; // edx
  char *v14; // eax
  int v15; // ecx
  unsigned int v16; // edx
  char *v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  char *v20; // eax
  int v21; // ecx
  char *v22; // eax
  char *v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  char *v27; // edx
  char *v28; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v31; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v5 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v6 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v7 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v7;
    while ( 1 )
    {
      v8 = (v7 - v5) / v6 + 1;
      if ( v8 <= 8 )
      {
        shortsort_s(hi: v7, lo: v5, width: v6, comp, context);
        goto LABEL_56;
      }
      v9 = &v5[(v8 >> 1) * v6];
      if ( comp(a1: context, a2: v5, a3: v9) > 0 )
      {
        v10 = width;
        v11 = v9;
        if ( v5 != v9 )
        {
          v12 = v5 - v9;
          do
          {
            v31 = v10 - 1;
            base_3 = v11[v12];
            v11[v12] = *v11;
            *v11 = base_3;
            v10 = v31;
            ++v11;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v5, a3: v7) > 0 )
      {
        v13 = width;
        v14 = v7;
        if ( v5 != v7 )
        {
          v15 = v5 - v7;
          do
          {
            v31 = v13 - 1;
            base_3a = v14[v15];
            v14[v15] = *v14;
            *v14 = base_3a;
            v13 = v31;
            ++v14;
          }
          while ( v31 != 0 );
        }
      }
      if ( comp(a1: context, a2: v9, a3: v7) > 0 )
      {
        v16 = width;
        v17 = v7;
        if ( v9 != v7 )
        {
          v18 = v9 - v7;
          do
          {
            base_3b = v17[v18];
            v17[v18] = *v17;
            *v17++ = base_3b;
            --v16;
          }
          while ( v16 != 0 );
          v5 = lo;
        }
      }
      while ( 1 )
      {
        if ( v9 > v5 )
        {
          while ( 1 )
          {
            v5 += width;
            if ( v5 >= v9 )
              break;
            if ( comp(a1: context, a2: v5, a3: v9) > 0 )
            {
              if ( v9 > v5 )
                goto LABEL_31;
              goto LABEL_29;
            }
          }
        }
        do
LABEL_29:
          v5 += width;
        while ( v5 <= hi && comp(a1: context, a2: v5, a3: v9) <= 0 );
        do
LABEL_31:
          v7 -= width;
        while ( v7 > v9 && comp(a1: context, a2: v7, a3: v9) > 0 );
        if ( v5 > v7 )
          break;
        v19 = width;
        v20 = v7;
        if ( v5 != v7 )
        {
          v21 = v5 - v7;
          do
          {
            v31 = v19 - 1;
            base_3c = v20[v21];
            v20[v21] = *v20;
            *v20 = base_3c;
            v19 = v31;
            ++v20;
          }
          while ( v31 != 0 );
        }
        if ( v9 == v7 )
          v9 = v5;
      }
      v7 += width;
      if ( v9 >= v7 )
        goto LABEL_43;
      do
      {
        v7 -= width;
        if ( v7 <= v9 )
          goto LABEL_43;
      }
      while ( comp(a1: context, a2: v7, a3: v9) == 0 );
      if ( v9 < v7 )
      {
LABEL_45:
        v22 = lo;
      }
      else
      {
LABEL_43:
        while ( 1 )
        {
          v7 -= width;
          v22 = lo;
          if ( v7 <= lo )
            break;
          if ( comp(a1: context, a2: v7, a3: v9) != 0 )
            goto LABEL_45;
        }
      }
      v23 = hi;
      if ( v7 - v22 < hi - v5 )
      {
        if ( v5 < hi )
        {
          v25 = stkptr;
          lostk[stkptr] = v5;
          histk[v25] = v23;
          stkptr = v25 + 1;
        }
        if ( v22 >= v7 )
          goto LABEL_55;
        v5 = lo;
        v6 = width;
        hi = v7;
      }
      else
      {
        if ( v22 < v7 )
        {
          v24 = stkptr;
          lostk[stkptr] = v22;
          histk[v24] = v7;
          stkptr = v24 + 1;
        }
        if ( v5 >= v23 )
        {
LABEL_55:
          v6 = width;
LABEL_56:
          v26 = --stkptr;
          if ( stkptr < 0 )
            return;
          v27 = lostk[v26];
          v28 = histk[v26];
          lo = v27;
          hi = v28;
          v5 = v27;
          v7 = v28;
        }
        else
        {
          v7 = hi;
          v6 = width;
          lo = v5;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1059DCE0
// Name: __allshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _allshr@<eax>(__int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> 31;
  }
  else if ( a2 >= 0x20u )
  {
    LODWORD(a1) = SHIDWORD(a1) >> (a2 & 0x1F);
  }
  else
  {
    a1 >>= a2 & 0x1F;
  }
  return a1;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100C9F70
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x100C9F80
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x100C9FB0
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C9FE0
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CA050
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x100CA090
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100CA0C0
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x100CA150
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x100CA170
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CA1C0
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CA210
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100CA260
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA400
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA490
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::ApplySettings(vgui::Slider *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // ebx
  int Int; // eax
  char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2, a3: (int)this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x100CA500
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_14, maxLen: 0x400u, pFormat: "%s, string leftText, string rightText", Description);
  return buf_14;
}

//------------------------------------------------------------------------------
// Address: 0x100CA530
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x100CA590
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CA5C0
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA750
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CA8A0
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x100CA960
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100CAA00
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100CAAA0
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x100CAB40
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x100CABA0
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x100CABC0
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CACC0
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CACE0
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CACF0
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

//------------------------------------------------------------------------------
// Address: 0x100CAD00
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAEB0
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CAEF0
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF10
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF20
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF40
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x100CAF50
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100CB070
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CB240
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100CB3A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB3D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x100CB3E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100CB410
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

} // namespace missionchooser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00663ED0
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x00663EE0
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x00663F10
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x00663F40
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x00663FC0
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x00664000
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x00664030
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x006640C0
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x006640E0
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00664130
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00664180
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x006641D0
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664370
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664400
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::ApplySettings(vgui::Slider *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // ebx
  int Int; // eax
  char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2, a3: (int)this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x00664470
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_13, maxLen: 0x400u, pFormat: "%s, string leftText, string rightText", Description);
  return buf_13;
}

//------------------------------------------------------------------------------
// Address: 0x006644A0
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x00664500
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x00664530
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006646C0
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664810
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x006648D0
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00664970
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00664A20
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x00664AC0
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x00664B20
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x00664B40
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664C40
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00664C60
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x00664C70
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664E20
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00664E60
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x00664E80
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x00664EA0
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x00664EB0
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x00664FD0
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006651A0
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00665300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00665330
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x00665340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00665370
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00670640
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

//------------------------------------------------------------------------------
// Address: 0x00670F10
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

} // namespace sceneviewer

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103BF5B0
// Name: public: static char const __near * vgui::Slider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Slider::GetPanelClassName()
{
  return "Slider";
}

//------------------------------------------------------------------------------
// Address: 0x103BF5C0
// Name: public: virtual void vgui::Slider::SetSliderThumbSubRange(bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetSliderThumbSubRange(vgui::Slider *this, bool bEnable, int nMin, int nMax)
{
  char v4; // al

  v4 = *((_BYTE *)this + 424) ^ (2 * bEnable);
  this->_subrange[0] = nMin;
  *((_BYTE *)this + 424) ^= v4 & 2;
  this->_subrange[1] = nMax;
}

//------------------------------------------------------------------------------
// Address: 0x103BF5F0
// Name: protected: virtual void vgui::Slider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnSizeChanged(vgui::Slider *this, int wide, int tall)
{
  vgui::Panel::OnSizeChanged(this, newWide: wide, newTall: tall);
  this->RecomputeNobPosFromValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BF620
// Name: public: virtual void vgui::Slider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetValue(vgui::Slider *this, int value, bool bTriggerChangeMessage)
{
  int v3; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // edi

  v3 = value;
  v5 = this->_range[0];
  v6 = this->_range[1];
  v7 = this->_value;
  if ( v5 >= v6 )
  {
    if ( value < v6 )
      v3 = this->_range[1];
    if ( v3 > v5 )
      v3 = v5;
  }
  else
  {
    if ( value < v5 )
      v3 = v5;
    if ( v3 > v6 )
      v3 = this->_range[1];
  }
  this->_value = v3;
  this->RecomputeNobPosFromValue(this);
  if ( this->_value != v7 && bTriggerChangeMessage )
    this->SendSliderMovedMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BF6A0
// Name: protected: virtual void vgui::Slider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PerformLayout(vgui::Slider *this)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *rightCaption; // ecx

  vgui::Panel::PerformLayout(this);
  this->RecomputeNobPosFromValue(this);
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: leftCaption);
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
    vgui::TextImage::ResizeImageToContent(this: rightCaption);
}

//------------------------------------------------------------------------------
// Address: 0x103BF6E0
// Name: protected: virtual void vgui::Slider::RecomputeValueFromNobPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeValueFromNobPos(vgui::Slider *this)
{
  int v2; // eax

  v2 = this->EstimateValueAtPos(this, a2: this->_nobPos[0], a3: 0);
  this->SetValue(this, a2: v2, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x103BF710
// Name: public: virtual int vgui::Slider::EstimateValueAtPos(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Slider::EstimateValueAtPos(vgui::Slider *this, int localMouseX, int __formal)
{
  int *range; // ecx
  float v5; // xmm2_4
  float v6; // xmm0_4
  int y; // [esp+4h] [ebp-10h] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int wide; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(a1: this, a2: &x, a3: &y, a4: &wide);
  range = this->_range;
  if ( (*((_BYTE *)this + 424) & 2) != 0 )
    range = this->_subrange;
  v5 = 0.0;
  v6 = (float)wide - this->_nobSize;
  if ( v6 != 0.0 )
    v5 = (float)(localMouseX - x) / v6;
  return (int)(float)((float)((float)((float)range[1] - (float)*range) * v5) + (float)*range);
}

//------------------------------------------------------------------------------
// Address: 0x103BF7A0
// Name: public: virtual void vgui::Slider::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetInverted(vgui::Slider *this, bool bInverted)
{
  *((_BYTE *)this + 424) ^= (*((_BYTE *)this + 424) ^ (4 * bInverted)) & 4;
}

//------------------------------------------------------------------------------
// Address: 0x103BF7C0
// Name: protected: virtual void vgui::Slider::SendSliderMovedMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderMovedMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderMoved", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103BF810
// Name: protected: virtual void vgui::Slider::SendSliderDragStartMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragStartMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragStart", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103BF860
// Name: protected: virtual void vgui::Slider::SendSliderDragEndMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SendSliderDragEndMessage(vgui::Slider *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SliderDragEnd", firstKey: "position", firstValue: this->_value);
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x103BF8B0
// Name: protected: virtual void vgui::Slider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::ApplySchemeSettings(vgui::Slider *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Slider_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::IScheme v6; // ebx
  Color *v7; // eax
  vgui::IScheme v8; // ebx
  Color *v9; // eax
  vgui::IScheme v10; // ebx
  Color *v11; // eax
  vgui::IScheme v12; // ebx
  Color *v13; // eax
  vgui::TextImage *leftCaption; // eax
  vgui::TextImage_vtbl *v15; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  bool v17; // al
  int v18; // eax
  vgui::TextImage *rightCaption; // eax
  vgui::TextImage_vtbl *v20; // ebx
  vgui::Slider_vtbl *v21; // edx
  bool v22; // al
  int v23; // eax
  char v24[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "Slider.NobColor", a4: v2);
  ((void (__thiscall *)(vgui::Slider *, _DWORD))v4->SetFgColor)(a1: this, a2: *v5);
  v6.__vftable = v2->__vftable;
  v7 = this->GetFgColor(this, result: &pScheme);
  this->m_TickColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v6.GetColor)(
                         a1: v2,
                         a2: (Color *)v24,
                         a3: "Slider.TextColor",
                         a4: *v7);
  v8.__vftable = v2->__vftable;
  v9 = this->GetFgColor(this, result: &pScheme);
  this->m_TrackColor = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v8.GetColor)(
                          a1: v2,
                          a2: (Color *)v24,
                          a3: "Slider.TrackColor",
                          a4: *v9);
  v10.__vftable = v2->__vftable;
  v11 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor1 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v10.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor1",
                                  a4: *v11);
  v12.__vftable = v2->__vftable;
  v13 = this->GetFgColor(this, result: &pScheme);
  this->m_DisabledTextColor2 = *((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v12.GetColor)(
                                  a1: v2,
                                  a2: (Color *)v24,
                                  a3: "Slider.DisabledTextColor2",
                                  a4: *v13);
  this->_sliderBorder = v2->GetBorder(this: v2, a2: "ButtonBorder");
  this->_insetBorder = v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  leftCaption = this->_leftCaption;
  if ( leftCaption != nullptr )
  {
    v15 = leftCaption->__vftable;
    IsProportional = this->IsProportional;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v17 = IsProportional(this);
    v18 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v17);
    v15->SetFont(this: this->_leftCaption, a2: v18);
  }
  rightCaption = this->_rightCaption;
  if ( rightCaption != nullptr )
  {
    v20 = rightCaption->__vftable;
    v21 = this->__vftable;
    pScheme = (vgui::IScheme *)v2->__vftable;
    v22 = v21->IsProportional(this);
    v23 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(
            a1: v2,
            a2: "DefaultVerySmall",
            a3: v22);
    v20->SetFont(this: this->_rightCaption, a2: v23);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFA50
// Name: protected: virtual void vgui::Slider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetSettings(vgui::Slider *this, KeyValues *outResourceData)
{
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  vgui::Panel::GetSettings(this, outResourceData);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->GetUnlocalizedText(this: this->_leftCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "leftText", value: buf);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetUnlocalizedText(this: this->_rightCaption, a2: buf, a3: 256);
    KeyValues::SetString(this: outResourceData, keyName: "rightText", value: buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFAE0
// Name: protected: virtual void vgui::Slider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::ApplySettings(vgui::Slider *this@<ecx>, int a2@<ebx>, KeyValues *inResourceData)
{
  char *String; // ebx
  int Int; // eax
  char *right; // [esp+14h] [ebp+8h]

  vgui::Panel::ApplySettings(this, a2, a3: (int)this, inResourceData);
  String = KeyValues::GetString(this: inResourceData, keyName: "leftText", defaultValue: nullptr);
  right = KeyValues::GetString(this: inResourceData, keyName: "rightText", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "thumbwidth", defaultValue: 0);
  if ( Int != 0 )
    this->SetThumbWidth(this, a2: Int);
  this->SetTickCaptions(this, a2: String, a3: right);
}

//------------------------------------------------------------------------------
// Address: 0x103BFB50
// Name: protected: virtual char const __near * vgui::Slider::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall vgui::Slider::GetDescription(vgui::Slider *this)
{
  const char *Description; // eax

  Description = vgui::Panel::GetDescription(this);
  V_snprintf(pDest: buf_16, maxLen: 0x400u, pFormat: "%s, string leftText, string rightText", Description);
  return buf_16;
}

//------------------------------------------------------------------------------
// Address: 0x103BFB80
// Name: protected: virtual void vgui::Slider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetTrackRect(vgui::Slider *this, int *x, int *y, int *w, int *h)
{
  int v6; // ecx
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  *x = 0;
  v6 = wide;
  *y = 8;
  *w = v6 - (int)this->_nobSize;
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x103BFBE0
// Name: protected: virtual void vgui::Slider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::Paint(vgui::Slider *this)
{
  this->DrawTicks(this);
  this->DrawTickLabels(this);
  this->DrawNob(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BFC10
// Name: protected: virtual void vgui::Slider::DrawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTicks(vgui::Slider *this)
{
  vgui::Slider *v1; // ebx
  void (__thiscall *GetTrackRect)(vgui::Slider *, int *, int *, int *, int *); // eax
  float nobSize; // xmm0_4
  __m128i v4; // xmm2
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  int *p_m_nNumTicks; // esi
  bool v7; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int i; // edi
  int v10; // edi
  int j; // edi
  int x; // [esp+Ch] [ebp-1Ch] BYREF
  int tall; // [esp+10h] [ebp-18h] BYREF
  vgui::Slider *v14; // [esp+14h] [ebp-14h]
  int wide; // [esp+18h] [ebp-10h] BYREF
  float leftpixel; // [esp+1Ch] [ebp-Ch]
  float pixelspertick; // [esp+20h] [ebp-8h]
  int y; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  GetTrackRect = this->GetTrackRect;
  v14 = this;
  ((void (__stdcall *)(int *, int *, int *, int *))GetTrackRect)(a1: &x, a2: &y, a3: &wide, a4: &tall);
  nobSize = v1->_nobSize;
  v4 = _mm_cvtsi32_si128(v1->m_nNumTicks);
  IsEnabled = v1->IsEnabled;
  leftpixel = nobSize * 0.5;
  p_m_nNumTicks = &v1->m_nNumTicks;
  y += (int)nobSize;
  pixelspertick = (float)((float)wide - nobSize) / _mm_cvtepi32_ps(v4).m128_f32[0];
  v7 = IsEnabled(this: v1);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_TickColor);
    for ( i = 0; i <= *p_m_nNumTicks; ++i )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)i * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)i * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))DrawSetColor)(a1: *(_DWORD *)&v1->m_DisabledTextColor1);
    v10 = 0;
    if ( *p_m_nNumTicks >= 0 )
    {
      do
      {
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 1,
          a3: y + 1,
          a4: (int)(float)((float)((float)v10 * pixelspertick) + leftpixel) + 2,
          a5: y + 6);
        ++v10;
      }
      while ( v10 <= *p_m_nNumTicks );
      v1 = v14;
    }
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&v1->m_DisabledTextColor2);
    for ( j = 0; j <= *p_m_nNumTicks; ++j )
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: (int)(float)((float)((float)j * pixelspertick) + leftpixel),
        a3: y,
        a4: (int)(float)((float)((float)j * pixelspertick) + leftpixel) + 1,
        a5: y + 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFDA0
// Name: protected: virtual void vgui::Slider::DrawTickLabels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawTickLabels(vgui::Slider *this)
{
  bool (__thiscall *IsEnabled)(vgui::Panel *); // eax
  bool v3; // al
  vgui::TextImage *leftCaption; // ecx
  bool v5; // al
  vgui::TextImage *rightCaption; // ecx
  int rtall; // [esp+4h] [ebp-18h] BYREF
  int x; // [esp+8h] [ebp-14h] BYREF
  int tall; // [esp+Ch] [ebp-10h] BYREF
  int rwide; // [esp+10h] [ebp-Ch] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  IsEnabled = this->IsEnabled;
  y += 12;
  if ( IsEnabled(this) )
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_TickColor);
  else
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_DisabledTextColor1);
  if ( this->_leftCaption != nullptr )
  {
    this->_leftCaption->SetPos(this: this->_leftCaption, a2: 0, a3: y);
    v3 = this->IsEnabled(this);
    leftCaption = this->_leftCaption;
    if ( v3 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))leftCaption->SetColor)(
        a1: leftCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_leftCaption->Paint(this: this->_leftCaption);
  }
  if ( this->_rightCaption != nullptr )
  {
    this->_rightCaption->GetSize(this: this->_rightCaption, a2: &rwide, a3: &rtall);
    this->_rightCaption->SetPos(this: this->_rightCaption, a2: wide - rwide, a3: y);
    v5 = this->IsEnabled(this);
    rightCaption = this->_rightCaption;
    if ( v5 )
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_TickColor);
    else
      ((void (__thiscall *)(vgui::TextImage *, _DWORD))rightCaption->SetColor)(
        a1: rightCaption,
        a2: *(_DWORD *)&this->m_DisabledTextColor1);
    this->_rightCaption->Paint(this: this->_rightCaption);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFEF0
// Name: protected: virtual void vgui::Slider::DrawNob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::DrawNob(vgui::Slider *this)
{
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  int tall; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0],
    a3: tall / 2 + y - 8,
    a4: this->_nobPos[1],
    a5: tall / 2 + y + 8);
  if ( this->_sliderBorder != nullptr )
    this->_sliderBorder->Paint_2(
      this: this->_sliderBorder,
      a2: this->_nobPos[0],
      a3: tall / 2 + y - 8,
      a4: this->_nobPos[1],
      a5: tall / 2 + y + 8);
}

//------------------------------------------------------------------------------
// Address: 0x103BFFB0
// Name: public: virtual void vgui::Slider::SetTickCaptions(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const char *left, const char *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText_2(this: leftCaption, a2: left);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, text: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText_2(this: rightCaption, a2: right);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, text: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C0050
// Name: public: virtual void vgui::Slider::SetTickCaptions(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetTickCaptions(vgui::Slider *this, const wchar_t *left, const wchar_t *right)
{
  vgui::TextImage *leftCaption; // ecx
  vgui::TextImage *v5; // eax
  vgui::TextImage *v6; // eax
  vgui::TextImage *rightCaption; // ecx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax

  if ( left != nullptr )
  {
    leftCaption = this->_leftCaption;
    if ( leftCaption != nullptr )
    {
      leftCaption->SetText(this: leftCaption, a2: left, a3: false);
    }
    else
    {
      v5 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v5 != nullptr )
        v6 = vgui::TextImage::TextImage(this: v5, wszText: left);
      else
        v6 = nullptr;
      this->_leftCaption = v6;
    }
  }
  if ( right != nullptr )
  {
    rightCaption = this->_rightCaption;
    if ( rightCaption != nullptr )
    {
      rightCaption->SetText(this: rightCaption, a2: right, a3: false);
    }
    else
    {
      v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x7Cu);
      if ( v8 != nullptr )
        v9 = vgui::TextImage::TextImage(this: v8, wszText: right);
      else
        v9 = nullptr;
      this->_rightCaption = v9;
    }
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103C00F0
// Name: protected: virtual void vgui::Slider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::PaintBackground(vgui::Slider *this)
{
  int wide; // [esp+Ch] [ebp-10h] BYREF
  int x; // [esp+10h] [ebp-Ch] BYREF
  int tall; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::PaintBackground(this);
  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_TrackColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x, a3: y, a4: x + wide, a5: y + tall);
  if ( this->_insetBorder != nullptr )
    this->_insetBorder->Paint_2(this: this->_insetBorder, a2: x, a3: y, a4: x + wide, a5: y + tall);
}

//------------------------------------------------------------------------------
// Address: 0x103C0190
// Name: public: virtual void vgui::Slider::SetRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetRange(vgui::Slider *this, int min, int max)
{
  int value; // esi

  value = this->_value;
  this->_range[0] = min;
  this->_range[1] = max;
  if ( min < max )
  {
    if ( value >= min )
    {
      if ( value <= max )
        return;
      goto LABEL_4;
    }
LABEL_7:
    this->SetValue(this, a2: min, a3: true);
    return;
  }
  if ( value < max )
  {
LABEL_4:
    this->SetValue(this, a2: max, a3: true);
    return;
  }
  if ( value > min )
    goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x103C01F0
// Name: public: virtual void vgui::Slider::GetRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetRange(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_range;
}

//------------------------------------------------------------------------------
// Address: 0x103C0210
// Name: public: virtual void vgui::Slider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnCursorMoved(vgui::Slider *this@<ecx>, int a2@<edi>, int x, int y)
{
  int v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int _y; // [esp+4h] [ebp-10h] BYREF
  int tall; // [esp+8h] [ebp-Ch] BYREF
  int wide; // [esp+Ch] [ebp-8h] BYREF
  int _x; // [esp+10h] [ebp-4h] BYREF

  if ( this->_dragging )
  {
    ((void (__thiscall *)(vgui::IInput *, int *, int *, int))g_pVGuiInput->GetCursorPosition)(
      a1: g_pVGuiInput,
      a2: &x,
      a3: &y,
      a4: a2);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->GetTrackRect(this, a2: &_x, a3: &_y, a4: &wide, a5: &tall);
    v5 = this->_dragStartPos[0];
    v6 = this->_nobDragStartPos[0] - v5;
    v7 = this->_nobDragStartPos[1] - v5 + x;
    v8 = _x;
    v9 = x + v6;
    v10 = _x + wide;
    this->_nobPos[0] = v9;
    this->_nobPos[1] = v7;
    if ( v7 > v10 )
    {
      this->_nobPos[0] = v10 + v9 - v7;
      this->_nobPos[1] = v10;
    }
    v11 = this->_nobPos[0];
    if ( v11 < v8 )
    {
      this->_nobPos[1] += v11 - v8;
      this->_nobPos[0] = 0;
    }
    v12 = ((int (__thiscall *)(vgui::Slider *, int))this->EstimateValueAtPos)(a1: this, a2: v9);
    this->SetValue(this, a2: v12, a3: true);
    this->Repaint(this);
    this->SendSliderMovedMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0310
// Name: public: virtual void vgui::Slider::SetDragOnRepositionNob(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetDragOnRepositionNob(vgui::Slider *this, bool state)
{
  *((_BYTE *)this + 424) ^= (state ^ *((_BYTE *)this + 424)) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C0330
// Name: public: virtual bool vgui::Slider::IsDragOnRepositionNob(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragOnRepositionNob(vgui::Slider *this)
{
  return *((_BYTE *)this + 424) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C0340
// Name: public: virtual bool vgui::Slider::IsDragged(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Slider::IsDragged(vgui::Slider *this)
{
  return this->_dragging;
}

//------------------------------------------------------------------------------
// Address: 0x103C0350
// Name: protected: virtual void vgui::Slider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnKeyCodeTyped(vgui::Slider *this, int code)
{
  int v3; // eax
  int v4; // eax
  int (__thiscall *v5)(vgui::Slider *); // edx
  int v6; // eax
  int (__thiscall *GetValue)(vgui::Slider *); // eax
  int v8; // eax
  int *p_pertick; // ecx
  int *p_code; // edx
  int pertick; // [esp+4h] [ebp-8h] BYREF
  int min; // [esp+8h] [ebp-4h] BYREF

  switch ( code )
  {
    case 'J':
      p_pertick = &pertick;
      p_code = &code;
      goto LABEL_7;
    case 'K':
      p_pertick = &code;
      p_code = &pertick;
LABEL_7:
      this->GetRange(this, a2: p_code, a3: p_pertick);
      this->SetValue(this, a2: code, a3: true);
      break;
    case 'L':
      this->GetRange(this, a2: &pertick, a3: &code);
      GetValue = this->GetValue;
      *(float *)&min = (float)((float)code - (float)pertick) / (float)this->m_nNumTicks;
      v8 = GetValue(this);
      this->SetValue(this, a2: v8 + (int)*(float *)&min, a3: true);
      break;
    case 'M':
      this->GetRange(this, a2: &min, a3: &code);
      v5 = this->GetValue;
      *(float *)&pertick = (float)((float)code - (float)min) / (float)this->m_nNumTicks;
      v6 = v5(this);
      this->SetValue(this, a2: v6 - (int)*(float *)&pertick, a3: true);
      break;
    case 'X':
    case '[':
      v4 = this->GetValue(this);
      this->SetValue(this, a2: v4 + 1, a3: true);
      break;
    case 'Y':
    case 'Z':
      v3 = this->GetValue(this);
      this->SetValue(this, a2: v3 - 1, a3: true);
      break;
    default:
      vgui::Panel::OnKeyCodeTyped(this, keycode: (ButtonCode_t)code);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0500
// Name: public: virtual void vgui::Slider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::OnMouseReleased(vgui::Slider *this, ButtonCode_t code)
{
  if ( this->_dragging )
  {
    this->_dragging = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->SendSliderDragEndMessage(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0540
// Name: public: virtual void vgui::Slider::GetNobPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::GetNobPos(vgui::Slider *this, int *min, int *max)
{
  *(_QWORD *)min = *(_QWORD *)this->_nobPos;
}

//------------------------------------------------------------------------------
// Address: 0x103C0560
// Name: public: virtual void vgui::Slider::SetThumbWidth(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetThumbWidth(vgui::Slider *this, int width)
{
  this->_nobSize = (float)width;
}

//------------------------------------------------------------------------------
// Address: 0x103C0580
// Name: public: virtual void vgui::Slider::SetNumTicks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetNumTicks(vgui::Slider *this, int ticks)
{
  this->m_nNumTicks = ticks;
}

//------------------------------------------------------------------------------
// Address: 0x103C0590
// Name: protected: virtual void vgui::Slider::RecomputeNobPosFromValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::RecomputeNobPosFromValue(vgui::Slider *this)
{
  char v2; // bl
  float value; // xmm1_4
  int *range; // eax
  int v5; // ecx
  int v6; // edx
  float v7; // xmm2_4
  int v8; // edx
  float v9; // xmm3_4
  float nobSize; // xmm1_4
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // ecx
  int y; // [esp+8h] [ebp-10h] BYREF
  int tall; // [esp+Ch] [ebp-Ch] BYREF
  int x; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  v2 = *((_BYTE *)this + 424);
  value = (float)this->_value;
  range = this->_range;
  if ( (v2 & 2) != 0 )
  {
    v5 = this->_value;
    v6 = this->_subrange[0];
    range = this->_subrange;
    if ( v5 >= v6 )
    {
      v6 = this->_subrange[1];
      if ( v5 <= v6 )
        v6 = this->_value;
    }
    value = (float)v6;
  }
  v7 = 0.0;
  v8 = wide;
  v9 = (float)(range[1] - *range);
  if ( v9 != 0.0 )
    v7 = (float)(value - (float)*range) / v9;
  if ( (v2 & 4) != 0 )
    v7 = 1.0 - v7;
  nobSize = this->_nobSize;
  v11 = x;
  v12 = (float)((float)((float)((float)wide - nobSize) * v7) + (float)x) + 0.5;
  this->_nobPos[0] = (int)v12;
  v13 = v8 + v11;
  this->_nobPos[1] = (int)(float)(nobSize + v12);
  if ( (int)(float)(nobSize + v12) > v13 )
  {
    this->_nobPos[0] = v13 - (int)nobSize;
    this->_nobPos[1] = v13;
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C06B0
// Name: public: virtual void vgui::Slider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge vgui::Slider::OnMousePressed(vgui::Slider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  int v4; // edx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool (__thiscall *IsDragOnRepositionNob)(vgui::Slider *); // edx
  char v8; // bl
  void (__thiscall *SendSliderDragStartMessage)(vgui::Slider *); // edx
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v11; // edi
  vgui::IInput_vtbl *v12; // ebx
  int v13; // eax
  bool v14; // zf
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int _y; // [esp+4h] [ebp-28h] BYREF
  int tall; // [esp+8h] [ebp-24h] BYREF
  float value; // [esp+Ch] [ebp-20h]
  int _x; // [esp+10h] [ebp-1Ch] BYREF
  int wide; // [esp+14h] [ebp-18h] BYREF
  int y; // [esp+18h] [ebp-14h] BYREF
  int min; // [esp+1Ch] [ebp-10h] BYREF
  int max; // [esp+20h] [ebp-Ch] BYREF
  int x; // [esp+24h] [ebp-8h] BYREF
  bool bPostDragStartSignal; // [esp+2Bh] [ebp-1h]

  if ( this->IsEnabled(this) )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    this->RequestFocus(this, a2: 0);
    bPostDragStartSignal = false;
    if ( x >= this->_nobPos[0] && x < this->_nobPos[1] )
    {
      bPostDragStartSignal = true;
LABEL_14:
      GetVPanel = this->GetVPanel;
      this->_dragging = true;
      v11 = g_pVGuiInput;
      v12 = g_pVGuiInput->__vftable;
      v13 = GetVPanel(this);
      v12->SetMouseCapture(this: v11, a2: v13);
      v14 = !bPostDragStartSignal;
      v15 = this->_nobPos[1];
      v16 = x;
      this->_nobDragStartPos[0] = this->_nobPos[0];
      v17 = y;
      this->_nobDragStartPos[1] = v15;
      this->_dragStartPos[0] = v16;
      this->_dragStartPos[1] = v17;
      if ( !v14 )
        this->SendSliderDragStartMessage(this);
      return;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int))this->GetRange)(a1: this, a2: &min, a3: &max, a4: a2);
    if ( (*((_BYTE *)this + 424) & 2) != 0 )
    {
      v4 = this->_subrange[1];
      min = this->_subrange[0];
      max = v4;
    }
    ((void (__thiscall *)(vgui::Slider *, int *, int *, int *))this->GetTrackRect)(
      a1: this,
      a2: &_x,
      a3: &_y,
      a4: &wide);
    if ( wide > 0 )
    {
      v5 = (float)(x - _x) / (float)(wide - 1);
      v6 = 0.0;
      if ( v5 >= 0.0 )
      {
        v6 = 1.0;
        if ( v5 <= 1.0 )
          v6 = (float)(x - _x) / (float)(wide - 1);
      }
      IsDragOnRepositionNob = this->IsDragOnRepositionNob;
      value = (float)(v6 * (float)(max - min)) + (float)min;
      v8 = ((int (__thiscall *)(vgui::Slider *, int *))IsDragOnRepositionNob)(a1: this, a2: &tall);
      if ( v8 != 0 )
      {
        SendSliderDragStartMessage = this->SendSliderDragStartMessage;
        this->_dragging = true;
        SendSliderDragStartMessage(this);
      }
      ((void (__thiscall *)(vgui::Slider *, int))this->SetValue)(a1: this, a2: (int)(float)(value + 0.5));
      if ( v8 != 0 )
        goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C0880
// Name: public: vgui::Slider::Slider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__thiscall vgui::Slider::Slider(vgui::Slider *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::Slider_vtbl *)&vgui::Slider::`vftable';
  if ( `vgui::Slider::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "Slider");
    v4->pfnClassName = vgui::Slider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::Slider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::Slider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "Slider");
    v5->pfnClassName = vgui::Slider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::Slider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::Slider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
    v6->pfnClassName = vgui::Slider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_TickColor = 0;
  this->m_TrackColor = 0;
  this->m_DisabledTextColor1 = 0;
  this->m_DisabledTextColor2 = 0;
  *((_BYTE *)this + 424) &= ~1u;
  this->_dragging = false;
  this->_value = 0;
  this->_range[0] = 0;
  this->_range[1] = 0;
  this->_buttonOffset = 0;
  this->_sliderBorder = nullptr;
  this->_insetBorder = nullptr;
  this->m_nNumTicks = 10;
  this->_leftCaption = nullptr;
  this->_rightCaption = nullptr;
  this->_nobSize = 8.0;
  vgui::Slider::RecomputeNobPosFromValue(this);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  vgui::Panel::SetBlockDragChaining(this, block: true);
  *((_BYTE *)this + 424) &= 0xF9u;
  this->_subrange[0] = 0;
  this->_subrange[1] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C09E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Slider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Slider::GetMessageMap(vgui::Slider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Slider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetMessageMap'::`2'::s_pMap;
  `vgui::Slider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Slider");
  `vgui::Slider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C0A10
// Name: public: virtual struct PanelAnimationMap __near * vgui::Slider::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Slider::GetAnimMap(vgui::Slider *this)
{
  return FindOrAddPanelAnimationMap(className: "Slider");
}

//------------------------------------------------------------------------------
// Address: 0x103C0A20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Slider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Slider::GetKBMap(vgui::Slider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Slider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Slider::GetKBMap'::`2'::s_pMap;
  `vgui::Slider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  `vgui::Slider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C0A50
// Name: Create_Slider
// Source: json
//------------------------------------------------------------------------------
vgui::Slider *__cdecl Create_Slider()
{
  vgui::Slider *v0; // eax

  v0 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v0 != nullptr )
    return vgui::Slider::Slider(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D6450
// Name: public: virtual void vgui::Slider::SetButtonOffset(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Slider::SetButtonOffset(vgui::Slider *this, int buttonOffset)
{
  this->_buttonOffset = buttonOffset;
}

} // namespace client
