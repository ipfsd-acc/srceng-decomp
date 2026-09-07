// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/mxlineedit2.cpp
// Functions: 3
// ============================================================

#include "utils\hlmv\mxlineedit2.h"

//------------------------------------------------------------------------------
// Address: 0x0041C260
// Name: public: mxLineEdit2::mxLineEdit2(class mxWindow __near *,int,int,int,int,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
mxLineEdit2 *__thiscall mxLineEdit2::mxLineEdit2(
        mxLineEdit2 *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label,
        int id,
        int style)
{
  mxLineEdit::mxLineEdit(this, parent, x, y, w, h, label, id, style);
  this->__vftable = (mxLineEdit2_vtbl *)&mxLineEdit2::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041C2A0
// Name: public: void mxLineEdit2::getText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit2::getText(mxLineEdit2 *this, char *pOut, int len)
{
  HWND Handle; // eax

  Handle = (HWND)mxWidget::getHandle(this);
  GetWindowTextA(hWnd: Handle, lpString: pOut, nMaxCount: len);
  pOut[len - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041C2D0
// Name: public: void mxLineEdit2::setText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxLineEdit2::setText(mxLineEdit2 *this, const char *pText)
{
  mxWidget::setLabel(this, format: "%s", pText);
}
