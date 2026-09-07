// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/listboxex.cpp
// Functions: 40
// ============================================================

#include "hammer\listboxex.h"

//------------------------------------------------------------------------------
// Address: 0x10048EE0
// Name: public: void CDC::FillRect(struct tagRECT const __near *,class CBrush __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDC::FillRect(CDC *this, const tagRECT *lpRect, CBrush *pBrush)
{
  if ( pBrush != nullptr )
    FillRect(hDC: this->m_hDC, lprc: lpRect, hbr: (HBRUSH)pBrush->m_hObject);
  else
    FillRect(hDC: this->m_hDC, lprc: lpRect, hbr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10048F20
// Name: public: virtual int CDC::TextOutA(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDC::TextOutA(CDC *this, int x, int y, const char *lpszString, int nCount)
{
  return TextOutA(hdc: this->m_hDC, x, y, lpString: lpszString, c: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x10048F80
// Name: public: void CEdit::SetSel(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdit::SetSel(CEdit *this, WPARAM nStartChar, LPARAM nEndChar, int bNoScroll)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xB1u, wParam: nStartChar, lParam: nEndChar);
  if ( bNoScroll == 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xB7u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10348846
// Name: public: int CEdit::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEdit::Create(
        CEdit *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "EDIT", a3: nullptr, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10348869
// Name: public: virtual CEdit::~CEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEdit::~CEdit(CEdit *this)
{
  this->__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10348906
// Name: public: virtual struct CRuntimeClass __near * CEdit::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CEdit::GetRuntimeClass(CEdit *this)
{
  return &CEdit::classCEdit;
}

//------------------------------------------------------------------------------
// Address: 0x1037339F
// Name: public: virtual int CPreviewDC::TextOutA(int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::TextOutA(CPreviewDC *this, int x, int y, const char *lpszString, unsigned int nCount)
{
  return this->ExtTextOutA(this, a2: x, a3: y, a4: 0, a5: nullptr, a6: lpszString, a7: nCount, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103733BE
// Name: public: virtual int CPreviewDC::GrayStringA(class CBrush __near *,int (*)(struct HDC__ __near *,long,int),long,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::GrayStringA(
        CPreviewDC *this,
        CBrush *__formal,
        int (__stdcall *a3)(HDC__ *, int, int),
        const char *lpData,
        int nCount,
        int x,
        int y,
        int a8,
        int a9)
{
  return this->TextOutA(this, a2: x, a3: y, a4: lpData, a5: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x103733D8
// Name: public: virtual int CPreviewDC::Escape(int,int,char const __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::Escape(CPreviewDC *this, int nEscape, int nCount, const char *lpszInData, void *lpOutData)
{
  if ( nEscape <= 35 )
  {
    if ( nEscape < 34 )
    {
      switch ( nEscape )
      {
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 12:
        case 13:
        case 14:
        case 16:
        case 17:
        case 18:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
          return Escape(hdc: this->m_hAttribDC, iEscape: nEscape, cjIn: nCount, pvIn: lpszInData, pvOut: lpOutData);
        default:
          return 0;
      }
    }
    return Escape(hdc: this->m_hAttribDC, iEscape: nEscape, cjIn: nCount, pvIn: lpszInData, pvOut: lpOutData);
  }
  if ( nEscape >= 256
    && (nEscape <= 259 || nEscape > 767 && (nEscape <= 772 || nEscape == 4103 || nEscape > 4104 && nEscape <= 4106)) )
  {
    return Escape(hdc: this->m_hAttribDC, iEscape: nEscape, cjIn: nCount, pvIn: lpszInData, pvOut: lpOutData);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10373472
// Name: public: virtual struct CRuntimeClass __near * CPreviewDC::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPreviewDC::GetRuntimeClass(CPreviewDC *this)
{
  return &CPreviewDC::classCPreviewDC;
}

//------------------------------------------------------------------------------
// Address: 0x10373478
// Name: public: bool ATL::CAutoVectorPtr<char>::Allocate(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __thiscall ATL::CAutoVectorPtr<char>::Allocate(ATL::CAutoVectorPtr<char> *this, unsigned int nElements)
{
  this->m_p = (char *)operator new(nSize: nElements);
  return this->m_p != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103734B9
// Name: public: bool ATL::CAutoVectorPtr<int>::Allocate(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __thiscall ATL::CAutoVectorPtr<int>::Allocate(ATL::CAutoVectorPtr<int> *this, unsigned int nElements)
{
  this->m_p = (int *)operator new(nSize: 4 * nElements);
  return this->m_p != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10373509
// Name: public: CPreviewDC::CPreviewDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPreviewDC *__thiscall CPreviewDC::CPreviewDC(CPreviewDC *this)
{
  CDC::CDC(this);
  this->__vftable = (CPreviewDC_vtbl *)&CPreviewDC::`vftable';
  this->m_sizeWinExt.cx = 0;
  this->m_sizeWinExt.cy = 0;
  this->m_sizeVpExt.cx = 0;
  this->m_sizeVpExt.cy = 0;
  this->m_nScaleDen = 1;
  this->m_nScaleNum = 1;
  this->m_hPrinterFont = nullptr;
  this->m_hFont = nullptr;
  this->m_sizeTopLeft.cy = 8;
  this->m_sizeTopLeft.cx = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10373564
// Name: protected: void CPreviewDC::MirrorAttributes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::MirrorAttributes(CPreviewDC *this)
{
  HGDIOBJ StockObject; // eax
  HGDIOBJ v3; // eax
  HGDIOBJ v4; // ebx
  int ROP2; // eax
  int BkMode; // eax
  UINT TextAlign; // eax
  int PolyFillMode; // eax
  int StretchBltMode; // eax
  COLORREF TextColor; // eax
  COLORREF NearestColor; // eax
  COLORREF BkColor; // eax
  COLORREF v13; // eax
  HGDIOBJ hTemp; // [esp+4h] [ebp-4h]

  if ( this->m_hDC != nullptr )
  {
    StockObject = GetStockObject(i: 7);
    hTemp = SelectObject(hdc: this->m_hAttribDC, h: StockObject);
    SelectObject(hdc: this->m_hAttribDC, h: hTemp);
    SelectObject(hdc: this->m_hDC, h: hTemp);
    v3 = GetStockObject(i: 4);
    v4 = SelectObject(hdc: this->m_hAttribDC, h: v3);
    SelectObject(hdc: this->m_hAttribDC, h: v4);
    SelectObject(hdc: this->m_hDC, h: v4);
    ROP2 = GetROP2(hdc: this->m_hAttribDC);
    CDC::SetROP2(this, nDrawMode: ROP2);
    BkMode = GetBkMode(hdc: this->m_hAttribDC);
    CDC::SetBkMode(this, nBkMode: BkMode);
    TextAlign = GetTextAlign(hdc: this->m_hAttribDC);
    CDC::SetTextAlign(this, nFlags: TextAlign);
    PolyFillMode = GetPolyFillMode(hdc: this->m_hAttribDC);
    CDC::SetPolyFillMode(this, nPolyFillMode: PolyFillMode);
    StretchBltMode = GetStretchBltMode(hdc: this->m_hAttribDC);
    CDC::SetStretchBltMode(this, nStretchMode: StretchBltMode);
    TextColor = GetTextColor(hdc: this->m_hAttribDC);
    NearestColor = GetNearestColor(hdc: this->m_hAttribDC, color: TextColor);
    this->SetTextColor(this, a2: NearestColor);
    BkColor = GetBkColor(hdc: this->m_hAttribDC);
    v13 = GetNearestColor(hdc: this->m_hAttribDC, color: BkColor);
    this->SetBkColor(this, a2: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10373646
// Name: protected: void CPreviewDC::MirrorFont(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::MirrorFont(CPreviewDC *this)
{
  HFONT__ *m_hPrinterFont; // eax
  int v3; // edi
  int v4; // eax
  HFONT v5; // edi
  void **p_m_hFont; // esi
  int cyDesired; // [esp+4h] [ebp-94h]
  int cyActual; // [esp+8h] [ebp-90h]
  HFONT__ *hNewFont; // [esp+Ch] [ebp-8Ch]
  CSize sizeVpExt; // [esp+10h] [ebp-88h] BYREF
  CSize sizeWinExt; // [esp+18h] [ebp-80h] BYREF
  tagTEXTMETRICA tm; // [esp+20h] [ebp-78h] BYREF
  tagLOGFONTA logFont; // [esp+58h] [ebp-40h] BYREF

  if ( this->m_hAttribDC != nullptr )
  {
    m_hPrinterFont = this->m_hPrinterFont;
    if ( m_hPrinterFont != nullptr )
    {
      if ( this->m_hDC != nullptr )
      {
        GetObjectA(h: m_hPrinterFont, c: 60, pv: &logFont);
        GetTextFaceA(hdc: this->m_hAttribDC, c: 32, lpName: logFont.lfFaceName);
        GetTextMetricsA(hdc: this->m_hAttribDC, lptm: &tm);
        if ( tm.tmHeight >= 0 )
          logFont.lfHeight = tm.tmInternalLeading - tm.tmHeight;
        else
          logFont.lfHeight = tm.tmHeight;
        logFont.lfWidth = tm.tmAveCharWidth;
        logFont.lfWeight = tm.tmWeight;
        logFont.lfItalic = tm.tmItalic;
        logFont.lfUnderline = tm.tmUnderlined;
        logFont.lfStrikeOut = tm.tmStruckOut;
        logFont.lfCharSet = tm.tmCharSet;
        logFont.lfPitchAndFamily = tm.tmPitchAndFamily;
        hNewFont = CreateFontIndirectA(lplf: &logFont);
        SelectObject(hdc: this->m_hDC, h: hNewFont);
        GetTextMetricsA(hdc: this->m_hDC, lptm: &tm);
        v3 = -logFont.lfHeight;
        if ( tm.tmHeight >= 0 )
          v4 = tm.tmHeight - tm.tmInternalLeading;
        else
          v4 = -tm.tmHeight;
        sizeWinExt.cx = 0;
        sizeWinExt.cy = 0;
        cyActual = v4;
        GetWindowExtEx(hdc: this->m_hDC, lpsize: &sizeWinExt);
        sizeVpExt.cx = 0;
        sizeVpExt.cy = 0;
        GetViewportExtEx(hdc: this->m_hDC, lpsize: &sizeVpExt);
        if ( sizeWinExt.cy < 0 )
          sizeWinExt.cy = -sizeWinExt.cy;
        if ( sizeVpExt.cy < 0 )
          sizeVpExt.cy = -sizeVpExt.cy;
        cyDesired = MulDiv(nNumber: v3, nNumerator: sizeVpExt.cy, nDenominator: sizeWinExt.cy);
        if ( cyDesired >= MulDiv(nNumber: cyActual, nNumerator: sizeVpExt.cy, nDenominator: sizeWinExt.cy) )
        {
          v5 = hNewFont;
        }
        else
        {
          logFont.lfPitchAndFamily = (logFont.lfPitchAndFamily & 0xF0) != 80 ? 0 : 0x50;
          logFont.lfFaceName[0] = 0;
          v5 = CreateFontIndirectA(lplf: &logFont);
          SelectObject(hdc: this->m_hDC, h: v5);
          DeleteObject(ho: hNewFont);
        }
        p_m_hFont = (void **)&this->m_hFont;
        AfxDeleteObject(pObject: p_m_hFont);
        *p_m_hFont = v5;
      }
    }
    else
    {
      this->SelectStockObject(this, a2: 14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103737FF
// Name: public: virtual class CFont __near * CPreviewDC::SelectObject(class CFont __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFont *__thiscall CPreviewDC::SelectObject(CPreviewDC *this, CFont *pFont)
{
  HGDIOBJ v4; // eax
  CGdiObject *v5; // ebx
  HFONT__ *m_hObject; // eax

  if ( pFont == nullptr )
    return nullptr;
  v4 = SelectObject(hdc: this->m_hAttribDC, h: pFont->m_hObject);
  v5 = CGdiObject::FromHandle(h: v4);
  m_hObject = (HFONT__ *)pFont->m_hObject;
  if ( this->m_hPrinterFont != m_hObject )
  {
    this->m_hPrinterFont = m_hObject;
    CPreviewDC::MirrorFont(this);
  }
  return (CFont *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x10373843
// Name: protected: class CSize CPreviewDC::ComputeDeltas(int __near &,char const __near *,unsigned int __near &,int,unsigned int,int __near *,int,char __near *,int __near *,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::ComputeDeltas(
        CPreviewDC *this,
        CSize *result,
        int *x,
        const char *lpszString,
        unsigned int *nCount,
        int bTabbed,
        unsigned int nTabStops,
        int *lpnTabStops,
        int nTabOrigin,
        char *lpszOutputString,
        int *pnDxWidths,
        int *nRightFixup)
{
  int *v13; // ecx
  unsigned __int8 *v14; // ebx
  int v15; // eax
  int *v16; // edi
  unsigned __int16 TabbedTextExtentW; // ax
  signed __int8 v18; // al
  int tmAveCharWidth; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  signed __int8 v24; // al
  char *v25; // ecx
  unsigned __int8 v26; // al
  char *v27; // ecx
  int v28; // eax
  int Tab; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  CSize *v32; // ebx
  int *v33; // eax
  int v34; // edx
  int v35; // eax
  HDC__ *m_hAttribDC; // [esp-8h] [ebp-E8h]
  HDC__ *v38; // [esp-4h] [ebp-E4h]
  char nAlignment; // [esp+Ch] [ebp-D4h]
  tagSIZE size; // [esp+10h] [ebp-D0h] BYREF
  int *v41; // [esp+18h] [ebp-C8h]
  CSize *v42; // [esp+1Ch] [ebp-C4h]
  CSize sizeExtent; // [esp+20h] [ebp-C0h] BYREF
  int bUpdateCP; // [esp+28h] [ebp-B8h]
  CPoint ptCurrent; // [esp+2Ch] [ebp-B4h] BYREF
  int *v46; // [esp+34h] [ebp-ACh]
  int bSpace; // [esp+38h] [ebp-A8h]
  int nTabWidth; // [esp+3Ch] [ebp-A4h]
  const char *lpszStartRun; // [esp+40h] [ebp-A0h]
  int cxScreen; // [esp+44h] [ebp-9Ch] BYREF
  int *v51; // [esp+48h] [ebp-98h]
  int nStartRunPos; // [esp+4Ch] [ebp-94h]
  LPINT lpBuffer; // [esp+50h] [ebp-90h]
  int nStartOffset; // [esp+54h] [ebp-8Ch]
  unsigned int i; // [esp+58h] [ebp-88h]
  unsigned int *v56; // [esp+5Ch] [ebp-84h]
  char *v57; // [esp+60h] [ebp-80h]
  unsigned int v58; // [esp+64h] [ebp-7Ch]
  int nCurrentPos; // [esp+68h] [ebp-78h]
  tagTEXTMETRICA tmScreen; // [esp+6Ch] [ebp-74h] BYREF
  tagTEXTMETRICA tmAttrib; // [esp+A4h] [ebp-3Ch] BYREF

  v51 = x;
  nStartRunPos = (int)lpszString;
  v56 = nCount;
  v46 = lpnTabStops;
  v57 = lpszOutputString;
  lpBuffer = pnDxWidths;
  v41 = nRightFixup;
  m_hAttribDC = this->m_hAttribDC;
  v42 = result;
  GetTextMetricsA(hdc: m_hAttribDC, lptm: &tmAttrib);
  GetTextMetricsA(hdc: this->m_hDC, lptm: &tmScreen);
  result->cx = 0;
  result->cy = 0;
  GetTextExtentPoint32W(hdc: this->m_hAttribDC, lpString: L"A", c: 1, psizl: result);
  v38 = this->m_hAttribDC;
  ptCurrent.x = 0;
  ptCurrent.y = 0;
  nAlignment = GetTextAlign(hdc: v38);
  bUpdateCP = nAlignment & 1;
  if ( (nAlignment & 1) != 0 )
  {
    GetCurrentPositionEx(hdc: this->m_hDC, lppt: &ptCurrent);
    *v51 = ptCurrent.x;
  }
  v13 = v51;
  v14 = (unsigned __int8 *)nStartRunPos;
  v15 = *v51;
  nStartOffset = 0;
  nTabWidth = 0;
  v16 = lpBuffer;
  lpszStartRun = (const char *)nStartRunPos;
  nStartRunPos = v15;
  nCurrentPos = v15;
  if ( bTabbed != 0 )
  {
    if ( nTabStops == 1 )
    {
      nTabWidth = *v46;
    }
    else
    {
      TabbedTextExtentW = GetTabbedTextExtentW(
                            hdc: this->m_hAttribDC,
                            lpString: L"\t",
                            chCount: 1,
                            nTabPositions: 0,
                            lpnTabStopPositions: nullptr);
      v13 = v51;
      nTabWidth = TabbedTextExtentW;
      v15 = nCurrentPos;
    }
  }
  i = 0;
  if ( *v56 != 0 )
  {
    v58 = 1;
    while ( 1 )
    {
      v18 = *v14;
      bSpace = *v14 == tmAttrib.tmBreakChar;
      if ( bSpace != 0 || bTabbed != 0 && v18 == 9 )
      {
        sizeExtent.cx = 0;
        sizeExtent.cy = 0;
        GetTextExtentPoint32A(
          hdc: this->m_hAttribDC,
          lpString: lpszStartRun,
          c: (int)&v14[bSpace - (_DWORD)lpszStartRun],
          psizl: &sizeExtent);
        Tab = nStartRunPos + sizeExtent.cx - tmAttrib.tmOverhang;
        if ( bSpace == 0 )
          Tab = _AfxComputeNextTab(
                  x: nStartRunPos + sizeExtent.cx - tmAttrib.tmOverhang,
                  nTabStops,
                  lpnTabStops: v46,
                  nTabOrigin,
                  nTabWidth);
        v30 = Tab - nCurrentPos;
        if ( v16 == lpBuffer )
          nStartOffset += v30;
        else
          *(v16 - 1) += v30;
        nCurrentPos = Tab;
        nStartRunPos = Tab;
        lpszStartRun = (const char *)(v14 + 1);
        goto LABEL_34;
      }
      if ( _ismbblead(tst: v18) != 0 && v58 < *v56 )
        break;
      GetCharWidthA(hdc: this->m_hDC, iFirst: *v14, iLast: *v14, lpBuffer: &cxScreen);
      if ( !GetCharWidthA(hdc: this->m_hAttribDC, iFirst: *v14, iLast: *v14, lpBuffer: v16) )
        goto LABEL_20;
LABEL_22:
      *v16 -= tmAttrib.tmOverhang;
      v21 = *v16;
      v22 = cxScreen - tmScreen.tmOverhang;
      nCurrentPos += *v16;
      cxScreen -= tmScreen.tmOverhang;
      if ( v16 != lpBuffer )
      {
        v23 = (v21 - v22) / 2;
        *(v16 - 1) += v23;
        *v16 = v21 - v23;
      }
      v24 = *v14;
      v25 = v57++;
      *v25 = v24;
      if ( _ismbblead(tst: (char)*v14) != 0 && v58 < *v56 )
      {
        v26 = v14[1];
        v27 = v57++;
        *v27 = v26;
        v28 = *v16;
        nCurrentPos += *v16++;
        ++i;
        ++v58;
        *v16 = v28;
      }
      ++v16;
LABEL_34:
      v31 = _mbsinc(current: v14);
      ++i;
      ++v58;
      v14 = v31;
      if ( i >= *v56 )
      {
        v15 = nCurrentPos;
        v13 = v51;
        goto LABEL_36;
      }
    }
    if ( GetTextExtentPointA(hdc: this->m_hDC, lpString: (LPCSTR)v14, c: 2, lpsz: &size) )
      tmAveCharWidth = size.cx / 2;
    else
      tmAveCharWidth = tmScreen.tmAveCharWidth;
    cxScreen = tmAveCharWidth;
    if ( GetTextExtentPointA(hdc: this->m_hAttribDC, lpString: (LPCSTR)v14, c: 2, lpsz: &size) )
      v20 = size.cx / 2;
    else
LABEL_20:
      v20 = tmAttrib.tmAveCharWidth;
    *v16 = v20;
    goto LABEL_22;
  }
LABEL_36:
  v32 = v42;
  v42->cx = v15 - *v13;
  v33 = v41;
  *v41 = 0;
  v34 = nAlignment & 6;
  if ( (nAlignment & 6) == 0 )
  {
    v35 = nStartOffset;
LABEL_40:
    *v13 += v35;
    goto LABEL_43;
  }
  if ( v34 == 6 )
  {
    v35 = nStartOffset / 2;
    goto LABEL_40;
  }
  if ( v34 == 2 )
    *v33 = nStartOffset;
LABEL_43:
  if ( bUpdateCP != 0 )
    MoveToEx(hdc: this->m_hDC, x: *v13, y: ptCurrent.y, lppt: nullptr);
  *v56 = v16 - lpBuffer;
  return v32;
}

//------------------------------------------------------------------------------
// Address: 0x10373C27
// Name: public: virtual int CPreviewDC::DrawTextA(char const __near *,int,struct tagRECT __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::DrawTextA(
        CPreviewDC *this,
        const char *lpszString,
        int nCount,
        tagRECT *lpRect,
        UINT nFormat)
{
  int v6; // eax
  int v7; // ebx
  CPoint pos; // [esp+8h] [ebp-8h] BYREF

  v6 = DrawTextA(hdc: this->m_hDC, lpchText: lpszString, cchText: nCount, lprc: lpRect, format: nFormat);
  pos.x = 0;
  pos.y = 0;
  v7 = v6;
  GetCurrentPositionEx(hdc: this->m_hDC, lppt: &pos);
  MoveToEx(hdc: this->m_hAttribDC, x: pos.x, y: pos.y, lppt: nullptr);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10373C77
// Name: public: virtual int CPreviewDC::DrawTextExA(char __near *,int,struct tagRECT __near *,unsigned int,struct tagDRAWTEXTPARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::DrawTextExA(
        CPreviewDC *this,
        char *lpszString,
        int nCount,
        tagRECT *lpRect,
        UINT nFormat,
        tagDRAWTEXTPARAMS *lpDTParams)
{
  int v7; // eax
  int v8; // ebx
  CPoint pos; // [esp+8h] [ebp-8h] BYREF

  v7 = DrawTextExA(
         hdc: this->m_hDC,
         lpchText: lpszString,
         cchText: nCount,
         lprc: lpRect,
         format: nFormat,
         lpdtp: lpDTParams);
  pos.x = 0;
  pos.y = 0;
  v8 = v7;
  GetCurrentPositionEx(hdc: this->m_hDC, lppt: &pos);
  MoveToEx(hdc: this->m_hAttribDC, x: pos.x, y: pos.y, lppt: nullptr);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10373CCA
// Name: public: void CPreviewDC::PrinterDPtoScreenDP(struct tagPOINT __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::PrinterDPtoScreenDP(CPreviewDC *this, tagPOINT *lpPoint)
{
  HDC__ *m_hAttribDC; // [esp-8h] [ebp-20h]
  HDC__ *v4; // [esp-8h] [ebp-20h]
  CSize sizePrinterWinExt; // [esp+8h] [ebp-10h] BYREF
  CSize sizePrinterVpExt; // [esp+10h] [ebp-8h] BYREF

  m_hAttribDC = this->m_hAttribDC;
  sizePrinterVpExt.cx = 0;
  sizePrinterVpExt.cy = 0;
  GetViewportExtEx(hdc: m_hAttribDC, lpsize: &sizePrinterVpExt);
  v4 = this->m_hAttribDC;
  sizePrinterWinExt.cx = 0;
  sizePrinterWinExt.cy = 0;
  GetWindowExtEx(hdc: v4, lpsize: &sizePrinterWinExt);
  lpPoint->x = _AfxMultMultDivDiv(
                 factor: lpPoint->x,
                 num1: sizePrinterWinExt.cx,
                 num2: this->m_sizeVpExt.cx,
                 den1: sizePrinterVpExt.cx,
                 den2: this->m_sizeWinExt.cx);
  lpPoint->y = _AfxMultMultDivDiv(
                 factor: lpPoint->y,
                 num1: sizePrinterWinExt.cy,
                 num2: this->m_sizeVpExt.cy,
                 den1: sizePrinterVpExt.cy,
                 den2: this->m_sizeWinExt.cy);
}

//------------------------------------------------------------------------------
// Address: 0x10373D33
// Name: public: ATL::CAutoVectorPtr<int>::~CAutoVectorPtr<int>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ATL::CAutoVectorPtr<int>::~CAutoVectorPtr<int>(ATL::CAutoVectorPtr<char> *this)
{
  operator delete(p: this->m_p);
  this->m_p = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10373D45
// Name: public: virtual int CPreviewDC::RestoreDC(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPreviewDC::RestoreDC(CPreviewDC *this, int nSavedDC)
{
  BOOL v3; // ebx
  int m_nSaveDCDelta; // eax

  v3 = RestoreDC(hdc: this->m_hAttribDC, nSavedDC);
  if ( v3 )
  {
    m_nSaveDCDelta = this->m_nSaveDCDelta;
    if ( m_nSaveDCDelta != 0x7FFF )
    {
      if ( nSavedDC != -1 )
        nSavedDC += m_nSaveDCDelta;
      v3 = RestoreDC(hdc: this->m_hDC, nSavedDC);
      CPreviewDC::MirrorFont(this);
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10373D90
// Name: public: virtual class CGdiObject __near * CPreviewDC::SelectStockObject(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGdiObject *__thiscall CPreviewDC::SelectStockObject(CPreviewDC *this, int nIndex)
{
  HFONT__ *StockObject; // eax
  HFONT__ *v4; // ebx
  HGDIOBJ v5; // eax
  CGdiObject *result; // eax
  CGdiObject *v7; // edi
  HDC__ *m_hDC; // eax
  HGDIOBJ v9; // eax

  StockObject = (HFONT__ *)GetStockObject(i: nIndex);
  v4 = StockObject;
  if ( nIndex < 10 || nIndex > 14 && (nIndex <= 15 || nIndex > 17) )
  {
    m_hDC = this->m_hDC;
    if ( m_hDC != nullptr )
      SelectObject(hdc: m_hDC, h: v4);
    v9 = SelectObject(hdc: this->m_hAttribDC, h: v4);
    return CGdiObject::FromHandle(h: v9);
  }
  else
  {
    v5 = SelectObject(hdc: this->m_hAttribDC, h: StockObject);
    result = CGdiObject::FromHandle(h: v5);
    v7 = result;
    if ( this->m_hPrinterFont != v4 )
    {
      this->m_hPrinterFont = v4;
      CPreviewDC::MirrorFont(this);
      return v7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10373E03
// Name: public: virtual int CPreviewDC::ExtTextOutA(int,int,unsigned int,struct tagRECT const __near *,char const __near *,unsigned int,int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CPreviewDC::ExtTextOutA(
        CPreviewDC *this,
        int x,
        int y,
        UINT nOptions,
        const tagRECT *lpRect,
        char *lpszString,
        UINT nCount,
        int *lpDxWidths)
{
  int *v9; // eax
  char *m_p; // edi
  BOOL v12; // eax
  BOOL v13; // edi
  BOOL v14; // esi
  HDC__ *m_hDC; // [esp-8h] [ebp-3Ch]
  CPoint pt; // [esp+10h] [ebp-24h] BYREF
  CPoint v17; // [esp+18h] [ebp-1Ch] BYREF
  ATL::CAutoVectorPtr<char> spOutputString; // [esp+20h] [ebp-14h] BYREF
  ATL::CAutoVectorPtr<int> spDeltas; // [esp+24h] [ebp-10h] BYREF
  int v20; // [esp+30h] [ebp-4h]

  spDeltas.m_p = nullptr;
  v20 = 1;
  spOutputString.m_p = nullptr;
  v9 = lpDxWidths;
  v17.y = 0;
  if ( lpDxWidths != nullptr )
    goto LABEL_7;
  if ( nCount == 0 )
  {
    operator delete(p: nullptr);
    v20 = -1;
    operator delete(p: nullptr);
    return true;
  }
  if ( ATL::CAutoVectorPtr<int>::Allocate(this: &spDeltas, nElements: nCount)
    && ATL::CAutoVectorPtr<char>::Allocate(this: &spOutputString, nElements: nCount) )
  {
    m_p = spOutputString.m_p;
    CPreviewDC::ComputeDeltas(
      this,
      result: (CSize *)&pt,
      &x,
      lpszString,
      &nCount,
      bTabbed: 0,
      nTabStops: 0,
      lpnTabStops: nullptr,
      nTabOrigin: 0,
      lpszOutputString: spOutputString.m_p,
      pnDxWidths: spDeltas.m_p,
      nRightFixup: &v17.y);
    v9 = spDeltas.m_p;
    lpszString = m_p;
LABEL_7:
    v12 = ExtTextOutA(
            hdc: this->m_hDC,
            x,
            y,
            options: nOptions,
            lprect: lpRect,
            lpString: lpszString,
            c: nCount,
            lpDx: v9);
    v13 = v12;
    if ( v17.y != 0 && v12 && (GetTextAlign(hdc: this->m_hAttribDC) & 1) != 0 )
    {
      m_hDC = this->m_hDC;
      pt.x = 0;
      pt.y = 0;
      GetCurrentPositionEx(hdc: m_hDC, lppt: &pt);
      CDC::MoveTo(this, result: &v17, x: pt.x - v17.y, y: pt.y);
    }
    v14 = v13;
    goto LABEL_13;
  }
  v14 = false;
LABEL_13:
  LOBYTE(v20) = 0;
  operator delete(p: spOutputString.m_p);
  v20 = -1;
  operator delete(p: spDeltas.m_p);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10373F22
// Name: public: virtual class CSize CPreviewDC::TabbedTextOutA(int,int,char const __near *,int,int,int __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::TabbedTextOutA(
        CPreviewDC *this,
        CSize *result,
        int x,
        int y,
        const char *lpszString,
        char *nCount,
        unsigned int nTabPositions,
        int *lpnTabStopPositions,
        int nTabOrigin)
{
  int v10; // edi
  CSize *v12; // esi
  HDC__ *m_hDC; // [esp-8h] [ebp-40h]
  CPoint v14; // [esp+10h] [ebp-28h] BYREF
  CSize sizeFinalExtent; // [esp+18h] [ebp-20h] BYREF
  tagPOINT pt; // [esp+20h] [ebp-18h] BYREF
  ATL::CAutoVectorPtr<int> spDeltas; // [esp+28h] [ebp-10h] BYREF
  int v18; // [esp+34h] [ebp-4h]

  v10 = (int)nCount;
  if ( (int)nCount > 0 )
  {
    spDeltas.m_p = nullptr;
    v18 = 1;
    nCount = nullptr;
    if ( ATL::CAutoVectorPtr<int>::Allocate(this: &spDeltas, nElements: v10)
      && ATL::CAutoVectorPtr<char>::Allocate(this: (ATL::CAutoVectorPtr<char> *)&nCount, nElements: v10) )
    {
      pt.y = v10;
      CPreviewDC::ComputeDeltas(
        this,
        result: &sizeFinalExtent,
        &x,
        lpszString,
        nCount: (unsigned int *)&pt.y,
        bTabbed: 1,
        nTabStops: nTabPositions,
        lpnTabStops: lpnTabStopPositions,
        nTabOrigin,
        lpszOutputString: nCount,
        pnDxWidths: spDeltas.m_p,
        nRightFixup: &nTabOrigin);
      if ( this->ExtTextOutA(this, a2: x, a3: y, a4: 0, a5: nullptr, a6: nCount, a7: pt.y, a8: spDeltas.m_p) != 0
        && (GetTextAlign(hdc: this->m_hAttribDC) & 1) != 0 )
      {
        m_hDC = this->m_hDC;
        pt.x = 0;
        pt.y = 0;
        GetCurrentPositionEx(hdc: m_hDC, lppt: &pt);
        CDC::MoveTo(this, result: &v14, x: pt.x - nTabOrigin, y: pt.y);
      }
      v12 = result;
      *result = sizeFinalExtent;
    }
    else
    {
      v12 = result;
      result->cx = 0;
      result->cy = 0;
    }
    LOBYTE(v18) = 0;
    operator delete(p: nCount);
    v18 = -1;
    operator delete(p: spDeltas.m_p);
    return v12;
  }
  else
  {
    result->cx = 0;
    result->cy = 0;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037402F
// Name: protected: void CPreviewDC::MirrorViewportOrg(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::MirrorViewportOrg(CPreviewDC *this)
{
  HDC__ *m_hAttribDC; // eax
  HDC__ *v3; // [esp-8h] [ebp-20h]
  CPoint ptWinOrg; // [esp+8h] [ebp-10h] BYREF
  CPoint ptVpOrg; // [esp+10h] [ebp-8h] BYREF

  m_hAttribDC = this->m_hAttribDC;
  if ( m_hAttribDC != nullptr && this->m_hDC != nullptr )
  {
    ptVpOrg.x = 0;
    ptVpOrg.y = 0;
    GetViewportOrgEx(hdc: m_hAttribDC, lppoint: &ptVpOrg);
    CPreviewDC::PrinterDPtoScreenDP(this, lpPoint: &ptVpOrg);
    ptVpOrg.y += this->m_sizeTopLeft.cy;
    ptVpOrg.x += this->m_sizeTopLeft.cx;
    SetViewportOrgEx(hdc: this->m_hDC, x: ptVpOrg.x, y: ptVpOrg.y, lppt: nullptr);
    v3 = this->m_hAttribDC;
    ptWinOrg.x = 0;
    ptWinOrg.y = 0;
    GetWindowOrgEx(hdc: v3, lppoint: &ptWinOrg);
    SetWindowOrgEx(hdc: this->m_hDC, x: ptWinOrg.x, y: ptWinOrg.y, lppt: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103740A8
// Name: public: void CPreviewDC::SetTopLeftOffset(class CSize)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::SetTopLeftOffset(CPreviewDC *this, CSize sizeTopLeft)
{
  this->m_sizeTopLeft = sizeTopLeft;
  CPreviewDC::MirrorViewportOrg(this);
}

//------------------------------------------------------------------------------
// Address: 0x103740C2
// Name: public: virtual class CPoint CPreviewDC::SetViewportOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CPreviewDC::SetViewportOrg(CPreviewDC *this, CPoint *result, int x, int y)
{
  result->x = 0;
  result->y = 0;
  SetViewportOrgEx(hdc: this->m_hAttribDC, x, y, lppt: result);
  CPreviewDC::MirrorViewportOrg(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103740F4
// Name: public: virtual class CPoint CPreviewDC::OffsetViewportOrg(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPoint *__thiscall CPreviewDC::OffsetViewportOrg(CPreviewDC *this, CPoint *result, int nWidth, int nHeight)
{
  result->x = 0;
  result->y = 0;
  OffsetViewportOrgEx(hdc: this->m_hAttribDC, x: nWidth, y: nHeight, lppt: result);
  CPreviewDC::MirrorViewportOrg(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10374126
// Name: protected: void CPreviewDC::MirrorMappingMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::MirrorMappingMode(CPreviewDC *this, int bCompute)
{
  CSize *p_m_sizeVpExt; // ebx
  CSize *p_m_sizeWinExt; // edi
  bool i; // cc
  int cx; // ecx
  int v7; // edx
  int cy; // edi
  int v9; // ecx
  int v10; // edi
  int DeviceCaps; // eax
  int v12; // eax
  int v13; // eax
  HDC__ *m_hDC; // eax
  HDC__ *m_hAttribDC; // [esp-10h] [ebp-14h]

  if ( bCompute != 0 )
  {
    p_m_sizeVpExt = &this->m_sizeVpExt;
    GetViewportExtEx(hdc: this->m_hAttribDC, lpsize: &this->m_sizeVpExt);
    p_m_sizeWinExt = &this->m_sizeWinExt;
    GetWindowExtEx(hdc: this->m_hAttribDC, lpsize: &this->m_sizeWinExt);
    for ( i = this->m_sizeWinExt.cx <= -16384; !i; i = v7 <= -16384 )
    {
      if ( p_m_sizeWinExt->cx >= 0x4000 )
        break;
      cx = p_m_sizeVpExt->cx;
      if ( p_m_sizeVpExt->cx <= -16384 || cx >= 0x4000 )
        break;
      v7 = 2 * p_m_sizeWinExt->cx;
      p_m_sizeWinExt->cx = v7;
      p_m_sizeVpExt->cx = 2 * cx;
    }
    if ( this->m_sizeWinExt.cy > -16384 )
    {
      do
      {
        cy = this->m_sizeWinExt.cy;
        if ( cy >= 0x4000 )
          break;
        v9 = this->m_sizeVpExt.cy;
        if ( v9 <= -16384 )
          break;
        if ( v9 >= 0x4000 )
          break;
        v10 = 2 * cy;
        this->m_sizeWinExt.cy = v10;
        this->m_sizeVpExt.cy = 2 * v9;
      }
      while ( v10 > -16384 );
    }
    DeviceCaps = GetDeviceCaps(hdc: this->m_hAttribDC, index: 88);
    v12 = _AfxMultMultDivDiv(
            factor: p_m_sizeVpExt->cx,
            num1: this->m_nScaleNum,
            num2: afxData.cxPixelsPerInch,
            den1: this->m_nScaleDen,
            den2: DeviceCaps);
    m_hAttribDC = this->m_hAttribDC;
    p_m_sizeVpExt->cx = v12;
    v13 = GetDeviceCaps(hdc: m_hAttribDC, index: 90);
    this->m_sizeVpExt.cy = _AfxMultMultDivDiv(
                             factor: this->m_sizeVpExt.cy,
                             num1: this->m_nScaleNum,
                             num2: afxData.cyPixelsPerInch,
                             den1: this->m_nScaleDen,
                             den2: v13);
  }
  m_hDC = this->m_hDC;
  if ( m_hDC != nullptr )
  {
    SetMapMode(hdc: m_hDC, iMode: 8);
    SetWindowExtEx(hdc: this->m_hDC, x: this->m_sizeWinExt.cx, y: this->m_sizeWinExt.cy, lpsz: nullptr);
    SetViewportExtEx(hdc: this->m_hDC, x: this->m_sizeVpExt.cx, y: this->m_sizeVpExt.cy, lpsz: nullptr);
    CPreviewDC::MirrorViewportOrg(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374225
// Name: public: void CPreviewDC::ClipToPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::ClipToPage(CPreviewDC *this)
{
  int DeviceCaps; // ebx
  CPoint pt; // [esp+Ch] [ebp-8h] BYREF

  DeviceCaps = GetDeviceCaps(hdc: this->m_hAttribDC, index: 10);
  pt.x = GetDeviceCaps(hdc: this->m_hAttribDC, index: 8);
  pt.y = DeviceCaps;
  CPreviewDC::PrinterDPtoScreenDP(this, lpPoint: &pt);
  SetMapMode(hdc: this->m_hDC, iMode: 1);
  SetWindowOrgEx(hdc: this->m_hDC, x: 0, y: 0, lppt: nullptr);
  SetViewportOrgEx(hdc: this->m_hDC, x: this->m_sizeTopLeft.cx, y: this->m_sizeTopLeft.cy, lppt: nullptr);
  IntersectClipRect(hdc: this->m_hDC, left: -1, top: -1, right: pt.x + 2, bottom: pt.y + 2);
  CPreviewDC::MirrorMappingMode(this, bCompute: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103742A9
// Name: public: virtual void CPreviewDC::SetOutputDC(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::SetOutputDC(CPreviewDC *this, HDC__ *hDC)
{
  this->m_nSaveDCIndex = SaveDC(hdc: hDC);
  CDC::SetOutputDC(this, hDC);
  if ( this->m_hAttribDC != nullptr )
  {
    CPreviewDC::MirrorMappingMode(this, bCompute: 0);
    if ( this->m_hFont != nullptr )
      SelectObject(hdc: this->m_hDC, h: this->m_hFont);
    else
      CPreviewDC::MirrorFont(this);
    CPreviewDC::MirrorAttributes(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103742FC
// Name: public: virtual void CPreviewDC::SetAttribDC(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::SetAttribDC(CPreviewDC *this, HDC__ *hDC)
{
  CMFCAutoHideButton::ShowButton((CMFCAutoHideButton *)this, bShow: (int)hDC);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  CPreviewDC::MirrorFont(this);
  CPreviewDC::MirrorAttributes(this);
}

//------------------------------------------------------------------------------
// Address: 0x10374328
// Name: public: void CPreviewDC::SetScaleRatio(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewDC::SetScaleRatio(CPreviewDC *this, int nNumerator, int nDenominator)
{
  bool v4; // zf

  v4 = this->m_hAttribDC == nullptr;
  this->m_nScaleNum = nNumerator;
  this->m_nScaleDen = nDenominator;
  if ( !v4 )
  {
    CPreviewDC::MirrorMappingMode(this, bCompute: 1);
    CPreviewDC::MirrorFont(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10374355
// Name: public: virtual int CPreviewDC::SetMapMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewDC::SetMapMode(CPreviewDC *this, int nMapMode)
{
  int v3; // edi

  v3 = SetMapMode(hdc: this->m_hAttribDC, iMode: nMapMode);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1037437D
// Name: public: virtual class CSize CPreviewDC::SetViewportExt(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::SetViewportExt(CPreviewDC *this, CSize *result, int x, int y)
{
  result->cx = 0;
  result->cy = 0;
  SetViewportExtEx(hdc: this->m_hAttribDC, x, y, lpsz: result);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103743B1
// Name: public: virtual class CSize CPreviewDC::ScaleViewportExt(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::ScaleViewportExt(
        CPreviewDC *this,
        CSize *result,
        int xNum,
        int xDenom,
        int yNum,
        int yDenom)
{
  result->cx = 0;
  result->cy = 0;
  ScaleViewportExtEx(hdc: this->m_hAttribDC, xn: xNum, dx: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103743EB
// Name: public: virtual class CSize CPreviewDC::SetWindowExt(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::SetWindowExt(CPreviewDC *this, CSize *result, int x, int y)
{
  result->cx = 0;
  result->cy = 0;
  SetWindowExtEx(hdc: this->m_hAttribDC, x, y, lpsz: result);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1037441F
// Name: public: virtual class CSize CPreviewDC::ScaleWindowExt(int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CPreviewDC::ScaleWindowExt(
        CPreviewDC *this,
        CSize *result,
        int xNum,
        int xDenom,
        int yNum,
        int yDenom)
{
  result->cx = 0;
  result->cy = 0;
  ScaleWindowExtEx(hdc: this->m_hAttribDC, xn: xNum, xd: xDenom, yn: yNum, yd: yDenom, lpsz: result);
  CPreviewDC::MirrorMappingMode(this, bCompute: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10374459
// Name: public: CFixedAllocNoSync::CFixedAllocNoSync(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFixedAllocNoSync *__thiscall CFixedAllocNoSync::CFixedAllocNoSync(
        CFixedAllocNoSync *this,
        unsigned int nAllocSize,
        unsigned int nBlockSize)
{
  CFixedAllocNoSync *result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // edx

  result = this;
  v4 = nAllocSize;
  if ( nAllocSize < 4 )
    v4 = 4;
  v5 = nBlockSize;
  if ( nBlockSize <= 1 )
    v5 = 64;
  result->m_pNodeFree = nullptr;
  result->m_pBlocks = nullptr;
  result->m_nAllocSize = v4;
  result->m_nBlockSize = v5;
  return result;
}
