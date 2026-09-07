// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/statuswindow.cpp
// Functions: 5
// ============================================================

#include "utils\scenemanager\statuswindow.h"

//------------------------------------------------------------------------------
// Address: 0x00412CD0
// Name: public: CStatusWindow::CStatusWindow(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CStatusWindow *__thiscall CStatusWindow::CStatusWindow(
        CStatusWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  int *p_r; // eax
  int i; // ecx
  mxScrollbar *v10; // eax
  mxScrollbar *v11; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label, style: 0);
  this->__vftable = (CStatusWindow_vtbl *)&CStatusWindow::`vftable';
  this->m_pScrollbar = nullptr;
  p_r = &this->m_rgTextLines[0].r;
  for ( i = 1024; i != 0; --i )
  {
    *((_BYTE *)p_r - 512) = 0;
    *p_r = 82;
    p_r[1] = 173;
    p_r[2] = 216;
    p_r[3] = 0;
    p_r += 132;
  }
  this->m_nCurrentLine = 0;
  v10 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v10 != nullptr )
    v11 = mxScrollbar::mxScrollbar(this: v10, parent: this, x: 0, y: 0, w: 12, h: 100, id: 1000, style: 1);
  else
    v11 = nullptr;
  this->m_pScrollbar = v11;
  mxScrollbar::setRange(this: v11, min: 0, max: 1000);
  mxScrollbar::setPagesize(this: this->m_pScrollbar, size: 100);
  g_pStatusWindow = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412DA0
// Name: public: virtual void CStatusWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusWindow::redraw(CStatusWindow *this)
{
  int v2; // eax
  mxScrollbar *m_pScrollbar; // ecx
  int MaxValue; // esi
  int Pagesize; // edi
  int v6; // eax
  int v7; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int b_low; // esi
  int g_low; // edx
  char *v14; // edi
  int r_low; // eax
  COLORREF v16; // esi
  int v17; // eax
  double v18; // [esp+0h] [ebp-C4h]
  CDrawHelper helper; // [esp+14h] [ebp-B0h] BYREF
  char sz[32]; // [esp+68h] [ebp-5Ch] BYREF
  tagRECT rc; // [esp+88h] [ebp-3Ch] BYREF
  int v22; // [esp+98h] [ebp-2Ch]
  int offset; // [esp+9Ch] [ebp-28h]
  tagRECT rcTime; // [esp+A0h] [ebp-24h] BYREF
  int i; // [esp+B0h] [ebp-14h]
  tagRECT rcText; // [esp+B4h] [ebp-10h] BYREF

  if ( this->m_pScrollbar != nullptr )
  {
    CDrawHelper::CDrawHelper(this: &helper, widget: this, bgColor: 0);
    CDrawHelper::GetClientRect(this: &helper, &rc);
    rcText = rc;
    InflateRect(lprc: &rcText, dx: -4, dy: 0);
    v2 = mxWidget::h2(this);
    m_pScrollbar = this->m_pScrollbar;
    rcText.bottom = v2 - 4;
    rcText.top = v2 - 16;
    MaxValue = mxScrollbar::getMaxValue(this: m_pScrollbar);
    Pagesize = mxScrollbar::getPagesize(this: this->m_pScrollbar);
    v6 = (MaxValue - Pagesize - mxScrollbar::getValue(this: this->m_pScrollbar) + 11) / 12;
    v7 = 0;
    i = 0;
    v8 = v6 < 0 ? 0 : v6;
    v9 = 1024 - v8;
    offset = v8;
    v22 = 1024 - v8;
    if ( 1024 - v8 > 0 )
    {
      do
      {
        v10 = this->m_nCurrentLine - v7 - 1;
        if ( v10 > 0 )
        {
          if ( rcText.bottom < 0 )
            break;
          v11 = ((_WORD)v10 - (_WORD)v8) & 0x3FF;
          b_low = LOBYTE(this->m_rgTextLines[v11].b);
          g_low = LOBYTE(this->m_rgTextLines[v11].g);
          v14 = (char *)this + v11 * 528;
          r_low = LOBYTE(this->m_rgTextLines[v11].r);
          rcTime = rcText;
          v18 = *((float *)v14 + 134);
          v16 = r_low | ((g_low | (b_low << 8)) << 8);
          rcTime.right = rcText.left + 50;
          sprintf(string: sz, format: "%.3f", v18);
          v17 = CDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0xA, weight: 400, fmt: sz);
          rcTime.left = rcTime.right - v17 - 5;
          CDrawHelper::DrawColoredText(
            this: &helper,
            font: "Arial",
            pointsize: 10,
            weight: 400,
            clr: 0x96FFFFu,
            rcText: &rcTime,
            fmt: sz);
          rcTime.top = rcText.top;
          *(_QWORD *)&rcTime.right = *(_QWORD *)&rcText.right;
          rcTime.left = rcText.left + 50;
          CDrawHelper::DrawColoredText(
            this: &helper,
            font: "Arial",
            pointsize: 10,
            weight: 400,
            clr: v16,
            rcText: &rcTime,
            fmt: v14 + 12);
          OffsetRect(lprc: &rcText, dx: 0, dy: -12);
          v9 = v22;
          v7 = i;
          LOWORD(v8) = offset;
        }
        i = ++v7;
      }
      while ( v7 < v9 );
    }
    CDrawHelper::~CDrawHelper(this: &helper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412FD0
// Name: private: void CStatusWindow::PositionSliders(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusWindow::PositionSliders(CStatusWindow *this, int sboffset)
{
  int m_nCurrentLine; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // edi

  m_nCurrentLine = this->m_nCurrentLine;
  if ( m_nCurrentLine <= 1024 )
  {
    if ( m_nCurrentLine <= 1 )
      m_nCurrentLine = 1;
  }
  else
  {
    m_nCurrentLine = 1024;
  }
  v4 = mxWidget::h2(this);
  v5 = 12 * m_nCurrentLine;
  v6 = v5;
  if ( v5 <= v4 )
    v6 = v4;
  mxWidget::setVisible(this: this->m_pScrollbar, b: v5 > v4);
  mxScrollbar::setPagesize(this: this->m_pScrollbar, size: v4);
  mxScrollbar::setRange(this: this->m_pScrollbar, min: 0, max: v6);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00413050
// Name: public: virtual int CStatusWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStatusWindow::handleEvent(CStatusWindow *this, mxEvent *event)
{
  int v3; // ecx
  int result; // eax
  int v5; // eax
  int MaxValue; // eax
  int height; // edi
  int v8; // [esp-4h] [ebp-8h]

  v3 = event->event;
  result = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      v8 = mxWidget::h2(this);
      v5 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pScrollbar, x: v5 - 12, y: 0, w: 12, h: v8);
      CStatusWindow::PositionSliders(this, sboffset: 0);
      MaxValue = mxScrollbar::getMaxValue(this: this->m_pScrollbar);
      mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: MaxValue);
      return 1;
    }
  }
  else if ( event->action == 1000 )
  {
    if ( event->modifiers == 5 )
    {
      height = event->height;
      mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: height);
      CStatusWindow::PositionSliders(this, sboffset: height);
    }
    return 1;
  }
  else
  {
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413140
// Name: public: void CStatusWindow::StatusPrint(int,int,int,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusWindow::StatusPrint(CStatusWindow *this, int r, int g, int b, bool overwrite, const char *text)
{
  double v7; // st7
  int v8; // ebx
  const char *v9; // eax
  char *v10; // edx
  char v11; // cl
  unsigned __int8 *v12; // esi
  float v13; // xmm0_4
  int MaxValue; // eax
  char fixedtext[512]; // [esp+14h] [ebp-224h] BYREF
  char sz[32]; // [esp+214h] [ebp-24h] BYREF
  float curtime; // [esp+234h] [ebp-4h]

  v7 = _Plat_FloatTime();
  curtime = v7;
  sprintf(string: sz, format: "%.3f  ", v7);
  OutputDebugStringA(lpOutputString: sz);
  OutputDebugStringA(lpOutputString: text);
  v8 = 0;
  v9 = text;
  v10 = fixedtext;
  while ( *v9 != 0 )
  {
    if ( v8 >= 511 )
      break;
    v11 = *v9;
    if ( *v9 == 10 || v11 == 13 )
    {
      ++v9;
    }
    else
    {
      *v10++ = v11;
      ++v9;
      ++v8;
    }
  }
  *v10 = 0;
  if ( overwrite )
    --this->m_nCurrentLine;
  v12 = (unsigned __int8 *)this + 528 * (this->m_nCurrentLine & 0x3FF);
  strncpy(dest: v12 + 12, source: (unsigned __int8 *)fixedtext, count: 0x1FFu);
  v13 = curtime;
  v12[523] = 0;
  *((_DWORD *)v12 + 131) = r;
  *((_DWORD *)v12 + 132) = g;
  *((_DWORD *)v12 + 133) = b;
  *((float *)v12 + 134) = v13;
  if ( ++this->m_nCurrentLine <= 1024 )
    CStatusWindow::PositionSliders(this, sboffset: 0);
  MaxValue = mxScrollbar::getMaxValue(this: this->m_pScrollbar);
  mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: MaxValue);
  this->redraw(this);
}
