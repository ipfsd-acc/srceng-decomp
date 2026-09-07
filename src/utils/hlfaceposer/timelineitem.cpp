// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/timelineitem.cpp
// Functions: 77
// ============================================================

#include "utils\hlfaceposer\timelineitem.h"

//------------------------------------------------------------------------------
// Address: 0x0044FA50
// Name: public: void CChoreoView::SetPreservedTimeZoom<class ExpressionTool>(class ExpressionTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetPreservedTimeZoom<ExpressionTool>(CChoreoView *this, float other, float tz)
{
  float v3; // esi
  HWND Handle; // eax
  int x; // edi
  float v6; // xmm0_4
  char *Name; // eax
  int v8; // edi
  float v9; // xmm0_4
  char *v10; // eax
  int TimeZoom; // eax
  float v12; // xmm1_4
  IterateRIFF *SafeEvent; // eax
  float v14; // xmm0_4
  int v15; // eax
  float v16; // xmm0_4
  int v17; // eax
  mxScrollbar *v18; // ecx
  int v19; // [esp-8h] [ebp-2Ch]
  tagPOINT pt; // [esp+Ch] [ebp-18h] BYREF
  CChoreoView *pps; // [esp+14h] [ebp-10h] BYREF
  int right; // [esp+18h] [ebp-Ch] BYREF
  int left; // [esp+1Ch] [ebp-8h] BYREF
  float st; // [esp+20h] [ebp-4h] BYREF

  pps = this;
  GetCursorPos(lpPoint: &pt);
  v3 = other;
  Handle = (HWND)mxWidget::getHandle(this: (mxWidget *)LODWORD(other));
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  x = pt.x;
  ExpressionTool::GetWorkspaceLeftRight(this: (ExpressionTool *)LODWORD(v3), &left, &right);
  ExpressionTool::GetStartAndEndTime(this: (ExpressionTool *)LODWORD(v3), &st, ed: &other);
  if ( x >= 0 )
  {
    if ( x <= mxWidget::w2(this: (mxWidget *)LODWORD(v3)) )
      v6 = (float)((float)((float)(x - left) / (float)(right - left)) * (float)(other - st)) + st;
    else
      v6 = other;
  }
  else
  {
    v6 = st;
  }
  v19 = LODWORD(tz);
  other = v6;
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)(LODWORD(v3) + 12));
  CChoreoView::SetTimeZoom(this: pps, tool: Name, tz: v19, preserveFocus: false);
  v8 = pt.x;
  ExpressionTool::GetWorkspaceLeftRight(this: (ExpressionTool *)LODWORD(v3), left: (int *)&pps, &right);
  ExpressionTool::GetStartAndEndTime(this: (ExpressionTool *)LODWORD(v3), &st, ed: &tz);
  if ( v8 >= 0 )
  {
    if ( v8 <= mxWidget::w2(this: (mxWidget *)LODWORD(v3)) )
      v9 = (float)((float)((float)(v8 - (int)pps) / (float)(right - (int)pps)) * (float)(tz - st)) + st;
    else
      v9 = tz;
  }
  else
  {
    v9 = st;
  }
  tz = v9;
  if ( v9 != other )
  {
    v10 = CChoreoChannel::GetName(this: (CChoreoChannel *)(LODWORD(v3) + 12));
    TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v10);
    v12 = (float)(tz - other) * (float)((float)((float)TimeZoom * *(float *)(LODWORD(v3) + 840)) * 0.0099999998);
    *(float *)&pps = (float)((float)TimeZoom * *(float *)(LODWORD(v3) + 840)) * 0.0099999998;
    other = *(float *)(LODWORD(v3) + 828) - v12;
    if ( other < 0.0 )
      other = 0.0;
    SafeEvent = ExpressionTool::GetSafeEvent(this: (ExpressionTool *)LODWORD(v3));
    if ( SafeEvent != nullptr )
    {
      tz = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      v14 = tz;
    }
    else
    {
      v14 = 1.0;
    }
    tz = v14 * *(float *)&pps;
    v15 = mxWidget::w2(this: (mxWidget *)LODWORD(v3));
    v16 = other;
    if ( (float)((float)v15 + other) > tz )
    {
      v17 = mxWidget::w2(this: (mxWidget *)LODWORD(v3));
      v16 = tz - (float)v17;
    }
    v18 = *(mxScrollbar **)(LODWORD(v3) + 832);
    *(float *)(LODWORD(v3) + 828) = v16;
    mxScrollbar::setValue(this: v18, ivalue: (int)v16);
  }
  ExpressionTool::RepositionHSlider(this: (ExpressionTool *)LODWORD(v3));
}

//------------------------------------------------------------------------------
// Address: 0x0045B7B0
// Name: public: void CChoreoView::SetPreservedTimeZoom<class GestureTool>(class GestureTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetPreservedTimeZoom<GestureTool>(CChoreoView *this, GestureTool *other, int tz)
{
  HWND Handle; // eax
  char *Name; // eax
  double TimeValueForMouse; // st7
  char *v8; // eax
  int TimeZoom; // eax
  float v10; // xmm1_4
  CChoreoEvent *SafeEvent; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  tagPOINT pt; // [esp+Ch] [ebp-Ch] BYREF
  float pps; // [esp+14h] [ebp-4h]
  float newOffset; // [esp+20h] [ebp+8h]
  float newOffseta; // [esp+20h] [ebp+8h]
  float eda; // [esp+24h] [ebp+Ch]
  float edb; // [esp+24h] [ebp+Ch]
  float ed; // [esp+24h] [ebp+Ch]

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this: other);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  newOffset = GestureTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
  CChoreoView::SetTimeZoom(this, tool: Name, tz, preserveFocus: false);
  TimeValueForMouse = GestureTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  if ( TimeValueForMouse != newOffset )
  {
    v8 = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
    TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v8);
    eda = TimeValueForMouse;
    v10 = (float)(eda - newOffset) * (float)((float)((float)TimeZoom * other->m_flPixelsPerSecond) * 0.0099999998);
    pps = (float)((float)TimeZoom * other->m_flPixelsPerSecond) * 0.0099999998;
    newOffseta = other->m_flLeftOffset - v10;
    if ( newOffseta < 0.0 )
      newOffseta = 0.0;
    SafeEvent = GestureTool::GetSafeEvent(this: other);
    if ( SafeEvent != nullptr )
    {
      edb = SafeEvent->GetDuration(this: SafeEvent);
      v12 = edb;
    }
    else
    {
      v12 = 1.0;
    }
    ed = v12 * pps;
    v13 = newOffseta;
    if ( (float)((float)mxWidget::w2(this: other) + newOffseta) > ed )
      v13 = ed - (float)mxWidget::w2(this: other);
    m_pHorzScrollBar = other->m_pHorzScrollBar;
    other->m_flLeftOffset = v13;
    mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)v13);
  }
  GestureTool::RepositionHSlider(this: other);
}

//------------------------------------------------------------------------------
// Address: 0x0045C0A0
// Name: public: int CChoreoView::HandleZoomKey<class GestureTool>(class GestureTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::HandleZoomKey<GestureTool>(CChoreoView *this, GestureTool *other, int keyCode)
{
  int result; // eax
  CChoreoEvent *v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // eax
  GestureTool *v9; // esi
  float v10; // xmm0_4
  int v11; // ebx
  CChoreoEvent *SafeEvent; // eax
  int v13; // edi
  int v14; // edi
  int v15; // edi
  float maxtime; // [esp+10h] [ebp+8h]
  float maxtimea; // [esp+10h] [ebp+8h]

  switch ( keyCode )
  {
    case '!':
      v9 = other;
      v10 = other->m_flLeftOffset - (float)mxWidget::w2(this: other);
      if ( v10 <= 0.0 )
        v10 = 0.0;
      goto LABEL_12;
    case '"':
      v9 = other;
      v11 = mxWidget::w2(this: other);
      SafeEvent = GestureTool::GetSafeEvent(this: other);
      if ( SafeEvent != nullptr )
        maxtimea = SafeEvent->GetDuration(this: SafeEvent);
      else
        maxtimea = 1.0;
      v13 = (int)(GestureTool::GetPixelsPerSecond(this: v9) * maxtimea);
      if ( v13 - mxWidget::w2(this: v9) >= 0 )
      {
        v15 = (int)(GestureTool::GetPixelsPerSecond(this: v9) * maxtimea);
        v14 = v15 - mxWidget::w2(this: v9);
      }
      else
      {
        v14 = 0;
      }
      v10 = (float)v11 + v9->m_flLeftOffset;
      if ( (float)v14 <= v10 )
        v10 = (float)v14;
LABEL_12:
      v9->m_flLeftOffset = v10;
      GestureTool::MoveTimeSliderToPos(this: v9, x: (int)v10);
      result = 1;
      break;
    case '#':
      v5 = GestureTool::GetSafeEvent(this: other);
      if ( v5 != nullptr )
        maxtime = v5->GetDuration(this: v5);
      else
        maxtime = 1.0;
      v6 = (int)(GestureTool::GetPixelsPerSecond(this: other) * maxtime);
      if ( v6 - mxWidget::w2(this: other) >= 0 )
      {
        v7 = (int)(GestureTool::GetPixelsPerSecond(this: other) * maxtime);
        v8 = mxWidget::w2(this: other);
        GestureTool::MoveTimeSliderToPos(this: other, x: v7 - v8);
      }
      else
      {
        GestureTool::MoveTimeSliderToPos(this: other, x: 0);
      }
      result = 1;
      break;
    case '$':
      GestureTool::MoveTimeSliderToPos(this: other, x: 0);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00479A10
// Name: public: void CChoreoView::SetPreservedTimeZoom<class RampTool>(class RampTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetPreservedTimeZoom<RampTool>(CChoreoView *this, GestureTool *other, int tz)
{
  HWND Handle; // eax
  char *Name; // eax
  double TimeValueForMouse; // st7
  char *v8; // eax
  int TimeZoom; // eax
  float v10; // xmm1_4
  IterateRIFF *SafeEvent; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  tagPOINT pt; // [esp+Ch] [ebp-Ch] BYREF
  float pps; // [esp+14h] [ebp-4h]
  float newOffset; // [esp+20h] [ebp+8h]
  float newOffseta; // [esp+20h] [ebp+8h]
  float eda; // [esp+24h] [ebp+Ch]
  float edb; // [esp+24h] [ebp+Ch]
  float ed; // [esp+24h] [ebp+Ch]

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this: other);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  newOffset = GestureTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
  CChoreoView::SetTimeZoom(this, tool: Name, tz, preserveFocus: false);
  TimeValueForMouse = GestureTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  if ( TimeValueForMouse != newOffset )
  {
    v8 = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
    TimeZoom = CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v8);
    eda = TimeValueForMouse;
    v10 = (float)(eda - newOffset) * (float)((float)((float)TimeZoom * other->m_flPixelsPerSecond) * 0.0099999998);
    pps = (float)((float)TimeZoom * other->m_flPixelsPerSecond) * 0.0099999998;
    newOffseta = other->m_flLeftOffset - v10;
    if ( newOffseta < 0.0 )
      newOffseta = 0.0;
    SafeEvent = RampTool::GetSafeEvent(this: (RampTool *)other);
    if ( SafeEvent != nullptr )
    {
      edb = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      v12 = edb;
    }
    else
    {
      v12 = 1.0;
    }
    ed = v12 * pps;
    v13 = newOffseta;
    if ( (float)((float)mxWidget::w2(this: other) + newOffseta) > ed )
      v13 = ed - (float)mxWidget::w2(this: other);
    m_pHorzScrollBar = other->m_pHorzScrollBar;
    other->m_flLeftOffset = v13;
    mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)v13);
  }
  RampTool::RepositionHSlider(this: (RampTool *)other);
}

//------------------------------------------------------------------------------
// Address: 0x00479B70
// Name: public: void CCurveEditorHelper<class RampTool>::SetCurveTypeForSample(int,struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<RampTool>::SetCurveTypeForSample(
        CCurveEditorHelper<RampTool> *this,
        __int16 curvetype,
        CExpressionSample *sample)
{
  RampTool *m_pOuter; // esi
  RampTool *v5; // esi

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
  }
  ++m_pOuter->m_nUndoSetup;
  *((_WORD *)sample + 4) = (2 * curvetype) | *((_WORD *)sample + 4) & 1;
  v5 = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
    v5->redraw(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479BF0
// Name: public: void CCurveEditorHelper<class RampTool>::ToggleHoldTypeForSample(struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<RampTool>::ToggleHoldTypeForSample(
        CCurveEditorHelper<RampTool> *this,
        CExpressionSample *sample)
{
  RampTool *m_pOuter; // esi
  int v4; // ecx
  __int16 v5; // dx
  RampTool *v6; // esi
  int l; // [esp+8h] [ebp-8h] BYREF
  int r; // [esp+Ch] [ebp-4h] BYREF

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
  }
  ++m_pOuter->m_nUndoSetup;
  Interpolator_CurveInterpolatorsForType(type: *((_WORD *)sample + 4) >> 1, inbound: &l, outbound: &r);
  v4 = 15;
  if ( r == 15 )
    v4 = l;
  v5 = *((_WORD *)sample + 4);
  r = v4;
  *((_WORD *)sample + 4) = v5 & 1 | (2 * (((_WORD)l << 8) | (unsigned __int8)v4));
  v6 = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
    v6->redraw(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047A0D0
// Name: public: int CChoreoView::HandleZoomKey<class RampTool>(class RampTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::HandleZoomKey<RampTool>(CChoreoView *this, GestureTool *other, int keyCode)
{
  int result; // eax
  IterateRIFF *v5; // eax
  int v6; // edi
  int v7; // edi
  int v8; // eax
  GestureTool *v9; // esi
  float v10; // xmm0_4
  int v11; // ebx
  IterateRIFF *SafeEvent; // eax
  int v13; // edi
  int v14; // edi
  int v15; // edi
  float maxtime; // [esp+10h] [ebp+8h]
  float maxtimea; // [esp+10h] [ebp+8h]

  switch ( keyCode )
  {
    case '!':
      v9 = other;
      v10 = other->m_flLeftOffset - (float)mxWidget::w2(this: other);
      if ( v10 <= 0.0 )
        v10 = 0.0;
      goto LABEL_12;
    case '"':
      v9 = other;
      v11 = mxWidget::w2(this: other);
      SafeEvent = RampTool::GetSafeEvent(this: (RampTool *)other);
      if ( SafeEvent != nullptr )
        maxtimea = ((double (__thiscall *)(IterateRIFF *))SafeEvent->m_riff->m_io)(a1: SafeEvent);
      else
        maxtimea = 1.0;
      v13 = (int)(GestureTool::GetPixelsPerSecond(this: v9) * maxtimea);
      if ( v13 - mxWidget::w2(this: v9) >= 0 )
      {
        v15 = (int)(GestureTool::GetPixelsPerSecond(this: v9) * maxtimea);
        v14 = v15 - mxWidget::w2(this: v9);
      }
      else
      {
        v14 = 0;
      }
      v10 = (float)v11 + v9->m_flLeftOffset;
      if ( (float)v14 <= v10 )
        v10 = (float)v14;
LABEL_12:
      v9->m_flLeftOffset = v10;
      RampTool::MoveTimeSliderToPos(this: (RampTool *)v9, x: (int)v10);
      result = 1;
      break;
    case '#':
      v5 = RampTool::GetSafeEvent(this: (RampTool *)other);
      if ( v5 != nullptr )
        maxtime = ((double (__thiscall *)(IterateRIFF *))v5->m_riff->m_io)(a1: v5);
      else
        maxtime = 1.0;
      v6 = (int)(GestureTool::GetPixelsPerSecond(this: other) * maxtime);
      if ( v6 - mxWidget::w2(this: other) >= 0 )
      {
        v7 = (int)(GestureTool::GetPixelsPerSecond(this: other) * maxtime);
        v8 = mxWidget::w2(this: other);
        RampTool::MoveTimeSliderToPos(this: (RampTool *)other, x: v7 - v8);
      }
      else
      {
        RampTool::MoveTimeSliderToPos(this: (RampTool *)other, x: 0);
      }
      result = 1;
      break;
    case '$':
      RampTool::MoveTimeSliderToPos(this: (RampTool *)other, x: 0);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047B730
// Name: public: int CCurveEditorHelper<class RampTool>::CountSelected(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<RampTool>::CountSelected(CCurveEditorHelper<RampTool> *this, bool reflect)
{
  int v2; // ebx
  RampTool *m_pOuter; // edi
  int v4; // esi
  RampTool **m_pMemory; // eax
  RampTool **v6; // edi
  IterateRIFF *SafeEvent; // eax
  int NumChannels; // eax
  int v9; // ebx
  int v10; // esi
  IterateRIFF *v11; // eax
  CExpressionSample *v12; // eax
  CUtlVector<RampTool *,CUtlMemory<RampTool *,int> > workList; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  int numSelected; // [esp+24h] [ebp-4h]

  v2 = 0;
  m_pOuter = this->m_pOuter;
  numSelected = 0;
  memset(&workList, 0, sizeof(workList));
  CUtlMemory<IFacePoserToolWindow *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
    num: 1);
  v4 = workList.m_Size + 1;
  if ( workList.m_Size > 0 )
    _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
  m_pMemory = workList.m_Memory.m_pMemory;
  if ( workList.m_Memory.m_pMemory != nullptr )
    *workList.m_Memory.m_pMemory = m_pOuter;
  if ( v4 > 0 )
  {
    v6 = m_pMemory;
    for ( i = v4; i != 0; --i )
    {
      SafeEvent = RampTool::GetSafeEvent(this: *v6);
      if ( SafeEvent != nullptr )
      {
        NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
        v9 = NumChannels;
        if ( NumChannels != 0 )
        {
          v10 = 0;
          if ( NumChannels > 0 )
          {
            do
            {
              v11 = RampTool::GetSafeEvent(this: *v6);
              if ( v11 != nullptr )
              {
                v12 = CCurveData::Get(this: (CCurveData *)&v11[3].m_chunkPosition, index: v10);
                if ( v12 != nullptr && (*((_BYTE *)v12 + 8) & 1) != 0 )
                  ++numSelected;
              }
              ++v10;
            }
            while ( v10 < v9 );
          }
        }
      }
      ++v6;
    }
    m_pMemory = workList.m_Memory.m_pMemory;
    v2 = numSelected;
  }
  if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0047B810
// Name: public: void CCurveEditorHelper<class RampTool>::SetCurveTypeForSelectedSamples(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<RampTool>::SetCurveTypeForSelectedSamples(
        CCurveEditorHelper<RampTool> *this,
        bool reflect,
        __int16 curvetype)
{
  RampTool *m_pOuter; // esi
  RampTool *v5; // edi
  int v6; // esi
  RampTool **m_pMemory; // ebx
  IterateRIFF *SafeEvent; // eax
  signed int NumChannels; // esi
  int i; // edi
  IterateRIFF *v11; // eax
  RampTool *v12; // esi
  CUtlVector<RampTool *,CUtlMemory<RampTool *,int> > workList; // [esp+4h] [ebp-18h] BYREF
  CCurveEditorHelper<RampTool> *v15; // [esp+18h] [ebp-4h]
  int reflecta; // [esp+24h] [ebp+8h]

  v15 = this;
  if ( CCurveEditorHelper<RampTool>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = this->m_pOuter;
    if ( this->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
    }
    ++m_pOuter->m_nUndoSetup;
    v5 = this->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v6 = workList.m_Size + 1;
    m_pMemory = workList.m_Memory.m_pMemory;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    if ( m_pMemory != nullptr )
      *m_pMemory = v5;
    if ( v6 > 0 )
    {
      for ( reflecta = v6; reflecta != 0; --reflecta )
      {
        SafeEvent = RampTool::GetSafeEvent(this: *m_pMemory);
        if ( SafeEvent != nullptr )
          NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
        else
          NumChannels = 0;
        for ( i = 0; i < NumChannels; ++i )
        {
          v11 = RampTool::GetSafeEvent(this: *m_pMemory);
          if ( v11 != nullptr )
            v11 = (IterateRIFF *)CCurveData::Get(this: (CCurveData *)&v11[3].m_chunkPosition, index: i);
          if ( (v11->m_size & 1) != 0 )
            LOWORD(v11->m_size) = v11->m_size & 1 | (2 * curvetype);
        }
        ++m_pMemory;
      }
      m_pMemory = workList.m_Memory.m_pMemory;
    }
    v12 = v15->m_pOuter;
    if ( v15->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
      v12->redraw(this: v12);
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047B960
// Name: public: void CCurveEditorHelper<class RampTool>::ToggleHoldTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<RampTool>::ToggleHoldTypeForSelectedSamples(
        CCurveEditorHelper<RampTool> *this,
        bool reflect)
{
  RampTool *m_pOuter; // esi
  RampTool *v4; // edi
  int v5; // esi
  RampTool **m_pMemory; // ebx
  IterateRIFF *SafeEvent; // eax
  int v8; // edi
  int j; // ebx
  IterateRIFF *v10; // eax
  CExpressionSample *v11; // esi
  unsigned __int8 v12; // cl
  RampTool *v13; // esi
  CUtlVector<RampTool *,CUtlMemory<RampTool *,int> > workList; // [esp+4h] [ebp-28h] BYREF
  CCurveEditorHelper<RampTool> *v16; // [esp+18h] [ebp-14h]
  int l; // [esp+1Ch] [ebp-10h] BYREF
  int r; // [esp+20h] [ebp-Ch] BYREF
  int i; // [esp+24h] [ebp-8h]
  int numSamples; // [esp+28h] [ebp-4h]
  RampTool **reflecta; // [esp+34h] [ebp+8h]

  v16 = this;
  if ( CCurveEditorHelper<RampTool>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = this->m_pOuter;
    if ( this->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
    }
    ++m_pOuter->m_nUndoSetup;
    v4 = this->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v5 = workList.m_Size + 1;
    m_pMemory = workList.m_Memory.m_pMemory;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    if ( m_pMemory != nullptr )
      *m_pMemory = v4;
    if ( v5 > 0 )
    {
      reflecta = m_pMemory;
      for ( i = v5; i != 0; --i )
      {
        SafeEvent = RampTool::GetSafeEvent(this: *reflecta);
        if ( SafeEvent != nullptr )
          numSamples = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
        else
          numSamples = 0;
        v8 = 0;
        for ( j = -1; v8 < numSamples; ++v8 )
        {
          v10 = RampTool::GetSafeEvent(this: *reflecta);
          if ( v10 != nullptr )
            v11 = CCurveData::Get(this: (CCurveData *)&v10[3].m_chunkPosition, index: v8);
          else
            v11 = nullptr;
          if ( (*((_WORD *)v11 + 4) & 1) != 0 )
          {
            Interpolator_CurveInterpolatorsForType(type: *((_WORD *)v11 + 4) >> 1, inbound: &l, outbound: &r);
            if ( j == -1 )
              j = r != 15;
            v12 = 15;
            if ( j != 1 )
              v12 = l;
            *((_WORD *)v11 + 4) = *((_WORD *)v11 + 4) & 1 | (2 * (((_WORD)l << 8) | v12));
          }
        }
        ++reflecta;
      }
      m_pMemory = workList.m_Memory.m_pMemory;
    }
    v13 = v16->m_pOuter;
    if ( v16->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
      v13->redraw(this: v13);
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C350
// Name: public: int CCurveEditorHelper<class RampTool>::GetBestCurveTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<RampTool>::GetBestCurveTypeForSelectedSamples(
        CCurveEditorHelper<RampTool> *this,
        BOOL reflect)
{
  int result; // eax
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v4; // ebx
  RampTool *m_pOuter; // edi
  int v6; // esi
  RampTool **m_pMemory; // eax
  IterateRIFF *SafeEvent; // eax
  unsigned int NumChannels; // eax
  const char *v10; // edi
  IterateRIFF *v11; // eax
  unsigned int m_size_low; // eax
  int v13; // esi
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // dx
  int v17; // ecx
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v18; // eax
  unsigned __int16 v19; // di
  int v20; // esi
  int v21; // edx
  bool v22; // zf
  int key; // esi
  unsigned __int16 j; // ax
  CUtlMap<int,int,unsigned short> counts; // [esp+4h] [ebp-50h] BYREF
  CUtlVector<RampTool *,CUtlMemory<RampTool *,int> > workList; // [esp+20h] [ebp-34h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+34h] [ebp-20h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t insert; // [esp+3Ch] [ebp-18h] BYREF
  int v29; // [esp+44h] [ebp-10h]
  int i; // [esp+48h] [ebp-Ch]
  unsigned __int16 parent[2]; // [esp+4Ch] [ebp-8h] BYREF
  RampTool **v32; // [esp+50h] [ebp-4h]

  result = CCurveEditorHelper<RampTool>::CountSelected(this, reflect);
  if ( result != 0 )
  {
    v4 = nullptr;
    m_pOuter = this->m_pOuter;
    counts.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
    memset(&counts.m_Tree.m_Elements, 0, sizeof(counts.m_Tree.m_Elements));
    *(_DWORD *)&counts.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&counts.m_Tree.m_FirstFree = -1;
    counts.m_Tree.m_pElements = nullptr;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v6 = workList.m_Size + 1;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    m_pMemory = workList.m_Memory.m_pMemory;
    if ( workList.m_Memory.m_pMemory != nullptr )
      *workList.m_Memory.m_pMemory = m_pOuter;
    if ( v6 > 0 )
    {
      v32 = m_pMemory;
      v29 = v6;
      do
      {
        SafeEvent = RampTool::GetSafeEvent(this: *m_pMemory);
        if ( SafeEvent != nullptr )
        {
          NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)((char *)SafeEvent + 92));
          if ( NumChannels != 0 )
          {
            v10 = (const char *)(NumChannels - 1);
            i = NumChannels - 1;
            if ( (int)(NumChannels - 1) >= 0 )
            {
              do
              {
                v11 = RampTool::GetSafeEvent(this: *v32);
                if ( v11 != nullptr )
                  v11 = (IterateRIFF *)CCurveData::Get(this: (CCurveData *)&v11[3].m_chunkPosition, index: (int)v10);
                m_size_low = LOWORD(v11->m_size);
                if ( (m_size_low & 1) != 0 )
                {
                  v13 = m_size_low >> 1;
                  search.key = m_size_low >> 1;
                  v14 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                          this: &counts.m_Tree,
                          &search);
                  if ( v14 == 0xFFFF )
                  {
                    *(_DWORD *)parent = 0xFFFF;
                    insert.key = v13;
                    insert.elem = 0;
                    HIBYTE(reflect) = 0;
                    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
                      this: &counts.m_Tree,
                      &insert,
                      parent,
                      leftchild: (bool *)&reflect + 3);
                    v15 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                            this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&counts,
                            a2: v10);
                    v16 = parent[0];
                    v17 = v15;
                    v18 = counts.m_Tree.m_Elements.m_pMemory;
                    v19 = v17;
                    v20 = v17;
                    counts.m_Tree.m_Elements.m_pMemory[v20].m_Right = -1;
                    v18[v20].m_Left = -1;
                    v18[v20].m_Tag = 0;
                    v18[v20].m_Parent = v16;
                    if ( v16 == 0xFFFF )
                    {
                      counts.m_Tree.m_Root = v17;
                    }
                    else
                    {
                      v21 = v16;
                      if ( HIBYTE(reflect) != 0 )
                        v18[v21].m_Left = v17;
                      else
                        v18[v21].m_Right = v17;
                    }
                    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
                      this: &counts.m_Tree,
                      elem: v17);
                    v4 = counts.m_Tree.m_Elements.m_pMemory;
                    ++counts.m_Tree.m_NumElements;
                    if ( &counts.m_Tree.m_Elements.m_pMemory[v20] != (UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *)-8 )
                      counts.m_Tree.m_Elements.m_pMemory[v20].m_Data = insert;
                    v14 = v19;
                    v10 = (const char *)i;
                  }
                  ++v4[v14].m_Data.elem;
                }
                i = (int)--v10;
              }
              while ( (int)v10 >= 0 );
            }
          }
        }
        m_pMemory = v32 + 1;
        v22 = v29-- == 1;
        ++v32;
      }
      while ( !v22 );
    }
    key = 0;
    for ( j = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &counts.m_Tree);
          j != 0xFFFF;
          j = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &counts.m_Tree,
                i: j) )
    {
      if ( v4[j].m_Data.elem > key )
        key = v4[j].m_Data.key;
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && workList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &counts.m_Tree);
    if ( counts.m_Tree.m_Elements.m_nGrowSize >= 0 && counts.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: counts.m_Tree.m_Elements.m_pMemory);
    return key;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047C5D0
// Name: public: void CCurveEditorHelper<class RampTool>::ChangeCurveType(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<RampTool>::ChangeCurveType(
        CCurveEditorHelper<RampTool> *this,
        bool forward,
        bool shiftdown,
        bool altdown)
{
  bool v5; // bl
  __int16 BestCurveTypeForSelectedSamples; // ax
  int v7; // eax
  int v8; // edx
  bool v9; // zf
  bool v10; // sf
  int sides[2]; // [esp+8h] [ebp-8h] BYREF

  v5 = !shiftdown || altdown;
  if ( CCurveEditorHelper<RampTool>::CountSelected(this, reflect: false) != 0 )
  {
    BestCurveTypeForSelectedSamples = CCurveEditorHelper<RampTool>::GetBestCurveTypeForSelectedSamples(
                                        this,
                                        reflect: false);
    Interpolator_CurveInterpolatorsForType(type: BestCurveTypeForSelectedSamples, inbound: sides, outbound: &sides[1]);
    v7 = 0;
    v8 = 2 * forward - 1;
    while ( 1 )
    {
      if ( v7 != 0 )
      {
        if ( v7 != 1 )
          goto LABEL_12;
        v9 = !v5;
      }
      else
      {
        v9 = !shiftdown;
      }
      if ( !v9 )
      {
LABEL_12:
        v10 = v8 + sides[v7] < 0;
        sides[v7] += v8;
        if ( v10 )
        {
          sides[v7] = 15;
        }
        else if ( sides[v7] >= 16 )
        {
          sides[v7] = 0;
        }
      }
      if ( ++v7 >= 2 )
      {
        CCurveEditorHelper<RampTool>::SetCurveTypeForSelectedSamples(
          this,
          reflect: false,
          curvetype: LOBYTE(sides[1]) | (LOBYTE(sides[0]) << 8));
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047C690
// Name: public: bool CCurveEditorHelper<class RampTool>::HelperHandleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurveEditorHelper<RampTool>::HelperHandleEvent(CCurveEditorHelper<RampTool> *this, mxEvent *event)
{
  int key; // ecx
  int v5; // eax
  __int16 v6; // bx
  CExpressionSample *v7; // eax
  CExpressionSample *SampleUnderMouse; // eax
  bool shiftdown; // [esp+13h] [ebp-5h]
  bool shiftdowna; // [esp+13h] [ebp-5h]
  bool handled; // [esp+17h] [ebp-1h]
  bool altdown; // [esp+20h] [ebp+8h]
  bool altdowna; // [esp+20h] [ebp+8h]
  bool altdownb; // [esp+20h] [ebp+8h]
  bool altdownc; // [esp+20h] [ebp+8h]

  handled = false;
  if ( event->event == 11 )
  {
    key = event->key;
    if ( key == 38 )
    {
      shiftdowna = GetAsyncKeyState(vKey: 16) != 0;
      altdownc = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
        CCurveEditorHelper<RampTool>::ChangeCurveType(this, forward: false, shiftdown: shiftdowna, altdown: altdownc);
    }
    else if ( event->key == 40 )
    {
      shiftdown = GetAsyncKeyState(vKey: 16) != 0;
      altdownb = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
      {
        CCurveEditorHelper<RampTool>::ChangeCurveType(this, forward: true, shiftdown, altdown: altdownb);
        return 0;
      }
    }
    else if ( event->key == 72 )
    {
      handled = true;
      altdowna = GetAsyncKeyState(vKey: 16) != 0;
      if ( CCurveEditorHelper<RampTool>::CountSelected(this, reflect: altdowna) > 0 )
      {
        CCurveEditorHelper<RampTool>::ToggleHoldTypeForSelectedSamples(this, reflect: altdowna);
        return 1;
      }
      RampTool::SetMousePositionForEvent(this: this->m_pOuter, event);
      SampleUnderMouse = RampTool::GetSampleUnderMouse(this: this->m_pOuter, mx: event->x, my: event->y, tolerance: 0.0);
      if ( SampleUnderMouse != nullptr )
      {
        CCurveEditorHelper<RampTool>::ToggleHoldTypeForSample(this, sample: SampleUnderMouse);
        return 1;
      }
    }
    else if ( key >= 48 && key <= 57 )
    {
      altdown = GetAsyncKeyState(vKey: 16) != 0;
      handled = true;
      v5 = Interpolator_CurveTypeForHotkey(key: event->key);
      v6 = v5;
      if ( v5 >= 0 )
      {
        if ( CCurveEditorHelper<RampTool>::CountSelected(this, reflect: altdown) > 0 )
        {
          CCurveEditorHelper<RampTool>::SetCurveTypeForSelectedSamples(this, reflect: altdown, curvetype: v6);
          return 1;
        }
        RampTool::SetMousePositionForEvent(this: this->m_pOuter, event);
        v7 = RampTool::GetSampleUnderMouse(this: this->m_pOuter, mx: event->x, my: event->y, tolerance: 0.0);
        if ( v7 != nullptr )
        {
          CCurveEditorHelper<RampTool>::SetCurveTypeForSample(this, curvetype: v6, sample: v7);
          return 1;
        }
      }
    }
  }
  return handled;
}

//------------------------------------------------------------------------------
// Address: 0x0047F260
// Name: public: void CChoreoView::SetPreservedTimeZoom<class SceneRampTool>(class SceneRampTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChoreoView::SetPreservedTimeZoom<SceneRampTool>(CChoreoView *this, SceneRampTool *other, int tz)
{
  HWND Handle; // eax
  char *Name; // eax
  double TimeValueForMouse; // st7
  char *v8; // eax
  float v9; // xmm0_4
  CChoreoScene *Scene; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  mxScrollbar *m_pHorzScrollBar; // ecx
  tagPOINT pt; // [esp+Ch] [ebp-Ch] BYREF
  float ed; // [esp+14h] [ebp-4h]
  float newOffset; // [esp+20h] [ebp+8h]
  float newOffseta; // [esp+20h] [ebp+8h]
  float pps; // [esp+24h] [ebp+Ch]

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this: other);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  newOffset = SceneRampTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  Name = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
  CChoreoView::SetTimeZoom(this, tool: Name, tz, preserveFocus: false);
  TimeValueForMouse = SceneRampTool::GetTimeValueForMouse(this: other, mx: pt.x, clip: true);
  ed = TimeValueForMouse;
  if ( TimeValueForMouse != newOffset )
  {
    v8 = CChoreoChannel::GetName(this: (CChoreoChannel *)&other->IFacePoserToolWindow);
    v9 = (float)((float)CChoreoView::GetTimeZoom(this: g_pChoreoView, tool: v8) * other->m_flPixelsPerSecond)
       * 0.0099999998;
    newOffseta = other->m_flLeftOffset - (float)((float)(ed - newOffset) * v9);
    if ( newOffseta < 0.0 )
      newOffseta = 0.0;
    if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
    {
      ed = CChoreoScene::FindStopTime(this: Scene);
      v11 = ed;
    }
    else
    {
      v11 = 1.0;
    }
    pps = v11 * v9;
    v12 = newOffseta;
    if ( (float)((float)mxWidget::w2(this: other) + newOffseta) > pps )
      v12 = pps - (float)mxWidget::w2(this: other);
    m_pHorzScrollBar = other->m_pHorzScrollBar;
    other->m_flLeftOffset = v12;
    mxScrollbar::setValue(this: m_pHorzScrollBar, ivalue: (int)v12);
  }
  SceneRampTool::RepositionHSlider(this: other);
}

//------------------------------------------------------------------------------
// Address: 0x0047F3D0
// Name: public: void CCurveEditorHelper<class SceneRampTool>::SetCurveTypeForSample(int,struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<SceneRampTool>::SetCurveTypeForSample(
        CCurveEditorHelper<SceneRampTool> *this,
        __int16 curvetype,
        CExpressionSample *sample)
{
  SceneRampTool *m_pOuter; // esi
  SceneRampTool *v5; // esi

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
  }
  ++m_pOuter->m_nUndoSetup;
  *((_WORD *)sample + 4) = (2 * curvetype) | *((_WORD *)sample + 4) & 1;
  v5 = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
    v5->redraw(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F450
// Name: public: void CCurveEditorHelper<class SceneRampTool>::ToggleHoldTypeForSample(struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<SceneRampTool>::ToggleHoldTypeForSample(
        CCurveEditorHelper<SceneRampTool> *this,
        CExpressionSample *sample)
{
  SceneRampTool *m_pOuter; // esi
  int v4; // ecx
  __int16 v5; // dx
  SceneRampTool *v6; // esi
  int l; // [esp+8h] [ebp-8h] BYREF
  int r; // [esp+Ch] [ebp-4h] BYREF

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
  }
  ++m_pOuter->m_nUndoSetup;
  Interpolator_CurveInterpolatorsForType(type: *((_WORD *)sample + 4) >> 1, inbound: &l, outbound: &r);
  v4 = 15;
  if ( r == 15 )
    v4 = l;
  v5 = *((_WORD *)sample + 4);
  r = v4;
  *((_WORD *)sample + 4) = v5 & 1 | (2 * (((_WORD)l << 8) | (unsigned __int8)v4));
  v6 = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
    v6->redraw(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047F770
// Name: public: int CChoreoView::HandleZoomKey<class SceneRampTool>(class SceneRampTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::HandleZoomKey<SceneRampTool>(CChoreoView *this, SceneRampTool *other, int keyCode)
{
  int result; // eax
  CChoreoScene *v4; // eax
  int v5; // esi
  int v6; // esi
  int v7; // eax
  SceneRampTool *v8; // esi
  float v9; // xmm0_4
  int v10; // ebx
  CChoreoScene *Scene; // eax
  int v12; // edi
  int v13; // edi
  int v14; // edi
  float othera; // [esp+10h] [ebp+8h]
  float maxtime; // [esp+14h] [ebp+Ch]

  switch ( keyCode )
  {
    case '!':
      v8 = other;
      v9 = other->m_flLeftOffset - (float)mxWidget::w2(this: other);
      if ( v9 <= 0.0 )
        v9 = 0.0;
      goto LABEL_13;
    case '"':
      v8 = other;
      v10 = mxWidget::w2(this: other);
      if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
        othera = CChoreoScene::FindStopTime(this: Scene);
      else
        othera = 1.0;
      v12 = (int)(SceneRampTool::GetPixelsPerSecond(this: v8) * othera);
      if ( v12 - mxWidget::w2(this: v8) >= 0 )
      {
        v14 = (int)(SceneRampTool::GetPixelsPerSecond(this: v8) * othera);
        v13 = v14 - mxWidget::w2(this: v8);
      }
      else
      {
        v13 = 0;
      }
      v9 = (float)v10 + v8->m_flLeftOffset;
      if ( (float)v13 <= v9 )
        v9 = (float)v13;
LABEL_13:
      v8->m_flLeftOffset = v9;
      SceneRampTool::MoveTimeSliderToPos(this: v8, x: (int)v9);
      result = 1;
      break;
    case '#':
      if ( g_pChoreoView != nullptr && (v4 = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
        maxtime = CChoreoScene::FindStopTime(this: v4);
      else
        maxtime = 1.0;
      v5 = (int)(SceneRampTool::GetPixelsPerSecond(this: other) * maxtime);
      if ( v5 - mxWidget::w2(this: other) >= 0 )
      {
        v6 = (int)(SceneRampTool::GetPixelsPerSecond(this: other) * maxtime);
        v7 = mxWidget::w2(this: other);
        SceneRampTool::MoveTimeSliderToPos(this: other, x: v6 - v7);
      }
      else
      {
        SceneRampTool::MoveTimeSliderToPos(this: other, x: 0);
      }
      result = 1;
      break;
    case '$':
      SceneRampTool::MoveTimeSliderToPos(this: other, x: 0);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0047FF70
// Name: public: int CCurveEditorHelper<class SceneRampTool>::CountSelected(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<SceneRampTool>::CountSelected(CCurveEditorHelper<SceneRampTool> *this, bool reflect)
{
  SceneRampTool *m_pOuter; // edi
  int v3; // esi
  SceneRampTool **m_pMemory; // eax
  CChoreoScene *Scene; // eax
  int NumChannels; // eax
  int v7; // edi
  int v8; // esi
  CChoreoScene *v9; // eax
  CExpressionSample *v10; // eax
  CUtlVector<SceneRampTool *,CUtlMemory<SceneRampTool *,int> > workList; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  int numSelected; // [esp+24h] [ebp-4h]

  m_pOuter = this->m_pOuter;
  numSelected = 0;
  memset(&workList, 0, sizeof(workList));
  CUtlMemory<IFacePoserToolWindow *,int>::Grow(
    this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
    num: 1);
  v3 = workList.m_Size + 1;
  if ( workList.m_Size > 0 )
    _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
  m_pMemory = workList.m_Memory.m_pMemory;
  if ( workList.m_Memory.m_pMemory != nullptr )
    *workList.m_Memory.m_pMemory = m_pOuter;
  if ( v3 > 0 )
  {
    for ( i = v3; i != 0; --i )
    {
      if ( g_pChoreoView != nullptr )
      {
        Scene = CChoreoView::GetScene(this: g_pChoreoView);
        if ( Scene != nullptr )
        {
          NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
          v7 = NumChannels;
          if ( NumChannels != 0 )
          {
            v8 = 0;
            if ( NumChannels > 0 )
            {
              do
              {
                if ( g_pChoreoView != nullptr )
                {
                  v9 = CChoreoView::GetScene(this: g_pChoreoView);
                  if ( v9 != nullptr )
                  {
                    v10 = CCurveData::Get(this: &v9->m_SceneRamp, index: v8);
                    if ( v10 != nullptr && (*((_BYTE *)v10 + 8) & 1) != 0 )
                      ++numSelected;
                  }
                }
                ++v8;
              }
              while ( v8 < v7 );
            }
          }
        }
      }
    }
    m_pMemory = workList.m_Memory.m_pMemory;
  }
  if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return numSelected;
}

//------------------------------------------------------------------------------
// Address: 0x00480060
// Name: public: void CCurveEditorHelper<class SceneRampTool>::SetCurveTypeForSelectedSamples(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<SceneRampTool>::SetCurveTypeForSelectedSamples(
        CCurveEditorHelper<SceneRampTool> *this,
        bool reflect,
        __int16 curvetype)
{
  SceneRampTool *m_pOuter; // esi
  SceneRampTool *v5; // edi
  int v6; // esi
  CChoreoScene *Scene; // eax
  signed int NumChannels; // esi
  int i; // edi
  CChoreoScene *v10; // eax
  CExpressionSample *v11; // eax
  SceneRampTool *v12; // esi
  CUtlVector<SceneRampTool *,CUtlMemory<SceneRampTool *,int> > workList; // [esp+4h] [ebp-18h] BYREF
  CCurveEditorHelper<SceneRampTool> *v15; // [esp+18h] [ebp-4h]
  int reflecta; // [esp+24h] [ebp+8h]

  v15 = this;
  if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = this->m_pOuter;
    if ( this->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
    }
    ++m_pOuter->m_nUndoSetup;
    v5 = this->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v6 = workList.m_Size + 1;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    if ( workList.m_Memory.m_pMemory != nullptr )
      *workList.m_Memory.m_pMemory = v5;
    if ( v6 > 0 )
    {
      for ( reflecta = v6; reflecta != 0; --reflecta )
      {
        if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
          NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
        else
          NumChannels = 0;
        for ( i = 0; i < NumChannels; ++i )
        {
          if ( g_pChoreoView != nullptr && (v10 = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
            v11 = CCurveData::Get(this: &v10->m_SceneRamp, index: i);
          else
            v11 = nullptr;
          if ( (*((_WORD *)v11 + 4) & 1) != 0 )
            *((_WORD *)v11 + 4) = *((_WORD *)v11 + 4) & 1 | (2 * curvetype);
        }
      }
    }
    v12 = v15->m_pOuter;
    if ( v15->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
      v12->redraw(this: v12);
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && workList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004801C0
// Name: public: void CCurveEditorHelper<class SceneRampTool>::ToggleHoldTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<SceneRampTool>::ToggleHoldTypeForSelectedSamples(
        CCurveEditorHelper<SceneRampTool> *this,
        bool reflect)
{
  SceneRampTool *m_pOuter; // esi
  SceneRampTool *v4; // edi
  int v5; // esi
  SceneRampTool **m_pMemory; // ebx
  CChoreoScene *Scene; // eax
  int v8; // edi
  int j; // ebx
  CChoreoScene *v10; // eax
  CExpressionSample *v11; // esi
  unsigned __int8 v12; // cl
  SceneRampTool *v13; // esi
  CUtlVector<SceneRampTool *,CUtlMemory<SceneRampTool *,int> > workList; // [esp+4h] [ebp-24h] BYREF
  CCurveEditorHelper<SceneRampTool> *v16; // [esp+18h] [ebp-10h]
  int l; // [esp+1Ch] [ebp-Ch] BYREF
  int r; // [esp+20h] [ebp-8h] BYREF
  int i; // [esp+24h] [ebp-4h]
  int numSamples; // [esp+30h] [ebp+8h]

  v16 = this;
  if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = this->m_pOuter;
    if ( this->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
    }
    ++m_pOuter->m_nUndoSetup;
    v4 = this->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v5 = workList.m_Size + 1;
    m_pMemory = workList.m_Memory.m_pMemory;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    if ( m_pMemory != nullptr )
      *m_pMemory = v4;
    if ( v5 > 0 )
    {
      for ( i = v5; i != 0; --i )
      {
        if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
          numSamples = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
        else
          numSamples = 0;
        v8 = 0;
        for ( j = -1; v8 < numSamples; ++v8 )
        {
          if ( g_pChoreoView != nullptr && (v10 = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
            v11 = CCurveData::Get(this: &v10->m_SceneRamp, index: v8);
          else
            v11 = nullptr;
          if ( (*((_WORD *)v11 + 4) & 1) != 0 )
          {
            Interpolator_CurveInterpolatorsForType(type: *((_WORD *)v11 + 4) >> 1, inbound: &l, outbound: &r);
            if ( j == -1 )
              j = r != 15;
            v12 = 15;
            if ( j != 1 )
              v12 = l;
            *((_WORD *)v11 + 4) = *((_WORD *)v11 + 4) & 1 | (2 * (((_WORD)l << 8) | v12));
          }
        }
      }
      m_pMemory = workList.m_Memory.m_pMemory;
    }
    v13 = v16->m_pOuter;
    if ( v16->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
      v13->redraw(this: v13);
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480C00
// Name: public: int CCurveEditorHelper<class SceneRampTool>::GetBestCurveTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<SceneRampTool>::GetBestCurveTypeForSelectedSamples(
        CCurveEditorHelper<SceneRampTool> *this,
        BOOL reflect)
{
  int result; // eax
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *v4; // ebx
  SceneRampTool *m_pOuter; // edi
  int v6; // esi
  CChoreoScene *Scene; // eax
  unsigned int NumChannels; // eax
  const char *v9; // edi
  CChoreoScene *v10; // eax
  CExpressionSample *v11; // eax
  unsigned int v12; // eax
  int v13; // esi
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // dx
  int v17; // ecx
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  unsigned __int16 v19; // di
  int v20; // esi
  int v21; // edx
  int key; // esi
  unsigned __int16 k; // ax
  CUtlMap<int,int,unsigned short> counts; // [esp+4h] [ebp-4Ch] BYREF
  CUtlVector<SceneRampTool *,CUtlMemory<SceneRampTool *,int> > workList; // [esp+20h] [ebp-30h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+34h] [ebp-1Ch] BYREF
  CUtlMap<int,int,unsigned short>::Node_t insert; // [esp+3Ch] [ebp-14h] BYREF
  int j; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  unsigned __int16 parent[2]; // [esp+4Ch] [ebp-4h] BYREF

  result = CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect);
  if ( result != 0 )
  {
    v4 = nullptr;
    m_pOuter = this->m_pOuter;
    counts.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
    memset(&counts.m_Tree.m_Elements, 0, sizeof(counts.m_Tree.m_Elements));
    *(_DWORD *)&counts.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&counts.m_Tree.m_FirstFree = -1;
    counts.m_Tree.m_pElements = nullptr;
    memset(&workList, 0, sizeof(workList));
    CUtlMemory<IFacePoserToolWindow *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList,
      num: 1);
    v6 = workList.m_Size + 1;
    if ( workList.m_Size > 0 )
      _V_memmove(dest: workList.m_Memory.m_pMemory + 1, src: workList.m_Memory.m_pMemory, count: 4 * workList.m_Size);
    if ( workList.m_Memory.m_pMemory != nullptr )
      *workList.m_Memory.m_pMemory = m_pOuter;
    if ( v6 > 0 )
    {
      for ( j = v6; j != 0; --j )
      {
        if ( g_pChoreoView != nullptr )
        {
          Scene = CChoreoView::GetScene(this: g_pChoreoView);
          if ( Scene != nullptr )
          {
            NumChannels = CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)&Scene->m_SceneRamp);
            if ( NumChannels != 0 )
            {
              v9 = (const char *)(NumChannels - 1);
              i = NumChannels - 1;
              if ( (int)(NumChannels - 1) >= 0 )
              {
                do
                {
                  if ( g_pChoreoView != nullptr && (v10 = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
                    v11 = CCurveData::Get(this: &v10->m_SceneRamp, index: (int)v9);
                  else
                    v11 = nullptr;
                  v12 = *((unsigned __int16 *)v11 + 4);
                  if ( (v12 & 1) != 0 )
                  {
                    v13 = v12 >> 1;
                    search.key = v12 >> 1;
                    v14 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                            this: &counts.m_Tree,
                            &search);
                    if ( v14 == 0xFFFF )
                    {
                      *(_DWORD *)parent = 0xFFFF;
                      insert.key = v13;
                      insert.elem = 0;
                      HIBYTE(reflect) = 0;
                      CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
                        this: &counts.m_Tree,
                        &insert,
                        parent,
                        leftchild: (bool *)&reflect + 3);
                      v15 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                              this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&counts,
                              a2: v9);
                      v16 = parent[0];
                      v17 = v15;
                      m_pMemory = counts.m_Tree.m_Elements.m_pMemory;
                      v19 = v17;
                      v20 = v17;
                      counts.m_Tree.m_Elements.m_pMemory[v20].m_Right = -1;
                      m_pMemory[v20].m_Left = -1;
                      m_pMemory[v20].m_Tag = 0;
                      m_pMemory[v20].m_Parent = v16;
                      if ( v16 == 0xFFFF )
                      {
                        counts.m_Tree.m_Root = v17;
                      }
                      else
                      {
                        v21 = v16;
                        if ( HIBYTE(reflect) != 0 )
                          m_pMemory[v21].m_Left = v17;
                        else
                          m_pMemory[v21].m_Right = v17;
                      }
                      CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
                        this: &counts.m_Tree,
                        elem: v17);
                      v4 = counts.m_Tree.m_Elements.m_pMemory;
                      ++counts.m_Tree.m_NumElements;
                      if ( &counts.m_Tree.m_Elements.m_pMemory[v20] != (UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *)-8 )
                        counts.m_Tree.m_Elements.m_pMemory[v20].m_Data = insert;
                      v14 = v19;
                      v9 = (const char *)i;
                    }
                    ++v4[v14].m_Data.elem;
                  }
                  i = (int)--v9;
                }
                while ( (int)v9 >= 0 );
              }
            }
          }
        }
      }
    }
    key = 0;
    for ( k = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &counts.m_Tree);
          k != 0xFFFF;
          k = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &counts.m_Tree,
                i: k) )
    {
      if ( v4[k].m_Data.elem > key )
        key = v4[k].m_Data.key;
    }
    if ( workList.m_Memory.m_nGrowSize >= 0 && workList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &counts.m_Tree);
    if ( counts.m_Tree.m_Elements.m_nGrowSize >= 0 && counts.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: counts.m_Tree.m_Elements.m_pMemory);
    return key;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00480EA0
// Name: public: void CCurveEditorHelper<class SceneRampTool>::ChangeCurveType(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<SceneRampTool>::ChangeCurveType(
        CCurveEditorHelper<SceneRampTool> *this,
        bool forward,
        bool shiftdown,
        bool altdown)
{
  bool v5; // bl
  __int16 BestCurveTypeForSelectedSamples; // ax
  int v7; // eax
  int v8; // edx
  bool v9; // zf
  bool v10; // sf
  int sides[2]; // [esp+8h] [ebp-8h] BYREF

  v5 = !shiftdown || altdown;
  if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect: false) != 0 )
  {
    BestCurveTypeForSelectedSamples = CCurveEditorHelper<SceneRampTool>::GetBestCurveTypeForSelectedSamples(
                                        this,
                                        reflect: false);
    Interpolator_CurveInterpolatorsForType(type: BestCurveTypeForSelectedSamples, inbound: sides, outbound: &sides[1]);
    v7 = 0;
    v8 = 2 * forward - 1;
    while ( 1 )
    {
      if ( v7 != 0 )
      {
        if ( v7 != 1 )
          goto LABEL_12;
        v9 = !v5;
      }
      else
      {
        v9 = !shiftdown;
      }
      if ( !v9 )
      {
LABEL_12:
        v10 = v8 + sides[v7] < 0;
        sides[v7] += v8;
        if ( v10 )
        {
          sides[v7] = 15;
        }
        else if ( sides[v7] >= 16 )
        {
          sides[v7] = 0;
        }
      }
      if ( ++v7 >= 2 )
      {
        CCurveEditorHelper<SceneRampTool>::SetCurveTypeForSelectedSamples(
          this,
          reflect: false,
          curvetype: LOBYTE(sides[1]) | (LOBYTE(sides[0]) << 8));
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00480F60
// Name: public: bool CCurveEditorHelper<class SceneRampTool>::HelperHandleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurveEditorHelper<SceneRampTool>::HelperHandleEvent(
        CCurveEditorHelper<SceneRampTool> *this,
        mxEvent *event)
{
  int key; // ecx
  int v5; // eax
  __int16 v6; // bx
  CExpressionSample *v7; // eax
  CExpressionSample *SampleUnderMouse; // eax
  bool shiftdown; // [esp+13h] [ebp-5h]
  bool shiftdowna; // [esp+13h] [ebp-5h]
  bool handled; // [esp+17h] [ebp-1h]
  bool altdown; // [esp+20h] [ebp+8h]
  bool altdowna; // [esp+20h] [ebp+8h]
  bool altdownb; // [esp+20h] [ebp+8h]
  bool altdownc; // [esp+20h] [ebp+8h]

  handled = false;
  if ( event->event == 11 )
  {
    key = event->key;
    if ( key == 38 )
    {
      shiftdowna = GetAsyncKeyState(vKey: 16) != 0;
      altdownc = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
        CCurveEditorHelper<SceneRampTool>::ChangeCurveType(
          this,
          forward: false,
          shiftdown: shiftdowna,
          altdown: altdownc);
    }
    else if ( event->key == 40 )
    {
      shiftdown = GetAsyncKeyState(vKey: 16) != 0;
      altdownb = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
      {
        CCurveEditorHelper<SceneRampTool>::ChangeCurveType(this, forward: true, shiftdown, altdown: altdownb);
        return 0;
      }
    }
    else if ( event->key == 72 )
    {
      handled = true;
      altdowna = GetAsyncKeyState(vKey: 16) != 0;
      if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect: altdowna) > 0 )
      {
        CCurveEditorHelper<SceneRampTool>::ToggleHoldTypeForSelectedSamples(this, reflect: altdowna);
        return 1;
      }
      RampTool::SetMousePositionForEvent(this: (RampTool *)this->m_pOuter, event);
      SampleUnderMouse = SceneRampTool::GetSampleUnderMouse(
                           this: this->m_pOuter,
                           mx: event->x,
                           my: event->y,
                           tolerance: 0.0);
      if ( SampleUnderMouse != nullptr )
      {
        CCurveEditorHelper<SceneRampTool>::ToggleHoldTypeForSample(this, sample: SampleUnderMouse);
        return 1;
      }
    }
    else if ( key >= 48 && key <= 57 )
    {
      altdown = GetAsyncKeyState(vKey: 16) != 0;
      handled = true;
      v5 = Interpolator_CurveTypeForHotkey(key: event->key);
      v6 = v5;
      if ( v5 >= 0 )
      {
        if ( CCurveEditorHelper<SceneRampTool>::CountSelected(this, reflect: altdown) > 0 )
        {
          CCurveEditorHelper<SceneRampTool>::SetCurveTypeForSelectedSamples(this, reflect: altdown, curvetype: v6);
          return 1;
        }
        RampTool::SetMousePositionForEvent(this: (RampTool *)this->m_pOuter, event);
        v7 = SceneRampTool::GetSampleUnderMouse(this: this->m_pOuter, mx: event->x, my: event->y, tolerance: 0.0);
        if ( v7 != nullptr )
        {
          CCurveEditorHelper<SceneRampTool>::SetCurveTypeForSample(this, curvetype: v6, sample: v7);
          return 1;
        }
      }
    }
  }
  return handled;
}

//------------------------------------------------------------------------------
// Address: 0x00482420
// Name: public: void TimelineItem::ResetHeight(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::ResetHeight(TimelineItem *this)
{
  this->m_nCurrentHeight = 100;
}

//------------------------------------------------------------------------------
// Address: 0x00482430
// Name: public: float TimelineItem::GetTimeForMouse(int,bool)
// Source: json
//------------------------------------------------------------------------------
double __thiscall TimelineItem::GetTimeForMouse(TimelineItem *this, int mx, bool clip)
{
  float start; // [esp+4h] [ebp-8h] BYREF
  float end; // [esp+8h] [ebp-4h] BYREF

  ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: &start, ed: &end);
  if ( !clip )
    return start
         + (end - start)
         * ((double)(mx - this->m_rcBounds.left)
          / (double)(this->m_rcBounds.right - this->m_rcBounds.left));
  if ( mx < this->m_rcBounds.left )
    return start;
  if ( mx >= this->m_rcBounds.right )
    return end;
  else
    return start
         + (end - start)
         * ((double)(mx - this->m_rcBounds.left)
          / (double)(this->m_rcBounds.right - this->m_rcBounds.left));
}

//------------------------------------------------------------------------------
// Address: 0x004824B0
// Name: public: void TimelineItem::DeselectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DeselectAll(TimelineItem *this)
{
  ExpressionTool::DeselectAll(this: g_pExpressionTool);
}

//------------------------------------------------------------------------------
// Address: 0x004824C0
// Name: public: void TimelineItem::Delete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::Delete(TimelineItem *this)
{
  ExpressionTool::DeleteSelectedSamples(this: g_pExpressionTool);
}

//------------------------------------------------------------------------------
// Address: 0x004824D0
// Name: public: void TimelineItem::SetMousePositionForEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetMousePositionForEvent(TimelineItem *this, mxEvent *event)
{
  HWND Handle; // eax
  int v4; // ecx
  tagPOINT pt; // [esp+4h] [ebp-8h] BYREF

  GetCursorPos(lpPoint: &pt);
  Handle = (HWND)mxWidget::getHandle(this: this->m_pWorkspace);
  ScreenToClient(hWnd: Handle, lpPoint: &pt);
  v4 = pt.y - this->m_rcBounds.top;
  event->x = pt.x - this->m_rcBounds.left;
  event->y = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00482520
// Name: private: void TimelineItem::MouseDrag(int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::MouseDrag(TimelineItem *this, float x, int y, int modifiers, bool snap)
{
  int m_nDragging; // edx
  int v7; // ebx
  int m_nLastX; // ecx
  int v9; // edi
  double PixelsPerSecond; // st7
  int v11; // edi
  int v12; // edx
  int v13; // edx
  int width; // [esp+18h] [ebp-8h]
  int height; // [esp+1Ch] [ebp-4h]

  m_nDragging = this->m_nDragging;
  if ( m_nDragging != 0 )
  {
    width = this->m_rcBounds.right - this->m_rcBounds.left;
    height = this->m_rcBounds.bottom - this->m_rcBounds.top;
    if ( m_nDragging == 2 || m_nDragging == 1 )
    {
      v7 = LODWORD(x);
      m_nLastX = this->m_nLastX;
      LODWORD(x) -= m_nLastX;
      v9 = y - this->m_nLastY;
      if ( (modifiers & 1) == 0 )
      {
        if ( m_nDragging == 1 )
        {
          x = 0.0;
          v7 = m_nLastX;
        }
        else
        {
          v9 = 0;
          y = this->m_nLastY;
        }
      }
      x = (float)SLODWORD(x);
      PixelsPerSecond = ExpressionTool::GetPixelsPerSecond(this: g_pExpressionTool);
      x = x / PixelsPerSecond;
      ExpressionTool::MoveSelectedSamples(this: g_pExpressionTool, dfdx: x, dfdy: (float)v9 / (float)height, snap);
      if ( (float)width > 0.0 )
      {
        v11 = v7 + this->m_rcBounds.left;
        ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: (float *)&modifiers, ed: &x);
        ExpressionTool::ForceScrubPosition(
          this: g_pExpressionTool,
          a2: v11 - this->m_rcBounds.left,
          frac: (float)((float)((float)(v11 - this->m_rcBounds.left) / (float)(this->m_rcBounds.right - this->m_rcBounds.left))
                * (float)(x - *(float *)&modifiers))
        + *(float *)&modifiers);
        MatSysWindow::Frame(this: g_pMatSysWindow);
        v12 = y;
        this->m_nLastX = v7;
        this->m_nLastY = v12;
        return;
      }
    }
    else
    {
      v7 = LODWORD(x);
    }
    v13 = y;
    this->m_nLastX = v7;
    this->m_nLastY = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482690
// Name: private: void TimelineItem::DrawFocusRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawFocusRect(TimelineItem *this)
{
  int m_nStartX; // eax
  int m_nLastX; // edx
  int m_nStartY; // eax
  int m_nLastY; // edx
  int left; // eax
  int top; // edx
  mxWindow *m_pWorkspace; // ecx
  HWND Handle; // eax
  HDC DC; // esi
  tagRECT rcFocus; // [esp+0h] [ebp-18h] BYREF
  tagPOINT offset; // [esp+10h] [ebp-8h] BYREF

  m_nStartX = this->m_nStartX;
  m_nLastX = this->m_nLastX;
  rcFocus.left = m_nStartX;
  if ( m_nStartX < m_nLastX )
  {
    rcFocus.right = m_nLastX;
  }
  else
  {
    rcFocus.left = m_nLastX;
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
  left = this->m_rcBounds.left;
  top = this->m_rcBounds.top;
  m_pWorkspace = this->m_pWorkspace;
  offset.x = left;
  offset.y = top;
  Handle = (HWND)mxWidget::getHandle(this: m_pWorkspace);
  ClientToScreen(hWnd: Handle, lpPoint: &offset);
  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
  DC = GetDC(hWnd: nullptr);
  DrawFocusRect(hDC: DC, lprc: &rcFocus);
  ReleaseDC(hWnd: nullptr, hDC: DC);
}

//------------------------------------------------------------------------------
// Address: 0x00482730
// Name: public: void TimelineItem::DrawSelf(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawSelf(TimelineItem *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+4h] [ebp-58h] BYREF

  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
    this: &drawHelper,
    widget: this->m_pWorkspace,
    bounds: &this->m_rcBounds);
  this->Draw(this, a2: &drawHelper);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
}

//------------------------------------------------------------------------------
// Address: 0x00482770
// Name: public: void TimelineItem::SetCollapsed(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetCollapsed(CAudioMixerWave *this, bool active)
{
  this->m_bActive = active;
}

//------------------------------------------------------------------------------
// Address: 0x00482790
// Name: public: int TimelineItem::GetHeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TimelineItem::GetHeight(TimelineItem *this)
{
  int result; // eax

  result = 12;
  if ( !this->m_bCollapsed )
    return this->m_nCurrentHeight;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004827B0
// Name: public: class CFlexAnimationTrack __near * TimelineItem::GetSafeTrack(void)
// Source: json
//------------------------------------------------------------------------------
CChoreoEvent *__thiscall TimelineItem::GetSafeTrack(TimelineItem *this)
{
  CChoreoEvent *result; // eax
  CChoreoEvent *v2; // ebx
  int v3; // edi
  CFlexAnimationTrack *FlexAnimationTrack; // esi
  const char *FlexControllerName; // eax

  if ( g_pExpressionTool == nullptr )
    return nullptr;
  result = (CChoreoEvent *)ExpressionTool::GetSafeEvent(this: g_pExpressionTool);
  v2 = result;
  if ( result != nullptr )
  {
    v3 = 0;
    if ( CChoreoEvent::GetNumFlexAnimationTracks(this: result) <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        FlexAnimationTrack = CChoreoEvent::GetFlexAnimationTrack(this: v2, index: v3);
        if ( FlexAnimationTrack != nullptr )
        {
          FlexControllerName = CFlexAnimationTrack::GetFlexControllerName(this: FlexAnimationTrack);
          if ( _V_stricmp(s1: FlexControllerName, s2: this->m_szTrackName) == 0 )
            break;
        }
        if ( ++v3 >= CChoreoEvent::GetNumFlexAnimationTracks(this: v2) )
          return nullptr;
      }
      return (CChoreoEvent *)FlexAnimationTrack;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482830
// Name: public: void TimelineItem::SetEditType(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetEditType(TimelineItem *this, int type)
{
  CChoreoEvent *SafeTrack; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr && CFlexAnimationTrack::IsComboType(this: (CFlexAnimationTrack *)SafeTrack) )
    this->m_nEditType = type;
  else
    this->m_nEditType = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00482870
// Name: public: int TimelineItem::GetEditType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TimelineItem::GetEditType(TimelineItem *this)
{
  return this->m_nEditType;
}

//------------------------------------------------------------------------------
// Address: 0x00482880
// Name: public: void TimelineItem::PreDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::PreDataChanged(TimelineItem *this, const char *undodescription)
{
  if ( this->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: undodescription);
  }
  ++this->m_nUndoSetup;
}

//------------------------------------------------------------------------------
// Address: 0x004828C0
// Name: public: void TimelineItem::PostDataChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::PostDataChanged(TimelineItem *this, const char *redodescription)
{
  if ( this->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: redodescription);
    ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004828F0
// Name: public: void TimelineItem::SetBounds(struct tagRECT const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetBounds(TimelineItem *this, const tagRECT *rect)
{
  this->m_rcBounds = *rect;
}

//------------------------------------------------------------------------------
// Address: 0x00482920
// Name: public: void TimelineItem::GetBounds(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::GetBounds(TimelineItem *this, tagRECT *rect)
{
  *rect = this->m_rcBounds;
}

//------------------------------------------------------------------------------
// Address: 0x00482950
// Name: public: void TimelineItem::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetVisible(TimelineItem *this, bool vis)
{
  this->m_bVisible = vis;
}

//------------------------------------------------------------------------------
// Address: 0x00482960
// Name: public: bool TimelineItem::GetVisible(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TimelineItem::GetVisible(TimelineItem *this)
{
  return this->m_bVisible;
}

//------------------------------------------------------------------------------
// Address: 0x00482970
// Name: public: void TimelineItem::SnapAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SnapAll(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // ebx
  int i; // edi
  int v3; // esi
  CExpressionSample *Sample; // ebx
  CFlexAnimationTrack *track; // [esp+10h] [ebp-4h]

  SafeTrack = TimelineItem::GetSafeTrack(this);
  track = (CFlexAnimationTrack *)SafeTrack;
  if ( SafeTrack != nullptr )
  {
    for ( i = 0; i < 2; ++i )
    {
      v3 = 0;
      if ( CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: i) > 0 )
      {
        do
        {
          Sample = CFlexAnimationTrack::GetSample(this: (CFlexAnimationTrack *)SafeTrack, index: v3, type: i);
          Sample->time = FacePoser_SnapTime(t: Sample->time);
          ++v3;
          SafeTrack = (CChoreoEvent *)track;
        }
        while ( v3 < CFlexAnimationTrack::GetNumSamples(this: track, type: i) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004829E0
// Name: public: void TimelineItem::SnapSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SnapSelected(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // ebx
  int i; // edi
  int v3; // esi
  CExpressionSample *Sample; // eax
  CFlexAnimationTrack *track; // [esp+10h] [ebp-4h]

  SafeTrack = TimelineItem::GetSafeTrack(this);
  track = (CFlexAnimationTrack *)SafeTrack;
  if ( SafeTrack != nullptr )
  {
    for ( i = 0; i < 2; ++i )
    {
      v3 = 0;
      if ( CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: i) > 0 )
      {
        do
        {
          Sample = CFlexAnimationTrack::GetSample(this: (CFlexAnimationTrack *)SafeTrack, index: v3, type: i);
          if ( (*((_BYTE *)Sample + 8) & 1) != 0 )
            Sample->time = FacePoser_SnapTime(t: Sample->time);
          ++v3;
          SafeTrack = (CChoreoEvent *)track;
        }
        while ( v3 < CFlexAnimationTrack::GetNumSamples(this: track, type: i) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482A50
// Name: public: void TimelineItem::DeletePoints(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DeletePoints(TimelineItem *this, float start, float end)
{
  CChoreoEvent *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  float time; // xmm0_4

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
  {
    for ( i = 0; i < 2; ++i )
    {
      for ( j = CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: i) - 1; j >= 0; --j )
      {
        time = CFlexAnimationTrack::GetSample(this: (CFlexAnimationTrack *)SafeTrack, index: j, type: i)->time;
        if ( start <= time && time <= end )
          CFlexAnimationTrack::RemoveSample(this: (CFlexAnimationTrack *)SafeTrack, index: j, type: i);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482AB0
// Name: private: void TimelineItem::OnDoubleClicked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::OnDoubleClicked(TimelineItem *this)
{
  if ( TimelineItem::GetSafeTrack(this) != nullptr )
  {
    this->m_bCollapsed = !this->m_bCollapsed;
    ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482AE0
// Name: private: void TimelineItem::GetGrowHandleRect(struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::GetGrowHandleRect(TimelineItem *this, tagRECT *rc)
{
  int v2; // eax

  *rc = this->m_rcBounds;
  rc->top = --rc->bottom - 8;
  v2 = (rc->left + rc->right) / 2 - 33;
  rc->left = v2;
  rc->right = v2 + 66;
}

//------------------------------------------------------------------------------
// Address: 0x00482B30
// Name: private: bool TimelineItem::IsMouseOverGrowHandle(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TimelineItem::IsMouseOverGrowHandle(TimelineItem *this, int x, int y)
{
  __int64 v5; // xmm0_8
  POINT v6; // [esp-8h] [ebp-1Ch]
  tagRECT rcGrowHandle; // [esp+4h] [ebp-10h] BYREF

  if ( this->m_bCollapsed || !ExpressionTool::IsFocusItem(this: g_pExpressionTool, item: this) )
    return false;
  *(_QWORD *)&rcGrowHandle.left = *(_QWORD *)&this->m_rcBounds.left;
  v5 = *(_QWORD *)&this->m_rcBounds.right;
  rcGrowHandle.bottom = HIDWORD(v5) - 1;
  rcGrowHandle.top = HIDWORD(v5) - 9;
  rcGrowHandle.left = ((int)v5 + rcGrowHandle.left) / 2 - 33;
  rcGrowHandle.right = rcGrowHandle.left + 66;
  v6.y = y + this->m_rcBounds.top;
  v6.x = x + this->m_rcBounds.left;
  return PtInRect(lprc: &rcGrowHandle, pt: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00482BC0
// Name: private: void TimelineItem::DrawGrowRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawGrowRect(TimelineItem *this)
{
  int top; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // edx
  mxWindow *m_pWorkspace; // ecx
  HWND Handle; // eax
  HDC DC; // esi
  tagRECT rcFocus; // [esp+4h] [ebp-18h] BYREF
  tagPOINT offset; // [esp+14h] [ebp-8h] BYREF

  top = this->m_rcBounds.top;
  v3 = top + this->m_nLastY;
  v4 = -this->m_rcBounds.left;
  *(_QWORD *)&rcFocus.left = *(_QWORD *)&this->m_rcBounds.left;
  rcFocus.right = _mm_loadl_epi64((const __m128i *)&this->m_rcBounds.right).m128i_u32[0];
  rcFocus.bottom = v3;
  OffsetRect(lprc: &rcFocus, dx: v4, dy: -top);
  v5 = this->m_rcBounds.top;
  offset.x = this->m_rcBounds.left;
  m_pWorkspace = this->m_pWorkspace;
  offset.y = v5;
  Handle = (HWND)mxWidget::getHandle(this: m_pWorkspace);
  ClientToScreen(hWnd: Handle, lpPoint: &offset);
  OffsetRect(lprc: &rcFocus, dx: offset.x, dy: offset.y);
  DC = GetDC(hWnd: nullptr);
  DrawFocusRect(hDC: DC, lprc: &rcFocus);
  ReleaseDC(hWnd: nullptr, hDC: DC);
}

//------------------------------------------------------------------------------
// Address: 0x00482C70
// Name: public: int CChoreoView::HandleZoomKey<class ExpressionTool>(class ExpressionTool __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CChoreoView::HandleZoomKey<ExpressionTool>(CChoreoView *this, ExpressionTool *other, int keyCode)
{
  int result; // eax
  int v5; // edi
  int v6; // edi
  int v7; // eax
  ExpressionTool *v8; // esi
  float v9; // xmm0_4
  int v10; // ebx
  int v11; // edi
  int v12; // edi
  int v13; // edi
  float maxtime; // [esp+14h] [ebp+8h]
  float maxtimea; // [esp+14h] [ebp+8h]

  switch ( keyCode )
  {
    case '!':
      v8 = other;
      v9 = other->m_flLeftOffset - (float)mxWidget::w2(this: other);
      if ( v9 <= 0.0 )
        v9 = 0.0;
      goto LABEL_9;
    case '"':
      v8 = other;
      v10 = mxWidget::w2(this: other);
      maxtimea = ExpressionTool::GetEventEndTime(this: other);
      v11 = (int)(ExpressionTool::GetPixelsPerSecond(this: v8) * maxtimea);
      if ( v11 - mxWidget::w2(this: v8) >= 0 )
      {
        v13 = (int)(ExpressionTool::GetPixelsPerSecond(this: v8) * maxtimea);
        v12 = v13 - mxWidget::w2(this: v8);
      }
      else
      {
        v12 = 0;
      }
      v9 = (float)v10 + v8->m_flLeftOffset;
      if ( (float)v12 <= v9 )
        v9 = (float)v12;
LABEL_9:
      v8->m_flLeftOffset = v9;
      ExpressionTool::MoveTimeSliderToPos(this: v8, x: (int)v9);
      result = 1;
      break;
    case '#':
      maxtime = ExpressionTool::GetEventEndTime(this: other);
      v5 = (int)(ExpressionTool::GetPixelsPerSecond(this: other) * maxtime);
      if ( v5 - mxWidget::w2(this: other) >= 0 )
      {
        v6 = (int)(ExpressionTool::GetPixelsPerSecond(this: other) * maxtime);
        v7 = mxWidget::w2(this: other);
        ExpressionTool::MoveTimeSliderToPos(this: other, x: v6 - v7);
      }
      else
      {
        ExpressionTool::MoveTimeSliderToPos(this: other, x: 0);
      }
      result = 1;
      break;
    case '$':
      ExpressionTool::MoveTimeSliderToPos(this: other, x: 0);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482E00
// Name: public: struct CExpressionSample __near * TimelineItem::GetSampleUnderMouse(int,int,float)
// Source: json
//------------------------------------------------------------------------------
CExpressionSample *__thiscall TimelineItem::GetSampleUnderMouse(TimelineItem *this, int mx, int my, float tolerance)
{
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v6; // edi
  int v7; // ebx
  int m_nEditType; // ecx
  CExpressionSample *Sample; // edi
  int v11; // eax
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // [esp+Ch] [ebp-1Ch]
  float ed; // [esp+10h] [ebp-18h] BYREF
  float time; // [esp+14h] [ebp-14h]
  int height; // [esp+18h] [ebp-10h] BYREF
  CExpressionSample *bestsample; // [esp+1Ch] [ebp-Ch]
  CFlexAnimationTrack *track; // [esp+20h] [ebp-8h]
  float closest_dist; // [esp+24h] [ebp-4h]
  int mxa; // [esp+30h] [ebp+8h]

  SafeTrack = TimelineItem::GetSafeTrack(this);
  v6 = (CFlexAnimationTrack *)SafeTrack;
  v7 = 0;
  track = (CFlexAnimationTrack *)SafeTrack;
  if ( SafeTrack == nullptr || CChoreoEvent::GetNumLoopsRemaining(this: SafeTrack) == 0 )
    return nullptr;
  m_nEditType = this->m_nEditType;
  height = this->m_rcBounds.bottom - this->m_rcBounds.top;
  mxa = this->m_rcBounds.left + mx;
  closest_dist = 9999999.0;
  bestsample = nullptr;
  if ( CFlexAnimationTrack::GetNumSamples(this: v6, type: m_nEditType) > 0 )
  {
    v14 = (float)height;
    while ( 1 )
    {
      Sample = CFlexAnimationTrack::GetSample(this: v6, index: v7, type: this->m_nEditType);
      time = Sample->time;
      ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: (float *)&height, &ed);
      v11 = this->m_rcBounds.left
          + (int)(float)((float)((float)(time - *(float *)&height) / (float)(ed - *(float *)&height))
                       * (float)(this->m_rcBounds.right - this->m_rcBounds.left))
          - mxa;
      v12 = (int)(float)((float)(1.0 - Sample->value) * v14) - my;
      v13 = fsqrt((float)(v11 * v11 + v12 * v12));
      if ( closest_dist > v13 )
      {
        bestsample = Sample;
        closest_dist = v13;
      }
      if ( ++v7 >= CFlexAnimationTrack::GetNumSamples(this: track, type: this->m_nEditType) )
        break;
      v6 = track;
    }
  }
  if ( tolerance == 0.0 || closest_dist <= tolerance )
    return bestsample;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00482F70
// Name: public: void TimelineItem::SelectAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SelectAll(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // ebx
  int i; // edi
  int j; // esi
  CExpressionSample *Sample; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
  {
    for ( i = 0; i < 2; ++i )
    {
      for ( j = 0; j < CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: i); ++j )
      {
        Sample = CFlexAnimationTrack::GetSample(this: (CFlexAnimationTrack *)SafeTrack, index: j, type: i);
        *((_WORD *)Sample + 4) |= 1u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482FC0
// Name: private: void TimelineItem::DrawAutoHighlight(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawAutoHighlight(TimelineItem *this, mxEvent *event)
{
  CFlexAnimationTrack *SafeTrack; // edi
  int m_nEditType; // esi
  CExpressionSample *BoundedSample; // edi
  float v6; // xmm0_4
  bool v7; // cl
  HPEN__ *v8; // esi
  float v9; // xmm0_4
  Color *p_clrSelected; // ecx
  int v11; // esi
  CChoreoWidgetDrawHelper drawHelper; // [esp+10h] [ebp-A0h] BYREF
  tagRECT rcClient; // [esp+68h] [ebp-48h]
  float value; // [esp+78h] [ebp-38h]
  float ed; // [esp+7Ch] [ebp-34h] BYREF
  Color clr; // [esp+80h] [ebp-30h] BYREF
  int height; // [esp+84h] [ebp-2Ch]
  Color clrSelected; // [esp+88h] [ebp-28h] BYREF
  float st; // [esp+8Ch] [ebp-24h] BYREF
  CExpressionSample *hover; // [esp+90h] [ebp-20h]
  float time; // [esp+94h] [ebp-1Ch]
  CFlexAnimationTrack *track; // [esp+98h] [ebp-18h]
  int type; // [esp+9Ch] [ebp-14h]
  bool dummy; // [esp+A3h] [ebp-Dh] BYREF
  Color clrHighlighted; // [esp+A4h] [ebp-Ch] BYREF
  Color bgColor; // [esp+A8h] [ebp-8h] BYREF
  int sample; // [esp+ACh] [ebp-4h]

  if ( !this->m_bCollapsed )
  {
    SafeTrack = (CFlexAnimationTrack *)TimelineItem::GetSafeTrack(this);
    track = SafeTrack;
    if ( SafeTrack != nullptr )
    {
      hover = TimelineItem::GetSampleUnderMouse(this, mx: event->x, my: event->y, tolerance: 0.0);
      CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(
        this: &drawHelper,
        widget: this->m_pWorkspace,
        bounds: &this->m_rcBounds,
        noPageFlip: true);
      *(_QWORD *)&rcClient.left = *(_QWORD *)&this->m_rcBounds.left;
      m_nEditType = this->m_nEditType;
      *(_QWORD *)&rcClient.right = *(_QWORD *)&this->m_rcBounds.right;
      height = rcClient.bottom - rcClient.top;
      type = m_nEditType;
      clrHighlighted = (Color)51200;
      clr = (Color)16711680;
      clrSelected = (Color)1331440;
      bgColor = (Color)13166310;
      sample = 0;
      if ( CFlexAnimationTrack::GetNumSamples(this: SafeTrack, type: m_nEditType) > 0 )
      {
        while ( 1 )
        {
          BoundedSample = CFlexAnimationTrack::GetBoundedSample(
                            this: SafeTrack,
                            number: sample,
                            bClamped: &dummy,
                            type: m_nEditType);
          value = BoundedSample->value;
          time = BoundedSample->time;
          ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, &st, &ed);
          v6 = (float)(time - st) / (float)(ed - st);
          v7 = v6 < 0.0 || v6 > 1.0;
          v8 = (HPEN__ *)(this->m_rcBounds.left
                        + (int)(float)((float)(this->m_rcBounds.right - this->m_rcBounds.left) * v6));
          if ( !v7 )
          {
            v9 = (float)rcClient.bottom - (float)((float)height * value);
            if ( hover == BoundedSample )
            {
              CChoreoWidgetDrawHelper::DrawCircle(
                this: &drawHelper,
                clr: &bgColor,
                x: v8,
                y: (HBRUSH__ *)(int)v9,
                radius: (HBRUSH__ *)6,
                filled: true);
              CChoreoWidgetDrawHelper::DrawCircle(
                this: &drawHelper,
                clr: &clrHighlighted,
                x: v8,
                y: (HBRUSH__ *)(int)v9,
                radius: (HBRUSH__ *)6,
                filled: false);
            }
            else
            {
              p_clrSelected = &clrSelected;
              if ( (*((_WORD *)BoundedSample + 4) & 1) == 0 )
                p_clrSelected = &clr;
              CChoreoWidgetDrawHelper::DrawCircle(
                this: &drawHelper,
                clr: p_clrSelected,
                x: v8,
                y: (HBRUSH__ *)(int)v9,
                radius: (HBRUSH__ *)6,
                filled: true);
            }
          }
          v11 = ++sample;
          if ( v11 >= CFlexAnimationTrack::GetNumSamples(this: track, type) )
            break;
          m_nEditType = type;
          SafeTrack = track;
        }
      }
      CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004831C0
// Name: private: void TimelineItem::DrawRelativeTags(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawRelativeTags(TimelineItem *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoEvent *SafeTrack; // eax
  CChoreoEvent *NumLoopsRemaining; // edi
  CChoreoScene *v5; // eax
  CChoreoScene *v6; // esi
  __m128i v7; // xmm0
  int v8; // ebx
  CChoreoActor *Actor; // eax
  CChoreoActor *v10; // esi
  CChoreoChannel *Channel; // eax
  CChoreoChannel *v12; // ebx
  CChoreoEvent *v13; // eax
  CChoreoEvent *v14; // esi
  int v15; // edi
  CEventRelativeTag *RelativeTag; // eax
  char v17; // bl
  double v18; // st7
  float v19; // xmm0_4
  int v20; // eax
  int v21; // esi
  int v22; // ebx
  int m; // esi
  CFlexTimingTag *TimingTag; // eax
  char v25; // bl
  float v26; // xmm0_4
  int v27; // eax
  __int64 rcClient; // [esp+4h] [ebp-40h]
  CChoreoActor *a; // [esp+14h] [ebp-30h]
  float aa; // [esp+14h] [ebp-30h]
  float ab; // [esp+14h] [ebp-30h]
  CChoreoChannel *c; // [esp+18h] [ebp-2Ch] BYREF
  float ed; // [esp+1Ch] [ebp-28h] BYREF
  float st; // [esp+20h] [ebp-24h] BYREF
  float StartTime; // [esp+24h] [ebp-20h]
  TimelineItem *v36; // [esp+28h] [ebp-1Ch]
  CChoreoScene *scene; // [esp+2Ch] [ebp-18h]
  int i; // [esp+30h] [ebp-14h]
  CChoreoEvent *event; // [esp+34h] [ebp-10h]
  int j; // [esp+38h] [ebp-Ch]
  int k; // [esp+3Ch] [ebp-8h]
  Color clr; // [esp+40h] [ebp-4h] BYREF

  v36 = this;
  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
  {
    NumLoopsRemaining = (CChoreoEvent *)CChoreoEvent::GetNumLoopsRemaining(this: SafeTrack);
    event = NumLoopsRemaining;
    if ( NumLoopsRemaining != nullptr
      && ((double (__thiscall *)(CChoreoEvent *))NumLoopsRemaining->GetDuration)(a1: NumLoopsRemaining) > 0.0 )
    {
      v5 = CChoreoView::GetScene(this: g_pChoreoView);
      v6 = v5;
      scene = v5;
      if ( v5 != nullptr )
      {
        rcClient = *(_QWORD *)&this->m_rcBounds.left;
        v7 = _mm_loadl_epi64((const __m128i *)&this->m_rcBounds.right);
        v8 = 0;
        i = 0;
        if ( CChoreoScene::GetNumActors(this: v5) > 0 )
        {
          while ( 1 )
          {
            Actor = CChoreoScene::GetActor(this: v6, actor: v8);
            v10 = Actor;
            a = Actor;
            if ( Actor != nullptr )
            {
              j = 0;
              if ( CChoreoActor::GetNumChannels(this: Actor) > 0 )
              {
                do
                {
                  Channel = CChoreoActor::GetChannel(this: v10, channel: j);
                  v12 = Channel;
                  c = Channel;
                  if ( Channel != nullptr )
                  {
                    k = 0;
                    if ( CChoreoChannel::GetNumEvents(this: Channel) > 0 )
                    {
                      do
                      {
                        v13 = CChoreoChannel::GetEvent(this: v12, event: k);
                        v14 = v13;
                        if ( v13 != nullptr )
                        {
                          v15 = 0;
                          if ( CChoreoEvent::GetNumRelativeTags(this: v13) > 0 )
                          {
                            do
                            {
                              RelativeTag = CChoreoEvent::GetRelativeTag(this: v14, tagnum: v15);
                              if ( RelativeTag != nullptr )
                              {
                                v17 = 0;
                                StartTime = CEventRelativeTag::GetStartTime(this: RelativeTag);
                                v18 = CChoreoEvent::GetStartTime(this: event);
                                StartTime = StartTime - v18;
                                ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, &st, &ed);
                                v19 = (float)(StartTime - st) / (float)(ed - st);
                                if ( v19 < 0.0 || v19 > 1.0 )
                                  v17 = 1;
                                v20 = v36->m_rcBounds.left
                                    + (int)(float)((float)(v36->m_rcBounds.right - v36->m_rcBounds.left) * v19);
                                if ( v17 == 0 )
                                {
                                  clr = (Color)14464180;
                                  CChoreoWidgetDrawHelper::DrawColoredLine(
                                    this: drawHelper,
                                    (HPEN__ *)&clr,
                                    style: 0,
                                    width: 1,
                                    x1: v20,
                                    y1: SHIDWORD(rcClient),
                                    x2: v20,
                                    y2: v7.m128i_i32[1]);
                                }
                              }
                              ++v15;
                            }
                            while ( v15 < CChoreoEvent::GetNumRelativeTags(this: v14) );
                            v12 = c;
                          }
                        }
                        v21 = ++k;
                      }
                      while ( v21 < CChoreoChannel::GetNumEvents(this: v12) );
                      NumLoopsRemaining = event;
                      v10 = a;
                    }
                  }
                  v22 = ++j;
                }
                while ( v22 < CChoreoActor::GetNumChannels(this: v10) );
                v8 = i;
              }
            }
            i = ++v8;
            if ( v8 >= CChoreoScene::GetNumActors(this: scene) )
              break;
            v6 = scene;
          }
        }
        for ( m = 0; m < CChoreoEvent::GetNumTimingTags(this: NumLoopsRemaining); ++m )
        {
          TimingTag = CChoreoEvent::GetTimingTag(this: NumLoopsRemaining, tagnum: m);
          if ( TimingTag != nullptr )
          {
            v25 = 0;
            aa = CEventRelativeTag::GetStartTime(this: TimingTag);
            ab = aa - CChoreoEvent::GetStartTime(this: NumLoopsRemaining);
            ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: (float *)&c, &ed);
            v26 = (float)(ab - *(float *)&c) / (float)(ed - *(float *)&c);
            if ( v26 < 0.0 || v26 > 1.0 )
              v25 = 1;
            v27 = v36->m_rcBounds.left + (int)(float)((float)(v36->m_rcBounds.right - v36->m_rcBounds.left) * v26);
            if ( v25 == 0 )
            {
              clr = (Color)11842780;
              CChoreoWidgetDrawHelper::DrawColoredLine(
                this: drawHelper,
                (HPEN__ *)&clr,
                style: 0,
                width: 1,
                x1: v27,
                y1: SHIDWORD(rcClient),
                x2: v27,
                y2: v7.m128i_i32[1]);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004834C0
// Name: public: void TimelineItem::Copy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::Copy(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // eax

  if ( g_pExpressionTool != nullptr )
  {
    SafeTrack = TimelineItem::GetSafeTrack(this);
    if ( SafeTrack != nullptr )
      ExpressionTool::Copy(this: g_pExpressionTool, source: (CFlexAnimationTrack *)SafeTrack);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004834E0
// Name: public: void TimelineItem::Paste(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::Paste(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // eax

  if ( g_pExpressionTool != nullptr && ExpressionTool::HasCopyData(this: g_pExpressionTool) )
  {
    SafeTrack = TimelineItem::GetSafeTrack(this);
    if ( SafeTrack != nullptr )
      ExpressionTool::Paste(this: g_pExpressionTool, destination: (CFlexAnimationTrack *)SafeTrack);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483510
// Name: public: void TimelineItem::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetActive(TimelineItem *this, bool state)
{
  CChoreoEvent *SafeTrack; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
    CFlexAnimationTrack::SetTrackActive(this: (CFlexAnimationTrack *)SafeTrack, active: state);
}

//------------------------------------------------------------------------------
// Address: 0x00483530
// Name: public: bool TimelineItem::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TimelineItem::IsActive(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  return SafeTrack != nullptr && CFlexAnimationTrack::IsTrackActive(this: (CFlexAnimationTrack *)SafeTrack);
}

//------------------------------------------------------------------------------
// Address: 0x00483550
// Name: public: bool TimelineItem::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TimelineItem::IsValid(TimelineItem *this)
{
  CChoreoEvent *SafeTrack; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  return SafeTrack != nullptr && CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: 0) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x00483570
// Name: private: void TimelineItem::SelectPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SelectPoints(TimelineItem *this)
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
  int v11; // ebx
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v13; // edi
  double (__thiscall ***NumLoopsRemaining)(_DWORD); // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  double PixelsPerSecond; // st7
  int v18; // ebx
  CExpressionSample *Sample; // eax
  float v20; // xmm0_4
  int m_nEditType; // [esp+0h] [ebp-3Ch]
  tagRECT rcSelection; // [esp+10h] [ebp-2Ch] BYREF
  float epsx; // [esp+20h] [ebp-1Ch]
  float epsy; // [esp+24h] [ebp-18h]
  float fleft; // [esp+28h] [ebp-14h]
  float duration; // [esp+2Ch] [ebp-10h]
  float fright; // [esp+30h] [ebp-Ch]
  float v28; // [esp+34h] [ebp-8h]
  float tolerance; // [esp+38h] [ebp-4h]

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
    SampleUnderMouse = TimelineItem::GetSampleUnderMouse(
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
  v11 = this->m_rcBounds.bottom - this->m_rcBounds.top;
  LODWORD(fleft) = this->m_rcBounds.right - this->m_rcBounds.left;
  SafeTrack = TimelineItem::GetSafeTrack(this);
  v13 = (CFlexAnimationTrack *)SafeTrack;
  if ( SafeTrack != nullptr && fleft != 0.0 && v11 != 0 )
  {
    NumLoopsRemaining = (double (__thiscall ***)(_DWORD))CChoreoEvent::GetNumLoopsRemaining(this: SafeTrack);
    if ( NumLoopsRemaining != nullptr )
    {
      duration = (**NumLoopsRemaining)(a1: NumLoopsRemaining);
      fleft = TimelineItem::GetTimeForMouse(this, mx: rcSelection.left + this->m_rcBounds.left, clip: false);
      fright = TimelineItem::GetTimeForMouse(this, mx: rcSelection.right + this->m_rcBounds.left, clip: false);
      epsy = (float)v11;
      v15 = (float)rcSelection.top / (float)v11;
      v16 = (float)rcSelection.bottom / (float)v11;
      if ( fleft >= 0.0 )
      {
        if ( fleft <= duration )
          v28 = fleft;
        else
          v28 = duration;
      }
      else
      {
        v28 = 0.0;
      }
      if ( fright >= 0.0 )
      {
        if ( fright > duration )
          fright = duration;
      }
      else
      {
        fright = 0.0;
      }
      if ( v15 >= 0.0 )
      {
        if ( v15 <= 1.0 )
          duration = (float)rcSelection.top / (float)v11;
        else
          duration = 1.0;
      }
      else
      {
        duration = 0.0;
      }
      if ( v16 >= 0.0 )
      {
        if ( v16 <= 1.0 )
          fleft = (float)rcSelection.bottom / (float)v11;
        else
          fleft = 1.0;
      }
      else
      {
        fleft = 0.0;
      }
      PixelsPerSecond = ExpressionTool::GetPixelsPerSecond(this: g_pExpressionTool);
      m_nEditType = this->m_nEditType;
      epsy = (float)(1.0 / epsy) * tolerance;
      v18 = 0;
      epsx = 1.0 / PixelsPerSecond * tolerance;
      if ( CFlexAnimationTrack::GetNumSamples(this: v13, type: m_nEditType) > 0 )
      {
        do
        {
          Sample = CFlexAnimationTrack::GetSample(this: v13, index: v18, type: this->m_nEditType);
          if ( v28 <= (float)(Sample->time + epsx) && (float)(Sample->time - epsx) <= fright )
          {
            v20 = 1.0 - Sample->value;
            if ( duration <= (float)(v20 + epsy) && (float)(v20 - epsy) <= fleft )
              *((_WORD *)Sample + 4) |= 1u;
          }
          ++v18;
        }
        while ( v18 < CFlexAnimationTrack::GetNumSamples(this: v13, type: this->m_nEditType) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483840
// Name: public: void TimelineItem::DrawEventEnd(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawEventEnd(TimelineItem *this, CChoreoWidgetDrawHelper *drawHelper)
{
  CChoreoEvent *SafeTrack; // eax
  double (__thiscall ***NumLoopsRemaining)(_DWORD); // eax
  double v5; // st7
  int v6; // eax
  int top; // [esp-Ch] [ebp-1Ch]
  int bottom; // [esp-4h] [ebp-14h]
  float ed; // [esp+4h] [ebp-Ch] BYREF
  float st; // [esp+8h] [ebp-8h] BYREF
  HPEN__ duration; // [esp+Ch] [ebp-4h] BYREF

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
  {
    NumLoopsRemaining = (double (__thiscall ***)(_DWORD))CChoreoEvent::GetNumLoopsRemaining(this: SafeTrack);
    if ( NumLoopsRemaining != nullptr )
    {
      v5 = (**NumLoopsRemaining)(a1: NumLoopsRemaining);
      *(float *)&duration.unused = v5;
      if ( v5 != 0.0 )
      {
        ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, &st, &ed);
        v6 = this->m_rcBounds.left
           + (int)(float)((float)((float)(*(float *)&duration.unused - st) / (float)(ed - st))
                        * (float)(this->m_rcBounds.right - this->m_rcBounds.left));
        if ( v6 <= this->m_rcBounds.right )
        {
          bottom = this->m_rcBounds.bottom;
          top = this->m_rcBounds.top;
          *(float *)&duration.unused = 2.3418052e-38;
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: drawHelper,
            clr: &duration,
            style: 0,
            width: 1,
            x1: v6,
            y1: top,
            x2: v6,
            y2: bottom);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483900
// Name: private: void TimelineItem::DrawGrowHandle(class CChoreoWidgetDrawHelper __near &,struct tagRECT __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::DrawGrowHandle(TimelineItem *this, CChoreoWidgetDrawHelper *helper, HBRUSH handleRect)
{
  HBRUSH__ *v3; // esi
  HDC NumChannels; // edi
  HRGN PolygonRgn; // ebx
  int v6; // ecx
  float v7; // xmm0_4
  tagPOINT region[4]; // [esp+8h] [ebp-38h] BYREF
  tagRECT useRect; // [esp+28h] [ebp-18h] BYREF
  int oldPF; // [esp+38h] [ebp-8h]
  HBRUSH__ *brBorder; // [esp+3Ch] [ebp-4h]

  v3 = handleRect;
  useRect = *(tagRECT *)handleRect;
  CChoreoWidgetDrawHelper::OffsetSubRect(this: helper, rc: &useRect);
  region[0].x = useRect.left + 8;
  region[0].y = useRect.top;
  region[1].y = useRect.top;
  region[3].y = useRect.bottom;
  region[1].x = useRect.right - 8;
  region[2] = *(tagPOINT *)&useRect.right;
  region[3].x = useRect.left;
  NumChannels = (HDC)CAudioSourceMemWave::GetNumChannels(this: (IterateRIFF *)helper);
  PolygonRgn = CreatePolygonRgn(pptl: region, cPoint: 4, iMode: 1);
  oldPF = SetPolyFillMode(hdc: NumChannels, mode: 1);
  handleRect = CreateSolidBrush(color: 0x969696u);
  brBorder = CreateSolidBrush(color: 0xC8C8C8u);
  FillRgn(hdc: NumChannels, hrgn: PolygonRgn, hbr: handleRect);
  FrameRgn(hdc: NumChannels, hrgn: PolygonRgn, hbr: brBorder, w: 1, h: 1);
  SetPolyFillMode(hdc: NumChannels, mode: oldPF);
  DeleteObject(ho: PolygonRgn);
  DeleteObject(ho: handleRect);
  DeleteObject(ho: brBorder);
  v6 = *((_DWORD *)v3 + 2);
  v7 = (float)(*((_DWORD *)v3 + 1) + *((_DWORD *)v3 + 3)) * 0.5;
  handleRect = (HBRUSH)4144959;
  CChoreoWidgetDrawHelper::DrawColoredLine(
    this: helper,
    clr: (HPEN__ *)&handleRect,
    style: 0,
    width: 1,
    x1: *(_DWORD *)v3 + 12,
    y1: (int)v7,
    x2: v6 - 12,
    y2: (int)v7);
}

//------------------------------------------------------------------------------
// Address: 0x00483A20
// Name: public: void CCurveEditorHelper<class TimelineItem>::SetCurveTypeForSample(int,struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<TimelineItem>::SetCurveTypeForSample(
        CCurveEditorHelper<TimelineItem> *this,
        __int16 curvetype,
        CExpressionSample *sample)
{
  TimelineItem *m_pOuter; // esi

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
  }
  ++m_pOuter->m_nUndoSetup;
  *((_WORD *)sample + 4) = (2 * curvetype) | *((_WORD *)sample + 4) & 1;
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
    ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483AA0
// Name: public: void CCurveEditorHelper<class TimelineItem>::ToggleHoldTypeForSample(struct CExpressionSample __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<TimelineItem>::ToggleHoldTypeForSample(
        CCurveEditorHelper<TimelineItem> *this,
        CExpressionSample *sample)
{
  TimelineItem *m_pOuter; // esi
  int v4; // ecx
  __int16 v5; // dx
  int l; // [esp+8h] [ebp-8h] BYREF
  int r; // [esp+Ch] [ebp-4h] BYREF

  m_pOuter = this->m_pOuter;
  if ( this->m_pOuter->m_nUndoSetup == 0 )
  {
    CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
    CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
  }
  ++m_pOuter->m_nUndoSetup;
  Interpolator_CurveInterpolatorsForType(type: *((_WORD *)sample + 4) >> 1, inbound: &l, outbound: &r);
  v4 = 15;
  if ( r == 15 )
    v4 = l;
  v5 = *((_WORD *)sample + 4);
  r = v4;
  *((_WORD *)sample + 4) = v5 & 1 | (2 * (((_WORD)l << 8) | (unsigned __int8)v4));
  if ( this->m_pOuter->m_nUndoSetup-- == 1 )
  {
    CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
    ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483B50
// Name: private: void TimelineItem::AddSample(struct CExpressionSample const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::AddSample(TimelineItem *this, const CExpressionSample *sample)
{
  CChoreoEvent *SafeTrack; // edi
  int m_nEditType; // eax
  CChoreoEvent *v5; // eax

  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
  {
    if ( this->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Add sample point");
    }
    m_nEditType = this->m_nEditType;
    ++this->m_nUndoSetup;
    CFlexAnimationTrack::AddSample(
      this: (CFlexAnimationTrack *)SafeTrack,
      time: sample->time,
      value: sample->value,
      type: m_nEditType);
    CFlexAnimationTrack::Resort(this: (CFlexAnimationTrack *)SafeTrack, type: this->m_nEditType);
    v5 = TimelineItem::GetSafeTrack(this);
    if ( v5 != nullptr )
      CFlexAnimationTrack::SetTrackActive(this: (CFlexAnimationTrack *)v5, active: true);
    if ( this->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Add sample point");
      ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483C10
// Name: public: void TimelineItem::SetExpressionInfo(class CFlexAnimationTrack __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::SetExpressionInfo(TimelineItem *this, CFlexAnimationTrack *track, int flexnum)
{
  char *FlexControllerName; // eax
  char *v5; // edx
  char v6; // cl
  CChoreoEvent *SafeTrack; // eax
  bool tracka; // [esp+14h] [ebp+8h]

  this->m_szTrackName[0] = 0;
  if ( track != nullptr )
  {
    FlexControllerName = (char *)CFlexAnimationTrack::GetFlexControllerName(this: track);
    v5 = (char *)(this->m_szTrackName - FlexControllerName);
    do
    {
      v6 = *FlexControllerName;
      FlexControllerName[(_DWORD)v5] = *FlexControllerName;
      ++FlexControllerName;
    }
    while ( v6 != 0 );
    tracka = CFlexAnimationTrack::IsTrackActive(this: track);
    SafeTrack = TimelineItem::GetSafeTrack(this);
    if ( SafeTrack != nullptr )
      CFlexAnimationTrack::SetTrackActive(this: (CFlexAnimationTrack *)SafeTrack, active: tracka);
    this->m_nFlexNum = flexnum;
  }
  else
  {
    this->m_nFlexNum = flexnum;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483C90
// Name: public: TimelineItem::TimelineItem(class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
TimelineItem *__thiscall TimelineItem::TimelineItem(TimelineItem *this, mxWindow *workspace)
{
  CCurveEditorHelper<TimelineItem> *v3; // eax
  CChoreoEvent *SafeTrack; // eax

  this->__vftable = (TimelineItem_vtbl *)&TimelineItem::`vftable';
  v3 = (CCurveEditorHelper<TimelineItem> *)operator new(nSize: 4u);
  if ( v3 != nullptr )
    v3->m_pOuter = this;
  else
    v3 = nullptr;
  this->m_pHelper = v3;
  this->m_pWorkspace = workspace;
  this->m_nDragging = 0;
  this->m_nLastX = 0;
  this->m_nLastY = 0;
  this->m_nStartX = 0;
  this->m_nStartY = 0;
  this->m_nFlexNum = 0;
  this->m_nNumSelected = 0;
  this->m_nEditType = 0;
  *(_WORD *)&this->m_bCollapsed = 0;
  SafeTrack = TimelineItem::GetSafeTrack(this);
  if ( SafeTrack != nullptr )
    CFlexAnimationTrack::SetTrackActive(this: (CFlexAnimationTrack *)SafeTrack, active: false);
  this->m_nUndoSetup = 0;
  this->m_rcBounds.top = 0;
  this->m_rcBounds.bottom = 0;
  this->m_rcBounds.left = 0;
  this->m_rcBounds.right = 0;
  this->m_bVisible = false;
  this->m_flLastClickTime = -1.0;
  this->m_nCurrentHeight = 100;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483D40
// Name: public: void TimelineItem::GetWorkList(bool,class CUtlVector<class TimelineItem __near *,class CUtlMemory<class TimelineItem __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::GetWorkList(
        TimelineItem *this,
        bool reflect,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list)
{
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  TimelineItem **v6; // ecx
  int v7; // eax
  TimelineItem **v8; // eax

  if ( reflect )
  {
    ExpressionTool::GetTimelineItems(this: g_pExpressionTool, list);
  }
  else
  {
    m_nAllocationCount = list->m_nAllocationCount;
    m_pMemory = (int)list[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IFacePoserToolWindow *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
    ++list[1].m_pMemory;
    v6 = (TimelineItem **)list->m_pMemory;
    v7 = (int)list[1].m_pMemory - m_pMemory - 1;
    list[1].m_nAllocationCount = (int)list->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (TimelineItem **)&list->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483DC0
// Name: public: int CCurveEditorHelper<class TimelineItem>::CountSelected(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<TimelineItem>::CountSelected(CCurveEditorHelper<TimelineItem> *this, bool reflect)
{
  TimelineItem *m_pOuter; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // eax
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v7; // esi
  int NumSamples; // ebx
  int v9; // ebx
  CChoreoEvent *v10; // eax
  CFlexAnimationTrack *v11; // esi
  int v12; // eax
  CExpressionSample *Sample; // eax
  TimelineItem **m_pMemory; // eax
  CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > workList; // [esp+8h] [ebp-18h] BYREF
  int numSelected; // [esp+1Ch] [ebp-4h]
  int w; // [esp+28h] [ebp+8h]

  m_pOuter = this->m_pOuter;
  v3 = 0;
  v4 = 0;
  numSelected = 0;
  memset(&workList, 0, sizeof(workList));
  TimelineItem::GetWorkList(this: m_pOuter, reflect, list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList);
  v5 = 0;
  w = 0;
  if ( workList.m_Size > 0 )
  {
    do
    {
      SafeTrack = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[v5]);
      v7 = (CFlexAnimationTrack *)SafeTrack;
      if ( SafeTrack != nullptr )
      {
        NumSamples = CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: 1);
        v9 = CFlexAnimationTrack::GetNumSamples(this: v7, type: 0) + NumSamples;
        if ( v9 != 0 )
        {
          if ( v9 > 0 )
          {
            do
            {
              v10 = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
              v11 = (CFlexAnimationTrack *)v10;
              if ( v10 != nullptr )
              {
                if ( v3 < CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)v10, type: 0) )
                {
                  Sample = CFlexAnimationTrack::GetSample(this: v11, index: v3, type: 0);
                }
                else
                {
                  v12 = CFlexAnimationTrack::GetNumSamples(this: v11, type: 0);
                  Sample = CFlexAnimationTrack::GetSample(this: v11, index: v3 - v12, type: 1);
                }
                if ( Sample != nullptr && (*((_BYTE *)Sample + 8) & 1) != 0 )
                  ++numSelected;
              }
              ++v3;
            }
            while ( v3 < v9 );
          }
          v3 = 0;
        }
      }
      v5 = w + 1;
      w = v5;
    }
    while ( v5 < workList.m_Size );
    v4 = numSelected;
  }
  m_pMemory = workList.m_Memory.m_pMemory;
  workList.m_Size = 0;
  if ( workList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( workList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      workList.m_Memory.m_pMemory = nullptr;
    }
    workList.m_Memory.m_nAllocationCount = 0;
  }
  workList.m_pElements = m_pMemory;
  if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00483EE0
// Name: public: void CCurveEditorHelper<class TimelineItem>::SetCurveTypeForSelectedSamples(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<TimelineItem>::SetCurveTypeForSelectedSamples(
        CCurveEditorHelper<TimelineItem> *this,
        bool reflect,
        __int16 curvetype)
{
  CCurveEditorHelper<TimelineItem> *v3; // ebx
  TimelineItem *m_pOuter; // esi
  TimelineItem *v5; // ecx
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v7; // esi
  int v8; // ebx
  int NumSamples; // ebx
  int i; // edi
  CExpressionSample *Sample; // eax
  CFlexAnimationTrack *v12; // esi
  int v13; // eax
  TimelineItem **m_pMemory; // eax
  CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > workList; // [esp+8h] [ebp-18h] BYREF
  CCurveEditorHelper<TimelineItem> *v17; // [esp+1Ch] [ebp-4h]
  int w; // [esp+28h] [ebp+8h]

  v3 = this;
  v17 = this;
  if ( CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = v3->m_pOuter;
    if ( v3->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set curve type");
    }
    ++m_pOuter->m_nUndoSetup;
    v5 = v3->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    TimelineItem::GetWorkList(this: v5, reflect, list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList);
    w = 0;
    if ( workList.m_Size > 0 )
    {
      do
      {
        SafeTrack = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
        v7 = (CFlexAnimationTrack *)SafeTrack;
        if ( SafeTrack != nullptr )
        {
          NumSamples = CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: 1);
          v8 = CFlexAnimationTrack::GetNumSamples(this: v7, type: 0) + NumSamples;
        }
        else
        {
          v8 = 0;
        }
        for ( i = 0; i < v8; ++i )
        {
          Sample = (CExpressionSample *)TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
          v12 = (CFlexAnimationTrack *)Sample;
          if ( Sample != nullptr )
          {
            if ( i < CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)Sample, type: 0) )
            {
              Sample = CFlexAnimationTrack::GetSample(this: v12, index: i, type: 0);
            }
            else
            {
              v13 = CFlexAnimationTrack::GetNumSamples(this: v12, type: 0);
              Sample = CFlexAnimationTrack::GetSample(this: v12, index: i - v13, type: 1);
            }
          }
          if ( (*((_WORD *)Sample + 4) & 1) != 0 )
            *((_WORD *)Sample + 4) = *((_WORD *)Sample + 4) & 1 | (2 * curvetype);
        }
        ++w;
      }
      while ( w < workList.m_Size );
      v3 = v17;
    }
    if ( v3->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set curve type");
      ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
    }
    m_pMemory = workList.m_Memory.m_pMemory;
    workList.m_Size = 0;
    if ( workList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( workList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        workList.m_Memory.m_pMemory = nullptr;
      }
      workList.m_Memory.m_nAllocationCount = 0;
    }
    workList.m_pElements = m_pMemory;
    if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484070
// Name: public: void CCurveEditorHelper<class TimelineItem>::ToggleHoldTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<TimelineItem>::ToggleHoldTypeForSelectedSamples(
        CCurveEditorHelper<TimelineItem> *this,
        bool reflect)
{
  CCurveEditorHelper<TimelineItem> *v2; // ebx
  TimelineItem *m_pOuter; // esi
  TimelineItem *v4; // ecx
  int v5; // edi
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v7; // esi
  int v8; // edi
  int v9; // edi
  int i; // ebx
  CChoreoEvent *v11; // eax
  CFlexAnimationTrack *v12; // esi
  int v13; // eax
  CExpressionSample *Sample; // eax
  unsigned __int8 v15; // cl
  TimelineItem **m_pMemory; // eax
  CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > workList; // [esp+8h] [ebp-24h] BYREF
  CCurveEditorHelper<TimelineItem> *v19; // [esp+1Ch] [ebp-10h]
  int l; // [esp+20h] [ebp-Ch] BYREF
  int r; // [esp+24h] [ebp-8h] BYREF
  int numSamples; // [esp+28h] [ebp-4h]
  int w; // [esp+34h] [ebp+8h]

  v2 = this;
  v19 = this;
  if ( CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect) != 0 )
  {
    m_pOuter = v2->m_pOuter;
    if ( v2->m_pOuter->m_nUndoSetup == 0 )
    {
      CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
      CChoreoView::PushUndo(this: g_pChoreoView, description: "Set hold out value");
    }
    ++m_pOuter->m_nUndoSetup;
    v4 = v2->m_pOuter;
    memset(&workList, 0, sizeof(workList));
    TimelineItem::GetWorkList(this: v4, reflect, list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList);
    v5 = 0;
    w = 0;
    if ( workList.m_Size > 0 )
    {
      do
      {
        SafeTrack = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
        v7 = (CFlexAnimationTrack *)SafeTrack;
        if ( SafeTrack != nullptr )
        {
          v8 = CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: 1);
          v5 = CFlexAnimationTrack::GetNumSamples(this: v7, type: 0) + v8;
        }
        numSamples = v5;
        v9 = 0;
        for ( i = -1; v9 < numSamples; ++v9 )
        {
          v11 = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
          v12 = (CFlexAnimationTrack *)v11;
          if ( v11 != nullptr )
          {
            if ( v9 < CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)v11, type: 0) )
            {
              Sample = CFlexAnimationTrack::GetSample(this: v12, index: v9, type: 0);
            }
            else
            {
              v13 = CFlexAnimationTrack::GetNumSamples(this: v12, type: 0);
              Sample = CFlexAnimationTrack::GetSample(this: v12, index: v9 - v13, type: 1);
            }
            v12 = (CFlexAnimationTrack *)Sample;
          }
          if ( (LOWORD(v12->m_flMin) & 1) != 0 )
          {
            Interpolator_CurveInterpolatorsForType(type: LOWORD(v12->m_flMin) >> 1, inbound: &l, outbound: &r);
            if ( i == -1 )
              i = r != 15;
            v15 = 15;
            if ( i != 1 )
              v15 = l;
            LOWORD(v12->m_flMin) = LOWORD(v12->m_flMin) & 1 | (2 * (((_WORD)l << 8) | v15));
          }
        }
        v5 = 0;
        ++w;
      }
      while ( w < workList.m_Size );
      v2 = v19;
    }
    if ( v2->m_pOuter->m_nUndoSetup-- == 1 )
    {
      CChoreoView::PushRedo(this: g_pChoreoView, description: "Set hold out value");
      ExpressionTool::InvalidateLayout(this: g_pExpressionTool);
    }
    m_pMemory = workList.m_Memory.m_pMemory;
    workList.m_Size = 0;
    if ( workList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( workList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        workList.m_Memory.m_pMemory = nullptr;
      }
      workList.m_Memory.m_nAllocationCount = 0;
    }
    workList.m_pElements = m_pMemory;
    if ( workList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484250
// Name: public: int TimelineItem::CountSelected(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TimelineItem::CountSelected(TimelineItem *this)
{
  int result; // eax

  result = CCurveEditorHelper<TimelineItem>::CountSelected(this: this->m_pHelper, reflect: false);
  this->m_nNumSelected = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484270
// Name: public: virtual void TimelineItem::Draw(class CChoreoWidgetDrawHelper __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TimelineItem::Draw(TimelineItem *this, int drawHelper)
{
  TimelineItem *v2; // edi
  CChoreoEvent *SafeTrack; // eax
  CChoreoEvent *v4; // eax
  CChoreoEvent *v5; // eax
  int v6; // eax
  bool v7; // zf
  CChoreoWidgetDrawHelper *v8; // esi
  float v9; // xmm1_4
  TimelineItem *v10; // ecx
  int m_nEditType; // eax
  int v12; // ebx
  Color *p_gray; // ecx
  const char **v14; // ecx
  Color *v15; // ecx
  Color *v16; // eax
  int v17; // esi
  float v18; // xmm0_4
  double PixelsPerSecond; // st7
  float (__thiscall *GetDuration)(struct CChoreoEvent *); // eax
  double v21; // st6
  float time; // xmm0_4
  int v23; // ebx
  int m_Size; // ecx
  int v25; // esi
  tagPOINT *m_pMemory; // edx
  int v27; // ecx
  tagPOINT *v28; // eax
  int v29; // ecx
  bool v30; // cf
  int v31; // esi
  int v32; // ebx
  CExpressionSample *BoundedSample; // esi
  float v34; // xmm0_4
  float v35; // xmm0_4
  HPEN__ *v36; // ebx
  float v37; // xmm0_4
  int v38; // edi
  Color *p_clrSelected; // eax
  char *v40; // eax
  int v41; // eax
  int NumSamples; // eax
  tagPOINT *v43; // eax
  CFlexAnimationTrack *v44; // ebx
  int v45; // xmm0_4
  CChoreoWidgetDrawHelper *v46; // esi
  const char *v47; // eax
  int v48; // xmm0_4
  int v49; // ebx
  int v50; // eax
  bool v51; // bl
  Color *p_drawHelper; // eax
  CChoreoEvent *v53; // eax
  const char *v54; // eax
  int v55; // edi
  Color *p_p_y; // eax
  int v57; // eax
  char sz[128]; // [esp+14h] [ebp-164h] BYREF
  Color dotColorSelected; // [esp+94h] [ebp-E4h]
  float v60; // [esp+98h] [ebp-E0h] BYREF
  float v61; // [esp+9Ch] [ebp-DCh] BYREF
  Color lineColor; // [esp+A0h] [ebp-D8h] BYREF
  float v63; // [esp+A4h] [ebp-D4h]
  float st; // [esp+A8h] [ebp-D0h] BYREF
  Color clrSelected; // [esp+ACh] [ebp-CCh] BYREF
  float v66; // [esp+B0h] [ebp-C8h] BYREF
  Color dotColor; // [esp+B4h] [ebp-C4h]
  float v68; // [esp+B8h] [ebp-C0h] BYREF
  int height; // [esp+BCh] [ebp-BCh]
  float ed; // [esp+C0h] [ebp-B8h] BYREF
  float v71; // [esp+C4h] [ebp-B4h]
  Color clr; // [esp+C8h] [ebp-B0h] BYREF
  float timestepperpixel; // [esp+CCh] [ebp-ACh]
  tagRECT rc; // [esp+D0h] [ebp-A8h] BYREF
  float starttime; // [esp+E0h] [ebp-98h] BYREF
  float linelength; // [esp+E4h] [ebp-94h]
  CChoreoEvent *e; // [esp+E8h] [ebp-90h]
  float prev_t; // [esp+ECh] [ebp-8Ch]
  TimelineItem *v79; // [esp+F0h] [ebp-88h]
  float v80; // [esp+F4h] [ebp-84h]
  float endtime; // [esp+F8h] [ebp-80h] BYREF
  float v82; // [esp+FCh] [ebp-7Ch]
  int value; // [esp+100h] [ebp-78h]
  bool dummy; // [esp+107h] [ebp-71h] BYREF
  float t; // [esp+108h] [ebp-70h]
  int len; // [esp+10Ch] [ebp-6Ch]
  const char *name; // [esp+110h] [ebp-68h] BYREF
  float stoptime; // [esp+114h] [ebp-64h]
  int v89; // [esp+118h] [ebp-60h] BYREF
  int v90; // [esp+11Ch] [ebp-5Ch] BYREF
  int v91; // [esp+120h] [ebp-58h] BYREF
  int bottom; // [esp+124h] [ebp-54h]
  CUtlVector<tagPOINT,CUtlMemory<tagPOINT,int> > segments; // [esp+128h] [ebp-50h] BYREF
  tagRECT rcClient; // [esp+13Ch] [ebp-3Ch] BYREF
  int sample; // [esp+14Ch] [ebp-2Ch]
  Color gray; // [esp+150h] [ebp-28h] BYREF
  tagRECT rcText; // [esp+154h] [ebp-24h] BYREF
  CFlexAnimationTrack *track; // [esp+164h] [ebp-14h]
  Color bgColor; // [esp+168h] [ebp-10h] BYREF
  bool clipped; // [esp+16Eh] [ebp-Ah]
  bool active; // [esp+16Fh] [ebp-9h]
  int type; // [esp+170h] [ebp-8h] BYREF
  Color p_y; // [esp+174h] [ebp-4h] BYREF

  v2 = this;
  v79 = this;
  SafeTrack = TimelineItem::GetSafeTrack(this);
  track = (CFlexAnimationTrack *)SafeTrack;
  if ( SafeTrack != nullptr )
  {
    e = (CChoreoEvent *)CChoreoEvent::GetNumLoopsRemaining(this: SafeTrack);
    if ( e != nullptr )
    {
      v4 = TimelineItem::GetSafeTrack(this: v2);
      active = v4 != nullptr && CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)v4, type: 0) > 0
            || (v5 = TimelineItem::GetSafeTrack(this: v2)) != nullptr
            && CFlexAnimationTrack::IsTrackActive(this: (CFlexAnimationTrack *)v5);
      ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: &starttime, ed: &endtime);
      v6 = CCurveEditorHelper<TimelineItem>::CountSelected(this: v2->m_pHelper, reflect: false);
      v7 = !v2->m_bCollapsed;
      len = v6;
      v2->m_nNumSelected = v6;
      bgColor = (Color)13166310;
      if ( !v7 && active )
      {
        bgColor._color[0] = -56;
        bgColor._color[1] = -26;
        bgColor._color[2] = -56;
        bgColor._color[3] = 0;
      }
      v8 = (CChoreoWidgetDrawHelper *)drawHelper;
      rcClient = v2->m_rcBounds;
      CChoreoWidgetDrawHelper::DrawFilledRect(this: (CChoreoWidgetDrawHelper *)drawHelper, clr: &bgColor, rc: &rcClient);
      gray._color[0] = -56;
      gray._color[1] = -56;
      gray._color[2] = -56;
      gray._color[3] = 0;
      TimelineItem::DrawEventEnd(this: v2, drawHelper: v8);
      TimelineItem::DrawRelativeTags(this: v2, drawHelper: v8);
      if ( !v2->m_bCollapsed )
      {
        if ( v2->m_nEditType == 1 )
        {
          *(float *)&bottom = CFlexAnimationTrack::GetZeroValue(this: track, type: 1, leftSide: true);
          v9 = (float)((float)(1.0 - *(float *)&bottom) * (float)rcClient.bottom)
             + (float)((float)rcClient.top * *(float *)&bottom);
          type = 14469300;
          CChoreoWidgetDrawHelper::DrawColoredLine(
            this: v8,
            clr: (HPEN__ *)&type,
            style: 0,
            width: 1,
            x1: rcClient.left,
            y1: (int)v9,
            x2: rcClient.right,
            y2: (int)v9);
        }
        type = 13145700;
        CChoreoWidgetDrawHelper::DrawOutlinedRect(
          this: v8,
          clr: (Color *)&type,
          style: 0,
          width: (HBRUSH__ *)1,
          rc: &rcClient);
        if ( !v2->m_bCollapsed && ExpressionTool::IsFocusItem(this: g_pExpressionTool, item: v2) )
        {
          TimelineItem::GetGrowHandleRect(this: v2, &rc);
          TimelineItem::DrawGrowHandle(this: v10, helper: v8, handleRect: (HBRUSH)&rc);
        }
        for ( type = CFlexAnimationTrack::IsComboType(this: track); type >= 0; --type )
        {
          m_nEditType = v2->m_nEditType;
          v12 = type;
          if ( type == m_nEditType )
          {
            v89 = 16711680;
            p_gray = (Color *)&v89;
          }
          else
          {
            p_gray = &gray;
          }
          lineColor = *p_gray;
          if ( type == m_nEditType )
          {
            v91 = 16422550;
            v14 = (const char **)&v91;
          }
          else
          {
            v14 = (const char **)&gray;
          }
          name = *v14;
          if ( type == m_nEditType )
          {
            v90 = 16711680;
            v15 = (Color *)&v90;
          }
          else
          {
            v15 = &gray;
          }
          dotColor = *v15;
          if ( type == m_nEditType )
          {
            p_y = (Color)1331440;
            v16 = &p_y;
          }
          else
          {
            v16 = &gray;
          }
          dotColorSelected = *v16;
          v17 = rcClient.bottom - rcClient.top;
          height = rcClient.bottom - rcClient.top;
          bottom = rcClient.bottom;
          if ( ExpressionTool::IsFocusItem(this: g_pExpressionTool, item: v2) )
            v18 = 2.0;
          else
            v18 = 8.0;
          linelength = v18;
          PixelsPerSecond = ExpressionTool::GetPixelsPerSecond(this: g_pExpressionTool);
          GetDuration = e->GetDuration;
          timestepperpixel = linelength / PixelsPerSecond;
          v21 = ((double (__thiscall *)(CChoreoEvent *))GetDuration)(a1: e);
          if ( v21 <= endtime )
            stoptime = e->GetDuration(this: e);
          else
            stoptime = endtime;
          prev_t = starttime;
          *(float *)&sample = CFlexAnimationTrack::GetFracIntensity(this: track, time: starttime, type: v12);
          time = starttime;
          memset(&segments, 0, sizeof(segments));
          t = starttime;
          if ( stoptime >= starttime )
          {
            v80 = (float)bottom;
            v82 = (float)v17;
            do
            {
              *(float *)&value = CFlexAnimationTrack::GetFracIntensity(this: track, time, type);
              ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, &st, &ed);
              v23 = v2->m_rcBounds.left
                  + (int)(float)((float)((float)(t - st) / (float)(ed - st))
                               * (float)(v2->m_rcBounds.right - v2->m_rcBounds.left));
              ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: &v68, ed: &v66);
              m_Size = segments.m_Size;
              if ( segments.m_Size == 0 )
              {
                rcText.right = v2->m_rcBounds.left
                             + (int)(float)((float)((float)(prev_t - v68) / (float)(v66 - v68))
                                          * (float)(v2->m_rcBounds.right - v2->m_rcBounds.left));
                rcText.bottom = (int)(float)(v80 - (float)(*(float *)&sample * v82));
                CUtlVector<tagPOINT,CUtlMemory<tagPOINT,int>>::InsertBefore(
                  this: (CUtlVector<variable_t,CUtlMemory<variable_t,int> > *)&segments,
                  elem: 0,
                  src: (const variable_t *)&rcText.right);
                m_Size = segments.m_Size;
              }
              rcText.bottom = (int)(float)(v80 - (float)(*(float *)&value * v82));
              v25 = m_Size;
              if ( m_Size + 1 > segments.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<VisibleStreamItem,int>::Grow(
                  this: (CUtlMemory<CAudioMixerState,int> *)&segments,
                  num: m_Size - segments.m_Memory.m_nAllocationCount + 1);
                m_Size = segments.m_Size;
              }
              m_pMemory = segments.m_Memory.m_pMemory;
              v27 = m_Size + 1;
              segments.m_Size = v27;
              segments.m_pElements = segments.m_Memory.m_pMemory;
              if ( v27 - v25 - 1 > 0 )
              {
                _V_memmove(
                  dest: &segments.m_Memory.m_pMemory[v25 + 1],
                  src: &segments.m_Memory.m_pMemory[v25],
                  count: 8 * (v27 - v25 - 1));
                v27 = segments.m_Size;
                m_pMemory = segments.m_Memory.m_pMemory;
              }
              v28 = &m_pMemory[v25];
              if ( v28 != nullptr )
              {
                v29 = rcText.bottom;
                v28->x = v23;
                v28->y = v29;
                v27 = segments.m_Size;
              }
              prev_t = t;
              time = t + timestepperpixel;
              sample = value;
              v30 = stoptime < (float)(t + timestepperpixel);
              t = t + timestepperpixel;
            }
            while ( !v30 );
            if ( v27 >= 2 )
              CChoreoWidgetDrawHelper::DrawColoredPolyLine(
                this: (CChoreoWidgetDrawHelper *)drawHelper,
                clr: (HPEN__ *)&lineColor,
                style: 0,
                width: (HPEN__ *)1,
                points: &segments);
          }
          v31 = 0;
          *(float *)&sample = 0.0;
          if ( CFlexAnimationTrack::GetNumSamples(this: track, type) > 0 )
          {
            v32 = type;
            do
            {
              BoundedSample = CFlexAnimationTrack::GetBoundedSample(
                                this: track,
                                number: v31,
                                bClamped: &dummy,
                                type: v32);
              v63 = BoundedSample->value;
              v34 = BoundedSample->time;
              clipped = false;
              v71 = v34;
              ExpressionTool::GetStartAndEndTime(this: g_pExpressionTool, st: &v60, ed: &v61);
              v35 = (float)(v71 - v60) / (float)(v61 - v60);
              if ( v35 < 0.0 || v35 > 1.0 )
                clipped = true;
              v36 = (HPEN__ *)(v2->m_rcBounds.left
                             + (int)(float)((float)(v2->m_rcBounds.right - v2->m_rcBounds.left) * v35));
              if ( !clipped )
              {
                clr = dotColor;
                clrSelected = dotColorSelected;
                v37 = (float)bottom - (float)((float)height * v63);
                v38 = (int)v37;
                p_clrSelected = &clrSelected;
                if ( (*((_WORD *)BoundedSample + 4) & 1) == 0 )
                  p_clrSelected = &clr;
                CChoreoWidgetDrawHelper::DrawCircle(
                  this: (CChoreoWidgetDrawHelper *)drawHelper,
                  clr: p_clrSelected,
                  x: v36,
                  y: (HBRUSH__ *)(int)v37,
                  radius: (HBRUSH__ *)6,
                  filled: true);
                if ( (*((_WORD *)BoundedSample + 4) & 1) != 0 && (*((_WORD *)BoundedSample + 4) & 0xFFFE) != 0 )
                {
                  v40 = Interpolator_NameForCurveType(type: *((_WORD *)BoundedSample + 4) >> 1, printname: true);
                  V_snprintf(pDest: sz, maxLen: 128, pFormat: "%s", v40);
                  v41 = v38 + 5;
                  if ( v38 + 5 >= rcClient.top + 2 )
                  {
                    if ( v41 > rcClient.bottom - 11 )
                      v41 = rcClient.bottom - 11;
                  }
                  else
                  {
                    v41 = rcClient.top + 2;
                  }
                  rc.top = v41;
                  rc.bottom = v41 + 10;
                  rc.left = (int)v36 - 75;
                  rc.right = (int)v36 + 175;
                  CChoreoWidgetDrawHelper::DrawColoredText(
                    this: (CChoreoWidgetDrawHelper *)drawHelper,
                    font: "Arial",
                    pointsize: 9,
                    weight: 500,
                    clr: (const Color *)&name,
                    rcText: &rc,
                    fmt: sz);
                }
              }
              v32 = type;
              v31 = ++sample;
              NumSamples = CFlexAnimationTrack::GetNumSamples(this: track, type);
              v2 = v79;
            }
            while ( v31 < NumSamples );
          }
          v43 = segments.m_Memory.m_pMemory;
          segments.m_Size = 0;
          if ( segments.m_Memory.m_nGrowSize >= 0 )
          {
            if ( segments.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: segments.m_Memory.m_pMemory);
              v43 = nullptr;
              segments.m_Memory.m_pMemory = nullptr;
            }
            segments.m_Memory.m_nAllocationCount = 0;
          }
          segments.m_pElements = v43;
          if ( segments.m_Memory.m_nGrowSize >= 0 && v43 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v43);
        }
      }
      v44 = track;
      if ( !CFlexAnimationTrack::IsComboType(this: track) || v2->m_bCollapsed )
      {
        v46 = (CChoreoWidgetDrawHelper *)drawHelper;
      }
      else
      {
        *(_QWORD *)&rcText.left = *(_QWORD *)&rcClient.left;
        v45 = _mm_loadl_epi64((const __m128i *)&rcClient.right).m128i_u32[0];
        rcText.top = rcClient.top + 14;
        v7 = v2->m_nEditType == 1;
        rcText.right = v45;
        rcText.left = rcClient.left + 10;
        rcText.bottom = rcClient.top + 23;
        if ( v7 )
        {
          sprintf(string: sz, format: "left");
          v46 = (CChoreoWidgetDrawHelper *)drawHelper;
          p_y = (Color)16711680;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: (CChoreoWidgetDrawHelper *)drawHelper,
            font: "Arial",
            pointsize: 9,
            weight: 500,
            clr: &p_y,
            &rcText,
            fmt: sz);
          sprintf(string: sz, format: "right");
          rcText.bottom = rcClient.bottom;
          rcText.top = rcClient.bottom - 22;
          drawHelper = 16711680;
          CChoreoWidgetDrawHelper::DrawColoredText(
            this: v46,
            font: "Arial",
            pointsize: 9,
            weight: 500,
            clr: (const Color *)&drawHelper,
            &rcText,
            fmt: sz);
        }
        else
        {
          v46 = (CChoreoWidgetDrawHelper *)drawHelper;
        }
        v7 = v2->m_nEditType == 0;
        rcText.bottom = (rcClient.bottom + rcClient.top) / 2;
        rcText.top = rcText.bottom - 10;
        v47 = "amount";
        if ( !v7 )
          v47 = "left/right";
        sprintf(string: sz, format: "editmode:  <%s>", v47);
        drawHelper = 16711680;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v46,
          font: "Arial",
          pointsize: 9,
          weight: 500,
          clr: (const Color *)&drawHelper,
          &rcText,
          fmt: sz);
      }
      *(_QWORD *)&rcText.left = *(_QWORD *)&rcClient.left;
      v48 = _mm_loadl_epi64((const __m128i *)&rcClient.right).m128i_u32[0];
      rcText.left = rcClient.left + 2;
      rcText.top = rcClient.top + 2;
      rcText.right = v48;
      rcText.bottom = rcClient.top + 11;
      name = CFlexAnimationTrack::GetFlexControllerName(this: v44);
      if ( len > 0 )
      {
        sprintf(string: sz, format: "{%i} - ", len);
        v49 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
        drawHelper = 30840;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v46,
          font: "Arial",
          pointsize: 9,
          weight: 500,
          clr: (const Color *)&drawHelper,
          &rcText,
          fmt: sz);
        rcText.left += v49 + 2;
      }
      sprintf(string: sz, format: "%s -", name);
      v50 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
      v51 = active;
      len = v50;
      if ( active )
      {
        drawHelper = (int)&g_flexedverts[1250].z;
        p_drawHelper = (Color *)&drawHelper;
      }
      else
      {
        p_y = (Color)&g_flexedverts[192].y;
        p_drawHelper = &p_y;
      }
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: v46,
        font: "Arial",
        pointsize: 9,
        weight: 500,
        clr: p_drawHelper,
        &rcText,
        fmt: sz);
      v53 = TimelineItem::GetSafeTrack(this: v2);
      if ( v53 == nullptr
        || (v7 = !CFlexAnimationTrack::IsTrackActive(this: (CFlexAnimationTrack *)v53), v54 = "enabled", v7) )
      {
        v54 = "disabled";
      }
      sprintf(string: sz, format: "%s", v54);
      rcText.left += len + 2;
      v55 = CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
      if ( v51 )
      {
        drawHelper = (int)&g_flexedverts[1250].z;
        p_p_y = (Color *)&drawHelper;
      }
      else
      {
        p_y = (Color)&g_flexedverts[192].y;
        p_p_y = &p_y;
      }
      CChoreoWidgetDrawHelper::DrawColoredText(
        this: v46,
        font: "Arial",
        pointsize: 9,
        weight: 500,
        clr: p_p_y,
        &rcText,
        fmt: sz);
      if ( v51 )
      {
        rcText.left += v55 + 2;
        v57 = CFlexAnimationTrack::GetNumSamples(this: track, type: 0);
        sprintf(string: sz, format: " <%i>", v57);
        CChoreoWidgetDrawHelper::CalcTextWidth(font: "Arial", pointsize: (HFONT__ *)9, weight: 500, fmt: sz);
        drawHelper = 220;
        CChoreoWidgetDrawHelper::DrawColoredText(
          this: v46,
          font: "Arial",
          pointsize: 9,
          weight: 500,
          clr: (const Color *)&drawHelper,
          &rcText,
          fmt: sz);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484D30
// Name: public: int CCurveEditorHelper<class TimelineItem>::GetBestCurveTypeForSelectedSamples(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurveEditorHelper<TimelineItem>::GetBestCurveTypeForSelectedSamples(
        CCurveEditorHelper<TimelineItem> *this,
        BOOL reflect)
{
  int result; // eax
  TimelineItem *m_pOuter; // ecx
  int v5; // eax
  CChoreoEvent *SafeTrack; // eax
  CFlexAnimationTrack *v7; // esi
  int NumSamples; // edi
  int v9; // edi
  const char *v10; // edi
  CChoreoEvent *v11; // eax
  CFlexAnimationTrack *v12; // esi
  CExpressionSample *Sample; // eax
  int v14; // eax
  unsigned int v15; // eax
  int v16; // esi
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // ax
  unsigned __int16 v19; // dx
  int v20; // ecx
  UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  unsigned __int16 v22; // di
  int v23; // esi
  int v24; // edx
  int key; // esi
  unsigned __int16 j; // ax
  TimelineItem **v27; // eax
  CUtlMap<int,int,unsigned short> counts; // [esp+8h] [ebp-4Ch] BYREF
  CUtlVector<TimelineItem *,CUtlMemory<TimelineItem *,int> > workList; // [esp+24h] [ebp-30h] BYREF
  CUtlMap<int,int,unsigned short>::Node_t search; // [esp+38h] [ebp-1Ch] BYREF
  CUtlMap<int,int,unsigned short>::Node_t insert; // [esp+40h] [ebp-14h] BYREF
  int i; // [esp+48h] [ebp-Ch]
  unsigned __int16 parent[2]; // [esp+4Ch] [ebp-8h] BYREF
  int w; // [esp+50h] [ebp-4h]

  result = CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect);
  if ( result != 0 )
  {
    m_pOuter = this->m_pOuter;
    counts.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
    memset(&counts.m_Tree.m_Elements, 0, sizeof(counts.m_Tree.m_Elements));
    *(_DWORD *)&counts.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&counts.m_Tree.m_FirstFree = -1;
    counts.m_Tree.m_pElements = nullptr;
    memset(&workList, 0, sizeof(workList));
    TimelineItem::GetWorkList(
      this: m_pOuter,
      reflect,
      list: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&workList);
    v5 = 0;
    for ( w = 0; v5 < workList.m_Size; w = v5 )
    {
      SafeTrack = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[v5]);
      v7 = (CFlexAnimationTrack *)SafeTrack;
      if ( SafeTrack != nullptr )
      {
        NumSamples = CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)SafeTrack, type: 1);
        v9 = CFlexAnimationTrack::GetNumSamples(this: v7, type: 0) + NumSamples;
        if ( v9 != 0 )
        {
          v10 = (const char *)(v9 - 1);
          for ( i = (int)v10; (int)v10 >= 0; i = (int)v10 )
          {
            v11 = TimelineItem::GetSafeTrack(this: workList.m_Memory.m_pMemory[w]);
            v12 = (CFlexAnimationTrack *)v11;
            if ( v11 != nullptr )
            {
              if ( (int)v10 < CFlexAnimationTrack::GetNumSamples(this: (CFlexAnimationTrack *)v11, type: 0) )
              {
                Sample = CFlexAnimationTrack::GetSample(this: v12, index: (int)v10, type: 0);
              }
              else
              {
                v14 = CFlexAnimationTrack::GetNumSamples(this: v12, type: 0);
                Sample = CFlexAnimationTrack::GetSample(this: v12, index: (int)&v10[-v14], type: 1);
              }
            }
            else
            {
              Sample = nullptr;
            }
            v15 = *((unsigned __int16 *)Sample + 4);
            if ( (v15 & 1) != 0 )
            {
              v16 = v15 >> 1;
              search.key = v15 >> 1;
              v17 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                      this: &counts.m_Tree,
                      &search);
              if ( v17 == 0xFFFF )
              {
                *(_DWORD *)parent = 0xFFFF;
                insert.key = v16;
                insert.elem = 0;
                HIBYTE(reflect) = 0;
                CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
                  this: &counts.m_Tree,
                  &insert,
                  parent,
                  leftchild: (bool *)&reflect + 3);
                v18 = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
                        this: (CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&counts,
                        a2: v10);
                v19 = parent[0];
                v20 = v18;
                m_pMemory = counts.m_Tree.m_Elements.m_pMemory;
                v22 = v20;
                v23 = v20;
                counts.m_Tree.m_Elements.m_pMemory[v23].m_Right = -1;
                m_pMemory[v23].m_Left = -1;
                m_pMemory[v23].m_Tag = 0;
                m_pMemory[v23].m_Parent = v19;
                if ( v19 == 0xFFFF )
                {
                  counts.m_Tree.m_Root = v20;
                }
                else
                {
                  v24 = v19;
                  if ( HIBYTE(reflect) != 0 )
                    m_pMemory[v24].m_Left = v20;
                  else
                    m_pMemory[v24].m_Right = v20;
                }
                CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
                  this: &counts.m_Tree,
                  elem: v20);
                ++counts.m_Tree.m_NumElements;
                if ( &counts.m_Tree.m_Elements.m_pMemory[v23] != (UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short> *)-8 )
                  counts.m_Tree.m_Elements.m_pMemory[v23].m_Data = insert;
                v17 = v22;
                v10 = (const char *)i;
              }
              ++counts.m_Tree.m_Elements.m_pMemory[v17].m_Data.elem;
            }
            --v10;
          }
        }
      }
      v5 = w + 1;
    }
    key = 0;
    for ( j = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &counts.m_Tree);
          j != 0xFFFF;
          j = CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &counts.m_Tree,
                i: j) )
    {
      if ( counts.m_Tree.m_Elements.m_pMemory[j].m_Data.elem > key )
        key = counts.m_Tree.m_Elements.m_pMemory[j].m_Data.key;
    }
    v27 = workList.m_Memory.m_pMemory;
    workList.m_Size = 0;
    if ( workList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( workList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
        v27 = nullptr;
        workList.m_Memory.m_pMemory = nullptr;
      }
      workList.m_Memory.m_nAllocationCount = 0;
    }
    workList.m_pElements = v27;
    if ( workList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v27 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
        workList.m_Memory.m_pMemory = nullptr;
      }
      workList.m_Memory.m_nAllocationCount = 0;
    }
    CUtlRBTree<CUtlMap<int,int,unsigned short>::Node_t,unsigned short,CUtlMap<int,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &counts.m_Tree);
    if ( counts.m_Tree.m_Elements.m_nGrowSize >= 0 && counts.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: counts.m_Tree.m_Elements.m_pMemory);
    return key;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00484FF0
// Name: public: void CCurveEditorHelper<class TimelineItem>::ChangeCurveType(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurveEditorHelper<TimelineItem>::ChangeCurveType(
        CCurveEditorHelper<TimelineItem> *this,
        bool forward,
        bool shiftdown,
        bool altdown)
{
  bool v5; // bl
  __int16 BestCurveTypeForSelectedSamples; // ax
  int v7; // eax
  int v8; // edx
  bool v9; // zf
  bool v10; // sf
  int sides[2]; // [esp+8h] [ebp-8h] BYREF

  v5 = !shiftdown || altdown;
  if ( CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect: false) != 0 )
  {
    BestCurveTypeForSelectedSamples = CCurveEditorHelper<TimelineItem>::GetBestCurveTypeForSelectedSamples(
                                        this,
                                        reflect: false);
    Interpolator_CurveInterpolatorsForType(type: BestCurveTypeForSelectedSamples, inbound: sides, outbound: &sides[1]);
    v7 = 0;
    v8 = 2 * forward - 1;
    while ( 1 )
    {
      if ( v7 != 0 )
      {
        if ( v7 != 1 )
          goto LABEL_12;
        v9 = !v5;
      }
      else
      {
        v9 = !shiftdown;
      }
      if ( !v9 )
      {
LABEL_12:
        v10 = v8 + sides[v7] < 0;
        sides[v7] += v8;
        if ( v10 )
        {
          sides[v7] = 15;
        }
        else if ( sides[v7] >= 16 )
        {
          sides[v7] = 0;
        }
      }
      if ( ++v7 >= 2 )
      {
        CCurveEditorHelper<TimelineItem>::SetCurveTypeForSelectedSamples(
          this,
          reflect: false,
          curvetype: LOBYTE(sides[1]) | (LOBYTE(sides[0]) << 8));
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004850B0
// Name: public: bool CCurveEditorHelper<class TimelineItem>::HelperHandleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurveEditorHelper<TimelineItem>::HelperHandleEvent(
        CCurveEditorHelper<TimelineItem> *this,
        mxEvent *event)
{
  int key; // ecx
  int v5; // eax
  __int16 v6; // bx
  CExpressionSample *v7; // eax
  CExpressionSample *SampleUnderMouse; // eax
  bool shiftdown; // [esp+13h] [ebp-5h]
  bool shiftdowna; // [esp+13h] [ebp-5h]
  bool handled; // [esp+17h] [ebp-1h]
  bool altdown; // [esp+20h] [ebp+8h]
  bool altdowna; // [esp+20h] [ebp+8h]
  bool altdownb; // [esp+20h] [ebp+8h]
  bool altdownc; // [esp+20h] [ebp+8h]

  handled = false;
  if ( event->event == 11 )
  {
    key = event->key;
    if ( key == 38 )
    {
      shiftdowna = GetAsyncKeyState(vKey: 16) != 0;
      altdownc = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
        CCurveEditorHelper<TimelineItem>::ChangeCurveType(
          this,
          forward: false,
          shiftdown: shiftdowna,
          altdown: altdownc);
    }
    else if ( event->key == 40 )
    {
      shiftdown = GetAsyncKeyState(vKey: 16) != 0;
      altdownb = GetAsyncKeyState(vKey: 18) != 0;
      if ( GetAsyncKeyState(vKey: 17) != 0 )
      {
        CCurveEditorHelper<TimelineItem>::ChangeCurveType(this, forward: true, shiftdown, altdown: altdownb);
        return 0;
      }
    }
    else if ( event->key == 72 )
    {
      handled = true;
      altdowna = GetAsyncKeyState(vKey: 16) != 0;
      if ( CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect: altdowna) > 0 )
      {
        CCurveEditorHelper<TimelineItem>::ToggleHoldTypeForSelectedSamples(this, reflect: altdowna);
        return 1;
      }
      TimelineItem::SetMousePositionForEvent(this: this->m_pOuter, event);
      SampleUnderMouse = TimelineItem::GetSampleUnderMouse(
                           this: this->m_pOuter,
                           mx: event->x,
                           my: event->y,
                           tolerance: 0.0);
      if ( SampleUnderMouse != nullptr )
      {
        CCurveEditorHelper<TimelineItem>::ToggleHoldTypeForSample(this, sample: SampleUnderMouse);
        return 1;
      }
    }
    else if ( key >= 48 && key <= 57 )
    {
      altdown = GetAsyncKeyState(vKey: 16) != 0;
      handled = true;
      v5 = Interpolator_CurveTypeForHotkey(key: event->key);
      v6 = v5;
      if ( v5 >= 0 )
      {
        if ( CCurveEditorHelper<TimelineItem>::CountSelected(this, reflect: altdown) > 0 )
        {
          CCurveEditorHelper<TimelineItem>::SetCurveTypeForSelectedSamples(this, reflect: altdown, curvetype: v6);
          return 1;
        }
        TimelineItem::SetMousePositionForEvent(this: this->m_pOuter, event);
        v7 = TimelineItem::GetSampleUnderMouse(this: this->m_pOuter, mx: event->x, my: event->y, tolerance: 0.0);
        if ( v7 != nullptr )
        {
          CCurveEditorHelper<TimelineItem>::SetCurveTypeForSample(this, curvetype: v6, sample: v7);
          return 1;
        }
      }
    }
  }
  return handled;
}

//------------------------------------------------------------------------------
// Address: 0x00485290
// Name: public: virtual int TimelineItem::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TimelineItem::handleEvent(TimelineItem *this, mxEvent *event)
{
  int v4; // ebx
  int result; // eax
  int key; // edi
  float v7; // xmm0_4
  CChoreoScene *v8; // eax
  CChoreoScene *Scene; // eax
  CChoreoScene *v10; // esi
  CChoreoScene *v11; // eax
  CChoreoScene *v12; // esi
  CChoreoEvent *SafeTrack; // eax
  HWND Handle; // eax
  int v15; // ebx
  float v16; // xmm0_4
  CExpressionSample *SampleUnderMouse; // eax
  int x_low; // eax
  int v19; // edx
  int y_low; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // edx
  int v24; // ecx
  int v25; // edx
  int modifiers; // eax
  int y; // edx
  mxWindow *m_pWorkspace; // ecx
  HWND v29; // eax
  HWND v30; // eax
  int time_low; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // eax
  int v37; // eax
  bool IsMouseOverGrowHandle; // bl
  int m_nDragging; // eax
  int v40; // eax
  int v41; // eax
  float scenetime; // [esp+0h] [ebp-20h]
  float scenetimea; // [esp+0h] [ebp-20h]
  int scenetimeb; // [esp+0h] [ebp-20h]
  float tolerance; // [esp+4h] [ebp-1Ch]
  int tolerancea; // [esp+4h] [ebp-1Ch]
  CExpressionSample sample; // [esp+14h] [ebp-Ch] BYREF
  float ta; // [esp+28h] [ebp+8h]
  float tb; // [esp+28h] [ebp+8h]
  float t; // [esp+28h] [ebp+8h]
  float tc; // [esp+28h] [ebp+8h]
  bool t_3; // [esp+2Bh] [ebp+Bh]

  v4 = 0;
  if ( CCurveEditorHelper<TimelineItem>::HelperHandleEvent(this: this->m_pHelper, event) != 0 )
    return 1;
  switch ( event->event )
  {
    case 6:
      IsMouseOverGrowHandle = TimelineItem::IsMouseOverGrowHandle(this, x: SLOWORD(event->x), y: SLOWORD(event->y));
      m_nDragging = this->m_nDragging;
      if ( m_nDragging != 0 )
      {
        if ( m_nDragging == 3 )
        {
          TimelineItem::DrawFocusRect(this);
        }
        else if ( m_nDragging == 4 )
        {
          TimelineItem::DrawGrowRect(this);
        }
        TimelineItem::MouseDrag(
          this,
          x: COERCE_FLOAT(LOWORD(event->x)),
          y: SLOWORD(event->y),
          modifiers: event->modifiers,
          snap: true);
        v40 = this->m_nDragging;
        if ( v40 == 4 )
        {
          v41 = event->y + this->m_nCurrentHeight - this->m_nStartY;
          if ( v41 >= 10 )
          {
            this->m_nCurrentHeight = v41;
            ExpressionTool::LayoutItems(this: g_pExpressionTool, force: true);
          }
        }
        else if ( v40 == 1 || v40 == 2 )
        {
          TimelineItem::PostDataChanged(this, redodescription: "Move sample point(s)");
        }
        else
        {
          TimelineItem::SelectPoints(this);
        }
        this->m_nDragging = 0;
        TimelineItem::DrawSelf(this);
      }
      if ( (event->buttons & 2) == 0 && (event->modifiers & 2) == 0 && (event->modifiers & 1) == 0 )
      {
        if ( realtime - this->m_flLastClickTime < 0.2 && (IsMouseOverGrowHandle || this->m_bCollapsed) )
          TimelineItem::OnDoubleClicked(this);
        this->m_flLastClickTime = realtime;
      }
      goto LABEL_88;
    case 7:
      sound->Flush(this: sound);
      Handle = (HWND)mxWidget::getHandle(this: g_pExpressionTool);
      SetFocus(hWnd: Handle);
      v15 = this->m_rcBounds.bottom - this->m_rcBounds.top;
      t_3 = (event->buttons & 2) != 0;
      if ( this->m_nDragging != 0 )
        goto LABEL_88;
      if ( (event->modifiers & 1) != 0 )
        v16 = 5.0;
      else
        v16 = 30.0;
      SampleUnderMouse = TimelineItem::GetSampleUnderMouse(this, mx: event->x, my: event->y, tolerance: v16);
      tolerancea = SLOWORD(event->y);
      scenetimeb = SLOWORD(event->x);
      LODWORD(sample.time) = SampleUnderMouse;
      if ( TimelineItem::IsMouseOverGrowHandle(this, x: scenetimeb, y: tolerancea) )
      {
        this->m_nDragging = 4;
        x_low = SLOWORD(event->x);
        this->m_nLastX = x_low;
        v19 = x_low;
        y_low = SLOWORD(event->y);
        this->m_nLastY = y_low;
        this->m_nStartX = v19;
        this->m_nStartY = y_low;
        TimelineItem::MouseDrag(
          this,
          x: COERCE_FLOAT(LOWORD(event->x)),
          y: SLOWORD(event->y),
          modifiers: event->modifiers,
          snap: false);
        TimelineItem::DrawGrowRect(this);
        return 1;
      }
      if ( LODWORD(sample.time) != 0 )
      {
        if ( (event->modifiers & 2) != 0 )
        {
          *(_WORD *)(LODWORD(sample.time) + 8) ^= ((unsigned __int8)*(_WORD *)(LODWORD(sample.time) + 8)
                                                 ^ (unsigned __int8)~(unsigned __int8)*(_WORD *)(LODWORD(sample.time) + 8))
                                                & 1;
          TimelineItem::DrawSelf(this);
          return 1;
        }
        else
        {
          if ( (*(_BYTE *)(LODWORD(sample.time) + 8) & 1) != 0 )
          {
            this->m_nDragging = t_3 + 1;
            v21 = SLOWORD(event->x);
            this->m_nLastX = v21;
            v22 = SLOWORD(event->y);
            this->m_nStartY = v22;
            this->m_nLastY = v22;
            this->m_nStartX = v21;
            TimelineItem::PreDataChanged(this, undodescription: "Move sample point(s)");
            TimelineItem::MouseDrag(
              this,
              x: COERCE_FLOAT(LOWORD(event->x)),
              y: SLOWORD(event->y),
              modifiers: event->modifiers,
              snap: false);
            TimelineItem::DrawSelf(this);
          }
          else
          {
            ExpressionTool::DeselectAll(this: g_pExpressionTool);
            TimelineItem::DrawSelf(this);
            this->m_nDragging = 3;
            v23 = SLOWORD(event->x);
            this->m_nLastX = v23;
            v24 = v23;
            v25 = SLOWORD(event->y);
            this->m_nStartX = v24;
            this->m_nLastY = v25;
            this->m_nStartY = v25;
            TimelineItem::MouseDrag(
              this,
              x: COERCE_FLOAT(LOWORD(event->x)),
              y: SLOWORD(event->y),
              modifiers: event->modifiers,
              snap: false);
            TimelineItem::DrawFocusRect(this);
          }
          return 1;
        }
      }
      else
      {
        modifiers = event->modifiers;
        if ( (modifiers & 1) != 0 )
        {
          if ( ExpressionTool::GetSafeEvent(this: g_pExpressionTool) == nullptr )
            goto LABEL_88;
          tc = TimelineItem::GetTimeForMouse(this, mx: this->m_rcBounds.left + SLOWORD(event->x), clip: false);
          sample.time = FacePoser_SnapTime(t: tc);
          sample.value = 1.0 - (float)((float)SLOWORD(event->y) / (float)v15);
          *((_WORD *)&sample + 4) = 0;
          TimelineItem::AddSample(this, &sample);
          TimelineItem::DrawSelf(this);
          return 1;
        }
        else if ( t_3 )
        {
          y = event->y;
          LODWORD(sample.value) = event->x;
          m_pWorkspace = this->m_pWorkspace;
          LODWORD(sample.time) = y;
          v29 = (HWND)mxWidget::getHandle(this: m_pWorkspace);
          ClientToScreen(hWnd: v29, lpPoint: (LPPOINT)&sample);
          v30 = (HWND)mxWidget::getHandle(this: g_pExpressionTool);
          ScreenToClient(hWnd: v30, lpPoint: (LPPOINT)&sample);
          time_low = LODWORD(sample.time);
          event->x = LODWORD(sample.value);
          event->y = time_low;
          ExpressionTool::ShowContextMenu(this: g_pExpressionTool, event, include_track_menus: true);
          return 0;
        }
        else
        {
          if ( (modifiers & 2) == 0 )
          {
            ExpressionTool::DeselectAll(this: g_pExpressionTool);
            TimelineItem::DrawSelf(this);
          }
          this->m_nDragging = 3;
          v32 = SLOWORD(event->x);
          this->m_nLastX = v32;
          v33 = v32;
          v34 = SLOWORD(event->y);
          this->m_nStartY = v34;
          this->m_nLastY = v34;
          this->m_nStartX = v33;
          TimelineItem::MouseDrag(
            this,
            x: COERCE_FLOAT(LOWORD(event->x)),
            y: SLOWORD(event->y),
            modifiers: event->modifiers,
            snap: false);
          TimelineItem::DrawFocusRect(this);
          return 1;
        }
      }
    case 8:
    case 9:
      v35 = this->m_nDragging;
      if ( v35 != 0 )
      {
        if ( v35 == 3 )
        {
          TimelineItem::DrawFocusRect(this);
        }
        else if ( v35 == 4 )
        {
          TimelineItem::DrawGrowRect(this);
        }
        TimelineItem::MouseDrag(
          this,
          x: COERCE_FLOAT(LOWORD(event->x)),
          y: SLOWORD(event->y),
          modifiers: event->modifiers,
          snap: false);
        v36 = this->m_nDragging;
        if ( v36 == 3 )
        {
          TimelineItem::DrawFocusRect(this);
        }
        else if ( v36 == 4 )
        {
          TimelineItem::DrawGrowRect(this);
        }
        v37 = this->m_nDragging;
        if ( v37 == 2 || v37 == 1 )
        {
          TimelineItem::DrawSelf(this);
          return 1;
        }
      }
      else
      {
        TimelineItem::CountSelected(this);
        if ( this->m_nNumSelected <= 0 && ExpressionTool::IsFocusItem(this: g_pExpressionTool, item: this) )
        {
          TimelineItem::DrawAutoHighlight(this, event);
          return 1;
        }
      }
LABEL_88:
      v4 = 1;
LABEL_89:
      result = v4;
      break;
    case 0xA:
      if ( event->key != 32 )
        goto LABEL_88;
      SafeTrack = TimelineItem::GetSafeTrack(this);
      if ( SafeTrack == nullptr || !CFlexAnimationTrack::IsComboType(this: (CFlexAnimationTrack *)SafeTrack) )
        goto LABEL_88;
      TimelineItem::SetEditType(this, type: this->m_nEditType == 0);
      TimelineItem::DrawSelf(this);
      return 1;
    case 0xB:
      key = event->key;
      switch ( key )
      {
        case 27:
          ExpressionTool::DeselectAll(this: g_pExpressionTool);
          TimelineItem::DrawSelf(this);
          return 1;
        case 37:
          Scene = CChoreoView::GetScene(this: g_pChoreoView);
          v10 = Scene;
          if ( Scene == nullptr || CChoreoScene::GetSceneFPS(this: Scene) <= 0 )
            goto LABEL_88;
          ta = g_pExpressionTool->m_flScrub;
          v7 = ta - (float)(1.0 / (float)CChoreoScene::GetSceneFPS(this: v10));
          if ( v7 <= 0.0 )
            v7 = 0.0;
          goto LABEL_12;
        case 39:
          v11 = CChoreoView::GetScene(this: g_pChoreoView);
          v12 = v11;
          if ( v11 == nullptr || CChoreoScene::GetSceneFPS(this: v11) <= 0 )
            goto LABEL_88;
          tb = g_pExpressionTool->m_flScrub;
          t = (float)(1.0 / (float)CChoreoScene::GetSceneFPS(this: v12)) + tb;
          if ( CChoreoScene::FindStopTime(this: v12) <= (double)t )
            t = CChoreoScene::FindStopTime(this: v12);
          v7 = t;
          goto LABEL_12;
        case 46:
          ExpressionTool::DeleteSelectedSamples(this: g_pExpressionTool);
          TimelineItem::DrawSelf(this);
          return 1;
        case 67:
          TimelineItem::Copy(this);
          TimelineItem::DrawSelf(this);
          return 1;
        case 74:
          scenetime = ExpressionTool::GetScrubberSceneTime(this: g_pExpressionTool);
          ExpressionTool::OnCopyToFlex(this: g_pExpressionTool, scenetime, isEdited: true);
          return 1;
        case 75:
          scenetimea = ExpressionTool::GetScrubberSceneTime(this: g_pExpressionTool);
          ExpressionTool::OnCopyFromFlex(this: g_pExpressionTool, scenetime: scenetimea, isEdited: false);
          return 1;
        case 86:
          TimelineItem::Paste(this);
          TimelineItem::DrawSelf(this);
          return 1;
        case 188:
          v7 = 0.0;
LABEL_12:
          ExpressionTool::SetScrubTargetTime(this: g_pExpressionTool, t: v7);
          result = 1;
          break;
        case 190:
          v8 = CChoreoView::GetScene(this: g_pChoreoView);
          if ( v8 == nullptr )
            goto LABEL_88;
          tolerance = CChoreoScene::FindStopTime(this: v8);
          ExpressionTool::SetScrubTargetTime(this: g_pExpressionTool, t: tolerance);
          result = 1;
          break;
        case 191:
          if ( !CChoreoView::IsPlayingScene(this: g_pChoreoView) )
            goto LABEL_88;
          CChoreoView::StopScene(this: g_pChoreoView);
          result = 1;
          break;
        default:
          CChoreoView::HandleZoomKey<ExpressionTool>(this: g_pChoreoView, other: g_pExpressionTool, keyCode: key);
          result = 1;
          break;
      }
      return result;
    default:
      goto LABEL_89;
  }
  return result;
}
