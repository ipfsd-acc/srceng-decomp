// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/drawhelper.cpp
// Functions: 9
// ============================================================

#include "utils\scenemanager\drawhelper.h"

//------------------------------------------------------------------------------
// Address: 0x00405770
// Name: private: void CDrawHelper::Init(class mxWindow __near *,int,int,int,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawHelper::Init(CDrawHelper *this, mxWindow *widget, int x, int y, int w, int h, COLORREF bgColor)
{
  int v8; // eax
  int v9; // eax
  HWND__ *Handle; // eax
  HDC__ *DC; // eax
  int m_x; // ecx
  int m_y; // edx
  int v14; // edi
  int v15; // ecx
  HDC__ *CompatibleDC; // eax
  int m_h; // edx
  HDC__ *m_dcReal; // ecx
  HBITMAP__ *CompatibleBitmap; // eax
  HBRUSH SolidBrush; // eax
  HBRUSH v21; // edi
  HDC__ *m_dcMemory; // [esp-8h] [ebp-20h]
  int v23; // [esp-8h] [ebp-20h]
  int v24; // [esp-4h] [ebp-1Ch]
  tagRECT rcFill; // [esp+8h] [ebp-10h] BYREF

  this->m_x = x;
  v8 = w;
  this->m_y = y;
  if ( w == 0 )
    v8 = mxWidget::w2(this: widget);
  this->m_w = v8;
  v9 = h;
  if ( h == 0 )
    v9 = mxWidget::h2(this: widget);
  this->m_h = v9;
  Handle = (HWND__ *)mxWidget::getHandle(this: widget);
  this->m_hWnd = Handle;
  DC = GetDC(hWnd: Handle);
  m_x = this->m_x;
  m_y = this->m_y;
  v14 = m_x + this->m_w;
  this->m_rcClient.left = m_x;
  v15 = m_y + this->m_h;
  this->m_dcReal = DC;
  this->m_rcClient.top = m_y;
  this->m_rcClient.right = v14;
  this->m_rcClient.bottom = v15;
  CompatibleDC = CreateCompatibleDC(hdc: DC);
  m_h = this->m_h;
  m_dcReal = this->m_dcReal;
  this->m_dcMemory = CompatibleDC;
  CompatibleBitmap = CreateCompatibleBitmap(hdc: m_dcReal, cx: this->m_w, cy: m_h);
  m_dcMemory = this->m_dcMemory;
  this->m_bmMemory = CompatibleBitmap;
  this->m_bmOld = (HBITMAP__ *)SelectObject(hdc: m_dcMemory, h: CompatibleBitmap);
  this->m_clrOld = SetBkColor(hdc: this->m_dcMemory, color: bgColor);
  SolidBrush = CreateSolidBrush(color: bgColor);
  v24 = -this->m_rcClient.top;
  v21 = SolidBrush;
  v23 = -this->m_rcClient.left;
  rcFill = this->m_rcClient;
  OffsetRect(lprc: &rcFill, dx: v23, dy: v24);
  FillRect(hDC: this->m_dcMemory, lprc: &rcFill, hbr: v21);
  DeleteObject(ho: v21);
  this->m_ClipRegion = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405880
// Name: public: void CDrawHelper::GetClientRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawHelper::GetClientRect(CDrawHelper *this, tagRECT *rc)
{
  rc->top = 0;
  rc->left = 0;
  rc->right = this->m_w;
  rc->bottom = this->m_h;
}

//------------------------------------------------------------------------------
// Address: 0x004058B0
// Name: public: static int CDrawHelper::CalcTextWidth(char const __near *,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
int CDrawHelper::CalcTextWidth(const char *font, HFONT__ *pointsize, int weight, const char *fmt, ...)
{
  HFONT FontA; // edi
  HDC DC; // esi
  tagRECT rcText; // [esp+Ch] [ebp-10h] BYREF
  HFONT__ *oldFont; // [esp+28h] [ebp+Ch]
  va_list ap; // [esp+34h] [ebp+18h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -(int)pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: 0,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  DC = GetDC(hWnd: nullptr);
  oldFont = (HFONT__ *)SelectObject(hdc: DC, h: FontA);
  rcText.top = 0;
  rcText.left = 0;
  rcText.bottom = (int)pointsize + 5;
  rcText.right = 2048;
  DrawTextA(hdc: DC, lpchText: output, cchText: -1, lprc: &rcText, format: 0xC24u);
  SelectObject(hdc: DC, h: oldFont);
  DeleteObject(ho: FontA);
  ReleaseDC(hWnd: nullptr, hDC: DC);
  return rcText.right;
}

//------------------------------------------------------------------------------
// Address: 0x00405970
// Name: public: void CDrawHelper::DrawColoredLine(unsigned long,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawHelper::DrawColoredLine(
        CDrawHelper *this,
        HPEN__ *clr,
        int style,
        int width,
        int x1,
        int y1,
        int x2,
        int y2)
{
  HPEN Pen; // edi
  HPEN__ *oldPen; // [esp+14h] [ebp+8h]

  Pen = CreatePen(iStyle: style, cWidth: width, color: (COLORREF)clr);
  oldPen = (HPEN__ *)SelectObject(hdc: this->m_dcMemory, h: Pen);
  MoveToEx(hdc: this->m_dcMemory, x: x1 - this->m_x, y: y1 - this->m_y, lppt: nullptr);
  LineTo(hdc: this->m_dcMemory, x: x2 - this->m_x, y: y2 - this->m_y);
  SelectObject(hdc: this->m_dcMemory, h: oldPen);
  DeleteObject(ho: Pen);
}

//------------------------------------------------------------------------------
// Address: 0x004059F0
// Name: public: void CDrawHelper::DrawColoredTextCharset(char const __near *,int,int,unsigned long,unsigned long,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDrawHelper::DrawColoredTextCharset(
        CDrawHelper *this,
        const char *font,
        int pointsize,
        int weight,
        DWORD charset,
        COLORREF clr,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  HFONT FontA; // edi
  HFONT__ *v10; // eax
  int v11; // eax
  int m_x; // edx
  HDC__ *m_dcMemory; // [esp-8h] [ebp-28h]
  int v14; // [esp-4h] [ebp-24h]
  tagRECT rcTextOffset; // [esp+Ch] [ebp-14h] BYREF
  HFONT__ *oldFont; // [esp+1Ch] [ebp-4h]
  unsigned int oldColor; // [esp+28h] [ebp+8h]
  int oldMode; // [esp+30h] [ebp+10h]
  va_list ap; // [esp+48h] [ebp+28h] BYREF

  va_start(ap, fmt);
  vsprintf(string: output_0, format: fmt, ap);
  FontA = CreateFontA(
            cHeight: -pointsize,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: weight,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: charset,
            iOutPrecision: 4u,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: font);
  v10 = (HFONT__ *)SelectObject(hdc: this->m_dcMemory, h: FontA);
  m_dcMemory = this->m_dcMemory;
  oldFont = v10;
  oldColor = SetTextColor(hdc: m_dcMemory, color: clr);
  v11 = SetBkMode(hdc: this->m_dcMemory, mode: 1);
  m_x = this->m_x;
  oldMode = v11;
  v14 = -this->m_y;
  rcTextOffset = *rcText;
  OffsetRect(lprc: &rcTextOffset, dx: -m_x, dy: v14);
  DrawTextA(hdc: this->m_dcMemory, lpchText: output_0, cchText: -1, lprc: &rcTextOffset, format: 0x40824u);
  SetBkMode(hdc: this->m_dcMemory, mode: oldMode);
  SetTextColor(hdc: this->m_dcMemory, color: oldColor);
  SelectObject(hdc: this->m_dcMemory, h: oldFont);
  DeleteObject(ho: FontA);
}

//------------------------------------------------------------------------------
// Address: 0x00405AF0
// Name: public: void CDrawHelper::DrawColoredText(char const __near *,int,int,unsigned long,struct tagRECT __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CDrawHelper::DrawColoredText(
        CDrawHelper *this,
        const char *font,
        int pointsize,
        int weight,
        COLORREF clr,
        tagRECT *rcText,
        const char *fmt,
        ...)
{
  va_list ap; // [esp+24h] [ebp+24h] BYREF

  va_start(ap, fmt);
  vsprintf(string: output_1, format: fmt, ap);
  CDrawHelper::DrawColoredTextCharset(this, font, pointsize, weight, charset: 0, clr, rcText, fmt: output_1);
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: private: void CDrawHelper::ClipToRects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawHelper::ClipToRects(CDrawHelper *this)
{
  HRGN (__stdcall *v2)(int, int, int, int); // ebx
  HRGN v3; // edi
  HRGN__ *v4; // ebx
  int i; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]

  SelectClipRgn(hdc: this->m_dcMemory, hrgn: nullptr);
  if ( this->m_ClipRegion != nullptr )
  {
    DeleteObject(ho: this->m_ClipRegion);
    this->m_ClipRegion = nullptr;
  }
  if ( this->m_ClipRects.m_Size > 0 )
  {
    v2 = CreateRectRgn;
    this->m_ClipRegion = CreateRectRgn(
                           x1: this->m_ClipRects.m_Memory.m_pMemory->left,
                           y1: this->m_ClipRects.m_Memory.m_pMemory->top,
                           x2: this->m_ClipRects.m_Memory.m_pMemory->right,
                           y2: this->m_ClipRects.m_Memory.m_pMemory->bottom);
    i = 1;
    if ( this->m_ClipRects.m_Size > 1 )
    {
      v6 = 1;
      while ( 1 )
      {
        v3 = v2(
               x1: this->m_ClipRects.m_Memory.m_pMemory[v6].left,
               y1: this->m_ClipRects.m_Memory.m_pMemory[v6].top,
               x2: this->m_ClipRects.m_Memory.m_pMemory[v6].right,
               y2: this->m_ClipRects.m_Memory.m_pMemory[v6].bottom);
        v4 = v2(x1: 0, y1: 0, x2: 100, y2: 100);
        CombineRgn(hrgnDst: v4, hrgnSrc1: this->m_ClipRegion, hrgnSrc2: v3, iMode: 1);
        DeleteObject(ho: this->m_ClipRegion);
        DeleteObject(ho: v3);
        ++v6;
        this->m_ClipRegion = v4;
        if ( ++i >= this->m_ClipRects.m_Size )
          break;
        v2 = CreateRectRgn;
      }
    }
  }
  SelectClipRgn(hdc: this->m_dcMemory, hrgn: this->m_ClipRegion);
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: public: CDrawHelper::CDrawHelper(class mxWindow __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
CDrawHelper *__thiscall CDrawHelper::CDrawHelper(CDrawHelper *this, mxWindow *widget, COLORREF bgColor)
{
  this->__vftable = (CDrawHelper_vtbl *)&CDrawHelper::`vftable';
  this->m_ClipRects.m_Memory.m_pMemory = nullptr;
  this->m_ClipRects.m_Memory.m_nAllocationCount = 0;
  this->m_ClipRects.m_Memory.m_nGrowSize = 0;
  this->m_ClipRects.m_Size = 0;
  this->m_ClipRects.m_pElements = nullptr;
  CDrawHelper::Init(this, widget, x: 0, y: 0, w: 0, h: 0, bgColor);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405C80
// Name: public: virtual CDrawHelper::~CDrawHelper(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDrawHelper::~CDrawHelper(CDrawHelper *this)
{
  HDC__ *m_dcMemory; // [esp-8h] [ebp-10h]

  m_dcMemory = this->m_dcMemory;
  this->__vftable = (CDrawHelper_vtbl *)&CDrawHelper::`vftable';
  SelectClipRgn(hdc: m_dcMemory, hrgn: nullptr);
  while ( this->m_ClipRects.m_Size > 0 )
  {
    if ( this->m_ClipRects.m_Size > 0 )
    {
      --this->m_ClipRects.m_Size;
      CDrawHelper::ClipToRects(this);
    }
  }
  BitBlt(
    hdc: this->m_dcReal,
    x: this->m_x,
    y: this->m_y,
    cx: this->m_w,
    cy: this->m_h,
    hdcSrc: this->m_dcMemory,
    x1: 0,
    y1: 0,
    rop: 0xCC0020u);
  SetBkColor(hdc: this->m_dcMemory, color: this->m_clrOld);
  SelectObject(hdc: this->m_dcMemory, h: this->m_bmOld);
  DeleteObject(ho: this->m_bmMemory);
  DeleteObject(ho: this->m_dcMemory);
  ReleaseDC(hWnd: this->m_hWnd, hDC: this->m_dcReal);
  ValidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rcClient);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ClipRects);
}
