// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/tabwindow.cpp
// Functions: 19
// ============================================================

#include "utils\scenemanager\tabwindow.h"

//------------------------------------------------------------------------------
// Address: 0x00413260
// Name: public: virtual void CTabWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::redraw(CTabWindow *this)
{
  int v2; // edi
  int v3; // eax
  int i; // edi
  int m_nSelected; // eax
  CDrawHelper drawHelper; // [esp+8h] [ebp-64h] BYREF
  tagRECT rc; // [esp+5Ch] [ebp-10h] BYREF

  CDrawHelper::CDrawHelper(this: &drawHelper, widget: this, bgColor: this->m_Colors[0]);
  if ( this->m_bInverted )
    v2 = 1;
  else
    v2 = mxWidget::h2(this) - 2;
  v3 = mxWidget::w(this);
  CDrawHelper::DrawColoredLine(
    this: &drawHelper,
    clr: (HPEN__ *)this->m_Colors[3],
    style: 0,
    width: 1,
    x1: 0,
    y1: v2,
    x2: v3,
    y2: v2);
  CDrawHelper::GetClientRect(this: &drawHelper, &rc);
  for ( i = 0; i < this->m_Items.m_Size; ++i )
  {
    if ( i != this->m_nSelected )
      this->DrawTab(this, a2: &drawHelper, a3: &rc, a4: i, a5: false);
  }
  m_nSelected = this->m_nSelected;
  if ( m_nSelected >= 0 && m_nSelected < this->m_Items.m_Size )
    this->DrawTab(this, a2: &drawHelper, a3: &rc, a4: m_nSelected, a5: true);
  CDrawHelper::~CDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00413310
// Name: public: virtual void CTabWindow::select(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::select(CTabWindow *this, int index)
{
  if ( index >= 0 && index < this->m_Items.m_Size )
  {
    this->m_nSelected = index;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413330
// Name: public: virtual int CTabWindow::getItemCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::getItemCount(CTabWindow *this)
{
  return this->m_Items.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00413340
// Name: public: void CUtlMemory<class CTabWindow::CETItem,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CTabWindow::CETItem,int>::Grow(CUtlMemory<CTabWindow::CETItem,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CTabWindow::CETItem *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 144 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CTabWindow::CETItem *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CTabWindow::CETItem *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004133E0
// Name: protected: virtual void CTabWindow::DrawTab(class CDrawHelper __near &,struct tagRECT __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTabWindow::DrawTab(
        CTabWindow *this@<ecx>,
        int a2@<edi>,
        CDrawHelper *drawHelper,
        tagRECT *rcClient,
        int tabnum,
        bool selected)
{
  BOOL v8; // edx
  BOOL m_bInverted; // ecx
  int m_nPixelDelta; // eax
  int v11; // ebx
  HDC Count; // edi
  HRGN PolygonRgn; // ebx
  int v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-Ch] [ebp-4Ch]
  tagPOINT region[4]; // [esp+4h] [ebp-3Ch] BYREF
  tagRECT rcTab; // [esp+24h] [ebp-1Ch] BYREF
  unsigned int text; // [esp+34h] [ebp-Ch]
  int oldPF; // [esp+38h] [ebp-8h]
  unsigned int hilightcolor; // [esp+3Ch] [ebp-4h]
  HBRUSH__ *brBg; // [esp+54h] [ebp+14h]
  HBRUSH__ *brBga; // [esp+54h] [ebp+14h]

  if ( tabnum >= 0 && tabnum < this->m_Items.m_Size )
  {
    rcTab = this->m_Items.m_Memory.m_pMemory[tabnum].rect;
    v8 = selected;
    brBg = (HBRUSH__ *)this->m_Colors[v8 + 1];
    hilightcolor = this->m_Colors[v8 + 3];
    m_bInverted = this->m_bInverted;
    text = this->m_Colors[selected + 5];
    OffsetRect(lprc: &rcTab, dx: 0, dy: 2 * m_bInverted - 1);
    m_nPixelDelta = this->m_nPixelDelta;
    if ( this->m_bInverted )
    {
      region[0].x = rcTab.left - m_nPixelDelta;
      v11 = m_nPixelDelta + rcTab.right;
      region[2].x = rcTab.right - m_nPixelDelta;
      region[0].y = rcTab.top;
      region[1].y = rcTab.top;
      region[2].y = rcTab.bottom;
      region[3].x = rcTab.left + m_nPixelDelta;
    }
    else
    {
      region[0].x = m_nPixelDelta + rcTab.left;
      region[0].y = rcTab.top;
      region[1].y = rcTab.top;
      v11 = rcTab.right - m_nPixelDelta;
      region[2].x = m_nPixelDelta + rcTab.right;
      region[2].y = rcTab.bottom;
      region[3].x = rcTab.left - m_nPixelDelta;
    }
    region[3].y = rcTab.bottom;
    region[1].x = v11;
    Count = (HDC)CCurveData::GetCount(this: (IterateRIFF *)drawHelper);
    PolygonRgn = CreatePolygonRgn(pptl: region, cPoint: 4, iMode: 1);
    oldPF = SetPolyFillMode(hdc: Count, mode: 1);
    brBga = CreateSolidBrush(color: (COLORREF)brBg);
    hilightcolor = (unsigned int)CreateSolidBrush(color: hilightcolor);
    FillRgn(hdc: Count, hrgn: PolygonRgn, hbr: brBga);
    FrameRgn(hdc: Count, hrgn: PolygonRgn, hbr: (HBRUSH)hilightcolor, w: 1, h: 1);
    SetPolyFillMode(hdc: Count, mode: oldPF);
    DeleteObject(ho: PolygonRgn);
    DeleteObject(ho: brBga);
    DeleteObject(ho: (HGDIOBJ)hilightcolor);
    InflateRect(lprc: &rcTab, dx: -5, dy: 0);
    OffsetRect(lprc: &rcTab, dx: 2, dy: 0);
    v14 = ((int (__thiscall *)(CTabWindow *, int, int))this->getLabel)(a1: this, a2: tabnum, a3: a2);
    v15 = (const char *)((int (__thiscall *)(CTabWindow *, int, int))this->getPrefix)(a1: this, a2: tabnum, a3: v14);
    CDrawHelper::DrawColoredText(
      this: drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: text,
      rcText: &rcTab,
      fmt: "%s%s",
      v15,
      v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004135C0
// Name: protected: int CTabWindow::GetItemUnderMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::GetItemUnderMouse(CTabWindow *this, int mx, int my)
{
  HWND Handle; // eax
  int m_Size; // edx
  int result; // eax
  tagRECT *i; // ecx
  tagRECT rcClient; // [esp+8h] [ebp-20h] BYREF
  tagRECT rcTab; // [esp+18h] [ebp-10h]

  Handle = (HWND)mxWidget::getHandle(this);
  GetClientRect(hWnd: Handle, lpRect: &rcClient);
  m_Size = this->m_Items.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = &this->m_Items.m_Memory.m_pMemory->rect; ; i += 9 )
  {
    rcTab = *i;
    if ( mx >= rcTab.left && mx <= rcTab.right && my >= rcTab.top && my <= rcTab.bottom )
      break;
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413630
// Name: public: virtual void CTabWindow::setPrefix(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::setPrefix(CTabWindow *this, int item, char *prefix)
{
  if ( item >= 0 && item < this->m_Items.m_Size )
    strncpy(
      dest: (unsigned __int8 *)this->m_Items.m_Memory.m_pMemory[item].m_szPrefix,
      source: (unsigned __int8 *)prefix,
      count: 0x40u);
}

//------------------------------------------------------------------------------
// Address: 0x00413660
// Name: public: virtual char const __near * CTabWindow::getLabel(int)
// Source: json
//------------------------------------------------------------------------------
CTabWindow::CETItem *__thiscall CTabWindow::getLabel(CTabWindow *this, int item)
{
  if ( item < 0 || item >= this->m_Items.m_Size )
    return (CTabWindow::CETItem *)&WindowName;
  else
    return &this->m_Items.m_Memory.m_pMemory[item];
}

//------------------------------------------------------------------------------
// Address: 0x00413690
// Name: public: virtual char const __near * CTabWindow::getPrefix(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTabWindow::getPrefix(CTabWindow *this, int item)
{
  if ( item < 0 || item >= this->m_Items.m_Size )
    return (char *)&WindowName;
  else
    return this->m_Items.m_Memory.m_pMemory[item].m_szPrefix;
}

//------------------------------------------------------------------------------
// Address: 0x004136C0
// Name: protected: int CTabWindow::RecomputeLayout(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::RecomputeLayout(CTabWindow *this, int windowWidth, bool dolayout)
{
  int m_nPixelDelta; // eax
  int v5; // ebx
  int v6; // eax
  CTabWindow::CETItem *v7; // edi
  int v8; // eax
  int v9; // ecx
  int m_nRowHeight; // eax
  int v11; // edx
  __int64 rc; // [esp+8h] [ebp-24h]
  __int64 rc_8; // [esp+10h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-14h]
  int startedge; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  int currentrow; // [esp+24h] [ebp-8h]
  int curtop; // [esp+28h] [ebp-4h]

  m_nPixelDelta = this->m_nPixelDelta;
  v5 = m_nPixelDelta + 1;
  curtop = 0;
  if ( this->m_bRightJustify )
    v5 = windowWidth - m_nPixelDelta - 6;
  v6 = 0;
  startedge = v5;
  currentrow = 0;
  i = 0;
  if ( this->m_Items.m_Size > 0 )
  {
    v17 = 0;
    do
    {
      v7 = &this->m_Items.m_Memory.m_pMemory[v17];
      v8 = CDrawHelper::CalcTextWidth(
             font: "Arial",
             pointsize: (HFONT__ *)9,
             weight: 400,
             fmt: "%s%s",
             v7->m_szPrefix,
             v7->m_szString)
         + 15;
      if ( this->m_bRightJustify )
      {
        v11 = curtop;
        if ( v5 - v8 < 0 )
        {
          v11 = this->m_nRowHeight + curtop;
          v5 = startedge;
          ++currentrow;
          curtop = v11;
        }
        HIDWORD(rc) = v11;
        LODWORD(rc_8) = v5;
        LODWORD(rc) = v5 - v8;
        HIDWORD(rc_8) = v11 + this->m_nRowHeight - 2;
        v5 -= v8;
      }
      else
      {
        v9 = curtop;
        if ( v8 + v5 > windowWidth )
        {
          v9 = this->m_nRowHeight + curtop;
          v5 = startedge;
          ++currentrow;
          curtop = v9;
        }
        LODWORD(rc) = v5;
        v5 += v8;
        m_nRowHeight = this->m_nRowHeight;
        HIDWORD(rc) = v9 + 2;
        *(_QWORD *)&v7->rect.left = rc;
        LODWORD(rc_8) = v5;
        HIDWORD(rc_8) = v9 + m_nRowHeight;
        *(_QWORD *)&v7->rect.right = rc_8;
      }
      if ( dolayout )
      {
        *(_QWORD *)&v7->rect.left = rc;
        *(_QWORD *)&v7->rect.right = rc_8;
      }
      ++v17;
      ++i;
    }
    while ( i < this->m_Items.m_Size );
    v6 = currentrow;
  }
  if ( dolayout )
    this->m_nRowsRequired = v6 + 1;
  return v6 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413800
// Name: public: void CTabWindow::SetInverted(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::SetInverted(CTabWindow *this, bool invert)
{
  int v3; // eax

  this->m_bInverted = invert;
  v3 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v3, dolayout: true);
}

//------------------------------------------------------------------------------
// Address: 0x00413820
// Name: public: virtual int CTabWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::handleEvent(CTabWindow *this, HWND__ *event)
{
  int v3; // edi
  int ItemUnderMouse; // eax
  CTabWindow_vtbl *v6; // edx
  mxWindow *v7; // eax
  WPARAM v8; // edi
  void *Handle; // eax
  int v11; // eax
  HWND__ *parent; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( *((_DWORD *)event + 1) == 1 )
  {
    v11 = mxWidget::w2(this);
    CTabWindow::RecomputeLayout(this, windowWidth: v11, dolayout: true);
  }
  else if ( *((_DWORD *)event + 1) == 7 )
  {
    ItemUnderMouse = CTabWindow::GetItemUnderMouse(this, mx: *((__int16 *)event + 12), my: *((__int16 *)event + 14));
    if ( ItemUnderMouse != -1 )
    {
      v6 = this->__vftable;
      this->m_nSelected = ItemUnderMouse;
      v6->redraw(this);
      if ( mxWidget::getParent(this) != nullptr )
      {
        v7 = mxWidget::getParent(this);
        parent = (HWND__ *)mxWidget::getHandle(this: v7);
        if ( parent != nullptr )
        {
          v8 = (unsigned __int16)mxWidget::getId(this) | 0x10000;
          Handle = mxWidget::getHandle(this);
          PostMessageA(hWnd: parent, Msg: 0x111u, wParam: v8, lParam: (LPARAM)Handle);
        }
      }
      v3 = 1;
    }
    if ( ((_BYTE)event[8] & 2) != 0 )
    {
      this->ShowRightClickMenu(this, a2: *((__int16 *)event + 12), a3: *((__int16 *)event + 14));
      return 1;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004138F0
// Name: public: virtual void CTabWindow::remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::remove(CTabWindow *this, int index)
{
  int m_nSelected; // eax
  int v4; // eax

  if ( index >= 0 && index < this->m_Items.m_Size )
  {
    if ( this->m_Items.m_Size - index - 1 > 0 )
      _V_memmove(
        dest: &this->m_Items.m_Memory.m_pMemory[index],
        src: &this->m_Items.m_Memory.m_pMemory[index + 1],
        count: 144 * (this->m_Items.m_Size - index - 1));
    m_nSelected = --this->m_Items.m_Size - 1;
    if ( this->m_nSelected < m_nSelected )
      m_nSelected = this->m_nSelected;
    this->m_nSelected = m_nSelected <= 0 ? 0 : m_nSelected;
    v4 = mxWidget::w2(this);
    CTabWindow::RecomputeLayout(this, windowWidth: v4, dolayout: true);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413970
// Name: public: virtual void CTabWindow::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::removeAll(CTabWindow *this)
{
  int v2; // eax

  this->m_nSelected = -1;
  this->m_Items.m_Size = 0;
  v2 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v2, dolayout: true);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x004139A0
// Name: public: void CTabWindow::SetRowHeight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::SetRowHeight(CTabWindow *this, int rowheight)
{
  int v3; // eax

  this->m_nRowHeight = rowheight;
  v3 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v3, dolayout: true);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x004139D0
// Name: public: int CTabWindow::GetBestHeight(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::GetBestHeight(CTabWindow *this, int width)
{
  return this->m_nRowHeight * CTabWindow::RecomputeLayout(this, windowWidth: width, dolayout: false);
}

//------------------------------------------------------------------------------
// Address: 0x004139F0
// Name: public: CTabWindow::CTabWindow(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CTabWindow *__thiscall CTabWindow::CTabWindow(
        CTabWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        int id,
        int style)
{
  mxWindow::mxWindow(this, parent, x, y, w, h, label: &WindowName, style);
  this->__vftable = (CTabWindow_vtbl *)&CTabWindow::`vftable';
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  mxWidget::setId(this, id);
  this->m_nSelected = -1;
  this->m_nRowHeight = 20;
  this->m_nRowsRequired = 1;
  this->m_nTabWidth = 80;
  this->m_nPixelDelta = 3;
  *(_WORD *)&this->m_bInverted = 0;
  this->m_Colors[0] = GetSysColor(nIndex: 15);
  this->m_Colors[1] = GetSysColor(nIndex: 3);
  this->m_Colors[2] = GetSysColor(nIndex: 2);
  this->m_Colors[3] = GetSysColor(nIndex: 16);
  this->m_Colors[4] = GetSysColor(nIndex: 20);
  this->m_Colors[5] = GetSysColor(nIndex: 18);
  this->m_Colors[6] = GetSysColor(nIndex: 19);
  SceneManager_AddWindowStyle(w: this, addbits: 100663296);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00413AC0
// Name: public: virtual CTabWindow::~CTabWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::~CTabWindow(CTabWindow *this)
{
  int v2; // eax

  this->__vftable = (CTabWindow_vtbl *)&CTabWindow::`vftable';
  this->m_nSelected = -1;
  this->m_Items.m_Size = 0;
  v2 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v2, dolayout: true);
  this->redraw(this);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Items);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00413B70
// Name: public: virtual void CTabWindow::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::add(CTabWindow *this, const char *item)
{
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CTabWindow::CETItem *m_pMemory; // ecx
  int v6; // eax
  CTabWindow::CETItem *v7; // esi
  int m_nSelected; // eax
  int v9; // eax

  m_Size = this->m_Items.m_Size;
  m_nAllocationCount = this->m_Items.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CTabWindow::CETItem,int>::Grow(this: &this->m_Items.m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Items.m_Size;
  m_pMemory = this->m_Items.m_Memory.m_pMemory;
  v6 = this->m_Items.m_Size - m_Size - 1;
  this->m_Items.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 144 * v6);
  v7 = &this->m_Items.m_Memory.m_pMemory[this->m_Items.m_Size - 1];
  _V_memset(dest: &v7->rect, fill: 0, count: 16);
  strcpy(v7->m_szString, item);
  v7->m_szPrefix[0] = 0;
  m_nSelected = this->m_Items.m_Size - 1;
  if ( this->m_nSelected < m_nSelected )
    m_nSelected = this->m_nSelected;
  this->m_nSelected = m_nSelected <= 0 ? 0 : m_nSelected;
  v9 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v9, dolayout: true);
  this->redraw(this);
}
