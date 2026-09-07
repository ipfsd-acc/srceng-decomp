// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/anglebox.cpp
// Functions: 28
// ============================================================

#include "hammer\anglebox.h"

//------------------------------------------------------------------------------
// Address: 0x100BC0C0
// Name: public: virtual CAngleBox::~CAngleBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleBox::~CAngleBox(CAngleBox *this)
{
  this->__vftable = (CAngleBox_vtbl *)&CAngleBox::`vftable';
  CDC::~CDC(this: &this->m_DragDC);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BC120
// Name: public: char __near * CAngleBox::GetAngles(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAngleBox::GetAngles(CAngleBox *this, char *szAngles)
{
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  float v6; // [esp+0h] [ebp-Ch]
  float v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+8h] [ebp-4h]

  if ( this->m_bDifferent )
  {
    z = v8;
    y = v7;
    x = v6;
  }
  else
  {
    x = this->m_vecAngles.x;
    y = this->m_vecAngles.y;
    z = this->m_vecAngles.z;
  }
  sprintf(string: szAngles, format: "%g %g %g", x, y, z);
  return szAngles;
}

//------------------------------------------------------------------------------
// Address: 0x100BC190
// Name: public: char __near * CAngleBox::GetAngleEditText(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CAngleBox::GetAngleEditText(CAngleBox *this, char *szBuf)
{
  float x; // xmm1_4
  float y; // xmm1_4

  *szBuf = 0;
  if ( this->m_bDifferent )
  {
    strcpy(szBuf, "(diff)");
    return szBuf;
  }
  else
  {
    x = this->m_vecAngles.x;
    if ( x == 90.0 && this->m_vecAngles.y == 0.0 && this->m_vecAngles.z == 0.0 )
    {
      strcpy(szBuf, "Down");
      return szBuf;
    }
    else if ( x == -90.0 && this->m_vecAngles.y == 0.0 && this->m_vecAngles.z == 0.0 )
    {
      strcpy(szBuf, "Up");
      return szBuf;
    }
    else
    {
      y = this->m_vecAngles.y;
      if ( y >= 0.0 )
        itoa(val: (int)y, buf: szBuf, radix: 0xAu);
      return szBuf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC280
// Name: public: int CDC::Ellipse(struct tagRECT const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDC::Ellipse(CDC *this, const tagRECT *lpRect)
{
  return Ellipse(hdc: this->m_hDC, left: lpRect->left, top: lpRect->top, right: lpRect->right, bottom: lpRect->bottom);
}

//------------------------------------------------------------------------------
// Address: 0x100BC2B0
// Name: public: CAngleBox::CAngleBox(void)
// Source: json
//------------------------------------------------------------------------------
CAngleBox *__thiscall CAngleBox::CAngleBox(CAngleBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CAngleBox_vtbl *)&CAngleBox::`vftable';
  CDC::CDC(this: &this->m_DragDC);
  this->m_ptClientCenter.x = 0;
  this->m_ptClientCenter.y = 0;
  this->m_vecAngles.x = 0.0;
  this->m_vecAngles.y = 0.0;
  this->m_vecAngles.z = 0.0;
  this->m_bDragging = false;
  this->m_pEdit = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC3B0
// Name: protected: void CAngleBox::DrawAngleLine(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::DrawAngleLine(CAngleBox *this@<ecx>, int a2@<ebx>, int a3@<esi>, CDC *pDC)
{
  float x; // xmm0_4
  float y; // xmm0_4
  int right; // ecx
  int v9; // edi
  int v10; // kr04_4
  CAngleBox *v11; // eax
  HWND__ *m_hWnd; // [esp-14h] [ebp-38h]
  long double v13; // [esp-Ch] [ebp-30h]
  long double v14; // [esp-Ch] [ebp-30h]
  CRect r; // [esp+0h] [ebp-24h] BYREF
  double rad; // [esp+10h] [ebp-14h] BYREF
  CPoint pt; // [esp+18h] [ebp-Ch]
  CAngleBox *v18; // [esp+20h] [ebp-4h]
  float pDCa; // [esp+2Ch] [ebp+8h]

  x = this->m_vecAngles.x;
  v18 = this;
  if ( x == 0.0 && this->m_vecAngles.z == 0.0 )
  {
    y = this->m_vecAngles.y;
    if ( y >= 0.0 && y <= 359.0 )
    {
      HIDWORD(v13) = a2;
      if ( !this->m_bDifferent )
      {
        LODWORD(v13) = a3;
        CDC::SetROP2(this: pDC, nDrawMode: 7);
        pDC->SelectStockObject(this: pDC, a2: 6);
        m_hWnd = this->m_hWnd;
        memset(&r, 0, sizeof(r));
        GetClientRect(hWnd: m_hWnd, lpRect: &r);
        right = r.right;
        v9 = (r.right + r.left) / 2;
        v10 = r.bottom + r.top;
        v11 = v18;
        v18->m_ptClientCenter.x = v9;
        v11->m_ptClientCenter.y = v10 / 2;
        rad = (double)((right - r.left) / 2 - 3);
        pDCa = (float)(v18->m_vecAngles.y + 90.0) * 0.017453292;
        __libm_sse2_sin(x: v13);
        pt.x = (int)(pDCa * rad + (double)v18->m_ptClientCenter.x + 0.5);
        __libm_sse2_cos(x: v14);
        pt.y = (int)(pDCa * rad + (double)v18->m_ptClientCenter.y + 0.5);
        CDC::MoveTo(this: pDC, result: (CPoint *)&rad, x: v9, y: v10 / 2);
        CDC::LineTo(this: pDC, x: pt.x, y: pt.y);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC550
// Name: private: void CAngleBox::SetAnglesInternal(class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::SetAnglesInternal(
        CAngleBox *this@<ecx>,
        int a2@<ebx>,
        const QAngle *vecAngles,
        bool bRedraw)
{
  float y; // xmm0_4
  CDC *v6; // edi
  HDC DC; // eax
  CDC *v8; // eax
  int v9; // [esp-Ch] [ebp-18h]
  const QAngle vecAngleSet; // 0:^10.12

  vecAngleSet = *vecAngles;
  y = vecAngles->y;
  if ( y < 0.0 )
  {
    do
      y = y + 360.0;
    while ( y < 0.0 );
    vecAngleSet.y = y;
  }
  v9 = a2;
  LOBYTE(a2) = bRedraw;
  v6 = nullptr;
  if ( bRedraw )
  {
    DC = GetDC(hWnd: this->m_hWnd);
    v8 = CDC::FromHandle(hDC: DC);
    v6 = v8;
    if ( v8 != nullptr )
      CAngleBox::DrawAngleLine(this, a2, a3: (int)this, pDC: v8);
    y = vecAngleSet.y;
  }
  this->m_vecAngles.y = y;
  this->m_vecAngles.x = vecAngleSet.x;
  this->m_vecAngles.z = vecAngleSet.z;
  if ( bRedraw && v6 != nullptr )
  {
    CAngleBox::DrawAngleLine(this, a2: v9, a3: (int)this, pDC: v6);
    ReleaseDC(hWnd: this->m_hWnd, hDC: v6->m_hDC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC610
// Name: public: void CAngleBox::Enable(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleBox::Enable(CAngleBox *this, bool bEnable)
{
  CAngleCombo *m_pEdit; // ecx
  CAngleCombo *v4; // ecx

  if ( bEnable )
  {
    CWnd::EnableWindow(this, bEnable: 1);
    m_pEdit = this->m_pEdit;
    if ( m_pEdit != nullptr )
      CWnd::EnableWindow(this: m_pEdit, bEnable: 1);
  }
  else
  {
    CWnd::EnableWindow(this, bEnable: 0);
    v4 = this->m_pEdit;
    if ( v4 != nullptr )
      CWnd::EnableWindow(this: v4, bEnable: 0);
  }
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: false);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x100BC670
// Name: public: CAngleCombo::CAngleCombo(void)
// Source: json
//------------------------------------------------------------------------------
CAngleCombo *__thiscall CAngleCombo::CAngleCombo(CAngleCombo *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CAngleCombo_vtbl *)&CComboBox::`vftable';
  this->__vftable = (CAngleCombo_vtbl *)&CAngleCombo::`vftable';
  this->m_pBox = nullptr;
  this->m_bEnableUpdate = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BC760
// Name: protected: void CAngleCombo::UpdateAngleBox(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleCombo::UpdateAngleBox(CAngleCombo *this, char *szText)
{
  CAngleBox *m_pBox; // esi
  HDC DC; // eax
  CDC *v5; // eax
  CDC *v6; // edi
  int v7; // eax
  CAngleBox *v8; // esi
  float v9; // xmm0_4
  int v10; // eax
  int v11; // xmm0_4
  HDC v12; // eax
  CDC *v13; // eax
  CDC *v14; // edi
  __int64 vecAngles; // [esp+8h] [ebp-18h]
  __int64 v16; // [esp+14h] [ebp-Ch]

  m_pBox = this->m_pBox;
  if ( m_pBox == nullptr )
    return;
  DC = GetDC(hWnd: m_pBox->m_hWnd);
  v5 = CDC::FromHandle(hDC: DC);
  v6 = v5;
  if ( v5 != nullptr )
    CAngleBox::DrawAngleLine(this: m_pBox, a2: (int)this, a3: (int)m_pBox, pDC: v5);
  m_pBox->m_bDifferent = false;
  if ( v6 != nullptr )
  {
    CAngleBox::DrawAngleLine(this: m_pBox, a2: (int)this, a3: (int)m_pBox, pDC: v6);
    ReleaseDC(hWnd: m_pBox->m_hWnd, hDC: v6->m_hDC);
  }
  if ( isdigit(c: *szText) == 0 )
  {
    v10 = _V_stricmp(s1: szText, s2: "down");
    v8 = this->m_pBox;
    if ( v10 != 0 )
      v11 = -1028390912;
    else
      v11 = 1119092736;
    LODWORD(v16) = v11;
    v9 = 0.0;
    goto LABEL_15;
  }
  LODWORD(vecAngles) = 0;
  v7 = atoi(nptr: szText);
  v8 = this->m_pBox;
  *((float *)&vecAngles + 1) = (float)v7;
  v16 = vecAngles;
  if ( (float)v7 < 0.0 )
  {
    v9 = (float)v7;
    do
      v9 = v9 + 360.0;
    while ( v9 < 0.0 );
LABEL_15:
    *((float *)&v16 + 1) = v9;
  }
  v12 = GetDC(hWnd: v8->m_hWnd);
  v13 = CDC::FromHandle(hDC: v12);
  v14 = v13;
  if ( v13 != nullptr )
    CAngleBox::DrawAngleLine(this: v8, a2: (int)this, a3: (int)v8, pDC: v13);
  *(_QWORD *)&v8->m_vecAngles.x = v16;
  v8->m_vecAngles.z = 0.0;
  if ( v14 != nullptr )
  {
    CAngleBox::DrawAngleLine(this: v8, a2: (int)this, a3: (int)v8, pDC: v14);
    ReleaseDC(hWnd: v8->m_hWnd, hDC: v14->m_hDC);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC8C0
// Name: protected: void CAngleBox::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::OnMouseMove(CAngleBox *this@<ecx>, int a2@<ebx>, unsigned int nFlags, CPoint point)
{
  int v5; // eax
  int v6; // eax

  if ( this->m_bDragging )
  {
    CAngleBox::DrawAngleLine(this, a2, a3: (int)this, pDC: &this->m_DragDC);
    v5 = (int)lineangle(
                x1: (float)point.x,
                y1: (float)point.y,
                x2: (float)this->m_ptClientCenter.x,
                y2: (float)this->m_ptClientCenter.y);
    v6 = (int)fixang(a: (float)(180 - v5));
    this->m_vecAngles.x = 0.0;
    this->m_vecAngles.z = 0.0;
    this->m_vecAngles.y = (float)v6;
    CAngleBox::DrawAngleLine(this, a2, a3: (int)this, pDC: &this->m_DragDC);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BC990
// Name: protected: void CAngleBox::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::OnLButtonDown(CAngleBox *this@<ecx>, int a2@<ebx>, unsigned int nFlags, CPoint point)
{
  HDC DC; // eax
  HWND v6; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-8h]

  DC = GetDC(hWnd: this->m_hWnd);
  CDC::Attach(this: &this->m_DragDC, hDC: DC);
  m_hWnd = this->m_hWnd;
  this->m_bDragging = true;
  v6 = SetCapture(hWnd: m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  CWnd::Default(this);
  CAngleBox::OnMouseMove(this, a2, nFlags: 0, point);
}

//------------------------------------------------------------------------------
// Address: 0x100BC9E0
// Name: public: void CAngleBox::SetAngles(class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::SetAngles(CAngleBox *this@<ecx>, int a2@<ebx>, const QAngle *vecAngles, bool bRedraw)
{
  CAngleCombo *m_pEdit; // esi
  char szBuf[20]; // [esp+4h] [ebp-14h] BYREF

  CAngleBox::SetAnglesInternal(this, a2, vecAngles, bRedraw);
  if ( this->m_pEdit != nullptr )
  {
    CAngleBox::GetAngleEditText(this, szBuf);
    m_pEdit = this->m_pEdit;
    m_pEdit->m_bEnableUpdate = false;
    CWnd::SetWindowTextA(this: m_pEdit, lpszString: szBuf);
    m_pEdit->m_bEnableUpdate = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCA30
// Name: public: void CAngleBox::SetAngles(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAngleBox::SetAngles(CAngleBox *this@<ecx>, int a2@<ebx>, const char *szAngles, bool bRedraw)
{
  CAngleCombo *m_pEdit; // esi
  char szBuf[20]; // [esp+0h] [ebp-20h] BYREF
  QAngle vecAngles; // [esp+14h] [ebp-Ch] BYREF

  memset(&vecAngles, 0, sizeof(vecAngles));
  sscanf(string: szAngles, format: "%f %f %f", &vecAngles, &vecAngles.y, &vecAngles.z);
  CAngleBox::SetAnglesInternal(this, a2, &vecAngles, bRedraw);
  if ( this->m_pEdit != nullptr )
  {
    CAngleBox::GetAngleEditText(this, szBuf);
    m_pEdit = this->m_pEdit;
    m_pEdit->m_bEnableUpdate = false;
    CWnd::SetWindowTextA(this: m_pEdit, lpszString: szBuf);
    m_pEdit->m_bEnableUpdate = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCAB0
// Name: public: void CAngleBox::SetDifferent(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleBox::SetDifferent(CAngleBox *this, bool bDifferent, bool bRedraw)
{
  CDC *v3; // edi
  HDC DC; // eax
  CDC *v6; // eax
  CAngleCombo *m_pEdit; // esi
  char szBuf[20]; // [esp+Ch] [ebp-14h] BYREF

  v3 = nullptr;
  if ( bRedraw )
  {
    DC = GetDC(hWnd: this->m_hWnd);
    v6 = CDC::FromHandle(hDC: DC);
    v3 = v6;
    if ( v6 != nullptr )
      CAngleBox::DrawAngleLine(this, a2: bRedraw, a3: (int)this, pDC: v6);
  }
  this->m_bDifferent = bDifferent;
  if ( bRedraw && v3 != nullptr )
  {
    CAngleBox::DrawAngleLine(this, a2: bRedraw, a3: (int)this, pDC: v3);
    ReleaseDC(hWnd: this->m_hWnd, hDC: v3->m_hDC);
  }
  if ( this->m_pEdit != nullptr )
  {
    CAngleBox::GetAngleEditText(this, szBuf);
    m_pEdit = this->m_pEdit;
    m_pEdit->m_bEnableUpdate = false;
    CWnd::SetWindowTextA(this: m_pEdit, lpszString: szBuf);
    m_pEdit->m_bEnableUpdate = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCB40
// Name: protected: void CAngleCombo::OnChangeAngleEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleCombo::OnChangeAngleEdit(CAngleCombo *this)
{
  HWND Parent; // eax
  CWnd *v3; // edi
  WPARAM DlgCtrlID; // eax
  char buf[64]; // [esp+4h] [ebp-40h] BYREF

  if ( this->m_bEnableUpdate )
  {
    CWnd::GetWindowTextA(this, lpszString: buf, nMaxCount: 64);
    CAngleCombo::UpdateAngleBox(this, szText: buf);
    Parent = GetParent(hWnd: this->m_hWnd);
    v3 = CWnd::FromHandle(hWnd: Parent);
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    PostMessageA(hWnd: v3->m_hWnd, Msg: 0x405u, wParam: DlgCtrlID, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCBA0
// Name: protected: void CAngleCombo::OnSelChangeAngleEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleCombo::OnSelChangeAngleEdit(CAngleCombo *this)
{
  WPARAM v2; // eax
  HWND Parent; // eax
  CWnd *v4; // edi
  WPARAM DlgCtrlID; // eax
  char buf[64]; // [esp+8h] [ebp-40h] BYREF

  v2 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x148u, wParam: v2, lParam: (LPARAM)buf);
  CAngleCombo::UpdateAngleBox(this, szText: buf);
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  DlgCtrlID = CWnd::GetDlgCtrlID(this);
  PostMessageA(hWnd: v4->m_hWnd, Msg: 0x405u, wParam: DlgCtrlID, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100BCC10
// Name: protected: void CAngleBox::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleBox::OnLButtonUp(CAngleBox *this, unsigned int nFlags, CPoint point)
{
  HDC v4; // eax
  HDC DC; // eax
  CDC *v6; // eax
  CDC *v7; // edi
  CAngleCombo *m_pEdit; // edi
  HWND Parent; // eax
  CWnd *v10; // edi
  WPARAM DlgCtrlID; // eax
  char szBuf[20]; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_bDragging )
  {
    v4 = CDC::Detach(this: &this->m_DragDC);
    ReleaseDC(hWnd: this->m_hWnd, hDC: v4);
    this->m_bDragging = false;
    ReleaseCapture();
    DC = GetDC(hWnd: this->m_hWnd);
    v6 = CDC::FromHandle(hDC: DC);
    v7 = v6;
    if ( v6 != nullptr )
      CAngleBox::DrawAngleLine(this, a2: (int)ReleaseDC, a3: (int)this, pDC: v6);
    this->m_bDifferent = false;
    if ( v7 != nullptr )
    {
      CAngleBox::DrawAngleLine(this, a2: (int)ReleaseDC, a3: (int)this, pDC: v7);
      ReleaseDC(hWnd: this->m_hWnd, hDC: v7->m_hDC);
    }
    if ( this->m_pEdit != nullptr )
    {
      CAngleBox::GetAngleEditText(this, szBuf);
      m_pEdit = this->m_pEdit;
      m_pEdit->m_bEnableUpdate = false;
      CWnd::SetWindowTextA(this: m_pEdit, lpszString: szBuf);
      m_pEdit->m_bEnableUpdate = true;
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    v10 = CWnd::FromHandle(hWnd: Parent);
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    PostMessageA(hWnd: v10->m_hWnd, Msg: 0x405u, wParam: DlgCtrlID, lParam: 0);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BCCF0
// Name: protected: virtual struct AFX_MSGMAP const __near * CAngleCombo::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CAngleCombo::GetMessageMap(CAngleCombo *this)
{
  return (const AFX_MSGMAP *)&off_105E8290;
}

//------------------------------------------------------------------------------
// Address: 0x100BCD00
// Name: protected: void CAngleBox::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAngleBox::OnPaint(CAngleBox *this)
{
  HDC v2; // eax
  CDC *v3; // esi
  COLORREF SysColor; // eax
  int v5; // ecx
  COLORREF v6; // eax
  COLORREF v7; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-94h]
  tagPAINTSTRUCT ps; // [esp+8h] [ebp-80h] BYREF
  CRect r; // [esp+48h] [ebp-40h] BYREF
  CBrush brushBlack; // [esp+58h] [ebp-30h] BYREF
  CPen hi; // [esp+60h] [ebp-28h] BYREF
  CPen lo; // [esp+68h] [ebp-20h] BYREF
  CBrush brushWindow; // [esp+70h] [ebp-18h] BYREF
  CBrush *pBackBrush; // [esp+78h] [ebp-10h]
  int v16; // [esp+84h] [ebp-4h]

  v2 = BeginPaint(hWnd: this->m_hWnd, lpPaint: &ps);
  v3 = CDC::FromHandle(hDC: v2);
  if ( v3 != nullptr )
  {
    SysColor = GetSysColor(nIndex: 15);
    CBrush::CBrush(this: &brushWindow, crColor: SysColor);
    v16 = 0;
    CBrush::CBrush(this: &brushBlack, crColor: 0);
    LOBYTE(v16) = 1;
    if ( CWnd::IsWindowEnabled(this) != 0 )
      pBackBrush = &brushBlack;
    else
      pBackBrush = &brushWindow;
    m_hWnd = this->m_hWnd;
    memset(&r, 0, sizeof(r));
    GetClientRect(hWnd: m_hWnd, lpRect: &r);
    FillRect(hDC: v3->m_hDC, lprc: &r, hbr: (HBRUSH)brushWindow.m_hObject);
    v5 = (r.top + r.bottom) / 2;
    this->m_ptClientCenter.x = (r.left + r.right) / 2;
    this->m_ptClientCenter.y = v5;
    v3->SelectStockObject(this: v3, a2: 8);
    CDC::SelectObject(this: v3, pFont: (CFont *)pBackBrush);
    Ellipse(hdc: v3->m_hDC, left: r.left, top: r.top, right: r.right, bottom: r.bottom);
    v6 = GetSysColor(nIndex: 16);
    CPen::CPen(this: &hi, nPenStyle: 0, nWidth: 2, crColor: v6);
    LOBYTE(v16) = 2;
    v7 = GetSysColor(nIndex: 20);
    CPen::CPen(this: &lo, nPenStyle: 0, nWidth: 2, crColor: v7);
    LOBYTE(v16) = 3;
    if ( hi.m_hObject != nullptr )
      SelectObject(hdc: v3->m_hDC, h: hi.m_hObject);
    Arc(
      hdc: v3->m_hDC,
      x1: r.left,
      y1: r.top,
      x2: r.right,
      y2: r.bottom,
      x3: r.right,
      y3: r.top,
      x4: r.left,
      y4: r.bottom);
    if ( lo.m_hObject != nullptr )
      SelectObject(hdc: v3->m_hDC, h: lo.m_hObject);
    Arc(
      hdc: v3->m_hDC,
      x1: r.left,
      y1: r.top,
      x2: r.right,
      y2: r.bottom,
      x3: r.left,
      y3: r.bottom,
      x4: r.right,
      y4: r.top);
    SetPixel(hdc: v3->m_hDC, x: this->m_ptClientCenter.x, y: this->m_ptClientCenter.y, color: 0xFFFFFFu);
    if ( CWnd::IsWindowEnabled(this) != 0 )
      CAngleBox::DrawAngleLine(this, a2: (int)GetSysColor, a3: (int)v3, pDC: v3);
    EndPaint(hWnd: this->m_hWnd, lpPaint: &ps);
    lo.__vftable = (CPen_vtbl *)&CPen::`vftable';
    LOBYTE(v16) = 2;
    CGdiObject::~CGdiObject(this: &lo);
    hi.__vftable = (CPen_vtbl *)&CPen::`vftable';
    LOBYTE(v16) = 1;
    CGdiObject::~CGdiObject(this: &hi);
    brushBlack.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    LOBYTE(v16) = 0;
    CGdiObject::~CGdiObject(this: &brushBlack);
    brushWindow.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
    v16 = -1;
    CGdiObject::~CGdiObject(this: &brushWindow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BCF40
// Name: protected: virtual struct AFX_MSGMAP const __near * CAngleBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CAngleBox::GetMessageMap(CAngleBox *this)
{
  return (const AFX_MSGMAP *)&off_105E82E0;
}

//------------------------------------------------------------------------------
// Address: 0x10338F69
// Name: public: virtual void CCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCmdUI::Enable(CCmdUI *this, int bOn)
{
  CMenu *m_pMenu; // ecx
  UINT m_nIndex; // eax
  CWnd *m_pOther; // edi
  HWND Parent; // eax
  CWnd *v7; // eax

  m_pMenu = this->m_pMenu;
  if ( m_pMenu != nullptr )
  {
    if ( this->m_pSubMenu != nullptr )
      return;
    m_nIndex = this->m_nIndex;
    if ( m_nIndex >= this->m_nIndexMax )
      goto LABEL_4;
    EnableMenuItem(hMenu: m_pMenu->m_hMenu, uIDEnableItem: m_nIndex, uEnable: (bOn != 0 ? 0 : 3) | 0x400);
  }
  else
  {
    if ( this->m_pOther == nullptr )
LABEL_4:
      AfxThrowInvalidArgException();
    if ( bOn == 0 )
    {
      m_pOther = this->m_pOther;
      if ( GetFocus() == m_pOther->m_hWnd )
      {
        Parent = GetParent(hWnd: m_pOther->m_hWnd);
        v7 = CWnd::FromHandle(hWnd: Parent);
        SendMessageA(hWnd: v7->m_hWnd, Msg: 0x28u, wParam: 0, lParam: 0);
      }
    }
    CWnd::EnableWindow(this: this->m_pOther, bEnable: bOn);
  }
  this->m_bEnableChanged = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10339B62
// Name: public: virtual void CTestCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestCmdUI::Enable(CMFCColorBarCmdUI *this, int bOn)
{
  this->m_bEnabled = bOn;
  this->m_bEnableChanged = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10350283
// Name: public: virtual void CStatusCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatusCmdUI::Enable(CStatusCmdUI *this, int bOn)
{
  CStatusBar *m_pOther; // ecx
  unsigned int m_nIndex; // edx
  unsigned int v5; // eax

  m_pOther = (CStatusBar *)this->m_pOther;
  m_nIndex = this->m_nIndex;
  this->m_bEnableChanged = 1;
  v5 = *((_DWORD *)m_pOther->m_pData + 5 * m_nIndex + 2) & 0xFBFFFFFF;
  if ( bOn == 0 )
    v5 |= 0x4000000u;
  CStatusBar::SetPaneStyle(this: m_pOther, nIndex: m_nIndex, nStyle: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10354842
// Name: public: virtual void CToolCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CToolCmdUI::Enable(CToolCmdUI *this@<ecx>, int a2@<ebx>, int bOn)
{
  CToolBar *m_pOther; // edi
  unsigned int v5; // eax
  unsigned int m_nIndex; // [esp-4h] [ebp-Ch]

  m_pOther = (CToolBar *)this->m_pOther;
  m_nIndex = this->m_nIndex;
  this->m_bEnableChanged = 1;
  v5 = CToolBar::GetButtonStyle(this: m_pOther, nIndex: m_nIndex) & 0xFFFBFFFF;
  if ( bOn == 0 )
    v5 = v5 & 0xFFF9FFFF | 0x40000;
  CToolBar::SetButtonStyle(this: m_pOther, a2, nIndex: this->m_nIndex, nStyle: v5);
}

//------------------------------------------------------------------------------
// Address: 0x103AC55C
// Name: public: virtual void CMFCToolBarCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarCmdUI::Enable(CMFCToolBarCmdUI *this, int bOn)
{
  CMFCToolBar *m_pOther; // edi
  unsigned int v4; // eax

  m_pOther = (CMFCToolBar *)this->m_pOther;
  this->m_bEnableChanged = 1;
  if ( m_pOther == nullptr )
    AfxThrowInvalidArgException();
  v4 = CMFCToolBar::GetButtonStyle(this: m_pOther, nIndex: this->m_nIndex) & 0xFFFBFFFF;
  if ( bOn == 0 )
    v4 |= 0x40000u;
  m_pOther->SetButtonStyle(this: m_pOther, a2: this->m_nIndex, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103F15A6
// Name: public: virtual void CMFCRibbonCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCmdUI::Enable(CMFCRibbonCmdUI *this, int bOn)
{
  CMFCRibbonBaseElement *m_pUpdated; // ecx
  int v4; // esi
  CRect *p_m_rect; // esi
  CWnd *m_pOther; // eax
  RECT rcUpdate; // [esp+8h] [ebp-14h] BYREF

  m_pUpdated = this->m_pUpdated;
  this->m_bEnableChanged = 1;
  v4 = bOn == 0;
  if ( m_pUpdated->IsDisabled(this: m_pUpdated) != v4 )
  {
    this->m_pUpdated->m_bIsDisabled = v4;
    this->m_pUpdated->OnEnable(this: this->m_pUpdated, a2: bOn != 0);
    p_m_rect = &this->m_pUpdated->m_rect;
    rcUpdate.left = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.top = p_m_rect->left;
    p_m_rect = (CRect *)((char *)p_m_rect + 4);
    rcUpdate.right = p_m_rect->left;
    m_pOther = this->m_pOther;
    rcUpdate.bottom = p_m_rect->top;
    RedrawWindow(hWnd: m_pOther->m_hWnd, lprcUpdate: &rcUpdate, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043026F
// Name: public: virtual void CMFCTasksPaneToolBarCmdUI::Enable(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneToolBarCmdUI::Enable(CMFCTasksPaneToolBarCmdUI *this, CObject_vtbl *bOn)
{
  CMFCTasksPane *m_pOther; // ecx
  CMFCTasksPaneTaskGroup *TaskGroup; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // esi
  HWND__ *v7; // esi
  CWnd *v8; // eax
  CMFCTasksPane *pTasksPane; // [esp+4h] [ebp-4h]

  m_pOther = (CMFCTasksPane *)this->m_pOther;
  this->m_bEnableChanged = 1;
  pTasksPane = m_pOther;
  if ( m_pOther == nullptr )
    AfxThrowInvalidArgException();
  TaskGroup = CMFCTasksPane::GetTaskGroup(this: m_pOther, nGroup: this->m_nIndex);
  if ( TaskGroup != nullptr )
  {
    m_pNodeHead = TaskGroup->m_lstTasks.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data[9].__vftable == (CObject_vtbl *)this->m_nID && data[14].__vftable != bOn )
      {
        data[14].__vftable = bOn;
        InvalidateRect(hWnd: pTasksPane->m_hWnd, lpRect: (const RECT *)&data[3], bErase: true);
        v7 = (HWND__ *)data[11].__vftable;
        if ( v7 != nullptr )
        {
          v8 = CWnd::FromHandle(hWnd: v7);
          CWnd::EnableWindow(this: v8, bEnable: (int)bOn);
        }
      }
    }
  }
}
