// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/image.cpp
// Functions: 25
// ============================================================

#include "vgui2\vgui_controls\image.h"

//------------------------------------------------------------------------------
// Address: 0x10009E60
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(CVTFTexture *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x102DC250
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x102DC260
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x102DC280
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x102DC2A0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x102DC2C0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102DC2D0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x102DC2F0
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC330
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x102DC350
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC390
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC3D0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC410
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102DC460
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x102DC480
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC4C0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x102DC4E0
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC510
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC530
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC570
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC590
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC5D0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x102DC5F0
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC610
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x102DC650
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

// ============================================================
// Overlay from AdminServer (Missing functions)
// ============================================================
namespace AdminServer {

//------------------------------------------------------------------------------
// Address: 0x100664E0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100664F0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x10066510
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x10066530
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x10066550
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10066560
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x10066580
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x100665C0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x100665E0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10066620
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10066660
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x100666A0
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100666F0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10066710
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10066750
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x10066770
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100667A0
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100667C0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10066800
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10066820
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10066860
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x10066880
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x100668A0
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x100668E0
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x100668F0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x10066900
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace AdminServer

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x004098B0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x00409900
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x0045BDB0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0045BDC0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x0045BDE0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x0045BE00
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x0045BE20
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0045BE30
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x0045BE50
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x0045BE90
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x0045BEB0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0045BEF0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0045BF30
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0045BF70
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0045BFC0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0045BFE0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x0045C020
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x0045C040
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x0045C070
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0045C090
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0045C0D0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0045C0F0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0045C130
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x0045C150
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x0045C170
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x0045C1A0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace avitest

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x10088C80
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10088C90
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x10088CB0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x10088CD0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x10088CF0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x10088D00
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x10088D20
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10088D60
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x10088D80
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10088DC0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10088E00
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10088E40
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10088E90
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10088EB0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10088EF0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x10088F10
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10088F40
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10088F60
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10088FA0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10088FC0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10089000
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x10089020
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x10089040
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10089080
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x10089090
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace dedicated

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00409180
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x004C6940
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x0063FF90
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0063FFA0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x0063FFC0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x0063FFE0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0063FFF0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00640010
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00640050
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00640070
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x006400B0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x006400F0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00640130
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00640180
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x006401A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x006401E0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00640200
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00640230
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00640250
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00640290
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x006402B0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x006402F0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x00640310
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x00640330
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00640370
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x00640380
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101C2CD0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(CVTFTexture *this)
{
  return this->m_nWidth;
}

//------------------------------------------------------------------------------
// Address: 0x102DC360
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x102DC380
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x102DC3A0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x102DC3C0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x102DC3F0
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC430
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x102DC450
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC490
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC4D0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC560
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x102DC580
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC5C0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x102DC5E0
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x102DC630
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC670
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC690
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102DC6D0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x102DC6F0
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x102DC710
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x102DC740
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1000C8A0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x1008A5D0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x1032F790
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1032F7A0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x1032F7C0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x1032F7E0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1032F7F0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x1032F810
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1032F850
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1032F870
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1032F8B0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1032F8F0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1032F930
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1032F980
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1032F9A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1032F9E0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1032FA00
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1032FA30
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1032FA50
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1032FA90
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1032FAB0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1032FAF0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x1032FB10
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1032FB30
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x1032FB60
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x10057B30
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x100D8570
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100D8580
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x100D85A0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x100D85C0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x100D85E0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x100D85F0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x100D8610
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x100D8650
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x100D8670
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x100D86B0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x100D86F0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x100D8730
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100D8780
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x100D87A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x100D87E0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x100D8800
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100D8830
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100D8850
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100D8890
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100D88B0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x100D88F0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x100D8910
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x100D8930
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x100D8960
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004142E0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x00418970
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x0047F450
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0047F460
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x0047F480
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x0047F4A0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x0047F4B0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x0047F4D0
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x0047F510
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x0047F530
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0047F570
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0047F5B0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x0047F5F0
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0047F640
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x0047F660
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x0047F6A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x0047F6C0
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x0047F6F0
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0047F710
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0047F750
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0047F770
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x0047F7B0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x0047F7D0
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x0047F7F0
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x0047F820
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x0047F830
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x0040A1B0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x0040A200
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x00463570
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00463580
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x004635A0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x004635C0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x004635E0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004635F0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00463610
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00463650
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00463660
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004636A0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004636E0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00463720
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int *v4; // eax
  int i; // esi

  if ( numPoints > 0 )
  {
    v4 = py;
    for ( i = numPoints; i != 0; --i )
    {
      *(int *)((char *)v4 + (char *)px - (char *)py) += this->_pos[0];
      *v4++ += this->_pos[1];
    }
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: numPoints);
}

//------------------------------------------------------------------------------
// Address: 0x00463770
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00463780
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x004637C0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x004637D0
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00463800
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00463820
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00463860
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00463880
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004638C0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x004638D0
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x004638E0
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00463920
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0043AE30
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x004C6350
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x006701E0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x006701F0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x00670210
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x00670230
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00670240
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00670260
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x006702A0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x006702C0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00670300
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00670340
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00670380
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x006703D0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x006703F0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00670430
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00670450
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00670480
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x006704A0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x006704E0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00670500
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00670540
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x00670560
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x00670580
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x006705B0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x006705C0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10013DF0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x1007D4E0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1007D4F0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x1007D510
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x1007D530
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x1007D550
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1007D560
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x1007D580
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1007D5C0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1007D5E0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1007D620
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1007D660
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1007D6A0
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1007D6F0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1007D710
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1007D750
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1007D770
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1007D7A0
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1007D7C0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1007D800
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1007D820
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1007D860
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x1007D880
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1007D8A0
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x1007D8D0
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x1007D8E0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace ServerBrowser

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x100978B0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100978C0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x100978E0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x10097900
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x10097920
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x10097940
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10097980
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x100979A0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x100979E0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10097A20
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x10097A60
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10097AB0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x10097AD0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x10097B10
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x10097B30
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10097B60
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10097B80
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10097BC0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10097BE0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x10097C20
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x10097C40
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x10097C60
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x10097C90
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x10097CA0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00416CA0
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x00471DC0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00471DD0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x00471DF0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x00471E10
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x00471E30
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00471E40
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00471E60
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00471EA0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00471EC0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00471F00
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00471F40
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00471F80
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00471FD0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x00471FF0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00472030
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00472050
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00472080
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004720A0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004720E0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00472100
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00472140
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x00472160
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x00472180
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x004721B0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x004721C0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004B37F0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004B3800
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x004B3820
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x004B3840
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x004B3860
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004B3870
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x004B3890
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x004B38D0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x004B38E0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004B3920
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004B3960
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004B39A0
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int *v4; // eax
  int i; // esi

  if ( numPoints > 0 )
  {
    v4 = py;
    for ( i = numPoints; i != 0; --i )
    {
      *(int *)((char *)v4 + (char *)px - (char *)py) += this->_pos[0];
      *v4++ += this->_pos[1];
    }
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: numPoints);
}

//------------------------------------------------------------------------------
// Address: 0x004B39F0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x004B3A00
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x004B3A40
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x004B3A50
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x004B3A80
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004B3AA0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004B3AE0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004B3B00
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004B3B40
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x004B3B50
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x004B3B60
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x004B3B90
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vp4 (Missing functions)
// ============================================================
namespace vp4 {

//------------------------------------------------------------------------------
// Address: 0x00407020
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x00467370
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00467380
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x004673A0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x004673C0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x004673E0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x004673F0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00467410
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00467450
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00467470
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004674B0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x004674F0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00467530
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00467580
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x004675A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x004675E0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00467600
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00467630
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00467650
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00467690
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004676B0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004676F0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x00467710
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x00467730
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x00467760
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x00467770
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace vp4

// ============================================================
// Overlay from vtex_gui (Missing functions)
// ============================================================
namespace vtex_gui {

//------------------------------------------------------------------------------
// Address: 0x0040D2A0
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x00467E90
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00467EA0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x00467EC0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x00467EE0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x00467F00
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x00467F10
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x00467F30
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00467F70
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00467F90
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00467FD0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00468010
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x00468050
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004680A0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x004680C0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00468100
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x00468120
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x00468150
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00468170
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004681B0
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004681D0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x00468210
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x00468230
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x00468250
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x004682A0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x004682B0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace vtex_gui

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1015A780
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::ImageList *this)
{
  return this->m_Images.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1039F370
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1039F380
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x1039F3A0
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x1039F3C0
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x1039F3E0
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1039F3F0
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x1039F410
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1039F450
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1039F470
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1039F4B0
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1039F4F0
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x1039F530
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1039F580
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x1039F5A0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x1039F5E0
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x1039F600
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x1039F630
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1039F650
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1039F690
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1039F6B0
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x1039F6F0
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x1039F710
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x1039F730
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x1039F760
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10097A00
// Name: public: virtual int vgui::Image::GetTall(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetTall(vgui::Image *this)
{
  return this->_size[1];
}

//------------------------------------------------------------------------------
// Address: 0x10376BC0
// Name: public: virtual int vgui::Image::GetWide(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Image::GetWide(vgui::Image *this)
{
  return this->_size[0];
}

//------------------------------------------------------------------------------
// Address: 0x103CBEE0
// Name: public: virtual vgui::Image::~Image(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::~Image(vgui::Image *this)
{
  this->__vftable = (vgui::Image_vtbl *)&vgui::IImage::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x103CBEF0
// Name: public: virtual void vgui::Image::SetPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetPos(vgui::Image *this, int x, int y)
{
  this->_pos[0] = x;
  this->_pos[1] = y;
}

//------------------------------------------------------------------------------
// Address: 0x103CBF10
// Name: public: virtual void vgui::Image::GetPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetPos(vgui::Image *this, int *x, int *y)
{
  *(_QWORD *)x = *(_QWORD *)this->_pos;
}

//------------------------------------------------------------------------------
// Address: 0x103CBF30
// Name: public: virtual void vgui::Image::GetSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetSize(vgui::Image *this, int *wide, int *tall)
{
  *(_QWORD *)wide = *(_QWORD *)this->_size;
}

//------------------------------------------------------------------------------
// Address: 0x103CBF50
// Name: public: virtual void vgui::Image::GetContentSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::GetContentSize(vgui::Image *this, int *wide, int *tall)
{
  this->GetSize(this, a2: wide, a3: tall);
}

//------------------------------------------------------------------------------
// Address: 0x103CBF60
// Name: protected: virtual void vgui::Image::SetSize(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetSize(vgui::Image *this, int wide, int tall)
{
  this->_size[0] = wide;
  this->_size[1] = tall;
}

//------------------------------------------------------------------------------
// Address: 0x103CBF80
// Name: protected: virtual void vgui::Image::DrawSetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, Color col)
{
  g_pVGuiSurface->DrawSetColor_2(
    this: g_pVGuiSurface,
    a2: col._color[0],
    a3: col._color[1],
    a4: col._color[2],
    a5: col._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x103CBFC0
// Name: protected: virtual void vgui::Image::DrawSetColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x103CBFE0
// Name: protected: virtual void vgui::Image::DrawFilledRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawFilledRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x103CC020
// Name: protected: virtual void vgui::Image::DrawOutlinedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawOutlinedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawOutlinedRect(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x103CC060
// Name: protected: virtual void vgui::Image::DrawLine(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawLine(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawLine(
    this: g_pVGuiSurface,
    a2: x0 + this->_pos[0],
    a3: y0 + this->_pos[1],
    a4: this->_pos[0] + x1,
    a5: this->_pos[1] + y1);
}

//------------------------------------------------------------------------------
// Address: 0x103CC0A0
// Name: protected: virtual void vgui::Image::DrawPolyLine(int __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPolyLine(vgui::Image *this, int *px, int *py, int numPoints)
{
  int v4; // esi
  int *v5; // eax

  v4 = numPoints;
  if ( numPoints > 0 )
  {
    v5 = py;
    do
    {
      *(int *)((char *)v5 + (char *)px - (char *)py) += this->_pos[0];
      *v5++ += this->_pos[1];
      --v4;
    }
    while ( v4 != 0 );
    v4 = numPoints;
  }
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103CC0F0
// Name: protected: virtual void vgui::Image::DrawSetTextFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextFont(vgui::Image *this, unsigned int font)
{
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
}

//------------------------------------------------------------------------------
// Address: 0x103CC110
// Name: protected: virtual void vgui::Image::DrawSetTextColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, Color sc)
{
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: sc._color[0],
    a3: sc._color[1],
    a4: sc._color[2],
    a5: sc._color[3]);
}

//------------------------------------------------------------------------------
// Address: 0x103CC150
// Name: protected: virtual void vgui::Image::DrawSetTextColor(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextColor(vgui::Image *this, int r, int g, int b, int a)
{
  g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
}

//------------------------------------------------------------------------------
// Address: 0x103CC170
// Name: protected: virtual void vgui::Image::DrawSetTextPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTextPos(vgui::Image *this, int x, int y)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
}

//------------------------------------------------------------------------------
// Address: 0x103CC1A0
// Name: protected: virtual void vgui::Image::DrawPrintText(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x103CC1C0
// Name: protected: virtual void vgui::Image::DrawPrintText(int,int,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintText(vgui::Image *this, int x, int y, const wchar_t *str, int strlen)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: str, a3: strlen, a4: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x103CC200
// Name: protected: virtual void vgui::Image::DrawPrintChar(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int ch)
{
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x103CC220
// Name: protected: virtual void vgui::Image::DrawPrintChar(int,int,wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawPrintChar(vgui::Image *this, int x, int y, int ch)
{
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x + this->_pos[0], a3: y + this->_pos[1]);
  g_pVGuiSurface->DrawUnicodeChar(this: g_pVGuiSurface, a2: ch, a3: FONT_DRAW_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x103CC260
// Name: protected: virtual void vgui::Image::DrawSetTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawSetTexture(vgui::Image *this, int id)
{
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: id);
}

//------------------------------------------------------------------------------
// Address: 0x103CC280
// Name: protected: virtual void vgui::Image::DrawTexturedRect(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::DrawTexturedRect(vgui::Image *this, int x0, int y0, int x1, int y1)
{
  g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: x0, a3: y0, a4: x1, a5: y1);
}

//------------------------------------------------------------------------------
// Address: 0x103CC2A0
// Name: public: virtual void vgui::Image::SetColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Image::SetColor(vgui::Image *this, Color color)
{
  this->_color = color;
  ((void (__thiscall *)(_DWORD, _DWORD))this->DrawSetTextColor_2)(a1: this, a2: color);
}

//------------------------------------------------------------------------------
// Address: 0x103CC2D0
// Name: public: vgui::Image::Image(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Image *__thiscall vgui::Image::Image(vgui::Image *this)
{
  this->_pos[0] = 0;
  this->_pos[1] = 0;
  this->_size[0] = 0;
  this->_size[1] = 0;
  this->__vftable = (vgui::Image_vtbl *)&vgui::Image::`vftable';
  this->_color = (Color)-1;
  ((void (__thiscall *)(vgui::Image *, int))this->DrawSetTextColor_2)(a1: this, a2: -1);
  return this;
}

} // namespace server
