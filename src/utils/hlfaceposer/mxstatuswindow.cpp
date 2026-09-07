// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mxstatuswindow.cpp
// Functions: 7
// ============================================================

#include "utils\hlfaceposer\mxstatuswindow.h"

//------------------------------------------------------------------------------
// Address: 0x004680D0
// Name: private: void mxStatusWindow::PositionSliders(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxStatusWindow::PositionSliders(mxStatusWindow *this, int sboffset)
{
  int m_nCurrentLine; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // [esp+Ch] [ebp-4h]

  m_nCurrentLine = this->m_nCurrentLine;
  if ( m_nCurrentLine <= 1024 )
  {
    if ( m_nCurrentLine <= 1 )
      m_nCurrentLine = 1;
  }
  else
  {
    m_nCurrentLine = 1024;
  }
  v7 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
  v4 = mxWidget::h2(this) - v7;
  v5 = 11 * m_nCurrentLine;
  v6 = v5;
  if ( v5 <= v4 )
    v6 = v4;
  mxWidget::setVisible(this: this->m_pScrollbar, b: v5 > v4);
  mxScrollbar::setPagesize(this: this->m_pScrollbar, size: v4);
  mxScrollbar::setRange(this: this->m_pScrollbar, min: 0, max: v6);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00468160
// Name: public: virtual int mxStatusWindow::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall mxStatusWindow::handleEvent(mxStatusWindow *this, mxEvent *event)
{
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int MaxValue; // eax
  int height; // ebx
  int v9; // [esp-Ch] [ebp-1Ch]
  int v10; // [esp-4h] [ebp-14h]
  int iret; // [esp+Ch] [ebp-4h]

  iret = 0;
  if ( this->HandleToolEvent(this: &this->IFacePoserToolWindow, a2: event) )
    return 0;
  v4 = event->event;
  if ( v4 != 0 )
  {
    if ( v4 == 1 )
    {
      v5 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      v10 = mxWidget::h2(this) - v5;
      v9 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      v6 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_pScrollbar, x: v6 - 12, y: v9, w: 12, h: v10);
      mxStatusWindow::PositionSliders(this, sboffset: 0);
      MaxValue = mxScrollbar::getMaxValue(this: this->m_pScrollbar);
      mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: MaxValue);
      return 1;
    }
  }
  else
  {
    iret = 1;
    if ( event->action != 1000 )
      return 0;
    if ( event->modifiers == 5 )
    {
      height = event->height;
      mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: height);
      mxStatusWindow::PositionSliders(this, sboffset: height);
      this->DrawActiveTool(this);
    }
  }
  return iret;
}

//------------------------------------------------------------------------------
// Address: 0x00468260
// Name: public: virtual void mxStatusWindow::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxStatusWindow::Think(mxStatusWindow *this, float dt)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 28))(a1: (char *)this - 12);
}

//------------------------------------------------------------------------------
// Address: 0x00468280
// Name: public: mxStatusWindow::mxStatusWindow(class mxWindow __near *,int,int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
mxStatusWindow *__thiscall mxStatusWindow::mxStatusWindow(
        mxStatusWindow *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h,
        const char *label)
{
  int v8; // ecx
  Color *p_rgb; // eax
  Color *v10; // eax
  int i; // ecx
  mxScrollbar *v12; // eax
  mxScrollbar *v13; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "Status Window",
    displaynameroot: "Output");
  this->mxWindow::mxWidget::__vftable = (mxStatusWindow_vtbl *)&mxStatusWindow::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&mxStatusWindow::`vftable'{for `IFacePoserToolWindow'};
  v8 = 1023;
  p_rgb = &this->m_rgTextLines[0].rgb;
  do
  {
    *p_rgb = 0;
    p_rgb += 130;
    --v8;
  }
  while ( v8 >= 0 );
  this->m_pScrollbar = nullptr;
  v10 = &this->m_rgTextLines[0].rgb;
  for ( i = 1024; i != 0; --i )
  {
    v10[-128]._color[0] = 0;
    *v10 = (Color)14200146;
    v10[1] = 0;
    v10 += 130;
  }
  this->m_nCurrentLine = 0;
  v12 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v12 != nullptr )
    v13 = mxScrollbar::mxScrollbar(this: v12, parent: this, x: 0, y: 0, w: 12, h: 100, id: 1000, style: 1);
  else
    v13 = nullptr;
  this->m_pScrollbar = v13;
  mxScrollbar::setRange(this: v13, min: 0, max: 1000);
  mxScrollbar::setPagesize(this: this->m_pScrollbar, size: 100);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004683C0
// Name: public: virtual void mxStatusWindow::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxStatusWindow::redraw(mxStatusWindow *this)
{
  int v2; // eax
  mxScrollbar *m_pScrollbar; // ecx
  int MaxValue; // esi
  int Pagesize; // ebx
  int Value; // eax
  int v7; // edx
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  char *v11; // esi
  int v12; // eax
  double v13; // [esp+4h] [ebp-C8h]
  CChoreoWidgetDrawHelper helper; // [esp+18h] [ebp-B4h] BYREF
  char sz[32]; // [esp+70h] [ebp-5Ch] BYREF
  tagRECT rc; // [esp+90h] [ebp-3Ch] BYREF
  int v17; // [esp+A0h] [ebp-2Ch]
  tagRECT rcTime; // [esp+A4h] [ebp-28h] BYREF
  int i; // [esp+B4h] [ebp-18h]
  tagRECT rcText; // [esp+B8h] [ebp-14h] BYREF
  Color bgColor; // [esp+C8h] [ebp-4h] BYREF

  if ( this->m_pScrollbar != nullptr )
  {
    bgColor = 0;
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &helper, widget: this, &bgColor);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &helper);
    CChoreoWidgetDrawHelper::GetClientRect(this: &helper, &rc);
    rcText = rc;
    InflateRect(lprc: &rcText, dx: -4, dy: 0);
    v2 = mxWidget::h2(this);
    m_pScrollbar = this->m_pScrollbar;
    rcText.bottom = v2 - 4;
    rcText.top = v2 - 15;
    MaxValue = mxScrollbar::getMaxValue(this: m_pScrollbar);
    Pagesize = mxScrollbar::getPagesize(this: this->m_pScrollbar);
    Value = mxScrollbar::getValue(this: this->m_pScrollbar);
    v7 = 0;
    i = 0;
    v8 = (MaxValue - Pagesize - Value + 10) / 11 < 0 ? 0 : (MaxValue - Pagesize - Value + 10) / 11;
    v9 = 1024 - v8;
    v17 = 1024 - v8;
    if ( 1024 - v8 > 0 )
    {
      do
      {
        v10 = this->m_nCurrentLine - v7 - 1;
        if ( v10 > 0 )
        {
          if ( rcText.bottom < 0 )
            break;
          rcTime = rcText;
          v11 = (char *)this + 520 * (((_WORD)v10 - (_WORD)v8) & 0x3FF);
          v13 = *((float *)v11 + 287);
          rcTime.right = rcText.left + 50;
          sprintf(string: sz, format: "%.3f", v13);
          v12 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
          rcTime.left = rcTime.right - v12 - 5;
          bgColor = (Color)9895935;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: &helper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: &bgColor,
            rcText: &rcTime,
            fmt: sz);
          rcTime.top = rcText.top;
          rcTime.left = rcText.left + 50;
          *(_QWORD *)&rcTime.right = *(_QWORD *)&rcText.right;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: &helper,
            font: "Arial",
            pointsize: 9,
            weight: 400,
            clr: (const Color *)v11 + 286,
            rcText: &rcTime,
            fmt: v11 + 632);
          OffsetRect(lprc: &rcText, dx: 0, dy: -11);
          v9 = v17;
          v7 = i;
        }
        i = ++v7;
      }
      while ( v7 < v9 );
    }
    this->DrawActiveTool(this);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004685E0
// Name: public: void mxStatusWindow::StatusPrint(class Color const __near &,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxStatusWindow::StatusPrint(mxStatusWindow *this, const Color *clr, bool overwrite, const char *text)
{
  double v5; // st7
  int v6; // ebx
  const char *v7; // eax
  char *v8; // edx
  char v9; // cl
  Color *v10; // esi
  float v11; // xmm0_4
  int MaxValue; // eax
  char fixedtext[512]; // [esp+14h] [ebp-224h] BYREF
  char sz[32]; // [esp+214h] [ebp-24h] BYREF
  float curtime; // [esp+234h] [ebp-4h]

  v5 = _Plat_FloatTime();
  curtime = v5;
  sprintf(string: sz, format: "%.3f  ", v5);
  OutputDebugStringA(lpOutputString: sz);
  OutputDebugStringA(lpOutputString: text);
  v6 = 0;
  v7 = text;
  v8 = fixedtext;
  while ( *v7 != 0 )
  {
    if ( v6 >= 511 )
      break;
    v9 = *v7;
    if ( *v7 == 10 || v9 == 13 )
    {
      ++v7;
    }
    else
    {
      *v8++ = v9;
      ++v7;
      ++v6;
    }
  }
  *v8 = 0;
  if ( overwrite )
    --this->m_nCurrentLine;
  v10 = (Color *)((char *)this + 520 * (this->m_nCurrentLine & 0x3FF));
  strncpy(dest: (unsigned __int8 *)&v10[158], source: (unsigned __int8 *)fixedtext, count: 0x1FFu);
  v11 = curtime;
  v10[285]._color[3] = 0;
  v10[286] = *clr;
  *(float *)&v10[287] = v11;
  if ( ++this->m_nCurrentLine <= 1024 )
    mxStatusWindow::PositionSliders(this, sboffset: 0);
  MaxValue = mxScrollbar::getMaxValue(this: this->m_pScrollbar);
  mxScrollbar::setValue(this: this->m_pScrollbar, ivalue: MaxValue);
  this->redraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x00468700
// Name: public: virtual void mxStatusWindow::DrawActiveTool(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mxStatusWindow::DrawActiveTool(mxStatusWindow *this)
{
  int v2; // eax
  CChoreoChannel *ActiveTool; // eax
  float v4; // xmm0_4
  char *Name; // edi
  int CurrentFrame; // eax
  int v7; // edi
  double v8; // [esp+0h] [ebp-18Ch]
  int v9; // [esp+10h] [ebp-17Ch]
  char sz[256]; // [esp+20h] [ebp-16Ch] BYREF
  CChoreoWidgetDrawHelper helper; // [esp+120h] [ebp-6Ch] BYREF
  tagRECT rcTool; // [esp+178h] [ebp-14h] BYREF
  int fps; // [esp+188h] [ebp-4h] BYREF

  rcTool.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 2;
  mxWidget::h2(this);
  v2 = mxWidget::w2(this);
  rcTool.right = v2 - 16;
  rcTool.bottom = rcTool.top + 10;
  rcTool.left = v2 - 516;
  ActiveTool = (CChoreoChannel *)IFacePoserToolWindow::GetActiveTool();
  v4 = (float)realtime - lastrealtime;
  if ( v4 >= 0.0 )
  {
    if ( v4 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  *(float *)&fps = 0.0;
  if ( v4 > 0.000099999997 )
    *(float *)&fps = 1.0 / v4;
  if ( ActiveTool != nullptr )
    Name = CChoreoChannel::GetName(this: ActiveTool);
  else
    Name = "None";
  v9 = models->CountActiveSources(this: models);
  v8 = (float)realtime;
  CurrentFrame = MDLViewer::GetCurrentFrame(this: g_MDLViewer);
  sprintf(string: sz, format: "%s (%i) at %.3f (%.2f fps) (soundcount %i)", Name, CurrentFrame, v8, *(float *)&fps, v9);
  lastrealtime = realtime;
  v7 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Courier New", pointsize: (HFONT__ *)0xA, weight: 400, fmt: sz);
  fps = 32;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
    this: &helper,
    widget: this,
    bounds: &rcTool,
    bgColor: (const Color *)&fps);
  rcTool.left = rcTool.right - v7 - 15;
  *(float *)&fps = 1.8458933e-38;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: &helper,
    font: "Courier New",
    pointsize: 10,
    weight: 400,
    clr: (const Color *)&fps,
    rcText: &rcTool,
    fmt: sz);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &helper);
}
