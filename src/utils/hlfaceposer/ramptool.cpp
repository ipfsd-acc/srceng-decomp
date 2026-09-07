// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/ramptool.cpp
// Functions: 52
// ============================================================

#include "utils\hlfaceposer\ramptool.h"

//------------------------------------------------------------------------------
// Address: 0x00413600
// Name: public: static bool CDefOps<class CChoreoEvent __near *>::LessFunc(class CChoreoEvent __near * const __near &,class CChoreoEvent __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<CChoreoEvent *>::LessFunc(const studiohdr_t *const *lhs, const studiohdr_t *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00459CB0
// Name: public: virtual bool RampTool::IsScrubbing(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall RampTool::IsScrubbing(GestureTool *this)
{
  return this->m_nMinX == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045AB90
// Name: public: void RampTool::DrawTimeLine(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawTimeLine(
        GestureTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rc,
        float left,
        float right)
{
  int v6; // edx
  double v8; // st7
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  const char *Name; // eax
  const char *v13; // eax
  int v14; // eax
  float v15; // xmm0_4
  int v16; // eax
  int v17; // eax
  int input; // [esp+4h] [ebp-6Ch]
  int granularity; // [esp+8h] [ebp-68h]
  char sz[32]; // [esp+14h] [ebp-5Ch] BYREF
  tagRECT rcOut; // [esp+34h] [ebp-3Ch] BYREF
  tagRECT rcLabel; // [esp+44h] [ebp-2Ch] BYREF
  float v23; // [esp+54h] [ebp-1Ch]
  float v24; // [esp+58h] [ebp-18h]
  float v25; // [esp+5Ch] [ebp-14h]
  float v26; // [esp+60h] [ebp-10h]
  float v27; // [esp+64h] [ebp-Ch]
  Color v28; // [esp+68h] [ebp-8h] BYREF
  Color clr; // [esp+6Ch] [ebp-4h] BYREF
  float f; // [esp+7Ch] [ebp+Ch]

  v6 = rc->left;
  granularity = rc->top + 2;
  input = rc->right;
  clr = (Color)13145750;
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    (HPEN__ *)&clr,
    style: 0,
    width: 1,
    x1: v6,
    y1: granularity,
    x2: input,
    y2: granularity);
  v8 = SnapTime(input: left, granularity: 0.5);
  f = v8;
  if ( right > v8 )
  {
    v9 = right - left;
    v10 = v8;
    v23 = right - left;
    do
    {
      v11 = (float)(v10 - left) / v9;
      if ( v11 >= 0.0 && v11 <= 1.0 )
      {
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        v27 = this->m_flLeftOffset
            / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                            * this->m_flPixelsPerSecond)
                    * 0.0099999998);
        v13 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        v26 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v13) * this->m_flPixelsPerSecond)
            * 0.0099999998;
        v25 = f - v27;
        v14 = mxWidget::w2(this);
        v24 = v25 / (float)((float)((float)((float)v14 / v26) + v27) - v27);
        v15 = (float)mxWidget::w2(this);
        rcLabel.top = rc->top + 5;
        rcLabel.bottom = rcLabel.top + 10;
        rcLabel.left = (int)(float)(v15 * v24);
        if ( f != left )
        {
          clr = (Color)15785180;
          v16 = mxWidget::h2(this);
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            (HPEN__ *)&clr,
            style: 2,
            width: 1,
            x1: rcLabel.left,
            y1: rc->top,
            x2: rcLabel.left,
            y2: v16);
        }
        sprintf(string: sz, format: "%.2f", f);
        v17 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz);
        rcLabel.right = v17 + rcLabel.left;
        OffsetRect(lprc: &rcLabel, dx: v17 / -2, dy: 0);
        rcOut = rcLabel;
        if ( rcLabel.left <= 0 )
          OffsetRect(lprc: &rcOut, dx: 2 - rcLabel.left, dy: 0);
        v28 = (Color)9843200;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: &v28,
          rcText: &rcOut,
          fmt: sz);
        v10 = f;
        v9 = v23;
      }
      v10 = v10 + 0.5;
      f = v10;
    }
    while ( right > v10 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477930
// Name: public: class CChoreoEvent __near * RampTool::GetSafeEvent(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall RampTool::GetSafeEvent(RampTool *this)
{
  IterateRIFF *result; // eax
  CChoreoScene *v2; // ebx
  int v3; // edi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v5; // esi

  if ( this->m_nFocusEventGlobalID == -1 || g_pChoreoView == nullptr )
    return nullptr;
  result = (IterateRIFF *)CChoreoView::GetScene(this: g_pChoreoView);
  v2 = (CChoreoScene *)result;
  if ( result != nullptr )
  {
    v3 = 0;
    if ( (int)CChoreoScene::GetNumEvents(this: result) <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        Event = CChoreoScene::GetEvent(this: v2, event: v3);
        v5 = Event;
        if ( Event != nullptr
          && CChoreoEvent::CurveHasEndTime(this: Event)
          && v5->m_nGlobalID == this->m_nFocusEventGlobalID )
        {
          break;
        }
        if ( ++v3 >= (int)CChoreoScene::GetNumEvents(this: (IterateRIFF *)v2) )
          return nullptr;
      }
      return (IterateRIFF *)v5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004779C0
// Name: public: virtual bool RampTool::IsProcessing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall RampTool::IsProcessing(RampTool *this)
{
  return RampTool::GetSafeEvent(this: (RampTool *)((char *)this - 12)) != nullptr
      && *(float *)&this->m_szWindowTitle[188] != *(float *)&this->m_bUseForMainWindowTitle;
}

//------------------------------------------------------------------------------
// Address: 0x004779F0
// Name: public: void RampTool::SetScrubTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SetScrubTime(RampTool *this, float t)
{
  CChoreoEvent *SafeEvent; // esi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrub = t;
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrub;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477A60
// Name: public: void RampTool::SetScrubTargetTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SetScrubTargetTime(RampTool *this, float t)
{
  CChoreoEvent *SafeEvent; // esi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrubTarget = t;
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrubTarget;
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477AD0
// Name: public: void RampTool::ScrubThink(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::ScrubThink(RampTool *this, float dt, bool scrubbing)
{
  float t; // xmm2_4
  float m_flScrub; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( RampTool::GetSafeEvent(this) != nullptr )
  {
    t = this->m_flScrubTarget;
    m_flScrub = this->m_flScrub;
    if ( t != m_flScrub || scrubbing )
    {
      v6 = t - m_flScrub;
      if ( (float)(t - m_flScrub) <= 0.0 )
      {
        if ( dt > COERCE_FLOAT(LODWORD(v6) ^ _mask__NegFloat_) )
          goto LABEL_6;
        v7 = m_flScrub - dt;
      }
      else
      {
        if ( dt > v6 )
        {
LABEL_6:
          RampTool::SetScrubTime(this, t);
          goto LABEL_11;
        }
        v7 = m_flScrub + dt;
      }
      RampTool::SetScrubTime(this, t: v7);
LABEL_11:
      if ( scrubbing )
        MatSysWindow::Frame(this: g_pMatSysWindow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477B60
// Name: private: void RampTool::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::CalcBounds(RampTool *this, int movetype)
{
  if ( movetype == 1 )
  {
    this->m_bUseBounds = true;
    this->m_nMinX = 0;
    this->m_nMaxX = mxWidget::w2(this);
  }
  else
  {
    this->m_bUseBounds = false;
    this->m_nMinX = 0;
    this->m_nMaxX = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477BF0
// Name: private: void RampTool::GetStartAndEndTime(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::GetStartAndEndTime(RampTool *this, float *st, float *ed)
{
  const char *Name; // eax
  const char *v6; // eax
  float sta; // [esp+14h] [ebp+8h]

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  *st = this->m_flLeftOffset
      / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
              * 0.0099999998);
  v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  sta = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6) * this->m_flPixelsPerSecond)
      * 0.0099999998;
  *ed = (float)((float)mxWidget::w2(this) / sta) + *st;
}

//------------------------------------------------------------------------------
// Address: 0x00477E80
// Name: private: void RampTool::GetSampleTrayRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::GetSampleTrayRect(RampTool *this, tagRECT *rc)
{
  rc->left = 0;
  rc->right = mxWidget::w2(this);
  rc->top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
  rc->bottom = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
}

//------------------------------------------------------------------------------
// Address: 0x00477ED0
// Name: public: struct CExpressionSample __near * RampTool::GetSampleUnderMouse(int,int,float)
// Source: json
//------------------------------------------------------------------------------
CExpressionSample *__thiscall RampTool::GetSampleUnderMouse(
        RampTool *this,
        unsigned int mx,
        unsigned int my,
        float tolerance)
{
  IterateRIFF *SafeEvent; // edi
  int v6; // ebx
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // esi
  CCurveData *p_m_chunkPosition; // edi
  int v12; // esi
  CExpressionSample *v13; // esi
  int PixelForTimeValue; // eax
  int v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  tagRECT rcSamples; // [esp+14h] [ebp-28h] BYREF
  tagPOINT pt; // [esp+24h] [ebp-18h]
  float v20; // [esp+2Ch] [ebp-10h]
  GestureTool *v21; // [esp+30h] [ebp-Ch]
  CExpressionSample *bestsample; // [esp+34h] [ebp-8h]
  float closest_dist; // [esp+38h] [ebp-4h]

  v21 = (GestureTool *)this;
  SafeEvent = RampTool::GetSafeEvent(this);
  v6 = 0;
  if ( SafeEvent == nullptr )
    return nullptr;
  rcSamples.left = 0;
  rcSamples.right = mxWidget::w2(this);
  rcSamples.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
  v8 = mxWidget::h2(this);
  v9 = -2 - this->m_nScrollbarHeight;
  v10 = my;
  rcSamples.bottom = v9 + v8;
  if ( !PtInRect(lprc: &rcSamples, pt: (POINT)__PAIR64__(my, mx)) )
    return nullptr;
  pt.y = v10 - rcSamples.top;
  p_m_chunkPosition = (CCurveData *)&SafeEvent[3].m_chunkPosition;
  closest_dist = 9999999.0;
  bestsample = nullptr;
  v12 = rcSamples.bottom - rcSamples.top;
  if ( (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_chunkPosition) > 0 )
  {
    v20 = (float)v12;
    do
    {
      v13 = CCurveData::Get(this: p_m_chunkPosition, index: v6);
      PixelForTimeValue = GestureTool::GetPixelForTimeValue(this: v21, time: v13->time, clipped: (bool *)&my + 3);
      v15 = (PixelForTimeValue - mx) * (PixelForTimeValue - mx);
      v16 = (int)(float)((float)(1.0 - v13->value) * v20) - pt.y;
      v17 = fsqrt((float)(v15 + v16 * v16));
      if ( closest_dist > v17 )
      {
        bestsample = v13;
        closest_dist = v17;
      }
      ++v6;
    }
    while ( v6 < (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_chunkPosition) );
  }
  if ( tolerance == 0.0 || closest_dist <= tolerance )
    return bestsample;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00478020
// Name: private: void RampTool::SelectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SelectAll(RampTool *this)
{
  IterateRIFF *SafeEvent; // eax
  CCurveData *p_m_chunkPosition; // edi
  int i; // esi
  CExpressionSample *v4; // eax

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    p_m_chunkPosition = (CCurveData *)&SafeEvent[3].m_chunkPosition;
    for ( i = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92)) - 1; i >= 0; --i )
    {
      v4 = CCurveData::Get(this: p_m_chunkPosition, index: i);
      *((_WORD *)v4 + 4) |= 1u;
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478070
// Name: public: void RampTool::PreDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::PreDataChanged(RampTool *this, const char *undodescription)
{
  if ( this->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: undodescription);
  }
  ++this->m_nUndoSetup;
}

//------------------------------------------------------------------------------
// Address: 0x004780B0
// Name: public: void RampTool::PostDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::PostDataChanged(RampTool *this, const char *redodescription)
{
  if ( this->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: redodescription);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004780E0
// Name: public: void RampTool::SetMousePositionForEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SetMousePositionForEvent(RampTool *this, mxEvent *event)
{
  HWND Handle; // eax
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  *(tagPOINT *)&event->x = pt;
}

//------------------------------------------------------------------------------
// Address: 0x00478120
// Name: private: void RampTool::OnEdgeProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::OnEdgeProperties(RampTool *this)
{
  IterateRIFF *SafeEvent; // edi
  CCurveData *p_m_chunkPosition; // edi
  CEdgePropertiesParams params; // [esp+8h] [ebp-1A0h] BYREF

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    _V_memset(dest: &params, fill: 0, count: 416);
    _V_strcpy(dest: params.m_szDialogTitle, src: "Edge Properties");
    p_m_chunkPosition = (CCurveData *)&SafeEvent[3].m_chunkPosition;
    CEdgePropertiesParams::SetFromCurve(this: &params, ramp: p_m_chunkPosition);
    if ( EdgeProperties(&params) != 0 )
    {
      if ( this->m_nUndoSetup == 0 )
      {
        CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
        CChoreoView::PushUndo(this: g_pChoreoView, description: "Change Event Ramp Edge Properties");
      }
      ++this->m_nUndoSetup;
      CEdgePropertiesParams::ApplyToCurve(this: &params, ramp: p_m_chunkPosition);
      if ( this->m_nUndoSetup-- == 1 )
      {
        CChoreoView::PushRedo(this: g_pChoreoView, description: "Change Event Ramp Edge Properties");
        this->redraw(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004781F0
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00478210
// Name: public: void RampTool::GetScrubHandleRect(struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::GetScrubHandleRect(GestureTool *this, tagRECT *rcHandle, float scrub, bool clipped)
{
  const char *Name; // eax
  const char *v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  float v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+4h] [ebp-8h]
  float scruba; // [esp+18h] [ebp+Ch]

  if ( mxWidget::w2(this) <= 0 )
  {
    v7 = 0.0;
  }
  else
  {
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v11 = this->m_flLeftOffset
        / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
                * 0.0099999998);
    v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v10 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6) * this->m_flPixelsPerSecond)
        * 0.0099999998;
    scruba = (float)(scrub - v11) / (float)((float)((float)((float)mxWidget::w2(this) / v10) + v11) - v11);
    v7 = (float)(int)(float)((float)mxWidget::w2(this) * scruba);
    if ( clipped )
    {
      v8 = mxWidget::w2(this) - 20;
      if ( v7 >= 20.0 )
      {
        if ( v7 > (float)v8 )
          v7 = (float)v8;
      }
      else
      {
        v7 = 20.0;
      }
    }
  }
  rcHandle->left = (int)(float)(v7 - 20.0);
  rcHandle->right = (int)(float)(v7 + 20.0);
  v9 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 2;
  rcHandle->top = v9;
  rcHandle->bottom = v9 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x00478390
// Name: public: void RampTool::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawScrubHandle(
        RampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcHandle,
        float scrub,
        Color reference)
{
  bool v5; // zf
  HBRUSH__ *SolidBrush; // eax
  int v9; // eax
  int v10; // eax
  CChoreoEvent *SafeEvent; // eax
  CChoreoEvent *v12; // ebx
  int v13; // eax
  int top; // [esp+4h] [ebp-44h]
  int bottom; // [esp+4h] [ebp-44h]
  char sz[32]; // [esp+14h] [ebp-34h] BYREF
  tagRECT rcText; // [esp+34h] [ebp-14h] BYREF
  HBRUSH__ *br; // [esp+44h] [ebp-4h]
  float st; // [esp+54h] [ebp+Ch]

  v5 = reference._color[0] == 0;
  reference = (Color)150;
  if ( v5 )
    reference = (Color)&g_flexedverts[1250].z;
  SolidBrush = CreateSolidBrush(color: reference._color[0] | ((reference._color[1] | (reference._color[2] << 8)) << 8));
  top = rcHandle->top;
  br = SolidBrush;
  reference = (Color)14477030;
  v9 = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    clr: (HPEN__ *)&reference,
    style: 0,
    width: 1,
    x1: 0,
    y1: rcHandle->top,
    x2: v9,
    y2: top);
  bottom = rcHandle->bottom;
  v10 = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    clr: (HPEN__ *)&reference,
    style: 0,
    width: 1,
    x1: 0,
    y1: rcHandle->bottom,
    x2: v10,
    y2: bottom);
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, br, rc: rcHandle);
  sprintf(string: sz, format: "%.3f", scrub);
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  v12 = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    st = CChoreoEvent::GetStartTime(this: SafeEvent);
    if ( CChoreoEvent::GetEndTime(this: v12) - st > 0.0 )
      sprintf(string: sz, format: "%.3f", (float)(st + scrub));
  }
  v13 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
  rcText = *rcHandle;
  rcText.left += (rcText.right - rcText.left - v13) / 2;
  scrub = 2.3509886e-38;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: drawHelper,
    font: "Arial",
    pointsize: 9,
    weight: 500,
    clr: (const Color *)&scrub,
    &rcText,
    fmt: sz);
  DeleteObject(ho: br);
}

//------------------------------------------------------------------------------
// Address: 0x00478520
// Name: public: bool RampTool::IsMouseOverScrubHandle(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall RampTool::IsMouseOverScrubHandle(GestureTool *this, mxEvent *event)
{
  POINT scrub; // [esp+0h] [ebp-18h]
  tagRECT rcHandle; // [esp+8h] [ebp-10h] BYREF

  RampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
  InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
  scrub.y = SLOWORD(event->y);
  scrub.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcHandle, pt: scrub);
}

//------------------------------------------------------------------------------
// Address: 0x00478570
// Name: public: virtual void RampTool::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::Think(RampTool *this, float dt)
{
  char v3; // al

  if ( RampTool::GetSafeEvent(this: (RampTool *)((char *)this - 12)) != nullptr )
  {
    v3 = ((int (__thiscall *)(RampTool *))this->redraw)(a1: this);
    RampTool::ScrubThink(this: (RampTool *)((char *)this - 12), dt, scrubbing: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004785B0
// Name: public: void RampTool::DrawScrubHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawScrubHandles(RampTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+Ch] [ebp-78h] BYREF
  tagRECT rcHandle; // [esp+64h] [ebp-20h] BYREF
  tagRECT rcTray; // [esp+74h] [ebp-10h] BYREF

  RampTool::GetScrubHandleRect((GestureTool *)this, &rcHandle, scrub: this->m_flScrub, clipped: true);
  rcTray.top = rcHandle.top;
  *(_QWORD *)&rcTray.right = *(_QWORD *)&rcHandle.right;
  rcTray.left = 0;
  rcTray.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcTray);
  RampTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00478630
// Name: private: void RampTool::ApplyBounds(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::ApplyBounds(GestureTool *this, int *mx, int *my)
{
  int m_nMinX; // edx
  int v4; // eax
  int m_nMaxX; // ecx

  if ( this->m_bUseBounds )
  {
    m_nMinX = this->m_nMinX;
    v4 = *mx;
    if ( *mx >= m_nMinX )
    {
      m_nMaxX = this->m_nMaxX;
      if ( v4 > m_nMaxX )
        v4 = m_nMaxX;
      *mx = v4;
    }
    else
    {
      *mx = m_nMinX;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478670
// Name: public: void RampTool::ForceScrubPositionFromSceneTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::ForceScrubPositionFromSceneTime(RampTool *this, float scenetime)
{
  CChoreoEvent *SafeEvent; // edi
  double v4; // st7

  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    v4 = scenetime - CChoreoEvent::GetStartTime(this: SafeEvent);
    this->m_flScrub = v4;
    this->m_flScrubTarget = v4;
    RampTool::DrawScrubHandles(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004786C0
// Name: public: void RampTool::ForceScrubPosition(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::ForceScrubPosition(RampTool *this, float t)
{
  CChoreoEvent *SafeEvent; // edi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrub = t;
  this->m_flScrubTarget = t;
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + t;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView);
  }
  RampTool::DrawScrubHandles(this);
}

//------------------------------------------------------------------------------
// Address: 0x00478750
// Name: public: void RampTool::DrawMouseOverPos(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawMouseOverPos(RampTool *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rcPos)
{
  CChoreoEvent *SafeEvent; // eax
  int v5; // eax
  int right; // edx
  int left; // ecx
  int v8; // edx
  const char *v9; // [esp+0h] [ebp-9Ch]
  char sz[128]; // [esp+8h] [ebp-94h] BYREF
  tagRECT rcText; // [esp+88h] [ebp-14h] BYREF
  float t; // [esp+98h] [ebp-4h]

  t = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: this->m_nMousePos[0], clip: false);
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    t = CChoreoEvent::GetStartTime(this: SafeEvent) + t;
    if ( t == FacePoser_SnapTime(t) )
    {
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%.3f", t);
    }
    else
    {
      v9 = FacePoser_DescribeSnappedTime(t);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v9);
    }
    v5 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0xB, weight: 900, fmt: sz);
    right = rcPos->right;
    *(_QWORD *)&rcText.left = *(_QWORD *)&rcPos->left;
    left = rcPos->left;
    v8 = right - v5;
    *(_QWORD *)&rcText.right = *(_QWORD *)&rcPos->right;
    rcText.left = left;
    if ( left <= v8 )
      rcText.left = v8;
    rcPos = (tagRECT *)((char *)&loc_4632FD + 2);
    CChoreoWidgetDrawHelper::DrawColoredText(
      this: drawHelper,
      font: "Arial",
      pointsize: 11,
      weight: 900,
      clr: (const Color *)&rcPos,
      &rcText,
      fmt: sz);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478870
// Name: public: void RampTool::DrawMouseOverPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawMouseOverPos(RampTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-68h] BYREF
  tagRECT rcPos; // [esp+5Ch] [ebp-10h] BYREF

  rcPos.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
  rcPos.left = mxWidget::w2(this) - 200;
  rcPos.right = mxWidget::w2(this) - 5;
  rcPos.bottom = rcPos.top + 13;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcPos);
  RampTool::DrawMouseOverPos(this, &drawHelper, &rcPos);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x004788E0
// Name: private: void RampTool::DrawAbsoluteTagsForEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CChoreoEvent __near *,class CChoreoEvent __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawAbsoluteTagsForEvent(
        RampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        float rc,
        CChoreoEvent *rampevent,
        CChoreoEvent *event,
        float starttime,
        float endtime)
{
  CChoreoEvent *v7; // esi
  tagRECT *v8; // ebx
  CEventAbsoluteTag *AbsoluteTag; // edi
  double Percentage; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  tagRECT *time; // xmm0_4
  int PixelForTimeValue; // esi
  Color *p_p_y; // eax
  Color v17; // edx
  int bottom; // eax
  const char *Name; // eax
  int v20; // eax
  int v21; // esi
  const char *v22; // eax
  int v23; // edi
  tagRECT rcText; // [esp+14h] [ebp-34h] BYREF
  tagRECT rcMark; // [esp+24h] [ebp-24h] BYREF
  GestureTool *v26; // [esp+34h] [ebp-14h]
  Color clr; // [esp+38h] [ebp-10h] BYREF
  int i; // [esp+3Ch] [ebp-Ch]
  float *p_y; // [esp+40h] [ebp-8h] BYREF
  int v30; // [esp+44h] [ebp-4h] BYREF

  v7 = event;
  v26 = (GestureTool *)this;
  if ( event != nullptr )
  {
    i = 0;
    if ( CChoreoEvent::GetNumAbsoluteTags(this: event, type: PLAYBACK) > 0 )
    {
      v8 = (tagRECT *)LODWORD(rc);
      do
      {
        AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: v7, type: PLAYBACK, tagnum: i);
        if ( AbsoluteTag == nullptr )
          goto LABEL_13;
        rc = v7->GetDuration(this: v7);
        Percentage = CEventAbsoluteTag::GetPercentage(this: AbsoluteTag);
        rc = Percentage * rc;
        v11 = CChoreoEvent::GetStartTime(this: v7);
        rc = v11 + rc;
        v12 = CChoreoEvent::GetStartTime(this: rampevent);
        v13 = rc - v12;
        rc = v13;
        if ( starttime > v13 )
          goto LABEL_13;
        time = (tagRECT *)LODWORD(rc);
        if ( rc > endtime )
          goto LABEL_13;
        HIBYTE(rc) = 0;
        PixelForTimeValue = GestureTool::GetPixelForTimeValue(
                              this: v26,
                              time: *(float *)&time,
                              clipped: (bool *)&rc + 3);
        if ( HIBYTE(rc) == 0 )
        {
          if ( event == rampevent )
          {
            v30 = 16409600;
            p_p_y = (Color *)&v30;
            goto LABEL_11;
          }
          if ( CChoreoEvent::GetType(this: event) != GESTURE )
          {
            p_y = &g_flexedverts[192].y;
            p_p_y = (Color *)&p_y;
LABEL_11:
            v17 = *p_p_y;
            bottom = v8->bottom;
            clr = v17;
            rcMark.top = bottom - 8;
            rcMark.left = PixelForTimeValue - 4;
            rcMark.bottom = bottom;
            rcMark.right = PixelForTimeValue + 4;
            CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &clr, inverted: false);
            rcText.left = rcMark.left;
            *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
            rcText.top = rcMark.top - 12;
            Name = CEventAbsoluteTag::GetName(this: AbsoluteTag);
            v20 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: Name);
            v21 = PixelForTimeValue - v20 / 2;
            rcText.right = v21 + v20 + 2;
            rcText.left = v21;
            rcText.bottom = rcText.top + 10;
            v22 = CEventAbsoluteTag::GetName(this: AbsoluteTag);
            CChoreoWidgetDrawHelper::DrawColoredText(
              this: drawHelper,
              font: "Arial",
              pointsize: 9,
              weight: 400,
              &clr,
              &rcText,
              fmt: v22);
          }
        }
        v7 = event;
LABEL_13:
        v23 = ++i;
      }
      while ( v23 < CChoreoEvent::GetNumAbsoluteTags(this: v7, type: PLAYBACK) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478AB0
// Name: private: void RampTool::DrawRelativeTagsForEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CChoreoEvent __near *,class CChoreoEvent __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawRelativeTagsForEvent(
        RampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        float rc,
        CChoreoEvent *rampevent,
        CChoreoEvent *event,
        float starttime,
        float endtime)
{
  CChoreoEvent *v7; // edi
  tagRECT *v8; // esi
  CEventAbsoluteTag *RelativeTag; // ebx
  double Percentage; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  tagRECT *time; // xmm0_4
  int PixelForTimeValue; // edi
  Color *p_p_y; // eax
  int bottom; // eax
  int v18; // eax
  const char *Name; // eax
  int v20; // eax
  const char *v21; // eax
  int v22; // ebx
  tagRECT rcText; // [esp+14h] [ebp-34h] BYREF
  tagRECT rcMark; // [esp+24h] [ebp-24h] BYREF
  GestureTool *v25; // [esp+34h] [ebp-14h]
  Color clr; // [esp+38h] [ebp-10h] BYREF
  int i; // [esp+3Ch] [ebp-Ch]
  float *p_y; // [esp+40h] [ebp-8h] BYREF
  int v29; // [esp+44h] [ebp-4h] BYREF

  v7 = event;
  v25 = (GestureTool *)this;
  if ( event != nullptr )
  {
    i = 0;
    if ( CChoreoEvent::GetNumRelativeTags(this: event) > 0 )
    {
      v8 = (tagRECT *)LODWORD(rc);
      do
      {
        RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: v7, tagnum: i);
        if ( RelativeTag != nullptr )
        {
          rc = v7->GetDuration(this: v7);
          Percentage = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
          rc = Percentage * rc;
          v11 = CChoreoEvent::GetStartTime(this: v7);
          rc = v11 + rc;
          v12 = CChoreoEvent::GetStartTime(this: rampevent);
          v13 = rc - v12;
          rc = v13;
          if ( starttime <= v13 )
          {
            time = (tagRECT *)LODWORD(rc);
            if ( rc <= endtime )
            {
              HIBYTE(rc) = 0;
              PixelForTimeValue = GestureTool::GetPixelForTimeValue(
                                    this: v25,
                                    time: *(float *)&time,
                                    clipped: (bool *)&rc + 3);
              if ( HIBYTE(rc) == 0 )
              {
                if ( event == rampevent )
                {
                  v29 = 16409600;
                  p_p_y = (Color *)&v29;
                }
                else
                {
                  p_y = &g_flexedverts[192].y;
                  p_p_y = (Color *)&p_y;
                }
                clr = *p_p_y;
                bottom = v8->bottom;
                rcMark.top = bottom - 8;
                rcMark.left = PixelForTimeValue - 4;
                rcMark.bottom = bottom;
                rcMark.right = PixelForTimeValue + 4;
                CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &clr, inverted: false);
                v18 = v8->bottom;
                *(_QWORD *)&rcText.left = *(_QWORD *)&v8->left;
                rcText.right = _mm_loadl_epi64((const __m128i *)&v8->right).m128i_u32[0];
                rcText.bottom = v18 - 10;
                rcText.top = v18 - 20;
                Name = CEventAbsoluteTag::GetName(this: RelativeTag);
                v20 = CChoreoWidgetDrawHelper::CalcTextWidth(
                        font: "Arial",
                        pointsize: (HFONT__ *)9,
                        weight: 400,
                        fmt: Name);
                rcText.left = PixelForTimeValue - v20 / 2;
                rcText.right = rcText.left + v20 + 2;
                v21 = CEventAbsoluteTag::GetName(this: RelativeTag);
                CChoreoWidgetDrawHelper::DrawColoredText(
                  this: drawHelper,
                  font: "Arial",
                  pointsize: 9,
                  weight: 400,
                  &clr,
                  &rcText,
                  fmt: v21);
              }
              v7 = event;
            }
          }
        }
        v22 = ++i;
      }
      while ( v22 < CChoreoEvent::GetNumRelativeTags(this: v7) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478C70
// Name: private: void RampTool::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::RepositionHSlider(RampTool *this)
{
  IterateRIFF *SafeEvent; // eax
  int v3; // edi
  const char *Name; // eax
  int v5; // eax
  int v6; // eax
  float m_flLeftOffset; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  int v9; // eax
  int v10; // [esp-8h] [ebp-14h]
  int m_nScrollbarHeight; // [esp-4h] [ebp-10h]
  float v12; // [esp+8h] [ebp-4h]

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v12 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v3 = (int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                            * this->m_flPixelsPerSecond)
                                    * 0.0099999998)
                            * v12)
                    + 10.0);
  }
  else
  {
    v3 = 0;
  }
  v5 = mxWidget::w2(this);
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: v3 > v5 - 10);
  m_nScrollbarHeight = this->m_nScrollbarHeight;
  v10 = mxWidget::w2(this) - m_nScrollbarHeight;
  v6 = mxWidget::h2(this);
  mxWidget::setBounds(
    this: this->m_pHorzScrollBar,
    x: 0,
    y: v6 - this->m_nScrollbarHeight,
    w: v10,
    h: m_nScrollbarHeight);
  m_flLeftOffset = this->m_flLeftOffset;
  if ( m_flLeftOffset < 0.0 )
    m_flLeftOffset = 0.0;
  this->m_flLeftOffset = m_flLeftOffset;
  if ( m_flLeftOffset > (float)v3 )
    m_flLeftOffset = (float)v3;
  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = m_flLeftOffset;
  mxScrollbar::setRange(this: m_pHorzScrollBar, min: 0, max: v3);
  mxScrollbar::setValue(this: this->m_pHorzScrollBar, ivalue: (int)this->m_flLeftOffset);
  v9 = mxWidget::w2(this);
  mxScrollbar::setPagesize(this: this->m_pHorzScrollBar, size: v9 - 10);
  this->m_nLastHPixelsNeeded = v3;
}

//------------------------------------------------------------------------------
// Address: 0x00478DA0
// Name: private: void RampTool::InvalidateLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::InvalidateLayout(RampTool *this)
{
  IterateRIFF *SafeEvent; // eax
  const char *Name; // eax
  void (__thiscall *redraw)(struct RampTool *); // eax
  float v5; // [esp+4h] [ebp-4h]

  if ( !this->m_bSuppressLayout )
  {
    SafeEvent = RampTool::GetSafeEvent(this);
    if ( SafeEvent != nullptr )
    {
      v5 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      SafeEvent = (IterateRIFF *)(int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(
                                                                               this: g_pChoreoView,
                                                                               tool: Name)
                                                                    * this->m_flPixelsPerSecond)
                                                            * 0.0099999998)
                                                    * v5)
                                            + 10.0);
    }
    if ( SafeEvent != (IterateRIFF *)this->m_nLastHPixelsNeeded )
      RampTool::RepositionHSlider(this);
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478E30
// Name: private: void RampTool::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::OnChangeScale(RampTool *this)
{
  const char *Name; // eax
  int TimeZoom; // eax
  int v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  int v7; // eax
  __int64 v8; // [esp+0h] [ebp-59Ch]
  CInputParams params; // [esp+10h] [ebp-58Ch] BYREF

  if ( CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
  {
    memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
    *(_QWORD *)params.m_szDialogTitle = *(_QWORD *)aChangeZ;
    strcpy(params.m_szPrompt, "New scale (e.g., 2.5x):");
    *(_DWORD *)&params.m_szDialogTitle[8] = (char *)&g_flexedverts[49579].z + 3;
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
    V_snprintf(pDest: params.m_szInputText, maxLen: 1024, pFormat: "%.2f", (float)((float)TimeZoom * 0.0099999998));
    if ( InputProperties(&params) != 0 )
    {
      v4 = (int)(atof(nptr: params.m_szInputText) * 100.0);
      if ( v4 >= 1 )
      {
        if ( v4 > 1000 )
          v4 = 1000;
      }
      else
      {
        v4 = 1;
      }
      v8 = (unsigned int)v4;
      v5 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      CChoreoView::SetTimeZoom(this: g_pChoreoView, tool: v5, tz: v8, preserveFocus: SBYTE4(v8));
      this->m_nLastHPixelsNeeded = -1;
      this->m_flLeftOffset = 0.0;
      RampTool::InvalidateLayout(this);
      v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v7 = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6);
      Con_Printf(fmt: "Zoom factor %i %%\n", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478FA0
// Name: public: void RampTool::DrawEventEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawEventEnd(RampTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  IterateRIFF *SafeEvent; // eax
  double v4; // st7
  const char *Name; // eax
  const char *v6; // eax
  int v7; // edi
  tagRECT rcSample; // [esp+4h] [ebp-1Ch] BYREF
  float v9; // [esp+14h] [ebp-Ch]
  float duration; // [esp+18h] [ebp-8h]
  Color clr; // [esp+1Ch] [ebp-4h] BYREF

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v4 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    duration = v4;
    if ( v4 != 0.0 )
    {
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      *(float *)&clr = this->m_flLeftOffset
                     / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                     * this->m_flPixelsPerSecond)
                             * 0.0099999998);
      v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v9 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6) * this->m_flPixelsPerSecond)
         * 0.0099999998;
      duration = duration - *(float *)&clr;
      v9 = duration / (float)((float)((float)((float)mxWidget::w2(this) / v9) + *(float *)&clr) - *(float *)&clr);
      v7 = (int)(float)((float)mxWidget::w2(this) * v9);
      if ( v7 < mxWidget::w2(this) )
      {
        RampTool::GetSampleTrayRect(this, rc: &rcSample);
        *(float *)&clr = 2.3418052e-38;
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: drawHelper,
          (HPEN__ *)&clr,
          style: 0,
          width: 1,
          x1: v7,
          y1: rcSample.top,
          x2: v7,
          y2: rcSample.bottom);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004790D0
// Name: public: void RampTool::DrawSamplesSimple(class CChoreoWidgetDrawHelper __near &,class CChoreoEvent __near *,bool,class Color const __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawSamplesSimple(
        RampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        CChoreoEvent *e,
        float clearbackground,
        float sampleColor,
        float rcSamples)
{
  float v6; // edi
  CChoreoEvent *v7; // esi
  float v8; // xmm0_4
  double v9; // st7
  int v10; // ebx
  float v11; // xmm0_4
  float v12; // xmm1_4
  int v13; // esi
  bool v14; // cc
  Color lineColor; // [esp+10h] [ebp-14h] BYREF
  float v16; // [esp+14h] [ebp-10h]
  float timestepperpixel; // [esp+18h] [ebp-Ch]
  int height; // [esp+1Ch] [ebp-8h]
  float prev_value; // [esp+20h] [ebp-4h]

  v6 = rcSamples;
  if ( LOBYTE(clearbackground) != 0 )
  {
    clearbackground = 1.9827462e-38;
    CChoreoWidgetDrawHelper::DrawFilledRect(
      this: drawHelper,
      clr: (const Color *)&clearbackground,
      rc: (tagRECT *)LODWORD(rcSamples));
  }
  v7 = e;
  if ( e != nullptr )
  {
    rcSamples = CChoreoEvent::GetStartTime(this: e);
    v8 = (float)(*(_DWORD *)(LODWORD(v6) + 8) - *(_DWORD *)LODWORD(v6));
    lineColor = *(Color *)LODWORD(sampleColor);
    clearbackground = v8;
    if ( v8 > 0.0 )
    {
      sampleColor = *(float *)(LODWORD(v6) + 12);
      height = LODWORD(sampleColor) - *(_DWORD *)(LODWORD(v6) + 4);
      v9 = ((double (__thiscall *)(CChoreoEvent *))e->GetDuration)(a1: e);
      timestepperpixel = v9 / clearbackground;
      prev_value = CChoreoEvent::GetIntensity(this: e, scenetime: rcSamples);
      v10 = *(_DWORD *)LODWORD(v6);
      v11 = (float)(int)*(_DWORD *)LODWORD(v6);
      v12 = (float)*(int *)(LODWORD(v6) + 8);
      clearbackground = v11;
      if ( v12 > v11 )
      {
        v16 = (float)SLODWORD(sampleColor);
        *(float *)&height = (float)height;
        while ( 1 )
        {
          sampleColor = CChoreoEvent::GetIntensity(
                          this: v7,
                          scenetime: (float)((float)(v11 - (float)(int)*(_DWORD *)LODWORD(v6)) * timestepperpixel) + rcSamples);
          v13 = (int)clearbackground;
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            clr: (HPEN__ *)&lineColor,
            style: 0,
            width: 1,
            x1: v10,
            y1: (int)(float)(v16 - (float)(*(float *)&height * prev_value)),
            x2: (int)clearbackground,
            y2: (int)(float)(v16 - (float)(*(float *)&height * sampleColor)));
          prev_value = sampleColor;
          v11 = clearbackground + 3.0;
          v14 = (float)*(int *)(LODWORD(v6) + 8) <= (float)(clearbackground + 3.0);
          v10 = v13;
          clearbackground = clearbackground + 3.0;
          if ( v14 )
            break;
          v7 = e;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479240
// Name: private: void RampTool::DrawSamples(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawSamples(RampTool *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rcSamples)
{
  RampTool *v3; // ebx
  IterateRIFF *SafeEvent; // eax
  CChoreoEvent *v5; // esi
  int v6; // eax
  const char *Name; // eax
  int TimeZoom; // eax
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // edx
  double v10; // st6
  bool v11; // cf
  double StartTime; // st7
  int PixelForTimeValue; // edi
  int v14; // eax
  int v15; // eax
  CExpressionSample *v16; // esi
  float time; // xmm0_4
  HPEN__ *v18; // ebx
  float v19; // xmm0_4
  int v20; // edi
  Color *p_clrSelected; // eax
  char *v22; // eax
  int v23; // eax
  float scenetime; // [esp+4h] [ebp-E4h]
  char sz[128]; // [esp+14h] [ebp-D4h] BYREF
  tagRECT rc; // [esp+94h] [ebp-54h] BYREF
  CCurveData *p_m_chunkPosition; // [esp+A4h] [ebp-44h]
  RampTool *v28; // [esp+A8h] [ebp-40h]
  int rampCount; // [esp+ACh] [ebp-3Ch]
  int height; // [esp+B0h] [ebp-38h]
  int bottom; // [esp+B4h] [ebp-34h]
  Color dotColorSelected; // [esp+B8h] [ebp-30h]
  Color shadowColor; // [esp+BCh] [ebp-2Ch] BYREF
  float value; // [esp+C0h] [ebp-28h]
  Color lineColor; // [esp+C4h] [ebp-24h] BYREF
  Color dotColor; // [esp+C8h] [ebp-20h]
  Color clr; // [esp+CCh] [ebp-1Ch] BYREF
  Color clrSelected; // [esp+D0h] [ebp-18h] BYREF
  int sample; // [esp+D4h] [ebp-14h]
  float stoptime; // [esp+D8h] [ebp-10h] BYREF
  bool clipped2; // [esp+DFh] [ebp-9h] BYREF
  Color t; // [esp+E0h] [ebp-8h] BYREF
  bool clipped; // [esp+E7h] [ebp-1h] BYREF

  v3 = this;
  v28 = this;
  *(float *)&t = 1.9827462e-38;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, clr: &t, rc: rcSamples);
  SafeEvent = RampTool::GetSafeEvent(this: v3);
  v5 = (CChoreoEvent *)SafeEvent;
  if ( SafeEvent != nullptr )
  {
    p_m_chunkPosition = (CCurveData *)&SafeEvent[3].m_chunkPosition;
    rampCount = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
    if ( rampCount != 0 )
    {
      RampTool::GetStartAndEndTime(this: v3, st: (float *)&t, ed: &stoptime);
      bottom = rcSamples->bottom;
      v6 = bottom - rcSamples->top;
      lineColor = (Color)16711680;
      dotColor = (Color)16711680;
      dotColorSelected = (Color)1331440;
      shadowColor = (Color)16422550;
      height = v6;
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&v3->IFacePoserToolWindow);
      TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
      GetDuration = v5->GetDuration;
      *(float *)&sample = 1.0 / (float)((float)((float)TimeZoom * v3->m_flPixelsPerSecond) * 0.0099999998);
      v10 = ((double (__thiscall *)(CChoreoEvent *))GetDuration)(a1: v5);
      if ( v10 <= stoptime )
        stoptime = v5->GetDuration(this: v5);
      clr = t;
      value = CChoreoEvent::GetIntensity(this: v5, scenetime: *(float *)&t);
      v11 = stoptime < (float)(*(float *)&t - *(float *)&sample);
      for ( *(float *)&t = *(float *)&t - *(float *)&sample; !v11; *(float *)&t = *(float *)&t + *(float *)&sample )
      {
        StartTime = CChoreoEvent::GetStartTime(this: v5);
        scenetime = StartTime + *(float *)&t;
        *(float *)&clrSelected = CChoreoEvent::GetIntensity(this: v5, scenetime);
        PixelForTimeValue = GestureTool::GetPixelForTimeValue(this: (GestureTool *)v3, time: *(float *)&t, &clipped);
        v14 = GestureTool::GetPixelForTimeValue(this: (GestureTool *)v3, time: *(float *)&clr, clipped: &clipped2);
        if ( !clipped && !clipped2 )
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            clr: (HPEN__ *)&lineColor,
            style: 0,
            width: 1,
            x1: v14,
            y1: (int)(float)((float)bottom - (float)((float)height * value)),
            x2: PixelForTimeValue,
            y2: (int)(float)((float)bottom - (float)((float)height * *(float *)&clrSelected)));
        clr = t;
        value = *(float *)&clrSelected;
        v11 = stoptime < (float)(*(float *)&t + *(float *)&sample);
      }
      *(float *)&v15 = 0.0;
      *(float *)&sample = 0.0;
      if ( rampCount > 0 )
      {
        while ( 1 )
        {
          v16 = CCurveData::Get(this: p_m_chunkPosition, index: v15);
          value = v16->value;
          time = v16->time;
          clipped = false;
          v18 = (HPEN__ *)GestureTool::GetPixelForTimeValue(this: (GestureTool *)v3, time, &clipped);
          if ( !clipped )
          {
            clr = dotColor;
            clrSelected = dotColorSelected;
            v19 = (float)bottom - (float)((float)height * value);
            v20 = (int)v19;
            p_clrSelected = &clrSelected;
            if ( (*((_WORD *)v16 + 4) & 1) == 0 )
              p_clrSelected = &clr;
            CChoreoWidgetDrawHelper::DrawCircle(
              this: drawHelper,
              clr: p_clrSelected,
              x: v18,
              y: (HBRUSH__ *)(int)v19,
              radius: (HBRUSH__ *)6,
              filled: true);
            if ( (*((_WORD *)v16 + 4) & 1) != 0 && (*((_WORD *)v16 + 4) & 0xFFFE) != 0 )
            {
              v22 = Interpolator_NameForCurveType(type: *((_WORD *)v16 + 4) >> 1, printname: true);
              V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v22);
              v23 = rcSamples->top + 2;
              if ( v20 + 5 >= v23 )
              {
                v23 = rcSamples->bottom - 11;
                if ( v20 + 5 <= v23 )
                  v23 = v20 + 5;
              }
              rc.top = v23;
              rc.bottom = v23 + 10;
              rc.left = (int)v18 - 75;
              rc.right = (int)v18 + 175;
              CChoreoWidgetDrawHelper::DrawColoredText(
                this: drawHelper,
                font: "Arial",
                pointsize: 9,
                weight: 500,
                clr: &shadowColor,
                rcText: &rc,
                fmt: sz);
            }
          }
          v15 = sample + 1;
          sample = v15;
          if ( v15 >= rampCount )
            break;
          v3 = v28;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479570
// Name: private: void RampTool::DrawAutoHighlight(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawAutoHighlight(RampTool *this, HBRUSH__ *event)
{
  IterateRIFF *SafeEvent; // edi
  IterateRIFF *v4; // edi
  CExpressionSample *v5; // edi
  float time; // xmm0_4
  HPEN__ *PixelForTimeValue; // eax
  float v8; // xmm0_4
  Color *p_clrSelected; // edx
  CChoreoWidgetDrawHelper drawHelper; // [esp+14h] [ebp-98h] BYREF
  tagRECT rcSamples; // [esp+6Ch] [ebp-40h] BYREF
  int bottom; // [esp+7Ch] [ebp-30h]
  IterateRIFF *v13; // [esp+80h] [ebp-2Ch]
  int sampleCount; // [esp+84h] [ebp-28h]
  CExpressionSample *hover; // [esp+88h] [ebp-24h]
  Color clr; // [esp+8Ch] [ebp-20h] BYREF
  int height; // [esp+90h] [ebp-1Ch]
  Color clrSelected; // [esp+94h] [ebp-18h] BYREF
  int x; // [esp+98h] [ebp-14h]
  float value; // [esp+9Ch] [ebp-10h]
  Color clrHighlighted; // [esp+A0h] [ebp-Ch] BYREF
  Color bgColor; // [esp+A4h] [ebp-8h] BYREF
  int sample; // [esp+A8h] [ebp-4h]

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    hover = RampTool::GetSampleUnderMouse(this, mx: *((_DWORD *)event + 6), my: *((_DWORD *)event + 7), tolerance: 0.0);
    rcSamples.left = 0;
    rcSamples.right = mxWidget::w2(this);
    rcSamples.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
    rcSamples.bottom = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
      this: &drawHelper,
      widget: this,
      bounds: &rcSamples,
      noPageFlip: true);
    bottom = rcSamples.bottom;
    sample = 1331440;
    height = rcSamples.bottom - rcSamples.top;
    v4 = (IterateRIFF *)((char *)SafeEvent + 92);
    HIBYTE(event) = 0;
    clrSelected = (Color)1331440;
    clrHighlighted = (Color)51200;
    clr = (Color)16711680;
    bgColor = (Color)13166310;
    v13 = v4;
    sampleCount = CAudioSourceMemWave::GetNumChannels(this: v4);
    sample = 0;
    if ( sampleCount > 0 )
    {
      while ( 1 )
      {
        v5 = CCurveData::Get(this: (CCurveData *)v4, index: sample);
        value = v5->value;
        time = v5->time;
        HIBYTE(event) = 0;
        PixelForTimeValue = (HPEN__ *)GestureTool::GetPixelForTimeValue(
                                        (GestureTool *)this,
                                        time,
                                        clipped: (bool *)&event + 3);
        x = (int)PixelForTimeValue;
        if ( HIBYTE(event) == 0 )
        {
          v8 = (float)bottom - (float)((float)height * value);
          event = (HBRUSH__ *)(int)v8;
          if ( hover == v5 )
          {
            CChoreoWidgetDrawHelper::DrawCircle(
              this: &drawHelper,
              clr: &bgColor,
              x: PixelForTimeValue,
              y: (HBRUSH__ *)(int)v8,
              radius: (HBRUSH__ *)6,
              filled: true);
            CChoreoWidgetDrawHelper::DrawCircle(
              this: &drawHelper,
              clr: &clrHighlighted,
              (HPEN__ *)x,
              y: event,
              radius: (HBRUSH__ *)6,
              filled: false);
          }
          else
          {
            p_clrSelected = &clrSelected;
            if ( (*((_WORD *)v5 + 4) & 1) == 0 )
              p_clrSelected = &clr;
            CChoreoWidgetDrawHelper::DrawCircle(
              this: &drawHelper,
              clr: p_clrSelected,
              x: PixelForTimeValue,
              y: (HBRUSH__ *)(int)v8,
              radius: (HBRUSH__ *)6,
              filled: true);
          }
        }
        if ( ++sample >= sampleCount )
          break;
        v4 = v13;
      }
    }
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479720
// Name: private: void RampTool::SelectPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SelectPoints(RampTool *this)
{
  int m_nStartX; // eax
  int m_nLastX; // ecx
  int v4; // ebx
  int m_nStartY; // eax
  int m_nLastY; // edi
  int v7; // edx
  int v8; // ecx
  int v9; // eax
  CExpressionSample *SampleUnderMouse; // eax
  int v11; // edi
  IterateRIFF *SafeEvent; // eax
  IterateRIFF *v13; // ebx
  float v14; // xmm1_4
  float v15; // xmm2_4
  const char *Name; // eax
  int TimeZoom; // eax
  CCurveData *p_m_chunkPosition; // ebx
  int i; // edi
  CExpressionSample *v20; // eax
  float v21; // xmm0_4
  tagRECT rcSelection; // [esp+10h] [ebp-2Ch] BYREF
  float epsy; // [esp+20h] [ebp-1Ch]
  float fright; // [esp+24h] [ebp-18h]
  float tolerance; // [esp+28h] [ebp-14h]
  float fleft; // [esp+2Ch] [ebp-10h]
  int height; // [esp+30h] [ebp-Ch]
  float duration; // [esp+34h] [ebp-8h]
  float v29; // [esp+38h] [ebp-4h]

  m_nStartX = this->m_nStartX;
  m_nLastX = this->m_nLastX;
  v4 = m_nStartX;
  if ( m_nStartX >= m_nLastX )
    v4 = m_nLastX;
  rcSelection.left = v4;
  if ( m_nStartX >= m_nLastX )
    m_nLastX = m_nStartX;
  m_nStartY = this->m_nStartY;
  m_nLastY = this->m_nLastY;
  rcSelection.right = m_nLastX;
  v7 = m_nStartY;
  if ( m_nStartY >= m_nLastY )
    v7 = m_nLastY;
  rcSelection.top = v7;
  if ( m_nStartY < m_nLastY )
    m_nStartY = m_nLastY;
  rcSelection.bottom = m_nStartY;
  v8 = m_nLastX - v4;
  v9 = m_nStartY - v7;
  tolerance = 5.0;
  if ( v8 > 2 || v9 > 2 )
  {
    InflateRect(lprc: &rcSelection, dx: 3, dy: 3);
  }
  else
  {
    tolerance = 30.0;
    SampleUnderMouse = RampTool::GetSampleUnderMouse(
                         this,
                         mx: (int)(float)((float)((float)v8 * 0.5) + (float)v4),
                         my: (int)(float)((float)((float)v9 * 0.5) + (float)v7),
                         tolerance: 30.0);
    if ( SampleUnderMouse != nullptr )
    {
      *((_WORD *)SampleUnderMouse + 4) |= 1u;
      return;
    }
  }
  mxWidget::w2(this);
  v11 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
  height = -2 - this->m_nScrollbarHeight + mxWidget::h2(this) - v11;
  SafeEvent = RampTool::GetSafeEvent(this);
  v13 = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    duration = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    fleft = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: rcSelection.left, clip: false);
    fright = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: rcSelection.right, clip: false);
    epsy = (float)height;
    v14 = (float)(rcSelection.top - v11) / (float)height;
    v15 = (float)(rcSelection.bottom - v11) / (float)height;
    if ( fleft >= 0.0 )
    {
      if ( fleft <= duration )
        v29 = fleft;
      else
        v29 = duration;
    }
    else
    {
      v29 = 0.0;
    }
    if ( fright >= 0.0 )
    {
      if ( fright <= duration )
        duration = fright;
    }
    else
    {
      duration = 0.0;
    }
    if ( v14 >= 0.0 )
    {
      if ( v14 <= 1.0 )
        *(float *)&height = (float)(rcSelection.top - v11) / (float)height;
      else
        *(float *)&height = 1.0;
    }
    else
    {
      *(float *)&height = 0.0;
    }
    if ( v15 >= 0.0 )
    {
      if ( v15 <= 1.0 )
        fleft = v15;
      else
        fleft = 1.0;
    }
    else
    {
      fleft = 0.0;
    }
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
    p_m_chunkPosition = (CCurveData *)&v13[3].m_chunkPosition;
    fright = (float)(1.0 / (float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)) * tolerance;
    epsy = (float)(1.0 / epsy) * tolerance;
    for ( i = 0; i < (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_chunkPosition); ++i )
    {
      v20 = CCurveData::Get(this: p_m_chunkPosition, index: i);
      if ( v29 <= (float)(v20->time + fright) && (float)(v20->time - fright) <= duration )
      {
        v21 = 1.0 - v20->value;
        if ( *(float *)&height <= (float)(v21 + epsy) && (float)(v21 - epsy) <= fleft )
          *((_WORD *)v20 + 4) |= 1u;
      }
    }
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479CA0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479D50
// Name: public: void RampTool::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::SetEvent(RampTool *this, CChoreoEvent *event)
{
  if ( this->m_bInSetEvent )
    return;
  this->m_bInSetEvent = true;
  if ( event != this->m_pLastEvent )
  {
    this->m_pLastEvent = event;
    this->m_nFocusEventGlobalID = -1;
    if ( event != nullptr )
    {
      this->m_nFocusEventGlobalID = event->m_nGlobalID;
      this->m_flLastDuration = event->GetDuration(this: event);
    }
    else
    {
      this->m_flLastDuration = 0.0;
    }
    this->m_flLeftOffset = 0.0;
    this->m_nLastHPixelsNeeded = -1;
    RampTool::InvalidateLayout(this);
    goto LABEL_11;
  }
  if ( event == nullptr )
  {
LABEL_11:
    this->m_bInSetEvent = false;
    return;
  }
  if ( ((double (__thiscall *)(CChoreoEvent *))event->GetDuration)(a1: event) != this->m_flLastDuration )
  {
    this->m_flLastDuration = event->GetDuration(this: event);
    this->m_nLastHPixelsNeeded = -1;
    this->m_flLeftOffset = 0.0;
    RampTool::InvalidateLayout(this);
  }
  this->m_nFocusEventGlobalID = event->m_nGlobalID;
  this->m_bInSetEvent = false;
}

//------------------------------------------------------------------------------
// Address: 0x00479E40
// Name: private: void RampTool::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawFocusRect(GestureTool *this)
{
  int v2; // edi
  int v3; // ebx
  tagRECT rc; // [esp+8h] [ebp-14h] BYREF
  HDC__ *dc; // [esp+18h] [ebp-4h]

  v2 = 0;
  dc = GetDC(hWnd: nullptr);
  if ( this->m_FocusRects.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      rc = this->m_FocusRects.m_Memory.m_pMemory[v3].m_rcFocus;
      DrawFocusRect(hDC: dc, lprc: &rc);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_FocusRects.m_Size );
  }
  ReleaseDC(hWnd: nullptr, hDC: dc);
}

//------------------------------------------------------------------------------
// Address: 0x00479EC0
// Name: private: void RampTool::DrawTimingTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DrawTimingTags(RampTool *this, CChoreoWidgetDrawHelper *drawHelper, int rc)
{
  CChoreoEvent *SafeEvent; // eax
  CChoreoScene *SceneFPS; // esi
  int v6; // eax
  double TimeValueForMouse; // st7
  float v8; // edi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v11; // esi
  double v12; // st7
  double v13; // st6
  tagRECT rcText; // [esp+14h] [ebp-28h] BYREF
  int c; // [esp+24h] [ebp-18h]
  CChoreoScene *scene; // [esp+28h] [ebp-14h]
  RampTool *v17; // [esp+2Ch] [ebp-10h]
  CChoreoEvent *rampevent; // [esp+30h] [ebp-Ch]
  float endtime; // [esp+34h] [ebp-8h]
  float starttime; // [esp+38h] [ebp-4h]
  float drawHelpera; // [esp+44h] [ebp+8h]
  float drawHelperb; // [esp+44h] [ebp+8h]

  v17 = this;
  SafeEvent = (CChoreoEvent *)RampTool::GetSafeEvent(this);
  rampevent = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)SafeEvent);
    scene = SceneFPS;
    if ( SceneFPS != nullptr )
    {
      starttime = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: 0, clip: false);
      v6 = mxWidget::w2(this);
      TimeValueForMouse = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: v6, clip: false);
      endtime = TimeValueForMouse;
      if ( TimeValueForMouse - starttime > 0.0 )
      {
        v8 = *(float *)&rc;
        *(_QWORD *)&rcText.left = *(_QWORD *)rc;
        rcText.right = _mm_loadl_epi64((const __m128i *)(rc + 8)).m128i_u32[0];
        rcText.bottom = rcText.top + 10;
        rc = 13132800;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          clr: (const Color *)&rc,
          &rcText,
          fmt: "Timing Tags:");
        c = CChoreoScene::GetNumEvents(this: (IterateRIFF *)SceneFPS);
        rc = 0;
        if ( c > 0 )
        {
          while ( 1 )
          {
            Event = CChoreoScene::GetEvent(this: SceneFPS, event: rc);
            v11 = Event;
            if ( Event != nullptr && CChoreoEvent::CurveHasEndTime(this: Event) )
            {
              drawHelpera = CChoreoEvent::GetEndTime(this: v11);
              v12 = CChoreoEvent::GetStartTime(this: v11);
              if ( starttime <= drawHelpera - v12 )
              {
                drawHelperb = CChoreoEvent::GetStartTime(this: v11);
                v13 = drawHelperb - CChoreoEvent::GetStartTime(this: v11);
                if ( v13 <= endtime )
                {
                  if ( CChoreoEvent::GetNumRelativeTags(this: v11) > 0 )
                    RampTool::DrawRelativeTagsForEvent(
                      this: v17,
                      drawHelper,
                      rc: v8,
                      rampevent,
                      event: v11,
                      starttime,
                      endtime);
                  if ( CChoreoEvent::GetNumAbsoluteTags(this: v11, type: PLAYBACK) > 0 )
                    RampTool::DrawAbsoluteTagsForEvent(
                      this: v17,
                      drawHelper,
                      rc: v8,
                      rampevent,
                      event: v11,
                      starttime,
                      endtime);
                }
              }
            }
            if ( ++rc >= c )
              break;
            SceneFPS = scene;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A080
// Name: private: void RampTool::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::MoveTimeSliderToPos(RampTool *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = (float)x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)(float)x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  RampTool::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047A680
// Name: public: virtual void RampTool::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::redraw(RampTool *this)
{
  int v2; // eax
  const char *Name; // eax
  int v4; // eax
  int v5; // eax
  double StartTime; // st7
  double v7; // st7
  int v8; // eax
  IFacePoserToolWindow_vtbl *v9; // edx
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v11; // eax
  IFacePoserToolWindow_vtbl *v12; // edx
  int v13; // edi
  tagRECT rcHandle; // [esp+18h] [ebp-10Ch] BYREF
  char sz[32]; // [esp+28h] [ebp-FCh] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+48h] [ebp-DCh] BYREF
  tagRECT rcTextLine; // [esp+A0h] [ebp-84h] BYREF
  tagRECT rc; // [esp+B0h] [ebp-74h] BYREF
  tagRECT rcUndo; // [esp+C0h] [ebp-64h] BYREF
  tagRECT rcSamples; // [esp+D0h] [ebp-54h] BYREF
  int current; // [esp+E0h] [ebp-44h] BYREF
  tagRECT timeRect; // [esp+E4h] [ebp-40h] BYREF
  int total; // [esp+F4h] [ebp-30h] BYREF
  CChoreoEvent *ev; // [esp+F8h] [ebp-2Ch]
  tagRECT rcTimeLine; // [esp+FCh] [ebp-28h] BYREF
  float righttime; // [esp+10Ch] [ebp-18h]
  tagRECT rcText; // [esp+110h] [ebp-14h] BYREF
  int lefttime; // [esp+120h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
    ev = (CChoreoEvent *)RampTool::GetSafeEvent(this);
    if ( ev != nullptr )
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcText);
      v2 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcText.top += v2 + 1;
      rcText.bottom = rcText.top + 13;
      rcText.left += 5;
      rcText.right -= 5;
      OffsetRect(lprc: &rcText, dx: 0, dy: 12);
      CChoreoView::GetUndoLevels(this: g_pChoreoView, &current, number: &total);
      if ( total > 0 )
      {
        rcUndo = rcText;
        OffsetRect(lprc: &rcUndo, dx: 0, dy: 2);
        lefttime = 25600;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: &drawHelper,
          font: "Small Fonts",
          pointsize: 8,
          weight: 400,
          clr: (const Color *)&lefttime,
          rcText: &rcUndo,
          fmt: "Undo:  %i/%i",
          current,
          total);
      }
      rcText.left += 60;
      rcTextLine = rcText;
      lefttime = 200;
      Name = CChoreoEvent::GetName(this: ev);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 11,
        weight: 900,
        clr: (const Color *)&lefttime,
        rcText: &rcTextLine,
        fmt: "Event:  %s",
        Name);
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcTimeLine);
      rcTimeLine.left = 0;
      rcTimeLine.right = mxWidget::w2(this);
      v4 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcTimeLine.top += v4 + 50;
      *(float *)&lefttime = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: 0, clip: false);
      v5 = mxWidget::w2(this);
      righttime = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: v5, clip: false);
      RampTool::DrawTimeLine(
        (GestureTool *)this,
        &drawHelper,
        rc: &rcTimeLine,
        left: *(float *)&lefttime,
        right: righttime);
      OffsetRect(lprc: &rcText, dx: 0, dy: 28);
      rcText.left = 5;
      *(_QWORD *)&timeRect.left = *(_QWORD *)&rcText.left;
      timeRect.bottom = rcText.bottom;
      timeRect.right = 105;
      StartTime = CChoreoEvent::GetStartTime(this: ev);
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", StartTime + *(float *)&lefttime);
      *(float *)&lefttime = 0.0;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&lefttime,
        rcText: &timeRect,
        fmt: sz);
      timeRect = rcText;
      v7 = CChoreoEvent::GetStartTime(this: ev);
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", v7 + righttime);
      righttime = COERCE_FLOAT(CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz));
      timeRect.right = mxWidget::w2(this) - 10;
      timeRect.left = timeRect.right - LODWORD(righttime);
      *(float *)&lefttime = 0.0;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 9,
        weight: 400,
        clr: (const Color *)&lefttime,
        rcText: &timeRect,
        fmt: sz);
    }
    RampTool::GetScrubHandleRect((GestureTool *)this, &rcHandle, scrub: this->m_flScrub, clipped: true);
    RampTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
    rcSamples.left = 0;
    v8 = mxWidget::w2(this);
    v9 = this->IFacePoserToolWindow::__vftable;
    rcSamples.right = v8;
    rcSamples.top = v9->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
    rcSamples.bottom = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
    RampTool::DrawSamples(this, &drawHelper, &rcSamples);
    RampTool::DrawEventEnd(this, &drawHelper);
    GetCaptionHeight = this->GetCaptionHeight;
    rcTimeLine = rc;
    v11 = GetCaptionHeight(this: &this->IFacePoserToolWindow);
    v12 = this->IFacePoserToolWindow::__vftable;
    rcTimeLine.top = v11 + 32;
    rcTimeLine.bottom = v12->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 52;
    RampTool::DrawTimingTags(this, &drawHelper, rc: (int)&rcTimeLine);
    v13 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
    rcTimeLine.top = v13;
    rcTimeLine.left = mxWidget::w2(this) - 200;
    rcTimeLine.right = mxWidget::w2(this) - 5;
    rcTimeLine.bottom = v13 + 13;
    RampTool::DrawMouseOverPos(this, &drawHelper, rcPos: &rcTimeLine);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B5B0
// Name: public: RampTool::RampTool(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
RampTool *__thiscall RampTool::RampTool(RampTool *this, mxWindow *parent)
{
  CCurveEditorHelper<RampTool> *v3; // eax
  mxScrollbar *v4; // eax
  mxScrollbar *v5; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "RampTool",
    displaynameroot: "Ramp");
  this->mxWindow::mxWidget::__vftable = (RampTool_vtbl *)&RampTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&RampTool::`vftable'{for `IFacePoserToolWindow'};
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
  v3 = (CCurveEditorHelper<RampTool> *)operator new(nSize: 4u);
  if ( v3 != nullptr )
    v3->m_pOuter = this;
  else
    v3 = nullptr;
  this->m_pHelper = v3;
  this->m_bSuppressLayout = false;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: true);
  this->m_nFocusEventGlobalID = -1;
  this->m_flScrub = 0.0;
  this->m_flScrubTarget = 0.0;
  this->m_nDragType = 0;
  this->m_nClickedX = 0;
  this->m_nClickedY = 0;
  this->m_hPrevCursor = nullptr;
  this->m_nStartX = 0;
  this->m_nStartY = 0;
  this->m_pLastEvent = nullptr;
  this->m_nMousePos[1] = 0;
  this->m_nMousePos[0] = 0;
  this->m_nMinX = 0;
  this->m_nMaxX = 0;
  this->m_bUseBounds = false;
  this->m_bLayoutIsValid = false;
  this->m_flPixelsPerSecond = 500.0;
  this->m_flLastDuration = 0.0;
  this->m_nScrollbarHeight = 12;
  this->m_flLeftOffset = 0.0;
  this->m_nLastHPixelsNeeded = -1;
  v4 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxScrollbar::mxScrollbar(this: v4, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1006, style: 0);
  else
    v5 = nullptr;
  this->m_pHorzScrollBar = v5;
  mxWidget::setVisible(this: v5, b: false);
  this->m_bInSetEvent = false;
  this->m_nUndoSetup = 0;
  this->m_flScrubberTimeOffset = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047BB60
// Name: private: void RampTool::StartDragging(int,int,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::StartDragging(RampTool *this, int dragtype, int startx, int starty, HICON__ *cursor)
{
  HICON__ *m_hPrevCursor; // eax
  int v7; // eax
  tagRECT rcScrub; // [esp+18h] [ebp-20h] BYREF
  tagRECT rcStart; // [esp+28h] [ebp-10h] BYREF

  this->m_nDragType = dragtype;
  this->m_nStartY = starty;
  this->m_nLastY = starty;
  m_hPrevCursor = this->m_hPrevCursor;
  this->m_nStartX = startx;
  this->m_nLastX = startx;
  if ( m_hPrevCursor != nullptr )
  {
    SetCursor(hCursor: m_hPrevCursor);
    this->m_hPrevCursor = nullptr;
  }
  this->m_hPrevCursor = SetCursor(hCursor: cursor);
  this->m_FocusRects.m_Size = 0;
  if ( this->m_FocusRects.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FocusRects.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FocusRects.m_Memory.m_pMemory);
      this->m_FocusRects.m_Memory.m_pMemory = nullptr;
    }
    this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FocusRects.m_pElements = this->m_FocusRects.m_Memory.m_pMemory;
  rcStart.left = startx;
  rcStart.right = startx;
  if ( dragtype == 1 )
  {
    RampTool::GetScrubHandleRect((GestureTool *)this, rcHandle: &rcScrub, scrub: this->m_flScrub, clipped: true);
    rcStart.bottom = rcScrub.bottom;
    rcStart.left = (rcScrub.right + rcScrub.left) / 2;
    rcStart.right = rcStart.left;
    rcStart.top = rcScrub.bottom;
    v7 = mxWidget::h2(this);
  }
  else
  {
    v7 = starty;
    rcStart.top = starty;
  }
  rcStart.bottom = v7;
  GestureTool::AddFocusRect((GestureTool *)this, rc: &rcStart);
  RampTool::DrawFocusRect((GestureTool *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0047BC80
// Name: private: void RampTool::MoveSelectedSamples(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::MoveSelectedSamples(RampTool *this, float dfdx, float dfdy)
{
  IterateRIFF *SafeEvent; // eax
  ICurveDataAccessor *v5; // ebx
  int i; // esi
  CExpressionSample *v7; // eax
  float v8; // xmm0_4
  int v9; // xmm1_4
  float v10; // xmm0_4
  float duration; // [esp+8h] [ebp-8h]
  int c; // [esp+Ch] [ebp-4h]

  if ( CCurveEditorHelper<RampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0 )
  {
    SafeEvent = RampTool::GetSafeEvent(this);
    v5 = (ICurveDataAccessor *)SafeEvent;
    if ( SafeEvent != nullptr )
    {
      c = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
      duration = v5->GetDuration(this: v5);
      for ( i = 0; i < c; ++i )
      {
        v7 = CCurveData::Get(this: (CCurveData *)&v5[23], index: i);
        if ( v7 != nullptr && (*((_BYTE *)v7 + 8) & 1) != 0 )
        {
          v8 = v7->time + dfdx;
          v9 = 0;
          v7->time = v8;
          if ( v8 >= 0.0 )
          {
            if ( v8 > duration )
              v8 = duration;
          }
          else
          {
            v8 = 0.0;
          }
          v7->time = v8;
          v10 = v7->value - dfdy;
          v7->value = v10;
          if ( v10 < 0.0 || (v9 = 1065353216, v10 > 1.0) )
            v10 = *(float *)&v9;
          v7->value = v10;
        }
      }
      CCurveData::Resort(this: (CCurveData *)&v5[23], data: v5);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BD60
// Name: private: void RampTool::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::DeselectAll(RampTool *this)
{
  IterateRIFF *SafeEvent; // eax
  CCurveData *p_m_chunkPosition; // edi
  int i; // esi
  CExpressionSample *v5; // eax

  if ( CCurveEditorHelper<RampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0 )
  {
    SafeEvent = RampTool::GetSafeEvent(this);
    if ( SafeEvent != nullptr )
    {
      p_m_chunkPosition = (CCurveData *)&SafeEvent[3].m_chunkPosition;
      for ( i = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92)) - 1; i >= 0; --i )
      {
        v5 = CCurveData::Get(this: p_m_chunkPosition, index: i);
        *((_WORD *)v5 + 4) &= ~1u;
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BDC0
// Name: private: void RampTool::Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::Delete(RampTool *this)
{
  IterateRIFF *SafeEvent; // edi
  IterateRIFF *v3; // edi
  int i; // esi

  SafeEvent = RampTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && CCurveEditorHelper<RampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0 )
  {
    if ( this->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Delete ramp points");
    }
    ++this->m_nUndoSetup;
    v3 = (IterateRIFF *)((char *)SafeEvent + 92);
    for ( i = CAudioSourceMemWave::GetNumChannels(this: v3) - 1; i >= 0; --i )
    {
      if ( (*((_BYTE *)CCurveData::Get(this: (CCurveData *)v3, index: i) + 8) & 1) != 0 )
        CCurveData::Delete(this: (CCurveData *)v3, index: i);
    }
    if ( this->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Delete ramp points");
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047BE70
// Name: private: void RampTool::ShowContextMenu(class mxEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::ShowContextMenu(RampTool *this, mxEvent *event, bool include_track_menus)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // esi
  const char *UndoDescription; // eax
  const char *v7; // eax
  const char *RedoDescription; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int current; // [esp+8h] [ebp-8h] BYREF
  int total; // [esp+Ch] [ebp-4h] BYREF

  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  CChoreoView::GetUndoLevels(this: g_pChoreoView, &current, number: &total);
  if ( total > 0 )
  {
    if ( current > 0 )
    {
      UndoDescription = CChoreoView::GetUndoDescription(this: g_pChoreoView);
      v7 = va(fmt: "Undo %s", UndoDescription);
      mxPopupMenu::add(this: v5, item: v7, id: 1001);
    }
    if ( current <= total - 1 )
    {
      RedoDescription = CChoreoView::GetRedoDescription(this: g_pChoreoView);
      v9 = va(fmt: "Redo %s", RedoDescription);
      mxPopupMenu::add(this: v5, item: v9, id: 1000);
    }
    mxMenu::addSeparator(this: v5);
  }
  if ( RampTool::GetSafeEvent(this) != nullptr )
  {
    if ( CCurveEditorHelper<RampTool>::CountSelected(this: this->m_pHelper, reflect: false) > 0 )
    {
      v10 = va(fmt: "Delete");
      mxPopupMenu::add(this: v5, item: v10, id: 1002);
      mxPopupMenu::add(this: v5, item: "Deselect all", id: 1003);
    }
    mxPopupMenu::add(this: v5, item: "Select all", id: 1004);
  }
  v11 = va(fmt: "Change scale...");
  mxPopupMenu::add(this: v5, item: v11, id: 1005);
  mxMenu::addSeparator(this: v5);
  mxPopupMenu::add(this: v5, item: "Edge Properties...", id: 1007);
  mxPopupMenu::popup(this: v5, widget: this, x: SLOWORD(event->x), y: SLOWORD(event->y));
}

//------------------------------------------------------------------------------
// Address: 0x0047BFC0
// Name: private: void RampTool::OnMouseMove(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RampTool::OnMouseMove(RampTool *this, mxEvent *event)
{
  mxEvent *v2; // edi
  int x_low; // ebx
  int y_low; // eax
  bool v6; // zf
  RampTool::CFocusRect *v7; // eax
  tagRECT *p_m_rcFocus; // edi
  int m_nDragType; // edx
  int m_nMinX; // eax
  int m_nLastX; // ecx
  int v12; // ebx
  HCURSOR v13; // eax
  int v14; // edi
  const char *Name; // eax
  int TimeZoom; // eax
  int m_nStartX; // eax
  int v18; // ecx
  int m_nStartY; // eax
  int m_nLastY; // ecx
  HWND Handle; // eax
  HCURSOR CursorA; // eax
  POINT dfdx; // [esp+0h] [ebp-58h]
  float dfdy; // [esp+4h] [ebp-54h]
  int rcSamples_4; // [esp+18h] [ebp-40h]
  tagRECT rcFocus; // [esp+24h] [ebp-34h] BYREF
  tagPOINT offset; // [esp+34h] [ebp-24h] BYREF
  LPRECT lprc; // [esp+3Ch] [ebp-1Ch]
  float t; // [esp+40h] [ebp-18h]
  int i; // [esp+44h] [ebp-14h]
  unsigned int v31; // [esp+48h] [ebp-10h]
  int my; // [esp+4Ch] [ebp-Ch]
  int v33; // [esp+50h] [ebp-8h]
  int mx; // [esp+54h] [ebp-4h]

  v2 = event;
  x_low = SLOWORD(event->x);
  y_low = SLOWORD(event->y);
  event->x = (__int16)x_low;
  v6 = this->m_nDragType == 0;
  mx = x_low;
  my = y_low;
  if ( v6 )
  {
    if ( this->m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: this->m_hPrevCursor);
      this->m_hPrevCursor = nullptr;
    }
    RampTool::GetScrubHandleRect((GestureTool *)this, rcHandle: &rcFocus, scrub: this->m_flScrub, clipped: true);
    InflateRect(lprc: &rcFocus, dx: 2, dy: 2);
    dfdx.y = SLOWORD(event->y);
    dfdx.x = SLOWORD(event->x);
    if ( PtInRect(lprc: &rcFocus, pt: dfdx) )
    {
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      this->m_hPrevCursor = SetCursor(hCursor: CursorA);
    }
    if ( CCurveEditorHelper<RampTool>::CountSelected(this: this->m_pHelper, reflect: false) <= 0 )
      RampTool::DrawAutoHighlight(this, (HBRUSH__ *)event);
  }
  else
  {
    RampTool::DrawFocusRect((GestureTool *)this);
    i = 0;
    if ( this->m_FocusRects.m_Size > 0 )
    {
      v31 = 0;
      do
      {
        v7 = &this->m_FocusRects.m_Memory.m_pMemory[v31 / 0x20];
        p_m_rcFocus = &v7->m_rcFocus;
        *(_QWORD *)&v7->m_rcFocus.left = *(_QWORD *)&v7->m_rcOrig.left;
        *(_QWORD *)&v7->m_rcFocus.right = *(_QWORD *)&v7->m_rcOrig.right;
        m_nDragType = this->m_nDragType;
        lprc = &v7->m_rcFocus;
        switch ( m_nDragType )
        {
          case 1:
            if ( this->m_bUseBounds )
            {
              m_nMinX = this->m_nMinX;
              if ( x_low < m_nMinX || (m_nMinX = this->m_nMaxX, x_low > m_nMinX) )
                x_low = m_nMinX;
              mx = x_low;
            }
            if ( mxWidget::w2(this) > 0 )
            {
              dfdy = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: x_low, clip: false)
                   + this->m_flScrubberTimeOffset;
              RampTool::ForceScrubPosition(this, t: dfdy);
            }
            OffsetRect(lprc: p_m_rcFocus, dx: x_low - this->m_nStartX, dy: 0);
            break;
          case 2:
          case 3:
            m_nLastX = this->m_nLastX;
            v33 = x_low - m_nLastX;
            v12 = my - this->m_nLastY;
            if ( (event->modifiers & 1) != 0 )
            {
              v13 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
              SetCursor(hCursor: v13);
            }
            else if ( m_nDragType == 2 )
            {
              v33 = 0;
              mx = m_nLastX;
            }
            else
            {
              v12 = 0;
              my = this->m_nLastY;
            }
            mxWidget::w2(this);
            rcSamples_4 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
            v14 = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
            t = (float)v33;
            Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
            TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
            RampTool::MoveSelectedSamples(
              this,
              dfdx: t / (float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998),
              dfdy: (float)v12 / (float)(v14 - rcSamples_4));
            if ( mxWidget::w2(this) > 0 )
            {
              t = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx, clip: false);
              RampTool::ForceScrubPosition(this, t);
              MatSysWindow::Frame(this: g_pMatSysWindow);
            }
            OffsetRect(lprc, dx: v33, dy: v12);
            x_low = mx;
            break;
          case 4:
            m_nStartX = this->m_nStartX;
            v18 = this->m_nLastX;
            rcFocus.left = m_nStartX;
            if ( m_nStartX < v18 )
            {
              rcFocus.right = v18;
            }
            else
            {
              rcFocus.left = v18;
              rcFocus.right = m_nStartX;
            }
            m_nStartY = this->m_nStartY;
            m_nLastY = this->m_nLastY;
            rcFocus.top = m_nStartY;
            if ( m_nStartY < m_nLastY )
            {
              rcFocus.bottom = m_nLastY;
            }
            else
            {
              rcFocus.top = m_nLastY;
              rcFocus.bottom = m_nStartY;
            }
            offset.x = 0;
            offset.y = 0;
            Handle = (HWND)mxWidget::getHandle(this);
            ClientToScreen(hWnd: Handle, lpPoint: &offset);
            OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
            *p_m_rcFocus = rcFocus;
            break;
          default:
            OffsetRect(lprc: p_m_rcFocus, dx: x_low - this->m_nStartX, dy: my - this->m_nStartY);
            break;
        }
        v31 += 32;
        ++i;
      }
      while ( i < this->m_FocusRects.m_Size );
      v2 = event;
    }
    RampTool::DrawFocusRect((GestureTool *)this);
  }
  this->m_nLastX = SLOWORD(v2->x);
  this->m_nLastY = SLOWORD(v2->y);
}

//------------------------------------------------------------------------------
// Address: 0x0047C870
// Name: public: virtual int RampTool::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall RampTool::handleEvent(RampTool *this, float event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  const char *Name; // eax
  int TimeZoom; // eax
  int v9; // ecx
  int v10; // eax
  int buttons; // edx
  int x_low; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  float v15; // xmm0_4
  double TimeValueForMouse; // st7
  double v17; // st7
  double v18; // st7
  HCURSOR CursorA; // eax
  bool v20; // bl
  HCURSOR v21; // eax
  HCURSOR v22; // eax
  float v23; // xmm1_4
  CChoreoEvent *v24; // ebx
  HCURSOR v25; // eax
  int v26; // eax
  bool v27; // zf
  int y_low; // ebx
  mxEvent *v29; // eax
  int v30; // eax
  int MaxValue; // edi
  int MinValue; // edi
  int key; // edi
  float tolerance; // [esp+Ch] [ebp-3Ch]
  float tolerancea; // [esp+Ch] [ebp-3Ch]
  tagRECT rcSamples; // [esp+1Ch] [ebp-2Ch] BYREF
  CChoreoEvent *e; // [esp+2Ch] [ebp-1Ch]
  float minVal; // [esp+30h] [ebp-18h] BYREF
  float t; // [esp+34h] [ebp-14h] BYREF
  int my; // [esp+38h] [ebp-10h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+3Ch] [ebp-Ch]
  int iret; // [esp+40h] [ebp-8h]
  bool ctrldown; // [esp+45h] [ebp-3h]
  bool rightbutton; // [esp+46h] [ebp-2h]
  bool insamplearea; // [esp+47h] [ebp-1h]

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = (mxEvent *)LODWORD(event);
  HandleToolEvent = this->HandleToolEvent;
  iret = 0;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)LODWORD(event)) )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  if ( CCurveEditorHelper<RampTool>::HelperHandleEvent(this: this->m_pHelper, event: v4) )
    goto LABEL_34;
  switch ( v4->event )
  {
    case 0:
      v30 = v4->action - 1000;
      iret = 1;
      switch ( v30 )
      {
        case 0:
          CChoreoView::Redo(this: g_pChoreoView);
          break;
        case 1:
          CChoreoView::Undo(this: g_pChoreoView);
          break;
        case 2:
          goto $LN1_10;
        case 3:
          goto $LN2_18;
        case 4:
          RampTool::SelectAll(this);
          break;
        case 5:
          RampTool::OnChangeScale(this);
          break;
        case 6:
          switch ( v4->modifiers )
          {
            case 0:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
              goto LABEL_62;
            case 1:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
              goto LABEL_67;
            case 2:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 20;
LABEL_62:
              if ( MaxValue > mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                goto LABEL_69;
              MinValue = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
              RampTool::MoveTimeSliderToPos(this, x: MinValue);
              break;
            case 3:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 20;
LABEL_67:
              if ( MaxValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                MaxValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
LABEL_69:
              RampTool::MoveTimeSliderToPos(this, x: MaxValue);
              break;
            case 5:
              RampTool::MoveTimeSliderToPos(this, x: v4->height);
              break;
            default:
              goto LABEL_78;
          }
          break;
        case 7:
          RampTool::OnEdgeProperties(this);
          break;
        default:
          iret = 0;
          break;
      }
      goto LABEL_78;
    case 1:
      this->m_nLastHPixelsNeeded = 0;
      RampTool::InvalidateLayout(this);
      iret = 1;
      goto LABEL_78;
    case 6:
      RampTool::OnMouseMove(this, event: v4);
      v27 = this->m_nDragType == 0;
      y_low = SLOWORD(v4->y);
      LODWORD(event) = SLOWORD(v4->x);
      if ( !v27 )
        RampTool::DrawFocusRect((GestureTool *)this);
      if ( this->m_hPrevCursor != nullptr )
      {
        SetCursor(hCursor: this->m_hPrevCursor);
        this->m_hPrevCursor = nullptr;
      }
      switch ( this->m_nDragType )
      {
        case 1:
          RampTool::ApplyBounds((GestureTool *)this, mx: (int *)&event, my: (int *)&event);
          if ( mxWidget::w2(this) > 0 )
          {
            tolerancea = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: SLOWORD(v4->x), clip: false)
                       + this->m_flScrubberTimeOffset;
            RampTool::ForceScrubPosition(this, t: tolerancea);
            this->m_flScrubberTimeOffset = 0.0;
          }
          break;
        case 2:
        case 3:
          RampTool::PostDataChanged(this, redodescription: "move ramp points");
          break;
        case 4:
          RampTool::SelectPoints(this);
          break;
        default:
          break;
      }
      v29 = (mxEvent *)LODWORD(event);
      this->m_nDragType = 0;
      this->m_nMousePos[0] = (int)v29;
      this->m_nMousePos[1] = y_low;
      RampTool::DrawMouseOverPos(this);
      goto LABEL_54;
    case 7:
      buttons = v4->buttons;
      x_low = SLOWORD(v4->x);
      v13 = (unsigned int)v4->modifiers >> 1;
      ctrldown = v4->modifiers & 1;
      v14 = SLOWORD(v4->y);
      HIBYTE(event) = v13 & 1;
      rightbutton = (buttons & 2) != 0;
      iret = 1;
      my = v14;
      this->m_nClickedX = x_low;
      this->m_nClickedY = v14;
      this->m_nMousePos[0] = x_low;
      this->m_nMousePos[1] = v14;
      RampTool::DrawMouseOverPos(this);
      RampTool::GetSampleTrayRect(this, rc: &rcSamples);
      insamplearea = PtInRect(lprc: &rcSamples, pt: (POINT)__PAIR64__(my, x_low));
      if ( this->m_nDragType != 0 )
        goto LABEL_78;
      if ( (v4->modifiers & 1) != 0 )
        v15 = 5.0;
      else
        v15 = 30.0;
      t = COERCE_FLOAT(RampTool::GetSampleUnderMouse(this, mx: v4->x, my: v4->y, tolerance: v15));
      if ( RampTool::IsMouseOverScrubHandle((GestureTool *)this, event: v4) )
      {
        if ( mxWidget::w2(this) > 0 )
        {
          TimeValueForMouse = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: SLOWORD(v4->x), clip: false);
          t = TimeValueForMouse;
          this->m_flScrubberTimeOffset = this->m_flScrub - TimeValueForMouse;
          v17 = 20.0 / GestureTool::GetPixelsPerSecond((GestureTool *)this);
          event = v17;
          *(float *)&my = -v17;
          v18 = clamp<float,float,float>(val: &this->m_flScrubberTimeOffset, minVal: (const float *)&my, maxVal: &event);
          this->m_flScrubberTimeOffset = v18;
          tolerance = v18 + t;
          RampTool::ForceScrubPosition(this, t: tolerance);
        }
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        RampTool::StartDragging(
          this,
          dragtype: 1,
          startx: this->m_nClickedX,
          starty: this->m_nClickedY,
          cursor: CursorA);
        RampTool::CalcBounds(this, movetype: this->m_nDragType);
        goto LABEL_78;
      }
      if ( !insamplearea )
      {
        if ( (v4->buttons & 2) != 0 )
        {
          RampTool::ShowContextMenu(this, event: v4, include_track_menus: false);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        if ( mxWidget::w2(this) > 0 )
        {
          event = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: SLOWORD(v4->x), clip: false);
          RampTool::SetScrubTargetTime(this, t: event);
        }
LABEL_27:
        RampTool::CalcBounds(this, movetype: this->m_nDragType);
        goto LABEL_78;
      }
      if ( t != 0.0 )
      {
        if ( HIBYTE(event) != 0 )
        {
          *(_WORD *)(LODWORD(t) + 8) ^= ((unsigned __int8)*(_WORD *)(LODWORD(t) + 8)
                                       ^ (unsigned __int8)~(unsigned __int8)*(_WORD *)(LODWORD(t) + 8))
                                      & 1;
          this->redraw(this);
          RampTool::CalcBounds(this, movetype: this->m_nDragType);
          goto LABEL_78;
        }
        if ( (*(_BYTE *)(LODWORD(t) + 8) & 1) != 0 )
        {
          RampTool::PreDataChanged(this, undodescription: "move ramp points");
          v20 = rightbutton;
          v21 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)(!rightbutton + 32644));
          RampTool::StartDragging(
            this,
            dragtype: v20 + 2,
            startx: this->m_nClickedX,
            starty: this->m_nClickedY,
            cursor: v21);
        }
        else
        {
          RampTool::DeselectAll(this);
          v22 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
          RampTool::StartDragging(this, dragtype: 4, startx: this->m_nClickedX, starty: this->m_nClickedY, cursor: v22);
        }
        goto LABEL_27;
      }
      if ( !ctrldown )
      {
        if ( (v4->buttons & 2) == 0 )
        {
          if ( HIBYTE(event) == 0 )
            RampTool::DeselectAll(this);
          v25 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
          RampTool::StartDragging(this, dragtype: 4, startx: this->m_nClickedX, starty: this->m_nClickedY, cursor: v25);
          RampTool::CalcBounds(this, movetype: this->m_nDragType);
          goto LABEL_78;
        }
        RampTool::ShowContextMenu(this, event: v4, include_track_menus: false);
LABEL_34:
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      e = (CChoreoEvent *)RampTool::GetSafeEvent(this);
      if ( e == nullptr )
        goto LABEL_27;
      *(float *)&my = GestureTool::GetTimeValueForMouse((GestureTool *)this, mx: x_low, clip: false);
      *(float *)&my = FacePoser_SnapTime(t: *(float *)&my);
      v23 = (float)(SLOWORD(v4->y) - rcSamples.top) / (float)(rcSamples.bottom - rcSamples.top);
      t = 1.0;
      event = 1.0 - v23;
      minVal = 0.0;
      event = clamp<float,float,float>(val: &event, &minVal, maxVal: &t);
      RampTool::PreDataChanged(this, undodescription: "Add ramp point");
      v24 = e;
      CCurveData::Add(this: &e->m_Ramp, time: *(float *)&my, value: event, selected: false);
      CCurveData::Resort(this: &v24->m_Ramp, data: v24);
      RampTool::PostDataChanged(this, redodescription: "Add ramp point");
      RampTool::CalcBounds(this, movetype: this->m_nDragType);
LABEL_78:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return iret;
    case 8:
    case 9:
      v26 = SLOWORD(v4->y);
      this->m_nMousePos[0] = SLOWORD(v4->x);
      this->m_nMousePos[1] = v26;
      RampTool::DrawMouseOverPos(this);
      RampTool::OnMouseMove(this, event: v4);
      iret = 1;
      goto LABEL_78;
    case 0xB:
      key = v4->key;
      iret = 1;
      if ( key == 27 )
      {
$LN2_18:
        RampTool::DeselectAll(this);
      }
      else if ( key == 46 )
      {
$LN1_10:
        RampTool::Delete(this);
      }
      else
      {
        iret = CChoreoView::HandleZoomKey<RampTool>(this: g_pChoreoView, other: this, keyCode: key);
      }
      goto LABEL_78;
    case 0xC:
      if ( CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
      {
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
        TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
        v9 = (4 * ((v4->modifiers & 2) != 0)) | 1;
        if ( v4->height <= 0 )
        {
          v10 = TimeZoom - 2 * v9;
          if ( v10 <= 2 )
            v10 = 2;
        }
        else
        {
          v10 = TimeZoom + 2 * v9;
          if ( v10 >= 1000 )
          {
            CChoreoView::SetPreservedTimeZoom<RampTool>(this: g_pChoreoView, other: this, tz: 1000);
            goto LABEL_54;
          }
        }
        CChoreoView::SetPreservedTimeZoom<RampTool>(this: g_pChoreoView, other: this, tz: v10);
      }
LABEL_54:
      this->redraw(this);
      iret = 1;
      goto LABEL_78;
    default:
      goto LABEL_78;
  }
}
