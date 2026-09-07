// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxslider.cpp
// Functions: 4
// ============================================================

#include "utils\mxtk\mxslider.h"

//------------------------------------------------------------------------------
// Address: 0x004C21C0
// Name: public: mxSlider::mxSlider(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxSlider *__thiscall mxSlider::mxSlider(
        mxSlider *this,
        HWND__ *parent,
        int x,
        int y,
        int w,
        int h,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND hwndParent; // [esp+10h] [ebp+8h]

  mxWidget::mxWidget(this, (mxWindow *)parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxSlider_vtbl *)&mxSlider::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342177280;
    hwndParent = mxWidget::getHandle(this: (mxWidget *)parent);
    if ( style == 1 )
      v10 = 1342177282;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "msctls_trackbar32",
               lpWindowName: defaultValue,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 14);
    mxWidget::setParent(this, parentWindow: (mxWindow *)parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C22A0
// Name: public: void mxSlider::setValue(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxSlider::setValue(mxSlider *this, float value)
{
  HWND__ *Handle; // eax
  LPARAM v3; // [esp-4h] [ebp-4h]

  v3 = (int)(float)((float)((float)((float)(value - this->m_min) / (float)(this->m_max - this->m_min))
                          * (float)this->m_ticks)
                  + 0.5);
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x405u, wParam: 1u, lParam: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004C22F0
// Name: public: void mxSlider::setRange(float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxSlider::setRange(mxSlider *this, float min, float max, int ticks)
{
  HWND__ *Handle; // eax

  this->m_ticks = ticks;
  this->m_min = min;
  this->m_max = max;
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x406u, wParam: 1u, lParam: (unsigned __int16)ticks << 16);
}

//------------------------------------------------------------------------------
// Address: 0x004C2330
// Name: public: float mxSlider::getValue(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxSlider::getValue(mxSlider *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return this->m_min
       + (double)SendMessageA(hWnd: Handle, Msg: 0x400u, wParam: 0, lParam: 0)
       / (double)this->m_ticks
       * (this->m_max - this->m_min);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056DA20
// Name: public: mxSlider::mxSlider(class mxWindow __near *,int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxSlider *__thiscall mxSlider::mxSlider(
        mxSlider *this,
        HWND__ *parent,
        int x,
        int y,
        int w,
        int h,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND hwndParent; // [esp+10h] [ebp+8h]

  mxWidget::mxWidget(this, (mxWindow *)parent, x, y, w, h, label: nullptr);
  this->__vftable = (mxSlider_vtbl *)&mxSlider::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342177280;
    hwndParent = mxWidget::getHandle(this: (mxWidget *)parent);
    if ( style == 1 )
      v10 = 1342177282;
    ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0,
               lpClassName: "msctls_trackbar32",
               lpWindowName: WindowName,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: ModuleHandleA,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 14);
    mxWidget::setParent(this, parentWindow: (mxWindow *)parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056DB00
// Name: public: void mxSlider::setValue(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxSlider::setValue(mxSlider *this, float value)
{
  HWND__ *Handle; // eax
  LPARAM v3; // [esp-4h] [ebp-4h]

  v3 = (int)(float)((float)((float)((float)(value - this->m_min) / (float)(this->m_max - this->m_min))
                          * (float)this->m_ticks)
                  + 0.5);
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x405u, wParam: 1u, lParam: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0056DB50
// Name: public: void mxSlider::setRange(float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxSlider::setRange(mxSlider *this, float min, float max, int ticks)
{
  HWND__ *Handle; // eax

  this->m_ticks = ticks;
  this->m_min = min;
  this->m_max = max;
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x406u, wParam: 1u, lParam: (unsigned __int16)ticks << 16);
}

//------------------------------------------------------------------------------
// Address: 0x0056DB90
// Name: public: void mxSlider::setSteps(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxSlider::setSteps(mxSlider *this, LPARAM line, LPARAM page)
{
  HWND__ *Handle; // eax
  HWND__ *v5; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0x417u, wParam: 0, lParam: line);
  v5 = mxWidget::getHandle(this);
  SendMessageA(hWnd: v5, Msg: 0x415u, wParam: 0, lParam: page);
}

//------------------------------------------------------------------------------
// Address: 0x0056DBD0
// Name: public: float mxSlider::getValue(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxSlider::getValue(mxSlider *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  return this->m_min
       + (double)SendMessageA(hWnd: Handle, Msg: 0x400u, wParam: 0, lParam: 0)
       / (double)this->m_ticks
       * (this->m_max - this->m_min);
}

} // namespace hlmv
