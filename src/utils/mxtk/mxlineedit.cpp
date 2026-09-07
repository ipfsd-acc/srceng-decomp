// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/mxtk/mxlineedit.cpp
// Functions: 5
// ============================================================

#include "utils\mxtk\mxlineedit.h"

//------------------------------------------------------------------------------
// Address: 0x004C1EC0
// Name: public: mxEvent::mxEvent(void)
// Source: json
//------------------------------------------------------------------------------
mxEvent *__thiscall mxEvent::mxEvent(mxEvent *this)
{
  this->__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
  this->event = 0;
  this->widget = nullptr;
  this->action = 0;
  this->width = 0;
  this->height = 0;
  this->x = 0;
  this->y = 0;
  this->buttons = 0;
  this->key = 0;
  this->modifiers = 0;
  this->flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1F20
// Name: EditWndProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EditWndProc(HWND__ *hwnd, unsigned int uMessage, unsigned int wParam, int lParam)
{
  mxWidget *WindowLongA; // edi
  mxWindow *i; // edi
  mxEvent event; // [esp+8h] [ebp-30h] BYREF
  int iret; // [esp+40h] [ebp+8h]

  if ( uMessage == 258 )
  {
    iret = s_OldWndProc(a1: hwnd, a2: 0x102u, a3: wParam, a4: lParam);
    WindowLongA = (mxWidget *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
    event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
    event.widget = nullptr;
    memset(&event.width, 0, 20);
    event.modifiers = 0;
    event.flags = 0;
    event.event = 11;
    event.action = mxWidget::getId(this: WindowLongA);
    event.key = wParam;
    for ( i = mxWidget::getParent(this: WindowLongA); i != nullptr; i = mxWidget::getParent(this: i) )
    {
      if ( i->handleEvent(this: i, a2: &event) != 0 )
        break;
    }
    return iret;
  }
  else
  {
    if ( uMessage == 513 )
      SetFocus(hWnd: hwnd);
    return s_OldWndProc(a1: hwnd, a2: uMessage, a3: wParam, a4: lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2000
// Name: public: mxLineEdit::mxLineEdit(class mxWindow __near *,int,int,int,int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
mxLineEdit *__thiscall mxLineEdit::mxLineEdit(
        mxLineEdit *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HMODULE v12; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND__ *Handle; // eax
  tagWNDCLASSEXA editClass; // [esp+8h] [ebp-34h] BYREF
  HWND__ *hwndParent; // [esp+38h] [ebp-4h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxLineEdit_vtbl *)&mxLineEdit::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342242944;
    hwndParent = mxWidget::getHandle(this: parent);
    if ( style == 1 )
    {
      v10 = 1342244992;
    }
    else if ( style == 2 )
    {
      v10 = 1342242976;
    }
    if ( s_OldWndProc == nullptr )
    {
      ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
      GetClassInfoExA(hInstance: ModuleHandleA, lpszClass: "EDIT", lpwcx: &editClass);
      s_OldWndProc = editClass.lpfnWndProc;
      editClass.cbSize = 48;
      editClass.cbClsExtra = 0;
      editClass.lpfnWndProc = EditWndProc;
      editClass.lpszClassName = "mx_edit";
      RegisterClassExA(a1: &editClass);
    }
    v12 = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0x200u,
               lpClassName: "mx_edit",
               lpWindowName: label,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: v12,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    Handle = mxWidget::getHandle(this);
    SendMessageA(hWnd: Handle, Msg: 0xC5u, wParam: 0x100u, lParam: 0);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 7);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C2150
// Name: public: void mxLineEdit::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit::clear(mxLineEdit *this)
{
  HWND__ *Handle; // eax

  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xCu, wParam: 0, lParam: (LPARAM)defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x004C2170
// Name: public: void mxLineEdit::getText(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit::getText(mxLineEdit *this, char *buf, WPARAM bufsize)
{
  HWND__ *Handle; // eax

  *buf = 0;
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xDu, wParam: bufsize, lParam: (LPARAM)buf);
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0056D610
// Name: public: mxEvent::mxEvent(void)
// Source: json
//------------------------------------------------------------------------------
mxEvent *__thiscall mxEvent::mxEvent(mxEvent *this)
{
  this->__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
  this->event = 0;
  this->widget = nullptr;
  this->action = 0;
  this->width = 0;
  this->height = 0;
  this->x = 0;
  this->y = 0;
  this->buttons = 0;
  this->key = 0;
  this->modifiers = 0;
  this->flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056D670
// Name: EditWndProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall EditWndProc(HWND__ *hwnd, unsigned int uMessage, unsigned int wParam, int lParam)
{
  mxWidget *WindowLongA; // edi
  mxWindow *i; // edi
  mxEvent event; // [esp+8h] [ebp-30h] BYREF
  int iret; // [esp+40h] [ebp+8h]

  if ( uMessage == 258 )
  {
    iret = s_OldWndProc(a1: hwnd, a2: 0x102u, a3: wParam, a4: lParam);
    WindowLongA = (mxWidget *)GetWindowLongA(hWnd: hwnd, nIndex: -21);
    event.__vftable = (mxEvent_vtbl *)&mxEvent::`vftable';
    event.widget = nullptr;
    memset(&event.width, 0, 20);
    event.modifiers = 0;
    event.flags = 0;
    event.event = 11;
    event.action = mxWidget::getId(this: WindowLongA);
    event.key = wParam;
    for ( i = mxWidget::getParent(this: WindowLongA); i != nullptr; i = mxWidget::getParent(this: i) )
    {
      if ( i->handleEvent(this: i, a2: &event) != 0 )
        break;
    }
    return iret;
  }
  else
  {
    if ( uMessage == 513 )
      SetFocus(hWnd: hwnd);
    return s_OldWndProc(a1: hwnd, a2: uMessage, a3: wParam, a4: lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056D750
// Name: public: mxLineEdit::mxLineEdit(class mxWindow __near *,int,int,int,int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
mxLineEdit *__thiscall mxLineEdit::mxLineEdit(
        mxLineEdit *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        HMENU id,
        int style)
{
  DWORD v10; // edi
  HMODULE ModuleHandleA; // eax
  HMODULE v12; // eax
  HWND Window; // edi
  HGDIOBJ StockObject; // eax
  HWND__ *Handle; // eax
  tagWNDCLASSEXA editClass; // [esp+8h] [ebp-34h] BYREF
  HWND__ *hwndParent; // [esp+38h] [ebp-4h]

  mxWidget::mxWidget(this, parent, x, y, w, h, label);
  this->__vftable = (mxLineEdit_vtbl *)&mxLineEdit::`vftable';
  if ( parent != nullptr )
  {
    v10 = 1342242944;
    hwndParent = mxWidget::getHandle(this: parent);
    if ( style == 1 )
    {
      v10 = 1342244992;
    }
    else if ( style == 2 )
    {
      v10 = 1342242976;
    }
    if ( s_OldWndProc == nullptr )
    {
      ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
      GetClassInfoExA(hInstance: ModuleHandleA, lpszClass: "EDIT", lpwcx: &editClass);
      s_OldWndProc = editClass.lpfnWndProc;
      editClass.cbSize = 48;
      editClass.cbClsExtra = 0;
      editClass.lpfnWndProc = EditWndProc;
      editClass.lpszClassName = "mx_edit";
      RegisterClassExA(a1: &editClass);
    }
    v12 = GetModuleHandleA(lpModuleName: nullptr);
    Window = CreateWindowExA(
               dwExStyle: 0x200u,
               lpClassName: "mx_edit",
               lpWindowName: label,
               dwStyle: v10,
               X: x,
               Y: y,
               nWidth: w,
               nHeight: h,
               hWndParent: hwndParent,
               hMenu: id,
               hInstance: v12,
               lpParam: nullptr);
    StockObject = GetStockObject(i: 12);
    SendMessageA(hWnd: Window, Msg: 0x30u, wParam: (WPARAM)StockObject, lParam: 1);
    Handle = mxWidget::getHandle(this);
    SendMessageA(hWnd: Handle, Msg: 0xC5u, wParam: 0x100u, lParam: 0);
    SetWindowLongA(hWnd: Window, nIndex: -21, dwNewLong: (LONG)this);
    mxWidget::setHandle(this, handle: Window);
    mxWidget::setType(this, type: 7);
    mxWidget::setParent(this, parentWindow: parent);
    mxWidget::setId(this, (LONG)id);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0056D8A0
// Name: public: virtual mxLineEdit::~mxLineEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit::~mxLineEdit(mxLineEdit *this)
{
  this->__vftable = (mxLineEdit_vtbl *)&mxLineEdit::`vftable';
  mxWidget::~mxWidget(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056D8B0
// Name: public: void mxLineEdit::getText(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit::getText(mxLineEdit *this, char *buf, WPARAM bufsize)
{
  HWND__ *Handle; // eax

  *buf = 0;
  Handle = mxWidget::getHandle(this);
  SendMessageA(hWnd: Handle, Msg: 0xDu, wParam: bufsize, lParam: (LPARAM)buf);
}

} // namespace hlmv
