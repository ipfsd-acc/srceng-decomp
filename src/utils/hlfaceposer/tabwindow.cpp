// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/tabwindow.cpp
// Functions: 19
// ============================================================

#include "utils\hlfaceposer\tabwindow.h"

//------------------------------------------------------------------------------
// Address: 0x00481950
// Name: public: virtual void CTabWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::redraw(CTabWindow *this)
{
  int v2; // edi
  int v3; // eax
  int i; // edi
  int m_nSelected; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+8h] [ebp-68h] BYREF
  tagRECT rc; // [esp+60h] [ebp-10h] BYREF

  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bgColor: this->m_Colors);
  if ( this->m_bInverted )
    v2 = 1;
  else
    v2 = mxWidget::h2(this) - 2;
  v3 = mxWidget::w(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: &drawHelper,
    clr: (HPEN__ *)&this->m_Colors[3],
    style: 0,
    width: 1,
    x1: 0,
    y1: v2,
    x2: v3,
    y2: v2);
  CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
  for ( i = 0; i < this->m_Items.m_Size; ++i )
  {
    if ( i != this->m_nSelected )
      this->DrawTab(this, a2: &drawHelper, a3: &rc, a4: i, a5: false);
  }
  m_nSelected = this->m_nSelected;
  if ( m_nSelected >= 0 && m_nSelected < this->m_Items.m_Size )
    this->DrawTab(this, a2: &drawHelper, a3: &rc, a4: m_nSelected, a5: true);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00481A00
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
// Address: 0x00481A30
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
// Address: 0x00481AD0
// Name: protected: virtual void CTabWindow::DrawTab(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTabWindow::DrawTab(
        CTabWindow *this@<ecx>,
        int a2@<edi>,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcClient,
        int tabnum,
        bool selected)
{
  BOOL v8; // edx
  BOOL m_bInverted; // ecx
  int m_nPixelDelta; // eax
  int v11; // ebx
  HDC NumChannels; // edi
  HRGN PolygonRgn; // ebx
  int v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-Ch] [ebp-4Ch]
  tagPOINT region[4]; // [esp+4h] [ebp-3Ch] BYREF
  tagRECT rcTab; // [esp+24h] [ebp-1Ch] BYREF
  Color text; // [esp+34h] [ebp-Ch] BYREF
  int oldPF; // [esp+38h] [ebp-8h]
  Color hilightcolor; // [esp+3Ch] [ebp-4h]
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
    NumChannels = (HDC)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)drawHelper);
    PolygonRgn = CreatePolygonRgn(pptl: region, cPoint: 4, iMode: 1);
    oldPF = SetPolyFillMode(hdc: NumChannels, mode: 1);
    brBga = CreateSolidBrush(color: (unsigned __int8)brBg | (*(unsigned __int16 *)((char *)&brBg + 1) << 8));
    hilightcolor = (Color)CreateSolidBrush(color: hilightcolor._color[0] | (*(unsigned __int16 *)&hilightcolor._color[1] << 8));
    FillRgn(hdc: NumChannels, hrgn: PolygonRgn, hbr: brBga);
    FrameRgn(hdc: NumChannels, hrgn: PolygonRgn, hbr: *(HBRUSH *)&hilightcolor, w: 1, h: 1);
    SetPolyFillMode(hdc: NumChannels, mode: oldPF);
    DeleteObject(ho: PolygonRgn);
    DeleteObject(ho: brBga);
    DeleteObject(ho: *(HGDIOBJ *)&hilightcolor);
    InflateRect(lprc: &rcTab, dx: -5, dy: 0);
    OffsetRect(lprc: &rcTab, dx: 2, dy: 0);
    v14 = ((int (__thiscall *)(CTabWindow *, int, int))this->getLabel)(a1: this, a2: tabnum, a3: a2);
    v15 = (const char *)((int (__thiscall *)(CTabWindow *, int, int))this->getPrefix)(a1: this, a2: tabnum, a3: v14);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: drawHelper,
      font: "Arial",
      pointsize: 9,
      weight: 400,
      clr: &text,
      rcText: &rcTab,
      fmt: "%s%s",
      v15,
      v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481CD0
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
// Address: 0x00481D40
// Name: public: virtual void CTabWindow::setPrefix(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::setPrefix(CTabWindow *this, int item, const char *prefix)
{
  if ( item >= 0 && item < this->m_Items.m_Size )
    V_strncpy(pDest: this->m_Items.m_Memory.m_pMemory[item].m_szPrefix, pSrc: prefix, maxLen: 64);
}

//------------------------------------------------------------------------------
// Address: 0x00481D70
// Name: public: virtual char const __near * CTabWindow::getLabel(int)
// Source: json
//------------------------------------------------------------------------------
CTabWindow::CETItem *__thiscall CTabWindow::getLabel(CTabWindow *this, int item)
{
  if ( item < 0 || item >= this->m_Items.m_Size )
    return (CTabWindow::CETItem *)defaultValue;
  else
    return &this->m_Items.m_Memory.m_pMemory[item];
}

//------------------------------------------------------------------------------
// Address: 0x00481DA0
// Name: public: virtual char const __near * CTabWindow::getPrefix(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTabWindow::getPrefix(CTabWindow *this, int item)
{
  if ( item < 0 || item >= this->m_Items.m_Size )
    return (char *)defaultValue;
  else
    return this->m_Items.m_Memory.m_pMemory[item].m_szPrefix;
}

//------------------------------------------------------------------------------
// Address: 0x00481DD0
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
      v8 = CChoreoWidgetDrawHelper::CalcTextWidth(
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
// Address: 0x00481F10
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
// Address: 0x00481F30
// Name: public: void CTabWindow::SetRightJustify(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTabWindow::SetRightJustify(CTabWindow *this, bool rightjustify)
{
  int v3; // eax

  this->m_bRightJustify = true;
  v3 = mxWidget::w2(this);
  CTabWindow::RecomputeLayout(this, windowWidth: v3, dolayout: true);
}

//------------------------------------------------------------------------------
// Address: 0x00481F50
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
// Address: 0x00482020
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
// Address: 0x004820A0
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
// Address: 0x004820D0
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
// Address: 0x00482100
// Name: public: int CTabWindow::GetBestHeight(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTabWindow::GetBestHeight(CTabWindow *this, int width)
{
  return this->m_nRowHeight * CTabWindow::RecomputeLayout(this, windowWidth: width, dolayout: false);
}

//------------------------------------------------------------------------------
// Address: 0x00482120
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
  DWORD SysColor; // eax
  DWORD v10; // eax
  DWORD v11; // eax
  DWORD v12; // eax
  DWORD v13; // eax
  DWORD v14; // eax
  DWORD v15; // eax
  int stylea; // [esp+2Ch] [ebp+20h]

  mxWindow::mxWindow(this, parent, x, y, w, h, label: defaultValue, style);
  this->__vftable = (CTabWindow_vtbl *)&CTabWindow::`vftable';
  this->m_Items.m_Memory.m_pMemory = nullptr;
  this->m_Items.m_Memory.m_nAllocationCount = 0;
  this->m_Items.m_Memory.m_nGrowSize = 0;
  this->m_Items.m_Size = 0;
  this->m_Items.m_pElements = nullptr;
  this->m_Colors[0] = 0;
  this->m_Colors[1] = 0;
  this->m_Colors[2] = 0;
  this->m_Colors[3] = 0;
  this->m_Colors[4] = 0;
  this->m_Colors[5] = 0;
  this->m_Colors[6] = 0;
  mxWidget::setId(this, id);
  this->m_nSelected = -1;
  this->m_nRowHeight = 20;
  this->m_nRowsRequired = 1;
  this->m_nTabWidth = 80;
  this->m_nPixelDelta = 3;
  *(_WORD *)&this->m_bInverted = 0;
  SysColor = GetSysColor(nIndex: 15);
  LOWORD(stylea) = SysColor;
  HIWORD(stylea) = BYTE2(SysColor);
  this->m_Colors[0] = (Color)stylea;
  v10 = GetSysColor(nIndex: 3);
  LOWORD(stylea) = v10;
  HIWORD(stylea) = BYTE2(v10);
  this->m_Colors[1] = (Color)stylea;
  v11 = GetSysColor(nIndex: 2);
  LOWORD(stylea) = v11;
  HIWORD(stylea) = BYTE2(v11);
  this->m_Colors[2] = (Color)stylea;
  v12 = GetSysColor(nIndex: 16);
  LOWORD(stylea) = v12;
  HIWORD(stylea) = BYTE2(v12);
  this->m_Colors[3] = (Color)stylea;
  v13 = GetSysColor(nIndex: 20);
  LOWORD(stylea) = v13;
  HIWORD(stylea) = BYTE2(v13);
  this->m_Colors[4] = (Color)stylea;
  v14 = GetSysColor(nIndex: 9);
  LOWORD(stylea) = v14;
  HIWORD(stylea) = BYTE2(v14);
  this->m_Colors[5] = (Color)stylea;
  v15 = GetSysColor(nIndex: 19);
  LOWORD(stylea) = v15;
  HIWORD(stylea) = BYTE2(v15);
  this->m_Colors[6] = (Color)stylea;
  FacePoser_AddWindowStyle(w: this, addbits: 100663296);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004822A0
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
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Items);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00482350
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
