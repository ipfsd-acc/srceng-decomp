// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxtreeview.cpp
// Functions: 11
// ============================================================

#include "utils\mxtk\mxtreeview.h"

//------------------------------------------------------------------------------
// Address: 0x004C4AC0
// Name: public: mxTreeView::mxTreeView(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxTreeView *__thiscall mxTreeView::mxTreeView(mxTreeView *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxTreeView_vtbl *)&mxTreeView::`vftable';
  if ( parent != nullptr )
  {
    this->d_this = (mxTreeView_i *)operator new(nSize: 4u);
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    this->d_this->d_hwnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SysTreeView32",
                             lpWindowName: defaultValue,
                             dwStyle: 0x50000027u,
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
    mxWidget::setType(this, type: 18);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C4BB0
// Name: public: void __near * __near * mxTreeView::add(void __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxTreeView_i *__thiscall mxTreeView::add(mxTreeView *this, void **parent, char *item)
{
  mxTreeView_i *result; // eax
  int v4; // ecx
  tagTVINSERTSTRUCTA tvInsert; // [esp+0h] [ebp-6Ch] BYREF
  tagTVITEMA tvItem; // [esp+44h] [ebp-28h]

  result = this->d_this;
  if ( result != nullptr )
  {
    tvItem.pszText = item;
    v4 = (int)parent;
    tvItem.mask = 1;
    tvItem.cchTextMax = 256;
    if ( parent == nullptr )
      v4 = -65536;
    tvInsert.item = tvItem;
    tvInsert.hParent = (_TREEITEM *)v4;
    tvInsert.hInsertAfter = (_TREEITEM *)-65534;
    return (mxTreeView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1100u, wParam: 0, lParam: (LPARAM)&tvInsert);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4C40
// Name: public: void mxTreeView::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::removeAll(mxTreeView *this)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
}

//------------------------------------------------------------------------------
// Address: 0x004C4C60
// Name: public: void mxTreeView::setUserData(void __near * __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setUserData(mxTreeView *this, void **item, void *userData)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
  {
    tvItem.hItem = (_TREEITEM *)item;
    tvItem.mask = 20;
    tvItem.lParam = (int)userData;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&tvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C4CA0
// Name: public: void mxTreeView::setOpen(void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setOpen(mxTreeView *this, void **item, bool b)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1102u, wParam: b + 1, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x004C4CD0
// Name: public: void __near * __near * mxTreeView::getFirstChild(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void **__thiscall mxTreeView::getFirstChild(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // ecx
  LPARAM v4; // eax

  d_this = this->d_this;
  if ( d_this == nullptr )
    return nullptr;
  v4 = (LPARAM)item;
  if ( item == nullptr )
    v4 = -65536;
  return (void **)SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Au, wParam: 4u, lParam: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C4D10
// Name: public: void __near * __near * mxTreeView::getNextChild(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void **__thiscall mxTreeView::getNextChild(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
    return (void **)SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)item);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004C4D40
// Name: public: void __near * __near * mxTreeView::getSelectedItem(void)const
// Source: json
//------------------------------------------------------------------------------
mxTreeView_i *__thiscall mxTreeView::getSelectedItem(mxTreeView *this)
{
  mxTreeView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxTreeView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4D60
// Name: public: char const __near * mxTreeView::getLabel(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxTreeView::getLabel(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  label_2[0] = 0;
  d_this = this->d_this;
  if ( d_this == nullptr || item == nullptr )
    return label_2;
  tvItem.hItem = (_TREEITEM *)item;
  tvItem.mask = 17;
  tvItem.pszText = label_2;
  tvItem.cchTextMax = 256;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&tvItem);
  return tvItem.pszText;
}

//------------------------------------------------------------------------------
// Address: 0x004C4DC0
// Name: public: void __near * mxTreeView::getUserData(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxTreeView::getUserData(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr || item == nullptr )
    return 0;
  tvItem.hItem = (_TREEITEM *)item;
  tvItem.mask = 20;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&tvItem);
  return tvItem.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x004C4E10
// Name: public: virtual mxTreeView::~mxTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::~mxTreeView(mxTreeView *this)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  this->__vftable = (mxTreeView_vtbl *)&mxTreeView::`vftable';
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00428F50
// Name: public: mxTreeView::mxTreeView(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxTreeView *__thiscall mxTreeView::mxTreeView(mxTreeView *this, mxWindow *parent, int x, int y, int w, int h, HMENU id)
{
  HWND__ *Handle; // ebx
  HMODULE ModuleHandleA; // eax
  HGDIOBJ StockObject; // eax

  mxWidget::mxWidget(this, parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxTreeView_vtbl *)&mxTreeView::`vftable';
  if ( parent != nullptr )
  {
    this->d_this = (mxTreeView_i *)operator new(nSize: 4u);
    Handle = mxWidget::getHandle(this: parent);
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    this->d_this->d_hwnd = CreateWindowExA(
                             dwExStyle: 0x200u,
                             lpClassName: "SysTreeView32",
                             lpWindowName: &WindowName,
                             dwStyle: 0x50000027u,
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
    mxWidget::setType(this, type: 18);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429040
// Name: public: void __near * __near * mxTreeView::add(void __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxTreeView_i *__thiscall mxTreeView::add(mxTreeView *this, void **parent, char *item)
{
  mxTreeView_i *result; // eax
  int v4; // ecx
  tagTVINSERTSTRUCTA tvInsert; // [esp+0h] [ebp-6Ch] BYREF
  tagTVITEMA tvItem; // [esp+44h] [ebp-28h]

  result = this->d_this;
  if ( result != nullptr )
  {
    tvItem.pszText = item;
    v4 = (int)parent;
    tvItem.mask = 1;
    tvItem.cchTextMax = 256;
    if ( parent == nullptr )
      v4 = -65536;
    tvInsert.item = tvItem;
    tvInsert.hParent = (_TREEITEM *)v4;
    tvInsert.hInsertAfter = (_TREEITEM *)-65534;
    return (mxTreeView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x1100u, wParam: 0, lParam: (LPARAM)&tvInsert);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004290D0
// Name: public: void mxTreeView::remove(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::remove(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    if ( item != nullptr )
      SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: (LPARAM)item);
    else
      SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429110
// Name: public: void mxTreeView::removeAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::removeAll(mxTreeView *this)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
}

//------------------------------------------------------------------------------
// Address: 0x00429130
// Name: public: void mxTreeView::setLabel(void __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setLabel(mxTreeView *this, void **item, char *label)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
  {
    tvItem.hItem = (_TREEITEM *)item;
    tvItem.mask = 17;
    tvItem.pszText = label;
    tvItem.cchTextMax = 256;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&tvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429180
// Name: public: void mxTreeView::setUserData(void __near * __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setUserData(mxTreeView *this, void **item, void *userData)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
  {
    tvItem.hItem = (_TREEITEM *)item;
    tvItem.mask = 20;
    tvItem.lParam = (int)userData;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&tvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004291C0
// Name: public: void mxTreeView::setOpen(void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setOpen(mxTreeView *this, void **item, bool b)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1102u, wParam: b + 1, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x004291F0
// Name: public: void __near * __near * mxTreeView::getFirstChild(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void **__thiscall mxTreeView::getFirstChild(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // ecx
  LPARAM v4; // eax

  d_this = this->d_this;
  if ( d_this == nullptr )
    return nullptr;
  v4 = (LPARAM)item;
  if ( item == nullptr )
    v4 = -65536;
  return (void **)SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Au, wParam: 4u, lParam: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00429230
// Name: public: void __near * __near * mxTreeView::getNextChild(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
void **__thiscall mxTreeView::getNextChild(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
    return (void **)SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Au, wParam: 1u, lParam: (LPARAM)item);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00429260
// Name: public: void __near * __near * mxTreeView::getSelectedItem(void)const
// Source: json
//------------------------------------------------------------------------------
mxTreeView_i *__thiscall mxTreeView::getSelectedItem(mxTreeView *this)
{
  mxTreeView_i *result; // eax

  result = this->d_this;
  if ( result != nullptr )
    return (mxTreeView_i *)SendMessageA(hWnd: result->d_hwnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429280
// Name: public: char const __near * mxTreeView::getLabel(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxTreeView::getLabel(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  label[0] = 0;
  d_this = this->d_this;
  if ( d_this == nullptr || item == nullptr )
    return label;
  tvItem.hItem = (_TREEITEM *)item;
  tvItem.mask = 17;
  tvItem.pszText = label;
  tvItem.cchTextMax = 256;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&tvItem);
  return tvItem.pszText;
}

//------------------------------------------------------------------------------
// Address: 0x004292E0
// Name: public: void __near * mxTreeView::getUserData(void __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxTreeView::getUserData(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this == nullptr || item == nullptr )
    return 0;
  tvItem.hItem = (_TREEITEM *)item;
  tvItem.mask = 20;
  SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)&tvItem);
  return tvItem.lParam;
}

//------------------------------------------------------------------------------
// Address: 0x00429330
// Name: public: void mxTreeView::setImageList(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setImageList(mxTreeView *this, void *himagelist)
{
  SendMessageA(hWnd: this->d_this->d_hwnd, Msg: 0x1109u, wParam: 0, lParam: (LPARAM)himagelist);
}

//------------------------------------------------------------------------------
// Address: 0x00429350
// Name: public: void mxTreeView::setImages(void __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::setImages(mxTreeView *this, void **item, int imagenormal, int imageselected)
{
  mxTreeView_i *d_this; // eax
  tagTVITEMA tvItem; // [esp+0h] [ebp-28h] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr && item != nullptr )
  {
    tvItem.hItem = (_TREEITEM *)item;
    tvItem.iImage = imagenormal;
    tvItem.mask = 50;
    tvItem.iSelectedImage = imageselected;
    tvItem.stateMask = 61440;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&tvItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004293A0
// Name: public: void mxTreeView::sortTree(void __near * __near *,bool,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::sortTree(
        mxTreeView *this,
        void **parent,
        bool recurse,
        int (__stdcall *func)(int, int, int),
        int parameter)
{
  mxTreeView_i *d_this; // eax
  tagTVSORTCB cb; // [esp+0h] [ebp-Ch] BYREF

  d_this = this->d_this;
  if ( d_this != nullptr )
  {
    cb.hParent = (_TREEITEM *)parent;
    cb.lParam = parameter;
    cb.lpfnCompare = func;
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1115u, wParam: recurse, lParam: (LPARAM)&cb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004293F0
// Name: public: void mxTreeView::scrollTo(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::scrollTo(mxTreeView *this, void **item)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1114u, wParam: 0, lParam: (LPARAM)item);
}

//------------------------------------------------------------------------------
// Address: 0x00429420
// Name: public: virtual mxTreeView::~mxTreeView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxTreeView::~mxTreeView(mxTreeView *this)
{
  mxTreeView_i *d_this; // eax

  d_this = this->d_this;
  this->__vftable = (mxTreeView_vtbl *)&mxTreeView::`vftable';
  if ( d_this != nullptr )
    SendMessageA(hWnd: d_this->d_hwnd, Msg: 0x1101u, wParam: 0, lParam: -65536);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

} // namespace scenemanager
