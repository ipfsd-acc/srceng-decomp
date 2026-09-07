// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxwidget.cpp
// Functions: 22
// ============================================================

#include "utils\mxtk\mxwidget.h"

//------------------------------------------------------------------------------
// Address: 0x004C12D0
// Name: public: virtual mxWidget::~mxWidget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::~mxWidget(mxWidget *this)
{
  mxWidget_i *d_this; // ecx
  int d_type; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  mx_removeWidget(widget: this);
  d_this = this->d_this;
  d_type = d_this->d_type;
  if ( d_type == 9 || d_type == 10 || d_type == 11 )
  {
    DestroyMenu(hMenu: (HMENU)d_this->d_hwnd);
    free(pMem: this->d_this);
  }
  else
  {
    DestroyWindow(hWnd: d_this->d_hwnd);
    free(pMem: this->d_this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1330
// Name: protected: void mxWidget::setHandle(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setHandle(mxWidget *this, HWND__ *handle)
{
  this->d_this->d_hwnd = handle;
}

//------------------------------------------------------------------------------
// Address: 0x004C1340
// Name: protected: void mxWidget::setType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setType(mxWidget *this, int type)
{
  this->d_this->d_type = type;
}

//------------------------------------------------------------------------------
// Address: 0x004C1350
// Name: protected: void mxWidget::setParent(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setParent(mxWidget *this, mxWindow *parentWindow)
{
  this->d_this->d_parent_p = parentWindow;
}

//------------------------------------------------------------------------------
// Address: 0x004C1360
// Name: public: void mxWidget::setBounds(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setBounds(mxWidget *this, int x, int y, int w, int h)
{
  bool v6; // zf
  int v7; // eax
  char str[128]; // [esp+4h] [ebp-80h] BYREF

  GetClassNameA(hWnd: this->d_this->d_hwnd, lpClassName: str, nMaxCount: 128);
  v6 = strcmp(str, "COMBOBOX") == 0;
  v7 = h;
  if ( v6 )
    v7 = h + 100;
  MoveWindow(hWnd: this->d_this->d_hwnd, X: x, Y: y, nWidth: w, nHeight: v7, bRepaint: true);
  if ( strcmp(str, "SysTabControl32") == 0 )
    mxTab_resizeChild(hwnd: this->d_this->d_hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x004C1430
// Name: public: void mxWidget::setLabel(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void mxWidget::setLabel(mxWidget *this, const char *format, ...)
{
  HWND__ *v2; // eax
  HWND__ *d_hwnd; // eax
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, format);
  if ( format != nullptr )
  {
    vsprintf(string: string, format, ap);
    d_hwnd = this->d_this->d_hwnd;
    if ( d_hwnd != nullptr )
      SetWindowTextA(hWnd: d_hwnd, lpString: string);
  }
  else
  {
    v2 = this->d_this->d_hwnd;
    if ( v2 != nullptr )
      SetWindowTextA(hWnd: v2, lpString: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C1480
// Name: public: void mxWidget::setVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setVisible(mxWidget *this, bool b)
{
  if ( b )
    SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  else
    ShowWindow(hWnd: this->d_this->d_hwnd, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C14C0
// Name: public: void mxWidget::setEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setEnabled(mxWidget *this, bool b)
{
  EnableWindow(hWnd: this->d_this->d_hwnd, bEnable: b);
}

//------------------------------------------------------------------------------
// Address: 0x004C14E0
// Name: public: void mxWidget::setId(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setId(mxWidget *this, LONG id)
{
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: id);
}

//------------------------------------------------------------------------------
// Address: 0x004C1500
// Name: public: void __near * mxWidget::getHandle(void)const
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall mxWidget::getHandle(mxWidget *this)
{
  return this->d_this->d_hwnd;
}

//------------------------------------------------------------------------------
// Address: 0x004C1510
// Name: public: class mxWindow __near * mxWidget::getParent(void)const
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWidget::getParent(mxWidget *this)
{
  return this->d_this->d_parent_p;
}

//------------------------------------------------------------------------------
// Address: 0x004C1520
// Name: public: int mxWidget::x(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::x(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x004C1540
// Name: public: int mxWidget::y(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::y(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x004C1560
// Name: public: int mxWidget::w(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x004C1590
// Name: public: int mxWidget::h(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x004C15C0
// Name: public: int mxWidget::w2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x004C15F0
// Name: public: int mxWidget::h2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x004C1620
// Name: public: char const __near * mxWidget::getLabel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxWidget::getLabel(mxWidget *this)
{
  GetWindowTextA(hWnd: this->d_this->d_hwnd, lpString: label_0, nMaxCount: 256);
  return label_0;
}

//------------------------------------------------------------------------------
// Address: 0x004C1640
// Name: public: bool mxWidget::isVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall mxWidget::isVisible(mxWidget *this)
{
  return IsWindowVisible(hWnd: this->d_this->d_hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x004C1660
// Name: public: int mxWidget::getId(void)const
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall mxWidget::getId(mxWidget *this)
{
  return GetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12);
}

//------------------------------------------------------------------------------
// Address: 0x004C1670
// Name: public: mxWidget::mxWidget(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxWidget *__thiscall mxWidget::mxWidget(
        mxWidget *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  mxWidget_i *v8; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  v8 = (mxWidget_i *)operator new(nSize: 0x10u);
  this->d_this = v8;
  v8->d_hwnd = nullptr;
  this->d_this->d_type = -1;
  this->d_this->d_parent_p = parent;
  mxWidget::setBounds(this, x, y, w, h);
  SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  EnableWindow(hWnd: this->d_this->d_hwnd, bEnable: true);
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: 0);
  this->d_this->d_userData = nullptr;
  mxWidget::setLabel(this, format: label);
  mx_addWidget(widget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C9E40
// Name: public: int mxWidget::getType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall mxWidget::getType(ConVar *this)
{
  return this->m_pNext->ConCommandBase::m_pszName;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056CA20
// Name: public: virtual mxWidget::~mxWidget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::~mxWidget(mxWidget *this)
{
  mxWidget_i *d_this; // ecx
  int d_type; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  mx_removeWidget(widget: this);
  d_this = this->d_this;
  d_type = d_this->d_type;
  if ( d_type == 9 || d_type == 10 || d_type == 11 )
  {
    DestroyMenu(hMenu: (HMENU)d_this->d_hwnd);
    free(pMem: this->d_this);
  }
  else
  {
    DestroyWindow(hWnd: d_this->d_hwnd);
    free(pMem: this->d_this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056CA80
// Name: protected: void mxWidget::setHandle(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setHandle(mxWidget *this, HWND__ *handle)
{
  this->d_this->d_hwnd = handle;
}

//------------------------------------------------------------------------------
// Address: 0x0056CA90
// Name: protected: void mxWidget::setType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setType(mxWidget *this, int type)
{
  this->d_this->d_type = type;
}

//------------------------------------------------------------------------------
// Address: 0x0056CAA0
// Name: protected: void mxWidget::setParent(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setParent(mxWidget *this, mxWindow *parentWindow)
{
  this->d_this->d_parent_p = parentWindow;
}

//------------------------------------------------------------------------------
// Address: 0x0056CAB0
// Name: public: void mxWidget::setBounds(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setBounds(mxWidget *this, int x, int y, int w, int h)
{
  bool v6; // zf
  int v7; // eax
  char str[128]; // [esp+4h] [ebp-80h] BYREF

  GetClassNameA(hWnd: this->d_this->d_hwnd, lpClassName: str, nMaxCount: 128);
  v6 = strcmp(str, "COMBOBOX") == 0;
  v7 = h;
  if ( v6 )
    v7 = h + 100;
  MoveWindow(hWnd: this->d_this->d_hwnd, X: x, Y: y, nWidth: w, nHeight: v7, bRepaint: true);
  if ( strcmp(str, "SysTabControl32") == 0 )
    mxTab_resizeChild(hwnd: this->d_this->d_hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x0056CB80
// Name: public: void mxWidget::setLabel(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void mxWidget::setLabel(mxWidget *this, const char *format, ...)
{
  HWND__ *v2; // eax
  HWND__ *d_hwnd; // eax
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, format);
  if ( format != nullptr )
  {
    vsprintf(string: string, format, ap);
    d_hwnd = this->d_this->d_hwnd;
    if ( d_hwnd != nullptr )
      SetWindowTextA(hWnd: d_hwnd, lpString: string);
  }
  else
  {
    v2 = this->d_this->d_hwnd;
    if ( v2 != nullptr )
      SetWindowTextA(hWnd: v2, lpString: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056CBD0
// Name: public: void mxWidget::setVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setVisible(mxWidget *this, bool b)
{
  if ( b )
    SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  else
    ShowWindow(hWnd: this->d_this->d_hwnd, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC10
// Name: public: void mxWidget::setEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setEnabled(mxWidget *this, bool b)
{
  EnableWindow(hWnd: this->d_this->d_hwnd, bEnable: b);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC30
// Name: public: void mxWidget::setId(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setId(mxWidget *this, LONG id)
{
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: id);
}

//------------------------------------------------------------------------------
// Address: 0x0056CC50
// Name: public: void __near * mxWidget::getHandle(void)const
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall mxWidget::getHandle(mxWidget *this)
{
  return this->d_this->d_hwnd;
}

//------------------------------------------------------------------------------
// Address: 0x0056CC60
// Name: public: class mxWindow __near * mxWidget::getParent(void)const
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWidget::getParent(mxWidget *this)
{
  return this->d_this->d_parent_p;
}

//------------------------------------------------------------------------------
// Address: 0x0056CC70
// Name: public: int mxWidget::x(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::x(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x0056CC90
// Name: public: int mxWidget::y(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::y(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x0056CCB0
// Name: public: int mxWidget::w(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x0056CCE0
// Name: public: int mxWidget::h(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x0056CD10
// Name: public: int mxWidget::w2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x0056CD40
// Name: public: int mxWidget::h2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x0056CD70
// Name: public: char const __near * mxWidget::getLabel(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall mxWidget::getLabel(mxWidget *this)
{
  GetWindowTextA(hWnd: this->d_this->d_hwnd, lpString: label, nMaxCount: 256);
  return label;
}

//------------------------------------------------------------------------------
// Address: 0x0056CD90
// Name: public: bool mxWidget::isEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall mxWidget::isEnabled(mxWidget *this)
{
  return IsWindowEnabled(hWnd: this->d_this->d_hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x0056CDB0
// Name: public: int mxWidget::getId(void)const
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall mxWidget::getId(mxWidget *this)
{
  return GetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12);
}

//------------------------------------------------------------------------------
// Address: 0x0056CDC0
// Name: public: mxWidget::mxWidget(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxWidget *__thiscall mxWidget::mxWidget(
        mxWidget *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  mxWidget_i *v8; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  v8 = (mxWidget_i *)operator new(nSize: 0x10u);
  this->d_this = v8;
  v8->d_hwnd = nullptr;
  this->d_this->d_type = -1;
  this->d_this->d_parent_p = parent;
  mxWidget::setBounds(this, x, y, w, h);
  SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  EnableWindow(hWnd: this->d_this->d_hwnd, bEnable: true);
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: 0);
  this->d_this->d_userData = nullptr;
  mxWidget::setLabel(this, format: label);
  mx_addWidget(widget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00577020
// Name: public: int mxWidget::getType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall mxWidget::getType(ConVar *this)
{
  return this->m_pNext->ConCommandBase::m_pszName;
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00428B30
// Name: public: virtual mxWidget::~mxWidget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::~mxWidget(mxWidget *this)
{
  mxWidget_i *d_this; // ecx
  int d_type; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  mx_removeWidget(widget: this);
  d_this = this->d_this;
  d_type = d_this->d_type;
  if ( d_type == 9 || d_type == 10 || d_type == 11 )
  {
    DestroyMenu(hMenu: (HMENU)d_this->d_hwnd);
    free(pMem: this->d_this);
  }
  else
  {
    DestroyWindow(hWnd: d_this->d_hwnd);
    free(pMem: this->d_this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428B90
// Name: protected: void mxWidget::setHandle(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setHandle(mxWidget *this, HWND__ *handle)
{
  this->d_this->d_hwnd = handle;
}

//------------------------------------------------------------------------------
// Address: 0x00428BA0
// Name: protected: void mxWidget::setType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setType(mxWidget *this, int type)
{
  this->d_this->d_type = type;
}

//------------------------------------------------------------------------------
// Address: 0x00428BB0
// Name: protected: void mxWidget::setParent(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setParent(mxWidget *this, mxWindow *parentWindow)
{
  this->d_this->d_parent_p = parentWindow;
}

//------------------------------------------------------------------------------
// Address: 0x00428BC0
// Name: public: void mxWidget::setBounds(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setBounds(mxWidget *this, int x, int y, int w, int h)
{
  bool v6; // zf
  int v7; // eax
  char str[128]; // [esp+4h] [ebp-80h] BYREF

  GetClassNameA(hWnd: this->d_this->d_hwnd, lpClassName: str, nMaxCount: 128);
  v6 = strcmp(str, "COMBOBOX") == 0;
  v7 = h;
  if ( v6 )
    v7 = h + 100;
  MoveWindow(hWnd: this->d_this->d_hwnd, X: x, Y: y, nWidth: w, nHeight: v7, bRepaint: true);
  if ( strcmp(str, "SysTabControl32") == 0 )
    mxTab_resizeChild(hwnd: this->d_this->d_hwnd);
}

//------------------------------------------------------------------------------
// Address: 0x00428C90
// Name: public: void mxWidget::setLabel(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void mxWidget::setLabel(mxWidget *this, const char *format, ...)
{
  HWND__ *v2; // eax
  HWND__ *d_hwnd; // eax
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, format);
  if ( format != nullptr )
  {
    vsprintf(string: string, format, ap);
    d_hwnd = this->d_this->d_hwnd;
    if ( d_hwnd != nullptr )
      SetWindowTextA(hWnd: d_hwnd, lpString: string);
  }
  else
  {
    v2 = this->d_this->d_hwnd;
    if ( v2 != nullptr )
      SetWindowTextA(hWnd: v2, lpString: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428CE0
// Name: public: void mxWidget::setVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setVisible(mxWidget *this, bool b)
{
  if ( b )
    SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  else
    ShowWindow(hWnd: this->d_this->d_hwnd, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00428D20
// Name: public: void mxWidget::setId(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWidget::setId(mxWidget *this, LONG id)
{
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: id);
}

//------------------------------------------------------------------------------
// Address: 0x00428D40
// Name: public: void __near * mxWidget::getHandle(void)const
// Source: json
//------------------------------------------------------------------------------
HWND__ *__thiscall mxWidget::getHandle(mxWidget *this)
{
  return this->d_this->d_hwnd;
}

//------------------------------------------------------------------------------
// Address: 0x00428D50
// Name: public: class mxWindow __near * mxWidget::getParent(void)const
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWidget::getParent(mxWidget *this)
{
  return this->d_this->d_parent_p;
}

//------------------------------------------------------------------------------
// Address: 0x00428D60
// Name: public: int mxWidget::x(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::x(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x00428D80
// Name: public: int mxWidget::y(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::y(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x00428DA0
// Name: public: int mxWidget::w(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x00428DD0
// Name: public: int mxWidget::h(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetWindowRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x00428E00
// Name: public: int mxWidget::w2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::w2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.right - rc.left;
}

//------------------------------------------------------------------------------
// Address: 0x00428E30
// Name: public: int mxWidget::h2(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWidget::h2(mxWidget *this)
{
  tagRECT rc; // [esp+0h] [ebp-10h] BYREF

  GetClientRect(hWnd: this->d_this->d_hwnd, lpRect: &rc);
  return rc.bottom - rc.top;
}

//------------------------------------------------------------------------------
// Address: 0x00428E60
// Name: public: int mxWidget::getId(void)const
// Source: json
//------------------------------------------------------------------------------
LONG __thiscall mxWidget::getId(mxWidget *this)
{
  return GetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12);
}

//------------------------------------------------------------------------------
// Address: 0x00428E70
// Name: public: mxWidget::mxWidget(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxWidget *__thiscall mxWidget::mxWidget(
        mxWidget *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  mxWidget_i *v8; // eax

  this->__vftable = (mxWidget_vtbl *)&mxWidget::`vftable';
  v8 = (mxWidget_i *)operator new(nSize: 0x10u);
  this->d_this = v8;
  v8->d_hwnd = nullptr;
  this->d_this->d_type = -1;
  this->d_this->d_parent_p = parent;
  mxWidget::setBounds(this, x, y, w, h);
  SetWindowPos(hWnd: this->d_this->d_hwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
  EnableWindow(hWnd: this->d_this->d_hwnd, bEnable: true);
  SetWindowLongA(hWnd: this->d_this->d_hwnd, nIndex: -12, dwNewLong: 0);
  this->d_this->d_userData = nullptr;
  mxWidget::setLabel(this, format: label);
  mx_addWidget(widget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042FDA0
// Name: public: int mxWidget::getType(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall mxWidget::getType(ConVar *this)
{
  return this->m_pNext->ConCommandBase::m_pszName;
}

} // namespace scenemanager
