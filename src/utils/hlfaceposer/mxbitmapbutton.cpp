// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxbitmapbutton.cpp
// Functions: 4
// ============================================================

#include "utils\hlfaceposer\mxbitmapbutton.h"

//------------------------------------------------------------------------------
// Address: 0x00464EF0
// Name: public: virtual void mxBitmapButton::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxBitmapButton::redraw(mxBitmapButton *this)
{
  HWND Handle; // esi
  HDC DC; // ebx
  int v4; // eax
  int v5; // [esp-Ch] [ebp-24h]
  tagRECT rc; // [esp+8h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  if ( Handle != nullptr && this->m_bmImage.valid )
  {
    GetClientRect(hWnd: Handle, lpRect: &rc);
    DC = GetDC(hWnd: Handle);
    v5 = mxWidget::h(this);
    v4 = mxWidget::w(this);
    DrawBitmapToDC(hdc: DC, x: 0, y: 0, w: v4, h: v5, bitmap: &this->m_bmImage);
    ReleaseDC(hWnd: Handle, hDC: DC);
    ValidateRect(hWnd: Handle, lpRect: &rc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464F60
// Name: public: virtual int mxBitmapButton::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxBitmapButton::handleEvent(mxBitmapButton *this, mxEvent *event)
{
  mxWindow *Parent; // eax
  HWND Handle; // edi
  WPARAM Id; // ebx
  void *v6; // eax

  if ( event->event != 6 || mxWidget::getParent(this) == nullptr )
    return 0;
  Parent = mxWidget::getParent(this);
  Handle = (HWND)mxWidget::getHandle(this: Parent);
  if ( Handle == nullptr )
    return 0;
  Id = (unsigned __int16)mxWidget::getId(this);
  v6 = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x111u, wParam: Id, lParam: (LPARAM)v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00464FD0
// Name: public: virtual mxBitmapButton::~mxBitmapButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxBitmapButton::~mxBitmapButton(mxBitmapButton *this)
{
  bool v2; // zf

  v2 = !this->m_bmImage.valid;
  this->__vftable = (mxBitmapButton_vtbl *)&mxBitmapButton::`vftable';
  if ( !v2 )
  {
    DeleteObject(ho: this->m_bmImage.image);
    this->m_bmImage.valid = false;
  }
  mxWindow::~mxWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00465000
// Name: public: mxBitmapButton::mxBitmapButton(class mxWindow __near *,int,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxBitmapButton *__thiscall mxBitmapButton::mxBitmapButton(
        mxBitmapButton *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        int id,
        const char *bitmap)
{
  HWND Handle; // edi
  LONG WindowLongA; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label: defaultValue, style: 0);
  this->__vftable = (mxBitmapButton_vtbl *)&mxBitmapButton::`vftable';
  this->m_bmImage.valid = false;
  this->m_bmImage.image = nullptr;
  this->m_bmImage.width = 0;
  this->m_bmImage.height = 0;
  mxWidget::setId(this, id);
  this->m_bmImage.valid = false;
  LoadBitmapFromFile(relative: bitmap, bitmap: &this->m_bmImage);
  Handle = (HWND)mxWidget::getHandle(this);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: WindowLongA | 0x4000000);
  return this;
}
