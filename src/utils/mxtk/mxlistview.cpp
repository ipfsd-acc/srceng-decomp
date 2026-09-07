// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxlistview.cpp
// Functions: 15
// ============================================================

#include "utils\mxtk\mxlistview.h"

//------------------------------------------------------------------------------
// Address: 0x004C4530
// Name: public: mxListView::mxListView(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxListView *__thiscall mxListView::mxListView(mxListView *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxListView_vtbl *)&mxListView::`vftable';
  if ( parent != nullptr )
  {
    this->d_this = (mxListView_i *)operator new(nSize: 4u);
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    this->d_this->d_hwnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SysListView32",
                             lpWindowName: defaultValue,
                             dwStyle: 0x50008009u,
                             X: x,
                             Y: y,
                             nWidth: w,
                             nHeight: h,
                             hWndParent: Handle,
                             hMenu: id,
                             hInstance: ModuleHandleA,
                             lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: this->d_this->d_hwnd);
    mxWidget::setType(this, type: 20);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C4620
// Name: public: void mxListView::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::removeAll(mxListView *this)
{
  SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x1009u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C4640
// Name: public: void mxListView::setLabel(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setLabel(mxListView *this, int item, int column, char *label)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 1;
    lvItem.iSubItem = column;
    lvItem.pszText = label;
    lvItem.cchTextMax = 256;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C46A0
// Name: public: void mxListView::setUserData(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setUserData(mxListView *this, int item, int column, void *userData)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 4;
    lvItem.iSubItem = column;
    lvItem.lParam = (int)userData;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4700
// Name: public: void mxListView::setSelected(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setSelected(mxListView *this, WPARAM item, bool b)
{
  mxListView_i *d_this; // eax
  tagLVITEMA _macro_lvi; // [esp+0h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    _macro_lvi.state = b ? 3 : 0;
    _macro_lvi.stateMask = 3;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x102Bu, wParam: item, lParam: (LPARAM)&_macro_lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4740
// Name: public: int mxListView::getItemCount(void)const
// Source: json
//------------------------------------------------------------------------------
mxListView_i *__thiscall mxListView::getItemCount(mxListView *this)
{
  mxListView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxListView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4760
// Name: public: int mxListView::getNumSelected(void)const
// Source: json
//------------------------------------------------------------------------------
mxListView_i *__thiscall mxListView::getNumSelected(mxListView *this)
{
  mxListView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxListView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1032u, wParam: 0, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4780
// Name: public: char const __near * mxListView::getLabel(int,int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxListView::getLabel(mxListView *this, int item, int column)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  label_1[0] = 0;
  d_this = this->d_this;
  if ( d_this == nullptr )
    return label_1;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  lvItem.mask = 1;
  lvItem.iItem = item;
  lvItem.iSubItem = column;
  lvItem.pszText = label_1;
  lvItem.cchTextMax = 256;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvItem);
  return lvItem.pszText;
}

//------------------------------------------------------------------------------
// Address: 0x004C47F0
// Name: public: void __near * mxListView::getUserData(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxListView::getUserData(mxListView *this, int item, int column)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  lvItem.mask = 4;
  lvItem.iItem = item;
  lvItem.iSubItem = column;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvItem);
  return lvItem.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x004C4850
// Name: public: void mxListView::insertTextColumn(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::insertTextColumn(mxListView *this, int column, int width, char *label)
{
  mxListView_i *d_this; // esi
  tagLVCOLUMNA col; // [esp+4h] [ebp-2Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&col, value: 0, count: sizeof(col));
    col.pszText = label;
    col.mask = 46;
    col.iOrder = column;
    col.cchTextMax = 256;
    col.iSubItem = column;
    col.cx = width;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x101Bu, wParam: column, lParam: (LPARAM)&col);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C48B0
// Name: public: void mxListView::setDrawingEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setDrawingEnabled(mxListView *this, bool draw)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0xBu, wParam: draw, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C48E0
// Name: public: void mxListView::scrollToItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::scrollToItem(mxListView *this, WPARAM item)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1013u, wParam: item, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C4910
// Name: public: virtual mxListView::~mxListView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::~mxListView(mxListView *this)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  this->__vftable = (mxListView_vtbl *)&mxListView::`vftable';
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1008u, wParam: 0, lParam: 0);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C4950
// Name: public: int mxListView::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxListView::add(mxListView *this, char *item)
{
  mxListView_i *d_this; // edi
  LRESULT v5; // eax
  mxListView_i *v6; // ecx
  tagLVITEMA lvItem; // [esp+8h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  v5 = SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  v6 = this->d_this;
  lvItem.iItem = v5;
  lvItem.mask = 1;
  lvItem.pszText = item;
  lvItem.cchTextMax = 256;
  return SendMessageA(hWnd: v6->d_hwnd, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvItem);
}

//------------------------------------------------------------------------------
// Address: 0x004C49D0
// Name: public: int mxListView::getNextSelectedItem(int)const
// Source: json
//------------------------------------------------------------------------------
WPARAM __thiscall mxListView::getNextSelectedItem(mxListView *this, int startitem)
{
  mxListView_i *d_this; // eax
  mxListView_i *v5; // eax
  LRESULT v6; // edi
  WPARAM v7; // esi
  mxListView_i *v8; // eax

  d_this = this->d_this;
  if ( d_this == nullptr )
    return -1;
  if ( SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1032u, wParam: 0, lParam: 0) == 0 )
    return -1;
  v5 = this->d_this;
  if ( v5 != nullptr )
    v6 = SendMessageA(hWnd: v5->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  else
    v6 = 0;
  v7 = startitem + 1;
  if ( startitem + 1 >= v6 )
    return -1;
  while ( 1 )
  {
    v8 = this->d_this;
    if ( v8 != nullptr && (SendMessageA(hWnd: v8->d_hwnd, Msg: 0x102Cu, wParam: v7, lParam: 2) & 2) != 0 )
      break;
    if ( (int)++v7 >= v6 )
      return -1;
  }
  return v7;
}

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042A7B0
// Name: public: mxListView::mxListView(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxListView *__thiscall mxListView::mxListView(mxListView *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxListView_vtbl *)&mxListView::`vftable';
  if ( parent != nullptr )
  {
    this->d_this = (mxListView_i *)operator new(nSize: 4u);
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    this->d_this->d_hwnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SysListView32",
                             lpWindowName: &WindowName,
                             dwStyle: 0x50008009u,
                             X: x,
                             Y: y,
                             nWidth: w,
                             nHeight: h,
                             hWndParent: Handle,
                             hMenu: id,
                             hInstance: ModuleHandleA,
                             lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: this->d_this->d_hwnd);
    mxWidget::setType(this, type: 20);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A8A0
// Name: public: void mxListView::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::removeAll(mxListView *this)
{
  SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x1009u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042A8C0
// Name: public: void mxListView::setLabel(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setLabel(mxListView *this, int item, int column, char *label)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 1;
    lvItem.iSubItem = column;
    lvItem.pszText = label;
    lvItem.cchTextMax = 256;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A920
// Name: public: void mxListView::setLabel(int,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setLabel(mxListView *this, int item, int column, wchar_t *label)
{
  mxListView_i *d_this; // esi
  tagLVITEMW lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 1;
    lvItem.iSubItem = column;
    lvItem.pszText = label;
    lvItem.cchTextMax = 256;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x104Cu, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A980
// Name: public: void mxListView::setUserData(int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setUserData(mxListView *this, int item, int column, void *userData)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 4;
    lvItem.iSubItem = column;
    lvItem.lParam = (int)userData;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042A9E0
// Name: public: void mxListView::setSelected(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setSelected(mxListView *this, WPARAM item, bool b)
{
  mxListView_i *d_this; // eax
  tagLVITEMA _macro_lvi; // [esp+0h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    _macro_lvi.state = b ? 3 : 0;
    _macro_lvi.stateMask = 3;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x102Bu, wParam: item, lParam: (LPARAM)&_macro_lvi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AA20
// Name: public: int mxListView::getItemCount(void)const
// Source: json
//------------------------------------------------------------------------------
mxListView_i *__thiscall mxListView::getItemCount(mxListView *this)
{
  mxListView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxListView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AA40
// Name: public: int mxListView::getNumSelected(void)const
// Source: json
//------------------------------------------------------------------------------
mxListView_i *__thiscall mxListView::getNumSelected(mxListView *this)
{
  mxListView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxListView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1032u, wParam: 0, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AA60
// Name: public: char const __near * mxListView::getLabel(int,int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxListView::getLabel(mxListView *this, int item, int column)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  label_0[0] = 0;
  d_this = this->d_this;
  if ( d_this == nullptr )
    return label_0;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  lvItem.mask = 1;
  lvItem.iItem = item;
  lvItem.iSubItem = column;
  lvItem.pszText = label_0;
  lvItem.cchTextMax = 256;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvItem);
  return lvItem.pszText;
}

//------------------------------------------------------------------------------
// Address: 0x0042AAD0
// Name: public: void __near * mxListView::getUserData(int,int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxListView::getUserData(mxListView *this, int item, int column)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  lvItem.mask = 4;
  lvItem.iItem = item;
  lvItem.iSubItem = column;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)&lvItem);
  return lvItem.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x0042AB30
// Name: public: void mxListView::setImageList(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setImageList(mxListView *this, void *himagelist)
{
  SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x1003u, wParam: 1u, lParam: (LPARAM)himagelist);
}

//------------------------------------------------------------------------------
// Address: 0x0042AB50
// Name: public: void mxListView::setImage(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setImage(mxListView *this, int item, int column, int imagenormal)
{
  mxListView_i *d_this; // esi
  tagLVITEMA lvItem; // [esp+4h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
    lvItem.iItem = item;
    lvItem.mask = 2;
    lvItem.iSubItem = column;
    lvItem.iImage = imagenormal;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ABB0
// Name: public: void mxListView::insertTextColumn(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::insertTextColumn(mxListView *this, int column, int width, char *label)
{
  mxListView_i *d_this; // esi
  tagLVCOLUMNA col; // [esp+4h] [ebp-2Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    memset(dst: (unsigned __int8 *)&col, value: 0, count: sizeof(col));
    col.pszText = label;
    col.mask = 46;
    col.iOrder = column;
    col.cchTextMax = 256;
    col.iSubItem = column;
    col.cx = width;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x101Bu, wParam: column, lParam: (LPARAM)&col);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AC10
// Name: public: void mxListView::setDrawingEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::setDrawingEnabled(mxListView *this, bool draw)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0xBu, wParam: draw, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042AC40
// Name: public: void mxListView::scrollToItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::scrollToItem(mxListView *this, WPARAM item)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1013u, wParam: item, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0042AC70
// Name: public: virtual mxListView::~mxListView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxListView::~mxListView(mxListView *this)
{
  mxListView_i *d_this; // eax

  d_this = this->d_this;
  this->__vftable = (mxListView_vtbl *)&mxListView::`vftable';
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1008u, wParam: 0, lParam: 0);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042ACB0
// Name: public: int mxListView::add(char const __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall mxListView::add(mxListView *this, char *item)
{
  mxListView_i *d_this; // edi
  LRESULT v5; // eax
  mxListView_i *v6; // ecx
  tagLVITEMA lvItem; // [esp+8h] [ebp-3Ch] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr )
    return 0;
  memset(dst: (unsigned __int8 *)&lvItem, value: 0, count: sizeof(lvItem));
  v5 = SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  v6 = this->d_this;
  lvItem.iItem = v5;
  lvItem.mask = 1;
  lvItem.pszText = item;
  lvItem.cchTextMax = 256;
  return SendMessageA(hWnd: v6->d_hwnd, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&lvItem);
}

//------------------------------------------------------------------------------
// Address: 0x0042AD30
// Name: public: int mxListView::getNextSelectedItem(int)const
// Source: json
//------------------------------------------------------------------------------
WPARAM __thiscall mxListView::getNextSelectedItem(mxListView *this, int startitem)
{
  mxListView_i *d_this; // eax
  mxListView_i *v5; // eax
  LRESULT v6; // edi
  WPARAM v7; // esi
  mxListView_i *v8; // eax

  d_this = this->d_this;
  if ( d_this == nullptr )
    return -1;
  if ( SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1032u, wParam: 0, lParam: 0) == 0 )
    return -1;
  v5 = this->d_this;
  if ( v5 != nullptr )
    v6 = SendMessageA(hWnd: v5->d_hwnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  else
    v6 = 0;
  v7 = startitem + 1;
  if ( startitem + 1 >= v6 )
    return -1;
  while ( 1 )
  {
    v8 = this->d_this;
    if ( v8 != nullptr && (SendMessageA(hWnd: v8->d_hwnd, Msg: 0x102Cu, wParam: v7, lParam: 2) & 2) != 0 )
      break;
    if ( (int)++v7 >= v6 )
      return -1;
  }
  return v7;
}

} // namespace scenemanager
