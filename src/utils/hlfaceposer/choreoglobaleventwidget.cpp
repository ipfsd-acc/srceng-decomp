// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/choreoglobaleventwidget.cpp
// Functions: 4
// ============================================================

#include "utils\hlfaceposer\choreoglobaleventwidget.h"

//------------------------------------------------------------------------------
// Address: 0x00491910
// Name: public: CChoreoGlobalEventWidget::CChoreoGlobalEventWidget(class CChoreoWidget __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoGlobalEventWidget *__thiscall CChoreoGlobalEventWidget::CChoreoGlobalEventWidget(
        CChoreoGlobalEventWidget *this,
        CChoreoWidget *parent)
{
  CChoreoWidget::CChoreoWidget(this, parent);
  this->m_pEvent = nullptr;
  this->m_bDragging = false;
  this->m_xStart = 0;
  this->m_hPrevCursor = nullptr;
  this->__vftable = (CChoreoGlobalEventWidget_vtbl *)&CChoreoGlobalEventWidget::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00491940
// Name: public: virtual void CChoreoGlobalEventWidget::Layout(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGlobalEventWidget::Layout(CChoreoGlobalEventWidget *this, tagRECT *rc)
{
  this->setBounds(this, a2: rc->left, a3: rc->top, a4: rc->right - rc->left, a5: rc->bottom - rc->top);
}

//------------------------------------------------------------------------------
// Address: 0x004919C0
// Name: private: void CChoreoGlobalEventWidget::DrawLabel(class CChoreoWidgetDrawHelper __near &,class Color const __near &,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGlobalEventWidget::DrawLabel(
        CChoreoGlobalEventWidget *this,
        CChoreoWidgetDrawHelper *drawHelper,
        const Color *clr,
        int x,
        int y,
        bool right)
{
  CChoreoEvent *m_pEvent; // edi
  const char *Name; // eax
  const char *v8; // eax
  int v9; // esi
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  tagRECT rcText; // [esp+4h] [ebp-10h] BYREF

  m_pEvent = this->m_pEvent;
  if ( m_pEvent != nullptr )
  {
    Name = CChoreoEvent::GetName(this: m_pEvent);
    v8 = va(fmt: "%s", Name);
    v9 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: v8);
    rcText.top = y;
    rcText.bottom = y + 10;
    rcText.left = x - v9 / 2;
    rcText.right = v9 + rcText.left;
    if ( right )
    {
      v12 = CChoreoEvent::GetName(this: m_pEvent);
      v13 = va(fmt: "%s", v12);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr,
        &rcText,
        fmt: v13);
      OffsetRect(lprc: &rcText, dx: v9, dy: 0);
      CChoreoWidgetDrawHelper::DrawColoredTextCharset(
        this: drawHelper,
        font: "Marlett",
        pointsize: (Color)9,
        weight: 400,
        charset: 2u,
        clr,
        &rcText,
        fmt: "4");
    }
    else
    {
      CChoreoWidgetDrawHelper::DrawColoredTextCharset(
        this: drawHelper,
        font: "Marlett",
        pointsize: (Color)9,
        weight: 400,
        charset: 2u,
        clr,
        &rcText,
        fmt: "3");
      OffsetRect(lprc: &rcText, dx: 8, dy: 0);
      v10 = CChoreoEvent::GetName(this: m_pEvent);
      v11 = va(fmt: "%s", v10);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr,
        &rcText,
        fmt: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491B00
// Name: public: virtual void CChoreoGlobalEventWidget::redraw(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoGlobalEventWidget::redraw(CChoreoGlobalEventWidget *this, float drawHelper)
{
  CChoreoEvent *m_pEvent; // esi
  __int32 v4; // eax
  CChoreoWidgetDrawHelper *v5; // esi
  bool (__thiscall *IsSelected)(struct CChoreoGlobalEventWidget *); // eax
  int v7; // edi
  CChoreoEvent::EVENTTYPE Type; // eax
  HDC NumChannels; // eax
  const char *Parameters; // eax
  int PixelForTimeValue; // edi
  int left; // [esp-Ch] [ebp-68h]
  int top; // [esp-8h] [ebp-64h]
  mxbitmapdata_t *v14; // [esp+4h] [ebp-58h]
  tagRECT rcClient; // [esp+14h] [ebp-48h] BYREF
  tagRECT rcLine; // [esp+24h] [ebp-38h]
  tagRECT rcTab; // [esp+34h] [ebp-28h] BYREF
  int y; // [esp+44h] [ebp-18h]
  CChoreoEvent *event; // [esp+48h] [ebp-14h]
  Color labelText; // [esp+4Ch] [ebp-10h] BYREF
  Color pointColor; // [esp+50h] [ebp-Ch] BYREF
  Color clr; // [esp+54h] [ebp-8h] BYREF
  bool clipped; // [esp+5Ah] [ebp-2h] BYREF
  bool isLoop; // [esp+5Bh] [ebp-1h]

  if ( this->getVisible(this) )
  {
    m_pEvent = this->m_pEvent;
    event = m_pEvent;
    if ( m_pEvent != nullptr )
    {
      rcTab = *this->getBounds(this);
      isLoop = false;
      pointColor = (Color)16742463;
      clr = (Color)15122090;
      v4 = CChoreoEvent::GetType(this: m_pEvent) - 12;
      if ( v4 != 0 )
      {
        if ( v4 == 2 )
        {
          clr = (Color)255;
          pointColor = (Color)2039807;
        }
      }
      else
      {
        clr = (Color)9856255;
        pointColor = (Color)16742655;
        isLoop = true;
      }
      if ( this->IsSelected(this) )
      {
        InflateRect(lprc: &rcTab, dx: 2, dy: 2);
        v5 = (CChoreoWidgetDrawHelper *)LODWORD(drawHelper);
        CChoreoWidgetDrawHelper::DrawTriangleMarker(
          this: (CChoreoWidgetDrawHelper *)LODWORD(drawHelper),
          rc: &rcTab,
          fill: &pointColor,
          inverted: false);
        InflateRect(lprc: &rcTab, dx: -2, dy: -2);
        drawHelper = 2.0290241e-38;
        CChoreoWidgetDrawHelper::DrawTriangleMarker(
          this: v5,
          rc: &rcTab,
          fill: (const Color *)&drawHelper,
          inverted: false);
      }
      else
      {
        v5 = (CChoreoWidgetDrawHelper *)LODWORD(drawHelper);
        CChoreoWidgetDrawHelper::DrawTriangleMarker(
          this: (CChoreoWidgetDrawHelper *)LODWORD(drawHelper),
          rc: &rcTab,
          fill: &pointColor,
          inverted: false);
      }
      CChoreoWidgetDrawHelper::GetClientRect(this: v5, rc: &rcClient);
      *(_QWORD *)&rcLine.left = *(_QWORD *)&rcTab.left;
      rcLine.right = _mm_loadl_epi64((const __m128i *)&rcTab.right).m128i_u32[0];
      rcLine.bottom = rcClient.bottom;
      IsSelected = this->IsSelected;
      rcLine.top = rcTab.bottom + 2;
      v7 = (rcLine.right + rcTab.left) / 2;
      if ( IsSelected(this) )
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: v5,
          (HPEN__ *)&clr,
          style: 2,
          width: 2,
          x1: v7,
          y1: rcLine.top,
          x2: v7,
          y2: rcLine.bottom);
      else
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: v5,
          (HPEN__ *)&clr,
          style: 2,
          width: 1,
          x1: v7,
          y1: rcLine.top,
          x2: v7,
          y2: rcLine.bottom);
      if ( CChoreoEvent::GetType(this: event) == STOPPOINT )
      {
        OffsetRect(lprc: &rcTab, dx: -4, dy: 15);
        Type = CChoreoEvent::GetType(this: event);
        drawHelper = COERCE_FLOAT(CChoreoEventWidget::GetImage(type: Type));
        if ( drawHelper != 0.0 )
        {
          CChoreoWidgetDrawHelper::OffsetSubRect(this: v5, rc: &rcTab);
          v14 = (mxbitmapdata_t *)LODWORD(drawHelper);
          top = rcTab.top;
          left = rcTab.left;
          NumChannels = (HDC)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)v5);
          DrawBitmapToDC(hdc: NumChannels, x: left, y: top, w: 16, h: 16, bitmap: v14);
        }
      }
      if ( isLoop )
      {
        y = rcLine.top + 2;
        labelText = (Color)7999;
        CChoreoGlobalEventWidget::DrawLabel(
          this,
          drawHelper: v5,
          clr: &labelText,
          x: v7,
          y: rcLine.top + 2,
          right: false);
        Parameters = CChoreoEvent::GetParameters(this: event);
        drawHelper = atof(nptr: Parameters);
        clipped = false;
        PixelForTimeValue = CChoreoView::GetPixelForTimeValue(this: CChoreoWidget::m_pView, time: drawHelper, &clipped);
        if ( !clipped )
        {
          drawHelper = 1.3829492e-38;
          clr = (Color)9869055;
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: v5,
            (HPEN__ *)&clr,
            style: 0,
            width: 1,
            x1: PixelForTimeValue,
            y1: rcLine.top,
            x2: PixelForTimeValue,
            y2: rcLine.top + 28);
          CChoreoGlobalEventWidget::DrawLabel(
            this,
            drawHelper: v5,
            clr: &labelText,
            x: PixelForTimeValue,
            y,
            right: true);
        }
      }
    }
  }
}
