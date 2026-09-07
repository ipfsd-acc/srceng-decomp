// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxwindow.cpp
// Functions: 3
// ============================================================

#include "utils\mxtk\mxwindow.h"

//------------------------------------------------------------------------------
// Address: 0x004C1C00
// Name: public: mxWindow::mxWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWindow::mxWindow(
        mxWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  mxWindow_i *v10; // eax
  DWORD v11; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  mxWindow *result; // eax
  HWND__ *parentHandle; // [esp+14h] [ebp+8h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  v10 = (mxWindow_i *)operator new(nSize: 4u);
  this->d_this = v10;
  v10->d_uTimer = 0;
  v11 = 0;
  if ( style != 0 )
  {
    if ( style == 1 )
    {
      v11 = 0x80000000;
    }
    else if ( style == 2 || style == 3 )
    {
      v11 = 13107200;
    }
  }
  else
  {
    v11 = 13565952;
  }
  parentHandle = nullptr;
  if ( parent != nullptr )
  {
    parentHandle = mxWidget::getHandle(this: parent);
    v11 = 1342177280;
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "mx_class",
             lpWindowName: label,
             dwStyle: v11,
             X: x,
             Y: y,
             nWidth: w,
             nHeight: h,
             hWndParent: parentHandle,
             hMenu: nullptr,
             hInstance: ModuleHandleA,
             lpParam: nullptr);
  SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
  mxWidget::setHandle(this, handle: Window);
  mxWidget::setType(this, type: 19);
  mxWidget::setParent(this, parentWindow: parent);
  result = this;
  if ( parent == nullptr && g_mainWindow == nullptr )
    g_mainWindow = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1D00
// Name: public: virtual mxWindow::~mxWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::~mxWindow(mxWindow *this)
{
  HWND__ *Handle; // eax

  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  Handle = mxWidget::getHandle(this);
  SetWindowLongA(hWnd: Handle, nIndex: -21, dwNewLong: 0);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C1D30
// Name: public: void mxWindow::setMenuBar(class mxMenuBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::setMenuBar(mxWindow *this, mxMenuBar *menuBar)
{
  HWND__ *v3; // eax
  HWND__ *Handle; // [esp-4h] [ebp-8h]

  Handle = mxWidget::getHandle(this: menuBar);
  v3 = mxWidget::getHandle(this);
  SetMenu(hWnd: v3, hMenu: (HMENU)Handle);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056C800
// Name: public: mxWindow::mxWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWindow::mxWindow(
        mxWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  mxWindow_i *v10; // eax
  DWORD v11; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  mxWindow *result; // eax
  HWND parentHandle; // [esp+14h] [ebp+8h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  v10 = (mxWindow_i *)operator new(nSize: 4u);
  this->d_this = v10;
  v10->d_uTimer = 0;
  v11 = 0;
  if ( style != 0 )
  {
    if ( style == 1 )
    {
      v11 = 0x80000000;
    }
    else if ( style == 2 || style == 3 )
    {
      v11 = 13107200;
    }
  }
  else
  {
    v11 = 13565952;
  }
  parentHandle = nullptr;
  if ( parent != nullptr )
  {
    parentHandle = (HWND)mxWidget::getHandle(this: parent);
    v11 = 1342177280;
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "mx_class",
             lpWindowName: label,
             dwStyle: v11,
             X: x,
             Y: y,
             nWidth: w,
             nHeight: h,
             hWndParent: parentHandle,
             hMenu: nullptr,
             hInstance: ModuleHandleA,
             lpParam: nullptr);
  SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
  mxWidget::setHandle(this, handle: Window);
  mxWidget::setType(this, type: 19);
  mxWidget::setParent(this, parentWindow: parent);
  result = this;
  if ( parent == nullptr && g_mainWindow == nullptr )
    g_mainWindow = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056C900
// Name: public: virtual mxWindow::~mxWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::~mxWindow(mxWindow *this)
{
  HWND Handle; // eax

  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  Handle = (HWND)mxWidget::getHandle(this);
  SetWindowLongA(hWnd: Handle, nIndex: -21, dwNewLong: 0);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056C940
// Name: public: void mxWindow::setTimer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::setTimer(mxWindow *this, int milliSeconds)
{
  HWND Handle; // eax
  HWND v4; // eax
  UINT_PTR v5; // [esp-Ch] [ebp-10h]
  UINT_PTR d_uTimer; // [esp-4h] [ebp-8h]

  if ( this->d_this->d_uTimer != 0 )
  {
    d_uTimer = this->d_this->d_uTimer;
    Handle = (HWND)mxWidget::getHandle(this);
    KillTimer(hWnd: Handle, uIDEvent: d_uTimer);
    this->d_this->d_uTimer = 0;
  }
  if ( milliSeconds > 0 )
  {
    this->d_this->d_uTimer = 21001;
    v5 = this->d_this->d_uTimer;
    v4 = (HWND)mxWidget::getHandle(this);
    this->d_this->d_uTimer = SetTimer(hWnd: v4, nIDEvent: v5, uElapse: milliSeconds, lpTimerFunc: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056C9A0
// Name: public: void mxWindow::setMenuBar(class mxMenuBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::setMenuBar(mxWindow *this, mxMenuBar *menuBar)
{
  HWND v3; // eax
  HMENU Handle; // [esp-4h] [ebp-8h]

  Handle = (HMENU)mxWidget::getHandle(this: menuBar);
  v3 = (HWND)mxWidget::getHandle(this);
  SetMenu(hWnd: v3, hMenu: Handle);
}

} // namespace hlmv

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x0042B160
// Name: public: mxWindow::mxWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxWindow *__thiscall mxWindow::mxWindow(
        mxWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  mxWindow_i *v10; // eax
  DWORD v11; // ebx
  HMODULE ModuleHandleA; // eax
  HWND Window; // ebx
  mxWindow *result; // eax
  HWND__ *parentHandle; // [esp+14h] [ebp+8h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  v10 = (mxWindow_i *)operator new(nSize: 4u);
  this->d_this = v10;
  v10->d_uTimer = 0;
  v11 = 0;
  if ( style != 0 )
  {
    if ( style == 1 )
    {
      v11 = 0x80000000;
    }
    else if ( style == 2 || style == 3 )
    {
      v11 = 13107200;
    }
  }
  else
  {
    v11 = 13565952;
  }
  parentHandle = nullptr;
  if ( parent != nullptr )
  {
    parentHandle = mxWidget::getHandle(this: parent);
    v11 = 1342177280;
  }
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "mx_class",
             lpWindowName: label,
             dwStyle: v11,
             X: x,
             Y: y,
             nWidth: w,
             nHeight: h,
             hWndParent: parentHandle,
             hMenu: nullptr,
             hInstance: ModuleHandleA,
             lpParam: nullptr);
  SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
  mxWidget::setHandle(this, handle: Window);
  mxWidget::setType(this, type: 19);
  mxWidget::setParent(this, parentWindow: parent);
  result = this;
  if ( parent == nullptr && g_mainWindow == nullptr )
    g_mainWindow = this;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B260
// Name: public: virtual mxWindow::~mxWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::~mxWindow(mxWindow *this)
{
  HWND__ *Handle; // eax

  this->__vftable = (mxWindow_vtbl *)&mxWindow::`vftable';
  Handle = mxWidget::getHandle(this);
  SetWindowLongA(hWnd: Handle, nIndex: -21, dwNewLong: 0);
  free(pMem: this->d_this);
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B290
// Name: public: virtual int mxWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxWindow::handleEvent(mxWindow *this, mxEvent *__formal)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B2B0
// Name: public: void mxWindow::setMenuBar(class mxMenuBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxWindow::setMenuBar(mxWindow *this, mxMenuBar *menuBar)
{
  HWND__ *v3; // eax
  HWND__ *Handle; // [esp-4h] [ebp-8h]

  Handle = mxWidget::getHandle(this: menuBar);
  v3 = mxWidget::getHandle(this);
  SetMenu(hWnd: v3, hMenu: (HMENU)Handle);
}

} // namespace scenemanager
