// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/sceneramptool.cpp
// Functions: 51
// ============================================================

#include "utils\hlfaceposer\sceneramptool.h"

//------------------------------------------------------------------------------
// Address: 0x00469340
// Name: public: void CUtlMemory<struct CChoreoView::CFocusRect,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CChoreoView::CFocusRect,int>::Grow(CUtlMemory<CChoreoView::CFocusRect,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CChoreoView::CFocusRect *m_pMemory; // edx
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
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CChoreoView::CFocusRect *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CChoreoView::CFocusRect *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D060
// Name: public: virtual bool SceneRampTool::IsProcessing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SceneRampTool::IsProcessing(SceneRampTool *this)
{
  return g_pChoreoView != nullptr
      && CChoreoView::GetScene(this: g_pChoreoView) != nullptr
      && *(float *)&this->m_szWindowTitle[188] != *(float *)&this->m_bUseForMainWindowTitle;
}

//------------------------------------------------------------------------------
// Address: 0x0047D0A0
// Name: public: virtual bool SceneRampTool::IsScrubbing(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SceneRampTool::IsScrubbing(SceneRampTool *this)
{
  return this->m_nMinX == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0047D0B0
// Name: public: void SceneRampTool::SetScrubTime(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SceneRampTool::SetScrubTime(SceneRampTool *this@<ecx>, int a2@<edi>, float t)
{
  CChoreoScene *Scene; // eax

  this->m_flScrub = t;
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr && CChoreoScene::FindStopTime(this: Scene) != 0.0 )
    {
      CChoreoView::SetScrubTime(this: g_pChoreoView, t: this->m_flScrub);
      CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D120
// Name: public: void SceneRampTool::SetScrubTargetTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::SetScrubTargetTime(SceneRampTool *this, float t)
{
  CChoreoScene *Scene; // eax

  this->m_flScrubTarget = t;
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr && CChoreoScene::FindStopTime(this: Scene) != 0.0 )
      CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t: this->m_flScrubTarget);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D180
// Name: public: void SceneRampTool::ScrubThink(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SceneRampTool::ScrubThink(SceneRampTool *this@<ecx>, int a2@<edi>, float dt, bool scrubbing)
{
  float t; // xmm2_4
  float m_flScrub; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( g_pChoreoView != nullptr && CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
  {
    t = this->m_flScrubTarget;
    m_flScrub = this->m_flScrub;
    if ( t != m_flScrub || scrubbing )
    {
      v7 = t - m_flScrub;
      if ( (float)(t - m_flScrub) <= 0.0 )
      {
        if ( dt > COERCE_FLOAT(LODWORD(v7) ^ _mask__NegFloat_) )
          goto LABEL_7;
        v8 = m_flScrub - dt;
      }
      else
      {
        if ( dt > v7 )
        {
LABEL_7:
          SceneRampTool::SetScrubTime(this, a2, t);
          goto LABEL_12;
        }
        v8 = m_flScrub + dt;
      }
      SceneRampTool::SetScrubTime(this, a2, t: v8);
LABEL_12:
      if ( scrubbing )
        MatSysWindow::Frame(this: g_pMatSysWindow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D220
// Name: private: void SceneRampTool::CalcBounds(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::CalcBounds(SceneRampTool *this, int movetype)
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
// Address: 0x0047D270
// Name: private: float SceneRampTool::GetPixelsPerSecond(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall SceneRampTool::GetPixelsPerSecond(SceneRampTool *this)
{
  char *Name; // eax

  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  return (double)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name) * this->m_flPixelsPerSecond * 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x0047D2B0
// Name: private: void SceneRampTool::GetStartAndEndTime(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::GetStartAndEndTime(SceneRampTool *this, float *st, float *ed)
{
  char *Name; // eax
  char *v6; // eax
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
// Address: 0x0047D350
// Name: private: int SceneRampTool::GetPixelForTimeValue(float,bool __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SceneRampTool::GetPixelForTimeValue(SceneRampTool *this, float time, bool *clipped)
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
// Address: 0x0047D450
// Name: private: float SceneRampTool::GetTimeValueForMouse(int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall SceneRampTool::GetTimeValueForMouse(SceneRampTool *this, int mx, bool clip)
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
// Address: 0x0047D540
// Name: private: void SceneRampTool::GetSampleTrayRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::GetSampleTrayRect(SceneRampTool *this, tagRECT *rc)
{
  rc->left = 0;
  rc->right = mxWidget::w2(this);
  rc->top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
  rc->bottom = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047D590
// Name: public: struct CExpressionSample __near * SceneRampTool::GetSampleUnderMouse(int,int,float)
// Source: json
//------------------------------------------------------------------------------
CExpressionSample *__thiscall SceneRampTool::GetSampleUnderMouse(
        SceneRampTool *this,
        unsigned int mx,
        unsigned int my,
        float tolerance)
{
  int v5; // ebx
  CChoreoScene *Scene; // edi
  int v8; // eax
  int v9; // ecx
  unsigned int v10; // esi
  CCurveData *p_m_SceneRamp; // edi
  int v12; // esi
  CExpressionSample *v13; // esi
  int PixelForTimeValue; // eax
  int v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  tagRECT rcSamples; // [esp+14h] [ebp-28h] BYREF
  tagPOINT pt; // [esp+24h] [ebp-18h]
  float v20; // [esp+2Ch] [ebp-10h]
  SceneRampTool *v21; // [esp+30h] [ebp-Ch]
  CExpressionSample *bestsample; // [esp+34h] [ebp-8h]
  float closest_dist; // [esp+38h] [ebp-4h]

  v5 = 0;
  v21 = this;
  if ( g_pChoreoView == nullptr )
    return nullptr;
  Scene = CChoreoView::GetScene(this: g_pChoreoView);
  if ( Scene == nullptr )
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
  p_m_SceneRamp = &Scene->m_SceneRamp;
  closest_dist = 9999999.0;
  bestsample = nullptr;
  v12 = rcSamples.bottom - rcSamples.top;
  if ( (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_SceneRamp) > 0 )
  {
    v20 = (float)v12;
    do
    {
      v13 = CCurveData::Get(this: p_m_SceneRamp, index: v5);
      PixelForTimeValue = SceneRampTool::GetPixelForTimeValue(this: v21, time: v13->time, clipped: (bool *)&my + 3);
      v15 = (PixelForTimeValue - mx) * (PixelForTimeValue - mx);
      v16 = (int)(float)((float)(1.0 - v13->value) * v20) - pt.y;
      v17 = fsqrt((float)(v15 + v16 * v16));
      if ( closest_dist > v17 )
      {
        bestsample = v13;
        closest_dist = v17;
      }
      ++v5;
    }
    while ( v5 < (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_SceneRamp) );
  }
  if ( tolerance == 0.0 || closest_dist <= tolerance )
    return bestsample;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0047D6E0
// Name: private: void SceneRampTool::SelectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::SelectAll(SceneRampTool *this)
{
  CChoreoScene *Scene; // eax
  CCurveData *p_m_SceneRamp; // edi
  int i; // esi
  CExpressionSample *v4; // eax

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr )
    {
      p_m_SceneRamp = &Scene->m_SceneRamp;
      for ( i = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp) - 1; i >= 0; --i )
      {
        v4 = CCurveData::Get(this: p_m_SceneRamp, index: i);
        *((_WORD *)v4 + 4) |= 1u;
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D740
// Name: public: void SceneRampTool::PreDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::PreDataChanged(SceneRampTool *this, const char *undodescription)
{
  if ( this->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: undodescription);
  }
  ++this->m_nUndoSetup;
}

//------------------------------------------------------------------------------
// Address: 0x0047D780
// Name: public: void SceneRampTool::PostDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::PostDataChanged(SceneRampTool *this, const char *redodescription)
{
  if ( this->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: redodescription);
    this->redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D7B0
// Name: private: void SceneRampTool::OnEdgeProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::OnEdgeProperties(SceneRampTool *this)
{
  CChoreoScene *Scene; // edi
  CCurveData *p_m_SceneRamp; // edi
  CEdgePropertiesParams params; // [esp+4h] [ebp-1A0h] BYREF

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr )
    {
      _V_memset(dest: &params, fill: 0, count: 416);
      _V_strcpy(dest: params.m_szDialogTitle, src: "Edge Properties");
      p_m_SceneRamp = &Scene->m_SceneRamp;
      CEdgePropertiesParams::SetFromCurve(this: &params, ramp: p_m_SceneRamp);
      if ( EdgeProperties(&params) != 0 )
      {
        if ( this->m_nUndoSetup == 0 )
        {
          CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
          CChoreoView::PushUndo(this: g_pChoreoView, description: "Change Scene Ramp Edge Properties");
        }
        ++this->m_nUndoSetup;
        CEdgePropertiesParams::ApplyToCurve(this: &params, ramp: p_m_SceneRamp);
        if ( this->m_nUndoSetup-- == 1 )
        {
          CChoreoView::PushRedo(this: g_pChoreoView, description: "Change Scene Ramp Edge Properties");
          this->redraw(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047D890
// Name: public: void SceneRampTool::GetScrubHandleRect(struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::GetScrubHandleRect(SceneRampTool *this, tagRECT *rcHandle, float scrub, bool clipped)
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
  v9 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 2;
  rcHandle->top = v9;
  rcHandle->bottom = v9 + 10;
}

//------------------------------------------------------------------------------
// Address: 0x0047DA10
// Name: public: void SceneRampTool::DrawScrubHandle(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawScrubHandle(
        SceneRampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcHandle,
        float scrub,
        Color reference)
{
  bool v5; // zf
  HBRUSH SolidBrush; // eax
  HBRUSH__ *v8; // ebx
  int v9; // eax
  int v10; // eax
  CChoreoScene *Scene; // eax
  int v12; // eax
  int top; // [esp+4h] [ebp-44h]
  int bottom; // [esp+4h] [ebp-44h]
  char sz[32]; // [esp+14h] [ebp-34h] BYREF
  tagRECT rcText; // [esp+34h] [ebp-14h] BYREF
  mxWidget *v17; // [esp+44h] [ebp-4h]

  v5 = reference._color[0] == 0;
  v17 = this;
  reference = (Color)150;
  if ( v5 )
    reference = (Color)&g_flexedverts[1250].z;
  SolidBrush = CreateSolidBrush(color: reference._color[0] | ((reference._color[1] | (reference._color[2] << 8)) << 8));
  top = rcHandle->top;
  v8 = SolidBrush;
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
  v10 = mxWidget::w2(this: v17);
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: drawHelper,
    clr: (HPEN__ *)&reference,
    style: 0,
    width: 1,
    x1: 0,
    y1: rcHandle->bottom,
    x2: v10,
    y2: bottom);
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, br: v8, rc: rcHandle);
  sprintf(string: sz, format: "%.3f", scrub);
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr && CChoreoScene::FindStopTime(this: Scene) > 0.0 )
      sprintf(string: sz, format: "%.3f", scrub);
  }
  v12 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
  rcText = *rcHandle;
  rcText.left += (rcText.right - rcText.left - v12) / 2;
  scrub = 2.3509886e-38;
  CChoreoWidgetDrawHelper::DrawColoredText(
    this: drawHelper,
    font: "Arial",
    pointsize: 9,
    weight: 500,
    clr: (const Color *)&scrub,
    &rcText,
    fmt: sz);
  DeleteObject(ho: v8);
}

//------------------------------------------------------------------------------
// Address: 0x0047DB90
// Name: public: bool SceneRampTool::IsMouseOverScrubHandle(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SceneRampTool::IsMouseOverScrubHandle(SceneRampTool *this, mxEvent *event)
{
  POINT scrub; // [esp+0h] [ebp-18h]
  tagRECT rcHandle; // [esp+8h] [ebp-10h] BYREF

  SceneRampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
  InflateRect(lprc: &rcHandle, dx: 2, dy: 2);
  scrub.y = SLOWORD(event->y);
  scrub.x = SLOWORD(event->x);
  return PtInRect(lprc: &rcHandle, pt: scrub);
}

//------------------------------------------------------------------------------
// Address: 0x0047DBE0
// Name: public: virtual void SceneRampTool::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SceneRampTool::Think(SceneRampTool *this@<ecx>, int a2@<edi>, float dt)
{
  char v4; // al

  if ( g_pChoreoView != nullptr && CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
  {
    v4 = ((int (__thiscall *)(SceneRampTool *))this->redraw)(a1: this);
    SceneRampTool::ScrubThink(this: (SceneRampTool *)((char *)this - 12), a2, dt, scrubbing: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DC30
// Name: public: void SceneRampTool::DrawScrubHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawScrubHandles(SceneRampTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+Ch] [ebp-78h] BYREF
  tagRECT rcHandle; // [esp+64h] [ebp-20h] BYREF
  tagRECT rcTray; // [esp+74h] [ebp-10h] BYREF

  SceneRampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
  rcTray.top = rcHandle.top;
  *(_QWORD *)&rcTray.right = *(_QWORD *)&rcHandle.right;
  rcTray.left = 0;
  rcTray.right = mxWidget::w2(this);
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcTray);
  SceneRampTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0047DCB0
// Name: private: void SceneRampTool::ApplyBounds(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::ApplyBounds(SceneRampTool *this, int *mx, int *my)
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
// Address: 0x0047DCF0
// Name: public: void SceneRampTool::ForceScrubPositionFromSceneTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::ForceScrubPositionFromSceneTime(SceneRampTool *this, float scenetime)
{
  CChoreoScene *Scene; // eax

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr && CChoreoScene::FindStopTime(this: Scene) != 0.0 )
    {
      this->m_flScrub = scenetime;
      this->m_flScrubTarget = scenetime;
      SceneRampTool::DrawScrubHandles(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047DD40
// Name: public: void SceneRampTool::ForceScrubPosition(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SceneRampTool::ForceScrubPosition(SceneRampTool *this@<ecx>, int a2@<edi>, float t)
{
  CChoreoScene *Scene; // eax

  this->m_flScrub = t;
  this->m_flScrubTarget = t;
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr && CChoreoScene::FindStopTime(this: Scene) != 0.0 )
    {
      CChoreoView::SetScrubTime(this: g_pChoreoView, t);
      CChoreoView::SetScrubTargetTime(this: g_pChoreoView, t);
      CChoreoView::DrawScrubHandle(this: g_pChoreoView, a2);
    }
  }
  SceneRampTool::DrawScrubHandles(this);
}

//------------------------------------------------------------------------------
// Address: 0x0047DDD0
// Name: public: void SceneRampTool::DrawMouseOverPos(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawMouseOverPos(
        SceneRampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcPos)
{
  int v3; // eax
  int right; // edx
  int left; // ecx
  int v6; // edx
  char *v7; // [esp+0h] [ebp-9Ch]
  char sz[128]; // [esp+8h] [ebp-94h] BYREF
  tagRECT rcText; // [esp+88h] [ebp-14h] BYREF
  float t; // [esp+98h] [ebp-4h]

  t = SceneRampTool::GetTimeValueForMouse(this, mx: this->m_nMousePos[0], clip: false);
  if ( g_pChoreoView != nullptr && CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
  {
    if ( t == FacePoser_SnapTime(t) )
    {
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%.3f", t);
    }
    else
    {
      v7 = FacePoser_DescribeSnappedTime(t);
      V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v7);
    }
    v3 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)0xB, weight: 900, fmt: sz);
    right = rcPos->right;
    *(_QWORD *)&rcText.left = *(_QWORD *)&rcPos->left;
    left = rcPos->left;
    v6 = right - v3;
    *(_QWORD *)&rcText.right = *(_QWORD *)&rcPos->right;
    rcText.left = left;
    if ( left <= v6 )
      rcText.left = v6;
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
// Address: 0x0047DEF0
// Name: public: void SceneRampTool::DrawMouseOverPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawMouseOverPos(SceneRampTool *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-68h] BYREF
  tagRECT rcPos; // [esp+5Ch] [ebp-10h] BYREF

  rcPos.top = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
  rcPos.left = mxWidget::w2(this) - 200;
  rcPos.right = mxWidget::w2(this) - 5;
  rcPos.bottom = rcPos.top + 13;
  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this, bounds: &rcPos);
  SceneRampTool::DrawMouseOverPos(this, &drawHelper, &rcPos);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x0047DF80
// Name: public: void SceneRampTool::DrawTimeLine(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawTimeLine(
        SceneRampTool *this,
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
  char *Name; // eax
  char *v13; // eax
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
// Address: 0x0047E210
// Name: private: void SceneRampTool::DrawAbsoluteTagsForEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CChoreoEvent __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawAbsoluteTagsForEvent(
        SceneRampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        float rc,
        CChoreoEvent *event,
        float starttime,
        float endtime)
{
  CChoreoEvent *v6; // esi
  tagRECT *v7; // ebx
  CEventAbsoluteTag *AbsoluteTag; // edi
  double Percentage; // st7
  double v10; // st7
  double v11; // st7
  tagRECT *time; // xmm0_4
  int PixelForTimeValue; // esi
  const char *Name; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // edi
  tagRECT rcText; // [esp+14h] [ebp-2Ch] BYREF
  tagRECT rcMark; // [esp+24h] [ebp-1Ch] BYREF
  SceneRampTool *v20; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  Color clr; // [esp+3Ch] [ebp-4h] BYREF

  v6 = event;
  v20 = this;
  if ( event != nullptr )
  {
    i = 0;
    if ( CChoreoEvent::GetNumAbsoluteTags(this: event, type: PLAYBACK) > 0 )
    {
      v7 = (tagRECT *)LODWORD(rc);
      do
      {
        AbsoluteTag = CChoreoEvent::GetAbsoluteTag(this: v6, type: PLAYBACK, tagnum: i);
        if ( AbsoluteTag != nullptr )
        {
          rc = v6->GetDuration(this: v6);
          Percentage = CEventAbsoluteTag::GetPercentage(this: AbsoluteTag);
          rc = Percentage * rc;
          v10 = CChoreoEvent::GetStartTime(this: v6);
          v11 = v10 + rc;
          rc = v11;
          if ( starttime <= v11 )
          {
            time = (tagRECT *)LODWORD(rc);
            if ( rc <= endtime )
            {
              HIBYTE(rc) = 0;
              PixelForTimeValue = SceneRampTool::GetPixelForTimeValue(
                                    this: v20,
                                    time: *(float *)&time,
                                    clipped: (bool *)&rc + 3);
              if ( HIBYTE(rc) == 0 && CChoreoEvent::GetType(this: event) != GESTURE )
              {
                rcMark.bottom = v7->bottom;
                rcMark.top = rcMark.bottom - 8;
                rcMark.left = PixelForTimeValue - 4;
                rcMark.right = PixelForTimeValue + 4;
                clr = (Color)16409600;
                CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &clr, inverted: false);
                rcText.left = rcMark.left;
                rcText.top = rcMark.top - 12;
                *(_QWORD *)&rcText.right = *(_QWORD *)&rcMark.right;
                Name = CEventAbsoluteTag::GetName(this: AbsoluteTag);
                v15 = CChoreoWidgetDrawHelper::CalcTextWidth(
                        font: "Arial",
                        pointsize: (HFONT__ *)9,
                        weight: 400,
                        fmt: Name);
                rcText.left = PixelForTimeValue - v15 / 2;
                rcText.right = rcText.left + v15 + 2;
                rcText.bottom = rcText.top + 10;
                v16 = CEventAbsoluteTag::GetName(this: AbsoluteTag);
                CChoreoWidgetDrawHelper::DrawColoredText(
                  this: drawHelper,
                  font: "Arial",
                  pointsize: 9,
                  weight: 400,
                  &clr,
                  &rcText,
                  fmt: v16);
              }
              v6 = event;
            }
          }
        }
        v17 = ++i;
      }
      while ( v17 < CChoreoEvent::GetNumAbsoluteTags(this: v6, type: PLAYBACK) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E3C0
// Name: private: void SceneRampTool::DrawRelativeTagsForEvent(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &,class CChoreoEvent __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawRelativeTagsForEvent(
        SceneRampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        float rc,
        CChoreoEvent *event,
        float starttime,
        float endtime)
{
  CChoreoEvent *v6; // edi
  tagRECT *v7; // esi
  CEventAbsoluteTag *RelativeTag; // ebx
  double Percentage; // st7
  double v10; // st7
  double v11; // st7
  tagRECT *time; // xmm0_4
  int PixelForTimeValue; // edi
  int bottom; // eax
  const char *Name; // eax
  int v16; // eax
  int v17; // edi
  const char *v18; // eax
  int v19; // ebx
  tagRECT rcText; // [esp+14h] [ebp-2Ch] BYREF
  tagRECT rcMark; // [esp+24h] [ebp-1Ch] BYREF
  SceneRampTool *v22; // [esp+34h] [ebp-Ch]
  int i; // [esp+38h] [ebp-8h]
  Color clr; // [esp+3Ch] [ebp-4h] BYREF

  v6 = event;
  v22 = this;
  if ( event != nullptr )
  {
    i = 0;
    if ( CChoreoEvent::GetNumRelativeTags(this: event) > 0 )
    {
      v7 = (tagRECT *)LODWORD(rc);
      do
      {
        RelativeTag = (CEventAbsoluteTag *)CChoreoEvent::GetRelativeTag(this: v6, tagnum: i);
        if ( RelativeTag != nullptr )
        {
          rc = v6->GetDuration(this: v6);
          Percentage = CEventAbsoluteTag::GetPercentage(this: RelativeTag);
          rc = Percentage * rc;
          v10 = CChoreoEvent::GetStartTime(this: v6);
          v11 = v10 + rc;
          rc = v11;
          if ( starttime <= v11 )
          {
            time = (tagRECT *)LODWORD(rc);
            if ( rc <= endtime )
            {
              HIBYTE(rc) = 0;
              PixelForTimeValue = SceneRampTool::GetPixelForTimeValue(
                                    this: v22,
                                    time: *(float *)&time,
                                    clipped: (bool *)&rc + 3);
              if ( HIBYTE(rc) == 0 )
              {
                rcMark.bottom = v7->bottom;
                rcMark.top = rcMark.bottom - 8;
                rcMark.left = PixelForTimeValue - 4;
                rcMark.right = PixelForTimeValue + 4;
                clr = (Color)&g_flexedverts[192].y;
                CChoreoWidgetDrawHelper::DrawTriangleMarker(this: drawHelper, rc: &rcMark, fill: &clr, inverted: false);
                bottom = v7->bottom;
                *(_QWORD *)&rcText.left = *(_QWORD *)&v7->left;
                rcText.right = _mm_loadl_epi64((const __m128i *)&v7->right).m128i_u32[0];
                rcText.bottom = bottom - 10;
                rcText.top = bottom - 20;
                Name = CEventAbsoluteTag::GetName(this: RelativeTag);
                v16 = CChoreoWidgetDrawHelper::CalcTextWidth(
                        font: "Arial",
                        pointsize: (HFONT__ *)9,
                        weight: 400,
                        fmt: Name);
                v17 = PixelForTimeValue - v16 / 2;
                rcText.right = v17 + v16 + 2;
                rcText.left = v17;
                v18 = CEventAbsoluteTag::GetName(this: RelativeTag);
                CChoreoWidgetDrawHelper::DrawColoredText(
                  this: drawHelper,
                  font: "Arial",
                  pointsize: 9,
                  weight: 400,
                  &clr,
                  &rcText,
                  fmt: v18);
              }
              v6 = event;
            }
          }
        }
        v19 = ++i;
      }
      while ( v19 < CChoreoEvent::GetNumRelativeTags(this: v6) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E550
// Name: private: int SceneRampTool::ComputeHPixelsNeeded(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SceneRampTool::ComputeHPixelsNeeded(SceneRampTool *this)
{
  CChoreoScene *Scene; // eax
  char *Name; // eax
  float maxtime; // [esp+4h] [ebp-4h]

  if ( g_pChoreoView == nullptr )
    return 0;
  Scene = CChoreoView::GetScene(this: g_pChoreoView);
  if ( Scene == nullptr )
    return 0;
  maxtime = CChoreoScene::FindStopTime(this: Scene);
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
  return (int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                            * this->m_flPixelsPerSecond)
                                    * 0.0099999998)
                            * maxtime)
                    + 10.0);
}

//------------------------------------------------------------------------------
// Address: 0x0047E5C0
// Name: private: void SceneRampTool::RepositionHSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::RepositionHSlider(SceneRampTool *this)
{
  CChoreoScene *Scene; // eax
  int v3; // edi
  char *Name; // eax
  int v5; // eax
  int v6; // eax
  float m_flLeftOffset; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  int v9; // eax
  int v10; // [esp-8h] [ebp-14h]
  int m_nScrollbarHeight; // [esp-4h] [ebp-10h]
  float StopTime; // [esp+8h] [ebp-4h]

  if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
  {
    StopTime = CChoreoScene::FindStopTime(this: Scene);
    Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
    v3 = (int)(float)((float)((float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                            * this->m_flPixelsPerSecond)
                                    * 0.0099999998)
                            * StopTime)
                    + 10.0);
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
// Address: 0x0047E6F0
// Name: private: void SceneRampTool::InvalidateLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::InvalidateLayout(SceneRampTool *this)
{
  void (__thiscall *redraw)(struct SceneRampTool *); // edx

  if ( !this->m_bSuppressLayout )
  {
    if ( SceneRampTool::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
      SceneRampTool::RepositionHSlider(this);
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E730
// Name: private: void SceneRampTool::OnChangeScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::OnChangeScale(SceneRampTool *this)
{
  char *Name; // eax
  int TimeZoom; // eax
  int v4; // eax
  char *v5; // eax
  bool v6; // zf
  void (__thiscall *redraw)(struct SceneRampTool *); // eax
  char *v8; // eax
  int v9; // eax
  Color v10; // ecx
  __int64 v11; // [esp+0h] [ebp-59Ch]
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
      v11 = (unsigned int)v4;
      v5 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      CChoreoView::SetTimeZoom(this: g_pChoreoView, tool: v5, tz: v11, preserveFocus: SBYTE4(v11));
      v6 = !this->m_bSuppressLayout;
      this->m_nLastHPixelsNeeded = -1;
      this->m_flLeftOffset = 0.0;
      if ( v6 )
      {
        if ( SceneRampTool::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
          SceneRampTool::RepositionHSlider(this);
        redraw = this->redraw;
        this->m_bLayoutIsValid = false;
        redraw(this);
      }
      v8 = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
      v9 = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v8);
      Con_Printf(a1: v10, fmt: "Zoom factor %i %%\n", v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047E8D0
// Name: public: void SceneRampTool::DrawSceneEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawSceneEnd(SceneRampTool *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoScene *Scene; // eax
  double StopTime; // st7
  char *Name; // eax
  char *v6; // eax
  int v7; // edi
  tagRECT rcSample; // [esp+4h] [ebp-1Ch] BYREF
  float v9; // [esp+14h] [ebp-Ch]
  float duration; // [esp+18h] [ebp-8h]
  Color clr; // [esp+1Ch] [ebp-4h] BYREF

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: Scene);
      duration = StopTime;
      if ( StopTime != 0.0 )
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
          SceneRampTool::GetSampleTrayRect(this, rc: &rcSample);
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
}

//------------------------------------------------------------------------------
// Address: 0x0047EA10
// Name: private: void SceneRampTool::DrawSamples(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawSamples(
        SceneRampTool *this,
        CChoreoWidgetDrawHelper *drawHelper,
        tagRECT *rcSamples)
{
  SceneRampTool *v3; // edi
  CChoreoScene *Scene; // eax
  CChoreoScene *v5; // esi
  int bottom; // eax
  int v7; // ebx
  char *Name; // eax
  double StopTime; // st7
  float time; // xmm0_4
  bool v11; // cf
  int PixelForTimeValue; // eax
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  CExpressionSample *v17; // esi
  float v18; // xmm0_4
  HPEN__ *v19; // ebx
  float v20; // xmm0_4
  int v21; // edi
  Color *p_clrSelected; // eax
  char *v23; // eax
  int v24; // eax
  char sz[128]; // [esp+14h] [ebp-DCh] BYREF
  tagRECT rc; // [esp+94h] [ebp-5Ch] BYREF
  int height; // [esp+A4h] [ebp-4Ch]
  int rampCount; // [esp+A8h] [ebp-48h]
  int v29; // [esp+ACh] [ebp-44h]
  SceneRampTool *v30; // [esp+B0h] [ebp-40h]
  float prev_t; // [esp+B4h] [ebp-3Ch]
  float prev_value; // [esp+B8h] [ebp-38h]
  float value; // [esp+BCh] [ebp-34h]
  Color clrSelected; // [esp+C0h] [ebp-30h] BYREF
  int x; // [esp+C4h] [ebp-2Ch]
  CCurveData *p_m_SceneRamp; // [esp+C8h] [ebp-28h]
  Color lineColor; // [esp+CCh] [ebp-24h] BYREF
  Color clr; // [esp+D0h] [ebp-20h] BYREF
  Color dotColorSelected; // [esp+D4h] [ebp-1Ch]
  Color shadowColor; // [esp+D8h] [ebp-18h] BYREF
  float t; // [esp+DCh] [ebp-14h] BYREF
  bool clipped2; // [esp+E3h] [ebp-Dh] BYREF
  Color dotColor; // [esp+E4h] [ebp-Ch] BYREF
  float sample; // [esp+E8h] [ebp-8h] BYREF
  bool clipped; // [esp+EFh] [ebp-1h] BYREF

  v3 = this;
  v30 = this;
  *(float *)&dotColor = 1.9827462e-38;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: drawHelper, clr: &dotColor, rc: rcSamples);
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    v5 = Scene;
    if ( Scene != nullptr )
    {
      p_m_SceneRamp = &Scene->m_SceneRamp;
      rampCount = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
      if ( rampCount != 0 )
      {
        SceneRampTool::GetStartAndEndTime(this: v3, st: &t, ed: &sample);
        bottom = rcSamples->bottom;
        v7 = bottom - rcSamples->top;
        clrSelected = (Color)rcSamples->top;
        lineColor = (Color)16711680;
        *(float *)&dotColor = 2.3418052e-38;
        dotColorSelected = (Color)1331440;
        shadowColor = (Color)16422550;
        v29 = bottom;
        height = v7;
        Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&v3->IFacePoserToolWindow);
        *(float *)&clr = 1.0
                       / (float)((float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name)
                                       * v3->m_flPixelsPerSecond)
                               * 0.0099999998);
        StopTime = CChoreoScene::FindStopTime(this: v5);
        if ( StopTime <= sample )
          sample = CChoreoScene::FindStopTime(this: v5);
        prev_t = t;
        prev_value = CCurveData::GetIntensity(this: p_m_SceneRamp, data: v5, time: t);
        time = t - *(float *)&clr;
        v11 = sample < (float)(t - *(float *)&clr);
        for ( t = t - *(float *)&clr; !v11; t = t + *(float *)&clr )
        {
          value = CCurveData::GetIntensity(this: p_m_SceneRamp, data: v5, time);
          *(float *)&x = COERCE_FLOAT(SceneRampTool::GetPixelForTimeValue(this: v3, time: t, &clipped));
          PixelForTimeValue = SceneRampTool::GetPixelForTimeValue(this: v3, time: prev_t, clipped: &clipped2);
          if ( !clipped && !clipped2 )
          {
            v13 = (float)v29;
            v14 = (float)v29 - (float)((float)v7 * value);
            v15 = (float)v29 - (float)((float)v7 * prev_value);
            v16 = (float)(int)clrSelected;
            if ( (float)*(int *)&clrSelected <= v14 )
            {
              if ( v14 > v13 )
                v14 = (float)v29;
            }
            else
            {
              v14 = (float)(int)clrSelected;
            }
            if ( v16 <= v15 )
            {
              if ( v15 <= v13 )
                v16 = (float)v29 - (float)((float)v7 * prev_value);
              else
                v16 = (float)v29;
            }
            CChoreoWidgetDrawHelper::DrawColoredLine(
              this: drawHelper,
              clr: (HPEN__ *)&lineColor,
              style: 0,
              width: 1,
              x1: PixelForTimeValue,
              y1: (int)v16,
              x2: x,
              y2: (int)v14);
          }
          prev_t = t;
          time = t + *(float *)&clr;
          prev_value = value;
          v11 = sample < (float)(t + *(float *)&clr);
        }
        sample = 0.0;
        if ( rampCount > 0 )
        {
          do
          {
            v17 = CCurveData::Get(this: p_m_SceneRamp, index: SLODWORD(sample));
            x = SLODWORD(v17->value);
            v18 = v17->time;
            clipped = false;
            v19 = (HPEN__ *)SceneRampTool::GetPixelForTimeValue(this: v3, time: v18, &clipped);
            if ( !clipped )
            {
              clr = dotColor;
              clrSelected = dotColorSelected;
              v20 = (float)v29 - (float)((float)height * *(float *)&x);
              v21 = (int)v20;
              p_clrSelected = &clrSelected;
              if ( (*((_WORD *)v17 + 4) & 1) == 0 )
                p_clrSelected = &clr;
              CChoreoWidgetDrawHelper::DrawCircle(
                this: drawHelper,
                clr: p_clrSelected,
                x: v19,
                y: (HBRUSH__ *)(int)v20,
                radius: (HBRUSH__ *)6,
                filled: true);
              if ( (*((_WORD *)v17 + 4) & 1) != 0 && (*((_WORD *)v17 + 4) & 0xFFFE) != 0 )
              {
                v23 = Interpolator_NameForCurveType(type: *((_WORD *)v17 + 4) >> 1, printname: true);
                V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v23);
                v24 = rcSamples->top + 2;
                if ( v21 + 5 >= v24 )
                {
                  v24 = rcSamples->bottom - 11;
                  if ( v21 + 5 <= v24 )
                    v24 = v21 + 5;
                }
                rc.top = v24;
                rc.bottom = v24 + 10;
                rc.left = (int)v19 - 75;
                rc.right = (int)v19 + 175;
                CChoreoWidgetDrawHelper::DrawColoredText(
                  this: drawHelper,
                  font: "Arial",
                  pointsize: 9,
                  weight: 500,
                  clr: &shadowColor,
                  rcText: &rc,
                  fmt: sz);
              }
              v3 = v30;
            }
            ++LODWORD(sample);
          }
          while ( SLODWORD(sample) < rampCount );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047ED90
// Name: private: void SceneRampTool::DrawAutoHighlight(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawAutoHighlight(SceneRampTool *this, HBRUSH__ *event)
{
  CChoreoScene *Scene; // edi
  IterateRIFF *p_m_SceneRamp; // edi
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

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr )
    {
      hover = SceneRampTool::GetSampleUnderMouse(
                this,
                mx: *((_DWORD *)event + 6),
                my: *((_DWORD *)event + 7),
                tolerance: 0.0);
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
      p_m_SceneRamp = (IterateRIFF *)&Scene->m_SceneRamp;
      HIBYTE(event) = 0;
      clrSelected = (Color)1331440;
      clrHighlighted = (Color)51200;
      clr = (Color)16711680;
      bgColor = (Color)13166310;
      v13 = p_m_SceneRamp;
      sampleCount = CAudioSourceMemWave::GetNumChannels(this: p_m_SceneRamp);
      sample = 0;
      if ( sampleCount > 0 )
      {
        while ( 1 )
        {
          v5 = CCurveData::Get(this: (CCurveData *)p_m_SceneRamp, index: sample);
          value = v5->value;
          time = v5->time;
          HIBYTE(event) = 0;
          PixelForTimeValue = (HPEN__ *)SceneRampTool::GetPixelForTimeValue(this, time, clipped: (bool *)&event + 3);
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
          p_m_SceneRamp = v13;
        }
      }
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EF50
// Name: private: void SceneRampTool::SelectPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::SelectPoints(SceneRampTool *this)
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
  CChoreoScene *Scene; // eax
  double StopTime; // st7
  float v14; // xmm1_4
  float v15; // xmm2_4
  char *Name; // eax
  int TimeZoom; // eax
  CCurveData *p_m_SceneRamp; // ebx
  int i; // edi
  CExpressionSample *v20; // eax
  float v21; // xmm0_4
  tagRECT rcSelection; // [esp+10h] [ebp-30h] BYREF
  CChoreoScene *v23; // [esp+20h] [ebp-20h]
  float epsy; // [esp+24h] [ebp-1Ch]
  float fright; // [esp+28h] [ebp-18h]
  float tolerance; // [esp+2Ch] [ebp-14h]
  float fleft; // [esp+30h] [ebp-10h]
  int height; // [esp+34h] [ebp-Ch]
  float duration; // [esp+38h] [ebp-8h]
  float v30; // [esp+3Ch] [ebp-4h]

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
    SampleUnderMouse = SceneRampTool::GetSampleUnderMouse(
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
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    v23 = Scene;
    if ( Scene != nullptr )
    {
      StopTime = CChoreoScene::FindStopTime(this: Scene);
      duration = StopTime;
      if ( StopTime != 0.0 )
      {
        fleft = SceneRampTool::GetTimeValueForMouse(this, mx: rcSelection.left, clip: false);
        fright = SceneRampTool::GetTimeValueForMouse(this, mx: rcSelection.right, clip: false);
        epsy = (float)height;
        v14 = (float)(rcSelection.top - v11) / (float)height;
        v15 = (float)(rcSelection.bottom - v11) / (float)height;
        if ( fleft >= 0.0 )
        {
          if ( fleft <= duration )
            v30 = fleft;
          else
            v30 = duration;
        }
        else
        {
          v30 = 0.0;
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
        p_m_SceneRamp = &v23->m_SceneRamp;
        fright = (float)(1.0 / (float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998)) * tolerance;
        epsy = (float)(1.0 / epsy) * tolerance;
        for ( i = 0; i < (int)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)p_m_SceneRamp); ++i )
        {
          v20 = CCurveData::Get(this: p_m_SceneRamp, index: i);
          if ( v30 <= (float)(v20->time + fright) && (float)(v20->time - fright) <= duration )
          {
            v21 = 1.0 - v20->value;
            if ( *(float *)&height <= (float)(v21 + epsy) && (float)(v21 - epsy) <= fleft )
              *((_WORD *)v20 + 4) |= 1u;
          }
        }
        this->redraw(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F500
// Name: private: void SceneRampTool::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawFocusRect(SceneRampTool *this)
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
// Address: 0x0047F580
// Name: private: void SceneRampTool::DrawTimingTags(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DrawTimingTags(SceneRampTool *this, CChoreoWidgetDrawHelper *drawHelper, int rc)
{
  IterateRIFF *Scene; // esi
  int v5; // eax
  double TimeValueForMouse; // st7
  float v7; // edi
  int v8; // ebx
  CChoreoEvent *Event; // eax
  CChoreoEvent *v10; // esi
  double v11; // st7
  double v12; // st6
  tagRECT rcText; // [esp+14h] [ebp-20h] BYREF
  IterateRIFF *v14; // [esp+24h] [ebp-10h]
  SceneRampTool *v15; // [esp+28h] [ebp-Ch]
  float endtime; // [esp+2Ch] [ebp-8h]
  float starttime; // [esp+30h] [ebp-4h]

  v15 = this;
  if ( g_pChoreoView != nullptr )
  {
    Scene = (IterateRIFF *)CChoreoView::GetScene(this: g_pChoreoView);
    v14 = Scene;
    if ( Scene != nullptr )
    {
      starttime = SceneRampTool::GetTimeValueForMouse(this, mx: 0, clip: false);
      v5 = mxWidget::w2(this);
      TimeValueForMouse = SceneRampTool::GetTimeValueForMouse(this, mx: v5, clip: false);
      endtime = TimeValueForMouse;
      if ( TimeValueForMouse - starttime > 0.0 )
      {
        v7 = *(float *)&rc;
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
        v8 = 0;
        rc = CChoreoScene::GetNumEvents(this: Scene);
        if ( rc > 0 )
        {
          while ( 1 )
          {
            Event = CChoreoScene::GetEvent(this: (CChoreoScene *)Scene, event: v8);
            v10 = Event;
            if ( Event != nullptr && CChoreoEvent::CurveHasEndTime(this: Event) )
            {
              v11 = CChoreoEvent::GetEndTime(this: v10);
              if ( starttime <= v11 )
              {
                v12 = CChoreoEvent::GetStartTime(this: v10);
                if ( v12 <= endtime )
                {
                  if ( CChoreoEvent::GetNumRelativeTags(this: v10) > 0 )
                    SceneRampTool::DrawRelativeTagsForEvent(
                      this: v15,
                      drawHelper,
                      rc: v7,
                      event: v10,
                      starttime,
                      endtime);
                  if ( CChoreoEvent::GetNumAbsoluteTags(this: v10, type: PLAYBACK) > 0 )
                    SceneRampTool::DrawAbsoluteTagsForEvent(
                      this: v15,
                      drawHelper,
                      rc: v7,
                      event: v10,
                      starttime,
                      endtime);
                }
              }
            }
            if ( ++v8 >= rc )
              break;
            Scene = v14;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F700
// Name: private: void SceneRampTool::MoveTimeSliderToPos(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::MoveTimeSliderToPos(SceneRampTool *this, int x)
{
  mxScrollbar *m_pHorzScrollBar; // ecx
  HWND Handle; // eax
  void (__thiscall *redraw)(struct SceneRampTool *); // eax

  m_pHorzScrollBar = this->m_pHorzScrollBar;
  this->m_flLeftOffset = (float)x;
  mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)(float)x);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pHorzScrollBar);
  InvalidateRect(hWnd: Handle, lpRect: nullptr, bErase: true);
  if ( !this->m_bSuppressLayout )
  {
    if ( SceneRampTool::ComputeHPixelsNeeded(this) != this->m_nLastHPixelsNeeded )
      SceneRampTool::RepositionHSlider(this);
    redraw = this->redraw;
    this->m_bLayoutIsValid = false;
    redraw(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F940
// Name: public: virtual void SceneRampTool::redraw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::redraw(SceneRampTool *this)
{
  int v2; // eax
  char *ChoreoFile; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  IFacePoserToolWindow_vtbl *v7; // edx
  int (__thiscall *GetCaptionHeight)(IFacePoserToolWindow *); // eax
  int v9; // eax
  IFacePoserToolWindow_vtbl *v10; // edx
  int v11; // edi
  tagRECT rcHandle; // [esp+18h] [ebp-108h] BYREF
  char sz[32]; // [esp+28h] [ebp-F8h] BYREF
  CChoreoWidgetDrawHelper drawHelper; // [esp+48h] [ebp-D8h] BYREF
  tagRECT rcTextLine; // [esp+A0h] [ebp-80h] BYREF
  tagRECT rc; // [esp+B0h] [ebp-70h] BYREF
  tagRECT rcUndo; // [esp+C0h] [ebp-60h] BYREF
  tagRECT rcSamples; // [esp+D0h] [ebp-50h] BYREF
  int current; // [esp+E0h] [ebp-40h] BYREF
  tagRECT timeRect; // [esp+E4h] [ebp-3Ch] BYREF
  int total; // [esp+F4h] [ebp-2Ch] BYREF
  tagRECT rcTimeLine; // [esp+F8h] [ebp-28h] BYREF
  float righttime; // [esp+108h] [ebp-18h]
  tagRECT rcText; // [esp+10Ch] [ebp-14h] BYREF
  int lefttime; // [esp+11Ch] [ebp-4h] BYREF

  if ( IFacePoserToolWindow::ToolCanDraw(this: &this->IFacePoserToolWindow) != 0 )
  {
    CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
    this->HandleToolRedraw(this: &this->IFacePoserToolWindow, a2: &drawHelper);
    CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
    if ( g_pChoreoView != nullptr && CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
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
      ChoreoFile = CChoreoView::GetChoreoFile(this: g_pChoreoView);
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: &drawHelper,
        font: "Arial",
        pointsize: 11,
        weight: 900,
        clr: (const Color *)&lefttime,
        rcText: &rcTextLine,
        fmt: "Scene:  %s",
        ChoreoFile);
      CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, rc: &rcTimeLine);
      rcTimeLine.left = 0;
      rcTimeLine.right = mxWidget::w2(this);
      v4 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow);
      rcTimeLine.top += v4 + 50;
      *(float *)&lefttime = SceneRampTool::GetTimeValueForMouse(this, mx: 0, clip: false);
      v5 = mxWidget::w2(this);
      righttime = SceneRampTool::GetTimeValueForMouse(this, mx: v5, clip: false);
      SceneRampTool::DrawTimeLine(this, &drawHelper, rc: &rcTimeLine, left: *(float *)&lefttime, right: righttime);
      OffsetRect(lprc: &rcText, dx: 0, dy: 28);
      rcText.left = 5;
      *(_QWORD *)&timeRect.left = *(_QWORD *)&rcText.left;
      timeRect.bottom = rcText.bottom;
      timeRect.right = 105;
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", *(float *)&lefttime);
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
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.2f", righttime);
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
    SceneRampTool::GetScrubHandleRect(this, &rcHandle, scrub: this->m_flScrub, clipped: true);
    SceneRampTool::DrawScrubHandle(this, &drawHelper, &rcHandle, scrub: this->m_flScrub, reference: 0);
    rcSamples.left = 0;
    v6 = mxWidget::w2(this);
    v7 = this->IFacePoserToolWindow::__vftable;
    rcSamples.right = v6;
    rcSamples.top = v7->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 65;
    rcSamples.bottom = -2 - this->m_nScrollbarHeight + mxWidget::h2(this);
    SceneRampTool::DrawSamples(this, &drawHelper, &rcSamples);
    SceneRampTool::DrawSceneEnd(this, &drawHelper);
    GetCaptionHeight = this->GetCaptionHeight;
    rcTimeLine = rc;
    v9 = GetCaptionHeight(this: &this->IFacePoserToolWindow);
    v10 = this->IFacePoserToolWindow::__vftable;
    rcTimeLine.top = v9 + 32;
    rcTimeLine.bottom = v10->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 52;
    SceneRampTool::DrawTimingTags(this, &drawHelper, rc: (int)&rcTimeLine);
    v11 = this->GetCaptionHeight(this: &this->IFacePoserToolWindow) + 12;
    rcTimeLine.top = v11;
    rcTimeLine.left = mxWidget::w2(this) - 200;
    rcTimeLine.right = mxWidget::w2(this) - 5;
    rcTimeLine.bottom = v11 + 13;
    SceneRampTool::DrawMouseOverPos(this, &drawHelper, rcPos: &rcTimeLine);
    CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FD70
// Name: public: SceneRampTool::SceneRampTool(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
SceneRampTool *__thiscall SceneRampTool::SceneRampTool(SceneRampTool *this, mxWindow *parent)
{
  CCurveEditorHelper<SceneRampTool> *v3; // eax
  mxScrollbar *v4; // eax
  mxScrollbar *v5; // eax

  mxWindow::mxWindow(this, parent, x: 0, y: 0, w: 0, h: 0, label: nullptr, style: 0);
  IFacePoserToolWindow::IFacePoserToolWindow(
    this: &this->IFacePoserToolWindow,
    toolname: "SceneRampTool",
    displaynameroot: "Scene Ramp");
  this->mxWindow::mxWidget::__vftable = (SceneRampTool_vtbl *)&SceneRampTool::`vftable'{for `mxWindow'};
  this->IFacePoserToolWindow::__vftable = (IFacePoserToolWindow_vtbl *)&SceneRampTool::`vftable'{for `IFacePoserToolWindow'};
  this->m_FocusRects.m_Memory.m_pMemory = nullptr;
  this->m_FocusRects.m_Memory.m_nAllocationCount = 0;
  this->m_FocusRects.m_Memory.m_nGrowSize = 0;
  this->m_FocusRects.m_Size = 0;
  this->m_FocusRects.m_pElements = nullptr;
  v3 = (CCurveEditorHelper<SceneRampTool> *)operator new(nSize: 4u);
  if ( v3 != nullptr )
    v3->m_pOuter = this;
  else
    v3 = nullptr;
  this->m_pHelper = v3;
  this->m_bSuppressLayout = false;
  IFacePoserToolWindow::SetAutoProcess(this: &this->IFacePoserToolWindow, autoprocess: true);
  this->m_flScrub = 0.0;
  this->m_flScrubTarget = 0.0;
  this->m_nDragType = 0;
  this->m_nClickedX = 0;
  this->m_nClickedY = 0;
  this->m_hPrevCursor = nullptr;
  this->m_nStartX = 0;
  this->m_nStartY = 0;
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
  this->m_nUndoSetup = 0;
  this->m_flScrubberTimeOffset = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0047FEE0
// Name: private: void SceneRampTool::AddFocusRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::AddFocusRect(SceneRampTool *this, tagRECT *rc)
{
  __int64 v2; // xmm0_8
  HWND Handle; // eax
  int m_Size; // [esp-Ch] [ebp-44h]
  SceneRampTool::CFocusRect fr; // [esp+0h] [ebp-38h] BYREF
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
// Address: 0x004803E0
// Name: private: void SceneRampTool::StartDragging(int,int,int,struct HICON__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::StartDragging(
        SceneRampTool *this,
        int dragtype,
        int startx,
        int starty,
        HICON__ *cursor)
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
    SceneRampTool::GetScrubHandleRect(this, rcHandle: &rcScrub, scrub: this->m_flScrub, clipped: true);
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
  SceneRampTool::AddFocusRect(this, rc: &rcStart);
  SceneRampTool::DrawFocusRect(this);
}

//------------------------------------------------------------------------------
// Address: 0x00480500
// Name: private: void SceneRampTool::MoveSelectedSamples(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::MoveSelectedSamples(SceneRampTool *this, float dfdx, float dfdy)
{
  CChoreoScene *Scene; // eax
  CChoreoScene *v4; // esi
  CCurveData *p_m_SceneRamp; // edi
  signed int NumChannels; // ebx
  int i; // esi
  CExpressionSample *v8; // eax
  float v9; // xmm0_4
  int v10; // xmm1_4
  float v11; // xmm0_4
  ICurveDataAccessor *data; // [esp+4h] [ebp-8h]
  float duration; // [esp+8h] [ebp-4h]

  if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0
    && g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    v4 = Scene;
    data = Scene;
    if ( Scene != nullptr )
    {
      p_m_SceneRamp = &Scene->m_SceneRamp;
      NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
      duration = CChoreoScene::FindStopTime(this: v4);
      for ( i = 0; i < NumChannels; ++i )
      {
        v8 = CCurveData::Get(this: p_m_SceneRamp, index: i);
        if ( v8 != nullptr && (*((_BYTE *)v8 + 8) & 1) != 0 )
        {
          v9 = v8->time + dfdx;
          v10 = 0;
          v8->time = v9;
          if ( v9 >= 0.0 )
          {
            if ( v9 > duration )
              v9 = duration;
          }
          else
          {
            v9 = 0.0;
          }
          v8->time = v9;
          v11 = v8->value - dfdy;
          v8->value = v11;
          if ( v11 < 0.0 || (v10 = 1065353216, v11 > 1.0) )
            v11 = *(float *)&v10;
          v8->value = v11;
        }
      }
      CCurveData::Resort(this: p_m_SceneRamp, data);
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004805F0
// Name: private: void SceneRampTool::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::DeselectAll(SceneRampTool *this)
{
  CChoreoScene *Scene; // eax
  CCurveData *p_m_SceneRamp; // edi
  int i; // esi
  CExpressionSample *v5; // eax

  if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0
    && g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr )
    {
      p_m_SceneRamp = &Scene->m_SceneRamp;
      for ( i = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp) - 1; i >= 0; --i )
      {
        v5 = CCurveData::Get(this: p_m_SceneRamp, index: i);
        *((_WORD *)v5 + 4) &= ~1u;
      }
      this->redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480660
// Name: private: void SceneRampTool::Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::Delete(SceneRampTool *this)
{
  CChoreoScene *Scene; // edi
  IterateRIFF *p_m_SceneRamp; // edi
  int i; // esi

  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    if ( Scene != nullptr
      && CCurveEditorHelper<SceneRampTool>::CountSelected(this: this->m_pHelper, reflect: false) != 0 )
    {
      if ( this->m_nUndoSetup == 0 )
      {
        CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
        CChoreoView::PushUndo(this: g_pChoreoView, description: "Delete scene ramp points");
      }
      ++this->m_nUndoSetup;
      p_m_SceneRamp = (IterateRIFF *)&Scene->m_SceneRamp;
      for ( i = CAudioSourceMemWave::GetNumChannels(this: p_m_SceneRamp) - 1; i >= 0; --i )
      {
        if ( (*((_BYTE *)CCurveData::Get(this: (CCurveData *)p_m_SceneRamp, index: i) + 8) & 1) != 0 )
          CCurveData::Delete(this: (CCurveData *)p_m_SceneRamp, index: i);
      }
      if ( this->m_nUndoSetup-- == 1 )
      {
        CChoreoView::PushRedo(this: g_pChoreoView, description: "Delete scene ramp points");
        this->redraw(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480720
// Name: private: void SceneRampTool::ShowContextMenu(class mxEvent __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::ShowContextMenu(SceneRampTool *this, mxEvent *event, bool include_track_menus)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // esi
  char *UndoDescription; // eax
  const char *v7; // eax
  char *RedoDescription; // eax
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
  if ( g_pChoreoView != nullptr && CChoreoView::GetScene(this: g_pChoreoView) != nullptr )
  {
    if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this: this->m_pHelper, reflect: false) > 0 )
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
// Address: 0x00480870
// Name: private: void SceneRampTool::OnMouseMove(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SceneRampTool::OnMouseMove(SceneRampTool *this, mxEvent *event)
{
  mxEvent *v2; // edi
  int x_low; // ebx
  int y_low; // eax
  bool v6; // zf
  SceneRampTool::CFocusRect *v7; // eax
  tagRECT *p_m_rcFocus; // edi
  int m_nDragType; // edx
  int m_nMinX; // eax
  int m_nLastX; // ecx
  int v12; // ebx
  HCURSOR v13; // eax
  int v14; // edi
  char *Name; // eax
  int TimeZoom; // eax
  int v17; // edi
  int m_nStartX; // eax
  int v19; // ecx
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
  unsigned int v32; // [esp+48h] [ebp-10h]
  int my; // [esp+4Ch] [ebp-Ch]
  int v34; // [esp+50h] [ebp-8h]
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
    SceneRampTool::GetScrubHandleRect(this, rcHandle: &rcFocus, scrub: this->m_flScrub, clipped: true);
    InflateRect(lprc: &rcFocus, dx: 2, dy: 2);
    dfdx.y = SLOWORD(event->y);
    dfdx.x = SLOWORD(event->x);
    if ( PtInRect(lprc: &rcFocus, pt: dfdx) )
    {
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      this->m_hPrevCursor = SetCursor(hCursor: CursorA);
    }
    if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this: this->m_pHelper, reflect: false) <= 0 )
      SceneRampTool::DrawAutoHighlight(this, (HBRUSH__ *)event);
  }
  else
  {
    SceneRampTool::DrawFocusRect(this);
    i = 0;
    if ( this->m_FocusRects.m_Size > 0 )
    {
      v32 = 0;
      do
      {
        v7 = &this->m_FocusRects.m_Memory.m_pMemory[v32 / 0x20];
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
              dfdy = SceneRampTool::GetTimeValueForMouse(this, mx: x_low, clip: false) + this->m_flScrubberTimeOffset;
              SceneRampTool::ForceScrubPosition(this, a2: (int)p_m_rcFocus, t: dfdy);
            }
            OffsetRect(lprc: p_m_rcFocus, dx: x_low - this->m_nStartX, dy: 0);
            break;
          case 2:
          case 3:
            m_nLastX = this->m_nLastX;
            v34 = x_low - m_nLastX;
            v12 = my - this->m_nLastY;
            if ( (event->modifiers & 1) != 0 )
            {
              v13 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
              SetCursor(hCursor: v13);
            }
            else if ( m_nDragType == 2 )
            {
              v34 = 0;
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
            t = (float)v34;
            Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&this->IFacePoserToolWindow);
            TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: Name);
            v17 = v14 - rcSamples_4;
            SceneRampTool::MoveSelectedSamples(
              this,
              dfdx: t / (float)((float)((float)TimeZoom * this->m_flPixelsPerSecond) * 0.0099999998),
              dfdy: (float)v12 / (float)v17);
            if ( mxWidget::w2(this) > 0 )
            {
              t = SceneRampTool::GetTimeValueForMouse(this, mx, clip: false);
              SceneRampTool::ForceScrubPosition(this, a2: v17, t);
              MatSysWindow::Frame(this: g_pMatSysWindow);
            }
            OffsetRect(lprc, dx: v34, dy: v12);
            x_low = mx;
            break;
          case 4:
            m_nStartX = this->m_nStartX;
            v19 = this->m_nLastX;
            rcFocus.left = m_nStartX;
            if ( m_nStartX < v19 )
            {
              rcFocus.right = v19;
            }
            else
            {
              rcFocus.left = v19;
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
        v32 += 32;
        ++i;
      }
      while ( i < this->m_FocusRects.m_Size );
      v2 = event;
    }
    SceneRampTool::DrawFocusRect(this);
  }
  this->m_nLastX = SLOWORD(v2->x);
  this->m_nLastY = SLOWORD(v2->y);
}

//------------------------------------------------------------------------------
// Address: 0x00481140
// Name: public: virtual int SceneRampTool::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SceneRampTool::handleEvent(SceneRampTool *this, int event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  bool (__thiscall *HandleToolEvent)(IFacePoserToolWindow *, mxEvent *); // edx
  char *Name; // eax
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
  ICurveDataAccessor *v24; // ebx
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
  ICurveDataAccessor *data; // [esp+2Ch] [ebp-1Ch]
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
  v4 = (mxEvent *)event;
  HandleToolEvent = this->HandleToolEvent;
  iret = 0;
  if ( HandleToolEvent(this: &this->IFacePoserToolWindow, a2: (mxEvent *)event) )
  {
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 0;
  }
  if ( CCurveEditorHelper<SceneRampTool>::HelperHandleEvent(this: this->m_pHelper, event: v4) != 0 )
    goto LABEL_35;
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
          goto $LN1_12;
        case 3:
          goto $LN2_20;
        case 4:
          SceneRampTool::SelectAll(this);
          break;
        case 5:
          SceneRampTool::OnChangeScale(this);
          break;
        case 6:
          switch ( v4->modifiers )
          {
            case 0:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 10;
              goto LABEL_63;
            case 1:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 10;
              goto LABEL_68;
            case 2:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) - 20;
LABEL_63:
              if ( MaxValue > mxScrollbar::getMinValue(this: this->m_pHorzScrollBar) )
                goto LABEL_70;
              MinValue = mxScrollbar::getMinValue(this: this->m_pHorzScrollBar);
              SceneRampTool::MoveTimeSliderToPos(this, x: MinValue);
              break;
            case 3:
              MaxValue = mxScrollbar::getValue(this: this->m_pHorzScrollBar) + 20;
LABEL_68:
              if ( MaxValue >= mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar) )
                MaxValue = mxScrollbar::getMaxValue(this: this->m_pHorzScrollBar);
LABEL_70:
              SceneRampTool::MoveTimeSliderToPos(this, x: MaxValue);
              break;
            case 5:
              SceneRampTool::MoveTimeSliderToPos(this, x: v4->height);
              break;
            default:
              goto LABEL_79;
          }
          break;
        case 7:
          SceneRampTool::OnEdgeProperties(this);
          break;
        default:
          iret = 0;
          break;
      }
      goto LABEL_79;
    case 1:
      this->m_nLastHPixelsNeeded = 0;
      SceneRampTool::InvalidateLayout(this);
      iret = 1;
      goto LABEL_79;
    case 6:
      SceneRampTool::OnMouseMove(this, event: v4);
      v27 = this->m_nDragType == 0;
      y_low = SLOWORD(v4->y);
      event = SLOWORD(v4->x);
      if ( !v27 )
        SceneRampTool::DrawFocusRect(this);
      if ( this->m_hPrevCursor != nullptr )
      {
        SetCursor(hCursor: this->m_hPrevCursor);
        this->m_hPrevCursor = nullptr;
      }
      switch ( this->m_nDragType )
      {
        case 1:
          SceneRampTool::ApplyBounds(this, mx: &event, my: &event);
          if ( mxWidget::w2(this) > 0 )
          {
            tolerancea = SceneRampTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false)
                       + this->m_flScrubberTimeOffset;
            SceneRampTool::ForceScrubPosition(this, a2: (int)v4, t: tolerancea);
            this->m_flScrubberTimeOffset = 0.0;
          }
          break;
        case 2:
        case 3:
          SceneRampTool::PostDataChanged(this, redodescription: "move ramp points");
          break;
        case 4:
          SceneRampTool::SelectPoints(this);
          break;
        default:
          break;
      }
      v29 = (mxEvent *)event;
      this->m_nDragType = 0;
      this->m_nMousePos[0] = (int)v29;
      this->m_nMousePos[1] = y_low;
      SceneRampTool::DrawMouseOverPos(this);
      goto LABEL_55;
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
      SceneRampTool::DrawMouseOverPos(this);
      SceneRampTool::GetSampleTrayRect(this, rc: &rcSamples);
      insamplearea = PtInRect(lprc: &rcSamples, pt: (POINT)__PAIR64__(my, x_low));
      if ( this->m_nDragType != 0 )
        goto LABEL_79;
      if ( (v4->modifiers & 1) != 0 )
        v15 = 5.0;
      else
        v15 = 30.0;
      t = COERCE_FLOAT(SceneRampTool::GetSampleUnderMouse(this, mx: v4->x, my: v4->y, tolerance: v15));
      if ( SceneRampTool::IsMouseOverScrubHandle(this, event: v4) )
      {
        if ( mxWidget::w2(this) > 0 )
        {
          TimeValueForMouse = SceneRampTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
          t = TimeValueForMouse;
          this->m_flScrubberTimeOffset = this->m_flScrub - TimeValueForMouse;
          v17 = 20.0 / SceneRampTool::GetPixelsPerSecond(this);
          *(float *)&event = v17;
          *(float *)&my = -v17;
          v18 = clamp<float,float,float>(
                  val: &this->m_flScrubberTimeOffset,
                  minVal: (const float *)&my,
                  maxVal: (const float *)&event);
          this->m_flScrubberTimeOffset = v18;
          tolerance = v18 + t;
          SceneRampTool::ForceScrubPosition(this, a2: (int)&this->m_flScrubberTimeOffset, t: tolerance);
        }
        CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
        SceneRampTool::StartDragging(
          this,
          dragtype: 1,
          startx: this->m_nClickedX,
          starty: this->m_nClickedY,
          cursor: CursorA);
        SceneRampTool::CalcBounds(this, movetype: this->m_nDragType);
        goto LABEL_79;
      }
      if ( !insamplearea )
      {
        if ( (v4->buttons & 2) != 0 )
        {
          SceneRampTool::ShowContextMenu(this, event: v4, include_track_menus: false);
          cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
          return 1;
        }
        if ( mxWidget::w2(this) > 0 )
        {
          *(float *)&event = SceneRampTool::GetTimeValueForMouse(this, mx: SLOWORD(v4->x), clip: false);
          SceneRampTool::SetScrubTargetTime(this, t: *(float *)&event);
        }
LABEL_27:
        SceneRampTool::CalcBounds(this, movetype: this->m_nDragType);
        goto LABEL_79;
      }
      if ( t != 0.0 )
      {
        if ( HIBYTE(event) != 0 )
        {
          *(_WORD *)(LODWORD(t) + 8) ^= ((unsigned __int8)*(_WORD *)(LODWORD(t) + 8)
                                       ^ (unsigned __int8)~(unsigned __int8)*(_WORD *)(LODWORD(t) + 8))
                                      & 1;
          this->redraw(this);
          SceneRampTool::CalcBounds(this, movetype: this->m_nDragType);
          goto LABEL_79;
        }
        if ( (*(_BYTE *)(LODWORD(t) + 8) & 1) != 0 )
        {
          SceneRampTool::PreDataChanged(this, undodescription: "move scene ramp points");
          v20 = rightbutton;
          v21 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)(!rightbutton + 32644));
          SceneRampTool::StartDragging(
            this,
            dragtype: v20 + 2,
            startx: this->m_nClickedX,
            starty: this->m_nClickedY,
            cursor: v21);
        }
        else
        {
          SceneRampTool::DeselectAll(this);
          v22 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
          SceneRampTool::StartDragging(
            this,
            dragtype: 4,
            startx: this->m_nClickedX,
            starty: this->m_nClickedY,
            cursor: v22);
        }
        goto LABEL_27;
      }
      if ( !ctrldown )
      {
        if ( (v4->buttons & 2) == 0 )
        {
          if ( HIBYTE(event) == 0 )
            SceneRampTool::DeselectAll(this);
          v25 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
          SceneRampTool::StartDragging(
            this,
            dragtype: 4,
            startx: this->m_nClickedX,
            starty: this->m_nClickedY,
            cursor: v25);
          SceneRampTool::CalcBounds(this, movetype: this->m_nDragType);
          goto LABEL_79;
        }
        SceneRampTool::ShowContextMenu(this, event: v4, include_track_menus: false);
LABEL_35:
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        return 1;
      }
      if ( g_pChoreoView == nullptr )
        goto LABEL_27;
      data = CChoreoView::GetScene(this: g_pChoreoView);
      if ( data == nullptr )
        goto LABEL_27;
      *(float *)&my = SceneRampTool::GetTimeValueForMouse(this, mx: x_low, clip: false);
      *(float *)&my = FacePoser_SnapTime(t: *(float *)&my);
      v23 = (float)(SLOWORD(v4->y) - rcSamples.top) / (float)(rcSamples.bottom - rcSamples.top);
      t = 1.0;
      *(float *)&event = 1.0 - v23;
      minVal = 0.0;
      *(float *)&event = clamp<float,float,float>(val: (const float *)&event, &minVal, maxVal: &t);
      SceneRampTool::PreDataChanged(this, undodescription: "Add scene ramp point");
      v24 = data;
      CCurveData::Add(this: (CCurveData *)&data[75], time: *(float *)&my, value: *(float *)&event, selected: false);
      CCurveData::Resort(this: (CCurveData *)&v24[75], data: v24);
      SceneRampTool::PostDataChanged(this, redodescription: "Add scene ramp point");
      SceneRampTool::CalcBounds(this, movetype: this->m_nDragType);
LABEL_79:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return iret;
    case 8:
    case 9:
      v26 = SLOWORD(v4->y);
      this->m_nMousePos[0] = SLOWORD(v4->x);
      this->m_nMousePos[1] = v26;
      SceneRampTool::DrawMouseOverPos(this);
      SceneRampTool::OnMouseMove(this, event: v4);
      iret = 1;
      goto LABEL_79;
    case 0xB:
      key = v4->key;
      iret = 1;
      if ( key == 27 )
      {
$LN2_20:
        SceneRampTool::DeselectAll(this);
      }
      else if ( key == 46 )
      {
$LN1_12:
        SceneRampTool::Delete(this);
      }
      else
      {
        iret = CChoreoView::HandleZoomKey<SceneRampTool>(this: g_pChoreoView, other: this, keyCode: key);
      }
      goto LABEL_79;
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
            CChoreoView::SetPreservedTimeZoom<SceneRampTool>(this: g_pChoreoView, other: this, tz: 1000);
            goto LABEL_55;
          }
        }
        CChoreoView::SetPreservedTimeZoom<SceneRampTool>(this: g_pChoreoView, other: this, tz: v10);
      }
LABEL_55:
      this->redraw(this);
      iret = 1;
      goto LABEL_79;
    default:
      goto LABEL_79;
  }
}
