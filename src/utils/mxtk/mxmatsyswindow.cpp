// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxmatsyswindow.cpp
// Functions: 4
// ============================================================

#include "utils\mxtk\mxmatsyswindow.h"

//------------------------------------------------------------------------------
// Address: 0x004C4040
// Name: public: virtual mxMatSysWindow::~mxMatSysWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMatSysWindow::~mxMatSysWindow(mxMatSysWindow *this)
{
  mxMatSysWindow_i *d_this; // eax
  HWND__ *Handle; // eax
  HDC hdc; // [esp-4h] [ebp-8h]

  d_this = this->d_this;
  this->__vftable = (mxMatSysWindow_vtbl *)&mxMatSysWindow::`vftable';
  if ( d_this->hdc != nullptr )
  {
    hdc = d_this->hdc;
    Handle = mxWidget::getHandle(this);
    ReleaseDC(hWnd: Handle, hDC: hdc);
  }
  free(pMem: this->d_this);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C4080
// Name: public: virtual int mxMatSysWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxMatSysWindow::handleEvent(mxWindow *this, mxEvent *__formal)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C4090
// Name: public: virtual void mxMatSysWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMatSysWindow::redraw(mxMatSysWindow *this)
{
  void (*d_drawFunc)(void); // eax

  d_drawFunc = this->d_drawFunc;
  if ( d_drawFunc != nullptr )
    d_drawFunc();
  else
    this->draw(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C40A0
// Name: public: mxMatSysWindow::mxMatSysWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxMatSysWindow *__thiscall mxMatSysWindow::mxMatSysWindow(
        mxMatSysWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  HWND__ *Handle; // eax
  HDC__ *DC; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label, style);
  this->__vftable = (mxMatSysWindow_vtbl *)&mxMatSysWindow::`vftable';
  this->d_this = (mxMatSysWindow_i *)operator new(nSize: 8u);
  Handle = mxWidget::getHandle(this);
  DC = GetDC(hWnd: Handle);
  this->d_this->hdc = DC;
  if ( DC != nullptr )
    this->d_drawFunc = nullptr;
  else
    ((void (__thiscall *)(mxMatSysWindow *, int))this->dtr_mxWidget)(a1: this, a2: 1);
  return this;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056C930
// Name: public: virtual int mxMatSysWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxMatSysWindow::handleEvent(mxWindow *this, mxEvent *__formal)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056F750
// Name: public: virtual mxMatSysWindow::~mxMatSysWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMatSysWindow::~mxMatSysWindow(mxMatSysWindow *this)
{
  mxMatSysWindow_i *d_this; // eax
  HWND Handle; // eax
  HDC hdc; // [esp-4h] [ebp-8h]

  d_this = this->d_this;
  this->__vftable = (mxMatSysWindow_vtbl *)&mxMatSysWindow::`vftable';
  if ( d_this->hdc != nullptr )
  {
    hdc = d_this->hdc;
    Handle = (HWND)mxWidget::getHandle(this);
    ReleaseDC(hWnd: Handle, hDC: hdc);
  }
  free(pMem: this->d_this);
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056F790
// Name: public: virtual void mxMatSysWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxMatSysWindow::redraw(mxMatSysWindow *this)
{
  void (*d_drawFunc)(void); // eax

  d_drawFunc = this->d_drawFunc;
  if ( d_drawFunc != nullptr )
    d_drawFunc();
  else
    this->draw(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056F7A0
// Name: public: mxMatSysWindow::mxMatSysWindow(class mxWindow __near *,int,int,int,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
mxMatSysWindow *__thiscall mxMatSysWindow::mxMatSysWindow(
        mxMatSysWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int style)
{
  HWND Handle; // eax
  HDC__ *DC; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label, style);
  this->__vftable = (mxMatSysWindow_vtbl *)&mxMatSysWindow::`vftable';
  this->d_this = (mxMatSysWindow_i *)operator new(nSize: 8u);
  Handle = (HWND)mxWidget::getHandle(this);
  DC = GetDC(hWnd: Handle);
  this->d_this->hdc = DC;
  if ( DC != nullptr )
    this->d_drawFunc = nullptr;
  else
    ((void (__thiscall *)(mxMatSysWindow *, int))this->dtr_mxWidget)(a1: this, a2: 1);
  return this;
}

} // namespace hlmv
