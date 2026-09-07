// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxexpressionslider.cpp
// Functions: 20
// ============================================================

#include "utils\hlfaceposer\mxexpressionslider.h"

//------------------------------------------------------------------------------
// Address: 0x00465300
// Name: public: mxExpressionSlider::mxExpressionSlider(class mxWindow __near *,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
mxExpressionSlider *__thiscall mxExpressionSlider::mxExpressionSlider(
        mxExpressionSlider *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        int id)
{
  mxCheckBox *v8; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label: nullptr, style: 0);
  this->__vftable = (mxExpressionSlider_vtbl *)&mxExpressionSlider::`vftable';
  mxWidget::setId(this, id);
  mxWidget::setType(this, type: 14);
  FacePoser_AddWindowStyle(w: this, addbits: 100663296);
  this->m_flMax[0] = 1.0;
  this->m_flMax[1] = 1.0;
  this->m_flMin[0] = 0.0;
  this->m_nTicks[0] = 20;
  this->m_flCurrent[0] = 0.0;
  this->m_flMin[1] = 0.0;
  this->m_nTicks[1] = 20;
  this->m_flCurrent[1] = 0.5;
  this->m_flSetting[0] = 0.0;
  this->m_flSetting[1] = 0.0;
  *(_WORD *)this->m_bIsEdited = 0;
  this->m_bDraggingThumb = false;
  this->m_nCurrentBar = 0;
  this->m_bPaired = false;
  this->m_nTitleWidth = 120;
  this->m_bDrawTitle = true;
  v8 = (mxCheckBox *)operator new(nSize: 0xCu);
  if ( v8 != nullptr )
    this->m_pInfluence = mxCheckBox::mxCheckBox(
                           this: v8,
                           parent: this,
                           x: 2,
                           y: 4,
                           w: 12,
                           h: 12,
                           label: defaultValue,
                           id: 1000);
  else
    this->m_pInfluence = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004653F0
// Name: public: void mxExpressionSlider::SetMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::SetMode(mxExpressionSlider *this, bool paired)
{
  if ( this->m_bPaired != paired )
  {
    this->m_bPaired = paired;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465410
// Name: public: void mxExpressionSlider::setValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::setValue(mxExpressionSlider *this, int barnum, float value)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  if ( this->m_flSetting[barnum] != value || this->m_bIsEdited[barnum] )
  {
    this->m_flSetting[barnum] = value;
    this->m_bIsEdited[barnum] = false;
    if ( this->m_bPaired )
    {
      v3 = this->m_flSetting[0];
      v4 = this->m_flSetting[1];
      if ( v4 <= v3 )
      {
        this->m_flCurrent[0] = v3;
        if ( v3 <= v4 )
          this->m_flCurrent[1] = 0.5;
        else
          this->m_flCurrent[1] = (float)(v4 / v3) * 0.5;
      }
      else
      {
        this->m_flCurrent[0] = v4;
        this->m_flCurrent[1] = 1.0 - (float)((float)(v3 / v4) * 0.5);
      }
    }
    else
    {
      this->m_flCurrent[barnum] = value;
    }
    v5 = this->m_flMax[0];
    if ( this->m_flCurrent[0] > v5 )
      this->m_flCurrent[0] = v5;
    v6 = this->m_flMin[0];
    if ( v6 > this->m_flCurrent[0] )
      this->m_flCurrent[0] = v6;
    v7 = this->m_flMax[1];
    if ( this->m_flCurrent[1] > v7 )
      this->m_flCurrent[1] = v7;
    v8 = this->m_flMin[1];
    if ( v8 > this->m_flCurrent[1] )
      this->m_flCurrent[1] = v8;
    if ( !this->m_bPaired || barnum == 1 )
      this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465510
// Name: public: void mxExpressionSlider::setRange(int,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::setRange(mxExpressionSlider *this, int barnum, float min, float max, int ticks)
{
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4

  this->m_flMin[barnum] = min;
  this->m_flMax[barnum] = max;
  this->m_nTicks[barnum] = ticks;
  v5 = this->m_flMax[0];
  if ( this->m_flCurrent[0] > v5 )
    this->m_flCurrent[0] = v5;
  v6 = this->m_flMin[0];
  if ( v6 > this->m_flCurrent[0] )
    this->m_flCurrent[0] = v6;
  v7 = this->m_flMax[1];
  if ( this->m_flCurrent[1] > v7 )
    this->m_flCurrent[1] = v7;
  v8 = this->m_flMin[1];
  if ( v8 > this->m_flCurrent[1] )
    this->m_flCurrent[1] = v8;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00465590
// Name: public: void mxExpressionSlider::setInfluence(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::setInfluence(mxExpressionSlider *this, float value)
{
  if ( value > 0.0 != mxCheckBox::isChecked(this: this->m_pInfluence) )
  {
    mxCheckBox::setChecked(this: this->m_pInfluence, b: value > 0.0);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004655E0
// Name: public: float mxExpressionSlider::getRawValue(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxExpressionSlider::getRawValue(mxExpressionSlider *this, int barnum)
{
  return this->m_flCurrent[barnum];
}

//------------------------------------------------------------------------------
// Address: 0x004655F0
// Name: public: float mxExpressionSlider::getValue(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxExpressionSlider::getValue(mxExpressionSlider *this, int barnum)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float scale; // [esp+0h] [ebp-4h]

  scale = 1.0;
  if ( this->m_bPaired )
  {
    if ( barnum != 0 )
    {
      if ( barnum == 1 )
      {
        v3 = this->m_flCurrent[1];
        if ( v3 < 0.5 )
          goto LABEL_7;
      }
    }
    else
    {
      v2 = this->m_flCurrent[1];
      if ( v2 > 0.5 )
      {
        v3 = 1.0 - v2;
LABEL_7:
        scale = v3 * 2.0;
      }
    }
  }
  return this->m_flCurrent[0] * scale;
}

//------------------------------------------------------------------------------
// Address: 0x00465660
// Name: public: float mxExpressionSlider::getMinValue(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxExpressionSlider::getMinValue(mxExpressionSlider *this, int barnum)
{
  return this->m_flMin[barnum];
}

//------------------------------------------------------------------------------
// Address: 0x00465670
// Name: public: float mxExpressionSlider::getMaxValue(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxExpressionSlider::getMaxValue(mxExpressionSlider *this, int barnum)
{
  return this->m_flMax[barnum];
}

//------------------------------------------------------------------------------
// Address: 0x00465680
// Name: public: float mxExpressionSlider::getInfluence(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall mxExpressionSlider::getInfluence(mxExpressionSlider *this)
{
  if ( mxCheckBox::isChecked(this: this->m_pInfluence) )
    return 1.0;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x004656C0
// Name: public: void mxExpressionSlider::setEdited(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::setEdited(mxExpressionSlider *this, int barnum, bool isEdited)
{
  if ( this->m_bIsEdited[barnum] != isEdited )
  {
    this->m_bIsEdited[barnum] = isEdited;
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004656E0
// Name: public: bool mxExpressionSlider::isEdited(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall mxExpressionSlider::isEdited(mxExpressionSlider *this, int barnum)
{
  return this->m_bIsEdited[barnum];
}

//------------------------------------------------------------------------------
// Address: 0x004656F0
// Name: private: void mxExpressionSlider::GetBarRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::GetBarRect(mxExpressionSlider *this, tagRECT *rcBar)
{
  HWND Handle; // eax
  int v4; // eax
  tagRECT rc; // [esp+4h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  if ( Handle != nullptr )
  {
    GetClientRect(hWnd: Handle, lpRect: &rc);
    if ( this->m_bDrawTitle )
      rc.left += this->m_nTitleWidth;
  }
  *rcBar = rc;
  InflateRect(lprc: rcBar, dx: -10, dy: 0);
  v4 = (2 * rcBar->top + 12) / 2;
  rcBar->top = v4 - 1;
  rcBar->bottom = v4 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00465760
// Name: private: void mxExpressionSlider::GetThumbRect(int,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::GetThumbRect(mxExpressionSlider *this, int barnum, tagRECT *rcThumb)
{
  HWND Handle; // eax
  float v5; // xmm0_4
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  tagRECT rc; // [esp+4h] [ebp-20h] BYREF
  tagRECT rcBar; // [esp+14h] [ebp-10h] BYREF

  Handle = (HWND)mxWidget::getHandle(this);
  if ( Handle != nullptr )
  {
    GetClientRect(hWnd: Handle, lpRect: &rc);
    if ( this->m_bDrawTitle )
      rc.left += this->m_nTitleWidth;
  }
  rcBar = rc;
  mxExpressionSlider::GetBarRect(this, &rcBar);
  v5 = 0.0;
  if ( (float)(this->m_flMax[barnum] - this->m_flMin[barnum]) > 0.0 )
    v5 = (float)(this->m_flCurrent[barnum] - this->m_flMin[barnum])
       / (float)(this->m_flMax[barnum] - this->m_flMin[barnum]);
  v6 = this->m_nTicks[barnum];
  v7 = (int)(float)((float)((float)v6 * v5) + 0.5);
  if ( v6 < v7 )
    v7 = this->m_nTicks[barnum];
  v8 = (int)(float)((float)((float)(v7 < 0 ? 0 : v7) * (float)(rcBar.right - rcBar.left)) / (float)this->m_nTicks[barnum])
     + rcBar.left
     - 10;
  rcThumb->left = v8;
  rcThumb->right = v8 + 20;
  v9 = rcBar.top - 5;
  rcThumb->top = rcBar.top - 5;
  rcThumb->bottom = v9 + 14;
}

//------------------------------------------------------------------------------
// Address: 0x00465860
// Name: private: void mxExpressionSlider::DrawBar(struct HDC__ __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::DrawBar(mxExpressionSlider *this, HDC__ **dc)
{
  DWORD SysColor; // eax
  HPEN Pen; // ebx
  DWORD v4; // eax
  HPEN__ *v5; // edi
  DWORD v6; // eax
  HBRUSH__ *SolidBrush; // eax
  HBRUSH__ *v9; // edi
  HDC v10; // [esp-8h] [ebp-2Ch]
  tagRECT rcBar; // [esp+Ch] [ebp-18h] BYREF
  HPEN__ *hilight; // [esp+1Ch] [ebp-8h]
  HBRUSH__ *face; // [esp+20h] [ebp-4h]
  HPEN__ *oldPen; // [esp+2Ch] [ebp+8h]

  mxExpressionSlider::GetBarRect(this, &rcBar);
  SysColor = GetSysColor(nIndex: 16);
  Pen = CreatePen(iStyle: 0, cWidth: 1, color: SysColor);
  v4 = GetSysColor(nIndex: 20);
  v5 = CreatePen(iStyle: 0, cWidth: 1, color: v4);
  hilight = v5;
  v6 = GetSysColor(nIndex: 15);
  SolidBrush = CreateSolidBrush(color: v6);
  v10 = *dc;
  face = SolidBrush;
  oldPen = (HPEN__ *)SelectObject(hdc: v10, h: v5);
  MoveToEx(hdc: *dc, x: rcBar.left, y: rcBar.bottom, lppt: nullptr);
  LineTo(hdc: *dc, x: rcBar.left, y: rcBar.top);
  LineTo(hdc: *dc, x: rcBar.right, y: rcBar.top);
  SelectObject(hdc: *dc, h: Pen);
  LineTo(hdc: *dc, x: rcBar.right, y: rcBar.bottom);
  LineTo(hdc: *dc, x: rcBar.left, y: rcBar.bottom);
  v9 = face;
  ++rcBar.left;
  ++rcBar.top;
  --rcBar.bottom;
  FillRect(hDC: *dc, lprc: &rcBar, hbr: face);
  SelectObject(hdc: *dc, h: oldPen);
  DeleteObject(ho: v9);
  DeleteObject(ho: Pen);
  DeleteObject(ho: hilight);
}

//------------------------------------------------------------------------------
// Address: 0x00465960
// Name: private: void mxExpressionSlider::MoveThumb(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::MoveThumb(mxExpressionSlider *this, int barnum, int xpos, bool finish)
{
  bool m_bPaired; // al
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  mxWindow *Parent; // eax
  HWND Handle; // ebx
  void *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  tagRECT rcBar; // [esp+8h] [ebp-10h] BYREF

  mxExpressionSlider::GetBarRect(this, &rcBar);
  if ( xpos >= rcBar.left )
  {
    if ( xpos <= rcBar.right )
      this->m_flCurrent[barnum] = (float)((float)((float)(int)(float)((float)((float)((float)(xpos - rcBar.left)
                                                                                    / (float)(rcBar.right - rcBar.left))
                                                                            * (float)this->m_nTicks[0])
                                                                    + 0.5)
                                                / (float)this->m_nTicks[0])
                                        * (float)(this->m_flMax[barnum] - this->m_flMin[barnum]))
                                + this->m_flMin[barnum];
    else
      this->m_flCurrent[barnum] = this->m_flMax[barnum];
  }
  else
  {
    this->m_flCurrent[barnum] = this->m_flMin[barnum];
  }
  m_bPaired = this->m_bPaired;
  v6 = 1.0;
  v7 = 1.0;
  if ( m_bPaired )
  {
    v8 = this->m_flCurrent[1];
    if ( v8 > 0.5 )
      v7 = (float)(1.0 - v8) * 2.0;
  }
  v9 = this->m_flCurrent[0];
  this->m_flSetting[0] = v9 * v7;
  if ( m_bPaired )
  {
    v10 = this->m_flCurrent[1];
    if ( v10 < 0.5 )
      v6 = v10 * 2.0;
  }
  this->m_flSetting[1] = v9 * v6;
  *(_WORD *)this->m_bIsEdited = 257;
  if ( mxWidget::getParent(this) != nullptr )
  {
    Parent = mxWidget::getParent(this);
    Handle = (HWND)mxWidget::getHandle(this: Parent);
    if ( Handle != nullptr )
    {
      v13 = mxWidget::getHandle(this);
      SendMessageA(
        hWnd: Handle,
        Msg: 0x114u,
        wParam: (4 * finish + 4) | ((unsigned __int16)barnum << 16),
        lParam: (LPARAM)v13);
    }
  }
  v14 = this->m_flMax[0];
  if ( this->m_flCurrent[0] > v14 )
    this->m_flCurrent[0] = v14;
  v15 = this->m_flMin[0];
  if ( v15 > this->m_flCurrent[0] )
    this->m_flCurrent[0] = v15;
  v16 = this->m_flMax[1];
  if ( this->m_flCurrent[1] > v16 )
    this->m_flCurrent[1] = v16;
  v17 = this->m_flMin[1];
  if ( v17 > this->m_flCurrent[1] )
    this->m_flCurrent[1] = v17;
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00465B00
// Name: public: virtual int mxExpressionSlider::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxExpressionSlider::handleEvent(mxExpressionSlider *this, mxEvent *event)
{
  int v2; // eax
  bool v4; // zf
  int result; // eax
  HWND Handle; // eax
  void (__thiscall *redraw)(struct mxExpressionSlider *); // eax
  void (__thiscall *v8)(struct mxExpressionSlider *); // eax
  mxWindow *Parent; // eax
  HWND v10; // ebx
  WPARAM v11; // edi
  void *v12; // eax
  HWND v13; // eax
  unsigned int x_low; // ebx
  BOOL v15; // eax
  int m_nCurrentBar; // edx
  int key; // edi
  const char *Label; // eax
  tagRECT rcThumb; // [esp+Ch] [ebp-18h] BYREF
  int iret; // [esp+20h] [ebp-4h]

  v2 = event->event;
  iret = 0;
  switch ( v2 )
  {
    case 0:
      v4 = event->action == 1000;
      iret = 1;
      if ( v4 )
      {
        Handle = (HWND)mxWidget::getHandle(this);
        SetFocus(hWnd: Handle);
        if ( this->m_bIsEdited[0] )
        {
          redraw = this->redraw;
          this->m_bIsEdited[0] = false;
          redraw(this);
        }
        if ( this->m_bIsEdited[1] )
        {
          v8 = this->redraw;
          this->m_bIsEdited[1] = false;
          v8(this);
        }
        if ( mxWidget::getParent(this) == nullptr )
          goto LABEL_23;
        Parent = mxWidget::getParent(this);
        v10 = (HWND)mxWidget::getHandle(this: Parent);
        if ( v10 == nullptr )
          goto LABEL_23;
        v11 = (LOWORD(this->m_nCurrentBar) << 16) | 8;
        v12 = mxWidget::getHandle(this);
        SendMessageA(hWnd: v10, Msg: 0x114u, wParam: v11, lParam: (LPARAM)v12);
        result = iret;
      }
      else
      {
        iret = 0;
        result = 0;
      }
      break;
    case 6:
      if ( this->m_bDraggingThumb )
      {
        mxCheckBox::setChecked(this: this->m_pInfluence, b: true);
        m_nCurrentBar = this->m_nCurrentBar;
        this->m_bDraggingThumb = false;
        mxExpressionSlider::MoveThumb(this, barnum: m_nCurrentBar, xpos: SLOWORD(event->x), finish: true);
        this->m_nCurrentBar = 0;
      }
      iret = 1;
      result = 1;
      break;
    case 7:
      v13 = (HWND)mxWidget::getHandle(this);
      SetFocus(hWnd: v13);
      if ( !this->m_bDraggingThumb )
      {
        x_low = SLOWORD(event->x);
        v15 = (event->buttons & 2) != 0;
        iret = SLOWORD(event->y);
        this->m_nCurrentBar = v15;
        mxExpressionSlider::GetThumbRect(this, barnum: v15, &rcThumb);
        if ( PtInRect(lprc: &rcThumb, pt: (POINT)__PAIR64__(iret, x_low)) )
          this->m_bDraggingThumb = true;
      }
      iret = 1;
      result = 1;
      break;
    case 8:
    case 9:
      if ( !this->m_bDraggingThumb )
        goto LABEL_23;
      mxCheckBox::setChecked(this: this->m_pInfluence, b: true);
      mxExpressionSlider::MoveThumb(this, barnum: this->m_nCurrentBar, xpos: SLOWORD(event->x), finish: false);
      iret = 1;
      result = 1;
      break;
    case 11:
      key = event->key;
      if ( key == 13 || key == 83 )
      {
        Label = mxWidget::getLabel(this);
        ExpressionTool::OnSetSingleKeyFromFlex(this: g_pExpressionTool, sliderName: Label);
      }
      goto LABEL_23;
    default:
LABEL_23:
      result = iret;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00465D20
// Name: private: void mxExpressionSlider::DrawThumb(int,struct HDC__ __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::DrawThumb(mxExpressionSlider *this, int barnum, HDC__ **dc)
{
  DWORD SysColor; // eax
  DWORD v5; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  DWORD v9; // eax
  unsigned __int8 v10; // ch
  int v11; // eax
  int v12; // edx
  int v13; // ecx
  HBRUSH SolidBrush; // eax
  float v15; // xmm0_4
  int v16; // xmm1_4
  DWORD v17; // eax
  HRGN PolygonRgn; // edi
  tagPOINT region[3]; // [esp+Ch] [ebp-30h] BYREF
  tagRECT rcThumb; // [esp+24h] [ebp-18h] BYREF
  HPEN__ *shadow; // [esp+34h] [ebp-8h]
  HPEN__ *hilight; // [esp+38h] [ebp-4h]
  float frac; // [esp+44h] [ebp+8h]
  float fraca; // [esp+44h] [ebp+8h]
  HBRUSH fracb; // [esp+44h] [ebp+8h]
  HPEN__ *oldPen; // [esp+48h] [ebp+Ch]
  HPEN__ *oldPena; // [esp+48h] [ebp+Ch]

  mxExpressionSlider::GetThumbRect(this, barnum, &rcThumb);
  SysColor = GetSysColor(nIndex: 21);
  shadow = CreatePen(iStyle: 0, cWidth: 1, color: SysColor);
  v5 = GetSysColor(nIndex: 20);
  hilight = CreatePen(iStyle: 0, cWidth: 1, color: v5);
  if ( barnum == 1 )
  {
    v15 = this->m_flCurrent[1];
    v16 = 1065353216;
    fraca = v15;
    if ( v15 > 1.0 || (v16 = 0, v15 < 0.0) )
      fraca = *(float *)&v16;
    v17 = GetSysColor(nIndex: 15);
    SolidBrush = CreateSolidBrush(
                   color: (unsigned __int8)(int)(float)((float)((float)(255 - (unsigned __int8)v17)
                                                       * (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(fraca - 0.5) & _mask__AbsFloat_)
                                                               * 2.0))
                                               + (float)(unsigned __int8)v17)
                 | (((unsigned __int8)(int)(float)((float)BYTE1(v17)
                                                 * (float)(1.0
                                                         - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(fraca - 0.5) & _mask__AbsFloat_)
                                                                 * 2.0)))
                   | ((unsigned __int8)(int)(float)((float)BYTE2(v17)
                                                  * (float)(1.0
                                                          - (float)(COERCE_FLOAT(
                                                                      COERCE_UNSIGNED_INT(fraca - 0.5)
                                                                    & _mask__AbsFloat_)
                                                                  * 2.0))) << 8)) << 8));
  }
  else
  {
    v7 = this->m_flCurrent[barnum];
    if ( v7 >= 0.0 )
      v8 = v7 / this->m_flMax[barnum];
    else
      v8 = v7 / this->m_flMin[barnum];
    frac = v8;
    if ( v8 <= 1.0 )
    {
      if ( v8 < 0.0 )
        frac = 0.0;
    }
    else
    {
      frac = 1.0;
    }
    v9 = GetSysColor(nIndex: 15);
    v10 = BYTE1(v9);
    v11 = (int)(float)((float)BYTE2(v9) * (float)(1.0 - frac));
    v12 = v10;
    v13 = (int)(float)((float)((float)(255 - v11) * frac) + (float)v11);
    if ( v13 > 255 )
      LOBYTE(v13) = -1;
    SolidBrush = CreateSolidBrush(
                   color: (unsigned __int8)v11
                 | (((unsigned __int8)(int)(float)((float)v12 * (float)(1.0 - frac)) | ((unsigned __int8)v13 << 8)) << 8));
  }
  fracb = SolidBrush;
  InflateRect(lprc: &rcThumb, dx: -2, dy: 0);
  if ( barnum == 1 )
  {
    region[0].x = (rcThumb.right + rcThumb.left) / 2;
    region[0].y = rcThumb.top + 2;
    region[1].x = rcThumb.left;
    region[1].y = rcThumb.bottom;
    region[2] = *(tagPOINT *)&rcThumb.right;
  }
  else
  {
    region[0].x = rcThumb.left;
    region[1].x = rcThumb.right;
    region[0].y = rcThumb.top;
    region[1].y = rcThumb.top;
    region[2].x = (rcThumb.right + rcThumb.left) / 2;
    region[2].y = rcThumb.bottom - 2;
  }
  PolygonRgn = CreatePolygonRgn(pptl: region, cPoint: 3, iMode: 1);
  oldPen = (HPEN__ *)SetPolyFillMode(hdc: *dc, mode: 1);
  FillRgn(hdc: *dc, hrgn: PolygonRgn, hbr: fracb);
  SetPolyFillMode(hdc: *dc, mode: (int)oldPen);
  DeleteObject(ho: PolygonRgn);
  oldPena = (HPEN__ *)SelectObject(hdc: *dc, h: hilight);
  MoveToEx(hdc: *dc, x: region[0].x, y: region[0].y, lppt: nullptr);
  LineTo(hdc: *dc, x: region[1].x, y: region[1].y);
  SelectObject(hdc: *dc, h: shadow);
  LineTo(hdc: *dc, x: region[2].x, y: region[2].y);
  SelectObject(hdc: *dc, h: hilight);
  LineTo(hdc: *dc, x: region[0].x, y: region[0].y);
  SelectObject(hdc: *dc, h: oldPena);
  DeleteObject(ho: fracb);
  DeleteObject(ho: shadow);
  DeleteObject(ho: hilight);
}

//------------------------------------------------------------------------------
// Address: 0x00466030
// Name: private: void mxExpressionSlider::DrawTitle(struct HDC__ __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::DrawTitle(mxExpressionSlider *this, HDC__ **dc)
{
  HWND Handle; // eax
  int m_nTitleWidth; // edx
  const char *Label; // eax
  COLORREF v7; // eax
  int v8; // eax
  HDC v9; // ecx
  HFONT__ *v10; // eax
  HDC v11; // ecx
  DWORD SysColor; // [esp-8h] [ebp-ACh]
  char sz[128]; // [esp+8h] [ebp-9Ch] BYREF
  tagRECT rc; // [esp+88h] [ebp-1Ch] BYREF
  HFONT__ *oldfont; // [esp+98h] [ebp-Ch]
  int oldMode; // [esp+9Ch] [ebp-8h]
  HFONT__ *fnt; // [esp+A0h] [ebp-4h]
  __int16 oldColor; // [esp+ACh] [ebp+8h]
  unsigned __int8 oldColor_2; // [esp+AEh] [ebp+Ah]

  if ( this->m_bDrawTitle )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    if ( Handle != nullptr )
    {
      GetClientRect(hWnd: Handle, lpRect: &rc);
      m_nTitleWidth = this->m_nTitleWidth;
      rc.left += 16;
      rc.right = m_nTitleWidth;
      InflateRect(lprc: &rc, dx: -5, dy: -2);
      Label = mxWidget::getLabel(this);
      sprintf(string: sz, format: "%s", Label);
      fnt = CreateFontA(
              cHeight: -12,
              cWidth: 0,
              cEscapement: 0,
              cOrientation: 0,
              cWeight: 400,
              bItalic: 0,
              bUnderline: 0,
              bStrikeOut: 0,
              iCharSet: 0,
              iOutPrecision: 4u,
              iClipPrecision: 0,
              iQuality: 2u,
              iPitchAndFamily: 2u,
              pszFaceName: "Arial");
      if ( this->m_bIsEdited[0] )
        SysColor = 255;
      else
        SysColor = GetSysColor(nIndex: 18);
      v7 = SetTextColor(hdc: *dc, color: SysColor);
      oldColor = v7;
      oldColor_2 = BYTE2(v7);
      v8 = SetBkMode(hdc: *dc, mode: 1);
      v9 = *dc;
      oldMode = v8;
      v10 = (HFONT__ *)SelectObject(hdc: v9, h: fnt);
      v11 = *dc;
      oldfont = v10;
      DrawTextA(hdc: v11, lpchText: sz, cchText: -1, lprc: &rc, format: 0x40824u);
      SelectObject(hdc: *dc, h: oldfont);
      DeleteObject(ho: fnt);
      SetBkMode(hdc: *dc, mode: oldMode);
      SetTextColor(hdc: *dc, color: (unsigned __int8)oldColor | ((HIBYTE(oldColor) | (oldColor_2 << 8)) << 8));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466180
// Name: public: virtual void mxExpressionSlider::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxExpressionSlider::redraw(mxExpressionSlider *this)
{
  HWND__ *Handle; // eax
  HWND v2; // edi
  HDC__ *v3; // esi
  int v4; // edi
  int v5; // ebx
  HDC__ *CompatibleDC; // esi
  DWORD SysColor; // eax
  int m_bPaired; // eax
  HDC__ *v9; // edi
  HWND__ *v10; // esi
  int v11; // [esp-20h] [ebp-50h]
  tagRECT rc; // [esp+4h] [ebp-2Ch] BYREF
  HWND__ *wnd; // [esp+14h] [ebp-1Ch]
  HBITMAP__ *bm; // [esp+18h] [ebp-18h]
  HBITMAP__ *oldbm; // [esp+1Ch] [ebp-14h]
  HDC__ *finalDC; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  HDC__ *dc; // [esp+28h] [ebp-8h] BYREF
  mxExpressionSlider *v19; // [esp+2Ch] [ebp-4h]

  v19 = this;
  Handle = (HWND__ *)mxWidget::getHandle(this);
  v2 = Handle;
  wnd = Handle;
  if ( Handle != nullptr )
  {
    v3 = GetDC(hWnd: Handle);
    finalDC = v3;
    if ( v3 != nullptr )
    {
      GetClientRect(hWnd: v2, lpRect: &rc);
      v4 = rc.right - rc.left;
      v5 = rc.bottom - rc.top;
      CompatibleDC = CreateCompatibleDC(hdc: v3);
      dc = CompatibleDC;
      bm = CreateCompatibleBitmap(hdc: finalDC, cx: v4, cy: v5);
      oldbm = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: bm);
      SysColor = GetSysColor(nIndex: 15);
      i = (int)CreateSolidBrush(color: SysColor);
      FillRect(hDC: CompatibleDC, lprc: &rc, hbr: (HBRUSH)i);
      DeleteObject(ho: (HGDIOBJ)i);
      mxExpressionSlider::DrawTitle(this: v19, &dc);
      mxExpressionSlider::DrawBar(this: v19, &dc);
      m_bPaired = v19->m_bPaired;
      for ( i = m_bPaired; ; m_bPaired = i )
      {
        mxExpressionSlider::DrawThumb(this: v19, barnum: m_bPaired, &dc);
        if ( --i < 0 )
          break;
      }
      v11 = v4;
      v9 = finalDC;
      BitBlt(hdc: finalDC, x: 0, y: 0, cx: v11, cy: v5, hdcSrc: CompatibleDC, x1: 0, y1: 0, rop: 0xCC0020u);
      SelectObject(hdc: CompatibleDC, h: oldbm);
      DeleteObject(ho: bm);
      DeleteDC(hdc: CompatibleDC);
      v10 = wnd;
      ReleaseDC(hWnd: wnd, hDC: v9);
      ValidateRect(hWnd: v10, lpRect: &rc);
    }
  }
}
