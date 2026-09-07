// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/gesturetool.cpp
// Functions: 40
// ============================================================

#include "utils\hlfaceposer\gesturetool.h"

//------------------------------------------------------------------------------
// Address: 0x00459BF0
// Name: public: class CChoreoEvent __near * GestureTool::GetSafeEvent(void)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall GestureTool::GetSafeEvent(GestureTool *this)
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
          && CChoreoEvent::GetType(this: Event) == GESTURE
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
// Address: 0x00459C80
// Name: public: virtual bool GestureTool::IsProcessing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GestureTool::IsProcessing(GestureTool *this)
{
  return GestureTool::GetSafeEvent(this: (GestureTool *)((char *)this - 12)) != nullptr
      && *(float *)&this->m_szWindowTitle[188] != *(float *)&this->m_bUseForMainWindowTitle;
}

//------------------------------------------------------------------------------
// Address: 0x00459CC0
// Name: public: void GestureTool::SetScrubTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::SetScrubTime(GestureTool *this, float t)
{
  CChoreoEvent *SafeEvent; // esi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrub = t;
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrub;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459D30
// Name: public: void GestureTool::SetScrubTargetTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::SetScrubTargetTime(GestureTool *this, float t)
{
  CChoreoEvent *SafeEvent; // esi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrubTarget = t;
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + this->m_flScrubTarget;
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459DA0
// Name: public: void GestureTool::ScrubThink(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::ScrubThink(GestureTool *this, float dt, bool scrubbing)
{
  float t; // xmm2_4
  float m_flScrub; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( GestureTool::GetSafeEvent(this) != nullptr )
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
          GestureTool::SetScrubTime(this, t);
          goto LABEL_11;
        }
        v7 = m_flScrub + dt;
      }
      GestureTool::SetScrubTime(this, t: v7);
LABEL_11:
      if ( scrubbing )
        MatSysWindow::Frame(this: g_pMatSysWindow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459E30
// Name: private: int GestureTool::GetTagTypeForTag(class CEventAbsoluteTag const __near *)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent::AbsTagType __thiscall GestureTool::GetTagTypeForTag(GestureTool *this, const CEventAbsoluteTag *tag)
{
  CChoreoEvent *SafeEvent; // ebx
  CChoreoEvent::AbsTagType v4; // edi
  int v5; // esi

  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent == nullptr )
    return INVALID;
  v4 = PLAYBACK;
  while ( 1 )
  {
    v5 = 0;
    if ( CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: v4) > 0 )
      break;
LABEL_7:
    if ( ++v4 >= NUM_ABS_TAG_TYPES )
      return INVALID;
  }
  while ( CChoreoEvent::GetAbsoluteTag(this: SafeEvent, type: v4, tagnum: v5) != tag )
  {
    if ( ++v5 >= CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: v4) )
      goto LABEL_7;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00459EA0
// Name: private: void GestureTool::OnRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnRevert(GestureTool *this)
{
  GestureTool *v1; // ebx
  CChoreoEvent *SafeEvent; // eax
  CChoreoEvent *v3; // edi
  int NumAbsoluteTags; // esi
  int v5; // esi
  CEventAbsoluteTag *AbsoluteTag; // ebx
  float percentage; // [esp+0h] [ebp-1Ch]
  int c; // [esp+14h] [ebp-8h]
  CEventAbsoluteTag *playback; // [esp+18h] [ebp-4h]

  v1 = this;
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  v3 = SafeEvent;
  if ( SafeEvent != nullptr && CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: PLAYBACK) != 0 )
  {
    NumAbsoluteTags = CChoreoEvent::GetNumAbsoluteTags(this: v3, type: ORIGINAL);
    if ( CChoreoEvent::GetNumAbsoluteTags(this: v3, type: PLAYBACK) == NumAbsoluteTags )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Revert Gesture Tags");
      v5 = 0;
      c = CChoreoEvent::GetNumAbsoluteTags(this: v3, type: PLAYBACK);
      if ( c > 0 )
      {
        do
        {
          AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: v3, type: ORIGINAL, tagnum: v5);
          playback = CChoreoEvent::GetAbsoluteTag(this: v3, type: PLAYBACK, tagnum: v5);
          percentage = CEventAbsoluteTag::GetPercentage(this: AbsoluteTag);
          CEventAbsoluteTag::SetPercentage(this: playback, percentage);
          ++v5;
        }
        while ( v5 < c );
        v1 = this;
      }
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Revert Gesture Tags");
      v1->redraw(this: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00459F80
// Name: public: void GestureTool::GetScrubHandleReferenceRect(struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::GetScrubHandleReferenceRect(
        GestureTool *this,
        tagRECT *rcHandle,
        float scrub,
        bool clipped)
{
  char *Name; // eax
  char *v6; // eax
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
  v9 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 197;
  rcHandle->top = v9;
  rcHandle->bottom = v9 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x0045A100
// Name: public: void GestureTool::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawScrubHandle(
        GestureTool *this,
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
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
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
// Address: 0x0045A290
// Name: public: virtual void GestureTool::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::Think(GestureTool *this, float dt)
{
  char v3; // al

  if ( GestureTool::GetSafeEvent(this: (GestureTool *)((char *)this - 12)) != nullptr )
  {
    v3 = ((int (__thiscall *)(GestureTool *))this->redraw)(a1: this);
    GestureTool::ScrubThink(this: (GestureTool *)((char *)this - 12), dt, scrubbing: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A2D0
// Name: public: void GestureTool::DrawScrubHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawScrubHandles(GestureTool *this)
{
  IterateRIFF *SafeEvent; // eax
  CChoreoEvent *v3; // edi
  double v4; // st7
  float t; // [esp+4h] [ebp-E0h]
  CChoreoWidgetDrawHelper drawHelper; // [esp+10h] [ebp-D4h] BYREF
  CChoreoWidgetDrawHelper v7; // [esp+68h] [ebp-7Ch] BYREF
  tagRECT rcHandle; // [esp+C0h] [ebp-24h] BYREF
  tagRECT rcTray; // [esp+D0h] [ebp-14h] BYREF
  float scrub; // [esp+E0h] [ebp-4h]

  RampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
  rcTray.top = rcHandle.top;
  *(_QWORD *)&rcTray.right = *(_QWORD *)&rcHandle.right;
  rcTray.left = 0;
  rcTray.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcTray);
  GestureTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
  SafeEvent = GestureTool::GetSafeEvent(this);
  v3 = (CChoreoEvent *)SafeEvent;
  if ( SafeEvent != nullptr && ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent) > 0.0 )
  {
    t = this->m_flScrub / ((double (__thiscall *)(CChoreoEvent *))v3->GetDuration)(a1: v3);
    scrub = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: v3, t);
    v4 = ((double (__thiscall *)(CChoreoEvent *))v3->GetDuration)(a1: v3);
    scrub = v4 * scrub;
    GestureTool::GetScrubHandleReferenceRect(this, &rcHandle, scrub, clipped: true);
    rcTray.top = rcHandle.top;
    *(_QWORD *)&rcTray.right = *(_QWORD *)&rcHandle.right;
    rcTray.left = 0;
    rcTray.right = mxWidget::w2(this);
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &v7, widget: this, bounds: &rcTray);
    GestureTool::DrawScrubHandle(this, drawHelper: &v7, &rcHandle, scrub, reference: (Color)1);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &v7);
  }
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0045A420
// Name: public: void GestureTool::ForceScrubPositionFromSceneTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::ForceScrubPositionFromSceneTime(GestureTool *this, float scenetime)
{
  CChoreoEvent *SafeEvent; // edi
  double v4; // st7

  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    v4 = scenetime - CChoreoEvent::GetStartTime(this: SafeEvent);
    this->m_flScrub = v4;
    this->m_flScrubTarget = v4;
    GestureTool::DrawScrubHandles(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A470
// Name: public: void GestureTool::ForceScrubPosition(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::ForceScrubPosition(GestureTool *this, float t)
{
  CChoreoEvent *SafeEvent; // edi
  float realtime; // [esp+14h] [ebp+8h]

  this->m_flScrub = t;
  this->m_flScrubTarget = t;
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
  {
    realtime = CChoreoEvent::GetStartTime(this: SafeEvent) + t;
    CChoreoView::SetScrubTime(this: g_pChoreoView, t: realtime);
    CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: realtime);
    CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2: (int)SafeEvent);
  }
  GestureTool::DrawScrubHandles(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045A500
// Name: public: void GestureTool::DrawMouseOverPos(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawMouseOverPos(GestureTool *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rcPos)
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

  t = GestureTool::GetTimeValueForMouse(this, mx: this->m_nMousePos[0], clip: false);
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
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
    rcPos = (tagRECT *)(&loc_4632FD + 2);
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
// Address: 0x0045A620
// Name: public: void GestureTool::DrawMouseOverPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawMouseOverPos(GestureTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-68h] BYREF
  tagRECT rcPos; // [esp+5Ch] [ebp-10h] BYREF

  rcPos.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
  rcPos.left = mxWidget::w2(this) - 200;
  rcPos.right = mxWidget::w2(this) - 5;
  rcPos.bottom = rcPos.top + 13;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcPos);
  GestureTool::DrawMouseOverPos(this, &drawHelper, &rcPos);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0045A690
// Name: public: bool GestureTool::GetAbsTagRect(struct tagRECT __near &,class CChoreoEvent __near *,int,class CEventAbsoluteTag __near *,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GestureTool::GetAbsTagRect(
        GestureTool *this,
        tagRECT *rcClient,
        CChoreoEvent *event,
        int tagtype,
        CEventAbsoluteTag *tag,
        float rcTag)
{
  tagRECT *v6; // eax
  tagRECT *v7; // esi
  bool v9; // zf
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // edx
  double Percentage; // st7
  int PixelForTimeValue; // eax

  v6 = rcClient;
  v7 = (tagRECT *)LODWORD(rcTag);
  *(tagRECT *)LODWORD(rcTag) = *rcClient;
  *v7 = *v6;
  v7->top += this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 110;
  v9 = tagtype == 1;
  v7->bottom = v7->top + 6;
  if ( v9 )
    OffsetRect(lprc: v7, dx: 0, dy: 45);
  GetDuration = event->GetDuration;
  HIBYTE(rcClient) = 0;
  rcTag = GetDuration(this: event);
  Percentage = CEventAbsoluteTag::GetPercentage(this: tag);
  rcTag = Percentage * rcTag;
  PixelForTimeValue = GestureTool::GetPixelForTimeValue(this, time: rcTag, clipped: (bool *)&rcClient + 3);
  v9 = HIBYTE(rcClient) == 0;
  v7->right = PixelForTimeValue + 3;
  v7->left = PixelForTimeValue - 3;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0045A740
// Name: public: void GestureTool::DrawAbsoluteTags(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawAbsoluteTags(GestureTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoEvent *SafeEvent; // esi
  CChoreoWidgetDrawHelper *v3; // edi
  int NumAbsoluteTags; // ebx
  CChoreoEvent::AbsTagType j; // ebx
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v7; // eax
  int top; // eax
  const char *v9; // eax
  int (__thiscall *v10)(IFacePoserToolWindow *); // eax
  int v11; // eax
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // edx
  double Percentage; // st7
  int PixelForTimeValue; // eax
  CEventAbsoluteTag *AbsoluteTag; // eax
  const char *Name; // eax
  int v17; // esi
  double v18; // st7
  int v19; // eax
  int v20; // eax
  char text[256]; // [esp+14h] [ebp-194h] BYREF
  tagRECT rcMark2; // [esp+114h] [ebp-94h] BYREF
  tagRECT rcClient; // [esp+124h] [ebp-84h] BYREF
  tagRECT rcText; // [esp+134h] [ebp-74h] BYREF
  CChoreoEvent *event; // [esp+144h] [ebp-64h]
  tagRECT rcTray; // [esp+148h] [ebp-60h] BYREF
  CEventAbsoluteTag *tag; // [esp+158h] [ebp-50h]
  float time; // [esp+15Ch] [ebp-4Ch]
  tagRECT v29; // [esp+160h] [ebp-48h] BYREF
  Color v30; // [esp+170h] [ebp-38h] BYREF
  GestureTool *v31; // [esp+174h] [ebp-34h]
  Color clr; // [esp+178h] [ebp-30h] BYREF
  Color v33; // [esp+17Ch] [ebp-2Ch] BYREF
  Color p_z; // [esp+180h] [ebp-28h] BYREF
  tagRECT rcMark; // [esp+184h] [ebp-24h] BYREF
  Color v36; // [esp+194h] [ebp-14h] BYREF
  Color fill; // [esp+198h] [ebp-10h] BYREF
  Color v38; // [esp+19Ch] [ebp-Ch] BYREF
  int i; // [esp+1A0h] [ebp-8h]
  bool showDots; // [esp+1A7h] [ebp-1h]

  v31 = this;
  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  event = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    v3 = drawHelper;
    CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcClient);
    showDots = true;
    NumAbsoluteTags = CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: ORIGINAL);
    if ( CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: PLAYBACK) != NumAbsoluteTags )
      showDots = false;
    for ( j = PLAYBACK; j < NUM_ABS_TAG_TYPES; ++j )
    {
      GetCaptionHeight = v31->GetCaptionHeight;
      rcTray = rcClient;
      v7 = GetCaptionHeight(this: &v31->IFacePoserToolWindow);
      top = rcTray.top + v7 + 110;
      rcTray.top = top;
      rcTray.bottom = top + 6;
      if ( j == ORIGINAL )
      {
        OffsetRect(lprc: &rcTray, dx: 0, dy: 45);
        top = rcTray.top;
      }
      clr = (Color)14474460;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v3,
        (HPEN__ *)&clr,
        style: 0,
        width: 1,
        x1: rcTray.left,
        y1: top,
        x2: rcTray.right,
        y2: top);
      v30 = (Color)14474460;
      CChoreoWidgetDrawHelper::DrawColoredLine(
        this: v3,
        clr: (HPEN__ *)&v30,
        style: 0,
        width: 1,
        x1: rcTray.left,
        y1: rcTray.bottom,
        x2: rcTray.right,
        y2: rcTray.bottom);
      rcText = rcTray;
      InflateRect(lprc: &rcText, dx: 0, dy: 4);
      OffsetRect(lprc: &rcText, dx: 0, dy: j != PLAYBACK ? 10 : -10);
      rcText.left = 2;
      v9 = "Playback Time";
      if ( j != PLAYBACK )
        v9 = "Original Time";
      v36 = (Color)9868950;
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: v3,
        font: "Arial",
        pointsize: 9,
        weight: 500,
        clr: &v36,
        &rcText,
        fmt: "%s",
        v9);
      i = 0;
      if ( CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: j) > 0 )
      {
        do
        {
          tag = CChoreoEvent::GetAbsoluteTag(this: SafeEvent, type: j, tagnum: i);
          if ( tag != nullptr )
          {
            v10 = v31->GetCaptionHeight;
            rcMark = rcClient;
            v11 = v10(this: &v31->IFacePoserToolWindow);
            rcMark.top += v11 + 110;
            rcMark.bottom = rcMark.top + 6;
            if ( j == ORIGINAL )
              OffsetRect(lprc: &rcMark, dx: 0, dy: 45);
            GetDuration = SafeEvent->GetDuration;
            HIBYTE(drawHelper) = 0;
            time = GetDuration(this: SafeEvent);
            Percentage = CEventAbsoluteTag::GetPercentage(this: tag);
            time = Percentage * time;
            PixelForTimeValue = GestureTool::GetPixelForTimeValue(this: v31, time, clipped: (bool *)&drawHelper + 3);
            rcMark.left = PixelForTimeValue - 3;
            HIBYTE(drawHelper) = HIBYTE(drawHelper) == 0;
            rcMark.right = PixelForTimeValue + 3;
            if ( showDots && j == ORIGINAL )
            {
              AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: SafeEvent, type: PLAYBACK, tagnum: i);
              if ( AbsoluteTag != nullptr )
              {
                GestureTool::GetAbsTagRect(
                  this: v31,
                  &rcClient,
                  event: SafeEvent,
                  tagtype: 0,
                  tag: AbsoluteTag,
                  rcTag: COERCE_FLOAT(&rcMark2));
                v33 = (Color)13158600;
                CChoreoWidgetDrawHelper::DrawColoredLine(
                  this: v3,
                  clr: (HPEN__ *)&v33,
                  style: 0,
                  width: 1,
                  x1: (rcMark.right + rcMark.left) / 2,
                  y1: rcMark.top,
                  x2: (rcMark2.right + rcMark2.left) / 2,
                  y2: rcMark2.bottom);
              }
            }
            if ( HIBYTE(drawHelper) != 0 )
            {
              fill = (Color)1966280;
              CChoreoWidgetDrawHelper::DrawTriangleMarker(this: v3, rc: &rcMark, &fill, inverted: j != PLAYBACK);
              v29 = rcMark;
              if ( j != PLAYBACK )
                v29.top = rcMark.top + 10;
              else
                v29.top = rcMark.top - 15;
              Name = CEventAbsoluteTag::GetName(this: tag);
              sprintf(string: text, format: "%s", Name);
              v17 = CChoreoWidgetDrawHelper::CalcTextWidth(
                      font: "Arial",
                      pointsize: (HFONT__ *)9,
                      weight: 400,
                      fmt: text);
              p_z = (Color)&g_flexedverts[200].z;
              v29.left = (rcMark.right + rcMark.left) / 2 - v17 / 2;
              v29.right = v29.left + v17 + 2;
              v29.bottom = v29.top + 10;
              CChoreoWidgetDrawHelper::DrawColoredText(
                this: v3,
                font: "Arial",
                pointsize: 9,
                weight: 400,
                clr: &p_z,
                rcText: &v29,
                fmt: text);
              if ( j != PLAYBACK )
                v29.top += 10;
              else
                v29.top -= 10;
              v18 = CEventAbsoluteTag::GetPercentage(this: tag);
              sprintf(string: text, format: "%.3f", v18);
              v19 = CChoreoWidgetDrawHelper::CalcTextWidth(
                      font: "Arial",
                      pointsize: (HFONT__ *)9,
                      weight: 400,
                      fmt: text);
              v38 = (Color)&g_flexedverts[200].z;
              v29.left = (rcMark.right + rcMark.left) / 2 - v19 / 2;
              v29.right = v29.left + v19 + 2;
              v29.bottom = v29.top + 10;
              CChoreoWidgetDrawHelper::DrawColoredText(
                this: v3,
                font: "Arial",
                pointsize: 9,
                weight: 400,
                clr: &v38,
                rcText: &v29,
                fmt: text);
              SafeEvent = event;
            }
          }
          ++i;
          v20 = CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: j);
        }
        while ( i < v20 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045AE20
// Name: private: class CEventAbsoluteTag __near * GestureTool::IsMouseOverTag(int,int)
// Source: json
//------------------------------------------------------------------------------
IterateRIFF *__thiscall GestureTool::IsMouseOverTag(GestureTool *this, unsigned int mx, unsigned int my)
{
  IterateRIFF *result; // eax
  CChoreoEvent *v5; // edi
  HWND Handle; // eax
  CChoreoEvent::AbsTagType v7; // esi
  CEventAbsoluteTag *AbsoluteTag; // eax
  CEventAbsoluteTag *v9; // ebx
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v11; // eax
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // edx
  double Percentage; // st7
  int PixelForTimeValue; // eax
  int v15; // ebx
  tagRECT rcClient; // [esp+14h] [ebp-30h] BYREF
  tagRECT rcTag; // [esp+24h] [ebp-20h] BYREF
  float time; // [esp+34h] [ebp-10h]
  GestureTool *v19; // [esp+38h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-8h]
  bool clipped; // [esp+43h] [ebp-1h] BYREF

  v19 = this;
  result = GestureTool::GetSafeEvent(this);
  v5 = (CChoreoEvent *)result;
  if ( result != nullptr )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    GetClientRect(hWnd: Handle, lpRect: &rcClient);
    v7 = PLAYBACK;
    while ( 1 )
    {
      i = 0;
      if ( CChoreoEvent::GetNumAbsoluteTags(this: v5, type: v7) > 0 )
        break;
LABEL_11:
      if ( ++v7 >= NUM_ABS_TAG_TYPES )
        return nullptr;
    }
    while ( 1 )
    {
      AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: v5, type: v7, tagnum: i);
      v9 = AbsoluteTag;
      if ( AbsoluteTag != nullptr && !CEventAbsoluteTag::GetLocked(this: AbsoluteTag) )
      {
        GetCaptionHeight = v19->GetCaptionHeight;
        rcTag = rcClient;
        v11 = GetCaptionHeight(this: &v19->IFacePoserToolWindow);
        rcTag.top += v11 + 110;
        rcTag.bottom = rcTag.top + 6;
        if ( v7 == ORIGINAL )
          OffsetRect(lprc: &rcTag, dx: 0, dy: 45);
        GetDuration = v5->GetDuration;
        clipped = false;
        time = GetDuration(this: v5);
        Percentage = CEventAbsoluteTag::GetPercentage(this: v9);
        time = Percentage * time;
        PixelForTimeValue = GestureTool::GetPixelForTimeValue(this: v19, time, &clipped);
        rcTag.left = PixelForTimeValue - 3;
        rcTag.right = PixelForTimeValue + 3;
        if ( !clipped && PtInRect(lprc: &rcTag, pt: (POINT)__PAIR64__(my, mx)) )
          return (IterateRIFF *)v9;
      }
      v15 = ++i;
      if ( v15 >= CChoreoEvent::GetNumAbsoluteTags(this: v5, type: v7) )
        goto LABEL_11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045AF70
// Name: private: void GestureTool::OnInsertTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnInsertTag(GestureTool *this)
{
  CChoreoEvent *SafeEvent; // eax
  CChoreoEvent *v3; // esi
  double v4; // st7
  CInputParams params; // [esp+Ch] [ebp-594h] BYREF
  float tshifted; // [esp+598h] [ebp-8h]
  float t; // [esp+59Ch] [ebp-4h]

  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  v3 = SafeEvent;
  if ( SafeEvent != nullptr )
  {
    if ( CChoreoEvent::GetType(this: SafeEvent) == GESTURE )
    {
      memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
      strcpy(params.m_szDialogTitle, "Absolute Tag Name");
      strcpy(params.m_szPrompt, "Name:");
      params.m_szInputText[0] = 0;
      if ( InputProperties(&params) != 0 )
      {
        if ( strlen(params.m_szInputText) != 0 )
        {
          t = GestureTool::GetTimeValueForMouse(this, mx: this->m_nClickedX, clip: false);
          v4 = ((double (__thiscall *)(CChoreoEvent *))v3->GetDuration)(a1: v3);
          t = t / v4;
          tshifted = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: v3, t);
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Add Gesture Tag");
          CChoreoEvent::AddAbsoluteTag(this: v3, type: ORIGINAL, tagname: params.m_szInputText, t: tshifted);
          CChoreoEvent::AddAbsoluteTag(this: v3, type: PLAYBACK, tagname: params.m_szInputText, t);
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Add Gesture Tag");
          this->redraw(this);
        }
        else
        {
          Con_ErrorPrintf(fmt: "Timing Tag Name:  No name entered!\n");
        }
      }
    }
    else
    {
      Con_ErrorPrintf(fmt: "Absolute Tag:  Can only tag GESTURE events\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B100
// Name: private: void GestureTool::OnDeleteTag(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnDeleteTag(GestureTool *this)
{
  CChoreoEvent *SafeEvent; // ebx
  CEventAbsoluteTag *v3; // esi
  const char *Name; // eax
  CChoreoEvent::AbsTagType i; // esi
  char sz[512]; // [esp+8h] [ebp-200h] BYREF

  SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v3 = (CEventAbsoluteTag *)GestureTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
    if ( v3 != nullptr )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Remove Gesture Tag");
      Name = CEventAbsoluteTag::GetName(this: v3);
      V_strncpy(pDest: sz, pSrc: Name, maxLen: 512);
      for ( i = PLAYBACK; i < NUM_ABS_TAG_TYPES; ++i )
        CChoreoEvent::RemoveAbsoluteTag(this: SafeEvent, type: i, tagname: sz);
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Remove Gesture Tags");
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B1B0
// Name: private: void GestureTool::DrawRelativeTagsForEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CChoreoEvent __near *,class CChoreoEvent __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawRelativeTagsForEvent(
        GestureTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        float rc,
        CChoreoEvent *gesture,
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
  int bottom; // eax
  const char *Name; // eax
  int v18; // eax
  int v19; // edi
  const char *v20; // eax
  int v21; // ebx
  tagRECT rcText; // [esp+14h] [ebp-30h] BYREF
  tagRECT rcMark; // [esp+24h] [ebp-20h] BYREF
  GestureTool *v24; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  Color clr; // [esp+3Ch] [ebp-8h] BYREF
  Color fill; // [esp+40h] [ebp-4h] BYREF

  v7 = event;
  v24 = this;
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
          v12 = CChoreoEvent::GetStartTime(this: gesture);
          v13 = rc - v12;
          rc = v13;
          if ( starttime <= v13 )
          {
            time = (tagRECT *)LODWORD(rc);
            if ( rc <= endtime )
            {
              HIBYTE(rc) = 0;
              PixelForTimeValue = GestureTool::GetPixelForTimeValue(
                                    this: v24,
                                    time: *(float *)&time,
                                    clipped: (bool *)&rc + 3);
              if ( HIBYTE(rc) == 0 )
              {
                rcMark.bottom = v8->bottom;
                rcMark.top = rcMark.bottom - 8;
                rcMark.left = PixelForTimeValue - 4;
                rcMark.right = PixelForTimeValue + 4;
                fill = (Color)13132800;
                CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, &fill, inverted: false);
                bottom = v8->bottom;
                *(_QWORD *)&rcText.left = *(_QWORD *)&v8->left;
                rcText.right = _mm_loadl_epi64((const __m128i *)&v8->right).m128i_u32[0];
                rcText.bottom = bottom - 10;
                rcText.top = bottom - 20;
                Name = CEventAbsoluteTag::GetName(this: RelativeTag);
                v18 = CChoreoWidgetDrawHelper::CalcTextWidth(
                        font: "Arial",
                        pointsize: (HFONT__ *)9,
                        weight: 400,
                        fmt: Name);
                v19 = PixelForTimeValue - v18 / 2;
                rcText.right = v19 + v18 + 2;
                rcText.left = v19;
                clr = (Color)13132800;
                v20 = CEventAbsoluteTag::GetName(this: RelativeTag);
                CChoreoWidgetDrawHelper::DrawColoredText(
                  this: drawHelper,
                  font: "Arial",
                  pointsize: 9,
                  weight: 400,
                  &clr,
                  &rcText,
                  fmt: v20);
              }
              v7 = event;
            }
          }
        }
        v21 = ++i;
      }
      while ( v21 < CChoreoEvent::GetNumRelativeTags(this: v7) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B350
// Name: private: void GestureTool::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::RepositionHSlider(GestureTool *this)
{
  IterateRIFF *SafeEvent; // eax
  int v3; // edi
  char *Name; // eax
  int v5; // eax
  int v6; // eax
  float m_flLeftOffset; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  int v9; // eax
  int v10; // [esp-8h] [ebp-14h]
  int m_nScrollbarHeight; // [esp-4h] [ebp-10h]
  float v12; // [esp+8h] [ebp-4h]

  SafeEvent = GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v12 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v3 = 10
       - (int)(float)((float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                    * this->m_flPixelsPerSecond)
                            * -0.0099999998)
                    * v12);
  }
  else
  {
    v3 = 0;
  }
  v5 = mxWidget::w2(this);
  mxWidget::setVisible(this: this->m_pHorzScrollBar, b: v3 > v5);
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
  mxScrollbar::setPagesize(this: this->m_pHorzScrollBar, size: v9);
  this->m_nLastHPixelsNeeded = v3;
}

//------------------------------------------------------------------------------
// Address: 0x0045B470
// Name: private: void GestureTool::InvalidateLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::InvalidateLayout(GestureTool *this)
{
  IterateRIFF *SafeEvent; // eax
  char *Name; // eax
  void (__thiscall *redraw)(struct GestureTool *); // eax
  float v5; // [esp+4h] [ebp-4h]

  if ( !this->m_bSuppressLayout )
  {
    SafeEvent = GestureTool::GetSafeEvent(this);
    if ( SafeEvent != nullptr )
    {
      v5 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      SafeEvent = (IterateRIFF *)(10
                                - (int)(float)((float)((float)((float)CChoreoView::GetTimeZoom(
                                                                        this: g_pChoreoView,
                                                                        tool: Name)
                                                             * this->m_flPixelsPerSecond)
                                                     * -0.0099999998)
                                             * v5));
    }
    if ( SafeEvent != (IterateRIFF *)this->m_nLastHPixelsNeeded )
      GestureTool::RepositionHSlider(this);
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B500
// Name: private: void GestureTool::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnChangeScale(GestureTool *this)
{
  char *Name; // eax
  int TimeZoom; // eax
  int v4; // eax
  char *v5; // eax
  char *v6; // eax
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
      GestureTool::InvalidateLayout(this);
      v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v7 = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6);
      Con_Printf(fmt: "Zoom factor %i %%\n", v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B670
// Name: public: void GestureTool::DrawEventEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawEventEnd(GestureTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  IterateRIFF *SafeEvent; // eax
  double v4; // st7
  IFacePoserToolWindow *v5; // edi
  char *Name; // eax
  char *v7; // eax
  int v8; // ebx
  CChoreoWidgetDrawHelper *v9; // esi
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // edx
  int v11; // eax
  int bottom; // [esp-Ch] [ebp-2Ch]
  tagRECT rcClient; // [esp+4h] [ebp-1Ch] BYREF
  float v14; // [esp+14h] [ebp-Ch]
  float duration; // [esp+18h] [ebp-8h]
  float v16; // [esp+1Ch] [ebp-4h]

  SafeEvent = GestureTool::GetSafeEvent(this);
  if ( SafeEvent != nullptr )
  {
    v4 = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
    duration = v4;
    if ( v4 != 0.0 )
    {
      v5 = &this->IFacePoserToolWindow;
      Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v16 = this->m_flLeftOffset
          / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
                  * 0.0099999998);
      v7 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v14 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v7) * this->m_flPixelsPerSecond)
          * 0.0099999998;
      duration = duration - v16;
      v14 = duration / (float)((float)((float)((float)mxWidget::w2(this) / v14) + v16) - v16);
      v8 = (int)(float)((float)mxWidget::w2(this) * v14);
      if ( v8 < mxWidget::w2(this) )
      {
        v9 = drawHelper;
        CChoreoWidgetDrawHelper::GetClientRect(this: drawHelper, rc: &rcClient);
        bottom = rcClient.bottom;
        GetCaptionHeight = v5->GetCaptionHeight;
        drawHelper = (CChoreoWidgetDrawHelper *)16711680;
        v11 = GetCaptionHeight(this: v5);
        CChoreoWidgetDrawHelper::DrawColoredLine(
          this: v9,
          clr: (HPEN__ *)&drawHelper,
          style: 0,
          width: 1,
          x1: v8,
          y1: v11 + 73,
          x2: v8,
          y2: bottom);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045B910
// Name: public: void GestureTool::SetEvent(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::SetEvent(GestureTool *this, CChoreoEvent *event)
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
    GestureTool::InvalidateLayout(this);
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
    GestureTool::InvalidateLayout(this);
  }
  this->m_nFocusEventGlobalID = event->m_nGlobalID;
  this->m_bInSetEvent = false;
}

//------------------------------------------------------------------------------
// Address: 0x0045BA00
// Name: private: void GestureTool::ShowContextMenu(class mxEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::ShowContextMenu(GestureTool *this, mxEvent *event, bool include_track_menus)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // esi
  char *UndoDescription; // eax
  const char *v7; // eax
  char *RedoDescription; // eax
  const char *v9; // eax
  CEventAbsoluteTag *v10; // eax
  const char *Name; // eax
  const char *v12; // eax
  const char *v13; // [esp-8h] [ebp-1Ch]
  int current; // [esp+Ch] [ebp-8h] BYREF
  int total; // [esp+10h] [ebp-4h] BYREF

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
  v10 = (CEventAbsoluteTag *)GestureTool::IsMouseOverTag(this, mx: SLOWORD(event->x), my: SLOWORD(event->y));
  if ( v10 != nullptr )
  {
    Name = CEventAbsoluteTag::GetName(this: v10);
    v13 = va(fmt: "Delete '%s'...", Name);
    mxPopupMenu::add(this: v5, item: v13, id: 1002);
  }
  else
  {
    mxPopupMenu::add(this: v5, item: "Insert Tag...", id: 1003);
  }
  mxPopupMenu::add(this: v5, item: "Revert Tag Timings", id: 1004);
  v12 = va(fmt: "Change scale...");
  mxPopupMenu::add(this: v5, item: v12, id: 1005);
  mxPopupMenu::popup(this: v5, widget: this, x: SLOWORD(event->x), y: SLOWORD(event->y));
}

//------------------------------------------------------------------------------
// Address: 0x0045BB30
// Name: private: void GestureTool::OnMouseMove(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnMouseMove(GestureTool *this, mxEvent *event)
{
  mxEvent *v2; // ebx
  int y_low; // eax
  signed int x_low; // edi
  bool v6; // zf
  GestureTool::CFocusRect *v7; // eax
  tagRECT *p_m_rcFocus; // ebx
  int m_nMaxX; // eax
  int m_nMinX; // eax
  HCURSOR CursorA; // eax
  POINT scrub; // [esp+0h] [ebp-2Ch]
  float t; // [esp+4h] [ebp-28h]
  tagRECT rcHandle; // [esp+14h] [ebp-18h] BYREF
  int i; // [esp+24h] [ebp-8h]
  unsigned int v16; // [esp+28h] [ebp-4h]

  v2 = event;
  y_low = SLOWORD(event->y);
  x_low = SLOWORD(event->x);
  event->x = (__int16)x_low;
  v6 = this->m_nDragType == 0;
  i = y_low;
  if ( v6 )
  {
    if ( this->m_hPrevCursor != nullptr )
    {
      SetCursor(hCursor: this->m_hPrevCursor);
      this->m_hPrevCursor = nullptr;
    }
    RampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
    InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
    scrub.y = SLOWORD(event->y);
    scrub.x = SLOWORD(event->x);
    if ( PtInRect(lprc: &rcHandle, pt: scrub) || GestureTool::IsMouseOverTag(this, mx: x_low, my: i) != nullptr )
    {
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      this->m_hPrevCursor = SetCursor(hCursor: CursorA);
    }
  }
  else
  {
    RampTool::DrawFocusRect(this);
    i = 0;
    if ( this->m_FocusRects.m_Size > 0 )
    {
      v16 = 0;
      do
      {
        v7 = &this->m_FocusRects.m_Memory.m_pMemory[v16 / 0x20];
        p_m_rcFocus = &v7->m_rcFocus;
        *(_QWORD *)&v7->m_rcFocus.left = *(_QWORD *)&v7->m_rcOrig.left;
        *(_QWORD *)&v7->m_rcFocus.right = *(_QWORD *)&v7->m_rcOrig.right;
        if ( this->m_nDragType == 2 )
        {
          if ( this->m_bUseBounds )
          {
            m_nMinX = this->m_nMinX;
            if ( x_low < m_nMinX || (m_nMinX = this->m_nMaxX, x_low > m_nMinX) )
              x_low = m_nMinX;
          }
        }
        else
        {
          if ( this->m_bUseBounds )
          {
            m_nMaxX = this->m_nMinX;
            if ( x_low < m_nMaxX || (m_nMaxX = this->m_nMaxX, x_low > m_nMaxX) )
              x_low = m_nMaxX;
          }
          if ( mxWidget::w2(this) > 0 )
          {
            t = GestureTool::GetTimeValueForMouse(this, mx: x_low, clip: false) + this->m_flScrubberTimeOffset;
            GestureTool::ForceScrubPosition(this, t);
          }
        }
        OffsetRect(lprc: p_m_rcFocus, dx: x_low - this->m_nStartX, dy: 0);
        v16 += 32;
        ++i;
      }
      while ( i < this->m_FocusRects.m_Size );
      v2 = event;
    }
    RampTool::DrawFocusRect(this);
  }
  this->m_nLastX = SLOWORD(v2->x);
  this->m_nLastY = SLOWORD(v2->y);
}

//------------------------------------------------------------------------------
// Address: 0x0045BCF0
// Name: private: void GestureTool::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::CalcBounds(GestureTool *this, CEventAbsoluteTag *movetype)
{
  CChoreoEvent *SafeEvent; // edi
  int PixelForTimeValue; // ebx
  int v5; // eax
  CChoreoEvent::AbsTagType TagTypeForTag; // eax
  int v7; // ebx
  double v8; // st7
  CEventAbsoluteTag *v9; // ecx
  double v10; // st7
  CEventAbsoluteTag *v11; // ecx
  float time; // [esp+0h] [ebp-1Ch]
  float timea; // [esp+0h] [ebp-1Ch]
  float timeb; // [esp+0h] [ebp-1Ch]
  float timec; // [esp+0h] [ebp-1Ch]
  CEventAbsoluteTag *prevTag; // [esp+14h] [ebp-8h]
  CEventAbsoluteTag *prevTaga; // [esp+14h] [ebp-8h]
  float prevTagb; // [esp+14h] [ebp-8h]
  int c; // [esp+18h] [ebp-4h]
  CEventAbsoluteTag *nextTag; // [esp+24h] [ebp+8h]
  CEventAbsoluteTag *nextTaga; // [esp+24h] [ebp+8h]
  float nextTagb; // [esp+24h] [ebp+8h]

  if ( movetype == (CEventAbsoluteTag *)1 )
  {
    this->m_bUseBounds = true;
    this->m_nMinX = 0;
    this->m_nMaxX = mxWidget::w2(this);
  }
  else if ( movetype == (CEventAbsoluteTag *)2 )
  {
    this->m_bUseBounds = true;
    this->m_nMinX = 0;
    this->m_nMaxX = mxWidget::w2(this);
    SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
    prevTag = (CEventAbsoluteTag *)GestureTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
    if ( prevTag != nullptr
      && SafeEvent != nullptr
      && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) != 0.0 )
    {
      this->m_nMinX = GestureTool::GetPixelForTimeValue(this, time: 0.0, clipped: nullptr);
      time = SafeEvent->GetDuration(this: SafeEvent);
      PixelForTimeValue = GestureTool::GetPixelForTimeValue(this, time, clipped: nullptr);
      if ( mxWidget::w2(this) <= PixelForTimeValue )
      {
        timea = SafeEvent->GetDuration(this: SafeEvent);
        v5 = GestureTool::GetPixelForTimeValue(this, time: timea, clipped: nullptr);
      }
      else
      {
        v5 = mxWidget::w2(this);
      }
      this->m_nMaxX = v5;
      TagTypeForTag = GestureTool::GetTagTypeForTag(this, tag: prevTag);
      nextTag = (CEventAbsoluteTag *)TagTypeForTag;
      if ( TagTypeForTag != INVALID )
      {
        v7 = 0;
        c = CChoreoEvent::GetNumAbsoluteTags(this: SafeEvent, type: TagTypeForTag);
        if ( c > 0 )
        {
          while ( CChoreoEvent::GetAbsoluteTag(this: SafeEvent, type: (CChoreoEvent::AbsTagType)nextTag, tagnum: v7) != prevTag )
          {
            if ( ++v7 >= c )
              return;
          }
          if ( v7 <= 0 )
            prevTaga = nullptr;
          else
            prevTaga = CChoreoEvent::GetAbsoluteTag(
                         this: SafeEvent,
                         type: (CChoreoEvent::AbsTagType)nextTag,
                         tagnum: v7 - 1);
          if ( v7 >= c - 1 )
            nextTaga = nullptr;
          else
            nextTaga = CChoreoEvent::GetAbsoluteTag(
                         this: SafeEvent,
                         type: (CChoreoEvent::AbsTagType)nextTag,
                         tagnum: v7 + 1);
          if ( v7 < c )
          {
            if ( prevTaga != nullptr )
            {
              v8 = ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent);
              v9 = prevTaga;
              prevTagb = v8;
              timeb = CEventAbsoluteTag::GetPercentage(this: v9) * prevTagb;
              this->m_nMinX = GestureTool::GetPixelForTimeValue(this, time: timeb, clipped: nullptr) + 1;
            }
            if ( nextTaga != nullptr )
            {
              v10 = ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent);
              v11 = nextTaga;
              nextTagb = v10;
              timec = CEventAbsoluteTag::GetPercentage(this: v11) * nextTagb;
              this->m_nMaxX = GestureTool::GetPixelForTimeValue(this, time: timec, clipped: nullptr) - 1;
            }
          }
        }
      }
    }
  }
  else
  {
    this->m_bUseBounds = false;
    this->m_nMinX = 0;
    this->m_nMaxX = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045BF10
// Name: private: void GestureTool::DrawRelativeTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::DrawRelativeTags(GestureTool *this, CChoreoWidgetDrawHelper *drawHelper, tagRECT *rc)
{
  CChoreoScene *SafeEvent; // eax
  IterateRIFF *SceneFPS; // ebx
  int v6; // eax
  double TimeValueForMouse; // st7
  int v8; // edi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v10; // esi
  double v11; // st7
  double v12; // st7
  int c; // [esp+14h] [ebp-18h]
  CChoreoEvent *gesture; // [esp+1Ch] [ebp-10h]
  float endtime; // [esp+20h] [ebp-Ch]
  float starttime; // [esp+24h] [ebp-8h]
  Color clr; // [esp+28h] [ebp-4h] BYREF

  SafeEvent = (CChoreoScene *)GestureTool::GetSafeEvent(this);
  gesture = (CChoreoEvent *)SafeEvent;
  if ( SafeEvent != nullptr )
  {
    SceneFPS = (IterateRIFF *)CChoreoScene::GetSceneFPS(this: SafeEvent);
    if ( SceneFPS != nullptr )
    {
      starttime = GestureTool::GetTimeValueForMouse(this, mx: 0, clip: false);
      v6 = mxWidget::w2(this);
      TimeValueForMouse = GestureTool::GetTimeValueForMouse(this, mx: v6, clip: false);
      endtime = TimeValueForMouse;
      if ( TimeValueForMouse - starttime > 0.0 )
      {
        *(float *)&clr = 1.8402972e-38;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: drawHelper,
          font: "Arial",
          pointsize: 9,
          weight: 400,
          &clr,
          rcText: rc,
          fmt: "Timing Tags:");
        v8 = 0;
        c = CChoreoScene::GetNumEvents(this: SceneFPS);
        if ( c > 0 )
        {
          do
          {
            Event = CChoreoScene::GetEvent(this: (CChoreoScene *)SceneFPS, event: v8);
            v10 = Event;
            if ( Event != nullptr
              && CChoreoEvent::GetNumRelativeTags(this: Event) > 0
              && CChoreoEvent::CurveHasEndTime(this: v10) )
            {
              *(float *)&clr = CChoreoEvent::GetEndTime(this: v10);
              v11 = CChoreoEvent::GetStartTime(this: v10);
              if ( starttime <= *(float *)&clr - v11 )
              {
                *(float *)&clr = CChoreoEvent::GetStartTime(this: v10);
                v12 = CChoreoEvent::GetStartTime(this: v10);
                if ( *(float *)&clr - v12 <= endtime )
                  GestureTool::DrawRelativeTagsForEvent(
                    this,
                    drawHelper,
                    rc: *(float *)&rc,
                    gesture,
                    event: v10,
                    starttime,
                    endtime);
              }
            }
            ++v8;
          }
          while ( v8 < c );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C050
// Name: private: void GestureTool::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::MoveTimeSliderToPos(GestureTool *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = (float)x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)(float)x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  GestureTool::InvalidateLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045C260
// Name: public: virtual void GestureTool::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::redraw(GestureTool *this)
{
  CChoreoEvent *SafeEvent; // edi
  int v3; // eax
  const char *Name; // eax
  const char *Parameters; // eax
  int v6; // eax
  IFacePoserToolWindow_vtbl *v7; // edx
  int v8; // eax
  int v9; // eax
  double StartTime; // st7
  double v11; // st7
  double v12; // st7
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // edx
  int v14; // edi
  double left_4; // [esp+4h] [ebp-120h]
  float t; // [esp+Ch] [ebp-118h]
  char sz[32]; // [esp+18h] [ebp-10Ch] BYREF
  tagRECT rc; // [esp+38h] [ebp-ECh] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+48h] [ebp-DCh] BYREF
  tagRECT rcUndo; // [esp+A0h] [ebp-84h] BYREF
  tagRECT rcHandle; // [esp+B0h] [ebp-74h] BYREF
  tagRECT rcTags; // [esp+C0h] [ebp-64h] BYREF
  tagRECT rcTimeLine; // [esp+D0h] [ebp-54h] BYREF
  int current; // [esp+E0h] [ebp-44h] BYREF
  tagRECT timeRect; // [esp+E4h] [ebp-40h] BYREF
  tagRECT rcTextLine; // [esp+F4h] [ebp-30h] BYREF
  int total; // [esp+104h] [ebp-20h] BYREF
  float seqduration; // [esp+108h] [ebp-1Ch] BYREF
  tagRECT rcText; // [esp+10Ch] [ebp-18h] BYREF
  float scrub; // [esp+11Ch] [ebp-8h]
  int lefttime; // [esp+120h] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) != 0 )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
    SafeEvent = (CChoreoEvent *)GestureTool::GetSafeEvent(this);
    if ( SafeEvent != nullptr )
    {
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcText);
      v3 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcText.top += v3 + 1;
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
      CChoreoEvent::GetGestureSequenceDuration(this: SafeEvent, duration: &seqduration);
      rcTextLine = rcText;
      lefttime = 200;
      Name = CChoreoEvent::GetName(this: SafeEvent);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 11,
        weight: 900,
        clr: (const Color *)&lefttime,
        rcText: &rcTextLine,
        fmt: "Event:  %s",
        Name);
      OffsetRect(lprc: &rcTextLine, dx: 0, dy: 12);
      lefttime = 200;
      left_4 = seqduration;
      Parameters = CChoreoEvent::GetParameters(this: SafeEvent);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 11,
        weight: 900,
        clr: (const Color *)&lefttime,
        rcText: &rcTextLine,
        fmt: "Sequence:  '%s' %.3f s.",
        Parameters,
        left_4);
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcTimeLine);
      rcTimeLine.left = 0;
      v6 = mxWidget::w2(this);
      v7 = this->IFacePoserToolWindow::__vftable;
      rcTimeLine.right = v6;
      v8 = v7->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcTimeLine.top += v8 + 70;
      *(float *)&lefttime = GestureTool::GetTimeValueForMouse(this, mx: 0, clip: false);
      v9 = mxWidget::w2(this);
      scrub = GestureTool::GetTimeValueForMouse(this, mx: v9, clip: false);
      RampTool::DrawTimeLine(this, &drawHelper, rc: &rcTimeLine, left: *(float *)&lefttime, right: scrub);
      OffsetRect(lprc: &rcText, dx: 0, dy: 30);
      rcText.left = 5;
      *(_QWORD *)&timeRect.left = *(_QWORD *)&rcText.left;
      timeRect.bottom = rcText.bottom;
      timeRect.right = 105;
      StartTime = CChoreoEvent::GetStartTime(this: SafeEvent);
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
      v11 = CChoreoEvent::GetStartTime(this: SafeEvent);
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", v11 + scrub);
      scrub = COERCE_FLOAT(CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 400, fmt: sz));
      timeRect.right = mxWidget::w2(this) - 10;
      timeRect.left = timeRect.right - LODWORD(scrub);
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
    RampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
    GestureTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
    GestureTool::DrawEventEnd(this, &drawHelper);
    if ( SafeEvent != nullptr && ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent) > 0.0 )
    {
      t = this->m_flScrub / ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent);
      seqduration = CChoreoEvent::GetOriginalPercentageFromPlaybackPercentage(this: SafeEvent, t);
      v12 = ((double (__thiscall *)(CChoreoEvent *))SafeEvent->GetDuration)(a1: SafeEvent);
      scrub = v12 * seqduration;
      GestureTool::GetScrubHandleReferenceRect(this, &rcHandle, scrub, clipped: true);
      GestureTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub, reference: (Color)1);
    }
    GetCaptionHeight = this->GetCaptionHeight;
    rcTags = rc;
    rcTags.top = GetCaptionHeight(this: &this->IFacePoserToolWindow) + 52;
    rcTags.bottom = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 72;
    GestureTool::DrawRelativeTags(this, &drawHelper, rc: &rcTags);
    GestureTool::DrawAbsoluteTags(this, &drawHelper);
    v14 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
    rcTextLine.top = v14;
    rcTextLine.left = mxWidget::w2(this) - 200;
    rcTextLine.right = mxWidget::w2(this) - 5;
    rcTextLine.bottom = v14 + 13;
    GestureTool::DrawMouseOverPos(this, &drawHelper, rcPos: &rcTextLine);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045C730
// Name: public: GestureTool::GestureTool(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
GestureTool *__thiscall GestureTool::GestureTool(GestureTool *this, mxWindow *parent)
{
  mxScrollbar *v3; // eax
  mxScrollbar *v4; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "GestureTool",
    displaynameroot: "Gesture");
  this->mxWindow::mxWidget::__vftable = (GestureTool_vtbl *)&GestureTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&GestureTool::`vftable'{for `IFacePoserToolWindow'};
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
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
  v3 = (mxScrollbar *)operator new(nSize: 0xCu);
  if ( v3 != nullptr )
    v4 = mxScrollbar::mxScrollbar(this: v3, parent: this, x: 0, y: 0, w: 18, h: 100, id: 1006, style: 0);
  else
    v4 = nullptr;
  this->m_pHorzScrollBar = v4;
  mxWidget::setVisible(this: v4, b: false);
  this->m_bInSetEvent = false;
  this->m_flScrubberTimeOffset = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0045C890
// Name: private: void GestureTool::AddFocusRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::AddFocusRect(GestureTool *this, tagRECT *rc)
{
  __int64 v2; // xmm0_8
  HWND Handle; // eax
  int m_Size; // [esp-Ch] [ebp-44h]
  GestureTool::CFocusRect fr; // [esp+0h] [ebp-38h] BYREF
  tagRECT rcFocus; // [esp+20h] [ebp-18h] BYREF
  tagPOINT offset; // [esp+30h] [ebp-8h] BYREF

  *(_QWORD *)&rcFocus.left = *(_QWORD *)&rc->left;
  v2 = *(_QWORD *)&rc->right;
  offset.x = 0;
  offset.y = 0;
  *(_QWORD *)&rcFocus.right = v2;
  Handle = (HWND)mxWidget::getHandle(this);
  ClientToScreen(hWnd: Handle, lpPoint: &offset);
  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
  m_Size = this->m_FocusRects.m_Size;
  fr.m_rcFocus = rcFocus;
  fr.m_rcOrig = rcFocus;
  CUtlVector<PhonemeEditor::CFocusRect,CUtlMemory<PhonemeEditor::CFocusRect,int>>::InsertBefore(
    this: (CUtlVector<CChoreoView::CFocusRect,CUtlMemory<CChoreoView::CFocusRect,int> > *)&this->m_FocusRects,
    elem: m_Size,
    src: (const CChoreoView::CFocusRect *)&fr);
}

//------------------------------------------------------------------------------
// Address: 0x0045C970
// Name: private: void GestureTool::StartDragging(int,int,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::StartDragging(GestureTool *this, int dragtype, int startx, int starty, HICON__ *cursor)
{
  HICON__ *m_hPrevCursor; // eax
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
  if ( dragtype == 2 )
  {
    rcStart.top = 0;
  }
  else
  {
    RampTool::GetScrubHandleRect(this, rcHandle: &rcScrub, scrub: this->m_flScrub, clipped: true);
    rcStart.bottom = rcScrub.bottom;
    rcStart.left = (rcScrub.right + rcScrub.left) / 2;
    rcStart.right = rcStart.left;
    rcStart.top = rcScrub.bottom;
  }
  rcStart.bottom = mxWidget::h2(this);
  GestureTool::AddFocusRect(this, rc: &rcStart);
  RampTool::DrawFocusRect(this);
}

//------------------------------------------------------------------------------
// Address: 0x0045CA90
// Name: public: virtual int GestureTool::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GestureTool::handleEvent(GestureTool *this, int event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  int result; // eax
  char *Name; // eax
  int TimeZoom; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int x_low; // ebx
  double TimeValueForMouse; // st7
  double v14; // st7
  double v15; // st7
  HCURSOR CursorA; // eax
  HCURSOR v17; // eax
  int v18; // eax
  int y_low; // ecx
  CEventAbsoluteTag *v20; // edi
  IterateRIFF *SafeEvent; // eax
  double v22; // st7
  int v23; // edx
  int v24; // eax
  int MaxValue; // edi
  int MinValue; // edi
  float percentage; // [esp+4h] [ebp-24h]
  float percentagea; // [esp+4h] [ebp-24h]
  float minVal; // [esp+14h] [ebp-14h] BYREF
  float t; // [esp+18h] [ebp-10h] BYREF
  int my; // [esp+1Ch] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+20h] [ebp-8h]
  int lastfrac; // [esp+24h] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = (mxEvent *)event;
  HandleToolEvent = this->HandleToolEvent;
  *(float *)&lastfrac = 0.0;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)event) )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  else
  {
    switch ( v4->event )
    {
      case 0:
        v24 = v4->action - 1000;
        lastfrac = 1;
        switch ( v24 )
        {
          case 0:
            CChoreoView::Redo(this: g_pChoreoView);
            break;
          case 1:
            CChoreoView::Undo(this: g_pChoreoView);
            break;
          case 2:
            GestureTool::OnDeleteTag(this);
            break;
          case 3:
            GestureTool::OnInsertTag(this);
            break;
          case 4:
            GestureTool::OnRevert(this);
            break;
          case 5:
            GestureTool::OnChangeScale(this);
            break;
          case 6:
            switch ( v4->modifiers )
            {
              case 0:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
                goto LABEL_51;
              case 1:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
                goto LABEL_56;
              case 2:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 20;
LABEL_51:
                if ( MaxValue > mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                  goto LABEL_58;
                MinValue = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
                GestureTool::MoveTimeSliderToPos(this, x: MinValue);
                break;
              case 3:
                MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 20;
LABEL_56:
                if ( MaxValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                  MaxValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
LABEL_58:
                GestureTool::MoveTimeSliderToPos(this, x: MaxValue);
                break;
              case 5:
                GestureTool::MoveTimeSliderToPos(this, x: v4->height);
                break;
              default:
                goto LABEL_61;
            }
            break;
          default:
            *(float *)&lastfrac = 0.0;
            break;
        }
        goto LABEL_61;
      case 1:
        this->m_nLastHPixelsNeeded = 0;
        GestureTool::InvalidateLayout(this);
        lastfrac = 1;
        goto LABEL_61;
      case 6:
        if ( (v4->buttons & 2) != 0 )
        {
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        y_low = SLOWORD(v4->y);
        event = SLOWORD(v4->x);
        my = y_low;
        if ( this->m_nDragType != 0 )
          RampTool::DrawFocusRect(this);
        if ( this->m_hPrevCursor != nullptr )
        {
          SetCursor(hCursor: this->m_hPrevCursor);
          this->m_hPrevCursor = nullptr;
        }
        if ( this->m_nDragType == 1 )
        {
          RampTool::ApplyBounds(this, mx: &event, &my);
          if ( mxWidget::w2(this) > 0 )
          {
            percentagea = GestureTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false)
                        + this->m_flScrubberTimeOffset;
            GestureTool::ForceScrubPosition(this, t: percentagea);
            this->m_flScrubberTimeOffset = 0.0;
          }
        }
        else if ( this->m_nDragType == 2 )
        {
          RampTool::ApplyBounds(this, mx: &event, &my);
          v20 = (CEventAbsoluteTag *)GestureTool::IsMouseOverTag(this, mx: this->m_nClickedX, my: this->m_nClickedY);
          if ( v20 != nullptr && mxWidget::w2(this) != 0 && GestureTool::GetSafeEvent(this) != nullptr )
          {
            t = GestureTool::GetTimeValueForMouse(this, mx: event, clip: false);
            SafeEvent = GestureTool::GetSafeEvent(this);
            v22 = t / ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
            t = 1.0;
            minVal = 0.0;
            *(float *)&lastfrac = v22;
            *(float *)&lastfrac = clamp<float,float,float>(val: (const float *)&lastfrac, &minVal, maxVal: &t);
            CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
            CChoreoView::PushUndo(this: g_pChoreoView, description: "move absolute tag");
            CEventAbsoluteTag::SetPercentage(this: v20, percentage: *(float *)&lastfrac);
            CChoreoView::PushRedo(this: g_pChoreoView, description: "move absolute tag");
            CChoreoView::InvalidateLayout(this: g_pChoreoView);
            this->redraw(this);
          }
        }
        v23 = my;
        this->m_nMousePos[0] = event;
        this->m_nDragType = 0;
        this->m_nMousePos[1] = v23;
        GestureTool::DrawMouseOverPos(this);
        lastfrac = 1;
        goto LABEL_61;
      case 7:
        v11 = SLOWORD(v4->y);
        x_low = SLOWORD(v4->x);
        lastfrac = 1;
        event = v11;
        this->m_nClickedX = x_low;
        this->m_nClickedY = v11;
        this->m_nMousePos[0] = x_low;
        this->m_nMousePos[1] = v11;
        GestureTool::DrawMouseOverPos(this);
        if ( (v4->buttons & 2) != 0 )
        {
          GestureTool::ShowContextMenu(this, event: v4, include_track_menus: false);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          result = 1;
        }
        else
        {
          if ( this->m_nDragType == 0 )
          {
            if ( RampTool::IsMouseOverScrubHandle(this, event: v4) )
            {
              if ( mxWidget::w2(this) > 0 )
              {
                TimeValueForMouse = GestureTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
                t = TimeValueForMouse;
                this->m_flScrubberTimeOffset = this->m_flScrub - TimeValueForMouse;
                v14 = 20.0 / GestureTool::GetPixelsPerSecond(this);
                *(float *)&event = v14;
                *(float *)&my = -v14;
                v15 = clamp<float,float,float>(
                        val: &this->m_flScrubberTimeOffset,
                        minVal: (const float *)&my,
                        maxVal: (const float *)&event);
                this->m_flScrubberTimeOffset = v15;
                percentage = v15 + t;
                GestureTool::ForceScrubPosition(this, t: percentage);
              }
              CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
              GestureTool::StartDragging(
                this,
                dragtype: 1,
                startx: this->m_nClickedX,
                starty: this->m_nClickedY,
                cursor: CursorA);
              GestureTool::CalcBounds(this, movetype: (CEventAbsoluteTag *)this->m_nDragType);
            }
            else if ( GestureTool::IsMouseOverTag(this, mx: x_low, my: event) != nullptr )
            {
              v17 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
              GestureTool::StartDragging(
                this,
                dragtype: 2,
                startx: this->m_nClickedX,
                starty: this->m_nClickedY,
                cursor: v17);
              GestureTool::CalcBounds(this, movetype: (CEventAbsoluteTag *)this->m_nDragType);
            }
            else
            {
              if ( mxWidget::w2(this) > 0 )
              {
                *(float *)&event = GestureTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
                GestureTool::SetScrubTargetTime(this, t: *(float *)&event);
              }
              GestureTool::CalcBounds(this, movetype: (CEventAbsoluteTag *)this->m_nDragType);
            }
          }
LABEL_61:
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          result = lastfrac;
        }
        break;
      case 8:
      case 9:
        v18 = SLOWORD(v4->y);
        this->m_nMousePos[0] = SLOWORD(v4->x);
        this->m_nMousePos[1] = v18;
        GestureTool::DrawMouseOverPos(this);
        GestureTool::OnMouseMove(this, event: v4);
        lastfrac = 1;
        goto LABEL_61;
      case 0xB:
        *(float *)&lastfrac = COERCE_FLOAT(
                                CChoreoView::HandleZoomKey<GestureTool>(
                                  this: g_pChoreoView,
                                  other: this,
                                  keyCode: v4->key));
        goto LABEL_61;
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
              v10 = 1000;
          }
          CChoreoView::SetPreservedTimeZoom<GestureTool>(this: g_pChoreoView, other: this, tz: v10);
        }
        GestureTool::RepositionHSlider(this);
        this->redraw(this);
        lastfrac = 1;
        goto LABEL_61;
      default:
        goto LABEL_61;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00477BB0
// Name: private: float GestureTool::GetPixelsPerSecond(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GestureTool::GetPixelsPerSecond(GestureTool *this)
{
  char *Name; // eax

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  return (double)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond * 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x00477C90
// Name: private: int GestureTool::GetPixelForTimeValue(float,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GestureTool::GetPixelForTimeValue(GestureTool *this, float time, bool *clipped)
{
  char *Name; // eax
  char *v6; // eax
  float v8; // [esp+8h] [ebp-4h]
  float sta; // [esp+18h] [ebp+Ch]
  float st; // [esp+18h] [ebp+Ch]

  if ( clipped != nullptr )
    *clipped = false;
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  sta = this->m_flLeftOffset
      / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
              * 0.0099999998);
  v6 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  v8 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v6) * this->m_flPixelsPerSecond)
     * 0.0099999998;
  st = (float)(time - sta) / (float)((float)((float)((float)mxWidget::w2(this) / v8) + sta) - sta);
  if ( (st < 0.0 || st > 1.0) && clipped != nullptr )
    *clipped = true;
  return (int)(float)((float)mxWidget::w2(this) * st);
}

//------------------------------------------------------------------------------
// Address: 0x00477D90
// Name: private: float GestureTool::GetTimeValueForMouse(int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GestureTool::GetTimeValueForMouse(GestureTool *this, int mx, bool clip)
{
  char *Name; // eax
  char *v5; // eax
  float eda; // [esp+8h] [ebp-8h]
  float ed; // [esp+8h] [ebp-8h]
  float st; // [esp+Ch] [ebp-4h]
  float mxa; // [esp+18h] [ebp+8h]

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  st = this->m_flLeftOffset
     / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond)
             * 0.0099999998);
  v5 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  eda = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v5) * this->m_flPixelsPerSecond)
      * 0.0099999998;
  ed = (float)((float)mxWidget::w2(this) / eda) + st;
  if ( clip )
  {
    if ( mx < 0 )
      return st;
    if ( mx > mxWidget::w2(this) )
      return ed;
  }
  mxa = (float)mx;
  return st + (ed - st) * (mxa / (double)mxWidget::w2(this));
}

//------------------------------------------------------------------------------
// Address: 0x0047D730
// Name: public: virtual void GestureTool::OnModelChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GestureTool::OnModelChanged(GestureTool *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 3) + 16))(a1: (char *)this - 12);
}
